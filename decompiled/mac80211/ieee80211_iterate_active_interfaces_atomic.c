__int64 __fastcall ieee80211_iterate_active_interfaces_atomic(
        __int64 a1,
        __int64 a2,
        __int64 (__fastcall *a3)(__int64, char *, __int64 *),
        __int64 a4)
{
  char v6; // w21
  __int64 v8; // x0

  v6 = a2;
  _rcu_read_lock(a1, a2);
  v8 = _iterate_interfaces(a1, v6 | 2u, a3, a4);
  return _rcu_read_unlock(v8);
}
