__int64 __fastcall dp_print_soc_cfg_params(
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
  unsigned int *v9; // x19
  unsigned int num_contexts; // w20
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
  unsigned __int64 v243; // x23
  unsigned __int8 v244; // w24
  char v245; // w0
  double v246; // d0
  double v247; // d1
  double v248; // d2
  double v249; // d3
  double v250; // d4
  double v251; // d5
  double v252; // d6
  double v253; // d7
  unsigned __int64 v254; // x24
  unsigned __int8 v255; // w25
  char v256; // w0
  double v257; // d0
  double v258; // d1
  double v259; // d2
  double v260; // d3
  double v261; // d4
  double v262; // d5
  double v263; // d6
  double v264; // d7
  unsigned __int64 v265; // x24
  unsigned __int8 v266; // w25
  char v267; // w0
  double v268; // d0
  double v269; // d1
  double v270; // d2
  double v271; // d3
  double v272; // d4
  double v273; // d5
  double v274; // d6
  double v275; // d7
  unsigned __int64 v276; // x24
  unsigned __int8 v277; // w25
  char v278; // w0
  double v279; // d0
  double v280; // d1
  double v281; // d2
  double v282; // d3
  double v283; // d4
  double v284; // d5
  double v285; // d6
  double v286; // d7
  unsigned __int64 v287; // x24
  unsigned __int8 v288; // w25
  char v289; // w0
  double v290; // d0
  double v291; // d1
  double v292; // d2
  double v293; // d3
  double v294; // d4
  double v295; // d5
  double v296; // d6
  double v297; // d7
  unsigned __int64 v298; // x24
  unsigned __int8 v299; // w25
  char v300; // w0
  double v301; // d0
  double v302; // d1
  double v303; // d2
  double v304; // d3
  double v305; // d4
  double v306; // d5
  double v307; // d6
  double v308; // d7
  unsigned __int64 v309; // x24
  unsigned __int8 v310; // w25
  char v311; // w0
  double v312; // d0
  double v313; // d1
  double v314; // d2
  double v315; // d3
  double v316; // d4
  double v317; // d5
  double v318; // d6
  double v319; // d7
  unsigned __int64 v320; // x24
  unsigned __int8 v321; // w25
  char v322; // w0
  double v323; // d0
  double v324; // d1
  double v325; // d2
  double v326; // d3
  double v327; // d4
  double v328; // d5
  double v329; // d6
  double v330; // d7
  __int64 result; // x0
  double v332; // d0
  double v333; // d1
  double v334; // d2
  double v335; // d3
  double v336; // d4
  double v337; // d5
  double v338; // d6
  double v339; // d7
  double v340; // d0
  double v341; // d1
  double v342; // d2
  double v343; // d3
  double v344; // d4
  double v345; // d5
  double v346; // d6
  double v347; // d7
  double v348; // d0
  double v349; // d1
  double v350; // d2
  double v351; // d3
  double v352; // d4
  double v353; // d5
  double v354; // d6
  double v355; // d7
  double v356; // d0
  double v357; // d1
  double v358; // d2
  double v359; // d3
  double v360; // d4
  double v361; // d5
  double v362; // d6
  double v363; // d7
  double v364; // d0
  double v365; // d1
  double v366; // d2
  double v367; // d3
  double v368; // d4
  double v369; // d5
  double v370; // d6
  double v371; // d7
  double v372; // d0
  double v373; // d1
  double v374; // d2
  double v375; // d3
  double v376; // d4
  double v377; // d5
  double v378; // d6
  double v379; // d7
  double v380; // d0
  double v381; // d1
  double v382; // d2
  double v383; // d3
  double v384; // d4
  double v385; // d5
  double v386; // d6
  double v387; // d7
  double v388; // d0
  double v389; // d1
  double v390; // d2
  double v391; // d3
  double v392; // d4
  double v393; // d5
  double v394; // d6
  double v395; // d7
  double v396; // d0
  double v397; // d1
  double v398; // d2
  double v399; // d3
  double v400; // d4
  double v401; // d5
  double v402; // d6
  double v403; // d7
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
  double v420; // d0
  double v421; // d1
  double v422; // d2
  double v423; // d3
  double v424; // d4
  double v425; // d5
  double v426; // d6
  double v427; // d7
  double v428; // d0
  double v429; // d1
  double v430; // d2
  double v431; // d3
  double v432; // d4
  double v433; // d5
  double v434; // d6
  double v435; // d7
  double v436; // d0
  double v437; // d1
  double v438; // d2
  double v439; // d3
  double v440; // d4
  double v441; // d5
  double v442; // d6
  double v443; // d7
  double v444; // d0
  double v445; // d1
  double v446; // d2
  double v447; // d3
  double v448; // d4
  double v449; // d5
  double v450; // d6
  double v451; // d7
  double v452; // d0
  double v453; // d1
  double v454; // d2
  double v455; // d3
  double v456; // d4
  double v457; // d5
  double v458; // d6
  double v459; // d7
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
  double v484; // d0
  double v485; // d1
  double v486; // d2
  double v487; // d3
  double v488; // d4
  double v489; // d5
  double v490; // d6
  double v491; // d7
  double v492; // d0
  double v493; // d1
  double v494; // d2
  double v495; // d3
  double v496; // d4
  double v497; // d5
  double v498; // d6
  double v499; // d7
  double v500; // d0
  double v501; // d1
  double v502; // d2
  double v503; // d3
  double v504; // d4
  double v505; // d5
  double v506; // d6
  double v507; // d7
  double v508; // d0
  double v509; // d1
  double v510; // d2
  double v511; // d3
  double v512; // d4
  double v513; // d5
  double v514; // d6
  double v515; // d7
  double v516; // d0
  double v517; // d1
  double v518; // d2
  double v519; // d3
  double v520; // d4
  double v521; // d5
  double v522; // d6
  double v523; // d7
  double v524; // d0
  double v525; // d1
  double v526; // d2
  double v527; // d3
  double v528; // d4
  double v529; // d5
  double v530; // d6
  double v531; // d7
  double v532; // d0
  double v533; // d1
  double v534; // d2
  double v535; // d3
  double v536; // d4
  double v537; // d5
  double v538; // d6
  double v539; // d7
  double v540; // d0
  double v541; // d1
  double v542; // d2
  double v543; // d3
  double v544; // d4
  double v545; // d5
  double v546; // d6
  double v547; // d7
  double v548; // d0
  double v549; // d1
  double v550; // d2
  double v551; // d3
  double v552; // d4
  double v553; // d5
  double v554; // d6
  double v555; // d7
  double v556; // d0
  double v557; // d1
  double v558; // d2
  double v559; // d3
  double v560; // d4
  double v561; // d5
  double v562; // d6
  double v563; // d7
  double v564; // d0
  double v565; // d1
  double v566; // d2
  double v567; // d3
  double v568; // d4
  double v569; // d5
  double v570; // d6
  double v571; // d7
  double v572; // d0
  double v573; // d1
  double v574; // d2
  double v575; // d3
  double v576; // d4
  double v577; // d5
  double v578; // d6
  double v579; // d7
  double v580; // d0
  double v581; // d1
  double v582; // d2
  double v583; // d3
  double v584; // d4
  double v585; // d5
  double v586; // d6
  double v587; // d7
  double v588; // d0
  double v589; // d1
  double v590; // d2
  double v591; // d3
  double v592; // d4
  double v593; // d5
  double v594; // d6
  double v595; // d7
  double v596; // d0
  double v597; // d1
  double v598; // d2
  double v599; // d3
  double v600; // d4
  double v601; // d5
  double v602; // d6
  double v603; // d7
  double v604; // d0
  double v605; // d1
  double v606; // d2
  double v607; // d3
  double v608; // d4
  double v609; // d5
  double v610; // d6
  double v611; // d7
  double v612; // d0
  double v613; // d1
  double v614; // d2
  double v615; // d3
  double v616; // d4
  double v617; // d5
  double v618; // d6
  double v619; // d7
  double v620; // d0
  double v621; // d1
  double v622; // d2
  double v623; // d3
  double v624; // d4
  double v625; // d5
  double v626; // d6
  double v627; // d7
  double v628; // d0
  double v629; // d1
  double v630; // d2
  double v631; // d3
  double v632; // d4
  double v633; // d5
  double v634; // d6
  double v635; // d7
  double v636; // d0
  double v637; // d1
  double v638; // d2
  double v639; // d3
  double v640; // d4
  double v641; // d5
  double v642; // d6
  double v643; // d7
  double v644; // d0
  double v645; // d1
  double v646; // d2
  double v647; // d3
  double v648; // d4
  double v649; // d5
  double v650; // d6
  double v651; // d7
  double v652; // d0
  double v653; // d1
  double v654; // d2
  double v655; // d3
  double v656; // d4
  double v657; // d5
  double v658; // d6
  double v659; // d7
  double v660; // d0
  double v661; // d1
  double v662; // d2
  double v663; // d3
  double v664; // d4
  double v665; // d5
  double v666; // d6
  double v667; // d7
  double v668; // d0
  double v669; // d1
  double v670; // d2
  double v671; // d3
  double v672; // d4
  double v673; // d5
  double v674; // d6
  double v675; // d7
  double v676; // d0
  double v677; // d1
  double v678; // d2
  double v679; // d3
  double v680; // d4
  double v681; // d5
  double v682; // d6
  double v683; // d7
  double v684; // d0
  double v685; // d1
  double v686; // d2
  double v687; // d3
  double v688; // d4
  double v689; // d5
  double v690; // d6
  double v691; // d7
  _QWORD v692[13]; // [xsp+8h] [xbp-78h] BYREF
  int v693; // [xsp+70h] [xbp-10h]
  __int64 v694; // [xsp+78h] [xbp-8h]

  v694 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v693 = 0;
  memset(v692, 0, sizeof(v692));
  if ( a1 && (v9 = *(unsigned int **)(a1 + 40)) != nullptr )
  {
    num_contexts = wlan_cfg_get_num_contexts(*(_QWORD *)(a1 + 40));
    DP_PRINT_STATS("No. of interrupt contexts: %u", v11, v12, v13, v14, v15, v16, v17, v18, *v9);
    DP_PRINT_STATS("Max clients: %u", v19, v20, v21, v22, v23, v24, v25, v26, v9[1]);
    DP_PRINT_STATS("Max alloc size: %u ", v27, v28, v29, v30, v31, v32, v33, v34, v9[2]);
    DP_PRINT_STATS("Per pdev tx ring: %u ", v35, v36, v37, v38, v39, v40, v41, v42, v9[3]);
    DP_PRINT_STATS("Num tcl data rings: %u ", v43, v44, v45, v46, v47, v48, v49, v50, v9[5]);
    DP_PRINT_STATS("Per pdev rx ring: %u ", v51, v52, v53, v54, v55, v56, v57, v58, v9[7]);
    DP_PRINT_STATS("Per pdev lmac ring: %u ", v59, v60, v61, v62, v63, v64, v65, v66, v9[8]);
    DP_PRINT_STATS("Num of reo dest rings: %u ", v67, v68, v69, v70, v71, v72, v73, v74, v9[9]);
    DP_PRINT_STATS("Num tx desc pool: %u ", v75, v76, v77, v78, v79, v80, v81, v82, v9[11]);
    DP_PRINT_STATS("Num tx ext desc pool: %u ", v83, v84, v85, v86, v87, v88, v89, v90, v9[12]);
    DP_PRINT_STATS("Num tx desc pool: %u ", v91, v92, v93, v94, v95, v96, v97, v98, v9[15]);
    DP_PRINT_STATS("Num tx ext desc: %u ", v99, v100, v101, v102, v103, v104, v105, v106, v9[18]);
    DP_PRINT_STATS("Htt packet type: %u ", v107, v108, v109, v110, v111, v112, v113, v114, v9[20]);
    DP_PRINT_STATS("Max peer_ids: %u ", v115, v116, v117, v118, v119, v120, v121, v122, v9[19]);
    DP_PRINT_STATS("Tx ring size: %u ", v123, v124, v125, v126, v127, v128, v129, v130, v9[34]);
    DP_PRINT_STATS("Tx comp ring size: %u ", v131, v132, v133, v134, v135, v136, v137, v138, v9[35]);
    DP_PRINT_STATS("Tx comp ring size nss: %u ", v139, v140, v141, v142, v143, v144, v145, v146, v9[37]);
    DP_PRINT_STATS("Int batch threshold tx: %u ", v147, v148, v149, v150, v151, v152, v153, v154, v9[23]);
    DP_PRINT_STATS("Int timer threshold tx: %u ", v155, v156, v157, v158, v159, v160, v161, v162, v9[24]);
    DP_PRINT_STATS("Int batch threshold rx: %u ", v163, v164, v165, v166, v167, v168, v169, v170, v9[25]);
    DP_PRINT_STATS("Int timer threshold rx: %u ", v171, v172, v173, v174, v175, v176, v177, v178, v9[26]);
    DP_PRINT_STATS("Int batch threshold other: %u ", v179, v180, v181, v182, v183, v184, v185, v186, v9[27]);
    DP_PRINT_STATS("Int timer threshold other: %u ", v187, v188, v189, v190, v191, v192, v193, v194, v9[28]);
    DP_PRINT_STATS("Int batch threshold mon dest: %u ", v195, v196, v197, v198, v199, v200, v201, v202, v9[29]);
    DP_PRINT_STATS("Int timer threshold mon dest: %u ", v203, v204, v205, v206, v207, v208, v209, v210, v9[30]);
    DP_PRINT_STATS("Int batch threshold ppe2tcl: %u ", v211, v212, v213, v214, v215, v216, v217, v218, v9[21]);
    DP_PRINT_STATS("Int timer threshold ppe2tcl: %u ", v219, v220, v221, v222, v223, v224, v225, v226, v9[22]);
    DP_PRINT_STATS(
      "DP NAPI scale factor: %u ",
      v227,
      v228,
      v229,
      v230,
      v231,
      v232,
      v233,
      v234,
      *((unsigned __int8 *)v9 + 811));
    if ( (int)num_contexts > 0 )
    {
      v243 = 0;
      v244 = 0;
      do
      {
        if ( v244 > 0x6Cu || v243 >= 0x12 )
          goto LABEL_41;
        v245 = snprintf((char *)v692 + v244, 108LL - v244, " %d", *((unsigned __int8 *)v9 + v243++ + 152));
        v244 += v245;
      }
      while ( num_contexts != v243 );
      DP_PRINT_STATS("Tx ring mask (0-%d):%s", v246, v247, v248, v249, v250, v251, v252, v253, num_contexts, v692);
      v254 = 0;
      v255 = 0;
      do
      {
        if ( v255 > 0x6Cu || v254 > 0x11 )
          goto LABEL_41;
        v256 = snprintf((char *)v692 + v255, 108LL - v255, " %d", *((unsigned __int8 *)v9 + v254++ + 170));
        v255 += v256;
      }
      while ( num_contexts != v254 );
      DP_PRINT_STATS("Rx ring mask (0-%d):%s", v257, v258, v259, v260, v261, v262, v263, v264, num_contexts, v692);
      v265 = 0;
      v266 = 0;
      do
      {
        if ( v266 > 0x6Cu || v265 > 0x11 )
          goto LABEL_41;
        v267 = snprintf((char *)v692 + v266, 108LL - v266, " %d", *((unsigned __int8 *)v9 + v265++ + 188));
        v266 += v267;
      }
      while ( num_contexts != v265 );
      DP_PRINT_STATS("Rx mon ring mask (0-%d):%s", v268, v269, v270, v271, v272, v273, v274, v275, num_contexts, v692);
      v276 = 0;
      v277 = 0;
      do
      {
        if ( v277 > 0x6Cu || v276 > 0x11 )
          goto LABEL_41;
        v278 = snprintf((char *)v692 + v277, 108LL - v277, " %d", *((unsigned __int8 *)v9 + v276++ + 278));
        v277 += v278;
      }
      while ( num_contexts != v276 );
      DP_PRINT_STATS("Rx err ring mask (0-%d):%s", v279, v280, v281, v282, v283, v284, v285, v286, num_contexts, v692);
      v287 = 0;
      v288 = 0;
      do
      {
        if ( v288 > 0x6Cu || v287 > 0x11 )
          goto LABEL_41;
        v289 = snprintf((char *)v692 + v288, 108LL - v288, " %d", *((unsigned __int8 *)v9 + v287++ + 296));
        v288 += v289;
      }
      while ( num_contexts != v287 );
      DP_PRINT_STATS(
        "Rx wbm rel ring mask (0-%d):%s",
        v290,
        v291,
        v292,
        v293,
        v294,
        v295,
        v296,
        v297,
        num_contexts,
        v692);
      v298 = 0;
      v299 = 0;
      do
      {
        if ( v299 > 0x6Cu || v298 > 0x11 )
          goto LABEL_41;
        v300 = snprintf((char *)v692 + v299, 108LL - v299, " %d", *((unsigned __int8 *)v9 + v298++ + 314));
        v299 += v300;
      }
      while ( num_contexts != v298 );
      DP_PRINT_STATS("Reo ring mask (0-%d):%s", v301, v302, v303, v304, v305, v306, v307, v308, num_contexts, v692);
      v309 = 0;
      v310 = 0;
      do
      {
        if ( v310 > 0x6Cu || v309 > 0x11 )
          goto LABEL_41;
        v311 = snprintf((char *)v692 + v310, 108LL - v310, " %d", *((unsigned __int8 *)v9 + v309++ + 332));
        v310 += v311;
      }
      while ( num_contexts != v309 );
      DP_PRINT_STATS(
        "Rxdma2host ring mask (0-%d):%s",
        v312,
        v313,
        v314,
        v315,
        v316,
        v317,
        v318,
        v319,
        num_contexts,
        v692);
      v320 = 0;
      v321 = 0;
      while ( v321 <= 0x6Cu && v320 <= 0x11 )
      {
        v322 = snprintf((char *)v692 + v321, 108LL - v321, " %d", *((unsigned __int8 *)v9 + v320++ + 350));
        v321 += v322;
        if ( num_contexts == v320 )
          goto LABEL_39;
      }
LABEL_41:
      __break(0x5512u);
    }
    DP_PRINT_STATS("Tx ring mask (0-%d):%s", v235, v236, v237, v238, v239, v240, v241, v242, num_contexts, v692);
    DP_PRINT_STATS("Rx ring mask (0-%d):%s", v332, v333, v334, v335, v336, v337, v338, v339, num_contexts, v692);
    DP_PRINT_STATS("Rx mon ring mask (0-%d):%s", v340, v341, v342, v343, v344, v345, v346, v347, num_contexts, v692);
    DP_PRINT_STATS("Rx err ring mask (0-%d):%s", v348, v349, v350, v351, v352, v353, v354, v355, num_contexts, v692);
    DP_PRINT_STATS("Rx wbm rel ring mask (0-%d):%s", v356, v357, v358, v359, v360, v361, v362, v363, num_contexts, v692);
    DP_PRINT_STATS("Reo ring mask (0-%d):%s", v364, v365, v366, v367, v368, v369, v370, v371, num_contexts, v692);
    DP_PRINT_STATS("Rxdma2host ring mask (0-%d):%s", v372, v373, v374, v375, v376, v377, v378, v379, num_contexts, v692);
LABEL_39:
    DP_PRINT_STATS("Host2rxdma ring mask (0-%d):%s", v323, v324, v325, v326, v327, v328, v329, v330, num_contexts, v692);
    DP_PRINT_STATS("Rx hash: %u ", v380, v381, v382, v383, v384, v385, v386, v387, *((unsigned __int8 *)v9 + 528));
    DP_PRINT_STATS("Tso enabled: %u ", v388, v389, v390, v391, v392, v393, v394, v395, *((unsigned __int8 *)v9 + 529));
    DP_PRINT_STATS("Lro enabled: %u ", v396, v397, v398, v399, v400, v401, v402, v403, *((unsigned __int8 *)v9 + 530));
    DP_PRINT_STATS("Sg enabled: %u ", v404, v405, v406, v407, v408, v409, v410, v411, *((unsigned __int8 *)v9 + 531));
    DP_PRINT_STATS("Gro enabled: %u ", v412, v413, v414, v415, v416, v417, v418, v419, *((unsigned __int8 *)v9 + 532));
    DP_PRINT_STATS(
      "TC based dynamic GRO: %u ",
      v420,
      v421,
      v422,
      v423,
      v424,
      v425,
      v426,
      v427,
      *((unsigned __int8 *)v9 + 533));
    DP_PRINT_STATS("TC ingress prio: %u ", v428, v429, v430, v431, v432, v433, v434, v435, v9[134]);
    DP_PRINT_STATS(
      "rawmode enabled: %u ",
      v436,
      v437,
      v438,
      v439,
      v440,
      v441,
      v442,
      v443,
      *((unsigned __int8 *)v9 + 543));
    DP_PRINT_STATS(
      "peer flow ctrl enabled: %u ",
      v444,
      v445,
      v446,
      v447,
      v448,
      v449,
      v450,
      v451,
      *((unsigned __int8 *)v9 + 544));
    DP_PRINT_STATS("napi enabled: %u ", v452, v453, v454, v455, v456, v457, v458, v459, *((unsigned __int8 *)v9 + 545));
    DP_PRINT_STATS(
      "P2P Tcp Udp checksum offload: %u ",
      v460,
      v461,
      v462,
      v463,
      v464,
      v465,
      v466,
      v467,
      *((unsigned __int8 *)v9 + 546));
    DP_PRINT_STATS(
      "NAN Tcp Udp checksum offload: %u ",
      v468,
      v469,
      v470,
      v471,
      v472,
      v473,
      v474,
      v475,
      *((unsigned __int8 *)v9 + 547));
    DP_PRINT_STATS(
      "Tcp Udp checksum offload: %u ",
      v476,
      v477,
      v478,
      v479,
      v480,
      v481,
      v482,
      v483,
      *((unsigned __int8 *)v9 + 548));
    DP_PRINT_STATS(
      "Defrag timeout check: %u ",
      v484,
      v485,
      v486,
      v487,
      v488,
      v489,
      v490,
      v491,
      *((unsigned __int8 *)v9 + 550));
    DP_PRINT_STATS("Rx defrag min timeout: %u ", v492, v493, v494, v495, v496, v497, v498, v499, v9[141]);
    DP_PRINT_STATS("WBM release ring: %u ", v500, v501, v502, v503, v504, v505, v506, v507, v9[142]);
    DP_PRINT_STATS("TCL CMD_CREDIT ring: %u ", v508, v509, v510, v511, v512, v513, v514, v515, v9[143]);
    DP_PRINT_STATS("TCL Status ring: %u ", v516, v517, v518, v519, v520, v521, v522, v523, v9[144]);
    DP_PRINT_STATS("REO Destination ring: %u ", v524, v525, v526, v527, v528, v529, v530, v531, v9[36]);
    DP_PRINT_STATS("REO Reinject ring: %u ", v532, v533, v534, v535, v536, v537, v538, v539, v9[145]);
    DP_PRINT_STATS("RX release ring: %u ", v540, v541, v542, v543, v544, v545, v546, v547, v9[146]);
    DP_PRINT_STATS("REO Exception ring: %u ", v548, v549, v550, v551, v552, v553, v554, v555, v9[147]);
    DP_PRINT_STATS("REO CMD ring: %u ", v556, v557, v558, v559, v560, v561, v562, v563, v9[148]);
    DP_PRINT_STATS("REO STATUS ring: %u ", v564, v565, v566, v567, v568, v569, v570, v571, v9[149]);
    DP_PRINT_STATS("RXDMA refill ring: %u ", v572, v573, v574, v575, v576, v577, v578, v579, v9[150]);
    DP_PRINT_STATS("RXDMA scan refill ring: %u ", v580, v581, v582, v583, v584, v585, v586, v587, v9[152]);
    DP_PRINT_STATS("TX_desc limit_0: %u ", v588, v589, v590, v591, v592, v593, v594, v595, v9[161]);
    DP_PRINT_STATS("TX_desc limit_1: %u ", v596, v597, v598, v599, v600, v601, v602, v603, v9[162]);
    DP_PRINT_STATS("TX_desc limit_2: %u ", v604, v605, v606, v607, v608, v609, v610, v611, v9[163]);
    DP_PRINT_STATS("TX device limit: %u ", v612, v613, v614, v615, v616, v617, v618, v619, v9[164]);
    DP_PRINT_STATS("TX sw internode queue: %u ", v620, v621, v622, v623, v624, v625, v626, v627, v9[166]);
    DP_PRINT_STATS("RXDMA err dst ring: %u ", v628, v629, v630, v631, v632, v633, v634, v635, v9[154]);
    DP_PRINT_STATS(
      "RX Flow Tag Enabled: %u ",
      v636,
      v637,
      v638,
      v639,
      v640,
      v641,
      v642,
      v643,
      *((unsigned __int8 *)v9 + 697));
    DP_PRINT_STATS(
      "RX Flow Search Table Size (# of entries): %u ",
      v644,
      v645,
      v646,
      v647,
      v648,
      v649,
      v650,
      v651,
      *((unsigned __int16 *)v9 + 350));
    DP_PRINT_STATS(
      "RX Flow Search Table Per PDev : %u ",
      v652,
      v653,
      v654,
      v655,
      v656,
      v657,
      v658,
      v659,
      *((unsigned __int8 *)v9 + 699));
    DP_PRINT_STATS("Rx desc pool size: %u ", v660, v661, v662, v663, v664, v665, v666, v667, v9[173]);
    DP_PRINT_STATS("IPA Status: %u", v668, v669, v670, v671, v672, v673, v674, v675, *((unsigned __int8 *)v9 + 540));
    DP_PRINT_STATS("IPA TX ring size: %u", v676, v677, v678, v679, v680, v681, v682, v683, v9[190]);
    result = DP_PRINT_STATS("IPA TX comp ring size: %u", v684, v685, v686, v687, v688, v689, v690, v691, v9[191]);
  }
  else
  {
    result = qdf_trace_msg(0x45u, 2u, "%s: Context is null", a2, a3, a4, a5, a6, a7, a8, a9, "dp_print_soc_cfg_params");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
