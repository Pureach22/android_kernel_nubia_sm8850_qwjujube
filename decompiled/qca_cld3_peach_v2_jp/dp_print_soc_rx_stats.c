__int64 __fastcall dp_print_soc_rx_stats(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // x1
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  double v51; // d0
  double v52; // d1
  double v53; // d2
  double v54; // d3
  double v55; // d4
  double v56; // d5
  double v57; // d6
  double v58; // d7
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  double v115; // d0
  double v116; // d1
  double v117; // d2
  double v118; // d3
  double v119; // d4
  double v120; // d5
  double v121; // d6
  double v122; // d7
  double v123; // d0
  double v124; // d1
  double v125; // d2
  double v126; // d3
  double v127; // d4
  double v128; // d5
  double v129; // d6
  double v130; // d7
  double v131; // d0
  double v132; // d1
  double v133; // d2
  double v134; // d3
  double v135; // d4
  double v136; // d5
  double v137; // d6
  double v138; // d7
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  double v147; // d0
  double v148; // d1
  double v149; // d2
  double v150; // d3
  double v151; // d4
  double v152; // d5
  double v153; // d6
  double v154; // d7
  double v155; // d0
  double v156; // d1
  double v157; // d2
  double v158; // d3
  double v159; // d4
  double v160; // d5
  double v161; // d6
  double v162; // d7
  double v163; // d0
  double v164; // d1
  double v165; // d2
  double v166; // d3
  double v167; // d4
  double v168; // d5
  double v169; // d6
  double v170; // d7
  double v171; // d0
  double v172; // d1
  double v173; // d2
  double v174; // d3
  double v175; // d4
  double v176; // d5
  double v177; // d6
  double v178; // d7
  double v179; // d0
  double v180; // d1
  double v181; // d2
  double v182; // d3
  double v183; // d4
  double v184; // d5
  double v185; // d6
  double v186; // d7
  double v187; // d0
  double v188; // d1
  double v189; // d2
  double v190; // d3
  double v191; // d4
  double v192; // d5
  double v193; // d6
  double v194; // d7
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  double v203; // d0
  double v204; // d1
  double v205; // d2
  double v206; // d3
  double v207; // d4
  double v208; // d5
  double v209; // d6
  double v210; // d7
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  double v219; // d0
  double v220; // d1
  double v221; // d2
  double v222; // d3
  double v223; // d4
  double v224; // d5
  double v225; // d6
  double v226; // d7
  double v227; // d0
  double v228; // d1
  double v229; // d2
  double v230; // d3
  double v231; // d4
  double v232; // d5
  double v233; // d6
  double v234; // d7
  double v235; // d0
  double v236; // d1
  double v237; // d2
  double v238; // d3
  double v239; // d4
  double v240; // d5
  double v241; // d6
  double v242; // d7
  double v243; // d0
  double v244; // d1
  double v245; // d2
  double v246; // d3
  double v247; // d4
  double v248; // d5
  double v249; // d6
  double v250; // d7
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  double v259; // d0
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  double v267; // d0
  double v268; // d1
  double v269; // d2
  double v270; // d3
  double v271; // d4
  double v272; // d5
  double v273; // d6
  double v274; // d7
  double v275; // d0
  double v276; // d1
  double v277; // d2
  double v278; // d3
  double v279; // d4
  double v280; // d5
  double v281; // d6
  double v282; // d7
  double v283; // d0
  double v284; // d1
  double v285; // d2
  double v286; // d3
  double v287; // d4
  double v288; // d5
  double v289; // d6
  double v290; // d7
  double v291; // d0
  double v292; // d1
  double v293; // d2
  double v294; // d3
  double v295; // d4
  double v296; // d5
  double v297; // d6
  double v298; // d7
  double v299; // d0
  double v300; // d1
  double v301; // d2
  double v302; // d3
  double v303; // d4
  double v304; // d5
  double v305; // d6
  double v306; // d7
  double v307; // d0
  double v308; // d1
  double v309; // d2
  double v310; // d3
  double v311; // d4
  double v312; // d5
  double v313; // d6
  double v314; // d7
  double v315; // d0
  double v316; // d1
  double v317; // d2
  double v318; // d3
  double v319; // d4
  double v320; // d5
  double v321; // d6
  double v322; // d7
  double v323; // d0
  double v324; // d1
  double v325; // d2
  double v326; // d3
  double v327; // d4
  double v328; // d5
  double v329; // d6
  double v330; // d7
  double v331; // d0
  double v332; // d1
  double v333; // d2
  double v334; // d3
  double v335; // d4
  double v336; // d5
  double v337; // d6
  double v338; // d7
  double v339; // d0
  double v340; // d1
  double v341; // d2
  double v342; // d3
  double v343; // d4
  double v344; // d5
  double v345; // d6
  double v346; // d7
  double v347; // d0
  double v348; // d1
  double v349; // d2
  double v350; // d3
  double v351; // d4
  double v352; // d5
  double v353; // d6
  double v354; // d7
  __int64 v355; // x22
  unsigned __int8 v356; // w23
  char v357; // w0
  double v358; // d0
  double v359; // d1
  double v360; // d2
  double v361; // d3
  double v362; // d4
  double v363; // d5
  double v364; // d6
  double v365; // d7
  __int64 v366; // x21
  unsigned __int8 v367; // w22
  char v368; // w0
  double v369; // d0
  double v370; // d1
  double v371; // d2
  double v372; // d3
  double v373; // d4
  double v374; // d5
  double v375; // d6
  double v376; // d7
  double v377; // d0
  double v378; // d1
  double v379; // d2
  double v380; // d3
  double v381; // d4
  double v382; // d5
  double v383; // d6
  double v384; // d7
  double v385; // d0
  double v386; // d1
  double v387; // d2
  double v388; // d3
  double v389; // d4
  double v390; // d5
  double v391; // d6
  double v392; // d7
  double v393; // d0
  double v394; // d1
  double v395; // d2
  double v396; // d3
  double v397; // d4
  double v398; // d5
  double v399; // d6
  double v400; // d7
  double v401; // d0
  double v402; // d1
  double v403; // d2
  double v404; // d3
  double v405; // d4
  double v406; // d5
  double v407; // d6
  double v408; // d7
  double v409; // d0
  double v410; // d1
  double v411; // d2
  double v412; // d3
  double v413; // d4
  double v414; // d5
  double v415; // d6
  double v416; // d7
  double v417; // d0
  double v418; // d1
  double v419; // d2
  double v420; // d3
  double v421; // d4
  double v422; // d5
  double v423; // d6
  double v424; // d7
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
  __int64 result; // x0
  _QWORD v458[24]; // [xsp+8h] [xbp-128h] BYREF
  _QWORD v459[11]; // [xsp+C8h] [xbp-68h] BYREF
  __int16 v460; // [xsp+120h] [xbp-10h]
  __int64 v461; // [xsp+128h] [xbp-8h]

  v461 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(unsigned int *)(a1 + 18652);
  v460 = 0;
  memset(v459, 0, sizeof(v459));
  memset(v458, 0, sizeof(v458));
  DP_PRINT_STATS("No of AST Entries = %d", a2, a3, a4, a5, a6, a7, a8, a9, v10);
  DP_PRINT_STATS("SOC Rx Stats:\n", v11, v12, v13, v14, v15, v16, v17, v18);
  DP_PRINT_STATS("Fast recycled packets: %llu", v19, v20, v21, v22, v23, v24, v25, v26, *(_QWORD *)(a1 + 13664));
  DP_PRINT_STATS("Fragmented packets: %u", v27, v28, v29, v30, v31, v32, v33, v34, *(unsigned int *)(a1 + 13604));
  DP_PRINT_STATS("Reo reinjected packets: %u", v35, v36, v37, v38, v39, v40, v41, v42, *(unsigned int *)(a1 + 13628));
  DP_PRINT_STATS("Errors:\n", v43, v44, v45, v46, v47, v48, v49, v50);
  DP_PRINT_STATS(
    "Rx Decrypt Errors = %d",
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    (unsigned int)(*(_DWORD *)(a1 + 13792) + *(_DWORD *)(a1 + 13788)));
  DP_PRINT_STATS("Invalid RBM = %d", v59, v60, v61, v62, v63, v64, v65, v66, *(unsigned int *)(a1 + 13688));
  DP_PRINT_STATS("Invalid Vdev = %d", v67, v68, v69, v70, v71, v72, v73, v74, *(unsigned int *)(a1 + 13692));
  DP_PRINT_STATS("Invalid sa_idx or da_idx = %d", v75, v76, v77, v78, v79, v80, v81, v82, *(unsigned int *)(a1 + 13708));
  DP_PRINT_STATS("Defrag peer uninit = %d", v83, v84, v85, v86, v87, v88, v89, v90, *(unsigned int *)(a1 + 13704));
  DP_PRINT_STATS("Pkts delivered no peer = %d", v91, v92, v93, v94, v95, v96, v97, v98, *(unsigned int *)(a1 + 13700));
  DP_PRINT_STATS("Invalid Pdev = %d", v99, v100, v101, v102, v103, v104, v105, v106, *(unsigned int *)(a1 + 13696));
  DP_PRINT_STATS("Invalid Peer = %llu", v107, v108, v109, v110, v111, v112, v113, v114, *(_QWORD *)(a1 + 13720));
  DP_PRINT_STATS(
    "HAL Ring Access Fail = %d",
    v115,
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    *(unsigned int *)(a1 + 13768));
  DP_PRINT_STATS(
    "HAL Ring Access Full Fail = %d",
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    *(unsigned int *)(a1 + 13772));
  DP_PRINT_STATS(
    "MSDU Done failures = %d",
    v131,
    v132,
    v133,
    v134,
    v135,
    v136,
    v137,
    v138,
    *(unsigned int *)(a1 + 13712));
  DP_PRINT_STATS("RX frags: %d", v139, v140, v141, v142, v143, v144, v145, v146, *(unsigned int *)(a1 + 13604));
  DP_PRINT_STATS("RX frag wait: %d", v147, v148, v149, v150, v151, v152, v153, v154, *(unsigned int *)(a1 + 13608));
  DP_PRINT_STATS("RX frag err: %d", v155, v156, v157, v158, v159, v160, v161, v162, *(unsigned int *)(a1 + 13612));
  DP_PRINT_STATS("RX frag OOR: %d", v163, v164, v165, v166, v167, v168, v169, v170, *(unsigned int *)(a1 + 13616));
  DP_PRINT_STATS("RX HP out_of_sync: %d", v171, v172, v173, v174, v175, v176, v177, v178, *(unsigned int *)(a1 + 13636));
  DP_PRINT_STATS("RX Ring Near Full: %d", v179, v180, v181, v182, v183, v184, v185, v186, *(unsigned int *)(a1 + 13640));
  DP_PRINT_STATS(
    "RX Reap Loop Pkt Limit Hit: %d",
    v187,
    v188,
    v189,
    v190,
    v191,
    v192,
    v193,
    v194,
    *(unsigned int *)(a1 + 13632));
  DP_PRINT_STATS(
    "RX DESC invalid magic: %u",
    v195,
    v196,
    v197,
    v198,
    v199,
    v200,
    v201,
    v202,
    *(unsigned int *)(a1 + 13904));
  DP_PRINT_STATS("RX DUP DESC: %d", v203, v204, v205, v206, v207, v208, v209, v210, *(unsigned int *)(a1 + 14000));
  DP_PRINT_STATS("RX REL DUP DESC: %d", v211, v212, v213, v214, v215, v216, v217, v218, *(unsigned int *)(a1 + 14004));
  DP_PRINT_STATS(
    "RXDMA ERR DUP DESC: %d",
    v219,
    v220,
    v221,
    v222,
    v223,
    v224,
    v225,
    v226,
    *(unsigned int *)(a1 + 14008));
  DP_PRINT_STATS("RX scatter msdu: %d", v227, v228, v229, v230, v231, v232, v233, v234, *(unsigned int *)(a1 + 14044));
  DP_PRINT_STATS("RX invalid cookie: %d", v235, v236, v237, v238, v239, v240, v241, v242, *(unsigned int *)(a1 + 14052));
  DP_PRINT_STATS("RX stale cookie: %d", v243, v244, v245, v246, v247, v248, v249, v250, *(unsigned int *)(a1 + 14056));
  DP_PRINT_STATS(
    "RX wait completed msdu break: %d",
    v251,
    v252,
    v253,
    v254,
    v255,
    v256,
    v257,
    v258,
    *(unsigned int *)(a1 + 13644));
  DP_PRINT_STATS(
    "2k jump delba sent: %d",
    v259,
    v260,
    v261,
    v262,
    v263,
    v264,
    v265,
    v266,
    *(unsigned int *)(a1 + 14060));
  DP_PRINT_STATS(
    "2k jump msdu to stack: %d",
    v267,
    v268,
    v269,
    v270,
    v271,
    v272,
    v273,
    v274,
    *(unsigned int *)(a1 + 14064));
  DP_PRINT_STATS("2k jump msdu drop: %d", v275, v276, v277, v278, v279, v280, v281, v282, *(unsigned int *)(a1 + 14068));
  DP_PRINT_STATS(
    "REO err oor msdu to stack %d",
    v283,
    v284,
    v285,
    v286,
    v287,
    v288,
    v289,
    v290,
    *(unsigned int *)(a1 + 14084));
  DP_PRINT_STATS(
    "REO err oor msdu drop: %d",
    v291,
    v292,
    v293,
    v294,
    v295,
    v296,
    v297,
    v298,
    *(unsigned int *)(a1 + 14080));
  DP_PRINT_STATS(
    "Rx err msdu rejected: %d",
    v299,
    v300,
    v301,
    v302,
    v303,
    v304,
    v305,
    v306,
    *(unsigned int *)(a1 + 14092));
  DP_PRINT_STATS(
    "Rx stale link desc cookie: %d",
    v307,
    v308,
    v309,
    v310,
    v311,
    v312,
    v313,
    v314,
    *(unsigned int *)(a1 + 14104));
  DP_PRINT_STATS(
    "Rx nbuf sanity fail: %d",
    v315,
    v316,
    v317,
    v318,
    v319,
    v320,
    v321,
    v322,
    *(unsigned int *)(a1 + 14108));
  DP_PRINT_STATS(
    "Rx err msdu continuation err: %d",
    v323,
    v324,
    v325,
    v326,
    v327,
    v328,
    v329,
    v330,
    *(unsigned int *)(a1 + 14116));
  DP_PRINT_STATS("ssn update count: %d", v331, v332, v333, v334, v335, v336, v337, v338, *(unsigned int *)(a1 + 14120));
  DP_PRINT_STATS(
    "bar handle update fail count: %d",
    v339,
    v340,
    v341,
    v342,
    v343,
    v344,
    v345,
    v346,
    *(unsigned int *)(a1 + 14124));
  DP_PRINT_STATS(
    "PN-in-Dest error frame pn-check fail: %d",
    v347,
    v348,
    v349,
    v350,
    v351,
    v352,
    v353,
    v354,
    *(unsigned int *)(a1 + 14132));
  v355 = 0;
  v356 = 0;
  do
  {
    if ( v356 > 0xC0u )
LABEL_8:
      __break(0x5512u);
    v357 = snprintf((char *)v458 + v356, 192LL - v356, " %d", *(_DWORD *)(a1 + 13776 + v355));
    v355 += 4;
    v356 += v357;
  }
  while ( v355 != 128 );
  DP_PRINT_STATS("RXDMA Error (0-31):%s", v358, v359, v360, v361, v362, v363, v364, v365, v458);
  v366 = 0;
  v367 = 0;
  do
  {
    if ( v367 > 0x5Au )
      goto LABEL_8;
    v368 = snprintf((char *)v459 + v367, 90LL - v367, " %d", *(_DWORD *)(a1 + 13908 + v366));
    v366 += 4;
    v367 += v368;
  }
  while ( v366 != 60 );
  DP_PRINT_STATS("REO Error(0-14):%s", v369, v370, v371, v372, v373, v374, v375, v376, v459);
  DP_PRINT_STATS("REO CMD SEND FAIL: %d", v377, v378, v379, v380, v381, v382, v383, v384, *(unsigned int *)(a1 + 14036));
  DP_PRINT_STATS("Rx BAR frames:%d", v385, v386, v387, v388, v389, v390, v391, v392, *(unsigned int *)(a1 + 13648));
  DP_PRINT_STATS(
    "Rxdma2rel route drop:%d",
    v393,
    v394,
    v395,
    v396,
    v397,
    v398,
    v399,
    v400,
    *(unsigned int *)(a1 + 13652));
  DP_PRINT_STATS("Reo2rel route drop:%d", v401, v402, v403, v404, v405, v406, v407, v408, *(unsigned int *)(a1 + 13656));
  DP_PRINT_STATS("Rx Flush count:%d", v409, v410, v411, v412, v413, v414, v415, v416, *(unsigned int *)(a1 + 14140));
  DP_PRINT_STATS(
    "RX HW stats request count:%d",
    v417,
    v418,
    v419,
    v420,
    v421,
    v422,
    v423,
    v424,
    *(unsigned int *)(a1 + 13672));
  DP_PRINT_STATS(
    "RX HW stats request timeout:%d",
    v425,
    v426,
    v427,
    v428,
    v429,
    v430,
    v431,
    v432,
    *(unsigned int *)(a1 + 13676));
  DP_PRINT_STATS(
    "Rx invalid TID count:%d",
    v433,
    v434,
    v435,
    v436,
    v437,
    v438,
    v439,
    v440,
    *(unsigned int *)(a1 + 14144));
  DP_PRINT_STATS(
    "Rx Defrag Address1 Invalid:%d",
    v441,
    v442,
    v443,
    v444,
    v445,
    v446,
    v447,
    v448,
    *(unsigned int *)(a1 + 14148));
  result = DP_PRINT_STATS(
             "Rx decrypt error frame for valid peer:%d",
             v449,
             v450,
             v451,
             v452,
             v453,
             v454,
             v455,
             v456,
             *(unsigned int *)(a1 + 14152));
  _ReadStatusReg(SP_EL0);
  return result;
}
