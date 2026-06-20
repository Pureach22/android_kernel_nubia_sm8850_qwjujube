__int64 __fastcall hal_rx_status_get_tlv_info_wrapper_be(
        unsigned int *a1,
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
  __int64 v11; // x21
  __int64 v13; // x22
  int v14; // w23
  int v15; // w8
  __int64 v16; // x8
  unsigned int v17; // w20
  void *v18; // x0
  __int64 v19; // x20
  __int64 v20; // x1
  void (__fastcall *v21)(__int64, __int64, __int64); // x8
  unsigned __int64 v22; // x10
  unsigned int v23; // w4
  unsigned int v24; // w8
  unsigned __int64 v25; // x9
  unsigned int *v26; // x0
  const char *v28; // x2
  unsigned int v29; // w1
  int v30; // w8
  unsigned int v31; // w0
  unsigned int v32; // w9
  unsigned int v33; // w8
  __int64 v34; // x20
  unsigned __int16 v35; // w0
  __int64 v36; // x8
  __int64 v37; // x8
  unsigned int v38; // w9
  __int16 v39; // w9
  unsigned int v40; // w9
  int v41; // w11
  unsigned int v42; // w9
  unsigned int v43; // w11
  unsigned __int64 v44; // x9
  unsigned __int64 v45; // x10
  unsigned int v46; // w11
  unsigned int v47; // w8
  unsigned int v48; // w11
  unsigned int v49; // w11
  unsigned __int64 v50; // x12
  unsigned int v51; // w10
  unsigned __int64 v52; // x13
  unsigned __int64 v53; // x11
  unsigned int v54; // w12
  int v55; // w10
  unsigned __int64 v56; // x8
  int v57; // w11
  unsigned __int64 v58; // x9
  unsigned int v59; // w8
  unsigned __int64 v60; // x9
  unsigned __int64 v61; // x9
  unsigned __int64 v62; // x8
  unsigned __int64 v63; // x8
  unsigned __int64 v64; // x9
  unsigned __int64 v65; // x9
  unsigned __int64 v66; // x8
  unsigned int v67; // w11
  __int64 v68; // x21
  __int64 (__fastcall *v69)(_QWORD); // x8
  __int64 (__fastcall *v70)(_QWORD); // x8
  unsigned __int64 v71; // x9
  int v72; // w10
  __int16 v73; // w11
  unsigned int v74; // w9
  int v75; // w8
  __int64 v76; // x8
  unsigned __int64 v77; // x8
  __int16 v78; // w9
  unsigned __int64 v79; // x8
  unsigned __int64 v80; // x9
  int v81; // w10
  unsigned __int64 v82; // x8
  int v83; // w9
  unsigned int v84; // w9
  int v85; // w8
  __int64 v86; // x8
  unsigned __int64 v87; // x8
  __int64 v88; // x8
  int v89; // w9
  unsigned int v90; // w9
  unsigned int v91; // w9
  unsigned __int64 v92; // x9
  unsigned __int64 v93; // x8
  unsigned __int64 v94; // x10
  unsigned __int64 v95; // x8
  int v96; // w9
  int v97; // w10
  __int16 v98; // w8
  unsigned __int64 v99; // x9
  int v100; // w8
  unsigned __int64 v101; // x9
  unsigned __int64 v102; // x9
  unsigned int v103; // w10
  int v104; // w10
  unsigned __int64 v105; // x9
  unsigned __int64 v106; // x9
  int v107; // w11
  bool v108; // zf
  __int16 v109; // w10
  char v110; // w10
  unsigned __int64 v111; // x9
  int v112; // w15
  __int64 v113; // x14
  __int64 v114; // x13
  unsigned __int64 v115; // x8
  int v116; // w12
  __int16 v117; // w11
  unsigned __int64 v118; // x10
  unsigned __int64 v119; // x10
  unsigned __int64 v120; // x15
  unsigned __int64 v121; // x15
  __int64 v122; // x17
  unsigned __int64 *v123; // x22
  unsigned __int64 v124; // x8
  unsigned __int64 v125; // x9
  unsigned __int64 v126; // x8
  int v127; // w9
  char v128; // w14
  __int64 v129; // x8
  unsigned __int64 v130; // x10
  unsigned __int64 v131; // x10
  unsigned __int64 v132; // x10
  unsigned __int64 v133; // x10
  unsigned __int64 v134; // x10
  unsigned int v135; // w11
  int v136; // w8
  unsigned int v137; // w12
  unsigned int v138; // w8
  int v139; // w8
  __int64 v140; // x8
  int v141; // w12
  unsigned int v142; // w10
  unsigned int v143; // w11
  int v144; // w12
  int v145; // w12
  unsigned __int64 v146; // x12
  int v147; // w11
  int v148; // w10
  __int64 v149; // x8
  unsigned __int64 v150; // x8
  __int16 v151; // w9
  unsigned __int64 v152; // x8
  char v153; // w9
  __int16 v154; // w10
  unsigned __int64 v155; // x9
  unsigned int v156; // w8
  __int64 v157; // x9
  unsigned int v158; // w10
  __int64 v159; // x8
  void (__fastcall *v160)(_QWORD); // x8
  __int64 v161; // x9
  int v162; // w8
  int v163; // w8
  int v164; // w8
  int v165; // w8
  int v166; // w8
  int v167; // w8
  unsigned int v168; // w8
  int v169; // w9
  int v170; // w11
  int v171; // w9
  int v172; // w9
  int v173; // w9
  int v174; // w9
  __int16 v175; // w8
  unsigned __int64 v176; // x8
  __int64 v177; // x8
  __int64 v178; // x8
  unsigned int v179; // w9
  __int64 v180; // x10
  __int64 v181; // x11
  int v182; // w10
  int v183; // w9
  int v184; // w9
  int v185; // w9
  int v186; // w9
  int v187; // w9
  unsigned int v188; // w8
  unsigned int v189; // w8
  __int64 v190; // x8
  int v191; // w12
  unsigned int v192; // w10
  __int64 v193; // x8
  int v194; // w12
  unsigned __int64 v195; // x8
  __int64 v196; // x8
  __int64 v197; // x8
  char v198; // w9
  __int64 v199; // x17
  char v200; // w2
  __int16 v201; // w3
  int v202; // w14
  char v203; // w15
  __int16 v204; // w9
  const void *v205; // x20
  unsigned __int64 v206; // x16
  __int64 v207; // x17
  unsigned __int64 v208; // x0
  char v209; // w2
  unsigned __int64 v210; // x3
  unsigned __int64 v211; // x16
  __int64 v212; // x0
  unsigned __int64 v213; // x13
  unsigned __int64 v214; // x12
  char v215; // w11
  unsigned __int64 v216; // x10
  __int64 v217; // x21
  __int64 v218; // x23
  __int16 v219; // w11
  unsigned __int64 v220; // x11
  int v221; // w9
  int v222; // w9
  unsigned int v223; // w9
  unsigned int v224; // w9
  int v225; // w9
  char v226; // w10
  unsigned __int64 v227; // x8
  int v228; // w9
  __int64 v229; // x8
  __int64 v230; // x8
  __int64 v231; // x8
  __int64 v232; // x8
  __int64 v233; // x8
  __int64 v234; // x8
  __int64 v235; // x8
  __int64 v236; // x8
  __int64 v237; // x12
  unsigned __int64 v238; // x13
  unsigned __int64 v239; // x14
  unsigned __int64 v240; // x11
  unsigned __int64 v241; // x11
  __int64 v242; // x9
  __int64 v243; // x20
  unsigned __int64 v244; // x10
  unsigned __int64 v245; // x11
  __int64 v246; // x19
  __int64 v247; // x9
  unsigned int v248; // w10
  __int64 v249; // x8
  __int64 v250; // x12
  __int64 v251; // x12
  __int64 v252; // x12
  __int64 v253; // x8
  __int64 v254; // x8
  unsigned int *v255; // x21
  __int64 v256; // x22
  char v257; // w10
  int v258; // w9
  __int64 v259; // x11
  int v260; // w11
  int v261; // w11
  __int64 v262; // x10
  unsigned __int64 v263; // x10
  __int16 v264; // w13
  int v265; // w14
  __int64 v266; // x12
  __int16 v267; // w11
  unsigned int v268; // w13
  unsigned __int64 v269; // x11
  __int16 v270; // w12
  __int16 v271; // w16
  __int64 v272; // x13
  __int64 v273; // x14
  __int64 v274; // x15
  int v275; // w17
  __int16 v276; // w12
  __int16 v277; // w10
  __int16 v278; // w12
  bool v279; // zf
  unsigned __int64 v280; // x8
  __int64 v281; // x9
  __int64 v282; // x9
  __int64 v283; // x22
  __int64 v284; // x20

  v11 = a2 + 12288;
  v13 = a3 + 73728;
  v14 = (*a1 >> 1) & 0x1FF;
  if ( !*(_BYTE *)(a2 + 14260) )
    goto LABEL_11;
  v15 = *(_DWORD *)(a2 + 14264);
  if ( v15 != v14 )
  {
    if ( v15 == 471 )
    {
      v19 = a2;
      v20 = a2 + 14268;
      v21 = *(void (__fastcall **)(__int64, __int64, __int64))(*(_QWORD *)(a3 + 74392) + 1904LL);
      if ( *((_DWORD *)v21 - 1) != -2021587881 )
        __break(0x8228u);
      v21(a3, v20, v19);
      a2 = v19;
    }
    *(_BYTE *)(v11 + 1972) = 0;
    *(_WORD *)(v11 + 1974) = 0;
LABEL_11:
    v22 = *a1;
    v23 = ((unsigned int)v22 >> 1) & 0x1FF;
    if ( v14 == 471 )
    {
      *(_DWORD *)(a2 + 14264) = v23;
      *(_DWORD *)(v11 + 1972) = 1;
      v17 = (*a1 >> 10) & 0xFFF;
      if ( v17 <= 0xC0 )
      {
        v18 = (void *)(a2 + 14268);
        goto LABEL_18;
      }
      goto LABEL_13;
    }
    v25 = v22 >> 26;
    v26 = a1 + 1;
    *(_BYTE *)(v11 + 1065) = v22 >> 26;
    if ( (((unsigned int)v22 >> 1) & 0x1FF) <= 0x1AA )
    {
      v24 = 1;
      switch ( v23 )
      {
        case 0x64u:
          v68 = a2;
          v69 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v13 + 664) + 304LL);
          if ( *((_DWORD *)v69 - 1) != 513397718 )
            __break(0x8228u);
          *(_BYTE *)(a2 + 144) = v69(v26);
          v70 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v13 + 664) + 296LL);
          if ( *((_DWORD *)v70 - 1) != -2091637267 )
            __break(0x8228u);
          v71 = *(_QWORD *)(v68 + 92) & 0xFFFFFFFFFF70FFFFLL | ((v70(a1 + 1) & 0xF) << 16);
          *(_QWORD *)(v68 + 92) = v71;
          v72 = a1[1] & 0xF;
          if ( v72 == 1 )
          {
            v73 = 2;
          }
          else
          {
            if ( v72 )
              goto LABEL_151;
            v71 |= 0x10000000000uLL;
            v73 = 3;
          }
          *(_WORD *)(v68 + 180) = v73;
