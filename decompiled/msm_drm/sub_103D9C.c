void sub_103D9C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x0
  __int64 v2; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v1 = _traceiter_sde_cmd_release_bw(0);
    v2 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v2;
    if ( !v2 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v1);
  }
  JUMPOUT(0x103CAC);
}
