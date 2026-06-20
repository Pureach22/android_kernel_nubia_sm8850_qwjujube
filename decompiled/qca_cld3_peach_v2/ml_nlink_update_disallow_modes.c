__int64 __fastcall ml_nlink_update_disallow_modes(
        __int64 a1,
        __int64 a2,
        char a3,
        char *a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x9
  __int64 v14; // x22
  __int64 result; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  unsigned __int64 v24; // x9
  __int64 v25; // x25
  unsigned __int64 v26; // x11
  unsigned __int64 v27; // x12
  __int64 v28; // x10
  unsigned __int64 v29; // x12
  unsigned int v30; // w23
  char v31; // w24
  char v32; // w26
  __int64 context; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  __int64 v42; // x20
  unsigned int legacy_conn_info; // w25
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  unsigned int v52; // w25
  unsigned int v53; // w8
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  int _24ghz_social_ch_freq; // w0
  unsigned __int8 v63; // w8
  unsigned int v64; // w21
  __int64 v65; // x27
  bool is_24ghz_ch_freq; // w19
  bool v67; // w0
  __int64 v68; // x20
  unsigned int v69; // w19
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  unsigned int hc_id; // w20
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  int v95; // w19
  double v96; // d0
  double v97; // d1
  double v98; // d2
  double v99; // d3
  double v100; // d4
  double v101; // d5
  double v102; // d6
  double v103; // d7
  int v104; // w21
  int v105; // w8
  bool v106; // w19
  bool v107; // w0
  char v108; // w8
  unsigned int v109; // w19
  bool v110; // cc
  __int64 v111; // x25
  __int64 v112; // x27
  int v113; // w26
  unsigned int _5g_low_high_cut_freq; // w19
  bool v115; // w0
  __int64 v116; // x8
  bool v117; // w0
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  __int64 v126; // x8
  int v127; // w8
  int v128; // w9
  int v129; // w7
  int v130; // w10
  int v131; // w8
  __int64 v132; // x19
  char v133; // w9
  int v134; // w11
  int v135; // w12
  int v136; // w12
  int v137; // w12
  int v138; // w11
  unsigned int v139; // w19
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  int rd_type; // w25
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  unsigned int v157; // w9
  char *v158; // x8
  char *v159; // x20
  char *v160; // x19
  unsigned int v161; // w0
  double v162; // d0
  double v163; // d1
  double v164; // d2
  double v165; // d3
  double v166; // d4
  double v167; // d5
  double v168; // d6
  double v169; // d7
  __int64 v170; // x19
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  __int64 v179; // x8
  const char *v180; // x2
  const char *v181; // x3
  unsigned int v182; // w4
  double v183; // d0
  double v184; // d1
  double v185; // d2
  double v186; // d3
  double v187; // d4
  double v188; // d5
  double v189; // d6
  double v190; // d7
  unsigned __int64 v191; // x19
  __int64 v192; // x26
  __int64 v193; // x8
  unsigned int v194; // w28
  char *v195; // x22
  char *v196; // x23
  __int64 v197; // x25
  __int64 v198; // x20
  unsigned __int64 v199; // x9
  unsigned int v200; // w5
  __int64 v201; // x10
  unsigned __int64 v202; // x12
  int v203; // w13
  unsigned __int64 v204; // x21
  unsigned int *v205; // x28
  unsigned int v206; // w4
  unsigned __int64 v207; // x19
  unsigned __int64 v208; // x10
  unsigned __int64 v209; // x9
  unsigned int *v210; // x8
  __int64 v211; // x21
  int v212; // w19
  int v213; // w20
  bool v214; // zf
  char v215; // w9
  __int64 v216; // [xsp+0h] [xbp-1F0h]
  int *v217; // [xsp+8h] [xbp-1E8h]
  __int64 v218; // [xsp+18h] [xbp-1D8h]
  unsigned __int64 v220; // [xsp+28h] [xbp-1C8h]
  int v221; // [xsp+30h] [xbp-1C0h]
  char v223; // [xsp+44h] [xbp-1ACh]
  unsigned __int64 v226; // [xsp+50h] [xbp-1A0h]
  unsigned __int64 v227; // [xsp+58h] [xbp-198h]
  unsigned __int64 v228; // [xsp+60h] [xbp-190h]
  __int64 v229; // [xsp+68h] [xbp-188h]
  unsigned __int64 v230; // [xsp+70h] [xbp-180h]
  unsigned __int64 v231; // [xsp+78h] [xbp-178h]
  __int64 v232; // [xsp+80h] [xbp-170h]
  __int64 v233; // [xsp+80h] [xbp-170h]
  unsigned int v234; // [xsp+88h] [xbp-168h]
  unsigned int v235; // [xsp+88h] [xbp-168h]
  int v236; // [xsp+90h] [xbp-160h] BYREF
  char v237[4]; // [xsp+94h] [xbp-15Ch] BYREF
  int v238; // [xsp+98h] [xbp-158h] BYREF
  char v239; // [xsp+9Ch] [xbp-154h]
  int v240; // [xsp+A0h] [xbp-150h] BYREF
  char v241; // [xsp+A4h] [xbp-14Ch]
  int v242; // [xsp+A8h] [xbp-148h] BYREF
  char v243; // [xsp+ACh] [xbp-144h]
  _QWORD v244[5]; // [xsp+B0h] [xbp-140h] BYREF
  __int64 v245; // [xsp+D8h] [xbp-118h] BYREF
  _QWORD v246[2]; // [xsp+E0h] [xbp-110h] BYREF
  int v247; // [xsp+F0h] [xbp-100h]
  _QWORD v248[4]; // [xsp+F8h] [xbp-F8h] BYREF
  _BYTE v249[16]; // [xsp+118h] [xbp-D8h] BYREF
  __int64 v250; // [xsp+128h] [xbp-C8h]
  __int64 v251; // [xsp+130h] [xbp-C0h]
  int v252; // [xsp+138h] [xbp-B8h]
  _QWORD v253[2]; // [xsp+140h] [xbp-B0h] BYREF
  int v254; // [xsp+150h] [xbp-A0h]
  __int64 v255; // [xsp+158h] [xbp-98h]
  __int64 v256; // [xsp+160h] [xbp-90h]
  int v257; // [xsp+168h] [xbp-88h]
  _QWORD v258[2]; // [xsp+170h] [xbp-80h] BYREF
  int v259; // [xsp+180h] [xbp-70h]
  _QWORD v260[2]; // [xsp+188h] [xbp-68h] BYREF
  int v261; // [xsp+198h] [xbp-58h]
  _QWORD v262[3]; // [xsp+1A0h] [xbp-50h] BYREF
  _QWORD v263[2]; // [xsp+1B8h] [xbp-38h]
  int v264; // [xsp+1C8h] [xbp-28h]
  __int64 v265; // [xsp+1D0h] [xbp-20h] BYREF
  __int64 v266; // [xsp+1D8h] [xbp-18h]
  __int64 v267; // [xsp+1E0h] [xbp-10h]

  v267 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a2 + 1360);
  memset(v248, 0, sizeof(v248));
  v237[0] = 0;
  v236 = 0;
  v247 = 0;
  v246[0] = 0;
  v246[1] = 0;
  v241 = 0;
  v240 = 0;
  v239 = 0;
  v238 = 0;
  memset(v244, 0, sizeof(v244));
  if ( v13 && *(_QWORD *)(v13 + 2224) )
  {
    v14 = a1;
    v218 = v13;
    v259 = 0;
    v258[0] = 0;
    v258[1] = 0;
    v255 = 0;
    v256 = 0;
    v257 = 0;
    v253[0] = 0;
    v253[1] = 0;
    v254 = 0;
    v250 = 0;
    v251 = 0;
    v252 = 0;
    memset(v249, 0, 15);
    v245 = 0;
    result = policy_mgr_is_mlo_in_mode_emlsr(a1, 0, nullptr);
    if ( (result & 1) != 0 )
    {
      v217 = &v236;
      result = ml_nlink_get_link_info(v14, a2, 1, 5, (int)v244, (int)v246, (int)&v240, (int)&v238, (__int64)v237);
      v24 = (unsigned __int8)v237[0];
      if ( (unsigned __int8)v237[0] >= 2uLL )
      {
        v25 = 0;
        v26 = 0;
        v27 = 1;
        v223 = 1;
        v221 = 1;
        v232 = v14;
        v226 = (unsigned __int8)v237[0];
        do
        {
          v220 = v26 + 1;
          if ( v26 + 1 < v24 )
          {
            if ( v26 > 4 )
              goto LABEL_220;
            v227 = v26;
            v228 = 4 * v26;
            do
            {
              if ( v228 > 0x13 )
                goto LABEL_219;
              v234 = *((_DWORD *)v246 + v26);
              LODWORD(v245) = v234;
              if ( v27 == 5 )
                goto LABEL_220;
              if ( 4 * v27 > 0x13 )
                goto LABEL_219;
              v30 = *((_DWORD *)v246 + v27);
              HIDWORD(v245) = v30;
              if ( v27 > 5 )
                goto LABEL_219;
              v264 = 0;
              v31 = *((_BYTE *)&v238 + v26);
              v32 = *((_BYTE *)&v238 + v27);
              v263[0] = 0;
              v263[1] = 0;
              memset(v262, 0, sizeof(v262));
              v243 = 0;
              v242 = 0;
              v261 = 0;
              v230 = v27;
              v260[0] = 0;
              v260[1] = 0;
              context = policy_mgr_get_context(v14);
              if ( !context )
              {
                qdf_trace_msg(
                  0x4Fu,
                  2u,
                  "%s: context is NULL",
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  "populate_disallow_modes");
                v53 = 4;
                goto LABEL_109;
              }
              v42 = context;
              v229 = v25;
              legacy_conn_info = policy_mgr_get_legacy_conn_info(v14, (__int64)&v242, (__int64)v262, (__int64)v260, 5u);
              if ( (a3 & 1) != 0 )
              {
                v52 = ((unsigned __int8)legacy_conn_info != 0) & ~(unsigned int)policy_mgr_is_hw_dbs_capable(v14);
                if ( (v52 & 7) != 0 )
                  goto LABEL_20;
                goto LABEL_36;
              }
              if ( !wlan_nan_is_disc_active(v14, v44, v45, v46, v47, v48, v49, v50, v51) )
                goto LABEL_30;
              if ( (unsigned __int8)legacy_conn_info > 1u )
                goto LABEL_31;
              if ( (unsigned int)wlan_nan_get_5ghz_social_ch_freq(
                                   *(_QWORD *)(v42 + 8),
                                   v54,
                                   v55,
                                   v56,
                                   v57,
                                   v58,
                                   v59,
                                   v60,
                                   v61) )
              {
                *((_DWORD *)v262 + (unsigned __int8)legacy_conn_info) = wlan_nan_get_5ghz_social_ch_freq(
                                                                          *(_QWORD *)(v42 + 8),
                                                                          v54,
                                                                          v55,
                                                                          v56,
                                                                          v57,
                                                                          v58,
                                                                          v59,
                                                                          v60,
                                                                          v61);
                *((_DWORD *)v260 + (unsigned __int8)legacy_conn_info) = 5;
                if ( (_BYTE)legacy_conn_info )
                {
                  legacy_conn_info = 2;
                  goto LABEL_31;
                }
                legacy_conn_info = 1;
              }
              if ( (unsigned int)wlan_nan_get_24ghz_social_ch_freq(
                                   *(_QWORD *)(v42 + 8),
                                   v54,
                                   v55,
                                   v56,
                                   v57,
                                   v58,
                                   v59,
                                   v60,
                                   v61) )
              {
                _24ghz_social_ch_freq = wlan_nan_get_24ghz_social_ch_freq(
                                          *(_QWORD *)(v42 + 8),
                                          v54,
                                          v55,
                                          v56,
                                          v57,
                                          v58,
                                          v59,
                                          v60,
                                          v61);
                v63 = legacy_conn_info++;
                *((_DWORD *)v262 + v63) = _24ghz_social_ch_freq;
                *((_DWORD *)v260 + v63) = 5;
              }
              else
              {
LABEL_30:
                if ( !(_BYTE)legacy_conn_info )
                {
                  v52 = 0;
                  goto LABEL_36;
                }
              }
LABEL_31:
              if ( LODWORD(v260[0]) >= 2 )
              {
                if ( (unsigned int)(LODWORD(v260[0]) - 2) > 1 )
                {
                  qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: mode type %d",
                    v54,
                    v55,
                    v56,
                    v57,
                    v58,
                    v59,
                    v60,
                    v61,
                    "populate_disallow_modes");
LABEL_43:
                  v65 = 0;
                  v64 = 1;
                  goto LABEL_44;
                }
                if ( (policy_mgr_is_vdev_high_tput_or_low_latency(v14, (unsigned __int8)v242) & 1) == 0 )
                  goto LABEL_43;
              }
              v64 = 0;
              v65 = 4;
LABEL_44:
              if ( (policy_mgr_is_hw_dbs_capable(v14) & 1) == 0 )
              {
                v223 = 0;
                v52 = 1;
                goto LABEL_48;
              }
              hc_id = get_hc_id(v14, 2, &v245);
              if ( hc_id >= 0x11 )
              {
                qdf_trace_msg(
                  0x8Fu,
                  8u,
                  "%s: invalid ml_hc_id, %d",
                  v87,
                  v88,
                  v89,
                  v90,
                  v91,
                  v92,
                  v93,
                  v94,
                  "populate_disallow_modes",
                  hc_id);
                v25 = v229;
                goto LABEL_116;
              }
              v139 = get_hc_id(v14, legacy_conn_info, v262);
              if ( v139 >= 0xA )
              {
                qdf_trace_msg(
                  0x8Fu,
                  8u,
                  "%s: invalid legacy_hc_id %d",
                  v140,
                  v141,
                  v142,
                  v143,
                  v144,
                  v145,
                  v146,
                  v147,
                  "populate_disallow_modes",
                  v139);
                v25 = v229;
                goto LABEL_116;
              }
              rd_type = policy_mgr_get_rd_type(v14);
              if ( wlan_nan_is_disc_active(v14, v149, v150, v151, v152, v153, v154, v155, v156) )
                v157 = 0;
              else
                v157 = rd_type - 1;
              v158 = (char *)&disallow_mlo_mode_table_sbs_low_share;
              if ( v157 <= 3 )
                v158 = (char *)*(&off_B32F18 + v157);
              if ( 8LL * v139 + 80 * (unsigned __int64)hc_id > 0x54F )
                goto LABEL_219;
              v52 = *(_DWORD *)&v158[80 * hc_id + 8 * v139 + v65];
              v159 = off_B32E90[hc_id];
              v160 = off_B32F50[v139];
              v161 = policy_mgr_get_rd_type(v14);
              LODWORD(v216) = v52;
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: ml %s legacy %s allow_mcc %d rd %d disallow_mode_bitmap 0x%x",
                v162,
                v163,
                v164,
                v165,
                v166,
                v167,
                v168,
                v169,
                "populate_disallow_modes",
                v159,
                v160,
                v64,
                v161,
                v216,
                v217);
              if ( (v52 & 7) != 0 )
              {
LABEL_20:
                v223 = 0;
                goto LABEL_48;
              }
LABEL_36:
              is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v234);
              v67 = wlan_reg_is_24ghz_ch_freq(v30);
              if ( !is_24ghz_ch_freq && !v67 )
              {
                v68 = *(_QWORD *)(a2 + 1360);
                if ( v68 )
                {
                  if ( *(_QWORD *)(v68 + 2224) )
                  {
                    qdf_mutex_acquire(v68 + 1656);
                    v69 = *(_DWORD *)(*(_QWORD *)(v68 + 2224) + 1448LL);
                    qdf_trace_msg(
                      0x8Fu,
                      8u,
                      "%s: disable_req 0x%x",
                      v70,
                      v71,
                      v72,
                      v73,
                      v74,
                      v75,
                      v76,
                      v77,
                      "ml_nlink_get_emlsr_mode_disable_req",
                      v69);
                    qdf_mutex_release(v68 + 1656);
                    if ( (v69 & 0x3FE) != 0 )
                    {
                      v52 |= 1u;
                      qdf_trace_msg(
                        0x8Fu,
                        8u,
                        "%s: disallow_mode_bitmap 0x%x req 0x%x",
                        v78,
                        v79,
                        v80,
                        v81,
                        v82,
                        v83,
                        v84,
                        v85,
                        "override_emlsr_disallow_mode",
                        v52,
                        v69 & 0x3FF);
                    }
                  }
                }
              }
LABEL_48:
              v95 = wlan_reg_is_24ghz_ch_freq(v234);
              v104 = 1 << v32;
              if ( wlan_reg_is_24ghz_ch_freq(v30) )
              {
                v105 = 0;
                if ( (v52 & 7) != 0 )
                  goto LABEL_50;
              }
              else
              {
                v105 = (((v104 | (1 << v31)) & ~a5) == 0) & ~v95;
                if ( (v52 & 7) != 0 )
                {
LABEL_50:
                  if ( (v52 & 0x18) != 0 )
                  {
                    if ( !v105 )
                      goto LABEL_62;
                  }
                  else if ( (v105 & (v52 >> 5) & 1) == 0 )
                  {
                    goto LABEL_62;
                  }
                  qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: disallow bitmap 0x%x conflict with force active bitmap 0x%x, allow MLMR",
                    v96,
                    v97,
                    v98,
                    v99,
                    v100,
                    v101,
                    v102,
                    v103,
                    "override_mlmr_disallow_mode",
                    v52,
                    a5);
                  v52 &= 0xFFFFFFC7;
                  goto LABEL_61;
                }
              }
              if ( (v52 & 0x38) == 0 && *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a2 + 1360) + 2224LL) + 1488LL) == 1 )
              {
                v106 = wlan_reg_is_24ghz_ch_freq(v234);
                v107 = wlan_reg_is_24ghz_ch_freq(v30);
                if ( !v106 && !v107 )
                {
                  v52 |= 8u;
                  qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: disallow_mode_bitmap 0x%x user emlsr_mode_req 0x%x",
                    v96,
                    v97,
                    v98,
                    v99,
                    v100,
                    v101,
                    v102,
                    v103,
                    "override_mlmr_disallow_mode",
                    v52,
                    *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(a2 + 1360) + 2224LL) + 1488LL));
