__int64 __fastcall hdd_rssi_threshold_breached(
        __int64 a1,
        unsigned int *a2,
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
  __int64 result; // x0
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
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  unsigned int v48; // [xsp+0h] [xbp-10h] BYREF
  char v49[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x33u, 8u, "%s: enter", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_rssi_threshold_breached");
  result = _wlan_hdd_validate_context(
             a1,
             (__int64)"hdd_rssi_threshold_breached",
             v12,
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19);
  if ( (_DWORD)result )
    goto LABEL_11;
  if ( !a2 )
  {
    v47 = "%s: data is null";
LABEL_10:
    result = qdf_trace_msg(0x33u, 2u, v47, v21, v22, v23, v24, v25, v26, v27, v28, "hdd_rssi_threshold_breached");
    goto LABEL_11;
  }
  v29 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 19, 4112, 3264);
  if ( !v29 )
  {
    v47 = "%s: mem alloc failed";
    goto LABEL_10;
  }
  v30 = v29;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Req Id: %u Current rssi: %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "hdd_rssi_threshold_breached",
    *a2,
    (unsigned int)*((char *)a2 + 8));
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: Current BSSID: %02x:%02x:%02x:**:**:%02x",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "hdd_rssi_threshold_breached",
    *((unsigned __int8 *)a2 + 9),
    *((unsigned __int8 *)a2 + 10),
    *((unsigned __int8 *)a2 + 11),
    *((unsigned __int8 *)a2 + 14));
  v48 = *a2;
  if ( (unsigned int)nla_put(v30, 2, 4, &v48)
    || (unsigned int)nla_put(v30, 5, 6, (char *)a2 + 9)
    || (v49[0] = *((_BYTE *)a2 + 8), (unsigned int)nla_put(v30, 6, 1, v49)) )
  {
    qdf_trace_msg(0x33u, 2u, "%s: nla put fail", v39, v40, v41, v42, v43, v44, v45, v46, "hdd_rssi_threshold_breached");
    result = sk_skb_reason_drop(0, v30, 2);
  }
  else
  {
    result = _cfg80211_send_event_skb(v30, 3264);
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
