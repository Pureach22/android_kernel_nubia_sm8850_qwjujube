__int64 __fastcall ieee80211_remain_on_channel_expired(__int64 a1)
{
  return wiphy_work_queue(*(_QWORD *)(a1 + 72), a1 + 5304);
}
