__int64 __fastcall cam_req_mgr_debug_register(__int64 a1)
{
  __int64 result; // x0
  _QWORD v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  if ( (unsigned int)cam_debugfs_create_subdir("req_mgr", v3) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x400000,
      1,
      "cam_req_mgr_debug_register",
      164,
      "DebugFS could not create directory!");
    result = 4294967294LL;
  }
  else
  {
    debugfs_root = v3[0];
    debugfs_create_file("sessions_info", 420, v3[0], a1, &session_info);
    debugfs_create_file("bubble_recovery", 420, debugfs_root, a1, &bubble_recovery);
    debugfs_create_bool("recovery_on_apply_fail", 420);
    debugfs_create_bool("disable_sensor_standby", 420);
    debugfs_create_u32("delay_detect_count", 420, debugfs_root, &cam_debug_mgr_delay_detect);
    debugfs_create_file("cam_print_boot_stats", 420, debugfs_root, 0, &cam_boot_debug_info);
    debugfs_create_bool("simulate_skip", 420);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
