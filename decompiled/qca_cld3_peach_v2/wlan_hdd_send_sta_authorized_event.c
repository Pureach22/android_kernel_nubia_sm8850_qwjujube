__int64 __fastcall wlan_hdd_send_sta_authorized_event(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x19
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  const char *v40; // x2
  __int64 result; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  _QWORD v50[2]; // [xsp+0h] [xbp-10h] BYREF

  v50[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v50[0] = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_send_sta_authorized_event");
  if ( a2 )
  {
    v22 = _cfg80211_alloc_event_skb(*(_QWORD *)(a2 + 24), a1 + 112, 103, 197, 0, 36, 30, 3264);
    if ( v22 )
    {
      v31 = v22;
      qdf_mem_set(v50, 8u, 0);
      LODWORD(v50[0]) |= 2u;
      HIDWORD(v50[0]) = 1;
      if ( (unsigned int)nla_put(v31, 5, 8, v50) )
      {
        v40 = "%s: STA flag put fails";
      }
      else
      {
        if ( !(unsigned int)nla_put(v31, 4, 6, a3) )
        {
          _cfg80211_send_event_skb(v31, 3264);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: exit",
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            "wlan_hdd_send_sta_authorized_event");
          result = 0;
          goto LABEL_11;
        }
        v40 = "%s: STA MAC put fails";
      }
      qdf_trace_msg(0x33u, 2u, v40, v32, v33, v34, v35, v36, v37, v38, v39, "wlan_hdd_send_sta_authorized_event");
      sk_skb_reason_drop(0, v31, 2);
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_cfg80211_vendor_event_alloc failed",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "wlan_hdd_send_sta_authorized_event");
    }
    result = 16;
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: HDD context is null",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "wlan_hdd_send_sta_authorized_event");
    result = 4;
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
