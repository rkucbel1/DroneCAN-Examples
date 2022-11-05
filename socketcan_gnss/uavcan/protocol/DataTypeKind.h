/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/DataTypeKind.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_DATATYPEKIND
#define __UAVCAN_PROTOCOL_DATATYPEKIND

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Data type kind (message or service).
#

uint8 SERVICE = 0
uint8 MESSAGE = 1
uint8 value
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.DataTypeKind
saturated uint8 value
******************************************************************************/

#define UAVCAN_PROTOCOL_DATATYPEKIND_NAME                  "uavcan.protocol.DataTypeKind"
#define UAVCAN_PROTOCOL_DATATYPEKIND_SIGNATURE             (0x9420A73E008E5930ULL)

#define UAVCAN_PROTOCOL_DATATYPEKIND_MAX_SIZE              ((8 + 7)/8)

// Constants
#define UAVCAN_PROTOCOL_DATATYPEKIND_SERVICE                                  0 // 0
#define UAVCAN_PROTOCOL_DATATYPEKIND_MESSAGE                                  1 // 1

typedef struct
{
    // FieldTypes
    uint8_t    value;                         // bit len 8

} uavcan_protocol_DataTypeKind;

static inline
uint32_t uavcan_protocol_DataTypeKind_encode(uavcan_protocol_DataTypeKind* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_protocol_DataTypeKind_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_DataTypeKind* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_protocol_DataTypeKind_encode_internal(uavcan_protocol_DataTypeKind* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_protocol_DataTypeKind_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_DataTypeKind* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/DataTypeKind.uavcan
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
  * @brief uavcan_protocol_DataTypeKind_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_DataTypeKind_encode_internal(uavcan_protocol_DataTypeKind* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->value); // 255
    offset += 8;

    return offset;
}

/**
  * @brief uavcan_protocol_DataTypeKind_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_DataTypeKind_encode(uavcan_protocol_DataTypeKind* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_DataTypeKind_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_DataTypeKind_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_DataTypeKind dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_DataTypeKind_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_DataTypeKind* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 8, false, (void*)&dest->value);
    if (ret != 8)
    {
        goto uavcan_protocol_DataTypeKind_error_exit;
    }
    offset += 8;
    return offset;

uavcan_protocol_DataTypeKind_error_exit:
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
  * @brief uavcan_protocol_DataTypeKind_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_DataTypeKind dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_DataTypeKind_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_DataTypeKind* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_DataTypeKind); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_DataTypeKind_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_DATATYPEKIND