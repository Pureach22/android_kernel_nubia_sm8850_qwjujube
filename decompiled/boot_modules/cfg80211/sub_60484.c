void __fastcall sub_60484(__int64 a1, __int64 a2, unsigned int a3, int a4)
{
  __int64 v4; // x19
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v7; // x2
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v5 + 24) = a2;
    v7 = *(_QWORD *)(v5 + 24);
    *(_DWORD *)(v5 - 4) = a4;
    v8 = _traceiter_rdev_crit_proto_start(0, v4 + 992, v7, a3, *(unsigned int *)(v5 - 4));
    v9 = *(_QWORD *)(v5 + 24);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v8, v9, a3);
  }
  JUMPOUT(0x60414);
}
