__int64 __fastcall wlan_cfg80211_get_nl80211_chwidth(unsigned int a1)
{
  if ( a1 < 8 )
    return dword_B35588[a1];
  qdf_trace_msg(72, 8, "%s: Invalid channel width %u", "wlan_cfg80211_get_nl80211_chwidth", a1);
  return 1;
}
