/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/protocol/file/46.GetDirectoryEntryInfo.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO
#define __UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/file/EntryType.h>
#include <uavcan/protocol/file/Error.h>
#include <uavcan/protocol/file/Path.h>

/******************************* Source text **********************************
#
# This service can be used to retrieve a remote directory listing, one entry per request.
#
# The client should query each entry independently, iterating 'entry_index' from 0 until the last entry is passed,
# in which case the server will report that there is no such entry (via the fields 'entry_type' and 'error').
#
# The entry_index shall be applied to the ordered list of directory entries (e.g. alphabetically ordered). The exact
# sorting criteria does not matter as long as it provides the same ordering for subsequent service calls.
#

uint32 entry_index

Path directory_path

---

Error error

EntryType entry_type

Path entry_full_path  # Ignored/Empty if such entry does not exist.
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.file.GetDirectoryEntryInfo
saturated uint32 entry_index
uavcan.protocol.file.Path directory_path
---
uavcan.protocol.file.Error error
uavcan.protocol.file.EntryType entry_type
uavcan.protocol.file.Path entry_full_path
******************************************************************************/

#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_ID      46
#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_NAME    "uavcan.protocol.file.GetDirectoryEntryInfo"
#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_SIGNATURE (0x8C46E8AB568BDA79ULL)

#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_REQUEST_MAX_SIZE ((1640 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint32_t   entry_index;                   // bit len 32
    uavcan_protocol_file_Path directory_path;                //

} uavcan_protocol_file_GetDirectoryEntryInfoRequest;

static inline
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_encode(uavcan_protocol_file_GetDirectoryEntryInfoRequest* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetDirectoryEntryInfoRequest* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_encode_internal(uavcan_protocol_file_GetDirectoryEntryInfoRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetDirectoryEntryInfoRequest* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

#define UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO_RESPONSE_MAX_SIZE ((1632 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uavcan_protocol_file_Error error;                         //
    uavcan_protocol_file_EntryType entry_type;                    //
    uavcan_protocol_file_Path entry_full_path;               //

} uavcan_protocol_file_GetDirectoryEntryInfoResponse;

static inline
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_encode(uavcan_protocol_file_GetDirectoryEntryInfoResponse* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetDirectoryEntryInfoResponse* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_encode_internal(uavcan_protocol_file_GetDirectoryEntryInfoResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_file_GetDirectoryEntryInfoResponse* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/protocol/file/46.GetDirectoryEntryInfo.uavcan
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
  * @brief uavcan_protocol_file_GetDirectoryEntryInfoRequest_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_encode_internal(uavcan_protocol_file_GetDirectoryEntryInfoRequest* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->entry_index); // 4294967295
    offset += 32;

    // Compound
    offset = uavcan_protocol_file_Path_encode_internal(&source->directory_path, msg_buf, offset, 0, tao_enabled);

    return offset;
}

/**
  * @brief uavcan_protocol_file_GetDirectoryEntryInfoRequest_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_encode(uavcan_protocol_file_GetDirectoryEntryInfoRequest* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_file_GetDirectoryEntryInfoRequest_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_file_GetDirectoryEntryInfoRequest_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_file_GetDirectoryEntryInfoRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_file_GetDirectoryEntryInfoRequest* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 32, false, (void*)&dest->entry_index);
    if (ret != 32)
    {
        goto uavcan_protocol_file_GetDirectoryEntryInfoRequest_error_exit;
    }
    offset += 32;

    // Compound
    offset = uavcan_protocol_file_Path_decode_internal(transfer, payload_len, &dest->directory_path, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_file_GetDirectoryEntryInfoRequest_error_exit;
    }
    return offset;

uavcan_protocol_file_GetDirectoryEntryInfoRequest_error_exit:
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
  * @brief uavcan_protocol_file_GetDirectoryEntryInfoRequest_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_file_GetDirectoryEntryInfoRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_file_GetDirectoryEntryInfoRequest_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_file_GetDirectoryEntryInfoRequest* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_file_GetDirectoryEntryInfoRequest); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_file_GetDirectoryEntryInfoRequest_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

/**
  * @brief uavcan_protocol_file_GetDirectoryEntryInfoResponse_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_encode_internal(uavcan_protocol_file_GetDirectoryEntryInfoResponse* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    // Compound
    offset = uavcan_protocol_file_Error_encode_internal(&source->error, msg_buf, offset, 0, tao_enabled);

    // Compound
    offset = uavcan_protocol_file_EntryType_encode_internal(&source->entry_type, msg_buf, offset, 0, tao_enabled);

    // Compound
    offset = uavcan_protocol_file_Path_encode_internal(&source->entry_full_path, msg_buf, offset, 0, tao_enabled);

    return offset;
}

/**
  * @brief uavcan_protocol_file_GetDirectoryEntryInfoResponse_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_encode(uavcan_protocol_file_GetDirectoryEntryInfoResponse* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_file_GetDirectoryEntryInfoResponse_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_file_GetDirectoryEntryInfoResponse_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_file_GetDirectoryEntryInfoResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_file_GetDirectoryEntryInfoResponse* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;

    // Compound
    offset = uavcan_protocol_file_Error_decode_internal(transfer, payload_len, &dest->error, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_file_GetDirectoryEntryInfoResponse_error_exit;
    }

    // Compound
    offset = uavcan_protocol_file_EntryType_decode_internal(transfer, payload_len, &dest->entry_type, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_file_GetDirectoryEntryInfoResponse_error_exit;
    }

    // Compound
    offset = uavcan_protocol_file_Path_decode_internal(transfer, payload_len, &dest->entry_full_path, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_file_GetDirectoryEntryInfoResponse_error_exit;
    }
    return offset;

uavcan_protocol_file_GetDirectoryEntryInfoResponse_error_exit:
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
  * @brief uavcan_protocol_file_GetDirectoryEntryInfoResponse_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_file_GetDirectoryEntryInfoResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_file_GetDirectoryEntryInfoResponse_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_file_GetDirectoryEntryInfoResponse* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_file_GetDirectoryEntryInfoResponse); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_file_GetDirectoryEntryInfoResponse_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_FILE_GETDIRECTORYENTRYINFO