__int64 __fastcall dsi_display_hfi_register_pwr_supplies(__int64 a1)
{
  __int64 v1; // x19
  int v3; // w20
  _QWORD *cmd_buf; // x19
  unsigned int v5; // w19

  if ( a1 )
  {
    v1 = *(_QWORD *)(a1 + 1688);
    v3 = strcmp(*(const char **)(a1 + 40), "primary");
    cmd_buf = hfi_adapter_get_cmd_buf(*(_QWORD *)(v1 + 8));
    hfi_adapter_add_get_property((__int64)cmd_buf, 33554445, v3, 0, 0, 0, a1 + 1696, 6);
    v5 = hfi_adapter_set_cmd_buf((__int64)cmd_buf);
    sde_evtlog_log(sde_dbg_base_evtlog, "dsi_display_hfi_register_pwr_supplies", 413, -1, v3, 33554445, v5, 13107, 239);
    if ( v5 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: Could not send HFI_COMMAND_DISPLAY_POWER_REGISTER, rc=%d\n",
        v5);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid display\n");
    return (unsigned int)-22;
  }
  return v5;
}
