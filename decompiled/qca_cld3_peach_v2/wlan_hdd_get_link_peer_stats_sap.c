__int64 __fastcall wlan_hdd_get_link_peer_stats_sap(
        __int64 a1,
        __int64 a2,
        __int64 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 *v14; // x23
  _QWORD *peer_by_mac; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x24
  __int64 v25; // x19
  __int64 peer_stats; // x0
  __int64 v27; // x25
  __int64 v28; // x1
  __int64 v29; // x21
  __int64 v30; // x9
  int v31; // w10
  __int64 v32; // x8
  __int64 v33; // x23
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x24
  _QWORD *context; // x0
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x8
  __int64 (*v54)(void); // x8
  unsigned int v55; // w0
  __int64 v56; // x4
  unsigned __int64 v57; // x8
  __int64 v58; // x24
  unsigned int v59; // w0
  int v60; // w0
  char v61; // w8
  __int64 v62; // x9
  __int64 v63; // x10
  int v64; // w8
  int v65; // w12
  __int64 v66; // x8
  int v67; // w9
  char v68; // w10
  char v69; // w9
  int v70; // w11
  int v71; // w13
  int v72; // w12
  int v73; // w13
  int v74; // w11
  int v75; // w12
  int v76; // w13
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  unsigned int v85; // w25
  unsigned int v86; // w26
  unsigned int v87; // w28
  unsigned int v88; // w24
  bool is_link_speed_report_actual; // w0
  unsigned int v90; // w8
  __int64 result; // x0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  unsigned int v124; // w27
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  _BOOL4 v133; // w27
  unsigned int v134; // w12
  unsigned __int8 v135; // w8
  unsigned int v136; // w28
  unsigned int v137; // w9
  unsigned __int8 v138; // w10
  int v139; // kr00_4
  unsigned __int16 *v140; // x8
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  unsigned int v149; // w8
  char *v150; // x12
  unsigned __int64 v151; // x11
  int v152; // w14
  __int64 v153; // x25
  unsigned int v154; // w25
  int v155; // w8
  unsigned __int64 v156; // x27
  unsigned __int64 v157; // x8
  __int64 v158; // x11
  __int64 v159; // x9
  unsigned __int64 v160; // x10
  unsigned int v161; // w10
  char *v162; // x9
  __int64 v163; // x11
  unsigned int v164; // w8
  unsigned int v165; // w9
  char *v166; // x14
  int v167; // w8
  unsigned __int64 v168; // x9
  __int64 v169; // x11
  __int64 v170; // x11
  __int64 v171; // x8
  __int64 v172; // x11
  __int64 v173; // x10
  __int64 v174; // x9
  unsigned __int64 v175; // x10
  __int64 v176; // x11
  __int64 v177; // x10
  __int64 v178; // x11
  __int64 v179; // x10
  char *v180; // x9
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  unsigned int v189; // w28
  int v190; // w8
  int v191; // w25
  int v192; // w9
  char v193; // w10
  void *v194; // x9
  __int64 v195; // x8
  bool v197; // w8
  unsigned int v198; // w26
  unsigned int v199; // w25
  bool v200; // w0
  unsigned int v201; // w8
  bool v202; // w0
  bool v204; // w9
  __int64 v205; // x9
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  double v214; // d0
  double v215; // d1
  double v216; // d2
  double v217; // d3
  double v218; // d4
  double v219; // d5
  double v220; // d6
  double v221; // d7
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  double v238; // d0
  double v239; // d1
  double v240; // d2
  double v241; // d3
  double v242; // d4
  double v243; // d5
  double v244; // d6
  double v245; // d7
  char *v246; // [xsp+8h] [xbp-98h]
  char *v247; // [xsp+10h] [xbp-90h]
  char v248; // [xsp+1Ch] [xbp-84h]
  unsigned int v249; // [xsp+20h] [xbp-80h]
  unsigned int v250; // [xsp+28h] [xbp-78h]
  unsigned int v251; // [xsp+2Ch] [xbp-74h] BYREF
  __int64 v252; // [xsp+30h] [xbp-70h] BYREF
  __int64 v253; // [xsp+38h] [xbp-68h]
  __int64 v254; // [xsp+40h] [xbp-60h]
  __int64 v255; // [xsp+48h] [xbp-58h]
  unsigned __int64 v256; // [xsp+50h] [xbp-50h]
  __int64 v257; // [xsp+58h] [xbp-48h]
  __int64 v258; // [xsp+60h] [xbp-40h]
  __int64 v259; // [xsp+68h] [xbp-38h]
  __int64 v260; // [xsp+70h] [xbp-30h]
  __int64 v261; // [xsp+78h] [xbp-28h]
  __int64 v262; // [xsp+80h] [xbp-20h]
  __int64 v263; // [xsp+88h] [xbp-18h] BYREF
  _QWORD v264[2]; // [xsp+90h] [xbp-10h] BYREF

  v264[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = *(__int64 **)(a1 + 24);
  v261 = 0;
  v262 = 0;
  v259 = 0;
  v260 = 0;
  v257 = 0;
  v258 = 0;
  v255 = 0;
  v256 = 0;
  v253 = 0;
  v254 = 0;
  v252 = 0;
  v251 = 0;
  qdf_trace_msg(0x33u, 8u, "%s: enter", a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_get_link_peer_stats_sap");
  peer_by_mac = wlan_objmgr_get_peer_by_mac(**(_QWORD **)(a1 + 24), (_BYTE *)(a2 + 32), 0x51u);
  if ( peer_by_mac )
  {
    v24 = peer_by_mac[12];
    if ( v24 )
    {
      v25 = (__int64)peer_by_mac;
      peer_stats = wlan_cfg80211_mc_cp_stats_get_peer_stats(peer_by_mac[12], a2 + 32, &v251);
      if ( !v251 && peer_stats )
      {
        v27 = peer_stats;
        *(_DWORD *)(a2 + 436) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 72LL);
        *(_DWORD *)(a2 + 440) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 76LL);
        *(_DWORD *)(a2 + 444) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 80LL);
        *(_DWORD *)(a2 + 448) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 84LL);
        *(_DWORD *)(a2 + 452) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 88LL);
        *(_DWORD *)(a2 + 456) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 92LL);
        *(_DWORD *)(a2 + 460) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 96LL);
        *(_DWORD *)(a2 + 464) = *(_DWORD *)(*(_QWORD *)(peer_stats + 160) + 100LL);
        qdf_mem_set(&v252, 0x58u, 0);
        v28 = *(_QWORD *)(v27 + 160);
        v29 = v27;
        v30 = *(_QWORD *)(v28 + 16);
        v31 = *(_DWORD *)(v28 + 24);
        LODWORD(v252) = *(_DWORD *)(v28 + 8);
        v32 = *(_QWORD *)(v28 + 32);
        v253 = v30;
        v255 = v32;
        LODWORD(v30) = *(_DWORD *)(v28 + 40);
        LODWORD(v32) = *(_DWORD *)(v28 + 44);
        LODWORD(v254) = v31;
        v256 = __PAIR64__(v32, v30);
        LODWORD(v32) = *(_DWORD *)(v28 + 52);
        LODWORD(v257) = *(_DWORD *)(v28 + 48);
        BYTE4(v257) = v32;
        wlan_hdd_fill_rate_info((__int64)&v252, (_DWORD *)v28);
        if ( !hdd_get_link_info_by_vdev((__int64)v14, *(unsigned __int8 *)(v24 + 168)) )
          goto LABEL_47;
        v33 = *v14;
        v34 = _qdf_mem_malloc(0x11C0u, "wlan_hdd_fill_station_info", 6826);
        if ( !v34 )
          goto LABEL_47;
        v43 = v34;
        context = _cds_get_context(71, (__int64)"wlan_hdd_fill_station_info", v35, v36, v37, v38, v39, v40, v41, v42);
        if ( context && *context )
        {
          v53 = *(_QWORD *)(*context + 32LL);
          if ( v53 )
          {
            v54 = *(__int64 (**)(void))(v53 + 144);
            if ( v54 )
            {
              if ( *((_DWORD *)v54 - 1) != -1642106733 )
                __break(0x8228u);
              v55 = v54();
              v56 = v55;
              if ( !v55 )
              {
                v57 = *(_QWORD *)(v43 + 1840);
                if ( v57 <= *(_QWORD *)(v43 + 3064) )
                  v57 = *(_QWORD *)(v43 + 3064);
                *(_QWORD *)(a2 + 104) = v57;
                _qdf_mem_free(v43);
                v58 = jiffies;
                v59 = jiffies_to_msecs(jiffies - *(_QWORD *)(a2 + 112));
                *a3 |= 0x10000uLL;
                *((_DWORD *)a3 + 2) = v59 / 0x3E8;
                v60 = jiffies_to_msecs(v58 - *(_QWORD *)(a2 + 104));
                v61 = BYTE4(v257);
                v62 = v253;
                v63 = v255;
                *((_DWORD *)a3 + 3) = v60;
                *((_BYTE *)a3 + 45) = v61;
                v64 = v252;
                v65 = *((_DWORD *)a3 + 28);
                a3[3] = v63;
                a3[4] = v62;
                *((_DWORD *)a3 + 21) = v254;
                *((_DWORD *)a3 + 22) = v64;
                v66 = *a3;
                LODWORD(v63) = HIDWORD(v256);
                *((_DWORD *)a3 + 23) = v256;
                *((_DWORD *)a3 + 24) = v63;
                *a3 = v66 | 0x1801E8E;
                *((_DWORD *)a3 + 27) = 3;
                if ( *(_BYTE *)(a2 + 48) )
                  v67 = 3;
                else
                  v67 = 0;
                *((_DWORD *)a3 + 28) = v65 & 0xFFFFFFFC | v67;
                v68 = *((_BYTE *)a3 + 47);
                *a3 = v66 | 0x1821E8E;
                v69 = 0x80;
                *((_BYTE *)a3 + 46) = 0x80;
                v70 = *(unsigned __int8 *)(a2 + 436);
                *((_BYTE *)a3 + 47) = v68 | 1;
                *((_BYTE *)a3 + 52) = v70;
                if ( (v70 & 0x7F) != 0 )
                {
                  v69 = v70;
                  *((_BYTE *)a3 + 46) = v70;
                }
                v71 = *(char *)(a2 + 440);
                *((_BYTE *)a3 + 47) = v68 | 3;
                v72 = (unsigned __int8)v71;
                *((_BYTE *)a3 + 53) = v71;
                if ( v71 && v69 < v71 )
                {
                  v69 = v71;
                  *((_BYTE *)a3 + 46) = v71;
                }
                v73 = *(char *)(a2 + 444);
                v74 = v72 | v70;
                *((_BYTE *)a3 + 47) = v68 | 7;
                v75 = (unsigned __int8)v73;
                *((_BYTE *)a3 + 54) = v73;
                if ( v73 && v69 < v73 )
                {
                  v69 = v73;
                  *((_BYTE *)a3 + 46) = v73;
                }
                v76 = *(char *)(a2 + 448);
                *((_BYTE *)a3 + 47) = v68 | 0xF;
                *((_BYTE *)a3 + 55) = v76;
                if ( v76 && v69 < v76 )
                  *((_BYTE *)a3 + 46) = v76;
                if ( v74 | v75 | (unsigned __int8)v76 )
                  *a3 = v66 | 0x5823E8E;
                v263 = 0;
                v264[0] = 0;
                ucfg_mlme_stats_get_cfg_values(v33, (_DWORD *)v264 + 1, v264, (_DWORD *)&v263 + 1, &v263);
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: reportMaxLinkSpeed %d",
                  v77,
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  v83,
                  v84,
                  "hdd_fill_rate_info",
                  (unsigned int)v263);
                v85 = v258;
                v86 = *(_DWORD *)(a2 + 52);
                v87 = (unsigned int)v258 / 0x64;
                if ( (v86 & 1) != 0 )
                {
                  v88 = 1;
                }
                else
                {
                  v88 = *(unsigned __int8 *)(a2 + 50);
                  is_link_speed_report_actual = ucfg_mlme_stats_is_link_speed_report_actual(v33);
                  v90 = v259;
                  if ( !(_DWORD)v259 )
                    v90 = v86;
                  if ( is_link_speed_report_actual )
                    v88 = BYTE5(v258);
                  else
                    v90 = v86;
                  if ( BYTE6(v258) == 255 )
                    v86 = 1;
                  else
                    v86 = v90;
                }
                if ( ucfg_mlme_stats_is_link_speed_report_actual(v33) )
                {
                  if ( (v86 & 1) != 0 )
                  {
                    v250 = 0;
                    v124 = 255;
                  }
                  else
                  {
                    v124 = BYTE6(v258);
                    v250 = 0;
                  }
                  goto LABEL_271;
                }
                v249 = v87;
                if ( (ucfg_mlme_stats_is_link_speed_report_max(v33) & 1) == 0 )
                {
                  if ( (ucfg_mlme_stats_is_link_speed_report_max_scaled(v33) & 1) != 0 )
                  {
                    if ( SHIDWORD(v264[0]) > SBYTE4(v257) )
                    {
                      if ( SLODWORD(v264[0]) <= SBYTE4(v257) )
                      {
                        v133 = 0;
                        v248 = 0;
                        v134 = 1;
                      }
                      else
                      {
                        v248 = 0;
                        v133 = SHIDWORD(v263) > SBYTE4(v257);
                        if ( SHIDWORD(v263) <= SBYTE4(v257) )
                          v134 = 2;
                        else
                          v134 = 3;
                      }
LABEL_63:
                      v135 = *(_BYTE *)(a2 + 153);
                      v136 = 0;
                      if ( (unsigned __int8)(v135 - 13) >= 0xF2u )
                        v135 = 12;
                      v137 = *(unsigned __int8 *)(a2 + 154);
                      v138 = v135;
                      if ( v135 <= v137 )
                        v138 = *(_BYTE *)(a2 + 154);
                      if ( v137 != 255 )
                        v135 = v138;
                      v139 = v135 - 2;
                      v140 = (unsigned __int16 *)&unk_AFACCA;
                      switch ( v139 )
                      {
                        case 0:
                          goto LABEL_83;
                        case 2:
                          v140 = (unsigned __int16 *)&unk_AFACD4;
                          goto LABEL_83;
                        case 9:
                          v140 = (unsigned __int16 *)&unk_AFACDE;
                          goto LABEL_83;
                        case 10:
                          v140 = (unsigned __int16 *)&unk_AFACE8;
                          goto LABEL_83;
                        case 16:
                          v140 = (unsigned __int16 *)&unk_AFACF2;
                          goto LABEL_83;
                        case 20:
                          v140 = (unsigned __int16 *)&unk_AFACFC;
                          goto LABEL_83;
                        case 22:
                          v140 = (unsigned __int16 *)&unk_AFAD06;
                          goto LABEL_83;
                        case 34:
                          v140 = (unsigned __int16 *)&unk_AFAD10;
                          goto LABEL_83;
                        case 42:
                          v140 = (unsigned __int16 *)&unk_AFAD1A;
                          goto LABEL_83;
                        case 46:
                          v140 = (unsigned __int16 *)&unk_AFAD24;
                          goto LABEL_83;
                        case 64:
                          v140 = (unsigned __int16 *)&unk_AFAD2E;
                          goto LABEL_83;
                        case 70:
                          v140 = (unsigned __int16 *)&unk_AFAD38;
                          goto LABEL_83;
                        case 94:
                          v140 = (unsigned __int16 *)&unk_AFAD42;
                          goto LABEL_83;
                        case 106:
                          v140 = (unsigned __int16 *)&unk_AFAD4C;
LABEL_83:
                          v136 = v140[v134];
                          break;
                        default:
                          break;
                      }
                      v250 = v134;
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: maxrate %d",
                        v125,
                        v126,
                        v127,
                        v128,
                        v129,
                        v130,
                        v131,
                        v132,
                        "hdd_get_max_rate_legacy",
                        v136);
                      if ( ((v133 | v86) & 1) != 0 )
                      {
                        if ( (v86 & 1) != 0 )
                        {
                          v124 = 255;
                          if ( v136 <= v249 )
                            v149 = v249;
                          else
                            v149 = v136;
                          if ( v136 )
                            v87 = v149;
                          else
                            v87 = v249;
                          goto LABEL_271;
                        }
                        v124 = BYTE6(v258);
                        v87 = v249;
                        if ( v85 >= 0x64 )
                        {
LABEL_271:
                          hdd_fill_sinfo_rate_info(a3, v86, v124, v88, v87, 1, HIDWORD(v259));
                          v198 = *(_DWORD *)(a2 + 52);
                          v199 = HIDWORD(v260) / 0x64;
                          if ( (v198 & 1) == 0 )
                          {
                            v88 = *(unsigned __int8 *)(a2 + 50);
                            v200 = ucfg_mlme_stats_is_link_speed_report_actual(v33);
                            v201 = HIDWORD(v261);
                            if ( !HIDWORD(v261) )
                              v201 = v198;
                            if ( v200 )
                              v88 = BYTE1(v261);
                            else
                              v201 = v198;
                            if ( BYTE2(v261) == 255 )
                              v198 = 1;
                            else
                              v198 = v201;
                          }
                          v202 = ucfg_mlme_stats_is_link_speed_report_actual(v33);
                          if ( v250 == 3 || v202 )
                          {
                            if ( (v198 & 1) == 0 )
                              v124 = BYTE2(v261);
                          }
                          else if ( v87 && v87 >= v199 )
                          {
                            v199 = v87;
                          }
                          else if ( (v198 & 1) == 0 )
                          {
                            v204 = (unsigned __int8)v88 != 3 && (unsigned __int8)v88 != 6;
                            if ( ((BYTE2(v261) > 8u) & (v198 >> 5) & *(_DWORD *)&v204) != 0 )
                              v124 = 8;
                            else
                              v124 = BYTE2(v261);
                          }
                          hdd_fill_sinfo_rate_info(a3, v198, v124, v88, v199, 0, (unsigned int)v262);
                          v205 = *a3;
                          *((_DWORD *)a3 + 41) = *(_DWORD *)(a2 + 68);
                          *a3 = v205 | 0x8000000;
                          a3[15] = *(_QWORD *)(a2 + 272);
                          a3[16] = *(unsigned int *)(a2 + 264);
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: dump stainfo",
                            v206,
                            v207,
                            v208,
                            v209,
                            v210,
                            v211,
                            v212,
                            v213,
                            "wlan_hdd_fill_station_info");
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: con_time %d inact_time %d tx_pkts %d rx_pkts %d",
                            v214,
                            v215,
                            v216,
                            v217,
                            v218,
                            v219,
                            v220,
                            v221,
                            "wlan_hdd_fill_station_info",
                            *((unsigned int *)a3 + 2),
                            *((unsigned int *)a3 + 3),
                            *((unsigned int *)a3 + 22),
                            *((unsigned int *)a3 + 21));
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: failed %d retries %d tx_bytes %lld rx_bytes %lld",
                            v222,
                            v223,
                            v224,
                            v225,
                            v226,
                            v227,
                            v228,
                            v229,
                            "wlan_hdd_fill_station_info",
                            *((unsigned int *)a3 + 24),
                            *((unsigned int *)a3 + 23),
                            a3[4],
                            a3[3]);
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: rssi %d tx mcs %d legacy %d nss %d flags %x",
                            v230,
                            v231,
                            v232,
                            v233,
                            v234,
                            v235,
                            v236,
                            v237,
                            "wlan_hdd_fill_station_info",
                            (unsigned int)*((char *)a3 + 45),
                            *((unsigned __int8 *)a3 + 60),
                            *((unsigned __int16 *)a3 + 29),
                            *((unsigned __int8 *)a3 + 61),
                            *((unsigned __int16 *)a3 + 28));
                          qdf_trace_msg(
                            0x33u,
                            8u,
                            "%s: rx mcs %d legacy %d nss %d flags %x",
                            v238,
                            v239,
                            v240,
                            v241,
                            v242,
                            v243,
                            v244,
                            v245,
                            "wlan_hdd_fill_station_info",
                            *((unsigned __int8 *)a3 + 74),
                            *((unsigned __int16 *)a3 + 36),
                            *((unsigned __int8 *)a3 + 75),
                            *((unsigned __int16 *)a3 + 35));
                          goto LABEL_47;
                        }
                        goto LABEL_263;
                      }
                      if ( (unsigned __int8)v88 == 1 )
                        v150 = (char *)&supported_he_mcs_rate_nss1_0;
                      else
                        v150 = (char *)&supported_he_mcs_rate_nss2_0;
                      if ( (v86 & 0x800) != 0 )
                      {
                        v151 = 3;
                      }
                      else if ( (v86 & 0x400) != 0 )
                      {
                        v151 = 2;
                      }
                      else
                      {
                        v151 = (v86 >> 9) & 1;
                      }
                      if ( (v86 & 0xF00) != 0 )
                      {
                        v152 = SBYTE4(v257);
                        v153 = 2;
                        if ( *(_WORD *)(a2 + 510) )
                        {
                          v124 = 13;
                        }
                        else
                        {
                          v155 = *(_BYTE *)(a2 + 158) & 3;
                          if ( v155 == 3 )
                          {
                            v247 = v150;
                            v156 = v151;
                            LODWORD(v246) = SBYTE4(v257);
                            qdf_trace_msg(
                              0x33u,
                              2u,
                              "%s: invalid he_max_mcs",
                              v141,
                              v142,
                              v143,
                              v144,
                              v145,
                              v146,
                              v147,
                              v148,
                              "hdd_get_max_rate_he");
                            v152 = (int)v246;
                            v151 = v156;
                            v150 = v247;
                            v124 = BYTE6(v258);
                          }
                          else
                          {
                            v124 = v155 + 9;
                          }
                        }
                        LODWORD(v157) = ~(v86 >> 2) & 2;
                        if ( (v248 & 1) == 0 )
                        {
                          if ( (v86 & 0x800) == 0 )
                          {
                            if ( v151 == 3 )
                              goto LABEL_309;
                            v161 = 0;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151] >= v152 || !v124 )
                              goto LABEL_123;
                            if ( ((56 * v151) | 4) > 0xA8 )
                              goto LABEL_309;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 1] >= v152 )
                            {
                              v161 = 1;
                              goto LABEL_123;
                            }
                            if ( v124 == 1 )
                              goto LABEL_121;
                            if ( v151 > 2 )
                              goto LABEL_309;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 2] >= v152 )
                            {
                              v161 = 2;
                              goto LABEL_123;
                            }
                            if ( v124 == 2 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 3] >= v152 )
                            {
                              v161 = 3;
                              goto LABEL_123;
                            }
                            if ( v124 == 3 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 4] >= v152 )
                            {
                              v161 = 4;
                              goto LABEL_123;
                            }
                            if ( v124 == 4 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 5] >= v152 )
                            {
                              v161 = 5;
                              goto LABEL_123;
                            }
                            if ( v124 == 5 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 6] >= v152 )
                            {
                              v161 = 6;
                              goto LABEL_123;
                            }
                            if ( v124 == 6 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 7] >= v152 )
                            {
                              v161 = 7;
                              goto LABEL_123;
                            }
                            if ( v124 == 7 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 8] >= v152 )
                              goto LABEL_310;
                            if ( v124 == 8 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 9] >= v152 )
                            {
                              v161 = 9;
                              goto LABEL_123;
                            }
                            if ( v124 == 9 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 10] >= v152 )
                            {
                              v161 = 10;
                              goto LABEL_123;
                            }
                            if ( v124 == 10 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 11] >= v152 )
                            {
                              v161 = 11;
                              goto LABEL_123;
                            }
                            if ( v124 == 11 )
                              goto LABEL_121;
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 12] >= v152 )
                            {
                              v161 = 12;
                              goto LABEL_123;
                            }
                            if ( v124 == 12 )
                            {
LABEL_121:
                              v161 = v124;
                              goto LABEL_123;
                            }
                            if ( rssi_mcs_tbl[14 * (unsigned int)v151 + 13] >= v152 )
                            {
                              v161 = 13;
                              goto LABEL_123;
                            }
                            v161 = v124;
                            if ( v124 == 13 )
                              goto LABEL_123;
                          }
                          __break(0x5512u);
                          goto LABEL_187;
                        }
                        if ( (v86 & 0x800) == 0 )
                          goto LABEL_126;
                        v158 = 2LL * (~(v86 >> 2) & 2);
                        v159 = v158 + 38;
                        v157 = v158 + 38 + 50LL * v124;
                        if ( v157 > 0x2BB )
                        {
                          do
                          {
                            while ( 1 )
                            {
LABEL_309:
                              while ( 1 )
                              {
                                __break(1u);
LABEL_310:
                                v161 = 8;
LABEL_123:
                                v124 = v161 <= BYTE6(v258) ? BYTE6(v258) : v161;
LABEL_126:
                                if ( (v86 & 0x400) == 0 )
                                  break;
                                v157 = 2LL * (unsigned int)v157 + 50LL * v124 + 26;
                                if ( v157 <= 0x2BB )
                                  goto LABEL_131;
                              }
                              if ( (v86 & 0x200) != 0 )
                                break;
                              if ( (v86 & 0x100) == 0 )
                              {
                                v154 = 0;
                                goto LABEL_138;
                              }
                              v157 = 2LL * (unsigned int)v157 + 50LL * v124 + 2;
                              if ( v157 <= 0x2BB )
                              {
LABEL_131:
                                v162 = &v150[v157];
                                v160 = v157;
                                goto LABEL_135;
                              }
                            }
                            v163 = 2LL * (unsigned int)v157;
                            v159 = v163 + 14;
                            v157 = v163 + 14 + 50LL * v124;
                          }
                          while ( v157 > 0x2BB );
                          v150 += 50 * v124;
                          v160 = v163 + 50LL * v124 + 14;
                        }
                        else
                        {
                          v150 += 50 * v124;
                          v160 = v158 + 50LL * v124 + 38;
                        }
                        v162 = &v150[v159];
