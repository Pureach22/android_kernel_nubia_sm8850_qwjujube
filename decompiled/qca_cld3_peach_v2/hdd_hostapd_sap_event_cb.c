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
  __int64 v12; // x24
  __int64 *v13; // x20
  int v14; // w26
  __int64 v16; // x25
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
  int *v35; // x1
  unsigned int *v36; // x22
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  const char *v45; // x2
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  const char *v54; // x2
  int v55; // w8
  __int64 v56; // x8
  __int64 v57; // x10
  __int64 v58; // x8
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  char *v75; // x0
  const char *v76; // x19
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  __int64 v85; // x0
  const char *v86; // x20
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  __int64 v95; // x0
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  __int64 v104; // x21
  __int64 v105; // x1
  unsigned int v106; // w0
  __int64 v107; // x4
  const char *v108; // x2
  unsigned int v109; // w8
  __int64 v110; // x4
  int *v111; // x25
  int v112; // t1
  int v113; // w12
  int v114; // w13
  int v115; // w14
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v124; // w8
  _BOOL8 v125; // x1
  bool v126; // cc
  unsigned int v127; // w0
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  __int64 v136; // x0
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int64 v145; // x0
  __int64 v146; // x23
  __int64 v147; // x22
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  const char *v156; // x2
  unsigned int v157; // w1
  const char *v158; // x5
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  __int64 v167; // x2
  const char *v168; // x3
  __int64 v169; // x8
  __int64 v170; // x9
  __int64 v171; // x10
  double dfs_cac_state; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  char is_dfs_for_freq; // w0
  __int64 v181; // x1
  __int64 v182; // x0
  double v183; // d0
  double v184; // d1
  double v185; // d2
  double v186; // d3
  double v187; // d4
  double v188; // d5
  double v189; // d6
  double v190; // d7
  __int64 v191; // x21
  __int64 v192; // x8
  __int64 v193; // x9
  __int64 v194; // x3
  char *v195; // x0
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  __int16 v204; // w9
  __int64 sta_info_by_mac; // x0
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  int v214; // w9
  __int64 v215; // x1
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  unsigned __int8 *v224; // x0
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  const char *v233; // x10
  unsigned __int8 *v234; // x25
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  __int16 v243; // w9
  __int64 v244; // x0
  double v245; // d0
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  unsigned __int8 *v253; // x1
  __int64 v254; // x23
  unsigned __int8 *v255; // x8
  unsigned int v256; // w9
  unsigned int i; // w8
  __int64 v258; // x11
  unsigned int v259; // w1
  __int64 v260; // x3
  __int64 v261; // x2
  unsigned int v262; // w21
  double v263; // d0
  double v264; // d1
  double v265; // d2
  double v266; // d3
  double v267; // d4
  double v268; // d5
  double v269; // d6
  double v270; // d7
  __int16 v271; // w9
  __int64 v272; // x0
  __int64 v273; // x1
  __int64 v274; // x2
  __int64 v275; // x3
  double v276; // d0
  double v277; // d1
  double v278; // d2
  double v279; // d3
  double v280; // d4
  double v281; // d5
  double v282; // d6
  double v283; // d7
  __int64 v284; // x0
  double v285; // d0
  double v286; // d1
  double v287; // d2
  double v288; // d3
  double v289; // d4
  double v290; // d5
  double v291; // d6
  double v292; // d7
  __int64 v293; // x25
  __int64 v294; // x25
  __int64 v295; // x0
  __int64 v296; // x25
  double v297; // d0
  double v298; // d1
  double v299; // d2
  double v300; // d3
  double v301; // d4
  double v302; // d5
  double v303; // d6
  double v304; // d7
  const char *v305; // x9
  double v306; // d0
  double v307; // d1
  double v308; // d2
  double v309; // d3
  double v310; // d4
  double v311; // d5
  double v312; // d6
  double v313; // d7
  __int64 vdev_by_user; // x0
  double v315; // d0
  double v316; // d1
  double v317; // d2
  double v318; // d3
  double v319; // d4
  double v320; // d5
  double v321; // d6
  double v322; // d7
  __int64 v323; // x22
  __int64 v324; // x0
  __int64 v325; // x1
  double v326; // d0
  double v327; // d1
  double v328; // d2
  double v329; // d3
  double v330; // d4
  double v331; // d5
  double v332; // d6
  double v333; // d7
  __int64 v334; // x22
  __int64 v335; // x0
  double v336; // d0
  double v337; // d1
  double v338; // d2
  double v339; // d3
  double v340; // d4
  double v341; // d5
  double v342; // d6
  double v343; // d7
  __int64 v344; // x23
  double v345; // d0
  double v346; // d1
  double v347; // d2
  double v348; // d3
  double v349; // d4
  double v350; // d5
  double v351; // d6
  double v352; // d7
  unsigned int v353; // w0
  double v354; // d0
  double v355; // d1
  double v356; // d2
  double v357; // d3
  double v358; // d4
  double v359; // d5
  double v360; // d6
  double v361; // d7
  __int64 v362; // x0
  void *v363; // x0
  __int64 v364; // x21
  __int64 v365; // x1
  double updated; // d0
  double v367; // d1
  double v368; // d2
  double v369; // d3
  double v370; // d4
  double v371; // d5
  double v372; // d6
  double v373; // d7
  __int64 v374; // x0
  double v375; // d0
  double v376; // d1
  double v377; // d2
  double v378; // d3
  double v379; // d4
  double v380; // d5
  double v381; // d6
  double v382; // d7
  double v383; // d0
  double v384; // d1
  double v385; // d2
  double v386; // d3
  double v387; // d4
  double v388; // d5
  double v389; // d6
  double v390; // d7
  char v391; // w8
  double v392; // d0
  double v393; // d1
  double v394; // d2
  double v395; // d3
  double v396; // d4
  double v397; // d5
  double v398; // d6
  double v399; // d7
  double v400; // d0
  double v401; // d1
  double v402; // d2
  double v403; // d3
  double v404; // d4
  double v405; // d5
  double v406; // d6
  double v407; // d7
  unsigned int v408; // w0
  double v409; // d0
  double v410; // d1
  double v411; // d2
  double v412; // d3
  double v413; // d4
  double v414; // d5
  double v415; // d6
  double v416; // d7
  __int64 v417; // x0
  double v418; // d0
  double v419; // d1
  double v420; // d2
  double v421; // d3
  double v422; // d4
  double v423; // d5
  double v424; // d6
  double v425; // d7
  __int64 v426; // x19
  double v427; // d0
  double v428; // d1
  double v429; // d2
  double v430; // d3
  double v431; // d4
  double v432; // d5
  double v433; // d6
  double v434; // d7
  __int64 v435; // x0
  double v436; // d0
  double v437; // d1
  double v438; // d2
  double v439; // d3
  double v440; // d4
  double v441; // d5
  double v442; // d6
  double v443; // d7
  __int64 v444; // x22
  void *v445; // x0
  __int64 v446; // x8
  double v447; // d0
  double v448; // d1
  double v449; // d2
  double v450; // d3
  double v451; // d4
  double v452; // d5
  double v453; // d6
  double v454; // d7
  __int64 v455; // x0
  __int64 v456; // x1
  unsigned int v457; // w0
  double v458; // d0
  double v459; // d1
  double v460; // d2
  double v461; // d3
  double v462; // d4
  double v463; // d5
  double v464; // d6
  double v465; // d7
  __int64 v466; // [xsp+0h] [xbp-90h]
  char v467[4]; // [xsp+38h] [xbp-58h] BYREF
  char v468[4]; // [xsp+3Ch] [xbp-54h] BYREF
  unsigned __int8 *v469; // [xsp+40h] [xbp-50h] BYREF
  __int64 v470; // [xsp+48h] [xbp-48h] BYREF
  unsigned __int8 *v471; // [xsp+50h] [xbp-40h] BYREF
  char v472[4]; // [xsp+58h] [xbp-38h] BYREF
  char v473[4]; // [xsp+5Ch] [xbp-34h] BYREF
  const char *v474; // [xsp+60h] [xbp-30h] BYREF
  __int64 v475; // [xsp+68h] [xbp-28h]
  int v476; // [xsp+70h] [xbp-20h] BYREF
  __int16 v477; // [xsp+74h] [xbp-1Ch]
  unsigned int v478; // [xsp+78h] [xbp-18h] BYREF
  unsigned __int16 v479; // [xsp+7Ch] [xbp-14h]
  int v480; // [xsp+80h] [xbp-10h] BYREF
  __int16 v481; // [xsp+84h] [xbp-Ch]
  __int64 v482; // [xsp+88h] [xbp-8h]

  v482 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)(a1 + 1216);
  v474 = nullptr;
  v475 = 0;
  v473[0] = 0;
  v472[0] = 0;
  v479 = 0;
  v478 = 0;
  v471 = nullptr;
  v469 = nullptr;
  v470 = 0;
  v468[0] = 0;
  v477 = 0;
  v476 = 0;
  v467[0] = 0;
  if ( !v10 )
  {
    v45 = "%s: invalid link info";
    goto LABEL_13;
  }
  v11 = *(_QWORD *)v10;
  if ( !*(_QWORD *)v10 || *(_DWORD *)v11 != 1885692259 )
  {
    v45 = "%s: invalid adapter or adapter has invalid magic";
    goto LABEL_13;
  }
  v12 = *(_QWORD *)(v11 + 32);
  if ( !v12 )
  {
    v45 = "%s: dev is null";
    goto LABEL_13;
  }
  if ( !a2 )
  {
    v45 = "%s: sap_event is null";
    goto LABEL_13;
  }
  v13 = *(__int64 **)(v11 + 24);
  v14 = *a2;
  v474 = nullptr;
  v475 = 0;
  if ( !v13 )
  {
    v45 = "%s: HDD context is null";
    goto LABEL_13;
  }
  if ( !v13[13] )
  {
    v45 = "%s: HDD config is null";
LABEL_13:
    qdf_trace_msg(0x33u, 2u, v45, a3, a4, a5, a6, a7, a8, a9, a10, "hdd_hostapd_sap_event_cb");
LABEL_14:
    result = 16;
    goto LABEL_15;
  }
  v16 = v13[2];
  LOWORD(v478) = (unsigned __int8)wlan_reg_freq_to_chan(
                                    v13[1],
                                    *(_DWORD *)(v10 + 2424),
                                    a3,
                                    a4,
                                    a5,
                                    a6,
                                    a7,
                                    a8,
                                    a9,
                                    a10);
  wlan_reg_get_cc_and_src(*v13, (char *)&v478 + 2, v18, v19, v20, v21, v22, v23, v24, v25);
  result = 0;
  v35 = a2;
  v36 = (unsigned int *)(a2 + 2);
  switch ( v14 )
  {
    case 0:
      *(_DWORD *)(v10 + 2424) = a2[3];
      *(_BYTE *)(v10 + 8) = *((_BYTE *)a2 + 22);
      *(_DWORD *)(v10 + 720) = a2[3];
      *(_DWORD *)(v10 + 728) = a2[4];
      if ( *((_BYTE *)a2 + 8) )
        v168 = "failed";
      else
        v168 = "started";
      qdf_trace_msg(0x33u, 4u, "AP %s vid %d freq %d BW %d", v26, v27, v28, v29, v30, v31, v32, v33, v168);
      hdd_cp_stats_cstats_sap_go_start_event(v10, a2);
      v169 = *(_QWORD *)(v10 + 272);
      v171 = *(_QWORD *)(v169 + 1500);
      v170 = *(_QWORD *)(v169 + 1508);
      *(_QWORD *)(v10 + 744) = *(_QWORD *)(v169 + 1516);
      *(_QWORD *)(v10 + 728) = v171;
      *(_QWORD *)(v10 + 736) = v170;
      *(_DWORD *)(v10 + 724) = *(_DWORD *)(v169 + 4);
      *(_DWORD *)(v10 + 248) = *((unsigned __int8 *)a2 + 8);
      *(_DWORD *)(v10 + 2620) = 0;
      wlansap_get_dfs_ignore_cac(v16, v473);
      if ( (policy_mgr_get_dfs_master_dynamic_enabled(*v13) & 1) == 0 )
        v473[0] = 1;
      dfs_cac_state = wlansap_get_dfs_cac_state(v16, *(_QWORD *)(v10 + 272), v472);
      is_dfs_for_freq = wlan_reg_is_dfs_for_freq(
                          v13[1],
                          *(_DWORD *)(v10 + 2424),
                          dfs_cac_state,
                          v173,
                          v174,
                          v175,
                          v176,
                          v177,
                          v178,
                          v179);
      v181 = 0;
      if ( (is_dfs_for_freq & 1) != 0 && !v473[0] )
      {
        if ( *((_BYTE *)v13 + 912) == 2 )
          v181 = 0;
        else
          v181 = (unsigned __int8)v472[0];
      }
      *(_BYTE *)(v10 + 256) = v181;
      ucfg_ipa_set_dfs_cac_tx(v13[1], v181);
      vdev_by_user = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
      if ( vdev_by_user )
      {
        v323 = vdev_by_user;
        ucfg_dp_set_dfs_cac_tx(vdev_by_user, *(_BYTE *)(v10 + 256), v315, v316, v317, v318, v319, v320, v321, v322);
        _hdd_objmgr_put_vdev_by_user(v323, 97, "hdd_hostapd_sap_event_cb");
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev %d dfs_cac_block_tx %d",
        v315,
        v316,
        v317,
        v318,
        v319,
        v320,
        v321,
        v322,
        "hdd_hostapd_sap_event_cb",
        *(unsigned __int8 *)(v10 + 8),
        *(unsigned __int8 *)(v10 + 256));
      if ( *(_DWORD *)(v10 + 248) )
      {
        *(_DWORD *)(v10 + 80) = 0;
        v324 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v324 )
        {
          v334 = v324;
          ucfg_dp_set_bss_state_start(v324, 0, v326, v327, v328, v329, v330, v331, v332, v333);
          _hdd_objmgr_put_vdev_by_user(v334, 97, "hdd_hostapd_sap_event_cb");
        }
        qdf_event_set(v10 + 88, v325);
        goto LABEL_163;
      }
      updated = sme_ch_avoid_update_req(v16);
      *(_BYTE *)(v10 + 259) = *((_BYTE *)a2 + 20);
      _cds_get_context(71, (__int64)"hdd_hostapd_sap_event_cb", updated, v367, v368, v369, v370, v371, v372, v373);
      v374 = hdd_softap_register_bc_sta(v10, *(_BYTE *)(v10 + 260) != 0);
      if ( (_DWORD)v374 )
      {
        qdf_trace_msg(
          0x33u,
          3u,
          "%s: Failed to register BC STA %d",
          v375,
          v376,
          v377,
          v378,
          v379,
          v380,
          v381,
          v382,
          "hdd_hostapd_sap_event_cb",
          (unsigned int)v374);
        v374 = hdd_stop_bss_link(v10);
      }
      if ( (ucfg_ipa_is_enabled(v374) & 1) != 0 )
      {
        if ( (unsigned int)hdd_ipa_get_tx_pipe(v13, v10, v467) )
        {
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: Failed to get alt pipe for vdev %d",
            v383,
            v384,
            v385,
            v386,
            v387,
            v388,
            v389,
            v390,
            "hdd_hostapd_sap_event_cb",
            *(unsigned __int8 *)(v10 + 8));
          v391 = 0;
          v467[0] = 0;
        }
        else
        {
          v391 = v467[0];
        }
        if ( (unsigned int)ucfg_ipa_wlan_evt(
                             v13[1],
                             *(_QWORD *)(v11 + 32),
                             *(unsigned int *)(v11 + 40),
                             *(unsigned __int8 *)(v10 + 8),
                             2,
                             *(_QWORD *)(*(_QWORD *)(v11 + 32) + 1008LL),
                             v391 & 1) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: WLAN_AP_CONNECT event failed",
            v427,
            v428,
            v429,
            v430,
            v431,
            v432,
            v433,
            v434,
            "hdd_hostapd_sap_event_cb");
      }
      hdd_hostapd_channel_prevent_suspend(v11, *(unsigned int *)(v10 + 2424));
      *(_DWORD *)(v10 + 80) = 1;
      v435 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
      if ( v435 )
      {
        v444 = v435;
        ucfg_dp_set_bss_state_start(v435, 1, v436, v437, v438, v439, v440, v441, v442, v443);
        _hdd_objmgr_put_vdev_by_user(v444, 97, "hdd_hostapd_sap_event_cb");
      }
      hdd_setup_tsf_sync(v11);
      hdd_hostapd_set_sap_key(v11);
      v445 = (void *)_qdf_mem_malloc(0x40u, "hdd_hostapd_sap_event_cb", 2804);
      if ( !v445 )
        goto LABEL_163;
      qmemcpy(v445, "SOFTAP.enabled", 14);
      v446 = *(_QWORD *)(v10 + 272);
      v474 = nullptr;
      v475 = 14;
      if ( !v446 )
        goto LABEL_206;
      v147 = (__int64)v445;
      if ( *(_BYTE *)(v446 + 1644) == 1 )
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
            v447,
            v448,
            v449,
            v450,
            v451,
            v452,
            v453,
            v454,
            "hdd_hostapd_sap_event_cb");
      }
      v455 = _hdd_objmgr_get_vdev_by_user(v10, 6, "hdd_hostapd_sap_event_cb");
      if ( v455 )
        _hdd_objmgr_put_vdev_by_user(v455, 6, "hdd_hostapd_sap_event_cb");
      v457 = qdf_event_set(v10 + 88, v456);
      if ( v457 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: qdf_event_set failed! status: %d",
          v458,
          v459,
          v460,
          v461,
          v462,
          v463,
          v464,
          v465,
          "hdd_hostapd_sap_event_cb",
          v457);
        goto LABEL_164;
      }
      wlan_hdd_apply_user_mcc_quota(v11);
      v86 = nullptr;
      v76 = nullptr;
      v85 = v147;
      goto LABEL_153;
    case 1:
      hdd_cp_stats_cstats_sap_go_stop_event(v10, a2);
      hdd_hostapd_channel_allow_suspend(v11, *(unsigned int *)(v10 + 2424));
      *(_DWORD *)(v10 + 2424) = 0;
      *(_DWORD *)(v10 + 2620) = 0;
      if ( !hdd_get_con_sap_adapter(v11, 1) )
      {
        *(_BYTE *)(v10 + 256) = 1;
        *((_BYTE *)v13 + 912) = 0;
        v145 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v145 )
        {
          v146 = v145;
          ucfg_dp_set_dfs_cac_tx(v145, *(_BYTE *)(v10 + 256), v137, v138, v139, v140, v141, v142, v143, v144);
          _hdd_objmgr_put_vdev_by_user(v146, 97, "hdd_hostapd_sap_event_cb");
        }
      }
      qdf_trace_msg(
        0x33u,
        4u,
        "Ap stopped vid %d reason=%d status %d",
        v137,
        v138,
        v139,
        v140,
        v141,
        v142,
        v143,
        v144,
        *(unsigned __int8 *)(v10 + 8),
        *(unsigned int *)(v10 + 2612),
        *(unsigned __int8 *)v36);
      if ( !(unsigned int)policy_mgr_get_mac_id_by_session_id(*v13, *(_BYTE *)(v10 + 8), v468) )
        ((void (__fastcall *)(_QWORD, __int64 *))hdd_medium_assess_stop_timer)((unsigned __int8)v468[0], v13);
      v147 = 0;
      *(_DWORD *)(v10 + 2612) = 0;
      *(_BYTE *)(v10 + 257) = 0;
      goto LABEL_164;
    case 2:
      v167 = *((_QWORD *)a2 + 5);
      if ( !v167 )
        goto LABEL_154;
      hdd_send_update_owe_info_event(
        (__int64 *)v10,
        (unsigned __int8 *)a2 + 8,
        v167,
        a2[9],
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33);
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
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "hdd_hostapd_sap_event_cb",
          0,
          0,
          0,
          0);
        goto LABEL_151;
      }
      hdd_hostapd_apply_action_oui(v13, v11, a2 + 2);
      v109 = *v36;
      v110 = *(unsigned __int8 *)(v10 + 8);
      v112 = *((unsigned __int8 *)a2 + 192);
      v111 = a2 + 48;
      HIWORD(v474) = *((_WORD *)a2 + 6);
      v113 = *((unsigned __int8 *)a2 + 193);
      v114 = *((unsigned __int8 *)a2 + 194);
      v115 = *((unsigned __int8 *)a2 + 197);
      *(_DWORD *)((char *)&v474 + 2) = v109;
      LOWORD(v474) = 1;
      qdf_trace_msg(
        0x33u,
        4u,
        "%s: Vdev %d, STA %02x:%02x:%02x:**:**:%02x with mld mac %02x:%02x:%02x:**:**:%02x associated",
        v116,
        v117,
        v118,
        v119,
        v120,
        v121,
        v122,
        v123,
        "hdd_hostapd_sap_event_cb",
        v110,
        (unsigned __int8)v109,
        BYTE1(v109),
        BYTE2(v109),
        HIBYTE(v474),
        v112,
        v113,
        v114,
        v115);
      v124 = *(_DWORD *)(v10 + 264);
      v125 = v124 > 2;
      if ( *((_BYTE *)a2 + 198) == 1 )
      {
        if ( *((_BYTE *)a2 + 21) )
          v126 = v124 > 2;
        else
          v126 = 0;
        v125 = v126;
      }
      v127 = hdd_softap_register_sta(v10, v125, *(_BYTE *)(v10 + 260) != 0, (char *)&v474 + 2, a2 + 2);
      if ( v127 )
      {
        LODWORD(v466) = HIBYTE(v474);
        v136 = qdf_trace_msg(
                 0x33u,
                 2u,
                 "%s: Failed to register STA %d %02x:%02x:%02x:**:**:%02x",
                 v128,
                 v129,
                 v130,
                 v131,
                 v132,
                 v133,
                 v134,
                 v135,
                 "hdd_hostapd_sap_event_cb",
                 v127,
                 BYTE2(v474),
                 BYTE3(v474),
                 BYTE4(v474),
                 v466);
      }
      else
      {
        v136 = hdd_fill_station_info(v11, a2 + 2);
      }
      if ( (ucfg_ipa_is_enabled(v136) & 1) != 0 )
      {
        if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(v10 + 32), v263, v264, v265, v266, v267, v268, v269, v270) & 1) == 0
          || (v481 = 0, v480 = 0, (qdf_is_macaddr_equal_1(v111, &v480) & 1) != 0) )
        {
          v111 = a2 + 2;
        }
        v271 = *((_WORD *)v111 + 2);
        v272 = v13[1];
        v273 = *(_QWORD *)(v11 + 32);
        v274 = *(unsigned int *)(v11 + 40);
        v275 = *(unsigned __int8 *)(v10 + 8);
        v476 = *v111;
        v477 = v271;
        if ( (unsigned int)ucfg_ipa_wlan_evt(v272, v273, v274, v275, 6, &v476, 0) )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: WLAN_CLIENT_CONNECT_EX event failed",
            v276,
            v277,
            v278,
            v279,
            v280,
            v281,
            v282,
            v283,
            "hdd_hostapd_sap_event_cb");
      }
      qdf_dp_trace_mgmt_pkt(5, *(_BYTE *)(v10 + 8), 0xFFu, 3, 28);
      if ( (*(_BYTE *)(v10 + 257) & 1) == 0 )
      {
        v284 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v284 )
        {
          v293 = v284;
          ucfg_dp_bus_bw_compute_prev_txrx_stats(v284, v285, v286, v287, v288, v289, v290, v291, v292);
          _hdd_objmgr_put_vdev_by_user(v293, 97, "hdd_hostapd_sap_event_cb");
        }
        ucfg_dp_bus_bw_compute_timer_start(*v13, v285, v286, v287, v288, v289, v290, v291, v292);
      }
      *(_BYTE *)(v10 + 257) = 1;
      hdd_hostapd_update_beacon_country_ie(v11);
      cds_host_diag_log_work(v13 + 36);
      qdf_wake_lock_timeout_acquire((__int64)(v13 + 36), 1000);
      v294 = (unsigned int)a2[8];
      v295 = _qdf_mem_malloc(0x108u, "hdd_hostapd_sap_event_cb", 3186);
      if ( !v295 )
        goto LABEL_14;
      *(_QWORD *)(v295 + 120) = *((_QWORD *)a2 + 3);
      *(_QWORD *)(v295 + 128) = v294;
      v296 = v295;
      hdd_hostapd_sap_fill_peer_ml_info(v10, v295, a2 + 2);
      cfg80211_new_sta(v12, a2 + 2, v296, 3264);
      _qdf_mem_free(v296);
      if ( (unsigned int)ucfg_scan_get_vdev_status(
                           *(_QWORD *)(v10 + 32),
                           v297,
                           v298,
                           v299,
                           v300,
                           v301,
                           v302,
                           v303,
                           v304) )
        wlan_abort_scan(v13[1], -1, *(unsigned __int8 *)(v10 + 8), 0xFFFFFFFF, 0);
      if ( *(_DWORD *)(v11 + 40) == 3 )
        hdd_send_peer_status_ind_to_app(
          a2 + 2,
          1,
          *((unsigned __int8 *)a2 + 41),
          *(unsigned __int8 *)(v10 + 8),
          a2 + 11);
      hdd_green_ap_add_sta(v13);
      goto LABEL_151;
    case 5:
      v204 = *((_WORD *)a2 + 6);
      *(_DWORD *)((char *)&v474 + 2) = *v36;
      HIWORD(v474) = v204;
      hdd_init_scan_reject_params(v13);
      sta_info_by_mac = hdd_get_sta_info_by_mac(v11 + 38888, a2 + 2, 17, 1);
      v470 = sta_info_by_mac;
      if ( sta_info_by_mac )
      {
        v214 = a2[7];
        *(_BYTE *)(sta_info_by_mac + 212) = v214;
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
          v206,
          v207,
          v208,
          v209,
          v210,
          v211,
          v212,
          v213,
          "hdd_hostapd_sap_event_cb",
          (unsigned int)(char)v214);
        hdd_put_sta_info_ref(v11 + 38888, &v470, 1, 17);
      }
      hdd_cp_stats_cstats_log_sap_go_sta_disassoc_event(v10, a2);
      if ( (unsigned int)qdf_event_set(v10 + 168, v215) )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Station Deauth event Set failed",
          v216,
          v217,
          v218,
          v219,
          v220,
          v221,
          v222,
          v223,
          "hdd_hostapd_sap_event_cb");
      qdf_dp_trace_mgmt_pkt(5, *(_BYTE *)(v10 + 8), 0xFFu, 3, 29);
      v224 = (unsigned __int8 *)hdd_get_sta_info_by_mac(v11 + 38848, a2 + 2, 17, 1);
      v471 = v224;
      if ( v224 )
      {
        v233 = (const char *)&unk_98C763;
        v234 = v224 + 38;
        if ( a2[6] == 65537 )
          v233 = "by user ";
        qdf_trace_msg(
          0x33u,
          4u,
          "SAP(%d) Peer %02x:%02x:%02x:**:**:%02x with mld %02x:%02x:%02x:**:**:%02x disassociated %sreason %d status code %d",
          v225,
          v226,
          v227,
          v228,
          v229,
          v230,
          v231,
          v232,
          *(unsigned __int8 *)(v10 + 8),
          v224[32],
          v224[33],
          v224[34],
          v224[37],
          v224[38],
          v224[39],
          v224[40],
          v224[43],
          v233,
          a2[5],
          a2[4]);
        if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(v10 + 32), v235, v236, v237, v238, v239, v240, v241, v242) & 1) == 0
          || (v481 = 0, v480 = 0, (qdf_is_macaddr_equal_1(v234, &v480) & 1) != 0) )
        {
          v234 = (unsigned __int8 *)(a2 + 2);
        }
        v243 = *((_WORD *)v234 + 2);
        v476 = *(_DWORD *)v234;
        v477 = v243;
        v244 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v244 )
        {
          v253 = (unsigned __int8 *)(a2 + 2);
          v254 = v244;
          ucfg_dp_update_dhcp_state_on_disassoc(v244, v253, v245, v246, v247, v248, v249, v250, v251, v252);
          _hdd_objmgr_put_vdev_by_user(v254, 97, "hdd_hostapd_sap_event_cb");
        }
        hdd_softap_deregister_sta(v11, &v471);
        hdd_put_sta_info_ref(v11 + 38848, &v471, 1, 17);
        *(_BYTE *)(v10 + 257) = 0;
        qdf_spin_lock_bh_5(v11 + 38872);
        hdd_get_front_sta_info_no_lock(v11 + 38848, &v471);
        if ( v471 )
          hdd_take_sta_info_ref(v11 + 38848, v471, 0, 17);
        hdd_get_next_sta_info_no_lock(v11 + 38848);
        if ( v469 )
          hdd_take_sta_info_ref(v11 + 38848, v469, 0, 17);
        qdf_spin_unlock_bh_3(v11 + 38872);
        v255 = v471;
        if ( v471 )
        {
          while ( 1 )
          {
            v481 = -1;
            v480 = -1;
            if ( (qdf_is_macaddr_equal_1(v255 + 32, &v480) & 1) == 0 )
              break;
            hdd_put_sta_info_ref(v11 + 38848, &v471, 1, 17);
            qdf_spin_lock_bh_5(v11 + 38872);
            v471 = v469;
            hdd_get_next_sta_info_no_lock(v11 + 38848);
            if ( v469 )
              hdd_take_sta_info_ref(v11 + 38848, v469, 0, 17);
            qdf_spin_unlock_bh_3(v11 + 38872);
            v255 = v471;
            if ( !v471 )
              goto LABEL_180;
          }
          *(_BYTE *)(v10 + 257) = 1;
          hdd_put_sta_info_ref(v11 + 38848, &v471, 1, 17);
          if ( v469 )
            hdd_put_sta_info_ref(v11 + 38848, &v469, 1, 17);
        }
