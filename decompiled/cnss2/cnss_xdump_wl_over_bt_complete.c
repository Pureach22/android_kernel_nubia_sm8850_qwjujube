__int64 __fastcall cnss_xdump_wl_over_bt_complete(
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
  int v10; // w9
  __int64 v11; // x6
  const char *v12; // x1
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  __int16 v17; // w9
  const char *v18; // x8
  char v19; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v10 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
  if ( *(_BYTE *)(a1 + 7957) )
  {
    v11 = a2;
    if ( v10 )
    {
      v12 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v15;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_xdump_wl_over_bt_complete",
      6u,
      6u,
      "Collect WLAN dump over BT completed with result %d\n",
      v11,
      a8,
      v19);
    return complete(a1 + 7960);
  }
  else
  {
    if ( v10 )
    {
      v13 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(StatusReg + 16);
      v18 = (const char *)(StatusReg + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v18;
    }
    return cnss_debug_ipc_log_print(
             cnss_ipc_log_context,
             v13,
             "cnss_xdump_wl_over_bt_complete",
             6u,
             6u,
             "Collect WLAN dump over BT is NOT in progress\n",
             a7,
             a8,
             v19);
  }
}
