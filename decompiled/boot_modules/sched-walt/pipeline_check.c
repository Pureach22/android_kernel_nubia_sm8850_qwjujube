__int64 __fastcall pipeline_check(__int64 a1)
{
  unsigned int heaviest_topapp; // w0
  unsigned __int64 v3; // x8
  unsigned int v4; // w19
  bool v5; // w21
  __int64 v6; // x1

  heaviest_topapp = find_heaviest_topapp(*(_QWORD *)(a1 + 64));
  v3 = *(_QWORD *)(a1 + 64);
  v4 = heaviest_topapp;
  rearrange_pipeline_preferred_cpus(v3);
  v5 = (sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres) != 0;
  if ( sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres )
  {
    if ( (pipeline_reset_unisolation_state_last_auto_pipeline & 1) == 0 )
    {
      v6 = 0;
LABEL_6:
      ((void (__fastcall *)(_QWORD, __int64))pipeline_set_unisolation)(0, v6);
      pipeline_reset_unisolation_state_last_auto_pipeline = v5;
    }
  }
  else if ( pipeline_reset_unisolation_state_last_auto_pipeline )
  {
    v6 = 1;
    goto LABEL_6;
  }
  return v4;
}
