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
  double v186; // d0
  double v187; // d1
  double v188; // d2
  double v189; // d3
  double v190; // d4
  double v191; // d5
  double v192; // d6
  double v193; // d7
  char is_dfs_for_freq; // w24
  const char *v195; // x2
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  _BOOL4 v212; // w23
  __int64 v213; // x4
  double v214; // d0
  double v215; // d1
  double v216; // d2
  double v217; // d3
  double v218; // d4
  double v219; // d5
  double v220; // d6
  double v221; // d7
  unsigned int *v222; // x0
  __int64 v223; // x4
  double v224; // d0
  double v225; // d1
  double v226; // d2
  double v227; // d3
  double v228; // d4
  double v229; // d5
  double v230; // d6
  double v231; // d7
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  __int64 v240; // x4
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  double v249; // d0
  double v250; // d1
  double v251; // d2
  double v252; // d3
  double v253; // d4
  double v254; // d5
  double v255; // d6
  double v256; // d7
  __int64 v257; // x4
  const char *v258; // x2
  unsigned int v259; // w1
  unsigned int v260; // w0
  double v261; // d0
  double v262; // d1
  double v263; // d2
  double v264; // d3
  double v265; // d4
  double v266; // d5
  double v267; // d6
  double v268; // d7
  __int64 v269; // x4
  unsigned int v270; // w19
  unsigned int v271; // w0
  double v272; // d0
  double v273; // d1
  double v274; // d2
  double v275; // d3
  double v276; // d4
  double v277; // d5
  double v278; // d6
  double v279; // d7
  __int64 v280; // x0
  unsigned int v281; // w22
  __int64 v282; // x0
  double v283; // d0
  double v284; // d1
  double v285; // d2
  double v286; // d3
  double v287; // d4
  double v288; // d5
  double v289; // d6
  double v290; // d7
  __int64 v291; // x24
  int curr_6g_power_type; // w23
  unsigned int *v293; // x8
  double v294; // d0
  double v295; // d1
  double v296; // d2
  double v297; // d3
  double v298; // d4
  double v299; // d5
  double v300; // d6
  double v301; // d7
  double v302; // d0
  double v303; // d1
  double v304; // d2
  double v305; // d3
  double v306; // d4
  double v307; // d5
  double v308; // d6
  double v309; // d7
  __int64 v310; // x0
  __int64 v311; // x1
  unsigned int v312; // w22
  int v313; // w23
  double v314; // d0
  double v315; // d1
  double v316; // d2
  double v317; // d3
  double v318; // d4
  double v319; // d5
  double v320; // d6
  double v321; // d7
  char v322; // w0
  unsigned int channel_state_from_secondary_list_for_freq; // w0
  double v324; // d0
  double v325; // d1
  double v326; // d2
  double v327; // d3
  double v328; // d4
  double v329; // d5
  double v330; // d6
  double v331; // d7
  __int64 v332; // x24
  __int64 v333; // x0
  _QWORD *v334; // x0
  unsigned int v335; // w20
  unsigned int v336; // w0
  double v337; // d0
  double v338; // d1
  double v339; // d2
  double v340; // d3
  double v341; // d4
  double v342; // d5
  double v343; // d6
  double v344; // d7
  unsigned int v345; // w22
  __int64 v346; // x0
  double v347; // d0
  double v348; // d1
  double v349; // d2
  double v350; // d3
  double v351; // d4
  double v352; // d5
  double v353; // d6
  double v354; // d7
  char v355; // w0
  __int64 v356; // x22
  unsigned int v357; // w23
  int v358; // w24
  double v359; // d0
  char v360; // w0
  double v361; // d1
  double v362; // d2
  double v363; // d3
  double v364; // d4
  double v365; // d5
  double v366; // d6
  double v367; // d7
  __int64 v368; // x0
  double v369; // d0
  double v370; // d1
  double v371; // d2
  double v372; // d3
  double v373; // d4
  double v374; // d5
  double v375; // d6
  double v376; // d7
  char v377; // w0
  double v378; // d0
  double v379; // d1
  double v380; // d2
  double v381; // d3
  double v382; // d4
  double v383; // d5
  double v384; // d6
  double v385; // d7
  unsigned int v386; // w24
  int *v387; // x22
  unsigned int v388; // w23
  double v389; // d0
  double v390; // d1
  double v391; // d2
  double v392; // d3
  double v393; // d4
  double v394; // d5
  double v395; // d6
  double v396; // d7
  unsigned int v397; // w9
  int v398; // w8
  unsigned int v399; // w8
  int v400; // w9
  int v401; // w10
  unsigned int v402; // w8
  __int64 v403; // x4
  double v404; // d0
  double v405; // d1
  double v406; // d2
  double v407; // d3
  double v408; // d4
  double v409; // d5
  double v410; // d6
  double v411; // d7
  __int16 v412; // w8
  size_t v413; // x2
  char v414; // w9
  char v415; // w10
  unsigned int v416; // w8
  unsigned int v417; // w9
  char v418; // w10
  size_t v419; // x2
  char v420; // w9
  size_t v421; // x2
  double v422; // d0
  double v423; // d1
  double v424; // d2
  double v425; // d3
  double v426; // d4
  double v427; // d5
  double v428; // d6
  double v429; // d7
  unsigned int v430; // w8
  const char *v431; // x2
  unsigned int v432; // w8
  unsigned int v433; // w1
  double v434; // d0
  double v435; // d1
  double v436; // d2
  double v437; // d3
  double v438; // d4
  double v439; // d5
  double v440; // d6
  double v441; // d7
  __int64 v442; // x4
  double v443; // d0
  double v444; // d1
  double v445; // d2
  double v446; // d3
  double v447; // d4
  double v448; // d5
  double v449; // d6
  double v450; // d7
  __int64 v451; // x0
  double v452; // d0
  double v453; // d1
  double v454; // d2
  double v455; // d3
  double v456; // d4
  double v457; // d5
  double v458; // d6
  double v459; // d7
  double v460; // d0
  double v461; // d1
  double v462; // d2
  double v463; // d3
  double v464; // d4
  double v465; // d5
  double v466; // d6
  double v467; // d7
  double v468; // d0
  double v469; // d1
  double v470; // d2
  double v471; // d3
  double v472; // d4
  double v473; // d5
  double v474; // d6
  double v475; // d7
  _QWORD *v476; // x21
  double v477; // d0
  double v478; // d1
  double v479; // d2
  double v480; // d3
  double v481; // d4
  double v482; // d5
  double v483; // d6
  double v484; // d7
  unsigned int v485; // [xsp+14h] [xbp-8Ch] BYREF
  unsigned int v486; // [xsp+18h] [xbp-88h] BYREF
  char v487[4]; // [xsp+1Ch] [xbp-84h] BYREF
  int v488; // [xsp+20h] [xbp-80h] BYREF
  char v489[4]; // [xsp+24h] [xbp-7Ch] BYREF
  __int64 v490; // [xsp+28h] [xbp-78h] BYREF
  __int64 v491; // [xsp+30h] [xbp-70h]
  __int64 v492; // [xsp+38h] [xbp-68h]
  __int64 v493; // [xsp+40h] [xbp-60h]
  __int64 v494; // [xsp+48h] [xbp-58h]
  __int64 v495; // [xsp+50h] [xbp-50h]
  __int64 v496; // [xsp+58h] [xbp-48h]
  __int64 v497; // [xsp+60h] [xbp-40h] BYREF
  __int64 v498; // [xsp+68h] [xbp-38h]
  __int64 v499; // [xsp+70h] [xbp-30h]
  __int64 v500; // [xsp+78h] [xbp-28h] BYREF
  _QWORD v501[2]; // [xsp+80h] [xbp-20h] BYREF
  int v502; // [xsp+90h] [xbp-10h]
  __int64 v503; // [xsp+98h] [xbp-8h]

  v503 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
        wlan_dnw_handle_bss_stop(*(_QWORD *)(v23 + 21632), *((unsigned __int8 *)a1 + 12));
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
      if ( (*(_DWORD *)(v23 + v101 + 14992) | 2) != 3 )
        goto LABEL_50;
      v102 = *(unsigned int **)(v23 + v101 + 14984);
      if ( !v102 )
        goto LABEL_50;
      v103 = result;
      if ( (wlan_is_dnw_in_progress(*(_QWORD *)(v23 + 21632), *((unsigned __int8 *)v102 + 12)) & 1) != 0 )
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
                                      *(_QWORD *)(v23 + 21632),
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
                 *(_QWORD *)(v23 + 21624),
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
    wlan_dnw_handle_radar_found(*(_QWORD *)(v23 + 21632), *((unsigned __int8 *)v102 + 12));
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
          utils_dfs_init_nol(v65[2704]);
          goto LABEL_111;
        }
        v195 = "%s: Invalid MAC context";
      }
      else
      {
        v195 = "%s: Invalid SAP context";
      }
      qdf_trace_msg(0x39u, 2u, v195, v15, v16, v17, v18, v19, v20, v21, v22, "sap_init_dfs_channel_nol_list");
