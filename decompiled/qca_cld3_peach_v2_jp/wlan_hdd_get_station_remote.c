__int64 __fastcall wlan_hdd_get_station_remote(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *v17; // x23
  _QWORD *peer_by_mac; // x0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x24
  __int64 v28; // x20
  __int64 peer_stats; // x0
  __int64 v30; // x25
  __int64 v31; // x1
  __int64 v32; // x22
  __int64 v33; // x9
  int v34; // w10
  __int64 v35; // x8
  __int64 v36; // x23
  __int64 v37; // x0
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x24
  _QWORD *context; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  __int64 v56; // x8
  __int64 (*v57)(void); // x8
  unsigned int v58; // w0
  __int64 v59; // x4
  unsigned __int64 v60; // x8
  __int64 v61; // x24
  unsigned int v62; // w0
  int v63; // w0
  char v64; // w8
  __int64 v65; // x9
  __int64 v66; // x10
  int v67; // w8
  int v68; // w12
  __int64 v69; // x8
  int v70; // w9
  char v71; // w10
  char v72; // w9
  int v73; // w11
  int v74; // w13
  int v75; // w12
  int v76; // w13
  int v77; // w11
  int v78; // w12
  int v79; // w13
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  unsigned int v88; // w25
  unsigned int v89; // w26
  unsigned int v90; // w28
  unsigned int v91; // w24
  bool is_link_speed_report_actual; // w0
  unsigned int v93; // w8
  __int64 result; // x0
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  unsigned int v127; // w27
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  _BOOL4 v136; // w27
  unsigned int v137; // w12
  unsigned __int8 v138; // w8
  unsigned int v139; // w28
  unsigned int v140; // w9
  unsigned __int8 v141; // w10
  int v142; // kr00_4
  unsigned __int16 *v143; // x8
  double v144; // d0
  double v145; // d1
  double v146; // d2
  double v147; // d3
  double v148; // d4
  double v149; // d5
  double v150; // d6
  double v151; // d7
  unsigned int v152; // w8
  char *v153; // x12
  unsigned __int64 v154; // x11
  int v155; // w14
  __int64 v156; // x25
  unsigned int v157; // w25
  int v158; // w8
  unsigned __int64 v159; // x27
  unsigned __int64 v160; // x8
  __int64 v161; // x11
  __int64 v162; // x9
  unsigned __int64 v163; // x10
  unsigned int v164; // w10
  char *v165; // x9
  __int64 v166; // x11
  unsigned int v167; // w8
  unsigned int v168; // w9
  char *v169; // x14
  int v170; // w8
  unsigned __int64 v171; // x9
  __int64 v172; // x11
  __int64 v173; // x11
  __int64 v174; // x8
  __int64 v175; // x11
  __int64 v176; // x10
  __int64 v177; // x9
  unsigned __int64 v178; // x10
  __int64 v179; // x11
  __int64 v180; // x10
  __int64 v181; // x11
  __int64 v182; // x10
  char *v183; // x9
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  unsigned int v192; // w28
  int v193; // w8
  int v194; // w25
  int v195; // w9
  char v196; // w10
  void *v197; // x9
  __int64 v198; // x8
  bool v200; // w8
  unsigned int v201; // w26
  unsigned int v202; // w25
  bool v203; // w0
  unsigned int v204; // w8
  bool v205; // w0
  bool v207; // w9
  __int64 v208; // x9
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
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
  char *v249; // [xsp+8h] [xbp-98h]
  char *v250; // [xsp+10h] [xbp-90h]
  char v251; // [xsp+1Ch] [xbp-84h]
  unsigned int v252; // [xsp+20h] [xbp-80h]
  unsigned int v253; // [xsp+28h] [xbp-78h]
  unsigned int v254; // [xsp+2Ch] [xbp-74h] BYREF
  __int64 v255; // [xsp+30h] [xbp-70h] BYREF
  __int64 v256; // [xsp+38h] [xbp-68h]
  __int64 v257; // [xsp+40h] [xbp-60h]
  __int64 v258; // [xsp+48h] [xbp-58h]
  unsigned __int64 v259; // [xsp+50h] [xbp-50h]
  __int64 v260; // [xsp+58h] [xbp-48h]
  __int64 v261; // [xsp+60h] [xbp-40h]
  __int64 v262; // [xsp+68h] [xbp-38h]
  __int64 v263; // [xsp+70h] [xbp-30h]
  __int64 v264; // [xsp+78h] [xbp-28h]
  __int64 v265; // [xsp+80h] [xbp-20h]
  __int64 v266; // [xsp+88h] [xbp-18h] BYREF
  _QWORD v267[2]; // [xsp+90h] [xbp-10h] BYREF

  v267[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a2 + 38) == *(_DWORD *)a3
    && *(unsigned __int16 *)(a2 + 42) == *(unsigned __int16 *)(a3 + 4)
    && (*(_DWORD *)(a2 + 32) != *(_DWORD *)a3 || *(unsigned __int16 *)(a2 + 36) != *(unsigned __int16 *)(a3 + 4)) )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Get stats with mld level %02x:%02x:%02x:**:**:%02x",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "wlan_hdd_get_station_remote",
      *(unsigned __int8 *)(a2 + 38),
      *(unsigned __int8 *)(a2 + 39),
      *(unsigned __int8 *)(a2 + 40),
      *(unsigned __int8 *)(a2 + 43));
  }
  v17 = *(__int64 **)(a1 + 2712);
  v264 = 0;
  v265 = 0;
  v262 = 0;
  v263 = 0;
  v260 = 0;
  v261 = 0;
  v258 = 0;
  v259 = 0;
  v256 = 0;
  v257 = 0;
  v255 = 0;
  v254 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_get_link_peer_stats_sap");
  peer_by_mac = wlan_objmgr_get_peer_by_mac(**(_QWORD **)(a1 + 2712), (_BYTE *)(a2 + 32), 0x51u);
  if ( peer_by_mac )
  {
    v27 = peer_by_mac[11];
    if ( v27 )
    {
      v28 = (__int64)peer_by_mac;
      peer_stats = wlan_cfg80211_mc_cp_stats_get_peer_stats(peer_by_mac[11], a2 + 32, &v254);
      if ( !v254 && peer_stats )
      {
        v30 = peer_stats;
        *(_DWORD *)(a2 + 436) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 72LL);
        *(_DWORD *)(a2 + 440) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 76LL);
        *(_DWORD *)(a2 + 444) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 80LL);
        *(_DWORD *)(a2 + 448) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 84LL);
        *(_DWORD *)(a2 + 452) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 88LL);
        *(_DWORD *)(a2 + 456) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 92LL);
        *(_DWORD *)(a2 + 460) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 96LL);
        *(_DWORD *)(a2 + 464) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 100LL);
        qdf_mem_set(&v255, 0x58u, 0);
        v31 = *(_QWORD *)(v30 + 160);
        v32 = v30;
        v33 = *(_QWORD *)(v31 + 16);
        v34 = *(_DWORD *)(v31 + 24);
        LODWORD(v255) = *(_DWORD *)(v31 + 8);
        v35 = *(_QWORD *)(v31 + 32);
        v256 = v33;
        v258 = v35;
        LODWORD(v33) = *(_DWORD *)(v31 + 40);
        LODWORD(v35) = *(_DWORD *)(v31 + 44);
        LODWORD(v257) = v34;
        v259 = __PAIR64__(v35, v33);
        LODWORD(v35) = *(_DWORD *)(v31 + 52);
        LODWORD(v260) = *(_DWORD *)(v31 + 48);
        BYTE4(v260) = v35;
        wlan_hdd_fill_rate_info((__int64)&v255, (_DWORD *)v31);
        if ( !hdd_get_link_info_by_vdev((__int64)v17, *(unsigned __int8 *)(v27 + 104)) )
          goto LABEL_57;
        v36 = *v17;
        v37 = _qdf_mem_malloc(0xE90u, "wlan_hdd_fill_station_info", 6826);
        if ( !v37 )
          goto LABEL_57;
        v46 = v37;
        context = _cds_get_context(71, (__int64)"wlan_hdd_fill_station_info", v38, v39, v40, v41, v42, v43, v44, v45);
        if ( context && *context )
        {
          v56 = *(_QWORD *)(*context + 32LL);
          if ( v56 )
          {
            v57 = *(__int64 (**)(void))(v56 + 144);
            if ( v57 )
            {
              if ( *((_DWORD *)v57 - 1) != -1642106733 )
                __break(0x8228u);
              v58 = v57();
              v59 = v58;
              if ( !v58 )
              {
                v60 = *(_QWORD *)(v46 + 1616);
                if ( v60 <= *(_QWORD *)(v46 + 2616) )
                  v60 = *(_QWORD *)(v46 + 2616);
                *(_QWORD *)(a2 + 104) = v60;
                _qdf_mem_free(v46);
                v61 = jiffies;
                v62 = jiffies_to_msecs(jiffies - *(_QWORD *)(a2 + 112));
                *a4 |= 0x10000uLL;
                *((_DWORD *)a4 + 2) = v62 / 0x3E8;
                v63 = jiffies_to_msecs(v61 - *(_QWORD *)(a2 + 104));
                v64 = BYTE4(v260);
                v65 = v256;
                v66 = v258;
                *((_DWORD *)a4 + 3) = v63;
                *((_BYTE *)a4 + 45) = v64;
                v67 = v255;
                v68 = *((_DWORD *)a4 + 28);
                a4[3] = v66;
                a4[4] = v65;
                *((_DWORD *)a4 + 21) = v257;
                *((_DWORD *)a4 + 22) = v67;
                v69 = *a4;
                LODWORD(v66) = HIDWORD(v259);
                *((_DWORD *)a4 + 23) = v259;
                *((_DWORD *)a4 + 24) = v66;
                *a4 = v69 | 0x1801E8E;
                *((_DWORD *)a4 + 27) = 3;
                if ( *(_BYTE *)(a2 + 48) )
                  v70 = 3;
                else
                  v70 = 0;
                *((_DWORD *)a4 + 28) = v68 & 0xFFFFFFFC | v70;
                v71 = *((_BYTE *)a4 + 47);
                *a4 = v69 | 0x1821E8E;
                v72 = 0x80;
                *((_BYTE *)a4 + 46) = 0x80;
                v73 = *(unsigned __int8 *)(a2 + 436);
                *((_BYTE *)a4 + 47) = v71 | 1;
                *((_BYTE *)a4 + 52) = v73;
                if ( (v73 & 0x7F) != 0 )
                {
                  v72 = v73;
                  *((_BYTE *)a4 + 46) = v73;
                }
                v74 = *(char *)(a2 + 440);
                *((_BYTE *)a4 + 47) = v71 | 3;
                v75 = (unsigned __int8)v74;
                *((_BYTE *)a4 + 53) = v74;
                if ( v74 && v72 < v74 )
                {
                  v72 = v74;
                  *((_BYTE *)a4 + 46) = v74;
                }
                v76 = *(char *)(a2 + 444);
                v77 = v75 | v73;
                *((_BYTE *)a4 + 47) = v71 | 7;
                v78 = (unsigned __int8)v76;
                *((_BYTE *)a4 + 54) = v76;
                if ( v76 && v72 < v76 )
                {
                  v72 = v76;
                  *((_BYTE *)a4 + 46) = v76;
                }
                v79 = *(char *)(a2 + 448);
                *((_BYTE *)a4 + 47) = v71 | 0xF;
                *((_BYTE *)a4 + 55) = v79;
                if ( v79 && v72 < v79 )
                  *((_BYTE *)a4 + 46) = v79;
                if ( v77 | v78 | (unsigned __int8)v79 )
                  *a4 = v69 | 0x5823E8E;
                v266 = 0;
                v267[0] = 0;
                ucfg_mlme_stats_get_cfg_values(v36, (_DWORD *)v267 + 1, v267, (_DWORD *)&v266 + 1, &v266);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: reportMaxLinkSpeed %d",
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  v85,
                  v86,
                  v87,
                  "hdd_fill_rate_info",
                  (unsigned int)v266);
                v88 = v261;
                v89 = *(_DWORD *)(a2 + 52);
                v90 = (unsigned int)v261 / 0x64;
                if ( (v89 & 1) != 0 )
                {
                  v91 = 1;
                }
                else
                {
                  v91 = *(unsigned __int8 *)(a2 + 50);
                  is_link_speed_report_actual = ucfg_mlme_stats_is_link_speed_report_actual(v36);
                  v93 = v262;
                  if ( !(_DWORD)v262 )
                    v93 = v89;
                  if ( is_link_speed_report_actual )
                    v91 = BYTE5(v261);
                  else
                    v93 = v89;
                  if ( BYTE6(v261) == 255 )
                    v89 = 1;
                  else
                    v89 = v93;
                }
                if ( ucfg_mlme_stats_is_link_speed_report_actual(v36) )
                {
                  if ( (v89 & 1) != 0 )
                  {
                    v253 = 0;
                    v127 = 255;
                  }
                  else
                  {
                    v127 = BYTE6(v261);
                    v253 = 0;
                  }
                  goto LABEL_281;
                }
                v252 = v90;
                if ( (ucfg_mlme_stats_is_link_speed_report_max(v36) & 1) == 0 )
                {
                  if ( (ucfg_mlme_stats_is_link_speed_report_max_scaled(v36) & 1) != 0 )
                  {
                    if ( SHIDWORD(v267[0]) > SBYTE4(v260) )
                    {
                      if ( SLODWORD(v267[0]) <= SBYTE4(v260) )
                      {
                        v136 = 0;
                        v251 = 0;
                        v137 = 1;
                      }
                      else
                      {
                        v251 = 0;
                        v136 = SHIDWORD(v266) > SBYTE4(v260);
                        if ( SHIDWORD(v266) <= SBYTE4(v260) )
                          v137 = 2;
                        else
                          v137 = 3;
                      }
LABEL_73:
                      v138 = *(_BYTE *)(a2 + 153);
                      v139 = 0;
                      if ( (unsigned __int8)(v138 - 13) >= 0xF2u )
                        v138 = 12;
                      v140 = *(unsigned __int8 *)(a2 + 154);
                      v141 = v138;
                      if ( v138 <= v140 )
                        v141 = *(_BYTE *)(a2 + 154);
                      if ( v140 != 255 )
                        v138 = v141;
                      v142 = v138 - 2;
                      v143 = (unsigned __int16 *)&unk_A08C42;
                      switch ( v142 )
                      {
                        case 0:
                          goto LABEL_93;
                        case 2:
                          v143 = (unsigned __int16 *)&unk_A08C4C;
                          goto LABEL_93;
                        case 9:
                          v143 = (unsigned __int16 *)&unk_A08C56;
                          goto LABEL_93;
                        case 10:
                          v143 = (unsigned __int16 *)&unk_A08C60;
                          goto LABEL_93;
                        case 16:
                          v143 = (unsigned __int16 *)&unk_A08C6A;
                          goto LABEL_93;
                        case 20:
                          v143 = (unsigned __int16 *)&unk_A08C74;
                          goto LABEL_93;
                        case 22:
                          v143 = (unsigned __int16 *)&unk_A08C7E;
                          goto LABEL_93;
                        case 34:
                          v143 = (unsigned __int16 *)&unk_A08C88;
                          goto LABEL_93;
                        case 42:
                          v143 = (unsigned __int16 *)&unk_A08C92;
                          goto LABEL_93;
                        case 46:
                          v143 = (unsigned __int16 *)&unk_A08C9C;
                          goto LABEL_93;
                        case 64:
                          v143 = (unsigned __int16 *)&unk_A08CA6;
                          goto LABEL_93;
                        case 70:
                          v143 = (unsigned __int16 *)&unk_A08CB0;
                          goto LABEL_93;
                        case 94:
                          v143 = (unsigned __int16 *)&unk_A08CBA;
                          goto LABEL_93;
                        case 106:
                          v143 = (unsigned __int16 *)&unk_A08CC4;
LABEL_93:
                          v139 = v143[v137];
                          break;
                        default:
                          break;
                      }
                      v253 = v137;
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: maxrate %d",
                        v128,
                        v129,
                        v130,
                        v131,
                        v132,
                        v133,
                        v134,
                        v135,
                        "hdd_get_max_rate_legacy",
                        v139);
                      if ( ((v136 | v89) & 1) != 0 )
                      {
                        if ( (v89 & 1) != 0 )
                        {
                          v127 = 255;
                          if ( v139 <= v252 )
                            v152 = v252;
                          else
                            v152 = v139;
                          if ( v139 )
                            v90 = v152;
                          else
                            v90 = v252;
                          goto LABEL_281;
                        }
                        v127 = BYTE6(v261);
                        v90 = v252;
                        if ( v88 >= 0x64 )
                        {
LABEL_281:
                          hdd_fill_sinfo_rate_info(a4, v89, v127, v91, v90, 1, HIDWORD(v262));
                          v201 = *(_DWORD *)(a2 + 52);
                          v202 = HIDWORD(v263) / 0x64;
                          if ( (v201 & 1) == 0 )
                          {
                            v91 = *(unsigned __int8 *)(a2 + 50);
                            v203 = ucfg_mlme_stats_is_link_speed_report_actual(v36);
                            v204 = HIDWORD(v264);
                            if ( !HIDWORD(v264) )
                              v204 = v201;
                            if ( v203 )
                              v91 = BYTE1(v264);
                            else
                              v204 = v201;
                            if ( BYTE2(v264) == 255 )
                              v201 = 1;
                            else
                              v201 = v204;
                          }
                          v205 = ucfg_mlme_stats_is_link_speed_report_actual(v36);
                          if ( v253 == 3 || v205 )
                          {
                            if ( (v201 & 1) == 0 )
                              v127 = BYTE2(v264);
                          }
                          else if ( v90 && v90 >= v202 )
                          {
                            v202 = v90;
                          }
                          else if ( (v201 & 1) == 0 )
                          {
                            v207 = (unsigned __int8)v91 != 3 && (unsigned __int8)v91 != 6;
                            if ( ((BYTE2(v264) > 8u) & (v201 >> 5) & *(_DWORD *)&v207) != 0 )
                              v127 = 8;
                            else
                              v127 = BYTE2(v264);
                          }
                          hdd_fill_sinfo_rate_info(a4, v201, v127, v91, v202, 0, (unsigned int)v265);
                          v208 = *a4;
                          *((_DWORD *)a4 + 41) = *(_DWORD *)(a2 + 68);
                          *a4 = v208 | 0x8000000;
                          a4[15] = *(_QWORD *)(a2 + 272);
                          a4[16] = *(unsigned int *)(a2 + 264);
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: dump stainfo",
                            v209,
                            v210,
                            v211,
                            v212,
                            v213,
                            v214,
                            v215,
                            v216,
                            "wlan_hdd_fill_station_info");
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: con_time %d inact_time %d tx_pkts %d rx_pkts %d",
                            v217,
                            v218,
                            v219,
                            v220,
                            v221,
                            v222,
                            v223,
                            v224,
                            "wlan_hdd_fill_station_info",
                            *((unsigned int *)a4 + 2),
                            *((unsigned int *)a4 + 3),
                            *((unsigned int *)a4 + 22),
                            *((unsigned int *)a4 + 21));
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: failed %d retries %d tx_bytes %lld rx_bytes %lld",
                            v225,
                            v226,
                            v227,
                            v228,
                            v229,
                            v230,
                            v231,
                            v232,
                            "wlan_hdd_fill_station_info",
                            *((unsigned int *)a4 + 24),
                            *((unsigned int *)a4 + 23),
                            a4[4],
                            a4[3]);
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: rssi %d tx mcs %d legacy %d nss %d flags %x",
                            v233,
                            v234,
                            v235,
                            v236,
                            v237,
                            v238,
                            v239,
                            v240,
                            "wlan_hdd_fill_station_info",
                            (unsigned int)*((char *)a4 + 45),
                            *((unsigned __int8 *)a4 + 60),
                            *((unsigned __int16 *)a4 + 29),
                            *((unsigned __int8 *)a4 + 61),
                            *((unsigned __int16 *)a4 + 28));
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: rx mcs %d legacy %d nss %d flags %x",
                            v241,
                            v242,
                            v243,
                            v244,
                            v245,
                            v246,
                            v247,
                            v248,
                            "wlan_hdd_fill_station_info",
                            *((unsigned __int8 *)a4 + 74),
                            *((unsigned __int16 *)a4 + 36),
                            *((unsigned __int8 *)a4 + 75),
                            *((unsigned __int16 *)a4 + 35));
                          goto LABEL_57;
                        }
                        goto LABEL_273;
                      }
                      if ( (unsigned __int8)v91 == 1 )
                        v153 = (char *)&supported_he_mcs_rate_nss1_0;
                      else
                        v153 = (char *)&supported_he_mcs_rate_nss2_0;
                      if ( (v89 & 0x800) != 0 )
                      {
                        v154 = 3;
                      }
                      else if ( (v89 & 0x400) != 0 )
                      {
                        v154 = 2;
                      }
                      else
                      {
                        v154 = (v89 >> 9) & 1;
                      }
                      if ( (v89 & 0xF00) != 0 )
                      {
                        v155 = SBYTE4(v260);
                        v156 = 2;
                        if ( *(_WORD *)(a2 + 510) )
                        {
                          v127 = 13;
                        }
                        else
                        {
                          v158 = *(_BYTE *)(a2 + 158) & 3;
                          if ( v158 == 3 )
                          {
                            v250 = v153;
                            v159 = v154;
                            LODWORD(v249) = SBYTE4(v260);
                            qdf_trace_msg(
                              0x33u,
                              2u,
                              "%s: invalid he_max_mcs",
                              v144,
                              v145,
                              v146,
                              v147,
                              v148,
                              v149,
                              v150,
                              v151,
                              "hdd_get_max_rate_he");
                            v155 = (int)v249;
                            v154 = v159;
                            v153 = v250;
                            v127 = BYTE6(v261);
                          }
                          else
                          {
                            v127 = v158 + 9;
                          }
                        }
                        LODWORD(v160) = ~(v89 >> 2) & 2;
                        if ( (v251 & 1) == 0 )
                        {
                          if ( (v89 & 0x800) == 0 )
                          {
                            if ( v154 == 3 )
                              goto LABEL_319;
                            v164 = 0;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154] >= v155 || !v127 )
                              goto LABEL_133;
                            if ( ((56 * v154) | 4) > 0xA8 )
                              goto LABEL_319;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 1] >= v155 )
                            {
                              v164 = 1;
                              goto LABEL_133;
                            }
                            if ( v127 == 1 )
                              goto LABEL_131;
                            if ( v154 > 2 )
                              goto LABEL_319;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 2] >= v155 )
                            {
                              v164 = 2;
                              goto LABEL_133;
                            }
                            if ( v127 == 2 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 3] >= v155 )
                            {
                              v164 = 3;
                              goto LABEL_133;
                            }
                            if ( v127 == 3 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 4] >= v155 )
                            {
                              v164 = 4;
                              goto LABEL_133;
                            }
                            if ( v127 == 4 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 5] >= v155 )
                            {
                              v164 = 5;
                              goto LABEL_133;
                            }
                            if ( v127 == 5 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 6] >= v155 )
                            {
                              v164 = 6;
                              goto LABEL_133;
                            }
                            if ( v127 == 6 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 7] >= v155 )
                            {
                              v164 = 7;
                              goto LABEL_133;
                            }
                            if ( v127 == 7 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 8] >= v155 )
                              goto LABEL_320;
                            if ( v127 == 8 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 9] >= v155 )
                            {
                              v164 = 9;
                              goto LABEL_133;
                            }
                            if ( v127 == 9 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 10] >= v155 )
                            {
                              v164 = 10;
                              goto LABEL_133;
                            }
                            if ( v127 == 10 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 11] >= v155 )
                            {
                              v164 = 11;
                              goto LABEL_133;
                            }
                            if ( v127 == 11 )
                              goto LABEL_131;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 12] >= v155 )
                            {
                              v164 = 12;
                              goto LABEL_133;
                            }
                            if ( v127 == 12 )
                            {
LABEL_131:
                              v164 = v127;
                              goto LABEL_133;
                            }
                            if ( rssi_mcs_tbl[14 * (unsigned int)v154 + 13] >= v155 )
                            {
                              v164 = 13;
                              goto LABEL_133;
                            }
                            v164 = v127;
                            if ( v127 == 13 )
                              goto LABEL_133;
                          }
                          __break(0x5512u);
                          goto LABEL_197;
                        }
                        if ( (v89 & 0x800) == 0 )
                          goto LABEL_136;
                        v161 = 2LL * (~(v89 >> 2) & 2);
                        v162 = v161 + 38;
                        v160 = v161 + 38 + 50LL * v127;
                        if ( v160 > 0x2BB )
                        {
                          do
                          {
                            while ( 1 )
                            {
LABEL_319:
                              while ( 1 )
                              {
                                __break(1u);
LABEL_320:
                                v164 = 8;
LABEL_133:
                                v127 = v164 <= BYTE6(v261) ? BYTE6(v261) : v164;
LABEL_136:
                                if ( (v89 & 0x400) == 0 )
                                  break;
                                v160 = 2LL * (unsigned int)v160 + 50LL * v127 + 26;
                                if ( v160 <= 0x2BB )
                                  goto LABEL_141;
                              }
                              if ( (v89 & 0x200) != 0 )
                                break;
                              if ( (v89 & 0x100) == 0 )
                              {
                                v157 = 0;
                                goto LABEL_148;
                              }
                              v160 = 2LL * (unsigned int)v160 + 50LL * v127 + 2;
                              if ( v160 <= 0x2BB )
                              {
LABEL_141:
                                v165 = &v153[v160];
                                v163 = v160;
                                goto LABEL_145;
                              }
                            }
                            v166 = 2LL * (unsigned int)v160;
                            v162 = v166 + 14;
                            v160 = v166 + 14 + 50LL * v127;
                          }
                          while ( v160 > 0x2BB );
                          v153 += 50 * v127;
                          v163 = v166 + 50LL * v127 + 14;
                        }
                        else
                        {
                          v153 += 50 * v127;
                          v163 = v161 + 50LL * v127 + 38;
                        }
                        v165 = &v153[v162];
