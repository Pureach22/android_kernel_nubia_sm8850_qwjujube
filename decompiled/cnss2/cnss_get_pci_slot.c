__int64 __fastcall cnss_get_pci_slot(
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
  __int64 v9; // x8
  unsigned __int64 v11; // x8
  const char *v12; // x1
  unsigned __int64 StatusReg; // x8
  const char *v14; // x1
  __int16 v15; // w9
  const char *v16; // x8
  __int16 v17; // w9
  const char *v18; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  v8 = *(_QWORD *)(a1 + 152);
  if ( v8 )
  {
    v9 = *(_QWORD *)(v8 + 8);
    if ( v9 )
    {
      return *(unsigned int *)(v9 + 520);
    }
    else
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v14 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(StatusReg + 16);
        v18 = (const char *)(StatusReg + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v14 = "soft_irq";
        else
          v14 = v18;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v14,
        "cnss_get_pci_slot",
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
    v11 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v11 + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(v11 + 16);
      v16 = (const char *)(v11 + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v16;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_get_pci_slot",
      3u,
      3u,
      "pci_priv is NULL\n",
      a7,
      a8,
      vars0);
    return 4294967274LL;
  }
}
