void __fastcall sub_534C0(
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
  unsigned __int64 StatusReg; // x19
  __int64 v12; // x0
  __int64 v13; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v12 = _traceiter_sched_overutilized(0, BYTE4(a10) & 1, (__int64)&a11);
    v13 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v13;
    if ( !v13 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v12);
  }
  JUMPOUT(0x53464);
}
