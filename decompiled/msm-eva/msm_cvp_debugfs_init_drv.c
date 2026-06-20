unsigned __int64 msm_cvp_debugfs_init_drv()
{
  unsigned __int64 dir; // x0
  unsigned __int64 v1; // x19
  unsigned __int64 StatusReg; // x8

  dir = debugfs_create_dir("msm_cvp", 0);
  if ( dir && (v1 = dir, dir <= 0xFFFFFFFFFFFFF000LL) )
  {
    debugfs_create_x32("debug_level", 420, dir, &msm_cvp_debug);
    debugfs_create_x32("fw_level", 420, v1, &msm_cvp_fw_debug);
    debugfs_create_u32("fw_debug_mode", 420, v1, &msm_cvp_fw_debug_mode);
    debugfs_create_u32("fw_low_power_mode", 420, v1, &msm_cvp_fw_low_power_mode);
    debugfs_create_u32("debug_output", 420, v1, &msm_cvp_debug_out);
    debugfs_create_u32("minidump_enable", 420, v1, &msm_cvp_minidump_enable);
    debugfs_create_bool("fw_coverage", 420, v1, &msm_cvp_fw_coverage);
    debugfs_create_bool("auto_pil", 420, v1, &msm_cvp_auto_pil);
    debugfs_create_u32("kernel_fence", 420, v1, &cvp_kernel_fence_enabled);
    debugfs_create_bool("disable_thermal_mitigation", 420, v1, &msm_cvp_thermal_mitigation_disabled);
    debugfs_create_bool("enable_cacheop", 420, v1, &msm_cvp_cacheop_enabled);
    debugfs_create_bool("disable_cvp_syscache", 420, v1, &msm_cvp_syscache_disable);
    debugfs_create_bool("disable_dcvs", 420, v1, &msm_cvp_dcvs_disable);
    debugfs_create_file("cvp_power", 420, v1, 0, &cvp_pwr_fops);
  }
  else
  {
    v1 = 0;
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_87A86, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      return 0;
    }
  }
  return v1;
}
