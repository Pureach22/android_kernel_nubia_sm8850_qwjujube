__int64 __fastcall dsi_panel_vm_trigger_esd_attack(__int64 a1)
{
  _DWORD *v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  unsigned int v5; // w19
  unsigned int v6; // w20
  __int64 v7; // x0
  int v8; // w6
  int v9; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = *(_DWORD **)(a1 + 1944);
  v3 = *(_QWORD *)(a1 + 1816);
  if ( *(v2 - 1) != -222936480 )
    __break(0x8228u);
  v4 = ((__int64 (__fastcall *)(__int64, const char *, _QWORD))v2)(v3, "qcom,platform-reset-gpio", 0);
  if ( (v4 & 0x80000000) != 0 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] reset gpio not provided\n", *(const char **)a1);
    return (unsigned int)-22;
  }
  else
  {
    v5 = v4;
    v6 = gpio_request(v4);
    if ( v6 )
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: request for reset_gpio failed, rc=%d\n", v6);
    }
    else
    {
      v7 = gpio_to_desc(v5);
      gpiod_set_raw_value(v7, 0);
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dsi_panel_trigger_esd_attack_sub",
        266,
        -1,
        13107,
        -1059143953,
        v8,
        v9,
        vars0);
      drm_dev_printk(0, &unk_2597DF, "[msm-dsi-info]: GPIO pulled low to simulate ESD\n");
      gpio_free(v5);
    }
  }
  return v6;
}
