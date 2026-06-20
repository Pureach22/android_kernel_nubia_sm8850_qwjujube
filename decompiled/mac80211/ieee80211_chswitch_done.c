__int64 __fastcall ieee80211_chswitch_done(__int64 lock, __int64 a2, unsigned int a3)
{
  char v4; // w21
  __int64 v5; // x19
  __int64 v6; // x3
  __int64 v7; // x8
  __int64 v8; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v11; // x8

  v4 = a2;
  v5 = lock;
  while ( 1 )
  {
    lock = _rcu_read_lock(lock, a2);
    if ( (v4 & 1) == 0 )
    {
      printk(&unk_BCF7C, v5 - 3080, a3, v6);
      lock = wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(v5 - 3104) + 72LL), v5 - 2288);
      return _rcu_read_unlock(lock);
    }
    if ( a3 < 0x10 )
      break;
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask
                     + (((unsigned __int64)*(unsigned int *)(StatusReg + 40) >> 3) & 0x1FFFFFF8)) >> *(_DWORD *)(StatusReg + 40))
        & 1) != 0 )
    {
      ++*(_DWORD *)(StatusReg + 16);
      lock = _traceiter_api_chswitch_done(0, v5 + v7, v4 & 1, a3);
      v11 = *(_QWORD *)(StatusReg + 16) - 1LL;
      *(_DWORD *)(StatusReg + 16) = v11;
      if ( !v11 || !*(_QWORD *)(StatusReg + 16) )
        lock = preempt_schedule_notrace(lock);
    }
  }
  v8 = *(_QWORD *)(v5 + 8LL * a3 - 152);
  if ( v8 )
    lock = wiphy_delayed_work_queue(*(_QWORD *)(*(_QWORD *)(v5 - 3104) + 72LL), v8 + 568, 0);
  else
    __break(0x800u);
  return _rcu_read_unlock(lock);
}
