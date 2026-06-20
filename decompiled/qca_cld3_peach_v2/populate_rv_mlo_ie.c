__int64 __fastcall populate_rv_mlo_ie(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // x0
  __int64 v14; // x8
  __int64 v15; // x20
  _QWORD *context; // x0
  __int64 v18; // x23
  _BYTE *v19; // x26
  __int16 v20; // w21
  __int16 v21; // w8
  char v22; // w8
  __int16 v23; // w9
  __int16 v24; // w11
  __int16 v25; // w10
  char v26; // w9
  _DWORD *v27; // x9
  unsigned int v28; // w10
  _DWORD *v29; // x8
  unsigned int v30; // w9
  __int16 v31; // w10
  char v32; // w9
  char v33; // w9
  __int16 v34; // w8
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int16 v43; // w9
  _WORD *v44; // x8
  __int16 v45; // w9
  unsigned int v46; // w9
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  double v63; // d0
  double v64; // d1
  double v65; // d2
  double v66; // d3
  double v67; // d4
  double v68; // d5
  double v69; // d6
  double v70; // d7
  int v71; // w8
  __int64 v72; // x11
  __int64 v73; // x21
  unsigned __int64 v74; // x19
  char *v75; // x26
  int v76; // w9
  int v77; // w10
  int v78; // w11
  int v79; // w12
  __int16 v80; // w8
  char v81; // w9
  _BYTE *v82; // x22
  __int64 ap_link_by_link_id; // x0
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  unsigned __int8 *v92; // x27
  int v93; // w8
  int v94; // w21
  unsigned __int8 *v95; // x22
  unsigned __int64 v96; // x19
  __int64 v97; // x5
  __int64 v98; // x6
  __int64 v99; // x7
  int v100; // w8
  __int64 v101; // x27
  __int64 v102; // x20
  int v103; // w9
  int v104; // w10
  int v105; // w11
  int v106; // w12
  __int16 v107; // w8
  int v108; // w11
  int v109; // w10
  unsigned int v110; // w9
  __int64 v111; // x8
  __int16 v112; // w11
  __int16 v113; // w10
  bool v114; // zf
  int v115; // w9
  __int16 v116; // w8
  __int16 v117; // w9
  unsigned int v118; // w24
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  unsigned __int64 v127; // x28
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  __int64 v136; // x3
  __int64 v137; // x20
  double v138; // d0
  double v139; // d1
  double v140; // d2
  double v141; // d3
  double v142; // d4
  double v143; // d5
  double v144; // d6
  double v145; // d7
  _BYTE *v146; // x28
  unsigned __int16 v147; // w21
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  char cb_mode_for_freq; // w25
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  __int16 v165; // w9
  __int64 v166; // x8
  char ftm_cap; // w0
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  char sta_cb_mode_for_24ghz; // w0
  char v177; // w20
  __int64 v178; // x9
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  __int64 v187; // x8
  __int16 v188; // w9
  char v189; // w8
  char v190; // w9
  unsigned __int16 v191; // w20
  __int64 v192; // x20
  __int64 v193; // x0
  double v194; // d0
  double v195; // d1
  double v196; // d2
  double v197; // d3
  double v198; // d4
  double v199; // d5
  double v200; // d6
  double v201; // d7
  unsigned __int8 *v202; // x0
  double v203; // d0
  double v204; // d1
  double v205; // d2
  double v206; // d3
  double v207; // d4
  double v208; // d5
  double v209; // d6
  double v210; // d7
  unsigned __int8 *v211; // x24
  __int16 v212; // w8
  int v213; // w21
  __int64 v214; // [xsp+0h] [xbp-2A0h]
  __int64 v215; // [xsp+8h] [xbp-298h]
  __int64 v216; // [xsp+10h] [xbp-290h]
  __int64 v217; // [xsp+18h] [xbp-288h]
  __int64 v218; // [xsp+20h] [xbp-280h]
  __int64 v219; // [xsp+30h] [xbp-270h]
  __int64 v220; // [xsp+38h] [xbp-268h]
  __int64 v221; // [xsp+40h] [xbp-260h]
  char v222; // [xsp+4Ch] [xbp-254h]
  int v223; // [xsp+50h] [xbp-250h]
  unsigned __int8 v224; // [xsp+54h] [xbp-24Ch]
  int v225; // [xsp+58h] [xbp-248h]
  int v226; // [xsp+64h] [xbp-23Ch]
  _BYTE *v227; // [xsp+70h] [xbp-230h]
  __int64 v228; // [xsp+78h] [xbp-228h]
  bool is_24ghz_ch_freq; // [xsp+84h] [xbp-21Ch]
  __int64 v230; // [xsp+88h] [xbp-218h]
  __int16 v231[2]; // [xsp+90h] [xbp-210h] BYREF
  __int16 v232; // [xsp+94h] [xbp-20Ch] BYREF
  char v233; // [xsp+96h] [xbp-20Ah]
  __int16 v234; // [xsp+98h] [xbp-208h] BYREF
  char v235; // [xsp+9Ah] [xbp-206h]
  int v236; // [xsp+9Ch] [xbp-204h] BYREF
  __int16 v237[2]; // [xsp+A0h] [xbp-200h] BYREF
  unsigned int v238; // [xsp+A4h] [xbp-1FCh] BYREF
  _QWORD v239[2]; // [xsp+A8h] [xbp-1F8h] BYREF
  __int128 v240; // [xsp+B8h] [xbp-1E8h] BYREF
  __int64 v241; // [xsp+C8h] [xbp-1D8h]
  __int64 v242; // [xsp+D0h] [xbp-1D0h]
  __int64 v243; // [xsp+D8h] [xbp-1C8h]
  __int64 v244; // [xsp+E0h] [xbp-1C0h]
  __int64 v245; // [xsp+E8h] [xbp-1B8h]
  int v246; // [xsp+F0h] [xbp-1B0h]
  __int128 v247; // [xsp+F8h] [xbp-1A8h] BYREF
  __int64 v248; // [xsp+108h] [xbp-198h]
  __int64 v249; // [xsp+110h] [xbp-190h]
  __int64 v250; // [xsp+118h] [xbp-188h]
  __int64 v251; // [xsp+120h] [xbp-180h]
  __int64 v252; // [xsp+128h] [xbp-178h]
  __int64 v253; // [xsp+130h] [xbp-170h]
  __int64 v254; // [xsp+138h] [xbp-168h]
  __int64 v255; // [xsp+140h] [xbp-160h]
  __int64 v256; // [xsp+148h] [xbp-158h]
  int v257; // [xsp+150h] [xbp-150h]
  _BYTE v258[16]; // [xsp+158h] [xbp-148h] BYREF
  _BYTE v259[16]; // [xsp+168h] [xbp-138h] BYREF
  __int128 v260; // [xsp+178h] [xbp-128h] BYREF
  __int64 v261; // [xsp+188h] [xbp-118h]
  __int64 v262; // [xsp+190h] [xbp-110h]
  __int64 v263; // [xsp+198h] [xbp-108h]
  __int64 v264; // [xsp+1A0h] [xbp-100h]
  __int64 v265; // [xsp+1A8h] [xbp-F8h]
  __int64 v266; // [xsp+1B0h] [xbp-F0h]
  __int64 v267; // [xsp+1B8h] [xbp-E8h]
  __int64 v268; // [xsp+1C0h] [xbp-E0h]
  __int64 v269; // [xsp+1C8h] [xbp-D8h]
  int v270; // [xsp+1D0h] [xbp-D0h]
  __int128 v271; // [xsp+1D8h] [xbp-C8h] BYREF
  __int64 v272; // [xsp+1E8h] [xbp-B8h]
  __int64 v273; // [xsp+1F0h] [xbp-B0h]
  __int64 v274; // [xsp+1F8h] [xbp-A8h] BYREF
  __int64 v275; // [xsp+200h] [xbp-A0h]
  __int64 v276; // [xsp+208h] [xbp-98h]
  int v277; // [xsp+210h] [xbp-90h]
  __int128 v278; // [xsp+218h] [xbp-88h] BYREF
  char v279; // [xsp+228h] [xbp-78h]
  _QWORD v280[7]; // [xsp+230h] [xbp-70h] BYREF
  int v281; // [xsp+268h] [xbp-38h]
  unsigned __int8 v282[16]; // [xsp+270h] [xbp-30h] BYREF
  _QWORD v283[4]; // [xsp+280h] [xbp-20h] BYREF

  result = 29;
  v283[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v231[0] = 0;
  if ( a1 && a2 )
  {
    memset(v282, 0, 13);
    v14 = *(_QWORD *)(a1 + 216);
    memset(v283, 0, 13);
    v238 = 0;
    v237[0] = 0;
    memset(v280, 0, sizeof(v280));
    v281 = 0;
    v239[0] = 0;
    v239[1] = 0;
    v279 = 0;
    v278 = 0u;
    v277 = 0;
    v275 = 0;
    v276 = 0;
    v273 = 0;
    v274 = 0;
    v272 = 0;
    v271 = 0u;
    v236 = 0;
    v260 = 0u;
    v261 = 0;
    v262 = 0;
    v263 = 0;
    v264 = 0;
    v265 = 0;
    v266 = 0;
    v267 = 0;
    v268 = 0;
    v269 = 0;
    v270 = 0;
    memset(v259, 0, 14);
    memset(v258, 0, 14);
    v235 = 0;
    v234 = 0;
    v233 = 0;
    v232 = 0;
    if ( v14 && (v15 = *(_QWORD *)(v14 + 80)) != 0 )
    {
      context = _cds_get_context(53, (__int64)"populate_rv_mlo_ie", a4, a5, a6, a7, a8, a9, a10, a11);
      if ( context )
      {
        v18 = (__int64)context;
        v19 = (_BYTE *)(a2 + 7024);
        v20 = 1;
        v21 = *(_WORD *)(a2 + 10874);
        *(_BYTE *)(a2 + 10876) = 1;
        *(_WORD *)(a2 + 10874) = v21 & 0xF008 | 0x902;
        qdf_mem_copy((void *)(a2 + 10877), (const void *)(a1 + 80), 6u);
        v22 = *(_BYTE *)(a2 + 10876);
        v23 = *(_WORD *)(a2 + 10874);
        *(_BYTE *)(a2 + 10876) = v22 + 6;
        if ( (v23 & 0x100) != 0 )
        {
          *(_BYTE *)(a2 + 10876) = v22 + 8;
          *(_WORD *)(a2 + 10890) = *(_WORD *)(a2 + 10890) & 0xFFE0 | wlan_mlme_get_sta_mlo_simultaneous_links(v15) & 0xF;
          v20 = 5;
          *(_WORD *)(a2 + 10890) = (32 * (wlan_mlme_get_t2lm_negotiation_supported(*(_QWORD *)(v18 + 21624)) & 3))
                                 | *(_WORD *)(a2 + 10890) & 0xC01F;
        }
        if ( (*(_BYTE *)(*(_QWORD *)(a2 + 16) + 49LL) & 4) != 0 )
        {
          wlan_mlme_get_eml_params(v15, v231);
          v24 = LOBYTE(v231[0]);
          v20 |= 2u;
          v25 = *(_WORD *)(a2 + 10888) & 0x8700;
          v26 = *(_BYTE *)(a2 + 10876) + 2;
          *(_WORD *)(a2 + 10874) |= 0x80u;
          *(_BYTE *)(a2 + 10876) = v26;
          *(_WORD *)(a2 + 10888) = v25 | v24;
        }
        v27 = *(_DWORD **)(v15 + 2800);
        v219 = v15;
        if ( v27 )
        {
          v28 = v27[126];
          v29 = v27 + 780;
          if ( v28 <= 0xA )
          {
            if ( *v29 == v28 )
            {
              v30 = 0;
            }
            else if ( v27[826] == v28 )
            {
              v30 = 1;
            }
            else if ( v27[872] == v28 )
            {
              v30 = 2;
            }
            else if ( v27[918] == v28 )
            {
              v30 = 3;
            }
            else if ( v27[964] == v28 )
            {
              v30 = 4;
            }
            else if ( v27[1010] == v28 )
            {
              v30 = 5;
            }
            else if ( v27[1056] == v28 )
            {
              v30 = 6;
            }
            else
            {
              if ( v27[1102] != v28 )
                goto LABEL_35;
              v30 = 7;
            }
            v29 += 46 * v30;
          }
          if ( v29 && (v29[45] & 0x80) != 0 )
          {
            v20 |= 8u;
            v31 = *(_WORD *)(a2 + 10894);
            v32 = *(_BYTE *)(a2 + 10876) + 2;
            *(_WORD *)(a2 + 10874) |= 0x400u;
            *(_BYTE *)(a2 + 10876) = v32;
            *(_WORD *)(a2 + 10894) = v31 | 0x80;
          }
        }
LABEL_35:
        v33 = *(_WORD *)(a2 + 10874);
        *(_WORD *)(a2 + 12964) = 255;
        v34 = *(_WORD *)(a2 + 12967) & 8 | v33 & 7;
        *(_BYTE *)(a2 + 12969) = *(_BYTE *)(a2 + 10876);
        *(_BYTE *)(a2 + 12966) = 107;
        *(_WORD *)(a2 + 12967) = v34 | (16 * v20);
        qdf_mem_copy((void *)(a2 + 12970), (const void *)(a1 + 80), 6u);
        v43 = *(_WORD *)(a2 + 10874);
        if ( (v43 & 0x80) != 0 )
        {
          *(_WORD *)(a2 + 12976) = *(_WORD *)(a2 + 12976) & 0x8000 | *(_WORD *)(a2 + 10888) & 0x7FFF;
          v44 = (_WORD *)(a2 + 12978);
          if ( (v43 & 0x100) == 0 )
          {
LABEL_40:
            v220 = a1;
            if ( (v43 & 0x400) != 0 )
            {
              v45 = *v44 & 0xFF7F;
              *v44 = v45;
              *v44 = *(_WORD *)(a2 + 10894) & 0x80 | v45;
              LOWORD(v44) = (_WORD)v44 + 2;
            }
            v46 = *(unsigned __int16 *)(a2 + 10888);
            *(_WORD *)(a2 + 12962) = (_WORD)v44 - (a2 + 12964);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: EMLSR support: %d, padding delay: %d, transition delay: %d",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "populate_rv_mlo_ie",
              v46 & 1,
              (v46 >> 1) & 7,
              (v46 >> 4) & 7);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Num add links %d Num del links %d",
              v47,
              v48,
              v49,
              v50,
              v51,
              v52,
              v53,
              v54,
              "populate_rv_mlo_ie",
              *(unsigned __int8 *)(a3 + 120),
              *(unsigned __int8 *)(a3 + 248));
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: Ext ML Caps, BTM MLD Recom for Multi AP support: %d",
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              "populate_rv_mlo_ie",
              (*(unsigned __int16 *)(a2 + 10894) >> 7) & 1);
            v71 = *(unsigned __int8 *)(a3 + 120);
            v224 = *(_BYTE *)(a3 + 248) + v71;
            if ( v224 >= 5u )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: total_sta_prof %d overflow %lu",
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                "populate_rv_mlo_ie");
              result = 29;
              goto LABEL_15;
            }
            if ( !*(_QWORD *)(*(_QWORD *)(a2 + 16) + 1360LL) )
            {
              qdf_trace_msg(
                0x35u,
                2u,
                "%s: mlo_dev_ctx is null",
                v63,
                v64,
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                "populate_rv_mlo_ie");
              result = 29;
              goto LABEL_15;
            }
            v72 = a3;
            v227 = (_BYTE *)(a2 + 7024);
            v228 = a3;
            v230 = a2;
            if ( !*(_BYTE *)(a3 + 248) )
            {
              v94 = 0;
              goto LABEL_61;
            }
            v73 = 0;
            v74 = 0;
            v75 = (char *)(a2 + 10905);
            while ( 1 )
            {
              if ( v73 == 120 )
LABEL_206:
                __break(0x5512u);
              v82 = (_BYTE *)(v72 + v73);
              ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(
                                     *(_QWORD *)(*(_QWORD *)(a2 + 16) + 1360LL),
                                     *(unsigned __int8 *)(v72 + v73 + 129));
              if ( ap_link_by_link_id )
                v92 = (unsigned __int8 *)ap_link_by_link_id;
              else
                v92 = v82 + 142;
              v93 = (_DWORD)v82 + 136;
              if ( v82 == (_BYTE *)-136LL )
              {
                if ( !v92 )
                {
LABEL_57:
                  v78 = 0;
                  v76 = 0;
                  v77 = 0;
                  v79 = 0;
                  goto LABEL_48;
                }
              }
              else
              {
                v93 = (unsigned __int8)v82[141];
                if ( !v92 )
                  goto LABEL_57;
              }
              v76 = *v92;
              v77 = v92[1];
              v78 = v92[2];
              v79 = v92[5];
LABEL_48:
              LODWORD(v218) = v79;
              LODWORD(v217) = v78;
              LODWORD(v216) = v77;
              LODWORD(v215) = v76;
              LODWORD(v214) = v93;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Del link id %d ap link addr : %02x:%02x:%02x:**:**:%02x self: %02x:%02x:%02x:**:**:%02x",
                v84,
                v85,
                v86,
                v87,
                v88,
                v89,
                v90,
                v91,
                "populate_rv_mlo_ie",
                v214,
                v215,
                v216,
                v217,
                v218);
              v80 = *(_WORD *)(v75 - 3);
              *(_WORD *)(v75 - 5) = 0;
              *(_WORD *)(v75 - 3) = v80 & 0xFFF0;
              v81 = v82[129];
              *(v75 - 1) = 7;
              *(_WORD *)(v75 - 3) = v80 & 0xD000 | v81 & 0xF | 0x1A0;
              qdf_mem_copy(v75, v92, 6u);
              v72 = v228;
              *(_WORD *)(v75 - 7) = 11;
              ++v74;
              *(v75 - 4) = 9;
              v73 += 40;
              v75 += 516;
              if ( v74 >= *(unsigned __int8 *)(v228 + 248) )
              {
                v71 = *(unsigned __int8 *)(v228 + 120);
                v94 = v74;
                v19 = (_BYTE *)(a2 + 7024);
LABEL_61:
                if ( !v71 || v224 == (unsigned __int8)v94 )
                {
LABEL_205:
                  result = 0;
                  *((_WORD *)v19 + 1936) = (unsigned __int8)v94;
                  goto LABEL_15;
                }
                v95 = (unsigned __int8 *)(v72 + 9);
                v96 = 1;
                v222 = 0;
                v221 = a2 + 10898;
                while ( 2 )
                {
                  if ( (unsigned __int8)v94 > 4u || v96 == 4 )
                    goto LABEL_206;
                  if ( v95 == (_BYTE *)&off_0 + 1 )
                  {
                    v99 = 0;
                    v97 = 0;
                    v98 = 0;
                    v100 = 0;
                  }
                  else
                  {
                    v97 = *(v95 - 1);
                    v98 = *v95;
                    v99 = v95[1];
                    v100 = v95[4];
                  }
                  v101 = v221 + 516LL * (unsigned __int8)v94;
                  v102 = v230;
                  v19 = v227;
                  if ( v95 == (unsigned __int8 *)-5LL )
                  {
                    v105 = 0;
                    v103 = 0;
                    v104 = 0;
                    v106 = 0;
                  }
                  else
                  {
                    v103 = v95[5];
                    v104 = v95[6];
                    v105 = v95[7];
                    v106 = v95[10];
                  }
                  LODWORD(v218) = v106;
                  LODWORD(v217) = v105;
                  LODWORD(v216) = v104;
                  LODWORD(v215) = v103;
                  LODWORD(v214) = v100;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Add link id %d link addr : %02x:%02x:%02x:**:**:%02x self: %02x:%02x:%02x:**:**:%02x",
                    v63,
                    v64,
                    v65,
                    v66,
                    v67,
                    v68,
                    v69,
                    v70,
                    "populate_rv_mlo_ie",
                    *(v95 - 8),
                    v97,
                    v98,
                    v99,
                    v214,
                    v215,
                    v216,
                    v217,
                    v218);
                  v107 = *(_WORD *)(v101 + 4);
                  *(_WORD *)(v101 + 2) = 0;
                  *(_WORD *)(v101 + 4) = v107 & 0xFFF0;
                  *(_WORD *)(v101 + 4) = v107 & 0xD000 | *(v95 - 8) & 0xF | 0x130;
                  *(_BYTE *)(v101 + 6) = 7;
                  qdf_mem_copy((void *)(v101 + 7), v95 + 5, 6u);
                  qdf_mem_set(v237, 2u, 0);
                  qdf_mem_set(v283, 0xDu, 0);
                  qdf_mem_set(v282, 0xDu, 0);
                  qdf_mem_set(v259, 0xEu, 0);
                  qdf_mem_set(v258, 0xEu, 0);
                  qdf_mem_set(v280, 0x3Cu, 0);
                  qdf_mem_set(&v278, 0x11u, 0);
                  qdf_mem_set(v239, 0x10u, 0);
                  qdf_mem_set(&v271, 0x3Cu, 0);
                  qdf_mem_set(&v234, 3u, 0);
                  qdf_mem_set(&v232, 3u, 0);
                  qdf_mem_set(&v236, 4u, 0);
                  qdf_mem_set(&v260, 0x5Cu, 0);
                  v108 = 0;
                  v109 = 0;
                  if ( (*v227 & 2) != 0 )
                  {
                    v110 = *(unsigned __int8 *)(v230 + 178);
                    v109 = 0;
                    v108 = (v110 >> 1) & 1;
                    if ( (*v227 & 4) != 0 && (v110 & 2) != 0 )
                    {
                      v109 = (v110 >> 2) & 1;
                      v108 = 1;
                    }
                  }
                  v111 = *(_QWORD *)(v18 + 8);
                  v223 = v109;
                  v226 = v108;
                  if ( *(_BYTE *)(v111 + 5652) )
                    v112 = 17;
                  else
                    v112 = 1;
                  if ( *(_BYTE *)(v111 + 1298) )
                    v112 |= 0x20u;
                  if ( *(_BYTE *)(v111 + 5604) )
                    v112 |= 0x400u;
                  if ( *(_BYTE *)(v111 + 1061) )
                    v113 = v112 | 0x100;
                  else
                    v113 = v112;
                  v114 = *(_BYTE *)(v111 + 5668) == 0;
                  v115 = *(unsigned __int8 *)(v111 + 3636);
                  v116 = *(_WORD *)(v111 + 5616);
                  if ( !v114 )
                    v113 |= 0x200u;
                  if ( v115 )
                    v117 = v113 | 0x800;
                  else
                    v117 = v113;
                  v237[0] = v117 & 0x2FFF | ((*(_BYTE *)(v18 + 17480) & 1) << 12) | (v116 << 14);
                  dot11f_pack_ff_capabilities(v18, v237, (void *)(v101 + 13));
                  v118 = *(_DWORD *)(v95 - 5);
                  if ( v118 )
                  {
                    is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v118);
                    v225 = v94;
                    if ( is_24ghz_ch_freq )
                    {
                      LODWORD(v247) = 369820674;
                      LOBYTE(v283[0]) = 4;
                      qdf_mem_copy((char *)v283 + 1, &v247, 4u);
                      *(_WORD *)((char *)v283 + 1) |= 0x8080u;
                      *(_WORD *)((char *)v283 + 3) |= 0x8080u;
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Default CCK Rates",
                        v119,
                        v120,
                        v121,
                        v122,
                        v123,
                        v124,
                        v125,
                        v126,
                        "wlan_populate_basic_rates");
                      ((void (__fastcall *)(__int64, __int64, char *, _QWORD))qdf_trace_hex_dump)(
                        53,
                        8,
                        (char *)v283 + 1,
                        LOBYTE(v283[0]));
                      v127 = (unsigned __int64)v282;
                      *(_QWORD *)&v247 = 0x6C6048302418120CLL;
                      v282[0] = 8;
                      qdf_mem_copy(&v282[1], &v247, 8u);
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Default OFDM Rates",
                        v128,
                        v129,
                        v130,
                        v131,
                        v132,
                        v133,
                        v134,
                        v135,
                        "wlan_populate_basic_rates");
                      v136 = v282[0];
                    }
                    else
                    {
                      v127 = (unsigned __int64)v283;
                      *(_QWORD *)&v247 = 0x6C6048302418120CLL;
                      LOBYTE(v283[0]) = 8;
                      qdf_mem_copy((char *)v283 + 1, &v247, 8u);
                      BYTE1(v283[0]) |= 0x80u;
                      BYTE3(v283[0]) |= 0x80u;
                      BYTE5(v283[0]) |= 0x80u;
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Default OFDM Rates",
                        v138,
                        v139,
                        v140,
                        v141,
                        v142,
                        v143,
                        v144,
                        v145,
                        "wlan_populate_basic_rates");
                      v136 = LOBYTE(v283[0]);
                    }
                    ((void (__fastcall *)(__int64, __int64, unsigned __int64, __int64))qdf_trace_hex_dump)(
                      53,
                      8,
                      v127 | 1,
                      v136);
                    v146 = (_BYTE *)(v101 + 15);
                    if ( LOBYTE(v283[0]) )
                    {
                      v259[1] = v283[0];
                      qdf_mem_copy(&v259[2], (char *)v283 + 1, LOBYTE(v283[0]));
                      v259[0] = 1;
                      v238 = 0;
                      dot11f_pack_ie_supp_rates(v18, v259, (_BYTE *)(v101 + 15), 0x1F5u, (int *)&v238);
                      v146 += v238;
                      v147 = 501 - v238;
                    }
                    else
                    {
                      v147 = 501;
                    }
                    if ( !wlan_reg_is_6ghz_chan_freq(v118) )
                    {
                      cb_mode_for_freq = lim_get_cb_mode_for_freq(v18, v230, v118);
                      populate_dot11f_ht_caps(
                        (_QWORD *)v18,
                        0,
                        (__int64)v280,
                        v157,
                        v158,
                        v159,
                        v160,
                        v161,
                        v162,
                        v163,
                        v164);
                      v102 = v230;
                      if ( cb_mode_for_freq )
                        v165 = 66;
                      else
                        v165 = 0;
                      *(_WORD *)((char *)v280 + 1) = *(_WORD *)((_BYTE *)v280 + 1) & 0xFFBD | v165;
                    }
                    if ( LOBYTE(v280[0]) )
                    {
                      v238 = 0;
                      dot11f_pack_ie_ht_caps(v18, (__int64)v280, v146, v147, (int *)&v238);
                      v146 += v238;
                      v147 -= v238;
                    }
                    if ( v282[0] )
                    {
                      v258[1] = v282[0];
                      qdf_mem_copy(&v258[2], &v282[1], v282[0]);
                      v258[0] = 1;
                      v238 = 0;
                      dot11f_pack_ie_ext_supp_rates(v18, v258, v146, v147, (int *)&v238);
                      v146 += v238;
                      v147 -= v238;
                    }
                    LOBYTE(v278) = 1;
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: 11MC - enabled for non-SAP cases",
                      v148,
                      v149,
                      v150,
                      v151,
                      v152,
                      v153,
                      v154,
                      v155,
                      "populate_dot11f_ext_cap");
                    v166 = *(_QWORD *)((char *)&v278 + 2) | 0x4000000000000000LL;
                    *(_QWORD *)((char *)&v278 + 2) |= 0x4000000000000000uLL;
                    v114 = *(_BYTE *)(*(_QWORD *)(v18 + 8) + 1049LL) == 1;
                    BYTE1(v278) = 15;
                    if ( v114 )
                    {
                      ftm_cap = ucfg_wifi_pos_get_ftm_cap(*(_QWORD *)(v18 + 21624));
                      v166 = *(_QWORD *)((char *)&v278 + 2);
                      WORD5(v278) = WORD5(v278) & 0xFF3F | (__rbit32(ftm_cap & 3) >> 24);
                    }
                    *(_QWORD *)((char *)&v278 + 2) = *(unsigned __int8 *)(v18 + 17230) | (unsigned __int64)v166 | 4;
                    if ( (_BYTE)v278 )
                      BYTE1(v278) = lim_compute_ext_cap_ie_length(&v278);
                    if ( (wlan_cm_get_assoc_btm_cap(v219, *(unsigned __int8 *)(v220 + 168)) & 1) != 0 )
                      *(_QWORD *)((char *)&v278 + 2) |= 0x80000uLL;
                    populate_dot11f_btm_extended_caps(v18, v102, (__int64)&v278);
                    if ( (_BYTE)v278 )
                    {
                      v238 = 0;
                      dot11f_pack_ie_ext_cap(v18, &v278, v146, v147, (int *)&v238);
                      v146 += v238;
                      v147 -= v238;
                    }
                    if ( !wlan_reg_is_6ghz_chan_freq(v118) )
                      populate_dot11f_vht_caps(v18, 0, (__int64)v239, v168, v169, v170, v171, v172, v173, v174, v175);
                    if ( LOBYTE(v239[0]) )
                    {
                      v238 = 0;
                      dot11f_pack_ie_vht_caps(v18, (__int64)v239, v146, v147, (int *)&v238);
                      v146 += v238;
                      v147 -= v238;
                    }
                    if ( is_24ghz_ch_freq )
                    {
                      qdf_mem_copy(&v271, (const void *)(v18 + 21788), 0x3Cu);
                      sta_cb_mode_for_24ghz = lim_get_sta_cb_mode_for_24ghz(v18, *(unsigned __int8 *)(v102 + 10));
                      *(_QWORD *)((char *)&v271 + 1) = *(_QWORD *)((_BYTE *)&v271 + 1) & 0xFFFBFFFFFFFFFFFFLL
                                                     | ((unsigned __int64)(sta_cb_mode_for_24ghz & 1) << 50);
                    }
                    else
                    {
                      qdf_mem_copy(&v271, (const void *)(v18 + 21848), 0x3Cu);
                    }
                    populate_dot11f_twt_he_cap(v18, v102, (__int64)&v271);
                    if ( (BYTE14(v271) & 4) != 0 )
                    {
                      v177 = 25;
                      v178 = 1453;
                      if ( is_24ghz_ch_freq )
                        v178 = 1428;
                      qdf_mem_copy((char *)&v274 + 1, (const void *)(*(_QWORD *)(v18 + 8) + v178), 0x19u);
                      if ( !BYTE1(v277) )
                      {
                        if ( (_BYTE)v277 )
                        {
                          v177 = 24;
                        }
                        else if ( HIBYTE(v276) )
                        {
                          v177 = 23;
                        }
                        else if ( BYTE6(v276) )
                        {
                          v177 = 22;
                        }
                        else if ( BYTE5(v276) )
                        {
                          v177 = 21;
                        }
                        else if ( BYTE4(v276) )
                        {
                          v177 = 20;
                        }
                        else if ( BYTE3(v276) )
                        {
                          v177 = 19;
                        }
                        else if ( BYTE2(v276) )
                        {
                          v177 = 18;
                        }
                        else if ( BYTE1(v276) )
                        {
                          v177 = 17;
                        }
                        else if ( (_BYTE)v276 )
                        {
                          v177 = 16;
                        }
                        else if ( HIBYTE(v275) )
                        {
                          v177 = 15;
                        }
                        else if ( BYTE6(v275) )
                        {
                          v177 = 14;
                        }
                        else if ( BYTE5(v275) )
                        {
                          v177 = 13;
                        }
                        else if ( BYTE4(v275) )
                        {
                          v177 = 12;
                        }
                        else if ( BYTE3(v275) )
                        {
                          v177 = 11;
                        }
                        else if ( BYTE2(v275) )
                        {
                          v177 = 10;
                        }
                        else if ( BYTE1(v275) )
                        {
                          v177 = 9;
                        }
                        else if ( (_BYTE)v275 )
                        {
                          v177 = 8;
                        }
                        else if ( HIBYTE(v274) )
                        {
                          v177 = 7;
                        }
                        else if ( BYTE6(v274) )
                        {
                          v177 = 6;
                        }
                        else if ( BYTE5(v274) )
                        {
                          v177 = 5;
                        }
                        else if ( BYTE4(v274) )
                        {
                          v177 = 4;
                        }
                        else if ( BYTE3(v274) )
                        {
                          v177 = 3;
                        }
                        else if ( BYTE2(v274) )
                        {
                          v177 = 2;
                        }
                        else
                        {
                          v177 = BYTE1(v274) != 0;
                        }
                      }
                    }
                    else
                    {
                      v177 = 0;
                    }
                    LOBYTE(v274) = v177;
                    if ( (_BYTE)v271 )
                    {
                      v238 = 0;
                      dot11f_pack_ie_he_cap(v18, (__int64)&v271, v146, v147, (int *)&v238);
                      v146 += v238;
                      v147 -= v238;
                      v222 = 1;
                    }
                    if ( wlan_reg_is_6ghz_chan_freq(v118) )
                    {
                      v187 = *(_QWORD *)(v18 + 8);
                      v188 = BYTE1(v236) & 0xC0
                           | (*(_BYTE *)(v187 + 1290) >> 2) & 7
                           | (*(_WORD *)(v187 + 1288) << 9) & 0x18C7
                           | (unsigned __int8)(8 * (*(_BYTE *)(v187 + 2877) & 7))
                           | ((*(_BYTE *)(v187 + 2878) & 7) << 8);
                      LOBYTE(v236) = 1;
                      *(_WORD *)((char *)&v236 + 1) = v188;
                      lim_log_he_6g_cap(v179, v180, v181, v182, v183, v184, v185, v186, v18, (__int64)&v236);
                    }
                    if ( (_BYTE)v236 )
                    {
                      v238 = 0;
                      dot11f_pack_ie_he_6ghz_band_cap(v18, (__int64)&v236, v146, v147, (int *)&v238);
                      v146 += v238;
                      v147 -= v238;
                    }
                    if ( v226 && wlan_reg_is_6ghz_chan_freq(v118) )
                    {
                      v189 = *(_BYTE *)(*(_QWORD *)(v18 + 8) + 5670LL);
                      v190 = v227[249] & 0xF;
                      v234 = 257;
                      v235 = v190 & 0x9F | (32 * (v189 & 3)) | v235 & 0x90;
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: wmm info present",
                        v179,
                        v180,
                        v181,
                        v182,
                        v183,
                        v184,
                        v185,
                        v186,
                        "populate_rv_mlo_ie");
                      v238 = 0;
                      dot11f_pack_ie_wmm_info_station(v18, &v234, v146, v147, (int *)&v238);
                      v146 += v238;
                      if ( v223 )
                      {
                        v232 = 257;
                        v233 = v233 & 0xF | 0x20;
                        goto LABEL_188;
                      }
                      if ( (_BYTE)v232 )
                      {
LABEL_188:
                        v191 = v147 - v238;
                        qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: wmm caps present",
                          v179,
                          v180,
                          v181,
                          v182,
                          v183,
                          v184,
                          v185,
                          v186,
                          "populate_rv_mlo_ie");
                        v238 = 0;
                        dot11f_pack_ie_wmm_caps(v18, &v232, v146, v191, (int *)&v238);
                        v146 += v238;
                      }
                    }
                    if ( is_24ghz_ch_freq )
                      v192 = 22064;
                    else
                      v192 = 22156;
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: is_2g %d",
                      v179,
                      v180,
                      v181,
                      v182,
                      v183,
                      v184,
                      v185,
                      v186,
                      "populate_dot11f_eht_caps_by_band",
                      is_24ghz_ch_freq);
                    qdf_mem_copy(&v260, (const void *)(v18 + v192), 0x5Cu);
                    v193 = *(_QWORD *)(v18 + 21624);
                    LOBYTE(v247) = 0;
                    wlan_twt_get_rtwt_support(v193, &v247);
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: rTWT support: %d",
                      v194,
                      v195,
                      v196,
                      v197,
                      v198,
                      v199,
                      v200,
                      v201,
                      "populate_dot11f_rtwt_eht_cap",
                      (unsigned __int8)v247);
                    *(_QWORD *)((char *)&v260 + 1) = *(_QWORD *)((_BYTE *)&v260 + 1) & 0xFFFFFFFFFFFFFFEFLL
                                                   | (16 * (v247 & 1));
                    if ( !wlan_reg_is_6ghz_chan_freq(v118) )
                      *(_QWORD *)((char *)&v260 + 1) &= ~0x20000uLL;
                    if ( ((_BYTE)v260 != 0) | v222 & 1 )
                    {
                      v202 = (unsigned __int8 *)_qdf_mem_malloc(0x101u, "populate_rv_mlo_ie", 15361);
                      if ( v202 )
                      {
                        v238 = 0;
                        v211 = v202;
                        v254 = v267;
                        v255 = v268;
                        v256 = v269;
                        v257 = v270;
                        v250 = v263;
                        v251 = v264;
                        v252 = v265;
                        v253 = v266;
                        v247 = v260;
                        v248 = v261;
                        v249 = v262;
                        v243 = v274;
                        v244 = v275;
                        v245 = v276;
                        v246 = v277;
                        v240 = v271;
                        v241 = v272;
                        v242 = v273;
                        lim_ieee80211_pack_ehtcap(
                          v202,
                          &v247,
                          (__int64)&v240,
                          is_24ghz_ch_freq,
                          1,
                          v203,
                          v204,
                          v205,
                          v206,
                          v207,
                          v208,
                          v209,
                          v210);
                        v238 = v211[1] + 2;
                        qdf_mem_copy(v146, v211, v238);
                        _qdf_mem_free((__int64)v211);
                        LOWORD(v146) = (_WORD)v146 + v238;
                      }
                      else
                      {
                        qdf_trace_msg(
                          0x35u,
                          2u,
                          "%s: malloc failed for eht_cap_ie",
                          v203,
                          v204,
                          v205,
                          v206,
                          v207,
                          v208,
                          v209,
                          v210,
                          "populate_rv_mlo_ie");
                      }
                    }
                    v212 = (_WORD)v146 - (v101 + 2);
                    *(_WORD *)v101 = v212;
                    if ( (v212 & 0xFFFEu) < 0x102uLL )
                    {
                      v19 = v227;
                      v213 = v225;
                      *(_BYTE *)(v101 + 3) = v212 - 2;
                    }
                    else
                    {
                      *(_BYTE *)(v101 + 3) = -1;
                      v19 = v227;
                      v213 = v225;
                      if ( (unsigned int)lim_add_frag_ie_for_sta_profile(v101 + 2, v101) )
                      {
                        qdf_trace_msg(
                          0x35u,
                          8u,
                          "%s: STA profile frag error",
                          v63,
                          v64,
                          v65,
                          v66,
                          v67,
                          v68,
                          v69,
                          v70,
                          "populate_rv_mlo_ie");
                        *(_WORD *)v101 = 257;
                      }
                    }
                    v94 = v213 + 1;
                  }
                  else
                  {
                    v137 = jiffies;
                    if ( populate_rv_mlo_ie___last_ticks - jiffies + 125 < 0 )
                    {
                      qdf_trace_msg(
                        0x35u,
                        8u,
                        "%s: Invalid channel freq %d",
                        v63,
                        v64,
                        v65,
                        v66,
                        v67,
                        v68,
                        v69,
                        v70,
                        "populate_rv_mlo_ie",
                        0);
                      populate_rv_mlo_ie___last_ticks = v137;
                    }
                  }
                  if ( v96 >= *(unsigned __int8 *)(v228 + 120) )
                    goto LABEL_205;
                  ++v96;
                  v95 += 40;
                  if ( v224 == (unsigned __int8)v94 )
                    goto LABEL_205;
                  continue;
                }
              }
            }
          }
        }
        else
        {
          v44 = (_WORD *)(a2 + 12976);
          if ( (*(_WORD *)(a2 + 10874) & 0x100) == 0 )
            goto LABEL_40;
        }
        *v44 = *(_WORD *)(a2 + 10890) & 0x206F | *v44 & 0xDF90;
        ++v44;
        goto LABEL_40;
      }
      result = 4;
    }
    else
    {
      qdf_trace_msg(0x35u, 2u, "%s: Invalid psoc", a4, a5, a6, a7, a8, a9, a10, a11, "populate_rv_mlo_ie");
      result = 16;
    }
  }
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}
