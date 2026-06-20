__int64 __fastcall sde_core_perf_debugfs_init(char *a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x20
  __int64 v5; // x21
  __int64 dir; // x0
  void *v8; // x0

  v2 = *(_QWORD *)(*(_QWORD *)a1 + 56LL);
  if ( !v2 || (v3 = *(_QWORD *)(v2 + 8)) == 0 )
  {
    v8 = &unk_25EA03;
LABEL_8:
    printk(v8, "sde_core_perf_debugfs_init");
    return 4294967274LL;
  }
  v5 = *((_QWORD *)a1 + 2);
  dir = debugfs_create_dir("core_perf", a2);
  *((_QWORD *)a1 + 1) = dir;
  if ( !dir )
  {
    v8 = &unk_2771DD;
    goto LABEL_8;
  }
  debugfs_create_u64("max_core_clk_rate", 384, dir, a1 + 56);
  debugfs_create_u64("core_clk_rate", 384, *((_QWORD *)a1 + 1), a1 + 48);
  debugfs_create_u32("threshold_low", 384, *((_QWORD *)a1 + 1), v5 + 21704);
  debugfs_create_file("threshold_high", 384, *((_QWORD *)a1 + 1), a1, &sde_core_perf_threshold_high_fops);
  debugfs_create_u32("min_core_ib", 384, *((_QWORD *)a1 + 1), v5 + 21712);
  debugfs_create_u32("min_llcc_ib", 384, *((_QWORD *)a1 + 1), v5 + 21716);
  debugfs_create_u32("min_dram_ib", 384, *((_QWORD *)a1 + 1), v5 + 21720);
  debugfs_create_file("perf_mode", 384, *((_QWORD *)a1 + 1), a1, &sde_core_perf_mode_fops);
  debugfs_create_file("mmrm_clk_cb", 384, *((_QWORD *)a1 + 1), a1, &sde_core_perf_mmrm_fops);
  debugfs_create_u32("bw_vote_mode", 384, *((_QWORD *)a1 + 1), a1 + 128);
  debugfs_create_bool("bw_vote_mode_updated", 384, *((_QWORD *)a1 + 1), a1 + 133);
  debugfs_create_u64("fix_core_clk_rate", 384, *((_QWORD *)a1 + 1), a1 + 104);
  debugfs_create_u64("fix_core_ib_vote", 384, *((_QWORD *)a1 + 1), a1 + 112);
  debugfs_create_u64("fix_core_ab_vote", 384, *((_QWORD *)a1 + 1), a1 + 120);
  debugfs_create_u32("sys_cache_enable", 384, *((_QWORD *)a1 + 1), a1 + 152);
  debugfs_create_u32("uidle_perf_cnt", 384, *((_QWORD *)a1 + 1), *(_QWORD *)(v3 + 152) + 21980LL);
  debugfs_create_u32("uidle_fal10_target_idle_time_us", 384, *((_QWORD *)a1 + 1), *(_QWORD *)(v3 + 152) + 21948LL);
  debugfs_create_u32("uidle_fal1_target_idle_time_us", 384, *((_QWORD *)a1 + 1), *(_QWORD *)(v3 + 152) + 21952LL);
  debugfs_create_u32("uidle_fal10_threshold_us", 384, *((_QWORD *)a1 + 1), *(_QWORD *)(v3 + 152) + 21956LL);
  debugfs_create_u32("uidle_fal1_max_threshold", 384, *((_QWORD *)a1 + 1), *(_QWORD *)(v3 + 152) + 21960LL);
  debugfs_create_bool("uidle_enable", 384, *((_QWORD *)a1 + 1), *(_QWORD *)(v3 + 152) + 21984LL);
  debugfs_create_bool("uidle_status", 256, *((_QWORD *)a1 + 1), v3 + 2097);
  return 0;
}
