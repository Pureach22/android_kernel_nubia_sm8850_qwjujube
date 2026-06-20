__int64 __fastcall dp_tu_calculate(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  unsigned int v5; // w11
  __int64 v6; // x9
  __int64 v7; // x11
  char v8; // w13
  bool v9; // cc
  __int64 v10; // x9
  __int64 v11; // x9
  char v12; // w11
  __int64 v13; // x9
  unsigned __int64 v14; // x11
  bool v15; // zf
  unsigned __int64 v16; // x9
  int v17; // w11
  unsigned __int64 v18; // x9
  int v19; // w12
  __int64 v20; // x11
  unsigned __int64 v21; // x12
  unsigned __int64 v22; // x14
  int v23; // w12
  unsigned __int64 v24; // x14
  __int64 v25; // x16
  bool v26; // cf
  __int64 v27; // x12
  __int64 v28; // x13
  unsigned int v29; // w14
  unsigned int v30; // w13
  __int64 v31; // x12
  __int64 v32; // x14
  __int64 v33; // x11
  signed __int64 v34; // x13
  __int64 v35; // x11
  char v36; // w16
  __int64 v37; // x12
  __int64 v38; // x13
  char v39; // w12
  unsigned __int64 v40; // x12
  unsigned __int64 v41; // x13
  char v42; // w14
  unsigned int v43; // w13
  char v44; // w11
  signed __int64 v45; // x12
  signed __int64 v46; // x11
  __int64 v48; // x12
  char v49; // w13
  unsigned __int64 v50; // x12
  __int64 v51; // x14
  __int64 i; // x17
  __int64 v53; // x0
  __int64 v54; // x1
  __int64 v55; // x2
  unsigned int v56; // w3
  unsigned int v57; // w2
  __int64 v58; // x1
  unsigned __int64 v59; // x0
  __int64 v60; // x0
  bool v61; // nf
  __int64 v62; // x0
  __int64 v63; // x2
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x1
  char v67; // w2
  __int64 v68; // x14
  __int64 v69; // x14
  __int64 v70; // x13
  __int64 v71; // x14
  __int64 v72; // x12
  unsigned int v73; // w14
  unsigned int v74; // w12
  __int64 v75; // x11
  bool v76; // zf
  unsigned __int64 v77; // x12
  unsigned __int64 v78; // x11
  unsigned __int64 v79; // x13
  __int64 v80; // x12
  unsigned __int64 v81; // x15
  int v82; // w13
  unsigned __int64 v83; // x15
  __int64 v84; // x17
  __int64 v85; // x9
  __int64 v86; // x12
  __int64 v87; // x13
  unsigned int v88; // w13
  unsigned int v89; // w12
  __int64 v90; // x9
  bool v91; // nf
  __int64 v92; // x10
  __int64 v93; // x11
  __int64 v94; // x10
  char v95; // w13
  __int64 v96; // x9
  __int64 v97; // x9
  char v98; // w10
  __int64 v99; // x9
  int v100; // w9
  __int64 ipc_log_context; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v103; // x0
  __int64 v104; // x10
  __int64 v105; // x9
  __int64 v106; // x9
  __int64 v107; // x11
  unsigned int v108; // w11
  unsigned int v109; // w10
  __int64 v110; // x9
  __int64 v111; // x8
  __int64 v112; // x8
  __int64 v113; // x10
  __int64 v114; // x8
  __int64 v115; // x8
  __int64 v116; // x9
  char v117; // w10
  __int64 v118; // x0
  __int64 v119; // x10
  __int64 v120; // x9
  __int64 v121; // x9
  __int64 v122; // x11
  unsigned int v123; // w11
  unsigned int v124; // w10
  __int64 v125; // x8
  bool v126; // zf
  unsigned __int64 v127; // x9
  unsigned __int64 v128; // x8
  __int64 v129; // x11
  unsigned __int64 v130; // x9
  __int64 v131; // x11
  unsigned __int64 v132; // x10
  unsigned __int64 v133; // x13
  int v134; // w12
  unsigned __int64 v135; // x13
  unsigned __int64 v136; // x15
  __int64 v137; // x8
  __int64 v138; // x9
  __int64 v139; // x10
  __int64 v140; // x11
  unsigned int v141; // w11
  unsigned int v142; // w10
  __int64 v143; // x8
  bool v144; // zf
  unsigned __int64 v145; // x9
  __int64 v146; // x12
  unsigned __int64 v147; // x8
  __int64 v148; // x11
  __int64 v149; // x10
  __int64 v150; // x8
  char v151; // w14
  bool v152; // cc
  __int64 v153; // x13
  char v154; // w12
  char v155; // w14
  bool v156; // nf
  __int64 v157; // x10
  __int64 v158; // x12
  __int64 v159; // x10
  __int64 v160; // x13
  unsigned int v161; // w14
  unsigned int v162; // w13
  __int64 v163; // x8
  bool v164; // zf
  unsigned __int64 v165; // x10
  __int64 v166; // x1
  unsigned __int64 v167; // x8
  __int64 v168; // x13
  int v169; // w16
  __int64 v170; // x17
  unsigned __int64 v171; // x15
  __int64 v172; // x2
  unsigned int v173; // w3
  unsigned int v174; // w2
  __int64 v175; // x1
  int v176; // w16
  __int64 v177; // x15
  signed __int64 v178; // x0
  __int64 v179; // x15
  __int64 v180; // x16
  unsigned __int64 v181; // x2
  __int64 v182; // x14
  __int64 v183; // x17
  char v184; // w4
  bool v185; // cc
  signed __int64 v186; // x3
  char v187; // w14
  __int64 v188; // x0
  char v189; // w6
  __int64 v190; // x14
  unsigned __int64 v191; // x3
  __int64 v192; // x0
  char v193; // w5
  bool v194; // cc
  signed __int64 v195; // x3
  __int64 v196; // x3
  char v197; // w17
  bool v198; // nf
  unsigned __int64 v199; // x16
  unsigned __int64 v200; // x27
  char v201; // w3
  __int64 v202; // x16
  __int64 v203; // x16
  char v204; // w17
  unsigned __int64 v205; // x0
  unsigned __int64 v206; // x16
  unsigned __int64 v207; // x17
  __int64 v208; // x3
  char v209; // w4
  __int64 v210; // x16
  __int64 v211; // x3
  char v212; // w4
  __int64 v213; // x17
  __int64 v214; // x3
  __int64 v215; // x17
  char v216; // w5
  bool v217; // cc
  __int64 v218; // x4
  char v219; // w3
  __int64 v220; // x3
  unsigned __int64 v221; // x6
  unsigned __int64 v222; // x4
  __int64 v223; // x5
  char v224; // w6
  __int64 v225; // x3
  __int64 v226; // x5
  char v227; // w6
  __int64 v228; // x4
  __int64 v229; // x4
  __int64 v230; // x1
  char v231; // w2
  __int64 v232; // x5
  unsigned int v233; // w3
  __int64 v234; // x4
  char v235; // w20
  char v236; // w6
  __int64 v237; // x2
  int v238; // w20
  __int64 v239; // x21
  unsigned __int64 v240; // x7
  unsigned __int64 v241; // x19
  unsigned __int64 v242; // x21
  unsigned __int64 v243; // x21
  unsigned __int64 v244; // x23
  __int64 v245; // x1
  unsigned __int64 v246; // x5
  __int64 v247; // x3
  __int64 v248; // x2
  __int64 v249; // x1
  unsigned __int64 v250; // x4
  __int64 v251; // x2
  __int64 v252; // x4
  unsigned int v253; // w4
  unsigned int v254; // w3
  __int64 v255; // x2
  bool v256; // zf
  unsigned __int64 v257; // x3
  unsigned int v258; // w1
  unsigned __int64 v259; // x2
  unsigned __int64 v260; // x6
  unsigned __int64 v261; // x5
  int v262; // w2
  unsigned __int64 v263; // x3
  unsigned __int64 v264; // x5
  __int64 v265; // x7
  __int64 v266; // x2
  __int64 v267; // x3
  __int64 v268; // x4
  unsigned int v269; // w4
  unsigned int v270; // w3
  __int64 v271; // x2
  bool v272; // zf
  unsigned __int64 v273; // x3
  unsigned __int64 v274; // x2
  __int64 v275; // x3
  __int64 v276; // x4
  unsigned int v277; // w4
  unsigned int v278; // w3
  __int64 v279; // x0
  bool v280; // zf
  unsigned __int64 v281; // x3
  unsigned __int64 v282; // x0
  unsigned __int64 v283; // x3
  unsigned __int64 v284; // x5
  __int64 v285; // x10
  int v286; // w15
  unsigned __int64 v287; // x5
  __int64 v288; // x7
  __int64 v289; // x15
  __int64 v290; // x3
  __int64 v291; // x4
  unsigned int v292; // w4
  unsigned int v293; // w3
  __int64 v294; // x15
  __int64 v295; // x3
  char v296; // w5
  __int64 v297; // x15
  __int64 v298; // x10
  char v299; // w15
  unsigned __int64 v300; // x4
  int v301; // w15
  int v302; // w4
  __int64 v303; // x8
  unsigned __int64 v304; // x5
  unsigned __int64 v305; // x3
  unsigned __int64 v306; // x2
  unsigned __int64 v307; // x5
  unsigned __int64 v308; // x5
  unsigned __int64 v309; // x7
  __int64 v310; // x8
  __int64 v311; // x8
  unsigned __int64 v312; // x2
  bool v313; // zf
  unsigned __int64 v314; // x8
  int v315; // w8
  unsigned int v316; // w15
  signed __int64 v317; // x10
  unsigned __int64 v318; // x2
  int v319; // w15
  unsigned __int64 v320; // x2
  __int64 v321; // x4
  unsigned __int64 v322; // x15
  bool v323; // zf
  __int64 v324; // x10
  __int64 v325; // x10
  signed __int64 v326; // x10
  unsigned __int64 v327; // x2
  int v328; // w15
  unsigned __int64 v329; // x2
  __int64 v330; // x4
  unsigned __int64 v331; // x15
  int v332; // w7
  __int64 v333; // x6
  char v334; // w4
  int v335; // w21
  unsigned __int64 v336; // x30
  unsigned __int64 v337; // x2
  unsigned __int64 v338; // x8
  _BOOL4 v341; // w8
  __int64 v342; // x8
  char v343; // w15
  bool v344; // cc
  __int64 v345; // x10
  char v346; // w8
  char v347; // w15
  __int64 v348; // x8
  __int64 v349; // x10
  __int64 v350; // x15
  __int64 v351; // x0
  unsigned int v352; // w0
  unsigned int v353; // w15
  __int64 v354; // x8
  unsigned __int64 v355; // x10
  int v356; // w0
  unsigned __int64 v357; // x15
  unsigned __int64 v358; // x2
  unsigned __int64 v359; // x10
  unsigned __int64 v360; // x2
  __int64 v361; // x4
  unsigned __int64 v362; // x15
  int v363; // w8
  __int64 v364; // x8
  __int64 v365; // x10
  __int64 v366; // x15
  unsigned int v367; // w15
  unsigned int v368; // w10
  __int64 v369; // x8
  bool v370; // zf
  unsigned __int64 v371; // x10
  unsigned __int64 v372; // x8
  unsigned __int64 v373; // x10
  unsigned __int64 v374; // x8
  bool v375; // nf
  unsigned __int64 v376; // x8
  __int64 v377; // x25
  __int64 v378; // x21
  __int64 v379; // x27
  __int64 v380; // x8
  int v381; // w10
  __int64 v382; // x2
  __int64 v383; // x8
  __int64 v384; // x24
  __int64 v385; // x8
  __int64 v386; // x10
  int v387; // w15
  unsigned int v388; // w10
  __int64 v389; // x8
  bool v390; // zf
  unsigned __int64 v391; // x10
  unsigned __int64 v392; // x15
  unsigned __int64 v393; // x8
  int v394; // w3
  int v395; // w22
  unsigned int v396; // w10
  unsigned __int64 v397; // x8
  unsigned __int64 v398; // x0
  int v399; // w10
  unsigned __int64 v400; // x0
  __int64 v401; // x7
  unsigned __int64 v402; // x0
  unsigned __int64 v403; // x7
  __int64 v404; // x10
  int v405; // w5
  unsigned __int64 v406; // x7
  __int64 v407; // x20
  __int64 v408; // x8
  __int64 v409; // x10
  __int64 v410; // x0
  __int64 v411; // x5
  unsigned int v412; // w5
  unsigned int v413; // w0
  __int64 v414; // x10
  __int64 v415; // x0
  char v416; // w7
  __int64 v417; // x20
  bool v418; // cc
  __int64 v419; // x10
  __int64 v420; // x10
  char v421; // w0
  __int64 v422; // x10
  int v423; // w10
  unsigned __int64 v424; // x19
  unsigned __int64 v425; // x5
  __int64 v426; // x7
  unsigned int v427; // w7
  unsigned int v428; // w20
  __int64 v429; // x5
  __int64 v430; // x20
  unsigned __int64 v431; // x5
  char v432; // w23
  __int64 v433; // x5
  __int64 v434; // x7
  char v435; // w5
  __int64 v436; // x23
  unsigned __int64 v437; // x5
  unsigned __int64 v438; // x7
  unsigned __int64 v439; // x26
  char v440; // w7
  unsigned int v441; // w20
  unsigned __int64 v442; // x28
  char v443; // w19
  __int64 v444; // x23
  int v445; // w7
  unsigned __int64 v446; // x28
  unsigned __int64 v447; // x27
  signed __int64 v448; // x10
  __int64 v449; // x0
  __int64 v450; // x10
  __int64 v451; // x0
  int v452; // w26
  int v453; // w20
  int v454; // w15
  unsigned int v455; // w20
  __int64 v456; // x15
  __int64 v457; // x20
  bool v458; // nf
  __int64 v459; // x7
  __int64 v460; // x15
  unsigned __int64 v461; // x28
  __int64 v462; // x10
  unsigned __int64 v463; // x19
  unsigned __int64 v464; // x10
  signed __int64 v465; // x15
  __int64 v466; // x20
  char v467; // w0
  __int64 v468; // x10
  char v469; // w15
  __int64 v470; // x19
  __int64 v471; // x15
  __int64 v472; // x0
  int v473; // w7
  unsigned int v474; // w0
  __int64 v475; // x15
  __int64 v476; // x20
  __int64 v477; // x19
  __int64 v478; // x15
  char v479; // w23
  __int64 v480; // x15
  __int64 v481; // x0
  int v482; // w7
  unsigned int v483; // w0
  __int64 v484; // x15
  __int64 v485; // x19
  __int64 v486; // x15
  char v487; // w23
  __int64 v488; // x0
  __int64 v489; // x7
  unsigned __int64 v490; // x15
  int v491; // w0
  bool v492; // cc
  __int64 v493; // x19
  __int64 v494; // x19
  unsigned __int64 v495; // x10
  __int64 v496; // x15
  __int64 v497; // x0
  unsigned int v498; // w7
  unsigned int v499; // w0
  __int64 v500; // x15
  __int64 v501; // x19
  char v502; // w0
  __int64 v503; // x10
  char v504; // w15
  __int64 v505; // x10
  unsigned __int64 v506; // x15
  bool v507; // zf
  unsigned __int64 v508; // x10
  __int64 v509; // x15
  unsigned __int64 v510; // x10
  __int64 v511; // x0
  unsigned int v512; // w0
  unsigned int v513; // w15
  __int64 v514; // x19
  __int64 v515; // x15
  __int64 v516; // x15
  __int64 v517; // x19
  char v518; // w23
  __int64 v519; // x23
  __int64 v520; // x10
  __int64 v521; // x19
  __int64 v522; // x0
  unsigned int v523; // w7
  unsigned int v524; // w0
  __int64 v525; // x15
  unsigned __int64 v526; // x10
  __int64 v527; // x19
  unsigned __int64 v528; // x10
  int v529; // w15
  __int64 v530; // x0
  int v531; // w7
  unsigned int v532; // w0
  __int64 v533; // x23
  __int64 v534; // x10
  __int64 v535; // x10
  __int64 v536; // x0
  __int64 v537; // x19
  __int64 v538; // x19
  __int64 v539; // x23
  char v540; // w26
  __int64 v541; // x23
  __int64 v542; // x0
  unsigned int v543; // w7
  unsigned int v544; // w0
  __int64 v545; // x19
  unsigned __int64 v546; // x10
  unsigned __int64 v547; // x0
  unsigned __int64 v548; // x10
  __int64 v549; // x19
  unsigned __int64 v550; // x15
  char v551; // w0
  __int64 v552; // x23
  __int64 v553; // x10
  char v554; // w15
  __int64 v555; // x10
  unsigned __int64 v556; // x15
  bool v557; // zf
  unsigned __int64 v558; // x10
  int v559; // w19
  __int64 v560; // x10
  __int64 v561; // x10
  __int64 v562; // x15
  __int64 v563; // x0
  unsigned int v564; // w7
  unsigned int v565; // w0
  __int64 v566; // x15
  __int64 v567; // x23
  char v568; // w0
  bool v569; // cc
  __int64 v570; // x10
  char v571; // w15
  __int64 v572; // x23
  __int64 v573; // x10
  unsigned __int64 v574; // x15
  unsigned __int64 v575; // x15
  int v576; // w26
  __int64 v577; // x10
  __int64 v578; // x10
  unsigned __int64 v579; // x15
  char v580; // w0
  __int64 v581; // x10
  char v582; // w15
  __int64 v583; // x15
  __int64 v584; // x23
  __int64 v585; // x0
  unsigned int v586; // w7
  unsigned int v587; // w0
  __int64 v588; // x15
  _BOOL4 v589; // w10
  bool v590; // zf
  unsigned __int64 v591; // x7
  int v592; // w10
  unsigned __int64 v593; // x15
  unsigned __int64 v594; // x10
  int v595; // w0
  __int64 v596; // x22
  unsigned __int64 v597; // x23
  unsigned __int64 v598; // x7
  __int64 v599; // x10
  _BOOL8 v600; // x7
  unsigned __int64 v601; // x27
  __int64 v602; // x0
  __int64 v603; // x10
  unsigned __int64 v604; // x0
  bool v605; // zf
  unsigned __int64 v606; // x10
  int v607; // w15
  unsigned int v608; // w0
  unsigned __int64 v609; // x22
  __int64 v610; // x7
  int v611; // w0
  bool v612; // cc
  __int64 v613; // x23
  unsigned __int64 v614; // x0
  __int64 v615; // x10
  bool v616; // zf
  __int64 v617; // x10
  __int64 v618; // x0
  unsigned __int64 v619; // x27
  __int64 v620; // x7
  unsigned __int64 v621; // x23
  unsigned __int64 v622; // x22
  __int64 v623; // x7
  int v624; // w0
  bool v625; // cc
  __int64 v626; // x23
  unsigned __int64 v627; // x0
  __int64 v628; // x10
  unsigned __int64 v629; // x27
  int v630; // w15
  bool v631; // w22
  unsigned __int64 v632; // x23
  bool v633; // zf
  char v634; // w10
  int v635; // w15
  _BOOL4 v636; // w15
  __int64 v637; // x23
  __int64 v638; // x22
  __int64 v639; // x22
  char v640; // w15
  __int64 v641; // x0
  __int64 v642; // x22
  char v643; // w0
  __int64 v644; // x7
  __int64 v645; // x22
  char v646; // w15
  __int64 v647; // x23
  char v648; // w0
  __int64 v649; // x23
  char v650; // w0
  __int64 v651; // x15
  __int64 v652; // x22
  char v653; // w27
  __int64 v654; // x23
  __int64 v655; // x23
  char v656; // w22
  __int64 v657; // x0
  __int64 v658; // x23
  char v659; // w22
  __int64 v660; // x15
  int v661; // w10
  bool v662; // zf
  int v663; // w9
  __int64 v664; // x9
  __int64 v665; // x8
  bool v666; // nf
  unsigned __int64 v667; // x8
  bool v668; // nf
  __int64 v669; // x9
  __int64 v670; // x10
  __int64 v671; // x9
  __int64 v672; // x13
  char v673; // w14
  __int64 v674; // x8
  __int64 v675; // x14
  char v676; // w9
  __int64 v677; // x11
  __int64 v678; // x9
  unsigned __int64 v679; // x14
  __int64 v680; // x15
  unsigned int v681; // w15
  unsigned int v682; // w13
  __int64 v683; // x14
  int v684; // w12
  unsigned __int64 v685; // x15
  __int64 v686; // x14
  unsigned __int64 v687; // x16
  unsigned __int64 v688; // x16
  __int64 v689; // x13
  __int64 v690; // x14
  __int64 v691; // x15
  unsigned int v692; // w15
  unsigned int v693; // w14
  __int64 v694; // x12
  __int64 v695; // x14
  __int64 v696; // x13
  char v697; // w16
  bool v698; // cc
  __int64 v699; // x12
  __int64 v700; // x12
  char v701; // w14
  __int64 v702; // x12
  signed __int64 v703; // x10
  char v704; // w12
  __int64 v705; // x9
  __int64 v706; // x9
  char v707; // w10
  int v708; // w8
  __int64 v709; // x9
  char v710; // w10
  __int64 v711; // x8
  bool v712; // zf
  unsigned __int64 v713; // x9
  __int64 v714; // x11
  __int64 v715; // x8
  __int64 v716; // x10
  __int64 v717; // x10
  __int64 v718; // x12
  unsigned int v719; // w12
  unsigned int v720; // w11
  __int64 v721; // x9
  unsigned __int64 v722; // x12
  unsigned __int64 v723; // x11
  unsigned __int64 v724; // x14
  int v725; // w12
  unsigned __int64 v726; // x14
  __int64 v727; // x16
  __int64 v728; // x12
  __int64 v729; // x10
  char v730; // w14
  __int64 v731; // x11
  __int64 v732; // x11
  char v733; // w12
  bool v734; // nf
  __int64 v735; // x8
  __int64 v736; // x9
  __int64 v737; // x8
  __int64 v738; // x11
  unsigned int v739; // w11
  unsigned int v740; // w10
  __int64 v741; // x8
  __int64 v742; // x9
  __int64 v743; // x9
  unsigned __int64 v744; // x11
  __int64 v745; // x9
  char v746; // w13
  bool v747; // cc
  __int64 v748; // x11
  char v749; // w9
  __int64 v750; // x10
  char v751; // w13
  __int64 v752; // x10
  int v753; // w11
  __int64 v754; // x8
  __int64 v755; // x0
  __int64 result; // x0
  unsigned __int64 v757; // [xsp+10h] [xbp-380h]
  __int64 v758; // [xsp+18h] [xbp-378h]
  _BOOL4 v759; // [xsp+24h] [xbp-36Ch]
  unsigned __int64 v760; // [xsp+28h] [xbp-368h]
  unsigned __int64 v761; // [xsp+30h] [xbp-360h]
  __int64 v762; // [xsp+40h] [xbp-350h]
  int v763; // [xsp+4Ch] [xbp-344h]
  char v764; // [xsp+50h] [xbp-340h]
  int v765; // [xsp+54h] [xbp-33Ch]
  int v766; // [xsp+58h] [xbp-338h]
  int v767; // [xsp+5Ch] [xbp-334h]
  int v768; // [xsp+60h] [xbp-330h]
  int v769; // [xsp+64h] [xbp-32Ch]
  unsigned __int64 v770; // [xsp+70h] [xbp-320h]
  unsigned __int64 v771; // [xsp+80h] [xbp-310h]
  int v772; // [xsp+8Ch] [xbp-304h]
  __int64 v773; // [xsp+90h] [xbp-300h]
  int v774; // [xsp+9Ch] [xbp-2F4h]
  unsigned int v775; // [xsp+A0h] [xbp-2F0h]
  unsigned int v776; // [xsp+ACh] [xbp-2E4h]
  __int64 v777; // [xsp+B0h] [xbp-2E0h]
  unsigned int v778; // [xsp+BCh] [xbp-2D4h]
  __int64 v779; // [xsp+C0h] [xbp-2D0h]
  unsigned __int64 v780; // [xsp+D0h] [xbp-2C0h]
  int v781; // [xsp+DCh] [xbp-2B4h]
  __int64 v782; // [xsp+E8h] [xbp-2A8h]
  __int64 v783; // [xsp+F0h] [xbp-2A0h]
  __int64 v784; // [xsp+F8h] [xbp-298h]
  unsigned __int64 v785; // [xsp+108h] [xbp-288h]
  int v786; // [xsp+114h] [xbp-27Ch]
  unsigned __int64 v787; // [xsp+118h] [xbp-278h]
  int v788; // [xsp+120h] [xbp-270h]
  int v789; // [xsp+124h] [xbp-26Ch]
  unsigned __int64 v790; // [xsp+128h] [xbp-268h]
  __int64 v791; // [xsp+130h] [xbp-260h]
  int v792; // [xsp+13Ch] [xbp-254h]
  int v793; // [xsp+140h] [xbp-250h]
  int v794; // [xsp+144h] [xbp-24Ch]
  int v795; // [xsp+148h] [xbp-248h]
  unsigned __int64 v796; // [xsp+150h] [xbp-240h]
  unsigned __int64 v797; // [xsp+158h] [xbp-238h]
  __int64 v798; // [xsp+160h] [xbp-230h]
  int v799; // [xsp+168h] [xbp-228h]
  _BOOL4 v800; // [xsp+168h] [xbp-228h]
  __int64 v801; // [xsp+168h] [xbp-228h]
  __int64 v802; // [xsp+178h] [xbp-218h]
  int v803; // [xsp+184h] [xbp-20Ch]
  _QWORD s[64]; // [xsp+190h] [xbp-200h] BYREF

  s[62] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x1F0u);
  dp_tu_update_timings(a1, (__int64)s);
  v4 = 62;
  do
  {
    if ( ((s[0] >> v4) & 1LL) != s[0] >> 63 )
      break;
    --v4;
  }
  while ( v4 );
  if ( (unsigned int)(v4 - 28) >= 0xFFFFFFC2 )
  {
    v6 = s[0] << 34;
    LOBYTE(v5) = 0;
    goto LABEL_9;
  }
  v5 = v4 - 27;
  v6 = (0x400000000uLL >> ((v5 >> 1) + ((v4 - 27) & 1))) * (s[0] >> (v5 >> 1));
  if ( (unsigned int)(v4 - 27) < 0x21 )
  {
    if ( (_DWORD)v4 == 59 )
      goto LABEL_10;
LABEL_9:
    v6 >>= 32 - (unsigned __int8)v5;
    goto LABEL_10;
  }
  v6 <<= (unsigned __int8)v4 - 59;
