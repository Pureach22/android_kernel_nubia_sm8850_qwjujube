__int64 __fastcall _qdf_nbuf_unmap_tso_segment(__int64 result, __int64 a2, __int64 a3)
{
  __int64 v3; // x17
  unsigned int v4; // w25
  char v5; // w21
  __int64 v7; // x20
  unsigned int v8; // w22
  unsigned __int16 *v9; // x28
  __int64 v10; // x23
  __int64 v11; // x24
  __int64 v12; // x21
  __int64 v13; // x22

  v4 = *(_DWORD *)(a2 + 32);
  v5 = a3;
  v7 = result;
  if ( v4 >= 2 )
  {
    v8 = v4 - 1;
    do
    {
      if ( v4 >= 7 )
      {
        __break(0x5512u);
        return _qdf_nbuf_get_tcp_payload_len(result, *(unsigned int *)(v3 + 108), a3, *(unsigned int *)(v3 + 104));
      }
      v9 = (unsigned __int16 *)(a2 + 40 + 24LL * v8);
      v10 = *((_QWORD *)v9 + 2);
      if ( !v10 )
        return qdf_trace_msg(
                 56,
                 2,
                 "%s: ERROR: TSO seg frag %d mapped physical address is NULL",
                 "__qdf_nbuf_unmap_tso_segment",
                 v8);
      v11 = *v9;
      qdf_mem_dp_tx_skb_cnt_dec();
      qdf_mem_dp_tx_skb_dec(v11);
      qdf_mem_skb_total_dec(v11);
      result = dma_unmap_page_attrs(*(_QWORD *)(v7 + 40), v10, v11, 1, 0);
      --v8;
      *((_QWORD *)v9 + 2) = 0;
    }
    while ( v8 );
    if ( (v5 & 1) == 0 )
      return result;
  }
  else if ( v4 != 1 || (a3 & 1) == 0 )
  {
    return qdf_trace_msg(56, 2, "%s: ERROR: num of frags in a tso segment is %d", "__qdf_nbuf_unmap_tso_segment", 1);
  }
  v12 = *(_QWORD *)(a2 + 56);
  if ( !v12 )
    return qdf_trace_msg(
             56,
             2,
             "%s: ERROR: TSO seg frag 0 mapped physical address is NULL",
             "__qdf_nbuf_unmap_tso_segment");
  v13 = *(unsigned __int16 *)(a2 + 40);
  qdf_mem_dp_tx_skb_cnt_dec();
  qdf_mem_dp_tx_skb_dec(v13);
  qdf_mem_skb_total_dec(v13);
  result = dma_unmap_page_attrs(*(_QWORD *)(v7 + 40), v12, v13, 1, 0);
  *(_QWORD *)(a2 + 56) = 0;
  return result;
}
