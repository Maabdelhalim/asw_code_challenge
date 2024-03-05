
/**
 ********************************************************************************
 * @file    lismdl.h
 * @author  Mahmoud Abdelhalim
 * @date    05.03.2024
 * @brief   header file for lis3mdl.h driver APIs.
 ********************************************************************************
 */
#ifndef LIS3MDL_H_
#define LIS3MDL_H_

/************************************
 * INCLUDES
 ************************************/
# include <stdint.h>
# include <lis3mdl_reg.h>

typedef signed char int8_t;
typedef unsigned char   uint8_t;
typedef short  int16_t;
typedef unsigned short  uint16_t;
typedef int  int32_t;
typedef unsigned   uint32_t;

# define NUM_OF_MAG_SENSORS (2) // Assume we have 2 Magenotmer Sensors

typedef enum
{

    /** sensor read write error status**/
    MEMS_SUCCESS     = 0x11,
    MEMS_ERROR       = 0x12,
    MEMS_TIMEOUT     = 0x13,

    /** Other errors**/
    INVALID_VAL      = 0x44,
    NO_IF_REGISTERED = 0xFF,

} status_t;

typedef enum
{
    /** Interrupt Pin Enable and Disable Commands - 
     * IEN Bit at INT_CFG register - (0: disabled; 1: enabled)**/
    INTR_PIN_EN = 0x1,
    INTR_PIN_DISABLE = 0x0,
} lis3mdl_cmds_t;


typedef enum{
    LIS3MDL_CONTINUOUS = 0x00,
    LIS3MDL_SINGLE = 0x01, // sampling frequency from 0.625 Hz to 80 Hz.
    LIS3MDL_POWER_DOWN = 0x02,
}lis3mdl_op_modes_t;


typedef status_t (*mag_write_t)(void *, uint8_t, const uint8_t *, uint16_t);
typedef status_t (*mag_read_t)(void *, uint8_t, uint8_t *, uint16_t);
typedef void (*mag_delay_ms_t)(uint32_t ms);


typedef struct
{
   int16_t raw_xyz[3];

   float sensitivity;

   int16_t x_gauss;
   int16_t y_gauss;
   int16_t z_gauss;

}mag_measurments_t;

typedef struct
{
    /** Sensor Id & Measurments **/
    uint8_t id;
    mag_measurments_t measurments;
} mag_data_t;

typedef struct
{
    /** Sensor Read Write Interfaces **/
    mag_write_t write_reg_if;
    mag_read_t read_reg_if;

    /** Sensor Timer Delay Interface **/
    mag_delay_ms_t delay_ms;

    /** Sensor Read Write Addresses **/
    uint8_t sesnor_read_addr;
    uint8_t sensor_write_addr;

} mag_handle_t;

mag_data_t lis3mdl_magnetometers_data[NUM_OF_MAG_SENSORS] = {
    // Magnometer Sensor 1 Data
    {
        .id = 0xFF},
    // Magnometer Sensor 2 Data
    {
        .id = 0xFF}};

mag_handle_t lis3mdl_magnetometers_handles[NUM_OF_MAG_SENSORS] = {
    // Magnometer Sensor 1 Interfaces
    {
        .write_reg_if = NULL,
        .read_reg_if = NULL,
        .delay_ms = NULL,
        .sesnor_read_addr = 0xFF,
        .sensor_write_addr = 0xFF,
    },
    // Magnometer Sensor 2 Interfaces
    {
        .write_reg_if = NULL,
        .read_reg_if = NULL,
        .delay_ms = NULL,
        .sesnor_read_addr = 0xFF,
        .sensor_write_addr = 0xFF,
    }};

/// @brief      lis3mdl magnetometer function that reads full scale configurations
status_t lis3mdl_get_full_scale_config(const mag_handle_t *handle, lis3mdl_fs_config_t fs_setVal);

/// @brief      lis3mdl magnetometer function that writes full scale configurations
status_t lis3mdl_set_full_scale_config(const mag_handle_t *handle,lis3mdl_fs_config_t *fs_newVal);

/// @brief      lis3mdl magnetometer function that validates data output rate
status_t lis3mdl_validate_outputDataRate(lis3mdl_do_rate_t val);

/// @brief      lis3mdl magnetometer function that reads data output rate
status_t lis3mdl_get_outputDataRate(lis3mdl_do_rate_t *val);

/// @brief      lis3mdl magnetometer function that sets data output rate
status_t  lis3mdl_set_outputDataRate(lis3mdl_do_rate_t newVal);

/// @brief      lis3mdl magnetometer function that controls Interrupt pin
status_t lis3mdl_ctrl_intPinEnable(const mag_handle_t *handle,lis3mdl_cmds_t cmd);

/// @brief      lis3mdl magnetometer function calculates magnometer sensitivity measurements
status_t  lis3mdl_get_magnetometerSensitivity(const mag_handle_t *handle, mag_data_t *mag_data);

/// @brief      lis3mdl magnetometer function gets magnometer measurements
status_t  lis3mdl_get_magnetometerMeasurments(const mag_handle_t *handle, mag_data_t *mag_data);

/// @brief      Main function for lis3mdl magnetometer register read
status_t lis3mdl_read_reg( mag_read_t read_reg_if, uint8_t mag_read_addr, uint8_t reg, uint8_t *pdata, uint16_t len );

/// @brief      Main function for lis3mdl magnetometer register write
status_t lis3mdl_write_reg( mag_write_t write_reg_if, uint8_t mag_write_addr, uint8_t reg, uint8_t *pdata, uint16_t len );


#endif // LIS3MDL_H_
