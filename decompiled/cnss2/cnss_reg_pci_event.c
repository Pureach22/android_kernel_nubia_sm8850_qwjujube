__int64 __fastcall cnss_reg_pci_event(__int64 *a1)
{
  __int64 v1; // x11
  bool v2; // zf
  int v3; // w8
  __int64 v4; // x7
  unsigned int v5; // w19
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int16 v8; // w9
  const char *v9; // x8
  char v11; // [xsp+0h] [xbp+0h]

  v1 = *a1;
  v2 = *((_BYTE *)a1 + 697) == 0;
  a1[14] = (__int64)cnss_pci_event_cb;
  if ( v2 )
    v3 = 69;
  else
    v3 = 117;
  *((_DWORD *)a1 + 26) = 0;
  a1[12] = v1;
  *((_DWORD *)a1 + 22) = v3;
  *((_DWORD *)a1 + 40) = 2;
  v5 = msm_pcie_register_event(a1 + 9);
  if ( v5 )
  {
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
      "cnss_reg_pci_event",
      3u,
      3u,
      "Failed to register MSM PCI event, err = %d\n",
      v5,
      v4,
      v11);
  }
  return v5;
}
