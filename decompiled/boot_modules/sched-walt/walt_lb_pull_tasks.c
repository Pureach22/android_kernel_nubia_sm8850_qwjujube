__int64 __fastcall walt_lb_pull_tasks(unsigned int a1, unsigned int a2, unsigned __int16 **a3)
{
  __int64 v4; // x13
  __int64 v5; // x22
  char *v6; // x21
  _BYTE *v7; // x15
  _BOOL4 v8; // w24
  __int64 v9; // x23
  _BOOL4 v10; // w25
  __int64 v11; // x0
  __int64 v12; // x28
  char *v13; // x20
  unsigned __int16 *v14; // x26
  int v15; // w21
  unsigned __int16 *v16; // x27
  unsigned __int16 *v17; // x8
  unsigned __int16 *v18; // x9
  unsigned int v19; // w8
  unsigned int v20; // w9
  __int64 v21; // x28
  int v22; // w21
  unsigned __int16 *v23; // x27
  unsigned __int16 *v24; // x8
  unsigned __int16 *v25; // x9
  unsigned int v26; // w8
  unsigned int v27; // w9
  __int64 v28; // x19
  __int64 v30; // x21
  bool v31; // zf
  bool v32; // zf
  bool v33; // zf
  _BOOL4 v34; // w8
  void *v35; // x22
  _BYTE *v36; // x10
  _BYTE *v37; // x8
  _BYTE *v38; // [xsp+8h] [xbp-28h]
  __int64 v41; // [xsp+20h] [xbp-10h]
  char *v42; // [xsp+28h] [xbp-8h]

  if ( a1 >= 0x20 || a2 > 0x1F )
  {
    __break(0x5512u);
    goto LABEL_81;
  }
  if ( a2 == a1 )
  {
LABEL_81:
    __break(0x800u);
    return ((__int64 (*)(void))walt_can_migrate_task)();
  }
  v4 = *((_QWORD *)&_per_cpu_offset + a2);
  v5 = *((_QWORD *)&_per_cpu_offset + a1);
  v6 = (char *)&runqueues + v4;
  v7 = &walt_rq[v4];
  v8 = ((_cpu_partial_halt_mask[0] & (1LL << a2)) == 0
     || *(_DWORD *)(*(_QWORD *)&walt_rq[v5 + 8] + 32LL) != min_possible_cluster_id)
    && (*(_DWORD *)(*((_QWORD *)v7 + 1) + 32LL) != min_possible_cluster_id
     || (((unsigned __int64)_cpu_partial_halt_mask[0] >> a1) & 1) == 0)
    && *((_QWORD *)v7 + 79) > *(_QWORD *)&walt_rq[v5 + 632];
  v9 = 1LL << a1;
  v38 = &walt_rq[v4];
  v10 = ((_cpu_partial_halt_mask[0] & (1LL << a1)) == 0
      || *(_DWORD *)(*((_QWORD *)v7 + 1) + 32LL) != min_possible_cluster_id)
     && (*(_DWORD *)(*(_QWORD *)&walt_rq[v5 + 8] + 32LL) != min_possible_cluster_id
      || (_cpu_partial_halt_mask[0] & (1LL << a2)) == 0)
     && *(_QWORD *)&walt_rq[v5 + 632] > *((_QWORD *)v7 + 79);
  v11 = raw_spin_lock_irqsave(v6);
  v12 = *((_QWORD *)v6 + 456);
  v13 = v6 + 3640;
  v41 = v11;
  v42 = v6;
  if ( (char *)v12 != v6 + 3640 )
  {
    v14 = nullptr;
    v15 = 0;
    do
    {
      if ( (**(_QWORD **)(v12 + 1120) & v9) != 0 && !*(_DWORD *)(v12 - 168) )
      {
        v16 = (unsigned __int16 *)(v12 - 256);
        if ( (walt_can_migrate_task(v12 - 256, a1, v8, v10, 0) & 1) != 0 )
        {
          if ( v14 )
          {
            v17 = (unsigned __int16 *)(v12 + 4928);
            if ( v16 == (unsigned __int16 *)&init_task )
              v17 = (unsigned __int16 *)&vendor_data_pad;
            v18 = v14 + 2592;
            if ( v14 == (unsigned __int16 *)&init_task )
              v18 = (unsigned __int16 *)&vendor_data_pad;
            v19 = v17[79];
            v20 = v18[79];
            if ( v8 )
            {
              if ( v19 >= v20 )
                v16 = v14;
            }
            else if ( v19 <= v20 )
            {
              v16 = v14;
            }
          }
          ++v15;
          v14 = v16;
          if ( v15 > 5 )
            break;
        }
      }
      v12 = *(_QWORD *)(v12 + 8);
    }
    while ( (char *)v12 != v13 );
    v6 = v42;
    if ( v14 )
      goto LABEL_52;
  }
  v21 = *((_QWORD *)v6 + 456);
  if ( (char *)v21 == v13 )
    goto LABEL_53;
  v14 = nullptr;
  v22 = 0;
  do
  {
    if ( (**(_QWORD **)(v21 + 1120) & v9) != 0 && !*(_DWORD *)(v21 - 168) )
    {
      v23 = (unsigned __int16 *)(v21 - 256);
      if ( (walt_can_migrate_task(v21 - 256, a1, v8, v10, 1) & 1) != 0 )
      {
        if ( v14 )
        {
          v24 = (unsigned __int16 *)(v21 + 4928);
          if ( v23 == (unsigned __int16 *)&init_task )
            v24 = (unsigned __int16 *)&vendor_data_pad;
          v25 = v14 + 2592;
          if ( v14 == (unsigned __int16 *)&init_task )
            v25 = (unsigned __int16 *)&vendor_data_pad;
          v26 = v24[79];
          v27 = v25[79];
          if ( v8 )
          {
            if ( v26 >= v27 )
              v23 = v14;
          }
          else if ( v26 <= v27 )
          {
            v23 = v14;
          }
        }
        ++v22;
        v14 = v23;
        if ( v22 > 5 )
          break;
      }
    }
    v21 = *(_QWORD *)(v21 + 8);
  }
  while ( (char *)v21 != v13 );
  v6 = v42;
  if ( !v14 )
  {
LABEL_53:
    v30 = *((_QWORD *)v6 + 456);
    if ( (char *)v30 == v13 )
      goto LABEL_78;
    v31 = !(sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres) || have_heavy_list == 0;
    v32 = v31 && pipeline_nr == 0;
    v33 = !v32 && sched_boost_type == 0;
    v34 = v33;
    while ( 1 )
    {
      v35 = (void *)(v30 - 256);
      if ( !v34 )
        goto LABEL_84;
      v36 = (_BYTE *)(v30 + 4928);
      if ( v35 == &init_task )
        v36 = &vendor_data_pad;
      if ( (v36[191] & 0xC) == 0 )
      {
LABEL_84:
        if ( *(_DWORD *)(v30 - 168) )
          break;
      }
      v30 = *(_QWORD *)(v30 + 8);
      if ( (char *)v30 == v13 )
        goto LABEL_78;
    }
    if ( (**(_QWORD **)(v30 + 1120) & v9) == 0
      || *(_BYTE *)(v30 + 17)
      || (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD))need_active_lb)(v30 - 256, a1, a2) & 1) == 0 )
    {
LABEL_78:
      raw_spin_unlock_irqrestore(v42, v41);
    }
    else
    {
      *((_DWORD *)v42 + 894) = 1;
      *((_DWORD *)v42 + 895) = a1;
      get_task_struct(v30 - 256);
      *(_QWORD *)v38 = v35;
      mark_reserved(a1, v38);
      raw_spin_unlock_irqrestore(v42, v41);
      trace_walt_active_load_balance();
      if ( (stop_one_cpu_nowait(a2, stop_walt_lb_active_migration, v42, v42 + 3584) & 1) == 0 )
        clear_reserved(a1, v37);
    }
    return 0;
  }
  else
  {
LABEL_52:
    walt_detach_task((__int64)v14, (__int64)v6, (__int64)&runqueues + v5);
    raw_spin_unlock_irqrestore(v6, v41);
    v28 = raw_spin_lock_irqsave((char *)&runqueues + v5);
    activate_task((char *)&runqueues + v5, v14, 0);
    wakeup_preempt((char *)&runqueues + v5, v14, 0);
    raw_spin_unlock_irqrestore((char *)&runqueues + v5, v28);
    *a3 = v14;
    return 1;
  }
}
