__int64 __fastcall ieee80211_vif_block_queues_csa(__int64 result)
{
  __int64 v1; // x19
  unsigned int vif_queues; // w0

  v1 = *(_QWORD *)(result + 1616);
  if ( (*(_QWORD *)(v1 + 96) & 0x80000000000000LL) == 0 )
  {
    vif_queues = ieee80211_get_vif_queues(*(_QWORD *)(result + 1616), result);
    return ieee80211_stop_queues_by_reason(v1, vif_queues, 2, 0);
  }
  return result;
}
