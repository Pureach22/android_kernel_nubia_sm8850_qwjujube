__int64 *__fastcall dp_get_peer_stats(
        __int64 *result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x12
  __int64 v12; // x9
  __int64 v13; // x10
  __int64 v14; // x11
  __int64 v15; // x12
  __int64 v16; // x10
  __int64 v17; // x11
  __int64 v18; // x12
  __int64 v19; // x10
  __int64 v20; // x11
  __int64 v21; // x12
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x12
  __int64 v25; // x10
  __int64 v26; // x11
  __int64 v27; // x10
  __int64 v28; // x11
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x12
  int v32; // w10
  int v33; // w9
  int v34; // w10
  int v35; // w9
  int v36; // w10
  int v37; // w9
  int v38; // w10
  int v39; // w9
  int v40; // w10
  int v41; // w9
  int v42; // w10
  int v43; // w9
  int v44; // w10
  int v45; // w9
  int v46; // w10
  int v47; // w9
  int v48; // w10
  int v49; // w9
  int v50; // w10
  int v51; // w9
  int v52; // w10
  int v53; // w9
  int v54; // w10
  int v55; // w9
  int v56; // w10
  int v57; // w9
  __int64 v58; // x10
  __int64 v59; // x9
  __int64 v60; // x10
  __int64 v61; // x9
  __int64 v62; // x10
  __int64 v63; // x9
  __int64 v64; // x10
  __int64 v65; // x9
  __int64 v66; // x10
  __int64 v67; // x9
  __int64 v68; // x10
  __int64 v69; // x9
  __int64 v70; // x10
  __int64 v71; // x9
  __int64 v72; // x10
  __int64 v73; // x9
  __int64 v74; // x10
  __int64 v75; // x9
  __int64 v76; // x10
  __int64 v77; // x9
  __int64 v78; // x10
  __int64 v79; // x9
  __int64 v80; // x10
  __int64 v81; // x9
  __int64 v82; // x10
  __int64 v83; // x9
  __int64 v84; // x10
  __int64 v85; // x9
  __int64 v86; // x10
  __int64 v87; // x9
  __int64 v88; // x10
  __int64 v89; // x9
  __int64 v90; // x10
  __int64 v91; // x9
  __int64 v92; // x10
  __int64 v93; // x9
  __int64 v94; // x10
  __int64 v95; // x9
  __int64 v96; // x10
  __int64 v97; // x9
  __int64 v98; // x10
  __int64 v99; // x9
  __int64 v100; // x10
  __int64 v101; // x9
  __int64 v102; // x10
  __int64 v103; // x9
  __int64 v104; // x10
  __int64 v105; // x11
  __int64 v106; // x12
  __int64 v107; // x11
  __int64 v108; // x12
  __int64 v109; // x9
  __int64 v110; // x10
  __int64 v111; // x11
  __int64 v112; // x12
  __int64 v113; // x11
  __int64 v114; // x12
  __int64 v115; // x9
  __int64 v116; // x10
  __int64 v117; // x11
  __int64 v118; // x12
  __int64 v119; // x11
  __int64 v120; // x12
  __int64 v121; // x9
  __int64 v122; // x10
  __int64 v123; // x11
  __int64 v124; // x12
  __int64 v125; // x11
  __int64 v126; // x12
  __int64 v127; // x9
  __int64 v128; // x10
  __int64 v129; // x11
  __int64 v130; // x12
  __int64 v131; // x11
  __int64 v132; // x12
  __int64 v133; // x9
  __int64 v134; // x10
  __int64 v135; // x11
  __int64 v136; // x12
  __int64 v137; // x11
  __int64 v138; // x12
  __int64 v139; // x9
  __int64 v140; // x10
  __int64 v141; // x11
  __int64 v142; // x12
  __int64 v143; // x9
  __int64 v144; // x10
  __int64 v145; // x9
  __int64 v146; // x10
  __int64 v147; // x9
  __int64 v148; // x10
  __int64 v149; // x9
  __int64 v150; // x10
  __int64 v151; // x9
  __int64 v152; // x10
  __int64 v153; // x9
  __int64 v154; // x10
  __int64 v155; // x9
  __int64 v156; // x10
  __int64 v157; // x9
  __int64 v158; // x10
  __int64 v159; // x9
  __int64 v160; // x10
  __int64 v161; // x9
  __int64 v162; // x10
  __int64 v163; // x9
  __int64 v164; // x8
  int v165; // w12
  __int64 v166; // x10
  int v167; // w12
  int v168; // w11
  int v169; // w9
  int v170; // w11
  int v171; // w9
  int v172; // w11
  int v173; // w9
  int v174; // w11
  int v175; // w9
  int v176; // w11
  int v177; // w9
  int v178; // w11
  int v179; // w9
  int v180; // w11
  int v181; // w9
  int v182; // w11
  unsigned int v183; // w11
  unsigned int v184; // w11
  unsigned int v185; // w11
  unsigned int v186; // w11
  int v187; // w11
  _DWORD *v188; // x13
  _DWORD *v189; // x14
  int v190; // w17
  int v191; // w17
  int v192; // w17
  int v193; // w17
  int v194; // w17
  int v195; // w17
  int v196; // w17
  __int64 v197; // x10
  __int64 v198; // x12
  __int64 v199; // x11
  __int64 v200; // x12
  __int64 v201; // x11
  __int64 v202; // x12
  __int64 v203; // x11
  __int64 v204; // x12
  __int64 v205; // x11
  __int64 v206; // x10
  __int64 v207; // x12
  __int64 v208; // x11
  __int64 v209; // x12
  __int64 v210; // x11
  __int64 v211; // x12
  __int64 v212; // x11
  __int64 v213; // x12
  __int64 v214; // x11
  __int64 v215; // x12
  __int64 v216; // x11
  __int64 v217; // x12
  __int64 v218; // x11
  _DWORD *v219; // x12
  _DWORD *v220; // x13
  int v221; // w16
  int v222; // w16
  int v223; // w16
  int v224; // w16
  int v225; // w16
  int v226; // w16
  int v227; // w16
  __int64 v228; // x9
  char v229; // w13
  __int64 v230; // x9
  _DWORD *v231; // x14
  _DWORD *v232; // x9
  int v233; // w17
  int v234; // w17
  int v235; // w17
  int v236; // w17
  int v237; // w17
  int v238; // w17
  int v239; // w17
  int v240; // w17
  int v241; // w17
  int v242; // w17
  int v243; // w17
  int v244; // w17
  char v245; // w16
  int v246; // w10
  int v247; // w9
  int v248; // w10
  int v249; // w9
  int v250; // w10
  int v251; // w9
  int v252; // w10
  int v253; // w9
  int v254; // w10
  int v255; // w9
  int v256; // w10
  int v257; // w9
  int v258; // w10
  int v259; // w9
  int v260; // w10
  int v261; // w9
  int v262; // w10
  int v263; // w9
  int v264; // w10
  int v265; // w9
  int v266; // w10
  int v267; // w9
  int v268; // w10
  int v269; // w9
  int v270; // w10
  int v271; // w9
  int v272; // w10
  int v273; // w9
  int v274; // w10
  int v275; // w9
  int v276; // w10
  int v277; // w9
  int v278; // w10
  int v279; // w9
  int v280; // w10
  int v281; // w9
  int v282; // w10
  int v283; // w9
  int v284; // w10
  int v285; // w9
  int v286; // w10
  int v287; // w9
  int v288; // w10
  int v289; // w9
  int v290; // w10
  int v291; // w9
  int v292; // w10
  int v293; // w9
  int v294; // w10
  int v295; // w9
  int v296; // w10
  int v297; // w9
  int v298; // w10
  int v299; // w9
  int v300; // w10
  int v301; // w9
  int v302; // w10
  int v303; // w9
  int v304; // w10
  int v305; // w9
  int v306; // w10
  int v307; // w9
  int v308; // w10
  int v309; // w9
  int v310; // w10
  int v311; // w9
  int v312; // w10
  int v313; // w9
  int v314; // w10
  int v315; // w9
  int v316; // w10
  __int64 v317; // x20
  __int64 *v318; // x21
  __int64 v319; // x22
  __int64 v320; // x8
  __int64 v321; // x9
  unsigned int v322; // w8
  __int64 v323; // x8
  __int64 v324; // x11
  int v325; // w10
  int v326; // w9
  __int64 v327; // x10

  if ( result )
  {
    *(_DWORD *)(a2 + 160) = *((_DWORD *)result + 40);
    *(_DWORD *)(a2 + 192) = *((_DWORD *)result + 41);
    *(_DWORD *)(a2 + 196) = *((_DWORD *)result + 42);
    *(_DWORD *)(a2 + 200) = *((_DWORD *)result + 43);
    *(_DWORD *)(a2 + 204) = *((_DWORD *)result + 44);
    *(_DWORD *)(a2 + 208) = *((_DWORD *)result + 45);
    *(_DWORD *)(a2 + 212) = *((_DWORD *)result + 46);
    *(_DWORD *)(a2 + 812) = *((_DWORD *)result + 47);
    *(_DWORD *)(a2 + 3480) = *((_DWORD *)result + 48);
    *(_DWORD *)(a2 + 3484) = *((_DWORD *)result + 49);
    *(_DWORD *)(a2 + 3488) = *((_DWORD *)result + 50);
    *(_DWORD *)(a2 + 3492) = *((_DWORD *)result + 51);
  }
  v10 = *result;
  if ( !*result )
    goto LABEL_16;
  v11 = *(_QWORD *)(a2 + 32);
  v12 = 0;
  *(_QWORD *)(a2 + 24) += *(_QWORD *)(v10 + 2224);
  v13 = v11 + *(_QWORD *)(v10 + 2232);
  v14 = *(_QWORD *)(a2 + 40);
  v15 = *(_QWORD *)(a2 + 48);
  *(_QWORD *)(a2 + 32) = v13;
  *(_QWORD *)(a2 + 40) = v14 + *(_QWORD *)(v10 + 2240);
  v16 = v15 + *(_QWORD *)(v10 + 2248);
  v17 = *(_QWORD *)(a2 + 56);
  v18 = *(_QWORD *)(a2 + 64);
  *(_QWORD *)(a2 + 48) = v16;
  *(_QWORD *)(a2 + 56) = v17 + *(_QWORD *)(v10 + 2256);
  v19 = v18 + *(_QWORD *)(v10 + 2264);
  v20 = *(_QWORD *)(a2 + 72);
  v21 = *(_QWORD *)(a2 + 80);
  *(_QWORD *)(a2 + 64) = v19;
  *(_QWORD *)(a2 + 72) = v20 + *(_QWORD *)(v10 + 2272);
  v22 = v21 + *(_QWORD *)(v10 + 2280);
  v23 = *(_QWORD *)(a2 + 88);
  v24 = *(_QWORD *)(a2 + 96);
  *(_QWORD *)(a2 + 80) = v22;
  v25 = v23 + *(_QWORD *)(v10 + 2288);
  LODWORD(v23) = *(_DWORD *)(a2 + 104);
  *(_QWORD *)(a2 + 88) = v25;
  *(_QWORD *)(a2 + 96) = v24 + *(_QWORD *)(v10 + 2296);
  LODWORD(v25) = v23 + *(_DWORD *)(v10 + 2304);
  LODWORD(v23) = *(_DWORD *)(a2 + 112);
  *(_DWORD *)(a2 + 104) = v25;
  *(_DWORD *)(a2 + 112) = v23 + *(_DWORD *)(v10 + 2308);
  LODWORD(v24) = *(_DWORD *)(a2 + 136);
  LODWORD(v23) = *(_DWORD *)(a2 + 852);
  *(_DWORD *)(a2 + 132) += *(_DWORD *)(v10 + 2312);
  *(_DWORD *)(a2 + 136) = v24 + *(_DWORD *)(v10 + 2316);
  LODWORD(v25) = v23 + *(_DWORD *)(v10 + 2400);
  LODWORD(v23) = *(_DWORD *)(a2 + 856);
  *(_DWORD *)(a2 + 852) = v25;
  LODWORD(v25) = v23 + *(_DWORD *)(v10 + 2404);
  LODWORD(v23) = *(_DWORD *)(a2 + 860);
  *(_DWORD *)(a2 + 856) = v25;
  LODWORD(v25) = v23 + *(_DWORD *)(v10 + 2408);
  LODWORD(v23) = *(_DWORD *)(a2 + 1648);
  *(_DWORD *)(a2 + 860) = v25;
  LODWORD(v25) = v23 + *(_DWORD *)(v10 + 2772);
  LODWORD(v23) = *(_DWORD *)(a2 + 864);
  *(_DWORD *)(a2 + 1648) = v25;
  LODWORD(v25) = v23 + *(_DWORD *)(v10 + 2412);
  LODWORD(v23) = *(_DWORD *)(a2 + 868);
  *(_DWORD *)(a2 + 864) = v25;
  LODWORD(v25) = v23 + *(_DWORD *)(v10 + 2416);
  LODWORD(v23) = *(_DWORD *)(a2 + 872);
  *(_DWORD *)(a2 + 868) = v25;
  LODWORD(v25) = v23 + *(_DWORD *)(v10 + 2420);
  v26 = *(_QWORD *)(a2 + 1592);
  *(_DWORD *)(a2 + 872) = v25;
  v27 = v26 + *(_QWORD *)(v10 + 2680);
  v28 = *(_QWORD *)(a2 + 1600);
  *(_QWORD *)(a2 + 1592) = v27;
  v29 = v28 + *(_QWORD *)(v10 + 2688);
  LODWORD(v28) = *(_DWORD *)(a2 + 1624);
  *(_QWORD *)(a2 + 1600) = v29;
  *(_QWORD *)(a2 + 1616) = *(_QWORD *)(v10 + 2696);
  *(_DWORD *)(a2 + 1624) = v28 + *(_DWORD *)(v10 + 2768);
  do
  {
    *(_DWORD *)(a2 + 1340 + v12) += *(_DWORD *)(v10 + 2424 + v12);
    v12 += 4;
  }
  while ( v12 != 252 );
  v30 = *(_QWORD *)(a2 + 2456);
  v31 = *(_QWORD *)(a2 + 2336);
  v32 = *(_DWORD *)(a2 + 1728);
  *(_DWORD *)(a2 + 1724) += *(_DWORD *)(v10 + 2776);
  v33 = v32 + *(_DWORD *)(v10 + 2780);
  v34 = *(_DWORD *)(a2 + 1732);
  *(_DWORD *)(a2 + 1728) = v33;
  v35 = v34 + *(_DWORD *)(v10 + 2784);
  v36 = *(_DWORD *)(a2 + 1736);
  *(_DWORD *)(a2 + 1732) = v35;
  v37 = v36 + *(_DWORD *)(v10 + 2788);
  v38 = *(_DWORD *)(a2 + 1740);
  *(_DWORD *)(a2 + 1736) = v37;
  v39 = v38 + *(_DWORD *)(v10 + 2792);
  v40 = *(_DWORD *)(a2 + 1744);
  *(_DWORD *)(a2 + 1740) = v39;
  v41 = v40 + *(_DWORD *)(v10 + 2796);
  v42 = *(_DWORD *)(a2 + 1748);
  *(_DWORD *)(a2 + 1744) = v41;
  v43 = v42 + *(_DWORD *)(v10 + 2800);
  v44 = *(_DWORD *)(a2 + 1752);
  *(_DWORD *)(a2 + 1748) = v43;
  v45 = v44 + *(_DWORD *)(v10 + 2804);
  v46 = *(_DWORD *)(a2 + 1756);
  *(_DWORD *)(a2 + 1752) = v45;
  v47 = v46 + *(_DWORD *)(v10 + 2808);
  v48 = *(_DWORD *)(a2 + 1760);
  *(_DWORD *)(a2 + 1756) = v47;
  v49 = v48 + *(_DWORD *)(v10 + 2812);
  v50 = *(_DWORD *)(a2 + 1764);
  *(_DWORD *)(a2 + 1760) = v49;
  v51 = v50 + *(_DWORD *)(v10 + 2816);
  v52 = *(_DWORD *)(a2 + 1768);
  *(_DWORD *)(a2 + 1764) = v51;
  v53 = v52 + *(_DWORD *)(v10 + 2820);
  v54 = *(_DWORD *)(a2 + 1772);
  *(_DWORD *)(a2 + 1768) = v53;
  v55 = v54 + *(_DWORD *)(v10 + 2824);
  v56 = *(_DWORD *)(a2 + 1776);
  *(_DWORD *)(a2 + 1772) = v55;
  v57 = v56 + *(_DWORD *)(v10 + 2828);
  v58 = *(_QWORD *)(a2 + 2512);
  *(_DWORD *)(a2 + 1776) = v57;
  v59 = v58 + *(_QWORD *)(v10 + 3008);
  v60 = *(_QWORD *)(a2 + 2520);
  *(_QWORD *)(a2 + 2512) = v59;
  v61 = v60 + *(_QWORD *)(v10 + 3016);
  v62 = *(_QWORD *)(a2 + 2600);
  *(_QWORD *)(a2 + 2520) = v61;
  v63 = v62 + *(_QWORD *)(v10 + 3216);
  v64 = *(_QWORD *)(a2 + 2608);
  *(_QWORD *)(a2 + 2600) = v63;
  v65 = v64 + *(_QWORD *)(v10 + 3224);
  v66 = *(_QWORD *)(a2 + 2528);
  *(_QWORD *)(a2 + 2608) = v65;
  v67 = v66 + *(_QWORD *)(v10 + 3024);
  v68 = *(_QWORD *)(a2 + 2536);
  *(_QWORD *)(a2 + 2528) = v67;
  v69 = v68 + *(_QWORD *)(v10 + 3032);
  v70 = *(_QWORD *)(a2 + 2496);
  *(_QWORD *)(a2 + 2536) = v69;
  v71 = v70 + *(_QWORD *)(v10 + 2992);
  v72 = *(_QWORD *)(a2 + 2504);
  *(_QWORD *)(a2 + 2496) = v71;
  v73 = v72 + *(_QWORD *)(v10 + 3000);
  v74 = *(_QWORD *)(a2 + 2544);
  *(_QWORD *)(a2 + 2504) = v73;
  v75 = v74 + *(_QWORD *)(v10 + 3040);
  v76 = *(_QWORD *)(a2 + 2552);
  *(_QWORD *)(a2 + 2544) = v75;
  v77 = v76 + *(_QWORD *)(v10 + 3048);
  LODWORD(v76) = *(_DWORD *)(a2 + 2560);
  *(_QWORD *)(a2 + 2552) = v77;
  LODWORD(v77) = v76 + *(_DWORD *)(v10 + 3056);
  LODWORD(v76) = *(_DWORD *)(a2 + 3636);
  *(_DWORD *)(a2 + 2560) = v77;
  LODWORD(v77) = v76 + *(_DWORD *)(v10 + 3232);
  v78 = *(_QWORD *)(a2 + 2568);
  *(_DWORD *)(a2 + 3636) = v77;
  v79 = v78 + *(_QWORD *)(v10 + 3064);
  v80 = *(_QWORD *)(a2 + 2576);
  *(_QWORD *)(a2 + 2568) = v79;
  v81 = v80 + *(_QWORD *)(v10 + 3072);
  v82 = *(_QWORD *)(a2 + 2584);
  *(_QWORD *)(a2 + 2576) = v81;
  v83 = v82 + *(_QWORD *)(v10 + 3080);
  v84 = *(_QWORD *)(a2 + 2592);
  *(_QWORD *)(a2 + 2584) = v83;
  v85 = v84 + *(_QWORD *)(v10 + 3088);
  v86 = *(_QWORD *)(a2 + 2624);
  *(_QWORD *)(a2 + 2592) = v85;
  v87 = v86 + *(_QWORD *)(v10 + 3104);
  v88 = *(_QWORD *)(a2 + 2632);
  *(_QWORD *)(a2 + 2624) = v87;
  v89 = v88 + *(_QWORD *)(v10 + 3112);
  v90 = *(_QWORD *)(a2 + 2640);
  *(_QWORD *)(a2 + 2632) = v89;
  v91 = v90 + *(_QWORD *)(v10 + 3120);
  v92 = *(_QWORD *)(a2 + 2648);
  *(_QWORD *)(a2 + 2640) = v91;
  v93 = v92 + *(_QWORD *)(v10 + 3128);
  LODWORD(v92) = *(_DWORD *)(a2 + 2656);
  *(_QWORD *)(a2 + 2648) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3136);
  LODWORD(v92) = *(_DWORD *)(a2 + 2664);
  *(_DWORD *)(a2 + 2656) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3144);
  LODWORD(v92) = *(_DWORD *)(a2 + 2668);
  *(_DWORD *)(a2 + 2664) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3148);
  LODWORD(v92) = *(_DWORD *)(a2 + 2672);
  *(_DWORD *)(a2 + 2668) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3152);
  LODWORD(v92) = *(_DWORD *)(a2 + 2676);
  *(_DWORD *)(a2 + 2672) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3156);
  LODWORD(v92) = *(_DWORD *)(a2 + 2680);
  *(_DWORD *)(a2 + 2676) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3160);
  LODWORD(v92) = *(_DWORD *)(a2 + 2684);
  *(_DWORD *)(a2 + 2680) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3164);
  LODWORD(v92) = *(_DWORD *)(a2 + 2688);
  *(_DWORD *)(a2 + 2684) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3168);
  LODWORD(v92) = *(_DWORD *)(a2 + 3432);
  *(_DWORD *)(a2 + 2688) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3172);
  LODWORD(v92) = *(_DWORD *)(a2 + 3436);
  *(_DWORD *)(a2 + 3432) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3176);
  LODWORD(v92) = *(_DWORD *)(a2 + 3496);
  *(_DWORD *)(a2 + 3436) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3180);
  LODWORD(v92) = *(_DWORD *)(a2 + 3540);
  *(_DWORD *)(a2 + 3496) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3184);
  LODWORD(v92) = *(_DWORD *)(a2 + 3544);
  *(_DWORD *)(a2 + 3540) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3188);
  LODWORD(v92) = *(_DWORD *)(a2 + 3548);
  *(_DWORD *)(a2 + 3544) = v93;
  LODWORD(v93) = v92 + *(_DWORD *)(v10 + 3192);
  v94 = *(_QWORD *)(a2 + 3616);
  *(_DWORD *)(a2 + 3548) = v93;
  v95 = v94 + *(_QWORD *)(v10 + 3200);
  v96 = *(_QWORD *)(a2 + 3624);
  *(_QWORD *)(a2 + 3616) = v95;
  v97 = v96 + *(_QWORD *)(v10 + 3208);
  LODWORD(v96) = *(_DWORD *)(a2 + 3648);
  *(_QWORD *)(a2 + 3624) = v97;
  *(_QWORD *)(a2 + 2616) = *(_QWORD *)(v10 + 3096);
  LODWORD(v97) = v96 + *(_DWORD *)(v10 + 3256);
  v98 = *(_QWORD *)(a2 + 2320);
  *(_DWORD *)(a2 + 3648) = v97;
  v99 = v98 + *(_QWORD *)(v10 + 2832);
  v100 = *(_QWORD *)(a2 + 2328);
  *(_QWORD *)(a2 + 2320) = v99;
  v101 = v100 + *(_QWORD *)(v10 + 2840);
  v102 = *(_QWORD *)(a2 + 2448);
  *(_QWORD *)(a2 + 2328) = v101;
  v103 = v102 + *(_QWORD *)(v10 + 2832);
  *(_QWORD *)(a2 + 2448) = v103;
  v104 = v30 + *(_QWORD *)(v10 + 2840);
  *(_QWORD *)(a2 + 2456) = v104;
  v105 = v31 + *(_QWORD *)(v10 + 2848);
  v106 = *(_QWORD *)(a2 + 2344);
  *(_QWORD *)(a2 + 2336) = v105;
  v107 = v106 + *(_QWORD *)(v10 + 2856);
  v108 = *(_QWORD *)(a2 + 2352);
  *(_QWORD *)(a2 + 2344) = v107;
  v109 = *(_QWORD *)(v10 + 2848) + v103;
  *(_QWORD *)(a2 + 2448) = v109;
  v110 = *(_QWORD *)(v10 + 2856) + v104;
  *(_QWORD *)(a2 + 2456) = v110;
  v111 = v108 + *(_QWORD *)(v10 + 2864);
  v112 = *(_QWORD *)(a2 + 2360);
  *(_QWORD *)(a2 + 2352) = v111;
  v113 = v112 + *(_QWORD *)(v10 + 2872);
  v114 = *(_QWORD *)(a2 + 2368);
  *(_QWORD *)(a2 + 2360) = v113;
  v115 = *(_QWORD *)(v10 + 2864) + v109;
  *(_QWORD *)(a2 + 2448) = v115;
  v116 = *(_QWORD *)(v10 + 2872) + v110;
  *(_QWORD *)(a2 + 2456) = v116;
  v117 = v114 + *(_QWORD *)(v10 + 2880);
  v118 = *(_QWORD *)(a2 + 2376);
  *(_QWORD *)(a2 + 2368) = v117;
  v119 = v118 + *(_QWORD *)(v10 + 2888);
  v120 = *(_QWORD *)(a2 + 2384);
  *(_QWORD *)(a2 + 2376) = v119;
  v121 = *(_QWORD *)(v10 + 2880) + v115;
  *(_QWORD *)(a2 + 2448) = v121;
  v122 = *(_QWORD *)(v10 + 2888) + v116;
  *(_QWORD *)(a2 + 2456) = v122;
  v123 = v120 + *(_QWORD *)(v10 + 2896);
  v124 = *(_QWORD *)(a2 + 2392);
  *(_QWORD *)(a2 + 2384) = v123;
  v125 = v124 + *(_QWORD *)(v10 + 2904);
  v126 = *(_QWORD *)(a2 + 2400);
  *(_QWORD *)(a2 + 2392) = v125;
  v127 = *(_QWORD *)(v10 + 2896) + v121;
  *(_QWORD *)(a2 + 2448) = v127;
  v128 = *(_QWORD *)(v10 + 2904) + v122;
  *(_QWORD *)(a2 + 2456) = v128;
  v129 = v126 + *(_QWORD *)(v10 + 2912);
  v130 = *(_QWORD *)(a2 + 2408);
  *(_QWORD *)(a2 + 2400) = v129;
  v131 = v130 + *(_QWORD *)(v10 + 2920);
  v132 = *(_QWORD *)(a2 + 2416);
  *(_QWORD *)(a2 + 2408) = v131;
  v133 = *(_QWORD *)(v10 + 2912) + v127;
  *(_QWORD *)(a2 + 2448) = v133;
  v134 = *(_QWORD *)(v10 + 2920) + v128;
  *(_QWORD *)(a2 + 2456) = v134;
  v135 = v132 + *(_QWORD *)(v10 + 2928);
  v136 = *(_QWORD *)(a2 + 2424);
  *(_QWORD *)(a2 + 2416) = v135;
  v137 = v136 + *(_QWORD *)(v10 + 2936);
  v138 = *(_QWORD *)(a2 + 2432);
  *(_QWORD *)(a2 + 2424) = v137;
  v139 = *(_QWORD *)(v10 + 2928) + v133;
  *(_QWORD *)(a2 + 2448) = v139;
  v140 = *(_QWORD *)(v10 + 2936) + v134;
  *(_QWORD *)(a2 + 2456) = v140;
  v141 = v138 + *(_QWORD *)(v10 + 2944);
  v142 = *(_QWORD *)(a2 + 2440);
  *(_QWORD *)(a2 + 2432) = v141;
  *(_QWORD *)(a2 + 2440) = v142 + *(_QWORD *)(v10 + 2952);
  *(_QWORD *)(a2 + 2448) = *(_QWORD *)(v10 + 2944) + v139;
  v143 = *(_QWORD *)(v10 + 2952) + v140;
  v144 = *(_QWORD *)(a2 + 2464);
  *(_QWORD *)(a2 + 2456) = v143;
  v145 = v144 + *(_QWORD *)(v10 + 2960);
  v146 = *(_QWORD *)(a2 + 2472);
  *(_QWORD *)(a2 + 2464) = v145;
  v147 = v146 + *(_QWORD *)(v10 + 2968);
  v148 = *(_QWORD *)(a2 + 2480);
  *(_QWORD *)(a2 + 2472) = v147;
  v149 = v148 + *(_QWORD *)(v10 + 2976);
  v150 = *(_QWORD *)(a2 + 2488);
  *(_QWORD *)(a2 + 2480) = v149;
  v151 = v150 + *(_QWORD *)(v10 + 2984);
  v152 = *(_QWORD *)(a2 + 3688);
  *(_QWORD *)(a2 + 2488) = v151;
  v153 = v152 + *(_QWORD *)(v10 + 3240);
  v154 = *(_QWORD *)(a2 + 3696);
  *(_QWORD *)(a2 + 3688) = v153;
  v155 = v154 + *(_QWORD *)(v10 + 3248);
  v156 = *(_QWORD *)(a2 + 656);
  *(_QWORD *)(a2 + 3696) = v155;
  v157 = v156 + *(unsigned int *)(v10 + 2324);
  v158 = *(_QWORD *)(a2 + 664);
  *(_QWORD *)(a2 + 656) = v157;
  v159 = v158 + *(_QWORD *)(v10 + 2384);
  LODWORD(v158) = *(_DWORD *)(a2 + 672);
  *(_QWORD *)(a2 + 664) = v159;
  LODWORD(v159) = v158 + *(_DWORD *)(v10 + 2332);
  v160 = *(_QWORD *)(a2 + 680);
  *(_DWORD *)(a2 + 672) = v159;
  v161 = v160 + *(unsigned int *)(v10 + 2328);
  v162 = *(_QWORD *)(a2 + 688);
  *(_QWORD *)(a2 + 680) = v161;
  v163 = v162 + *(_QWORD *)(v10 + 2392);
  LODWORD(v162) = *(_DWORD *)(a2 + 696);
  *(_QWORD *)(a2 + 688) = v163;
  LODWORD(v163) = v162 + *(_DWORD *)(v10 + 2336);
  LODWORD(v162) = *(_DWORD *)(a2 + 700);
  *(_DWORD *)(a2 + 696) = v163;
  LODWORD(v163) = v162 + *(_DWORD *)(v10 + 2340);
  LODWORD(v162) = *(_DWORD *)(a2 + 704);
  *(_DWORD *)(a2 + 700) = v163;
  LODWORD(v163) = v162 + *(_DWORD *)(v10 + 2344);
  LODWORD(v162) = *(_DWORD *)(a2 + 708);
  *(_DWORD *)(a2 + 704) = v163;
  LODWORD(v163) = v162 + *(_DWORD *)(v10 + 2348);
  LODWORD(v162) = *(_DWORD *)(a2 + 712);
  *(_DWORD *)(a2 + 708) = v163;
  LODWORD(v163) = v162 + *(_DWORD *)(v10 + 2352);
  LODWORD(v162) = *(_DWORD *)(a2 + 716);
  *(_DWORD *)(a2 + 712) = v163;
  LODWORD(v163) = v162 + *(_DWORD *)(v10 + 2356);
  LODWORD(v162) = *(_DWORD *)(a2 + 720);
  *(_DWORD *)(a2 + 716) = v163;
  LODWORD(v163) = v162 + *(_DWORD *)(v10 + 2360);
  LODWORD(v162) = *(_DWORD *)(a2 + 724);
  *(_DWORD *)(a2 + 720) = v163;
  LODWORD(v163) = v162 + *(_DWORD *)(v10 + 2364);
  LODWORD(v162) = *(_DWORD *)(a2 + 728);
  *(_DWORD *)(a2 + 724) = v163;
  LODWORD(v163) = v162 + *(_DWORD *)(v10 + 2368);
  LODWORD(v162) = *(_DWORD *)(a2 + 732);
  *(_DWORD *)(a2 + 728) = v163;
  *(_DWORD *)(a2 + 732) = v162 + *(_DWORD *)(v10 + 2372);
  *(_DWORD *)(a2 + 736) += *(_DWORD *)(v10 + 2380);
  v164 = *result;
  if ( *result )
  {
    v165 = *(_DWORD *)(a2 + 120);
    v166 = 0;
    *(_DWORD *)(a2 + 116) += *(_DWORD *)(v164 + 3264);
    *(_DWORD *)(a2 + 120) = v165 + *(_DWORD *)(v164 + 3268);
    v167 = *(_DWORD *)(a2 + 128);
    v168 = *(_DWORD *)(a2 + 844);
    *(_DWORD *)(a2 + 124) += *(_DWORD *)(v164 + 3272);
    v169 = v168 + *(_DWORD *)(v164 + 3608);
    v170 = *(_DWORD *)(a2 + 848);
    *(_DWORD *)(a2 + 844) = v169;
    v171 = v170 + *(_DWORD *)(v164 + 3612);
    v172 = *(_DWORD *)(a2 + 1336);
    *(_DWORD *)(a2 + 848) = v171;
    v173 = v172 + *(_DWORD *)(v164 + 3616);
    v174 = *(_DWORD *)(a2 + 880);
    *(_DWORD *)(a2 + 1336) = v173;
    v175 = v174 + *(_DWORD *)(v164 + 3620);
    v176 = *(_DWORD *)(a2 + 884);
    *(_DWORD *)(a2 + 880) = v175;
    v177 = v176 + *(_DWORD *)(v164 + 3624);
    v178 = *(_DWORD *)(a2 + 888);
    *(_DWORD *)(a2 + 884) = v177;
    v179 = v178 + *(_DWORD *)(v164 + 3628);
    v180 = *(_DWORD *)(a2 + 536);
    *(_DWORD *)(a2 + 888) = v179;
    *(_DWORD *)(a2 + 140) = *(_DWORD *)(v164 + 3632);
    *(_DWORD *)(a2 + 144) = *(_DWORD *)(v164 + 3636);
    *(_DWORD *)(a2 + 148) = *(_DWORD *)(v164 + 3640);
    *(_DWORD *)(a2 + 152) = *(_DWORD *)(v164 + 3644);
    *(_DWORD *)(a2 + 156) = *(_DWORD *)(v164 + 3648);
    *(_QWORD *)(a2 + 168) = *(_QWORD *)(v164 + 3656);
    *(_QWORD *)(a2 + 176) = *(_QWORD *)(v164 + 3664);
    *(_WORD *)(a2 + 840) = *(_WORD *)(v164 + 3672);
    v181 = v180 + *(_DWORD *)(v164 + 3696);
    v182 = *(_DWORD *)(a2 + 1608);
    *(_DWORD *)(a2 + 536) = v181;
    *(_DWORD *)(a2 + 1256) = *(_DWORD *)(v164 + 3764);
    *(_DWORD *)(a2 + 1260) = *(_DWORD *)(v164 + 3768);
    *(_DWORD *)(a2 + 184) = *(_DWORD *)(v164 + 4208);
    *(_DWORD *)(a2 + 188) = *(_DWORD *)(v164 + 4212);
    v183 = v182 & 0xFFFFFFF0 | *(_DWORD *)(v164 + 4220) & 0xF;
    *(_DWORD *)(a2 + 1608) = v183;
    v184 = v183 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v164 + 4220) >> 4) & 0xF));
    *(_DWORD *)(a2 + 1608) = v184;
    v185 = v184 & 0xFFFFF0FF | (((*(_DWORD *)(v164 + 4220) >> 8) & 0xF) << 8);
    *(_DWORD *)(a2 + 1608) = v185;
    v186 = v185 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v164 + 4220)) >> 4 << 12);
    *(_DWORD *)(a2 + 1608) = v186;
    *(_DWORD *)(a2 + 1608) = v186 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v164 + 4220)) & 0xF) << 16);
    v187 = *(_DWORD *)(a2 + 1612);
    *(_DWORD *)(a2 + 128) = v167 + *(_DWORD *)(v164 + 4224);
    *(_DWORD *)(a2 + 1612) = v187 + *(_DWORD *)(v164 + 4228);
    *(_DWORD *)(a2 + 1632) = *(_DWORD *)(v164 + 4264);
    *(_DWORD *)(a2 + 1636) = *(_DWORD *)(v164 + 4268);
    *(_DWORD *)(a2 + 1640) = *(_DWORD *)(v164 + 4272);
    *(_DWORD *)(a2 + 1644) = *(_DWORD *)(v164 + 4276);
    do
    {
      v188 = (_DWORD *)(a2 + 216 + v166);
      v189 = (_DWORD *)(v164 + 3332 + v166);
      v166 += 60;
      v190 = v188[1];
      *v188 += *(v189 - 14);
      v188[1] = v190 + *(v189 - 13);
      v191 = v188[3];
      v188[2] += *(v189 - 12);
      v188[3] = v191 + *(v189 - 11);
      v192 = v188[5];
      v188[4] += *(v189 - 10);
      v188[5] = v192 + *(v189 - 9);
      v193 = v188[7];
      v188[6] += *(v189 - 8);
      v188[7] = v193 + *(v189 - 7);
      v194 = v188[9];
      v188[8] += *(v189 - 6);
      v188[9] = v194 + *(v189 - 5);
      v195 = v188[11];
      v188[10] += *(v189 - 4);
      v188[11] = v195 + *(v189 - 3);
      v196 = v188[13];
      v188[12] += *(v189 - 2);
      v188[13] = v196 + *(v189 - 1);
      v188[14] += *v189;
    }
    while ( v166 != 300 );
    v197 = 0;
    v198 = *(_QWORD *)(a2 + 1656);
    *(_DWORD *)(a2 + 604) += *(_DWORD *)(v164 + 3576);
    v199 = v198 + *(_QWORD *)(v164 + 4312);
    LODWORD(v198) = *(_DWORD *)(a2 + 620);
    *(_QWORD *)(a2 + 1656) = v199;
    LODWORD(v199) = v198 + *(_DWORD *)(v164 + 3592);
    LODWORD(v198) = *(_DWORD *)(a2 + 608);
    *(_DWORD *)(a2 + 620) = v199;
    LODWORD(v199) = v198 + *(_DWORD *)(v164 + 3580);
    v200 = *(_QWORD *)(a2 + 1664);
    *(_DWORD *)(a2 + 608) = v199;
    v201 = v200 + *(_QWORD *)(v164 + 4320);
    LODWORD(v200) = *(_DWORD *)(a2 + 624);
    *(_QWORD *)(a2 + 1664) = v201;
    LODWORD(v201) = v200 + *(_DWORD *)(v164 + 3596);
    LODWORD(v200) = *(_DWORD *)(a2 + 612);
    *(_DWORD *)(a2 + 624) = v201;
    LODWORD(v201) = v200 + *(_DWORD *)(v164 + 3584);
    v202 = *(_QWORD *)(a2 + 1672);
    *(_DWORD *)(a2 + 612) = v201;
    v203 = v202 + *(_QWORD *)(v164 + 4328);
    LODWORD(v202) = *(_DWORD *)(a2 + 628);
    *(_QWORD *)(a2 + 1672) = v203;
    LODWORD(v203) = v202 + *(_DWORD *)(v164 + 3600);
    LODWORD(v202) = *(_DWORD *)(a2 + 616);
    *(_DWORD *)(a2 + 628) = v203;
    LODWORD(v203) = v202 + *(_DWORD *)(v164 + 3588);
    v204 = *(_QWORD *)(a2 + 1680);
    *(_DWORD *)(a2 + 616) = v203;
    v205 = v204 + *(_QWORD *)(v164 + 4336);
    LODWORD(v204) = *(_DWORD *)(a2 + 632);
    *(_QWORD *)(a2 + 1680) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3604);
    LODWORD(v204) = *(_DWORD *)(a2 + 516);
    *(_DWORD *)(a2 + 632) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3676);
    LODWORD(v204) = *(_DWORD *)(a2 + 520);
    *(_DWORD *)(a2 + 516) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3680);
    LODWORD(v204) = *(_DWORD *)(a2 + 524);
    *(_DWORD *)(a2 + 520) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3684);
    LODWORD(v204) = *(_DWORD *)(a2 + 528);
    *(_DWORD *)(a2 + 524) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3688);
    LODWORD(v204) = *(_DWORD *)(a2 + 532);
    *(_DWORD *)(a2 + 528) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3692);
    LODWORD(v204) = *(_DWORD *)(a2 + 540);
    *(_DWORD *)(a2 + 532) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3700);
    LODWORD(v204) = *(_DWORD *)(a2 + 544);
    *(_DWORD *)(a2 + 540) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3704);
    LODWORD(v204) = *(_DWORD *)(a2 + 548);
    *(_DWORD *)(a2 + 544) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3708);
    LODWORD(v204) = *(_DWORD *)(a2 + 552);
    *(_DWORD *)(a2 + 548) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3712);
    LODWORD(v204) = *(_DWORD *)(a2 + 556);
    *(_DWORD *)(a2 + 552) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3716);
    LODWORD(v204) = *(_DWORD *)(a2 + 560);
    *(_DWORD *)(a2 + 556) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3720);
    LODWORD(v204) = *(_DWORD *)(a2 + 564);
    *(_DWORD *)(a2 + 560) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3724);
    LODWORD(v204) = *(_DWORD *)(a2 + 568);
    *(_DWORD *)(a2 + 564) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3728);
    LODWORD(v204) = *(_DWORD *)(a2 + 572);
    *(_DWORD *)(a2 + 568) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3732);
    LODWORD(v204) = *(_DWORD *)(a2 + 576);
    *(_DWORD *)(a2 + 572) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3736);
    LODWORD(v204) = *(_DWORD *)(a2 + 580);
    *(_DWORD *)(a2 + 576) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3740);
    LODWORD(v204) = *(_DWORD *)(a2 + 584);
    *(_DWORD *)(a2 + 580) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3744);
    LODWORD(v204) = *(_DWORD *)(a2 + 588);
    *(_DWORD *)(a2 + 584) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3748);
    LODWORD(v204) = *(_DWORD *)(a2 + 592);
    *(_DWORD *)(a2 + 588) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3752);
    LODWORD(v204) = *(_DWORD *)(a2 + 596);
    *(_DWORD *)(a2 + 592) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3756);
    LODWORD(v204) = *(_DWORD *)(a2 + 600);
    *(_DWORD *)(a2 + 596) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3760);
    LODWORD(v204) = *(_DWORD *)(a2 + 1264);
    *(_DWORD *)(a2 + 600) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3772);
    LODWORD(v204) = *(_DWORD *)(a2 + 1268);
    *(_DWORD *)(a2 + 1264) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3776);
    LODWORD(v204) = *(_DWORD *)(a2 + 1272);
    *(_DWORD *)(a2 + 1268) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3780);
    LODWORD(v204) = *(_DWORD *)(a2 + 1276);
    *(_DWORD *)(a2 + 1272) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3784);
    LODWORD(v204) = *(_DWORD *)(a2 + 1280);
    *(_DWORD *)(a2 + 1276) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3788);
    LODWORD(v204) = *(_DWORD *)(a2 + 1284);
    *(_DWORD *)(a2 + 1280) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3792);
    LODWORD(v204) = *(_DWORD *)(a2 + 1288);
    *(_DWORD *)(a2 + 1284) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3796);
    LODWORD(v204) = *(_DWORD *)(a2 + 1292);
    *(_DWORD *)(a2 + 1288) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3800);
    LODWORD(v204) = *(_DWORD *)(a2 + 1296);
    *(_DWORD *)(a2 + 1292) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3804);
    LODWORD(v204) = *(_DWORD *)(a2 + 1300);
    *(_DWORD *)(a2 + 1296) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3808);
    LODWORD(v204) = *(_DWORD *)(a2 + 1304);
    *(_DWORD *)(a2 + 1300) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3812);
    LODWORD(v204) = *(_DWORD *)(a2 + 1308);
    *(_DWORD *)(a2 + 1304) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3816);
    LODWORD(v204) = *(_DWORD *)(a2 + 1312);
    *(_DWORD *)(a2 + 1308) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3820);
    LODWORD(v204) = *(_DWORD *)(a2 + 1316);
    *(_DWORD *)(a2 + 1312) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3824);
    LODWORD(v204) = *(_DWORD *)(a2 + 1320);
    *(_DWORD *)(a2 + 1316) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3828);
    LODWORD(v204) = *(_DWORD *)(a2 + 1324);
    *(_DWORD *)(a2 + 1320) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3832);
    LODWORD(v204) = *(_DWORD *)(a2 + 1328);
    *(_DWORD *)(a2 + 1324) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3836);
    LODWORD(v204) = *(_DWORD *)(a2 + 1332);
    *(_DWORD *)(a2 + 1328) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3840);
    LODWORD(v204) = *(_DWORD *)(a2 + 892);
    *(_DWORD *)(a2 + 1332) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3844);
    LODWORD(v204) = *(_DWORD *)(a2 + 896);
    *(_DWORD *)(a2 + 892) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3848);
    LODWORD(v204) = *(_DWORD *)(a2 + 900);
    *(_DWORD *)(a2 + 896) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3852);
    LODWORD(v204) = *(_DWORD *)(a2 + 904);
    *(_DWORD *)(a2 + 900) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3856);
    LODWORD(v204) = *(_DWORD *)(a2 + 908);
    *(_DWORD *)(a2 + 904) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3860);
    LODWORD(v204) = *(_DWORD *)(a2 + 912);
    *(_DWORD *)(a2 + 908) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3864);
    LODWORD(v204) = *(_DWORD *)(a2 + 916);
    *(_DWORD *)(a2 + 912) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3868);
    LODWORD(v204) = *(_DWORD *)(a2 + 920);
    *(_DWORD *)(a2 + 916) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3872);
    LODWORD(v204) = *(_DWORD *)(a2 + 924);
    *(_DWORD *)(a2 + 920) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3876);
    LODWORD(v204) = *(_DWORD *)(a2 + 928);
    *(_DWORD *)(a2 + 924) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3880);
    LODWORD(v204) = *(_DWORD *)(a2 + 932);
    *(_DWORD *)(a2 + 928) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3884);
    LODWORD(v204) = *(_DWORD *)(a2 + 936);
    *(_DWORD *)(a2 + 932) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3888);
    LODWORD(v204) = *(_DWORD *)(a2 + 940);
    *(_DWORD *)(a2 + 936) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3892);
    LODWORD(v204) = *(_DWORD *)(a2 + 944);
    *(_DWORD *)(a2 + 940) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3896);
    LODWORD(v204) = *(_DWORD *)(a2 + 948);
    *(_DWORD *)(a2 + 944) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3900);
    LODWORD(v204) = *(_DWORD *)(a2 + 952);
    *(_DWORD *)(a2 + 948) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3904);
    LODWORD(v204) = *(_DWORD *)(a2 + 956);
    *(_DWORD *)(a2 + 952) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3908);
    LODWORD(v204) = *(_DWORD *)(a2 + 960);
    *(_DWORD *)(a2 + 956) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3912);
    LODWORD(v204) = *(_DWORD *)(a2 + 964);
    *(_DWORD *)(a2 + 960) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3916);
    LODWORD(v204) = *(_DWORD *)(a2 + 968);
    *(_DWORD *)(a2 + 964) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3920);
    LODWORD(v204) = *(_DWORD *)(a2 + 972);
    *(_DWORD *)(a2 + 968) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3924);
    LODWORD(v204) = *(_DWORD *)(a2 + 976);
    *(_DWORD *)(a2 + 972) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3928);
    LODWORD(v204) = *(_DWORD *)(a2 + 980);
    *(_DWORD *)(a2 + 976) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3932);
    LODWORD(v204) = *(_DWORD *)(a2 + 984);
    *(_DWORD *)(a2 + 980) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3936);
    LODWORD(v204) = *(_DWORD *)(a2 + 988);
    *(_DWORD *)(a2 + 984) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3940);
    LODWORD(v204) = *(_DWORD *)(a2 + 992);
    *(_DWORD *)(a2 + 988) = v205;
    LODWORD(v205) = v204 + *(_DWORD *)(v164 + 3944);
    LODWORD(v204) = *(_DWORD *)(a2 + 996);
    *(_DWORD *)(a2 + 992) = v205;
    *(_DWORD *)(a2 + 996) = v204 + *(_DWORD *)(v164 + 3948);
    do
    {
      *(_DWORD *)(a2 + 1000 + v197) = *(_DWORD *)(v164 + 3952 + v197);
      v197 += 4;
    }
    while ( v197 != 256 );
    v206 = 0;
    v207 = *(_QWORD *)(a2 + 1696);
    *(_QWORD *)(a2 + 1688) += *(_QWORD *)(v164 + 4232);
    v208 = v207 + *(_QWORD *)(v164 + 4240);
    v209 = *(_QWORD *)(a2 + 1704);
    *(_QWORD *)(a2 + 1696) = v208;
    v210 = v209 + *(_QWORD *)(v164 + 4248);
    v211 = *(_QWORD *)(a2 + 1712);
    *(_QWORD *)(a2 + 1704) = v210;
    v212 = v211 + *(_QWORD *)(v164 + 4256);
    v213 = *(_QWORD *)(a2 + 2296);
    *(_QWORD *)(a2 + 1712) = v212;
    *(_DWORD *)(a2 + 780) = *(_DWORD *)(v164 + 4280);
    *(_DWORD *)(a2 + 784) = *(_DWORD *)(v164 + 4284);
    *(_DWORD *)(a2 + 788) = *(_DWORD *)(v164 + 4288);
    *(_DWORD *)(a2 + 792) = *(_DWORD *)(v164 + 4292);
    *(_DWORD *)(a2 + 796) = *(_DWORD *)(v164 + 4296);
    *(_DWORD *)(a2 + 800) = *(_DWORD *)(v164 + 4300);
    *(_DWORD *)(a2 + 804) = *(_DWORD *)(v164 + 4304);
    *(_DWORD *)(a2 + 808) = *(_DWORD *)(v164 + 4308);
    v214 = v213 + *(_QWORD *)(v164 + 4344);
    LODWORD(v213) = *(_DWORD *)(a2 + 3108);
    *(_QWORD *)(a2 + 2296) = v214;
    LODWORD(v214) = v213 + *(_DWORD *)(v164 + 4668);
    LODWORD(v213) = *(_DWORD *)(a2 + 3112);
    *(_DWORD *)(a2 + 3108) = v214;
    LODWORD(v214) = v213 + *(_DWORD *)(v164 + 4672);
    v215 = *(_QWORD *)(a2 + 3688);
    *(_DWORD *)(a2 + 3112) = v214;
    v216 = v215 + *(_QWORD *)(v164 + 5264);
    v217 = *(_QWORD *)(a2 + 3696);
    *(_QWORD *)(a2 + 3688) = v216;
    v218 = v217 + *(_QWORD *)(v164 + 5272);
    LODWORD(v217) = *(_DWORD *)(a2 + 3424);
    *(_QWORD *)(a2 + 3696) = v218;
    LODWORD(v218) = v217 + *(_DWORD *)(v164 + 4676);
    LODWORD(v217) = *(_DWORD *)(a2 + 3428);
    *(_DWORD *)(a2 + 3424) = v218;
    LODWORD(v218) = v217 + *(_DWORD *)(v164 + 4680);
    LODWORD(v217) = *(_DWORD *)(a2 + 3500);
    *(_DWORD *)(a2 + 3428) = v218;
    LODWORD(v218) = v217 + *(_DWORD *)(v164 + 4684);
    LODWORD(v217) = *(_DWORD *)(a2 + 3504);
    *(_DWORD *)(a2 + 3500) = v218;
    LODWORD(v218) = v217 + *(_DWORD *)(v164 + 4688);
    LODWORD(v217) = *(_DWORD *)(a2 + 3720);
    *(_DWORD *)(a2 + 3504) = v218;
    *(_DWORD *)(a2 + 3448) = *(_DWORD *)(v164 + 5160);
    *(_DWORD *)(a2 + 3452) = *(_DWORD *)(v164 + 5164);
    *(_DWORD *)(a2 + 3456) = *(_DWORD *)(v164 + 5168);
    *(_DWORD *)(a2 + 3460) = *(_DWORD *)(v164 + 5172);
    *(_DWORD *)(a2 + 3516) = *(_DWORD *)(v164 + 5176);
    *(_DWORD *)(a2 + 3444) = *(_DWORD *)(v164 + 5180);
    *(_QWORD *)(a2 + 3528) = *(_QWORD *)(v164 + 5184);
    LODWORD(v218) = v217 + *(_DWORD *)(v164 + 5256);
    LODWORD(v217) = *(_DWORD *)(a2 + 3612);
    *(_DWORD *)(a2 + 3720) = v218;
    *(_BYTE *)(a2 + 3536) = *(_BYTE *)(v164 + 5192);
    *(_BYTE *)(a2 + 3537) = *(_BYTE *)(v164 + 5193);
    LODWORD(v217) = v217 & 0xFFFFFFF0 | *(_DWORD *)(v164 + 5194) & 0xF;
    *(_DWORD *)(a2 + 3612) = v217;
    LODWORD(v217) = v217 & 0xFFFFFF0F | (16 * ((*(_DWORD *)(v164 + 5194) >> 4) & 0xF));
    *(_DWORD *)(a2 + 3612) = v217;
    LODWORD(v217) = v217 & 0xFFFFF0FF | (((*(_DWORD *)(v164 + 5194) >> 8) & 0xF) << 8);
    *(_DWORD *)(a2 + 3612) = v217;
    LODWORD(v217) = v217 & 0xFFFF0FFF | ((unsigned __int8)HIBYTE(*(_WORD *)(v164 + 5194)) >> 4 << 12);
    LODWORD(v218) = *(_DWORD *)(a2 + 3632);
    *(_DWORD *)(a2 + 3612) = v217;
    *(_DWORD *)(a2 + 3612) = v217 & 0xFFF0FFFF | ((HIWORD(*(_DWORD *)(v164 + 5194)) & 0xF) << 16);
    *(_DWORD *)(a2 + 3632) = v218 + *(_DWORD *)(v164 + 5200);
    *(_DWORD *)(a2 + 3640) = *(_DWORD *)(v164 + 5204);
    *(_DWORD *)(a2 + 3644) = *(_DWORD *)(v164 + 5208);
    do
    {
      v219 = (_DWORD *)(a2 + 2724 + v206);
      v220 = (_DWORD *)(v164 + 4408 + v206);
      v206 += 60;
      v221 = v219[1];
      *v219 += *(v220 - 14);
      v219[1] = v221 + *(v220 - 13);
      v222 = v219[3];
      v219[2] += *(v220 - 12);
      v219[3] = v222 + *(v220 - 11);
      v223 = v219[5];
      v219[4] += *(v220 - 10);
      v219[5] = v223 + *(v220 - 9);
      v224 = v219[7];
      v219[6] += *(v220 - 8);
      v219[7] = v224 + *(v220 - 7);
      v225 = v219[9];
      v219[8] += *(v220 - 6);
      v219[9] = v225 + *(v220 - 5);
      v226 = v219[11];
      v219[10] += *(v220 - 4);
      v219[11] = v226 + *(v220 - 3);
      v227 = v219[13];
      v219[12] += *(v220 - 2);
      v219[13] = v227 + *(v220 - 1);
      v219[14] += *v220;
    }
    while ( v206 != 300 );
    v228 = 0;
    v229 = 1;
    *(_DWORD *)(a2 + 2692) += *(_DWORD *)(v164 + 4652);
    *(_QWORD *)(a2 + 3656) += *(_QWORD *)(v164 + 5216);
    *(_DWORD *)(a2 + 2696) += *(_DWORD *)(v164 + 4656);
    *(_QWORD *)(a2 + 3664) += *(_QWORD *)(v164 + 5224);
    *(_DWORD *)(a2 + 2700) += *(_DWORD *)(v164 + 4660);
    *(_QWORD *)(a2 + 3672) += *(_QWORD *)(v164 + 5232);
    *(_DWORD *)(a2 + 2704) += *(_DWORD *)(v164 + 4664);
    *(_QWORD *)(a2 + 3680) += *(_QWORD *)(v164 + 5240);
    *(_DWORD *)(a2 + 3116) += *(_DWORD *)(v164 + 4692);
    *(_DWORD *)(a2 + 3552) += *(_DWORD *)(v164 + 5100);
    *(_DWORD *)(a2 + 3120) += *(_DWORD *)(v164 + 4696);
    *(_DWORD *)(a2 + 3556) += *(_DWORD *)(v164 + 5104);
    *(_DWORD *)(a2 + 3124) += *(_DWORD *)(v164 + 4700);
    *(_DWORD *)(a2 + 3560) += *(_DWORD *)(v164 + 5108);
    *(_DWORD *)(a2 + 3128) += *(_DWORD *)(v164 + 4704);
    *(_DWORD *)(a2 + 3564) += *(_DWORD *)(v164 + 5112);
    *(_DWORD *)(a2 + 3132) += *(_DWORD *)(v164 + 4708);
    *(_DWORD *)(a2 + 3568) += *(_DWORD *)(v164 + 5116);
    *(_DWORD *)(a2 + 3136) += *(_DWORD *)(v164 + 4712);
    *(_DWORD *)(a2 + 3572) += *(_DWORD *)(v164 + 5120);
    *(_DWORD *)(a2 + 3140) += *(_DWORD *)(v164 + 4716);
    *(_DWORD *)(a2 + 3576) += *(_DWORD *)(v164 + 5124);
    *(_DWORD *)(a2 + 3144) += *(_DWORD *)(v164 + 4720);
    *(_DWORD *)(a2 + 3580) += *(_DWORD *)(v164 + 5128);
    *(_DWORD *)(a2 + 3148) += *(_DWORD *)(v164 + 4724);
    *(_DWORD *)(a2 + 3584) += *(_DWORD *)(v164 + 5132);
    *(_DWORD *)(a2 + 3152) += *(_DWORD *)(v164 + 4728);
    *(_DWORD *)(a2 + 3588) += *(_DWORD *)(v164 + 5136);
    *(_DWORD *)(a2 + 3156) += *(_DWORD *)(v164 + 4732);
    *(_DWORD *)(a2 + 3592) += *(_DWORD *)(v164 + 5140);
    *(_DWORD *)(a2 + 3160) += *(_DWORD *)(v164 + 4736);
    *(_DWORD *)(a2 + 3596) += *(_DWORD *)(v164 + 5144);
    *(_DWORD *)(a2 + 3164) += *(_DWORD *)(v164 + 4740);
    *(_DWORD *)(a2 + 3600) += *(_DWORD *)(v164 + 5148);
    *(_DWORD *)(a2 + 3168) += *(_DWORD *)(v164 + 4744);
    *(_DWORD *)(a2 + 3604) += *(_DWORD *)(v164 + 5152);
    *(_DWORD *)(a2 + 3172) += *(_DWORD *)(v164 + 4748);
    *(_DWORD *)(a2 + 3608) += *(_DWORD *)(v164 + 5156);
    do
    {
      v230 = 100 * v228;
      v231 = (_DWORD *)(v164 + 4752 + v230);
      v232 = (_DWORD *)(a2 + 3192 + v230);
      v233 = v232[9];
      v232[8] += v231[8];
      v232[9] = v233 + v231[9];
      v234 = v232[1];
      *v232 += *v231;
      v232[1] = v234 + v231[1];
      v235 = v232[3];
      v232[2] += v231[2];
      v232[3] = v235 + v231[3];
      v236 = v232[5];
      v232[4] += v231[4];
      v232[5] = v236 + v231[5];
      v237 = v232[7];
      v232[6] += v231[6];
      v232[7] = v237 + v231[7];
      v238 = v232[11];
      v232[10] += v231[10];
      v232[11] = v238 + v231[11];
      v239 = v232[13];
      v232[12] += v231[12];
      v232[13] = v239 + v231[13];
      v240 = v232[15];
      v232[14] += v231[14];
      v232[15] = v240 + v231[15];
      v241 = v232[17];
      v232[16] += v231[16];
      v232[17] = v241 + v231[17];
      v242 = v232[19];
      v232[18] += v231[18];
      v232[19] = v242 + v231[19];
      v243 = v232[21];
      v232[20] += v231[20];
      v232[21] = v243 + v231[21];
      v244 = v232[23];
      v245 = v229;
      v232[22] += v231[22];
      v232[23] = v244 + v231[23];
      v232[24] += v231[24];
      v228 = 1;
      v229 = 0;
    }
    while ( (v245 & 1) != 0 );
    v246 = *(_DWORD *)(a2 + 3176);
    *(_DWORD *)(a2 + 2708) += *(_DWORD *)(v164 + 4952);
    v247 = v246 + *(_DWORD *)(v164 + 4968);
    v248 = *(_DWORD *)(a2 + 2712);
    *(_DWORD *)(a2 + 3176) = v247;
    v249 = v248 + *(_DWORD *)(v164 + 4956);
    v250 = *(_DWORD *)(a2 + 3180);
    *(_DWORD *)(a2 + 2712) = v249;
    v251 = v250 + *(_DWORD *)(v164 + 4972);
    v252 = *(_DWORD *)(a2 + 2716);
    *(_DWORD *)(a2 + 3180) = v251;
    v253 = v252 + *(_DWORD *)(v164 + 4960);
    v254 = *(_DWORD *)(a2 + 3184);
    *(_DWORD *)(a2 + 2716) = v253;
    v255 = v254 + *(_DWORD *)(v164 + 4976);
    v256 = *(_DWORD *)(a2 + 2720);
    *(_DWORD *)(a2 + 3184) = v255;
    v257 = v256 + *(_DWORD *)(v164 + 4964);
    v258 = *(_DWORD *)(a2 + 3188);
    *(_DWORD *)(a2 + 2720) = v257;
    v259 = v258 + *(_DWORD *)(v164 + 4980);
    v260 = *(_DWORD *)(a2 + 3024);
    *(_DWORD *)(a2 + 3188) = v259;
    v261 = v260 + *(_DWORD *)(v164 + 4984);
    v262 = *(_DWORD *)(a2 + 3028);
    *(_DWORD *)(a2 + 3024) = v261;
    v263 = v262 + *(_DWORD *)(v164 + 4988);
    v264 = *(_DWORD *)(a2 + 3032);
    *(_DWORD *)(a2 + 3028) = v263;
    v265 = v264 + *(_DWORD *)(v164 + 4992);
    v266 = *(_DWORD *)(a2 + 3036);
    *(_DWORD *)(a2 + 3032) = v265;
    v267 = v266 + *(_DWORD *)(v164 + 4996);
    v268 = *(_DWORD *)(a2 + 3040);
    *(_DWORD *)(a2 + 3036) = v267;
    v269 = v268 + *(_DWORD *)(v164 + 5000);
    v270 = *(_DWORD *)(a2 + 3044);
    *(_DWORD *)(a2 + 3040) = v269;
    v271 = v270 + *(_DWORD *)(v164 + 5004);
    v272 = *(_DWORD *)(a2 + 3076);
    *(_DWORD *)(a2 + 3044) = v271;
    v273 = v272 + *(_DWORD *)(v164 + 5036);
    v274 = *(_DWORD *)(a2 + 3048);
    *(_DWORD *)(a2 + 3076) = v273;
    v275 = v274 + *(_DWORD *)(v164 + 5008);
    v276 = *(_DWORD *)(a2 + 3080);
    *(_DWORD *)(a2 + 3048) = v275;
    v277 = v276 + *(_DWORD *)(v164 + 5040);
    v278 = *(_DWORD *)(a2 + 3052);
    *(_DWORD *)(a2 + 3080) = v277;
    v279 = v278 + *(_DWORD *)(v164 + 5012);
    v280 = *(_DWORD *)(a2 + 3084);
    *(_DWORD *)(a2 + 3052) = v279;
    v281 = v280 + *(_DWORD *)(v164 + 5044);
    v282 = *(_DWORD *)(a2 + 3056);
    *(_DWORD *)(a2 + 3084) = v281;
    v283 = v282 + *(_DWORD *)(v164 + 5016);
    v284 = *(_DWORD *)(a2 + 3088);
    *(_DWORD *)(a2 + 3056) = v283;
    v285 = v284 + *(_DWORD *)(v164 + 5048);
    v286 = *(_DWORD *)(a2 + 3060);
    *(_DWORD *)(a2 + 3088) = v285;
    v287 = v286 + *(_DWORD *)(v164 + 5020);
    v288 = *(_DWORD *)(a2 + 3092);
    *(_DWORD *)(a2 + 3060) = v287;
    v289 = v288 + *(_DWORD *)(v164 + 5052);
    v290 = *(_DWORD *)(a2 + 3064);
    *(_DWORD *)(a2 + 3092) = v289;
    v291 = v290 + *(_DWORD *)(v164 + 5024);
    v292 = *(_DWORD *)(a2 + 3096);
    *(_DWORD *)(a2 + 3064) = v291;
    v293 = v292 + *(_DWORD *)(v164 + 5056);
    v294 = *(_DWORD *)(a2 + 3068);
    *(_DWORD *)(a2 + 3096) = v293;
    v295 = v294 + *(_DWORD *)(v164 + 5028);
    v296 = *(_DWORD *)(a2 + 3100);
    *(_DWORD *)(a2 + 3068) = v295;
    v297 = v296 + *(_DWORD *)(v164 + 5060);
    v298 = *(_DWORD *)(a2 + 3072);
    *(_DWORD *)(a2 + 3100) = v297;
    v299 = v298 + *(_DWORD *)(v164 + 5032);
    v300 = *(_DWORD *)(a2 + 3104);
    *(_DWORD *)(a2 + 3072) = v299;
    v301 = v300 + *(_DWORD *)(v164 + 5064);
    v302 = *(_DWORD *)(a2 + 3392);
    *(_DWORD *)(a2 + 3104) = v301;
    v303 = v302 + *(_DWORD *)(v164 + 5068);
    v304 = *(_DWORD *)(a2 + 3396);
    *(_DWORD *)(a2 + 3392) = v303;
    v305 = v304 + *(_DWORD *)(v164 + 5072);
    v306 = *(_DWORD *)(a2 + 3400);
    *(_DWORD *)(a2 + 3396) = v305;
    v307 = v306 + *(_DWORD *)(v164 + 5076);
    v308 = *(_DWORD *)(a2 + 3404);
    *(_DWORD *)(a2 + 3400) = v307;
    v309 = v308 + *(_DWORD *)(v164 + 5080);
    v310 = *(_DWORD *)(a2 + 3408);
    *(_DWORD *)(a2 + 3404) = v309;
    v311 = v310 + *(_DWORD *)(v164 + 5084);
    v312 = *(_DWORD *)(a2 + 3412);
    *(_DWORD *)(a2 + 3408) = v311;
    v313 = v312 + *(_DWORD *)(v164 + 5088);
    v314 = *(_DWORD *)(a2 + 3416);
    *(_DWORD *)(a2 + 3412) = v313;
    v315 = v314 + *(_DWORD *)(v164 + 5092);
    v316 = *(_DWORD *)(a2 + 3420);
    *(_DWORD *)(a2 + 3416) = v315;
    *(_DWORD *)(a2 + 3420) = v316 + *(_DWORD *)(v164 + 5096);
    *(_QWORD *)(a2 + 3712) += *(_QWORD *)(v164 + 5248);
  }
  else
  {
LABEL_16:
    v317 = jiffies;
    if ( dp_get_peer_extd_stats___last_ticks - jiffies + 125 < 0 )
    {
      v318 = result;
      v319 = a2;
      qdf_trace_msg(0x45u, 2u, "%s: txrx_peer NULL", a3, a4, a5, a6, a7, a8, a9, a10, "dp_get_peer_extd_stats");
      result = v318;
      a2 = v319;
      dp_get_peer_extd_stats___last_ticks = v317;
    }
  }
  v320 = *(unsigned int *)(a2 + 124);
  v321 = *(_QWORD *)(a2 + 88) + v320;
  if ( v321 )
    v322 = 100 * (int)v320 / (unsigned int)v321;
  else
    v322 = 0;
  *(_DWORD *)(a2 + 1628) = v322;
  v323 = *result;
  if ( *result )
  {
    v324 = *(_QWORD *)(a2 + 16);
    v325 = *(_DWORD *)(a2 + 108);
    *(_QWORD *)(a2 + 8) += *(_QWORD *)(v323 + 16);
    *(_QWORD *)(a2 + 16) = v324 + *(_QWORD *)(v323 + 24);
    v326 = v325 + *(_DWORD *)(v323 + 12);
    v327 = *(_QWORD *)(a2 + 2304);
    *(_DWORD *)(a2 + 108) = v326;
    *(_QWORD *)(a2 + 2304) = v327 + *(_QWORD *)(v323 + 32);
    *(_QWORD *)(a2 + 2312) += *(_QWORD *)(v323 + 40);
  }
  return result;
}
