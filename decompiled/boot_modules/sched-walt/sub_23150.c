void __usercall sub_23150(unsigned __int64 a1@<X0>, unsigned __int64 a2@<X8>)
{
  unsigned __int64 v2; // x9
  unsigned __int64 v3; // x10
  __int64 v4; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v6; // x0
  __int64 v7; // x11

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v4 + 24) = a1;
    *(_QWORD *)(v4 - 8) = v2;
    _traceiter_sched_boost_bus_dcvs(0, v3 >= a1, v2 >= a1, a2 >= a1);
    v6 = *(_QWORD *)(v4 + 24);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v6);
  }
  JUMPOUT(0x23108);
}
