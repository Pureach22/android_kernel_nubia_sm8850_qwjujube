__int64 __fastcall target_if_mc_cp_stats_peer_stats_info_event_handler(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 psoc_from_scn_hdl; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x28
  __int64 v21; // x8
  __int64 v22; // x22
  __int64 v23; // x21
  __int64 v24; // x0
  unsigned int peer_stats_param; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w20
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 result; // x0
  const char *v44; // x2
  unsigned int v45; // w27
  __int64 v46; // x0
  __int64 v47; // x19
  unsigned int v48; // w23
  unsigned int v49; // w24
  unsigned int v50; // w25
  __int64 v51; // x26
  unsigned int v52; // w0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  int v61; // w9
  int v62; // w10
  int v63; // w9
  int v64; // w8
  int v65; // w11
  unsigned int v66; // w0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int v75; // w0
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  _DWORD *v84; // x8
  int v85; // w21
  __int64 *v86; // x22
  __int64 v87; // x0
  int v88; // w21
  __int64 *v89; // x22
  __int64 v90; // x0
  int v91; // w21
  __int64 *v92; // x22
  __int64 v93; // x0
  _QWORD v94[19]; // [xsp+8h] [xbp-1B8h] BYREF
  __int64 v95; // [xsp+A0h] [xbp-120h]
  __int64 v96; // [xsp+A8h] [xbp-118h]
  __int64 v97; // [xsp+B0h] [xbp-110h]
  __int64 v98; // [xsp+B8h] [xbp-108h]
  __int64 v99; // [xsp+C0h] [xbp-100h]
  __int64 v100; // [xsp+C8h] [xbp-F8h]
  __int64 v101; // [xsp+D0h] [xbp-F0h]
  __int64 v102; // [xsp+D8h] [xbp-E8h]
  _QWORD v103[7]; // [xsp+E0h] [xbp-E0h] BYREF
  __int64 v104; // [xsp+118h] [xbp-A8h]
  __int64 v105; // [xsp+120h] [xbp-A0h]
  __int64 v106; // [xsp+128h] [xbp-98h] BYREF
  __int64 v107; // [xsp+130h] [xbp-90h]
  __int64 v108; // [xsp+138h] [xbp-88h]
  __int64 v109; // [xsp+140h] [xbp-80h]
  __int64 v110; // [xsp+148h] [xbp-78h]
  __int64 v111; // [xsp+150h] [xbp-70h]
  __int64 v112; // [xsp+158h] [xbp-68h]
  __int64 v113; // [xsp+160h] [xbp-60h]
  __int64 v114; // [xsp+168h] [xbp-58h]
  __int64 v115; // [xsp+170h] [xbp-50h]
  __int64 v116; // [xsp+178h] [xbp-48h]
  __int64 v117; // [xsp+180h] [xbp-40h]
  __int64 v118; // [xsp+188h] [xbp-38h]
  __int64 v119; // [xsp+190h] [xbp-30h]
  __int64 v120; // [xsp+198h] [xbp-28h]
  __int64 v121; // [xsp+1A0h] [xbp-20h]
  __int64 v122; // [xsp+1A8h] [xbp-18h]
  __int64 v123; // [xsp+1B0h] [xbp-10h]

  v123 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v101 = 0;
  v102 = 0;
  v99 = 0;
  v100 = 0;
  v97 = 0;
  v98 = 0;
  v95 = 0;
  v96 = 0;
  memset(v94, 0, sizeof(v94));
  if ( !a1 || !a2 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: scn: 0x%pK, data: 0x%pK",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "target_if_mc_cp_stats_peer_stats_info_event_handler",
      a1,
      a2);
LABEL_18:
    result = 4294967274LL;
    goto LABEL_19;
  }
  psoc_from_scn_hdl = target_if_get_psoc_from_scn_hdl(a1);
  if ( !psoc_from_scn_hdl )
  {
    v44 = "%s: null psoc";
LABEL_17:
    qdf_trace_msg(
      0x62u,
      2u,
      v44,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_mc_cp_stats_peer_stats_info_event_handler");
    goto LABEL_18;
  }
  v20 = *(_QWORD *)(psoc_from_scn_hdl + 2136);
  if ( !v20 )
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: rx_ops is NULL",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_cp_stats_get_rx_ops");
    goto LABEL_15;
  }
  if ( !*(_QWORD *)(v20 + 176) )
  {
LABEL_15:
    v44 = "%s: callback not registered";
    goto LABEL_17;
  }
  v21 = *(_QWORD *)(psoc_from_scn_hdl + 2800);
  if ( !v21 || (v22 = *(_QWORD *)(v21 + 16)) == 0 )
  {
    v44 = "%s: wmi_handle is null";
    goto LABEL_17;
  }
  v23 = psoc_from_scn_hdl;
  v24 = *(_QWORD *)(v21 + 16);
  v104 = 0;
  v105 = 0;
  memset(v103, 0, sizeof(v103));
  v121 = 0;
  v122 = 0;
  v119 = 0;
  v120 = 0;
  v117 = 0;
  v118 = 0;
  v115 = 0;
  v116 = 0;
  v113 = 0;
  v114 = 0;
  v111 = 0;
  v112 = 0;
  v109 = 0;
  v110 = 0;
  v107 = 0;
  v108 = 0;
  v106 = 0;
  peer_stats_param = wmi_extract_peer_stats_param(v24, a2, v103);
  if ( peer_stats_param )
  {
    v34 = peer_stats_param;
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: peer stats param extract failed: %d",
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      "target_if_cp_stats_extract_peer_stats_event");
  }
  else
  {
    v45 = v104;
    if ( !(_DWORD)v104 )
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: num_peer_stats_info_ext is 0",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "target_if_cp_stats_extract_peer_stats_event");
LABEL_32:
      v84 = *(_DWORD **)(v20 + 176);
      if ( *(v84 - 1) != -165074511 )
        __break(0x8228u);
      v34 = ((__int64 (__fastcall *)(__int64, _QWORD *))v84)(v23, v94);
      goto LABEL_11;
    }
    HIDWORD(v95) = v104;
    v46 = _qdf_mem_malloc((unsigned int)(136 * v104), "target_if_cp_stats_extract_peer_stats_event", 1296);
    v96 = v46;
    if ( v46 )
    {
      v47 = v46;
      v48 = 0;
      v49 = 0;
      v50 = 0;
      v51 = v46;
      while ( 1 )
      {
        v52 = wmi_extract_peer_stats_info(v22, a2, v50, &v106);
        if ( v52 )
          break;
        qdf_mem_copy((void *)v51, &v106, 6u);
        *(_DWORD *)(v51 + 8) = v108;
        *(_QWORD *)(v51 + 16) = v107;
        *(_DWORD *)(v51 + 24) = v110;
        *(_QWORD *)(v51 + 32) = v109;
        *(_DWORD *)(v51 + 40) = HIDWORD(v110);
        *(_DWORD *)(v51 + 44) = v111;
        v61 = v114;
        *(_DWORD *)(v51 + 128) = v122;
        v62 = HIDWORD(v122);
        *(_DWORD *)(v51 + 48) = v61;
        v63 = HIDWORD(v111);
        v64 = HIDWORD(v113);
        *(_DWORD *)(v51 + 132) = v62;
        *(_DWORD *)(v51 + 52) = v64;
        v65 = v112;
        *(_DWORD *)(v51 + 56) = HIDWORD(v112);
        *(_DWORD *)(v51 + 60) = v63;
        *(_DWORD *)(v51 + 64) = v113;
        *(_DWORD *)(v51 + 68) = v65;
        *(_DWORD *)(v51 + 72) = HIDWORD(v114);
        *(_QWORD *)(v51 + 76) = v115;
        *(_QWORD *)(v51 + 84) = v116;
        *(_QWORD *)(v51 + 92) = v117;
        *(_DWORD *)(v51 + 100) = v118;
        if ( HIDWORD(v118) )
        {
          *(_DWORD *)(v51 + 104) = HIDWORD(v118);
          v66 = wmi_extract_peer_tx_pkt_per_mcs(v22, a2, v49, &v106);
          if ( v66 )
          {
            v34 = v66;
            qdf_trace_msg(
              0x31u,
              2u,
              "%s: tx rate count extract failed",
              v67,
              v68,
              v69,
              v70,
              v71,
              v72,
              v73,
              v74,
              "target_if_cp_stats_extract_peer_stats_event");
            v88 = 0;
            v89 = (__int64 *)(v47 + 120);
            do
            {
              _qdf_mem_free(*(v89 - 1));
              v90 = *v89;
              *(v89 - 1) = 0;
              _qdf_mem_free(v90);
              ++v88;
              *v89 = 0;
              v89 += 17;
            }
            while ( v45 > (unsigned __int16)v88 );
            goto LABEL_44;
          }
          v49 += *(_DWORD *)(v51 + 104);
          *(_QWORD *)(v51 + 112) = v120;
          v120 = 0;
        }
        if ( (_DWORD)v119 )
        {
          *(_DWORD *)(v51 + 108) = v119;
          v75 = wmi_extract_peer_rx_pkt_per_mcs(v22, a2, v48, &v106);
          if ( v75 )
          {
            v34 = v75;
            qdf_trace_msg(
              0x31u,
              2u,
              "%s: rx rate count extract failed",
              v76,
              v77,
              v78,
              v79,
              v80,
              v81,
              v82,
              v83,
              "target_if_cp_stats_extract_peer_stats_event");
            v91 = 0;
            v92 = (__int64 *)(v47 + 120);
            do
            {
              _qdf_mem_free(*(v92 - 1));
              v93 = *v92;
              *(v92 - 1) = 0;
              _qdf_mem_free(v93);
              ++v91;
              *v92 = 0;
              v92 += 17;
            }
            while ( v45 > (unsigned __int16)v91 );
            goto LABEL_44;
          }
          v48 += *(_DWORD *)(v51 + 108);
          *(_QWORD *)(v51 + 120) = v121;
          v121 = 0;
        }
        ++v50;
        v51 += 136;
        if ( v50 >= v45 )
          goto LABEL_32;
      }
      v34 = v52;
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: peer stats info extract failed: %d",
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        v60,
        "target_if_cp_stats_extract_peer_stats_event");
      v85 = 0;
      v86 = (__int64 *)(v47 + 120);
      do
      {
        _qdf_mem_free(*(v86 - 1));
        v87 = *v86;
        *(v86 - 1) = 0;
        _qdf_mem_free(v87);
        ++v85;
        *v86 = 0;
        v86 += 17;
      }
      while ( v45 > (unsigned __int16)v85 );
LABEL_44:
      _qdf_mem_free(v47);
      v96 = 0;
      HIDWORD(v95) = 0;
    }
    else
    {
      HIDWORD(v95) = 0;
      v34 = 2;
    }
  }
  qdf_trace_msg(
    0x62u,
    2u,
    "%s: extract event failed",
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    "target_if_mc_cp_stats_peer_stats_info_event_handler");
LABEL_11:
  target_if_cp_stats_free_stats_event(v94);
  result = qdf_status_to_os_return(v34);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return result;
}
