/***************************************************************
** Copyright (C), 2023, ZTE Mobile Comm Corp., Ltd
**
** File : zte_panel_backlight.c
** Description : ZTE display panel
** Version : 1.0
** Date : 2023/08
** Author : Display
******************************************************************/
void dimming_work_handler(struct work_struct *work);

void zte_aod_handler(struct dsi_panel *panel, u32 msg);
void zte_fod_handler(struct dsi_panel *panel, u32 msg);
void setting_bl_work_handler(struct work_struct *work);
void setting_aodbl_work_handler(struct work_struct *work);
void setting_nolp_work_handler(struct work_struct *work);
