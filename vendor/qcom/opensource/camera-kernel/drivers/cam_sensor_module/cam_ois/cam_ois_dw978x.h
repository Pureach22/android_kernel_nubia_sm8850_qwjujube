#ifndef _CAM_OIS_DW978X_H_
#define _CAM_OIS_DW978X_H_

#include <linux/cma.h>
#include "cam_ois_dev.h"

#define OIS_NAME_LEN            32
#define INVAILD_FW_VER          0xFFFFFF

/* dw9784 params */
#define DW9784_SLAVE_ADDR      0xE4
#define EXTRA_FIRMWARE_SIZE    512
#define NAME_PROG_SIZE         64

/* dw9785 params */
#define DW9785_SLAVE_ADDR      0x48
#define DW9785_MCS_SIZE_W      32256
#define FUNC_PASS              0
#define FUNC_FAIL              -1
#define ERROR_FW_ERASE         3
#define PROG_MEM_SEL           0x0020
#define ERROR_FW_DOWN_FMC      7
#define PKT_SIZE               32
#define MCS_START_ADDRESS      0x0000
#define ERROR_FW_CHECKSUM      6
#define AUTORD_RV_OK           0xFF00
#define FLASH_FW_CHECKSUM_OK   0x0007
#define FLASH_FW_CHECKSUM      0x0001
#define FLASH_DATA_X_CHECKSUM  0x0002
#define FLASH_PARAM_CHECKSUM   0x0004
#define ERROR_FLASH_CHECKSUM   10
#define LOOP                   30
#define WAIT_TIME              100
#define ERROR_RV_CHECKSUM      9
#define DW9785_CHIP_ID         0x9785

#define CHECK_RC(rc_val, log_msg, ...) \
	do { \
		if (rc_val) { \
			CAM_ERR(CAM_OIS, log_msg, ##__VA_ARGS__); \
			return rc_val; \
		} \
	} while (0)

#define CHECK_PTR(ptr1, ptr2, log_msg) \
	do { \
		if (!(ptr1) || !(ptr2)) { \
			CAM_ERR(CAM_OIS, log_msg); \
			return -EINVAL; \
		} \
	} while (0)

enum dw9785_extra_regs_index {
	mcu_enable_check = 0,
	wait_check_register,
	fw_slect,
	fw_addr_setting,
	fw_data_setting,
	area_erase = 5,
};

struct CameraOisParams
{
	const char*             SensorName;
	const char*             OISName;
	int32_t                 FWVersion;
	int32_t                 FWDate;
	struct ois_model_config *config;
};

extern struct CameraOisParams g_CameraOisParams[];
extern int g_CameraOisParamsCount;

// func
int cam_ois_dw978x_init(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg);

int cam_ois_dw978x_extra_init(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg);

int cam_ois_dw978x_reset(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg);

int dw9785_fw_wait_check_register(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg,
                                    uint16_t read_cycle, uint16_t wait_delay);

int cam_ois_dw9785_reset(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg);

int dw9785_fw_eflash_erase(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg);

int dw9785_fw_select(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg);

int dw9785_fw_checksum_check(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg);

int dw9785_write_ois_firmware(struct cam_ois_ctrl_t *o_ctrl, uint16_t *fireware);

uint32_t cam_ois_read_firmware_ver(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg);

int32_t dw978x_download_fw(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg, uint32_t *data);

int32_t dw9785_download_fw(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg, uint32_t *data);

uint32_t cam_ois_dw978x_firmware_download(struct cam_ois_ctrl_t *o_ctrl, struct ois_model_config *modecfg);

bool cam_ois_dw978x_need_update_fw(struct cam_ois_ctrl_t *o_ctrl);

#endif
/* _CAM_OIS_DW978X_H_ */
