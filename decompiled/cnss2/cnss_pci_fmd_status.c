__int64 __fastcall cnss_pci_fmd_status(__int64 a1, unsigned int a2)
{
  unsigned int v3; // w0
  unsigned __int64 StatusReg; // x9
  const char *v5; // x1
  __int16 v6; // w10
  const char *v7; // x9
  char v9; // [xsp+0h] [xbp+0h]

  if ( a2 )
  {
    v3 = cnss_pci_fmd_enable();
    StatusReg = _ReadStatusReg(SP_EL0);
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
      "cnss_pci_fmd_status",
      7u,
      7u,
      "Update FMD status to PCI: %d ret: %d\n",
      a2,
      v3,
      v9);
  }
  return 0;
}
