__int64 __fastcall wlan_hdd_send_hang_reason_event(
        __int64 a1,
        int a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x21
  int v34; // w8
  __int64 result; // x0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+8h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_send_hang_reason_event");
  if ( !a1 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HDD context is null",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_hdd_send_hang_reason_event");
LABEL_11:
    result = 4294967274LL;
    goto LABEL_12;
  }
  v24 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 32, a4 + 4, 3264);
  if ( v24 )
  {
    v33 = v24;
    if ( (unsigned int)(a2 - 1) > 0x20 )
      v34 = 0;
    else
      v34 = dword_A05450[a2 - 1];
    v52 = v34;
    if ( !(unsigned int)nla_put(v24, 1, 4, &v52) && !(unsigned int)nla_put(v33, 2, a4, a3) )
    {
      _cfg80211_send_event_skb(v33, 3264);
      qdf_trace_msg(0x33u, 8u, "%s: exit", v44, v45, v46, v47, v48, v49, v50, v51, "wlan_hdd_send_hang_reason_event");
      result = 0;
      goto LABEL_12;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: QCA_WLAN_VENDOR_ATTR_HANG_REASON put fail",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      "wlan_hdd_send_hang_reason_event");
    sk_skb_reason_drop(0, v33, 2);
    goto LABEL_11;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: wlan_cfg80211_vendor_event_alloc failed",
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    "wlan_hdd_send_hang_reason_event");
  result = 4294967284LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
