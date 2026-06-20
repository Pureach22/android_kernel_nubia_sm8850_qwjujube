__int64 __fastcall sched_long_running_rt_task_ms_handler(
        _QWORD *a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 a5)
{
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x10
  unsigned int v13; // w20
  _QWORD v15[8]; // [xsp+0h] [xbp-40h] BYREF

  v15[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[4];
  v10 = a1[5];
  v15[6] = a1[6];
  v15[4] = v9;
  v15[5] = v10;
  v11 = a1[1];
  v15[0] = *a1;
  v15[1] = v11;
  v12 = a1[3];
  v15[2] = a1[2];
  v15[3] = v12;
  mutex_lock(&sched_long_running_rt_task_ms_handler_mutex);
  v13 = proc_douintvec_minmax(v15, a2, a3, a4, a5);
  if ( (unsigned int)(sysctl_sched_long_running_rt_task_ms - 1) <= 0x31E )
    sysctl_sched_long_running_rt_task_ms = 800;
  if ( a2 && (long_running_rt_task_trace_rgstrd & 1) == 0 )
  {
    tracepoint_probe_register(&_tracepoint_sched_switch, rt_task_arrival_marker, 0);
    tracepoint_probe_register(&_tracepoint_android_vh_scheduler_tick, &long_running_rt_task_notifier, 0);
    long_running_rt_task_trace_rgstrd = 1;
  }
  mutex_unlock(&sched_long_running_rt_task_ms_handler_mutex);
  _ReadStatusReg(SP_EL0);
  return v13;
}