LABEL_151:
          *(_QWORD *)(v68 + 92) = v71 & 0xC3FFFFFFFFFFFFFFLL | ((unsigned __int64)(v72 & 0xF) << 58);
          *(_WORD *)(v68 + 206) = a1[25];
          *(_BYTE *)(v68 + 208) = BYTE2(a1[25]);
          *(_BYTE *)(v68 + 209) = HIBYTE(a1[25]);
          *(_WORD *)(v68 + 214) = a1[29];
          *(_BYTE *)(v68 + 216) = BYTE2(a1[29]);
          *(_BYTE *)(v68 + 217) = HIBYTE(a1[29]);
          *(_WORD *)(v68 + 222) = a1[33];
          *(_BYTE *)(v68 + 224) = BYTE2(a1[33]);
          *(_BYTE *)(v68 + 225) = HIBYTE(a1[33]);
          *(_WORD *)(v68 + 230) = a1[37];
          *(_BYTE *)(v68 + 232) = BYTE2(a1[37]);
          *(_BYTE *)(v68 + 233) = HIBYTE(a1[37]);
          *(_BYTE *)(v68 + 145) = a1[25];
          *(_BYTE *)(v68 + 146) = a1[29];
          *(_BYTE *)(v68 + 147) = a1[33];
          *(_BYTE *)(v68 + 148) = a1[37];
          return 0;
        case 0x65u:
        case 0x66u:
        case 0x68u:
        case 0x69u:
        case 0x6Au:
        case 0x6Fu:
        case 0x70u:
        case 0x71u:
        case 0x72u:
        case 0x73u:
        case 0x74u:
        case 0x75u:
        case 0x76u:
        case 0x80u:
        case 0x82u:
        case 0x83u:
        case 0x84u:
        case 0x85u:
        case 0x86u:
        case 0x87u:
        case 0x88u:
        case 0x89u:
        case 0x8Au:
        case 0x8Bu:
        case 0x8Cu:
        case 0x8Du:
        case 0x8Eu:
        case 0x8Fu:
        case 0x90u:
        case 0x91u:
        case 0x92u:
        case 0x93u:
        case 0x94u:
        case 0x95u:
        case 0x96u:
        case 0x97u:
        case 0x98u:
        case 0x99u:
        case 0x9Au:
        case 0x9Bu:
        case 0x9Cu:
        case 0x9Du:
        case 0x9Eu:
        case 0x9Fu:
        case 0xA0u:
        case 0xA1u:
        case 0xA2u:
        case 0xA3u:
        case 0xA4u:
        case 0xA5u:
        case 0xA6u:
        case 0xA7u:
        case 0xA8u:
        case 0xA9u:
        case 0xAAu:
        case 0xABu:
        case 0xACu:
        case 0xADu:
        case 0xAEu:
        case 0xAFu:
        case 0xB0u:
        case 0xB1u:
        case 0xB2u:
        case 0xB3u:
        case 0xB4u:
        case 0xB5u:
        case 0xB6u:
        case 0xB7u:
        case 0xB8u:
        case 0xB9u:
        case 0xBAu:
        case 0xBBu:
        case 0xBCu:
        case 0xBDu:
        case 0xBEu:
        case 0xBFu:
        case 0xC4u:
        case 0xC6u:
        case 0xC7u:
        case 0xC8u:
        case 0xCAu:
        case 0xCBu:
        case 0xCCu:
        case 0xCDu:
        case 0xCEu:
        case 0xCFu:
        case 0xD0u:
        case 0xD1u:
        case 0xD2u:
        case 0xD3u:
        case 0xD4u:
        case 0xD5u:
        case 0xD6u:
        case 0xD7u:
        case 0xD8u:
        case 0xD9u:
        case 0xDAu:
        case 0xDBu:
        case 0xDCu:
        case 0xDDu:
        case 0xDEu:
        case 0xDFu:
        case 0xE0u:
        case 0xE1u:
        case 0xE2u:
        case 0xE3u:
        case 0xE4u:
        case 0xE5u:
        case 0xE6u:
        case 0xE7u:
        case 0xE8u:
        case 0xE9u:
        case 0xEAu:
        case 0xEBu:
        case 0xECu:
        case 0xEDu:
        case 0xEEu:
        case 0xEFu:
        case 0xF0u:
        case 0xF1u:
        case 0xF2u:
        case 0xF3u:
        case 0xF4u:
        case 0xF5u:
        case 0xF6u:
        case 0xF7u:
        case 0xF8u:
        case 0xF9u:
        case 0xFAu:
        case 0xFBu:
        case 0xFCu:
        case 0xFDu:
        case 0xFEu:
        case 0xFFu:
        case 0x100u:
        case 0x101u:
        case 0x102u:
        case 0x103u:
        case 0x104u:
        case 0x105u:
        case 0x106u:
        case 0x107u:
        case 0x108u:
        case 0x109u:
        case 0x10Au:
        case 0x10Bu:
        case 0x10Cu:
        case 0x10Du:
        case 0x10Eu:
        case 0x10Fu:
        case 0x110u:
        case 0x111u:
        case 0x112u:
        case 0x113u:
        case 0x114u:
        case 0x115u:
        case 0x116u:
        case 0x119u:
        case 0x11Au:
        case 0x11Bu:
        case 0x11Cu:
        case 0x11Du:
        case 0x11Eu:
        case 0x11Fu:
        case 0x120u:
        case 0x121u:
        case 0x122u:
        case 0x123u:
        case 0x124u:
        case 0x127u:
        case 0x128u:
        case 0x129u:
        case 0x12Au:
        case 0x12Bu:
        case 0x12Cu:
        case 0x12Du:
        case 0x12Eu:
        case 0x12Fu:
        case 0x130u:
        case 0x131u:
        case 0x132u:
        case 0x133u:
        case 0x134u:
        case 0x135u:
        case 0x137u:
        case 0x138u:
          goto LABEL_29;
        case 0x67u:
        case 0x7Du:
        case 0x7Fu:
        case 0x126u:
          return 0;
        case 0x6Bu:
          v84 = *v26;
          v85 = *v26 & 0xF;
          *(_DWORD *)(a2 + 112) = *v26;
          if ( (v84 & 0xF) <= 0xB )
          {
            if ( v85 > 9 )
            {
              if ( v85 == 10 )
              {
                v235 = *(_QWORD *)(a2 + 92);
                *(_BYTE *)(a2 + 122) = 24;
                v87 = v235 & 0xFFFFFFFFFFFFE1FFLL | 0x400;
                goto LABEL_201;
              }
              if ( v85 == 11 )
              {
                v196 = *(_QWORD *)(a2 + 92);
                *(_BYTE *)(a2 + 122) = 12;
                v87 = v196 & 0xFFFFFFFFFFFFE1FFLL | 0x600;
                goto LABEL_201;
              }
            }
            else
            {
              if ( v85 == 8 )
              {
                v233 = *(_QWORD *)(a2 + 92);
                *(_BYTE *)(a2 + 122) = 96;
                v87 = v233 & 0xFFFFFFFFFFFFE1FFLL;
                goto LABEL_201;
              }
              if ( v85 == 9 )
              {
                v86 = *(_QWORD *)(a2 + 92);
                *(_BYTE *)(a2 + 122) = 48;
                v87 = v86 & 0xFFFFFFFFFFFFE1FFLL | 0x200;
                goto LABEL_201;
              }
            }
            goto LABEL_200;
          }
          if ( v85 <= 13 )
          {
            if ( v85 == 12 )
            {
              v234 = *(_QWORD *)(a2 + 92);
              *(_BYTE *)(a2 + 122) = 108;
              v87 = v234 & 0xFFFFFFFFFFFFE1FFLL | 0x800;
              goto LABEL_201;
            }
            if ( v85 == 13 )
            {
              v177 = *(_QWORD *)(a2 + 92);
              *(_BYTE *)(a2 + 122) = 72;
              v87 = v177 & 0xFFFFFFFFFFFFE1FFLL | 0xA00;
              goto LABEL_201;
            }
LABEL_200:
            v87 = *(_QWORD *)(a2 + 92);
            goto LABEL_201;
          }
          if ( v85 == 14 )
          {
            v236 = *(_QWORD *)(a2 + 92);
            *(_BYTE *)(a2 + 122) = 36;
            v87 = v236 & 0xFFFFFFFFFFFFE1FFLL | 0xC00;
          }
          else
          {
            v197 = *(_QWORD *)(a2 + 92);
            *(_BYTE *)(a2 + 122) = 18;
            v87 = v197 & 0xFFFFFFFFFFFFE1FFLL | 0xE00;
          }
