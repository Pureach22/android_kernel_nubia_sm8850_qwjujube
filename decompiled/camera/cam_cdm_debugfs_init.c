__int64 __fastcall cam_cdm_debugfs_init(__int64 a1)
{
  unsigned int subdir; // w19
  unsigned __int64 v3; // x2
  unsigned __int64 v5[2]; // [xsp+0h] [xbp-10h] BYREF

  v5[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5[0] = 0;
  subdir = cam_debugfs_create_subdir("cdm", v5);
  if ( subdir )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      1,
      1,
      "cam_cdm_debugfs_init",
      686,
      "DebugFS could not create directory!");
  }
  else
  {
    v3 = v5[0];
    *(_QWORD *)(a1 + 1168) = v5[0];
    debugfs_create_file("test_irq_line", 420, v3, 0, &cam_cdm_irq_line_test);
  }
  _ReadStatusReg(SP_EL0);
  return subdir;
}
