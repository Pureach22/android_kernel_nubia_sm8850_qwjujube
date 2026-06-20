__int64 __fastcall cnss_pci_update_fw_name(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v2; // w8
  __int64 v3; // x7
  unsigned __int64 v4; // x8
  const char *v5; // x1
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int16 v8; // w9
  const char *v9; // x8
  __int16 v11; // w9
  const char *v12; // x8
  char v13; // [xsp+0h] [xbp+0h]

  v1 = *(_QWORD *)(a1 + 8);
  v2 = *(_DWORD *)(a1 + 24) - 4353;
  if ( v2 > 0x11 )
    goto LABEL_4;
  if ( ((1 << v2) & 0x22244) != 0 )
  {
    if ( *(_DWORD *)(v1 + 512) != 2 )
    {
LABEL_4:
      cnss_pci_add_fw_prefix_name(a1, v1 + 6515, "amss.bin");
      strcpy((char *)(v1 + 6555), "amss.bin");
LABEL_12:
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v7 = "irq";
      }
      else
      {
        v8 = *(_DWORD *)(StatusReg + 16);
        v9 = (const char *)(StatusReg + 2320);
        if ( (v8 & 0xFF00) != 0 )
          v7 = "soft_irq";
        else
          v7 = v9;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v7,
        "cnss_pci_update_fw_name",
        7u,
        7u,
        "FW name is %s, FW fallback name is %s\n",
        v1 + 6515,
        v1 + 6555,
        v13);
      return 0;
    }
    goto LABEL_11;
  }
  if ( *(_DWORD *)(a1 + 24) != 4353 )
    goto LABEL_4;
  v3 = *(unsigned int *)(v1 + 512);
  if ( (unsigned int)v3 > 1 )
  {
LABEL_11:
    cnss_pci_add_fw_prefix_name(a1, v1 + 6515, "amss20.bin");
    strcpy((char *)(v1 + 6555), "amss20.bin");
    goto LABEL_12;
  }
  v4 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v4 + 16) & 0xF0000) != 0 )
  {
    v5 = "irq";
  }
  else
  {
    v11 = *(_DWORD *)(v4 + 16);
    v12 = (const char *)(v4 + 2320);
    if ( (v11 & 0xFF00) != 0 )
      v5 = "soft_irq";
    else
      v5 = v12;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v5,
    "cnss_pci_update_fw_name",
    7u,
    7u,
    "Device ID:version (0x%lx:%d) is not supported\n",
    4353,
    v3,
    v13);
  return 4294967274LL;
}
