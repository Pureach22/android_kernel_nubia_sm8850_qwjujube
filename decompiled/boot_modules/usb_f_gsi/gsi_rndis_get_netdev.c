__int64 gsi_rndis_get_netdev()
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  __int64 v2; // x9
  unsigned int *v3; // x9
  unsigned int v4; // w12
  __int64 v5; // x9
  __int64 v6; // x19

  result = dev_get_by_name(&init_net, "rndis0");
  if ( !result )
    return -22;
  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(StatusReg + 16);
  v2 = *(_QWORD *)(result + 1320);
  v3 = (unsigned int *)(_ReadStatusReg(TPIDR_EL1) + v2);
  do
    v4 = __ldxr(v3);
  while ( __stxr(v4 - 1, v3) );
  v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
  *(_DWORD *)(StatusReg + 16) = v5;
  if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
  {
    v6 = result;
    preempt_schedule_notrace();
    return v6;
  }
  return result;
}
