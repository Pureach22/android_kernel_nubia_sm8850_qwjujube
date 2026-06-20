__int64 __fastcall dsi_conn_set_dyn_bit_clk(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        int a7,
        int a8)
{
  __int64 v8; // x19
  size_t v9; // x0
  char v11; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    v8 = *(_QWORD *)(a1 + 2760);
    v9 = sde_dbg_base_evtlog;
    *(_DWORD *)(v8 + 852) = a2;
    *(_BYTE *)(v8 + 856) = 1;
    sde_evtlog_log(v9, "dsi_conn_set_dyn_bit_clk", 1624, -1, a2, -1059143953, a7, a8, v11);
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: update dynamic bit clock rate to %u\n", *(_DWORD *)(v8 + 852));
    return 0;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid connector\n");
    return 4294967274LL;
  }
}
