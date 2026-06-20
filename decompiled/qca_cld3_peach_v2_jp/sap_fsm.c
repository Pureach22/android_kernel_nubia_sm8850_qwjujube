__int64 __fastcall sap_fsm(
        unsigned int *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v12; // w22
  unsigned int v13; // w23
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  __int64 result; // x0
  int v25; // w22
  __int64 v26; // x21
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w22
  unsigned int v37; // w8
  __int64 v38; // x23
  unsigned int v39; // w9
  unsigned int v40; // w0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  char v49; // w8
  const char *v50; // x2
  const char *v51; // x3
  int v52; // w5
  __int64 v53; // x4
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // x0
  __int64 v63; // x1
  unsigned int v64; // w2
  _QWORD *v65; // x0
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  int v74; // w22
  unsigned int *sap_ch_sw_info; // x0
  __int64 v76; // x4
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x4
  __int64 v94; // x4
  const char *v95; // x2
  const char *v96; // x3
  __int64 v97; // x4
  const char *v98; // x2
  const char *v99; // x3
  unsigned int *v100; // x21
  __int64 v101; // x26
  unsigned int *v102; // x28
  unsigned int v103; // w24
  double v104; // d0
  double v105; // d1
  double v106; // d2
  double v107; // d3
  double v108; // d4
  double v109; // d5
  double v110; // d6
  double v111; // d7
  __int64 v112; // x0
  __int64 active_channel; // x0
  double v114; // d0
  double v115; // d1
  double v116; // d2
  double v117; // d3
  double v118; // d4
  double v119; // d5
  double v120; // d6
  double v121; // d7
  unsigned int *v122; // x0
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  int v131; // w0
  const char *v132; // x2
  const char *v133; // x2
  unsigned int v134; // w27
  unsigned int v135; // w28
  unsigned int channel_state_for_pwrmode; // w0
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  __int64 v145; // x4
  __int64 v146; // x5
  __int64 v147; // x6
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  unsigned int v156; // w21
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  unsigned int v173; // w22
  char v174; // w0
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  unsigned int v183; // w23
  unsigned int v184; // w8
  __int64 v185; // x0
  char is_dfs_for_freq; // w24
  const char *v187; // x2
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  _BOOL4 v204; // w23
  __int64 v205; // x4
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  unsigned int *v214; // x0
  __int64 v215; // x4
  double v216; // d0
  double v217; // d1
  double v218; // d2
  double v219; // d3
  double v220; // d4
  double v221; // d5
  double v222; // d6
  double v223; // d7
  double v224; // d0
  double v225; // d1
  double v226; // d2
  double v227; // d3
  double v228; // d4
  double v229; // d5
  double v230; // d6
  double v231; // d7
  __int64 v232; // x4
  double v233; // d0
  double v234; // d1
  double v235; // d2
  double v236; // d3
  double v237; // d4
  double v238; // d5
  double v239; // d6
  double v240; // d7
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  __int64 v249; // x4
  const char *v250; // x2
  unsigned int v251; // w1
  unsigned int v252; // w0
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  __int64 v261; // x4
  unsigned int v262; // w19
  unsigned int v263; // w0
  double v264; // d0
  double v265; // d1
  double v266; // d2
  double v267; // d3
  double v268; // d4
  double v269; // d5
  double v270; // d6
  double v271; // d7
  __int64 v272; // x0
  unsigned int v273; // w22
  __int64 v274; // x0
  __int64 v275; // x24
  int curr_6g_power_type; // w23
  unsigned int *v277; // x8
  double v278; // d0
  double v279; // d1
  double v280; // d2
  double v281; // d3
  double v282; // d4
  double v283; // d5
  double v284; // d6
  double v285; // d7
  double v286; // d0
  double v287; // d1
  double v288; // d2
  double v289; // d3
  double v290; // d4
  double v291; // d5
  double v292; // d6
  double v293; // d7
  unsigned int v294; // w22
  __int64 v295; // x0
  __int64 v296; // x1
  double v297; // d0
  int v298; // w23
  double v299; // d1
  double v300; // d2
  double v301; // d3
  double v302; // d4
  double v303; // d5
  double v304; // d6
  double v305; // d7
  unsigned int v306; // w0
  double v307; // d0
  double v308; // d1
  double v309; // d2
  double v310; // d3
  double v311; // d4
  double v312; // d5
  double v313; // d6
  double v314; // d7
  unsigned int v315; // w22
  double v316; // d0
  double v317; // d1
  double v318; // d2
  double v319; // d3
  double v320; // d4
  double v321; // d5
  double v322; // d6
  double v323; // d7
  double v324; // d0
  double v325; // d1
  double v326; // d2
  double v327; // d3
  double v328; // d4
  double v329; // d5
  double v330; // d6
  double v331; // d7
  unsigned int v332; // w1
  double v333; // d0
  double v334; // d1
  double v335; // d2
  double v336; // d3
  double v337; // d4
  double v338; // d5
  double v339; // d6
  double v340; // d7
  unsigned int v341; // w24
  int *v342; // x22
  unsigned int v343; // w23
  double v344; // d0
  double v345; // d1
  double v346; // d2
  double v347; // d3
  double v348; // d4
  double v349; // d5
  double v350; // d6
  double v351; // d7
  unsigned int v352; // w9
  int v353; // w8
  unsigned int v354; // w8
  int v355; // w9
  int v356; // w10
  unsigned int v357; // w8
  __int64 v358; // x4
  double v359; // d0
  double v360; // d1
  double v361; // d2
  double v362; // d3
  double v363; // d4
  double v364; // d5
  double v365; // d6
  double v366; // d7
  __int16 v367; // w8
  size_t v368; // x2
  char v369; // w9
  char v370; // w10
  unsigned int v371; // w8
  unsigned int v372; // w9
  char v373; // w10
  size_t v374; // x2
  char v375; // w9
  size_t v376; // x2
  __int64 v377; // x0
  _QWORD *v378; // x0
  unsigned int v379; // w20
  double v380; // d0
  double v381; // d1
  double v382; // d2
  double v383; // d3
  double v384; // d4
  double v385; // d5
  double v386; // d6
  double v387; // d7
  unsigned int v388; // w8
  const char *v389; // x2
  unsigned int v390; // w8
  unsigned int v391; // w1
  double v392; // d0
  double v393; // d1
  double v394; // d2
  double v395; // d3
  double v396; // d4
  double v397; // d5
  double v398; // d6
  double v399; // d7
  __int64 v400; // x4
  double v401; // d0
  double v402; // d1
  double v403; // d2
  double v404; // d3
  double v405; // d4
  double v406; // d5
  double v407; // d6
  double v408; // d7
  __int64 v409; // x0
  double v410; // d0
  double v411; // d1
  double v412; // d2
  double v413; // d3
  double v414; // d4
  double v415; // d5
  double v416; // d6
  double v417; // d7
  double v418; // d0
  double v419; // d1
  double v420; // d2
  double v421; // d3
  double v422; // d4
  double v423; // d5
  double v424; // d6
  double v425; // d7
  double v426; // d0
  double v427; // d1
  double v428; // d2
  double v429; // d3
  double v430; // d4
  double v431; // d5
  double v432; // d6
  double v433; // d7
  _QWORD *v434; // x21
  unsigned int v435; // [xsp+Ch] [xbp-84h] BYREF
  unsigned int v436; // [xsp+10h] [xbp-80h] BYREF
  _BYTE v437[4]; // [xsp+14h] [xbp-7Ch] BYREF
  int v438; // [xsp+18h] [xbp-78h] BYREF
  _BYTE v439[4]; // [xsp+1Ch] [xbp-74h] BYREF
  _QWORD v440[4]; // [xsp+20h] [xbp-70h] BYREF
  __int64 v441; // [xsp+40h] [xbp-50h]
  __int64 v442; // [xsp+48h] [xbp-48h]
  __int128 v443; // [xsp+50h] [xbp-40h] BYREF
  __int64 v444; // [xsp+60h] [xbp-30h]
  __int64 v445; // [xsp+68h] [xbp-28h] BYREF
  _QWORD v446[2]; // [xsp+70h] [xbp-20h] BYREF
  int v447; // [xsp+80h] [xbp-10h]
  __int64 v448; // [xsp+88h] [xbp-8h]

  v448 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = a1[182];
  v13 = *(_DWORD *)(a2 + 8);
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( !context )
  {
    v50 = "%s: Invalid MAC context";
    v51 = "sap_fsm";
    goto LABEL_16;
  }
  v23 = (__int64)context;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: vdev %d: state %d event %d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "sap_fsm",
    *((unsigned __int8 *)a1 + 12),
    (unsigned int)v12,
    v13);
  result = 16;
  if ( v12 > 1 )
  {
    if ( v12 != 2 )
    {
      if ( v12 != 3 )
        goto LABEL_72;
      v52 = *(_DWORD *)(a2 + 8);
      if ( v52 == 11 )
      {
        v97 = *((unsigned __int8 *)a1 + 12);
        v98 = "%s: vdev %d SAP already in Stopping state";
        v99 = "sap_fsm_state_stopping";
        goto LABEL_39;
      }
      if ( v52 == 6 )
      {
        v53 = *((unsigned __int8 *)a1 + 12);
        a1[182] = 0;
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: sap_fsm: vdev %d: SAP_STOPPING => SAP_INIT",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "sap_fsm_state_stopping",
          v53);
        v62 = (__int64)a1;
        v63 = 0;
        v64 = 1;
LABEL_22:
        result = sap_signal_hdd_event(v62, v63, v64, nullptr, v54, v55, v56, v57, v58, v59, v60, v61);
        goto LABEL_72;
      }
      v94 = *((unsigned __int8 *)a1 + 12);
      v95 = "%s: sap_fsm: vdev %d: SAP_STOPPING, invalid event %d";
      v96 = "sap_fsm_state_stopping";
      goto LABEL_70;
    }
    v74 = *(_DWORD *)(a2 + 8);
    sap_ch_sw_info = (unsigned int *)wlan_get_sap_ch_sw_info(
                                       *((_QWORD *)a1 + 2),
                                       v15,
                                       v16,
                                       v17,
                                       v18,
                                       v19,
                                       v20,
                                       v21,
                                       v22);
    if ( !sap_ch_sw_info )
    {
      v50 = "%s: Invalid channel info";
      v51 = "sap_fsm_state_started";
      goto LABEL_16;
    }
    if ( v74 != 16 )
    {
      if ( v74 == 11 )
      {
        v76 = *((unsigned __int8 *)a1 + 12);
        a1[182] = 3;
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: sap_fsm: vdev %d: SAP_STARTED => SAP_STOPPING",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "sap_fsm_state_started",
          v76);
        wlan_dnw_handle_bss_stop(*(_QWORD *)(v23 + 21560), *((unsigned __int8 *)a1 + 12));
LABEL_35:
        result = sap_goto_stopping(a1);
        goto LABEL_72;
      }
      v94 = *((unsigned __int8 *)a1 + 12);
      v95 = "%s: sap_fsm: vdev %d: SAP_STARTED, invalid event %d";
      v96 = "sap_fsm_state_started";
      goto LABEL_70;
    }
    v100 = sap_ch_sw_info;
    if ( !*sap_ch_sw_info )
    {
      qdf_trace_msg(
        0x39u,
        2u,
        "%s: Invalid target channel freq %d",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "sap_fsm_state_started",
        0);
      goto LABEL_71;
    }
    result = 16;
    v101 = -96;
    while ( 1 )
    {
      if ( (*(_DWORD *)(v23 + v101 + 14920) | 2) != 3 )
        goto LABEL_50;
      v102 = *(unsigned int **)(v23 + v101 + 14912);
      if ( !v102 )
        goto LABEL_50;
      v103 = result;
      if ( (wlan_is_dnw_in_progress(*(_QWORD *)(v23 + 21560), *((unsigned __int8 *)v102 + 12)) & 1) != 0 )
        break;
      v112 = *((_QWORD *)v102 + 2);
      if ( !v112 )
      {
        v133 = "%s: vdev invalid";
LABEL_63:
        qdf_trace_msg(0x39u, 8u, v133, v104, v105, v106, v107, v108, v109, v110, v111, "sap_operating_on_dfs");
LABEL_64:
        v134 = *((unsigned __int8 *)v102 + 12);
        v135 = *v102;
        channel_state_for_pwrmode = wlan_reg_get_channel_state_for_pwrmode(
                                      *(_QWORD *)(v23 + 21560),
                                      v135,
                                      0,
                                      v104,
                                      v105,
                                      v106,
                                      v107,
                                      v108,
                                      v109,
                                      v110,
                                      v111);
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: vdev %d freq %d (state %d) is not DFS or disabled so continue",
          v137,
          v138,
          v139,
          v140,
          v141,
          v142,
          v143,
          v144,
          "sap_fsm_state_started",
          v134,
          v135,
          channel_state_for_pwrmode);
LABEL_49:
        result = v103;
        goto LABEL_50;
      }
      active_channel = wlan_vdev_get_active_channel(v112);
      if ( !active_channel )
      {
        v133 = "%s: Couldn't get vdev active channel";
        goto LABEL_63;
      }
      if ( (*(_WORD *)(active_channel + 6) & 6) == 0 )
        goto LABEL_64;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: vdev %d switch freq %d -> %d",
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        v111,
        "sap_fsm_state_started",
        *((unsigned __int8 *)v102 + 12),
        *v102,
        *v100);
      v122 = (unsigned int *)wlan_get_sap_ch_sw_info(
                               *((_QWORD *)v102 + 2),
                               v114,
                               v115,
                               v116,
                               v117,
                               v118,
                               v119,
                               v120,
                               v121);
      if ( v122 )
      {
        v131 = policy_mgr_check_and_set_hw_mode_for_channel_switch(
                 *(_QWORD *)(v23 + 21552),
                 *((_BYTE *)v102 + 12),
                 *v122,
                 8u);
        if ( !v131 )
        {
          qdf_trace_msg(
            0x39u,
            4u,
            "%s: Channel change will continue after HW mode change",
            v123,
            v124,
            v125,
            v126,
            v127,
            v128,
            v129,
            v130,
            "sap_fsm_send_csa_restart_req");
          result = 0;
          goto LABEL_50;
        }
        if ( v131 != 16 )
        {
          result = sme_csa_restart(v23, *((unsigned __int8 *)v102 + 12));
          goto LABEL_50;
        }
        v132 = "%s: HW change required but failed to set hw mode";
      }
      else
      {
        v132 = "%s: Invalid channel info";
      }
      qdf_trace_msg(0x39u, 2u, v132, v123, v124, v125, v126, v127, v128, v129, v130, "sap_fsm_send_csa_restart_req");
      result = 16;
