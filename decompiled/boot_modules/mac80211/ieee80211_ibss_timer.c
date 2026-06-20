__int64 __fastcall ieee80211_ibss_timer(__int64 a1)
{
  return wiphy_work_queue(*(_QWORD *)(*(_QWORD *)(a1 - 648) + 72LL), a1 - 304);
}
