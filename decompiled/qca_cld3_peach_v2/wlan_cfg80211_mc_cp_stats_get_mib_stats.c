__int64 __fastcall wlan_cfg80211_mc_cp_stats_get_mib_stats(__int64 a1, unsigned int *a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  __int64 v6; // x0
  __int64 v7; // x21
  __int64 v8; // x24
  __int64 v9; // x0
  __int64 v10; // x9
  unsigned int v11; // w10
  __int64 v12; // x23
  unsigned int v13; // w8
  __int64 bsspeer; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x25
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x6
  __int64 v33; // x7
  int v34; // w8
  int v35; // w9
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w22
  unsigned int v62; // w0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  __int64 v71; // x4
  _QWORD v72[2]; // [xsp+18h] [xbp-38h] BYREF
  unsigned int v73; // [xsp+28h] [xbp-28h]
  unsigned int v74; // [xsp+2Ch] [xbp-24h]
  _QWORD v75[4]; // [xsp+30h] [xbp-20h] BYREF

  v75[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v75, 0, 24);
  result = _qdf_mem_malloc(0xD8u, "wlan_cfg80211_mc_cp_stats_get_mib_stats", 1351);
  if ( result )
  {
    v5 = result;
    v6 = osif_request_alloc(&wlan_cfg80211_mc_cp_stats_get_mib_stats_params);
    if ( v6 )
    {
      v7 = v6;
      v8 = osif_request_cookie(v6);
      v9 = osif_request_priv(v7);
      v10 = *(_QWORD *)(a1 + 216);
      v11 = *(unsigned __int8 *)(a1 + 168);
      v72[0] = v8;
      v72[1] = get_mib_stats_cb;
      v12 = v9;
      v13 = *(unsigned __int8 *)(v10 + 40);
      v73 = v11;
      v74 = v13;
      bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x26u);
      if ( bsspeer )
      {
        v23 = bsspeer;
        qdf_mem_copy(v75, (const void *)(bsspeer + 48), 6u);
        if ( v75 )
          v32 = LOBYTE(v75[0]);
        else
          v32 = 0;
        if ( v75 )
          v33 = BYTE1(v75[0]);
        else
          v33 = 0;
        if ( v75 )
          v34 = BYTE2(v75[0]);
        else
          v34 = 0;
        if ( v75 )
          v35 = BYTE5(v75[0]);
        else
          v35 = 0;
        qdf_trace_msg(
          0x48u,
          8u,
          "%s: vdev id %d, pdev id %d, peer %02x:%02x:%02x:**:**:%02x",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wlan_cfg80211_mc_cp_stats_get_mib_stats",
          v73,
          v74,
          v32,
          v33,
          v34,
          v35);
        wlan_objmgr_peer_release_ref(v23, 0x26u, v36, v37, v38, v39, v40, v41, v42, v43);
        v52 = ucfg_mc_cp_stats_send_stats_request(a1, 3u, (__int64)v72, v44, v45, v46, v47, v48, v49, v50, v51);
        if ( v52 )
        {
          v61 = v52;
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: Failed to send stats request status: %d",
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            "wlan_cfg80211_mc_cp_stats_get_mib_stats",
            v52);
          *a2 = qdf_status_to_os_return(v61);
LABEL_24:
          osif_request_put(v7);
          wlan_cfg80211_mc_cp_stats_free_stats_event(v5);
          result = 0;
          goto LABEL_25;
        }
        v62 = osif_request_wait_for_response(v7);
        *a2 = v62;
        if ( v62 )
        {
          qdf_trace_msg(
            0x48u,
            2u,
            "%s: wait failed or timed out ret: %d",
            v63,
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            "wlan_cfg80211_mc_cp_stats_get_mib_stats",
            v62);
          goto LABEL_24;
        }
        v71 = *(unsigned int *)(v12 + 104);
        if ( *(_QWORD *)(v12 + 112) && (_DWORD)v71 )
        {
          *(_DWORD *)(v5 + 104) = v71;
          *(_QWORD *)(v5 + 112) = *(_QWORD *)(v12 + 112);
          *(_QWORD *)(v12 + 112) = 0;
          osif_request_put(v7);
          result = v5;
          goto LABEL_25;
        }
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: Invalid mib stats %d:%pK",
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          v69,
          v70,
          "wlan_cfg80211_mc_cp_stats_get_mib_stats",
          v71);
      }
      else
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: peer is null",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "wlan_cfg80211_mc_cp_stats_get_mib_stats");
      }
      *a2 = -22;
      goto LABEL_24;
    }
    _qdf_mem_free(v5);
    result = 0;
  }
  *a2 = -12;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
