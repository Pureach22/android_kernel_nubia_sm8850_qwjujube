__int64 __fastcall extract_peer_tx_pkt_per_mcs_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        unsigned int a11,
        __int64 a12)
{
  __int64 v12; // x5
  __int64 v16; // x0
  unsigned int v17; // w8

  v12 = *(unsigned int *)(a12 + 100);
  if ( (unsigned int)v12 + a11 <= *(_DWORD *)(a10 + 40) )
  {
    v16 = _qdf_mem_malloc(4 * v12, "extract_peer_tx_pkt_per_mcs_tlv", 398);
    *(_QWORD *)(a12 + 112) = v16;
    if ( !v16 )
      return 2;
    if ( *(_DWORD *)(a12 + 100) )
    {
      v17 = 0;
      do
      {
        *(_DWORD *)(*(_QWORD *)(a12 + 112) + 4LL * (int)v17) = *(_DWORD *)(*(_QWORD *)(a10 + 32) + 4LL
                                                                                                 * (int)(a11 + v17));
        ++v17;
      }
      while ( v17 < *(_DWORD *)(a12 + 100) );
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: invalid idx %d curr peer tx_rate_counts %d total tx_rate_count %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_peer_tx_pkt_per_mcs_tlv",
      a11);
  }
  return 0;
}
