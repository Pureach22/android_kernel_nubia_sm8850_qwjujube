__int64 __fastcall hdd_sr_osif_events(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *link_info_from_objmgr; // x0
  __int64 v15; // x24
  __int64 cmpt_obj; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w20
  unsigned int v26; // w21
  const char *v27; // x2
  unsigned int v28; // w1
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w22
  char v40; // w25
  unsigned int v41; // w23
  __int64 v42; // x6
  __int64 v43; // x0
  __int64 v44; // x24

  if ( !a1 )
  {
    v27 = "%s: Null VDEV";
    goto LABEL_7;
  }
  link_info_from_objmgr = (__int64 *)wlan_hdd_get_link_info_from_objmgr(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !link_info_from_objmgr )
  {
    v27 = "%s: Null adapter";
    goto LABEL_7;
  }
  v15 = *link_info_from_objmgr;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, a4, a5, a6, a7, a8, a9, a10, a11);
  if ( cmpt_obj )
  {
    v25 = *(unsigned __int8 *)(cmpt_obj + 184);
    v26 = *(unsigned __int8 *)(cmpt_obj + 185);
  }
  else
  {
    v25 = 0;
    v26 = 0;
  }
  v30 = wlan_vdev_mlme_get_cmpt_obj(a1, v17, v18, v19, v20, v21, v22, v23, v24);
  if ( !v30 )
  {
    v39 = 0;
    if ( a2 )
      goto LABEL_13;
LABEL_18:
    v40 = 0;
    v41 = 2;
    if ( a3 >= 2 )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: Invalid SR Reason Code: %d",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "hdd_sr_osif_events",
               a3);
    goto LABEL_21;
  }
  v39 = *(unsigned __int8 *)(v30 + 183);
  if ( !a2 )
    goto LABEL_18;
LABEL_13:
  if ( a2 != 1 )
  {
    if ( a2 != 2 )
      return qdf_trace_msg(
               0x33u,
               2u,
               "%s: Invalid SR Operation: %d",
               v31,
               v32,
               v33,
               v34,
               v35,
               v36,
               v37,
               v38,
               "hdd_sr_osif_events",
               a2);
    v40 = 0;
    v41 = 9;
    if ( a3 < 2 )
      goto LABEL_21;
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid SR Reason Code: %d",
             v31,
             v32,
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             "hdd_sr_osif_events",
             a3);
  }
  v41 = 3;
  v40 = 1;
  if ( a3 >= 2 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid SR Reason Code: %d",
             v31,
             v32,
             v33,
             v34,
             v35,
             v36,
             v37,
             v38,
             "hdd_sr_osif_events",
             a3);
LABEL_21:
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: SR Operation: %u SR Reason Code: %u",
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    "hdd_sr_osif_events",
    v41,
    a3);
  if ( (v41 & 0xAAAAAAAA) != 2 )
  {
    v27 = "%s: SR Operation not supported";
LABEL_30:
    v28 = 8;
    return qdf_trace_msg(0x33u, v28, v27, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_sr_osif_events");
  }
  if ( ((a3 == 0) & (unsigned __int8)v40) != 0 )
    v42 = 60;
  else
    v42 = 36;
  v43 = _cfg80211_alloc_event_skb(*(_QWORD *)(*(_QWORD *)(v15 + 24) + 24LL), v15 + 112, 103, 197, 0, 57, v42, 3264);
  if ( v43 )
  {
    v44 = v43;
    if ( (unsigned int)hdd_sr_pack_suspend_resume_event(v43, v41, a3, v25, v26, v39) )
      return sk_skb_reason_drop(0, v44, 2);
    _cfg80211_send_event_skb(v44, 3264);
    v27 = "%s: SR cfg80211 event is sent";
    goto LABEL_30;
  }
  v27 = "%s: wlan_cfg80211_vendor_event_alloc failed";
LABEL_7:
  v28 = 2;
  return qdf_trace_msg(0x33u, v28, v27, a4, a5, a6, a7, a8, a9, a10, a11, "hdd_sr_osif_events");
}
