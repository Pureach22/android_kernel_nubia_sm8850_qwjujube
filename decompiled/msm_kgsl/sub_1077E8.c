void __fastcall sub_1077E8(
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
        __int64 a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        char a16)
{
  __int64 v16; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v18; // x0
  __int64 v19; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v18 = _traceiter_kgsl_pwrstats(0, v16, a3, &a16);
    v19 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v19;
    if ( !v19 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v18);
  }
  JUMPOUT(0x107600);
}