LABEL_10:
  v7 = 62;
  do
  {
    if ( (((unsigned __int64)v6 >> v7) & 1) != (unsigned __int64)v6 >> 63 )
      break;
    --v7;
  }
  while ( v7 );
  v8 = v7 - 30;
  v9 = (unsigned int)(62 - v7) > 0x20;
  v10 = v6 << (62 - (unsigned __int8)v7);
  if ( (unsigned int)(62 - v7) >= 0x20 )
    v8 = 0;
  v11 = v10 / (s[2] >> v8);
  v12 = 30 - v7;
  if ( !v9 )
    v12 = 0;
  v13 = v11 >> v12;
  v14 = 0xFFFFFFFF00000001LL;
  v15 = v13 == 0;
  if ( v13 >= 0 )
    v14 = 0xFFFFFFFFLL;
  v16 = v14 + v13;
  v17 = *(_DWORD *)(a1 + 56);
  v18 = HIDWORD(v16);
  if ( v15 )
    v19 = 0;
  else
    v19 = v18;
  LODWORD(s[14]) = v19;
  if ( v17 == 375 && LODWORD(s[10]) == 30 )
  {
    v20 = 0x300000000LL;
  }
  else
  {
    if ( SLODWORD(s[10]) >= 0 )
      v21 = LODWORD(s[10]);
    else
      v21 = (unsigned int)-LODWORD(s[10]);
    v20 = v21 >> 3;
    v22 = v21 & 7;
    v23 = -32;
    do
    {
      v24 = 2 * v22;
      if ( v24 <= 7 )
        v25 = 0;
      else
        v25 = -8;
      v26 = __CFADD__(v23++, 1);
      v20 = (v24 > 7) | (unsigned __int64)(2 * v20);
      v22 = v25 + v24;
    }
    while ( !v26 );
    if ( (v22 & 0x7FFFFFFFFFFFFFFCLL) != 0 )
      ++v20;
    if ( SLODWORD(s[10]) < 0 )
      v20 = -v20;
  }
  v27 = 62;
  do
  {
    if ( ((s[2] >> v27) & 1LL) != s[2] >> 63 )
      break;
    --v27;
  }
  while ( v27 );
  v28 = 62;
  do
  {
    if ( (((unsigned __int64)v20 >> v28) & 1) != (unsigned __int64)v20 >> 63 )
      break;
    --v28;
  }
  while ( v28 );
  v29 = v28 + v27;
  v30 = v28 + v27 - 61;
  if ( v29 <= 0x3D )
  {
    v31 = v20 * s[2];
    LOBYTE(v30) = 0;
LABEL_49:
    v31 >>= 32 - (unsigned __int8)v30;
    goto LABEL_50;
  }
  v31 = (s[2] >> ((v30 >> 1) + (v30 & 1))) * (v20 >> (v30 >> 1));
  if ( v30 >= 0x21 )
  {
    v31 <<= (unsigned __int8)v29 - 93;
    goto LABEL_50;
  }
  if ( v30 != 32 )
    goto LABEL_49;
LABEL_50:
  v32 = 62;
  if ( s[9] >= 0 )
    v33 = HIDWORD(s[9]);
  else
    v33 = (unsigned int)-HIDWORD(s[9]);
  v34 = v33 << 32;
  if ( s[9] < 0 )
    v34 = 0xFFFFFFFF00000000LL * v33;
  do
  {
    if ( (((unsigned __int64)v31 >> v32) & 1) != (unsigned __int64)v31 >> 63 )
      break;
    --v32;
  }
  while ( v32 );
  v35 = 62;
  v36 = v32 - 30;
  v37 = v31 << (62 - (unsigned __int8)v32);
  if ( (unsigned int)(62 - v32) >= 0x20 )
    v36 = 0;
  v38 = v37 / (v34 >> v36);
  v39 = 30 - v32;
  if ( (unsigned int)(62 - v32) <= 0x20 )
    v39 = 0;
  v40 = v38 >> v39;
  v41 = (unsigned __int64)v38 >> 63;
  do
  {
    if ( ((v40 >> v35) & 1) != v41 )
      break;
    --v35;
  }
  while ( v35 );
  v42 = v35 - 30;
  v43 = 62 - v35;
  v44 = 30 - v35;
  BYTE4(s[42]) = 0;
  v45 = v40 << v43;
  s[52] = 0;
  if ( v43 >= 0x20 )
    v42 = 0;
  if ( v43 <= 0x20 )
    v44 = 0;
  s[54] = 0;
  LODWORD(s[58]) = 0;
  s[19] = 0;
  *(_QWORD *)((char *)&s[43] + 4) = 0;
  *(_QWORD *)((char *)&s[44] + 4) = 0;
  *(_QWORD *)((char *)&s[45] + 4) = 0;
  *(_QWORD *)((char *)&s[46] + 4) = 0;
  *(_QWORD *)((char *)&s[47] + 4) = 0;
  *(_QWORD *)((char *)&s[48] + 4) = 0;
  *(_QWORD *)((char *)&s[49] + 4) = 0;
  v46 = (v45 / (s[0] >> v42)) >> v44;
  s[15] = v46;
  s[16] = v46;
  s[17] = 0x3E800000000LL;
  if ( !(HIDWORD(s[5]) % HIDWORD(s[9])) || v46 == 0x100000000LL )
    goto LABEL_85;
  if ( v46 > 0x100000000LL || LODWORD(s[11]) != 0 )
    goto LABEL_85;
  v48 = 62;
  do
  {
    if ( (((unsigned __int64)v46 >> v48) & 1) != (unsigned __int64)v46 >> 63 )
      break;
    --v48;
  }
  while ( v48 );
  if ( (unsigned int)(v48 - 30) >= 0xFFFFFFC2 )
  {
    v46 *= 0x100418937LL;
    v49 = 0;
    goto LABEL_83;
  }
  v49 = v48 - 29;
  v46 = (v46 >> (((unsigned int)(v48 - 29) >> 1) + ((v48 - 29) & 1)))
      * (0x100418937uLL >> ((unsigned int)(v48 - 29) >> 1));
  if ( (unsigned int)(v48 - 29) < 0x21 )
  {
    if ( (_DWORD)v48 == 61 )
      goto LABEL_84;
LABEL_83:
    v46 >>= 32 - v49;
    goto LABEL_84;
  }
  v46 <<= (unsigned __int8)v48 - 61;
LABEL_84:
  s[15] = v46;
LABEL_85:
  if ( v46 >= 0x100000001LL )
  {
    v46 = 0x100000000LL;
    s[15] = 0x100000000LL;
  }
  v50 = (unsigned __int64)v46 >> 63;
  v51 = 0x3E800000000LL;
  for ( i = 32; i != 65; ++i )
  {
    v53 = i << 32;
    v54 = 62;
    do
    {
      if ( (((unsigned __int64)v46 >> v54) & 1) != v50 )
        break;
      --v54;
    }
    while ( v54 );
    v55 = 62;
    do
    {
      if ( (((unsigned __int64)v53 >> v55) & 1) != (unsigned __int64)(unsigned int)i >> 31 )
        break;
      --v55;
    }
    while ( v55 );
    v56 = v55 + v54;
    v57 = v55 + v54 - 61;
    if ( v56 <= 0x3D )
    {
      v58 = v46 * v53;
      LOBYTE(v57) = 0;
LABEL_99:
      v58 >>= 32 - (unsigned __int8)v57;
      goto LABEL_100;
    }
    v58 = (v46 >> ((v57 >> 1) + (v57 & 1))) * (v53 >> (v57 >> 1));
    if ( v57 >= 0x21 )
    {
      v58 <<= (unsigned __int8)v56 - 93;
      goto LABEL_100;
    }
    if ( v57 != 32 )
      goto LABEL_99;
LABEL_100:
    if ( v58 < 0 )
      v59 = 0xFFFFFFFF00000001LL;
    else
      v59 = 0xFFFFFFFFLL;
    v60 = (__int64)(v59 + v58) >> 32;
    if ( !v58 )
      v60 = 0;
    v61 = v60 < 0;
    if ( v60 < 0 )
      v60 = -v60;
    v62 = v60 << 32;
    if ( v61 )
      v63 = -v62;
    else
      v63 = v62;
    v64 = v63 - v58;
    if ( v63 < v58 )
    {
      v65 = v58 - v63;
      v66 = 0;
      while ( (((unsigned __int64)v65 >> ((unsigned __int8)v66 + 62)) & 1) == (unsigned __int64)v65 >> 63 )
      {
        if ( --v66 == -62 )
          goto LABEL_118;
      }
      if ( (unsigned int)(v66 + 31) >= 0xFFFFFFC2 )
      {
LABEL_118:
        v64 = 0xFFFFFFFF00000000LL * v65;
        v67 = 0;
LABEL_119:
        v64 >>= 32 - v67;
        goto LABEL_120;
      }
      v67 = v66 + 32;
      v64 = (v65 >> (((unsigned int)(v66 + 32) >> 1) + ((v66 + 62) & 1)))
          * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v66 + 32) >> 1));
      if ( (unsigned int)(v66 + 32) >= 0x21 )
      {
        v64 <<= v66;
        goto LABEL_120;
      }
      if ( (_DWORD)v66 )
        goto LABEL_119;
    }