LABEL_201:
          v62 = v87 | 0x8000000000LL;
          goto LABEL_202;
        case 0x6Cu:
          v74 = *v26;
          v75 = *v26 & 0xF;
          *(_DWORD *)(a2 + 116) = *v26;
          if ( (v74 & 0xF) <= 3 )
          {
            if ( v75 == 1 )
            {
              v229 = *(_QWORD *)(a2 + 92);
              *(_BYTE *)(a2 + 122) = 2;
              v77 = v229 & 0xFFFFFFFFFFFFE1FFLL | 0x600;
              goto LABEL_195;
            }
            if ( v75 != 2 )
            {
              if ( v75 == 3 )
              {
                v190 = *(_QWORD *)(a2 + 92);
                *(_BYTE *)(a2 + 122) = 11;
                v77 = v190 & 0xFFFFFFFFFFFFE1FFLL | 0x200;
                goto LABEL_195;
              }
              goto LABEL_191;
            }
            v232 = *(_QWORD *)(a2 + 92);
            *(_BYTE *)(a2 + 122) = 4;
            v77 = v232 & 0xFFFFFFFFFFFFE1FFLL | 0x400;
          }
          else if ( v75 > 5 )
          {
            if ( v75 != 6 )
            {
              if ( v75 == 7 )
              {
                v193 = *(_QWORD *)(a2 + 92);
                *(_BYTE *)(a2 + 122) = 22;
                v77 = v193 & 0xFFFFFFFFFFFFE1FFLL | 0x800;
                goto LABEL_195;
              }
              goto LABEL_191;
            }
            v231 = *(_QWORD *)(a2 + 92);
            *(_BYTE *)(a2 + 122) = 11;
            v77 = v231 & 0xFFFFFFFFFFFFE1FFLL | 0xA00;
          }
          else
          {
            if ( v75 != 4 )
            {
              if ( v75 == 5 )
              {
                v76 = *(_QWORD *)(a2 + 92);
                *(_BYTE *)(a2 + 122) = 4;
                v77 = v76 & 0xFFFFFFFFFFFFE1FFLL | 0xC00;
                goto LABEL_195;
              }
LABEL_191:
              v77 = *(_QWORD *)(a2 + 92);
              goto LABEL_195;
            }
            v230 = *(_QWORD *)(a2 + 92);
            *(_BYTE *)(a2 + 122) = 22;
            v77 = v230 & 0xFFFFFFFFFFFFE1FFLL;
          }
