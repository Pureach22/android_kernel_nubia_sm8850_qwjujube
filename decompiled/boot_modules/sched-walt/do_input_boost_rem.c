__int64 do_input_boost_rem()
{
  char v0; // w12
  unsigned __int64 v1; // x12
  unsigned __int64 v2; // x12
  __int64 v3; // x13
  bool v4; // cf
  __int64 result; // x0

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
    *(_DWORD *)((char *)&sync_info + v3 + 4) = 0;
  }
  while ( !v4 );
  result = ((__int64 (*)(void))update_policy_online)();
  if ( sched_boost_active == 1 )
  {
    result = sched_set_boost(0);
    if ( !(_DWORD)result )
      result = printk(&unk_63C45);
    sched_boost_active = 0;
  }
  return result;
}
