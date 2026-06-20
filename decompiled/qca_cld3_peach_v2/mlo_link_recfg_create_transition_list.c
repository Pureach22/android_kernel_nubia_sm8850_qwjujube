__int64 __fastcall mlo_link_recfg_create_transition_list(
        __int64 a1,
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
  unsigned __int8 *v10; // x25
  _QWORD *v11; // x20
  __int64 v12; // x5
  __int64 v13; // x4
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x23
  __int64 v23; // x9
  int v24; // w11
  int v25; // w21
  int v26; // w8
  int v27; // w19
  int v28; // w22
  int v29; // w26
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int v38; // w24
  __int64 v39; // x4
  __int64 v40; // x5
  __int64 v41; // x6
  __int64 v42; // x7
  __int64 v43; // x9
  int v44; // w11
  __int64 v45; // x4
  __int64 v46; // x5
  __int64 v47; // x6
  __int64 v48; // x7
  __int64 v49; // x9
  int v50; // w11
  __int64 v51; // x4
  __int64 v52; // x5
  __int64 v53; // x6
  __int64 v54; // x7
  __int64 v55; // x4
  __int64 v56; // x8
  int v57; // w9
  int v58; // w10
  char *v59; // x11
  __int64 v60; // x13
  char v61; // w14
  char v62; // t1
  unsigned __int8 *v63; // x9
  __int64 v64; // x8
  char *v65; // x9
  char v66; // t1
  __int64 v67; // x27
  __int64 v68; // x8
  int v69; // w9
  int v70; // w10
  char *v71; // x11
  __int64 v72; // x13
  char v73; // w14
  char v74; // t1
  unsigned __int8 *v75; // x9
  __int64 v76; // x8
  char *v77; // x9
  char v78; // t1
  __int64 v79; // x22
  __int64 v80; // x0
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  __int64 v89; // x21
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int *v98; // x8
  double v99; // d0
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  unsigned __int8 *v107; // x27
  __int64 v108; // x10
  __int64 v109; // x28
  int v110; // w9
  char v111; // w27
  unsigned int v112; // w26
  __int64 v113; // x25
  int *v114; // x20
  __int64 v115; // x1
  __int64 v116; // x0
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  __int64 v125; // x21
  bool is_vdev_disconnected; // w22
  unsigned int *v127; // x8
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  int v136; // w10
  unsigned __int8 *v137; // x8
  int v138; // w9
  __int64 v139; // x4
  __int64 v140; // x5
  __int64 v141; // x6
  __int64 v142; // x7
  double v143; // d0
  double v144; // d1
  double v145; // d2
  double v146; // d3
  double v147; // d4
  double v148; // d5
  double v149; // d6
  double v150; // d7
  unsigned __int8 *v151; // x28
  int v152; // w1
  unsigned __int8 *v153; // x27
  unsigned __int8 *v154; // x20
  __int64 v155; // x0
  double v156; // d0
  double v157; // d1
  double v158; // d2
  double v159; // d3
  double v160; // d4
  double v161; // d5
  double v162; // d6
  double v163; // d7
  __int64 v164; // x21
  bool is_vdev_connected; // w22
  unsigned int *v166; // x8
  double v167; // d0
  double v168; // d1
  double v169; // d2
  double v170; // d3
  double v171; // d4
  double v172; // d5
  double v173; // d6
  double v174; // d7
  unsigned int *v175; // x22
  int v176; // w19
  const char *v177; // x2
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  int v186; // w1
  __int64 v187; // x20
  __int64 v188; // x0
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  __int64 v197; // x21
  bool v198; // w22
  unsigned int *v199; // x8
  double v200; // d0
  double v201; // d1
  double v202; // d2
  double v203; // d3
  double v204; // d4
  double v205; // d5
  double v206; // d6
  double v207; // d7
  int v208; // w1
  __int64 v209; // x20
  __int64 v210; // x0
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  __int64 v219; // x21
  bool v220; // w22
  unsigned int *v221; // x8
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  int v230; // w9
  __int64 v231; // x4
  __int64 v232; // x5
  double v233; // d0
  double v234; // d1
  double v235; // d2
  double v236; // d3
  double v237; // d4
  double v238; // d5
  double v239; // d6
  double v240; // d7
  __int64 v241; // x4
  __int64 v242; // x5
  __int64 v243; // x6
  __int64 v244; // x7
  char v245; // w22
  __int64 i; // x27
  __int64 v247; // x25
  int *v248; // x20
  __int64 v249; // x1
  __int64 v250; // x0
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  __int64 v259; // x21
  bool v260; // w28
  unsigned int *v261; // x8
  double v262; // d0
  double v263; // d1
  double v264; // d2
  double v265; // d3
  double v266; // d4
  double v267; // d5
  double v268; // d6
  double v269; // d7
  __int64 v270; // x21
  int v271; // w10
  unsigned __int8 *v272; // x8
  int v273; // w9
  __int64 v274; // x4
  __int64 v275; // x5
  __int64 v276; // x6
  __int64 v277; // x7
  __int64 v278; // x25
  double v279; // d0
  double v280; // d1
  double v281; // d2
  double v282; // d3
  double v283; // d4
  double v284; // d5
  double v285; // d6
  double v286; // d7
  int v287; // w9
  int v288; // w20
  char v289; // w19
  __int64 v290; // x27
  unsigned int v291; // w5
  __int64 v292; // x25
  __int64 v293; // x20
  __int64 v294; // x28
  int v295; // w8
  unsigned __int8 *v296; // x8
  int v297; // w11
  int v298; // w9
  __int64 v299; // x4
  __int64 v300; // x5
  __int64 v301; // x6
  __int64 v302; // x7
  double v303; // d0
  double v304; // d1
  double v305; // d2
  double v306; // d3
  double v307; // d4
  double v308; // d5
  double v309; // d6
  double v310; // d7
  const char *v311; // x2
  __int64 v312; // x4
  unsigned int state; // w21
  double v314; // d0
  double v315; // d1
  double v316; // d2
  double v317; // d3
  double v318; // d4
  double v319; // d5
  double v320; // d6
  double v321; // d7
  int v322; // w8
  unsigned int v323; // w21
  unsigned int v324; // w26
  _QWORD *v325; // x19
  __int64 v326; // x8
  __int64 v327; // x10
  __int64 v328; // x11
  __int64 v329; // x8
  __int64 v330; // x10
  __int64 v331; // x11
  __int64 v332; // x8
  __int64 v333; // x10
  __int64 v334; // x11
  __int64 v335; // x8
  __int64 v336; // x9
  __int64 v337; // x10
  __int64 v338; // x11
  __int64 v339; // x9
  __int64 v340; // x10
  __int64 v341; // x11
  __int64 v342; // x9
  __int64 v343; // x10
  __int64 v344; // x11
  __int64 v345; // x9
  __int64 v346; // x10
  __int64 v347; // x11
  __int64 v348; // x8
  __int64 v349; // x9
  __int64 v350; // x10
  __int64 v351; // x11
  __int64 v352; // x9
  __int64 v353; // x10
  __int64 v354; // x11
  __int64 v355; // x9
  __int64 v356; // x10
  __int64 v357; // x11
  __int64 v358; // x9
  __int64 v359; // x10
  __int64 v360; // x11
  __int64 v361; // x9
  __int64 v362; // x10
  __int64 v363; // x11
  __int64 v364; // x9
  __int64 v365; // x10
  __int64 v366; // x11
  __int64 v367; // x9
  __int64 v368; // x10
  __int64 v369; // x11
  __int64 v370; // x9
  __int64 v371; // x10
  __int64 v372; // x11
  __int64 v373; // x9
  __int64 v374; // x10
  __int64 v375; // x11
  unsigned int v376; // w0
  __int64 v377; // x9
  __int64 v378; // x10
  __int64 v379; // x11
  __int64 v380; // x9
  __int64 v381; // x10
  __int64 v382; // x11
  __int64 v383; // x9
  __int64 v384; // x10
  __int64 v385; // x11
  __int64 v386; // x9
  __int64 v387; // x10
  __int64 v388; // x11
  __int64 v389; // x9
  __int64 v390; // x10
  __int64 v391; // x11
  __int64 v392; // x9
  __int64 v393; // x10
  __int64 v394; // x11
  __int64 v395; // x9
  __int64 v396; // x10
  __int64 v397; // x11
  __int64 v398; // x9
  __int64 v399; // x10
  __int64 v400; // x11
  __int64 v401; // x9
  __int64 v402; // x10
  __int64 v403; // x11
  __int64 v404; // x9
  __int64 v405; // x10
  __int64 v406; // x11
  __int64 v407; // x9
  __int64 v408; // x10
  __int64 v409; // x11
  __int64 v410; // x8
  __int64 v411; // x9
  __int64 v412; // x10
  __int64 v413; // x11
  char v414; // w9
  __int64 v415; // x9
  __int64 v416; // x10
  __int64 v417; // x11
  __int64 v418; // x9
  __int64 v419; // x10
  __int64 v420; // x11
  __int64 v421; // x9
  __int64 v422; // x10
  __int64 v423; // x11
  __int64 v424; // x8
  __int64 v425; // x9
  __int64 v426; // x10
  __int64 v427; // x11
  __int64 v428; // x9
  __int64 v429; // x10
  __int64 v430; // x11
  __int64 v431; // x9
  __int64 v432; // x10
  __int64 v433; // x11
  __int64 v434; // x9
  __int64 v435; // x10
  __int64 v436; // x11
  __int64 v437; // x8
  __int64 v438; // x9
  __int64 v439; // x10
  __int64 v440; // x11
  __int64 v441; // x9
  __int64 v442; // x10
  __int64 v443; // x11
  __int64 v444; // x9
  __int64 v445; // x10
  __int64 v446; // x11
  __int64 v447; // x9
  __int64 v448; // x10
  __int64 v449; // x11
  __int64 v450; // x9
  __int64 v451; // x10
  __int64 v452; // x11
  __int64 v453; // x9
  __int64 v454; // x10
  __int64 v455; // x11
  __int64 v456; // x9
  __int64 v457; // x10
  __int64 v458; // x11
  __int64 v459; // x9
  __int64 v460; // x10
  __int64 v461; // x11
  __int64 v462; // x9
  __int64 v463; // x10
  __int64 v464; // x11
  __int64 v465; // x9
  __int64 v466; // x10
  __int64 v467; // x11
  __int64 v468; // x9
  __int64 v469; // x10
  __int64 v470; // x11
  __int64 v471; // x9
  __int64 v472; // x10
  __int64 v473; // x11
  __int64 v474; // x8
  __int64 v475; // x9
  __int64 v476; // x10
  __int64 v477; // x11
  __int64 v478; // x9
  __int64 v479; // x10
  __int64 v480; // x11
  __int64 v481; // x9
  __int64 v482; // x10
  __int64 v483; // x11
  __int64 v484; // x9
  __int64 v485; // x10
  __int64 v486; // x11
  __int64 v487; // x9
  __int64 v488; // x10
  __int64 v489; // x11
  __int64 v490; // x9
  __int64 v491; // x10
  __int64 v492; // x11
  __int64 v493; // x9
  __int64 v494; // x10
  __int64 v495; // x11
  __int64 v496; // x9
  __int64 v497; // x10
  __int64 v498; // x11
  __int64 v499; // x8
  __int64 v500; // x9
  __int64 v501; // x10
  __int64 v502; // x11
  __int64 v503; // x9
  __int64 v504; // x10
  __int64 v505; // x11
  __int64 v506; // x9
  __int64 v507; // x10
  __int64 v508; // x11
  __int64 v509; // x9
  __int64 v510; // x10
  __int64 v511; // x11
  __int64 v512; // x9
  __int64 v513; // x10
  __int64 v514; // x11
  double v515; // d0
  double v516; // d1
  double v517; // d2
  double v518; // d3
  double v519; // d4
  double v520; // d5
  double v521; // d6
  double v522; // d7
  unsigned int v523; // w24
  __int64 v524; // x9
  __int64 v525; // x10
  __int64 v526; // x11
  __int64 v527; // x9
  __int64 v528; // x10
  __int64 v529; // x11
  __int64 v530; // x9
  __int64 v531; // x10
  __int64 v532; // x11
  __int64 v533; // x8
  __int64 v534; // x9
  __int64 v535; // x10
  __int64 v536; // x11
  unsigned int v537; // w0
  _QWORD *v538; // x22
  __int64 v539; // x9
  __int64 v540; // x10
  __int64 v541; // x11
  __int64 v542; // x9
  __int64 v543; // x10
  __int64 v544; // x11
  __int64 v545; // x9
  __int64 v546; // x10
  __int64 v547; // x11
  __int64 v548; // x8
  __int64 v549; // x9
  __int64 v550; // x10
  __int64 v551; // x11
  __int64 v552; // x9
  __int64 v553; // x10
  __int64 v554; // x11
  __int64 v555; // x9
  __int64 v556; // x10
  __int64 v557; // x11
  __int64 v558; // x9
  __int64 v559; // x10
  __int64 v560; // x11
  __int64 v561; // x9
  __int64 v562; // x10
  __int64 v563; // x11
  __int64 v564; // x9
  __int64 v565; // x10
  __int64 v566; // x11
  __int64 v567; // x9
  __int64 v568; // x10
  __int64 v569; // x11
  __int64 v570; // x9
  __int64 v571; // x10
  __int64 v572; // x11
  __int64 v573; // x8
  __int64 v574; // x9
  __int64 v575; // x10
  __int64 v576; // x11
  __int64 v577; // x9
  __int64 v578; // x10
  __int64 v579; // x11
  __int64 v580; // x9
  __int64 v581; // x10
  __int64 v582; // x11
  __int64 v583; // x9
  __int64 v584; // x10
  __int64 v585; // x11
  __int64 v586; // x8
  __int64 v587; // x9
  __int64 v588; // x10
  __int64 v589; // x11
  __int64 v590; // x9
  __int64 v591; // x10
  __int64 v592; // x11
  __int64 v593; // x9
  __int64 v594; // x10
  __int64 v595; // x11
  __int64 v596; // x9
  __int64 v597; // x10
  __int64 v598; // x11
  __int64 v599; // x8
  __int64 v600; // x9
  __int64 v601; // x10
  __int64 v602; // x11
  __int64 v603; // x8
  __int64 v604; // x10
  __int64 v605; // x11
  __int64 v606; // x8
  __int64 v607; // x10
  __int64 v608; // x11
  __int64 v609; // x8
  __int64 v610; // x10
  __int64 v611; // x11
  __int64 v612; // x8
  __int64 v613; // x9
  __int64 v614; // x10
  __int64 v615; // x11
  __int64 v616; // x9
  __int64 v617; // x10
  __int64 v618; // x11
  __int64 v619; // x9
  __int64 v620; // x10
  __int64 v621; // x11
  __int64 v622; // x9
  __int64 v623; // x10
  __int64 v624; // x11
  __int64 v625; // x9
  __int64 v626; // x10
  __int64 v627; // x11
  __int64 v628; // x9
  __int64 v629; // x10
  __int64 v630; // x11
  __int64 v631; // x9
  __int64 v632; // x10
  __int64 v633; // x11
  __int64 v634; // x9
  __int64 v635; // x10
  __int64 v636; // x11
  __int64 v637; // x9
  __int64 v638; // x10
  __int64 v639; // x11
  __int64 v640; // x9
  __int64 v641; // x10
  __int64 v642; // x11
  __int64 v643; // x9
  __int64 v644; // x10
  __int64 v645; // x11
  __int64 v646; // x9
  __int64 v647; // x10
  __int64 v648; // x11
  __int64 v649; // x8
  __int64 v650; // x9
  __int64 v651; // x10
  __int64 v652; // x11
  __int64 v653; // x9
  __int64 v654; // x10
  __int64 v655; // x11
  __int64 v656; // x9
  __int64 v657; // x10
  __int64 v658; // x11
  __int64 v659; // x9
  __int64 v660; // x10
  __int64 v661; // x11
  __int64 v662; // x9
  __int64 v663; // x10
  __int64 v664; // x11
  __int64 v665; // x9
  __int64 v666; // x10
  __int64 v667; // x11
  __int64 v668; // x9
  __int64 v669; // x10
  __int64 v670; // x11
  __int64 v671; // x9
  __int64 v672; // x10
  __int64 v673; // x11
  __int64 v674; // x8
  __int64 v675; // x9
  __int64 v676; // x10
  __int64 v677; // x11
  __int64 v678; // x9
  __int64 v679; // x10
  __int64 v680; // x11
  __int64 v681; // x9
  __int64 v682; // x10
  __int64 v683; // x11
  __int64 v684; // x9
  __int64 v685; // x10
  __int64 v686; // x11
  __int64 v687; // x9
  __int64 v688; // x10
  __int64 v689; // x11
  __int64 v690; // x9
  __int64 v691; // x10
  __int64 v692; // x11
  __int64 v693; // x9
  __int64 v694; // x10
  __int64 v695; // x11
  __int64 v696; // x9
  __int64 v697; // x10
  __int64 v698; // x11
  __int64 v699; // x9
  __int64 v700; // x10
  __int64 v701; // x11
  __int64 v702; // x9
  __int64 v703; // x10
  __int64 v704; // x11
  __int64 v705; // x9
  __int64 v706; // x10
  __int64 v707; // x11
  __int64 v708; // x9
  __int64 v709; // x10
  __int64 v710; // x11
  __int64 v711; // x8
  __int64 v712; // x9
  __int64 v713; // x10
  __int64 v714; // x11
  __int64 v715; // x9
  __int64 v716; // x10
  __int64 v717; // x11
  __int64 v718; // x9
  __int64 v719; // x10
  __int64 v720; // x11
  __int64 v721; // x9
  __int64 v722; // x10
  __int64 v723; // x11
  __int64 v724; // x9
  __int64 v725; // x10
  __int64 v726; // x11
  __int64 v727; // x9
  __int64 v728; // x10
  __int64 v729; // x11
  __int64 v730; // x8
  __int64 v731; // x10
  __int64 v732; // x11
  __int64 v733; // x8
  __int64 v734; // x10
  __int64 v735; // x11
  __int64 v736; // x8
  __int64 v737; // x10
  __int64 v738; // x11
  __int64 v739; // x11
  __int64 v740; // x9
  __int64 v741; // x10
  __int64 v742; // x8
  __int64 v743; // x10
  __int64 v744; // x11
  __int64 v745; // x8
  __int64 v746; // x10
  __int64 v747; // x11
  __int64 v748; // x8
  __int64 v749; // x10
  __int64 v750; // x11
  __int64 v751; // x9
  __int64 v752; // x10
  __int64 v753; // x11
  __int64 v754; // x9
  __int64 v755; // x10
  __int64 v756; // x11
  __int64 v757; // x9
  __int64 v758; // x10
  __int64 v759; // x11
  __int64 v760; // x8
  __int64 v761; // x9
  __int64 v762; // x10
  __int64 v763; // x11
  __int64 v764; // x10
  __int64 v765; // x9
  __int64 v766; // x11
  __int64 v767; // x10
  __int64 v768; // x9
  __int64 v769; // x11
  __int64 v770; // x10
  __int64 v771; // x9
  __int64 v772; // x11
  __int64 v773; // x8
  __int64 v774; // x10
  __int64 v775; // x9
  __int64 v776; // x11
  __int64 v777; // x9
  __int64 v778; // x10
  __int64 v779; // x11
  __int64 v780; // x9
  __int64 v781; // x10
  __int64 v782; // x11
  __int64 v783; // x9
  __int64 v784; // x10
  __int64 v785; // x11
  __int64 v786; // x9
  __int64 v787; // x10
  __int64 v788; // x11
  __int64 v789; // x9
  __int64 v790; // x8
  __int64 v791; // x9
  __int64 v792; // x8
  __int64 v793; // x9
  __int64 v794; // x8
  __int64 v795; // x9
  __int64 v796; // x8
  __int64 v797; // x9
  __int64 v798; // x8
  __int64 v799; // x9
  __int64 v800; // x8
  __int64 v801; // x9
  __int64 v802; // x8
  __int64 v803; // x9
  __int64 v804; // x8
  __int64 v805; // x9
  __int64 v806; // x9
  __int64 v807; // x8
  __int64 v808; // x9
  __int64 v809; // x8
  __int64 v810; // x9
  __int64 v811; // x8
  __int64 v812; // x9
  __int64 v813; // x8
  __int64 v814; // x9
  __int64 v815; // x8
  __int64 v816; // x9
  __int64 v817; // x8
  __int64 v818; // x9
  __int64 v819; // x8
  __int64 v820; // x9
  __int64 v821; // x8
  __int64 v822; // x9
  __int64 v823; // x9
  __int64 v824; // x8
  __int64 v825; // x9
  __int64 v826; // x8
  __int64 v827; // x9
  __int64 v828; // x8
  __int64 v829; // x9
  __int64 v830; // x8
  __int64 v831; // x9
  __int64 v832; // x8
  __int64 v833; // x9
  __int64 v834; // x8
  __int64 v835; // x8
  __int64 v836; // x8
  __int64 v837; // x1
  __int64 v839; // x9
  __int64 v840; // x10
  __int64 v841; // x11
  __int64 v842; // x9
  __int64 v843; // x10
  __int64 v844; // x11
  __int64 v845; // x9
  __int64 v846; // x10
  __int64 v847; // x11
  __int64 v848; // x9
  __int64 v849; // x10
  __int64 v850; // x11
  __int64 v851; // x9
  __int64 v852; // x10
  __int64 v853; // x11
  __int64 v854; // x9
  __int64 v855; // x10
  __int64 v856; // x11
  __int64 v857; // x9
  __int64 v858; // x10
  __int64 v859; // x11
  __int64 v860; // x9
  __int64 v861; // x10
  __int64 v862; // x11
  double v863; // d0
  double v864; // d1
  double v865; // d2
  double v866; // d3
  double v867; // d4
  double v868; // d5
  double v869; // d6
  double v870; // d7
  double v871; // d0
  double v872; // d1
  double v873; // d2
  double v874; // d3
  double v875; // d4
  double v876; // d5
  double v877; // d6
  double v878; // d7
  __int64 v879; // [xsp+0h] [xbp-A0h]
  __int64 v880; // [xsp+8h] [xbp-98h]
  __int64 v881; // [xsp+10h] [xbp-90h]
  __int64 v882; // [xsp+18h] [xbp-88h]
  _QWORD *v883; // [xsp+20h] [xbp-80h]
  unsigned int v884; // [xsp+2Ch] [xbp-74h]
  unsigned int v885; // [xsp+30h] [xbp-70h]
  unsigned int v886; // [xsp+3Ch] [xbp-64h]
  unsigned int v887; // [xsp+40h] [xbp-60h]
  char v888; // [xsp+44h] [xbp-5Ch]
  unsigned __int8 *v889; // [xsp+48h] [xbp-58h]
  __int64 v890; // [xsp+50h] [xbp-50h]
  __int64 v891; // [xsp+58h] [xbp-48h]
  unsigned __int8 *v892; // [xsp+60h] [xbp-40h]
  int v893; // [xsp+68h] [xbp-38h]
  int v894; // [xsp+68h] [xbp-38h]
  int v895; // [xsp+68h] [xbp-38h]
  int v896; // [xsp+68h] [xbp-38h]
  unsigned int v897; // [xsp+6Ch] [xbp-34h] BYREF
  __int64 v898; // [xsp+70h] [xbp-30h] BYREF
  __int64 v899; // [xsp+78h] [xbp-28h]
  __int16 v900; // [xsp+80h] [xbp-20h]
  __int64 v901; // [xsp+98h] [xbp-8h]

  v10 = a2;
  v11 = (_QWORD *)a1;
  v901 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_DWORD *)(a1 + 3464) = 0;
  v12 = *(unsigned __int8 *)(a1 + 3248);
  v13 = a2[264];
  v897 = 0;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: is_user_req %d xmit num frms %d",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "mlo_link_recfg_create_transition_list",
    v13,
    v12);
  v10[558] = *((unsigned __int8 *)v11 + 3248) > 1u;
  v22 = v11[1];
  *((_BYTE *)v11 + 3248) = 0;
  if ( !v22 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: mlo_ctx null",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "mlo_link_recfg_get_link_bitmap");
    v29 = 0;
    v885 = 0;
    v38 = 0;
    v27 = 0;
    goto LABEL_58;
  }
  v23 = *(_QWORD *)(v22 + 3880);
  if ( !(*(_DWORD *)(v23 + 24) | *(unsigned __int16 *)(v23 + 28)) )
    goto LABEL_13;
  v24 = *(unsigned __int8 *)(v23 + 6);
  if ( v24 == 255 )
    goto LABEL_13;
  if ( (*(_QWORD *)(v23 + 16) & 1) != 0 )
  {
    if ( v23 == -24 )
    {
      v41 = 0;
      v39 = 0;
      v40 = 0;
      v42 = 0;
    }
    else
    {
      v39 = *(unsigned __int8 *)(v23 + 24);
      v40 = *(unsigned __int8 *)(v23 + 25);
      v41 = *(unsigned __int8 *)(v23 + 26);
      v42 = *(unsigned __int8 *)(v23 + 29);
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: skip del ap link addr: %02x:%02x:%02x:**:**:%02x link flag 0x%x",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "mlo_link_recfg_get_link_bitmap",
      v39,
      v40,
      v41,
      v42,
      *(_QWORD *)(v23 + 16));
LABEL_13:
    v27 = 0;
    v25 = 0;
    v28 = 0;
    v29 = 0;
    goto LABEL_14;
  }
  v25 = 1;
  v26 = *(unsigned __int8 *)(v23 + 12);
  v27 = 1 << v24;
  v28 = v26 == 255;
  if ( v26 == 255 )
    v29 = 1 << v24;
  else
    v29 = 0;
