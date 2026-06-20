__int64 __fastcall hdd_oem_event_async_cb(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  _QWORD *link_info_by_vdev; // x0
  __int64 v21; // x1
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x20
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x2
  unsigned int v42; // w1

  context = _cds_get_context(51, (__int64)"hdd_oem_event_async_cb", a2, a3, a4, a5, a6, a7, a8, a9);
  result = qdf_trace_msg(0x33u, 8u, "%s: enter", v11, v12, v13, v14, v15, v16, v17, v18, "hdd_oem_event_async_cb");
  if ( context )
  {
    if ( *((_QWORD *)a1 + 5) )
      return hdd_copy_file_name_and_oem_data(context, a1);
    link_info_by_vdev = (_QWORD *)hdd_get_link_info_by_vdev((__int64)context, *a1);
    if ( link_info_by_vdev )
      v21 = *link_info_by_vdev + 112LL;
    else
      v21 = 0;
    v22 = _cfg80211_alloc_event_skb(
            context[3],
            v21,
            103,
            197,
            0,
            40,
            ((*((_DWORD *)a1 + 2) + 7) & 0xFFFFFFFC) + 16,
            3264);
    if ( v22 )
    {
      v31 = v22;
      v32 = nla_put(v22, 1, *((unsigned int *)a1 + 2), *((_QWORD *)a1 + 3));
      if ( v32 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: OEM event put fails status %d",
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          "hdd_oem_event_async_cb",
          v32);
        return sk_skb_reason_drop(0, v31, 2);
      }
      _cfg80211_send_event_skb(v31, 3264);
      v41 = "%s: exit";
      v42 = 8;
    }
    else
    {
      v41 = "%s: wlan_cfg80211_vendor_event_alloc failed";
      v42 = 2;
    }
    return qdf_trace_msg(0x33u, v42, v41, v23, v24, v25, v26, v27, v28, v29, v30, "hdd_oem_event_async_cb");
  }
  return result;
}
