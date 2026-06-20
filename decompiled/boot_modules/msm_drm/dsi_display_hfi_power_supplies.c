__int64 __fastcall dsi_display_hfi_power_supplies(__int64 a1, int a2, char a3)
{
  unsigned int v5; // w21
  const char *v7; // x4

  if ( (a2 & 1) != 0 )
  {
    v5 = dsi_display_hfi_panel_enable_supplies(a1, a3 & 1);
    if ( v5 )
    {
      if ( (a3 & 1) != 0 )
        v7 = "enable";
      else
        v7 = "disable";
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] dsi panel power supply %s failed, rc=%d\n",
        *(const char **)(a1 + 32),
        v7,
        v5);
      if ( (a3 & 1) != 0 )
        dsi_display_hfi_panel_enable_supplies(a1, 0);
    }
  }
  else
  {
    v5 = 0;
  }
  _drm_dev_dbg(
    0,
    0,
    0,
    "[msm-dsi-debug]: %s: DSI core power, hfi_pwr_mask=%d, enable=%d\n",
    "dsi_display_hfi_power_supplies",
    a2,
    a3 & 1);
  return v5;
}
