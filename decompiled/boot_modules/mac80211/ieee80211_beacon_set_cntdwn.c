__int64 __fastcall ieee80211_beacon_set_cntdwn(_DWORD *a1, __int64 a2)
{
  unsigned __int8 v2; // w19
  __int64 lock; // x0
  __int64 v5; // x8

  v2 = a2;
  lock = _rcu_read_lock(a1, a2);
  if ( *a1 == 3 )
  {
    v5 = *((_QWORD *)a1 - 71);
    if ( !v5 )
      return _rcu_read_unlock(lock);
  }
  else
  {
    if ( *a1 != 1 )
      return _rcu_read_unlock(lock);
    v5 = *((_QWORD *)a1 - 285);
    if ( !v5 )
      return _rcu_read_unlock(lock);
  }
  if ( *(unsigned __int8 *)(v5 + 36) > (unsigned int)v2 )
    *(_BYTE *)(v5 + 36) = v2;
  return _rcu_read_unlock(lock);
}
