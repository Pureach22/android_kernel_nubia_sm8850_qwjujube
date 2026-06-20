void __fastcall sub_4D8F4(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x21
  __int64 lowest_rq; // x0
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    lowest_rq = _traceiter_sched_rt_find_lowest_rq(0, v5, a3, a4, v4);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(lowest_rq);
  }
  JUMPOUT(0x4D8C0);
}
