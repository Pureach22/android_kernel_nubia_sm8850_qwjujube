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
#include "zte_disp_work.h"

typedef enum {
    WORK_REBL,
    WORK_AODBL,
    WORK_MAX
} work_type_t;

char *work2string[WORK_MAX] = {
    "WORK_REBL",
    "WORK_AODBL",
};

char *aod2string[AOD_MAX] = {
  "AOD_NONE",
  "FRAME_AOD_ACTIVE",
  "FRAME_AOD_MISS",
  "PM_AOD_ON",
  "PM_AOD_OFF",
};

char *aodstate[AOD_STATE_MAX] = {
    "AOD_STATE_INACTIVE",
    "AOD_STATE_FRAME_ONLY",
    "AOD_STATE_PM_ONLY",
    "AOD_STATE_BOTH_ACTIVE",
};

void zte_schedule_work(struct dsi_panel *panel, work_type_t type, bool en, bool force) {
    bool *pending_flag;
    struct work_struct *work;
    struct workqueue_struct *wq;

    switch (type) {
        case WORK_REBL:
            pending_flag = &panel->pending_rebl;
            work = &panel->rebl_work;
            wq = panel->rebl_workq;
            break;
        case WORK_AODBL:
            pending_flag = &panel->pending_aodbl;
            work = &panel->aodbl_work;
            wq = panel->aodbl_workq;
            break;
        default: return;
    }

    pr_info("[MSM_LCD] type %s status [%d, %d]\n", work2string[type], en, *pending_flag);

    if ((type == WORK_REBL) && (en == *pending_flag) && (en == false)) return;

    if (en) {
        if (type == WORK_AODBL && panel->drm_aod_bl == 0) {
            panel->drm_aod_bl = 2;
        }
        queue_work(wq, work);
        *pending_flag = true;
    } else {
        *pending_flag = false;
    }
}

void dimming_work_handler(struct work_struct *work)
{
	struct delayed_work *dwork = to_delayed_work(work);
	struct dsi_panel *panel = container_of(dwork,
  				struct dsi_panel, dim_work);

	if (!panel) {
		pr_err("MSM_LCD no primary panel device\n");
		goto exit;
	}
    zte_set_disp_parameter(panel, ZTE_LCD_DIM_CTRL, panel->set_dim, false);

exit:
    return;
}

void setting_bl_work_handler(struct work_struct *work)
{
	struct dsi_panel *panel = container_of(work,
				struct dsi_panel, rebl_work);

	if (!panel) {
		pr_err("MSM_LCD no primary panel device\n");
		goto exit;
	}

    pr_info("[MSM_LCD] set bl %d\n", panel->cur_bl);

	if (panel->cur_bl) {
		zte_set_disp_parameter(panel, ZTE_LCD_SET_BL, panel->cur_bl, false);
	}

exit:
    return;
}

void setting_aodbl_work_handler(struct work_struct *work)
{
	struct dsi_panel *panel = container_of(work,
				struct dsi_panel, aodbl_work);

	if (!panel) {
		pr_err("MSM_LCD no primary panel device\n");
		goto exit;
	}
    pr_info("[MSM_LCD] set aodbl %d\n", panel->drm_aod_bl);
    if (panel->drm_aod_bl > 0) {
        zte_set_disp_parameter(panel, ZTE_LCD_AOD_BL, panel->drm_aod_bl, false);
    }

exit:
    return;
}

void setting_nolp_work_handler(struct work_struct *work)
{
	struct dsi_panel *panel = container_of(work,
				struct dsi_panel, nolp_work);

	if (!panel) {
		pr_err("MSM_LCD no primary panel device\n");
		goto exit;
	}

    dsi_panel_set_nolp(panel);
    zte_aod_handler(panel, PM_AOD_OFF);

exit:
    return;
}

void zte_aod_handler(struct dsi_panel *panel, u32 msg) {
    aod_state_t prev_state = panel->aod_state;
    switch (msg) {
        case FRAME_AOD_ACTIVE:
            panel->aod_state = (panel->aod_state == AOD_STATE_PM_ONLY || panel->aod_state == AOD_STATE_BOTH_ACTIVE) ?
                        AOD_STATE_BOTH_ACTIVE : AOD_STATE_FRAME_ONLY;
            break;
        case FRAME_AOD_MISS:
            panel->aod_state = (panel->aod_state == AOD_STATE_BOTH_ACTIVE) ?
                        AOD_STATE_PM_ONLY : AOD_STATE_INACTIVE;
            break;
        case PM_AOD_ON:
            panel->aod_state = (panel->aod_state == AOD_STATE_FRAME_ONLY) ?
                        AOD_STATE_BOTH_ACTIVE : AOD_STATE_PM_ONLY;
            break;
        case PM_AOD_OFF:
            panel->aod_state = (panel->aod_state == AOD_STATE_BOTH_ACTIVE) ?
                        AOD_STATE_FRAME_ONLY : AOD_STATE_INACTIVE;
            break;
        default: return;
    }
    pr_info("[MSM_LCD] AOD panel->State: %s -> %s (Msg: %s)\n",
                aodstate[prev_state], aodstate[panel->aod_state], aod2string[msg]);

    const bool need_rebl = (panel->aod_state == AOD_STATE_INACTIVE);
    const bool need_aodbl = (panel->aod_state == AOD_STATE_BOTH_ACTIVE || (msg == PM_AOD_ON && panel->aod_layer));
    pr_info("[MSM_LCD] need_rebl %d need_aodbl %d\n", need_rebl, need_aodbl);

    if (need_rebl) {
        if (panel->cur_bl > 0) {
           zte_schedule_work(panel, WORK_REBL, need_rebl, true);
        }
    } else {
        zte_schedule_work(panel, WORK_REBL, need_rebl, false);
    }

    zte_schedule_work(panel, WORK_AODBL, need_aodbl, false);
}

void zte_fod_handler(struct dsi_panel *panel, u32 msg) {
    pr_info("MSM_LCD msg %d has_bl = %d\n", msg, panel->has_bl);
    if (msg == FOD_ACTIVE) {
        if (!panel->has_bl) {
            if ((panel->power_mode == SDE_MODE_DPMS_LP1) ||
			    (panel->power_mode == SDE_MODE_DPMS_LP2)) {
                panel->skip_nolp = true;
                queue_work(panel->nolp_workq, &panel->nolp_work);
            }
            if (panel->cur_bl > 0)
                zte_schedule_work(panel, WORK_REBL, true, false);
        }
    }
}