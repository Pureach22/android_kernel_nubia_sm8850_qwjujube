__int64 __fastcall _cnss_pci_allow_l1(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x8
  unsigned __int64 StatusReg; // x8
  __int64 v10; // x0
  const char *v11; // x1
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  __int16 v15; // w9
  const char *v16; // x8
  const char *v17; // x5
  __int16 v18; // w9
  const char *v19; // x8
  __int16 v20; // w9
  const char *v21; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 152);
  if ( v8 )
  {
    if ( *(_BYTE *)(v8 + 48) )
    {
      if ( !*(_BYTE *)(v8 + 49) )
        return msm_pcie_allow_l1(*(_QWORD *)v8);
      StatusReg = _ReadStatusReg(SP_EL0);
      v10 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v18 = *(_DWORD *)(StatusReg + 16);
        v19 = (const char *)(StatusReg + 2320);
        if ( (v18 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v19;
      }
      v17 = "PCIe link is down\n";
    }
    else
    {
      v13 = _ReadStatusReg(SP_EL0);
      v10 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v20 = *(_DWORD *)(v13 + 16);
        v21 = (const char *)(v13 + 2320);
        if ( (v20 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v21;
      }
      v17 = "PCIe link is in suspend state\n";
    }
  }
  else
  {
    v12 = _ReadStatusReg(SP_EL0);
    v10 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(v12 + 16);
      v16 = (const char *)(v12 + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v16;
    }
    v17 = "pci_priv is NULL\n";
  }
  return cnss_debug_ipc_log_print(v10, v11, "__cnss_pci_allow_l1", 3u, 3u, v17, a7, a8, vars0);
}
