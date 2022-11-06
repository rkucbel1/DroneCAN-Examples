/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/Timestamp.uavcan
 */

#ifndef __UAVCAN_TIMESTAMP
#define __UAVCAN_TIMESTAMP

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Global timestamp in microseconds, 7 bytes.
#
# Use this data type for timestamp fields in messages, like follows:
#   uavcan.Timestamp timestamp
#

uint56 UNKNOWN = 0
truncated uint56 usec     # Microseconds
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.Timestamp
truncated uint56 usec
******************************************************************************/

#define UAVCAN_TIMESTAMP_NAME                              "uavcan.Timestamp"
#define UAVCAN_TIMESTAMP_SIGNATURE                         (0x5BD0B5C81087E0DULL)

#define UAVCAN_TIMESTAMP_MAX_SIZE                          ((56 + 7)/8)

// Constants
#define UAVCAN_TIMESTAMP_UNKNOWN                                              0 // 0

typedef struct
{
    // FieldTypes
    uint64_t   usec;                          // bit len 56

} uavcan_Timestamp;

static inline
uint32_t uavcan_Timestamp_encode(uavcan_Timestamp* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_Timestamp_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_Timestamp* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_Timestamp_encode_internal(uavcan_Timestamp* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_Timestamp_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_Timestamp* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/Timestamp.uavcan
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
  * @brief uavcan_Timestamp_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_Timestamp_encode_internal(uavcan_Timestamp* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    canardEncodeScalar(msg_buf, offset, 56, (void*)&source->usec); // 72057594037927935
    offset += 56;

    return offset;
}

/**
  * @brief uavcan_Timestamp_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_Timestamp_encode(uavcan_Timestamp* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_Timestamp_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_Timestamp_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_Timestamp dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_Timestamp_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_Timestamp* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 56, false, (void*)&dest->usec);
    if (ret != 56)
    {
        goto uavcan_Timestamp_error_exit;
    }
    offset += 56;
    return offset;

uavcan_Timestamp_error_exit:
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
  * @brief uavcan_Timestamp_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_Timestamp dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_Timestamp_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_Timestamp* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_Timestamp); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_Timestamp_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_TIMESTAMP