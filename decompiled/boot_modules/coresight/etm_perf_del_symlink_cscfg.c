__int64 __fastcall etm_perf_del_symlink_cscfg(__int64 result)
{
  __int64 v1; // x1
  __int64 v2; // x19

  v1 = *(_QWORD *)(result + 64);
  if ( v1 )
  {
    v2 = result;
    result = sysfs_remove_file_from_group(qword_11970, v1, "events");
    *(_QWORD *)(v2 + 64) = 0;
  }
  return result;
}
