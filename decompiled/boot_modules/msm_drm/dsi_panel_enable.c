__int64 __fastcall dsi_panel_enable(const char **a1)
{
  unsigned int v2; // w0
  unsigned int v3; // w20
  int v4; // w8
  unsigned int v5; // w0
  unsigned int v6; // w0

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    v2 = dsi_panel_tx_cmd_set(a1, 1u, 0);
    if ( v2 )
    {
      v3 = v2;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_ON cmds, rc=%d\n",
        *a1,
        v2);
      goto LABEL_13;
    }
    v4 = *((_DWORD *)a1 + 338);
    if ( v4 == 1 )
    {
      v6 = dsi_panel_tx_cmd_set(a1, 2u, 0);
      if ( v6 )
      {
        v3 = v6;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_VID_ON cmds, rc=%d\n",
          *a1,
          v6);
        goto LABEL_13;
      }
    }
    else if ( v4 == 2 )
    {
      v5 = dsi_panel_tx_cmd_set(a1, 3u, 0);
      if ( v5 )
      {
        v3 = v5;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_CMD_ON cmds, rc=%d\n",
          *a1,
          v5);
LABEL_13:
        mutex_unlock(a1 + 130);
        return v3;
      }
    }
    v3 = 0;
    *((_BYTE *)a1 + 1973) = 1;
    goto LABEL_13;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
  return (unsigned int)-22;
}
