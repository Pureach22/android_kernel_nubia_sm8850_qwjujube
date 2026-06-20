double __fastcall sub_67AB40(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __asm { UDOT            V20.2D, V20.16B, V26.16B }
  return wlan_cfg80211_spectral_scan_get_status(a1, a2, a3, a4, a5);
}
