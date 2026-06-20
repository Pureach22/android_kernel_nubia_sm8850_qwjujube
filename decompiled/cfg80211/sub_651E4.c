void __fastcall sub_651E4(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        char a10)
{
  __int64 v10; // x19
  __int64 v11; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v13; // x0
  __int64 v14; // x1
  __int64 v15; // x2
  __int64 v16; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v13 = _traceiter_rdev_set_ttlm(0, v11 + 992, v10, &a10);
    v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v16;
    if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v13, v14, v15);
  }
  JUMPOUT(0x65164);
}
