__int64 __fastcall dma_map_single_attrs(const char **a1, __int64 a2, __int64 a3, __int64 a4)
{
  char v8; // w0
  char v10; // w23
  const char *v11; // x0
  const char *v12; // x2

  v8 = is_vmalloc_addr(a2);
  if ( (v8 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    v10 = v8;
    dma_map_single_attrs___already_done = 1;
    v11 = (const char *)dev_driver_string(a1);
    v12 = a1[14];
    if ( !v12 )
      v12 = *a1;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v11, v12);
    __break(0x800u);
    if ( (v10 & 1) != 0 )
      return -1;
  }
  else if ( (v8 & 1) != 0 )
  {
    return -1;
  }
  return dma_map_page_attrs(
           a1,
           ((unsigned __int64)((a2 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
           a2 & 0xFFF,
           a3,
           1,
           a4);
}
