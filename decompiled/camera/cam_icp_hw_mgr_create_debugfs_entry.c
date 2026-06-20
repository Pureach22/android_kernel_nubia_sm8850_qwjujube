__int64 __fastcall cam_icp_hw_mgr_create_debugfs_entry(__int64 a1)
{
  __int64 v2; // x20
  __int64 result; // x0
  unsigned __int64 v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v2 = a1 + 40960;
  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  if ( (unsigned int)cam_debugfs_create_subdir((const char *)(a1 + 112), v4) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_hw_mgr_create_debugfs_entry",
      2301,
      "[%s] DebugFS could not create directory",
      (const char *)(a1 + 112));
    result = 4294967294LL;
  }
  else
  {
    *(_QWORD *)(v2 + 3128) = v4[0];
    debugfs_create_bool("icp_pc", 420);
    debugfs_create_bool("dev_interframe_pc", 420);
    debugfs_create_file("icp_debug_clk", 420, *(_QWORD *)(v2 + 3128), a1, &cam_icp_debug_default_clk);
    debugfs_create_bool("icp_jtag_debug", 420);
    debugfs_create_file("icp_debug_type", 420, *(_QWORD *)(v2 + 3128), a1, &cam_icp_debug_type_fs);
    debugfs_create_file("icp_debug_lvl", 420, *(_QWORD *)(v2 + 3128), a1, &cam_icp_debug_fs);
    debugfs_create_file("icp_fw_dump_lvl", 420, *(_QWORD *)(v2 + 3128), a1, &cam_icp_debug_fw_dump);
    debugfs_create_file("icp_fw_ramdump_lvl", 420, *(_QWORD *)(v2 + 3128), a1, &cam_icp_debug_fw_ramdump);
    debugfs_create_bool("disable_ubwc_comp", 420);
    debugfs_create_file("test_irq_line", 420, *(_QWORD *)(v2 + 3128), a1, &cam_icp_irq_line_test);
    debugfs_create_bool("enable_kernel_panic", 420);
    debugfs_create_bool("print_llcc_state", 420);
    result = 0;
  }
  *(_DWORD *)(v2 + 3184) = 0;
  *(_QWORD *)(v2 + 3176) = 1;
  _ReadStatusReg(SP_EL0);
  return result;
}
