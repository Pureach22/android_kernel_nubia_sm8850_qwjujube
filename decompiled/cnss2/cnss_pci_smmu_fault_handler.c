__int64 __fastcall cnss_pci_smmu_fault_handler(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 StatusReg; // x20
  const char *v10; // x1
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7
  __int64 v17; // x1
  const char *v19; // x1
  char v20; // [xsp+0h] [xbp+0h]
  char v21; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v10 = "soft_irq";
  }
  else
  {
    v10 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v10,
    "cnss_pci_smmu_fault_handler",
    3u,
    3u,
    "fatal: SMMU fault happened with IOVA 0x%lx\n",
    a3,
    a8,
    v20);
  if ( a5 )
  {
    *(_BYTE *)(a5 + 698) = 1;
    cnss_pci_update_status((__int64 *)a5, 4u, v11, v12, v13, v14, v15, v16);
    cnss_force_fw_assert(*(_QWORD *)a5 + 200LL, v17);
    return 4294967258LL;
  }
  else
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v19 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v19 = "soft_irq";
    }
    else
    {
      v19 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v19,
      "cnss_pci_smmu_fault_handler",
      3u,
      3u,
      "pci_priv is NULL\n",
      v15,
      v16,
      v21);
    return 4294967277LL;
  }
}
