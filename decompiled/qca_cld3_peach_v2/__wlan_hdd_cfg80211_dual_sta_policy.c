__int64 __fastcall _wlan_hdd_cfg80211_dual_sta_policy(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  unsigned int v12; // w19
  __int64 result; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7

  v10 = *(_QWORD *)(a2 + 8);
  v12 = *(unsigned __int8 *)(v10 + 4);
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: Concurrent STA policy : %d",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "__wlan_hdd_cfg80211_dual_sta_policy",
             *(unsigned __int8 *)(v10 + 4));
  if ( v12 <= 1 )
  {
    result = wlan_mlme_set_dual_sta_policy(*(_QWORD *)a1, v12);
    if ( (_DWORD)result )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: failed to set MLME dual sta config",
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               v20,
               v21,
               "__wlan_hdd_cfg80211_dual_sta_policy");
    else
      *(_BYTE *)(a1 + 7118) = v12;
  }
  return result;
}
