__int64 __fastcall qdf_nbuf_unmap_nbytes_single_0(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x19
  __int64 result; // x0
  __int64 v8; // x22

  v3 = *(_QWORD *)(a2 + 40);
  result = _qdf_is_pp_nbuf(a2);
  if ( (result & 1) != 0 && *(_QWORD *)(a2 + 40) )
  {
    result = *(_QWORD *)(a1 + 40);
    if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
      return _dma_sync_single_for_cpu(result, v3);
  }
  else if ( v3 )
  {
    v8 = *(int *)(a2 + 212);
    qdf_mem_dp_rx_skb_cnt_dec();
    qdf_mem_dp_rx_skb_dec(v8);
    qdf_mem_skb_total_dec(v8);
    return dma_unmap_page_attrs(*(_QWORD *)(a1 + 40), v3, a3, 2, 0);
  }
  return result;
}
