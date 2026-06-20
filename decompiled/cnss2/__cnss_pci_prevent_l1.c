__int64 __fastcall _cnss_pci_prevent_l1(
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
  unsigned __int64 v9; // x8
  __int64 v10; // x0
  const char *v11; // x1
  unsigned __int64 v12; // x8
  const char *v13; // x1
  unsigned __int64 v14; // x8
  __int64 result; // x0
  __int64 v17; // x6
  __int64 v18; // x7
  unsigned __int64 StatusReg; // x8
  const char *v20; // x1
  __int16 v21; // w9
  const char *v22; // x8
  __int16 v23; // w9
  const char *v24; // x8
  const char *v25; // x5
  __int16 v26; // w9
  const char *v27; // x8
  __int16 v28; // w9
  const char *v29; // x8
  __int64 v30; // x1
  __int64 v31; // x2
  __int64 v32; // x3
  __int64 v33; // x4
  __int64 v34; // x5
  __int64 v35; // x6
  __int64 v36; // x7
  char v37; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 152);
  if ( v8 )
  {
    if ( *(_BYTE *)(v8 + 48) )
    {
      if ( !*(_BYTE *)(v8 + 49) )
      {
        result = msm_pcie_prevent_l1(*(_QWORD *)v8);
        if ( (_DWORD)result != -5 )
          return result;
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v20 = "irq";
        }
        else
        {
          v28 = *(_DWORD *)(StatusReg + 16);
          v29 = (const char *)(StatusReg + 2320);
          if ( (v28 & 0xFF00) != 0 )
            v20 = "soft_irq";
          else
            v20 = v29;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v20,
          "__cnss_pci_prevent_l1",
          3u,
          3u,
          "Failed to prevent PCIe L1, considered as link down\n",
          v17,
          v18,
          v37);
        cnss_pci_link_down(a1, v30, v31, v32, v33, v34, v35, v36);
        return 4294967291LL;
      }
      v9 = _ReadStatusReg(SP_EL0);
      v10 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v23 = *(_DWORD *)(v9 + 16);
        v24 = (const char *)(v9 + 2320);
        if ( (v23 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v24;
      }
      v25 = "PCIe link is down\n";
    }
    else
    {
      v14 = _ReadStatusReg(SP_EL0);
      v10 = cnss_ipc_log_context;
      if ( (*(_DWORD *)(v14 + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v26 = *(_DWORD *)(v14 + 16);
        v27 = (const char *)(v14 + 2320);
        if ( (v26 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v27;
      }
      v25 = "PCIe link is in suspend state\n";
    }
    cnss_debug_ipc_log_print(v10, v11, "__cnss_pci_prevent_l1", 3u, 3u, v25, a7, a8, v37);
    return 4294967291LL;
  }
  v12 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
  {
    v13 = "irq";
  }
  else
  {
    v21 = *(_DWORD *)(v12 + 16);
    v22 = (const char *)(v12 + 2320);
    if ( (v21 & 0xFF00) != 0 )
      v13 = "soft_irq";
    else
      v13 = v22;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v13,
    "__cnss_pci_prevent_l1",
    3u,
    3u,
    "pci_priv is NULL\n",
    a7,
    a8,
    v37);
  return 4294967277LL;
}