LABEL_145:
                        if ( v160 > 0x2BA || v163 > 0x2BA )
                          goto LABEL_319;
                        v157 = *(unsigned __int16 *)v165;
                      }
                      else
                      {
                        v157 = 0;
                        v127 = 255;
                      }
LABEL_148:
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: tmprate %d mcsidx %d",
                        v144,
                        v145,
                        v146,
                        v147,
                        v148,
                        v149,
                        v150,
                        v151,
                        "hdd_get_max_rate_he",
                        v157,
                        v127);
                      if ( v139 <= v157 )
                        v167 = v157;
                      else
                        v167 = v139;
                      if ( v127 == 255 )
                        v168 = v139;
                      else
                        v168 = v167;
                      if ( v127 != 255 )
                      {
LABEL_267:
                        v90 = v252;
                        if ( v167 <= v157 )
                          v167 = v157;
                        if ( v167 >= v252 && v167 )
                        {
                          v90 = v167;
                          goto LABEL_281;
                        }
                        v127 = BYTE6(v261);
LABEL_273:
                        v200 = (unsigned __int8)v91 != 3 && (unsigned __int8)v91 != 6;
                        if ( ((v127 > 8) & (v89 >> 5) & *(_DWORD *)&v200) != 0 )
                          v127 = 8;
                        goto LABEL_281;
                      }
                      LODWORD(v250) = v168;
                      if ( (unsigned __int8)v91 == 1 )
                        v169 = (char *)&supported_vht_mcs_rate_nss1_0;
                      else
                        v169 = (char *)&supported_vht_mcs_rate_nss2_0;
                      if ( (v89 & 0x80) != 0 )
                        v156 = 2;
                      else
                        v156 = (v89 >> 6) & 1;
                      if ( (v89 & 0xE0) == 0 )
                      {
                        v157 = 0;
                        v127 = 255;
                        goto LABEL_230;
                      }
                      v139 = SBYTE4(v260);
                      if ( *(_BYTE *)(a2 + 508) )
                      {
                        v127 = 11;
                        goto LABEL_203;
                      }
                      v249 = v169;
                      v170 = *(_BYTE *)(a2 + 158) & 3;
                      if ( (*(_BYTE *)(a2 + 158) & 3) == 0 )
                      {
                        v127 = 7;
LABEL_202:
                        v169 = v249;
LABEL_203:
                        if ( (v251 & 1) == 0 )
                        {
                          v160 = 0;
                          v171 = 56 * v156;
                          if ( (unsigned __int8)v127 >= 0xDuLL )
                            v172 = 13;
                          else
                            v172 = (unsigned __int8)v127;
                          v173 = ~v172;
                          v153 = (char *)rssi_mcs_tbl;
                          while ( 1 )
                          {
                            if ( -(__int64)((unsigned __int64)(-56LL * (int)v156 + 171) >> 2) == v160 || v171 > 0xA7 )
                              goto LABEL_319;
                            if ( rssi_mcs_tbl[v171 / 4] >= (signed int)v139 )
                              break;
                            --v160;
                            v171 += 4LL;
                            if ( v173 == v160 )
                              goto LABEL_214;
                          }
                          v127 = -(int)v160;
LABEL_214:
                          if ( (unsigned __int8)v127 <= (unsigned int)BYTE6(v261) )
                            v127 = BYTE6(v261);
                          else
                            v127 = (unsigned __int8)v127;
                        }
                        v174 = (v89 >> 3) & 1;
                        if ( (v89 & 0x80) != 0 )
                        {
                          v175 = 2 * v174;
                          v176 = 2 * v174 + 2;
                          v177 = 14LL * (unsigned __int8)v127;
                          v160 = v176 + v177;
                          if ( (unsigned __int64)(v176 + v177) > 0xA7 )
                            goto LABEL_319;
                          v153 = &v169[v176];
                          v178 = v177 + v175 + 2;
                        }
                        else if ( (v89 & 0x40) != 0 )
                        {
                          v179 = 2 * v174;
                          v177 = 14LL * (unsigned __int8)v127;
                          v180 = 2 * v174 + 6;
                          v160 = v180 + v177;
                          if ( (unsigned __int64)(v180 + v177) > 0xA7 )
                            goto LABEL_319;
                          v153 = &v169[v180];
                          v178 = v177 + v179 + 6;
                        }
                        else
                        {
                          if ( (v89 & 0x20) == 0 )
                          {
                            v157 = 0;
LABEL_230:
                            qdf_trace_msg(
                              0x33u,
                              8u,
                              "%s: tmprate %d mcsidx %d",
                              v144,
                              v145,
                              v146,
                              v147,
                              v148,
                              v149,
                              v150,
                              v151,
                              "hdd_get_max_rate_vht",
                              v157,
                              (unsigned __int8)v127);
                            if ( (unsigned int)v250 <= v157 )
                              v167 = v157;
                            else
                              v167 = (unsigned int)v250;
                            if ( (unsigned __int8)v127 == 255 )
                              v192 = (unsigned int)v250;
                            else
                              v192 = v167;
                            if ( (unsigned __int8)v127 == 255 )
                            {
                              v193 = *(unsigned __int8 *)(a2 + 155);
                              v194 = SBYTE4(v260);
                              if ( v193 == 255 )
                              {
                                qdf_trace_msg(
                                  0x33u,
                                  2u,
                                  "%s: invalid max_mcs_idx",
                                  v184,
                                  v185,
                                  v186,
                                  v187,
                                  v188,
                                  v189,
                                  v190,
                                  v191,
                                  "hdd_get_max_rate_ht");
                                LOBYTE(v193) = BYTE6(v261);
                              }
                              if ( (v251 & 1) == 0 )
                              {
                                if ( (_BYTE)v193 && (v195 = (v89 >> 2) & 1, rssi_mcs_tbl[14 * v195] < v194) )
                                {
                                  if ( (unsigned __int8)v193 != 1 )
                                  {
                                    if ( rssi_mcs_tbl[14 * v195 + 1] >= v194 )
                                    {
                                      LOBYTE(v193) = 1;
                                    }
                                    else if ( (unsigned __int8)v193 != 2 )
                                    {
                                      if ( rssi_mcs_tbl[14 * v195 + 2] >= v194 )
                                      {
                                        LOBYTE(v193) = 2;
                                      }
                                      else if ( (unsigned __int8)v193 != 3 )
                                      {
                                        if ( rssi_mcs_tbl[14 * v195 + 3] >= v194 )
                                        {
                                          LOBYTE(v193) = 3;
                                        }
                                        else if ( (unsigned __int8)v193 != 4 )
                                        {
                                          if ( rssi_mcs_tbl[14 * v195 + 4] >= v194 )
                                          {
                                            LOBYTE(v193) = 4;
                                          }
                                          else if ( (unsigned __int8)v193 != 5 )
                                          {
                                            if ( rssi_mcs_tbl[14 * v195 + 5] >= v194 )
                                            {
                                              LOBYTE(v193) = 5;
                                            }
                                            else if ( (unsigned __int8)v193 != 6 && rssi_mcs_tbl[14 * v195 + 6] >= v194 )
                                            {
                                              LOBYTE(v193) = 6;
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                else
                                {
                                  LOBYTE(v193) = 0;
                                }
                                v196 = v193;
                                if ( (unsigned __int8)v193 <= (unsigned int)BYTE6(v261) )
                                  v196 = BYTE6(v261);
                                if ( BYTE6(v261) < 8u )
                                  LOBYTE(v193) = v196;
                              }
                              if ( (unsigned __int8)v193 >= 7u )
                                v127 = 7;
                              else
                                v127 = (unsigned __int8)v193;
                              if ( (unsigned __int8)v91 == 1 )
                                v197 = &supported_mcs_rate_nss1_0;
                              else
                                v197 = &supported_mcs_rate_nss2_0;
                              v198 = (__int64)v197 + 10 * v127 + 2 * ((v89 >> 2) & 3);
                              v157 = *(unsigned __int16 *)(v198 + 2);
                              qdf_trace_msg(
                                0x33u,
                                8u,
                                "%s: tmprate %d mcsidx %d",
                                v184,
                                v185,
                                v186,
                                v187,
                                v188,
                                v189,
                                v190,
                                v191,
                                "hdd_get_max_rate_ht",
                                *(unsigned __int16 *)(v198 + 2),
                                v127);
                              v167 = v192;
                            }
                            goto LABEL_267;
                          }
                          v181 = 2 * v174;
                          v177 = 14LL * (unsigned __int8)v127;
                          v182 = 2 * v174 + 10;
                          v160 = v182 + v177;
                          if ( (unsigned __int64)(v182 + v177) > 0xA7 )
                            goto LABEL_319;
                          v153 = &v169[v182];
                          v178 = v177 + v181 + 10;
                        }
                        v183 = &v153[v177];
                        if ( v160 > 0xA6 || v178 > 0xA6 )
                          goto LABEL_319;
                        v157 = *(unsigned __int16 *)v183;
                        goto LABEL_230;
                      }
                      if ( v170 != 2 )
                      {
                        if ( v170 == 1 )
                        {
                          v127 = 8;
                        }
                        else
                        {
                          qdf_trace_msg(
                            0x33u,
                            2u,
                            "%s: invalid vht_max_mcs",
                            v144,
                            v145,
                            v146,
                            v147,
                            v148,
                            v149,
                            v150,
                            v151,
                            "hdd_get_max_rate_vht");
                          v127 = BYTE6(v261);
                        }
                        goto LABEL_202;
                      }
LABEL_197:
                      if ( (((unsigned __int8)v91 != 6) & ((unsigned __int8)v91 != 3) & (v89 >> 5)) != 0 )
                        v127 = 8;
                      else
                        v127 = 9;
                      goto LABEL_202;
                    }
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: Invalid value for reportMaxLinkSpeed: %u",
                      v128,
                      v129,
                      v130,
                      v131,
                      v132,
                      v133,
                      v134,
                      v135,
                      "hdd_fill_rate_info",
                      (unsigned int)v266);
                  }
                }
                v136 = 0;
                v137 = 0;
                v251 = 1;
                goto LABEL_73;
              }
              goto LABEL_56;
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance",
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            "cdp_host_get_peer_stats");
        }
        v59 = 16;
