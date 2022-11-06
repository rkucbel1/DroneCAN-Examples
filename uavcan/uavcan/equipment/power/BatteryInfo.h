/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/equipment/power/1092.BatteryInfo.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_POWER_BATTERYINFO
#define __UAVCAN_EQUIPMENT_POWER_BATTERYINFO

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

/******************************* Source text **********************************
#
# Single battery info.
#
# Typical publishing rate should be around 0.2~1 Hz.
#
# Please refer to the Smart Battery data specification for some elaboration.
#

#
# Primary parameters.
# Some fields can be set to NAN if their values are unknown.
# Full charge capacity is expected to slowly reduce as the battery is aging. Normally its estimate is updated after
# every charging cycle.
#
float16 temperature             # [Kelvin]
float16 voltage                 # [Volt]
float16 current                 # [Ampere]
float16 average_power_10sec     # [Watt]        Average power consumption over the last 10 seconds
float16 remaining_capacity_wh   # [Watt hours]  Will be increasing during charging
float16 full_charge_capacity_wh # [Watt hours]  Predicted battery capacity when it is fully charged. Falls with aging
float16 hours_to_full_charge    # [Hours]       Charging is expected to complete in this time; zero if not charging

#
# Status flags.
# Notes:
#  - CHARGING must be always set as long as the battery is connected to a charger, even if the charging is complete.
#  - CHARGED must be cleared immediately when the charger is disconnected.
#
uint11 STATUS_FLAG_IN_USE       = 1     # The battery is currently used as a power supply
uint11 STATUS_FLAG_CHARGING     = 2     # Charger is active
uint11 STATUS_FLAG_CHARGED      = 4     # Charging complete, but the charger is still active
uint11 STATUS_FLAG_TEMP_HOT     = 8     # Battery temperature is above normal
uint11 STATUS_FLAG_TEMP_COLD    = 16    # Battery temperature is below normal
uint11 STATUS_FLAG_OVERLOAD     = 32    # Safe operating area violation
uint11 STATUS_FLAG_BAD_BATTERY  = 64    # This battery should not be used anymore (e.g. low SOH)
uint11 STATUS_FLAG_NEED_SERVICE = 128   # This battery requires maintenance (e.g. balancing, full recharge)
uint11 STATUS_FLAG_BMS_ERROR    = 256   # Battery management system/controller error, smart battery interface error
uint11 STATUS_FLAG_RESERVED_A   = 512   # Keep zero
uint11 STATUS_FLAG_RESERVED_B   = 1024  # Keep zero
uint11 status_flags

#
# State of Health (SOH) estimate, in percent.
# http://en.wikipedia.org/wiki/State_of_health
#
uint7 STATE_OF_HEALTH_UNKNOWN = 127     # Use this constant if SOH cannot be estimated
uint7 state_of_health_pct               # Health of the battery, in percent, optional

#
# Relative State of Charge (SOC) estimate, in percent.
# http://en.wikipedia.org/wiki/State_of_charge
#
uint7 state_of_charge_pct               # Percent of the full charge [0, 100]. This field is required
uint7 state_of_charge_pct_stdev         # SOC error standard deviation; use best guess if unknown

#
# Battery identification.
# Model instance ID must be unique within the same battery model name.
# Model name is a human-readable string that normally should include the vendor name, model name, and chemistry
# type of this battery. This field should be assumed case-insensitive. Example: "Zubax Smart Battery v1.1 LiPo".
#
uint8 battery_id                        # Identifies the battery within this vehicle, e.g. 0 - primary battery
uint32 model_instance_id                # Set to zero if not applicable
uint8[<32] model_name                   # Battery model name
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.power.BatteryInfo
saturated float16 temperature
saturated float16 voltage
saturated float16 current
saturated float16 average_power_10sec
saturated float16 remaining_capacity_wh
saturated float16 full_charge_capacity_wh
saturated float16 hours_to_full_charge
saturated uint11 status_flags
saturated uint7 state_of_health_pct
saturated uint7 state_of_charge_pct
saturated uint7 state_of_charge_pct_stdev
saturated uint8 battery_id
saturated uint32 model_instance_id
saturated uint8[<=31] model_name
******************************************************************************/

