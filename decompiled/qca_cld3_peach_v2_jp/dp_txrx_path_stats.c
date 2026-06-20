__int64 __fastcall dp_txrx_path_stats(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x20
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  double v180; // d0
  double v181; // d1
  double v182; // d2
  double v183; // d3
  double v184; // d4
  double v185; // d5
  double v186; // d6
  double v187; // d7
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  double v228; // d0
  double v229; // d1
  double v230; // d2
  double v231; // d3
  double v232; // d4
  double v233; // d5
  double v234; // d6
  double v235; // d7
  double v236; // d0
  double v237; // d1
  double v238; // d2
  double v239; // d3
  double v240; // d4
  double v241; // d5
  double v242; // d6
  double v243; // d7
  double v244; // d0
  double v245; // d1
  double v246; // d2
  double v247; // d3
  double v248; // d4
  double v249; // d5
  double v250; // d6
  double v251; // d7
  double v252; // d0
  double v253; // d1
  double v254; // d2
  double v255; // d3
  double v256; // d4
  double v257; // d5
  double v258; // d6
  double v259; // d7
  double v260; // d0
  double v261; // d1
  double v262; // d2
  double v263; // d3
  double v264; // d4
  double v265; // d5
  double v266; // d6
  double v267; // d7
  double v268; // d0
  double v269; // d1
  double v270; // d2
  double v271; // d3
  double v272; // d4
  double v273; // d5
  double v274; // d6
  double v275; // d7
  int v276; // w0
  __int64 v277; // x24
  int v278; // w0
  __int64 v279; // x24
  int v280; // w0
  __int64 v281; // x24
  int v282; // w0
  __int64 v283; // x24
  int v284; // w0
  __int64 v285; // x24
  int v286; // w0
  __int64 v287; // x24
  int v288; // w0
  __int64 v289; // x24
  int v290; // w0
  __int64 v291; // x24
  int v292; // w0
  double v293; // d0
  double v294; // d1
  double v295; // d2
  double v296; // d3
  double v297; // d4
  double v298; // d5
  double v299; // d6
  double v300; // d7
  double v301; // d0
  double v302; // d1
  double v303; // d2
  double v304; // d3
  double v305; // d4
  double v306; // d5
  double v307; // d6
  double v308; // d7
  double v309; // d0
  double v310; // d1
  double v311; // d2
  double v312; // d3
  double v313; // d4
  double v314; // d5
  double v315; // d6
  double v316; // d7
  int v317; // w0
  __int64 v318; // x4
  __int64 v319; // x22
  int v320; // w0
  __int64 v321; // x4
  int v322; // w0
  __int64 v323; // x4
  int v324; // w0
  __int64 v325; // x4
  int v326; // w0
  __int64 v327; // x4
  int v328; // w0
  __int64 v329; // x4
  int v330; // w0
  __int64 v331; // x4
  int v332; // w0
  __int64 v333; // x4
  int v334; // w0
  double v335; // d0
  double v336; // d1
  double v337; // d2
  double v338; // d3
  double v339; // d4
  double v340; // d5
  double v341; // d6
  double v342; // d7
  double v343; // d0
  double v344; // d1
  double v345; // d2
  double v346; // d3
  double v347; // d4
  double v348; // d5
  double v349; // d6
  double v350; // d7
  double v351; // d0
  double v352; // d1
  double v353; // d2
  double v354; // d3
  double v355; // d4
  double v356; // d5
  double v357; // d6
  double v358; // d7
  double v359; // d0
  double v360; // d1
  double v361; // d2
  double v362; // d3
  double v363; // d4
  double v364; // d5
  double v365; // d6
  double v366; // d7
  double v367; // d0
  double v368; // d1
  double v369; // d2
  double v370; // d3
  double v371; // d4
  double v372; // d5
  double v373; // d6
  double v374; // d7
  double v375; // d0
  double v376; // d1
  double v377; // d2
  double v378; // d3
  double v379; // d4
  double v380; // d5
  double v381; // d6
  double v382; // d7
  double v383; // d0
  double v384; // d1
  double v385; // d2
  double v386; // d3
  double v387; // d4
  double v388; // d5
  double v389; // d6
  double v390; // d7
  double v391; // d0
  double v392; // d1
  double v393; // d2
  double v394; // d3
  double v395; // d4
  double v396; // d5
  double v397; // d6
  double v398; // d7
  double v399; // d0
  double v400; // d1
  double v401; // d2
  double v402; // d3
  double v403; // d4
  double v404; // d5
  double v405; // d6
  double v406; // d7
  __int64 i; // x22
  int v408; // w0
  __int64 v409; // x24
  int v410; // w0
  __int64 v411; // x24
  int v412; // w0
  __int64 v413; // x24
  int v414; // w0
  __int64 v415; // x24
  int v416; // w0
  __int64 v417; // x24
  int v418; // w0
  __int64 v419; // x24
  int v420; // w0
  __int64 v421; // x24
  int v422; // w0
  __int64 v423; // x24
  int v424; // w0
  double v425; // d0
  double v426; // d1
  double v427; // d2
  double v428; // d3
  double v429; // d4
  double v430; // d5
  double v431; // d6
  double v432; // d7
  double v433; // d0
  double v434; // d1
  double v435; // d2
  double v436; // d3
  double v437; // d4
  double v438; // d5
  double v439; // d6
  double v440; // d7
  double v441; // d0
  double v442; // d1
  double v443; // d2
  double v444; // d3
  double v445; // d4
  double v446; // d5
  double v447; // d6
  double v448; // d7
  double v449; // d0
  double v450; // d1
  double v451; // d2
  double v452; // d3
  double v453; // d4
  double v454; // d5
  double v455; // d6
  double v456; // d7
  double v457; // d0
  double v458; // d1
  double v459; // d2
  double v460; // d3
  double v461; // d4
  double v462; // d5
  double v463; // d6
  double v464; // d7
  _BYTE s[283]; // [xsp+2h] [xbp-23Eh] BYREF
  _BYTE v466[283]; // [xsp+11Dh] [xbp-123h] BYREF
  __int64 v467; // [xsp+238h] [xbp-8h]

  v467 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)memset(s, 0, sizeof(s));
  if ( !a1 )
    goto LABEL_25;
  if ( *(_BYTE *)(a1 + 1120) )
  {
    v11 = *(_QWORD *)(a1 + 72);
    dp_aggregate_pdev_stats((_QWORD *)v11);
    DP_PRINT_STATS("Tx path Statistics:", v12, v13, v14, v15, v16, v17, v18, v19);
    DP_PRINT_STATS(
      "from stack: %llu msdus (%llu bytes)",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      *(_QWORD *)(v11 + 520),
      *(_QWORD *)(v11 + 528));
    DP_PRINT_STATS(
      "processed from host: %llu msdus (%llu bytes)",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      *(_QWORD *)(v11 + 568),
      *(_QWORD *)(v11 + 576));
    DP_PRINT_STATS(
      "successfully transmitted: %llu msdus (%llu bytes)",
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      *(_QWORD *)(v11 + 3072),
      *(_QWORD *)(v11 + 3080));
    dp_print_tx_ring_stats(a1);
    DP_PRINT_STATS("Invalid release source: %u", v44, v45, v46, v47, v48, v49, v50, v51, *(unsigned int *)(a1 + 13492));
    DP_PRINT_STATS(
      "Invalid TX desc from completion ring: %u",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      *(unsigned int *)(a1 + 13496));
    DP_PRINT_STATS("Dropped in host:", v60, v61, v62, v63, v64, v65, v66, v67);
    DP_PRINT_STATS("Total packets dropped: %llu", v68, v69, v70, v71, v72, v73, v74, v75, *(_QWORD *)(v11 + 784));
    DP_PRINT_STATS("Descriptor not available: %llu", v76, v77, v78, v79, v80, v81, v82, v83, *(_QWORD *)(v11 + 800));
    DP_PRINT_STATS("Ring full: %u", v84, v85, v86, v87, v88, v89, v90, v91, *(unsigned int *)(v11 + 864));
    DP_PRINT_STATS("Enqueue fail: %u", v92, v93, v94, v95, v96, v97, v98, v99, *(unsigned int *)(v11 + 868));
    DP_PRINT_STATS(
      "Pkt dropped in vdev-id check: %u",
      v100,
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      *(unsigned int *)(v11 + 884));
    DP_PRINT_STATS("DMA Error: %u", v108, v109, v110, v111, v112, v113, v114, v115, *(unsigned int *)(v11 + 872));
    DP_PRINT_STATS("Drop Ingress: %u", v116, v117, v118, v119, v120, v121, v122, v123, *(unsigned int *)(v11 + 888));
    DP_PRINT_STATS("Resources full: %u", v124, v125, v126, v127, v128, v129, v130, v131, *(unsigned int *)(v11 + 876));
    DP_PRINT_STATS(
      "Headroom insufficient: %u",
      v132,
      v133,
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      *(unsigned int *)(v11 + 880));
    DP_PRINT_STATS(
      "Invalid peer id in exception path: %u",
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      v147,
      *(unsigned int *)(v11 + 892));
    DP_PRINT_STATS("Tx Mcast Drop: %u", v148, v149, v150, v151, v152, v153, v154, v155, *(unsigned int *)(v11 + 896));
    DP_PRINT_STATS("FW2WBM Tx Drop: %u", v156, v157, v158, v159, v160, v161, v162, v163, *(unsigned int *)(v11 + 900));
    DP_PRINT_STATS("Dropped in hardware:", v164, v165, v166, v167, v168, v169, v170, v171);
    DP_PRINT_STATS(
      "total packets dropped: %u",
      v172,
      v173,
      v174,
      v175,
      v176,
      v177,
      v178,
      v179,
      *(unsigned int *)(v11 + 3092));
    DP_PRINT_STATS("mpdu age out: %u", v180, v181, v182, v183, v184, v185, v186, v187, *(unsigned int *)(v11 + 3680));
    DP_PRINT_STATS(
      "firmware removed packets: %llu (%llu bytes)",
      v188,
      v189,
      v190,
      v191,
      v192,
      v193,
      v194,
      v195,
      *(_QWORD *)(v11 + 3640),
      *(_QWORD *)(v11 + 3648));
    DP_PRINT_STATS("firmware removed tx: %llu", v196, v197, v198, v199, v200, v201, v202, v203, *(_QWORD *)(v11 + 3664));
    DP_PRINT_STATS(
      "firmware removed notx %u",
      v204,
      v205,
      v206,
      v207,
      v208,
      v209,
      v210,
      v211,
      *(unsigned int *)(v11 + 3656));
    DP_PRINT_STATS(
      "Invalid peer on tx path: %llu",
      v212,
      v213,
      v214,
      v215,
      v216,
      v217,
      v218,
      v219,
      *(_QWORD *)(*(_QWORD *)(v11 + 8) + 13448LL));
    DP_PRINT_STATS(
      "Tx desc freed in non-completion path: %u",
      v220,
      v221,
      v222,
      v223,
      v224,
      v225,
      v226,
      v227,
      *(unsigned int *)(*(_QWORD *)(v11 + 8) + 13532LL));
    DP_PRINT_STATS(
      "Tx desc force freed: %u",
      v228,
      v229,
      v230,
      v231,
      v232,
      v233,
      v234,
      v235,
      *(unsigned int *)(*(_QWORD *)(v11 + 8) + 13564LL));
    DP_PRINT_STATS(
      "SW tso pkt cnt: %u",
      v236,
      v237,
      v238,
      v239,
      v240,
      v241,
      v242,
      v243,
      *(unsigned int *)(*(_QWORD *)(v11 + 8) + 13576LL));
    DP_PRINT_STATS(
      "SW tso fail cnt: %u",
      v244,
      v245,
      v246,
      v247,
      v248,
      v249,
      v250,
      v251,
      *(unsigned int *)(*(_QWORD *)(v11 + 8) + 13580LL));
    DP_PRINT_STATS(
      "Push Head fail Tx Drop: %u",
      v252,
      v253,
      v254,
      v255,
      v256,
      v257,
      v258,
      v259,
      *(unsigned int *)(v11 + 904));
    DP_PRINT_STATS(
      "Prep MetaData fail Tx Drop: %u",
      v260,
      v261,
      v262,
      v263,
      v264,
      v265,
      v266,
      v267,
      *(unsigned int *)(v11 + 908));
    DP_PRINT_STATS(
      "Multipass fail Tx Drop: %u",
      v268,
      v269,
      v270,
      v271,
      v272,
      v273,
      v274,
      v275,
      *(unsigned int *)(v11 + 912));
    scnprintf(s, 283, "%s", "Tx/IRQ [Range:Pkts] [");
    v277 = v276;
    scnprintf(&s[v276], 283LL - v276, "1: %u, ", *(_DWORD *)(v11 + 6712));
    v279 = v277 + v278;
    scnprintf(&s[v279], 283 - v279, "2-20: %u, ", *(_DWORD *)(v11 + 6716));
    v281 = v279 + v280;
    scnprintf(&s[v281], 283 - v281, "21-40: %u, ", *(_DWORD *)(v11 + 6720));
    v283 = v281 + v282;
    scnprintf(&s[v283], 283 - v283, "41-60: %u, ", *(_DWORD *)(v11 + 6724));
    v285 = v283 + v284;
    scnprintf(&s[v285], 283 - v285, "61-80: %u, ", *(_DWORD *)(v11 + 6728));
    v287 = v285 + v286;
    scnprintf(&s[v287], 283 - v287, "81-100: %u, ", *(_DWORD *)(v11 + 6732));
    v289 = v287 + v288;
    scnprintf(&s[v289], 283 - v289, "101-200: %u, ", *(_DWORD *)(v11 + 6736));
    v291 = v289 + v290;
    scnprintf(&s[v291], 283 - v291, "201+: %u", *(_DWORD *)(v11 + 6740));
    v293 = scnprintf(&s[v291 + v292], 283 - (v291 + v292), "%s", "]");
    DP_PRINT_STATS("%s", v293, v294, v295, v296, v297, v298, v299, v300, s);
    DP_PRINT_STATS("Rx path statistics:", v301, v302, v303, v304, v305, v306, v307, v308);
    DP_PRINT_STATS(
      "delivered %llu msdus ( %llu bytes)",
      v309,
      v310,
      v311,
      v312,
      v313,
      v314,
      v315,
      v316,
      *(_QWORD *)(v11 + 5288),
      *(_QWORD *)(v11 + 5296));
    memset(v466, 0, sizeof(v466));
    scnprintf(v466, 283, "%s", "REO/msdus/bytes [");
    v318 = *(_QWORD *)(v11 + 5304);
    v319 = v317;
    if ( v318 )
    {
      scnprintf(&v466[v317], 283LL - v317, "%d %llu %llu, ", 0, v318, *(_QWORD *)(v11 + 5312));
      v319 += v320;
    }
    v321 = *(_QWORD *)(v11 + 5320);
    if ( v321 )
    {
      scnprintf(&v466[v319], 283 - v319, "%d %llu %llu, ", 1, v321, *(_QWORD *)(v11 + 5328));
      v319 += v322;
    }
    v323 = *(_QWORD *)(v11 + 5336);
    if ( v323 )
    {
      scnprintf(&v466[v319], 283 - v319, "%d %llu %llu, ", 2, v323, *(_QWORD *)(v11 + 5344));
      v319 += v324;
    }
    v325 = *(_QWORD *)(v11 + 5352);
    if ( v325 )
    {
      scnprintf(&v466[v319], 283 - v319, "%d %llu %llu, ", 3, v325, *(_QWORD *)(v11 + 5360));
      v319 += v326;
    }
    v327 = *(_QWORD *)(v11 + 5368);
    if ( v327 )
    {
      scnprintf(&v466[v319], 283 - v319, "%d %llu %llu, ", 4, v327, *(_QWORD *)(v11 + 5376));
      v319 += v328;
    }
    v329 = *(_QWORD *)(v11 + 5384);
    if ( v329 )
    {
      scnprintf(&v466[v319], 283 - v319, "%d %llu %llu, ", 5, v329, *(_QWORD *)(v11 + 5392));
      v319 += v330;
    }
    v331 = *(_QWORD *)(v11 + 5400);
    if ( v331 )
    {
      scnprintf(&v466[v319], 283 - v319, "%d %llu %llu, ", 6, v331, *(_QWORD *)(v11 + 5408));
      v319 += v332;
    }
    v333 = *(_QWORD *)(v11 + 5416);
    if ( v333 )
    {
      scnprintf(&v466[v319], 283 - v319, "%d %llu %llu, ", 7, v333, *(_QWORD *)(v11 + 5424));
      v319 += v334;
    }
    v335 = scnprintf(&v466[v319], 283 - v319, "%s", "]");
    DP_PRINT_STATS("%s", v335, v336, v337, v338, v339, v340, v341, v342, v466);
    DP_PRINT_STATS(
      "received on lmac[%d] %llu msdus (%llu bytes)",
      v343,
      v344,
      v345,
      v346,
      v347,
      v348,
      v349,
      v350,
      0,
      *(_QWORD *)(v11 + 5448),
      *(_QWORD *)(v11 + 5456));
    DP_PRINT_STATS(
      "received on lmac[%d] %llu msdus (%llu bytes)",
      v351,
      v352,
      v353,
      v354,
      v355,
      v356,
      v357,
      v358,
      1,
      *(_QWORD *)(v11 + 5464),
      *(_QWORD *)(v11 + 5472));
    DP_PRINT_STATS(
      "intra-bss packets %llu msdus ( %llu bytes)",
      v359,
      v360,
      v361,
      v362,
      v363,
      v364,
      v365,
      v366,
      *(_QWORD *)(v11 + 5608),
      *(_QWORD *)(v11 + 5616));
    DP_PRINT_STATS(
      "intra-bss fails %llu msdus ( %llu bytes)",
      v367,
      v368,
      v369,
      v370,
      v371,
      v372,
      v373,
      v374,
      *(_QWORD *)(v11 + 5624),
      *(_QWORD *)(v11 + 5632));
    DP_PRINT_STATS(
      "intra-bss no mdns fwds %u msdus",
      v375,
      v376,
      v377,
      v378,
      v379,
      v380,
      v381,
      v382,
      *(unsigned int *)(v11 + 5640));
    DP_PRINT_STATS(
      "raw packets %llu msdus ( %llu bytes)",
      v383,
      v384,
      v385,
      v386,
      v387,
      v388,
      v389,
      v390,
      *(_QWORD *)(v11 + 5528),
      *(_QWORD *)(v11 + 5536));
    DP_PRINT_STATS("Rx BAR frames:%d", v391, v392, v393, v394, v395, v396, v397, v398, *(unsigned int *)(a1 + 13648));
    dp_print_rx_err_stats(a1, v11);
    for ( i = 3444; i != 3476; ++i )
    {
      if ( *(_DWORD *)(*(_QWORD *)(v11 + 8) + 4 * i) )
        DP_PRINT_STATS("Rxdma error number (%u): %u msdus", v399, v400, v401, v402, v403, v404, v405, v406, i - 3444);
    }
    scnprintf(s, 283, "%s", "Rx/IRQ [Range:Pkts] [");
    v409 = v408;
    scnprintf(&s[v408], 283LL - v408, "1: %u, ", *(_DWORD *)(v11 + 6744));
    v411 = v409 + v410;
    scnprintf(&s[v411], 283 - v411, "2-20: %u, ", *(_DWORD *)(v11 + 6748));
    v413 = v411 + v412;
    scnprintf(&s[v413], 283 - v413, "21-40: %u, ", *(_DWORD *)(v11 + 6752));
    v415 = v413 + v414;
    scnprintf(&s[v415], 283 - v415, "41-60: %u, ", *(_DWORD *)(v11 + 6756));
    v417 = v415 + v416;
    scnprintf(&s[v417], 283 - v417, "61-80: %u, ", *(_DWORD *)(v11 + 6760));
    v419 = v417 + v418;
    scnprintf(&s[v419], 283 - v419, "81-100: %u, ", *(_DWORD *)(v11 + 6764));
    v421 = v419 + v420;
    scnprintf(&s[v421], 283 - v421, "101-200: %u, ", *(_DWORD *)(v11 + 6768));
    v423 = v421 + v422;
    scnprintf(&s[v423], 283 - v423, "201+: %u", *(_DWORD *)(v11 + 6772));
    v425 = scnprintf(&s[v423 + v424], 283 - (v423 + v424), "%s", "]");
    DP_PRINT_STATS("%s", v425, v426, v427, v428, v429, v430, v431, v432, s);
    DP_PRINT_STATS(
      "%s: tso_enable: %u lro_enable: %u rx_hash: %u napi_enable: %u",
      v433,
      v434,
      v435,
      v436,
      v437,
      v438,
      v439,
      v440,
      "dp_txrx_path_stats",
      *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v11 + 8) + 40LL) + 529LL),
      *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v11 + 8) + 40LL) + 530LL),
      *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v11 + 8) + 40LL) + 528LL),
      *(unsigned __int8 *)(*(_QWORD *)(*(_QWORD *)(v11 + 8) + 40LL) + 545LL));
    DP_PRINT_STATS(
      "%s: Tx flow stop queue: %u tx flow start queue offset: %u",
      v441,
      v442,
      v443,
      v444,
      v445,
      v446,
      v447,
      v448,
      "dp_txrx_path_stats",
      *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v11 + 8) + 40LL) + 556LL),
      *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v11 + 8) + 40LL) + 560LL));
    dp_print_rx_rates((unsigned int *)v11, v449, v450, v451, v452, v453, v454, v455, v456);
    result = dp_print_tx_rates((unsigned int *)v11, v457, v458, v459, v460, v461, v462, v463, v464);
    if ( *(unsigned __int8 *)(a1 + 1120) > 1u )
    {
      __break(0x5512u);
LABEL_25:
      result = qdf_trace_msg(0x45u, 2u, "%s: Invalid access", v3, v4, v5, v6, v7, v8, v9, v10, "dp_txrx_path_stats");
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
