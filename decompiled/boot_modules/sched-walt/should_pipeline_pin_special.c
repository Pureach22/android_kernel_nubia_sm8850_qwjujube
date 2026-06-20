__int64 __fastcall should_pipeline_pin_special(__int64 a1)
{
  _DWORD *v2; // x9
  _DWORD *v3; // x11
  unsigned __int64 v4; // x8

  if ( !pipeline_special_task || (soc_flags & 0x800) == 0 && !qword_699B0 )
    return 0;
  v2 = (_DWORD *)(pipeline_special_task + 5184);
  if ( (_UNKNOWN *)pipeline_special_task == &init_task )
    v2 = &vendor_data_pad;
  if ( v2 == (_DWORD *)&vendor_data_pad )
    v3 = &init_task;
  else
    v3 = v2 - 1296;
  if ( (unsigned int)(num_sched_clusters - 1) >= 8 )
  {
    __break(0x5512u);
    return is_prime_worthy(a1);
  }
  else
  {
    v4 = v2[8] / (unsigned int)walt_scale_demand_divisor;
    if ( ((*(_QWORD *)(sched_cluster[num_sched_clusters - 1]
                     + (((unsigned __int64)(unsigned int)v3[10] >> 3) & 0x1FFFFFF8)
                     + 24) >> v3[10])
        & 1) != 0 )
      v4 = (unsigned __int16)(100 * ((unsigned int)v4 % 0x46)) / 0x46u + 100LL * ((unsigned int)v4 / 0x46);
    return v4 < (unsigned int)sysctl_pipeline_special_task_util_thres;
  }
}
