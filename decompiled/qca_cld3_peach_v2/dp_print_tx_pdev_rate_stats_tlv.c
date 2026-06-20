__int64 __fastcall dp_print_tx_pdev_rate_stats_tlv(unsigned int *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  void *v11; // x19
  __int64 v12; // x25
  __int64 v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  void *v22; // x20
  void *v23; // x21
  void *v24; // x22
  void *v25; // x23
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x0
  __int64 v35; // x0
  __int64 v36; // x0
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
  unsigned __int16 v77; // w0
  unsigned __int16 v78; // w25
  unsigned __int16 v79; // w25
  unsigned __int16 v80; // w25
  unsigned __int16 v81; // w25
  unsigned __int16 v82; // w25
  unsigned __int16 v83; // w25
  unsigned __int16 v84; // w25
  unsigned __int16 v85; // w25
  unsigned __int16 v86; // w25
  unsigned __int16 v87; // w25
  unsigned __int16 v88; // w25
  unsigned __int16 v89; // w25
  unsigned __int16 v90; // w25
  __int16 v91; // w0
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  unsigned __int16 v100; // w0
  unsigned __int16 v101; // w25
  unsigned __int16 v102; // w25
  unsigned __int16 v103; // w25
  unsigned __int16 v104; // w25
  unsigned __int16 v105; // w25
  unsigned __int16 v106; // w25
  unsigned __int16 v107; // w25
  unsigned __int16 v108; // w25
  unsigned __int16 v109; // w25
  __int16 v110; // w0
  double v111; // d0
  double v112; // d1
  double v113; // d2
  double v114; // d3
  double v115; // d4
  double v116; // d5
  double v117; // d6
  double v118; // d7
  unsigned __int16 v119; // w0
  unsigned __int16 v120; // w25
  unsigned __int16 v121; // w25
  unsigned __int16 v122; // w25
  unsigned __int16 v123; // w25
  unsigned __int16 v124; // w25
  unsigned __int16 v125; // w25
  unsigned __int16 v126; // w25
  unsigned __int16 v127; // w25
  unsigned __int16 v128; // w25
  __int16 v129; // w0
  double v130; // d0
  double v131; // d1
  double v132; // d2
  double v133; // d3
  double v134; // d4
  double v135; // d5
  double v136; // d6
  double v137; // d7
  unsigned __int16 v138; // w0
  unsigned __int16 v139; // w25
  unsigned __int16 v140; // w25
  unsigned __int16 v141; // w25
  unsigned __int16 v142; // w25
  unsigned __int16 v143; // w25
  __int16 v144; // w0
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  unsigned __int16 v153; // w0
  unsigned __int16 v154; // w25
  __int16 v155; // w0
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
  unsigned __int16 v172; // w0
  unsigned __int16 v173; // w25
  unsigned __int16 v174; // w25
  unsigned __int16 v175; // w25
  unsigned __int16 v176; // w25
  unsigned __int16 v177; // w25
  unsigned __int16 v178; // w25
  unsigned __int16 v179; // w25
  unsigned __int16 v180; // w25
  unsigned __int16 v181; // w25
  unsigned __int16 v182; // w25
  unsigned __int16 v183; // w25
  __int16 v184; // w0
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  unsigned __int16 v193; // w26
  unsigned __int16 v194; // w25
  unsigned __int16 v195; // w25
  unsigned __int16 v196; // w25
  unsigned __int16 v197; // w25
  __int16 v198; // w0
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  __int64 v207; // x9
  int *v208; // x25
  void *v209; // x28
  int v210; // w27
  int v211; // w27
  int v212; // w27
  int v213; // w27
  int v214; // w27
  int v215; // w27
  int v216; // w27
  int v217; // w27
  int v218; // w27
  __int16 v219; // w0
  int v220; // t1
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  unsigned __int16 v229; // w0
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  unsigned __int16 v238; // w0
  double v239; // d0
  double v240; // d1
  double v241; // d2
  double v242; // d3
  double v243; // d4
  double v244; // d5
  double v245; // d6
  double v246; // d7
  unsigned __int16 v247; // w0
  double v248; // d0
  double v249; // d1
  double v250; // d2
  double v251; // d3
  double v252; // d4
  double v253; // d5
  double v254; // d6
  double v255; // d7
  unsigned __int16 v256; // w0
  double v257; // d0
  double v258; // d1
  double v259; // d2
  double v260; // d3
  double v261; // d4
  double v262; // d5
  double v263; // d6
  double v264; // d7
  unsigned __int16 v265; // w0
  unsigned __int16 v266; // w25
  unsigned __int16 v267; // w25
  __int16 v268; // w0
  double v269; // d0
  double v270; // d1
  double v271; // d2
  double v272; // d3
  double v273; // d4
  double v274; // d5
  double v275; // d6
  double v276; // d7
  unsigned __int16 v277; // w0
  unsigned __int16 v278; // w25
  unsigned __int16 v279; // w25
  __int16 v280; // w0
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
  unsigned __int16 v321; // w0
  unsigned __int16 v322; // w25
  __int16 v323; // w0
  double v324; // d0
  double v325; // d1
  double v326; // d2
  double v327; // d3
  double v328; // d4
  double v329; // d5
  double v330; // d6
  double v331; // d7
  unsigned __int16 v332; // w0
  unsigned __int16 v333; // w25
  unsigned __int16 v334; // w25
  unsigned __int16 v335; // w25
  unsigned __int16 v336; // w25
  unsigned __int16 v337; // w25
  __int16 v338; // w0
  double v339; // d0
  double v340; // d1
  double v341; // d2
  double v342; // d3
  double v343; // d4
  double v344; // d5
  double v345; // d6
  double v346; // d7
  unsigned __int16 v347; // w0
  unsigned __int16 v348; // w25
  unsigned __int16 v349; // w25
  unsigned __int16 v350; // w25
  double v351; // d0
  double v352; // d1
  double v353; // d2
  double v354; // d3
  double v355; // d4
  double v356; // d5
  double v357; // d6
  double v358; // d7
  unsigned __int16 v359; // w25
  unsigned __int16 v360; // w25
  unsigned __int16 v361; // w25
  unsigned __int16 v362; // w25
  unsigned __int16 v363; // w25
  unsigned __int16 v364; // w25
  unsigned __int16 v365; // w25
  unsigned __int16 v366; // w25
  unsigned __int16 v367; // w25
  unsigned __int16 v368; // w25
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
  unsigned __int16 v379; // w25
  unsigned __int16 v380; // w25
  unsigned __int16 v381; // w25
  unsigned __int16 v382; // w25
  unsigned __int16 v383; // w25
  unsigned __int16 v384; // w25
  unsigned __int16 v385; // w25
  unsigned __int16 v386; // w25
  unsigned __int16 v387; // w25
  __int16 v388; // w0
  double v389; // d0
  double v390; // d1
  double v391; // d2
  double v392; // d3
  double v393; // d4
  double v394; // d5
  double v395; // d6
  double v396; // d7
  unsigned __int16 v397; // w0
  unsigned __int16 v398; // w25
  unsigned __int16 v399; // w25
  unsigned __int16 v400; // w25
  unsigned __int16 v401; // w25
  unsigned __int16 v402; // w25
  unsigned __int16 v403; // w25
  unsigned __int16 v404; // w25
  unsigned __int16 v405; // w25
  unsigned __int16 v406; // w25
  __int16 v407; // w0
  double v408; // d0
  double v409; // d1
  double v410; // d2
  double v411; // d3
  double v412; // d4
  double v413; // d5
  double v414; // d6
  double v415; // d7
  unsigned __int16 v416; // w27
  unsigned __int16 v417; // w25
  unsigned __int16 v418; // w25
  unsigned __int16 v419; // w25
  unsigned __int16 v420; // w25
  unsigned __int16 v421; // w25
  unsigned __int16 v422; // w25
  unsigned __int16 v423; // w25
  unsigned __int16 v424; // w25
  unsigned __int16 v425; // w25
  __int16 v426; // w0
  double v427; // d0
  double v428; // d1
  double v429; // d2
  double v430; // d3
  double v431; // d4
  double v432; // d5
  double v433; // d6
  double v434; // d7
  unsigned __int16 v435; // w0
  unsigned __int16 v436; // w25
  unsigned __int16 v437; // w25
  unsigned __int16 v438; // w25
  unsigned __int16 v439; // w25
  unsigned __int16 v440; // w25
  __int16 v441; // w0
  double v442; // d0
  double v443; // d1
  double v444; // d2
  double v445; // d3
  double v446; // d4
  double v447; // d5
  double v448; // d6
  double v449; // d7
  unsigned __int16 v450; // w0
  unsigned __int16 v451; // w25
  unsigned __int16 v452; // w25
  unsigned __int16 v453; // w25
  unsigned __int16 v454; // w25
  unsigned __int16 v455; // w25
  __int16 v456; // w0
  double v457; // d0
  double v458; // d1
  double v459; // d2
  double v460; // d3
  double v461; // d4
  double v462; // d5
  double v463; // d6
  double v464; // d7
  unsigned __int16 v465; // w0
  unsigned __int16 v466; // w25
  unsigned __int16 v467; // w25
  unsigned __int16 v468; // w25
  unsigned __int16 v469; // w25
  unsigned __int16 v470; // w25
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
  unsigned __int16 v481; // w25
  __int16 v482; // w0
  double v483; // d0
  double v484; // d1
  double v485; // d2
  double v486; // d3
  double v487; // d4
  double v488; // d5
  double v489; // d6
  double v490; // d7
  unsigned __int16 v491; // w0
  unsigned __int16 v492; // w25
  __int16 v493; // w0
  double v494; // d0
  double v495; // d1
  double v496; // d2
  double v497; // d3
  double v498; // d4
  double v499; // d5
  double v500; // d6
  double v501; // d7
  unsigned __int16 v502; // w26
  unsigned __int16 v503; // w25
  __int16 v504; // w0
  double v505; // d0
  double v506; // d1
  double v507; // d2
  double v508; // d3
  double v509; // d4
  double v510; // d5
  double v511; // d6
  double v512; // d7
  __int64 v513; // x9
  int *v514; // x25
  void *v515; // x28
  int v516; // w27
  int v517; // w27
  int v518; // w27
  int v519; // w27
  int v520; // w27
  int v521; // w27
  int v522; // w27
  int v523; // w27
  int v524; // w27
  __int16 v525; // w0
  int v526; // t1
  double v527; // d0
  double v528; // d1
  double v529; // d2
  double v530; // d3
  double v531; // d4
  double v532; // d5
  double v533; // d6
  double v534; // d7
  __int64 v535; // x9
  int *v536; // x26
  void *v537; // x28
  int v538; // w27
  int v539; // w27
  int v540; // w27
  int v541; // w27
  int v542; // w27
  int v543; // w27
  int v544; // w27
  int v545; // w27
  int v546; // w27
  __int16 v547; // w0
  int v548; // t1
  double v549; // d0
  double v550; // d1
  double v551; // d2
  double v552; // d3
  double v553; // d4
  double v554; // d5
  double v555; // d6
  double v556; // d7
  __int64 v557; // x25
  int *v558; // x26
  void *v559; // x27
  int v560; // w28
  int v561; // w28
  int v562; // w28
  int v563; // w28
  int v564; // w28
  int v565; // w28
  int v566; // w28
  int v567; // w28
  int v568; // w28
  __int16 v569; // w0
  int v570; // t1
  double v571; // d0
  double v572; // d1
  double v573; // d2
  double v574; // d3
  double v575; // d4
  double v576; // d5
  double v577; // d6
  double v578; // d7
  __int64 result; // x0
  const char *v580; // x2
  __int64 v581; // [xsp+0h] [xbp-90h]
  __int64 v582; // [xsp+0h] [xbp-90h]
  __int64 v583; // [xsp+0h] [xbp-90h]
  __int64 v584; // [xsp+8h] [xbp-88h]
  __int64 v585; // [xsp+10h] [xbp-80h]
  __int64 v586; // [xsp+18h] [xbp-78h]
  __int64 v587; // [xsp+20h] [xbp-70h]
  __int64 v588; // [xsp+28h] [xbp-68h]
  __int64 v589; // [xsp+30h] [xbp-60h]
  __int64 v590; // [xsp+38h] [xbp-58h]
  __int64 v591; // [xsp+40h] [xbp-50h]
  __int64 v592; // [xsp+48h] [xbp-48h]
  __int64 v593; // [xsp+50h] [xbp-40h]
  __int64 v594; // [xsp+58h] [xbp-38h]
  __int64 v595; // [xsp+60h] [xbp-30h]
  __int64 v596; // [xsp+68h] [xbp-28h]
  __int64 v597; // [xsp+70h] [xbp-20h]
  __int64 v598; // [xsp+78h] [xbp-18h]
  __int64 v599; // [xsp+80h] [xbp-10h]
  __int64 v600; // [xsp+88h] [xbp-8h]

  v600 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v598 = 0;
  v599 = 0;
  v597 = 0;
  v594 = 0;
  v595 = 0;
  v592 = 0;
  v593 = 0;
  v590 = 0;
  v591 = 0;
  v588 = 0;
  v589 = 0;
  v586 = 0;
  v587 = 0;
  v584 = 0;
  v585 = 0;
  v2 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3243);
  if ( !v2 )
  {
    result = qdf_trace_msg(
               0x45u,
               2u,
               "%s: Output buffer not allocated",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "dp_print_tx_pdev_rate_stats_tlv");
    goto LABEL_82;
  }
  v11 = (void *)v2;
  v12 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3251);
  v596 = v12;
  v13 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3252);
  v22 = (void *)v13;
  v23 = nullptr;
  v24 = nullptr;
  v25 = nullptr;
  if ( !v12 || !v13 )
    goto LABEL_41;
  v592 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3257);
  if ( !v592 )
  {
    v25 = nullptr;
    v24 = nullptr;
    v23 = nullptr;
    goto LABEL_34;
  }
  v588 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3262);
  if ( !v588 )
  {
    v25 = nullptr;
    v24 = nullptr;
    v23 = nullptr;
LABEL_36:
    v580 = "%s: Unable to allocate buffer for ax_mu_mimo_tx_gi";
    goto LABEL_39;
  }
  v584 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3267);
  if ( !v584 )
  {
    v25 = nullptr;
    v24 = nullptr;
    v23 = nullptr;
LABEL_38:
    v580 = "%s: Unable to allocate buffer for ofdma_tx_gi";
    goto LABEL_39;
  }
  v597 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3251);
  v34 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3252);
  v23 = (void *)v34;
  v24 = nullptr;
  if ( !v597 || !v34 )
  {
    v25 = nullptr;
    goto LABEL_41;
  }
  v593 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3257);
  if ( !v593 )
  {
    v25 = nullptr;
    v24 = nullptr;
    goto LABEL_34;
  }
  v589 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3262);
  if ( !v589 )
  {
    v25 = nullptr;
    v24 = nullptr;
    goto LABEL_36;
  }
  v585 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3267);
  if ( !v585 )
  {
    v25 = nullptr;
    v24 = nullptr;
    goto LABEL_38;
  }
  v598 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3251);
  v35 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3252);
  v24 = (void *)v35;
  v25 = nullptr;
  if ( !v598 || !v35 )
    goto LABEL_41;
  v594 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3257);
  if ( !v594 )
  {
    v25 = nullptr;
    goto LABEL_34;
  }
  v590 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3262);
  if ( !v590 )
  {
    v25 = nullptr;
    goto LABEL_36;
  }
  v586 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3267);
  if ( !v586 )
  {
    v25 = nullptr;
    goto LABEL_38;
  }
  v599 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3251);
  v36 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3252);
  v25 = (void *)v36;
  if ( v599 && v36 )
  {
    v595 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3257);
    if ( v595 )
    {
      v591 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3262);
      if ( v591 )
      {
        v587 = _qdf_mem_malloc(0x3E8u, "dp_print_tx_pdev_rate_stats_tlv", 3267);
        if ( v587 )
        {
          DP_PRINT_STATS("HTT_TX_PDEV_RATE_STATS_TLV:", v26, v27, v28, v29, v30, v31, v32, v33);
          DP_PRINT_STATS("mac_id__word = %u", v37, v38, v39, v40, v41, v42, v43, v44, a1[1]);
          DP_PRINT_STATS("tx_ldpc = %u", v45, v46, v47, v48, v49, v50, v51, v52, a1[2]);
          DP_PRINT_STATS("rts_cnt = %u", v53, v54, v55, v56, v57, v58, v59, v60, a1[3]);
          DP_PRINT_STATS("rts_success = %u", v61, v62, v63, v64, v65, v66, v67, v68, a1[125]);
          DP_PRINT_STATS("ack_rssi = %u", v69, v70, v71, v72, v73, v74, v75, v76, a1[4]);
          qdf_mem_set(v11, 0x3E8u, 0);
          v77 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[5]);
          v78 = v77 + snprintf((char *)v11 + v77, 1000LL - v77, " %u:%u,", 1, a1[6]);
          v79 = v78 + snprintf((char *)v11 + v78, 1000LL - v78, " %u:%u,", 2, a1[7]);
          v80 = v79 + snprintf((char *)v11 + v79, 1000LL - v79, " %u:%u,", 3, a1[8]);
          v81 = v80 + snprintf((char *)v11 + v80, 1000LL - v80, " %u:%u,", 4, a1[9]);
          v82 = v81 + snprintf((char *)v11 + v81, 1000LL - v81, " %u:%u,", 5, a1[10]);
          v83 = v82 + snprintf((char *)v11 + v82, 1000LL - v82, " %u:%u,", 6, a1[11]);
          v84 = v83 + snprintf((char *)v11 + v83, 1000LL - v83, " %u:%u,", 7, a1[12]);
          v85 = v84 + snprintf((char *)v11 + v84, 1000LL - v84, " %u:%u,", 8, a1[13]);
          v86 = v85 + snprintf((char *)v11 + v85, 1000LL - v85, " %u:%u,", 9, a1[14]);
          v87 = v86 + snprintf((char *)v11 + v86, 1000LL - v86, " %u:%u,", 10, a1[15]);
          v88 = v87 + snprintf((char *)v11 + v87, 1000LL - v87, " %u:%u,", 11, a1[16]);
          v89 = v88 + snprintf((char *)v11 + v88, 1000LL - v88, " %u:%u,", 12, a1[368]);
          v90 = v89 + snprintf((char *)v11 + v89, 1000LL - v89, " %u:%u,", 13, a1[369]);
          v91 = snprintf((char *)v11 + v90, 1000LL - v90, " %u:%u,", 14, a1[400]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v90 + v91),
            1000LL - (unsigned __int16)(v90 + v91),
            " %u:%u,",
            15,
            a1[401]);
          DP_PRINT_STATS("tx_mcs = %s ", v92, v93, v94, v95, v96, v97, v98, v99, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v100 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[17]);
          v101 = v100 + snprintf((char *)v11 + v100, 1000LL - v100, " %u:%u,", 1, a1[18]);
          v102 = v101 + snprintf((char *)v11 + v101, 1000LL - v101, " %u:%u,", 2, a1[19]);
          v103 = v102 + snprintf((char *)v11 + v102, 1000LL - v102, " %u:%u,", 3, a1[20]);
          v104 = v103 + snprintf((char *)v11 + v103, 1000LL - v103, " %u:%u,", 4, a1[21]);
          v105 = v104 + snprintf((char *)v11 + v104, 1000LL - v104, " %u:%u,", 5, a1[22]);
          v106 = v105 + snprintf((char *)v11 + v105, 1000LL - v105, " %u:%u,", 6, a1[23]);
          v107 = v106 + snprintf((char *)v11 + v106, 1000LL - v106, " %u:%u,", 7, a1[24]);
          v108 = v107 + snprintf((char *)v11 + v107, 1000LL - v107, " %u:%u,", 8, a1[25]);
          v109 = v108 + snprintf((char *)v11 + v108, 1000LL - v108, " %u:%u,", 9, a1[26]);
          v110 = snprintf((char *)v11 + v109, 1000LL - v109, " %u:%u,", 10, a1[27]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v109 + v110),
            1000LL - (unsigned __int16)(v109 + v110),
            " %u:%u,",
            11,
            a1[28]);
          DP_PRINT_STATS("tx_su_mcs = %s ", v111, v112, v113, v114, v115, v116, v117, v118, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v119 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[29]);
          v120 = v119 + snprintf((char *)v11 + v119, 1000LL - v119, " %u:%u,", 1, a1[30]);
          v121 = v120 + snprintf((char *)v11 + v120, 1000LL - v120, " %u:%u,", 2, a1[31]);
          v122 = v121 + snprintf((char *)v11 + v121, 1000LL - v121, " %u:%u,", 3, a1[32]);
          v123 = v122 + snprintf((char *)v11 + v122, 1000LL - v122, " %u:%u,", 4, a1[33]);
          v124 = v123 + snprintf((char *)v11 + v123, 1000LL - v123, " %u:%u,", 5, a1[34]);
          v125 = v124 + snprintf((char *)v11 + v124, 1000LL - v124, " %u:%u,", 6, a1[35]);
          v126 = v125 + snprintf((char *)v11 + v125, 1000LL - v125, " %u:%u,", 7, a1[36]);
          v127 = v126 + snprintf((char *)v11 + v126, 1000LL - v126, " %u:%u,", 8, a1[37]);
          v128 = v127 + snprintf((char *)v11 + v127, 1000LL - v127, " %u:%u,", 9, a1[38]);
          v129 = snprintf((char *)v11 + v128, 1000LL - v128, " %u:%u,", 10, a1[39]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v128 + v129),
            1000LL - (unsigned __int16)(v128 + v129),
            " %u:%u,",
            11,
            a1[40]);
          DP_PRINT_STATS("tx_mu_mcs = %s ", v130, v131, v132, v133, v134, v135, v136, v137, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v138 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 1, a1[41]);
          v139 = v138 + snprintf((char *)v11 + v138, 1000LL - v138, " %u:%u,", 2, a1[42]);
          v140 = v139 + snprintf((char *)v11 + v139, 1000LL - v139, " %u:%u,", 3, a1[43]);
          v141 = v140 + snprintf((char *)v11 + v140, 1000LL - v140, " %u:%u,", 4, a1[44]);
          v142 = v141 + snprintf((char *)v11 + v141, 1000LL - v141, " %u:%u,", 5, a1[45]);
          v143 = v142 + snprintf((char *)v11 + v142, 1000LL - v142, " %u:%u,", 6, a1[46]);
          v144 = snprintf((char *)v11 + v143, 1000LL - v143, " %u:%u,", 7, a1[47]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v143 + v144),
            1000LL - (unsigned __int16)(v143 + v144),
            " %u:%u,",
            8,
            a1[48]);
          DP_PRINT_STATS("tx_nss = %s ", v145, v146, v147, v148, v149, v150, v151, v152, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v153 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[49]);
          v154 = v153 + snprintf((char *)v11 + v153, 1000LL - v153, " %u:%u,", 1, a1[50]);
          v155 = snprintf((char *)v11 + v154, 1000LL - v154, " %u:%u,", 2, a1[51]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v154 + v155),
            1000LL - (unsigned __int16)(v154 + v155),
            " %u:%u,",
            3,
            a1[52]);
          DP_PRINT_STATS("tx_bw = %s ", v156, v157, v158, v159, v160, v161, v162, v163, v11);
          DP_PRINT_STATS("tx_bw_320mhz = %u ", v164, v165, v166, v167, v168, v169, v170, v171, a1[402]);
          qdf_mem_set(v11, 0x3E8u, 0);
          v172 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[53]);
          v173 = v172 + snprintf((char *)v11 + v172, 1000LL - v172, " %u:%u,", 1, a1[54]);
          v174 = v173 + snprintf((char *)v11 + v173, 1000LL - v173, " %u:%u,", 2, a1[55]);
          v175 = v174 + snprintf((char *)v11 + v174, 1000LL - v174, " %u:%u,", 3, a1[56]);
          v176 = v175 + snprintf((char *)v11 + v175, 1000LL - v175, " %u:%u,", 4, a1[57]);
          v177 = v176 + snprintf((char *)v11 + v176, 1000LL - v176, " %u:%u,", 5, a1[58]);
          v178 = v177 + snprintf((char *)v11 + v177, 1000LL - v177, " %u:%u,", 6, a1[59]);
          v179 = v178 + snprintf((char *)v11 + v178, 1000LL - v178, " %u:%u,", 7, a1[60]);
          v180 = v179 + snprintf((char *)v11 + v179, 1000LL - v179, " %u:%u,", 8, a1[61]);
          v181 = v180 + snprintf((char *)v11 + v180, 1000LL - v180, " %u:%u,", 9, a1[62]);
          v182 = v181 + snprintf((char *)v11 + v181, 1000LL - v181, " %u:%u,", 10, a1[63]);
          v183 = v182 + snprintf((char *)v11 + v182, 1000LL - v182, " %u:%u,", 11, a1[64]);
          v184 = snprintf((char *)v11 + v183, 1000LL - v183, " %u:%u,", 12, a1[370]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v183 + v184),
            1000LL - (unsigned __int16)(v183 + v184),
            " %u:%u,",
            13,
            a1[371]);
          DP_PRINT_STATS("tx_stbc = %s ", v185, v186, v187, v188, v189, v190, v191, v192, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v193 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[65]);
          v194 = v193 + snprintf((char *)v11 + v193, 1000LL - v193, " %u:%u,", 1, a1[66]);
          v195 = v194 + snprintf((char *)v11 + v194, 1000LL - v194, " %u:%u,", 2, a1[67]);
          v196 = v195 + snprintf((char *)v11 + v195, 1000LL - v195, " %u:%u,", 3, a1[68]);
          v197 = v196 + snprintf((char *)v11 + v196, 1000LL - v196, " %u:%u,", 4, a1[69]);
          v198 = snprintf((char *)v11 + v197, 1000LL - v197, " %u:%u,", 5, a1[70]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v197 + v198),
            1000LL - (unsigned __int16)(v197 + v198),
            " %u:%u,",
            6,
            a1[71]);
          DP_PRINT_STATS("tx_pream = %s ", v199, v200, v201, v202, v203, v204, v205, v206, v11);
          v207 = 0;
          v208 = (int *)(a1 + 83);
          do
          {
            v209 = (void *)*(&v596 + v207);
            v581 = v207;
            qdf_mem_set(v209, 0x3E8u, 0);
            v210 = snprintf((char *)v209, 0x3E8u, " %u:%u,", 0, *(v208 - 11));
            v211 = v210
                 + snprintf(
                     (char *)v209 + (unsigned __int16)v210,
                     1000LL - (unsigned __int16)v210,
                     " %u:%u,",
                     1,
                     *(v208 - 10));
            v212 = v211
                 + snprintf(
                     (char *)v209 + (unsigned __int16)v211,
                     1000LL - (unsigned __int16)v211,
                     " %u:%u,",
                     2,
                     *(v208 - 9));
            v213 = v212
                 + snprintf(
                     (char *)v209 + (unsigned __int16)v212,
                     1000LL - (unsigned __int16)v212,
                     " %u:%u,",
                     3,
                     *(v208 - 8));
            v214 = v213
                 + snprintf(
                     (char *)v209 + (unsigned __int16)v213,
                     1000LL - (unsigned __int16)v213,
                     " %u:%u,",
                     4,
                     *(v208 - 7));
            v215 = v214
                 + snprintf(
                     (char *)v209 + (unsigned __int16)v214,
                     1000LL - (unsigned __int16)v214,
                     " %u:%u,",
                     5,
                     *(v208 - 6));
            v216 = v215
                 + snprintf(
                     (char *)v209 + (unsigned __int16)v215,
                     1000LL - (unsigned __int16)v215,
                     " %u:%u,",
                     6,
                     *(v208 - 5));
            v217 = v216
                 + snprintf(
                     (char *)v209 + (unsigned __int16)v216,
                     1000LL - (unsigned __int16)v216,
                     " %u:%u,",
                     7,
                     *(v208 - 4));
            v218 = v217
                 + snprintf(
                     (char *)v209 + (unsigned __int16)v217,
                     1000LL - (unsigned __int16)v217,
                     " %u:%u,",
                     8,
                     *(v208 - 3));
            LOWORD(v218) = v218
                         + snprintf(
                             (char *)v209 + (unsigned __int16)v218,
                             1000LL - (unsigned __int16)v218,
                             " %u:%u,",
                             9,
                             *(v208 - 2));
            v219 = snprintf(
                     (char *)v209 + (unsigned __int16)v218,
                     1000LL - (unsigned __int16)v218,
                     " %u:%u,",
                     10,
                     *(v208 - 1));
            v220 = *v208;
            v208 += 12;
            snprintf(
              (char *)v209 + (unsigned __int16)(v218 + v219),
              1000LL - (unsigned __int16)(v218 + v219),
              " %u:%u,",
              11,
              v220);
            DP_PRINT_STATS("tx_gi[%u] = %s ", v221, v222, v223, v224, v225, v226, v227, v228, v581, v209);
            v207 = v581 + 1;
          }
          while ( v581 != 3 );
          qdf_mem_set(v22, 0x3E8u, 0);
          v229 = snprintf((char *)v22, 0x3E8u, " %u:%u,", 0, a1[372]);
          snprintf((char *)v22 + v229, 1000LL - v229, " %u:%u,", 1, a1[373]);
          DP_PRINT_STATS("tx_gi_ext[%u] = %s ", v230, v231, v232, v233, v234, v235, v236, v237, 0, v22);
          qdf_mem_set(v23, 0x3E8u, 0);
          v238 = snprintf((char *)v23, 0x3E8u, " %u:%u,", 0, a1[374]);
          snprintf((char *)v23 + v238, 1000LL - v238, " %u:%u,", 1, a1[375]);
          DP_PRINT_STATS("tx_gi_ext[%u] = %s ", v239, v240, v241, v242, v243, v244, v245, v246, 1, v23);
          qdf_mem_set(v24, 0x3E8u, 0);
          v247 = snprintf((char *)v24, 0x3E8u, " %u:%u,", 0, a1[376]);
          snprintf((char *)v24 + v247, 1000LL - v247, " %u:%u,", 1, a1[377]);
          DP_PRINT_STATS("tx_gi_ext[%u] = %s ", v248, v249, v250, v251, v252, v253, v254, v255, 2, v24);
          qdf_mem_set(v25, 0x3E8u, 0);
          v256 = snprintf((char *)v25, 0x3E8u, " %u:%u,", 0, a1[378]);
          snprintf((char *)v25 + v256, 1000LL - v256, " %u:%u,", 1, a1[379]);
          DP_PRINT_STATS("tx_gi_ext[%u] = %s ", v257, v258, v259, v260, v261, v262, v263, v264, 3, v25);
          qdf_mem_set(v11, 0x3E8u, 0);
          v265 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[120]);
          v266 = v265 + snprintf((char *)v11 + v265, 1000LL - v265, " %u:%u,", 1, a1[121]);
          v267 = v266 + snprintf((char *)v11 + v266, 1000LL - v266, " %u:%u,", 2, a1[122]);
          v268 = snprintf((char *)v11 + v267, 1000LL - v267, " %u:%u,", 3, a1[123]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v267 + v268),
            1000LL - (unsigned __int16)(v267 + v268),
            " %u:%u,",
            4,
            a1[124]);
          DP_PRINT_STATS("tx_dcm = %s", v269, v270, v271, v272, v273, v274, v275, v276, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v277 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[411]);
          v278 = v277 + snprintf((char *)v11 + v277, 1000LL - v277, " %u:%u,", 1, a1[412]);
          v279 = v278 + snprintf((char *)v11 + v278, 1000LL - v278, " %u:%u,", 2, a1[413]);
          v280 = snprintf((char *)v11 + v279, 1000LL - v279, " %u:%u,", 3, a1[414]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v279 + v280),
            1000LL - (unsigned __int16)(v279 + v280),
            " %u:%u,",
            4,
            a1[415]);
          DP_PRINT_STATS("tx_su_punctured_mode = %s\n", v281, v282, v283, v284, v285, v286, v287, v288, v11);
          DP_PRINT_STATS("rts_success = %u", v289, v290, v291, v292, v293, v294, v295, v296, a1[125]);
          DP_PRINT_STATS("ac_mu_mimo_tx_ldpc = %u", v297, v298, v299, v300, v301, v302, v303, v304, a1[138]);
          DP_PRINT_STATS("ax_mu_mimo_tx_ldpc = %u", v305, v306, v307, v308, v309, v310, v311, v312, a1[139]);
          DP_PRINT_STATS("ofdma_tx_ldpc = %u", v313, v314, v315, v316, v317, v318, v319, v320, a1[140]);
          qdf_mem_set(v11, 0x3E8u, 0);
          v321 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[126]);
          v322 = v321 + snprintf((char *)v11 + v321, 1000LL - v321, " %u:%u,", 1, a1[127]);
          v323 = snprintf((char *)v11 + v322, 1000LL - v322, " %u:%u,", 2, a1[128]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v322 + v323),
            1000LL - (unsigned __int16)(v322 + v323),
            " %u:%u,",
            3,
            a1[129]);
          DP_PRINT_STATS("tx_legacy_cck_rate = %s ", v324, v325, v326, v327, v328, v329, v330, v331, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v332 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[130]);
          v333 = v332 + snprintf((char *)v11 + v332, 1000LL - v332, " %u:%u,", 1, a1[131]);
          v334 = v333 + snprintf((char *)v11 + v333, 1000LL - v333, " %u:%u,", 2, a1[132]);
          v335 = v334 + snprintf((char *)v11 + v334, 1000LL - v334, " %u:%u,", 3, a1[133]);
          v336 = v335 + snprintf((char *)v11 + v335, 1000LL - v335, " %u:%u,", 4, a1[134]);
          v337 = v336 + snprintf((char *)v11 + v336, 1000LL - v336, " %u:%u,", 5, a1[135]);
          v338 = snprintf((char *)v11 + v337, 1000LL - v337, " %u:%u,", 6, a1[136]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v337 + v338),
            1000LL - (unsigned __int16)(v337 + v338),
            " %u:%u,",
            7,
            a1[137]);
          DP_PRINT_STATS("tx_legacy_ofdm_rate = %s ", v339, v340, v341, v342, v343, v344, v345, v346, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v347 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[141]);
          v348 = v347 + snprintf((char *)v11 + v347, 1000LL - v347, " %u:%u,", 1, a1[142]);
          v349 = v348 + snprintf((char *)v11 + v348, 1000LL - v348, " %u:%u,", 2, a1[143]);
          v350 = v349 + snprintf((char *)v11 + v349, 1000LL - v349, " %u:%u,", 3, a1[144]);
          DP_PRINT_STATS("tx_he_ltf = %s ", v351, v352, v353, v354, v355, v356, v357, v358, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v359 = v350 + snprintf((char *)v11 + v350, 1000LL - v350, " %u:%u,", 0, a1[169]);
          v360 = v359 + snprintf((char *)v11 + v359, 1000LL - v359, " %u:%u,", 1, a1[170]);
          v361 = v360 + snprintf((char *)v11 + v360, 1000LL - v360, " %u:%u,", 2, a1[171]);
          v362 = v361 + snprintf((char *)v11 + v361, 1000LL - v361, " %u:%u,", 3, a1[172]);
          v363 = v362 + snprintf((char *)v11 + v362, 1000LL - v362, " %u:%u,", 4, a1[173]);
          v364 = v363 + snprintf((char *)v11 + v363, 1000LL - v363, " %u:%u,", 5, a1[174]);
          v365 = v364 + snprintf((char *)v11 + v364, 1000LL - v364, " %u:%u,", 6, a1[175]);
          v366 = v365 + snprintf((char *)v11 + v365, 1000LL - v365, " %u:%u,", 7, a1[176]);
          v367 = v366 + snprintf((char *)v11 + v366, 1000LL - v366, " %u:%u,", 8, a1[177]);
          v368 = v367 + snprintf((char *)v11 + v367, 1000LL - v367, " %u:%u,", 9, a1[178]);
          v369 = snprintf((char *)v11 + v368, 1000LL - v368, " %u:%u,", 10, a1[179]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v368 + v369),
            1000LL - (unsigned __int16)(v368 + v369),
            " %u:%u,",
            11,
            a1[180]);
          DP_PRINT_STATS("ofdma_tx_mcs = %s ", v370, v371, v372, v373, v374, v375, v376, v377, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v378 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[145]);
          v379 = v378 + snprintf((char *)v11 + v378, 1000LL - v378, " %u:%u,", 1, a1[146]);
          v380 = v379 + snprintf((char *)v11 + v379, 1000LL - v379, " %u:%u,", 2, a1[147]);
          v381 = v380 + snprintf((char *)v11 + v380, 1000LL - v380, " %u:%u,", 3, a1[148]);
          v382 = v381 + snprintf((char *)v11 + v381, 1000LL - v381, " %u:%u,", 4, a1[149]);
          v383 = v382 + snprintf((char *)v11 + v382, 1000LL - v382, " %u:%u,", 5, a1[150]);
          v384 = v383 + snprintf((char *)v11 + v383, 1000LL - v383, " %u:%u,", 6, a1[151]);
          v385 = v384 + snprintf((char *)v11 + v384, 1000LL - v384, " %u:%u,", 7, a1[152]);
          v386 = v385 + snprintf((char *)v11 + v385, 1000LL - v385, " %u:%u,", 8, a1[153]);
          v387 = v386 + snprintf((char *)v11 + v386, 1000LL - v386, " %u:%u,", 9, a1[154]);
          v388 = snprintf((char *)v11 + v387, 1000LL - v387, " %u:%u,", 10, a1[155]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v387 + v388),
            1000LL - (unsigned __int16)(v387 + v388),
            " %u:%u,",
            11,
            a1[156]);
          DP_PRINT_STATS("ac_mu_mimo_tx_mcs = %s ", v389, v390, v391, v392, v393, v394, v395, v396, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v397 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[157]);
          v398 = v397 + snprintf((char *)v11 + v397, 1000LL - v397, " %u:%u,", 1, a1[158]);
          v399 = v398 + snprintf((char *)v11 + v398, 1000LL - v398, " %u:%u,", 2, a1[159]);
          v400 = v399 + snprintf((char *)v11 + v399, 1000LL - v399, " %u:%u,", 3, a1[160]);
          v401 = v400 + snprintf((char *)v11 + v400, 1000LL - v400, " %u:%u,", 4, a1[161]);
          v402 = v401 + snprintf((char *)v11 + v401, 1000LL - v401, " %u:%u,", 5, a1[162]);
          v403 = v402 + snprintf((char *)v11 + v402, 1000LL - v402, " %u:%u,", 6, a1[163]);
          v404 = v403 + snprintf((char *)v11 + v403, 1000LL - v403, " %u:%u,", 7, a1[164]);
          v405 = v404 + snprintf((char *)v11 + v404, 1000LL - v404, " %u:%u,", 8, a1[165]);
          v406 = v405 + snprintf((char *)v11 + v405, 1000LL - v405, " %u:%u,", 9, a1[166]);
          v407 = snprintf((char *)v11 + v406, 1000LL - v406, " %u:%u,", 10, a1[167]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v406 + v407),
            1000LL - (unsigned __int16)(v406 + v407),
            " %u:%u,",
            11,
            a1[168]);
          DP_PRINT_STATS("ax_mu_mimo_tx_mcs = %s ", v408, v409, v410, v411, v412, v413, v414, v415, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v416 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[169]);
          v417 = v416 + snprintf((char *)v11 + v416, 1000LL - v416, " %u:%u,", 1, a1[170]);
          v418 = v417 + snprintf((char *)v11 + v417, 1000LL - v417, " %u:%u,", 2, a1[171]);
          v419 = v418 + snprintf((char *)v11 + v418, 1000LL - v418, " %u:%u,", 3, a1[172]);
          v420 = v419 + snprintf((char *)v11 + v419, 1000LL - v419, " %u:%u,", 4, a1[173]);
          v421 = v420 + snprintf((char *)v11 + v420, 1000LL - v420, " %u:%u,", 5, a1[174]);
          v422 = v421 + snprintf((char *)v11 + v421, 1000LL - v421, " %u:%u,", 6, a1[175]);
          v423 = v422 + snprintf((char *)v11 + v422, 1000LL - v422, " %u:%u,", 7, a1[176]);
          v424 = v423 + snprintf((char *)v11 + v423, 1000LL - v423, " %u:%u,", 8, a1[177]);
          v425 = v424 + snprintf((char *)v11 + v424, 1000LL - v424, " %u:%u,", 9, a1[178]);
          v426 = snprintf((char *)v11 + v425, 1000LL - v425, " %u:%u,", 10, a1[179]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v425 + v426),
            1000LL - (unsigned __int16)(v425 + v426),
            " %u:%u,",
            11,
            a1[180]);
          DP_PRINT_STATS("ofdma_tx_mcs = %s ", v427, v428, v429, v430, v431, v432, v433, v434, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v435 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[181]);
          v436 = v435 + snprintf((char *)v11 + v435, 1000LL - v435, " %u:%u,", 1, a1[182]);
          v437 = v436 + snprintf((char *)v11 + v436, 1000LL - v436, " %u:%u,", 2, a1[183]);
          v438 = v437 + snprintf((char *)v11 + v437, 1000LL - v437, " %u:%u,", 3, a1[184]);
          v439 = v438 + snprintf((char *)v11 + v438, 1000LL - v438, " %u:%u,", 4, a1[185]);
          v440 = v439 + snprintf((char *)v11 + v439, 1000LL - v439, " %u:%u,", 5, a1[186]);
          v441 = snprintf((char *)v11 + v440, 1000LL - v440, " %u:%u,", 6, a1[187]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v440 + v441),
            1000LL - (unsigned __int16)(v440 + v441),
            " %u:%u,",
            7,
            a1[188]);
          DP_PRINT_STATS("ac_mu_mimo_tx_nss = %s ", v442, v443, v444, v445, v446, v447, v448, v449, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v450 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[189]);
          v451 = v450 + snprintf((char *)v11 + v450, 1000LL - v450, " %u:%u,", 1, a1[190]);
          v452 = v451 + snprintf((char *)v11 + v451, 1000LL - v451, " %u:%u,", 2, a1[191]);
          v453 = v452 + snprintf((char *)v11 + v452, 1000LL - v452, " %u:%u,", 3, a1[192]);
          v454 = v453 + snprintf((char *)v11 + v453, 1000LL - v453, " %u:%u,", 4, a1[193]);
          v455 = v454 + snprintf((char *)v11 + v454, 1000LL - v454, " %u:%u,", 5, a1[194]);
          v456 = snprintf((char *)v11 + v455, 1000LL - v455, " %u:%u,", 6, a1[195]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v455 + v456),
            1000LL - (unsigned __int16)(v455 + v456),
            " %u:%u,",
            7,
            a1[196]);
          DP_PRINT_STATS("ax_mu_mimo_tx_nss = %s ", v457, v458, v459, v460, v461, v462, v463, v464, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v465 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[197]);
          v466 = v465 + snprintf((char *)v11 + v465, 1000LL - v465, " %u:%u,", 1, a1[198]);
          v467 = v466 + snprintf((char *)v11 + v466, 1000LL - v466, " %u:%u,", 2, a1[199]);
          v468 = v467 + snprintf((char *)v11 + v467, 1000LL - v467, " %u:%u,", 3, a1[200]);
          v469 = v468 + snprintf((char *)v11 + v468, 1000LL - v468, " %u:%u,", 4, a1[201]);
          v470 = v469 + snprintf((char *)v11 + v469, 1000LL - v469, " %u:%u,", 5, a1[202]);
          v471 = snprintf((char *)v11 + v470, 1000LL - v470, " %u:%u,", 6, a1[203]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v470 + v471),
            1000LL - (unsigned __int16)(v470 + v471),
            " %u:%u,",
            7,
            a1[204]);
          DP_PRINT_STATS("ofdma_tx_nss = %s ", v472, v473, v474, v475, v476, v477, v478, v479, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v480 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[205]);
          v481 = v480 + snprintf((char *)v11 + v480, 1000LL - v480, " %u:%u,", 1, a1[206]);
          v482 = snprintf((char *)v11 + v481, 1000LL - v481, " %u:%u,", 2, a1[207]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v481 + v482),
            1000LL - (unsigned __int16)(v481 + v482),
            " %u:%u,",
            3,
            a1[208]);
          DP_PRINT_STATS("ac_mu_mimo_tx_bw = %s ", v483, v484, v485, v486, v487, v488, v489, v490, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v491 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[209]);
          v492 = v491 + snprintf((char *)v11 + v491, 1000LL - v491, " %u:%u,", 1, a1[210]);
          v493 = snprintf((char *)v11 + v492, 1000LL - v492, " %u:%u,", 2, a1[211]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v492 + v493),
            1000LL - (unsigned __int16)(v492 + v493),
            " %u:%u,",
            3,
            a1[212]);
          DP_PRINT_STATS("ax_mu_mimo_tx_bw = %s ", v494, v495, v496, v497, v498, v499, v500, v501, v11);
          qdf_mem_set(v11, 0x3E8u, 0);
          v502 = snprintf((char *)v11, 0x3E8u, " %u:%u,", 0, a1[213]);
          v503 = v502 + snprintf((char *)v11 + v502, 1000LL - v502, " %u:%u,", 1, a1[214]);
          v504 = snprintf((char *)v11 + v503, 1000LL - v503, " %u:%u,", 2, a1[215]);
          snprintf(
            (char *)v11 + (unsigned __int16)(v503 + v504),
            1000LL - (unsigned __int16)(v503 + v504),
            " %u:%u,",
            3,
            a1[216]);
          DP_PRINT_STATS("ofdma_tx_bw = %s ", v505, v506, v507, v508, v509, v510, v511, v512, v11);
          v513 = 0;
          v514 = (int *)(a1 + 228);
          do
          {
            v515 = (void *)*(&v592 + v513);
            v582 = v513;
            qdf_mem_set(v515, 0x3E8u, 0);
            v516 = snprintf((char *)v515, 0x3E8u, " %u:%u,", 0, *(v514 - 11));
            v517 = v516
                 + snprintf(
                     (char *)v515 + (unsigned __int16)v516,
                     1000LL - (unsigned __int16)v516,
                     " %u:%u,",
                     1,
                     *(v514 - 10));
            v518 = v517
                 + snprintf(
                     (char *)v515 + (unsigned __int16)v517,
                     1000LL - (unsigned __int16)v517,
                     " %u:%u,",
                     2,
                     *(v514 - 9));
            v519 = v518
                 + snprintf(
                     (char *)v515 + (unsigned __int16)v518,
                     1000LL - (unsigned __int16)v518,
                     " %u:%u,",
                     3,
                     *(v514 - 8));
            v520 = v519
                 + snprintf(
                     (char *)v515 + (unsigned __int16)v519,
                     1000LL - (unsigned __int16)v519,
                     " %u:%u,",
                     4,
                     *(v514 - 7));
            v521 = v520
                 + snprintf(
                     (char *)v515 + (unsigned __int16)v520,
                     1000LL - (unsigned __int16)v520,
                     " %u:%u,",
                     5,
                     *(v514 - 6));
            v522 = v521
                 + snprintf(
                     (char *)v515 + (unsigned __int16)v521,
                     1000LL - (unsigned __int16)v521,
                     " %u:%u,",
                     6,
                     *(v514 - 5));
            v523 = v522
                 + snprintf(
                     (char *)v515 + (unsigned __int16)v522,
                     1000LL - (unsigned __int16)v522,
                     " %u:%u,",
                     7,
                     *(v514 - 4));
            v524 = v523
                 + snprintf(
                     (char *)v515 + (unsigned __int16)v523,
                     1000LL - (unsigned __int16)v523,
                     " %u:%u,",
                     8,
                     *(v514 - 3));
            LOWORD(v524) = v524
                         + snprintf(
                             (char *)v515 + (unsigned __int16)v524,
                             1000LL - (unsigned __int16)v524,
                             " %u:%u,",
                             9,
                             *(v514 - 2));
            v525 = snprintf(
                     (char *)v515 + (unsigned __int16)v524,
                     1000LL - (unsigned __int16)v524,
                     " %u:%u,",
                     10,
                     *(v514 - 1));
            v526 = *v514;
            v514 += 12;
            snprintf(
              (char *)v515 + (unsigned __int16)(v524 + v525),
              1000LL - (unsigned __int16)(v524 + v525),
              " %u:%u,",
              11,
              v526);
            DP_PRINT_STATS("ac_mu_mimo_tx_gi[%u] = %s ", v527, v528, v529, v530, v531, v532, v533, v534, v582, v515);
            v513 = v582 + 1;
          }
          while ( v582 != 3 );
          v535 = 0;
          v536 = (int *)(a1 + 276);
          do
          {
            v537 = (void *)*(&v588 + v535);
            v583 = v535;
            qdf_mem_set(v537, 0x3E8u, 0);
            v538 = snprintf((char *)v537, 0x3E8u, " %u:%u,", 0, *(v536 - 11));
            v539 = v538
                 + snprintf(
                     (char *)v537 + (unsigned __int16)v538,
                     1000LL - (unsigned __int16)v538,
                     " %u:%u,",
                     1,
                     *(v536 - 10));
            v540 = v539
                 + snprintf(
                     (char *)v537 + (unsigned __int16)v539,
                     1000LL - (unsigned __int16)v539,
                     " %u:%u,",
                     2,
                     *(v536 - 9));
            v541 = v540
                 + snprintf(
                     (char *)v537 + (unsigned __int16)v540,
                     1000LL - (unsigned __int16)v540,
                     " %u:%u,",
                     3,
                     *(v536 - 8));
            v542 = v541
                 + snprintf(
                     (char *)v537 + (unsigned __int16)v541,
                     1000LL - (unsigned __int16)v541,
                     " %u:%u,",
                     4,
                     *(v536 - 7));
            v543 = v542
                 + snprintf(
                     (char *)v537 + (unsigned __int16)v542,
                     1000LL - (unsigned __int16)v542,
                     " %u:%u,",
                     5,
                     *(v536 - 6));
            v544 = v543
                 + snprintf(
                     (char *)v537 + (unsigned __int16)v543,
                     1000LL - (unsigned __int16)v543,
                     " %u:%u,",
                     6,
                     *(v536 - 5));
            v545 = v544
                 + snprintf(
                     (char *)v537 + (unsigned __int16)v544,
                     1000LL - (unsigned __int16)v544,
                     " %u:%u,",
                     7,
                     *(v536 - 4));
            v546 = v545
                 + snprintf(
                     (char *)v537 + (unsigned __int16)v545,
                     1000LL - (unsigned __int16)v545,
                     " %u:%u,",
                     8,
                     *(v536 - 3));
            LOWORD(v546) = v546
                         + snprintf(
                             (char *)v537 + (unsigned __int16)v546,
                             1000LL - (unsigned __int16)v546,
                             " %u:%u,",
                             9,
                             *(v536 - 2));
            v547 = snprintf(
                     (char *)v537 + (unsigned __int16)v546,
                     1000LL - (unsigned __int16)v546,
                     " %u:%u,",
                     10,
                     *(v536 - 1));
            v548 = *v536;
            v536 += 12;
            snprintf(
              (char *)v537 + (unsigned __int16)(v546 + v547),
              1000LL - (unsigned __int16)(v546 + v547),
              " %u:%u,",
              11,
              v548);
            DP_PRINT_STATS("ax_mu_mimo_tx_gi[%u] = %s ", v549, v550, v551, v552, v553, v554, v555, v556, v583, v537);
            v535 = v583 + 1;
          }
          while ( v583 != 3 );
          v557 = 0;
          v558 = (int *)(a1 + 324);
          do
          {
            v559 = (void *)*(&v584 + v557);
            qdf_mem_set(v559, 0x3E8u, 0);
            v560 = snprintf((char *)v559, 0x3E8u, " %u:%u,", 0, *(v558 - 11));
            v561 = v560
                 + snprintf(
                     (char *)v559 + (unsigned __int16)v560,
                     1000LL - (unsigned __int16)v560,
                     " %u:%u,",
                     1,
                     *(v558 - 10));
            v562 = v561
                 + snprintf(
                     (char *)v559 + (unsigned __int16)v561,
                     1000LL - (unsigned __int16)v561,
                     " %u:%u,",
                     2,
                     *(v558 - 9));
            v563 = v562
                 + snprintf(
                     (char *)v559 + (unsigned __int16)v562,
                     1000LL - (unsigned __int16)v562,
                     " %u:%u,",
                     3,
                     *(v558 - 8));
            v564 = v563
                 + snprintf(
                     (char *)v559 + (unsigned __int16)v563,
                     1000LL - (unsigned __int16)v563,
                     " %u:%u,",
                     4,
                     *(v558 - 7));
            v565 = v564
                 + snprintf(
                     (char *)v559 + (unsigned __int16)v564,
                     1000LL - (unsigned __int16)v564,
                     " %u:%u,",
                     5,
                     *(v558 - 6));
            v566 = v565
                 + snprintf(
                     (char *)v559 + (unsigned __int16)v565,
                     1000LL - (unsigned __int16)v565,
                     " %u:%u,",
                     6,
                     *(v558 - 5));
            v567 = v566
                 + snprintf(
                     (char *)v559 + (unsigned __int16)v566,
                     1000LL - (unsigned __int16)v566,
                     " %u:%u,",
                     7,
                     *(v558 - 4));
            v568 = v567
                 + snprintf(
                     (char *)v559 + (unsigned __int16)v567,
                     1000LL - (unsigned __int16)v567,
                     " %u:%u,",
                     8,
                     *(v558 - 3));
            LOWORD(v568) = v568
                         + snprintf(
                             (char *)v559 + (unsigned __int16)v568,
                             1000LL - (unsigned __int16)v568,
                             " %u:%u,",
                             9,
                             *(v558 - 2));
            v569 = snprintf(
                     (char *)v559 + (unsigned __int16)v568,
                     1000LL - (unsigned __int16)v568,
                     " %u:%u,",
                     10,
                     *(v558 - 1));
            v570 = *v558;
            v558 += 12;
            snprintf(
              (char *)v559 + (unsigned __int16)(v568 + v569),
              1000LL - (unsigned __int16)(v568 + v569),
              " %u:%u,",
              11,
              v570);
            DP_PRINT_STATS(
              "ofdma_tx_gi[%u] = %s ",
              v571,
              v572,
              v573,
              v574,
              v575,
              v576,
              v577,
              v578,
              (unsigned int)v557++,
              v559);
          }
          while ( v557 != 4 );
          v12 = v596;
          if ( !v596 )
            goto LABEL_43;
          goto LABEL_42;
        }
        goto LABEL_38;
      }
      goto LABEL_36;
    }
