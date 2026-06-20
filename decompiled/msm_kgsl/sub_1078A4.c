void __usercall sub_1078A4(__int64 a1@<X2>, __int64 a2@<X3>, __int64 a3@<X4>, unsigned int a4@<W8>)
{
  __int64 v4; // x9
  __int64 v5; // x20
  unsigned __int64 StatusReg; // x25
  __int64 v7; // x0
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v7 = _traceiter_kgsl_pwrlevel(0, v5, a1, a2, a3, a4, v4);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v7);
  }
  JUMPOUT(0x1074F0);
}
