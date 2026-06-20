__int64 __fastcall hdd_cfr_data_send_nl_event(
        unsigned __int8 a1,
        unsigned int a2,
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
  _QWORD *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  _QWORD *v25; // x23
  __int64 link_info_by_vdev; // x0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 *v35; // x24
  __int64 v36; // x23
  __int64 v37; // x24
  unsigned int v38; // w0
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x23
  unsigned int v49; // w0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v59; // x8
  __int64 v60; // x20
  unsigned int v61; // w0

  context = _cds_get_context(51, (__int64)"hdd_cfr_data_send_nl_event", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( !context )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: HDD context is NULL",
             v17,
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             "hdd_cfr_data_send_nl_event");
  v25 = context;
  link_info_by_vdev = hdd_get_link_info_by_vdev(context);
  if ( !link_info_by_vdev )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: adapter NULL for vdev id %d",
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             "hdd_cfr_data_send_nl_event",
             a1);
  v35 = (__int64 *)link_info_by_vdev;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: vdev id %d pid %d data len %d",
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    "hdd_cfr_data_send_nl_event",
    a1,
    a2,
    a4);
  v36 = v25[3];
  v37 = *v35;
  v38 = qdf_mem_malloc_flags();
  v39 = _cfg80211_alloc_event_skb(v36, v37 + 112, 103, 197, 0, 50, ((a4 + 7) & 0xFFFFFFFC) + 16, v38);
  if ( !v39 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: wlan_cfg80211_vendor_event_alloc failed vdev id %d, data len %d",
             v40,
             v41,
             v42,
             v43,
             v44,
             v45,
             v46,
             v47,
             "hdd_cfr_data_send_nl_event",
             a1,
             a4);
  v48 = v39;
  v49 = nla_put(v39, 28, a4, a3);
  if ( v49 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: CFR event put fails status %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "hdd_cfr_data_send_nl_event",
      v49);
    return sk_skb_reason_drop(0, v48, 2);
  }
  else
  {
    if ( a2 )
    {
      v59 = *(_QWORD *)(v48 + 224);
      if ( v59 )
      {
        *(_DWORD *)(v59 + 12) = a2;
      }
      else
      {
        v60 = jiffies;
        if ( hdd_cfr_data_send_nl_event___last_ticks - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: nlhdr is null",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "hdd_cfr_data_send_nl_event");
          hdd_cfr_data_send_nl_event___last_ticks = v60;
        }
      }
    }
    v61 = qdf_mem_malloc_flags();
    return _cfg80211_send_event_skb(v48, v61);
  }
}
