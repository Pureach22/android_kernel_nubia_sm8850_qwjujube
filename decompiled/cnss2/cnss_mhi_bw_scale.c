__int64 __fastcall cnss_mhi_bw_scale(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v5; // x19
  __int64 v6; // x21
  const char *v7; // x1
  unsigned int v8; // w0
  const char *v9; // x1
  __int64 v10; // x7
  unsigned int v11; // w21
  const char *v12; // x1
  char v14; // [xsp+0h] [xbp+0h]
  char v15; // [xsp+0h] [xbp+0h]

  v2 = *(_QWORD *)(a1 + 8);
  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(v2 + 152);
  v6 = *(_QWORD *)(v5 + 8);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v7 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v7 = "soft_irq";
  }
  else
  {
    v7 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v7,
    "cnss_mhi_bw_scale",
    7u,
    7u,
    "Setting link speed:0x%x, width:0x%x\n",
    *a2,
    a2[1],
    v14);
  v8 = cnss_pci_set_max_link_speed(v5, *(unsigned int *)(v6 + 520), *a2);
  if ( v8 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v9 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v9 = "soft_irq";
    }
    else
    {
      v9 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v9,
      "cnss_mhi_bw_scale",
      3u,
      3u,
      "Failed to set target link speed to 0x%x, err = %d\n",
      *a2,
      v8,
      v15);
  }
  v11 = cnss_pci_set_link_bandwidth(v5, *a2, a2[1]);
  if ( v11 )
  {
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v12 = "soft_irq";
    }
    else
    {
      v12 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_mhi_bw_scale",
      3u,
      3u,
      "Failed to set link bandwidth, err = %d\n",
      v11,
      v10,
      v15);
  }
  else
  {
    *(_WORD *)(v5 + 240) = *a2;
    *(_WORD *)(v5 + 242) = a2[1];
  }
  return v11;
}
