/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/dynamic_node_id/1.Allocation.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION
#define __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# This message is used for dynamic Node ID allocation.
#
# When a node needs to request a node ID dynamically, it will transmit an anonymous message transfer of this type.
# In order to reduce probability of CAN ID collisions when multiple nodes are publishing this request, the CAN ID
# field of anonymous message transfer includes a Discriminator, which is a special field that has to be filled with
# random data by the transmitting node. Since Discriminator collisions are likely to happen (probability approx.
# 0.006%), nodes that are requesting dynamic allocations need to be able to handle them correctly. Hence, a collision
# resolution protocol is defined (alike CSMA/CD). The collision resolution protocol is based on two randomized
# transmission intervals:
#
# - Request period - Trequest.
# - Follow up delay - Tfollowup.
#
# Recommended randomization ranges for these intervals are documented in the constants of this message type (see below).
# Random intervals must be chosen anew per transmission, whereas the Discriminator value is allowed to stay constant
# per node.
#
# In the below description the following terms are used:
# - Allocator - the node that serves allocation requests.
# - Allocatee - the node that requests an allocation from the Allocator.
#
# The response timeout is not explicitly defined for this protocol, as the Allocatee will request the allocation
# Trequest units of time later again, unless the allocation has been granted. Despite this, the implementation can
# consider the value of FOLLOWUP_TIMEOUT_MS as an allocation timeout, if necessary.
#
# On the allocatee's side the protocol is defined through the following set of rules:
#
# Rule A. On initialization:
# 1. The allocatee subscribes to this message.
# 2. The allocatee starts the Request Timer with a random interval of Trequest.
#
# Rule B. On expiration of Request Timer:
# 1. Request Timer restarts with a random interval of Trequest.
# 2. The allocatee broadcasts a first-stage Allocation request message, where the fields are assigned following values:
#    node_id                 - preferred node ID, or zero if the allocatee doesn't have any preference
#    first_part_of_unique_id - true
#    unique_id               - first MAX_LENGTH_OF_UNIQUE_ID_IN_REQUEST bytes of unique ID
#
# Rule C. On any Allocation message, even if other rules also match:
# 1. Request Timer restarts with a random interval of Trequest.
#
# Rule D. On an Allocation message WHERE (source node ID is non-anonymous) AND (allocatee's unique ID starts with the
# bytes available in the field unique_id) AND (unique_id is less than 16 bytes long):
# 1. The allocatee waits for Tfollowup units of time, while listening for other Allocation messages. If an Allocation
#    message is received during this time, the execution of this rule will be terminated. Also see rule C.
# 2. The allocatee broadcasts a second-stage Allocation request message, where the fields are assigned following values:
#    node_id                 - same value as in the first-stage
#    first_part_of_unique_id - false
#    unique_id               - at most MAX_LENGTH_OF_UNIQUE_ID_IN_REQUEST bytes of local unique ID with an offset
#                              equal to number of bytes in the received unique ID
#
# Rule E. On an Allocation message WHERE (source node ID is non-anonymous) AND (unique_id fully matches allocatee's
# unique ID) AND (node_id in the received message is not zero):
# 1. Request Timer stops.
# 2. The allocatee initializes its node_id with the received value.
# 3. The allocatee terminates subscription to Allocation messages.
# 4. Exit.
#

#
# Recommended randomization range for request period.
#
# These definitions have an advisory status; it is OK to pick higher values for both bounds, as it won't affect
# protocol compatibility. In fact, it is advised to pick higher values if the target application is not concerned
# about the time it will spend on completing the dynamic node ID allocation procedure, as it will reduce
# interference with other nodes, possibly of higher importance.
#
# The lower bound shall not be lower than FOLLOWUP_TIMEOUT_MS, otherwise the request may conflict with a followup.
#
uint16 MAX_REQUEST_PERIOD_MS = 1000     # It is OK to exceed this value
uint16 MIN_REQUEST_PERIOD_MS = 600      # It is OK to exceed this value

