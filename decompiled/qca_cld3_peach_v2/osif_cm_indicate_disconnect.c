__int64 __fastcall osif_cm_indicate_disconnect(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        char a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        unsigned int a8)
{
  __int64 result; // x0

  result = wlan_vdev_mlme_is_mlo_vdev(a1);
  if ( (result & 1) == 0 || (*(_BYTE *)(a1 + 60) & 2) == 0 )
    return cfg80211_disconnected(a2, a3, a5, a6, a4 & 1, a8);
  return result;
}
