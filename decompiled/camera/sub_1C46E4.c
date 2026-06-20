void sub_1C46E4()
{
  __int64 v0; // x22
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x0
  __int64 v3; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v2 = _traceiter_cam_log_event(0, (__int64)"UnexpectedRUP", (__int64)"RUP_IRQ", v0, 40);
    v3 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v3;
    if ( !v3 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v2);
  }
  JUMPOUT(0x1C4620);
}