LABEL_14:
  v43 = *(_QWORD *)(v22 + 3880);
  if ( *(_DWORD *)(v43 + 72) | *(unsigned __int16 *)(v43 + 76) )
  {
    v44 = *(unsigned __int8 *)(v43 + 54);
    if ( v44 != 255 )
    {
      if ( (*(_QWORD *)(v43 + 64) & 1) != 0 )
      {
        if ( v43 == -72 )
        {
          v47 = 0;
          v45 = 0;
          v46 = 0;
          v48 = 0;
        }
        else
        {
          v45 = *(unsigned __int8 *)(v43 + 72);
          v46 = *(unsigned __int8 *)(v43 + 73);
          v47 = *(unsigned __int8 *)(v43 + 74);
          v48 = *(unsigned __int8 *)(v43 + 77);
        }
        LODWORD(v879) = *(_QWORD *)(v43 + 64);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: skip del ap link addr: %02x:%02x:%02x:**:**:%02x link flag 0x%x",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "mlo_link_recfg_get_link_bitmap",
          v45,
          v46,
          v47,
          v48,
          v879);
      }
      else
      {
        ++v25;
        v27 |= 1 << v44;
        if ( *(unsigned __int8 *)(v43 + 60) == 255 )
        {
          v29 |= 1 << v44;
          ++v28;
        }
      }
    }
  }
  v49 = *(_QWORD *)(v22 + 3880);
  if ( *(_DWORD *)(v49 + 120) | *(unsigned __int16 *)(v49 + 124) )
  {
    v50 = *(unsigned __int8 *)(v49 + 102);
    if ( v50 != 255 )
    {
      if ( (*(_QWORD *)(v49 + 112) & 1) != 0 )
      {
        if ( v49 == -120 )
        {
          v53 = 0;
          v51 = 0;
          v52 = 0;
          v54 = 0;
        }
        else
        {
          v51 = *(unsigned __int8 *)(v49 + 120);
          v52 = *(unsigned __int8 *)(v49 + 121);
          v53 = *(unsigned __int8 *)(v49 + 122);
          v54 = *(unsigned __int8 *)(v49 + 125);
        }
        LODWORD(v879) = *(_QWORD *)(v49 + 112);
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: skip del ap link addr: %02x:%02x:%02x:**:**:%02x link flag 0x%x",
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          "mlo_link_recfg_get_link_bitmap",
          v51,
          v52,
          v53,
          v54,
          v879);
      }
      else
      {
        ++v25;
        v27 |= 1 << v50;
        if ( *(unsigned __int8 *)(v49 + 108) == 255 )
        {
          v29 |= 1 << v50;
          ++v28;
        }
      }
    }
  }
  v55 = v10[128];
  if ( !v10[128] )
  {
    v38 = 0;
    goto LABEL_41;
  }
  if ( (_DWORD)v55 == 1 )
  {
    v38 = 0;
    v56 = 0;
LABEL_39:
    v63 = &v10[40 * (unsigned int)v56];
    v64 = v55 - v56;
    v65 = (char *)(v63 + 9);
    do
    {
      v66 = *v65;
      v65 += 40;
      --v64;
      v38 |= 1 << v66;
    }
    while ( v64 );
    goto LABEL_41;
  }
  v56 = (unsigned __int8)v55 & 0xFE;
  v57 = 0;
  v58 = 0;
  v59 = (char *)(v10 + 49);
  v60 = v56;
  do
  {
    v61 = *(v59 - 40);
    v62 = *v59;
    v59 += 80;
    v60 -= 2;
    v57 |= 1 << v61;
    v58 |= 1 << v62;
  }
  while ( v60 );
  v38 = v58 | v57;
  if ( v56 != v55 )
    goto LABEL_39;
