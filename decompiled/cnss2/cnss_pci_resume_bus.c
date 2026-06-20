__int64 __fastcall cnss_pci_resume_bus(__int64 a1)
{
  char v1; // w29
  __int64 v3; // x19
  __int64 v5; // x1
  __int64 v6; // x6
  __int64 v7; // x7
  unsigned __int64 StatusReg; // x8
  const char *v9; // x1
  int v10; // w8
  __int16 v11; // w9
  const char *v12; // x8
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  unsigned int v20; // w0
  __int64 v21; // x7
  unsigned __int64 v22; // x9
  unsigned int v23; // w19
  const char *v24; // x1
  __int16 v25; // w8
  const char *v26; // x9

  if ( *(_BYTE *)(a1 + 48) == 1 )
    return 0;
  v3 = *(_QWORD *)a1;
  if ( (unsigned int)cnss_set_pci_link(a1, 1) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else
    {
      v11 = *(_DWORD *)(StatusReg + 16);
      v12 = (const char *)(StatusReg + 2320);
      if ( (v11 & 0xFF00) != 0 )
        v9 = "soft_irq";
      else
        v9 = v12;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v9,
      "cnss_pci_resume_bus",
      3u,
      3u,
      "fatal: Failed to resume PCI link from suspend\n",
      v6,
      v7,
      v1);
    cnss_pci_link_down(v3 + 200, v13, v14, v15, v16, v17, v18, v19);
    return 4294967285LL;
  }
  v10 = *(unsigned __int8 *)(a1 + 232);
  *(_BYTE *)(a1 + 48) = 1;
  if ( v10 )
  {
LABEL_7:
    if ( (unsigned int)cnss_pci_set_mhi_state(a1, 7) )
      return 4294967285LL;
    else
      return 0;
  }
  v20 = pci_enable_device(v3, v5);
  if ( !v20 )
  {
    if ( *(_QWORD *)(a1 + 56) )
      cnss_set_pci_config_space((_QWORD *)a1, 0);
    pci_set_master(v3);
    goto LABEL_7;
  }
  v22 = _ReadStatusReg(SP_EL0);
  v23 = v20;
  if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
  {
    v24 = "irq";
  }
  else
  {
    v25 = *(_DWORD *)(v22 + 16);
    v26 = (const char *)(v22 + 2320);
    if ( (v25 & 0xFF00) != 0 )
      v24 = "soft_irq";
    else
      v24 = v26;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v24,
    "cnss_pci_resume_bus",
    3u,
    3u,
    "Failed to enable PCI device, err = %d\n",
    v20,
    v21,
    v1);
  return v23;
}
