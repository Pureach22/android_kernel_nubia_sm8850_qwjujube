__int64 __fastcall wiphy_work_flush(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // x19
  __int64 v3; // x20
  __int64 v4; // x1
  _QWORD *v5; // x22
  __int64 result; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v8; // x0
  __int64 v9; // x1
  __int64 v10; // x2
  __int64 v11; // x8

  if ( a1 )
  {
    v3 = a1;
    v2 = a2;
  }
  else
  {
    __break(0x800u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      v8 = _traceiter_wiphy_work_flush(0, v3, v2);
      v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v11;
      if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
        preempt_schedule_notrace(v8, v9, v10);
    }
  }
  v4 = raw_spin_lock_irqsave(v3 - 24);
  if ( v2 )
  {
    v5 = (_QWORD *)*v2;
    result = raw_spin_unlock_irqrestore(v3 - 24, v4);
    if ( v5 == v2 )
      return result;
  }
  else
  {
    raw_spin_unlock_irqrestore(v3 - 24, v4);
  }
  return cfg80211_process_wiphy_works(v3 - 992, v2);
}