LABEL_41:
  v67 = v10[256];
  if ( !v10[256] )
  {
    LODWORD(v22) = 0;
    goto LABEL_50;
  }
  if ( (_DWORD)v67 == 1 )
  {
    LODWORD(v22) = 0;
    v68 = 0;
LABEL_48:
    v75 = &v10[40 * (unsigned int)v68];
    v76 = v67 - v68;
    v77 = (char *)(v75 + 137);
    do
    {
      v78 = *v77;
      v77 += 40;
      --v76;
      LODWORD(v22) = (1 << v78) | v22;
    }
    while ( v76 );
    goto LABEL_50;
  }
  v68 = (unsigned __int8)v67 & 0xFE;
  v69 = 0;
  v70 = 0;
  v71 = (char *)(v10 + 177);
  v72 = v68;
  do
  {
    v73 = *(v71 - 40);
    v74 = *v71;
    v71 += 80;
    v72 -= 2;
    v69 |= 1 << v73;
    v70 |= 1 << v74;
  }
  while ( v72 );
  LODWORD(v22) = v70 | v69;
  if ( v68 != v67 )
    goto LABEL_48;
LABEL_50:
  LODWORD(v879) = v25;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: add link num %d bitmap 0x%x del num %d bitmap 0x%x curr num %d bitmap 0x%x standby %d 0x%x",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "mlo_link_recfg_get_link_bitmap",
    v879,
    v27,
    v28,
    v29);
  v900 = 0;
  v898 = 0;
  v899 = 0;
  v885 = v67;
  if ( (_DWORD)v22 )
  {
    v79 = *v11;
    if ( !*v11 )
    {
      qdf_trace_msg(0x8Fu, 2u, "%s: psoc null", v30, v31, v32, v33, v34, v35, v36, v37, "mlo_link_recfg_xmit_req_first");
      goto LABEL_56;
    }
    v80 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(*v11, *v10, 108);
    if ( v80 )
    {
      v89 = v80;
      ml_nlink_get_curr_force_state(v81, v82, v83, v84, v85, v86, v87, v88, v79, v80, &v898);
      LODWORD(v882) = v22;
      LODWORD(v881) = WORD2(v899);
      LODWORD(v880) = HIWORD(v898);
      LODWORD(v879) = BYTE4(v898);
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: inactive 0x%x active 0x%x inact num %d 0x%x act num %d 0x%x dyn 0x%xdel_link_set 0x%x",
        v90,
        v91,
        v92,
        v93,
        v94,
        v95,
        v96,
        v97,
        "mlo_link_recfg_xmit_req_first",
        WORD1(v898),
        (unsigned __int16)v898,
        (unsigned __int8)v899,
        WORD1(v899),
        v879,
        v880,
        v881,
        v882);
      wlan_objmgr_vdev_release_ref(v89, 0x6Cu, v98, v99, v100, v101, v102, v103, v104, v105, v106);
      if ( (v27 & ~WORD1(v898) & ~(_DWORD)v22) == 0 )
      {
        qdf_trace_msg(
          0x8Fu,
          8u,
          "%s: xmit_first xmit_link 0x%x",
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          "mlo_link_recfg_xmit_req_first");
LABEL_56:
        v888 = 0;
        goto LABEL_59;
      }
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: invalid vdev for id %d",
        v81,
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        "mlo_link_recfg_xmit_req_first",
        *v10);
    }
  }
LABEL_58:
  v888 = 1;
LABEL_59:
  v107 = v10 + 8;
  if ( !v10[128] )
  {
    v884 = v29;
    v886 = 0;
    v887 = v27;
    goto LABEL_155;
  }
  v108 = v11[1];
  if ( !v108 )
  {
    v177 = "%s: mlo_ctx null";
LABEL_90:
    qdf_trace_msg(0x8Fu, 2u, v177, v30, v31, v32, v33, v34, v35, v36, v37, "mlo_link_recfg_assign_self_link_addr");
LABEL_154:
    v311 = "%s: fail to ssign self link for added links status %d";
    v312 = 4;
    state = 4;
LABEL_192:
    qdf_trace_msg(
      0x8Fu,
      2u,
      v311,
      v178,
      v179,
      v180,
      v181,
      v182,
      v183,
      v184,
      v185,
      "mlo_link_recfg_create_transition_list",
      v312);
    goto LABEL_193;
  }
  v890 = *v11;
  if ( !*v11 )
  {
    v177 = "%s: psoc null";
    goto LABEL_90;
  }
  v884 = v29;
  v109 = 0;
  v110 = 0;
  v889 = v10 + 8;
  v111 = 0;
  v112 = 0;
  v887 = v27;
  v883 = v11;
  v891 = v11[1];
  v892 = v10;
  do
  {
    if ( v112 >= v10[128] )
      break;
    if ( (v110 & (1 << v111)) == 0 )
    {
      v113 = *(_QWORD *)(v108 + 3880);
      v114 = (int *)(v113 + v109);
      v115 = *(unsigned __int8 *)(v113 + v109 + 12);
      if ( (_DWORD)v115 == 255 )
      {
        v10 = v892;
      }
      else
      {
        v893 = v110;
        v116 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                 v890,
                 v115,
                 108);
        if ( v116 )
        {
          v125 = v116;
          is_vdev_disconnected = cm_is_vdev_disconnected(v116, v117, v118, v119, v120, v121, v122, v123, v124);
          wlan_objmgr_vdev_release_ref(v125, 0x6Cu, v127, v128, v129, v130, v131, v132, v133, v134, v135);
          if ( is_vdev_disconnected
            && (!(*(_DWORD *)(v113 + v109 + 24) | *(unsigned __int16 *)(v113 + v109 + 28))
             || *(unsigned __int8 *)(v113 + v109 + 6) == 255) )
          {
            v136 = *v114;
            v137 = &v889[40 * v112];
            *((_WORD *)v137 + 9) = *((_WORD *)v114 + 2);
            *(_DWORD *)(v137 + 14) = v136;
            v138 = *((unsigned __int8 *)v114 + 12);
            *v137 = v138;
            if ( v114 )
            {
              v139 = *(unsigned __int8 *)(v113 + v109);
              v140 = *(unsigned __int8 *)(v113 + v109 + 1);
              v141 = *(unsigned __int8 *)(v113 + v109 + 2);
              v142 = *(unsigned __int8 *)(v113 + v109 + 5);
            }
            else
            {
              v141 = 0;
              v139 = 0;
              v140 = 0;
              v142 = 0;
            }
            LODWORD(v881) = v138;
            LODWORD(v880) = *((_DWORD *)v137 + 1);
            LODWORD(v879) = v137[1];
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: assign idle self link addr: %02x:%02x:%02x:**:**:%02x for add link %d freq %d vdev %d",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "mlo_link_recfg_assign_self_link_addr",
              v139,
              v140,
              v141,
              v142,
              v879,
              v880,
              v881);
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: old link id %d flag 0x%x on vdev %d ",
              v143,
              v144,
              v145,
              v146,
              v147,
              v148,
              v149,
              v150,
              "mlo_link_recfg_assign_self_link_addr",
              *(unsigned __int8 *)(v113 + v109 + 6),
              *(unsigned int *)(v113 + v109 + 16),
              *((unsigned __int8 *)v114 + 12));
            v108 = v891;
            v10 = v892;
            ++v112;
            v110 = v893 | (1 << v111);
          }
          else
          {
            v108 = v891;
            v10 = v892;
            v110 = v893;
          }
        }
        else
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Invalid VDEV id %d",
            v117,
            v118,
            v119,
            v120,
            v121,
            v122,
            v123,
            v124,
            "mlo_link_recfg_assign_self_link_addr",
            *((unsigned __int8 *)v114 + 12));
          v108 = v891;
          v10 = v892;
          v110 = v893;
        }
      }
    }
    v109 += 48;
    ++v111;
  }
  while ( v109 != 144 );
  if ( v112 >= v10[128] )
    goto LABEL_113;
  v151 = &v889[40 * v112];
  v152 = *v151;
  if ( v152 == 255 )
    goto LABEL_113;
  if ( (v110 & 1) != 0 )
    goto LABEL_92;
  v153 = *(unsigned __int8 **)(v108 + 3880);
  v154 = v153 + 12;
  if ( v153[12] != v152 )
    goto LABEL_92;
  v894 = v110;
  v155 = ((__int64 (__fastcall *)(__int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v890);
  if ( !v155 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Invalid VDEV id %d",
      v156,
      v157,
      v158,
      v159,
      v160,
      v161,
      v162,
      v163,
      "mlo_link_recfg_assign_self_link_addr",
      *v154);
    v108 = v891;
    v110 = v894;
    goto LABEL_92;
  }
  v164 = v155;
  is_vdev_connected = cm_is_vdev_connected(v155, v156, v157, v158, v159, v160, v161, v162, v163);
  wlan_objmgr_vdev_release_ref(v164, 0x5Au, v166, v167, v168, v169, v170, v171, v172, v173, v174);
  v108 = v891;
  v110 = v894;
  if ( !is_vdev_connected
    || (v175 = (unsigned int *)(v153 + 16), (*((_QWORD *)v153 + 2) & 1) == 0)
    && (((unsigned int)v22 >> v153[6]) & 1) == 0 )
  {
LABEL_92:
    if ( v112 < v10[128] )
    {
      v186 = *v151;
      if ( v186 != 255 )
      {
        if ( (v110 & 2) == 0 )
        {
          v187 = *(_QWORD *)(v108 + 3880);
          if ( *(unsigned __int8 *)(v187 + 60) == v186 )
          {
            v894 = v110;
            v188 = ((__int64 (__fastcall *)(__int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v890);
            if ( v188 )
            {
              v197 = v188;
              v198 = cm_is_vdev_connected(v188, v189, v190, v191, v192, v193, v194, v195, v196);
              wlan_objmgr_vdev_release_ref(v197, 0x5Au, v199, v200, v201, v202, v203, v204, v205, v206, v207);
              v108 = v891;
              v110 = v894;
              if ( v198 )
              {
                v153 = (unsigned __int8 *)(v187 + 48);
                v175 = (unsigned int *)(v187 + 64);
                if ( (*(_QWORD *)(v187 + 64) & 1) != 0 || (((unsigned int)v22 >> *(_BYTE *)(v187 + 54)) & 1) != 0 )
                {
                  v154 = (unsigned __int8 *)(v187 + 60);
                  v176 = 2;
                  goto LABEL_111;
                }
              }
            }
            else
            {
              qdf_trace_msg(
                0x8Fu,
                2u,
                "%s: Invalid VDEV id %d",
                v189,
                v190,
                v191,
                v192,
                v193,
                v194,
                v195,
                v196,
                "mlo_link_recfg_assign_self_link_addr",
                *(unsigned __int8 *)(v187 + 60));
              v108 = v891;
              v110 = v894;
            }
          }
        }
        if ( v112 < v10[128] )
        {
          v208 = *v151;
          if ( v208 != 255 && (v110 & 4) == 0 )
          {
            v209 = *(_QWORD *)(v108 + 3880);
            if ( *(unsigned __int8 *)(v209 + 108) == v208 )
            {
              v894 = v110;
              v210 = ((__int64 (__fastcall *)(__int64))wlan_objmgr_get_vdev_by_id_from_psoc)(v890);
              if ( v210 )
              {
                v219 = v210;
                v220 = cm_is_vdev_connected(v210, v211, v212, v213, v214, v215, v216, v217, v218);
                wlan_objmgr_vdev_release_ref(v219, 0x5Au, v221, v222, v223, v224, v225, v226, v227, v228, v229);
                if ( v220 )
                {
                  v153 = (unsigned __int8 *)(v209 + 96);
                  v175 = (unsigned int *)(v209 + 112);
                  if ( (*(_QWORD *)(v209 + 112) & 1) != 0 || (((unsigned int)v22 >> *(_BYTE *)(v209 + 102)) & 1) != 0 )
                  {
                    v154 = (unsigned __int8 *)(v209 + 108);
                    v176 = 4;
                    goto LABEL_111;
                  }
                }
              }
              else
              {
                qdf_trace_msg(
                  0x8Fu,
                  2u,
                  "%s: Invalid VDEV id %d",
                  v211,
                  v212,
                  v213,
                  v214,
                  v215,
                  v216,
                  v217,
                  v218,
                  "mlo_link_recfg_assign_self_link_addr",
                  *(unsigned __int8 *)(v209 + 108));
              }
              v108 = v891;
              v110 = v894;
              v886 = 0;
              goto LABEL_114;
            }
          }
        }
      }
    }
LABEL_113:
    v886 = 0;
    goto LABEL_114;
  }
  v176 = 1;
LABEL_111:
  v230 = *(_DWORD *)v153;
  v231 = *v151;
  v232 = v151[1];
  *((_WORD *)v151 + 9) = *((_WORD *)v153 + 2);
  *(_DWORD *)(v151 + 14) = v230;
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: fw preferred vdev %d for add link %d",
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    "mlo_link_recfg_assign_self_link_addr",
    v231,
    v232);
  if ( v153 )
  {
    v241 = *v153;
    v242 = v153[1];
    v243 = v153[2];
    v244 = v153[5];
  }
  else
  {
    v243 = 0;
    v241 = 0;
    v242 = 0;
    v244 = 0;
  }
  LODWORD(v881) = *v154;
  LODWORD(v880) = *((_DWORD *)v151 + 1);
  LODWORD(v879) = v151[1];
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: assign active self link addr: %02x:%02x:%02x:**:**:%02x for add link %d freq %d vdev %d",
    v233,
    v234,
    v235,
    v236,
    v237,
    v238,
    v239,
    v240,
    "mlo_link_recfg_assign_self_link_addr",
    v241,
    v242,
    v243,
    v244,
    v879,
    v880,
    v881);
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: old link id %d flag 0x%x on vdev %d ",
    v863,
    v864,
    v865,
    v866,
    v867,
    v868,
    v869,
    v870,
    "mlo_link_recfg_assign_self_link_addr",
    v153[6],
    *v175,
    *v154);
  v886 = 1 << v153[6];
  qdf_trace_msg(
    0x8Fu,
    8u,
    "%s: select link %d to delete first if no common link",
    v871,
    v872,
    v873,
    v874,
    v875,
    v876,
    v877,
    v878,
    "mlo_link_recfg_assign_self_link_addr");
  v108 = v891;
  ++v112;
  v110 = v176 | v894;
