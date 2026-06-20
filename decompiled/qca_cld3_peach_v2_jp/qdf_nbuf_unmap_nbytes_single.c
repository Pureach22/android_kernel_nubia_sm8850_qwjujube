__int64 __fastcall qdf_nbuf_unmap_nbytes_single(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x19
  __int64 v5; // x21
  __int64 v7; // x22

  v3 = *(_QWORD *)(a2 + 40);
  v5 = result;
  if ( *(_BYTE *)(result + 624) == 1 && (result = _qdf_is_pp_nbuf(a2), (result & 1) != 0) && *(_QWORD *)(a2 + 40) )
  {
    result = *(_QWORD *)(v5 + 40);
    if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
      return _dma_sync_single_for_cpu(result, v3);
  }
  else if ( v3 )
  {
    v7 = *(int *)(a2 + 212);
    qdf_mem_dp_tx_skb_cnt_dec();
    qdf_mem_dp_tx_skb_dec(v7);
    qdf_mem_skb_total_dec(v7);
    return dma_unmap_page_attrs(*(_QWORD *)(v5 + 40), v3, a3, 1, 0);
  }
  return result;
}
