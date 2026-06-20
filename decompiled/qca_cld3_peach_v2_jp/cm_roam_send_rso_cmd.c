__int64 __fastcall cm_roam_send_rso_cmd(__int64 a1, __int64 a2, unsigned __int8 a3, unsigned __int8 a4)
{
  unsigned int v6; // w19
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x24
  unsigned int v18; // w27
  __int64 psoc_ext_obj_fl; // x0
  unsigned int *v20; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x25
  __int64 rso_config_fl; // x0
  __int64 v31; // x26
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int v48; // w0
  unsigned int *v49; // x8
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int updated; // w25
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  const char *v67; // x2
  unsigned int v68; // w1
  const char *v69; // x2
  const char *v70; // x3
  _BOOL4 v72; // w25
  unsigned int *v73; // x8
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x0
  unsigned int v83; // w1
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  _BOOL4 v92; // w8
  const char *v93; // x4
  unsigned __int64 v94; // x8
  bool is_vdev_disconnected; // w0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  _BYTE *v104; // x0
  _DWORD *v105; // x24
  _DWORD *v106; // x0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  int v115; // w6
  int v116; // w7
  int v117; // w8
  int v118; // w9
  int v119; // w10
  int v120; // w11
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x0
  __int64 v138; // x20
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  unsigned int hb_ap_rssi; // w0
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  __int64 v156; // x0
  __int64 v157; // x22
  __int64 v158; // x0
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  __int64 v167; // x23
  __int64 v168; // x0
  unsigned int *v169; // x8
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  __int64 v178; // x25
  __int64 v179; // x24
  __int64 v180; // x0
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  __int64 v189; // x26
  unsigned int *v190; // x8
  double v191; // d0
  double v192; // d1
  double v193; // d2
  double v194; // d3
  double v195; // d4
  double v196; // d5
  double v197; // d6
  double v198; // d7
  char v199; // w0
  char v200; // w8
  char v201; // w9
  __int64 v202; // x0
  double v203; // d0
  double v204; // d1
  double v205; // d2
  double v206; // d3
  double v207; // d4
  double v208; // d5
  double v209; // d6
  double v210; // d7
  __int64 v211; // x22
  unsigned int *v212; // x8
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  __int64 v221; // x0
  __int64 v222; // x0
  __int64 v223; // x0
  __int64 v224; // x25
  __int64 v225; // x24
  char is_any_sta_dfs_ap_scc_by_vdev_id; // w0
  char v227; // w8
  char v228; // w9
  const char *v229; // x3
  char v230; // w8
  int v231; // w5
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  __int64 v240; // x0
  unsigned int v241; // w24
  _DWORD *v242; // x21
  __int64 v243; // x0
  int v244; // w8
  unsigned int v245; // w25
  char assoc_btm_cap; // w0
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  __int64 v255; // x0
  double v256; // d0
  double v257; // d1
  double v258; // d2
  double v259; // d3
  double v260; // d4
  double v261; // d5
  double v262; // d6
  double v263; // d7
  char v264; // w8
  __int64 cmpt_obj; // x0
  size_t v266; // x2
  int v267; // w5
  double v268; // d0
  double v269; // d1
  double v270; // d2
  double v271; // d3
  double v272; // d4
  double v273; // d5
  double v274; // d6
  double v275; // d7
  const char *v276; // x2
  const char *v277; // x3
  int v278; // w25
  double v279; // d0
  double v280; // d1
  double v281; // d2
  double v282; // d3
  double v283; // d4
  double v284; // d5
  double v285; // d6
  double v286; // d7
  char btm_abridge_flag; // w25
  double v288; // d0
  double v289; // d1
  double v290; // d2
  double v291; // d3
  double v292; // d4
  double v293; // d5
  double v294; // d6
  double v295; // d7
  __int64 v296; // x5
  _QWORD v297[4]; // [xsp+20h] [xbp-50h] BYREF
  __int64 v298; // [xsp+40h] [xbp-30h] BYREF
  __int64 v299; // [xsp+48h] [xbp-28h]
  __int64 v300; // [xsp+50h] [xbp-20h]
  __int64 v301; // [xsp+58h] [xbp-18h]
  char v302[4]; // [xsp+64h] [xbp-Ch] BYREF
  __int64 v303; // [xsp+68h] [xbp-8h]

  v6 = a2;
  v303 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 77);
  if ( !v8 )
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev_id: %d: vdev not found",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "cm_is_rso_allowed",
      (unsigned __int8)v6);
