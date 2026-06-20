_QWORD *__fastcall ucfg_mc_cp_stats_free_stats_resources(_QWORD *result)
{
  _QWORD *v1; // x19
  __int64 v2; // x0
  int v3; // w20
  __int64 *v4; // x21
  __int64 v5; // t1
  __int64 v6; // x0

  if ( result )
  {
    v1 = result;
    _qdf_mem_free(result[1]);
    _qdf_mem_free(v1[3]);
    _qdf_mem_free(v1[7]);
    _qdf_mem_free(v1[5]);
    _qdf_mem_free(v1[10]);
    _qdf_mem_free(v1[12]);
    _qdf_mem_free(v1[16]);
    _qdf_mem_free(v1[9]);
    v2 = v1[20];
    if ( *((_DWORD *)v1 + 39) )
    {
      v3 = 0;
      v4 = (__int64 *)(v2 + 120);
      do
      {
        _qdf_mem_free(*(v4 - 1));
        v5 = *v4;
        v4 += 17;
        _qdf_mem_free(v5);
        ++v3;
      }
      while ( *((_DWORD *)v1 + 39) > (unsigned int)(unsigned __int16)v3 );
      v2 = v1[20];
    }
    _qdf_mem_free(v2);
    _qdf_mem_free(v1[24]);
    v6 = v1[26];
    if ( v6 )
      _qdf_mem_free(v6);
    return qdf_mem_set(v1, 0xD8u, 0);
  }
  return result;
}
