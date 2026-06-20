__int64 *__fastcall hdd_roam_scan_stats_debugfs_dealloc(__int64 *result)
{
  __int64 v1; // x8

  if ( result )
  {
    v1 = *result;
    *result = 0;
    return (__int64 *)_qdf_mem_free(v1);
  }
  return result;
}
