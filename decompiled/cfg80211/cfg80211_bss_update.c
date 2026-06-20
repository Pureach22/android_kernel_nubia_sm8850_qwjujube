__int64 __fastcall cfg80211_bss_update(__int64 a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 v8; // x19

  raw_spin_lock_bh(a1 + 184);
  v8 = _cfg80211_bss_update(a1, a2, a3, a4);
  raw_spin_unlock_bh(a1 + 184);
  return v8;
}
