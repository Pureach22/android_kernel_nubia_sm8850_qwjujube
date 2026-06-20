__int64 __fastcall cnss_pci_load_sku_license(
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
  __int64 v11; // x7
  unsigned __int64 v12; // x20
  const char *v13; // x1
  unsigned __int64 StatusReg; // x8
  const char *v15; // x1
  __int16 v16; // w9
  const char *v17; // x8
  __int64 result; // x0
  unsigned int updated; // w0
  unsigned int v20; // w19
  const char *v21; // x1
  __int64 v22; // x0
  __int64 v23; // x7
  size_t *v24; // x0
  const char *v25; // x1
  char v26; // [xsp+0h] [xbp-40h]
  char v27; // [xsp+0h] [xbp-40h]
  size_t *v28; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v29[6]; // [xsp+10h] [xbp-30h] BYREF

  v29[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned int *)(a1 + 24);
  v9 = *(_QWORD *)(a1 + 8);
  v28 = nullptr;
  memset(v29, 0, 40);
  if ( (_DWORD)v8 != 4369 && (_DWORD)v8 != 4366 )
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
      "cnss_pci_load_sku_license",
      7u,
      7u,
      "Soft SKU not supported for device ID: (0x%x)\n",
      v8,
      a8,
      v26);
    goto LABEL_13;
  }
  if ( *(_QWORD *)(v9 + 3856) || *(_QWORD *)(v9 + 3848) )
  {
LABEL_13:
    result = 0;
    goto LABEL_14;
  }
  scnprintf(v29, 40, "%s", "cnss_softsku_peach.pfm");
  v12 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
  {
    v13 = "irq";
  }
  else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
  {
    v13 = "soft_irq";
  }
  else
  {
    v13 = (const char *)(v12 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v13,
    "cnss_pci_load_sku_license",
    7u,
    7u,
    "Invoke firmware_request_nowarn for %s\n",
    (__int64)v29,
    v11,
    v26);
  updated = cnss_request_firmware_update_timer((_QWORD *)v9, (__int64)&v28, (__int64)v29);
  if ( updated )
  {
    v20 = updated;
    if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(v12 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "cnss_pci_load_sku_license",
      3u,
      3u,
      "Failed to load Soft SKU License: %s, ret: %d\n",
      (__int64)v29,
      updated,
      v27);
    result = v20;
    goto LABEL_14;
  }
  v22 = dma_alloc_attrs(*(_QWORD *)a1 + 200LL, *v28, v9 + 3864, 3264, 0);
  *(_QWORD *)(v9 + 3856) = v22;
  if ( v22 )
  {
    memcpy(*(void **)(v9 + 3856), (const void *)v28[1], *v28);
    v24 = v28;
    *(_QWORD *)(v9 + 3848) = *v28;
    release_firmware(v24);
    goto LABEL_13;
  }
  if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
  {
    v25 = "irq";
  }
  else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
  {
    v25 = "soft_irq";
  }
  else
  {
    v25 = (const char *)(v12 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v25,
    "cnss_pci_load_sku_license",
    3u,
    3u,
    "Failed to allocate memory for SKU License, size: 0x%zx\n",
    *v28,
    v23,
    v27);
  release_firmware(v28);
  result = 4294967284LL;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
