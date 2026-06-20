__int64 __fastcall cam_debugfs_create_subdir(const char *a1, unsigned __int64 *a2)
{
  unsigned __int64 dir; // x0
  unsigned int v5; // w19

  if ( cam_debugfs_root )
  {
    if ( a2 )
    {
      dir = debugfs_create_dir(a1, cam_debugfs_root);
      if ( dir >= 0xFFFFFFFFFFFFF001LL )
      {
        v5 = dir;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_debugfs_create_subdir",
          91,
          "failed to create debugfs subdir (name=%s, rc=%d)",
          a1,
          dir);
      }
      else
      {
        *a2 = dir;
        return 0;
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_debugfs_create_subdir",
        84,
        "invalid subdir pointer %pK",
        nullptr);
      return (unsigned int)-22;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_debugfs_create_subdir",
      78,
      "debugfs root not created");
    *a2 = 0;
    return (unsigned int)-19;
  }
  return v5;
}
