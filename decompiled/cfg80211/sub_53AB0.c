void sub_53AB0()
{
  __int64 v0; // x21
  unsigned int v1; // w22
  __int64 v2; // x24
  unsigned __int64 StatusReg; // x26
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v4 = _traceiter_rdev_add_virtual_intf(0, v0 + 992, v2 + 4, v1);
    v7 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v7;
    if ( !v7 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v4, v5, v6);
  }
  JUMPOUT(0x53908);
}