LABEL_195:
          v62 = v77 | 0x4000000000LL;
          goto LABEL_202;
        case 0x6Du:
          v58 = *(_QWORD *)(a2 + 92) & 0xFFFFFFFFFEFFFFFFLL | ((((unsigned __int64)a1[2] >> 6) & 1) << 24);
          *(_QWORD *)(a2 + 92) = v58;
          v59 = a1[1];
          v60 = v58 & 0xFFFFFFFFFFFFE1FFLL | (v59 << 9) & 0x1E00;
          *(_QWORD *)(a2 + 92) = v60;
          *(_BYTE *)(a2 + 125) = v59 & 0xF;
          v61 = v60 & 0xFFFFFFFFFFF0FFFFLL | ((((unsigned __int64)a1[1] >> 7) & 1) << 16);
          *(_QWORD *)(a2 + 92) = v61;
          v62 = v61 & 0xFFF87FFFFF9101FFLL
              | (v59 << 9) & 0xE00
              | (unsigned __int64)(((a1[2] << 14) & 0x200000 | (((v59 >> 3) & 1) << 13)) + 0x2000);
          goto LABEL_202;
        case 0x6Eu:
          v99 = *(_QWORD *)(a2 + 92) & 0xFFFFFFFFFEFFFFFFLL | ((((unsigned __int64)a1[2] >> 2) & 1) << 24);
          *(_QWORD *)(a2 + 92) = v99;
          v100 = (a1[1] >> 4) & 0x3F;
          *(_BYTE *)(a2 + 139) = (a1[1] >> 4) & 0x3F;
          v101 = v99 & 0xFFFFFFFFFFFFE1FFLL | ((((unsigned __int64)a1[2] >> 4) & 0xF) << 9);
          *(_QWORD *)(a2 + 92) = v101;
          v102 = v101 & 0xFFFFFFFFFF9FFFFFLL | ((unsigned __int64)(a1[2] & 3) << 21);
          *(_QWORD *)(a2 + 92) = v102;
          v103 = *(_DWORD *)(v13 + 324);
          if ( v103 > 0x2B )
            goto LABEL_185;
          if ( ((1LL << v103) & 0x28067000000LL) != 0 || ((1LL << v103) & 0xD2480000000LL) != 0 )
            goto LABEL_81;
          if ( ((1LL << v103) & 0x18000000) != 0 )
          {
            v102 &= 0xFFFFFFFFFFFF1FFFLL;
          }
          else
          {
LABEL_185:
            if ( v103 != 21 && v103 != 20 )
            {
LABEL_89:
              *(_BYTE *)(a2 + 134) = ((unsigned int)v102 >> 5) & 0xF0 | ((unsigned __int16)v102 >> 13);
              v110 = a1[1];
              v111 = v102 & 0xFFFFFFFFFFF0FFFFLL | ((unsigned __int64)(v110 & 3) << 16);
              *(_QWORD *)(a2 + 92) = v111;
              *(_BYTE *)(a2 + 133) = v110 & 3;
              *(_BYTE *)(a2 + 138) = (a1[2] & 4) != 0;
              if ( v100 != 63 && v100 )
                v62 = v111 & 0xFFF87FFFFDF3FFFFLL | (a1[2] << 17) & 0x2000000 | 0x800000000000LL;
              else
                v62 = v111 & 0xFFF87FFFFDF3FFFFLL | (a1[2] << 17) & 0x2000000;
LABEL_202:
              *(_QWORD *)(a2 + 92) = v62;
              return 0;
            }
LABEL_81:
            v104 = (*v26 << 17) & 0x100000;
            v105 = v102 & 0xFFFFFFFFFFEFFFFFLL | ((((unsigned __int64)*v26 >> 3) & 1) << 20);
            *(_QWORD *)(a2 + 92) = v105;
            v106 = v105 & 0xFFFFFFFFFFFF1FFFLL;
            v107 = (*v26 >> 10) & 7;
            if ( v107 )
              v108 = v104 == 0;
            else
              v108 = 1;
            if ( v108 )
              v109 = v107;
            else
              v109 = ((((*v26 >> 10) & 7) + 1) >> 1) - 1;
            v102 = v106 | (unsigned __int16)((v109 << 13) + 0x2000) & 0xE000;
          }
          *(_QWORD *)(a2 + 92) = v102;
          goto LABEL_89;
        case 0x77u:
          v37 = *(_QWORD *)(a2 + 92) | 4LL;
          *(_QWORD *)(a2 + 92) = v37;
          v38 = a1[1];
          *(_WORD *)(a2 + 182) = 254;
          if ( (v38 & 1) != 0 )
            v39 = -15364;
          else
            v39 = -15361;
          *(_WORD *)(a2 + 180) = v39;
          v40 = a1[1];
          *(_WORD *)(a2 + 184) = (v40 >> 8) & 0x3F;
          v41 = (32 * a1[1]) & 0x40 | (v40 >> 8) & 0x3F;
          *(_WORD *)(a2 + 184) = v41;
          v42 = a1[1];
          *(_QWORD *)(a2 + 92) = v37 & 0xFDFFFFFFFFFFFFFFLL;
          v43 = v41 & 0xFFFFFF7F | (((v42 >> 2) & 1) << 7);
          *(_WORD *)(a2 + 184) = v43;
          v44 = a1[1];
          v45 = v37 & 0xFDFFFFFFFFFFE1FFLL | (((v44 >> 3) & 0xF) << 9);
          v46 = v43 & 0xFFFFF0FF | ((((unsigned int)v44 >> 3) & 0xF) << 8);
          *(_QWORD *)(a2 + 92) = v45;
          *(_WORD *)(a2 + 184) = v46;
          v47 = a1[1];
          v48 = v46 & 0xFFFFEFFF | (((v47 >> 7) & 1) << 12);
          *(_WORD *)(a2 + 184) = v48;
          LODWORD(v44) = a1[2];
          v49 = v48 & 0xFFFFDFFF | ((((unsigned int)v44 >> 7) & 1) << 13);
          v50 = v45 & 0xFFFFFFFFFEFFFFFFLL | ((_DWORD)v44 << 17) & 0x1000000;
          *(_QWORD *)(a2 + 92) = v50;
          *(_WORD *)(a2 + 184) = v49;
          LOWORD(v49) = v49 & 0xBFFF | (((a1[2] >> 8) & 1) << 14);
          *(_WORD *)(a2 + 184) = v49;
          v51 = a1[2];
          *(_WORD *)(a2 + 184) = ((_WORD)v51 << 6) & 0x8000 | v49;
          *(_WORD *)(a2 + 186) = (a1[1] >> 15) & 0xF;
          v52 = (unsigned __int64)a1[1] >> 19;
          v53 = v50 & 0xFDFFFFFFFFF0FFFFLL | ((v52 & 3) << 16);
          *(_WORD *)(a2 + 188) = v52 & 3;
          *(_QWORD *)(a2 + 92) = v53;
          v54 = (a1[1] >> 21) & 3;
          if ( v54 > 1 )
          {
            if ( v54 == 2 )
            {
              v176 = v53 & 0xFDE7FFFFFF93FFFFLL;
              v57 = 128;
              v56 = v176 | 0x8000000400000LL;
              v55 = 16;
            }
            else
            {
              v194 = (v47 >> 7) & 1;
              v195 = v53 & 0xFDE7FFFFFF93FFFFLL;
              if ( v194 && (v51 & 0x200) != 0 )
              {
                v55 = 0;
                v56 = v195 | 0x10000000000000LL;
                v57 = 192;
              }
              else
              {
                v57 = 192;
                v56 = v195 | 0x10000000600000LL;
                v55 = 32;
              }
            }
          }
          else
          {
            v55 = 0;
            v56 = v53 & 0xFDE7FFFFFF93FFFFLL;
            if ( v54 )
            {
              v56 |= 0x8000000000000uLL;
              v57 = 128;
            }
            else
            {
              v57 = 64;
            }
          }
          *(_QWORD *)(a2 + 92) = v56;
          v221 = v55 | v57 | v52 & 3;
          *(_WORD *)(a2 + 188) = v221;
          v222 = (a1[1] >> 15) & 0x700 | v221;
          *(_WORD *)(a2 + 188) = v222;
          v223 = v222 & 0xFFFFCFFF | (((a1[2] >> 11) & 3) << 12);
          *(_WORD *)(a2 + 188) = v223;
          v224 = v223 & 0xFFFFBFFF | (((a1[2] >> 10) & 1) << 14);
          *(_WORD *)(a2 + 188) = v224;
          *(_WORD *)(a2 + 188) = v224 & 0x7FFF | (((a1[2] >> 13) & 1) << 15);
          v225 = ((a1[1] >> 23) & 7) + 1;
          v226 = ((a1[1] >> 23) & 7) + 1;
          *(_WORD *)(a2 + 190) = v225;
          v227 = v56 & 0xFFFFFFFFFFFF1FFFLL | ((unsigned __int64)(v226 & 7) << 13);
          *(_QWORD *)(a2 + 92) = v227;
          v228 = (a1[2] >> 11) & 0x10 | v225;
          *(_WORD *)(a2 + 190) = v228;
          *(_WORD *)(a2 + 190) = v228 & 0x80FF | ((a1[2] & 0x7F) << 8);
          v62 = v227 & 0xFFF87FFFFDFFFFFFLL | ((((unsigned __int64)a1[2] >> 10) & 1) << 25);
          goto LABEL_202;
        case 0x78u:
          v88 = *(_QWORD *)(a2 + 92) | 8LL;
          *(_DWORD *)(a2 + 180) = 15647510;
          *(_QWORD *)(a2 + 92) = v88;
          v89 = (a1[1] >> 5) & 0x3F;
          *(_WORD *)(a2 + 184) = v89;
          v90 = v89 & 0xFFFFFF7F | ((a1[1] & 1) << 7);
          *(_WORD *)(a2 + 184) = v90;
          v91 = v90 & 0xFFFFBFFF | (((a1[2] >> 11) & 1) << 14);
          *(_WORD *)(a2 + 184) = v91;
          *(_WORD *)(a2 + 184) = v91 & 0x7FFF | (((a1[2] >> 12) & 1) << 15);
          *(_WORD *)(a2 + 186) = (a1[1] >> 11) & 0xF;
          v92 = ((unsigned __int64)a1[1] >> 15) & 7;
          v93 = v88 & 0xFFFFFFFFFFF0FFFFLL | (v92 << 16);
          *(_WORD *)(a2 + 188) = v92;
          *(_QWORD *)(a2 + 92) = v93;
          v94 = ((unsigned __int64)a1[1] >> 23) & 3;
          v95 = v93 & 0xFFE7FFFFFF97FFFFLL | qword_B35268[v94];
          LOWORD(v92) = (0x20001000000000uLL >> (16 * (unsigned __int8)v94))
                      | (0xC00080008000C0uLL >> (16 * (unsigned __int8)v94))
                      | v92;
          *(_QWORD *)(a2 + 92) = v95;
          *(_WORD *)(a2 + 188) = v92;
          LOWORD(v92) = a1[2] & 0x700 | v92;
          *(_WORD *)(a2 + 188) = v92;
          LOWORD(v92) = (a1[2] >> 1) & 0x3000 | v92;
          *(_WORD *)(a2 + 188) = v92;
          *(_WORD *)(a2 + 188) = a1[2] & 0x8000 | v92;
          LOWORD(v92) = (a1[1] >> 21) & 0x10 | *(_WORD *)(a2 + 190);
          *(_WORD *)(a2 + 190) = v92;
          LOBYTE(v94) = a1[2];
          *(_WORD *)(a2 + 168) = -16048;
          *(_WORD *)(a2 + 190) = ((v94 & 0x7F) << 8) | v92;
          LODWORD(v94) = (a1[1] >> 1) & 7 | 0xFFFFC150;
          *(_WORD *)(a2 + 168) = v94;
          LOWORD(v94) = v94 & 0xFFDF | (32 * ((a1[1] >> 4) & 1));
          *(_WORD *)(a2 + 170) = 4;
          *(_WORD *)(a2 + 168) = v94;
          v96 = (a1[1] >> 15) & 3 | 4;
          *(_WORD *)(a2 + 170) = (a1[1] >> 15) & 3 | 4;
          v97 = (a1[1] >> 22) & 1;
          if ( v97 )
            *(_QWORD *)(a2 + 92) = v95 & 0xFFF87FFFFFF7FFFFLL | 0x800000000000LL;
          v98 = v96 | (8 * v97);
          *(_WORD *)(a2 + 170) = v98;
          *(_WORD *)(a2 + 170) = ((*v26 >> 14) & 0xF0 | v98) - 16;
          return 0;
        case 0x79u:
          v149 = *(_QWORD *)(a2 + 92) | 0x4000000000000004LL;
          *(_QWORD *)(a2 + 92) = v149;
          v150 = v149 & 0xFFFFFFFFFFF0FFFFLL;
          if ( (a1[1] & 1) != 0 )
            v151 = 16388;
          else
            v151 = 16391;
          *(_WORD *)(a2 + 182) |= 0x40u;
          *(_WORD *)(a2 + 180) = v151;
          *(_WORD *)(a2 + 184) = (a1[1] >> 1) & 0x3F;
          v152 = v150 & 0xFFFFFFFFFFFCFFFFLL | ((unsigned __int64)(HIBYTE(a1[1]) & 3) << 16);
          *(_WORD *)(a2 + 188) = HIBYTE(a1[1]) & 3;
          *(_QWORD *)(a2 + 92) = v152;
          v153 = a1[2];
          v154 = *(_WORD *)(a2 + 190);
          *(_QWORD *)(a2 + 92) = v152 & 0xFDF87FFFFFFFFFFFLL | 0x200800000000000LL;
          v24 = 0;
          *(_WORD *)(a2 + 190) = ((v153 & 0x7F) << 8) | v154;
          return v24;
        case 0x7Au:
          *(_WORD *)(a2 + 110) |= 1u;
          v155 = *(_QWORD *)(a2 + 92) & 0xFFF87FFFFFFFFFFFLL;
          *(_BYTE *)(a2 + 172) = *v26;
          v62 = v155 | 0x800000000000LL;
          goto LABEL_202;
        case 0x7Bu:
          *(_WORD *)(a2 + 180) |= 0xA0u;
          v63 = *v26;
          v64 = *(_QWORD *)(a2 + 92) & 0xFFFFFFFFFFFFE1FFLL | (((v63 >> 15) & 0xF) << 9);
          LOWORD(v63) = ((unsigned int)v63 >> 7) & 0xF00 | *(_WORD *)(a2 + 184);
          *(_QWORD *)(a2 + 92) = v64;
          *(_WORD *)(a2 + 184) = v63;
          *(_WORD *)(a2 + 184) = (*v26 >> 7) & 0x2000 | v63;
          *(_WORD *)(a2 + 186) |= 16 * (*(_WORD *)v26 & 0x7FF);
          LOWORD(v63) = ((*v26 >> 28) & 7) + 1;
          v65 = v64 & 0xFFFFFFFFFFFF1FFFLL | ((v63 & 7) << 13);
          *(_WORD *)(a2 + 190) |= v63;
          v24 = 0;
          *(_QWORD *)(a2 + 92) = v65;
          return v24;
        case 0x7Cu:
          v78 = *(_WORD *)(a2 + 182) | 0x10;
          *(_WORD *)(a2 + 180) |= 0xE0u;
          *(_WORD *)(a2 + 182) = v78;
          v79 = *v26;
          v80 = *(_QWORD *)(a2 + 92) & 0xFFFFFFFFFFFFE1FFLL | (((v79 >> 15) & 0xF) << 9);
          LOWORD(v79) = ((unsigned int)v79 >> 7) & 0xF00 | *(_WORD *)(a2 + 184);
          *(_QWORD *)(a2 + 92) = v80;
          *(_WORD *)(a2 + 184) = v79;
          LOWORD(v79) = (*v26 >> 7) & 0x1000 | v79;
          *(_WORD *)(a2 + 184) = v79;
          *(_WORD *)(a2 + 184) = (*v26 >> 7) & 0x2000 | v79;
          *(_WORD *)(a2 + 186) |= 16 * (*(_WORD *)v26 & 0x7FF);
          *(_WORD *)(a2 + 188) |= *v26 & 0x4000;
          LOWORD(v79) = ((*v26 >> 11) & 7) + 1;
          *(_WORD *)(a2 + 190) |= v79;
          v62 = v80 & 0xFFF87FFFFFFF1FFFLL | ((v79 & 7) << 13) | 0x1000000000000LL;
          goto LABEL_202;
        case 0x7Eu:
          v81 = *(_DWORD *)(a2 + 328);
          *(_DWORD *)(a2 + 324) |= 0xCu;
          v82 = *(_QWORD *)(a2 + 92);
          v83 = (a1[3] >> 9) & 0x180 | v81;
          *(_DWORD *)(a2 + 328) = v83;
          if ( (v82 & 0x600000) == 0 )
          {
            v82 |= (32 * a1[3]) & 0x600000;
            *(_QWORD *)(a2 + 92) = v82;
          }
          *(_DWORD *)(a2 + 328) = (a1[3] >> 9) & 0x600 | v83;
          if ( (v82 & 0x18000000000000LL) == 0 )
            *(_QWORD *)(a2 + 92) = (*(_QWORD *)(a1 + 3) << 33) & 0x18000000000000LL | v82;
          *(_WORD *)(a2 + 310) = *((_WORD *)a1 + 9);
          return 0;
        case 0x81u:
          return 2;
        case 0xC0u:
          if ( *(_DWORD *)(a2 + 52) == (unsigned __int16)*v26 )
          {
            v284 = a2;
            qdf_trace_msg(
              0x46u,
              2u,
              "%s: Matching ppdu_id(%u) detected",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "hal_rx_status_get_tlv_info_generic_be");
            a2 = v284;
          }
          v30 = (unsigned __int16)a1[1];
          *(_DWORD *)a2 = v30;
          *(_DWORD *)(a2 + 52) = v30;
          v31 = a1[2];
          *(_WORD *)(a2 + 88) = v31;
          v32 = a1[2];
          v33 = HIWORD(v32);
          if ( (_WORD)v31 && v32 >= 0x10000 )
          {
            v34 = a2;
            v35 = hal_rx_radiotap_num_to_freq();
            a2 = v34;
            v33 = v35;
          }
          *(_DWORD *)(a2 + 84) = v33;
          v36 = a1[3];
          *(_BYTE *)(v11 + 1064) = 0;
          *(_QWORD *)(a2 + 8) = v36;
          *(_DWORD *)(a2 + 80) = v36;
          return 0;
        case 0xC1u:
          *(_BYTE *)(v11 + 1064) = 1;
          return 0;
        case 0xC2u:
          v135 = a1[12];
          v136 = *(_WORD *)(v11 + 1040) & 0xFFFE | (*(unsigned __int8 *)(v11 + 1042) << 16) | a1[9] & 1;
          *(_WORD *)(v11 + 1040) = *(_WORD *)(v11 + 1040) & 0xFFFE | a1[9] & 1;
          v137 = a1[9];
          *(_WORD *)(v11 + 1040) = v136;
          v138 = v136 & 0xFFFDFFFF | (((v137 >> 17) & 1) << 17);
          *(_BYTE *)(v11 + 1042) = BYTE2(v138);
          v139 = v138 & 0xFE0001 | (*((_QWORD *)a1 + 7) >> 31) & 0x1FFFE;
          *(_WORD *)(v11 + 1040) = v139;
          *(_BYTE *)(v11 + 1042) = BYTE2(v139);
          *(_BYTE *)(v11 + 1085) = (a1[12] >> 2) & 0x7F;
          if ( (unsigned int)v22 >> 26 > 0x24 )
            goto LABEL_341;
          v140 = a2 + 344LL * (unsigned int)v25;
          v141 = *(unsigned __int8 *)(v11 + 1085);
          *(_WORD *)(v140 + 418) = *((_WORD *)a1 + 23);
          v142 = HIWORD(v135);
          v143 = *(unsigned __int16 *)(v11 + 1040) | (*(unsigned __int8 *)(v11 + 1042) << 16);
          if ( v141 == 3 )
          {
            *(_QWORD *)(a2 + 92) = *(_QWORD *)(a2 + 92) & 0xFFFFDFFFFFFFFFFFLL
                                 | ((unsigned __int64)(*(_WORD *)(v11 + 1040) & 1) << 45);
            *(_WORD *)(a2 + 156) = v143 >> 1;
          }
          v144 = *(_WORD *)(v11 + 1052) & 0xFFFE | (*(unsigned __int8 *)(v11 + 1054) << 16) | a1[9] & 1;
          *(_WORD *)(v11 + 1052) = *(_WORD *)(v11 + 1052) & 0xFFFE | a1[9] & 1;
          v145 = (*((_QWORD *)a1 + 7) >> 31) & 0x1FFFE | v144 & 0xFE0001;
          *(_WORD *)(v11 + 1052) = v145;
          *(_BYTE *)(v11 + 1054) = BYTE2(v145);
          v146 = *((_QWORD *)a1 + 4);
          *(_WORD *)(v11 + 1040) = v143;
          *(_BYTE *)(v11 + 1042) = ((v146 >> 17) & 0x40000 | v143 & 0xFBFFFF) >> 16;
          *(_WORD *)(v11 + 1043) = *((_WORD *)a1 + 35);
          v147 = *(unsigned __int16 *)(a2 + 196);
          *(_DWORD *)(v11 + 1045) = *((_QWORD *)a1 + 9);
          if ( v142 == v147 )
          {
            v148 = (a1[14] & 0x3FFF) + *(_DWORD *)(a2 + 192);
          }
          else
          {
            *(_WORD *)(a2 + 196) = v142;
            v148 = a1[14] & 0x3FFF;
          }
          *(_DWORD *)(a2 + 192) = v148;
          v180 = *((_QWORD *)a1 + 6);
          if ( (a1[12] & 3) != 0 )
          {
            if ( (v180 & 3) != 1 )
              goto LABEL_155;
            v181 = 0x20000000000LL;
          }
          else
          {
            v181 = 0x80000000000LL;
          }
          *(_QWORD *)(a2 + 92) |= v181;
