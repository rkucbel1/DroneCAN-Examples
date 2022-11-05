/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/equipment/hardpoint/1070.Command.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_HARDPOINT_COMMAND
#define __UAVCAN_EQUIPMENT_HARDPOINT_COMMAND

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Generic cargo holder/hardpoint command.
#

uint8 hardpoint_id

#
# Either a binary command (0 - release, 1+ - hold) or bitmask
#
uint16 command
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.hardpoint.Command
saturated uint8 hardpoint_id
saturated uint16 command
******************************************************************************/

#define UAVCAN_EQUIPMENT_HARDPOINT_COMMAND_ID              1070
#define UAVCAN_EQUIPMENT_HARDPOINT_COMMAND_NAME            "uavcan.equipment.hardpoint.Command"
#define UAVCAN_EQUIPMENT_HARDPOINT_COMMAND_SIGNATURE       (0xA1A036268B0C3455ULL)

#define UAVCAN_EQUIPMENT_HARDPOINT_COMMAND_MAX_SIZE        ((24 + 7)/8)

// Constants

typedef struct
{
    // FieldTypes
    uint8_t    hardpoint_id;                  // bit len 8
    uint16_t   command;                       // bit len 16

} uavcan_equipment_hardpoint_Command;

static inline
uint32_t uavcan_equipment_hardpoint_Command_encode(uavcan_equipment_hardpoint_Command* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_equipment_hardpoint_Command_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_hardpoint_Command* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_equipment_hardpoint_Command_encode_internal(uavcan_equipment_hardpoint_Command* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_equipment_hardpoint_Command_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_hardpoint_Command* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/socketcan_gnss/libcanard/DSDL-master/uavcan/equipment/hardpoint/1070.Command.uavcan
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
  * @brief uavcan_equipment_hardpoint_Command_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_hardpoint_Command_encode_internal(uavcan_equipment_hardpoint_Command* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->hardpoint_id); // 255
    offset += 8;

    canardEncodeScalar(msg_buf, offset, 16, (void*)&source->command); // 65535
    offset += 16;

    return offset;
}

/**
  * @brief uavcan_equipment_hardpoint_Command_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_hardpoint_Command_encode(uavcan_equipment_hardpoint_Command* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_hardpoint_Command_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_hardpoint_Command_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_hardpoint_Command dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_hardpoint_Command_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_hardpoint_Command* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 8, false, (void*)&dest->hardpoint_id);
    if (ret != 8)
    {
        goto uavcan_equipment_hardpoint_Command_error_exit;
    }
    offset += 8;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&dest->command);
    if (ret != 16)
    {
        goto uavcan_equipment_hardpoint_Command_error_exit;
    }
    offset += 16;
    return offset;

uavcan_equipment_hardpoint_Command_error_exit:
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
  * @brief uavcan_equipment_hardpoint_Command_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_hardpoint_Command dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_hardpoint_Command_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_hardpoint_Command* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_hardpoint_Command); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_hardpoint_Command_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_HARDPOINT_COMMAND