LABEL_114:
  v245 = 0;
  for ( i = 0; i != 144; i += 48 )
  {
    if ( v112 >= v10[128] )
      break;
    if ( (v110 & (1 << v245)) == 0 )
    {
      v247 = *(_QWORD *)(v108 + 3880);
      v248 = (int *)(v247 + i);
      v249 = *(unsigned __int8 *)(v247 + i + 12);
      if ( (_DWORD)v249 == 255 )
      {
        v10 = v892;
      }
      else
      {
        v895 = v110;
        v250 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
                 v890,
                 v249,
                 108);
        if ( v250 )
        {
          v259 = v250;
          v260 = cm_is_vdev_connected(v250, v251, v252, v253, v254, v255, v256, v257, v258);
          wlan_objmgr_vdev_release_ref(v259, 0x6Cu, v261, v262, v263, v264, v265, v266, v267, v268, v269);
          if ( v260
            && ((v270 = v247 + i, (*(_QWORD *)(v247 + i + 16) & 1) != 0)
             || (((unsigned int)v22 >> *(_BYTE *)(v270 + 6)) & 1) != 0) )
          {
            v271 = *v248;
            v272 = &v889[40 * v112];
            *((_WORD *)v272 + 9) = *((_WORD *)v248 + 2);
            *(_DWORD *)(v272 + 14) = v271;
            v273 = *((unsigned __int8 *)v248 + 12);
            *v272 = v273;
            if ( v248 )
            {
              v274 = *(unsigned __int8 *)(v247 + i);
              v275 = *(unsigned __int8 *)(v247 + i + 1);
              v276 = *(unsigned __int8 *)(v247 + i + 2);
              v277 = *(unsigned __int8 *)(v247 + i + 5);
            }
            else
            {
              v276 = 0;
              v274 = 0;
              v275 = 0;
              v277 = 0;
            }
            LODWORD(v881) = v273;
            LODWORD(v880) = *((_DWORD *)v272 + 1);
            LODWORD(v879) = v272[1];
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: assign active self link addr: %02x:%02x:%02x:**:**:%02x for add link %d freq %d vdev %d",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "mlo_link_recfg_assign_self_link_addr",
              v274,
              v275,
              v276,
              v277,
              v879,
              v880,
              v881);
            v278 = v247 + i;
            qdf_trace_msg(
              0x8Fu,
              8u,
              "%s: old link id %d flag 0x%x on vdev %d ",
              v279,
              v280,
              v281,
              v282,
              v283,
              v284,
              v285,
              v286,
              "mlo_link_recfg_assign_self_link_addr",
              *(unsigned __int8 *)(v278 + 6),
              *(unsigned int *)(v270 + 16),
              *((unsigned __int8 *)v248 + 12));
            if ( (*(_QWORD *)(v270 + 16) & 1) != 0 )
            {
              v108 = v891;
              v10 = v892;
              v287 = v895;
            }
            else
            {
              v108 = v891;
              v287 = v895;
              v288 = 1 << *(_BYTE *)(v278 + 6);
              if ( (v288 & (unsigned int)v22) != 0 )
              {
                v10 = v892;
                if ( !v886 )
                {
                  qdf_trace_msg(
                    0x8Fu,
                    8u,
                    "%s: select link %d to delete first if no common link",
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    v37,
                    "mlo_link_recfg_assign_self_link_addr");
                  v287 = v895;
                  v108 = v891;
                  v886 = v288;
                }
              }
              else
              {
                v10 = v892;
              }
            }
            ++v112;
            v110 = v287 | (1 << v245);
          }
          else
          {
            v108 = v891;
            v10 = v892;
            v110 = v895;
          }
        }
        else
        {
          qdf_trace_msg(
            0x8Fu,
            2u,
            "%s: Invalid VDEV id %d",
            v251,
            v252,
            v253,
            v254,
            v255,
            v256,
            v257,
            v258,
            "mlo_link_recfg_assign_self_link_addr",
            *((unsigned __int8 *)v248 + 12));
          v108 = v891;
          v10 = v892;
          v110 = v895;
        }
      }
    }
    ++v245;
  }
  v289 = 0;
  v290 = 24;
  v897 = v886;
  while ( 1 )
  {
    v291 = v10[128];
    if ( v112 >= v291 )
      break;
    if ( (v110 & (1 << v289)) == 0 )
    {
      v292 = *(_QWORD *)(v108 + 3880);
      v293 = v292 + v290;
      if ( *(unsigned __int8 *)(v292 + v290 - 12) == 255 )
      {
        v896 = v110;
        v294 = v292 + v290;
        if ( (*(_QWORD *)(v292 + v290 - 8) & 1) != 0
          || !(*(_DWORD *)v294 | *(unsigned __int16 *)(v294 + 4))
          || (v295 = *(unsigned __int8 *)(v292 + v290 - 18), v295 == 255)
          || (((unsigned int)v22 >> v295) & 1) != 0 )
        {
          v296 = &v889[40 * v112];
          v297 = *(_DWORD *)(v293 - 24);
          *((_WORD *)v296 + 9) = *(_WORD *)(v293 - 20);
          *(_DWORD *)(v296 + 14) = v297;
          v298 = *(unsigned __int8 *)(v293 - 12);
          *v296 = v298;
          if ( v293 == 24 )
          {
            v301 = 0;
            v299 = 0;
            v300 = 0;
            v302 = 0;
          }
          else
          {
            v299 = *(unsigned __int8 *)(v293 - 24);
            v300 = *(unsigned __int8 *)(v292 + v290 - 23);
            v301 = *(unsigned __int8 *)(v292 + v290 - 22);
            v302 = *(unsigned __int8 *)(v292 + v290 - 19);
          }
          LODWORD(v881) = v298;
          LODWORD(v880) = *((_DWORD *)v296 + 1);
          LODWORD(v879) = v296[1];
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: assign standby self link addr: %02x:%02x:%02x:**:**:%02x for add link %d freq %d vdev %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "mlo_link_recfg_assign_self_link_addr",
            v299,
            v300,
            v301,
            v302,
            v879,
            v880,
            v881);
          qdf_trace_msg(
            0x8Fu,
            8u,
            "%s: old link id %d flag 0x%x on vdev %d ",
            v303,
            v304,
            v305,
            v306,
            v307,
            v308,
            v309,
            v310,
            "mlo_link_recfg_assign_self_link_addr",
            *(unsigned __int8 *)(v292 + v290 - 18),
            *(unsigned int *)(v294 - 8),
            *(unsigned __int8 *)(v293 - 12));
          v108 = v891;
          v10 = v892;
          ++v112;
          v110 = v896 | (1 << v289);
        }
        else
        {
          v10 = v892;
        }
      }
      else
      {
        v10 = v892;
      }
    }
    v290 += 48;
    ++v289;
    if ( v290 == 168 )
    {
      v291 = v10[128];
      break;
    }
  }
  v11 = v883;
  v107 = v889;
  if ( v112 < v291 )
  {
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: assign num %d, can't assign self mac for all added links, total %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "mlo_link_recfg_assign_self_link_addr",
      v112);
    goto LABEL_154;
  }
LABEL_155:
  *((_BYTE *)v11 + 3024) = -1;
  *((_BYTE *)v11 + 3208) = -1;
  *(_DWORD *)((char *)v11 + 3209) = 0;
  *(_WORD *)((char *)v11 + 3213) = 0;
  qdf_mem_set(v11 + 105, 0x888u, 0);
  v322 = v10[128];
  *((_DWORD *)v10 + 67) = 0;
  v10[272] = -1;
  if ( v322 )
  {
    v323 = v887;
    if ( v10[256] )
      goto LABEL_157;
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: add link only",
      v314,
      v315,
      v316,
      v317,
      v318,
      v319,
      v320,
      v321,
      "mlo_link_recfg_create_transition_list");
    v11[105] = 0x1300000007LL;
    v465 = *((_QWORD *)v107 + 2);
    v466 = *(_QWORD *)v107;
    v467 = *((_QWORD *)v107 + 1);
    v11[125] = *((_QWORD *)v107 + 3);
    v11[124] = v465;
    v11[123] = v467;
    v11[122] = v466;
    v468 = *((_QWORD *)v107 + 6);
    v469 = *((_QWORD *)v107 + 4);
    v470 = *((_QWORD *)v107 + 5);
    v11[129] = *((_QWORD *)v107 + 7);
    v11[128] = v468;
    v11[127] = v470;
    v11[126] = v469;
    v471 = *((_QWORD *)v107 + 10);
    v472 = *((_QWORD *)v107 + 8);
    v473 = *((_QWORD *)v107 + 9);
    v11[133] = *((_QWORD *)v107 + 11);
    v11[132] = v471;
    v11[131] = v473;
    v11[130] = v472;
    v475 = *((_QWORD *)v107 + 14);
    v474 = *((_QWORD *)v107 + 15);
    v476 = *((_QWORD *)v107 + 12);
    v477 = *((_QWORD *)v107 + 13);
    v11[139] = 0;
    v11[137] = v474;
    v11[136] = v475;
    v11[135] = v477;
    v11[134] = v476;
    *((_DWORD *)v10 + 67) = 2;
    v11[144] = 0x600000003LL;
    v478 = *((_QWORD *)v107 + 2);
    v479 = *(_QWORD *)v107;
    v480 = *((_QWORD *)v107 + 1);
    v11[148] = *((_QWORD *)v107 + 3);
    v11[147] = v478;
    v11[146] = v480;
    v11[145] = v479;
    v481 = *((_QWORD *)v107 + 6);
    v482 = *((_QWORD *)v107 + 4);
    v483 = *((_QWORD *)v107 + 5);
    v11[152] = *((_QWORD *)v107 + 7);
    v11[151] = v481;
    v11[150] = v483;
    v11[149] = v482;
    v484 = *((_QWORD *)v107 + 10);
    v485 = *((_QWORD *)v107 + 8);
    v486 = *((_QWORD *)v107 + 9);
    v11[156] = *((_QWORD *)v107 + 11);
    v11[155] = v484;
    v11[154] = v486;
    v11[153] = v485;
    v487 = *((_QWORD *)v107 + 14);
    v488 = *((_QWORD *)v107 + 12);
    v489 = *((_QWORD *)v107 + 13);
    v11[160] = *((_QWORD *)v107 + 15);
    v11[159] = v487;
    v11[158] = v489;
    v11[157] = v488;
    v376 = mlo_link_recfg_set_tx_link_addr(v11, v11 + 145, v887);
    if ( v376 )
      goto LABEL_185;
    v11[178] = 0;
    v11[183] = 0x500000004LL;
    v490 = *((_QWORD *)v107 + 2);
    v491 = *(_QWORD *)v107;
    v492 = *((_QWORD *)v107 + 1);
    v11[187] = *((_QWORD *)v107 + 3);
    v11[186] = v490;
    v11[185] = v492;
    v11[184] = v491;
    v493 = *((_QWORD *)v107 + 6);
    v494 = *((_QWORD *)v107 + 4);
    v495 = *((_QWORD *)v107 + 5);
    v11[191] = *((_QWORD *)v107 + 7);
    v11[190] = v493;
    v11[189] = v495;
    v11[188] = v494;
    v496 = *((_QWORD *)v107 + 10);
    v497 = *((_QWORD *)v107 + 8);
    v498 = *((_QWORD *)v107 + 9);
    v11[195] = *((_QWORD *)v107 + 11);
    v11[194] = v496;
    v11[193] = v498;
    v11[192] = v497;
    v500 = *((_QWORD *)v107 + 14);
    v499 = *((_QWORD *)v107 + 15);
    v501 = *((_QWORD *)v107 + 12);
    v502 = *((_QWORD *)v107 + 13);
    v11[217] = 0;
    v11[199] = v499;
    v11[198] = v500;
    v11[197] = v502;
    v11[196] = v501;
    v11[222] = 0xF00000005LL;
    v503 = *((_QWORD *)v107 + 2);
    v504 = *(_QWORD *)v107;
    v505 = *((_QWORD *)v107 + 1);
    v11[226] = *((_QWORD *)v107 + 3);
    v11[225] = v503;
    v11[224] = v505;
    v11[223] = v504;
    v506 = *((_QWORD *)v107 + 6);
    v507 = *((_QWORD *)v107 + 4);
    v508 = *((_QWORD *)v107 + 5);
    v11[230] = *((_QWORD *)v107 + 7);
    v11[229] = v506;
    v11[228] = v508;
    v11[227] = v507;
    v509 = *((_QWORD *)v107 + 10);
    v510 = *((_QWORD *)v107 + 8);
    v511 = *((_QWORD *)v107 + 9);
    v11[234] = *((_QWORD *)v107 + 11);
    v11[233] = v509;
    v11[232] = v511;
    v11[231] = v510;
    v512 = *((_QWORD *)v107 + 14);
    v513 = *((_QWORD *)v107 + 12);
    v514 = *((_QWORD *)v107 + 13);
    v11[238] = *((_QWORD *)v107 + 15);
    v11[237] = v512;
    v11[236] = v514;
    v11[235] = v513;
