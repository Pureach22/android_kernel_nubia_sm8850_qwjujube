/***************************************************************
** Copyright (C), 2023, ZTE Mobile Comm Corp., Ltd
**
** File : zte_panel_backlight.c
** Description : ZTE display panel
** Version : 1.0
** Date : 2023/08
** Author : Display
******************************************************************/
#include "zte_disp_feature.h"
#include "zte_disp_backlight.h"
int zte_set_disp_parameter(struct dsi_panel *panel, u32 feature, u32 feature_mode, bool from_node)
{
    int rc = 0;
    struct dsi_display_mode_priv_info *priv_info;
    struct dsi_cmd_desc *cmds = NULL;
    u8 *tx_buf;
    u32 count;

    if (!panel) {
        pr_info("[MSM_LCD] No panel device\n");
        return -EINVAL;
    }

    if (panel->cur_mode)
        priv_info = panel->cur_mode->priv_info;
    else
        priv_info = NULL;

    if (!panel->disp_feature[feature].writeable) {
        pr_info("[MSM_LCD] %s is not writeable!\n", panel->disp_feature[feature].fname);
        return rc;
    }

    if (!panel->disp_feature[feature].panel_must_init) {
        panel->disp_feature[feature].mode = feature_mode;
    }

    if (panel->disp_feature[feature].logable)
        pr_info("[MSM_LCD] set [%s, %d]!\n", panel->disp_feature[feature].fname, feature_mode);

    mutex_lock(&panel->panel_lock);

    if (!panel->panel_initialized){
        pr_err("[MSM_LCD] skip when panel is not init!");
        goto exit;
    }

    switch(feature) {
        case ZTE_LCD_HBM_CTRL:

            break;
        case ZTE_LCD_ACL_CTRL:
            rc = zte_dsi_panel_tx_cmd_set(panel, DSI_CMD_SET_ZTE_ACL_OFF + feature_mode);
            break;
        case ZTE_LCD_AOD_BL:
            rc = zte_dsi_panel_tx_cmd_set(panel, DSI_CMD_SET_ZTE_AOD_LOW + feature_mode - 1);
            break;
        case ZTE_LCD_BL_LIMIT:
            break;
        case ZTE_LCD_DIM_CTRL:
            if (feature_mode != panel->disp_feature[feature].mode) {
                rc = zte_dsi_panel_tx_cmd_set(panel, DSI_CMD_SET_ZTE_DIM_OFF + feature_mode);
                panel->disp_feature[feature].mode = feature_mode;
            }
            break;
        case ZTE_LCD_SET_BL:
        case ZTE_LCD_SET_SYNC_BL:
            if (priv_info) {
                count = priv_info->cmd_sets[DSI_CMD_SET_ZTE_BL].count;
                cmds = priv_info->cmd_sets[DSI_CMD_SET_ZTE_BL].cmds;
                if (cmds && count >= 1) {
                    tx_buf = (u8 *)cmds[count-1].msg.tx_buf;
                    if (tx_buf && tx_buf[0] == 0x51) {
                        tx_buf[1] = feature_mode >> 8;
                        tx_buf[2] = feature_mode & 0xff;
                    #ifdef ZTE_FEATURE_PV_AR
                        if (feature == ZTE_LCD_SET_BL || feature == ZTE_LCD_SET_SYNC_BL)
                            pr_info("[MSM_LCD] LCD_PV DSI_CMD_SET_ZTE_BL 0x%02X=0x%02X 0x%02X\n", tx_buf[0], tx_buf[1], tx_buf[2]);
                    #else
                        if (feature == ZTE_LCD_SET_BL)
                            pr_info("[MSM_LCD] DSI_CMD_SET_ZTE_BL 0x%02X = 0x%02X 0x%02X\n",tx_buf[0], tx_buf[1], tx_buf[2]);
                    #endif
                    }
                }
            }
            priv_info->cmd_sets[DSI_CMD_SET_ZTE_BL].logable = feature == ZTE_LCD_SET_BL ? true : false;
            rc = zte_dsi_panel_tx_cmd_set(panel, DSI_CMD_SET_ZTE_BL);
            panel->has_bl = true;
            break;
        case ZTE_LCD_LOCAL_HBM_CTRL:
            rc = zte_dsi_panel_tx_cmd_set(panel, DSI_CMD_SET_ZTE_LOCAL_HBM_OFF + feature_mode);
            break;
        default:
            break;
    }

exit:
    mutex_unlock(&panel->panel_lock);
    return rc;
}

char *msg[5] = {
	"LCD_FPS=60",
	"LCD_FPS=90",
	"LCD_FPS=120",
	"LCD_FPS=144",
	"LCD_FPS=165",
};

int get_index(int mode) {
	int id = 0;

	if (mode == 90) {
		id = 1;
	} else if (mode == 120) {
		id = 2;
	} else if (mode == 144) {
		id = 3;
	} else if (mode == 165) {
		id = 4;
	}

	return id + MSG_FPS;
}

void zte_panel_send_uevent(int type, int mode, int ret)
{
	char *envp[3];
	struct device *dev= get_disp_dev();

	if (!dev)
		return;

	switch(type) {
		case MSG_FPS:
			envp[0] = msg[get_index(mode)];
			envp[1] = NULL;
			break;
		default:
			break;
	}
    
	envp[2] = NULL;
	kobject_uevent_env(&dev->kobj, KOBJ_CHANGE, envp);

	if (type == MSG_FPS) {
		pr_info("[MSM_LCD] uevent = %s\n", envp[0]);
	}
}