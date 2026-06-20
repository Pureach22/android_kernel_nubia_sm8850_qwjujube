_DWORD *__fastcall cnss_pci_handle_linkdown(__int64 *a1)
{
  __int64 v1; // x21
  __int64 v3; // x6
  __int64 v4; // x7
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x8
  const char *v7; // x1
  __int64 v8; // x6
  __int64 v9; // x7
  unsigned __int64 v10; // x8
  const char *v11; // x1
  __int16 v12; // w9
  const char *v13; // x8
  _DWORD *result; // x0
  __int16 v15; // w9
  const char *v16; // x8
  char v17; // [xsp+0h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  v1 = *a1;
  if ( (*(_QWORD *)(a1[1] + 6680) & 0x40) != 0 )
    panic("cnss: PCI link is down\n");
  v5 = raw_spin_lock_irqsave(&pci_link_down_lock);
  if ( *((_BYTE *)a1 + 49) )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v7 = "irq";
    }
    else
    {
      v12 = *(_DWORD *)(StatusReg + 16);
      v13 = (const char *)(StatusReg + 2320);
      if ( (v12 & 0xFF00) != 0 )
        v7 = "soft_irq";
      else
        v7 = v13;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v7,
      "cnss_pci_handle_linkdown",
      7u,
      7u,
      "PCI link down recovery is in progress, ignore\n",
      v3,
      v4,
      v17);
    result = (_DWORD *)raw_spin_unlock_irqrestore(&pci_link_down_lock, v5);
  }
  else
  {
    *((_BYTE *)a1 + 49) = 1;
    raw_spin_unlock_irqrestore(&pci_link_down_lock, v5);
    if ( a1[43] )
      mhi_report_error();
    if ( *(_WORD *)(v1 + 62) == 62 )
      disable_irq_nosync(*(unsigned int *)(v1 + 1116));
    cnss_pci_call_driver_uevent(a1);
    v10 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v15 = *(_DWORD *)(v10 + 16);
      v16 = (const char *)(v10 + 2320);
      if ( (v15 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v16;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_pci_handle_linkdown",
      3u,
      3u,
      "fatal: PCI link down, schedule recovery\n",
      v8,
      v9,
      v17);
    *((_DWORD *)a1 + 92) = 0;
    result = cnss_schedule_recovery(v1 + 200, 1);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
