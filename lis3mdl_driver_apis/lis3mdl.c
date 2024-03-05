
/**
 ********************************************************************************
 * @file    lismdl.c
 * @author  Mahmoud Abdelhalim
 * @date    05.03.2024
 * @brief   source file for lis3mdl driver APIs definitions and instances.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/
# include <lis3mdl.h>


/**** Set and get full scale configurations at control register 2****/


status_t lis3mdl_set_full_scale_config(const mag_handle_t *handle,lis3mdl_fs_config_t fs_setVal)
{
  lis3mdl_ctrl_reg2_t ctrl_reg2;
  status_t ret = MEMS_ERROR;

  ret = lis3mdl_read_reg(handle->read_reg_if, handle->sesnor_read_addr, LIS3MDL_CTRL_REG2, (uint8_t *)&ctrl_reg2,sizeof(ctrl_reg2));

  if (ret == MEMS_SUCCESS)
  {
    ctrl_reg2.full_scale = (uint8_t)fs_setVal;
    ret = lis3mdl_write_reg(handle->write_reg_if,handle->sensor_write_addr, LIS3MDL_CTRL_REG2, (uint8_t *)&ctrl_reg2,sizeof(ctrl_reg2));
  }

  return ret;
}

status_t lis3mdl_get_full_scale_config(const mag_handle_t *handle, lis3mdl_fs_config_t *fs_newVal)
{
  lis3mdl_ctrl_reg2_t ctrl_reg2;
  status_t ret = MEMS_ERROR;

  ret = lis3mdl_read_reg(handle->read_reg_if, handle->sesnor_read_addr, LIS3MDL_CTRL_REG2, (uint8_t *)&ctrl_reg2, sizeof(ctrl_reg2));

  if (ret == MEMS_SUCCESS)
  {
    switch (ctrl_reg2.full_scale)
    {
    case LIS3MDL_4_GAUSS:
      *fs_newVal = LIS3MDL_4_GAUSS;
      break;

    case LIS3MDL_8_GAUSS:
      *fs_newVal = LIS3MDL_8_GAUSS;
      break;

    case LIS3MDL_12_GAUSS:
      *fs_newVal = LIS3MDL_12_GAUSS;
      break;

    case LIS3MDL_16_GAUSS:
      *fs_newVal = LIS3MDL_16_GAUSS;
      break;

    default:
      *fs_newVal = LIS3MDL_4_GAUSS;
      break;
    }
  }

  return ret;
}


/**** Validate , set and get output data rates configurations at control register 1****/

status_t lis3mdl_validate_outputDataRate(lis3mdl_do_rate_t val)
{

status_t ret = MEMS_SUCCESS;

  switch (val)
  {
    case LIS3MDL_LP_Hz625:
      val = LIS3MDL_LP_Hz625;
      break;

    case LIS3MDL_LP_1kHz:
      val = LIS3MDL_LP_1kHz;
      break;

    case LIS3MDL_MP_560Hz:
      val = LIS3MDL_MP_560Hz;
      break;

    case LIS3MDL_HP_300Hz:
      val = LIS3MDL_HP_300Hz;
      break;

    case LIS3MDL_UHP_155Hz:
      val = LIS3MDL_UHP_155Hz;
      break;

    case LIS3MDL_LP_1Hz25:
      val = LIS3MDL_LP_1Hz25;
      break;

    case LIS3MDL_LP_2Hz5:
      val = LIS3MDL_LP_2Hz5;
      break;

    case LIS3MDL_LP_5Hz:
      val = LIS3MDL_LP_5Hz;
      break;

    case LIS3MDL_LP_10Hz:
      val = LIS3MDL_LP_10Hz;
      break;

    case LIS3MDL_LP_20Hz:
      val = LIS3MDL_LP_20Hz;
      break;

    case LIS3MDL_LP_40Hz:
      val = LIS3MDL_LP_40Hz;
      break;

    case LIS3MDL_LP_80Hz:
      val = LIS3MDL_LP_80Hz;
      break;

    case LIS3MDL_MP_1Hz25:
      val = LIS3MDL_MP_1Hz25;
      break;

    case LIS3MDL_MP_2Hz5:
      val = LIS3MDL_MP_2Hz5;
      break;

    case LIS3MDL_MP_5Hz:
      val = LIS3MDL_MP_5Hz;
      break;

    case LIS3MDL_MP_10Hz:
      val = LIS3MDL_MP_10Hz;
      break;

    case LIS3MDL_MP_20Hz:
      val = LIS3MDL_MP_20Hz;
      break;

    case LIS3MDL_MP_40Hz:
      val = LIS3MDL_MP_40Hz;
      break;

    case LIS3MDL_MP_80Hz:
      val = LIS3MDL_MP_80Hz;
      break;

    case LIS3MDL_HP_1Hz25:
      val = LIS3MDL_HP_1Hz25;
      break;

    case LIS3MDL_HP_2Hz5:
      val = LIS3MDL_HP_2Hz5;
      break;

    case LIS3MDL_HP_5Hz:
      val = LIS3MDL_HP_5Hz;
      break;

    case LIS3MDL_HP_10Hz:
      val = LIS3MDL_HP_10Hz;
      break;

    case LIS3MDL_HP_20Hz:
      val = LIS3MDL_HP_20Hz;
      break;

    case LIS3MDL_HP_40Hz:
      val = LIS3MDL_HP_40Hz;
      break;

    case LIS3MDL_HP_80Hz:
      val = LIS3MDL_HP_80Hz;
      break;

    case LIS3MDL_UHP_1Hz25:
      val = LIS3MDL_UHP_1Hz25;
      break;

    case LIS3MDL_UHP_2Hz5:
      val = LIS3MDL_UHP_2Hz5;
      break;

    case LIS3MDL_UHP_5Hz:
      val = LIS3MDL_UHP_5Hz;
      break;

    case LIS3MDL_UHP_10Hz:
      val = LIS3MDL_UHP_10Hz;
      break;

    case LIS3MDL_UHP_20Hz:
      val = LIS3MDL_UHP_20Hz;
      break;

    case LIS3MDL_UHP_40Hz:
      val = LIS3MDL_UHP_40Hz;
      break;

    case LIS3MDL_UHP_80Hz:
      val = LIS3MDL_UHP_80Hz;
      break;

    default:
      ret = INVALID_VAL;
      break;
  }

  return ret;
}

