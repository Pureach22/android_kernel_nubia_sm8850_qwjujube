__int64 sub_172B50()
{
  __int64 v0; // x22

  if ( (v0 & 0x100000000000000LL) != 0 )
    JUMPOUT(0x16DFA8);
  return wlan_cfg80211_cleanup_scan_queue();
}
