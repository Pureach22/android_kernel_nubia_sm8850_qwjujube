void sub_45B84()
{
  __int64 v0; // x19
  unsigned int v1; // w20
  unsigned __int64 StatusReg; // x24
  __int64 et_strings; // x0
  __int64 v4; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    et_strings = _traceiter_drv_get_et_strings(0, v0, v1);
    v4 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v4;
    if ( !v4 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(et_strings);
  }
  JUMPOUT(0x45B30);
}