LABEL_16:
    updated = 16;
    goto LABEL_17;
  }
  v17 = v8;
  v18 = *(unsigned __int8 *)(v8 + 104);
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl
    || (v29 = psoc_ext_obj_fl, (rso_config_fl = wlan_cm_get_rso_config_fl(v17, "cm_roam_cmd_allowed", 4286)) == 0) )
  {
LABEL_15:
    wlan_objmgr_vdev_release_ref(v17, 0x4Du, v20, v21, v22, v23, v24, v25, v26, v27, v28);
    goto LABEL_16;
  }
  v31 = rso_config_fl;
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: RSO Command %d, vdev %d, Reason %d",
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    "cm_roam_cmd_allowed",
    a3,
    v18,
    a4);
  if ( !cm_is_vdev_connected(v17, v32, v33, v34, v35, v36, v37, v38, v39) && a3 <= 4u && ((1 << a3) & 0x1A) != 0 )
  {
    v67 = "%s: vdev not in connected state and command %d ";
    v68 = 8;
LABEL_14:
    qdf_trace_msg(0x68u, v68, v67, v40, v41, v42, v43, v44, v45, v46, v47, "cm_roam_cmd_allowed", a3);
    goto LABEL_15;
  }
  if ( *(_BYTE *)(v31 + 831) == 1 && (*(_BYTE *)(v29 + 1775) & 1) == 0 )
  {
    qdf_trace_msg(
      0x68u,
      4u,
      "%s: Adaptive 11r Roaming not suppprted by fw",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "cm_roam_cmd_allowed");
    v82 = v17;
    v83 = 77;
    goto LABEL_24;
  }
  v48 = cm_akm_roam_allowed(a1, v17);
  if ( !v48 )
  {
    if ( (cfg_p2p_is_roam_config_disabled(a1) & 1) != 0 )
    {
      if ( (unsigned int)policy_mgr_mode_specific_connection_count(a1, 2, nullptr) )
        v72 = 1;
      else
        v72 = policy_mgr_mode_specific_connection_count(a1, 3, nullptr) != 0;
    }
    else
    {
      v72 = 0;
    }
    v92 = (cfg_nan_is_roam_config_disabled(a1) & 1) != 0
       && policy_mgr_mode_specific_connection_count(a1, 4, nullptr) != 0;
    if ( (a3 == 4 || a3 == 1) && (v72 || v92) )
    {
      if ( v72 )
        v93 = "p2p";
      else
        v93 = "ndi";
      qdf_trace_msg(
        0x68u,
        4u,
        "%s: roaming not supported for active %s connection",
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        "cm_roam_cmd_allowed",
        v93);
      goto LABEL_15;
    }
    if ( cm_is_vdev_disconnecting(v17, v84, v85, v86, v87, v88, v89, v90, v91) )
    {
      v94 = a3;
      if ( a3 == 2 )
        goto LABEL_46;
      v94 = a4;
      if ( a4 == 29 )
        goto LABEL_46;
    }
    else
    {
      is_vdev_disconnected = cm_is_vdev_disconnected(v17, v40, v41, v42, v43, v44, v45, v46, v47);
      v94 = a4;
      if ( a4 == 29 || (v94 = a3, a3 == 2) || !is_vdev_disconnected )
      {
LABEL_46:
        wlan_objmgr_vdev_release_ref(v17, 0x4Du, (unsigned int *)v94, v40, v41, v42, v43, v44, v45, v46, v47);
        if ( a3 == 2 )
        {
LABEL_47:
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: ROAM: invalid RSO command %d",
            v96,
            v97,
            v98,
            v99,
            v100,
            v101,
            v102,
            v103,
            "cm_roam_send_rso_cmd",
            a3);
          goto LABEL_25;
        }
        if ( (cm_roam_is_per_roam_allowed(a1, v6) & 1) != 0 )
        {
          v104 = (_BYTE *)_qdf_mem_malloc(0x30u, "cm_roam_offload_per_config", 4106);
          if ( v104 )
          {
            v105 = v104;
            *v104 = v6;
            v106 = (_DWORD *)mlme_get_psoc_ext_obj_fl(a1);
            if ( v106 )
            {
              v105[1] = v106[407];
              v115 = v106[408];
              v105[2] = v115;
              v105[3] = v115;
              v116 = v106[409];
              v105[4] = v116;
              v105[5] = v116;
              v117 = v106[411];
              v105[8] = v117;
              v118 = v106[412];
              v105[9] = v118;
              v105[10] = v118;
              v119 = v106[410];
              v105[6] = v119;
              v105[7] = v119;
              v120 = v106[413];
              v105[11] = v120;
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: PER based roaming configuration enable: %d vdev: %d high_rate_thresh: %d low_rate_thresh: %d rate_th"
                "resh_percnt: %d per_rest_time: %d monitor_time: %d min cand rssi: %d",
                v107,
                v108,
                v109,
                v110,
                v111,
                v112,
                v113,
                v114,
                "cm_roam_fill_per_roam_request",
                v119,
                v117,
                v118,
                v120);
              if ( (unsigned int)wlan_cm_tgt_send_roam_per_config(a1, v6, v105) )
                qdf_trace_msg(
                  0x68u,
                  8u,
                  "%s: fail to send roam stop",
                  v121,
                  v122,
                  v123,
                  v124,
                  v125,
                  v126,
                  v127,
                  v128,
                  "cm_roam_offload_per_config");
              _qdf_mem_free((__int64)v105);
            }
            else
            {
              _qdf_mem_free((__int64)v105);
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: fail to fill per config",
                v129,
                v130,
                v131,
                v132,
                v133,
                v134,
                v135,
                v136,
                "cm_roam_offload_per_config");
            }
          }
        }
        if ( a3 > 3u )
        {
          if ( a3 != 4 )
          {
            if ( a3 == 5 )
            {
              updated = wlan_cm_tgt_send_roam_abort_req(a1, v6);
              if ( !updated )
                goto LABEL_19;
              v69 = "%s: fail to send abort start";
              v70 = "cm_roam_abort_req";
              goto LABEL_18;
            }
            goto LABEL_47;
          }
          v300 = 0;
          v301 = 0;
          v298 = 0;
          v299 = 0;
          v202 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v6, 2);
          if ( v202 )
          {
            v211 = v202;
            mlme_set_roam_reason_better_ap(v202, 0, v203, v204, v205, v206, v207, v208, v209, v210);
            wlan_objmgr_vdev_release_ref(v211, 2u, v212, v213, v214, v215, v216, v217, v218, v219, v220);
          }
          v221 = _qdf_mem_malloc(0x10E8u, "cm_roam_update_config_req", 3737);
          if ( v221 )
          {
            v157 = v221;
            v222 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v6, 77);
            if ( v222 )
            {
              v167 = v222;
              v223 = wlan_cm_get_rso_config_fl(v222, "cm_roam_update_config_req", 3747);
              if ( v223 )
              {
                v224 = *(_QWORD *)(v167 + 152);
                if ( v224 )
                {
                  v225 = v223;
                  LOBYTE(v297[0]) = 0;
                  v302[0] = 0;
                  *(_DWORD *)v157 = (unsigned __int8)v6;
                  wlan_mlme_get_roam_bmiss_first_bcnt(a1, (char *)v297);
                  wlan_mlme_get_roam_bmiss_final_bcnt(a1, v302);
                  is_any_sta_dfs_ap_scc_by_vdev_id = policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id(a1, v6);
                  v227 = v297[0];
                  if ( (is_any_sta_dfs_ap_scc_by_vdev_id & 1) != 0 )
                  {
                    v228 = v302[0];
                    if ( LOBYTE(v297[0]) >= 2u )
                      v227 = 2;
                    if ( (unsigned __int8)v302[0] >= 5u )
                      v228 = 5;
                  }
                  else
                  {
                    v228 = v302[0];
                  }
                  *(_BYTE *)(v157 + 4) = v227;
                  *(_BYTE *)(v157 + 5) = v228;
                  LOBYTE(v297[0]) = 0;
                  *(_DWORD *)(v157 + 8) = (unsigned __int8)v6;
                  wlan_mlme_get_bmiss_timeout_on_wakeup(a1, (char *)v297);
                  *(_BYTE *)(v157 + 12) = v297[0];
                  wlan_mlme_get_bmiss_timeout_on_sleep(a1, (char *)v297);
                  *(_BYTE *)(v157 + 13) = v297[0];
                  cm_roam_fill_rssi_change_params(a1, v6, (_DWORD *)(v157 + 1056));
                  if ( (unsigned int)mlme_get_roam_state(a1, v6) == 2 )
                  {
                    cm_roam_disconnect_params(a1, v6, v157 + 4052);
                    cm_roam_triggers(a1, v6, (_DWORD *)(v157 + 4092));
                    *(_DWORD *)(v157 + 4064) = (unsigned __int8)v6;
                    wlan_mlme_get_enable_idle_roam(a1, (_BYTE *)(v157 + 4068));
                    wlan_mlme_get_idle_roam_rssi_delta(a1, (int *)(v157 + 4076));
                    wlan_mlme_get_idle_roam_inactive_time(a1, (int *)(v157 + 4084));
                    wlan_mlme_get_idle_data_packet_count(a1, (int *)(v157 + 4088));
                    wlan_mlme_get_idle_roam_min_rssi(a1, (int *)(v157 + 4080));
                    wlan_mlme_get_idle_roam_band(a1, (_DWORD *)(v157 + 4072));
                    if ( (*(_BYTE *)(v157 + 4097) & 0x40) == 0 )
                      *(_BYTE *)(v157 + 4068) = 0;
                  }
                  cm_roam_scan_offload_rssi_thresh(a1, v6, v157 + 3944, v225);
                  *(_DWORD *)(v157 + 1024) = (unsigned __int8)v6;
                  v267 = *(unsigned __int16 *)(v225 + 146);
                  *(_DWORD *)(v157 + 1028) = v267;
                  *(_DWORD *)(v157 + 1032) = v267;
                  *(_DWORD *)(v157 + 1036) = 3 * v267;
                  *(_DWORD *)(v157 + 1040) = *(_DWORD *)(v225 + 196);
                  *(_DWORD *)(v157 + 1044) = *(_DWORD *)(v225 + 200);
                  *(_DWORD *)(v157 + 1048) = *(_DWORD *)(v225 + 184);
                  *(_DWORD *)(v157 + 1052) = *(_DWORD *)(v225 + 216);
                  qdf_trace_msg(
                    0x68u,
                    8u,
                    "%s: full_scan_period:%d, empty_scan_refresh_period:%d, roam_periodic_scan_interval %d",
                    v268,
                    v269,
                    v270,
                    v271,
                    v272,
                    v273,
                    v274,
                    v275,
                    "cm_roam_scan_offload_scan_period");
                  cm_roam_scan_offload_ap_profile(a1, v167, v225, v157 + 3028);
                  cm_fill_rso_channel_list(a1, v167, v225, v157 + 3532, a4);
                  cm_roam_scan_filter(a1, v224, v6, 4, a4, v157 + 16);
                  ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD))cm_roam_scan_offload_fill_rso_configs)(
                    a1,
                    v167,
                    v225,
                    v157 + 1072,
                    v157 + 3532,
                    4,
                    a4);
                  *(_BYTE *)(v157 + 4316) = wlan_cm_get_roam_rt_stats(a1, 0);
                  *(_WORD *)(v157 + 4318) = wlan_cm_roam_get_ho_delay_config(a1);
                  *(_BYTE *)(v157 + 4320) = wlan_cm_get_exclude_rm_partial_scan_freq(a1);
                  *(_BYTE *)(v157 + 4321) = wlan_cm_roam_get_full_scan_6ghz_on_disc(a1);
                  wlan_cm_roam_cfg_get_value(a1, v6, 29, (int)&v298);
                  *(_BYTE *)(v157 + 4322) = v298;
                  wlan_cm_roam_cfg_get_value(a1, v6, 30, (int)&v298);
                  *(_BYTE *)(v157 + 4323) = v298;
                  updated = wlan_cm_tgt_send_roam_update_req(a1, v6, v157);
                  if ( !updated )
                    goto LABEL_135;
                  v276 = "%s: fail to send update config";
                  v277 = "cm_roam_update_config_req";
                  goto LABEL_134;
                }
              }
              goto LABEL_90;
            }
            v229 = "cm_roam_update_config_req";
