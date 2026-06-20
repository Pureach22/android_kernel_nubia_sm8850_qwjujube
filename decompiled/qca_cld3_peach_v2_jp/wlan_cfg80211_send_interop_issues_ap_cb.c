__int64 __fastcall wlan_cfg80211_send_interop_issues_ap_cb(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x8
  __int64 v11; // x0
  unsigned __int8 *v12; // x20
  unsigned int v13; // t1
  __int64 v14; // x19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const char *v24; // x2

  if ( !a1 )
  {
    v24 = "%s: Invalid result.";
    return qdf_trace_msg(0x48u, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfg80211_send_interop_issues_ap_cb");
  }
  if ( !*(_QWORD *)a1 )
  {
    v24 = "%s: pdev is null.";
    return qdf_trace_msg(0x48u, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfg80211_send_interop_issues_ap_cb");
  }
  v9 = *(_QWORD **)(*(_QWORD *)a1 + 24LL);
  if ( !v9 )
  {
    v24 = "%s: os_priv is null.";
    return qdf_trace_msg(0x48u, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfg80211_send_interop_issues_ap_cb");
  }
  v11 = _cfg80211_alloc_event_skb(*v9, 0, 103, 197, 0, 24, 28, 3264);
  if ( !v11 )
  {
    v24 = "%s: skb alloc failed";
    return qdf_trace_msg(0x48u, 2u, v24, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_cfg80211_send_interop_issues_ap_cb");
  }
  v13 = a1[20];
  v12 = a1 + 20;
  v14 = v11;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: interop issues ap mac:%02x:%02x:%02x:**:**:%02x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wlan_cfg80211_send_interop_issues_ap_cb",
    v13,
    v12[1],
    v12[2],
    v12[5]);
  if ( !(unsigned int)nla_put(v14, 3, 6, v12) )
    return _cfg80211_send_event_skb(v14, 3264);
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: nla put fail",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "wlan_cfg80211_send_interop_issues_ap_cb");
  return sk_skb_reason_drop(0, v14, 2);
}
