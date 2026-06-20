__int64 __fastcall syna_tcm_parse_touch_report(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  _BYTE *v6; // x24
  unsigned int v7; // w28
  __int64 v8; // x2
  int v9; // w13
  unsigned int v10; // w25
  unsigned int v11; // w1
  __int64 v12; // x8
  unsigned int v13; // w9
  int v14; // w10
  unsigned int v15; // w11
  int v16; // w23
  unsigned int v17; // w19
  int v18; // w26
  __int64 v19; // x9
  unsigned int v20; // w27
  _DWORD *v21; // x9
  unsigned int v22; // w20
  __int64 v23; // x6
  int v24; // w0
  _DWORD *v25; // x10
  __int64 v26; // x6
  unsigned int v27; // w20
  int v28; // w0
  _DWORD *v29; // x10
  __int64 v30; // x6
  unsigned int v31; // w20
  unsigned int v32; // w8
  int v33; // w11
  __int64 result; // x0
  unsigned __int64 v35; // x10
  unsigned int v36; // w9
  char v37; // w12
  unsigned int v38; // w9
  unsigned int v39; // w10
  int v40; // w12
  int v41; // w14
  char v42; // w13
  unsigned __int64 v43; // x10
  unsigned int v44; // w9
  char v45; // w12
  unsigned int v46; // w9
  unsigned int v47; // w10
  int v48; // w12
  int v49; // w14
  char v50; // w13
  unsigned __int64 v51; // x10
  unsigned int v52; // w9
  char v53; // w12
  unsigned int v54; // w9
  unsigned int v55; // w10
  int v56; // w12
  int v57; // w14
  char v58; // w13
  unsigned __int64 v59; // x10
  unsigned int v60; // w9
  char v61; // w12
  unsigned int v62; // w9
  unsigned int v63; // w10
  int v64; // w12
  int v65; // w14
  char v66; // w13
  unsigned __int64 v67; // x9
  unsigned int v68; // w8
  char v69; // w12
  unsigned int v70; // w8
  unsigned int v71; // w9
  int v72; // w12
  int v73; // w14
  char v74; // w13
  unsigned __int64 v75; // x10
  unsigned int v76; // w8
  char v77; // w12
  unsigned int v78; // w8
  unsigned int v79; // w10
  int v80; // w12
  int v81; // w14
  char v82; // w13
  unsigned __int64 v83; // x9
  unsigned int v84; // w8
  char v85; // w12
  unsigned int v86; // w8
  unsigned int v87; // w9
  int v88; // w12
  int v89; // w14
  char v90; // w13
  unsigned __int64 v91; // x10
  unsigned int v92; // w9
  char v93; // w12
  unsigned int v94; // w9
  unsigned int v95; // w10
  int v96; // w12
  int v97; // w14
  char v98; // w13
  unsigned __int64 v99; // x9
  unsigned int v100; // w8
  char v101; // w12
  unsigned int v102; // w8
  unsigned int v103; // w9
  int v104; // w12
  int v105; // w14
  char v106; // w13
  unsigned __int64 v107; // x9
  unsigned int v108; // w8
  char v109; // w12
  unsigned int v110; // w8
  unsigned int v111; // w9
  int v112; // w12
  int v113; // w14
  char v114; // w13
  unsigned __int64 v115; // x9
  unsigned int v116; // w8
  char v117; // w12
  unsigned int v118; // w8
  unsigned int v119; // w9
  int v120; // w12
  int v121; // w14
  char v122; // w13
  unsigned __int64 v123; // x9
  unsigned int v124; // w8
  char v125; // w12
  unsigned int v126; // w8
  unsigned int v127; // w9
  int v128; // w12
  int v129; // w14
  char v130; // w13
  unsigned __int64 v131; // x10
  unsigned int v132; // w9
  char v133; // w12
  unsigned int v134; // w9
  unsigned int v135; // w10
  int v136; // w12
  int v137; // w14
  char v138; // w13
  unsigned __int64 v139; // x9
  unsigned int v140; // w8
  char v141; // w12
  unsigned int v142; // w8
  unsigned int v143; // w9
  int v144; // w12
  int v145; // w14
  char v146; // w13
  unsigned __int64 v147; // x9
  unsigned int v148; // w8
  char v149; // w12
  unsigned int v150; // w8
  unsigned int v151; // w9
  int v152; // w12
  int v153; // w14
  char v154; // w13
  unsigned __int64 v155; // x10
  unsigned int v156; // w9
  char v157; // w12
  unsigned int v158; // w9
  unsigned int v159; // w10
  int v160; // w12
  int v161; // w14
  char v162; // w13
  unsigned __int64 v163; // x10
  unsigned int v164; // w9
  char v165; // w12
  unsigned int v166; // w9
  unsigned int v167; // w10
  int v168; // w12
  int v169; // w14
  char v170; // w13
  unsigned __int64 v171; // x9
  unsigned int v172; // w8
  char v173; // w12
  unsigned int v174; // w8
  unsigned int v175; // w9
  int v176; // w12
  int v177; // w14
  char v178; // w13
  unsigned __int64 v179; // x9
  unsigned int v180; // w8
  char v181; // w12
  unsigned int v182; // w8
  unsigned int v183; // w9
  int v184; // w12
  int v185; // w14
  char v186; // w13
  unsigned __int64 v187; // x9
  unsigned int v188; // w8
  char v189; // w12
  unsigned int v190; // w8
  unsigned int v191; // w9
  int v192; // w12
  int v193; // w14
  char v194; // w13
  unsigned __int64 v195; // x9
  unsigned int v196; // w8
  char v197; // w12
  unsigned int v198; // w8
  unsigned int v199; // w9
  int v200; // w12
  int v201; // w14
  char v202; // w13
  unsigned __int64 v203; // x9
  unsigned int v204; // w8
  char v205; // w12
  unsigned int v206; // w8
  unsigned int v207; // w9
  int v208; // w12
  int v209; // w14
  char v210; // w13
  unsigned __int64 v211; // x9
  unsigned int v212; // w8
  char v213; // w12
  unsigned int v214; // w8
  unsigned int v215; // w9
  int v216; // w12
  int v217; // w14
  char v218; // w13
  unsigned __int64 v219; // x9
  unsigned int v220; // w8
  char v221; // w12
  unsigned int v222; // w8
  unsigned int v223; // w9
  int v224; // w12
  int v225; // w14
  char v226; // w13
  int v227; // w9
  int v228; // w27
  unsigned __int64 v229; // x11
  char v230; // w10
  unsigned int v231; // w27
  unsigned int v232; // w8
  unsigned __int64 v233; // x10
  unsigned int v234; // w9
  char v235; // w12
  unsigned int v236; // w9
  unsigned int v237; // w10
  int v238; // w12
  int v239; // w14
  char v240; // w13
  unsigned int v241; // w13
  unsigned int v242; // w14
  int v243; // w12
  int v244; // w16
  int v245; // w0
  char v246; // w17
  unsigned __int64 v247; // x12
  int v248; // w11
  unsigned int v249; // w13
  unsigned int v250; // w14
  int v251; // w16
  int v252; // w0
  char v253; // w17
  unsigned __int64 v254; // x11
  int v255; // w12
  unsigned int v256; // w20
  unsigned int v257; // w13
  unsigned int v258; // w14
  int v259; // w16
  int v260; // w0
  char v261; // w17
  unsigned int v262; // w9
  unsigned __int64 v263; // x11
  unsigned int v264; // w13
  unsigned int v265; // w12
  unsigned int v266; // w11
  unsigned int v267; // w10
  int v268; // w13
  int v269; // w15
  char v270; // w14
  unsigned int v271; // w20
  void *v272; // x0
  void *v273; // x8
  unsigned int v274; // w19
  int v275; // [xsp+4h] [xbp-3Ch]
  __int64 v276; // [xsp+8h] [xbp-38h]
  unsigned int v277; // [xsp+10h] [xbp-30h]
  int v278; // [xsp+14h] [xbp-2Ch]
  void *s; // [xsp+18h] [xbp-28h]
  unsigned int v281; // [xsp+28h] [xbp-18h]
  unsigned int v282; // [xsp+2Ch] [xbp-14h]
  _QWORD v283[2]; // [xsp+30h] [xbp-10h] BYREF

  v282 = a3;
  v283[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v272 = &unk_3365A;
LABEL_398:
    printk(v272, "syna_tcm_parse_touch_report", a3);
    result = 4294967055LL;
    goto LABEL_399;
  }
  if ( !a2 )
  {
    v272 = &unk_37361;
    goto LABEL_398;
  }
  if ( !a4 )
  {
    v272 = &unk_390B0;
    goto LABEL_398;
  }
  if ( !*(_DWORD *)(a1 + 24) )
  {
    v272 = &unk_344B9;
    goto LABEL_398;
  }
  if ( *(_DWORD *)(a1 + 908) == 1 )
  {
    printk(&unk_37384, "syna_tcm_parse_touch_report", a3);
    result = 0;
    goto LABEL_399;
  }
  v6 = *(_BYTE **)(a1 + 400);
  s = (void *)(a4 + 8);
  if ( !v6 || (v7 = *(_DWORD *)(a1 + 412)) == 0 )
  {
    printk(&unk_37AB9, "syna_tcm_parse_touch_report", a3);
    v7 = 21;
    v6 = &default_custom_touch_format;
  }
  memset(s, 0, 0x208u);
  v9 = *(_DWORD *)(a1 + 484);
  v10 = 0;
  v11 = 0;
  LODWORD(v12) = 0;
  v278 = *(_DWORD *)(a1 + 472);
  v13 = 0;
  v14 = 0;
  v15 = *(_DWORD *)(a1 + 480) + v9;
  v276 = 0;
  v283[0] = 0;
  v275 = v9;
  v281 = 8 * v282;
  v277 = v15;
  while ( 2 )
  {
    v16 = v14;
    v17 = v13;
    v18 = v12;
LABEL_12:
    v19 = HIDWORD(v283[0]);
    if ( HIDWORD(v283[0]) >= v7 )
    {
LABEL_393:
      result = LODWORD(v283[0]);
      goto LABEL_399;
    }
    v12 = HIDWORD(v283[0]) + 1LL;
    ++HIDWORD(v283[0]);
    v20 = (unsigned __int8)v6[v19];
    switch ( v6[v19] )
    {
      case 0:
        goto LABEL_393;
      case 1:
        v13 = 0;
        v14 = 1;
        if ( v277 < v281 )
          continue;
        goto LABEL_9;
      case 2:
        v13 = 0;
        v14 = 0;
        if ( v277 < v281 )
          continue;
        goto LABEL_9;
      case 3:
        result = LODWORD(v283[0]);
        if ( LODWORD(v283[0]) + v275 > v281 )
          goto LABEL_399;
        if ( LODWORD(v283[0]) + v275 == v281 )
        {
LABEL_9:
          HIDWORD(v283[0]) = v278;
          goto LABEL_10;
        }
        if ( (v16 & 1) == 0 )
        {
          v13 = v17 + 1;
          v14 = 0;
          LODWORD(v12) = v18;
          if ( v17 + 1 >= *(_DWORD *)(a1 + 24) )
            continue;
          v14 = 0;
LABEL_359:
          HIDWORD(v283[0]) = v18;
          LODWORD(v12) = v18;
          continue;
        }
        if ( (v276 & 0x100000000LL) == 0 )
        {
          v14 = 1;
          v13 = v17;
          BYTE4(v276) = 0;
          LODWORD(v12) = v18;
          if ( LODWORD(v283[0]) >= v281 )
            continue;
          BYTE4(v276) = 0;
          v13 = v17 + 1;
          goto LABEL_359;
        }
        ++v11;
        v13 = v17 + 1;
        v14 = 1;
        BYTE4(v276) = 1;
        LODWORD(v12) = v18;
        if ( v11 < (unsigned int)v276 )
        {
          HIDWORD(v283[0]) = v18;
          BYTE4(v276) = 1;
          LODWORD(v12) = v18;
        }
        continue;
      case 4:
        v32 = (LODWORD(v283[0]) + 7) & 0xFFFFFFF8;
        goto LABEL_41;
      case 5:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v115 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v116 = 8 - (v283[0] & 7);
            if ( v116 >= (unsigned int)v8 )
              v116 = v8;
            v117 = 8 - v116;
            v118 = v8 - v116;
            v10 = (*(unsigned __int8 *)(a2 + v115) >> (v283[0] & 7)) & (0xFFu >> v117);
            if ( v118 )
            {
              v119 = v115 + 1;
              do
              {
                if ( v118 >= 8 )
                  v120 = 8;
                else
                  v120 = v118;
                v121 = *(unsigned __int8 *)(a2 + v119++);
                v122 = v8 - v118;
                v118 -= v120;
                v10 |= ((0xFFu >> (8 - v120)) & v121) << v122;
              }
              while ( v118 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 540) = v10;
LABEL_333:
          LODWORD(v12) = v18;
          v13 = v17;
          goto LABEL_334;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_35154;
        goto LABEL_398;
      case 6:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) < 0xFFFFFFE0 )
        {
          printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
          v272 = &unk_344E6;
          goto LABEL_398;
        }
        v33 = LODWORD(v283[0]) + v8;
        if ( LODWORD(v283[0]) + (int)v8 <= v281 )
        {
          v139 = (unsigned __int64)LODWORD(v283[0]) >> 3;
          v140 = 8 - (v283[0] & 7);
          if ( v140 >= (unsigned int)v8 )
            v140 = v8;
          v141 = 8 - v140;
          v142 = v8 - v140;
          v10 = (*(unsigned __int8 *)(a2 + v139) >> (v283[0] & 7)) & (0xFFu >> v141);
          if ( v142 )
          {
            v143 = v139 + 1;
            do
            {
              if ( v142 >= 8 )
                v144 = 8;
              else
                v144 = v142;
              v145 = *(unsigned __int8 *)(a2 + v143++);
              v146 = v8 - v142;
              v142 -= v144;
              v10 |= ((0xFFu >> (8 - v144)) & v145) << v146;
            }
            while ( v142 );
          }
        }
        else
        {
          v10 = 0;
        }
        v13 = v10;
        *(_DWORD *)a4 = v10;
        LODWORD(v12) = v18;
LABEL_334:
        v14 = v16;
        LODWORD(v283[0]) = v33;
        continue;
      case 7:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) < 0xFFFFFFE0 )
        {
          printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
          v272 = &unk_3A60B;
          goto LABEL_398;
        }
        if ( LODWORD(v283[0]) + (int)v8 <= v281 )
        {
          v91 = (unsigned __int64)LODWORD(v283[0]) >> 3;
          v92 = 8 - (v283[0] & 7);
          if ( v92 >= (unsigned int)v8 )
            v92 = (unsigned __int8)v6[v12];
          v93 = 8 - v92;
          v94 = v8 - v92;
          v10 = (*(unsigned __int8 *)(a2 + v91) >> (v283[0] & 7)) & (0xFFu >> v93);
          if ( v94 )
          {
            v95 = v91 + 1;
            do
            {
              if ( v94 >= 8 )
                v96 = 8;
              else
                v96 = v94;
              v97 = *(unsigned __int8 *)(a2 + v95++);
              v98 = v8 - v94;
              v94 -= v96;
              v10 |= ((0xFFu >> (8 - v96)) & v97) << v98;
            }
            while ( v94 );
          }
        }
        else
        {
          v10 = 0;
        }
        LODWORD(v283[0]) += v8;
        *((_BYTE *)s + 52 * v17) = v10;
        goto LABEL_10;
      case 8:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) < 0xFFFFFFE0 )
        {
          printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
          v272 = &unk_3C226;
          goto LABEL_398;
        }
        if ( LODWORD(v283[0]) + (int)v8 <= v281 )
        {
          v163 = (unsigned __int64)LODWORD(v283[0]) >> 3;
          v164 = 8 - (v283[0] & 7);
          if ( v164 >= (unsigned int)v8 )
            v164 = (unsigned __int8)v6[v12];
          v165 = 8 - v164;
          v166 = v8 - v164;
          v10 = (*(unsigned __int8 *)(a2 + v163) >> (v283[0] & 7)) & (0xFFu >> v165);
          if ( v166 )
          {
            v167 = v163 + 1;
            do
            {
              if ( v166 >= 8 )
                v168 = 8;
              else
                v168 = v166;
              v169 = *(unsigned __int8 *)(a2 + v167++);
              v170 = v8 - v166;
              v166 -= v168;
              v10 |= ((0xFFu >> (8 - v168)) & v169) << v170;
            }
            while ( v166 );
          }
        }
        else
        {
          v10 = 0;
        }
        LODWORD(v283[0]) += v8;
        *((_DWORD *)s + 13 * v17 + 1) = v10;
        goto LABEL_10;
      case 9:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v59 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v60 = 8 - (v283[0] & 7);
            if ( v60 >= (unsigned int)v8 )
              v60 = (unsigned __int8)v6[v12];
            v61 = 8 - v60;
            v62 = v8 - v60;
            v10 = (*(unsigned __int8 *)(a2 + v59) >> (v283[0] & 7)) & (0xFFu >> v61);
            if ( v62 )
            {
              v63 = v59 + 1;
              do
              {
                if ( v62 >= 8 )
                  v64 = 8;
                else
                  v64 = v62;
                v65 = *(unsigned __int8 *)(a2 + v63++);
                v66 = v8 - v62;
                v62 -= v64;
                v10 |= ((0xFFu >> (8 - v64)) & v65) << v66;
              }
              while ( v62 );
            }
          }
          else
          {
            v10 = 0;
          }
          LODWORD(v283[0]) += v8;
          *((_DWORD *)s + 13 * v17 + 2) = v10;
          goto LABEL_10;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_34ADA;
        goto LABEL_398;
      case 0xA:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v155 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v156 = 8 - (v283[0] & 7);
            if ( v156 >= (unsigned int)v8 )
              v156 = (unsigned __int8)v6[v12];
            v157 = 8 - v156;
            v158 = v8 - v156;
            v10 = (*(unsigned __int8 *)(a2 + v155) >> (v283[0] & 7)) & (0xFFu >> v157);
            if ( v158 )
            {
              v159 = v155 + 1;
              do
              {
                if ( v158 >= 8 )
                  v160 = 8;
                else
                  v160 = v158;
                v161 = *(unsigned __int8 *)(a2 + v159++);
                v162 = v8 - v158;
                v158 -= v160;
                v10 |= ((0xFFu >> (8 - v160)) & v161) << v162;
              }
              while ( v158 );
            }
          }
          else
          {
            v10 = 0;
          }
          LODWORD(v283[0]) += v8;
          *((_DWORD *)s + 13 * v17 + 5) = v10;
          goto LABEL_10;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_34B07;
        goto LABEL_398;
      case 0xB:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) < 0xFFFFFFE0 )
        {
          printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
          v272 = &unk_32C73;
          goto LABEL_398;
        }
        if ( LODWORD(v283[0]) + (int)v8 <= v281 )
        {
          v43 = (unsigned __int64)LODWORD(v283[0]) >> 3;
          v44 = 8 - (v283[0] & 7);
          if ( v44 >= (unsigned int)v8 )
            v44 = (unsigned __int8)v6[v12];
          v45 = 8 - v44;
          v46 = v8 - v44;
          v10 = (*(unsigned __int8 *)(a2 + v43) >> (v283[0] & 7)) & (0xFFu >> v45);
          if ( v46 )
          {
            v47 = v43 + 1;
            do
            {
              if ( v46 >= 8 )
                v48 = 8;
              else
                v48 = v46;
              v49 = *(unsigned __int8 *)(a2 + v47++);
              v50 = v8 - v46;
              v46 -= v48;
              v10 |= ((0xFFu >> (8 - v48)) & v49) << v50;
            }
            while ( v46 );
          }
        }
        else
        {
          v10 = 0;
        }
        LODWORD(v283[0]) += v8;
        *((_DWORD *)s + 13 * v17 + 3) = v10;
        goto LABEL_10;
      case 0xC:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v51 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v52 = 8 - (v283[0] & 7);
            if ( v52 >= (unsigned int)v8 )
              v52 = (unsigned __int8)v6[v12];
            v53 = 8 - v52;
            v54 = v8 - v52;
            v10 = (*(unsigned __int8 *)(a2 + v51) >> (v283[0] & 7)) & (0xFFu >> v53);
            if ( v54 )
            {
              v55 = v51 + 1;
              do
              {
                if ( v54 >= 8 )
                  v56 = 8;
                else
                  v56 = v54;
                v57 = *(unsigned __int8 *)(a2 + v55++);
                v58 = v8 - v54;
                v54 -= v56;
                v10 |= ((0xFFu >> (8 - v56)) & v57) << v58;
              }
              while ( v54 );
            }
          }
          else
          {
            v10 = 0;
          }
          LODWORD(v283[0]) += v8;
          *((_DWORD *)s + 13 * v17 + 4) = v10;
          goto LABEL_10;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_3C868;
        goto LABEL_398;
      case 0xD:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) < 0xFFFFFFE0 )
        {
          printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
          v272 = &unk_33236;
          goto LABEL_398;
        }
        if ( LODWORD(v283[0]) + (int)v8 <= v281 )
        {
          v131 = (unsigned __int64)LODWORD(v283[0]) >> 3;
          v132 = 8 - (v283[0] & 7);
          if ( v132 >= (unsigned int)v8 )
            v132 = (unsigned __int8)v6[v12];
          v133 = 8 - v132;
          v134 = v8 - v132;
          v10 = (*(unsigned __int8 *)(a2 + v131) >> (v283[0] & 7)) & (0xFFu >> v133);
          if ( v134 )
          {
            v135 = v131 + 1;
            do
            {
              if ( v134 >= 8 )
                v136 = 8;
              else
                v136 = v134;
              v137 = *(unsigned __int8 *)(a2 + v135++);
              v138 = v8 - v134;
              v134 -= v136;
              v10 |= ((0xFFu >> (8 - v136)) & v137) << v138;
            }
            while ( v134 );
          }
        }
        else
        {
          v10 = 0;
        }
        LODWORD(v283[0]) += v8;
        *((_DWORD *)s + 13 * v17 + 6) = v10;
        goto LABEL_10;
      case 0xE:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v35 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v36 = 8 - (v283[0] & 7);
            if ( v36 >= (unsigned int)v8 )
              v36 = (unsigned __int8)v6[v12];
            v37 = 8 - v36;
            v38 = v8 - v36;
            v10 = (*(unsigned __int8 *)(a2 + v35) >> (v283[0] & 7)) & (0xFFu >> v37);
            if ( v38 )
            {
              v39 = v35 + 1;
              do
              {
                if ( v38 >= 8 )
                  v40 = 8;
                else
                  v40 = v38;
                v41 = *(unsigned __int8 *)(a2 + v39++);
                v42 = v8 - v38;
                v38 -= v40;
                v10 |= ((0xFFu >> (8 - v40)) & v41) << v42;
              }
              while ( v38 );
            }
          }
          else
          {
            v10 = 0;
          }
          LODWORD(v283[0]) += v8;
          *((_DWORD *)s + 13 * v17 + 7) = v10;
          goto LABEL_10;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_32C9D;
        goto LABEL_398;
      case 0xF:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v83 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v84 = 8 - (v283[0] & 7);
            if ( v84 >= (unsigned int)v8 )
              v84 = v8;
            v85 = 8 - v84;
            v86 = v8 - v84;
            v10 = (*(unsigned __int8 *)(a2 + v83) >> (v283[0] & 7)) & (0xFFu >> v85);
            if ( v86 )
            {
              v87 = v83 + 1;
              do
              {
                if ( v86 >= 8 )
                  v88 = 8;
                else
                  v88 = v86;
                v89 = *(unsigned __int8 *)(a2 + v87++);
                v90 = v8 - v86;
                v86 -= v88;
                v10 |= ((0xFFu >> (8 - v88)) & v89) << v90;
              }
              while ( v86 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 544) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_33264;
        goto LABEL_398;
      case 0x10:
        v29 = *(_DWORD **)(a1 + 976);
        if ( v29 )
        {
          v30 = *(_QWORD *)(a1 + 968);
          v31 = v11;
          if ( *(v29 - 1) != 1415872911 )
            __break(0x822Au);
          v28 = ((__int64 (__fastcall *)(__int64, _BYTE *, char *, __int64, _QWORD *, _QWORD, __int64))v29)(
                  16,
                  v6,
                  (char *)v283 + 4,
                  a2,
                  v283,
                  v282,
                  v30);
          v11 = v31;
        }
        else
        {
          HIDWORD(v283[0]) = v19 + 2;
          v231 = (unsigned __int8)v6[v12];
          if ( v231 - 33 <= 0xFFFFFFDF )
          {
            v256 = v11;
            printk(&unk_3399D, "syna_tcm_get_touch_data", (unsigned __int8)v6[v12]);
            v11 = v256;
            v28 = -241;
            v232 = LODWORD(v283[0]) + v231;
          }
          else
          {
            v232 = LODWORD(v283[0]) + v231;
            if ( LODWORD(v283[0]) + v231 <= v281 )
            {
              v233 = (unsigned __int64)LODWORD(v283[0]) >> 3;
              v234 = 8 - (v283[0] & 7);
              if ( v234 >= v231 )
                v234 = v231;
              v235 = 8 - v234;
              v236 = v231 - v234;
              v10 = (*(unsigned __int8 *)(a2 + v233) >> (v283[0] & 7)) & (0xFFu >> v235);
              if ( v236 )
              {
                v237 = v233 + 1;
                do
                {
                  if ( v236 >= 8 )
                    v238 = 8;
                  else
                    v238 = v236;
                  v239 = *(unsigned __int8 *)(a2 + v237++);
                  v240 = v231 - v236;
                  v236 -= v238;
                  v10 |= ((0xFFu >> (8 - v238)) & v239) << v240;
                }
                while ( v236 );
              }
            }
            else
            {
              v10 = 0;
            }
            v28 = 0;
          }
          LODWORD(v283[0]) = v232;
          *(_DWORD *)(a4 + 528) = v10;
        }
        LODWORD(v12) = v18;
        v13 = v17;
        v14 = v16;
        if ( (v28 & 0x80000000) == 0 )
          continue;
        v273 = &unk_3AE51;
        goto LABEL_426;
      case 0x11:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v99 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v100 = 8 - (v283[0] & 7);
            if ( v100 >= (unsigned int)v8 )
              v100 = v8;
            v101 = 8 - v100;
            v102 = v8 - v100;
            v10 = (*(unsigned __int8 *)(a2 + v99) >> (v283[0] & 7)) & (0xFFu >> v101);
            if ( v102 )
            {
              v103 = v99 + 1;
              do
              {
                if ( v102 >= 8 )
                  v104 = 8;
                else
                  v104 = v102;
                v105 = *(unsigned __int8 *)(a2 + v103++);
                v106 = v8 - v102;
                v102 -= v104;
                v10 |= ((0xFFu >> (8 - v104)) & v105) << v106;
              }
              while ( v102 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 548) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_36D66;
        goto LABEL_398;
      case 0x12:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v147 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v148 = 8 - (v283[0] & 7);
            if ( v148 >= (unsigned int)v8 )
              v148 = v8;
            v149 = 8 - v148;
            v150 = v8 - v148;
            v10 = (*(unsigned __int8 *)(a2 + v147) >> (v283[0] & 7)) & (0xFFu >> v149);
            if ( v150 )
            {
              v151 = v147 + 1;
              do
              {
                if ( v150 >= 8 )
                  v152 = 8;
                else
                  v152 = v150;
                v153 = *(unsigned __int8 *)(a2 + v151++);
                v154 = v8 - v150;
                v150 -= v152;
                v10 |= ((0xFFu >> (8 - v152)) & v153) << v154;
              }
              while ( v150 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 552) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_32CCB;
        goto LABEL_398;
      case 0x13:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v187 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v188 = 8 - (v283[0] & 7);
            if ( v188 >= (unsigned int)v8 )
              v188 = v8;
            v189 = 8 - v188;
            v190 = v8 - v188;
            v10 = (*(unsigned __int8 *)(a2 + v187) >> (v283[0] & 7)) & (0xFFu >> v189);
            if ( v190 )
            {
              v191 = v187 + 1;
              do
              {
                if ( v190 >= 8 )
                  v192 = 8;
                else
                  v192 = v190;
                v193 = *(unsigned __int8 *)(a2 + v191++);
                v194 = v8 - v190;
                v190 -= v192;
                v10 |= ((0xFFu >> (8 - v192)) & v193) << v194;
              }
              while ( v190 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 556) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_3517A;
        goto LABEL_398;
      case 0x14:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v107 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v108 = 8 - (v283[0] & 7);
            if ( v108 >= (unsigned int)v8 )
              v108 = v8;
            v109 = 8 - v108;
            v110 = v8 - v108;
            v10 = (*(unsigned __int8 *)(a2 + v107) >> (v283[0] & 7)) & (0xFFu >> v109);
            if ( v110 )
            {
              v111 = v107 + 1;
              do
              {
                if ( v110 >= 8 )
                  v112 = 8;
                else
                  v112 = v110;
                v113 = *(unsigned __int8 *)(a2 + v111++);
                v114 = v8 - v110;
                v110 -= v112;
                v10 |= ((0xFFu >> (8 - v112)) & v113) << v114;
              }
              while ( v110 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 560) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_37AEF;
        goto LABEL_398;
      case 0x15:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v123 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v124 = 8 - (v283[0] & 7);
            if ( v124 >= (unsigned int)v8 )
              v124 = v8;
            v125 = 8 - v124;
            v126 = v8 - v124;
            v10 = (*(unsigned __int8 *)(a2 + v123) >> (v283[0] & 7)) & (0xFFu >> v125);
            if ( v126 )
            {
              v127 = v123 + 1;
              do
              {
                if ( v126 >= 8 )
                  v128 = 8;
                else
                  v128 = v126;
                v129 = *(unsigned __int8 *)(a2 + v127++);
                v130 = v8 - v126;
                v126 -= v128;
                v10 |= ((0xFFu >> (8 - v128)) & v129) << v130;
              }
              while ( v126 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 564) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_33290;
        goto LABEL_398;
      case 0x16:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v179 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v180 = 8 - (v283[0] & 7);
            if ( v180 >= (unsigned int)v8 )
              v180 = v8;
            v181 = 8 - v180;
            v182 = v8 - v180;
            v10 = (*(unsigned __int8 *)(a2 + v179) >> (v283[0] & 7)) & (0xFFu >> v181);
            if ( v182 )
            {
              v183 = v179 + 1;
              do
              {
                if ( v182 >= 8 )
                  v184 = 8;
                else
                  v184 = v182;
                v185 = *(unsigned __int8 *)(a2 + v183++);
                v186 = v8 - v182;
                v182 -= v184;
                v10 |= ((0xFFu >> (8 - v184)) & v185) << v186;
              }
              while ( v182 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 568) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_332BB;
        goto LABEL_398;
      case 0x17:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v195 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v196 = 8 - (v283[0] & 7);
            if ( v196 >= (unsigned int)v8 )
              v196 = v8;
            v197 = 8 - v196;
            v198 = v8 - v196;
            v10 = (*(unsigned __int8 *)(a2 + v195) >> (v283[0] & 7)) & (0xFFu >> v197);
            if ( v198 )
            {
              v199 = v195 + 1;
              do
              {
                if ( v198 >= 8 )
                  v200 = 8;
                else
                  v200 = v198;
                v201 = *(unsigned __int8 *)(a2 + v199++);
                v202 = v8 - v198;
                v198 -= v200;
                v10 |= ((0xFFu >> (8 - v200)) & v201) << v202;
              }
              while ( v198 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 572) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_36D8C;
        goto LABEL_398;
      case 0x18:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) < 0xFFFFFFE0 )
        {
          printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
          v272 = &unk_31CCD;
          goto LABEL_398;
        }
        if ( LODWORD(v283[0]) + (int)v8 > v281 )
        {
          LODWORD(v283[0]) += v8;
          *(_DWORD *)(a4 + 4) = 0;
LABEL_170:
          v10 = 0;
          HIDWORD(v283[0]) = v278;
          v276 = 0x100000000LL;
          goto LABEL_10;
        }
        v75 = (unsigned __int64)LODWORD(v283[0]) >> 3;
        v76 = 8 - (v283[0] & 7);
        if ( v76 >= (unsigned int)v8 )
          v76 = v8;
        v77 = 8 - v76;
        v78 = v8 - v76;
        v10 = (*(unsigned __int8 *)(a2 + v75) >> (v283[0] & 7)) & (0xFFu >> v77);
        if ( v78 )
        {
          v79 = v75 + 1;
          do
          {
            if ( v78 >= 8 )
              v80 = 8;
            else
              v80 = v78;
            v81 = *(unsigned __int8 *)(a2 + v79++);
            v82 = v8 - v78;
            v78 -= v80;
            v10 |= ((0xFFu >> (8 - v80)) & v81) << v82;
          }
          while ( v78 );
        }
        LODWORD(v283[0]) += v8;
        v13 = v17;
        v14 = v16;
        *(_DWORD *)(a4 + 4) = v10;
        LODWORD(v276) = v10;
        BYTE4(v276) = 1;
        LODWORD(v12) = v18;
        if ( !v10 )
          goto LABEL_170;
        continue;
      case 0x19:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v67 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v68 = 8 - (v283[0] & 7);
            if ( v68 >= (unsigned int)v8 )
              v68 = v8;
            v69 = 8 - v68;
            v70 = v8 - v68;
            v10 = (*(unsigned __int8 *)(a2 + v67) >> (v283[0] & 7)) & (0xFFu >> v69);
            if ( v70 )
            {
              v71 = v67 + 1;
              do
              {
                if ( v70 >= 8 )
                  v72 = 8;
                else
                  v72 = v70;
                v73 = *(unsigned __int8 *)(a2 + v71++);
                v74 = v8 - v70;
                v70 -= v72;
                v10 |= ((0xFFu >> (8 - v72)) & v73) << v74;
              }
              while ( v70 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 576) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_3C253;
        goto LABEL_398;
      case 0x1A:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v219 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v220 = 8 - (v283[0] & 7);
            if ( v220 >= (unsigned int)v8 )
              v220 = v8;
            v221 = 8 - v220;
            v222 = v8 - v220;
            v10 = (*(unsigned __int8 *)(a2 + v219) >> (v283[0] & 7)) & (0xFFu >> v221);
            if ( v222 )
            {
              v223 = v219 + 1;
              do
              {
                if ( v222 >= 8 )
                  v224 = 8;
                else
                  v224 = v222;
                v225 = *(unsigned __int8 *)(a2 + v223++);
                v226 = v8 - v222;
                v222 -= v224;
                v10 |= ((0xFFu >> (8 - v224)) & v225) << v226;
              }
              while ( v222 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 580) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_36DB1;
        goto LABEL_398;
      case 0x1B:
        v25 = *(_DWORD **)(a1 + 976);
        if ( !v25 )
        {
          HIDWORD(v283[0]) = v19 + 2;
          v227 = v283[0];
          v228 = (unsigned __int8)v6[v12];
          v32 = LODWORD(v283[0]) + v228;
          if ( v282 >= (unsigned int)(LODWORD(v283[0]) + v228) >> 3 )
          {
            if ( v32 > LODWORD(v283[0]) )
            {
              v229 = (unsigned int)(LODWORD(v283[0]) + 16);
              v230 = v283[0] & 7;
              if ( (unsigned int)v229 > v281 )
              {
                LOWORD(v243) = 0;
              }
              else
              {
                v241 = (LODWORD(v283[0]) | 0xFFFFFFF8) + 16;
                v242 = (LODWORD(v283[0]) >> 3) + 1;
                v243 = *(unsigned __int8 *)(a2 + ((unsigned __int64)LODWORD(v283[0]) >> 3)) >> v230;
                do
                {
                  if ( v241 >= 8 )
                    v244 = 8;
                  else
                    v244 = v241;
                  v245 = *(unsigned __int8 *)(a2 + v242++);
                  v246 = 16 - v241;
                  v241 -= v244;
                  v243 |= ((0xFFu >> (8 - v244)) & v245) << v246;
                }
                while ( v241 );
              }
              *(_WORD *)(a4 + 532) = v243;
              if ( (unsigned int)v229 < v32 )
              {
                v247 = (unsigned int)(v227 + 32);
                if ( (unsigned int)v247 <= v281 )
                {
                  v249 = (v227 | 0xFFFFFFF8) + 16;
                  v250 = ((unsigned int)(v227 + 16) >> 3) + 1;
                  v248 = *(unsigned __int8 *)(a2 + (v229 >> 3)) >> v230;
                  do
                  {
                    if ( v249 >= 8 )
                      v251 = 8;
                    else
                      v251 = v249;
                    v252 = *(unsigned __int8 *)(a2 + v250++);
                    v253 = 16 - v249;
                    v249 -= v251;
                    v248 |= ((0xFFu >> (8 - v251)) & v252) << v253;
                  }
                  while ( v249 );
                }
                else
                {
                  LOWORD(v248) = 0;
                }
                *(_WORD *)(a4 + 534) = v248;
                if ( (unsigned int)v247 < v32 )
                {
                  v254 = (unsigned int)(v227 + 48);
                  if ( (unsigned int)v254 <= v281 )
                  {
                    v257 = (v227 | 0xFFFFFFF8) + 16;
                    v258 = ((unsigned int)(v227 + 32) >> 3) + 1;
                    v255 = *(unsigned __int8 *)(a2 + (v247 >> 3)) >> v230;
                    do
                    {
                      if ( v257 >= 8 )
                        v259 = 8;
                      else
                        v259 = v257;
                      v260 = *(unsigned __int8 *)(a2 + v258++);
                      v261 = 16 - v257;
                      v257 -= v259;
                      v255 |= ((0xFFu >> (8 - v259)) & v260) << v261;
                    }
                    while ( v257 );
                  }
                  else
                  {
                    LOWORD(v255) = 0;
                  }
                  *(_WORD *)(a4 + 536) = v255;
                  if ( (unsigned int)v254 < v32 )
                  {
                    if ( v227 + 64 <= v281 )
                    {
                      v263 = v254 >> 3;
                      v264 = v227 | 0xFFFFFFF8;
                      v265 = *(unsigned __int8 *)(a2 + v263);
                      v266 = v263 + 1;
                      v262 = v265 >> v230;
                      v267 = v264 + 16;
                      do
                      {
                        if ( v267 >= 8 )
                          v268 = 8;
                        else
                          v268 = v267;
                        v269 = *(unsigned __int8 *)(a2 + v266++);
                        v270 = 16 - v267;
                        v267 -= v268;
                        v262 |= ((0xFFu >> (8 - v268)) & v269) << v270;
                      }
                      while ( v267 );
                    }
                    else
                    {
                      LOWORD(v262) = 0;
                    }
                    *(_WORD *)(a4 + 538) = v262;
                  }
                }
              }
            }
            v8 = *(unsigned int *)(a4 + 528);
            if ( (unsigned int)v8 > 7 || ((1 << v8) & 0xC7) == 0 )
            {
              v271 = v11;
              printk(&unk_39BE7, "syna_tcm_get_gesture_data", v8);
              v11 = v271;
              v32 = LODWORD(v283[0]) + v228;
            }
          }
LABEL_41:
          LODWORD(v283[0]) = v32;
LABEL_10:
          LODWORD(v12) = v18;
          v13 = v17;
          v14 = v16;
          continue;
        }
        v26 = *(_QWORD *)(a1 + 968);
        v27 = v11;
        if ( *(v25 - 1) != 1415872911 )
          __break(0x822Au);
        v28 = ((__int64 (__fastcall *)(__int64, _BYTE *, char *, __int64, _QWORD *, _QWORD, __int64))v25)(
                27,
                v6,
                (char *)v283 + 4,
                a2,
                v283,
                v282,
                v26);
        v11 = v27;
        LODWORD(v12) = v18;
        v13 = v17;
        v14 = v16;
        if ( (v28 & 0x80000000) == 0 )
          continue;
        v273 = &unk_35793;
LABEL_426:
        v274 = v28;
        printk(v273, "syna_tcm_parse_touch_report", v8);
        result = v274;
LABEL_399:
        _ReadStatusReg(SP_EL0);
        return result;
      case 0x1C:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v203 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v204 = 8 - (v283[0] & 7);
            if ( v204 >= (unsigned int)v8 )
              v204 = v8;
            v205 = 8 - v204;
            v206 = v8 - v204;
            v10 = (*(unsigned __int8 *)(a2 + v203) >> (v283[0] & 7)) & (0xFFu >> v205);
            if ( v206 )
            {
              v207 = v203 + 1;
              do
              {
                if ( v206 >= 8 )
                  v208 = 8;
                else
                  v208 = v206;
                v209 = *(unsigned __int8 *)(a2 + v207++);
                v210 = v8 - v206;
                v206 -= v208;
                v10 |= ((0xFFu >> (8 - v208)) & v209) << v210;
              }
              while ( v206 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 584) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_339C6;
        goto LABEL_398;
      case 0x1D:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v211 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v212 = 8 - (v283[0] & 7);
            if ( v212 >= (unsigned int)v8 )
              v212 = v8;
            v213 = 8 - v212;
            v214 = v8 - v212;
            v10 = (*(unsigned __int8 *)(a2 + v211) >> (v283[0] & 7)) & (0xFFu >> v213);
            if ( v214 )
            {
              v215 = v211 + 1;
              do
              {
                if ( v214 >= 8 )
                  v216 = 8;
                else
                  v216 = v214;
                v217 = *(unsigned __int8 *)(a2 + v215++);
                v218 = v8 - v214;
                v214 -= v216;
                v10 |= ((0xFFu >> (8 - v216)) & v217) << v218;
              }
              while ( v214 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 588) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_3B58B;
        goto LABEL_398;
      case 0x1E:
        HIDWORD(v283[0]) = v19 + 2;
        v8 = (unsigned __int8)v6[v12];
        if ( (unsigned int)(v8 - 33) >= 0xFFFFFFE0 )
        {
          v33 = LODWORD(v283[0]) + v8;
          if ( LODWORD(v283[0]) + (int)v8 <= v281 )
          {
            v171 = (unsigned __int64)LODWORD(v283[0]) >> 3;
            v172 = 8 - (v283[0] & 7);
            if ( v172 >= (unsigned int)v8 )
              v172 = v8;
            v173 = 8 - v172;
            v174 = v8 - v172;
            v10 = (*(unsigned __int8 *)(a2 + v171) >> (v283[0] & 7)) & (0xFFu >> v173);
            if ( v174 )
            {
              v175 = v171 + 1;
              do
              {
                if ( v174 >= 8 )
                  v176 = 8;
                else
                  v176 = v174;
                v177 = *(unsigned __int8 *)(a2 + v175++);
                v178 = v8 - v174;
                v174 -= v176;
                v10 |= ((0xFFu >> (8 - v176)) & v177) << v178;
              }
              while ( v174 );
            }
          }
          else
          {
            v10 = 0;
          }
          *(_DWORD *)(a4 + 592) = v10;
          goto LABEL_333;
        }
        printk(&unk_3399D, "syna_tcm_get_touch_data", v8);
        v272 = &unk_3BBFF;
        goto LABEL_398;
      default:
        v21 = *(_DWORD **)(a1 + 960);
        v22 = v11;
        if ( !v21 )
          goto LABEL_19;
        v23 = *(_QWORD *)(a1 + 952);
        if ( *(v21 - 1) != 1415872911 )
          __break(0x8229u);
        v24 = ((__int64 (__fastcall *)(_QWORD, _BYTE *, char *, __int64, _QWORD *, _QWORD, __int64))v21)(
                v20,
                v6,
                (char *)v283 + 4,
                a2,
                v283,
                v282,
                v23);
        v11 = v22;
        if ( (v24 & 0x80000000) == 0 )
          goto LABEL_12;
        LODWORD(v12) = HIDWORD(v283[0]);
LABEL_19:
        if ( v20 != 202 )
        {
          printk(&unk_3519C, "syna_tcm_parse_touch_report", v20);
          LODWORD(v12) = HIDWORD(v283[0]);
        }
        v14 = v16;
        v11 = v22;
        HIDWORD(v283[0]) = v12 + 1;
        v13 = v17;
        LODWORD(v283[0]) += (unsigned __int8)v6[(unsigned int)v12];
        LODWORD(v12) = v18;
        continue;
    }
  }
}
