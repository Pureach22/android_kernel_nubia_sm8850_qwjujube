__int64 __fastcall wlan_hdd_send_green_ap_ll_ps_event(
        __int64 a1,
        unsigned __int16 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 **v10; // x19
  __int64 *v12; // x19
  __int64 v13; // x21
  unsigned int v14; // w0
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x19
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  const char *v33; // x2
  __int64 result; // x0
  unsigned int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  _QWORD v44[2]; // [xsp+0h] [xbp-10h] BYREF

  v44[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 ***)(a1 + 608);
  if ( !v10 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: OSIF priv is NULL",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_hdd_send_green_ap_ll_ps_event");
LABEL_12:
    result = 16;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: enter(%s)",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_hdd_send_green_ap_ll_ps_event",
    (*v10)[4] + 296);
  v12 = *v10;
  v13 = *v12;
  v14 = qdf_mem_malloc_flags();
  v15 = _cfg80211_alloc_event_skb(v13, v12, 103, 197, 0, 59, 48, v14);
  if ( v15 )
  {
    v24 = v15;
    v44[0] = *((unsigned int *)a2 + 1);
    if ( (unsigned int)nla_put_64bit(v15, 2, 8, v44, 229) )
    {
      v33 = "%s: nla_put failed";
    }
    else
    {
      v44[0] = *((_QWORD *)a2 + 1);
      if ( (unsigned int)nla_put_64bit(v24, 3, 8, v44, 229) )
      {
        v33 = "%s: nla_put failed for next tsf";
      }
      else
      {
        LOWORD(v44[0]) = *a2;
        if ( !(unsigned int)nla_put(v24, 4, 2, v44) )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: next_tsf : %llu, cookie: %u beacon multiplier: %u",
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            "wlan_hdd_send_green_ap_ll_ps_event",
            *((_QWORD *)a2 + 1),
            *((unsigned int *)a2 + 1),
            *a2);
          v35 = qdf_mem_malloc_flags();
          _cfg80211_send_event_skb(v24, v35);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: exit",
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            "wlan_hdd_send_green_ap_ll_ps_event");
          result = 0;
          goto LABEL_13;
        }
        v33 = "%s: nla_put for BI multiplier failed";
      }
    }
    qdf_trace_msg(0x33u, 2u, v33, v25, v26, v27, v28, v29, v30, v31, v32, "wlan_hdd_send_green_ap_ll_ps_event");
    sk_skb_reason_drop(0, v24, 2);
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: skb allocation failed",
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    "wlan_hdd_send_green_ap_ll_ps_event");
  result = 2;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