LABEL_155:
          *(_QWORD *)(v140 + 416) = *(_QWORD *)(v140 + 416) & 0x9FFFFFFFFFFFFFFFLL
                                  | ((unsigned __int64)(v180 & 3) << 61);
          v191 = *(unsigned __int16 *)(v11 + 1040);
          v192 = (16 * a1[14]) & 0x80000 | (v191 | (*(unsigned __int8 *)(v11 + 1042) << 16)) & 0xFFF7FFFF;
          *(_WORD *)(v11 + 1040) = v191;
          *(_BYTE *)(v11 + 1042) = BYTE2(v192);
          *(_BYTE *)(a2 + 4LL * (unsigned int)v25 + 14984) = (*((_QWORD *)a1 + 6) >> 42) & 3;
          *(_BYTE *)(v140 + 706) = (*((_BYTE *)a1 + 8) >> 2) & 0xF;
          return 10;
        case 0xC3u:
          v156 = a1[2];
          *(_BYTE *)(v11 + 1084) = (v156 & 0x80000) != 0;
          if ( (unsigned int)v22 >> 26 > 0x24 )
            goto LABEL_341;
          v157 = a2 + 4LL * (unsigned int)v25;
          v158 = *(_DWORD *)(v157 + 14984) & 0xFFFFFDFF | (((v156 >> 19) & 1) << 9);
          v24 = 6;
          *(_DWORD *)(v157 + 14984) = v158;
          return v24;
        case 0xC5u:
          if ( (unsigned int)v22 >> 26 <= 0x24 )
          {
            v129 = a2 + 12LL * (unsigned int)v25;
            v130 = *(_QWORD *)(v129 + 13380) & 0xFFFFFFFFFFFF0000LL | *((unsigned __int16 *)a1 + 30);
            *(_QWORD *)(v129 + 13380) = v130;
            *(_DWORD *)(v129 + 13376) = a1[14];
            v131 = v130 & 0xFFFFFFFFFFFEFFFFLL | (((*(_QWORD *)(a1 + 15) >> 44) & 1LL) << 16);
            *(_QWORD *)(v129 + 13380) = v131;
            v132 = v131 & 0xFFFFFFFFFFFDFFFFLL | (((*(_QWORD *)(a1 + 15) >> 45) & 1LL) << 17);
            *(_QWORD *)(v129 + 13380) = v132;
            *(_QWORD *)(v129 + 13380) = v132 & 0xFFF00000FFFFFFFFLL | (((*(_QWORD *)(a1 + 13) >> 6) & 0xFFFFFLL) << 32);
            v129 += 14540;
            v133 = *(_QWORD *)v129 & 0xFFFFFFFFFFFFFFDFLL | (32 * ((*(_QWORD *)(a1 + 11) >> 28) & 1LL));
            *(_QWORD *)v129 = v133;
            v134 = v133 & 0xFFFFFFFFFFFFFDFFLL | (((*(_QWORD *)(a1 + 11) >> 29) & 1LL) << 9);
            *(_QWORD *)v129 = v134;
            *(_WORD *)(v129 + 8) = a1[19] & 0x3FFF;
            *(_WORD *)(v129 + 10) = *((unsigned __int8 *)a1 + 92);
            *(_QWORD *)v129 = v134 & 0xFFFFFFFFFFF8FFFFLL | (((*(_QWORD *)(a1 + 23) >> 21) & 7LL) << 16);
          }
          return 8;
        case 0xC9u:
          if ( *(unsigned __int8 *)(v11 + 1532) >= 0x10u )
          {
            v28 = "%s: Number of MPDUs(%d) per status buff exceeded";
            v29 = 2;
            goto LABEL_104;
          }
          v178 = a2 + 16LL * *(unsigned __int8 *)(v11 + 1532);
          v179 = ((unsigned int)v22 >> 10) & 0xFFF;
          *(_QWORD *)(a2 + 13296) = v26;
          *(_QWORD *)(v178 + 13824) = v26;
          *(_WORD *)(v178 + 13832) = v179;
          LOWORD(v178) = *(_WORD *)(a2 + 56);
          *(_WORD *)(v11 + 1016) = v179;
          *(_DWORD *)(a2 + 13368) = v179;
          *(_QWORD *)(a2 + 13360) = a1 + 2;
          LOWORD(v179) = v178 + 1;
          v24 = 5;
          *(_BYTE *)(v11 + 1065) = (unsigned int)v22 >> 26;
          *(_WORD *)(a2 + 56) = v179;
          return v24;
        case 0x117u:
          if ( (unsigned int)v22 >> 26 >= 0x25 )
            goto LABEL_341;
          v112 = *(unsigned __int8 *)(v11 + 1085);
          v113 = a2 + 344LL * (unsigned int)v25;
          *(_WORD *)(v113 + 418) = *((_WORD *)a1 + 6);
          v114 = *((_QWORD *)a1 + 2);
          *(_WORD *)(a2 + 158) = WORD2(v114);
          v115 = *(_QWORD *)(a2 + 92) & 0xFFFFFFE0FFFFFFFFLL
               | ((__clz(__rbit64(*((unsigned __int16 *)a1 + 26))) & 0x1F) << 32);
          *(_QWORD *)(a2 + 92) = v115;
          v116 = HIWORD(*((_QWORD *)a1 + 5)) + WORD1(*((_QWORD *)a1 + 5));
          *(_WORD *)(a2 + 126) = HIWORD(*((_QWORD *)a1 + 5)) + WORD1(*((_QWORD *)a1 + 5));
          v117 = *((_WORD *)a1 + 20);
          *(_WORD *)(a2 + 128) = v117;
          v118 = *((_QWORD *)a1 + 5);
          *(_WORD *)(a2 + 308) = 0;
          v119 = HIDWORD(v118);
          *(_WORD *)(a2 + 130) = v119;
          if ( v112 != 3 )
          {
            v120 = *((_QWORD *)a1 + 2);
            v115 = v115 & 0xFFFFDFFFFFFFFFFFLL | (((v120 >> 11) & 1) << 45);
            *(_QWORD *)(a2 + 92) = v115;
            if ( (v120 & 0x800) != 0 )
              *(_WORD *)(a2 + 156) = *((_WORD *)a1 + 11);
          }
          v121 = *((_QWORD *)a1 + 2);
          v122 = (unsigned int)v25;
          v123 = (unsigned __int64 *)(v113 + 400);
          v124 = v115 & 0xFFFFFBFFFFFFFFFFLL | (((v121 >> 14) & 1) << 42);
          *(_QWORD *)(a2 + 92) = v124;
          if ( (v121 & 0x4000) != 0 )
            *(_WORD *)(a2 + 204) = *((_QWORD *)a1 + 3);
          v125 = *((_QWORD *)a1 + 2);
          v126 = v124 & 0xFFFFFFFF87FFFFFFLL | (((v125 >> 21) & 0xF) << 27);
          v127 = ((_DWORD)v125 << 6 >> 27) & 0xF;
          v128 = *(_BYTE *)(v11 + 2864) + 1;
          *(_QWORD *)(a2 + 92) = v126;
          *(_BYTE *)(v11 + 2864) = v128;
          if ( v127 > 3 )
          {
            if ( v127 == 4 )
            {
              v126 |= 4u;
            }
            else
            {
              if ( v127 != 6 )
                goto LABEL_174;
              v126 |= 0x20u;
            }
          }
          else
          {
            if ( v127 == 2 )
            {
              v198 = *(_BYTE *)(a2 + 123);
              v126 |= 1u;
              *(_QWORD *)(a2 + 92) = v126;
              *(_BYTE *)(a2 + 123) = v198 | 0x80;
              goto LABEL_174;
            }
            if ( v127 != 3 )
              goto LABEL_174;
            v126 |= 2u;
          }
          *(_QWORD *)(a2 + 92) = v126;
