__int64 __fastcall ieee80211_recalc_min_chandef(__int64 result, __int64 a2)
{
  int v2; // w19
  __int64 v3; // x20
  __int64 v4; // x22
  __int64 v5; // x21
  __int64 v6; // x23
  __int64 lock; // x0
  __int64 v8; // x8
  __int64 v9; // x24

  v2 = a2;
  v3 = *(_QWORD *)(result + 1616);
  v4 = 8LL * (unsigned int)a2;
  v5 = 0;
  v6 = result + 5680;
  while ( 1 )
  {
    if ( (v2 & 0x80000000) == 0 && v4 != v5 )
      goto LABEL_3;
    lock = _rcu_read_lock(result, a2);
    v8 = *(_QWORD *)(v6 + v5);
    if ( v8 )
      break;
    result = _rcu_read_unlock(lock);
LABEL_3:
    v5 += 8;
    if ( v5 == 120 )
      return result;
  }
  v9 = *(_QWORD *)(v8 + 832);
  result = _rcu_read_unlock(lock);
  if ( v9 )
  {
    result = ieee80211_recalc_chanctx_min_def(v3, v9 - 152);
    goto LABEL_3;
  }
  return result;
}
