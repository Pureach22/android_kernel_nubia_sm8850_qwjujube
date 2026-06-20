__int64 __fastcall wlan_hdd_cfg80211_start_ap(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 mode_specific_conn_info; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x20
  const char *v25; // x2
  int v26; // w0
  unsigned int v27; // w21
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 *v36; // x21
  const char *v37; // x0
  unsigned int v38; // w25
  const char *v39; // x27
  int v40; // w21
  unsigned int v41; // w26
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  _BOOL4 is_5_mhz_enabled; // w24
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w25
  int v68; // w24
  int *v69; // x25
  int *v70; // x21
  unsigned int v71; // w27
  unsigned int *v72; // x26
  unsigned int v73; // w27
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned int v82; // w1
  int v83; // w8
  __int64 *v84; // x21
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  unsigned int v101; // w25
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  int v126; // w21
  unsigned int v127; // w25
  bool is_5ghz_ch_freq; // w8
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  __int64 v137; // x0
  int _5g_bonded_channel_state_for_pwrmode; // w0
  unsigned int v139; // w25
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  int v148; // w8
  unsigned int v149; // w9
  int v150; // w10
  _BOOL4 v151; // w21
  char is_sta_p2p_ndp_supported; // w0
  char is_sta_sap_ndp_supported; // w0
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  unsigned int v171; // w0
  __int64 vdev_by_user; // x0
  int v173; // w8
  __int64 v174; // x27
  __int64 adapter; // x0
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  __int64 v184; // x25
  __int64 v185; // x8
  int v186; // w19
  double v187; // d0
  double v188; // d1
  double v189; // d2
  double v190; // d3
  double v191; // d4
  double v192; // d5
  double v193; // d6
  double v194; // d7
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
  __int64 v211; // x1
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  unsigned int chandef_type; // w4
  int v221; // w8
  int v222; // w9
  int v223; // w8
  char v224; // w1
  __int64 *v225; // x0
  double v226; // d0
  __int64 v227; // x1
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  unsigned int started; // w0
  __int64 v236; // x9
  __int64 v237; // x2
  unsigned int v238; // w22
  double v239; // d0
  double v240; // d1
  double v241; // d2
  double v242; // d3
  double v243; // d4
  double v244; // d5
  double v245; // d6
  double v246; // d7
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  double v255; // d0
  double v256; // d1
  double v257; // d2
  double v258; // d3
  double v259; // d4
  double v260; // d5
  double v261; // d6
  double v262; // d7
  __int64 v263; // x0
  __int64 v264; // x21
  unsigned __int64 v270; // x10
  __int64 v271; // [xsp+0h] [xbp-90h]
  __int64 v272; // [xsp+8h] [xbp-88h]
  __int64 v273; // [xsp+10h] [xbp-80h]
  unsigned int v274; // [xsp+1Ch] [xbp-74h]
  __int64 *v275; // [xsp+20h] [xbp-70h]
  unsigned int v276; // [xsp+28h] [xbp-68h]
  unsigned int v277; // [xsp+2Ch] [xbp-64h]
  unsigned int v278; // [xsp+2Ch] [xbp-64h]
  __int64 *v279; // [xsp+30h] [xbp-60h]
  __int64 v280; // [xsp+38h] [xbp-58h] BYREF
  _QWORD v281[2]; // [xsp+40h] [xbp-50h] BYREF
  bool v282; // [xsp+54h] [xbp-3Ch] BYREF
  __int64 v283; // [xsp+58h] [xbp-38h] BYREF
  __int64 v284; // [xsp+60h] [xbp-30h] BYREF
  _QWORD v285[2]; // [xsp+68h] [xbp-28h] BYREF
  char v286[4]; // [xsp+78h] [xbp-18h] BYREF
  char v287[4]; // [xsp+7Ch] [xbp-14h] BYREF
  int v288; // [xsp+80h] [xbp-10h] BYREF
  unsigned __int8 v289; // [xsp+84h] [xbp-Ch]
  __int64 v290; // [xsp+88h] [xbp-8h]

  v290 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v280 = 0;
  result = _osif_vdev_sync_op_start(a2, &v280, "wlan_hdd_cfg80211_start_ap");
  if ( !(_DWORD)result )
  {
    v287[0] = 0;
    v286[0] = 0;
    v285[0] = 0;
    v285[1] = 0;
    v283 = 0;
    v284 = 0;
    v282 = 0;
    v289 = 0;
    v288 = 0;
    mode_specific_conn_info = qdf_trace_msg(
                                0x33u,
                                8u,
                                "%s: enter",
                                v7,
                                v8,
                                v9,
                                v10,
                                v11,
                                v12,
                                v13,
                                v14,
                                "__wlan_hdd_cfg80211_start_ap");
    v24 = *(_QWORD *)(a2 + 55512);
    if ( !v24 )
    {
      v25 = "%s: invalid link_info";
LABEL_7:
      qdf_trace_msg(0x33u, 2u, v25, v16, v17, v18, v19, v20, v21, v22, v23, "__wlan_hdd_cfg80211_start_ap");
      goto LABEL_9;
    }
    while ( 1 )
    {
      _X8 = (unsigned __int64 *)(v24 + 4416);
      __asm { PRFM            #0x11, [X8] }
      do
        v270 = __ldxr(_X8);
      while ( __stxr(v270 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
      if ( (unsigned int)hdd_get_conparam(mode_specific_conn_info) == 5 )
      {
        v25 = "%s: Command not allowed in FTM mode";
        goto LABEL_7;
      }
      if ( (unsigned int)_wlan_hdd_validate_vdev_id(*(unsigned __int8 *)(v24 + 8), "__wlan_hdd_cfg80211_start_ap") )
        goto LABEL_9;
      qdf_mtrace(51, 51, 0x1Au, *(_BYTE *)(v24 + 8), a3[52]);
      if ( *(_DWORD *)(a2 + 2688) != 1885692259 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: HDD adapter magic is invalid",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "__wlan_hdd_cfg80211_start_ap");
        v27 = -19;
        goto LABEL_11;
      }
      v36 = *(__int64 **)(a2 + 2712);
      v26 = _wlan_hdd_validate_context(v36, "__wlan_hdd_cfg80211_start_ap");
      if ( v26 )
        goto LABEL_10;
      v277 = *(unsigned __int8 *)(v24 + 8);
      v37 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
      v38 = *(_DWORD *)(a2 + 2728);
      v39 = v37;
      v279 = v36;
      v40 = a3[2];
      v41 = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
      is_5_mhz_enabled = cds_is_5_mhz_enabled(v42, v43, v44, v45, v46, v47, v48, v49);
      LODWORD(v271) = v40;
      LODWORD(v273) = cds_is_10_mhz_enabled(v51, v52, v53, v54, v55, v56, v57, v58);
      LODWORD(v272) = is_5_mhz_enabled;
      qdf_trace_msg(
        0x33u,
        4u,
        "%s(vdevid-%d): START AP: mode %s(%d) %d bw %d (5MHz %d 10MHz %d)",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        a2 + 296,
        v277,
        v39,
        v38,
        v41,
        v271,
        v272,
        v273);
      if ( (unsigned int)policy_mgr_is_hw_mode_change_in_progress(*v279)
        && (unsigned int)policy_mgr_wait_for_connection_update(*v279) )
      {
        goto LABEL_17;
      }
      hdd_reg_wait_for_country_change(v279);
      v67 = ((__int64 (__fastcall *)(_QWORD))wlan_hdd_get_channel_bw)((unsigned int)a3[2]);
      v68 = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
      if ( wlan_reg_is_6ghz_chan_freq(v68)
        && (wlan_reg_is_6ghz_band_set(v279[1], v16, v17, v18, v19, v20, v21, v22, v23) & 1) == 0 )
      {
        v25 = "%s: 6 GHz band disabled.";
        goto LABEL_7;
      }
      v278 = v67;
      v69 = a3 + 3;
      v70 = a3 + 4;
      v275 = (__int64 *)(a3 + 2);
      if ( (*(_DWORD *)(a2 + 2728) | 2) == 3 )
      {
        v71 = v68;
        v72 = a3;
        if ( (wlan_hdd_is_ap_ap_force_scc_override(v24, a3, &v283) & 1) != 0 )
        {
          v70 = (int *)v285;
          v69 = (int *)&v284 + 1;
          v71 = *(_DWORD *)(v283 + 4);
          v275 = &v284;
          v72 = (unsigned int *)&v283;
          v278 = ((__int64 (__fastcall *)(_QWORD))wlan_hdd_get_channel_bw)((unsigned int)v284);
        }
      }
      else
      {
        v71 = v68;
        v72 = a3;
      }
      v276 = v71;
      v73 = policy_mgr_qdf_opmode_to_pm_con_mode(
              *v279,
              *(_DWORD *)(a2 + 2728),
              *(_BYTE *)(*(_QWORD *)(a2 + 55512) + 8LL),
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23);
      if ( (unsigned int)ucfg_policy_mgr_get_sap_mandt_chnl(*v279, v287) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: can't get mandatory channel list",
          v74,
          v75,
          v76,
          v77,
          v78,
          v79,
          v80,
          v81,
          "__wlan_hdd_cfg80211_start_ap");
      if ( v287[0] && v73 == 1 )
        policy_mgr_init_sap_mandatory_chan(*v279, *(_DWORD *)(*(_QWORD *)v72 + 4LL));
      *(_BYTE *)(v24 + 733) = cds_freq_to_chan(*v69);
      *(_BYTE *)(v24 + 734) = cds_freq_to_chan(*v70);
      v82 = *(unsigned __int8 *)(v24 + 8);
      *(_DWORD *)(v24 + 736) = *v69;
      v83 = *v70;
      v84 = v279;
      *(_DWORD *)(v24 + 740) = v83;
      if ( (policy_mgr_is_sap_allowed_on_dfs_freq(
              v279[1],
              v82,
              *(_DWORD *)(*(_QWORD *)v72 + 4LL),
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92)
          & 1) == 0 )
        goto LABEL_9;
      if ( (policy_mgr_is_sap_go_interface_allowed_on_indoor(
              v279[1],
              *(unsigned __int8 *)(v24 + 8),
              *(_DWORD *)(*(_QWORD *)v72 + 4LL))
          & 1) == 0 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: SAP start not allowed on indoor channel %d",
          v93,
          v94,
          v95,
          v96,
          v97,
          v98,
          v99,
          v100,
          "__wlan_hdd_cfg80211_start_ap",
          *(unsigned int *)(*(_QWORD *)v72 + 4LL));
        goto LABEL_9;
      }
      v101 = *(_DWORD *)(*(_QWORD *)(v24 + 32) + 16LL);
      ucfg_mlme_get_srd_master_mode_for_vdev(*v279, v101, &v282);
      if ( !v282
        && (wlan_reg_is_etsi_srd_chan_for_freq(v279[1], v276, v102, v103, v104, v105, v106, v107, v108, v109) & 1) != 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: vdev opmode %d not allowed on SRD channel.",
          v102,
          v103,
          v104,
          v105,
          v106,
          v107,
          v108,
          v109,
          "__wlan_hdd_cfg80211_start_ap",
          v101);
        goto LABEL_9;
      }
      if ( cds_is_sub_20_mhz_enabled(v102, v103, v104, v105, v106, v107, v108, v109) )
      {
        v281[0] = 0;
        v281[1] = 0;
        if ( (unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                             v279[1],
                             v276,
                             v110,
                             v111,
                             v112,
                             v113,
                             v114,
                             v115,
                             v116,
                             v117) == 2 )
        {
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Can't start SAP-DFS (channel=%d)with sub 20 MHz ch wd",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "__wlan_hdd_cfg80211_start_ap",
            v276);
          goto LABEL_9;
        }
        if ( v278 != 3 )
        {
          v25 = "%s: Hostapd (20+ MHz) conflits with config.ini (sub 20 MHz)";
          goto LABEL_7;
        }
        if ( cds_is_5_mhz_enabled(v16, v17, v18, v19, v20, v21, v22, v23) )
          v126 = 5;
        else
          v126 = 8;
        if ( cds_is_10_mhz_enabled(v118, v119, v120, v121, v122, v123, v124, v125) )
          v127 = 6;
        else
          v127 = v126;
        qdf_mem_set(v281, 0x10u, 0);
        LODWORD(v281[0]) = v127;
        is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v276);
        v137 = v279[1];
        if ( is_5ghz_ch_freq )
          _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                                   v137,
                                                   v276,
                                                   (unsigned int *)v281,
                                                   0,
                                                   v129,
                                                   v130,
                                                   v131,
                                                   v132,
                                                   v133,
                                                   v134,
                                                   v135,
                                                   v136);
        else
          _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_2g_bonded_channel_state_for_freq(
                                                   v137,
                                                   v276,
                                                   v127,
                                                   0,
                                                   v129,
                                                   v130,
                                                   v131,
                                                   v132,
                                                   v133,
                                                   v134,
                                                   v135,
                                                   v136);
        if ( !_5g_bonded_channel_state_for_pwrmode )
        {
          v25 = "%s: Given ch width not supported by reg domain";
          goto LABEL_7;
        }
        v84 = v279;
        *(_DWORD *)(v24 + 320) = 1;
      }
      mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(*v84, 0, (unsigned __int64)&v288, 0);
      if ( (unsigned __int16)mode_specific_conn_info <= 5u )
      {
        v139 = (unsigned __int16)mode_specific_conn_info;
        mode_specific_conn_info = policy_mgr_get_sap_mode_info(
                                    *v84,
                                    0,
                                    (unsigned __int64)&v288 + (unsigned __int16)mode_specific_conn_info);
        v148 = *(_DWORD *)(a2 + 2728);
        if ( !v139 && v148 != 3 && !(_WORD)mode_specific_conn_info )
          goto LABEL_85;
        v149 = (unsigned __int16)mode_specific_conn_info + v139;
        v274 = (unsigned __int16)mode_specific_conn_info;
        if ( !v149 )
        {
          v151 = 1;
          goto LABEL_77;
        }
        if ( v149 - 6 >= 0xFFFFFFFB )
          break;
      }
      __break(0x5512u);
    }
    v150 = *(unsigned __int8 *)(v24 + 8);
    v151 = (unsigned __int8)v288 != v150;
    if ( v149 != 1 )
    {
      _ZF = BYTE1(v288) == v150 || (unsigned __int8)v288 == v150;
      v151 = !_ZF;
      if ( v149 != 2 )
      {
        if ( BYTE2(v288) == v150 )
          v151 = 0;
        if ( v149 != 3 )
        {
          if ( HIBYTE(v288) == v150 )
            v151 = 0;
          if ( v149 != 4 && v289 == v150 )
            v151 = 0;
        }
      }
    }
