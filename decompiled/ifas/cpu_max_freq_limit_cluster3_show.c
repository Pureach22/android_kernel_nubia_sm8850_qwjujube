__int64 __fastcall cpu_max_freq_limit_cluster3_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x22

  if ( cluster_num < 4 )
    return -1;
  mutex_lock(&cpu_ctrl_lock);
  v4 = *(int *)(cpufreq_dev + 1044);
  mutex_unlock(&cpu_ctrl_lock);
  return (int)scnprintf(a3, 4096, "%d\n", *(_DWORD *)(*(_QWORD *)(cpufreq_dev + 1064) + 4 * v4));
}
