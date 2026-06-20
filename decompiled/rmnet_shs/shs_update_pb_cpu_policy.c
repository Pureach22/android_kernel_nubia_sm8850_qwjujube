__int64 shs_update_pb_cpu_policy()
{
  __int64 lock; // x0
  char v1; // w8
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x27

  lock = cpus_read_lock();
  v1 = 0;
  _ReadStatusReg(SP_EL0);
  do
  {
    v2 = (unsigned int)(-1LL << v1) & _cpu_online_mask;
    if ( !(_DWORD)v2 )
      break;
    v3 = __clz(__rbit64(v2));
    lock = freq_qos_update_request(
             (char *)&pb_boost_req + _per_cpu_offset[v3],
             *(unsigned int *)(_per_cpu_offset[v3] + shs_pb_cpu_boosts_0));
    v1 = v3 + 1;
  }
  while ( v3 < 0x1F );
  return cpus_read_unlock(lock);
}
