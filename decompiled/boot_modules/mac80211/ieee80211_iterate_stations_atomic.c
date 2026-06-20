__int64 __fastcall ieee80211_iterate_stations_atomic(
        __int64 a1,
        __int64 (__fastcall *a2)(__int64, __int64 *),
        __int64 a3)
{
  __int64 lock; // x0
  __int64 *v7; // x22
  __int64 *v8; // x21

  lock = _rcu_read_lock(a1, a2);
  v7 = *(__int64 **)(a1 + 1616);
  v8 = (__int64 *)(a1 + 1616);
  while ( v7 != v8 )
  {
    if ( *((_BYTE *)v7 + 204) == 1 )
    {
      if ( *((_DWORD *)a2 - 1) != -372844944 )
        __break(0x8234u);
      lock = a2(a3, v7 + 336);
    }
    v7 = (__int64 *)*v7;
  }
  return _rcu_read_unlock(lock);
}
