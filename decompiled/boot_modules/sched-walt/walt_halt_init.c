__int64 walt_halt_init()
{
  unsigned __int64 v0; // x0
  __int64 v1; // x19
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 99;
  v0 = kthread_create_on_node(try_drain_rqs, &drain_data, 0xFFFFFFFFLL, "halt_drain_rqs");
  if ( v0 >= 0xFFFFFFFFFFFFF001LL )
  {
    walt_drain_thread = v0;
    result = printk(&unk_6215C);
  }
  else
  {
    v1 = v0;
    wake_up_process(v0);
    walt_drain_thread = v1;
    sched_setscheduler_nocheck(v1, 1, &v3);
    android_rvh_probe_register(&_tracepoint_android_rvh_get_nohz_timer_target, android_rvh_get_nohz_timer_target, 0);
    android_rvh_probe_register(
      &_tracepoint_android_rvh_set_cpus_allowed_by_task,
      android_rvh_set_cpus_allowed_by_task,
      0);
    android_rvh_probe_register(&_tracepoint_android_rvh_rto_next_cpu, android_rvh_rto_next_cpu, 0);
    result = android_rvh_probe_register(&_tracepoint_android_rvh_is_cpu_allowed, android_rvh_is_cpu_allowed, 0);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
