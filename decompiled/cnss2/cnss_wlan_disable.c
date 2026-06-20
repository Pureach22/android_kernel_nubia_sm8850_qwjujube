__int64 __fastcall cnss_wlan_disable(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x0
  __int64 v9; // x19
  unsigned int v10; // w20
  unsigned __int64 StatusReg; // x8
  const char *v13; // x1
  __int16 v14; // w9
  const char *v15; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( a1 )
  {
    v8 = cnss_bus_dev_to_plat_priv(a1, a2);
    if ( v8 )
    {
      if ( *(_QWORD *)(v8 + 528) == 62 || (*(_QWORD *)(v8 + 6680) & 0x10) != 0 )
      {
        return 0;
      }
      else
      {
        v9 = v8;
        v10 = cnss_wlfw_wlan_mode_send_sync(v8, 4);
        cnss_bus_free_qdss_mem(v9);
        return v10;
      }
    }
    else
    {
      return 4294967277LL;
    }
  }
  else
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v15;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_wlan_disable",
      3u,
      3u,
      "Invalid dev pointer\n",
      a7,
      a8,
      vars0);
    return 4294967274LL;
  }
}
