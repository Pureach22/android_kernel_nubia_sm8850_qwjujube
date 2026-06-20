__int64 __fastcall update_history(__int64 result, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x20
  __int64 v5; // x21
  unsigned int v6; // w23
  unsigned int v7; // w25
  __int64 v8; // x8
  unsigned int *v9; // x22
  char *v10; // x6
  unsigned int v11; // w2
  int v12; // w12
  unsigned int v13; // w10
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x12
  unsigned int v19; // w19
  __int64 v20; // x14
  unsigned int v21; // w28
  __int64 v22; // x8
  char *v23; // x11
  unsigned __int64 v24; // x24
  unsigned __int64 v25; // x8
  unsigned int v26; // w8
  unsigned int v27; // w8
  unsigned int v28; // w8
  int v29; // w8
  unsigned int v30; // w8
  unsigned int v31; // w9
  unsigned int v32; // w8
  char v33; // w8
  __int64 v34; // x8
  __int64 v35; // x8
  unsigned int v36; // w8
  __int64 v37; // x27
  unsigned int pred_busy; // w26
  __int64 v39; // x8
  char *v40; // x11
  unsigned int v41; // w14
  int v42; // w15
  unsigned int v43; // w17
  char v44; // w15
  bool v45; // cf
  unsigned int v46; // w14
  unsigned int v47; // w27
  unsigned int v48; // w8
  int v49; // w8
  int v50; // w8
  unsigned __int64 StatusReg; // x19
  __int64 v52; // x8
  char *v53; // [xsp+8h] [xbp-28h]
  char *v54; // [xsp+8h] [xbp-28h]
  __int16 v55; // [xsp+14h] [xbp-1Ch]
  __int16 v56; // [xsp+14h] [xbp-1Ch]
  int v57; // [xsp+18h] [xbp-18h]
  char *v58; // [xsp+20h] [xbp-10h]

  v8 = *(unsigned int *)(result + 3632);
  if ( (_UNKNOWN *)a2 == &init_task )
    v9 = (unsigned int *)&vendor_data_pad;
  else
    v9 = (unsigned int *)(a2 + 5184);
  if ( (unsigned int)v8 >= 0x20 )
    goto LABEL_117;
  v7 = a4;
  v4 = a2;
  v5 = result;
  v6 = a3;
  v10 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v8);
  if ( (*((_BYTE *)v9 + 386) & 0x7Fu) <= 0x18 )
    *((_BYTE *)v9 + 386) = 0;
  if ( !a3 || (*(_BYTE *)v9 & 4) != 0 )
    return result;
  v11 = a3 / walt_scale_demand_divisor;
  if ( a4 >= 1 )
  {
    v12 = v9[83];
    v13 = a4 + 1;
    do
    {
      v9[v12 + 9] = v6;
      --v13;
      *((_WORD *)v9 + (int)v9[83] + 28) = v11;
      v12 = (int)(v9[83] + 1) % 5;
      v9[83] = v12;
    }
    while ( v13 > 1 );
    v7 = 0;
  }
  v14 = v9[9];
  v15 = v9[10];
  v16 = v9[11];
  v17 = v9[12];
  v18 = v9[13];
  v19 = v6;
  v9[6] = 0;
  v20 = ((unsigned __int64)(v14 + v15 + v16 + v17 + v18) * (unsigned __int128)0x3333333333333334uLL) >> 64;
  if ( sysctl_sched_window_stats_policy )
  {
    if ( sysctl_sched_window_stats_policy == 1 )
    {
      if ( (unsigned int)v15 > (unsigned int)v14 )
        LODWORD(v14) = v15;
      if ( (unsigned int)v16 > (unsigned int)v14 )
        LODWORD(v14) = v16;
      if ( (unsigned int)v17 > (unsigned int)v14 )
        LODWORD(v14) = v17;
      if ( (unsigned int)v18 <= (unsigned int)v14 )
        v19 = v14;
      else
        v19 = v18;
    }
    else
    {
      v19 = ((unsigned __int64)(v14 + v15 + v16 + v17 + v18) * (unsigned __int128)0x3333333333333334uLL) >> 64;
      if ( sysctl_sched_window_stats_policy != 3 )
      {
        if ( (unsigned int)v20 <= v6 )
          v19 = v6;
        else
          v19 = ((unsigned __int64)(v14 + v15 + v16 + v17 + v18) * (unsigned __int128)0x3333333333333334uLL) >> 64;
      }
    }
  }
  v57 = v20;
  v58 = v10;
  if ( *(int *)(a2 + 148) < 100 )
    goto LABEL_82;
  v21 = *v9;
  if ( (*v9 & 4) != 0 || !*((_QWORD *)v9 + 30) )
    goto LABEL_77;
  v22 = *(unsigned int *)(result + 3632);
  if ( (unsigned int)v22 >= 0x20 )
    goto LABEL_117;
  v23 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v22);
  if ( (sysctl_walt_features & 1) != 0 )
  {
    v24 = *((_QWORD *)v9 + 1) + 3000000000LL;
    if ( walt_clock_suspended == 1 )
    {
      if ( v24 < sched_clock_last )
LABEL_42:
        *((_BYTE *)v9 + 384) = 0;
    }
    else
    {
      if ( (*(_BYTE *)(result + 3392) & 4) == 0 )
      {
        v55 = v11;
        v53 = (char *)&walt_rq + *((_QWORD *)&_per_cpu_offset + v22);
        result = update_rq_clock(result);
        v23 = v53;
        LOWORD(v11) = v55;
        if ( *(_DWORD *)(v5 + 3392) <= 1u && (assert_clock_updated___already_done & 1) == 0 )
        {
          assert_clock_updated___already_done = 1;
          result = _warn_printk("rq->clock_update_flags < RQCF_ACT_SKIP");
          v23 = v53;
          LOWORD(v11) = v55;
          __break(0x800u);
        }
      }
      v25 = *(_QWORD *)(v5 + 3400);
      if ( v25 <= *((_QWORD *)v23 + 77) )
        v25 = *((_QWORD *)v23 + 77);
      if ( v24 < v25 )
        goto LABEL_42;
    }
  }
  if ( (sched_boost_type
     || !pipeline_nr && (!(sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres) || !have_heavy_list))
    && (sysctl_walt_features & 1) != 0 )
  {
    v26 = *((unsigned __int8 *)v9 + 384);
    if ( v19 <= v6 )
    {
      if ( v26 > 0xE5 )
      {
LABEL_55:
        v19 = walt_scale_demand_divisor << 10;
        v27 = *v9 | 2;
LABEL_58:
        *v9 = v27;
        goto LABEL_59;
      }
    }
    else if ( v26 >= 0xF3 )
    {
      goto LABEL_55;
    }
  }
  if ( (v21 & 2) != 0 )
  {
    v27 = *v9 & 0xFFFFFFFD;
    goto LABEL_58;
  }
