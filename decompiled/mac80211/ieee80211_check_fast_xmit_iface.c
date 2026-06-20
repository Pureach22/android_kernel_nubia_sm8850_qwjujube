__int64 __fastcall ieee80211_check_fast_xmit_iface(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 lock; // x0
  _QWORD *v5; // x20
  _QWORD *v6; // x21
  __int64 v7; // x8
  __int64 v8; // x8

  v2 = *(_QWORD *)(a1 + 1616);
  lock = _rcu_read_lock(a1, a2);
  v5 = *(_QWORD **)(v2 + 1616);
  v6 = (_QWORD *)(v2 + 1616);
  while ( v5 != v6 )
  {
    v7 = v5[10];
    if ( v7 == a1 || (v8 = *(_QWORD *)(v7 + 2032)) != 0 && v8 == *(_QWORD *)(a1 + 2032) )
      lock = ieee80211_check_fast_xmit((__int64)v5);
    v5 = (_QWORD *)*v5;
  }
  return _rcu_read_unlock(lock);
}
