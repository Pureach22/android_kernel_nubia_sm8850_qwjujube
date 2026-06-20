__int64 __fastcall cnss_pci_get_link_status(__int64 *a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x7
  unsigned __int64 StatusReg; // x21
  const char *v6; // x1
  __int64 v7; // x0
  __int64 v8; // x7
  __int64 v9; // x6
  const char *v10; // x1
  char v11; // [xsp+0h] [xbp-10h]
  char v12; // [xsp+0h] [xbp-10h]
  unsigned __int16 v13; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+8h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v13 = 0;
  result = pcie_capability_read_word(v2, 18, &v13);
  if ( !(_DWORD)result )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v6 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v6 = "soft_irq";
    }
    else
    {
      v6 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v6,
      "cnss_pci_get_link_status",
      7u,
      7u,
      "Get PCI link status register: %u\n",
      v13,
      v4,
      v11);
    v7 = cnss_ipc_log_context;
    v8 = (v13 >> 4) & 0x3F;
    v9 = v13 & 0xF;
    *((_WORD *)a1 + 120) = v13 & 0xF;
    *((_WORD *)a1 + 121) = v8;
    *((_WORD *)a1 + 122) = v9;
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
      v7,
      v10,
      "cnss_pci_get_link_status",
      7u,
      7u,
      "Default PCI link speed is 0x%x, link width is 0x%x\n",
      v9,
      v8,
      v12);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