LABEL_174:
          v199 = a2 + 4 * v122;
          v200 = *(_BYTE *)(v11 + 840);
          v201 = *(_WORD *)(v11 + 842);
          v202 = a1[4] & 0x7FF;
          v203 = *(_BYTE *)(a2 + 160) & 0xFE;
          *(_WORD *)(a2 + 16) = v202;
          v204 = *((_WORD *)a1 + 7);
          *(_BYTE *)(a2 + 18) = v204;
          if ( (v204 & 0xFE | (unsigned int)v202) > 1 )
            ++v203;
          *(_BYTE *)(a2 + 160) = v203;
          *(_DWORD *)(a2 + 20) = *((_QWORD *)a1 + 4);
          v205 = (const void *)(a2 + 20);
          *(_DWORD *)(a2 + 24) = a1[9];
          v206 = v126 & 0xFFFFFFFFFFFF1FFFLL
               | ((unsigned __int64)((unsigned __int8)((unsigned __int16)((a1[2] >> 4) + 0x2000) >> 8) >> 5) << 13);
          v207 = v199 + 13142;
          *(_QWORD *)(a2 + 92) = v206;
          v208 = *((_QWORD *)a1 + 1);
          *(_BYTE *)(v207 + 2) = v200;
          v209 = *(_BYTE *)(a2 + 19);
          *(_WORD *)v207 = v201;
          v210 = v123[2];
          *((_WORD *)v123 + 13) = v116;
          *(_BYTE *)(a2 + 19) = v209 + 1;
          v211 = v206 & 0xFFFFFFFFFFFFE1FFLL | (((v208 >> 13) & 0xF) << 9);
          v212 = *(unsigned __int16 *)(a2 + 156);
          v213 = v126 & 0xF00000000LL | WORD2(v114) | v210 & 0xFFFFFFF0FFFF0000LL;
          v123[2] = v213;
          v214 = v211 << 40;
          *((_WORD *)v123 + 14) = v117;
          *(_QWORD *)(a2 + 92) = v211;
          LOWORD(v207) = *((_WORD *)a1 + 43);
          *((_WORD *)v123 + 15) = v119;
          *((_WORD *)v123 + 154) = v207;
          v215 = *(_BYTE *)(a2 + 123);
          v216 = v213 & 0xE000040FFFFFFFFFLL
               | (v212 << 44) & 0xEFFFFDFFFFFFFFFFLL
               | (v126 >> 2) & 0x80000000000LL
               | (((v126 >> 42) & 1) << 60)
               | (v211 << 40) & 0x10000000000LL
               | (((v126 >> 27) & 0xF) << 36) & 0xFFFFFDFFFFFFFFFFLL
               | (((v211 >> 1) & 1) << 41);
          *((_WORD *)v123 + 16) = *(_WORD *)(a2 + 204);
          *((_BYTE *)v123 + 120) = v215;
          v123[2] = v216;
          if ( (v126 & 2) != 0 )
          {
            v218 = a2;
            *((_BYTE *)v123 + 36) = *(_BYTE *)(a2 + 133);
            qdf_mem_copy((char *)v123 + 37, (const void *)(a2 + 134), 4u);
            v211 = *(_QWORD *)(v218 + 92);
            v217 = v218;
            v219 = *(_WORD *)(v218 + 104);
            v216 = v123[2];
            v203 = *(_BYTE *)(v218 + 160);
            v214 = v211 << 40;
            LOWORD(v202) = *(_WORD *)(v218 + 16);
            LOBYTE(v204) = *(_BYTE *)(v218 + 18);
            *(_WORD *)((char *)v123 + 41) = *(_WORD *)(v218 + 138);
            *((_WORD *)v123 + 22) = v219;
          }
          else
          {
            v217 = a2;
          }
          v220 = *v123;
          *((_BYTE *)v123 + 121) = v203;
          *((_WORD *)v123 + 61) = v202;
          *((_BYTE *)v123 + 124) = v204;
          v123[2] = v216 & 0xFFFFFBFFFFFFFFFFLL | (((v214 >> 42) & 1) << 42);
          *v123 = v220 & 0xFFFFFFFFFFFFFF80LL | ((unsigned __int16)v211 >> 9);
          qdf_mem_copy(v123 + 16, v205, 0x20u);
          *((_WORD *)v123 + 84) = *(_WORD *)(v217 + 308);
          *((_DWORD *)v123 + 40) = a1[18] & 0x1FFFFFF;
          *((_DWORD *)v123 + 41) = a1[20] & 0x1FFFFFF;
          return 0;
        case 0x118u:
          *(_DWORD *)(a2 + 28) = a1[2];
          *(_DWORD *)(a2 + 32) = a1[3];
          *(_DWORD *)(a2 + 36) = a1[4];
          *(_DWORD *)(a2 + 40) = a1[5];
          *(_DWORD *)(a2 + 44) = a1[6];
          *(_DWORD *)(a2 + 48) = a1[7];
          return 0;
        case 0x125u:
          return v24;
        case 0x136u:
          v66 = *(_QWORD *)(a2 + 92);
          if ( (v66 & 0x4000000000000000LL) != 0 )
            return 0;
          v67 = *v26 >> 29;
          if ( v67 <= 2 )
          {
            if ( v67 )
            {
              if ( v67 == 1 )
                v66 = v66 & 0xBDF87FFFFFFFFFFFLL | 0x800000000000LL;
              else
                v66 = v66 & 0xBDF87FFFFFFFFFFFLL | 0x1000000000000LL;
            }
            else
            {
              v66 &= 0xBFF87FFFFFFFFFFFLL;
            }
          }
          else if ( *v26 >> 29 > 4 )
          {
            if ( v67 == 5 )
            {
              v66 = v66 & 0xBDF87FFFFFFFFFFFLL | 0x201000000000000LL;
            }
            else
            {
              if ( v67 != 6 )
                goto LABEL_208;
              v66 = v66 & 0xBDF87FFFFFFFFFFFLL | 0x201800000000000LL;
            }
          }
          else if ( v67 == 3 )
          {
            v66 = v66 & 0xBDF87FFFFFFFFFFFLL | 0x1800000000000LL;
          }
          else
          {
            if ( v67 != 4 )
              goto LABEL_208;
            v66 = v66 & 0xBDF87FFFFFFFFFFFLL | 0x200800000000000LL;
          }
          *(_QWORD *)(a2 + 92) = v66;
