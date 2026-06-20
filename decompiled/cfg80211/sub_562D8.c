void sub_562D8()
{
  __int64 v0; // x19
  __int64 v1; // x20
  __int64 v2; // x21
  __int64 v3; // x29
  unsigned __int64 StatusReg; // x23
  __int64 mpath; // x0
  __int64 v6; // x1
  __int64 v7; // x2
  __int64 v8; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    mpath = _traceiter_rdev_get_mpath(0, v1 + 992, v0, v2 + 4, v3 - 16);
    v8 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v8;
    if ( !v8 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(mpath, v6, v7);
  }
  JUMPOUT(0x561DC);
}
