__int64 __fastcall cnss_reset_time_sync_period(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  int v5; // w1
  unsigned __int64 StatusReg; // x8
  const char *v8; // x1
  __int16 v9; // w9
  const char *v10; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v2 )
    return 4294967277LL;
  v5 = *(_DWORD *)(v2 + 6712);
  *(_DWORD *)(v2 + 6708) = -1;
  if ( v5 == -1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v8 = "irq";
    }
    else
    {
      v9 = *(_DWORD *)(StatusReg + 16);
      v10 = (const char *)(StatusReg + 2320);
      if ( (v9 & 0xFF00) != 0 )
        v8 = "soft_irq";
      else
        v8 = v10;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v8,
      "cnss_reset_time_sync_period",
      3u,
      3u,
      "Invalid min time sync value\n",
      v3,
      v4,
      vars0);
    return 4294967274LL;
  }
  else
  {
    cnss_bus_update_time_sync_period(v2);
    return 0;
  }
}
