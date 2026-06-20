__int64 __fastcall cnss_set_host_sol_value(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x8
  const char *v10; // x1
  __int16 v12; // w9
  const char *v13; // x8
  __int64 v14; // x0
  char vars0; // [xsp+0h] [xbp+0h]

  if ( (*(_DWORD *)(a1 + 148) & 0x80000000) != 0 )
    return 4294967274LL;
  if ( a2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
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
      "cnss_set_host_sol_value",
      7u,
      7u,
      "Assert host SOL GPIO\n",
      a7,
      a8,
      vars0);
  }
  v14 = gpio_to_desc();
  gpiod_set_raw_value(v14, a2);
  return 0;
}