LABEL_59:
  if ( *(_DWORD *)(v4 + 144) == 1 && !*(_BYTE *)(v4 + 273) )
  {
    v28 = *v9 & 2;
    if ( ((v21 >> 1) & 1) != v28 >> 1 )
    {
      v56 = v11;
      v54 = v23;
      result = sched_update_nr_prod(*(unsigned int *)(v5 + 3632), 0);
      v23 = v54;
      LOWORD(v11) = v56;
      v28 = *v9 & 2;
    }
    if ( (v21 & 2) != 0 )
    {
      if ( v28 )
        goto LABEL_69;
      v29 = -1;
    }
    else
    {
      if ( !v28 )
        goto LABEL_69;
      v29 = 1;
    }
    *((_DWORD *)v23 + 7) += v29;
  }
LABEL_69:
  if ( !*(_DWORD *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1)) )
    goto LABEL_117;
  v30 = *(_DWORD *)((char *)&walt_rq
                  + *((_QWORD *)&_per_cpu_offset
                    + __clz(__rbit64(*(unsigned int *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1)))))
                  + 632);
  v31 = (unsigned __int16)(v30 - (v30 >> 3));
  v32 = *((unsigned __int8 *)v9 + 384);
  if ( v31 <= (unsigned __int16)v11 )
  {
    if ( v32 > 0xF7 )
      v33 = -1;
    else
      v33 = v32 + 8;
    goto LABEL_76;
  }
  if ( *((_BYTE *)v9 + 384) )
  {
    v33 = v32 - 1;
LABEL_76:
    *((_BYTE *)v9 + 384) = v33;
  }
