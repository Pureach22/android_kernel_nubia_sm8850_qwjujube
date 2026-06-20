bool __fastcall reg_dfs_domain_same(__int64 a1, __int64 a2)
{
  __int64 lock; // x0
  __int64 v5; // x8
  __int64 v6; // x9
  _BOOL4 v7; // w19

  lock = _rcu_read_lock(a1);
  v5 = cfg80211_regdomain;
  v6 = *(_QWORD *)(a1 + 384);
  if ( !v6 )
    v6 = cfg80211_regdomain;
  if ( *(_QWORD *)(a2 + 384) )
    v5 = *(_QWORD *)(a2 + 384);
  v7 = *(_DWORD *)(v6 + 24) == *(_DWORD *)(v5 + 24);
  _rcu_read_unlock(lock);
  return v7;
}
