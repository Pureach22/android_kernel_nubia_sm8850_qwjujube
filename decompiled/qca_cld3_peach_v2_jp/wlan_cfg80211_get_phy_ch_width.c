__int64 __fastcall wlan_cfg80211_get_phy_ch_width(int a1)
{
  unsigned int v1; // w19

  if ( (unsigned int)(a1 - 1) >= 7 )
  {
    v1 = 8;
    qdf_trace_msg(72, 8, "%s: Invalid nl80211 channel width %u", "wlan_cfg80211_get_phy_ch_width", a1);
  }
  else
  {
    return dword_9DE1D8[a1 - 1];
  }
  return v1;
}
