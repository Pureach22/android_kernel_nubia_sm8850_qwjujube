__int64 __fastcall dsi_panel_switch_video_mode_out(const char **a1)
{
  unsigned int v2; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    v2 = dsi_panel_tx_cmd_set(a1, 0xCu, 0);
    if ( v2 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_VID_SWITCH_OUT cmds, rc=%d\n",
        *a1,
        v2);
    mutex_unlock(a1 + 130);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  return v2;
}
