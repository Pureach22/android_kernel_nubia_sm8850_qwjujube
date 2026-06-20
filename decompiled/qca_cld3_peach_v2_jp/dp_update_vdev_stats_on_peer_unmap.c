__int64 __fastcall dp_update_vdev_stats_on_peer_unmap(__int64 result, __int64 *a2)
{
  __int64 v2; // x3
  __int64 v3; // x10
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x9
  __int64 v10; // x11
  __int64 v11; // x17
  __int64 v12; // x1
  __int64 v13; // x2
  __int64 v14; // x3
  __int64 v15; // x6
  __int64 v16; // x7
  int v17; // w20
  int v18; // w19
  int v19; // w20
  int v20; // w19
  int v21; // w20
  int v22; // w19
  int v23; // w20
  int v24; // w19
  int v25; // w20
  int v26; // w19
  int v27; // w20
  int v28; // w19
  int v29; // w20
  int v30; // w19
  int v31; // w20
  int v32; // w19
  int v33; // w20
  int v34; // w19
  int v35; // w20
  unsigned int v36; // w20
  unsigned int v37; // w20
  unsigned int v38; // w20
  unsigned int v39; // w20
  int v40; // w20
  _DWORD *v41; // x19
  _DWORD *v42; // x20
  int v43; // w23
  int v44; // w23
  int v45; // w23
  int v46; // w23
  int v47; // w23
  int v48; // w23
  int v49; // w23
  __int64 v50; // x7
  __int64 v51; // x20
  __int64 v52; // x19
  __int64 v53; // x20
  __int64 v54; // x19
  __int64 v55; // x20
  __int64 v56; // x19
  __int64 v57; // x20
  __int64 v58; // x19
  __int64 v59; // x7
  int v60; // w21
  __int64 v61; // x20
  __int64 v62; // x19
  __int64 v63; // x20
  __int64 v64; // x19
  __int64 v65; // x20
  __int64 v66; // x19
  __int64 v67; // x20
  __int64 v68; // x19
  __int64 v69; // x20
  __int64 v70; // x19
  __int64 v71; // x20
  __int64 v72; // x19
  unsigned int v73; // w21
  unsigned int v74; // w21
  unsigned int v75; // w21
  unsigned int v76; // w21
  _DWORD *v77; // x19
  _DWORD *v78; // x20
  int v79; // w23
  int v80; // w23
  int v81; // w23
  int v82; // w23
  int v83; // w23
  int v84; // w23
  int v85; // w23
  __int64 v86; // x7
  __int64 v87; // x20
  __int64 v88; // x19
  __int64 v89; // x20
  __int64 v90; // x19
  __int64 v91; // x20
  __int64 v92; // x19
  __int64 v93; // x20
  __int64 v94; // x19
  char v95; // w20
  __int64 v96; // x7
  _DWORD *v97; // x21
  _DWORD *v98; // x7
  int v99; // w24
  int v100; // w24
  int v101; // w24
  int v102; // w24
  int v103; // w24
  int v104; // w24
  int v105; // w24
  int v106; // w24
  int v107; // w24
  int v108; // w24
  int v109; // w24
  int v110; // w24
  char v111; // w23
  __int64 v112; // x7
  int v113; // w20
  int v114; // w19
  int v115; // w20
  int v116; // w19
  int v117; // w20
  int v118; // w19
  int v119; // w20
  int v120; // w19
  int v121; // w20
  int v122; // w19
  int v123; // w20
  int v124; // w19
  int v125; // w20
  int v126; // w19
  int v127; // w20
  int v128; // w19
  int v129; // w20
  int v130; // w19
  int v131; // w20
  int v132; // w19
  int v133; // w20
  int v134; // w19
  int v135; // w20
  int v136; // w19
  int v137; // w20
  int v138; // w19
  int v139; // w20
  int v140; // w19
  int v141; // w20
  int v142; // w19
  int v143; // w20
  int v144; // w19
  int v145; // w20
  int v146; // w19
  int v147; // w20
  int v148; // w19
  int v149; // w20
  int v150; // w19
  int v151; // w20
  int v152; // w19
  int v153; // w20
  int v154; // w19
  int v155; // w20
  int v156; // w19
  int v157; // w20
  int v158; // w19
  int v159; // w20
  int v160; // w19
  int v161; // w20
  int v162; // w19
  int v163; // w20
  int v164; // w19
  int v165; // w20
  int v166; // w19
  int v167; // w20
  int v168; // w19
  int v169; // w20
  int v170; // w19
  int v171; // w20
  int v172; // w19
  int v173; // w20
  int v174; // w19
  int v175; // w20
  int v176; // w19
  int v177; // w20
  int v178; // w19
  int v179; // w20
  int v180; // w19
  int v181; // w20
  int v182; // w19
  int v183; // w20
  int v184; // w19
  __int64 v185; // x20
  __int64 v186; // x19
  __int64 v187; // x20
  __int64 v188; // x19
  __int64 v189; // x20
  __int64 v190; // x19
  __int64 v191; // x20
  __int64 v192; // x19
  __int64 v193; // x20
  __int64 v194; // x19
  __int64 v195; // x20
  __int64 v196; // x19
  __int64 v197; // x20
  __int64 v198; // x19
  __int64 v199; // x20
  __int64 v200; // x19
  __int64 v201; // x20
  __int64 v202; // x19
  __int64 v203; // x20
  __int64 v204; // x19
  __int64 v205; // x20
  __int64 v206; // x19
  __int64 v207; // x20
  __int64 v208; // x19
  __int64 v209; // x20
  __int64 v210; // x19
  __int64 v211; // x7
  __int64 v212; // x19
  __int64 v213; // x19
  __int64 v214; // x20
  __int64 v215; // x7
  __int64 v216; // x19
  __int64 v217; // x20
  __int64 v218; // x7
  __int64 v219; // x19
  __int64 v220; // x20
  __int64 v221; // x7
  __int64 v222; // x19
  __int64 v223; // x20
  __int64 v224; // x7
  __int64 v225; // x19
  __int64 v226; // x20
  __int64 v227; // x7
  __int64 v228; // x19
  __int64 v229; // x20
  __int64 v230; // x7
  __int64 v231; // x19
  __int64 v232; // x20

  v2 = *a2;
  if ( *a2 )
  {
    v3 = *(_QWORD *)(result + 2880);
    v4 = *(unsigned __int8 *)(v2 + 2221);
    *(_QWORD *)(result + 2872) += *(_QWORD *)(v2 + 16);
    v5 = v3 + *(_QWORD *)(v2 + 24);
    LODWORD(v3) = *(_DWORD *)(result + 2972);
    *(_QWORD *)(result + 2880) = v5;
    LODWORD(v5) = v3 + *(_DWORD *)(v2 + 12);
    v6 = *(_QWORD *)(result + 5168);
    *(_DWORD *)(result + 2972) = v5;
    v7 = v6 + *(_QWORD *)(v2 + 32);
    v8 = *(_QWORD *)(result + 5176);
    *(_QWORD *)(result + 5168) = v7;
    *(_QWORD *)(result + 5176) = v8 + *(_QWORD *)(v2 + 40);
    if ( v4 )
    {
      v9 = 0;
      v10 = v2 + 2224;
      v11 = v2 + 3332;
      v12 = v2 + 3952;
      v13 = v2 + 4408;
      v14 = v2 + 2424;
      do
      {
        v15 = v10 + 3256 * v9;
        v16 = 0;
        v17 = *(_DWORD *)(result + 2984);
        *(_DWORD *)(result + 2980) += *(_DWORD *)(v15 + 1040);
        v18 = v17 + *(_DWORD *)(v15 + 1044);
        v19 = *(_DWORD *)(result + 2988);
        *(_DWORD *)(result + 2984) = v18;
        v20 = v19 + *(_DWORD *)(v15 + 1048);
        v21 = *(_DWORD *)(result + 3708);
        *(_DWORD *)(result + 2988) = v20;
        v22 = v21 + *(_DWORD *)(v15 + 1384);
        v23 = *(_DWORD *)(result + 3712);
        *(_DWORD *)(result + 3708) = v22;
        v24 = v23 + *(_DWORD *)(v15 + 1388);
        v25 = *(_DWORD *)(result + 4200);
        *(_DWORD *)(result + 3712) = v24;
        v26 = v25 + *(_DWORD *)(v15 + 1392);
        v27 = *(_DWORD *)(result + 3744);
        *(_DWORD *)(result + 4200) = v26;
        v28 = v27 + *(_DWORD *)(v15 + 1396);
        v29 = *(_DWORD *)(result + 3748);
        *(_DWORD *)(result + 3744) = v28;
        v30 = v29 + *(_DWORD *)(v15 + 1400);
        v31 = *(_DWORD *)(result + 3752);
        *(_DWORD *)(result + 3748) = v30;
        v32 = v31 + *(_DWORD *)(v15 + 1404);
        v33 = *(_DWORD *)(result + 3400);
        *(_DWORD *)(result + 3752) = v32;
        *(_DWORD *)(result + 3004) = *(_DWORD *)(v15 + 1408);
        *(_DWORD *)(result + 3008) = *(_DWORD *)(v15 + 1412);
        *(_DWORD *)(result + 3012) = *(_DWORD *)(v15 + 1416);
        *(_DWORD *)(result + 3016) = *(_DWORD *)(v15 + 1420);
        *(_DWORD *)(result + 3020) = *(_DWORD *)(v15 + 1424);
        *(_QWORD *)(result + 3032) = *(_QWORD *)(v15 + 1432);
        *(_QWORD *)(result + 3040) = *(_QWORD *)(v15 + 1440);
        *(_WORD *)(result + 3704) = *(_WORD *)(v15 + 1448);
        v34 = v33 + *(_DWORD *)(v15 + 1472);
        v35 = *(_DWORD *)(result + 4472);
        *(_DWORD *)(result + 3400) = v34;
        *(_DWORD *)(result + 4120) = *(_DWORD *)(v15 + 1540);
        *(_DWORD *)(result + 4124) = *(_DWORD *)(v15 + 1544);
        *(_DWORD *)(result + 3048) = *(_DWORD *)(v15 + 1984);
        *(_DWORD *)(result + 3052) = *(_DWORD *)(v15 + 1988);
        v36 = v35 & 0xFFFFFFF0 | *(_DWORD *)(v15 + 1996) & 0xF;
        *(_DWORD *)(result + 4472) = v36;
        v37 = v36 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v15 + 1996) >> 4) & 0xF));
        *(_DWORD *)(result + 4472) = v37;
        v38 = v37 & 0xFFFFF0FF | (((*(_DWORD *)(v15 + 1996) >> 8) & 0xF) << 8);
        *(_DWORD *)(result + 4472) = v38;
        v39 = v38 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v15 + 1996)) >> 4 << 12);
        *(_DWORD *)(result + 4472) = v39;
        *(_DWORD *)(result + 4472) = v39 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v15 + 1996)) & 0xF) << 16);
        v40 = *(_DWORD *)(result + 4476);
        *(_DWORD *)(result + 2992) += *(_DWORD *)(v15 + 2000);
        *(_DWORD *)(result + 4476) = v40 + *(_DWORD *)(v15 + 2004);
        *(_DWORD *)(result + 4496) = *(_DWORD *)(v15 + 2040);
        *(_DWORD *)(result + 4500) = *(_DWORD *)(v15 + 2044);
        *(_DWORD *)(result + 4504) = *(_DWORD *)(v15 + 2048);
        *(_DWORD *)(result + 4508) = *(_DWORD *)(v15 + 2052);
        do
        {
          v41 = (_DWORD *)(result + 3080 + v16);
          v42 = (_DWORD *)(v11 + v16);
          v16 += 60;
          v43 = v41[1];
          *v41 += *(v42 - 14);
          v41[1] = v43 + *(v42 - 13);
          v44 = v41[3];
          v41[2] += *(v42 - 12);
          v41[3] = v44 + *(v42 - 11);
          v45 = v41[5];
          v41[4] += *(v42 - 10);
          v41[5] = v45 + *(v42 - 9);
          v46 = v41[7];
          v41[6] += *(v42 - 8);
          v41[7] = v46 + *(v42 - 7);
          v47 = v41[9];
          v41[8] += *(v42 - 6);
          v41[9] = v47 + *(v42 - 5);
          v48 = v41[11];
          v41[10] += *(v42 - 4);
          v41[11] = v48 + *(v42 - 3);
          v49 = v41[13];
          v41[12] += *(v42 - 2);
          v41[13] = v49 + *(v42 - 1);
          v41[14] += *v42;
        }
        while ( v16 != 300 );
        v50 = 0;
        v51 = *(_QWORD *)(result + 4520);
        *(_DWORD *)(result + 3468) += *(_DWORD *)(v15 + 1352);
        v52 = v51 + *(_QWORD *)(v15 + 2088);
        LODWORD(v51) = *(_DWORD *)(result + 3484);
        *(_QWORD *)(result + 4520) = v52;
        LODWORD(v52) = v51 + *(_DWORD *)(v15 + 1368);
        LODWORD(v51) = *(_DWORD *)(result + 3472);
        *(_DWORD *)(result + 3484) = v52;
        LODWORD(v52) = v51 + *(_DWORD *)(v15 + 1356);
        v53 = *(_QWORD *)(result + 4528);
        *(_DWORD *)(result + 3472) = v52;
        v54 = v53 + *(_QWORD *)(v15 + 2096);
        LODWORD(v53) = *(_DWORD *)(result + 3488);
        *(_QWORD *)(result + 4528) = v54;
        LODWORD(v54) = v53 + *(_DWORD *)(v15 + 1372);
        LODWORD(v53) = *(_DWORD *)(result + 3476);
        *(_DWORD *)(result + 3488) = v54;
        LODWORD(v54) = v53 + *(_DWORD *)(v15 + 1360);
        v55 = *(_QWORD *)(result + 4536);
        *(_DWORD *)(result + 3476) = v54;
        v56 = v55 + *(_QWORD *)(v15 + 2104);
        LODWORD(v55) = *(_DWORD *)(result + 3492);
        *(_QWORD *)(result + 4536) = v56;
        LODWORD(v56) = v55 + *(_DWORD *)(v15 + 1376);
        LODWORD(v55) = *(_DWORD *)(result + 3480);
        *(_DWORD *)(result + 3492) = v56;
        LODWORD(v56) = v55 + *(_DWORD *)(v15 + 1364);
        v57 = *(_QWORD *)(result + 4544);
        *(_DWORD *)(result + 3480) = v56;
        v58 = v57 + *(_QWORD *)(v15 + 2112);
        LODWORD(v57) = *(_DWORD *)(result + 3496);
        *(_QWORD *)(result + 4544) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1380);
        LODWORD(v57) = *(_DWORD *)(result + 3380);
        *(_DWORD *)(result + 3496) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1452);
        LODWORD(v57) = *(_DWORD *)(result + 3384);
        *(_DWORD *)(result + 3380) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1456);
        LODWORD(v57) = *(_DWORD *)(result + 3388);
        *(_DWORD *)(result + 3384) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1460);
        LODWORD(v57) = *(_DWORD *)(result + 3392);
        *(_DWORD *)(result + 3388) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1464);
        LODWORD(v57) = *(_DWORD *)(result + 3396);
        *(_DWORD *)(result + 3392) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1468);
        LODWORD(v57) = *(_DWORD *)(result + 3404);
        *(_DWORD *)(result + 3396) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1476);
        LODWORD(v57) = *(_DWORD *)(result + 3408);
        *(_DWORD *)(result + 3404) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1480);
        LODWORD(v57) = *(_DWORD *)(result + 3412);
        *(_DWORD *)(result + 3408) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1484);
        LODWORD(v57) = *(_DWORD *)(result + 3416);
        *(_DWORD *)(result + 3412) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1488);
        LODWORD(v57) = *(_DWORD *)(result + 3420);
        *(_DWORD *)(result + 3416) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1492);
        LODWORD(v57) = *(_DWORD *)(result + 3424);
        *(_DWORD *)(result + 3420) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1496);
        LODWORD(v57) = *(_DWORD *)(result + 3428);
        *(_DWORD *)(result + 3424) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1500);
        LODWORD(v57) = *(_DWORD *)(result + 3432);
        *(_DWORD *)(result + 3428) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1504);
        LODWORD(v57) = *(_DWORD *)(result + 3436);
        *(_DWORD *)(result + 3432) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1508);
        LODWORD(v57) = *(_DWORD *)(result + 3440);
        *(_DWORD *)(result + 3436) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1512);
        LODWORD(v57) = *(_DWORD *)(result + 3444);
        *(_DWORD *)(result + 3440) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1516);
        LODWORD(v57) = *(_DWORD *)(result + 3448);
        *(_DWORD *)(result + 3444) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1520);
        LODWORD(v57) = *(_DWORD *)(result + 3452);
        *(_DWORD *)(result + 3448) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1524);
        LODWORD(v57) = *(_DWORD *)(result + 3456);
        *(_DWORD *)(result + 3452) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1528);
        LODWORD(v57) = *(_DWORD *)(result + 3460);
        *(_DWORD *)(result + 3456) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1532);
        LODWORD(v57) = *(_DWORD *)(result + 3464);
        *(_DWORD *)(result + 3460) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1536);
        LODWORD(v57) = *(_DWORD *)(result + 4128);
        *(_DWORD *)(result + 3464) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1548);
        LODWORD(v57) = *(_DWORD *)(result + 4132);
        *(_DWORD *)(result + 4128) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1552);
        LODWORD(v57) = *(_DWORD *)(result + 4136);
        *(_DWORD *)(result + 4132) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1556);
        LODWORD(v57) = *(_DWORD *)(result + 4140);
        *(_DWORD *)(result + 4136) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1560);
        LODWORD(v57) = *(_DWORD *)(result + 4144);
        *(_DWORD *)(result + 4140) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1564);
        LODWORD(v57) = *(_DWORD *)(result + 4148);
        *(_DWORD *)(result + 4144) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1568);
        LODWORD(v57) = *(_DWORD *)(result + 4152);
        *(_DWORD *)(result + 4148) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1572);
        LODWORD(v57) = *(_DWORD *)(result + 4156);
        *(_DWORD *)(result + 4152) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1576);
        LODWORD(v57) = *(_DWORD *)(result + 4160);
        *(_DWORD *)(result + 4156) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1580);
        LODWORD(v57) = *(_DWORD *)(result + 4164);
        *(_DWORD *)(result + 4160) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1584);
        LODWORD(v57) = *(_DWORD *)(result + 4168);
        *(_DWORD *)(result + 4164) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1588);
        LODWORD(v57) = *(_DWORD *)(result + 4172);
        *(_DWORD *)(result + 4168) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1592);
        LODWORD(v57) = *(_DWORD *)(result + 4176);
        *(_DWORD *)(result + 4172) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1596);
        LODWORD(v57) = *(_DWORD *)(result + 4180);
        *(_DWORD *)(result + 4176) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1600);
        LODWORD(v57) = *(_DWORD *)(result + 4184);
        *(_DWORD *)(result + 4180) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1604);
        LODWORD(v57) = *(_DWORD *)(result + 4188);
        *(_DWORD *)(result + 4184) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1608);
        LODWORD(v57) = *(_DWORD *)(result + 4192);
        *(_DWORD *)(result + 4188) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1612);
        LODWORD(v57) = *(_DWORD *)(result + 4196);
        *(_DWORD *)(result + 4192) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1616);
        LODWORD(v57) = *(_DWORD *)(result + 3756);
        *(_DWORD *)(result + 4196) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1620);
        LODWORD(v57) = *(_DWORD *)(result + 3760);
        *(_DWORD *)(result + 3756) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1624);
        LODWORD(v57) = *(_DWORD *)(result + 3764);
        *(_DWORD *)(result + 3760) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1628);
        LODWORD(v57) = *(_DWORD *)(result + 3768);
        *(_DWORD *)(result + 3764) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1632);
        LODWORD(v57) = *(_DWORD *)(result + 3772);
        *(_DWORD *)(result + 3768) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1636);
        LODWORD(v57) = *(_DWORD *)(result + 3776);
        *(_DWORD *)(result + 3772) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1640);
        LODWORD(v57) = *(_DWORD *)(result + 3780);
        *(_DWORD *)(result + 3776) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1644);
        LODWORD(v57) = *(_DWORD *)(result + 3784);
        *(_DWORD *)(result + 3780) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1648);
        LODWORD(v57) = *(_DWORD *)(result + 3788);
        *(_DWORD *)(result + 3784) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1652);
        LODWORD(v57) = *(_DWORD *)(result + 3792);
        *(_DWORD *)(result + 3788) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1656);
        LODWORD(v57) = *(_DWORD *)(result + 3796);
        *(_DWORD *)(result + 3792) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1660);
        LODWORD(v57) = *(_DWORD *)(result + 3800);
        *(_DWORD *)(result + 3796) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1664);
        LODWORD(v57) = *(_DWORD *)(result + 3804);
        *(_DWORD *)(result + 3800) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1668);
        LODWORD(v57) = *(_DWORD *)(result + 3808);
        *(_DWORD *)(result + 3804) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1672);
        LODWORD(v57) = *(_DWORD *)(result + 3812);
        *(_DWORD *)(result + 3808) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1676);
        LODWORD(v57) = *(_DWORD *)(result + 3816);
        *(_DWORD *)(result + 3812) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1680);
        LODWORD(v57) = *(_DWORD *)(result + 3820);
        *(_DWORD *)(result + 3816) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1684);
        LODWORD(v57) = *(_DWORD *)(result + 3824);
        *(_DWORD *)(result + 3820) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1688);
        LODWORD(v57) = *(_DWORD *)(result + 3828);
        *(_DWORD *)(result + 3824) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1692);
        LODWORD(v57) = *(_DWORD *)(result + 3832);
        *(_DWORD *)(result + 3828) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1696);
        LODWORD(v57) = *(_DWORD *)(result + 3836);
        *(_DWORD *)(result + 3832) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1700);
        LODWORD(v57) = *(_DWORD *)(result + 3840);
        *(_DWORD *)(result + 3836) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1704);
        LODWORD(v57) = *(_DWORD *)(result + 3844);
        *(_DWORD *)(result + 3840) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1708);
        LODWORD(v57) = *(_DWORD *)(result + 3848);
        *(_DWORD *)(result + 3844) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1712);
        LODWORD(v57) = *(_DWORD *)(result + 3852);
        *(_DWORD *)(result + 3848) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1716);
        LODWORD(v57) = *(_DWORD *)(result + 3856);
        *(_DWORD *)(result + 3852) = v58;
        LODWORD(v58) = v57 + *(_DWORD *)(v15 + 1720);
        LODWORD(v57) = *(_DWORD *)(result + 3860);
        *(_DWORD *)(result + 3856) = v58;
        *(_DWORD *)(result + 3860) = v57 + *(_DWORD *)(v15 + 1724);
        do
        {
          *(_DWORD *)(result + 3864 + v50) = *(_DWORD *)(v12 + v50);
          v50 += 4;
        }
        while ( v50 != 256 );
        v59 = 0;
        v60 = *(_DWORD *)(result + 6476);
        v61 = *(_QWORD *)(result + 4560);
        *(_QWORD *)(result + 4552) += *(_QWORD *)(v15 + 2008);
        v62 = v61 + *(_QWORD *)(v15 + 2016);
        v63 = *(_QWORD *)(result + 4568);
        *(_QWORD *)(result + 4560) = v62;
        v64 = v63 + *(_QWORD *)(v15 + 2024);
        v65 = *(_QWORD *)(result + 4576);
        *(_QWORD *)(result + 4568) = v64;
        v66 = v65 + *(_QWORD *)(v15 + 2032);
        v67 = *(_QWORD *)(result + 5160);
        *(_QWORD *)(result + 4576) = v66;
        *(_DWORD *)(result + 3644) = *(_DWORD *)(v15 + 2056);
        *(_DWORD *)(result + 3648) = *(_DWORD *)(v15 + 2060);
        *(_DWORD *)(result + 3652) = *(_DWORD *)(v15 + 2064);
        *(_DWORD *)(result + 3656) = *(_DWORD *)(v15 + 2068);
        *(_DWORD *)(result + 3660) = *(_DWORD *)(v15 + 2072);
        *(_DWORD *)(result + 3664) = *(_DWORD *)(v15 + 2076);
        *(_DWORD *)(result + 3668) = *(_DWORD *)(v15 + 2080);
        *(_DWORD *)(result + 3672) = *(_DWORD *)(v15 + 2084);
        v68 = v67 + *(_QWORD *)(v15 + 2120);
        LODWORD(v67) = *(_DWORD *)(result + 5972);
        *(_QWORD *)(result + 5160) = v68;
        LODWORD(v68) = v67 + *(_DWORD *)(v15 + 2444);
        LODWORD(v67) = *(_DWORD *)(result + 5976);
        *(_DWORD *)(result + 5972) = v68;
        LODWORD(v68) = v67 + *(_DWORD *)(v15 + 2448);
        v69 = *(_QWORD *)(result + 6552);
        *(_DWORD *)(result + 5976) = v68;
        v70 = v69 + *(_QWORD *)(v15 + 3040);
        v71 = *(_QWORD *)(result + 6560);
        *(_QWORD *)(result + 6552) = v70;
        v72 = v71 + *(_QWORD *)(v15 + 3048);
        LODWORD(v71) = *(_DWORD *)(result + 6288);
        *(_QWORD *)(result + 6560) = v72;
        LODWORD(v72) = v71 + *(_DWORD *)(v15 + 2452);
        LODWORD(v71) = *(_DWORD *)(result + 6292);
        *(_DWORD *)(result + 6288) = v72;
        LODWORD(v72) = v71 + *(_DWORD *)(v15 + 2456);
        LODWORD(v71) = *(_DWORD *)(result + 6364);
        *(_DWORD *)(result + 6292) = v72;
        LODWORD(v72) = v71 + *(_DWORD *)(v15 + 2460);
        LODWORD(v71) = *(_DWORD *)(result + 6368);
        *(_DWORD *)(result + 6364) = v72;
        LODWORD(v72) = v71 + *(_DWORD *)(v15 + 2464);
        LODWORD(v71) = *(_DWORD *)(result + 6584);
        *(_DWORD *)(result + 6368) = v72;
        *(_DWORD *)(result + 6312) = *(_DWORD *)(v15 + 2936);
        *(_DWORD *)(result + 6316) = *(_DWORD *)(v15 + 2940);
        *(_DWORD *)(result + 6320) = *(_DWORD *)(v15 + 2944);
        *(_DWORD *)(result + 6324) = *(_DWORD *)(v15 + 2948);
        *(_DWORD *)(result + 6380) = *(_DWORD *)(v15 + 2952);
        *(_DWORD *)(result + 6308) = *(_DWORD *)(v15 + 2956);
        *(_QWORD *)(result + 6392) = *(_QWORD *)(v15 + 2960);
        *(_DWORD *)(result + 6584) = v71 + *(_DWORD *)(v15 + 3032);
        *(_BYTE *)(result + 6400) = *(_BYTE *)(v15 + 2968);
        *(_BYTE *)(result + 6401) = *(_BYTE *)(v15 + 2969);
        v73 = v60 & 0xFFFFFFF0 | *(_DWORD *)(v15 + 2970) & 0xF;
        *(_DWORD *)(result + 6476) = v73;
        v74 = v73 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v15 + 2970) >> 4) & 0xF));
        *(_DWORD *)(result + 6476) = v74;
        v75 = v74 & 0xFFFFF0FF | (((*(_DWORD *)(v15 + 2970) >> 8) & 0xF) << 8);
        *(_DWORD *)(result + 6476) = v75;
        v76 = v75 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v15 + 2970)) >> 4 << 12);
        LODWORD(v71) = *(_DWORD *)(result + 6496);
        *(_DWORD *)(result + 6476) = v76;
        *(_DWORD *)(result + 6476) = v76 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v15 + 2970)) & 0xF) << 16);
        *(_DWORD *)(result + 6496) = v71 + *(_DWORD *)(v15 + 2976);
        *(_DWORD *)(result + 6504) = *(_DWORD *)(v15 + 2980);
        *(_DWORD *)(result + 6508) = *(_DWORD *)(v15 + 2984);
        do
        {
          v77 = (_DWORD *)(result + 5588 + v59);
          v78 = (_DWORD *)(v13 + v59);
          v59 += 60;
          v79 = v77[1];
          *v77 += *(v78 - 14);
          v77[1] = v79 + *(v78 - 13);
          v80 = v77[3];
          v77[2] += *(v78 - 12);
          v77[3] = v80 + *(v78 - 11);
          v81 = v77[5];
          v77[4] += *(v78 - 10);
          v77[5] = v81 + *(v78 - 9);
          v82 = v77[7];
          v77[6] += *(v78 - 8);
          v77[7] = v82 + *(v78 - 7);
          v83 = v77[9];
          v77[8] += *(v78 - 6);
          v77[9] = v83 + *(v78 - 5);
          v84 = v77[11];
          v77[10] += *(v78 - 4);
          v77[11] = v84 + *(v78 - 3);
          v85 = v77[13];
          v77[12] += *(v78 - 2);
          v77[13] = v85 + *(v78 - 1);
          v77[14] += *v78;
        }
        while ( v59 != 300 );
        v86 = 0;
        v87 = *(_QWORD *)(result + 6520);
        *(_DWORD *)(result + 5556) += *(_DWORD *)(v15 + 2428);
        v88 = v87 + *(_QWORD *)(v15 + 2992);
        LODWORD(v87) = *(_DWORD *)(result + 5560);
        *(_QWORD *)(result + 6520) = v88;
        LODWORD(v88) = v87 + *(_DWORD *)(v15 + 2432);
        v89 = *(_QWORD *)(result + 6528);
        *(_DWORD *)(result + 5560) = v88;
        v90 = v89 + *(_QWORD *)(v15 + 3000);
        LODWORD(v89) = *(_DWORD *)(result + 5564);
        *(_QWORD *)(result + 6528) = v90;
        LODWORD(v90) = v89 + *(_DWORD *)(v15 + 2436);
        v91 = *(_QWORD *)(result + 6536);
        *(_DWORD *)(result + 5564) = v90;
        v92 = v91 + *(_QWORD *)(v15 + 3008);
        LODWORD(v91) = *(_DWORD *)(result + 5568);
        *(_QWORD *)(result + 6536) = v92;
        LODWORD(v92) = v91 + *(_DWORD *)(v15 + 2440);
        v93 = *(_QWORD *)(result + 6544);
        *(_DWORD *)(result + 5568) = v92;
        v94 = v93 + *(_QWORD *)(v15 + 3016);
        LODWORD(v93) = *(_DWORD *)(result + 5980);
        *(_QWORD *)(result + 6544) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2468);
        LODWORD(v93) = *(_DWORD *)(result + 6416);
        *(_DWORD *)(result + 5980) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2876);
        LODWORD(v93) = *(_DWORD *)(result + 5984);
        *(_DWORD *)(result + 6416) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2472);
        LODWORD(v93) = *(_DWORD *)(result + 6420);
        *(_DWORD *)(result + 5984) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2880);
        LODWORD(v93) = *(_DWORD *)(result + 5988);
        *(_DWORD *)(result + 6420) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2476);
        LODWORD(v93) = *(_DWORD *)(result + 6424);
        *(_DWORD *)(result + 5988) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2884);
        LODWORD(v93) = *(_DWORD *)(result + 5992);
        *(_DWORD *)(result + 6424) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2480);
        LODWORD(v93) = *(_DWORD *)(result + 6428);
        *(_DWORD *)(result + 5992) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2888);
        LODWORD(v93) = *(_DWORD *)(result + 5996);
        *(_DWORD *)(result + 6428) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2484);
        LODWORD(v93) = *(_DWORD *)(result + 6432);
        *(_DWORD *)(result + 5996) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2892);
        LODWORD(v93) = *(_DWORD *)(result + 6000);
        *(_DWORD *)(result + 6432) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2488);
        LODWORD(v93) = *(_DWORD *)(result + 6436);
        *(_DWORD *)(result + 6000) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2896);
        LODWORD(v93) = *(_DWORD *)(result + 6004);
        *(_DWORD *)(result + 6436) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2492);
        LODWORD(v93) = *(_DWORD *)(result + 6440);
        *(_DWORD *)(result + 6004) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2900);
        LODWORD(v93) = *(_DWORD *)(result + 6008);
        *(_DWORD *)(result + 6440) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2496);
        LODWORD(v93) = *(_DWORD *)(result + 6444);
        *(_DWORD *)(result + 6008) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2904);
        LODWORD(v93) = *(_DWORD *)(result + 6012);
        *(_DWORD *)(result + 6444) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2500);
        LODWORD(v93) = *(_DWORD *)(result + 6448);
        *(_DWORD *)(result + 6012) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2908);
        LODWORD(v93) = *(_DWORD *)(result + 6016);
        *(_DWORD *)(result + 6448) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2504);
        LODWORD(v93) = *(_DWORD *)(result + 6452);
        *(_DWORD *)(result + 6016) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2912);
        LODWORD(v93) = *(_DWORD *)(result + 6020);
        *(_DWORD *)(result + 6452) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2508);
        LODWORD(v93) = *(_DWORD *)(result + 6456);
        *(_DWORD *)(result + 6020) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2916);
        LODWORD(v93) = *(_DWORD *)(result + 6024);
        *(_DWORD *)(result + 6456) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2512);
        LODWORD(v93) = *(_DWORD *)(result + 6460);
        *(_DWORD *)(result + 6024) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2920);
        LODWORD(v93) = *(_DWORD *)(result + 6028);
        *(_DWORD *)(result + 6460) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2516);
        LODWORD(v93) = *(_DWORD *)(result + 6464);
        *(_DWORD *)(result + 6028) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2924);
        LODWORD(v93) = *(_DWORD *)(result + 6032);
        *(_DWORD *)(result + 6464) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2520);
        LODWORD(v93) = *(_DWORD *)(result + 6468);
        *(_DWORD *)(result + 6032) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2928);
        LODWORD(v93) = *(_DWORD *)(result + 6036);
        *(_DWORD *)(result + 6468) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2524);
        LODWORD(v93) = *(_DWORD *)(result + 6472);
        *(_DWORD *)(result + 6036) = v94;
        LODWORD(v94) = v93 + *(_DWORD *)(v15 + 2932);
        v95 = 1;
        *(_DWORD *)(result + 6472) = v94;
        do
        {
          v96 = 100 * v86;
          v97 = (_DWORD *)(v15 + 2528 + v96);
          v98 = (_DWORD *)(result + 6056 + v96);
          v99 = v98[9];
          v98[8] += v97[8];
          v98[9] = v99 + v97[9];
          v100 = v98[1];
          *v98 += *v97;
          v98[1] = v100 + v97[1];
          v101 = v98[3];
          v98[2] += v97[2];
          v98[3] = v101 + v97[3];
          v102 = v98[5];
          v98[4] += v97[4];
          v98[5] = v102 + v97[5];
          v103 = v98[7];
          v98[6] += v97[6];
          v98[7] = v103 + v97[7];
          v104 = v98[11];
          v98[10] += v97[10];
          v98[11] = v104 + v97[11];
          v105 = v98[13];
          v98[12] += v97[12];
          v98[13] = v105 + v97[13];
          v106 = v98[15];
          v98[14] += v97[14];
          v98[15] = v106 + v97[15];
          v107 = v98[17];
          v98[16] += v97[16];
          v98[17] = v107 + v97[17];
          v108 = v98[19];
          v98[18] += v97[18];
          v98[19] = v108 + v97[19];
          v109 = v98[21];
          v98[20] += v97[20];
          v98[21] = v109 + v97[21];
          v110 = v98[23];
          v111 = v95;
          v98[22] += v97[22];
          v98[23] = v110 + v97[23];
          v98[24] += v97[24];
          v86 = 1;
          v95 = 0;
        }
        while ( (v111 & 1) != 0 );
        v112 = 0;
        v113 = *(_DWORD *)(result + 6040);
        *(_DWORD *)(result + 5572) += *(_DWORD *)(v15 + 2728);
        v114 = v113 + *(_DWORD *)(v15 + 2744);
        v115 = *(_DWORD *)(result + 5576);
        *(_DWORD *)(result + 6040) = v114;
        v116 = v115 + *(_DWORD *)(v15 + 2732);
        v117 = *(_DWORD *)(result + 6044);
        *(_DWORD *)(result + 5576) = v116;
        v118 = v117 + *(_DWORD *)(v15 + 2748);
        v119 = *(_DWORD *)(result + 5580);
        *(_DWORD *)(result + 6044) = v118;
        v120 = v119 + *(_DWORD *)(v15 + 2736);
        v121 = *(_DWORD *)(result + 6048);
        *(_DWORD *)(result + 5580) = v120;
        v122 = v121 + *(_DWORD *)(v15 + 2752);
        v123 = *(_DWORD *)(result + 5584);
        *(_DWORD *)(result + 6048) = v122;
        v124 = v123 + *(_DWORD *)(v15 + 2740);
        v125 = *(_DWORD *)(result + 6052);
        *(_DWORD *)(result + 5584) = v124;
        v126 = v125 + *(_DWORD *)(v15 + 2756);
        v127 = *(_DWORD *)(result + 5888);
        *(_DWORD *)(result + 6052) = v126;
        v128 = v127 + *(_DWORD *)(v15 + 2760);
        v129 = *(_DWORD *)(result + 5892);
        *(_DWORD *)(result + 5888) = v128;
        v130 = v129 + *(_DWORD *)(v15 + 2764);
        v131 = *(_DWORD *)(result + 5896);
        *(_DWORD *)(result + 5892) = v130;
        v132 = v131 + *(_DWORD *)(v15 + 2768);
        v133 = *(_DWORD *)(result + 5900);
        *(_DWORD *)(result + 5896) = v132;
        v134 = v133 + *(_DWORD *)(v15 + 2772);
        v135 = *(_DWORD *)(result + 5904);
        *(_DWORD *)(result + 5900) = v134;
        v136 = v135 + *(_DWORD *)(v15 + 2776);
        v137 = *(_DWORD *)(result + 5908);
        *(_DWORD *)(result + 5904) = v136;
        v138 = v137 + *(_DWORD *)(v15 + 2780);
        v139 = *(_DWORD *)(result + 5940);
        *(_DWORD *)(result + 5908) = v138;
        v140 = v139 + *(_DWORD *)(v15 + 2812);
        v141 = *(_DWORD *)(result + 5912);
        *(_DWORD *)(result + 5940) = v140;
        v142 = v141 + *(_DWORD *)(v15 + 2784);
        v143 = *(_DWORD *)(result + 5944);
        *(_DWORD *)(result + 5912) = v142;
        v144 = v143 + *(_DWORD *)(v15 + 2816);
        v145 = *(_DWORD *)(result + 5916);
        *(_DWORD *)(result + 5944) = v144;
        v146 = v145 + *(_DWORD *)(v15 + 2788);
        v147 = *(_DWORD *)(result + 5948);
        *(_DWORD *)(result + 5916) = v146;
        v148 = v147 + *(_DWORD *)(v15 + 2820);
        v149 = *(_DWORD *)(result + 5920);
        *(_DWORD *)(result + 5948) = v148;
        v150 = v149 + *(_DWORD *)(v15 + 2792);
        v151 = *(_DWORD *)(result + 5952);
        *(_DWORD *)(result + 5920) = v150;
        v152 = v151 + *(_DWORD *)(v15 + 2824);
        v153 = *(_DWORD *)(result + 5924);
        *(_DWORD *)(result + 5952) = v152;
        v154 = v153 + *(_DWORD *)(v15 + 2796);
        v155 = *(_DWORD *)(result + 5956);
        *(_DWORD *)(result + 5924) = v154;
        v156 = v155 + *(_DWORD *)(v15 + 2828);
        v157 = *(_DWORD *)(result + 5928);
        *(_DWORD *)(result + 5956) = v156;
        v158 = v157 + *(_DWORD *)(v15 + 2800);
        v159 = *(_DWORD *)(result + 5960);
        *(_DWORD *)(result + 5928) = v158;
        v160 = v159 + *(_DWORD *)(v15 + 2832);
        v161 = *(_DWORD *)(result + 5932);
        *(_DWORD *)(result + 5960) = v160;
        v162 = v161 + *(_DWORD *)(v15 + 2804);
        v163 = *(_DWORD *)(result + 5964);
        *(_DWORD *)(result + 5932) = v162;
        v164 = v163 + *(_DWORD *)(v15 + 2836);
        v165 = *(_DWORD *)(result + 5936);
        *(_DWORD *)(result + 5964) = v164;
        v166 = v165 + *(_DWORD *)(v15 + 2808);
        v167 = *(_DWORD *)(result + 5968);
        *(_DWORD *)(result + 5936) = v166;
        v168 = v167 + *(_DWORD *)(v15 + 2840);
        v169 = *(_DWORD *)(result + 6256);
        *(_DWORD *)(result + 5968) = v168;
        v170 = v169 + *(_DWORD *)(v15 + 2844);
        v171 = *(_DWORD *)(result + 6260);
        *(_DWORD *)(result + 6256) = v170;
        v172 = v171 + *(_DWORD *)(v15 + 2848);
        v173 = *(_DWORD *)(result + 6264);
        *(_DWORD *)(result + 6260) = v172;
        v174 = v173 + *(_DWORD *)(v15 + 2852);
        v175 = *(_DWORD *)(result + 6268);
        *(_DWORD *)(result + 6264) = v174;
        v176 = v175 + *(_DWORD *)(v15 + 2856);
        v177 = *(_DWORD *)(result + 6272);
        *(_DWORD *)(result + 6268) = v176;
        v178 = v177 + *(_DWORD *)(v15 + 2860);
        v179 = *(_DWORD *)(result + 6276);
        *(_DWORD *)(result + 6272) = v178;
        v180 = v179 + *(_DWORD *)(v15 + 2864);
        v181 = *(_DWORD *)(result + 6280);
        *(_DWORD *)(result + 6276) = v180;
        v182 = v181 + *(_DWORD *)(v15 + 2868);
        v183 = *(_DWORD *)(result + 6284);
        *(_DWORD *)(result + 6280) = v182;
        v184 = v183 + *(_DWORD *)(v15 + 2872);
        v185 = *(_QWORD *)(result + 6576);
        *(_DWORD *)(result + 6284) = v184;
        v186 = v185 + *(_QWORD *)(v15 + 3024);
        v187 = *(_QWORD *)(result + 2888);
        *(_QWORD *)(result + 6576) = v186;
        v188 = v187 + *(_QWORD *)v15;
        v189 = *(_QWORD *)(result + 2896);
        *(_QWORD *)(result + 2888) = v188;
        v190 = v189 + *(_QWORD *)(v15 + 8);
        v191 = *(_QWORD *)(result + 2904);
        *(_QWORD *)(result + 2896) = v190;
        v192 = v191 + *(_QWORD *)(v15 + 16);
        v193 = *(_QWORD *)(result + 2912);
        *(_QWORD *)(result + 2904) = v192;
        v194 = v193 + *(_QWORD *)(v15 + 24);
        v195 = *(_QWORD *)(result + 2920);
        *(_QWORD *)(result + 2912) = v194;
        v196 = v195 + *(_QWORD *)(v15 + 32);
        v197 = *(_QWORD *)(result + 2928);
        *(_QWORD *)(result + 2920) = v196;
        v198 = v197 + *(_QWORD *)(v15 + 40);
        v199 = *(_QWORD *)(result + 2936);
        *(_QWORD *)(result + 2928) = v198;
        v200 = v199 + *(_QWORD *)(v15 + 48);
        v201 = *(_QWORD *)(result + 2944);
        *(_QWORD *)(result + 2936) = v200;
        v202 = v201 + *(_QWORD *)(v15 + 56);
        v203 = *(_QWORD *)(result + 2952);
        *(_QWORD *)(result + 2944) = v202;
        v204 = v203 + *(_QWORD *)(v15 + 64);
        v205 = *(_QWORD *)(result + 2960);
        *(_QWORD *)(result + 2952) = v204;
        v206 = v205 + *(_QWORD *)(v15 + 72);
        LODWORD(v205) = *(_DWORD *)(result + 2968);
        *(_QWORD *)(result + 2960) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 80);
        LODWORD(v205) = *(_DWORD *)(result + 2976);
        *(_DWORD *)(result + 2968) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 84);
        LODWORD(v205) = *(_DWORD *)(result + 2996);
        *(_DWORD *)(result + 2976) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 88);
        LODWORD(v205) = *(_DWORD *)(result + 3000);
        *(_DWORD *)(result + 2996) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 92);
        LODWORD(v205) = *(_DWORD *)(result + 3716);
        *(_DWORD *)(result + 3000) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 176);
        LODWORD(v205) = *(_DWORD *)(result + 3720);
        *(_DWORD *)(result + 3716) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 180);
        LODWORD(v205) = *(_DWORD *)(result + 3724);
        *(_DWORD *)(result + 3720) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 184);
        LODWORD(v205) = *(_DWORD *)(result + 4512);
        *(_DWORD *)(result + 3724) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 548);
        LODWORD(v205) = *(_DWORD *)(result + 3728);
        *(_DWORD *)(result + 4512) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 188);
        LODWORD(v205) = *(_DWORD *)(result + 3732);
        *(_DWORD *)(result + 3728) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 192);
        LODWORD(v205) = *(_DWORD *)(result + 3736);
        *(_DWORD *)(result + 3732) = v206;
        LODWORD(v206) = v205 + *(_DWORD *)(v15 + 196);
        v207 = *(_QWORD *)(result + 4456);
        *(_DWORD *)(result + 3736) = v206;
        v208 = v207 + *(_QWORD *)(v15 + 456);
        v209 = *(_QWORD *)(result + 4464);
        *(_QWORD *)(result + 4456) = v208;
        v210 = v209 + *(_QWORD *)(v15 + 464);
        LODWORD(v209) = *(_DWORD *)(result + 4488);
        *(_QWORD *)(result + 4464) = v210;
        *(_QWORD *)(result + 4480) = *(_QWORD *)(v15 + 472);
        *(_DWORD *)(result + 4488) = v209 + *(_DWORD *)(v15 + 544);
        do
        {
          *(_DWORD *)(result + 4204 + v112) += *(_DWORD *)(v14 + v112);
          v112 += 4;
        }
        while ( v112 != 252 );
        ++v9;
        v11 += 3256;
        v12 += 3256;
        v13 += 3256;
        v14 += 3256;
        *(_DWORD *)(result + 4588) += *(_DWORD *)(v15 + 552);
        *(_DWORD *)(result + 4592) += *(_DWORD *)(v15 + 556);
        *(_DWORD *)(result + 4596) += *(_DWORD *)(v15 + 560);
        *(_DWORD *)(result + 4600) += *(_DWORD *)(v15 + 564);
        *(_DWORD *)(result + 4604) += *(_DWORD *)(v15 + 568);
        *(_DWORD *)(result + 4608) += *(_DWORD *)(v15 + 572);
        *(_DWORD *)(result + 4612) += *(_DWORD *)(v15 + 576);
        *(_DWORD *)(result + 4616) += *(_DWORD *)(v15 + 580);
        *(_DWORD *)(result + 4620) += *(_DWORD *)(v15 + 584);
        *(_DWORD *)(result + 4624) += *(_DWORD *)(v15 + 588);
        *(_DWORD *)(result + 4628) += *(_DWORD *)(v15 + 592);
        *(_DWORD *)(result + 4632) += *(_DWORD *)(v15 + 596);
        *(_DWORD *)(result + 4636) += *(_DWORD *)(v15 + 600);
        *(_DWORD *)(result + 4640) += *(_DWORD *)(v15 + 604);
        *(_QWORD *)(result + 5376) += *(_QWORD *)(v15 + 784);
        *(_QWORD *)(result + 5384) += *(_QWORD *)(v15 + 792);
        *(_QWORD *)(result + 5464) += *(_QWORD *)(v15 + 992);
        *(_QWORD *)(result + 5472) += *(_QWORD *)(v15 + 1000);
        *(_QWORD *)(result + 5392) += *(_QWORD *)(v15 + 800);
        *(_QWORD *)(result + 5400) += *(_QWORD *)(v15 + 808);
        *(_QWORD *)(result + 5360) += *(_QWORD *)(v15 + 768);
        *(_QWORD *)(result + 5368) += *(_QWORD *)(v15 + 776);
        *(_QWORD *)(result + 5408) += *(_QWORD *)(v15 + 816);
        *(_QWORD *)(result + 5416) += *(_QWORD *)(v15 + 824);
        *(_DWORD *)(result + 5424) += *(_DWORD *)(v15 + 832);
        *(_DWORD *)(result + 6500) += *(_DWORD *)(v15 + 1008);
        *(_QWORD *)(result + 5432) += *(_QWORD *)(v15 + 840);
        *(_QWORD *)(result + 5440) += *(_QWORD *)(v15 + 848);
        *(_QWORD *)(result + 5448) += *(_QWORD *)(v15 + 856);
        *(_QWORD *)(result + 5456) += *(_QWORD *)(v15 + 864);
        *(_QWORD *)(result + 5488) += *(_QWORD *)(v15 + 880);
        *(_QWORD *)(result + 5496) += *(_QWORD *)(v15 + 888);
        *(_QWORD *)(result + 5504) += *(_QWORD *)(v15 + 896);
        *(_QWORD *)(result + 5512) += *(_QWORD *)(v15 + 904);
        *(_DWORD *)(result + 5520) += *(_DWORD *)(v15 + 912);
        *(_DWORD *)(result + 5528) += *(_DWORD *)(v15 + 920);
        *(_DWORD *)(result + 5532) += *(_DWORD *)(v15 + 924);
        *(_DWORD *)(result + 5536) += *(_DWORD *)(v15 + 928);
        *(_DWORD *)(result + 5540) += *(_DWORD *)(v15 + 932);
        *(_DWORD *)(result + 5544) += *(_DWORD *)(v15 + 936);
        *(_DWORD *)(result + 5548) += *(_DWORD *)(v15 + 940);
        *(_DWORD *)(result + 5552) += *(_DWORD *)(v15 + 944);
        *(_DWORD *)(result + 6296) += *(_DWORD *)(v15 + 948);
        *(_DWORD *)(result + 6300) += *(_DWORD *)(v15 + 952);
        *(_DWORD *)(result + 6360) += *(_DWORD *)(v15 + 956);
        *(_DWORD *)(result + 6404) += *(_DWORD *)(v15 + 960);
        *(_DWORD *)(result + 6408) += *(_DWORD *)(v15 + 964);
        *(_DWORD *)(result + 6412) += *(_DWORD *)(v15 + 968);
        *(_QWORD *)(result + 6480) += *(_QWORD *)(v15 + 976);
        *(_QWORD *)(result + 6488) += *(_QWORD *)(v15 + 984);
        *(_QWORD *)(result + 5480) = *(_QWORD *)(v15 + 872);
        *(_DWORD *)(result + 6512) += *(_DWORD *)(v15 + 1032);
        *(_QWORD *)(result + 5184) += *(_QWORD *)(v15 + 608);
        *(_QWORD *)(result + 5192) += *(_QWORD *)(v15 + 616);
        v211 = *(_QWORD *)(result + 5312) + *(_QWORD *)(v15 + 608);
        v212 = *(_QWORD *)(result + 5320);
        *(_QWORD *)(result + 5312) = v211;
        v213 = v212 + *(_QWORD *)(v15 + 616);
        v214 = *(_QWORD *)(result + 5200);
        *(_QWORD *)(result + 5320) = v213;
        *(_QWORD *)(result + 5200) = v214 + *(_QWORD *)(v15 + 624);
        *(_QWORD *)(result + 5208) += *(_QWORD *)(v15 + 632);
        v215 = v211 + *(_QWORD *)(v15 + 624);
        *(_QWORD *)(result + 5312) = v215;
        v216 = v213 + *(_QWORD *)(v15 + 632);
        v217 = *(_QWORD *)(result + 5216);
        *(_QWORD *)(result + 5320) = v216;
        *(_QWORD *)(result + 5216) = v217 + *(_QWORD *)(v15 + 640);
        *(_QWORD *)(result + 5224) += *(_QWORD *)(v15 + 648);
        v218 = v215 + *(_QWORD *)(v15 + 640);
        *(_QWORD *)(result + 5312) = v218;
        v219 = v216 + *(_QWORD *)(v15 + 648);
        v220 = *(_QWORD *)(result + 5232);
        *(_QWORD *)(result + 5320) = v219;
        *(_QWORD *)(result + 5232) = v220 + *(_QWORD *)(v15 + 656);
        *(_QWORD *)(result + 5240) += *(_QWORD *)(v15 + 664);
        v221 = v218 + *(_QWORD *)(v15 + 656);
        *(_QWORD *)(result + 5312) = v221;
        v222 = v219 + *(_QWORD *)(v15 + 664);
        v223 = *(_QWORD *)(result + 5248);
        *(_QWORD *)(result + 5320) = v222;
        *(_QWORD *)(result + 5248) = v223 + *(_QWORD *)(v15 + 672);
        *(_QWORD *)(result + 5256) += *(_QWORD *)(v15 + 680);
        v224 = v221 + *(_QWORD *)(v15 + 672);
        *(_QWORD *)(result + 5312) = v224;
        v225 = v222 + *(_QWORD *)(v15 + 680);
        v226 = *(_QWORD *)(result + 5264);
        *(_QWORD *)(result + 5320) = v225;
        *(_QWORD *)(result + 5264) = v226 + *(_QWORD *)(v15 + 688);
        *(_QWORD *)(result + 5272) += *(_QWORD *)(v15 + 696);
        v227 = v224 + *(_QWORD *)(v15 + 688);
        *(_QWORD *)(result + 5312) = v227;
        v228 = v225 + *(_QWORD *)(v15 + 696);
        v229 = *(_QWORD *)(result + 5280);
        *(_QWORD *)(result + 5320) = v228;
        *(_QWORD *)(result + 5280) = v229 + *(_QWORD *)(v15 + 704);
        *(_QWORD *)(result + 5288) += *(_QWORD *)(v15 + 712);
        v230 = v227 + *(_QWORD *)(v15 + 704);
        *(_QWORD *)(result + 5312) = v230;
        v231 = v228 + *(_QWORD *)(v15 + 712);
        v232 = *(_QWORD *)(result + 5296);
        *(_QWORD *)(result + 5320) = v231;
        *(_QWORD *)(result + 5296) = v232 + *(_QWORD *)(v15 + 720);
        *(_QWORD *)(result + 5304) += *(_QWORD *)(v15 + 728);
        *(_QWORD *)(result + 5312) = v230 + *(_QWORD *)(v15 + 720);
        *(_QWORD *)(result + 5320) = v231 + *(_QWORD *)(v15 + 728);
        *(_QWORD *)(result + 5328) += *(_QWORD *)(v15 + 736);
        *(_QWORD *)(result + 5336) += *(_QWORD *)(v15 + 744);
        *(_QWORD *)(result + 5344) += *(_QWORD *)(v15 + 752);
        *(_QWORD *)(result + 5352) += *(_QWORD *)(v15 + 760);
        *(_QWORD *)(result + 6552) += *(_QWORD *)(v15 + 1016);
        *(_QWORD *)(result + 6560) += *(_QWORD *)(v15 + 1024);
        *(_QWORD *)(result + 3520) += *(unsigned int *)(v15 + 100);
        *(_QWORD *)(result + 3528) += *(_QWORD *)(v15 + 160);
        *(_DWORD *)(result + 3536) += *(_DWORD *)(v15 + 108);
        *(_QWORD *)(result + 3544) += *(unsigned int *)(v15 + 104);
        *(_QWORD *)(result + 3552) += *(_QWORD *)(v15 + 168);
        *(_DWORD *)(result + 3560) += *(_DWORD *)(v15 + 112);
        *(_DWORD *)(result + 3564) += *(_DWORD *)(v15 + 116);
        *(_DWORD *)(result + 3568) += *(_DWORD *)(v15 + 120);
        *(_DWORD *)(result + 3572) += *(_DWORD *)(v15 + 124);
        *(_DWORD *)(result + 3576) += *(_DWORD *)(v15 + 128);
        *(_DWORD *)(result + 3580) += *(_DWORD *)(v15 + 132);
        *(_DWORD *)(result + 3584) += *(_DWORD *)(v15 + 136);
        *(_DWORD *)(result + 3588) += *(_DWORD *)(v15 + 140);
        *(_DWORD *)(result + 3592) += *(_DWORD *)(v15 + 144);
        *(_DWORD *)(result + 3596) += *(_DWORD *)(v15 + 148);
        *(_DWORD *)(result + 3600) += *(_DWORD *)(v15 + 156);
      }
      while ( v9 != v4 );
    }
  }
  return result;
}
