__int64 __fastcall wlan_cfg80211_get_phy_ch_width(int a1)
{
  int v1; // w8
  unsigned int v2; // w19

  v1 = a1 - 1;
  if ( (unsigned int)(a1 - 1) < 0xD && ((0x107Fu >> v1) & 1) != 0 )
  {
    return dword_ACFDA8[v1];
  }
  else
  {
    v2 = 8;
    qdf_trace_msg(72, 8, "%s: Invalid channel width %u", "wlan_cfg80211_get_phy_ch_width", a1);
  }
  return v2;
}
