unsigned __int64 __usercall _cpu_util_freq_walt@<X0>(
        unsigned int a1@<W0>,
        __int64 a2@<X1>,
        int *a3@<X2>,
        __int64 a4@<X3>,
        __int64 a5@<X4>,
        __int64 a6@<X8>)
{
  unsigned __int64 v6; // x9
  int v7; // w10
  void *v8; // x11
  __int64 v9; // x12
  __int64 v10; // x19
  char *v11; // x20
  unsigned __int64 v12; // x23
  char *v13; // x24
  __int64 v14; // x8
  int *v15; // x21
  __int64 v16; // x10
  int v17; // w10
  _DWORD *v18; // x15
  char v19; // w14
  char *v20; // x17
  bool v21; // zf
  unsigned int *v22; // x15
  unsigned __int64 v23; // x15
  __int64 v24; // x15
  char *v25; // x15
  int v26; // w16
  unsigned int v27; // w3
  __int64 v28; // x13
  unsigned __int64 v29; // x10
  unsigned __int64 v30; // x8
  unsigned __int64 v31; // x9
  __int64 v32; // x10
  char v33; // w12
  __int64 v34; // x10
  __int64 v35; // x9
  unsigned __int64 StatusReg; // x22
  char *v38; // x1
  void *v39; // x20
  unsigned __int64 v40; // x21
  __int64 v41; // x0
  __int64 v42; // x8

  if ( a1 >= 0x20 )
    goto LABEL_56;
  v14 = *((_QWORD *)&_per_cpu_offset + a1);
  v12 = a1;
  v15 = a3;
  v10 = a2;
  v13 = *(char **)((char *)&walt_rq + v14 + 8);
  v11 = (char *)&runqueues + v14;
  v6 = (((__int64 (__fastcall *)(char *))cluster_in_smart_lrpb)(v13) & 1) != 0
     ? (unsigned __int64)(v13 + 56)
     : (unsigned __int64)&walt_rq + *((_QWORD *)&_per_cpu_offset + (unsigned int)v12) + 632;
  a6 = *((unsigned int *)v11 + 908);
  if ( (unsigned int)a6 > 0x1F )
    goto LABEL_56;
  v16 = *((_QWORD *)&_per_cpu_offset + a6);
  v12 = *(_QWORD *)v6;
  LOBYTE(a6) = walt_rotation_enabled;
  v13 = (char *)&walt_rq + v16;
  v9 = *(_QWORD *)((char *)&walt_rq + v16 + 8);
  a3 = *(int **)(v9 + 64);
  if ( walt_rotation_enabled == 1 )
  {
    v8 = nullptr;
    v6 = (unsigned int)sched_ravg_window;
    v17 = 1;
LABEL_50:
    *v15 = v17;
    goto LABEL_51;
  }
  v18 = *(_DWORD **)((char *)&ksoftirqd + v16);
  v8 = &unk_68000;
  if ( *((_DWORD *)v13 + 7) && (sysctl_walt_features & 1) != 0 )
  {
    v8 = nullptr;
    v6 = (unsigned int)sched_ravg_window;
    v17 = 0x10000;
    goto LABEL_50;
  }
  v19 = sched_freq_aggr_en;
  if ( (sched_freq_aggr_en & 1) == 0
    && sysctl_sched_user_hint
    && a3
    && qword_67BA0
    && (*(_BYTE *)(qword_67BA0 + 40) & 1 | (boost_policy == 1)) != (*(_DWORD *)(v9 + 32) == min_possible_cluster_id)
    && sysctl_sched_user_hint == 1000 )
  {
    v8 = nullptr;
    v6 = (unsigned int)sched_ravg_window;
    v17 = 512;
    goto LABEL_50;
  }
  v7 = 1546188227;
  if ( sched_freq_aggr_en )
  {
    v6 = (unsigned __int64)a3 + *((_QWORD *)v13 + 19);
    *v15 = 64;
    if ( !v18 )
      goto LABEL_27;
LABEL_22:
    if ( !v18[12] )
    {
      v20 = (char *)(v18 + 1296);
      v21 = v18 == (_DWORD *)&init_task;
      v22 = (unsigned int *)&vendor_data_pad;
      if ( !v21 )
        v22 = (unsigned int *)v20;
      v23 = v22[7];
      if ( v6 < v23 )
      {
        *v15 = 128;
        v6 = v23;
      }
    }
    goto LABEL_27;
  }
  v6 = *((_QWORD *)v13 + 19)
     + *((_QWORD *)v13 + 23) / 0x64uLL * (unsigned int)sysctl_topapp_weight_pct
     + *((_QWORD *)v13 + 23) % 0x64uLL * (unsigned int)sysctl_topapp_weight_pct / 0x64;
  if ( v18 )
    goto LABEL_22;
LABEL_27:
  v24 = *((unsigned int *)v11 + 908);
  if ( (unsigned int)v24 >= 0x20 )
    goto LABEL_56;
  v25 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v24);
  v26 = *((_DWORD *)v25 + 133);
  if ( v26 == 999 )
  {
    v27 = sched_ravg_window;
    goto LABEL_36;
  }
  if ( v26 )
  {
    v27 = sched_load_granule + sched_load_granule * v26;
    goto LABEL_36;
  }
  if ( (unsigned __int8)(1 - v25[528]) > 2u )
  {
LABEL_56:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      v38 = v11;
      v39 = v8;
      v40 = v6;
      ++*(_DWORD *)(StatusReg + 16);
      v41 = _traceiter_sched_load_to_gov(0, v38, a3, a4, a5, v8, v6, 0, (_BYTE)a6, v7, v13, v9);
      v42 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v42;
      if ( !v42 || (v8 = v39, v6 = v40, !*(_QWORD *)(StatusReg + 16)) )
      {
        preempt_schedule_notrace(v41);
        v8 = v39;
        v6 = v40;
      }
    }
    goto LABEL_51;
  }
  if ( (*(_QWORD *)&v25[128 * (unsigned __int64)(unsigned __int8)(1 - v25[528]) + 376] & 0x8000000000LL) != 0 )
    v27 = sched_load_granule;
  else
    v27 = 0;
