void sub_6F3D0()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x22
  __int64 antenna; // x0
  __int64 v3; // x1
  __int64 v4; // x2
  __int64 v5; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    antenna = _traceiter_rdev_get_antenna(0, v0 + 992);
    v5 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v5;
    if ( !v5 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(antenna, v3, v4);
  }
  JUMPOUT(0x6F32C);
}
