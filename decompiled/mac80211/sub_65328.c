void __fastcall sub_65328(
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
        __int64 a12)
{
  __int64 v12; // x19
  __int64 v13; // x23
  unsigned __int64 StatusReg; // x20
  __int64 v15; // x0
  __int64 v16; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v15 = _traceiter_drv_sta_set_4addr(0, a12, v12, v13 + 2688, 1);
    v16 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v16;
    if ( !v16 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v15);
  }
  JUMPOUT(0x64E3C);
}
