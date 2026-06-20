__int64 __fastcall dsi_panel_post_enable(const char **a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    if ( *((_BYTE *)a1 + 2232) == 1 && (v2 = dsi_panel_post_pwr_ctrl(a1, 1)) != 0 )
    {
      v3 = v2;
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] power on post vregs failed, rc=%d\n", *a1, v2);
    }
    else
    {
      v3 = dsi_panel_tx_cmd_set(a1, 4u, 0);
      if ( v3 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_POST_ON cmds, rc=%d\n",
          *a1,
          v3);
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
