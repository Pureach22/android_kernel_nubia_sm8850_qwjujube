__int64 __fastcall dsi_panel_switch(const char **a1)
{
  unsigned int v2; // w19

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    v2 = dsi_panel_tx_cmd_set(a1, 0x15u, 0);
    if ( v2 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_TIMING_SWITCH cmds, rc=%d\n",
        *a1,
        v2);
    mutex_unlock(a1 + 130);
    zte_panel_send_uevent(0, *((unsigned int *)a1[289] + 10), 1);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  return v2;
}
