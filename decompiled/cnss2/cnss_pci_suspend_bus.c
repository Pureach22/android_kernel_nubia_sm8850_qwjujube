__int64 __fastcall cnss_pci_suspend_bus(_QWORD *a1)
{
  __int64 v1; // x20
  __int64 result; // x0
  __int64 v4; // x1
  __int64 v5; // x6
  __int64 v6; // x7
  unsigned __int64 v7; // x8
  const char *v8; // x1
  __int64 v9; // x8
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x6
  __int64 v13; // x7
  unsigned int v14; // w0
  unsigned __int64 StatusReg; // x8
  const char *v16; // x1
  unsigned __int64 v17; // x8
  const char *v18; // x1
  __int16 v19; // w9
  const char *v20; // x8
  __int64 v21; // x8
  __int64 v22; // x21
  __int16 v23; // w9
  const char *v24; // x8
  __int16 v25; // w9
  const char *v26; // x8
  char v27; // [xsp+0h] [xbp+0h]

  if ( !*((_BYTE *)a1 + 48) )
    return 0;
  v1 = *a1;
  if ( !(unsigned int)cnss_pci_set_mhi_state((__int64)a1, 6) )
  {
    if ( !*((_BYTE *)a1 + 232) )
    {
      pci_clear_master(v1);
      v9 = a1[1];
      if ( v9 )
      {
        if ( *((_BYTE *)a1 + 49) || (v10 = *a1, (*(_QWORD *)(v9 + 552) & 0x200) != 0) )
        {
          v11 = 0;
        }
        else
        {
          pci_save_state(*a1);
          v11 = pci_store_saved_state(v10);
        }
        a1[7] = v11;
      }
      pci_disable_device(v1);
      if ( v1 )
      {
        v14 = pci_set_power_state(v1, 3);
        if ( v14 )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v16 = "irq";
          }
          else
          {
            v23 = *(_DWORD *)(StatusReg + 16);
            v24 = (const char *)(StatusReg + 2320);
            if ( (v23 & 0xFF00) != 0 )
              v16 = "soft_irq";
            else
              v16 = v24;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v16,
            "cnss_pci_set_power_state",
            3u,
            3u,
            "Failed to set power state %d, err = %d\n",
            3,
            v14,
            v27);
        }
      }
      else
      {
        v17 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v17 + 16) & 0xF0000) != 0 )
        {
          v18 = "irq";
        }
        else
        {
          v25 = *(_DWORD *)(v17 + 16);
          v26 = (const char *)(v17 + 2320);
          if ( (v25 & 0xFF00) != 0 )
            v18 = "soft_irq";
          else
            v18 = v26;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v18,
          "cnss_pci_set_power_state",
          3u,
          3u,
          "pci dev is NULL\n",
          v12,
          v13,
          v27);
      }
    }
    result = cnss_set_pci_link(a1, 0);
    if ( !(_DWORD)result )
    {
      *((_BYTE *)a1 + 48) = 0;
      return result;
    }
    if ( *(int *)(v1 + 2856) < 1 && (unsigned int)pci_enable_device(v1, v4) )
    {
      v7 = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(v7 + 16) & 0xF0000) != 0 )
      {
        v8 = "irq";
      }
      else
      {
        v19 = *(_DWORD *)(v7 + 16);
        v20 = (const char *)(v7 + 2320);
        if ( (v19 & 0xFF00) != 0 )
          v8 = "soft_irq";
        else
          v8 = v20;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v8,
        "cnss_pci_suspend_bus",
        3u,
        3u,
        "Failed to enable PCI device\n",
        v5,
        v6,
        v27);
    }
    if ( a1[7] )
    {
      v21 = a1[1];
      if ( v21 )
      {
        v22 = *a1;
        if ( *((_BYTE *)a1 + 49) || (*(_QWORD *)(v21 + 552) & 0x200) != 0 )
          pci_load_saved_state(*a1, a1[8]);
        else
          pci_load_and_free_saved_state(*a1, a1 + 7);
        pci_restore_state(v22);
      }
    }
    pci_set_master(v1);
    cnss_pci_set_mhi_state((__int64)a1, 7);
  }
  return 4294967285LL;
}