LABEL_111:
      v260 = sap_validate_chan(a1, 0, 1, v66, v67, v68, v69, v70, v71, v72, v73);
      if ( v260 )
      {
        v269 = *((unsigned __int8 *)a1 + 12);
        v270 = v260;
        qdf_trace_msg(
          0x39u,
          2u,
          "%s: vdev %d: channel is not valid!",
          v261,
          v262,
          v263,
          v264,
          v265,
          v266,
          v267,
          v268,
          "sap_fsm_state_init",
          v269);
        result = v270;
        goto LABEL_72;
      }
      v502 = 0;
      v271 = *a1;
      v501[0] = 0;
      v501[1] = 0;
      v499 = 0;
      v500 = 0;
      v497 = 0;
      v498 = 0;
      v485 = 0;
      v486 = 0;
      v495 = 0;
      v496 = 0;
      v493 = 0;
      v494 = 0;
      v491 = 0;
      v492 = 0;
      v490 = 0;
      if ( wlan_reg_is_6ghz_chan_freq(v271) )
      {
        if ( !policy_mgr_get_ap_6ghz_capable(*(_QWORD *)(v23 + 21624), *((unsigned __int8 *)a1 + 12), nullptr) )
        {
          v335 = 16;
          goto LABEL_198;
        }
        v280 = *(_QWORD *)(v23 + 21624);
        v281 = *a1;
        v487[0] = 0;
        if ( v280 )
        {
          if ( *(_QWORD *)(v23 + 21632) )
          {
            v489[0] = 0;
            v488 = 0;
            if ( (policy_mgr_is_sta_present_on_freq(v280, v489, v281, &v488) & 1) != 0 )
            {
              v282 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                       *(_QWORD *)(v23 + 21624),
                       (unsigned __int8)v489[0],
                       44);
              if ( v282 )
              {
                v291 = v282;
                curr_6g_power_type = wlan_mlme_get_curr_6g_power_type(
                                       v282,
                                       v283,
                                       v284,
                                       v285,
                                       v286,
                                       v287,
                                       v288,
                                       v289,
                                       v290);
                wlan_objmgr_vdev_release_ref(v291, 0x2Cu, v293, v294, v295, v296, v297, v298, v299, v300, v301);
                if ( curr_6g_power_type != 2 )
                {
                  ucfg_mlme_get_indoor_channel_support(*(_QWORD *)(v23 + 21624), v487);
                  if ( curr_6g_power_type || v487[0] != 1 )
                  {
                    if ( (wlan_reg_get_channel_state_for_pwrmode(
                            *(_QWORD *)(v23 + 21632),
                            v281,
                            3u,
                            v302,
                            v303,
                            v304,
                            v305,
                            v306,
                            v307,
                            v308,
                            v309)
                        & 3) != 0 )
                      wlan_set_tpc_update_required_for_sta(
                        *((_QWORD *)a1 + 2),
                        1,
                        v477,
                        v478,
                        v479,
                        v480,
                        v481,
                        v482,
                        v483,
                        v484);
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x39u,
                      8u,
                      "%s: STA is connected to Indoor AP and indoor concurrency is supported",
                      v302,
                      v303,
                      v304,
                      v305,
                      v306,
                      v307,
                      v308,
                      v309,
                      "wlansap_is_power_change_required");
                  }
                }
              }
            }
          }
        }
