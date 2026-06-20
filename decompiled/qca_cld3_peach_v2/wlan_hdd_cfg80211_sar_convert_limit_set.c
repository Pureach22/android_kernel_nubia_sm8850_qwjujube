__int64 __fastcall wlan_hdd_cfg80211_sar_convert_limit_set(unsigned int a1, _DWORD *a2)
{
  int v2; // w8

  if ( a1 > 7 )
    return 0xFFFFFFFFLL;
  v2 = dword_B355A8[a1];
  *a2 = v2;
  return 0;
}
