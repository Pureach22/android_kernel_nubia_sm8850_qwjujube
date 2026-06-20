__int64 __fastcall dsi_panel_trigger_esd_attack(__int64 a1)
{
  unsigned int v1; // w19
  unsigned int v3; // w19
  _DWORD *v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  int v7; // w6
  int v8; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid panel param\n");
    return (unsigned int)-22;
  }
  v1 = *(_DWORD *)(a1 + 1596);
  if ( !strcmp(*(const char **)(a1 + 8), "secondary") )
  {
    if ( (v1 & 0x80000000) != 0 )
    {
      v4 = *(_DWORD **)(a1 + 1944);
      v5 = *(_QWORD *)(a1 + 1816);
      if ( *(v4 - 1) != -222936480 )
        __break(0x8228u);
      v1 = ((__int64 (__fastcall *)(__int64, const char *, _QWORD))v4)(v5, "qcom,platform-reset-gpio", 0);
      if ( (v1 & 0x80000000) != 0 )
        goto LABEL_4;
    }
LABEL_10:
    v6 = gpio_to_desc(v1);
    gpiod_set_raw_value(v6, 0);
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_panel_trigger_esd_attack_sub", 266, -1, 13107, -1059143953, v7, v8, vars0);
    v3 = 0;
    drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: GPIO pulled low to simulate ESD\n");
    return v3;
  }
  if ( (v1 & 0x80000000) == 0 )
    goto LABEL_10;
LABEL_4:
  v3 = -22;
  drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: failed to pull down the reset gpio\n");
  return v3;
}