LABEL_180:
        hdd_hostapd_update_beacon_country_ie(v11);
        cds_host_diag_log_work(v13 + 36);
        qdf_wake_lock_timeout_acquire((__int64)(v13 + 36), 1000);
        if ( *(_DWORD *)(v11 + 40) != 3
          || (cds_get_driver_state(v392, v393, v394, v395, v396, v397, v398, v399) & 8) == 0 )
        {
          cfg80211_del_sta_sinfo(v12, &v476, 0, 3264);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: indicate sta deletion event",
            v400,
            v401,
            v402,
            v403,
            v404,
            v405,
            v406,
            v407,
            "hdd_hostapd_sap_event_cb");
        }
        v408 = policy_mgr_change_mcc_go_beacon_interval(*v13, *(unsigned __int8 *)(v10 + 8), *(_DWORD *)(v11 + 40));
        if ( v408 )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to update Beacon interval status: %d",
            v409,
            v410,
            v411,
            v412,
            v413,
            v414,
            v415,
            v416,
            "hdd_hostapd_sap_event_cb",
            v408);
        if ( *(_DWORD *)(v11 + 40) == 3 )
          os_if_wifi_pos_send_peer_status(v36, 2, 0, *(unsigned __int8 *)(v10 + 8), 0, 3);
        if ( (*(_BYTE *)(v10 + 257) & 1) == 0 )
        {
          v417 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
          if ( v417 )
          {
            v426 = v417;
            ucfg_dp_bus_bw_compute_reset_prev_txrx_stats(v417, v418, v419, v420, v421, v422, v423, v424, v425);
            _hdd_objmgr_put_vdev_by_user(v426, 97, "hdd_hostapd_sap_event_cb");
          }
          ucfg_dp_bus_bw_compute_timer_try_stop(*v13);
        }
        hdd_green_ap_del_sta(v13);
        goto LABEL_151;
      }
      v305 = (const char *)&unk_98C763;
      if ( a2[6] == 65537 )
        v305 = "by user ";
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to find STA info for %02x:%02x:%02x:**:**:%02x %sreason %d sc %d",
        v225,
        v226,
        v227,
        v228,
        v229,
        v230,
        v231,
        v232,
        "hdd_hostapd_sap_event_cb",
        *((unsigned __int8 *)a2 + 8),
        *((unsigned __int8 *)a2 + 9),
        *((unsigned __int8 *)a2 + 10),
        *((unsigned __int8 *)a2 + 13),
        v305,
        a2[5],
        a2[4]);
      result = 4;
      break;
    case 6:
      if ( *(_BYTE *)v36 )
        v158 = "eSAP_STATUS_FAILURE";
      else
        v158 = "eSAP_STATUS_SUCCESS";
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
        v158);
      if ( !*(_BYTE *)v36 )
      {
        hdd_softap_change_sta_state(v10, (char *)a2 + 9, 3);
        wlan_hdd_send_sta_authorized_event(
          v11,
          (__int64)v13,
          (__int64)a2 + 9,
          v159,
          v160,
          v161,
          v162,
          v163,
          v164,
          v165,
          v166);
      }
      goto LABEL_154;
    case 7:
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
        *((unsigned __int8 *)a2 + 14),
        *((unsigned __int8 *)a2 + 15),
        *((unsigned __int8 *)a2 + 16),
        *((unsigned __int8 *)a2 + 19));
      v260 = *((unsigned __int8 *)a2 + 28);
      v261 = *((unsigned __int8 *)a2 + 26) ^ 1u;
      v474 = nullptr;
      v475 = 28;
      cfg80211_michael_mic_failure(v12, (char *)a2 + 14, v261, v260, (char *)a2 + 29, 3264);
      goto LABEL_151;
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
      goto LABEL_154;
    case 9:
      hdd_clear_all_sta(v11, a2);
      goto LABEL_154;
    case 10:
      result = hdd_stop_bss_link(v10);
      if ( !(_DWORD)result )
        break;
      qdf_trace_msg(
        0x33u,
        3u,
        "%s: hdd_stop_bss_link failed %d",
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        "hdd_hostapd_sap_event_cb",
        (unsigned int)result);
      goto LABEL_154;
    case 11:
      v75 = (char *)_qdf_mem_malloc(0x101u, "hdd_hostapd_sap_event_cb", 3444);
      if ( !v75 )
        goto LABEL_172;
      v76 = v75;
      snprintf(
        v75,
        0x100u,
        "JOIN_UNKNOWN_STA-%02x:%02x:%02x:**:**:%02x",
        *((unsigned __int8 *)a2 + 8),
        *((unsigned __int8 *)a2 + 9),
        *((unsigned __int8 *)a2 + 10),
        *((unsigned __int8 *)a2 + 13));
      v474 = v76;
      LOWORD(v475) = strlen(v76);
      qdf_trace_msg(0x33u, 2u, "%s: %s", v77, v78, v79, v80, v81, v82, v83, v84, "hdd_hostapd_sap_event_cb", v76);
      v85 = 0;
      v86 = nullptr;
      goto LABEL_153;
    case 12:
      v195 = (char *)_qdf_mem_malloc(0x101u, "hdd_hostapd_sap_event_cb", 3459);
      if ( !v195 )
        goto LABEL_172;
      v86 = v195;
      snprintf(
        v195,
        0x100u,
        "Peer %02x:%02x:%02x:**:**:%02x denied assoc due to Maximum Mobile Hotspot connections reached. Please disconnect"
        " one or more devices to enable the new device connection",
        *((unsigned __int8 *)a2 + 8),
        *((unsigned __int8 *)a2 + 9),
        *((unsigned __int8 *)a2 + 10),
        *((unsigned __int8 *)a2 + 13));
      v474 = v86;
      LOWORD(v475) = strlen(v86);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev %d %s",
        v196,
        v197,
        v198,
        v199,
        v200,
        v201,
        v202,
        v203,
        "hdd_hostapd_sap_event_cb",
        *(unsigned __int8 *)(v10 + 8),
        v86);
      v85 = 0;
      goto LABEL_152;
    case 13:
      if ( *(_DWORD *)(v10 + 80) )
      {
        hdd_hostapd_channel_allow_suspend(v11, *(unsigned int *)(*(_QWORD *)(v10 + 272) + 1736LL));
        hdd_hostapd_channel_prevent_suspend(v11, *v36);
        v35 = a2;
      }
      v55 = v35[2];
      *(_DWORD *)(v10 + 2424) = v55;
      *(_DWORD *)(v10 + 1988) = v55;
      *(_DWORD *)(v10 + 1992) = v35[3];
      *(_DWORD *)(v10 + 1996) = *((unsigned __int16 *)v35 + 8);
      *(_DWORD *)(v10 + 2000) = *((unsigned __int16 *)v35 + 9);
      *(_WORD *)(v10 + 1466) = *((_WORD *)v35 + 10);
      *(_DWORD *)(v10 + 720) = *(_DWORD *)a1;
      v57 = *(_QWORD *)(a1 + 1508);
      v56 = *(_QWORD *)(a1 + 1516);
      *(_QWORD *)(v10 + 728) = *(_QWORD *)(a1 + 1500);
      *(_QWORD *)(v10 + 744) = v56;
      *(_QWORD *)(v10 + 736) = v57;
      *(_DWORD *)(v10 + 724) = *(_DWORD *)(a1 + 4);
      _cds_get_context(71, (__int64)"hdd_hostapd_sap_event_cb", v26, v27, v28, v29, v30, v31, v32, v33);
      v58 = *(_QWORD *)(v10 + 272);
      if ( !v58 )
      {
LABEL_206:
        v45 = "%s: sap ctx is null";
        goto LABEL_13;
      }
      if ( *(_BYTE *)(v58 + 1644) == 1 )
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
            v59,
            v60,
            v61,
            v62,
            v63,
            v64,
            v65,
            v66,
            "hdd_hostapd_sap_event_cb");
      }
