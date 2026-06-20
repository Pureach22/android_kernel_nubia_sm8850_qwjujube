__int64 __fastcall ieee80211_ready_on_channel(__int64 a1)
{
  *(_QWORD *)(a1 + 5328) = jiffies;
  return wiphy_work_queue(*(_QWORD *)(a1 + 72), a1 + 5280);
}
