void sub_AB510()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x0
  __int64 v2; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v1 = _traceiter_kgsl_gmu_oob_clear(0, 0x80000000LL);
    v2 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v2;
    if ( !v2 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v1);
  }
  JUMPOUT(0xAB450);
}
