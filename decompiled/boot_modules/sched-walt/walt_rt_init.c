__int64 walt_rt_init()
{
  char v0; // w12
  unsigned __int64 v1; // x12
  unsigned __int64 v2; // x12
  __int64 v3; // x13
  bool v4; // cf

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
    *(_QWORD *)((char *)&walt_local_cpu_mask + v3) = 0;
  }
  while ( !v4 );
  android_rvh_probe_register(&_tracepoint_android_rvh_select_task_rq_rt, walt_select_task_rq_rt, 0);
  return android_rvh_probe_register(&_tracepoint_android_rvh_find_lowest_rq, walt_rt_find_lowest_rq, 0);
}
