__int64 __fastcall wlan_hdd_cm_connect(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  const char *v22; // x2
  __int64 result; // x0
  unsigned int v24; // w0
  _QWORD *v25; // x21
  __int64 v26; // x27
  unsigned __int64 StatusReg; // x8
  __int64 v28; // x1
  const char *v29; // x0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x8
  __int64 v39; // x0
  unsigned __int64 v40; // x20
  __int64 v41; // x22
  __int64 v42; // x8
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 active_channel; // x0
  unsigned int *v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned __int16 *v61; // x25
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x0
  unsigned int *v71; // x8
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  const char *v88; // x2
  double v89; // d0
  double v90; // d1
  double v91; // d2
  double v92; // d3
  double v93; // d4
  double v94; // d5
  double v95; // d6
  double v96; // d7
  __int64 v97; // x23
  __int64 v98; // x0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  __int64 v115; // x8
  _QWORD *v116; // x24
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  char is_hw_sbs_capable; // w0
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  unsigned int next_lower_bandwidth; // w24
  unsigned int *v167; // x20
  bool ap_6ghz_capable; // w25
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  __int64 v185; // x0
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  int _5g_bonded_channel_state_for_pwrmode; // w0
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 v203; // x0
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  int v212; // w0
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  __int64 vdev_by_user; // x0
  __int64 v222; // x22
  _WORD *v223; // x20
  _DWORD *v224; // x9
  unsigned int v225; // w9
  int v226; // w8
  int v227; // w9
  unsigned int v228; // w20
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  double v237; // d0
  double v238; // d1
  double v239; // d2
  double v240; // d3
  double v241; // d4
  double v242; // d5
  double v243; // d6
  double v244; // d7
  __int64 v245; // [xsp+0h] [xbp-60h]
  __int64 v246; // [xsp+8h] [xbp-58h]
  __int64 v247; // [xsp+10h] [xbp-50h] BYREF
  __int64 v248; // [xsp+18h] [xbp-48h] BYREF
  __int64 v249; // [xsp+20h] [xbp-40h]
  __int64 v250; // [xsp+28h] [xbp-38h] BYREF
  __int64 v251; // [xsp+30h] [xbp-30h] BYREF
  __int64 v252; // [xsp+38h] [xbp-28h] BYREF
  __int64 v253; // [xsp+40h] [xbp-20h]
  __int64 v254; // [xsp+48h] [xbp-18h]
  __int64 v255; // [xsp+50h] [xbp-10h]
  __int64 v256; // [xsp+58h] [xbp-8h]

  v256 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v254 = 0;
  v255 = 0;
  v252 = 0;
  v253 = 0;
  v13 = qdf_trace_msg(0x33u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "wlan_hdd_cm_connect");
  if ( (unsigned int)hdd_get_conparam(v13) == 5 )
  {
    v22 = "%s: Command not allowed in FTM mode";
    goto LABEL_3;
  }
  if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                       *(unsigned __int8 *)(*(_QWORD *)(a10 + 55512) + 8LL),
                       "wlan_hdd_cm_connect") )
    goto LABEL_5;
  qdf_mtrace(51, 51, 0x21u, *(_BYTE *)(*(_QWORD *)(a10 + 55512) + 8LL), *(_DWORD *)(a10 + 2728));
  v24 = *(_DWORD *)(a10 + 2728);
  if ( (v24 | 2) != 2 )
  {
    v29 = qdf_opmode_str(v24);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Device_mode %s(%d) is not supported",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wlan_hdd_cm_connect",
      v29,
      *(unsigned int *)(a10 + 2728));
    goto LABEL_5;
  }
  v25 = *(_QWORD **)(a10 + 2712);
  v26 = *(_QWORD *)(a10 + 55512);
  result = _wlan_hdd_validate_context(v25, "wlan_hdd_cm_connect");
  if ( !(_DWORD)result )
  {
    hdd_reg_wait_for_country_change(v25);
    if ( (policy_mgr_is_hw_dbs_capable(*v25) & 1) != 0 )
    {
      v247 = 0;
      v248 = 0;
      v250 = 0;
      v251 = 0;
      v249 = 0;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v25 + 4);
      }
      else
      {
        raw_spin_lock_bh(v25 + 4);
        v25[5] |= 1uLL;
      }
      hdd_get_front_adapter_no_lock(v25, &v251);
      if ( v251 )
      {
        hdd_adapter_dev_hold_debug(v251, 25);
        v28 = v251;
      }
      else
      {
        v28 = 0;
      }
      hdd_get_next_adapter_no_lock(v25, v28, &v250);
      if ( v250 )
        hdd_adapter_dev_hold_debug(v250, 25);
      v38 = v25[5];
      v245 = v26;
      v246 = a11;
      if ( (v38 & 1) != 0 )
      {
        v25[5] = v38 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v25 + 4);
        v39 = v251;
        if ( !v251 )
          goto LABEL_106;
      }
      else
      {
        raw_spin_unlock(v25 + 4);
        v39 = v251;
        if ( !v251 )
          goto LABEL_106;
      }
      v40 = _ReadStatusReg(SP_EL0);
      do
      {
        while ( 1 )
        {
          if ( *(_DWORD *)(v39 + 40) == 1 && (*(_QWORD *)(v39 + 1640) & 1) != 0 )
          {
            v41 = v39 + 52832;
            if ( v39 != -52832 )
            {
              do
              {
                if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                                      *(unsigned __int8 *)(v41 + 8),
                                      "hdd_get_sap_link_info_of_dfs")
                  && ((*(_QWORD *)(v41 + 4416) & 2) != 0 || *((_BYTE *)v25 + 912) == 1) )
                {
                  wlan_objmgr_vdev_get_ref(*(_QWORD *)(v41 + 32), 5u, v43, v44, v45, v46, v47, v48, v49, v50);
                  active_channel = wlan_vdev_get_active_channel(*(_QWORD *)(v41 + 32));
                  if ( active_channel )
                  {
                    v61 = (unsigned __int16 *)active_channel;
                    wlan_objmgr_vdev_release_ref(*(_QWORD *)(v41 + 32), 5u, v52, v53, v54, v55, v56, v57, v58, v59, v60);
                    if ( wlan_reg_is_5ghz_ch_freq(*v61) )
                    {
                      v70 = v25[1];
                      LODWORD(v248) = *((_DWORD *)v61 + 6);
                      if ( (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                           v70,
                                           *v61,
                                           (unsigned int *)&v248,
                                           0,
                                           v62,
                                           v63,
                                           v64,
                                           v65,
                                           v66,
                                           v67,
                                           v68,
                                           v69) == 2 )
                      {
                        hdd_adapter_dev_put_debug(v251, 25);
                        if ( v250 )
                          hdd_adapter_dev_put_debug(v250, 25);
                        a11 = v246;
                        if ( *((_BYTE *)v25 + 912) == 1 )
                        {
                          v88 = "%s: Concurrent SAP is in CAC state, STA is not allowed";
                          goto LABEL_59;
                        }
                        if ( v41 == -80 )
                        {
                          v88 = "%s: AP context not found";
                          goto LABEL_59;
                        }
                        if ( (policy_mgr_is_sta_sap_scc(*v25, *(_DWORD *)(v41 + 2152), 0) & 1) != 0 )
                        {
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: DFS SAP is already in SCC with STA",
                            v89,
                            v90,
                            v91,
                            v92,
                            v93,
                            v94,
                            v95,
                            v96,
                            "wlan_hdd_cm_handle_sap_sta_dfs_conc");
                          goto LABEL_107;
                        }
                        if ( !*(_QWORD *)v246 || (LODWORD(v97) = *(_DWORD *)(*(_QWORD *)v246 + 4LL), !(_DWORD)v97) )
                        {
                          v98 = _qdf_mem_malloc(0x2D0u, "wlan_hdd_cm_handle_sap_sta_dfs_conc", 736);
                          v97 = v98;
                          if ( v98 )
                          {
                            if ( *(_QWORD *)(v246 + 16) )
                            {
                              *(_BYTE *)(v98 + 16) = 1;
                              qdf_mem_copy((void *)(v98 + 70), *(const void **)(v246 + 16), 6u);
                            }
                            if ( *(_QWORD *)(v246 + 40) < 0x21u )
                            {
                              *(_BYTE *)(v97 + 17) = 1;
                              v115 = *(_QWORD *)(v246 + 40);
                              *(_BYTE *)(v97 + 100) = v115;
                              qdf_mem_copy((void *)(v97 + 101), *(const void **)(v246 + 32), (unsigned __int8)v115);
                            }
                            else
                            {
                              *(_BYTE *)(v97 + 17) = 0;
                              qdf_trace_msg(
                                0x33u,
                                2u,
                                "%s: req ssid len invalid %zu",
                                v99,
                                v100,
                                v101,
                                v102,
                                v103,
                                v104,
                                v105,
                                v106,
                                "wlan_hdd_cm_handle_sap_sta_dfs_conc",
                                *(_QWORD *)(v246 + 40));
                            }
                            *(_WORD *)v97 |= 8u;
                            v116 = ucfg_scan_get_result(v25[1], v97, v107, v108, v109, v110, v111, v112, v113, v114);
                            _qdf_mem_free(v97);
                            if ( v116 )
                            {
                              if ( *((_DWORD *)v116 + 4) )
                              {
                                qdf_list_peek_front(v116, &v247);
                                if ( v247 )
                                {
                                  LODWORD(v97) = *(_DWORD *)(*(_QWORD *)(v247 + 24) + 1064LL);
                                  goto LABEL_75;
                                }
                              }
                              else
                              {
                                qdf_trace_msg(
                                  0x33u,
                                  8u,
                                  "%s: scan list empty",
                                  v117,
                                  v118,
                                  v119,
                                  v120,
                                  v121,
                                  v122,
                                  v123,
                                  v124,
                                  "wlan_hdd_cm_handle_sap_sta_dfs_conc");
                              }
                              LODWORD(v97) = 0;
LABEL_75:
                              ucfg_scan_purge_results((__int64)v116, v125, v126, v127, v128, v129, v130, v131, v132);
                            }
                            else
                            {
                              qdf_trace_msg(
                                0x33u,
                                8u,
                                "%s: scan list empty",
                                v117,
                                v118,
                                v119,
                                v120,
                                v121,
                                v122,
                                v123,
                                v124,
                                "wlan_hdd_cm_handle_sap_sta_dfs_conc");
                              LODWORD(v97) = 0;
                            }
                          }
                        }
                        if ( wlan_reg_is_24ghz_ch_freq(v97) )
                        {
                          qdf_trace_msg(
                            0x33u,
                            4u,
                            "%s: sap is on dfs, new sta conn on 2.4 is allowed",
                            v133,
                            v134,
                            v135,
                            v136,
                            v137,
                            v138,
                            v139,
                            v140,
                            "wlan_hdd_cm_handle_sap_sta_dfs_conc");
                          goto LABEL_107;
                        }
                        is_hw_sbs_capable = policy_mgr_is_hw_sbs_capable(*v25);
                        if ( (_DWORD)v97 && (is_hw_sbs_capable & 1) != 0 )
                        {
                          if ( (policy_mgr_are_sbs_chan(*v25, v97, *(_DWORD *)(v41 + 2152)) & 1) != 0 )
                          {
                            qdf_trace_msg(
                              0x33u,
                              8u,
                              "%s: sta freq %d sap freq %d in sbs mode is allowed",
                              v142,
                              v143,
                              v144,
                              v145,
                              v146,
                              v147,
                              v148,
                              v149,
                              "wlan_hdd_cm_handle_sap_sta_dfs_conc",
                              (unsigned int)v97,
                              *(unsigned int *)(v41 + 2152));
                            goto LABEL_107;
                          }
LABEL_83:
                          if ( policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(*v25)
                            && (wlan_reg_is_dfs_for_freq(v25[1], v97, v150, v151, v152, v153, v154, v155, v156, v157) & 1) != 0
                            && (_DWORD)v97 == *(_DWORD *)(v41 + 2152) )
                          {
                            qdf_trace_msg(
                              0x33u,
                              8u,
                              "%s: sta freq allow with running dfs sap %d",
                              v158,
                              v159,
                              v160,
                              v161,
                              v162,
                              v163,
                              v164,
                              v165,
                              "wlan_hdd_cm_handle_sap_sta_dfs_conc",
                              (unsigned int)v97);
                            goto LABEL_107;
                          }
                          next_lower_bandwidth = *(_DWORD *)(v41 + 744);
                          v167 = (unsigned int *)(v41 + 744);
                          ap_6ghz_capable = policy_mgr_get_ap_6ghz_capable(*v25, *(unsigned __int8 *)(v41 + 8), nullptr);
                          if ( (wlan_reg_is_dfs_for_freq(v25[1], v97, v169, v170, v171, v172, v173, v174, v175, v176) & 1) == 0
                            && (((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(
                                  *v25,
                                  (unsigned int)v97)
                              & 1) != 0
                            && (wlan_reg_is_passive_for_freq(
                                  v25[1],
                                  v97,
                                  v177,
                                  v178,
                                  v179,
                                  v180,
                                  v181,
                                  v182,
                                  v183,
                                  v184)
                              & 1) == 0
                            && ap_6ghz_capable | !wlan_reg_is_6ghz_chan_freq(v97) )
                          {
LABEL_94:
                            if ( wlan_reg_is_5ghz_ch_freq(v97) && next_lower_bandwidth )
                            {
                              v248 = 0;
                              v249 = 0;
                              qdf_mem_set(&v248, 0x10u, 0);
                              v185 = v25[1];
                              LODWORD(v248) = next_lower_bandwidth;
                              _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                                                       v185,
                                                                       v97,
                                                                       (unsigned int *)&v248,
                                                                       0,
                                                                       v186,
                                                                       v187,
                                                                       v188,
                                                                       v189,
                                                                       v190,
                                                                       v191,
                                                                       v192,
                                                                       v193);
                              do
                              {
                                if ( _5g_bonded_channel_state_for_pwrmode == 3 )
                                  break;
                                next_lower_bandwidth = wlan_reg_get_next_lower_bandwidth();
                                v203 = v25[1];
                                LODWORD(v248) = next_lower_bandwidth;
                                _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                                                         v203,
                                                                         v97,
                                                                         (unsigned int *)&v248,
                                                                         0,
                                                                         v204,
                                                                         v205,
                                                                         v206,
                                                                         v207,
                                                                         v208,
                                                                         v209,
                                                                         v210,
                                                                         v211);
                              }
                              while ( next_lower_bandwidth );
                              qdf_trace_msg(
                                0x33u,
                                8u,
                                "%s: bw change from %d to %d",
                                v195,
                                v196,
                                v197,
                                v198,
                                v199,
                                v200,
                                v201,
                                v202,
                                "wlan_hdd_cm_handle_sap_sta_dfs_conc",
                                *v167,
                                next_lower_bandwidth,
                                v26,
                                v246);
                            }
                            v26 = v245;
                            a11 = v246;
                            qdf_event_reset(v41 + 88);
                            wlan_hdd_set_sap_csa_reason(*v25, *(unsigned __int8 *)(v41 + 8), 1);
                            if ( (unsigned int)hdd_softap_set_channel_change(
                                                 v41,
                                                 (unsigned int)v97,
                                                 0,
                                                 next_lower_bandwidth,
                                                 0,
                                                 0,
                                                 1)
                              && *(int *)(v41 + 2348) < 2 )
                            {
                              v88 = "%s: Set channel with CSA IE failed, can't allow STA";
                            }
                            else
                            {
                              if ( !(unsigned int)qdf_wait_for_event_completion(v41 + 88, 0x2710u) )
                                goto LABEL_107;
                              v88 = "%s: wait for qdf_event failed, STA not allowed!!";
                            }
LABEL_59:
                            qdf_trace_msg(
                              0x33u,
                              2u,
                              v88,
                              v80,
                              v81,
                              v82,
                              v83,
                              v84,
                              v85,
                              v86,
                              v87,
                              "wlan_hdd_cm_handle_sap_sta_dfs_conc",
                              v245,
                              v246);
                            v22 = "%s: sap-sta conc will fail, can't allow sta";
LABEL_3:
                            qdf_trace_msg(
                              0x33u,
                              2u,
                              v22,
                              v14,
                              v15,
                              v16,
                              v17,
                              v18,
                              v19,
                              v20,
                              v21,
                              "wlan_hdd_cm_connect",
                              v245,
                              v246);
                            goto LABEL_5;
                          }
                        }
                        else
                        {
                          if ( (_DWORD)v97 )
                            goto LABEL_83;
                          next_lower_bandwidth = *(_DWORD *)(v41 + 744);
                          v167 = (unsigned int *)(v41 + 744);
                        }
                        LODWORD(v97) = policy_mgr_get_nondfs_preferred_channel(
                                         *v25,
                                         1u,
                                         1,
                                         *(unsigned __int8 *)(v41 + 8));
                        goto LABEL_94;
                      }
                    }
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Can not get active channel",
                      v53,
                      v54,
                      v55,
                      v56,
                      v57,
                      v58,
                      v59,
                      v60,
                      "hdd_get_sap_link_info_of_dfs");
                    wlan_objmgr_vdev_release_ref(*(_QWORD *)(v41 + 32), 5u, v71, v72, v73, v74, v75, v76, v77, v78, v79);
                  }
                }
                v39 = v251;
                if ( v251 )
                {
                  if ( (unsigned __int8)~(-910593773 * ((unsigned int)(v41 - *(_DWORD *)v41 - 52832) >> 4))
                    || (*(_QWORD *)(v251 + 1640) & 1) == 0 )
                  {
                    break;
                  }
                  v41 = v251 + 52832;
                }
              }
              while ( v41 );
            }
          }
          hdd_adapter_dev_put_debug(v39, 25);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v40 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v40 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v25 + 4);
          }
          else
          {
            raw_spin_lock_bh(v25 + 4);
            v25[5] |= 1uLL;
          }
          v251 = v250;
          hdd_get_next_adapter_no_lock(v25, v250, &v250);
          hdd_validate_next_adapter(&v251, &v250, 25);
          if ( v250 )
            hdd_adapter_dev_hold_debug(v250, 25);
          v42 = v25[5];
          if ( (v42 & 1) != 0 )
            break;
          raw_spin_unlock(v25 + 4);
          v39 = v251;
          if ( !v251 )
            goto LABEL_106;
        }
        v25[5] = v42 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v25 + 4);
        v39 = v251;
      }
      while ( v251 );
