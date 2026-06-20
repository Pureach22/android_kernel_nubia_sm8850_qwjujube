__int64 __fastcall qdf_nbuf_map_nbytes_single(__int64 a1, __int64 a2, int a3)
{
  __int64 v6; // x22
  const char **v7; // x21
  char v8; // w0
  char v10; // w23
  const char *v11; // x0
  const char *v12; // x2
  __int64 v13; // x0
  __int64 v14; // x19

  if ( *(_BYTE *)(a1 + 624) == 1 && (_qdf_is_pp_nbuf(a2) & 1) != 0 && *(_QWORD *)(a2 + 40) )
  {
    if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 844LL) & 0x40) == 0 )
      _dma_sync_single_for_device();
    return 0;
  }
  v6 = *(_QWORD *)(a2 + 224);
  v7 = *(const char ***)(a1 + 40);
  v8 = is_vmalloc_addr(v6);
  if ( (v8 & 1) != 0 && (dma_map_single_attrs___already_done_2 & 1) == 0 )
  {
    v10 = v8;
    dma_map_single_attrs___already_done_2 = 1;
    v11 = (const char *)dev_driver_string(v7);
    v12 = v7[14];
    if ( !v12 )
      v12 = *v7;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v11, v12);
    __break(0x800u);
    if ( (v10 & 1) != 0 )
      goto LABEL_9;
  }
  else if ( (v8 & 1) != 0 )
  {
LABEL_9:
    *(_QWORD *)(a2 + 40) = -1;
    return 5;
  }
  v13 = dma_map_page_attrs(
          v7,
          ((unsigned __int64)((v6 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
          v6 & 0xFFF,
          a3,
          1,
          0);
  *(_QWORD *)(a2 + 40) = v13;
  if ( v13 == -1 )
    return 5;
  v14 = *(int *)(a2 + 212);
  qdf_mem_dp_tx_skb_cnt_inc();
  qdf_mem_dp_tx_skb_inc(v14);
  qdf_mem_skb_total_inc(v14);
  return 0;
}