LABEL_120:
    if ( v64 < v51 )
    {
      v51 = v64;
      s[17] = v64;
      HIDWORD(s[20]) = i;
    }
  }
  s[18] = v64;
  LODWORD(s[20]) = 65;
  if ( s[20] >= 0 )
    v68 = HIDWORD(s[20]);
  else
    v68 = (unsigned int)-HIDWORD(s[20]);
  v69 = v68 << 32;
  LODWORD(s[21]) = HIDWORD(s[20]) - 1;
  if ( s[20] >= 0 )
    v70 = v69;
  else
    v70 = -v69;
  v71 = 62;
  do
  {
    if ( (((unsigned __int64)v46 >> v71) & 1) != v50 )
      break;
    --v71;
  }
  while ( v71 );
  v72 = 62;
  do
  {
    if ( (((unsigned __int64)v70 >> v72) & 1) != (unsigned __int64)v70 >> 63 )
      break;
    --v72;
  }
  while ( v72 );
  v73 = v72 + v71;
  v74 = v73 - 61;
  if ( v73 <= 0x3D )
  {
    v75 = v46 * v70;
    LOBYTE(v74) = 0;
    goto LABEL_143;
  }
  v75 = (v46 >> ((v74 >> 1) + (v74 & 1))) * (v70 >> (v74 >> 1));
  if ( v74 >= 0x21 )
  {
    v75 <<= (unsigned __int8)v73 - 93;
    goto LABEL_144;
  }
  if ( v73 != 93 )
LABEL_143:
    v75 >>= 32 - (unsigned __int8)v74;
LABEL_144:
  v76 = v75 == 0;
  v77 = 0xFFFFFFFF00000001LL;
  if ( v75 >= 0 )
    v77 = 0xFFFFFFFFLL;
  v78 = (v77 + v75) >> 32;
  if ( v76 )
    LODWORD(v78) = 0;
  if ( SLODWORD(s[10]) >= 0 )
    v79 = LODWORD(s[10]);
  else
    v79 = (unsigned int)-LODWORD(s[10]);
  HIDWORD(s[21]) = v78;
  v80 = v79 >> 3;
  v81 = v79 & 7;
  v82 = -32;
  do
  {
    v83 = 2 * v81;
    if ( v83 <= 7 )
      v84 = 0;
    else
      v84 = -8;
    v26 = __CFADD__(v82++, 1);
    v80 = (v83 > 7) | (unsigned __int64)(2 * v80);
    v81 = v84 + v83;
  }
  while ( !v26 );
  if ( (v81 & 0x7FFFFFFFFFFFFFFCLL) != 0 )
    ++v80;
  if ( SLODWORD(s[10]) >= 0 )
    v85 = v80;
  else
    v85 = -v80;
  v86 = 62;
  do
  {
    if ( ((s[5] >> v86) & 1LL) != s[5] >> 63 )
      break;
    --v86;
  }
  while ( v86 );
  v87 = 62;
  do
  {
    if ( (((unsigned __int64)v85 >> v87) & 1) != (unsigned __int64)v85 >> 63 )
      break;
    --v87;
  }
  while ( v87 );
  v88 = v87 + v86;
  v89 = v88 - 61;
  if ( v88 <= 0x3D )
  {
    v90 = v85 * s[5];
    LOBYTE(v89) = 0;
    goto LABEL_173;
  }
  v90 = (s[5] >> ((v89 >> 1) + (v89 & 1))) * (v85 >> (v89 >> 1));
  if ( v89 >= 0x21 )
  {
    v90 <<= (unsigned __int8)v88 - 93;
    goto LABEL_174;
  }
  if ( v88 != 93 )
LABEL_173:
    v90 >>= 32 - (unsigned __int8)v89;
LABEL_174:
  v91 = (v78 & 0x80000000) != 0LL;
  if ( (v78 & 0x80000000) == 0LL )
    v92 = (unsigned int)v78;
  else
    v92 = (unsigned int)-(int)v78;
  v93 = 62;
  v94 = v92 << 32;
  if ( v91 )
    v94 = -v94;
  do
  {
    if ( (((unsigned __int64)v90 >> v93) & 1) != (unsigned __int64)v90 >> 63 )
      break;
    --v93;
  }
  while ( v93 );
  v95 = v93 - 30;
  v96 = v90 << (62 - (unsigned __int8)v93);
  if ( (unsigned int)(62 - v93) >= 0x20 )
    v95 = 0;
  v97 = v96 / (v94 >> v95);
  v98 = 30 - v93;
  if ( (unsigned int)(62 - v93) <= 0x20 )
    v98 = 0;
  v99 = v97 >> v98;
  if ( (unsigned int)v99 <= 0xFFFFF000uLL )
    v100 = HIDWORD(v99);
  else
    v100 = HIDWORD(v99) + 1;
  LODWORD(s[26]) = v100;
  HIDWORD(s[46]) = v100 % SHIDWORD(s[9]) == 0;
  ipc_log_context = get_ipc_log_context(v64);
  StatusReg = _ReadStatusReg(SP_EL0);
  v103 = ipc_log_string(
           ipc_log_context,
           "[d][%-4d]n_sym= %d, n_tus= %d\n",
           *(_DWORD *)(StatusReg + 1800),
           HIDWORD(s[21]),
           LODWORD(s[26]));
  if ( (_drm_debug & 4) != 0 )
    v103 = _drm_dev_dbg(
             0,
             0,
             0,
             "[msm-dp-debug][%-4d]n_sym= %d, n_tus= %d\n",
             *(_DWORD *)(StatusReg + 1800),
             HIDWORD(s[21]),
             LODWORD(s[26]));
  v104 = 62;
  if ( s[20] >= 0 )
    v105 = HIDWORD(s[20]);
  else
    v105 = (unsigned int)-HIDWORD(s[20]);
  v106 = v105 << 32;
  if ( s[20] < 0 )
    v106 = -v106;
  do
  {
    if ( ((s[16] >> v104) & 1LL) != s[16] >> 63 )
      break;
    --v104;
  }
  while ( v104 );
  v107 = 62;
  do
  {
    if ( (((unsigned __int64)v106 >> v107) & 1) != (unsigned __int64)v106 >> 63 )
      break;
    --v107;
  }
  while ( v107 );
  v108 = v107 + v104;
  v109 = v108 - 61;
  if ( v108 <= 0x3D )
  {
    v110 = s[16] * v106;
    LOBYTE(v109) = 0;
    goto LABEL_205;
  }
  v110 = (s[16] >> ((v109 >> 1) + (v109 & 1))) * (v106 >> (v109 >> 1));
  if ( v109 >= 0x21 )
  {
    v110 <<= (unsigned __int8)v108 - 93;
    goto LABEL_206;
  }
  if ( v108 != 93 )
LABEL_205:
    v110 >>= 32 - (unsigned __int8)v109;
LABEL_206:
  if ( s[21] >= 0 )
    v111 = HIDWORD(s[21]);
  else
    v111 = (unsigned int)-HIDWORD(s[21]);
  v112 = v111 << 32;
  if ( s[21] >= 0 )
    v113 = v112;
  else
    v113 = -v112;
  v114 = v113 - v110;
  if ( v113 < v110 )
  {
    v115 = v110 - v113;
    v116 = 0;
    while ( (((unsigned __int64)v115 >> ((unsigned __int8)v116 + 62)) & 1) == (unsigned __int64)v115 >> 63 )
    {
      if ( --v116 == -62 )
        goto LABEL_220;
    }
    if ( (unsigned int)(v116 + 31) >= 0xFFFFFFC2 )
    {
LABEL_220:
      v114 = 0xFFFFFFFF00000000LL * v115;
      v117 = 0;
    }
    else
    {
      v117 = v116 + 32;
      v114 = (v115 >> (((unsigned int)(v116 + 32) >> 1) + ((v116 + 62) & 1)))
           * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v116 + 32) >> 1));
      if ( (unsigned int)(v116 + 32) >= 0x21 )
      {
        v114 <<= v116;
        goto LABEL_222;
      }
      if ( !(_DWORD)v116 )
        goto LABEL_222;
    }
    v114 >>= 32 - v117;
  }
LABEL_222:
  if ( (unsigned int)v114 <= 0x40000 )
  {
    LODWORD(s[29]) = 0;
    v118 = get_ipc_log_context(v103);
    ipc_log_string(v118, "[d][%-4d]extra_bytes set to 0\n", *(_DWORD *)(StatusReg + 1800));
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "[msm-dp-debug][%-4d]extra_bytes set to 0\n", *(_DWORD *)(StatusReg + 1800));
    goto LABEL_245;
  }
  v119 = 62;
  if ( LODWORD(s[26]) + 1 >= 0 )
    v120 = (unsigned int)(LODWORD(s[26]) + 1);
  else
    v120 = (unsigned int)~LODWORD(s[26]);
  v121 = v120 << 32;
  if ( LODWORD(s[26]) + 1 < 0 )
    v121 = -v121;
  do
  {
    if ( (((unsigned __int64)v121 >> v119) & 1) != (unsigned __int64)v121 >> 63 )
      break;
    --v119;
  }
  while ( v119 );
  v122 = 62;
  do
  {
    if ( (((unsigned __int64)v114 >> v122) & 1) != (unsigned __int64)v114 >> 63 )
      break;
    --v122;
  }
  while ( v122 );
  v123 = v122 + v119;
  v124 = v123 - 61;
  if ( v123 <= 0x3D )
  {
    v125 = v121 * v114;
    LOBYTE(v124) = 0;
LABEL_239:
    v125 >>= 32 - (unsigned __int8)v124;
    goto LABEL_240;
  }
  v125 = (v121 >> ((v124 >> 1) + (v124 & 1))) * (v114 >> (v124 >> 1));
  if ( v124 < 0x21 )
  {
    if ( v123 == 93 )
      goto LABEL_240;
    goto LABEL_239;
  }
  v125 <<= (unsigned __int8)v123 - 93;
LABEL_240:
  v126 = v125 == 0;
  v127 = 0xFFFFFFFF00000001LL;
  if ( v125 >= 0 )
    v127 = 0xFFFFFFFFLL;
  v128 = (v127 + v125) >> 32;
  if ( v126 )
    LODWORD(v128) = 0;
  LODWORD(s[29]) = v128;
LABEL_245:
  if ( SLODWORD(s[29]) >= 0 )
    v129 = LODWORD(s[29]);
  else
    v129 = (unsigned int)-LODWORD(s[29]);
  if ( SLODWORD(s[10]) >= 0 )
    v130 = LODWORD(s[10]);
  else
    v130 = (unsigned int)-LODWORD(s[10]);
  v131 = v129 << 32;
  v132 = 8 / (unsigned int)v130;
  v133 = 8 % (unsigned int)v130;
  v134 = -32;
  do
  {
    v135 = 2 * v133;
    if ( v135 < v130 )
      v136 = 0;
    else
      v136 = v130;
    v26 = __CFADD__(v134++, 1);
    v132 = (v135 >= v130) | (2 * v132);
    v133 = v135 - v136;
  }
  while ( !v26 );
  if ( SLODWORD(s[29]) >= 0 )
    v137 = v131;
  else
    v137 = -v131;
  if ( v130 > 2 * v133 )
    v138 = v132;
  else
    v138 = v132 + 1;
  v139 = 62;
  if ( SLODWORD(s[10]) < 0 )
    v138 = -v138;
  do
  {
    if ( (((unsigned __int64)v137 >> v139) & 1) != (unsigned __int64)v137 >> 63 )
      break;
    --v139;
  }
  while ( v139 );
  v140 = 62;
  do
  {
    if ( (((unsigned __int64)v138 >> v140) & 1) != (unsigned __int64)v138 >> 63 )
      break;
    --v140;
  }
  while ( v140 );
  v141 = v140 + v139;
  v142 = v141 - 61;
  if ( v141 <= 0x3D )
  {
    v143 = v138 * v137;
    LOBYTE(v142) = 0;
    goto LABEL_275;
  }
  v143 = (v137 >> ((v142 >> 1) + (v142 & 1))) * (v138 >> (v142 >> 1));
  if ( v142 >= 0x21 )
  {
    v143 <<= (unsigned __int8)v141 - 93;
    goto LABEL_276;
  }
  if ( v141 != 93 )
LABEL_275:
    v143 >>= 32 - (unsigned __int8)v142;
LABEL_276:
  v144 = v143 == 0;
  v145 = 0xFFFFFFFF00000001LL;
  v146 = 62;
  if ( v143 >= 0 )
    v145 = 0xFFFFFFFFLL;
  v147 = (v145 + v143) >> 32;
  v148 = s[0] >> 63;
  if ( v144 )
    LODWORD(v149) = 0;
  else
    LODWORD(v149) = v147;
  HIDWORD(s[30]) = v149;
  do
  {
    if ( ((s[0] >> v146) & 1LL) != v148 )
      break;
    --v146;
  }
  while ( v146 );
  v150 = 62;
  v151 = v146 - 30;
  v152 = (unsigned int)(62 - v146) > 0x20;
  if ( (unsigned int)(62 - v146) >= 0x20 )
    v151 = 0;
  v153 = (s[0] << (62 - (unsigned __int8)v146)) / (s[2] >> v151);
  v154 = 30 - v146;
  if ( v152 )
    v155 = v154;
  else
    v155 = 0;
  v156 = (int)v149 < 0;
  if ( (int)v149 >= 0 )
    v149 = (unsigned int)v149;
  else
    v149 = (unsigned int)-(int)v149;
  v157 = v149 << 32;
  if ( v156 )
    v158 = -v157;
  else
    v158 = v157;
  v159 = v153 >> v155;
  do
  {
    if ( (((unsigned __int64)v158 >> v150) & 1) != (unsigned __int64)v158 >> 63 )
      break;
    --v150;
  }
  while ( v150 );
  v160 = 62;
  do
  {
    if ( (((unsigned __int64)v159 >> v160) & 1) != (unsigned __int64)v159 >> 63 )
      break;
    --v160;
  }
  while ( v160 );
  v161 = v160 + v150;
  v162 = v160 + v150 - 61;
  if ( v161 <= 0x3D )
  {
    v163 = v159 * v158;
    LOBYTE(v162) = 0;
    goto LABEL_306;
  }
  v163 = (v158 >> ((v162 >> 1) + (v162 & 1))) * (v159 >> (v162 >> 1));
  if ( v162 >= 0x21 )
  {
    v163 <<= (unsigned __int8)v161 - 93;
    goto LABEL_307;
  }
  if ( v162 != 32 )
LABEL_306:
    v163 >>= 32 - (unsigned __int8)v162;
LABEL_307:
  v164 = v163 == 0;
  v165 = 0xFFFFFFFF00000001LL;
  if ( v163 >= 0 )
    v165 = 0xFFFFFFFFLL;
  v166 = 62;
  v167 = (v165 + v163) >> 32;
  v168 = s[15] >> 63;
  if ( v164 )
    v169 = 0;
  else
    v169 = v167;
  if ( s[20] >= 0 )
    v170 = HIDWORD(s[20]);
  else
    v170 = (unsigned int)-HIDWORD(s[20]);
  LODWORD(s[31]) = v169;
  v171 = v170 << 32;
  HIDWORD(s[29]) = HIDWORD(s[20]) - HIDWORD(s[21]);
  if ( s[20] < 0 )
    v171 = 0xFFFFFFFF00000000LL * v170;
  do
  {
    if ( ((s[15] >> v166) & 1LL) != v168 )
      break;
    --v166;
  }
  while ( v166 );
  v172 = 62;
  do
  {
    if ( ((v171 >> v172) & 1) != v171 >> 63 )
      break;
    --v172;
  }
  while ( v172 );
  v173 = v172 + v166;
  v174 = v172 + v166 - 61;
  if ( v173 <= 0x3D )
  {
    v175 = s[15] * v171;
    LOBYTE(v174) = 0;
    goto LABEL_327;
  }
  v175 = (s[15] >> ((v174 >> 1) + (v174 & 1))) * ((__int64)v171 >> (v174 >> 1));
  if ( v174 >= 0x21 )
  {
    v175 <<= (unsigned __int8)v173 - 93;
    goto LABEL_328;
  }
  if ( v174 != 32 )
LABEL_327:
    v175 >>= 32 - (unsigned __int8)v174;