LABEL_106:
      a11 = v246;
    }
LABEL_107:
    if ( *(_QWORD *)a11 )
    {
      v212 = *(_DWORD *)(*(_QWORD *)a11 + 4LL);
      if ( v212 )
      {
        if ( wlan_reg_is_6ghz_chan_freq(v212)
          && (wlan_reg_is_6ghz_band_set(v25[1], v213, v214, v215, v216, v217, v218, v219, v220) & 1) == 0 )
        {
          v22 = "%s: 6 GHz band disabled";
          goto LABEL_3;
        }
      }
    }
    qdf_mem_set(&v252, 0x20u, 0);
    ucfg_dlm_dump_deny_list_ap(v25[1]);
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a10 + 55512), 88, "wlan_hdd_cm_connect");
    if ( vdev_by_user )
    {
      v222 = vdev_by_user;
      v223 = (_WORD *)(a10 + 42312);
      ucfg_pmo_flush_gtk_offload_req();
      qdf_mem_set((void *)(v26 + 763), 1u, 0);
      *(_WORD *)(v26 + 685) = 0;
      *(_DWORD *)(a10 + 55088) = 0;
      qdf_runtime_pm_prevent_suspend(v25 + 208);
      hdd_prevent_suspend_timeout(6000, 19);
      v224 = (_DWORD *)v25[13];
      LOBYTE(v254) = *((_BYTE *)v25 + 3284);
      v225 = *v224 - 6;
      v226 = 0;
      if ( v225 <= 5 )
        v226 = dword_A0567C[v225];
      v227 = *(_DWORD *)(a10 + 2728);
      HIDWORD(v254) = v226;
      if ( v227 != 2 )
      {
        if ( *(_QWORD *)(a10 + 44368) )
        {
          v253 = *(_QWORD *)(a10 + 44368);
          v223 = (_WORD *)(a10 + 44376);
          goto LABEL_118;
        }
        if ( !*v223 )
        {
LABEL_119:
          v228 = osif_cm_connect(a10, v222, a11, (__int64)&v252);
          if ( v228 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Vdev %d connect failed status %d",
              v229,
              v230,
              v231,
              v232,
              v233,
              v234,
              v235,
              v236,
              "wlan_hdd_cm_connect",
              *(unsigned __int8 *)(*(_QWORD *)(a10 + 55512) + 8LL),
              v228);
          }
          else
          {
            if ( !ucfg_cm_is_vdev_roaming(v222, v229, v230, v231, v232, v233, v234, v235, v236) )
            {
LABEL_124:
              _hdd_objmgr_put_vdev_by_user(v222, 88, "wlan_hdd_cm_connect");
              result = v228;
              *(_QWORD *)(a10 + 60128) = 0;
              goto LABEL_6;
            }
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Vdev %d: connect lead to roam invoke",
              v237,
              v238,
              v239,
              v240,
              v241,
              v242,
              v243,
              v244,
              "wlan_hdd_cm_connect",
              *(unsigned __int8 *)(*(_QWORD *)(a10 + 55512) + 8LL));
          }
          qdf_runtime_pm_allow_suspend(v25 + 208);
          hdd_allow_suspend(19);
          goto LABEL_124;
        }
      }
      v253 = a10 + 42314;
LABEL_118:
      LODWORD(v252) = (unsigned __int16)*v223;
      goto LABEL_119;
    }
LABEL_5:
    result = 4294967274LL;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
