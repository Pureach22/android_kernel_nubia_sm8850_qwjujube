void sub_3DFFC()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v2 = _traceiter_rdev_return_void(0, v0 + 992);
    v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v5;
    if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v2, v3, v4);
  }
  JUMPOUT(0x3DF28);
}
