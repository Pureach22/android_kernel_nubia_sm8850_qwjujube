__int64 __fastcall policy_mgr_is_concurrency_allowed(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        int a4,
        unsigned int a5,
        __int64 a6)
{
  __int64 context; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x21
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _BOOL4 v31; // w27
  __int64 v32; // x28
  int v33; // w26
  __int64 v34; // x0
  __int64 v35; // x20
  __int64 result; // x0
  const char *v37; // x2
  const char *v38; // x3
  const char *v39; // x3
  _BYTE *v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int ch_width; // w0
  __int64 v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  _BOOL4 v67; // w25
  __int64 v68; // x20
  bool is_sta_sap_scc_allowed_on_dfs_chan; // w26
  int v70; // w0
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x20
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x20
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  _BOOL4 v106; // w8
  int v107; // w24
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  __int64 v116; // x20
  __int64 v117; // x20
  __int64 v118; // x0
  __int64 v119; // x25
  __int64 v120; // x0
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  __int64 v129; // x26
  int is_mlo_vdev; // w0
  _BOOL8 v131; // x8
  int v132; // w28
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x0
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  __int64 v150; // x26
  int v151; // w0
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  unsigned __int64 v160; // x8
  __int64 v161; // x0
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  __int64 v170; // x26
  int v171; // w0
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  unsigned __int64 v180; // x8
  __int64 v181; // x0
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  __int64 v190; // x26
  int v191; // w0
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  unsigned __int64 v200; // x8
  __int64 v201; // x0
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  __int64 v210; // x26
  int v211; // w0
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  unsigned __int64 v220; // x8
  __int64 v221; // x25
  __int64 v222; // x8
  __int64 v223; // x0
  __int64 v224; // x20
  __int64 v225; // x20
  __int64 v226; // x20
  __int64 v227; // x24
  __int64 v228; // x8
  __int64 v229; // x8
  __int64 v230; // x0
  __int64 v231; // x0
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  __int64 v240; // x24
  int v241; // w25
  int v242; // w26
  const char *v243; // x2
  __int64 v244; // x20
  __int64 v245; // x20
  __int64 v246; // x8
  __int64 v247; // x8
  __int64 v248; // x9
  int v249; // [xsp+4h] [xbp-3Ch]
  _QWORD v250[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v251; // [xsp+20h] [xbp-20h] BYREF
  __int64 v252; // [xsp+28h] [xbp-18h]
  unsigned int v253; // [xsp+30h] [xbp-10h]
  __int64 v254; // [xsp+38h] [xbp-8h]

  v254 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v253 = 0;
  v251 = 0;
  v252 = 0;
  memset(v250, 0, sizeof(v250));
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v37 = "%s: Invalid Context";
LABEL_9:
    v38 = "policy_mgr_is_concurrency_allowed";
LABEL_10:
    qdf_trace_msg(0x4Fu, 2u, v37, v13, v14, v15, v16, v17, v18, v19, v20, v38);
    goto LABEL_126;
  }
  v21 = context;
  v22 = policy_mgr_get_context(a1);
  v31 = v22 != 0;
  if ( !v22 )
  {
    v33 = 0;
    v39 = "policy_mgr_get_connection_count";
LABEL_14:
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v23, v24, v25, v26, v27, v28, v29, v30, v39);
    goto LABEL_15;
  }
  v32 = v22;
  qdf_mutex_acquire(v22 + 56);
  v33 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C) + BYTE4(qword_8D4F90);
  qdf_mutex_release(v32 + 56);
  if ( !v33 )
  {
    v31 = 0;
    goto LABEL_15;
  }
  v34 = policy_mgr_get_context(a1);
  if ( !v34 )
  {
    v39 = "policy_mgr_is_sub_20_mhz_enabled";
    goto LABEL_14;
  }
  if ( *(_BYTE *)(v34 + 1673) == 1 )
  {
    v35 = jiffies;
    if ( policy_mgr_is_concurrency_allowed___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: dont allow concurrency if Sub 20 MHz is enabled",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "policy_mgr_is_concurrency_allowed");
      result = 0;
      policy_mgr_is_concurrency_allowed___last_ticks = v35;
      goto LABEL_127;
    }
LABEL_126:
    result = 0;
    goto LABEL_127;
  }
  v31 = 1;
