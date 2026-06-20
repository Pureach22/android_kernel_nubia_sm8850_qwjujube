__int64 __fastcall dp_print_tx_sounding_stats_tlv(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  int v9; // w8
  unsigned int *v10; // x19
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
  double v355; // d0
  double v356; // d1
  double v357; // d2
  double v358; // d3
  double v359; // d4
  double v360; // d5
  double v361; // d6
  double v362; // d7
  double v363; // d0
  double v364; // d1
  double v365; // d2
  double v366; // d3
  double v367; // d4
  double v368; // d5
  double v369; // d6
  double v370; // d7
  double v371; // d0
  double v372; // d1
  double v373; // d2
  double v374; // d3
  double v375; // d4
  double v376; // d5
  double v377; // d6
  double v378; // d7
  double v379; // d0
  double v380; // d1
  double v381; // d2
  double v382; // d3
  double v383; // d4
  double v384; // d5
  double v385; // d6
  double v386; // d7
  double v387; // d0
  double v388; // d1
  double v389; // d2
  double v390; // d3
  double v391; // d4
  double v392; // d5
  double v393; // d6
  double v394; // d7
  double v395; // d0
  double v396; // d1
  double v397; // d2
  double v398; // d3
  double v399; // d4
  double v400; // d5
  double v401; // d6
  double v402; // d7
  double v403; // d0
  double v404; // d1
  double v405; // d2
  double v406; // d3
  double v407; // d4
  double v408; // d5
  double v409; // d6
  double v410; // d7
  double v411; // d0
  double v412; // d1
  double v413; // d2
  double v414; // d3
  double v415; // d4
  double v416; // d5
  double v417; // d6
  double v418; // d7
  double v419; // d0
  double v420; // d1
  double v421; // d2
  double v422; // d3
  double v423; // d4
  double v424; // d5
  double v425; // d6
  double v426; // d7
  double v427; // d0
  double v428; // d1
  double v429; // d2
  double v430; // d3
  double v431; // d4
  double v432; // d5
  double v433; // d6
  double v434; // d7
  double v435; // d0
  double v436; // d1
  double v437; // d2
  double v438; // d3
  double v439; // d4
  double v440; // d5
  double v441; // d6
  double v442; // d7
  double v443; // d0
  double v444; // d1
  double v445; // d2
  double v446; // d3
  double v447; // d4
  double v448; // d5
  double v449; // d6
  double v450; // d7
  double v451; // d0
  double v452; // d1
  double v453; // d2
  double v454; // d3
  double v455; // d4
  double v456; // d5
  double v457; // d6
  double v458; // d7
  double v459; // d0
  double v460; // d1
  double v461; // d2
  double v462; // d3
  double v463; // d4
  double v464; // d5
  double v465; // d6
  double v466; // d7
  double v467; // d0
  double v468; // d1
  double v469; // d2
  double v470; // d3
  double v471; // d4
  double v472; // d5
  double v473; // d6
  double v474; // d7
  double v475; // d0
  double v476; // d1
  double v477; // d2
  double v478; // d3
  double v479; // d4
  double v480; // d5
  double v481; // d6
  double v482; // d7
  double v483; // d0
  double v484; // d1
  double v485; // d2
  double v486; // d3
  double v487; // d4
  double v488; // d5
  double v489; // d6
  double v490; // d7
  double v491; // d0
  double v492; // d1
  double v493; // d2
  double v494; // d3
  double v495; // d4
  double v496; // d5
  double v497; // d6
  double v498; // d7
  double v499; // d0
  double v500; // d1
  double v501; // d2
  double v502; // d3
  double v503; // d4
  double v504; // d5
  double v505; // d6
  double v506; // d7
  double v507; // d0
  double v508; // d1
  double v509; // d2
  double v510; // d3
  double v511; // d4
  double v512; // d5
  double v513; // d6
  double v514; // d7

  v9 = *(_DWORD *)(result + 4);
  v10 = (unsigned int *)result;
  if ( v9 > 1 )
  {
    if ( v9 == 2 )
    {
      DP_PRINT_STATS("\n HTT_TX_BE_SOUNDING_STATS_TLV: ", a2, a3, a4, a5, a6, a7, a8, a9);
      DP_PRINT_STATS(
        "be_cbf_20 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
        v411,
        v412,
        v413,
        v414,
        v415,
        v416,
        v417,
        v418,
        v10[2],
        v10[3],
        v10[4],
        v10[5],
        v10[6]);
      DP_PRINT_STATS(
        "be_cbf_40 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
        v419,
        v420,
        v421,
        v422,
        v423,
        v424,
        v425,
        v426,
        v10[7],
        v10[8],
        v10[9],
        v10[10],
        v10[11]);
      DP_PRINT_STATS(
        "be_cbf_80 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
        v427,
        v428,
        v429,
        v430,
        v431,
        v432,
        v433,
        v434,
        v10[12],
        v10[13],
        v10[14],
        v10[15],
        v10[16]);
      DP_PRINT_STATS(
        "be_cbf_160 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
        v435,
        v436,
        v437,
        v438,
        v439,
        v440,
        v441,
        v442,
        v10[17],
        v10[18],
        v10[19],
        v10[20],
        v10[21]);
      DP_PRINT_STATS(
        "be_cbf_320 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
        v443,
        v444,
        v445,
        v446,
        v447,
        v448,
        v449,
        v450,
        v10[87],
        v10[88],
        v10[89],
        v10[90],
        v10[91]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d, 320MHz: %d",
        v451,
        v452,
        v453,
        v454,
        v455,
        v456,
        v457,
        v458,
        0,
        v10[22],
        v10[23],
        v10[24],
        v10[25],
        v10[79]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d, 320MHz: %d",
        v459,
        v460,
        v461,
        v462,
        v463,
        v464,
        v465,
        v466,
        1,
        v10[26],
        v10[27],
        v10[28],
        v10[29],
        v10[80]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d, 320MHz: %d",
        v467,
        v468,
        v469,
        v470,
        v471,
        v472,
        v473,
        v474,
        2,
        v10[30],
        v10[31],
        v10[32],
        v10[33],
        v10[81]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d, 320MHz: %d",
        v475,
        v476,
        v477,
        v478,
        v479,
        v480,
        v481,
        v482,
        3,
        v10[34],
        v10[35],
        v10[36],
        v10[37],
        v10[82]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d, 320MHz: %d",
        v483,
        v484,
        v485,
        v486,
        v487,
        v488,
        v489,
        v490,
        4,
        v10[38],
        v10[39],
        v10[40],
        v10[41],
        v10[83]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d, 320MHz: %d",
        v491,
        v492,
        v493,
        v494,
        v495,
        v496,
        v497,
        v498,
        5,
        v10[42],
        v10[43],
        v10[44],
        v10[45],
        v10[84]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d, 320MHz: %d",
        v499,
        v500,
        v501,
        v502,
        v503,
        v504,
        v505,
        v506,
        6,
        v10[46],
        v10[47],
        v10[48],
        v10[49],
        v10[85]);
      return DP_PRINT_STATS(
               "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d, 320MHz: %d",
               v507,
               v508,
               v509,
               v510,
               v511,
               v512,
               v513,
               v514,
               7,
               v10[50],
               v10[51],
               v10[52],
               v10[53],
               v10[86]);
    }
    else if ( v9 == 3 )
    {
      DP_PRINT_STATS("\n CV UPLOAD HANDLER STATS:", a2, a3, a4, a5, a6, a7, a8, a9);
      DP_PRINT_STATS("cv_nc_mismatch_err         : %u", v107, v108, v109, v110, v111, v112, v113, v114, v10[54]);
      DP_PRINT_STATS("cv_fcs_err                 : %u", v115, v116, v117, v118, v119, v120, v121, v122, v10[55]);
      DP_PRINT_STATS("cv_frag_idx_mismatch       : %u", v123, v124, v125, v126, v127, v128, v129, v130, v10[56]);
      DP_PRINT_STATS("cv_invalid_peer_id         : %u", v131, v132, v133, v134, v135, v136, v137, v138, v10[57]);
      DP_PRINT_STATS("cv_no_txbf_setup           : %u", v139, v140, v141, v142, v143, v144, v145, v146, v10[58]);
      DP_PRINT_STATS("cv_expiry_in_update        : %u", v147, v148, v149, v150, v151, v152, v153, v154, v10[59]);
      DP_PRINT_STATS("cv_pkt_bw_exceed           : %u", v155, v156, v157, v158, v159, v160, v161, v162, v10[60]);
      DP_PRINT_STATS("cv_dma_not_done_err        : %u", v163, v164, v165, v166, v167, v168, v169, v170, v10[61]);
      DP_PRINT_STATS("cv_update_failed           : %u\n", v171, v172, v173, v174, v175, v176, v177, v178, v10[62]);
      DP_PRINT_STATS("\n CV QUERY STATS:", v179, v180, v181, v182, v183, v184, v185, v186);
      DP_PRINT_STATS("cv_total_query             : %u", v187, v188, v189, v190, v191, v192, v193, v194, v10[63]);
      DP_PRINT_STATS("cv_total_pattern_query     : %u", v195, v196, v197, v198, v199, v200, v201, v202, v10[64]);
      DP_PRINT_STATS("cv_total_bw_query          : %u", v203, v204, v205, v206, v207, v208, v209, v210, v10[65]);
      DP_PRINT_STATS("cv_total_query             : %u", v211, v212, v213, v214, v215, v216, v217, v218, v10[63]);
      DP_PRINT_STATS("cv_invalid_bw_coding       : %u", v219, v220, v221, v222, v223, v224, v225, v226, v10[66]);
      DP_PRINT_STATS("cv_forced_sounding         : %u", v227, v228, v229, v230, v231, v232, v233, v234, v10[67]);
      DP_PRINT_STATS("cv_standalone_sounding     : %u", v235, v236, v237, v238, v239, v240, v241, v242, v10[68]);
      DP_PRINT_STATS("cv_nc_mismatch             : %u", v243, v244, v245, v246, v247, v248, v249, v250, v10[69]);
      DP_PRINT_STATS("cv_fb_type_mismatch        : %u", v251, v252, v253, v254, v255, v256, v257, v258, v10[70]);
      DP_PRINT_STATS("cv_ofdma_bw_mismatch       : %u", v259, v260, v261, v262, v263, v264, v265, v266, v10[71]);
      DP_PRINT_STATS("cv_bw_mismatch             : %u", v267, v268, v269, v270, v271, v272, v273, v274, v10[72]);
      DP_PRINT_STATS("cv_pattern_mismatch        : %u", v275, v276, v277, v278, v279, v280, v281, v282, v10[73]);
      DP_PRINT_STATS("cv_preamble_mismatch       : %u", v283, v284, v285, v286, v287, v288, v289, v290, v10[74]);
      DP_PRINT_STATS("cv_nr_mismatch             : %u", v291, v292, v293, v294, v295, v296, v297, v298, v10[75]);
      DP_PRINT_STATS("cv_in_use_cnt_exceeded     : %u", v299, v300, v301, v302, v303, v304, v305, v306, v10[76]);
      DP_PRINT_STATS("cv_found                   : %u", v307, v308, v309, v310, v311, v312, v313, v314, v10[77]);
      DP_PRINT_STATS("cv_not found               : %u", v315, v316, v317, v318, v319, v320, v321, v322, v10[78]);
      DP_PRINT_STATS("cv_ntbr_sounding           : %u", v323, v324, v325, v326, v327, v328, v329, v330, v10[92]);
      DP_PRINT_STATS("cv_found_upload_in_progress: %u", v331, v332, v333, v334, v335, v336, v337, v338, v10[93]);
      return DP_PRINT_STATS(
               "cv_expired_during_query    : %u\n",
               v339,
               v340,
               v341,
               v342,
               v343,
               v344,
               v345,
               v346,
               v10[94]);
    }
  }
  else if ( v9 )
  {
    if ( v9 == 1 )
    {
      DP_PRINT_STATS("\n HTT_TX_AX_SOUNDING_STATS_TLV: ", a2, a3, a4, a5, a6, a7, a8, a9);
      DP_PRINT_STATS(
        "ax_cbf_20 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v10[2],
        v10[3],
        v10[4],
        v10[5],
        v10[6]);
      DP_PRINT_STATS(
        "ax_cbf_40 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v10[7],
        v10[8],
        v10[9],
        v10[10],
        v10[11]);
      DP_PRINT_STATS(
        "ax_cbf_80 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v10[12],
        v10[13],
        v10[14],
        v10[15],
        v10[16]);
      DP_PRINT_STATS(
        "ax_cbf_160 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
        v35,
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v10[17],
        v10[18],
        v10[19],
        v10[20],
        v10[21]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49,
        v50,
        0,
        v10[22],
        v10[23],
        v10[24],
        v10[25]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        1,
        v10[26],
        v10[27],
        v10[28],
        v10[29]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        2,
        v10[30],
        v10[31],
        v10[32],
        v10[33]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
        v67,
        v68,
        v69,
        v70,
        v71,
        v72,
        v73,
        v74,
        3,
        v10[34],
        v10[35],
        v10[36],
        v10[37]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
        v75,
        v76,
        v77,
        v78,
        v79,
        v80,
        v81,
        v82,
        4,
        v10[38],
        v10[39],
        v10[40],
        v10[41]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        v90,
        5,
        v10[42],
        v10[43],
        v10[44],
        v10[45]);
      DP_PRINT_STATS(
        "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        v98,
        6,
        v10[46],
        v10[47],
        v10[48],
        v10[49]);
      return DP_PRINT_STATS(
               "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
               v99,
               v100,
               v101,
               v102,
               v103,
               v104,
               v105,
               v106,
               7,
               v10[50],
               v10[51],
               v10[52],
               v10[53]);
    }
  }
  else
  {
    DP_PRINT_STATS("\n HTT_TX_AC_SOUNDING_STATS_TLV: ", a2, a3, a4, a5, a6, a7, a8, a9);
    DP_PRINT_STATS(
      "ac_cbf_20 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
      v347,
      v348,
      v349,
      v350,
      v351,
      v352,
      v353,
      v354,
      v10[2],
      v10[3],
      v10[4],
      v10[5],
      v10[6]);
    DP_PRINT_STATS(
      "ac_cbf_40 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
      v355,
      v356,
      v357,
      v358,
      v359,
      v360,
      v361,
      v362,
      v10[7],
      v10[8],
      v10[9],
      v10[10],
      v10[11]);
    DP_PRINT_STATS(
      "ac_cbf_80 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
      v363,
      v364,
      v365,
      v366,
      v367,
      v368,
      v369,
      v370,
      v10[12],
      v10[13],
      v10[14],
      v10[15],
      v10[16]);
    DP_PRINT_STATS(
      "ac_cbf_160 =  IBF : %d, SU_SIFS : %d, SU_RBO : %d, MU_SIFS : %d, MU_RBO : %d:",
      v371,
      v372,
      v373,
      v374,
      v375,
      v376,
      v377,
      v378,
      v10[17],
      v10[18],
      v10[19],
      v10[20],
      v10[21]);
    DP_PRINT_STATS(
      "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
      v379,
      v380,
      v381,
      v382,
      v383,
      v384,
      v385,
      v386,
      0,
      v10[22],
      v10[23],
      v10[24],
      v10[25]);
    DP_PRINT_STATS(
      "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
      v387,
      v388,
      v389,
      v390,
      v391,
      v392,
      v393,
      v394,
      1,
      v10[26],
      v10[27],
      v10[28],
      v10[29]);
    DP_PRINT_STATS(
      "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
      v395,
      v396,
      v397,
      v398,
      v399,
      v400,
      v401,
      v402,
      2,
      v10[30],
      v10[31],
      v10[32],
      v10[33]);
    return DP_PRINT_STATS(
             "Sounding User %d = 20MHz: %d, 40MHz : %d, 80MHz: %d, 160MHz: %d",
             v403,
             v404,
             v405,
             v406,
             v407,
             v408,
             v409,
             v410,
             3,
             v10[34],
             v10[35],
             v10[36],
             v10[37]);
  }
  return result;
}