LABEL_50:
      v101 += 16;
      if ( !v101 )
        goto LABEL_72;
    }
    wlan_dnw_handle_radar_found(*(_QWORD *)(v23 + 21560), *((unsigned __int8 *)v102 + 12));
    goto LABEL_49;
  }
  if ( !v12 )
  {
    if ( *(_DWORD *)(a2 + 8) == 5 )
    {
      if ( a1 )
      {
        v65 = _cds_get_context(53, (__int64)"sap_get_mac_context", v15, v16, v17, v18, v19, v20, v21, v22);
        if ( v65 )
        {
          utils_dfs_init_nol(v65[2695]);
          goto LABEL_111;
        }
        v187 = "%s: Invalid MAC context";
      }
      else
      {
        v187 = "%s: Invalid SAP context";
      }
      qdf_trace_msg(0x39u, 2u, v187, v15, v16, v17, v18, v19, v20, v21, v22, "sap_init_dfs_channel_nol_list");
LABEL_111:
      v252 = sap_validate_chan(a1, 0, 1, v66, v67, v68, v69, v70, v71, v72, v73);
      if ( v252 )
      {
        v261 = *((unsigned __int8 *)a1 + 12);
        v262 = v252;
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: vdev %d: channel is not valid!",
          v253,
          v254,
          v255,
          v256,
          v257,
          v258,
          v259,
          v260,
          "sap_fsm_state_init",
          v261);
        result = v262;
        goto LABEL_72;
      }
      v447 = 0;
      v263 = *a1;
      v446[0] = 0;
      v446[1] = 0;
      v444 = 0;
      v445 = 0;
      v443 = 0u;
      v435 = 0;
      v436 = 0;
      v441 = 0;
      v442 = 0;
      memset(v440, 0, sizeof(v440));
      if ( wlan_reg_is_6ghz_chan_freq(v263) )
      {
        if ( !policy_mgr_get_ap_6ghz_capable(*(_QWORD *)(v23 + 21552), *((unsigned __int8 *)a1 + 12), nullptr) )
        {
          v379 = 16;
          goto LABEL_190;
        }
        v272 = *(_QWORD *)(v23 + 21552);
        v273 = *a1;
        v437[0] = 0;
        if ( v272 )
        {
          if ( *(_QWORD *)(v23 + 21560) )
          {
            v439[0] = 0;
            v438 = 0;
            if ( (policy_mgr_is_sta_present_on_freq(v272, v439, v273, &v438) & 1) != 0 )
            {
              v274 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                       *(_QWORD *)(v23 + 21552),
                       v439[0],
                       44);
              if ( v274 )
              {
                v275 = v274;
                curr_6g_power_type = wlan_mlme_get_curr_6g_power_type(
                                       v274,
                                       v264,
                                       v265,
                                       v266,
                                       v267,
                                       v268,
                                       v269,
                                       v270,
                                       v271);
                wlan_objmgr_vdev_release_ref(v275, 0x2Cu, v277, v278, v279, v280, v281, v282, v283, v284, v285);
                if ( curr_6g_power_type != 2 )
                {
                  ucfg_mlme_get_indoor_channel_support(*(_QWORD *)(v23 + 21552), v437);
                  if ( curr_6g_power_type || v437[0] != 1 )
                  {
                    if ( (wlan_reg_get_channel_state_for_pwrmode(
                            *(_QWORD *)(v23 + 21560),
                            v273,
                            3u,
                            v286,
                            v287,
                            v288,
                            v289,
                            v290,
                            v291,
                            v292,
                            v293)
                        & 3) != 0 )
                      wlan_set_tpc_update_required_for_sta(
                        *((_QWORD *)a1 + 2),
                        1,
                        v264,
                        v265,
                        v266,
                        v267,
                        v268,
                        v269,
                        v270,
                        v271);
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x39u,
                      8u,
                      "%s: STA is connected to Indoor AP and indoor concurrency is supported",
                      v286,
                      v287,
                      v288,
                      v289,
                      v290,
                      v291,
                      v292,
                      v293,
                      "wlansap_is_power_change_required");
                  }
                }
              }
            }
          }
        }
      }
      else
      {
        v294 = *a1;
        v295 = *(_QWORD *)(v23 + 21560);
        v296 = a1[375];
        LOWORD(v438) = *a1;
        v297 = utils_dfs_mark_leaking_chan_for_freq(v295, v296, 1, &v438);
        v298 = (unsigned __int16)v438;
        if ( sap_dfs_is_channel_in_nol_list((__int64)a1, *a1, 11, v297, v299, v300, v301, v302, v303, v304, v305)
          || v298 != (unsigned __int16)v294 )
        {
          v306 = sap_random_channel_sel(a1);
          if ( !v306 )
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: No available channel found!!!",
              v307,
              v308,
              v309,
              v310,
              v311,
              v312,
              v313,
              v314,
              "sap_validate_dfs_nol");
            sap_signal_hdd_event((__int64)a1, 0, 0x12u, nullptr, v392, v393, v394, v395, v396, v397, v398, v399);
            v379 = 5;
            goto LABEL_190;
          }
          v315 = v306;
          qdf_trace_msg(
            0x39u,
            8u,
            "%s: ch_freq %d is in NOL, start bss on new freq %d",
            v307,
            v308,
            v309,
            v310,
            v311,
            v312,
            v313,
            v314,
            "sap_validate_dfs_nol",
            *a1,
            v306);
          *a1 = v315;
          wlan_reg_set_channel_params_for_pwrmode(
            *(_QWORD *)(v23 + 21560),
            v315,
            a1[1],
            (__int64)(a1 + 375),
            0,
            v316,
            v317,
            v318,
            v319,
            v320,
            v321,
            v322,
            v323);
        }
      }
      if ( (policy_mgr_is_sap_override_dfs_required(
              *(_QWORD *)(v23 + 21560),
              *a1,
              *((unsigned __int16 *)a1 + 749),
              0,
              0,
              v264,
              v265,
              v266,
              v267,
              v268,
              v269,
              v270,
              v271,
              0,
              &v435,
              &v436)
          & 1) != 0 )
      {
        v332 = v436;
        *a1 = v436;
        wlan_reg_set_channel_params_for_pwrmode(
          *(_QWORD *)(v23 + 21560),
          v332,
          0,
          (__int64)(a1 + 375),
          0,
          v324,
          v325,
          v326,
          v327,
          v328,
          v329,
          v330,
          v331);
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: override to DFS channel %d vdev id %d",
          v333,
          v334,
          v335,
          v336,
          v337,
          v338,
          v339,
          v340,
          "sap_goto_starting",
          v436,
          v435);
      }
      v341 = a1[375];
      v342 = (int *)(a1 + 375);
      v343 = a1[371];
      if ( !wlan_reg_is_5ghz_ch_freq(*a1) || (v352 = a1[371], v353 = 2, v352 != 8) && v352 != 32 )
      {
        if ( !wlan_reg_is_24ghz_ch_freq(*a1) || a1[371] != 2 )
        {
LABEL_140:
          v354 = *v342;
          if ( !*v342 )
            goto LABEL_149;
          v355 = a1[371];
          if ( (unsigned int)(v355 - 1) < 8 && ((0x8Bu >> (v355 - 1)) & 1) != 0 )
          {
            v356 = 0;
          }
          else
          {
            if ( v354 == 1 )
              goto LABEL_149;
            if ( v355 != 16 )
            {
              if ( v354 >= 5 )
              {
                v356 = 3;
                if ( v355 > 2047 )
                {
                  if ( v355 == 2048 || v355 == 4096 )
                    goto LABEL_148;
                }
                else if ( v355 == 256 || v355 == 512 )
                {
                  goto LABEL_148;
                }
              }
LABEL_149:
              if ( v341 == v354 )
              {
                v357 = a1[371];
              }
              else
              {
                wlan_reg_set_channel_params_for_pwrmode(
                  *(_QWORD *)(v23 + 21560),
                  *a1,
                  *((unsigned __int8 *)a1 + 1504),
                  (__int64)(a1 + 375),
                  0,
                  v344,
                  v345,
                  v346,
                  v347,
                  v348,
                  v349,
                  v350,
                  v351);
                v357 = a1[371];
                if ( v341 != a1[375] )
                {
LABEL_153:
                  qdf_trace_msg(
                    0x39u,
                    4u,
                    "%s: Freq %d Updated BW %d -> %d , phymode %d -> %d",
                    v344,
                    v345,
                    v346,
                    v347,
                    v348,
                    v349,
                    v350,
                    v351,
                    "sap_validate_chanmode_and_chwidth",
                    *a1,
                    v341,
                    v357);
                  v343 = a1[371];
                  v341 = a1[375];
LABEL_154:
                  v358 = *((unsigned __int8 *)a1 + 12);
                  a1[182] = 1;
                  qdf_trace_msg(
                    0x39u,
                    8u,
                    "%s: sap_fsm: vdev %d: SAP_INIT => SAP_STARTING, phyMode %d bw %d",
                    v344,
                    v345,
                    v346,
                    v347,
                    v348,
                    v349,
                    v350,
                    v351,
                    "sap_goto_starting",
                    v358,
                    v343,
                    v341);
                  ((void (__fastcall *)(unsigned int *, unsigned int *, unsigned int *, _QWORD, unsigned int *))sap_get_cac_dur_dfs_region)(
                    a1,
                    a1 + 111,
                    a1 + 112,
                    *a1,
                    a1 + 375);
                  if ( !(unsigned int)wlan_dnw_set_info(
                                        *(_QWORD *)(v23 + 21560),
                                        *((unsigned __int8 *)a1 + 12),
                                        *a1,
                                        a1[375],
                                        a1[111],
                                        *(_BYTE *)(v23 + 14808) != 0,
                                        sap_dnw_request_handler,
                                        a1) )
                  {
                    a1[111] = 0;
                    qdf_trace_msg(
                      0x39u,
                      8u,
                      "%s: Start SAP with DFS No Wait",
                      v359,
                      v360,
                      v361,
                      v362,
                      v363,
                      v364,
                      v365,
                      v366,
                      "sap_goto_starting");
                  }
                  mlme_set_cac_required(
                    *((_QWORD *)a1 + 2),
                    a1[111] != 0,
                    v359,
                    v360,
                    v361,
                    v362,
                    v363,
                    v364,
                    v365,
                    v366);
                  v367 = *(_WORD *)((char *)a1 + 1505);
                  v368 = *((unsigned __int8 *)a1 + 416);
                  *((_BYTE *)a1 + 404) = a1[375];
                  v369 = *((_BYTE *)a1 + 12);
                  *(_WORD *)((char *)a1 + 405) = v367;
                  v370 = *((_BYTE *)a1 + 1504);
                  v371 = *a1;
                  LOBYTE(v443) = v369;
                  v372 = a1[371];
                  *((_BYTE *)a1 + 407) = v370;
                  v373 = *((_BYTE *)a1 + 81);
                  a1[100] = v371;
                  *(_QWORD *)((char *)&v443 + 4) = __PAIR64__(v371, v372);
                  BYTE1(v443) = v373;
                  qdf_mem_copy((char *)&v445 + 1, (char *)a1 + 417, v368);
                  v374 = *((unsigned __int8 *)a1 + 429);
                  LOBYTE(v445) = *((_BYTE *)a1 + 416);
                  qdf_mem_copy((char *)v446 + 6, (char *)a1 + 430, v374);
                  BYTE5(v446[0]) = *((_BYTE *)a1 + 429);
                  sme_get_network_params(v23, &v443);
                  v375 = BYTE12(v443);
                  v376 = (unsigned __int8)v445;
                  a1[103] = v444;
                  *((_BYTE *)a1 + 409) = v375;
                  if ( (_DWORD)v376 )
                  {
                    qdf_mem_copy((char *)a1 + 417, (char *)&v445 + 1, v376);
                    *((_BYTE *)a1 + 416) = v445;
                  }
                  else
                  {
                    qdf_mem_set(a1 + 104, 0xDu, 0);
                  }
                  if ( BYTE5(v446[0]) )
                  {
                    qdf_mem_copy((char *)a1 + 430, (char *)v446 + 6, BYTE5(v446[0]));
                    *((_BYTE *)a1 + 429) = BYTE5(v446[0]);
                  }
                  else
                  {
                    qdf_mem_set((char *)a1 + 429, 0xDu, 0);
                  }
                  if ( *((_BYTE *)a1 + 1752) != 1 )
                    goto LABEL_186;
                  v388 = *((unsigned __int8 *)a1 + 429);
                  if ( v388 > 0xB )
                  {
                    v390 = *((unsigned __int8 *)a1 + 416);
                    if ( v390 > 0xB )
                    {
                      v389 = "%s: rates full, can not add H2E bss membership";
                      v391 = 2;
                      goto LABEL_185;
                    }
                    *((_BYTE *)a1 + *((unsigned __int8 *)a1 + 416) + 417) = -5;
                    *((_BYTE *)a1 + 416) = v390 + 1;
                    v389 = "%s: H2E bss membership add to support rate";
                  }
                  else
                  {
                    *((_BYTE *)a1 + *((unsigned __int8 *)a1 + 429) + 430) = -5;
                    v389 = "%s: H2E bss membership add to ext support rate";
                    *((_BYTE *)a1 + 429) = v388 + 1;
                  }
                  v391 = 8;
LABEL_185:
                  qdf_trace_msg(0x39u, v391, v389, v380, v381, v382, v383, v384, v385, v386, v387, "sap_goto_starting");
LABEL_186:
                  sap_dfs_set_current_channel(a1, v380, v381, v382, v383, v384, v385, v386, v387);
                  v400 = *((unsigned __int8 *)a1 + 12);
                  *((_BYTE *)a1 + 13) = 0;
                  qdf_trace_msg(
                    0x39u,
                    8u,
                    "%s: session: %d",
                    v401,
                    v402,
                    v403,
                    v404,
                    v405,
                    v406,
                    v407,
                    v408,
                    "sap_goto_starting",
                    v400);
                  v409 = *((_QWORD *)a1 + 2);
                  LODWORD(v441) = *a1;
                  if ( (unsigned int)if_mgr_deliver_event(
                                       v409,
                                       0x18u,
                                       (__int64)v440,
                                       v410,
                                       v411,
                                       v412,
                                       v413,
                                       v414,
                                       v415,
                                       v416,
                                       v417) )
                    qdf_trace_msg(
                      0x39u,
                      2u,
                      "%s: Failed to inform IF_MGR for channel selection",
                      v418,
                      v419,
                      v420,
                      v421,
                      v422,
                      v423,
                      v424,
                      v425,
                      "sap_goto_starting");
                  result = sme_start_bss(v23, *((unsigned __int8 *)a1 + 12), a1 + 8);
                  if ( !(_DWORD)result )
                    goto LABEL_72;
                  v379 = result;
                  qdf_trace_msg(
                    0x39u,
                    2u,
                    "%s: Failed to issue sme_roam_connect",
                    v426,
                    v427,
                    v428,
                    v429,
                    v430,
                    v431,
                    v432,
                    v433,
                    "sap_goto_starting");
LABEL_190:
                  qdf_trace_msg(
                    0x39u,
                    2u,
                    "%s: vdev %d: sap_goto_starting failed",
                    v264,
                    v265,
                    v266,
                    v267,
                    v268,
                    v269,
                    v270,
                    v271,
                    "sap_fsm_state_init",
                    *((unsigned __int8 *)a1 + 12));
                  result = v379;
                  goto LABEL_72;
                }
              }
              if ( v343 == v357 )
                goto LABEL_154;
              goto LABEL_153;
            }
            v356 = 1;
          }
LABEL_148:
          v354 = v356;
          *v342 = v356;
          goto LABEL_149;
        }
        v353 = 8;
      }
      a1[371] = v353;
      goto LABEL_140;
    }
    v94 = *((unsigned __int8 *)a1 + 12);
    v95 = "%s: sap_fsm: vdev %d: SAP_INIT, invalid event %d";
    v96 = "sap_fsm_state_init";
