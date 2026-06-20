__int64 __fastcall sched_dynamic_tp_handler(__int64 *a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v9; // x8
  __int64 v10; // x9
  _DWORD *v11; // x23
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v14; // x8
  __int64 v15; // x9
  int v16; // w25
  unsigned int v17; // w19
  char v18; // w13
  unsigned __int64 v19; // x13
  unsigned __int64 v20; // x13
  __int64 v21; // x14
  bool v22; // cf
  _QWORD v24[8]; // [xsp+0h] [xbp-40h] BYREF

  v24[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[4];
  v10 = a1[5];
  v11 = (_DWORD *)a1[1];
  v24[6] = a1[6];
  v13 = a1[2];
  v12 = a1[3];
  v24[4] = v9;
  v24[5] = v10;
  v14 = *a1;
  v15 = a1[1];
  v24[2] = v13;
  v24[3] = v12;
  v24[0] = v14;
  v24[1] = v15;
  mutex_lock(&sched_dynamic_tp_handler_mutex);
  v16 = sysctl_sched_dynamic_tp_enable;
  v17 = proc_dointvec_minmax(v24, a2, a3, a4, a5);
  if ( a2 && !v17 && v16 != sysctl_sched_dynamic_tp_enable )
  {
    if ( *v11 )
    {
      tracepoint_probe_register(&_tracepoint_sched_overutilized_tp, sched_overutilized, 0);
      v18 = 0;
      do
      {
        v19 = (unsigned int)(-1LL << v18) & _cpu_possible_mask;
        if ( !(_DWORD)v19 )
          break;
        v20 = __clz(__rbit64(v19));
        v21 = *((_QWORD *)&_per_cpu_offset + v20);
        v22 = v20 >= 0x1F;
        v18 = v20 + 1;
        *(_DWORD *)((char *)&old_pid + v21) = -1;
      }
      while ( !v22 );
      if ( (_cpuhp_setup_state(193, "tracectr_cpu_hotplug", 0, &tracectr_cpu_hotplug_coming_up, 0, 0) & 0x80000000) == 0 )
        tracepoint_probe_register(&_tracepoint_sched_switch, tracectr_notifier, 0);
    }
    else
    {
      tracepoint_probe_unregister(&_tracepoint_sched_overutilized_tp, sched_overutilized, 0);
      tracepoint_probe_unregister(&_tracepoint_sched_switch, tracectr_notifier, 0);
      _cpuhp_remove_state(193, 0);
    }
  }
  mutex_unlock(&sched_dynamic_tp_handler_mutex);
  _ReadStatusReg(SP_EL0);
  return v17;
}
