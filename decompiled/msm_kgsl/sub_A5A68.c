void sub_A5A68()
{
  unsigned int v0; // w20
  unsigned int v1; // w21
  unsigned __int64 StatusReg; // x25
  __int64 v3; // x0
  __int64 v4; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v3 = _traceiter_kgsl_bcl_clock_throttling(0, v0, v1);
    v4 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v4;
    if ( !v4 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v3);
  }
  JUMPOUT(0xA5998);
}
