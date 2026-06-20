__int64 __fastcall is_prime_worthy(char *a1, __int64 a2)
{
  char v2; // w8
  char *v3; // x19
  unsigned int v4; // w10
  unsigned int v5; // w20
  unsigned int *v6; // x21
  unsigned int v8; // w9
  __int64 v9; // x10
  int v10; // w11
  char v11; // w0
  char v13; // w10
  bool v14; // w10
  bool v15; // zf
  unsigned __int64 v16; // x13
  unsigned int v17; // w22
  char v18; // w0

  if ( !a1 )
  {
    v2 = 0;
    return v2 & 1;
  }
  if ( num_sched_clusters < 2 )
  {
    v2 = 1;
    return v2 & 1;
  }
  if ( a1 == (char *)&vendor_data_pad )
    v3 = (char *)&init_task;
  else
    v3 = a1 - 5184;
  v4 = 63 - __clz(*(unsigned int *)(*(_QWORD *)cpu_array + 8LL * (unsigned int)num_sched_clusters - 16));
  if ( *(_DWORD *)(*(_QWORD *)cpu_array + 8LL * (unsigned int)num_sched_clusters - 16) )
    v5 = v4;
  else
    v5 = 32;
  if ( v3 == (char *)&init_task )
    v6 = (unsigned int *)&vendor_data_pad;
  else
    v6 = (unsigned int *)(v3 + 5184);
  if ( *((_QWORD *)v6 + 24) )
  {
    a1 = (char *)walt_sched_clock((__int64)a1, a2);
    if ( (unsigned __int64)a1 > *((_QWORD *)v6 + 25) )
    {
      v6[46] = 0;
      *((_QWORD *)v6 + 24) = 0;
      *((_QWORD *)v6 + 25) = 0;
    }
  }
  if ( v6[46] == 1 && (soc_flags & 8) == 0 )
    v8 = 0;
  else
    v8 = v6[46];
  if ( v5 < 0x20 )
  {
    v9 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v5) + 8];
    if ( (_cpu_possible_mask & (unsigned int)~*(_DWORD *)(v9 + 24) & **((_QWORD **)v3 + 172)) == 0 )
      goto LABEL_26;
    v10 = *(_DWORD *)(v9 + 32);
    if ( v10 == max_possible_cluster_id )
      goto LABEL_26;
    if ( !sched_boost_type )
    {
      if ( pipeline_nr )
      {
        v14 = 0;
      }
      else
      {
        v15 = !(sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres) || have_heavy_list == 0;
        v14 = v15;
      }
      if ( !v14 )
      {
        v16 = v6[91];
        if ( (_DWORD)v16 != -1 )
        {
          if ( have_heavy_list )
          {
            if ( have_heavy_list >= 3 )
              goto LABEL_58;
          }
          else if ( pipeline_nr >= 3 )
          {
LABEL_58:
            v11 = ((*(_QWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1) + ((v16 >> 3) & 0x1FFFFFF8)) >> v16)
                 & 1LL) == 0;
            goto LABEL_27;
          }
        }
      }
    }
    if ( v10 == min_possible_cluster_id )
    {
      v13 = boost_policy;
      if ( !boost_policy )
      {
LABEL_32:
        v11 = 0;
        if ( (v13 & 1) != 0 || v8 )
          goto LABEL_27;
        if ( (soc_flags & 4) != 0
          && uclamp_eff_value(v3, 0)
          && sysctl_sched_min_task_util_for_uclamp < (unsigned int)*((unsigned __int16 *)v6 + 79)
          || (walt_should_kick_upmigrate_1(v3, v5) & 1) != 0 )
        {
          goto LABEL_40;
        }
LABEL_45:
        v11 = task_fits_capacity_1(v3, v5);
        goto LABEL_27;
      }
      v17 = v8;
      v18 = ((__int64 (__fastcall *)(char *))task_sched_boost_3)(v3);
      v13 = 0;
      if ( (v18 & 1) == 0 )
      {
LABEL_64:
        v8 = v17;
        goto LABEL_32;
      }
      v8 = v17;
      if ( boost_policy != 1 )
        goto LABEL_32;
      if ( sched_boost_type == 5 || sched_boost_type == 2 )
      {
        v13 = sysctl_sched_min_task_util_for_boost < (unsigned int)*((unsigned __int16 *)v6 + 79);
        goto LABEL_64;
      }
    }
    else if ( v8 <= 1 )
    {
      if ( !*((_QWORD *)v6 + 30) && *((int *)v3 + 37) > 123 )
      {
LABEL_26:
        v11 = 1;
LABEL_27:
        v2 = v11 ^ 1;
        return v2 & 1;
      }
      goto LABEL_45;
    }
LABEL_40:
    v11 = 0;
    goto LABEL_27;
  }
  __break(0x5512u);
  return task_fits_capacity_1(a1, a2);
}
