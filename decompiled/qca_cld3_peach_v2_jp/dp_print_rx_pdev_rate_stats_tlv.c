__int64 __fastcall dp_print_rx_pdev_rate_stats_tlv(_DWORD *a1, unsigned int *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  void *v13; // x19
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 v24; // x0
  __int64 v25; // x22
  __int64 v26; // x0
  __int64 v27; // x23
  __int64 v28; // x0
  __int64 v29; // x24
  __int64 v30; // x0
  __int64 v31; // x25
  __int64 v32; // x0
  __int64 v33; // x26
  __int64 v34; // x0
  __int64 v35; // x27
  __int64 v36; // x0
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  __int64 v45; // x0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 i; // x21
  unsigned __int16 v63; // w0
  unsigned __int16 v64; // w22
  unsigned __int16 v65; // w22
  unsigned __int16 v66; // w22
  unsigned __int16 v67; // w22
  __int16 v68; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned __int16 v77; // w0
  unsigned __int16 v78; // w22
  unsigned __int16 v79; // w22
  unsigned __int16 v80; // w22
  unsigned __int16 v81; // w22
  __int16 v82; // w0
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
  unsigned __int16 v219; // w0
  unsigned __int16 v220; // w22
  unsigned __int16 v221; // w22
  unsigned __int16 v222; // w22
  unsigned __int16 v223; // w22
  unsigned __int16 v224; // w22
  unsigned __int16 v225; // w22
  unsigned __int16 v226; // w22
  unsigned __int16 v227; // w22
  unsigned __int16 v228; // w22
  unsigned __int16 v229; // w22
  unsigned __int16 v230; // w22
  __int16 v231; // w0
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  unsigned __int16 v240; // w0
  unsigned __int16 v241; // w22
  unsigned __int16 v242; // w22
  unsigned __int16 v243; // w22
  unsigned __int16 v244; // w22
  unsigned __int16 v245; // w22
  __int16 v246; // w0
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  unsigned __int16 v255; // w0
  unsigned __int16 v256; // w22
  unsigned __int16 v257; // w22
  __int16 v258; // w0
  double v259; // d0
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  unsigned __int16 v267; // w0
  unsigned __int16 v268; // w22
  unsigned __int16 v269; // w22
  unsigned __int16 v270; // w22
  unsigned __int16 v271; // w22
  unsigned __int16 v272; // w22
  unsigned __int16 v273; // w22
  unsigned __int16 v274; // w22
  unsigned __int16 v275; // w22
  unsigned __int16 v276; // w22
  __int16 v277; // w0
  double v278; // d0
  double v279; // d1
  double v280; // d2
  double v281; // d3
  double v282; // d4
  double v283; // d5
  double v284; // d6
  double v285; // d7
  unsigned __int16 v286; // w0
  unsigned __int16 v287; // w22
  __int16 v288; // w0
  double v289; // d0
  double v290; // d1
  double v291; // d2
  double v292; // d3
  double v293; // d4
  double v294; // d5
  double v295; // d6
  double v296; // d7
  __int64 v297; // x22
  unsigned __int8 *v298; // x27
  char *v299; // x24
  unsigned __int16 v300; // w25
  unsigned __int16 v301; // w25
  __int16 v302; // w0
  int v303; // t1
  double v304; // d0
  double v305; // d1
  double v306; // d2
  double v307; // d3
  double v308; // d4
  double v309; // d5
  double v310; // d6
  double v311; // d7
  __int64 v312; // x21
  int *v313; // x26
  void *v314; // x24
  int v315; // w25
  int v316; // w25
  int v317; // w25
  int v318; // w25
  int v319; // w25
  int v320; // w25
  int v321; // w25
  int v322; // w25
  int v323; // w25
  __int16 v324; // w0
  int v325; // t1
  double v326; // d0
  double v327; // d1
  double v328; // d2
  double v329; // d3
  double v330; // d4
  double v331; // d5
  double v332; // d6
  double v333; // d7
  unsigned __int16 v334; // w0
  unsigned __int16 v335; // w22
  unsigned __int16 v336; // w22
  unsigned __int16 v337; // w22
  unsigned __int16 v338; // w22
  __int16 v339; // w0
  double v340; // d0
  double v341; // d1
  double v342; // d2
  double v343; // d3
  double v344; // d4
  double v345; // d5
  double v346; // d6
  double v347; // d7
  unsigned __int16 v348; // w0
  unsigned __int16 v349; // w22
  __int16 v350; // w0
  double v351; // d0
  double v352; // d1
  double v353; // d2
  double v354; // d3
  double v355; // d4
  double v356; // d5
  double v357; // d6
  double v358; // d7
  unsigned __int16 v359; // w0
  unsigned __int16 v360; // w22
  unsigned __int16 v361; // w22
  unsigned __int16 v362; // w22
  unsigned __int16 v363; // w22
  unsigned __int16 v364; // w22
  __int16 v365; // w0
  double v366; // d0
  double v367; // d1
  double v368; // d2
  double v369; // d3
  double v370; // d4
  double v371; // d5
  double v372; // d6
  double v373; // d7
  unsigned __int16 v374; // w0
  unsigned __int16 v375; // w22
  unsigned __int16 v376; // w22
  unsigned __int16 v377; // w22
  unsigned __int16 v378; // w22
  unsigned __int16 v379; // w22
  unsigned __int16 v380; // w22
  unsigned __int16 v381; // w22
  unsigned __int16 v382; // w22
  unsigned __int16 v383; // w22
  __int16 v384; // w0
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
  __int64 v401; // x22
  int *v402; // x27
  void *v403; // x24
  int v404; // w25
  int v405; // w25
  int v406; // w25
  int v407; // w25
  int v408; // w25
  int v409; // w25
  int v410; // w25
  int v411; // w25
  int v412; // w25
  __int16 v413; // w0
  int v414; // t1
  double v415; // d0
  double v416; // d1
  double v417; // d2
  double v418; // d3
  double v419; // d4
  double v420; // d5
  double v421; // d6
  double v422; // d7
  unsigned __int16 v423; // w0
  unsigned __int16 v424; // w22
  unsigned __int16 v425; // w22
  unsigned __int16 v426; // w22
  unsigned __int16 v427; // w22
  unsigned __int16 v428; // w22
  __int16 v429; // w0
  double v430; // d0
  double v431; // d1
  double v432; // d2
  double v433; // d3
  double v434; // d4
  double v435; // d5
  double v436; // d6
  double v437; // d7
  unsigned __int16 v438; // w0
  unsigned __int16 v439; // w22
  __int16 v440; // w0
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
  unsigned __int16 v465; // w0
  unsigned __int16 v466; // w22
  unsigned __int16 v467; // w22
  unsigned __int16 v468; // w22
  unsigned __int16 v469; // w22
  unsigned __int16 v470; // w22
  __int16 v471; // w0
  double v472; // d0
  double v473; // d1
  double v474; // d2
  double v475; // d3
  double v476; // d4
  double v477; // d5
  double v478; // d6
  double v479; // d7
  unsigned __int16 v480; // w0
  unsigned __int16 v481; // w22
  unsigned __int16 v482; // w22
  unsigned __int16 v483; // w22
  unsigned __int16 v484; // w22
  unsigned __int16 v485; // w22
  __int16 v486; // w0
  double v487; // d0
  double v488; // d1
  double v489; // d2
  double v490; // d3
  double v491; // d4
  double v492; // d5
  double v493; // d6
  double v494; // d7
  unsigned __int16 v495; // w0
  unsigned __int16 v496; // w22
  unsigned __int16 v497; // w22
  unsigned __int16 v498; // w22
  unsigned __int16 v499; // w22
  unsigned __int16 v500; // w22
  __int16 v501; // w0
  double v502; // d0
  double v503; // d1
  double v504; // d2
  double v505; // d3
  double v506; // d4
  double v507; // d5
  double v508; // d6
  double v509; // d7
  unsigned __int16 v510; // w0
  unsigned __int16 v511; // w22
  unsigned __int16 v512; // w22
  unsigned __int16 v513; // w22
  unsigned __int16 v514; // w22
  unsigned __int16 v515; // w22
  __int16 v516; // w0
  double v517; // d0
  double v518; // d1
  double v519; // d2
  double v520; // d3
  double v521; // d4
  double v522; // d5
  double v523; // d6
  double v524; // d7
  unsigned __int16 v525; // w0
  unsigned __int16 v526; // w22
  unsigned __int16 v527; // w22
  unsigned __int16 v528; // w22
  unsigned __int16 v529; // w22
  unsigned __int16 v530; // w22
  unsigned __int16 v531; // w22
  unsigned __int16 v532; // w22
  unsigned __int16 v533; // w22
  unsigned __int16 v534; // w22
  __int16 v535; // w0
  double v536; // d0
  double v537; // d1
  double v538; // d2
  double v539; // d3
  double v540; // d4
  double v541; // d5
  double v542; // d6
  double v543; // d7
  unsigned __int16 v544; // w0
  unsigned __int16 v545; // w22
  unsigned __int16 v546; // w22
  unsigned __int16 v547; // w22
  unsigned __int16 v548; // w22
  unsigned __int16 v549; // w22
  unsigned __int16 v550; // w22
  unsigned __int16 v551; // w22
  unsigned __int16 v552; // w22
  unsigned __int16 v553; // w22
  __int16 v554; // w0
  double v555; // d0
  double v556; // d1
  double v557; // d2
  double v558; // d3
  double v559; // d4
  double v560; // d5
  double v561; // d6
  double v562; // d7
  __int64 v563; // x28
  __int64 v564; // x0
  __int64 v565; // x20
  __int64 result; // x0
  __int64 v567; // [xsp+8h] [xbp-B8h]
  __int64 v568; // [xsp+28h] [xbp-98h]
  __int64 v569; // [xsp+30h] [xbp-90h]
  __int64 v570; // [xsp+38h] [xbp-88h]
  __int64 v571; // [xsp+40h] [xbp-80h]
  __int64 v572; // [xsp+48h] [xbp-78h]
  __int64 v573; // [xsp+50h] [xbp-70h]
  __int64 v574; // [xsp+58h] [xbp-68h]
  __int64 v575; // [xsp+60h] [xbp-60h]
  __int64 v576; // [xsp+68h] [xbp-58h]
  __int64 v577; // [xsp+70h] [xbp-50h]
  __int64 v578; // [xsp+78h] [xbp-48h]
  __int64 v579; // [xsp+80h] [xbp-40h]
  __int64 v580; // [xsp+88h] [xbp-38h]
  __int64 v581; // [xsp+90h] [xbp-30h]
  __int64 v582; // [xsp+98h] [xbp-28h]
  __int64 v583; // [xsp+A0h] [xbp-20h]
  __int64 v584; // [xsp+A8h] [xbp-18h]
  __int64 v585; // [xsp+B0h] [xbp-10h]

  v585 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3788);
  if ( v4 )
  {
    v13 = (void *)v4;
    v14 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v577 = v14;
    if ( !v14 )
      goto LABEL_27;
    v23 = v14;
    v24 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v578 = v24;
    if ( !v24 )
      goto LABEL_27;
    v25 = v24;
    v26 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v579 = v26;
    if ( !v26 )
      goto LABEL_27;
    v27 = v26;
    v28 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v580 = v28;
    if ( !v28 )
      goto LABEL_27;
    v29 = v28;
    v30 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v581 = v30;
    if ( !v30 )
      goto LABEL_27;
    v31 = v30;
    v32 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v582 = v32;
    if ( !v32 )
      goto LABEL_27;
    v33 = v32;
    v584 = 0;
    v34 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v583 = v34;
    if ( v34 && (v35 = v34, v36 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797), (v584 = v36) != 0) )
    {
      v568 = v36;
      v569 = 0;
      v575 = 0;
      v576 = 0;
      v574 = 0;
      v570 = 0;
      v571 = 0;
      v572 = 0;
      v573 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3804);
      if ( v573
        && (v574 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3804)) != 0
        && (v575 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3804)) != 0
        && (v45 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3804), (v576 = v45) != 0) )
      {
        v567 = v45;
        v569 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3811);
        if ( v569
          && (v570 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3811)) != 0
          && (v571 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3811)) != 0
          && (v572 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3811)) != 0 )
        {
          DP_PRINT_STATS("ul_ofdma_data_rx_ppdu = %d", v46, v47, v48, v49, v50, v51, v52, v53, (unsigned int)a1[22790]);
          for ( i = 0; i != 37; ++i )
            DP_PRINT_STATS(
              "ul_ofdma data %d user = %d",
              v54,
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              (unsigned int)i,
              (unsigned int)a1[i + 22791]);
          qdf_mem_set(v13, 0x3E8u, 0);
          v63 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a1[22776]);
          v64 = v63 + snprintf((char *)v13 + v63, 1000LL - v63, " %u:%u,", 1, a1[22777]);
          v65 = v64 + snprintf((char *)v13 + v64, 1000LL - v64, " %u:%u,", 2, a1[22778]);
          v66 = v65 + snprintf((char *)v13 + v65, 1000LL - v65, " %u:%u,", 3, a1[22779]);
          v67 = v66 + snprintf((char *)v13 + v66, 1000LL - v66, " %u:%u,", 4, a1[22780]);
          v68 = snprintf((char *)v13 + v67, 1000LL - v67, " %u:%u,", 5, a1[22781]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v67 + v68),
            1000LL - (unsigned __int16)(v67 + v68),
            " %u:%u,",
            6,
            a1[22782]);
          DP_PRINT_STATS("ul_ofdma_data_rx_ru_size= %s", v69, v70, v71, v72, v73, v74, v75, v76, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v77 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a1[22783]);
          v78 = v77 + snprintf((char *)v13 + v77, 1000LL - v77, " %u:%u,", 1, a1[22784]);
          v79 = v78 + snprintf((char *)v13 + v78, 1000LL - v78, " %u:%u,", 2, a1[22785]);
          v80 = v79 + snprintf((char *)v13 + v79, 1000LL - v79, " %u:%u,", 3, a1[22786]);
          v81 = v80 + snprintf((char *)v13 + v80, 1000LL - v80, " %u:%u,", 4, a1[22787]);
          v82 = snprintf((char *)v13 + v81, 1000LL - v81, " %u:%u,", 5, a1[22788]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v81 + v82),
            1000LL - (unsigned __int16)(v81 + v82),
            " %u:%u,",
            6,
            a1[22789]);
          DP_PRINT_STATS("ul_ofdma_nondata_rx_ru_size= %s", v83, v84, v85, v86, v87, v88, v89, v90, v13);
          DP_PRINT_STATS("HTT_RX_PDEV_RATE_STATS_TLV:", v91, v92, v93, v94, v95, v96, v97, v98);
          DP_PRINT_STATS("mac_id__word = %u", v99, v100, v101, v102, v103, v104, v105, v106, a2[1]);
          DP_PRINT_STATS("nsts = %u", v107, v108, v109, v110, v111, v112, v113, v114, a2[2]);
          DP_PRINT_STATS("rx_ldpc = %u", v115, v116, v117, v118, v119, v120, v121, v122, a2[3]);
          DP_PRINT_STATS("rts_cnt = %u", v123, v124, v125, v126, v127, v128, v129, v130, a2[4]);
          DP_PRINT_STATS("rssi_mgmt = %u", v131, v132, v133, v134, v135, v136, v137, v138, a2[5]);
          DP_PRINT_STATS("rssi_data = %u", v139, v140, v141, v142, v143, v144, v145, v146, a2[6]);
          DP_PRINT_STATS("rssi_comb = %u", v147, v148, v149, v150, v151, v152, v153, v154, a2[7]);
          DP_PRINT_STATS("rssi_in_dbm = %d", v155, v156, v157, v158, v159, v160, v161, v162, a2[112]);
          DP_PRINT_STATS("rx_11ax_su_ext = %u", v163, v164, v165, v166, v167, v168, v169, v170, a2[113]);
          DP_PRINT_STATS("rx_11ac_mumimo = %u", v171, v172, v173, v174, v175, v176, v177, v178, a2[114]);
          DP_PRINT_STATS("rx_11ax_mumimo = %u", v179, v180, v181, v182, v183, v184, v185, v186, a2[115]);
          DP_PRINT_STATS("rx_11ax_ofdma = %u", v187, v188, v189, v190, v191, v192, v193, v194, a2[116]);
          DP_PRINT_STATS("txbf = %u", v195, v196, v197, v198, v199, v200, v201, v202, a2[117]);
          DP_PRINT_STATS("rx_su_ndpa = %u", v203, v204, v205, v206, v207, v208, v209, v210, a2[402]);
          DP_PRINT_STATS("rx_br_poll = %u", v211, v212, v213, v214, v215, v216, v217, v218, a2[428]);
          qdf_mem_set(v13, 0x3E8u, 0);
          v219 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[8]);
          v220 = v219 + snprintf((char *)v13 + v219, 1000LL - v219, " %u:%u,", 1, a2[9]);
          v221 = v220 + snprintf((char *)v13 + v220, 1000LL - v220, " %u:%u,", 2, a2[10]);
          v222 = v221 + snprintf((char *)v13 + v221, 1000LL - v221, " %u:%u,", 3, a2[11]);
          v223 = v222 + snprintf((char *)v13 + v222, 1000LL - v222, " %u:%u,", 4, a2[12]);
          v224 = v223 + snprintf((char *)v13 + v223, 1000LL - v223, " %u:%u,", 5, a2[13]);
          v225 = v224 + snprintf((char *)v13 + v224, 1000LL - v224, " %u:%u,", 6, a2[14]);
          v226 = v225 + snprintf((char *)v13 + v225, 1000LL - v225, " %u:%u,", 7, a2[15]);
          v227 = v226 + snprintf((char *)v13 + v226, 1000LL - v226, " %u:%u,", 8, a2[16]);
          v228 = v227 + snprintf((char *)v13 + v227, 1000LL - v227, " %u:%u,", 9, a2[17]);
          v229 = v228 + snprintf((char *)v13 + v228, 1000LL - v228, " %u:%u,", 10, a2[18]);
          v230 = v229 + snprintf((char *)v13 + v229, 1000LL - v229, " %u:%u,", 11, a2[19]);
          v231 = snprintf((char *)v13 + v230, 1000LL - v230, " %u:%u,", 12, a2[495]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v230 + v231),
            1000LL - (unsigned __int16)(v230 + v231),
            " %u:%u,",
            13,
            a2[496]);
          DP_PRINT_STATS("rx_mcs = %s ", v232, v233, v234, v235, v236, v237, v238, v239, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v240 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 1, a2[20]);
          v241 = v240 + snprintf((char *)v13 + v240, 1000LL - v240, " %u:%u,", 2, a2[21]);
          v242 = v241 + snprintf((char *)v13 + v241, 1000LL - v241, " %u:%u,", 3, a2[22]);
          v243 = v242 + snprintf((char *)v13 + v242, 1000LL - v242, " %u:%u,", 4, a2[23]);
          v244 = v243 + snprintf((char *)v13 + v243, 1000LL - v243, " %u:%u,", 5, a2[24]);
          v245 = v244 + snprintf((char *)v13 + v244, 1000LL - v244, " %u:%u,", 6, a2[25]);
          v246 = snprintf((char *)v13 + v245, 1000LL - v245, " %u:%u,", 7, a2[26]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v245 + v246),
            1000LL - (unsigned __int16)(v245 + v246),
            " %u:%u,",
            8,
            a2[27]);
          DP_PRINT_STATS("rx_nss = %s ", v247, v248, v249, v250, v251, v252, v253, v254, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v255 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[28]);
          v256 = v255 + snprintf((char *)v13 + v255, 1000LL - v255, " %u:%u,", 1, a2[29]);
          v257 = v256 + snprintf((char *)v13 + v256, 1000LL - v256, " %u:%u,", 2, a2[30]);
          v258 = snprintf((char *)v13 + v257, 1000LL - v257, " %u:%u,", 3, a2[31]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v257 + v258),
            1000LL - (unsigned __int16)(v257 + v258),
            " %u:%u,",
            4,
            a2[32]);
          DP_PRINT_STATS("rx_dcm = %s ", v259, v260, v261, v262, v263, v264, v265, v266, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v267 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[33]);
          v268 = v267 + snprintf((char *)v13 + v267, 1000LL - v267, " %u:%u,", 1, a2[34]);
          v269 = v268 + snprintf((char *)v13 + v268, 1000LL - v268, " %u:%u,", 2, a2[35]);
          v270 = v269 + snprintf((char *)v13 + v269, 1000LL - v269, " %u:%u,", 3, a2[36]);
          v271 = v270 + snprintf((char *)v13 + v270, 1000LL - v270, " %u:%u,", 4, a2[37]);
          v272 = v271 + snprintf((char *)v13 + v271, 1000LL - v271, " %u:%u,", 5, a2[38]);
          v273 = v272 + snprintf((char *)v13 + v272, 1000LL - v272, " %u:%u,", 6, a2[39]);
          v274 = v273 + snprintf((char *)v13 + v273, 1000LL - v273, " %u:%u,", 7, a2[40]);
          v275 = v274 + snprintf((char *)v13 + v274, 1000LL - v274, " %u:%u,", 8, a2[41]);
          v276 = v275 + snprintf((char *)v13 + v275, 1000LL - v275, " %u:%u,", 9, a2[42]);
          v277 = snprintf((char *)v13 + v276, 1000LL - v276, " %u:%u,", 10, a2[43]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v276 + v277),
            1000LL - (unsigned __int16)(v276 + v277),
            " %u:%u,",
            11,
            a2[44]);
          DP_PRINT_STATS("rx_stbc = %s ", v278, v279, v280, v281, v282, v283, v284, v285, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v286 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[45]);
          v287 = v286 + snprintf((char *)v13 + v286, 1000LL - v286, " %u:%u,", 1, a2[46]);
          v288 = snprintf((char *)v13 + v287, 1000LL - v287, " %u:%u,", 2, a2[47]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v287 + v288),
            1000LL - (unsigned __int16)(v287 + v288),
            " %u:%u,",
            3,
            a2[48]);
          DP_PRINT_STATS("rx_bw = %s ", v289, v290, v291, v292, v293, v294, v295, v296, v13);
          v297 = 0;
          v298 = (unsigned __int8 *)a2 + 227;
          do
          {
            v299 = (char *)*(&v577 + v297);
            v300 = snprintf(v299, 0x3E8u, " %u:%u,", 0, *(v298 - 3));
            v301 = v300 + snprintf(&v299[v300], 1000LL - v300, " %u:%u,", 1, *(v298 - 2));
            v302 = snprintf(&v299[v301], 1000LL - v301, " %u:%u,", 2, *(v298 - 1));
            v303 = *v298;
            v298 += 4;
            snprintf(
              &v299[(unsigned __int16)(v301 + v302)],
              1000LL - (unsigned __int16)(v301 + v302),
              " %u:%u,",
              3,
              v303);
            DP_PRINT_STATS(
              "rssi_chain[%u] = %s ",
              v304,
              v305,
              v306,
              v307,
              v308,
              v309,
              v310,
              v311,
              (unsigned int)v297++,
              v299);
          }
          while ( v297 != 8 );
          v312 = 0;
          v313 = (int *)(a2 + 75);
          do
          {
            v314 = (void *)*(&v573 + v312);
            qdf_mem_set(v314, 0x3E8u, 0);
            v315 = snprintf((char *)v314, 0x3E8u, " %u:%u,", 0, *(v313 - 11));
            v316 = v315
                 + snprintf(
                     (char *)v314 + (unsigned __int16)v315,
                     1000LL - (unsigned __int16)v315,
                     " %u:%u,",
                     1,
                     *(v313 - 10));
            v317 = v316
                 + snprintf(
                     (char *)v314 + (unsigned __int16)v316,
                     1000LL - (unsigned __int16)v316,
                     " %u:%u,",
                     2,
                     *(v313 - 9));
            v318 = v317
                 + snprintf(
                     (char *)v314 + (unsigned __int16)v317,
                     1000LL - (unsigned __int16)v317,
                     " %u:%u,",
                     3,
                     *(v313 - 8));
            v319 = v318
                 + snprintf(
                     (char *)v314 + (unsigned __int16)v318,
                     1000LL - (unsigned __int16)v318,
                     " %u:%u,",
                     4,
                     *(v313 - 7));
            v320 = v319
                 + snprintf(
                     (char *)v314 + (unsigned __int16)v319,
                     1000LL - (unsigned __int16)v319,
                     " %u:%u,",
                     5,
                     *(v313 - 6));
            v321 = v320
                 + snprintf(
                     (char *)v314 + (unsigned __int16)v320,
                     1000LL - (unsigned __int16)v320,
                     " %u:%u,",
                     6,
                     *(v313 - 5));
            v322 = v321
                 + snprintf(
                     (char *)v314 + (unsigned __int16)v321,
                     1000LL - (unsigned __int16)v321,
                     " %u:%u,",
                     7,
                     *(v313 - 4));
            v323 = v322
                 + snprintf(
                     (char *)v314 + (unsigned __int16)v322,
                     1000LL - (unsigned __int16)v322,
                     " %u:%u,",
                     8,
                     *(v313 - 3));
            LOWORD(v323) = v323
                         + snprintf(
                             (char *)v314 + (unsigned __int16)v323,
                             1000LL - (unsigned __int16)v323,
                             " %u:%u,",
                             9,
                             *(v313 - 2));
            v324 = snprintf(
                     (char *)v314 + (unsigned __int16)v323,
                     1000LL - (unsigned __int16)v323,
                     " %u:%u,",
                     10,
                     *(v313 - 1));
            v325 = *v313;
            v313 += 12;
            snprintf(
              (char *)v314 + (unsigned __int16)(v323 + v324),
              1000LL - (unsigned __int16)(v323 + v324),
              " %u:%u,",
              11,
              v325);
            DP_PRINT_STATS(
              "rx_gi[%u] = %s ",
              v326,
              v327,
              v328,
              v329,
              v330,
              v331,
              v332,
              v333,
              (unsigned int)v312++,
              v314);
          }
          while ( v312 != 4 );
          qdf_mem_set(v13, 0x3E8u, 0);
          v334 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[49]);
          v335 = v334 + snprintf((char *)v13 + v334, 1000LL - v334, " %u:%u,", 1, a2[50]);
          v336 = v335 + snprintf((char *)v13 + v335, 1000LL - v335, " %u:%u,", 2, a2[51]);
          v337 = v336 + snprintf((char *)v13 + v336, 1000LL - v336, " %u:%u,", 3, a2[52]);
          v338 = v337 + snprintf((char *)v13 + v337, 1000LL - v337, " %u:%u,", 4, a2[53]);
          v339 = snprintf((char *)v13 + v338, 1000LL - v338, " %u:%u,", 5, a2[54]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v338 + v339),
            1000LL - (unsigned __int16)(v338 + v339),
            " %u:%u,",
            6,
            a2[55]);
          DP_PRINT_STATS("rx_pream = %s", v340, v341, v342, v343, v344, v345, v346, v347, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v348 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[118]);
          v349 = v348 + snprintf((char *)v13 + v348, 1000LL - v348, " %u:%u,", 1, a2[119]);
          v350 = snprintf((char *)v13 + v349, 1000LL - v349, " %u:%u,", 2, a2[120]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v349 + v350),
            1000LL - (unsigned __int16)(v349 + v350),
            " %u:%u,",
            3,
            a2[121]);
          DP_PRINT_STATS("rx_legacy_cck_rate = %s", v351, v352, v353, v354, v355, v356, v357, v358, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v359 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[122]);
          v360 = v359 + snprintf((char *)v13 + v359, 1000LL - v359, " %u:%u,", 1, a2[123]);
          v361 = v360 + snprintf((char *)v13 + v360, 1000LL - v360, " %u:%u,", 2, a2[124]);
          v362 = v361 + snprintf((char *)v13 + v361, 1000LL - v361, " %u:%u,", 3, a2[125]);
          v363 = v362 + snprintf((char *)v13 + v362, 1000LL - v362, " %u:%u,", 4, a2[126]);
          v364 = v363 + snprintf((char *)v13 + v363, 1000LL - v363, " %u:%u,", 5, a2[127]);
          v365 = snprintf((char *)v13 + v364, 1000LL - v364, " %u:%u,", 6, a2[128]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v364 + v365),
            1000LL - (unsigned __int16)(v364 + v365),
            " %u:%u,",
            7,
            a2[129]);
          DP_PRINT_STATS("rx_legacy_ofdm_rate = %s", v366, v367, v368, v369, v370, v371, v372, v373, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v374 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[133]);
          v375 = v374 + snprintf((char *)v13 + v374, 1000LL - v374, " %u:%u,", 1, a2[134]);
          v376 = v375 + snprintf((char *)v13 + v375, 1000LL - v375, " %u:%u,", 2, a2[135]);
          v377 = v376 + snprintf((char *)v13 + v376, 1000LL - v376, " %u:%u,", 3, a2[136]);
          v378 = v377 + snprintf((char *)v13 + v377, 1000LL - v377, " %u:%u,", 4, a2[137]);
          v379 = v378 + snprintf((char *)v13 + v378, 1000LL - v378, " %u:%u,", 5, a2[138]);
          v380 = v379 + snprintf((char *)v13 + v379, 1000LL - v379, " %u:%u,", 6, a2[139]);
          v381 = v380 + snprintf((char *)v13 + v380, 1000LL - v380, " %u:%u,", 7, a2[140]);
          v382 = v381 + snprintf((char *)v13 + v381, 1000LL - v381, " %u:%u,", 8, a2[141]);
          v383 = v382 + snprintf((char *)v13 + v382, 1000LL - v382, " %u:%u,", 9, a2[142]);
          v384 = snprintf((char *)v13 + v383, 1000LL - v383, " %u:%u,", 10, a2[143]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v383 + v384),
            1000LL - (unsigned __int16)(v383 + v384),
            " %u:%u,",
            11,
            a2[144]);
          DP_PRINT_STATS("ul_ofdma_rx_mcs = %s", v385, v386, v387, v388, v389, v390, v391, v392, v13);
          DP_PRINT_STATS("rx_11ax_ul_ofdma = %u", v393, v394, v395, v396, v397, v398, v399, v400, a2[132]);
          v401 = 0;
          v402 = (int *)(a2 + 156);
          do
          {
            v403 = (void *)*(&v569 + v401);
            qdf_mem_set(v403, 0x3E8u, 0);
            v404 = snprintf((char *)v403, 0x3E8u, " %u:%u,", 0, *(v402 - 11));
            v405 = v404
                 + snprintf(
                     (char *)v403 + (unsigned __int16)v404,
                     1000LL - (unsigned __int16)v404,
                     " %u:%u,",
                     1,
                     *(v402 - 10));
            v406 = v405
                 + snprintf(
                     (char *)v403 + (unsigned __int16)v405,
                     1000LL - (unsigned __int16)v405,
                     " %u:%u,",
                     2,
                     *(v402 - 9));
            v407 = v406
                 + snprintf(
                     (char *)v403 + (unsigned __int16)v406,
                     1000LL - (unsigned __int16)v406,
                     " %u:%u,",
                     3,
                     *(v402 - 8));
            v408 = v407
                 + snprintf(
                     (char *)v403 + (unsigned __int16)v407,
                     1000LL - (unsigned __int16)v407,
                     " %u:%u,",
                     4,
                     *(v402 - 7));
            v409 = v408
                 + snprintf(
                     (char *)v403 + (unsigned __int16)v408,
                     1000LL - (unsigned __int16)v408,
                     " %u:%u,",
                     5,
                     *(v402 - 6));
            v410 = v409
                 + snprintf(
                     (char *)v403 + (unsigned __int16)v409,
                     1000LL - (unsigned __int16)v409,
                     " %u:%u,",
                     6,
                     *(v402 - 5));
            v411 = v410
                 + snprintf(
                     (char *)v403 + (unsigned __int16)v410,
                     1000LL - (unsigned __int16)v410,
                     " %u:%u,",
                     7,
                     *(v402 - 4));
            v412 = v411
                 + snprintf(
                     (char *)v403 + (unsigned __int16)v411,
                     1000LL - (unsigned __int16)v411,
                     " %u:%u,",
                     8,
                     *(v402 - 3));
            LOWORD(v412) = v412
                         + snprintf(
                             (char *)v403 + (unsigned __int16)v412,
                             1000LL - (unsigned __int16)v412,
                             " %u:%u,",
                             9,
                             *(v402 - 2));
            v413 = snprintf(
                     (char *)v403 + (unsigned __int16)v412,
                     1000LL - (unsigned __int16)v412,
                     " %u:%u,",
                     10,
                     *(v402 - 1));
            v414 = *v402;
            v402 += 12;
            snprintf(
              (char *)v403 + (unsigned __int16)(v412 + v413),
              1000LL - (unsigned __int16)(v412 + v413),
              " %u:%u,",
              11,
              v414);
            DP_PRINT_STATS(
              "ul_ofdma_rx_gi[%u] = %s ",
              v415,
              v416,
              v417,
              v418,
              v419,
              v420,
              v421,
              v422,
              (unsigned int)v401++,
              v403);
          }
          while ( v401 != 4 );
          qdf_mem_set(v13, 0x3E8u, 0);
          v423 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[193]);
          v424 = v423 + snprintf((char *)v13 + v423, 1000LL - v423, " %u:%u,", 1, a2[194]);
          v425 = v424 + snprintf((char *)v13 + v424, 1000LL - v424, " %u:%u,", 2, a2[195]);
          v426 = v425 + snprintf((char *)v13 + v425, 1000LL - v425, " %u:%u,", 3, a2[196]);
          v427 = v426 + snprintf((char *)v13 + v426, 1000LL - v426, " %u:%u,", 4, a2[197]);
          v428 = v427 + snprintf((char *)v13 + v427, 1000LL - v427, " %u:%u,", 5, a2[198]);
          v429 = snprintf((char *)v13 + v428, 1000LL - v428, " %u:%u,", 6, a2[199]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v428 + v429),
            1000LL - (unsigned __int16)(v428 + v429),
            " %u:%u,",
            7,
            a2[200]);
          DP_PRINT_STATS("ul_ofdma_rx_nss = %s", v430, v431, v432, v433, v434, v435, v436, v437, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v438 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[201]);
          v439 = v438 + snprintf((char *)v13 + v438, 1000LL - v438, " %u:%u,", 1, a2[202]);
          v440 = snprintf((char *)v13 + v439, 1000LL - v439, " %u:%u,", 2, a2[203]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v439 + v440),
            1000LL - (unsigned __int16)(v439 + v440),
            " %u:%u,",
            3,
            a2[204]);
          DP_PRINT_STATS("ul_ofdma_rx_bw = %s", v441, v442, v443, v444, v445, v446, v447, v448, v13);
          DP_PRINT_STATS("ul_ofdma_rx_stbc = %u", v449, v450, v451, v452, v453, v454, v455, v456, a2[205]);
          DP_PRINT_STATS("ul_ofdma_rx_ldpc = %u", v457, v458, v459, v460, v461, v462, v463, v464, a2[206]);
          qdf_mem_set(v13, 0x3E8u, 0);
          v465 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[207]);
          v466 = v465 + snprintf((char *)v13 + v465, 1000LL - v465, " %u:%u,", 1, a2[208]);
          v467 = v466 + snprintf((char *)v13 + v466, 1000LL - v466, " %u:%u,", 2, a2[209]);
          v468 = v467 + snprintf((char *)v13 + v467, 1000LL - v467, " %u:%u,", 3, a2[210]);
          v469 = v468 + snprintf((char *)v13 + v468, 1000LL - v468, " %u:%u,", 4, a2[211]);
          v470 = v469 + snprintf((char *)v13 + v469, 1000LL - v469, " %u:%u,", 5, a2[212]);
          v471 = snprintf((char *)v13 + v470, 1000LL - v470, " %u:%u,", 6, a2[213]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v470 + v471),
            1000LL - (unsigned __int16)(v470 + v471),
            " %u:%u,",
            7,
            a2[214]);
          DP_PRINT_STATS("rx_ulofdma_non_data_ppdu = %s", v472, v473, v474, v475, v476, v477, v478, v479, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v480 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[215]);
          v481 = v480 + snprintf((char *)v13 + v480, 1000LL - v480, " %u:%u,", 1, a2[216]);
          v482 = v481 + snprintf((char *)v13 + v481, 1000LL - v481, " %u:%u,", 2, a2[217]);
          v483 = v482 + snprintf((char *)v13 + v482, 1000LL - v482, " %u:%u,", 3, a2[218]);
          v484 = v483 + snprintf((char *)v13 + v483, 1000LL - v483, " %u:%u,", 4, a2[219]);
          v485 = v484 + snprintf((char *)v13 + v484, 1000LL - v484, " %u:%u,", 5, a2[220]);
          v486 = snprintf((char *)v13 + v485, 1000LL - v485, " %u:%u,", 6, a2[221]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v485 + v486),
            1000LL - (unsigned __int16)(v485 + v486),
            " %u:%u,",
            7,
            a2[222]);
          DP_PRINT_STATS("rx_ulofdma_data_ppdu = %s", v487, v488, v489, v490, v491, v492, v493, v494, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v495 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[223]);
          v496 = v495 + snprintf((char *)v13 + v495, 1000LL - v495, " %u:%u,", 1, a2[224]);
          v497 = v496 + snprintf((char *)v13 + v496, 1000LL - v496, " %u:%u,", 2, a2[225]);
          v498 = v497 + snprintf((char *)v13 + v497, 1000LL - v497, " %u:%u,", 3, a2[226]);
          v499 = v498 + snprintf((char *)v13 + v498, 1000LL - v498, " %u:%u,", 4, a2[227]);
          v500 = v499 + snprintf((char *)v13 + v499, 1000LL - v499, " %u:%u,", 5, a2[228]);
          v501 = snprintf((char *)v13 + v500, 1000LL - v500, " %u:%u,", 6, a2[229]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v500 + v501),
            1000LL - (unsigned __int16)(v500 + v501),
            " %u:%u,",
            7,
            a2[230]);
          DP_PRINT_STATS("rx_ulofdma_mpdu_ok = %s", v502, v503, v504, v505, v506, v507, v508, v509, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v510 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[231]);
          v511 = v510 + snprintf((char *)v13 + v510, 1000LL - v510, " %u:%u,", 1, a2[232]);
          v512 = v511 + snprintf((char *)v13 + v511, 1000LL - v511, " %u:%u,", 2, a2[233]);
          v513 = v512 + snprintf((char *)v13 + v512, 1000LL - v512, " %u:%u,", 3, a2[234]);
          v514 = v513 + snprintf((char *)v13 + v513, 1000LL - v513, " %u:%u,", 4, a2[235]);
          v515 = v514 + snprintf((char *)v13 + v514, 1000LL - v514, " %u:%u,", 5, a2[236]);
          v516 = snprintf((char *)v13 + v515, 1000LL - v515, " %u:%u,", 6, a2[237]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v515 + v516),
            1000LL - (unsigned __int16)(v515 + v516),
            " %u:%u,",
            7,
            a2[238]);
          DP_PRINT_STATS("rx_ulofdma_mpdu_fail = %s", v517, v518, v519, v520, v521, v522, v523, v524, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v525 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[403]);
          v526 = v525 + snprintf((char *)v13 + v525, 1000LL - v525, " %u:%u,", 1, a2[404]);
          v527 = v526 + snprintf((char *)v13 + v526, 1000LL - v526, " %u:%u,", 2, a2[405]);
          v528 = v527 + snprintf((char *)v13 + v527, 1000LL - v527, " %u:%u,", 3, a2[406]);
          v529 = v528 + snprintf((char *)v13 + v528, 1000LL - v528, " %u:%u,", 4, a2[407]);
          v530 = v529 + snprintf((char *)v13 + v529, 1000LL - v529, " %u:%u,", 5, a2[408]);
          v531 = v530 + snprintf((char *)v13 + v530, 1000LL - v530, " %u:%u,", 6, a2[409]);
          v532 = v531 + snprintf((char *)v13 + v531, 1000LL - v531, " %u:%u,", 7, a2[410]);
          v533 = v532 + snprintf((char *)v13 + v532, 1000LL - v532, " %u:%u,", 8, a2[411]);
          v534 = v533 + snprintf((char *)v13 + v533, 1000LL - v533, " %u:%u,", 9, a2[412]);
          v535 = snprintf((char *)v13 + v534, 1000LL - v534, " %u:%u,", 10, a2[413]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v534 + v535),
            1000LL - (unsigned __int16)(v534 + v535),
            " %u:%u,",
            11,
            a2[414]);
          DP_PRINT_STATS("rx_11ax_su_txbf_mcs = %s", v536, v537, v538, v539, v540, v541, v542, v543, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v544 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a2[416]);
          v545 = v544 + snprintf((char *)v13 + v544, 1000LL - v544, " %u:%u,", 1, a2[417]);
          v546 = v545 + snprintf((char *)v13 + v545, 1000LL - v545, " %u:%u,", 2, a2[418]);
          v547 = v546 + snprintf((char *)v13 + v546, 1000LL - v546, " %u:%u,", 3, a2[419]);
          v548 = v547 + snprintf((char *)v13 + v547, 1000LL - v547, " %u:%u,", 4, a2[420]);
          v549 = v548 + snprintf((char *)v13 + v548, 1000LL - v548, " %u:%u,", 5, a2[421]);
          v550 = v549 + snprintf((char *)v13 + v549, 1000LL - v549, " %u:%u,", 6, a2[422]);
          v551 = v550 + snprintf((char *)v13 + v550, 1000LL - v550, " %u:%u,", 7, a2[423]);
          v552 = v551 + snprintf((char *)v13 + v551, 1000LL - v551, " %u:%u,", 8, a2[424]);
          v553 = v552 + snprintf((char *)v13 + v552, 1000LL - v552, " %u:%u,", 9, a2[425]);
          v554 = snprintf((char *)v13 + v553, 1000LL - v553, " %u:%u,", 10, a2[426]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v553 + v554),
            1000LL - (unsigned __int16)(v553 + v554),
            " %u:%u,",
            11,
            a2[427]);
          DP_PRINT_STATS("rx_11ax_mu_txbf_mcs = %s", v555, v556, v557, v558, v559, v560, v561, v562, v13);
          _qdf_mem_free(v569);
          _qdf_mem_free(v570);
          _qdf_mem_free(v571);
          _qdf_mem_free(v572);
          v563 = v575;
          v564 = v573;
          v565 = v574;
          v23 = v577;
          v25 = v578;
          v567 = v576;
          v27 = v579;
          v29 = v580;
          v31 = v581;
          v33 = v582;
          v35 = v583;
          v568 = v584;
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Unable to allocate buffer for ul_ofdma_rx_gi",
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            "dp_print_rx_pdev_rate_stats_tlv");
          v565 = v574;
          v564 = v573;
          v563 = v575;
        }
        _qdf_mem_free(v564);
        _qdf_mem_free(v565);
        _qdf_mem_free(v563);
        _qdf_mem_free(v567);
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Unable to allocate buffer for rx_gi",
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          "dp_print_rx_pdev_rate_stats_tlv");
      }
      _qdf_mem_free(v23);
      _qdf_mem_free(v25);
      _qdf_mem_free(v27);
      _qdf_mem_free(v29);
      _qdf_mem_free(v31);
      _qdf_mem_free(v33);
      _qdf_mem_free(v35);
      _qdf_mem_free(v568);
    }
    else
    {
LABEL_27:
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Unable to allocate buffer for rssi_chain",
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        "dp_print_rx_pdev_rate_stats_tlv");
    }
    result = _qdf_mem_free((__int64)v13);
  }
  else
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Output buffer not allocated",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "dp_print_rx_pdev_rate_stats_tlv");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
