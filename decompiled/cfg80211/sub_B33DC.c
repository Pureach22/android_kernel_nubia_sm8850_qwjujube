void __fastcall sub_B33DC(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v3; // x21
  __int64 v4; // x22
  unsigned __int64 StatusReg; // x24
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  __int64 v9; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v6 = _traceiter_rdev_return_int(0, a1 + 992, a3);
    v9 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v9;
    if ( !v9 || (v7 = v4, v6 = v3, !*(_QWORD *)(StatusReg + 16)) )
      preempt_schedule_notrace(v6, v7, v8);
  }
  JUMPOUT(0xB304C);
}
