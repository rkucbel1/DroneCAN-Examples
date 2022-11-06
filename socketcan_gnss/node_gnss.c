/*
 * This demo application is distributed under the terms of CC0 (public domain dedication).
 * More info: https://creativecommons.org/publicdomain/zero/1.0/
 */

// This is needed to enable necessary declarations in sys/
#ifndef _GNU_SOURCE
# define _GNU_SOURCE
#endif

#include "/home/rkucbel1/DroneCAN-Examples/socketcan_gnss/libcanard/canard.h"
#include "/home/rkucbel1/DroneCAN-Examples/socketcan_gnss/socketcan/socketcan.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>
#include <errno.h>

/*
 * Application constants
 */
#define APP_VERSION_MAJOR                                           1
#define APP_VERSION_MINOR                                           0
#define APP_NODE_NAME                                               "org.uavcan.libcanard.demo"
#define UNIQUE_ID                                                   55

/*
 * Some useful constants defined by the UAVCAN specification.
 * Data type signature values can be easily obtained with the script show_data_type_info.py
 */
#define UAVCAN_NODE_ID_ALLOCATION_DATA_TYPE_ID                      1
#define UAVCAN_NODE_ID_ALLOCATION_DATA_TYPE_SIGNATURE               0x0b2a812620a11d40

#define UAVCAN_NODE_STATUS_MESSAGE_SIZE                             7
#define UAVCAN_NODE_STATUS_DATA_TYPE_ID                             341
#define UAVCAN_NODE_STATUS_DATA_TYPE_SIGNATURE                      0x0f0868d0c1a7c6f1

#define UAVCAN_NODE_HEALTH_OK                                       0
#define UAVCAN_NODE_HEALTH_WARNING                                  1
#define UAVCAN_NODE_HEALTH_ERROR                                    2
#define UAVCAN_NODE_HEALTH_CRITICAL                                 3

#define UAVCAN_NODE_MODE_OPERATIONAL                                0
#define UAVCAN_NODE_MODE_INITIALIZATION                             1

#define UAVCAN_GET_NODE_INFO_RESPONSE_MAX_SIZE                      ((3015 + 7) / 8)
#define UAVCAN_GET_NODE_INFO_DATA_TYPE_SIGNATURE                    0xee468a8121c46a9e
#define UAVCAN_GET_NODE_INFO_DATA_TYPE_ID                           1


static CanardInstance g_canard;                     ///< The library instance
static uint8_t g_canard_memory_pool[1024];          ///< Arena for memory allocation, used by the library


static uint64_t getMonotonicTimestampUSec(void)
{
    struct timespec ts;
    memset(&ts, 0, sizeof(ts));
    if (clock_gettime(CLOCK_MONOTONIC, &ts) != 0) {
        abort();
    }
    return (uint64_t)(ts.tv_sec * 1000000LL + ts.tv_nsec / 1000LL);
}

static void makeNodeStatusMessage(uint8_t buffer[UAVCAN_NODE_STATUS_MESSAGE_SIZE])
{
    memset(buffer, 0, UAVCAN_NODE_STATUS_MESSAGE_SIZE);

    static uint8_t g_node_health = 0x3;
    static uint8_t g_node_mode   = 0x2;

    static uint32_t started_at_sec = 0;
    if (started_at_sec == 0) {
        started_at_sec = (uint32_t)(getMonotonicTimestampUSec() / 1000000U);
    }

    const uint32_t uptime_sec = (uint32_t)((getMonotonicTimestampUSec() / 1000000U) - started_at_sec);


    /* Here we're using the helper for demonstrational purposes; in this simple case it could be preferred to encode the values manually. */
    canardEncodeScalar(buffer,  0, 32, &uptime_sec);
    canardEncodeScalar(buffer, 32,  2, &g_node_health);
    canardEncodeScalar(buffer, 34,  3, &g_node_mode);
}

/* This callback is invoked by the library when a new message or request or response is received. */
static void onTransferReceived(CanardInstance* ins, CanardRxTransfer* transfer)
{
    if ((transfer->transfer_type == CanardTransferTypeRequest) && (transfer->data_type_id == UAVCAN_GET_NODE_INFO_DATA_TYPE_ID)) {

    	printf("GetNodeInfo request from %d\n", transfer->source_node_id);

        uint8_t buffer[UAVCAN_GET_NODE_INFO_RESPONSE_MAX_SIZE];
        memset(buffer, 0, UAVCAN_GET_NODE_INFO_RESPONSE_MAX_SIZE);

        // NodeStatus
        makeNodeStatusMessage(buffer);
        // SoftwareVersion
        buffer[7] = APP_VERSION_MAJOR;
        buffer[8] = APP_VERSION_MINOR;
        buffer[9] = 1;                          // Optional field flags, VCS commit is set
        //uint32_t u32 = GIT_HASH;
        uint32_t u32 = 12345;
        canardEncodeScalar(buffer, 80, 32, &u32);
        // Image CRC skipped
        // HardwareVersion
        // Major skipped
        // Minor skipped
        buffer[24] = UNIQUE_ID;
        // Certificate of authenticity skipped
        // Name
        const size_t name_len = strlen(APP_NODE_NAME);
        memcpy(&buffer[41], APP_NODE_NAME, name_len);
        const size_t total_size = 41 + name_len;

        /* Transmitting; in this case we don't have to release the payload because it's empty anyway. */
        const int16_t resp_res = canardRequestOrRespond(ins, transfer->source_node_id, UAVCAN_GET_NODE_INFO_DATA_TYPE_SIGNATURE, UAVCAN_GET_NODE_INFO_DATA_TYPE_ID, &transfer->transfer_id, transfer->priority, CanardResponse, &buffer[0], (uint16_t)total_size);
        if (resp_res <= 0) {
            (void)fprintf(stderr, "Could not respond to GetNodeInfo; error %d\n", resp_res);
        }
    }
}


