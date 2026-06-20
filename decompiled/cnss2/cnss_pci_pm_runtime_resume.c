__int64 __fastcall cnss_pci_pm_runtime_resume(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v9; // x19
  unsigned __int64 StatusReg; // x8
  const char *v11; // x1
  __int16 v13; // w9
  const char *v14; // x8
  char v15; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  v9 = *a1;
  if ( (*(_DWORD *)(*a1 + 700) & 0xFFFFFFFE) == 2 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v13 = *(_DWORD *)(StatusReg + 16);
      v14 = (const char *)(StatusReg + 2320);
      if ( (v13 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v14;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_long_context,
      v11,
      "cnss_pci_pm_runtime_resume",
      7u,
      7u,
      "Runtime PM resume is requested by %ps\n",
      v8,
      a8,
      v15);
  }
  return _pm_runtime_resume(v9 + 200, 0);
}
