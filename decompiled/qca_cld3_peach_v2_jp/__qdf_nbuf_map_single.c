__int64 __fastcall _qdf_nbuf_map_single(__int64 a1, __int64 a2, unsigned int a3)
{
  int *v6; // x25
  __int64 v7; // x21
  __int64 v8; // x22
  unsigned int v9; // w23
  const char **v10; // x24
  char v11; // w0
  char v13; // w26
  const char *v14; // x0
  const char *v15; // x2
  __int64 v16; // x0
  __int64 v17; // x20

  if ( !a3 || a3 == 2 )
  {
LABEL_5:
    if ( (_qdf_is_pp_nbuf(a2) & 1) != 0 && *(_QWORD *)(a2 + 40) )
    {
      if ( (*(_BYTE *)(*(_QWORD *)(a1 + 40) + 844LL) & 0x40) == 0 )
        _dma_sync_single_for_device();
      return 0;
    }
    goto LABEL_9;
  }
  if ( a3 == 1 )
  {
    if ( (*(_BYTE *)(a1 + 624) & 1) == 0 )
    {
      v9 = 1;
      v6 = (int *)(a2 + 212);
      v7 = *(_QWORD *)(a2 + 224);
      v8 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) - v7;
      goto LABEL_12;
    }
    goto LABEL_5;
  }
LABEL_9:
  v6 = (int *)(a2 + 212);
  v7 = *(_QWORD *)(a2 + 224);
  v8 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) - v7;
  if ( a3 >= 3 )
    v9 = 3;
  else
    v9 = a3;
LABEL_12:
  v10 = *(const char ***)(a1 + 40);
  v11 = is_vmalloc_addr(v7);
  if ( (v11 & 1) != 0 && (dma_map_single_attrs___already_done & 1) == 0 )
  {
    v13 = v11;
    dma_map_single_attrs___already_done = 1;
    v14 = (const char *)dev_driver_string(v10);
    v15 = v10[14];
    if ( !v15 )
      v15 = *v10;
    _warn_printk("%s %s: rejecting DMA map of vmalloc memory\n", v14, v15);
    __break(0x800u);
    if ( (v13 & 1) != 0 )
      goto LABEL_15;
  }
  else if ( (v11 & 1) != 0 )
  {
LABEL_15:
    *(_QWORD *)(a2 + 40) = -1;
    return 16;
  }
  v16 = dma_map_page_attrs(
          v10,
          ((unsigned __int64)((v7 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
          v7 & 0xFFF,
          v8,
          v9,
          0);
  *(_QWORD *)(a2 + 40) = v16;
  if ( v16 != -1 )
  {
    v17 = *v6;
    if ( a3 == 1 )
    {
      qdf_mem_dp_tx_skb_cnt_inc();
      qdf_mem_dp_tx_skb_inc(v17);
    }
    else if ( a3 == 2 )
    {
      qdf_mem_dp_rx_skb_cnt_inc();
      qdf_mem_dp_rx_skb_inc(v17);
    }
    qdf_mem_skb_total_inc(v17);
    return 0;
  }
  return 16;
}
