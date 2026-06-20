void __fastcall wlan_cfg80211_tdls_get_all_peers(
        __int64 a1,
        __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  __int64 v12; // x23
  __int64 peer_rssi; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x22
  unsigned int v26; // w24
  __int64 v27; // x8
  unsigned int all_peers; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  unsigned int v45; // [xsp+Ch] [xbp-14h] BYREF
  int v46; // [xsp+10h] [xbp-10h] BYREF
  __int16 v47; // [xsp+14h] [xbp-Ch]
  __int64 v48; // [xsp+18h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 680);
  if ( v11 && (v12 = *(_QWORD *)(v11 + 16)) != 0 )
  {
    if ( *(_BYTE *)(v12 + 240) == 1 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: TDLS user cmd still in progress, reject this one",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_cfg80211_tdls_get_all_peers");
    }
    else
    {
      *(_BYTE *)(v12 + 240) = 1;
      v47 = -1;
      v45 = 0;
      v46 = -1;
      peer_rssi = wlan_cfg80211_mc_cp_stats_get_peer_rssi(a1, &v46, &v45);
      v25 = peer_rssi;
      if ( v45 || !peer_rssi )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: get peer rssi fail",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wlan_cfg80211_update_tdls_peers_rssi");
      }
      else if ( *(_DWORD *)(peer_rssi + 32) )
      {
        v26 = 0;
        do
        {
          v27 = *(_QWORD *)(v25 + 40) + 88LL * (int)v26;
          ucfg_tdls_set_rssi(
            a1,
            (unsigned __int8 *)(v27 + 9),
            *(_BYTE *)(v27 + 8),
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24);
          ++v26;
        }
        while ( v26 < *(_DWORD *)(v25 + 32) );
      }
      wlan_cfg80211_mc_cp_stats_free_stats_event(v25);
      *(_DWORD *)(v12 + 160) = 0;
      all_peers = ucfg_tdls_get_all_peers(a1, a2, a3);
      if ( all_peers )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: ucfg_tdls_get_all_peers failed err %d",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "wlan_cfg80211_tdls_get_all_peers",
          all_peers);
        scnprintf(a2, a3, "\nucfg_tdls_send_mgmt failed\n");
      }
      else
      {
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: Wait for tdls_user_cmd_comp. Timeout %u ms",
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          "wlan_cfg80211_tdls_get_all_peers",
          11000);
        if ( !wait_for_completion_timeout(v12 + 160, 2750) )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: TDLS user cmd get all peers timed out rc %ld",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "wlan_cfg80211_tdls_get_all_peers",
            0);
          scnprintf(a2, a3, "\nTDLS user cmd get all peers timed out\n");
        }
      }
      *(_BYTE *)(v12 + 240) = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: osif_tdls_vdev or osif_priv is NULL for the current vdev",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_cfg80211_tdls_get_all_peers");
  }
  _ReadStatusReg(SP_EL0);
}
