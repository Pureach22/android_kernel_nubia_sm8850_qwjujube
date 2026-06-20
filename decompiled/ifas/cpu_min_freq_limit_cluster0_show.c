__int64 __fastcall cpu_min_freq_limit_cluster0_show(__int64 a1, __int64 a2, __int64 a3)
{
  if ( cluster_num < 1 )
    return -1;
  else
    return (int)scnprintf(
                  a3,
                  4096,
                  "%d\n",
                  *(_DWORD *)(*(_QWORD *)(cpufreq_dev + 32) + 4LL * *(int *)(cpufreq_dev + 16)));
}
