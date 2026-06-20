__int64 __fastcall cnss_pci_update_time_sync_period(
        __int64 a1,
        int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x21
  unsigned int v11; // w8
  unsigned int v12; // w8
  unsigned __int64 StatusReg; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  unsigned __int64 v18; // x8
  const char *v19; // x1
  __int16 v20; // w9
  const char *v21; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  v8 = *(_QWORD *)(a1 + 8);
  v11 = *(_DWORD *)(a1 + 24) - 4353;
  if ( v11 <= 0x11 && ((1 << v11) & 0x32245) != 0 )
    cancel_delayed_work_sync(a1 + 488);
  *(_DWORD *)(v8 + 6704) = a2;
  v12 = *(_DWORD *)(a1 + 24) - 4353;
  if ( v12 <= 0x11 && ((1 << v12) & 0x32245) != 0 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 6484LL) )
    {
      cnss_pci_time_sync_work_hdlr(a1 + 488);
    }
    else
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v15 = "irq";
      }
      else
      {
        v16 = *(_DWORD *)(StatusReg + 16);
        v17 = (const char *)(StatusReg + 2320);
        if ( (v16 & 0xFF00) != 0 )
          v15 = "soft_irq";
        else
          v15 = v17;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v15,
        "cnss_pci_start_time_sync_update",
        7u,
        7u,
        "Device time clock frequency is not valid, skip time sync\n",
        a7,
        a8,
        vars0);
    }
  }
  v18 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v18 + 16) & 0xF0000) != 0 )
  {
    v19 = "irq";
  }
  else
  {
    v20 = *(_DWORD *)(v18 + 16);
    v21 = (const char *)(v18 + 2320);
    if ( (v20 & 0xFF00) != 0 )
      v19 = "soft_irq";
    else
      v19 = v21;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v19,
    "cnss_pci_update_time_sync_period",
    7u,
    7u,
    "WLAN time sync period %u ms\n",
    *(unsigned int *)(v8 + 6704),
    a8,
    vars0);
  return 0;
}
