/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/file/40.BeginFirmwareUpdate.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE
#define __UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/file/Path.h>

/******************************* Source text **********************************
#
# This service initiates firmware update on a remote node.
#
# The node that is being updated (slave) will retrieve the firmware image file 'image_file_remote_path' from the node
# 'source_node_id' using the file read service, then it will update the firmware and reboot.
#
# The slave can explicitly reject this request if it is not possible to update the firmware at the moment
# (e.g. if the node is busy).
#
# If the slave node accepts this request, the initiator will get a response immediately, before the update process
# actually begins.
#
# While the firmware is being updated, the slave should set its mode (uavcan.protocol.NodeStatus.mode) to
# MODE_SOFTWARE_UPDATE.
#

uint8 source_node_id         # If this field is zero, the caller's Node ID will be used instead.
Path image_file_remote_path

---

#
# Other error codes may be added in the future.
#
uint8 ERROR_OK               = 0
uint8 ERROR_INVALID_MODE     = 1    # Cannot perform the update in the current operating mode or state.
uint8 ERROR_IN_PROGRESS      = 2    # Firmware update is already in progress, and the slave doesn't want to restart.
uint8 ERROR_UNKNOWN          = 255
uint8 error

uint8[<128] optional_error_message   # Detailed description of the error.
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.file.BeginFirmwareUpdate
saturated uint8 source_node_id
uavcan.protocol.file.Path image_file_remote_path
---
saturated uint8 error
saturated uint8[<=127] optional_error_message
******************************************************************************/

#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_ID        40
#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_NAME      "uavcan.protocol.file.BeginFirmwareUpdate"
#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_SIGNATURE (0xB7D725DF72724126ULL)

#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_REQUEST_MAX_SIZE ((1616 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint8_t    source_node_id;                // bit len 8
    uavcan_protocol_file_Path image_file_remote_path;        //

} uavcan_protocol_file_BeginFirmwareUpdateRequest;

