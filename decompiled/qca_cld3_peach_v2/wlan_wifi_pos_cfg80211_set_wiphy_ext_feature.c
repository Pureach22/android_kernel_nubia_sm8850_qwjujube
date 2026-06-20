__int64 __fastcall wlan_wifi_pos_cfg80211_set_wiphy_ext_feature(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = wifi_pos_get_rsta_11az_ranging_cap(a1);
  if ( (_DWORD)result )
  {
    if ( (result & 1) != 0 && (*(_DWORD *)(a2 + 20) & 0x80000000) != 0 )
    {
      byte_92E49B |= 4u;
      byte_92E4AA |= 4u;
    }
    if ( (result & 2) != 0 && (*(_WORD *)(a2 + 24) & 0x201) != 0 )
    {
      byte_92E49B |= 8u;
      byte_92E4AA |= 8u;
    }
    iftype_ext_cap = 3;
    *(_QWORD *)(a1 + 304) = &iftype_ext_cap;
    qword_92E4B8 = (__int64)&wlan_extended_caps_iface;
    qword_92E4C0 = (__int64)&wlan_extended_caps_iface_mask;
    byte_92E4C8 = 15;
    *(_DWORD *)(a1 + 312) = 1;
  }
  return result;
}
