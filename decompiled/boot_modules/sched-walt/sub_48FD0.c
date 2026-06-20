void __fastcall sub_48FD0(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        unsigned int a8)
{
  __int64 v8; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v10; // x0
  __int64 v11; // x11

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v8 + 24) = a1;
    _traceiter_walt_account_yields(0, *(_QWORD *)(v8 + 24), a3, a4, a5, a6, a7, a8);
    v10 = *(_QWORD *)(v8 + 24);
    v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v11;
    if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v10);
  }
  JUMPOUT(0x48F84);
}
