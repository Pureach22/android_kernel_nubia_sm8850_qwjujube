void __fastcall sub_396D4(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x20
  __int64 v4; // x21
  unsigned __int64 StatusReg; // x22
  __int64 v6; // x0
  __int64 v7; // x9

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v6 = _traceiter_drv_add_nan_func(0, v4, a3, v3);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v6);
  }
  JUMPOUT(0x39634);
}