LABEL_62:
                  v108 = 0;
                  v109 = 0;
                  do
                  {
                    if ( (v52 & 1) != 0 )
                    {
                      if ( v109 >= 5 )
                      {
                        qdf_trace_msg(
                          0x8Fu,
                          8u,
                          "%s: unexpected disallow_mode_bitmap 0x%x",
                          v96,
                          v97,
                          v98,
                          v99,
                          v100,
                          v101,
                          v102,
                          v103,
                          "extract_disallow_mode",
                          v52);
                        goto LABEL_71;
                      }
                      *((_DWORD *)v263 + v109++) = 1 << v108;
                    }
                    v110 = v52 > 1;
                    ++v108;
                    v52 >>= 1;
                  }
                  while ( v110 );
                  if ( v109 )
                    goto LABEL_71;
                  goto LABEL_70;
                }
              }
LABEL_61:
              if ( v52 )
                goto LABEL_62;
LABEL_70:
              v109 = 1;
              LODWORD(v263[0]) = 0;
LABEL_71:
              v111 = 0;
              v112 = v109;
              do
              {
                if ( v111 == 5 )
                  goto LABEL_220;
                v265 = 0;
                v266 = 0;
                v113 = *((_DWORD *)v263 + v111);
                _5g_low_high_cut_freq = policy_mgr_get_5g_low_high_cut_freq(v232);
                qdf_mem_set(&v265, 0x10u, 0);
                v115 = wlan_reg_is_24ghz_ch_freq(v234);
                if ( v234 <= _5g_low_high_cut_freq )
                  v116 = 8;
                else
                  v116 = 12;
                if ( v115 )
                  v116 = 4;
                *(_DWORD *)((char *)&v265 + v116) |= 1 << v31;
                v117 = wlan_reg_is_24ghz_ch_freq(v30);
                if ( v30 <= _5g_low_high_cut_freq )
                  v126 = 8;
                else
                  v126 = 12;
                if ( v117 )
                  v126 = 4;
                *(_DWORD *)((char *)&v265 + v126) |= v104;
                *((_DWORD *)&v255 + v111) = 1;
                if ( v113 > 15 )
                {
                  if ( v113 > 63 )
                  {
                    if ( v113 == 64 )
                    {
                      v127 = HIDWORD(v265);
                      v128 = v266;
                      goto LABEL_72;
                    }
                    if ( v113 == 128 )
                    {
                      v127 = HIDWORD(v265);
                      v128 = HIDWORD(v266);
LABEL_72:
                      *((_DWORD *)&v250 + v111) = v128 | v127;
                      goto LABEL_73;
                    }
LABEL_106:
                    v130 = HIDWORD(v266);
                    v131 = v266 | HIDWORD(v265);
                    *((_DWORD *)&v255 + v111) = 0;
                    v129 = v131 | v130;
                    goto LABEL_107;
                  }
                  if ( v113 != 16 )
                  {
                    if ( v113 != 32 )
                      goto LABEL_106;
                    goto LABEL_104;
                  }
                }
                else
                {
                  if ( v113 > 3 )
                  {
                    if ( v113 == 4 )
                    {
                      *((_DWORD *)&v255 + v111) = 2;
LABEL_104:
                      v129 = v266;
                      goto LABEL_107;
                    }
                    if ( v113 != 8 )
                      goto LABEL_106;
                    goto LABEL_102;
                  }
                  if ( v113 == 1 )
                  {
                    *((_DWORD *)&v255 + v111) = 2;
LABEL_102:
                    v129 = HIDWORD(v266) | v266;
                    goto LABEL_107;
                  }
                  if ( v113 != 2 )
                    goto LABEL_106;
                  *((_DWORD *)&v255 + v111) = 2;
                }
                v129 = HIDWORD(v266);
LABEL_107:
                *((_DWORD *)&v250 + v111) = v129;
LABEL_73:
                qdf_trace_msg(
                  0x8Fu,
                  8u,
                  "%s: [%d] disallow_mode 0x%x %s link bitmap 0x%x",
                  v118,
                  v119,
                  v120,
                  v121,
                  v122,
                  v123,
                  v124,
                  v125,
                  "populate_disallow_modes",
                  (unsigned int)v111++,
                  (unsigned int)v113);
              }
              while ( v112 != v111 );
              LOBYTE(v25) = v229;
              v14 = v232;
              v53 = (unsigned __int8)v112;