LABEL_94:
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: vdev object is NULL for vdev %d",
              v159,
              v160,
              v161,
              v162,
              v163,
              v164,
              v165,
              v166,
              v229,
              (unsigned __int8)v6);
            updated = 4;
LABEL_136:
            _qdf_mem_free(v157);
            goto LABEL_19;
          }
        }
        else
        {
          if ( a3 != 1 )
          {
            if ( a3 != 3 )
              goto LABEL_47;
            v137 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v6, 2);
            if ( !v137 )
            {
              updated = 4;
              goto LABEL_19;
            }
            v138 = v137;
            v73 = (unsigned int *)(unsigned __int8)(a4 - 11);
            if ( (unsigned int)v73 <= 1
              && (mlme_get_roam_reason_better_ap(v137, v74, v75, v76, v77, v78, v79, v80, v81) & 1) != 0 )
            {
              qdf_trace_msg(
                0x68u,
                2u,
                "%s: Sending heartbeat failure, reason %d",
                v74,
                v75,
                v76,
                v77,
                v78,
                v79,
                v80,
                v81,
                "cm_roam_restart_req",
                a4);
              hb_ap_rssi = mlme_get_hb_ap_rssi(v138, v139, v140, v141, v142, v143, v144, v145, v146);
              v148 = wlan_cm_send_beacon_miss(v6, hb_ap_rssi);
              mlme_set_roam_reason_better_ap(v138, 0, v148, v149, v150, v151, v152, v153, v154, v155);
            }
            v82 = v138;
            v83 = 2;
LABEL_24:
            wlan_objmgr_vdev_release_ref(v82, v83, v73, v74, v75, v76, v77, v78, v79, v80, v81);
LABEL_25:
            updated = 0;
            goto LABEL_19;
          }
          memset(v297, 0, sizeof(v297));
          v156 = _qdf_mem_malloc(0x1198u, "cm_roam_start_req", 3631);
          if ( v156 )
          {
            v157 = v156;
            v158 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, v6, 77);
            if ( v158 )
            {
              v167 = v158;
              v168 = wlan_cm_get_rso_config_fl(v158, "cm_roam_start_req", 3641);
              if ( v168 )
              {
                v178 = *(_QWORD *)(v167 + 152);
                if ( v178 )
                {
                  v179 = v168;
                  v180 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                           a1,
                           v6,
                           2);
                  if ( v180 )
                  {
                    v189 = v180;
                    mlme_set_roam_reason_better_ap(v180, 0, v181, v182, v183, v184, v185, v186, v187, v188);
                    wlan_objmgr_vdev_release_ref(v189, 2u, v190, v191, v192, v193, v194, v195, v196, v197, v198);
                  }
                  LOBYTE(v298) = 0;
                  v302[0] = 0;
                  *(_DWORD *)(v157 + 108) = (unsigned __int8)v6;
                  wlan_mlme_get_roam_bmiss_first_bcnt(a1, (char *)&v298);
                  wlan_mlme_get_roam_bmiss_final_bcnt(a1, v302);
                  v199 = policy_mgr_is_any_sta_dfs_ap_scc_by_vdev_id(a1, v6);
                  v200 = v298;
                  if ( (v199 & 1) != 0 )
                  {
                    v201 = v302[0];
                    if ( (unsigned __int8)v298 >= 2u )
                      v200 = 2;
                    if ( (unsigned __int8)v302[0] >= 5u )
                      v201 = 5;
                  }
                  else
                  {
                    v201 = v302[0];
                  }
                  *(_BYTE *)(v157 + 112) = v200;
                  *(_BYTE *)(v157 + 113) = v201;
                  LOBYTE(v298) = 0;
                  *(_DWORD *)(v157 + 116) = (unsigned __int8)v6;
                  wlan_mlme_get_bmiss_timeout_on_wakeup(a1, (char *)&v298);
                  *(_BYTE *)(v157 + 120) = v298;
                  wlan_mlme_get_bmiss_timeout_on_sleep(a1, (char *)&v298);
                  v230 = v298;
                  LOBYTE(v298) = 0;
                  *(_BYTE *)(v157 + 121) = v230;
                  *(_DWORD *)(v157 + 124) = (unsigned __int8)v6;
                  wlan_mlme_get_roam_reason_vsie_status(a1, &v298);
                  *(_BYTE *)(v157 + 128) = v298;
                  cm_roam_triggers(a1, v6, (_DWORD *)(v157 + 132));
                  cm_roam_fill_rssi_change_params(a1, v6, (_DWORD *)(v157 + 2344));
                  LOBYTE(v298) = 0;
                  v302[0] = 0;
                  *(_BYTE *)(v157 + 3276) = v6;
                  wlan_mlme_get_mawc_enabled(a1, &v298);
                  wlan_mlme_get_mawc_roam_enabled(a1, v302);
                  *(_BYTE *)(v157 + 3277) = v298 & v302[0];
                  wlan_mlme_get_mawc_roam_traffic_threshold(a1, (int *)(v157 + 3280));
                  wlan_mlme_get_mawc_roam_ap_rssi_threshold(a1, (int *)(v157 + 3284));
                  wlan_mlme_get_mawc_roam_rssi_high_adjust(a1, (char *)(v157 + 3288));
                  wlan_mlme_get_mawc_roam_rssi_low_adjust(a1, (char *)(v157 + 3289));
                  *(_DWORD *)(v157 + 4404) = (unsigned __int8)v6;
                  wlan_mlme_get_bss_load_threshold(a1, (int *)(v157 + 4408));
                  wlan_mlme_get_bss_load_sample_time(a1, (int *)(v157 + 4412));
                  wlan_mlme_get_bss_load_alpha(a1, (int *)(v157 + 4416));
                  wlan_mlme_get_bss_load_rssi_threshold_6ghz(a1, (int *)(v157 + 4420));
                  wlan_mlme_get_bss_load_rssi_threshold_5ghz(a1, (int *)(v157 + 4424));
                  wlan_mlme_get_bss_load_rssi_threshold_24ghz(a1, (int *)(v157 + 4428));
                  cm_roam_disconnect_params(a1, v6, v157 + 4432);
                  *(_DWORD *)(v157 + 4444) = (unsigned __int8)v6;
                  wlan_mlme_get_enable_idle_roam(a1, (_BYTE *)(v157 + 4448));
                  wlan_mlme_get_idle_roam_rssi_delta(a1, (int *)(v157 + 4456));
                  wlan_mlme_get_idle_roam_inactive_time(a1, (int *)(v157 + 4464));
                  wlan_mlme_get_idle_data_packet_count(a1, (int *)(v157 + 4468));
                  wlan_mlme_get_idle_roam_min_rssi(a1, (int *)(v157 + 4460));
                  wlan_mlme_get_idle_roam_band(a1, (_DWORD *)(v157 + 4452));
                  if ( (*(_BYTE *)(v157 + 137) & 0x40) == 0 )
                    *(_BYTE *)(v157 + 4448) = 0;
                  cm_roam_scan_offload_rssi_thresh(a1, v6, v157, v179);
                  *(_DWORD *)(v157 + 356) = (unsigned __int8)v6;
                  v231 = *(unsigned __int16 *)(v179 + 146);
                  *(_DWORD *)(v157 + 360) = v231;
                  *(_DWORD *)(v157 + 364) = v231;
                  *(_DWORD *)(v157 + 368) = 3 * v231;
                  *(_DWORD *)(v157 + 372) = *(_DWORD *)(v179 + 196);
                  *(_DWORD *)(v157 + 376) = *(_DWORD *)(v179 + 200);
                  *(_DWORD *)(v157 + 380) = *(_DWORD *)(v179 + 184);
                  *(_DWORD *)(v157 + 384) = *(_DWORD *)(v179 + 216);
                  qdf_trace_msg(
                    0x68u,
                    8u,
                    "%s: full_scan_period:%d, empty_scan_refresh_period:%d, roam_periodic_scan_interval %d",
                    v232,
                    v233,
                    v234,
                    v235,
                    v236,
                    v237,
                    v238,
                    v239,
                    "cm_roam_scan_offload_scan_period");
                  cm_roam_scan_offload_ap_profile(a1, v167, v179, v157 + 2360);
                  cm_fill_rso_channel_list(a1, v167, v179, v157 + 2864, a4);
                  cm_roam_scan_filter(a1, v178, v6, 1, a4, v157 + 3296);
                  ((void (__fastcall *)(__int64, __int64, __int64, __int64, __int64, __int64, _QWORD))cm_roam_scan_offload_fill_rso_configs)(
                    a1,
                    v167,
                    v179,
                    v157 + 388,
                    v157 + 2864,
                    1,
                    a4);
                  v240 = mlme_get_psoc_ext_obj_fl(a1);
                  if ( !v240 )
                  {
LABEL_106:
                    v255 = mlme_get_psoc_ext_obj_fl(a1);
                    if ( !v255 )
                      goto LABEL_132;
                    *(_DWORD *)(v157 + 4336) = *(unsigned __int8 *)(v167 + 104);
                    *(_DWORD *)(v157 + 4340) = *(_DWORD *)(v255 + 2520);
                    if ( (*(_BYTE *)(v255 + 2524) & 0x3F) == 0 )
                    {
                      qdf_trace_msg(
                        0x68u,
                        2u,
                        "%s: No valid neighbor report offload params %x",
                        v256,
                        v257,
                        v258,
                        v259,
                        v260,
                        v261,
                        v262,
                        v263,
                        "cm_roam_offload_11k_params");
                      *(_DWORD *)(v157 + 4340) = 0;
                      goto LABEL_132;
                    }
                    *(_QWORD *)(v157 + 4360) = -1;
                    *(_QWORD *)(v157 + 4352) = -1;
                    *(_QWORD *)(v157 + 4344) = -1;
                    v264 = *(_BYTE *)(v255 + 2524);
                    if ( (v264 & 1) != 0 )
                    {
                      *(_DWORD *)(v157 + 4344) = *(_DWORD *)(v255 + 2528);
                      v264 = *(_BYTE *)(v255 + 2524);
                      if ( (v264 & 2) == 0 )
                      {
LABEL_110:
                        if ( (v264 & 4) == 0 )
                          goto LABEL_111;
                        goto LABEL_127;
                      }
                    }
                    else if ( (*(_BYTE *)(v255 + 2524) & 2) == 0 )
                    {
                      goto LABEL_110;
                    }
                    *(_DWORD *)(v157 + 4348) = *(_DWORD *)(v255 + 2532);
                    v264 = *(_BYTE *)(v255 + 2524);
                    if ( (v264 & 4) == 0 )
                    {
LABEL_111:
                      if ( (v264 & 8) == 0 )
                        goto LABEL_112;
                      goto LABEL_128;
                    }
LABEL_127:
                    *(_DWORD *)(v157 + 4352) = *(_DWORD *)(v255 + 2536);
                    v264 = *(_BYTE *)(v255 + 2524);
                    if ( (v264 & 8) == 0 )
                    {
LABEL_112:
                      if ( (v264 & 0x10) == 0 )
                        goto LABEL_113;
                      goto LABEL_129;
                    }
LABEL_128:
                    *(_DWORD *)(v157 + 4356) = *(_DWORD *)(v255 + 2540);
                    v264 = *(_BYTE *)(v255 + 2524);
                    if ( (v264 & 0x10) == 0 )
                    {
LABEL_113:
                      if ( (v264 & 0x20) == 0 )
                        goto LABEL_115;
                      goto LABEL_114;
                    }
LABEL_129:
                    *(_DWORD *)(v157 + 4360) = *(_DWORD *)(v255 + 2544);
                    if ( (*(_BYTE *)(v255 + 2524) & 0x20) == 0 )
                    {
LABEL_115:
                      cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(v167, v256, v257, v258, v259, v260, v261, v262, v263);
                      if ( cmpt_obj )
                      {
                        v266 = *(unsigned __int8 *)(cmpt_obj + 162);
                        if ( *(_BYTE *)(cmpt_obj + 162) )
                        {
                          *(_BYTE *)(v157 + 4368) = v266;
                          qdf_mem_copy((void *)(v157 + 4369), (const void *)(cmpt_obj + 129), v266);
                        }
                        else
                        {
                          *(_BYTE *)(v157 + 4368) = 0;
                        }
                      }
LABEL_132:
                      *(_BYTE *)(v157 + 4472) = wlan_cm_get_roam_rt_stats(a1, 0);
                      *(_WORD *)(v157 + 4496) = wlan_cm_roam_get_ho_delay_config(a1);
                      *(_BYTE *)(v157 + 4498) = wlan_cm_get_exclude_rm_partial_scan_freq(a1);
                      *(_BYTE *)(v157 + 4499) = wlan_cm_roam_get_full_scan_6ghz_on_disc(a1);
                      wlan_cm_roam_cfg_get_value(a1, v6, 29, (int)v297);
                      *(_BYTE *)(v157 + 4500) = v297[0];
                      wlan_cm_roam_cfg_get_value(a1, v6, 30, (int)v297);
                      *(_BYTE *)(v157 + 4501) = v297[0];
                      updated = wlan_cm_tgt_send_roam_start_req(a1, v6, v157);
                      if ( updated )
                      {
                        v276 = "%s: fail to send roam start";
                        v277 = "cm_roam_start_req";
LABEL_134:
                        qdf_trace_msg(0x68u, 8u, v276, v170, v171, v172, v173, v174, v175, v176, v177, v277);
                      }
LABEL_135:
                      wlan_objmgr_vdev_release_ref(v167, 0x4Du, v169, v170, v171, v172, v173, v174, v175, v176, v177);
                      goto LABEL_136;
                    }
LABEL_114:
                    *(_DWORD *)(v157 + 4364) = *(_DWORD *)(v255 + 2548);
                    goto LABEL_115;
                  }
                  v241 = *(unsigned __int8 *)(v167 + 104);
                  v242 = (_DWORD *)v240;
                  *(_BYTE *)(v157 + 4304) = v241;
                  v302[0] = 0;
                  v300 = 0;
                  v301 = 0;
                  v298 = 0;
                  v299 = 0;
                  v243 = mlme_get_psoc_ext_obj_fl(a1);
                  if ( v243 )
                  {
                    v244 = *(_DWORD *)(v243 + 5652);
                    *(_DWORD *)(v157 + 4308) = v244;
                    if ( v244 )
                    {
                      wlan_cm_roam_cfg_get_value(a1, v241, 31, (int)&v298);
                      v245 = (unsigned __int8)v299;
                      assoc_btm_cap = wlan_cm_get_assoc_btm_cap(a1, v241);
                      if ( (assoc_btm_cap & 1) != 0 && !v245 )
                      {
                        wlan_cm_roam_cfg_get_value(a1, v241, 23, (int)&v298);
                        v278 = (unsigned __int8)v299;
                        wlan_mlme_is_hs_20_btm_offload_disabled(a1, v302);
                        if ( v278 != 1 || v302[0] != 1 )
                        {
                          btm_abridge_flag = wlan_mlme_get_btm_abridge_flag(a1);
                          if ( (btm_abridge_flag & 1) == 0 )
                            *(_DWORD *)(v157 + 4308) &= ~0x80u;
                          if ( cm_is_mbo_ap_without_pmf(a1, v241) )
                          {
                            v296 = 0;
                            *(_DWORD *)(v157 + 4308) = 0;
                          }
                          else
                          {
                            v296 = *(unsigned int *)(v157 + 4308);
                          }
                          qdf_trace_msg(
                            0x68u,
                            8u,
                            "%s: Abridge flag: %d, btm offload: %u",
                            v288,
                            v289,
                            v290,
                            v291,
                            v292,
                            v293,
                            v294,
                            v295,
                            "cm_update_btm_offload_config",
                            btm_abridge_flag & 1,
                            v296);
                          goto LABEL_105;
                        }
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "%s: RSO cmd: %d is_hs_20_ap:%d",
                          v279,
                          v280,
                          v281,
                          v282,
                          v283,
                          v284,
                          v285,
                          v286,
                          "cm_update_btm_offload_config",
                          1,
                          1);
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "%s: disable btm offload vdev:%d btm_cap: %d is_btm: %d",
                          v247,
                          v248,
                          v249,
                          v250,
                          v251,
                          v252,
                          v253,
                          v254,
                          "cm_update_btm_offload_config",
                          v241,
                          assoc_btm_cap & 1,
                          v245);
                      }
                      *(_DWORD *)(v157 + 4308) = 0;
                    }
                  }
