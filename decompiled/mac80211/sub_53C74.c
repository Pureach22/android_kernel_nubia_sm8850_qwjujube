void __fastcall sub_53C74(
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
  int v11; // w21
  unsigned int v12; // w22
  unsigned __int64 StatusReg; // x23
  __int64 v14; // x0
  __int64 v15; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v14 = _traceiter_drv_configure_filter(0, v9, v11 ^ v12, (char *)&a9 + 4, v10);
    v15 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v15;
    if ( !v15 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v14);
  }
  JUMPOUT(0x53B30);
}
