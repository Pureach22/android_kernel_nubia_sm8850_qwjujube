void __fastcall sub_4152C(unsigned int a1)
{
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x22
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v4 = _traceiter_rdev_return_int(0, v1, a1);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || (v4 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v4, v5, v6);
  }
  JUMPOUT(0x41320);
}
