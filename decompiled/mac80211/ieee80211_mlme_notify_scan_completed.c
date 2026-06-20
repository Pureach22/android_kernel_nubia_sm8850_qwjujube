__int64 __fastcall ieee80211_mlme_notify_scan_completed(__int64 a1, __int64 a2)
{
  __int64 lock; // x0
  __int64 *v4; // x20
  __int64 *v5; // x19
  __int64 v6; // x0
  __int64 v7; // x8

  lock = _rcu_read_lock(a1, a2);
  v4 = *(__int64 **)(a1 + 4616);
  v5 = (__int64 *)(a1 + 4616);
  while ( v4 != v5 )
  {
    if ( (v4[204] & 1) != 0 && *((_DWORD *)v4 + 1180) == 2 )
    {
      v6 = v4[202];
      *((_DWORD *)v4 + 625) &= ~2u;
      lock = ieee80211_run_deferred_scan(v6);
      v7 = v4[202];
      if ( (*(_QWORD *)(v7 + 96) & 0x20000) == 0 )
        lock = wiphy_work_queue(*(_QWORD *)(v7 + 72), v4 + 298);
    }
    v4 = (__int64 *)*v4;
  }
  return _rcu_read_unlock(lock);
}
