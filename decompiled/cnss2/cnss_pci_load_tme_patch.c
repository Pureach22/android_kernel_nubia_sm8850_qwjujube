__int64 __fastcall cnss_pci_load_tme_patch(
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
  int v10; // w8
  const char *v11; // x9
  const char *v12; // x3
  __int64 v14; // x7
  unsigned __int64 v15; // x20
  const char *v16; // x1
  unsigned __int64 StatusReg; // x8
  const char *v18; // x1
  __int16 v19; // w9
  const char *v20; // x8
  __int64 result; // x0
  unsigned int updated; // w0
  unsigned int v23; // w19
  const char *v24; // x1
  __int64 v25; // x0
  __int64 v26; // x7
  size_t *v27; // x0
  const char *v28; // x1
  char v29; // [xsp+0h] [xbp-40h]
  char v30; // [xsp+0h] [xbp-40h]
  size_t *v31; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v32[6]; // [xsp+10h] [xbp-30h] BYREF

  v32[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = *(unsigned int *)(a1 + 24);
  v9 = *(_QWORD *)(a1 + 8);
  v31 = nullptr;
  memset(v32, 0, 40);
  if ( (_DWORD)v8 != 4369 && (_DWORD)v8 != 4366 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v18 = "irq";
    }
    else
    {
      v19 = *(_DWORD *)(StatusReg + 16);
      v20 = (const char *)(StatusReg + 2320);
      if ( (v19 & 0xFF00) != 0 )
        v18 = "soft_irq";
      else
        v18 = v20;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v18,
      "cnss_pci_load_tme_patch",
      7u,
      7u,
      "TME-L not supported for device ID: (0x%x)\n",
      v8,
      a8,
      v29);
    goto LABEL_18;
  }
  v10 = *(_DWORD *)(v9 + 512);
  v11 = "tmel_peach_20.elf";
  if ( v10 != 2 )
    v11 = nullptr;
  if ( v10 == 1 )
    v12 = "tmel_peach_10.elf";
  else
    v12 = v11;
  if ( *(_QWORD *)(v9 + 3896) || *(_QWORD *)(v9 + 3888) )
    goto LABEL_18;
  scnprintf(v32, 40, "%s", v12);
  v15 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
  {
    v16 = "irq";
  }
  else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
  {
    v16 = "soft_irq";
  }
  else
  {
    v16 = (const char *)(v15 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v16,
    "cnss_pci_load_tme_patch",
    7u,
    7u,
    "Invoke firmware_request_nowarn for %s\n",
    (__int64)v32,
    v14,
    v29);
  updated = cnss_request_firmware_update_timer((_QWORD *)v9, (__int64)&v31, (__int64)v32);
  if ( updated )
  {
    v23 = updated;
    if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
    {
      v24 = "irq";
    }
    else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
    {
      v24 = "soft_irq";
    }
    else
    {
      v24 = (const char *)(v15 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v24,
      "cnss_pci_load_tme_patch",
      3u,
      3u,
      "Failed to load TME-L patch: %s, ret: %d\n",
      (__int64)v32,
      updated,
      v30);
    result = v23;
    goto LABEL_19;
  }
  v25 = dma_alloc_attrs(*(_QWORD *)a1 + 200LL, *v31, v9 + 3904, 3264, 0);
  *(_QWORD *)(v9 + 3896) = v25;
  if ( v25 )
  {
    memcpy(*(void **)(v9 + 3896), (const void *)v31[1], *v31);
    v27 = v31;
    *(_QWORD *)(v9 + 3888) = *v31;
    release_firmware(v27);
LABEL_18:
    result = 0;
    goto LABEL_19;
  }
  if ( (*(_DWORD *)(v15 + 16) & 0xF0000) != 0 )
  {
    v28 = "irq";
  }
  else if ( (*(_DWORD *)(v15 + 16) & 0xFF00) != 0 )
  {
    v28 = "soft_irq";
  }
  else
  {
    v28 = (const char *)(v15 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v28,
    "cnss_pci_load_tme_patch",
    3u,
    3u,
    "Failed to allocate memory for TME Lite Patch, size: 0x%zx\n",
    *v31,
    v26,
    v30);
  release_firmware(v31);
  result = 4294967284LL;
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
