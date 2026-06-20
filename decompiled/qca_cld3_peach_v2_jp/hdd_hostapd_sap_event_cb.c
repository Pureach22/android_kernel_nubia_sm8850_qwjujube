__int64 __fastcall hdd_hostapd_sap_event_cb(
        __int64 a1,
        int *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  __int64 v11; // x21
  __int64 v12; // x23
  __int64 *v13; // x20
  int v14; // w25
  __int64 v16; // x24
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 result; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  const char *v43; // x2
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  const char *v52; // x2
  int v53; // w9
  __int64 v54; // x9
  __int64 v55; // x8
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  char *v72; // x0
  const char *v73; // x19
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  __int64 v82; // x0
  const char *v83; // x20
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  __int64 v92; // x0
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  __int64 v101; // x21
  __int64 v102; // x1
  unsigned int v103; // w0
  __int64 v104; // x4
  const char *v105; // x2
  int v106; // w8
  __int64 v107; // x4
  int v108; // w11
  int v109; // w12
  int v110; // w13
  int v111; // w14
  double v112; // d0
  double v113; // d1
  double v114; // d2
  double v115; // d3
  double v116; // d4
  double v117; // d5
  double v118; // d6
  double v119; // d7
  unsigned int v120; // w9
  _BOOL8 v121; // x1
  bool v122; // cc
  unsigned int v123; // w0
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x0
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  __int64 v141; // x0
  __int64 v142; // x23
  __int64 v143; // x22
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  const char *v152; // x2
  unsigned int v153; // w1
  const char *v154; // x5
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  __int64 v163; // x2
  const char *v164; // x3
  __int64 v165; // x8
  __int64 v166; // x9
  double dfs_cac_state; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  char is_dfs_for_freq; // w0
  __int64 v176; // x1
  __int64 v177; // x0
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  __int64 v186; // x21
  __int64 v187; // x8
  __int64 v188; // x9
  __int64 v189; // x3
  char *v190; // x0
  double v191; // d0
  double v192; // d1
  double v193; // d2
  double v194; // d3
  double v195; // d4
  double v196; // d5
  double v197; // d6
  double v198; // d7
  __int16 v199; // w9
  __int64 sta_info_by_mac; // x0
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  int v209; // w9
  __int64 v210; // x1
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  unsigned __int8 *v219; // x0
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  const char *v228; // x9
  __int16 v229; // w9
  __int64 v230; // x0
  double v231; // d0
  double v232; // d1
  double v233; // d2
  double v234; // d3
  double v235; // d4
  double v236; // d5
  double v237; // d6
  double v238; // d7
  __int64 v239; // x24
  unsigned __int8 *v240; // x8
  unsigned int v241; // w9
  unsigned int i; // w8
  __int64 v243; // x11
  unsigned int v244; // w1
  unsigned __int8 *v245; // x22
  unsigned int v246; // t1
  __int64 v247; // x3
  __int64 v248; // x2
  unsigned int v249; // w21
  __int16 v250; // w8
  __int64 v251; // x0
  __int64 v252; // x1
  __int64 v253; // x2
  __int64 v254; // x3
  double v255; // d0
  double v256; // d1
  double v257; // d2
  double v258; // d3
  double v259; // d4
  double v260; // d5
  double v261; // d6
  double v262; // d7
  __int64 v263; // x0
  double v264; // d0
  double v265; // d1
  double v266; // d2
  double v267; // d3
  double v268; // d4
  double v269; // d5
  double v270; // d6
  double v271; // d7
  __int64 v272; // x24
  __int64 v273; // x24
  __int64 v274; // x0
  __int64 v275; // x24
  double v276; // d0
  double v277; // d1
  double v278; // d2
  double v279; // d3
  double v280; // d4
  double v281; // d5
  double v282; // d6
  double v283; // d7
  const char *v284; // x9
  double v285; // d0
  double v286; // d1
  double v287; // d2
  double v288; // d3
  double v289; // d4
  double v290; // d5
  double v291; // d6
  double v292; // d7
  __int64 vdev_by_user; // x0
  double v294; // d0
  double v295; // d1
  double v296; // d2
  double v297; // d3
  double v298; // d4
  double v299; // d5
  double v300; // d6
  double v301; // d7
  __int64 v302; // x23
  __int64 v303; // x0
  __int64 v304; // x1
  double v305; // d0
  double v306; // d1
  double v307; // d2
  double v308; // d3
  double v309; // d4
  double v310; // d5
  double v311; // d6
  double v312; // d7
  __int64 v313; // x22
  __int64 v314; // x0
  double v315; // d0
  double v316; // d1
  double v317; // d2
  double v318; // d3
  double v319; // d4
  double v320; // d5
  double v321; // d6
  double v322; // d7
  __int64 v323; // x23
  double v324; // d0
  double v325; // d1
  double v326; // d2
  double v327; // d3
  double v328; // d4
  double v329; // d5
  double v330; // d6
  double v331; // d7
  unsigned int v332; // w0
  double v333; // d0
  double v334; // d1
  double v335; // d2
  double v336; // d3
  double v337; // d4
  double v338; // d5
  double v339; // d6
  double v340; // d7
  __int64 v341; // x0
  void *v342; // x0
  __int64 v343; // x21
  __int64 v344; // x1
  double updated; // d0
  double v346; // d1
  double v347; // d2
  double v348; // d3
  double v349; // d4
  double v350; // d5
  double v351; // d6
  double v352; // d7
  __int64 v353; // x0
  double v354; // d0
  double v355; // d1
  double v356; // d2
  double v357; // d3
  double v358; // d4
  double v359; // d5
  double v360; // d6
  double v361; // d7
  double v362; // d0
  double v363; // d1
  double v364; // d2
  double v365; // d3
  double v366; // d4
  double v367; // d5
  double v368; // d6
  double v369; // d7
  char v370; // w8
  double v371; // d0
  double v372; // d1
  double v373; // d2
  double v374; // d3
  double v375; // d4
  double v376; // d5
  double v377; // d6
  double v378; // d7
  double v379; // d0
  double v380; // d1
  double v381; // d2
  double v382; // d3
  double v383; // d4
  double v384; // d5
  double v385; // d6
  double v386; // d7
  unsigned int v387; // w0
  double v388; // d0
  double v389; // d1
  double v390; // d2
  double v391; // d3
  double v392; // d4
  double v393; // d5
  double v394; // d6
  double v395; // d7
  __int64 v396; // x0
  double v397; // d0
  double v398; // d1
  double v399; // d2
  double v400; // d3
  double v401; // d4
  double v402; // d5
  double v403; // d6
  double v404; // d7
  __int64 v405; // x19
  double v406; // d0
  double v407; // d1
  double v408; // d2
  double v409; // d3
  double v410; // d4
  double v411; // d5
  double v412; // d6
  double v413; // d7
  __int64 v414; // x0
  double v415; // d0
  double v416; // d1
  double v417; // d2
  double v418; // d3
  double v419; // d4
  double v420; // d5
  double v421; // d6
  double v422; // d7
  __int64 v423; // x22
  void *v424; // x0
  __int64 v425; // x8
  double v426; // d0
  double v427; // d1
  double v428; // d2
  double v429; // d3
  double v430; // d4
  double v431; // d5
  double v432; // d6
  double v433; // d7
  __int64 v434; // x0
  __int64 v435; // x1
  unsigned int v436; // w0
  double v437; // d0
  double v438; // d1
  double v439; // d2
  double v440; // d3
  double v441; // d4
  double v442; // d5
  double v443; // d6
  double v444; // d7
  __int64 v445; // [xsp+0h] [xbp-90h]
  char v446[4]; // [xsp+38h] [xbp-58h] BYREF
  char v447[4]; // [xsp+3Ch] [xbp-54h] BYREF
  unsigned __int8 *v448; // [xsp+40h] [xbp-50h] BYREF
  __int64 v449; // [xsp+48h] [xbp-48h] BYREF
  unsigned __int8 *v450; // [xsp+50h] [xbp-40h] BYREF
  char v451[4]; // [xsp+58h] [xbp-38h] BYREF
  char v452[4]; // [xsp+5Ch] [xbp-34h] BYREF
  const char *v453; // [xsp+60h] [xbp-30h] BYREF
  __int64 v454; // [xsp+68h] [xbp-28h]
  int v455; // [xsp+70h] [xbp-20h] BYREF
  __int16 v456; // [xsp+74h] [xbp-1Ch]
  unsigned int v457; // [xsp+78h] [xbp-18h] BYREF
  unsigned __int16 v458; // [xsp+7Ch] [xbp-14h]
  int v459; // [xsp+80h] [xbp-10h] BYREF
  __int16 v460; // [xsp+84h] [xbp-Ch]
  __int64 v461; // [xsp+88h] [xbp-8h]

  v461 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1216);
  v453 = nullptr;
  v454 = 0;
  v452[0] = 0;
  v451[0] = 0;
  v458 = 0;
  v457 = 0;
  v450 = nullptr;
  v448 = nullptr;
  v449 = 0;
  v447[0] = 0;
  v456 = 0;
  v455 = 0;
  v446[0] = 0;
  if ( !v10 )
  {
    v43 = "%s: invalid link info";
    goto LABEL_13;
  }
  v11 = *(_QWORD *)v10;
  if ( !*(_QWORD *)v10 || *(_DWORD *)v11 != 1885692259 )
  {
    v43 = "%s: invalid adapter or adapter has invalid magic";
    goto LABEL_13;
  }
  v12 = *(_QWORD *)(v11 + 32);
  if ( !v12 )
  {
    v43 = "%s: dev is null";
    goto LABEL_13;
  }
  if ( !a2 )
  {
    v43 = "%s: sap_event is null";
    goto LABEL_13;
  }
  v13 = *(__int64 **)(v11 + 24);
  v14 = *a2;
  v453 = nullptr;
  v454 = 0;
  if ( !v13 )
  {
    v43 = "%s: HDD context is null";
    goto LABEL_13;
  }
  if ( !v13[13] )
  {
    v43 = "%s: HDD config is null";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v43, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_hostapd_sap_event_cb");
LABEL_14:
    result = 16;
    goto LABEL_15;
  }
  v16 = v13[2];
  LOWORD(v457) = (unsigned __int8)wlan_reg_freq_to_chan(
                                    v13[1],
                                    *(_DWORD *)(v10 + 2152),
                                    a3,
                                    a4,
                                    a5,
                                    a6,
                                    a7,
                                    a8,
                                    a9,
                                    a10);
  wlan_reg_get_cc_and_src(*v13, (char *)&v457 + 2, v18, v19, v20, v21, v22, v23, v24, v25);
  result = 0;
  switch ( v14 )
  {
    case 0:
      *(_DWORD *)(v10 + 2152) = a2[3];
      *(_BYTE *)(v10 + 8) = *((_BYTE *)a2 + 22);
      *(_DWORD *)(v10 + 720) = a2[3];
      *(_DWORD *)(v10 + 728) = a2[4];
      if ( *((_BYTE *)a2 + 8) )
        v164 = "failed";
      else
        v164 = "started";
      qdf_trace_msg(0x33u, 4u, "AP %s vid %d freq %d BW %d", v26, v27, v28, v29, v30, v31, v32, v33, v164);
      hdd_cp_stats_cstats_sap_go_start_event(v10, a2);
      v165 = *(_QWORD *)(v10 + 272);
      v166 = *(_QWORD *)(v165 + 1500);
      *(_QWORD *)(v10 + 736) = *(_QWORD *)(v165 + 1508);
      *(_QWORD *)(v10 + 728) = v166;
      *(_DWORD *)(v10 + 724) = *(_DWORD *)(v165 + 4);
      *(_DWORD *)(v10 + 248) = *((unsigned __int8 *)a2 + 8);
      *(_DWORD *)(v10 + 2348) = 0;
      wlansap_get_dfs_ignore_cac(v16, v452);
      if ( (policy_mgr_get_dfs_master_dynamic_enabled(*v13) & 1) == 0 )
        v452[0] = 1;
      dfs_cac_state = wlansap_get_dfs_cac_state(v16, *(_QWORD *)(v10 + 272), v451);
      is_dfs_for_freq = wlan_reg_is_dfs_for_freq(
                          v13[1],
                          *(_DWORD *)(v10 + 2152),
                          dfs_cac_state,
                          v168,
                          v169,
                          v170,
                          v171,
                          v172,
                          v173,
                          v174);
      v176 = 0;
      if ( (is_dfs_for_freq & 1) != 0 && !v452[0] )
      {
        if ( *((_BYTE *)v13 + 912) == 2 )
          v176 = 0;
        else
          v176 = (unsigned __int8)v451[0];
      }
      *(_BYTE *)(v10 + 256) = v176;
      ucfg_ipa_set_dfs_cac_tx(v13[1], v176);
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
      if ( vdev_by_user )
      {
        v302 = vdev_by_user;
        ucfg_dp_set_dfs_cac_tx(vdev_by_user, *(_BYTE *)(v10 + 256), v294, v295, v296, v297, v298, v299, v300, v301);
        _hdd_objmgr_put_vdev_by_user(v302, 97, "hdd_hostapd_sap_event_cb");
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev %d dfs_cac_block_tx %d",
        v294,
        v295,
        v296,
        v297,
        v298,
        v299,
        v300,
        v301,
        "hdd_hostapd_sap_event_cb",
        *(unsigned __int8 *)(v10 + 8),
        *(unsigned __int8 *)(v10 + 256));
      if ( *(_DWORD *)(v10 + 248) )
      {
        *(_DWORD *)(v10 + 80) = 0;
        v303 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v303 )
        {
          v313 = v303;
          ucfg_dp_set_bss_state_start(v303, 0, v305, v306, v307, v308, v309, v310, v311, v312);
          _hdd_objmgr_put_vdev_by_user(v313, 97, "hdd_hostapd_sap_event_cb");
        }
        qdf_event_set(v10 + 88, v304);
        goto LABEL_157;
      }
      updated = sme_ch_avoid_update_req(v16);
      *(_BYTE *)(v10 + 259) = *((_BYTE *)a2 + 20);
      _cds_get_context(71, (__int64)"hdd_hostapd_sap_event_cb", updated, v346, v347, v348, v349, v350, v351, v352);
      v353 = hdd_softap_register_bc_sta(v10, *(_BYTE *)(v10 + 260) != 0);
      if ( (_DWORD)v353 )
      {
        qdf_trace_msg(
          0x33u,
          3u,
          "%s: Failed to register BC STA %d",
          v354,
          v355,
          v356,
          v357,
          v358,
          v359,
          v360,
          v361,
          "hdd_hostapd_sap_event_cb",
          (unsigned int)v353);
        v353 = hdd_stop_bss_link(v10);
      }
      if ( (ucfg_ipa_is_enabled(v353) & 1) != 0 )
      {
        if ( (unsigned int)hdd_ipa_get_tx_pipe(v13, v10, v446) )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Failed to get alt pipe for vdev %d",
            v362,
            v363,
            v364,
            v365,
            v366,
            v367,
            v368,
            v369,
            "hdd_hostapd_sap_event_cb",
            *(unsigned __int8 *)(v10 + 8));
          v370 = 0;
          v446[0] = 0;
        }
        else
        {
          v370 = v446[0];
        }
        if ( (unsigned int)ucfg_ipa_wlan_evt(
                             v13[1],
                             *(_QWORD *)(v11 + 32),
                             *(unsigned int *)(v11 + 40),
                             *(unsigned __int8 *)(v10 + 8),
                             2,
                             *(_QWORD *)(*(_QWORD *)(v11 + 32) + 1008LL),
                             v370 & 1) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: WLAN_AP_CONNECT event failed",
            v406,
            v407,
            v408,
            v409,
            v410,
            v411,
            v412,
            v413,
            "hdd_hostapd_sap_event_cb");
      }
      hdd_hostapd_channel_prevent_suspend(v11, *(unsigned int *)(v10 + 2152));
      *(_DWORD *)(v10 + 80) = 1;
      v414 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
      if ( v414 )
      {
        v423 = v414;
        ucfg_dp_set_bss_state_start(v414, 1, v415, v416, v417, v418, v419, v420, v421, v422);
        _hdd_objmgr_put_vdev_by_user(v423, 97, "hdd_hostapd_sap_event_cb");
      }
      hdd_setup_tsf_sync(v11);
      hdd_hostapd_set_sap_key(v11);
      v424 = (void *)_qdf_mem_malloc(0x40u, "hdd_hostapd_sap_event_cb", 2804);
      if ( !v424 )
        goto LABEL_157;
      qmemcpy(v424, "SOFTAP.enabled", 14);
      v425 = *(_QWORD *)(v10 + 272);
      v453 = nullptr;
      v454 = 14;
      if ( !v425 )
        goto LABEL_200;
      v143 = (__int64)v424;
      if ( *(_BYTE *)(v425 + 1628) == 1 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: check for possible hw mode change",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "hdd_hostapd_sap_event_cb");
        if ( (unsigned int)policy_mgr_set_hw_mode_on_channel_switch(*v13, *(_BYTE *)(v10 + 8)) )
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: set hw mode change not done",
            v426,
            v427,
            v428,
            v429,
            v430,
            v431,
            v432,
            v433,
            "hdd_hostapd_sap_event_cb");
      }
      v434 = _hdd_objmgr_get_vdev_by_user(v10, 6, "hdd_hostapd_sap_event_cb");
      if ( v434 )
        _hdd_objmgr_put_vdev_by_user(v434, 6, "hdd_hostapd_sap_event_cb");
      v436 = qdf_event_set(v10 + 88, v435);
      if ( v436 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: qdf_event_set failed! status: %d",
          v437,
          v438,
          v439,
          v440,
          v441,
          v442,
          v443,
          v444,
          "hdd_hostapd_sap_event_cb",
          v436);
        goto LABEL_158;
      }
      wlan_hdd_apply_user_mcc_quota(v11);
      v83 = nullptr;
      v73 = nullptr;
      v82 = v143;
      goto LABEL_147;
    case 1:
      hdd_cp_stats_cstats_sap_go_stop_event(v10, a2);
      hdd_hostapd_channel_allow_suspend(v11, *(unsigned int *)(v10 + 2152));
      *(_DWORD *)(v10 + 2152) = 0;
      *(_DWORD *)(v10 + 2348) = 0;
      if ( !hdd_get_con_sap_adapter(v11, 1) )
      {
        *(_BYTE *)(v10 + 256) = 1;
        *((_BYTE *)v13 + 912) = 0;
        v141 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v141 )
        {
          v142 = v141;
          ucfg_dp_set_dfs_cac_tx(v141, *(_BYTE *)(v10 + 256), v133, v134, v135, v136, v137, v138, v139, v140);
          _hdd_objmgr_put_vdev_by_user(v142, 97, "hdd_hostapd_sap_event_cb");
        }
      }
      qdf_trace_msg(
        0x33u,
        4u,
        "Ap stopped vid %d reason=%d status %d",
        v133,
        v134,
        v135,
        v136,
        v137,
        v138,
        v139,
        v140,
        *(unsigned __int8 *)(v10 + 8),
        *(unsigned int *)(v10 + 2340),
        *((unsigned __int8 *)a2 + 8));
      if ( !(unsigned int)policy_mgr_get_mac_id_by_session_id(*v13, *(_BYTE *)(v10 + 8), v447) )
        ((void (__fastcall *)(_QWORD, __int64 *))hdd_medium_assess_stop_timer)((unsigned __int8)v447[0], v13);
      v143 = 0;
      *(_DWORD *)(v10 + 2340) = 0;
      *(_BYTE *)(v10 + 257) = 0;
      goto LABEL_158;
    case 2:
      v163 = *((_QWORD *)a2 + 5);
      if ( !v163 )
        goto LABEL_148;
      hdd_send_update_owe_info_event((__int64 *)v10, a2 + 2, v163, a2[9], v26, v27, v28, v29, v30, v31, v32, v33);
      _qdf_mem_free(*((_QWORD *)a2 + 5));
      result = 0;
      *((_QWORD *)a2 + 5) = 0;
      a2[9] = 0;
      break;
    case 3:
    case 4:
      hdd_cp_stats_cstats_log_sap_go_sta_assoc_reassoc_event(v10, a2);
      hdd_init_scan_reject_params(v13);
      if ( *((_BYTE *)a2 + 21) == 1 )
      {
        qdf_trace_msg(
          0x33u,
          4u,
          "%s: assoc failure: %02x:%02x:%02x:**:**:%02x",
          v35,
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          "hdd_hostapd_sap_event_cb",
          0,
          0,
          0,
          0);
        goto LABEL_145;
      }
      hdd_hostapd_apply_action_oui(v13, v11, a2 + 2);
      v106 = a2[2];
      v107 = *(unsigned __int8 *)(v10 + 8);
      v108 = *((unsigned __int8 *)a2 + 192);
      HIWORD(v453) = *((_WORD *)a2 + 6);
      v109 = *((unsigned __int8 *)a2 + 193);
      v110 = *((unsigned __int8 *)a2 + 194);
      v111 = *((unsigned __int8 *)a2 + 197);
      *(_DWORD *)((char *)&v453 + 2) = v106;
      LOWORD(v453) = 1;
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Vdev %d, STA %02x:%02x:%02x:**:**:%02x with mld mac %02x:%02x:%02x:**:**:%02x associated",
        v112,
        v113,
        v114,
        v115,
        v116,
        v117,
        v118,
        v119,
        "hdd_hostapd_sap_event_cb",
        v107,
        (unsigned __int8)v106,
        BYTE1(v106),
        BYTE2(v106),
        HIBYTE(v453),
        v108,
        v109,
        v110,
        v111);
      v120 = *(_DWORD *)(v10 + 264);
      v121 = v120 > 2;
      if ( *((_BYTE *)a2 + 198) == 1 )
      {
        if ( *((_BYTE *)a2 + 21) )
          v122 = v120 > 2;
        else
          v122 = 0;
        v121 = v122;
      }
      v123 = hdd_softap_register_sta(v10, v121, *(_BYTE *)(v10 + 260) != 0, (char *)&v453 + 2, a2 + 2);
      if ( v123 )
      {
        LODWORD(v445) = HIBYTE(v453);
        v132 = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Failed to register STA %d %02x:%02x:%02x:**:**:%02x",
                 v124,
                 v125,
                 v126,
                 v127,
                 v128,
                 v129,
                 v130,
                 v131,
                 "hdd_hostapd_sap_event_cb",
                 v123,
                 BYTE2(v453),
                 BYTE3(v453),
                 BYTE4(v453),
                 v445);
      }
      else
      {
        v132 = hdd_fill_station_info(v11, a2 + 2);
      }
      if ( (ucfg_ipa_is_enabled(v132) & 1) != 0 )
      {
        v250 = *((_WORD *)a2 + 6);
        v251 = v13[1];
        v252 = *(_QWORD *)(v11 + 32);
        v253 = *(unsigned int *)(v11 + 40);
        v254 = *(unsigned __int8 *)(v10 + 8);
        v455 = a2[2];
        v456 = v250;
        if ( (unsigned int)ucfg_ipa_wlan_evt(v251, v252, v253, v254, 6, &v455, 0) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: WLAN_CLIENT_CONNECT_EX event failed",
            v255,
            v256,
            v257,
            v258,
            v259,
            v260,
            v261,
            v262,
            "hdd_hostapd_sap_event_cb");
      }
      qdf_dp_trace_mgmt_pkt(5, *(_BYTE *)(v10 + 8), 0xFFu, 3, 28);
      if ( (*(_BYTE *)(v10 + 257) & 1) == 0 )
      {
        v263 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v263 )
        {
          v272 = v263;
          ucfg_dp_bus_bw_compute_prev_txrx_stats(v263, v264, v265, v266, v267, v268, v269, v270, v271);
          _hdd_objmgr_put_vdev_by_user(v272, 97, "hdd_hostapd_sap_event_cb");
        }
        ucfg_dp_bus_bw_compute_timer_start(*v13, v264, v265, v266, v267, v268, v269, v270, v271);
      }
      *(_BYTE *)(v10 + 257) = 1;
      hdd_hostapd_update_beacon_country_ie(v11);
      cds_host_diag_log_work(v13 + 36);
      qdf_wake_lock_timeout_acquire((__int64)(v13 + 36), 1000);
      v273 = (unsigned int)a2[8];
      v274 = _qdf_mem_malloc(0x108u, "hdd_hostapd_sap_event_cb", 3186);
      if ( !v274 )
        goto LABEL_14;
      *(_QWORD *)(v274 + 120) = *((_QWORD *)a2 + 3);
      *(_QWORD *)(v274 + 128) = v273;
      v275 = v274;
      hdd_hostapd_sap_fill_peer_ml_info(v10, v274);
      cfg80211_new_sta(v12, a2 + 2, v275, 3264);
      _qdf_mem_free(v275);
      if ( (unsigned int)ucfg_scan_get_vdev_status(
                           *(_QWORD *)(v10 + 32),
                           v276,
                           v277,
                           v278,
                           v279,
                           v280,
                           v281,
                           v282,
                           v283) )
        wlan_abort_scan(v13[1], -1, *(unsigned __int8 *)(v10 + 8), 0xFFFFFFFF, 0);
      if ( *(_DWORD *)(v11 + 40) == 3 )
        hdd_send_peer_status_ind_to_app(
          a2 + 2,
          1,
          *((unsigned __int8 *)a2 + 41),
          *(unsigned __int8 *)(v10 + 8),
          a2 + 11);
      hdd_green_ap_add_sta(v13);
      goto LABEL_145;
    case 5:
      v199 = *((_WORD *)a2 + 6);
      *(_DWORD *)((char *)&v453 + 2) = a2[2];
      HIWORD(v453) = v199;
      hdd_init_scan_reject_params(v13);
      sta_info_by_mac = hdd_get_sta_info_by_mac(v11 + 38888, a2 + 2, 17, 1);
      v449 = sta_info_by_mac;
      if ( sta_info_by_mac )
      {
        v209 = a2[7];
        *(_BYTE *)(sta_info_by_mac + 212) = v209;
        *(_DWORD *)(sta_info_by_mac + 128) = a2[8];
        *(_DWORD *)(sta_info_by_mac + 132) = a2[9];
        *(_DWORD *)(sta_info_by_mac + 232) = a2[10];
        *(_DWORD *)(sta_info_by_mac + 228) = a2[11];
        *(_DWORD *)(sta_info_by_mac + 208) = a2[5];
        *(_QWORD *)(sta_info_by_mac + 120) = jiffies;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Cache_stainfo rssi %d txrate %d rxrate %d reason_code %d",
          v201,
          v202,
          v203,
          v204,
          v205,
          v206,
          v207,
          v208,
          "hdd_hostapd_sap_event_cb",
          (unsigned int)(char)v209);
        hdd_put_sta_info_ref(v11 + 38888, &v449, 1, 17);
      }
      hdd_cp_stats_cstats_log_sap_go_sta_disassoc_event(v10, a2);
      if ( (unsigned int)qdf_event_set(v10 + 168, v210) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Station Deauth event Set failed",
          v211,
          v212,
          v213,
          v214,
          v215,
          v216,
          v217,
          v218,
          "hdd_hostapd_sap_event_cb");
      qdf_dp_trace_mgmt_pkt(5, *(_BYTE *)(v10 + 8), 0xFFu, 3, 29);
      v219 = (unsigned __int8 *)hdd_get_sta_info_by_mac(v11 + 38848, a2 + 2, 17, 1);
      v450 = v219;
      if ( v219 )
      {
        v228 = (const char *)&unk_8B9E43;
        if ( a2[6] == 65537 )
          v228 = "by user ";
        qdf_trace_msg(
          0x33u,
          4u,
          "SAP(%d) Peer %02x:%02x:%02x:**:**:%02x with mld %02x:%02x:%02x:**:**:%02x disassociated %sreason %d status code %d",
          v220,
          v221,
          v222,
          v223,
          v224,
          v225,
          v226,
          v227,
          *(unsigned __int8 *)(v10 + 8),
          v219[32],
          v219[33],
          v219[34],
          v219[37],
          v219[38],
          v219[39],
          v219[40],
          v219[43],
          v228,
          a2[5],
          a2[4]);
        v229 = *((_WORD *)a2 + 6);
        v455 = a2[2];
        v456 = v229;
        v230 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v230 )
        {
          v239 = v230;
          ucfg_dp_update_dhcp_state_on_disassoc(
            v230,
            (unsigned __int8 *)a2 + 8,
            v231,
            v232,
            v233,
            v234,
            v235,
            v236,
            v237,
            v238);
          _hdd_objmgr_put_vdev_by_user(v239, 97, "hdd_hostapd_sap_event_cb");
        }
        hdd_softap_deregister_sta(v11, &v450);
        hdd_put_sta_info_ref(v11 + 38848, &v450, 1, 17);
        *(_BYTE *)(v10 + 257) = 0;
        qdf_spin_lock_bh_5(v11 + 38872);
        hdd_get_front_sta_info_no_lock(v11 + 38848, &v450);
        if ( v450 )
          hdd_take_sta_info_ref(v11 + 38848, v450, 0, 17);
        hdd_get_next_sta_info_no_lock(v11 + 38848);
        if ( v448 )
          hdd_take_sta_info_ref(v11 + 38848, v448, 0, 17);
        qdf_spin_unlock_bh_3(v11 + 38872);
        v240 = v450;
        if ( v450 )
        {
          while ( 1 )
          {
            v460 = -1;
            v459 = -1;
            if ( (qdf_is_macaddr_equal_1(v240 + 32, &v459) & 1) == 0 )
              break;
            hdd_put_sta_info_ref(v11 + 38848, &v450, 1, 17);
            qdf_spin_lock_bh_5(v11 + 38872);
            v450 = v448;
            hdd_get_next_sta_info_no_lock(v11 + 38848);
            if ( v448 )
              hdd_take_sta_info_ref(v11 + 38848, v448, 0, 17);
            qdf_spin_unlock_bh_3(v11 + 38872);
            v240 = v450;
            if ( !v450 )
              goto LABEL_174;
          }
          *(_BYTE *)(v10 + 257) = 1;
          hdd_put_sta_info_ref(v11 + 38848, &v450, 1, 17);
          if ( v448 )
            hdd_put_sta_info_ref(v11 + 38848, &v448, 1, 17);
        }
