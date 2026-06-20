__int64 __fastcall dma_map_single_attrs(const char **a1, __int64 a2)
{
  char v4; // w0
  char v6; // w21
  const char *v7; // x0
  const char *v8; // x2

  v4 = is_vmalloc_addr(a2);
  if ( (v4 & 1) != 0 && (dma_map_single_attrs___already_done_0 & 1) == 0 )
  {
    v6 = v4;
    dma_map_single_attrs___already_done_0 = 1;
    v7 = (const char *)dev_driver_string(a1);
    v8 = a1[14];
    if ( !v8 )
      v8 = *a1;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v7, v8);
    __break(0x800u);
    if ( (v6 & 1) != 0 )
      return -1;
  }
  else if ( (v4 & 1) != 0 )
  {
    return -1;
  }
  return dma_map_page_attrs(
           a1,
           ((unsigned __int64)((a2 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
           a2 & 0xFFF,
           56,
           1,
           0);
}