LABEL_150:
        v356 = *(_QWORD *)(v23 + 21632);
        v357 = *a1;
        v358 = *((unsigned __int16 *)a1 + 749);
        v359 = sap_phymode_is_eht(a1[371]);
        if ( (policy_mgr_is_sap_override_dfs_required(
                v356,
                v357,
                v358,
                0,
                0,
                v360 & 1,
                &v485,
                &v486,
                v359,
                v361,
                v362,
                v363,
                v364,
                v365,
                v366,
                v367)
            & 1) != 0 )
        {
          v368 = a1[371];
          *a1 = v486;
          v369 = sap_phymode_is_eht(v368);
          if ( (v377 & 1) != 0 )
            wlan_reg_set_create_punc_bitmap((__int64)(a1 + 375), 1);
          wlan_reg_set_channel_params_for_pwrmode(
            *(_QWORD *)(v23 + 21632),
            v486,
            0,
            (__int64)(a1 + 375),
            0,
            v369,
            v370,
            v371,
            v372,
            v373,
            v374,
            v375,
            v376);
          qdf_trace_msg(
            0x39u,
            8u,
            "%s: override to DFS channel %d vdev id %d",
            v378,
            v379,
            v380,
            v381,
            v382,
            v383,
            v384,
            v385,
            "sap_goto_starting",
            v486,
            v485);
        }
        v386 = a1[375];
        v387 = (int *)(a1 + 375);
        v388 = a1[371];
        if ( !wlan_reg_is_5ghz_ch_freq(*a1) || (v397 = a1[371], v398 = 2, v397 != 8) && v397 != 32 )
        {
          if ( !wlan_reg_is_24ghz_ch_freq(*a1) || a1[371] != 2 )
          {
LABEL_161:
            v399 = *v387;
            if ( !*v387 )
              goto LABEL_169;
            v400 = a1[371];
            if ( (unsigned int)(v400 - 1) < 8 && ((0x8Bu >> (v400 - 1)) & 1) != 0 )
            {
              v401 = 0;
            }
            else
            {
              if ( v399 == 1 )
                goto LABEL_169;
              if ( v400 != 16 )
              {
                if ( v399 >= 5 )
                {
                  v401 = 3;
                  if ( v400 > 2047 )
                  {
                    if ( v400 == 2048 || v400 == 4096 )
                      goto LABEL_168;
                  }
                  else if ( v400 == 256 || v400 == 512 )
                  {
                    goto LABEL_168;
                  }
                }
LABEL_169:
                if ( v386 == v399 )
                {
                  v402 = a1[371];
                }
                else
                {
                  wlan_reg_set_channel_params_for_pwrmode(
                    *(_QWORD *)(v23 + 21632),
                    *a1,
                    *((unsigned __int8 *)a1 + 1504),
                    (__int64)(a1 + 375),
                    0,
                    v389,
                    v390,
                    v391,
                    v392,
                    v393,
                    v394,
                    v395,
                    v396);
                  v402 = a1[371];
                  if ( v386 != a1[375] )
                  {
LABEL_173:
                    qdf_trace_msg(
                      0x39u,
                      4u,
                      "%s: Freq %d Updated BW %d -> %d , phymode %d -> %d",
                      v389,
                      v390,
                      v391,
                      v392,
                      v393,
                      v394,
                      v395,
                      v396,
                      "sap_validate_chanmode_and_chwidth",
                      *a1,
                      v386,
                      v402);
                    v388 = a1[371];
                    v386 = a1[375];
LABEL_174:
                    v403 = *((unsigned __int8 *)a1 + 12);
                    a1[182] = 1;
                    qdf_trace_msg(
                      0x39u,
                      8u,
                      "%s: sap_fsm: vdev %d: SAP_INIT => SAP_STARTING, phyMode %d bw %d",
                      v389,
                      v390,
                      v391,
                      v392,
                      v393,
                      v394,
                      v395,
                      v396,
                      "sap_goto_starting",
                      v403,
                      v388,
                      v386);
                    ((void (__fastcall *)(unsigned int *, unsigned int *, unsigned int *, _QWORD, unsigned int *))sap_get_cac_dur_dfs_region)(
                      a1,
                      a1 + 111,
                      a1 + 112,
                      *a1,
                      a1 + 375);
                    if ( !(unsigned int)wlan_dnw_set_info(
                                          *(_QWORD *)(v23 + 21632),
                                          *((unsigned __int8 *)a1 + 12),
                                          *a1,
                                          a1[375],
                                          a1[111],
                                          *(_BYTE *)(v23 + 14880) != 0,
                                          sap_dnw_request_handler,
                                          a1) )
                    {
                      a1[111] = 0;
                      qdf_trace_msg(
                        0x39u,
                        8u,
                        "%s: Start SAP with DFS No Wait",
                        v404,
                        v405,
                        v406,
                        v407,
                        v408,
                        v409,
                        v410,
                        v411,
                        "sap_goto_starting");
                    }
                    mlme_set_cac_required(
                      *((_QWORD *)a1 + 2),
                      a1[111] != 0,
                      v404,
                      v405,
                      v406,
                      v407,
                      v408,
                      v409,
                      v410,
                      v411);
                    v412 = *(_WORD *)((char *)a1 + 1505);
                    v413 = *((unsigned __int8 *)a1 + 416);
                    *((_BYTE *)a1 + 404) = a1[375];
                    v414 = *((_BYTE *)a1 + 12);
                    *(_WORD *)((char *)a1 + 405) = v412;
                    v415 = *((_BYTE *)a1 + 1504);
                    v416 = *a1;
                    LOBYTE(v497) = v414;
                    v417 = a1[371];
                    *((_BYTE *)a1 + 407) = v415;
                    v418 = *((_BYTE *)a1 + 81);
                    a1[100] = v416;
                    HIDWORD(v497) = v417;
                    LODWORD(v498) = v416;
                    BYTE1(v497) = v418;
                    qdf_mem_copy((char *)&v500 + 1, (char *)a1 + 417, v413);
                    v419 = *((unsigned __int8 *)a1 + 429);
                    LOBYTE(v500) = *((_BYTE *)a1 + 416);
                    qdf_mem_copy((char *)v501 + 6, (char *)a1 + 430, v419);
                    BYTE5(v501[0]) = *((_BYTE *)a1 + 429);
                    sme_get_network_params(v23, &v497);
                    v420 = BYTE4(v498);
                    v421 = (unsigned __int8)v500;
                    a1[103] = v499;
                    *((_BYTE *)a1 + 409) = v420;
                    if ( (_DWORD)v421 )
                    {
                      qdf_mem_copy((char *)a1 + 417, (char *)&v500 + 1, v421);
                      *((_BYTE *)a1 + 416) = v500;
                    }
                    else
                    {
                      qdf_mem_set(a1 + 104, 0xDu, 0);
                    }
                    if ( BYTE5(v501[0]) )
                    {
                      qdf_mem_copy((char *)a1 + 430, (char *)v501 + 6, BYTE5(v501[0]));
                      *((_BYTE *)a1 + 429) = BYTE5(v501[0]);
                    }
                    else
                    {
                      qdf_mem_set((char *)a1 + 429, 0xDu, 0);
                    }
                    if ( *((_BYTE *)a1 + 1776) != 1 )
                      goto LABEL_194;
                    v430 = *((unsigned __int8 *)a1 + 429);
                    if ( v430 > 0xB )
                    {
                      v432 = *((unsigned __int8 *)a1 + 416);
                      if ( v432 > 0xB )
                      {
                        v431 = "%s: rates full, can not add H2E bss membership";
                        v433 = 2;
                        goto LABEL_193;
                      }
                      *((_BYTE *)a1 + *((unsigned __int8 *)a1 + 416) + 417) = -5;
                      *((_BYTE *)a1 + 416) = v432 + 1;
                      v431 = "%s: H2E bss membership add to support rate";
                    }
                    else
                    {
                      *((_BYTE *)a1 + *((unsigned __int8 *)a1 + 429) + 430) = -5;
                      v431 = "%s: H2E bss membership add to ext support rate";
                      *((_BYTE *)a1 + 429) = v430 + 1;
                    }
                    v433 = 8;
LABEL_193:
                    qdf_trace_msg(
                      0x39u,
                      v433,
                      v431,
                      v422,
                      v423,
                      v424,
                      v425,
                      v426,
                      v427,
                      v428,
                      v429,
                      "sap_goto_starting");
LABEL_194:
                    sap_dfs_set_current_channel(a1, v422, v423, v424, v425, v426, v427, v428, v429);
                    v442 = *((unsigned __int8 *)a1 + 12);
                    *((_BYTE *)a1 + 13) = 0;
                    qdf_trace_msg(
                      0x39u,
                      8u,
                      "%s: session: %d",
                      v443,
                      v444,
                      v445,
                      v446,
                      v447,
                      v448,
                      v449,
                      v450,
                      "sap_goto_starting",
                      v442);
                    v451 = *((_QWORD *)a1 + 2);
                    LODWORD(v495) = *a1;
                    if ( (unsigned int)if_mgr_deliver_event(
                                         v451,
                                         0x18u,
                                         (__int64)&v490,
                                         v452,
                                         v453,
                                         v454,
                                         v455,
                                         v456,
                                         v457,
                                         v458,
                                         v459) )
                      qdf_trace_msg(
                        0x39u,
                        2u,
                        "%s: Failed to inform IF_MGR for channel selection",
                        v460,
                        v461,
                        v462,
                        v463,
                        v464,
                        v465,
                        v466,
                        v467,
                        "sap_goto_starting");
                    result = sme_start_bss(v23, *((unsigned __int8 *)a1 + 12), a1 + 8);
                    if ( !(_DWORD)result )
                      goto LABEL_72;
                    v335 = result;
                    qdf_trace_msg(
                      0x39u,
                      2u,
                      "%s: Failed to issue sme_roam_connect",
                      v468,
                      v469,
                      v470,
                      v471,
                      v472,
                      v473,
                      v474,
                      v475,
                      "sap_goto_starting");
LABEL_198:
                    qdf_trace_msg(
                      0x39u,
                      2u,
                      "%s: vdev %d: sap_goto_starting failed",
                      v272,
                      v273,
                      v274,
                      v275,
                      v276,
                      v277,
                      v278,
                      v279,
                      "sap_fsm_state_init",
                      *((unsigned __int8 *)a1 + 12));
                    result = v335;
                    goto LABEL_72;
                  }
                }
                if ( v388 == v402 )
                  goto LABEL_174;
                goto LABEL_173;
              }
              v401 = 1;
            }
LABEL_168:
            v399 = v401;
            *v387 = v401;
            goto LABEL_169;
          }
          v398 = 8;
        }
        a1[371] = v398;
        goto LABEL_161;
      }
      v310 = *(_QWORD *)(v23 + 21632);
      v311 = a1[375];
      v312 = (unsigned __int16)*a1;
      LOWORD(v488) = *a1;
      utils_dfs_mark_leaking_chan_for_freq(v310, v311, 1, &v488);
      v313 = (unsigned __int16)v488;
      v314 = sap_phymode_is_eht(a1[371]);
      if ( (v322 & 1) != 0 )
      {
        channel_state_from_secondary_list_for_freq = wlan_reg_get_channel_state_from_secondary_list_for_freq(
                                                       *(_QWORD *)(v23 + 21632),
                                                       v312,
                                                       v314,
                                                       v315,
                                                       v316,
                                                       v317,
                                                       v318,
                                                       v319,
                                                       v320,
                                                       v321);
        if ( channel_state_from_secondary_list_for_freq - 4 <= 0xFFFFFFFD )
        {
          v332 = jiffies;
          if ( sap_validate_dfs_nol___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x39u,
              2u,
              "%s: Invalid sap freq = %d, ch state=%d",
              v324,
              v325,
              v326,
              v327,
              v328,
              v329,
              v330,
              v331,
              "sap_validate_dfs_nol",
              v312,
              channel_state_from_secondary_list_for_freq);
            sap_validate_dfs_nol___last_ticks = v332;
          }
          goto LABEL_146;
        }
      }
      else if ( sap_dfs_is_channel_in_nol_list((__int64)a1, *a1, 11, v314, v315, v316, v317, v318, v319, v320, v321) )
      {
LABEL_146:
        v336 = sap_random_channel_sel(a1);
        if ( !v336 )
        {
          qdf_trace_msg(
            0x39u,
            2u,
            "%s: No available channel found!!!",
            v337,
            v338,
            v339,
            v340,
            v341,
            v342,
            v343,
            v344,
            "sap_validate_dfs_nol");
          sap_signal_hdd_event((__int64)a1, 0, 0x12u, nullptr, v434, v435, v436, v437, v438, v439, v440, v441);
          v335 = 5;
          goto LABEL_198;
        }
        v345 = v336;
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: ch_freq %d is in NOL, start bss on new freq %d",
          v337,
          v338,
          v339,
          v340,
          v341,
          v342,
          v343,
          v344,
          "sap_validate_dfs_nol",
          *a1,
          v336);
        v346 = a1[371];
        *a1 = v345;
        v347 = sap_phymode_is_eht(v346);
        if ( (v355 & 1) != 0 )
          wlan_reg_set_create_punc_bitmap((__int64)(a1 + 375), 1);
        wlan_reg_set_channel_params_for_pwrmode(
          *(_QWORD *)(v23 + 21632),
          *a1,
          a1[1],
          (__int64)(a1 + 375),
          0,
          v347,
          v348,
          v349,
          v350,
          v351,
          v352,
          v353,
          v354);
        goto LABEL_150;
      }
      if ( v313 == v312 )
        goto LABEL_150;
      goto LABEL_146;
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
  LOBYTE(v497) = 0;
  LOBYTE(v488) = 0;
  if ( v25 != 7 )
  {
    if ( (v25 & 0xFFFFFFFE) == 0xA )
    {
      wlan_dnw_handle_bss_stop(*(_QWORD *)(v23 + 21632), *((unsigned __int8 *)a1 + 12));
      if ( v25 != 11 )
      {
        v213 = *((unsigned __int8 *)a1 + 12);
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
          v213);
        sap_signal_hdd_event((__int64)a1, 0, 0, (char *)&off_0 + 1, v214, v215, v216, v217, v218, v219, v220, v221);
        v491 = 6;
        v492 = 0;
        v490 = 0;
        result = sap_fsm(a1, &v490);
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
          v334 = _cds_get_context(53, (__int64)"sap_get_mac_context", v85, v86, v87, v88, v89, v90, v91, v92);
          if ( v334 )
          {
            if ( *((_BYTE *)a1 + 1643) == 1 )
            {
              *((_BYTE *)v334 + 14881) = 0;
            }
            else
            {
              v476 = v334;
              if ( (unsigned int)qdf_mc_timer_get_current_state((__int64)(v334 + 1839)) == 21 )
              {
                qdf_mc_timer_stop((__int64)(v476 + 1839));
                *((_BYTE *)v476 + 14881) = 0;
                qdf_mc_timer_destroy((__int64)(v476 + 1839));
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
        if ( *((_BYTE *)a1 + 1644) == 1 )
        {
          sap_signal_hdd_event((__int64)a1, 0, 0xDu, nullptr, v15, v16, v17, v18, v19, v20, v21, v22);
          *((_BYTE *)a1 + 1644) = 0;
        }
        goto LABEL_135;
      }
      if ( v25 == 14 )
      {
        if ( (wlan_is_dnw_in_progress(*(_QWORD *)(v23 + 21632), *((unsigned __int8 *)a1 + 12)) & 1) != 0 )
          result = wlan_dnw_handle_radar_found(*(_QWORD *)(v23 + 21632), *((unsigned __int8 *)a1 + 12));
        else
          result = sap_fsm_handle_radar_during_cac(a1, v23);
        goto LABEL_72;
      }
      goto LABEL_132;
    }
    if ( v25 != 15 )
    {
      if ( v25 != 17 )
      {
LABEL_132:
        v94 = *((unsigned __int8 *)a1 + 12);
        v95 = "%s: sap_fsm: vdev %d: SAP_STARTING, invalid event %d";
        v96 = "sap_fsm_state_starting";
        goto LABEL_70;
      }
      v222 = (unsigned int *)wlan_get_sap_ch_sw_info(*((_QWORD *)a1 + 2), v15, v16, v17, v18, v19, v20, v21, v22);
      if ( v222 )
      {
        v223 = *((unsigned __int8 *)a1 + 12);
        *a1 = *v222;
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
          v223);
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
    v333 = *((_QWORD *)a1 + 2);
    if ( v333 && (unsigned int)wlan_util_vdev_mgr_get_cac_timeout_for_vdev(v333) )
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
  if ( *((_BYTE *)a1 + 1644) == 1 )
  {
    v156 = sap_signal_hdd_event((__int64)a1, v26, 0xDu, nullptr, v148, v149, v150, v151, v152, v153, v154, v155);
    *((_BYTE *)a1 + 1644) = 0;
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
  wlan_dnw_handle_bss_start(*(_QWORD *)(v23 + 21632), *((unsigned __int8 *)a1 + 12), 1);
  v173 = *a1;
  v174 = wlan_reg_freq_to_band(*a1);
  if ( *((_BYTE *)a1 + 1506) )
    v183 = wlan_reg_chan_band_to_freq(
             *(_QWORD *)(v23 + 21632),
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
                         *(_QWORD *)(v23 + 21632),
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
                          *(_QWORD *)(v23 + 21632),
                          v183,
                          0,
                          v196,
                          v197,
                          v198,
                          v199,
                          v200,
                          v201,
                          v202,
                          v203) == 2) )
    {
      is_dfs_for_freq = 1;
    }
  }
  else if ( v184 == 3 )
  {
    v491 = 0;
    v492 = 0;
    v490 = 0;
    wlan_reg_set_create_punc_bitmap((__int64)&v490, 1);
    v185 = *(_QWORD *)(v23 + 21632);
    LODWORD(v490) = 3;
    is_dfs_for_freq = (unsigned int)wlan_reg_get_5g_bonded_channel_state_for_pwrmode(
                                      v185,
                                      v173,
                                      (int *)&v490,
                                      0,
                                      v186,
                                      v187,
                                      v188,
                                      v189,
                                      v190,
                                      v191,
                                      v192,
                                      v193) == 2;
  }
  else
  {
    is_dfs_for_freq = wlan_reg_is_dfs_for_freq(
                        *(_QWORD *)(v23 + 21632),
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
  v212 = 0;
  if ( !wlan_reg_is_6ghz_chan_freq(*a1) && (is_dfs_for_freq & 1) != 0 )
  {
    if ( wlan_p2p_is_vdev_wfd_r2_mode(*((_QWORD *)a1 + 2)) )
    {
      wlan_p2p_get_ap_assist_dfs_params(*((_QWORD *)a1 + 2), &v488, &v497, nullptr, 0, nullptr, nullptr);
      v212 = 1;
      if ( (v488 & 1) == 0 )
        v212 = (v497 & 1) == 0;
    }
    else
    {
      v212 = 1;
    }
  }
  qdf_trace_msg(
    0x39u,
    8u,
    "%s: vdev %d freq %d, is_dfs %d is_dfs_owner %d is_valid_ap_assist %d",
    v204,
    v205,
    v206,
    v207,
    v208,
    v209,
    v210,
    v211,
    "sap_fsm_state_starting",
    *((unsigned __int8 *)a1 + 12),
    *a1,
    v212,
    (unsigned __int8)v488,
    (unsigned __int8)v497);
  if ( v212 )
  {
    if ( (sap_plus_sap_cac_skip(v23, (__int64)a1, v173, v224, v225, v226, v227, v228, v229, v230, v231) & 1) == 0
      && !*(_BYTE *)(v23 + 14880)
      && (wlan_pre_cac_complete_get(*((_QWORD *)a1 + 2)) & 1) == 0
      && (wlan_is_dnw_in_progress(*(_QWORD *)(v23 + 21632), *((unsigned __int8 *)a1 + 12)) & 1) == 0
      && (policy_mgr_get_dfs_master_dynamic_enabled(*(_QWORD *)(v23 + 21624)) & 1) != 0 )
    {
      v240 = *((unsigned __int8 *)a1 + 12);
      a1[182] = 1;
      qdf_trace_msg(
        0x39u,
        8u,
        "%s: sap_fsm: vdev %d: SAP_STARTED => SAP_STARTING to start cac timer",
        v232,
        v233,
        v234,
        v235,
        v236,
        v237,
        v238,
        v239,
        "sap_fsm_state_starting",
        v240);
LABEL_135:
      result = sap_fsm_cac_start(a1, v23, v23);
      goto LABEL_72;
    }
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: vdev %d skip cac timer",
      v232,
      v233,
      v234,
      v235,
      v236,
      v237,
      v238,
      v239,
      "sap_fsm_state_starting",
      *((unsigned __int8 *)a1 + 12));
    *((_BYTE *)a1 + 13) = 0;
    if ( (unsigned int)sap_signal_hdd_event(
                         (__int64)a1,
                         0,
                         0xEu,
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
      v257 = *((unsigned __int8 *)a1 + 12);
      v258 = "%s: Failed to indicate CAC START vdev %d";
      v259 = 2;
    }
    else
    {
      if ( !(unsigned int)sap_signal_hdd_event(
                            (__int64)a1,
                            0,
                            0x10u,
                            nullptr,
                            v249,
                            v250,
                            v251,
                            v252,
                            v253,
                            v254,
                            v255,
                            v256) )
      {
LABEL_126:
        wlansap_start_beacon_req(a1);
        result = v156;
        goto LABEL_72;
      }
      v257 = *((unsigned __int8 *)a1 + 12);
      v258 = "%s: Failed to indicate CAC End vdev %d";
      v259 = 8;
    }
    qdf_trace_msg(0x39u, v259, v258, v249, v250, v251, v252, v253, v254, v255, v256, "sap_propagate_cac_events", v257);
    goto LABEL_126;
  }
  result = v156;
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}
