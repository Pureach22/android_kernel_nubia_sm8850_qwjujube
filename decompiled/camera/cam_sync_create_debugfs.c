__int64 cam_sync_create_debugfs()
{
  __int64 result; // x0
  unsigned __int64 v1[2]; // [xsp+0h] [xbp-10h] BYREF

  v1[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1[0] = 0;
  if ( (unsigned int)cam_debugfs_create_subdir("sync", v1) )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               128,
               1,
               "cam_sync_create_debugfs",
               2673,
               "DebugFS could not create directory!");
  }
  else
  {
    *(_QWORD *)(sync_dev + 8384) = v1[0];
    debugfs_create_bool("trigger_cb_without_switch", 420);
    result = debugfs_create_ulong("cam_sync_monitor_mask", 420, *(_QWORD *)(sync_dev + 8384), &cam_sync_monitor_mask);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
