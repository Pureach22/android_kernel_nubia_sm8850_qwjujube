__int64 __fastcall wma_post_vdev_create_setup(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  _QWORD *v19; // x22
  __int64 *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 *v29; // x21
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 result; // x0
  unsigned int v39; // w20
  __int64 cmpt_obj; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x23
  _QWORD *v50; // x0
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  __int64 v59; // x8
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  __int64 v68; // x0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  __int64 v77; // x2
  __int64 v78; // x25
  unsigned int v79; // w9
  __int64 v80; // x24
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  unsigned int v89; // w0
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w0
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned int set_param; // w0
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  unsigned int v116; // w19
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  const char *v125; // x2
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  int v134; // w8
  unsigned int fw_active_apf_mode; // w24
  unsigned int v136; // w0
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
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
  __int64 v185; // x22
  unsigned int v186; // w21
  _QWORD *v187; // x0
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  unsigned int v196; // w0
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  __int64 v205; // x4
  char v206[4]; // [xsp+4h] [xbp-1Ch] BYREF
  char v207[4]; // [xsp+8h] [xbp-18h] BYREF
  _DWORD v208[3]; // [xsp+Ch] [xbp-14h] BYREF
  __int64 v209; // [xsp+18h] [xbp-8h]

  v209 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  context = _cds_get_context(53, (__int64)"wma_post_vdev_create_setup", a2, a3, a4, a5, a6, a7, a8, a9);
  v207[0] = 0;
  v206[0] = 0;
  if ( !context )
    goto LABEL_4;
  v19 = context;
  v20 = _cds_get_context(54, (__int64)"wma_post_vdev_create_setup", v11, v12, v13, v14, v15, v16, v17, v18);
  if ( !v20 )
    goto LABEL_4;
  v29 = v20;
  if ( (unsigned int)wlan_objmgr_vdev_try_get_ref(a1, 8u, v21, v22, v23, v24, v25, v26, v27, v28) )
    goto LABEL_4;
  v39 = *(unsigned __int8 *)(a1 + 104);
  *(_QWORD *)(v29[65] + 488LL * *(unsigned __int8 *)(a1 + 104)) = a1;
  *(_BYTE *)(v29[65] + 488LL * v39 + 184) = 1;
  cmpt_obj = wlan_vdev_mlme_get_cmpt_obj(a1, v30, v31, v32, v33, v34, v35, v36, v37);
  if ( cmpt_obj )
  {
    v49 = cmpt_obj;
    v50 = _cds_get_context(54, (__int64)"wma_vdev_update_pause_bitmap", v41, v42, v43, v44, v45, v46, v47, v48);
    if ( v50 )
    {
      if ( *((unsigned __int16 *)v50 + 81) <= v39 )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid vdev_id: %d",
          v51,
          v52,
          v53,
          v54,
          v55,
          v56,
          v57,
          v58,
          "wma_vdev_update_pause_bitmap",
          v39);
      }
      else
      {
        v59 = v50[65] + 488LL * v39;
        if ( v59 )
          *(_WORD *)(v59 + 238) = 0;
        else
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Interface is NULL",
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            "wma_vdev_update_pause_bitmap");
      }
    }
    *(_DWORD *)(v29[65] + 488LL * v39 + 164) = *(unsigned __int8 *)(v49 + 163);
    *(_DWORD *)(v29[65] + 488LL * v39 + 168) = *(unsigned __int8 *)(v49 + 164);
    v68 = v19[2694];
    v208[0] = 0;
    if ( (unsigned int)ucfg_mlme_get_sta_keepalive_method(v68, v208) )
    {
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to get ini config for keep sta alive method",
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        v75,
        v76,
        "wma_get_keep_sta_alive_method");
      v77 = 1;
    }
    else
    {
      v78 = jiffies;
      if ( wma_get_keep_sta_alive_method___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x36u,
          8u,
          "%s: ini_val: %u",
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          v75,
          v76,
          "wma_get_keep_sta_alive_method",
          v208[0]);
        wma_get_keep_sta_alive_method___last_ticks = v78;
      }
      if ( v208[0] == 3 )
        v79 = 2;
      else
        v79 = 1;
      if ( v208[0] == 2 )
        v77 = 4;
      else
        v77 = v79;
    }
    if ( *(_BYTE *)(v49 + 163) == 2 )
    {
      v80 = v19[1];
      v81 = wma_set_sta_keep_alive(v29, v39, v77, *(unsigned int *)(v80 + 3300), 0, 0, 0);
      if ( (wmi_service_enabled(*v29, 0x6Au, v81, v82, v83, v84, v85, v86, v87, v88) & 1) != 0 )
        wma_set_sta_sa_query_param(v29, v39);
      v89 = wma_set_sw_retry_threshold(v80 + 2688);
      if ( v89 )
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: failed to set sw retry threshold (status = %d)",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "wma_post_vdev_create_setup",
          v89);
      v98 = wma_set_sw_retry_threshold_per_ac(v29, v39, v80 + 2688);
      if ( v98 )
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: failed to set sw retry threshold per ac(status = %d)",
          v99,
          v100,
          v101,
          v102,
          v103,
          v104,
          v105,
          v106,
          "wma_post_vdev_create_setup",
          v98);
    }
    set_param = wma_vdev_create_set_param(a1);
    if ( set_param )
    {
      v116 = set_param;
      qdf_trace_msg(
        0x36u,
        2u,
        "%s: Failed to setup Vdev create set param for vdev: %d",
        v108,
        v109,
        v110,
        v111,
        v112,
        v113,
        v114,
        v115,
        "wma_post_vdev_create_setup",
        v39);
      result = v116;
      goto LABEL_5;
    }
    if ( (unsigned int)policy_mgr_get_dynamic_mcc_adaptive_sch(v19[2694], v207) )
    {
      v125 = "%s: Failed to get value for WNI_CFG_ENABLE_MCC_ADAPTIVE_SCHED, leaving unchanged";
    }
    else
    {
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: setting ini value for WNI_CFG_ENABLE_MCC_ADAPTIVE_SCHED: %d",
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        "wma_post_vdev_create_setup",
        (unsigned __int8)v207[0]);
      if ( !(unsigned int)wma_set_enable_disable_mcc_adaptive_scheduler(
                            (unsigned __int8)v207[0],
                            v126,
                            v127,
                            v128,
                            v129,
                            v130,
                            v131,
                            v132,
                            v133) )
      {
LABEL_38:
        v134 = *(unsigned __int8 *)(v49 + 163);
        if ( v134 == 2 )
        {
          if ( (ucfg_pmo_is_apf_enabled(v29[3]) & 1) != 0
            && (ucfg_pmo_is_configure_apf_per_screen_state(v29[3]) & 1) == 0 )
          {
            fw_active_apf_mode = wma_get_fw_active_apf_mode(*((unsigned int *)v29 + 838));
            v136 = wma_get_fw_active_apf_mode(*((unsigned int *)v29 + 839));
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: Configuring Active APF Mode UC:%d MC/BC:%d for vdev %u",
              v137,
              v138,
              v139,
              v140,
              v141,
              v142,
              v143,
              v144,
              "wma_post_vdev_create_setup",
              fw_active_apf_mode,
              v136,
              v39);
            if ( (unsigned int)wmi_unified_set_active_apf_mode_cmd(*v29) )
              qdf_trace_msg(
                0x36u,
                2u,
                "%s: Failed to configure active APF mode",
                v145,
                v146,
                v147,
                v148,
                v149,
                v150,
                v151,
                v152,
                "wma_post_vdev_create_setup");
          }
          v134 = *(unsigned __int8 *)(v49 + 163);
          if ( v134 == 2 )
          {
            if ( (ucfg_pmo_is_apf_enabled(v29[3]) & 1) != 0
              && (wmi_service_enabled(*v29, 0x9Du, v153, v154, v155, v156, v157, v158, v159, v160) & 1) != 0 )
            {
              ucfg_pmo_get_apfv6_offload_bitmap(v29[3]);
              if ( (unsigned int)wmi_unified_set_apf_supported_offload_bitmap_cmd(*v29) )
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: Failed to configure APF supported offload bitmap",
                  v161,
                  v162,
                  v163,
                  v164,
                  v165,
                  v166,
                  v167,
                  v168,
                  "wma_post_vdev_create_setup");
            }
            v134 = *(unsigned __int8 *)(v49 + 163);
            if ( v134 == 2 )
            {
              if ( (ucfg_pmo_is_apf_enabled(v29[3]) & 1) != 0 && (ucfg_pmo_is_apf_mode_enabled(v29[3]) & 1) != 0 )
              {
                ucfg_pmo_get_apf_mode(v29[3]);
                if ( (unsigned int)wmi_unified_set_apf_mode_bitmap_cmd(*v29) )
                  qdf_trace_msg(
                    0x36u,
                    2u,
                    "%s: Failed to configure APF mode bitmap",
                    v169,
                    v170,
                    v171,
                    v172,
                    v173,
                    v174,
                    v175,
                    v176,
                    "wma_post_vdev_create_setup");
              }
              v134 = *(unsigned __int8 *)(v49 + 163);
              if ( v134 == 2 )
              {
                if ( *(_BYTE *)(v49 + 164) )
                  goto LABEL_60;
                wma_set_vdev_latency_level_param(v19, v39);
                v134 = *(unsigned __int8 *)(v49 + 163);
              }
            }
          }
        }
        if ( (unsigned int)(v134 - 4) >= 3 && v134 != 2 && (v134 != 1 || *(_BYTE *)(v49 + 164) != 1) )
          goto LABEL_70;
