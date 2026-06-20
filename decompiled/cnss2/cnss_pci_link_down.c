__int64 __fastcall cnss_pci_link_down(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  __int64 v9; // x20
  unsigned __int64 StatusReg; // x8
  const char *v11; // x1
  unsigned __int64 v12; // x8
  const char *v13; // x1
  unsigned __int64 v14; // x8
  const char *v15; // x1
  unsigned __int64 v16; // x8
  const char *v17; // x1
  __int16 v18; // w9
  const char *v19; // x8
  __int64 result; // x0
  __int16 v21; // w9
  const char *v22; // x8
  __int16 v23; // w9
  const char *v24; // x8
  __int16 v25; // w9
  const char *v26; // x8
  unsigned int v27; // w20
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 152);
  if ( v8 )
  {
    v9 = *(_QWORD *)(v8 + 8);
    if ( v9 )
    {
      if ( *(_BYTE *)(v8 + 49) )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
        {
          v11 = "irq";
        }
        else
        {
          v21 = *(_DWORD *)(StatusReg + 16);
          v22 = (const char *)(StatusReg + 2320);
          if ( (v21 & 0xFF00) != 0 )
            v11 = "soft_irq";
          else
            v11 = v22;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v11,
          "cnss_pci_link_down",
          7u,
          7u,
          "PCI link down recovery is already in progress\n",
          a7,
          a8,
          vars0);
        return 4294967280LL;
      }
      else
      {
        if ( *(_BYTE *)(v8 + 232)
          && of_find_property(*(_QWORD *)(*(_QWORD *)v9 + 760LL), "cnss-enable-self-recovery", 0)
          && !*(_BYTE *)(v9 + 7955) )
        {
          *(_QWORD *)(v9 + 6680) |= 1uLL;
        }
        v16 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
        {
          v17 = "irq";
        }
        else
        {
          v25 = *(_DWORD *)(v16 + 16);
          v26 = (const char *)(v16 + 2320);
          if ( (v25 & 0xFF00) != 0 )
            v17 = "soft_irq";
          else
            v17 = v26;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v17,
          "cnss_pci_link_down",
          3u,
          3u,
          "PCI link down is detected by drivers, driver state 0x%lx\n",
          *(_QWORD *)(v9 + 552),
          a8,
          vars0);
        result = cnss_pci_assert_perst(v8);
        if ( (_DWORD)result )
        {
          v27 = result;
          cnss_pci_handle_linkdown(v8);
          return v27;
        }
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
        v23 = *(_DWORD *)(v14 + 16);
        v24 = (const char *)(v14 + 2320);
        if ( (v23 & 0xFF00) != 0 )
          v15 = "soft_irq";
        else
          v15 = v24;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v15,
        "cnss_pci_link_down",
        3u,
        3u,
        "plat_priv is NULL\n",
        a7,
        a8,
        vars0);
      return 4294967277LL;
    }
  }
  else
  {
    v12 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v13 = "irq";
    }
    else
    {
      v18 = *(_DWORD *)(v12 + 16);
      v19 = (const char *)(v12 + 2320);
      if ( (v18 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v19;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_pci_link_down",
      3u,
      3u,
      "pci_priv is NULL\n",
      a7,
      a8,
      vars0);
    return 4294967274LL;
  }
  return result;
}
