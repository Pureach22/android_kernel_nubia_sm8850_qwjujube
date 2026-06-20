__int64 __fastcall dsi_panel_set_lp1(const char **a1)
{
  unsigned int v2; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 130);
    if ( *((_BYTE *)a1 + 1973) != 1 )
      goto LABEL_7;
    if ( *((_DWORD *)a1 + 557) == 1 && *((_DWORD *)a1 + 555) != 2 )
      dsi_pwr_panel_regulator_mode_set((__int64 *)a1 + 180, "ibb", 4u);
    if ( !*((_DWORD *)a1 + 559) )
    {
      v2 = dsi_panel_tx_cmd_set(a1, 0x10u, 0);
      if ( v2 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to send DSI_CMD_SET_LP1 cmd, rc=%d\n",
          *a1,
          v2);
    }
    else
    {
LABEL_7:
      v2 = 0;
    }
    mutex_unlock(a1 + 130);
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return (unsigned int)-22;
  }
  return v2;
}
