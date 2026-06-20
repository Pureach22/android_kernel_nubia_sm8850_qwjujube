__int64 __fastcall ieee80211_dynamic_ps_timer(__int64 a1)
{
  return wiphy_work_queue(*(_QWORD *)(a1 - 4992), a1 - 48);
}
