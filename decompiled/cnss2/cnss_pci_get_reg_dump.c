__int64 __fastcall cnss_pci_get_reg_dump(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  unsigned __int64 StatusReg; // x8
  int v10; // w9
  const char *v13; // x1
  unsigned __int64 v14; // x8
  const char *v15; // x1
  const char *v16; // x1
  __int16 v17; // w9
  const char *v18; // x8
  __int16 v20; // w9
  const char *v21; // x8
  __int16 v22; // w9
  const char *v23; // x8
  char v24; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 152);
  if ( v8 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v10 = *(_DWORD *)(StatusReg + 16) & 0xF0000;
    if ( *(_BYTE *)(v8 + 48) )
    {
      if ( v10 )
      {
        v13 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(StatusReg + 16);
        v18 = (const char *)(StatusReg + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v13 = "soft_irq";
        else
          v13 = v18;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v13,
        "cnss_pci_get_reg_dump",
        7u,
        7u,
        "Start to get PCIe reg dump\n",
        a7,
        a8,
        v24);
      return cnss_pci_get_reg_dump(v8, a2, a3);
    }
    else
    {
      if ( v10 )
      {
        v16 = "irq";
      }
      else
      {
        v22 = *(_DWORD *)(StatusReg + 16);
        v23 = (const char *)(StatusReg + 2320);
        if ( (v22 & 0xFF00) != 0 )
          v16 = "soft_irq";
        else
          v16 = v23;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v16,
        "cnss_pci_get_reg_dump",
        7u,
        7u,
        "No PCIe reg dump since PCIe is suspended(D3)\n",
        a7,
        a8,
        v24);
      return 4294967283LL;
    }
  }
  else
  {
    v14 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v20 = *(_DWORD *)(v14 + 16);
      v21 = (const char *)(v14 + 2320);
      if ( (v20 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v21;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_pci_get_reg_dump",
      3u,
      3u,
      "pci_priv is NULL\n",
      a7,
      a8,
      v24);
    return 4294967277LL;
  }
}
