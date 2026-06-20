// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (c) 2017-2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#include <linux/module.h>
#include <linux/firmware.h>

#include "cam_sensor_cmn_header.h"
#include "cam_ois_core.h"
#include "cam_ois_soc.h"
#include "cam_sensor_util.h"
#include "cam_debug_util.h"
#include "cam_res_mgr_api.h"
#include "cam_common_util.h"
#include "cam_packet_util.h"
#include "zte_camera_ois_util.h"
#include "cam_ois_dw978x.h"

/* dw9784 */
struct cam_sensor_i2c_reg_array ois_dw9784_init[15] =
{
	/* step 1: MTP Erase and DSP Disable for firmware 0x8000 write */
	{0xd001, 0x0000, 0, 0xFFFF},

	/* release all protection */
	{0xFAFA, 0x98AC, 1, 0xFFFF},
	{0xF053, 0x70BD, 1, 0xFFFF},

	{0xDE01, 0x0000, 1, 0xFFFF},
	{0xFD00, 0x5252, 1, 0xFFFF},

	/* 4k Sector_0 */
	{0xde03, 0x0000, 0, 0xFFFF},
	/* 4k Sector Erase */
	{0xde04, 0x0002, 10, 0xFFFF},
	/* 4k Sector_1 */
	{0xde03, 0x0008, 0, 0xFFFF},
	/* 4k Sector Erase */
	{0xde04, 0x0002, 10, 0xFFFF},
	/* 4k Sector_2 */
	{0xde03, 0x0010, 0, 0xFFFF},
	/* 4k Sector Erase */
	{0xde04, 0x0002, 10, 0xFFFF},
	/* 4k Sector_3 */
	{0xde03, 0x0018, 0, 0xFFFF},
	/* 4k Sector Erase */
	{0xde04, 0x0002, 10, 0xFFFF},
	/* 4k Sector_4 */
	{0xde03, 0x0020, 0, 0xFFFF},
	/* 4k Sector Erase */
	{0xde04, 0x0002, 10, 0xFFFF}
};

struct cam_sensor_i2c_reg_array ois_dw978x_reset[3] =
{
	{0xD002, 0x0001, 4, 0xFFFF},    /* printfc reset */
	{0xD001, 0x0001, 25, 0xFFFF},   /* Active mode (DSP ON) */
	{0xEBF1, 0x56FA, 1, 0xFFFF}     /* User protection release */
};

struct cam_sensor_i2c_reg_array ois_dw9784_extra_init[3] =
{
	{0xDE01, 0x1000, 1, 0xFFFF},
	{0xde03, 0x0000, 1, 0xFFFF},
	{0xde04, 0x0008, 10, 0xFFFF}
};

/* DW9785 configuration */
struct cam_sensor_i2c_reg_array dw9785_init_regs[3] = {
	{0xD001, 0x0000, 0, 0xFFFF},    /* MCU disable */
	{0xD01A, 0x0001, 0, 0xFFFF},    /* Wake up */
	{0xDEA3, 0xAFDA, 1, 0xFFFF}     /* Program memory protection off */
};

struct cam_sensor_i2c_reg_array dw9785_reset_regs[4] = {
	{0xD002, 0x0001, 4, 0xFFFF},    /* Reset */
	{0xD001, 0x0001, 25, 0xFFFF},   /* Active mode */
	{0xDD03, 0x0002, 1, 0xFFFF},    /* I2C SDA strength x1 */
	{0xDD04, 0x0002, 1, 0xFFFF}     /* I2C SDA strength x1 */
};

struct cam_sensor_i2c_reg_array dw9785_extra_regs[6] = {
	{0xD004, 0x0000, 1, 0xFFFF},  /* MCU enable check */
	{0xDE00, 0x0000, 0, 0xFFFF},  /* Wait check register */
	{0xDE01, 0x0020, 1, 0xFFFF},  /* FMC block FW select */
	{0xDE04, 0x0000, 0, 0},       /* Write ois firmware addr setting register*/
	{0xDE05, 0x0000, 0, 0},       /* Write ois firmware addr setting register*/
	{0xDE06, 0x0002, 36, 0xFFFF}  /* Auto-Program Area Erase */
};

