__int64 __fastcall policy_mgr_check_sta_ap_concurrent_ch_intf(
        _QWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x23
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x20
  __int64 context; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x21
  __int64 v47; // x22
  void *v48; // x21
  int v49; // t1
  __int64 v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x21
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int *v68; // x8
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w22
  const char *v78; // x2
  __int64 v79; // x5
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x4
  __int64 v89; // x8
  __int64 v90; // x20
  __int64 v91; // x0
  __int64 v92; // x0
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x26
  _QWORD *v102; // x21
  unsigned int v103; // w24
  unsigned int operation_chan_freq_vdev_id; // w25
  unsigned int opmode_from_vdev_id; // w0
  unsigned int v106; // w23
  unsigned int existing_con_info; // w22
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  bool v116; // zf
  int v117; // w8
  _DWORD *v118; // x8
  unsigned int v119; // w23
  double v120; // d0
  double v121; // d1
  double v122; // d2
  double v123; // d3
  double v124; // d4
  double v125; // d5
  double v126; // d6
  double v127; // d7
  _DWORD *v128; // x8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int64 v145; // x5
  __int64 v146; // x6
  const char *v147; // x2
  __int64 v148; // x20
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  unsigned __int8 *v157; // x22
  unsigned int sap_mode_info; // w20
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  const char *v175; // x2
  const char *v176; // x3
  void (__fastcall *v177)(__int64, __int64, __int64); // x8
  __int64 v178; // x2
  __int64 v179; // x1
  unsigned int v180; // w0
  unsigned int *v181; // x8
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  const char *v190; // x2
  const char *v191; // x2
  __int64 (*v192)(void); // x8
  unsigned int (__fastcall *v193)(__int64, __int64, unsigned int *); // x8
  __int64 v194; // x0
  __int64 v195; // x1
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  unsigned int (__fastcall *v204)(__int64, __int64, unsigned int *); // x8
  __int64 v205; // x0
  __int64 v206; // x1
  unsigned int (__fastcall *v207)(__int64, __int64, unsigned int *); // x8
  __int64 v208; // x0
  __int64 v209; // x1
  unsigned int (__fastcall *v210)(__int64, __int64, unsigned int *); // x8
  __int64 v211; // x0
  __int64 v212; // x1
  unsigned int (__fastcall *v213)(__int64, __int64, unsigned int *); // x8
  __int64 v214; // x0
  __int64 v215; // x1
  unsigned int *v216; // x8
  _DWORD *v217; // x8
  __int64 v218; // x2
  unsigned int v219; // [xsp+2Ch] [xbp-54h] BYREF
  unsigned int v220[6]; // [xsp+30h] [xbp-50h] BYREF
  unsigned int v221; // [xsp+48h] [xbp-38h] BYREF
  unsigned int v222; // [xsp+4Ch] [xbp-34h] BYREF
  unsigned int v223; // [xsp+50h] [xbp-30h] BYREF
  int v224; // [xsp+54h] [xbp-2Ch] BYREF
  int v225; // [xsp+58h] [xbp-28h] BYREF
  unsigned __int8 v226; // [xsp+5Ch] [xbp-24h] BYREF
  __int64 v227; // [xsp+60h] [xbp-20h] BYREF
  __int64 v228; // [xsp+68h] [xbp-18h] BYREF
  int v229; // [xsp+70h] [xbp-10h] BYREF
  __int64 v230; // [xsp+78h] [xbp-8h]

  v230 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               "%s: Invalid context",
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               "policy_mgr_check_sta_ap_concurrent_ch_intf");
    goto LABEL_129;
  }
  result = _qdf_op_protect();
  if ( !(_DWORD)result )
  {
    v27 = a1[262];
    *((_BYTE *)a1 + 1128) = 0;
    v219 = 0;
    v229 = 0;
    v227 = 0;
    v228 = 0;
    v226 = 0;
    v225 = 0;
    if ( !v27 )
    {
      qdf_trace_msg(
        0x4Fu,
        2u,
        "%s: Invalid work_info context",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "__policy_mgr_check_sta_ap_concurrent_ch_intf");
LABEL_128:
      result = _qdf_op_unprotect();
      goto LABEL_129;
    }
    a1[261] = qdf_get_current_task();
    if ( !*(_DWORD *)(v27 + 8) )
      goto LABEL_29;
    v36 = *a1;
    memset(v220, 0, sizeof(v220));
    context = policy_mgr_get_context(v36);
    if ( context )
    {
      v46 = *(_QWORD *)(context + 2096);
      v47 = context;
      if ( v46 )
      {
        if ( (wlan_mlme_is_aux_emlsr_support(v36) & 1) != 0 )
        {
          qdf_mutex_acquire(v47 + 56);
          v49 = *(_DWORD *)(v46 + 8);
          v48 = (void *)(v46 + 8);
          if ( v49 )
          {
            qdf_mem_copy(v220, v48, 0x18u);
            qdf_mem_set(v48, 0x18u, 0);
            qdf_mutex_release(v47 + 56);
            v50 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                    v36,
                    LOBYTE(v220[1]),
                    24);
            if ( v50 )
            {
              v59 = v50;
              if ( (unsigned __int8)policy_mgr_get_connection_for_vdev_id(v36, LOBYTE(v220[1])) == 5 )
              {
                qdf_trace_msg(
                  0x4Fu,
                  2u,
                  "%s: vdev %d not in conn tbl",
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  v67,
                  "policy_mgr_proc_deferred_csa",
                  LOBYTE(v220[1]));
                v77 = 4;
LABEL_75:
                wlan_objmgr_vdev_release_ref(v59, 0x18u, v68, v69, v70, v71, v72, v73, v74, v75, v76);
                v88 = v77;
                goto LABEL_26;
              }
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: proc deferred csa vdev %d reason %d tgt %d bw %d forced %d",
                v60,
                v61,
                v62,
                v63,
                v64,
                v65,
                v66,
                v67,
                "policy_mgr_proc_deferred_csa",
                LOBYTE(v220[1]),
                v220[2],
                v220[0],
                v220[4],
                LOBYTE(v220[5]));
              v177 = *(void (__fastcall **)(__int64, __int64, __int64))(v47 + 336);
              if ( v177 )
              {
                v178 = v220[2];
                v179 = LOBYTE(v220[1]);
                if ( *((_DWORD *)v177 - 1) != -1125204353 )
                  __break(0x8228u);
                v177(v36, v179, v178);
              }
              v180 = policy_mgr_change_sap_channel_with_csa(v36, LOBYTE(v220[1]), v220[0], v220[4], v220[5]);
              if ( v180 )
              {
                v77 = v180;
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: status %d vdev %d",
                  v182,
                  v183,
                  v184,
                  v185,
                  v186,
                  v187,
                  v188,
                  v189,
                  "policy_mgr_proc_deferred_csa",
                  v180,
                  LOBYTE(v220[1]));
                policy_mgr_ap_csa_end(v36, LOBYTE(v220[1]), 1, 1);
                goto LABEL_75;
              }
              wlan_objmgr_vdev_release_ref(v59, 0x18u, v181, v182, v183, v184, v185, v186, v187, v188, v189);
              v191 = "%s: deferred csa is handled";
LABEL_89:
              qdf_trace_msg(
                0x4Fu,
                8u,
                v191,
                v149,
                v150,
                v151,
                v152,
                v153,
                v154,
                v155,
                v156,
                "__policy_mgr_check_sta_ap_concurrent_ch_intf");
              goto LABEL_127;
            }
            qdf_trace_msg(
              0x4Fu,
              2u,
              "%s: vdev %d: not found",
              v51,
              v52,
              v53,
              v54,
              v55,
              v56,
              v57,
              v58,
              "policy_mgr_proc_deferred_csa",
              LOBYTE(v220[1]));
LABEL_25:
            v88 = 4;
LABEL_26:
            qdf_trace_msg(
              0x4Fu,
              8u,
              "%s: deferred csa failed %d",
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              "__policy_mgr_check_sta_ap_concurrent_ch_intf",
              v88);
            goto LABEL_127;
          }
          qdf_mutex_release(v47 + 56);
        }
