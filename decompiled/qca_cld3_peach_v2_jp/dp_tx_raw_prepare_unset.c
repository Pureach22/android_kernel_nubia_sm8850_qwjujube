__int64 __fastcall dp_tx_raw_prepare_unset(__int64 result, __int64 *a2)
{
  __int64 v3; // x20
  __int64 v4; // x24
  __int64 v5; // x21
  __int64 v6; // x22
  __int64 v7; // x23

  v3 = result;
  do
  {
    v4 = *(_QWORD *)(v3 + 24);
    v5 = *((int *)a2 + 28);
    v6 = a2[5];
    if ( *(_BYTE *)(v4 + 624) == 1 && (result = _qdf_is_pp_nbuf(a2), (result & 1) != 0) && a2[5] )
    {
      result = *(_QWORD *)(v4 + 40);
      if ( (*(_BYTE *)(result + 844) & 0x40) == 0 )
        result = _dma_sync_single_for_cpu(result, v6);
    }
    else if ( v6 )
    {
      v7 = *((int *)a2 + 53);
      qdf_mem_dp_tx_skb_cnt_dec();
      qdf_mem_dp_tx_skb_dec(v7);
      qdf_mem_skb_total_dec(v7);
      result = dma_unmap_page_attrs(*(_QWORD *)(v4 + 40), v6, v5, 1, 0);
    }
    a2 = (__int64 *)*a2;
  }
  while ( a2 );
  return result;
}
