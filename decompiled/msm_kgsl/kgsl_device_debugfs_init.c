__int64 __fastcall kgsl_device_debugfs_init(__int64 result)
{
  __int64 v1; // x19
  __int64 dir; // x0
  __int64 v3; // x0

  if ( kgsl_debugfs_dir )
  {
    if ( (unsigned __int64)kgsl_debugfs_dir <= 0xFFFFFFFFFFFFF000LL )
    {
      v1 = result;
      dir = debugfs_create_dir(*(_QWORD *)(result + 8), kgsl_debugfs_dir);
      *(_QWORD *)(v1 + 11176) = dir;
      debugfs_create_file("globals", 292, dir, v1, &globals_fops);
      v3 = debugfs_create_dir("snapshot", kgsl_debugfs_dir);
      return debugfs_create_file("break_isdb", 420, v3, v1, &isdb_fops);
    }
  }
  return result;
}