LABEL_135:
                        if ( v157 > 0x2BA || v160 > 0x2BA )
                          goto LABEL_309;
                        v154 = *(unsigned __int16 *)v162;
                      }
                      else
                      {
                        v154 = 0;
                        v124 = 255;
                      }
LABEL_138:
                      qdf_trace_msg(
                        0x33u,
                        8u,
                        "%s: tmprate %d mcsidx %d",
                        v141,
                        v142,
                        v143,
                        v144,
                        v145,
                        v146,
                        v147,
                        v148,
                        "hdd_get_max_rate_he",
                        v154,
                        v124);
                      if ( v136 <= v154 )
                        v164 = v154;
                      else
                        v164 = v136;
                      if ( v124 == 255 )
                        v165 = v136;
                      else
                        v165 = v164;
                      if ( v124 != 255 )
                      {
LABEL_257:
                        v87 = v249;
                        if ( v164 <= v154 )
                          v164 = v154;
                        if ( v164 >= v249 && v164 )
                        {
                          v87 = v164;
                          goto LABEL_271;
                        }
                        v124 = BYTE6(v258);
LABEL_263:
                        v197 = (unsigned __int8)v88 != 3 && (unsigned __int8)v88 != 6;
                        if ( ((v124 > 8) & (v86 >> 5) & *(_DWORD *)&v197) != 0 )
                          v124 = 8;
                        goto LABEL_271;
                      }
                      LODWORD(v247) = v165;
                      if ( (unsigned __int8)v88 == 1 )
                        v166 = (char *)&supported_vht_mcs_rate_nss1_0;
                      else
                        v166 = (char *)&supported_vht_mcs_rate_nss2_0;
                      if ( (v86 & 0x80) != 0 )
                        v153 = 2;
                      else
                        v153 = (v86 >> 6) & 1;
                      if ( (v86 & 0xE0) == 0 )
                      {
                        v154 = 0;
                        v124 = 255;
                        goto LABEL_220;
                      }
                      v136 = SBYTE4(v257);
                      if ( *(_BYTE *)(a2 + 508) )
                      {
                        v124 = 11;
                        goto LABEL_193;
                      }
                      v246 = v166;
                      v167 = *(_BYTE *)(a2 + 158) & 3;
                      if ( (*(_BYTE *)(a2 + 158) & 3) == 0 )
                      {
                        v124 = 7;
LABEL_192:
                        v166 = v246;
LABEL_193:
                        if ( (v248 & 1) == 0 )
                        {
                          v157 = 0;
                          v168 = 56 * v153;
                          if ( (unsigned __int8)v124 >= 0xDuLL )
                            v169 = 13;
                          else
                            v169 = (unsigned __int8)v124;
                          v170 = ~v169;
                          v150 = (char *)rssi_mcs_tbl;
                          while ( 1 )
                          {
                            if ( -(__int64)((unsigned __int64)(-56LL * (int)v153 + 171) >> 2) == v157 || v168 > 0xA7 )
                              goto LABEL_309;
                            if ( rssi_mcs_tbl[v168 / 4] >= (signed int)v136 )
                              break;
                            --v157;
                            v168 += 4LL;
                            if ( v170 == v157 )
                              goto LABEL_204;
                          }
                          v124 = -(int)v157;
LABEL_204:
                          if ( (unsigned __int8)v124 <= (unsigned int)BYTE6(v258) )
                            v124 = BYTE6(v258);
                          else
                            v124 = (unsigned __int8)v124;
                        }
                        v171 = (v86 >> 3) & 1;
                        if ( (v86 & 0x80) != 0 )
                        {
                          v172 = 2 * v171;
                          v173 = 2 * v171 + 2;
                          v174 = 14LL * (unsigned __int8)v124;
                          v157 = v173 + v174;
                          if ( (unsigned __int64)(v173 + v174) > 0xA7 )
                            goto LABEL_309;
                          v150 = &v166[v173];
                          v175 = v174 + v172 + 2;
                        }
                        else if ( (v86 & 0x40) != 0 )
                        {
                          v176 = 2 * v171;
                          v174 = 14LL * (unsigned __int8)v124;
                          v177 = 2 * v171 + 6;
                          v157 = v177 + v174;
                          if ( (unsigned __int64)(v177 + v174) > 0xA7 )
                            goto LABEL_309;
                          v150 = &v166[v177];
                          v175 = v174 + v176 + 6;
                        }
                        else
                        {
                          if ( (v86 & 0x20) == 0 )
                          {
                            v154 = 0;
LABEL_220:
                            qdf_trace_msg(
                              0x33u,
                              8u,
                              "%s: tmprate %d mcsidx %d",
                              v141,
                              v142,
                              v143,
                              v144,
                              v145,
                              v146,
                              v147,
                              v148,
                              "hdd_get_max_rate_vht",
                              v154,
                              (unsigned __int8)v124);
                            if ( (unsigned int)v247 <= v154 )
                              v164 = v154;
                            else
                              v164 = (unsigned int)v247;
                            if ( (unsigned __int8)v124 == 255 )
                              v189 = (unsigned int)v247;
                            else
                              v189 = v164;
                            if ( (unsigned __int8)v124 == 255 )
                            {
                              v190 = *(unsigned __int8 *)(a2 + 155);
                              v191 = SBYTE4(v257);
                              if ( v190 == 255 )
                              {
                                qdf_trace_msg(
                                  0x33u,
                                  2u,
                                  "%s: invalid max_mcs_idx",
                                  v181,
                                  v182,
                                  v183,
                                  v184,
                                  v185,
                                  v186,
                                  v187,
                                  v188,
                                  "hdd_get_max_rate_ht");
                                LOBYTE(v190) = BYTE6(v258);
                              }
                              if ( (v248 & 1) == 0 )
                              {
                                if ( (_BYTE)v190 && (v192 = (v86 >> 2) & 1, rssi_mcs_tbl[14 * v192] < v191) )
                                {
                                  if ( (unsigned __int8)v190 != 1 )
                                  {
                                    if ( rssi_mcs_tbl[14 * v192 + 1] >= v191 )
                                    {
                                      LOBYTE(v190) = 1;
                                    }
                                    else if ( (unsigned __int8)v190 != 2 )
                                    {
                                      if ( rssi_mcs_tbl[14 * v192 + 2] >= v191 )
                                      {
                                        LOBYTE(v190) = 2;
                                      }
                                      else if ( (unsigned __int8)v190 != 3 )
                                      {
                                        if ( rssi_mcs_tbl[14 * v192 + 3] >= v191 )
                                        {
                                          LOBYTE(v190) = 3;
                                        }
                                        else if ( (unsigned __int8)v190 != 4 )
                                        {
                                          if ( rssi_mcs_tbl[14 * v192 + 4] >= v191 )
                                          {
                                            LOBYTE(v190) = 4;
                                          }
                                          else if ( (unsigned __int8)v190 != 5 )
                                          {
                                            if ( rssi_mcs_tbl[14 * v192 + 5] >= v191 )
                                            {
                                              LOBYTE(v190) = 5;
                                            }
                                            else if ( (unsigned __int8)v190 != 6 && rssi_mcs_tbl[14 * v192 + 6] >= v191 )
                                            {
                                              LOBYTE(v190) = 6;
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                                else
                                {
                                  LOBYTE(v190) = 0;
                                }
                                v193 = v190;
                                if ( (unsigned __int8)v190 <= (unsigned int)BYTE6(v258) )
                                  v193 = BYTE6(v258);
                                if ( BYTE6(v258) < 8u )
                                  LOBYTE(v190) = v193;
                              }
                              if ( (unsigned __int8)v190 >= 7u )
                                v124 = 7;
                              else
                                v124 = (unsigned __int8)v190;
                              if ( (unsigned __int8)v88 == 1 )
                                v194 = &supported_mcs_rate_nss1_0;
                              else
                                v194 = &supported_mcs_rate_nss2_0;
                              v195 = (__int64)v194 + 10 * v124 + 2 * ((v86 >> 2) & 3);
                              v154 = *(unsigned __int16 *)(v195 + 2);
                              qdf_trace_msg(
                                0x33u,
                                8u,
                                "%s: tmprate %d mcsidx %d",
                                v181,
                                v182,
                                v183,
                                v184,
                                v185,
                                v186,
                                v187,
                                v188,
                                "hdd_get_max_rate_ht",
                                *(unsigned __int16 *)(v195 + 2),
                                v124);
                              v164 = v189;
                            }
                            goto LABEL_257;
                          }
                          v178 = 2 * v171;
                          v174 = 14LL * (unsigned __int8)v124;
                          v179 = 2 * v171 + 10;
                          v157 = v179 + v174;
                          if ( (unsigned __int64)(v179 + v174) > 0xA7 )
                            goto LABEL_309;
                          v150 = &v166[v179];
                          v175 = v174 + v178 + 10;
                        }
                        v180 = &v150[v174];
                        if ( v157 > 0xA6 || v175 > 0xA6 )
                          goto LABEL_309;
                        v154 = *(unsigned __int16 *)v180;
                        goto LABEL_220;
                      }
                      if ( v167 != 2 )
                      {
                        if ( v167 == 1 )
                        {
                          v124 = 8;
                        }
                        else
                        {
                          qdf_trace_msg(
                            0x33u,
                            2u,
                            "%s: invalid vht_max_mcs",
                            v141,
                            v142,
                            v143,
                            v144,
                            v145,
                            v146,
                            v147,
                            v148,
                            "hdd_get_max_rate_vht");
                          v124 = BYTE6(v258);
                        }
                        goto LABEL_192;
                      }
LABEL_187:
                      if ( (((unsigned __int8)v88 != 6) & ((unsigned __int8)v88 != 3) & (v86 >> 5)) != 0 )
                        v124 = 8;
                      else
                        v124 = 9;
                      goto LABEL_192;
                    }
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x33u,
                      2u,
                      "%s: Invalid value for reportMaxLinkSpeed: %u",
                      v125,
                      v126,
                      v127,
                      v128,
                      v129,
                      v130,
                      v131,
                      v132,
                      "hdd_fill_rate_info",
                      (unsigned int)v263);
                  }
                }
                v133 = 0;
                v134 = 0;
                v248 = 1;
                goto LABEL_63;
              }
              goto LABEL_46;
            }
          }
        }
        else
        {
          qdf_trace_msg(
            0x89u,
            8u,
            "%s: Invalid Instance",
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            "cdp_host_get_peer_stats");
        }
        v56 = 16;
