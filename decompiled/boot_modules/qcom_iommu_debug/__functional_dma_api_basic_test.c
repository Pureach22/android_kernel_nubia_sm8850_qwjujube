__int64 __fastcall _functional_dma_api_basic_test(const char **a1, __int64 a2)
{
  const char *v2; // x8
  int v5; // w24
  void *v6; // x0
  void *v7; // x22
  char v8; // w0
  __int64 v9; // x26
  unsigned __int64 v10; // x19
  __int64 v11; // x23
  __int64 v12; // x3
  int v13; // w0
  __int64 i; // x19
  char v15; // w19
  const char *v16; // x0
  const char *v17; // x2
  const char *v18; // x1
  unsigned int v19; // w21
  const char *v21; // x1
  __int64 v22; // [xsp+8h] [xbp-8h]

  v2 = a1[14];
  if ( !v2 )
    v2 = *a1;
  printk(&unk_CB8B, v2);
  v22 = a2;
  seq_printf(a2, "Basic DMA API test");
  v5 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 2 )
  {
    v6 = (void *)_kmalloc_cache_noprof(seq_putc, 3264, 1518);
    v7 = v6;
    if ( !v6 )
    {
      v13 = -12;
LABEL_26:
      v18 = a1[14];
      v19 = v13;
      if ( !v18 )
        v18 = *a1;
      printk(&unk_D054, v18);
      seq_printf(v22, "  -> FAILED\n");
      return v19;
    }
    memset(v6, 165, 0x5EEu);
    v8 = is_vmalloc_addr(v7);
    if ( (v8 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v15 = v8;
      dma_map_single_attrs___already_done = 1;
      v16 = (const char *)dev_driver_string(a1);
      v17 = a1[14];
      if ( !v17 )
        v17 = *a1;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v16, v17);
      v8 = v15;
      __break(0x800u);
    }
    v9 = (__int64)((_QWORD)v7 << 8) >> 8;
    v10 = v9 + 0x8000000000LL;
    if ( (v8 & 1) != 0 )
      v11 = -1;
    else
      v11 = dma_map_page_attrs(a1, (v10 >> 12 << 6) - 0x140000000LL, (unsigned __int16)v7 & 0xFF8, 1518, 1, 0);
    if ( v10 >> 38 )
      v12 = v9 - kimage_voffset;
    else
      v12 = memstart_addr + v10;
    v13 = iommu_debug_check_mapping_flags(a1, v11, 4096, v12, 0);
    if ( v13 )
      goto LABEL_26;
    dma_unmap_page_attrs(a1, v11, 1518, 1, 0);
    for ( i = 0; i != 1518; ++i )
    {
      if ( *((unsigned __int8 *)v7 + i) != 165 )
      {
        if ( (unsigned int)__ratelimit(&_functional_dma_api_basic_test__rs, "__functional_dma_api_basic_test") )
          dev_err(a1, "data[%d] != 0xa5\n", *((unsigned __int8 *)v7 + i));
        v13 = -22;
        goto LABEL_26;
      }
    }
    kfree(v7);
    if ( ++v5 != 1000 )
      continue;
    break;
  }
  v21 = a1[14];
  if ( !v21 )
    v21 = *a1;
  printk(&unk_CFA4, v21);
  v19 = 0;
  seq_printf(v22, "  -> SUCCEEDED\n");
  return v19;
}
