void sub_12024()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x0
  __int64 v2; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v1 = _traceiter_rmnet_shs_wq_low(0, 11, 67, 156, 3567, 3567, 3567, 0);
    v2 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v2;
    if ( !v2 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v1);
    JUMPOUT(0x11AC8);
  }
  JUMPOUT(0x11A6C);
}
