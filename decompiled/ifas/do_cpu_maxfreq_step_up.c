void do_cpu_maxfreq_step_up()
{
  __int64 v0; // x20
  __int64 v1; // x19
  int v2; // w4
  unsigned int v3; // w8
  bool v4; // cf
  unsigned int v5; // w8
  __int64 v6; // x27

  if ( cluster_num >= 1 )
  {
    v0 = 0;
    v1 = 0;
    while ( 1 )
    {
      if ( !cpu_loading_enable )
        goto LABEL_13;
      v2 = *(_DWORD *)(cpufreq_dev + v0 + 84);
      if ( v2 == 100 )
        goto LABEL_12;
      if ( v2 >= *(_DWORD *)(cpufreq_dev + v0 + 80) )
        break;
      if ( ifas_log_enable )
        printk(&unk_1084E, "do_cpu_maxfreq_step_up");
LABEL_5:
      ++v1;
      v0 += 344;
      if ( v1 >= cluster_num )
        return;
    }
    if ( !v2 )
    {
      if ( ifas_log_enable )
        printk(&unk_F947, "do_cpu_maxfreq_step_up");
      goto LABEL_5;
    }
LABEL_12:
    if ( v2 < cpu_loading_low )
    {
      if ( ifas_log_enable )
        printk(&unk_108AE, "do_cpu_maxfreq_step_up");
      goto LABEL_5;
    }
LABEL_13:
    if ( *(_DWORD *)(cpufreq_dev + v0 + 12) || *(_DWORD *)(cpufreq_dev + v0 + 20) )
    {
      mutex_lock(&cpu_ctrl_lock);
      v3 = *(_DWORD *)(cpufreq_dev + v0 + 12);
      v4 = v3 >= rescue_freq_level_up + 1;
      v5 = v3 - (rescue_freq_level_up + 1);
      if ( v4 )
        v6 = v5;
      else
        v6 = 0;
      mutex_unlock(&cpu_ctrl_lock);
      if ( ifas_log_enable )
        printk(&unk_F430, "do_cpu_maxfreq_step_up");
      cpufreq_set_level_max(cpufreq_dev + v0, v6, 1);
    }
    else if ( ifas_log_enable )
    {
      printk(&unk_F26E, "do_cpu_maxfreq_step_up");
    }
    goto LABEL_5;
  }
}
