__int64 __fastcall cnss_clk_off_single(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x9
  int v9; // w10
  const char *v10; // x1
  const char *v11; // x1
  __int16 v12; // w10
  const char *v13; // x9
  __int64 v15; // x19
  __int64 result; // x0
  __int16 v17; // w10
  const char *v18; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v9 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( *(_DWORD *)(a1 + 40) )
  {
    if ( v9 )
    {
      v10 = "irq";
    }
    else
    {
      v12 = *(_DWORD *)(StatusReg + 16);
      v13 = (const char *)(StatusReg + 2320);
      if ( (v12 & 0xFF00) != 0 )
        v10 = "soft_irq";
      else
        v10 = v13;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v10,
      "cnss_clk_off_single",
      7u,
      7u,
      "Clock %s is being disabled\n",
      *(_QWORD *)(a1 + 24),
      a8,
      vars0);
    v15 = *(_QWORD *)(a1 + 16);
    clk_disable(v15);
    result = clk_unprepare(v15);
    *(_DWORD *)(a1 + 40) = 0;
  }
  else
  {
    if ( v9 )
    {
      v11 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v18;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v11,
             "cnss_clk_off_single",
             7u,
             7u,
             "Clock %s is already disabled\n",
             *(_QWORD *)(a1 + 24),
             a8,
             vars0);
  }
  return result;
}
