__int64 __fastcall cnss_resume_pci_link(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  __int64 v9; // x8
  unsigned __int64 v10; // x8
  const char *v11; // x1
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  __int64 v18; // x20
  unsigned int v19; // w0
  __int64 v20; // x7
  unsigned int v21; // w8
  unsigned __int64 v22; // x9
  __int64 v23; // x0
  unsigned int v24; // w19
  const char *v25; // x1
  __int16 v26; // w9
  const char *v27; // x8
  _QWORD *v28; // x8
  __int64 v29; // x9
  _QWORD *v30; // x1
  unsigned int v31; // w0
  unsigned int v32; // w8
  unsigned __int64 v33; // x9
  __int16 v34; // w8
  const char *v35; // x9
  const char *v36; // x5
  __int16 v37; // w8
  const char *v38; // x9
  char v39; // [xsp+0h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  if ( !a1 )
    goto LABEL_29;
  v9 = a1[1];
  if ( v9 && (*(_QWORD *)(v9 + 6680) & 0x4000) != 0 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v15 = "irq";
    }
    else
    {
      v26 = *(_DWORD *)(StatusReg + 16);
      v27 = (const char *)(StatusReg + 2320);
      if ( (v26 & 0xFF00) != 0 )
        v15 = "soft_irq";
      else
        v15 = v27;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v15,
      "cnss_resume_pci_link",
      6u,
      6u,
      "%ps: prevent link resume\n",
      v8,
      a8,
      v39);
    result = 0xFFFFFFFFLL;
    goto LABEL_30;
  }
  if ( *((_BYTE *)a1 + 48) == 1 )
  {
    v10 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v10 + 16) & 0xF0000) != 0 )
    {
      v11 = "irq";
    }
    else
    {
      v16 = *(_DWORD *)(v10 + 16);
      v17 = (const char *)(v10 + 2320);
      if ( (v16 & 0xFF00) != 0 )
        v11 = "soft_irq";
      else
        v11 = v17;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v11,
      "cnss_resume_pci_link",
      6u,
      6u,
      "PCI link is already resumed\n",
      a7,
      a8,
      v39);
    result = 0;
    goto LABEL_30;
  }
  if ( (unsigned int)cnss_set_pci_link(a1, 1) )
  {
    cnss_pci_call_driver_uevent(a1);
    result = 4294967285LL;
    goto LABEL_30;
  }
  v18 = *a1;
  *((_BYTE *)a1 + 48) = 1;
  if ( *(_WORD *)(v18 + 62) != 62 )
  {
    v19 = pci_set_power_state(v18, 0);
    if ( v19 )
    {
      v21 = v19;
      v22 = _ReadStatusReg(SP_EL0);
      v23 = cnss_ipc_log_context;
      v24 = v21;
      if ( (*(_DWORD *)(v22 + 16) & 0xF0000) != 0 )
      {
        v25 = "irq";
      }
      else
      {
        v34 = *(_DWORD *)(v22 + 16);
        v35 = (const char *)(v22 + 2320);
        if ( (v34 & 0xFF00) != 0 )
          v25 = "soft_irq";
        else
          v25 = v35;
      }
      v36 = "Failed to set D0, err = %d\n";
LABEL_46:
      cnss_debug_ipc_log_print(v23, v25, "cnss_resume_pci_link", 3u, 3u, v36, v24, v20, v39);
      result = v24;
      goto LABEL_30;
    }
    v18 = *a1;
  }
  v28 = a1;
  v29 = a1[1];
  if ( !v29 )
  {
LABEL_29:
    result = 4294967277LL;
    goto LABEL_30;
  }
  if ( *((_BYTE *)a1 + 49) || (*(_QWORD *)(v29 + 552) & 0x200) != 0 )
  {
    pci_load_saved_state(v18, a1[8]);
    goto LABEL_32;
  }
  v30 = a1 + 7;
  if ( a1[7] )
  {
    pci_load_and_free_saved_state(v18, v30);
LABEL_32:
    pci_restore_state(v18);
    v28 = a1;
  }
  v31 = pci_enable_device(*v28, v30);
  if ( v31 )
  {
    v32 = v31;
    v33 = _ReadStatusReg(SP_EL0);
    v23 = cnss_ipc_log_context;
    v24 = v32;
    if ( (*(_DWORD *)(v33 + 16) & 0xF0000) != 0 )
    {
      v25 = "irq";
    }
    else
    {
      v37 = *(_DWORD *)(v33 + 16);
      v38 = (const char *)(v33 + 2320);
      if ( (v37 & 0xFF00) != 0 )
        v25 = "soft_irq";
      else
        v25 = v38;
    }
    v36 = "Failed to enable PCI device, err = %d\n";
    goto LABEL_46;
  }
  pci_set_master(*a1);
  result = 0;
  if ( *((_BYTE *)a1 + 49) )
    *((_BYTE *)a1 + 49) = 0;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}
