/***************************************************************
** Copyright (C), 2023, ZTE Mobile Comm Corp., Ltd
**
** File : zte_panel_backlight.c
** Description : ZTE display panel
** Version : 1.0
** Date : 2023/08
** Author : Display
******************************************************************/
#include <drm/drm_mipi_dsi.h>
#include "../dsi/dsi_display.h"
#include "../sde/sde_encoder.h"
#include "zte_disp_backlight.h"

bool apply_dim(struct dsi_panel *panel) {
    //s64 diff = 0;
    //s64 us_per_frame = 0;

    if (panel->disp_feature[ZTE_LCD_HBM_CTRL].mode)
        return false;
    
    /*if ((panel->layer_flag & ZTE_LAYER_DIM) > 0)
        return false;
    
    diff = ktime_to_us(ktime_sub(ktime_get(), panel->hbm_off_timestamp));    
    us_per_frame = 1000000 / (panel->cur_mode->timing.refresh_rate);    
    if (diff <= us_per_frame)
        return false;
	*/

    return true;
}

void dsi_panel_dim_handle(struct dsi_panel *panel, bool en, bool skip_cmds, bool need_dim_delay) {
    static bool last_en = false;

    if (en == last_en)
        return;

    if (!panel)
        return;

    if (!en)
        goto exit;

    if ((panel->power_mode == SDE_MODE_DPMS_LP1 || panel->power_mode == SDE_MODE_DPMS_LP2))
        return;

    if (!apply_dim(panel)) {
        pr_info("[MSM_LCD] wait next bl to restore dim!\n");
        return;
    }

exit:
    panel->set_dim = en ? 1 : 0;
    if (!skip_cmds) {
		if (need_dim_delay)
			queue_delayed_work(panel->dim_workq, &panel->dim_work, msecs_to_jiffies(panel->dim_delay));
		else
			queue_delayed_work(panel->dim_workq, &panel->dim_work, 0);
	}
    last_en = en;
}

int zte_dsi_panel_update_backlight(struct dsi_panel *panel,
	u32 bl_lvl)
{
	int rc = 0;
	unsigned long mode_flags = 0;
	struct mipi_dsi_device *dsi = NULL;
	static u32 last_brightness = 0;
	static u32 last_fps = 0;

	if (!panel || (bl_lvl > 0xffff)) {
		DSI_ERR("invalid params\n");
		return -EINVAL;
	}

    pr_info("MSM_LCD backlight = %d\n", bl_lvl);

	if (bl_lvl > 0) {
		if ((panel->aod_layer && !panel->fod_layer) || (panel->power_mode == SDE_MODE_DPMS_LP1 || panel->power_mode == SDE_MODE_DPMS_LP2)) {
			pr_info("MSM_LCD backlight donot set pm %d,fod_layer=%d,aod_layer=%d\n", panel->power_mode, panel->fod_layer, panel->aod_layer);
			goto exit;
		}

        if (panel->disp_feature[ZTE_LCD_FPS_CTRL].mode != last_fps) {
			if (last_brightness == bl_lvl) {
				pr_info("MSM_LCD backlight donot set when panel fps change\n");
				goto exit;
			}
		}
	}

	dsi = &panel->mipi_device;

	if (unlikely(panel->bl_config.lp_mode)) {
		mode_flags = dsi->mode_flags;
		dsi->mode_flags |= MIPI_DSI_MODE_LPM;
	}

	if (panel->bl_config.bl_inverted_dbv)
		bl_lvl = (((bl_lvl & 0xff) << 8) | (bl_lvl >> 8));

	rc = mipi_dsi_dcs_set_display_brightness(dsi, bl_lvl);
	if (rc < 0)
		DSI_ERR("failed to update dcs backlight:%d\n", bl_lvl);

	if (unlikely(panel->bl_config.lp_mode))
		dsi->mode_flags = mode_flags;

    if (panel->bl_config.bl_inverted_dbv)
		bl_lvl = (((bl_lvl & 0xff) << 8) | (bl_lvl >> 8));

	dsi_panel_dim_handle(panel, bl_lvl > 0, false, true);
	panel->has_bl = (bl_lvl > 0) ? true: false;
exit:
    last_fps = panel->disp_feature[ZTE_LCD_FPS_CTRL].mode;
	last_brightness = bl_lvl;
    panel->cur_bl = bl_lvl;
	return rc;
}