LABEL_174:
        hdd_hostapd_update_beacon_country_ie(v11);
        cds_host_diag_log_work(v13 + 36);
        qdf_wake_lock_timeout_acquire((__int64)(v13 + 36), 1000);
        if ( *(_DWORD *)(v11 + 40) != 3
          || (cds_get_driver_state(v371, v372, v373, v374, v375, v376, v377, v378) & 8) == 0 )
        {
          cfg80211_del_sta_sinfo(v12, &v455, 0, 3264);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: indicate sta deletion event",
            v379,
            v380,
            v381,
            v382,
            v383,
            v384,
            v385,
            v386,
            "hdd_hostapd_sap_event_cb");
        }
        v387 = policy_mgr_change_mcc_go_beacon_interval(*v13, *(unsigned __int8 *)(v10 + 8), *(_DWORD *)(v11 + 40));
        if ( v387 )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to update Beacon interval status: %d",
            v388,
            v389,
            v390,
            v391,
            v392,
            v393,
            v394,
            v395,
            "hdd_hostapd_sap_event_cb",
            v387);
        if ( *(_DWORD *)(v11 + 40) == 3 )
          os_if_wifi_pos_send_peer_status(a2 + 2, 2, 0, *(unsigned __int8 *)(v10 + 8), 0, 3);
        if ( (*(_BYTE *)(v10 + 257) & 1) == 0 )
        {
          v396 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
          if ( v396 )
          {
            v405 = v396;
            ucfg_dp_bus_bw_compute_reset_prev_txrx_stats(v396, v397, v398, v399, v400, v401, v402, v403, v404);
            _hdd_objmgr_put_vdev_by_user(v405, 97, "hdd_hostapd_sap_event_cb");
          }
          ucfg_dp_bus_bw_compute_timer_try_stop(*v13);
        }
        hdd_green_ap_del_sta(v13);
        goto LABEL_145;
      }
      v284 = (const char *)&unk_8B9E43;
      if ( a2[6] == 65537 )
        v284 = "by user ";
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to find STA info for %02x:%02x:%02x:**:**:%02x %sreason %d sc %d",
        v220,
        v221,
        v222,
        v223,
        v224,
        v225,
        v226,
        v227,
        "hdd_hostapd_sap_event_cb",
        *((unsigned __int8 *)a2 + 8),
        *((unsigned __int8 *)a2 + 9),
        *((unsigned __int8 *)a2 + 10),
        *((unsigned __int8 *)a2 + 13),
        v284,
        a2[5],
        a2[4]);
      result = 4;
      break;
    case 6:
      if ( *((_BYTE *)a2 + 8) )
        v154 = "eSAP_STATUS_FAILURE";
      else
        v154 = "eSAP_STATUS_SUCCESS";
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Vdev %d SET Key: configured status = %s",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_hostapd_sap_event_cb",
        *(unsigned __int8 *)(v10 + 8),
        v154);
      if ( !*((_BYTE *)a2 + 8) )
      {
        hdd_softap_change_sta_state(v10, (char *)a2 + 9, 3);
        wlan_hdd_send_sta_authorized_event(
          v11,
          (__int64)v13,
          (__int64)a2 + 9,
          v155,
          v156,
          v157,
          v158,
          v159,
          v160,
          v161,
          v162);
      }
      goto LABEL_148;
    case 7:
      v246 = *((unsigned __int8 *)a2 + 14);
      v245 = (unsigned __int8 *)a2 + 14;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Vdev %d MIC MAC %02x:%02x:%02x:**:**:%02x",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_hostapd_sap_event_cb",
        *(unsigned __int8 *)(v10 + 8),
        v246,
        v245[1],
        v245[2],
        v245[5]);
      v247 = v245[14];
      v248 = v245[12] ^ 1u;
      v453 = nullptr;
      v454 = 28;
      cfg80211_michael_mic_failure(v12, v245, v248, v247, v245 + 15, 3264);
      goto LABEL_145;
    case 8:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: WPS PBC probe req",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_hostapd_sap_event_cb");
      goto LABEL_148;
    case 9:
      hdd_clear_all_sta(v11);
      goto LABEL_148;
    case 10:
      result = hdd_stop_bss_link(v10);
      if ( !(_DWORD)result )
        break;
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: hdd_stop_bss_link failed %d",
        v64,
        v65,
        v66,
        v67,
        v68,
        v69,
        v70,
        v71,
        "hdd_hostapd_sap_event_cb",
        (unsigned int)result);
      goto LABEL_148;
    case 11:
      v72 = (char *)_qdf_mem_malloc(0x101u, "hdd_hostapd_sap_event_cb", 3444);
      if ( !v72 )
        goto LABEL_166;
      v73 = v72;
      snprintf(
        v72,
        0x100u,
        "JOIN_UNKNOWN_STA-%02x:%02x:%02x:**:**:%02x",
        *((unsigned __int8 *)a2 + 8),
        *((unsigned __int8 *)a2 + 9),
        *((unsigned __int8 *)a2 + 10),
        *((unsigned __int8 *)a2 + 13));
      v453 = v73;
      LOWORD(v454) = strlen(v73);
      qdf_trace_msg(0x33u, 2u, "%s: %s", v74, v75, v76, v77, v78, v79, v80, v81, "hdd_hostapd_sap_event_cb", v73);
      v82 = 0;
      v83 = nullptr;
      goto LABEL_147;
    case 12:
      v190 = (char *)_qdf_mem_malloc(0x101u, "hdd_hostapd_sap_event_cb", 3459);
      if ( !v190 )
        goto LABEL_166;
      v83 = v190;
      snprintf(
        v190,
        0x100u,
        "Peer %02x:%02x:%02x:**:**:%02x denied assoc due to Maximum Mobile Hotspot connections reached. Please disconnect"
        " one or more devices to enable the new device connection",
        *((unsigned __int8 *)a2 + 8),
        *((unsigned __int8 *)a2 + 9),
        *((unsigned __int8 *)a2 + 10),
        *((unsigned __int8 *)a2 + 13));
      v453 = v83;
      LOWORD(v454) = strlen(v83);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev %d %s",
        v191,
        v192,
        v193,
        v194,
        v195,
        v196,
        v197,
        v198,
        "hdd_hostapd_sap_event_cb",
        *(unsigned __int8 *)(v10 + 8),
        v83);
      v82 = 0;
      goto LABEL_146;
    case 13:
      if ( *(_DWORD *)(v10 + 80) )
      {
        hdd_hostapd_channel_allow_suspend(v11, *(unsigned int *)(*(_QWORD *)(v10 + 272) + 1720LL));
        v26 = hdd_hostapd_channel_prevent_suspend(v11, (unsigned int)a2[2]);
      }
      v53 = a2[2];
      *(_DWORD *)(v10 + 2152) = v53;
      *(_DWORD *)(v10 + 1980) = v53;
      *(_DWORD *)(v10 + 1984) = a2[3];
      *(_DWORD *)(v10 + 1988) = *((unsigned __int16 *)a2 + 8);
      *(_DWORD *)(v10 + 1992) = *((unsigned __int16 *)a2 + 9);
      *(_WORD *)(v10 + 1458) = *((_WORD *)a2 + 10);
      *(_DWORD *)(v10 + 720) = *(_DWORD *)a1;
      v54 = *(_QWORD *)(a1 + 1500);
      *(_QWORD *)(v10 + 736) = *(_QWORD *)(a1 + 1508);
      *(_QWORD *)(v10 + 728) = v54;
      *(_DWORD *)(v10 + 724) = *(_DWORD *)(a1 + 4);
      _cds_get_context(71, (__int64)"hdd_hostapd_sap_event_cb", v26, v27, v28, v29, v30, v31, v32, v33);
      v55 = *(_QWORD *)(v10 + 272);
      if ( !v55 )
      {
LABEL_200:
        v43 = "%s: sap ctx is null";
        goto LABEL_13;
      }
      if ( *(_BYTE *)(v55 + 1628) == 1 )
      {
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: check for possible hw mode change",
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "hdd_hostapd_sap_event_cb");
        if ( (unsigned int)policy_mgr_set_hw_mode_on_channel_switch(*v13, *(_BYTE *)(v10 + 8)) )
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: set hw mode change not done",
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            v62,
            v63,
            "hdd_hostapd_sap_event_cb");
      }
