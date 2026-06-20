unsigned __int64 __fastcall adreno_debugfs_init(unsigned __int64 result)
{
  unsigned __int64 v1; // x2
  _QWORD *v2; // x19
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x20
  __int64 v5; // x8
  unsigned __int64 dir; // x0

  v1 = *(_QWORD *)(result + 11176);
  if ( v1 && v1 <= 0xFFFFFFFFFFFFF000LL )
  {
    v2 = (_QWORD *)result;
    debugfs_create_file("active_cnt", 292, v1, result, &active_count_fops);
    v2[2553] = debugfs_create_dir("ctx", v2[1397]);
    v3 = debugfs_lookup("snapshot", kgsl_debugfs_dir);
    v4 = v3;
    if ( v3 && v3 <= 0xFFFFFFFFFFFFF000LL )
      debugfs_create_file("coop_reset", 420, v3, v2, &coop_reset_fops);
    v5 = v2[1783];
    if ( (*(_BYTE *)(v5 + 32) & 8) != 0 )
    {
      debugfs_create_file("lm_limit", 420, v2[1397], v2, &lm_limit_fops);
      debugfs_create_file("lm_threshold_count", 292, v2[1397], v2, &lm_threshold_fops);
      v5 = v2[1783];
    }
    if ( (unsigned int)(*(_DWORD *)v5 - 600) >= 0xFFFFFF9C )
      debugfs_create_file("isdb", 420, v2[1397], v2, &isdb_fops_0);
    if ( (gmu_core_isenabled((__int64)v2) & 1) != 0 )
    {
      debugfs_create_file("ifpc_hyst", 420, v2[1397], v2, &ifpc_hyst_fops);
      debugfs_create_file("minbw", 420, v2[1397], v2, &minbw_fops);
      debugfs_create_file("gmu_fault_policy", 420, v2[1397], v2, &gmu_fp_fops);
    }
    if ( (*(_BYTE *)(v2[1783] + 34LL) & 8) != 0 )
      debugfs_create_file("warmboot", 420, v2[1397], v2, &warmboot_fops);
    debugfs_create_file("ctxt_record_size", 420, v4, v2, &ctxt_record_size_fops);
    debugfs_create_file("gpu_client_pf", 420, v4, v2, &gpu_client_pf_fops);
    debugfs_create_bool("dump_all_ibs", 420, v4, v2 + 1769);
    debugfs_create_file("prealloc_atomic_snapshot_mem", 420, v4, v2, &prealloc_atomic_snapshot_mem_fops);
    dir = debugfs_create_dir("bcl", v2[1397]);
    v2[3000] = dir;
    if ( dir && dir <= 0xFFFFFFFFFFFFF000LL )
    {
      debugfs_create_file("sid0", 420, dir, v2, &sid0_fops);
      debugfs_create_file("sid1", 420, v2[3000], v2, &sid1_fops);
      debugfs_create_file("sid2", 420, v2[3000], v2, &sid2_fops);
      debugfs_create_file("bcl_throttle_time_us", 292, v2[3000], v2, &bcl_throttle_fops);
    }
    result = debugfs_create_dir("preemption", v2[1397]);
    v2[3002] = result;
    if ( result && result <= 0xFFFFFFFFFFFFF000LL )
    {
      debugfs_create_file("preempt_level", 420, result, v2, &preempt_level_fops);
      debugfs_create_file("usesgmem", 420, v2[3002], v2, &usesgmem_fops);
      result = debugfs_create_file("skipsaverestore", 420, v2[3002], v2, &skipsaverestore_fops);
    }
    if ( (*(_BYTE *)(v2[1783] + 34LL) & 0x40) != 0 )
      return debugfs_create_file("host_based_dcvs", 420, v2[1397], v2, &host_based_dcvs_fops);
  }
  return result;
}
