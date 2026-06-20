__int64 cam_ife_hw_mgr_debug_register()
{
  __int64 result; // x0
  __int64 v1; // x0
  unsigned __int64 v2[2]; // [xsp+0h] [xbp-10h] BYREF

  v2[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2[0] = 0;
  irq_inject_display_buf = 0;
  if ( (unsigned int)cam_debugfs_create_subdir("ife", v2) )
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               8,
               1,
               "cam_ife_hw_mgr_debug_register",
               19693,
               "DebugFS could not create directory!");
  }
  else
  {
    if ( mem_trace_en == 1 )
      v1 = cam_mem_trace_alloc(4096, 0xCC0u, 0, "cam_ife_hw_mgr_debug_register", 0x4CF3u);
    else
      v1 = _kvmalloc_node_noprof(4096, 0, 3520, 0xFFFFFFFFLL);
    irq_inject_display_buf = v1;
    qword_3A84F0 = v2[0];
    debugfs_create_file("ife_csid_debug", 420, v2[0], 0, &cam_ife_csid_debug);
    debugfs_create_file("ife_csid_rx_capture_debug", 420, qword_3A84F0, 0, &cam_ife_csid_rx_capture_debug);
    debugfs_create_u32("enable_recovery", 420, qword_3A84F0, &dword_3A8504);
    debugfs_create_bool("enable_req_dump", 420);
    debugfs_create_u32("enable_csid_recovery", 420, qword_3A84F0, &dword_3A8510);
    debugfs_create_file("ife_camif_debug", 420, qword_3A84F0, 0, &cam_ife_camif_debug);
    debugfs_create_bool("per_req_reg_dump", 420);
    debugfs_create_bool("disable_ubwc_comp", 420);
    debugfs_create_file("sfe_debug", 420, qword_3A84F0, 0, &cam_ife_sfe_debug);
    debugfs_create_file("sfe_sensor_diag_sel", 420, qword_3A84F0, 0, &cam_ife_sfe_sensor_diag_debug);
    debugfs_create_bool("disable_ife_mmu_prefetch", 420);
    debugfs_create_bool("enable_ife_frame_irqs", 420);
    debugfs_create_file("sfe_cache_debug", 420, qword_3A84F0, 0, &cam_ife_sfe_cache_debug);
    debugfs_create_file("test_irq_line", 420, qword_3A84F0, 0, &cam_isp_test_irq_line);
    debugfs_create_file("isp_top_perf_counters", 420, qword_3A84F0, 0, &cam_ife_hw_mgr_perfcnter_debug);
    debugfs_create_file("isp_bus_wr_perf_counters", 420, qword_3A84F0, 0, &cam_ife_hw_mgr_bus_wr_perfcnter_debug);
    debugfs_create_file("isp_csid_perf_counters", 420, qword_3A84F0, 0, &cam_ife_hw_mgr_csid_perfcnter_debug);
    debugfs_create_file("ife_csid_testbus", 420, qword_3A84F0, 0, &cam_ife_csid_testbus_debug);
    debugfs_create_file("evt_based_reg_read", 420, qword_3A84F0, 0, &cam_evt_based_reg_read);
    debugfs_create_bool("disable_isp_drv", 420);
    debugfs_create_bool("enable_presil_reg_dump", 420);
    debugfs_create_file("isp_irq_inject", 420, qword_3A84F0, 0, &cam_isp_irq_injection);
    debugfs_create_bool("enable_cdm_cmd_check", 420);
    debugfs_create_bool("enable_csid_set_domain_id", 420);
    debugfs_create_u32("csid_domain_id_value", 420, qword_3A84F0, &unk_3A8540);
    debugfs_create_u32("csid_out_of_sync_simul", 420, qword_3A84F0, &unk_3A8544);
    debugfs_create_bool("per_req_wait_cdm", 420);
    debugfs_create_bool("enable_cdr_sweep_debug", 420);
    debugfs_create_bool("use_last_consumed_addr", 420);
    debugfs_create_bool("ignore_skip_reg_dump", 420);
    result = debugfs_create_u32("force_acq_csid", 420, qword_3A84F0, &dword_3A8570);
  }
  dword_3A8510 = 1;
  _ReadStatusReg(SP_EL0);
  return result;
}
