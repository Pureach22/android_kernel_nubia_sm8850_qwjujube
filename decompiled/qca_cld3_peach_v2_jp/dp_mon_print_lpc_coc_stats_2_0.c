__int64 __fastcall dp_mon_print_lpc_coc_stats_2_0(
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
  __int64 v10; // x22
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
  __int64 v91; // x8
  __int64 v92; // x24
  unsigned int *v93; // x23
  unsigned int *v94; // x19
  double v95; // d0
  double v96; // d1
  double v97; // d2
  double v98; // d3
  double v99; // d4
  double v100; // d5
  double v101; // d6
  double v102; // d7
  double v103; // d0
  double v104; // d1
  double v105; // d2
  double v106; // d3
  double v107; // d4
  double v108; // d5
  double v109; // d6
  double v110; // d7
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  double v127; // d0
  double v128; // d1
  double v129; // d2
  double v130; // d3
  double v131; // d4
  double v132; // d5
  double v133; // d6
  double v134; // d7
  double v135; // d0
  double v136; // d1
  double v137; // d2
  double v138; // d3
  double v139; // d4
  double v140; // d5
  double v141; // d6
  double v142; // d7
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  double v159; // d0
  double v160; // d1
  double v161; // d2
  double v162; // d3
  double v163; // d4
  double v164; // d5
  double v165; // d6
  double v166; // d7
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  __int64 result; // x0
  double v184; // d0
  double v185; // d1
  double v186; // d2
  double v187; // d3
  double v188; // d4
  double v189; // d5
  double v190; // d6
  double v191; // d7
  __int64 v192; // x27
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  double v201; // d0
  double v202; // d1
  double v203; // d2
  double v204; // d3
  double v205; // d4
  double v206; // d5
  double v207; // d6
  double v208; // d7
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  double v233; // d0
  double v234; // d1
  double v235; // d2
  double v236; // d3
  double v237; // d4
  double v238; // d5
  double v239; // d6
  double v240; // d7
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  double v249; // d0
  double v250; // d1
  double v251; // d2
  double v252; // d3
  double v253; // d4
  double v254; // d5
  double v255; // d6
  double v256; // d7
  double v257; // d0
  double v258; // d1
  double v259; // d2
  double v260; // d3
  double v261; // d4
  double v262; // d5
  double v263; // d6
  double v264; // d7
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  double v273; // d0
  double v274; // d1
  double v275; // d2
  double v276; // d3
  double v277; // d4
  double v278; // d5
  double v279; // d6
  double v280; // d7
  double v281; // d0
  double v282; // d1
  double v283; // d2
  double v284; // d3
  double v285; // d4
  double v286; // d5
  double v287; // d6
  double v288; // d7
  double v289; // d0
  double v290; // d1
  double v291; // d2
  double v292; // d3
  double v293; // d4
  double v294; // d5
  double v295; // d6
  double v296; // d7
  double v297; // d0
  double v298; // d1
  double v299; // d2
  double v300; // d3
  double v301; // d4
  double v302; // d5
  double v303; // d6
  double v304; // d7
  double v305; // d0
  double v306; // d1
  double v307; // d2
  double v308; // d3
  double v309; // d4
  double v310; // d5
  double v311; // d6
  double v312; // d7
  double v313; // d0
  double v314; // d1
  double v315; // d2
  double v316; // d3
  double v317; // d4
  double v318; // d5
  double v319; // d6
  double v320; // d7
  double v321; // d0
  double v322; // d1
  double v323; // d2
  double v324; // d3
  double v325; // d4
  double v326; // d5
  double v327; // d6
  double v328; // d7
  double v329; // d0
  double v330; // d1
  double v331; // d2
  double v332; // d3
  double v333; // d4
  double v334; // d5
  double v335; // d6
  double v336; // d7
  double v337; // d0
  double v338; // d1
  double v339; // d2
  double v340; // d3
  double v341; // d4
  double v342; // d5
  double v343; // d6
  double v344; // d7
  double v345; // d0
  double v346; // d1
  double v347; // d2
  double v348; // d3
  double v349; // d4
  double v350; // d5
  double v351; // d6
  double v352; // d7
  double v353; // d0
  double v354; // d1
  double v355; // d2
  double v356; // d3
  double v357; // d4
  double v358; // d5
  double v359; // d6
  double v360; // d7
  double v361; // d0
  double v362; // d1
  double v363; // d2
  double v364; // d3
  double v365; // d4
  double v366; // d5
  double v367; // d6
  double v368; // d7
  double v369; // d0
  double v370; // d1
  double v371; // d2
  double v372; // d3
  double v373; // d4
  double v374; // d5
  double v375; // d6
  double v376; // d7
  __int64 v377; // x19
  double v378; // d0
  double v379; // d1
  double v380; // d2
  double v381; // d3
  double v382; // d4
  double v383; // d5
  double v384; // d6
  double v385; // d7
  double v386; // d0
  double v387; // d1
  double v388; // d2
  double v389; // d3
  double v390; // d4
  double v391; // d5
  double v392; // d6
  double v393; // d7
  double v394; // d0
  double v395; // d1
  double v396; // d2
  double v397; // d3
  double v398; // d4
  double v399; // d5
  double v400; // d6
  double v401; // d7
  double v402; // d0
  double v403; // d1
  double v404; // d2
  double v405; // d3
  double v406; // d4
  double v407; // d5
  double v408; // d6
  double v409; // d7
  double v410; // d0
  double v411; // d1
  double v412; // d2
  double v413; // d3
  double v414; // d4
  double v415; // d5
  double v416; // d6
  double v417; // d7
  double v418; // d0
  double v419; // d1
  double v420; // d2
  double v421; // d3
  double v422; // d4
  double v423; // d5
  double v424; // d6
  double v425; // d7
  double v426; // d0
  double v427; // d1
  double v428; // d2
  double v429; // d3
  double v430; // d4
  double v431; // d5
  double v432; // d6
  double v433; // d7
  double v434; // d0
  double v435; // d1
  double v436; // d2
  double v437; // d3
  double v438; // d4
  double v439; // d5
  double v440; // d6
  double v441; // d7
  double v442; // d0
  double v443; // d1
  double v444; // d2
  double v445; // d3
  double v446; // d4
  double v447; // d5
  double v448; // d6
  double v449; // d7
  double v450; // d0
  double v451; // d1
  double v452; // d2
  double v453; // d3
  double v454; // d4
  double v455; // d5
  double v456; // d6
  double v457; // d7
  double v458; // d0
  double v459; // d1
  double v460; // d2
  double v461; // d3
  double v462; // d4
  double v463; // d5
  double v464; // d6
  double v465; // d7
  double v466; // d0
  double v467; // d1
  double v468; // d2
  double v469; // d3
  double v470; // d4
  double v471; // d5
  double v472; // d6
  double v473; // d7
  double v474; // d0
  double v475; // d1
  double v476; // d2
  double v477; // d3
  double v478; // d4
  double v479; // d5
  double v480; // d6
  double v481; // d7
  double v482; // d0
  double v483; // d1
  double v484; // d2
  double v485; // d3
  double v486; // d4
  double v487; // d5
  double v488; // d6
  double v489; // d7
  double v490; // d0
  double v491; // d1
  double v492; // d2
  double v493; // d3
  double v494; // d4
  double v495; // d5
  double v496; // d6
  double v497; // d7
  double v498; // d0
  double v499; // d1
  double v500; // d2
  double v501; // d3
  double v502; // d4
  double v503; // d5
  double v504; // d6
  double v505; // d7
  double v506; // d0
  double v507; // d1
  double v508; // d2
  double v509; // d3
  double v510; // d4
  double v511; // d5
  double v512; // d6
  double v513; // d7
  double v514; // d0
  double v515; // d1
  double v516; // d2
  double v517; // d3
  double v518; // d4
  double v519; // d5
  double v520; // d6
  double v521; // d7
  double v522; // d0
  double v523; // d1
  double v524; // d2
  double v525; // d3
  double v526; // d4
  double v527; // d5
  double v528; // d6
  double v529; // d7
  double v530; // d0
  double v531; // d1
  double v532; // d2
  double v533; // d3
  double v534; // d4
  double v535; // d5
  double v536; // d6
  double v537; // d7
  double v538; // d0
  double v539; // d1
  double v540; // d2
  double v541; // d3
  double v542; // d4
  double v543; // d5
  double v544; // d6
  double v545; // d7
  double v546; // d0
  double v547; // d1
  double v548; // d2
  double v549; // d3
  double v550; // d4
  double v551; // d5
  double v552; // d6
  double v553; // d7
  double v554; // d0
  double v555; // d1
  double v556; // d2
  double v557; // d3
  double v558; // d4
  double v559; // d5
  double v560; // d6
  double v561; // d7
  double v562; // d0
  double v563; // d1
  double v564; // d2
  double v565; // d3
  double v566; // d4
  double v567; // d5
  double v568; // d6
  double v569; // d7

  v10 = *(_QWORD *)(a1 + 95560);
  DP_PRINT_STATS("MAC %u Rx Stats:\n", a2, a3, a4, a5, a6, a7, a8, a9, 0);
  DP_PRINT_STATS("status_ppdu_compl_cnt: %d", v11, v12, v13, v14, v15, v16, v17, v18, *(unsigned int *)(v10 + 72));
  DP_PRINT_STATS("status_ppdu_start_cnt: %d", v19, v20, v21, v22, v23, v24, v25, v26, *(unsigned int *)(v10 + 64));
  DP_PRINT_STATS("status_ppdu_end_cnt: %d", v27, v28, v29, v30, v31, v32, v33, v34, *(unsigned int *)(v10 + 68));
  DP_PRINT_STATS("status_ppdu_start_mis_cnt: %d", v35, v36, v37, v38, v39, v40, v41, v42, *(unsigned int *)(v10 + 76));
  DP_PRINT_STATS("status_ppdu_end_mis_cnt: %d", v43, v44, v45, v46, v47, v48, v49, v50, *(unsigned int *)(v10 + 80));
  DP_PRINT_STATS("status_ppdu_done_cnt: %d", v51, v52, v53, v54, v55, v56, v57, v58, *(unsigned int *)(v10 + 1908));
  DP_PRINT_STATS(
    "status_ppdu_rx_header_tlv_cnt: %d",
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    *(unsigned int *)(v10 + 18512));
  DP_PRINT_STATS(
    "status_ppdu_rx_mpdu_start_tlv_cnt: %d",
    v67,
    v68,
    v69,
    v70,
    v71,
    v72,
    v73,
    v74,
    *(unsigned int *)(v10 + 18516));
  DP_PRINT_STATS("pkt_rx_delivered: %d", v75, v76, v77, v78, v79, v80, v81, v82, *(unsigned int *)(v10 + 18520));
  DP_PRINT_STATS("pkt_rx_dropped: %d", v83, v84, v85, v86, v87, v88, v89, v90, *(unsigned int *)(v10 + 18524));
  v91 = *(_QWORD *)(a1 + 95560);
  v92 = a1;
  v93 = (unsigned int *)(v91 + 37040);
  v94 = (unsigned int *)(v91 + 18592);
  DP_PRINT_STATS("MAC %u Rx Stats:\n", v95, v96, v97, v98, v99, v100, v101, v102, 1);
  DP_PRINT_STATS("status_ppdu_compl_cnt: %d", v103, v104, v105, v106, v107, v108, v109, v110, v94[2]);
  DP_PRINT_STATS("status_ppdu_start_cnt: %d", v111, v112, v113, v114, v115, v116, v117, v118, *v94);
  DP_PRINT_STATS("status_ppdu_end_cnt: %d", v119, v120, v121, v122, v123, v124, v125, v126, v94[1]);
  DP_PRINT_STATS("status_ppdu_start_mis_cnt: %d", v127, v128, v129, v130, v131, v132, v133, v134, v94[3]);
  DP_PRINT_STATS("status_ppdu_end_mis_cnt: %d", v135, v136, v137, v138, v139, v140, v141, v142, v94[4]);
  DP_PRINT_STATS("status_ppdu_done_cnt: %d", v143, v144, v145, v146, v147, v148, v149, v150, v94[461]);
  DP_PRINT_STATS("status_ppdu_rx_header_tlv_cnt: %d", v151, v152, v153, v154, v155, v156, v157, v158, *v93);
  DP_PRINT_STATS("status_ppdu_rx_mpdu_start_tlv_cnt: %d", v159, v160, v161, v162, v163, v164, v165, v166, v93[1]);
  DP_PRINT_STATS("pkt_rx_delivered: %d", v167, v168, v169, v170, v171, v172, v173, v174, v93[2]);
  result = DP_PRINT_STATS("pkt_rx_dropped: %d", v175, v176, v177, v178, v179, v180, v181, v182, v93[3]);
  if ( v10 )
  {
    v192 = *(_QWORD *)(v92 + 95560) + 0x4000LL;
    DP_PRINT_STATS("MAC %u Tx Stats:\n", v184, v185, v186, v187, v188, v189, v190, v191, 0);
    DP_PRINT_STATS("replenish count: %llu", v193, v194, v195, v196, v197, v198, v199, v200, *(_QWORD *)(v10 + 39584));
    DP_PRINT_STATS("reap count: %llu", v201, v202, v203, v204, v205, v206, v207, v208, *(_QWORD *)(v10 + 39592));
    DP_PRINT_STATS("monitor stuck: %u", v209, v210, v211, v212, v213, v214, v215, v216, *(unsigned int *)(v10 + 39604));
    DP_PRINT_STATS("Status buffer", v217, v218, v219, v220, v221, v222, v223, v224);
    DP_PRINT_STATS("received: %llu", v225, v226, v227, v228, v229, v230, v231, v232, *(_QWORD *)(v10 + 39568));
    DP_PRINT_STATS("free: %llu", v233, v234, v235, v236, v237, v238, v239, v240, *(_QWORD *)(v10 + 39576));
    DP_PRINT_STATS("Packet buffer", v241, v242, v243, v244, v245, v246, v247, v248);
    DP_PRINT_STATS("received: %llu", v249, v250, v251, v252, v253, v254, v255, v256, *(_QWORD *)(v10 + 39520));
    DP_PRINT_STATS("free: %llu", v257, v258, v259, v260, v261, v262, v263, v264, *(_QWORD *)(v10 + 39528));
    DP_PRINT_STATS("processed: %llu", v265, v266, v267, v268, v269, v270, v271, v272, *(_QWORD *)(v10 + 39536));
    DP_PRINT_STATS("drop: %llu", v273, v274, v275, v276, v277, v278, v279, v280, *(_QWORD *)(v10 + 39544));
    DP_PRINT_STATS("radiotap err: %llu", v281, v282, v283, v284, v285, v286, v287, v288, *(_QWORD *)(v10 + 39560));
    DP_PRINT_STATS("to stack: %llu", v289, v290, v291, v292, v293, v294, v295, v296, *(_QWORD *)(v10 + 39552));
    DP_PRINT_STATS("ppdu info", v297, v298, v299, v300, v301, v302, v303, v304);
    DP_PRINT_STATS("threshold: %llu", v305, v306, v307, v308, v309, v310, v311, v312, *(_QWORD *)(v10 + 39608));
    DP_PRINT_STATS("flush: %llu", v313, v314, v315, v316, v317, v318, v319, v320, *(_QWORD *)(v10 + 39616));
    DP_PRINT_STATS("truncated: %llu", v321, v322, v323, v324, v325, v326, v327, v328, *(_QWORD *)(v10 + 39624));
    DP_PRINT_STATS("Drop stats", v329, v330, v331, v332, v333, v334, v335, v336);
    DP_PRINT_STATS("ppdu drop: %llu", v337, v338, v339, v340, v341, v342, v343, v344, *(_QWORD *)(v10 + 39496));
    DP_PRINT_STATS("mpdu drop: %llu", v345, v346, v347, v348, v349, v350, v351, v352, *(_QWORD *)(v10 + 39504));
    DP_PRINT_STATS("tlv drop: %llu", v353, v354, v355, v356, v357, v358, v359, v360, *(_QWORD *)(v10 + 39512));
    DP_PRINT_STATS(
      "pkt_tx_delivered: %d",
      v361,
      v362,
      v363,
      v364,
      v365,
      v366,
      v367,
      v368,
      *(unsigned int *)(v192 + 2144));
    DP_PRINT_STATS("pkt_tx_dropped: %d", v369, v370, v371, v372, v373, v374, v375, v376, *(unsigned int *)(v192 + 2148));
    v377 = *(_QWORD *)(v92 + 95560) + 36864LL;
    DP_PRINT_STATS("MAC %u Tx Stats:\n", v378, v379, v380, v381, v382, v383, v384, v385, 1);
    DP_PRINT_STATS("replenish count: %llu", v386, v387, v388, v389, v390, v391, v392, v393, *(_QWORD *)(v10 + 42160));
    DP_PRINT_STATS("reap count: %llu", v394, v395, v396, v397, v398, v399, v400, v401, *(_QWORD *)(v10 + 42168));
    DP_PRINT_STATS("monitor stuck: %u", v402, v403, v404, v405, v406, v407, v408, v409, *(unsigned int *)(v10 + 42180));
    DP_PRINT_STATS("Status buffer", v410, v411, v412, v413, v414, v415, v416, v417);
    DP_PRINT_STATS("received: %llu", v418, v419, v420, v421, v422, v423, v424, v425, *(_QWORD *)(v10 + 42144));
    DP_PRINT_STATS("free: %llu", v426, v427, v428, v429, v430, v431, v432, v433, *(_QWORD *)(v10 + 42152));
    DP_PRINT_STATS("Packet buffer", v434, v435, v436, v437, v438, v439, v440, v441);
    DP_PRINT_STATS("received: %llu", v442, v443, v444, v445, v446, v447, v448, v449, *(_QWORD *)(v10 + 42096));
    DP_PRINT_STATS("free: %llu", v450, v451, v452, v453, v454, v455, v456, v457, *(_QWORD *)(v10 + 42104));
    DP_PRINT_STATS("processed: %llu", v458, v459, v460, v461, v462, v463, v464, v465, *(_QWORD *)(v10 + 42112));
    DP_PRINT_STATS("drop: %llu", v466, v467, v468, v469, v470, v471, v472, v473, *(_QWORD *)(v10 + 42120));
    DP_PRINT_STATS("radiotap err: %llu", v474, v475, v476, v477, v478, v479, v480, v481, *(_QWORD *)(v10 + 42136));
    DP_PRINT_STATS("to stack: %llu", v482, v483, v484, v485, v486, v487, v488, v489, *(_QWORD *)(v10 + 42128));
    DP_PRINT_STATS("ppdu info", v490, v491, v492, v493, v494, v495, v496, v497);
    DP_PRINT_STATS("threshold: %llu", v498, v499, v500, v501, v502, v503, v504, v505, *(_QWORD *)(v10 + 42184));
    DP_PRINT_STATS("flush: %llu", v506, v507, v508, v509, v510, v511, v512, v513, *(_QWORD *)(v10 + 42192));
    DP_PRINT_STATS("truncated: %llu", v514, v515, v516, v517, v518, v519, v520, v521, *(_QWORD *)(v10 + 42200));
    DP_PRINT_STATS("Drop stats", v522, v523, v524, v525, v526, v527, v528, v529);
    DP_PRINT_STATS("ppdu drop: %llu", v530, v531, v532, v533, v534, v535, v536, v537, *(_QWORD *)(v10 + 42072));
    DP_PRINT_STATS("mpdu drop: %llu", v538, v539, v540, v541, v542, v543, v544, v545, *(_QWORD *)(v10 + 42080));
    DP_PRINT_STATS("tlv drop: %llu", v546, v547, v548, v549, v550, v551, v552, v553, *(_QWORD *)(v10 + 42088));
    DP_PRINT_STATS(
      "pkt_tx_delivered: %d",
      v554,
      v555,
      v556,
      v557,
      v558,
      v559,
      v560,
      v561,
      *(unsigned int *)(v377 + 192));
    return DP_PRINT_STATS(
             "pkt_tx_dropped: %d",
             v562,
             v563,
             v564,
             v565,
             v566,
             v567,
             v568,
             v569,
             *(unsigned int *)(v377 + 196));
  }
  return result;
}
