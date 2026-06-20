__int64 __fastcall dp_update_vdev_stats(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 v5; // x2
  __int64 v6; // x8
  __int64 v7; // x10
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x9
  __int64 v13; // x11
  __int64 v14; // x17
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x5
  __int64 v19; // x6
  int v20; // w21
  int v21; // w7
  int v22; // w21
  int v23; // w7
  int v24; // w21
  int v25; // w7
  int v26; // w21
  int v27; // w7
  int v28; // w21
  int v29; // w7
  int v30; // w21
  int v31; // w7
  int v32; // w21
  int v33; // w7
  int v34; // w21
  int v35; // w7
  int v36; // w21
  int v37; // w7
  int v38; // w21
  unsigned int v39; // w21
  unsigned int v40; // w21
  unsigned int v41; // w21
  unsigned int v42; // w21
  int v43; // w21
  _DWORD *v44; // x7
  _DWORD *v45; // x21
  int v46; // w24
  int v47; // w24
  int v48; // w24
  int v49; // w24
  int v50; // w24
  int v51; // w24
  int v52; // w24
  __int64 v53; // x6
  __int64 v54; // x21
  __int64 v55; // x7
  __int64 v56; // x21
  __int64 v57; // x7
  __int64 v58; // x21
  __int64 v59; // x7
  __int64 v60; // x21
  __int64 v61; // x7
  __int64 v62; // x6
  int v63; // w22
  __int64 v64; // x21
  __int64 v65; // x7
  __int64 v66; // x21
  __int64 v67; // x7
  __int64 v68; // x21
  __int64 v69; // x7
  __int64 v70; // x21
  __int64 v71; // x7
  __int64 v72; // x21
  __int64 v73; // x7
  __int64 v74; // x21
  __int64 v75; // x7
  unsigned int v76; // w22
  unsigned int v77; // w22
  unsigned int v78; // w22
  unsigned int v79; // w22
  _DWORD *v80; // x7
  _DWORD *v81; // x21
  int v82; // w24
  int v83; // w24
  int v84; // w24
  int v85; // w24
  int v86; // w24
  int v87; // w24
  int v88; // w24
  __int64 v89; // x6
  __int64 v90; // x21
  __int64 v91; // x7
  __int64 v92; // x21
  __int64 v93; // x7
  __int64 v94; // x21
  __int64 v95; // x7
  __int64 v96; // x21
  __int64 v97; // x7
  char v98; // w21
  __int64 v99; // x6
  _DWORD *v100; // x22
  _DWORD *v101; // x6
  int v102; // w25
  int v103; // w25
  int v104; // w25
  int v105; // w25
  int v106; // w25
  int v107; // w25
  int v108; // w25
  int v109; // w25
  int v110; // w25
  int v111; // w25
  int v112; // w25
  int v113; // w25
  char v114; // w24
  __int64 v115; // x6
  int v116; // w21
  int v117; // w7
  int v118; // w21
  int v119; // w7
  int v120; // w21
  int v121; // w7
  int v122; // w21
  int v123; // w7
  int v124; // w21
  int v125; // w7
  int v126; // w21
  int v127; // w7
  int v128; // w21
  int v129; // w7
  int v130; // w21
  int v131; // w7
  int v132; // w21
  int v133; // w7
  int v134; // w21
  int v135; // w7
  int v136; // w21
  int v137; // w7
  int v138; // w21
  int v139; // w7
  int v140; // w21
  int v141; // w7
  int v142; // w21
  int v143; // w7
  int v144; // w21
  int v145; // w7
  int v146; // w21
  int v147; // w7
  int v148; // w21
  int v149; // w7
  int v150; // w21
  int v151; // w7
  int v152; // w21
  int v153; // w7
  int v154; // w21
  int v155; // w7
  int v156; // w21
  int v157; // w7
  int v158; // w21
  int v159; // w7
  int v160; // w21
  int v161; // w7
  int v162; // w21
  int v163; // w7
  int v164; // w21
  int v165; // w7
  int v166; // w21
  int v167; // w7
  int v168; // w21
  int v169; // w7
  int v170; // w21
  int v171; // w7
  int v172; // w21
  int v173; // w7
  int v174; // w21
  int v175; // w7
  int v176; // w21
  int v177; // w7
  int v178; // w21
  int v179; // w7
  int v180; // w21
  int v181; // w7
  int v182; // w21
  int v183; // w7
  int v184; // w21
  int v185; // w7
  int v186; // w21
  int v187; // w7
  __int64 v188; // x21
  __int64 v189; // x7
  __int64 v190; // x21
  __int64 v191; // x7
  __int64 v192; // x21
  __int64 v193; // x7
  __int64 v194; // x21
  __int64 v195; // x7
  __int64 v196; // x21
  __int64 v197; // x7
  __int64 v198; // x21
  __int64 v199; // x7
  __int64 v200; // x21
  __int64 v201; // x7
  __int64 v202; // x21
  __int64 v203; // x7
  __int64 v204; // x21
  __int64 v205; // x7
  __int64 v206; // x21
  __int64 v207; // x7
  __int64 v208; // x21
  __int64 v209; // x7
  __int64 v210; // x21
  __int64 v211; // x7
  __int64 v212; // x21
  __int64 v213; // x7
  __int64 v214; // x6
  __int64 v215; // x7
  __int64 v216; // x7
  __int64 v217; // x21
  __int64 v218; // x6
  __int64 v219; // x7
  __int64 v220; // x21
  __int64 v221; // x6
  __int64 v222; // x7
  __int64 v223; // x21
  __int64 v224; // x6
  __int64 v225; // x7
  __int64 v226; // x21
  __int64 v227; // x6
  __int64 v228; // x7
  __int64 v229; // x21
  __int64 v230; // x6
  __int64 v231; // x7
  __int64 v232; // x21
  __int64 v233; // x6
  __int64 v234; // x7
  __int64 v235; // x21

  raw_spin_lock(a2 + 18);
  v5 = *a2;
  if ( *a2 )
  {
    v6 = *(unsigned __int8 *)(v5 + 2221);
    if ( a3 )
    {
      v7 = *(_QWORD *)(a3 + 2480);
      *(_QWORD *)(a3 + 2472) += *(_QWORD *)(v5 + 16);
      v8 = v7 + *(_QWORD *)(v5 + 24);
      LODWORD(v7) = *(_DWORD *)(a3 + 2572);
      *(_QWORD *)(a3 + 2480) = v8;
      LODWORD(v8) = v7 + *(_DWORD *)(v5 + 12);
      v9 = *(_QWORD *)(a3 + 4768);
      *(_DWORD *)(a3 + 2572) = v8;
      v10 = v9 + *(_QWORD *)(v5 + 32);
      v11 = *(_QWORD *)(a3 + 4776);
      *(_QWORD *)(a3 + 4768) = v10;
      *(_QWORD *)(a3 + 4776) = v11 + *(_QWORD *)(v5 + 40);
    }
    if ( (_DWORD)v6 )
    {
      v12 = 0;
      v13 = v5 + 2224;
      v14 = v5 + 3332;
      v15 = v5 + 3952;
      v16 = v5 + 4408;
      v17 = v5 + 2424;
      do
      {
        v18 = v13 + 3256 * v12;
        v19 = 0;
        v20 = *(_DWORD *)(a3 + 2584);
        *(_DWORD *)(a3 + 2580) += *(_DWORD *)(v18 + 1040);
        v21 = v20 + *(_DWORD *)(v18 + 1044);
        v22 = *(_DWORD *)(a3 + 2588);
        *(_DWORD *)(a3 + 2584) = v21;
        v23 = v22 + *(_DWORD *)(v18 + 1048);
        v24 = *(_DWORD *)(a3 + 3308);
        *(_DWORD *)(a3 + 2588) = v23;
        v25 = v24 + *(_DWORD *)(v18 + 1384);
        v26 = *(_DWORD *)(a3 + 3312);
        *(_DWORD *)(a3 + 3308) = v25;
        v27 = v26 + *(_DWORD *)(v18 + 1388);
        v28 = *(_DWORD *)(a3 + 3800);
        *(_DWORD *)(a3 + 3312) = v27;
        v29 = v28 + *(_DWORD *)(v18 + 1392);
        v30 = *(_DWORD *)(a3 + 3344);
        *(_DWORD *)(a3 + 3800) = v29;
        v31 = v30 + *(_DWORD *)(v18 + 1396);
        v32 = *(_DWORD *)(a3 + 3348);
        *(_DWORD *)(a3 + 3344) = v31;
        v33 = v32 + *(_DWORD *)(v18 + 1400);
        v34 = *(_DWORD *)(a3 + 3352);
        *(_DWORD *)(a3 + 3348) = v33;
        v35 = v34 + *(_DWORD *)(v18 + 1404);
        v36 = *(_DWORD *)(a3 + 3000);
        *(_DWORD *)(a3 + 3352) = v35;
        *(_DWORD *)(a3 + 2604) = *(_DWORD *)(v18 + 1408);
        *(_DWORD *)(a3 + 2608) = *(_DWORD *)(v18 + 1412);
        *(_DWORD *)(a3 + 2612) = *(_DWORD *)(v18 + 1416);
        *(_DWORD *)(a3 + 2616) = *(_DWORD *)(v18 + 1420);
        *(_DWORD *)(a3 + 2620) = *(_DWORD *)(v18 + 1424);
        *(_QWORD *)(a3 + 2632) = *(_QWORD *)(v18 + 1432);
        *(_QWORD *)(a3 + 2640) = *(_QWORD *)(v18 + 1440);
        *(_WORD *)(a3 + 3304) = *(_WORD *)(v18 + 1448);
        v37 = v36 + *(_DWORD *)(v18 + 1472);
        v38 = *(_DWORD *)(a3 + 4072);
        *(_DWORD *)(a3 + 3000) = v37;
        *(_DWORD *)(a3 + 3720) = *(_DWORD *)(v18 + 1540);
        *(_DWORD *)(a3 + 3724) = *(_DWORD *)(v18 + 1544);
        *(_DWORD *)(a3 + 2648) = *(_DWORD *)(v18 + 1984);
        *(_DWORD *)(a3 + 2652) = *(_DWORD *)(v18 + 1988);
        v39 = v38 & 0xFFFFFFF0 | *(_DWORD *)(v18 + 1996) & 0xF;
        *(_DWORD *)(a3 + 4072) = v39;
        v40 = v39 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v18 + 1996) >> 4) & 0xF));
        *(_DWORD *)(a3 + 4072) = v40;
        v41 = v40 & 0xFFFFF0FF | (((*(_DWORD *)(v18 + 1996) >> 8) & 0xF) << 8);
        *(_DWORD *)(a3 + 4072) = v41;
        v42 = v41 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v18 + 1996)) >> 4 << 12);
        *(_DWORD *)(a3 + 4072) = v42;
        *(_DWORD *)(a3 + 4072) = v42 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v18 + 1996)) & 0xF) << 16);
        v43 = *(_DWORD *)(a3 + 4076);
        *(_DWORD *)(a3 + 2592) += *(_DWORD *)(v18 + 2000);
        *(_DWORD *)(a3 + 4076) = v43 + *(_DWORD *)(v18 + 2004);
        *(_DWORD *)(a3 + 4096) = *(_DWORD *)(v18 + 2040);
        *(_DWORD *)(a3 + 4100) = *(_DWORD *)(v18 + 2044);
        *(_DWORD *)(a3 + 4104) = *(_DWORD *)(v18 + 2048);
        *(_DWORD *)(a3 + 4108) = *(_DWORD *)(v18 + 2052);
        do
        {
          v44 = (_DWORD *)(a3 + 2680 + v19);
          v45 = (_DWORD *)(v14 + v19);
          v19 += 60;
          v46 = v44[1];
          *v44 += *(v45 - 14);
          v44[1] = v46 + *(v45 - 13);
          v47 = v44[3];
          v44[2] += *(v45 - 12);
          v44[3] = v47 + *(v45 - 11);
          v48 = v44[5];
          v44[4] += *(v45 - 10);
          v44[5] = v48 + *(v45 - 9);
          v49 = v44[7];
          v44[6] += *(v45 - 8);
          v44[7] = v49 + *(v45 - 7);
          v50 = v44[9];
          v44[8] += *(v45 - 6);
          v44[9] = v50 + *(v45 - 5);
          v51 = v44[11];
          v44[10] += *(v45 - 4);
          v44[11] = v51 + *(v45 - 3);
          v52 = v44[13];
          v44[12] += *(v45 - 2);
          v44[13] = v52 + *(v45 - 1);
          v44[14] += *v45;
        }
        while ( v19 != 300 );
        v53 = 0;
        v54 = *(_QWORD *)(a3 + 4120);
        *(_DWORD *)(a3 + 3068) += *(_DWORD *)(v18 + 1352);
        v55 = v54 + *(_QWORD *)(v18 + 2088);
        LODWORD(v54) = *(_DWORD *)(a3 + 3084);
        *(_QWORD *)(a3 + 4120) = v55;
        LODWORD(v55) = v54 + *(_DWORD *)(v18 + 1368);
        LODWORD(v54) = *(_DWORD *)(a3 + 3072);
        *(_DWORD *)(a3 + 3084) = v55;
        LODWORD(v55) = v54 + *(_DWORD *)(v18 + 1356);
        v56 = *(_QWORD *)(a3 + 4128);
        *(_DWORD *)(a3 + 3072) = v55;
        v57 = v56 + *(_QWORD *)(v18 + 2096);
        LODWORD(v56) = *(_DWORD *)(a3 + 3088);
        *(_QWORD *)(a3 + 4128) = v57;
        LODWORD(v57) = v56 + *(_DWORD *)(v18 + 1372);
        LODWORD(v56) = *(_DWORD *)(a3 + 3076);
        *(_DWORD *)(a3 + 3088) = v57;
        LODWORD(v57) = v56 + *(_DWORD *)(v18 + 1360);
        v58 = *(_QWORD *)(a3 + 4136);
        *(_DWORD *)(a3 + 3076) = v57;
        v59 = v58 + *(_QWORD *)(v18 + 2104);
        LODWORD(v58) = *(_DWORD *)(a3 + 3092);
        *(_QWORD *)(a3 + 4136) = v59;
        LODWORD(v59) = v58 + *(_DWORD *)(v18 + 1376);
        LODWORD(v58) = *(_DWORD *)(a3 + 3080);
        *(_DWORD *)(a3 + 3092) = v59;
        LODWORD(v59) = v58 + *(_DWORD *)(v18 + 1364);
        v60 = *(_QWORD *)(a3 + 4144);
        *(_DWORD *)(a3 + 3080) = v59;
        v61 = v60 + *(_QWORD *)(v18 + 2112);
        LODWORD(v60) = *(_DWORD *)(a3 + 3096);
        *(_QWORD *)(a3 + 4144) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1380);
        LODWORD(v60) = *(_DWORD *)(a3 + 2980);
        *(_DWORD *)(a3 + 3096) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1452);
        LODWORD(v60) = *(_DWORD *)(a3 + 2984);
        *(_DWORD *)(a3 + 2980) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1456);
        LODWORD(v60) = *(_DWORD *)(a3 + 2988);
        *(_DWORD *)(a3 + 2984) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1460);
        LODWORD(v60) = *(_DWORD *)(a3 + 2992);
        *(_DWORD *)(a3 + 2988) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1464);
        LODWORD(v60) = *(_DWORD *)(a3 + 2996);
        *(_DWORD *)(a3 + 2992) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1468);
        LODWORD(v60) = *(_DWORD *)(a3 + 3004);
        *(_DWORD *)(a3 + 2996) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1476);
        LODWORD(v60) = *(_DWORD *)(a3 + 3008);
        *(_DWORD *)(a3 + 3004) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1480);
        LODWORD(v60) = *(_DWORD *)(a3 + 3012);
        *(_DWORD *)(a3 + 3008) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1484);
        LODWORD(v60) = *(_DWORD *)(a3 + 3016);
        *(_DWORD *)(a3 + 3012) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1488);
        LODWORD(v60) = *(_DWORD *)(a3 + 3020);
        *(_DWORD *)(a3 + 3016) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1492);
        LODWORD(v60) = *(_DWORD *)(a3 + 3024);
        *(_DWORD *)(a3 + 3020) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1496);
        LODWORD(v60) = *(_DWORD *)(a3 + 3028);
        *(_DWORD *)(a3 + 3024) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1500);
        LODWORD(v60) = *(_DWORD *)(a3 + 3032);
        *(_DWORD *)(a3 + 3028) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1504);
        LODWORD(v60) = *(_DWORD *)(a3 + 3036);
        *(_DWORD *)(a3 + 3032) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1508);
        LODWORD(v60) = *(_DWORD *)(a3 + 3040);
        *(_DWORD *)(a3 + 3036) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1512);
        LODWORD(v60) = *(_DWORD *)(a3 + 3044);
        *(_DWORD *)(a3 + 3040) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1516);
        LODWORD(v60) = *(_DWORD *)(a3 + 3048);
        *(_DWORD *)(a3 + 3044) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1520);
        LODWORD(v60) = *(_DWORD *)(a3 + 3052);
        *(_DWORD *)(a3 + 3048) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1524);
        LODWORD(v60) = *(_DWORD *)(a3 + 3056);
        *(_DWORD *)(a3 + 3052) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1528);
        LODWORD(v60) = *(_DWORD *)(a3 + 3060);
        *(_DWORD *)(a3 + 3056) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1532);
        LODWORD(v60) = *(_DWORD *)(a3 + 3064);
        *(_DWORD *)(a3 + 3060) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1536);
        LODWORD(v60) = *(_DWORD *)(a3 + 3728);
        *(_DWORD *)(a3 + 3064) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1548);
        LODWORD(v60) = *(_DWORD *)(a3 + 3732);
        *(_DWORD *)(a3 + 3728) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1552);
        LODWORD(v60) = *(_DWORD *)(a3 + 3736);
        *(_DWORD *)(a3 + 3732) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1556);
        LODWORD(v60) = *(_DWORD *)(a3 + 3740);
        *(_DWORD *)(a3 + 3736) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1560);
        LODWORD(v60) = *(_DWORD *)(a3 + 3744);
        *(_DWORD *)(a3 + 3740) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1564);
        LODWORD(v60) = *(_DWORD *)(a3 + 3748);
        *(_DWORD *)(a3 + 3744) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1568);
        LODWORD(v60) = *(_DWORD *)(a3 + 3752);
        *(_DWORD *)(a3 + 3748) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1572);
        LODWORD(v60) = *(_DWORD *)(a3 + 3756);
        *(_DWORD *)(a3 + 3752) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1576);
        LODWORD(v60) = *(_DWORD *)(a3 + 3760);
        *(_DWORD *)(a3 + 3756) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1580);
        LODWORD(v60) = *(_DWORD *)(a3 + 3764);
        *(_DWORD *)(a3 + 3760) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1584);
        LODWORD(v60) = *(_DWORD *)(a3 + 3768);
        *(_DWORD *)(a3 + 3764) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1588);
        LODWORD(v60) = *(_DWORD *)(a3 + 3772);
        *(_DWORD *)(a3 + 3768) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1592);
        LODWORD(v60) = *(_DWORD *)(a3 + 3776);
        *(_DWORD *)(a3 + 3772) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1596);
        LODWORD(v60) = *(_DWORD *)(a3 + 3780);
        *(_DWORD *)(a3 + 3776) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1600);
        LODWORD(v60) = *(_DWORD *)(a3 + 3784);
        *(_DWORD *)(a3 + 3780) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1604);
        LODWORD(v60) = *(_DWORD *)(a3 + 3788);
        *(_DWORD *)(a3 + 3784) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1608);
        LODWORD(v60) = *(_DWORD *)(a3 + 3792);
        *(_DWORD *)(a3 + 3788) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1612);
        LODWORD(v60) = *(_DWORD *)(a3 + 3796);
        *(_DWORD *)(a3 + 3792) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1616);
        LODWORD(v60) = *(_DWORD *)(a3 + 3356);
        *(_DWORD *)(a3 + 3796) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1620);
        LODWORD(v60) = *(_DWORD *)(a3 + 3360);
        *(_DWORD *)(a3 + 3356) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1624);
        LODWORD(v60) = *(_DWORD *)(a3 + 3364);
        *(_DWORD *)(a3 + 3360) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1628);
        LODWORD(v60) = *(_DWORD *)(a3 + 3368);
        *(_DWORD *)(a3 + 3364) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1632);
        LODWORD(v60) = *(_DWORD *)(a3 + 3372);
        *(_DWORD *)(a3 + 3368) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1636);
        LODWORD(v60) = *(_DWORD *)(a3 + 3376);
        *(_DWORD *)(a3 + 3372) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1640);
        LODWORD(v60) = *(_DWORD *)(a3 + 3380);
        *(_DWORD *)(a3 + 3376) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1644);
        LODWORD(v60) = *(_DWORD *)(a3 + 3384);
        *(_DWORD *)(a3 + 3380) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1648);
        LODWORD(v60) = *(_DWORD *)(a3 + 3388);
        *(_DWORD *)(a3 + 3384) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1652);
        LODWORD(v60) = *(_DWORD *)(a3 + 3392);
        *(_DWORD *)(a3 + 3388) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1656);
        LODWORD(v60) = *(_DWORD *)(a3 + 3396);
        *(_DWORD *)(a3 + 3392) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1660);
        LODWORD(v60) = *(_DWORD *)(a3 + 3400);
        *(_DWORD *)(a3 + 3396) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1664);
        LODWORD(v60) = *(_DWORD *)(a3 + 3404);
        *(_DWORD *)(a3 + 3400) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1668);
        LODWORD(v60) = *(_DWORD *)(a3 + 3408);
        *(_DWORD *)(a3 + 3404) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1672);
        LODWORD(v60) = *(_DWORD *)(a3 + 3412);
        *(_DWORD *)(a3 + 3408) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1676);
        LODWORD(v60) = *(_DWORD *)(a3 + 3416);
        *(_DWORD *)(a3 + 3412) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1680);
        LODWORD(v60) = *(_DWORD *)(a3 + 3420);
        *(_DWORD *)(a3 + 3416) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1684);
        LODWORD(v60) = *(_DWORD *)(a3 + 3424);
        *(_DWORD *)(a3 + 3420) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1688);
        LODWORD(v60) = *(_DWORD *)(a3 + 3428);
        *(_DWORD *)(a3 + 3424) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1692);
        LODWORD(v60) = *(_DWORD *)(a3 + 3432);
        *(_DWORD *)(a3 + 3428) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1696);
        LODWORD(v60) = *(_DWORD *)(a3 + 3436);
        *(_DWORD *)(a3 + 3432) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1700);
        LODWORD(v60) = *(_DWORD *)(a3 + 3440);
        *(_DWORD *)(a3 + 3436) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1704);
        LODWORD(v60) = *(_DWORD *)(a3 + 3444);
        *(_DWORD *)(a3 + 3440) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1708);
        LODWORD(v60) = *(_DWORD *)(a3 + 3448);
        *(_DWORD *)(a3 + 3444) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1712);
        LODWORD(v60) = *(_DWORD *)(a3 + 3452);
        *(_DWORD *)(a3 + 3448) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1716);
        LODWORD(v60) = *(_DWORD *)(a3 + 3456);
        *(_DWORD *)(a3 + 3452) = v61;
        LODWORD(v61) = v60 + *(_DWORD *)(v18 + 1720);
        LODWORD(v60) = *(_DWORD *)(a3 + 3460);
        *(_DWORD *)(a3 + 3456) = v61;
        *(_DWORD *)(a3 + 3460) = v60 + *(_DWORD *)(v18 + 1724);
        do
        {
          *(_DWORD *)(a3 + 3464 + v53) = *(_DWORD *)(v15 + v53);
          v53 += 4;
        }
        while ( v53 != 256 );
        v62 = 0;
        v63 = *(_DWORD *)(a3 + 6076);
        v64 = *(_QWORD *)(a3 + 4160);
        *(_QWORD *)(a3 + 4152) += *(_QWORD *)(v18 + 2008);
        v65 = v64 + *(_QWORD *)(v18 + 2016);
        v66 = *(_QWORD *)(a3 + 4168);
        *(_QWORD *)(a3 + 4160) = v65;
        v67 = v66 + *(_QWORD *)(v18 + 2024);
        v68 = *(_QWORD *)(a3 + 4176);
        *(_QWORD *)(a3 + 4168) = v67;
        v69 = v68 + *(_QWORD *)(v18 + 2032);
        v70 = *(_QWORD *)(a3 + 4760);
        *(_QWORD *)(a3 + 4176) = v69;
        *(_DWORD *)(a3 + 3244) = *(_DWORD *)(v18 + 2056);
        *(_DWORD *)(a3 + 3248) = *(_DWORD *)(v18 + 2060);
        *(_DWORD *)(a3 + 3252) = *(_DWORD *)(v18 + 2064);
        *(_DWORD *)(a3 + 3256) = *(_DWORD *)(v18 + 2068);
        *(_DWORD *)(a3 + 3260) = *(_DWORD *)(v18 + 2072);
        *(_DWORD *)(a3 + 3264) = *(_DWORD *)(v18 + 2076);
        *(_DWORD *)(a3 + 3268) = *(_DWORD *)(v18 + 2080);
        *(_DWORD *)(a3 + 3272) = *(_DWORD *)(v18 + 2084);
        v71 = v70 + *(_QWORD *)(v18 + 2120);
        LODWORD(v70) = *(_DWORD *)(a3 + 5572);
        *(_QWORD *)(a3 + 4760) = v71;
        LODWORD(v71) = v70 + *(_DWORD *)(v18 + 2444);
        LODWORD(v70) = *(_DWORD *)(a3 + 5576);
        *(_DWORD *)(a3 + 5572) = v71;
        LODWORD(v71) = v70 + *(_DWORD *)(v18 + 2448);
        v72 = *(_QWORD *)(a3 + 6152);
        *(_DWORD *)(a3 + 5576) = v71;
        v73 = v72 + *(_QWORD *)(v18 + 3040);
        v74 = *(_QWORD *)(a3 + 6160);
        *(_QWORD *)(a3 + 6152) = v73;
        v75 = v74 + *(_QWORD *)(v18 + 3048);
        LODWORD(v74) = *(_DWORD *)(a3 + 5888);
        *(_QWORD *)(a3 + 6160) = v75;
        LODWORD(v75) = v74 + *(_DWORD *)(v18 + 2452);
        LODWORD(v74) = *(_DWORD *)(a3 + 5892);
        *(_DWORD *)(a3 + 5888) = v75;
        LODWORD(v75) = v74 + *(_DWORD *)(v18 + 2456);
        LODWORD(v74) = *(_DWORD *)(a3 + 5964);
        *(_DWORD *)(a3 + 5892) = v75;
        LODWORD(v75) = v74 + *(_DWORD *)(v18 + 2460);
        LODWORD(v74) = *(_DWORD *)(a3 + 5968);
        *(_DWORD *)(a3 + 5964) = v75;
        LODWORD(v75) = v74 + *(_DWORD *)(v18 + 2464);
        LODWORD(v74) = *(_DWORD *)(a3 + 6184);
        *(_DWORD *)(a3 + 5968) = v75;
        *(_DWORD *)(a3 + 5912) = *(_DWORD *)(v18 + 2936);
        *(_DWORD *)(a3 + 5916) = *(_DWORD *)(v18 + 2940);
        *(_DWORD *)(a3 + 5920) = *(_DWORD *)(v18 + 2944);
        *(_DWORD *)(a3 + 5924) = *(_DWORD *)(v18 + 2948);
        *(_DWORD *)(a3 + 5980) = *(_DWORD *)(v18 + 2952);
        *(_DWORD *)(a3 + 5908) = *(_DWORD *)(v18 + 2956);
        *(_QWORD *)(a3 + 5992) = *(_QWORD *)(v18 + 2960);
        *(_DWORD *)(a3 + 6184) = v74 + *(_DWORD *)(v18 + 3032);
        *(_BYTE *)(a3 + 6000) = *(_BYTE *)(v18 + 2968);
        *(_BYTE *)(a3 + 6001) = *(_BYTE *)(v18 + 2969);
        v76 = v63 & 0xFFFFFFF0 | *(_DWORD *)(v18 + 2970) & 0xF;
        *(_DWORD *)(a3 + 6076) = v76;
        v77 = v76 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v18 + 2970) >> 4) & 0xF));
        *(_DWORD *)(a3 + 6076) = v77;
        v78 = v77 & 0xFFFFF0FF | (((*(_DWORD *)(v18 + 2970) >> 8) & 0xF) << 8);
        *(_DWORD *)(a3 + 6076) = v78;
        v79 = v78 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v18 + 2970)) >> 4 << 12);
        LODWORD(v74) = *(_DWORD *)(a3 + 6096);
        *(_DWORD *)(a3 + 6076) = v79;
        *(_DWORD *)(a3 + 6076) = v79 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v18 + 2970)) & 0xF) << 16);
        *(_DWORD *)(a3 + 6096) = v74 + *(_DWORD *)(v18 + 2976);
        *(_DWORD *)(a3 + 6104) = *(_DWORD *)(v18 + 2980);
        *(_DWORD *)(a3 + 6108) = *(_DWORD *)(v18 + 2984);
        do
        {
          v80 = (_DWORD *)(a3 + 5188 + v62);
          v81 = (_DWORD *)(v16 + v62);
          v62 += 60;
          v82 = v80[1];
          *v80 += *(v81 - 14);
          v80[1] = v82 + *(v81 - 13);
          v83 = v80[3];
          v80[2] += *(v81 - 12);
          v80[3] = v83 + *(v81 - 11);
          v84 = v80[5];
          v80[4] += *(v81 - 10);
          v80[5] = v84 + *(v81 - 9);
          v85 = v80[7];
          v80[6] += *(v81 - 8);
          v80[7] = v85 + *(v81 - 7);
          v86 = v80[9];
          v80[8] += *(v81 - 6);
          v80[9] = v86 + *(v81 - 5);
          v87 = v80[11];
          v80[10] += *(v81 - 4);
          v80[11] = v87 + *(v81 - 3);
          v88 = v80[13];
          v80[12] += *(v81 - 2);
          v80[13] = v88 + *(v81 - 1);
          v80[14] += *v81;
        }
        while ( v62 != 300 );
        v89 = 0;
        v90 = *(_QWORD *)(a3 + 6120);
        *(_DWORD *)(a3 + 5156) += *(_DWORD *)(v18 + 2428);
        v91 = v90 + *(_QWORD *)(v18 + 2992);
        LODWORD(v90) = *(_DWORD *)(a3 + 5160);
        *(_QWORD *)(a3 + 6120) = v91;
        LODWORD(v91) = v90 + *(_DWORD *)(v18 + 2432);
        v92 = *(_QWORD *)(a3 + 6128);
        *(_DWORD *)(a3 + 5160) = v91;
        v93 = v92 + *(_QWORD *)(v18 + 3000);
        LODWORD(v92) = *(_DWORD *)(a3 + 5164);
        *(_QWORD *)(a3 + 6128) = v93;
        LODWORD(v93) = v92 + *(_DWORD *)(v18 + 2436);
        v94 = *(_QWORD *)(a3 + 6136);
        *(_DWORD *)(a3 + 5164) = v93;
        v95 = v94 + *(_QWORD *)(v18 + 3008);
        LODWORD(v94) = *(_DWORD *)(a3 + 5168);
        *(_QWORD *)(a3 + 6136) = v95;
        LODWORD(v95) = v94 + *(_DWORD *)(v18 + 2440);
        v96 = *(_QWORD *)(a3 + 6144);
        *(_DWORD *)(a3 + 5168) = v95;
        v97 = v96 + *(_QWORD *)(v18 + 3016);
        LODWORD(v96) = *(_DWORD *)(a3 + 5580);
        *(_QWORD *)(a3 + 6144) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2468);
        LODWORD(v96) = *(_DWORD *)(a3 + 6016);
        *(_DWORD *)(a3 + 5580) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2876);
        LODWORD(v96) = *(_DWORD *)(a3 + 5584);
        *(_DWORD *)(a3 + 6016) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2472);
        LODWORD(v96) = *(_DWORD *)(a3 + 6020);
        *(_DWORD *)(a3 + 5584) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2880);
        LODWORD(v96) = *(_DWORD *)(a3 + 5588);
        *(_DWORD *)(a3 + 6020) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2476);
        LODWORD(v96) = *(_DWORD *)(a3 + 6024);
        *(_DWORD *)(a3 + 5588) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2884);
        LODWORD(v96) = *(_DWORD *)(a3 + 5592);
        *(_DWORD *)(a3 + 6024) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2480);
        LODWORD(v96) = *(_DWORD *)(a3 + 6028);
        *(_DWORD *)(a3 + 5592) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2888);
        LODWORD(v96) = *(_DWORD *)(a3 + 5596);
        *(_DWORD *)(a3 + 6028) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2484);
        LODWORD(v96) = *(_DWORD *)(a3 + 6032);
        *(_DWORD *)(a3 + 5596) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2892);
        LODWORD(v96) = *(_DWORD *)(a3 + 5600);
        *(_DWORD *)(a3 + 6032) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2488);
        LODWORD(v96) = *(_DWORD *)(a3 + 6036);
        *(_DWORD *)(a3 + 5600) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2896);
        LODWORD(v96) = *(_DWORD *)(a3 + 5604);
        *(_DWORD *)(a3 + 6036) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2492);
        LODWORD(v96) = *(_DWORD *)(a3 + 6040);
        *(_DWORD *)(a3 + 5604) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2900);
        LODWORD(v96) = *(_DWORD *)(a3 + 5608);
        *(_DWORD *)(a3 + 6040) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2496);
        LODWORD(v96) = *(_DWORD *)(a3 + 6044);
        *(_DWORD *)(a3 + 5608) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2904);
        LODWORD(v96) = *(_DWORD *)(a3 + 5612);
        *(_DWORD *)(a3 + 6044) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2500);
        LODWORD(v96) = *(_DWORD *)(a3 + 6048);
        *(_DWORD *)(a3 + 5612) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2908);
        LODWORD(v96) = *(_DWORD *)(a3 + 5616);
        *(_DWORD *)(a3 + 6048) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2504);
        LODWORD(v96) = *(_DWORD *)(a3 + 6052);
        *(_DWORD *)(a3 + 5616) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2912);
        LODWORD(v96) = *(_DWORD *)(a3 + 5620);
        *(_DWORD *)(a3 + 6052) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2508);
        LODWORD(v96) = *(_DWORD *)(a3 + 6056);
        *(_DWORD *)(a3 + 5620) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2916);
        LODWORD(v96) = *(_DWORD *)(a3 + 5624);
        *(_DWORD *)(a3 + 6056) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2512);
        LODWORD(v96) = *(_DWORD *)(a3 + 6060);
        *(_DWORD *)(a3 + 5624) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2920);
        LODWORD(v96) = *(_DWORD *)(a3 + 5628);
        *(_DWORD *)(a3 + 6060) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2516);
        LODWORD(v96) = *(_DWORD *)(a3 + 6064);
        *(_DWORD *)(a3 + 5628) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2924);
        LODWORD(v96) = *(_DWORD *)(a3 + 5632);
        *(_DWORD *)(a3 + 6064) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2520);
        LODWORD(v96) = *(_DWORD *)(a3 + 6068);
        *(_DWORD *)(a3 + 5632) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2928);
        LODWORD(v96) = *(_DWORD *)(a3 + 5636);
        *(_DWORD *)(a3 + 6068) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2524);
        LODWORD(v96) = *(_DWORD *)(a3 + 6072);
        *(_DWORD *)(a3 + 5636) = v97;
        LODWORD(v97) = v96 + *(_DWORD *)(v18 + 2932);
        v98 = 1;
        *(_DWORD *)(a3 + 6072) = v97;
        do
        {
          v99 = 100 * v89;
          v100 = (_DWORD *)(v18 + 2528 + v99);
          v101 = (_DWORD *)(a3 + 5656 + v99);
          v102 = v101[9];
          v101[8] += v100[8];
          v101[9] = v102 + v100[9];
          v103 = v101[1];
          *v101 += *v100;
          v101[1] = v103 + v100[1];
          v104 = v101[3];
          v101[2] += v100[2];
          v101[3] = v104 + v100[3];
          v105 = v101[5];
          v101[4] += v100[4];
          v101[5] = v105 + v100[5];
          v106 = v101[7];
          v101[6] += v100[6];
          v101[7] = v106 + v100[7];
          v107 = v101[11];
          v101[10] += v100[10];
          v101[11] = v107 + v100[11];
          v108 = v101[13];
          v101[12] += v100[12];
          v101[13] = v108 + v100[13];
          v109 = v101[15];
          v101[14] += v100[14];
          v101[15] = v109 + v100[15];
          v110 = v101[17];
          v101[16] += v100[16];
          v101[17] = v110 + v100[17];
          v111 = v101[19];
          v101[18] += v100[18];
          v101[19] = v111 + v100[19];
          v112 = v101[21];
          v101[20] += v100[20];
          v101[21] = v112 + v100[21];
          v113 = v101[23];
          v114 = v98;
          v101[22] += v100[22];
          v101[23] = v113 + v100[23];
          v101[24] += v100[24];
          v89 = 1;
          v98 = 0;
        }
        while ( (v114 & 1) != 0 );
        v115 = 0;
        v116 = *(_DWORD *)(a3 + 5640);
        *(_DWORD *)(a3 + 5172) += *(_DWORD *)(v18 + 2728);
        v117 = v116 + *(_DWORD *)(v18 + 2744);
        v118 = *(_DWORD *)(a3 + 5176);
        *(_DWORD *)(a3 + 5640) = v117;
        v119 = v118 + *(_DWORD *)(v18 + 2732);
        v120 = *(_DWORD *)(a3 + 5644);
        *(_DWORD *)(a3 + 5176) = v119;
        v121 = v120 + *(_DWORD *)(v18 + 2748);
        v122 = *(_DWORD *)(a3 + 5180);
        *(_DWORD *)(a3 + 5644) = v121;
        v123 = v122 + *(_DWORD *)(v18 + 2736);
        v124 = *(_DWORD *)(a3 + 5648);
        *(_DWORD *)(a3 + 5180) = v123;
        v125 = v124 + *(_DWORD *)(v18 + 2752);
        v126 = *(_DWORD *)(a3 + 5184);
        *(_DWORD *)(a3 + 5648) = v125;
        v127 = v126 + *(_DWORD *)(v18 + 2740);
        v128 = *(_DWORD *)(a3 + 5652);
        *(_DWORD *)(a3 + 5184) = v127;
        v129 = v128 + *(_DWORD *)(v18 + 2756);
        v130 = *(_DWORD *)(a3 + 5488);
        *(_DWORD *)(a3 + 5652) = v129;
        v131 = v130 + *(_DWORD *)(v18 + 2760);
        v132 = *(_DWORD *)(a3 + 5492);
        *(_DWORD *)(a3 + 5488) = v131;
        v133 = v132 + *(_DWORD *)(v18 + 2764);
        v134 = *(_DWORD *)(a3 + 5496);
        *(_DWORD *)(a3 + 5492) = v133;
        v135 = v134 + *(_DWORD *)(v18 + 2768);
        v136 = *(_DWORD *)(a3 + 5500);
        *(_DWORD *)(a3 + 5496) = v135;
        v137 = v136 + *(_DWORD *)(v18 + 2772);
        v138 = *(_DWORD *)(a3 + 5504);
        *(_DWORD *)(a3 + 5500) = v137;
        v139 = v138 + *(_DWORD *)(v18 + 2776);
        v140 = *(_DWORD *)(a3 + 5508);
        *(_DWORD *)(a3 + 5504) = v139;
        v141 = v140 + *(_DWORD *)(v18 + 2780);
        v142 = *(_DWORD *)(a3 + 5540);
        *(_DWORD *)(a3 + 5508) = v141;
        v143 = v142 + *(_DWORD *)(v18 + 2812);
        v144 = *(_DWORD *)(a3 + 5512);
        *(_DWORD *)(a3 + 5540) = v143;
        v145 = v144 + *(_DWORD *)(v18 + 2784);
        v146 = *(_DWORD *)(a3 + 5544);
        *(_DWORD *)(a3 + 5512) = v145;
        v147 = v146 + *(_DWORD *)(v18 + 2816);
        v148 = *(_DWORD *)(a3 + 5516);
        *(_DWORD *)(a3 + 5544) = v147;
        v149 = v148 + *(_DWORD *)(v18 + 2788);
        v150 = *(_DWORD *)(a3 + 5548);
        *(_DWORD *)(a3 + 5516) = v149;
        v151 = v150 + *(_DWORD *)(v18 + 2820);
        v152 = *(_DWORD *)(a3 + 5520);
        *(_DWORD *)(a3 + 5548) = v151;
        v153 = v152 + *(_DWORD *)(v18 + 2792);
        v154 = *(_DWORD *)(a3 + 5552);
        *(_DWORD *)(a3 + 5520) = v153;
        v155 = v154 + *(_DWORD *)(v18 + 2824);
        v156 = *(_DWORD *)(a3 + 5524);
        *(_DWORD *)(a3 + 5552) = v155;
        v157 = v156 + *(_DWORD *)(v18 + 2796);
        v158 = *(_DWORD *)(a3 + 5556);
        *(_DWORD *)(a3 + 5524) = v157;
        v159 = v158 + *(_DWORD *)(v18 + 2828);
        v160 = *(_DWORD *)(a3 + 5528);
        *(_DWORD *)(a3 + 5556) = v159;
        v161 = v160 + *(_DWORD *)(v18 + 2800);
        v162 = *(_DWORD *)(a3 + 5560);
        *(_DWORD *)(a3 + 5528) = v161;
        v163 = v162 + *(_DWORD *)(v18 + 2832);
        v164 = *(_DWORD *)(a3 + 5532);
        *(_DWORD *)(a3 + 5560) = v163;
        v165 = v164 + *(_DWORD *)(v18 + 2804);
        v166 = *(_DWORD *)(a3 + 5564);
        *(_DWORD *)(a3 + 5532) = v165;
        v167 = v166 + *(_DWORD *)(v18 + 2836);
        v168 = *(_DWORD *)(a3 + 5536);
        *(_DWORD *)(a3 + 5564) = v167;
        v169 = v168 + *(_DWORD *)(v18 + 2808);
        v170 = *(_DWORD *)(a3 + 5568);
        *(_DWORD *)(a3 + 5536) = v169;
        v171 = v170 + *(_DWORD *)(v18 + 2840);
        v172 = *(_DWORD *)(a3 + 5856);
        *(_DWORD *)(a3 + 5568) = v171;
        v173 = v172 + *(_DWORD *)(v18 + 2844);
        v174 = *(_DWORD *)(a3 + 5860);
        *(_DWORD *)(a3 + 5856) = v173;
        v175 = v174 + *(_DWORD *)(v18 + 2848);
        v176 = *(_DWORD *)(a3 + 5864);
        *(_DWORD *)(a3 + 5860) = v175;
        v177 = v176 + *(_DWORD *)(v18 + 2852);
        v178 = *(_DWORD *)(a3 + 5868);
        *(_DWORD *)(a3 + 5864) = v177;
        v179 = v178 + *(_DWORD *)(v18 + 2856);
        v180 = *(_DWORD *)(a3 + 5872);
        *(_DWORD *)(a3 + 5868) = v179;
        v181 = v180 + *(_DWORD *)(v18 + 2860);
        v182 = *(_DWORD *)(a3 + 5876);
        *(_DWORD *)(a3 + 5872) = v181;
        v183 = v182 + *(_DWORD *)(v18 + 2864);
        v184 = *(_DWORD *)(a3 + 5880);
        *(_DWORD *)(a3 + 5876) = v183;
        v185 = v184 + *(_DWORD *)(v18 + 2868);
        v186 = *(_DWORD *)(a3 + 5884);
        *(_DWORD *)(a3 + 5880) = v185;
        v187 = v186 + *(_DWORD *)(v18 + 2872);
        v188 = *(_QWORD *)(a3 + 6176);
        *(_DWORD *)(a3 + 5884) = v187;
        v189 = v188 + *(_QWORD *)(v18 + 3024);
        v190 = *(_QWORD *)(a3 + 2488);
        *(_QWORD *)(a3 + 6176) = v189;
        v191 = v190 + *(_QWORD *)v18;
        v192 = *(_QWORD *)(a3 + 2496);
        *(_QWORD *)(a3 + 2488) = v191;
        v193 = v192 + *(_QWORD *)(v18 + 8);
        v194 = *(_QWORD *)(a3 + 2504);
        *(_QWORD *)(a3 + 2496) = v193;
        v195 = v194 + *(_QWORD *)(v18 + 16);
        v196 = *(_QWORD *)(a3 + 2512);
        *(_QWORD *)(a3 + 2504) = v195;
        v197 = v196 + *(_QWORD *)(v18 + 24);
        v198 = *(_QWORD *)(a3 + 2520);
        *(_QWORD *)(a3 + 2512) = v197;
        v199 = v198 + *(_QWORD *)(v18 + 32);
        v200 = *(_QWORD *)(a3 + 2528);
        *(_QWORD *)(a3 + 2520) = v199;
        v201 = v200 + *(_QWORD *)(v18 + 40);
        v202 = *(_QWORD *)(a3 + 2536);
        *(_QWORD *)(a3 + 2528) = v201;
        v203 = v202 + *(_QWORD *)(v18 + 48);
        v204 = *(_QWORD *)(a3 + 2544);
        *(_QWORD *)(a3 + 2536) = v203;
        v205 = v204 + *(_QWORD *)(v18 + 56);
        v206 = *(_QWORD *)(a3 + 2552);
        *(_QWORD *)(a3 + 2544) = v205;
        v207 = v206 + *(_QWORD *)(v18 + 64);
        v208 = *(_QWORD *)(a3 + 2560);
        *(_QWORD *)(a3 + 2552) = v207;
        v209 = v208 + *(_QWORD *)(v18 + 72);
        LODWORD(v208) = *(_DWORD *)(a3 + 2568);
        *(_QWORD *)(a3 + 2560) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 80);
        LODWORD(v208) = *(_DWORD *)(a3 + 2576);
        *(_DWORD *)(a3 + 2568) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 84);
        LODWORD(v208) = *(_DWORD *)(a3 + 2596);
        *(_DWORD *)(a3 + 2576) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 88);
        LODWORD(v208) = *(_DWORD *)(a3 + 2600);
        *(_DWORD *)(a3 + 2596) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 92);
        LODWORD(v208) = *(_DWORD *)(a3 + 3316);
        *(_DWORD *)(a3 + 2600) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 176);
        LODWORD(v208) = *(_DWORD *)(a3 + 3320);
        *(_DWORD *)(a3 + 3316) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 180);
        LODWORD(v208) = *(_DWORD *)(a3 + 3324);
        *(_DWORD *)(a3 + 3320) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 184);
        LODWORD(v208) = *(_DWORD *)(a3 + 4112);
        *(_DWORD *)(a3 + 3324) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 548);
        LODWORD(v208) = *(_DWORD *)(a3 + 3328);
        *(_DWORD *)(a3 + 4112) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 188);
        LODWORD(v208) = *(_DWORD *)(a3 + 3332);
        *(_DWORD *)(a3 + 3328) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 192);
        LODWORD(v208) = *(_DWORD *)(a3 + 3336);
        *(_DWORD *)(a3 + 3332) = v209;
        LODWORD(v209) = v208 + *(_DWORD *)(v18 + 196);
        v210 = *(_QWORD *)(a3 + 4056);
        *(_DWORD *)(a3 + 3336) = v209;
        v211 = v210 + *(_QWORD *)(v18 + 456);
        v212 = *(_QWORD *)(a3 + 4064);
        *(_QWORD *)(a3 + 4056) = v211;
        v213 = v212 + *(_QWORD *)(v18 + 464);
        LODWORD(v212) = *(_DWORD *)(a3 + 4088);
        *(_QWORD *)(a3 + 4064) = v213;
        *(_QWORD *)(a3 + 4080) = *(_QWORD *)(v18 + 472);
        *(_DWORD *)(a3 + 4088) = v212 + *(_DWORD *)(v18 + 544);
        do
        {
          *(_DWORD *)(a3 + 3804 + v115) += *(_DWORD *)(v17 + v115);
          v115 += 4;
        }
        while ( v115 != 252 );
        ++v12;
        v14 += 3256;
        v15 += 3256;
        v16 += 3256;
        v17 += 3256;
        *(_DWORD *)(a3 + 4188) += *(_DWORD *)(v18 + 552);
        *(_DWORD *)(a3 + 4192) += *(_DWORD *)(v18 + 556);
        *(_DWORD *)(a3 + 4196) += *(_DWORD *)(v18 + 560);
        *(_DWORD *)(a3 + 4200) += *(_DWORD *)(v18 + 564);
        *(_DWORD *)(a3 + 4204) += *(_DWORD *)(v18 + 568);
        *(_DWORD *)(a3 + 4208) += *(_DWORD *)(v18 + 572);
        *(_DWORD *)(a3 + 4212) += *(_DWORD *)(v18 + 576);
        *(_DWORD *)(a3 + 4216) += *(_DWORD *)(v18 + 580);
        *(_DWORD *)(a3 + 4220) += *(_DWORD *)(v18 + 584);
        *(_DWORD *)(a3 + 4224) += *(_DWORD *)(v18 + 588);
        *(_DWORD *)(a3 + 4228) += *(_DWORD *)(v18 + 592);
        *(_DWORD *)(a3 + 4232) += *(_DWORD *)(v18 + 596);
        *(_DWORD *)(a3 + 4236) += *(_DWORD *)(v18 + 600);
        *(_DWORD *)(a3 + 4240) += *(_DWORD *)(v18 + 604);
        *(_QWORD *)(a3 + 4976) += *(_QWORD *)(v18 + 784);
        *(_QWORD *)(a3 + 4984) += *(_QWORD *)(v18 + 792);
        *(_QWORD *)(a3 + 5064) += *(_QWORD *)(v18 + 992);
        *(_QWORD *)(a3 + 5072) += *(_QWORD *)(v18 + 1000);
        *(_QWORD *)(a3 + 4992) += *(_QWORD *)(v18 + 800);
        *(_QWORD *)(a3 + 5000) += *(_QWORD *)(v18 + 808);
        *(_QWORD *)(a3 + 4960) += *(_QWORD *)(v18 + 768);
        *(_QWORD *)(a3 + 4968) += *(_QWORD *)(v18 + 776);
        *(_QWORD *)(a3 + 5008) += *(_QWORD *)(v18 + 816);
        *(_QWORD *)(a3 + 5016) += *(_QWORD *)(v18 + 824);
        *(_DWORD *)(a3 + 5024) += *(_DWORD *)(v18 + 832);
        *(_DWORD *)(a3 + 6100) += *(_DWORD *)(v18 + 1008);
        *(_QWORD *)(a3 + 5032) += *(_QWORD *)(v18 + 840);
        *(_QWORD *)(a3 + 5040) += *(_QWORD *)(v18 + 848);
        *(_QWORD *)(a3 + 5048) += *(_QWORD *)(v18 + 856);
        *(_QWORD *)(a3 + 5056) += *(_QWORD *)(v18 + 864);
        *(_QWORD *)(a3 + 5088) += *(_QWORD *)(v18 + 880);
        *(_QWORD *)(a3 + 5096) += *(_QWORD *)(v18 + 888);
        *(_QWORD *)(a3 + 5104) += *(_QWORD *)(v18 + 896);
        *(_QWORD *)(a3 + 5112) += *(_QWORD *)(v18 + 904);
        *(_DWORD *)(a3 + 5120) += *(_DWORD *)(v18 + 912);
        *(_DWORD *)(a3 + 5128) += *(_DWORD *)(v18 + 920);
        *(_DWORD *)(a3 + 5132) += *(_DWORD *)(v18 + 924);
        *(_DWORD *)(a3 + 5136) += *(_DWORD *)(v18 + 928);
        *(_DWORD *)(a3 + 5140) += *(_DWORD *)(v18 + 932);
        *(_DWORD *)(a3 + 5144) += *(_DWORD *)(v18 + 936);
        *(_DWORD *)(a3 + 5148) += *(_DWORD *)(v18 + 940);
        *(_DWORD *)(a3 + 5152) += *(_DWORD *)(v18 + 944);
        *(_DWORD *)(a3 + 5896) += *(_DWORD *)(v18 + 948);
        *(_DWORD *)(a3 + 5900) += *(_DWORD *)(v18 + 952);
        *(_DWORD *)(a3 + 5960) += *(_DWORD *)(v18 + 956);
        *(_DWORD *)(a3 + 6004) += *(_DWORD *)(v18 + 960);
        *(_DWORD *)(a3 + 6008) += *(_DWORD *)(v18 + 964);
        *(_DWORD *)(a3 + 6012) += *(_DWORD *)(v18 + 968);
        *(_QWORD *)(a3 + 6080) += *(_QWORD *)(v18 + 976);
        *(_QWORD *)(a3 + 6088) += *(_QWORD *)(v18 + 984);
        *(_QWORD *)(a3 + 5080) = *(_QWORD *)(v18 + 872);
        *(_DWORD *)(a3 + 6112) += *(_DWORD *)(v18 + 1032);
        *(_QWORD *)(a3 + 4784) += *(_QWORD *)(v18 + 608);
        *(_QWORD *)(a3 + 4792) += *(_QWORD *)(v18 + 616);
        v214 = *(_QWORD *)(a3 + 4912) + *(_QWORD *)(v18 + 608);
        v215 = *(_QWORD *)(a3 + 4920);
        *(_QWORD *)(a3 + 4912) = v214;
        v216 = v215 + *(_QWORD *)(v18 + 616);
        v217 = *(_QWORD *)(a3 + 4800);
        *(_QWORD *)(a3 + 4920) = v216;
        *(_QWORD *)(a3 + 4800) = v217 + *(_QWORD *)(v18 + 624);
        *(_QWORD *)(a3 + 4808) += *(_QWORD *)(v18 + 632);
        v218 = v214 + *(_QWORD *)(v18 + 624);
        *(_QWORD *)(a3 + 4912) = v218;
        v219 = v216 + *(_QWORD *)(v18 + 632);
        v220 = *(_QWORD *)(a3 + 4816);
        *(_QWORD *)(a3 + 4920) = v219;
        *(_QWORD *)(a3 + 4816) = v220 + *(_QWORD *)(v18 + 640);
        *(_QWORD *)(a3 + 4824) += *(_QWORD *)(v18 + 648);
        v221 = v218 + *(_QWORD *)(v18 + 640);
        *(_QWORD *)(a3 + 4912) = v221;
        v222 = v219 + *(_QWORD *)(v18 + 648);
        v223 = *(_QWORD *)(a3 + 4832);
        *(_QWORD *)(a3 + 4920) = v222;
        *(_QWORD *)(a3 + 4832) = v223 + *(_QWORD *)(v18 + 656);
        *(_QWORD *)(a3 + 4840) += *(_QWORD *)(v18 + 664);
        v224 = v221 + *(_QWORD *)(v18 + 656);
        *(_QWORD *)(a3 + 4912) = v224;
        v225 = v222 + *(_QWORD *)(v18 + 664);
        v226 = *(_QWORD *)(a3 + 4848);
        *(_QWORD *)(a3 + 4920) = v225;
        *(_QWORD *)(a3 + 4848) = v226 + *(_QWORD *)(v18 + 672);
        *(_QWORD *)(a3 + 4856) += *(_QWORD *)(v18 + 680);
        v227 = v224 + *(_QWORD *)(v18 + 672);
        *(_QWORD *)(a3 + 4912) = v227;
        v228 = v225 + *(_QWORD *)(v18 + 680);
        v229 = *(_QWORD *)(a3 + 4864);
        *(_QWORD *)(a3 + 4920) = v228;
        *(_QWORD *)(a3 + 4864) = v229 + *(_QWORD *)(v18 + 688);
        *(_QWORD *)(a3 + 4872) += *(_QWORD *)(v18 + 696);
        v230 = v227 + *(_QWORD *)(v18 + 688);
        *(_QWORD *)(a3 + 4912) = v230;
        v231 = v228 + *(_QWORD *)(v18 + 696);
        v232 = *(_QWORD *)(a3 + 4880);
        *(_QWORD *)(a3 + 4920) = v231;
        *(_QWORD *)(a3 + 4880) = v232 + *(_QWORD *)(v18 + 704);
        *(_QWORD *)(a3 + 4888) += *(_QWORD *)(v18 + 712);
        v233 = v230 + *(_QWORD *)(v18 + 704);
        *(_QWORD *)(a3 + 4912) = v233;
        v234 = v231 + *(_QWORD *)(v18 + 712);
        v235 = *(_QWORD *)(a3 + 4896);
        *(_QWORD *)(a3 + 4920) = v234;
        *(_QWORD *)(a3 + 4896) = v235 + *(_QWORD *)(v18 + 720);
        *(_QWORD *)(a3 + 4904) += *(_QWORD *)(v18 + 728);
        *(_QWORD *)(a3 + 4912) = v233 + *(_QWORD *)(v18 + 720);
        *(_QWORD *)(a3 + 4920) = v234 + *(_QWORD *)(v18 + 728);
        *(_QWORD *)(a3 + 4928) += *(_QWORD *)(v18 + 736);
        *(_QWORD *)(a3 + 4936) += *(_QWORD *)(v18 + 744);
        *(_QWORD *)(a3 + 4944) += *(_QWORD *)(v18 + 752);
        *(_QWORD *)(a3 + 4952) += *(_QWORD *)(v18 + 760);
        *(_QWORD *)(a3 + 6152) += *(_QWORD *)(v18 + 1016);
        *(_QWORD *)(a3 + 6160) += *(_QWORD *)(v18 + 1024);
        *(_QWORD *)(a3 + 3120) += *(unsigned int *)(v18 + 100);
        *(_QWORD *)(a3 + 3128) += *(_QWORD *)(v18 + 160);
        *(_DWORD *)(a3 + 3136) += *(_DWORD *)(v18 + 108);
        *(_QWORD *)(a3 + 3144) += *(unsigned int *)(v18 + 104);
        *(_QWORD *)(a3 + 3152) += *(_QWORD *)(v18 + 168);
        *(_DWORD *)(a3 + 3160) += *(_DWORD *)(v18 + 112);
        *(_DWORD *)(a3 + 3164) += *(_DWORD *)(v18 + 116);
        *(_DWORD *)(a3 + 3168) += *(_DWORD *)(v18 + 120);
        *(_DWORD *)(a3 + 3172) += *(_DWORD *)(v18 + 124);
        *(_DWORD *)(a3 + 3176) += *(_DWORD *)(v18 + 128);
        *(_DWORD *)(a3 + 3180) += *(_DWORD *)(v18 + 132);
        *(_DWORD *)(a3 + 3184) += *(_DWORD *)(v18 + 136);
        *(_DWORD *)(a3 + 3188) += *(_DWORD *)(v18 + 140);
        *(_DWORD *)(a3 + 3192) += *(_DWORD *)(v18 + 144);
        *(_DWORD *)(a3 + 3196) += *(_DWORD *)(v18 + 148);
        *(_DWORD *)(a3 + 3200) += *(_DWORD *)(v18 + 156);
      }
      while ( v12 != v6 );
    }
  }
  return raw_spin_unlock(a2 + 18);
}
