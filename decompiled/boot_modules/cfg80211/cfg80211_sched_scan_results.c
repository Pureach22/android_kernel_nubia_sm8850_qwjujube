__int64 __fastcall cfg80211_sched_scan_results(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 lock; // x0
  _QWORD *v5; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v8; // x1
  __int64 v9; // x2
  __int64 v10; // x8

  if ( a1 )
  {
    v2 = a1;
    v3 = a2;
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
      a1 = _traceiter_cfg80211_sched_scan_results(0, v2, v3);
      v10 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v10;
      if ( !v10 || !*(_QWORD *)(StatusReg + 16) )
        a1 = preempt_schedule_notrace(a1, v8, v9);
    }
  }
  lock = _rcu_read_lock(a1);
  v5 = (_QWORD *)(v2 - 744);
  while ( 1 )
  {
    v5 = (_QWORD *)*v5;
    if ( v5 == (_QWORD *)(v2 - 744) )
      break;
    if ( *(v5 - 21) == v3 )
    {
      if ( v5 != &_ksymtab_cfg80211_cac_event )
      {
        *((_BYTE *)v5 - 32) = 1;
        lock = queue_work_on(32, cfg80211_wq, v2 - 272);
      }
      return _rcu_read_unlock(lock);
    }
  }
  return _rcu_read_unlock(lock);
}
