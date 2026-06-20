__int64 __fastcall dp_mon_filter_show_rx_filter_be(
        unsigned int a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  double v173; // d0
  double v174; // d1
  double v175; // d2
  double v176; // d3
  double v177; // d4
  double v178; // d5
  double v179; // d6
  double v180; // d7
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  double v237; // d0
  double v238; // d1
  double v239; // d2
  double v240; // d3
  double v241; // d4
  double v242; // d5
  double v243; // d6
  double v244; // d7
  double v245; // d0
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  double v261; // d0
  double v262; // d1
  double v263; // d2
  double v264; // d3
  double v265; // d4
  double v266; // d5
  double v267; // d6
  double v268; // d7
  double v269; // d0
  double v270; // d1
  double v271; // d2
  double v272; // d3
  double v273; // d4
  double v274; // d5
  double v275; // d6
  double v276; // d7
  double v277; // d0
  double v278; // d1
  double v279; // d2
  double v280; // d3
  double v281; // d4
  double v282; // d5
  double v283; // d6
  double v284; // d7
  double v285; // d0
  double v286; // d1
  double v287; // d2
  double v288; // d3
  double v289; // d4
  double v290; // d5
  double v291; // d6
  double v292; // d7
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
  double v317; // d0
  double v318; // d1
  double v319; // d2
  double v320; // d3
  double v321; // d4
  double v322; // d5
  double v323; // d6
  double v324; // d7
  double v325; // d0
  double v326; // d1
  double v327; // d2
  double v328; // d3
  double v329; // d4
  double v330; // d5
  double v331; // d6
  double v332; // d7
  double v333; // d0
  double v334; // d1
  double v335; // d2
  double v336; // d3
  double v337; // d4
  double v338; // d5
  double v339; // d6
  double v340; // d7
  double v341; // d0
  double v342; // d1
  double v343; // d2
  double v344; // d3
  double v345; // d4
  double v346; // d5
  double v347; // d6
  double v348; // d7
  double v349; // d0
  double v350; // d1
  double v351; // d2
  double v352; // d3
  double v353; // d4
  double v354; // d5
  double v355; // d6
  double v356; // d7
  double v357; // d0
  double v358; // d1
  double v359; // d2
  double v360; // d3
  double v361; // d4
  double v362; // d5
  double v363; // d6
  double v364; // d7
  double v365; // d0
  double v366; // d1
  double v367; // d2
  double v368; // d3
  double v369; // d4
  double v370; // d5
  double v371; // d6
  double v372; // d7
  double v373; // d0
  double v374; // d1
  double v375; // d2
  double v376; // d3
  double v377; // d4
  double v378; // d5
  double v379; // d6
  double v380; // d7
  double v381; // d0
  double v382; // d1
  double v383; // d2
  double v384; // d3
  double v385; // d4
  double v386; // d5
  double v387; // d6
  double v388; // d7
  double v389; // d0
  double v390; // d1
  double v391; // d2
  double v392; // d3
  double v393; // d4
  double v394; // d5
  double v395; // d6
  double v396; // d7
  double v397; // d0
  double v398; // d1
  double v399; // d2
  double v400; // d3
  double v401; // d4
  double v402; // d5
  double v403; // d6
  double v404; // d7
  double v405; // d0
  double v406; // d1
  double v407; // d2
  double v408; // d3
  double v409; // d4
  double v410; // d5
  double v411; // d6
  double v412; // d7
  double v413; // d0
  double v414; // d1
  double v415; // d2
  double v416; // d3
  double v417; // d4
  double v418; // d5
  double v419; // d6
  double v420; // d7
  double v421; // d0
  double v422; // d1
  double v423; // d2
  double v424; // d3
  double v425; // d4
  double v426; // d5
  double v427; // d6
  double v428; // d7
  double v429; // d0
  double v430; // d1
  double v431; // d2
  double v432; // d3
  double v433; // d4
  double v434; // d5
  double v435; // d6
  double v436; // d7
  double v437; // d0
  double v438; // d1
  double v439; // d2
  double v440; // d3
  double v441; // d4
  double v442; // d5
  double v443; // d6
  double v444; // d7
  double v445; // d0
  double v446; // d1
  double v447; // d2
  double v448; // d3
  double v449; // d4
  double v450; // d5
  double v451; // d6
  double v452; // d7
  double v453; // d0
  double v454; // d1
  double v455; // d2
  double v456; // d3
  double v457; // d4
  double v458; // d5
  double v459; // d6
  double v460; // d7
  double v461; // d0
  double v462; // d1
  double v463; // d2
  double v464; // d3
  double v465; // d4
  double v466; // d5
  double v467; // d6
  double v468; // d7
  double v469; // d0
  double v470; // d1
  double v471; // d2
  double v472; // d3
  double v473; // d4
  double v474; // d5
  double v475; // d6
  double v476; // d7
  double v477; // d0
  double v478; // d1
  double v479; // d2
  double v480; // d3
  double v481; // d4
  double v482; // d5
  double v483; // d6
  double v484; // d7
  double v485; // d0
  double v486; // d1
  double v487; // d2
  double v488; // d3
  double v489; // d4
  double v490; // d5
  double v491; // d6
  double v492; // d7

  qdf_trace_msg(0x73u, 8u, "RX MON RING TLV FILTER CONFIG:", a3, a4, a5, a6, a7, a8, a9, a10);
  result = qdf_trace_msg(0x73u, 8u, "[Mode %d]: Valid: %d", v12, v13, v14, v15, v16, v17, v18, v19, a1, *a2);
  if ( *a2 == 1 )
  {
    qdf_trace_msg(0x73u, 8u, "Enable: %d", v21, v22, v23, v24, v25, v26, v27, v28, (*(_DWORD *)(a2 + 78) >> 15) & 1);
    qdf_trace_msg(0x73u, 8u, "mpdu_start: %d", v29, v30, v31, v32, v33, v34, v35, v36, *((_DWORD *)a2 + 1) & 1);
    qdf_trace_msg(0x73u, 8u, "msdu_start: %d", v37, v38, v39, v40, v41, v42, v43, v44, (*((_DWORD *)a2 + 1) >> 1) & 1);
    qdf_trace_msg(0x73u, 8u, "packet: %d", v45, v46, v47, v48, v49, v50, v51, v52, (*((_DWORD *)a2 + 1) >> 2) & 1);
    qdf_trace_msg(0x73u, 8u, "msdu_end: %d", v53, v54, v55, v56, v57, v58, v59, v60, (*((_DWORD *)a2 + 1) >> 3) & 1);
    qdf_trace_msg(0x73u, 8u, "mpdu_end: %d", v61, v62, v63, v64, v65, v66, v67, v68, (*((_DWORD *)a2 + 1) >> 4) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "packet_header: %d",
      v69,
      v70,
      v71,
      v72,
      v73,
      v74,
      v75,
      v76,
      (*((_DWORD *)a2 + 1) >> 5) & 1);
    qdf_trace_msg(0x73u, 8u, "attention: %d", v77, v78, v79, v80, v81, v82, v83, v84, (*((_DWORD *)a2 + 1) >> 6) & 1);
    qdf_trace_msg(0x73u, 8u, "ppdu_start: %d", v85, v86, v87, v88, v89, v90, v91, v92, (*((_DWORD *)a2 + 1) >> 7) & 1);
    qdf_trace_msg(0x73u, 8u, "ppdu_end: %d", v93, v94, v95, v96, v97, v98, v99, v100, (*((_DWORD *)a2 + 1) >> 8) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "ppdu_end_user_stats: %d",
      v101,
      v102,
      v103,
      v104,
      v105,
      v106,
      v107,
      v108,
      (*((_DWORD *)a2 + 1) >> 9) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "ppdu_end_user_stats_ext: %d",
      v109,
      v110,
      v111,
      v112,
      v113,
      v114,
      v115,
      v116,
      (*((_DWORD *)a2 + 1) >> 10) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "ppdu_end_status_done: %d",
      v117,
      v118,
      v119,
      v120,
      v121,
      v122,
      v123,
      v124,
      (*((_DWORD *)a2 + 1) >> 11) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "ppdu_start_user_info: %d",
      v125,
      v126,
      v127,
      v128,
      v129,
      v130,
      v131,
      v132,
      (*((_DWORD *)a2 + 1) >> 12) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "header_per_msdu: %d",
      v133,
      v134,
      v135,
      v136,
      v137,
      v138,
      v139,
      v140,
      (*((_DWORD *)a2 + 1) >> 13) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "enable_fp: %d",
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      v147,
      v148,
      (*((_DWORD *)a2 + 1) >> 14) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "enable_md: %d",
      v149,
      v150,
      v151,
      v152,
      v153,
      v154,
      v155,
      v156,
      (*((_DWORD *)a2 + 1) >> 15) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "enable_mo: %d",
      v157,
      v158,
      v159,
      v160,
      v161,
      v162,
      v163,
      v164,
      HIWORD(*((_DWORD *)a2 + 1)) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "enable_fpmo: %d",
      v165,
      v166,
      v167,
      v168,
      v169,
      v170,
      v171,
      v172,
      HIWORD(*(_DWORD *)(a2 + 78)) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "fp_mgmt_filter: 0x%x",
      v173,
      v174,
      v175,
      v176,
      v177,
      v178,
      v179,
      v180,
      *((unsigned __int16 *)a2 + 4));
    qdf_trace_msg(
      0x73u,
      8u,
      "mo_mgmt_filter: 0x%x",
      v181,
      v182,
      v183,
      v184,
      v185,
      v186,
      v187,
      v188,
      *((unsigned __int16 *)a2 + 5));
    qdf_trace_msg(
      0x73u,
      8u,
      "fp_ctrl_filter: 0x%x",
      v189,
      v190,
      v191,
      v192,
      v193,
      v194,
      v195,
      v196,
      *((unsigned __int16 *)a2 + 6));
    qdf_trace_msg(
      0x73u,
      8u,
      "mo_ctrl_filter: 0x%x",
      v197,
      v198,
      v199,
      v200,
      v201,
      v202,
      v203,
      v204,
      *((unsigned __int16 *)a2 + 7));
    qdf_trace_msg(
      0x73u,
      8u,
      "fp_data_filter: 0x%x",
      v205,
      v206,
      v207,
      v208,
      v209,
      v210,
      v211,
      v212,
      *((unsigned __int16 *)a2 + 8));
    qdf_trace_msg(
      0x73u,
      8u,
      "mo_data_filter: 0x%x",
      v213,
      v214,
      v215,
      v216,
      v217,
      v218,
      v219,
      v220,
      *((unsigned __int16 *)a2 + 9));
    qdf_trace_msg(
      0x73u,
      8u,
      "md_data_filter: 0x%x",
      v221,
      v222,
      v223,
      v224,
      v225,
      v226,
      v227,
      v228,
      *((unsigned __int16 *)a2 + 10));
    qdf_trace_msg(
      0x73u,
      8u,
      "md_mgmt_filter: 0x%x",
      v229,
      v230,
      v231,
      v232,
      v233,
      v234,
      v235,
      v236,
      *((unsigned __int16 *)a2 + 11));
    qdf_trace_msg(
      0x73u,
      8u,
      "md_ctrl_filter: 0x%x",
      v237,
      v238,
      v239,
      v240,
      v241,
      v242,
      v243,
      v244,
      *((unsigned __int16 *)a2 + 12));
    qdf_trace_msg(
      0x73u,
      8u,
      "fpmo_data_filter: 0x%x",
      v245,
      v246,
      v247,
      v248,
      v249,
      v250,
      v251,
      v252,
      *((unsigned __int16 *)a2 + 41));
    qdf_trace_msg(
      0x73u,
      8u,
      "fpmo_mgmt_filter: 0x%x",
      v253,
      v254,
      v255,
      v256,
      v257,
      v258,
      v259,
      v260,
      *((unsigned __int16 *)a2 + 42));
    qdf_trace_msg(
      0x73u,
      8u,
      "fpmo_ctrl_filter: 0x%x",
      v261,
      v262,
      v263,
      v264,
      v265,
      v266,
      v267,
      v268,
      *((unsigned __int16 *)a2 + 43));
    qdf_trace_msg(
      0x73u,
      8u,
      "mgmt_dma_length: %d",
      v269,
      v270,
      v271,
      v272,
      v273,
      v274,
      v275,
      v276,
      *(_DWORD *)(a2 + 78) & 7);
    qdf_trace_msg(
      0x73u,
      8u,
      "ctrl_dma_length: %d",
      v277,
      v278,
      v279,
      v280,
      v281,
      v282,
      v283,
      v284,
      (*(_DWORD *)(a2 + 78) >> 3) & 7);
    qdf_trace_msg(
      0x73u,
      8u,
      "data_dma_length: %d",
      v285,
      v286,
      v287,
      v288,
      v289,
      v290,
      v291,
      v292,
      (*(_DWORD *)(a2 + 78) >> 6) & 7);
    qdf_trace_msg(
      0x73u,
      8u,
      "rx_mpdu_start_wmask: 0x%x",
      v293,
      v294,
      v295,
      v296,
      v297,
      v298,
      v299,
      v300,
      *((unsigned int *)a2 + 16));
    qdf_trace_msg(
      0x73u,
      8u,
      "rx_msdu_end_wmask: 0x%x",
      v301,
      v302,
      v303,
      v304,
      v305,
      v306,
      v307,
      v308,
      *((unsigned int *)a2 + 18));
    qdf_trace_msg(
      0x73u,
      8u,
      "rx_hdr_length: %d",
      v309,
      v310,
      v311,
      v312,
      v313,
      v314,
      v315,
      v316,
      (*(_DWORD *)(a2 + 78) >> 9) & 7);
    qdf_trace_msg(
      0x73u,
      8u,
      "mgmt_mpdu_log: 0x%x",
      v317,
      v318,
      v319,
      v320,
      v321,
      v322,
      v323,
      v324,
      (*(_DWORD *)(a2 + 78) >> 12) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "data_mpdu_log: 0x%x",
      v325,
      v326,
      v327,
      v328,
      v329,
      v330,
      v331,
      v332,
      (*(_DWORD *)(a2 + 78) >> 14) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "ctrl_mpdu_log: 0x%x",
      v333,
      v334,
      v335,
      v336,
      v337,
      v338,
      v339,
      v340,
      (*(_DWORD *)(a2 + 78) >> 13) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "mgmt_dma_length: 0x%x",
      v341,
      v342,
      v343,
      v344,
      v345,
      v346,
      v347,
      v348,
      *(_DWORD *)(a2 + 78) & 7);
    qdf_trace_msg(
      0x73u,
      8u,
      "data_dma_length: 0x%x",
      v349,
      v350,
      v351,
      v352,
      v353,
      v354,
      v355,
      v356,
      (*(_DWORD *)(a2 + 78) >> 6) & 7);
    qdf_trace_msg(
      0x73u,
      8u,
      "ctrl_dma_length: 0x%x",
      v357,
      v358,
      v359,
      v360,
      v361,
      v362,
      v363,
      v364,
      (*(_DWORD *)(a2 + 78) >> 3) & 7);
    qdf_trace_msg(
      0x73u,
      8u,
      "enable_fp_packet: %d",
      v365,
      v366,
      v367,
      v368,
      v369,
      v370,
      v371,
      v372,
      (*((_DWORD *)a2 + 1) >> 17) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "enable_md_packet: %d",
      v373,
      v374,
      v375,
      v376,
      v377,
      v378,
      v379,
      v380,
      (*((_DWORD *)a2 + 1) >> 18) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "enable_mo_packet: %d",
      v381,
      v382,
      v383,
      v384,
      v385,
      v386,
      v387,
      v388,
      (*((_DWORD *)a2 + 1) >> 19) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "enable_fpmo_packet: %d",
      v389,
      v390,
      v391,
      v392,
      v393,
      v394,
      v395,
      v396,
      (*((_DWORD *)a2 + 1) >> 20) & 1);
    qdf_trace_msg(
      0x73u,
      8u,
      "fp_packet_mgmt_filter: 0x%x",
      v397,
      v398,
      v399,
      v400,
      v401,
      v402,
      v403,
      v404,
      *((unsigned __int16 *)a2 + 13));
    qdf_trace_msg(
      0x73u,
      8u,
      "mo_packet_mgmt_filter: 0x%x",
      v405,
      v406,
      v407,
      v408,
      v409,
      v410,
      v411,
      v412,
      *((unsigned __int16 *)a2 + 14));
    qdf_trace_msg(
      0x73u,
      8u,
      "fp_packet_ctrl_filter: 0x%x",
      v413,
      v414,
      v415,
      v416,
      v417,
      v418,
      v419,
      v420,
      *((unsigned __int16 *)a2 + 15));
    qdf_trace_msg(
      0x73u,
      8u,
      "mo_packet_ctrl_filter: 0x%x",
      v421,
      v422,
      v423,
      v424,
      v425,
      v426,
      v427,
      v428,
      *((unsigned __int16 *)a2 + 16));
    qdf_trace_msg(
      0x73u,
      8u,
      "fp_packet_data_filter: 0x%x",
      v429,
      v430,
      v431,
      v432,
      v433,
      v434,
      v435,
      v436,
      *((unsigned __int16 *)a2 + 17));
    qdf_trace_msg(
      0x73u,
      8u,
      "mo_packet_data_filter: 0x%x",
      v437,
      v438,
      v439,
      v440,
      v441,
      v442,
      v443,
      v444,
      *((unsigned __int16 *)a2 + 18));
    qdf_trace_msg(
      0x73u,
      8u,
      "md_packetdata_filter: 0x%x",
      v445,
      v446,
      v447,
      v448,
      v449,
      v450,
      v451,
      v452,
      *((unsigned __int16 *)a2 + 19));
    qdf_trace_msg(
      0x73u,
      8u,
      "md_packet_mgmt_filter: 0x%x",
      v453,
      v454,
      v455,
      v456,
      v457,
      v458,
      v459,
      v460,
      *((unsigned __int16 *)a2 + 20));
    qdf_trace_msg(
      0x73u,
      8u,
      "md_packet_ctrl_filter: 0x%x",
      v461,
      v462,
      v463,
      v464,
      v465,
      v466,
      v467,
      v468,
      *((unsigned __int16 *)a2 + 21));
    qdf_trace_msg(
      0x73u,
      8u,
      "fpmo_packet_data_filter: 0x%x",
      v469,
      v470,
      v471,
      v472,
      v473,
      v474,
      v475,
      v476,
      *((unsigned __int16 *)a2 + 22));
    qdf_trace_msg(
      0x73u,
      8u,
      "fpmo_packet_mgmt_filter: 0x%x",
      v477,
      v478,
      v479,
      v480,
      v481,
      v482,
      v483,
      v484,
      *((unsigned __int16 *)a2 + 23));
    return qdf_trace_msg(
             0x73u,
             8u,
             "fpmo_packet_ctrl_filter: 0x%x",
             v485,
             v486,
             v487,
             v488,
             v489,
             v490,
             v491,
             v492,
             *((unsigned __int16 *)a2 + 24));
  }
  return result;
}
