__int64 __fastcall cnss_pci_suspend(__int64 a1)
{
  __int64 *v1; // x20
  __int64 v2; // x19
  __int64 v3; // x6
  __int64 v4; // x7
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 (__fastcall *v8)(__int64, __int64); // x8
  unsigned int v9; // w0
  unsigned __int64 StatusReg; // x8
  const char *v11; // x1
  __int64 result; // x0
  unsigned __int64 v13; // x8
  const char *v14; // x1
  unsigned int v15; // w21
  __int16 v16; // w9
  const char *v17; // x8
  unsigned __int64 v18; // x8
  const char *v19; // x1
  __int16 v20; // w9
  const char *v21; // x8
  __int16 v22; // w9
  const char *v23; // x8
  unsigned __int64 v29; // x9
  unsigned __int64 v32; // x10
  char v33; // [xsp+0h] [xbp+0h]

  v1 = *(__int64 **)(a1 + 152);
  if ( !v1 )
    return 0;
  v2 = v1[1];
  if ( !v2 || (cnss_is_device_powered_on(v1[1]) & 1) == 0 || (*(_BYTE *)(v2 + 7880) & 1) != 0 )
    return 0;
  if ( (*(_QWORD *)(v2 + 552) & 8) != 0 )
    return 4294967285LL;
  if ( (*(_QWORD *)(v2 + 6680) & 0x200) != 0
    || *((_BYTE *)v1 + 697) != 1
    || (_ZF = (unsigned __int8)*((_DWORD *)v1 + 57) == 0, *((_BYTE *)v1 + 232) = *((_DWORD *)v1 + 57), !_ZF) )
  {
    _X8 = (unsigned __int64 *)(v2 + 552);
    __asm { PRFM            #0x11, [X8] }
    do
      v29 = __ldxr(_X8);
    while ( __stxr(v29 | 0x8000, _X8) );
    v6 = *v1;
    v7 = v1[5];
    if ( (*(_QWORD *)(v1[1] + 552) & 0x4000000) != 0 )
    {
      if ( v7 )
      {
        v8 = *(__int64 (__fastcall **)(__int64, __int64))(v7 + 64);
        if ( v8 )
        {
          if ( *((_DWORD *)v8 - 1) != 1589707286 )
            __break(0x8228u);
          v9 = v8(v6, 2);
          if ( v9 )
          {
            StatusReg = _ReadStatusReg(SP_EL0);
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
            {
              v11 = "irq";
            }
            else
            {
              v20 = *(_DWORD *)(StatusReg + 16);
              v21 = (const char *)(StatusReg + 2320);
              if ( (v20 & 0xFF00) != 0 )
                v11 = "soft_irq";
              else
                v11 = v21;
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v11,
              "cnss_pci_suspend_driver",
              3u,
              3u,
              "Failed to suspend host driver, err = %d\n",
              v9,
              v4,
              v33);
            result = 4294967285LL;
            goto LABEL_35;
          }
        }
      }
    }
    if ( !*((_BYTE *)v1 + 592) )
    {
      mutex_lock(v1 + 75);
      v15 = cnss_pci_suspend_bus(v1);
      mutex_unlock(v1 + 75);
      if ( v15 )
      {
        cnss_pci_resume_driver(v1);
        result = v15;
LABEL_35:
        *((_BYTE *)v1 + 232) = 0;
        _X8 = (unsigned __int64 *)(v2 + 552);
        __asm { PRFM            #0x11, [X8] }
        do
          v32 = __ldxr(_X8);
        while ( __stxr(v32 & 0xFFFFFFFFFFFF7FFFLL, _X8) );
        return result;
      }
    }
    *((_BYTE *)v1 + 260) = 0;
    v13 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v13 + 16) & 0xF0000) != 0 )
    {
      v14 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(v13 + 16);
      v17 = (const char *)(v13 + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v14 = "soft_irq";
      else
        v14 = v17;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v14,
      "cnss_pci_suspend",
      6u,
      6u,
      "WoW Entry. pcie_time_sync_offset = %llu",
      *(_QWORD *)(v2 + 7872),
      v4,
      v33);
    return 0;
  }
  v18 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
  {
    v19 = "irq";
  }
  else
  {
    v22 = *(_DWORD *)(v18 + 16);
    v23 = (const char *)(v18 + 2320);
    if ( (v22 & 0xFF00) != 0 )
      v19 = "soft_irq";
    else
      v19 = v23;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v19,
    "cnss_pci_suspend",
    7u,
    7u,
    "Firmware does not support non-DRV suspend, reject\n",
    v3,
    v4,
    v33);
  return 4294967285LL;
}
