void __fastcall sub_6E780(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v6; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v6 - 8) = a2;
    v8 = _traceiter_rdev_tdls_channel_switch(0, v5 + 992, *(_QWORD *)(v6 - 8), a3, a4, a5);
    v9 = *(_QWORD *)(v6 - 8);
    v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v10;
    if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v8, v9, a3);
  }
  JUMPOUT(0x6E740);
}
