__int64 __fastcall _qdf_nbuf_unmap_single(__int64 result, __int64 a2, int a3)
{
  __int64 v5; // x20
  __int64 v6; // x22
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x3
  __int64 v10; // x2

  v5 = result;
  if ( a3 && a3 != 2 && (a3 != 1 || *(_BYTE *)(result + 624) != 1)
    || (result = _qdf_is_pp_nbuf(a2), (result & 1) == 0)
    || !*(_QWORD *)(a2 + 40) )
  {
    if ( !*(_QWORD *)(a2 + 40) )
      return result;
    v6 = *(int *)(a2 + 212);
    if ( a3 == 2 )
    {
      qdf_mem_dp_rx_skb_cnt_dec();
      qdf_mem_dp_rx_skb_dec(v6);
      qdf_mem_skb_total_dec(v6);
      v7 = *(_QWORD *)(a2 + 216);
      v8 = *(_QWORD *)(a2 + 224);
      v9 = 2;
    }
    else
    {
      if ( a3 != 1 )
      {
        qdf_mem_skb_total_dec(*(int *)(a2 + 212));
        v10 = *(_QWORD *)(a2 + 216) + *(unsigned int *)(a2 + 212) - *(_QWORD *)(a2 + 224);
        if ( a3 )
          v9 = 3;
        else
          v9 = 0;
        return dma_unmap_page_attrs(*(_QWORD *)(v5 + 40), *(_QWORD *)(a2 + 40), v10, v9, 0);
      }
      qdf_mem_dp_tx_skb_cnt_dec();
      qdf_mem_dp_tx_skb_dec(v6);
      qdf_mem_skb_total_dec(v6);
      v7 = *(_QWORD *)(a2 + 216);
      v8 = *(_QWORD *)(a2 + 224);
      v9 = 1;
    }
    v10 = v7 + *(unsigned int *)(a2 + 212) - v8;
    return dma_unmap_page_attrs(*(_QWORD *)(v5 + 40), *(_QWORD *)(a2 + 40), v10, v9, 0);
  }
  result = *(_QWORD *)(v5 + 40);
  if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
    return _dma_sync_single_for_cpu();
  return result;
}
