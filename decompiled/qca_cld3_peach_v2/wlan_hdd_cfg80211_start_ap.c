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
  int v15; // w24
  __int64 mode_specific_conn_info; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  const char *v26; // x2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w0
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 *v44; // x27
  const char *v45; // x0
  unsigned int v46; // w25
  int v47; // w28
  const char *v48; // x27
  unsigned int v49; // w26
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  _BOOL4 is_5_mhz_enabled; // w24
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 *v67; // x28
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  unsigned int v76; // w0
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x4
  const char *v86; // x2
  unsigned int v87; // w1
  const char *v88; // x2
  unsigned int v89; // w25
  int *v90; // x27
  int *v91; // x25
  unsigned int *v92; // x26
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  unsigned int v101; // w1
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  unsigned int v110; // w25
  unsigned int v111; // w20
  __int64 v112; // x21
  __int64 *v113; // x19
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  __int64 v122; // x0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  unsigned int v131; // w25
  bool is_5ghz_ch_freq; // w8
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x0
  int _5g_bonded_channel_state_for_pwrmode; // w0
  unsigned int v143; // w25
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  int v152; // w8
  unsigned int v153; // w9
  int v154; // w10
  _BOOL4 v155; // w27
  char is_sta_p2p_ndp_supported; // w0
  char is_sta_sap_ndp_supported; // w0
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
  __int64 v175; // x25
  unsigned int conc_ext_flags; // w0
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  int v185; // w0
  int v186; // w27
  __int64 vdev_by_user; // x0
  int v188; // w8
  __int64 v189; // x28
  __int64 adapter; // x0
  double v191; // d0
  double v192; // d1
  double v193; // d2
  double v194; // d3
  double v195; // d4
  double v196; // d5
  double v197; // d6
  double v198; // d7
  __int64 v199; // x25
  __int64 v200; // x8
  int v201; // w20
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  double v218; // d0
  double v219; // d1
  double v220; // d2
  double v221; // d3
  double v222; // d4
  double v223; // d5
  double v224; // d6
  double v225; // d7
  __int64 v226; // x1
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  unsigned int chandef_type; // w4
  int v236; // w8
  int v237; // w9
  int v238; // w8
  char v239; // w1
  __int64 *v240; // x0
  double v241; // d0
  __int64 v242; // x1
  double v243; // d1
  double v244; // d2
  double v245; // d3
  double v246; // d4
  double v247; // d5
  double v248; // d6
  double v249; // d7
  int started; // w23
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  int v259; // w25
  double v260; // d0
  double v261; // d1
  double v262; // d2
  double v263; // d3
  double v264; // d4
  double v265; // d5
  double v266; // d6
  double v267; // d7
  double v268; // d0
  double v269; // d1
  double v270; // d2
  double v271; // d3
  double v272; // d4
  double v273; // d5
  double v274; // d6
  double v275; // d7
  double v276; // d0
  double v277; // d1
  double v278; // d2
  double v279; // d3
  double v280; // d4
  double v281; // d5
  double v282; // d6
  double v283; // d7
  __int64 v284; // x0
  __int64 v285; // x23
  unsigned __int64 v291; // x10
  __int64 v292; // [xsp+0h] [xbp-A0h]
  __int64 v293; // [xsp+8h] [xbp-98h]
  __int64 v294; // [xsp+10h] [xbp-90h]
  unsigned int v295; // [xsp+1Ch] [xbp-84h]
  __int64 *v296; // [xsp+20h] [xbp-80h]
  unsigned int v297; // [xsp+2Ch] [xbp-74h]
  unsigned int v298; // [xsp+30h] [xbp-70h]
  unsigned int v299; // [xsp+34h] [xbp-6Ch]
  unsigned int v300; // [xsp+34h] [xbp-6Ch]
  __int64 *v301; // [xsp+38h] [xbp-68h]
  __int64 v302; // [xsp+40h] [xbp-60h] BYREF
  _QWORD v303[3]; // [xsp+48h] [xbp-58h] BYREF
  bool v304; // [xsp+64h] [xbp-3Ch] BYREF
  __int64 v305; // [xsp+68h] [xbp-38h] BYREF
  __int64 v306; // [xsp+70h] [xbp-30h] BYREF
  _QWORD v307[2]; // [xsp+78h] [xbp-28h] BYREF
  char v308[4]; // [xsp+88h] [xbp-18h] BYREF
  char v309[4]; // [xsp+8Ch] [xbp-14h] BYREF
  int v310; // [xsp+90h] [xbp-10h] BYREF
  unsigned __int8 v311; // [xsp+94h] [xbp-Ch]
  __int64 v312; // [xsp+98h] [xbp-8h]

  v312 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v302 = 0;
  result = _osif_vdev_sync_op_start(a2, &v302, "wlan_hdd_cfg80211_start_ap");
  if ( (_DWORD)result )
    goto LABEL_46;
  v309[0] = 0;
  v15 = 1885692259;
  v308[0] = 0;
  v307[0] = 0;
  v307[1] = 0;
  v305 = 0;
  v306 = 0;
  v304 = 0;
  v311 = 0;
  v310 = 0;
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
  v25 = *(_QWORD *)(a2 + 55520);
  if ( !v25 )
  {
    v26 = "%s: invalid link_info";
LABEL_7:
    qdf_trace_msg(0x33u, 2u, v26, v17, v18, v19, v20, v21, v22, v23, v24, "__wlan_hdd_cfg80211_start_ap");
    v35 = -22;
LABEL_40:
    v111 = v35;
    if ( *(_DWORD *)(a2 + 2688) == v15 )
    {
      v112 = *(_QWORD *)(a2 + 55520);
      v113 = *(__int64 **)(a2 + 2712);
      if ( !(unsigned int)_wlan_hdd_validate_context(v113, "wlan_hdd_post_start_ap_failed")
        && !(unsigned int)_wlan_hdd_validate_vdev_id(*(unsigned __int8 *)(v112 + 8), "wlan_hdd_post_start_ap_failed") )
      {
        ucfg_policy_mgr_post_ap_start_failed(*v113, *(unsigned __int8 *)(v112 + 8));
      }
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: HDD adapter magic is invalid",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wlan_hdd_post_start_ap_failed");
    }
    goto LABEL_45;
  }
  while ( 1 )
  {
    _X8 = (unsigned __int64 *)(v25 + 5968);
    __asm { PRFM            #0x11, [X8] }
    do
      v291 = __ldxr(_X8);
    while ( __stxr(v291 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
    if ( (unsigned int)hdd_get_conparam(mode_specific_conn_info) == 5 )
    {
      v26 = "%s: Command not allowed in FTM mode";
      goto LABEL_7;
    }
    if ( (unsigned int)_wlan_hdd_validate_vdev_id(*(unsigned __int8 *)(v25 + 8), "__wlan_hdd_cfg80211_start_ap") )
    {
      v35 = -22;
      goto LABEL_40;
    }
    qdf_mtrace(51, 51, 0x1Au, *(_BYTE *)(v25 + 8), a3[52]);
    if ( *(_DWORD *)(a2 + 2688) != v15 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: HDD adapter magic is invalid",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "__wlan_hdd_cfg80211_start_ap");
      v35 = -19;
      goto LABEL_40;
    }
    v44 = *(__int64 **)(a2 + 2712);
    v35 = _wlan_hdd_validate_context(v44, "__wlan_hdd_cfg80211_start_ap");
    if ( v35 )
      goto LABEL_40;
    v299 = *(unsigned __int8 *)(v25 + 8);
    v45 = qdf_opmode_str(*(_DWORD *)(a2 + 2728));
    v46 = *(_DWORD *)(a2 + 2728);
    v47 = a3[2];
    v301 = v44;
    v48 = v45;
    v49 = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
    is_5_mhz_enabled = cds_is_5_mhz_enabled(v50, v51, v52, v53, v54, v55, v56, v57);
    LODWORD(v292) = v47;
    v67 = v301;
    LODWORD(v294) = cds_is_10_mhz_enabled(v59, v60, v61, v62, v63, v64, v65, v66);
    LODWORD(v293) = is_5_mhz_enabled;
    qdf_trace_msg(
      0x33u,
      4u,
      "%s(vdevid-%d): START AP: mode %s(%d) %d bw %d (5MHz %d 10MHz %d)",
      v68,
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      a2 + 296,
      v299,
      v48,
      v46,
      v49,
      v292,
      v293,
      v294);
    v76 = ucfg_policy_mgr_pre_ap_start(*v301, *(unsigned __int8 *)(v25 + 8));
    if ( v76 )
    {
      v85 = v76;
      v86 = "%s: handle pre ap start failed %d";
LABEL_14:
      v87 = 2;
      goto LABEL_15;
    }
    if ( (unsigned int)policy_mgr_is_hw_mode_change_in_progress(*v301)
      && (unsigned int)policy_mgr_wait_for_connection_update(*v301) )
    {
      goto LABEL_19;
    }
    hdd_reg_wait_for_country_change(v301);
    v89 = ((__int64 (__fastcall *)(_QWORD))wlan_hdd_get_channel_bw)((unsigned int)a3[2]);
    v15 = *(_DWORD *)(*(_QWORD *)a3 + 4LL);
    if ( wlan_reg_is_6ghz_chan_freq(v15)
      && (wlan_reg_is_6ghz_band_set(v301[1], v77, v78, v79, v80, v81, v82, v83, v84) & 1) == 0 )
    {
      v88 = "%s: 6 GHz band disabled.";
      goto LABEL_37;
    }
    v297 = v89;
    v90 = a3 + 3;
    v91 = a3 + 4;
    v296 = (__int64 *)(a3 + 2);
    if ( (*(_DWORD *)(a2 + 2728) | 2) == 3 )
    {
      v92 = a3;
      v300 = v15;
      if ( (wlan_hdd_is_ap_ap_force_scc_override(v25, a3, &v305) & 1) != 0 )
      {
        v91 = (int *)v307;
        v90 = (int *)&v306 + 1;
        v300 = *(_DWORD *)(v305 + 4);
        v296 = &v306;
        v92 = (unsigned int *)&v305;
        v297 = ((__int64 (__fastcall *)(_QWORD))wlan_hdd_get_channel_bw)((unsigned int)v306);
      }
    }
    else
    {
      v300 = v15;
      v92 = a3;
    }
    v298 = policy_mgr_qdf_opmode_to_pm_con_mode(
             *v301,
             *(_DWORD *)(a2 + 2728),
             *(_BYTE *)(*(_QWORD *)(a2 + 55520) + 8LL),
             v77,
             v78,
             v79,
             v80,
             v81,
             v82,
             v83,
             v84);
    if ( (unsigned int)ucfg_policy_mgr_get_sap_mandt_chnl(*v301, v309) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: can't get mandatory channel list",
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        v99,
        v100,
        "__wlan_hdd_cfg80211_start_ap");
    if ( v309[0] && v298 == 1 )
      policy_mgr_init_sap_mandatory_chan(*v301, *(_DWORD *)(*(_QWORD *)v92 + 4LL));
    *(_BYTE *)(v25 + 733) = cds_freq_to_chan(*v90);
    *(_BYTE *)(v25 + 734) = cds_freq_to_chan(*v91);
    v101 = *(unsigned __int8 *)(v25 + 8);
    *(_DWORD *)(v25 + 736) = *v90;
    *(_DWORD *)(v25 + 740) = *v91;
    if ( (policy_mgr_is_sap_allowed_on_dfs_freq(
            v301[1],
            v101,
            *(_DWORD *)(*(_QWORD *)v92 + 4LL),
            v102,
            v103,
            v104,
            v105,
            v106,
            v107,
            v108,
            v109)
        & 1) == 0 )
      goto LABEL_38;
    if ( (policy_mgr_is_sap_go_interface_allowed_on_indoor(
            v301[1],
            *(unsigned __int8 *)(v25 + 8),
            *(_DWORD *)(*(_QWORD *)v92 + 4LL))
        & 1) == 0 )
    {
      v86 = "%s: SAP start not allowed on indoor channel %d";
      v85 = *(unsigned int *)(*(_QWORD *)v92 + 4LL);
      v87 = 8;
LABEL_15:
      qdf_trace_msg(0x33u, v87, v86, v77, v78, v79, v80, v81, v82, v83, v84, "__wlan_hdd_cfg80211_start_ap", v85);
LABEL_38:
      v35 = -22;
LABEL_39:
      v15 = 1885692259;
      goto LABEL_40;
    }
    v110 = *(_DWORD *)(*(_QWORD *)(v25 + 32) + 16LL);
    ucfg_mlme_get_srd_master_mode_for_vdev(*v301, v110, &v304);
    if ( !v304 && (wlan_reg_is_etsi_srd_chan_for_freq(v301[1], v300, v77, v78, v79, v80, v81, v82, v83, v84) & 1) != 0 )
    {
      v86 = "%s: vdev opmode %d not allowed on SRD channel.";
      v87 = 2;
      v85 = v110;
      goto LABEL_15;
    }
    if ( cds_is_sub_20_mhz_enabled(v77, v78, v79, v80, v81, v82, v83, v84) )
    {
      v122 = v301[1];
      memset(v303, 0, sizeof(v303));
      if ( (unsigned int)wlan_reg_get_channel_state_from_secondary_list_for_freq(
                           v122,
                           v300,
                           v114,
                           v115,
                           v116,
                           v117,
                           v118,
                           v119,
                           v120,
                           v121) == 2 )
      {
        v85 = v300;
        v86 = "%s: Can't start SAP-DFS (channel=%d)with sub 20 MHz ch wd";
        goto LABEL_14;
      }
      if ( v297 != 3 )
      {
        v88 = "%s: Hostapd (20+ MHz) conflits with config.ini (sub 20 MHz)";
        goto LABEL_37;
      }
      if ( cds_is_5_mhz_enabled(v77, v78, v79, v80, v81, v82, v83, v84) )
        v131 = 5;
      else
        v131 = 8;
      if ( cds_is_10_mhz_enabled(v123, v124, v125, v126, v127, v128, v129, v130) )
        v131 = 6;
      qdf_mem_set(v303, 0x18u, 0);
      LODWORD(v303[0]) = v131;
      is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v300);
      v141 = v301[1];
      if ( is_5ghz_ch_freq )
        _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                                 v141,
                                                 v300,
                                                 (int *)v303,
                                                 0,
                                                 v133,
                                                 v134,
                                                 v135,
                                                 v136,
                                                 v137,
                                                 v138,
                                                 v139,
                                                 v140);
      else
        _5g_bonded_channel_state_for_pwrmode = wlan_reg_get_2g_bonded_channel_state_for_freq(
                                                 v141,
                                                 v300,
                                                 v131,
                                                 0,
                                                 v133,
                                                 v134,
                                                 v135,
                                                 v136,
                                                 v137,
                                                 v138,
                                                 v139,
                                                 v140);
      if ( !_5g_bonded_channel_state_for_pwrmode )
      {
        v88 = "%s: Given ch width not supported by reg domain";
        goto LABEL_37;
      }
      v67 = v301;
      *(_DWORD *)(v25 + 320) = 1;
    }
    mode_specific_conn_info = policy_mgr_get_mode_specific_conn_info(*v67, 0, (unsigned __int64)&v310, 0);
    v143 = (unsigned __int16)mode_specific_conn_info;
    if ( (unsigned __int16)mode_specific_conn_info <= 5u )
    {
      mode_specific_conn_info = policy_mgr_get_sap_mode_info(
                                  *v67,
                                  0,
                                  (unsigned __int64)&v310 + (unsigned __int16)mode_specific_conn_info);
      v152 = *(_DWORD *)(a2 + 2728);
      if ( !v143 && v152 != 3 && !(_WORD)mode_specific_conn_info )
        goto LABEL_95;
      v295 = (unsigned __int16)mode_specific_conn_info;
      v153 = (unsigned __int16)mode_specific_conn_info + v143;
      if ( !v153 )
      {
        v155 = 1;
        goto LABEL_87;
      }
      if ( v153 - 6 >= 0xFFFFFFFB )
        break;
    }
    __break(0x5512u);
  }
  v154 = *(unsigned __int8 *)(v25 + 8);
  v155 = (unsigned __int8)v310 != v154;
  if ( v153 != 1 )
  {
    _ZF = BYTE1(v310) == v154 || (unsigned __int8)v310 == v154;
    v155 = !_ZF;
    if ( v153 != 2 )
    {
      if ( BYTE2(v310) == v154 )
        v155 = 0;
      if ( v153 != 3 )
      {
        if ( HIBYTE(v310) == v154 )
          v155 = 0;
        if ( v153 != 4 && v311 == v154 )
          v155 = 0;
      }
    }
  }
LABEL_87:
  v67 = v301;
  if ( v152 == 3 )
  {
    is_sta_p2p_ndp_supported = ucfg_nan_is_sta_p2p_ndp_supported(*v301);
    v152 = *(_DWORD *)(a2 + 2728);
    if ( (is_sta_p2p_ndp_supported & 1) != 0 )
    {
LABEL_95:
      if ( v152 != 1 )
        goto LABEL_102;
      goto LABEL_96;
    }
  }
  if ( v152 != 1 )
  {
    v67 = v301;
    if ( v155 )
      goto LABEL_94;
    goto LABEL_102;
  }
  is_sta_sap_ndp_supported = ucfg_nan_is_sta_sap_ndp_supported(*v301);
  v152 = *(_DWORD *)(a2 + 2728);
  if ( (is_sta_sap_ndp_supported & 1) == 0 )
  {
    v67 = v301;
    if ( !v155 )
      goto LABEL_95;
LABEL_94:
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Invalid NAN concurrency. SAP: %d STA: %d P2P_GO: %d",
      v144,
      v145,
      v146,
      v147,
      v148,
      v149,
      v150,
      v151,
      "__wlan_hdd_cfg80211_start_ap",
      v295,
      v143,
      v152 == 3);
    ucfg_nan_disable_concurrency(*v67);
    v152 = *(_DWORD *)(a2 + 2728);
    goto LABEL_95;
  }
  v67 = v301;
  if ( v152 == 1 )
  {
LABEL_96:
    if ( (ucfg_nan_is_sta_sap_ndp_supported(*v67) & 1) == 0 )
    {
      ucfg_nan_check_and_disable_unsupported_ndi(*v67, 1);
      if ( (unsigned int)policy_mgr_mode_specific_connection_count(*v67, 5, nullptr) )
      {
        if ( (policy_mgr_nan_sap_pre_enable_conc_check(*v67, 1u, v300) & 1) == 0 )
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: NAN disabled due to concurrency constraints",
            v159,
            v160,
            v161,
            v162,
            v163,
            v164,
            v165,
            v166,
            "__wlan_hdd_cfg80211_start_ap");
      }
    }
  }
