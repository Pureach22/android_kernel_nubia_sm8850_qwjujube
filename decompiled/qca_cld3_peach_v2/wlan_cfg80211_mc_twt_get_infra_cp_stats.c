__int64 __fastcall wlan_cfg80211_mc_twt_get_infra_cp_stats(
        __int64 a1,
        int a2,
        const void *a3,
        int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x8
  __int64 v25; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  int v34; // w8
  __int64 result; // x0
  __int64 v36; // x26
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 v39; // x21
  __int64 v40; // x25
  __int64 v41; // x24
  __int64 v42; // x0
  unsigned int v43; // w9
  _DWORD *v44; // x27
  __int64 bsspeer; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x8
  __int64 v63; // x0
  __int64 v64; // x0
  unsigned int v65; // w0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  unsigned int v74; // w23
  unsigned int v75; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  unsigned int v84; // w23
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  unsigned int v93; // w0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // x8
  __int64 v103; // x0
  unsigned int v104; // w0
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  __int64 v113; // x0
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x10
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  __int64 v131; // x8
  __int64 v132; // x0
  unsigned int v133; // w0
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 v142; // [xsp+0h] [xbp-60h] BYREF
  __int64 v143; // [xsp+8h] [xbp-58h] BYREF
  __int64 v144; // [xsp+10h] [xbp-50h] BYREF
  __int64 v145; // [xsp+18h] [xbp-48h]
  __int64 v146; // [xsp+20h] [xbp-40h]
  __int64 v147; // [xsp+28h] [xbp-38h]
  __int64 v148; // [xsp+30h] [xbp-30h]
  __int64 v149; // [xsp+38h] [xbp-28h] BYREF
  __int64 v150; // [xsp+40h] [xbp-20h]
  __int64 (__fastcall *v151)(); // [xsp+48h] [xbp-18h]
  __int64 v152; // [xsp+50h] [xbp-10h]
  __int64 v153; // [xsp+58h] [xbp-8h]

  v153 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v151 = nullptr;
  v152 = 0;
  v149 = 0;
  v150 = 0;
  v147 = 0;
  v148 = 0;
  v145 = 0;
  v146 = 0;
  v143 = 0;
  v144 = 0;
  qdf_trace_msg(0x48u, 8u, "%s: Enter", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_cfg80211_mc_twt_get_infra_cp_stats", 0);
  v24 = *(_QWORD *)(a1 + 216);
  if ( v24 )
    v25 = *(_QWORD *)(v24 + 80);
  else
    v25 = 0;
  if ( (unsigned int)wlan_cp_stats_infra_cp_get_context(v25, &v143, &v142, v16, v17, v18, v19, v20, v21, v22, v23) )
  {
    v34 = -14;
LABEL_8:
    result = 0;
    *a4 = v34;
    goto LABEL_9;
  }
  if ( v143 )
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: another request already in progress",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "wlan_cfg80211_mc_twt_get_infra_cp_stats");
    v34 = -16;
    goto LABEL_8;
  }
  result = _qdf_mem_malloc(0x28u, "wlan_cfg80211_mc_twt_get_infra_cp_stats", 831);
  if ( !result )
  {
LABEL_18:
    *a4 = -12;
    goto LABEL_9;
  }
  v36 = result;
  v37 = _qdf_mem_malloc(0x38u, "wlan_cfg80211_mc_twt_get_infra_cp_stats", 837);
  *(_QWORD *)(v36 + 16) = v37;
  if ( !v37 )
  {
    _qdf_mem_free(v36);
    result = 0;
    goto LABEL_18;
  }
  v38 = osif_request_alloc(&wlan_cfg80211_mc_twt_get_infra_cp_stats_params);
  if ( !v38 )
  {
    *a4 = -12;
    _qdf_mem_free(*(_QWORD *)(v36 + 16));
    v64 = v36;
    if ( *(_QWORD *)(v36 + 24) )
    {
      _qdf_mem_free(*(_QWORD *)(v36 + 24));
      v64 = v36;
      *(_QWORD *)(v36 + 24) = 0;
    }
    _qdf_mem_free(v64);
    goto LABEL_39;
  }
  v39 = v38;
  v40 = osif_request_cookie(v38);
  v41 = osif_request_priv(v39);
  v42 = _qdf_mem_malloc(0x38u, "wlan_cfg80211_mc_twt_get_infra_cp_stats", 855);
  *(_QWORD *)(v41 + 16) = v42;
  if ( !v42 )
  {
    *a4 = -12;
LABEL_36:
    osif_request_put(v39);
    _qdf_mem_free(*(_QWORD *)(v36 + 16));
    v113 = v36;
    if ( *(_QWORD *)(v36 + 24) )
    {
      _qdf_mem_free(*(_QWORD *)(v36 + 24));
      v113 = v36;
      *(_QWORD *)(v36 + 24) = 0;
    }
    _qdf_mem_free(v113);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Exit",
      v114,
      v115,
      v116,
      v117,
      v118,
      v119,
      v120,
      v121,
      "wlan_cfg80211_mc_twt_get_infra_cp_stats");
LABEL_39:
    result = 0;
    goto LABEL_9;
  }
  v43 = *(unsigned __int8 *)(a1 + 168);
  v44 = (_DWORD *)v42;
  v144 = 3;
  v145 = v40;
  v151 = infra_cp_stats_response_cb;
  HIDWORD(v147) = 1;
  v148 = v43 | 0x100000000LL;
  HIDWORD(v146) = 0;
  qdf_mem_copy(&v149, a3, 6u);
  LODWORD(v150) = a2;
  HIDWORD(v146) = 0;
  bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x26u);
  if ( !bsspeer )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: peer is null",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "wlan_cfg80211_mc_twt_get_infra_cp_stats");
    *a4 = -22;
    goto LABEL_36;
  }
  wlan_objmgr_peer_release_ref(bsspeer, 0x26u, v46, v47, v48, v49, v50, v51, v52, v53);
  v62 = *(_QWORD *)(a1 + 216);
  if ( v62 )
    v63 = *(_QWORD *)(v62 + 80);
  else
    v63 = 0;
  v65 = ucfg_infra_cp_stats_register_resp_cb(v63, (__int64)&v144, v54, v55, v56, v57, v58, v59, v60, v61);
  if ( v65 )
  {
    v74 = v65;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to register resp callback: %d",
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      "wlan_cfg80211_mc_twt_get_infra_cp_stats",
      v65);
    *a4 = qdf_status_to_os_return(v74);
    goto LABEL_36;
  }
  v75 = ucfg_send_infra_cp_stats_request(a1, v66, v67, v68, v69, v70, v71, v72, v73);
  if ( v75 )
  {
    v84 = v75;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to send twt stats request status: %d",
      v76,
      v77,
      v78,
      v79,
      v80,
      v81,
      v82,
      v83,
      "wlan_cfg80211_mc_twt_get_infra_cp_stats",
      v75);
    *a4 = qdf_status_to_os_return(v84);
    goto LABEL_31;
  }
  v93 = osif_request_wait_for_response(v39);
  *a4 = v93;
  if ( v93 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: wait failed or timed out ret: %d",
      v94,
      v95,
      v96,
      v97,
      v98,
      v99,
      v100,
      v101,
      "wlan_cfg80211_mc_twt_get_infra_cp_stats",
      v93);
