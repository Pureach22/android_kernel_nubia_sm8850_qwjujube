__int64 __fastcall cnss_pci_load_m3(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  const char *v8; // x2
  int v9; // w8
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x8
  const char *v12; // x1
  __int64 result; // x0
  __int64 v15; // x7
  unsigned __int64 v16; // x20
  const char *v17; // x1
  unsigned int updated; // w0
  __int64 v19; // x7
  unsigned int v20; // w19
  const char *v21; // x1
  __int64 v22; // x0
  __int64 v23; // x7
  size_t *v24; // x0
  __int16 v25; // w9
  const char *v26; // x8
  const char *v27; // x1
  char v28; // [xsp+0h] [xbp-40h]
  char v29; // [xsp+0h] [xbp-40h]
  size_t *v30; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v31[6]; // [xsp+10h] [xbp-30h] BYREF

  v8 = "phy_ucode.elf";
  v31[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = *(_DWORD *)(a1 + 24);
  v10 = *(_QWORD *)(a1 + 8);
  v30 = nullptr;
  memset(v31, 0, 40);
  if ( (unsigned int)(v9 - 4352) <= 0x12 )
  {
    if ( ((1 << v9) & 0x64480) != 0 )
    {
      if ( *(_DWORD *)(v10 + 512) == 2 )
        v8 = "phy_ucode20.elf";
      goto LABEL_11;
    }
    if ( ((1 << v9) & 0xB) != 0 )
    {
      v8 = "m3.bin";
      goto LABEL_11;
    }
  }
  if ( v9 == 62 )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
    {
      v12 = "irq";
    }
    else
    {
      v25 = *(_DWORD *)(StatusReg + 16);
      v26 = (const char *)(StatusReg + 2320);
      if ( (v25 & 0xFF00) != 0 )
        v12 = "soft_irq";
      else
        v12 = v26;
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v12,
      "cnss_pci_load_m3",
      3u,
      3u,
      "Invalid device ID (0x%x) to load phy image\n",
      62,
      a8,
      v28);
    result = 4294967274LL;
    goto LABEL_14;
  }
LABEL_11:
  if ( *(_QWORD *)(v10 + 3816) || *(_QWORD *)(v10 + 3808) )
    goto LABEL_13;
  cnss_pci_add_fw_prefix_name(a1, (__int64)v31, v8);
  v16 = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
  {
    v17 = "irq";
  }
  else if ( (*(_DWORD *)(v16 + 16) & 0xFF00) != 0 )
  {
    v17 = "soft_irq";
  }
  else
  {
    v17 = (const char *)(v16 + 2320);
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v17,
    "cnss_pci_load_m3",
    7u,
    7u,
    "Invoke firmware_request_nowarn for %s\n",
    (__int64)v31,
    v15,
    v28);
  updated = cnss_request_firmware_update_timer((_QWORD *)v10, (__int64)&v30, (__int64)v31);
  if ( updated )
  {
    v20 = updated;
    if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
    {
      v21 = "irq";
    }
    else if ( (*(_DWORD *)(v16 + 16) & 0xFF00) != 0 )
    {
      v21 = "soft_irq";
    }
    else
    {
      v21 = (const char *)(v16 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v21,
      "cnss_pci_load_m3",
      3u,
      3u,
      "Failed to load M3 image: %s\n",
      (__int64)v31,
      v19,
      v29);
    result = v20;
  }
  else
  {
    v22 = dma_alloc_attrs(*(_QWORD *)a1 + 200LL, *v30, v10 + 3824, 3264, 0);
    *(_QWORD *)(v10 + 3816) = v22;
    if ( v22 )
    {
      memcpy(*(void **)(v10 + 3816), (const void *)v30[1], *v30);
      v24 = v30;
      *(_QWORD *)(v10 + 3808) = *v30;
      release_firmware(v24);
LABEL_13:
      result = 0;
      goto LABEL_14;
    }
    if ( (*(_DWORD *)(v16 + 16) & 0xF0000) != 0 )
    {
      v27 = "irq";
    }
    else if ( (*(_DWORD *)(v16 + 16) & 0xFF00) != 0 )
    {
      v27 = "soft_irq";
    }
    else
    {
      v27 = (const char *)(v16 + 2320);
    }
    cnss_debug_ipc_log_print(
      cnss_ipc_log_context,
      v27,
      "cnss_pci_load_m3",
      3u,
      3u,
      "Failed to allocate memory for M3, size: 0x%zx\n",
      *v30,
      v23,
      v29);
    release_firmware(v30);
    result = 4294967284LL;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}