LABEL_15:
  v40 = (_BYTE *)policy_mgr_get_context(a1);
  if ( v40
    && (unsigned __int8)v40[2202] <= (unsigned int)(unsigned __int8)(v40[990]
                                                                   + v40[989]
                                                                   + v40[991]
                                                                   + v40[992]
                                                                   + v40[993]
                                                                   + v40[994]
                                                                   + v40[995]
                                                                   + v40[996]
                                                                   + v40[997]
                                                                   + v40[998]
                                                                   + v40[999]
                                                                   + v40[1000]
                                                                   + v40[1001]
                                                                   + v40[1002]
                                                                   + v40[1003]
                                                                   + v40[1004]) )
  {
    v68 = jiffies;
    if ( policy_mgr_is_concurrency_allowed___last_ticks_179 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Reached max concurrent connections: %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "policy_mgr_is_concurrency_allowed",
        *(unsigned __int8 *)(v21 + 2202));
      policy_mgr_is_concurrency_allowed___last_ticks_179 = v68;
    }
    policy_mgr_validate_conn_info(a1);
    goto LABEL_126;
  }
  if ( !a3 )
    goto LABEL_43;
  if ( wlan_reg_is_5ghz_ch_freq(a3) )
  {
    qdf_mem_set(v250, 0x18u, 0);
    ch_width = policy_mgr_get_ch_width(a4, v49, v50, v51, v52, v53, v54, v55, v56);
    v58 = *(_QWORD *)(v21 + 8);
    LODWORD(v250[0]) = ch_width;
    v67 = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
            v58,
            a3,
            (int *)v250,
            0,
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66) == 2;
  }
  else
  {
    v67 = 0;
  }
  if ( (policy_mgr_allow_new_home_channel(a1, a2, a3, v33, v67, a5) & 1) == 0
    || (policy_mgr_is_5g_channel_allowed(a1, a3, &v251, 3u) & 1) == 0
    || (policy_mgr_is_5g_channel_allowed(a1, a3, &v251, 1u) & 1) == 0
    || (policy_mgr_is_6g_channel_allowed(a1, a2, a3) & 1) == 0 )
  {
    goto LABEL_126;
  }
  is_sta_sap_scc_allowed_on_dfs_chan = policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(a1);
  v70 = policy_mgr_go_scc_enforced(a1);
  if ( (a2 | 2) == 3 )
  {
    if ( is_sta_sap_scc_allowed_on_dfs_chan )
    {
      if ( (((a2 != 3) | v70) & (unsigned int)policy_mgr_is_sta_sap_scc(a1, a3, 0) & 1) != 0 || !v67 )
        goto LABEL_38;
    }
    else if ( !v67 )
    {
      goto LABEL_38;
    }
    if ( (policy_mgr_disallow_mcc(a1, a3) & 1) != 0 )
    {
      v79 = jiffies;
      if ( policy_mgr_is_concurrency_allowed___last_ticks_181 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: No MCC, SAP/GO about to come up on DFS channel",
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          v77,
          v78,
          "policy_mgr_is_concurrency_allowed");
        result = 0;
        policy_mgr_is_concurrency_allowed___last_ticks_181 = v79;
        goto LABEL_127;
      }
      goto LABEL_126;
    }
  }
LABEL_38:
  if ( (v31 & ((unsigned int)policy_mgr_is_hw_dbs_capable(a1) ^ 1)) == 1
    && wlan_reg_is_24ghz_ch_freq(a3)
    && (policy_mgr_is_sap_p2pgo_on_dfs(a1, v80, v81, v82, v83, v84, v85, v86, v87) & 1) != 0 )
  {
    v96 = jiffies;
    if ( policy_mgr_is_concurrency_allowed___last_ticks_183 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: MCC not allowed: SAP/P2PGO on DFS",
        v88,
        v89,
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        "policy_mgr_is_concurrency_allowed");
      result = 0;
      policy_mgr_is_concurrency_allowed___last_ticks_183 = v96;
      goto LABEL_127;
    }
    goto LABEL_126;
  }
