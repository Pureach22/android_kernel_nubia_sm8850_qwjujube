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
  __int64 v23; // x27
  __int64 result; // x0
  unsigned int v25; // w0
  _QWORD *v26; // x21
  __int64 v27; // x28
  unsigned __int64 StatusReg; // x8
  __int64 v29; // x1
  const char *v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x8
  __int64 v40; // x0
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
  __int64 v51; // x8
  __int64 v52; // x9
  __int64 v53; // x10
  __int64 active_channel; // x0
  unsigned int *v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  unsigned __int16 *v64; // x25
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  unsigned int *v73; // x8
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  const char *v90; // x2
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x23
  __int64 v100; // x0
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  __int64 v117; // x8
  _QWORD *v118; // x24
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  char is_hw_sbs_capable; // w0
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  unsigned int next_lower_bandwidth; // w24
  unsigned int *v169; // x20
  bool ap_6ghz_capable; // w25
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  __int64 v187; // x0
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  int _5g_bonded_channel_state_for_pwrmode; // w0
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  __int64 v205; // x0
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  int v214; // w0
  double v215; // d0
  double v216; // d1
  double v217; // d2
  double v218; // d3
  double v219; // d4
  double v220; // d5
  double v221; // d6
  double v222; // d7
  __int64 vdev_by_user; // x0
  __int64 v224; // x22
  _WORD *v225; // x20
  int v226; // w24
  int *v227; // x9
  int v228; // w8
  int v229; // w8
  unsigned int v230; // w20
  double v231; // d0
  double v232; // d1
  double v233; // d2
  double v234; // d3
  double v235; // d4
  double v236; // d5
  double v237; // d6
  double v238; // d7
  double v239; // d0
  double v240; // d1
  double v241; // d2
  double v242; // d3
  double v243; // d4
  double v244; // d5
  double v245; // d6
  double v246; // d7
  unsigned __int64 v247; // [xsp+20h] [xbp-60h]
  __int64 v248; // [xsp+28h] [xbp-58h] BYREF
  __int64 v249; // [xsp+30h] [xbp-50h] BYREF
  __int64 v250; // [xsp+38h] [xbp-48h]
  __int64 v251; // [xsp+40h] [xbp-40h]
  __int64 v252; // [xsp+48h] [xbp-38h] BYREF
  __int64 v253; // [xsp+50h] [xbp-30h] BYREF
  __int64 v254; // [xsp+58h] [xbp-28h] BYREF
  __int64 v255; // [xsp+60h] [xbp-20h]
  __int64 v256; // [xsp+68h] [xbp-18h]
  __int64 v257; // [xsp+70h] [xbp-10h]
  __int64 v258; // [xsp+78h] [xbp-8h]

  v258 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v256 = 0;
  v257 = 0;
  v254 = 0;
  v255 = 0;
  v13 = qdf_trace_msg(0x33u, 8u, "%s: enter", a1, a2, a3, a4, a5, a6, a7, a8, "wlan_hdd_cm_connect");
  if ( (unsigned int)hdd_get_conparam(v13) == 5 )
  {
    v22 = "%s: Command not allowed in FTM mode";
    goto LABEL_3;
  }
  v23 = a10 + 55088;
  if ( (unsigned int)_wlan_hdd_validate_vdev_id(
                       *(unsigned __int8 *)(*(_QWORD *)(a10 + 55520) + 8LL),
                       "wlan_hdd_cm_connect") )
    goto LABEL_5;
  qdf_mtrace(51, 51, 0x21u, *(_BYTE *)(*(_QWORD *)(a10 + 55520) + 8LL), *(_DWORD *)(a10 + 2728));
  v25 = *(_DWORD *)(a10 + 2728);
  if ( (v25 | 2) != 2 )
  {
    v30 = qdf_opmode_str(v25);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Device_mode %s(%d) is not supported",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "wlan_hdd_cm_connect",
      v30,
      *(unsigned int *)(a10 + 2728));
    goto LABEL_5;
  }
  v26 = *(_QWORD **)(a10 + 2712);
  v27 = *(_QWORD *)(a10 + 55520);
  result = _wlan_hdd_validate_context(v26, "wlan_hdd_cm_connect");
  if ( !(_DWORD)result )
  {
    hdd_reg_wait_for_country_change(v26);
    if ( (policy_mgr_is_hw_dbs_capable(*v26) & 1) != 0 )
    {
      v248 = 0;
      v249 = 0;
      v252 = 0;
      v253 = 0;
      v250 = 0;
      v251 = 0;
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v26 + 4);
      }
      else
      {
        raw_spin_lock_bh(v26 + 4);
        v26[5] |= 1uLL;
      }
      hdd_get_front_adapter_no_lock(v26, &v253);
      if ( v253 )
      {
        hdd_adapter_dev_hold_debug(v253, 25);
        v29 = v253;
      }
      else
      {
        v29 = 0;
      }
      hdd_get_next_adapter_no_lock(v26, v29, &v252);
      if ( v252 )
        hdd_adapter_dev_hold_debug(v252, 25);
      v39 = v26[5];
      if ( (v39 & 1) != 0 )
      {
        v26[5] = v39 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v26 + 4);
        v40 = v253;
        if ( !v253 )
          goto LABEL_115;
      }
      else
      {
        raw_spin_unlock(v26 + 4);
        v40 = v253;
        if ( !v253 )
          goto LABEL_115;
      }
      v247 = _ReadStatusReg(SP_EL0);
      do
      {
        while ( 1 )
        {
          if ( *(_DWORD *)(v40 + 40) == 1 )
          {
            if ( (*(_QWORD *)(v40 + 1640) & 1) != 0 && (v41 = v40 + 52840, v40 != -52840)
              || (v41 = v40 + 58928, v40 != -58928) && (*(_QWORD *)(v40 + 1640) & 2) != 0
              || (v41 = v40 + 65016, v40 != -65016) && (*(_QWORD *)(v40 + 1640) & 4) != 0 )
            {
              do
              {
                if ( !(unsigned int)_wlan_hdd_validate_vdev_id(
                                      *(unsigned __int8 *)(v41 + 8),
                                      "hdd_get_sap_link_info_of_dfs")
                  && ((*(_QWORD *)(v41 + 5968) & 2) != 0 || *((_BYTE *)v26 + 912) == 1) )
                {
                  wlan_objmgr_vdev_get_ref(*(_QWORD *)(v41 + 32), 5u, v43, v44, v45, v46, v47, v48, v49, v50);
                  active_channel = wlan_vdev_get_active_channel(*(_QWORD *)(v41 + 32));
                  if ( active_channel )
                  {
                    v64 = (unsigned __int16 *)active_channel;
                    wlan_objmgr_vdev_release_ref(*(_QWORD *)(v41 + 32), 5u, v55, v56, v57, v58, v59, v60, v61, v62, v63);
                    if ( wlan_reg_is_5ghz_ch_freq(*v64) )
                    {
                      LODWORD(v249) = *((_DWORD *)v64 + 6);
                      if ( (_DWORD)v249 == 3 )
                        wlan_reg_set_create_punc_bitmap((__int64)&v249, 1);
                      if ( (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                           v26[1],
                                           *v64,
                                           (int *)&v249,
                                           0,
                                           v65,
                                           v66,
                                           v67,
                                           v68,
                                           v69,
                                           v70,
                                           v71,
                                           v72) == 2 )
                      {
                        hdd_adapter_dev_put_debug(v253, 25);
                        if ( v252 )
                          hdd_adapter_dev_put_debug(v252, 25);
                        v23 = a10 + 55088;
                        if ( *((_BYTE *)v26 + 912) == 1 )
                        {
                          v90 = "%s: Concurrent SAP is in CAC state, STA is not allowed";
                          goto LABEL_67;
                        }
                        if ( v41 == -80 )
                        {
                          v90 = "%s: AP context not found";
                          goto LABEL_67;
                        }
                        if ( (policy_mgr_is_sta_sap_scc(*v26, *(_DWORD *)(v41 + 2424), 0) & 1) != 0 )
                        {
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: DFS SAP is already in SCC with STA",
                            v91,
                            v92,
                            v93,
                            v94,
                            v95,
                            v96,
                            v97,
                            v98,
                            "wlan_hdd_cm_handle_sap_sta_dfs_conc");
                          goto LABEL_116;
                        }
                        if ( !*(_QWORD *)a11 || (LODWORD(v99) = *(_DWORD *)(*(_QWORD *)a11 + 4LL), !(_DWORD)v99) )
                        {
                          v100 = _qdf_mem_malloc(0x2D8u, "wlan_hdd_cm_handle_sap_sta_dfs_conc", 736);
                          v99 = v100;
                          if ( v100 )
                          {
                            if ( *(_QWORD *)(a11 + 16) )
                            {
                              *(_BYTE *)(v100 + 16) = 1;
                              qdf_mem_copy((void *)(v100 + 70), *(const void **)(a11 + 16), 6u);
                            }
                            if ( *(_QWORD *)(a11 + 40) < 0x21u )
                            {
                              *(_BYTE *)(v99 + 17) = 1;
                              v117 = *(_QWORD *)(a11 + 40);
                              *(_BYTE *)(v99 + 100) = v117;
                              qdf_mem_copy((void *)(v99 + 101), *(const void **)(a11 + 32), (unsigned __int8)v117);
                            }
                            else
                            {
                              *(_BYTE *)(v99 + 17) = 0;
                              qdf_trace_msg(
                                0x33u,
                                2u,
                                "%s: req ssid len invalid %zu",
                                v101,
                                v102,
                                v103,
                                v104,
                                v105,
                                v106,
                                v107,
                                v108,
                                "wlan_hdd_cm_handle_sap_sta_dfs_conc",
                                *(_QWORD *)(a11 + 40));
                            }
                            *(_WORD *)v99 |= 8u;
                            v118 = ucfg_scan_get_result(v26[1], v99, v109, v110, v111, v112, v113, v114, v115, v116);
                            _qdf_mem_free(v99);
                            if ( v118 )
                            {
                              if ( *((_DWORD *)v118 + 4) )
                              {
                                qdf_list_peek_front(v118, &v248);
                                if ( v248 )
                                {
                                  LODWORD(v99) = *(_DWORD *)(*(_QWORD *)(v248 + 24) + 1192LL);
                                  goto LABEL_83;
                                }
                              }
                              else
                              {
                                qdf_trace_msg(
                                  0x33u,
                                  8u,
                                  "%s: scan list empty",
                                  v119,
                                  v120,
                                  v121,
                                  v122,
                                  v123,
                                  v124,
                                  v125,
                                  v126,
                                  "wlan_hdd_cm_handle_sap_sta_dfs_conc");
                              }
                              LODWORD(v99) = 0;
LABEL_83:
                              ucfg_scan_purge_results((__int64)v118, v127, v128, v129, v130, v131, v132, v133, v134);
                            }
                            else
                            {
                              qdf_trace_msg(
                                0x33u,
                                8u,
                                "%s: scan list empty",
                                v119,
                                v120,
                                v121,
                                v122,
                                v123,
                                v124,
                                v125,
                                v126,
                                "wlan_hdd_cm_handle_sap_sta_dfs_conc");
                              LODWORD(v99) = 0;
                            }
                          }
                        }
                        if ( wlan_reg_is_24ghz_ch_freq(v99) )
                        {
                          qdf_trace_msg(
                            0x33u,
                            4u,
                            "%s: sap is on dfs, new sta conn on 2.4 is allowed",
                            v135,
                            v136,
                            v137,
                            v138,
                            v139,
                            v140,
                            v141,
                            v142,
                            "wlan_hdd_cm_handle_sap_sta_dfs_conc");
                          goto LABEL_116;
                        }
                        is_hw_sbs_capable = policy_mgr_is_hw_sbs_capable(*v26);
                        if ( (_DWORD)v99 && (is_hw_sbs_capable & 1) != 0 )
                        {
                          if ( (policy_mgr_are_sbs_chan(*v26, v99, *(_DWORD *)(v41 + 2424)) & 1) != 0 )
                          {
                            qdf_trace_msg(
                              0x33u,
                              8u,
                              "%s: sta freq %d sap freq %d in sbs mode is allowed",
                              v144,
                              v145,
                              v146,
                              v147,
                              v148,
                              v149,
                              v150,
                              v151,
                              "wlan_hdd_cm_handle_sap_sta_dfs_conc",
                              (unsigned int)v99,
                              *(unsigned int *)(v41 + 2424));
                            goto LABEL_116;
                          }
LABEL_91:
                          if ( policy_mgr_is_sta_sap_scc_allowed_on_dfs_chan(*v26)
                            && (wlan_reg_is_dfs_for_freq(v26[1], v99, v152, v153, v154, v155, v156, v157, v158, v159) & 1) != 0
                            && (_DWORD)v99 == *(_DWORD *)(v41 + 2424) )
                          {
                            qdf_trace_msg(
                              0x33u,
                              8u,
                              "%s: sta freq allow with running dfs sap %d",
                              v160,
                              v161,
                              v162,
                              v163,
                              v164,
                              v165,
                              v166,
                              v167,
                              "wlan_hdd_cm_handle_sap_sta_dfs_conc",
                              (unsigned int)v99);
                            goto LABEL_116;
                          }
                          next_lower_bandwidth = *(_DWORD *)(v41 + 752);
                          v169 = (unsigned int *)(v41 + 752);
                          ap_6ghz_capable = policy_mgr_get_ap_6ghz_capable(*v26, *(unsigned __int8 *)(v41 + 8), nullptr);
                          if ( (wlan_reg_is_dfs_for_freq(v26[1], v99, v171, v172, v173, v174, v175, v176, v177, v178) & 1) == 0
                            && (((__int64 (__fastcall *)(_QWORD, _QWORD))policy_mgr_is_safe_channel)(
                                  *v26,
                                  (unsigned int)v99)
                              & 1) != 0 )
                          {
                            if ( (wlan_reg_is_passive_for_freq(
                                    v26[1],
                                    v99,
                                    v179,
                                    v180,
                                    v181,
                                    v182,
                                    v183,
                                    v184,
                                    v185,
                                    v186)
                                & 1) != 0 )
                            {
                              v23 = a10 + 55088;
                              goto LABEL_100;
                            }
                            v23 = a10 + 55088;
                            if ( ap_6ghz_capable | !wlan_reg_is_6ghz_chan_freq(v99) )
                            {
LABEL_101:
                              if ( wlan_reg_is_5ghz_ch_freq(v99) && next_lower_bandwidth )
                              {
                                v250 = 0;
                                v251 = 0;
                                v249 = 0;
                                qdf_mem_set(&v249, 0x18u, 0);
                                v187 = v26[1];
                                LODWORD(v249) = next_lower_bandwidth;
                                _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                                                         v187,
                                                                         v99,
                                                                         (int *)&v249,
                                                                         0,
                                                                         v188,
                                                                         v189,
                                                                         v190,
                                                                         v191,
                                                                         v192,
                                                                         v193,
                                                                         v194,
                                                                         v195);
                                do
                                {
                                  if ( _5g_bonded_channel_state_for_pwrmode == 3 )
                                    break;
                                  next_lower_bandwidth = wlan_reg_get_next_lower_bandwidth(next_lower_bandwidth);
                                  v205 = v26[1];
                                  LODWORD(v249) = next_lower_bandwidth;
                                  _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                                                           v205,
                                                                           v99,
                                                                           (int *)&v249,
                                                                           0,
                                                                           v206,
                                                                           v207,
                                                                           v208,
                                                                           v209,
                                                                           v210,
                                                                           v211,
                                                                           v212,
                                                                           v213);
                                }
                                while ( next_lower_bandwidth );
                                qdf_trace_msg(
                                  0x33u,
                                  8u,
                                  "%s: bw change from %d to %d",
                                  v197,
                                  v198,
                                  v199,
                                  v200,
                                  v201,
                                  v202,
                                  v203,
                                  v204,
                                  "wlan_hdd_cm_handle_sap_sta_dfs_conc",
                                  *v169,
                                  next_lower_bandwidth);
                              }
                              qdf_event_reset(v41 + 88);
                              wlan_hdd_set_sap_csa_reason(*v26, *(unsigned __int8 *)(v41 + 8), 1);
                              if ( (unsigned int)hdd_softap_set_channel_change(
                                                   v41,
                                                   (unsigned int)v99,
                                                   0,
                                                   next_lower_bandwidth,
                                                   0,
                                                   0,
                                                   1)
                                && *(int *)(v41 + 2620) < 2 )
                              {
                                v90 = "%s: Set channel with CSA IE failed, can't allow STA";
                              }
                              else
                              {
                                if ( !(unsigned int)qdf_wait_for_event_completion(v41 + 88, 0x2710u) )
                                  goto LABEL_116;
                                v90 = "%s: wait for qdf_event failed, STA not allowed!!";
                              }
LABEL_67:
                              qdf_trace_msg(
                                0x33u,
                                2u,
                                v90,
                                v82,
                                v83,
                                v84,
                                v85,
                                v86,
                                v87,
                                v88,
                                v89,
                                "wlan_hdd_cm_handle_sap_sta_dfs_conc");
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
                                "wlan_hdd_cm_connect");
                              goto LABEL_5;
                            }
                          }
                        }
                        else
                        {
                          if ( (_DWORD)v99 )
                            goto LABEL_91;
                          next_lower_bandwidth = *(_DWORD *)(v41 + 752);
                          v169 = (unsigned int *)(v41 + 752);
                        }
LABEL_100:
                        LODWORD(v99) = policy_mgr_get_nondfs_preferred_channel(
                                         *v26,
                                         1u,
                                         1,
                                         *(unsigned __int8 *)(v41 + 8));
                        goto LABEL_101;
                      }
                    }
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x33u,
                      8u,
                      "%s: Can not get active channel",
                      v56,
                      v57,
                      v58,
                      v59,
                      v60,
                      v61,
                      v62,
                      v63,
                      "hdd_get_sap_link_info_of_dfs");
                    wlan_objmgr_vdev_release_ref(*(_QWORD *)(v41 + 32), 5u, v73, v74, v75, v76, v77, v78, v79, v80, v81);
                  }
                }
                v40 = v253;
                if ( v253 )
                {
                  if ( (unsigned __int8)(73 * ((unsigned int)(v41 - *(_DWORD *)v41 - 52840) >> 3) + 1) > 2u )
                    break;
                  v51 = (unsigned __int8)(73 * ((unsigned int)(v41 - *(_DWORD *)v41 - 52840) >> 3) + 1);
                  v41 = 0;
                  v52 = v253 + 6088LL * (unsigned int)v51 + 52840;
                  do
                  {
                    if ( v41 )
                      break;
                    v53 = *(_QWORD *)(v253 + 1640) >> v51++;
                    v41 = (v53 << 63 >> 63) & v52;
                    v52 += 6088;
                  }
                  while ( v51 != 3 );
                }
              }
              while ( v41 );
            }
          }
          hdd_adapter_dev_put_debug(v40, 25);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(v247 + 16) & 0xF0000) != 0
            || (*(_DWORD *)(v247 + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v26 + 4);
          }
          else
          {
            raw_spin_lock_bh(v26 + 4);
            v26[5] |= 1uLL;
          }
          v253 = v252;
          hdd_get_next_adapter_no_lock(v26, v252, &v252);
          hdd_validate_next_adapter(&v253, &v252, 25);
          if ( v252 )
            hdd_adapter_dev_hold_debug(v252, 25);
          v42 = v26[5];
          if ( (v42 & 1) != 0 )
            break;
          raw_spin_unlock(v26 + 4);
          v40 = v253;
          if ( !v253 )
            goto LABEL_115;
        }
        v26[5] = v42 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v26 + 4);
        v40 = v253;
      }
      while ( v253 );
