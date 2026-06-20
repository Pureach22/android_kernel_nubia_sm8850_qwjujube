void ipa_save_registers()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  long double v3; // q0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  int **v7; // x23
  __int64 v8; // x24
  __int64 (__fastcall *v9)(); // x8
  __int64 v10; // x9
  __int64 v11; // x0
  int v12; // w0
  int *v13; // t1
  __int64 v14; // x22
  char v15; // w27
  __int64 (__fastcall **v16)(); // x0
  __int64 v17; // x0
  __int64 (__fastcall **v18)(); // x27
  __int64 v19; // x19
  int *v20; // x25
  __int64 (__fastcall *v21)(); // x9
  __int64 v22; // x0
  int v23; // w0
  int v24; // w8
  unsigned int v25; // w23
  __int64 v26; // x0
  _DWORD *v27; // x9
  __int64 v28; // x24
  __int64 v29; // x0
  __int64 (__fastcall **v30)(); // x0
  long double v31; // q0
  __int64 (__fastcall *v32)(); // x9
  __int64 v33; // x8
  __int64 (__fastcall **v34)(); // x23
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  int v38; // w0
  int v39; // w8
  __int64 (__fastcall **v40)(); // x0
  __int64 v41; // x8
  __int64 (__fastcall **v42)(); // x23
  __int64 v43; // x0
  __int64 i; // x23
  __int64 (__fastcall *v45)(); // x8
  __int64 v46; // x9
  __int64 v47; // x0
  int v48; // w0
  char *v49; // x8
  __int64 v50; // x22
  char v51; // w27
  __int64 (__fastcall **v52)(); // x0
  __int64 v53; // x0
  __int64 (__fastcall **v54)(); // x27
  __int64 v55; // x24
  int v56; // w21
  __int64 (__fastcall *v57)(); // x8
  __int64 v58; // x0
  __int64 v59; // x0
  _DWORD *v60; // x9
  __int64 v61; // x23
  __int64 v62; // x0
  __int64 (__fastcall **v63)(); // x0
  long double v64; // q0
  __int64 (__fastcall *v65)(); // x9
  __int64 v66; // x8
  __int64 (__fastcall **v67)(); // x23
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x0
  int v71; // w0
  int v72; // w8
  __int64 (__fastcall **v73)(); // x0
  long double v74; // q0
  __int64 (__fastcall *v75)(); // x9
  __int64 v76; // x8
  __int64 (__fastcall **v77)(); // x23
  __int64 v78; // x0
  unsigned int v79; // w21
  __int64 v80; // x0
  int v81; // w0
  int v82; // w8
  __int64 v83; // x23
  _DWORD *v84; // x9
  __int64 v85; // x0
  __int64 (__fastcall **v86)(); // x0
  long double v87; // q0
  __int64 (__fastcall *v88)(); // x8
  __int64 v89; // x9
  __int64 (__fastcall **v90)(); // x23
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 (__fastcall **v93)(); // x0
  long double v94; // q0
  __int64 (__fastcall *v95)(); // x8
  __int64 v96; // x9
  __int64 (__fastcall **v97)(); // x25
  __int64 v98; // x0
  __int64 (__fastcall **v99)(); // x0
  long double v100; // q0
  __int64 (__fastcall *v101)(); // x8
  __int64 v102; // x9
  __int64 (__fastcall **v103)(); // x23
  __int64 v104; // x0
  int *v105; // x23
  __int64 (__fastcall **v106)(); // x0
  __int64 v107; // x9
  __int64 (__fastcall **v108)(); // x25
  __int64 v109; // x24
  int v110; // w22
  int *v111; // x20
  __int64 (__fastcall *v112)(); // x9
  __int64 v113; // x0
  int v114; // w0
  int v115; // w8
  __int64 v116; // x0
  _DWORD *v117; // x9
  __int64 v118; // x23
  __int64 v119; // x0
  __int64 (__fastcall **v120)(); // x0
  long double v121; // q0
  __int64 (__fastcall *v122)(); // x9
  __int64 v123; // x8
  __int64 (__fastcall **v124)(); // x23
  __int64 v125; // x0
  __int64 v126; // x0
  __int64 v127; // x0
  int v128; // w0
  int v129; // w8
  __int64 (__fastcall **v130)(); // x0
  long double v131; // q0
  __int64 (__fastcall *v132)(); // x9
  __int64 v133; // x8
  __int64 (__fastcall **v134)(); // x23
  __int64 v135; // x0
  unsigned int v136; // w22
  __int64 v137; // x0
  int v138; // w0
  int v139; // w8
  __int64 v140; // x23
  _DWORD *v141; // x9
  __int64 v142; // x0
  __int64 (__fastcall **v143)(); // x0
  __int64 v144; // x8
  __int64 (__fastcall **v145)(); // x23
  __int64 v146; // x0
  __int64 v147; // x0
  __int64 v148; // x24
  int v149; // w21
  int *v150; // x20
  __int64 (__fastcall *v151)(); // x9
  __int64 v152; // x0
  int v153; // w0
  int v154; // w8
  __int64 v155; // x0
  _DWORD *v156; // x9
  __int64 v157; // x23
  __int64 v158; // x0
  __int64 (__fastcall **v159)(); // x0
  long double v160; // q0
  __int64 (__fastcall *v161)(); // x9
  __int64 v162; // x8
  __int64 (__fastcall **v163)(); // x23
  __int64 v164; // x0
  __int64 v165; // x0
  __int64 v166; // x0
  int v167; // w0
  int v168; // w8
  __int64 (__fastcall **v169)(); // x0
  long double v170; // q0
  __int64 (__fastcall *v171)(); // x9
  __int64 v172; // x8
  __int64 (__fastcall **v173)(); // x23
  __int64 v174; // x0
  unsigned int v175; // w21
  __int64 v176; // x0
  int v177; // w0
  int v178; // w8
  __int64 v179; // x0
  _DWORD *v180; // x9
  __int64 v181; // x23
  __int64 v182; // x0
  __int64 (__fastcall **v183)(); // x0
  __int64 v184; // x8
  __int64 (__fastcall **v185)(); // x23
  __int64 v186; // x0
  __int64 v187; // x0
  __int64 v188; // x24
  int v189; // w22
  __int64 (__fastcall *v190)(); // x9
  __int64 v191; // x0
  int v192; // w0
  int v193; // w8
  int *v194; // x9
  __int64 v195; // x0
  _DWORD *v196; // x9
  __int64 v197; // x23
  __int64 v198; // x0
  __int64 (__fastcall **v199)(); // x0
  long double v200; // q0
  __int64 (__fastcall *v201)(); // x9
  __int64 v202; // x8
  __int64 (__fastcall **v203)(); // x23
  __int64 v204; // x0
  __int64 v205; // x0
  __int64 v206; // x0
  int v207; // w0
  int v208; // w8
  __int64 (__fastcall **v209)(); // x0
  long double v210; // q0
  __int64 (__fastcall *v211)(); // x9
  __int64 v212; // x8
  __int64 (__fastcall **v213)(); // x23
  __int64 v214; // x0
  unsigned int v215; // w22
  __int64 v216; // x0
  int v217; // w0
  int v218; // w8
  __int64 v219; // x23
  _DWORD *v220; // x9
  __int64 v221; // x0
  __int64 (__fastcall **v222)(); // x0
  __int64 v223; // x8
  __int64 (__fastcall **v224)(); // x23
  __int64 v225; // x0
  __int64 v226; // x0
  __int64 v227; // x24
  int v228; // w21
  __int64 (__fastcall *v229)(); // x8
  __int64 v230; // x0
  int v231; // w0
  int *v232; // x8
  __int64 v233; // x0
  _DWORD *v234; // x9
  __int64 v235; // x23
  __int64 v236; // x0
  __int64 (__fastcall **v237)(); // x0
  long double v238; // q0
  __int64 (__fastcall *v239)(); // x9
  __int64 v240; // x8
  __int64 (__fastcall **v241)(); // x23
  __int64 v242; // x0
  __int64 v243; // x0
  __int64 v244; // x0
  int v245; // w0
  int v246; // w8
  __int64 (__fastcall **v247)(); // x0
  long double v248; // q0
  __int64 (__fastcall *v249)(); // x9
  __int64 v250; // x8
  __int64 (__fastcall **v251)(); // x23
  __int64 v252; // x0
  unsigned int v253; // w21
  __int64 v254; // x0
  int v255; // w0
  int v256; // w8
  __int64 v257; // x23
  _DWORD *v258; // x9
  __int64 v259; // x0
  __int64 (__fastcall **v260)(); // x0
  __int64 v261; // x9
  __int64 (__fastcall **v262)(); // x23
  __int64 v263; // x0
  __int64 v264; // x24
  int v265; // w22
  int *v266; // x20
  __int64 (__fastcall *v267)(); // x9
  __int64 v268; // x0
  int v269; // w0
  int v270; // w8
  __int64 v271; // x0
  _DWORD *v272; // x9
  __int64 v273; // x23
  __int64 v274; // x0
  __int64 (__fastcall **v275)(); // x0
  long double v276; // q0
  __int64 (__fastcall *v277)(); // x9
  __int64 v278; // x8
  __int64 (__fastcall **v279)(); // x23
  __int64 v280; // x0
  __int64 v281; // x0
  __int64 v282; // x0
  int v283; // w0
  int v284; // w8
  __int64 (__fastcall **v285)(); // x0
  long double v286; // q0
  __int64 (__fastcall *v287)(); // x9
  __int64 v288; // x8
  __int64 (__fastcall **v289)(); // x23
  __int64 v290; // x0
  unsigned int v291; // w22
  __int64 v292; // x0
  int v293; // w0
  int v294; // w8
  __int64 v295; // x23
  _DWORD *v296; // x9
  __int64 v297; // x0
  __int64 (__fastcall **v298)(); // x0
  __int64 v299; // x8
  __int64 (__fastcall **v300)(); // x23
  __int64 v301; // x0
  __int64 v302; // x0
  __int64 v303; // x9
  int v304; // w27
  char *v305; // x20
  __int64 v306; // x25
  int v307; // w26
  __int64 (__fastcall *v308)(); // x9
  __int64 v309; // x0
  int v310; // w0
  char *v311; // x9
  int v312; // w8
  unsigned int v313; // w22
  __int64 v314; // x23
  _DWORD *v315; // x9
  __int64 v316; // x0
  __int64 (__fastcall **v317)(); // x0
  long double v318; // q0
  __int64 (__fastcall *v319)(); // x9
  __int64 v320; // x8
  __int64 (__fastcall **v321)(); // x23
  __int64 v322; // x0
  __int64 v323; // x0
  __int64 v324; // x0
  int v325; // w0
  int v326; // w8
  __int64 (__fastcall **v327)(); // x0
  __int64 v328; // x8
  __int64 (__fastcall **v329)(); // x23
  __int64 v330; // x0
  __int64 v331; // x25
  _DWORD *v332; // x26
  __int64 (__fastcall *v333)(); // x8
  __int64 v334; // x0
  unsigned int v335; // w23
  __int64 v336; // x0
  _DWORD *v337; // x9
  __int64 v338; // x24
  __int64 v339; // x0
  __int64 (__fastcall **v340)(); // x0
  __int64 v341; // x9
  __int64 (__fastcall **v342)(); // x23
  __int64 v343; // x0
  __int64 (__fastcall **v344)(); // x0
  __int64 (__fastcall *v345)(); // x8
  __int64 v346; // x9
  __int64 (__fastcall **v347)(); // x20
  __int64 v348; // x0
  __int16 v349; // w0
  __int64 (__fastcall **v350)(); // x0
  __int64 (__fastcall *v351)(); // x8
  __int64 v352; // x9
  __int64 (__fastcall **v353)(); // x20
  __int64 v354; // x0
  __int16 v355; // w0
  __int64 (__fastcall **v356)(); // x0
  __int64 (__fastcall *v357)(); // x8
  __int64 v358; // x9
  __int64 (__fastcall **v359)(); // x20
  __int64 v360; // x0
  __int16 v361; // w0
  __int64 (__fastcall **v362)(); // x0
  __int64 (__fastcall *v363)(); // x8
  __int64 v364; // x9
  __int64 (__fastcall **v365)(); // x20
  __int64 v366; // x0
  __int16 v367; // w0
  __int64 (__fastcall **v368)(); // x0
  __int64 (__fastcall *v369)(); // x8
  __int64 v370; // x9
  __int64 (__fastcall **v371)(); // x20
  __int64 v372; // x0
  __int16 v373; // w0
  __int64 (__fastcall **v374)(); // x0
  __int64 (__fastcall *v375)(); // x8
  __int64 v376; // x9
  __int64 (__fastcall **v377)(); // x20
  __int64 v378; // x0
  __int16 v379; // w0
  __int64 (__fastcall **v380)(); // x0
  __int64 (__fastcall *v381)(); // x8
  __int64 v382; // x9
  __int64 (__fastcall **v383)(); // x19
  __int64 v384; // x0
  __int16 v385; // w0
  __int64 v386; // x23
  __int64 (__fastcall *v387)(); // x8
  __int64 v388; // x0
  int v389; // w0
  int *v390; // x8
  __int64 (__fastcall **v391)(); // x0
  __int64 v392; // x9
  __int64 (__fastcall **v393)(); // x27
  __int64 j; // x22
  __int64 (__fastcall *v395)(); // x8
  __int64 v396; // x0
  __int16 v397; // w0
  long double v398; // q0
  int *v399; // x8
  __int64 (__fastcall **v400)(); // x0
  __int64 v401; // x9
  __int64 (__fastcall **v402)(); // x27
  __int64 v403; // x22
  __int64 (__fastcall *v404)(); // x8
  __int64 v405; // x0
  int v406; // w28
  __int64 v407; // x21
  __int64 (__fastcall **v408)(); // x0
  long double v409; // q0
  __int64 (__fastcall *v410)(); // x8
  __int64 v411; // x9
  __int64 (__fastcall **v412)(); // x19
  __int64 v413; // x0
  unsigned int v414; // w21
  __int64 (__fastcall **v415)(); // x0
  long double v416; // q0
  __int64 v417; // x9
  __int64 (__fastcall *v418)(); // x8
  __int64 (__fastcall **v419)(); // x20
  __int64 v420; // x0
  unsigned int v421; // w21
  __int64 (__fastcall **v422)(); // x0
  __int64 v423; // x9
  __int64 (__fastcall **v424)(); // x19
  __int64 v425; // x9
  char v426; // w8
  __int64 (__fastcall *v427)(); // x8
  __int64 v428; // x0
  int *v429; // x20
  char v430; // w19
  int v431; // w25
  __int64 v432; // x21
  __int64 (__fastcall **v433)(); // x0
  long double v434; // q0
  __int64 v435; // x9
  __int64 (__fastcall *v436)(); // x8
  __int64 (__fastcall **v437)(); // x23
  _DWORD *v438; // x20
  __int64 v439; // x0
  unsigned int v440; // w21
  __int64 (__fastcall **v441)(); // x0
  long double v442; // q0
  __int64 v443; // x9
  __int64 (__fastcall *v444)(); // x8
  __int64 (__fastcall **v445)(); // x23
  __int64 v446; // x0
  unsigned int v447; // w21
  __int64 (__fastcall **v448)(); // x0
  __int64 v449; // x9
  __int64 (__fastcall **v450)(); // x23
  __int64 v451; // x22
  __int64 (__fastcall *v452)(); // x8
  __int64 v453; // x0
  int v454; // w28
  __int64 v455; // x21
  __int64 (__fastcall **v456)(); // x0
  long double v457; // q0
  __int64 v458; // x9
  __int64 (__fastcall *v459)(); // x8
  __int64 (__fastcall **v460)(); // x19
  __int64 v461; // x0
  unsigned int v462; // w21
  __int64 (__fastcall **v463)(); // x0
  long double v464; // q0
  __int64 v465; // x9
  __int64 (__fastcall *v466)(); // x8
  __int64 (__fastcall **v467)(); // x20
  __int64 v468; // x0
  unsigned int v469; // w21
  __int64 (__fastcall **v470)(); // x0
  __int64 v471; // x9
  __int64 (__fastcall **v472)(); // x19
  _BYTE *v473; // x20
  _DWORD *v474; // x19
  __int64 v475; // x22
  __int64 v476; // x22
  __int64 v477; // x22
  __int64 v478; // x22
  __int64 v479; // x22
  __int16 v480; // w0
  __int16 v481; // w25
  __int64 v482; // x27
  int *v483; // x28
  __int64 v484; // x24
  _DWORD *v485; // x9
  __int64 v486; // x0
  __int64 (__fastcall **v487)(); // x0
  long double v488; // q0
  __int64 (__fastcall *v489)(); // x8
  __int64 v490; // x9
  __int64 (__fastcall **v491)(); // x24
  __int64 v492; // x0
  __int64 v493; // x0
  __int64 v494; // x8
  __int64 v495; // x0
  __int64 v496; // x0
  __int64 k; // x23
  __int64 (__fastcall *v498)(); // x8
  __int64 v499; // x0
  __int64 (__fastcall **v500)(); // x0
  __int64 v501; // x9
  __int64 (__fastcall **v502)(); // x27
  __int64 m; // x23
  __int64 (__fastcall *v504)(); // x8
  __int64 v505; // x0
  __int64 (__fastcall **v506)(); // x0
  __int64 v507; // x9
  __int64 (__fastcall **v508)(); // x27
  __int64 n; // x24
  __int64 (__fastcall *v510)(); // x8
  __int64 v511; // x0
  __int64 (__fastcall **v512)(); // x0
  __int64 v513; // x9
  __int64 (__fastcall **v514)(); // x23
  __int64 ii; // x25
  __int64 (__fastcall *v516)(); // x8
  __int64 v517; // x0
  __int64 (__fastcall **v518)(); // x0
  __int64 v519; // x9
  __int64 (__fastcall **v520)(); // x24
  __int64 jj; // x25
  __int64 (__fastcall *v522)(); // x8
  __int64 v523; // x0
  __int64 (__fastcall **v524)(); // x0
  __int64 v525; // x9
  __int64 (__fastcall **v526)(); // x24
  __int64 v527; // x25
  __int64 v528; // x20
  __int64 (__fastcall *v529)(); // x8
  __int64 v530; // x0
  __int64 (__fastcall **v531)(); // x0
  __int64 v532; // x9
  __int64 (__fastcall **v533)(); // x24
  __int64 v534; // x8
  unsigned __int64 v535; // x9
  __int64 v536; // x8
  unsigned __int64 v537; // x12
  __int64 v538; // x9
  __int64 v539; // x8
  __int64 v540; // x0
  __int64 v541; // x0
  __int64 v542; // x8
  unsigned __int64 v543; // x9
  __int64 v544; // x8
  unsigned __int64 v545; // x12
  __int64 v546; // x9
  __int64 v547; // x8
  __int64 v548; // x0
  __int64 v549; // x0
  __int64 v550; // x8
  unsigned __int64 v551; // x9
  __int64 v552; // x8
  unsigned __int64 v553; // x12
  __int64 v554; // x9
  __int64 v555; // x8
  __int64 v556; // x0
  __int64 v557; // x0
  __int64 v558; // x8
  unsigned __int64 v559; // x9
  __int64 v560; // x8
  unsigned __int64 v561; // x12
  __int64 v562; // x9
  __int64 v563; // x8
  __int64 v564; // x0
  __int64 v565; // x0
  __int64 v566; // x8
  unsigned __int64 v567; // x9
  __int64 v568; // x8
  unsigned __int64 v569; // x12
  __int64 v570; // x9
  __int64 v571; // x8
  __int64 v572; // x0
  __int64 v573; // x0
  __int64 v574; // x8
  unsigned __int64 v575; // x9
  __int64 v576; // x8
  unsigned __int64 v577; // x12
  __int64 v578; // x9
  __int64 v579; // x8
  __int64 v580; // x0
  __int64 v581; // x0
  unsigned int v582; // w8
  __int64 v583; // x9
  __int64 v584; // x0
  __int64 v585; // x0
  __int64 v586; // x8
  __int64 v587; // x0
  __int64 v588; // x0
  __int64 v589; // x8
  __int64 v590; // x0
  __int64 v591; // x0
  __int64 v592; // [xsp+8h] [xbp-18h]
  _QWORD v593[2]; // [xsp+10h] [xbp-10h] BYREF

  v593[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(ipa3_ctx + 44860) == 1 )
  {
    printk(&unk_3C8DAE, "ipa_save_registers");
    v0 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v1 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v1 )
      {
        ipc_log_string(v1, "ipa %s:%d Commencing\n", "ipa_save_registers", 1027);
        v0 = ipa3_ctx;
      }
      v2 = *(_QWORD *)(v0 + 34160);
      if ( v2 )
        ipc_log_string(v2, "ipa %s:%d Commencing\n", "ipa_save_registers", 1027);
    }
    printk(&unk_3B1512, "ipa_save_registers");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        v3 = ipc_log_string(v5, "ipa %s:%d reading %d registers\n", "ipa_save_registers", 1039, 2728);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        v3 = ipc_log_string(v6, "ipa %s:%d reading %d registers\n", "ipa_save_registers", 1039, 2728);
    }
    v7 = &off_1E5CA8;
    v8 = 2728;
    do
    {
      v14 = *((unsigned int *)v7 - 2);
      v15 = *((_BYTE *)v7 + 8);
      v16 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD, long double))get_access_funcs)(
                                         (unsigned int)v14,
                                         v3);
      if ( (v15 & 1) != 0 )
      {
        v9 = *v16;
        v10 = ipa3_ctx;
        if ( *v16 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v18 = v16;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword",
              930,
              v14);
            v9 = *v18;
            v10 = ipa3_ctx;
          }
          else
          {
            v9 = nop_read;
          }
        }
        v11 = *(_QWORD *)(v10 + 44872) + v14;
        if ( *((_DWORD *)v9 - 1) != -1536295579 )
          __break(0x8228u);
        v12 = ((__int64 (__fastcall *)(__int64))v9)(v11);
      }
      else
      {
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v17 )
            v3 = ipc_log_string(v17, "ipa %s:%d not permitted to read addr 0x%X\n", "in_dword", 933, v14);
        }
        v12 = -1;
      }
      v13 = *v7;
      v7 += 3;
      --v8;
      *v13 = v12;
    }
    while ( v8 );
    v19 = 0;
    v20 = (int *)&unk_20A6D8;
    byte_207078 = 1;
    byte_2070D4 = 1;
    byte_207130 = 1;
    byte_20718C = 1;
    byte_2071E8 = 1;
    byte_207244 = 1;
    byte_2072A0 = 1;
    byte_2072FC = 1;
    byte_207358 = 1;
    byte_2073B4 = 1;
    byte_207410 = 1;
    byte_20746C = 1;
    byte_2074C8 = 1;
    byte_207524 = 1;
    byte_207580 = 1;
    byte_2075DC = 1;
    byte_207638 = 1;
    byte_207694 = 1;
    byte_2076F0 = 1;
    byte_20774C = 1;
    byte_2077A8 = 1;
    byte_207804 = 1;
    byte_207860 = 1;
    byte_2078BC = 1;
    byte_207918 = 1;
    byte_207974 = 1;
    byte_2079D0 = 1;
    byte_207A2C = 1;
    byte_207A88 = 1;
    byte_207AE4 = 1;
    byte_207B40 = 1;
    byte_207B9C = 1;
    byte_207BF8 = 1;
    byte_207C54 = 1;
    byte_207CB0 = 1;
    byte_207D0C = 1;
    do
    {
      v25 = (unsigned __int8)v19 | 0x20;
      *(v20 - 2) = v25;
      v26 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1344740);
      v27 = *(_DWORD **)(v26 + 8);
      v28 = v26;
      v29 = *(_QWORD *)(ipa3_ctx + 44872) + 1344740LL;
      if ( *(v27 - 1) != -1783303382 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, _QWORD))v27)(v29, v25);
      if ( *(__int64 (__fastcall **)())(v28 + 8) == nop_write )
      {
        if ( ipa3_ctx )
        {
          v36 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v36 )
            ipc_log_string(v36, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1344740);
        }
      }
      v30 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344744);
      v32 = *v30;
      v33 = ipa3_ctx;
      v34 = v30;
      if ( *v30 == nop_read )
      {
        if ( ipa3_ctx && (v35 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
        {
          v31 = ipc_log_string(v35, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344744);
          v32 = *v34;
          v33 = ipa3_ctx;
        }
        else
        {
          v32 = nop_read;
        }
      }
      v37 = *(_QWORD *)(v33 + 44872) + 1344744LL;
      if ( *((_DWORD *)v32 - 1) != -1536295579 )
        __break(0x8229u);
      v38 = ((__int64 (__fastcall *)(__int64, long double))v32)(v37, v31);
      if ( *v34 == act_read )
        v39 = 0x7FFFFFFF;
      else
        v39 = -1;
      *(v20 - 1) = v39 & v38;
      v40 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344748);
      v21 = *v40;
      v41 = ipa3_ctx;
      v42 = v40;
      if ( *v40 == nop_read )
      {
        if ( ipa3_ctx && (v43 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
        {
          ipc_log_string(v43, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344748);
          v21 = *v42;
          v41 = ipa3_ctx;
        }
        else
        {
          v21 = nop_read;
        }
      }
      v22 = *(_QWORD *)(v41 + 44872) + 1344748LL;
      if ( *((_DWORD *)v21 - 1) != -1536295579 )
        __break(0x8229u);
      v23 = ((__int64 (__fastcall *)(__int64))v21)(v22);
      ++v19;
      if ( *v42 == act_read )
        v24 = 0x7FFFFFFF;
      else
        v24 = -1;
      *v20 = v24 & v23;
      v20 += 3;
    }
    while ( v19 != 36 );
    if ( *(_BYTE *)(ipa3_ctx + 44862) == 1 )
    {
      for ( i = 0; i != 120; i += 24 )
      {
        v50 = *(unsigned int *)((char *)&ipa_uc_regs_to_save_array + i);
        v51 = *((_BYTE *)&ipa_uc_regs_to_save_array + i + 16);
        v52 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)v50);
        if ( (v51 & 1) != 0 )
        {
          v45 = *v52;
          v46 = ipa3_ctx;
          if ( *v52 == nop_read )
          {
            if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
            {
              v54 = v52;
              ipc_log_string(
                *(_QWORD *)(ipa3_ctx + 34160),
                "ipa %s:%d nop read action for address 0x%X\n",
                "in_dword",
                930,
                v50);
              v45 = *v54;
              v46 = ipa3_ctx;
            }
            else
            {
              v45 = nop_read;
            }
          }
          v47 = *(_QWORD *)(v46 + 44872) + v50;
          if ( *((_DWORD *)v45 - 1) != -1536295579 )
            __break(0x8228u);
          v48 = ((__int64 (__fastcall *)(__int64))v45)(v47);
        }
        else
        {
          if ( ipa3_ctx )
          {
            v53 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v53 )
              ipc_log_string(v53, "ipa %s:%d not permitted to read addr 0x%X\n", "in_dword", 933, v50);
          }
          v48 = -1;
        }
        v49 = (char *)&ipa_uc_regs_to_save_array + i;
        **((_DWORD **)v49 + 1) = v48;
      }
      v55 = 0;
      v56 = 0;
      do
      {
        v59 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1344128);
        v60 = *(_DWORD **)(v59 + 8);
        v61 = v59;
        v62 = *(_QWORD *)(ipa3_ctx + 44872) + 1344128LL;
        if ( *(v60 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v60)(v62, (unsigned int)(v55 * 4) + (v56 & 3));
        if ( *(__int64 (__fastcall **)())(v61 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v69 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v69 )
              ipc_log_string(v69, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1344128);
          }
        }
        v63 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344192);
        v65 = *v63;
        v66 = ipa3_ctx;
        v67 = v63;
        if ( *v63 == nop_read )
        {
          if ( ipa3_ctx && (v68 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v64 = ipc_log_string(v68, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344192);
            v65 = *v67;
            v66 = ipa3_ctx;
          }
          else
          {
            v65 = nop_read;
          }
        }
        v70 = *(_QWORD *)(v66 + 44872) + 1344192LL;
        if ( *((_DWORD *)v65 - 1) != -1536295579 )
          __break(0x8229u);
        v71 = ((__int64 (__fastcall *)(__int64, long double))v65)(v70, v64);
        if ( *v67 == act_read )
          v72 = 127;
        else
          v72 = -1;
        ipa_reg_save[v55 + 318] = v72 & v71;
        v73 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344180);
        v75 = *v73;
        v76 = ipa3_ctx;
        v77 = v73;
        if ( *v73 == nop_read )
        {
          if ( ipa3_ctx && (v78 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v74 = ipc_log_string(v78, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344180);
            v75 = *v77;
            v76 = ipa3_ctx;
          }
          else
          {
            v75 = nop_read;
          }
        }
        v79 = v56 & 0xFFFFFFC3;
        v80 = *(_QWORD *)(v76 + 44872) + 1344180LL;
        if ( *((_DWORD *)v75 - 1) != -1536295579 )
          __break(0x8229u);
        v81 = ((__int64 (__fastcall *)(__int64, long double))v75)(v80, v74);
        if ( *v77 == act_read )
          v82 = 511;
        else
          v82 = -1;
        v56 = v79 | (v55 * 4) | 0x20;
        ipa_reg_save[v55 + 322] = v82 & v81;
        v83 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1344128);
        v84 = *(_DWORD **)(v83 + 8);
        v85 = *(_QWORD *)(ipa3_ctx + 44872) + 1344128LL;
        if ( *(v84 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v84)(v85, v56 & 0x2F);
        if ( *(__int64 (__fastcall **)())(v83 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v91 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v91 )
              ipc_log_string(v91, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1344128);
          }
        }
        v86 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344164);
        v88 = *v86;
        v89 = ipa3_ctx;
        if ( *v86 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v90 = v86;
            v87 = ipc_log_string(
                    *(_QWORD *)(ipa3_ctx + 34160),
                    "ipa %s:%d nop read action for address 0x%X\n",
                    "in_dword_masked",
                    948,
                    1344164);
            v88 = *v90;
            v89 = ipa3_ctx;
          }
          else
          {
            v88 = nop_read;
          }
        }
        v92 = *(_QWORD *)(v89 + 44872) + 1344164LL;
        if ( *((_DWORD *)v88 - 1) != -1536295579 )
          __break(0x8228u);
        ipa_reg_save[v55 + 302] = ((__int64 (__fastcall *)(__int64, long double))v88)(v92, v87);
        v93 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344168);
        v95 = *v93;
        v96 = ipa3_ctx;
        if ( *v93 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v97 = v93;
            v94 = ipc_log_string(
                    *(_QWORD *)(ipa3_ctx + 34160),
                    "ipa %s:%d nop read action for address 0x%X\n",
                    "in_dword_masked",
                    948,
                    1344168);
            v95 = *v97;
            v96 = ipa3_ctx;
          }
          else
          {
            v95 = nop_read;
          }
        }
        v98 = *(_QWORD *)(v96 + 44872) + 1344168LL;
        if ( *((_DWORD *)v95 - 1) != -1536295579 )
          __break(0x8228u);
        ipa_reg_save[v55 + 306] = ((__int64 (__fastcall *)(__int64, long double))v95)(v98, v94);
        v99 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344172);
        v101 = *v99;
        v102 = ipa3_ctx;
        if ( *v99 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v103 = v99;
            v100 = ipc_log_string(
                     *(_QWORD *)(ipa3_ctx + 34160),
                     "ipa %s:%d nop read action for address 0x%X\n",
                     "in_dword_masked",
                     948,
                     1344172);
            v101 = *v103;
            v102 = ipa3_ctx;
          }
          else
          {
            v101 = nop_read;
          }
        }
        v104 = *(_QWORD *)(v102 + 44872) + 1344172LL;
        if ( *((_DWORD *)v101 - 1) != -1536295579 )
          __break(0x8228u);
        v105 = &ipa_reg_save[v55];
        ipa_reg_save[v55 + 310] = ((__int64 (__fastcall *)(__int64, long double))v101)(v104, v100);
        v106 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344176);
        v57 = *v106;
        v107 = ipa3_ctx;
        if ( *v106 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v108 = v106;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword_masked",
              948,
              1344176);
            v57 = *v108;
            v107 = ipa3_ctx;
          }
          else
          {
            v57 = nop_read;
          }
        }
        v58 = *(_QWORD *)(v107 + 44872) + 1344176LL;
        if ( *((_DWORD *)v57 - 1) != -1536295579 )
          __break(0x8228u);
        ++v55;
        v105[314] = ((__int64 (__fastcall *)(__int64))v57)(v58);
      }
      while ( v55 != 4 );
      v109 = 0;
      v110 = 0;
      v111 = (int *)&unk_205604;
      do
      {
        v116 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1344224);
        v117 = *(_DWORD **)(v116 + 8);
        v118 = v116;
        v119 = *(_QWORD *)(ipa3_ctx + 44872) + 1344224LL;
        if ( *(v117 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v117)(v119, (unsigned int)v109 + (v110 & 3));
        if ( *(__int64 (__fastcall **)())(v118 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v126 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v126 )
              ipc_log_string(v126, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1344224);
          }
        }
        v120 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344236);
        v122 = *v120;
        v123 = ipa3_ctx;
        v124 = v120;
        if ( *v120 == nop_read )
        {
          if ( ipa3_ctx && (v125 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v121 = ipc_log_string(v125, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344236);
            v122 = *v124;
            v123 = ipa3_ctx;
          }
          else
          {
            v122 = nop_read;
          }
        }
        v127 = *(_QWORD *)(v123 + 44872) + 1344236LL;
        if ( *((_DWORD *)v122 - 1) != -1536295579 )
          __break(0x8229u);
        v128 = ((__int64 (__fastcall *)(__int64, long double))v122)(v127, v121);
        if ( *v124 == act_read )
          v129 = 4083;
        else
          v129 = -1;
        *v111 = v129 & v128;
        v130 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344244);
        v132 = *v130;
        v133 = ipa3_ctx;
        v134 = v130;
        if ( *v130 == nop_read )
        {
          if ( ipa3_ctx && (v135 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v131 = ipc_log_string(v135, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344244);
            v132 = *v134;
            v133 = ipa3_ctx;
          }
          else
          {
            v132 = nop_read;
          }
        }
        v136 = v110 & 0xFFFFF00B;
        v137 = *(_QWORD *)(v133 + 44872) + 1344244LL;
        if ( *((_DWORD *)v132 - 1) != -1536295579 )
          __break(0x8229u);
        v138 = ((__int64 (__fastcall *)(__int64, long double))v132)(v137, v131);
        if ( *v134 == act_read )
          v139 = 255;
        else
          v139 = -1;
        v110 = v136 | v109 | 4;
        *(v111 - 32) = v139 & v138;
        v140 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1344224);
        v141 = *(_DWORD **)(v140 + 8);
        v142 = *(_QWORD *)(ipa3_ctx + 44872) + 1344224LL;
        if ( *(v141 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v141)(v142, v110 & 0x1F7);
        if ( *(__int64 (__fastcall **)())(v140 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v147 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v147 )
              ipc_log_string(v147, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1344224);
          }
        }
        v143 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344232);
        v112 = *v143;
        v144 = ipa3_ctx;
        v145 = v143;
        if ( *v143 == nop_read )
        {
          if ( ipa3_ctx && (v146 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            ipc_log_string(v146, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344232);
            v112 = *v145;
            v144 = ipa3_ctx;
          }
          else
          {
            v112 = nop_read;
          }
        }
        v113 = *(_QWORD *)(v144 + 44872) + 1344232LL;
        if ( *((_DWORD *)v112 - 1) != -1536295579 )
          __break(0x8229u);
        v114 = ((__int64 (__fastcall *)(__int64))v112)(v113);
        v109 += 16;
        if ( *v145 == act_read )
          v115 = 0xFFFFFF;
        else
          v115 = -1;
        *(v111 - 64) = v115 & v114;
        ++v111;
      }
      while ( v109 != 512 );
      v148 = 0;
      v149 = 0;
      v150 = (int *)&unk_2056C0;
      do
      {
        v155 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1344512);
        v156 = *(_DWORD **)(v155 + 8);
        v157 = v155;
        v158 = *(_QWORD *)(ipa3_ctx + 44872) + 1344512LL;
        if ( *(v156 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v156)(v158, (unsigned int)v148 + (v149 & 3));
        if ( *(__int64 (__fastcall **)())(v157 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v165 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v165 )
              ipc_log_string(v165, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1344512);
          }
        }
        v159 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344540);
        v161 = *v159;
        v162 = ipa3_ctx;
        v163 = v159;
        if ( *v159 == nop_read )
        {
          if ( ipa3_ctx && (v164 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v160 = ipc_log_string(v164, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344540);
            v161 = *v163;
            v162 = ipa3_ctx;
          }
          else
          {
            v161 = nop_read;
          }
        }
        v166 = *(_QWORD *)(v162 + 44872) + 1344540LL;
        if ( *((_DWORD *)v161 - 1) != -1536295579 )
          __break(0x8229u);
        v167 = ((__int64 (__fastcall *)(__int64, long double))v161)(v166, v160);
        if ( *v163 == act_read )
          v168 = 4083;
        else
          v168 = -1;
        *v150 = v168 & v167;
        v169 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344552);
        v171 = *v169;
        v172 = ipa3_ctx;
        v173 = v169;
        if ( *v169 == nop_read )
        {
          if ( ipa3_ctx && (v174 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v170 = ipc_log_string(v174, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344552);
            v171 = *v173;
            v172 = ipa3_ctx;
          }
          else
          {
            v171 = nop_read;
          }
        }
        v175 = v149 & 0xFFFFFF83;
        v176 = *(_QWORD *)(v172 + 44872) + 1344552LL;
        if ( *((_DWORD *)v171 - 1) != -1536295579 )
          __break(0x8229u);
        v177 = ((__int64 (__fastcall *)(__int64, long double))v171)(v176, v170);
        if ( *v173 == act_read )
          v178 = 127;
        else
          v178 = -1;
        v149 = v175 | v148 | 4;
        *(v150 - 6) = v178 & v177;
        v179 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1344512);
        v180 = *(_DWORD **)(v179 + 8);
        v181 = v179;
        v182 = *(_QWORD *)(ipa3_ctx + 44872) + 1344512LL;
        if ( *(v180 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v180)(v182, v149 & 0x3F);
        if ( *(__int64 (__fastcall **)())(v181 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v187 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v187 )
              ipc_log_string(v187, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1344512);
          }
        }
        v183 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344536);
        v151 = *v183;
        v184 = ipa3_ctx;
        v185 = v183;
        if ( *v183 == nop_read )
        {
          if ( ipa3_ctx && (v186 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            ipc_log_string(v186, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344536);
            v151 = *v185;
            v184 = ipa3_ctx;
          }
          else
          {
            v151 = nop_read;
          }
        }
        v152 = *(_QWORD *)(v184 + 44872) + 1344536LL;
        if ( *((_DWORD *)v151 - 1) != -1536295579 )
          __break(0x8229u);
        v153 = ((__int64 (__fastcall *)(__int64))v151)(v152);
        v148 += 8;
        if ( *v185 == act_read )
          v154 = 0x7FFFFFF;
        else
          v154 = -1;
        *(v150 - 12) = v154 & v153;
        ++v150;
      }
      while ( v148 != 48 );
      v188 = 0;
      v189 = 0;
      do
      {
        v195 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1344672);
        v196 = *(_DWORD **)(v195 + 8);
        v197 = v195;
        v198 = *(_QWORD *)(ipa3_ctx + 44872) + 1344672LL;
        if ( *(v196 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v196)(v198, (unsigned int)(v188 * 4) + (v189 & 3));
        if ( *(__int64 (__fastcall **)())(v197 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v205 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v205 )
              ipc_log_string(v205, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1344672);
          }
        }
        v199 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344700);
        v201 = *v199;
        v202 = ipa3_ctx;
        v203 = v199;
        if ( *v199 == nop_read )
        {
          if ( ipa3_ctx && (v204 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v200 = ipc_log_string(v204, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344700);
            v201 = *v203;
            v202 = ipa3_ctx;
          }
          else
          {
            v201 = nop_read;
          }
        }
        v206 = *(_QWORD *)(v202 + 44872) + 1344700LL;
        if ( *((_DWORD *)v201 - 1) != -1536295579 )
          __break(0x8229u);
        v207 = ((__int64 (__fastcall *)(__int64, long double))v201)(v206, v200);
        if ( *v203 == act_read )
          v208 = 511;
        else
          v208 = -1;
        ipa_reg_save[v188 + 478] = v208 & v207;
        v209 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344736);
        v211 = *v209;
        v212 = ipa3_ctx;
        v213 = v209;
        if ( *v209 == nop_read )
        {
          if ( ipa3_ctx && (v214 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v210 = ipc_log_string(v214, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344736);
            v211 = *v213;
            v212 = ipa3_ctx;
          }
          else
          {
            v211 = nop_read;
          }
        }
        v215 = v189 & 0xFFFFF803;
        v216 = *(_QWORD *)(v212 + 44872) + 1344736LL;
        if ( *((_DWORD *)v211 - 1) != -1536295579 )
          __break(0x8229u);
        v217 = ((__int64 (__fastcall *)(__int64, long double))v211)(v216, v210);
        if ( *v213 == act_read )
          v218 = 127;
        else
          v218 = -1;
        v189 = v215 | (v188 * 4) | 0x400;
        ipa_reg_save[v188 + 469] = v218 & v217;
        v219 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1344672);
        v220 = *(_DWORD **)(v219 + 8);
        v221 = *(_QWORD *)(ipa3_ctx + 44872) + 1344672LL;
        if ( *(v220 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v220)(v221, v189 & 0x41F);
        if ( *(__int64 (__fastcall **)())(v219 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v226 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v226 )
              ipc_log_string(v226, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1344672);
          }
        }
        v222 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1344696);
        v190 = *v222;
        v223 = ipa3_ctx;
        v224 = v222;
        if ( *v222 == nop_read )
        {
          if ( ipa3_ctx && (v225 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            ipc_log_string(v225, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1344696);
            v190 = *v224;
            v223 = ipa3_ctx;
          }
          else
          {
            v190 = nop_read;
          }
        }
        v191 = *(_QWORD *)(v223 + 44872) + 1344696LL;
        if ( *((_DWORD *)v190 - 1) != -1536295579 )
          __break(0x8229u);
        v192 = ((__int64 (__fastcall *)(__int64))v190)(v191);
        if ( *v224 == act_read )
          v193 = 0xFFFFFFF;
        else
          v193 = -1;
        v194 = &ipa_reg_save[v188++];
        v194[460] = v193 & v192;
      }
      while ( v188 != 6 );
      v227 = 0;
      v228 = 0;
      do
      {
        v233 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1345092);
        v234 = *(_DWORD **)(v233 + 8);
        v235 = v233;
        v236 = *(_QWORD *)(ipa3_ctx + 44872) + 1345092LL;
        if ( *(v234 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v234)(v236, (unsigned int)(v227 * 4) + (v228 & 3));
        if ( *(__int64 (__fastcall **)())(v235 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v243 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v243 )
              ipc_log_string(v243, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1345092);
          }
        }
        v237 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1345136);
        v239 = *v237;
        v240 = ipa3_ctx;
        v241 = v237;
        if ( *v237 == nop_read )
        {
          if ( ipa3_ctx && (v242 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v238 = ipc_log_string(v242, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1345136);
            v239 = *v241;
            v240 = ipa3_ctx;
          }
          else
          {
            v239 = nop_read;
          }
        }
        v244 = *(_QWORD *)(v240 + 44872) + 1345136LL;
        if ( *((_DWORD *)v239 - 1) != -1536295579 )
          __break(0x8229u);
        v245 = ((__int64 (__fastcall *)(__int64, long double))v239)(v244, v238);
        if ( *v241 == act_read )
          v246 = 511;
        else
          v246 = -1;
        ipa_reg_save[v227 + 554] = v246 & v245;
        v247 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1345140);
        v249 = *v247;
        v250 = ipa3_ctx;
        v251 = v247;
        if ( *v247 == nop_read )
        {
          if ( ipa3_ctx && (v252 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v248 = ipc_log_string(v252, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1345140);
            v249 = *v251;
            v250 = ipa3_ctx;
          }
          else
          {
            v249 = nop_read;
          }
        }
        v253 = v228 & 0xFFFFF803;
        v254 = *(_QWORD *)(v250 + 44872) + 1345140LL;
        if ( *((_DWORD *)v249 - 1) != -1536295579 )
          __break(0x8229u);
        v255 = ((__int64 (__fastcall *)(__int64, long double))v249)(v254, v248);
        if ( *v251 == act_read )
          v256 = 127;
        else
          v256 = -1;
        v228 = v253 | (v227 * 4) | 0x400;
        ipa_reg_save[v227 + 522] = v256 & v255;
        v257 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1345092);
        v258 = *(_DWORD **)(v257 + 8);
        v259 = *(_QWORD *)(ipa3_ctx + 44872) + 1345092LL;
        if ( *(v258 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v258)(v259, v228 & 0x47F);
        if ( *(__int64 (__fastcall **)())(v257 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v263 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v263 )
              ipc_log_string(v263, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1345092);
          }
        }
        v260 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1345096);
        v229 = *v260;
        v261 = ipa3_ctx;
        if ( *v260 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v262 = v260;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword_masked",
              948,
              1345096);
            v229 = *v262;
            v261 = ipa3_ctx;
          }
          else
          {
            v229 = nop_read;
          }
        }
        v230 = *(_QWORD *)(v261 + 44872) + 1345096LL;
        if ( *((_DWORD *)v229 - 1) != -1536295579 )
          __break(0x8228u);
        v231 = ((__int64 (__fastcall *)(__int64))v229)(v230);
        v232 = &ipa_reg_save[v227++];
        v232[490] = v231;
      }
      while ( v227 != 32 );
      v264 = 0;
      v265 = 0;
      v266 = (int *)&unk_2059E4;
      do
      {
        v271 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1345068);
        v272 = *(_DWORD **)(v271 + 8);
        v273 = v271;
        v274 = *(_QWORD *)(ipa3_ctx + 44872) + 1345068LL;
        if ( *(v272 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v272)(v274, (unsigned int)v264 + (v265 & 3));
        if ( *(__int64 (__fastcall **)())(v273 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v281 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v281 )
              ipc_log_string(v281, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1345068);
          }
        }
        v275 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1345080);
        v277 = *v275;
        v278 = ipa3_ctx;
        v279 = v275;
        if ( *v275 == nop_read )
        {
          if ( ipa3_ctx && (v280 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v276 = ipc_log_string(v280, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1345080);
            v277 = *v279;
            v278 = ipa3_ctx;
          }
          else
          {
            v277 = nop_read;
          }
        }
        v282 = *(_QWORD *)(v278 + 44872) + 1345080LL;
        if ( *((_DWORD *)v277 - 1) != -1536295579 )
          __break(0x8229u);
        v283 = ((__int64 (__fastcall *)(__int64, long double))v277)(v282, v276);
        if ( *v279 == act_read )
          v284 = 511;
        else
          v284 = -1;
        *v266 = v284 & v283;
        v285 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1345088);
        v287 = *v285;
        v288 = ipa3_ctx;
        v289 = v285;
        if ( *v285 == nop_read )
        {
          if ( ipa3_ctx && (v290 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            v286 = ipc_log_string(v290, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1345088);
            v287 = *v289;
            v288 = ipa3_ctx;
          }
          else
          {
            v287 = nop_read;
          }
        }
        v291 = v265 & 0xFFFFF00B;
        v292 = *(_QWORD *)(v288 + 44872) + 1345088LL;
        if ( *((_DWORD *)v287 - 1) != -1536295579 )
          __break(0x8229u);
        v293 = ((__int64 (__fastcall *)(__int64, long double))v287)(v292, v286);
        if ( *v289 == act_read )
          v294 = 127;
        else
          v294 = -1;
        v265 = v291 | v264 | 4;
        *(v266 - 32) = v294 & v293;
        v295 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1345068);
        v296 = *(_DWORD **)(v295 + 8);
        v297 = *(_QWORD *)(ipa3_ctx + 44872) + 1345068LL;
        if ( *(v296 - 1) != -1783303382 )
          __break(0x8229u);
        ((void (__fastcall *)(__int64, _QWORD))v296)(v297, v265 & 0x1F7);
        if ( *(__int64 (__fastcall **)())(v295 + 8) == nop_write )
        {
          if ( ipa3_ctx )
          {
            v302 = *(_QWORD *)(ipa3_ctx + 34160);
            if ( v302 )
              ipc_log_string(v302, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1345068);
          }
        }
        v298 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1345076);
        v267 = *v298;
        v299 = ipa3_ctx;
        v300 = v298;
        if ( *v298 == nop_read )
        {
          if ( ipa3_ctx && (v301 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
          {
            ipc_log_string(v301, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1345076);
            v267 = *v300;
            v299 = ipa3_ctx;
          }
          else
          {
            v267 = nop_read;
          }
        }
        v268 = *(_QWORD *)(v299 + 44872) + 1345076LL;
        if ( *((_DWORD *)v267 - 1) != -1536295579 )
          __break(0x8229u);
        v269 = ((__int64 (__fastcall *)(__int64))v267)(v268);
        v264 += 16;
        if ( *v300 == act_read )
          v270 = 0x7FFFFFF;
        else
          v270 = -1;
        *(v266 - 64) = v270 & v269;
        ++v266;
      }
      while ( v264 != 512 );
      v303 = 0;
      v304 = 0;
      v305 = (char *)&unk_205A6C;
      do
      {
        v306 = 0;
        v592 = v303;
        v307 = 16 * (v303 & 7);
        do
        {
          v313 = v304 & 0xFFFFC08F;
          v304 = v307 + (v304 & 0xFFFFC08F);
          v314 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1343512);
          v315 = *(_DWORD **)(v314 + 8);
          v316 = *(_QWORD *)(ipa3_ctx + 44872) + 1343512LL;
          if ( *(v315 - 1) != -1783303382 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD))v315)(v316, v304 & 0x3F77);
          if ( *(__int64 (__fastcall **)())(v314 + 8) == nop_write )
          {
            if ( ipa3_ctx )
            {
              v323 = *(_QWORD *)(ipa3_ctx + 34160);
              if ( v323 )
                ipc_log_string(v323, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1343512);
            }
          }
          v317 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1343516);
          v319 = *v317;
          v320 = ipa3_ctx;
          v321 = v317;
          if ( *v317 == nop_read )
          {
            if ( ipa3_ctx && (v322 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
            {
              v318 = ipc_log_string(
                       v322,
                       "ipa %s:%d nop read action for address 0x%X\n",
                       "in_dword_masked",
                       948,
                       1343516);
              v319 = *v321;
              v320 = ipa3_ctx;
            }
            else
            {
              v319 = nop_read;
            }
          }
          v324 = *(_QWORD *)(v320 + 44872) + 1343516LL;
          if ( *((_DWORD *)v319 - 1) != -1536295579 )
            __break(0x8229u);
          v325 = ((__int64 (__fastcall *)(__int64, long double))v319)(v324, v318);
          if ( *v321 == act_read )
            v326 = 1011;
          else
            v326 = -1;
          *(_DWORD *)&v305[v306] = v326 & v325;
          v327 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1343520);
          v308 = *v327;
          v328 = ipa3_ctx;
          v329 = v327;
          if ( *v327 == nop_read )
          {
            if ( ipa3_ctx && (v330 = *(_QWORD *)(ipa3_ctx + 34160)) != 0 )
            {
              ipc_log_string(v330, "ipa %s:%d nop read action for address 0x%X\n", "in_dword_masked", 948, 1343520);
              v308 = *v329;
              v328 = ipa3_ctx;
            }
            else
            {
              v308 = nop_read;
            }
          }
          v309 = *(_QWORD *)(v328 + 44872) + 1343520LL;
          if ( *((_DWORD *)v308 - 1) != -1536295579 )
            __break(0x8229u);
          v310 = ((__int64 (__fastcall *)(__int64))v308)(v309);
          v307 += 256;
          v311 = &v305[v306];
          v306 += 4;
          if ( *v329 == act_read )
            v312 = 133690355;
          else
            v312 = -1;
          *((_DWORD *)v311 + 704) = v312 & v310;
        }
        while ( v306 != 256 );
        v305 += 256;
        v304 = v313 + v307 - 256;
        v303 = v592 + 1;
      }
      while ( v592 != 10 );
      if ( *(_BYTE *)(ipa3_ctx + 44861) == 1 )
        ipa_hal_save_regs_save_ipa_testbus();
    }
    v331 = 0;
    v332 = &unk_20994C;
    do
    {
      v335 = *(_DWORD *)((char *)&ipa_reg_save_gsi_ch_test_bus_selector_array + v331);
      *(v332 - 51) = v335;
      v336 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(20480);
      v337 = *(_DWORD **)(v336 + 8);
      v338 = v336;
      v339 = *(_QWORD *)(ipa3_ctx + 44872) + 20480LL;
      if ( *(v337 - 1) != -1783303382 )
        __break(0x8229u);
      ((void (__fastcall *)(__int64, _QWORD))v337)(v339, v335);
      if ( *(__int64 (__fastcall **)())(v338 + 8) == nop_write )
      {
        if ( ipa3_ctx )
        {
          v343 = *(_QWORD *)(ipa3_ctx + 34160);
          if ( v343 )
            ipc_log_string(v343, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 20480);
        }
      }
      v340 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(20488);
      v333 = *v340;
      v341 = ipa3_ctx;
      if ( *v340 == nop_read )
      {
        if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
        {
          v342 = v340;
          ipc_log_string(
            *(_QWORD *)(ipa3_ctx + 34160),
            "ipa %s:%d nop read action for address 0x%X\n",
            "in_dword_masked",
            948,
            20488);
          v333 = *v342;
          v341 = ipa3_ctx;
        }
        else
        {
          v333 = nop_read;
        }
      }
      v331 += 4;
      v334 = *(_QWORD *)(v341 + 44872) + 20488LL;
      if ( *((_DWORD *)v333 - 1) != -1536295579 )
        __break(0x8228u);
      *v332++ = ((__int64 (__fastcall *)(__int64))v333)(v334);
    }
    while ( v331 != 204 );
    byte_20A6C0 = 0;
    byte_20A6C8 = 1;
    v344 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1312016);
    v345 = *v344;
    v346 = ipa3_ctx;
    if ( *v344 == nop_read )
    {
      if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
      {
        v347 = v344;
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34160),
          "ipa %s:%d nop read action for address 0x%X\n",
          "in_dword_masked",
          948,
          1312016);
        v345 = *v347;
        v346 = ipa3_ctx;
      }
      else
      {
        v345 = nop_read;
      }
    }
    v348 = *(_QWORD *)(v346 + 44872) + 1312016LL;
    if ( *((_DWORD *)v345 - 1) != -1536295579 )
      __break(0x8228u);
    v349 = ((__int64 (__fastcall *)(__int64))v345)(v348);
    byte_20A6C1 = v349 & 0x3F;
    byte_20A6C9 = HIBYTE(v349) & 0x3F;
    v350 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1312048);
    v351 = *v350;
    v352 = ipa3_ctx;
    if ( *v350 == nop_read )
    {
      if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
      {
        v353 = v350;
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34160),
          "ipa %s:%d nop read action for address 0x%X\n",
          "in_dword_masked",
          948,
          1312048);
        v351 = *v353;
        v352 = ipa3_ctx;
      }
      else
      {
        v351 = nop_read;
      }
    }
    v354 = *(_QWORD *)(v352 + 44872) + 1312048LL;
    if ( *((_DWORD *)v351 - 1) != -1536295579 )
      __break(0x8228u);
    v355 = ((__int64 (__fastcall *)(__int64))v351)(v354);
    byte_20A6C2 = v355 & 0x3F;
    byte_20A6CA = HIBYTE(v355) & 0x3F;
    v356 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1312080);
    v357 = *v356;
    v358 = ipa3_ctx;
    if ( *v356 == nop_read )
    {
      if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
      {
        v359 = v356;
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34160),
          "ipa %s:%d nop read action for address 0x%X\n",
          "in_dword_masked",
          948,
          1312080);
        v357 = *v359;
        v358 = ipa3_ctx;
      }
      else
      {
        v357 = nop_read;
      }
    }
    v360 = *(_QWORD *)(v358 + 44872) + 1312080LL;
    if ( *((_DWORD *)v357 - 1) != -1536295579 )
      __break(0x8228u);
    v361 = ((__int64 (__fastcall *)(__int64))v357)(v360);
    byte_20A6C3 = v361 & 0x3F;
    byte_20A6CB = HIBYTE(v361) & 0x3F;
    v362 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1312112);
    v363 = *v362;
    v364 = ipa3_ctx;
    if ( *v362 == nop_read )
    {
      if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
      {
        v365 = v362;
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34160),
          "ipa %s:%d nop read action for address 0x%X\n",
          "in_dword_masked",
          948,
          1312112);
        v363 = *v365;
        v364 = ipa3_ctx;
      }
      else
      {
        v363 = nop_read;
      }
    }
    v366 = *(_QWORD *)(v364 + 44872) + 1312112LL;
    if ( *((_DWORD *)v363 - 1) != -1536295579 )
      __break(0x8228u);
    v367 = ((__int64 (__fastcall *)(__int64))v363)(v366);
    byte_20A6C4 = v367 & 0x3F;
    byte_20A6CC = HIBYTE(v367) & 0x3F;
    v368 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1312144);
    v369 = *v368;
    v370 = ipa3_ctx;
    if ( *v368 == nop_read )
    {
      if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
      {
        v371 = v368;
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34160),
          "ipa %s:%d nop read action for address 0x%X\n",
          "in_dword_masked",
          948,
          1312144);
        v369 = *v371;
        v370 = ipa3_ctx;
      }
      else
      {
        v369 = nop_read;
      }
    }
    v372 = *(_QWORD *)(v370 + 44872) + 1312144LL;
    if ( *((_DWORD *)v369 - 1) != -1536295579 )
      __break(0x8228u);
    v373 = ((__int64 (__fastcall *)(__int64))v369)(v372);
    byte_20A6C5 = v373 & 0x3F;
    byte_20A6CD = HIBYTE(v373) & 0x3F;
    v374 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1312272);
    v375 = *v374;
    v376 = ipa3_ctx;
    if ( *v374 == nop_read )
    {
      if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
      {
        v377 = v374;
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34160),
          "ipa %s:%d nop read action for address 0x%X\n",
          "in_dword_masked",
          948,
          1312272);
        v375 = *v377;
        v376 = ipa3_ctx;
      }
      else
      {
        v375 = nop_read;
      }
    }
    v378 = *(_QWORD *)(v376 + 44872) + 1312272LL;
    if ( *((_DWORD *)v375 - 1) != -1536295579 )
      __break(0x8228u);
    v379 = ((__int64 (__fastcall *)(__int64))v375)(v378);
    byte_20A6C6 = v379 & 0x3F;
    byte_20A6CE = HIBYTE(v379) & 0x3F;
    v380 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1312304);
    v381 = *v380;
    v382 = ipa3_ctx;
    if ( *v380 == nop_read )
    {
      if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
      {
        v383 = v380;
        ipc_log_string(
          *(_QWORD *)(ipa3_ctx + 34160),
          "ipa %s:%d nop read action for address 0x%X\n",
          "in_dword_masked",
          948,
          1312304);
        v381 = *v383;
        v382 = ipa3_ctx;
      }
      else
      {
        v381 = nop_read;
      }
    }
    v384 = *(_QWORD *)(v382 + 44872) + 1312304LL;
    if ( *((_DWORD *)v381 - 1) != -1536295579 )
      __break(0x8228u);
    v385 = ((__int64 (__fastcall *)(__int64))v381)(v384);
    v386 = 0;
    byte_20A6C7 = v385 & 0x3F;
    byte_20A6CF = HIBYTE(v385) & 0x3F;
    do
    {
      v391 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(v386 * 4 + 20736));
      v387 = *v391;
      v392 = ipa3_ctx;
      if ( *v391 == nop_read )
      {
        if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
        {
          v393 = v391;
          ipc_log_string(
            *(_QWORD *)(ipa3_ctx + 34160),
            "ipa %s:%d nop read action for address 0x%X\n",
            "in_dword_masked",
            948,
            v386 * 4 + 20736);
          v387 = *v393;
          v392 = ipa3_ctx;
        }
        else
        {
          v387 = nop_read;
        }
      }
      v388 = *(_QWORD *)(v392 + 44872) + v386 * 4 + 20736;
      if ( *((_DWORD *)v387 - 1) != -1536295579 )
        __break(0x8228u);
      v389 = ((__int64 (__fastcall *)(__int64))v387)(v388);
      v390 = &ipa_reg_save[v386++];
      v390[4762] = v389;
    }
    while ( v386 != 32 );
    for ( j = 0; j != 8; ++j )
    {
      v400 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(j * 4 + 20896));
      v395 = *v400;
      v401 = ipa3_ctx;
      if ( *v400 == nop_read )
      {
        if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
        {
          v402 = v400;
          ipc_log_string(
            *(_QWORD *)(ipa3_ctx + 34160),
            "ipa %s:%d nop read action for address 0x%X\n",
            "in_dword_masked",
            948,
            j * 4 + 20896);
          v395 = *v402;
          v401 = ipa3_ctx;
        }
        else
        {
          v395 = nop_read;
        }
      }
      v396 = *(_QWORD *)(v401 + 44872) + j * 4 + 20896;
      if ( *((_DWORD *)v395 - 1) != -1536295579 )
        __break(0x8228u);
      v397 = ((__int64 (__fastcall *)(__int64))v395)(v396);
      v399 = &ipa_reg_save[j];
      *((_WORD *)v399 + 9604) = v397;
    }
    v403 = 0x3FFFFFFFFFFFFD8FLL;
    do
    {
      if ( (ipa_reg_save[v403 + 3701] & 0x100) != 0 )
      {
        v406 = 80 * (unsigned __int8)ipa_reg_save[v403 + 3701];
        v407 = 80LL * (unsigned __int8)ipa_reg_save[v403 + 3701] + 24648;
        v408 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)v407);
        v410 = *v408;
        v411 = ipa3_ctx;
        if ( *v408 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v412 = v408;
            v409 = ipc_log_string(
                     *(_QWORD *)(ipa3_ctx + 34160),
                     "ipa %s:%d nop read action for address 0x%X\n",
                     "in_dword_masked",
                     948,
                     v407);
            v410 = *v412;
            v411 = ipa3_ctx;
          }
          else
          {
            v410 = nop_read;
          }
        }
        v413 = *(_QWORD *)(v411 + 44872) + v407;
        if ( *((_DWORD *)v410 - 1) != -1536295579 )
          __break(0x8228u);
        v414 = v406 + 24652;
        ipa_reg_save[v403 + 3702] = ((__int64 (__fastcall *)(__int64, long double))v410)(v413, v409);
        v415 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(v406 + 24652));
        v417 = ipa3_ctx;
        v418 = *v415;
        if ( *v415 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v419 = v415;
            v416 = ipc_log_string(
                     *(_QWORD *)(ipa3_ctx + 34160),
                     "ipa %s:%d nop read action for address 0x%X\n",
                     "in_dword_masked",
                     948,
                     v414);
            v418 = *v419;
            v417 = ipa3_ctx;
          }
          else
          {
            v418 = nop_read;
          }
        }
        v420 = *(_QWORD *)(v417 + 44872) + v414;
        if ( *((_DWORD *)v418 - 1) != -1536295579 )
          __break(0x8228u);
        v421 = v406 + 24604;
        ipa_reg_save[v403 + 3703] = ((__int64 (__fastcall *)(__int64, long double))v418)(v420, v416);
        v422 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(v406 + 24604));
        v404 = *v422;
        v423 = ipa3_ctx;
        if ( *v422 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v424 = v422;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword_masked",
              948,
              v421);
            v404 = *v424;
            v423 = ipa3_ctx;
          }
          else
          {
            v404 = nop_read;
          }
        }
        v405 = *(_QWORD *)(v423 + 44872) + v421;
        if ( *((_DWORD *)v404 - 1) != -1536295579 )
          __break(0x8228u);
        ipa_reg_save[v403 + 3704] = ((__int64 (__fastcall *)(__int64))v404)(v405);
      }
      v403 += 25;
    }
    while ( v403 * 4 );
    v425 = 0;
    v426 = 1;
    do
    {
      v429 = &ipa_reg_save[25 * v425];
      v430 = v426;
      if ( (v429[3701] & 0x100) != 0 )
      {
        v431 = 80 * (unsigned __int8)v429[3701];
        v432 = 80LL * (unsigned __int8)v429[3701] + 24648;
        v433 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)v432);
        v435 = ipa3_ctx;
        v436 = *v433;
        if ( *v433 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v437 = v433;
            v434 = ipc_log_string(
                     *(_QWORD *)(ipa3_ctx + 34160),
                     "ipa %s:%d nop read action for address 0x%X\n",
                     "in_dword_masked",
                     948,
                     v432);
            v436 = *v437;
            v435 = ipa3_ctx;
          }
          else
          {
            v436 = nop_read;
          }
        }
        v438 = v429 + 3680;
        v439 = *(_QWORD *)(v435 + 44872) + v432;
        if ( *((_DWORD *)v436 - 1) != -1536295579 )
          __break(0x8228u);
        v440 = v431 + 24652;
        v438[22] = ((__int64 (__fastcall *)(__int64, long double))v436)(v439, v434);
        v441 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(v431 + 24652));
        v443 = ipa3_ctx;
        v444 = *v441;
        if ( *v441 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v445 = v441;
            v442 = ipc_log_string(
                     *(_QWORD *)(ipa3_ctx + 34160),
                     "ipa %s:%d nop read action for address 0x%X\n",
                     "in_dword_masked",
                     948,
                     v440);
            v444 = *v445;
            v443 = ipa3_ctx;
          }
          else
          {
            v444 = nop_read;
          }
        }
        v446 = *(_QWORD *)(v443 + 44872) + v440;
        if ( *((_DWORD *)v444 - 1) != -1536295579 )
          __break(0x8228u);
        v447 = v431 + 24604;
        v438[23] = ((__int64 (__fastcall *)(__int64, long double))v444)(v446, v442);
        v448 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(v431 + 24604));
        v449 = ipa3_ctx;
        v427 = *v448;
        if ( *v448 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v450 = v448;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword_masked",
              948,
              v447);
            v427 = *v450;
            v449 = ipa3_ctx;
          }
          else
          {
            v427 = nop_read;
          }
        }
        v428 = *(_QWORD *)(v449 + 44872) + v447;
        if ( *((_DWORD *)v427 - 1) != -1536295579 )
          __break(0x8228u);
        v438[24] = ((__int64 (__fastcall *)(__int64))v427)(v428);
      }
      v426 = 0;
      v425 = 1;
    }
    while ( (v430 & 1) != 0 );
    v451 = 0x3FFFFFFFFFFFFEEDLL;
    do
    {
      if ( (ipa_reg_save[v451 + 4026] & 0x100) != 0 )
      {
        v454 = 80 * (unsigned __int8)ipa_reg_save[v451 + 4026];
        v455 = 80LL * (unsigned __int8)ipa_reg_save[v451 + 4026] + 24648;
        v456 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)v455);
        v458 = ipa3_ctx;
        v459 = *v456;
        if ( *v456 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v460 = v456;
            v457 = ipc_log_string(
                     *(_QWORD *)(ipa3_ctx + 34160),
                     "ipa %s:%d nop read action for address 0x%X\n",
                     "in_dword_masked",
                     948,
                     v455);
            v459 = *v460;
            v458 = ipa3_ctx;
          }
          else
          {
            v459 = nop_read;
          }
        }
        v461 = *(_QWORD *)(v458 + 44872) + v455;
        if ( *((_DWORD *)v459 - 1) != -1536295579 )
          __break(0x8228u);
        v462 = v454 + 24652;
        ipa_reg_save[v451 + 4027] = ((__int64 (__fastcall *)(__int64, long double))v459)(v461, v457);
        v463 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(v454 + 24652));
        v465 = ipa3_ctx;
        v466 = *v463;
        if ( *v463 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v467 = v463;
            v464 = ipc_log_string(
                     *(_QWORD *)(ipa3_ctx + 34160),
                     "ipa %s:%d nop read action for address 0x%X\n",
                     "in_dword_masked",
                     948,
                     v462);
            v466 = *v467;
            v465 = ipa3_ctx;
          }
          else
          {
            v466 = nop_read;
          }
        }
        v468 = *(_QWORD *)(v465 + 44872) + v462;
        if ( *((_DWORD *)v466 - 1) != -1536295579 )
          __break(0x8228u);
        v469 = v454 + 24604;
        ipa_reg_save[v451 + 4028] = ((__int64 (__fastcall *)(__int64, long double))v466)(v468, v464);
        v470 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(v454 + 24604));
        v452 = *v470;
        v471 = ipa3_ctx;
        if ( *v470 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v472 = v470;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword_masked",
              948,
              v469);
            v452 = *v472;
            v471 = ipa3_ctx;
          }
          else
          {
            v452 = nop_read;
          }
        }
        v453 = *(_QWORD *)(v471 + 44872) + v469;
        if ( *((_DWORD *)v452 - 1) != -1536295579 )
          __break(0x8228u);
        ipa_reg_save[v451 + 4029] = ((__int64 (__fastcall *)(__int64))v452)(v453);
      }
      v451 += 25;
    }
    while ( v451 * 4 );
    if ( *(_BYTE *)(ipa3_ctx + 44862) == 1 )
    {
      if ( *(__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1351680) == act_read )
      {
        v473 = &unk_209B6C;
        v474 = &unk_209BC0;
        v475 = *(_QWORD *)(ipa3_ctx + 44872);
        memcpy(&unk_209BC0, (const void *)(v475 + 1351680), 0xB0u);
        memcpy(&unk_209C70, (const void *)(v475 + 1351936), 0xB0u);
        memcpy(&unk_209D20, (const void *)(v475 + 1352192), 0xB0u);
        v476 = *(_QWORD *)(ipa3_ctx + 44872);
        memcpy(&unk_209DD0, (const void *)(v476 + 1352448), 0xB0u);
        memcpy(&unk_209E80, (const void *)(v476 + 1352704), 0xB0u);
        memcpy(&unk_209F30, (const void *)(v476 + 1352960), 0xB0u);
        v477 = *(_QWORD *)(ipa3_ctx + 44872);
        memcpy(&unk_209FE0, (const void *)(v477 + 1353216), 0xB0u);
        memcpy(&unk_20A090, (const void *)(v477 + 1353472), 0xB0u);
        memcpy(&unk_20A140, (const void *)(v477 + 1353728), 0xB0u);
        v478 = *(_QWORD *)(ipa3_ctx + 44872);
        memcpy(&unk_20A1F0, (const void *)(v478 + 1353984), 0xB0u);
        memcpy(&unk_20A2A0, (const void *)(v478 + 1354240), 0xB0u);
        memcpy(&unk_20A350, (const void *)(v478 + 1354496), 0xB0u);
        v479 = *(_QWORD *)(ipa3_ctx + 44872);
        memcpy(&unk_20A400, (const void *)(v479 + 1354752), 0xB0u);
        memcpy(&unk_20A4B0, (const void *)(v479 + 1355008), 0xB0u);
        memcpy(&unk_20A560, (const void *)(v479 + 1355264), 0xB0u);
        memcpy(&unk_20A610, (const void *)(*(_QWORD *)(ipa3_ctx + 44872) + 1355520LL), 0xB0u);
        v480 = in_dword_masked(0x148018u, 16247, 3);
        v481 = v480 & 0xFF8F;
        out_dword(1343512, v480 & 0x3F07);
        v482 = 0;
        v483 = (int *)&unk_209B80;
        do
        {
          v481 = v482 + (v481 & 0xC0FF);
          v484 = ((__int64 (__fastcall *)(__int64))get_access_funcs)(1343512);
          v485 = *(_DWORD **)(v484 + 8);
          v486 = *(_QWORD *)(ipa3_ctx + 44872) + 1343512LL;
          if ( *(v485 - 1) != -1783303382 )
            __break(0x8229u);
          ((void (__fastcall *)(__int64, _QWORD))v485)(v486, v481 & 0xF77);
          if ( *(__int64 (__fastcall **)())(v484 + 8) == nop_write )
          {
            if ( ipa3_ctx )
            {
              v492 = *(_QWORD *)(ipa3_ctx + 34160);
              if ( v492 )
                ipc_log_string(v492, "ipa %s:%d nop write action for address 0x%X\n", "out_dword", 971, 1343512);
            }
          }
          v487 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(__int64))get_access_funcs)(1343516);
          v489 = *v487;
          v490 = ipa3_ctx;
          if ( *v487 == nop_read )
          {
            if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
            {
              v491 = v487;
              v488 = ipc_log_string(
                       *(_QWORD *)(ipa3_ctx + 34160),
                       "ipa %s:%d nop read action for address 0x%X\n",
                       "in_dword_masked",
                       948,
                       1343516);
              v489 = *v491;
              v490 = ipa3_ctx;
            }
            else
            {
              v489 = nop_read;
            }
          }
          v493 = *(_QWORD *)(v490 + 44872) + 1343516LL;
          if ( *((_DWORD *)v489 - 1) != -1536295579 )
            __break(0x8228u);
          if ( (((__int64 (__fastcall *)(__int64, long double))v489)(v493, v488) & 1) != 0 )
          {
            *v473 = 1;
            *v483 = (*v474 >> 8) & 0x1F;
          }
          v482 += 256;
          ++v473;
          v474 += 44;
          ++v483;
        }
        while ( v482 != 4096 );
      }
      else
      {
        printk(&unk_3F441C, "ipa_save_registers");
        v494 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v495 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v495 )
          {
            v398 = ipc_log_string(
                     v495,
                     "ipa %s:%d IPA_CTX_ID is not currently accessible\n",
                     "ipa_save_registers",
                     1252);
            v494 = ipa3_ctx;
          }
          v496 = *(_QWORD *)(v494 + 34160);
          if ( v496 )
            v398 = ipc_log_string(
                     v496,
                     "ipa %s:%d IPA_CTX_ID is not currently accessible\n",
                     "ipa_save_registers",
                     1252);
        }
      }
    }
    if ( *(_BYTE *)(ipa3_ctx + 44863) == 1 )
    {
      for ( k = 0; k != 40704; k += 4 )
      {
        v500 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD, long double))get_access_funcs)(
                                            (unsigned int)(k + 1703936),
                                            v398);
        v498 = *v500;
        v501 = ipa3_ctx;
        if ( *v500 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v502 = v500;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword",
              930,
              k + 1703936);
            v498 = *v502;
            v501 = ipa3_ctx;
          }
          else
          {
            v498 = nop_read;
          }
        }
        v499 = *(_QWORD *)(v501 + 44872) + k + 1703936;
        if ( *((_DWORD *)v498 - 1) != -1536295579 )
          __break(0x8228u);
        *(_DWORD *)(qword_207E48 + k) = ((__int64 (__fastcall *)(__int64))v498)(v499);
      }
      for ( m = 0; m != 19232; m += 4 )
      {
        v506 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(m + 1376256));
        v507 = ipa3_ctx;
        v504 = *v506;
        if ( *v506 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v508 = v506;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword",
              930,
              m + 1376256);
            v504 = *v508;
            v507 = ipa3_ctx;
          }
          else
          {
            v504 = nop_read;
          }
        }
        v505 = *(_QWORD *)(v507 + 44872) + m + 1376256;
        if ( *((_DWORD *)v504 - 1) != -1536295579 )
          __break(0x8228u);
        *(_DWORD *)(qword_207E50 + m) = ((__int64 (__fastcall *)(__int64))v504)(v505);
      }
      for ( n = 0; n != 256; n += 4 )
      {
        v512 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(n + 1843200));
        v513 = ipa3_ctx;
        v510 = *v512;
        if ( *v512 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v514 = v512;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword",
              930,
              n + 1843200);
            v510 = *v514;
            v513 = ipa3_ctx;
          }
          else
          {
            v510 = nop_read;
          }
        }
        v511 = *(_QWORD *)(v513 + 44872) + n + 1843200;
        if ( *((_DWORD *)v510 - 1) != -1536295579 )
          __break(0x8228u);
        *(_DWORD *)(qword_207E58 + n) = ((__int64 (__fastcall *)(__int64))v510)(v511);
      }
      for ( ii = 0; ii != 47536; ii += 4 )
      {
        v518 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(ii + 1441792));
        v519 = ipa3_ctx;
        v516 = *v518;
        if ( *v518 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v520 = v518;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword",
              930,
              ii + 1441792);
            v516 = *v520;
            v519 = ipa3_ctx;
          }
          else
          {
            v516 = nop_read;
          }
        }
        v517 = *(_QWORD *)(v519 + 44872) + ii + 1441792;
        if ( *((_DWORD *)v516 - 1) != -1536295579 )
          __break(0x8228u);
        *(_DWORD *)(qword_207E60 + ii) = ((__int64 (__fastcall *)(__int64))v516)(v517);
      }
      for ( jj = 0; jj != 768; jj += 4 )
      {
        v524 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)(jj + 1576960));
        v525 = ipa3_ctx;
        v522 = *v524;
        if ( *v524 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v526 = v524;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword",
              930,
              jj + 1576960);
            v522 = *v526;
            v525 = ipa3_ctx;
          }
          else
          {
            v522 = nop_read;
          }
        }
        v523 = *(_QWORD *)(v525 + 44872) + jj + 1576960;
        if ( *((_DWORD *)v522 - 1) != -1536295579 )
          __break(0x8228u);
        *(_DWORD *)(qword_207E68 + jj) = ((__int64 (__fastcall *)(__int64))v522)(v523);
      }
      v527 = 0;
      v528 = 24576;
      do
      {
        v531 = (__int64 (__fastcall **)())((__int64 (__fastcall *)(_QWORD))get_access_funcs)((unsigned int)v528);
        v532 = ipa3_ctx;
        v529 = *v531;
        if ( *v531 == nop_read )
        {
          if ( ipa3_ctx && *(_QWORD *)(ipa3_ctx + 34160) )
          {
            v533 = v531;
            ipc_log_string(
              *(_QWORD *)(ipa3_ctx + 34160),
              "ipa %s:%d nop read action for address 0x%X\n",
              "in_dword",
              930,
              v528);
            v529 = *v533;
            v532 = ipa3_ctx;
          }
          else
          {
            v529 = nop_read;
          }
        }
        v530 = *(_QWORD *)(v532 + 44872) + v528;
        if ( *((_DWORD *)v529 - 1) != -1536295579 )
          __break(0x8228u);
        v528 += 4;
        *(_DWORD *)(qword_207E70 + 4 * v527++) = ((__int64 (__fastcall *)(__int64))v529)(v530);
      }
      while ( v527 != 1344 );
      v534 = qword_207E48 << 8 >> 8;
      v535 = v534 + 0x8000000000LL;
      v536 = v534 - kimage_voffset;
      v537 = v535 >> 38;
      v538 = v535 + memstart_addr;
      if ( !v537 )
        v536 = v538;
      v593[0] = v536;
      printk(&unk_3E5614, "ipa_save_registers");
      v539 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v540 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v540 )
        {
          ipc_log_string(
            v540,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1287,
            "ipa_reg_save.ipa.ipa_iu_ptr",
            (const void *)qword_207E48,
            v593);
          v539 = ipa3_ctx;
        }
        v541 = *(_QWORD *)(v539 + 34160);
        if ( v541 )
          ipc_log_string(
            v541,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1287,
            "ipa_reg_save.ipa.ipa_iu_ptr",
            (const void *)qword_207E48,
            v593);
      }
      v542 = qword_207E50 << 8 >> 8;
      v543 = v542 + 0x8000000000LL;
      v544 = v542 - kimage_voffset;
      v545 = v543 >> 38;
      v546 = v543 + memstart_addr;
      if ( !v545 )
        v544 = v546;
      v593[0] = v544;
      printk(&unk_3E5614, "ipa_save_registers");
      v547 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v548 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v548 )
        {
          ipc_log_string(
            v548,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1288,
            "ipa_reg_save.ipa.ipa_sram_ptr",
            (const void *)qword_207E50,
            v593);
          v547 = ipa3_ctx;
        }
        v549 = *(_QWORD *)(v547 + 34160);
        if ( v549 )
          ipc_log_string(
            v549,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1288,
            "ipa_reg_save.ipa.ipa_sram_ptr",
            (const void *)qword_207E50,
            v593);
      }
      v550 = qword_207E58 << 8 >> 8;
      v551 = v550 + 0x8000000000LL;
      v552 = v550 - kimage_voffset;
      v553 = v551 >> 38;
      v554 = v551 + memstart_addr;
      if ( !v553 )
        v552 = v554;
      v593[0] = v552;
      printk(&unk_3E5614, "ipa_save_registers");
      v555 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v556 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v556 )
        {
          ipc_log_string(
            v556,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1289,
            "ipa_reg_save.ipa.ipa_mbox_ptr",
            (const void *)qword_207E58,
            v593);
          v555 = ipa3_ctx;
        }
        v557 = *(_QWORD *)(v555 + 34160);
        if ( v557 )
          ipc_log_string(
            v557,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1289,
            "ipa_reg_save.ipa.ipa_mbox_ptr",
            (const void *)qword_207E58,
            v593);
      }
      v558 = qword_207E60 << 8 >> 8;
      v559 = v558 + 0x8000000000LL;
      v560 = v558 - kimage_voffset;
      v561 = v559 >> 38;
      v562 = v559 + memstart_addr;
      if ( !v561 )
        v560 = v562;
      v593[0] = v560;
      printk(&unk_3E5614, "ipa_save_registers");
      v563 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v564 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v564 )
        {
          ipc_log_string(
            v564,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1290,
            "ipa_reg_save.ipa.ipa_hram_ptr",
            (const void *)qword_207E60,
            v593);
          v563 = ipa3_ctx;
        }
        v565 = *(_QWORD *)(v563 + 34160);
        if ( v565 )
          ipc_log_string(
            v565,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1290,
            "ipa_reg_save.ipa.ipa_hram_ptr",
            (const void *)qword_207E60,
            v593);
      }
      v566 = qword_207E68 << 8 >> 8;
      v567 = v566 + 0x8000000000LL;
      v568 = v566 - kimage_voffset;
      v569 = v567 >> 38;
      v570 = v567 + memstart_addr;
      if ( !v569 )
        v568 = v570;
      v593[0] = v568;
      printk(&unk_3E5614, "ipa_save_registers");
      v571 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v572 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v572 )
        {
          ipc_log_string(
            v572,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1291,
            "ipa_reg_save.ipa.ipa_seq_ptr",
            (const void *)qword_207E68,
            v593);
          v571 = ipa3_ctx;
        }
        v573 = *(_QWORD *)(v571 + 34160);
        if ( v573 )
          ipc_log_string(
            v573,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1291,
            "ipa_reg_save.ipa.ipa_seq_ptr",
            (const void *)qword_207E68,
            v593);
      }
      v574 = qword_207E70 << 8 >> 8;
      v575 = v574 + 0x8000000000LL;
      v576 = v574 - kimage_voffset;
      v577 = v575 >> 38;
      v578 = v575 + memstart_addr;
      if ( !v577 )
        v576 = v578;
      v593[0] = v576;
      printk(&unk_3E5614, "ipa_save_registers");
      v579 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v580 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v580 )
        {
          ipc_log_string(
            v580,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1292,
            "ipa_reg_save.ipa.ipa_gsi_ptr",
            (const void *)qword_207E70,
            v593);
          v579 = ipa3_ctx;
        }
        v581 = *(_QWORD *)(v579 + 34160);
        if ( v581 )
          ipc_log_string(
            v581,
            "ipa %s:%d %s: VIRT: %pK PHYS: %pa\n",
            "ipa_save_registers",
            1292,
            "ipa_reg_save.ipa.ipa_gsi_ptr",
            (const void *)qword_207E70,
            v593);
      }
    }
    v582 = ipa_reg_save[0];
    if ( (ipa_reg_save[0] & 3) != 2 )
    {
      v583 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v584 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v584 )
        {
          ipc_log_string(
            v584,
            "ipa %s:%d RX ACTIVITY_%d, ipa_state.rx_wait = %d, ipa_state.rx_idle = %d, ipa_state_rx_active.endpoints = %d (bitmask)\n",
            "ipa_reg_save_anomaly_check",
            1905,
            0,
            ipa_reg_save[0] & 1,
            ((unsigned int)ipa_reg_save[0] >> 1) & 1,
            dword_204FB4);
          v583 = ipa3_ctx;
          v582 = ipa_reg_save[0];
        }
        v585 = *(_QWORD *)(v583 + 34160);
        if ( v585 )
        {
          ipc_log_string(
            v585,
            "ipa %s:%d RX ACTIVITY_%d, ipa_state.rx_wait = %d, ipa_state.rx_idle = %d, ipa_state_rx_active.endpoints = %d (bitmask)\n",
            "ipa_reg_save_anomaly_check",
            1905,
            0,
            v582 & 1,
            (v582 >> 1) & 1,
            dword_204FB4);
          LOBYTE(v582) = ipa_reg_save[0];
        }
      }
      if ( (v582 & 4) == 0 )
      {
        v586 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v587 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v587 )
          {
            ipc_log_string(
              v587,
              "ipa %s:%d TX ACTIVITY, ipa_state.idle = %d, ipa_state_tx_wrapper.tx_idle = %d\n",
              "ipa_reg_save_anomaly_check",
              1911,
              0,
              dword_204FB8 & 1);
            v586 = ipa3_ctx;
          }
          v588 = *(_QWORD *)(v586 + 34160);
          if ( v588 )
            ipc_log_string(
              v588,
              "ipa %s:%d TX ACTIVITY, ipa_state.idle = %d, ipa_state_tx_wrapper.tx_idle = %d\n",
              "ipa_reg_save_anomaly_check",
              1911,
              ((unsigned int)ipa_reg_save[0] >> 2) & 1,
              dword_204FB8 & 1);
        }
      }
    }
    printk(&unk_3EE0B2, "ipa_save_registers");
    v589 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v590 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v590 )
      {
        ipc_log_string(v590, "ipa %s:%d Completed\n", "ipa_save_registers", 1297);
        v589 = ipa3_ctx;
      }
      v591 = *(_QWORD *)(v589 + 34160);
      if ( v591 )
        ipc_log_string(v591, "ipa %s:%d Completed\n", "ipa_save_registers", 1297);
    }
  }
  _ReadStatusReg(SP_EL0);
}