struct cam_sensor_i2c_reg_array dw9785_fw_checksum_regs[4] = {
	{0x74FE, 0x0000, 0, 0xFFFF},    /* reg_fw_checksum[1] */
	{0x74FF, 0x0000, 0, 0xFFFF},    /* reg_fw_checksum[0] */
	{0xD010, 0x0000, 0, 0xFFFF},    /* reg_flash_checksum_status */
	{0xD011, 0x0000, 0, 0xFFFF}     /* reg_rv_checksum_status */
};

struct ois_model_config dw978x_model_config = {
	.model = ois_dw9784,
	.slave_addr = DW9784_SLAVE_ADDR,
	.addr_type = CAMERA_SENSOR_I2C_TYPE_WORD,
	.data_type = CAMERA_SENSOR_I2C_TYPE_WORD,
	.init_regs = ois_dw9784_init,
	.init_write_size = ARRAY_SIZE(ois_dw9784_init),
	.extra_init_regs = ois_dw9784_extra_init,
	.extra_init_write_size = ARRAY_SIZE(ois_dw9784_extra_init),
	.reset_regs = ois_dw978x_reset,
	.reset_write_size = ARRAY_SIZE(ois_dw978x_reset),
};

struct ois_model_config dw9785_model_config = {
	.model = ois_dw9785,
	.slave_addr = DW9785_SLAVE_ADDR,
	.addr_type = CAMERA_SENSOR_I2C_TYPE_WORD,
	.data_type = CAMERA_SENSOR_I2C_TYPE_WORD,
	.init_regs = dw9785_init_regs,
	.init_write_size = ARRAY_SIZE(dw9785_init_regs),
	.extra_init_regs = NULL,
	.extra_init_write_size = 0,
	.reset_regs = dw9785_reset_regs,
	.reset_write_size = ARRAY_SIZE(dw9785_reset_regs),
};

struct CameraOisParams g_CameraOisParams[] = {
	{
		.SensorName = "ov64b40_qwbarley",
		.OISName = "ois_ov64b40_qwbarley",
		.FWVersion = 0xA01,
		.FWDate = 0x0715,
		.config = &dw978x_model_config,
	},
	{
		.SensorName = "ov50e40_qwjujube",
		.OISName = "ois_dw9785_qwjujube",
		.FWVersion = 0x302,
		.FWDate = 0x0623,
		.config = &dw9785_model_config,
	},
};

int g_CameraOisParamsCount = ARRAY_SIZE(g_CameraOisParams);

/*FUNC*/
void swap_low_high_byte(uint32_t *data)
{
	uint32_t UpdateH, UpdateL = 0;

	UpdateH = (*data & 0xFF) << 8;
	UpdateL = (*data & 0xFF00) >> 8;
	*data = UpdateH | UpdateL;
}

static int cam_ois_write_regs(
	struct cam_ois_ctrl_t                   *o_ctrl,
	struct ois_model_config                 *modecfg,
	const struct cam_sensor_i2c_reg_array   *regs,
	uint32_t                                 size)
{
	int rc = 0;
	uint8_t cnt;

	if (!modecfg || !o_ctrl || !regs) {
		CAM_ERR(CAM_OIS, "Invalid Args");
		return -EINVAL;
	}

	for (cnt = 0; cnt < size; cnt++) {
		rc = zte_cam_cci_i2c_write(&(o_ctrl->io_master_info),
			regs[cnt].reg_addr,
			regs[cnt].reg_data,
			modecfg->addr_type,
			modecfg->data_type);
		msleep(regs[cnt].delay);

		if (rc < 0) {
			CAM_ERR(CAM_OIS, "dw978x i2c write failed, rc=%d", rc);
			return rc;
		}
	}

	return rc;
}

int cam_ois_dw978x_init(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg)
{
	return cam_ois_write_regs(o_ctrl, modecfg,
		modecfg->init_regs, modecfg->init_write_size);
}

int cam_ois_dw978x_extra_init(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg)
{
	return cam_ois_write_regs(o_ctrl, modecfg,
		modecfg->extra_init_regs, modecfg->extra_init_write_size);
}

