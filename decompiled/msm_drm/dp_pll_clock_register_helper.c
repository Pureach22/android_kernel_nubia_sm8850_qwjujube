__int64 __fastcall dp_pll_clock_register_helper(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x20
  __int64 v4; // x21
  __int64 v5; // x22
  __int64 v7; // x23
  unsigned __int64 v8; // x0
  __int64 v10; // x0
  __int64 ipc_log_context; // x0
  int v12; // w21
  __int64 v13; // x22
  const char *name; // x0

  if ( a1 && (v3 = a2) != 0 )
  {
    if ( a3 < 1 )
    {
      return 0;
    }
    else
    {
      v4 = *(_QWORD *)(a1 + 312);
      v5 = 8LL * (unsigned int)a3;
      v7 = 0;
      while ( 1 )
      {
        *(_QWORD *)(v3 + 24) = a1;
        v8 = clk_register(v4 + 16, v3);
        if ( v8 >= 0xFFFFFFFFFFFFF001LL )
          break;
        v3 += 120;
        *(_QWORD *)(**(_QWORD **)(a1 + 384) + v7) = v8;
        v7 += 8;
        if ( v5 == v7 )
          return 0;
      }
      ipc_log_context = get_ipc_log_context();
      v12 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800);
      v13 = ipc_log_context;
      name = (const char *)clk_hw_get_name(v3);
      ipc_log_string(v13, "[e][%-4d]%s registration failed for DP: %d\n", v12, name, *(_DWORD *)(a1 + 16));
      clk_hw_get_name(v3);
      printk(&unk_252E70, "dp_pll_clock_register_helper");
      return 4294967274LL;
    }
  }
  else
  {
    v10 = get_ipc_log_context();
    ipc_log_string(v10, "[e][%-4d]input not initialized\n", *(_DWORD *)(_ReadStatusReg(SP_EL0) + 1800));
    printk(&unk_261853, "dp_pll_clock_register_helper");
    return 4294967274LL;
  }
}
