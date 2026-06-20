void *__fastcall sme_update_tgt_he_cap(_QWORD *a1, __int64 a2, __int64 a3)
{
  _QWORD *v6; // x22
  char v7; // w25
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x8
  unsigned __int64 v17; // x9
  unsigned __int64 *v18; // x26
  __int64 v19; // x21
  unsigned __int64 v20; // x10
  unsigned __int64 v21; // x9
  unsigned __int64 v22; // x9
  unsigned __int64 *v23; // x14
  int v24; // w15
  unsigned int v25; // w11
  int v26; // w17
  int v27; // w0
  __int64 v28; // x12
  unsigned int v29; // w10
  unsigned int v30; // w13
  int v31; // w15
  int v32; // w2
  int v33; // w6
  int v34; // w5
  unsigned int v35; // w11
  unsigned __int64 v36; // x16
  unsigned int v37; // w10
  unsigned int v38; // w9
  unsigned __int64 v39; // x16
  int v40; // w17
  char v41; // w1
  char v42; // w3
  unsigned int v43; // w12
  int v44; // w0
  unsigned int v45; // w1
  int v46; // w7
  int v47; // w20
  __int16 v48; // w27
  int v49; // w3
  int v50; // w21
  int v51; // w4
  unsigned int v52; // w16
  int v53; // w19
  int v54; // w14
  __int16 v55; // w1
  int v56; // w22
  int v57; // w15
  int v58; // w7
  int v59; // w23
  __int16 v60; // w26
  int v61; // w25
  __int16 v62; // w17
  int v63; // w0
  int v64; // w1
  int v65; // w2
  int v66; // w28
  int v67; // w3
  int v68; // w1
  int v69; // w8
  int v70; // w5
  int v71; // w3
  int v72; // w4
  int v73; // w7
  int v74; // w20
  int v75; // w6
  int v76; // w21
  int v77; // w8
  int v78; // w5
  int v79; // w19
  int v80; // w20
  int v81; // w23
  int v82; // w7
  int v83; // w4
  int v84; // w24
  int v85; // w21
  int v86; // w8
  int v87; // w20
  int v88; // w23
  int v89; // w1
  int v90; // w13
  int v91; // w20
  __int64 v92; // x30
  __int16 v93; // w12
  unsigned int v94; // w13
  int v95; // w16
  unsigned int v96; // w14
  int v97; // w6
  int v98; // w12
  int v99; // w2
  int v100; // w3
  int v101; // w1
  int v102; // w0
  int v103; // w16
  int v104; // w8
  int v105; // w17
  int v106; // w1
  int v107; // w2
  int v108; // w3
  int v109; // w7
  int v110; // w4
  int v111; // w8
  int v112; // w17
  int v113; // w1
  int v114; // w8
  int v115; // w2
  int v116; // w4
  int v117; // w5
  int v118; // w6
  int v119; // w22
  int v120; // w8
  int v121; // w19
  int v122; // w4
  int v123; // w7
  int v124; // w5
  int v125; // w6
  int v126; // w20
  int v127; // w3
  int v128; // w8
  int v129; // w2
  int v130; // w20
  int v131; // w7
  int v132; // w21
  int v133; // w6
  int v134; // w3
  int v135; // w22
  int v136; // w23
  int v137; // w8
  int v138; // w7
  int v139; // w21
  int v140; // w5
  int v141; // w6
  int v142; // w11
  unsigned int v143; // w19
  int v144; // w20
  unsigned int v145; // w12
  int v146; // w15
  unsigned int v147; // w13
  int v148; // w5
  int v149; // w11
  int v150; // w1
  int v151; // w2
  int v152; // w0
  int v153; // w17
  int v154; // w15
  int v155; // w8
  int v156; // w16
  int v157; // w0
  int v158; // w1
  int v159; // w2
  int v160; // w6
  int v161; // w3
  int v162; // w8
  int v163; // w16
  int v164; // w0
  int v165; // w8
  int v166; // w1
  int v167; // w3
  int v168; // w4
  int v169; // w5
  int v170; // w21
  int v171; // w8
  int v172; // w7
  int v173; // w3
  int v174; // w6
  int v175; // w4
  int v176; // w5
  int v177; // w19
  int v178; // w2
  int v179; // w8
  int v180; // w1
  int v181; // w19
  int v182; // w6
  int v183; // w20
  int v184; // w5
  int v185; // w2
  int v186; // w21
  int v187; // w22
  int v188; // w8
  int v189; // w6
  int v190; // w20
  int v191; // w4
  int v192; // w5
  int v193; // w10
  unsigned int v194; // w7
  int v195; // w19
  unsigned int v196; // w11
  int v197; // w14
  int v198; // w8
  unsigned int v199; // w12
  int v200; // w4
  int v201; // w10
  int v202; // w0
  int v203; // w1
  int v204; // w13
  int v205; // w16
  int v206; // w15
  int v207; // w14
  int v208; // w8
  int v209; // w17
  int v210; // w16
  int v211; // w0
  int v212; // w1
  int v213; // w16
  int v214; // w2
  int v215; // w3
  int v216; // w4
  int v217; // w17
  int v218; // w8
  int v219; // w6
  int v220; // w2
  int v221; // w5
  int v222; // w3
  int v223; // w4
  int v224; // w7
  int v225; // w20
  int v226; // w1
  int v227; // w8
  int v228; // w0
  int v229; // w7
  int v230; // w5
  int v231; // w19
  int v232; // w4
  int v233; // w1
  int v234; // w20
  int v235; // w21
  int v236; // w8
  int v237; // w5
  int v238; // w19
  int v239; // w3
  int v240; // w4
  int v241; // w9
  unsigned int v242; // w6
  int v243; // w7
  __int64 v244; // x9
  unsigned int v245; // w8
  unsigned int v246; // w12
  unsigned __int64 v247; // x9
  char v248; // w8
  unsigned __int64 v249; // x8
  __int64 v250; // x9
  unsigned int v251; // w12
  unsigned __int64 v252; // x9
  char v253; // w8
  __int64 v255; // [xsp+8h] [xbp-18h]
  _QWORD *v256; // [xsp+10h] [xbp-10h]
  _QWORD *v257; // [xsp+18h] [xbp-8h]

  v6 = a1 + 2560;
  v7 = *(_BYTE *)(a1[1] + 2871LL);
  qdf_mem_copy((char *)a1 + 21788, (const void *)(a2 + 288), 0x3Cu);
  qdf_mem_copy(a1 + 2731, (const void *)(a2 + 348), 0x3Cu);
  v16 = a1[1];
  if ( (*(_BYTE *)(v16 + 1316) & 0x1E) == 0 )
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: feature is disabled via INI, FW caps 2G:%d, 5G:%d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "sme_update_tgt_he_cap",
      (*(_QWORD *)((char *)v6 + 1309) >> 57) & 0xFLL,
      (*(_QWORD *)((char *)v6 + 1369) >> 57) & 0xFLL);
    v16 = a1[1];
    v17 = *(_QWORD *)((char *)v6 + 1369) & 0xE1FFFFFFFFFFFFFFLL;
    *(_QWORD *)((char *)v6 + 1309) &= 0xE1FFFFFFFFFFFFFFLL;
    *(_QWORD *)((char *)v6 + 1369) = v17;
  }
  v18 = (_QWORD *)((char *)v6 + 1317);
  v19 = a2 + 297;
  v20 = *(_QWORD *)((char *)v6 + 1317);
  v256 = a1;
  if ( *(_BYTE *)(v16 + 1485) )
  {
    v21 = *(_QWORD *)((char *)v6 + 1377);
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: feature is disabled via INI, FW caps 2G:%d, 5G:%d",
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      "sme_update_tgt_he_cap",
      ((unsigned int)v20 >> 7) & 3,
      (*(_DWORD *)((char *)v6 + 1377) >> 7) & 3);
    v20 = *v18 & 0xFFFFFFFFFFFFFE7FLL;
    v16 = a1[1];
    v21 = *(_QWORD *)((char *)v6 + 1377) & 0xFFFFFFFFFFFFFE7FLL;
    *v18 = v20;
    *(_QWORD *)((char *)v6 + 1377) = v21;
  }
  v22 = v21 & 0xFFFFFFFFFFC7FFFFLL;
  v23 = (_QWORD *)((char *)v6 + 1377);
  v24 = *((unsigned __int16 *)v6 + 664);
  v25 = (*(_DWORD *)v19 >> 19) & 7;
  v26 = *((unsigned __int16 *)v6 + 694);
  v27 = *((unsigned __int16 *)v6 + 695);
  v257 = v6;
  v255 = v16;
  if ( v25 >= ((*(_DWORD *)(a3 + 9) >> 19) & 7u) )
    v25 = (*(_DWORD *)(a3 + 9) >> 19) & 7;
  *(_QWORD *)((char *)v6 + 1317) = v20 & 0xFFFFFFFFF8C7FFFFLL | (v25 << 19);
  v28 = -4LL << (2 * v7);
  v29 = (*(_DWORD *)(v19 + 60) >> 19) & 7;
  v30 = v24 | v28;
  v31 = (unsigned __int16)(v24 | v28) >> 1;
  v32 = (unsigned __int16)v30 >> 3;
  if ( v29 >= ((*(_DWORD *)(a3 + 9) >> 19) & 7u) )
    v29 = (*(_DWORD *)(a3 + 9) >> 19) & 7;
  v33 = (unsigned __int16)v30 >> 5;
  v34 = (unsigned __int16)v30 >> 7;
  v35 = *((unsigned __int16 *)v6 + 665) | (unsigned int)v28;
  v36 = v22 | (v29 << 19);
  v37 = v26 | v28;
  v38 = v27 | v28;
  *v23 = v36;
  v39 = v36 & 0xFFFFFFFFF8FFFFFFLL;
  v40 = v30 & 1;
  v41 = *(_BYTE *)(v19 + 63);
  v42 = *(_BYTE *)(a3 + 12);
  *((_WORD *)v6 + 664) = v30;
  *((_WORD *)v6 + 665) = v35;
  v43 = (unsigned __int16)v30;
  v44 = (v30 >> 2) & 1;
  v45 = v41 & 7;
  *((_WORD *)v6 + 694) = v37;
  *((_WORD *)v6 + 695) = v38;
  v46 = ((unsigned __int16)v30 >> 1) & 1;
  if ( v45 >= (v42 & 7u) )
    v45 = v42 & 7;
  v47 = ((unsigned __int16)v30 >> 3) & 1;
  v48 = v46 ^ v40;
  v49 = (v30 >> 4) & 1;
  v50 = ((unsigned __int16)v30 >> 5) & 1;
  v51 = (v30 >> 6) & 1;
  *v23 = v39 | (v45 << 24);
  v52 = *(unsigned __int16 *)(v16 + 1328);
  v53 = (v52 >> 2) & 1;
  v54 = (v52 >> 1) & v52 & 1 | v31 & v40;
  v55 = ((*(_WORD *)(v16 + 1328) >> 1) ^ *(_WORD *)(v16 + 1328)) & ~(_WORD)v31;
  v56 = v46 & ~(v52 & 1 | v40) & (v52 >> 1);
  v57 = v53 & (v52 >> 3) | v44 & v32;
  v58 = (v52 >> 4) & 1;
  v59 = (v47 ^ v44) & ~(v52 >> 3) & (v52 >> 2);
  LOWORD(v53) = v47 & ~(v53 | v44);
  v60 = v58 & (*(_WORD *)(v16 + 1328) >> 5) | v49 & v33;
  v61 = (v50 ^ v49) & ~(v52 >> 5) & (v52 >> 4);
  v62 = v55 & v40;
  v63 = ((v52 >> 3) ^ (v52 >> 2)) & ~v32 & v44;
  v64 = ((v52 >> 5) ^ (v52 >> 4)) & ~v33 & v49;
  v65 = v50 & ~(v58 | v49) & (v52 >> 5);
  v66 = ((unsigned __int16)v30 >> 7) & 1;
  v67 = (v52 >> 6) & 1;
  LOWORD(v63) = v59 | v63 | (2 * (v53 & (*(_WORD *)(v16 + 1328) >> 3) | v57));
  LOWORD(v65) = v61 | v64 | (2 * (v65 | v60)) | v60;
  v68 = v67 & (v52 >> 7) | v51 & v34;
  v69 = ((v52 >> 7) ^ (v52 >> 6)) & ~v34 & v51;
  v70 = (v66 ^ v51) & ~(v52 >> 7);
  v71 = v67 | v51;
  v72 = (unsigned __int16)v30 >> 9;
  v73 = (v30 >> 8) & 1;
  v74 = (v52 >> 8) & 1;
  v75 = ((unsigned __int16)v30 >> 9) & 1;
  v76 = v74 & (v52 >> 9) | v73 & v72;
  v77 = v70 & (v52 >> 6) | v69 | (2 * (v66 & ~v71 & (v52 >> 7) | v68));
  v78 = v75 & ~(v74 | v73) & (v52 >> 9) | v76;
  v79 = (unsigned __int16)v30 >> 11;
  v80 = (v30 >> 10) & 1;
  v81 = (v52 >> 10) & 1;
  LOWORD(v71) = (v75 ^ v73) & ~(unsigned __int16)(v52 >> 9) & (v52 >> 8)
              | ((v52 >> 9) ^ (v52 >> 8)) & ~(_WORD)v72 & v73
              | (2 * v78);
  LOWORD(v78) = v77 | v68;
  v82 = ((unsigned __int16)v30 >> 11) & 1;
  LOWORD(v71) = v71 | v76;
  v83 = v81 & (v52 >> 11) | v80 & v79;
  v84 = (v30 >> 15) & 1;
  v85 = (unsigned __int16)v30 >> 14;
  v86 = (v82 ^ v80) & ~(v52 >> 11) & (v52 >> 10);
  LOWORD(v68) = ((v52 >> 11) ^ (v52 >> 10)) & ~(_WORD)v79 & v80;
  v87 = v81 | v80;
  v88 = (v52 >> 14) & (v52 >> 15) | v85 & v84;
  LOWORD(v86) = v86 | v68;
  v89 = v82 & ~v87 & (v52 >> 11);
  LOWORD(v82) = (unsigned __int16)v30 >> 13;
  v90 = (v30 >> 12) & 1;
  v91 = (v52 >> 12) & 1;
  LOWORD(v75) = v91 & (v52 >> 13) | v90 & v82;
  v92 = v255;
  LOWORD(v86) = ((((v43 >> 14)
                 & 1
                 ^ (unsigned __int16)v84)
                & (unsigned __int16)~(unsigned __int16)(v52 >> 15)
                & (unsigned __int16)(v52 >> 14)
                | ((v52 >> 14)
                 & 1
                 ^ (unsigned __int16)(v52 >> 15))
                & (unsigned __int16)~(_WORD)v84
                & (unsigned __int16)v85
                | (unsigned __int16)(2 * (v88 | v84 & ~((v52 >> 14) | v85) & (v52 >> 15)))
                | (unsigned __int16)v88) << 14)
              | (16 * v65)
              | ((_WORD)v78 << 6)
              | ((_WORD)v71 << 8)
              | (((unsigned __int16)(v86 | (2 * (v89 | v83))) | (unsigned __int16)v83) << 10)
              | ((((v43 >> 13)
                 & 1
                 ^ (unsigned __int16)v90)
                & (unsigned __int16)~(unsigned __int16)(v52 >> 13)
                & (unsigned __int16)(v52 >> 12)
                | ((v52 >> 13) ^ (unsigned __int16)(v52 >> 12)) & (unsigned __int16)~(_WORD)v82 & (unsigned __int16)v90
                | (unsigned __int16)(2 * ((v43 >> 13) & 1 & ~(v91 | v90) & (v52 >> 13) | v75))
                | (unsigned __int16)v75) << 12);
  v93 = v48 & ~(unsigned __int16)(v52 >> 1) & v52 | v62 | (2 * (v56 | v54)) | (4 * (v63 | v57)) | v54;
  v94 = (unsigned __int16)v35;
  v95 = ((unsigned __int16)v35 >> 1) & 1;
  *((_WORD *)v257 + 664) = v86 | v93;
  v96 = *(unsigned __int16 *)(v255 + 1330);
  v97 = (v96 >> 2) & 1;
  v98 = (v96 >> 1) & v96 & 1 | ((unsigned __int16)v35 >> 1) & v35 & 1;
  v99 = (unsigned __int16)v35 >> 3;
  v100 = (v35 >> 2) & 1;
  LOWORD(v57) = (v95 ^ v35 & 1) & ~(*(_WORD *)(v92 + 1330) >> 1) & v96
              | ((*(_WORD *)(v92 + 1330) >> 1) ^ *(_WORD *)(v92 + 1330)) & ~((unsigned __int16)v35 >> 1) & v35 & 1;
  v101 = ((unsigned __int16)v35 >> 3) & 1;
  v102 = v95 & ~(v96 & 1 | v35 & 1) & (v96 >> 1);
  v103 = v97 & (v96 >> 3) | v100 & v99;
  v104 = ((v96 >> 3) ^ (v96 >> 2)) & ~v99 & v100;
  v105 = (v101 ^ v100) & ~(v96 >> 3);
  v106 = v101 & ~(v97 | v100);
  v107 = (unsigned __int16)v35 >> 5;
  v108 = (v35 >> 4) & 1;
  v109 = (v96 >> 4) & 1;
  v110 = ((unsigned __int16)v35 >> 5) & 1;
  v111 = v105 & (v96 >> 2) | v104;
  v112 = v106 & (v96 >> 3) | v103;
  v113 = v109 & (v96 >> 5) | v108 & v107;
  LOWORD(v112) = v111 | (2 * v112);
  v114 = (v110 ^ v108) & ~(v96 >> 5) & (v96 >> 4) | ((v96 >> 5) ^ (v96 >> 4)) & ~v107 & v108;
  v115 = v110 & ~(v109 | v108) & (v96 >> 5) | v113;
  v116 = (unsigned __int16)v35 >> 7;
  v117 = (v35 >> 6) & 1;
  v118 = (v96 >> 6) & 1;
  v119 = (v96 >> 8) & 1;
  LOWORD(v113) = v114 | (2 * v115) | v113;
  v120 = ((unsigned __int16)v35 >> 7) & 1;
  v121 = v118 & (v96 >> 7) | v117 & v116;
  v122 = ((v96 >> 7) ^ (v96 >> 6)) & ~v116 & v117;
  v123 = v120 ^ v117;
  v124 = v118 | v117;
  v125 = (unsigned __int16)v35 >> 9;
  v126 = (v35 >> 8) & 1;
  v127 = v119 & (v96 >> 9) | v126 & v125;
  v128 = v123 & ~(v96 >> 7) & (v96 >> 6) | v122 | (2 * (v120 & ~v124 & (v96 >> 7) | v121));
  v129 = (((unsigned __int16)v35 >> 9) & 1 ^ v126) & ~(v96 >> 9) & (v96 >> 8)
       | ((v96 >> 9) ^ (v96 >> 8)) & ~v125 & v126
       | (2 * (((unsigned __int16)v35 >> 9) & 1 & ~(v119 | v126) & (v96 >> 9) | v127));
  v130 = (unsigned __int16)v35 >> 11;
  v131 = (v35 >> 10) & 1;
  v132 = (v96 >> 10) & 1;
  LOWORD(v122) = v128 | v121;
  v133 = ((unsigned __int16)v35 >> 11) & 1;
  LOWORD(v129) = v129 | v127;
  v134 = v132 & (v96 >> 11) | v131 & v130;
  v135 = (unsigned __int16)v35 >> 14;
  v136 = (v35 >> 15) & 1;
  v137 = (v133 ^ v131) & ~(v96 >> 11) & (v96 >> 10);
  LOWORD(v121) = ((*(_WORD *)(v92 + 1330) >> 11) ^ (*(_WORD *)(v92 + 1330) >> 10)) & ~(_WORD)v130 & v131;
  v138 = v132 | v131;
  v139 = (v96 >> 14) & (v96 >> 15) | v135 & v136;
  v140 = v133 & ~v138 & (v96 >> 11);
  v141 = (((unsigned __int16)v35 >> 14) & 1 ^ v136) & ~(v96 >> 15) & (v96 >> 14)
       | ((v96 >> 14) & 1 ^ (v96 >> 15)) & ~v136 & v135
       | (2 * (v139 | v136 & ~((v96 >> 14) | v135) & (v96 >> 15)));
  LOWORD(v137) = v137 | v121;
  LOWORD(v138) = (unsigned __int16)v35 >> 13;
  v142 = (v35 >> 12) & 1;
  v143 = v96 >> 13;
  v144 = (v96 >> 12) & 1;
  LOWORD(v137) = (((unsigned __int16)v141 | (unsigned __int16)v139) << 14)
               | (16 * v113)
               | ((_WORD)v122 << 6)
               | ((_WORD)v129 << 8)
               | (((unsigned __int16)(v137 | (2 * (v140 | v134))) | (unsigned __int16)v134) << 10)
               | ((((v94 >> 13)
                  & 1
                  ^ (unsigned __int16)v142)
                 & (unsigned __int16)~(_WORD)v143
                 & (*(_WORD *)(v92 + 1330) >> 12)
                 | (v143 ^ (*(_WORD *)(v92 + 1330) >> 12)) & (unsigned __int16)~(_WORD)v138 & (unsigned __int16)v142
                 | (unsigned __int16)(2
                                    * (((v94 & 0x2000) != 0) & (unsigned __int8)~(v144 | v142) & (unsigned __int8)v143
                                     | v144 & v143
                                     | v142 & v138))
                 | (unsigned __int16)(v144 & v143 | v142 & v138)) << 12);
  LOWORD(v142) = v57 | (2 * (v102 | v98)) | (4 * (v112 | v103)) | v98;
  v145 = (unsigned __int16)v37;
  v146 = ((unsigned __int16)v37 >> 1) & 1;
  *((_WORD *)v257 + 665) = v137 | v142;
  v147 = *(unsigned __int16 *)(v255 + 1328);
  v148 = (v147 >> 2) & 1;
  v149 = (v147 >> 1) & v147 & 1 | ((unsigned __int16)v37 >> 1) & v37 & 1;
  v150 = (unsigned __int16)v37 >> 3;
  v151 = (v37 >> 2) & 1;
  LOWORD(v96) = (v146 ^ v37 & 1) & ~(*(_WORD *)(v92 + 1328) >> 1) & v147
              | ((*(_WORD *)(v92 + 1328) >> 1) ^ *(_WORD *)(v92 + 1328)) & ~((unsigned __int16)v37 >> 1) & v37 & 1;
  v152 = ((unsigned __int16)v37 >> 3) & 1;
  v153 = v146 & ~(v147 & 1 | v37 & 1) & (v147 >> 1);
  v154 = v148 & (v147 >> 3) | v151 & v150;
  v155 = ((v147 >> 3) ^ (v147 >> 2)) & ~v150 & v151;
  v156 = (v152 ^ v151) & ~(v147 >> 3);
  v157 = v152 & ~(v148 | v151);
  v158 = (unsigned __int16)v37 >> 5;
  v159 = (v37 >> 4) & 1;
  v160 = (v147 >> 4) & 1;
  v161 = ((unsigned __int16)v37 >> 5) & 1;
  v162 = v156 & (v147 >> 2) | v155;
  v163 = v157 & (v147 >> 3) | v154;
  v164 = v160 & (v147 >> 5) | v159 & v158;
  LOWORD(v163) = v162 | (2 * v163);
  v165 = (v161 ^ v159) & ~(v147 >> 5) & (v147 >> 4) | ((v147 >> 5) ^ (v147 >> 4)) & ~v158 & v159;
  v166 = v161 & ~(v160 | v159) & (v147 >> 5) | v164;
  v167 = (unsigned __int16)v37 >> 7;
  v168 = (v37 >> 6) & 1;
  v169 = (v147 >> 6) & 1;
  v170 = (v147 >> 8) & 1;
  LOWORD(v164) = v165 | (2 * v166) | v164;
  v171 = ((unsigned __int16)v37 >> 7) & 1;
  v172 = v169 & (v147 >> 7) | v168 & v167;
  v173 = ((v147 >> 7) ^ (v147 >> 6)) & ~v167 & v168;
  v174 = v171 ^ v168;
  v175 = v169 | v168;
  v176 = (unsigned __int16)v37 >> 9;
  v177 = (v37 >> 8) & 1;
  v178 = v170 & (v147 >> 9) | v177 & v176;
  v179 = v174 & ~(v147 >> 7) & (v147 >> 6) | v173 | (2 * (v171 & ~v175 & (v147 >> 7) | v172));
  v180 = (((unsigned __int16)v37 >> 9) & 1 ^ v177) & ~(v147 >> 9) & (v147 >> 8)
       | ((v147 >> 9) ^ (v147 >> 8)) & ~v176 & v177
       | (2 * (((unsigned __int16)v37 >> 9) & 1 & ~(v170 | v177) & (v147 >> 9) | v178));
  v181 = (unsigned __int16)v37 >> 11;
  v182 = (v37 >> 10) & 1;
  v183 = (v147 >> 10) & 1;
  LOWORD(v173) = v179 | v172;
  v184 = ((unsigned __int16)v37 >> 11) & 1;
  LOWORD(v180) = v180 | v178;
  v185 = v183 & (v147 >> 11) | v182 & v181;
  v186 = (unsigned __int16)v37 >> 14;
  v187 = (v37 >> 15) & 1;
  v188 = (v184 ^ v182) & ~(v147 >> 11) & (v147 >> 10);
  LOWORD(v172) = ((*(_WORD *)(v92 + 1328) >> 11) ^ (*(_WORD *)(v92 + 1328) >> 10)) & ~(_WORD)v181 & v182;
  v189 = v183 | v182;
  v190 = (v147 >> 14) & (v147 >> 15) | v186 & v187;
  v191 = v184 & ~v189 & (v147 >> 11);
  v192 = (((unsigned __int16)v37 >> 14) & 1 ^ v187) & ~(v147 >> 15) & (v147 >> 14)
       | ((v147 >> 14) & 1 ^ (v147 >> 15)) & ~v187 & v186
       | (2 * (v190 | v187 & ~((v147 >> 14) | v186) & (v147 >> 15)));
  LOWORD(v188) = v188 | v172;
  LOWORD(v189) = (unsigned __int16)v37 >> 13;
  v193 = (v37 >> 12) & 1;
  v194 = v147 >> 13;
  v195 = (v147 >> 12) & 1;
  LOWORD(v188) = (((unsigned __int16)v192 | (unsigned __int16)v190) << 14)
               | (16 * v164)
               | ((_WORD)v173 << 6)
               | ((_WORD)v180 << 8)
               | (((unsigned __int16)(v188 | (2 * (v191 | v185))) | (unsigned __int16)v185) << 10)
               | ((((v145 >> 13)
                  & 1
                  ^ (unsigned __int16)v193)
                 & (unsigned __int16)~(_WORD)v194
                 & (*(_WORD *)(v92 + 1328) >> 12)
                 | (v194 ^ (*(_WORD *)(v92 + 1328) >> 12)) & (unsigned __int16)~(_WORD)v189 & (unsigned __int16)v193
                 | (unsigned __int16)(2
                                    * (((v145 & 0x2000) != 0) & (unsigned __int8)~(v195 | v193) & (unsigned __int8)v194
                                     | v195 & v194
                                     | v193 & v189))
                 | (unsigned __int16)(v195 & v194 | v193 & v189)) << 12);
  LOWORD(v193) = v96 | (2 * (v153 | v149)) | (4 * (v163 | v154)) | v149;
  v196 = (unsigned __int16)v38;
  v197 = ((unsigned __int16)v38 >> 1) & 1;
  *((_WORD *)v257 + 694) = v188 | v193;
  v198 = (unsigned __int16)v38 >> 1;
  v199 = *(unsigned __int16 *)(v255 + 1330);
  v200 = (v199 >> 2) & 1;
  v201 = (v199 >> 1) & v199 & 1 | (unsigned __int8)v198 & v38 & 1;
  v202 = (unsigned __int16)v38 >> 3;
  v203 = (v38 >> 2) & 1;
  v204 = (v197 ^ v38 & 1) & ~(v199 >> 1) & v199 | ((v199 >> 1) ^ v199) & ~v198 & v38 & 1;
  v205 = ((unsigned __int16)v38 >> 3) & 1;
  v206 = v197 & ~(v199 & 1 | v38 & 1) & (v199 >> 1);
  v207 = v200 & (v199 >> 3) | v203 & v202;
  v208 = ((v199 >> 3) ^ (v199 >> 2)) & ~v202 & v203;
  v209 = (v205 ^ v203) & ~(v199 >> 3);
  v210 = v205 & ~(v200 | v203);
  v211 = (unsigned __int16)v38 >> 5;
  v212 = (v38 >> 4) & 1;
  v213 = v209 & (v199 >> 2) | v208 | (2 * (v210 & (v199 >> 3) | v207));
  v214 = (unsigned __int16)v38 >> 7;
  v215 = (v38 >> 6) & 1;
  v216 = (v199 >> 6) & 1;
  v217 = (((unsigned __int16)v38 >> 5) & 1 ^ v212) & ~(v199 >> 5) & (v199 >> 4)
       | ((v199 >> 5) ^ (v199 >> 4)) & ~v211 & v212
       | (2
        * (((unsigned __int16)v38 >> 5) & 1 & ~((v199 >> 4) & 1 | v212) & (v199 >> 5)
         | (v199 >> 4) & 1 & (v199 >> 5)
         | v212 & v211))
       | (v199 >> 4) & 1 & (v199 >> 5)
       | v212 & v211;
  v218 = ((unsigned __int16)v38 >> 7) & 1;
  v219 = v216 & (v199 >> 7) | v215 & v214;
  v220 = ((v199 >> 7) ^ (v199 >> 6)) & ~v214 & v215;
  v221 = v218 ^ v215;
  v222 = v216 | v215;
  v223 = (unsigned __int16)v38 >> 9;
  v224 = (v38 >> 8) & 1;
  v225 = (v199 >> 8) & 1;
  v226 = v225 & (v199 >> 9) | v224 & v223;
  v227 = v221 & ~(v199 >> 7) & (v199 >> 6) | v220 | (2 * (v218 & ~v222 & (v199 >> 7) | v219));
  v228 = (((unsigned __int16)v38 >> 9) & 1 ^ v224) & ~(v199 >> 9) & (v199 >> 8)
       | ((v199 >> 9) ^ (v199 >> 8)) & ~v223 & v224
       | (2 * (((unsigned __int16)v38 >> 9) & 1 & ~(v225 | v224) & (v199 >> 9) | v226));
  v229 = (unsigned __int16)v38 >> 11;
  v230 = (v38 >> 10) & 1;
  v231 = (v199 >> 10) & 1;
  LOWORD(v220) = v227 | v219;
  v232 = ((unsigned __int16)v38 >> 11) & 1;
  LOWORD(v228) = v228 | v226;
  v233 = v231 & (v199 >> 11) | v230 & v229;
  v234 = (unsigned __int16)v38 >> 14;
  v235 = (v38 >> 15) & 1;
  v236 = (v232 ^ v230) & ~(v199 >> 11) & (v199 >> 10);
  LOWORD(v219) = ((*(_WORD *)(v92 + 1330) >> 11) ^ (*(_WORD *)(v92 + 1330) >> 10)) & ~(_WORD)v229 & v230;
  v237 = v231 | v230;
  v238 = (v199 >> 14) & (v199 >> 15) | v234 & v235;
  v239 = v232 & ~v237 & (v199 >> 11);
  LOWORD(v236) = v236 | v219;
  v240 = (((unsigned __int16)v38 >> 14) & 1 ^ v235) & ~(v199 >> 15) & (v199 >> 14)
       | ((v199 >> 14) & 1 ^ (v199 >> 15)) & ~v235 & v234
       | (2 * (v238 | v235 & ~((v199 >> 14) | v234) & (v199 >> 15)));
  LOWORD(v237) = (unsigned __int16)v38 >> 13;
  v241 = (v38 >> 12) & 1;
  v242 = v199 >> 13;
  v243 = (v199 >> 12) & 1;
  LOWORD(v236) = (((unsigned __int16)v240 | (unsigned __int16)v238) << 14)
               | (16 * v217)
               | ((_WORD)v220 << 6)
               | ((_WORD)v228 << 8)
               | (((unsigned __int16)(v236 | (2 * (v239 | v233))) | (unsigned __int16)v233) << 10)
               | ((((v196 >> 13)
                  & 1
                  ^ (unsigned __int16)v241)
                 & (unsigned __int16)~(_WORD)v242
                 & (*(_WORD *)(v255 + 1330) >> 12)
                 | (v242 ^ (*(_WORD *)(v255 + 1330) >> 12)) & (unsigned __int16)~(_WORD)v237 & (unsigned __int16)v241
                 | (unsigned __int16)(2
                                    * (((v196 & 0x2000) != 0) & (unsigned __int8)~(v243 | v241) & (unsigned __int8)v242
                                     | v243 & v242
                                     | v241 & v237))
                 | (unsigned __int16)(v243 & v242 | v241 & v237)) << 12)
               | v204
               | (2 * (v206 | v201))
               | (4 * (v213 | v207))
               | v201;
  v244 = *(_QWORD *)((char *)v257 + 1309);
  *((_WORD *)v257 + 695) = v236;
  v245 = ((unsigned int)v244 >> 3) & 3;
  v246 = (unsigned int)v244 >> 3;
  v247 = v244 & 0xFFFFFFFFFFFFFFE7LL;
  if ( v245 >= *(unsigned __int8 *)(v255 + 1484) )
    v248 = *(_BYTE *)(v255 + 1484);
  else
    v248 = v246;
  v249 = v247 | (8 * (v248 & 3u));
  v250 = *(_QWORD *)((char *)v257 + 1369);
  *(_QWORD *)((char *)v257 + 1309) = v249;
  LODWORD(v249) = ((unsigned int)v250 >> 3) & 3;
  v251 = (unsigned int)v250 >> 3;
  v252 = v250 & 0xFFFFFFFFFFFFFFE7LL;
  if ( (unsigned int)v249 >= *(unsigned __int8 *)(v255 + 1484) )
    v253 = *(_BYTE *)(v255 + 1484);
  else
    v253 = v251;
  *(_QWORD *)((char *)v257 + 1369) = v252 | (8 * (v253 & 3u));
  qdf_mem_copy((char *)v256 + 21908, (char *)v256 + 21788, 0x3Cu);
  return qdf_mem_copy(v256 + 2746, v256 + 2731, 0x3Cu);
}
