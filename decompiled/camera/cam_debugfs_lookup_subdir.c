__int64 __fastcall cam_debugfs_lookup_subdir(__int64 a1, __int64 *a2)
{
  __int64 v3; // x0

  if ( cam_debugfs_root )
  {
    if ( a2 )
    {
      v3 = debugfs_lookup();
      *a2 = v3;
      if ( v3 )
        return 0;
      else
        return 4294967294LL;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x20000,
        1,
        "cam_debugfs_lookup_subdir",
        108,
        "invalid subdir pointer %pK",
        nullptr);
      return 4294967274LL;
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x20000,
      2,
      "cam_debugfs_lookup_subdir",
      102,
      "debugfs root not created");
    *a2 = 0;
    return 4294967277LL;
  }
}