#
# Recommended randomization range for followup delay.
# The upper bound shall not exceed FOLLOWUP_TIMEOUT_MS, because the allocator will reset the state on its end.
#
uint16 MAX_FOLLOWUP_DELAY_MS = 400
uint16 MIN_FOLLOWUP_DELAY_MS = 0        # Defined only for regularity; will always be zero.

#
# Allocator will reset its state if there was no follow-up request in this amount of time.
#
uint16 FOLLOWUP_TIMEOUT_MS = 500

#
# Any request message can accommodate no more than this number of bytes of unique ID.
# This limitation is needed to ensure that all request transfers are single-frame.
# This limitation does not apply to CAN FD transport.
#
uint8 MAX_LENGTH_OF_UNIQUE_ID_IN_REQUEST = 6

#
# When requesting an allocation, set the field 'node_id' to this value if there's no preference.
#
uint7 ANY_NODE_ID = 0

#
# If transfer is anonymous, this is the preferred ID.
# If transfer is non-anonymous, this is allocated ID.
#
# If the allocatee does not have any preference, this value must be set to zero. In this case, the allocator
# must choose the highest unused node ID value for this allocation (except 126 and 127, that are reserved for
# network maintenance tools). E.g., if the allocation table is empty and the node has requested an allocation
# without any preference, the allocator will grant the node ID 125.
#
# If the preferred node ID is not zero, the allocator will traverse the allocation table starting from the
# preferred node ID upward, until a free node ID is found. If a free node ID could not be found, the
# allocator will restart the search from the preferred node ID downward, until a free node ID is found.
#
# In pseudocode:
#   int findFreeNodeID(const int preferred)
#   {
#       // Search up
#       int candidate = (preferred > 0) ? preferred : 125;
#       while (candidate <= 125)
#       {
#           if (!isOccupied(candidate))
#               return candidate;
#           candidate++;
#       }
#       // Search down
#       candidate = (preferred > 0) ? preferred : 125;
#       while (candidate > 0)
#       {
#           if (!isOccupied(candidate))
#               return candidate;
#           candidate--;
#       }
#       // Not found
#       return -1;
#   }
#
uint7 node_id

#
# If transfer is anonymous, this field indicates first-stage request.
# If transfer is non-anonymous, this field should be assigned zero and ignored.
#
bool first_part_of_unique_id