LABEL_172:
    v11[256] = 0;
    goto LABEL_187;
  }
  v323 = v887;
  v414 = v888;
  if ( !v10[256] )
    v414 = 1;
  if ( (v414 & 1) == 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: del link only - send frm first",
      v314,
      v315,
      v316,
      v317,
      v318,
      v319,
      v320,
      v321,
      "mlo_link_recfg_create_transition_list");
    *((_DWORD *)v10 + 67) = 1;
    v11[105] = 0x1300000007LL;
    v539 = *((_QWORD *)v10 + 19);
    v540 = *((_QWORD *)v10 + 17);
    v541 = *((_QWORD *)v10 + 18);
    v11[125] = *((_QWORD *)v10 + 20);
    v11[124] = v539;
    v11[123] = v541;
    v11[122] = v540;
    v542 = *((_QWORD *)v10 + 23);
    v543 = *((_QWORD *)v10 + 21);
    v544 = *((_QWORD *)v10 + 22);
    v11[129] = *((_QWORD *)v10 + 24);
    v11[128] = v542;
    v11[127] = v544;
    v11[126] = v543;
    v545 = *((_QWORD *)v10 + 27);
    v546 = *((_QWORD *)v10 + 25);
    v547 = *((_QWORD *)v10 + 26);
    v11[133] = *((_QWORD *)v10 + 28);
    v11[132] = v545;
    v11[131] = v547;
    v11[130] = v546;
    v549 = *((_QWORD *)v10 + 31);
    v548 = *((_QWORD *)v10 + 32);
    v550 = *((_QWORD *)v10 + 29);
    v551 = *((_QWORD *)v10 + 30);
    v11[139] = 0;
    v11[144] = 0x600000003LL;
    v11[137] = v548;
    v11[136] = v549;
    v11[135] = v551;
    v11[134] = v550;
    v552 = *((_QWORD *)v10 + 19);
    v553 = *((_QWORD *)v10 + 17);
    v554 = *((_QWORD *)v10 + 18);
    v11[164] = *((_QWORD *)v10 + 20);
    v11[163] = v552;
    v11[162] = v554;
    v11[161] = v553;
    v555 = *((_QWORD *)v10 + 23);
    v556 = *((_QWORD *)v10 + 21);
    v557 = *((_QWORD *)v10 + 22);
    v11[168] = *((_QWORD *)v10 + 24);
    v11[167] = v555;
    v11[166] = v557;
    v11[165] = v556;
    v558 = *((_QWORD *)v10 + 27);
    v559 = *((_QWORD *)v10 + 25);
    v560 = *((_QWORD *)v10 + 26);
    v11[172] = *((_QWORD *)v10 + 28);
    v11[171] = v558;
    v11[170] = v560;
    v11[169] = v559;
    v561 = *((_QWORD *)v10 + 31);
    v562 = *((_QWORD *)v10 + 29);
    v563 = *((_QWORD *)v10 + 30);
    v11[176] = *((_QWORD *)v10 + 32);
    v11[175] = v561;
    v11[174] = v563;
    v11[173] = v562;
    v376 = mlo_link_recfg_set_tx_link_addr(v11, v11 + 145, v887 & ~(_DWORD)v22);
    if ( v376 )
      goto LABEL_185;
    v11[178] = 0;
    v11[181] = mlo_link_recfg_defer_rsp_handler;
    *((_DWORD *)v10 + 67) = 1;
    v11[183] = 0x400000002LL;
    v564 = *((_QWORD *)v10 + 19);
    v565 = *((_QWORD *)v10 + 17);
    v566 = *((_QWORD *)v10 + 18);
    v11[203] = *((_QWORD *)v10 + 20);
    v11[202] = v564;
    v11[201] = v566;
    v11[200] = v565;
    v567 = *((_QWORD *)v10 + 23);
    v568 = *((_QWORD *)v10 + 21);
    v569 = *((_QWORD *)v10 + 22);
    v11[207] = *((_QWORD *)v10 + 24);
    v11[206] = v567;
    v11[205] = v569;
    v11[204] = v568;
    v570 = *((_QWORD *)v10 + 27);
    v571 = *((_QWORD *)v10 + 25);
    v572 = *((_QWORD *)v10 + 26);
    v11[211] = *((_QWORD *)v10 + 28);
    v11[210] = v570;
    v11[209] = v572;
    v11[208] = v571;
    v574 = *((_QWORD *)v10 + 31);
    v573 = *((_QWORD *)v10 + 32);
    v575 = *((_QWORD *)v10 + 29);
    v576 = *((_QWORD *)v10 + 30);
    v11[217] = 0;
    v11[222] = 0x600000003LL;
    v11[215] = v573;
    v11[214] = v574;
    v11[213] = v576;
    v11[212] = v575;
    v577 = *((_QWORD *)v10 + 19);
    v578 = *((_QWORD *)v10 + 17);
    v579 = *((_QWORD *)v10 + 18);
    v11[242] = *((_QWORD *)v10 + 20);
    v11[241] = v577;
    v11[240] = v579;
    v11[239] = v578;
    v580 = *((_QWORD *)v10 + 23);
    v581 = *((_QWORD *)v10 + 21);
    v582 = *((_QWORD *)v10 + 22);
    v11[246] = *((_QWORD *)v10 + 24);
    v11[245] = v580;
    v11[244] = v582;
    v11[243] = v581;
    v583 = *((_QWORD *)v10 + 27);
    v584 = *((_QWORD *)v10 + 25);
    v585 = *((_QWORD *)v10 + 26);
    v11[250] = *((_QWORD *)v10 + 28);
    v11[249] = v583;
    v11[248] = v585;
    v11[247] = v584;
    v587 = *((_QWORD *)v10 + 31);
    v586 = *((_QWORD *)v10 + 32);
    v588 = *((_QWORD *)v10 + 29);
    v589 = *((_QWORD *)v10 + 30);
    v11[256] = 0;
    v11[254] = v586;
    v11[260] = mlo_link_recfg_proc_defer_rsp_handler;
    v11[253] = v587;
    v11[252] = v589;
    v11[251] = v588;
    v11[261] = 0xF00000005LL;
    v590 = *((_QWORD *)v10 + 19);
    v591 = *((_QWORD *)v10 + 17);
    v592 = *((_QWORD *)v10 + 18);
    v11[281] = *((_QWORD *)v10 + 20);
    v11[280] = v590;
    v11[279] = v592;
    v11[278] = v591;
    v593 = *((_QWORD *)v10 + 23);
    v594 = *((_QWORD *)v10 + 21);
    v595 = *((_QWORD *)v10 + 22);
    v11[285] = *((_QWORD *)v10 + 24);
    v11[284] = v593;
    v11[283] = v595;
    v11[282] = v594;
    v596 = *((_QWORD *)v10 + 27);
    v597 = *((_QWORD *)v10 + 25);
    v598 = *((_QWORD *)v10 + 26);
    v11[289] = *((_QWORD *)v10 + 28);
    v11[288] = v596;
    v11[287] = v598;
    v11[286] = v597;
    v600 = *((_QWORD *)v10 + 31);
    v599 = *((_QWORD *)v10 + 32);
    v601 = *((_QWORD *)v10 + 29);
    v602 = *((_QWORD *)v10 + 30);
    v11[295] = 0;
    v11[293] = v599;
    v11[292] = v600;
    v11[291] = v602;
    v11[290] = v601;
    goto LABEL_187;
  }
  if ( v10[256] )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: del link only",
      v314,
      v315,
      v316,
      v317,
      v318,
      v319,
      v320,
      v321,
      "mlo_link_recfg_create_transition_list");
    *((_DWORD *)v10 + 67) = 1;
    v11[105] = 0x1300000007LL;
    v415 = *((_QWORD *)v10 + 19);
    v416 = *((_QWORD *)v10 + 17);
    v417 = *((_QWORD *)v10 + 18);
    v11[125] = *((_QWORD *)v10 + 20);
    v11[124] = v415;
    v11[123] = v417;
    v11[122] = v416;
    v418 = *((_QWORD *)v10 + 23);
    v419 = *((_QWORD *)v10 + 21);
    v420 = *((_QWORD *)v10 + 22);
    v11[129] = *((_QWORD *)v10 + 24);
    v11[128] = v418;
    v11[127] = v420;
    v11[126] = v419;
    v421 = *((_QWORD *)v10 + 27);
    v422 = *((_QWORD *)v10 + 25);
    v423 = *((_QWORD *)v10 + 26);
    v11[133] = *((_QWORD *)v10 + 28);
    v11[132] = v421;
    v11[131] = v423;
    v11[130] = v422;
    v425 = *((_QWORD *)v10 + 31);
    v424 = *((_QWORD *)v10 + 32);
    v426 = *((_QWORD *)v10 + 29);
    v427 = *((_QWORD *)v10 + 30);
    v11[139] = 0;
    v11[137] = v424;
    v11[136] = v425;
    v11[135] = v427;
    v11[134] = v426;
    v11[144] = 0x400000002LL;
    v428 = *((_QWORD *)v10 + 19);
    v429 = *((_QWORD *)v10 + 17);
    v430 = *((_QWORD *)v10 + 18);
    v11[164] = *((_QWORD *)v10 + 20);
    v11[163] = v428;
    v11[162] = v430;
    v11[161] = v429;
    v431 = *((_QWORD *)v10 + 23);
    v432 = *((_QWORD *)v10 + 21);
    v433 = *((_QWORD *)v10 + 22);
    v11[168] = *((_QWORD *)v10 + 24);
    v11[167] = v431;
    v11[166] = v433;
    v11[165] = v432;
    v434 = *((_QWORD *)v10 + 27);
    v435 = *((_QWORD *)v10 + 25);
    v436 = *((_QWORD *)v10 + 26);
    v11[172] = *((_QWORD *)v10 + 28);
    v11[171] = v434;
    v11[170] = v436;
    v11[169] = v435;
    v438 = *((_QWORD *)v10 + 31);
    v437 = *((_QWORD *)v10 + 32);
    v439 = *((_QWORD *)v10 + 29);
    v440 = *((_QWORD *)v10 + 30);
    v11[178] = 0;
    v11[176] = v437;
    v11[175] = v438;
    v11[174] = v440;
    v11[173] = v439;
    v11[183] = 0x600000003LL;
    v441 = *((_QWORD *)v10 + 19);
    v442 = *((_QWORD *)v10 + 17);
    v443 = *((_QWORD *)v10 + 18);
    v11[203] = *((_QWORD *)v10 + 20);
    v11[202] = v441;
    v11[201] = v443;
    v11[200] = v442;
    v444 = *((_QWORD *)v10 + 23);
    v445 = *((_QWORD *)v10 + 21);
    v446 = *((_QWORD *)v10 + 22);
    v11[207] = *((_QWORD *)v10 + 24);
    v11[206] = v444;
    v11[205] = v446;
    v11[204] = v445;
    v447 = *((_QWORD *)v10 + 27);
    v448 = *((_QWORD *)v10 + 25);
    v449 = *((_QWORD *)v10 + 26);
    v11[211] = *((_QWORD *)v10 + 28);
    v11[210] = v447;
    v11[209] = v449;
    v11[208] = v448;
    v450 = *((_QWORD *)v10 + 31);
    v451 = *((_QWORD *)v10 + 29);
    v452 = *((_QWORD *)v10 + 30);
    v11[215] = *((_QWORD *)v10 + 32);
    v11[214] = v450;
    v11[213] = v452;
    v11[212] = v451;
    v376 = mlo_link_recfg_set_tx_link_addr(v11, v11 + 184, v887 & ~(_DWORD)v22);
    if ( v376 )
      goto LABEL_185;
    v11[217] = 0;
    v11[222] = 0xF00000005LL;
    v453 = *((_QWORD *)v10 + 19);
    v454 = *((_QWORD *)v10 + 17);
    v455 = *((_QWORD *)v10 + 18);
    v11[242] = *((_QWORD *)v10 + 20);
    v11[241] = v453;
    v11[240] = v455;
    v11[239] = v454;
    v456 = *((_QWORD *)v10 + 23);
    v457 = *((_QWORD *)v10 + 21);
    v458 = *((_QWORD *)v10 + 22);
    v11[246] = *((_QWORD *)v10 + 24);
    v11[245] = v456;
    v11[244] = v458;
    v11[243] = v457;
    v459 = *((_QWORD *)v10 + 27);
    v460 = *((_QWORD *)v10 + 25);
    v461 = *((_QWORD *)v10 + 26);
    v11[250] = *((_QWORD *)v10 + 28);
    v11[249] = v459;
    v11[248] = v461;
    v11[247] = v460;
    v462 = *((_QWORD *)v10 + 31);
    v463 = *((_QWORD *)v10 + 29);
    v464 = *((_QWORD *)v10 + 30);
    v11[254] = *((_QWORD *)v10 + 32);
    v11[253] = v462;
    v11[252] = v464;
    v11[251] = v463;
    goto LABEL_172;
  }
