__int64 __fastcall cnss_wlan_pm_control(
        __int64 a1,
        char a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  char v9; // w20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  const char *v12; // x8
  __int16 v13; // w9
  const char *v14; // x6
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 152);
  if ( !v8 )
    return 4294967277LL;
  if ( *(_BYTE *)(v8 + 697) != 1
    || (v9 = a2, result = cnss_pci_disable_pc(*(_QWORD *)(a1 + 152), a2 & 1), a2 = v9, !(_DWORD)result) )
  {
    *(_BYTE *)(v8 + 592) = a2 & 1;
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v13 = *(_DWORD *)(StatusReg + 16);
      v12 = (const char *)(StatusReg + 2320);
      if ( (v13 & 0xFF00) != 0 )
        v12 = "soft_irq";
    }
    if ( (a2 & 1) != 0 )
      v14 = "disable";
    else
      v14 = "enable";
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_wlan_pm_control",
      7u,
      7u,
      "%s PCIe power collapse\n",
      (__int64)v14,
      a8,
      vars0);
    return 0;
  }
  return result;
}
