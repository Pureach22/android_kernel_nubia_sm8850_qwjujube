__int64 __fastcall etm_perf_del_symlink_sink(__int64 result)
{
  __int64 v1; // x1
  __int64 v2; // x19

  if ( (*(_DWORD *)(result + 8) | 2) == 2 )
  {
    v1 = *(_QWORD *)(result + 984);
    v2 = result;
    if ( v1 )
    {
      result = sysfs_remove_file_from_group(qword_11970, v1, "sinks");
      *(_QWORD *)(v2 + 984) = 0;
    }
  }
  return result;
}
