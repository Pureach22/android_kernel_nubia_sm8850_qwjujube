__int64 __fastcall _wma_unified_radio_tx_mem_free(__int64 a1)
{
  __int64 v1; // x20
  unsigned int v3; // w21
  __int64 *v4; // x22
  __int64 v5; // x0
  __int64 result; // x0

  v1 = *(_QWORD *)(a1 + 3808);
  if ( v1 && *(_DWORD *)(v1 + 20) )
  {
    v3 = 0;
    v4 = (__int64 *)(v1 + 100);
    do
    {
      v5 = *(v4 - 2);
      if ( v5 )
      {
        _qdf_mem_free(v5);
        *(v4 - 2) = 0;
      }
      if ( *v4 )
      {
        _qdf_mem_free(*v4);
        *v4 = 0;
      }
      ++v3;
      v4 += 10;
    }
    while ( v3 < *(_DWORD *)(v1 + 20) );
    v1 = *(_QWORD *)(a1 + 3808);
  }
  result = _qdf_mem_free(v1);
  *(_QWORD *)(a1 + 3808) = 0;
  return result;
}
