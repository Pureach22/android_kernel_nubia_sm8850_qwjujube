__int64 __fastcall ieee80211_xmit(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x22

  v3 = *(_QWORD *)(a1 + 1616);
  if ( (unsigned int)ieee80211_skb_resize() )
    return ieee80211_free_txskb(v3, a3);
  *(_QWORD *)(a3 + 64) = a1 + 4720;
  ieee80211_set_qos_hdr(a1, a3);
  return ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))ieee80211_tx)(a1, a2, a3, 0);
}
