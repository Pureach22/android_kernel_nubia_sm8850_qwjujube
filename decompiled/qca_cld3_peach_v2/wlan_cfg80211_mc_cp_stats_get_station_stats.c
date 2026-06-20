__int64 __fastcall wlan_cfg80211_mc_cp_stats_get_station_stats(
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
  __int64 result; // x0
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 v15; // x20
  __int64 v16; // x24
  __int64 v17; // x0
  __int64 v18; // x9
  int v19; // w10
  __int64 v20; // x22
  int v21; // w8
  __int64 bsspeer; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x24
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  unsigned int v57; // w23
  unsigned int v58; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x9
  __int64 v76; // x9
  __int64 v77; // x9
  __int64 v78; // x9
  __int64 v79; // x10
  __int64 v80; // x11
  int v81; // w9
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  _QWORD v98[2]; // [xsp+8h] [xbp-38h] BYREF
  int v99; // [xsp+18h] [xbp-28h]
  int v100; // [xsp+1Ch] [xbp-24h]
  _QWORD v101[4]; // [xsp+20h] [xbp-20h] BYREF

  v101[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v101, 0, 24);
  qdf_trace_msg(0x48u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "wlan_cfg80211_mc_cp_stats_get_station_stats");
  result = _qdf_mem_malloc(0xD8u, "wlan_cfg80211_mc_cp_stats_get_station_stats", 1119);
  if ( !result )
    goto LABEL_7;
  v13 = result;
  v14 = osif_request_alloc(&wlan_cfg80211_mc_cp_stats_get_station_stats_params);
  if ( !v14 )
  {
    _qdf_mem_free(v13);
    result = 0;
LABEL_7:
    *a2 = -12;
    goto LABEL_13;
  }
  v15 = v14;
  v16 = osif_request_cookie(v14);
  v17 = osif_request_priv(v15);
  v18 = *(_QWORD *)(a1 + 216);
  v19 = *(unsigned __int8 *)(a1 + 168);
  v98[0] = v16;
  v98[1] = get_station_stats_cb;
  v20 = v17;
  v21 = *(unsigned __int8 *)(v18 + 40);
  v99 = v19;
  v100 = v21;
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x26u);
  if ( !bsspeer )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: peer is null",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "wlan_cfg80211_mc_cp_stats_get_station_stats");
LABEL_9:
    *a2 = -22;
    goto LABEL_12;
  }
  v31 = bsspeer;
  qdf_mem_copy(v101, (const void *)(bsspeer + 48), 6u);
  wlan_objmgr_peer_release_ref(v31, 0x26u, v32, v33, v34, v35, v36, v37, v38, v39);
  v48 = ucfg_mc_cp_stats_send_stats_request(a1, 1u, (__int64)v98, v40, v41, v42, v43, v44, v45, v46, v47);
  if ( v48 )
  {
    v57 = v48;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to send stats request status: %d",
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      "wlan_cfg80211_mc_cp_stats_get_station_stats",
      v48);
    *a2 = qdf_status_to_os_return(v57);
LABEL_12:
    osif_request_put(v15);
    wlan_cfg80211_mc_cp_stats_free_stats_event(v13);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Exit",
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      "wlan_cfg80211_mc_cp_stats_get_station_stats");
    result = 0;
    goto LABEL_13;
  }
  v58 = osif_request_wait_for_response(v15);
  *a2 = v58;
  if ( v58 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: wait failed or timed out ret: %d",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "wlan_cfg80211_mc_cp_stats_get_station_stats",
      v58);
    goto LABEL_12;
  }
  if ( !*(_QWORD *)(v20 + 96) || !*(_QWORD *)(v20 + 128) || !*(_DWORD *)(v20 + 88) || !*(_DWORD *)(v20 + 120) )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Invalid stats",
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      "wlan_cfg80211_mc_cp_stats_get_station_stats");
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: summary %d:%pK, rssi %d:%pK",
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      v96,
      v97,
      "wlan_cfg80211_mc_cp_stats_get_station_stats",
      *(unsigned int *)(v20 + 88),
      *(_QWORD *)(v20 + 96),
      *(unsigned int *)(v20 + 120),
      *(_QWORD *)(v20 + 128));
    goto LABEL_9;
  }
  *(_DWORD *)(v13 + 136) = *(_DWORD *)(v20 + 136);
  *(_DWORD *)(v13 + 140) = *(_DWORD *)(v20 + 140);
  *(_DWORD *)(v13 + 144) = *(_DWORD *)(v20 + 144);
  *(_DWORD *)(v13 + 88) = *(_DWORD *)(v20 + 88);
  *(_DWORD *)(v13 + 120) = *(_DWORD *)(v20 + 120);
  *(_QWORD *)(v13 + 96) = *(_QWORD *)(v20 + 96);
  v75 = *(_QWORD *)(v20 + 128);
  *(_QWORD *)(v20 + 96) = 0;
  *(_QWORD *)(v13 + 128) = v75;
  LODWORD(v75) = *(_DWORD *)(v20 + 48);
  *(_QWORD *)(v20 + 128) = 0;
  *(_DWORD *)(v13 + 48) = v75;
  v76 = *(_QWORD *)(v20 + 56);
  if ( v76 )
    *(_QWORD *)(v13 + 56) = v76;
  v77 = *(_QWORD *)(v20 + 8);
  *(_QWORD *)(v20 + 56) = 0;
  if ( v77 )
    *(_QWORD *)(v13 + 8) = v77;
  v78 = *(_QWORD *)(v20 + 192);
  *(_QWORD *)(v20 + 8) = 0;
  if ( v78 )
    *(_QWORD *)(v13 + 192) = v78;
  v80 = *(_QWORD *)(v20 + 168);
  v79 = *(_QWORD *)(v20 + 176);
  v81 = *(_DWORD *)(v20 + 184);
  *(_QWORD *)(v20 + 192) = 0;
  *(_DWORD *)(v13 + 184) = v81;
  *(_QWORD *)(v13 + 168) = v80;
  *(_QWORD *)(v13 + 176) = v79;
  *(_DWORD *)(v13 + 200) = *(_DWORD *)(v20 + 200);
  *(_QWORD *)(v13 + 208) = *(_QWORD *)(v20 + 208);
  *(_QWORD *)(v20 + 208) = 0;
  osif_request_put(v15);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Exit",
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v89,
    "wlan_cfg80211_mc_cp_stats_get_station_stats");
  result = v13;
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}
