__int64 __fastcall ieee80211_free_txskb(__int64 a1, __int64 a2)
{
  ieee80211_report_used_skb(a1, a2, 1, 0);
  return dev_kfree_skb_any_reason(a2, 2);
}
