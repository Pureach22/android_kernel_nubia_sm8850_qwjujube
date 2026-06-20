__int64 __fastcall csr_update_channel_list(
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
  __int64 v9; // x25
  unsigned int v11; // w20
  _QWORD *context; // x0
  _QWORD *v13; // x22
  __int64 psoc_ext_obj_fl; // x0
  __int64 v15; // x21
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  unsigned __int8 v49; // w22
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  __int64 v66; // x0
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x20
  bool is_5_mhz_enabled; // w22
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  bool is_10_mhz_enabled; // w23
  double v86; // d0
  double v87; // d1
  double v88; // d2
  double v89; // d3
  double v90; // d4
  double v91; // d5
  double v92; // d6
  double v93; // d7
  __int64 v94; // x26
  int v95; // w27
  __int64 v96; // x24
  __int64 v97; // x22
  __int64 v98; // x8
  unsigned int v99; // w28
  int channel_state_for_pwrmode; // w23
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  const char *v109; // x2
  __int64 v110; // x9
  _BOOL4 v111; // w20
  int v112; // w8
  unsigned int v113; // w28
  __int64 v114; // x8
  _DWORD *v115; // x20
  int v116; // w9
  int v117; // w22
  int v118; // w8
  __int64 v119; // x27
  _BYTE *v120; // x27
  int v121; // w8
  int v122; // w27
  _BYTE *v123; // x28
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  __int64 v132; // x8
  _BYTE *v133; // x21
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  __int64 v142; // x8
  _BYTE *v143; // x20
  int v144; // w8
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  __int64 v153; // x8
  _BYTE *v154; // x20
  int v155; // w8
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  __int64 v164; // x8
  _BYTE *v165; // x20
  int v166; // w8
  __int64 v167; // x21
  __int64 v168; // x23
  __int64 v169; // x20
  __int64 v170; // x26
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  __int64 v179; // x0
  __int64 v180; // x22
  unsigned __int8 v181; // w20
  _DWORD *v182; // x1
  __int64 v183; // x9
  unsigned int v184; // w23
  __int64 v185; // x20
  unsigned __int8 v186; // w22
  char *v187; // x24
  char *v188; // x26
  _DWORD *v189; // x1
  __int64 v190; // x9
  double v191; // d0
  double v192; // d1
  double v193; // d2
  double v194; // d3
  double v195; // d4
  double v196; // d5
  double v197; // d6
  double v198; // d7
  __int64 v199; // x8
  int v200; // w20
  char *v201; // x27
  int v202; // w23
  _DWORD *v203; // x26
  __int64 v204; // x28
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  char *v213; // x0
  _DWORD *v214; // x26
  __int64 v215; // x22
  char *v216; // x0
  _DWORD *v217; // x26
  __int64 v218; // x22
  char *v219; // x0
  _DWORD *v220; // x26
  char *v221; // x0
  unsigned int v222; // w8
  __int64 v223; // x19
  __int64 v224; // x0
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  unsigned int *is_vdev_connected; // x8
  __int64 v234; // x20
  __int64 v235; // x0
  double v236; // d0
  double v237; // d1
  double v238; // d2
  double v239; // d3
  double v240; // d4
  double v241; // d5
  double v242; // d6
  double v243; // d7
  unsigned int *v244; // x8
  __int64 v245; // x20
  __int64 v246; // x0
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  unsigned int *v255; // x8
  __int64 v256; // x20
  __int64 v257; // x0
  double v258; // d0
  double v259; // d1
  double v260; // d2
  double v261; // d3
  double v262; // d4
  double v263; // d5
  double v264; // d6
  double v265; // d7
  unsigned int *v266; // x8
  __int64 v267; // x20
  __int64 v268; // x0
  double v269; // d0
  double v270; // d1
  double v271; // d2
  double v272; // d3
  double v273; // d4
  double v274; // d5
  double v275; // d6
  double v276; // d7
  unsigned int *v277; // x8
  __int64 v278; // x20
  double v279; // d0
  double v280; // d1
  double v281; // d2
  double v282; // d3
  double v283; // d4
  double v284; // d5
  double v285; // d6
  double v286; // d7
  unsigned int *v287; // x8
  __int64 v288; // x20
  __int64 n; // [xsp+0h] [xbp-140h]
  _BYTE *v290; // [xsp+8h] [xbp-138h]
  bool v291; // [xsp+10h] [xbp-130h]
  __int64 v292; // [xsp+10h] [xbp-130h]
  bool v293; // [xsp+18h] [xbp-128h]
  __int64 v294; // [xsp+18h] [xbp-128h]
  __int64 v295; // [xsp+20h] [xbp-120h]
  char v296; // [xsp+20h] [xbp-120h]
  unsigned __int16 v297; // [xsp+2Ch] [xbp-114h] BYREF
  __int64 v298; // [xsp+30h] [xbp-110h] BYREF
  _BYTE *v299; // [xsp+38h] [xbp-108h]
  __int64 v300; // [xsp+40h] [xbp-100h]
  __int64 v301; // [xsp+48h] [xbp-F8h]
  __int64 v302; // [xsp+50h] [xbp-F0h]
  __int64 v303; // [xsp+58h] [xbp-E8h]
  _QWORD v304[25]; // [xsp+60h] [xbp-E0h] BYREF
  int v305; // [xsp+128h] [xbp-18h]
  __int64 v306; // [xsp+130h] [xbp-10h]

  v9 = a1 + 0x4000;
  v306 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(unsigned __int8 *)(a1 + 16604);
  v302 = 0;
  v303 = 0;
  v300 = 0;
  v301 = 0;
  v298 = 0;
  v299 = nullptr;
  v305 = 0;
  memset(v304, 0, sizeof(v304));
  v297 = 0;
  context = _cds_get_context(64, (__int64)"csr_update_channel_list", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
    goto LABEL_162;
  v13 = context;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 21624));
  if ( !psoc_ext_obj_fl )
    goto LABEL_162;
  v15 = psoc_ext_obj_fl;
  result = sme_acquire_global_lock(a1 + 12840);
  if ( (_DWORD)result )
    goto LABEL_163;
  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 6600LL) == 1 )
  {
    if ( (wlan_get_pdev_status(*(_QWORD *)(a1 + 21632), v17, v18, v19, v20, v21, v22, v23, v24) & 0xFFFFFFFD) == 1 )
    {
      *(_BYTE *)(v9 + 802) = 1;
      sme_release_global_lock(a1 + 12840);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: scan in progress postpone channel list req ",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "csr_update_channel_list");
LABEL_194:
      result = 0;
      goto LABEL_163;
    }
    *(_BYTE *)(v9 + 802) = 0;
  }
  sme_release_global_lock(a1 + 12840);
  cnss_utils_get_wlan_unsafe_channel(v13[5], v304, &v297, 204);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: add len of social channels, before adding - num_chan:%hu",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "csr_add_len_of_social_channels",
    v11);
  v49 = v11;
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 8) + 1036LL) == 2 )
  {
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                         *(_QWORD *)(a1 + 21632),
                         0x96Cu,
                         0,
                         v41,
                         v42,
                         v43,
                         v44,
                         v45,
                         v46,
                         v47,
                         v48) == 3 )
      LOBYTE(v11) = v11 + 1;
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                         *(_QWORD *)(a1 + 21632),
                         0x985u,
                         0,
                         v50,
                         v51,
                         v52,
                         v53,
                         v54,
                         v55,
                         v56,
                         v57) == 3 )
      LOBYTE(v11) = v11 + 1;
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                         *(_QWORD *)(a1 + 21632),
                         0x99Eu,
                         0,
                         v58,
                         v59,
                         v60,
                         v61,
                         v62,
                         v63,
                         v64,
                         v65) == 3 )
      v49 = v11 + 1;
    else
      v49 = v11;
    v11 = v49;
  }
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: after adding - num_chan:%hu",
    v41,
    v42,
    v43,
    v44,
    v45,
    v46,
    v47,
    v48,
    "csr_add_len_of_social_channels",
    v11);
  csr_init_operating_classes(a1);
  v66 = _qdf_mem_malloc(12LL * v49 + 20, "csr_update_channel_list", 1014);
  if ( !v66 )
  {
    result = 2;
    goto LABEL_163;
  }
  v75 = v66;
  is_5_mhz_enabled = cds_is_5_mhz_enabled(v67, v68, v69, v70, v71, v72, v73, v74);
  if ( is_5_mhz_enabled )
    qdf_trace_msg(0x34u, 8u, "quarter_rate enabled", v77, v78, v79, v80, v81, v82, v83, v84);
  is_10_mhz_enabled = cds_is_10_mhz_enabled(v77, v78, v79, v80, v81, v82, v83, v84);
  if ( is_10_mhz_enabled )
    qdf_trace_msg(0x34u, 8u, "half_rate enabled", v86, v87, v88, v89, v90, v91, v92, v93);
  v290 = (_BYTE *)v75;
  if ( *(_BYTE *)(v9 + 220) )
  {
    v94 = 0;
    v95 = 0;
    v293 = is_5_mhz_enabled;
    v96 = a1 + 16608;
    v97 = v75 + 8;
    v291 = is_10_mhz_enabled;
    v295 = v75 + 8;
    while ( 1 )
    {
      if ( v94 == 100 )
LABEL_195:
        __break(0x5512u);
      v99 = *(_DWORD *)(v96 + 4 * v94);
      if ( (wlan_reg_is_dsrc_freq() & 1) != 0 )
        goto LABEL_25;
      channel_state_for_pwrmode = (unsigned __int8)wlan_reg_get_channel_state_for_pwrmode(
                                                     *(_QWORD *)(a1 + 21632),
                                                     v99,
                                                     0,
                                                     v86,
                                                     v87,
                                                     v88,
                                                     v89,
                                                     v90,
                                                     v91,
                                                     v92,
                                                     v93);
      if ( channel_state_for_pwrmode != 3 && !*(_BYTE *)(v9 + 800) )
        goto LABEL_25;
      if ( wlan_reg_is_6ghz_chan_freq(v99)
        && (wlan_reg_is_6ghz_band_set(*(_QWORD *)(a1 + 21632), v101, v102, v103, v104, v105, v106, v107, v108) & 1) == 0 )
      {
        v109 = "%s: skip 6ghz frequency %d";
      }
      else if ( channel_state_for_pwrmode == 2 && *(_DWORD *)(v15 + 2716) == 2 )
      {
        v109 = "%s: skip dfs channel frequency %d";
      }
      else
      {
        if ( *(_BYTE *)(v15 + 2720) != 1 || !v297 )
          goto LABEL_47;
        v110 = 0;
        v111 = 1;
        do
        {
          if ( v110 == 102 )
            goto LABEL_195;
          if ( v99 == *((unsigned __int16 *)v304 + v110) )
            break;
          v111 = ++v110 < (unsigned __int64)v297;
        }
        while ( v297 != v110 );
        if ( !wlan_reg_is_24ghz_ch_freq(v99) || (v112 = *(unsigned __int8 *)(v15 + 2721), v112 != 1) )
        {
          if ( !wlan_reg_is_5ghz_ch_freq(v99) )
            goto LABEL_47;
          v112 = *(unsigned __int8 *)(v15 + 2721) == 2;
        }
        if ( (v111 & v112) != 1 )
        {
LABEL_47:
          v113 = (unsigned __int8)v95;
          v114 = 0;
          v115 = (_DWORD *)(v97 + 12LL * (unsigned __int8)v95);
          v116 = *(_DWORD *)(v96 + 4 * v94);
          *v115 = v116;
          while ( *(_DWORD *)(a1 + v114 + 15404) != v116 )
          {
            v114 += 12;
            if ( v114 == 1200 )
            {
              v117 = v95;
              LOBYTE(v118) = 0;
              goto LABEL_54;
            }
          }
          v118 = *(_DWORD *)(a1 + v114 + 15412);
          v117 = v95;
LABEL_54:
          v119 = v295 + 12LL * (unsigned __int8)v95;
          *(_BYTE *)(v119 + 4) = v118;
          v120 = (_BYTE *)(v119 + 4);
          if ( *(_BYTE *)(v9 + 801) == 1 )
          {
            v121 = *(_DWORD *)(v96 + 4 * v94);
            if ( v121 == 2467 )
            {
              *v120 = 8;
              qdf_trace_msg(
                0x34u,
                8u,
                "%s: txpow for channel 12 is %d",
                v101,
                v102,
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                "csr_update_channel_list",
                8);
              v121 = *(_DWORD *)(v96 + 4 * v94);
            }
            if ( v121 == 2472 )
            {
              *v120 = 2;
              qdf_trace_msg(
                0x34u,
                8u,
                "%s: txpow for channel 13 is %d",
                v101,
                v102,
                v103,
                v104,
                v105,
                v106,
                v107,
                v108,
                "csr_update_channel_list",
                2);
            }
          }
          v122 = v117;
          v97 = v295;
          if ( (ucfg_is_nan_allowed_on_freq(*(_QWORD *)(a1 + 21632), (unsigned int)*v115) & 1) == 0 )
            *(_BYTE *)(v295 + 12LL * v113 + 8) = 1;
          if ( channel_state_for_pwrmode == 2 )
            *(_BYTE *)(v295 + 12LL * v113 + 5) = 1;
          v95 = v122 + 1;
          v98 = v295 + 12LL * v113;
          *(_BYTE *)(v98 + 7) = v293;
          *(_BYTE *)(v98 + 6) = v291;
          goto LABEL_25;
        }
        v109 = "%s: ignoring unsafe channel freq %d";
      }
      qdf_trace_msg(0x34u, 8u, v109, v101, v102, v103, v104, v105, v106, v107, v108, "csr_update_channel_list", v99);
LABEL_25:
      if ( ++v94 >= (unsigned __int64)*(unsigned __int8 *)(v9 + 220) )
        goto LABEL_65;
    }
  }
  LOBYTE(v95) = 0;