LABEL_60:
        if ( (unsigned int)ucfg_get_enable_sifs_burst(v29[3], v206) )
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Failed to get sifs burst value, use default",
            v177,
            v178,
            v179,
            v180,
            v181,
            v182,
            v183,
            v184,
            "wma_post_vdev_create_setup");
        v185 = *v29;
        v186 = (unsigned __int8)v206[0];
        v187 = _cds_get_context(54, (__int64)"wma_is_vdev_valid", v177, v178, v179, v180, v181, v182, v183, v184);
        if ( v187 )
        {
          if ( *((unsigned __int16 *)v187 + 81) <= v39 )
          {
            qdf_trace_msg(
              0x36u,
              8u,
              "%s: vdev_id: %d is invalid, max_bssid: %d",
              v188,
              v189,
              v190,
              v191,
              v192,
              v193,
              v194,
              v195,
              "wma_is_vdev_valid",
              v39);
          }
          else if ( (*(_BYTE *)(v187[65] + 488LL * v39 + 184) & 1) != 0 )
          {
            v208[0] = v39;
            v208[1] = 48;
            v208[2] = v186;
            v196 = wmi_unified_vdev_set_param_send(v185);
            v205 = v196;
            if ( !v196 )
              goto LABEL_70;
            goto LABEL_69;
          }
        }
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: vdev_id: %d is not active reject the req: param id %d val %d",
          v188,
          v189,
          v190,
          v191,
          v192,
          v193,
          v194,
          v195,
          "wma_vdev_set_param",
          v39,
          48,
          v186);
        v205 = 4;
LABEL_69:
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: WMI_PDEV_PARAM_BURST_ENABLE set failed %d",
          v197,
          v198,
          v199,
          v200,
          v201,
          v202,
          v203,
          v204,
          "wma_post_vdev_create_setup",
          v205);
LABEL_70:
        wma_vdev_set_data_tx_callback(a1);
        result = 0;
        goto LABEL_5;
      }
      v125 = "%s: Failed to set WNI_CFG_ENABLE_MCC_ADAPTIVE_SCHED";
    }
    qdf_trace_msg(0x36u, 2u, v125, v117, v118, v119, v120, v121, v122, v123, v124, "wma_post_vdev_create_setup");
    goto LABEL_38;
  }
  qdf_trace_msg(
    0x36u,
    2u,
    "%s: Failed to get vdev mlme obj!",
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    "wma_post_vdev_create_setup");
  wma_cleanup_vdev(a1, v60, v61, v62, v63, v64, v65, v66, v67);
LABEL_4:
  result = 16;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
