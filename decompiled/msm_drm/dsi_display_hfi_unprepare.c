__int64 __fastcall dsi_display_hfi_unprepare(__int64 a1)
{
  unsigned int v2; // w19

  if ( a1 )
  {
    v2 = dsi_display_hfi_panel_enable_supplies(a1, 0);
    if ( v2 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] dsi panel power supply %s failed, rc=%d\n",
        *(const char **)(a1 + 32),
        "disable",
        v2);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    v2 = 0;
  }
  _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: DSI core power, enable=%d\n", "dsi_display_hfi_unprepare", 0);
  return v2;
}
