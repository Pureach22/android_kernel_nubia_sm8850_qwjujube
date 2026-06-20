__int64 __fastcall _qdf_nbuf_map_nbytes(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  unsigned int v8; // w22
  __int64 v9; // x24
  const char **v10; // x23
  char v11; // w0
  char v13; // w25
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
    if ( *(_BYTE *)(a1 + 624) != 1 )
    {
      v8 = 1;
      goto LABEL_12;
    }
    goto LABEL_5;
  }
LABEL_9:
  if ( a3 >= 3 )
    v8 = 3;
  else
    v8 = a3;
LABEL_12:
  v9 = *(_QWORD *)(a2 + 224);
  v10 = *(const char ***)(a1 + 40);
  v11 = is_vmalloc_addr(v9);
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
    return 5;
  }
  v16 = dma_map_page_attrs(
          v10,
          ((unsigned __int64)((v9 << 8 >> 8) + 0x8000000000LL) >> 12 << 6) - 0x140000000LL,
          v9 & 0xFFF,
          a4,
          v8,
          0);
  *(_QWORD *)(a2 + 40) = v16;
  if ( v16 != -1 )
  {
    v17 = *(int *)(a2 + 212);
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
  return 5;
}