LABEL_102:
  if ( !(unsigned int)policy_mgr_mode_specific_connection_count(*v67, 5, nullptr) )
  {
    v175 = *v67;
    conc_ext_flags = policy_mgr_get_conc_ext_flags(
                       *(_QWORD *)(v25 + 32),
                       0,
                       v167,
                       v168,
                       v169,
                       v170,
                       v171,
                       v172,
                       v173,
                       v174);
    if ( (((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD))policy_mgr_allow_concurrency)(
            v175,
            v298,
            v300,
            v297,
            conc_ext_flags,
            *(unsigned __int8 *)(v25 + 8))
        & 1) == 0 )
    {
      v88 = "%s: Connection failed due to concurrency check failure";
      goto LABEL_37;
    }
  }
  if ( (unsigned int)policy_mgr_reset_connection_update(*v67) )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: ERR: clear event failed",
      v177,
      v178,
      v179,
      v180,
      v181,
      v182,
      v183,
      v184,
      "__wlan_hdd_cfg80211_start_ap");
  policy_mgr_checkn_update_hw_mode_single_mac_mode(*v67, v300);
  v185 = policy_mgr_current_connections_update(*v67, *(unsigned __int8 *)(v25 + 8), v300, 2u, 0);
  if ( v185 )
  {
    v186 = v185;
    if ( v185 == 16 )
    {
      v88 = "%s: ERROR: connections update failed!!";
      goto LABEL_37;
    }
  }
  else
  {
    v186 = 0;
    if ( (unsigned int)policy_mgr_wait_for_connection_update(*v67) )
    {
LABEL_19:
      v88 = "%s: qdf wait for event failed!!";
LABEL_37:
      qdf_trace_msg(0x33u, 2u, v88, v77, v78, v79, v80, v81, v82, v83, v84, "__wlan_hdd_cfg80211_start_ap");
      goto LABEL_38;
    }
  }
  vdev_by_user = _hdd_objmgr_get_vdev_by_user(v25, 6, "__wlan_hdd_cfg80211_start_ap");
  if ( !vdev_by_user )
    goto LABEL_38;
  v188 = *(_DWORD *)(a2 + 2728);
  v189 = vdev_by_user;
  if ( v188 == 3 )
  {
    adapter = hdd_get_adapter(v301, 7);
    if ( adapter )
    {
      v199 = adapter;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Cleanup active p2p device ROC before GO starting",
        v191,
        v192,
        v193,
        v194,
        v195,
        v196,
        v197,
        v198,
        "__wlan_hdd_cfg80211_start_ap");
      wlan_hdd_cleanup_remain_on_channel_ctx(*(_QWORD *)(v199 + 52832));
    }
    if ( (wlan_reg_is_dfs_for_freq(v301[1], v300, v191, v192, v193, v194, v195, v196, v197, v198) & 1) != 0
      && ucfg_p2p_is_vdev_wfd_r2_mode(v189) )
    {
      if ( (unsigned int)hdd_check_ap_assist_dfs_group_start_req(
                           v25,
                           *((_QWORD *)a3 + 6),
                           *((unsigned __int16 *)a3 + 68),
                           v300) )
      {
        _hdd_objmgr_put_vdev_by_user(v189, 6, "__wlan_hdd_cfg80211_start_ap");
        goto LABEL_38;
      }
      v186 = 0;
    }
    v188 = *(_DWORD *)(a2 + 2728);
  }
  if ( (v188 | 2) != 3 )
  {
    _hdd_objmgr_put_vdev_by_user(v189, 6, "__wlan_hdd_cfg80211_start_ap");
    qdf_trace_msg(0x33u, 8u, "%s: exit", v202, v203, v204, v205, v206, v207, v208, v209, "__wlan_hdd_cfg80211_start_ap");
    v35 = v186;
    v15 = 1885692259;
    if ( !v186 )
    {
      v111 = 0;
      goto LABEL_45;
    }
    goto LABEL_40;
  }
  v200 = *(_QWORD *)(v25 + 2432);
  v303[0] = 0;
  if ( v200 )
  {
    v201 = -114;
LABEL_130:
    _hdd_objmgr_put_vdev_by_user(v189, 6, "__wlan_hdd_cfg80211_start_ap");
    v35 = v201;
    goto LABEL_39;
  }
  if ( policy_mgr_is_vdev_ll_lt_sap(*v301, *(unsigned __int8 *)(v25 + 8)) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Actual dtim_period %d",
      v210,
      v211,
      v212,
      v213,
      v214,
      v215,
      v216,
      v217,
      "__wlan_hdd_cfg80211_start_ap",
      (unsigned int)a3[53]);
    a3[53] = 10;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: overwritten dtim_period %d",
      v218,
      v219,
      v220,
      v221,
      v222,
      v223,
      v224,
      v225,
      "__wlan_hdd_cfg80211_start_ap",
      10);
  }
  if ( (unsigned int)wlan_hdd_cfg80211_alloc_new_beacon(v25, v303, a3 + 8, (unsigned int)a3[53]) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Error!!! Allocating the new beacon",
      v227,
      v228,
      v229,
      v230,
      v231,
      v232,
      v233,
      v234,
      "__wlan_hdd_cfg80211_start_ap");
    v201 = -22;
    goto LABEL_130;
  }
  *(_QWORD *)(v25 + 2432) = v303[0];
  if ( *(_DWORD *)v296 > 2u )
    chandef_type = 3;
  else
    chandef_type = cfg80211_get_chandef_type(v92);
  wlan_hdd_set_channel(v25, v227, v228, v229, v230, v231, v232, v233, v234, v226, a2, v92, chandef_type);
  hdd_update_beacon_rate(v25, a1, a3);
  v236 = a3[91];
  if ( v236 == 1 )
    v237 = 1;
  else
    v237 = 2;
  if ( v236 )
    v238 = v237;
  else
    v238 = 0;
  *(_DWORD *)(v25 + 1276) = v238;
  *(_DWORD *)(v25 + 752) = hdd_map_nl_chan_width(v92[2]);
  v239 = *((_BYTE *)a3 + 812);
  v240 = *(__int64 **)(a2 + 2712);
  *(_BYTE *)(*(_QWORD *)(a2 + 55520) + 2148LL) = v239;
  wlan_hdd_configure_twt_responder(v240, v239, *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL));
  hdd_update_he_obss_pd(v25, a3);
  v241 = ucfg_ll_lt_sap_switch_bearer_for_p2p_go_start(
           *v301,
           *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
           *(unsigned int *)(*(_QWORD *)a3 + 4LL),
           *(unsigned int *)(a2 + 2728));
  started = wlan_hdd_cfg80211_start_bss(
              v25,
              v241,
              v243,
              v244,
              v245,
              v246,
              v247,
              v248,
              v249,
              v242,
              *((const void **)a3 + 27),
              *((_QWORD *)a3 + 28),
              a3[58],
              1);
  ucfg_ll_lt_sap_switch_bearer_on_p2p_go_complete(
    *v301,
    *(unsigned __int8 *)(*(_QWORD *)(a2 + 55520) + 8LL),
    *(unsigned int *)(a2 + 2728));
  if ( started )
  {
    v259 = started;
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Error Start bss Failed",
      v251,
      v252,
      v253,
      v254,
      v255,
      v256,
      v257,
      v258,
      "__wlan_hdd_cfg80211_start_ap");
    _hdd_objmgr_put_vdev_by_user(v189, 6, "__wlan_hdd_cfg80211_start_ap");
