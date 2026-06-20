void __fastcall sub_4314C(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, unsigned int a5)
{
  __int64 v5; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v7; // x0
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v5 + 24) = a1;
    _traceiter_drv_sta_state(0, *(_QWORD *)(v5 + 24), a2, a3 + 2688, a4, a5);
    v7 = *(_QWORD *)(v5 + 24);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7);
  }
  JUMPOUT(0x42D90);
}