int cam_ois_dw978x_reset(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg)
{
	return cam_ois_write_regs(o_ctrl, modecfg,
		modecfg->reset_regs, modecfg->reset_write_size);
}

int dw9785_fw_wait_check_register(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg,
	uint16_t                read_cycle,
	uint16_t                wait_delay)
{
	uint32_t r_data;

	for (int i = 0; i < read_cycle; i++) {
		cam_cci_i2c_read(o_ctrl->io_master_info.cci_client,
						 dw9785_extra_regs[wait_check_register].reg_addr,
						 &r_data,
						 modecfg->addr_type,
						 modecfg->data_type,
						 TRUE);

		if (r_data == dw9785_extra_regs[wait_check_register].reg_data) {
			CAM_DBG(CAM_OIS, "[dw9785_fw_wait_check_register] pass (addr : 0x%04X, data : 0x%04X, cnt: %d, delay: %dms)",
				dw9785_extra_regs[wait_check_register].reg_addr, r_data, i, i * wait_delay);
			return FUNC_PASS;
		}
		msleep(wait_delay);
	}

	CAM_DBG(CAM_OIS, "[dw9785_fw_wait_check_register] fail (addr : 0x%04X, data : 0x%04X, cnt: %d, time: %dms)",
		dw9785_extra_regs[wait_check_register].reg_addr, r_data, read_cycle, read_cycle * wait_delay);

	return FUNC_FAIL;
}

int cam_ois_dw9785_reset(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg)
{
	uint32_t product_id = 0;
	int32_t rc = 0;

	rc = cam_ois_write_regs(o_ctrl, modecfg,
			modecfg->reset_regs, modecfg->reset_write_size);
	CHECK_RC(rc, "Failed to dw9785 reset %d", rc);

	/* mcu enable */
	cam_cci_i2c_read(o_ctrl->io_master_info.cci_client,
					dw9785_extra_regs[mcu_enable_check].reg_addr,
					&product_id,
					modecfg->addr_type,
					modecfg->data_type,
					TRUE);
	msleep(1); /* wait for fw initialize */

	if(product_id == DW9785_CHIP_ID) {
		CAM_DBG(CAM_OIS, "[dw9785_mcu_enable] pass");
	} else {
		CAM_ERR(CAM_OIS, "[dw9785_mcu_enable] fail");
		return -EINVAL;
	}

	return rc;
}

int dw9785_fw_eflash_erase(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg)
{
	int32_t rc = 0;
	CHECK_PTR(modecfg, o_ctrl, "Invalid Args");

	CAM_DBG(CAM_OIS, "[dw9785_fw_eflash_erase] start");
	CAM_DBG(CAM_OIS, "[dw9785_fw_eflash_erase] prog_auto_erase Run");

	/* Auto-Program Area Erase */
	rc = zte_cam_cci_i2c_write(&(o_ctrl->io_master_info),
								dw9785_extra_regs[area_erase].reg_addr,
								dw9785_extra_regs[area_erase].reg_data,
								modecfg->addr_type,
								modecfg->data_type);
	msleep(dw9785_extra_regs[area_erase].delay);
	CHECK_RC(rc, "Failed to dw9785 fw_eflash_erase %d", rc);

	if(dw9785_fw_wait_check_register(o_ctrl, modecfg, 3, 30) != FUNC_PASS){
		CAM_ERR(CAM_OIS, "[dw9785_fw_eflash_erase] fail");
		return ERROR_FW_ERASE;
	}

	CAM_DBG(CAM_OIS, "[dw9785_fw_eflash_erase] finish");
	return FUNC_PASS;
}

