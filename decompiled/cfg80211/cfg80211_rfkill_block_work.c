__int64 __fastcall cfg80211_rfkill_block_work(__int64 a1)
{
  __int64 v2; // x0

  rtnl_lock();
  v2 = ((__int64 (__fastcall *)(__int64))cfg80211_shutdown_all_interfaces)(a1 + 944);
  return rtnl_unlock(v2);
}
