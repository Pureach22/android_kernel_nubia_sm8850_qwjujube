__int64 __fastcall wlan_hdd_mlo_link_add_pairwise_key(
        __int64 result,
        __int64 *a2,
        unsigned int a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x21

  _ReadStatusReg(SP_EL0);
  v15 = *(_QWORD *)(*(_QWORD *)(result + 1360) + 3880LL);
  if ( *(_DWORD *)(v15 + 24) | *(unsigned __int16 *)(v15 + 28) && *(unsigned __int8 *)(v15 + 6) != 255 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Add key link id %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_hdd_mlo_link_add_pairwise_key");
    result = wlan_cfg80211_store_link_key(*a2, a3, 0, v15 + 24, a4, v15, *(unsigned __int8 *)(v15 + 6));
  }
  if ( *(_DWORD *)(v15 + 72) | *(unsigned __int16 *)(v15 + 76) && *(unsigned __int8 *)(v15 + 54) != 255 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Add key link id %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_hdd_mlo_link_add_pairwise_key");
    result = wlan_cfg80211_store_link_key(*a2, a3, 0, v15 + 72, a4, v15 + 48, *(unsigned __int8 *)(v15 + 54));
  }
  if ( *(_DWORD *)(v15 + 120) | *(unsigned __int16 *)(v15 + 124) && *(unsigned __int8 *)(v15 + 102) != 255 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Add key link id %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_hdd_mlo_link_add_pairwise_key");
    result = wlan_cfg80211_store_link_key(*a2, a3, 0, v15 + 120, a4, v15 + 96, *(unsigned __int8 *)(v15 + 102));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
