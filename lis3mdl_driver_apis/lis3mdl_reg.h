
/**
 ********************************************************************************
 * @file    lismdl_reg.h
 * @author  Mahmoud Abdelhalim
 * @date    05.03.2024
 * @brief   header file for lis3mdl.h regsiters mapping.
 ********************************************************************************
 */
#ifndef LIS3MDL_REG_H
#define LIS3MDL_REG_H

# include <stdint.h>


/************** Sensor I2C Write Address *****************/

#define LIS3MDL_I2C_WRITE_ADDR_LOW    ((uint8_t)0x38)  // SAD[0] = 0
#define LIS3MDL_I2C_WRITE_ADDR_HIGH   ((uint8_t)0x3C)  // SAD[0] = 1

/************** Sensor I2C Read Address *******************/

#define LIS3MDL_I2C_READ_ADDR_LOW      ((uint8_t)0x39)
#define LIS3MDL_I2C_READ_ADDR_HIGH     ((uint8_t)0x3D)


/************** Device Register Addressing*******************/

#define LIS3MDL_WHO_AM_I_REG    0x0FU

// Control Registers
#define LIS3MDL_CTRL_REG1       0x20U
#define LIS3MDL_CTRL_REG2       0x21U
#define LIS3MDL_CTRL_REG3       0x22U
#define LIS3MDL_CTRL_REG4       0x23U
#define LIS3MDL_CTRL_REG5       0x24U

// Status Register
#define LIS3MDL_STATUS_REG      0x27U

// Magentic Filed Measurment Registers two’s complement.
#define LIS3MDL_OUTX_L          0x28U
#define LIS3MDL_OUTX_H          0x29U
#define LIS3MDL_OUTY_L          0x2AU
#define LIS3MDL_OUTY_H          0x2BU
#define LIS3MDL_OUTZ_L          0x2CU
#define LIS3MDL_OUTZ_H          0x2DU

// Temprature Sensor Data Registers in two’s complement.
#define LIS3MDL_TEMP_OUT_L      0x2EU
#define LIS3MDL_TEMP_OUT_H      0x2FU

// Configurations Registers
#define LIS3MDL_INT_CFG         0x30U
#define LIS3MDL_INT_SRC         0x31U

// Interrupt threshold Registers
#define LIS3MDL_INT_THS_L       0x32U
#define LIS3MDL_INT_THS_H       0x33U


/* Control Regsiter 1 Bits Mapping */
typedef struct
{
  uint8_t self_test_en              : 1;
  uint8_t operation_mode            : 6; /* X and Y Operation Modes + ODR 'Output Data Rate Confiugrations' + Fast ODR -> om */
  uint8_t temprature_sensor_en      : 1;
} lis3mdl_ctrl_reg1_t;

/* Control Regsiter 2 Bits Mapping */
typedef struct
{
  uint8_t not_used_1     : 2;
  uint8_t soft_reset     : 1;
  uint8_t reboot         : 1;
  uint8_t not_used_2     : 1;
  uint8_t full_scale     : 2;
  uint8_t not_used_3     : 1;
} lis3mdl_ctrl_reg2_t;

/* Configurations Regsiter Bits Mapping */
typedef struct
{
  uint8_t ir_pin_en       : 1; /* Enables the interrupt on the INT pin, (0: disabled; 1: enabled) */
  uint8_t latch_ir_req    : 1;
  uint8_t ir_en_a         : 1; /* Interrupt active configuration on INT */
  uint8_t not_used_1      : 2;
  uint8_t z_ir_en         : 1;
  uint8_t y_ir_en         : 1;
  uint8_t x_ir_en         : 1;
} lis3mdl_int_cfg_t;

typedef struct
{
  uint8_t not_used_1      : 1;
  uint8_t ble             : 1; /* Big/little endian data selection */
  uint8_t op_md_z         : 2; /* Z-axis operative mode */
  uint8_t not_used_2      : 4;
} lis3mdl_ctrl_reg4_t;

typedef enum{

  /*x-y op mode : low power mode only*/
  LIS3MDL_LP_Hz625      = 0x00,          
  LIS3MDL_LP_1kHz       = 0x01,
  LIS3MDL_LP_1Hz25      = 0x02,
  LIS3MDL_LP_2Hz5       = 0x04,
  LIS3MDL_LP_5Hz        = 0x06,
  LIS3MDL_LP_10Hz       = 0x08,
  LIS3MDL_LP_20Hz       = 0x0A,
  LIS3MDL_LP_40Hz       = 0x0C,
  LIS3MDL_LP_80Hz       = 0x0E,

  /*x-y op mode : low power mode + fast ODR*/
  LIS3MDL_LP_1kHz       = 0x01,

  /*x-y op mode : medium performance mode only*/
  LIS3MDL_MP_1Hz25      = 0x12,
  LIS3MDL_MP_2Hz5       = 0x14,
  LIS3MDL_MP_5Hz        = 0x16,
  LIS3MDL_MP_10Hz       = 0x18,
  LIS3MDL_MP_20Hz       = 0x1A,
  LIS3MDL_MP_40Hz       = 0x1C,
  LIS3MDL_MP_80Hz       = 0x1E,

  /*x-y op mode : medium performance mode + fast ODR*/
  LIS3MDL_MP_560Hz      = 0x11,

  /*x-y op mode : high performance mode only*/
  LIS3MDL_HP_1Hz25      = 0x22,
  LIS3MDL_HP_2Hz5       = 0x24,
  LIS3MDL_HP_5Hz        = 0x26,
  LIS3MDL_HP_10Hz       = 0x28,
  LIS3MDL_HP_20Hz       = 0x2A,
  LIS3MDL_HP_40Hz       = 0x2C,
  LIS3MDL_HP_80Hz       = 0x2E,

  /*x-y op mode : high performance mode only + fast ODR*/
  LIS3MDL_HP_300Hz      = 0x21,

  /*x-y op mode : ultra high performance mode only*/
  LIS3MDL_UHP_1Hz25     = 0x32,
  LIS3MDL_UHP_2Hz5      = 0x34,
  LIS3MDL_UHP_5Hz       = 0x36,
  LIS3MDL_UHP_10Hz      = 0x38,
  LIS3MDL_UHP_20Hz      = 0x3A,
  LIS3MDL_UHP_40Hz      = 0x3C,
  LIS3MDL_UHP_80Hz      = 0x3E,

  /*x-y op mode : ultra high performance mode only + fast ODR*/
  LIS3MDL_UHP_155Hz     = 0x31,

} lis3mdl_do_rate_t;

typedef enum{
  LIS3MDL_4_GAUSS   = 0,
  LIS3MDL_8_GAUSS   = 1,
  LIS3MDL_12_GAUSS  = 2,
  LIS3MDL_16_GAUSS  = 3,
} lis3mdl_fs_config_t;

/* Sensitivity Values ----------------------------------------*/
#define LIS3MDL_SENSITIVITY_FOR_FS_4G 0.14  /**< Sensitivity  for 4 gauss full scale [LSB/gauss] */
#define LIS3MDL_SENSITIVITY_FOR_FS_8G 0.29  /**< Sensitivity  for 8 gauss full scale [LSB/gauss] */
#define LIS3MDL_SENSITIVITY_FOR_FS_12G 0.43 /**< Sensitivity  for 12 gauss full scale [LSB/gauss] */
#define LIS3MDL_SENSITIVITY_FOR_FS_16G 0.58  /**< Sensitivity  for 16 gauss full scale [LSB/gauss] */

#endif // LIS3MDL_REG_H