LABEL_29:
        if ( *(_BYTE *)(v27 + 52) && (unsigned int)policy_mgr_nan_sap_post_enable_conc_check(*a1) == 24 )
          goto LABEL_127;
        qdf_trace_msg(
          0x4Fu,
          8u,
          "%s: p2p go vdev id: %d csa reason: %d",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "__policy_mgr_check_sta_ap_concurrent_ch_intf",
          *(unsigned __int8 *)(v27 + 32),
          *(unsigned int *)(v27 + 44));
        v89 = a1[262];
        if ( *(unsigned __int8 *)(v89 + 32) != 255 )
        {
          policy_mgr_do_go_plus_go_force_scc(
            *a1,
            *(unsigned __int8 *)(v27 + 32),
            *(unsigned int *)(v27 + 36),
            *(unsigned int *)(v27 + 40));
          *(_BYTE *)(v27 + 32) = -1;
          goto LABEL_127;
        }
        v90 = *a1;
        if ( *(_DWORD *)(v89 + 44) )
        {
          v91 = *a1;
          v221 = 0;
          v223 = 0;
          v224 = 7;
          memset(&v220[1], 0, 20);
          v92 = policy_mgr_get_context(v91);
          if ( v92 )
          {
            v101 = *(_QWORD *)(v92 + 2096);
            v102 = (_QWORD *)v92;
            if ( v101 )
            {
              if ( !*(_DWORD *)(v101 + 44) )
                goto LABEL_127;
              v103 = *(unsigned __int8 *)(v101 + 48);
              operation_chan_freq_vdev_id = wlan_get_operation_chan_freq_vdev_id(
                                              *(_QWORD *)(v92 + 8),
                                              *(unsigned __int8 *)(v101 + 48));
              opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(v102[1], v103);
              v106 = policy_mgr_qdf_opmode_to_pm_con_mode(v90, opmode_from_vdev_id, v103);
              existing_con_info = (unsigned __int8)policy_mgr_fetch_existing_con_info(
                                                     v90,
                                                     v103,
                                                     operation_chan_freq_vdev_id,
                                                     &v224,
                                                     &v223,
                                                     &v221);
              qdf_trace_msg(
                0x4Fu,
                8u,
                "%s: initiator vdev %d mode %d freq %d, existing vdev %d mode %d freq %d reason %d",
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                v115,
                "policy_mgr_handle_sap_plus_go_force_scc",
                v103,
                v106,
                operation_chan_freq_vdev_id,
                existing_con_info,
                v224,
                v223,
                *(_DWORD *)(v101 + 44));
              if ( existing_con_info != 255 )
              {
                if ( v106 == 3 && v224 == 1
                  || (v224 != 3 ? (v116 = v224 == 1) : (v116 = 1), !v116 ? (v117 = 0) : (v117 = 1), v106 == 1 && v117) )
                {
                  v118 = (_DWORD *)v102[47];
                  if ( v118 )
                  {
                    v222 = 0;
                    if ( *(v118 - 1) != 801623019 )
                      __break(0x8228u);
                    v119 = ((__int64 (__fastcall *)(__int64, _QWORD, unsigned int *))v118)(
                             v90,
                             existing_con_info,
                             &v222);
                    qdf_trace_msg(
                      0x4Fu,
                      8u,
                      "%s: vdev %d freq %d intf %d status %d",
                      v120,
                      v121,
                      v122,
                      v123,
                      v124,
                      v125,
                      v126,
                      v127,
                      "policy_mgr_handle_sap_plus_go_force_scc",
                      existing_con_info,
                      v223,
                      v222,
                      v119);
                    if ( !v119 && v222 && v222 != v223 )
                    {
                      v128 = (_DWORD *)v102[45];
                      v220[0] = v221;
                      if ( v128 )
                      {
                        if ( *(v128 - 1) != 157525345 )
                          __break(0x8228u);
                        if ( ((unsigned int (__fastcall *)(__int64, _QWORD))v128)(v90, existing_con_info) )
                          qdf_trace_msg(
                            0x4Fu,
                            8u,
                            "%s: no candidate valid bw for vdev %d intf %d",
                            v129,
                            v130,
                            v131,
                            v132,
                            v133,
                            v134,
                            v135,
                            v136,
                            "policy_mgr_handle_sap_plus_go_force_scc",
                            existing_con_info,
                            v222);
                      }
                      if ( (unsigned int)policy_mgr_valid_sap_conc_channel_check(
                                           v90,
                                           &v222,
                                           v223,
                                           existing_con_info,
                                           v220) )
                      {
                        v146 = v222;
                        v145 = v223;
                        v147 = "%s: warning no candidate freq for vdev %d freq %d intf %d";
                      }
                      else
                      {
                        v217 = (_DWORD *)v102[42];
                        if ( v217 )
                        {
                          v218 = *(unsigned int *)(v101 + 44);
                          if ( *(v217 - 1) != -1125204353 )
                            __break(0x8228u);
                          ((void (__fastcall *)(__int64, _QWORD, __int64))v217)(v90, existing_con_info, v218);
                        }
                        if ( !(unsigned int)policy_mgr_change_sap_channel_with_csa(
                                              v90,
                                              existing_con_info,
                                              v222,
                                              v220[0],
                                              1) )
                          goto LABEL_126;
                        v146 = v222;
                        v145 = v223;
                        v147 = "%s: warning sap/go vdev %d freq %d intf %d csa failed";
                      }
                      qdf_trace_msg(
                        0x4Fu,
                        2u,
                        v147,
                        v137,
                        v138,
                        v139,
                        v140,
                        v141,
                        v142,
                        v143,
                        v144,
                        "policy_mgr_handle_sap_plus_go_force_scc",
                        existing_con_info,
                        v145,
                        v146);
                    }
                  }
                }
              }
LABEL_126:
              *(_DWORD *)(v101 + 44) = 0;
              *(_WORD *)(v101 + 48) = -1;
              goto LABEL_127;
            }
            v175 = "%s: invalid work info";
          }
          else
          {
            v175 = "%s: Invalid Context";
          }
          v176 = "policy_mgr_handle_sap_plus_go_force_scc";
LABEL_81:
          qdf_trace_msg(0x4Fu, 2u, v175, v93, v94, v95, v96, v97, v98, v99, v100, v176);
          goto LABEL_127;
        }
        policy_mgr_get_mcc_to_scc_switch_mode(*a1);
        v148 = *a1;
        if ( !(unsigned int)policy_mgr_get_sap_mode_count(*a1, 0)
          && !(unsigned int)policy_mgr_mode_specific_connection_count(v148, 3, 0) )
        {
          v191 = "%s: No beaconing interface present";
          goto LABEL_89;
        }
        v157 = (unsigned __int8 *)&v225;
        sap_mode_info = policy_mgr_get_sap_mode_info(*a1, &v227, &v225);
        if ( sap_mode_info >= 5 )
        {
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: No. of beaconing interface (SAP + LL LT SAP + GO):%d",
            v159,
            v160,
            v161,
            v162,
            v163,
            v164,
            v165,
            v166,
            "__policy_mgr_check_sta_ap_concurrent_ch_intf",
            sap_mode_info);
        }
        else
        {
          sap_mode_info += policy_mgr_get_mode_specific_conn_info(
                             *a1,
                             (char *)&v227 + 4 * sap_mode_info,
                             (char *)&v225 + sap_mode_info,
                             3);
          qdf_trace_msg(
            0x4Fu,
            8u,
            "%s: No. of beaconing interface (SAP + LL LT SAP + GO):%d",
            v167,
            v168,
            v169,
            v170,
            v171,
            v172,
            v173,
            v174,
            "__policy_mgr_check_sta_ap_concurrent_ch_intf",
            sap_mode_info);
          if ( !sap_mode_info )
          {
            v175 = "%s: Could not retrieve SAP/GO operating channel&vdevid";
LABEL_66:
            v176 = "__policy_mgr_check_sta_ap_concurrent_ch_intf";
            goto LABEL_81;
          }
        }
        if ( (policy_mgr_is_any_conn_in_transition(*a1) & 1) != 0 )
        {
          v190 = "%s: defer sap conc check to a later time due to another sta/cli dicon/roam pending";
        }
        else if ( (policy_mgr_is_ap_start_in_progress(*a1) & 1) != 0 )
        {
          v190 = "%s: defer sap conc check to a later time due to another sap/go start pending";
        }
        else
        {
          if ( (policy_mgr_is_set_link_in_progress(*a1) & 1) == 0 )
          {
            v192 = (__int64 (*)(void))a1[40];
            if ( v192 )
            {
              if ( *((_DWORD *)v192 - 1) != 799902358 )
                __break(0x8228u);
              if ( (v192() & 1) != 0 )
              {
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: wait as channel switch is already in progress",
                  v93,
                  v94,
                  v95,
                  v96,
                  v97,
                  v98,
                  v99,
                  v100,
                  "__policy_mgr_check_sta_ap_concurrent_ch_intf");
                if ( (unsigned int)qdf_wait_single_event((__int64)(a1 + 269), 0x7D0u) )
                  qdf_trace_msg(
                    0x4Fu,
                    2u,
                    "%s: wait for event failed, still continue with channel switch",
                    v93,
                    v94,
                    v95,
                    v96,
                    v97,
                    v98,
                    v99,
                    v100,
                    "__policy_mgr_check_sta_ap_concurrent_ch_intf");
              }
            }
            if ( a1[37] )
            {
              if ( sap_mode_info <= 5 )
              {
                policy_mgr_switch_sap_vdev_table_sequence(a1, &v225, sap_mode_info);
                v193 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
                v194 = *a1;
                v195 = (unsigned __int8)v225;
                if ( *((_DWORD *)v193 - 1) != 801623019 )
                  __break(0x8228u);
                if ( v193(v194, v195, &v219) )
                {
                  if ( sap_mode_info == 1 )
                    goto LABEL_127;
                  v204 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
                  v205 = *a1;
                  v206 = BYTE1(v225);
                  if ( *((_DWORD *)v204 - 1) != 801623019 )
                    __break(0x8228u);
                  if ( v204(v205, v206, &v219) )
                  {
                    if ( sap_mode_info == 2 )
                      goto LABEL_127;
                    v207 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
                    v208 = *a1;
                    v209 = BYTE2(v225);
                    if ( *((_DWORD *)v207 - 1) != 801623019 )
                      __break(0x8228u);
                    if ( v207(v208, v209, &v219) )
                    {
                      if ( sap_mode_info == 3 )
                        goto LABEL_127;
                      v210 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
                      v211 = *a1;
                      v212 = HIBYTE(v225);
                      if ( *((_DWORD *)v210 - 1) != 801623019 )
                        __break(0x8228u);
                      if ( v210(v211, v212, &v219) )
                      {
                        if ( sap_mode_info == 4 )
                          goto LABEL_127;
                        v213 = (unsigned int (__fastcall *)(__int64, __int64, unsigned int *))a1[37];
                        v214 = *a1;
                        v215 = v226;
                        if ( *((_DWORD *)v213 - 1) != 801623019 )
                          __break(0x8228u);
                        if ( v213(v214, v215, &v219) )
                          goto LABEL_127;
                        v157 = &v226;
                        v216 = (unsigned int *)&v229;
                      }
                      else
                      {
                        v157 = (unsigned __int8 *)&v225 + 3;
                        v216 = (unsigned int *)&v228 + 1;
                      }
                    }
                    else
                    {
                      v157 = (unsigned __int8 *)&v225 + 2;
                      v216 = (unsigned int *)&v228;
                    }
                  }
                  else
                  {
                    v157 = (unsigned __int8 *)&v225 + 1;
                    v216 = (unsigned int *)&v227 + 1;
                  }
                }
                else
                {
                  v216 = (unsigned int *)&v227;
                }
                qdf_trace_msg(
                  0x4Fu,
                  8u,
                  "%s: SAP vdev id %d restarts, old ch freq :%d new ch freq: %d",
                  v196,
                  v197,
                  v198,
                  v199,
                  v200,
                  v201,
                  v202,
                  v203,
                  "__policy_mgr_check_sta_ap_concurrent_ch_intf",
                  *v157,
                  *v216,
                  v219);
              }
LABEL_127:
              *((_DWORD *)a1 + 241) = 0;
              a1[261] = 0;
              goto LABEL_128;
            }
            v175 = "%s: SAP restart get channel callback in NULL";
            goto LABEL_66;
          }
          v190 = "%s: defer sap conc check to a later time due to ml sta set link in progress";
        }
        qdf_trace_msg(
          0x4Fu,
          8u,
          v190,
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          "__policy_mgr_check_sta_ap_concurrent_ch_intf");
        _qdf_delayed_work_start((__int64)(a1 + 126), 0x7D0u);
        goto LABEL_127;
      }
      v78 = "%s: Invalid work_info context";
    }
    else
    {
      v78 = "%s: Invalid context";
    }
    qdf_trace_msg(0x4Fu, 2u, v78, v38, v39, v40, v41, v42, v43, v44, v45, "policy_mgr_proc_deferred_csa");
    goto LABEL_25;
  }
  if ( (_DWORD)result == -11 )
  {
    if ( (qdf_is_driver_unloading() & 1) != 0
      || (qdf_is_recovering() & 1) != 0
      || (result = qdf_is_driver_state_module_stop(), (result & 1) != 0) )
    {
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: driver not ready",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "policy_mgr_check_sta_ap_concurrent_ch_intf");
    }
    else if ( a1[262] )
    {
      v79 = (unsigned __int8)++*((_BYTE *)a1 + 1128);
      result = qdf_trace_msg(
                 0x4Fu,
                 8u,
                 "%s: qdf_op start fail, ret %d, work_fail_count %d",
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 "policy_mgr_check_sta_ap_concurrent_ch_intf",
                 4294967285LL,
                 v79);
      if ( *((unsigned __int8 *)a1 + 1128) < 2u )
        result = _qdf_delayed_work_start((__int64)(a1 + 126), 0x7D0u);
      else
        *((_BYTE *)a1 + 1128) = 0;
    }
  }
LABEL_129:
  _ReadStatusReg(SP_EL0);
  return result;
}