LABEL_77:
  if ( *(int *)(v4 + 148) >= 100 && (*(_BYTE *)v9 & 4) == 0 )
  {
    v34 = *(unsigned int *)(v4 + 40);
    if ( (unsigned int)v34 < 0x20 )
    {
      v35 = *((_QWORD *)&_per_cpu_offset + v34);
      if ( *(_DWORD *)(*(_QWORD *)((char *)&walt_rq + v35 + 8) + 32LL) == max_possible_cluster_id
        && !*(_DWORD *)((char *)&big_task_pid + v35)
        && *(_DWORD *)(v4 + 144)
        && !*(_BYTE *)(v4 + 273)
        && v9[7] < v19 )
      {
        force_big_task_pid_eval[v35] = 1;
      }
      goto LABEL_82;
    }
LABEL_117:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      result = _traceiter_sched_update_history(0, v5, v4, v6, v7);
      v52 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v52;
      if ( !v52 || !*(_QWORD *)(StatusReg + 16) )
        return preempt_schedule_notrace(result);
    }
    return result;
  }
LABEL_82:
  v36 = (unsigned __int16)v11 >> 6;
  if ( v36 >= 0xF )
    v36 = 15;
  if ( (v11 & 0xFFC0) != 0 )
    v37 = v36;
  else
    v37 = 1;
  pred_busy = get_pred_busy(v4, (unsigned int)v37);
  v39 = 0;
  v40 = (char *)(v9 + 35);
  do
  {
    if ( v37 == v39 )
    {
      v41 = (unsigned __int8)v40[v37];
      if ( v41 <= 0xF )
        v42 = 8;
      else
        v42 = 16;
      v43 = v42 ^ 0xFF;
      v44 = v41 + v42;
      v45 = v43 >= v41;
      LOWORD(v41) = *((_WORD *)v9 + 78) | (1 << v37);
      if ( !v45 )
        v44 = -1;
      v40[v37] = v44;
      goto LABEL_94;
    }
    v46 = (unsigned __int8)v40[v39];
    if ( v46 < 3 )
    {
      v40[v39] = 0;
      v41 = (unsigned __int16)v9[39] & ~(unsigned int)(1LL << v39);
LABEL_94:
      *((_WORD *)v9 + 78) = v41;
      goto LABEL_95;
    }
    v40[v39] = v46 - 2;
LABEL_95:
    ++v39;
  }
  while ( v39 != 16 );
  result = nbia_task_demand_boost(v4, pred_busy);
  if ( pred_busy <= (unsigned int)result )
    pred_busy = result;
  v47 = v19 / walt_scale_demand_divisor;
  if ( *(_DWORD *)(v4 + 144) == 1 && !*(_BYTE *)(v4 + 273) )
    result = fixup_walt_sched_stats_common(v5, v4, v47, pred_busy);
  v48 = sysctl_sched_min_task_util_for_colocation;
  *((_WORD *)v9 + 79) = v47;
  v9[7] = v19;
  v9[8] = v57;
  *((_WORD *)v9 + 80) = pred_busy;
  if ( v48 < (unsigned __int16)v47 )
  {
    v49 = sysctl_sched_task_unfilter_period;
    goto LABEL_109;
  }
  v50 = v9[55];
  if ( v50 )
  {
    v49 = (v50 - *((_DWORD *)v58 + 18)) & ~((v50 - *((_DWORD *)v58 + 18)) >> 31);
LABEL_109:
    v9[55] = v49;
  }
  return result;
}
