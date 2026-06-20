__int64 __fastcall dp_rx_nbuf_prepare(__int64 a1, __int64 a2)
{
  unsigned int v4; // w26
  _DWORD *v5; // x27
  _DWORD *v6; // x28
  __int64 v7; // x0
  __int64 v8; // x22
  __int64 v9; // x24
  __int64 v10; // x25
  const char **v11; // x24
  char v12; // w0
  _DWORD *v13; // x8
  const char *v14; // x0
  const char *v15; // x2
  __int64 v16; // x0
  __int64 v17; // x19
  char v19; // [xsp+Ch] [xbp-4h]

  v4 = 0;
  v5 = (_DWORD *)(a2 + 444);
  v6 = (_DWORD *)(a2 + 436);
  while ( 1 )
  {
    v7 = _qdf_nbuf_alloc_no_recycler(1408, 128, 128);
    if ( v7 )
      break;
    v13 = v6;
    if ( a2 )
      goto LABEL_12;
LABEL_13:
    if ( ++v4 == 20 )
      return 0;
  }
  v8 = v7;
  memset(*(void **)(v7 + 224), 0, 0x580u);
  v9 = *(_QWORD *)(a1 + 24);
  if ( (_qdf_is_pp_nbuf(v8) & 1) == 0 || !*(_QWORD *)(v8 + 40) )
  {
    v10 = *(_QWORD *)(v8 + 224);
    v11 = *(const char ***)(v9 + 40);
    v12 = is_vmalloc_addr(v10);
    if ( (v12 & 1) != 0 && (dma_map_single_attrs___already_done_4 & 1) == 0 )
    {
      v19 = v12;
      dma_map_single_attrs___already_done_4 = 1;
      v14 = (const char *)dev_driver_string(v11);
      v15 = v11[14];
      if ( !v15 )
        v15 = *v11;
      _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v14, v15);
      __break(0x800u);
      if ( (v19 & 1) != 0 )
        goto LABEL_8;
    }
    else if ( (v12 & 1) != 0 )
    {
LABEL_8:
      *(_QWORD *)(v8 + 40) = -1;
      goto LABEL_9;
    }
    v16 = dma_map_page_attrs(
            v11,
            ((unsigned __int64)((v10 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
            v10 & 0xFFF,
            1408,
            2,
            0);
    *(_QWORD *)(v8 + 40) = v16;
    if ( v16 != -1 )
    {
      v17 = *(int *)(v8 + 212);
      qdf_mem_dp_rx_skb_cnt_inc();
      qdf_mem_dp_rx_skb_inc(v17);
      qdf_mem_skb_total_inc(v17);
      goto LABEL_20;
    }
LABEL_9:
    _qdf_nbuf_free(v8);
    v13 = v5;
    if ( !a2 )
      goto LABEL_13;
LABEL_12:
    ++*v13;
    goto LABEL_13;
  }
  if ( (*(_BYTE *)(*(_QWORD *)(v9 + 40) + 844LL) & 0x40) == 0 )
    _dma_sync_single_for_device();
LABEL_20:
  if ( v4 < 0x14 )
    return v8;
  return 0;
}
