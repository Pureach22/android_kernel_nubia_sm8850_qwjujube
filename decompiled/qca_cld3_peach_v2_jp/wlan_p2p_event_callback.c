__int64 __fastcall wlan_p2p_event_callback(
        __int64 a1,
        unsigned int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x0
  __int64 v21; // x19
  _QWORD *p2p_wdev; // x21
  const char *v23; // x2
  const char *v24; // x2
  _QWORD *v25; // x8
  unsigned int v26; // w8
  __int64 channel_khz; // x0
  __int64 v28; // x22
  unsigned int v29; // w8
  unsigned int *v30; // x8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  qdf_trace_msg(
    0x48u,
    8u,
    "%s: user data:%pK, vdev id:%d, event type:%d opmode:%d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wlan_p2p_event_callback",
    a1,
    *a2,
    a2[1],
    a2[6]);
  if ( !a1 )
  {
    v24 = "%s: psoc is null";
    return qdf_trace_msg(0x48u, 2u, v24, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_p2p_event_callback");
  }
  v20 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, *a2, 15);
  if ( !v20 )
  {
    v24 = "%s: vdev is null";
    return qdf_trace_msg(0x48u, 2u, v24, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_p2p_event_callback");
  }
  v21 = v20;
  if ( a2[6] == 7 && (a2[7] & 1) != 0 && (ucfg_p2p_is_sta_vdev_usage_allowed_for_p2p_dev(a1) & 1) != 0 )
  {
    p2p_wdev = (_QWORD *)osif_vdev_mgr_get_p2p_wdev();
    if ( !p2p_wdev )
      goto LABEL_7;
  }
  else
  {
    v25 = *(_QWORD **)(v21 + 608);
    if ( !v25 )
    {
      v23 = "%s: osif_priv is null";
      goto LABEL_21;
    }
    p2p_wdev = (_QWORD *)*v25;
    if ( !*v25 )
    {
LABEL_7:
      v23 = "%s: wireless dev is null";
LABEL_21:
      qdf_trace_msg(0x48u, 2u, v23, v12, v13, v14, v15, v16, v17, v18, v19, "wlan_p2p_event_callback");
      return wlan_objmgr_vdev_release_ref(v21, 0xFu, v30, v31, v32, v33, v34, v35, v36, v37, v38);
    }
  }
  if ( !*p2p_wdev || (v26 = a2[4]) == 0 )
  {
    v23 = "%s: wiphy or freq is null";
    goto LABEL_21;
  }
  channel_khz = ieee80211_get_channel_khz(*p2p_wdev, 1000 * v26);
  if ( !channel_khz )
  {
    v23 = "%s: channel conversion failed";
    goto LABEL_21;
  }
  v28 = channel_khz;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Indicate frame over nl80211, idx:%d and interface:%s",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wlan_p2p_event_callback",
    *(unsigned int *)(p2p_wdev[4] + 224LL),
    p2p_wdev[4] + 296LL);
  v29 = a2[1];
  if ( v29 == 1 )
  {
    cfg80211_remain_on_channel_expired(p2p_wdev, *((_QWORD *)a2 + 1), v28, 3264);
    return wlan_objmgr_vdev_release_ref(v21, 0xFu, v30, v31, v32, v33, v34, v35, v36, v37, v38);
  }
  if ( v29 )
  {
    v23 = "%s: Invalid p2p event";
    goto LABEL_21;
  }
  cfg80211_ready_on_channel(p2p_wdev, *((_QWORD *)a2 + 1), v28, a2[5], 3264);
  return wlan_objmgr_vdev_release_ref(v21, 0xFu, v30, v31, v32, v33, v34, v35, v36, v37, v38);
}
