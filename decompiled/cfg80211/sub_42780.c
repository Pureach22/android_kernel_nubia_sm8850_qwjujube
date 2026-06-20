void __fastcall sub_42780(unsigned int a1)
{
  __int64 v1; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x1
  __int64 v5; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v3 = v1 + 992;
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_rdev_return_int(0, v3, a1);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || (v5 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v5, v6, v7);
  }
  JUMPOUT(0x426EC);
}