LABEL_328:
  v176 = v169 + HIDWORD(s[20]) - HIDWORD(s[21]);
  if ( s[21] >= 0LL )
    v177 = SHIDWORD(s[21]);
  else
    v177 = -(__int64)SHIDWORD(s[21]);
  v178 = v170 << 32;
  v179 = v177 << 32;
  LODWORD(v180) = v176 + LODWORD(s[14]);
  s[32] = v175;
  LODWORD(s[30]) = v180;
  if ( s[21] >= 0 )
    v181 = v179;
  else
    v181 = -v179;
  v182 = 62;
  if ( s[20] < 0 )
    v178 = 0xFFFFFFFF00000000LL * v170;
  s[22] = v181;
  do
  {
    if ( ((v181 >> v182) & 1) != v181 >> 63 )
      break;
    --v182;
  }
  while ( v182 );
  v183 = 62;
  v184 = v182 - 30;
  v185 = (unsigned int)(62 - v182) > 0x20;
  v186 = v181 << (62 - (unsigned __int8)v182);
  if ( (unsigned int)(62 - v182) >= 0x20 )
    v184 = 0;
  v187 = 30 - v182;
  v188 = v186 / (v178 >> v184);
  if ( v185 )
    v189 = v187;
  else
    v189 = 0;
  v190 = 0x400000000LL - s[7];
  if ( s[7] - 0x400000000LL >= 0 )
    v190 = s[7] - 0x400000000LL;
  v191 = v190 << 32;
  if ( s[7] - 0x400000000LL < 0 )
    v191 = 0xFFFFFFFF00000000LL * v190;
  s[38] = (v188 >> v189) - s[16];
  do
  {
    if ( ((v191 >> v183) & 1) != v191 >> 63 )
      break;
    --v183;
  }
  while ( v183 );
  v192 = 62;
  v193 = v183 - 30;
  v194 = (unsigned int)(62 - v183) > 0x20;
  v195 = v191 << (62 - (unsigned __int8)v183);
  if ( (unsigned int)(62 - v183) >= 0x20 )
    v193 = 0;
  v196 = v195 / (s[2] >> v193);
  v197 = 30 - v183;
  if ( !v194 )
    v197 = 0;
  v198 = (int)v180 < 0;
  if ( (int)v180 >= 0 )
    v180 = (unsigned int)v180;
  else
    v180 = (unsigned int)-(int)v180;
  v199 = v180 << 32;
  if ( v198 )
    v199 = -(__int64)v199;
  v200 = v196 >> v197;
  s[55] = v196 >> v197;
  do
  {
    if ( ((v199 >> v192) & 1) != v199 >> 63 )
      break;
    --v192;
  }
  while ( v192 );
  v201 = v192 - 30;
  v202 = v199 << (62 - (unsigned __int8)v192);
  if ( (unsigned int)(62 - v192) >= 0x20 )
    v201 = 0;
  v203 = v202 / (s[0] >> v201);
  v204 = 30 - v192;
  if ( (unsigned int)(62 - v192) <= 0x20 )
    v204 = 0;
  v205 = v203 >> v204;
  s[54] = v203 >> v204;
  if ( v200 == v203 >> v204 )
    goto LABEL_397;
  v206 = v200 >> 63;
  v207 = v205 >> 63;
  if ( v200 >> 63 > v205 >> 63 )
    goto LABEL_369;
  if ( v207 > v206 )
    goto LABEL_397;
  if ( ((v205 | v200) & 0x8000000000000000LL) != 0 )
  {
    v208 = 0;
    while ( ((v200 >> ((unsigned __int8)v208 + 62)) & 1) == v206 )
    {
      if ( --v208 == -62 )
        goto LABEL_385;
    }
    if ( (unsigned int)(v208 + 31) >= 0xFFFFFFC2 )
    {
LABEL_385:
      v210 = 0xFFFFFFFF00000000LL * v200;
      v209 = 0;
    }
    else
    {
      v209 = v208 + 32;
      v210 = ((__int64)v200 >> (((unsigned int)(v208 + 32) >> 1) + ((v208 + 62) & 1)))
           * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v208 + 32) >> 1));
      if ( (unsigned int)(v208 + 32) >= 0x21 )
      {
        v210 <<= v208;
        goto LABEL_387;
      }
      if ( !(_DWORD)v208 )
      {
LABEL_387:
        v211 = 0;
        while ( ((v205 >> ((unsigned __int8)v211 + 62)) & 1) == v207 )
        {
          if ( --v211 == -62 )
            goto LABEL_394;
        }
        if ( (unsigned int)(v211 + 31) >= 0xFFFFFFC2 )
        {
LABEL_394:
          v213 = 0xFFFFFFFF00000000LL * v205;
          v212 = 0;
        }
        else
        {
          v212 = v211 + 32;
          v213 = ((__int64)v205 >> (((unsigned int)(v211 + 32) >> 1) + ((v211 + 62) & 1)))
               * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v211 + 32) >> 1));
          if ( (unsigned int)(v211 + 32) >= 0x21 )
          {
            v213 <<= v211;
            goto LABEL_396;
          }
          if ( !(_DWORD)v211 )
          {
LABEL_396:
            if ( v210 > v213 )
              goto LABEL_369;
            goto LABEL_397;
          }
        }
        v213 >>= 32 - v212;
        goto LABEL_396;
      }
    }
    v210 >>= 32 - v209;
    goto LABEL_387;
  }
  if ( (__int64)v200 > (__int64)v205 )
    goto LABEL_397;
LABEL_369:
  LODWORD(s[53]) = 1;
LABEL_397:
  v214 = 62;
  v215 = s[5] >> 63;
  do
  {
    if ( ((s[5] >> v214) & 1LL) != v215 )
      break;
    --v214;
  }
  while ( v214 );
  v216 = v214 - 30;
  v217 = (unsigned int)(62 - v214) > 0x20;
  if ( (unsigned int)(62 - v214) >= 0x20 )
    v216 = 0;
  v218 = (s[5] << (62 - (unsigned __int8)v214)) / (s[2] >> v216);
  v219 = 30 - v214;
  if ( !v217 )
    v219 = 0;
  v220 = v218 >> v219;
  s[56] = v220;
  if ( v220 != v205 )
  {
    v221 = (unsigned __int64)v220 >> 63;
    v222 = v205 >> 63;
    if ( (unsigned __int64)v220 >> 63 > v205 >> 63 )
      goto LABEL_406;
    if ( v222 <= v221 )
    {
      if ( ((v220 | v205) & 0x8000000000000000LL) == 0 )
      {
        if ( v220 > (__int64)v205 )
          goto LABEL_430;
LABEL_406:
        LODWORD(s[53]) = 1;
        goto LABEL_430;
      }
      v223 = 0;
      while ( (((unsigned __int64)v220 >> ((unsigned __int8)v223 + 62)) & 1) == v221 )
      {
        if ( --v223 == -62 )
          goto LABEL_418;
      }
      if ( (unsigned int)(v223 + 31) >= 0xFFFFFFC2 )
      {
LABEL_418:
        v225 = 0xFFFFFFFF00000000LL * v220;
        v224 = 0;
      }
      else
      {
        v224 = v223 + 32;
        v225 = (v220 >> (((unsigned int)(v223 + 32) >> 1) + ((v223 + 62) & 1)))
             * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v223 + 32) >> 1));
        if ( (unsigned int)(v223 + 32) >= 0x21 )
        {
          v225 <<= v223;
          goto LABEL_420;
        }
        if ( !(_DWORD)v223 )
        {
LABEL_420:
          v226 = 0;
          while ( ((v205 >> ((unsigned __int8)v226 + 62)) & 1) == v222 )
          {
            if ( --v226 == -62 )
              goto LABEL_427;
          }
          if ( (unsigned int)(v226 + 31) >= 0xFFFFFFC2 )
          {
LABEL_427:
            v228 = 0xFFFFFFFF00000000LL * v205;
            v227 = 0;
          }
          else
          {
            v227 = v226 + 32;
            v228 = ((__int64)v205 >> (((unsigned int)(v226 + 32) >> 1) + ((v226 + 62) & 1)))
                 * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v226 + 32) >> 1));
            if ( (unsigned int)(v226 + 32) >= 0x21 )
            {
              v228 <<= v226;
              goto LABEL_429;
            }
            if ( !(_DWORD)v226 )
            {
LABEL_429:
              if ( v225 <= v228 )
                goto LABEL_430;
              goto LABEL_406;
            }
          }
          v228 >>= 32 - v227;
          goto LABEL_429;
        }
      }
      v225 >>= 32 - v224;
      goto LABEL_420;
    }
  }
LABEL_430:
  v229 = v181 - v175;
  HIDWORD(s[13]) = 4;
  s[57] = v181 - v175;
  if ( v181 - v175 < 0x10000 )
  {
    v229 = 0;
    goto LABEL_442;
  }
  if ( v229 < 0 )
  {
    v230 = 0;
    while ( (((unsigned __int64)v229 >> ((unsigned __int8)v230 + 62)) & 1) != 0 )
    {
      if ( --v230 == -62 )
        goto LABEL_440;
    }
    if ( (unsigned int)(v230 + 62) <= 0x3D )
    {
LABEL_440:
      v231 = 0;
      v229 = -v229;
    }
    else
    {
      v231 = v230 + 1;
      v229 = -(v229 >> (((v230 + 1) & 1) + ((unsigned int)(v230 + 1) >> 1)));
      if ( (unsigned int)(v230 + 1) >= 0x21 )
      {
        v229 <<= (unsigned __int8)v230 - 31;
        goto LABEL_442;
      }
      if ( (_DWORD)v230 == 31 )
      {
LABEL_442:
        s[57] = v229;
        goto LABEL_443;
      }
    }
    v229 >>= 32 - v231;
    goto LABEL_442;
  }
LABEL_443:
  v232 = 62;
  v785 = v229;
  LODWORD(s[43]) = 0;
  do
  {
    if ( ((s[1] >> v232) & 1LL) != s[1] >> 63 )
      break;
    --v232;
  }
  while ( v232 );
  v233 = 62 - v232;
  v234 = LODWORD(s[9]) + LODWORD(s[6]);
  if ( (unsigned int)(62 - v232) >= 0x20 )
    v235 = 0;
  else
    v235 = v232 - 30;
  if ( v233 <= 0x20 )
    v236 = 0;
  else
    v236 = 30 - v232;
  v237 = s[3] >> v235;
  v238 = -32;
  if ( v234 >= 0 )
    LODWORD(v239) = LODWORD(s[9]) + LODWORD(s[6]);
  else
    v239 = -v234;
  if ( SLODWORD(s[61]) >= 0LL )
    v240 = SLODWORD(s[61]);
  else
    v240 = -(__int64)SLODWORD(s[61]);
  v241 = (unsigned int)v239 / (unsigned int)v240;
  v242 = (unsigned int)v239 % (unsigned int)v240;
  do
  {
    v243 = 2 * v242;
    if ( v243 < v240 )
      v244 = 0;
    else
      v244 = v240;
    v26 = __CFADD__(v238++, 1);
    v241 = (v243 >= v240) | (2 * v241);
    v242 = v243 - v244;
  }
  while ( !v26 );
  v245 = s[1] << v233;
  if ( v240 > 2 * v242 )
    v246 = v241;
  else
    v246 = v241 + 1;
  v61 = ((SLODWORD(s[61]) ^ (unsigned __int64)v234) & 0x8000000000000000LL) != 0LL;
  v247 = 62;
  v248 = v245 / v237;
  v249 = v248 >> v236;
  v250 = (unsigned __int64)v248 >> 63;
  if ( v61 )
    v251 = -(__int64)v246;
  else
    v251 = v246;
  do
  {
    if ( (((unsigned __int64)v249 >> v247) & 1) != v250 )
      break;
    --v247;
  }
  while ( v247 );
  v252 = 62;
  do
  {
    if ( (((unsigned __int64)v251 >> v252) & 1) != (unsigned __int64)v251 >> 63 )
      break;
    --v252;
  }
  while ( v252 );
  v253 = v252 + v247;
  v254 = v253 - 61;
  if ( v253 <= 0x3D )
  {
    v255 = v251 * v249;
    LOBYTE(v254) = 0;
    goto LABEL_480;
  }
  v255 = (v249 >> ((v254 >> 1) + (v254 & 1))) * (v251 >> (v254 >> 1));
  if ( v254 >= 0x21 )
  {
    v255 <<= (unsigned __int8)v253 - 93;
    goto LABEL_481;
  }
  if ( v253 != 93 )
LABEL_480:
    v255 >>= 32 - (unsigned __int8)v254;
LABEL_481:
  v256 = v249 == 0;
  v257 = 0xFFFFFFFF00000001LL;
  if ( v249 >= 0 )
    v257 = 0xFFFFFFFFLL;
  v771 = HIDWORD(v255);
  v258 = ((v257 + v249) >> 32) + 9;
  LODWORD(s[52]) = HIDWORD(v255);
  if ( v256 )
    v258 = 9;
  v259 = SLODWORD(s[10]);
  s[48] = v258 | 0x500000000LL;
  if ( SLODWORD(s[10]) < 0LL )
    v259 = -(__int64)SLODWORD(s[10]);
  v260 = v259 >> 3;
  v261 = v259 & 7;
  v262 = -32;
  v263 = v260;
  v796 = v261;
  v797 = v260;
  do
  {
    v264 = 2 * v261;
    if ( v264 <= 7 )
      v265 = 0;
    else
      v265 = -8;
    v26 = __CFADD__(v262++, 1);
    v263 = (v264 > 7) | (2 * v263);
    v261 = v265 + v264;
  }
  while ( !v26 );
  if ( (v261 & 0x7FFFFFFFFFFFFFFCLL) != 0 )
    v266 = v263 + 1;
  else
    v266 = v263;
  v267 = 62;
  if ( SLODWORD(s[10]) < 0 )
    v266 = -v266;
  do
  {
    if ( ((s[5] >> v267) & 1LL) != v215 )
      break;
    --v267;
  }
  while ( v267 );
  v268 = 62;
  do
  {
    if ( (((unsigned __int64)v266 >> v268) & 1) != (unsigned __int64)v266 >> 63 )
      break;
    --v268;
  }
  while ( v268 );
  v269 = v268 + v267;
  v270 = v269 - 61;
  if ( v269 <= 0x3D )
  {
    v271 = v266 * s[5];
    LOBYTE(v270) = 0;
    goto LABEL_508;
  }
  v271 = (s[5] >> ((v270 >> 1) + (v270 & 1))) * (v266 >> (v270 >> 1));
  if ( v270 >= 0x21 )
  {
    v271 <<= (unsigned __int8)v269 - 93;
    goto LABEL_509;
  }
  if ( v269 != 93 )
LABEL_508:
    v271 >>= 32 - (unsigned __int8)v270;
LABEL_509:
  v272 = v271 == 0;
  v273 = 0xFFFFFFFF00000001LL;
  if ( v271 >= 0 )
    v273 = 0xFFFFFFFFLL;
  v274 = (v273 + v271) >> 32;
  if ( v272 )
    LODWORD(v274) = 0;
  LODWORD(s[35]) = v274;
  if ( !LODWORD(s[13]) )
    goto LABEL_622;
  v275 = 62;
  do
  {
    if ( ((v205 >> v275) & 1) != v205 >> 63 )
      break;
    --v275;
  }
  while ( v275 );
  v276 = 62;
  do
  {
    if ( ((s[0] >> v276) & 1LL) != v148 )
      break;
    --v276;
  }
  while ( v276 );
  v277 = v276 + v275;
  v278 = v277 - 61;
  if ( v277 <= 0x3D )
  {
    v279 = v205 * s[0];
    LOBYTE(v278) = 0;
LABEL_524:
    v279 >>= 32 - (unsigned __int8)v278;
    goto LABEL_525;
  }
  v279 = ((__int64)v205 >> ((v278 >> 1) + (v278 & 1))) * (s[0] >> (v278 >> 1));
  if ( v278 >= 0x21 )
  {
    v279 <<= (unsigned __int8)v277 - 93;
    goto LABEL_525;
  }
  if ( v277 != 93 )
    goto LABEL_524;
LABEL_525:
  v280 = v279 == 0;
  v281 = 0xFFFFFFFF00000001LL;
  if ( v279 >= 0 )
    v281 = 0xFFFFFFFFLL;
  LODWORD(s[34]) = HIDWORD(s[21]);
  v282 = (v281 + v279) >> 32;
  *(_QWORD *)((char *)&s[44] + 4) = 1;
  v284 = v796;
  v283 = v260;
  if ( v280 )
    LODWORD(v282) = 0;
  if ( s[21] >= 0 )
    v285 = v179;
  else
    v285 = -v179;
  v286 = -32;
  HIDWORD(s[49]) = v282;
  s[33] = v285;
  do
  {
    v287 = 2 * v284;
    if ( v287 <= 7 )
      v288 = 0;
    else
      v288 = -8;
    v26 = __CFADD__(v286++, 1);
    v283 = (v287 > 7) | (2 * v283);
    v284 = v288 + v287;
  }
  while ( !v26 );
  if ( (v284 & 0x7FFFFFFFFFFFFFFCLL) != 0 )
    v289 = v283 + 1;
  else
    v289 = v283;
  v290 = 62;
  if ( SLODWORD(s[10]) < 0 )
    v289 = -v289;
  do
  {
    if ( ((s[5] >> v290) & 1LL) != v215 )
      break;
    --v290;
  }
  while ( v290 );
  v291 = 62;
  do
  {
    if ( (((unsigned __int64)v289 >> v291) & 1) != (unsigned __int64)v289 >> 63 )
      break;
    --v291;
  }
  while ( v291 );
  v292 = v291 + v290;
  v293 = v292 - 61;
  if ( v292 <= 0x3D )
  {
    v294 = v289 * s[5];
    LOBYTE(v293) = 0;
LABEL_552:
    v294 >>= 32 - (unsigned __int8)v293;
    goto LABEL_553;
  }
  v294 = (s[5] >> ((v293 >> 1) + (v293 & 1))) * (v289 >> (v293 >> 1));
  if ( v293 < 0x21 )
  {
    if ( v292 == 93 )
      goto LABEL_553;
    goto LABEL_552;
  }
  v294 <<= (unsigned __int8)v292 - 93;
