_QWORD *__fastcall hdd_send_roam_scan_ch_list_event(
        _QWORD *result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        __int64 a10,
        unsigned __int16 a11,
        __int64 a12)
{
  _QWORD *v13; // x20
  __int64 v15; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x20

  if ( result )
  {
    v13 = result;
    result = (_QWORD *)hdd_get_link_info_by_vdev(result);
    if ( result )
    {
      v15 = _cfg80211_alloc_event_skb(v13[3], *result + 112LL, 103, 197, 0, 42, ((a11 + 7) & 0x1FFFCu) + 16, 3264);
      if ( v15 )
      {
        v24 = v15;
        v25 = nla_put(v15, 1, a11, a12);
        if ( v25 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: OEM event put fails status %d",
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            "hdd_send_roam_scan_ch_list_event",
            v25);
          return (_QWORD *)sk_skb_reason_drop(0, v24, 2);
        }
        else
        {
          return (_QWORD *)_cfg80211_send_event_skb(v24, 3264);
        }
      }
      else
      {
        return (_QWORD *)qdf_trace_msg(
                           0x33u,
                           2u,
                           "%s: wlan_cfg80211_vendor_event_alloc failed",
                           v16,
                           v17,
                           v18,
                           v19,
                           v20,
                           v21,
                           v22,
                           v23,
                           "hdd_send_roam_scan_ch_list_event");
      }
    }
  }
  else
  {
    v34 = jiffies;
    if ( hdd_send_roam_scan_ch_list_event___last_ticks - jiffies + 125 < 0 )
    {
      result = (_QWORD *)qdf_trace_msg(
                           0x33u,
                           2u,
                           "%s: hdd context is null",
                           a2,
                           a3,
                           a4,
                           a5,
                           a6,
                           a7,
                           a8,
                           a9,
                           "hdd_send_roam_scan_ch_list_event");
      hdd_send_roam_scan_ch_list_event___last_ticks = v34;
    }
  }
  return result;
}
