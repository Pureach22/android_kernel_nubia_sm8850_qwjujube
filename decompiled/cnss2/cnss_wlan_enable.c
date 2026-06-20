__int64 __fastcall cnss_wlan_enable(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v11; // x0
  __int64 v12; // x22
  unsigned __int64 v13; // x8
  __int64 v14; // x0
  int v15; // w9
  const char *v16; // x1
  unsigned __int64 StatusReg; // x8
  const char *v18; // x1
  __int64 result; // x0
  __int16 v20; // w9
  const char *v21; // x8
  const char *v22; // x5
  __int16 v23; // w9
  const char *v24; // x8
  __int16 v25; // w9
  const char *v26; // x8
  char v27; // [xsp+0h] [xbp-10h]

  if ( !a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v14 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else
    {
      v20 = *(_DWORD *)(StatusReg + 16);
      v21 = (const char *)(StatusReg + 2320);
      if ( (v20 & 0xFF00) != 0 )
        v18 = "soft_irq";
      else
        v18 = v21;
    }
    v22 = "Invalid dev pointer\n";
    goto LABEL_17;
  }
  v11 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( !v11 )
    return 4294967277LL;
  v12 = v11;
  if ( *(_QWORD *)(v11 + 528) == 62 || (*(_QWORD *)(v11 + 6680) & 0x10) != 0 )
    return 0;
  v13 = _ReadStatusReg(SP_EL0);
  v14 = cnss_ipc_log_context;
  v15 = *(_DWORD *)(v13 + 16) & 0xF0000;
  if ( !a2 || !a4 )
  {
    if ( v15 )
    {
      v18 = "irq";
    }
    else
    {
      v23 = *(_DWORD *)(v13 + 16);
      v24 = (const char *)(v13 + 2320);
      if ( (v23 & 0xFF00) != 0 )
        v18 = "soft_irq";
      else
        v18 = v24;
    }
    v22 = "Invalid config or host_version pointer\n";
LABEL_17:
    cnss_debug_ipc_log_print(v14, v18, "cnss_wlan_enable", 3u, 3u, v22, a7, a8, v27);
    return 4294967274LL;
  }
  if ( v15 )
  {
    v16 = "irq";
  }
  else
  {
    v25 = *(_DWORD *)(v13 + 16);
    v26 = (const char *)(v13 + 2320);
    if ( (v25 & 0xFF00) != 0 )
      v16 = "soft_irq";
    else
      v16 = v26;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v16,
    "cnss_wlan_enable",
    7u,
    7u,
    "Mode: %d, config: %pK, host_version: %s\n",
    a3,
    a2,
    a4);
  if ( a3 == 3 || a3 == 5 )
    return cnss_wlfw_wlan_mode_send_sync(v12, a3);
  if ( *(_QWORD *)(v12 + 528) == 4354 )
    *(_BYTE *)(a2 + 88) = 1;
  result = cnss_wlfw_wlan_cfg_send_sync(v12, a2, a4);
  if ( !(_DWORD)result )
    return cnss_wlfw_wlan_mode_send_sync(v12, a3);
  return result;
}