LABEL_43:
      hdd_hostapd_chan_change(v10, a2);
      goto LABEL_148;
    case 14:
      wlan_hdd_send_svc_nlink_msg(*((unsigned int *)v13 + 364), 259, &v457, 6);
      *((_BYTE *)v13 + 912) = 1;
      hdd_cp_stats_cstats_log_sap_go_dfs_event(v10, 14);
      if ( (unsigned int)hdd_send_radar_event(v10, 14, v457 | ((unsigned __int64)v458 << 32)) )
      {
        v152 = "%s: Unable to indicate CAC start NL event";
        v153 = 2;
      }
      else
      {
        v152 = "%s: Sent CAC start to user space";
        v153 = 8;
      }
      qdf_trace_msg(0x33u, v153, v152, v144, v145, v146, v147, v148, v149, v150, v151, "hdd_hostapd_sap_event_cb");
      *(_DWORD *)(v10 + 2348) = 0;
      hdd_reset_tsf_sync(v11);
      goto LABEL_145;
    case 15:
      hdd_cp_stats_cstats_log_sap_go_dfs_event(v10, 15);
      if ( (unsigned int)hdd_send_radar_event(v10, 16, v457 | ((unsigned __int64)v458 << 32)) )
      {
        v52 = "%s: Unable to indicate CAC end (interrupted) event";
        goto LABEL_114;
      }
      v52 = "%s: Sent CAC end (interrupted) to user space";
      goto LABEL_143;
    case 16:
      wlan_hdd_send_svc_nlink_msg(*((unsigned int *)v13 + 364), 260, &v457, 6);
      *(_BYTE *)(v10 + 256) = 0;
      ucfg_ipa_set_dfs_cac_tx(v13[1], 0);
      v177 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
      if ( v177 )
      {
        v186 = v177;
        ucfg_dp_set_dfs_cac_tx(v177, *(_BYTE *)(v10 + 256), v178, v179, v180, v181, v182, v183, v184, v185);
        _hdd_objmgr_put_vdev_by_user(v186, 97, "hdd_hostapd_sap_event_cb");
      }
      hdd_cp_stats_cstats_log_sap_go_dfs_event(v10, 16);
      v187 = v458;
      v188 = v457;
      *((_BYTE *)v13 + 912) = 2;
      if ( (unsigned int)hdd_send_radar_event(v10, 16, v188 | (v187 << 32)) )
      {
        v52 = "%s: Unable to indicate CAC end NL event";
        goto LABEL_114;
      }
      v52 = "%s: Sent CAC end to user space";
      goto LABEL_143;
    case 17:
      hdd_cp_stats_cstats_log_sap_go_dfs_event(v10, 17);
      hdd_dfs_indicate_radar(v13);
      wlan_hdd_send_svc_nlink_msg(*((unsigned int *)v13 + 364), 261, &v457, 6);
      *((_BYTE *)v13 + 912) = 0;
      v241 = *(_DWORD *)(v10 + 2128);
      if ( v241 )
      {
        for ( i = 0; i < v241; ++i )
        {
          v243 = *(_QWORD *)(v10 + 2120) + 20LL * (int)i;
          if ( (unsigned __int16)v457 == *(unsigned __int8 *)(v243 + 10) )
          {
            *(_DWORD *)(v243 + 4) |= 0x1000u;
            v241 = *(_DWORD *)(v10 + 2128);
          }
        }
      }
      if ( (unsigned int)hdd_send_radar_event(v10, 17, v457 | ((unsigned __int64)v458 << 32)) )
      {
        v52 = "%s: Unable to indicate Radar detect NL event";
LABEL_114:
        v244 = 2;
      }
      else
      {
        v52 = "%s: Sent radar detected to user space";
LABEL_143:
        v244 = 8;
      }
      qdf_trace_msg(0x33u, v244, v52, v44, v45, v46, v47, v48, v49, v50, v51, "hdd_hostapd_sap_event_cb");
      wlan_reg_chan_band_to_freq(v13[1], (unsigned __int8)v457, 2u, v285, v286, v287, v288, v289, v290, v291, v292);