#
# If transfer is anonymous, this array must not contain more than MAX_LENGTH_OF_UNIQUE_ID_IN_REQUEST items.
# Note that array is tail-optimized, i.e. it will not be prepended with length field.
#
uint8[<=16] unique_id
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.dynamic_node_id.Allocation
saturated uint7 node_id
saturated bool first_part_of_unique_id
saturated uint8[<=16] unique_id
******************************************************************************/

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ID      1
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_NAME    "uavcan.protocol.dynamic_node_id.Allocation"
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_SIGNATURE (0xB2A812620A11D40ULL)

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_MAX_SIZE ((141 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_MAX_REQUEST_PERIOD_MS       1000 // 1000
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_MIN_REQUEST_PERIOD_MS        600 // 600
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_MAX_FOLLOWUP_DELAY_MS        400 // 400
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_MIN_FOLLOWUP_DELAY_MS          0 // 0
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_FOLLOWUP_TIMEOUT_MS        500 // 500
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_MAX_LENGTH_OF_UNIQUE_ID_IN_REQUEST          6 // 6
#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_ANY_NODE_ID                0 // 0

#define UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION_UNIQUE_ID_MAX_LENGTH                  16

typedef struct
{
    // FieldTypes
    uint8_t    node_id;                       // bit len 7
    bool       first_part_of_unique_id;       // bit len 1
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[16] max items
    } unique_id;

} uavcan_protocol_dynamic_node_id_Allocation;

static inline
uint32_t uavcan_protocol_dynamic_node_id_Allocation_encode(uavcan_protocol_dynamic_node_id_Allocation* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_protocol_dynamic_node_id_Allocation_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_Allocation* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_protocol_dynamic_node_id_Allocation_encode_internal(uavcan_protocol_dynamic_node_id_Allocation* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_protocol_dynamic_node_id_Allocation_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_dynamic_node_id_Allocation* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/dynamic_node_id/1.Allocation.uavcan
 */

#ifndef CANARD_INTERNAL_SATURATE
#define CANARD_INTERNAL_SATURATE(x, max) ( ((x) > max) ? max : ( (-(x) > max) ? (-max) : (x) ) );
#endif

#ifndef CANARD_INTERNAL_SATURATE_UNSIGNED
#define CANARD_INTERNAL_SATURATE_UNSIGNED(x, max) ( ((x) >= max) ? max : (x) );
#endif

#if defined(__GNUC__)
# define CANARD_MAYBE_UNUSED(x) x __attribute__((unused))
#else
# define CANARD_MAYBE_UNUSED(x) x
#endif

/**
  * @brief uavcan_protocol_dynamic_node_id_Allocation_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_dynamic_node_id_Allocation_encode_internal(uavcan_protocol_dynamic_node_id_Allocation* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    uint32_t c = 0;

    source->node_id = CANARD_INTERNAL_SATURATE_UNSIGNED(source->node_id, 127)
    canardEncodeScalar(msg_buf, offset, 7, (void*)&source->node_id); // 127
    offset += 7;

    source->first_part_of_unique_id = CANARD_INTERNAL_SATURATE_UNSIGNED(source->first_part_of_unique_id, 1)
    canardEncodeScalar(msg_buf, offset, 1, (void*)&source->first_part_of_unique_id); // 1
    offset += 1;

    // Dynamic Array (unique_id)
    if (! root_item || ! tao_enabled)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 5, (void*)&source->unique_id.len);
        offset += 5;
    }

    // - Add array items
    for (c = 0; c < source->unique_id.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           8,
                           (void*)(source->unique_id.data + c));// 255
        offset += 8;
    }

    return offset;
}

/**
  * @brief uavcan_protocol_dynamic_node_id_Allocation_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_dynamic_node_id_Allocation_encode(uavcan_protocol_dynamic_node_id_Allocation* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_dynamic_node_id_Allocation_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_dynamic_node_id_Allocation_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_dynamic_node_id_Allocation dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_dynamic_node_id_Allocation_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_dynamic_node_id_Allocation* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;
    uint32_t c = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 7, false, (void*)&dest->node_id);
    if (ret != 7)
    {
        goto uavcan_protocol_dynamic_node_id_Allocation_error_exit;
    }
    offset += 7;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 1, false, (void*)&dest->first_part_of_unique_id);
    if (ret != 1)
    {
        goto uavcan_protocol_dynamic_node_id_Allocation_error_exit;
    }
    offset += 1;

    // Dynamic Array (unique_id)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao_enabled)
    {
        //  - Calculate Array length from MSG length
        dest->unique_id.len = ((payload_len * 8) - offset ) / 8; // 8 bit array item size
    }
    else
    {
        // - Array length 5 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 5,
                                 false,
                                 (void*)&dest->unique_id.len); // 255
        if (ret != 5)
        {
            goto uavcan_protocol_dynamic_node_id_Allocation_error_exit;
        }
        offset += 5;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->unique_id.data = (uint8_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->unique_id.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer,
                                     (uint32_t)offset,
                                     8,
                                     false,
                                     (void*)*dyn_arr_buf); // 255
            if (ret != 8)
            {
                goto uavcan_protocol_dynamic_node_id_Allocation_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((uint8_t*)*dyn_arr_buf) + 1);
        }
        offset += 8;
    }
    return offset;

uavcan_protocol_dynamic_node_id_Allocation_error_exit:
    if (ret < 0)
    {
        return ret;
    }
    else
    {
        return -CANARD_ERROR_INTERNAL;
    }
}

/**
  * @brief uavcan_protocol_dynamic_node_id_Allocation_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_dynamic_node_id_Allocation dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_dynamic_node_id_Allocation_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_dynamic_node_id_Allocation* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_dynamic_node_id_Allocation); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_dynamic_node_id_Allocation_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_DYNAMIC_NODE_ID_ALLOCATION