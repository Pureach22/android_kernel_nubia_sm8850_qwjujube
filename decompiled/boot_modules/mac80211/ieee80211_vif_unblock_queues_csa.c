__int64 __fastcall ieee80211_vif_unblock_queues_csa(__int64 a1)
{
  __int64 v1; // x19
  unsigned int vif_queues; // w0

  v1 = *(_QWORD *)(a1 + 1616);
  vif_queues = ieee80211_get_vif_queues(v1, a1);
  return ieee80211_wake_queues_by_reason(v1, vif_queues, 2, 0);
}
