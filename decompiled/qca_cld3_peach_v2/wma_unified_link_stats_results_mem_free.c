__int64 __fastcall wma_unified_link_stats_results_mem_free(__int64 result)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  __int64 *v3; // x21
  __int64 v4; // x0

  if ( result )
  {
    v1 = result;
    if ( *(_DWORD *)(result + 20) )
    {
      v2 = 0;
      v3 = (__int64 *)(result + 100);
      do
      {
        v4 = *(v3 - 2);
        if ( v4 )
        {
          _qdf_mem_free(v4);
          *(v3 - 2) = 0;
        }
        result = *v3;
        if ( *v3 )
        {
          result = _qdf_mem_free(result);
          *v3 = 0;
        }
        ++v2;
        v3 += 10;
      }
      while ( v2 < *(_DWORD *)(v1 + 20) );
    }
  }
  return result;
}
