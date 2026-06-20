__int64 __fastcall cfg80211_rfkill_set_block(__int64 a1, char a2)
{
  __int64 v3; // x0

  if ( (a2 & 1) != 0 )
  {
    rtnl_lock();
    v3 = ((__int64 (__fastcall *)(__int64))cfg80211_shutdown_all_interfaces)(a1 + 992);
    rtnl_unlock(v3);
  }
  return 0;
}
