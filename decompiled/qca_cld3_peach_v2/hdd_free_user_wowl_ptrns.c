__int64 hdd_free_user_wowl_ptrns()
{
  __int64 i; // x20
  __int64 v1; // x0
  __int64 j; // x20
  __int64 v3; // x0
  __int64 k; // x20
  __int64 v5; // x0
  __int64 m; // x20
  __int64 v7; // x0
  __int64 n; // x20
  __int64 v9; // x0
  __int64 ii; // x20
  __int64 result; // x0

  for ( i = 0; i != 256; i += 8 )
  {
    v1 = *(_QWORD *)((char *)&g_hdd_wowl_ptrns + i);
    if ( v1 )
    {
      _qdf_mem_free(v1);
      *(_QWORD *)((char *)&g_hdd_wowl_ptrns + i) = 0;
    }
  }
  for ( j = 0; j != 256; j += 8 )
  {
    v3 = *(_QWORD *)((char *)&g_hdd_wowl_ptrns + j + 256);
    if ( v3 )
    {
      _qdf_mem_free(v3);
      *(_QWORD *)((char *)&g_hdd_wowl_ptrns + j + 256) = 0;
    }
  }
  for ( k = 0; k != 256; k += 8 )
  {
    v5 = *(_QWORD *)((char *)&g_hdd_wowl_ptrns + k + 512);
    if ( v5 )
    {
      _qdf_mem_free(v5);
      *(_QWORD *)((char *)&g_hdd_wowl_ptrns + k + 512) = 0;
    }
  }
  for ( m = 0; m != 256; m += 8 )
  {
    v7 = *(_QWORD *)((char *)&g_hdd_wowl_ptrns + m + 768);
    if ( v7 )
    {
      _qdf_mem_free(v7);
      *(_QWORD *)((char *)&g_hdd_wowl_ptrns + m + 768) = 0;
    }
  }
  for ( n = 0; n != 256; n += 8 )
  {
    v9 = *(_QWORD *)((char *)&g_hdd_wowl_ptrns + n + 1024);
    if ( v9 )
    {
      _qdf_mem_free(v9);
      *(_QWORD *)((char *)&g_hdd_wowl_ptrns + n + 1024) = 0;
    }
  }
  for ( ii = 0; ii != 256; ii += 8 )
  {
    result = *(_QWORD *)((char *)&g_hdd_wowl_ptrns + ii + 1280);
    if ( result )
    {
      result = _qdf_mem_free(result);
      *(_QWORD *)((char *)&g_hdd_wowl_ptrns + ii + 1280) = 0;
    }
  }
  return result;
}