status_t lis3mdl_set_outputDataRate(const mag_handle_t *handle, lis3mdl_do_rate_t val)
{
    lis3mdl_ctrl_reg1_t ctrl_reg1;
    lis3mdl_ctrl_reg4_t ctrl_reg4;
    lis3mdl_do_rate_t data_output_rates;
    status_t ret = MEMS_ERROR;

    ret = lis3mdl_validate_outputDataRate(val);
    
    if( ret != MEMS_SUCCESS)
    {
    return ret;
    }

    ret = lis3mdl_read_reg(handle->read_reg_if, handle->sesnor_read_addr, LIS3MDL_CTRL_REG1, (uint8_t *)&ctrl_reg1, sizeof(ctrl_reg1));

    if (ret == MEMS_SUCCESS)
    {
        ctrl_reg1.operation_mode = (uint8_t)val;
        ret = lis3mdl_write_reg(handle->write_reg_if, handle->sensor_write_addr, LIS3MDL_CTRL_REG1, (uint8_t *)&ctrl_reg1, sizeof(ctrl_reg1));
    }
    else
    {
        return ret;
    }

    if (ret == MEMS_SUCCESS)
    {
        /* set mode also for z axis, ctrl_reg4 -> omz */
        ret = lis3mdl_read_reg(handle->read_reg_if, handle->sesnor_read_addr, LIS3MDL_CTRL_REG4, (uint8_t *)&ctrl_reg4, sizeof(ctrl_reg4));
    }
    else
    {
        return ret;
    }

    if (ret == MEMS_SUCCESS)
    {
        ctrl_reg4.op_md_z = (uint8_t)(((uint8_t)val >> 4) & 0x03U);
        ret = lis3mdl_write_reg(handle->write_reg_if, handle->sensor_write_addr, LIS3MDL_CTRL_REG4, (uint8_t *)&ctrl_reg4, sizeof(ctrl_reg4));
    }else
    {
        return ret;
    }

    return ret;
}

status_t lis3mdl_get_outputDataRate(const mag_handle_t *handle, lis3mdl_do_rate_t *val)
{
    lis3mdl_ctrl_reg1_t ctrl_reg1;    
    status_t ret = MEMS_ERROR;

    /* z axis, ctrl_reg4 -> operation mode z axis is aligned with x/y axis ctrl_reg1 -> operation mode*/
    if(lis3mdl_read_reg(handle->read_reg_if, handle->sesnor_read_addr, LIS3MDL_CTRL_REG1, (uint8_t *)&ctrl_reg1, sizeof(ctrl_reg1)) == MEMS_SUCCESS)
     ret = lis3mdl_validate_OutputDataRate(ctrl_reg1.operation_mode);

    return ret;
}


/**** Interrupt pin enable control function****/

