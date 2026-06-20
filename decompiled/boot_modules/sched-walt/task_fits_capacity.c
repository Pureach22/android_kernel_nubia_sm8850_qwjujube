__int64 __fastcall task_fits_capacity(__int64 unlock, unsigned int a2)
{
  __int64 v2; // x19
  __int64 v3; // x23
  _BYTE *v4; // x10
  unsigned __int64 v5; // x21
  unsigned __int64 v6; // x8
  _BYTE *v7; // x8
  _BOOL4 v8; // w24
  __int64 lock; // x0
  _DWORD *v10; // x8
  unsigned int v11; // w25
  unsigned int v12; // w8
  __int64 v13; // x9
  _DWORD *v14; // x10
  __int64 v15; // x9
  _DWORD *v16; // x13
  _QWORD *v17; // x8
  unsigned int v18; // w22
  unsigned int v19; // w9
  unsigned __int64 v20; // x23
  unsigned __int64 v21; // x20
  unsigned __int64 v22; // x0
  unsigned __int64 v23; // x8

  if ( a2 >= 0x20 )
    goto LABEL_35;
  v2 = unlock;
  v3 = a2;
  v4 = &walt_rq[*((_QWORD *)&_per_cpu_offset + a2)];
  v5 = *((_QWORD *)v4 + 79);
  v6 = *(unsigned int *)(unlock + 40);
  if ( ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask + ((v6 >> 3) & 0x1FFFFFF8)) >> v6) & 1) != 0
    && *(_DWORD *)(*((_QWORD *)v4 + 1) + 32LL) == min_possible_cluster_id )
  {
    goto LABEL_7;
  }
  if ( (unsigned int)v6 >= 0x20 )
    goto LABEL_35;
  v7 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v6)];
  if ( *(_DWORD *)(*((_QWORD *)v7 + 1) + 32LL) == min_possible_cluster_id
    && (((unsigned __int64)_cpu_partial_halt_mask[0] >> a2) & 1) != 0 )
  {
LABEL_7:
    v8 = 0;
  }
  else
  {
    v8 = *((_QWORD *)v7 + 79) > v5;
  }
  lock = _rcu_read_lock(unlock);
  v10 = *(_DWORD **)(*(_QWORD *)(v2 + 2872) + 8LL);
  if ( v10 && **(_BYTE **)(*(_QWORD *)(*(_QWORD *)v10 + 264LL) + 16LL) )
    v11 = v10[156];
  else
    v11 = 0;
  unlock = _rcu_read_unlock(lock);
  if ( use_cgroup_margin )
    v12 = v11;
  else
    v12 = 0;
  if ( !v8 )
  {
    v15 = *(unsigned int *)(v2 + 40);
    if ( (unsigned int)v15 < 0x20 && v12 <= 3 )
    {
      v13 = *(int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v15) + 8] + 32LL);
      if ( (unsigned int)v13 <= 3 )
      {
        v14 = sched_capacity_margin_up;
        goto LABEL_24;
      }
    }
LABEL_35:
    __break(0x5512u);
    return task_sched_boost_1(unlock);
  }
  if ( v12 >= 4 )
    goto LABEL_35;
  v13 = *(int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v3) + 8] + 32LL);
  if ( (unsigned int)v13 > 3 )
    goto LABEL_35;
  v14 = sched_capacity_margin_down;
LABEL_24:
  v16 = &v14[4 * v12];
  v17 = (_QWORD *)(v2 + 5184);
  if ( (_UNKNOWN *)v2 == &init_task )
    v17 = &vendor_data_pad;
  v18 = v16[v13];
  if ( v17[30] )
  {
    v19 = v14[v13 + 4];
    if ( v18 <= v19 )
      v18 = v19;
  }
  v20 = *((unsigned __int16 *)v17 + 79);
  v21 = uclamp_eff_value(v2, 0);
  v22 = uclamp_eff_value(v2, 1);
  if ( v20 <= v21 )
    v23 = v21;
  else
    v23 = v20;
  if ( v22 <= v20 )
    v23 = v22;
  return v23 * v18 < v5 << 10;
}