LABEL_34:
    v580 = "%s: Unable to allocate buffer for ac_mu_mimo_tx_gi";
LABEL_39:
    qdf_trace_msg(0x45u, 2u, v580, v26, v27, v28, v29, v30, v31, v32, v33, "dp_print_tx_pdev_rate_stats_tlv");
LABEL_42:
    _qdf_mem_free(v12);
    goto LABEL_43;
  }
LABEL_41:
  qdf_trace_msg(
    0x45u,
    2u,
    "%s: Unable to allocate buffer for tx_gi",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "dp_print_tx_pdev_rate_stats_tlv");
  if ( v12 )
    goto LABEL_42;
LABEL_43:
  if ( v22 )
    _qdf_mem_free((__int64)v22);
  if ( v592 )
    _qdf_mem_free(v592);
  if ( v588 )
    _qdf_mem_free(v588);
  if ( v584 )
    _qdf_mem_free(v584);
  if ( v597 )
    _qdf_mem_free(v597);
  if ( v23 )
    _qdf_mem_free((__int64)v23);
  if ( v593 )
    _qdf_mem_free(v593);
  if ( v589 )
    _qdf_mem_free(v589);
  if ( v585 )
    _qdf_mem_free(v585);
  if ( v598 )
    _qdf_mem_free(v598);
  if ( v24 )
    _qdf_mem_free((__int64)v24);
  if ( v594 )
    _qdf_mem_free(v594);
  if ( v590 )
    _qdf_mem_free(v590);
  if ( v586 )
    _qdf_mem_free(v586);
  if ( v599 )
    _qdf_mem_free(v599);
  if ( v25 )
    _qdf_mem_free((__int64)v25);
  if ( v595 )
    _qdf_mem_free(v595);
  if ( v591 )
    _qdf_mem_free(v591);
  if ( v587 )
    _qdf_mem_free(v587);
  result = _qdf_mem_free((__int64)v11);
LABEL_82:
  _ReadStatusReg(SP_EL0);
  return result;
}