int dw9785_fw_select(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg)
{
	int32_t	rc = 0;
	uint32_t FMC;

	CHECK_PTR(modecfg, o_ctrl, "Invalid Args");

	CAM_DBG(CAM_OIS, "[FMC block FW select] start");

	/* FMC block FW select */
	rc = zte_cam_cci_i2c_write(&(o_ctrl->io_master_info),
								dw9785_extra_regs[fw_slect].reg_addr,
								dw9785_extra_regs[fw_slect].reg_data,
								modecfg->addr_type,
								modecfg->data_type);
	msleep(dw9785_extra_regs[fw_slect].delay);
	CHECK_RC(rc, "Failed to dw9785 fw_select %d", rc);

	cam_cci_i2c_read(o_ctrl->io_master_info.cci_client,
					dw9785_extra_regs[fw_slect].reg_addr,
					&FMC,
					modecfg->addr_type,
					modecfg->data_type,
					TRUE);

	if (FMC != PROG_MEM_SEL)
	{
		CAM_ERR(CAM_OIS, "[dw9785_download_fw] fmc register value 1st warning : %04x", FMC);
		rc = zte_cam_cci_i2c_write(&(o_ctrl->io_master_info),
									dw9785_extra_regs[fw_slect].reg_addr,
									PROG_MEM_SEL,
									modecfg->addr_type,
									modecfg->data_type);
		msleep(dw9785_extra_regs[fw_slect].delay);
		CHECK_RC(rc, "Failed to dw9785 fmc register %d", rc);

		FMC = 0;
		cam_cci_i2c_read(o_ctrl->io_master_info.cci_client,
						dw9785_extra_regs[fw_slect].reg_addr,
						&FMC,
						modecfg->addr_type,
						modecfg->data_type,
						TRUE);
		if (FMC != 0)
		{
			CAM_ERR(CAM_OIS, "[dw9785_download_fw] 2nd fmc register value 2nd warning : %04x", FMC);
			CAM_ERR(CAM_OIS, "[dw9785_download_fw] stop f/w download");
			return ERROR_FW_DOWN_FMC;
		}
	}

	return FUNC_PASS;
}

int dw9785_fw_checksum_check(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg)
{
	/*
	flash_checksum_status : 0xD010
	Bit [0]: fw checksum error
	Bit [1]: data-x checksum status
	Bit [2]: param checksum error
	*/
	uint32_t reg_values[4] = {0};
	int rc;

	CHECK_PTR(modecfg, o_ctrl, "Invalid Args");

	//i2c_block_read_reg(0x74FE, &reg_fw_checksum, 2);

	//read_reg_16bit_value_16bit(0xD010, &reg_flash_checksum_status);
	//read_reg_16bit_value_16bit(0xD011, &reg_rv_checksum_status);
	for (int i = 0; i < ARRAY_SIZE(dw9785_fw_checksum_regs); i++) {
		rc = cam_cci_i2c_read(o_ctrl->io_master_info.cci_client,
							  dw9785_fw_checksum_regs[i].reg_addr,
							  &reg_values[i],
							  modecfg->addr_type,
							  modecfg->data_type,
							  TRUE);
		CHECK_RC(rc, "Failed to read register 0x%04X: %d",
					dw9785_fw_checksum_regs[i].reg_addr, rc);
	}

	uint32_t reg_fw_checksum[2] = {reg_values[1], reg_values[0]};
	uint32_t reg_flash_checksum_status = reg_values[2];
	uint32_t reg_rv_checksum_status = reg_values[3];

	CAM_ERR(CAM_OIS, "[dw9785_fw_checksum] fw checksum(0x74FE) : 0x%04X%04X",
			reg_fw_checksum[1], reg_fw_checksum[0]);

	if (reg_rv_checksum_status == AUTORD_RV_OK) {
		CAM_DBG(CAM_OIS, "[dw9785_fw_checksum_check] read_verification_checksum : 0x%04X - pass",
				reg_rv_checksum_status);
	} else {
		CAM_ERR(CAM_OIS, "[dw9785_fw_checksum_check] read_verification_checksum : 0x%04X - fail",
				reg_rv_checksum_status);
		return ERROR_RV_CHECKSUM;
	}

	if ((reg_flash_checksum_status & FLASH_FW_CHECKSUM_OK) == FLASH_FW_CHECKSUM_OK) {
		CAM_DBG(CAM_OIS, "[dw9785_fw_checksum_check] flash_checksum(0x%04X) : 0x%04X - pass",
				0xD010, reg_flash_checksum_status);
	} else {
		if (!(reg_flash_checksum_status & FLASH_FW_CHECKSUM))
			CAM_ERR(CAM_OIS, "[dw9785_fw_checksum_check] fw flash checksum(bit[0]) : 0x%04X - error",
					reg_flash_checksum_status);

		if (!(reg_flash_checksum_status & FLASH_DATA_X_CHECKSUM))
			CAM_ERR(CAM_OIS, "[dw9785_fw_checksum_check] data_X flash checksum(bit[1]) : 0x%04X - error",
					reg_flash_checksum_status);

		if (!(reg_flash_checksum_status & FLASH_PARAM_CHECKSUM))
			CAM_ERR(CAM_OIS, "[dw9785_fw_checksum_check] param flash checksum(bit[2]) : 0x%04X - error",
					reg_flash_checksum_status);

		return ERROR_FLASH_CHECKSUM;
	}

	return FUNC_PASS;
}