LABEL_142:
    _qdf_mem_free(*(_QWORD *)(v25 + 2432));
    *(_QWORD *)(v25 + 2432) = 0;
    qdf_trace_msg(0x33u, 8u, "%s: exit", v260, v261, v262, v263, v264, v265, v266, v267, "__wlan_hdd_cfg80211_start_ap");
    v35 = v259;
    goto LABEL_39;
  }
  if ( v15 != v300 )
    wlan_set_sap_user_config_freq(v189, v15, v251, v252, v253, v254, v255, v256, v257, v258);
  wlan_vdev_mlme_is_mlo_vdev(v189, v251, v252, v253, v254, v255, v256, v257, v258);
  _hdd_objmgr_put_vdev_by_user(v189, 6, "__wlan_hdd_cfg80211_start_ap");
  if ( (unsigned int)wlan_get_operation_chan_freq(*(unsigned __int16 **)(v25 + 32)) != *(_DWORD *)(*(_QWORD *)a3 + 4LL) )
    hdd_update_param_chandef(v25, a3);
  if ( *(_DWORD *)(v25 + 720)
    && (policy_mgr_is_dnsc_set(*(_QWORD *)(v25 + 32), v268, v269, v270, v271, v272, v273, v274, v275) & 1) != 0 )
  {
    wlan_hdd_send_avoid_freq_for_dnbs((__int64)v301, *(_DWORD *)(v25 + 720));
  }
  wlan_mlme_get_sap_inactivity_override(*v301, v308);
  if ( v308[0] == 1 )
  {
    v284 = _qdf_mem_malloc(8u, "__wlan_hdd_cfg80211_start_ap", 9456);
    if ( !v284 )
    {
      v259 = 16;
      goto LABEL_142;
    }
    v285 = v284;
    *(_BYTE *)v284 = *(_BYTE *)(v25 + 8);
    *(_DWORD *)(v284 + 4) = a3[93];
    sme_update_sta_inactivity_timeout(v301[2], v284);
    _qdf_mem_free(v285);
  }
  qdf_trace_msg(0x33u, 8u, "%s: exit", v276, v277, v278, v279, v280, v281, v282, v283, "__wlan_hdd_cfg80211_start_ap");
  v111 = 0;
LABEL_45:
  _osif_vdev_sync_op_stop(v302, "wlan_hdd_cfg80211_start_ap");
  result = v111;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
