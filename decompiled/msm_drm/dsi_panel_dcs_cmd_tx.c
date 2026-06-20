__int64 __fastcall dsi_panel_dcs_cmd_tx(const char **a1, unsigned int a2)
{
  unsigned int v4; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    v4 = dsi_panel_tx_cmd_set(a1, a2, 0);
    if ( v4 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to send cmds %d, rc=%d\n", *a1, a2, v4);
    mutex_unlock(a1 + 130);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Invalid params\n");
    return (unsigned int)-22;
  }
  return v4;
}