LABEL_46:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: cdp_host_get_peer_stats failed. error: %u",
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          "wlan_hdd_fill_station_info",
          v56);
        _qdf_mem_free(v43);
LABEL_47:
        wlan_cfg80211_mc_cp_stats_free_stats_event(v29);
        wlan_objmgr_peer_release_ref(v25, 0x51u, v108, v109, v110, v111, v112, v113, v114, v115);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: exit",
          v116,
          v117,
          v118,
          v119,
          v120,
          v121,
          v122,
          v123,
          "wlan_hdd_get_link_peer_stats_sap");
        result = v251;
        goto LABEL_48;
      }
      wlan_cfg80211_mc_cp_stats_free_stats_event(peer_stats);
      wlan_objmgr_peer_release_ref(v25, 0x51u, v92, v93, v94, v95, v96, v97, v98, v99);
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: fail to get peer info from fw",
        v100,
        v101,
        v102,
        v103,
        v104,
        v105,
        v106,
        v107,
        "wlan_hdd_get_link_peer_stats_sap");
      result = 0xFFFFFFFFLL;
    }
    else
    {
      wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 0x51u, v16, v17, v18, v19, v20, v21, v22, v23);
      result = 4294967274LL;
    }
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Peer not found with MAC %02x:%02x:%02x:**:**:%02x",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "wlan_hdd_get_link_peer_stats_sap",
      *(unsigned __int8 *)(a2 + 32),
      *(unsigned __int8 *)(a2 + 33),
      *(unsigned __int8 *)(a2 + 34),
      *(unsigned __int8 *)(a2 + 37));
    result = 4294967274LL;
  }
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
