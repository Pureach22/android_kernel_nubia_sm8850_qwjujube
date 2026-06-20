__int64 __fastcall ieee80211_mgd_stop_link(__int64 a1)
{
  wiphy_work_cancel(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 1616LL) + 72LL), a1 + 792);
  wiphy_work_cancel(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 1616LL) + 72LL), a1 + 816);
  return wiphy_delayed_work_cancel(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 1616LL) + 72LL), a1 + 568);
}
