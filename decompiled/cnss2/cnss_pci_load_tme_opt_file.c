__int64 __fastcall cnss_pci_load_tme_opt_file(__int64 a1, int a2)
{
  __int64 v2; // x7
  __int64 v3; // x8
  __int64 v4; // x19
  unsigned __int64 StatusReg; // x8
  const char *v6; // x1
  __int64 v8; // x7
  unsigned __int64 v9; // x20
  const char *v10; // x1
  __int16 v11; // w9
  const char *v12; // x8
  __int64 result; // x0
  unsigned int v14; // w0
  unsigned int v15; // w19
  const char *v16; // x1
  __int64 v17; // x0
  size_t *v18; // x0
  const char *v19; // x1
  char v20; // [xsp+0h] [xbp-40h]
  char v21; // [xsp+0h] [xbp-40h]
  size_t *v22; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v23[6]; // [xsp+10h] [xbp-30h] BYREF

  v23[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned int *)(a1 + 24);
  v3 = *(_QWORD *)(a1 + 8);
  v22 = nullptr;
  memset(v23, 0, 40);
  if ( (_DWORD)v2 != 4366 )
  {
    if ( (_DWORD)v2 == 4370 )
    {
      if ( a2 != 1 )
        goto LABEL_25;
      v4 = v3 + 3928;
      if ( v3 == -3928 )
        goto LABEL_25;
      goto LABEL_17;
    }
    if ( (_DWORD)v2 != 4369 )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
      {
        v6 = "irq";
      }
      else
      {
        v11 = *(_DWORD *)(StatusReg + 16);
        v12 = (const char *)(StatusReg + 2320);
        if ( (v11 & 0xFF00) != 0 )
          v6 = "soft_irq";
        else
          v6 = v12;
      }
      cnss_debug_ipc_log_print(
        cnss_ipc_log_context,
        v6,
        "cnss_pci_load_tme_opt_file",
        7u,
        7u,
        "TME-L opt file: %s not supported for device ID: (0x%x)\n",
        0,
        v2,
        v20);
      goto LABEL_25;
    }
  }
  switch ( a2 )
  {
    case 3:
      v4 = v3 + 4008;
      if ( v3 == -4008 )
      {
LABEL_25:
        result = 0;
        goto LABEL_26;
      }
      break;
    case 2:
      v4 = v3 + 3968;
      if ( v3 == -3968 )
        goto LABEL_25;
      break;
    case 1:
      v4 = v3 + 3928;
      if ( v3 == -3928 )
        goto LABEL_25;
      break;
    default:
      goto LABEL_25;
  }
LABEL_17:
  if ( *(_QWORD *)(v4 + 8) || *(_QWORD *)v4 )
    goto LABEL_25;
  cnss_pci_add_fw_prefix_name(a1);
  v9 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v10 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v10 = "soft_irq";
  }
  else
  {
    v10 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v10,
    "cnss_pci_load_tme_opt_file",
    7u,
    7u,
    "Invoke firmware_request_nowarn for %s\n",
    (__int64)v23,
    v8,
    v20);
  v14 = firmware_request_nowarn(&v22, v23, *(_QWORD *)a1 + 200LL);
  if ( v14 )
  {
    v15 = v14;
    if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
    {
      v16 = "soft_irq";
    }
    else
    {
      v16 = (const char *)(v9 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "cnss_pci_load_tme_opt_file",
      3u,
      3u,
      "Failed to load TME-L opt file: %s, ret: %d\n",
      (__int64)v23,
      v14,
      v21);
    result = v15;
    goto LABEL_26;
  }
  v17 = dma_alloc_attrs(*(_QWORD *)a1 + 200LL, *v22, v4 + 16, 3264, 0);
  *(_QWORD *)(v4 + 8) = v17;
  if ( v17 )
  {
    memcpy(*(void **)(v4 + 8), (const void *)v22[1], *v22);
    v18 = v22;
    *(_QWORD *)v4 = *v22;
    release_firmware(v18);
    goto LABEL_25;
  }
  if ( (*(_DWORD *)(v9 + 16) & 0xF0000) != 0 )
  {
    v19 = "irq";
  }
  else if ( (*(_DWORD *)(v9 + 16) & 0xFF00) != 0 )
  {
    v19 = "soft_irq";
  }
  else
  {
    v19 = (const char *)(v9 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v19,
    "cnss_pci_load_tme_opt_file",
    3u,
    3u,
    "Failed to allocate memory for TME-L opt file %s,size: 0x%zx\n",
    (__int64)v23,
    *v22,
    v21);
  release_firmware(v22);
  result = 4294967284LL;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
