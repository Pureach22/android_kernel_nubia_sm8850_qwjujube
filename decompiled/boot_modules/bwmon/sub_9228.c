void sub_9228()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_bw_hwmon_meas(0);
    v1 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v1;
    if ( !v1 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace();
    JUMPOUT(0x9210);
  }
  JUMPOUT(0x9120);
}
