__int64 __fastcall task_fits_max(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  _DWORD *v4; // x21
  unsigned __int64 v5; // x0
  unsigned int v7; // w27
  __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // x24
  _BYTE *v11; // x8
  char v12; // w8
  unsigned __int64 v13; // x25
  unsigned __int64 v14; // x9
  _BYTE *v15; // x8
  _BOOL4 v16; // w20
  __int64 lock; // x0
  _DWORD *v18; // x8
  unsigned int v19; // w26
  unsigned int v20; // w8
  __int64 v21; // x9
  _DWORD *v22; // x10
  __int64 v23; // x9
  unsigned int v24; // w22
  unsigned __int64 v25; // x21
  unsigned __int64 v26; // x20
  unsigned __int64 v27; // x0
  unsigned __int64 v28; // x8
  char v29; // w0

  v3 = a2;
  if ( (_UNKNOWN *)a1 == &init_task )
    v4 = &vendor_data_pad;
  else
    v4 = (_DWORD *)(a1 + 5184);
  if ( *((_QWORD *)v4 + 24) )
  {
    v5 = walt_clock_suspended == 1 ? sched_clock_last : sched_clock(a1, a2);
    if ( v5 > *((_QWORD *)v4 + 25) )
    {
      v4[46] = 0;
      *((_QWORD *)v4 + 24) = 0;
      *((_QWORD *)v4 + 25) = 0;
    }
  }
  if ( v4[46] == 1 && (soc_flags & 8) == 0 )
    v7 = 0;
  else
    v7 = v4[46];
  if ( v3 >= 0x20 )
    goto LABEL_71;
  v8 = *(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v3) + 8];
  if ( (_cpu_possible_mask & (unsigned int)~*(_DWORD *)(v8 + 24) & **(_QWORD **)(a1 + 1376)) == 0
    || *(_DWORD *)(v8 + 32) == max_possible_cluster_id )
  {
    return 1;
  }
  result = pipeline_fits_smaller_cpus(a1);
  if ( (unsigned int)result >= 2 )
  {
    v10 = v3;
    v11 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v3)];
    if ( *(_DWORD *)(*((_QWORD *)v11 + 1) + 32LL) == min_possible_cluster_id )
    {
      v12 = boost_policy;
      if ( boost_policy )
      {
        v29 = task_sched_boost(a1);
        v12 = 0;
        if ( (v29 & 1) != 0 && boost_policy == 1 )
        {
          if ( sched_boost_type != 5 && sched_boost_type != 2 )
            return 0;
          v12 = sysctl_sched_min_task_util_for_boost < (unsigned int)*((unsigned __int16 *)v4 + 79);
        }
      }
      result = 0;
      if ( (v12 & 1) != 0 || v7 )
        return result;
      if ( (soc_flags & 4) == 0
        || !uclamp_eff_value(a1, 0)
        || sysctl_sched_min_task_util_for_uclamp >= (unsigned int)*((unsigned __int16 *)v4 + 79) )
      {
        result = ((__int64 (__fastcall *)(__int64, _QWORD))walt_should_kick_upmigrate)(a1, v3);
        if ( (result & 1) == 0 )
        {
          v11 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v3)];
          goto LABEL_34;
        }
      }
    }
    else if ( v7 <= 1 )
    {
      if ( !*((_QWORD *)v4 + 30) && *(int *)(a1 + 148) > 123 )
        return 1;
LABEL_34:
      v13 = *((_QWORD *)v11 + 79);
      v14 = *(unsigned int *)(a1 + 40);
      if ( ((*(unsigned __int64 *)((char *)&_cpu_partial_halt_mask + ((v14 >> 3) & 0x1FFFFFF8)) >> v14) & 1) != 0
        && *(_DWORD *)(*((_QWORD *)v11 + 1) + 32LL) == min_possible_cluster_id )
      {
        goto LABEL_39;
      }
      if ( (unsigned int)v14 >= 0x20 )
        goto LABEL_71;
      v15 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v14)];
      if ( *(_DWORD *)(*((_QWORD *)v15 + 1) + 32LL) == min_possible_cluster_id
        && (((unsigned __int64)_cpu_partial_halt_mask >> v3) & 1) != 0 )
      {
LABEL_39:
        v16 = 0;
      }
      else
      {
        v16 = *((_QWORD *)v15 + 79) > v13;
      }
      lock = _rcu_read_lock(result);
      v18 = *(_DWORD **)(*(_QWORD *)(a1 + 2872) + 8LL);
      if ( v18 && **(_BYTE **)(*(_QWORD *)(*(_QWORD *)v18 + 264LL) + 16LL) )
        v19 = v18[156];
      else
        v19 = 0;
      _rcu_read_unlock(lock);
      if ( use_cgroup_margin )
        v20 = v19;
      else
        v20 = 0;
      if ( v16 )
      {
        if ( v20 < 4 )
        {
          v21 = *(int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v10) + 8] + 32LL);
          if ( (unsigned int)v21 <= 3 )
          {
            v22 = sched_capacity_margin_down;
            goto LABEL_56;
          }
        }
      }
      else
      {
        v23 = *(unsigned int *)(a1 + 40);
        if ( (unsigned int)v23 < 0x20 && v20 <= 3 )
        {
          v21 = *(int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v23) + 8] + 32LL);
          if ( (unsigned int)v21 <= 3 )
          {
            v22 = sched_capacity_margin_up;
LABEL_56:
            v24 = v22[4 * v20 + v21];
            if ( *((_QWORD *)v4 + 30) && v24 <= v22[v21 + 4] )
              v24 = v22[v21 + 4];
            v25 = *((unsigned __int16 *)v4 + 79);
            v26 = uclamp_eff_value(a1, 0);
            v27 = uclamp_eff_value(a1, 1);
            if ( v25 <= v26 )
              v28 = v26;
            else
              v28 = v25;
            if ( v27 <= v25 )
              v28 = v27;
            return v28 * v24 < v13 << 10;
          }
        }
      }
LABEL_71:
      __break(0x5512u);
      JUMPOUT(0x2CC20);
    }
    return 0;
  }
  return result;
}