LABEL_43:
      hdd_hostapd_chan_change(v10, a2);
      goto LABEL_154;
    case 14:
      wlan_hdd_send_svc_nlink_msg(*((unsigned int *)v13 + 364), 259, &v478, 6);
      *((_BYTE *)v13 + 912) = 1;
      hdd_cp_stats_cstats_log_sap_go_dfs_event(v10, 14);
      if ( (unsigned int)hdd_send_radar_event(v10, 14, v478 | ((unsigned __int64)v479 << 32)) )
      {
        v156 = "%s: Unable to indicate CAC start NL event";
        v157 = 2;
      }
      else
      {
        v156 = "%s: Sent CAC start to user space";
        v157 = 8;
      }
      qdf_trace_msg(0x33u, v157, v156, v148, v149, v150, v151, v152, v153, v154, v155, "hdd_hostapd_sap_event_cb");
      *(_DWORD *)(v10 + 2620) = 0;
      hdd_reset_tsf_sync(v11);
      goto LABEL_151;
    case 15:
      hdd_cp_stats_cstats_log_sap_go_dfs_event(v10, 15);
      if ( (unsigned int)hdd_send_radar_event(v10, 16, v478 | ((unsigned __int64)v479 << 32)) )
      {
        v54 = "%s: Unable to indicate CAC end (interrupted) event";
        goto LABEL_117;
      }
      v54 = "%s: Sent CAC end (interrupted) to user space";
      goto LABEL_149;
    case 16:
      wlan_hdd_send_svc_nlink_msg(*((unsigned int *)v13 + 364), 260, &v478, 6);
      *(_BYTE *)(v10 + 256) = 0;
      ucfg_ipa_set_dfs_cac_tx(v13[1], 0);
      v182 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
      if ( v182 )
      {
        v191 = v182;
        ucfg_dp_set_dfs_cac_tx(v182, *(_BYTE *)(v10 + 256), v183, v184, v185, v186, v187, v188, v189, v190);
        _hdd_objmgr_put_vdev_by_user(v191, 97, "hdd_hostapd_sap_event_cb");
      }
      hdd_cp_stats_cstats_log_sap_go_dfs_event(v10, 16);
      v192 = v479;
      v193 = v478;
      *((_BYTE *)v13 + 912) = 2;
      if ( (unsigned int)hdd_send_radar_event(v10, 16, v193 | (v192 << 32)) )
      {
        v54 = "%s: Unable to indicate CAC end NL event";
        goto LABEL_117;
      }
      v54 = "%s: Sent CAC end to user space";
      goto LABEL_149;
    case 17:
      hdd_cp_stats_cstats_log_sap_go_dfs_event(v10, 17);
      hdd_dfs_indicate_radar(v13);
      wlan_hdd_send_svc_nlink_msg(*((unsigned int *)v13 + 364), 261, &v478, 6);
      *((_BYTE *)v13 + 912) = 0;
      v256 = *(_DWORD *)(v10 + 2144);
      if ( v256 )
      {
        for ( i = 0; i < v256; ++i )
        {
          v258 = *(_QWORD *)(v10 + 2136) + 20LL * (int)i;
          if ( (unsigned __int16)v478 == *(unsigned __int8 *)(v258 + 10) )
          {
            *(_DWORD *)(v258 + 4) |= 0x1000u;
            v256 = *(_DWORD *)(v10 + 2144);
          }
        }
      }
      if ( (unsigned int)hdd_send_radar_event(v10, 17, v478 | ((unsigned __int64)v479 << 32)) )
      {
        v54 = "%s: Unable to indicate Radar detect NL event";
LABEL_117:
        v259 = 2;
      }
      else
      {
        v54 = "%s: Sent radar detected to user space";
LABEL_149:
        v259 = 8;
      }
      qdf_trace_msg(0x33u, v259, v54, v46, v47, v48, v49, v50, v51, v52, v53, "hdd_hostapd_sap_event_cb");
      wlan_reg_chan_band_to_freq(v13[1], (unsigned __int8)v478, 2u, v306, v307, v308, v309, v310, v311, v312, v313);