static inline
uint32_t uavcan_protocol_file_BeginFirmwareUpdateRequest_encode(uavcan_protocol_file_BeginFirmwareUpdateRequest* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_protocol_file_BeginFirmwareUpdateRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_BeginFirmwareUpdateRequest* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_protocol_file_BeginFirmwareUpdateRequest_encode_internal(uavcan_protocol_file_BeginFirmwareUpdateRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_protocol_file_BeginFirmwareUpdateRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_BeginFirmwareUpdateRequest* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_RESPONSE_MAX_SIZE ((1031 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_RESPONSE_ERROR_OK            0 // 0
#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_RESPONSE_ERROR_INVALID_MODE          1 // 1
#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_RESPONSE_ERROR_IN_PROGRESS          2 // 2
#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_RESPONSE_ERROR_UNKNOWN        255 // 255

#define UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE_RESPONSE_OPTIONAL_ERROR_MESSAGE_MAX_LENGTH 127

typedef struct
{
    // FieldTypes
    uint8_t    error;                         // bit len 8
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[127] max items
    } optional_error_message;

} uavcan_protocol_file_BeginFirmwareUpdateResponse;

static inline
uint32_t uavcan_protocol_file_BeginFirmwareUpdateResponse_encode(uavcan_protocol_file_BeginFirmwareUpdateResponse* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_protocol_file_BeginFirmwareUpdateResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_BeginFirmwareUpdateResponse* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_protocol_file_BeginFirmwareUpdateResponse_encode_internal(uavcan_protocol_file_BeginFirmwareUpdateResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_protocol_file_BeginFirmwareUpdateResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_BeginFirmwareUpdateResponse* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/file/40.BeginFirmwareUpdate.uavcan
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
  * @brief uavcan_protocol_file_BeginFirmwareUpdateRequest_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_file_BeginFirmwareUpdateRequest_encode_internal(uavcan_protocol_file_BeginFirmwareUpdateRequest* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->source_node_id); // 255
    offset += 8;

    // Compound
    offset = uavcan_protocol_file_Path_encode_internal(&source->image_file_remote_path, msg_buf, offset, 0, tao_enabled);

    return offset;
}

/**
  * @brief uavcan_protocol_file_BeginFirmwareUpdateRequest_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_file_BeginFirmwareUpdateRequest_encode(uavcan_protocol_file_BeginFirmwareUpdateRequest* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_file_BeginFirmwareUpdateRequest_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_file_BeginFirmwareUpdateRequest_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_file_BeginFirmwareUpdateRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_file_BeginFirmwareUpdateRequest_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_file_BeginFirmwareUpdateRequest* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 8, false, (void*)&dest->source_node_id);
    if (ret != 8)
    {
        goto uavcan_protocol_file_BeginFirmwareUpdateRequest_error_exit;
    }
    offset += 8;

    // Compound
    offset = uavcan_protocol_file_Path_decode_internal(transfer, payload_len, &dest->image_file_remote_path, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_file_BeginFirmwareUpdateRequest_error_exit;
    }
    return offset;

uavcan_protocol_file_BeginFirmwareUpdateRequest_error_exit:
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
  * @brief uavcan_protocol_file_BeginFirmwareUpdateRequest_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_file_BeginFirmwareUpdateRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_file_BeginFirmwareUpdateRequest_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_file_BeginFirmwareUpdateRequest* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_file_BeginFirmwareUpdateRequest); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_file_BeginFirmwareUpdateRequest_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

/**
  * @brief uavcan_protocol_file_BeginFirmwareUpdateResponse_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_file_BeginFirmwareUpdateResponse_encode_internal(uavcan_protocol_file_BeginFirmwareUpdateResponse* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    uint32_t c = 0;

    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->error); // 255
    offset += 8;

    // Dynamic Array (optional_error_message)
    if (! root_item || ! tao_enabled)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 7, (void*)&source->optional_error_message.len);
        offset += 7;
    }

    // - Add array items
    for (c = 0; c < source->optional_error_message.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           8,
                           (void*)(source->optional_error_message.data + c));// 255
        offset += 8;
    }

    return offset;
}

/**
  * @brief uavcan_protocol_file_BeginFirmwareUpdateResponse_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_file_BeginFirmwareUpdateResponse_encode(uavcan_protocol_file_BeginFirmwareUpdateResponse* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_file_BeginFirmwareUpdateResponse_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_file_BeginFirmwareUpdateResponse_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_file_BeginFirmwareUpdateResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_file_BeginFirmwareUpdateResponse_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_file_BeginFirmwareUpdateResponse* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;
    uint32_t c = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 8, false, (void*)&dest->error);
    if (ret != 8)
    {
        goto uavcan_protocol_file_BeginFirmwareUpdateResponse_error_exit;
    }
    offset += 8;

    // Dynamic Array (optional_error_message)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao_enabled)
    {
        //  - Calculate Array length from MSG length
        dest->optional_error_message.len = ((payload_len * 8) - offset ) / 8; // 8 bit array item size
    }
    else
    {
        // - Array length 7 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 7,
                                 false,
                                 (void*)&dest->optional_error_message.len); // 255
        if (ret != 7)
        {
            goto uavcan_protocol_file_BeginFirmwareUpdateResponse_error_exit;
        }
        offset += 7;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->optional_error_message.data = (uint8_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->optional_error_message.len; c++)
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
                goto uavcan_protocol_file_BeginFirmwareUpdateResponse_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((uint8_t*)*dyn_arr_buf) + 1);
        }
        offset += 8;
    }
    return offset;

uavcan_protocol_file_BeginFirmwareUpdateResponse_error_exit:
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
  * @brief uavcan_protocol_file_BeginFirmwareUpdateResponse_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_file_BeginFirmwareUpdateResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_file_BeginFirmwareUpdateResponse_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_file_BeginFirmwareUpdateResponse* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_file_BeginFirmwareUpdateResponse); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_file_BeginFirmwareUpdateResponse_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_FILE_BEGINFIRMWAREUPDATE