void __fastcall sub_10B92C(__int64 a1)
{
  __int64 v1; // x29
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x0
  __int64 v4; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_QWORD *)(v1 + 24) = a1;
    _traceiter_kgsl_irq(0, *(_QWORD *)(v1 + 24), 0);
    v3 = *(_QWORD *)(v1 + 24);
    v4 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v4;
    if ( !v4 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v3);
  }
  JUMPOUT(0x10B810);
}
