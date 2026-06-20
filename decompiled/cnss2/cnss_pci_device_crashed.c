__int64 __fastcall cnss_pci_device_crashed(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v11; // x0
  const char *v12; // x1
  unsigned __int64 v13; // x8
  __int16 v14; // w9
  const char *v15; // x8
  const char *v16; // x5
  __int16 v17; // w9
  const char *v18; // x8
  char v19; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    v11 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v14 = *(_DWORD *)(StatusReg + 16);
      v15 = (const char *)(StatusReg + 2320);
      if ( (v14 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v15;
    }
    v16 = "pci_priv is NULL\n";
    return cnss_debug_ipc_log_print(v11, v12, "cnss_pci_device_crashed", 3u, 3u, v16, a7, a8, v19);
  }
  v8 = *(_QWORD *)(a1 + 8);
  if ( !v8 )
  {
    v13 = _ReadStatusReg(SP_EL0);
    v11 = cnss_ipc_log_context;
    if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v17 = *(_DWORD *)(v13 + 16);
      v18 = (const char *)(v13 + 2320);
      if ( (v17 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v18;
    }
    v16 = "plat_priv is NULL\n";
    return cnss_debug_ipc_log_print(v11, v12, "cnss_pci_device_crashed", 3u, 3u, v16, a7, a8, v19);
  }
  if ( *(_BYTE *)(v8 + 544) )
    cnss_pci_collect_host_dump_info(a1);
  return cnss_recovery_handler(v8);
}
