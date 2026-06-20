unsigned __int64 msm_vidc_debugfs_init_drv()
{
  unsigned __int64 dir; // x19
  unsigned __int64 result; // x0

  dir = debugfs_create_dir("msm_vidc", 0);
  result = 0;
  if ( dir )
  {
    if ( dir <= 0xFFFFFFFFFFFFF000LL )
    {
      debugfs_create_u32("core_clock_voting", 420, dir, &msm_vidc_clock_voting);
      debugfs_create_u32("vpp_clock_voting", 420, dir, &msm_vidc_vpp_clock_voting);
      debugfs_create_u32("apv_clock_voting", 420, dir, &msm_vidc_apv_clock_voting);
      debugfs_create_u32("bse_clock_voting", 420, dir, &msm_vidc_bse_clock_voting);
      debugfs_create_u32("tensilica_clock_voting", 420, dir, &msm_vidc_tensilica_clock_voting);
      debugfs_create_u32("ddr_bw_kbps", 420, dir, &msm_vidc_ddr_bw);
      debugfs_create_u32("llc_bw_kbps", 420, dir, &msm_vidc_llc_bw);
      debugfs_create_bool("disable_video_syscache", 420, dir, &msm_vidc_syscache_disable);
      debugfs_create_bool("lossless_encoding", 420, dir, &msm_vidc_lossless_encode);
      debugfs_create_u32("enable_bugon", 420, dir, &msm_vidc_enable_bugon);
      debugfs_create_u32("apv_bitrate", 420, dir, &msm_vidc_apv_bitrate);
      return dir;
    }
  }
  return result;
}
