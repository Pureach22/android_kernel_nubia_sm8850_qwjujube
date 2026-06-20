void __fastcall sub_638F8(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v9; // x19
  __int64 v10; // x20
  unsigned __int64 StatusReg; // x21
  __int64 updated; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    updated = _traceiter_rdev_update_owe_info(0, v10 + 992, v9, &a9);
    v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v15;
    if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(updated, v13, v14);
  }
  JUMPOUT(0x63878);
}