LABEL_115:
      v23 = a10 + 55088;
    }
LABEL_116:
    if ( *(_QWORD *)a11 )
    {
      v214 = *(_DWORD *)(*(_QWORD *)a11 + 4LL);
      if ( v214 )
      {
        if ( wlan_reg_is_6ghz_chan_freq(v214)
          && (wlan_reg_is_6ghz_band_set(v26[1], v215, v216, v217, v218, v219, v220, v221, v222) & 1) == 0 )
        {
          v22 = "%s: 6 GHz band disabled";
          goto LABEL_3;
        }
      }
    }
    qdf_mem_set(&v254, 0x20u, 0);
    ucfg_dlm_dump_deny_list_ap(v26[1]);
    vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(v23 + 432), 88, "wlan_hdd_cm_connect");
    if ( vdev_by_user )
    {
      v224 = vdev_by_user;
      v225 = (_WORD *)(a10 + 42312);
      ucfg_pmo_flush_gtk_offload_req();
      v226 = 1;
      qdf_mem_set((void *)(v27 + 771), 1u, 0);
      *(_WORD *)(v27 + 693) = 0;
      *(_DWORD *)v23 = 0;
      qdf_runtime_pm_prevent_suspend(v26 + 208);
      hdd_prevent_suspend_timeout(6000, 19);
      v227 = (int *)v26[13];
      LOBYTE(v256) = *((_BYTE *)v26 + 3284);
      v228 = *v227;
      if ( *v227 != 6 )
      {
        if ( v228 == 11 )
        {
          v226 = 3;
        }
        else if ( v228 == 8 )
        {
          v226 = 2;
        }
        else
        {
          v226 = 4 * (v228 == 14);
        }
      }
      v229 = *(_DWORD *)(a10 + 2728);
      HIDWORD(v256) = v226;
      if ( v229 != 2 )
      {
        if ( *(_QWORD *)(a10 + 44368) )
        {
          v255 = *(_QWORD *)(a10 + 44368);
          v225 = (_WORD *)(a10 + 44376);
          goto LABEL_131;
        }
        if ( !*v225 )
        {
LABEL_132:
          hdd_update_action_oui_for_connect(v26, a11);
          v230 = osif_cm_connect(a10, v224, a11, (__int64)&v254);
          if ( v230 )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Vdev %d connect failed status %d",
              v231,
              v232,
              v233,
              v234,
              v235,
              v236,
              v237,
              v238,
              "wlan_hdd_cm_connect",
              *(unsigned __int8 *)(*(_QWORD *)(v23 + 432) + 8LL),
              v230);
          }
          else
          {
            if ( !ucfg_cm_is_vdev_roaming(v224, v231, v232, v233, v234, v235, v236, v237, v238) )
            {
LABEL_137:
              _hdd_objmgr_put_vdev_by_user(v224, 88, "wlan_hdd_cm_connect");
              result = v230;
              *(_QWORD *)(a10 + 73880) = 0;
              goto LABEL_6;
            }
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Vdev %d: connect lead to roam invoke",
              v239,
              v240,
              v241,
              v242,
              v243,
              v244,
              v245,
              v246,
              "wlan_hdd_cm_connect",
              *(unsigned __int8 *)(*(_QWORD *)(v23 + 432) + 8LL));
          }
          qdf_runtime_pm_allow_suspend(v26 + 208);
          hdd_allow_suspend(19);
          goto LABEL_137;
        }
      }
      v255 = a10 + 42314;
LABEL_131:
      LODWORD(v254) = (unsigned __int16)*v225;
      goto LABEL_132;
    }
LABEL_5:
    result = 4294967274LL;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
