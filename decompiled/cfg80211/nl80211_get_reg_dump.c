__int64 __fastcall nl80211_get_reg_dump(__int64 a1, __int64 a2)
{
  int v2; // w22
  __int64 lock; // x0
  _UNKNOWN **v6; // x23
  int v7; // w24
  int v8; // w25
  __int64 v9; // x8
  unsigned int v10; // w21

  v2 = *(_DWORD *)(a2 + 96);
  lock = _rcu_read_lock(a1);
  if ( cfg80211_regdomain
    && !v2
    && (lock = nl80211_send_regdom(a1, a2, *(unsigned int *)(*(_QWORD *)(a2 + 8) + 8LL), 0, cfg80211_regdomain),
        (lock & 0x80000000) != 0) )
  {
    v10 = lock;
  }
  else
  {
    v6 = (_UNKNOWN **)cfg80211_rdev_list;
    if ( cfg80211_rdev_list != (_UNKNOWN *)&cfg80211_rdev_list )
    {
      v7 = 1;
      while ( 1 )
      {
        lock = get_wiphy_regdom(v6 + 123);
        if ( lock )
        {
          v8 = v7 + 1;
          if ( v7 + 1 > v2 )
          {
            lock = nl80211_send_regdom(a1, a2, *(unsigned int *)(*(_QWORD *)(a2 + 8) + 8LL), v6 + 123, lock);
            if ( (lock & 0x80000000) != 0 )
            {
LABEL_11:
              v9 = v7;
              goto LABEL_13;
            }
          }
        }
        else
        {
          v8 = v7;
        }
        v6 = (_UNKNOWN **)*v6;
        v7 = v8;
        if ( v6 == &cfg80211_rdev_list )
          goto LABEL_11;
      }
    }
    v9 = 1;
LABEL_13:
    *(_QWORD *)(a2 + 96) = v9;
    v10 = *(_DWORD *)(a1 + 112);
  }
  _rcu_read_unlock(lock);
  return v10;
}
