_QWORD *__fastcall hdd_send_scan_done_complete_cb(
        unsigned __int8 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *result; // x0
  _QWORD *v11; // x20
  _QWORD *link_info_by_vdev; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20

  result = _cds_get_context(51, (__int64)"hdd_send_scan_done_complete_cb", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( result )
  {
    v11 = result;
    link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev((__int64)result, a1);
    if ( link_info_by_vdev )
    {
      v21 = _cfg80211_alloc_event_skb(v11[3], *link_info_by_vdev + 112LL, 103, 197, 0, 61, 16, 3264);
      if ( v21 )
      {
        v30 = v21;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: sending scan done ind to upper layer for vdev_id:%d",
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          "hdd_send_scan_done_complete_cb",
          a1);
        return (_QWORD *)_cfg80211_send_event_skb(v30, 3264);
      }
      else
      {
        return (_QWORD *)qdf_trace_msg(
                           0x33u,
                           2u,
                           "%s: wlan_cfg80211_vendor_event_alloc failed",
                           v22,
                           v23,
                           v24,
                           v25,
                           v26,
                           v27,
                           v28,
                           v29,
                           "hdd_send_scan_done_complete_cb");
      }
    }
    else
    {
      return (_QWORD *)qdf_trace_msg(
                         0x33u,
                         2u,
                         "%s: Invalid vdev id:%d",
                         v13,
                         v14,
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         "hdd_send_scan_done_complete_cb",
                         a1);
    }
  }
  return result;
}
