/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/equipment/esc/1031.RPMCommand.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_ESC_RPMCOMMAND
#define __UAVCAN_EQUIPMENT_ESC_RPMCOMMAND

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Simple RPM setpoint.
# The ESC should automatically clamp the setpoint according to the minimum and maximum supported RPM;
# for example, given a ESC that operates in the range 100 to 10000 RPM, a setpoint of 1 RPM will be clamped to 100 RPM.
# Negative values indicate reverse rotation.
#

int18[<=20] rpm
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.esc.RPMCommand
saturated int18[<=20] rpm
******************************************************************************/

#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_ID                 1031
#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_NAME               "uavcan.equipment.esc.RPMCommand"
#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_SIGNATURE          (0xCE0F9F621CF7E70BULL)

#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_MAX_SIZE           ((365 + 7)/8)

// Constants

#define UAVCAN_EQUIPMENT_ESC_RPMCOMMAND_RPM_MAX_LENGTH                                   20

typedef struct
{
    // FieldTypes
    struct
    {
        uint8_t    len;                       // Dynamic array length
        int32_t*   data;                      // Dynamic Array 18bit[20] max items
    } rpm;

} uavcan_equipment_esc_RPMCommand;

static inline
uint32_t uavcan_equipment_esc_RPMCommand_encode(uavcan_equipment_esc_RPMCommand* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_equipment_esc_RPMCommand_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_esc_RPMCommand* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_equipment_esc_RPMCommand_encode_internal(uavcan_equipment_esc_RPMCommand* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_equipment_esc_RPMCommand_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_esc_RPMCommand* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/equipment/esc/1031.RPMCommand.uavcan
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
  * @brief uavcan_equipment_esc_RPMCommand_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_esc_RPMCommand_encode_internal(uavcan_equipment_esc_RPMCommand* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    uint32_t c = 0;

    // Dynamic Array (rpm)
    if (! root_item || ! tao_enabled)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 5, (void*)&source->rpm.len);
        offset += 5;
    }

    // - Add array items
    for (c = 0; c < source->rpm.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           18,
                           (void*)(source->rpm.data + c));// 131071
        offset += 18;
    }

    return offset;
}

/**
  * @brief uavcan_equipment_esc_RPMCommand_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_esc_RPMCommand_encode(uavcan_equipment_esc_RPMCommand* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_esc_RPMCommand_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_esc_RPMCommand_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_esc_RPMCommand dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_esc_RPMCommand_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_esc_RPMCommand* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;
    uint32_t c = 0;

    // Dynamic Array (rpm)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao_enabled)
    {
        //  - Calculate Array length from MSG length
        dest->rpm.len = ((payload_len * 8) - offset ) / 18; // 18 bit array item size
    }
    else
    {
        // - Array length 5 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 5,
                                 false,
                                 (void*)&dest->rpm.len); // 131071
        if (ret != 5)
        {
            goto uavcan_equipment_esc_RPMCommand_error_exit;
        }
        offset += 5;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->rpm.data = (int32_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->rpm.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer,
                                     (uint32_t)offset,
                                     18,
                                     true,
                                     (void*)*dyn_arr_buf); // 131071
            if (ret != 18)
            {
                goto uavcan_equipment_esc_RPMCommand_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((int32_t*)*dyn_arr_buf) + 1);
        }
        offset += 18;
    }
    return offset;

uavcan_equipment_esc_RPMCommand_error_exit:
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
  * @brief uavcan_equipment_esc_RPMCommand_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_esc_RPMCommand dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_esc_RPMCommand_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_esc_RPMCommand* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_esc_RPMCommand); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_esc_RPMCommand_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_ESC_RPMCOMMAND