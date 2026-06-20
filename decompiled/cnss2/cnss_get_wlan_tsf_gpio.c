__int64 __fastcall cnss_get_wlan_tsf_gpio(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  __int64 v3; // x6
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int16 v8; // w9
  const char *v9; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v2 = cnss_bus_dev_to_plat_priv(a1, a2);
  if ( v2 )
    return *(unsigned int *)(v2 + 152);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v7 = "irq";
  }
  else
  {
    v8 = *(_DWORD *)(StatusReg + 16);
    v9 = (const char *)(StatusReg + 2320);
    if ( (v8 & 0xFF00) != 0 )
      v7 = "soft_irq";
    else
      v7 = v9;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v7,
    "cnss_get_wlan_tsf_gpio",
    3u,
    3u,
    "plat_priv is NULL!\n",
    v3,
    v4,
    vars0);
  return 4294967274LL;
}
