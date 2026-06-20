__int64 __fastcall wlan_hdd_p2p_lo_event_callback(
        __int64 a1,
        int *a2,
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
  _QWORD *link_info_by_vdev; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x0
  __int64 v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 result; // x0
  const char *v40; // x2
  __int64 v41; // x4
  const char *v42; // x2
  unsigned int v43; // w1
  int v44; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_p2p_lo_event_callback");
  if ( !a1 )
  {
    v40 = "%s: Invalid HDD context pointer";
LABEL_9:
    result = qdf_trace_msg(0x33u, 2u, v40, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_hdd_p2p_lo_event_callback");
    goto LABEL_12;
  }
  link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev(a1, *a2);
  if ( !link_info_by_vdev )
  {
    v41 = (unsigned int)*a2;
    v42 = "%s: Cannot find adapter by vdev_id = %d";
    v43 = 2;
LABEL_11:
    result = qdf_trace_msg(
               0x33u,
               v43,
               v42,
               v21,
               v22,
               v23,
               v24,
               v25,
               v26,
               v27,
               v28,
               "wlan_hdd_p2p_lo_event_callback",
               v41);
    goto LABEL_12;
  }
  v29 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), *link_info_by_vdev + 112LL, 103, 197, 0, 27, 20, 3264);
  if ( !v29 )
  {
    v40 = "%s: wlan_cfg80211_vendor_event_alloc failed";
    goto LABEL_9;
  }
  v30 = v29;
  v44 = a2[1];
  if ( !(unsigned int)nla_put(v29, 8, 4, &v44) )
  {
    _cfg80211_send_event_skb(v30, 3264);
    v41 = (unsigned int)*a2;
    v42 = "%s: Sent P2P_LISTEN_OFFLOAD_STOP event for vdev_id = %d";
    v43 = 8;
    goto LABEL_11;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: nla put failed",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "wlan_hdd_p2p_lo_event_callback");
  result = sk_skb_reason_drop(0, v30, 2);
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
