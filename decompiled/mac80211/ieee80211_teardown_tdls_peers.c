__int64 __fastcall ieee80211_teardown_tdls_peers(__int64 *a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 lock; // x0
  __int64 v5; // x3
  __int64 v6; // x8
  __int64 *v7; // x22

  v2 = *a1;
  lock = _rcu_read_lock(a1, a2);
  v6 = *(_QWORD *)(v2 + 1616);
  v7 = *(__int64 **)(v6 + 1616);
  if ( v7 != (__int64 *)(v6 + 1616) )
  {
    do
    {
      if ( *((_BYTE *)v7 + 2712) == 1
        && v7[10] == v2
        && *((_BYTE *)v7 + 204) == 1
        && (v7[27] & 8) != 0
        && *((_DWORD *)a1 + 2) == *((unsigned __int8 *)v7 + 1646) )
      {
        if ( *(_DWORD *)(v2 + 4720) == 2 && (*(_BYTE *)(v2 + 4728) & 1) != 0 )
          lock = cfg80211_tdls_oper_request(*(_QWORD *)(v2 + 1608));
        else
          lock = printk(&unk_BB729, v2 + 1640, 2, v5);
      }
      v7 = (__int64 *)*v7;
    }
    while ( v7 != (__int64 *)(*(_QWORD *)(v2 + 1616) + 1616LL) );
  }
  return _rcu_read_unlock(lock);
}
