__int64 __fastcall wlan_cfg80211_mc_bmiss_get_infra_cp_stats(
        __int64 a1,
        const void *a2,
        int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  __int64 result; // x0
  __int64 v34; // x25
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x20
  __int64 v38; // x24
  __int64 v39; // x23
  __int64 v40; // x0
  unsigned int v41; // w9
  _DWORD *v42; // x26
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // x8
  __int64 v52; // x0
  unsigned int v53; // w0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned int v62; // w24
  unsigned int v63; // w0
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  unsigned int v72; // w24
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  unsigned int v81; // w0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  __int64 v90; // x8
  __int64 v91; // x0
  unsigned int v92; // w0
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x11
  int v111; // w10
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  __int64 v120; // x8
  __int64 v121; // x0
  unsigned int v122; // w0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  __int64 v131; // [xsp+0h] [xbp-60h] BYREF
  __int64 v132; // [xsp+8h] [xbp-58h] BYREF
  __int64 v133; // [xsp+10h] [xbp-50h] BYREF
  __int64 v134; // [xsp+18h] [xbp-48h]
  __int64 v135; // [xsp+20h] [xbp-40h]
  __int64 v136; // [xsp+28h] [xbp-38h]
  __int64 v137; // [xsp+30h] [xbp-30h]
  _QWORD v138[2]; // [xsp+38h] [xbp-28h] BYREF
  __int64 (__fastcall *v139)(); // [xsp+48h] [xbp-18h]
  __int64 v140; // [xsp+50h] [xbp-10h]
  __int64 v141; // [xsp+58h] [xbp-8h]

  v141 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v139 = nullptr;
  v140 = 0;
  v138[0] = 0;
  v138[1] = 0;
  v136 = 0;
  v137 = 0;
  v134 = 0;
  v135 = 0;
  v132 = 0;
  v133 = 0;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Enter",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_cfg80211_mc_bmiss_get_infra_cp_stats",
    0);
  v22 = *(_QWORD *)(a1 + 152);
  if ( v22 )
    v23 = *(_QWORD *)(v22 + 80);
  else
    v23 = 0;
  if ( (unsigned int)wlan_cp_stats_infra_cp_get_context(v23, &v132, &v131, v14, v15, v16, v17, v18, v19, v20, v21) )
  {
    v32 = -14;
LABEL_8:
    result = 0;
LABEL_9:
    *a3 = v32;
    goto LABEL_10;
  }
  if ( v132 )
  {
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: another request already in progress",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "wlan_cfg80211_mc_bmiss_get_infra_cp_stats");
    v32 = -16;
    goto LABEL_8;
  }
  result = _qdf_mem_malloc(0x28u, "wlan_cfg80211_mc_bmiss_get_infra_cp_stats", 1869);
  if ( !result )
  {
LABEL_19:
    v32 = -12;
    goto LABEL_9;
  }
  v34 = result;
  v35 = _qdf_mem_malloc(0x84u, "wlan_cfg80211_mc_bmiss_get_infra_cp_stats", 1876);
  *(_QWORD *)(v34 + 24) = v35;
  if ( !v35 )
  {
LABEL_18:
    _qdf_mem_free(v34);
    result = 0;
    goto LABEL_19;
  }
  v36 = osif_request_alloc(&wlan_cfg80211_mc_bmiss_get_infra_cp_stats_params);
  if ( !v36
    || (v37 = v36,
        v38 = osif_request_cookie(v36),
        v39 = osif_request_priv(v37),
        v40 = _qdf_mem_malloc(0x84u, "wlan_cfg80211_mc_bmiss_get_infra_cp_stats", 1895),
        (*(_QWORD *)(v39 + 24) = v40) == 0) )
  {
    _qdf_mem_free(*(_QWORD *)(v34 + 24));
    goto LABEL_18;
  }
  v41 = *(unsigned __int8 *)(a1 + 104);
  v42 = (_DWORD *)v40;
  v133 = 4;
  v134 = v38;
  v139 = infra_cp_stats_bmiss_response_cb;
  v137 = v41 | 0x100000000LL;
  HIDWORD(v136) = 1;
  HIDWORD(v135) = 0;
  qdf_mem_copy(v138, a2, 6u);
  v51 = *(_QWORD *)(a1 + 152);
  if ( v51 )
    v52 = *(_QWORD *)(v51 + 80);
  else
    v52 = 0;
  v53 = ucfg_infra_cp_stats_register_resp_cb(v52, (__int64)&v133, v43, v44, v45, v46, v47, v48, v49, v50);
  if ( v53 )
  {
    v62 = v53;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to register resp callback: %d",
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      v61,
      "wlan_cfg80211_mc_bmiss_get_infra_cp_stats",
      v53);
    *a3 = qdf_status_to_os_return(v62);
