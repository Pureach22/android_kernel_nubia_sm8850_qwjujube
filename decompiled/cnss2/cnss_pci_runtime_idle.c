__int64 __fastcall cnss_pci_runtime_idle(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x9
  const char *v10; // x1
  __int16 v11; // w10
  const char *v12; // x9
  char v14; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else
  {
    v11 = *(_DWORD *)(StatusReg + 16);
    v12 = (const char *)(StatusReg + 2320);
    if ( (v11 & 0xFF00) != 0 )
      v10 = "soft_irq";
    else
      v10 = v12;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_long_context,
    v10,
    "cnss_pci_runtime_idle",
    7u,
    7u,
    "Runtime idle\n",
    a7,
    a8,
    v14);
  _pm_runtime_suspend(a1, 9);
  return 4294967280LL;
}
