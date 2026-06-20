__int64 __fastcall util_scan_free_cache_entry_2(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0

  v2 = *(_QWORD *)(a1 + 1320);
  if ( v2 )
    _qdf_mem_free(v2);
  v3 = *(_QWORD *)(a1 + 1896);
  if ( v3 )
    _qdf_mem_free(v3);
  return _qdf_mem_free(a1);
}
