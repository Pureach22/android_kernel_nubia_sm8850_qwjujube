void __fastcall sub_6909C(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  unsigned __int64 StatusReg; // x20
  __int64 started; // x0
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    started = _traceiter_rdev_start_ap(0, v3 + 992, a2, a3);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(started, a2, a3);
  }
  JUMPOUT(0x6905C);
}
