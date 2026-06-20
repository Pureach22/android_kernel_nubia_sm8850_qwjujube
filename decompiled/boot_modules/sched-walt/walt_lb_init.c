__int64 walt_lb_init()
{
  char v0; // w12
  unsigned __int64 v1; // x12
  unsigned __int64 v2; // x12
  __int64 v3; // x13
  bool v4; // cf
  _QWORD *v5; // x13
  __int64 result; // x0
  char v7; // w11
  unsigned __int64 v8; // x11
  unsigned __int64 v9; // x11
  _QWORD *v10; // x12

  v0 = 0;
  do
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v1 )
      break;
    v2 = __clz(__rbit64(v1));
    v3 = *((_QWORD *)&_per_cpu_offset + v2);
    v4 = v2 >= 0x1F;
    v0 = v2 + 1;
    v5 = (_QWORD *)((char *)&walt_lb_rotate_works + v3);
    *v5 = 0xFFFFFFFE00000LL;
    v5[1] = v5 + 1;
    v5[2] = v5 + 1;
    v5[3] = walt_lb_rotate_work_func;
  }
  while ( !v4 );
  android_rvh_probe_register(&_tracepoint_android_rvh_sched_nohz_balancer_kick, walt_nohz_balancer_kick, 0);
  android_rvh_probe_register(&_tracepoint_android_rvh_can_migrate_task, &walt_can_migrate_task, 0);
  android_rvh_probe_register(&_tracepoint_android_rvh_find_busiest_queue, walt_find_busiest_queue, 0);
  android_rvh_probe_register(&_tracepoint_android_rvh_sched_newidle_balance, walt_sched_newidle_balance, 0);
  result = android_rvh_probe_register(&_tracepoint_android_rvh_find_new_ilb, walt_find_new_ilb, 0);
  v7 = 0;
  do
  {
    v8 = (unsigned int)(-1LL << v7) & _cpu_possible_mask;
    if ( !(_DWORD)v8 )
      break;
    v9 = __clz(__rbit64(v8));
    v4 = v9 >= 0x1F;
    v10 = (_QWORD *)((char *)&nib_csd + *((_QWORD *)&_per_cpu_offset + v9));
    v10[2] = walt_smp_newidle_balance;
    v10[3] = v9;
    v7 = v9 + 1;
    *v10 = 0;
    v10[1] = 0;
  }
  while ( !v4 );
  return result;
}
