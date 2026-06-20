__int64 __fastcall icnss_load_aux(__int64 a1)
{
  __int64 v1; // x8
  unsigned int v3; // w0
  __int64 v4; // x0
  size_t *v5; // x8
  size_t v6; // x2
  size_t *v7; // x0
  __int64 result; // x0
  unsigned int v9; // w20
  size_t *v10; // [xsp+0h] [xbp-40h] BYREF
  _QWORD v11[7]; // [xsp+8h] [xbp-38h] BYREF

  v11[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 5416);
  v10 = nullptr;
  if ( !v1 && !*(_QWORD *)(a1 + 5408) )
  {
    memset(v11, 0, 45);
    icnss_add_fw_prefix_name(a1, (const char *)v11, "aux_ucode.elf");
    v3 = firmware_request_nowarn(&v10, v11, *(_QWORD *)(a1 + 8) + 16LL);
    if ( v3 )
    {
      v9 = v3;
      printk("%sicnss2_qmi: Failed to load AUX image: %s\n", byte_130B32, (const char *)v11);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: Failed to load AUX image: %s\n",
        (const char *)&unk_12DBF3,
        (const char *)v11);
      result = v9;
      goto LABEL_7;
    }
    v4 = dma_alloc_attrs(*(_QWORD *)(a1 + 8) + 16LL, *v10, a1 + 5424, 3264, 0);
    v5 = v10;
    *(_QWORD *)(a1 + 5416) = v4;
    v6 = *v5;
    if ( !v4 )
    {
      printk("%sicnss2_qmi: Failed to allocate memory for AUX, size: 0x%zx\n", byte_130B32, v6);
      ipc_log_string(
        icnss_ipc_log_context,
        "%sicnss2_qmi: Failed to allocate memory for AUX, size: 0x%zx\n",
        (const char *)&unk_12DBF3,
        *v10);
      release_firmware(v10);
      result = 4294967284LL;
      goto LABEL_7;
    }
    memcpy(*(void **)(a1 + 5416), (const void *)v10[1], v6);
    v7 = v10;
    *(_QWORD *)(a1 + 5408) = *v10;
    release_firmware(v7);
  }
  result = 0;
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
