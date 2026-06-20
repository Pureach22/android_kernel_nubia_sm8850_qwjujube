__int64 __fastcall cnss_suspend_pci_link(
        _BYTE *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x20
  __int64 v12; // x8
  __int64 result; // x0
  unsigned __int64 v14; // x8
  const char *v15; // x1
  unsigned int v16; // w0
  __int64 v17; // x7
  unsigned __int64 StatusReg; // x8
  const char *v19; // x1
  __int16 v20; // w9
  const char *v21; // x8
  __int16 v22; // w9
  const char *v23; // x8
  char vars0; // [xsp+0h] [xbp+0h]

  if ( !a1 )
    return 4294967277LL;
  if ( a1[48] )
  {
    pci_clear_master(*(_QWORD *)a1);
    v9 = *((_QWORD *)a1 + 1);
    if ( v9 )
    {
      v10 = *(_QWORD *)a1;
      if ( a1[49] || (*(_QWORD *)(v9 + 552) & 0x200) != 0 )
      {
        *((_QWORD *)a1 + 7) = 0;
      }
      else
      {
        v11 = *(_QWORD *)a1;
        pci_save_state();
        v12 = pci_store_saved_state(v11);
        v10 = *(_QWORD *)a1;
        *((_QWORD *)a1 + 7) = v12;
      }
      pci_disable_device(v10);
      if ( *(_WORD *)(*(_QWORD *)a1 + 62LL) != 62 )
      {
        v16 = pci_set_power_state();
        if ( v16 )
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
          {
            v19 = "irq";
          }
          else
          {
            v22 = *(_DWORD *)(StatusReg + 16);
            v23 = (const char *)(StatusReg + 2320);
            if ( (v22 & 0xFF00) != 0 )
              v19 = "soft_irq";
            else
              v19 = v23;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v19,
            "cnss_suspend_pci_link",
            3u,
            3u,
            "Failed to set D3Hot, err =  %d\n",
            v16,
            v17,
            vars0);
        }
      }
      a1[232] = 0;
      result = cnss_set_pci_link(a1, 0);
      if ( !(_DWORD)result )
        a1[48] = 0;
    }
    else
    {
      return 4294967277LL;
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
      "cnss_suspend_pci_link",
      6u,
      6u,
      "PCI link is already suspended\n",
      a7,
      a8,
      vars0);
    return 0;
  }
  return result;
}