LABEL_77:
    if ( v148 == 3 )
    {
      is_sta_p2p_ndp_supported = ucfg_nan_is_sta_p2p_ndp_supported(*v279);
      v148 = *(_DWORD *)(a2 + 2728);
      if ( (is_sta_p2p_ndp_supported & 1) != 0 )
        goto LABEL_85;
    }
    if ( v148 == 1 )
    {
      is_sta_sap_ndp_supported = ucfg_nan_is_sta_sap_ndp_supported(*v279);
      v148 = *(_DWORD *)(a2 + 2728);
      if ( (is_sta_sap_ndp_supported & 1) != 0 || !v151 )
      {
LABEL_85:
        if ( v148 == 1 && (ucfg_nan_is_sta_sap_ndp_supported(*v279) & 1) == 0 )
        {
          ucfg_nan_check_and_disable_unsupported_ndi(*v279, 1);
          if ( (unsigned int)policy_mgr_mode_specific_connection_count(*v279, 5, nullptr) )
          {
            if ( (policy_mgr_nan_sap_pre_enable_conc_check(*v279, 1u, v276) & 1) == 0 )
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: NAN disabled due to concurrency constraints",
                v155,
                v156,
                v157,
                v158,
                v159,
                v160,
                v161,
                v162,
                "__wlan_hdd_cfg80211_start_ap");
          }
        }
LABEL_90:
        if ( !(unsigned int)policy_mgr_mode_specific_connection_count(*v279, 5, nullptr)
          && (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
                *v279,
                v73,
                v276,
                v278,
                0,
                *(unsigned __int8 *)(v24 + 8))
            & 1) == 0 )
        {
          v25 = "%s: Connection failed due to concurrency check failure";
          goto LABEL_7;
        }
        if ( (unsigned int)policy_mgr_reset_connection_update(*v279) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: ERR: clear event failed",
            v163,
            v164,
            v165,
            v166,
            v167,
            v168,
            v169,
            v170,
            "__wlan_hdd_cfg80211_start_ap");
        policy_mgr_checkn_update_hw_mode_single_mac_mode(*v279, v276);
        v171 = policy_mgr_current_connections_update(*v279, *(unsigned __int8 *)(v24 + 8), v276, 2u, 0);
        if ( v171 )
        {
          v27 = v171;
          if ( v171 == 16 )
          {
            v25 = "%s: ERROR: connections update failed!!";
            goto LABEL_7;
          }
        }
        else
        {
          v27 = 0;
          if ( (unsigned int)policy_mgr_wait_for_connection_update(*v279) )
          {
LABEL_17:
            v25 = "%s: qdf wait for event failed!!";
            goto LABEL_7;
          }
        }
        vdev_by_user = _hdd_objmgr_get_vdev_by_user(v24, 6, "__wlan_hdd_cfg80211_start_ap");
        if ( vdev_by_user )
        {
          v173 = *(_DWORD *)(a2 + 2728);
          v174 = vdev_by_user;
          if ( v173 == 3 )
          {
            adapter = hdd_get_adapter(v279, 7);
            if ( adapter )
            {
              v184 = adapter;
              qdf_trace_msg(
                0x33u,
                8u,
                "%s: Cleanup active p2p device ROC before GO starting",
                v176,
                v177,
                v178,
                v179,
                v180,
                v181,
                v182,
                v183,
                "__wlan_hdd_cfg80211_start_ap");
              wlan_hdd_cleanup_remain_on_channel_ctx(*(_QWORD *)(v184 + 52824));
            }
            if ( (wlan_reg_is_dfs_for_freq(v279[1], v276, v176, v177, v178, v179, v180, v181, v182, v183) & 1) != 0
              && ucfg_p2p_is_vdev_wfd_r2_mode(v174) )
            {
              if ( (unsigned int)hdd_check_ap_assist_dfs_group_start_req(
                                   v24,
                                   *((_QWORD *)a3 + 6),
                                   *((unsigned __int16 *)a3 + 68),
                                   v276) )
              {
                _hdd_objmgr_put_vdev_by_user(v174, 6, "__wlan_hdd_cfg80211_start_ap");
                goto LABEL_9;
              }
              v27 = 0;
            }
            v173 = *(_DWORD *)(a2 + 2728);
          }
          if ( (v173 | 2) != 3 )
          {
            _hdd_objmgr_put_vdev_by_user(v174, 6, "__wlan_hdd_cfg80211_start_ap");
LABEL_114:
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: exit",
              v187,
              v188,
              v189,
              v190,
              v191,
              v192,
              v193,
              v194,
              "__wlan_hdd_cfg80211_start_ap");
LABEL_11:
            _osif_vdev_sync_op_stop(v280, "wlan_hdd_cfg80211_start_ap");
            result = v27;
            goto LABEL_12;
          }
          v185 = *(_QWORD *)(v24 + 2160);
          v281[0] = 0;
          if ( v185 )
          {
            v186 = -114;
LABEL_119:
            _hdd_objmgr_put_vdev_by_user(v174, 6, "__wlan_hdd_cfg80211_start_ap");
            v27 = v186;
            goto LABEL_11;
          }
          if ( policy_mgr_is_vdev_ll_lt_sap(*v279, *(unsigned __int8 *)(v24 + 8)) )
          {
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: Actual dtim_period %d",
              v195,
              v196,
              v197,
              v198,
              v199,
              v200,
              v201,
              v202,
              "__wlan_hdd_cfg80211_start_ap",
              (unsigned int)a3[53]);
            a3[53] = 10;
            qdf_trace_msg(
              0x33u,
              8u,
              "%s: overwritten dtim_period %d",
              v203,
              v204,
              v205,
              v206,
              v207,
              v208,
              v209,
              v210,
              "__wlan_hdd_cfg80211_start_ap",
              10);
          }
          if ( (unsigned int)wlan_hdd_cfg80211_alloc_new_beacon(v24, v281, a3 + 8, (unsigned int)a3[53]) )
          {
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Error!!! Allocating the new beacon",
              v212,
              v213,
              v214,
              v215,
              v216,
              v217,
              v218,
              v219,
              "__wlan_hdd_cfg80211_start_ap");
            v186 = -22;
            goto LABEL_119;
          }
          *(_QWORD *)(v24 + 2160) = v281[0];
          if ( *(_DWORD *)v275 > 2u )
            chandef_type = 3;
          else
            chandef_type = cfg80211_get_chandef_type(v72);
          wlan_hdd_set_channel(v24, v212, v213, v214, v215, v216, v217, v218, v219, v211, a2, v72, chandef_type);
          hdd_update_beacon_rate(v24, a1, a3);
          v221 = a3[91];
          if ( v221 == 1 )
            v222 = 1;
          else
            v222 = 2;
          if ( v221 )
            v223 = v222;
          else
            v223 = 0;
          *(_DWORD *)(v24 + 1268) = v223;
          *(_DWORD *)(v24 + 744) = hdd_map_nl_chan_width(v72[2]);
          v224 = *((_BYTE *)a3 + 812);
          v225 = *(__int64 **)(a2 + 2712);
          *(_BYTE *)(*(_QWORD *)(a2 + 55512) + 2132LL) = v224;
          wlan_hdd_configure_twt_responder(v225, v224, *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL));
          hdd_update_he_obss_pd(v24, a3);
          v226 = ucfg_ll_lt_sap_switch_bearer_for_p2p_go_start(
                   *v279,
                   *(unsigned __int8 *)(*(_QWORD *)(a2 + 55512) + 8LL),
                   *(unsigned int *)(*(_QWORD *)a3 + 4LL),
                   *(unsigned int *)(a2 + 2728));
          started = wlan_hdd_cfg80211_start_bss(
                      v24,
                      v226,
                      v228,
                      v229,
                      v230,
                      v231,
                      v232,
                      v233,
                      v234,
                      v227,
                      *((const void **)a3 + 27),
                      *((_QWORD *)a3 + 28),
                      a3[58],
                      1);
          v236 = *(_QWORD *)(a2 + 55512);
          v237 = *(unsigned int *)(a2 + 2728);
          v238 = started;
          ucfg_ll_lt_sap_switch_bearer_on_p2p_go_complete(*v279, *(unsigned __int8 *)(v236 + 8), v237);
          if ( v238 )
          {
            v27 = v238;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Error Start bss Failed",
              v239,
              v240,
              v241,
              v242,
              v243,
              v244,
              v245,
              v246,
              "__wlan_hdd_cfg80211_start_ap");
            _hdd_objmgr_put_vdev_by_user(v174, 6, "__wlan_hdd_cfg80211_start_ap");
