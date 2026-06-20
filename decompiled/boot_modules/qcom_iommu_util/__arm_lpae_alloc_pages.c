unsigned __int64 __fastcall _arm_lpae_alloc_pages(__int64 a1, __int64 a2, int a3, __int64 a4)
{
  const char **v4; // x20
  __int64 v7; // x0
  __int64 v8; // x8
  unsigned __int64 v9; // x22
  __int64 v10; // x21
  char v11; // w0
  char v12; // w23
  const char *v13; // x0
  const char *v14; // x2
  __int64 v15; // x23
  unsigned __int64 v16; // x24
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v20; // x22

  v4 = *(const char ***)(a4 + 48);
  v7 = qcom_io_pgtable_alloc_page(*(unsigned int *)(a1 + 224), a3 | 0x100u);
  if ( !v7 )
    return 0;
  v8 = ((v7 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL;
  v9 = v8 | 0xFF00000000000000LL;
  if ( (*(_BYTE *)(a4 + 32) & 1) == 0 )
  {
    v10 = v7;
    v11 = is_vmalloc_addr(v8 | 0xFF00000000000000LL);
    if ( (v11 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
    {
      v12 = v11;
      dma_map_single_attrs___already_done = 1;
      v13 = (const char *)dev_driver_string(v4);
      v14 = v4[14];
      if ( !v14 )
        v14 = *v4;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v13, v14);
      __break(0x800u);
      if ( (v12 & 1) != 0 )
        goto LABEL_6;
    }
    else if ( (v11 & 1) != 0 )
    {
LABEL_6:
      qcom_io_pgtable_free_page(v10);
      return 0;
    }
    v15 = (__int64)(v9 << 8) >> 8;
    v16 = v15 + 0x8000000000LL;
    v17 = dma_map_page_attrs(v4, ((unsigned __int64)(v15 + 0x8000000000LL) >> 12 << 6) - 0x140000000LL, 0, a2, 1, 0);
    if ( v17 == -1 )
      goto LABEL_6;
    v18 = memstart_addr + v16;
    if ( v16 >> 38 )
      v18 = v15 - kimage_voffset;
    if ( v17 != v18 )
    {
      v20 = v17;
      dev_err(v4, "Cannot accommodate DMA translation for IOMMU page tables\n");
      dma_unmap_page_attrs(v4, v20, a2, 1, 0);
      goto LABEL_6;
    }
  }
  return v9;
}
