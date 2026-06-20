__int64 __fastcall cfg80211_cqm_rssi_notify(__int64 result, unsigned int a2, int a3)
{
  __int64 *v3; // x19
  __int64 lock; // x0
  __int64 v7; // x8

  v3 = *(__int64 **)(result + 992);
  if ( a2 >= 2 )
  {
    __break(0x800u);
  }
  else
  {
    lock = _rcu_read_lock(result);
    v7 = v3[26];
    if ( v7 )
    {
      *(_DWORD *)(v7 + 20) = a3;
      *(_DWORD *)(v7 + 24) = a2;
      lock = wiphy_work_queue(*v3, v3 + 23);
    }
    return _rcu_read_unlock(lock);
  }
  return result;
}
