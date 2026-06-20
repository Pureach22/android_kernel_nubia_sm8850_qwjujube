__int64 __fastcall util_scan_free_cache_entry_1(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x0
  __int64 v3; // x0

  if ( result )
  {
    v1 = result;
    v2 = *(_QWORD *)(result + 1320);
    if ( v2 )
      _qdf_mem_free(v2);
    v3 = *(_QWORD *)(v1 + 1896);
    if ( v3 )
      _qdf_mem_free(v3);
    return _qdf_mem_free(v1);
  }
  return result;
}
