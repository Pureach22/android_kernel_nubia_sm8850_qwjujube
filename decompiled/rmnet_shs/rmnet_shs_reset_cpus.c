__int64 rmnet_shs_reset_cpus()
{
  char v0; // w15
  unsigned __int64 v1; // x15
  unsigned __int64 v2; // x15
  bool v3; // cf
  __int64 result; // x0

  v0 = 0;
  _ReadStatusReg(SP_EL0);
  do
  {
    v1 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v1 )
      break;
    v2 = __clz(__rbit64(v1));
    *(_QWORD *)(_per_cpu_offset[v2] + shs_cpu_boosts_0) = 0x7FFFFFFF00000000LL;
    v3 = v2 >= 0x1F;
    v0 = v2 + 1;
  }
  while ( !v3 );
  if ( (boost_cpu & 1) == 0 )
  {
    if ( shs_boost_wq )
      return queue_work_on(2, shs_boost_wq, &boost_cpu);
  }
  return result;
}
