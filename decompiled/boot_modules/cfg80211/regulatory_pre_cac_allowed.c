__int64 __fastcall regulatory_pre_cac_allowed(__int64 a1)
{
  __int64 lock; // x0
  __int64 v3; // x9
  int v4; // w8
  int v5; // w9
  bool v6; // zf
  unsigned int v7; // w19

  lock = _rcu_read_lock(a1);
  v3 = *(_QWORD *)(a1 + 384);
  v4 = *(_DWORD *)(cfg80211_regdomain + 24);
  if ( v3 )
  {
    v5 = *(_DWORD *)(v3 + 24);
    v6 = v4 == 2 && v5 == 2;
  }
  else
  {
    v6 = v4 == 2;
  }
  v7 = v6;
  _rcu_read_unlock(lock);
  return v7;
}