int dw9785_write_ois_firmware(struct cam_ois_ctrl_t *o_ctrl, uint16_t *fireware)
{
	struct cam_sensor_i2c_reg_array addr_setting;
	struct cam_sensor_i2c_reg_array data_setting[PKT_SIZE];

	// 初始化地址配置（固定部分）
	struct cam_sensor_i2c_reg_setting addr_config = {
		.reg_setting = &addr_setting,
		.size = 1,
		.addr_type = CAMERA_SENSOR_I2C_TYPE_WORD,
		.data_type = CAMERA_SENSOR_I2C_TYPE_WORD,
		.delay = 0,
		.read_buff = NULL,
		.read_buff_len = 0
	};

	struct cam_sensor_i2c_reg_setting data_config = {
		.reg_setting = data_setting,
		.size = PKT_SIZE,
		.addr_type = CAMERA_SENSOR_I2C_TYPE_WORD,
		.data_type = CAMERA_SENSOR_I2C_TYPE_WORD,
		.delay = 0,
		.read_buff = NULL,
		.read_buff_len = 0
	};

	addr_setting.reg_addr = dw9785_extra_regs[fw_addr_setting].reg_addr;
	addr_setting.delay = dw9785_extra_regs[fw_addr_setting].delay;
	addr_setting.data_mask = dw9785_extra_regs[fw_addr_setting].data_mask;

	for (int i = 0; i < PKT_SIZE; i++) {
		data_setting[i].reg_addr = dw9785_extra_regs[fw_data_setting].reg_addr;
		data_setting[i].delay = dw9785_extra_regs[fw_data_setting].delay;
		data_setting[i].data_mask = dw9785_extra_regs[fw_data_setting].data_mask;
	}

	for (int i = 0; i < DW9785_MCS_SIZE_W / 2; i += PKT_SIZE) {
		uint32_t curr_addr = MCS_START_ADDRESS + i * 2;

		addr_setting.reg_data = curr_addr;

		int32_t rc = camera_io_dev_write_continuous(&(o_ctrl->io_master_info), &addr_config, 1);
		if (rc != 0) {
			CAM_ERR(CAM_OIS, "Address write failed at block %d (0x%04X)",
					i / PKT_SIZE, curr_addr);
			return rc;
		}
		uint32_t temp;

		for (int j = 0; j < PKT_SIZE; j++) {
			temp = fireware[i + j];
			swap_low_high_byte(&temp);
			data_setting[j].reg_data = temp;
		}

		rc = camera_io_dev_write_continuous(&(o_ctrl->io_master_info), &data_config, 1);
		if (rc != 0) {
			CAM_ERR(CAM_OIS, "Data write failed at block %d", i / PKT_SIZE);
			return rc;
		}

		if (i % (PKT_SIZE * 10) == 0) {
			CAM_ERR(CAM_OIS, "procession: %d/%d",
					 i / PKT_SIZE, (DW9785_MCS_SIZE_W / 2) / PKT_SIZE);
		}
	}

	return FUNC_PASS;
}

bool cam_ois_dw978x_need_update_fw(
	struct cam_ois_ctrl_t *o_ctrl)
{
	if (!o_ctrl || !o_ctrl->soc_info.dev || !o_ctrl->soc_info.dev->of_node) {
		CAM_ERR(CAM_OIS, "Invalid device node configuration");
		return false;
	}

