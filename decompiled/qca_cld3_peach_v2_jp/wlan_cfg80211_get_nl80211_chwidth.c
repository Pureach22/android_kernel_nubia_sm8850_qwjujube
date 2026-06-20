__int64 __fastcall wlan_cfg80211_get_nl80211_chwidth(unsigned int a1)
{
  if ( a1 < 0xA && ((0x27Fu >> a1) & 1) != 0 )
    return dword_9DE1B0[a1];
  qdf_trace_msg(72, 8, "%s: Invalid channel width %u", "wlan_cfg80211_get_nl80211_chwidth", a1);
  return 1;
}
