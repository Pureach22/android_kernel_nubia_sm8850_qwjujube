__int64 __fastcall mhi_map_single_no_bb(__int64 a1, __int64 *a2)
{
  __int64 v2; // x23
  const char **v3; // x20
  __int64 v5; // x21
  unsigned int v6; // w22
  char v7; // w0
  unsigned int v8; // w24
  __int64 v9; // x8
  char v10; // w24
  const char *v11; // x0
  const char *v12; // x2
  char v13; // w0

  v2 = *a2;
  v3 = *(const char ***)(a1 + 8);
  v5 = a2[5];
  v6 = *((_DWORD *)a2 + 12);
  v7 = is_vmalloc_addr(*a2);
  if ( (v7 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    v10 = v7;
    dma_map_single_attrs___already_done = 1;
    v11 = (const char *)dev_driver_string(v3);
    v12 = v3[14];
    if ( !v12 )
      v12 = *v3;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v11, v12);
    v13 = v10;
    __break(0x800u);
    v8 = -12;
    if ( (v13 & 1) != 0 )
      goto LABEL_4;
  }
  else
  {
    v8 = -12;
    if ( (v7 & 1) != 0 )
    {
LABEL_4:
      v9 = -1;
      goto LABEL_11;
    }
  }
  v9 = dma_map_page_attrs(
         v3,
         ((unsigned __int64)((v2 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
         v2 & 0xFFF,
         v5,
         v6,
         0);
  if ( v9 == -1 )
    v8 = -12;
  else
    v8 = 0;
LABEL_11:
  a2[4] = v9;
  return v8;
}
