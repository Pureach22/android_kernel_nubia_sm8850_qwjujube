__int64 __fastcall cnss_pci_load_aux(_QWORD *a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  int v3; // w8
  const char *v5; // x2
  __int64 v6; // x7
  unsigned __int64 StatusReg; // x20
  const char *v8; // x1
  unsigned int updated; // w0
  __int64 v10; // x7
  unsigned int v11; // w19
  const char *v12; // x1
  __int64 v13; // x0
  __int64 v14; // x7
  size_t *v15; // x0
  const char *v16; // x1
  char v17; // [xsp+0h] [xbp-40h]
  char v18; // [xsp+0h] [xbp-40h]
  size_t *v19; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v20[6]; // [xsp+10h] [xbp-30h] BYREF

  v20[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = a1[1];
  if ( *(_QWORD *)(v1 + 4064) || *(_QWORD *)(v1 + 4056) )
    goto LABEL_3;
  v3 = *(_DWORD *)(v1 + 512);
  v20[3] = 0;
  v20[4] = 0;
  if ( v3 == 2 )
    v5 = "aux_ucode20.elf";
  else
    v5 = "aux_ucode.elf";
  v19 = nullptr;
  memset(v20, 0, 24);
  cnss_pci_add_fw_prefix_name((__int64)a1, (__int64)v20, v5);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v8 = "irq";
  }
  else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    v8 = "soft_irq";
  }
  else
  {
    v8 = (const char *)(StatusReg + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v8,
    "cnss_pci_load_aux",
    7u,
    7u,
    "Invoke firmware_request_nowarn for %s\n",
    (__int64)v20,
    v6,
    v17);
  updated = cnss_request_firmware_update_timer((_QWORD *)v1, (__int64)&v19, (__int64)v20);
  if ( updated )
  {
    v11 = updated;
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v12 = "soft_irq";
    }
    else
    {
      v12 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_pci_load_aux",
      3u,
      3u,
      "Failed to load AUX image: %s\n",
      (__int64)v20,
      v10,
      v18);
    result = v11;
  }
  else
  {
    v13 = dma_alloc_attrs(*a1 + 200LL, *v19, v1 + 4072, 3264, 0);
    *(_QWORD *)(v1 + 4064) = v13;
    if ( v13 )
    {
      memcpy(*(void **)(v1 + 4064), (const void *)v19[1], *v19);
      v15 = v19;
      *(_QWORD *)(v1 + 4056) = *v19;
      release_firmware(v15);
LABEL_3:
      result = 0;
      goto LABEL_4;
    }
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v16 = "irq";
    }
    else if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v16 = "soft_irq";
    }
    else
    {
      v16 = (const char *)(StatusReg + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v16,
      "cnss_pci_load_aux",
      3u,
      3u,
      "Failed to allocate memory for AUX, size: 0x%zx\n",
      *v19,
      v14,
      v18);
    release_firmware(v19);
    result = 4294967284LL;
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}
