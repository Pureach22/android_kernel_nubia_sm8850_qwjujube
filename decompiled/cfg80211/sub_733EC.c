void __fastcall sub_733EC(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22
  unsigned __int64 StatusReg; // x20
  __int64 started; // x0
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    started = _traceiter_rdev_start_pmsr(0, v3 + 992, a2);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || (v9 = a3, v8 = a2, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(started, v8, v9);
  }
  JUMPOUT(0x73234);
}
