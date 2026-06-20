__int64 __fastcall devm_cnss_group_remove(__int64 a1, __int64 *a2)
{
  unsigned __int64 StatusReg; // x9
  __int64 v3; // x19
  const char *v5; // x1
  __int16 v6; // w10
  const char *v7; // x9
  char vars0; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *a2;
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v5 = "irq";
  }
  else
  {
    v6 = *(_DWORD *)(StatusReg + 16);
    v7 = (const char *)(StatusReg + 2320);
    if ( (v6 & 0xFF00) != 0 )
      v5 = "soft_irq";
    else
      v5 = v7;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v5,
    "devm_cnss_group_remove",
    7u,
    7u,
    "%s: removing group %p\n",
    (__int64)"devm_cnss_group_remove",
    v3,
    vars0);
  return sysfs_remove_group(a1, v3);
}
