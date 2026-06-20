__int64 __fastcall wlan_cfg80211_mc_cp_stats_get_peer_stats(
        __int64 a1,
        const void *a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 peer_stats_ext; // x19
  __int64 result; // x0
  __int64 v16; // x0
  __int64 v17; // x20
  __int64 v18; // x25
  __int64 v19; // x24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w22
  unsigned int v38; // w0
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  int v47; // w8
  _QWORD v48[3]; // [xsp+8h] [xbp-38h] BYREF
  _QWORD v49[4]; // [xsp+20h] [xbp-20h] BYREF

  v49[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v48[2] = 0;
  memset(v49, 0, 24);
  peer_stats_ext = wlan_cfg80211_mc_cp_stats_get_peer_stats_ext(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
  result = 0;
  if ( !*a3 )
  {
    v16 = osif_request_alloc(&wlan_cfg80211_mc_cp_stats_get_peer_stats_params);
    if ( v16 )
    {
      v17 = v16;
      v18 = osif_request_cookie(v16);
      v19 = osif_request_priv(v17);
      v48[0] = v18;
      v48[1] = get_station_adv_stats_cb;
      qdf_mem_copy(v49, a2, 6u);
      v28 = ucfg_mc_cp_stats_send_stats_request(a1, 1u, (__int64)v48, v20, v21, v22, v23, v24, v25, v26, v27);
      if ( v28 )
      {
        v37 = v28;
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Failed to send stats request status: %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "wlan_cfg80211_mc_cp_stats_get_peer_stats",
          v28);
        *a3 = qdf_status_to_os_return(v37);
LABEL_12:
        osif_request_put(v17);
        wlan_cfg80211_mc_cp_stats_free_stats_event(peer_stats_ext);
        result = 0;
        goto LABEL_13;
      }
      v38 = osif_request_wait_for_response(v17);
      *a3 = v38;
      if ( v38 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: wait failed or timed out ret: %d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "wlan_cfg80211_mc_cp_stats_get_peer_stats",
          v38);
        goto LABEL_12;
      }
      if ( !*(_QWORD *)(v19 + 56) || (v47 = *(_DWORD *)(v19 + 48)) == 0 )
      {
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: Invalid stats",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "wlan_cfg80211_mc_cp_stats_get_peer_stats");
        goto LABEL_12;
      }
      *(_DWORD *)(peer_stats_ext + 48) = v47;
      *(_QWORD *)(peer_stats_ext + 56) = *(_QWORD *)(v19 + 56);
      *(_QWORD *)(v19 + 56) = 0;
      osif_request_put(v17);
      result = peer_stats_ext;
    }
    else
    {
      wlan_cfg80211_mc_cp_stats_free_stats_event(peer_stats_ext);
      result = 0;
      *a3 = -12;
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
