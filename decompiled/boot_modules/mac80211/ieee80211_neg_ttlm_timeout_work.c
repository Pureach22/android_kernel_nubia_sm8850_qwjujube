__int64 __fastcall ieee80211_neg_ttlm_timeout_work(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x19

  v4 = a2 - 3160;
  printk(&unk_B8F29, a2 - 1520, a3, a4);
  return _ieee80211_disconnect(v4);
}
