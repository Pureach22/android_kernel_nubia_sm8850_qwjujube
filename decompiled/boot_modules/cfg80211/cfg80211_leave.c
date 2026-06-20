__int64 __fastcall cfg80211_leave(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 result; // x0
  int v6; // w8
  _QWORD *v7; // x8
  _QWORD *v8; // x22

  v2 = *(_QWORD *)(a2 + 32);
  cfg80211_pmsr_wdev_down(a2);
  result = cfg80211_stop_background_radar_detection(a2);
  v6 = *(_DWORD *)(a2 + 8);
  if ( v6 <= 6 )
  {
    if ( v6 == 1 )
      return cfg80211_leave_ibss(a1, v2, 1);
    if ( v6 == 2 )
    {
LABEL_13:
      v7 = *(_QWORD **)(a1 + 248);
      if ( v7 != (_QWORD *)(a1 + 248) )
      {
        do
        {
          v8 = (_QWORD *)*v7;
          if ( v2 == *(v7 - 6) )
            cfg80211_stop_sched_scan_req(a1, v7 - 21, 0);
          v7 = v8;
        }
        while ( v8 != (_QWORD *)(a1 + 248) );
      }
      return cfg80211_disconnect(a1, v2, 3, 1);
    }
    if ( v6 != 3 )
      return result;
    return cfg80211_stop_ap(a1, v2, 0xFFFFFFFFLL, 1);
  }
  if ( v6 <= 8 )
  {
    if ( v6 == 7 )
      return cfg80211_leave_mesh(a1, v2);
    goto LABEL_13;
  }
  if ( v6 == 9 )
    return cfg80211_stop_ap(a1, v2, 0xFFFFFFFFLL, 1);
  if ( v6 == 11 )
    return cfg80211_leave_ocb(a1, v2);
  return result;
}
