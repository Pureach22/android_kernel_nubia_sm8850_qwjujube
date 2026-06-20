void sub_4CCE8()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x24
  __int64 v2; // x0
  __int64 v3; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    v2 = _traceiter_drv_return_void(0, v0);
    v3 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v3;
    if ( !v3 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(v2);
  }
  JUMPOUT(0x4CA48);
}
