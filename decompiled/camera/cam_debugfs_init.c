unsigned __int64 cam_debugfs_init()
{
  const char *v0; // x5
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 v3; // x4
  unsigned __int64 result; // x0

  if ( cam_debugfs_root )
  {
    v0 = "already created debugfs root";
    v1 = 0x20000;
    v2 = 2;
    v3 = 50;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v1,
             v2,
             "cam_debugfs_init",
             v3,
             v0);
  }
  result = debugfs_create_dir("camera", 0);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             0x20000,
             1,
             "cam_debugfs_init",
             56,
             "failed to create debugfs root folder (rc=%d)",
             result);
  cam_debugfs_root = result;
  if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
  {
    v0 = "successfully created debugfs root";
    v1 = debug_mdl & 0x20000;
    v2 = 4;
    v3 = 61;
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             v1,
             v2,
             "cam_debugfs_init",
             v3,
             v0);
  }
  return result;
}
