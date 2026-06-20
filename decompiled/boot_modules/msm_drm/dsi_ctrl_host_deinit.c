__int64 __fastcall dsi_ctrl_host_deinit(__int64 a1)
{
  int v2; // w5
  unsigned int v3; // w20

  if ( a1 )
  {
    mutex_lock(a1 + 32);
    if ( *(_DWORD *)(a1 + 1608) != 1 )
    {
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "dsi_ctrl_check_state",
        535,
        -1,
        *(unsigned __int8 *)(a1 + 2584),
        *(_DWORD *)(a1 + 8),
        5,
        0,
        239);
      if ( (*(_BYTE *)(a1 + 1628) & 1) != 0 )
      {
        v2 = *(_DWORD *)(a1 + 1612);
        if ( v2 == 1 )
          goto LABEL_5;
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: State error: op=%d: %d\n",
          *(const char **)(a1 + 16),
          5,
          v2);
      }
      else
      {
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: %s: No change in state, host_init=%d\n",
          *(const char **)(a1 + 16),
          0);
      }
      v3 = -22;
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: Controller state check failed, rc=%d\n",
        *(const char **)(a1 + 16),
        -22);
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: %s: driver state check failed, rc=%d\n",
        *(const char **)(a1 + 16),
        -22);
      goto LABEL_10;
    }
LABEL_5:
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: Host deinitization complete\n", *(const char **)(a1 + 16));
    v3 = 0;
    *(_BYTE *)(a1 + 1628) = 0;
LABEL_10:
    mutex_unlock(a1 + 32);
    return v3;
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: %s: Invalid params\n", "inv");
  return (unsigned int)-22;
}
