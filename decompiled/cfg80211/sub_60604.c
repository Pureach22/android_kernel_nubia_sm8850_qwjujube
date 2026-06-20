void __fastcall sub_60604(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v4; // x0
  __int64 v5; // x2
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v4 = _traceiter_rdev_crit_proto_stop(0, v2 + 992, a2);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v4, a2, v5);
  }
  JUMPOUT(0x605B8);
}