LABEL_131:
            _qdf_mem_free(*(_QWORD *)(v24 + 2160));
            *(_QWORD *)(v24 + 2160) = 0;
            goto LABEL_114;
          }
          if ( v68 != v276 )
            wlan_set_sap_user_config_freq(v174, v68, v239, v240, v241, v242, v243, v244, v245, v246);
          _hdd_objmgr_put_vdev_by_user(v174, 6, "__wlan_hdd_cfg80211_start_ap");
          if ( (unsigned int)wlan_get_operation_chan_freq(*(unsigned __int16 **)(v24 + 32)) != *(_DWORD *)(*(_QWORD *)a3 + 4LL) )
            hdd_update_param_chandef(v24, a3);
          if ( *(_DWORD *)(v24 + 720)
            && (policy_mgr_is_dnsc_set(*(_QWORD *)(v24 + 32), v247, v248, v249, v250, v251, v252, v253, v254) & 1) != 0 )
          {
            wlan_hdd_send_avoid_freq_for_dnbs((__int64)v279, *(_DWORD *)(v24 + 720));
          }
          wlan_mlme_get_sap_inactivity_override(*v279, v286);
          if ( v286[0] == 1 )
          {
            v263 = _qdf_mem_malloc(8u, "__wlan_hdd_cfg80211_start_ap", 9456);
            if ( !v263 )
            {
              v27 = 16;
              goto LABEL_131;
            }
            v264 = v263;
            *(_BYTE *)v263 = *(_BYTE *)(v24 + 8);
            *(_DWORD *)(v263 + 4) = a3[93];
            sme_update_sta_inactivity_timeout(v279[2], v263);
            _qdf_mem_free(v264);
          }
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: exit",
            v255,
            v256,
            v257,
            v258,
            v259,
            v260,
            v261,
            v262,
            "__wlan_hdd_cfg80211_start_ap");
          v27 = 0;
          goto LABEL_11;
        }
LABEL_9:
        v26 = -22;
LABEL_10:
        v27 = v26;
        goto LABEL_11;
      }
    }
    else if ( !v151 )
    {
      goto LABEL_90;
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Invalid NAN concurrency. SAP: %d STA: %d P2P_GO: %d",
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      v147,
      "__wlan_hdd_cfg80211_start_ap",
      v274,
      v139,
      v148 == 3);
    ucfg_nan_disable_concurrency(*v279);
    v148 = *(_DWORD *)(a2 + 2728);
    goto LABEL_85;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
