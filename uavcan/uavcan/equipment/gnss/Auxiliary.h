/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/equipment/gnss/1061.Auxiliary.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_GNSS_AUXILIARY
#define __UAVCAN_EQUIPMENT_GNSS_AUXILIARY

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# GNSS low priority auxiliary info.
# Unknown DOP parameters should be set to NAN.
#

float16 gdop
float16 pdop
float16 hdop
float16 vdop
float16 tdop
float16 ndop
float16 edop

uint7 sats_visible                    # All visible sats of all available GNSS (e.g. GPS, GLONASS, etc)
uint6 sats_used                       # All used sats of all available GNSS
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.gnss.Auxiliary
saturated float16 gdop
saturated float16 pdop
saturated float16 hdop
saturated float16 vdop
saturated float16 tdop
saturated float16 ndop
saturated float16 edop
saturated uint7 sats_visible
saturated uint6 sats_used
******************************************************************************/

#define UAVCAN_EQUIPMENT_GNSS_AUXILIARY_ID                 1061
#define UAVCAN_EQUIPMENT_GNSS_AUXILIARY_NAME               "uavcan.equipment.gnss.Auxiliary"
#define UAVCAN_EQUIPMENT_GNSS_AUXILIARY_SIGNATURE          (0x9BE8BDC4C3DBBFD2ULL)

#define UAVCAN_EQUIPMENT_GNSS_AUXILIARY_MAX_SIZE           ((125 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    float      gdop;                          // float16 Saturate
    float      pdop;                          // float16 Saturate
    float      hdop;                          // float16 Saturate
    float      vdop;                          // float16 Saturate
    float      tdop;                          // float16 Saturate
    float      ndop;                          // float16 Saturate
    float      edop;                          // float16 Saturate
    uint8_t    sats_visible;                  // bit len 7
    uint8_t    sats_used;                     // bit len 6

} uavcan_equipment_gnss_Auxiliary;

static inline
uint32_t uavcan_equipment_gnss_Auxiliary_encode(uavcan_equipment_gnss_Auxiliary* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_equipment_gnss_Auxiliary_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_gnss_Auxiliary* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_equipment_gnss_Auxiliary_encode_internal(uavcan_equipment_gnss_Auxiliary* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_equipment_gnss_Auxiliary_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_gnss_Auxiliary* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/equipment/gnss/1061.Auxiliary.uavcan
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
  * @brief uavcan_equipment_gnss_Auxiliary_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_gnss_Auxiliary_encode_internal(uavcan_equipment_gnss_Auxiliary* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->gdop);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->gdop;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->pdop);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->pdop;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->hdop);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->hdop;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->vdop);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->vdop;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->tdop);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->tdop;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->ndop);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->ndop;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->edop);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->edop;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;
    source->sats_visible = CANARD_INTERNAL_SATURATE_UNSIGNED(source->sats_visible, 127)
    canardEncodeScalar(msg_buf, offset, 7, (void*)&source->sats_visible); // 127
    offset += 7;

    source->sats_used = CANARD_INTERNAL_SATURATE_UNSIGNED(source->sats_used, 63)
    canardEncodeScalar(msg_buf, offset, 6, (void*)&source->sats_used); // 63
    offset += 6;

    return offset;
}

/**
  * @brief uavcan_equipment_gnss_Auxiliary_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_gnss_Auxiliary_encode(uavcan_equipment_gnss_Auxiliary* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_gnss_Auxiliary_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_gnss_Auxiliary_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_gnss_Auxiliary dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_gnss_Auxiliary_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_gnss_Auxiliary* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_gnss_Auxiliary_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->gdop = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->gdop = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_gnss_Auxiliary_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->pdop = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->pdop = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_gnss_Auxiliary_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->hdop = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->hdop = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_gnss_Auxiliary_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->vdop = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->vdop = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_gnss_Auxiliary_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->tdop = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->tdop = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_gnss_Auxiliary_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->ndop = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->ndop = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_gnss_Auxiliary_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->edop = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->edop = (float)tmp_float;
#endif
    offset += 16;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 7, false, (void*)&dest->sats_visible);
    if (ret != 7)
    {
        goto uavcan_equipment_gnss_Auxiliary_error_exit;
    }
    offset += 7;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 6, false, (void*)&dest->sats_used);
    if (ret != 6)
    {
        goto uavcan_equipment_gnss_Auxiliary_error_exit;
    }
    offset += 6;
    return offset;

uavcan_equipment_gnss_Auxiliary_error_exit:
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
  * @brief uavcan_equipment_gnss_Auxiliary_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_gnss_Auxiliary dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_gnss_Auxiliary_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_gnss_Auxiliary* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_gnss_Auxiliary); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_gnss_Auxiliary_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_GNSS_AUXILIARY