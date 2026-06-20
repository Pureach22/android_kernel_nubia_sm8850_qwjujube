__int64 __fastcall dp_tx_ipa_uc_detach(__int64 a1)
{
  unsigned int v2; // w8
  int v3; // w9
  __int64 v4; // x10
  __int64 v5; // x22
  __int64 v6; // x20

  v2 = *(_DWORD *)(a1 + 18072);
  if ( v2 )
  {
    v3 = 0;
    do
    {
      v4 = *(_QWORD *)(a1 + 18120);
      v5 = v3;
      v6 = *(_QWORD *)(v4 + 8LL * v3);
      if ( v6 )
      {
        _qdf_nbuf_unmap_single(*(_QWORD *)(a1 + 24), *(_QWORD *)(v4 + 8LL * v3), 0);
        qdf_mem_dp_tx_skb_cnt_dec();
        qdf_mem_dp_tx_skb_dec(*(unsigned int *)(v6 + 212));
        _qdf_nbuf_free(v6);
        *(_QWORD *)(*(_QWORD *)(a1 + 18120) + 8 * v5) = 0;
        v2 = *(_DWORD *)(a1 + 18072);
      }
      v3 = v5 + 1;
    }
    while ( (int)v5 + 1 < v2 );
  }
  _qdf_mem_free(*(_QWORD *)(a1 + 18120));
  *(_QWORD *)(a1 + 18120) = 0;
  sg_free_table(a1 + 18248);
  return sg_free_table(a1 + 18320);
}
