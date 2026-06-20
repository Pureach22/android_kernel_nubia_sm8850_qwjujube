__int64 __fastcall sme_rrm_msg_processor(
        _QWORD *a1,
        unsigned __int16 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w21
  _QWORD *v14; // x23
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x22
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // x21
  unsigned __int16 *v42; // x22
  unsigned int v43; // w8
  unsigned int v44; // w9
  unsigned __int16 v45; // w8
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  unsigned __int64 v54; // x20
  __int64 v55; // x21
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x4
  __int64 v65; // x5
  __int64 v66; // x6
  __int64 v67; // x7
  unsigned __int8 v68; // w25
  __int64 v69; // x4
  __int64 v70; // x5
  __int64 v71; // x6
  __int64 v72; // x7
  __int64 v73; // x0
  __int64 v74; // x26
  void *v75; // x0
  unsigned __int8 *v76; // x27
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x4
  __int64 v86; // x5
  __int64 v87; // x6
  __int64 v88; // x7
  __int64 v89; // x8
  int v90; // w8
  int v91; // w28
  int v92; // w9
  int v93; // w8
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  __int64 v110; // x0
  __int64 v111; // x1
  __int64 v112; // x0
  __int64 v113; // x0
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x22
  __int64 v123; // x23
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  unsigned int *v140; // x8
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  double report_xmit_ind; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  bool v157; // zf
  int v158; // w20
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  _DWORD *v167; // x8
  __int64 v168; // x0
  int scan_id; // w0
  int v171; // w9
  int v172; // w10
  int v173; // w11
  int v174; // w9
  unsigned int v175; // w25
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  unsigned int v184; // w0
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  unsigned int v193; // w24
  int v194; // w2
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  double v203; // d0
  double v204; // d1
  double v205; // d2
  double v206; // d3
  double v207; // d4
  double v208; // d5
  double v209; // d6
  double v210; // d7
  unsigned int *v211; // x8
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  unsigned __int16 op_class_width; // w0
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  int v237; // w26
  double v238; // d0
  double v239; // d1
  double v240; // d2
  double v241; // d3
  double v242; // d4
  double v243; // d5
  double v244; // d6
  double v245; // d7
  __int64 v246; // [xsp+0h] [xbp-90h]
  __int64 v247; // [xsp+8h] [xbp-88h]
  __int64 v248; // [xsp+10h] [xbp-80h]
  __int64 v249; // [xsp+60h] [xbp-30h] BYREF
  __int64 v250; // [xsp+68h] [xbp-28h]
  __int64 v251; // [xsp+70h] [xbp-20h]
  __int64 v252; // [xsp+78h] [xbp-18h]
  __int16 v253; // [xsp+84h] [xbp-Ch] BYREF
  unsigned __int8 v254; // [xsp+86h] [xbp-Ah]
  __int64 v255; // [xsp+88h] [xbp-8h]

  v11 = a2;
  v14 = a1 + 2048;
  v255 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Msg = %d for RRM measurement",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_rrm_msg_processor",
    a2);
  if ( v11 == 5167 )
  {
    if ( *(unsigned __int8 *)(a3 + 4) >= 6uLL )
      goto LABEL_106;
    v42 = (unsigned __int16 *)&a1[68 * *(unsigned __int8 *)(a3 + 4) + 2186];
    qdf_mem_copy(v42 + 1, (const void *)(a3 + 5), 6u);
    *v42 = *(_WORD *)(a3 + 12);
    *((_BYTE *)v42 + 8) = *(_BYTE *)(a3 + 20);
    v43 = *((unsigned __int8 *)v14 + 1098);
    v44 = *(unsigned __int16 *)(a3 + 28);
    *((_BYTE *)v42 + 72) = 0;
    if ( v44 > v43 )
      LOWORD(v43) = v44;
    v42[56] = v43;
    v45 = *(_WORD *)(a3 + 30);
    *((_DWORD *)v42 + 3) = 0;
    v42[57] = v45;
    *((_BYTE *)v42 + 16) = *(_BYTE *)(a3 + 21);
    *((_DWORD *)v42 + 5) = *(_DWORD *)(a3 + 24);
    qdf_mem_copy(v42 + 20, (const void *)(a3 + 32), 8u);
    qdf_mem_copy(v42 + 24, (const void *)(a3 + 40), 4u);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: idx:%d, token: %d randnIntvl: %d meas_duration %d, rrm_ctx dur %d reg_class: %d, type: %d, channel: %d, freq: "
      "%d, [bw_ind present: %d, cw: %d, ccfs0: %d], [wide_bw present: %d, cw: %d]",
      v46,
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      "sme_rrm_process_chan_load_req_ind",
      *(unsigned __int8 *)(a3 + 4),
      *v42,
      v42[56],
      *(unsigned __int16 *)(a3 + 30),
      v42[57],
      *((unsigned __int8 *)v42 + 8),
      *((_DWORD *)v42 + 3),
      *((unsigned __int8 *)v42 + 16),
      *((_DWORD *)v42 + 5),
      *((unsigned __int8 *)v42 + 40),
      *((unsigned __int8 *)v42 + 41),
      *((_DWORD *)v42 + 11),
      *((unsigned __int8 *)v42 + 48),
      *((unsigned __int8 *)v42 + 49));
    v54 = *(unsigned __int8 *)(a3 + 4);
    if ( v54 >= 6 )
      goto LABEL_106;
    v55 = (__int64)&a1[68 * (unsigned int)v54 + 2186];
    LODWORD(v249) = 0;
    if ( (unsigned int)csr_roam_get_session_id_from_bssid((__int64)a1, (int *)(v55 + 2), &v249) )
    {
      if ( v55 == -2 )
      {
        v66 = 0;
        v64 = 0;
        v65 = 0;
        v67 = 0;
      }
      else
      {
        v64 = *(unsigned __int8 *)(v55 + 2);
        v65 = *(unsigned __int8 *)(v55 + 3);
        v66 = *(unsigned __int8 *)(v55 + 4);
        v67 = *(unsigned __int8 *)(v55 + 7);
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: sme session ID not found for bssid %02x:%02x:%02x:**:**:%02x",
        v56,
        v57,
        v58,
        v59,
        v60,
        v61,
        v62,
        v63,
        "sme_rrm_issue_chan_load_measurement_scan",
        v64,
        v65,
        v66,
        v67);
      goto LABEL_68;
    }
    v113 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             a1[2703],
             (unsigned int)v249,
             11);
    if ( !v113 )
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: VDEV is null %d",
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        "sme_rrm_issue_chan_load_measurement_scan",
        (unsigned int)v249);
      goto LABEL_68;
    }
    v122 = v113;
    v123 = _qdf_mem_malloc(0x8F0u, "sme_rrm_issue_chan_load_measurement_scan", 1335);
    if ( !v123
      || (unsigned int)wlan_scan_init_default_params(
                         v122,
                         (__int64 *)v123,
                         v124,
                         v125,
                         v126,
                         v127,
                         v128,
                         v129,
                         v130,
                         v131) )
    {
LABEL_65:
      _qdf_mem_free(v123);
      wlan_objmgr_vdev_release_ref(v122, 0xBu, v140, v141, v142, v143, v144, v145, v146, v147, v148);
LABEL_68:
      report_xmit_ind = sme_rrm_send_chan_load_report_xmit_ind(
                          a1,
                          &a1[68 * (unsigned int)v54 + 2186],
                          (unsigned int)v249,
                          0);
      rrm_cleanup((__int64)a1, (unsigned int)v54, report_xmit_ind, v150, v151, v152, v153, v154, v155, v156);
      goto LABEL_80;
    }
    scan_id = wlan_scan_get_scan_id(a1[2703], v132, v133, v134, v135, v136, v137, v138, v139);
    *(_DWORD *)(v123 + 8) = scan_id;
    *(_DWORD *)(v55 + 140) = scan_id;
    v171 = *(unsigned __int8 *)(v122 + 168);
    v172 = *(_DWORD *)(v123 + 92);
    v254 = 0;
    v253 = 0;
    *(_DWORD *)(v123 + 16) = v171;
    v173 = *(unsigned __int16 *)(v55 + 540);
    *(_DWORD *)(v123 + 92) = v172 | 1;
    *(_DWORD *)(v123 + 12) = v173;
    v174 = *(unsigned __int16 *)(v55 + 114);
    *(_DWORD *)(v123 + 100) = 4;
    *(_DWORD *)(v123 + 28) = 3;
    *(_DWORD *)(v123 + 44) = v174;
    *(_DWORD *)(v123 + 56) = v174;
    *(_DWORD *)(v123 + 92) = v172 | 0x5000001;
    v175 = *(unsigned __int8 *)(v55 + 16);
    rrm_get_country_code_from_connected_profile((__int64)a1, *(_BYTE *)(v122 + 168), (unsigned __int8 *)&v253);
    v184 = wlan_reg_country_chan_opclass_to_freq(
             a1[2704],
             (unsigned __int8 *)&v253,
             v175,
             *(_BYTE *)(v55 + 8),
             0,
             v176,
             v177,
             v178,
             v179,
             v180,
             v181,
             v182,
             v183);
    if ( !v184 )
    {
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: invalid scan freq",
        v185,
        v186,
        v187,
        v188,
        v189,
        v190,
        v191,
        v192,
        "sme_rrm_fill_freq_list_for_channel_load");
      goto LABEL_65;
    }
    v193 = v184;
    if ( (*(_BYTE *)(v55 + 40) & 1) != 0 )
    {
      if ( !*(_BYTE *)(v55 + 48) )
      {
        v194 = *(unsigned __int8 *)(v55 + 41);
        goto LABEL_89;
      }
    }
    else if ( !*(_BYTE *)(v55 + 48) )
    {
      if ( wlan_reg_is_6ghz_op_class(a1[2704], *(_BYTE *)(v55 + 8)) )
        op_class_width = wlan_reg_get_op_class_width();
      else
        op_class_width = wlan_reg_dmn_get_chanwidth_from_opclass_auto(
                           (unsigned __int8 *)&v253,
                           v175,
                           *(_BYTE *)(v55 + 8),
                           v220,
                           v221,
                           v222,
                           v223,
                           v224,
                           v225,
                           v226,
                           v227);
      v237 = op_class_width;
      LODWORD(v248) = op_class_width;
      LODWORD(v247) = v254;
      LODWORD(v246) = HIBYTE(v253);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: op: %d, ch: %d freq:%d, cc %c%c 0x%x, c_space:%d",
        v229,
        v230,
        v231,
        v232,
        v233,
        v234,
        v235,
        v236,
        "sme_rrm_fill_freq_list_for_channel_load",
        *(unsigned __int8 *)(v55 + 8),
        v175,
        v193,
        (unsigned __int8)v253,
        v246,
        v247,
        v248);
      if ( v237 > 79 )
      {
        v194 = 3;
        if ( v237 == 320 || v237 == 160 )
        {
LABEL_89:
          *(_DWORD *)(v55 + 24) = v194;
          if ( !(unsigned int)((__int64 (__fastcall *)(__int64, __int64))mlme_update_freq_in_scan_start_req)(v122, v123) )
          {
            LODWORD(v246) = *(_DWORD *)(v123 + 44);
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: vdev:%d, rrm_idx:%d scan_id:%d num chan: %d dwell_time: %d",
              v195,
              v196,
              v197,
              v198,
              v199,
              v200,
              v201,
              v202,
              "sme_rrm_issue_chan_load_measurement_scan",
              *(unsigned int *)(v123 + 16),
              *(unsigned __int8 *)(v55 + 9),
              *(unsigned int *)(v55 + 140),
              *(unsigned __int8 *)(v123 + 120),
              v246);
            *(_QWORD *)(v55 + 32) = jiffies;
            if ( !(unsigned int)wlan_scan_start((__int64 *)v123, v203, v204, v205, v206, v207, v208, v209, v210) )
            {
              wlan_objmgr_vdev_release_ref(v122, 0xBu, v211, v212, v213, v214, v215, v216, v217, v218, v219);
              goto LABEL_80;
            }
          }
          goto LABEL_65;
        }
        if ( v237 == 80 )
        {
          v194 = 2;
          goto LABEL_89;
        }
      }
      else
      {
        if ( v237 == 20 || v237 == 25 )
        {
          v194 = 0;
          goto LABEL_89;
        }
        if ( v237 == 40 )
        {
          v194 = 1;
          goto LABEL_89;
        }
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: invalid chan_space: %d",
        v238,
        v239,
        v240,
        v241,
        v242,
        v243,
        v244,
        v245,
        "sme_rrm_fill_freq_list_for_channel_load",
        (unsigned int)v237);
      goto LABEL_65;
    }
    v194 = *(unsigned __int8 *)(v55 + 49);
    goto LABEL_89;
  }
  if ( v11 == 5165 )
  {
    sme_rrm_process_beacon_report_req_ind(a1, a3);
    goto LABEL_80;
  }
  if ( v11 != 5164 )
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Unknown msg type: %d",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "sme_rrm_msg_processor",
      v11);
    goto LABEL_80;
  }
  if ( *(unsigned __int8 *)(a3 + 5) >= 5uLL )
    goto LABEL_106;
  v23 = (__int64)&a1[68 * *(unsigned __int8 *)(a3 + 5) + 2186];
  if ( (*(_BYTE *)(v23 + 232) & 1) == 0 )
  {
    csr_ll_lock(v23 + 144, v15, v16, v17, v18, v19, v20, v21, v22);
    while ( 1 )
    {
      v32 = csr_ll_remove_head(v23 + 144, 0, v24, v25, v26, v27, v28, v29, v30, v31);
      if ( !v32 )
        break;
      v41 = v32;
      _qdf_mem_free(*(_QWORD *)(v32 + 16));
      _qdf_mem_free(v41);
    }
    csr_ll_unlock(v23 + 144, v33, v34, v35, v36, v37, v38, v39, v40);
  }
  if ( *(_WORD *)(a3 + 6) )
  {
    v68 = 0;
    do
    {
      v73 = _qdf_mem_malloc(0x20u, "sme_rrm_process_neighbor_report", 1970);
      if ( !v73 )
        break;
      v74 = v73;
      v75 = (void *)_qdf_mem_malloc(0x18u, "sme_rrm_process_neighbor_report", 1978);
      *(_QWORD *)(v74 + 16) = v75;
      if ( !v75 )
      {
        _qdf_mem_free(v74);
        break;
      }
      v76 = (unsigned __int8 *)(a3 + 16 + 24LL * v68);
      qdf_mem_copy(v75, v76, 0x18u);
      if ( v76 == (unsigned __int8 *)-2LL )
      {
        v87 = 0;
        v85 = 0;
        v86 = 0;
        v88 = 0;
      }
      else
      {
        v85 = v76[2];
        v86 = v76[3];
        v87 = v76[4];
        v88 = v76[7];
      }
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: Received neighbor report with Neighbor BSSID: %02x:%02x:%02x:**:**:%02x",
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        v83,
        v84,
        "sme_rrm_process_neighbor_report",
        v85,
        v86,
        v87,
        v88);
      v89 = *(_QWORD *)(v74 + 16);
      if ( v89 )
      {
        v251 = 0;
        v252 = 0;
        v249 = 0;
        v250 = 0;
        v90 = *(_DWORD *)(v89 + 12);
        if ( (v90 & 0x400) != 0 )
        {
          if ( (v90 & 4) != 0 )
          {
            if ( (v90 & 8) != 0 )
            {
              if ( (v90 & 0x80) != 0 )
              {
                if ( (v90 & 0x20) != 0 )
                  v92 = 73;
                else
                  v92 = 68;
                if ( (v90 & 0x40) != 0 )
                  v92 += 3;
                if ( (v90 & 0x200) != 0 )
                  v91 = v92 + 3;
                else
                  v91 = v92;
              }
              else
              {
                v91 = 60;
              }
            }
            else
            {
              v91 = 40;
            }
          }
          else
          {
            v91 = 30;
          }
        }
        else
        {
          v91 = 0;
        }
        wlan_cm_roam_cfg_get_value(a1[2703], *(unsigned __int8 *)(v74 + 28), 0x15u, &v249);
        if ( (_BYTE)v250 )
          v93 = v91;
        else
          v93 = v91 + 30;
        *(_DWORD *)(v74 + 24) = v93;
      }
      if ( *(_DWORD *)(v74 + 24) )
      {
        if ( *(_QWORD *)(v74 + 16) )
        {
          if ( (csr_ll_is_list_empty((__int64)(a1 + 2204), 1, v15, v16, v17, v18, v19, v20, v21, v22) & 1) != 0 )
          {
            qdf_trace_msg(
              0x34u,
              2u,
              "%s: Neighbor report cache is empty.. Adding a entry now",
              v94,
              v95,
              v96,
              v97,
              v98,
              v99,
              v100,
              v101,
              "rrm_store_neighbor_rpt_by_roam_score");
          }
          else
          {
            v110 = csr_ll_peek_head((__int64)(a1 + 2204), 1, v94, v95, v96, v97, v98, v99, v100, v101);
            if ( v110 )
            {
              v111 = v110;
              while ( 1 )
              {
                v112 = (__int64)(a1 + 2204);
                if ( *(_DWORD *)(v111 + 24) < *(_DWORD *)(v74 + 24) )
                  break;
                v111 = csr_ll_next(v112, v111, 1, v102, v103, v104, v105, v106, v107, v108, v109);
                if ( !v111 )
                  goto LABEL_60;
              }
              csr_ll_insert_entry(
                v112,
                (__int64 *)v111,
                (_QWORD *)v74,
                1,
                v102,
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                v109);
              continue;
            }
          }
LABEL_60:
          csr_ll_insert_tail((__int64)(a1 + 2204), (_QWORD *)v74, 1, v102, v103, v104, v105, v106, v107, v108, v109);
        }
      }
      else
      {
        if ( v76 == (unsigned __int8 *)-2LL )
        {
          v71 = 0;
          v69 = 0;
          v70 = 0;
          v72 = 0;
        }
        else
        {
          v69 = v76[2];
          v70 = v76[3];
          v71 = v76[4];
          v72 = v76[7];
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Roam score of BSSID  %02x:%02x:%02x:**:**:%02x is 0, Ignoring..",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "sme_rrm_process_neighbor_report",
          v69,
          v70,
          v71,
          v72);
        _qdf_mem_free(*(_QWORD *)(v74 + 16));
        _qdf_mem_free(v74);
      }
    }
    while ( *(unsigned __int16 *)(a3 + 6) > (unsigned int)++v68 );
  }
  if ( *(unsigned __int8 *)(a3 + 5) > 4uLL )
LABEL_106:
    __break(0x5512u);
  v157 = (unsigned int)csr_ll_count(
                         (__int64)&a1[68 * *(unsigned __int8 *)(a3 + 5) + 2204],
                         v15,
                         v16,
                         v17,
                         v18,
                         v19,
                         v20,
                         v21,
                         v22) == 0;
  *((_BYTE *)v14 + 1336) = 0;
  v158 = v157;
  if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(a1 + 2216)) == 21 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: No entry in neighbor report cache",
      v159,
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      v166,
      "rrm_indicate_neighbor_report_result");
    qdf_mc_timer_stop((__int64)(a1 + 2216));
  }
  v167 = (_DWORD *)a1[2238];
  v168 = a1[2239];
  a1[2238] = 0;
  a1[2239] = 0;
  if ( v167 )
  {
    if ( *(v167 - 1) != -963780396 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD))v167)(v168, (unsigned int)(16 * v158));
  }
LABEL_80:
  _ReadStatusReg(SP_EL0);
  return 0;
}
