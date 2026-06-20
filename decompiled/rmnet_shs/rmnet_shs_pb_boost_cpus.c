__int64 rmnet_shs_pb_boost_cpus()
{
  char v0; // w17
  bool v1; // cf
  __int64 result; // x0
  unsigned __int64 v3; // x17
  unsigned __int64 v4; // x17

  v0 = 0;
  _ReadStatusReg(SP_EL0);
  do
  {
    result = _cpu_possible_mask;
    v3 = (unsigned int)(-1LL << v0) & _cpu_possible_mask;
    if ( !(_DWORD)v3 )
      break;
    v4 = __clz(__rbit64(v3));
    result = (unsigned __int8)word_1949D >> v4;
    if ( (result & 1) == 0 )
    {
      result = _per_cpu_offset[v4] + shs_pb_cpu_boosts_0;
      *(_DWORD *)result = dword_194A0;
      *(_DWORD *)(result + 4) = 0x7FFFFFFF;
    }
    v1 = v4 >= 0x1F;
    v0 = v4 + 1;
  }
  while ( !v1 );
  if ( (pb_boost_worker & 1) == 0 )
  {
    if ( shs_boost_wq )
      return queue_work_on(2, shs_boost_wq, &pb_boost_worker);
  }
  return result;
}
