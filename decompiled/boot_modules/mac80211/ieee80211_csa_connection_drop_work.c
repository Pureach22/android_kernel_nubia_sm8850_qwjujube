__int64 __fastcall ieee80211_csa_connection_drop_work(__int64 a1, __int64 a2)
{
  __int64 v3; // x0

  v3 = ieee80211_ibss_disconnect(a2 - 2304);
  synchronize_rcu(v3);
  skb_queue_purge_reason(a2 - 320, 85);
  return wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(a2 - 688) + 72LL), a2 - 344);
}
