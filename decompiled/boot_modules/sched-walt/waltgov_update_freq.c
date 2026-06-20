__int64 __fastcall waltgov_update_freq(__int64 result, unsigned __int64 a2, int a3)
{
  int v3; // w22
  _QWORD *v4; // x26
  __int64 v5; // x21
  char v6; // w27
  _QWORD *v8; // x19
  unsigned int v9; // w1
  __int64 v10; // x2
  __int64 v11; // x3
  __int64 v12; // x4
  __int64 v13; // x5
  __int64 v14; // x6
  unsigned int v15; // w7
  unsigned __int64 v16; // x9
  unsigned __int64 v17; // x24
  unsigned __int64 v18; // x23
  __int64 v19; // x28
  void *v20; // x8
  unsigned __int64 v21; // x0
  unsigned __int64 v22; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v24; // x10
  unsigned __int64 v25; // x11
  __int64 v26; // x10
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x10
  unsigned __int64 v29; // x11
  _BOOL4 v30; // w8
  char v31; // w8
  unsigned __int64 v32; // x8
  unsigned __int64 v33; // x25
  unsigned int v34; // w9
  __int64 v35; // x1
  unsigned __int64 v36; // x23
  __int64 v37; // x0
  __int64 v38; // x8

  v4 = *(_QWORD **)(result + 8);
  v5 = result;
  v6 = a3;
  if ( (a3 & 0x200) != 0 )
  {
    v8 = v4 + 19;
    raw_spin_lock(v4 + 19);
    *((_DWORD *)v4 + 51) = get_cluster_ipc_level_freq(*(unsigned int *)(v5 + 16), a2);
    v20 = (void *)*(unsigned int *)(v5 + 16);
    if ( (unsigned int)v20 < 0x20 )
    {
      ((void (__fastcall *)(_QWORD))update_smart_freq_capacities_one_cluster)(*(_QWORD *)&walt_rq[*((_QWORD *)&_per_cpu_offset
                                                                                                  + (_QWORD)v20)
                                                                                                + 8]);
      if ( (unsigned int)waltgov_next_freq_shared(v5, a2) )
      {
        v21 = *v4;
        if ( *(_BYTE *)(*v4 + 609LL) != 1 )
          goto LABEL_14;
        goto LABEL_11;
      }
      return raw_spin_unlock(v8);
    }
    goto LABEL_47;
  }
  v3 = a3;
  if ( (a3 & 8) == 0 || (*(_BYTE *)(v4[5] + 216LL) & 1) != 0 )
  {
    v8 = v4 + 19;
    *(_QWORD *)(result + 64) = cpu_util_freq_walt(
                                 *(_DWORD *)(result + 16),
                                 (unsigned __int64 *)(result + 24),
                                 result + 76);
    *(_DWORD *)(v5 + 72) = v3;
    raw_spin_lock(v4 + 19);
    v17 = v4[1];
    v18 = *(_QWORD *)(v5 + 48);
    v19 = *(unsigned int *)(*v4 + 60LL);
    if ( v17 > v18 )
    {
      printk_deferred("============ WALT CPUFREQ DUMP START ==============\n");
      v31 = 0;
      do
      {
        v32 = (unsigned int)(-1LL << v31) & _cpu_online_mask;
        if ( !(_DWORD)v32 )
          break;
        v33 = __clz(__rbit64(v32));
        printk_deferred(
          "cpu=%d walt_load->ws=%llu and policy->last_ws=%llu\n",
          *(_DWORD *)((char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v33) + 16),
          *(_QWORD *)((char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v33) + 48),
          *(_QWORD *)(*(_QWORD *)((char *)&waltgov_cpu + *((_QWORD *)&_per_cpu_offset + v33) + 8) + 8LL));
        v31 = v33 + 1;
      }
      while ( v33 < 0x1F );
      printk_deferred("============ WALT CPUFREQ DUMP END  ==============\n");
      LOBYTE(v16) = -34;
      if ( (unsigned int)sysctl_panic_on_walt_bug >> 8 == 4539614 )
      {
        if ( (sysctl_panic_on_walt_bug & 0x10) != 0 )
          goto LABEL_37;
        while ( (sysctl_panic_on_walt_bug & 2) != 0 )
        {
          LOBYTE(v16) = in_sched_bug;
          if ( in_sched_bug )
            break;
          in_sched_bug = 1;
          walt_dump();
          __break(0x800u);
LABEL_37:
          printk_deferred(
            "WALT-BUG policy->related_cpus=0x%lx curr_ws=%llu < last_ws=%llu",
            *(_QWORD *)(*v4 + 8LL),
            v18,
            v17);
        }
      }
    }
    v20 = &cpu_scale;
    if ( v17 >= v18 )
    {
      v11 = v4[4];
    }
    else
    {
      if ( v17 + (unsigned int)sched_ravg_window >= v18 )
      {
        v24 = v4[1] + (unsigned int)sched_ravg_window;
        if ( v24 >= v18 )
          v24 = v18;
        v25 = v4[2] + (v24 - v4[3]) * v19 / 0xF4240;
        LODWORD(v19) = (unsigned int)v25 / (sched_ravg_window / 0xF4240u);
        v4[2] = v25;
        v4[3] = v24;
      }
      else
      {
        v4[3] = v18;
      }
      v16 = *v4;
      v26 = *(unsigned int *)(*v4 + 28LL);
      if ( (unsigned int)v26 >= 0x20 )
        goto LABEL_47;
      v27 = *(unsigned int *)(v16 + 40);
      v28 = *(_QWORD *)((char *)&cpu_scale + *((_QWORD *)&_per_cpu_offset + v26));
      v4[1] = v18;
      v4[2] = 0;
      v29 = v28 / v27;
      v16 = v28 % v27 * (unsigned int)v19 / v27;
      v11 = v16 + v29 * (unsigned int)v19;
      v4[4] = v11;
    }
    v9 = *(_DWORD *)(v5 + 16);
    if ( v9 < 0x20 )
    {
LABEL_23:
      if ( *((_BYTE *)v4 + 392) == 1 )
      {
        *((_WORD *)v4 + 196) = 256;
        v30 = 1;
        if ( (v6 & 2) != 0 )
          return raw_spin_unlock(v8);
      }
      else
      {
        v30 = (__int64)(a2 - v4[20]) >= v4[21];
        if ( (v6 & 2) != 0 )
          return raw_spin_unlock(v8);
      }
      if ( v30 && (unsigned int)waltgov_next_freq_shared(v5, a2) )
      {
        v21 = *v4;
        if ( *(_BYTE *)(*v4 + 609LL) != 1 )
        {
LABEL_14:
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                           + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
              & 1) != 0 )
          {
            irq_work_queue(v4 + 26);
          }
          else
          {
            v34 = __clz(__rbit64(_cpu_online_mask));
            if ( _cpu_online_mask )
              v35 = v34;
            else
              v35 = 32;
            irq_work_queue_on(v4 + 26, v35);
          }
          return raw_spin_unlock(v8);
        }
LABEL_11:
        v22 = v4[1] + (unsigned int)sched_ravg_window;
        if ( v22 >= a2 )
          v22 = a2;
        v4[2] += (v22 - v4[3]) * *(unsigned int *)(v21 + 60) / 0xF4240;
        v4[3] = v22;
        cpufreq_driver_fast_switch();
      }
      return raw_spin_unlock(v8);
    }
LABEL_47:
    __break(0x5512u);
    v36 = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + (((unsigned __int64)*(unsigned int *)(v36 + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(v36 + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(v36 + 16);
      v37 = _traceiter_waltgov_util_update(0, v9, v10, v11, v12, v13, v14, v15, v3, (int)v20, v16);
      v38 = *(_QWORD *)(v36 + 16) - 1LL;
      *(_DWORD *)(v36 + 16) = v38;
      if ( !v38 || !*(_QWORD *)(v36 + 16) )
        preempt_schedule_notrace(v37);
    }
    goto LABEL_23;
  }
  return result;
}
