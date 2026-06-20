__int64 __fastcall task_fits_max_0(char *a1, __int64 a2)
{
  char *v2; // x19
  unsigned int v3; // w20
  _DWORD *v4; // x21
  unsigned int v6; // w23
  __int64 v7; // x8
  unsigned int v8; // w0
  char v10; // w8
  char v11; // w0

  v2 = a1;
  v3 = a2;
  if ( a1 == (char *)&init_task )
    v4 = &vendor_data_pad;
  else
    v4 = a1 + 5184;
  if ( *((_QWORD *)v4 + 24) )
  {
    a1 = (char *)walt_sched_clock((__int64)a1, a2);
    if ( (unsigned __int64)a1 > *((_QWORD *)v4 + 25) )
    {
      v4[46] = 0;
      *((_QWORD *)v4 + 24) = 0;
      *((_QWORD *)v4 + 25) = 0;
    }
  }
  if ( v4[46] == 1 && (soc_flags & 8) == 0 )
    v6 = 0;
  else
    v6 = v4[46];
  if ( v3 < 0x20 )
  {
    v7 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v3) + 8];
    if ( (_cpu_possible_mask & (unsigned int)~*(_DWORD *)(v7 + 24) & **((_QWORD **)v2 + 172)) == 0
      || *(_DWORD *)(v7 + 32) == max_possible_cluster_id )
    {
      goto LABEL_16;
    }
    v8 = pipeline_fits_smaller_cpus(v2);
    if ( v8 < 2 )
      return v8 & 1;
    if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v3) + 8] + 32LL) == min_possible_cluster_id )
    {
      v10 = boost_policy;
      if ( !boost_policy || (v11 = task_sched_boost_1(v2), v10 = 0, (v11 & 1) == 0) || boost_policy != 1 )
      {
LABEL_21:
        LOBYTE(v8) = 0;
        if ( (v10 & 1) != 0 || v6 )
          return v8 & 1;
        if ( (soc_flags & 4) != 0
          && uclamp_eff_value(v2, 0)
          && sysctl_sched_min_task_util_for_uclamp < (unsigned int)*((unsigned __int16 *)v4 + 79)
          || (walt_should_kick_upmigrate_0(v2, v3) & 1) != 0 )
        {
          goto LABEL_29;
        }
LABEL_32:
        LOBYTE(v8) = task_fits_capacity(v2, v3);
        return v8 & 1;
      }
      if ( sched_boost_type == 5 || sched_boost_type == 2 )
      {
        v10 = sysctl_sched_min_task_util_for_boost < (unsigned int)*((unsigned __int16 *)v4 + 79);
        goto LABEL_21;
      }
    }
    else if ( v6 <= 1 )
    {
      if ( !*((_QWORD *)v4 + 30) && *((int *)v2 + 37) > 123 )
      {
LABEL_16:
        LOBYTE(v8) = 1;
        return v8 & 1;
      }
      goto LABEL_32;
    }
LABEL_29:
    LOBYTE(v8) = 0;
    return v8 & 1;
  }
  __break(0x5512u);
  return get_task_struct(a1);
}
