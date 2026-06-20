__int64 __fastcall wlan_scan_cfg80211_add_connected_pno_support(__int64 result)
{
  *(_BYTE *)(result + 113) |= 0x10u;
  return result;
}