	bool fw_update_enabled = of_property_read_bool(o_ctrl->soc_info.dev->of_node, "firmware-update-enable");
	CAM_INFO(CAM_OIS, "%s: firmware update enabled: %d", o_ctrl->ois_name, fw_update_enabled);

	return fw_update_enabled;
}

uint32_t cam_ois_read_firmware_ver(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg)
{
	int32_t rc = 0;
	uint32_t addr_ver, addr_date, ver, date;
	uint32_t firmware_ver = INVAILD_FW_VER;

	if (!o_ctrl || !modecfg) {
		CAM_ERR(CAM_OIS, "Invalid Args");
		return firmware_ver;
	}

	o_ctrl->io_master_info.cci_client->sid = (modecfg->slave_addr) >> 1;
	o_ctrl->io_master_info.cci_client->i2c_freq_mode = I2C_STANDARD_MODE;
	msleep(5);

	switch (modecfg->model) {
		case ois_dw9784:
			rc = cam_ois_dw978x_reset(o_ctrl, modecfg);
			break;
		case ois_dw9785:
			rc = cam_ois_dw9785_reset(o_ctrl, modecfg);
			break;
		default:
			rc = -EINVAL;
			CAM_ERR(CAM_OIS, "Unsupported OIS model: %d", modecfg->model);
	}

	if(rc != FUNC_PASS) {
		CAM_ERR(CAM_OIS, "%s: Failed to reset %d", o_ctrl->ois_name, rc);
		return firmware_ver;
	}

	addr_ver = 0x7001;
	ver = 0;
	rc = cam_cci_i2c_read(o_ctrl->io_master_info.cci_client, addr_ver, &ver, modecfg->addr_type, modecfg->data_type, TRUE);
	if (rc < 0) {
		CAM_ERR(CAM_OIS, "%s :%d: read vers id fail\n", __func__, __LINE__);
	}

	addr_date = 0x7002;
	date = 0;
	rc = cam_cci_i2c_read(o_ctrl->io_master_info.cci_client, addr_date, &date, modecfg->addr_type, modecfg->data_type, TRUE);
	CHECK_RC(rc, "read date fail %d", rc);

	firmware_ver = ver << 16 | date;
	if (rc < 0) {
		CAM_ERR(CAM_OIS, "%s :%d: read date	 fail\n", __func__, __LINE__);
	}
	CAM_ERR(CAM_OIS, "%s ver:0x%x, date:0x%x firmware_ver:0x%x\n", o_ctrl->ois_name, ver, date, firmware_ver);

	return firmware_ver;
}

