__int64 __fastcall hdd_pagefault_action_cb(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _QWORD *context; // x0
  _QWORD *v13; // x19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 ssr_frequency_on_pagefault; // x0
  __int64 v23; // x20
  unsigned __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x5
  unsigned int gfp_flags; // w22
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x19
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7

  context = _cds_get_context(51, (__int64)"hdd_pagefault_action_cb", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
    return 29;
  v13 = context;
  if ( (wlan_pmo_enable_ssr_on_page_fault(*context) & 1) != 0 )
  {
    qdf_trace_msg(0x33u, 8u, "%s: enter", v14, v15, v16, v17, v18, v19, v20, v21, "hdd_ssr_on_pagefault_cb");
    ssr_frequency_on_pagefault = ucfg_pmo_get_ssr_frequency_on_pagefault(*v13);
    v23 = jiffies;
    v24 = _msecs_to_jiffies(ssr_frequency_on_pagefault);
    v33 = v13[1025];
    if ( v33 && v23 - v33 < v24 )
      return 3;
    qdf_trace_msg(
      0x33u,
      4u,
      "%s: curr_time %lu last_pagefault_ssr_time %lu ssr_frequency %lu",
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      "hdd_ssr_on_pagefault_cb",
      v23);
    v13[1025] = v23;
    _cds_trigger_recovery(29, (__int64)"hdd_ssr_on_pagefault_cb", 19288, v54, v55, v56, v57, v58, v59, v60, v61);
  }
  else
  {
    gfp_flags = cds_get_gfp_flags();
    v36 = _cfg80211_alloc_event_skb(v13[3], 0, 103, 197, 0, 66, (unsigned __int16)(a2 + 16), gfp_flags);
    if ( !v36 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: wlan_cfg80211_vendor_event_alloc failed",
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        "hdd_send_pagefault_report_to_user");
      return 2;
    }
    v45 = v36;
    if ( (unsigned int)nla_put(v36, 1, a2, a1) )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Failed to fill pagefault blob data",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "hdd_send_pagefault_report_to_user");
      sk_skb_reason_drop(0, v45, 2);
      return 16;
    }
    _cfg80211_send_event_skb(v45, gfp_flags);
  }
  return 0;
}