LABEL_70:
    qdf_trace_msg(0x39u, 2u, v95, v15, v16, v17, v18, v19, v20, v21, v22, v96, v94);
    goto LABEL_71;
  }
  if ( v12 != 1 )
    goto LABEL_72;
  v25 = *(_DWORD *)(a2 + 8);
  v26 = *(_QWORD *)a2;
  LOBYTE(v440[0]) = 0;
  LOBYTE(v438) = 0;
  if ( v25 != 7 )
  {
    if ( (v25 & 0xFFFFFFFE) == 0xA )
    {
      wlan_dnw_handle_bss_stop(*(_QWORD *)(v23 + 21560), *((unsigned __int8 *)a1 + 12));
      if ( v25 != 11 )
      {
        v205 = *((unsigned __int8 *)a1 + 12);
        a1[182] = 0;
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: sap_fsm: vdev %d: SAP_STARTING => SAP_INIT",
          v77,
          v78,
          v79,
          v80,
          v81,
          v82,
          v83,
          v84,
          "sap_fsm_handle_start_failure",
          v205);
        sap_signal_hdd_event((__int64)a1, 0, 0, (char *)&off_0 + 1, v206, v207, v208, v209, v210, v211, v212, v213);
        *((_QWORD *)&v443 + 1) = 6;
        v444 = 0;
        *(_QWORD *)&v443 = 0;
        result = sap_fsm(a1, &v443);
        goto LABEL_72;
      }
      if ( !sap_find_valid_concurrent_session(v23) )
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: sapdfs: no sessions are valid, stopping timer",
          v85,
          v86,
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          "sap_fsm_handle_start_failure");
        if ( a1 )
        {
          v378 = _cds_get_context(53, (__int64)"sap_get_mac_context", v85, v86, v87, v88, v89, v90, v91, v92);
          if ( v378 )
          {
            if ( *((_BYTE *)a1 + 1627) == 1 )
            {
              *((_BYTE *)v378 + 14809) = 0;
            }
            else
            {
              v434 = v378;
              if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(v378 + 1830)) == 21 )
              {
                qdf_mc_timer_stop((__int64)(v434 + 1830));
                *((_BYTE *)v434 + 14809) = 0;
                qdf_mc_timer_destroy((__int64)(v434 + 1830));
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: Invalid MAC context",
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              v91,
              v92,
              "sap_stop_dfs_cac_timer");
          }
        }
      }
      v93 = *((unsigned __int8 *)a1 + 12);
      a1[182] = 3;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sap_fsm: vdev %d: SAP_STARTING => SAP_STOPPING, start is in progress",
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        v91,
        v92,
        "sap_fsm_handle_start_failure",
        v93);
      goto LABEL_35;
    }
    if ( v25 <= 14 )
    {
      if ( v25 == 13 )
      {
        if ( *((_BYTE *)a1 + 1628) == 1 )
        {
          sap_signal_hdd_event((__int64)a1, 0, 0xDu, nullptr, v15, v16, v17, v18, v19, v20, v21, v22);
          *((_BYTE *)a1 + 1628) = 0;
        }
        goto LABEL_161;
      }
      if ( v25 == 14 )
      {
        if ( (wlan_is_dnw_in_progress(*(_QWORD *)(v23 + 21560), *((unsigned __int8 *)a1 + 12)) & 1) != 0 )
          result = wlan_dnw_handle_radar_found(*(_QWORD *)(v23 + 21560), *((unsigned __int8 *)a1 + 12));
        else
          result = sap_fsm_handle_radar_during_cac(a1, v23);
        goto LABEL_72;
      }
      goto LABEL_158;
    }
    if ( v25 != 15 )
    {
      if ( v25 != 17 )
      {
LABEL_158:
        v94 = *((unsigned __int8 *)a1 + 12);
        v95 = "%s: sap_fsm: vdev %d: SAP_STARTING, invalid event %d";
        v96 = "sap_fsm_state_starting";
        goto LABEL_70;
      }
      v214 = (unsigned int *)wlan_get_sap_ch_sw_info(*((_QWORD *)a1 + 2), v15, v16, v17, v18, v19, v20, v21, v22);
      if ( v214 )
      {
        v215 = *((unsigned __int8 *)a1 + 12);
        *a1 = *v214;
        a1[182] = 2;
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: sap_fsm: vdev %d: SAP_STARTING => SAP_STARTED",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "sap_fsm_state_starting",
          v215);
        v62 = (__int64)a1;
        v63 = v26;
        v64 = 0;
        goto LABEL_22;
      }
      v50 = "%s: Invalid channel info";
      v51 = "sap_fsm_state_starting";
