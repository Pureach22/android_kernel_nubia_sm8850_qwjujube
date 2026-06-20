__int64 __fastcall ieee80211_recalc_p2p_go_ps_allowed(__int64 a1, __int64 a2)
{
  __int64 v2; // x20
  __int64 v3; // x22
  int v5; // w21
  __int64 lock; // x0
  __int64 *i; // x8
  __int64 result; // x0

  v2 = a1 + 4096;
  v3 = *(_QWORD *)(a1 + 1616);
  v5 = *(unsigned __int8 *)(a1 + 5848);
  lock = _rcu_read_lock(a1, a2);
  for ( i = *(__int64 **)(v3 + 1616); i != (__int64 *)(v3 + 1616); i = (__int64 *)*i )
  {
    if ( i[10] == a1 && (i[27] & 2) != 0 && *((_BYTE *)i + 2728) != 1 )
    {
      v5 = 0;
      break;
    }
  }
  result = _rcu_read_unlock(lock);
  if ( *(unsigned __int8 *)(v2 + 1002) != v5 )
  {
    *(_BYTE *)(v2 + 1002) = v5;
    return ieee80211_link_info_change_notify(a1, a1 + 3616, 0x80000);
  }
  return result;
}
