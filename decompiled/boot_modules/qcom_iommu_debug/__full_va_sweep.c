__int64 __fastcall _full_va_sweep(const char **a1, __int64 a2, unsigned __int64 a3)
{
  unsigned int v6; // w9
  __int64 v7; // x1
  __int64 free_pages_noprof; // x0
  __int64 v9; // x21
  __int64 v10; // x8
  unsigned __int64 v11; // x12
  unsigned __int64 v12; // x15
  __int64 v13; // x9
  __int64 v14; // x8
  unsigned __int64 v15; // x25
  int v16; // w27
  int v17; // w26
  __int64 v18; // x24
  char v19; // w0
  __int64 v20; // x0
  const char *v21; // x0
  const char *v22; // x2
  __int64 v23; // x22
  unsigned __int64 v24; // x26
  int v25; // w25
  unsigned __int64 v26; // x22
  unsigned __int64 v27; // x26
  char v28; // w0
  __int64 v29; // x0
  __int64 v30; // x22
  void *v31; // x0
  unsigned int v32; // w22
  unsigned __int64 v33; // x23
  int v34; // w24
  unsigned __int64 v35; // x8
  unsigned int v36; // w9
  __int64 v37; // x1
  char v38; // w22
  const char *v39; // x0
  const char *v40; // x2
  const char *v42; // x0
  char v43; // [xsp+Ch] [xbp-14h]
  __int64 v44; // [xsp+18h] [xbp-8h]

  v6 = 64 - __clz((a3 - 1) >> 12);
  if ( a3 - 1 >= 0x1000 )
    v7 = v6;
  else
    v7 = 0;
  free_pages_noprof = get_free_pages_noprof(3264, v7);
  v9 = free_pages_noprof;
  if ( !free_pages_noprof )
  {
    if ( a3 <= 0x2000 )
    {
      return (unsigned int)-12;
    }
    else
    {
      if ( (unsigned int)__ratelimit(&_full_va_sweep__rs, "__full_va_sweep") )
      {
        v42 = size_to_string(a3);
        dev_err(a1, "Failed to allocate %s of memory, which is a lot. Skipping test for this size\n", v42);
      }
      return 0;
    }
  }
  v10 = free_pages_noprof << 8 >> 8;
  v11 = (unsigned __int64)(v10 + 0x8000000000LL) >> 38;
  v12 = (unsigned __int64)(v10 + 0x8000000000LL) >> 12;
  v13 = memstart_addr + v10 + 0x8000000000LL;
  v14 = v10 - kimage_voffset;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  if ( v11 )
    v18 = v14;
  else
    v18 = v13;
  v44 = (v12 << 6) - 0x140000000LL;
  do
  {
    if ( v15 == 0x8000000 )
    {
      v15 = 135266304 - a3;
    }
    else
    {
      v19 = is_vmalloc_addr(v9);
      if ( (v19 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
      {
        v43 = v19;
        dma_map_single_attrs___already_done = 1;
        v21 = (const char *)dev_driver_string(a1);
        v22 = a1[14];
        if ( !v22 )
          v22 = *a1;
        _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v21, v22);
        __break(0x800u);
        if ( (v43 & 1) != 0 )
        {
LABEL_20:
          v23 = -1;
          goto LABEL_35;
        }
      }
      else if ( (v19 & 1) != 0 )
      {
        goto LABEL_20;
      }
      v20 = dma_map_page_attrs(a1, v44, v9 & 0xFFF, a3, 1, 0);
      if ( v20 != v15 )
      {
        v23 = v20;
LABEL_35:
        if ( (unsigned int)__ratelimit(&_full_va_sweep__rs_101, "__full_va_sweep") )
        {
          dev_err(a1, "Unexpected iova on iter %d (expected: 0x%lx got: 0x%lx)\n", v17, v15, v23);
          if ( v23 != -1 )
LABEL_37:
            dma_unmap_page_attrs(a1, v23, a3, 1, 0);
        }
        else if ( v23 != -1 )
        {
          goto LABEL_37;
        }
LABEL_42:
        v32 = -22;
        goto LABEL_43;
      }
      ++v16;
    }
    v15 += a3;
    ++v17;
  }
  while ( v15 < 0xFFFFFFFF );
  if ( a2 )
  {
    v24 = 0;
    v25 = 0;
    do
    {
      if ( (unsigned int)_check_mapping(a1, a2, v24, v18) )
      {
        v31 = &_full_va_sweep__rs_103;
        goto LABEL_40;
      }
      v24 += a3;
      ++v25;
    }
    while ( v24 < 0x600000 );
    v26 = 0;
    v25 = 0;
    v27 = 0x100000000LL - a3;
    while ( !(unsigned int)_check_mapping(a1, a2, v27, v18) )
    {
      v26 += a3;
      ++v25;
      v27 -= a3;
      if ( v26 >= 0x600000 )
        goto LABEL_28;
    }
    v31 = &_full_va_sweep__rs_105;
LABEL_40:
    if ( (unsigned int)__ratelimit(v31, "__full_va_sweep") )
      dev_err(a1, "iter: %d\n", v25);
    goto LABEL_42;
  }
LABEL_28:
  v28 = is_vmalloc_addr(v9);
  if ( (v28 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    v38 = v28;
    dma_map_single_attrs___already_done = 1;
    v39 = (const char *)dev_driver_string(a1);
    v40 = a1[14];
    if ( !v40 )
      v40 = *a1;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v39, v40);
    __break(0x800u);
    if ( (v38 & 1) == 0 )
    {
LABEL_31:
      v29 = dma_map_page_attrs(a1, v44, v9 & 0xFFF, a3, 1, 0);
      if ( v29 != -1 )
      {
        v30 = v29;
        if ( (unsigned int)__ratelimit(&_full_va_sweep__rs_106, "__full_va_sweep") )
          dev_err(a1, "dma_map_single succeeded when it should have failed. Got iova: 0x%lx\n", v30);
        goto LABEL_42;
      }
    }
  }
  else if ( (v28 & 1) == 0 )
  {
    goto LABEL_31;
  }
  v32 = 0;
LABEL_43:
  v33 = 0;
  v34 = v16 + 1;
  do
  {
    if ( !--v34 )
      break;
    v35 = 135266304 - a3;
    if ( v33 != 0x8000000 )
    {
      dma_unmap_page_attrs(a1, v33, a3, 1, 0);
      v35 = v33;
    }
    v33 = v35 + a3;
  }
  while ( v35 + a3 < 0xFFFFFFFF );
  v36 = 64 - __clz((a3 - 1) >> 12);
  if ( a3 - 1 >= 0x1000 )
    v37 = v36;
  else
    v37 = 0;
  free_pages(v9, v37);
  return v32;
}
