__int64 __fastcall ieee80211_ibss_stop(__int64 a1)
{
  return wiphy_work_cancel(*(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL), a1 + 2304);
}
