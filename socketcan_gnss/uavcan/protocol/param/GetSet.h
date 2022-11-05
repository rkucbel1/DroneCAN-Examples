/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/param/11.GetSet.uavcan
 */

#ifndef __UAVCAN_PROTOCOL_PARAM_GETSET
#define __UAVCAN_PROTOCOL_PARAM_GETSET

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/protocol/param/NumericValue.h>
#include <uavcan/protocol/param/Value.h>

/******************************* Source text **********************************
#
# Get or set a parameter by name or by index.
# Note that access by index should only be used to retrieve the list of parameters; it is highly
# discouraged to use it for anything else, because persistent ordering is not guaranteed.
#

#
# Index of the parameter starting from 0; ignored if name is nonempty.
# Use index only to retrieve the list of parameters.
# Parameter ordering must be well defined (e.g. alphabetical, or any other stable ordering),
# in order for the index access to work.
#
uint13 index

#
# If set - parameter will be assigned this value, then the new value will be returned.
# If not set - current parameter value will be returned.
# Refer to the definition of Value for details.
#
Value value

#
# Name of the parameter; always preferred over index if nonempty.
#
uint8[<=92] name

---

void5

#
# Actual parameter value.
#
# For set requests, it should contain the actual parameter value after the set request was
# executed. The objective is to let the client know if the value could not be updated, e.g.
# due to its range violation, etc.
#
# Empty value (and/or empty name) indicates that there is no such parameter.
#
Value value

void5
Value default_value    # Optional

void6
NumericValue max_value # Optional, not applicable for bool/string

void6
NumericValue min_value # Optional, not applicable for bool/string

#
# Empty name (and/or empty value) in response indicates that there is no such parameter.
#
uint8[<=92] name
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.param.GetSet
saturated uint13 index
uavcan.protocol.param.Value value
saturated uint8[<=92] name
---
void5
uavcan.protocol.param.Value value
void5
uavcan.protocol.param.Value default_value
void6
uavcan.protocol.param.NumericValue max_value
void6
uavcan.protocol.param.NumericValue min_value
saturated uint8[<=92] name
******************************************************************************/

#define UAVCAN_PROTOCOL_PARAM_GETSET_ID                    11
#define UAVCAN_PROTOCOL_PARAM_GETSET_NAME                  "uavcan.protocol.param.GetSet"
#define UAVCAN_PROTOCOL_PARAM_GETSET_SIGNATURE             (0xA7B622F939D1A4D5ULL)

#define UAVCAN_PROTOCOL_PARAM_GETSET_REQUEST_MAX_SIZE      ((1791 + 7)/8)

// Constants

#define UAVCAN_PROTOCOL_PARAM_GETSET_REQUEST_NAME_MAX_LENGTH                             92

typedef struct
{
    // FieldTypes
    uint16_t   index;                         // bit len 13
    uavcan_protocol_param_Value value;                         //
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[92] max items
    } name;

} uavcan_protocol_param_GetSetRequest;

static inline
uint32_t uavcan_protocol_param_GetSetRequest_encode(uavcan_protocol_param_GetSetRequest* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_protocol_param_GetSetRequest_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_param_GetSetRequest* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_protocol_param_GetSetRequest_encode_internal(uavcan_protocol_param_GetSetRequest* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_protocol_param_GetSetRequest_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_param_GetSetRequest* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

#define UAVCAN_PROTOCOL_PARAM_GETSET_RESPONSE_MAX_SIZE     ((2967 + 7)/8)

// Constants

#define UAVCAN_PROTOCOL_PARAM_GETSET_RESPONSE_NAME_MAX_LENGTH                            92

typedef struct
{
    // FieldTypes
    // void5
    uavcan_protocol_param_Value value;                         //
    // void5
    uavcan_protocol_param_Value default_value;                 //
    // void6
    uavcan_protocol_param_NumericValue max_value;                     //
    // void6
    uavcan_protocol_param_NumericValue min_value;                     //
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[92] max items
    } name;

} uavcan_protocol_param_GetSetResponse;

static inline
uint32_t uavcan_protocol_param_GetSetResponse_encode(uavcan_protocol_param_GetSetResponse* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_protocol_param_GetSetResponse_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_param_GetSetResponse* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_protocol_param_GetSetResponse_encode_internal(uavcan_protocol_param_GetSetResponse* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_protocol_param_GetSetResponse_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_protocol_param_GetSetResponse* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/protocol/param/11.GetSet.uavcan
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
  * @brief uavcan_protocol_param_GetSetRequest_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_param_GetSetRequest_encode_internal(uavcan_protocol_param_GetSetRequest* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    uint32_t c = 0;

    source->index = CANARD_INTERNAL_SATURATE_UNSIGNED(source->index, 8191)
    canardEncodeScalar(msg_buf, offset, 13, (void*)&source->index); // 8191
    offset += 13;

    // Compound
    offset = uavcan_protocol_param_Value_encode_internal(&source->value, msg_buf, offset, 0, tao_enabled);

    // Dynamic Array (name)
    if (! root_item || ! tao_enabled)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 7, (void*)&source->name.len);
        offset += 7;
    }

    // - Add array items
    for (c = 0; c < source->name.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           8,
                           (void*)(source->name.data + c));// 255
        offset += 8;
    }

    return offset;
}

