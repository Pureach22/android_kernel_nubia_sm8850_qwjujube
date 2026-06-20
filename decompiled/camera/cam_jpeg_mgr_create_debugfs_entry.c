__int64 cam_jpeg_mgr_create_debugfs_entry()
{
  __int64 result; // x0
  unsigned __int64 v1[2]; // [xsp+0h] [xbp-10h] BYREF

  v1[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1[0] = 0;
  if ( (unsigned int)cam_debugfs_create_subdir("jpeg", v1) )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               512,
               1,
               "cam_jpeg_mgr_create_debugfs_entry",
               2256,
               "DebugFS could not create directory!");
  }
  else
  {
    qword_3AA0C8 = v1[0];
    debugfs_create_file("camnoc_misr_test", 420, v1[0], 0, &camnoc_misr_test);
    debugfs_create_file("bug_on_misr_mismatch", 420, qword_3AA0C8, 0, &bug_on_misr_mismatch);
    result = debugfs_create_file("test_irq_line", 420, qword_3AA0C8, 0, &cam_jpeg_irq_line_test);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
