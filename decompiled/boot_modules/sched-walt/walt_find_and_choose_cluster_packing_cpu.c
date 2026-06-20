__int64 __fastcall walt_find_and_choose_cluster_packing_cpu(
        __int64 cluster_util_pct,
        __int64 a2,
        __int64 a3,
        __int64 a4)
{
  __int64 v4; // x19
  __int64 v5; // x8
  unsigned __int64 v6; // x20
  __int64 v7; // x24
  _QWORD *v8; // x8
  int v9; // w8
  unsigned int v10; // w20
  char *v11; // x24
  __int64 v12; // x9
  _BYTE *v13; // x8
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x11
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x9
  unsigned __int16 *v18; // x9

  v4 = *(_QWORD *)&walt_rq[_per_cpu_offset + 8];
  v5 = *(int *)(v4 + 32);
  if ( (unsigned int)v5 >= 4 )
    goto LABEL_27;
  if ( !sysctl_sched_idle_enough_clust[v5] || !sysctl_sched_cluster_util_thres_pct_clust[v5] )
    return 0xFFFFFFFFLL;
  v6 = _cpu_active_mask & (unsigned int)~LODWORD(_cpu_halt_mask[0]) & *(_QWORD *)(v4 + 24);
  if ( (*(_QWORD *)cluster_util_pct & 0x400000) != 0 )
  {
    v7 = cluster_util_pct;
    v8 = (_QWORD *)system_32bit_el0_cpumask(cluster_util_pct);
    cluster_util_pct = v7;
    v6 &= *v8;
  }
  v9 = __clz(__rbit64(v6));
  v10 = v6 ? v9 : 32;
  if ( v10 >= nr_cpu_ids || ((**(_QWORD **)(cluster_util_pct + 1376) >> v10) & 1) == 0 )
    return 0xFFFFFFFFLL;
  v11 = (char *)cluster_util_pct;
  cluster_util_pct = sched_get_cluster_util_pct(v4);
  v12 = *(unsigned int *)(v4 + 32);
  if ( (unsigned int)v12 > 3 )
    goto LABEL_27;
  if ( (unsigned int)cluster_util_pct >= sysctl_sched_cluster_util_thres_pct_clust[v12] )
    return 0xFFFFFFFFLL;
  if ( v10 >= 0x20 )
  {
LABEL_27:
    __break(0x5512u);
    return walt_rt_energy_aware_wake_cpu(cluster_util_pct, a2, a3, a4);
  }
  v13 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v10)];
  v14 = *((_QWORD *)v13 + 5);
  v15 = *((_QWORD *)v13 + 79);
  v16 = (unsigned int)sysctl_sched_idle_enough_clust[v12];
  if ( v14 >= v15 )
    v17 = v15;
  else
    v17 = v14;
  if ( v17 >= v16 )
    return 0xFFFFFFFFLL;
  v18 = (unsigned __int16 *)&vendor_data_pad;
  if ( v11 != (char *)&init_task )
    v18 = (unsigned __int16 *)(v11 + 5184);
  if ( (unsigned int)v16 <= v18[79]
    || (((__int64 (__fastcall *)(char *, _QWORD))task_reject_partialhalt_cpu)(v11, v10) & 1) != 0 )
  {
    return 0xFFFFFFFFLL;
  }
  if ( *(_QWORD *)((char *)&arch_freq_scale + *((_QWORD *)&_per_cpu_offset + v10)) > 0x1C2u )
    return 0xFFFFFFFFLL;
  else
    return v10;
}
