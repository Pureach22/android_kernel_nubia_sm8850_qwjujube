__int64 __fastcall htc_free_control_tx_packet(__int64 a1, __int64 a2)
{
  __int64 v2; // x0

  v2 = *(_QWORD *)(a2 + 96);
  if ( v2 )
    _qdf_nbuf_free(v2);
  return _qdf_mem_free(a2);
}