LABEL_65:
  v123 = v290;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: add social channels chan_list %pK, num_chan %hu",
    v86,
    v87,
    v88,
    v89,
    v90,
    v91,
    v92,
    v93,
    "csr_add_social_channels",
    v290,
    (unsigned __int8)v95);
  v132 = *(_QWORD *)(a1 + 8);
  if ( *(_DWORD *)(v132 + 1036) == 2 )
  {
    v133 = v290 + 8;
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                         *(_QWORD *)(a1 + 21632),
                         0x96Cu,
                         0,
                         v124,
                         v125,
                         v126,
                         v127,
                         v128,
                         v129,
                         v130,
                         v131) == 3 )
    {
      v142 = 0;
      v143 = &v133[12 * (unsigned __int8)v95];
      *(_DWORD *)v143 = 2412;
      while ( *(_DWORD *)(a1 + v142 + 15404) != 2412 )
      {
        v142 += 12;
        if ( v142 == 1200 )
        {
          LOBYTE(v144) = 0;
          goto LABEL_72;
        }
      }
      v144 = *(_DWORD *)(a1 + v142 + 15412);
LABEL_72:
      v143[4] = v144;
      v143[5] = 0;
      if ( cds_is_5_mhz_enabled(v134, v135, v136, v137, v138, v139, v140, v141) )
      {
        v143[7] = 1;
      }
      else if ( cds_is_10_mhz_enabled(v134, v135, v136, v137, v138, v139, v140, v141) )
      {
        v143[6] = 1;
      }
      LOBYTE(v95) = v95 + 1;
    }
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                         *(_QWORD *)(a1 + 21632),
                         0x985u,
                         0,
                         v134,
                         v135,
                         v136,
                         v137,
                         v138,
                         v139,
                         v140,
                         v141) == 3 )
    {
      v153 = 0;
      v154 = &v133[12 * (unsigned __int8)v95];
      *(_DWORD *)v154 = 2437;
      while ( *(_DWORD *)(a1 + v153 + 15404) != 2437 )
      {
        v153 += 12;
        if ( v153 == 1200 )
        {
          LOBYTE(v155) = 0;
          goto LABEL_83;
        }
      }
      v155 = *(_DWORD *)(a1 + v153 + 15412);
LABEL_83:
      v154[4] = v155;
      v154[5] = 0;
      if ( cds_is_5_mhz_enabled(v145, v146, v147, v148, v149, v150, v151, v152) )
      {
        v154[7] = 1;
      }
      else if ( cds_is_10_mhz_enabled(v145, v146, v147, v148, v149, v150, v151, v152) )
      {
        v154[6] = 1;
      }
      LOBYTE(v95) = v95 + 1;
    }
    if ( (unsigned int)wlan_reg_get_channel_state_for_pwrmode(
                         *(_QWORD *)(a1 + 21632),
                         0x99Eu,
                         0,
                         v145,
                         v146,
                         v147,
                         v148,
                         v149,
                         v150,
                         v151,
                         v152) == 3 )
    {
      v164 = 0;
      v165 = &v133[12 * (unsigned __int8)v95];
      *(_DWORD *)v165 = 2462;
      while ( *(_DWORD *)(a1 + v164 + 15404) != 2462 )
      {
        v164 += 12;
        if ( v164 == 1200 )
        {
          LOBYTE(v166) = 0;
          goto LABEL_94;
        }
      }
      v166 = *(_DWORD *)(a1 + v164 + 15412);
LABEL_94:
      v165[4] = v166;
      v165[5] = 0;
      if ( cds_is_5_mhz_enabled(v156, v157, v158, v159, v160, v161, v162, v163) )
      {
        v165[7] = 1;
      }
      else if ( cds_is_10_mhz_enabled(v156, v157, v158, v159, v160, v161, v162, v163) )
      {
        v165[6] = 1;
      }
      LOBYTE(v95) = v95 + 1;
    }
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: after adding -num_chan %hu",
      v156,
      v157,
      v158,
      v159,
      v160,
      v161,
      v162,
      v163,
      "csr_add_social_channels",
      (unsigned __int8)v95);
    v132 = *(_QWORD *)(a1 + 8);
  }
  if ( *(_BYTE *)(v132 + 1764) != 1 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: Early Stop Scan Feature not supported",
      v124,
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      "csr_update_channel_list");
    goto LABEL_147;
  }
  v167 = (unsigned __int8)v95;
  v296 = v95;
  v168 = 12LL * (unsigned __int8)v95;
  v169 = _qdf_mem_malloc(v168 + 20, "csr_roam_sort_channel_for_early_stop", 694);
  v170 = _qdf_mem_malloc(v168 + 20, "csr_roam_sort_channel_for_early_stop", 695);
  v179 = v169;
  if ( v169 && v170 )
  {
    n = 12LL * (unsigned __int8)v95;
    v292 = v170;
    v294 = v169;
    if ( (_BYTE)v95 )
    {
      v180 = 0;
      v181 = 0;
      do
      {
        v182 = &v290[12 * v180 + 8];
        v183 = 0;
        while ( *v182 != csr_roam_sort_channel_for_early_stop_fixed_greedy_freq_list[v183] )
        {
          if ( ++v183 == 36 )
          {
            qdf_mem_copy((void *)(v170 + 8 + 12LL * v181++), v182, 0xCu);
            break;
          }
        }
        ++v180;
      }
      while ( v180 != (unsigned __int8)v95 );
      v179 = v294;
      v184 = v181;
    }
    else
    {
      v184 = 0;
    }
    v185 = 0;
    v186 = 0;
    v187 = v290 + 8;
    v188 = (char *)(v179 + 8);
    do
    {
      if ( (_BYTE)v95 )
      {
        v189 = v290 + 8;
        v190 = (unsigned __int8)v95;
        while ( csr_roam_sort_channel_for_early_stop_fixed_greedy_freq_list[v185] != *v189 )
        {
          --v190;
          v189 += 3;
          if ( !v190 )
            goto LABEL_115;
        }
        qdf_mem_copy(&v188[12 * v186++], v189, 0xCu);
      }
LABEL_115:
      ++v185;
    }
    while ( v185 != 36 );
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: greedy=%d, non-greedy=%d, tot=%d",
      v171,
      v172,
      v173,
      v174,
      v175,
      v176,
      v177,
      v178,
      "csr_roam_sort_channel_for_early_stop",
      v186,
      v184,
      (unsigned __int8)v95);
    if ( v184 + v186 == (unsigned __int8)v95 )
    {
      qdf_mem_copy(v187, v188, 12 * (unsigned int)v186);
      v170 = v292;
      qdf_mem_copy(&v187[12 * v186], (const void *)(v292 + 8), 12 * v184);
      v199 = *(_QWORD *)(a1 + 8);
      v179 = v294;
      v123 = v290;
      if ( *(_BYTE *)(v199 + 1976) != 1 )
        goto LABEL_146;
      v200 = *(_DWORD *)(v199 + 1956);
      v201 = (char *)_qdf_mem_malloc(n, "csr_roam_arrange_ch_list", 609);
      v179 = v294;
      if ( !v201 )
        goto LABEL_146;
      if ( v296 )
      {
        v202 = 0;
        v203 = v290 + 8;
        v204 = v167;
        do
        {
          if ( wlan_reg_is_5ghz_ch_freq(*v203)
            && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), *v203, v205, v206, v207, v208, v209, v210, v211, v212)
              & 1) == 0 )
          {
            v213 = &v201[12 * v202++];
            qdf_mem_copy(v213, v203, 0xCu);
            *v203 = 0;
          }
          --v204;
          v203 += 3;
        }
        while ( v204 );
        if ( v200 )
        {
          v123 = v290;
          v214 = v290 + 8;
          v215 = v167;
          do
          {
            if ( wlan_reg_is_5ghz_ch_freq(*v214) )
            {
              v216 = &v201[12 * v202++];
              qdf_mem_copy(v216, v214, 0xCu);
              *v214 = 0;
            }
            --v215;
            v214 += 3;
          }
          while ( v215 );
        }
        else
        {
          v123 = v290;
          v217 = v290 + 8;
          v218 = v167;
          do
          {
            if ( wlan_reg_is_24ghz_ch_freq(*v217) )
            {
              v219 = &v201[12 * v202++];
              qdf_mem_copy(v219, v217, 0xCu);
              *v217 = 0;
            }
            --v218;
            v217 += 3;
          }
          while ( v218 );
        }
        v220 = v290 + 8;
        do
        {
          if ( *v220 )
          {
            v221 = &v201[12 * v202++];
            qdf_mem_copy(v221, v220, 0xCu);
            *v220 = 0;
          }
          --v167;
          v220 += 3;
        }
        while ( v167 );
      }
      qdf_mem_copy(v187, v201, n);
      _qdf_mem_free((__int64)v201);
    }
    else
    {
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: incorrect sorting of channels",
        v191,
        v192,
        v193,
        v194,
        v195,
        v196,
        v197,
        v198,
        "csr_roam_sort_channel_for_early_stop");
      v123 = v290;
    }
    v170 = v292;
    v179 = v294;
  }
