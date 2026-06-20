__int64 __fastcall ieee80211_tx_status_skb(__int64 a1, __int64 a2)
{
  __int64 v3; // x20
  unsigned __int64 v4; // x0
  __int64 v5; // x0
  __int64 result; // x0
  _QWORD v7[8]; // [xsp+0h] [xbp-40h] BYREF

  v7[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 224);
  v7[0] = 0;
  v7[1] = a2 + 40;
  v7[2] = a2;
  memset(&v7[3], 0, 32);
  _rcu_read_lock(a1, a2);
  v4 = sta_info_get_by_addrs(a1, (const void *)(v3 + 4), v3 + 10);
  if ( v4 )
    v7[0] = v4 + 2688;
  v5 = ieee80211_tx_status_ext(a1, v7);
  result = _rcu_read_unlock(v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
