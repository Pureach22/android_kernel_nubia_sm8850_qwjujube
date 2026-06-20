__int64 __fastcall dp_update_vdev_stats_on_peer_unmap(__int64 result, __int64 a2)
{
  __int64 *v2; // x8
  __int64 v3; // x24
  __int64 v4; // x10
  __int64 v5; // x8
  __int64 v6; // x9
  __int64 v7; // x10
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x9
  __int64 v11; // x8
  __int64 v12; // x5
  __int64 v13; // x6
  __int64 v14; // x7
  __int64 v15; // x19
  __int64 v16; // x20
  __int64 v17; // x21
  __int64 v18; // x22
  __int64 v19; // x23
  __int64 v20; // x24
  __int64 v21; // x27
  __int64 v22; // x28
  int v23; // w29
  int v24; // w25
  int v25; // w29
  int v26; // w25
  int v27; // w29
  int v28; // w25
  int v29; // w29
  int v30; // w25
  int v31; // w29
  int v32; // w25
  int v33; // w29
  int v34; // w25
  int v35; // w29
  int v36; // w25
  int v37; // w29
  int v38; // w25
  int v39; // w29
  int v40; // w25
  int v41; // w29
  unsigned int v42; // w29
  unsigned int v43; // w29
  unsigned int v44; // w29
  unsigned int v45; // w29
  int v46; // w29
  _DWORD *v47; // x25
  _DWORD *v48; // x29
  int v49; // w8
  int v50; // w30
  int v51; // w30
  int v52; // w30
  int v53; // w30
  int v54; // w30
  int v55; // w30
  int v56; // w30
  int v57; // w11
  __int64 v58; // x28
  __int64 v59; // x29
  __int64 v60; // x25
  __int64 v61; // x29
  __int64 v62; // x25
  __int64 v63; // x29
  __int64 v64; // x25
  __int64 v65; // x29
  __int64 v66; // x25
  _DWORD *v67; // x11
  _DWORD *v68; // x8
  int v69; // w30
  __int64 v70; // x25
  int v71; // w11
  int v72; // w8
  int v73; // w11
  int v74; // w8
  int v75; // w11
  int v76; // w8
  int v77; // w11
  int v78; // w8
  int v79; // w11
  int v80; // w8
  int v81; // w11
  int v82; // w8
  int v83; // w11
  int v84; // w8
  int v85; // w11
  int v86; // w8
  int v87; // w11
  int v88; // w8
  int v89; // w11
  int v90; // w8
  int v91; // w11
  int v92; // w8
  int v93; // w11
  int v94; // w8
  int v95; // w11
  int v96; // w8
  int v97; // w11
  int v98; // w8
  int v99; // w11
  int v100; // w8
  int v101; // w11
  int v102; // w8
  int v103; // w11
  int v104; // w8
  int v105; // w11
  int v106; // w8
  int v107; // w11
  int v108; // w8
  int v109; // w11
  int v110; // w8
  int v111; // w11
  int v112; // w8
  int v113; // w11
  int v114; // w8
  int v115; // w11
  int v116; // w8
  int v117; // w11
  int v118; // w8
  int v119; // w11
  int v120; // w8
  int v121; // w11
  __int64 v122; // x28
  int v123; // w25
  __int64 v124; // x11
  __int64 v125; // x8
  __int64 v126; // x11
  __int64 v127; // x8
  __int64 v128; // x11
  __int64 v129; // x8
  __int64 v130; // x11
  __int64 v131; // x8
  __int64 v132; // x11
  __int64 v133; // x8
  __int64 v134; // x11
  __int64 v135; // x8
  unsigned int v136; // w25
  unsigned int v137; // w25
  unsigned int v138; // w25
  unsigned int v139; // w25
  _DWORD *v140; // x25
  _DWORD *v141; // x29
  int v142; // w30
  int v143; // w30
  int v144; // w30
  int v145; // w30
  int v146; // w30
  int v147; // w30
  int v148; // w30
  int v149; // w30
  int v150; // w11
  __int64 v151; // x25
  __int64 v152; // x11
  __int64 v153; // x8
  __int64 v154; // x11
  __int64 v155; // x8
  __int64 v156; // x11
  __int64 v157; // x8
  __int64 v158; // x11
  _DWORD *v159; // x8
  _DWORD *v160; // x11
  __int64 v161; // x25
  char v162; // w29
  _DWORD *v163; // x30
  _DWORD *v164; // x25
  int v165; // w10
  int v166; // w11
  int v167; // w11
  int v168; // w11
  int v169; // w11
  int v170; // w11
  int v171; // w11
  int v172; // w11
  int v173; // w11
  int v174; // w11
  int v175; // w11
  int v176; // w11
  int v177; // w11
  int v178; // w10
  int v179; // w8
  int v180; // w8
  __int64 v181; // x28
  int v182; // w11
  int v183; // w8
  int v184; // w11
  int v185; // w8
  int v186; // w11
  int v187; // w8
  int v188; // w11
  int v189; // w8
  int v190; // w11
  int v191; // w8
  int v192; // w11
  int v193; // w8
  int v194; // w11
  int v195; // w8
  int v196; // w11
  int v197; // w8
  int v198; // w11
  int v199; // w8
  int v200; // w11
  int v201; // w8
  int v202; // w11
  int v203; // w8
  int v204; // w11
  int v205; // w8
  int v206; // w11
  int v207; // w8
  int v208; // w11
  int v209; // w8
  int v210; // w11
  int v211; // w8
  int v212; // w11
  int v213; // w8
  int v214; // w11
  int v215; // w8
  int v216; // w11
  int v217; // w8
  int v218; // w11
  int v219; // w8
  int v220; // w11
  int v221; // w8
  int v222; // w11
  int v223; // w8
  int v224; // w11
  int v225; // w8
  int v226; // w11
  int v227; // w8
  int v228; // w11
  int v229; // w8
  int v230; // w11
  int v231; // w8
  int v232; // w11
  int v233; // w8
  int v234; // w11
  int v235; // w8
  int v236; // w11
  int v237; // w8
  int v238; // w11
  int v239; // w8
  int v240; // w11
  int v241; // w8
  int v242; // w11
  int v243; // w8
  int v244; // w11
  int v245; // w8
  int v246; // w11
  int v247; // w8
  int v248; // w11
  int v249; // w8
  int v250; // w11
  int v251; // w8
  int v252; // w11
  int v253; // w8
  __int64 v254; // x11
  _DWORD *v255; // x8
  _DWORD *v256; // x10
  __int64 i; // x25
  _DWORD *v258; // x8
  _DWORD *v259; // x10
  __int64 j; // x25
  _DWORD *v261; // x8
  _DWORD *v262; // x10
  __int64 v263; // x28
  int v264; // w10
  int v265; // w8
  int v266; // w10
  int v267; // w8
  int v268; // w10
  int v269; // w8
  int v270; // w10
  int v271; // w8
  int v272; // w10
  int v273; // w8
  int v274; // w10
  int v275; // w8
  int v276; // w10
  int v277; // w8
  int v278; // w10
  int v279; // w8
  int v280; // w10
  int v281; // w8
  __int64 v282; // x10
  __int64 v283; // x8
  __int64 v284; // x10
  __int64 v285; // x8
  __int64 v286; // x10
  __int64 v287; // x8
  __int64 v288; // x10
  __int64 v289; // x8
  __int64 v290; // x10
  __int64 v291; // x8
  __int64 v292; // x10
  __int64 v293; // x8
  __int64 v294; // x10
  __int64 v295; // x8
  __int64 v296; // x10
  __int64 v297; // x8
  __int64 v298; // x10
  __int64 v299; // x8
  __int64 v300; // x10
  __int64 v301; // x8
  __int64 v302; // x10
  __int64 v303; // x8
  __int64 v304; // x10
  __int64 v305; // x8
  __int64 v306; // x8
  __int64 v307; // x10
  __int64 v308; // x10
  __int64 v309; // x11
  __int64 v310; // x8
  __int64 v311; // x10
  __int64 v312; // x11
  __int64 v313; // x8
  __int64 v314; // x10
  __int64 v315; // x11
  __int64 v316; // x8
  __int64 v317; // x10
  __int64 v318; // x11
  __int64 v319; // x8
  __int64 v320; // x10
  __int64 v321; // x11
  __int64 v322; // x8
  __int64 v323; // x10
  __int64 v324; // x11
  __int64 v325; // x8
  __int64 v326; // x10
  __int64 v327; // x11
  __int64 v328; // [xsp+8h] [xbp-78h]
  __int64 v329; // [xsp+18h] [xbp-68h]

  if ( *(_DWORD *)(a2 + 408) != 1 || (v2 = *(__int64 **)(a2 + 416)) == nullptr )
    v2 = (__int64 *)a2;
  v3 = *v2;
  if ( *v2 )
  {
    v4 = *(_QWORD *)(result + 2888);
    v5 = *(unsigned __int8 *)(v3 + 2281);
    *(_QWORD *)(result + 2880) += *(_QWORD *)(v3 + 16);
    v329 = v5;
    v6 = v4 + *(_QWORD *)(v3 + 24);
    LODWORD(v4) = *(_DWORD *)(result + 2980);
    *(_QWORD *)(result + 2888) = v6;
    LODWORD(v6) = v4 + *(_DWORD *)(v3 + 12);
    v7 = *(_QWORD *)(result + 5624);
    *(_DWORD *)(result + 2980) = v6;
    v8 = v7 + *(_QWORD *)(v3 + 32);
    v9 = *(_QWORD *)(result + 5632);
    *(_QWORD *)(result + 5624) = v8;
    *(_QWORD *)(result + 5632) = v9 + *(_QWORD *)(v3 + 40);
    if ( v5 )
    {
      v10 = 0;
      v11 = v3 + 2288;
      v12 = v3 + 3404;
      v13 = v3 + 3948;
      v14 = v3 + 4240;
      v15 = v3 + 4928;
      v16 = v3 + 5312;
      v17 = v3 + 4552;
      v18 = v3 + 4620;
      v19 = v3 + 4688;
      v20 = v3 + 2488;
      v328 = v11;
      do
      {
        v21 = v328 + 4072 * v10;
        v22 = 0;
        v23 = *(_DWORD *)(result + 2992);
        *(_DWORD *)(result + 2988) += *(_DWORD *)(v21 + 1040);
        v24 = v23 + *(_DWORD *)(v21 + 1044);
        v25 = *(_DWORD *)(result + 2996);
        *(_DWORD *)(result + 2992) = v24;
        v26 = v25 + *(_DWORD *)(v21 + 1048);
        v27 = *(_DWORD *)(result + 3820);
        *(_DWORD *)(result + 2996) = v26;
        v28 = v27 + *(_DWORD *)(v21 + 1492);
        v29 = *(_DWORD *)(result + 3824);
        *(_DWORD *)(result + 3820) = v28;
        v30 = v29 + *(_DWORD *)(v21 + 1496);
        v31 = *(_DWORD *)(result + 4432);
        *(_DWORD *)(result + 3824) = v30;
        v32 = v31 + *(_DWORD *)(v21 + 1500);
        v33 = *(_DWORD *)(result + 3856);
        *(_DWORD *)(result + 4432) = v32;
        v34 = v33 + *(_DWORD *)(v21 + 1504);
        v35 = *(_DWORD *)(result + 3860);
        *(_DWORD *)(result + 3856) = v34;
        v36 = v35 + *(_DWORD *)(v21 + 1508);
        v37 = *(_DWORD *)(result + 3864);
        *(_DWORD *)(result + 3860) = v36;
        v38 = v37 + *(_DWORD *)(v21 + 1512);
        v39 = *(_DWORD *)(result + 3516);
        *(_DWORD *)(result + 3864) = v38;
        *(_DWORD *)(result + 3012) = *(_DWORD *)(v21 + 1516);
        *(_DWORD *)(result + 3016) = *(_DWORD *)(v21 + 1520);
        *(_DWORD *)(result + 3020) = *(_DWORD *)(v21 + 1524);
        *(_DWORD *)(result + 3024) = *(_DWORD *)(v21 + 1528);
        *(_DWORD *)(result + 3028) = *(_DWORD *)(v21 + 1532);
        *(_QWORD *)(result + 3040) = *(_QWORD *)(v21 + 1536);
        *(_QWORD *)(result + 3048) = *(_QWORD *)(v21 + 1544);
        *(_WORD *)(result + 3816) = *(_WORD *)(v21 + 1552);
        v40 = v39 + *(_DWORD *)(v21 + 1576);
        v41 = *(_DWORD *)(result + 4704);
        *(_DWORD *)(result + 3516) = v40;
        *(_DWORD *)(result + 4232) = *(_DWORD *)(v21 + 1644);
        *(_DWORD *)(result + 4236) = *(_DWORD *)(v21 + 1648);
        *(_DWORD *)(result + 3056) = *(_DWORD *)(v21 + 2208);
        *(_DWORD *)(result + 3060) = *(_DWORD *)(v21 + 2212);
        v42 = v41 & 0xFFFFFFF0 | *(_DWORD *)(v21 + 2220) & 0xF;
        *(_DWORD *)(result + 4704) = v42;
        v43 = v42 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v21 + 2220) >> 4) & 0xF));
        *(_DWORD *)(result + 4704) = v43;
        v44 = v43 & 0xFFFFF0FF | (((*(_DWORD *)(v21 + 2220) >> 8) & 0xF) << 8);
        *(_DWORD *)(result + 4704) = v44;
        v45 = v44 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v21 + 2220)) >> 4 << 12);
        *(_DWORD *)(result + 4704) = v45;
        *(_DWORD *)(result + 4704) = v45 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v21 + 2220)) & 0xF) << 16);
        v46 = *(_DWORD *)(result + 4708);
        *(_DWORD *)(result + 3000) += *(_DWORD *)(v21 + 2224);
        *(_DWORD *)(result + 4708) = v46 + *(_DWORD *)(v21 + 2228);
        *(_DWORD *)(result + 4952) = *(_DWORD *)(v21 + 2488);
        *(_DWORD *)(result + 4956) = *(_DWORD *)(v21 + 2492);
        *(_DWORD *)(result + 4960) = *(_DWORD *)(v21 + 2496);
        *(_DWORD *)(result + 4964) = *(_DWORD *)(v21 + 2500);
        do
        {
          v47 = (_DWORD *)(result + 3088 + v22);
          v48 = (_DWORD *)(v12 + v22);
          v22 += 68;
          v49 = v47[1];
          *v47 += *(v48 - 16);
          v47[1] = v49 + *(v48 - 15);
          v50 = v47[3];
          v47[2] += *(v48 - 14);
          v47[3] = v50 + *(v48 - 13);
          v51 = v47[5];
          v47[4] += *(v48 - 12);
          v47[5] = v51 + *(v48 - 11);
          v52 = v47[7];
          v47[6] += *(v48 - 10);
          v47[7] = v52 + *(v48 - 9);
          v53 = v47[9];
          v47[8] += *(v48 - 8);
          v47[9] = v53 + *(v48 - 7);
          v54 = v47[11];
          v47[10] += *(v48 - 6);
          v47[11] = v54 + *(v48 - 5);
          v55 = v47[13];
          v47[12] += *(v48 - 4);
          v47[13] = v55 + *(v48 - 3);
          v56 = v47[15];
          v57 = v47[16];
          v47[14] += *(v48 - 2);
          v47[15] = v56 + *(v48 - 1);
          v47[16] = v57 + *v48;
        }
        while ( v22 != 408 );
        v58 = 0;
        v59 = *(_QWORD *)(result + 4976);
        *(_DWORD *)(result + 3584) += *(_DWORD *)(v21 + 1460);
        v60 = v59 + *(_QWORD *)(v21 + 2536);
        LODWORD(v59) = *(_DWORD *)(result + 3600);
        *(_QWORD *)(result + 4976) = v60;
        LODWORD(v60) = v59 + *(_DWORD *)(v21 + 1476);
        LODWORD(v59) = *(_DWORD *)(result + 3588);
        *(_DWORD *)(result + 3600) = v60;
        LODWORD(v60) = v59 + *(_DWORD *)(v21 + 1464);
        v61 = *(_QWORD *)(result + 4984);
        *(_DWORD *)(result + 3588) = v60;
        v62 = v61 + *(_QWORD *)(v21 + 2544);
        LODWORD(v61) = *(_DWORD *)(result + 3604);
        *(_QWORD *)(result + 4984) = v62;
        LODWORD(v62) = v61 + *(_DWORD *)(v21 + 1480);
        LODWORD(v61) = *(_DWORD *)(result + 3592);
        *(_DWORD *)(result + 3604) = v62;
        LODWORD(v62) = v61 + *(_DWORD *)(v21 + 1468);
        v63 = *(_QWORD *)(result + 4992);
        *(_DWORD *)(result + 3592) = v62;
        v64 = v63 + *(_QWORD *)(v21 + 2552);
        LODWORD(v63) = *(_DWORD *)(result + 3608);
        *(_QWORD *)(result + 4992) = v64;
        LODWORD(v64) = v63 + *(_DWORD *)(v21 + 1484);
        LODWORD(v63) = *(_DWORD *)(result + 3596);
        *(_DWORD *)(result + 3608) = v64;
        LODWORD(v64) = v63 + *(_DWORD *)(v21 + 1472);
        v65 = *(_QWORD *)(result + 5000);
        *(_DWORD *)(result + 3596) = v64;
        v66 = v65 + *(_QWORD *)(v21 + 2560);
        LODWORD(v65) = *(_DWORD *)(result + 3612);
        *(_QWORD *)(result + 5000) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1488);
        LODWORD(v65) = *(_DWORD *)(result + 3496);
        *(_DWORD *)(result + 3612) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1556);
        LODWORD(v65) = *(_DWORD *)(result + 3500);
        *(_DWORD *)(result + 3496) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1560);
        LODWORD(v65) = *(_DWORD *)(result + 3504);
        *(_DWORD *)(result + 3500) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1564);
        LODWORD(v65) = *(_DWORD *)(result + 3508);
        *(_DWORD *)(result + 3504) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1568);
        LODWORD(v65) = *(_DWORD *)(result + 3512);
        *(_DWORD *)(result + 3508) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1572);
        LODWORD(v65) = *(_DWORD *)(result + 3520);
        *(_DWORD *)(result + 3512) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1580);
        LODWORD(v65) = *(_DWORD *)(result + 3524);
        *(_DWORD *)(result + 3520) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1584);
        LODWORD(v65) = *(_DWORD *)(result + 3528);
        *(_DWORD *)(result + 3524) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1588);
        LODWORD(v65) = *(_DWORD *)(result + 3532);
        *(_DWORD *)(result + 3528) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1592);
        LODWORD(v65) = *(_DWORD *)(result + 3536);
        *(_DWORD *)(result + 3532) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1596);
        LODWORD(v65) = *(_DWORD *)(result + 3540);
        *(_DWORD *)(result + 3536) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1600);
        LODWORD(v65) = *(_DWORD *)(result + 3544);
        *(_DWORD *)(result + 3540) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1604);
        LODWORD(v65) = *(_DWORD *)(result + 3548);
        *(_DWORD *)(result + 3544) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1608);
        LODWORD(v65) = *(_DWORD *)(result + 3552);
        *(_DWORD *)(result + 3548) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1612);
        LODWORD(v65) = *(_DWORD *)(result + 3556);
        *(_DWORD *)(result + 3552) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1616);
        LODWORD(v65) = *(_DWORD *)(result + 3560);
        *(_DWORD *)(result + 3556) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1620);
        LODWORD(v65) = *(_DWORD *)(result + 3564);
        *(_DWORD *)(result + 3560) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1624);
        LODWORD(v65) = *(_DWORD *)(result + 3568);
        *(_DWORD *)(result + 3564) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1628);
        LODWORD(v65) = *(_DWORD *)(result + 3572);
        *(_DWORD *)(result + 3568) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1632);
        LODWORD(v65) = *(_DWORD *)(result + 3576);
        *(_DWORD *)(result + 3572) = v66;
        LODWORD(v66) = v65 + *(_DWORD *)(v21 + 1636);
        LODWORD(v65) = *(_DWORD *)(result + 3580);
        *(_DWORD *)(result + 3576) = v66;
        *(_DWORD *)(result + 3580) = v65 + *(_DWORD *)(v21 + 1640);
        do
        {
          v67 = (_DWORD *)(result + 4240 + v58);
          v68 = (_DWORD *)(v13 + v58);
          v58 += 12;
          v69 = v67[1];
          *v67 += *(v68 - 2);
          v67[1] = v69 + *(v68 - 1);
          v67[2] += *v68;
        }
        while ( v58 != 192 );
        v70 = 0;
        v71 = *(_DWORD *)(result + 3872);
        *(_DWORD *)(result + 3868) += *(_DWORD *)(v21 + 1844);
        v72 = v71 + *(_DWORD *)(v21 + 1848);
        v73 = *(_DWORD *)(result + 3876);
        *(_DWORD *)(result + 3872) = v72;
        v74 = v73 + *(_DWORD *)(v21 + 1852);
        v75 = *(_DWORD *)(result + 3880);
        *(_DWORD *)(result + 3876) = v74;
        v76 = v75 + *(_DWORD *)(v21 + 1856);
        v77 = *(_DWORD *)(result + 3884);
        *(_DWORD *)(result + 3880) = v76;
        v78 = v77 + *(_DWORD *)(v21 + 1860);
        v79 = *(_DWORD *)(result + 3888);
        *(_DWORD *)(result + 3884) = v78;
        v80 = v79 + *(_DWORD *)(v21 + 1864);
        v81 = *(_DWORD *)(result + 3892);
        *(_DWORD *)(result + 3888) = v80;
        v82 = v81 + *(_DWORD *)(v21 + 1868);
        v83 = *(_DWORD *)(result + 3896);
        *(_DWORD *)(result + 3892) = v82;
        v84 = v83 + *(_DWORD *)(v21 + 1872);
        v85 = *(_DWORD *)(result + 3900);
        *(_DWORD *)(result + 3896) = v84;
        v86 = v85 + *(_DWORD *)(v21 + 1876);
        v87 = *(_DWORD *)(result + 3904);
        *(_DWORD *)(result + 3900) = v86;
        v88 = v87 + *(_DWORD *)(v21 + 1880);
        v89 = *(_DWORD *)(result + 3908);
        *(_DWORD *)(result + 3904) = v88;
        v90 = v89 + *(_DWORD *)(v21 + 1884);
        v91 = *(_DWORD *)(result + 3912);
        *(_DWORD *)(result + 3908) = v90;
        v92 = v91 + *(_DWORD *)(v21 + 1888);
        v93 = *(_DWORD *)(result + 3916);
        *(_DWORD *)(result + 3912) = v92;
        v94 = v93 + *(_DWORD *)(v21 + 1892);
        v95 = *(_DWORD *)(result + 3920);
        *(_DWORD *)(result + 3916) = v94;
        v96 = v95 + *(_DWORD *)(v21 + 1896);
        v97 = *(_DWORD *)(result + 3924);
        *(_DWORD *)(result + 3920) = v96;
        v98 = v97 + *(_DWORD *)(v21 + 1900);
        v99 = *(_DWORD *)(result + 3928);
        *(_DWORD *)(result + 3924) = v98;
        v100 = v99 + *(_DWORD *)(v21 + 1904);
        v101 = *(_DWORD *)(result + 3932);
        *(_DWORD *)(result + 3928) = v100;
        v102 = v101 + *(_DWORD *)(v21 + 1908);
        v103 = *(_DWORD *)(result + 3936);
        *(_DWORD *)(result + 3932) = v102;
        v104 = v103 + *(_DWORD *)(v21 + 1912);
        v105 = *(_DWORD *)(result + 3940);
        *(_DWORD *)(result + 3936) = v104;
        v106 = v105 + *(_DWORD *)(v21 + 1916);
        v107 = *(_DWORD *)(result + 3944);
        *(_DWORD *)(result + 3940) = v106;
        v108 = v107 + *(_DWORD *)(v21 + 1920);
        v109 = *(_DWORD *)(result + 3948);
        *(_DWORD *)(result + 3944) = v108;
        v110 = v109 + *(_DWORD *)(v21 + 1924);
        v111 = *(_DWORD *)(result + 3952);
        *(_DWORD *)(result + 3948) = v110;
        v112 = v111 + *(_DWORD *)(v21 + 1928);
        v113 = *(_DWORD *)(result + 3956);
        *(_DWORD *)(result + 3952) = v112;
        v114 = v113 + *(_DWORD *)(v21 + 1932);
        v115 = *(_DWORD *)(result + 3960);
        *(_DWORD *)(result + 3956) = v114;
        v116 = v115 + *(_DWORD *)(v21 + 1936);
        v117 = *(_DWORD *)(result + 3964);
        *(_DWORD *)(result + 3960) = v116;
        v118 = v117 + *(_DWORD *)(v21 + 1940);
        v119 = *(_DWORD *)(result + 3968);
        *(_DWORD *)(result + 3964) = v118;
        v120 = v119 + *(_DWORD *)(v21 + 1944);
        v121 = *(_DWORD *)(result + 3972);
        *(_DWORD *)(result + 3968) = v120;
        *(_DWORD *)(result + 3972) = v121 + *(_DWORD *)(v21 + 1948);
        do
        {
          *(_DWORD *)(result + 3976 + v70) = *(_DWORD *)(v14 + v70);
          v70 += 4;
        }
        while ( v70 != 256 );
        v122 = 0;
        v123 = *(_DWORD *)(result + 7076);
        v124 = *(_QWORD *)(result + 5016);
        *(_QWORD *)(result + 5008) += *(_QWORD *)(v21 + 2232);
        v125 = v124 + *(_QWORD *)(v21 + 2240);
        v126 = *(_QWORD *)(result + 5024);
        *(_QWORD *)(result + 5016) = v125;
        v127 = v126 + *(_QWORD *)(v21 + 2248);
        v128 = *(_QWORD *)(result + 5032);
        *(_QWORD *)(result + 5024) = v127;
        v129 = v128 + *(_QWORD *)(v21 + 2256);
        v130 = *(_QWORD *)(result + 5616);
        *(_QWORD *)(result + 5032) = v129;
        *(_DWORD *)(result + 3756) = *(_DWORD *)(v21 + 2504);
        *(_DWORD *)(result + 3760) = *(_DWORD *)(v21 + 2508);
        *(_DWORD *)(result + 3764) = *(_DWORD *)(v21 + 2512);
        *(_DWORD *)(result + 3768) = *(_DWORD *)(v21 + 2516);
        *(_DWORD *)(result + 3772) = *(_DWORD *)(v21 + 2520);
        *(_DWORD *)(result + 3776) = *(_DWORD *)(v21 + 2524);
        *(_DWORD *)(result + 3780) = *(_DWORD *)(v21 + 2528);
        *(_DWORD *)(result + 3784) = *(_DWORD *)(v21 + 2532);
        v131 = v130 + *(_QWORD *)(v21 + 2568);
        LODWORD(v130) = *(_DWORD *)(result + 6536);
        *(_QWORD *)(result + 5616) = v131;
        LODWORD(v131) = v130 + *(_DWORD *)(v21 + 3000);
        LODWORD(v130) = *(_DWORD *)(result + 6540);
        *(_DWORD *)(result + 6536) = v131;
        LODWORD(v131) = v130 + *(_DWORD *)(v21 + 3004);
        v132 = *(_QWORD *)(result + 7376);
        *(_DWORD *)(result + 6540) = v131;
        v133 = v132 + *(_QWORD *)(v21 + 3856);
        v134 = *(_QWORD *)(result + 7384);
        *(_QWORD *)(result + 7376) = v133;
        v135 = v134 + *(_QWORD *)(v21 + 3864);
        LODWORD(v134) = *(_DWORD *)(result + 6876);
        *(_QWORD *)(result + 7384) = v135;
        LODWORD(v135) = v134 + *(_DWORD *)(v21 + 3008);
        LODWORD(v134) = *(_DWORD *)(result + 6880);
        *(_DWORD *)(result + 6876) = v135;
        LODWORD(v135) = v134 + *(_DWORD *)(v21 + 3012);
        LODWORD(v134) = *(_DWORD *)(result + 6956);
        *(_DWORD *)(result + 6880) = v135;
        LODWORD(v135) = v134 + *(_DWORD *)(v21 + 3016);
        LODWORD(v134) = *(_DWORD *)(result + 6960);
        *(_DWORD *)(result + 6956) = v135;
        LODWORD(v135) = v134 + *(_DWORD *)(v21 + 3020);
        LODWORD(v134) = *(_DWORD *)(result + 7408);
        *(_DWORD *)(result + 6960) = v135;
        *(_DWORD *)(result + 6900) = *(_DWORD *)(v21 + 3524);
        *(_DWORD *)(result + 6904) = *(_DWORD *)(v21 + 3528);
        *(_DWORD *)(result + 6908) = *(_DWORD *)(v21 + 3532);
        *(_DWORD *)(result + 6912) = *(_DWORD *)(v21 + 3536);
        *(_DWORD *)(result + 6972) = *(_DWORD *)(v21 + 3540);
        *(_DWORD *)(result + 6896) = *(_DWORD *)(v21 + 3544);
        *(_QWORD *)(result + 6984) = *(_QWORD *)(v21 + 3552);
        *(_DWORD *)(result + 7408) = v134 + *(_DWORD *)(v21 + 3848);
        *(_BYTE *)(result + 6992) = *(_BYTE *)(v21 + 3560);
        *(_BYTE *)(result + 6993) = *(_BYTE *)(v21 + 3561);
        v136 = v123 & 0xFFFFFFF0 | *(_DWORD *)(v21 + 3562) & 0xF;
        *(_DWORD *)(result + 7076) = v136;
        v137 = v136 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v21 + 3562) >> 4) & 0xF));
        *(_DWORD *)(result + 7076) = v137;
        v138 = v137 & 0xFFFFF0FF | (((*(_DWORD *)(v21 + 3562) >> 8) & 0xF) << 8);
        *(_DWORD *)(result + 7076) = v138;
        v139 = v138 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v21 + 3562)) >> 4 << 12);
        LODWORD(v134) = *(_DWORD *)(result + 7096);
        *(_DWORD *)(result + 7076) = v139;
        *(_DWORD *)(result + 7076) = v139 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v21 + 3562)) & 0xF) << 16);
        *(_DWORD *)(result + 7096) = v134 + *(_DWORD *)(v21 + 3568);
        *(_DWORD *)(result + 7328) = *(_DWORD *)(v21 + 3796);
        *(_DWORD *)(result + 7332) = *(_DWORD *)(v21 + 3800);
        do
        {
          v140 = (_DWORD *)(result + 6044 + v122);
          v141 = (_DWORD *)(v15 + v122);
          v122 += 68;
          v142 = v140[1];
          *v140 += *(v141 - 16);
          v140[1] = v142 + *(v141 - 15);
          v143 = v140[3];
          v140[2] += *(v141 - 14);
          v140[3] = v143 + *(v141 - 13);
          v144 = v140[5];
          v140[4] += *(v141 - 12);
          v140[5] = v144 + *(v141 - 11);
          v145 = v140[7];
          v140[6] += *(v141 - 10);
          v140[7] = v145 + *(v141 - 9);
          v146 = v140[9];
          v140[8] += *(v141 - 8);
          v140[9] = v146 + *(v141 - 7);
          v147 = v140[11];
          v140[10] += *(v141 - 6);
          v140[11] = v147 + *(v141 - 5);
          v148 = v140[13];
          v140[12] += *(v141 - 4);
          v140[13] = v148 + *(v141 - 3);
          v149 = v140[15];
          v150 = v140[16];
          v140[14] += *(v141 - 2);
          v140[15] = v149 + *(v141 - 1);
          v140[16] = v150 + *v141;
        }
        while ( v122 != 408 );
        v151 = 0;
        v152 = *(_QWORD *)(result + 7344);
        *(_DWORD *)(result + 6012) += *(_DWORD *)(v21 + 2984);
        v153 = v152 + *(_QWORD *)(v21 + 3808);
        LODWORD(v152) = *(_DWORD *)(result + 6016);
        *(_QWORD *)(result + 7344) = v153;
        LODWORD(v153) = v152 + *(_DWORD *)(v21 + 2988);
        v154 = *(_QWORD *)(result + 7352);
        *(_DWORD *)(result + 6016) = v153;
        v155 = v154 + *(_QWORD *)(v21 + 3816);
        LODWORD(v154) = *(_DWORD *)(result + 6020);
        *(_QWORD *)(result + 7352) = v155;
        LODWORD(v155) = v154 + *(_DWORD *)(v21 + 2992);
        v156 = *(_QWORD *)(result + 7360);
        *(_DWORD *)(result + 6020) = v155;
        v157 = v156 + *(_QWORD *)(v21 + 3824);
        LODWORD(v156) = *(_DWORD *)(result + 6024);
        *(_QWORD *)(result + 7360) = v157;
        LODWORD(v157) = v156 + *(_DWORD *)(v21 + 2996);
        v158 = *(_QWORD *)(result + 7368);
        *(_DWORD *)(result + 6024) = v157;
        *(_QWORD *)(result + 7368) = v158 + *(_QWORD *)(v21 + 3832);
        do
        {
          v159 = (_DWORD *)(v16 + v151);
          v160 = (_DWORD *)(result + 6544 + v151);
          v151 += 4;
          *v160 += *v159;
          v160[116] += v159[108];
        }
        while ( v151 != 68 );
        v161 = 0;
        v162 = 1;
        do
        {
          v163 = (_DWORD *)(result + 6628 + 108 * v161);
          v164 = (_DWORD *)(v21 + 3092 + 108 * v161);
          v165 = v163[9];
          v163[8] += v164[8];
          v163[9] = v165 + v164[9];
          v166 = v163[1];
          *v163 += *v164;
          v163[1] = v166 + v164[1];
          v167 = v163[3];
          v163[2] += v164[2];
          v163[3] = v167 + v164[3];
          v168 = v163[5];
          v163[4] += v164[4];
          v163[5] = v168 + v164[5];
          v169 = v163[7];
          v163[6] += v164[6];
          v163[7] = v169 + v164[7];
          v170 = v163[11];
          v163[10] += v164[10];
          v163[11] = v170 + v164[11];
          v171 = v163[13];
          v163[12] += v164[12];
          v163[13] = v171 + v164[13];
          v172 = v163[15];
          v163[14] += v164[14];
          v163[15] = v172 + v164[15];
          v173 = v163[17];
          v163[16] += v164[16];
          v163[17] = v173 + v164[17];
          v174 = v163[19];
          v163[18] += v164[18];
          v163[19] = v174 + v164[19];
          v175 = v163[21];
          v163[20] += v164[20];
          v163[21] = v175 + v164[21];
          v176 = v163[23];
          v163[22] += v164[22];
          v163[23] = v176 + v164[23];
          v177 = v163[25];
          v178 = v163[26];
          v163[24] += v164[24];
          v179 = v177 + v164[25];
          LOBYTE(v177) = v162;
          v162 = 0;
          v163[25] = v179;
          v180 = v164[26];
          v161 = 1;
          v163[26] = v178 + v180;
        }
        while ( (v177 & 1) != 0 );
        v181 = 0;
        v182 = *(_DWORD *)(result + 6612);
        *(_DWORD *)(result + 6028) += *(_DWORD *)(v21 + 3308);
        v183 = v182 + *(_DWORD *)(v21 + 3324);
        v184 = *(_DWORD *)(result + 6032);
        *(_DWORD *)(result + 6612) = v183;
        v185 = v184 + *(_DWORD *)(v21 + 3312);
        v186 = *(_DWORD *)(result + 6616);
        *(_DWORD *)(result + 6032) = v185;
        v187 = v186 + *(_DWORD *)(v21 + 3328);
        v188 = *(_DWORD *)(result + 6036);
        *(_DWORD *)(result + 6616) = v187;
        v189 = v188 + *(_DWORD *)(v21 + 3316);
        v190 = *(_DWORD *)(result + 6620);
        *(_DWORD *)(result + 6036) = v189;
        v191 = v190 + *(_DWORD *)(v21 + 3332);
        v192 = *(_DWORD *)(result + 6040);
        *(_DWORD *)(result + 6620) = v191;
        v193 = v192 + *(_DWORD *)(v21 + 3320);
        v194 = *(_DWORD *)(result + 6624);
        *(_DWORD *)(result + 6040) = v193;
        v195 = v194 + *(_DWORD *)(v21 + 3336);
        v196 = *(_DWORD *)(result + 6452);
        *(_DWORD *)(result + 6624) = v195;
        v197 = v196 + *(_DWORD *)(v21 + 3340);
        v198 = *(_DWORD *)(result + 6456);
        *(_DWORD *)(result + 6452) = v197;
        v199 = v198 + *(_DWORD *)(v21 + 3344);
        v200 = *(_DWORD *)(result + 6460);
        *(_DWORD *)(result + 6456) = v199;
        v201 = v200 + *(_DWORD *)(v21 + 3348);
        v202 = *(_DWORD *)(result + 6464);
        *(_DWORD *)(result + 6460) = v201;
        v203 = v202 + *(_DWORD *)(v21 + 3352);
        v204 = *(_DWORD *)(result + 6468);
        *(_DWORD *)(result + 6464) = v203;
        v205 = v204 + *(_DWORD *)(v21 + 3356);
        v206 = *(_DWORD *)(result + 6472);
        *(_DWORD *)(result + 6468) = v205;
        v207 = v206 + *(_DWORD *)(v21 + 3360);
        v208 = *(_DWORD *)(result + 6504);
        *(_DWORD *)(result + 6472) = v207;
        v209 = v208 + *(_DWORD *)(v21 + 3392);
        v210 = *(_DWORD *)(result + 6476);
        *(_DWORD *)(result + 6504) = v209;
        v211 = v210 + *(_DWORD *)(v21 + 3364);
        v212 = *(_DWORD *)(result + 6508);
        *(_DWORD *)(result + 6476) = v211;
        v213 = v212 + *(_DWORD *)(v21 + 3396);
        v214 = *(_DWORD *)(result + 6480);
        *(_DWORD *)(result + 6508) = v213;
        v215 = v214 + *(_DWORD *)(v21 + 3368);
        v216 = *(_DWORD *)(result + 6512);
        *(_DWORD *)(result + 6480) = v215;
        v217 = v216 + *(_DWORD *)(v21 + 3400);
        v218 = *(_DWORD *)(result + 6484);
        *(_DWORD *)(result + 6512) = v217;
        v219 = v218 + *(_DWORD *)(v21 + 3372);
        v220 = *(_DWORD *)(result + 6516);
        *(_DWORD *)(result + 6484) = v219;
        v221 = v220 + *(_DWORD *)(v21 + 3404);
        v222 = *(_DWORD *)(result + 6488);
        *(_DWORD *)(result + 6516) = v221;
        v223 = v222 + *(_DWORD *)(v21 + 3376);
        v224 = *(_DWORD *)(result + 6520);
        *(_DWORD *)(result + 6488) = v223;
        v225 = v224 + *(_DWORD *)(v21 + 3408);
        v226 = *(_DWORD *)(result + 6492);
        *(_DWORD *)(result + 6520) = v225;
        v227 = v226 + *(_DWORD *)(v21 + 3380);
        v228 = *(_DWORD *)(result + 6524);
        *(_DWORD *)(result + 6492) = v227;
        v229 = v228 + *(_DWORD *)(v21 + 3412);
        v230 = *(_DWORD *)(result + 6496);
        *(_DWORD *)(result + 6524) = v229;
        v231 = v230 + *(_DWORD *)(v21 + 3384);
        v232 = *(_DWORD *)(result + 6528);
        *(_DWORD *)(result + 6496) = v231;
        v233 = v232 + *(_DWORD *)(v21 + 3416);
        v234 = *(_DWORD *)(result + 6500);
        *(_DWORD *)(result + 6528) = v233;
        v235 = v234 + *(_DWORD *)(v21 + 3388);
        v236 = *(_DWORD *)(result + 6532);
        *(_DWORD *)(result + 6500) = v235;
        v237 = v236 + *(_DWORD *)(v21 + 3420);
        v238 = *(_DWORD *)(result + 6844);
        *(_DWORD *)(result + 6532) = v237;
        v239 = v238 + *(_DWORD *)(v21 + 3424);
        v240 = *(_DWORD *)(result + 6848);
        *(_DWORD *)(result + 6844) = v239;
        v241 = v240 + *(_DWORD *)(v21 + 3428);
        v242 = *(_DWORD *)(result + 6852);
        *(_DWORD *)(result + 6848) = v241;
        v243 = v242 + *(_DWORD *)(v21 + 3432);
        v244 = *(_DWORD *)(result + 6856);
        *(_DWORD *)(result + 6852) = v243;
        v245 = v244 + *(_DWORD *)(v21 + 3436);
        v246 = *(_DWORD *)(result + 6860);
        *(_DWORD *)(result + 6856) = v245;
        v247 = v246 + *(_DWORD *)(v21 + 3440);
        v248 = *(_DWORD *)(result + 6864);
        *(_DWORD *)(result + 6860) = v247;
        v249 = v248 + *(_DWORD *)(v21 + 3444);
        v250 = *(_DWORD *)(result + 6868);
        *(_DWORD *)(result + 6864) = v249;
        v251 = v250 + *(_DWORD *)(v21 + 3448);
        v252 = *(_DWORD *)(result + 6872);
        *(_DWORD *)(result + 6868) = v251;
        v253 = v252 + *(_DWORD *)(v21 + 3452);
        v254 = *(_QWORD *)(result + 7400);
        *(_DWORD *)(result + 6872) = v253;
        *(_QWORD *)(result + 7400) = v254 + *(_QWORD *)(v21 + 3840);
        do
        {
          v255 = (_DWORD *)(v17 + v181);
          v256 = (_DWORD *)(result + 4720 + v181);
          v181 += 4;
          *v256 += *v255;
          v256[595] += v255[327];
        }
        while ( v181 != 68 );
        for ( i = 0; i != 68; i += 4 )
        {
          v258 = (_DWORD *)(v18 + i);
          v259 = (_DWORD *)(result + 4788 + i);
          *v259 += *v258;
          v259[595] += v258[327];
        }
        for ( j = 0; j != 68; j += 4 )
        {
          v261 = (_DWORD *)(v19 + j);
          v262 = (_DWORD *)(result + 4856 + j);
          *v262 += *v261;
          v262[595] += v261[327];
        }
        v263 = 0;
        v264 = *(_DWORD *)(result + 7304);
        *(_DWORD *)(result + 4924) += *(_DWORD *)(v21 + 2468);
        v265 = v264 + *(_DWORD *)(v21 + 3776);
        v266 = *(_DWORD *)(result + 4928);
        *(_DWORD *)(result + 7304) = v265;
        v267 = v266 + *(_DWORD *)(v21 + 2472);
        v268 = *(_DWORD *)(result + 7308);
        *(_DWORD *)(result + 4928) = v267;
        v269 = v268 + *(_DWORD *)(v21 + 3780);
        v270 = *(_DWORD *)(result + 4932);
        *(_DWORD *)(result + 7308) = v269;
        v271 = v270 + *(_DWORD *)(v21 + 2476);
        v272 = *(_DWORD *)(result + 7312);
        *(_DWORD *)(result + 4932) = v271;
        v273 = v272 + *(_DWORD *)(v21 + 3784);
        v274 = *(_DWORD *)(result + 4936);
        *(_DWORD *)(result + 7312) = v273;
        v275 = v274 + *(_DWORD *)(v21 + 2480);
        v276 = *(_DWORD *)(result + 7316);
        *(_DWORD *)(result + 4936) = v275;
        v277 = v276 + *(_DWORD *)(v21 + 3788);
        v278 = *(_DWORD *)(result + 4940);
        *(_DWORD *)(result + 7316) = v277;
        v279 = v278 + *(_DWORD *)(v21 + 2484);
        v280 = *(_DWORD *)(result + 7320);
        *(_DWORD *)(result + 4940) = v279;
        v281 = v280 + *(_DWORD *)(v21 + 3792);
        v282 = *(_QWORD *)(result + 2896);
        *(_DWORD *)(result + 7320) = v281;
        v283 = v282 + *(_QWORD *)v21;
        v284 = *(_QWORD *)(result + 2904);
        *(_QWORD *)(result + 2896) = v283;
        v285 = v284 + *(_QWORD *)(v21 + 8);
        v286 = *(_QWORD *)(result + 2912);
        *(_QWORD *)(result + 2904) = v285;
        v287 = v286 + *(_QWORD *)(v21 + 16);
        v288 = *(_QWORD *)(result + 2920);
        *(_QWORD *)(result + 2912) = v287;
        v289 = v288 + *(_QWORD *)(v21 + 24);
        v290 = *(_QWORD *)(result + 2928);
        *(_QWORD *)(result + 2920) = v289;
        v291 = v290 + *(_QWORD *)(v21 + 32);
        v292 = *(_QWORD *)(result + 2936);
        *(_QWORD *)(result + 2928) = v291;
        v293 = v292 + *(_QWORD *)(v21 + 40);
        v294 = *(_QWORD *)(result + 2944);
        *(_QWORD *)(result + 2936) = v293;
        v295 = v294 + *(_QWORD *)(v21 + 48);
        v296 = *(_QWORD *)(result + 2952);
        *(_QWORD *)(result + 2944) = v295;
        v297 = v296 + *(_QWORD *)(v21 + 56);
        v298 = *(_QWORD *)(result + 2960);
        *(_QWORD *)(result + 2952) = v297;
        v299 = v298 + *(_QWORD *)(v21 + 64);
        v300 = *(_QWORD *)(result + 2968);
        *(_QWORD *)(result + 2960) = v299;
        v301 = v300 + *(_QWORD *)(v21 + 72);
        LODWORD(v300) = *(_DWORD *)(result + 2976);
        *(_QWORD *)(result + 2968) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 80);
        LODWORD(v300) = *(_DWORD *)(result + 2984);
        *(_DWORD *)(result + 2976) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 84);
        LODWORD(v300) = *(_DWORD *)(result + 3004);
        *(_DWORD *)(result + 2984) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 88);
        LODWORD(v300) = *(_DWORD *)(result + 3008);
        *(_DWORD *)(result + 3004) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 92);
        LODWORD(v300) = *(_DWORD *)(result + 3828);
        *(_DWORD *)(result + 3008) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 176);
        LODWORD(v300) = *(_DWORD *)(result + 3832);
        *(_DWORD *)(result + 3828) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 180);
        LODWORD(v300) = *(_DWORD *)(result + 3836);
        *(_DWORD *)(result + 3832) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 184);
        LODWORD(v300) = *(_DWORD *)(result + 4968);
        *(_DWORD *)(result + 3836) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 548);
        LODWORD(v300) = *(_DWORD *)(result + 3840);
        *(_DWORD *)(result + 4968) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 188);
        LODWORD(v300) = *(_DWORD *)(result + 3844);
        *(_DWORD *)(result + 3840) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 192);
        LODWORD(v300) = *(_DWORD *)(result + 3848);
        *(_DWORD *)(result + 3844) = v301;
        LODWORD(v301) = v300 + *(_DWORD *)(v21 + 196);
        v302 = *(_QWORD *)(result + 4688);
        *(_DWORD *)(result + 3848) = v301;
        v303 = v302 + *(_QWORD *)(v21 + 456);
        v304 = *(_QWORD *)(result + 4696);
        *(_QWORD *)(result + 4688) = v303;
        v305 = v304 + *(_QWORD *)(v21 + 464);
        LODWORD(v304) = *(_DWORD *)(result + 4944);
        *(_QWORD *)(result + 4696) = v305;
        *(_QWORD *)(result + 4712) = *(_QWORD *)(v21 + 472);
        *(_DWORD *)(result + 4944) = v304 + *(_DWORD *)(v21 + 544);
        do
        {
          *(_DWORD *)(result + 4436 + v263) += *(_DWORD *)(v20 + v263);
          v263 += 4;
        }
        while ( v263 != 252 );
        ++v10;
        v12 += 4072;
        v13 += 4072;
        v14 += 4072;
        v15 += 4072;
        v16 += 4072;
        *(_DWORD *)(result + 5044) += *(_DWORD *)(v21 + 552);
        v17 += 4072;
        v18 += 4072;
        v19 += 4072;
        v20 += 4072;
        *(_DWORD *)(result + 5048) += *(_DWORD *)(v21 + 556);
        *(_DWORD *)(result + 5052) += *(_DWORD *)(v21 + 560);
        *(_DWORD *)(result + 5056) += *(_DWORD *)(v21 + 564);
        *(_DWORD *)(result + 5060) += *(_DWORD *)(v21 + 568);
        *(_DWORD *)(result + 5064) += *(_DWORD *)(v21 + 572);
        *(_DWORD *)(result + 5068) += *(_DWORD *)(v21 + 576);
        *(_DWORD *)(result + 5072) += *(_DWORD *)(v21 + 580);
        *(_DWORD *)(result + 5076) += *(_DWORD *)(v21 + 584);
        *(_DWORD *)(result + 5080) += *(_DWORD *)(v21 + 588);
        *(_DWORD *)(result + 5084) += *(_DWORD *)(v21 + 592);
        *(_DWORD *)(result + 5088) += *(_DWORD *)(v21 + 596);
        *(_DWORD *)(result + 5092) += *(_DWORD *)(v21 + 600);
        *(_DWORD *)(result + 5096) += *(_DWORD *)(v21 + 604);
        *(_QWORD *)(result + 5832) += *(_QWORD *)(v21 + 784);
        *(_QWORD *)(result + 5840) += *(_QWORD *)(v21 + 792);
        *(_QWORD *)(result + 5920) += *(_QWORD *)(v21 + 992);
        *(_QWORD *)(result + 5928) += *(_QWORD *)(v21 + 1000);
        *(_QWORD *)(result + 5848) += *(_QWORD *)(v21 + 800);
        *(_QWORD *)(result + 5856) += *(_QWORD *)(v21 + 808);
        *(_QWORD *)(result + 5816) += *(_QWORD *)(v21 + 768);
        *(_QWORD *)(result + 5824) += *(_QWORD *)(v21 + 776);
        *(_QWORD *)(result + 5864) += *(_QWORD *)(v21 + 816);
        *(_QWORD *)(result + 5872) += *(_QWORD *)(v21 + 824);
        *(_DWORD *)(result + 5880) += *(_DWORD *)(v21 + 832);
        *(_DWORD *)(result + 7324) += *(_DWORD *)(v21 + 1008);
        *(_QWORD *)(result + 5888) += *(_QWORD *)(v21 + 840);
        *(_QWORD *)(result + 5896) += *(_QWORD *)(v21 + 848);
        *(_QWORD *)(result + 5904) += *(_QWORD *)(v21 + 856);
        *(_QWORD *)(result + 5912) += *(_QWORD *)(v21 + 864);
        *(_QWORD *)(result + 5944) += *(_QWORD *)(v21 + 880);
        *(_QWORD *)(result + 5952) += *(_QWORD *)(v21 + 888);
        *(_QWORD *)(result + 5960) += *(_QWORD *)(v21 + 896);
        *(_QWORD *)(result + 5968) += *(_QWORD *)(v21 + 904);
        *(_DWORD *)(result + 5976) += *(_DWORD *)(v21 + 912);
        *(_DWORD *)(result + 5984) += *(_DWORD *)(v21 + 920);
        *(_DWORD *)(result + 5988) += *(_DWORD *)(v21 + 924);
        *(_DWORD *)(result + 5992) += *(_DWORD *)(v21 + 928);
        *(_DWORD *)(result + 5996) += *(_DWORD *)(v21 + 932);
        *(_DWORD *)(result + 6000) += *(_DWORD *)(v21 + 936);
        *(_DWORD *)(result + 6004) += *(_DWORD *)(v21 + 940);
        *(_DWORD *)(result + 6008) += *(_DWORD *)(v21 + 944);
        *(_DWORD *)(result + 6884) += *(_DWORD *)(v21 + 948);
        *(_DWORD *)(result + 6888) += *(_DWORD *)(v21 + 952);
        *(_DWORD *)(result + 6952) += *(_DWORD *)(v21 + 956);
        *(_DWORD *)(result + 6996) += *(_DWORD *)(v21 + 960);
        *(_DWORD *)(result + 7000) += *(_DWORD *)(v21 + 964);
        *(_DWORD *)(result + 7004) += *(_DWORD *)(v21 + 968);
        *(_QWORD *)(result + 7080) += *(_QWORD *)(v21 + 976);
        *(_QWORD *)(result + 7088) += *(_QWORD *)(v21 + 984);
        *(_QWORD *)(result + 5936) = *(_QWORD *)(v21 + 872);
        *(_DWORD *)(result + 7336) += *(_DWORD *)(v21 + 1032);
        *(_QWORD *)(result + 5640) += *(_QWORD *)(v21 + 608);
        *(_QWORD *)(result + 5648) += *(_QWORD *)(v21 + 616);
        v306 = *(_QWORD *)(result + 5768) + *(_QWORD *)(v21 + 608);
        v307 = *(_QWORD *)(result + 5776);
        *(_QWORD *)(result + 5768) = v306;
        v308 = v307 + *(_QWORD *)(v21 + 616);
        v309 = *(_QWORD *)(result + 5656);
        *(_QWORD *)(result + 5776) = v308;
        *(_QWORD *)(result + 5656) = v309 + *(_QWORD *)(v21 + 624);
        *(_QWORD *)(result + 5664) += *(_QWORD *)(v21 + 632);
        v310 = v306 + *(_QWORD *)(v21 + 624);
        *(_QWORD *)(result + 5768) = v310;
        v311 = v308 + *(_QWORD *)(v21 + 632);
        v312 = *(_QWORD *)(result + 5672);
        *(_QWORD *)(result + 5776) = v311;
        *(_QWORD *)(result + 5672) = v312 + *(_QWORD *)(v21 + 640);
        *(_QWORD *)(result + 5680) += *(_QWORD *)(v21 + 648);
        v313 = v310 + *(_QWORD *)(v21 + 640);
        *(_QWORD *)(result + 5768) = v313;
        v314 = v311 + *(_QWORD *)(v21 + 648);
        v315 = *(_QWORD *)(result + 5688);
        *(_QWORD *)(result + 5776) = v314;
        *(_QWORD *)(result + 5688) = v315 + *(_QWORD *)(v21 + 656);
        *(_QWORD *)(result + 5696) += *(_QWORD *)(v21 + 664);
        v316 = v313 + *(_QWORD *)(v21 + 656);
        *(_QWORD *)(result + 5768) = v316;
        v317 = v314 + *(_QWORD *)(v21 + 664);
        v318 = *(_QWORD *)(result + 5704);
        *(_QWORD *)(result + 5776) = v317;
        *(_QWORD *)(result + 5704) = v318 + *(_QWORD *)(v21 + 672);
        *(_QWORD *)(result + 5712) += *(_QWORD *)(v21 + 680);
        v319 = v316 + *(_QWORD *)(v21 + 672);
        *(_QWORD *)(result + 5768) = v319;
        v320 = v317 + *(_QWORD *)(v21 + 680);
        v321 = *(_QWORD *)(result + 5720);
        *(_QWORD *)(result + 5776) = v320;
        *(_QWORD *)(result + 5720) = v321 + *(_QWORD *)(v21 + 688);
        *(_QWORD *)(result + 5728) += *(_QWORD *)(v21 + 696);
        v322 = v319 + *(_QWORD *)(v21 + 688);
        *(_QWORD *)(result + 5768) = v322;
        v323 = v320 + *(_QWORD *)(v21 + 696);
        v324 = *(_QWORD *)(result + 5736);
        *(_QWORD *)(result + 5776) = v323;
        *(_QWORD *)(result + 5736) = v324 + *(_QWORD *)(v21 + 704);
        *(_QWORD *)(result + 5744) += *(_QWORD *)(v21 + 712);
        v325 = v322 + *(_QWORD *)(v21 + 704);
        *(_QWORD *)(result + 5768) = v325;
        v326 = v323 + *(_QWORD *)(v21 + 712);
        v327 = *(_QWORD *)(result + 5752);
        *(_QWORD *)(result + 5776) = v326;
        *(_QWORD *)(result + 5752) = v327 + *(_QWORD *)(v21 + 720);
        *(_QWORD *)(result + 5760) += *(_QWORD *)(v21 + 728);
        *(_QWORD *)(result + 5768) = v325 + *(_QWORD *)(v21 + 720);
        *(_QWORD *)(result + 5776) = v326 + *(_QWORD *)(v21 + 728);
        *(_QWORD *)(result + 5784) += *(_QWORD *)(v21 + 736);
        *(_QWORD *)(result + 5792) += *(_QWORD *)(v21 + 744);
        *(_QWORD *)(result + 5800) += *(_QWORD *)(v21 + 752);
        *(_QWORD *)(result + 5808) += *(_QWORD *)(v21 + 760);
        *(_QWORD *)(result + 7376) += *(_QWORD *)(v21 + 1016);
        *(_QWORD *)(result + 7384) += *(_QWORD *)(v21 + 1024);
        *(_QWORD *)(result + 3632) += *(unsigned int *)(v21 + 100);
        *(_QWORD *)(result + 3640) += *(_QWORD *)(v21 + 160);
        *(_DWORD *)(result + 3648) += *(_DWORD *)(v21 + 108);
        *(_QWORD *)(result + 3656) += *(unsigned int *)(v21 + 104);
        *(_QWORD *)(result + 3664) += *(_QWORD *)(v21 + 168);
        *(_DWORD *)(result + 3672) += *(_DWORD *)(v21 + 112);
        *(_DWORD *)(result + 3676) += *(_DWORD *)(v21 + 116);
        *(_DWORD *)(result + 3680) += *(_DWORD *)(v21 + 120);
        *(_DWORD *)(result + 3684) += *(_DWORD *)(v21 + 124);
        *(_DWORD *)(result + 3688) += *(_DWORD *)(v21 + 128);
        *(_DWORD *)(result + 3692) += *(_DWORD *)(v21 + 132);
        *(_DWORD *)(result + 3696) += *(_DWORD *)(v21 + 136);
        *(_DWORD *)(result + 3700) += *(_DWORD *)(v21 + 140);
        *(_DWORD *)(result + 3704) += *(_DWORD *)(v21 + 144);
        *(_DWORD *)(result + 3708) += *(_DWORD *)(v21 + 148);
        *(_DWORD *)(result + 3712) += *(_DWORD *)(v21 + 156);
      }
      while ( v10 != v329 );
    }
  }
  return result;
}
