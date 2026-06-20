__int64 __fastcall wlan_hdd_send_avoid_freq_event(
        __int64 a1,
        const void *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v21; // x20
  void *v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v32; // x2

  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_send_avoid_freq_event");
  if ( a1 )
  {
    if ( a2 )
    {
      v20 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 0, 680, 3264);
      if ( v20 )
      {
        v21 = v20;
        v22 = (void *)skb_put(v20, 680);
        memcpy(v22, a2, 0x2A8u);
        _cfg80211_send_event_skb(v21, 3264);
        qdf_trace_msg(0x33u, 8u, "%s: exit", v23, v24, v25, v26, v27, v28, v29, v30, "wlan_hdd_send_avoid_freq_event");
        return 0;
      }
      v32 = "%s: wlan_cfg80211_vendor_event_alloc failed";
    }
    else
    {
      v32 = "%s: avoid_freq_list is null";
    }
  }
  else
  {
    v32 = "%s: HDD context is null";
  }
  qdf_trace_msg(0x33u, 2u, v32, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_hdd_send_avoid_freq_event");
  return 4294967274LL;
}
