__int64 __fastcall ieee80211_radar_detected(__int64 a1, __int64 a2)
{
  ieee80211_iter_chan_contexts_atomic(
    a1,
    (__int64 (__fastcall *)(__int64, __int64 *, __int64))ieee80211_radar_mark_chan_ctx_iterator,
    a2);
  return wiphy_work_queue(*(_QWORD *)(a1 + 72), a1 + 1480);
}
