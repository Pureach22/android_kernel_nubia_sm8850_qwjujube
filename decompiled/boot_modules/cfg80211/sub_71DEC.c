void __fastcall sub_71DEC(unsigned int a1)
{
  __int64 v1; // x19
  __int64 v2; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v4; // x1
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    v4 = v2 + 992;
    ++*(_DWORD *)(StatusReg + 16);
    v6 = _traceiter_rdev_return_chandef(0, v4, a1, v1);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || (v6 = a1, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v6, v7, v8);
  }
  JUMPOUT(0x71D58);
}
