__int64 __fastcall reg_get_dfs_region(__int64 a1)
{
  __int64 lock; // x0
  unsigned int v3; // w19
  __int64 v4; // x8

  lock = _rcu_read_lock(a1);
  v3 = *(_DWORD *)(cfg80211_regdomain + 24);
  if ( a1 )
  {
    v4 = *(_QWORD *)(a1 + 384);
    if ( v4 )
    {
      if ( (*(_BYTE *)(a1 + 104) & 0x80) != 0 )
        v3 = *(_DWORD *)(v4 + 24);
    }
  }
  _rcu_read_unlock(lock);
  return v3;
}
