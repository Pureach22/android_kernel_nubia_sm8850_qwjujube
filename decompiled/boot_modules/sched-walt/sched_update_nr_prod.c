__int64 __fastcall sched_update_nr_prod(unsigned int a1, int a2, __int64 a3)
{
  unsigned int v3; // w19
  __int64 v4; // x20
  unsigned __int64 v5; // x21
  _QWORD *v6; // x23
  char *v7; // x24
  __int64 v8; // x25
  unsigned __int64 StatusReg; // x26
  __int64 v11; // x1
  __int64 v12; // x0
  __int64 v13; // x9
  char *v14; // x8
  __int64 v15; // x4
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  __int64 v18; // x24
  int v19; // w8
  __int64 v20; // x12
  unsigned __int64 v21; // x13
  _BOOL4 v22; // w14
  _BOOL4 v23; // w16
  _BOOL4 v24; // w15
  int v25; // w17
  unsigned __int64 v26; // x16
  unsigned __int64 v27; // x15
  char v28; // w4
  unsigned __int64 v29; // x17
  unsigned __int64 v30; // x4
  unsigned __int64 v31; // x4
  _BYTE *v32; // x5
  unsigned __int64 v33; // x6
  unsigned __int64 v34; // x5
  bool v35; // cc
  int v36; // w15
  int v37; // w14
  bool v38; // zf
  unsigned __int64 v39; // x14
  unsigned __int64 v40; // x14
  unsigned __int64 v41; // x2
  __int64 busy; // x0
  __int64 v44; // x8
  __int64 v45; // [xsp+8h] [xbp-8h]

  if ( a1 >= 0x20 )
  {
LABEL_53:
    __break(0x5512u);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      busy = _traceiter_sched_busy_hyst_time(0, v3, a3, v5);
      v44 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v44;
      if ( !v44 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(busy);
    }
  }
  else
  {
    v6 = &_per_cpu_offset;
    v7 = (char *)&nr_lock;
    v3 = a1;
    v4 = raw_spin_lock_irqsave((char *)&nr_lock + *((_QWORD *)&_per_cpu_offset + a1));
    v5 = *(_QWORD *)((char *)&nr + *((_QWORD *)&_per_cpu_offset + v3));
    v12 = sched_clock(v4, v11);
    v13 = *((_QWORD *)&_per_cpu_offset + v3);
    v14 = (char *)&last_time + v13;
    v15 = *(_QWORD *)((char *)&last_time + v13);
    v8 = v12 - v15;
    if ( v12 - v15 < 0 )
    {
      v45 = v12;
      printk_deferred(
        "WALT-BUG CPU%d; curr_time=%llu(0x%llx) is lesser than per_cpu_last_time=%llu(0x%llx) last_time_cpu=%d",
        v3,
        v45,
        v45,
        v15,
        *(_QWORD *)((char *)&last_time + v13),
        *(_DWORD *)((char *)&last_time_cpu + v13));
      if ( !in_sched_bug )
      {
        in_sched_bug = 1;
        walt_dump();
        __break(0x800u);
        JUMPOUT(0x2F3F8);
      }
      v12 = v45;
      v14 = (char *)&last_time + *((_QWORD *)&_per_cpu_offset + v3);
    }
    *(_QWORD *)v14 = v12;
    StatusReg = _ReadStatusReg(SP_EL0);
    *(_DWORD *)((char *)&last_time_cpu + *((_QWORD *)&_per_cpu_offset + v3)) = *(_DWORD *)(StatusReg + 40);
    *(_QWORD *)((char *)&nr + *((_QWORD *)&_per_cpu_offset + v3)) = (unsigned int)(*(_DWORD *)((char *)&runqueues
                                                                                             + *((_QWORD *)&_per_cpu_offset
                                                                                               + v3)
                                                                                             + 4)
                                                                                 + a2);
    v16 = *((_QWORD *)&_per_cpu_offset + v3);
    v17 = *(_QWORD *)((char *)&nr + v16);
    if ( v17 > *(_QWORD *)((char *)&nr_max + v16) )
      *(_QWORD *)((char *)&nr_max + v16) = v17;
    if ( a2 )
    {
      if ( *(_DWORD *)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset + v3) + 8] + 32LL) != max_possible_cluster_id
        || is_obet != 1
        || (v18 = v12,
            v19 = _sw_hweight64(*(unsigned int *)(*(_QWORD *)cpu_array + 8LL * (num_sched_clusters - 1))),
            v12 = v18,
            v7 = (char *)&nr_lock,
            (v19 & 0xFFFFFFFE) == 0)
        && !sched_boost_type
        && (pipeline_nr || sysctl_sched_heavy_nr | sysctl_sched_pipeline_util_thres && have_heavy_list) )
      {
        v20 = *((_QWORD *)&_per_cpu_offset + v3);
        v21 = *(_QWORD *)((char *)&hyst_time + v20);
        if ( v21
          || *(_QWORD *)((char *)&coloc_hyst_time + v20)
          || *(_QWORD *)((char *)&util_hyst_time + v20)
          || *(_QWORD *)((char *)&smart_freq_legacy_reason_hyst_ns + v20) )
        {
          if ( v5 < 3 )
          {
            v22 = 0;
            if ( (a2 & 0x80000000) == 0 )
              goto LABEL_19;
          }
          else
          {
            v22 = *(_QWORD *)((char *)&nr + v20) < 3u;
            if ( (a2 & 0x80000000) == 0 )
            {
LABEL_19:
              v23 = 0;
              v24 = 0;
              v25 = 0;
LABEL_33:
              v36 = v22 || v24;
              v37 = v22 || v23;
              if ( !v36 )
                v21 = 0;
              v38 = v37 == 1;
              v39 = 0;
              if ( v38 )
                v39 = *(_QWORD *)((char *)&coloc_hyst_time + v20);
              if ( v21 <= v39 )
                v21 = v39;
              if ( v25 )
                v40 = *(_QWORD *)((char *)&util_hyst_time + v20);
              else
                v40 = 0;
              if ( v21 <= v40 )
                v21 = v40;
              if ( v21 <= *(_QWORD *)((char *)&smart_freq_legacy_reason_hyst_ns + v20) )
                v41 = *(_QWORD *)((char *)&smart_freq_legacy_reason_hyst_ns + v20);
              else
                v41 = v21;
              if ( v41 )
                *(_QWORD *)((char *)&busy_hyst_end_time + v20) = v41 + v12;
              goto LABEL_50;
            }
          }
          v26 = *(_QWORD *)&walt_rq[v20 + 40];
          v27 = *(_QWORD *)&walt_rq[v20 + 632];
          v28 = 0;
          v29 = 0;
          if ( v26 >= v27 )
            v26 = *(_QWORD *)&walt_rq[v20 + 632];
          v24 = 10 * v26 > v27;
          v23 = v26 > *(_QWORD *)((char *)&coloc_hyst_busy + v20);
          a3 = -1;
          while ( 1 )
          {
            v30 = _cpu_possible_mask & (unsigned __int64)(-1LL << v28);
            if ( !v30 )
            {
LABEL_31:
              v25 = 0;
              goto LABEL_33;
            }
            if ( v3 > 7 )
              goto LABEL_53;
            v31 = __clz(__rbit64(v30));
            v32 = &walt_rq[*((_QWORD *)&_per_cpu_offset + v31)];
            v33 = *((_QWORD *)v32 + 5);
            v34 = *((_QWORD *)v32 + 79);
            if ( v33 < v34 )
              v34 = v33;
            v29 += v34;
            if ( v29 >= *((unsigned int *)&sysctl_sched_util_busy_hyst_cpu_util + v3) )
              break;
            v35 = v31 > 0x1E;
            v28 = v31 + 1;
            if ( v35 )
              goto LABEL_31;
          }
          v25 = 1;
          goto LABEL_33;
        }
      }
    }
  }
LABEL_50:
  *(_QWORD *)((char *)&nr_prod_sum + v6[v3]) += v8 * v5;
  *(_QWORD *)((char *)&nr_big_prod_sum + v6[v3]) += v8
                                                  * (unsigned int)((__int64 (__fastcall *)(_QWORD))walt_big_tasks)(v3);
  *(_QWORD *)((char *)&nr_giant_prod_sum + v6[v3]) += v8 * (int)walt_giant_tasks(v3);
  return raw_spin_unlock_irqrestore(&v7[v6[v3]], v4);
}