/*
 * This callback is invoked by the library when it detects beginning of a new transfer on the bus that can be received by the local node.
 * If the callback returns true, the library will receive the transfer.
 * If the callback returns false, the library will ignore the transfer.
 * All transfers that are addressed to other nodes are always ignored. */
static bool shouldAcceptTransfer(const CanardInstance* ins, uint64_t* out_data_type_signature, uint16_t data_type_id, CanardTransferType transfer_type, uint8_t source_node_id)
{
    (void)source_node_id;

    if (canardGetLocalNodeID(ins) == CANARD_BROADCAST_NODE_ID) {

    	/* If we're in the process of allocation of dynamic node ID, accept only relevant transfers. */
        if ((transfer_type == CanardTransferTypeBroadcast) && (data_type_id == UAVCAN_NODE_ID_ALLOCATION_DATA_TYPE_ID)) {
            *out_data_type_signature = UAVCAN_NODE_ID_ALLOCATION_DATA_TYPE_SIGNATURE;
            return true;
        }
    }
    else {

    	if ((transfer_type == CanardTransferTypeRequest) && (data_type_id == UAVCAN_GET_NODE_INFO_DATA_TYPE_ID)) {
            *out_data_type_signature = UAVCAN_GET_NODE_INFO_DATA_TYPE_SIGNATURE;
            return true;
        }
    }

    return false;
}


/* This function is called at 1 Hz rate from the main loop. */
static void process1HzTasks(uint64_t timestamp_usec)
{
    /* Purging transfers that are no longer transmitted. This will occasionally free up some memory. */
    canardCleanupStaleTransfers(&g_canard, timestamp_usec);

    /* Printing the memory usage statistics. */
    const CanardPoolAllocatorStatistics stats = canardGetPoolAllocatorStatistics(&g_canard);
    const uint16_t peak_percent = (uint16_t)(100U * stats.peak_usage_blocks / stats.capacity_blocks);

    printf("Memory pool stats: capacity %u blocks, usage %u blocks, peak usage %u blocks (%u%%)\n", stats.capacity_blocks, stats.current_usage_blocks, stats.peak_usage_blocks, peak_percent);

    /* The recommended way to establish the minimal size of the memory pool is to stress-test the application and record the worst case memory usage. */
    if (peak_percent > 70) {
        puts("WARNING: ENLARGE MEMORY POOL");
    }

    /* Transmit the node status message. */
    uint8_t buffer[UAVCAN_NODE_STATUS_MESSAGE_SIZE];
    makeNodeStatusMessage(buffer);

    // Note that the transfer ID variable MUST BE STATIC (or heap-allocated)!
    static uint8_t transfer_id;
    const int16_t bc_res = canardBroadcast(&g_canard, UAVCAN_NODE_STATUS_DATA_TYPE_SIGNATURE, UAVCAN_NODE_STATUS_DATA_TYPE_ID, &transfer_id, CANARD_TRANSFER_PRIORITY_LOW, buffer, UAVCAN_NODE_STATUS_MESSAGE_SIZE);
    if (bc_res <= 0) {
        (void)fprintf(stderr, "Could not broadcast node status; error %d\n", bc_res);
    }
}


/* Transmits all frames from the TX queue, receives up to one frame. */
static void processTxRxOnce(SocketCANInstance* socketcan, int32_t timeout_msec)
{
    // Transmitting
    for (const CanardCANFrame* txf = NULL; (txf = canardPeekTxQueue(&g_canard)) != NULL;) {
        const int16_t tx_res = socketcanTransmit(socketcan, txf, 0);
        // Failure - drop the frame and report
        if (tx_res < 0){
            canardPopTxQueue(&g_canard);
            (void)fprintf(stderr, "Transmit error %d, frame dropped, errno '%s'\n", tx_res, strerror(errno));
        }
        // Success - just drop the frame
        else if (tx_res > 0){
            canardPopTxQueue(&g_canard);
        }
        // Timeout - just exit and try again later
        else {
            break;
        }
    }

    // Receiving
    CanardCANFrame rx_frame;
    const uint64_t timestamp = getMonotonicTimestampUSec();
    const int16_t rx_res = socketcanReceive(socketcan, &rx_frame, timeout_msec);
    // Failure - report
    if (rx_res < 0){
        (void)fprintf(stderr, "Receive error %d, errno '%s'\n", rx_res, strerror(errno));
    }
    // Success - process the frame
    else if (rx_res > 0)        {
        canardHandleRxFrame(&g_canard, &rx_frame, timestamp);
    }
    // Timeout - nothing to do
    else{
        ;
    }
}


int main(void)
{
    /* Initialize SocketCAN */
    SocketCANInstance socketcan;

    const char* const can_iface_name = "can0";
    int16_t res = socketcanInit(&socketcan, can_iface_name);
    if (res < 0) {
        (void)fprintf(stderr, "Failed to open CAN iface '%s'\n", can_iface_name);
        return 1;
    }

    /* Initialize a Libcanard instance. */
    canardInit(&g_canard, g_canard_memory_pool, sizeof(g_canard_memory_pool), onTransferReceived, shouldAcceptTransfer, NULL);
    canardSetLocalNodeID(&g_canard, 126);

    /* Run the main loop. */
    uint64_t next_1hz_service_at = getMonotonicTimestampUSec();

    for (;;) {
        processTxRxOnce(&socketcan, 10);

        const uint64_t ts = getMonotonicTimestampUSec();

        if (ts >= next_1hz_service_at) {
            next_1hz_service_at += 1000000;
            process1HzTasks(ts);
        }
    }

    return 0;
}
