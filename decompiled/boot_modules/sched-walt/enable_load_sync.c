bool __fastcall enable_load_sync(unsigned int a1)
{
  char v1; // w8
  unsigned __int64 v2; // x9
  _BOOL8 result; // x0
  bool v4; // zf
  int v5; // w9

  v1 = a1;
  v2 = (unsigned __int64)a1 >> 3;
  result = 0;
  if ( ((*(unsigned __int64 *)((char *)&pipeline_sync_cpus + (v2 & 0x1FFFFFF8)) >> v1) & 1) == 0 || sched_boost_type )
    return result;
  if ( pipeline_nr )
  {
    result = 0;
  }
  else
  {
    if ( sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres )
      v4 = have_heavy_list == 0;
    else
      v4 = 1;
    v5 = !v4;
    result = 0;
    if ( !v5 )
      return result;
  }
  if ( !sysctl_single_thread_pipeline )
  {
    if ( sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres
      || ((unsigned int)pipeline_sync_cpus & (unsigned int)cpus_for_pipeline) != 0 )
    {
      if ( have_heavy_list )
        return have_heavy_list == 3;
      else
        return pipeline_nr > 2;
    }
    else
    {
      return 0;
    }
  }
  return result;
}
