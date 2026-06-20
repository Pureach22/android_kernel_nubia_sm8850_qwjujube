__int64 __fastcall dsi_panel_unprepare(const char **a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    v2 = dsi_panel_tx_cmd_set(a1, 7u, 0);
    if ( v2 )
    {
      v3 = v2;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_POST_OFF cmds, rc=%d\n",
        *a1,
        v2);
    }
    else if ( *((_BYTE *)a1 + 2232) == 1 )
    {
      v3 = dsi_panel_post_pwr_ctrl(a1, 0);
      if ( v3 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] panel power off post vregs failed, rc=%d\n",
          *a1,
          v3);
    }
    else
    {
      v3 = 0;
    }
    mutex_unlock(a1 + 130);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return (unsigned int)-22;
  }
  return v3;
}
