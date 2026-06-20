void sub_46118()
{
  __int64 v0; // x23
  unsigned __int64 StatusReg; // x25
  __int64 et_stats; // x0
  __int64 v3; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    et_stats = _traceiter_drv_get_et_stats(0, v0);
    v3 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v3;
    if ( !v3 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(et_stats);
  }
  JUMPOUT(0x46094);
}
