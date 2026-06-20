__int64 __fastcall wlan_cfg80211_set_feature(__int64 result, unsigned __int8 a2)
{
  *(_BYTE *)(result + (a2 >> 3)) |= 1 << (a2 & 7);
  return result;
}
