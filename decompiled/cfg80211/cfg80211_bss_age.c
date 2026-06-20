__int64 __fastcall cfg80211_bss_age(__int64 a1, int a2)
{
  __int64 v3; // x20
  _QWORD *i; // x9

  v3 = _msecs_to_jiffies((unsigned int)(1000 * a2));
  raw_spin_lock_bh(a1 + 184);
  for ( i = *(_QWORD **)(a1 + 192); i != (_QWORD *)(a1 + 192); i = (_QWORD *)*i )
    i[8] -= v3;
  return raw_spin_unlock_bh(a1 + 184);
}