/**
  * @brief uavcan_protocol_param_GetSetRequest_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_param_GetSetRequest_encode(uavcan_protocol_param_GetSetRequest* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_param_GetSetRequest_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_param_GetSetRequest_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_param_GetSetRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_param_GetSetRequest_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_param_GetSetRequest* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;
    uint32_t c = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 13, false, (void*)&dest->index);
    if (ret != 13)
    {
        goto uavcan_protocol_param_GetSetRequest_error_exit;
    }
    offset += 13;

    // Compound
    offset = uavcan_protocol_param_Value_decode_internal(transfer, payload_len, &dest->value, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_param_GetSetRequest_error_exit;
    }

    // Dynamic Array (name)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao_enabled)
    {
        //  - Calculate Array length from MSG length
        dest->name.len = ((payload_len * 8) - offset ) / 8; // 8 bit array item size
    }
    else
    {
        // - Array length 7 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 7,
                                 false,
                                 (void*)&dest->name.len); // 255
        if (ret != 7)
        {
            goto uavcan_protocol_param_GetSetRequest_error_exit;
        }
        offset += 7;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->name.data = (uint8_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->name.len; c++)
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
                goto uavcan_protocol_param_GetSetRequest_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((uint8_t*)*dyn_arr_buf) + 1);
        }
        offset += 8;
    }
    return offset;

uavcan_protocol_param_GetSetRequest_error_exit:
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
  * @brief uavcan_protocol_param_GetSetRequest_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_param_GetSetRequest dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_param_GetSetRequest_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_param_GetSetRequest* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_param_GetSetRequest); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_param_GetSetRequest_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

/**
  * @brief uavcan_protocol_param_GetSetResponse_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_protocol_param_GetSetResponse_encode_internal(uavcan_protocol_param_GetSetResponse* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    uint32_t c = 0;

    // Void5
    offset += 5;

    // Compound
    offset = uavcan_protocol_param_Value_encode_internal(&source->value, msg_buf, offset, 0, tao_enabled);

    // Void5
    offset += 5;

    // Compound
    offset = uavcan_protocol_param_Value_encode_internal(&source->default_value, msg_buf, offset, 0, tao_enabled);

    // Void6
    offset += 6;

    // Compound
    offset = uavcan_protocol_param_NumericValue_encode_internal(&source->max_value, msg_buf, offset, 0, tao_enabled);

    // Void6
    offset += 6;

    // Compound
    offset = uavcan_protocol_param_NumericValue_encode_internal(&source->min_value, msg_buf, offset, 0, tao_enabled);

    // Dynamic Array (name)
    if (! root_item || ! tao_enabled)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 7, (void*)&source->name.len);
        offset += 7;
    }

    // - Add array items
    for (c = 0; c < source->name.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           8,
                           (void*)(source->name.data + c));// 255
        offset += 8;
    }

    return offset;
}

/**
  * @brief uavcan_protocol_param_GetSetResponse_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_protocol_param_GetSetResponse_encode(uavcan_protocol_param_GetSetResponse* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_protocol_param_GetSetResponse_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_protocol_param_GetSetResponse_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_param_GetSetResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_param_GetSetResponse_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_protocol_param_GetSetResponse* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;
    uint32_t c = 0;

    // Void5
    offset += 5;

    // Compound
    offset = uavcan_protocol_param_Value_decode_internal(transfer, payload_len, &dest->value, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_param_GetSetResponse_error_exit;
    }

    // Void5
    offset += 5;

    // Compound
    offset = uavcan_protocol_param_Value_decode_internal(transfer, payload_len, &dest->default_value, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_param_GetSetResponse_error_exit;
    }

    // Void6
    offset += 6;

    // Compound
    offset = uavcan_protocol_param_NumericValue_decode_internal(transfer, payload_len, &dest->max_value, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_param_GetSetResponse_error_exit;
    }

    // Void6
    offset += 6;

    // Compound
    offset = uavcan_protocol_param_NumericValue_decode_internal(transfer, payload_len, &dest->min_value, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_protocol_param_GetSetResponse_error_exit;
    }

    // Dynamic Array (name)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao_enabled)
    {
        //  - Calculate Array length from MSG length
        dest->name.len = ((payload_len * 8) - offset ) / 8; // 8 bit array item size
    }
    else
    {
        // - Array length 7 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 7,
                                 false,
                                 (void*)&dest->name.len); // 255
        if (ret != 7)
        {
            goto uavcan_protocol_param_GetSetResponse_error_exit;
        }
        offset += 7;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->name.data = (uint8_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->name.len; c++)
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
                goto uavcan_protocol_param_GetSetResponse_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((uint8_t*)*dyn_arr_buf) + 1);
        }
        offset += 8;
    }
    return offset;

uavcan_protocol_param_GetSetResponse_error_exit:
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
  * @brief uavcan_protocol_param_GetSetResponse_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_protocol_param_GetSetResponse dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_protocol_param_GetSetResponse_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_protocol_param_GetSetResponse* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_protocol_param_GetSetResponse); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_protocol_param_GetSetResponse_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_PROTOCOL_PARAM_GETSET