status_t lis3mdl_ctrl_intPinEnable(const mag_handle_t *handle, lis3mdl_cmds_t cmd)
{
    lis3mdl_int_cfg_t int_cfg;
    status_t ret = MEMS_ERROR;

    ret = lis3mdl_read_reg(handle->read_reg_if, handle->sesnor_read_addr, LIS3MDL_INT_CFG, (uint8_t *)&int_cfg, sizeof(int_cfg));

    if (ret == MEMS_SUCCESS)
    {
        int_cfg.ir_pin_en = cmd;
        ret = lis3mdl_write_reg(handle->write_reg_if, handle->sensor_write_addr, LIS3MDL_INT_CFG, (uint8_t *)&int_cfg, sizeof(int_cfg));
    }

    return ret;
}

status_t  lis3mdl_get_magnetometerSensitivity(const mag_handle_t *handle, mag_data_t *mag_data)
{
    lis3mdl_fs_config_t fs_config;

      /* get actual scale selection from sensor. */
  if ( lis3mdl_get_full_scale_config(handle, &fs_config ) != MEMS_SUCCESS )
  {
    return MEMS_ERROR;
  }

  /* Calculate the sensitivity based on full scale configurations. */
  switch( fs_config )
  {
    case LIS3MDL_4_GAUSS:
      mag_data->measurments.sensitivity = ( float )LIS3MDL_SENSITIVITY_FOR_FS_4G;
      break;
    case LIS3MDL_8_GAUSS:
      mag_data->measurments.sensitivity = ( float )LIS3MDL_SENSITIVITY_FOR_FS_8G;
      break;
    case LIS3MDL_12_GAUSS:
      mag_data->measurments.sensitivity = ( float )LIS3MDL_SENSITIVITY_FOR_FS_12G;
      break;
    case LIS3MDL_16_GAUSS:
      mag_data->measurments.sensitivity = ( float )LIS3MDL_SENSITIVITY_FOR_FS_16G;
      break;
    default:
      return INVALID_VAL;
      break;
  }
  return MEMS_SUCCESS;
}
/**** Get magnetometer measurement values function ****/

status_t lis3mdl_get_magnetometerMeasurments(const mag_handle_t *handle, mag_data_t *mag_data)
{
    uint8_t reg_dataRaw[6];
    uint8_t sensitivity = 0;

    /* Read raw output registers from LIS3MDL_OUTX_L to LIS3MDL_OUTZ_H. */
    if (lis3mdl_read_reg(handle->read_reg_if, handle->sesnor_read_addr, LIS3MDL_OUTX_L, (uint8_t *)reg_dataRaw, 6) != MEMS_SUCCESS)
        return MEMS_ERROR;

    /* Format data. */
    mag_data->measurments.raw_xyz[0] = ((((int16_t)reg_dataRaw[1]) << 8) + (int16_t)reg_dataRaw[0]);
    mag_data->measurments.raw_xyz[1] = ((((int16_t)reg_dataRaw[3]) << 8) + (int16_t)reg_dataRaw[2]);
    mag_data->measurments.raw_xyz[2] = ((((int16_t)reg_dataRaw[5]) << 8) + (int16_t)reg_dataRaw[4]);


    /* Get LIS3MDL actual sensitivity. */
    if (lis3mdl_get_magnetometerSensitivity(handle,mag_data) != MEMS_SUCCESS)
    {
        return MEMS_ERROR;
    }

    /* Calculate the data. */
    mag_data->measurments.x_gauss = (int32_t)(mag_data->measurments.raw_xyz[0] * mag_data->measurments.sensitivity);
    mag_data->measurments.x_gauss = (int32_t)(mag_data->measurments.raw_xyz[1] * mag_data->measurments.sensitivity);
    mag_data->measurments.x_gauss = (int32_t)(mag_data->measurments.raw_xyz[2] * mag_data->measurments.sensitivity);

    return MEMS_SUCCESS;
}

/**** IO Read Write Registers functions ****/

status_t lis3mdl_read_reg( mag_read_t read_reg_if, uint8_t mag_read_addr, uint8_t reg, uint8_t *pdata, uint16_t len )
{
  status_t ret = MEMS_ERROR;

  if (read_reg_if == NULL) 
  {
    return NO_IF_REGISTERED;
  }

  ret = read_reg_if(mag_read_addr,reg, pdata, len);

  return ret;
}

status_t lis3mdl_write_reg( mag_write_t write_reg_if, uint8_t mag_write_addr, uint8_t reg, uint8_t *pdata, uint16_t len )
{
  status_t ret;

  if (write_reg_if == NULL)
  {
    return NO_IF_REGISTERED;
  }

  ret = write_reg_if(mag_write_addr, reg, pdata, len);

  return ret;
}