LABEL_208:
          ++*(_BYTE *)(v11 + 2865);
          v237 = (*(_QWORD *)(a1 + 1) >> 8) & 0x100000LL;
          *(_QWORD *)(a2 + 92) = v237 | v66 & 0xFFFFFFFFFFEFFFFFLL;
          v238 = a1[3];
          *(_QWORD *)(a2 + 92) = v237 & 0xFFFFFFFFFEFFFFFFLL | v66 & 0xFFFFFFFFFEEFFFFFLL | (((v238 >> 15) & 1) << 24);
          v239 = a1[3];
          *(_QWORD *)(a2 + 92) = v237 & 0xFFFFFFFFFAFFFFFFLL
                               | v66 & 0xFFFFFFFFFAEFFFFFLL
                               | (((v238 >> 15) & 1) << 24) & 0xFFFFFFFFFBFFFFFFLL
                               | (((v239 >> 14) & 1) << 26);
          v240 = v237 & 0xFFFFFFFFFAFFE1FFLL
               | v66 & 0xFFFFFFFFFAEFE1FFLL
               | (((v238 >> 15) & 1) << 24) & 0xFFFFFFFFFBFFE1FFLL
               | (((v239 >> 14) & 1) << 26)
               | ((HIDWORD(*(_QWORD *)(a1 + 1)) & 0xFLL) << 9);
          *(_QWORD *)(a2 + 92) = v240;
          v241 = v240 & 0xFFFFFFFFFFFF1FFFLL
               | ((unsigned __int64)((unsigned __int8)((unsigned __int16)(32 * *((_WORD *)a1 + 6) + 0x2000) >> 8) >> 5) << 13);
          *(_QWORD *)(a2 + 92) = v241;
          if ( (unsigned int)v22 >> 26 > 0x24 )
          {
            v243 = 0;
          }
          else
          {
            v242 = a2 + 344LL * (unsigned int)v25;
            v243 = v242 + 400;
            v244 = *(_QWORD *)(v242 + 400) & 0xFFFF8FFFFFFFFF80LL
                 | (v237 << 26)
                 | ((unsigned __int64)(((_DWORD)v238 << 9) & 0x1000000) << 20);
            *(_DWORD *)(v242 + 476) |= 1u;
            *(_DWORD *)(v242 + 480) |= a1[3] & 1;
            *(_QWORD *)(v242 + 400) = v244 & 0xFFFFFFFFFFFFFF80LL
                                    | ((unsigned __int64)(((_DWORD)v239 << 12) & 0x4000000) << 19)
                                    | ((unsigned __int16)v241 >> 9);
          }
          if ( ((v66 >> 47) & 0xF) - 1 > 2 )
            return 0;
          v245 = *(_QWORD *)(a1 + 3);
          v246 = WORD1(v245) & 0xF;
          if ( (_DWORD)v246 == 15 )
          {
            v247 = 0;
            LODWORD(v246) = 0;
            v248 = 0;
            LODWORD(v249) = 31;
          }
          else
          {
            v249 = HIDWORD(v245) & 0x3F;
            v248 = 1;
            v247 = v246 << (4 * (BYTE4(v245) & 0x3Fu));
          }
          v250 = ((unsigned int)v245 >> 20) & 0xF;
          if ( (_DWORD)v250 != 15 )
          {
            v249 = (v245 >> 40) & 0x3F;
            LODWORD(v246) = v246 + v250;
            ++v248;
            v247 |= v250 << (4 * (unsigned __int8)v249 + 16);
          }
          v251 = BYTE3(v245) & 0xF;
          if ( (_DWORD)v251 != 15 )
          {
            v249 = HIWORD(v245) & 0x3F;
            LODWORD(v246) = v246 + v251;
            ++v248;
            v247 |= v251 << (4 * (BYTE6(v245) & 0x3Fu) + 32);
          }
          v252 = (unsigned int)v245 >> 28;
          if ( (_DWORD)v252 == 15 )
          {
            if ( v248 >= 2 )
              goto LABEL_221;
          }
          else
          {
            v249 = HIBYTE(v245) & 0x3F;
            LODWORD(v246) = v246 + v252;
            v247 |= v252 << (4 * (unsigned __int8)v249 + 48);
            if ( v248 + 1 >= 2 )
            {
LABEL_221:
              LODWORD(v249) = 0;
              if ( v247 <= 0x8005FFFFFFFFFLL )
              {
                if ( v247 <= 0x90009005FLL )
                {
                  if ( v247 > 6291463 )
                  {
                    if ( v247 <= 0x900060008LL )
                    {
                      if ( v247 != 6291464 )
                      {
                        v253 = 0x600090009LL;
                        goto LABEL_269;
                      }
                      goto LABEL_260;
                    }
                    if ( v247 != 0x900060009LL )
                    {
                      if ( v247 != 0x900090006LL )
                        goto LABEL_278;
                      goto LABEL_263;
                    }
LABEL_266:
                    LODWORD(v249) = 3;
                    goto LABEL_279;
                  }
                  if ( v247 == 393224 )
                    goto LABEL_266;
                  if ( v247 != 524294 )
                  {
                    if ( v247 != 524384 )
                      goto LABEL_278;
                    goto LABEL_279;
                  }
LABEL_263:
                  LODWORD(v249) = 1;
                  goto LABEL_279;
                }
                if ( v247 > 0x60007FFFFFFFFLL )
                {
                  if ( v247 > 0x6000A000A0009LL )
                  {
                    if ( v247 != 0x6000A000A000ALL )
                    {
                      v253 = 0x8000600000000LL;
LABEL_269:
                      if ( v247 == v253 )
                        goto LABEL_270;
                      goto LABEL_278;
                    }
                  }
                  else if ( v247 != 0x6000800000000LL )
                  {
                    if ( v247 != 0x6000900090000LL )
                      goto LABEL_278;
                    LODWORD(v249) = 11;
                    goto LABEL_279;
                  }
LABEL_271:
                  LODWORD(v249) = 7;
                  goto LABEL_279;
                }
                if ( v247 == 0x900090060LL )
                  goto LABEL_279;
                if ( v247 != 0x900600009LL )
                {
                  if ( v247 != 0x6000090009LL )
                    goto LABEL_278;
                  goto LABEL_256;
                }
LABEL_260:
                LODWORD(v249) = 2;
                goto LABEL_279;
              }
              if ( v247 <= 0xA000A000A0005LL )
              {
                if ( v247 > 0x90009005FFFFFLL )
                {
                  if ( v247 > 0xA0006000A0009LL )
                  {
                    if ( v247 == 0xA0006000A000ALL )
                    {
LABEL_270:
                      LODWORD(v249) = 5;
                      goto LABEL_279;
                    }
                    if ( v247 != 0xA000A0006000ALL )
                    {
LABEL_278:
                      v255 = v26;
                      v256 = a2;
                      qdf_trace_msg(
                        0x45u,
                        8u,
                        "%s: Invalid RU index",
                        a4,
                        a5,
                        a6,
                        a7,
                        a8,
                        a9,
                        a10,
                        a11,
                        "hal_rx_parse_receive_user_info");
                      v26 = v255;
                      a2 = v256;
                      LODWORD(v249) = 31;
                      goto LABEL_279;
                    }
                    goto LABEL_266;
                  }
                  if ( v247 != 0x9000900600000LL )
                  {
                    if ( v247 != 0x9006000090000LL )
                      goto LABEL_278;
                    LODWORD(v249) = 8;
LABEL_279:
                    LODWORD(v246) = v246 + 4;
                    goto LABEL_280;
                  }
LABEL_275:
                  LODWORD(v249) = 6;
                  goto LABEL_279;
                }
                if ( v247 != 0x8006000000000LL )
                {
                  if ( v247 == 0x9000600090000LL )
                  {
                    LODWORD(v249) = 9;
                    goto LABEL_279;
                  }
                  if ( v247 != 0x9000900060000LL )
                    goto LABEL_278;
                  goto LABEL_271;
                }
LABEL_256:
                LODWORD(v249) = 4;
                goto LABEL_279;
              }
              if ( v247 <= 0xA0060000A0009LL )
              {
                if ( v247 == 0xA000A000A0006LL )
                  goto LABEL_263;
                if ( v247 == 0xA000A000A0060LL )
                  goto LABEL_279;
                if ( v247 != 0xA000A0060000ALL )
                  goto LABEL_278;
                goto LABEL_260;
              }
              if ( v247 > 0x6000090008FFFFLL )
              {
                if ( v247 == 0x60000900090000LL )
                {
                  LODWORD(v249) = 10;
                  goto LABEL_279;
                }
                v254 = 0xA000A000ALL;
              }
              else
              {
                if ( v247 == 0xA0060000A000ALL )
                  goto LABEL_256;
                v254 = 0x800000000LL;
              }
              if ( v247 != (v254 & 0xFFFFFFFFFFFFLL | 0x60000000000000LL) )
                goto LABEL_278;
              goto LABEL_275;
            }
          }
          if ( (unsigned int)v246 > 0x28 )
          {
LABEL_281:
            v258 = 0;
            LODWORD(v246) = 16;
            v257 = 1;
            goto LABEL_297;
          }
LABEL_280:
          v257 = 0;
          v258 = 1;
          switch ( (int)v246 )
          {
            case 0:
              break;
            case 1:
              v257 = 0;
              LODWORD(v246) = 1;
              break;
            case 2:
              v257 = 0;
              LODWORD(v246) = 8;
              break;
            case 3:
              v257 = 0;
              LODWORD(v246) = 2;
              break;
            case 4:
              v257 = 0;
              LODWORD(v246) = 9;
              break;
            case 5:
              v257 = 0;
              LODWORD(v246) = 3;
              break;
            case 6:
              v257 = 0;
              LODWORD(v246) = 4;
              break;
            case 7:
              v257 = 0;
              LODWORD(v246) = 10;
              break;
            case 8:
              v257 = 0;
              LODWORD(v246) = 5;
              break;
            case 9:
              v257 = 0;
              LODWORD(v246) = 6;
              break;
            case 10:
              v257 = 0;
              LODWORD(v246) = 14;
              break;
            case 11:
              v257 = 0;
              LODWORD(v246) = 7;
              break;
            case 18:
              v257 = 0;
              LODWORD(v246) = 11;
              break;
            case 23:
              v257 = 0;
              LODWORD(v246) = 12;
              break;
            case 28:
              v257 = 0;
              LODWORD(v246) = 13;
              break;
            case 40:
              v257 = 0;
              LODWORD(v246) = 15;
              break;
            default:
              goto LABEL_281;
          }
