void __fastcall sub_39B34(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8,
        __int64 a9)
{
  __int64 v9; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v11; // x0
  __int64 v12; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v11 = _traceiter_drv_nan_change_conf(0, v9, a3, (char *)&a9 + 4, a4);
    v12 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v12;
    if ( !v12 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v11);
  }
  JUMPOUT(0x39A74);
}
