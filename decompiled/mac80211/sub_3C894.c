void sub_3C894()
{
  __int64 v0; // x19
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x21
  __int64 key_seq; // x0
  __int64 v4; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    key_seq = _traceiter_drv_get_key_seq(0, v0, v1 + 536);
    v4 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v4;
    if ( !v4 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(key_seq);
  }
  JUMPOUT(0x3C880);
}