#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_ID              1092
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_NAME            "uavcan.equipment.power.BatteryInfo"
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_SIGNATURE       (0x249C26548A711966ULL)

#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_MAX_SIZE        ((437 + 7)/8)

// Constants
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_IN_USE                 1 // 1
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_CHARGING               2 // 2
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_CHARGED                4 // 4
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_TEMP_HOT               8 // 8
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_TEMP_COLD             16 // 16
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_OVERLOAD              32 // 32
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_BAD_BATTERY           64 // 64
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_NEED_SERVICE         128 // 128
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_BMS_ERROR            256 // 256
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_RESERVED_A           512 // 512
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATUS_FLAG_RESERVED_B          1024 // 1024
#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_STATE_OF_HEALTH_UNKNOWN          127 // 127

#define UAVCAN_EQUIPMENT_POWER_BATTERYINFO_MODEL_NAME_MAX_LENGTH                         31

typedef struct
{
    // FieldTypes
    float      temperature;                   // float16 Saturate
    float      voltage;                       // float16 Saturate
    float      current;                       // float16 Saturate
    float      average_power_10sec;           // float16 Saturate
    float      remaining_capacity_wh;         // float16 Saturate
    float      full_charge_capacity_wh;       // float16 Saturate
    float      hours_to_full_charge;          // float16 Saturate
    uint16_t   status_flags;                  // bit len 11
    uint8_t    state_of_health_pct;           // bit len 7
    uint8_t    state_of_charge_pct;           // bit len 7
    uint8_t    state_of_charge_pct_stdev;     // bit len 7
    uint8_t    battery_id;                    // bit len 8
    uint32_t   model_instance_id;             // bit len 32
    struct
    {
        uint8_t    len;                       // Dynamic array length
        uint8_t*   data;                      // Dynamic Array 8bit[31] max items
    } model_name;

} uavcan_equipment_power_BatteryInfo;

static inline
uint32_t uavcan_equipment_power_BatteryInfo_encode(uavcan_equipment_power_BatteryInfo* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_equipment_power_BatteryInfo_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_power_BatteryInfo* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_equipment_power_BatteryInfo_encode_internal(uavcan_equipment_power_BatteryInfo* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_equipment_power_BatteryInfo_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_power_BatteryInfo* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/equipment/power/1092.BatteryInfo.uavcan
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
  * @brief uavcan_equipment_power_BatteryInfo_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_power_BatteryInfo_encode_internal(uavcan_equipment_power_BatteryInfo* source,
  void* msg_buf,
  uint32_t offset,
  uint8_t CANARD_MAYBE_UNUSED(root_item),
  bool tao_enabled)
{
    uint32_t c = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->temperature);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->temperature;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->voltage);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->voltage;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->current);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->current;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->average_power_10sec);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->average_power_10sec;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->remaining_capacity_wh);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->remaining_capacity_wh;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->full_charge_capacity_wh);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->full_charge_capacity_wh;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->hours_to_full_charge);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->hours_to_full_charge;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;
    source->status_flags = CANARD_INTERNAL_SATURATE_UNSIGNED(source->status_flags, 2047)
    canardEncodeScalar(msg_buf, offset, 11, (void*)&source->status_flags); // 2047
    offset += 11;

    source->state_of_health_pct = CANARD_INTERNAL_SATURATE_UNSIGNED(source->state_of_health_pct, 127)
    canardEncodeScalar(msg_buf, offset, 7, (void*)&source->state_of_health_pct); // 127
    offset += 7;

    source->state_of_charge_pct = CANARD_INTERNAL_SATURATE_UNSIGNED(source->state_of_charge_pct, 127)
    canardEncodeScalar(msg_buf, offset, 7, (void*)&source->state_of_charge_pct); // 127
    offset += 7;

    source->state_of_charge_pct_stdev = CANARD_INTERNAL_SATURATE_UNSIGNED(source->state_of_charge_pct_stdev, 127)
    canardEncodeScalar(msg_buf, offset, 7, (void*)&source->state_of_charge_pct_stdev); // 127
    offset += 7;

    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->battery_id); // 255
    offset += 8;

    canardEncodeScalar(msg_buf, offset, 32, (void*)&source->model_instance_id); // 4294967295
    offset += 32;

    // Dynamic Array (model_name)
    if (! root_item || ! tao_enabled)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 5, (void*)&source->model_name.len);
        offset += 5;
    }

    // - Add array items
    for (c = 0; c < source->model_name.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           8,
                           (void*)(source->model_name.data + c));// 255
        offset += 8;
    }

    return offset;
}

