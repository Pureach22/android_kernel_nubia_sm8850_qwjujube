__int64 __fastcall htt_soc_htc_prealloc(__int64 a1)
{
  int v2; // w21
  __int64 v3; // x0

  v2 = 64;
  *(_QWORD *)(a1 + 72) = 0;
  while ( 1 )
  {
    v3 = _qdf_mem_malloc(0x80u, "htt_soc_htc_prealloc", 5166);
    if ( !v3 )
      break;
    htt_htc_pkt_free(a1, v3);
    if ( !--v2 )
      return 0;
  }
  return 2;
}
