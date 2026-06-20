__int64 do_maxfreq_release_with_ceiling()
{
  __int64 v0; // x23
  __int64 v1; // x19

  if ( cluster_num >= 1 )
  {
    v0 = 0;
    v1 = 0;
    do
    {
      cpufreq_set_level_max((_DWORD *)(cpufreq_dev + v0), 0, 1);
      if ( ifas_log_enable )
        printk(&unk_F639, "do_maxfreq_release_with_ceiling");
      ++v1;
      v0 += 344;
    }
    while ( v1 < cluster_num );
  }
  return update_cpu_loading_locked();
}
