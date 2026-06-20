__int64 __fastcall cm_fw_roam_sync_propagation(
        __int64 a1,
        unsigned int a2,
        unsigned __int16 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x23
  __int64 session_by_vdev_id; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x26
  __int64 v34; // x0
  __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x27
  __int64 v45; // x19
  __int64 cm_ctx_fl; // x0
  __int64 first_roam_command; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  unsigned int *v56; // x21
  unsigned int v57; // w28
  _QWORD *v58; // x0
  __int64 v59; // x8
  __int64 v60; // x21
  __int64 v61; // x8
  __int64 v62; // x0
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  unsigned __int16 v71; // w9
  unsigned int v72; // w25
  int v73; // w9
  __int64 v74; // x8
  __int64 result; // x0
  unsigned int v76; // w23
  __int64 cmpt_obj; // x0
  __int64 v78; // x0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  size_t v87; // x2
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  char v96; // w8
  size_t v97; // x0
  void *v98; // x0
  size_t v99; // x0
  void *v100; // x0
  size_t v101; // x0
  __int64 v102; // x25
  void *v103; // x0
  size_t v104; // x0
  __int64 v105; // x25
  void *v106; // x0
  unsigned int v107; // w25
  size_t v108; // x0
  void *v109; // x0
  unsigned int v110; // w8
  size_t v111; // x0
  __int64 v112; // x25
  void *v113; // x0
  __int64 v114; // x0
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  unsigned __int16 *v123; // x25
  __int64 v124; // x25
  size_t v125; // x2
  int v126; // w8
  size_t v127; // x2
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  int v136; // w9
  __int64 v137; // x8
  __int64 v138; // x0
  int v139; // w25
  __int64 fils_connection_info; // x0
  const char *v141; // x2
  __int64 v142; // x5
  const char *v143; // x2
  __int64 v144; // x4
  __int64 v145; // x8
  int v146; // w9
  __int64 v147; // x10
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  int v157; // w1
  double updated; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  unsigned int v166; // w0
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  const char *v175; // x2
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  double v192; // d0
  double v193; // d1
  double v194; // d2
  double v195; // d3
  double v196; // d4
  double v197; // d5
  double v198; // d6
  double v199; // d7
  double v200; // d0
  double v201; // d1
  double v202; // d2
  double v203; // d3
  double v204; // d4
  double v205; // d5
  double v206; // d6
  double v207; // d7
  char tdls_chan_switch_prohibited; // w25
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  char tdls_prohibited; // w0
  double v218; // d0
  double v219; // d1
  double v220; // d2
  double v221; // d3
  double v222; // d4
  double v223; // d5
  double v224; // d6
  double v225; // d7
  double v226; // d0
  double v227; // d1
  double v228; // d2
  double v229; // d3
  double v230; // d4
  double v231; // d5
  double v232; // d6
  double v233; // d7
  double v234; // d0
  double v235; // d1
  double v236; // d2
  double v237; // d3
  double v238; // d4
  double v239; // d5
  double v240; // d6
  double v241; // d7
  unsigned int v242; // w0
  double v243; // d0
  double v244; // d1
  double v245; // d2
  double v246; // d3
  double v247; // d4
  double v248; // d5
  double v249; // d6
  double v250; // d7
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  double v259; // d0
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  unsigned int v267; // w0
  __int64 v268; // [xsp+10h] [xbp-30h]
  int v269[2]; // [xsp+18h] [xbp-28h]
  __int64 *v270; // [xsp+28h] [xbp-18h]
  bool v271; // [xsp+30h] [xbp-10h] BYREF
  unsigned int v272; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v273; // [xsp+38h] [xbp-8h]

  v273 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v272 = 0;
  v271 = 0;
  context = _cds_get_context(53, (__int64)"cm_fw_roam_sync_propagation", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( context )
  {
    v23 = (__int64)context;
    session_by_vdev_id = pe_find_session_by_vdev_id((__int64)context, a2, v15, v16, v17, v18, v19, v20, v21, v22);
    if ( session_by_vdev_id )
    {
      v33 = session_by_vdev_id;
      v34 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 1);
      if ( v34 )
      {
        v44 = *(_QWORD *)(v34 + 152);
        v45 = v34;
        if ( v44
          && (cm_ctx_fl = cm_get_cm_ctx_fl(
                            v34,
                            (__int64)"cm_fw_roam_sync_propagation",
                            0x4FCu,
                            v36,
                            v37,
                            v38,
                            v39,
                            v40,
                            v41,
                            v42,
                            v43)) != 0 )
        {
          v270 = (__int64 *)cm_ctx_fl;
          first_roam_command = cm_get_first_roam_command(v45, v36, v37, v38, v39, v40, v41, v42, v43);
          if ( first_roam_command )
          {
            v56 = (unsigned int *)first_roam_command;
            wlan_rec_debug_log((char *)&off_0 + 1, a2, 0x13u, 0, a3 + 7, 0, 0, 0);
            v57 = *v56;
            v272 = *v56;
            v58 = (_QWORD *)_qdf_mem_malloc(0xD0u, "cm_fw_roam_sync_propagation", 1296);
            if ( v58 )
            {
              v59 = *(_QWORD *)(v45 + 152);
              v60 = (__int64)v58;
              if ( v59 )
              {
                v61 = *(_QWORD *)(v59 + 80);
                *v58 = v61;
                if ( v61 )
                {
                  v62 = _qdf_mem_malloc(0xC8u, "cm_fill_roam_info", 816);
                  *(_QWORD *)(v60 + 152) = v62;
                  if ( !v62 )
                    goto LABEL_67;
                  *(_BYTE *)(v60 + 8) = *(_BYTE *)(v45 + 104);
                  v71 = a3[9];
                  *(_DWORD *)(v60 + 16) = *(_DWORD *)(a3 + 7);
                  *(_WORD *)(v60 + 20) = v71;
                  *(_DWORD *)(v60 + 56) = *((_DWORD *)a3 + 16);
                  v72 = *((unsigned __int8 *)a3 + 20);
                  if ( *((_BYTE *)a3 + 20) )
                  {
                    v73 = *((unsigned __int8 *)a3 + 21);
                    if ( *((_BYTE *)a3 + 21) )
                    {
                      v74 = 0;
                      while ( (v73 | 0x20) == 0x20 )
                      {
                        if ( v72 - 1 == (_DWORD)v74 )
                          goto LABEL_30;
                        v73 = *((unsigned __int8 *)a3 + v74++ + 22);
                      }
                      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v45, v63, v64, v65, v66, v67, v68, v69, v70);
                      if ( cmpt_obj )
                      {
                        if ( v72 > 0x20 )
                        {
                          LOBYTE(v72) = 0;
                        }
                        else
                        {
                          v268 = cmpt_obj;
                          qdf_mem_copy((void *)(cmpt_obj + 129), (char *)a3 + 21, v72);
                          cmpt_obj = v268;
                        }
                        *(_BYTE *)(cmpt_obj + 162) = v72;
                      }
                    }
                  }
LABEL_30:
                  v78 = wlan_vdev_mlme_get_cmpt_obj(v45, v63, v64, v65, v66, v67, v68, v69, v70);
                  if ( v78 )
                  {
                    v87 = *(unsigned __int8 *)(v78 + 162);
                    if ( *(_BYTE *)(v78 + 162) )
                    {
                      *(_BYTE *)(v60 + 22) = v87;
                      qdf_mem_copy((void *)(v60 + 23), (const void *)(v78 + 129), v87);
                      v96 = *(_BYTE *)(v60 + 9);
                      *(_DWORD *)(v60 + 60) = 0;
                      *(_DWORD *)(v60 + 12) = v57;
                      *(_BYTE *)(v60 + 9) = v96 | 4;
                      *(_BYTE *)(v60 + 200) = *((_BYTE *)a3 + 392);
                      v97 = *((unsigned int *)a3 + 72);
                      if ( (_DWORD)v97 )
                      {
                        *(_DWORD *)(v60 + 168) = v97;
                        v98 = (void *)_qdf_mem_malloc(v97, "cm_fill_roam_info", 851);
                        *(_QWORD *)(v60 + 176) = v98;
                        if ( !v98 )
                          goto LABEL_67;
                        qdf_mem_copy(v98, *((const void **)a3 + 37), *(unsigned int *)(v60 + 168));
                      }
                      v99 = *((unsigned int *)a3 + 73);
                      if ( (_DWORD)v99 )
                      {
                        *(_DWORD *)(v60 + 184) = v99;
                        v100 = (void *)_qdf_mem_malloc(v99, "cm_copy_tspec_ie", 527);
                        *(_QWORD *)(v60 + 192) = v100;
                        if ( v100 )
                          qdf_mem_copy(
                            v100,
                            (const void *)(*((_QWORD *)a3 + 37) + *((unsigned int *)a3 + 72)),
                            *(unsigned int *)(v60 + 184));
                      }
                      v101 = a3[1];
                      if ( a3[1] )
                      {
                        *(_DWORD *)(v60 + 80) = v101;
                        v102 = *a3;
                        v103 = (void *)_qdf_mem_malloc(v101, "cm_populate_connect_ies", 434);
                        *(_QWORD *)(v60 + 88) = v103;
                        if ( !v103 )
                          goto LABEL_67;
                        qdf_mem_copy(v103, (char *)a3 + v102, *(unsigned int *)(v60 + 80));
                      }
                      v104 = a3[1247];
                      if ( a3[1247] )
                      {
                        *(_DWORD *)(v60 + 96) = v104;
                        v105 = a3[1246];
                        v106 = (void *)_qdf_mem_malloc(v104, "cm_populate_connect_ies", 449);
                        *(_QWORD *)(v60 + 104) = v106;
                        if ( !v106 )
                          goto LABEL_67;
                        qdf_mem_copy(v106, (char *)a3 + v105, *(unsigned int *)(v60 + 96));
                      }
                      v107 = a3[3];
                      if ( v107 < 0x19 )
                      {
LABEL_47:
                        v110 = a3[5];
                        if ( v110 < 0x19 )
                        {
LABEL_50:
                          *(_BYTE *)(v60 + 9) = *(_BYTE *)(v60 + 9) & 0xEF | (16 * (*((_BYTE *)a3 + 2457) & 1));
                          if ( a3[203] )
                          {
                            v114 = _qdf_mem_malloc(0x990u, "cm_fill_fils_ie", 338);
                            *(_QWORD *)(v60 + 144) = v114;
                            if ( v114 )
                            {
                              v123 = (unsigned __int16 *)v114;
                              cds_copy_hlp_info(
                                (int *)((char *)a3 + 393),
                                (int *)((char *)a3 + 399),
                                a3[203],
                                a3 + 204,
                                (__int64)v123 + 379,
                                (__int64)v123 + 385,
                                v123 + 1220,
                                (char *)v123 + 391,
                                v115,
                                v116,
                                v117,
                                v118,
                                v119,
                                v120,
                                v121,
                                v122);
                              v123[1221] = a3[129];
                            }
                          }
                          v124 = *(_QWORD *)(v60 + 152);
                          *(_BYTE *)v124 = *((_DWORD *)a3 + 14);
                          v125 = *((unsigned __int8 *)a3 + 100);
                          *(_BYTE *)(v124 + 1) = v125;
                          if ( (_DWORD)v125 )
                            qdf_mem_copy((void *)(v124 + 2), a3 + 34, v125);
                          v126 = *((unsigned __int8 *)a3 + 104);
                          *(_BYTE *)(v124 + 34) = v126;
                          if ( v126 )
                            qdf_mem_copy((void *)(v124 + 35), a3 + 54, *((unsigned int *)a3 + 26));
                          qdf_mem_copy((void *)(v124 + 99), a3 + 130, 8u);
                          *(_WORD *)(v124 + 108) = *((_BYTE *)a3 + 61) & 0xF;
                          *(_BYTE *)(v124 + 107) = (*((_BYTE *)a3 + 61) >> 4) & 3;
                          v127 = *((unsigned int *)a3 + 43);
                          *(_DWORD *)(v124 + 112) = v127;
                          if ( (_DWORD)v127 )
                            qdf_mem_copy((void *)(v124 + 116), a3 + 88, v127);
                          qdf_mem_copy((void *)(v124 + 180), a3 + 120, 0x10u);
                          *(_BYTE *)(v124 + 196) = *((_BYTE *)a3 + 256);
                          v136 = a3[129];
                          *(_WORD *)(v124 + 198) = v136;
                          v137 = *(_QWORD *)(v45 + 152);
                          if ( v137 )
                          {
                            v138 = *(_QWORD *)(v137 + 80);
                            if ( v138 )
                            {
                              v139 = v136;
                              fils_connection_info = wlan_cm_get_fils_connection_info(
                                                       v138,
                                                       *(unsigned __int8 *)(v45 + 104));
                              if ( fils_connection_info )
                                *(_DWORD *)(fils_connection_info + 260) = v139;
                              goto LABEL_75;
                            }
                            v141 = "%s: vdev %d cm_id 0x%x: Failed to find psoc";
                          }
                          else
                          {
                            v141 = "%s: vdev %d cm_id 0x%x: Failed to find pdev";
                          }
                          qdf_trace_msg(
                            0x68u,
                            2u,
                            v141,
                            v128,
                            v129,
                            v130,
                            v131,
                            v132,
                            v133,
                            v134,
                            v135,
                            "cm_fils_update_erp_seq_num",
                            *(unsigned __int8 *)(v45 + 104),
                            v57);
LABEL_75:
                          v145 = *(_QWORD *)(v60 + 120);
                          if ( v145 )
                          {
                            v146 = *(_DWORD *)(v60 + 112);
                            if ( v146 )
                            {
                              if ( (*(_BYTE *)(v60 + 9) & 0x10) != 0 )
                                v147 = 4;
                              else
                                v147 = 10;
                              ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(
                                                  0x7Fu,
                                                  (unsigned __int8 *)(v145 + v147),
                                                  (unsigned __int16)v146 - (unsigned __int16)v147);
                              if ( ie_ptr_from_eid )
                              {
                                v157 = (ie_ptr_from_eid[4] >> 3) & 1;
                              }
                              else
                              {
                                qdf_trace_msg(
                                  0x68u,
                                  8u,
                                  "%s: Ext cap is not present, disable btm",
                                  v149,
                                  v150,
                                  v151,
                                  v152,
                                  v153,
                                  v154,
                                  v155,
                                  v156,
                                  "cm_update_assoc_btm_cap");
                                LOBYTE(v157) = 0;
                              }
                              wlan_cm_set_assoc_btm_cap(v45, v157, v149, v150, v151, v152, v153, v154, v155, v156);
                            }
                          }
                          updated = cm_update_scan_db_on_roam_success(v45, v60 + 8, a3, v272);
                          v166 = cm_csr_connect_rsp(v45, v60, updated, v159, v160, v161, v162, v163, v164, v165);
                          if ( v166 )
                          {
                            v76 = v166;
                            v175 = "%s: Roam sync propagation failed, abort roaming";
LABEL_86:
                            qdf_trace_msg(
                              0x68u,
                              2u,
                              v175,
                              v167,
                              v168,
                              v169,
                              v170,
                              v171,
                              v172,
                              v173,
                              v174,
                              "cm_fw_roam_sync_propagation");
                            goto LABEL_70;
                          }
                          v176 = cm_process_roam_keys(v45, v60, v272);
                          cm_inform_dlm_connect_complete(*v270, v60 + 8, v176, v177, v178, v179, v180, v181, v182, v183);
                          wlan_p2p_status_connect(v45, v184, v185, v186, v187, v188, v189, v190, v191);
                          if ( (((__int64 (__fastcall *)(_QWORD))cm_csr_is_ss_wait_for_key)(a2) & 1) == 0 )
                          {
                            qdf_trace_msg(
                              0x68u,
                              8u,
                              "%s: vdev %d cm_id 0x%x: WLAN link up with AP = %02x:%02x:%02x:**:**:%02x",
                              v192,
                              v193,
                              v194,
                              v195,
                              v196,
                              v197,
                              v198,
                              v199,
                              "cm_fw_roam_sync_propagation",
                              (unsigned __int8)a2,
                              v272,
                              *(unsigned __int8 *)(v60 + 16),
                              *(unsigned __int8 *)(v60 + 17),
                              *(unsigned __int8 *)(v60 + 18),
                              *(unsigned __int8 *)(v60 + 21));
                            cm_roam_start_init_on_connect(v44, a2);
                          }
                          wlan_cm_tgt_send_roam_sync_complete_cmd(a1, a2);
                          cm_connect_info(
                            v45,
                            1,
                            (const void *)(v60 + 16),
                            (unsigned __int8 *)(v60 + 22),
                            *(_DWORD *)(v60 + 56));
                          tdls_chan_switch_prohibited = mlme_get_tdls_chan_switch_prohibited(
                                                          v45,
                                                          v200,
                                                          v201,
                                                          v202,
                                                          v203,
                                                          v204,
                                                          v205,
                                                          v206,
                                                          v207);
                          tdls_prohibited = mlme_get_tdls_prohibited(
                                              v45,
                                              v209,
                                              v210,
                                              v211,
                                              v212,
                                              v213,
                                              v214,
                                              v215,
                                              v216);
                          v218 = wlan_tdls_notify_sta_connect(
                                   a2,
                                   tdls_chan_switch_prohibited & 1,
                                   tdls_prohibited & 1,
                                   v45);
                          wlan_cm_update_scan_mlme_info(v45, v60 + 8, v218, v219, v220, v221, v222, v223, v224, v225);
                          cm_update_associated_ch_info(v45, 1, v226, v227, v228, v229, v230, v231, v232, v233);
                          v242 = wlan_sm_dispatch(
                                   v270[9],
                                   0x20u,
                                   0x9C8u,
                                   (__int64)a3,
                                   v234,
                                   v235,
                                   v236,
                                   v237,
                                   v238,
                                   v239,
                                   v240,
                                   v241);
                          if ( v242 )
                          {
                            v76 = v242;
                            v143 = "%s: vdev %d cm_id 0x%x:  fail to post WLAN_CM_SM_EV_ROAM_DONE";
                            v144 = (unsigned __int8)a2;
                            v142 = v272;
                            goto LABEL_69;
                          }
                          mlme_cm_osif_connect_complete();
                          mlme_cm_osif_roam_complete();
                          lim_set_tpc_power(v23, v33, 0, 0, v243, v244, v245, v246, v247, v248, v249, v250);
                          qdf_trace_msg(
                            0x68u,
                            8u,
                            "%s: vdev %d cm_id 0x%x: ",
                            v251,
                            v252,
                            v253,
                            v254,
                            v255,
                            v256,
                            v257,
                            v258,
                            "cm_fw_roam_sync_propagation",
                            (unsigned __int8)a2,
                            v272);
                          cm_remove_cmd(v270, &v272, v259, v260, v261, v262, v263, v264, v265, v266);
                          wlan_psoc_mlme_get_11be_capab(a1, &v271);
                          v76 = 0;
                          if ( v271 )
                          {
                            v267 = policy_mgr_current_connections_update(
                                     a1,
                                     (unsigned __int8)a2,
                                     *(_DWORD *)(v60 + 56),
                                     0xFu,
                                     0);
                            if ( v267 == 11 )
                            {
                              v76 = 0;
                              goto LABEL_70;
                            }
                            v76 = v267;
                            if ( v267 == 16 )
                            {
                              v175 = "%s: Failed to take next action LFR3_ROAM";
                              goto LABEL_86;
                            }
                          }
LABEL_70:
                          wlan_cm_free_connect_rsp(v60);
                          goto LABEL_71;
                        }
                        v111 = v110 - 24;
                        *(_DWORD *)(v60 + 112) = v111;
                        v112 = a3[4];
                        v113 = (void *)_qdf_mem_malloc(v111, "cm_populate_connect_ies", 506);
                        *(_QWORD *)(v60 + 120) = v113;
                        if ( v113 )
                        {
                          qdf_mem_copy(v113, (char *)a3 + v112 + 24, *(unsigned int *)(v60 + 112));
                          goto LABEL_50;
                        }
                        goto LABEL_67;
                      }
                      *(_QWORD *)v269 = (char *)a3 + a3[2];
                      qdf_trace_msg(
                        0x68u,
                        8u,
                        "%s: vdevid: %d Assoc Rsp",
                        v88,
                        v89,
                        v90,
                        v91,
                        v92,
                        v93,
                        v94,
                        v95,
                        "cm_populate_connect_ies",
                        *(unsigned __int8 *)(v60 + 8));
                      ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
                        31,
                        8,
                        *(_QWORD *)v269,
                        v107);
                      v108 = v107 - 24;
                      *(_DWORD *)(v60 + 128) = v108;
                      v109 = (void *)_qdf_mem_malloc(v108, "cm_populate_connect_ies", 485);
                      *(_QWORD *)(v60 + 136) = v109;
                      if ( v109 )
                      {
                        qdf_mem_copy(v109, (const void *)(*(_QWORD *)v269 + 24LL), *(unsigned int *)(v60 + 128));
                        _qdf_mem_free(0);
                        goto LABEL_47;
                      }
                      _qdf_mem_free(0);
LABEL_67:
                      v76 = 2;
                      goto LABEL_68;
                    }
                    *(_BYTE *)(v60 + 22) = 0;
                  }
                  qdf_trace_msg(
                    0x68u,
                    2u,
                    "%s: vdev %d cm_id 0x%x: Failed to get ssid",
                    v79,
                    v80,
                    v81,
                    v82,
                    v83,
                    v84,
                    v85,
                    v86,
                    "cm_fill_roam_info",
                    *(unsigned __int8 *)(v60 + 8),
                    v57);
                  v76 = 16;
LABEL_68:
                  v142 = v272;
                  v143 = "%s: vdev %d cm_id 0x%x:  fail to prepare rsp";
                  v144 = (unsigned __int8)a2;
LABEL_69:
                  qdf_trace_msg(
                    0x68u,
                    2u,
                    v143,
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    v68,
                    v69,
                    v70,
                    "cm_fw_roam_sync_propagation",
                    v144,
                    v142);
                  goto LABEL_70;
                }
              }
              else
              {
                *v58 = 0;
              }
              qdf_trace_msg(
                0x68u,
                2u,
                "%s: vdev %d cm_id 0x%x: Failed to find psoc",
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                "cm_fw_roam_sync_propagation",
                (unsigned __int8)a2,
                v57);
              v76 = 16;
              goto LABEL_70;
            }
            v76 = 2;
          }
          else
          {
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: Failed to find roam req from list",
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              v55,
              "cm_fw_roam_sync_propagation");
            v35 = 0xFFFFFFFFLL;
            v76 = 16;
            v272 = -1;
          }
        }
        else
        {
          v76 = 16;
        }
LABEL_71:
        wlan_objmgr_vdev_release_ref(v45, 1u, (unsigned int *)v35, v36, v37, v38, v39, v40, v41, v42, v43);
        result = v76;
        goto LABEL_72;
      }
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: vdev object is NULL",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "cm_fw_roam_sync_propagation");
      result = 29;
    }
    else
    {
      qdf_trace_msg(
        0x68u,
        2u,
        "%s: Session not found for vdev_id: %d",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "cm_fw_roam_sync_propagation",
        (unsigned __int8)a2);
      result = 16;
    }
  }
  else
  {
    result = 16;
  }
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
