__int64 __fastcall dsi_panel_pre_disable(const char **a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  unsigned int v4; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    v2 = *((unsigned int *)a1 + 385);
    if ( (v2 & 0x80000000) == 0 )
    {
      v3 = gpio_to_desc(v2);
      gpiod_set_raw_value(v3, 0);
    }
    v4 = dsi_panel_tx_cmd_set(a1, 5u, 0);
    if ( v4 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_PRE_OFF cmds, rc=%d\n",
        *a1,
        v4);
    mutex_unlock(a1 + 130);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return (unsigned int)-22;
  }
  return v4;
}
