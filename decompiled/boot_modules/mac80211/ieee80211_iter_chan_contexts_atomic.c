__int64 __fastcall ieee80211_iter_chan_contexts_atomic(
        __int64 a1,
        __int64 (__fastcall *a2)(__int64, __int64 *, __int64),
        __int64 a3)
{
  __int64 lock; // x0
  __int64 *i; // x22

  lock = _rcu_read_lock(a1, a2);
  for ( i = *(__int64 **)(a1 + 4984); i != (__int64 *)(a1 + 4984); i = (__int64 *)*i )
  {
    if ( *((_BYTE *)i + 84) == 1 )
    {
      if ( *((_DWORD *)a2 - 1) != -187704826 )
        __break(0x8234u);
      lock = a2(a1, i + 19, a3);
    }
  }
  return _rcu_read_unlock(lock);
}
