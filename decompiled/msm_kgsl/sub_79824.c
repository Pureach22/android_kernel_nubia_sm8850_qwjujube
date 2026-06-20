void __fastcall sub_79824(int a1)
{
  __int64 v1; // x19
  unsigned int v2; // w20
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x22
  __int64 v5; // x0
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    *(_DWORD *)(v3 - 4) = a1;
    _traceiter_kgsl_a5xx_irq_status(0, v1, v2);
    v5 = *(unsigned int *)(v3 - 4);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v5);
  }
  JUMPOUT(0x797F0);
}
