__int64 __fastcall dsi_display_splash_res_cleanup(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w20
  __int64 v4; // x0
  int v5; // w7
  char vars0; // [xsp+0h] [xbp+0h]

  if ( *(_BYTE *)(a1 + 64) == 1 )
  {
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 264) + 2024LL) == 1 && *(_DWORD *)(a1 + 888) == 1 )
    {
      v2 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1328), 4, 0);
      if ( v2 )
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI link clocks, rc=%d\n",
          *(const char **)(a1 + 32),
          v2);
    }
    v3 = dsi_display_clk_ctrl(*(_QWORD *)(a1 + 1320), 3, 0);
    if ( v3 )
      drm_dev_printk(
        0,
        &unk_248D72,
        "*ERROR* [msm-dsi-error]: [%s] failed to disable DSI link clocks, rc=%d\n",
        *(const char **)(a1 + 32),
        v3);
    _pm_runtime_idle(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), 4);
    v4 = *(_QWORD *)(a1 + 1312);
    *(_BYTE *)(a1 + 64) = 0;
    dsi_display_clk_mngr_update_splash_status(v4, 0);
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "dsi_display_splash_res_cleanup",
      5928,
      -1,
      8738,
      *(unsigned __int8 *)(a1 + 64),
      -1059143953,
      v5,
      vars0);
  }
  else
  {
    return 0;
  }
  return v3;
}
