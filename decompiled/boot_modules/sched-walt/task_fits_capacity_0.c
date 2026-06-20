__int64 __fastcall task_fits_capacity_0(__int64 unlock, __int64 a2)
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
  __int64 v12; // x8
  __int64 v13; // x9
  _DWORD *v14; // x10
  __int64 v15; // x9
  _DWORD *v16; // x13
  _QWORD *v17; // x8
  unsigned int v18; // w22
  __int64 v19; // x9
  unsigned int v20; // w9
  unsigned __int64 v21; // x23
  unsigned __int64 v22; // x20
  unsigned __int64 v23; // x0
  unsigned __int64 v24; // x8

  if ( (unsigned int)a2 >= 0x20 )
    goto LABEL_38;
  v2 = unlock;
  v3 = (unsigned int)a2;
  v4 = &walt_rq[*((_QWORD *)&_per_cpu_offset + (unsigned int)a2)];
  v5 = *((_QWORD *)v4 + 79);
  v6 = *(unsigned int *)(unlock + 40);
  if ( ((*(unsigned __int64 *)((char *)_cpu_partial_halt_mask + ((v6 >> 3) & 0x1FFFFFF8)) >> v6) & 1) != 0
    && *(_DWORD *)(*((_QWORD *)v4 + 1) + 32LL) == min_possible_cluster_id )
  {
    goto LABEL_7;
  }
  if ( (unsigned int)v6 >= 0x20 )
    goto LABEL_38;
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
    if ( (unsigned int)v15 < 0x20 && (unsigned int)v12 <= 3 )
    {
      v13 = *(int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v15) + 8] + 32LL);
      if ( (unsigned int)v13 <= 3 )
      {
        if ( ((16LL * (unsigned int)v12) | (unsigned __int64)(4 * v13)) > 0x40 )
          goto LABEL_39;
        v14 = sched_capacity_margin_up;
        goto LABEL_26;
      }
    }
LABEL_38:
    __break(0x5512u);
    goto LABEL_39;
  }
  if ( (unsigned int)v12 >= 4 )
    goto LABEL_38;
  v13 = *(int *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v3) + 8] + 32LL);
  if ( (unsigned int)v13 > 3 )
    goto LABEL_38;
  if ( ((16LL * (unsigned int)v12) | (unsigned __int64)(4 * v13)) > 0x40 )
    goto LABEL_39;
  v14 = sched_capacity_margin_down;
LABEL_26:
  v16 = &v14[4 * v12];
  v17 = (_QWORD *)(v2 + 5184);
  if ( (_UNKNOWN *)v2 == &init_task )
    v17 = &vendor_data_pad;
  v18 = v16[v13];
  if ( !v17[30] )
    goto LABEL_32;
  v19 = v13;
  if ( ((v19 * 4) | 0x10uLL) > 0x40 )
  {
LABEL_39:
    __break(1u);
    return task_reject_partialhalt_cpu_0(unlock, a2);
  }
  v20 = v14[v19 + 4];
  if ( v18 <= v20 )
    v18 = v20;
LABEL_32:
  v21 = *((unsigned __int16 *)v17 + 79);
  v22 = uclamp_eff_value(v2, 0);
  v23 = uclamp_eff_value(v2, 1);
  if ( v21 <= v22 )
    v24 = v22;
  else
    v24 = v21;
  if ( v23 <= v21 )
    v24 = v23;
  return v24 * v18 < v5 << 10;
}
