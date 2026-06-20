void __fastcall sub_463C4(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x29
  unsigned __int64 StatusReg; // x22
  __int64 v8; // x0
  __int64 v9; // x2
  __int64 v10; // x1
  __int64 v11; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v6 + 24) = a2;
    v8 = _traceiter_rdev_assoc_ml_reconf(0, v5 + 992, *(_QWORD *)(v6 + 24), v4, a4);
    v10 = *(_QWORD *)(v6 + 24);
    v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v11;
    if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v8, v10, v9);
  }
  JUMPOUT(0x462D8);
}