LABEL_157:
  v324 = v323 & ~(_DWORD)v22;
  if ( !v324 || !v38 )
  {
    if ( v323 != (_DWORD)v22 || !v38 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: not supported, unexpected request del set 0x%x add set 0x%x curr set 0x%x",
        v314,
        v315,
        v316,
        v317,
        v318,
        v319,
        v320,
        v321,
        "mlo_link_recfg_create_transition_list",
        (unsigned int)v22,
        v38);
      state = 4;
      goto LABEL_193;
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: del and add link - no common link",
      v314,
      v315,
      v316,
      v317,
      v318,
      v319,
      v320,
      v321,
      "mlo_link_recfg_create_transition_list");
    *((_DWORD *)v10 + 67) = 4;
    if ( v885 < 2 )
    {
      v523 = v884;
      v538 = v11 + 144;
      v11[105] = 0x1300000007LL;
      v715 = *((_QWORD *)v10 + 19);
      v716 = *((_QWORD *)v10 + 17);
      v717 = *((_QWORD *)v10 + 18);
      v11[125] = *((_QWORD *)v10 + 20);
      v11[124] = v715;
      v11[123] = v717;
      v11[122] = v716;
      v718 = *((_QWORD *)v10 + 23);
      v719 = *((_QWORD *)v10 + 21);
      v720 = *((_QWORD *)v10 + 22);
      v11[129] = *((_QWORD *)v10 + 24);
      v11[128] = v718;
      v11[127] = v720;
      v11[126] = v719;
      v721 = *((_QWORD *)v10 + 27);
      v722 = *((_QWORD *)v10 + 25);
      v723 = *((_QWORD *)v10 + 26);
      v11[133] = *((_QWORD *)v10 + 28);
      v11[132] = v721;
      v11[131] = v723;
      v11[130] = v722;
      v724 = *((_QWORD *)v10 + 31);
      v725 = *((_QWORD *)v10 + 29);
      v726 = *((_QWORD *)v10 + 30);
      v11[137] = *((_QWORD *)v10 + 32);
      v11[136] = v724;
      v11[135] = v726;
      v11[134] = v725;
    }
    else
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: del_link_set_no_common 0x%x",
        v515,
        v516,
        v517,
        v518,
        v519,
        v520,
        v521,
        v522,
        "mlo_link_recfg_create_transition_list",
        v886);
      v523 = v884;
      v11[105] = 0x1300000007LL;
      v524 = *((_QWORD *)v10 + 19);
      v525 = *((_QWORD *)v10 + 17);
      v526 = *((_QWORD *)v10 + 18);
      v11[125] = *((_QWORD *)v10 + 20);
      v11[124] = v524;
      v11[123] = v526;
      v11[122] = v525;
      v527 = *((_QWORD *)v10 + 23);
      v528 = *((_QWORD *)v10 + 21);
      v529 = *((_QWORD *)v10 + 22);
      v11[129] = *((_QWORD *)v10 + 24);
      v11[128] = v527;
      v11[127] = v529;
      v11[126] = v528;
      v530 = *((_QWORD *)v10 + 27);
      v531 = *((_QWORD *)v10 + 25);
      v532 = *((_QWORD *)v10 + 26);
      v11[133] = *((_QWORD *)v10 + 28);
      v11[132] = v530;
      v11[131] = v532;
      v11[130] = v531;
      v534 = *((_QWORD *)v10 + 31);
      v533 = *((_QWORD *)v10 + 32);
      v535 = *((_QWORD *)v10 + 29);
      v536 = *((_QWORD *)v10 + 30);
      v11[139] = 0;
      v11[178] = 0;
      v11[137] = v533;
      v11[136] = v534;
      v11[135] = v536;
      v11[134] = v535;
      v11[144] = 0x400000002LL;
      v537 = ((__int64 (__fastcall *)(unsigned __int8 *, _QWORD, _QWORD, _QWORD *, unsigned int *))mlo_link_recfg_fill_del_link_no_common)(
               v10,
               v886,
               v884,
               v11 + 161,
               &v897);
      if ( v537 )
        goto LABEL_190;
      v538 = v11 + 183;
      v886 = v897;
    }
    v538[34] = 0;
    *v538 = 0x500000004LL;
    v538[36] = mlo_link_pre_link_add_handler;
    v727 = *((_QWORD *)v107 + 1);
    v729 = *((_QWORD *)v107 + 2);
    v728 = *((_QWORD *)v107 + 3);
    v538[1] = *(_QWORD *)v107;
    v538[3] = v729;
    v538[4] = v728;
    v538[2] = v727;
    v730 = *((_QWORD *)v107 + 7);
    v731 = *((_QWORD *)v107 + 4);
    v732 = *((_QWORD *)v107 + 5);
    v538[7] = *((_QWORD *)v107 + 6);
    v538[8] = v730;
    v538[5] = v731;
    v538[6] = v732;
    v733 = *((_QWORD *)v107 + 11);
    v734 = *((_QWORD *)v107 + 8);
    v735 = *((_QWORD *)v107 + 9);
    v538[11] = *((_QWORD *)v107 + 10);
    v538[12] = v733;
    v538[9] = v734;
    v538[10] = v735;
    v736 = *((_QWORD *)v107 + 15);
    v737 = *((_QWORD *)v107 + 12);
    v738 = *((_QWORD *)v107 + 13);
    v538[15] = *((_QWORD *)v107 + 14);
    v538[16] = v736;
    v538[13] = v737;
    v538[14] = v738;
    v739 = *((_QWORD *)v10 + 18);
    v741 = *((_QWORD *)v10 + 19);
    v740 = *((_QWORD *)v10 + 20);
    v538[17] = *((_QWORD *)v10 + 17);
    v538[18] = v739;
    v538[19] = v741;
    v538[20] = v740;
    v742 = *((_QWORD *)v10 + 24);
    v743 = *((_QWORD *)v10 + 21);
    v744 = *((_QWORD *)v10 + 22);
    v538[23] = *((_QWORD *)v10 + 23);
    v538[24] = v742;
    v538[21] = v743;
    v538[22] = v744;
    v745 = *((_QWORD *)v10 + 28);
    v746 = *((_QWORD *)v10 + 25);
    v747 = *((_QWORD *)v10 + 26);
    v538[27] = *((_QWORD *)v10 + 27);
    v538[28] = v745;
    v538[25] = v746;
    v538[26] = v747;
    v748 = *((_QWORD *)v10 + 32);
    v749 = *((_QWORD *)v10 + 29);
    v750 = *((_QWORD *)v10 + 30);
    v538[31] = *((_QWORD *)v10 + 31);
    v538[32] = v748;
    v538[29] = v749;
    v538[30] = v750;
    v376 = mlo_link_recfg_set_tx_link_addr(v11, v538 + 1, (unsigned int)v22 & ~v886);
    if ( v376 )
      goto LABEL_185;
    v837 = (unsigned int)v22 & ~v897;
    v538[39] = 0x400000002LL;
    v538[73] = 0;
    v897 = v837;
    v537 = ((__int64 (__fastcall *)(unsigned __int8 *, __int64, _QWORD, _QWORD *, unsigned int *))mlo_link_recfg_fill_del_link_no_common)(
             v10,
             v837,
             v523,
             v538 + 56,
             &v897);
    if ( !v537 )
    {
      v538[112] = 0;
      v538[78] = 0xF00000005LL;
      v839 = *((_QWORD *)v10 + 19);
      v840 = *((_QWORD *)v10 + 17);
      v841 = *((_QWORD *)v10 + 18);
      v538[98] = *((_QWORD *)v10 + 20);
      v538[97] = v839;
      v538[96] = v841;
      v538[95] = v840;
      v842 = *((_QWORD *)v10 + 23);
      v843 = *((_QWORD *)v10 + 21);
      v844 = *((_QWORD *)v10 + 22);
      v538[102] = *((_QWORD *)v10 + 24);
      v538[101] = v842;
      v538[100] = v844;
      v538[99] = v843;
      v845 = *((_QWORD *)v10 + 27);
      v846 = *((_QWORD *)v10 + 25);
      v847 = *((_QWORD *)v10 + 26);
      v538[106] = *((_QWORD *)v10 + 28);
      v538[105] = v845;
      v538[104] = v847;
      v538[103] = v846;
      v848 = *((_QWORD *)v10 + 31);
      v849 = *((_QWORD *)v10 + 29);
      v850 = *((_QWORD *)v10 + 30);
      v538[110] = *((_QWORD *)v10 + 32);
      v538[109] = v848;
      v538[108] = v850;
      v538[107] = v849;
      v851 = *((_QWORD *)v107 + 2);
      v852 = *(_QWORD *)v107;
      v853 = *((_QWORD *)v107 + 1);
      v538[82] = *((_QWORD *)v107 + 3);
      v538[81] = v851;
      v538[80] = v853;
      v538[79] = v852;
      v854 = *((_QWORD *)v107 + 6);
      v855 = *((_QWORD *)v107 + 4);
      v856 = *((_QWORD *)v107 + 5);
      v538[86] = *((_QWORD *)v107 + 7);
      v538[85] = v854;
      v538[84] = v856;
      v538[83] = v855;
      v857 = *((_QWORD *)v107 + 10);
      v858 = *((_QWORD *)v107 + 8);
      v859 = *((_QWORD *)v107 + 9);
      v538[90] = *((_QWORD *)v107 + 11);
      v538[89] = v857;
      v538[88] = v859;
      v538[87] = v858;
      v860 = *((_QWORD *)v107 + 14);
      v861 = *((_QWORD *)v107 + 12);
      v862 = *((_QWORD *)v107 + 13);
      v538[94] = *((_QWORD *)v107 + 15);
      v538[93] = v860;
      v538[92] = v862;
      v538[91] = v861;
      goto LABEL_187;
    }
