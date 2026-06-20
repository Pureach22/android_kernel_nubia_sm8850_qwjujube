void __fastcall sub_5BCD4(unsigned int a1)
{
  __int64 v1; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x0
  __int64 v4; // x1
  __int64 v5; // x2
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v3 = _traceiter_rdev_return_int(0, v1 + 992, a1);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v3, v4, v5);
  }
  JUMPOUT(0x5BC38);
}
