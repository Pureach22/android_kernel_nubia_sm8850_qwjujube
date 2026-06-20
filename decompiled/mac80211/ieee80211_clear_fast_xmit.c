__int64 __fastcall ieee80211_clear_fast_xmit(__int64 a1)
{
  __int64 v2; // x19
  __int64 result; // x0

  raw_spin_lock_bh(a1 + 148);
  v2 = *(_QWORD *)(a1 + 152);
  *(_QWORD *)(a1 + 152) = 0;
  result = raw_spin_unlock_bh(a1 + 148);
  if ( v2 )
    return kvfree_call_rcu(v2 + 72, v2);
  return result;
}
