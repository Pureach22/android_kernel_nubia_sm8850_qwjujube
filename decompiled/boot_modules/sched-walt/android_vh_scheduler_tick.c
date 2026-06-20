__int64 __fastcall android_vh_scheduler_tick(__int64 result, __int64 a2)
{
  unsigned __int64 v2; // x19
  __int64 *v3; // x20
  char *v4; // x8
  char *v5; // x22
  _DWORD *v6; // x8
  int v7; // w23
  __int64 lock; // x0
  char *v9; // x8
  _QWORD *v10; // x8
  _QWORD *v11; // x21
  unsigned int v12; // w9
  void *v13; // x1
  __int64 v14; // x2
  __int64 v15; // x3
  __int64 v16; // x4
  __int64 v17; // x5
  __int64 v18; // x6
  __int64 v19; // x7
  unsigned __int64 v20; // x8
  char *v21; // x9
  __int64 v22; // x10
  unsigned __int64 v23; // x11
  __int64 v24; // x12
  unsigned __int64 v25; // x13
  __int64 v26; // x16
  __int64 v27; // x13
  __int64 v28; // x17
  __int64 v29; // x16
  unsigned __int64 StatusReg; // x1
  unsigned __int64 v31; // x0
  __int64 v32; // x16
  __int64 v33; // x16
  int v34; // w14
  char v35; // w10
  __int64 v36; // x23
  __int64 v37; // x1
  __int64 (__fastcall *v38)(unsigned __int64, __int64, __int64); // x27
  unsigned __int64 v39; // x23
  __int64 v40; // x25
  unsigned __int64 v41; // x26
  __int64 v42; // x24
  unsigned __int64 v43; // x27
  __int64 v44; // x14

  v2 = *(unsigned int *)(a2 + 3632);
  v3 = (__int64 *)a2;
  if ( !tick_sched_clock )
  {
    tick_sched_clock = *(_QWORD *)(a2 + 3400) - 20000LL;
    result = complete(&tick_sched_clock_completion);
  }
  if ( (walt_disabled & 1) == 0 )
  {
    v4 = (char *)v3[418];
    v5 = (_BYTE *)&unk_1440;
    if ( v4 == (char *)&init_task )
      v6 = &vendor_data_pad;
    else
      v6 = v4 + 5184;
    v7 = v6[7];
    lock = _rcu_read_lock(result);
    v9 = (char *)v3[418];
    if ( v9 == (char *)&init_task )
      v10 = &vendor_data_pad;
    else
      v10 = v9 + 5184;
    v11 = (_QWORD *)v10[30];
    if ( v11 )
    {
      v5 = (char *)v3[425];
      if ( sysctl_sched_user_hint == 1000
        || (*((_DWORD *)v10 + 7) - v7 >= 0 ? (v12 = *((_DWORD *)v10 + 7) - v7) : (v12 = v7 - *((_DWORD *)v10 + 7)),
            v12 > (unsigned int)sched_ravg_window >> 2
         || (unsigned __int64)&v5[-v11[8]] > (unsigned int)sched_ravg_window) )
      {
        raw_spin_lock((char *)v11 + 4);
        set_preferred_cluster(v11, v5);
        lock = raw_spin_unlock((char *)v11 + 4);
      }
    }
    _rcu_read_unlock(lock);
    result = walt_lb_tick(v3);
    if ( (unsigned int)v2 >= 0x20 )
      goto LABEL_68;
    if ( smart_freq_init_done == 1 )
    {
      v11 = &_per_cpu_offset;
      v26 = *((_QWORD *)&_per_cpu_offset + v2);
      v27 = *(_QWORD *)((char *)&walt_rq + v26 + 8);
      v23 = *(_QWORD *)(v27 + 480);
      if ( (*(_BYTE *)(v23 + 24) & 0x1F) != 0 )
      {
        v21 = (char *)&ipc_level;
        v20 = (unsigned __int64)&ipc_deactivate_ns;
        v24 = *(unsigned int *)((char *)&ipc_level + v26);
        v22 = *(_QWORD *)((char *)&ipc_deactivate_ns + v26);
        v28 = *(_QWORD *)((char *)&cycle_cnt + v26);
        v29 = *(_QWORD *)((char *)&intr_cnt + v26);
        StatusReg = _ReadStatusReg(AMEVCNTR00_EL0);
        *(_QWORD *)((char *)&cycle_cnt + *((_QWORD *)&_per_cpu_offset + v2)) = StatusReg;
        v31 = _ReadStatusReg(AMEVCNTR02_EL0);
        *(_QWORD *)((char *)&intr_cnt + *((_QWORD *)&_per_cpu_offset + v2)) = v31;
        if ( v28 && StatusReg - v28 > *(_QWORD *)(*(_QWORD *)(v27 + 480) + 16LL) )
          v25 = 100 * (v31 - v29) / (StatusReg - v28);
        else
          v25 = 0;
        v5 = (char *)&runqueues;
        v13 = &last_ipc_update;
        *(_QWORD *)((char *)&ipc_cnt + *((_QWORD *)&_per_cpu_offset + v2)) = v25;
        v32 = *((_QWORD *)&_per_cpu_offset + v2);
        result = *(_QWORD *)((char *)&runqueues + v32 + 3400);
        *(_QWORD *)((char *)&last_ipc_update + v32) = result;
        v33 = *((_QWORD *)&_per_cpu_offset + v2);
        v14 = *(_QWORD *)((char *)&cycle_cnt + v33);
        v15 = *(_QWORD *)((char *)&intr_cnt + v33);
        v16 = *(_QWORD *)((char *)&ipc_cnt + v33);
        v17 = *(_QWORD *)((char *)&last_ipc_update + v33);
        v18 = *(_QWORD *)((char *)&ipc_deactivate_ns + v33);
        v19 = *(_QWORD *)((char *)&runqueues + v33 + 3400);
        while ( 1 )
        {
          if ( v25 >= *(_QWORD *)(v23 + 296) )
          {
            if ( v25 >= *(_QWORD *)(v23 + 320) )
            {
              if ( v25 >= *(_QWORD *)(v23 + 344) )
              {
                if ( v25 >= *(_QWORD *)(v23 + 368) )
                {
                  if ( v25 < *(_QWORD *)(v23 + 392) )
                    LODWORD(v25) = 4;
                  else
                    LODWORD(v25) = 5;
                }
                else
                {
                  LODWORD(v25) = 3;
                }
              }
              else
              {
                LODWORD(v25) = 2;
              }
            }
            else
            {
              LODWORD(v25) = 1;
            }
          }
          else
          {
            LODWORD(v25) = 0;
          }
          if ( (unsigned int)v25 >= 4 )
            v25 = 4;
          else
            v25 = (unsigned int)v25;
          if ( (_DWORD)v25 == (_DWORD)v24 && tickless_mode[v11[v2]] != 1 )
          {
            v34 = 0;
            if ( (unsigned int)v25 >= (unsigned int)v24 )
              goto LABEL_53;
          }
          else
          {
            v34 = 1;
            if ( (unsigned int)v25 >= (unsigned int)v24 )
              goto LABEL_53;
          }
          if ( (unsigned int)v24 > 4 )
            goto LABEL_68;
          v23 = *(_QWORD *)(v23 + 296 + 24LL * (unsigned int)v24 + 16);
          if ( v23 )
          {
            v24 = v3[425];
            if ( !v22 )
            {
              *(_QWORD *)(v11[v2] + v20) = v24;
              return result;
            }
            if ( v23 <= v24 - v22 )
              v35 = v34;
            else
              v35 = 0;
            if ( (v35 & 1) == 0 )
              return result;
            goto LABEL_54;
          }
LABEL_53:
          if ( !v34 )
            return result;
LABEL_54:
          v22 = v11[v2];
          v3 = &cluster_head;
          *(_DWORD *)&v21[v22] = v25;
          v21 = (char *)v11[v2];
          *(_QWORD *)&v21[v20] = 0;
          v36 = cluster_head;
          if ( (__int64 *)cluster_head == &cluster_head )
            return result;
          while ( 1 )
          {
            v20 = *(unsigned int *)(v36 + 16);
            if ( !*(_DWORD *)(v36 + 16) )
              break;
            v20 = *(unsigned int *)&v5[v11[__clz(__rbit64(v20))] + 3632];
            if ( (unsigned int)v20 >= 0x20 )
              break;
            v2 = *(_QWORD *)((char *)&waltgov_cb_data + v11[v20]);
            if ( v2 )
            {
              v38 = *(__int64 (__fastcall **)(unsigned __int64, __int64, __int64))v2;
              if ( walt_clock_suspended == 1 )
                v37 = sched_clock_last;
              else
                v37 = sched_clock(result, v13);
              if ( *((_DWORD *)v38 - 1) != 1756229429 )
                __break(0x823Bu);
              result = v38(v2, v37, 512);
            }
            v36 = *(_QWORD *)v36;
            if ( (__int64 *)v36 == &cluster_head )
              return result;
          }
LABEL_68:
          __break(0x5512u);
          v39 = _ReadStatusReg(SP_EL0);
          if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                           + (((unsigned __int64)*(unsigned int *)(v39 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v39 + 40))
              & 1) != 0 )
          {
            v40 = v22;
            v41 = v23;
            v42 = v24;
            v43 = v25;
            ++*(_DWORD *)(v39 + 16);
            result = _traceiter_ipc_update(0, (unsigned int)v2, v14, v15, v16, v17, v18, v19);
            v21 = (char *)&ipc_level;
            v20 = (unsigned __int64)&ipc_deactivate_ns;
            v44 = *(_QWORD *)(v39 + 16) - 1LL;
            *(_DWORD *)(v39 + 16) = v44;
            if ( !v44 || (v25 = v43, v24 = v42, v23 = v41, v22 = v40, !*(_QWORD *)(v39 + 16)) )
            {
              result = preempt_schedule_notrace(result);
              v25 = v43;
              v24 = v42;
              v23 = v41;
              v22 = v40;
              v21 = (char *)&ipc_level;
              v20 = (unsigned __int64)&ipc_deactivate_ns;
            }
          }
        }
      }
    }
  }
  return result;
}