LABEL_151:
      v85 = 0;
      v86 = nullptr;
LABEL_152:
      v76 = nullptr;
LABEL_153:
      _qdf_mem_free(v85);
      _qdf_mem_free((__int64)v76);
      _qdf_mem_free((__int64)v86);
      goto LABEL_154;
    case 18:
      wlan_hdd_send_svc_nlink_msg(*((unsigned int *)v13 + 364), 264, &v478, 6);
      goto LABEL_151;
    case 19:
      v107 = *(unsigned __int8 *)(v10 + 8);
      v108 = "%s: eSAP_STOP_BSS_DUE_TO_NO_CHNL Stop sap vdev %d";
      goto LABEL_82;
    case 20:
      break;
    case 21:
      v194 = *(unsigned __int8 *)(v10 + 8);
      *(_DWORD *)(v10 + 1988) = a2[2];
      *(_DWORD *)(v10 + 1992) = a2[3];
      *(_DWORD *)(v10 + 1996) = *((unsigned __int16 *)a2 + 8);
      *(_DWORD *)(v10 + 2000) = *((unsigned __int16 *)a2 + 9);
      *(_WORD *)(v10 + 1466) = *((_WORD *)a2 + 10);
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
        v194);
      if ( *(_DWORD *)(v10 + 2616) && (*(_QWORD *)(v10 + 5968) & 2) != 0 )
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
      goto LABEL_154;
    case 22:
      v262 = *v36;
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
        *v36);
      wlan_hdd_set_sap_csa_reason(*v13, *(unsigned __int8 *)(v10 + 8), 3);
      result = 16 * (unsigned int)((unsigned int)hdd_softap_set_channel_change(v10, v262, 0, 9, 0, 0, 0) != 0);
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
      goto LABEL_154;
    case 24:
      *(_DWORD *)(v10 + 2620) = 0;
      policy_mgr_set_chan_switch_complete_evt(*v13);
      v87 = wlan_hdd_set_roaming_state(v10, 8, 1);
      if ( (wlan_reg_is_dfs_for_freq(v13[1], *(_DWORD *)(v10 + 2424), v87, v88, v89, v90, v91, v92, v93, v94) & 1) == 0 )
      {
        *(_BYTE *)(v10 + 256) = 0;
        v95 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
        if ( v95 )
        {
          v104 = v95;
          ucfg_dp_set_dfs_cac_tx(v95, *(_BYTE *)(v10 + 256), v96, v97, v98, v99, v100, v101, v102, v103);
          _hdd_objmgr_put_vdev_by_user(v104, 97, "hdd_hostapd_sap_event_cb");
        }
      }
      if ( !policy_mgr_is_vdev_ll_lt_sap(*v13, *(unsigned __int8 *)(v10 + 8)) )
        hdd_hostapd_check_channel_post_csa(v13, v10);
      v106 = qdf_event_set(v10 + 88, v105);
      if ( v106 )
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
          v106);
      if ( !a2[6] )
        goto LABEL_43;
      v107 = *(unsigned __int8 *)(v10 + 8);
      v108 = "%s: SAP[vdev%d] channel switch fail, will stop";
