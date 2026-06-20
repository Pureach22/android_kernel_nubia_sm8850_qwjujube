__int64 setup_events()
{
  __int64 v0; // x19
  __int64 v1; // x8
  char v2; // w8
  unsigned int v3; // w0
  unsigned int v4; // w22
  __int64 v5; // x0
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x21
  __int64 v9; // x25
  unsigned __int64 v10; // x26
  _DWORD *v11; // x22
  unsigned int v12; // w23
  char v13; // w8
  unsigned int v14; // w20
  int v15; // w0
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x21
  __int64 v18; // x22
  unsigned int v19; // w8
  unsigned __int64 StatusReg; // x20
  __int64 v22; // x21
  __int64 (*v23)(void); // x0

  v0 = _kmalloc_cache_noprof(cpus_read_lock, 3520, 136);
  if ( v0 )
  {
    while ( 2 )
    {
      v1 = *(_QWORD *)(v0 + 40);
      *(_DWORD *)(v0 + 4) = 136;
      *(_QWORD *)(v0 + 40) = v1 | 4;
      cpus_read_lock();
      v2 = 0;
      v3 = 0;
      while ( 1 )
      {
        v7 = (unsigned int)(-1LL << v2) & _cpu_possible_mask;
        if ( !(_DWORD)v7 )
        {
LABEL_12:
          v14 = v3;
          v15 = _cpuhp_setup_state_cpuslocked(
                  193,
                  "QCOM_PMU",
                  0,
                  qcom_pmu_hotplug_coming_up,
                  qcom_pmu_hotplug_going_down,
                  0);
          if ( v15 < 0 )
          {
            v14 = v15;
            printk(&unk_8DE8);
            cpuhp_state = v14;
            printk(&unk_8FBE);
          }
          else
          {
            cpuhp_state = v15;
          }
LABEL_45:
          cpus_read_unlock();
          if ( v14 != -517 && v14 != cpuhp_state )
          {
            tracepoint_probe_register(&_tracepoint_android_vh_cpu_idle_enter, qcom_pmu_idle_enter_notif, 0);
            tracepoint_probe_register(&_tracepoint_android_vh_cpu_idle_exit, qcom_pmu_idle_exit_notif, 0);
            cpu_pm_register_notifier(&memlat_event_pm_nb);
          }
          kfree(v0);
          return v14;
        }
        v8 = __clz(__rbit64(v7));
        v9 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[v8]);
        if ( *(_DWORD *)(v9 + 328) )
          break;
LABEL_3:
        v4 = v3;
        v5 = raw_spin_lock_irqsave(v9 + 336);
        v6 = _cpu_online_mask;
        *(_BYTE *)v9 = 0;
        *(_BYTE *)(v9 + 2) = 0;
        *(_BYTE *)(v9 + 1) = ((v6 >> v8) & 1) == 0;
        raw_spin_unlock_irqrestore(v9 + 336, v5);
        v3 = v4;
        v2 = v8 + 1;
        if ( v8 >= 0x1F )
          goto LABEL_12;
      }
      v10 = 0;
      v11 = (_DWORD *)(v9 + 8);
      while ( v10 != 9 )
      {
        v3 = set_event(v11, (unsigned int)v8, v0);
        if ( (v3 & 0x80000000) != 0 )
        {
          v12 = v3;
          printk(&unk_8E43);
          v3 = 0;
          *v11 = 0;
          if ( v12 == -517 )
          {
            v13 = 0;
            do
            {
              v16 = (unsigned int)(-1LL << v13) & _cpu_possible_mask;
              if ( !(_DWORD)v16 )
                break;
              v17 = __clz(__rbit64(v16));
              v18 = *(_QWORD *)((char *)&cpu_ev_data + _per_cpu_offset[v17]);
              v19 = *(_DWORD *)(v18 + 328);
              if ( v19 )
              {
                if ( *(_QWORD *)(v18 + 16) )
                {
                  perf_event_release_kernel();
                  v19 = *(_DWORD *)(v18 + 328);
                  *(_QWORD *)(v18 + 16) = 0;
                }
                if ( v19 >= 2 )
                {
                  if ( *(_QWORD *)(v18 + 56) )
                  {
                    perf_event_release_kernel();
                    v19 = *(_DWORD *)(v18 + 328);
                    *(_QWORD *)(v18 + 56) = 0;
                  }
                  if ( v19 >= 3 )
                  {
                    if ( *(_QWORD *)(v18 + 96) )
                    {
                      perf_event_release_kernel();
                      v19 = *(_DWORD *)(v18 + 328);
                      *(_QWORD *)(v18 + 96) = 0;
                    }
                    if ( v19 >= 4 )
                    {
                      if ( *(_QWORD *)(v18 + 136) )
                      {
                        perf_event_release_kernel();
                        v19 = *(_DWORD *)(v18 + 328);
                        *(_QWORD *)(v18 + 136) = 0;
                      }
                      if ( v19 >= 5 )
                      {
                        if ( *(_QWORD *)(v18 + 176) )
                        {
                          perf_event_release_kernel();
                          v19 = *(_DWORD *)(v18 + 328);
                          *(_QWORD *)(v18 + 176) = 0;
                        }
                        if ( v19 >= 6 )
                        {
                          if ( *(_QWORD *)(v18 + 216) )
                          {
                            perf_event_release_kernel();
                            v19 = *(_DWORD *)(v18 + 328);
                            *(_QWORD *)(v18 + 216) = 0;
                          }
                          if ( v19 >= 7 )
                          {
                            if ( *(_QWORD *)(v18 + 256) )
                            {
                              perf_event_release_kernel();
                              v19 = *(_DWORD *)(v18 + 328);
                              *(_QWORD *)(v18 + 256) = 0;
                            }
                            if ( v19 >= 8 )
                            {
                              if ( *(_QWORD *)(v18 + 296) )
                              {
                                perf_event_release_kernel();
                                v19 = *(_DWORD *)(v18 + 328);
                                *(_QWORD *)(v18 + 296) = 0;
                              }
                              if ( v19 >= 9 )
                              {
                                if ( *(_QWORD *)(v18 + 336) )
                                {
                                  perf_event_release_kernel();
                                  v19 = *(_DWORD *)(v18 + 328);
                                  *(_QWORD *)(v18 + 336) = 0;
                                }
                                if ( v19 > 9 )
                                  goto LABEL_50;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
              v13 = v17 + 1;
            }
            while ( v17 < 0x1F );
            v14 = -517;
            goto LABEL_45;
          }
        }
        ++v10;
        v11 += 10;
        if ( v10 >= *(unsigned int *)(v9 + 328) )
          goto LABEL_3;
      }
LABEL_50:
      __break(0x5512u);
      StatusReg = _ReadStatusReg(SP_EL0);
      v22 = *(_QWORD *)(StatusReg + 80);
      v23 = cpus_read_lock;
      *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
      v0 = _kmalloc_cache_noprof(v23, 3520, 136);
      *(_QWORD *)(StatusReg + 80) = v22;
      if ( v0 )
        continue;
      break;
    }
  }
  return 4294967284LL;
}