LABEL_32:
    osif_request_put(v37);
    _qdf_mem_free(*(_QWORD *)(v34 + 16));
    v101 = v34;
    if ( *(_QWORD *)(v34 + 24) )
    {
      _qdf_mem_free(*(_QWORD *)(v34 + 24));
      v101 = v34;
      *(_QWORD *)(v34 + 24) = 0;
    }
    _qdf_mem_free(v101);
    qdf_trace_msg(
      0x48u,
      8u,
      "%s: Exit",
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      v109,
      "wlan_cfg80211_mc_bmiss_get_infra_cp_stats");
    result = 0;
    goto LABEL_10;
  }
  v63 = ucfg_send_infra_cp_stats_request(a1, v54, v55, v56, v57, v58, v59, v60, v61);
  if ( v63 )
  {
    v72 = v63;
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: Failed to send bmiss stats request status: %d",
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      v70,
      v71,
      "wlan_cfg80211_mc_bmiss_get_infra_cp_stats",
      v63);
    *a3 = qdf_status_to_os_return(v72);
    goto LABEL_27;
  }
  v81 = osif_request_wait_for_response(v37);
  *a3 = v81;
  if ( v81 )
  {
    qdf_trace_msg(
      0x48u,
      2u,
      "%s: wait failed or timed out ret: %d",
      v82,
      v83,
      v84,
      v85,
      v86,
      v87,
      v88,
      v89,
      "wlan_cfg80211_mc_bmiss_get_infra_cp_stats",
      v81);
LABEL_27:
    v90 = *(_QWORD *)(a1 + 152);
    if ( v90 )
      v91 = *(_QWORD *)(v90 + 80);
    else
      v91 = 0;
    v92 = ucfg_infra_cp_stats_deregister_resp_cb(v91, v73, v74, v75, v76, v77, v78, v79, v80);
    if ( v92 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to deregister resp callback: %d",
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        "wlan_cfg80211_mc_bmiss_get_infra_cp_stats",
        v92);
    goto LABEL_32;
  }
  v110 = *(_QWORD *)(v34 + 24);
  *(_DWORD *)(v34 + 4) = *(_DWORD *)(v39 + 4);
  v111 = v42[2];
  *(_DWORD *)(v110 + 8) = v111;
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 8LL) = v111;
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 12LL) = v42[3];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 16LL) = v42[4];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 20LL) = v42[5];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 24LL) = v42[6];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 28LL) = v42[7];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 32LL) = v42[8];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 36LL) = v42[9];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 40LL) = v42[10];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 44LL) = v42[11];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 48LL) = v42[12];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 52LL) = v42[13];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 56LL) = v42[14];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 60LL) = v42[15];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 64LL) = v42[16];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 68LL) = v42[17];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 72LL) = v42[18];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 76LL) = v42[19];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 80LL) = v42[20];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 84LL) = v42[21];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 88LL) = v42[22];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 92LL) = v42[23];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 96LL) = v42[24];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 104LL) = v42[26];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 108LL) = v42[27];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 112LL) = v42[28];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 116LL) = v42[29];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 120LL) = v42[30];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 124LL) = v42[31];
  *(_DWORD *)(*(_QWORD *)(v34 + 24) + 128LL) = v42[32];
  qdf_mem_copy((void *)(*(_QWORD *)(v34 + 24) + 1LL), a2, 6u);
  osif_request_put(v37);
  v120 = *(_QWORD *)(a1 + 152);
  if ( v120 )
    v121 = *(_QWORD *)(v120 + 80);
  else
    v121 = 0;
  v122 = ucfg_infra_cp_stats_deregister_resp_cb(v121, v112, v113, v114, v115, v116, v117, v118, v119);
  if ( v122 )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to deregister resp callback: %d",
      v123,
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      "wlan_cfg80211_mc_bmiss_get_infra_cp_stats",
      v122);
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Exit",
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    "wlan_cfg80211_mc_bmiss_get_infra_cp_stats");
  result = v34;
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}
