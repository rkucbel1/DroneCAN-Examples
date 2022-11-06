/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/equipment/gnss/1060.Fix.uavcan
 */

#ifndef __UAVCAN_EQUIPMENT_GNSS_FIX
#define __UAVCAN_EQUIPMENT_GNSS_FIX

#include <stdint.h>
#include "canard.h"

#ifdef __cplusplus
extern "C"
{
#endif

#include <uavcan/Timestamp.h>

/******************************* Source text **********************************
#
# GNSS navigation solution with uncertainty.
# This message is deprecated. Use the newer 1063.Fix2.uavcan message.
#

uavcan.Timestamp timestamp         # Global network-synchronized time, if available, otherwise zero

#
# Time solution.
# Time standard (GPS, UTC, TAI, etc) is defined in the field below.
#
uavcan.Timestamp gnss_timestamp

#
# Time standard used in the GNSS timestamp field.
#
uint3 GNSS_TIME_STANDARD_NONE = 0  # Time is unknown
uint3 GNSS_TIME_STANDARD_TAI  = 1
uint3 GNSS_TIME_STANDARD_UTC  = 2
uint3 GNSS_TIME_STANDARD_GPS  = 3
uint3 gnss_time_standard

void5   # Reserved space

#
# If known, the number of leap seconds allows to perform conversions between some time standards.
#
uint8 NUM_LEAP_SECONDS_UNKNOWN = 0
uint8 num_leap_seconds

#
# Position and velocity solution
#
int37 longitude_deg_1e8            # Longitude degrees multiplied by 1e8 (approx. 1 mm per LSB)
int37 latitude_deg_1e8             # Latitude degrees multiplied by 1e8 (approx. 1 mm per LSB on equator)
int27 height_ellipsoid_mm          # Height above ellipsoid in millimeters
int27 height_msl_mm                # Height above mean sea level in millimeters

float16[3] ned_velocity            # NED frame (north-east-down) in meters per second

#
# Fix status
#
uint6 sats_used

uint2 STATUS_NO_FIX    = 0
uint2 STATUS_TIME_ONLY = 1
uint2 STATUS_2D_FIX    = 2
uint2 STATUS_3D_FIX    = 3
uint2 status

#
# Precision
#
float16 pdop

void4
float16[<=9] position_covariance   # m^2
float16[<=9] velocity_covariance   # (m/s)^2
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.equipment.gnss.Fix
uavcan.Timestamp timestamp
uavcan.Timestamp gnss_timestamp
saturated uint3 gnss_time_standard
void5
saturated uint8 num_leap_seconds
saturated int37 longitude_deg_1e8
saturated int37 latitude_deg_1e8
saturated int27 height_ellipsoid_mm
saturated int27 height_msl_mm
saturated float16[3] ned_velocity
saturated uint6 sats_used
saturated uint2 status
saturated float16 pdop
void4
saturated float16[<=9] position_covariance
saturated float16[<=9] velocity_covariance
******************************************************************************/

#define UAVCAN_EQUIPMENT_GNSS_FIX_ID                       1060
#define UAVCAN_EQUIPMENT_GNSS_FIX_NAME                     "uavcan.equipment.gnss.Fix"
#define UAVCAN_EQUIPMENT_GNSS_FIX_SIGNATURE                (0x54C1572B9E07F297ULL)

#define UAVCAN_EQUIPMENT_GNSS_FIX_MAX_SIZE                 ((628 + 7)/8)

// Constants
#define UAVCAN_EQUIPMENT_GNSS_FIX_GNSS_TIME_STANDARD_NONE                     0 // 0
#define UAVCAN_EQUIPMENT_GNSS_FIX_GNSS_TIME_STANDARD_TAI                      1 // 1
#define UAVCAN_EQUIPMENT_GNSS_FIX_GNSS_TIME_STANDARD_UTC                      2 // 2
#define UAVCAN_EQUIPMENT_GNSS_FIX_GNSS_TIME_STANDARD_GPS                      3 // 3
#define UAVCAN_EQUIPMENT_GNSS_FIX_NUM_LEAP_SECONDS_UNKNOWN                    0 // 0
#define UAVCAN_EQUIPMENT_GNSS_FIX_STATUS_NO_FIX                               0 // 0
#define UAVCAN_EQUIPMENT_GNSS_FIX_STATUS_TIME_ONLY                            1 // 1
#define UAVCAN_EQUIPMENT_GNSS_FIX_STATUS_2D_FIX                               2 // 2
#define UAVCAN_EQUIPMENT_GNSS_FIX_STATUS_3D_FIX                               3 // 3

#define UAVCAN_EQUIPMENT_GNSS_FIX_NED_VELOCITY_LENGTH                                    3
#define UAVCAN_EQUIPMENT_GNSS_FIX_POSITION_COVARIANCE_MAX_LENGTH                         9
#define UAVCAN_EQUIPMENT_GNSS_FIX_VELOCITY_COVARIANCE_MAX_LENGTH                         9

typedef struct
{
    // FieldTypes
    uavcan_Timestamp timestamp;                     //
    uavcan_Timestamp gnss_timestamp;                //
    uint8_t    gnss_time_standard;            // bit len 3
    // void5
    uint8_t    num_leap_seconds;              // bit len 8
    int64_t    longitude_deg_1e8;             // bit len 37
    int64_t    latitude_deg_1e8;              // bit len 37
    int32_t    height_ellipsoid_mm;           // bit len 27
    int32_t    height_msl_mm;                 // bit len 27
    float      ned_velocity[3];               // Static Array 16bit[3] max items
    uint8_t    sats_used;                     // bit len 6
    uint8_t    status;                        // bit len 2
    float      pdop;                          // float16 Saturate
    // void4
    struct
    {
        uint8_t    len;                       // Dynamic array length
        float*     data;                      // Dynamic Array 16bit[9] max items
    } position_covariance;
    struct
    {
        uint8_t    len;                       // Dynamic array length
        float*     data;                      // Dynamic Array 16bit[9] max items
    } velocity_covariance;

} uavcan_equipment_gnss_Fix;

static inline
uint32_t uavcan_equipment_gnss_Fix_encode(uavcan_equipment_gnss_Fix* source, void* msg_buf, bool tao_enabled);

static inline
int32_t uavcan_equipment_gnss_Fix_decode(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_gnss_Fix* dest, uint8_t** dyn_arr_buf, bool tao_enabled);

static inline
uint32_t uavcan_equipment_gnss_Fix_encode_internal(uavcan_equipment_gnss_Fix* source, void* msg_buf, uint32_t offset, uint8_t root_item, bool tao_enabled);

static inline
int32_t uavcan_equipment_gnss_Fix_decode_internal(const CanardRxTransfer* transfer, uint16_t payload_len, uavcan_equipment_gnss_Fix* dest, uint8_t** dyn_arr_buf, int32_t offset, bool tao_enabled);

/*
 * UAVCAN data structure definition for libcanard.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/rkucbel1/DroneCAN/DSDL/uavcan/equipment/gnss/1060.Fix.uavcan
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
  * @brief uavcan_equipment_gnss_Fix_encode_internal
  * @param source : pointer to source data struct
  * @param msg_buf: pointer to msg storage
  * @param offset: bit offset to msg storage
  * @param root_item: for detecting if TAO should be used
  * @retval returns offset
  */
uint32_t uavcan_equipment_gnss_Fix_encode_internal(uavcan_equipment_gnss_Fix* source,
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

    // Compound
    offset = uavcan_Timestamp_encode_internal(&source->timestamp, msg_buf, offset, 0, tao_enabled);

    // Compound
    offset = uavcan_Timestamp_encode_internal(&source->gnss_timestamp, msg_buf, offset, 0, tao_enabled);
    source->gnss_time_standard = CANARD_INTERNAL_SATURATE_UNSIGNED(source->gnss_time_standard, 7)
    canardEncodeScalar(msg_buf, offset, 3, (void*)&source->gnss_time_standard); // 7
    offset += 3;

    // Void5
    offset += 5;
    canardEncodeScalar(msg_buf, offset, 8, (void*)&source->num_leap_seconds); // 255
    offset += 8;

    source->longitude_deg_1e8 = CANARD_INTERNAL_SATURATE(source->longitude_deg_1e8, 68719476735)
    canardEncodeScalar(msg_buf, offset, 37, (void*)&source->longitude_deg_1e8); // 68719476735
    offset += 37;

    source->latitude_deg_1e8 = CANARD_INTERNAL_SATURATE(source->latitude_deg_1e8, 68719476735)
    canardEncodeScalar(msg_buf, offset, 37, (void*)&source->latitude_deg_1e8); // 68719476735
    offset += 37;

    source->height_ellipsoid_mm = CANARD_INTERNAL_SATURATE(source->height_ellipsoid_mm, 67108863)
    canardEncodeScalar(msg_buf, offset, 27, (void*)&source->height_ellipsoid_mm); // 67108863
    offset += 27;

    source->height_msl_mm = CANARD_INTERNAL_SATURATE(source->height_msl_mm, 67108863)
    canardEncodeScalar(msg_buf, offset, 27, (void*)&source->height_msl_mm); // 67108863
    offset += 27;

    // Static array (ned_velocity)
    for (c = 0; c < 3; c++)
    {
        canardEncodeScalar(msg_buf, offset, 16, (void*)(source->ned_velocity + c)); // 32767
        offset += 16;
    }

    source->sats_used = CANARD_INTERNAL_SATURATE_UNSIGNED(source->sats_used, 63)
    canardEncodeScalar(msg_buf, offset, 6, (void*)&source->sats_used); // 63
    offset += 6;

    source->status = CANARD_INTERNAL_SATURATE_UNSIGNED(source->status, 3)
    canardEncodeScalar(msg_buf, offset, 2, (void*)&source->status); // 3
    offset += 2;

    // float16 special handling
#ifndef CANARD_USE_FLOAT16_CAST
    tmp_float = canardConvertNativeFloatToFloat16(source->pdop);
#else
    tmp_float = (CANARD_USE_FLOAT16_CAST)source->pdop;
#endif
    canardEncodeScalar(msg_buf, offset, 16, (void*)&tmp_float); // 32767
    offset += 16;

    // Void4
    offset += 4;

    // Dynamic Array (position_covariance)
    // - Add array length
    canardEncodeScalar(msg_buf, offset, 4, (void*)&source->position_covariance.len);
    offset += 4;

    // - Add array items
    for (c = 0; c < source->position_covariance.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           16,
                           (void*)(source->position_covariance.data + c));// 32767
        offset += 16;
    }

    // Dynamic Array (velocity_covariance)
    if (! root_item || ! tao_enabled)
    {
        // - Add array length
        canardEncodeScalar(msg_buf, offset, 4, (void*)&source->velocity_covariance.len);
        offset += 4;
    }

    // - Add array items
    for (c = 0; c < source->velocity_covariance.len; c++)
    {
        canardEncodeScalar(msg_buf,
                           offset,
                           16,
                           (void*)(source->velocity_covariance.data + c));// 32767
        offset += 16;
    }

    return offset;
}