LABEL_553:
  v295 = 62;
  do
  {
    if ( (((unsigned __int64)v294 >> v295) & 1) != (unsigned __int64)v294 >> 63 )
      break;
    --v295;
  }
  while ( v295 );
  v296 = v295 - 30;
  HIDWORD(s[27]) = 0;
  v297 = v294 << (62 - (unsigned __int8)v295);
  if ( (unsigned int)(62 - v295) >= 0x20 )
    v296 = 0;
  v298 = v297 / (v285 >> v296);
  v299 = 30 - v295;
  if ( (unsigned int)(62 - v295) <= 0x20 )
    v299 = 0;
  v300 = (unsigned __int64)(v298 >> v299) >> 32;
  v301 = (int)v300 / SHIDWORD(s[9]);
  s[26] = __PAIR64__((int)v300 / SHIDWORD(s[9]), v300);
  v302 = -32;
  LODWORD(s[27]) = v301;
  v303 = (int)v274 - SHIDWORD(s[21]) * (__int64)(v301 * HIDWORD(s[9]));
  if ( v303 >= 0 )
    v304 = (int)v274 - SHIDWORD(s[21]) * (__int64)(v301 * HIDWORD(s[9]));
  else
    v304 = SHIDWORD(s[21]) * (__int64)(v301 * HIDWORD(s[9])) - (int)v274;
  if ( s[9] >= 0LL )
    v305 = SHIDWORD(s[9]);
  else
    v305 = -(__int64)SHIDWORD(s[9]);
  v306 = v304 / v305;
  v307 = v304 % v305;
  do
  {
    v308 = 2 * v307;
    if ( v308 < v305 )
      v309 = 0;
    else
      v309 = v305;
    v26 = __CFADD__(v302++, 1);
    v306 = (v308 >= v305) | (2 * v306);
    v307 = v308 - v309;
  }
  while ( !v26 );
  v310 = v303 ^ SHIDWORD(s[9]);
  if ( v305 <= 2 * v307 )
    ++v306;
  v205 = v258 + (unsigned int)v282;
  if ( v310 >= 0 )
    v311 = v306;
  else
    v311 = -(__int64)v306;
  v312 = 0xFFFFFFFF00000001LL;
  v313 = v311 == 0;
  if ( v311 >= 0 )
    v312 = 0xFFFFFFFFLL;
  v314 = (v312 + v311) >> 32;
  if ( v313 )
    LODWORD(v314) = 0;
  HIDWORD(s[52]) = v314;
  LODWORD(s[50]) = v314 + LODWORD(s[20]) * v301;
  v315 = v205 + LODWORD(s[50]) + 5;
  if ( LODWORD(s[12]) == 1 )
  {
    if ( v315 >= 0 )
      v316 = v205 + LODWORD(s[50]) + 5;
    else
      v316 = -v315;
    if ( HIDWORD(s[9]) == 1 )
    {
      v317 = v316 / 0x1F4uLL;
      v318 = v316 % 0x1F4;
      v319 = -32;
      v205 = -500;
      do
      {
        v320 = 2 * v318;
        if ( v320 <= 0x1F3 )
          v321 = 0;
        else
          v321 = -500;
        v26 = __CFADD__(v319++, 1);
        v317 = (v320 > 0x1F3) | (unsigned __int64)(2 * v317);
        v318 = v321 + v320;
      }
      while ( !v26 );
      v322 = 0xFFFFFFFF00000001LL;
      if ( 2 * v318 > 0x1F3 )
        ++v317;
      if ( v315 < 0 )
        v317 = -v317;
      v323 = v317 == 0;
      if ( v317 >= 0 )
        v322 = 0xFFFFFFFFLL;
      v324 = (int)(12 * ((v322 + v317) >> 32));
    }
    else
    {
      v326 = v316 / 0xFAuLL;
      v327 = v316 % 0xFA;
      v328 = -32;
      v205 = -250;
      do
      {
        v329 = 2 * v327;
        if ( v329 <= 0xF9 )
          v330 = 0;
        else
          v330 = -250;
        v26 = __CFADD__(v328++, 1);
        v326 = (v329 > 0xF9) | (unsigned __int64)(2 * v326);
        v327 = v330 + v329;
      }
      while ( !v26 );
      v331 = 0xFFFFFFFF00000001LL;
      if ( 2 * v327 > 0xF9 )
        ++v326;
      if ( v315 < 0 )
        v326 = -v326;
      v323 = v326 == 0;
      if ( v326 >= 0 )
        v331 = 0xFFFFFFFFLL;
      v324 = (int)(6 * ((v331 + v326) >> 32));
    }
    if ( v323 )
      v325 = 1;
    else
      v325 = v324 + 1;
  }
  else
  {
    v325 = 0;
  }
  s[51] = v325;
  LODWORD(s[49]) = v315 + v325;
  if ( v315 + (int)v325 + 1 >= (int)v771 )
    LODWORD(s[53]) = 1;
LABEL_622:
  if ( !v785 && LODWORD(s[53]) != 1 )
    goto LABEL_1421;
  v332 = HIDWORD(s[9]);
  v333 = s[16] >> 63;
  v334 = BYTE4(s[42]);
  v335 = 0;
  if ( s[9] >= 0LL )
    v336 = SHIDWORD(s[9]);
  else
    v336 = -(__int64)SHIDWORD(s[9]);
  v337 = 4;
  v757 = StatusReg;
  v758 = a2;
  v770 = v200 >> 63;
  v773 = v200;
  v761 = 0xFFFFFFFF00000000LL * v200;
  v763 = s[46];
  v338 = v336 << 32;
  if ( s[9] < 0 )
    v338 = 0xFFFFFFFF00000000LL * v336;
  v779 = v338;
  v341 = (LODWORD(s[13]) != 1 || LODWORD(s[58]) != 0) && LODWORD(s[13]) != 0;
  v759 = v341;
  while ( 2 )
  {
    v342 = 62;
    do
    {
      if ( ((s[0] >> v342) & 1LL) != v148 )
        break;
      --v342;
    }
    while ( v342 );
    v343 = v342 - 30;
    v760 = v337;
    v344 = (unsigned int)(62 - v342) > 0x20;
    if ( (unsigned int)(62 - v342) >= 0x20 )
      v343 = 0;
    v345 = (s[0] << (62 - (unsigned __int8)v342)) / (s[2] >> v343);
    v346 = 30 - v342;
    if ( v344 )
      v347 = v346;
    else
      v347 = 0;
    v348 = v337 << 32;
    v349 = v345 >> v347;
    v350 = 62;
    do
    {
      if ( (((unsigned __int64)v348 >> v350) & 1) != ((v337 >> 31) & 1) )
        break;
      --v350;
    }
    while ( v350 );
    v351 = 62;
    do
    {
      if ( (((unsigned __int64)v349 >> v351) & 1) != (unsigned __int64)v349 >> 63 )
        break;
      --v351;
    }
    while ( v351 );
    v352 = v351 + v350;
    v764 = v334;
    v353 = v352 - 61;
    if ( v352 <= 0x3D )
    {
      v354 = v349 * v348;
      LOBYTE(v353) = 0;
LABEL_657:
      v354 >>= 32 - (unsigned __int8)v353;
      goto LABEL_658;
    }
    v354 = (v348 >> ((v353 >> 1) + (v353 & 1))) * (v349 >> (v353 >> 1));
    if ( v353 >= 0x21 )
    {
      v354 <<= (unsigned __int8)v352 - 93;
      goto LABEL_658;
    }
    if ( v352 != 93 )
      goto LABEL_657;
LABEL_658:
    v355 = 0xFFFFFFFF00000001LL;
    v356 = -32;
    if ( v354 >= 0 )
      v355 = 0xFFFFFFFFLL;
    v357 = v355 + v354;
    v358 = v796;
    v359 = v797;
    do
    {
      v360 = 2 * v358;
      if ( v360 <= 7 )
        v361 = 0;
      else
        v361 = -8;
      v26 = __CFADD__(v356++, 1);
      v359 = (v360 > 7) | (2 * v359);
      v358 = v361 + v360;
    }
    while ( !v26 );
    v362 = HIDWORD(v357);
    if ( v354 )
      v363 = v362;
    else
      v363 = 0;
    v781 = v363;
    if ( (v358 & 0x7FFFFFFFFFFFFFFCLL) != 0 )
      v364 = v359 + 1;
    else
      v364 = v359;
    v365 = 62;
    if ( SLODWORD(s[10]) < 0 )
      v364 = -v364;
    do
    {
      if ( ((s[5] >> v365) & 1LL) != v215 )
        break;
      --v365;
    }
    while ( v365 );
    v366 = 62;
    do
    {
      if ( (((unsigned __int64)v364 >> v366) & 1) != (unsigned __int64)v364 >> 63 )
        break;
      --v366;
    }
    while ( v366 );
    v367 = v366 + v365;
    v368 = v367 - 61;
    if ( v367 <= 0x3D )
    {
      v369 = v364 * s[5];
      LOBYTE(v368) = 0;
LABEL_683:
      v369 >>= 32 - (unsigned __int8)v368;
      goto LABEL_684;
    }
    v369 = (s[5] >> ((v368 >> 1) + (v368 & 1))) * (v364 >> (v368 >> 1));
    if ( v368 >= 0x21 )
    {
      v369 <<= (unsigned __int8)v367 - 93;
      goto LABEL_684;
    }
    if ( v367 != 93 )
      goto LABEL_683;
LABEL_684:
    v370 = v369 == 0;
    v371 = 0xFFFFFFFF00000001LL;
    v205 = 0x3E800000000LL;
    if ( v369 >= 0 )
      v371 = 0xFFFFFFFFLL;
    v767 = v335;
    v768 = v335;
    v372 = v371 + v369;
    v373 = 32;
    v374 = HIDWORD(v372);
    if ( v370 )
      LODWORD(v374) = 0;
    v375 = (v374 & 0x80000000) != 0LL;
    v772 = v374;
    if ( (v374 & 0x80000000) == 0LL )
      v374 = (unsigned int)v374;
    else
      v374 = (unsigned int)-(int)v374;
    v376 = v374 << 32;
    if ( v375 )
      v376 = -(__int64)v376;
    v780 = v376;
    v765 = v763;
    while ( 2 )
    {
      v377 = v373 << 32;
      v378 = (v373 >> 31) & 1;
      v379 = 1;
      v790 = v373;
      v784 = (v373 << 32) * s[15];
      v782 = (v373 << 32) * s[16];
      v769 = v768;
      v766 = v765;
      while ( 2 )
      {
        LODWORD(v380) = v332 * v379;
        v381 = v769;
        v382 = 1;
        v802 = v379;
        if ( v332 * (int)v379 >= 0 )
          v380 = (unsigned int)v380;
        else
          v380 = (unsigned int)-(int)v380;
        v383 = v380 << 32;
        if ( v332 * (int)v379 >= 0 )
          v384 = v383;
        else
          v384 = -v383;
        v774 = v766;
        while ( 2 )
        {
          v385 = 62;
          v792 = v381;
          do
          {
            if ( ((s[15] >> v385) & 1LL) != v168 )
              break;
            --v385;
          }
          while ( v385 );
          v386 = 62;
          do
          {
            if ( (((unsigned __int64)v377 >> v386) & 1) != v378 )
              break;
            --v386;
          }
          while ( v386 );
          v387 = v386 + v385;
          v798 = v205;
          if ( (unsigned int)(v386 + v385) < 0x3E )
          {
            v389 = v784;
            LOBYTE(v388) = 0;
LABEL_717:
            v389 >>= 32 - (unsigned __int8)v388;
            goto LABEL_718;
          }
          v388 = v387 - 61;
          v389 = (s[15] >> ((v388 >> 1) + ((v387 - 61) & 1))) * (v377 >> (v388 >> 1));
          if ( (unsigned int)(v387 - 61) >= 0x21 )
          {
            v389 <<= (unsigned __int8)v387 - 93;
            goto LABEL_718;
          }
          if ( v387 != 93 )
            goto LABEL_717;
LABEL_718:
          v390 = v389 == 0;
          v391 = 0xFFFFFFFF00000001LL;
          v392 = v382 + v379;
          if ( v389 >= 0 )
            v391 = 0xFFFFFFFFLL;
          v393 = (v391 + v389) >> 32;
          if ( v390 )
            v394 = 0;
          else
            v394 = v393;
          v395 = v394 * v379 + (v394 - 1) * v382;
          v803 = v394 - 1;
          v799 = v394 * v379;
          if ( v395 >= 0 )
            v396 = v394 * v379 + (v394 - 1) * v382;
          else
            v396 = -v395;
          v397 = v396 / (unsigned int)v392;
          v398 = v396 % (unsigned int)v392;
          v399 = -32;
          do
          {
            v400 = 2 * v398;
            if ( v400 < v392 )
              v401 = 0;
            else
              v401 = v382 + v379;
            v26 = __CFADD__(v399++, 1);
            v397 = (v400 >= v392) | (2 * v397);
            v398 = v400 - v401;
          }
          while ( !v26 );
          v9 = v392 > 2 * v398;
          v403 = v796;
          v402 = v797;
          v404 = !v9;
          v405 = -32;
          do
          {
            v406 = 2 * v403;
            if ( v406 <= 7 )
              v407 = 0;
            else
              v407 = -8;
            v26 = __CFADD__(v405++, 1);
            v402 = (v406 > 7) | (2 * v402);
            v403 = v407 + v406;
          }
          while ( !v26 );
          v408 = v397 + v404;
          if ( v395 < 0 )
            v408 = -v408;
          if ( (v403 & 0x7FFFFFFFFFFFFFFCLL) != 0 )
            v409 = v402 + 1;
          else
            v409 = v402;
          v410 = 62;
          if ( SLODWORD(s[10]) < 0 )
            v409 = -v409;
          do
          {
            if ( ((s[5] >> v410) & 1LL) != v215 )
              break;
            --v410;
          }
          while ( v410 );
          v411 = 62;
          do
          {
            if ( (((unsigned __int64)v409 >> v411) & 1) != (unsigned __int64)v409 >> 63 )
              break;
            --v411;
          }
          while ( v411 );
          v412 = v411 + v410;
          v413 = v412 - 61;
          if ( v412 <= 0x3D )
          {
            v414 = v409 * s[5];
            LOBYTE(v413) = 0;
LABEL_757:
            v414 >>= 32 - (unsigned __int8)v413;
            goto LABEL_758;
          }
          v414 = (s[5] >> ((v413 >> 1) + (v413 & 1))) * (v409 >> (v413 >> 1));
          if ( v413 < 0x21 )
          {
            if ( v412 == 93 )
              goto LABEL_758;
            goto LABEL_757;
          }
          v414 <<= (unsigned __int8)v412 - 93;
LABEL_758:
          v415 = 62;
          do
          {
            if ( (((unsigned __int64)v414 >> v415) & 1) != (unsigned __int64)v414 >> 63 )
              break;
            --v415;
          }
          while ( v415 );
          v416 = v415 - 30;
          v417 = 62;
          v418 = (unsigned int)(62 - v415) > 0x20;
          v419 = v414 << (62 - (unsigned __int8)v415);
          if ( (unsigned int)(62 - v415) >= 0x20 )
            v416 = 0;
          v420 = v419 / (v408 >> v416);
          v421 = 30 - v415;
          if ( !v418 )
            v421 = 0;
          v422 = v420 >> v421;
          if ( (unsigned int)v422 <= 0xFFFFF000 )
            v423 = HIDWORD(v422);
          else
            v423 = HIDWORD(v422) + 1;
          v795 = v423;
          if ( v423 >= 0LL )
            v424 = v423;
          else
            v424 = -(__int64)v423;
          v425 = v424 << 32;
          if ( v423 < 0 )
            v425 = 0xFFFFFFFF00000000LL * v424;
          do
          {
            if ( ((v425 >> v417) & 1) != v425 >> 63 )
              break;
            --v417;
          }
          while ( v417 );
          v426 = 62;
          do
          {
            if ( (((unsigned __int64)v408 >> v426) & 1) != (unsigned __int64)v408 >> 63 )
              break;
            --v426;
          }
          while ( v426 );
          v427 = v426 + v417;
          v428 = v427 - 61;
          if ( v427 <= 0x3D )
          {
            v429 = v425 * v408;
            LOBYTE(v428) = 0;
LABEL_782:
            v429 >>= 32 - (unsigned __int8)v428;
            goto LABEL_783;
          }
          v429 = ((__int64)v425 >> ((v428 >> 1) + (v428 & 1))) * (v408 >> (v428 >> 1));
          if ( v428 < 0x21 )
          {
            if ( v427 == 93 )
              goto LABEL_783;
            goto LABEL_782;
          }
          v429 <<= (unsigned __int8)v427 - 93;
LABEL_783:
          v430 = 62;
          v431 = v780 - v429;
          do
          {
            if ( ((v431 >> v430) & 1) != v431 >> 63 )
              break;
            --v430;
          }
          while ( v430 );
          v432 = v430 - 30;
          v433 = v431 << (62 - (unsigned __int8)v430);
          if ( (unsigned int)(62 - v430) >= 0x20 )
            v432 = 0;
          v434 = v433 / (v779 >> v432);
          v435 = 30 - v430;
          v436 = 62;
          if ( (unsigned int)(62 - v430) <= 0x20 )
            v435 = 0;
          v437 = v434 >> v435;
          v438 = (unsigned __int64)v434 >> 63;
          do
          {
            if ( ((v437 >> v436) & 1) != v438 )
              break;
            --v436;
          }
          while ( v436 );
          v439 = v424 / v336;
          v440 = v436 - 30;
          v441 = 62 - v436;
          if ( (unsigned int)(62 - v436) >= 0x20 )
            v440 = 0;
          v442 = v424 % v336;
          v443 = 30 - v436;
          v444 = v377 >> v440;
          if ( v441 <= 0x20 )
            v443 = 0;
          v445 = -32;
          do
          {
            v446 = 2 * v442;
            if ( v446 < v336 )
              v447 = 0;
            else
              v447 = v336;
            v26 = __CFADD__(v445++, 1);
            v439 = (v446 >= v336) | (2 * v439);
            v442 = v446 - v447;
          }
          while ( !v26 );
          v448 = v423 ^ (unsigned __int64)SHIDWORD(s[9]);
          if ( v336 > 2 * v442 )
            v449 = v439;
          else
            v449 = v439 + 1;
          if ( v448 >= 0 )
            v450 = v449;
          else
            v450 = -v449;
          v451 = (__int64)(v437 << v441) / v444;
          v787 = HIDWORD(v450);
          v452 = SHIDWORD(v450) / (int)v392;
          v453 = SHIDWORD(v450) % (int)v392;
          v789 = SHIDWORD(v450) / (int)v392;
          v454 = SHIDWORD(v450) % (int)v392 * v394;
          v788 = v453;
          v9 = v453 - (int)v802 <= 0;
          v786 = v453 - v802;
          v455 = (v453 - v802) & ~((v453 - (int)v802) >> 31);
          v778 = v455;
          if ( !v9 )
            v454 = v799;
          LODWORD(v456) = v454 + v452 * v395 + v455 * v803;
          v457 = v451 >> v443;
          v777 = v451 >> v443;
          v458 = (int)v456 < 0;
          if ( (int)v456 >= 0 )
            v456 = (unsigned int)v456;
          else
            v456 = (unsigned int)-(int)v456;
          v459 = v456 << 32;
          v460 = v450 >> 32;
          if ( v458 )
            v461 = -v459;
          else
            v461 = v459;
          if ( v460 >= 0 )
            v462 = v450 >> 32;
          else
            v462 = -v460;
          if ( v437 )
          {
            v463 = v461 + v437;
            if ( v460 >= 0 )
              v464 = v462 << 32;
            else
              v464 = 0xFFFFFFFF00000000LL * v462;
            v465 = v464 + v457;
            v466 = 62;
            do
            {
              if ( ((v463 >> v466) & 1) != v463 >> 63 )
                break;
              --v466;
            }
            while ( v466 );
          }
          else
          {
            v466 = 62;
            if ( v460 >= 0 )
              v465 = v462 << 32;
            else
              v465 = 0xFFFFFFFF00000000LL * v462;
            do
            {
              if ( ((v461 >> v466) & 1) != v461 >> 63 )
                break;
              --v466;
            }
            while ( v466 );
            v463 = v461;
          }
          v467 = v466 - 30;
          if ( (unsigned int)(62 - v466) >= 0x20 )
            v467 = 0;
          v468 = (__int64)(v463 << (62 - (unsigned __int8)v466)) / (v465 >> v467);
          v469 = 30 - v466;
          if ( (unsigned int)(62 - v466) <= 0x20 )
            v469 = 0;
          v470 = v468 >> v469;
          v471 = 62;
          do
          {
            if ( ((s[15] >> v471) & 1LL) != v168 )
              break;
            --v471;
          }
          while ( v471 );
          v472 = 62;
          do
          {
            if ( (((unsigned __int64)v377 >> v472) & 1) != v378 )
              break;
            --v472;
          }
          while ( v472 );
          v473 = v472 + v471;
          if ( (unsigned int)(v472 + v471) < 0x3E )
          {
            v475 = v784;
            LOBYTE(v474) = 0;
LABEL_855:
            v475 >>= 32 - (unsigned __int8)v474;
            goto LABEL_856;
          }
          v474 = v473 - 61;
          v475 = (s[15] >> ((v474 >> 1) + ((v473 - 61) & 1))) * (v377 >> (v474 >> 1));
          if ( (unsigned int)(v473 - 61) >= 0x21 )
          {
            v475 <<= (unsigned __int8)v473 - 93;
            goto LABEL_856;
          }
          if ( v473 != 93 )
            goto LABEL_855;
LABEL_856:
          v476 = v470 - v475;
          v783 = v470;
          if ( v470 < v475 )
          {
            v477 = v475 - v470;
            v478 = 0;
            while ( (((unsigned __int64)v477 >> ((unsigned __int8)v478 + 62)) & 1) == (unsigned __int64)v477 >> 63 )
            {
              if ( --v478 == -62 )
                goto LABEL_864;
            }
            if ( (unsigned int)(v478 + 31) >= 0xFFFFFFC2 )
            {
LABEL_864:
              v476 = 0xFFFFFFFF00000000LL * v477;
              v479 = 0;
LABEL_865:
              v476 >>= 32 - v479;
              goto LABEL_866;
            }
            v479 = v478 + 32;
            v476 = (v477 >> (((unsigned int)(v478 + 32) >> 1) + ((v478 + 62) & 1)))
                 * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v478 + 32) >> 1));
            if ( (unsigned int)(v478 + 32) >= 0x21 )
            {
              v476 <<= v478;
              goto LABEL_866;
            }
            if ( (_DWORD)v478 )
              goto LABEL_865;
          }
LABEL_866:
          v480 = 62;
          do
          {
            if ( ((s[15] >> v480) & 1LL) != v168 )
              break;
            --v480;
          }
          while ( v480 );
          v481 = 62;
          do
          {
            if ( (((unsigned __int64)v377 >> v481) & 1) != v378 )
              break;
            --v481;
          }
          while ( v481 );
          v482 = v481 + v480;
          if ( (unsigned int)(v481 + v480) < 0x3E )
          {
            v484 = v784;
            LOBYTE(v483) = 0;
LABEL_876:
            v484 >>= 32 - (unsigned __int8)v483;
            goto LABEL_877;
          }
          v483 = v482 - 61;
          v484 = (s[15] >> ((v483 >> 1) + ((v482 - 61) & 1))) * (v377 >> (v483 >> 1));
          if ( (unsigned int)(v482 - 61) >= 0x21 )
          {
            v484 <<= (unsigned __int8)v482 - 93;
            goto LABEL_877;
          }
          if ( v482 != 93 )
            goto LABEL_876;
LABEL_877:
          if ( v408 >= v484 )
          {
            v791 = v408 - v484;
          }
          else
          {
            v485 = v484 - v408;
            v486 = 0;
            while ( (((unsigned __int64)v485 >> ((unsigned __int8)v486 + 62)) & 1) == (unsigned __int64)v485 >> 63 )
            {
              if ( --v486 == -62 )
                goto LABEL_886;
            }
            if ( (unsigned int)(v486 + 31) >= 0xFFFFFFC2 )
            {
LABEL_886:
              v488 = 0xFFFFFFFF00000000LL * v485;
              v487 = 0;
LABEL_887:
              v488 >>= 32 - v487;
              goto LABEL_888;
            }
            v487 = v486 + 32;
            v488 = (v485 >> (((unsigned int)(v486 + 32) >> 1) + ((v486 + 62) & 1)))
                 * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v486 + 32) >> 1));
            if ( (unsigned int)(v486 + 32) >= 0x21 )
            {
              v488 <<= v486;
              goto LABEL_888;
            }
            if ( (_DWORD)v486 )
              goto LABEL_887;
