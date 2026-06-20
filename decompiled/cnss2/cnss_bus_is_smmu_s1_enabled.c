__int64 __fastcall cnss_bus_is_smmu_s1_enabled(__int64 a1)
{
  int v1; // w6
  unsigned __int64 StatusReg; // x8
  const char *v3; // x1
  __int16 v4; // w9
  const char *v5; // x8

  if ( a1 )
  {
    v1 = *(_DWORD *)(a1 + 16);
    if ( v1 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v3 = "irq";
      }
      else
      {
        v4 = *(_DWORD *)(StatusReg + 16);
        v5 = (const char *)(StatusReg + 2320);
        if ( (v4 & 0xFF00) != 0 )
          v3 = "soft_irq";
        else
          v3 = v5;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v3,
        "cnss_bus_is_smmu_s1_enabled",
        3,
        3,
        "Unsupported bus type: %d\n",
        v1);
      LOBYTE(a1) = 0;
    }
    else
    {
      LOBYTE(a1) = cnss_pci_is_smmu_s1_enabled(*(_QWORD *)(a1 + 8));
    }
  }
  return a1 & 1;
}
