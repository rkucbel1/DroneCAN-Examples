/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/enumeration/380.Indication.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_ENUMERATION_INDICATION
#define __UAVCAN_PROTOCOL_ENUMERATION_INDICATION

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/param/NumericValue.h>

/******************************* Source text **********************************
#
# This message will be broadcasted when the node receives user input in the process of enumeration.
#

void6

#
# This field is unused; keep it empty
#
uavcan.protocol.param.NumericValue value

#
# Name of the enumerated parameter.
# This field must always be populated by the enumeratee.
# If multiple parameters were enumerated at once (e.g. ESC index and the direction of rotation),
# the field should contain the name of the most important parameter.
#
uint8[<=92] parameter_name
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.enumeration.Indication
void6
uavcan.protocol.param.NumericValue value
saturated uint8[<=92] parameter_name
******************************************************************************/

#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_ID          380
#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_NAME        "uavcan.protocol.enumeration.Indication"
#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_SIGNATURE   (0x884CB63050A84F35ULL)

#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_MAX_SIZE    ((815 + 7)/8)

// Constants

#define UAVCAN_PROTOCOL_ENUMERATION_INDICATION_PARAMETER_NAME_MAX_LENGTH                 92

typedef struct
{
    // FieldTypes
    // void6
    uavcan_protocol_param_NumericValue value;                         //
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[92] max items
    } parameter_name;

} uavcan_protocol_enumeration_Indication;

static inline
uint32_t uavcan_protocol_enumeration_Indication_encode(uavcan_protocol_enumeration_Indication* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_protocol_enumeration_Indication_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_enumeration_Indication* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_protocol_enumeration_Indication_encode_internal(uavcan_protocol_enumeration_Indication* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_protocol_enumeration_Indication_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_enumeration_Indication* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/enumeration/380.Indication.uavcan
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
  * @brief uavcan_protocol_enumeration_Indication_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_enumeration_Indication_encode_internal(uavcan_protocol_enumeration_Indication* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    uint32_t c = 0;

    // Void6
    offset += 6;

    // Compound
    offset = uavcan_protocol_param_NumericValue_encode_internal(&source->value, msg_buf, offset, 0, tao_enabled);

    // Dynamic Array (parameter_name)
    if (! root_item || ! tao_enabled)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 7, (void*)&source->parameter_name.len);
        offset += 7;
    }

    // - Add array items
    for (c = 0; c < source->parameter_name.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           8,
                           (void*)(source->parameter_name.data + c));// 255
        offset += 8;
    }

    return offset;
}

/**
  * @brief uavcan_protocol_enumeration_Indication_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_enumeration_Indication_encode(uavcan_protocol_enumeration_Indication* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_enumeration_Indication_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_enumeration_Indication_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_enumeration_Indication dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_enumeration_Indication_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_enumeration_Indication* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;
    uint32_t c = 0;

    // Void6
    offset += 6;

    // Compound
    offset = uavcan_protocol_param_NumericValue_decode_internal(transfer, payload_len, &dest->value, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_enumeration_Indication_error_exit;
    }

    // Dynamic Array (parameter_name)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao_enabled)
    {
        //  - Calculate Array length from MSG length
        dest->parameter_name.len = ((payload_len * 8) - offset ) / 8; // 8 bit array item size
    }
    else
    {
        // - Array length 7 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 7,
                                 false,
                                 (void*)&dest->parameter_name.len); // 255
        if (ret != 7)
        {
            goto uavcan_protocol_enumeration_Indication_error_exit;
        }
        offset += 7;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->parameter_name.data = (uint8_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->parameter_name.len; c++)
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
                goto uavcan_protocol_enumeration_Indication_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((uint8_t*)*dyn_arr_buf) + 1);
        }
        offset += 8;
    }
    return offset;

uavcan_protocol_enumeration_Indication_error_exit:
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
  * @brief uavcan_protocol_enumeration_Indication_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_enumeration_Indication dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_enumeration_Indication_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_enumeration_Indication* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_enumeration_Indication); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_enumeration_Indication_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_ENUMERATION_INDICATION