LABEL_888:
            v791 = v488;
          }
          v489 = v796;
          v490 = v797;
          v491 = -32;
          do
          {
            v492 = (unsigned __int64)(2 * v489) > 7;
            if ( v492 )
              v493 = -8;
            else
              v493 = 0;
            v26 = __CFADD__(v491++, 1);
            v490 = v492 | (2 * v490);
            v489 = v493 + 2 * v489;
          }
          while ( !v26 );
          v494 = 62;
          v794 = v795 % SHIDWORD(s[9]);
          if ( (v489 & 0x7FFFFFFFFFFFFFFCLL) != 0 )
            v495 = v490 + 1;
          else
            v495 = v490;
          if ( SLODWORD(s[10]) >= 0 )
            v496 = v495;
          else
            v496 = -(__int64)v495;
          do
          {
            if ( ((s[5] >> v494) & 1LL) != v215 )
              break;
            --v494;
          }
          while ( v494 );
          v497 = 62;
          do
          {
            if ( (((unsigned __int64)v496 >> v497) & 1) != (unsigned __int64)v496 >> 63 )
              break;
            --v497;
          }
          while ( v497 );
          v498 = v497 + v494;
          v499 = v497 + v494 - 61;
          if ( v498 <= 0x3D )
          {
            v500 = v496 * s[5];
            LOBYTE(v499) = 0;
LABEL_910:
            v500 >>= 32 - (unsigned __int8)v499;
            goto LABEL_911;
          }
          v500 = (s[5] >> ((v499 >> 1) + (v499 & 1))) * (v496 >> (v499 >> 1));
          if ( v499 < 0x21 )
          {
            if ( v499 == 32 )
              goto LABEL_911;
            goto LABEL_910;
          }
          v500 <<= (unsigned __int8)v498 - 93;
LABEL_911:
          v501 = 62;
          do
          {
            if ( (((unsigned __int64)v500 >> v501) & 1) != (unsigned __int64)v500 >> 63 )
              break;
            --v501;
          }
          while ( v501 );
          v502 = v501 - 30;
          if ( (unsigned int)(62 - v501) >= 0x20 )
            v502 = 0;
          v503 = (v500 << (62 - (unsigned __int8)v501)) / (v408 >> v502);
          v504 = 30 - v501;
          if ( (unsigned int)(62 - v501) <= 0x20 )
            v504 = 0;
          v505 = v503 >> v504;
          v506 = 0xFFFFFFFF00000001LL;
          v507 = v505 == 0;
          if ( v505 >= 0 )
            v506 = 0xFFFFFFFFLL;
          v508 = v506 + v505;
          v509 = 62;
          v510 = HIDWORD(v508);
          if ( v507 )
            LODWORD(v510) = 0;
          v793 = v510;
          do
          {
            if ( ((s[16] >> v509) & 1LL) != v333 )
              break;
            --v509;
          }
          while ( v509 );
          v511 = 62;
          do
          {
            if ( (((unsigned __int64)v377 >> v511) & 1) != v378 )
              break;
            --v511;
          }
          while ( v511 );
          v512 = v511 + v509;
          if ( v512 < 0x3E )
          {
            v514 = v782;
            LOBYTE(v513) = 0;
LABEL_932:
            v514 >>= 32 - (unsigned __int8)v513;
            goto LABEL_933;
          }
          v513 = v512 - 61;
          v514 = (s[16] >> ((v513 >> 1) + ((v512 - 61) & 1))) * (v377 >> (v513 >> 1));
          if ( v512 - 61 >= 0x21 )
          {
            v514 <<= (unsigned __int8)v512 - 93;
            goto LABEL_933;
          }
          if ( v512 != 93 )
            goto LABEL_932;
LABEL_933:
          v515 = v408 - v514;
          if ( v408 < v514 )
          {
            v516 = v514 - v408;
            v517 = 0;
            while ( (((unsigned __int64)v516 >> ((unsigned __int8)v517 + 62)) & 1) == (unsigned __int64)v516 >> 63 )
            {
              if ( --v517 == -62 )
                goto LABEL_941;
            }
            if ( (unsigned int)(v517 + 31) >= 0xFFFFFFC2 )
            {
LABEL_941:
              v515 = 0xFFFFFFFF00000000LL * v516;
              v518 = 0;
LABEL_942:
              v515 >>= 32 - v518;
              goto LABEL_943;
            }
            v518 = v517 + 32;
            v515 = (v516 >> (((unsigned int)(v517 + 32) >> 1) + ((v517 + 62) & 1)))
                 * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v517 + 32) >> 1));
            if ( (unsigned int)(v517 + 32) >= 0x21 )
            {
              v515 <<= v517;
              goto LABEL_943;
            }
            if ( (_DWORD)v517 )
              goto LABEL_942;
          }
LABEL_943:
          v519 = 62;
          if ( (v510 & 0x80000000) == 0LL )
            v510 = (unsigned int)v510;
          else
            v510 = (unsigned int)-(int)v510;
          v520 = v510 << 32;
          if ( v793 >= 0 )
            v521 = v520;
          else
            v521 = -v520;
          do
          {
            if ( (((unsigned __int64)v521 >> v519) & 1) != (unsigned __int64)v521 >> 63 )
              break;
            --v519;
          }
          while ( v519 );
          v522 = 62;
          do
          {
            if ( (((unsigned __int64)v515 >> v522) & 1) != (unsigned __int64)v515 >> 63 )
              break;
            --v522;
          }
          while ( v522 );
          v523 = v522 + v519;
          v524 = v522 + v519 - 61;
          if ( v523 <= 0x3D )
          {
            v525 = v515 * v521;
            LOBYTE(v524) = 0;
LABEL_958:
            v525 >>= 32 - (unsigned __int8)v524;
            goto LABEL_959;
          }
          v525 = (v521 >> ((v524 >> 1) + (v524 & 1))) * (v515 >> (v524 >> 1));
          if ( v524 >= 0x21 )
          {
            v525 <<= (unsigned __int8)v523 - 93;
            goto LABEL_959;
          }
          if ( v524 != 32 )
            goto LABEL_958;
LABEL_959:
          v526 = 0xFFFFFFFF00000001LL;
          if ( v525 >= 0 )
            v526 = 0xFFFFFFFFLL;
          v527 = 62;
          v528 = (v526 + v525) >> 32;
          if ( !v525 )
            LODWORD(v528) = 0;
          if ( (v525 & 0xFFFC0000) != 0 )
            v529 = v528;
          else
            v529 = HIDWORD(v525);
          do
          {
            if ( ((s[16] >> v527) & 1LL) != v333 )
              break;
            --v527;
          }
          while ( v527 );
          v530 = 62;
          do
          {
            if ( (((unsigned __int64)v377 >> v530) & 1) != v378 )
              break;
            --v530;
          }
          while ( v530 );
          v531 = v530 + v527;
          if ( (unsigned int)(v530 + v527) < 0x3E )
          {
            v533 = v782;
            LOBYTE(v532) = 0;
LABEL_975:
            v533 >>= 32 - (unsigned __int8)v532;
            goto LABEL_976;
          }
          v532 = v531 - 61;
          v533 = (s[16] >> ((v532 >> 1) + ((v531 - 61) & 1))) * (v377 >> (v532 >> 1));
          if ( (unsigned int)(v531 - 61) >= 0x21 )
          {
            v533 <<= (unsigned __int8)v531 - 93;
            goto LABEL_976;
          }
          if ( v531 != 93 )
            goto LABEL_975;
LABEL_976:
          if ( v394 >= 0 )
            v534 = (unsigned int)v394;
          else
            v534 = (unsigned int)-v394;
          v535 = v534 << 32;
          if ( v394 >= 0 )
            v536 = v535;
          else
            v536 = -v535;
          v537 = v536 - v533;
          if ( v536 < v533 )
          {
            v538 = v533 - v536;
            v539 = 0;
            while ( (((unsigned __int64)v538 >> ((unsigned __int8)v539 + 62)) & 1) == (unsigned __int64)v538 >> 63 )
            {
              if ( --v539 == -62 )
                goto LABEL_990;
            }
            if ( (unsigned int)(v539 + 31) >= 0xFFFFFFC2 )
            {
LABEL_990:
              v537 = 0xFFFFFFFF00000000LL * v538;
              v540 = 0;
LABEL_991:
              v537 >>= 32 - v540;
              goto LABEL_992;
            }
            v540 = v539 + 32;
            v537 = (v538 >> (((unsigned int)(v539 + 32) >> 1) + ((v539 + 62) & 1)))
                 * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v539 + 32) >> 1));
            if ( (unsigned int)(v539 + 32) >= 0x21 )
            {
              v537 <<= v539;
              goto LABEL_992;
            }
            if ( (_DWORD)v539 )
              goto LABEL_991;
          }
LABEL_992:
          v541 = 62;
          do
          {
            if ( (((unsigned __int64)v384 >> v541) & 1) != (unsigned __int64)v384 >> 63 )
              break;
            --v541;
          }
          while ( v541 );
          v542 = 62;
          do
          {
            if ( (((unsigned __int64)v537 >> v542) & 1) != (unsigned __int64)v537 >> 63 )
              break;
            --v542;
          }
          while ( v542 );
          v543 = v542 + v541;
          v544 = v542 + v541 - 61;
          if ( v543 <= 0x3D )
          {
            v545 = v537 * v384;
            LOBYTE(v544) = 0;
LABEL_1002:
            v545 >>= 32 - (unsigned __int8)v544;
            goto LABEL_1003;
          }
          v545 = (v384 >> ((v544 >> 1) + (v544 & 1))) * (v537 >> (v544 >> 1));
          if ( v544 >= 0x21 )
          {
            v545 <<= (unsigned __int8)v543 - 93;
            goto LABEL_1003;
          }
          if ( v544 != 32 )
            goto LABEL_1002;
LABEL_1003:
          v546 = 0xFFFFFFFF00000001LL;
          v547 = HIDWORD(v545);
          if ( v545 >= 0 )
            v546 = 0xFFFFFFFFLL;
          v548 = (v546 + v545) >> 32;
          if ( !v545 )
            LODWORD(v548) = 0;
          v15 = (v545 & 0xFFFC0000) == 0;
          v549 = 62;
          if ( v15 )
            LODWORD(v548) = v547;
          v776 = v548 + v529;
          v550 = 8 * ((int)v548 + v529);
          do
          {
            if ( ((v550 >> v549) & 1) != v550 >> 63 )
              break;
            --v549;
          }
          while ( v549 );
          v551 = v549 - 30;
          v552 = 62;
          if ( (unsigned int)(62 - v549) >= 0x20 )
            v551 = 0;
          v553 = (__int64)(v550 << (62 - (unsigned __int8)v549)) / ((__int64)SLODWORD(s[10]) >> v551);
          v554 = 30 - v549;
          if ( (unsigned int)(62 - v549) <= 0x20 )
            v554 = 0;
          v555 = v553 >> v554;
          v556 = 0xFFFFFFFF00000001LL;
          v557 = v555 == 0;
          if ( v555 >= 0 )
            v556 = 0xFFFFFFFFLL;
          v558 = (v556 + v555) >> 32;
          if ( v557 )
            v559 = 0;
          else
            v559 = v558;
          if ( v559 >= 0 )
            v560 = (unsigned int)v559;
          else
            v560 = (unsigned int)-v559;
          v561 = v560 << 32;
          if ( v559 >= 0 )
            v562 = v561;
          else
            v562 = -v561;
          do
          {
            if ( (((unsigned __int64)v562 >> v552) & 1) != (unsigned __int64)v562 >> 63 )
              break;
            --v552;
          }
          while ( v552 );
          v563 = 62;
          do
          {
            if ( ((s[0] >> v563) & 1LL) != v148 )
              break;
            --v563;
          }
          while ( v563 );
          v564 = v563 + v552;
          v565 = v563 + v552 - 61;
          if ( v564 <= 0x3D )
          {
            v566 = v562 * s[0];
            LOBYTE(v565) = 0;
LABEL_1036:
            v566 >>= 32 - (unsigned __int8)v565;
            goto LABEL_1037;
          }
          v566 = (v562 >> ((v565 >> 1) + (v565 & 1))) * (s[0] >> (v565 >> 1));
          if ( v565 < 0x21 )
          {
            if ( v565 == 32 )
              goto LABEL_1037;
            goto LABEL_1036;
          }
          v566 <<= (unsigned __int8)v564 - 93;