LABEL_82:
      qdf_trace_msg(0x33u, 8u, v108, v26, v27, v28, v29, v30, v31, v32, v33, "hdd_hostapd_sap_event_cb", v107);
      queue_work_on(32, system_wq, v10 + 6056);
      goto LABEL_154;
    case 25:
      hdd_hostapd_chan_change_started(v10, a2[2], (_DWORD)a2 + 12);
      goto LABEL_154;
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
LABEL_163:
      v147 = 0;
LABEL_164:
      *(_DWORD *)(v10 + 80) = 0;
      v335 = _hdd_objmgr_get_vdev_by_user(v10, 97, "hdd_hostapd_sap_event_cb");
      if ( v335 )
      {
        v344 = v335;
        ucfg_dp_set_bss_state_start(v335, 0, v336, v337, v338, v339, v340, v341, v342, v343);
        _hdd_objmgr_put_vdev_by_user(v344, 97, "hdd_hostapd_sap_event_cb");
      }
      hdd_reset_tsf_sync(v11);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: vdev %d Disabling queues",
        v345,
        v346,
        v347,
        v348,
        v349,
        v350,
        v351,
        v352,
        "hdd_hostapd_sap_event_cb",
        *(unsigned __int8 *)(*(_QWORD *)(v11 + 52832) + 8LL));
      wlan_hdd_netif_queue_control(v11, 4, 1);
      v353 = hdd_softap_stop_bss(v10);
      if ( v353 )
      {
        v362 = qdf_trace_msg(
                 0x33u,
                 8u,
                 "%s: hdd_softap_stop_bss failed %d",
                 v354,
                 v355,
                 v356,
                 v357,
                 v358,
                 v359,
                 v360,
                 v361,
                 "hdd_hostapd_sap_event_cb",
                 v353);
        if ( (ucfg_ipa_is_enabled(v362) & 1) != 0 )
        {
          ucfg_ipa_uc_disconnect_ap(v13[1], *(_QWORD *)(v11 + 32));
          ucfg_ipa_cleanup_dev_iface(v13[1], *(_QWORD *)(v11 + 32), *(unsigned __int8 *)(v10 + 8));
        }
      }
      v363 = (void *)_qdf_mem_malloc(0x40u, "hdd_hostapd_sap_event_cb", 3739);
      if ( v363 )
      {
        v364 = (__int64)v363;
        qmemcpy(v363, "STOP-BSS.response", 17);
        v474 = nullptr;
        v475 = 17;
        _qdf_mem_free(v147);
        _qdf_mem_free(0);
        _qdf_mem_free(0);
        _qdf_mem_free(v364);
        if ( v14 == 1 )
        {
          qdf_event_set(v10 + 128, v365);
          ucfg_dp_bus_bw_compute_timer_try_stop(*v13);
        }
LABEL_154:
        result = 0;
      }
      else
      {
LABEL_172:
        result = 2;
      }
      break;
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
