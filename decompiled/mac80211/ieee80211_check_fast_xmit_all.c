__int64 __fastcall ieee80211_check_fast_xmit_all(__int64 a1, __int64 a2)
{
  __int64 lock; // x0
  _QWORD *v4; // x19
  _QWORD *i; // x20

  lock = _rcu_read_lock(a1, a2);
  v4 = *(_QWORD **)(a1 + 1616);
  for ( i = (_QWORD *)(a1 + 1616); v4 != i; v4 = (_QWORD *)*v4 )
    lock = ieee80211_check_fast_xmit((__int64)v4);
  return _rcu_read_unlock(lock);
}
