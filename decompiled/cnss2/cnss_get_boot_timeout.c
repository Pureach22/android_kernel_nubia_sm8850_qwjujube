__int64 __fastcall cnss_get_boot_timeout(__int64 a1, __int64 a2)
{
  __int64 v2; // x6
  __int64 v3; // x7
  unsigned __int64 StatusReg; // x8
  const char *v6; // x1
  __int16 v7; // w9
  const char *v8; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( cnss_bus_dev_to_plat_priv(a1, a2) )
    return cnss_get_qmi_timeout();
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v6 = "irq";
  }
  else
  {
    v7 = *(_DWORD *)(StatusReg + 16);
    v8 = (const char *)(StatusReg + 2320);
    if ( (v7 & 0xFF00) != 0 )
      v6 = "soft_irq";
    else
      v6 = v8;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v6,
    "cnss_get_boot_timeout",
    3u,
    3u,
    "plat_priv is NULL\n",
    v2,
    v3,
    vars0);
  return 0;
}
