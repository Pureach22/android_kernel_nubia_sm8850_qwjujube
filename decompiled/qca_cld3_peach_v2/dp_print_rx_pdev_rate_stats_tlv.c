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
  __int64 v37; // x20
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x0
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7
  __int64 i; // x20
  unsigned __int16 v64; // w0
  unsigned __int16 v65; // w20
  unsigned __int16 v66; // w20
  unsigned __int16 v67; // w20
  unsigned __int16 v68; // w20
  unsigned __int16 v69; // w20
  unsigned __int16 v70; // w20
  unsigned __int16 v71; // w20
  unsigned __int16 v72; // w20
  unsigned __int16 v73; // w20
  unsigned __int16 v74; // w20
  unsigned __int16 v75; // w20
  unsigned __int16 v76; // w20
  unsigned __int16 v77; // w20
  __int16 v78; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned __int16 v87; // w0
  unsigned __int16 v88; // w20
  unsigned __int16 v89; // w20
  unsigned __int16 v90; // w20
  unsigned __int16 v91; // w20
  unsigned __int16 v92; // w20
  unsigned __int16 v93; // w20
  unsigned __int16 v94; // w20
  unsigned __int16 v95; // w20
  unsigned __int16 v96; // w20
  unsigned __int16 v97; // w20
  unsigned __int16 v98; // w20
  unsigned __int16 v99; // w20
  unsigned __int16 v100; // w20
  __int16 v101; // w0
  double v102; // d0
  double v103; // d1
  double v104; // d2
  double v105; // d3
  double v106; // d4
  double v107; // d5
  double v108; // d6
  double v109; // d7
  double v110; // d0
  double v111; // d1
  double v112; // d2
  double v113; // d3
  double v114; // d4
  double v115; // d5
  double v116; // d6
  double v117; // d7
  double v118; // d0
  double v119; // d1
  double v120; // d2
  double v121; // d3
  double v122; // d4
  double v123; // d5
  double v124; // d6
  double v125; // d7
  double v126; // d0
  double v127; // d1
  double v128; // d2
  double v129; // d3
  double v130; // d4
  double v131; // d5
  double v132; // d6
  double v133; // d7
  double v134; // d0
  double v135; // d1
  double v136; // d2
  double v137; // d3
  double v138; // d4
  double v139; // d5
  double v140; // d6
  double v141; // d7
  double v142; // d0
  double v143; // d1
  double v144; // d2
  double v145; // d3
  double v146; // d4
  double v147; // d5
  double v148; // d6
  double v149; // d7
  double v150; // d0
  double v151; // d1
  double v152; // d2
  double v153; // d3
  double v154; // d4
  double v155; // d5
  double v156; // d6
  double v157; // d7
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  double v166; // d0
  double v167; // d1
  double v168; // d2
  double v169; // d3
  double v170; // d4
  double v171; // d5
  double v172; // d6
  double v173; // d7
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  double v182; // d0
  double v183; // d1
  double v184; // d2
  double v185; // d3
  double v186; // d4
  double v187; // d5
  double v188; // d6
  double v189; // d7
  double v190; // d0
  double v191; // d1
  double v192; // d2
  double v193; // d3
  double v194; // d4
  double v195; // d5
  double v196; // d6
  double v197; // d7
  double v198; // d0
  double v199; // d1
  double v200; // d2
  double v201; // d3
  double v202; // d4
  double v203; // d5
  double v204; // d6
  double v205; // d7
  double v206; // d0
  double v207; // d1
  double v208; // d2
  double v209; // d3
  double v210; // d4
  double v211; // d5
  double v212; // d6
  double v213; // d7
  double v214; // d0
  double v215; // d1
  double v216; // d2
  double v217; // d3
  double v218; // d4
  double v219; // d5
  double v220; // d6
  double v221; // d7
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  unsigned __int16 v238; // w0
  unsigned __int16 v239; // w20
  unsigned __int16 v240; // w20
  unsigned __int16 v241; // w20
  unsigned __int16 v242; // w20
  unsigned __int16 v243; // w20
  unsigned __int16 v244; // w20
  unsigned __int16 v245; // w20
  unsigned __int16 v246; // w20
  unsigned __int16 v247; // w20
  unsigned __int16 v248; // w20
  unsigned __int16 v249; // w20
  __int16 v250; // w0
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  unsigned __int16 v259; // w0
  unsigned __int16 v260; // w20
  unsigned __int16 v261; // w20
  unsigned __int16 v262; // w20
  unsigned __int16 v263; // w20
  unsigned __int16 v264; // w20
  __int16 v265; // w0
  double v266; // d0
  double v267; // d1
  double v268; // d2
  double v269; // d3
  double v270; // d4
  double v271; // d5
  double v272; // d6
  double v273; // d7
  unsigned __int16 v274; // w0
  unsigned __int16 v275; // w20
  unsigned __int16 v276; // w20
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
  unsigned __int16 v287; // w20
  unsigned __int16 v288; // w20
  unsigned __int16 v289; // w20
  unsigned __int16 v290; // w20
  unsigned __int16 v291; // w20
  unsigned __int16 v292; // w20
  unsigned __int16 v293; // w20
  unsigned __int16 v294; // w20
  unsigned __int16 v295; // w20
  __int16 v296; // w0
  double v297; // d0
  double v298; // d1
  double v299; // d2
  double v300; // d3
  double v301; // d4
  double v302; // d5
  double v303; // d6
  double v304; // d7
  unsigned __int16 v305; // w0
  unsigned __int16 v306; // w20
  __int16 v307; // w0
  double v308; // d0
  double v309; // d1
  double v310; // d2
  double v311; // d3
  double v312; // d4
  double v313; // d5
  double v314; // d6
  double v315; // d7
  __int64 v316; // x20
  unsigned __int8 *v317; // x26
  char *v318; // x23
  unsigned __int16 v319; // w24
  unsigned __int16 v320; // w24
  __int16 v321; // w0
  int v322; // t1
  double v323; // d0
  double v324; // d1
  double v325; // d2
  double v326; // d3
  double v327; // d4
  double v328; // d5
  double v329; // d6
  double v330; // d7
  __int64 v331; // x20
  int *v332; // x25
  void *v333; // x23
  int v334; // w24
  int v335; // w24
  int v336; // w24
  int v337; // w24
  int v338; // w24
  int v339; // w24
  int v340; // w24
  int v341; // w24
  int v342; // w24
  __int16 v343; // w0
  int v344; // t1
  double v345; // d0
  double v346; // d1
  double v347; // d2
  double v348; // d3
  double v349; // d4
  double v350; // d5
  double v351; // d6
  double v352; // d7
  unsigned __int16 v353; // w0
  unsigned __int16 v354; // w20
  unsigned __int16 v355; // w20
  unsigned __int16 v356; // w20
  unsigned __int16 v357; // w20
  __int16 v358; // w0
  double v359; // d0
  double v360; // d1
  double v361; // d2
  double v362; // d3
  double v363; // d4
  double v364; // d5
  double v365; // d6
  double v366; // d7
  unsigned __int16 v367; // w0
  unsigned __int16 v368; // w20
  __int16 v369; // w0
  double v370; // d0
  double v371; // d1
  double v372; // d2
  double v373; // d3
  double v374; // d4
  double v375; // d5
  double v376; // d6
  double v377; // d7
  unsigned __int16 v378; // w0
  unsigned __int16 v379; // w20
  unsigned __int16 v380; // w20
  unsigned __int16 v381; // w20
  unsigned __int16 v382; // w20
  unsigned __int16 v383; // w20
  __int16 v384; // w0
  double v385; // d0
  double v386; // d1
  double v387; // d2
  double v388; // d3
  double v389; // d4
  double v390; // d5
  double v391; // d6
  double v392; // d7
  unsigned __int16 v393; // w0
  unsigned __int16 v394; // w20
  unsigned __int16 v395; // w20
  unsigned __int16 v396; // w20
  unsigned __int16 v397; // w20
  unsigned __int16 v398; // w20
  unsigned __int16 v399; // w20
  unsigned __int16 v400; // w20
  unsigned __int16 v401; // w20
  unsigned __int16 v402; // w20
  __int16 v403; // w0
  double v404; // d0
  double v405; // d1
  double v406; // d2
  double v407; // d3
  double v408; // d4
  double v409; // d5
  double v410; // d6
  double v411; // d7
  double v412; // d0
  double v413; // d1
  double v414; // d2
  double v415; // d3
  double v416; // d4
  double v417; // d5
  double v418; // d6
  double v419; // d7
  __int64 v420; // x20
  int *v421; // x26
  void *v422; // x23
  int v423; // w24
  int v424; // w24
  int v425; // w24
  int v426; // w24
  int v427; // w24
  int v428; // w24
  int v429; // w24
  int v430; // w24
  int v431; // w24
  __int16 v432; // w0
  int v433; // t1
  double v434; // d0
  double v435; // d1
  double v436; // d2
  double v437; // d3
  double v438; // d4
  double v439; // d5
  double v440; // d6
  double v441; // d7
  unsigned __int16 v442; // w0
  unsigned __int16 v443; // w20
  unsigned __int16 v444; // w20
  unsigned __int16 v445; // w20
  unsigned __int16 v446; // w20
  unsigned __int16 v447; // w20
  __int16 v448; // w0
  double v449; // d0
  double v450; // d1
  double v451; // d2
  double v452; // d3
  double v453; // d4
  double v454; // d5
  double v455; // d6
  double v456; // d7
  unsigned __int16 v457; // w0
  unsigned __int16 v458; // w20
  __int16 v459; // w0
  double v460; // d0
  double v461; // d1
  double v462; // d2
  double v463; // d3
  double v464; // d4
  double v465; // d5
  double v466; // d6
  double v467; // d7
  double v468; // d0
  double v469; // d1
  double v470; // d2
  double v471; // d3
  double v472; // d4
  double v473; // d5
  double v474; // d6
  double v475; // d7
  double v476; // d0
  double v477; // d1
  double v478; // d2
  double v479; // d3
  double v480; // d4
  double v481; // d5
  double v482; // d6
  double v483; // d7
  unsigned __int16 v484; // w0
  unsigned __int16 v485; // w20
  unsigned __int16 v486; // w20
  unsigned __int16 v487; // w20
  unsigned __int16 v488; // w20
  unsigned __int16 v489; // w20
  __int16 v490; // w0
  double v491; // d0
  double v492; // d1
  double v493; // d2
  double v494; // d3
  double v495; // d4
  double v496; // d5
  double v497; // d6
  double v498; // d7
  unsigned __int16 v499; // w0
  unsigned __int16 v500; // w20
  unsigned __int16 v501; // w20
  unsigned __int16 v502; // w20
  unsigned __int16 v503; // w20
  unsigned __int16 v504; // w20
  __int16 v505; // w0
  double v506; // d0
  double v507; // d1
  double v508; // d2
  double v509; // d3
  double v510; // d4
  double v511; // d5
  double v512; // d6
  double v513; // d7
  unsigned __int16 v514; // w0
  unsigned __int16 v515; // w20
  unsigned __int16 v516; // w20
  unsigned __int16 v517; // w20
  unsigned __int16 v518; // w20
  unsigned __int16 v519; // w20
  __int16 v520; // w0
  double v521; // d0
  double v522; // d1
  double v523; // d2
  double v524; // d3
  double v525; // d4
  double v526; // d5
  double v527; // d6
  double v528; // d7
  unsigned __int16 v529; // w0
  unsigned __int16 v530; // w20
  unsigned __int16 v531; // w20
  unsigned __int16 v532; // w20
  unsigned __int16 v533; // w20
  unsigned __int16 v534; // w20
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
  unsigned __int16 v545; // w20
  unsigned __int16 v546; // w20
  unsigned __int16 v547; // w20
  unsigned __int16 v548; // w20
  unsigned __int16 v549; // w20
  unsigned __int16 v550; // w20
  unsigned __int16 v551; // w20
  unsigned __int16 v552; // w20
  unsigned __int16 v553; // w20
  __int16 v554; // w0
  double v555; // d0
  double v556; // d1
  double v557; // d2
  double v558; // d3
  double v559; // d4
  double v560; // d5
  double v561; // d6
  double v562; // d7
  unsigned __int16 v563; // w0
  unsigned __int16 v564; // w20
  unsigned __int16 v565; // w20
  unsigned __int16 v566; // w20
  unsigned __int16 v567; // w20
  unsigned __int16 v568; // w20
  unsigned __int16 v569; // w20
  unsigned __int16 v570; // w20
  unsigned __int16 v571; // w20
  unsigned __int16 v572; // w20
  __int16 v573; // w0
  double v574; // d0
  double v575; // d1
  double v576; // d2
  double v577; // d3
  double v578; // d4
  double v579; // d5
  double v580; // d6
  double v581; // d7
  __int64 v582; // x0
  __int64 v583; // x28
  __int64 result; // x0
  __int64 v585; // [xsp+8h] [xbp-B8h]
  __int64 v586; // [xsp+10h] [xbp-B0h]
  unsigned int *v587; // [xsp+28h] [xbp-98h]
  __int64 v588; // [xsp+30h] [xbp-90h]
  __int64 v589; // [xsp+38h] [xbp-88h]
  __int64 v590; // [xsp+40h] [xbp-80h]
  __int64 v591; // [xsp+48h] [xbp-78h]
  __int64 v592; // [xsp+50h] [xbp-70h]
  __int64 v593; // [xsp+58h] [xbp-68h]
  __int64 v594; // [xsp+60h] [xbp-60h]
  __int64 v595; // [xsp+68h] [xbp-58h]
  __int64 v596; // [xsp+70h] [xbp-50h]
  __int64 v597; // [xsp+78h] [xbp-48h]
  __int64 v598; // [xsp+80h] [xbp-40h]
  __int64 v599; // [xsp+88h] [xbp-38h]
  __int64 v600; // [xsp+90h] [xbp-30h]
  __int64 v601; // [xsp+98h] [xbp-28h]
  __int64 v602; // [xsp+A0h] [xbp-20h]
  __int64 v603; // [xsp+A8h] [xbp-18h]
  __int64 v604; // [xsp+B0h] [xbp-10h]

  v604 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3788);
  if ( v4 )
  {
    v13 = (void *)v4;
    v587 = a2;
    v14 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v596 = v14;
    if ( !v14 )
      goto LABEL_27;
    v23 = v14;
    v24 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v597 = v24;
    if ( !v24 )
      goto LABEL_27;
    v25 = v24;
    v26 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v598 = v26;
    if ( !v26 )
      goto LABEL_27;
    v27 = v26;
    v28 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v599 = v28;
    if ( !v28 )
      goto LABEL_27;
    v29 = v28;
    v30 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v600 = v30;
    if ( !v30 )
      goto LABEL_27;
    v31 = v30;
    v32 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v601 = v32;
    if ( !v32 )
      goto LABEL_27;
    v33 = v32;
    v603 = 0;
    v34 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797);
    v602 = v34;
    if ( v34 && (v35 = v34, v36 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3797), (v603 = v36) != 0) )
    {
      v37 = v36;
      v594 = 0;
      v595 = 0;
      v593 = 0;
      v588 = 0;
      v589 = 0;
      v590 = 0;
      v591 = 0;
      v592 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3804);
      if ( v592
        && (v593 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3804)) != 0
        && (v594 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3804), (v586 = v594) != 0)
        && (v46 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3804), (v595 = v46) != 0) )
      {
        v585 = v46;
        v588 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3811);
        if ( v588
          && (v589 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3811)) != 0
          && (v590 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3811)) != 0
          && (v591 = _qdf_mem_malloc(0x3E8u, "dp_print_rx_pdev_rate_stats_tlv", 3811)) != 0 )
        {
          DP_PRINT_STATS("ul_ofdma_data_rx_ppdu = %d", v47, v48, v49, v50, v51, v52, v53, v54, (unsigned int)a1[23014]);
          for ( i = 0; i != 37; ++i )
            DP_PRINT_STATS(
              "ul_ofdma data %d user = %d",
              v55,
              v56,
              v57,
              v58,
              v59,
              v60,
              v61,
              v62,
              (unsigned int)i,
              (unsigned int)a1[i + 23015]);
          qdf_mem_set(v13, 0x3E8u, 0);
          v64 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a1[22982]);
          v65 = v64 + snprintf((char *)v13 + v64, 1000LL - v64, " %u:%u,", 1, a1[22983]);
          v66 = v65 + snprintf((char *)v13 + v65, 1000LL - v65, " %u:%u,", 2, a1[22984]);
          v67 = v66 + snprintf((char *)v13 + v66, 1000LL - v66, " %u:%u,", 3, a1[22985]);
          v68 = v67 + snprintf((char *)v13 + v67, 1000LL - v67, " %u:%u,", 4, a1[22986]);
          v69 = v68 + snprintf((char *)v13 + v68, 1000LL - v68, " %u:%u,", 5, a1[22987]);
          v70 = v69 + snprintf((char *)v13 + v69, 1000LL - v69, " %u:%u,", 6, a1[22988]);
          v71 = v70 + snprintf((char *)v13 + v70, 1000LL - v70, " %u:%u,", 7, a1[22989]);
          v72 = v71 + snprintf((char *)v13 + v71, 1000LL - v71, " %u:%u,", 8, a1[22990]);
          v73 = v72 + snprintf((char *)v13 + v72, 1000LL - v72, " %u:%u,", 9, a1[22991]);
          v74 = v73 + snprintf((char *)v13 + v73, 1000LL - v73, " %u:%u,", 10, a1[22992]);
          v75 = v74 + snprintf((char *)v13 + v74, 1000LL - v74, " %u:%u,", 11, a1[22993]);
          v76 = v75 + snprintf((char *)v13 + v75, 1000LL - v75, " %u:%u,", 12, a1[22994]);
          v77 = v76 + snprintf((char *)v13 + v76, 1000LL - v76, " %u:%u,", 13, a1[22995]);
          v78 = snprintf((char *)v13 + v77, 1000LL - v77, " %u:%u,", 14, a1[22996]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v77 + v78),
            1000LL - (unsigned __int16)(v77 + v78),
            " %u:%u,",
            15,
            a1[22997]);
          DP_PRINT_STATS("ul_ofdma_data_rx_ru_size= %s", v79, v80, v81, v82, v83, v84, v85, v86, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v87 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, a1[22998]);
          v88 = v87 + snprintf((char *)v13 + v87, 1000LL - v87, " %u:%u,", 1, a1[22999]);
          v89 = v88 + snprintf((char *)v13 + v88, 1000LL - v88, " %u:%u,", 2, a1[23000]);
          v90 = v89 + snprintf((char *)v13 + v89, 1000LL - v89, " %u:%u,", 3, a1[23001]);
          v91 = v90 + snprintf((char *)v13 + v90, 1000LL - v90, " %u:%u,", 4, a1[23002]);
          v92 = v91 + snprintf((char *)v13 + v91, 1000LL - v91, " %u:%u,", 5, a1[23003]);
          v93 = v92 + snprintf((char *)v13 + v92, 1000LL - v92, " %u:%u,", 6, a1[23004]);
          v94 = v93 + snprintf((char *)v13 + v93, 1000LL - v93, " %u:%u,", 7, a1[23005]);
          v95 = v94 + snprintf((char *)v13 + v94, 1000LL - v94, " %u:%u,", 8, a1[23006]);
          v96 = v95 + snprintf((char *)v13 + v95, 1000LL - v95, " %u:%u,", 9, a1[23007]);
          v97 = v96 + snprintf((char *)v13 + v96, 1000LL - v96, " %u:%u,", 10, a1[23008]);
          v98 = v97 + snprintf((char *)v13 + v97, 1000LL - v97, " %u:%u,", 11, a1[23009]);
          v99 = v98 + snprintf((char *)v13 + v98, 1000LL - v98, " %u:%u,", 12, a1[23010]);
          v100 = v99 + snprintf((char *)v13 + v99, 1000LL - v99, " %u:%u,", 13, a1[23011]);
          v101 = snprintf((char *)v13 + v100, 1000LL - v100, " %u:%u,", 14, a1[23012]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v100 + v101),
            1000LL - (unsigned __int16)(v100 + v101),
            " %u:%u,",
            15,
            a1[23013]);
          DP_PRINT_STATS("ul_ofdma_nondata_rx_ru_size= %s", v102, v103, v104, v105, v106, v107, v108, v109, v13);
          DP_PRINT_STATS("HTT_RX_PDEV_RATE_STATS_TLV:", v110, v111, v112, v113, v114, v115, v116, v117);
          DP_PRINT_STATS("mac_id__word = %u", v118, v119, v120, v121, v122, v123, v124, v125, v587[1]);
          DP_PRINT_STATS("nsts = %u", v126, v127, v128, v129, v130, v131, v132, v133, v587[2]);
          DP_PRINT_STATS("rx_ldpc = %u", v134, v135, v136, v137, v138, v139, v140, v141, v587[3]);
          DP_PRINT_STATS("rts_cnt = %u", v142, v143, v144, v145, v146, v147, v148, v149, v587[4]);
          DP_PRINT_STATS("rssi_mgmt = %u", v150, v151, v152, v153, v154, v155, v156, v157, v587[5]);
          DP_PRINT_STATS("rssi_data = %u", v158, v159, v160, v161, v162, v163, v164, v165, v587[6]);
          DP_PRINT_STATS("rssi_comb = %u", v166, v167, v168, v169, v170, v171, v172, v173, v587[7]);
          DP_PRINT_STATS("rssi_in_dbm = %d", v174, v175, v176, v177, v178, v179, v180, v181, v587[112]);
          DP_PRINT_STATS("rx_11ax_su_ext = %u", v182, v183, v184, v185, v186, v187, v188, v189, v587[113]);
          DP_PRINT_STATS("rx_11ac_mumimo = %u", v190, v191, v192, v193, v194, v195, v196, v197, v587[114]);
          DP_PRINT_STATS("rx_11ax_mumimo = %u", v198, v199, v200, v201, v202, v203, v204, v205, v587[115]);
          DP_PRINT_STATS("rx_11ax_ofdma = %u", v206, v207, v208, v209, v210, v211, v212, v213, v587[116]);
          DP_PRINT_STATS("txbf = %u", v214, v215, v216, v217, v218, v219, v220, v221, v587[117]);
          DP_PRINT_STATS("rx_su_ndpa = %u", v222, v223, v224, v225, v226, v227, v228, v229, v587[402]);
          DP_PRINT_STATS("rx_br_poll = %u", v230, v231, v232, v233, v234, v235, v236, v237, v587[428]);
          qdf_mem_set(v13, 0x3E8u, 0);
          v238 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[8]);
          v239 = v238 + snprintf((char *)v13 + v238, 1000LL - v238, " %u:%u,", 1, v587[9]);
          v240 = v239 + snprintf((char *)v13 + v239, 1000LL - v239, " %u:%u,", 2, v587[10]);
          v241 = v240 + snprintf((char *)v13 + v240, 1000LL - v240, " %u:%u,", 3, v587[11]);
          v242 = v241 + snprintf((char *)v13 + v241, 1000LL - v241, " %u:%u,", 4, v587[12]);
          v243 = v242 + snprintf((char *)v13 + v242, 1000LL - v242, " %u:%u,", 5, v587[13]);
          v244 = v243 + snprintf((char *)v13 + v243, 1000LL - v243, " %u:%u,", 6, v587[14]);
          v245 = v244 + snprintf((char *)v13 + v244, 1000LL - v244, " %u:%u,", 7, v587[15]);
          v246 = v245 + snprintf((char *)v13 + v245, 1000LL - v245, " %u:%u,", 8, v587[16]);
          v247 = v246 + snprintf((char *)v13 + v246, 1000LL - v246, " %u:%u,", 9, v587[17]);
          v248 = v247 + snprintf((char *)v13 + v247, 1000LL - v247, " %u:%u,", 10, v587[18]);
          v249 = v248 + snprintf((char *)v13 + v248, 1000LL - v248, " %u:%u,", 11, v587[19]);
          v250 = snprintf((char *)v13 + v249, 1000LL - v249, " %u:%u,", 12, v587[495]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v249 + v250),
            1000LL - (unsigned __int16)(v249 + v250),
            " %u:%u,",
            13,
            v587[496]);
          DP_PRINT_STATS("rx_mcs = %s ", v251, v252, v253, v254, v255, v256, v257, v258, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v259 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 1, v587[20]);
          v260 = v259 + snprintf((char *)v13 + v259, 1000LL - v259, " %u:%u,", 2, v587[21]);
          v261 = v260 + snprintf((char *)v13 + v260, 1000LL - v260, " %u:%u,", 3, v587[22]);
          v262 = v261 + snprintf((char *)v13 + v261, 1000LL - v261, " %u:%u,", 4, v587[23]);
          v263 = v262 + snprintf((char *)v13 + v262, 1000LL - v262, " %u:%u,", 5, v587[24]);
          v264 = v263 + snprintf((char *)v13 + v263, 1000LL - v263, " %u:%u,", 6, v587[25]);
          v265 = snprintf((char *)v13 + v264, 1000LL - v264, " %u:%u,", 7, v587[26]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v264 + v265),
            1000LL - (unsigned __int16)(v264 + v265),
            " %u:%u,",
            8,
            v587[27]);
          DP_PRINT_STATS("rx_nss = %s ", v266, v267, v268, v269, v270, v271, v272, v273, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v274 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[28]);
          v275 = v274 + snprintf((char *)v13 + v274, 1000LL - v274, " %u:%u,", 1, v587[29]);
          v276 = v275 + snprintf((char *)v13 + v275, 1000LL - v275, " %u:%u,", 2, v587[30]);
          v277 = snprintf((char *)v13 + v276, 1000LL - v276, " %u:%u,", 3, v587[31]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v276 + v277),
            1000LL - (unsigned __int16)(v276 + v277),
            " %u:%u,",
            4,
            v587[32]);
          DP_PRINT_STATS("rx_dcm = %s ", v278, v279, v280, v281, v282, v283, v284, v285, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v286 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[33]);
          v287 = v286 + snprintf((char *)v13 + v286, 1000LL - v286, " %u:%u,", 1, v587[34]);
          v288 = v287 + snprintf((char *)v13 + v287, 1000LL - v287, " %u:%u,", 2, v587[35]);
          v289 = v288 + snprintf((char *)v13 + v288, 1000LL - v288, " %u:%u,", 3, v587[36]);
          v290 = v289 + snprintf((char *)v13 + v289, 1000LL - v289, " %u:%u,", 4, v587[37]);
          v291 = v290 + snprintf((char *)v13 + v290, 1000LL - v290, " %u:%u,", 5, v587[38]);
          v292 = v291 + snprintf((char *)v13 + v291, 1000LL - v291, " %u:%u,", 6, v587[39]);
          v293 = v292 + snprintf((char *)v13 + v292, 1000LL - v292, " %u:%u,", 7, v587[40]);
          v294 = v293 + snprintf((char *)v13 + v293, 1000LL - v293, " %u:%u,", 8, v587[41]);
          v295 = v294 + snprintf((char *)v13 + v294, 1000LL - v294, " %u:%u,", 9, v587[42]);
          v296 = snprintf((char *)v13 + v295, 1000LL - v295, " %u:%u,", 10, v587[43]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v295 + v296),
            1000LL - (unsigned __int16)(v295 + v296),
            " %u:%u,",
            11,
            v587[44]);
          DP_PRINT_STATS("rx_stbc = %s ", v297, v298, v299, v300, v301, v302, v303, v304, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v305 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[45]);
          v306 = v305 + snprintf((char *)v13 + v305, 1000LL - v305, " %u:%u,", 1, v587[46]);
          v307 = snprintf((char *)v13 + v306, 1000LL - v306, " %u:%u,", 2, v587[47]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v306 + v307),
            1000LL - (unsigned __int16)(v306 + v307),
            " %u:%u,",
            3,
            v587[48]);
          DP_PRINT_STATS("rx_bw = %s ", v308, v309, v310, v311, v312, v313, v314, v315, v13);
          v316 = 0;
          v317 = (unsigned __int8 *)v587 + 227;
          do
          {
            v318 = (char *)*(&v596 + v316);
            v319 = snprintf(v318, 0x3E8u, " %u:%u,", 0, *(v317 - 3));
            v320 = v319 + snprintf(&v318[v319], 1000LL - v319, " %u:%u,", 1, *(v317 - 2));
            v321 = snprintf(&v318[v320], 1000LL - v320, " %u:%u,", 2, *(v317 - 1));
            v322 = *v317;
            v317 += 4;
            snprintf(
              &v318[(unsigned __int16)(v320 + v321)],
              1000LL - (unsigned __int16)(v320 + v321),
              " %u:%u,",
              3,
              v322);
            DP_PRINT_STATS(
              "rssi_chain[%u] = %s ",
              v323,
              v324,
              v325,
              v326,
              v327,
              v328,
              v329,
              v330,
              (unsigned int)v316++,
              v318);
          }
          while ( v316 != 8 );
          v331 = 0;
          v332 = (int *)(v587 + 75);
          do
          {
            v333 = (void *)*(&v592 + v331);
            qdf_mem_set(v333, 0x3E8u, 0);
            v334 = snprintf((char *)v333, 0x3E8u, " %u:%u,", 0, *(v332 - 11));
            v335 = v334
                 + snprintf(
                     (char *)v333 + (unsigned __int16)v334,
                     1000LL - (unsigned __int16)v334,
                     " %u:%u,",
                     1,
                     *(v332 - 10));
            v336 = v335
                 + snprintf(
                     (char *)v333 + (unsigned __int16)v335,
                     1000LL - (unsigned __int16)v335,
                     " %u:%u,",
                     2,
                     *(v332 - 9));
            v337 = v336
                 + snprintf(
                     (char *)v333 + (unsigned __int16)v336,
                     1000LL - (unsigned __int16)v336,
                     " %u:%u,",
                     3,
                     *(v332 - 8));
            v338 = v337
                 + snprintf(
                     (char *)v333 + (unsigned __int16)v337,
                     1000LL - (unsigned __int16)v337,
                     " %u:%u,",
                     4,
                     *(v332 - 7));
            v339 = v338
                 + snprintf(
                     (char *)v333 + (unsigned __int16)v338,
                     1000LL - (unsigned __int16)v338,
                     " %u:%u,",
                     5,
                     *(v332 - 6));
            v340 = v339
                 + snprintf(
                     (char *)v333 + (unsigned __int16)v339,
                     1000LL - (unsigned __int16)v339,
                     " %u:%u,",
                     6,
                     *(v332 - 5));
            v341 = v340
                 + snprintf(
                     (char *)v333 + (unsigned __int16)v340,
                     1000LL - (unsigned __int16)v340,
                     " %u:%u,",
                     7,
                     *(v332 - 4));
            v342 = v341
                 + snprintf(
                     (char *)v333 + (unsigned __int16)v341,
                     1000LL - (unsigned __int16)v341,
                     " %u:%u,",
                     8,
                     *(v332 - 3));
            LOWORD(v342) = v342
                         + snprintf(
                             (char *)v333 + (unsigned __int16)v342,
                             1000LL - (unsigned __int16)v342,
                             " %u:%u,",
                             9,
                             *(v332 - 2));
            v343 = snprintf(
                     (char *)v333 + (unsigned __int16)v342,
                     1000LL - (unsigned __int16)v342,
                     " %u:%u,",
                     10,
                     *(v332 - 1));
            v344 = *v332;
            v332 += 12;
            snprintf(
              (char *)v333 + (unsigned __int16)(v342 + v343),
              1000LL - (unsigned __int16)(v342 + v343),
              " %u:%u,",
              11,
              v344);
            DP_PRINT_STATS(
              "rx_gi[%u] = %s ",
              v345,
              v346,
              v347,
              v348,
              v349,
              v350,
              v351,
              v352,
              (unsigned int)v331++,
              v333);
          }
          while ( v331 != 4 );
          qdf_mem_set(v13, 0x3E8u, 0);
          v353 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[49]);
          v354 = v353 + snprintf((char *)v13 + v353, 1000LL - v353, " %u:%u,", 1, v587[50]);
          v355 = v354 + snprintf((char *)v13 + v354, 1000LL - v354, " %u:%u,", 2, v587[51]);
          v356 = v355 + snprintf((char *)v13 + v355, 1000LL - v355, " %u:%u,", 3, v587[52]);
          v357 = v356 + snprintf((char *)v13 + v356, 1000LL - v356, " %u:%u,", 4, v587[53]);
          v358 = snprintf((char *)v13 + v357, 1000LL - v357, " %u:%u,", 5, v587[54]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v357 + v358),
            1000LL - (unsigned __int16)(v357 + v358),
            " %u:%u,",
            6,
            v587[55]);
          DP_PRINT_STATS("rx_pream = %s", v359, v360, v361, v362, v363, v364, v365, v366, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v367 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[118]);
          v368 = v367 + snprintf((char *)v13 + v367, 1000LL - v367, " %u:%u,", 1, v587[119]);
          v369 = snprintf((char *)v13 + v368, 1000LL - v368, " %u:%u,", 2, v587[120]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v368 + v369),
            1000LL - (unsigned __int16)(v368 + v369),
            " %u:%u,",
            3,
            v587[121]);
          DP_PRINT_STATS("rx_legacy_cck_rate = %s", v370, v371, v372, v373, v374, v375, v376, v377, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v378 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[122]);
          v379 = v378 + snprintf((char *)v13 + v378, 1000LL - v378, " %u:%u,", 1, v587[123]);
          v380 = v379 + snprintf((char *)v13 + v379, 1000LL - v379, " %u:%u,", 2, v587[124]);
          v381 = v380 + snprintf((char *)v13 + v380, 1000LL - v380, " %u:%u,", 3, v587[125]);
          v382 = v381 + snprintf((char *)v13 + v381, 1000LL - v381, " %u:%u,", 4, v587[126]);
          v383 = v382 + snprintf((char *)v13 + v382, 1000LL - v382, " %u:%u,", 5, v587[127]);
          v384 = snprintf((char *)v13 + v383, 1000LL - v383, " %u:%u,", 6, v587[128]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v383 + v384),
            1000LL - (unsigned __int16)(v383 + v384),
            " %u:%u,",
            7,
            v587[129]);
          DP_PRINT_STATS("rx_legacy_ofdm_rate = %s", v385, v386, v387, v388, v389, v390, v391, v392, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v393 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[133]);
          v394 = v393 + snprintf((char *)v13 + v393, 1000LL - v393, " %u:%u,", 1, v587[134]);
          v395 = v394 + snprintf((char *)v13 + v394, 1000LL - v394, " %u:%u,", 2, v587[135]);
          v396 = v395 + snprintf((char *)v13 + v395, 1000LL - v395, " %u:%u,", 3, v587[136]);
          v397 = v396 + snprintf((char *)v13 + v396, 1000LL - v396, " %u:%u,", 4, v587[137]);
          v398 = v397 + snprintf((char *)v13 + v397, 1000LL - v397, " %u:%u,", 5, v587[138]);
          v399 = v398 + snprintf((char *)v13 + v398, 1000LL - v398, " %u:%u,", 6, v587[139]);
          v400 = v399 + snprintf((char *)v13 + v399, 1000LL - v399, " %u:%u,", 7, v587[140]);
          v401 = v400 + snprintf((char *)v13 + v400, 1000LL - v400, " %u:%u,", 8, v587[141]);
          v402 = v401 + snprintf((char *)v13 + v401, 1000LL - v401, " %u:%u,", 9, v587[142]);
          v403 = snprintf((char *)v13 + v402, 1000LL - v402, " %u:%u,", 10, v587[143]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v402 + v403),
            1000LL - (unsigned __int16)(v402 + v403),
            " %u:%u,",
            11,
            v587[144]);
          DP_PRINT_STATS("ul_ofdma_rx_mcs = %s", v404, v405, v406, v407, v408, v409, v410, v411, v13);
          DP_PRINT_STATS("rx_11ax_ul_ofdma = %u", v412, v413, v414, v415, v416, v417, v418, v419, v587[132]);
          v420 = 0;
          v421 = (int *)(v587 + 156);
          do
          {
            v422 = (void *)*(&v588 + v420);
            qdf_mem_set(v422, 0x3E8u, 0);
            v423 = snprintf((char *)v422, 0x3E8u, " %u:%u,", 0, *(v421 - 11));
            v424 = v423
                 + snprintf(
                     (char *)v422 + (unsigned __int16)v423,
                     1000LL - (unsigned __int16)v423,
                     " %u:%u,",
                     1,
                     *(v421 - 10));
            v425 = v424
                 + snprintf(
                     (char *)v422 + (unsigned __int16)v424,
                     1000LL - (unsigned __int16)v424,
                     " %u:%u,",
                     2,
                     *(v421 - 9));
            v426 = v425
                 + snprintf(
                     (char *)v422 + (unsigned __int16)v425,
                     1000LL - (unsigned __int16)v425,
                     " %u:%u,",
                     3,
                     *(v421 - 8));
            v427 = v426
                 + snprintf(
                     (char *)v422 + (unsigned __int16)v426,
                     1000LL - (unsigned __int16)v426,
                     " %u:%u,",
                     4,
                     *(v421 - 7));
            v428 = v427
                 + snprintf(
                     (char *)v422 + (unsigned __int16)v427,
                     1000LL - (unsigned __int16)v427,
                     " %u:%u,",
                     5,
                     *(v421 - 6));
            v429 = v428
                 + snprintf(
                     (char *)v422 + (unsigned __int16)v428,
                     1000LL - (unsigned __int16)v428,
                     " %u:%u,",
                     6,
                     *(v421 - 5));
            v430 = v429
                 + snprintf(
                     (char *)v422 + (unsigned __int16)v429,
                     1000LL - (unsigned __int16)v429,
                     " %u:%u,",
                     7,
                     *(v421 - 4));
            v431 = v430
                 + snprintf(
                     (char *)v422 + (unsigned __int16)v430,
                     1000LL - (unsigned __int16)v430,
                     " %u:%u,",
                     8,
                     *(v421 - 3));
            LOWORD(v431) = v431
                         + snprintf(
                             (char *)v422 + (unsigned __int16)v431,
                             1000LL - (unsigned __int16)v431,
                             " %u:%u,",
                             9,
                             *(v421 - 2));
            v432 = snprintf(
                     (char *)v422 + (unsigned __int16)v431,
                     1000LL - (unsigned __int16)v431,
                     " %u:%u,",
                     10,
                     *(v421 - 1));
            v433 = *v421;
            v421 += 12;
            snprintf(
              (char *)v422 + (unsigned __int16)(v431 + v432),
              1000LL - (unsigned __int16)(v431 + v432),
              " %u:%u,",
              11,
              v433);
            DP_PRINT_STATS(
              "ul_ofdma_rx_gi[%u] = %s ",
              v434,
              v435,
              v436,
              v437,
              v438,
              v439,
              v440,
              v441,
              (unsigned int)v420++,
              v422);
          }
          while ( v420 != 4 );
          qdf_mem_set(v13, 0x3E8u, 0);
          v442 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[193]);
          v443 = v442 + snprintf((char *)v13 + v442, 1000LL - v442, " %u:%u,", 1, v587[194]);
          v444 = v443 + snprintf((char *)v13 + v443, 1000LL - v443, " %u:%u,", 2, v587[195]);
          v445 = v444 + snprintf((char *)v13 + v444, 1000LL - v444, " %u:%u,", 3, v587[196]);
          v446 = v445 + snprintf((char *)v13 + v445, 1000LL - v445, " %u:%u,", 4, v587[197]);
          v447 = v446 + snprintf((char *)v13 + v446, 1000LL - v446, " %u:%u,", 5, v587[198]);
          v448 = snprintf((char *)v13 + v447, 1000LL - v447, " %u:%u,", 6, v587[199]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v447 + v448),
            1000LL - (unsigned __int16)(v447 + v448),
            " %u:%u,",
            7,
            v587[200]);
          DP_PRINT_STATS("ul_ofdma_rx_nss = %s", v449, v450, v451, v452, v453, v454, v455, v456, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v457 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[201]);
          v458 = v457 + snprintf((char *)v13 + v457, 1000LL - v457, " %u:%u,", 1, v587[202]);
          v459 = snprintf((char *)v13 + v458, 1000LL - v458, " %u:%u,", 2, v587[203]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v458 + v459),
            1000LL - (unsigned __int16)(v458 + v459),
            " %u:%u,",
            3,
            v587[204]);
          DP_PRINT_STATS("ul_ofdma_rx_bw = %s", v460, v461, v462, v463, v464, v465, v466, v467, v13);
          DP_PRINT_STATS("ul_ofdma_rx_stbc = %u", v468, v469, v470, v471, v472, v473, v474, v475, v587[205]);
          DP_PRINT_STATS("ul_ofdma_rx_ldpc = %u", v476, v477, v478, v479, v480, v481, v482, v483, v587[206]);
          qdf_mem_set(v13, 0x3E8u, 0);
          v484 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[207]);
          v485 = v484 + snprintf((char *)v13 + v484, 1000LL - v484, " %u:%u,", 1, v587[208]);
          v486 = v485 + snprintf((char *)v13 + v485, 1000LL - v485, " %u:%u,", 2, v587[209]);
          v487 = v486 + snprintf((char *)v13 + v486, 1000LL - v486, " %u:%u,", 3, v587[210]);
          v488 = v487 + snprintf((char *)v13 + v487, 1000LL - v487, " %u:%u,", 4, v587[211]);
          v489 = v488 + snprintf((char *)v13 + v488, 1000LL - v488, " %u:%u,", 5, v587[212]);
          v490 = snprintf((char *)v13 + v489, 1000LL - v489, " %u:%u,", 6, v587[213]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v489 + v490),
            1000LL - (unsigned __int16)(v489 + v490),
            " %u:%u,",
            7,
            v587[214]);
          DP_PRINT_STATS("rx_ulofdma_non_data_ppdu = %s", v491, v492, v493, v494, v495, v496, v497, v498, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v499 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[215]);
          v500 = v499 + snprintf((char *)v13 + v499, 1000LL - v499, " %u:%u,", 1, v587[216]);
          v501 = v500 + snprintf((char *)v13 + v500, 1000LL - v500, " %u:%u,", 2, v587[217]);
          v502 = v501 + snprintf((char *)v13 + v501, 1000LL - v501, " %u:%u,", 3, v587[218]);
          v503 = v502 + snprintf((char *)v13 + v502, 1000LL - v502, " %u:%u,", 4, v587[219]);
          v504 = v503 + snprintf((char *)v13 + v503, 1000LL - v503, " %u:%u,", 5, v587[220]);
          v505 = snprintf((char *)v13 + v504, 1000LL - v504, " %u:%u,", 6, v587[221]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v504 + v505),
            1000LL - (unsigned __int16)(v504 + v505),
            " %u:%u,",
            7,
            v587[222]);
          DP_PRINT_STATS("rx_ulofdma_data_ppdu = %s", v506, v507, v508, v509, v510, v511, v512, v513, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v514 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[223]);
          v515 = v514 + snprintf((char *)v13 + v514, 1000LL - v514, " %u:%u,", 1, v587[224]);
          v516 = v515 + snprintf((char *)v13 + v515, 1000LL - v515, " %u:%u,", 2, v587[225]);
          v517 = v516 + snprintf((char *)v13 + v516, 1000LL - v516, " %u:%u,", 3, v587[226]);
          v518 = v517 + snprintf((char *)v13 + v517, 1000LL - v517, " %u:%u,", 4, v587[227]);
          v519 = v518 + snprintf((char *)v13 + v518, 1000LL - v518, " %u:%u,", 5, v587[228]);
          v520 = snprintf((char *)v13 + v519, 1000LL - v519, " %u:%u,", 6, v587[229]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v519 + v520),
            1000LL - (unsigned __int16)(v519 + v520),
            " %u:%u,",
            7,
            v587[230]);
          DP_PRINT_STATS("rx_ulofdma_mpdu_ok = %s", v521, v522, v523, v524, v525, v526, v527, v528, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v529 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[231]);
          v530 = v529 + snprintf((char *)v13 + v529, 1000LL - v529, " %u:%u,", 1, v587[232]);
          v531 = v530 + snprintf((char *)v13 + v530, 1000LL - v530, " %u:%u,", 2, v587[233]);
          v532 = v531 + snprintf((char *)v13 + v531, 1000LL - v531, " %u:%u,", 3, v587[234]);
          v533 = v532 + snprintf((char *)v13 + v532, 1000LL - v532, " %u:%u,", 4, v587[235]);
          v534 = v533 + snprintf((char *)v13 + v533, 1000LL - v533, " %u:%u,", 5, v587[236]);
          v535 = snprintf((char *)v13 + v534, 1000LL - v534, " %u:%u,", 6, v587[237]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v534 + v535),
            1000LL - (unsigned __int16)(v534 + v535),
            " %u:%u,",
            7,
            v587[238]);
          DP_PRINT_STATS("rx_ulofdma_mpdu_fail = %s", v536, v537, v538, v539, v540, v541, v542, v543, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v544 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[403]);
          v545 = v544 + snprintf((char *)v13 + v544, 1000LL - v544, " %u:%u,", 1, v587[404]);
          v546 = v545 + snprintf((char *)v13 + v545, 1000LL - v545, " %u:%u,", 2, v587[405]);
          v547 = v546 + snprintf((char *)v13 + v546, 1000LL - v546, " %u:%u,", 3, v587[406]);
          v548 = v547 + snprintf((char *)v13 + v547, 1000LL - v547, " %u:%u,", 4, v587[407]);
          v549 = v548 + snprintf((char *)v13 + v548, 1000LL - v548, " %u:%u,", 5, v587[408]);
          v550 = v549 + snprintf((char *)v13 + v549, 1000LL - v549, " %u:%u,", 6, v587[409]);
          v551 = v550 + snprintf((char *)v13 + v550, 1000LL - v550, " %u:%u,", 7, v587[410]);
          v552 = v551 + snprintf((char *)v13 + v551, 1000LL - v551, " %u:%u,", 8, v587[411]);
          v553 = v552 + snprintf((char *)v13 + v552, 1000LL - v552, " %u:%u,", 9, v587[412]);
          v554 = snprintf((char *)v13 + v553, 1000LL - v553, " %u:%u,", 10, v587[413]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v553 + v554),
            1000LL - (unsigned __int16)(v553 + v554),
            " %u:%u,",
            11,
            v587[414]);
          DP_PRINT_STATS("rx_11ax_su_txbf_mcs = %s", v555, v556, v557, v558, v559, v560, v561, v562, v13);
          qdf_mem_set(v13, 0x3E8u, 0);
          v563 = snprintf((char *)v13, 0x3E8u, " %u:%u,", 0, v587[416]);
          v564 = v563 + snprintf((char *)v13 + v563, 1000LL - v563, " %u:%u,", 1, v587[417]);
          v565 = v564 + snprintf((char *)v13 + v564, 1000LL - v564, " %u:%u,", 2, v587[418]);
          v566 = v565 + snprintf((char *)v13 + v565, 1000LL - v565, " %u:%u,", 3, v587[419]);
          v567 = v566 + snprintf((char *)v13 + v566, 1000LL - v566, " %u:%u,", 4, v587[420]);
          v568 = v567 + snprintf((char *)v13 + v567, 1000LL - v567, " %u:%u,", 5, v587[421]);
          v569 = v568 + snprintf((char *)v13 + v568, 1000LL - v568, " %u:%u,", 6, v587[422]);
          v570 = v569 + snprintf((char *)v13 + v569, 1000LL - v569, " %u:%u,", 7, v587[423]);
          v571 = v570 + snprintf((char *)v13 + v570, 1000LL - v570, " %u:%u,", 8, v587[424]);
          v572 = v571 + snprintf((char *)v13 + v571, 1000LL - v571, " %u:%u,", 9, v587[425]);
          v573 = snprintf((char *)v13 + v572, 1000LL - v572, " %u:%u,", 10, v587[426]);
          snprintf(
            (char *)v13 + (unsigned __int16)(v572 + v573),
            1000LL - (unsigned __int16)(v572 + v573),
            " %u:%u,",
            11,
            v587[427]);
          DP_PRINT_STATS("rx_11ax_mu_txbf_mcs = %s", v574, v575, v576, v577, v578, v579, v580, v581, v13);
          _qdf_mem_free(v588);
          _qdf_mem_free(v589);
          _qdf_mem_free(v590);
          _qdf_mem_free(v591);
          v582 = v592;
          v583 = v593;
          v23 = v596;
          v25 = v597;
          v27 = v598;
          v29 = v599;
          v31 = v600;
          v33 = v601;
          v585 = v595;
          v586 = v594;
          v35 = v602;
          v37 = v603;
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: Unable to allocate buffer for ul_ofdma_rx_gi",
            v47,
            v48,
            v49,
            v50,
            v51,
            v52,
            v53,
            v54,
            "dp_print_rx_pdev_rate_stats_tlv");
          v583 = v593;
          v582 = v592;
        }
        _qdf_mem_free(v582);
        _qdf_mem_free(v583);
        _qdf_mem_free(v586);
        _qdf_mem_free(v585);
      }
      else
      {
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: Unable to allocate buffer for rx_gi",
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          "dp_print_rx_pdev_rate_stats_tlv");
      }
      _qdf_mem_free(v23);
      _qdf_mem_free(v25);
      _qdf_mem_free(v27);
      _qdf_mem_free(v29);
      _qdf_mem_free(v31);
      _qdf_mem_free(v33);
      _qdf_mem_free(v35);
      _qdf_mem_free(v37);
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
