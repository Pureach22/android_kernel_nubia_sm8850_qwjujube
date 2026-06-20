__int64 __fastcall cnss_bus_debug_reg_write(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  int v4; // w6
  unsigned __int64 StatusReg; // x8
  const char *v6; // x1
  __int16 v8; // w9
  const char *v9; // x8

  if ( !a1 )
    return 4294967277LL;
  v4 = *(_DWORD *)(a1 + 16);
  if ( !v4 )
    return cnss_pci_debug_reg_write(*(_QWORD *)(a1 + 8), a2, a3, a4 & 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v6 = "irq";
  }
  else
  {
    v8 = *(_DWORD *)(StatusReg + 16);
    v9 = (const char *)(StatusReg + 2320);
    if ( (v8 & 0xFF00) != 0 )
      v6 = "soft_irq";
    else
      v6 = v9;
  }
  cnss_debug_ipc_log_print(cnss_ipc_log_context, v6, "cnss_bus_debug_reg_write", 7, 7, "Unsupported bus type: %d\n", v4);
  return 0;
}
