/* Copyright (c) 2011-2018, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef MSM_OTP_H
#define MSM_OTP_H

#include <linux/i2c.h>
#include <linux/gpio.h>
#include <soc/qcom/camera2.h>
#include <media/v4l2-subdev.h>
#include <media/msmb_camera.h>
#include "msm_camera_i2c.h"
#include "msm_camera_spi.h"
#include "msm_camera_io_util.h"
#include "msm_camera_dt_util.h"
#include "cam_soc_api.h"

#define DEFINE_MSM_MUTEX(mutexname) \
	static struct mutex mutexname = __MUTEX_INITIALIZER(mutexname)

#define PROPERTY_MAXSIZE 32
#define r_otp_addr_h     0x010A
#define r_otp_addr_l     0x010B
#define r_otp_cmd        0x0102
#define r_otp_wdata      0x0106
#define r_otp_rdata      0x0108
#define START_ADDR_FOR_S5K5E3_OTP 0xA04

struct msm_otp_ctrl_t {
	struct platform_device *pdev;
	struct mutex *otp_mutex;
	struct v4l2_subdev sdev;
	struct v4l2_subdev_ops *eeprom_v4l2_subdev_ops;
	enum msm_camera_device_type_t otp_device_type;
	struct msm_sd_subdev msm_sd;
	enum cci_i2c_master_t cci_master;
	struct msm_camera_i2c_client i2c_client;
	struct msm_eeprom_memory_block_t cal_data;
	uint8_t is_supported;
	struct msm_eeprom_board_info *eboard_info;
	uint32_t subdev_id;
};

extern uint8_t* get_eeprom_data_addr(void);

#endif