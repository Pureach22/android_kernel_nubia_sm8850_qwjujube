_QWORD *__fastcall ieee80211_proberesp_get(__int64 a1, _DWORD *a2)
{
  _QWORD *lock; // x0
  __int64 v4; // x21
  _QWORD *v5; // x19
  size_t v6; // x20
  void *v7; // x0
  __int64 v8; // x8

  if ( *a2 != 3 )
    return nullptr;
  lock = (_QWORD *)_rcu_read_lock(a1, a2);
  v4 = *((_QWORD *)a2 - 70);
  if ( v4 )
  {
    lock = (_QWORD *)_netdev_alloc_skb(0, *(unsigned int *)(v4 + 16), 2080);
    v5 = lock;
    if ( lock )
    {
      v6 = *(unsigned int *)(v4 + 16);
      v7 = (void *)skb_put(lock, (unsigned int)v6);
      lock = memcpy(v7, (const void *)(v4 + 24), v6);
      v8 = v5[28];
      *(_DWORD *)(v8 + 4) = 0;
      *(_WORD *)(v8 + 8) = 0;
    }
  }
  else
  {
    v5 = nullptr;
  }
  _rcu_read_unlock(lock);
  return v5;
}
