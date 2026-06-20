void do_cpu_maxfreq_step_down()
{
  __int64 v0; // x27
  __int64 i; // x19
  void *v2; // x0
  unsigned __int64 v3; // x25

  if ( cluster_num >= 1 )
  {
    v0 = 0;
    for ( i = 0; i < cluster_num; ++i )
    {
      if ( cpu_loading_enable && *(_DWORD *)(cpufreq_dev + v0 + 84) > cpu_loading_high )
      {
        if ( ifas_log_enable )
        {
          v2 = &unk_10925;
LABEL_14:
          printk(v2, "do_cpu_maxfreq_step_down");
        }
      }
      else
      {
        if ( *(_DWORD *)(cpufreq_dev + v0 + 12) != *(_DWORD *)(cpufreq_dev + v0 + 24) )
        {
          mutex_lock(&cpu_ctrl_lock);
          v3 = (unsigned int)(*(_DWORD *)(cpufreq_dev + v0 + 12) + rescue_freq_level_down + 1);
          mutex_unlock(&cpu_ctrl_lock);
          if ( ifas_log_enable )
            printk(&unk_F9A5, "do_cpu_maxfreq_step_down");
          cpufreq_set_level_max((_DWORD *)(cpufreq_dev + v0), v3, 1);
          goto LABEL_4;
        }
        if ( ifas_log_enable )
        {
          v2 = &unk_10993;
          goto LABEL_14;
        }
      }
LABEL_4:
      v0 += 344;
    }
  }
}
