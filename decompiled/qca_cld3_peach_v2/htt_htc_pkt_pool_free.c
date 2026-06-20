_QWORD *__fastcall htt_htc_pkt_pool_free(__int64 a1)
{
  _QWORD *result; // x0
  _QWORD *v3; // x20

  result = *(_QWORD **)(a1 + 72);
  if ( result )
  {
    do
    {
      v3 = (_QWORD *)*result;
      _qdf_mem_free((__int64)result);
      result = v3;
    }
    while ( v3 );
  }
  *(_QWORD *)(a1 + 72) = 0;
  return result;
}