LABEL_109:
              LODWORD(v132) = (unsigned __int8)v25;
              v133 = 5 - v25;
              if ( (unsigned __int8)v25 > 5u )
                v133 = 0;
              if ( (unsigned __int8)v25 > 4u )
                goto LABEL_115;
              v134 = v255;
              *((_DWORD *)v253 + (unsigned __int8)v25) = v250;
              *((_DWORD *)v258 + (unsigned __int8)v25) = v134;
              v28 = (unsigned __int8)v25 + 1LL;
              if ( v53 == 1 )
                goto LABEL_11;
              if ( v133 == 1 )
                goto LABEL_114;
              if ( (unsigned __int8)v25 == 4 )
                goto LABEL_219;
              v135 = HIDWORD(v255);
              *((_DWORD *)v253 + v28) = HIDWORD(v250);
              *((_DWORD *)v258 + v28) = v135;
              v28 = (unsigned __int8)v25 + 2LL;
              if ( v53 == 2 )
                goto LABEL_11;
              if ( v133 == 2 )
                goto LABEL_114;
              if ( (unsigned __int8)v25 > 2u )
                goto LABEL_219;
              v136 = v256;
              *((_DWORD *)v253 + v28) = v251;
              *((_DWORD *)v258 + v28) = v136;
              v28 = (unsigned __int8)v25 + 3LL;
              if ( v53 == 3 )
              {
LABEL_11:
                v24 = v226;
                v26 = v227;
                v29 = v230;
                v25 = (unsigned int)v28;
                goto LABEL_12;
              }
              if ( v133 == 3 )
              {
LABEL_114:
                LODWORD(v132) = v28;
                goto LABEL_115;
              }
              if ( (unsigned __int8)v25 == 2 )
                goto LABEL_219;
              v137 = HIDWORD(v256);
              *((_DWORD *)v253 + v28) = HIDWORD(v251);
              v132 = (unsigned __int8)v25 | 4LL;
              *((_DWORD *)v258 + v28) = v137;
              if ( v53 == 4 )
              {
                LODWORD(v28) = (unsigned __int8)v25 | 4;
                goto LABEL_11;
              }
              if ( v133 != 4 )
              {
                if ( (_BYTE)v25 )
                  goto LABEL_219;
                v138 = v257;
                *((_DWORD *)v253 + v132) = v252;
                *((_DWORD *)v258 + v132) = v138;
                if ( v53 > 4 )
                {
                  LODWORD(v28) = 5;
                  goto LABEL_11;
                }
                if ( v133 != 5 )
                  goto LABEL_219;
                LODWORD(v132) = 5;
              }
