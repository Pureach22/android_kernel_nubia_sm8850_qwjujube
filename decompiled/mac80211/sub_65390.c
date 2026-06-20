void __fastcall sub_65390(
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
  unsigned __int64 StatusReg; // x19
  __int64 v13; // x0
  __int64 v14; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v13 = _traceiter_drv_return_void(0, a12);
    v14 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v14;
    if ( !v14 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v13);
  }
  JUMPOUT(0x64E7C);
}