LABEL_43:
  if ( a2 )
    goto LABEL_44;
  v118 = policy_mgr_get_context(a1);
  if ( !v118 )
  {
    v37 = "%s: Invalid Context";
    v38 = "policy_mgr_allow_sta_concurrency";
    goto LABEL_10;
  }
  v119 = v118;
  qdf_mutex_acquire(v118 + 56);
  if ( !(_DWORD)pm_conc_connection_list
    && BYTE4(qword_8D4F00) == 1
    && (v120 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                 a1,
                 (unsigned int)qword_8D4F00,
                 24)) != 0 )
  {
    v129 = v120;
    is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v120, v121, v122, v123, v124, v125, v126, v127, v128);
    v131 = (*(_DWORD *)(v129 + 60) & 2) == 0;
    v132 = v131 & is_mlo_vdev;
    v249 = (*(_DWORD *)(v129 + 60) & 2) == 0;
    wlan_objmgr_vdev_release_ref(v129, 0x18u, (unsigned int *)v131, v133, v134, v135, v136, v137, v138, v139, v140);
  }
  else
  {
    v132 = 0;
    v249 = 0;
  }
  if ( !(_DWORD)qword_8D4F0C && BYTE4(qword_8D4F24) == 1 )
  {
    v141 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             a1,
             (unsigned int)qword_8D4F24,
             24);
    if ( v141 )
    {
      v150 = v141;
      v151 = wlan_vdev_mlme_is_mlo_vdev(v141, v142, v143, v144, v145, v146, v147, v148, v149);
      v160 = *(unsigned __int8 *)(v150 + 60);
      if ( (v160 & 2) == 0 )
      {
        v132 |= v151;
        v160 = (unsigned int)++v249;
      }
      wlan_objmgr_vdev_release_ref(v150, 0x18u, (unsigned int *)v160, v152, v153, v154, v155, v156, v157, v158, v159);
    }
  }
  if ( !(_DWORD)qword_8D4F30 && BYTE4(qword_8D4F48) == 1 )
  {
    v161 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             a1,
             (unsigned int)qword_8D4F48,
             24);
    if ( v161 )
    {
      v170 = v161;
      v171 = wlan_vdev_mlme_is_mlo_vdev(v161, v162, v163, v164, v165, v166, v167, v168, v169);
      v180 = *(unsigned __int8 *)(v170 + 60);
      if ( (v180 & 2) == 0 )
      {
        v132 |= v171;
        v180 = (unsigned int)++v249;
      }
      wlan_objmgr_vdev_release_ref(v170, 0x18u, (unsigned int *)v180, v172, v173, v174, v175, v176, v177, v178, v179);
    }
  }
  if ( !(_DWORD)qword_8D4F54 && BYTE4(qword_8D4F6C) == 1 )
  {
    v181 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             a1,
             (unsigned int)qword_8D4F6C,
             24);
    if ( v181 )
    {
      v190 = v181;
      v191 = wlan_vdev_mlme_is_mlo_vdev(v181, v182, v183, v184, v185, v186, v187, v188, v189);
      v200 = *(unsigned __int8 *)(v190 + 60);
      if ( (v200 & 2) == 0 )
      {
        v132 |= v191;
        v200 = (unsigned int)++v249;
      }
      wlan_objmgr_vdev_release_ref(v190, 0x18u, (unsigned int *)v200, v192, v193, v194, v195, v196, v197, v198, v199);
    }
  }
  if ( !(_DWORD)qword_8D4F78 && BYTE4(qword_8D4F90) == 1 )
  {
    v201 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
             a1,
             (unsigned int)qword_8D4F90,
             24);
    if ( v201 )
    {
      v210 = v201;
      v211 = wlan_vdev_mlme_is_mlo_vdev(v201, v202, v203, v204, v205, v206, v207, v208, v209);
      v220 = *(unsigned __int8 *)(v210 + 60);
      if ( (v220 & 2) == 0 )
      {
        v132 |= v211;
        v220 = (unsigned int)++v249;
      }
      wlan_objmgr_vdev_release_ref(v210, 0x18u, (unsigned int *)v220, v212, v213, v214, v215, v216, v217, v218, v219);
    }
  }
  qdf_mutex_release(v119 + 56);
  if ( (a5 & 2) != 0 && (v132 & 1) != 0 )
  {
    v221 = jiffies;
    if ( policy_mgr_allow_sta_concurrency___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Allow secondary MLO link",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "policy_mgr_allow_sta_concurrency");
      policy_mgr_allow_sta_concurrency___last_ticks = v221;
    }
    goto LABEL_44;
  }
  if ( !v249 )
  {
    if ( (a5 & v132 & 1) == 0 )
      goto LABEL_44;
LABEL_109:
    v226 = jiffies;
    if ( policy_mgr_allow_sta_concurrency___last_ticks_414 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Disallow ML STA when ML STA is present",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "policy_mgr_allow_sta_concurrency");
      result = 0;
      policy_mgr_allow_sta_concurrency___last_ticks_414 = v226;
      goto LABEL_127;
    }
    goto LABEL_126;
  }
  if ( !a1 || (v222 = *(_QWORD *)(a1 + 2800)) == 0 || (v223 = *(_QWORD *)(v222 + 16)) == 0 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Invalid WMI handle",
      v108,
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      "policy_mgr_allow_multiple_sta_connections");
    goto LABEL_106;
  }
  if ( (wmi_service_enabled(v223, 0xABu, v108, v109, v110, v111, v112, v113, v114, v115) & 1) == 0 )
  {
LABEL_142:
    v245 = jiffies;
    if ( policy_mgr_allow_multiple_sta_connections___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: STA+STA is not supported",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "policy_mgr_allow_multiple_sta_connections");
      policy_mgr_allow_multiple_sta_connections___last_ticks = v245;
    }
LABEL_106:
    v225 = jiffies;
    if ( policy_mgr_allow_sta_concurrency___last_ticks_412 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Disallow Multiple STA connections",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "policy_mgr_allow_sta_concurrency");
      result = 0;
      policy_mgr_allow_sta_concurrency___last_ticks_412 = v225;
      goto LABEL_127;
    }
    goto LABEL_126;
  }
  if ( (a5 & v132 & 1) != 0 )
    goto LABEL_109;
  if ( v249 != 1 )
  {
    v224 = jiffies;
    if ( policy_mgr_allow_sta_concurrency___last_ticks_416 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: Disallow 3rd STA",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "policy_mgr_allow_sta_concurrency");
      result = 0;
      policy_mgr_allow_sta_concurrency___last_ticks_416 = v224;
      goto LABEL_127;
    }
    goto LABEL_126;
  }