LABEL_145:
      v82 = 0;
      v83 = nullptr;
LABEL_146:
      v73 = nullptr;
LABEL_147:
      _qdf_mem_free(v82);
      _qdf_mem_free((__int64)v73);
      _qdf_mem_free((__int64)v83);
      goto LABEL_148;
    case 18:
      wlan_hdd_send_svc_nlink_msg(*((unsigned int *)v13 + 364), 264, &v457, 6);
      goto LABEL_145;
    case 19:
      v104 = *(unsigned __int8 *)(v10 + 8);
      v105 = "%s: eSAP_STOP_BSS_DUE_TO_NO_CHNL Stop sap vdev %d";
      goto LABEL_82;
    case 20:
      break;
    case 21:
      v189 = *(unsigned __int8 *)(v10 + 8);
      *(_DWORD *)(v10 + 1980) = a2[2];
      *(_DWORD *)(v10 + 1984) = a2[3];
      *(_DWORD *)(v10 + 1988) = *((unsigned __int16 *)a2 + 8);
      *(_DWORD *)(v10 + 1992) = *((unsigned __int16 *)a2 + 9);
      *(_WORD *)(v10 + 1458) = *((_WORD *)a2 + 10);
      qdf_trace_msg(
        0x33u,
        4u,
        "Vdev %d ACS Completed freq %d BW %d flag 0x%lx ACS in progress %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v189);
      if ( *(_DWORD *)(v10 + 2344) && (*(_QWORD *)(v10 + 4416) & 2) != 0 )
      {
        hdd_dcs_chan_select_complete(v11);
      }
      else
      {
        wlan_hdd_cfg80211_acs_ch_select_evt((__int64 *)v10, 1);
        ((void (__fastcall *)(_QWORD, __int64))wlansap_dcs_set_wlan_interference_mitigation_on_band)(
          *(_QWORD *)(v10 + 272),
          v10 + 280);
      }
      goto LABEL_148;
    case 22:
      v249 = a2[2];
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Channel change indication from peer for channel freq %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_hostapd_sap_event_cb",
        v249);
      wlan_hdd_set_sap_csa_reason(*v13, *(unsigned __int8 *)(v10 + 8), 3);
      result = 16 * (unsigned int)((unsigned int)hdd_softap_set_channel_change(v10, v249, 0, 9, 0, 0, 0) != 0);
      break;
    case 23:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Sending next channel query to userspace",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_hostapd_sap_event_cb");
      hdd_update_acs_timer_reason(v11, 1);
      goto LABEL_148;
    case 24:
      *(_DWORD *)(v10 + 2348) = 0;
      policy_mgr_set_chan_switch_complete_evt(*v13);
      v84 = wlan_hdd_set_roaming_state(v10, 8, 1);
      if ( (wlan_reg_is_dfs_for_freq(v13[1], *(_DWORD *)(v10 + 2152), v84, v85, v86, v87, v88, v89, v90, v91) & 1) == 0 )
      {
        *(_BYTE *)(v10 + 256) = 0;
        v92 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v92 )
        {
          v101 = v92;
          ucfg_dp_set_dfs_cac_tx(v92, *(_BYTE *)(v10 + 256), v93, v94, v95, v96, v97, v98, v99, v100);
          _hdd_objmgr_put_vdev_by_user(v101, 97, "hdd_hostapd_sap_event_cb");
        }
      }
      if ( !policy_mgr_is_vdev_ll_lt_sap(*v13, *(unsigned __int8 *)(v10 + 8)) )
        hdd_hostapd_check_channel_post_csa(v13, v10);
      v103 = qdf_event_set(v10 + 88, v102);
      if ( v103 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: qdf_event_set failed! status: %d",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "hdd_hostapd_sap_event_cb",
          v103);
      if ( !a2[6] )
        goto LABEL_43;
      v104 = *(unsigned __int8 *)(v10 + 8);
      v105 = "%s: SAP[vdev%d] channel switch fail, will stop";
