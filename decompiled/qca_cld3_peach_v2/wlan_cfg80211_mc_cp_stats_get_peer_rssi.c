__int64 __fastcall wlan_cfg80211_mc_cp_stats_get_peer_rssi(__int64 a1, const void *a2, unsigned int *a3)
{
  __int64 result; // x0
  __int64 v7; // x19
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x21
  __int64 v18; // x25
  __int64 v19; // x0
  __int64 v20; // x9
  int v21; // w10
  __int64 v22; // x24
  int v23; // w8
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  unsigned int v41; // w22
  unsigned int v42; // w0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x4
  _QWORD v52[2]; // [xsp+8h] [xbp-38h] BYREF
  int v53; // [xsp+18h] [xbp-28h]
  int v54; // [xsp+1Ch] [xbp-24h]
  _QWORD v55[4]; // [xsp+20h] [xbp-20h] BYREF

  v55[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v55, 0, 24);
  result = _qdf_mem_malloc(0xD8u, "wlan_cfg80211_mc_cp_stats_get_peer_rssi", 497);
  if ( result )
  {
    v7 = result;
    v8 = osif_request_alloc(&wlan_cfg80211_mc_cp_stats_get_peer_rssi_params);
    if ( !v8 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Request allocation failure, return cached value",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "wlan_cfg80211_mc_cp_stats_get_peer_rssi");
      *a3 = -12;
      _qdf_mem_free(v7);
LABEL_14:
      result = 0;
      goto LABEL_15;
    }
    v17 = v8;
    v18 = osif_request_cookie(v8);
    v19 = osif_request_priv(v17);
    v20 = *(_QWORD *)(a1 + 216);
    v21 = *(unsigned __int8 *)(a1 + 168);
    v52[0] = v18;
    v52[1] = get_peer_rssi_cb;
    v22 = v19;
    v23 = *(unsigned __int8 *)(v20 + 40);
    v53 = v21;
    v54 = v23;
    qdf_mem_copy(v55, a2, 6u);
    v32 = ucfg_mc_cp_stats_send_stats_request(a1, 2u, (__int64)v52, v24, v25, v26, v27, v28, v29, v30, v31);
    if ( v32 )
    {
      v41 = v32;
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: stats req failed: %d",
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        "wlan_cfg80211_mc_cp_stats_get_peer_rssi",
        v32);
      *a3 = qdf_status_to_os_return(v41);
LABEL_13:
      osif_request_put(v17);
      wlan_cfg80211_mc_cp_stats_free_stats_event(v7);
      goto LABEL_14;
    }
    v42 = osif_request_wait_for_response(v17);
    *a3 = v42;
    if ( v42 )
    {
      qdf_trace_msg(
        0x48u,
        8u,
        "%s: wait failed or timed out ret: %d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "wlan_cfg80211_mc_cp_stats_get_peer_rssi",
        v42);
      goto LABEL_13;
    }
    v51 = *(unsigned int *)(v22 + 32);
    if ( !*(_QWORD *)(v22 + 40) || !(_DWORD)v51 )
    {
      qdf_trace_msg(
        0x48u,
        2u,
        "%s: Invalid peer stats, count %d, data %pK",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        "wlan_cfg80211_mc_cp_stats_get_peer_rssi",
        v51);
      *a3 = -22;
      goto LABEL_13;
    }
    *(_DWORD *)(v7 + 32) = v51;
    *(_QWORD *)(v7 + 40) = *(_QWORD *)(v22 + 40);
    *(_QWORD *)(v22 + 40) = 0;
    osif_request_put(v17);
    result = v7;
  }
  else
  {
    *a3 = -12;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
