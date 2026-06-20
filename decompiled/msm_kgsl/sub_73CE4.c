void sub_73CE4()
{
  __int64 v0; // x19
  __int64 v1; // x30
  unsigned __int64 StatusReg; // x20
  __int64 active; // x0
  __int64 v4; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    active = _traceiter_kgsl_active_count(0, v0, v1);
    v4 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v4;
    if ( !v4 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(active);
  }
  JUMPOUT(0x73C70);
}
