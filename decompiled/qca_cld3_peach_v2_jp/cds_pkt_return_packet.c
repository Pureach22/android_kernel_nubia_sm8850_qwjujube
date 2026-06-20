__int64 __fastcall cds_pkt_return_packet(__int64 a1)
{
  __int64 v2; // x0

  if ( !a1 )
    return 4;
  v2 = *(_QWORD *)(a1 + 64);
  if ( v2 )
    _qdf_nbuf_free(v2);
  *(_QWORD *)(a1 + 64) = 0;
  _qdf_mem_free(a1);
  return 0;
}