/*9784*/
int32_t dw978x_download_fw(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg,
	uint32_t                *data)
{
	uint16_t						   total_words = 0;
	uint16_t						   *ptr = NULL;
	int32_t							   rc = 0, cnt;
	uint32_t						   fw_size;
	const struct firmware			  *fw = NULL;
	const char						  *fw_name_prog = NULL;
	char							   name_prog[NAME_PROG_SIZE] = {0};
	struct device					  *dev = &(o_ctrl->pdev->dev);
	struct cam_sensor_i2c_reg_setting  i2c_reg_setting;
	void							  *vaddr = NULL;
	int32_t							   max_len = 128;
	int32_t							   current_len = max_len;
	uint32_t						   temp;
	uint32_t						   addr_offset = 0;

	CHECK_PTR(modecfg, o_ctrl, "Invalid Args");

	o_ctrl->io_master_info.cci_client->sid = (modecfg->slave_addr) >> 1;
	o_ctrl->io_master_info.cci_client->i2c_freq_mode = I2C_STANDARD_MODE;

	CAM_INFO(CAM_OIS, "cam_ois_dw978x_firmware_download %s E", o_ctrl->ois_name);

	snprintf(name_prog, NAME_PROG_SIZE, "%s.prog", o_ctrl->ois_name);
	/* cast pointer as const pointer*/
	fw_name_prog = name_prog;

	// init
	rc = cam_ois_dw978x_init(o_ctrl, modecfg);
	CHECK_RC(rc, "Failed to dw978x init %d", rc);

	/* Load FW prog*/
	rc = request_firmware(&fw, fw_name_prog, dev);
	CHECK_RC(rc, "Failed to locate %s", fw_name_prog);

	CAM_DBG(CAM_OIS, "fw->size %d", fw->size);
	total_words = fw->size - EXTRA_FIRMWARE_SIZE;

	i2c_reg_setting.addr_type = modecfg->addr_type;
	i2c_reg_setting.data_type = modecfg->data_type;
	total_words = total_words / 2;	 //word

	i2c_reg_setting.size = total_words;
	i2c_reg_setting.delay = 0;
	fw_size = (sizeof(struct cam_sensor_i2c_reg_array) * total_words);
	vaddr = vmalloc(fw_size);
	if (!vaddr) {
		CAM_ERR(CAM_OIS,
			"Failed in allocating i2c_array: fw_size: %u", fw_size);
		release_firmware(fw);
		return -ENOMEM;
	}

	o_ctrl->opcode.prog = 0x8000;
	CAM_ERR(CAM_OIS, "FW prog size(word):%d. o_ctrl->opcode.prog[0x%x]", total_words, o_ctrl->opcode.prog);

	i2c_reg_setting.reg_setting = (struct cam_sensor_i2c_reg_array *) (
		vaddr);

	ptr = (uint16_t *)fw->data;
	do {
		current_len = (total_words > max_len) ? max_len : total_words;
		for (cnt = 0; cnt < current_len; cnt++, ptr++) {
			i2c_reg_setting.reg_setting[cnt].reg_addr =
			o_ctrl->opcode.prog + addr_offset;
			temp = *ptr;
			swap_low_high_byte(&temp);
			i2c_reg_setting.reg_setting[cnt].reg_data = temp;
			i2c_reg_setting.reg_setting[cnt].delay = 0;
			i2c_reg_setting.reg_setting[cnt].data_mask = 0;
		}
		i2c_reg_setting.size = cnt;
		addr_offset = addr_offset + cnt;
		rc = camera_io_dev_write_continuous(&(o_ctrl->io_master_info),
			&i2c_reg_setting, 1);
		if (rc < 0) {
			CAM_ERR(CAM_OIS, "OIS FW download failed %d", rc);
		}
		total_words -= cnt;
	} while (total_words > 0);

	// extra init
	rc = cam_ois_dw978x_extra_init(o_ctrl, modecfg);
	CHECK_RC(rc, "Failed to dw978x extra init %d", rc);

	// extra firmware download
	total_words = EXTRA_FIRMWARE_SIZE;
	total_words = total_words / 2;  //word
	addr_offset = 0;

	do {
		current_len = (total_words > max_len) ? max_len : total_words;
		for (cnt = 0; cnt < current_len; cnt++, ptr++) {
			i2c_reg_setting.reg_setting[cnt].reg_addr =
			o_ctrl->opcode.prog + addr_offset;  //  0x8000
			temp = *ptr;
			swap_low_high_byte(&temp);
			i2c_reg_setting.reg_setting[cnt].reg_data = temp;
			i2c_reg_setting.reg_setting[cnt].delay = 0;
			i2c_reg_setting.reg_setting[cnt].data_mask = 0;
		}
		i2c_reg_setting.size = cnt;
		addr_offset = addr_offset + cnt;
		rc = camera_io_dev_write_continuous(&(o_ctrl->io_master_info),
			&i2c_reg_setting, 1);
		if (rc < 0) {
			CAM_ERR(CAM_OIS, "OIS FW download failed %d", rc);
		}
		total_words -= cnt;
	} while (total_words > 0);

	// read firmware version
	*data = cam_ois_read_firmware_ver(o_ctrl, modecfg);

	if (vaddr) {
		vfree(vaddr);
		vaddr = NULL;
	}

	fw_size = 0;
	release_firmware(fw);

	CAM_ERR(CAM_OIS, "%s Exit\n", __func__);

	return rc;
}

