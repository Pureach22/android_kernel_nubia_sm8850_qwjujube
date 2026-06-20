__int64 __fastcall _qdf_nbuf_unmap_nbytes(__int64 result, __int64 a2, int a3, int a4)
{
  __int64 v4; // x19
  __int64 v8; // x21
  __int64 v9; // x23
  __int64 v10; // x3

  v4 = *(_QWORD *)(a2 + 40);
  v8 = result;
  if ( (!a3 || a3 == 2 || a3 == 1 && *(_BYTE *)(result + 624) == 1)
    && (result = _qdf_is_pp_nbuf(a2), (result & 1) != 0)
    && *(_QWORD *)(a2 + 40) )
  {
    result = *(_QWORD *)(v8 + 40);
    if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
      return _dma_sync_single_for_cpu();
  }
  else if ( v4 )
  {
    v9 = *(int *)(a2 + 212);
    if ( a3 == 2 )
    {
      qdf_mem_dp_rx_skb_cnt_dec();
      qdf_mem_dp_rx_skb_dec(v9);
      qdf_mem_skb_total_dec(v9);
      v10 = 2;
    }
    else if ( a3 == 1 )
    {
      qdf_mem_dp_tx_skb_cnt_dec();
      qdf_mem_dp_tx_skb_dec(v9);
      qdf_mem_skb_total_dec(v9);
      v10 = 1;
    }
    else
    {
      qdf_mem_skb_total_dec(v9);
      if ( a3 )
        v10 = 3;
      else
        v10 = 0;
    }
    return dma_unmap_page_attrs(*(_QWORD *)(v8 + 40), v4, a4, v10, 0);
  }
  return result;
}