LABEL_36:
  if ( v6 < v27 )
  {
    *v15 = 256;
    v6 = v27;
  }
  if ( (v19 & 1) == 0 )
  {
    v28 = (unsigned int)sysctl_sched_user_hint;
    if ( sysctl_sched_user_hint )
    {
      if ( *(_QWORD *)(v9 + 64)
        && qword_67BA0
        && (*(_BYTE *)(qword_67BA0 + 40) & 1 | (boost_policy == 1)) != (*(_DWORD *)(v9 + 32) == min_possible_cluster_id) )
      {
        *v15 = 512;
        v6 = v6 * v28 / 0x64;
      }
    }
  }
  v8 = (void *)v6;
  if ( (sysctl_walt_features & 8) != 0 )
    v8 = *((void **)v13 + 23);
  if ( *((_QWORD *)v13 + 14) )
  {
    v6 = v6 / 0x64 * (unsigned int)(sysctl_ed_boost_pct + 100)
       + v6 % 0x64 * (unsigned int)(sysctl_ed_boost_pct + 100) / 0x64;
    *v15 = 4;
  }
  if ( *((_QWORD *)v13 + 82) )
  {
    v17 = 0x100000;
    v6 = v6 / 0x64 * (unsigned int)(sysctl_pipeline_busy_boost_pct + 100)
       + v6 % 0x64 * (unsigned int)(sysctl_pipeline_busy_boost_pct + 100) / 0x64;
    goto LABEL_50;
  }
LABEL_51:
  v29 = (unsigned int)walt_scale_demand_divisor;
  v30 = v6 / (unsigned int)walt_scale_demand_divisor;
  *((_QWORD *)v13 + 70) = v30;
  if ( v10 )
  {
    v31 = (*((_QWORD *)v13 + 25) + *((_QWORD *)v13 + 21)) / v29;
    v32 = *((_QWORD *)v13 + 6);
    v33 = rtgb_active;
    *((_QWORD *)v13 + 16) = v30;
    *((_QWORD *)v13 + 17) = v32;
    *(_BYTE *)(v10 + 32) = v33;
    *(_QWORD *)v10 = v31;
    *(_QWORD *)(v10 + 8) = v32;
    v34 = trailblazer_boost_state_ns;
    *(_QWORD *)(v10 + 24) = walt_load_reported_window;
    v35 = *((_QWORD *)v13 + 14);
    *(_QWORD *)(v10 + 16) = v8;
    *(_BYTE *)(v10 + 33) = v35 != 0;
    *(_BYTE *)(v10 + 34) = v34 != 0;
  }
  if ( v30 >= v12 )
    return v12;
  else
    return v30;
}
