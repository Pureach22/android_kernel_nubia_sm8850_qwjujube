__int64 __fastcall cnss_power_down(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x9
  int v6; // w10
  __int64 v7; // x19
  const char *v8; // x1
  const char *v9; // x1
  __int16 v10; // w10
  const char *v11; // x9
  __int16 v13; // w10
  const char *v14; // x9
  char v15; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  StatusReg = _ReadStatusReg(SP_EL0);
  v6 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( v2 )
  {
    v7 = v2;
    if ( v6 )
    {
      v8 = "irq";
    }
    else
    {
      v10 = *(_DWORD *)(StatusReg + 16);
      v11 = (const char *)(StatusReg + 2320);
      if ( (v10 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v11;
    }
    cnss_debug_ipc_log_print(cnss_ipc_log_context, v8, "cnss_power_down", 7u, 7u, "Powering down device\n", v3, v4, v15);
    return cnss_driver_event_post(v7, 0xCu, 1, 0);
  }
  else
  {
    if ( v6 )
    {
      v9 = "irq";
    }
    else
    {
      v13 = *(_DWORD *)(StatusReg + 16);
      v14 = (const char *)(StatusReg + 2320);
      if ( (v13 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v14;
    }
    cnss_debug_ipc_log_print(cnss_ipc_log_context, v9, "cnss_power_down", 3u, 3u, "plat_priv is NULL\n", v3, v4, v15);
    return 4294967277LL;
  }
}