/**
  * @brief uavcan_equipment_power_BatteryInfo_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_power_BatteryInfo_encode(uavcan_equipment_power_BatteryInfo* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_power_BatteryInfo_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_power_BatteryInfo_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_power_BatteryInfo dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_power_BatteryInfo_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_power_BatteryInfo* dest,
  uint8_t** CANARD_MAYBE_UNUSED(dyn_arr_buf),
  int32_t offset,
  bool tao_enabled)
{
    int32_t ret = 0;
    uint32_t c = 0;
#ifndef CANARD_USE_FLOAT16_CAST
    uint16_t tmp_float = 0;
#else
    CANARD_USE_FLOAT16_CAST tmp_float = 0;
#endif

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->temperature = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->temperature = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->voltage = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->voltage = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->current = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->current = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->average_power_10sec = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->average_power_10sec = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->remaining_capacity_wh = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->remaining_capacity_wh = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->full_charge_capacity_wh = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->full_charge_capacity_wh = (float)tmp_float;
#endif
    offset += 16;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->hours_to_full_charge = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->hours_to_full_charge = (float)tmp_float;
#endif
    offset += 16;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 11, false, (void*)&dest->status_flags);
    if (ret != 11)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
    offset += 11;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 7, false, (void*)&dest->state_of_health_pct);
    if (ret != 7)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
    offset += 7;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 7, false, (void*)&dest->state_of_charge_pct);
    if (ret != 7)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
    offset += 7;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 7, false, (void*)&dest->state_of_charge_pct_stdev);
    if (ret != 7)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
    offset += 7;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 8, false, (void*)&dest->battery_id);
    if (ret != 8)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
    offset += 8;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 32, false, (void*)&dest->model_instance_id);
    if (ret != 32)
    {
        goto uavcan_equipment_power_BatteryInfo_error_exit;
    }
    offset += 32;

    // Dynamic Array (model_name)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao_enabled)
    {
        //  - Calculate Array length from MSG length
        dest->model_name.len = ((payload_len * 8) - offset ) / 8; // 8 bit array item size
    }
    else
    {
        // - Array length 5 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 5,
                                 false,
                                 (void*)&dest->model_name.len); // 255
        if (ret != 5)
        {
            goto uavcan_equipment_power_BatteryInfo_error_exit;
        }
        offset += 5;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->model_name.data = (uint8_t*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->model_name.len; c++)
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
                goto uavcan_equipment_power_BatteryInfo_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((uint8_t*)*dyn_arr_buf) + 1);
        }
        offset += 8;
    }
    return offset;

uavcan_equipment_power_BatteryInfo_error_exit:
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
  * @brief uavcan_equipment_power_BatteryInfo_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_power_BatteryInfo dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_power_BatteryInfo_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_power_BatteryInfo* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_power_BatteryInfo); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_power_BatteryInfo_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_POWER_BATTERYINFO