LABEL_16:
      qdf_trace_msg(0x39u, 2u, v50, v15, v16, v17, v18, v19, v20, v21, v22, v51);
LABEL_71:
      result = 16;
      goto LABEL_72;
    }
    v377 = *((_QWORD *)a1 + 2);
    if ( v377 && (unsigned int)wlan_util_vdev_mgr_get_cac_timeout_for_vdev(v377) )
    {
      result = sap_cac_end_notify(v23, v26, v15, v16, v17, v18, v19, v20, v21, v22);
      goto LABEL_72;
    }
    v97 = *((unsigned __int8 *)a1 + 12);
    v98 = "%s: vdev %d cac duration is zero";
    v99 = "sap_fsm_state_starting";
LABEL_39:
    qdf_trace_msg(0x39u, 8u, v98, v15, v16, v17, v18, v19, v20, v21, v22, v99, v97);
    result = 0;
    goto LABEL_72;
  }
  v27 = wlan_vdev_get_active_channel(*((_QWORD *)a1 + 2));
  if ( v27 )
  {
    v36 = a1[375];
    v37 = *(_DWORD *)(v27 + 24);
    if ( v36 != v37 )
    {
      a1[375] = v37;
      v38 = v27;
      *((_BYTE *)a1 + 1505) = *(_BYTE *)(v27 + 3);
      *((_BYTE *)a1 + 1506) = *(_BYTE *)(v27 + 4);
      a1[377] = *(_DWORD *)(v27 + 16);
      v39 = *(_DWORD *)(v27 + 20);
      v40 = *a1;
      a1[378] = v39;
      if ( wlan_reg_is_24ghz_ch_freq(v40) && *(_DWORD *)(v38 + 24) == 1 )
      {
        if ( *a1 < *(unsigned __int8 *)(v38 + 3) )
          v49 = 1;
        else
          v49 = 3;
        *((_BYTE *)a1 + 1504) = v49;
      }
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: updated BW %d -> %d",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "sap_check_and_update_vdev_ch_params",
        v36,
        a1[375]);
    }
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: Couldn't get vdev active channel",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "sap_check_and_update_vdev_ch_params");
  }
  v145 = *((unsigned __int8 *)a1 + 12);
  v146 = *a1;
  v147 = a1[375];
  a1[182] = 2;
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: sap_fsm: vdev %d: SAP_STARTING => SAP_STARTED, freq %d ch_width %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "sap_fsm_state_starting",
    v145,
    v146,
    v147);
  if ( *((_BYTE *)a1 + 1628) == 1 )
  {
    v156 = sap_signal_hdd_event((__int64)a1, v26, 0xDu, nullptr, v148, v149, v150, v151, v152, v153, v154, v155);
    *((_BYTE *)a1 + 1628) = 0;
  }
  else
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: vdev %d notify hostapd about chan freq selection: %d",
      v148,
      v149,
      v150,
      v151,
      v152,
      v153,
      v154,
      v155,
      "sap_fsm_state_starting",
      *((unsigned __int8 *)a1 + 12),
      *a1);
    sap_signal_hdd_event((__int64)a1, v26, 0xDu, nullptr, v157, v158, v159, v160, v161, v162, v163, v164);
    v156 = sap_signal_hdd_event((__int64)a1, v26, 0, nullptr, v165, v166, v167, v168, v169, v170, v171, v172);
  }
  wlan_dnw_handle_bss_start(*(_QWORD *)(v23 + 21560), *((unsigned __int8 *)a1 + 12), 1);
  v173 = *a1;
  v174 = wlan_reg_freq_to_band(*a1);
  if ( *((_BYTE *)a1 + 1506) )
    v183 = wlan_reg_chan_band_to_freq(
             *(_QWORD *)(v23 + 21560),
             *((unsigned __int8 *)a1 + 1506),
             1LL << v174,
             v175,
             v176,
             v177,
             v178,
             v179,
             v180,
             v181,
             v182);
  else
    v183 = 0;
  v184 = a1[375];
  if ( v184 == 4 )
  {
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                         *(_QWORD *)(v23 + 21560),
                         v173,
                         0,
                         v175,
                         v176,
                         v177,
                         v178,
                         v179,
                         v180,
                         v181,
                         v182) == 2
      || (is_dfs_for_freq = 0,
          (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                          *(_QWORD *)(v23 + 21560),
                          v183,
                          0,
                          v188,
                          v189,
                          v190,
                          v191,
                          v192,
                          v193,
                          v194,
                          v195) == 2) )
    {
      is_dfs_for_freq = 1;
    }
  }
  else if ( v184 == 3 )
  {
    v185 = *(_QWORD *)(v23 + 21560);
    v443 = 3u;
    is_dfs_for_freq = (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                      v185,
                                      v173,
                                      (unsigned int *)&v443,
                                      0,
                                      v175,
                                      v176,
                                      v177,
                                      v178,
                                      v179,
                                      v180,
                                      v181,
                                      v182) == 2;
  }
  else
  {
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(
                        *(_QWORD *)(v23 + 21560),
                        v173,
                        v175,
                        v176,
                        v177,
                        v178,
                        v179,
                        v180,
                        v181,
                        v182);
  }
  v204 = 0;
  if ( !wlan_reg_is_6ghz_chan_freq(*a1) && (is_dfs_for_freq & 1) != 0 )
  {
    if ( wlan_p2p_is_vdev_wfd_r2_mode(*((_QWORD *)a1 + 2)) )
    {
      wlan_p2p_get_ap_assist_dfs_params(*((_QWORD *)a1 + 2), &v438, v440, nullptr, 0, nullptr, nullptr);
      v204 = 1;
      if ( (v438 & 1) == 0 )
        v204 = (v440[0] & 1) == 0;
    }
    else
    {
      v204 = 1;
    }
  }
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: vdev %d freq %d, is_dfs %d is_dfs_owner %d is_valid_ap_assist %d",
    v196,
    v197,
    v198,
    v199,
    v200,
    v201,
    v202,
    v203,
    "sap_fsm_state_starting",
    *((unsigned __int8 *)a1 + 12),
    *a1,
    v204,
    (unsigned __int8)v438,
    LOBYTE(v440[0]));
  if ( v204 )
  {
    if ( (sap_plus_sap_cac_skip(v23, (__int64)a1, v173, v216, v217, v218, v219, v220, v221, v222, v223) & 1) == 0
      && !*(_BYTE *)(v23 + 14808)
      && (wlan_pre_cac_complete_get(*((_QWORD *)a1 + 2)) & 1) == 0
      && (wlan_is_dnw_in_progress(*(_QWORD *)(v23 + 21560), *((unsigned __int8 *)a1 + 12)) & 1) == 0
      && (policy_mgr_get_dfs_master_dynamic_enabled(*(_QWORD *)(v23 + 21552)) & 1) != 0 )
    {
      v232 = *((unsigned __int8 *)a1 + 12);
      a1[182] = 1;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sap_fsm: vdev %d: SAP_STARTED => SAP_STARTING to start cac timer",
        v224,
        v225,
        v226,
        v227,
        v228,
        v229,
        v230,
        v231,
        "sap_fsm_state_starting",
        v232);
LABEL_161:
      result = sap_fsm_cac_start(a1, v23, v23);
      goto LABEL_72;
    }
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: vdev %d skip cac timer",
      v224,
      v225,
      v226,
      v227,
      v228,
      v229,
      v230,
      v231,
      "sap_fsm_state_starting",
      *((unsigned __int8 *)a1 + 12));
    *((_BYTE *)a1 + 13) = 0;
    if ( (unsigned int)sap_signal_hdd_event(
                         (__int64)a1,
                         0,
                         0xEu,
                         nullptr,
                         v233,
                         v234,
                         v235,
                         v236,
                         v237,
                         v238,
                         v239,
                         v240) )
    {
      v249 = *((unsigned __int8 *)a1 + 12);
      v250 = "%s: Failed to indicate CAC START vdev %d";
      v251 = 2;
    }
    else
    {
      if ( !(unsigned int)sap_signal_hdd_event(
                            (__int64)a1,
                            0,
                            0x10u,
                            nullptr,
                            v241,
                            v242,
                            v243,
                            v244,
                            v245,
                            v246,
                            v247,
                            v248) )
      {
LABEL_126:
        wlansap_start_beacon_req(a1);
        result = v156;
        goto LABEL_72;
      }
      v249 = *((unsigned __int8 *)a1 + 12);
      v250 = "%s: Failed to indicate CAC End vdev %d";
      v251 = 8;
    }
    qdf_trace_msg(0x39u, v251, v250, v241, v242, v243, v244, v245, v246, v247, v248, "sap_propagate_cac_events", v249);
    goto LABEL_126;
  }
  result = v156;
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
