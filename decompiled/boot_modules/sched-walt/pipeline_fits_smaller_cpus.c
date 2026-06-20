__int64 __fastcall pipeline_fits_smaller_cpus(char *a1)
{
  unsigned int *v1; // x9
  __int64 result; // x0
  bool v3; // zf
  char v4; // w10
  unsigned __int64 v5; // x9

  v1 = (unsigned int *)(a1 + 5184);
  if ( a1 == (char *)&init_task )
    v1 = (unsigned int *)&vendor_data_pad;
  if ( sched_boost_type )
    return 0xFFFFFFFFLL;
  if ( pipeline_nr )
  {
    result = 0xFFFFFFFFLL;
  }
  else
  {
    if ( sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres )
      v3 = have_heavy_list == 0;
    else
      v3 = 1;
    v4 = v3;
    result = 0xFFFFFFFFLL;
    if ( (v4 & 1) != 0 )
      return result;
  }
  v5 = v1[91];
  if ( (_DWORD)v5 != -1 )
  {
    if ( have_heavy_list )
    {
      if ( have_heavy_list >= 3 )
        return ((*(_QWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1) + ((v5 >> 3) & 0x1FFFFFF8)) >> v5)
              & 1LL) == 0;
    }
    else if ( pipeline_nr >= 3 )
    {
      return ((*(_QWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1) + ((v5 >> 3) & 0x1FFFFFF8)) >> v5) & 1LL) == 0;
    }
  }
  return result;
}
