__int64 __fastcall dsi_panel_send_qsync_on_dcs(const char **a1, int a2)
{
  unsigned int v4; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: ctrl:%d qsync on\n", a2);
    v4 = dsi_panel_tx_cmd_set(a1, 0x17u, 0);
    if ( v4 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_QSYNC_ON cmds rc=%d\n",
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
