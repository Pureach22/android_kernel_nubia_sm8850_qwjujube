__int64 __fastcall cnss_get_platform_cap(__int64 a1, _DWORD *a2)
{
  __int64 v3; // x0
  __int64 v4; // x7
  __int64 v5; // x6
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int16 v9; // w9
  const char *v10; // x8
  char v11; // [xsp+0h] [xbp+0h]

  v3 = cnss_bus_dev_to_plat_priv(a1, (__int64)a2);
  if ( !v3 )
    return 4294967277LL;
  if ( !a2 )
    return 4294967274LL;
  v5 = *(unsigned int *)(v3 + 448);
  StatusReg = _ReadStatusReg(SP_EL0);
  *a2 = v5;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v7 = "irq";
  }
  else
  {
    v9 = *(_DWORD *)(StatusReg + 16);
    v10 = (const char *)(StatusReg + 2320);
    if ( (v9 & 0xFF00) != 0 )
      v7 = "soft_irq";
    else
      v7 = v10;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v7,
    "cnss_get_platform_cap",
    7u,
    7u,
    "Platform cap_flag is 0x%x\n",
    v5,
    v4,
    v11);
  return 0;
}
