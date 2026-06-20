__int64 __fastcall wlan_hdd_send_idle_shutdown_event(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v12; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  const char *v31; // x2
  unsigned int v32; // w1
  int v33; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_send_idle_shutdown_event");
  v12 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 73, 4, 3264);
  if ( !v12 )
  {
    v31 = "%s: wlan_cfg80211_vendor_event_alloc failed";
    v32 = 2;
LABEL_6:
    result = qdf_trace_msg(0x33u, v32, v31, v13, v14, v15, v16, v17, v18, v19, v20, "wlan_hdd_send_idle_shutdown_event");
    goto LABEL_7;
  }
  v21 = v12;
  v33 = a2;
  if ( !(unsigned int)nla_put(v12, 1, 4, &v33) )
  {
    _cfg80211_send_event_skb(v21, 3264);
    v31 = "%s: exit";
    v32 = 8;
    goto LABEL_6;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: QCA_WLAN_VENDOR_ATTR_IDLE_SHUTDOWN_STATUS put fail",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "wlan_hdd_send_idle_shutdown_event");
  result = sk_skb_reason_drop(0, v21, 2);
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}
