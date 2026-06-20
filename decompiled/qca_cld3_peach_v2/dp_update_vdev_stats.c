__int64 __fastcall dp_update_vdev_stats(__int64 a1, __int64 *a2, __int64 a3)
{
  __int64 *v3; // x19
  __int64 *v5; // x8
  __int64 *v6; // x8
  __int64 v7; // x11
  __int64 v8; // x10
  __int64 v9; // x9
  __int64 v10; // x10
  __int64 v11; // x9
  __int64 v12; // x10
  __int64 v13; // x21
  __int64 v14; // x10
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  __int64 v19; // x22
  __int64 v20; // x23
  __int64 v21; // x24
  __int64 v22; // x25
  __int64 v23; // x28
  __int64 v24; // x30
  int v25; // w19
  int v26; // w11
  int v27; // w19
  int v28; // w11
  int v29; // w19
  int v30; // w11
  int v31; // w19
  int v32; // w11
  int v33; // w19
  int v34; // w11
  int v35; // w19
  int v36; // w11
  int v37; // w19
  int v38; // w11
  int v39; // w19
  int v40; // w11
  int v41; // w19
  int v42; // w11
  int v43; // w19
  unsigned int v44; // w19
  unsigned int v45; // w19
  unsigned int v46; // w19
  unsigned int v47; // w19
  int v48; // w19
  _DWORD *v49; // x11
  _DWORD *v50; // x19
  int v51; // w10
  int v52; // w26
  int v53; // w26
  int v54; // w26
  int v55; // w26
  int v56; // w26
  int v57; // w26
  int v58; // w26
  int v59; // w10
  __int64 v60; // x30
  __int64 v61; // x19
  __int64 v62; // x11
  __int64 v63; // x19
  __int64 v64; // x11
  __int64 v65; // x19
  __int64 v66; // x11
  __int64 v67; // x19
  __int64 v68; // x11
  _DWORD *v69; // x10
  _DWORD *v70; // x8
  int v71; // w26
  __int64 v72; // x11
  int v73; // w10
  int v74; // w8
  int v75; // w10
  int v76; // w8
  int v77; // w10
  int v78; // w8
  int v79; // w10
  int v80; // w8
  int v81; // w10
  int v82; // w8
  int v83; // w10
  int v84; // w8
  int v85; // w10
  int v86; // w8
  int v87; // w10
  int v88; // w8
  int v89; // w10
  int v90; // w8
  int v91; // w10
  int v92; // w8
  int v93; // w10
  int v94; // w8
  int v95; // w10
  int v96; // w8
  int v97; // w10
  int v98; // w8
  int v99; // w10
  int v100; // w8
  int v101; // w10
  int v102; // w8
  int v103; // w10
  int v104; // w8
  int v105; // w10
  int v106; // w8
  int v107; // w10
  int v108; // w8
  int v109; // w10
  int v110; // w8
  int v111; // w10
  int v112; // w8
  int v113; // w10
  int v114; // w8
  int v115; // w10
  int v116; // w8
  int v117; // w10
  int v118; // w8
  int v119; // w10
  int v120; // w8
  int v121; // w10
  int v122; // w8
  int v123; // w10
  __int64 v124; // x30
  int v125; // w11
  __int64 v126; // x10
  __int64 v127; // x8
  __int64 v128; // x10
  __int64 v129; // x8
  __int64 v130; // x10
  __int64 v131; // x8
  __int64 v132; // x10
  __int64 v133; // x8
  __int64 v134; // x10
  __int64 v135; // x8
  __int64 v136; // x10
  __int64 v137; // x8
  unsigned int v138; // w11
  unsigned int v139; // w11
  unsigned int v140; // w11
  unsigned int v141; // w11
  _DWORD *v142; // x11
  _DWORD *v143; // x19
  int v144; // w26
  int v145; // w26
  int v146; // w26
  int v147; // w26
  int v148; // w26
  int v149; // w26
  int v150; // w26
  int v151; // w26
  int v152; // w10
  __int64 v153; // x11
  __int64 v154; // x10
  __int64 v155; // x8
  __int64 v156; // x10
  __int64 v157; // x8
  __int64 v158; // x10
  __int64 v159; // x8
  __int64 v160; // x10
  _DWORD *v161; // x8
  _DWORD *v162; // x10
  __int64 v163; // x11
  char v164; // w26
  _DWORD *v165; // x19
  _DWORD *v166; // x11
  int v167; // w9
  int v168; // w10
  int v169; // w10
  int v170; // w10
  int v171; // w10
  int v172; // w10
  int v173; // w10
  int v174; // w10
  int v175; // w10
  int v176; // w10
  int v177; // w10
  int v178; // w10
  int v179; // w10
  int v180; // w9
  int v181; // w8
  int v182; // w8
  __int64 v183; // x30
  int v184; // w10
  int v185; // w8
  int v186; // w10
  int v187; // w8
  int v188; // w10
  int v189; // w8
  int v190; // w10
  int v191; // w8
  int v192; // w10
  int v193; // w8
  int v194; // w10
  int v195; // w8
  int v196; // w10
  int v197; // w8
  int v198; // w10
  int v199; // w8
  int v200; // w10
  int v201; // w8
  int v202; // w10
  int v203; // w8
  int v204; // w10
  int v205; // w8
  int v206; // w10
  int v207; // w8
  int v208; // w10
  int v209; // w8
  int v210; // w10
  int v211; // w8
  int v212; // w10
  int v213; // w8
  int v214; // w10
  int v215; // w8
  int v216; // w10
  int v217; // w8
  int v218; // w10
  int v219; // w8
  int v220; // w10
  int v221; // w8
  int v222; // w10
  int v223; // w8
  int v224; // w10
  int v225; // w8
  int v226; // w10
  int v227; // w8
  int v228; // w10
  int v229; // w8
  int v230; // w10
  int v231; // w8
  int v232; // w10
  int v233; // w8
  int v234; // w10
  int v235; // w8
  int v236; // w10
  int v237; // w8
  int v238; // w10
  int v239; // w8
  int v240; // w10
  int v241; // w8
  int v242; // w10
  int v243; // w8
  int v244; // w10
  int v245; // w8
  int v246; // w10
  int v247; // w8
  int v248; // w10
  int v249; // w8
  int v250; // w10
  int v251; // w8
  int v252; // w10
  int v253; // w8
  int v254; // w10
  int v255; // w8
  __int64 v256; // x10
  _DWORD *v257; // x8
  _DWORD *v258; // x9
  __int64 i; // x11
  _DWORD *v260; // x8
  _DWORD *v261; // x9
  __int64 j; // x11
  _DWORD *v263; // x8
  _DWORD *v264; // x9
  __int64 v265; // x26
  int v266; // w9
  int v267; // w8
  int v268; // w9
  int v269; // w8
  int v270; // w9
  int v271; // w8
  int v272; // w9
  int v273; // w8
  int v274; // w9
  int v275; // w8
  int v276; // w9
  int v277; // w8
  int v278; // w9
  int v279; // w8
  int v280; // w9
  int v281; // w8
  int v282; // w9
  int v283; // w8
  __int64 v284; // x9
  __int64 v285; // x8
  __int64 v286; // x9
  __int64 v287; // x8
  __int64 v288; // x9
  __int64 v289; // x8
  __int64 v290; // x9
  __int64 v291; // x8
  __int64 v292; // x9
  __int64 v293; // x8
  __int64 v294; // x9
  __int64 v295; // x8
  __int64 v296; // x9
  __int64 v297; // x8
  __int64 v298; // x9
  __int64 v299; // x8
  __int64 v300; // x9
  __int64 v301; // x8
  __int64 v302; // x9
  __int64 v303; // x8
  __int64 v304; // x9
  __int64 v305; // x8
  __int64 v306; // x9
  __int64 v307; // x8
  __int64 v308; // x8
  __int64 v309; // x9
  __int64 v310; // x9
  __int64 v311; // x10
  __int64 v312; // x8
  __int64 v313; // x9
  __int64 v314; // x10
  __int64 v315; // x8
  __int64 v316; // x9
  __int64 v317; // x10
  __int64 v318; // x8
  __int64 v319; // x9
  __int64 v320; // x10
  __int64 v321; // x8
  __int64 v322; // x9
  __int64 v323; // x10
  __int64 v324; // x8
  __int64 v325; // x9
  __int64 v326; // x10
  __int64 v327; // x8
  __int64 v328; // x9
  __int64 v329; // x10
  __int64 *v330; // x8
  __int64 *v332; // [xsp+8h] [xbp-28h]
  __int64 v333; // [xsp+10h] [xbp-20h]
  __int64 v334; // [xsp+20h] [xbp-10h]
  __int64 v335; // [xsp+28h] [xbp-8h]

  v3 = a2;
  if ( *((_DWORD *)a2 + 102) != 1 || (v5 = (__int64 *)a2[52]) == nullptr )
    v5 = a2;
  raw_spin_lock(v5 + 19);
  if ( *((_DWORD *)v3 + 102) != 1 )
    goto LABEL_37;
  v6 = (__int64 *)v3[52];
  v332 = v3;
  if ( v6 )
  {
    v7 = *v6;
    if ( !*v6 || (v3[16] & 2) == 0 )
      goto LABEL_35;
  }
  else
  {
    v7 = *v3;
    if ( !*v3 )
      goto LABEL_35;
  }
  v334 = *(unsigned __int8 *)(v7 + 2281);
  if ( a3 )
  {
    v8 = *(_QWORD *)(a3 + 2480);
    *(_QWORD *)(a3 + 2472) += *(_QWORD *)(v7 + 16);
    v9 = v8 + *(_QWORD *)(v7 + 24);
    LODWORD(v8) = *(_DWORD *)(a3 + 2572);
    *(_QWORD *)(a3 + 2480) = v9;
    LODWORD(v9) = v8 + *(_DWORD *)(v7 + 12);
    v10 = *(_QWORD *)(a3 + 5216);
    *(_DWORD *)(a3 + 2572) = v9;
    v11 = v10 + *(_QWORD *)(v7 + 32);
    v12 = *(_QWORD *)(a3 + 5224);
    *(_QWORD *)(a3 + 5216) = v11;
    *(_QWORD *)(a3 + 5224) = v12 + *(_QWORD *)(v7 + 40);
  }
  if ( (_DWORD)v334 )
  {
    v13 = v7 + 5312;
    v14 = 0;
    v15 = v7 + 3404;
    v16 = v7 + 3948;
    v17 = v7 + 4240;
    v18 = v7 + 4928;
    v19 = v7 + 4552;
    v20 = v7 + 4620;
    v21 = v7 + 4688;
    v22 = v7 + 2488;
    v333 = v7 + 2288;
    do
    {
      v23 = v333 + 4072 * v14;
      v24 = 0;
      v335 = v14;
      v25 = *(_DWORD *)(a3 + 2584);
      *(_DWORD *)(a3 + 2580) += *(_DWORD *)(v23 + 1040);
      v26 = v25 + *(_DWORD *)(v23 + 1044);
      v27 = *(_DWORD *)(a3 + 2588);
      *(_DWORD *)(a3 + 2584) = v26;
      v28 = v27 + *(_DWORD *)(v23 + 1048);
      v29 = *(_DWORD *)(a3 + 3412);
      *(_DWORD *)(a3 + 2588) = v28;
      v30 = v29 + *(_DWORD *)(v23 + 1492);
      v31 = *(_DWORD *)(a3 + 3416);
      *(_DWORD *)(a3 + 3412) = v30;
      v32 = v31 + *(_DWORD *)(v23 + 1496);
      v33 = *(_DWORD *)(a3 + 4024);
      *(_DWORD *)(a3 + 3416) = v32;
      v34 = v33 + *(_DWORD *)(v23 + 1500);
      v35 = *(_DWORD *)(a3 + 3448);
      *(_DWORD *)(a3 + 4024) = v34;
      v36 = v35 + *(_DWORD *)(v23 + 1504);
      v37 = *(_DWORD *)(a3 + 3452);
      *(_DWORD *)(a3 + 3448) = v36;
      v38 = v37 + *(_DWORD *)(v23 + 1508);
      v39 = *(_DWORD *)(a3 + 3456);
      *(_DWORD *)(a3 + 3452) = v38;
      v40 = v39 + *(_DWORD *)(v23 + 1512);
      v41 = *(_DWORD *)(a3 + 3108);
      *(_DWORD *)(a3 + 3456) = v40;
      *(_DWORD *)(a3 + 2604) = *(_DWORD *)(v23 + 1516);
      *(_DWORD *)(a3 + 2608) = *(_DWORD *)(v23 + 1520);
      *(_DWORD *)(a3 + 2612) = *(_DWORD *)(v23 + 1524);
      *(_DWORD *)(a3 + 2616) = *(_DWORD *)(v23 + 1528);
      *(_DWORD *)(a3 + 2620) = *(_DWORD *)(v23 + 1532);
      *(_QWORD *)(a3 + 2632) = *(_QWORD *)(v23 + 1536);
      *(_QWORD *)(a3 + 2640) = *(_QWORD *)(v23 + 1544);
      *(_WORD *)(a3 + 3408) = *(_WORD *)(v23 + 1552);
      v42 = v41 + *(_DWORD *)(v23 + 1576);
      v43 = *(_DWORD *)(a3 + 4296);
      *(_DWORD *)(a3 + 3108) = v42;
      *(_DWORD *)(a3 + 3824) = *(_DWORD *)(v23 + 1644);
      *(_DWORD *)(a3 + 3828) = *(_DWORD *)(v23 + 1648);
      *(_DWORD *)(a3 + 2648) = *(_DWORD *)(v23 + 2208);
      *(_DWORD *)(a3 + 2652) = *(_DWORD *)(v23 + 2212);
      v44 = v43 & 0xFFFFFFF0 | *(_DWORD *)(v23 + 2220) & 0xF;
      *(_DWORD *)(a3 + 4296) = v44;
      v45 = v44 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v23 + 2220) >> 4) & 0xF));
      *(_DWORD *)(a3 + 4296) = v45;
      v46 = v45 & 0xFFFFF0FF | (((*(_DWORD *)(v23 + 2220) >> 8) & 0xF) << 8);
      *(_DWORD *)(a3 + 4296) = v46;
      v47 = v46 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v23 + 2220)) >> 4 << 12);
      *(_DWORD *)(a3 + 4296) = v47;
      *(_DWORD *)(a3 + 4296) = v47 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v23 + 2220)) & 0xF) << 16);
      v48 = *(_DWORD *)(a3 + 4300);
      *(_DWORD *)(a3 + 2592) += *(_DWORD *)(v23 + 2224);
      *(_DWORD *)(a3 + 4300) = v48 + *(_DWORD *)(v23 + 2228);
      *(_DWORD *)(a3 + 4544) = *(_DWORD *)(v23 + 2488);
      *(_DWORD *)(a3 + 4548) = *(_DWORD *)(v23 + 2492);
      *(_DWORD *)(a3 + 4552) = *(_DWORD *)(v23 + 2496);
      *(_DWORD *)(a3 + 4556) = *(_DWORD *)(v23 + 2500);
      do
      {
        v49 = (_DWORD *)(a3 + 2680 + v24);
        v50 = (_DWORD *)(v15 + v24);
        v24 += 68;
        v51 = v49[1];
        *v49 += *(v50 - 16);
        v49[1] = v51 + *(v50 - 15);
        v52 = v49[3];
        v49[2] += *(v50 - 14);
        v49[3] = v52 + *(v50 - 13);
        v53 = v49[5];
        v49[4] += *(v50 - 12);
        v49[5] = v53 + *(v50 - 11);
        v54 = v49[7];
        v49[6] += *(v50 - 10);
        v49[7] = v54 + *(v50 - 9);
        v55 = v49[9];
        v49[8] += *(v50 - 8);
        v49[9] = v55 + *(v50 - 7);
        v56 = v49[11];
        v49[10] += *(v50 - 6);
        v49[11] = v56 + *(v50 - 5);
        v57 = v49[13];
        v49[12] += *(v50 - 4);
        v49[13] = v57 + *(v50 - 3);
        v58 = v49[15];
        v59 = v49[16];
        v49[14] += *(v50 - 2);
        v49[15] = v58 + *(v50 - 1);
        v49[16] = v59 + *v50;
      }
      while ( v24 != 408 );
      v60 = 0;
      v61 = *(_QWORD *)(a3 + 4568);
      *(_DWORD *)(a3 + 3176) += *(_DWORD *)(v23 + 1460);
      v62 = v61 + *(_QWORD *)(v23 + 2536);
      LODWORD(v61) = *(_DWORD *)(a3 + 3192);
      *(_QWORD *)(a3 + 4568) = v62;
      LODWORD(v62) = v61 + *(_DWORD *)(v23 + 1476);
      LODWORD(v61) = *(_DWORD *)(a3 + 3180);
      *(_DWORD *)(a3 + 3192) = v62;
      LODWORD(v62) = v61 + *(_DWORD *)(v23 + 1464);
      v63 = *(_QWORD *)(a3 + 4576);
      *(_DWORD *)(a3 + 3180) = v62;
      v64 = v63 + *(_QWORD *)(v23 + 2544);
      LODWORD(v63) = *(_DWORD *)(a3 + 3196);
      *(_QWORD *)(a3 + 4576) = v64;
      LODWORD(v64) = v63 + *(_DWORD *)(v23 + 1480);
      LODWORD(v63) = *(_DWORD *)(a3 + 3184);
      *(_DWORD *)(a3 + 3196) = v64;
      LODWORD(v64) = v63 + *(_DWORD *)(v23 + 1468);
      v65 = *(_QWORD *)(a3 + 4584);
      *(_DWORD *)(a3 + 3184) = v64;
      v66 = v65 + *(_QWORD *)(v23 + 2552);
      LODWORD(v65) = *(_DWORD *)(a3 + 3200);
      *(_QWORD *)(a3 + 4584) = v66;
      LODWORD(v66) = v65 + *(_DWORD *)(v23 + 1484);
      LODWORD(v65) = *(_DWORD *)(a3 + 3188);
      *(_DWORD *)(a3 + 3200) = v66;
      LODWORD(v66) = v65 + *(_DWORD *)(v23 + 1472);
      v67 = *(_QWORD *)(a3 + 4592);
      *(_DWORD *)(a3 + 3188) = v66;
      v68 = v67 + *(_QWORD *)(v23 + 2560);
      LODWORD(v67) = *(_DWORD *)(a3 + 3204);
      *(_QWORD *)(a3 + 4592) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1488);
      LODWORD(v67) = *(_DWORD *)(a3 + 3088);
      *(_DWORD *)(a3 + 3204) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1556);
      LODWORD(v67) = *(_DWORD *)(a3 + 3092);
      *(_DWORD *)(a3 + 3088) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1560);
      LODWORD(v67) = *(_DWORD *)(a3 + 3096);
      *(_DWORD *)(a3 + 3092) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1564);
      LODWORD(v67) = *(_DWORD *)(a3 + 3100);
      *(_DWORD *)(a3 + 3096) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1568);
      LODWORD(v67) = *(_DWORD *)(a3 + 3104);
      *(_DWORD *)(a3 + 3100) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1572);
      LODWORD(v67) = *(_DWORD *)(a3 + 3112);
      *(_DWORD *)(a3 + 3104) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1580);
      LODWORD(v67) = *(_DWORD *)(a3 + 3116);
      *(_DWORD *)(a3 + 3112) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1584);
      LODWORD(v67) = *(_DWORD *)(a3 + 3120);
      *(_DWORD *)(a3 + 3116) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1588);
      LODWORD(v67) = *(_DWORD *)(a3 + 3124);
      *(_DWORD *)(a3 + 3120) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1592);
      LODWORD(v67) = *(_DWORD *)(a3 + 3128);
      *(_DWORD *)(a3 + 3124) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1596);
      LODWORD(v67) = *(_DWORD *)(a3 + 3132);
      *(_DWORD *)(a3 + 3128) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1600);
      LODWORD(v67) = *(_DWORD *)(a3 + 3136);
      *(_DWORD *)(a3 + 3132) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1604);
      LODWORD(v67) = *(_DWORD *)(a3 + 3140);
      *(_DWORD *)(a3 + 3136) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1608);
      LODWORD(v67) = *(_DWORD *)(a3 + 3144);
      *(_DWORD *)(a3 + 3140) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1612);
      LODWORD(v67) = *(_DWORD *)(a3 + 3148);
      *(_DWORD *)(a3 + 3144) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1616);
      LODWORD(v67) = *(_DWORD *)(a3 + 3152);
      *(_DWORD *)(a3 + 3148) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1620);
      LODWORD(v67) = *(_DWORD *)(a3 + 3156);
      *(_DWORD *)(a3 + 3152) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1624);
      LODWORD(v67) = *(_DWORD *)(a3 + 3160);
      *(_DWORD *)(a3 + 3156) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1628);
      LODWORD(v67) = *(_DWORD *)(a3 + 3164);
      *(_DWORD *)(a3 + 3160) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1632);
      LODWORD(v67) = *(_DWORD *)(a3 + 3168);
      *(_DWORD *)(a3 + 3164) = v68;
      LODWORD(v68) = v67 + *(_DWORD *)(v23 + 1636);
      LODWORD(v67) = *(_DWORD *)(a3 + 3172);
      *(_DWORD *)(a3 + 3168) = v68;
      *(_DWORD *)(a3 + 3172) = v67 + *(_DWORD *)(v23 + 1640);
      do
      {
        v69 = (_DWORD *)(a3 + 3832 + v60);
        v70 = (_DWORD *)(v16 + v60);
        v60 += 12;
        v71 = v69[1];
        *v69 += *(v70 - 2);
        v69[1] = v71 + *(v70 - 1);
        v69[2] += *v70;
      }
      while ( v60 != 192 );
      v72 = 0;
      v73 = *(_DWORD *)(a3 + 3464);
      *(_DWORD *)(a3 + 3460) += *(_DWORD *)(v23 + 1844);
      v74 = v73 + *(_DWORD *)(v23 + 1848);
      v75 = *(_DWORD *)(a3 + 3468);
      *(_DWORD *)(a3 + 3464) = v74;
      v76 = v75 + *(_DWORD *)(v23 + 1852);
      v77 = *(_DWORD *)(a3 + 3472);
      *(_DWORD *)(a3 + 3468) = v76;
      v78 = v77 + *(_DWORD *)(v23 + 1856);
      v79 = *(_DWORD *)(a3 + 3476);
      *(_DWORD *)(a3 + 3472) = v78;
      v80 = v79 + *(_DWORD *)(v23 + 1860);
      v81 = *(_DWORD *)(a3 + 3480);
      *(_DWORD *)(a3 + 3476) = v80;
      v82 = v81 + *(_DWORD *)(v23 + 1864);
      v83 = *(_DWORD *)(a3 + 3484);
      *(_DWORD *)(a3 + 3480) = v82;
      v84 = v83 + *(_DWORD *)(v23 + 1868);
      v85 = *(_DWORD *)(a3 + 3488);
      *(_DWORD *)(a3 + 3484) = v84;
      v86 = v85 + *(_DWORD *)(v23 + 1872);
      v87 = *(_DWORD *)(a3 + 3492);
      *(_DWORD *)(a3 + 3488) = v86;
      v88 = v87 + *(_DWORD *)(v23 + 1876);
      v89 = *(_DWORD *)(a3 + 3496);
      *(_DWORD *)(a3 + 3492) = v88;
      v90 = v89 + *(_DWORD *)(v23 + 1880);
      v91 = *(_DWORD *)(a3 + 3500);
      *(_DWORD *)(a3 + 3496) = v90;
      v92 = v91 + *(_DWORD *)(v23 + 1884);
      v93 = *(_DWORD *)(a3 + 3504);
      *(_DWORD *)(a3 + 3500) = v92;
      v94 = v93 + *(_DWORD *)(v23 + 1888);
      v95 = *(_DWORD *)(a3 + 3508);
      *(_DWORD *)(a3 + 3504) = v94;
      v96 = v95 + *(_DWORD *)(v23 + 1892);
      v97 = *(_DWORD *)(a3 + 3512);
      *(_DWORD *)(a3 + 3508) = v96;
      v98 = v97 + *(_DWORD *)(v23 + 1896);
      v99 = *(_DWORD *)(a3 + 3516);
      *(_DWORD *)(a3 + 3512) = v98;
      v100 = v99 + *(_DWORD *)(v23 + 1900);
      v101 = *(_DWORD *)(a3 + 3520);
      *(_DWORD *)(a3 + 3516) = v100;
      v102 = v101 + *(_DWORD *)(v23 + 1904);
      v103 = *(_DWORD *)(a3 + 3524);
      *(_DWORD *)(a3 + 3520) = v102;
      v104 = v103 + *(_DWORD *)(v23 + 1908);
      v105 = *(_DWORD *)(a3 + 3528);
      *(_DWORD *)(a3 + 3524) = v104;
      v106 = v105 + *(_DWORD *)(v23 + 1912);
      v107 = *(_DWORD *)(a3 + 3532);
      *(_DWORD *)(a3 + 3528) = v106;
      v108 = v107 + *(_DWORD *)(v23 + 1916);
      v109 = *(_DWORD *)(a3 + 3536);
      *(_DWORD *)(a3 + 3532) = v108;
      v110 = v109 + *(_DWORD *)(v23 + 1920);
      v111 = *(_DWORD *)(a3 + 3540);
      *(_DWORD *)(a3 + 3536) = v110;
      v112 = v111 + *(_DWORD *)(v23 + 1924);
      v113 = *(_DWORD *)(a3 + 3544);
      *(_DWORD *)(a3 + 3540) = v112;
      v114 = v113 + *(_DWORD *)(v23 + 1928);
      v115 = *(_DWORD *)(a3 + 3548);
      *(_DWORD *)(a3 + 3544) = v114;
      v116 = v115 + *(_DWORD *)(v23 + 1932);
      v117 = *(_DWORD *)(a3 + 3552);
      *(_DWORD *)(a3 + 3548) = v116;
      v118 = v117 + *(_DWORD *)(v23 + 1936);
      v119 = *(_DWORD *)(a3 + 3556);
      *(_DWORD *)(a3 + 3552) = v118;
      v120 = v119 + *(_DWORD *)(v23 + 1940);
      v121 = *(_DWORD *)(a3 + 3560);
      *(_DWORD *)(a3 + 3556) = v120;
      v122 = v121 + *(_DWORD *)(v23 + 1944);
      v123 = *(_DWORD *)(a3 + 3564);
      *(_DWORD *)(a3 + 3560) = v122;
      *(_DWORD *)(a3 + 3564) = v123 + *(_DWORD *)(v23 + 1948);
      do
      {
        *(_DWORD *)(a3 + 3568 + v72) = *(_DWORD *)(v17 + v72);
        v72 += 4;
      }
      while ( v72 != 256 );
      v124 = 0;
      v125 = *(_DWORD *)(a3 + 6668);
      v126 = *(_QWORD *)(a3 + 4608);
      *(_QWORD *)(a3 + 4600) += *(_QWORD *)(v23 + 2232);
      v127 = v126 + *(_QWORD *)(v23 + 2240);
      v128 = *(_QWORD *)(a3 + 4616);
      *(_QWORD *)(a3 + 4608) = v127;
      v129 = v128 + *(_QWORD *)(v23 + 2248);
      v130 = *(_QWORD *)(a3 + 4624);
      *(_QWORD *)(a3 + 4616) = v129;
      v131 = v130 + *(_QWORD *)(v23 + 2256);
      v132 = *(_QWORD *)(a3 + 5208);
      *(_QWORD *)(a3 + 4624) = v131;
      *(_DWORD *)(a3 + 3348) = *(_DWORD *)(v23 + 2504);
      *(_DWORD *)(a3 + 3352) = *(_DWORD *)(v23 + 2508);
      *(_DWORD *)(a3 + 3356) = *(_DWORD *)(v23 + 2512);
      *(_DWORD *)(a3 + 3360) = *(_DWORD *)(v23 + 2516);
      *(_DWORD *)(a3 + 3364) = *(_DWORD *)(v23 + 2520);
      *(_DWORD *)(a3 + 3368) = *(_DWORD *)(v23 + 2524);
      *(_DWORD *)(a3 + 3372) = *(_DWORD *)(v23 + 2528);
      *(_DWORD *)(a3 + 3376) = *(_DWORD *)(v23 + 2532);
      v133 = v132 + *(_QWORD *)(v23 + 2568);
      LODWORD(v132) = *(_DWORD *)(a3 + 6128);
      *(_QWORD *)(a3 + 5208) = v133;
      LODWORD(v133) = v132 + *(_DWORD *)(v23 + 3000);
      LODWORD(v132) = *(_DWORD *)(a3 + 6132);
      *(_DWORD *)(a3 + 6128) = v133;
      LODWORD(v133) = v132 + *(_DWORD *)(v23 + 3004);
      v134 = *(_QWORD *)(a3 + 6968);
      *(_DWORD *)(a3 + 6132) = v133;
      v135 = v134 + *(_QWORD *)(v23 + 3856);
      v136 = *(_QWORD *)(a3 + 6976);
      *(_QWORD *)(a3 + 6968) = v135;
      v137 = v136 + *(_QWORD *)(v23 + 3864);
      LODWORD(v136) = *(_DWORD *)(a3 + 6468);
      *(_QWORD *)(a3 + 6976) = v137;
      LODWORD(v137) = v136 + *(_DWORD *)(v23 + 3008);
      LODWORD(v136) = *(_DWORD *)(a3 + 6472);
      *(_DWORD *)(a3 + 6468) = v137;
      LODWORD(v137) = v136 + *(_DWORD *)(v23 + 3012);
      LODWORD(v136) = *(_DWORD *)(a3 + 6548);
      *(_DWORD *)(a3 + 6472) = v137;
      LODWORD(v137) = v136 + *(_DWORD *)(v23 + 3016);
      LODWORD(v136) = *(_DWORD *)(a3 + 6552);
      *(_DWORD *)(a3 + 6548) = v137;
      LODWORD(v137) = v136 + *(_DWORD *)(v23 + 3020);
      LODWORD(v136) = *(_DWORD *)(a3 + 7000);
      *(_DWORD *)(a3 + 6552) = v137;
      *(_DWORD *)(a3 + 6492) = *(_DWORD *)(v23 + 3524);
      *(_DWORD *)(a3 + 6496) = *(_DWORD *)(v23 + 3528);
      *(_DWORD *)(a3 + 6500) = *(_DWORD *)(v23 + 3532);
      *(_DWORD *)(a3 + 6504) = *(_DWORD *)(v23 + 3536);
      *(_DWORD *)(a3 + 6564) = *(_DWORD *)(v23 + 3540);
      *(_DWORD *)(a3 + 6488) = *(_DWORD *)(v23 + 3544);
      *(_QWORD *)(a3 + 6576) = *(_QWORD *)(v23 + 3552);
      *(_DWORD *)(a3 + 7000) = v136 + *(_DWORD *)(v23 + 3848);
      *(_BYTE *)(a3 + 6584) = *(_BYTE *)(v23 + 3560);
      *(_BYTE *)(a3 + 6585) = *(_BYTE *)(v23 + 3561);
      v138 = v125 & 0xFFFFFFF0 | *(_DWORD *)(v23 + 3562) & 0xF;
      *(_DWORD *)(a3 + 6668) = v138;
      v139 = v138 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v23 + 3562) >> 4) & 0xF));
      *(_DWORD *)(a3 + 6668) = v139;
      v140 = v139 & 0xFFFFF0FF | (((*(_DWORD *)(v23 + 3562) >> 8) & 0xF) << 8);
      *(_DWORD *)(a3 + 6668) = v140;
      v141 = v140 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v23 + 3562)) >> 4 << 12);
      LODWORD(v136) = *(_DWORD *)(a3 + 6688);
      *(_DWORD *)(a3 + 6668) = v141;
      *(_DWORD *)(a3 + 6668) = v141 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v23 + 3562)) & 0xF) << 16);
      *(_DWORD *)(a3 + 6688) = v136 + *(_DWORD *)(v23 + 3568);
      *(_DWORD *)(a3 + 6920) = *(_DWORD *)(v23 + 3796);
      *(_DWORD *)(a3 + 6924) = *(_DWORD *)(v23 + 3800);
      do
      {
        v142 = (_DWORD *)(a3 + 5636 + v124);
        v143 = (_DWORD *)(v18 + v124);
        v124 += 68;
        v144 = v142[1];
        *v142 += *(v143 - 16);
        v142[1] = v144 + *(v143 - 15);
        v145 = v142[3];
        v142[2] += *(v143 - 14);
        v142[3] = v145 + *(v143 - 13);
        v146 = v142[5];
        v142[4] += *(v143 - 12);
        v142[5] = v146 + *(v143 - 11);
        v147 = v142[7];
        v142[6] += *(v143 - 10);
        v142[7] = v147 + *(v143 - 9);
        v148 = v142[9];
        v142[8] += *(v143 - 8);
        v142[9] = v148 + *(v143 - 7);
        v149 = v142[11];
        v142[10] += *(v143 - 6);
        v142[11] = v149 + *(v143 - 5);
        v150 = v142[13];
        v142[12] += *(v143 - 4);
        v142[13] = v150 + *(v143 - 3);
        v151 = v142[15];
        v152 = v142[16];
        v142[14] += *(v143 - 2);
        v142[15] = v151 + *(v143 - 1);
        v142[16] = v152 + *v143;
      }
      while ( v124 != 408 );
      v153 = 0;
      v154 = *(_QWORD *)(a3 + 6936);
      *(_DWORD *)(a3 + 5604) += *(_DWORD *)(v23 + 2984);
      v155 = v154 + *(_QWORD *)(v23 + 3808);
      LODWORD(v154) = *(_DWORD *)(a3 + 5608);
      *(_QWORD *)(a3 + 6936) = v155;
      LODWORD(v155) = v154 + *(_DWORD *)(v23 + 2988);
      v156 = *(_QWORD *)(a3 + 6944);
      *(_DWORD *)(a3 + 5608) = v155;
      v157 = v156 + *(_QWORD *)(v23 + 3816);
      LODWORD(v156) = *(_DWORD *)(a3 + 5612);
      *(_QWORD *)(a3 + 6944) = v157;
      LODWORD(v157) = v156 + *(_DWORD *)(v23 + 2992);
      v158 = *(_QWORD *)(a3 + 6952);
      *(_DWORD *)(a3 + 5612) = v157;
      v159 = v158 + *(_QWORD *)(v23 + 3824);
      LODWORD(v158) = *(_DWORD *)(a3 + 5616);
      *(_QWORD *)(a3 + 6952) = v159;
      LODWORD(v159) = v158 + *(_DWORD *)(v23 + 2996);
      v160 = *(_QWORD *)(a3 + 6960);
      *(_DWORD *)(a3 + 5616) = v159;
      *(_QWORD *)(a3 + 6960) = v160 + *(_QWORD *)(v23 + 3832);
      do
      {
        v161 = (_DWORD *)(v13 + v153);
        v162 = (_DWORD *)(a3 + 6136 + v153);
        v153 += 4;
        *v162 += *v161;
        v162[116] += v161[108];
      }
      while ( v153 != 68 );
      v163 = 0;
      v164 = 1;
      do
      {
        v165 = (_DWORD *)(a3 + 6220 + 108 * v163);
        v166 = (_DWORD *)(v23 + 3092 + 108 * v163);
        v167 = v165[9];
        v165[8] += v166[8];
        v165[9] = v167 + v166[9];
        v168 = v165[1];
        *v165 += *v166;
        v165[1] = v168 + v166[1];
        v169 = v165[3];
        v165[2] += v166[2];
        v165[3] = v169 + v166[3];
        v170 = v165[5];
        v165[4] += v166[4];
        v165[5] = v170 + v166[5];
        v171 = v165[7];
        v165[6] += v166[6];
        v165[7] = v171 + v166[7];
        v172 = v165[11];
        v165[10] += v166[10];
        v165[11] = v172 + v166[11];
        v173 = v165[13];
        v165[12] += v166[12];
        v165[13] = v173 + v166[13];
        v174 = v165[15];
        v165[14] += v166[14];
        v165[15] = v174 + v166[15];
        v175 = v165[17];
        v165[16] += v166[16];
        v165[17] = v175 + v166[17];
        v176 = v165[19];
        v165[18] += v166[18];
        v165[19] = v176 + v166[19];
        v177 = v165[21];
        v165[20] += v166[20];
        v165[21] = v177 + v166[21];
        v178 = v165[23];
        v165[22] += v166[22];
        v165[23] = v178 + v166[23];
        v179 = v165[25];
        v180 = v165[26];
        v165[24] += v166[24];
        v181 = v179 + v166[25];
        LOBYTE(v179) = v164;
        v164 = 0;
        v165[25] = v181;
        v182 = v166[26];
        v163 = 1;
        v165[26] = v180 + v182;
      }
      while ( (v179 & 1) != 0 );
      v183 = 0;
      v184 = *(_DWORD *)(a3 + 6204);
      *(_DWORD *)(a3 + 5620) += *(_DWORD *)(v23 + 3308);
      v185 = v184 + *(_DWORD *)(v23 + 3324);
      v186 = *(_DWORD *)(a3 + 5624);
      *(_DWORD *)(a3 + 6204) = v185;
      v187 = v186 + *(_DWORD *)(v23 + 3312);
      v188 = *(_DWORD *)(a3 + 6208);
      *(_DWORD *)(a3 + 5624) = v187;
      v189 = v188 + *(_DWORD *)(v23 + 3328);
      v190 = *(_DWORD *)(a3 + 5628);
      *(_DWORD *)(a3 + 6208) = v189;
      v191 = v190 + *(_DWORD *)(v23 + 3316);
      v192 = *(_DWORD *)(a3 + 6212);
      *(_DWORD *)(a3 + 5628) = v191;
      v193 = v192 + *(_DWORD *)(v23 + 3332);
      v194 = *(_DWORD *)(a3 + 5632);
      *(_DWORD *)(a3 + 6212) = v193;
      v195 = v194 + *(_DWORD *)(v23 + 3320);
      v196 = *(_DWORD *)(a3 + 6216);
      *(_DWORD *)(a3 + 5632) = v195;
      v197 = v196 + *(_DWORD *)(v23 + 3336);
      v198 = *(_DWORD *)(a3 + 6044);
      *(_DWORD *)(a3 + 6216) = v197;
      v199 = v198 + *(_DWORD *)(v23 + 3340);
      v200 = *(_DWORD *)(a3 + 6048);
      *(_DWORD *)(a3 + 6044) = v199;
      v201 = v200 + *(_DWORD *)(v23 + 3344);
      v202 = *(_DWORD *)(a3 + 6052);
      *(_DWORD *)(a3 + 6048) = v201;
      v203 = v202 + *(_DWORD *)(v23 + 3348);
      v204 = *(_DWORD *)(a3 + 6056);
      *(_DWORD *)(a3 + 6052) = v203;
      v205 = v204 + *(_DWORD *)(v23 + 3352);
      v206 = *(_DWORD *)(a3 + 6060);
      *(_DWORD *)(a3 + 6056) = v205;
      v207 = v206 + *(_DWORD *)(v23 + 3356);
      v208 = *(_DWORD *)(a3 + 6064);
      *(_DWORD *)(a3 + 6060) = v207;
      v209 = v208 + *(_DWORD *)(v23 + 3360);
      v210 = *(_DWORD *)(a3 + 6096);
      *(_DWORD *)(a3 + 6064) = v209;
      v211 = v210 + *(_DWORD *)(v23 + 3392);
      v212 = *(_DWORD *)(a3 + 6068);
      *(_DWORD *)(a3 + 6096) = v211;
      v213 = v212 + *(_DWORD *)(v23 + 3364);
      v214 = *(_DWORD *)(a3 + 6100);
      *(_DWORD *)(a3 + 6068) = v213;
      v215 = v214 + *(_DWORD *)(v23 + 3396);
      v216 = *(_DWORD *)(a3 + 6072);
      *(_DWORD *)(a3 + 6100) = v215;
      v217 = v216 + *(_DWORD *)(v23 + 3368);
      v218 = *(_DWORD *)(a3 + 6104);
      *(_DWORD *)(a3 + 6072) = v217;
      v219 = v218 + *(_DWORD *)(v23 + 3400);
      v220 = *(_DWORD *)(a3 + 6076);
      *(_DWORD *)(a3 + 6104) = v219;
      v221 = v220 + *(_DWORD *)(v23 + 3372);
      v222 = *(_DWORD *)(a3 + 6108);
      *(_DWORD *)(a3 + 6076) = v221;
      v223 = v222 + *(_DWORD *)(v23 + 3404);
      v224 = *(_DWORD *)(a3 + 6080);
      *(_DWORD *)(a3 + 6108) = v223;
      v225 = v224 + *(_DWORD *)(v23 + 3376);
      v226 = *(_DWORD *)(a3 + 6112);
      *(_DWORD *)(a3 + 6080) = v225;
      v227 = v226 + *(_DWORD *)(v23 + 3408);
      v228 = *(_DWORD *)(a3 + 6084);
      *(_DWORD *)(a3 + 6112) = v227;
      v229 = v228 + *(_DWORD *)(v23 + 3380);
      v230 = *(_DWORD *)(a3 + 6116);
      *(_DWORD *)(a3 + 6084) = v229;
      v231 = v230 + *(_DWORD *)(v23 + 3412);
      v232 = *(_DWORD *)(a3 + 6088);
      *(_DWORD *)(a3 + 6116) = v231;
      v233 = v232 + *(_DWORD *)(v23 + 3384);
      v234 = *(_DWORD *)(a3 + 6120);
      *(_DWORD *)(a3 + 6088) = v233;
      v235 = v234 + *(_DWORD *)(v23 + 3416);
      v236 = *(_DWORD *)(a3 + 6092);
      *(_DWORD *)(a3 + 6120) = v235;
      v237 = v236 + *(_DWORD *)(v23 + 3388);
      v238 = *(_DWORD *)(a3 + 6124);
      *(_DWORD *)(a3 + 6092) = v237;
      v239 = v238 + *(_DWORD *)(v23 + 3420);
      v240 = *(_DWORD *)(a3 + 6436);
      *(_DWORD *)(a3 + 6124) = v239;
      v241 = v240 + *(_DWORD *)(v23 + 3424);
      v242 = *(_DWORD *)(a3 + 6440);
      *(_DWORD *)(a3 + 6436) = v241;
      v243 = v242 + *(_DWORD *)(v23 + 3428);
      v244 = *(_DWORD *)(a3 + 6444);
      *(_DWORD *)(a3 + 6440) = v243;
      v245 = v244 + *(_DWORD *)(v23 + 3432);
      v246 = *(_DWORD *)(a3 + 6448);
      *(_DWORD *)(a3 + 6444) = v245;
      v247 = v246 + *(_DWORD *)(v23 + 3436);
      v248 = *(_DWORD *)(a3 + 6452);
      *(_DWORD *)(a3 + 6448) = v247;
      v249 = v248 + *(_DWORD *)(v23 + 3440);
      v250 = *(_DWORD *)(a3 + 6456);
      *(_DWORD *)(a3 + 6452) = v249;
      v251 = v250 + *(_DWORD *)(v23 + 3444);
      v252 = *(_DWORD *)(a3 + 6460);
      *(_DWORD *)(a3 + 6456) = v251;
      v253 = v252 + *(_DWORD *)(v23 + 3448);
      v254 = *(_DWORD *)(a3 + 6464);
      *(_DWORD *)(a3 + 6460) = v253;
      v255 = v254 + *(_DWORD *)(v23 + 3452);
      v256 = *(_QWORD *)(a3 + 6992);
      *(_DWORD *)(a3 + 6464) = v255;
      *(_QWORD *)(a3 + 6992) = v256 + *(_QWORD *)(v23 + 3840);
      do
      {
        v257 = (_DWORD *)(v19 + v183);
        v258 = (_DWORD *)(a3 + 4312 + v183);
        v183 += 4;
        *v258 += *v257;
        v258[595] += v257[327];
      }
      while ( v183 != 68 );
      for ( i = 0; i != 68; i += 4 )
      {
        v260 = (_DWORD *)(v20 + i);
        v261 = (_DWORD *)(a3 + 4380 + i);
        *v261 += *v260;
        v261[595] += v260[327];
      }
      for ( j = 0; j != 68; j += 4 )
      {
        v263 = (_DWORD *)(v21 + j);
        v264 = (_DWORD *)(a3 + 4448 + j);
        *v264 += *v263;
        v264[595] += v263[327];
      }
      v265 = 0;
      v266 = *(_DWORD *)(a3 + 6896);
      *(_DWORD *)(a3 + 4516) += *(_DWORD *)(v23 + 2468);
      v267 = v266 + *(_DWORD *)(v23 + 3776);
      v268 = *(_DWORD *)(a3 + 4520);
      *(_DWORD *)(a3 + 6896) = v267;
      v269 = v268 + *(_DWORD *)(v23 + 2472);
      v270 = *(_DWORD *)(a3 + 6900);
      *(_DWORD *)(a3 + 4520) = v269;
      v271 = v270 + *(_DWORD *)(v23 + 3780);
      v272 = *(_DWORD *)(a3 + 4524);
      *(_DWORD *)(a3 + 6900) = v271;
      v273 = v272 + *(_DWORD *)(v23 + 2476);
      v274 = *(_DWORD *)(a3 + 6904);
      *(_DWORD *)(a3 + 4524) = v273;
      v275 = v274 + *(_DWORD *)(v23 + 3784);
      v276 = *(_DWORD *)(a3 + 4528);
      *(_DWORD *)(a3 + 6904) = v275;
      v277 = v276 + *(_DWORD *)(v23 + 2480);
      v278 = *(_DWORD *)(a3 + 6908);
      *(_DWORD *)(a3 + 4528) = v277;
      v279 = v278 + *(_DWORD *)(v23 + 3788);
      v280 = *(_DWORD *)(a3 + 4532);
      *(_DWORD *)(a3 + 6908) = v279;
      v281 = v280 + *(_DWORD *)(v23 + 2484);
      v282 = *(_DWORD *)(a3 + 6912);
      *(_DWORD *)(a3 + 4532) = v281;
      v283 = v282 + *(_DWORD *)(v23 + 3792);
      v284 = *(_QWORD *)(a3 + 2488);
      *(_DWORD *)(a3 + 6912) = v283;
      v285 = v284 + *(_QWORD *)v23;
      v286 = *(_QWORD *)(a3 + 2496);
      *(_QWORD *)(a3 + 2488) = v285;
      v287 = v286 + *(_QWORD *)(v23 + 8);
      v288 = *(_QWORD *)(a3 + 2504);
      *(_QWORD *)(a3 + 2496) = v287;
      v289 = v288 + *(_QWORD *)(v23 + 16);
      v290 = *(_QWORD *)(a3 + 2512);
      *(_QWORD *)(a3 + 2504) = v289;
      v291 = v290 + *(_QWORD *)(v23 + 24);
      v292 = *(_QWORD *)(a3 + 2520);
      *(_QWORD *)(a3 + 2512) = v291;
      v293 = v292 + *(_QWORD *)(v23 + 32);
      v294 = *(_QWORD *)(a3 + 2528);
      *(_QWORD *)(a3 + 2520) = v293;
      v295 = v294 + *(_QWORD *)(v23 + 40);
      v296 = *(_QWORD *)(a3 + 2536);
      *(_QWORD *)(a3 + 2528) = v295;
      v297 = v296 + *(_QWORD *)(v23 + 48);
      v298 = *(_QWORD *)(a3 + 2544);
      *(_QWORD *)(a3 + 2536) = v297;
      v299 = v298 + *(_QWORD *)(v23 + 56);
      v300 = *(_QWORD *)(a3 + 2552);
      *(_QWORD *)(a3 + 2544) = v299;
      v301 = v300 + *(_QWORD *)(v23 + 64);
      v302 = *(_QWORD *)(a3 + 2560);
      *(_QWORD *)(a3 + 2552) = v301;
      v303 = v302 + *(_QWORD *)(v23 + 72);
      LODWORD(v302) = *(_DWORD *)(a3 + 2568);
      *(_QWORD *)(a3 + 2560) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 80);
      LODWORD(v302) = *(_DWORD *)(a3 + 2576);
      *(_DWORD *)(a3 + 2568) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 84);
      LODWORD(v302) = *(_DWORD *)(a3 + 2596);
      *(_DWORD *)(a3 + 2576) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 88);
      LODWORD(v302) = *(_DWORD *)(a3 + 2600);
      *(_DWORD *)(a3 + 2596) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 92);
      LODWORD(v302) = *(_DWORD *)(a3 + 3420);
      *(_DWORD *)(a3 + 2600) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 176);
      LODWORD(v302) = *(_DWORD *)(a3 + 3424);
      *(_DWORD *)(a3 + 3420) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 180);
      LODWORD(v302) = *(_DWORD *)(a3 + 3428);
      *(_DWORD *)(a3 + 3424) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 184);
      LODWORD(v302) = *(_DWORD *)(a3 + 4560);
      *(_DWORD *)(a3 + 3428) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 548);
      LODWORD(v302) = *(_DWORD *)(a3 + 3432);
      *(_DWORD *)(a3 + 4560) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 188);
      LODWORD(v302) = *(_DWORD *)(a3 + 3436);
      *(_DWORD *)(a3 + 3432) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 192);
      LODWORD(v302) = *(_DWORD *)(a3 + 3440);
      *(_DWORD *)(a3 + 3436) = v303;
      LODWORD(v303) = v302 + *(_DWORD *)(v23 + 196);
      v304 = *(_QWORD *)(a3 + 4280);
      *(_DWORD *)(a3 + 3440) = v303;
      v305 = v304 + *(_QWORD *)(v23 + 456);
      v306 = *(_QWORD *)(a3 + 4288);
      *(_QWORD *)(a3 + 4280) = v305;
      v307 = v306 + *(_QWORD *)(v23 + 464);
      LODWORD(v306) = *(_DWORD *)(a3 + 4536);
      *(_QWORD *)(a3 + 4288) = v307;
      *(_QWORD *)(a3 + 4304) = *(_QWORD *)(v23 + 472);
      *(_DWORD *)(a3 + 4536) = v306 + *(_DWORD *)(v23 + 544);
      do
      {
        *(_DWORD *)(a3 + 4028 + v265) += *(_DWORD *)(v22 + v265);
        v265 += 4;
      }
      while ( v265 != 252 );
      v15 += 4072;
      v16 += 4072;
      v17 += 4072;
      v18 += 4072;
      v13 += 4072;
      v19 += 4072;
      *(_DWORD *)(a3 + 4636) += *(_DWORD *)(v23 + 552);
      v20 += 4072;
      v21 += 4072;
      v22 += 4072;
      *(_DWORD *)(a3 + 4640) += *(_DWORD *)(v23 + 556);
      *(_DWORD *)(a3 + 4644) += *(_DWORD *)(v23 + 560);
      *(_DWORD *)(a3 + 4648) += *(_DWORD *)(v23 + 564);
      *(_DWORD *)(a3 + 4652) += *(_DWORD *)(v23 + 568);
      *(_DWORD *)(a3 + 4656) += *(_DWORD *)(v23 + 572);
      *(_DWORD *)(a3 + 4660) += *(_DWORD *)(v23 + 576);
      *(_DWORD *)(a3 + 4664) += *(_DWORD *)(v23 + 580);
      *(_DWORD *)(a3 + 4668) += *(_DWORD *)(v23 + 584);
      *(_DWORD *)(a3 + 4672) += *(_DWORD *)(v23 + 588);
      *(_DWORD *)(a3 + 4676) += *(_DWORD *)(v23 + 592);
      *(_DWORD *)(a3 + 4680) += *(_DWORD *)(v23 + 596);
      *(_DWORD *)(a3 + 4684) += *(_DWORD *)(v23 + 600);
      *(_DWORD *)(a3 + 4688) += *(_DWORD *)(v23 + 604);
      *(_QWORD *)(a3 + 5424) += *(_QWORD *)(v23 + 784);
      *(_QWORD *)(a3 + 5432) += *(_QWORD *)(v23 + 792);
      *(_QWORD *)(a3 + 5512) += *(_QWORD *)(v23 + 992);
      *(_QWORD *)(a3 + 5520) += *(_QWORD *)(v23 + 1000);
      *(_QWORD *)(a3 + 5440) += *(_QWORD *)(v23 + 800);
      *(_QWORD *)(a3 + 5448) += *(_QWORD *)(v23 + 808);
      *(_QWORD *)(a3 + 5408) += *(_QWORD *)(v23 + 768);
      *(_QWORD *)(a3 + 5416) += *(_QWORD *)(v23 + 776);
      *(_QWORD *)(a3 + 5456) += *(_QWORD *)(v23 + 816);
      *(_QWORD *)(a3 + 5464) += *(_QWORD *)(v23 + 824);
      *(_DWORD *)(a3 + 5472) += *(_DWORD *)(v23 + 832);
      *(_DWORD *)(a3 + 6916) += *(_DWORD *)(v23 + 1008);
      *(_QWORD *)(a3 + 5480) += *(_QWORD *)(v23 + 840);
      *(_QWORD *)(a3 + 5488) += *(_QWORD *)(v23 + 848);
      *(_QWORD *)(a3 + 5496) += *(_QWORD *)(v23 + 856);
      *(_QWORD *)(a3 + 5504) += *(_QWORD *)(v23 + 864);
      *(_QWORD *)(a3 + 5536) += *(_QWORD *)(v23 + 880);
      *(_QWORD *)(a3 + 5544) += *(_QWORD *)(v23 + 888);
      *(_QWORD *)(a3 + 5552) += *(_QWORD *)(v23 + 896);
      *(_QWORD *)(a3 + 5560) += *(_QWORD *)(v23 + 904);
      *(_DWORD *)(a3 + 5568) += *(_DWORD *)(v23 + 912);
      *(_DWORD *)(a3 + 5576) += *(_DWORD *)(v23 + 920);
      *(_DWORD *)(a3 + 5580) += *(_DWORD *)(v23 + 924);
      *(_DWORD *)(a3 + 5584) += *(_DWORD *)(v23 + 928);
      *(_DWORD *)(a3 + 5588) += *(_DWORD *)(v23 + 932);
      *(_DWORD *)(a3 + 5592) += *(_DWORD *)(v23 + 936);
      *(_DWORD *)(a3 + 5596) += *(_DWORD *)(v23 + 940);
      *(_DWORD *)(a3 + 5600) += *(_DWORD *)(v23 + 944);
      *(_DWORD *)(a3 + 6476) += *(_DWORD *)(v23 + 948);
      *(_DWORD *)(a3 + 6480) += *(_DWORD *)(v23 + 952);
      *(_DWORD *)(a3 + 6544) += *(_DWORD *)(v23 + 956);
      *(_DWORD *)(a3 + 6588) += *(_DWORD *)(v23 + 960);
      *(_DWORD *)(a3 + 6592) += *(_DWORD *)(v23 + 964);
      *(_DWORD *)(a3 + 6596) += *(_DWORD *)(v23 + 968);
      *(_QWORD *)(a3 + 6672) += *(_QWORD *)(v23 + 976);
      *(_QWORD *)(a3 + 6680) += *(_QWORD *)(v23 + 984);
      *(_QWORD *)(a3 + 5528) = *(_QWORD *)(v23 + 872);
      *(_DWORD *)(a3 + 6928) += *(_DWORD *)(v23 + 1032);
      *(_QWORD *)(a3 + 5232) += *(_QWORD *)(v23 + 608);
      *(_QWORD *)(a3 + 5240) += *(_QWORD *)(v23 + 616);
      v308 = *(_QWORD *)(a3 + 5360) + *(_QWORD *)(v23 + 608);
      v309 = *(_QWORD *)(a3 + 5368);
      *(_QWORD *)(a3 + 5360) = v308;
      v310 = v309 + *(_QWORD *)(v23 + 616);
      v311 = *(_QWORD *)(a3 + 5248);
      *(_QWORD *)(a3 + 5368) = v310;
      *(_QWORD *)(a3 + 5248) = v311 + *(_QWORD *)(v23 + 624);
      *(_QWORD *)(a3 + 5256) += *(_QWORD *)(v23 + 632);
      v312 = v308 + *(_QWORD *)(v23 + 624);
      *(_QWORD *)(a3 + 5360) = v312;
      v313 = v310 + *(_QWORD *)(v23 + 632);
      v314 = *(_QWORD *)(a3 + 5264);
      *(_QWORD *)(a3 + 5368) = v313;
      *(_QWORD *)(a3 + 5264) = v314 + *(_QWORD *)(v23 + 640);
      *(_QWORD *)(a3 + 5272) += *(_QWORD *)(v23 + 648);
      v315 = v312 + *(_QWORD *)(v23 + 640);
      *(_QWORD *)(a3 + 5360) = v315;
      v316 = v313 + *(_QWORD *)(v23 + 648);
      v317 = *(_QWORD *)(a3 + 5280);
      *(_QWORD *)(a3 + 5368) = v316;
      *(_QWORD *)(a3 + 5280) = v317 + *(_QWORD *)(v23 + 656);
      *(_QWORD *)(a3 + 5288) += *(_QWORD *)(v23 + 664);
      v318 = v315 + *(_QWORD *)(v23 + 656);
      *(_QWORD *)(a3 + 5360) = v318;
      v319 = v316 + *(_QWORD *)(v23 + 664);
      v320 = *(_QWORD *)(a3 + 5296);
      *(_QWORD *)(a3 + 5368) = v319;
      *(_QWORD *)(a3 + 5296) = v320 + *(_QWORD *)(v23 + 672);
      *(_QWORD *)(a3 + 5304) += *(_QWORD *)(v23 + 680);
      v321 = v318 + *(_QWORD *)(v23 + 672);
      *(_QWORD *)(a3 + 5360) = v321;
      v322 = v319 + *(_QWORD *)(v23 + 680);
      v323 = *(_QWORD *)(a3 + 5312);
      *(_QWORD *)(a3 + 5368) = v322;
      *(_QWORD *)(a3 + 5312) = v323 + *(_QWORD *)(v23 + 688);
      *(_QWORD *)(a3 + 5320) += *(_QWORD *)(v23 + 696);
      v324 = v321 + *(_QWORD *)(v23 + 688);
      *(_QWORD *)(a3 + 5360) = v324;
      v325 = v322 + *(_QWORD *)(v23 + 696);
      v326 = *(_QWORD *)(a3 + 5328);
      *(_QWORD *)(a3 + 5368) = v325;
      *(_QWORD *)(a3 + 5328) = v326 + *(_QWORD *)(v23 + 704);
      *(_QWORD *)(a3 + 5336) += *(_QWORD *)(v23 + 712);
      v327 = v324 + *(_QWORD *)(v23 + 704);
      *(_QWORD *)(a3 + 5360) = v327;
      v328 = v325 + *(_QWORD *)(v23 + 712);
      v329 = *(_QWORD *)(a3 + 5344);
      *(_QWORD *)(a3 + 5368) = v328;
      *(_QWORD *)(a3 + 5344) = v329 + *(_QWORD *)(v23 + 720);
      *(_QWORD *)(a3 + 5352) += *(_QWORD *)(v23 + 728);
      *(_QWORD *)(a3 + 5360) = v327 + *(_QWORD *)(v23 + 720);
      v14 = v335 + 1;
      *(_QWORD *)(a3 + 5368) = v328 + *(_QWORD *)(v23 + 728);
      *(_QWORD *)(a3 + 5376) += *(_QWORD *)(v23 + 736);
      *(_QWORD *)(a3 + 5384) += *(_QWORD *)(v23 + 744);
      *(_QWORD *)(a3 + 5392) += *(_QWORD *)(v23 + 752);
      *(_QWORD *)(a3 + 5400) += *(_QWORD *)(v23 + 760);
      *(_QWORD *)(a3 + 6968) += *(_QWORD *)(v23 + 1016);
      *(_QWORD *)(a3 + 6976) += *(_QWORD *)(v23 + 1024);
      *(_QWORD *)(a3 + 3224) += *(unsigned int *)(v23 + 100);
      *(_QWORD *)(a3 + 3232) += *(_QWORD *)(v23 + 160);
      *(_DWORD *)(a3 + 3240) += *(_DWORD *)(v23 + 108);
      *(_QWORD *)(a3 + 3248) += *(unsigned int *)(v23 + 104);
      *(_QWORD *)(a3 + 3256) += *(_QWORD *)(v23 + 168);
      *(_DWORD *)(a3 + 3264) += *(_DWORD *)(v23 + 112);
      *(_DWORD *)(a3 + 3268) += *(_DWORD *)(v23 + 116);
      *(_DWORD *)(a3 + 3272) += *(_DWORD *)(v23 + 120);
      *(_DWORD *)(a3 + 3276) += *(_DWORD *)(v23 + 124);
      *(_DWORD *)(a3 + 3280) += *(_DWORD *)(v23 + 128);
      *(_DWORD *)(a3 + 3284) += *(_DWORD *)(v23 + 132);
      *(_DWORD *)(a3 + 3288) += *(_DWORD *)(v23 + 136);
      *(_DWORD *)(a3 + 3292) += *(_DWORD *)(v23 + 140);
      *(_DWORD *)(a3 + 3296) += *(_DWORD *)(v23 + 144);
      *(_DWORD *)(a3 + 3300) += *(_DWORD *)(v23 + 148);
      *(_DWORD *)(a3 + 3304) += *(_DWORD *)(v23 + 156);
    }
    while ( v335 + 1 != v334 );
  }
LABEL_35:
  v3 = v332;
  if ( *((_DWORD *)v332 + 102) != 1 || (v330 = (__int64 *)v332[52]) == nullptr )
LABEL_37:
    v330 = v3;
  return raw_spin_unlock(v330 + 19);
}
