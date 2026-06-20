__int64 __fastcall wlan_cfg80211_mc_cp_stats_get_peer_stats_ext(
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
  __int64 v11; // x8
  __int64 v12; // x22
  __int64 result; // x0
  __int64 v17; // x20
  __int64 v18; // x0
  __int64 v19; // x21
  __int64 v20; // x25
  __int64 v21; // x0
  __int64 v22; // x9
  int v23; // w10
  __int64 v24; // x23
  int v25; // w8
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w24
  unsigned int v44; // w0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w8
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  char v70[4]; // [xsp+4h] [xbp-2Ch] BYREF
  _QWORD v71[2]; // [xsp+8h] [xbp-28h] BYREF
  int v72; // [xsp+18h] [xbp-18h]
  int v73; // [xsp+1Ch] [xbp-14h]
  _QWORD v74[2]; // [xsp+20h] [xbp-10h] BYREF

  v74[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 152);
  v74[0] = 0;
  v70[0] = 0;
  if ( v11 )
  {
    v12 = *(_QWORD *)(v11 + 80);
    if ( v12 )
    {
      result = _qdf_mem_malloc(0xD8u, "wlan_cfg80211_mc_cp_stats_get_peer_stats_ext", 1604);
      if ( result )
      {
        v17 = result;
        v18 = osif_request_alloc(&wlan_cfg80211_mc_cp_stats_get_peer_stats_ext_params);
        if ( v18 )
        {
          v19 = v18;
          v20 = osif_request_cookie(v18);
          v21 = osif_request_priv(v19);
          v22 = *(_QWORD *)(a1 + 152);
          v23 = *(unsigned __int8 *)(a1 + 104);
          v71[0] = v20;
          v71[1] = get_peer_stats_cb;
          v24 = v21;
          v25 = *(unsigned __int8 *)(v22 + 40);
          v72 = v23;
          v73 = v25;
          qdf_mem_copy(v74, a2, 6u);
          v34 = ucfg_mc_cp_stats_send_stats_request(a1, 4u, (__int64)v71, v26, v27, v28, v29, v30, v31, v32, v33);
          if ( v34 )
          {
            v43 = v34;
            qdf_trace_msg(
              0x48u,
              2u,
              "%s: Failed to send stats request status: %d",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "wlan_cfg80211_mc_cp_stats_get_peer_stats_ext",
              v34);
            *a3 = qdf_status_to_os_return(v43);
          }
          else
          {
            v44 = osif_request_wait_for_response(v19);
            *a3 = v44;
            if ( v44 )
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: wait failed or timed out ret: %d",
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                "wlan_cfg80211_mc_cp_stats_get_peer_stats_ext",
                v44);
              ucfg_mc_cp_stats_reset_pending_req(v12, 4u, v71, v70, v53, v54, v55, v56, v57, v58, v59, v60);
            }
            else
            {
              if ( *(_QWORD *)(v24 + 160) )
              {
                v61 = *(_DWORD *)(v24 + 156);
                if ( v61 )
                {
                  *(_DWORD *)(v17 + 156) = v61;
                  *(_QWORD *)(v17 + 160) = *(_QWORD *)(v24 + 160);
                  *(_QWORD *)(v24 + 160) = 0;
                  osif_request_put(v19);
                  result = v17;
                  goto LABEL_11;
                }
              }
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: Invalid stats",
                v45,
                v46,
                v47,
                v48,
                v49,
                v50,
                v51,
                v52,
                "wlan_cfg80211_mc_cp_stats_get_peer_stats_ext");
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: Peer stats info ext %d:%pK",
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                "wlan_cfg80211_mc_cp_stats_get_peer_stats_ext",
                *(unsigned int *)(v24 + 156),
                *(_QWORD *)(v24 + 160));
              *a3 = -22;
            }
          }
          osif_request_put(v19);
          wlan_cfg80211_mc_cp_stats_free_stats_event(v17);
          goto LABEL_8;
        }
        _qdf_mem_free(v17);
        result = 0;
      }
      *a3 = -12;
      goto LABEL_11;
    }
  }
  qdf_trace_msg(
    0x48u,
    2u,
    "%s: Failed to get psoc",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_cfg80211_mc_cp_stats_get_peer_stats_ext");
LABEL_8:
  result = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
