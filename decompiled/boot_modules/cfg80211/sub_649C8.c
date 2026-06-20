void __fastcall sub_649C8(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        char a11)
{
  __int64 v11; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v13; // x0
  __int64 v14; // x2
  __int64 v15; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v13 = _traceiter_rdev_set_fils_aad(0, v11 + 992, a2, &a11);
    v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v15;
    if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v13, a2, v14);
  }
  JUMPOUT(0x64958);
}
