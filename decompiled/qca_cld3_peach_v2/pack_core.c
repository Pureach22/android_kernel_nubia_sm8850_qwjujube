__int64 __fastcall pack_core(
        __int64 packed_size_core,
        __int64 a2,
        char *a3,
        unsigned int a4,
        _DWORD *a5,
        __int64 a6,
        unsigned int *a7)
{
  char *v7; // x24
  unsigned int v8; // w19
  unsigned int v9; // w23
  unsigned int v11; // w8
  __int64 v13; // x26
  __int64 v15; // x9
  unsigned int *v16; // x1
  char *v17; // x0
  size_t v18; // x2
  int *v19; // x27
  __int64 v20; // x8
  unsigned int v21; // w27
  unsigned int v22; // w25
  int v23; // w8
  unsigned __int8 *v24; // x9
  int v25; // w8
  char v26; // w8
  unsigned __int8 *v27; // x26
  _BYTE *v28; // x8
  unsigned int v29; // w9
  int v30; // w10
  char v31; // w10
  char v32; // w10
  int v33; // w10
  char v34; // w9
  __int64 v35; // x8
  _BYTE *v36; // x26
  const void *v37; // x1
  _BYTE *v38; // x28
  void *v39; // x0
  unsigned __int8 *v40; // x8
  int v41; // w9
  unsigned __int8 v42; // w10
  unsigned __int8 v43; // w8
  _BYTE *v44; // x8
  char v45; // w10
  unsigned __int8 *v46; // x8
  _BYTE *v47; // x26
  unsigned __int8 v48; // w10
  unsigned __int8 v49; // w10
  unsigned __int8 v50; // w10
  char v51; // w8
  unsigned __int8 *v52; // x26
  unsigned __int8 v53; // w9
  unsigned __int8 v54; // w9
  unsigned __int8 v55; // w9
  unsigned int v56; // w9
  unsigned __int8 *v57; // x9
  unsigned __int8 v58; // w9
  _BYTE *v59; // x9
  char v60; // w10
  _BYTE *v61; // x28
  int v62; // w9
  int v63; // w9
  char v64; // w8
  unsigned __int8 *v65; // x8
  unsigned __int8 *v66; // x9
  unsigned __int8 v67; // w9
  unsigned __int8 *v68; // x26
  char v69; // w8
  unsigned __int8 *v70; // x8
  unsigned __int8 v71; // w10
  unsigned __int8 v72; // w8
  unsigned __int8 *v73; // x8
  unsigned __int8 *v74; // x9
  unsigned __int8 v75; // w9
  unsigned __int8 *v76; // x8
  unsigned __int8 v77; // w10
  unsigned __int8 v78; // w8
  unsigned __int8 *v79; // x8
  char v80; // w10
  int v81; // w10
  unsigned __int8 v82; // w8
  unsigned __int8 *v83; // x9
  unsigned __int8 v84; // w9
  unsigned __int8 *v85; // x9
  unsigned __int8 v86; // w9
  char v87; // w8
  unsigned __int8 *v88; // x28
  int v89; // w8
  _BYTE *v90; // x10
  unsigned int v91; // w9
  char v92; // w9
  char v93; // w9
  unsigned __int8 *v94; // x8
  unsigned __int8 v95; // w10
  unsigned __int8 v96; // w10
  unsigned __int8 *v97; // x8
  unsigned __int8 v98; // w10
  unsigned __int8 v99; // w8
  unsigned __int8 *v100; // x8
  unsigned __int8 v101; // w10
  unsigned __int8 v102; // w10
  unsigned __int8 v103; // w8
  unsigned __int8 *v104; // x26
  unsigned __int8 v105; // w9
  unsigned __int8 v106; // w9
  unsigned __int8 v107; // w9
  unsigned __int8 v108; // w9
  size_t v109; // x2
  int v110; // w8
  unsigned __int8 *v111; // x8
  unsigned __int8 v112; // w8
  unsigned __int8 *v113; // x26
  unsigned __int8 v114; // w9
  unsigned __int8 v115; // w9
  unsigned __int8 v116; // w9
  size_t v117; // x2
  unsigned __int8 *v118; // x8
  unsigned __int8 v119; // w10
  unsigned __int8 v120; // w8
  unsigned __int8 *v121; // x26
  unsigned __int8 v122; // w9
  unsigned __int8 *v123; // x8
  unsigned __int8 v124; // w10
  unsigned __int8 v125; // w8
  unsigned __int8 *v126; // x8
  unsigned __int8 v127; // w10
  unsigned __int8 v128; // w8
  unsigned __int8 *v129; // x9
  unsigned __int8 v130; // w9
  unsigned __int8 *v131; // x26
  unsigned __int8 v132; // w9
  unsigned __int8 v133; // w9
  unsigned __int8 v134; // w9
  unsigned __int8 v135; // w9
  size_t v136; // x2
  unsigned int v137; // w9
  unsigned __int8 *v138; // x26
  size_t v139; // x2
  unsigned __int8 *v140; // x28
  size_t v141; // x2
  unsigned __int8 *v142; // x26
  size_t v143; // x2
  unsigned __int8 *v144; // x8
  unsigned __int8 v145; // w9
  size_t v146; // x2
  unsigned __int8 *v147; // x8
  unsigned __int8 v148; // w10
  unsigned __int8 v149; // w8
  unsigned __int8 *v150; // x9
  unsigned __int8 v151; // w9
  unsigned __int8 *v152; // x9
  unsigned __int8 v153; // w9
  unsigned __int8 *v154; // x26
  unsigned __int8 v155; // w9
  void *v156; // x0
  __int16 v157; // w9
  unsigned int v158; // w8
  unsigned __int8 *v159; // x8
  char v160; // w9
  _BYTE *v161; // x8
  char v162; // w9
  unsigned __int8 *v163; // x8
  unsigned __int8 v164; // w10
  unsigned __int8 v165; // w10
  unsigned __int8 v166; // w8
  unsigned __int8 *v167; // x8
  unsigned __int8 *v168; // x8
  unsigned __int8 *v169; // x9
  unsigned __int8 v170; // w9
  unsigned __int8 *v171; // x26
  unsigned __int8 v172; // w9
  unsigned __int8 *v173; // x9
  unsigned __int8 v174; // w9
  unsigned __int8 *v175; // x26
  unsigned __int8 v176; // w9
  unsigned __int8 v177; // w9
  size_t v178; // x2
  unsigned int v179; // w8
  unsigned __int8 *v180; // x8
  unsigned __int8 v181; // w10
  unsigned __int8 v182; // w10
  unsigned __int8 v183; // w10
  unsigned __int8 v184; // w10
  unsigned __int8 v185; // w8
  unsigned __int8 *v186; // x8
  unsigned __int8 v187; // w8
  unsigned __int8 *v188; // x8
  unsigned __int8 v189; // w10
  unsigned __int8 v190; // w8
  unsigned __int8 *v191; // x8
  unsigned __int8 v192; // w10
  unsigned __int8 *v193; // x8
  unsigned __int8 *v194; // x8
  unsigned __int8 v195; // w10
  unsigned __int8 v196; // w10
  unsigned __int8 v197; // w10
  unsigned __int8 v198; // w8
  unsigned __int8 *v199; // x26
  unsigned __int8 v200; // w9
  unsigned __int8 *v201; // x26
  _BYTE *v202; // x28
  unsigned __int8 v203; // w9
  unsigned __int8 v204; // w9
  unsigned int v205; // w9
  unsigned __int8 *v206; // x8
  unsigned __int8 v207; // w10
  unsigned __int8 v208; // w10
  unsigned __int8 v209; // w8
  unsigned __int8 *v210; // x8
  unsigned __int8 v211; // w10
  unsigned __int8 *v212; // x8
  unsigned __int8 *v213; // x26
  void *v214; // x0
  const void *v215; // x1
  unsigned __int8 v216; // w9
  unsigned __int8 *v217; // x26
  char v218; // w8
  void *v219; // x0
  const void *v220; // x1
  unsigned __int8 *v221; // x8
  __int16 v222; // w8
  unsigned __int8 v223; // w9
  unsigned __int8 *v224; // x26
  size_t v225; // x2
  int v226; // w8
  unsigned __int8 *v227; // x8
  unsigned __int8 v228; // w8
  unsigned __int8 *v229; // x8
  unsigned __int8 v230; // w10
  unsigned __int8 v231; // w10
  unsigned __int8 *v232; // x8
  unsigned __int8 v233; // w10
  unsigned __int8 v234; // w8
  unsigned __int8 *v235; // x26
  size_t v236; // x2
  unsigned __int8 *v237; // x8
  unsigned __int8 v238; // w10
  unsigned __int8 v239; // w8
  unsigned __int8 *v240; // x8
  unsigned __int8 v241; // w10
  char v242; // w9
  unsigned __int8 *v243; // x8
  unsigned __int8 v244; // w10
  unsigned __int8 v245; // w10
  unsigned __int8 v246; // w8
  unsigned __int8 *v247; // x8
  unsigned __int8 v248; // w10
  unsigned __int8 v249; // w8
  __int64 v250; // x8
  _BYTE *v251; // x26
  unsigned __int8 *v252; // x28
  unsigned __int8 v253; // w9
  char v254; // w10
  size_t v255; // x2
  unsigned int v256; // w8
  unsigned __int8 *v257; // x8
  unsigned __int8 *v258; // x8
  unsigned __int8 v259; // w10
  unsigned __int8 v260; // w8
  char v261; // w10
  char v262; // w8
  unsigned __int8 *v263; // x8
  _BYTE *v264; // x26
  char v265; // w8
  unsigned __int8 *v266; // x26
  unsigned __int8 v267; // w9
  unsigned __int8 *v268; // x26
  unsigned __int8 v269; // w9
  unsigned __int8 v270; // w9
  unsigned __int8 v271; // w9
  unsigned __int8 v272; // w9
  size_t v273; // x2
  unsigned int v274; // w9
  unsigned __int8 v275; // w9
  size_t v276; // x2
  unsigned __int8 *v277; // x8
  __int64 v279; // [xsp+8h] [xbp-18h]
  unsigned int v280; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v281; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v282; // [xsp+18h] [xbp-8h]

  v279 = packed_size_core;
  v282 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v280 = 0;
  if ( a2 )
  {
    v7 = a3;
    v8 = 268435460;
    if ( a3 )
    {
      v9 = a4;
      if ( a4 )
      {
        if ( a5 )
        {
          v11 = *(unsigned __int8 *)(a6 + 14);
          v13 = a6;
          if ( *(_BYTE *)(a6 + 14) )
          {
            v8 = 268435457;
            while ( 2 )
            {
              if ( v9 >= v11 )
              {
                switch ( *(_WORD *)(v13 + 12) )
                {
                  case 1:
                  case 3:
                  case 4:
                  case 5:
                  case 6:
                  case 0xB:
                  case 0xD:
                  case 0x11:
                  case 0x14:
                  case 0x1F:
                  case 0x20:
                  case 0x21:
                  case 0x23:
                    v16 = &v281;
                    LOWORD(v281) = *(_WORD *)(a2 + *(unsigned int *)(v13 + 8));
                    goto LABEL_12;
                  case 2:
                  case 7:
                  case 9:
                  case 0xA:
                  case 0xC:
                  case 0xE:
                  case 0xF:
                  case 0x10:
                  case 0x12:
                  case 0x13:
                  case 0x15:
                  case 0x16:
                  case 0x17:
                  case 0x1B:
                  case 0x1C:
                  case 0x22:
                  case 0x26:
                  case 0x27:
                    *v7 = *(_BYTE *)(a2 + *(unsigned int *)(v13 + 8));
                    goto LABEL_8;
                  case 8:
                    v17 = v7;
                    v18 = 6;
                    v16 = (unsigned int *)(a2 + *(unsigned int *)(v13 + 8));
                    goto LABEL_13;
                  case 0x18:
                  case 0x24:
                    v16 = &v281;
                    v281 = *(_DWORD *)(a2 + *(unsigned int *)(v13 + 8));
                    goto LABEL_22;
                  case 0x19:
                    v19 = (int *)(a2 + *(unsigned int *)(v13 + 8));
                    v281 = *v19;
                    qdf_mem_copy(v7, &v281, 4u);
                    v17 = v7 + 4;
                    v16 = &v281;
                    v18 = 4;
                    v281 = v19[1];
                    goto LABEL_13;
                  case 0x1A:
                    v16 = (unsigned int *)(a2 + *(unsigned int *)(v13 + 8));
LABEL_12:
                    v17 = v7;
                    v18 = 2;
                    goto LABEL_13;
                  case 0x1D:
                    v17 = v7;
                    v18 = 8;
                    v16 = (unsigned int *)(a2 + *(unsigned int *)(v13 + 8));
                    goto LABEL_13;
                  case 0x1E:
                    v17 = v7;
                    v18 = 16;
                    v16 = (unsigned int *)(a2 + *(unsigned int *)(v13 + 8));
                    goto LABEL_13;
                  case 0x25:
                    v16 = (unsigned int *)(a2 + *(unsigned int *)(v13 + 8));
LABEL_22:
                    v17 = v7;
                    v18 = 4;
                    goto LABEL_13;
                  case 0x28:
                    v17 = v7;
                    v18 = 3;
                    v16 = (unsigned int *)(a2 + *(unsigned int *)(v13 + 8));
LABEL_13:
                    packed_size_core = (__int64)qdf_mem_copy(v17, v16, v18);
LABEL_8:
                    v15 = *(unsigned __int8 *)(v13 + 14);
                    v7 += v15;
                    v9 -= v15;
                    *a5 += v15;
                    v11 = *(unsigned __int8 *)(v13 + 30);
                    v13 += 16;
                    if ( v11 )
                      continue;
                    goto LABEL_24;
                  default:
                    goto LABEL_558;
                }
              }
              break;
            }
LABEL_557:
            v8 = 268435461;
          }
          else
          {
LABEL_24:
            v8 = 0;
            while ( *((unsigned __int8 *)a7 + 38) != 255 || *((_BYTE *)a7 + 39) )
            {
              if ( *(_BYTE *)(a2 + *a7 + a7[1]) && v9 < *((unsigned __int16 *)a7 + 13) )
                goto LABEL_557;
              if ( !*((_WORD *)a7 + 12) )
              {
                v21 = 1;
LABEL_34:
                v22 = 0;
                while ( 2 )
                {
                  v23 = *((unsigned __int16 *)a7 + 15);
                  v280 = 0;
                  switch ( v23 )
                  {
                    case 1:
                      packed_size_core = dot11f_pack_ie_gtk(
                                           packed_size_core,
                                           a2 + *a7 + 46LL * v22,
                                           v7,
                                           v9,
                                           (int *)&v280);
                      goto LABEL_553;
                    case 2:
                      v199 = (unsigned __int8 *)(a2 + *a7 + 34LL * v22);
                      v25 = *v199;
                      if ( !*v199 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < 0x21 )
                        goto LABEL_35;
                      *v7 = 4;
                      v38 = v7 + 1;
                      v280 += 2;
                      qdf_mem_copy(v7 + 2, v199 + 1, 2u);
                      v280 += 2;
                      qdf_mem_copy(v7 + 4, v199 + 3, 6u);
                      v200 = v199[9];
                      v280 += 6;
                      v7[10] = v200;
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 11, v199 + 10, 0x18u);
                      v56 = v280 + 24;
                      goto LABEL_365;
                    case 3:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 50LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v87 = 3;
                      goto LABEL_326;
                    case 4:
                      v65 = (unsigned __int8 *)(a2 + *a7 - v22 + 8LL * v22);
                      v41 = *v65;
                      if ( !*v65 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 6 )
                        goto LABEL_510;
                      *v7 = 1;
                      v47 = v7 + 1;
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, v65 + 1, 6u);
                      v41 = 0;
                      v51 = v280 + 6;
                      v280 += 6;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 5:
                      v68 = (unsigned __int8 *)(a2 + *a7 + 53LL * v22);
                      v25 = *v68;
                      if ( !*v68 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 <= v68[2] )
                        goto LABEL_35;
                      v69 = 51;
                      goto LABEL_235;
                    case 6:
                      v74 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v74;
                      if ( !*v74 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      *v7 = 2;
                      v75 = v74[1];
                      v280 += 2;
                      v7[2] = v75;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 7:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 226LL * v22);
                      v25 = *v27;
                      if ( *v27 )
                      {
                        v25 = 268435461;
                        if ( v9 >= v27[1] )
                          goto LABEL_230;
                      }
                      goto LABEL_35;
                    case 8:
                      v277 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v277;
                      if ( *v277 )
                      {
                        v41 = 268435461;
                        if ( v9 >= 2 )
                        {
                          *v7 = 2;
                          v264 = v7 + 1;
                          v280 += 2;
                          packed_size_core = (__int64)qdf_mem_copy(v7 + 2, v277 + 1, 2u);
                          v41 = 0;
                          v265 = v280 + 2;
                          v280 += 2;
                          if ( v7 != (char *)-1LL )
                            goto LABEL_551;
                        }
                      }
                      goto LABEL_510;
                    case 9:
                      v213 = (unsigned __int8 *)(a2 + *a7 + 258LL * v22);
                      v25 = *v213;
                      if ( !*v213 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 <= v213[2] )
                        goto LABEL_35;
                      v262 = 11;
                      goto LABEL_541;
                    case 10:
                      v213 = (unsigned __int8 *)(a2 + *a7 + 258LL * v22);
                      v25 = *v213;
                      if ( !*v213 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 <= v213[2] )
                        goto LABEL_35;
                      v262 = 66;
                      goto LABEL_541;
                    case 11:
                      v213 = (unsigned __int8 *)(a2 + *a7 + 258LL * v22);
                      v25 = *v213;
                      if ( !*v213 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 <= v213[2] )
                        goto LABEL_35;
                      v262 = 71;
LABEL_541:
                      v214 = v7 + 3;
                      v215 = v213 + 3;
                      *v7 = v262;
                      v202 = v7 + 1;
                      v275 = v213[1];
                      v280 += 2;
                      v7[2] = v275;
                      goto LABEL_542;
                    case 12:
                      v94 = (unsigned __int8 *)(a2 + *a7 + 6LL * v22);
                      v41 = *v94;
                      if ( !*v94 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 4 )
                        goto LABEL_510;
                      *v7 = 57;
                      v47 = v7 + 1;
                      v95 = v94[1];
                      v280 += 2;
                      v7[2] = v95;
                      v96 = v94[2];
                      ++v280;
                      v7[3] = v96;
                      LOWORD(v281) = *((_WORD *)v94 + 2);
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 4, &v281, 2u);
                      v41 = 0;
                      v51 = v280 + 2;
                      v280 += 2;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 13:
                      v68 = (unsigned __int8 *)(a2 + *a7 + 258LL * v22);
                      v25 = *v68;
                      if ( !*v68 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 <= v68[2] )
                        goto LABEL_35;
                      v69 = 75;
                      goto LABEL_235;
                    case 14:
                      v79 = (unsigned __int8 *)(a2 + *a7 + 6LL * v22);
                      v41 = *v79;
                      if ( !*v79 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 5 )
                        goto LABEL_510;
                      *v7 = 70;
                      v80 = *(_DWORD *)(v79 + 1);
                      v280 += 2;
                      v7[2] = v80;
                      v81 = *(_DWORD *)(v79 + 1) >> 8;
                      ++v280;
                      v7[3] = v81;
                      LOBYTE(v81) = *(_WORD *)(v79 + 3);
                      ++v280;
                      v7[4] = v81;
                      LOBYTE(v81) = v79[4];
                      ++v280;
                      v7[5] = v81;
                      v82 = v79[5];
                      ++v280;
                      v7[6] = v82;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 15:
                      v217 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v217;
                      if ( !*v217 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v217[1] )
                        goto LABEL_35;
                      v218 = 10;
                      goto LABEL_536;
                    case 16:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 34LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v37 = v27 + 2;
                      v38 = v7 + 1;
                      *v7 = 0;
                      v39 = v7 + 2;
                      goto LABEL_327;
                    case 17:
                      packed_size_core = dot11f_pack_ie_schedule(
                                           packed_size_core,
                                           a2 + *a7 + 16LL * v22,
                                           v7,
                                           v9,
                                           (int *)&v280);
                      goto LABEL_553;
                    case 18:
                      packed_size_core = dot11f_pack_ie_tclas(
                                           packed_size_core,
                                           a2 + *a7 + 46LL * v22,
                                           v7,
                                           v9,
                                           (int *)&v280);
                      goto LABEL_553;
                    case 19:
                      v24 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v24;
                      if ( !*v24 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      v26 = 44;
                      goto LABEL_495;
                    case 20:
                      v168 = (unsigned __int8 *)(a2 + *a7 + 8LL * v22);
                      v41 = *v168;
                      if ( !*v168 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 4 )
                        goto LABEL_510;
                      *v7 = 43;
                      v47 = v7 + 1;
                      v281 = *((_DWORD *)v168 + 1);
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, &v281, 4u);
                      v41 = 0;
                      v51 = v280 + 4;
                      v280 += 4;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 21:
                      v88 = (unsigned __int8 *)(a2 + *a7 + 6LL * v22);
                      v89 = *v88;
                      if ( !*v88 )
                        goto LABEL_482;
                      v89 = 268435461;
                      if ( v9 < 4 )
                        goto LABEL_482;
                      *v7 = 1;
                      LOWORD(v281) = *((_WORD *)v88 + 1);
                      v280 += 2;
                      qdf_mem_copy(v7 + 2, &v281, 2u);
                      LOWORD(v281) = *((_WORD *)v88 + 2);
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 4, &v281, 2u);
                      v90 = v7 + 1;
                      v91 = v280 + 2;
                      goto LABEL_480;
                    case 22:
                      packed_size_core = dot11f_pack_ie_tspec(
                                           packed_size_core,
                                           a2 + *a7 + 60LL * v22,
                                           v7,
                                           v9,
                                           (int *)&v280);
                      goto LABEL_553;
                    case 23:
                      packed_size_core = dot11f_pack_ie_vht_caps(
                                           packed_size_core,
                                           a2 + *a7 + 16LL * v22,
                                           v7,
                                           v9,
                                           (int *)&v280);
                      goto LABEL_553;
                    case 24:
                      v46 = (unsigned __int8 *)(a2 + *a7 + 6LL * v22);
                      v41 = *v46;
                      if ( !*v46 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 5 )
                        goto LABEL_510;
                      *v7 = -64;
                      v47 = v7 + 1;
                      v48 = v46[1];
                      v280 += 2;
                      v7[2] = v48;
                      v49 = v46[2];
                      ++v280;
                      v7[3] = v49;
                      v50 = v46[3];
                      ++v280;
                      v7[4] = v50;
                      LOWORD(v281) = *((_WORD *)v46 + 2);
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 5, &v281, 2u);
                      v41 = 0;
                      v51 = v280 + 2;
                      v280 += 2;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 25:
                      packed_size_core = dot11f_pack_ie_wmm_schedule(
                                           packed_size_core,
                                           a2 + *a7 + 16LL * v22,
                                           v7,
                                           v9,
                                           (int *)&v280);
                      goto LABEL_553;
                    case 26:
                      packed_size_core = dot11f_pack_ie_wmmtclas(
                                           packed_size_core,
                                           a2 + *a7 + 48LL * v22,
                                           v7,
                                           v9,
                                           (int *)&v280);
                      goto LABEL_553;
                    case 27:
                      v258 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v258;
                      if ( *v258 )
                      {
                        v41 = 268435461;
                        if ( v9 >= 2 )
                        {
                          *v7 = -35;
                          v280 += 2;
                          v7[2] = 0;
                          ++v280;
                          v7[3] = 80;
                          ++v280;
                          v7[4] = -14;
                          ++v280;
                          v7[5] = 2;
                          ++v280;
                          v7[6] = 7;
                          v259 = v258[1];
                          ++v280;
                          v7[7] = v259;
                          v260 = v258[2];
                          ++v280;
                          v7[8] = v260;
                          v261 = v280 + 1;
                          v41 = 0;
                          ++v280;
                          if ( v7 != (char *)-1LL )
                            v7[1] = v261 - 2;
                        }
                      }
                      goto LABEL_510;
                    case 28:
                      v240 = (unsigned __int8 *)(a2 + *a7 + 8LL * v22);
                      v41 = *v240;
                      if ( !*v240 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 5 )
                        goto LABEL_510;
                      *v7 = -35;
                      v47 = v7 + 1;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 80;
                      ++v280;
                      v7[4] = -14;
                      ++v280;
                      v7[5] = 2;
                      ++v280;
                      v7[6] = 8;
                      v241 = v240[1];
                      ++v280;
                      v7[7] = v241;
                      v281 = *((_DWORD *)v240 + 1);
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 8, &v281, 4u);
                      v41 = 0;
                      v51 = v280 + 4;
                      v280 += 4;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 29:
                      packed_size_core = dot11f_pack_ie_wmmtspec(
                                           packed_size_core,
                                           a2 + *a7 + 60LL * v22,
                                           v7,
                                           v9,
                                           (int *)&v280);
                      goto LABEL_553;
                    case 30:
                      v100 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v100;
                      if ( !*v100 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 3 )
                        goto LABEL_510;
                      *v7 = -62;
                      v101 = v100[1];
                      v280 += 2;
                      v7[2] = v101;
                      v102 = v100[2];
                      ++v280;
                      v7[3] = v102;
                      v103 = v100[3];
                      ++v280;
                      v7[4] = v103;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 31:
                    case 39:
                      v24 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v24;
                      if ( !*v24 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      v26 = 1;
                      goto LABEL_495;
                    case 32:
                      v257 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v257;
                      if ( *v257 )
                      {
                        v41 = 268435461;
                        if ( v9 >= 2 )
                        {
                          *v7 = 2;
                          v47 = v7 + 1;
                          LOWORD(v281) = *(_WORD *)(v257 + 1);
                          v280 += 2;
                          packed_size_core = (__int64)qdf_mem_copy(v7 + 2, &v281, 2u);
                          v41 = 0;
                          v51 = v280 + 2;
                          v280 += 2;
                          if ( v7 != (char *)-1LL )
                            goto LABEL_509;
                        }
                      }
                      goto LABEL_510;
                    case 33:
                      v268 = (unsigned __int8 *)(a2 + *a7 - v22 + 8LL * v22);
                      v25 = *v268;
                      if ( !*v268 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < (*(_WORD *)(v268 + 1) & 2 | 4u) )
                        goto LABEL_35;
                      *v7 = -1;
                      v202 = v7 + 1;
                      v280 += 2;
                      v7[2] = -121;
                      v269 = v268[1];
                      ++v280;
                      v7[3] = v269;
                      v270 = v268[2];
                      ++v280;
                      v7[4] = v270;
                      v271 = v268[3];
                      ++v280;
                      v7[5] = v271;
                      v272 = v268[4];
                      ++v280;
                      v7[6] = v272;
                      v273 = *(_WORD *)(v268 + 1) & 2;
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 7, v268 + 5, v273);
                      v274 = v280;
                      v226 = *(_WORD *)(v268 + 1) & 2;
                      goto LABEL_544;
                    case 34:
                      v131 = (unsigned __int8 *)(a2 + *a7 - v22 + 8LL * v22);
                      v25 = *v131;
                      if ( !*v131 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < (*(_WORD *)(v131 + 1) & 2 | 4u) )
                        goto LABEL_35;
                      *v7 = -92;
                      v38 = v7 + 1;
                      v132 = v131[1];
                      v280 += 2;
                      v7[2] = v132;
                      v133 = v131[2];
                      ++v280;
                      v7[3] = v133;
                      v134 = v131[3];
                      ++v280;
                      v7[4] = v134;
                      v135 = v131[4];
                      ++v280;
                      v7[5] = v135;
                      v136 = *(_WORD *)(v131 + 1) & 2;
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 6, v131 + 5, v136);
                      v137 = v280;
                      v110 = *(_WORD *)(v131 + 1) & 2;
                      goto LABEL_364;
                    case 35:
                      v57 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v57;
                      if ( !*v57 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      *v7 = -92;
                      v58 = v57[1];
                      v280 += 2;
                      v7[2] = v58;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 36:
                      v73 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v73;
                      if ( !*v73 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = 4;
                      v47 = v7 + 1;
                      LOWORD(v281) = *((_WORD *)v73 + 1);
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, &v281, 2u);
                      v41 = 0;
                      v51 = v280 + 2;
                      v280 += 2;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 37:
                      v24 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v24;
                      if ( !*v24 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      v26 = 76;
                      goto LABEL_495;
                    case 38:
                      packed_size_core = dot11f_pack_ie_neighbor_rpt(v279, a2 + *a7 + 548LL * v22, v7, v9, (int *)&v280);
                      goto LABEL_553;
                    case 40:
                      v263 = (unsigned __int8 *)(a2 + *a7 - v22 + 8LL * v22);
                      v41 = *v263;
                      if ( !*v263 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 6 )
                        goto LABEL_510;
                      *v7 = 2;
                      v264 = v7 + 1;
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, v263 + 1, 6u);
                      v41 = 0;
                      v265 = v280 + 6;
                      v280 += 6;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
LABEL_551:
                      *v264 = v265 - 2;
                      goto LABEL_510;
                    case 41:
                      v40 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v40;
                      if ( !*v40 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = 1;
                      v42 = v40[1];
                      v280 += 2;
                      v7[2] = v42;
                      v43 = v40[2];
                      ++v280;
                      v7[3] = v43;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 42:
                      v28 = (_BYTE *)(a2 + *a7 + 19LL * v22);
                      if ( *v28 )
                      {
                        if ( v28[1] == 4 )
                          v29 = 18;
                        else
                          v29 = 2;
                        v30 = 268435461;
                        if ( v29 <= v9 )
                        {
                          *v7 = -1;
                          v280 += 2;
                          v7[2] = 89;
                          v31 = v28[1];
                          ++v280;
                          v7[3] = v31;
                          v32 = v28[2];
                          ++v280;
                          v7[4] = v32;
                          v33 = (unsigned __int8)v28[1];
                          v34 = ++v280;
                          if ( v33 == 4 )
                          {
                            packed_size_core = (__int64)qdf_mem_copy(v7 + 5, v28 + 3, 0x10u);
                            v34 = v280 + 16;
                            v280 += 16;
                          }
                          v30 = 0;
                          if ( v7 != (char *)-1LL )
                            v7[1] = v34 - 2;
                        }
                        v8 |= v30;
                      }
                      goto LABEL_36;
                    case 43:
                      v144 = (unsigned __int8 *)(a2 + *a7 - v22 + 8LL * v22);
                      v41 = *v144;
                      if ( !*v144 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 6 )
                        goto LABEL_510;
                      *v7 = 3;
                      v47 = v7 + 1;
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, v144 + 1, 6u);
                      v41 = 0;
                      v51 = v280 + 6;
                      v280 += 6;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 44:
                      packed_size_core = dot11f_pack_ie_transmit_power_env(
                                           packed_size_core,
                                           a2 + *a7 + 27LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 45:
                      v206 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v206;
                      if ( !*v206 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 3 )
                        goto LABEL_510;
                      *v7 = -93;
                      v207 = v206[1];
                      v280 += 2;
                      v7[2] = v207;
                      v208 = v206[2];
                      ++v280;
                      v7[3] = v208;
                      v209 = v206[3];
                      ++v280;
                      v7[4] = v209;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 46:
                      v159 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v159;
                      if ( !*v159 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = -59;
                      v47 = v7 + 1;
                      LOWORD(v281) = *((_WORD *)v159 + 1);
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, &v281, 2u);
                      v41 = 0;
                      v51 = v280 + 2;
                      v280 += 2;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 47:
                      v201 = (unsigned __int8 *)(a2 + *a7 + 8LL * v22);
                      v25 = *v201;
                      if ( !*v201 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < 6 )
                        goto LABEL_35;
                      *v7 = 4;
                      v202 = v7 + 1;
                      v203 = v201[1];
                      v280 += 2;
                      v7[2] = v203;
                      v204 = v201[2];
                      ++v280;
                      v7[3] = v204;
                      LOWORD(v281) = *((_WORD *)v201 + 2);
                      ++v280;
                      qdf_mem_copy(v7 + 4, &v281, 2u);
                      LOWORD(v281) = *((_WORD *)v201 + 3);
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 6, &v281, 2u);
                      v205 = v280 + 2;
                      goto LABEL_545;
                    case 48:
                      v27 = (unsigned __int8 *)(a2 + *a7 - v22 + ((unsigned __int64)v22 << 8));
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v87 = 16;
                      goto LABEL_326;
                    case 49:
                      v243 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v243;
                      if ( !*v243 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 3 )
                        goto LABEL_510;
                      *v7 = 37;
                      v244 = v243[1];
                      v280 += 2;
                      v7[2] = v244;
                      v245 = v243[2];
                      ++v280;
                      v7[3] = v245;
                      v246 = v243[3];
                      ++v280;
                      v7[4] = v246;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 50:
                      v35 = *a7;
                      v281 = 0;
                      v36 = (_BYTE *)(a2 + v35 + 232LL * v22);
                      if ( !*v36 )
                        goto LABEL_552;
                      packed_size_core = get_packed_size_core(
                                           v279,
                                           (__int64)v36,
                                           (int *)&v281,
                                           IES_ChannelSwitchWrapper);
                      if ( (_DWORD)packed_size_core )
                        goto LABEL_553;
                      if ( !*v36 )
                        goto LABEL_552;
                      packed_size_core = 268435461;
                      if ( v281 <= v9 )
                      {
                        *v7 = -60;
                        v280 += 2;
                        packed_size_core = pack_core(
                                             v279,
                                             v36,
                                             v7 + 2,
                                             v9 - 2,
                                             &v280,
                                             &FFS_ChannelSwitchWrapper,
                                             IES_ChannelSwitchWrapper);
                        if ( v7 != (char *)-1LL )
                          v7[1] = v280 - 2;
                      }
                      goto LABEL_553;
                    case 51:
                      v61 = (_BYTE *)(a2 + *a7 + 248LL * v22);
                      if ( *v61 )
                      {
                        v62 = 268435461;
                        if ( 3 * (unsigned int)(unsigned __int8)v61[7] + 6 <= v9 )
                        {
                          *v7 = 7;
                          v280 += 2;
                          qdf_mem_copy(v7 + 2, v61 + 1, 3u);
                          v280 += 3;
                          packed_size_core = (__int64)qdf_mem_copy(v7 + 5, v61 + 4, 3u);
                          v63 = (unsigned __int8)v61[7];
                          v64 = v280 + 3;
                          v280 += 3;
                          if ( v63 )
                          {
                            packed_size_core = (__int64)qdf_mem_copy(v7 + 8, v61 + 8, (unsigned int)(3 * v63));
                            v64 = 3 * v61[7] + v280;
                            v280 += 3 * (unsigned __int8)v61[7];
                          }
                          v62 = 0;
                          if ( v7 != (char *)-1LL )
                            v7[1] = v64 - 2;
                        }
                      }
                      else
                      {
                        v62 = 0;
                      }
                      v8 |= v62;
                      goto LABEL_36;
                    case 52:
                      v152 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v152;
                      if ( !*v152 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      *v7 = 3;
                      v153 = v152[1];
                      v280 += 2;
                      v7[2] = v153;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 53:
                      packed_size_core = dot11f_pack_ie_edca_param_set(
                                           packed_size_core,
                                           a2 + *a7 + 20LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 54:
                      v24 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v24;
                      if ( !*v24 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      v26 = 42;
                      goto LABEL_495;
                    case 55:
                      v217 = (unsigned __int8 *)(a2 + *a7 + 22LL * v22);
                      v25 = *v217;
                      if ( !*v217 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v217[1] )
                        goto LABEL_35;
                      v219 = v7 + 6;
                      *v7 = -100;
                      v220 = v217 + 2;
                      v202 = v7 + 1;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 64;
                      ++v280;
                      v7[4] = -106;
                      ++v280;
                      v7[5] = 0;
                      goto LABEL_502;
                    case 56:
                      v147 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v147;
                      if ( !*v147 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = -35;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 64;
                      ++v280;
                      v7[4] = -106;
                      ++v280;
                      v7[5] = 1;
                      v148 = v147[1];
                      ++v280;
                      v7[6] = v148;
                      v149 = v147[2];
                      ++v280;
                      v7[7] = v149;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 57:
                      v229 = (unsigned __int8 *)(a2 + *a7 + 6LL * v22);
                      v41 = *v229;
                      if ( !*v229 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 4 )
                        goto LABEL_510;
                      *v7 = -35;
                      v47 = v7 + 1;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 64;
                      ++v280;
                      v7[4] = -106;
                      ++v280;
                      v7[5] = 7;
                      v230 = v229[1];
                      ++v280;
                      v7[6] = v230;
                      v231 = v229[2];
                      ++v280;
                      v7[7] = v231;
                      LOWORD(v281) = *((_WORD *)v229 + 2);
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 8, &v281, 2u);
                      v41 = 0;
                      v51 = v280 + 2;
                      v280 += 2;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 58:
                      v213 = (unsigned __int8 *)(a2 + *a7 + 11LL * v22);
                      v25 = *v213;
                      if ( !*v213 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 <= v213[2] )
                        goto LABEL_35;
                      v214 = v7 + 7;
                      *v7 = -35;
                      v215 = v213 + 3;
                      v202 = v7 + 1;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 64;
                      ++v280;
                      v7[4] = -106;
                      ++v280;
                      v7[5] = 8;
                      v216 = v213[1];
                      ++v280;
                      v7[6] = v216;
                      goto LABEL_542;
                    case 59:
                      v97 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v97;
                      if ( !*v97 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = -106;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 64;
                      ++v280;
                      v7[4] = -106;
                      ++v280;
                      v7[5] = 0;
                      v98 = v97[1];
                      ++v280;
                      v7[6] = v98;
                      v99 = v97[2];
                      ++v280;
                      v7[7] = v99;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 60:
                      v111 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v41 = *v111;
                      if ( !*v111 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( !v9 )
                        goto LABEL_510;
                      *v7 = -35;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 64;
                      ++v280;
                      v7[4] = -106;
                      ++v280;
                      v7[5] = 3;
                      v112 = v111[1];
                      ++v280;
                      v7[6] = v112;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 61:
                      v217 = (unsigned __int8 *)(a2 + *a7 + 17LL * v22);
                      v25 = *v217;
                      if ( !*v217 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v217[1] )
                        goto LABEL_35;
                      v218 = 127;
                      goto LABEL_536;
                    case 62:
                      v217 = (unsigned __int8 *)(a2 + *a7 + 14LL * v22);
                      v25 = *v217;
                      if ( !*v217 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v217[1] )
                        goto LABEL_35;
                      v218 = 50;
                      goto LABEL_536;
                    case 63:
                      v52 = (unsigned __int8 *)(a2 + *a7 + 8LL * v22);
                      v25 = *v52;
                      if ( !*v52 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < 5 )
                        goto LABEL_35;
                      *v7 = 2;
                      v38 = v7 + 1;
                      LOWORD(v281) = *((_WORD *)v52 + 1);
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, &v281, 2u);
                      v53 = v52[4];
                      v280 += 2;
                      v7[4] = v53;
                      v54 = v52[5];
                      ++v280;
                      v7[5] = v54;
                      v55 = v52[6];
                      ++v280;
                      v7[6] = v55;
                      v56 = v280 + 1;
                      goto LABEL_365;
                    case 64:
                      v70 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v70;
                      if ( !*v70 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = 8;
                      v71 = v70[1];
                      v280 += 2;
                      v7[2] = v71;
                      v72 = v70[2];
                      ++v280;
                      v7[3] = v72;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 65:
                      v104 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v104;
                      if ( !*v104 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( (unsigned int)v104[5] + 4 > v9 )
                        goto LABEL_35;
                      *v7 = 9;
                      v38 = v7 + 1;
                      v105 = v104[1];
                      v280 += 2;
                      v7[2] = v105;
                      v106 = v104[2];
                      ++v280;
                      v7[3] = v106;
                      v107 = v104[3];
                      ++v280;
                      v7[4] = v107;
                      v108 = v104[4];
                      ++v280;
                      v7[5] = v108;
                      v109 = v104[5];
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 6, v104 + 6, v109);
                      v110 = v104[5];
                      goto LABEL_363;
                    case 66:
                      packed_size_core = dot11f_pack_ie_ft_info(v279, a2 + *a7 + 220LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 67:
                      packed_size_core = dot11f_pack_ie_ht_caps(packed_size_core, a2 + *a7 + 60LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 68:
                      packed_size_core = dot11f_pack_ie_ht_info(packed_size_core, a2 + *a7 + 58LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 69:
                      v252 = (unsigned __int8 *)(a2 + *a7 + 19LL * v22);
                      v89 = *v252;
                      if ( !*v252 )
                        goto LABEL_482;
                      v89 = 268435461;
                      if ( v9 < 0x12 )
                        goto LABEL_482;
                      *v7 = 101;
                      v280 += 2;
                      qdf_mem_copy(v7 + 2, v252 + 1, 6u);
                      v280 += 6;
                      qdf_mem_copy(v7 + 8, v252 + 7, 6u);
                      v280 += 6;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 14, v252 + 13, 6u);
                      v90 = v7 + 1;
                      v91 = v280 + 6;
                      goto LABEL_480;
                    case 70:
                      packed_size_core = dot11f_pack_ie_MBO_IE(v279, a2 + *a7 + 282LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 71:
                      v27 = (unsigned __int8 *)(a2 + *a7 - v22 + ((unsigned __int64)v22 << 8));
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v93 = 88;
                      goto LABEL_356;
                    case 72:
                      packed_size_core = dot11f_pack_ie_measurement_report(v279, a2 + *a7 + 264LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 73:
                      packed_size_core = dot11f_pack_ie_measurement_request(v279, a2 + *a7 + 682LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 74:
                      v266 = (unsigned __int8 *)(a2 + *a7 + 6LL * v22);
                      v25 = *v266;
                      if ( !*v266 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < 3 )
                        goto LABEL_35;
                      *v7 = 54;
                      LOWORD(v281) = *((_WORD *)v266 + 1);
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, &v281, 2u);
                      v267 = v266[4];
                      v280 += 2;
                      v7[4] = v267;
                      goto LABEL_496;
                    case 75:
                      packed_size_core = dot11f_pack_ie_neighbor_report(v279, a2 + *a7 + 548LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 76:
                      packed_size_core = dot11f_pack_ie_obss_scan_parameters(
                                           packed_size_core,
                                           a2 + *a7 + 16LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 77:
                      v85 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v85;
                      if ( !*v85 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      *v7 = -57;
                      v86 = v85[1];
                      v280 += 2;
                      v7[2] = v86;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 78:
                      v217 = (unsigned __int8 *)(a2 + *a7 + 251LL * v22);
                      v25 = *v217;
                      if ( !*v217 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v217[1] )
                        goto LABEL_35;
                      v219 = v7 + 6;
                      *v7 = -35;
                      v220 = v217 + 2;
                      v202 = v7 + 1;
                      v280 += 2;
                      v7[2] = 80;
                      ++v280;
                      v7[3] = 111;
                      ++v280;
                      v7[4] = -102;
                      v242 = 40;
                      goto LABEL_501;
                    case 79:
                      packed_size_core = dot11f_pack_ie_p2_p_assoc_req(v279, a2 + *a7 + 62LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 80:
                      packed_size_core = dot11f_pack_ie_p2_p_assoc_res(v279, a2 + *a7 + 10LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 81:
                      packed_size_core = dot11f_pack_ie_p2_p_beacon(v279, a2 + *a7 + 51LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 82:
                      packed_size_core = dot11f_pack_ie_p2_p_beacon_probe_res(
                                           v279,
                                           a2 + *a7 + 1136LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 83:
                      packed_size_core = dot11f_pack_ie_p2_p_de_auth(v279, a2 + *a7 + 3LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 84:
                      packed_size_core = dot11f_pack_ie_p2_p_dis_assoc(v279, a2 + *a7 + 3LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 85:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 251LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v39 = v7 + 6;
                      *v7 = -35;
                      v37 = v27 + 2;
                      v38 = v7 + 1;
                      v280 += 2;
                      v7[2] = 80;
                      ++v280;
                      v7[3] = 111;
                      ++v280;
                      v7[4] = -102;
                      v92 = 9;
                      goto LABEL_360;
                    case 86:
                      packed_size_core = dot11f_pack_ie_p2_p_probe_req(v279, a2 + *a7 + 30LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 87:
                      packed_size_core = dot11f_pack_ie_p2_p_probe_res(v279, a2 + *a7 + 1128LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 88:
                      v210 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v210;
                      if ( !*v210 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 3 )
                        goto LABEL_510;
                      *v7 = 105;
                      v47 = v7 + 1;
                      v211 = v210[1];
                      v280 += 2;
                      v7[2] = v211;
                      LOWORD(v281) = *((_WORD *)v210 + 1);
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 3, &v281, 2u);
                      v41 = 0;
                      v51 = v280 + 2;
                      v280 += 2;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 89:
                      v66 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v66;
                      if ( !*v66 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      *v7 = 106;
                      v67 = v66[1];
                      v280 += 2;
                      v7[2] = v67;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 90:
                      v76 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v76;
                      if ( !*v76 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = 33;
                      v77 = v76[1];
                      v280 += 2;
                      v7[2] = v77;
                      v78 = v76[2];
                      ++v280;
                      v7[3] = v78;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 91:
                      v150 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v150;
                      if ( !*v150 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      *v7 = 32;
                      v151 = v150[1];
                      v280 += 2;
                      v7[2] = v151;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 92:
                      v154 = (unsigned __int8 *)(a2 + *a7 + 8LL * v22);
                      v25 = *v154;
                      if ( !*v154 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < 5 )
                        goto LABEL_35;
                      *v7 = 11;
                      v38 = v7 + 1;
                      LOWORD(v281) = *((_WORD *)v154 + 1);
                      v280 += 2;
                      qdf_mem_copy(v7 + 2, &v281, 2u);
                      v155 = v154[4];
                      v156 = v7 + 5;
                      v280 += 2;
                      v7[4] = v155;
                      v157 = *((_WORD *)v154 + 3);
                      v158 = v280 + 1;
                      goto LABEL_322;
                    case 93:
                      v118 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v118;
                      if ( !*v118 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = -35;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = -96;
                      ++v280;
                      v7[4] = -58;
                      v119 = v118[1];
                      ++v280;
                      v7[5] = v119;
                      v120 = v118[2];
                      ++v280;
                      v7[6] = v120;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 94:
                      v83 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v83;
                      if ( !*v83 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      *v7 = 46;
                      v84 = v83[1];
                      v280 += 2;
                      v7[2] = v84;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 95:
                      v24 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v24;
                      if ( !*v24 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      v26 = 46;
                      goto LABEL_495;
                    case 96:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 60LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v87 = 110;
                      goto LABEL_326;
                    case 97:
                      v175 = (unsigned __int8 *)(a2 + *a7 + 8LL * v22);
                      v25 = *v175;
                      if ( !*v175 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < 6 )
                        goto LABEL_35;
                      *v7 = 40;
                      v38 = v7 + 1;
                      v176 = v175[1];
                      v280 += 2;
                      v7[2] = v176;
                      v177 = v175[2];
                      ++v280;
                      v7[3] = v177;
                      LOWORD(v281) = *((_WORD *)v175 + 2);
                      ++v280;
                      qdf_mem_copy(v7 + 4, &v281, 2u);
                      v157 = *((_WORD *)v175 + 3);
                      v156 = v7 + 6;
                      v158 = v280 + 2;
LABEL_322:
                      LOWORD(v281) = v157;
                      v280 = v158;
                      packed_size_core = (__int64)qdf_mem_copy(v156, &v281, 2u);
                      v56 = v280 + 2;
                      goto LABEL_365;
                    case 98:
                      v129 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v129;
                      if ( !*v129 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      *v7 = 53;
                      v130 = v129[1];
                      v280 += 2;
                      v7[2] = v130;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 99:
                      v250 = *a7;
                      v281 = 0;
                      v251 = (_BYTE *)(a2 + v250 + 636LL * v22);
                      if ( !*v251 )
                        goto LABEL_552;
                      packed_size_core = get_packed_size_core(v279, (__int64)v251, (int *)&v281, IES_RICDataDesc);
                      if ( (_DWORD)packed_size_core )
                        goto LABEL_553;
                      if ( *v251 )
                      {
                        packed_size_core = 268435461;
                        if ( v281 <= v9 )
                          packed_size_core = pack_core(v279, v251, v7, v9, &v280, &FFS_RICDataDesc, IES_RICDataDesc);
                      }
                      else
                      {
LABEL_552:
                        packed_size_core = 0;
                      }
                      goto LABEL_553;
                    case 100:
                      packed_size_core = dot11f_pack_ie_rsn(packed_size_core, a2 + *a7 + 146LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 101:
                      v24 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v24;
                      if ( !*v24 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      v26 = 65;
                      goto LABEL_495;
                    case 102:
                      v27 = (unsigned __int8 *)(a2 + *a7 - v22 + ((unsigned __int64)v22 << 8));
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v87 = 48;
                      goto LABEL_326;
                    case 103:
                      v27 = (unsigned __int8 *)(a2 + *a7 - v22 + ((unsigned __int64)v22 << 8));
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v87 = -12;
                      goto LABEL_326;
                    case 104:
                      v138 = (unsigned __int8 *)(a2 + *a7 + 98LL * v22);
                      v25 = *v138;
                      if ( !*v138 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < 2 * (unsigned int)v138[1] )
                        goto LABEL_35;
                      *v7 = 36;
                      v38 = v7 + 1;
                      v139 = 2 * (unsigned int)v138[1];
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, v138 + 2, v139);
                      v56 = v280 + 2 * v138[1];
                      goto LABEL_365;
                    case 105:
                      v217 = (unsigned __int8 *)(a2 + *a7 + 34LL * v22);
                      v25 = *v217;
                      if ( !*v217 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v217[1] )
                        goto LABEL_35;
                      v218 = 59;
                      goto LABEL_536;
                    case 106:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 14LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
LABEL_230:
                      v87 = 1;
                      goto LABEL_326;
                    case 107:
                      v113 = (unsigned __int8 *)(a2 + *a7 + ((unsigned __int64)v22 << 8));
                      v25 = *v113;
                      if ( !*v113 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( (unsigned int)v113[4] + 3 > v9 )
                        goto LABEL_35;
                      *v7 = 5;
                      v38 = v7 + 1;
                      v114 = v113[1];
                      v280 += 2;
                      v7[2] = v114;
                      v115 = v113[2];
                      ++v280;
                      v7[3] = v115;
                      v116 = v113[3];
                      ++v280;
                      v7[4] = v116;
                      v117 = v113[4];
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 5, v113 + 5, v117);
                      v110 = v113[4];
                      goto LABEL_363;
                    case 108:
                      v188 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v188;
                      if ( !*v188 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = 35;
                      v189 = v188[1];
                      v280 += 2;
                      v7[2] = v189;
                      v190 = v188[2];
                      ++v280;
                      v7[3] = v190;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 109:
                      if ( !*(_BYTE *)(a2 + *a7 + v22) )
                        goto LABEL_36;
                      *v7 = 34;
                      v161 = v7 + 1;
                      v162 = v280 + 2;
                      v280 += 2;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_36;
                      goto LABEL_419;
                    case 110:
                      v171 = (unsigned __int8 *)(a2 + *a7 + 17LL * v22);
                      v25 = *v171;
                      if ( !*v171 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < 0x10 )
                        goto LABEL_35;
                      *v7 = 69;
                      v38 = v7 + 1;
                      v172 = v171[1];
                      v280 += 2;
                      v7[2] = v172;
                      ++v280;
                      qdf_mem_copy(v7 + 3, v171 + 2, 0xAu);
                      v280 += 10;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 13, v171 + 12, 5u);
                      v56 = v280 + 5;
                      goto LABEL_365;
                    case 111:
                      v191 = (unsigned __int8 *)(a2 + *a7 + 8LL * v22);
                      v41 = *v191;
                      if ( !*v191 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 5 )
                        goto LABEL_510;
                      *v7 = 56;
                      v47 = v7 + 1;
                      v192 = v191[1];
                      v280 += 2;
                      v7[2] = v192;
                      v281 = *((_DWORD *)v191 + 1);
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 3, &v281, 4u);
                      v41 = 0;
                      v51 = v280 + 4;
                      v280 += 4;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 112:
                      v180 = (unsigned __int8 *)(a2 + *a7 + 6LL * v22);
                      v41 = *v180;
                      if ( !*v180 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 5 )
                        goto LABEL_510;
                      *v7 = -63;
                      v181 = v180[1];
                      v280 += 2;
                      v7[2] = v181;
                      v182 = v180[2];
                      ++v280;
                      v7[3] = v182;
                      v183 = v180[3];
                      ++v280;
                      v7[4] = v183;
                      v184 = v180[4];
                      ++v280;
                      v7[5] = v184;
                      v185 = v180[5];
                      ++v280;
                      v7[6] = v185;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 113:
                      if ( !*(_BYTE *)(a2 + *a7 + v22) )
                        goto LABEL_36;
                      *v7 = -35;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 16;
                      v160 = 24;
                      goto LABEL_418;
                    case 114:
                      if ( !*(_BYTE *)(a2 + *a7 + v22) )
                        goto LABEL_36;
                      *v7 = -35;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 22;
                      v160 = 50;
LABEL_418:
                      ++v280;
                      v161 = v7 + 1;
                      v7[4] = v160;
                      v162 = ++v280;
                      if ( v7 != (char *)-1LL )
LABEL_419:
                        *v161 = v162 - 2;
                      goto LABEL_36;
                    case 115:
                      packed_size_core = dot11f_pack_ie_wapi(packed_size_core, a2 + *a7 + 112LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 116:
                      v217 = (unsigned __int8 *)(a2 + *a7 - v22 + ((unsigned __int64)v22 << 8));
                      v25 = *v217;
                      if ( !*v217 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v217[1] )
                        goto LABEL_35;
                      v218 = 68;
LABEL_536:
                      v220 = v217 + 2;
                      *v7 = v218;
                      v219 = v7 + 2;
                      v202 = v7 + 1;
                      v255 = v217[1];
                      v256 = v280 + 2;
                      goto LABEL_537;
                    case 117:
                      v126 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v126;
                      if ( !*v126 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = -35;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 80;
                      ++v280;
                      v7[4] = -14;
                      ++v280;
                      v7[5] = 8;
                      ++v280;
                      v7[6] = 0;
                      v127 = v126[1];
                      ++v280;
                      v7[7] = v127;
                      v128 = v126[2];
                      ++v280;
                      v7[8] = v128;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 118:
                      v217 = (unsigned __int8 *)(a2 + *a7 + 251LL * v22);
                      v25 = *v217;
                      if ( !*v217 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v217[1] )
                        goto LABEL_35;
                      v219 = v7 + 6;
                      *v7 = -35;
                      v220 = v217 + 2;
                      v202 = v7 + 1;
                      v280 += 2;
                      v7[2] = 80;
                      ++v280;
                      v7[3] = 111;
                      ++v280;
                      v7[4] = -102;
                      v242 = 10;
LABEL_501:
                      ++v280;
                      v7[5] = v242;
LABEL_502:
                      v255 = v217[1];
                      v256 = v280 + 1;
LABEL_537:
                      v280 = v256;
                      packed_size_core = (__int64)qdf_mem_copy(v219, v220, v255);
                      v226 = v217[1];
                      goto LABEL_543;
                    case 119:
                      v237 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v237;
                      if ( !*v237 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = -35;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 80;
                      ++v280;
                      v7[4] = -14;
                      ++v280;
                      v7[5] = 2;
                      ++v280;
                      v7[6] = 5;
                      v238 = v237[1];
                      ++v280;
                      v7[7] = v238;
                      v239 = v237[2];
                      ++v280;
                      v7[8] = v239;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 120:
                      v123 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v123;
                      if ( !*v123 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = -35;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 80;
                      ++v280;
                      v7[4] = -14;
                      ++v280;
                      v7[5] = 2;
                      ++v280;
                      v7[6] = 0;
                      v124 = v123[1];
                      ++v280;
                      v7[7] = v124;
                      v125 = v123[2];
                      ++v280;
                      v7[8] = v125;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 121:
                      v247 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v247;
                      if ( *v247 )
                      {
                        v41 = 268435461;
                        if ( v9 >= 2 )
                        {
                          *v7 = -35;
                          v280 += 2;
                          v7[2] = 0;
                          ++v280;
                          v7[3] = 80;
                          ++v280;
                          v7[4] = -14;
                          ++v280;
                          v7[5] = 2;
                          ++v280;
                          v7[6] = 0;
                          v248 = v247[1];
                          ++v280;
                          v7[7] = v248;
                          v249 = v247[2];
                          ++v280;
                          v7[8] = v249;
                          v44 = v7 + 1;
                          v45 = v280 + 1;
                          v41 = 0;
                          ++v280;
                          if ( v7 != (char *)-1LL )
                            goto LABEL_468;
                        }
                      }
                      goto LABEL_510;
                    case 122:
                      packed_size_core = dot11f_pack_ie_wmm_params(
                                           packed_size_core,
                                           a2 + *a7 + 20LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 123:
                      packed_size_core = dot11f_pack_ie_wpa(packed_size_core, a2 + *a7 + 48LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 124:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 251LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v39 = v7 + 6;
                      *v7 = -35;
                      v37 = v27 + 2;
                      v38 = v7 + 1;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 80;
                      ++v280;
                      v7[4] = -14;
                      v92 = 1;
                      goto LABEL_360;
                    case 125:
                      packed_size_core = dot11f_pack_ie_wsc(v279, a2 + *a7 + 308LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 126:
                      packed_size_core = dot11f_pack_ie_wsc_assoc_req(v279, a2 + *a7 + 20LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 127:
                      packed_size_core = dot11f_pack_ie_wsc_assoc_res(v279, a2 + *a7 + 20LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 128:
                      packed_size_core = dot11f_pack_ie_wsc_beacon(v279, a2 + *a7 + 52LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 129:
                      packed_size_core = dot11f_pack_ie_wsc_beacon_probe_res(
                                           v279,
                                           a2 + *a7 + 272LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 130:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 251LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v39 = v7 + 6;
                      *v7 = -35;
                      v37 = v27 + 2;
                      v38 = v7 + 1;
                      v280 += 2;
                      v7[2] = 0;
                      ++v280;
                      v7[3] = 80;
                      ++v280;
                      v7[4] = -14;
                      v92 = 4;
                      goto LABEL_360;
                    case 131:
                      packed_size_core = dot11f_pack_ie_wsc_probe_req(v279, a2 + *a7 + 246LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 132:
                      packed_size_core = dot11f_pack_ie_wsc_probe_res(v279, a2 + *a7 + 272LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 133:
                      packed_size_core = dot11f_pack_ie_wsc_reassoc_res(v279, a2 + *a7 + 20LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 134:
                      v24 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v24;
                      if ( !*v24 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      v26 = -97;
LABEL_495:
                      *v7 = v26;
                      v253 = v24[1];
                      v280 += 2;
                      v7[2] = v253;
LABEL_496:
                      v254 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 != (char *)-1LL )
                        v7[1] = v254 - 2;
                      goto LABEL_35;
                    case 135:
                      v232 = (unsigned __int8 *)(a2 + *a7 + 3LL * v22);
                      v41 = *v232;
                      if ( !*v232 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = -1;
                      v280 += 2;
                      v7[2] = 42;
                      v233 = v232[1];
                      ++v280;
                      v7[3] = v233;
                      v234 = v232[2];
                      ++v280;
                      v7[4] = v234;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 136:
                      v121 = (unsigned __int8 *)(a2 + *a7 + 6LL * v22);
                      v25 = *v121;
                      if ( !*v121 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < 3 )
                        goto LABEL_35;
                      *v7 = 90;
                      LOWORD(v281) = *((_WORD *)v121 + 1);
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 2, &v281, 2u);
                      v122 = v121[4];
                      v280 += 2;
                      v7[4] = v122;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 137:
                      v68 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v68;
                      if ( !*v68 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 <= v68[2] )
                        goto LABEL_35;
                      v69 = 97;
                      goto LABEL_235;
                    case 138:
                      packed_size_core = dot11f_pack_ie_descriptor_element(v279, a2 + *a7 + 32LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 139:
                      v142 = (unsigned __int8 *)(a2 + *a7 + 259LL * v22);
                      v25 = *v142;
                      if ( !*v142 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( (unsigned int)v142[3] + 2 > v9 )
                        goto LABEL_35;
                      *v7 = -1;
                      v38 = v7 + 1;
                      v280 += 2;
                      v7[2] = 32;
                      ++v280;
                      qdf_mem_copy(v7 + 3, v142 + 1, 2u);
                      v143 = v142[3];
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 5, v142 + 4, v143);
                      v110 = v142[3];
                      goto LABEL_363;
                    case 140:
                      packed_size_core = dot11f_pack_ie_eht_cap(packed_size_core, a2 + *a7 + 92LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 141:
                      packed_size_core = dot11f_pack_ie_eht_op(packed_size_core, a2 + *a7 + 12LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 142:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 98LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v93 = 11;
                      goto LABEL_356;
                    case 143:
                      v194 = (unsigned __int8 *)(a2 + *a7 + 5LL * v22);
                      v41 = *v194;
                      if ( !*v194 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 4 )
                        goto LABEL_510;
                      *v7 = 60;
                      v195 = v194[1];
                      v280 += 2;
                      v7[2] = v195;
                      v196 = v194[2];
                      ++v280;
                      v7[3] = v196;
                      v197 = v194[3];
                      ++v280;
                      v7[4] = v197;
                      v198 = v194[4];
                      ++v280;
                      v7[5] = v198;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 144:
                      v227 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v41 = *v227;
                      if ( !*v227 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( !v9 )
                        goto LABEL_510;
                      *v7 = -1;
                      v280 += 2;
                      v7[2] = 1;
                      v228 = v227[1];
                      ++v280;
                      v7[3] = v228;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 145:
                      v224 = (unsigned __int8 *)(a2 + *a7 + 269LL * v22);
                      v25 = *v224;
                      if ( !*v224 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( (unsigned int)v224[13] + 12 > v9 )
                        goto LABEL_35;
                      *v7 = -1;
                      v202 = v7 + 1;
                      v280 += 2;
                      v7[2] = 5;
                      ++v280;
                      qdf_mem_copy(v7 + 3, v224 + 1, 6u);
                      v280 += 6;
                      qdf_mem_copy(v7 + 9, v224 + 7, 6u);
                      v225 = v224[13];
                      v280 += 6;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 15, v224 + 14, v225);
                      v226 = v224[13];
                      goto LABEL_543;
                    case 146:
                      v140 = (unsigned __int8 *)(a2 + *a7 + 260LL * v22);
                      v89 = *v140;
                      if ( !*v140 )
                        goto LABEL_482;
                      v89 = 268435461;
                      if ( (unsigned int)v140[3] + 2 > v9 )
                        goto LABEL_482;
                      *v7 = -16;
                      LOWORD(v281) = *(_WORD *)(v140 + 1);
                      v280 += 2;
                      qdf_mem_copy(v7 + 2, &v281, 2u);
                      v141 = v140[3];
                      v280 += 2;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 4, v140 + 4, v141);
                      v90 = v7 + 1;
                      v91 = v280 + v140[3];
LABEL_480:
                      v89 = 0;
                      v280 = v91;
                      if ( v90 )
                        *v90 = v91 - 2;
LABEL_482:
                      v8 |= v89;
                      goto LABEL_36;
                    case 147:
                      v235 = (unsigned __int8 *)(a2 + *a7 + 265LL * v22);
                      v25 = *v235;
                      if ( !*v235 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( (unsigned int)v235[9] + 8 > v9 )
                        goto LABEL_35;
                      *v7 = -1;
                      v202 = v7 + 1;
                      v280 += 2;
                      v7[2] = 7;
                      ++v280;
                      qdf_mem_copy(v7 + 3, v235 + 1, 8u);
                      v236 = v235[9];
                      v280 += 8;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 11, v235 + 10, v236);
                      v226 = v235[9];
                      goto LABEL_543;
                    case 148:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v93 = 3;
                      goto LABEL_356;
                    case 149:
                      v167 = (unsigned __int8 *)(a2 + *a7 + 17LL * v22);
                      v41 = *v167;
                      if ( !*v167 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 0x10 )
                        goto LABEL_510;
                      *v7 = -1;
                      v47 = v7 + 1;
                      v280 += 2;
                      v7[2] = 13;
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 3, v167 + 1, 0x10u);
                      v41 = 0;
                      v51 = v280 + 16;
                      v280 += 16;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 150:
                      v213 = (unsigned __int8 *)(a2 + *a7 + 258LL * v22);
                      v25 = *v213;
                      if ( !*v213 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 <= v213[2] )
                        goto LABEL_35;
                      v214 = v7 + 4;
                      *v7 = -1;
                      v215 = v213 + 3;
                      v202 = v7 + 1;
                      v280 += 2;
                      v7[2] = 12;
                      v223 = v213[1];
                      ++v280;
                      v7[3] = v223;
LABEL_542:
                      v276 = v213[2];
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v214, v215, v276);
                      v226 = v213[2];
LABEL_543:
                      v274 = v280;
LABEL_544:
                      v205 = v274 + v226;
LABEL_545:
                      v25 = 0;
                      v280 = v205;
                      if ( v202 )
                        *v202 = v205 - 2;
                      goto LABEL_35;
                    case 151:
                      v212 = (unsigned __int8 *)(a2 + *a7 + 9LL * v22);
                      v41 = *v212;
                      if ( !*v212 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 8 )
                        goto LABEL_510;
                      *v7 = -1;
                      v47 = v7 + 1;
                      v280 += 2;
                      v7[2] = 4;
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 3, v212 + 1, 8u);
                      v41 = 0;
                      v51 = v280 + 8;
                      v280 += 8;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 152:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v93 = 8;
                      goto LABEL_356;
                    case 153:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v87 = -14;
LABEL_326:
                      v37 = v27 + 2;
                      *v7 = v87;
                      v39 = v7 + 2;
                      v38 = v7 + 1;
LABEL_327:
                      v178 = v27[1];
                      v179 = v280 + 2;
                      goto LABEL_362;
                    case 154:
                      v221 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v221;
                      if ( !*v221 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 2 )
                        goto LABEL_510;
                      *v7 = -1;
                      v47 = v7 + 1;
                      v280 += 2;
                      v7[2] = 59;
                      v222 = *(_WORD *)(v221 + 1) & 0x3F
                           | ((unsigned __int8)HIBYTE(*(_WORD *)(v221 + 1)) << 6)
                           | (v221[3] << 14);
                      ++v280;
                      LOWORD(v281) = v222;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 3, &v281, 2u);
                      v41 = 0;
                      v51 = v280 + 2;
                      v280 += 2;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_509;
                    case 155:
                      packed_size_core = dot11f_pack_ie_he_cap(packed_size_core, a2 + *a7 + 60LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 156:
                      packed_size_core = dot11f_pack_ie_he_op(packed_size_core, a2 + *a7 + 18LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 157:
                      packed_size_core = dot11f_pack_ie_hs20vendor_ie(
                                           packed_size_core,
                                           a2 + *a7 + 4LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 158:
                      v169 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v169;
                      if ( !*v169 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( !v9 )
                        goto LABEL_35;
                      *v7 = 72;
                      v170 = v169[1];
                      v280 += 2;
                      v7[2] = v170;
                      v59 = v7 + 1;
                      v60 = v280 + 1;
                      v25 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_35;
                      goto LABEL_305;
                    case 159:
                      v68 = (unsigned __int8 *)(a2 + *a7 + 53LL * v22);
                      v25 = *v68;
                      if ( !*v68 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 <= v68[2] )
                        goto LABEL_35;
                      v69 = 73;
LABEL_235:
                      *v7 = v69;
                      v38 = v7 + 1;
                      v145 = v68[1];
                      v280 += 2;
                      v7[2] = v145;
                      v146 = v68[2];
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 3, v68 + 3, v146);
                      v110 = v68[2];
                      goto LABEL_363;
                    case 160:
                      v193 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v193;
                      if ( !*v193 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 3 )
                        goto LABEL_510;
                      *v7 = -1;
                      v47 = v7 + 1;
                      v280 += 2;
                      v7[2] = 52;
                      ++v280;
                      packed_size_core = (__int64)qdf_mem_copy(v7 + 3, v193 + 1, 3u);
                      v41 = 0;
                      v51 = v280 + 3;
                      v280 += 3;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
LABEL_509:
                      *v47 = v51 - 2;
                      goto LABEL_510;
                    case 161:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v93 = 107;
                      goto LABEL_356;
                    case 162:
                      packed_size_core = dot11f_pack_ie_mu_edca_param_set(
                                           packed_size_core,
                                           a2 + *a7 + 14LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 163:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v93 = 56;
                      goto LABEL_356;
                    case 164:
                      v163 = (unsigned __int8 *)(a2 + *a7 + 4LL * v22);
                      v41 = *v163;
                      if ( !*v163 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( v9 < 3 )
                        goto LABEL_510;
                      *v7 = -1;
                      v280 += 2;
                      v7[2] = 54;
                      v164 = v163[1];
                      ++v280;
                      v7[3] = v164;
                      v165 = v163[2];
                      ++v280;
                      v7[4] = v165;
                      v166 = v163[3];
                      ++v280;
                      v7[5] = v166;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
                      goto LABEL_468;
                    case 165:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v39 = v7 + 6;
                      *v7 = -35;
                      v37 = v27 + 2;
                      v38 = v7 + 1;
                      v280 += 2;
                      v7[2] = 80;
                      ++v280;
                      v7[3] = 111;
                      ++v280;
                      v7[4] = -102;
                      v92 = 18;
                      goto LABEL_360;
                    case 166:
                      packed_size_core = dot11f_pack_ie_qcn_ie(v279, a2 + *a7 + 44LL * v22, v7, v9, &v280);
                      goto LABEL_553;
                    case 167:
                      packed_size_core = dot11f_pack_ie_reduced_neighbor_report(
                                           packed_size_core,
                                           a2 + *a7 + 28LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 168:
                      v186 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v41 = *v186;
                      if ( !*v186 )
                        goto LABEL_510;
                      v41 = 268435461;
                      if ( !v9 )
                        goto LABEL_510;
                      *v7 = -1;
                      v280 += 2;
                      v7[2] = -119;
                      v187 = v186[1];
                      ++v280;
                      v7[3] = v187;
                      v44 = v7 + 1;
                      v45 = v280 + 1;
                      v41 = 0;
                      ++v280;
                      if ( v7 == (char *)-1LL )
                        goto LABEL_510;
LABEL_468:
                      *v44 = v45 - 2;
LABEL_510:
                      v8 |= v41;
                      goto LABEL_36;
                    case 169:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v39 = v7 + 6;
                      *v7 = -35;
                      v37 = v27 + 2;
                      v38 = v7 + 1;
                      v280 += 2;
                      v7[2] = 80;
                      ++v280;
                      v7[3] = 111;
                      ++v280;
                      v7[4] = -102;
                      v92 = 29;
LABEL_360:
                      ++v280;
                      v7[5] = v92;
                      goto LABEL_361;
                    case 170:
                      v173 = (unsigned __int8 *)(a2 + *a7 + 2LL * v22);
                      v25 = *v173;
                      if ( *v173 )
                      {
                        v25 = 268435461;
                        if ( v9 )
                        {
                          *v7 = 62;
                          v174 = v173[1];
                          v280 += 2;
                          v7[2] = v174;
                          v59 = v7 + 1;
                          v60 = v280 + 1;
                          v25 = 0;
                          ++v280;
                          if ( v7 != (char *)-1LL )
LABEL_305:
                            *v59 = v60 - 2;
                        }
                      }
                      goto LABEL_35;
                    case 171:
                      packed_size_core = dot11f_pack_ie_spatial_reuse(
                                           packed_size_core,
                                           a2 + *a7 + 21LL * v22,
                                           v7,
                                           v9,
                                           &v280);
                      goto LABEL_553;
                    case 172:
                      v27 = (unsigned __int8 *)(a2 + *a7 + 257LL * v22);
                      v25 = *v27;
                      if ( !*v27 )
                        goto LABEL_35;
                      v25 = 268435461;
                      if ( v9 < v27[1] )
                        goto LABEL_35;
                      v93 = 109;
LABEL_356:
                      v39 = v7 + 3;
                      *v7 = -1;
                      v37 = v27 + 2;
                      v38 = v7 + 1;
                      v280 += 2;
                      v7[2] = v93;
LABEL_361:
                      v178 = v27[1];
                      v179 = v280 + 1;
LABEL_362:
                      v280 = v179;
                      packed_size_core = (__int64)qdf_mem_copy(v39, v37, v178);
                      v110 = v27[1];
LABEL_363:
                      v137 = v280;
LABEL_364:
                      v56 = v137 + v110;
LABEL_365:
                      v25 = 0;
                      v280 = v56;
                      if ( v38 )
                        *v38 = v56 - 2;
LABEL_35:
                      v8 |= v25;
                      goto LABEL_36;
                    case 173:
                      packed_size_core = dot11f_pack_ie_vendor_vht_ie(v279, a2 + *a7 + 28LL * v22, v7, v9, &v280);
LABEL_553:
                      v8 |= packed_size_core;
LABEL_36:
                      ++v22;
                      v7 += v280;
                      v9 -= v280;
                      *a5 += v280;
                      if ( v22 < v21 )
                        continue;
                      goto LABEL_25;
                    default:
                      v8 = 268435457;
                      goto LABEL_558;
                  }
                }
              }
              v20 = a7[2];
              v21 = *(unsigned __int16 *)(a2 + v20);
              if ( *(_WORD *)(a2 + v20) )
                goto LABEL_34;
LABEL_25:
              a7 += 12;
            }
          }
        }
      }
    }
  }
  else
  {
    v8 = 268435459;
  }
LABEL_558:
  _ReadStatusReg(SP_EL0);
  return v8;
}
