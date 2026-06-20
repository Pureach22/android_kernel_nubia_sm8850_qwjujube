__int64 __fastcall dma_map_single_attrs(const char **a1, __int64 a2, __int64 a3)
{
  char v6; // w0
  char v8; // w22
  const char *v9; // x0
  const char *v10; // x2

  v6 = is_vmalloc_addr(a2);
  if ( (v6 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    v8 = v6;
    dma_map_single_attrs___already_done = 1;
    v9 = (const char *)dev_driver_string(a1);
    v10 = a1[14];
    if ( !v10 )
      v10 = *a1;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v9, v10);
    __break(0x800u);
    if ( (v8 & 1) != 0 )
      return -1;
  }
  else if ( (v6 & 1) != 0 )
  {
    return -1;
  }
  return dma_map_page_attrs(
           a1,
           ((unsigned __int64)((a2 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
           a2 & 0xFFF,
           a3,
           1,
           0);
}