LABEL_44:
  if ( (policy_mgr_allow_sap_go_concurrency(a1, a2, a3, 255) & 1) == 0 )
  {
    v117 = jiffies;
    if ( policy_mgr_is_concurrency_allowed___last_ticks_185 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: This concurrency combination is not allowed",
        v97,
        v98,
        v99,
        v100,
        v101,
        v102,
        v103,
        v104,
        "policy_mgr_is_concurrency_allowed");
      result = 0;
      policy_mgr_is_concurrency_allowed___last_ticks_185 = v117;
      goto LABEL_127;
    }
    goto LABEL_126;
  }
  v106 = a2 == 3 && a3 != 0 && v31;
  if ( v106 && (wlan_mlme_get_p2p_p2p_conc_support(a1) & 1) == 0 )
  {
    v107 = policy_mgr_mode_specific_connection_count(a1, 3, &v251);
    qdf_mutex_acquire(v21 + 56);
    if ( v107 )
    {
      if ( (unsigned int)v251 >= 5 )
        goto LABEL_141;
      if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v251 + 1)) & 1) != 0 )
      {
LABEL_56:
        v116 = jiffies;
        if ( policy_mgr_is_concurrency_allowed___last_ticks_187 - jiffies + 125 < 0 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: Don't allow P2P GO on same band",
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            v115,
            "policy_mgr_is_concurrency_allowed");
          policy_mgr_is_concurrency_allowed___last_ticks_187 = v116;
        }
        qdf_mutex_release(v21 + 56);
        goto LABEL_126;
      }
      if ( v107 != 1 )
      {
        if ( HIDWORD(v251) > 4 )
          goto LABEL_141;
        if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v251) + 1)) & 1) != 0 )
          goto LABEL_56;
        if ( v107 != 2 )
        {
          if ( (unsigned int)v252 > 4 )
            goto LABEL_141;
          if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * (unsigned int)v252 + 1)) & 1) != 0 )
            goto LABEL_56;
          if ( v107 != 3 )
          {
            if ( HIDWORD(v252) > 4 )
              goto LABEL_141;
            if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * HIDWORD(v252) + 1)) & 1) != 0 )
              goto LABEL_56;
            if ( v107 != 4 )
            {
              if ( v253 > 4 )
                goto LABEL_141;
              if ( (wlan_reg_is_same_band_freqs(a3, *((_DWORD *)&pm_conc_connection_list + 9 * v253 + 1)) & 1) != 0 )
                goto LABEL_56;
              if ( v107 != 5 )
                goto LABEL_141;
            }
          }
        }
      }
    }
    qdf_mutex_release(v21 + 56);
  }
  v227 = *(_QWORD *)(v21 + 8);
  if ( !v227 )
  {
    v243 = "%s: pdev is Null";
LABEL_124:
    qdf_trace_msg(0x4Fu, 8u, v243, v97, v98, v99, v100, v101, v102, v103, v104, "policy_mgr_allow_wapi_concurrency");
    goto LABEL_125;
  }
  v228 = *(_QWORD *)(v227 + 80);
  if ( !v228 )
    goto LABEL_125;
  v229 = *(_QWORD *)(v228 + 2800);
  if ( !v229 || (v230 = *(_QWORD *)(v229 + 16)) == 0 )
  {
    v243 = "%s: Invalid WMI handle";
    goto LABEL_124;
  }
  if ( (wmi_service_enabled(v230, 0xE6u, v97, v98, v99, v100, v101, v102, v103, v104) & 1) == 0
    && (mlme_is_wapi_sta_active(v227) & 1) != 0 )
  {
    v231 = policy_mgr_get_context(*(_QWORD *)v21);
    if ( !v231 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid Context",
        v232,
        v233,
        v234,
        v235,
        v236,
        v237,
        v238,
        v239,
        "policy_mgr_get_connection_count");
      goto LABEL_145;
    }
    v240 = v231;
    qdf_mutex_acquire(v231 + 56);
    v241 = BYTE4(qword_8D4F90);
    v242 = BYTE4(qword_8D4F24) + BYTE4(qword_8D4F00) + BYTE4(qword_8D4F48) + BYTE4(qword_8D4F6C);
    qdf_mutex_release(v240 + 56);
    if ( v242 | v241 )
    {
LABEL_125:
      v244 = jiffies;
      if ( policy_mgr_is_concurrency_allowed___last_ticks_189 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: Don't allow new conn when wapi security conn existing",
          v97,
          v98,
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          "policy_mgr_is_concurrency_allowed");
        result = 0;
        policy_mgr_is_concurrency_allowed___last_ticks_189 = v244;
        goto LABEL_127;
      }
      goto LABEL_126;
    }
  }
LABEL_145:
  if ( (policy_mgr_is_third_conn_sta_p2p_p2p_valid(a1, a2) & 1) == 0 )
  {
    v37 = "%s: Don't allow third connection as GO or GC or STA with old fw";
    goto LABEL_9;
  }
  result = 1;
  if ( a2 == 1 && a6 )
  {
    if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(v21 + 8), a3, v13, v14, v15, v16, v17, v18, v19, v20) & 1) == 0 )
    {
LABEL_156:
      result = 1;
      goto LABEL_127;
    }
    v246 = *(unsigned int *)(a6 + 512);
    if ( !(_DWORD)v246 )
    {
LABEL_154:
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: SAP channel %d Not present in PCL",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "policy_mgr_is_concurrency_allowed",
        a3);
      goto LABEL_126;
    }
    v247 = 4 * v246;
    v248 = 0;
    while ( v248 != 408 )
    {
      if ( *(_DWORD *)(a6 + v248) == a3 )
        goto LABEL_156;
      v248 += 4;
      if ( v247 == v248 )
        goto LABEL_154;
    }
LABEL_141:
    __break(0x5512u);
    goto LABEL_142;
  }
LABEL_127:
  _ReadStatusReg(SP_EL0);
  return result;
}
