__int64 __fastcall cnss_pci_dev_ramdump(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x6
  __int64 v9; // x19
  unsigned int v10; // w20
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  __int64 v19; // x6
  __int64 v20; // x7
  unsigned __int64 v21; // x8
  const char *v22; // x1
  unsigned __int64 StatusReg; // x8
  const char *v24; // x1
  __int16 v25; // w9
  const char *v26; // x8
  _QWORD *v27; // x0
  unsigned __int64 v28; // x8
  const char *v29; // x1
  __int16 v30; // w9
  const char *v31; // x8
  __int16 v32; // w9
  const char *v33; // x8
  char v35; // [xsp+0h] [xbp+0h]

  if ( !a1 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v24 = "irq";
    }
    else
    {
      v25 = *(_DWORD *)(StatusReg + 16);
      v26 = (const char *)(StatusReg + 2320);
      if ( (v25 & 0xFF00) != 0 )
        v24 = "soft_irq";
      else
        v24 = v26;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v24,
      "cnss_pci_dev_ramdump",
      3u,
      3u,
      "pci_priv is NULL\n",
      a7,
      a8,
      v35);
    return (unsigned int)-19;
  }
  v8 = *(unsigned int *)(a1 + 24);
  if ( (unsigned int)(v8 - 4352) > 0x12 || ((1 << *(_DWORD *)(a1 + 24)) & 0x6448F) == 0 )
  {
    if ( (_DWORD)v8 == 62 )
    {
      v27 = *(_QWORD **)(a1 + 8);
      if ( v27[21] )
        return (unsigned int)cnss_do_ramdump(v27);
      else
        return (unsigned int)-22;
    }
    v28 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v28 + 16) & 0xF0000) != 0 )
    {
      v29 = "irq";
    }
    else
    {
      v30 = *(_DWORD *)(v28 + 16);
      v31 = (const char *)(v28 + 2320);
      if ( (v30 & 0xFF00) != 0 )
        v29 = "soft_irq";
      else
        v29 = v31;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v29,
      "cnss_pci_dev_ramdump",
      3u,
      3u,
      "Unknown device_id found: 0x%x\n",
      v8,
      a8,
      v35);
    return (unsigned int)-19;
  }
  v9 = *(_QWORD *)(a1 + 8);
  v10 = 0;
  if ( *(_BYTE *)(v9 + 280) && *(_QWORD *)(v9 + 272) )
  {
    if ( *(_DWORD *)(v9 + 336) )
    {
      v10 = cnss_do_elf_ramdump(*(_QWORD *)(a1 + 8));
      cnss_pci_clear_dump_info(a1);
      cnss_pci_power_off_mhi(a1, 0);
      cnss_suspend_pci_link((_BYTE *)a1, v12, v13, v14, v15, v16, v17, v18);
      if ( (*(_QWORD *)(*(_QWORD *)(a1 + 8) + 6680LL) & 0x80) == 0 )
      {
        if ( (*(_QWORD *)(a1 + 352) & 1) != 0 )
        {
          cnss_pci_set_mhi_state(a1, 1);
        }
        else
        {
          v21 = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(v21 + 16) & 0xF0000) != 0 )
          {
            v22 = "irq";
          }
          else
          {
            v32 = *(_DWORD *)(v21 + 16);
            v33 = (const char *)(v21 + 2320);
            if ( (v32 & 0xFF00) != 0 )
              v22 = "soft_irq";
            else
              v22 = v33;
          }
          cnss_debug_ipc_log_print(
            cnss_ipc_log_context,
            v22,
            "cnss_pci_deinit_mhi",
            7u,
            7u,
            "MHI is already deinited\n",
            v19,
            v20,
            v35);
        }
      }
      cnss_power_off_device(v9);
    }
    else
    {
      return 0;
    }
  }
  return v10;
}