LABEL_1037:
          v567 = 62;
          do
          {
            if ( (((unsigned __int64)v566 >> v567) & 1) != (unsigned __int64)v566 >> 63 )
              break;
            --v567;
          }
          while ( v567 );
          v568 = v567 - 30;
          v569 = (unsigned int)(62 - v567) > 0x20;
          if ( (unsigned int)(62 - v567) >= 0x20 )
            v568 = 0;
          v570 = (v566 << (62 - (unsigned __int8)v567)) / (s[2] >> v568);
          v571 = 30 - v567;
          v572 = 62;
          if ( !v569 )
            v571 = 0;
          v573 = v570 >> v571;
          v574 = 0xFFFFFFFF00000001LL;
          if ( v573 >= 0 )
            v574 = 0xFFFFFFFFLL;
          v575 = (v574 + v573) >> 32;
          if ( !v573 )
            LODWORD(v575) = 0;
          if ( (v573 & 0xFFFC0000) == 0 )
            LODWORD(v575) = HIDWORD(v573);
          v775 = v575;
          v576 = v790 - v394 + 1 + v781 + v575;
          if ( v576 >= 0 )
            v577 = (unsigned int)v576;
          else
            v577 = (unsigned int)-v576;
          v578 = v577 << 32;
          if ( v576 >= 0 )
            v579 = v578;
          else
            v579 = -v578;
          do
          {
            if ( ((v579 >> v572) & 1) != v579 >> 63 )
              break;
            --v572;
          }
          while ( v572 );
          v580 = v572 - 30;
          if ( (unsigned int)(62 - v572) >= 0x20 )
            v580 = 0;
          v581 = (__int64)(v579 << (62 - (unsigned __int8)v572)) / (s[0] >> v580);
          v582 = 30 - v572;
          if ( (unsigned int)(62 - v572) <= 0x20 )
            v582 = 0;
          v583 = v581 >> v582;
          if ( !LODWORD(s[13]) )
          {
            if ( v773 == v583 )
            {
              v589 = 1;
              goto LABEL_1158;
            }
            v619 = (unsigned __int64)v583 >> 63;
            v205 = v798;
            v621 = v785 >> 63;
            v620 = v785;
            if ( v770 > (unsigned __int64)v583 >> 63 )
              goto LABEL_1138;
            if ( v619 <= v770 )
            {
              if ( (v583 | v773) < 0 )
              {
                v655 = 0;
                while ( (((unsigned __int64)v773 >> ((unsigned __int8)v655 + 62)) & 1) == v770 )
                {
                  if ( --v655 == -62 )
                    goto LABEL_1294;
                }
                if ( (unsigned int)(v655 + 31) > 0xFFFFFFC1 )
                {
LABEL_1294:
                  v657 = v761;
                  v656 = 0;
LABEL_1295:
                  v657 >>= 32 - v656;
                  goto LABEL_1296;
                }
                v656 = v655 + 32;
                v657 = (v773 >> (((unsigned int)(v655 + 32) >> 1) + ((v655 + 62) & 1)))
                     * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v655 + 32) >> 1));
                if ( (unsigned int)(v655 + 32) >= 0x21 )
                {
                  v657 <<= v655;
                  goto LABEL_1296;
                }
                if ( (_DWORD)v655 )
                  goto LABEL_1295;
LABEL_1296:
                v658 = 0;
                v801 = v657;
                while ( (((unsigned __int64)v583 >> ((unsigned __int8)v658 + 62)) & 1) == v619 )
                {
                  if ( --v658 == -62 )
                    goto LABEL_1303;
                }
                if ( (unsigned int)(v658 + 31) >= 0xFFFFFFC2 )
                {
LABEL_1303:
                  v205 = v798;
                  v660 = 0xFFFFFFFF00000000LL * v583;
                  v659 = 0;
LABEL_1304:
                  v660 >>= 32 - v659;
                  goto LABEL_1305;
                }
                v659 = v658 + 32;
                v660 = (v583 >> (((unsigned int)(v658 + 32) >> 1) + ((v658 + 62) & 1)))
                     * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v658 + 32) >> 1));
                if ( (unsigned int)(v658 + 32) >= 0x21 )
                {
                  v660 <<= v658;
                  v621 = v785 >> 63;
                  v620 = v785;
                  v205 = v798;
                  goto LABEL_1306;
                }
                v205 = v798;
                if ( (_DWORD)v658 )
                  goto LABEL_1304;
LABEL_1305:
                v621 = v785 >> 63;
                v620 = v785;
LABEL_1306:
                if ( v801 <= v660 )
                  goto LABEL_1307;
              }
              else
              {
                v205 = v798;
                if ( v773 > v583 )
                  goto LABEL_1307;
              }
LABEL_1138:
              v800 = 0;
              goto LABEL_1160;
            }
LABEL_1307:
            v589 = 1;
            goto LABEL_1159;
          }
          v584 = 62;
          do
          {
            if ( (((unsigned __int64)v583 >> v584) & 1) != (unsigned __int64)v583 >> 63 )
              break;
            --v584;
          }
          while ( v584 );
          v585 = 62;
          do
          {
            if ( ((s[0] >> v585) & 1LL) != v148 )
              break;
            --v585;
          }
          while ( v585 );
          v586 = v585 + v584;
          v587 = v585 + v584 - 61;
          if ( v586 <= 0x3D )
          {
            v588 = v583 * s[0];
            LOBYTE(v587) = 0;
LABEL_1075:
            v588 >>= 32 - (unsigned __int8)v587;
            goto LABEL_1076;
          }
          v588 = (v583 >> ((v587 >> 1) + (v587 & 1))) * (s[0] >> (v587 >> 1));
          if ( v587 >= 0x21 )
          {
            v588 <<= (unsigned __int8)v586 - 93;
            goto LABEL_1076;
          }
          if ( v587 != 32 )
            goto LABEL_1075;
LABEL_1076:
          v590 = v588 == 0;
          v591 = 0xFFFFFFFF00000001LL;
          if ( v588 >= 0 )
            v591 = 0xFFFFFFFFLL;
          v592 = v394 * HIDWORD(s[9]) * v788;
          v593 = (v591 + v588) >> 32;
          if ( v590 )
            LODWORD(v593) = 0;
          HIDWORD(s[49]) = v593;
          if ( v802 < v788 )
            v592 = (v799 + v786 * v803) * HIDWORD(s[9]);
          LODWORD(v594) = v772 - (v592 + v395 * HIDWORD(s[9]) * v789);
          v595 = -32;
          v596 = (int)v594;
          if ( (v594 & 0x80000000) == 0LL )
            v594 = (int)v594;
          else
            v594 = -(__int64)(int)v594;
          v597 = v594 / v336;
          v598 = v594 % v336;
          do
          {
            v599 = 2 * v598;
            v26 = 2 * v598 >= v336;
            v600 = v26;
            if ( v26 )
              v601 = v336;
            else
              v601 = 0;
            v26 = __CFADD__(v595++, 1);
            v597 = v600 | (2 * v597);
            v598 = v599 - v601;
          }
          while ( !v26 );
          if ( v336 > 2 * v598 )
            v602 = v597;
          else
            v602 = v597 + 1;
          if ( (v596 ^ SHIDWORD(s[9])) >= 0 )
            v603 = v602;
          else
            v603 = -v602;
          v604 = 0xFFFFFFFF00000001LL;
          v605 = v603 == 0;
          if ( v603 >= 0 )
            v604 = 0xFFFFFFFFLL;
          v606 = (v604 + v603) >> 32;
          if ( v605 )
            LODWORD(v606) = 0;
          HIDWORD(s[52]) = v606;
          LODWORD(s[50]) = v606 + v787 * v790;
          HIDWORD(s[48]) = 5;
          v607 = v258 + 5 + v593 + LODWORD(s[50]);
          if ( LODWORD(s[12]) == 1 )
          {
            if ( v607 >= 0 )
              v608 = v607;
            else
              v608 = -v607;
            if ( HIDWORD(s[9]) == 1 )
            {
              v609 = v608 / 0x1F4uLL;
              v610 = v608 % 0x1F4;
              v611 = -32;
              do
              {
                v612 = (unsigned __int64)(2 * v610) > 0x1F3;
                if ( v612 )
                  v613 = -500;
                else
                  v613 = 0;
                v26 = __CFADD__(v611++, 1);
                v609 = v612 | (2 * v609);
                v610 = v613 + 2 * v610;
              }
              while ( !v26 );
              v614 = 0xFFFFFFFF00000001LL;
              if ( (unsigned __int64)(2 * v610) <= 0x1F3 )
                v615 = v609;
              else
                v615 = v609 + 1;
              if ( v607 < 0 )
                v615 = -v615;
              v616 = v615 == 0;
              if ( v615 >= 0 )
                v614 = 0xFFFFFFFFLL;
              v617 = (int)(12 * ((v614 + v615) >> 32));
            }
            else
            {
              v622 = v608 / 0xFAuLL;
              v623 = v608 % 0xFA;
              v624 = -32;
              do
              {
                v625 = (unsigned __int64)(2 * v623) > 0xF9;
                if ( v625 )
                  v626 = -250;
                else
                  v626 = 0;
                v26 = __CFADD__(v624++, 1);
                v622 = v625 | (2 * v622);
                v623 = v626 + 2 * v623;
              }
              while ( !v26 );
              v627 = 0xFFFFFFFF00000001LL;
              if ( (unsigned __int64)(2 * v623) <= 0xF9 )
                v628 = v622;
              else
                v628 = v622 + 1;
              if ( v607 < 0 )
                v628 = -v628;
              v616 = v628 == 0;
              if ( v628 >= 0 )
                v627 = 0xFFFFFFFFLL;
              v617 = (int)(6 * ((v627 + v628) >> 32));
            }
            v618 = 1;
            if ( !v616 )
              v618 = v617 + 1;
          }
          else
          {
            v618 = 0;
          }
          s[51] = v618;
          LODWORD(s[49]) = v607 + v618;
          v589 = v607 + (int)v618 + 1 <= (int)v771;
LABEL_1158:
          v621 = v785 >> 63;
          v620 = v785;
          v205 = v798;
LABEL_1159:
          v800 = v589;
LABEL_1160:
          v629 = (unsigned __int64)v476 >> 63;
          if ( v476 != v620 )
          {
            if ( v629 <= v621 )
            {
              if ( v621 <= v629 )
              {
                if ( (v476 | v620) < 0 )
                {
                  v637 = 0;
                  while ( (((unsigned __int64)v476 >> ((unsigned __int8)v637 + 62)) & 1) == v629 )
                  {
                    if ( --v637 == -62 )
                      goto LABEL_1236;
                  }
                  if ( (unsigned int)(v637 + 31) >= 0xFFFFFFC2 )
                  {
LABEL_1236:
                    v641 = 0xFFFFFFFF00000000LL * v476;
                    v640 = 0;
LABEL_1237:
                    v641 >>= 32 - v640;
                    goto LABEL_1238;
                  }
                  v640 = v637 + 32;
                  v641 = (v476 >> (((unsigned int)(v637 + 32) >> 1) + ((v637 + 62) & 1)))
                       * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v637 + 32) >> 1));
                  if ( (unsigned int)(v637 + 32) >= 0x21 )
                  {
                    v641 <<= v637;
                    goto LABEL_1238;
                  }
                  if ( (_DWORD)v637 )
                    goto LABEL_1237;
LABEL_1238:
                  v642 = 0;
                  v762 = v641;
                  while ( ((v785 >> ((unsigned __int8)v642 + 62)) & 1) == v785 >> 63 )
                  {
                    if ( --v642 == -62 )
                      goto LABEL_1254;
                  }
                  if ( (unsigned int)(v642 + 31) > 0xFFFFFFC1 )
                  {
LABEL_1254:
                    v647 = 0xFFFFFFFF00000000LL * v785;
                    v205 = v798;
                    v646 = 0;
LABEL_1255:
                    v647 >>= 32 - v646;
                    goto LABEL_1256;
                  }
                  v646 = v642 + 32;
                  v647 = ((__int64)v785 >> (((unsigned int)(v642 + 32) >> 1) + ((v642 + 62) & 1)))
                       * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v642 + 32) >> 1));
                  if ( (unsigned int)(v642 + 32) >= 0x21 )
                  {
                    v205 = v798;
                    v647 <<= v642;
                    goto LABEL_1256;
                  }
                  v205 = v798;
                  if ( (_DWORD)v642 )
                    goto LABEL_1255;
LABEL_1256:
                  v9 = v762 <= v647;
                  v621 = v785 >> 63;
                  v620 = v785;
                  if ( v9 )
                    v630 = 1;
                  else
                    v630 = 2;
                  if ( v476 != v205 )
                    goto LABEL_1166;
                }
                else
                {
                  if ( v476 > v620 )
                    v630 = 1;
                  else
                    v630 = 2;
                  if ( v476 != v205 )
                    goto LABEL_1166;
                }
              }
              else
              {
                v630 = 1;
                if ( v476 != v205 )
                  goto LABEL_1166;
              }
            }
            else
            {
              v630 = 2;
              if ( v476 != v205 )
                goto LABEL_1166;
            }
LABEL_1162:
            v631 = 0;
            if ( v794 )
              goto LABEL_1182;
            goto LABEL_1184;
          }
          v630 = 0;
          if ( v476 == v205 )
            goto LABEL_1162;
LABEL_1166:
          v632 = v205 >> 63;
          if ( v629 > v205 >> 63 )
          {
            v631 = 1;
            goto LABEL_1181;
          }
          if ( v632 > v629 )
          {
            v631 = 0;
            goto LABEL_1181;
          }
          if ( ((v476 | v205) & 0x8000000000000000LL) != 0 )
          {
            v638 = 0;
            while ( (((unsigned __int64)v476 >> ((unsigned __int8)v638 + 62)) & 1) == v629 )
            {
              if ( --v638 == -62 )
                goto LABEL_1245;
            }
            if ( (unsigned int)(v638 + 31) >= 0xFFFFFFC2 )
            {
LABEL_1245:
              v644 = 0xFFFFFFFF00000000LL * v476;
              v643 = 0;
LABEL_1246:
              v644 >>= 32 - v643;
              goto LABEL_1247;
            }
            v643 = v638 + 32;
            v644 = (v476 >> (((unsigned int)(v638 + 32) >> 1) + ((v638 + 62) & 1)))
                 * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v638 + 32) >> 1));
            if ( (unsigned int)(v638 + 32) >= 0x21 )
            {
              v644 <<= v638;
              goto LABEL_1247;
            }
            if ( (_DWORD)v638 )
              goto LABEL_1246;
LABEL_1247:
            v645 = 0;
            while ( (((unsigned __int64)v798 >> ((unsigned __int8)v645 + 62)) & 1) == v632 )
            {
              if ( --v645 == -62 )
                goto LABEL_1264;
            }
            if ( (unsigned int)(v645 + 31) >= 0xFFFFFFC2 )
            {
LABEL_1264:
              v649 = 0xFFFFFFFF00000000LL * v798;
              v648 = 0;
LABEL_1265:
              v649 >>= 32 - v648;
              goto LABEL_1266;
            }
            v648 = v645 + 32;
            v649 = (v798 >> (((unsigned int)(v645 + 32) >> 1) + ((v645 + 62) & 1)))
                 * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v645 + 32) >> 1));
            if ( (unsigned int)(v645 + 32) >= 0x21 )
            {
              v649 <<= v645;
              goto LABEL_1266;
            }
            if ( (_DWORD)v645 )
              goto LABEL_1265;
LABEL_1266:
            v9 = v644 <= v649;
            v621 = v785 >> 63;
            v620 = v785;
            v205 = v798;
            v631 = !v9;
            if ( v794 )
              goto LABEL_1182;
            goto LABEL_1184;
          }
          v631 = v476 <= (__int64)v205;
LABEL_1181:
          v621 = v785 >> 63;
          v620 = v785;
          if ( !v794 )
          {
LABEL_1184:
            if ( v791 < 0 )
              goto LABEL_1201;
            v633 = v630 == 2 || LODWORD(s[53]) == 1;
            v634 = !v631;
            v635 = v633;
            if ( v476 < 0 )
              v634 = 1;
            if ( (v634 & 1) != 0 || !v635 )
              goto LABEL_1201;
            v636 = v803 > 0 && v800;
            if ( v576 > 1023 || !v636 )
              goto LABEL_1201;
            v379 = v802;
            LODWORD(s[44]) = v382;
            v205 = v476;
            HIDWORD(s[20]) = v790;
            HIDWORD(s[43]) = v802;
            s[25] = v783;
            v765 = 1;
            v766 = 1;
            v763 = 1;
            v764 = 1;
            v774 = 1;
            v381 = v792;
            BYTE4(s[42]) = 1;
            HIDWORD(s[21]) = v394;
            LODWORD(s[46]) = 1;
            LODWORD(s[30]) = v576;
            goto LABEL_706;
          }
LABEL_1182:
          if ( !v774 && !HIDWORD(s[46]) )
            goto LABEL_1184;