LABEL_31:
    v102 = *(_QWORD *)(a1 + 216);
    if ( v102 )
      v103 = *(_QWORD *)(v102 + 80);
    else
      v103 = 0;
    v104 = ucfg_infra_cp_stats_deregister_resp_cb(v103, v85, v86, v87, v88, v89, v90, v91, v92);
    if ( v104 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to deregister resp callback: %d",
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        v112,
        "wlan_cfg80211_mc_twt_get_infra_cp_stats",
        v104);
    goto LABEL_36;
  }
  v122 = *(_QWORD *)(v36 + 16);
  *(_DWORD *)(v36 + 12) = *(_DWORD *)(v41 + 12);
  *(_DWORD *)(v36 + 4) = *(_DWORD *)(v41 + 4);
  *(_DWORD *)(v122 + 8) = v44[2];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 12LL) = v44[3];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 16LL) = v44[4];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 20LL) = v44[5];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 24LL) = v44[6];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 28LL) = v44[7];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 32LL) = v44[8];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 36LL) = v44[9];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 40LL) = v44[10];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 44LL) = v44[11];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 48LL) = v44[12];
  *(_DWORD *)(*(_QWORD *)(v36 + 16) + 52LL) = v44[13];
  qdf_mem_copy((void *)(*(_QWORD *)(v36 + 16) + 1LL), a3, 6u);
  osif_request_put(v39);
  v131 = *(_QWORD *)(a1 + 216);
  if ( v131 )
    v132 = *(_QWORD *)(v131 + 80);
  else
    v132 = 0;
  v133 = ucfg_infra_cp_stats_deregister_resp_cb(v132, v123, v124, v125, v126, v127, v128, v129, v130);
  if ( v133 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to deregister resp callback: %d",
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      v141,
      "wlan_cfg80211_mc_twt_get_infra_cp_stats",
      v133);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Exit",
    v134,
    v135,
    v136,
    v137,
    v138,
    v139,
    v140,
    v141,
    "wlan_cfg80211_mc_twt_get_infra_cp_stats");
  result = v36;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