LABEL_190:
    state = v537;
    v311 = "%s: fail to fill del link info status %d";
    goto LABEL_191;
  }
  if ( v10[558] == 1 && (v10[264] & 1) == 0 )
  {
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: send 2 OTA frames - del and add link",
      v314,
      v315,
      v316,
      v317,
      v318,
      v319,
      v320,
      v321,
      "mlo_link_recfg_create_transition_list");
    *((_DWORD *)v10 + 67) = 5;
    v11[105] = 0x1300000007LL;
    v751 = *((_QWORD *)v10 + 19);
    v752 = *((_QWORD *)v10 + 17);
    v753 = *((_QWORD *)v10 + 18);
    v11[125] = *((_QWORD *)v10 + 20);
    v11[124] = v751;
    v11[123] = v753;
    v11[122] = v752;
    v754 = *((_QWORD *)v10 + 23);
    v755 = *((_QWORD *)v10 + 21);
    v756 = *((_QWORD *)v10 + 22);
    v11[129] = *((_QWORD *)v10 + 24);
    v11[128] = v754;
    v11[127] = v756;
    v11[126] = v755;
    v757 = *((_QWORD *)v10 + 27);
    v758 = *((_QWORD *)v10 + 25);
    v759 = *((_QWORD *)v10 + 26);
    v11[133] = *((_QWORD *)v10 + 28);
    v11[132] = v757;
    v11[131] = v759;
    v11[130] = v758;
    v761 = *((_QWORD *)v10 + 31);
    v760 = *((_QWORD *)v10 + 32);
    v762 = *((_QWORD *)v10 + 29);
    v763 = *((_QWORD *)v10 + 30);
    v11[139] = 0;
    v11[137] = v760;
    v11[136] = v761;
    v11[135] = v763;
    v11[134] = v762;
    memcpy(v11 + 434, v10, 0x230u);
    v11[144] = 0x400000002LL;
    v764 = *((_QWORD *)v10 + 18);
    v766 = *((_QWORD *)v10 + 19);
    v765 = *((_QWORD *)v10 + 20);
    v11[161] = *((_QWORD *)v10 + 17);
    v11[164] = v765;
    v11[163] = v766;
    v11[162] = v764;
    v767 = *((_QWORD *)v10 + 22);
    v769 = *((_QWORD *)v10 + 23);
    v768 = *((_QWORD *)v10 + 24);
    v11[165] = *((_QWORD *)v10 + 21);
    v11[168] = v768;
    v11[167] = v769;
    v11[166] = v767;
    v770 = *((_QWORD *)v10 + 26);
    v772 = *((_QWORD *)v10 + 27);
    v771 = *((_QWORD *)v10 + 28);
    v11[169] = *((_QWORD *)v10 + 25);
    v11[172] = v771;
    v11[171] = v772;
    v11[170] = v770;
    v773 = *((_QWORD *)v10 + 29);
    v774 = *((_QWORD *)v10 + 30);
    v776 = *((_QWORD *)v10 + 31);
    v775 = *((_QWORD *)v10 + 32);
    v11[178] = 0;
    v11[183] = 0x600000003LL;
    v11[173] = v773;
    v11[176] = v775;
    v11[175] = v776;
    v11[174] = v774;
    v777 = *((_QWORD *)v10 + 19);
    v778 = *((_QWORD *)v10 + 17);
    v779 = *((_QWORD *)v10 + 18);
    v11[203] = *((_QWORD *)v10 + 20);
    v11[202] = v777;
    v11[201] = v779;
    v11[200] = v778;
    v780 = *((_QWORD *)v10 + 23);
    v781 = *((_QWORD *)v10 + 21);
    v782 = *((_QWORD *)v10 + 22);
    v11[207] = *((_QWORD *)v10 + 24);
    v11[206] = v780;
    v11[205] = v782;
    v11[204] = v781;
    v783 = *((_QWORD *)v10 + 27);
    v784 = *((_QWORD *)v10 + 25);
    v785 = *((_QWORD *)v10 + 26);
    v11[211] = *((_QWORD *)v10 + 28);
    v11[210] = v783;
    v11[209] = v785;
    v11[208] = v784;
    v786 = *((_QWORD *)v10 + 31);
    v787 = *((_QWORD *)v10 + 29);
    v788 = *((_QWORD *)v10 + 30);
    v11[215] = *((_QWORD *)v10 + 32);
    v11[214] = v786;
    v11[213] = v788;
    v11[212] = v787;
    mlo_link_recfg_set_tx_link_addr(v11, v11 + 184, v324);
    v789 = v11[448];
    v11[218] = &two_frm_del_xmit_handler;
    v790 = v11[447];
    v11[236] = v789;
    v791 = v11[450];
    v11[235] = v790;
    v792 = v11[449];
    v11[238] = v791;
    v793 = v11[444];
    v11[237] = v792;
    v794 = v11[443];
    v11[232] = v793;
    v795 = v11[446];
    v11[231] = v794;
    v796 = v11[445];
    v11[234] = v795;
    v797 = v11[440];
    v11[233] = v796;
    v798 = v11[439];
    v11[228] = v797;
    v799 = v11[442];
    v11[227] = v798;
    v800 = v11[441];
    v11[230] = v799;
    v801 = v11[436];
    v11[229] = v800;
    v802 = v11[435];
    v11[224] = v801;
    v803 = v11[438];
    v11[223] = v802;
    v804 = v11[437];
    v11[217] = 0;
    v11[222] = 0x600000003LL;
    v11[225] = v804;
    v11[226] = v803;
    mlo_link_recfg_set_tx_link_addr(v11, v11 + 223, v324);
    v805 = v11[447];
    v11[257] = &two_frm_add_xmit_handler;
    v11[274] = v805;
    v806 = v11[449];
    v11[261] = 0x500000004LL;
    v807 = v11[448];
    v11[276] = v806;
    v808 = v11[443];
    v11[275] = v807;
    v809 = v11[450];
    v11[270] = v808;
    v810 = v11[445];
    v11[277] = v809;
    v811 = v11[444];
    v11[272] = v810;
    v812 = v11[439];
    v11[271] = v811;
    v813 = v11[446];
    v11[266] = v812;
    v814 = v11[441];
    v11[273] = v813;
    v815 = v11[440];
    v11[268] = v814;
    v816 = v11[435];
    v11[267] = v815;
    v817 = v11[442];
    v11[262] = v816;
    v818 = v11[437];
    v11[269] = v817;
    v819 = v11[436];
    v11[264] = v818;
    v820 = v11[447];
    v11[263] = v819;
    v821 = v11[438];
    v11[313] = v820;
    v822 = v11[449];
    v11[265] = v821;
    v11[315] = v822;
    v823 = v11[443];
    v11[300] = 0xF00000005LL;
    v824 = v11[448];
    v11[309] = v823;
    v825 = v11[445];
    v11[314] = v824;
    v826 = v11[450];
    v11[311] = v825;
    v827 = v11[439];
    v11[316] = v826;
    v828 = v11[444];
    v11[305] = v827;
    v829 = v11[441];
    v11[310] = v828;
    v830 = v11[446];
    v11[307] = v829;
    v831 = v11[435];
    v11[312] = v830;
    v832 = v11[440];
    v11[301] = v831;
    v833 = v11[437];
    v11[306] = v832;
    v834 = v11[442];
    v11[303] = v833;
    v11[308] = v834;
    v835 = v11[436];
    v11[256] = 0;
    v11[302] = v835;
    v836 = v11[438];
    v11[334] = 0;
    v11[304] = v836;
  }
  else
  {
    v325 = v11 + 122;
    if ( (v888 & 1) != 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        8u,
        "%s: del and add link",
        v314,
        v315,
        v316,
        v317,
        v318,
        v319,
        v320,
        v321,
        "mlo_link_recfg_create_transition_list");
      *((_DWORD *)v10 + 67) = 3;
      v11[105] = 0x1300000007LL;
      v326 = *((_QWORD *)v10 + 20);
      v327 = *((_QWORD *)v10 + 17);
      v328 = *((_QWORD *)v10 + 18);
      v11[124] = *((_QWORD *)v10 + 19);
      v11[125] = v326;
      *v325 = v327;
      v11[123] = v328;
      v329 = *((_QWORD *)v10 + 24);
      v330 = *((_QWORD *)v10 + 21);
      v331 = *((_QWORD *)v10 + 22);
      v11[128] = *((_QWORD *)v10 + 23);
      v11[129] = v329;
      v11[126] = v330;
      v11[127] = v331;
      v332 = *((_QWORD *)v10 + 28);
      v333 = *((_QWORD *)v10 + 25);
      v334 = *((_QWORD *)v10 + 26);
      v11[132] = *((_QWORD *)v10 + 27);
      v11[133] = v332;
      v11[130] = v333;
      v11[131] = v334;
      v336 = *((_QWORD *)v10 + 31);
      v335 = *((_QWORD *)v10 + 32);
      v337 = *((_QWORD *)v10 + 29);
      v338 = *((_QWORD *)v10 + 30);
      v11[139] = 0;
      v11[136] = v336;
      v11[137] = v335;
      v11[134] = v337;
      v11[135] = v338;
      v11[144] = 0x400000002LL;
      v339 = *((_QWORD *)v10 + 19);
      v340 = *((_QWORD *)v10 + 17);
      v341 = *((_QWORD *)v10 + 18);
      v11[164] = *((_QWORD *)v10 + 20);
      v11[163] = v339;
      v11[162] = v341;
      v11[161] = v340;
      v342 = *((_QWORD *)v10 + 23);
      v343 = *((_QWORD *)v10 + 21);
      v344 = *((_QWORD *)v10 + 22);
      v11[168] = *((_QWORD *)v10 + 24);
      v11[167] = v342;
      v11[166] = v344;
      v11[165] = v343;
      v345 = *((_QWORD *)v10 + 27);
      v346 = *((_QWORD *)v10 + 25);
      v347 = *((_QWORD *)v10 + 26);
      v11[172] = *((_QWORD *)v10 + 28);
      v11[171] = v345;
      v11[170] = v347;
      v11[169] = v346;
      v349 = *((_QWORD *)v10 + 31);
      v348 = *((_QWORD *)v10 + 32);
      v350 = *((_QWORD *)v10 + 29);
      v351 = *((_QWORD *)v10 + 30);
      v11[178] = 0;
      v11[176] = v348;
      v11[175] = v349;
      v11[174] = v351;
      v11[173] = v350;
      v11[183] = 0x600000003LL;
      v352 = *((_QWORD *)v10 + 19);
      v353 = *((_QWORD *)v10 + 17);
      v354 = *((_QWORD *)v10 + 18);
      v11[203] = *((_QWORD *)v10 + 20);
      v11[202] = v352;
      v11[201] = v354;
      v11[200] = v353;
      v355 = *((_QWORD *)v10 + 23);
      v356 = *((_QWORD *)v10 + 21);
      v357 = *((_QWORD *)v10 + 22);
      v11[207] = *((_QWORD *)v10 + 24);
      v11[206] = v355;
      v11[205] = v357;
      v11[204] = v356;
      v358 = *((_QWORD *)v10 + 27);
      v359 = *((_QWORD *)v10 + 25);
      v360 = *((_QWORD *)v10 + 26);
      v11[211] = *((_QWORD *)v10 + 28);
      v11[210] = v358;
      v11[209] = v360;
      v11[208] = v359;
      v361 = *((_QWORD *)v10 + 31);
      v362 = *((_QWORD *)v10 + 29);
      v363 = *((_QWORD *)v10 + 30);
      v11[215] = *((_QWORD *)v10 + 32);
      v11[214] = v361;
      v11[213] = v363;
      v11[212] = v362;
      v364 = *((_QWORD *)v107 + 2);
      v365 = *(_QWORD *)v107;
      v366 = *((_QWORD *)v107 + 1);
      v11[187] = *((_QWORD *)v107 + 3);
      v11[186] = v364;
      v11[185] = v366;
      v11[184] = v365;
      v367 = *((_QWORD *)v107 + 6);
      v368 = *((_QWORD *)v107 + 4);
      v369 = *((_QWORD *)v107 + 5);
      v11[191] = *((_QWORD *)v107 + 7);
      v11[190] = v367;
      v11[189] = v369;
      v11[188] = v368;
      v370 = *((_QWORD *)v107 + 10);
      v371 = *((_QWORD *)v107 + 8);
      v372 = *((_QWORD *)v107 + 9);
      v11[195] = *((_QWORD *)v107 + 11);
      v11[194] = v370;
      v11[193] = v372;
      v11[192] = v371;
      v373 = *((_QWORD *)v107 + 14);
      v374 = *((_QWORD *)v107 + 12);
      v375 = *((_QWORD *)v107 + 13);
      v11[199] = *((_QWORD *)v107 + 15);
      v11[198] = v373;
      v11[197] = v375;
      v11[196] = v374;
      v376 = mlo_link_recfg_set_tx_link_addr(v11, v11 + 184, v324);
      if ( !v376 )
      {
        v11[217] = 0;
        v11[222] = 0x500000004LL;
        v377 = *((_QWORD *)v107 + 2);
        v378 = *(_QWORD *)v107;
        v379 = *((_QWORD *)v107 + 1);
        v11[226] = *((_QWORD *)v107 + 3);
        v11[225] = v377;
        v11[224] = v379;
        v11[223] = v378;
        v380 = *((_QWORD *)v107 + 6);
        v381 = *((_QWORD *)v107 + 4);
        v382 = *((_QWORD *)v107 + 5);
        v11[230] = *((_QWORD *)v107 + 7);
        v11[229] = v380;
        v11[228] = v382;
        v11[227] = v381;
        v383 = *((_QWORD *)v107 + 10);
        v384 = *((_QWORD *)v107 + 8);
        v385 = *((_QWORD *)v107 + 9);
        v11[234] = *((_QWORD *)v107 + 11);
        v11[233] = v383;
        v11[232] = v385;
        v11[231] = v384;
        v386 = *((_QWORD *)v107 + 14);
        v387 = *((_QWORD *)v107 + 12);
        v388 = *((_QWORD *)v107 + 13);
        v11[238] = *((_QWORD *)v107 + 15);
        v11[237] = v386;
        v11[236] = v388;
        v11[235] = v387;
        v11[261] = 0xF00000005LL;
        v389 = *((_QWORD *)v10 + 19);
        v390 = *((_QWORD *)v10 + 17);
        v391 = *((_QWORD *)v10 + 18);
        v11[281] = *((_QWORD *)v10 + 20);
        v11[280] = v389;
        v11[279] = v391;
        v11[278] = v390;
        v392 = *((_QWORD *)v10 + 23);
        v393 = *((_QWORD *)v10 + 21);
        v394 = *((_QWORD *)v10 + 22);
        v11[285] = *((_QWORD *)v10 + 24);
        v11[284] = v392;
        v11[283] = v394;
        v11[282] = v393;
        v395 = *((_QWORD *)v10 + 27);
        v396 = *((_QWORD *)v10 + 25);
        v397 = *((_QWORD *)v10 + 26);
        v11[289] = *((_QWORD *)v10 + 28);
        v11[288] = v395;
        v11[287] = v397;
        v11[286] = v396;
        v398 = *((_QWORD *)v10 + 31);
        v399 = *((_QWORD *)v10 + 29);
        v400 = *((_QWORD *)v10 + 30);
        v11[293] = *((_QWORD *)v10 + 32);
        v11[292] = v398;
        v11[291] = v400;
        v11[290] = v399;
        v401 = *((_QWORD *)v107 + 2);
        v402 = *(_QWORD *)v107;
        v403 = *((_QWORD *)v107 + 1);
        v11[265] = *((_QWORD *)v107 + 3);
        v11[264] = v401;
        v11[263] = v403;
        v11[262] = v402;
        v404 = *((_QWORD *)v107 + 6);
        v405 = *((_QWORD *)v107 + 4);
        v406 = *((_QWORD *)v107 + 5);
        v11[269] = *((_QWORD *)v107 + 7);
        v11[268] = v404;
        v11[267] = v406;
        v11[266] = v405;
        v407 = *((_QWORD *)v107 + 10);
        v408 = *((_QWORD *)v107 + 8);
        v409 = *((_QWORD *)v107 + 9);
        v11[273] = *((_QWORD *)v107 + 11);
        v11[272] = v407;
        v11[271] = v409;
        v11[270] = v408;
        v411 = *((_QWORD *)v107 + 14);
        v410 = *((_QWORD *)v107 + 15);
        v412 = *((_QWORD *)v107 + 12);
        v413 = *((_QWORD *)v107 + 13);
        v11[295] = 0;
        v11[277] = v410;
        v11[276] = v411;
        v11[275] = v413;
        v11[274] = v412;
        goto LABEL_187;
      }
LABEL_185:
      state = v376;
      v311 = "%s: fail to set tx frame link addr status %d";
LABEL_191:
      v312 = state;
      goto LABEL_192;
    }
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: del and add link - send frm first",
      v314,
      v315,
      v316,
      v317,
      v318,
      v319,
      v320,
      v321,
      "mlo_link_recfg_create_transition_list");
    *((_DWORD *)v10 + 67) = 3;
    v11[105] = 0x1300000007LL;
    v603 = *((_QWORD *)v10 + 20);
    v604 = *((_QWORD *)v10 + 17);
    v605 = *((_QWORD *)v10 + 18);
    v11[124] = *((_QWORD *)v10 + 19);
    v11[125] = v603;
    *v325 = v604;
    v11[123] = v605;
    v606 = *((_QWORD *)v10 + 24);
    v607 = *((_QWORD *)v10 + 21);
    v608 = *((_QWORD *)v10 + 22);
    v11[128] = *((_QWORD *)v10 + 23);
    v11[129] = v606;
    v11[126] = v607;
    v11[127] = v608;
    v609 = *((_QWORD *)v10 + 28);
    v610 = *((_QWORD *)v10 + 25);
    v611 = *((_QWORD *)v10 + 26);
    v11[132] = *((_QWORD *)v10 + 27);
    v11[133] = v609;
    v11[130] = v610;
    v11[131] = v611;
    v613 = *((_QWORD *)v10 + 31);
    v612 = *((_QWORD *)v10 + 32);
    v614 = *((_QWORD *)v10 + 29);
    v615 = *((_QWORD *)v10 + 30);
    v11[139] = 0;
    v11[136] = v613;
    v11[137] = v612;
    v11[134] = v614;
    v11[135] = v615;
    v11[144] = 0x600000003LL;
    v616 = *((_QWORD *)v10 + 19);
    v617 = *((_QWORD *)v10 + 17);
    v618 = *((_QWORD *)v10 + 18);
    v11[164] = *((_QWORD *)v10 + 20);
    v11[163] = v616;
    v11[162] = v618;
    v11[161] = v617;
    v619 = *((_QWORD *)v10 + 23);
    v620 = *((_QWORD *)v10 + 21);
    v621 = *((_QWORD *)v10 + 22);
    v11[168] = *((_QWORD *)v10 + 24);
    v11[167] = v619;
    v11[166] = v621;
    v11[165] = v620;
    v622 = *((_QWORD *)v10 + 27);
    v623 = *((_QWORD *)v10 + 25);
    v624 = *((_QWORD *)v10 + 26);
    v11[172] = *((_QWORD *)v10 + 28);
    v11[171] = v622;
    v11[170] = v624;
    v11[169] = v623;
    v625 = *((_QWORD *)v10 + 31);
    v626 = *((_QWORD *)v10 + 29);
    v627 = *((_QWORD *)v10 + 30);
    v11[176] = *((_QWORD *)v10 + 32);
    v11[175] = v625;
    v11[174] = v627;
    v11[173] = v626;
    v628 = *((_QWORD *)v107 + 2);
    v629 = *(_QWORD *)v107;
    v630 = *((_QWORD *)v107 + 1);
    v11[148] = *((_QWORD *)v107 + 3);
    v11[147] = v628;
    v11[146] = v630;
    v11[145] = v629;
    v631 = *((_QWORD *)v107 + 6);
    v632 = *((_QWORD *)v107 + 4);
    v633 = *((_QWORD *)v107 + 5);
    v11[152] = *((_QWORD *)v107 + 7);
    v11[151] = v631;
    v11[150] = v633;
    v11[149] = v632;
    v634 = *((_QWORD *)v107 + 10);
    v635 = *((_QWORD *)v107 + 8);
    v636 = *((_QWORD *)v107 + 9);
    v11[156] = *((_QWORD *)v107 + 11);
    v11[155] = v634;
    v11[154] = v636;
    v11[153] = v635;
    v637 = *((_QWORD *)v107 + 14);
    v638 = *((_QWORD *)v107 + 12);
    v639 = *((_QWORD *)v107 + 13);
    v11[160] = *((_QWORD *)v107 + 15);
    v11[159] = v637;
    v11[158] = v639;
    v11[157] = v638;
    v376 = mlo_link_recfg_set_tx_link_addr(v11, v11 + 145, v324);
    if ( v376 )
      goto LABEL_185;
    v11[178] = 0;
    v11[181] = mlo_link_recfg_defer_rsp_handler;
    v11[183] = 0x400000002LL;
    v640 = *((_QWORD *)v10 + 19);
    v641 = *((_QWORD *)v10 + 17);
    v642 = *((_QWORD *)v10 + 18);
    v11[203] = *((_QWORD *)v10 + 20);
    v11[202] = v640;
    v11[201] = v642;
    v11[200] = v641;
    v643 = *((_QWORD *)v10 + 23);
    v644 = *((_QWORD *)v10 + 21);
    v645 = *((_QWORD *)v10 + 22);
    v11[207] = *((_QWORD *)v10 + 24);
    v11[206] = v643;
    v11[205] = v645;
    v11[204] = v644;
    v646 = *((_QWORD *)v10 + 27);
    v647 = *((_QWORD *)v10 + 25);
    v648 = *((_QWORD *)v10 + 26);
    v11[211] = *((_QWORD *)v10 + 28);
    v11[210] = v646;
    v11[209] = v648;
    v11[208] = v647;
    v650 = *((_QWORD *)v10 + 31);
    v649 = *((_QWORD *)v10 + 32);
    v651 = *((_QWORD *)v10 + 29);
    v652 = *((_QWORD *)v10 + 30);
    v11[217] = 0;
    v11[222] = 0x600000003LL;
    v11[215] = v649;
    v11[214] = v650;
    v11[213] = v652;
    v11[212] = v651;
    v653 = *((_QWORD *)v10 + 19);
    v654 = *((_QWORD *)v10 + 17);
    v655 = *((_QWORD *)v10 + 18);
    v11[242] = *((_QWORD *)v10 + 20);
    v11[241] = v653;
    v11[240] = v655;
    v11[239] = v654;
    v656 = *((_QWORD *)v10 + 23);
    v657 = *((_QWORD *)v10 + 21);
    v658 = *((_QWORD *)v10 + 22);
    v11[246] = *((_QWORD *)v10 + 24);
    v11[245] = v656;
    v11[244] = v658;
    v11[243] = v657;
    v659 = *((_QWORD *)v10 + 27);
    v660 = *((_QWORD *)v10 + 25);
    v661 = *((_QWORD *)v10 + 26);
    v11[250] = *((_QWORD *)v10 + 28);
    v11[249] = v659;
    v11[248] = v661;
    v11[247] = v660;
    v662 = *((_QWORD *)v10 + 31);
    v663 = *((_QWORD *)v10 + 29);
    v664 = *((_QWORD *)v10 + 30);
    v11[254] = *((_QWORD *)v10 + 32);
    v11[253] = v662;
    v11[252] = v664;
    v11[251] = v663;
    v665 = *((_QWORD *)v107 + 2);
    v666 = *(_QWORD *)v107;
    v667 = *((_QWORD *)v107 + 1);
    v11[226] = *((_QWORD *)v107 + 3);
    v11[225] = v665;
    v11[224] = v667;
    v11[223] = v666;
    v668 = *((_QWORD *)v107 + 6);
    v669 = *((_QWORD *)v107 + 4);
    v670 = *((_QWORD *)v107 + 5);
    v11[230] = *((_QWORD *)v107 + 7);
    v11[229] = v668;
    v11[228] = v670;
    v11[227] = v669;
    v671 = *((_QWORD *)v107 + 10);
    v672 = *((_QWORD *)v107 + 8);
    v673 = *((_QWORD *)v107 + 9);
    v11[234] = *((_QWORD *)v107 + 11);
    v11[233] = v671;
    v11[232] = v673;
    v11[231] = v672;
    v675 = *((_QWORD *)v107 + 14);
    v674 = *((_QWORD *)v107 + 15);
    v676 = *((_QWORD *)v107 + 12);
    v677 = *((_QWORD *)v107 + 13);
    v11[256] = 0;
    v11[238] = v674;
    v11[260] = mlo_link_recfg_proc_defer_rsp_handler;
    v11[237] = v675;
    v11[236] = v677;
    v11[235] = v676;
    v11[261] = 0x500000004LL;
    v678 = *((_QWORD *)v107 + 2);
    v679 = *(_QWORD *)v107;
    v680 = *((_QWORD *)v107 + 1);
    v11[265] = *((_QWORD *)v107 + 3);
    v11[264] = v678;
    v11[263] = v680;
    v11[262] = v679;
    v681 = *((_QWORD *)v107 + 6);
    v682 = *((_QWORD *)v107 + 4);
    v683 = *((_QWORD *)v107 + 5);
    v11[269] = *((_QWORD *)v107 + 7);
    v11[268] = v681;
    v11[267] = v683;
    v11[266] = v682;
    v684 = *((_QWORD *)v107 + 10);
    v685 = *((_QWORD *)v107 + 8);
    v686 = *((_QWORD *)v107 + 9);
    v11[273] = *((_QWORD *)v107 + 11);
    v11[272] = v684;
    v11[271] = v686;
    v11[270] = v685;
    v687 = *((_QWORD *)v107 + 14);
    v688 = *((_QWORD *)v107 + 12);
    v689 = *((_QWORD *)v107 + 13);
    v11[277] = *((_QWORD *)v107 + 15);
    v11[276] = v687;
    v11[275] = v689;
    v11[274] = v688;
    v11[300] = 0xF00000005LL;
    v690 = *((_QWORD *)v10 + 19);
    v691 = *((_QWORD *)v10 + 17);
    v692 = *((_QWORD *)v10 + 18);
    v11[320] = *((_QWORD *)v10 + 20);
    v11[319] = v690;
    v11[318] = v692;
    v11[317] = v691;
    v693 = *((_QWORD *)v10 + 23);
    v694 = *((_QWORD *)v10 + 21);
    v695 = *((_QWORD *)v10 + 22);
    v11[324] = *((_QWORD *)v10 + 24);
    v11[323] = v693;
    v11[322] = v695;
    v11[321] = v694;
    v696 = *((_QWORD *)v10 + 27);
    v697 = *((_QWORD *)v10 + 25);
    v698 = *((_QWORD *)v10 + 26);
    v11[328] = *((_QWORD *)v10 + 28);
    v11[327] = v696;
    v11[326] = v698;
    v11[325] = v697;
    v699 = *((_QWORD *)v10 + 31);
    v700 = *((_QWORD *)v10 + 29);
    v701 = *((_QWORD *)v10 + 30);
    v11[332] = *((_QWORD *)v10 + 32);
    v11[331] = v699;
    v11[330] = v701;
    v11[329] = v700;
    v702 = *((_QWORD *)v107 + 2);
    v703 = *(_QWORD *)v107;
    v704 = *((_QWORD *)v107 + 1);
    v11[304] = *((_QWORD *)v107 + 3);
    v11[303] = v702;
    v11[302] = v704;
    v11[301] = v703;
    v705 = *((_QWORD *)v107 + 6);
    v706 = *((_QWORD *)v107 + 4);
    v707 = *((_QWORD *)v107 + 5);
    v11[308] = *((_QWORD *)v107 + 7);
    v11[307] = v705;
    v11[306] = v707;
    v11[305] = v706;
    v708 = *((_QWORD *)v107 + 10);
    v709 = *((_QWORD *)v107 + 8);
    v710 = *((_QWORD *)v107 + 9);
    v11[312] = *((_QWORD *)v107 + 11);
    v11[311] = v708;
    v11[310] = v710;
    v11[309] = v709;
    v712 = *((_QWORD *)v107 + 14);
    v711 = *((_QWORD *)v107 + 15);
    v713 = *((_QWORD *)v107 + 12);
    v714 = *((_QWORD *)v107 + 13);
    v11[334] = 0;
    v11[316] = v711;
    v11[315] = v712;
    v11[314] = v714;
    v11[313] = v713;
  }
LABEL_187:
  state = mlo_link_recfg_tranistion_to_next_state(v11);
  if ( state )
  {
    v311 = "%s: start trans failed status %d";
    goto LABEL_191;
  }
LABEL_193:
  _ReadStatusReg(SP_EL0);
  return state;
}
