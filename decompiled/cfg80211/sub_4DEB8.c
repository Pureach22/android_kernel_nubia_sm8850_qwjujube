void sub_4DEB8()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 v3; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                   + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
      & 1) != 0 )
  {
    ++*(_DWORD *)(StatusReg + 16);
    _traceiter_cfg80211_return_bool(0, 0);
    v3 = *(_QWORD *)(StatusReg + 16) - 1LL;
    *(_DWORD *)(StatusReg + 16) = v3;
    if ( !v3 || !*(_QWORD *)(StatusReg + 16) )
      preempt_schedule_notrace(0, v1, v2);
    JUMPOUT(0x4DE0C);
  }
  JUMPOUT(0x4DE08);
}
