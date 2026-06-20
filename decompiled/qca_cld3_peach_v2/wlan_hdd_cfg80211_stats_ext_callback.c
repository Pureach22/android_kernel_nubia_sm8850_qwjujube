__int64 __fastcall wlan_hdd_cfg80211_stats_ext_callback(
        __int64 a1,
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
  __int64 result; // x0
  __int64 link_info_by_vdev; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x21
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x20
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  const char *v41; // x2
  int v42; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v43; // [xsp+8h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _wlan_hdd_validate_context(
             a1,
             (__int64)"wlan_hdd_cfg80211_stats_ext_callback",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10);
  if ( !(_DWORD)result )
  {
    link_info_by_vdev = hdd_get_link_info_by_vdev(a1, *a2);
    if ( link_info_by_vdev )
    {
      v22 = link_info_by_vdev;
      v23 = _cfg80211_alloc_event_skb(*(_QWORD *)(a1 + 24), 0, 103, 197, 0, 2, (unsigned int)(a2[1] + 36), 3264);
      if ( v23 )
      {
        v32 = v23;
        v42 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)v22 + 32LL) + 224LL);
        if ( (unsigned int)nla_put(v23, 4, 4, &v42) )
        {
          v41 = "%s: QCA_WLAN_VENDOR_ATTR_IFINDEX put fail";
        }
        else
        {
          if ( !(unsigned int)nla_put(v32, 3, (unsigned int)a2[1], a2 + 2) )
          {
            result = _cfg80211_send_event_skb(v32, 3264);
            goto LABEL_2;
          }
          v41 = "%s: QCA_WLAN_VENDOR_ATTR_STATS_EXT put fail";
        }
        qdf_trace_msg(0x33u, 2u, v41, v33, v34, v35, v36, v37, v38, v39, v40, "wlan_hdd_cfg80211_stats_ext_callback");
        result = sk_skb_reason_drop(0, v32, 2);
      }
      else
      {
        result = qdf_trace_msg(
                   0x33u,
                   2u,
                   "%s: wlan_cfg80211_vendor_event_alloc failed",
                   v24,
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   "wlan_hdd_cfg80211_stats_ext_callback");
      }
    }
    else
    {
      result = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: vdev_id %d does not exist with host",
                 v14,
                 v15,
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 "wlan_hdd_cfg80211_stats_ext_callback",
                 (unsigned int)*a2);
    }
  }
LABEL_2:
  _ReadStatusReg(SP_EL0);
  return result;
}
