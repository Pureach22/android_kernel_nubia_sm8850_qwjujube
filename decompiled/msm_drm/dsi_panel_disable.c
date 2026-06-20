__int64 __fastcall dsi_panel_disable(__int64 a1)
{
  __int64 v2; // x9

  if ( a1 )
  {
    mutex_lock(a1 + 1040);
    if ( !*(_DWORD *)(a1 + 1968) )
    {
      if ( *(_DWORD *)(a1 + 2228) == 1 && (unsigned int)(*(_DWORD *)(a1 + 2220) - 1) <= 1 )
        dsi_pwr_panel_regulator_mode_set((__int64 *)(a1 + 1440), "ibb", 8u);
      if ( (unsigned int)dsi_panel_tx_cmd_set((const char **)a1, 6u, 0) )
      {
        if ( (unsigned int)__ratelimit(&dsi_panel_disable__rs, "dsi_panel_disable") )
          printk(&unk_267367, *(_QWORD *)a1);
      }
    }
    v2 = *(_QWORD *)(a1 + 2312);
    *(_BYTE *)(a1 + 1973) = 0;
    *(_DWORD *)(a1 + 2220) = 5;
    *(_DWORD *)(a1 + 2324) = 0;
    *(_DWORD *)(v2 + 120) = 0;
    *(_DWORD *)(*(_QWORD *)(a1 + 2312) + 168LL) = 0;
    mutex_unlock(a1 + 1040);
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
    return 4294967274LL;
  }
}
