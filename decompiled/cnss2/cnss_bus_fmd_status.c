__int64 __fastcall cnss_bus_fmd_status(__int64 a1)
{
  int v1; // w6
  unsigned __int64 StatusReg; // x8
  const char *v3; // x1
  __int16 v5; // w9
  const char *v6; // x8

  if ( !a1 )
    return 4294967277LL;
  v1 = *(_DWORD *)(a1 + 16);
  if ( !v1 )
    return cnss_pci_fmd_status(*(_QWORD *)(a1 + 8));
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v3 = "irq";
  }
  else
  {
    v5 = *(_DWORD *)(StatusReg + 16);
    v6 = (const char *)(StatusReg + 2320);
    if ( (v5 & 0xFF00) != 0 )
      v3 = "soft_irq";
    else
      v3 = v6;
  }
  cnss_debug_ipc_log_print(cnss_ipc_log_context, v3, "cnss_bus_fmd_status", 3, 3, "Unsupported bus type: %d\n", v1);
  return 4294967274LL;
}
