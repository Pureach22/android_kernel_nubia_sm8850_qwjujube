__int64 __fastcall dp_pll_configure(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  unsigned __int64 v4; // x8
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x22
  unsigned int v7; // w21
  __int64 v8; // x0
  int v9; // w2
  __int64 v12; // x0
  __int64 v13; // x0

  if ( a1 && a2 )
  {
    v3 = 1620000;
    v4 = 10 * a2;
    if ( (unsigned __int64)(10 * a2) >= 0x18B821 )
    {
      v3 = 2700000;
      if ( v4 >= 0x2932E1 )
      {
        if ( v4 <= 0x5265C0 )
          v3 = 5400000;
        else
          v3 = 8100000;
      }
    }
    *(_QWORD *)(a1 + 8) = v3;
    ipc_log_context = get_ipc_log_context();
    StatusReg = _ReadStatusReg(SP_EL0);
    ipc_log_string(ipc_log_context, "[d][%-4d]DP lane CLK rate=%ld\n", *(_DWORD *)(StatusReg + 1800), v3);
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]DP lane CLK rate=%ld\n", *(_DWORD *)(StatusReg + 1800), v3);
    v7 = dp_config_vco_rate_5nm(a1, v3);
    v8 = get_ipc_log_context();
    v9 = *(_DWORD *)(StatusReg + 1800);
    if ( (v7 & 0x80000000) != 0 )
    {
      ipc_log_string(v8, "[e][%-4d]Failed to set clk rate\n", v9);
      printk(&unk_215461, "dp_vco_set_rate_5nm");
      v13 = get_ipc_log_context();
      ipc_log_string(v13, "[e][%-4d]pll rate %lu set failed\n", *(_DWORD *)(StatusReg + 1800), v3);
      printk(&unk_21542C, "dp_pll_configure");
      *(_QWORD *)(a1 + 8) = 0;
      return v7;
    }
    else
    {
      ipc_log_string(v8, "[d][%-4d]pll rate %lu set success\n", v9, v3);
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]pll rate %lu set success\n", *(_DWORD *)(StatusReg + 1800), v3);
      return 0;
    }
  }
  else
  {
    v12 = get_ipc_log_context();
    ipc_log_string(
      v12,
      "[e][%-4d]invalid input parameters rate = %lu\n",
      *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800),
      a2);
    printk(&unk_234518, "dp_pll_configure");
    return 4294967274LL;
  }
}