LABEL_56:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: cdp_host_get_peer_stats failed. error: %u",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "wlan_hdd_fill_station_info",
          v59);
        _qdf_mem_free(v46);
LABEL_57:
        wlan_cfg80211_mc_cp_stats_free_stats_event(v32);
        wlan_objmgr_peer_release_ref(v28, 0x51u, v111, v112, v113, v114, v115, v116, v117, v118);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: exit",
          v119,
          v120,
          v121,
          v122,
          v123,
          v124,
          v125,
          v126,
          "wlan_hdd_get_link_peer_stats_sap");
        result = v254;
        goto LABEL_58;
      }
      wlan_cfg80211_mc_cp_stats_free_stats_event(peer_stats);
      wlan_objmgr_peer_release_ref(v28, 0x51u, v95, v96, v97, v98, v99, v100, v101, v102);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: fail to get peer info from fw",
        v103,
        v104,
        v105,
        v106,
        v107,
        v108,
        v109,
        v110,
        "wlan_hdd_get_link_peer_stats_sap");
      result = 0xFFFFFFFFLL;
    }
    else
    {
      wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 0x51u, v19, v20, v21, v22, v23, v24, v25, v26);
      result = 4294967274LL;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Peer not found with MAC %02x:%02x:%02x:**:**:%02x",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "wlan_hdd_get_link_peer_stats_sap",
      *(unsigned __int8 *)(a2 + 32),
      *(unsigned __int8 *)(a2 + 33),
      *(unsigned __int8 *)(a2 + 34),
      *(unsigned __int8 *)(a2 + 37));
    result = 4294967274LL;
  }
LABEL_58:
  _ReadStatusReg(SP_EL0);
  return result;
}
