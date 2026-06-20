/***************************************************************
** Copyright (C), 2023, ZTE Mobile Comm Corp., Ltd
**
** File : zte_panel_backlight.c
** Description : ZTE display panel
** Version : 1.0
** Date : 2023/08
** Author : Display
******************************************************************/
#include "zte_disp_panel.h"
#include "zte_disp_panel_info.h"
#include "zte_lcd_reg_debug.h"
#include "zte_disp_work.h"
#ifdef CONFIG_ZTE_LCD_ZLOG
#include "zte_disp_zlog.h"
#endif

LCD_PROC_FILE_DEFINE(zte_lcd_hbm, ZTE_LCD_HBM_CTRL)
LCD_PROC_FILE_DEFINE(zte_lcd_aod_bl, ZTE_LCD_AOD_BL)
LCD_PROC_FILE_DEFINE(zte_lcd_color_gamut, ZTE_LCD_COLOR_GAMUT_CTRL)
LCD_PROC_FILE_DEFINE(zte_lcd_acl, ZTE_LCD_ACL_CTRL)
LCD_PROC_FILE_DEFINE(zte_lcd_cur_fps, ZTE_LCD_FPS_CTRL)
LCD_PROC_FILE_DEFINE(zte_panel_state, ZTE_LCD_STATE_CTRL)
LCD_PROC_FILE_DEFINE(zte_lcd_bl_limit, ZTE_LCD_BL_LIMIT)
LCD_PROC_FILE_DEFINE(zte_lcd_local_hbm, ZTE_LCD_LOCAL_HBM_CTRL)
LCD_PROC_FILE_DEFINE(zte_lcd_temp_debug, ZTE_LCD_TEMP_DEBUG)
#ifdef CONFIG_DRM_ZTE_DISP_LTM
LCD_PROC_FILE_DEFINE(zte_lcd_ltm_sensor_bl, ZTE_LCD_LTM_SENSOR_BL)
#endif

static void dsi_panel_parse_feature_config(struct dsi_panel *panel)
{
	struct dsi_parser_utils *utils = &panel->utils;
    zte_panel_state_init(panel);
    zte_lcd_temp_debug_init(panel);

    if (utils->read_bool(utils->data, "zte,hbm_enabled"))
        zte_lcd_hbm_init(panel);

    if (utils->read_bool(utils->data, "zte,aod_enabled"))
        zte_lcd_aod_bl_init(panel);

    if (utils->read_bool(utils->data, "zte,fps_enabled"))
        zte_lcd_cur_fps_init(panel);

    if (utils->read_bool(utils->data, "zte,color_space_enabled"))
        zte_lcd_color_gamut_init(panel);

    if (utils->read_bool(utils->data, "zte,acl_enabled"))
        zte_lcd_acl_init(panel);

    if (utils->read_bool(utils->data, "zte,bl_limit_enabled"))
        zte_lcd_bl_limit_init(panel);

    if (utils->read_bool(utils->data, "zte,local_hbm_enabled"))
        zte_lcd_local_hbm_init(panel);
}

static void dsi_panel_parse_config(struct dsi_panel *panel)
{
    int rc = 0;
    struct dsi_parser_utils *utils = &panel->utils;

    rc = utils->read_u32(utils->data, "zte,te-high-width", &panel->vsync_width);
    if (rc)
		panel->vsync_width = 0;
    
    rc = utils->read_u32(utils->data, "zte,dim-delay", &panel->dim_delay);
    if (rc)
		panel->dim_delay = 20; //default value 20ms

    rc = utils->read_u32(utils->data, "zte,bl-normalmax-level", &panel->bl_normalmax_level);
    if (rc)
		panel->bl_normalmax_level = 0;
}


void zte_disp_common_func(struct dsi_panel *panel)
{
    int id;

    if (!panel) {
        pr_info("MSM_LCD No panel device\n");
  		return;
    }

    panel->disp_feature = kcalloc(ZTE_LCD_MAX_CTRL, sizeof(struct zte_disp_feature), GFP_KERNEL);
    if (!panel->disp_feature) {
  		pr_err("%s: %d MSM_LCD kzalloc memory failed\n", __func__, __LINE__);
  		return;
  	}

    for (id = 0; id < ZTE_LCD_MAX_CTRL; id++) {
        panel->disp_feature[id].fname = feature_name[id];
        panel->disp_feature[id].mode = 0;
        panel->disp_feature[id].panel_must_init = true;
        panel->disp_feature[id].writeable = true;
        panel->disp_feature[id].logable = true;

        if (id == ZTE_LCD_COLOR_GAMUT_CTRL){
            panel->disp_feature[id].panel_must_init = false;
        } else if (id == ZTE_LCD_FPS_CTRL) {
            panel->disp_feature[id].mode = 60;
            panel->disp_feature[id].writeable = false;
        } else if (id == ZTE_LCD_ACL_CTRL) {
            panel->disp_feature[id].panel_must_init = false;
        } else if (id == ZTE_LCD_AOD_BL) {
            panel->disp_feature[id].mode = 1;
            panel->disp_feature[id].panel_must_init = false;
        } else if (id == ZTE_LCD_STATE_CTRL) {
            panel->disp_feature[id].writeable = false;
        } else if (id == ZTE_LCD_BL_LIMIT) {
            panel->disp_feature[id].mode = panel->bl_config.brightness_max_level;
            panel->disp_feature[id].panel_must_init = false;
        } else if (id == ZTE_LCD_SET_SYNC_BL) {
        #ifdef ZTE_FEATURE_PV_AR
            panel->disp_feature[id].logable = true;
        #else
            panel->disp_feature[id].logable = false;
        #endif
        } else if (id == ZTE_LCD_TEMP_DEBUG) {
            panel->disp_feature[id].panel_must_init = false;
        }
    #ifdef CONFIG_DRM_ZTE_DISP_LTM
        else if (id == ZTE_LCD_LTM_SENSOR_BL) {
            panel->disp_feature[id].panel_must_init = false;
        }
    #endif
    }

    load_panel_info(panel);

    dsi_panel_parse_feature_config(panel);
    dsi_panel_parse_config(panel);
    zte_lcd_reg_debug_func(panel);

#ifdef CONFIG_ZTE_LCD_ZLOG
    zte_zlog_lcd_client_init(panel);
#endif
#ifdef CONFIG_DRM_ZTE_DISP_LTM
    zte_lcd_ltm_sensor_bl_init(panel);
#endif

    INIT_DELAYED_WORK(&panel->dim_work, dimming_work_handler);
    panel->dim_workq = create_singlethread_workqueue("panel_dim_workq");

    INIT_WORK(&panel->rebl_work, setting_bl_work_handler);
    panel->rebl_workq = create_singlethread_workqueue("panel_rebl_workq");

    INIT_WORK(&panel->aodbl_work, setting_aodbl_work_handler);
    panel->aodbl_workq = create_singlethread_workqueue("panel_aodbl_workq");

    INIT_WORK(&panel->nolp_work, setting_nolp_work_handler);
    panel->nolp_workq = create_singlethread_workqueue("panel_nolp_workq");
}