LABEL_1201:
          if ( v476 == v620 )
          {
            v379 = v802;
            v381 = v792;
          }
          else
          {
            v381 = v792;
            if ( !v792 )
            {
              if ( v629 > v621 )
                goto LABEL_704;
              if ( v621 > v629 )
                goto LABEL_1286;
              if ( (v476 | v620) < 0 )
              {
                v639 = 0;
                while ( (((unsigned __int64)v476 >> ((unsigned __int8)v639 + 62)) & 1) == v629 )
                {
                  if ( --v639 == -62 )
                    goto LABEL_1274;
                }
                if ( (unsigned int)(v639 + 31) >= 0xFFFFFFC2 )
                {
LABEL_1274:
                  v651 = 0xFFFFFFFF00000000LL * v476;
                  v650 = 0;
LABEL_1275:
                  v651 >>= 32 - v650;
                  goto LABEL_1276;
                }
                v650 = v639 + 32;
                v651 = (v476 >> (((unsigned int)(v639 + 32) >> 1) + ((v639 + 62) & 1)))
                     * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v639 + 32) >> 1));
                if ( (unsigned int)(v639 + 32) >= 0x21 )
                {
                  v651 <<= v639;
                  goto LABEL_1276;
                }
                if ( (_DWORD)v639 )
                  goto LABEL_1275;
LABEL_1276:
                v652 = 0;
                while ( (((unsigned __int64)v620 >> ((unsigned __int8)v652 + 62)) & 1) == v621 )
                {
                  if ( --v652 == -62 )
                    goto LABEL_1283;
                }
                if ( (unsigned int)(v652 + 31) > 0xFFFFFFC1 )
                {
LABEL_1283:
                  v654 = 0xFFFFFFFF00000000LL * v785;
                  v205 = v798;
                  v653 = 0;
LABEL_1284:
                  v654 >>= 32 - v653;
                  goto LABEL_1285;
                }
                v653 = v652 + 32;
                v654 = (v620 >> (((unsigned int)(v652 + 32) >> 1) + ((v652 + 62) & 1)))
                     * ((__int64)0xFFFFFFFF00000000LL >> ((unsigned int)(v652 + 32) >> 1));
                if ( (unsigned int)(v652 + 32) >= 0x21 )
                {
                  v205 = v798;
                  v654 <<= v652;
                  goto LABEL_1285;
                }
                v205 = v798;
                if ( (_DWORD)v652 )
                  goto LABEL_1284;
LABEL_1285:
                if ( v651 > v654 )
                  goto LABEL_704;
LABEL_1286:
                v381 = 0;
              }
              else
              {
                if ( v476 > v620 )
                  goto LABEL_1286;
LABEL_704:
                v381 = 1;
                v767 = 1;
                v768 = 1;
                LODWORD(s[43]) = 1;
                v769 = 1;
              }
            }
            v379 = v802;
          }
LABEL_706:
          ++v382;
          v332 = HIDWORD(s[9]);
          if ( v382 != 16 )
            continue;
          break;
        }
        if ( ++v379 != 16 )
          continue;
        break;
      }
      v373 = v790 + 1;
      if ( v790 != 64 )
        continue;
      break;
    }
    v337 = v760 - 1;
    if ( (v764 & 1) == 0 )
    {
      v661 = v759;
      v334 = 0;
      v662 = v767 != 1 || v760 == 1;
      v335 = 1;
      if ( v662 )
        v661 = 1;
      if ( v661 != 1 )
        continue;
    }
    break;
  }
  s[33] = v408;
  StatusReg = v757;
  a2 = v758;
  LODWORD(s[42]) = v576;
  LODWORD(s[14]) = v781;
  HIDWORD(s[13]) = v760 - 1;
  LODWORD(s[35]) = v772;
  LODWORD(s[20]) = 65;
  *(_QWORD *)((char *)&s[44] + 4) = 0x1000000010LL;
  LODWORD(s[34]) = v394;
  s[37] = v777;
  s[36] = v437;
  s[27] = __PAIR64__(v788, v789);
  HIDWORD(s[34]) = v437 != 0;
  LODWORD(s[47]) = v794 == 0;
  s[26] = __PAIR64__(v787, v795);
  LODWORD(s[39]) = v793;
  s[23] = v461;
  if ( v786 <= 0 )
    v663 = v788;
  else
    v663 = 15;
  s[19] = v476;
  s[28] = __PAIR64__(v778, v663);
  s[17] = v205;
  HIDWORD(s[39]) = v559;
  s[24] = v783;
  s[18] = v791;
  HIDWORD(s[41]) = v790 - v394 + 1;
  LODWORD(s[41]) = v790 - v394;
  s[40] = __PAIR64__(v776, v775);
  HIDWORD(s[47]) = v800;
  if ( BYTE4(s[42]) != 1 )
    goto LABEL_1421;
  LODWORD(v664) = LODWORD(s[44]) + HIDWORD(s[43]);
  LODWORD(v665) = HIDWORD(s[21]) * HIDWORD(s[43]) + LODWORD(s[44]) * (HIDWORD(s[21]) - 1);
  v666 = (int)v665 < 0;
  if ( (int)v665 >= 0 )
    v665 = (unsigned int)v665;
  else
    v665 = (unsigned int)-(int)v665;
  v667 = v665 << 32;
  if ( v666 )
    v667 = -(__int64)v667;
  v668 = (int)v664 < 0;
  if ( (int)v664 >= 0 )
    v664 = (unsigned int)v664;
  else
    v664 = (unsigned int)-(int)v664;
  v669 = v664 << 32;
  if ( v668 )
    v670 = -v669;
  else
    v670 = v669;
  v671 = 62;
  do
  {
    if ( ((v667 >> v671) & 1) != v667 >> 63 )
      break;
    --v671;
  }
  while ( v671 );
  v672 = 62;
  v673 = v671 - 30;
  v674 = v667 << (62 - (unsigned __int8)v671);
  if ( (unsigned int)(62 - v671) >= 0x20 )
    v673 = 0;
  v675 = v674 / (v670 >> v673);
  if ( (unsigned int)(62 - v671) <= 0x20 )
    v676 = 0;
  else
    v676 = 30 - v671;
  if ( s[20] >= 0 )
    v677 = HIDWORD(s[20]);
  else
    v677 = (unsigned int)-HIDWORD(s[20]);
  v678 = v675 >> v676;
  v679 = v677 << 32;
  if ( s[20] < 0 )
    v679 = 0xFFFFFFFF00000000LL * v677;
  s[22] = v678;
  do
  {
    if ( ((s[16] >> v672) & 1LL) != s[16] >> 63 )
      break;
    --v672;
  }
  while ( v672 );
  v680 = 62;
  do
  {
    if ( ((v679 >> v680) & 1) != v679 >> 63 )
      break;
    --v680;
  }
  while ( v680 );
  v681 = v680 + v672;
  v682 = v681 - 61;
  if ( v681 <= 0x3D )
  {
    v683 = s[16] * v679;
    LOBYTE(v682) = 0;
    goto LABEL_1376;
  }
  v683 = (s[16] >> ((v682 >> 1) + (v682 & 1))) * ((__int64)v679 >> (v682 >> 1));
  if ( v682 < 0x21 )
  {
    if ( v681 == 93 )
      goto LABEL_1377;
LABEL_1376:
    v683 >>= 32 - (unsigned __int8)v682;
    goto LABEL_1377;
  }
  v683 <<= (unsigned __int8)v681 - 93;
LABEL_1377:
  s[32] = v683;
  HIDWORD(s[45]) = HIDWORD(s[21]) - 1;
  v684 = -32;
  if ( SLODWORD(s[10]) >= 0 )
    v685 = LODWORD(s[10]);
  else
    v685 = (unsigned int)-LODWORD(s[10]);
  v686 = v685 >> 3;
  v687 = v685 & 7;
  do
  {
    v688 = 2 * v687;
    if ( v688 <= 7 )
      v205 = 0;
    else
      v205 = -8;
    v26 = __CFADD__(v684++, 1);
    v686 = (v688 > 7) | (unsigned __int64)(2 * v686);
    v687 = v205 + v688;
  }
  while ( !v26 );
  if ( (v687 & 0x7FFFFFFFFFFFFFFCLL) != 0 )
    ++v686;
  if ( SLODWORD(s[10]) >= 0 )
    v689 = v686;
  else
    v689 = -v686;
  v690 = 62;
  do
  {
    if ( ((s[5] >> v690) & 1LL) != s[5] >> 63 )
      break;
    --v690;
  }
  while ( v690 );
  v691 = 62;
  do
  {
    if ( (((unsigned __int64)v689 >> v691) & 1) != (unsigned __int64)v689 >> 63 )
      break;
    --v691;
  }
  while ( v691 );
  v692 = v691 + v690;
  v693 = v692 - 61;
  if ( v692 <= 0x3D )
  {
    v694 = s[5] * v689;
    LOBYTE(v693) = 0;
    goto LABEL_1402;
  }
  v694 = (s[5] >> ((v693 >> 1) + (v693 & 1))) * (v689 >> (v693 >> 1));
  if ( v693 < 0x21 )
  {
    if ( v692 == 93 )
      goto LABEL_1403;
LABEL_1402:
    v694 >>= 32 - (unsigned __int8)v693;
    goto LABEL_1403;
  }
  v694 <<= (unsigned __int8)v692 - 93;
LABEL_1403:
  v695 = 62;
  do
  {
    if ( (((unsigned __int64)v694 >> v695) & 1) != (unsigned __int64)v694 >> 63 )
      break;
    --v695;
  }
  while ( v695 );
  v696 = 62;
  v697 = v695 - 30;
  v698 = (unsigned int)(62 - v695) > 0x20;
  v699 = v694 << (62 - (unsigned __int8)v695);
  if ( (unsigned int)(62 - v695) >= 0x20 )
    v697 = 0;
  v700 = v699 / (v678 >> v697);
  v701 = 30 - v695;
  if ( !v698 )
    v701 = 0;
  LODWORD(s[46]) = 1;
  v702 = v700 >> v701;
  if ( s[20] >= 0 )
    v703 = v677 << 32;
  else
    v703 = 0xFFFFFFFF00000000LL * v677;
  LODWORD(s[21]) = HIDWORD(s[20]) - 1;
  LODWORD(s[26]) = HIDWORD(v702);
  do
  {
    if ( (((unsigned __int64)v678 >> v696) & 1) != (unsigned __int64)v678 >> 63 )
      break;
    --v696;
  }
  while ( v696 );
  v704 = v696 - 30;
  v705 = v678 << (62 - (unsigned __int8)v696);
  if ( (unsigned int)(62 - v696) >= 0x20 )
    v704 = 0;
  v706 = v705 / (v703 >> v704);
  v707 = 30 - v696;
  if ( (unsigned int)(62 - v696) <= 0x20 )
    v707 = 0;
  s[38] = (v706 >> v707) - s[16];
LABEL_1421:
  if ( !HIDWORD(s[11]) )
  {
    v708 = s[30];
    goto LABEL_1487;
  }
  v709 = 62;
  do
  {
    if ( ((s[5] >> v709) & 1LL) != s[5] >> 63 )
      break;
    --v709;
  }
  while ( v709 );
  if ( (unsigned int)(v709 - 41) >= 0xFFFFFFC2 )
  {
    v711 = 2576980LL * s[5];
    v710 = 0;
LABEL_1430:
    v711 >>= 32 - v710;
    goto LABEL_1431;
  }
  v710 = v709 - 40;
  v711 = (0x275254uLL >> (((unsigned int)(v709 - 40) >> 1) + (v709 & 1))) * (s[5] >> ((unsigned int)(v709 - 40) >> 1));
  if ( (unsigned int)(v709 - 40) >= 0x21 )
  {
    v711 <<= (unsigned __int8)v709 - 72;
    goto LABEL_1431;
  }
  if ( (_DWORD)v709 != 72 )
    goto LABEL_1430;
LABEL_1431:
  v712 = v711 == 0;
  v713 = 0xFFFFFFFF00000001LL;
  v714 = 62;
  if ( v711 >= 0 )
    v713 = 0xFFFFFFFFLL;
  v715 = (__int64)(v713 + v711) >> 32;
  if ( v712 )
    v715 = 0;
  if ( s[9] >= 0 )
    v716 = HIDWORD(s[9]);
  else
    v716 = (unsigned int)-HIDWORD(s[9]);
  v717 = v716 << 32;
  if ( s[9] < 0 )
    v717 = -v717;
  do
  {
    if ( ((s[16] >> v714) & 1LL) != s[16] >> 63 )
      break;
    --v714;
  }
  while ( v714 );
  v718 = 62;
  do
  {
    if ( (((unsigned __int64)v717 >> v718) & 1) != (unsigned __int64)v717 >> 63 )
      break;
    --v718;
  }
  while ( v718 );
  v719 = v718 + v714;
  v720 = v719 - 61;
  if ( v719 <= 0x3D )
  {
    v721 = s[16] * v717;
    LOBYTE(v720) = 0;
LABEL_1449:
    v721 >>= 32 - (unsigned __int8)v720;
    goto LABEL_1450;
  }
  v721 = (s[16] >> ((v720 >> 1) + (v720 & 1))) * (v717 >> (v720 >> 1));
  if ( v720 < 0x21 )
  {
    if ( v719 == 93 )
      goto LABEL_1450;
    goto LABEL_1449;
  }
  v721 <<= (unsigned __int8)v719 - 93;
LABEL_1450:
  if ( SLODWORD(s[10]) >= 0 )
    v722 = LODWORD(s[10]);
  else
    v722 = (unsigned int)-LODWORD(s[10]);
  v723 = v722 >> 3;
  v724 = v722 & 7;
  v725 = -32;
  do
  {
    v726 = 2 * v724;
    if ( v726 <= 7 )
      v727 = 0;
    else
      v727 = -8;
    v26 = __CFADD__(v725++, 1);
    v723 = (v726 > 7) | (2 * v723);
    v724 = v727 + v726;
  }
  while ( !v26 );
  v728 = 62;
  if ( (v724 & 0x7FFFFFFFFFFFFFFCLL) != 0 )
    ++v723;
  if ( SLODWORD(s[10]) < 0 )
    v723 = -(__int64)v723;
  do
  {
    if ( ((v723 >> v728) & 1) != v723 >> 63 )
      break;
    --v728;
  }
  while ( v728 );
  v729 = 62;
  v730 = v728 - 30;
  v731 = v723 << (62 - (unsigned __int8)v728);
  if ( (unsigned int)(62 - v728) >= 0x20 )
    v730 = 0;
  v732 = v731 / (v721 >> v730);
  if ( (unsigned int)(62 - v728) <= 0x20 )
    v733 = 0;
  else
    v733 = 30 - v728;
  v734 = v715 < 0;
  if ( v715 < 0 )
    v715 = -v715;
  v735 = v715 << 32;
  if ( v734 )
    v736 = -v735;
  else
    v736 = v735;
  v737 = v732 >> v733;
  do
  {
    if ( (((unsigned __int64)v736 >> v729) & 1) != (unsigned __int64)v736 >> 63 )
      break;
    --v729;
  }
  while ( v729 );
  v738 = 62;
  do
  {
    if ( (((unsigned __int64)v737 >> v738) & 1) != (unsigned __int64)v737 >> 63 )
      break;
    --v738;
  }
  while ( v738 );
  v739 = v738 + v729;
  v740 = v739 - 61;
  if ( v739 <= 0x3D )
  {
    v741 = v736 * v737;
    LOBYTE(v740) = 0;
LABEL_1485:
    v741 >>= 32 - (unsigned __int8)v740;
    goto LABEL_1486;
  }
  v741 = (v736 >> ((v740 >> 1) + (v740 & 1))) * (v737 >> (v740 >> 1));
  if ( v740 < 0x21 )
  {
    if ( v739 == 93 )
      goto LABEL_1486;
    goto LABEL_1485;
  }
  v741 <<= (unsigned __int8)v739 - 93;
LABEL_1486:
  v708 = LODWORD(s[30]) + HIDWORD(v741);
  LODWORD(s[30]) += HIDWORD(v741);
LABEL_1487:
  if ( v708 >= 0 )
    v742 = (unsigned int)v708;
  else
    v742 = (unsigned int)-v708;
  v743 = v742 << 32;
  if ( v708 >= 0 )
    v744 = v743;
  else
    v744 = -v743;
  v745 = 62;
  do
  {
    if ( ((v744 >> v745) & 1) != v744 >> 63 )
      break;
    --v745;
  }
  while ( v745 );
  v746 = v745 - 30;
  v747 = (unsigned int)(62 - v745) > 0x20;
  v748 = v744 << (62 - (unsigned __int8)v745);
  if ( (unsigned int)(62 - v745) >= 0x20 )
    v746 = 0;
  v749 = 30 - v745;
  v750 = s[0] >> v746;
  if ( !v747 )
    v749 = 0;
  v751 = BYTE4(s[42]);
  *(_DWORD *)(a2 + 24) = s[21];
  v752 = v748 / v750;
  v753 = HIDWORD(s[21]);
  *(_BYTE *)(a2 + 8) = v751;
  *(_DWORD *)a2 = v753;
  *(_DWORD *)(a2 + 4) = v708;
  v754 = *(_QWORD *)((char *)&s[43] + 4);
  *(_DWORD *)(a2 + 12) = HIDWORD(s[45]);
  *(_QWORD *)(a2 + 16) = v754;
  s[54] = v752 >> v749;
  v755 = get_ipc_log_context(v205);
  ipc_log_string(
    v755,
    "[i][%-4d]TU: %d %d %d %d %d %d %d\n",
    *(_DWORD *)(StatusReg + 1800),
    *(_DWORD *)a2,
    *(_DWORD *)(a2 + 4),
    *(unsigned __int8 *)(a2 + 8),
    *(_DWORD *)(a2 + 12),
    *(_DWORD *)(a2 + 16),
    *(_DWORD *)(a2 + 20),
    *(_DWORD *)(a2 + 24));
  if ( (_drm_debug & 4) != 0 )
    result = printk(&unk_2483A8, *(unsigned int *)(StatusReg + 1800));
  else
    result = printk(&unk_25988B, "dp_tu_calculate");
  _ReadStatusReg(SP_EL0);
  return result;
}