LABEL_82:
      qdf_trace_msg(0x33u, 8u, v105, v26, v27, v28, v29, v30, v31, v32, v33, "hdd_hostapd_sap_event_cb", v104);
      queue_work_on(32, system_wq, v10 + 4496);
      goto LABEL_148;
    case 25:
      hdd_hostapd_chan_change_started(v10, a2[2], (_DWORD)a2 + 12);
      goto LABEL_148;
    default:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: SAP message is not handled",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_hostapd_sap_event_cb");
LABEL_157:
      v143 = 0;
LABEL_158:
      *(_DWORD *)(v10 + 80) = 0;
      v314 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
      if ( v314 )
      {
        v323 = v314;
        ucfg_dp_set_bss_state_start(v314, 0, v315, v316, v317, v318, v319, v320, v321, v322);
        _hdd_objmgr_put_vdev_by_user(v323, 97, "hdd_hostapd_sap_event_cb");
      }
      hdd_reset_tsf_sync(v11);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev %d Disabling queues",
        v324,
        v325,
        v326,
        v327,
        v328,
        v329,
        v330,
        v331,
        "hdd_hostapd_sap_event_cb",
        *(unsigned __int8 *)(*(_QWORD *)(v11 + 52824) + 8LL));
      wlan_hdd_netif_queue_control(v11, 4, 1);
      v332 = hdd_softap_stop_bss(v10);
      if ( v332 )
      {
        v341 = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: hdd_softap_stop_bss failed %d",
                 v333,
                 v334,
                 v335,
                 v336,
                 v337,
                 v338,
                 v339,
                 v340,
                 "hdd_hostapd_sap_event_cb",
                 v332);
        if ( (ucfg_ipa_is_enabled(v341) & 1) != 0 )
        {
          ucfg_ipa_uc_disconnect_ap(v13[1], *(_QWORD *)(v11 + 32));
          ucfg_ipa_cleanup_dev_iface(v13[1], *(_QWORD *)(v11 + 32), *(unsigned __int8 *)(v10 + 8));
        }
      }
      v342 = (void *)_qdf_mem_malloc(0x40u, "hdd_hostapd_sap_event_cb", 3739);
      if ( v342 )
      {
        v343 = (__int64)v342;
        qmemcpy(v342, "STOP-BSS.response", 17);
        v453 = nullptr;
        v454 = 17;
        _qdf_mem_free(v143);
        _qdf_mem_free(0);
        _qdf_mem_free(0);
        _qdf_mem_free(v343);
        if ( v14 == 1 )
        {
          qdf_event_set(v10 + 128, v344);
          ucfg_dp_bus_bw_compute_timer_try_stop(*v13);
        }
LABEL_148:
        result = 0;
      }
      else
      {
LABEL_166:
        result = 2;
      }
      break;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
