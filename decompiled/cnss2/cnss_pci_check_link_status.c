__int64 __fastcall cnss_pci_check_link_status(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x30
  int v9; // w8
  unsigned __int64 StatusReg; // x8
  const char *v11; // x1
  unsigned __int64 v12; // x8
  const char *v13; // x1
  __int64 v15; // x21
  __int64 result; // x0
  __int16 v17; // w9
  const char *v18; // x8
  __int16 v19; // w9
  const char *v20; // x8
  unsigned __int64 v21; // x9
  const char *v22; // x1
  __int16 v23; // w10
  const char *v24; // x9
  unsigned int v31; // w19
  unsigned int v32; // w19
  char v33; // [xsp+0h] [xbp-20h]
  unsigned __int16 v34; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v35; // [xsp+18h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(unsigned __int8 *)(a1 + 48);
  v34 = 0;
  if ( v9 )
  {
    if ( *(_BYTE *)(a1 + 49) )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v11 = "irq";
      }
      else
      {
        v17 = *(_DWORD *)(StatusReg + 16);
        v18 = (const char *)(StatusReg + 2320);
        if ( (v17 & 0xFF00) != 0 )
          v11 = "soft_irq";
        else
          v11 = v18;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v11,
        "cnss_pci_check_link_status",
        3u,
        3u,
        "%ps: PCIe link is down\n",
        v8,
        a8,
        v33);
      result = 4294967291LL;
    }
    else
    {
      v15 = v8;
      pci_read_config_word(*(_QWORD *)a1, 2, &v34);
      if ( *(_DWORD *)(a1 + 24) == v34 )
      {
        result = 0;
        *(_DWORD *)(a1 + 728) = 0;
      }
      else
      {
        _X9 = (unsigned int *)(a1 + 728);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v31 = __ldxr(_X9);
          v32 = v31 + 1;
        }
        while ( __stlxr(v32, _X9) );
        __dmb(0xBu);
        v21 = _ReadStatusReg(SP_EL0);
        if ( (*(_DWORD *)(v21 + 16) & 0xF0000) != 0 )
        {
          v22 = "irq";
        }
        else
        {
          v23 = *(_DWORD *)(v21 + 16);
          v24 = (const char *)(v21 + 2320);
          if ( (v23 & 0xFF00) != 0 )
            v22 = "soft_irq";
          else
            v22 = v24;
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v22,
          "cnss_pci_check_link_status",
          3u,
          3u,
          "fatal: %ps: PCI device ID mismatch(%d), link possibly down, current read ID: 0x%x, record ID: 0x%x\n",
          v15,
          v32,
          v34);
        if ( v32 == 1 )
          cnss_pci_link_down(*(_QWORD *)a1 + 200LL);
        result = 4294967291LL;
      }
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
      v19 = *(_DWORD *)(v12 + 16);
      v20 = (const char *)(v12 + 2320);
      if ( (v19 & 0xFF00) != 0 )
        v13 = "soft_irq";
      else
        v13 = v20;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v13,
      "cnss_pci_check_link_status",
      7u,
      7u,
      "%ps: PCIe link is in suspend state\n",
      v8,
      a8,
      v33);
    result = 4294967283LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
