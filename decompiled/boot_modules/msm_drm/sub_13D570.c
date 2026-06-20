void __fastcall sub_13D570(unsigned int a1, unsigned int a2, unsigned int a3, unsigned int a4)
{
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x0
  __int64 v6; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v5 = _traceiter_sde_perf_set_ot(0, a1, a2, a3, a4);
    v6 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v6;
    if ( !v6 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v5);
  }
  JUMPOUT(0x13D560);
}