LABEL_105:
                  *(_DWORD *)(v157 + 4312) = v242[1414];
                  *(_DWORD *)(v157 + 4316) = v242[1415];
                  *(_DWORD *)(v157 + 4320) = v242[1416];
                  *(_DWORD *)(v157 + 4324) = v242[1418];
                  *(_DWORD *)(v157 + 4328) = v242[1419];
                  *(_DWORD *)(v157 + 4332) = v242[1420];
                  goto LABEL_106;
                }
              }
LABEL_90:
              updated = 4;
              goto LABEL_135;
            }
            v229 = "cm_roam_start_req";
            goto LABEL_94;
          }
        }
        updated = 2;
        goto LABEL_19;
      }
    }
    v67 = "%s: Scan Command not sent to FW and cmd=%d";
    v68 = 4;
    goto LABEL_14;
  }
  updated = v48;
  wlan_objmgr_vdev_release_ref(v17, 0x4Du, v49, v50, v51, v52, v53, v54, v55, v56, v57);
  if ( updated == 11 )
    goto LABEL_25;
LABEL_17:
  v69 = "%s: ROAM: not allowed";
  v70 = "cm_roam_send_rso_cmd";
LABEL_18:
  qdf_trace_msg(0x68u, 8u, v69, v59, v60, v61, v62, v63, v64, v65, v66, v70);
LABEL_19:
  _ReadStatusReg(SP_EL0);
  return updated;
}