LABEL_297:
          v259 = *(_QWORD *)v26;
          if ( v243 && (*(_QWORD *)v26 & 0xF000000LL) == 0x4000000 && (_DWORD)v249 != 31 )
          {
            *(_WORD *)(v243 + 60) |= (unsigned __int16)((_WORD)v249 << 8) | 0x4000;
            v259 = *(_QWORD *)v26;
          }
          if ( v243 && (v259 & 0xF000000) == 0x6000000 )
          {
            if ( (v257 & 1) == 0 )
            {
              v260 = *(_DWORD *)(v243 + 84) | v246;
              *(_DWORD *)(v243 + 76) |= 0x400000u;
              *(_DWORD *)(v243 + 84) = v260;
            }
            if ( (_DWORD)v249 != 31 )
            {
              v261 = *(_DWORD *)(v243 + 84) | (32 * v249);
              *(_DWORD *)(v243 + 76) |= 0x800000u;
              *(_DWORD *)(v243 + 84) = v261;
            }
          }
          if ( v243 && (*(_QWORD *)v26 & 0xF000000LL) == 0x4000000 )
          {
            v262 = *(_QWORD *)(a2 + 92);
            if ( (v262 & 0x7800000000000LL) == 0x800000000000LL )
            {
              *(_QWORD *)(a2 + 92) = v262 | 8;
              v263 = *(_QWORD *)v243;
              v264 = *(_WORD *)(v243 + 62);
              v265 = (*(_QWORD *)v243 & 0xF) << 8;
              v266 = *(_QWORD *)v243 >> 28;
              *(_WORD *)(v243 + 58) |= 0xA0u;
              v267 = v265 | v264;
              LOWORD(v265) = *(_WORD *)(v243 + 64);
              *(_WORD *)(v243 + 62) = v267;
              v268 = *(_DWORD *)(a2 + 92);
              LOWORD(v266) = v265 | v266 & 0xFFF0;
              LOWORD(v265) = *(_WORD *)(v243 + 68);
              *(_WORD *)(v243 + 64) = v266;
              *(_WORD *)(v243 + 68) = v265 | ((unsigned int)v263 >> 4) & 7;
              *(_WORD *)(v243 + 62) = (v268 >> 11) & 0x2000 | v267;
              v262 = *(_QWORD *)(a2 + 92);
            }
            if ( (v262 & 0x7800000000000LL) == 0x1000000000000LL )
            {
              if ( (v262 & 0x200000000000000LL) == 0 )
                *(_QWORD *)(a2 + 92) = v262 | 8;
              v269 = *(_QWORD *)v243;
              v270 = *(_WORD *)(v243 + 62);
              v271 = *(_WORD *)(v243 + 64);
              v272 = *(_QWORD *)v243 >> 33;
              v273 = *(_QWORD *)v243 >> 31;
              v274 = *(_QWORD *)v243 >> 28;
              v275 = (*(_QWORD *)v243 & 0xF) << 8;
              *(_WORD *)(v243 + 58) |= 0xE0u;
              v276 = v273 & 0x2000 | v270;
              LOWORD(v273) = v274 & 0xFFF0 | v271;
              LOWORD(v274) = *(_WORD *)(v243 + 66);
              v277 = v276 | v272 & 0x1000 | v275;
              v278 = *(_WORD *)(v243 + 68);
              *(_WORD *)(v243 + 62) = v277;
              *(_WORD *)(v243 + 64) = v273;
              *(_WORD *)(v243 + 66) = v274 | v272 & 0x4000;
              *(_WORD *)(v243 + 68) = v278 | ((unsigned int)v269 >> 4) & 7;
              *(_WORD *)(v243 + 46) = *(_WORD *)(a2 + 168);
              *(_WORD *)(v243 + 48) = *(_WORD *)(a2 + 170);
            }
          }
          if ( v243 )
            v279 = (_DWORD)v249 == 31;
          else
            v279 = 1;
          if ( v279 )
            v258 = 0;
          if ( v258 == 1 )
          {
            v280 = *(_QWORD *)v243 & 0xFFFFFFFFC03F80FFLL | (unsigned int)(((_DWORD)v249 << 8) | ((_DWORD)v246 << 22));
            *(_QWORD *)v243 = v280;
            v281 = 32896;
            switch ( (int)v246 )
            {
              case 0:
              case 15:
                break;
              case 1:
                v281 = 65664;
                break;
              case 2:
                v281 = 131200;
                break;
              case 3:
                v281 = 295040;
                break;
              case 4:
                v281 = 589952;
                break;
              case 5:
                v281 = 1212544;
                break;
              case 6:
                v282 = 2359296;
                goto LABEL_331;
              case 7:
                v281 = 655488;
                break;
              case 8:
                v281 = 98432;
                break;
              case 9:
                v281 = 163968;
                break;
              case 10:
                v282 = 819200;
                goto LABEL_331;
              case 11:
                v282 = 1736704;
                goto LABEL_331;
              case 12:
                v281 = 2097280;
                break;
              case 13:
                v281 = 3014784;
                break;
              case 14:
                v282 = 3571712;
LABEL_331:
                v281 = v282 | 0x10080;
                break;
              default:
                v283 = jiffies;
                if ( hal_rx_ul_ofdma_ru_size_to_width___last_ticks - jiffies + 125 < 0 )
                {
                  qdf_trace_msg(
                    0x46u,
                    2u,
                    "%s: RU size(%d) to width convert err",
                    a4,
                    a5,
                    a6,
                    a7,
                    a8,
                    a9,
                    a10,
                    a11,
                    "hal_rx_ul_ofdma_ru_size_to_width",
                    (unsigned int)v246);
                  hal_rx_ul_ofdma_ru_size_to_width___last_ticks = v283;
                  v280 = *(_QWORD *)v243;
                }
                v281 = 128;
                break;
            }
            *(_QWORD *)v243 = v281 | v280 & 0xFFFFFFFFFFC07F7FLL;
            return 0;
          }
          break;
        case 0x139u:
          *(_DWORD *)(a2 + 100) = a1[3] & 0xFFFFFF | (*(unsigned __int8 *)(a2 + 103) << 24);
          v159 = a1[2];
          *(_QWORD *)(a2 + 72) = v159;
          *(_QWORD *)(a2 + 72) = a1[1] | (unsigned __int64)(v159 << 32);
          *(_WORD *)(a2 + 154) = a1[10];
          v160 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v13 + 664) + 864LL);
          if ( !v160 )
            return 0;
          goto LABEL_124;
        default:
          if ( v23 )
            goto LABEL_29;
          return v24;
      }
      return 0;
    }
    if ( (((unsigned int)v22 >> 1) & 0x1FF) <= 0x1C7 )
    {
      if ( v23 == 427 )
      {
        v160 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(v13 + 664) + 872LL);
        if ( v160 )
        {
LABEL_124:
          if ( *((_DWORD *)v160 - 1) != -72220 )
            __break(0x8228u);
          v160(v26);
          return 0;
        }
        return 0;
      }
      if ( v23 == 442 )
        return 9;
    }
    else
    {
      switch ( v23 )
      {
        case 0x1C8u:
          return 0;
        case 0x1D6u:
          v161 = *(_QWORD *)(a2 + 92) | 0x4000000000000010LL;
          v162 = *(_DWORD *)(a2 + 312) | 0x1F;
          *(_QWORD *)(a2 + 92) = v161;
          *(_DWORD *)(a2 + 312) = v162;
          v163 = ((a1[1] & 7) << 12) | v162;
          *(_DWORD *)(a2 + 312) = v163;
          v164 = (a1[1] << 12) & 0x38000 | v163;
          *(_DWORD *)(a2 + 312) = v164;
          v165 = (a1[1] << 12) & 0x40000 | v164;
          *(_DWORD *)(a2 + 312) = v165;
          v166 = (a1[1] << 12) & 0x1F80000 | v165;
          *(_DWORD *)(a2 + 312) = v166;
          *(_DWORD *)(a2 + 312) = v166 | (a1[1] >> 13 << 25);
          v167 = *(_WORD *)(a2 + 64) & 0xFFFE | (*((unsigned __int16 *)a1 + 2) >> 6) & 1;
          *(_WORD *)(a2 + 64) = v167;
          v168 = v167 & 0xFFFFFFF1 | (2 * ((*((unsigned __int16 *)a1 + 2) >> 3) & 7));
          *(_WORD *)(a2 + 64) = v168;
          *(_QWORD *)(a2 + 92) = v161 & 0xFFFFFFFFFFF0FFFFLL | ((((unsigned __int64)a1[1] >> 3) & 7) << 16);
          v169 = *(_DWORD *)(a2 + 320);
          if ( (*(_QWORD *)(a1 + 1) & 0x300000040LL) == 0x40 )
          {
            v170 = *(_DWORD *)(a2 + 316);
            *(_DWORD *)(a2 + 320) = v169 | 0x37D;
            *(_DWORD *)(a2 + 316) = v170 | 0x3F;
            v171 = v170 | 0x13F | ((a1[2] & 3) << 6);
            *(_DWORD *)(a2 + 316) = v171;
            v172 = (a1[2] << 6) & 0x1E00 | v171;
            *(_DWORD *)(a2 + 316) = v172;
            v173 = v172 | (a1[2] << 6) & 0x1E000 | 0x3E0000;
            *(_DWORD *)(a2 + 316) = v173;
            v174 = (a1[2] << 6) & 0x3C00000 | v173;
            *(_DWORD *)(a2 + 316) = v174;
            *(_DWORD *)(a2 + 316) = v174 | (a1[2] >> 20 << 26);
            v175 = v168 & 0xFFCF | (16 * (a1[2] & 3));
          }
          else
          {
            v182 = *(_DWORD *)(a2 + 316);
            *(_DWORD *)(a2 + 320) = v169 | 0x3FF;
            *(_DWORD *)(a2 + 316) = v182 | 0x3F;
            v183 = ((a1[2] & 3) << 6) | v182;
            *(_DWORD *)(a2 + 316) = v183 | 0x13F;
            v184 = v183 | (a1[2] << 6) & 0x3E00 | 0x413F;
            *(_DWORD *)(a2 + 316) = v184;
            v185 = (a1[2] << 6) & 0x18000 | v184;
            *(_DWORD *)(a2 + 316) = v185;
            v186 = (a1[2] << 6) & 0x3E0000 | v185;
            *(_DWORD *)(a2 + 316) = v186;
            v187 = (a1[2] << 6) & 0x3C00000 | v186;
            *(_DWORD *)(a2 + 316) = v187;
            *(_DWORD *)(a2 + 316) = v187 | (a1[2] >> 20 << 26);
            v188 = v168 & 0xFFFFFFCF | (16 * (a1[2] & 3));
            *(_WORD *)(a2 + 64) = v188;
            v189 = v188 & 0xFFFFFF3F | (((*((unsigned __int16 *)a1 + 4) >> 9) & 3) << 6);
            *(_WORD *)(a2 + 64) = v189;
            v175 = v189 & 0xE0FF | ((unsigned __int8)HIBYTE(*((_WORD *)a1 + 4)) >> 3 << 8);
          }
          *(_WORD *)(a2 + 64) = v175;
          return 0;
        case 0x1DDu:
          *(_BYTE *)(v11 + 1535) = 1;
          return 11;
      }
    }
LABEL_29:
    v28 = "%s: unhandled tlv tag %d";
    v29 = 8;
LABEL_104:
    qdf_trace_msg(0x46u, v29, v28, a4, a5, a6, a7, a8, a9, a10, a11, "hal_rx_status_get_tlv_info_generic_be");
    return 0;
  }
  v16 = *(unsigned __int16 *)(a2 + 14262);
  v17 = (*a1 >> 10) & 0xFFF;
  if ( v17 > 192 - (int)v16 )
  {
LABEL_13:
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Length of TLV exceeds max aggregation length",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "hal_rx_status_aggr_tlv");
    return 0;
  }
  if ( (unsigned int)v16 < 0xC1 )
  {
    v18 = (void *)(a2 + v16 + 14268);
LABEL_18:
    qdf_mem_copy(v18, a1 + 1, v17);
    v24 = 0;
    *(_WORD *)(v11 + 1974) += v17;
    return v24;
  }
LABEL_341:
  __break(0x5512u);
  return hal_rx_priv_info_set_in_tlv_peach();
}