int32_t dw9785_download_fw(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg,
	uint32_t                *data)
{
	int32_t	rc = 0;
	uint16_t *ptr = NULL;
	char name_prog[NAME_PROG_SIZE] = {0};
	const char *fw_name_prog = NULL;
	struct device *dev = &(o_ctrl->pdev->dev);
	const struct firmware *fw = NULL;

	CHECK_PTR(modecfg, o_ctrl, "Invalid Args");

	CAM_INFO(CAM_OIS, "dw9785_download_fw %s Entry", o_ctrl->ois_name);

	snprintf(name_prog, NAME_PROG_SIZE, "%s.prog", o_ctrl->ois_name);

	/* cast pointer as const pointer*/
	fw_name_prog = name_prog;

	/* Load FW prog*/
	rc = request_firmware(&fw, fw_name_prog, dev);
	CHECK_RC(rc, "Failed to locate %s", fw_name_prog);

	CAM_DBG(CAM_OIS, "fw->size %d", fw->size);
	ptr = (uint16_t *)fw->data;

	CAM_DBG(CAM_OIS, "[dw9785_download_fw] start");

	rc = cam_ois_dw9785_reset(o_ctrl, modecfg);
	CHECK_RC(rc, "Failed to dw9785 reset %d", rc);

	CAM_DBG(CAM_OIS, "[dw9785_ois_reset] done : standby");

	/* step 1: MCU Disable (sleep mode) and prog mem protection off*/
	rc = cam_ois_dw978x_init(o_ctrl, modecfg);
	CHECK_RC(rc, "Failed to dw978x init %d", rc);

	/* step 2: erase flash fw area */
	if(dw9785_fw_eflash_erase(o_ctrl, modecfg) != FUNC_PASS)
		return ERROR_FW_ERASE;

	/* step 3: FMC register check */
	if(dw9785_fw_select(o_ctrl, modecfg) != FUNC_PASS)
		return ERROR_FW_DOWN_FMC;

	/* step 4: firmware sequential write to flash */
	/* updates the module status before firmware download */
	//CAM_ERR(CAM_OIS, "[dw9785_download_fw] fw ver. : 0x%04x, fw size : %d [Byte]", DW9785_FW_VERSION, MCS_SIZE_W);

	CAM_DBG(CAM_OIS, "[dw9785_download_fw] sequential write start");
	dw9785_write_ois_firmware(o_ctrl, ptr);
	msleep(300);

	if(dw9785_fw_wait_check_register(o_ctrl, modecfg, LOOP, WAIT_TIME) != FUNC_PASS){
		CAM_ERR(CAM_OIS, "[dw9785_download_fw] sequential write done");
	}

	/* step 5: memory load from sram */
	cam_ois_dw9785_reset(o_ctrl, modecfg);

	/* step 6: check fw_checksum */
	if(dw9785_fw_checksum_check(o_ctrl, modecfg) == FUNC_PASS)
	{
		CAM_ERR(CAM_OIS, "[dw9785_download_fw] fw download success.");
		CAM_DBG(CAM_OIS, "[dw9785_download_fw] finish");
	} else {
		CAM_ERR(CAM_OIS, "[dw9785_download_fw] fw download cheksum fail.");
		CAM_DBG(CAM_OIS, "[dw9785_download_fw] finish");
		return ERROR_FW_CHECKSUM;
	}
	msleep(5);

	/* step 8: read firmware version */
	*data = cam_ois_read_firmware_ver(o_ctrl, modecfg);

	return rc;
}

uint32_t cam_ois_dw978x_firmware_download(
	struct cam_ois_ctrl_t   *o_ctrl,
	struct ois_model_config *modecfg)
{
	uint32_t firmware_ver = INVAILD_FW_VER;
	int32_t rc;

	if (!o_ctrl || !modecfg) {
		CAM_ERR(CAM_OIS, "Invalid Args");
		return firmware_ver;
	}

	switch (modecfg->model) {
		case ois_dw9784:
			rc = dw978x_download_fw(o_ctrl, modecfg, &firmware_ver);
			break;
		case ois_dw9785:
			rc = dw9785_download_fw(o_ctrl, modecfg, &firmware_ver);
			break;
		default:
			rc = -EINVAL;
			CAM_ERR(CAM_OIS, "Unsupported OIS model: %d", modecfg->model);
	}

	if(rc != FUNC_PASS) {
		CAM_ERR(CAM_OIS, "%s: FirmWare Download failed", o_ctrl->ois_name);
	}

	return firmware_ver;
}
