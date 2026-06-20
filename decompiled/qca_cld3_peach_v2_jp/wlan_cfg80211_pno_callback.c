__int64 __fastcall wlan_cfg80211_pno_callback(__int64 result, _DWORD *a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  _QWORD *v4; // x8

  if ( a2[1] == 11 )
  {
    v2 = result;
    qdf_trace_msg(72, 8, "%s: vdev id = %d", "wlan_cfg80211_pno_callback", *a2);
    v3 = *(_QWORD *)(v2 + 152);
    if ( v3 )
    {
      v4 = *(_QWORD **)(v3 + 24);
      if ( v4 )
        return cfg80211_sched_scan_results(*v4, 0);
      else
        return qdf_trace_msg(72, 2, "%s: pdev_ospriv is NULL", "wlan_cfg80211_pno_callback");
    }
    else
    {
      return qdf_trace_msg(72, 2, "%s: pdev is NULL", "wlan_cfg80211_pno_callback");
    }
  }
  return result;
}
