__int64 __fastcall sub_A8E48(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v5; // x9
  __int64 v6; // x10
  _QWORD *v7; // x13

  *v7 = v5;
  v7[1] = v6;
  return _ieee80211_tx_skb_tid_band(a1, a2, a3, a4, a5);
}
