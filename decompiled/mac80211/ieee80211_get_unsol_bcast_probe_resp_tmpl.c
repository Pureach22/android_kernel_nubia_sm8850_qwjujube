_QWORD *__fastcall ieee80211_get_unsol_bcast_probe_resp_tmpl(__int64 a1, _DWORD *a2)
{
  _QWORD *lock; // x0
  __int64 v4; // x21
  _DWORD *v5; // x20
  _QWORD *v6; // x19
  __int64 v7; // x8
  __int64 v8; // x9
  size_t v9; // x20
  void *v10; // x0

  if ( *a2 != 3 )
    return nullptr;
  lock = (_QWORD *)_rcu_read_lock(a1, a2);
  v4 = *((_QWORD *)a2 - 68);
  if ( v4 )
  {
    v5 = a2 - 776;
    lock = (_QWORD *)_netdev_alloc_skb(
                       0,
                       (unsigned int)(*(_DWORD *)(v4 + 16) + *(_DWORD *)(*((_QWORD *)a2 - 388) + 104LL)),
                       2080);
    v6 = lock;
    if ( lock )
    {
      v7 = *(int *)(*(_QWORD *)v5 + 104LL);
      v8 = lock[28] + v7;
      LODWORD(v7) = *((_DWORD *)lock + 52) + v7;
      lock[28] = v8;
      *((_DWORD *)lock + 52) = v7;
      v9 = *(unsigned int *)(v4 + 16);
      v10 = (void *)skb_put(lock, (unsigned int)v9);
      lock = memcpy(v10, (const void *)(v4 + 20), v9);
    }
  }
  else
  {
    v6 = nullptr;
  }
  _rcu_read_unlock(lock);
  return v6;
}
