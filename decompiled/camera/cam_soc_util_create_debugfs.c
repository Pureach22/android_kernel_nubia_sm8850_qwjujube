__int64 cam_soc_util_create_debugfs()
{
  __int64 result; // x0
  _QWORD v1[2]; // [xsp+0h] [xbp-10h] BYREF

  v1[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1[0] = 0;
  if ( (unsigned int)cam_debugfs_create_subdir("soc_util", v1) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_soc_util_create_debugfs",
      5725,
      "DebugFS could not create directory!");
    result = 4294967294LL;
  }
  else
  {
    debugfs_create_bool("clk_rgltr_bus_ops_profiling", 420);
    debugfs_create_bool("clk_ops_profiling_hw_and_sw_voting", 420);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
