__int64 __fastcall cnss_update_time_sync_period(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 v3; // x0
  __int64 v4; // x6
  __int64 v5; // x7
  unsigned __int64 v6; // x8
  __int64 v7; // x0
  const char *v8; // x1
  unsigned int v10; // w8
  unsigned int v11; // w1
  __int16 v12; // w9
  const char *v13; // x8
  const char *v14; // x5
  unsigned __int64 StatusReg; // x8
  __int16 v16; // w9
  const char *v17; // x8
  char v18; // [xsp+0h] [xbp+0h]

  v2 = a2;
  v3 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v3 )
    return 4294967277LL;
  if ( v2 > 0x7CF )
  {
    v10 = *(_DWORD *)(v3 + 6712);
    *(_DWORD *)(v3 + 6708) = v2;
    if ( v2 >= v10 )
      v11 = v10;
    else
      v11 = v2;
    if ( v11 != -1 )
    {
      cnss_bus_update_time_sync_period(v3);
      return 0;
    }
    StatusReg = _ReadStatusReg(SP_EL0);
    v7 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(StatusReg + 16);
      v17 = (const char *)(StatusReg + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v17;
    }
    v14 = "Invalid min time sync value\n";
  }
  else
  {
    v6 = _ReadStatusReg(SP_EL0);
    v7 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v6 + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v12 = *(_DWORD *)(v6 + 16);
      v13 = (const char *)(v6 + 2320);
      if ( (v12 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v13;
    }
    v14 = "Invalid time sync value\n";
  }
  cnss_debug_ipc_log_print(v7, v8, "cnss_update_time_sync_period", 3u, 3u, v14, v4, v5, v18);
  return 4294967274LL;
}