LABEL_115:
              qdf_trace_msg(
                0x8Fu,
                2u,
                "%s: max disallowed modes exceeded limits",
                v16,
                v17,
                v18,
                v19,
                v20,
                v21,
                v22,
                v23,
                "ml_nlink_update_disallow_modes");
              v25 = (unsigned int)v132;
LABEL_116:
              v24 = v226;
              v26 = v227;
              v29 = v230;
LABEL_12:
              v27 = v29 + 1;
            }
            while ( v27 < v24 );
          }
          v26 = v220;
          v27 = (unsigned __int8)++v221;
        }
        while ( v220 < v24 );
        v170 = *(_QWORD *)(a2 + 1360);
        if ( (v223 & 1) != 0 )
        {
          if ( v170 && *(_QWORD *)(v170 + 2224) )
          {
            qdf_mutex_acquire(v170 + 1656);
            v179 = *(_QWORD *)(v170 + 2224);
            v180 = "%s: clr disable_req to 0x%x from 0x%x by req 0x%x";
            v181 = "ml_nlink_clr_emlsr_mode_disable_req";
            v182 = *(_DWORD *)(v179 + 1448) & 0xFFFFFFFE;
            goto LABEL_150;
          }
        }
        else if ( v170 && *(_QWORD *)(v170 + 2224) )
        {
          qdf_mutex_acquire(v170 + 1656);
          v179 = *(_QWORD *)(v170 + 2224);
          v180 = "%s: set disable_req to 0x%x from 0x%x by req 0x%x";
          v181 = "ml_nlink_set_emlsr_mode_disable_req";
          v182 = *(_DWORD *)(v179 + 1448) | 1;
LABEL_150:
          *(_DWORD *)(v179 + 1448) = v182;
          qdf_trace_msg(0x8Fu, 8u, v180, v171, v172, v173, v174, v175, v176, v177, v178, v181);
          qdf_mutex_release(v170 + 1656);
        }
        else
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: mlo_ctx or sta_ctx null",
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            v23,
            "ml_nlink_set_emlsr_mode_disable_req");
        }
        qdf_mem_set(v248, 0x20u, 0);
        if ( (_BYTE)v25 )
        {
          v191 = (unsigned __int8)v25;
          v192 = 0;
          v193 = 0;
          v194 = 0;
          v195 = (char *)v258 + 4;
          v196 = (char *)v253 + 4;
          v197 = (unsigned __int8)v25 - 1LL;
          v198 = 4;
          v231 = v191;
          while ( 1 )
          {
            if ( v193 == 5 )
              goto LABEL_220;
            v199 = 4 * v193;
            if ( (unsigned __int64)(4 * v193) > 0x13 )
              goto LABEL_219;
            v200 = *((_DWORD *)v253 + v193);
            if ( !v200 )
            {
              ++v193;
              goto LABEL_155;
            }
            if ( v194 > 3 )
            {
              qdf_trace_msg(
                0x8Fu,
                8u,
                "%s: unexpected num_disallow_mode_comb %d",
                v183,
                v184,
                v185,
                v186,
                v187,
                v188,
                v189,
                v190,
                "ml_nlink_update_disallow_modes",
                v194);
              goto LABEL_211;
            }
            v233 = v193 + 1;
            v235 = v194;
            if ( v193 + 1 >= v191 )
            {
              if ( v199 <= 0x13 )
              {
                v204 = 8LL * v194;
                v205 = (unsigned int *)&v248[v204 / 8];
                LODWORD(v248[v204 / 8]) = *((_DWORD *)v258 + v193);
                goto LABEL_178;
              }
              goto LABEL_219;
            }
            v201 = 0;
            v202 = v198;
            do
            {
              if ( v192 + 4 == v201 )
                goto LABEL_220;
              if ( v202 > 0x13 )
                goto LABEL_219;
              if ( *((_DWORD *)v253 + v193) == *(_DWORD *)&v196[4 * v201] )
              {
                if ( v199 > 0x13 )
                  goto LABEL_219;
                v203 = *((_DWORD *)v258 + v193);
                if ( v203 == 2 )
                {
                  if ( *(_DWORD *)&v195[4 * v201] == 1 )
                    goto LABEL_162;
                }
                else if ( v203 == 1 && *(_DWORD *)&v195[4 * v201] == 2 )
                {
LABEL_162:
                  *((_DWORD *)v258 + v193) = 3;
                  *(_DWORD *)&v196[4 * v201] = 0;
                }
              }
              ++v201;
              v202 += 4LL;
            }
            while ( v197 != v201 );
            if ( v199 > 0x13 )
              goto LABEL_219;
            v204 = 8LL * v194;
            v200 = *((_DWORD *)v253 + v193);
            v205 = (unsigned int *)&v248[v204 / 8];
            LODWORD(v248[v204 / 8]) = *((_DWORD *)v258 + v193);
            if ( !v200 )
            {
              v209 = v204 | 4;
              v210 = v205 + 1;
              if ( (v204 | 4) <= 0x20 )
              {
LABEL_199:
                *(_BYTE *)v210 = -1;
LABEL_200:
                if ( v204 - 28 >= 0xFFFFFFFFFFFFFFDFLL )
                {
                  *((_BYTE *)v205 + 5) = -1;
LABEL_202:
                  if ( v204 - 27 >= 0xFFFFFFFFFFFFFFDFLL )
                  {
                    *((_BYTE *)v205 + 6) = -1;
LABEL_204:
                    if ( v204 - 25 >= 0xFFFFFFFFFFFFFFE0LL )
                    {
                      *((_BYTE *)v205 + 7) = -1;
                      goto LABEL_206;
                    }
                  }
                }
              }
LABEL_219:
              __break(1u);
LABEL_220:
              __break(0x5512u);
            }
LABEL_178:
            v206 = 0;
            v207 = 0;
            while ( 2 )
            {
              if ( (v200 & 1) == 0 )
              {
LABEL_180:
                v110 = v200 > 1;
                ++v206;
                v200 >>= 1;
                if ( !v110 )
                  goto LABEL_187;
                continue;
              }
              break;
            }
            if ( v206 < 0xF )
            {
              if ( v207 >= 0xF )
              {
                qdf_trace_msg(
                  0x8Fu,
                  2u,
                  "%s: linkid buff overflow 0x%x",
                  v183,
                  v184,
                  v185,
                  v186,
                  v187,
                  v188,
                  v189,
                  v190,
                  "convert_link_bitmap_to_link_ids",
                  v200);
                goto LABEL_187;
              }
              v249[v207++] = v206;
              goto LABEL_180;
            }
            qdf_trace_msg(
              0x8Fu,
              2u,
              "%s: linkid invalid %d 0x%x",
              v183,
              v184,
              v185,
              v186,
              v187,
              v188,
              v189,
              v190,
              "convert_link_bitmap_to_link_ids");
LABEL_187:
            v208 = (unsigned __int8)v207;
            v209 = v204 | 4;
            v210 = v205 + 1;
            if ( !(_BYTE)v207 )
            {
              v191 = v231;
              if ( v209 <= 0x20 )
                goto LABEL_199;
              goto LABEL_219;
            }
            v191 = v231;
            if ( v209 > 0x20 )
              goto LABEL_219;
            *(_BYTE *)v210 = v249[0];
            if ( v208 == 1 )
              goto LABEL_200;
            if ( (v204 | 5) > 0x20 )
              goto LABEL_219;
            *((_BYTE *)v205 + 5) = v249[1];
            if ( v208 <= 2 )
              goto LABEL_202;
            if ( (v204 | 6) > 0x20 )
              goto LABEL_219;
            *((_BYTE *)v205 + 6) = v249[2];
            if ( v208 == 3 )
              goto LABEL_204;
            if ( (v204 | 7) > 0x20 )
              goto LABEL_219;
            *((_BYTE *)v205 + 7) = v249[3];
LABEL_206:
            if ( v204 > 0x1C || v209 > 0x1C )
              goto LABEL_219;
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: [%d] mode %d ieee_link_id_comb 0x%0x",
              v183,
              v184,
              v185,
              v186,
              v187,
              v188,
              v189,
              v190,
              "ml_nlink_update_disallow_modes",
              v235,
              *v205,
              *v210);
            v193 = v233;
            v194 = v235 + 1;
LABEL_155:
            v198 += 4;
            --v192;
            v195 += 4;
            v196 += 4;
            --v197;
            if ( v193 == v191 )
              goto LABEL_211;
          }
        }
        v194 = 0;
LABEL_211:
        qdf_mutex_acquire(v218 + 1656);
        v211 = *(_QWORD *)(v218 + 2224);
        v212 = *(_DWORD *)(v211 + 1452);
        v213 = qdf_mem_cmp(v248, (const void *)(v211 + 1456), 0x20u);
        *(_DWORD *)(v211 + 1452) = v194;
        qdf_mem_copy((void *)(v211 + 1456), v248, 0x20u);
        result = qdf_mutex_release(v218 + 1656);
        if ( a4 )
        {
          if ( v213 )
            v214 = 0;
          else
            v214 = v194 == v212;
          v215 = !v214;
          *a4 = v215;
        }
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x8Fu,
               2u,
               "%s: mlo_ctx or sta_ctx null",
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               a13,
               "ml_nlink_update_disallow_modes");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