/**
  * @brief uavcan_equipment_gnss_Fix_encode
  * @param source : Pointer to source data struct
  * @param msg_buf: Pointer to msg storage
  * @retval returns message length as bytes
  */
uint32_t uavcan_equipment_gnss_Fix_encode(uavcan_equipment_gnss_Fix* source, void* msg_buf, bool tao_enabled)
{
    uint32_t offset = 0;

    offset = uavcan_equipment_gnss_Fix_encode_internal(source, msg_buf, offset, 1, tao_enabled);

    return (offset + 7 ) / 8;
}

/**
  * @brief uavcan_equipment_gnss_Fix_decode_internal
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_gnss_Fix dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @param offset: Call with 0, bit offset to msg storage
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_gnss_Fix_decode_internal(
  const CanardRxTransfer* transfer,
  uint16_t CANARD_MAYBE_UNUSED(payload_len),
  uavcan_equipment_gnss_Fix* dest,
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

    // Compound
    offset = uavcan_Timestamp_decode_internal(transfer, payload_len, &dest->timestamp, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_equipment_gnss_Fix_error_exit;
    }

    // Compound
    offset = uavcan_Timestamp_decode_internal(transfer, payload_len, &dest->gnss_timestamp, dyn_arr_buf, offset, tao_enabled);
    if (offset < 0)
    {
        ret = offset;
        goto uavcan_equipment_gnss_Fix_error_exit;
    }

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 3, false, (void*)&dest->gnss_time_standard);
    if (ret != 3)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
    offset += 3;

    // Void5
    offset += 5;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 8, false, (void*)&dest->num_leap_seconds);
    if (ret != 8)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
    offset += 8;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 37, true, (void*)&dest->longitude_deg_1e8);
    if (ret != 37)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
    offset += 37;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 37, true, (void*)&dest->latitude_deg_1e8);
    if (ret != 37)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
    offset += 37;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 27, true, (void*)&dest->height_ellipsoid_mm);
    if (ret != 27)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
    offset += 27;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 27, true, (void*)&dest->height_msl_mm);
    if (ret != 27)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
    offset += 27;

    // Static array (ned_velocity)
    for (c = 0; c < 3; c++)
    {
        ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)(dest->ned_velocity + c));
        if (ret != 16)
        {
            goto uavcan_equipment_gnss_Fix_error_exit;
        }
        offset += 16;
    }

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 6, false, (void*)&dest->sats_used);
    if (ret != 6)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
    offset += 6;

    ret = canardDecodeScalar(transfer, (uint32_t)offset, 2, false, (void*)&dest->status);
    if (ret != 2)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
    offset += 2;

    // float16 special handling
    ret = canardDecodeScalar(transfer, (uint32_t)offset, 16, false, (void*)&tmp_float);

    if (ret != 16)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
#ifndef CANARD_USE_FLOAT16_CAST
    dest->pdop = canardConvertFloat16ToNativeFloat(tmp_float);
#else
    dest->pdop = (float)tmp_float;
#endif
    offset += 16;

    // Void4
    offset += 4;

    // Dynamic Array (position_covariance)
    //  - Array length, not last item 4 bits
    ret = canardDecodeScalar(transfer,
                             (uint32_t)offset,
                             4,
                             false,
                             (void*)&dest->position_covariance.len); // 32767
    if (ret != 4)
    {
        goto uavcan_equipment_gnss_Fix_error_exit;
    }
    offset += 4;

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->position_covariance.data = (float*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->position_covariance.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer,
                                     (uint32_t)offset,
                                     16,
                                     false,
                                     (void*)*dyn_arr_buf); // 32767
            if (ret != 16)
            {
                goto uavcan_equipment_gnss_Fix_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((float*)*dyn_arr_buf) + 1);
        }
        offset += 16;
    }

    // Dynamic Array (velocity_covariance)
    //  - Last item in struct & Root item & (Array Size > 8 bit), tail array optimization
    if (payload_len && tao_enabled)
    {
        //  - Calculate Array length from MSG length
        dest->velocity_covariance.len = ((payload_len * 8) - offset ) / 16; // 16 bit array item size
    }
    else
    {
        // - Array length 4 bits
        ret = canardDecodeScalar(transfer,
                                 (uint32_t)offset,
                                 4,
                                 false,
                                 (void*)&dest->velocity_covariance.len); // 32767
        if (ret != 4)
        {
            goto uavcan_equipment_gnss_Fix_error_exit;
        }
        offset += 4;
    }

    //  - Get Array
    if (dyn_arr_buf)
    {
        dest->velocity_covariance.data = (float*)*dyn_arr_buf;
    }

    for (c = 0; c < dest->velocity_covariance.len; c++)
    {
        if (dyn_arr_buf)
        {
            ret = canardDecodeScalar(transfer,
                                     (uint32_t)offset,
                                     16,
                                     false,
                                     (void*)*dyn_arr_buf); // 32767
            if (ret != 16)
            {
                goto uavcan_equipment_gnss_Fix_error_exit;
            }
            *dyn_arr_buf = (uint8_t*)(((float*)*dyn_arr_buf) + 1);
        }
        offset += 16;
    }
    return offset;

uavcan_equipment_gnss_Fix_error_exit:
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
  * @brief uavcan_equipment_gnss_Fix_decode
  * @param transfer: Pointer to CanardRxTransfer transfer
  * @param payload_len: Payload message length
  * @param dest: Pointer to destination struct
  * @param dyn_arr_buf: NULL or Pointer to memory storage to be used for dynamic arrays
  *                     uavcan_equipment_gnss_Fix dyn memory will point to dyn_arr_buf memory.
  *                     NULL will ignore dynamic arrays decoding.
  * @retval offset or ERROR value if < 0
  */
int32_t uavcan_equipment_gnss_Fix_decode(const CanardRxTransfer* transfer,
  uint16_t payload_len,
  uavcan_equipment_gnss_Fix* dest,
  uint8_t** dyn_arr_buf,
  bool tao_enabled)
{
    const int32_t offset = 0;
    int32_t ret = 0;

    // Clear the destination struct
    for (uint32_t c = 0; c < sizeof(uavcan_equipment_gnss_Fix); c++)
    {
        ((uint8_t*)dest)[c] = 0x00;
    }

    ret = uavcan_equipment_gnss_Fix_decode_internal(transfer, payload_len, dest, dyn_arr_buf, offset, tao_enabled);

    return ret;
}

#ifdef __cplusplus
} // extern "C"
#endif
#endif // __UAVCAN_EQUIPMENT_GNSS_FIX