LABEL_146:
  _qdf_mem_free(v179);
  _qdf_mem_free(v170);
  LOBYTE(v95) = v296;
LABEL_147:
  v222 = *(_DWORD *)(v9 + 820);
  if ( v222 <= 9 && ((1 << v222) & 0x320) != 0 )
  {
    v123[2] = 1;
    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 2875LL) == 1 )
      v123[3] = 1;
    v222 = *(_DWORD *)(v9 + 820);
  }
  if ( v222 <= 9 && ((1 << v222) & 0x290) != 0 )
  {
    v123[1] = 1;
    v222 = *(_DWORD *)(v9 + 820);
  }
  if ( v222 - 9 <= 2 )
  {
    v123[4] = 1;
    v222 = *(_DWORD *)(v9 + 820);
  }
  if ( v222 <= 0xD && ((1 << v222) & 0x3200) != 0 )
    v123[5] = 1;
  *v123 = v95;
  ((void (__fastcall *)(_QWORD, _BYTE *))mlme_store_fw_scan_channels)(*(_QWORD *)(a1 + 21624), v123);
  LODWORD(v298) = 4295;
  v299 = v123;
  qdf_trace(52, 0xFBu, 255, 4295);
  if ( (unsigned int)scheduler_post_message_debug(
                       0x34u,
                       0x36u,
                       54,
                       (unsigned __int16 *)&v298,
                       0x494u,
                       (__int64)"csr_update_channel_list") )
  {
    _qdf_mem_free((__int64)v123);
LABEL_162:
    result = 16;
    goto LABEL_163;
  }
  v223 = *(_QWORD *)(a1 + 21624);
  v224 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v223, 0, 11);
  if ( v224 )
  {
    is_vdev_connected = (unsigned int *)*(unsigned int *)(v224 + 16);
    if ( !(_DWORD)is_vdev_connected )
    {
      v234 = v224;
      is_vdev_connected = (unsigned int *)wlan_cm_is_vdev_connected(
                                            v224,
                                            v225,
                                            v226,
                                            v227,
                                            v228,
                                            v229,
                                            v230,
                                            v231,
                                            v232);
      v224 = v234;
      if ( ((unsigned __int8)is_vdev_connected & 1) != 0 )
      {
        policy_mgr_set_pcl_for_existing_combo(v223, 0, 0);
        v224 = v234;
      }
    }
    wlan_objmgr_vdev_release_ref(v224, 0xBu, is_vdev_connected, v225, v226, v227, v228, v229, v230, v231, v232);
  }
  v235 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v223, 1, 11);
  if ( v235 )
  {
    v244 = (unsigned int *)*(unsigned int *)(v235 + 16);
    if ( !(_DWORD)v244 )
    {
      v245 = v235;
      v244 = (unsigned int *)wlan_cm_is_vdev_connected(v235, v236, v237, v238, v239, v240, v241, v242, v243);
      v235 = v245;
      if ( ((unsigned __int8)v244 & 1) != 0 )
      {
        policy_mgr_set_pcl_for_existing_combo(v223, 0, 1u);
        v235 = v245;
      }
    }
    wlan_objmgr_vdev_release_ref(v235, 0xBu, v244, v236, v237, v238, v239, v240, v241, v242, v243);
  }
  v246 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v223, 2, 11);
  if ( v246 )
  {
    v255 = (unsigned int *)*(unsigned int *)(v246 + 16);
    if ( !(_DWORD)v255 )
    {
      v256 = v246;
      v255 = (unsigned int *)wlan_cm_is_vdev_connected(v246, v247, v248, v249, v250, v251, v252, v253, v254);
      v246 = v256;
      if ( ((unsigned __int8)v255 & 1) != 0 )
      {
        policy_mgr_set_pcl_for_existing_combo(v223, 0, 2u);
        v246 = v256;
      }
    }
    wlan_objmgr_vdev_release_ref(v246, 0xBu, v255, v247, v248, v249, v250, v251, v252, v253, v254);
  }
  v257 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v223, 3, 11);
  if ( v257 )
  {
    v266 = (unsigned int *)*(unsigned int *)(v257 + 16);
    if ( !(_DWORD)v266 )
    {
      v267 = v257;
      v266 = (unsigned int *)wlan_cm_is_vdev_connected(v257, v258, v259, v260, v261, v262, v263, v264, v265);
      v257 = v267;
      if ( ((unsigned __int8)v266 & 1) != 0 )
      {
        policy_mgr_set_pcl_for_existing_combo(v223, 0, 3u);
        v257 = v267;
      }
    }
    wlan_objmgr_vdev_release_ref(v257, 0xBu, v266, v258, v259, v260, v261, v262, v263, v264, v265);
  }
  v268 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v223, 4, 11);
  if ( v268 )
  {
    v277 = (unsigned int *)*(unsigned int *)(v268 + 16);
    if ( !(_DWORD)v277 )
    {
      v278 = v268;
      v277 = (unsigned int *)wlan_cm_is_vdev_connected(v268, v269, v270, v271, v272, v273, v274, v275, v276);
      v268 = v278;
      if ( ((unsigned __int8)v277 & 1) != 0 )
      {
        policy_mgr_set_pcl_for_existing_combo(v223, 0, 4u);
        v268 = v278;
      }
    }
    wlan_objmgr_vdev_release_ref(v268, 0xBu, v277, v269, v270, v271, v272, v273, v274, v275, v276);
  }
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v223, 5, 11);
  if ( result )
  {
    v287 = (unsigned int *)*(unsigned int *)(result + 16);
    if ( !(_DWORD)v287 )
    {
      v288 = result;
      v287 = (unsigned int *)wlan_cm_is_vdev_connected(result, v279, v280, v281, v282, v283, v284, v285, v286);
      result = v288;
      if ( ((unsigned __int8)v287 & 1) != 0 )
      {
        policy_mgr_set_pcl_for_existing_combo(v223, 0, 5u);
        result = v288;
      }
    }
    wlan_objmgr_vdev_release_ref(result, 0xBu, v287, v279, v280, v281, v282, v283, v284, v285, v286);
    goto LABEL_194;
  }
LABEL_163:
  _ReadStatusReg(SP_EL0);
  return result;
}
