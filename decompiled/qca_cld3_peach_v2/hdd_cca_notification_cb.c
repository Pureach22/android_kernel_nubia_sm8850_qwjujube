__int64 __fastcall hdd_cca_notification_cb(
        unsigned __int8 a1,
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
  _QWORD *context; // x21
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 result; // x0
  _QWORD *link_info_by_vdev; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x20
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+8h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(51, (__int64)"hdd_cca_notification_cb", a3, a4, a5, a6, a7, a8, a9, a10);
  result = _wlan_hdd_validate_context(
             (__int64)context,
             (__int64)"hdd_cca_notification_cb",
             v13,
             v14,
             v15,
             v16,
             v17,
             v18,
             v19,
             v20);
  if ( !(_DWORD)result )
  {
    link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev((__int64)context, a1);
    if ( link_info_by_vdev )
    {
      v31 = _cfg80211_alloc_event_skb(context[3], *link_info_by_vdev + 112LL, 103, 197, 0, 43, 72, 3264);
      if ( v31 )
      {
        v40 = v31;
        LOBYTE(v49) = 0;
        if ( (unsigned int)nla_put(v31, 1, 1, &v49)
          || (v49 = a2[2], (unsigned int)nla_put(v40, 3, 4, &v49))
          || (v49 = a2[2] - a2[3], (unsigned int)nla_put(v40, 4, 4, &v49))
          || (v49 = a2[5], (unsigned int)nla_put(v40, 5, 4, &v49))
          || (v49 = a2[4] - a2[5], (unsigned int)nla_put(v40, 6, 4, &v49))
          || (v49 = *a2, (unsigned int)nla_put(v40, 7, 4, &v49))
          || (v49 = a2[1], (unsigned int)nla_put(v40, 8, 4, &v49)) )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: nla put failed",
            v41,
            v42,
            v43,
            v44,
            v45,
            v46,
            v47,
            v48,
            "hdd_cca_notification_cb");
          result = sk_skb_reason_drop(0, v40, 2);
        }
        else
        {
          result = _cfg80211_send_event_skb(v40, 3264);
        }
      }
      else
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: wlan_cfg80211_vendor_event_alloc failed",
                   v32,
                   v33,
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   "hdd_cca_notification_cb");
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Failed to find adapter of vdev %d",
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 "hdd_cca_notification_cb",
                 a1);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
