__int64 __fastcall cam_cpas_util_create_debugfs(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 v3[2]; // [xsp+0h] [xbp-10h] BYREF

  v3[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3[0] = 0;
  if ( (unsigned int)cam_debugfs_create_subdir("cpas", v3) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_util_create_debugfs",
      5081,
      "DebugFS could not create directory!");
    result = 4294967294LL;
  }
  else
  {
    *(_QWORD *)(a1 + 8136) = v3[0];
    debugfs_create_bool("ahb_bus_scaling_disable", 420);
    debugfs_create_bool("full_state_dump", 420);
    debugfs_create_bool("smart_qos_dump", 420);
    debugfs_create_bool("force_hlos_drv", 420);
    debugfs_create_bool("force_cesta_sw_client", 420);
    debugfs_create_bool("force_core_secure", 420);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
