unsigned __int64 __fastcall adreno_profile_init(unsigned __int64 result)
{
  char v1; // w8
  unsigned __int64 v2; // x20
  _QWORD *v3; // x19
  unsigned __int64 v4; // x20

  v1 = *(_BYTE *)(result + 24024);
  v2 = result + 19728;
  *(_BYTE *)(result + 19728) = 0;
  if ( (v1 & 1) == 0 )
  {
    v3 = (_QWORD *)result;
    *(_DWORD *)(result + 19752) = 49152;
    result = kgsl_allocate_global(result, 196608, 0, 0, 0, (__int64)"profile");
    v3[2467] = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      v3[2460] = v3 + 2460;
      v3[2461] = v3 + 2460;
      result = debugfs_create_dir("profiling", v3[1397]);
      if ( result <= 0xFFFFFFFFFFFFF000LL )
      {
        v4 = result;
        debugfs_create_file("enable", 420, result, v3, &profile_enable_fops);
        debugfs_create_file("blocks", 292, v4, v3, &profile_groups_fops);
        debugfs_create_file("pipe", 292, v4, v3, &profile_pipe_fops);
        return debugfs_create_file("assignments", 420, v4, v3, &profile_assignments_fops);
      }
    }
    else
    {
      *(_DWORD *)(v2 + 24) = 0;
    }
  }
  return result;
}
