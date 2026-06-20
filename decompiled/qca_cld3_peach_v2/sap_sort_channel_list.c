__int64 __fastcall sap_sort_channel_list(
        __int64 a1,
        unsigned __int8 a2,
        _QWORD *a3,
        _BYTE *a4,
        _DWORD *a5,
        int *a6,
        char a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x0
  char v20; // w1
  signed int v22; // w20
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x8
  __int64 v32; // x0
  unsigned int *v33; // x24
  __int64 result; // x0
  __int64 v35; // x0
  __int64 v36; // x25
  int v37; // w26
  unsigned int v38; // w23
  unsigned int v39; // w20
  unsigned int *v40; // x27
  char is_channel_in_nol_list; // w28
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  char is_puncture_applicable; // w8
  __int64 v51; // x0
  __int64 v52; // x3
  __int64 v53; // x1
  int v54; // w0
  int v55; // w0
  char v56; // w8
  int v57; // w0
  __int64 v58; // x4
  unsigned __int64 v59; // x8
  unsigned int v60; // w20
  __int64 v61; // x0
  double v62; // d0
  double v63; // d1
  double v64; // d2
  double v65; // d3
  double v66; // d4
  double v67; // d5
  double v68; // d6
  double v69; // d7
  __int64 v70; // x23
  _QWORD *v71; // x25
  void *v72; // x24
  _QWORD *v73; // x27
  unsigned int v74; // w26
  __int64 v75; // x8
  int v76; // w12
  int v77; // w9
  unsigned int v78; // w28
  bool v79; // zf
  bool v80; // zf
  int v81; // w20
  unsigned int v82; // w13
  int v83; // w14
  unsigned int v84; // w9
  __int64 v85; // x22
  unsigned int v86; // w10
  int v87; // w8
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  int v96; // w8
  int v97; // w10
  int v98; // w8
  bool v99; // cc
  unsigned int v100; // w8
  __int64 v101; // x20
  __int64 v102; // x8
  int v103; // w8
  int *v104; // x22
  int v105; // t1
  int v106; // w9
  int v107; // w8
  int v108; // w10
  int v109; // w8
  bool v110; // cc
  int v111; // w10
  int v112; // w8
  bool v113; // cc
  int v114; // w10
  int v115; // w8
  bool v116; // cc
  int v117; // w10
  int v118; // w8
  bool v119; // cc
  int v120; // w10
  int v121; // w8
  bool v122; // cc
  int v123; // w10
  int v124; // w8
  bool v125; // cc
  int v126; // w10
  int v127; // w8
  bool v128; // cc
  int v129; // w10
  int v130; // w8
  bool v131; // cc
  int v132; // w10
  int v133; // w8
  bool v134; // cc
  int v135; // w10
  int v136; // w8
  bool v137; // cc
  int v138; // w10
  int v139; // w8
  bool v140; // cc
  int v141; // w10
  int v142; // w8
  bool v143; // cc
  int v144; // w10
  int v145; // w8
  bool v146; // cc
  int v147; // w10
  int v148; // w8
  bool v149; // cc
  int v150; // w10
  int v151; // w8
  bool v152; // cc
  int v153; // w10
  int v154; // w8
  bool v155; // cc
  int v156; // w10
  int v157; // w8
  bool v158; // cc
  __int64 v159; // x9
  int v160; // t1
  int v161; // w9
  bool v162; // cc
  int v163; // w10
  int v164; // w8
  bool v165; // cc
  int v166; // w10
  int v167; // w8
  bool v168; // cc
  int v169; // w10
  int v170; // w8
  bool v171; // cc
  int v172; // w10
  int v173; // w8
  bool v174; // cc
  int v175; // w10
  int v176; // w8
  bool v177; // cc
  int v178; // w10
  int v179; // w8
  bool v180; // cc
  int v181; // w10
  int v182; // w8
  bool v183; // cc
  int v184; // w10
  int v185; // w8
  bool v186; // cc
  int v187; // w10
  int v188; // w8
  bool v189; // cc
  int v190; // w10
  int v191; // w8
  bool v192; // cc
  int v193; // w10
  int v194; // w8
  bool v195; // cc
  int v196; // w10
  int v197; // w8
  bool v198; // cc
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  int v207; // w0
  __int64 v208; // x23
  __int64 v209; // x24
  __int64 v210; // x26
  int *v211; // x25
  int v212; // w9
  unsigned int *v213; // x8
  __int64 v214; // x8
  int v215; // w9
  int v216; // w11
  bool v217; // cc
  __int64 v218; // x3
  unsigned int *v219; // x22
  unsigned int v220; // w8
  int v221; // w9
  unsigned int v222; // w10
  unsigned int v223; // w11
  unsigned int v224; // w13
  unsigned int v225; // w12
  double v226; // d0
  double v227; // d1
  double v228; // d2
  double v229; // d3
  double v230; // d4
  double v231; // d5
  double v232; // d6
  double v233; // d7
  int v234; // w24
  unsigned int v235; // w27
  unsigned int v236; // w23
  unsigned int v237; // w25
  int v238; // w28
  unsigned int v239; // w26
  unsigned int v240; // w0
  __int64 v241; // x11
  unsigned int v242; // w8
  unsigned __int64 v243; // x9
  __int64 v244; // x10
  __int64 v245; // x11
  bool v246; // w12
  int v247; // w9
  unsigned int v248; // w8
  char v249; // w20
  __int64 v250; // x8
  int *v251; // x9
  int v252; // t1
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  int v261; // w9
  unsigned int v262; // w8
  _BYTE *v263; // x0
  unsigned int v264; // w1
  int v265; // w16
  int v266; // w14
  int v267; // w13
  int v268; // w12
  int v269; // w11
  int v270; // w15
  int v271; // w8
  unsigned int v272; // w9
  unsigned int v273; // w10
  int v274; // w17
  unsigned int v275; // w16
  int v276; // w1
  int v277; // w15
  unsigned __int16 v278; // w0
  unsigned int v279; // w17
  unsigned int v280; // w15
  unsigned int v281; // w0
  unsigned int v282; // w20
  unsigned int v283; // w26
  _DWORD *channel_status; // x0
  unsigned int v285; // w8
  int v286; // w9
  int v287; // w15
  unsigned int v288; // w14
  int v289; // w17
  unsigned int v290; // w16
  unsigned int v291; // w14
  unsigned int v292; // w28
  int v293; // w14
  unsigned int v294; // w13
  int v295; // w15
  unsigned int v296; // w16
  unsigned int v297; // w14
  unsigned int v298; // w16
  unsigned int v299; // w13
  int v300; // w13
  unsigned int v301; // w12
  int v302; // w14
  unsigned int v303; // w13
  unsigned int v304; // w26
  unsigned int v305; // w12
  int v306; // w12
  unsigned int v307; // w11
  int v308; // w13
  unsigned int v309; // w12
  unsigned int v310; // w27
  int v311; // w20
  const char *v312; // x2
  unsigned int v313; // w11
  int v314; // w4
  int v315; // w8
  const char *v316; // x2
  unsigned int v317; // w8
  int v318; // w9
  int v319; // w12
  int v320; // w10
  unsigned int v321; // w8
  __int64 v322; // x8
  unsigned int v323; // w1
  char v324; // w27
  __int64 v325; // x10
  __int64 v326; // x9
  unsigned __int8 *v327; // x11
  unsigned int v328; // w20
  __int64 v329; // x8
  unsigned __int8 *v330; // x9
  int v331; // w8
  char v332; // w9
  unsigned int v333; // w8
  double v334; // d0
  double v335; // d1
  double v336; // d2
  double v337; // d3
  double v338; // d4
  double v339; // d5
  double v340; // d6
  double v341; // d7
  unsigned int v342; // w8
  unsigned int v343; // w9
  unsigned int v344; // w4
  int v345; // w0
  __int64 v346; // x20
  unsigned __int64 v347; // x22
  __int64 v348; // x25
  __int64 v349; // x8
  double v350; // d0
  double v351; // d1
  double v352; // d2
  double v353; // d3
  double v354; // d4
  double v355; // d5
  double v356; // d6
  double v357; // d7
  unsigned int v358; // w20
  unsigned int v359; // w20
  unsigned int v360; // w20
  int v361; // w8
  int v362; // w26
  signed int next_lower_bandwidth; // w22
  int v364; // w8
  __int64 v365; // x0
  char v366; // w1
  int v367; // w0
  int v368; // w20
  __int64 v369; // x27
  __int64 v370; // x0
  double v371; // d0
  double v372; // d1
  double v373; // d2
  double v374; // d3
  double v375; // d4
  double v376; // d5
  double v377; // d6
  double v378; // d7
  unsigned __int64 v379; // x20
  __int64 v380; // x23
  double v381; // d0
  double v382; // d1
  double v383; // d2
  double v384; // d3
  double v385; // d4
  double v386; // d5
  double v387; // d6
  double v388; // d7
  unsigned __int64 v389; // x23
  __int64 v390; // x0
  int v391; // w0
  __int64 v392; // x27
  __int64 v393; // x0
  double v394; // d0
  double v395; // d1
  double v396; // d2
  double v397; // d3
  double v398; // d4
  double v399; // d5
  double v400; // d6
  double v401; // d7
  unsigned __int64 v402; // x26
  unsigned int *v403; // x20
  _BYTE *v404; // x23
  double v405; // d0
  double v406; // d1
  double v407; // d2
  double v408; // d3
  double v409; // d4
  double v410; // d5
  double v411; // d6
  double v412; // d7
  unsigned int v413; // w2
  unsigned __int64 v414; // x8
  unsigned int v415; // w9
  __int64 v416; // x23
  unsigned int v417; // w28
  unsigned int v418; // w9
  int v419; // w0
  unsigned int v420; // w8
  unsigned int v421; // w2
  bool v422; // cc
  int v423; // w9
  int v424; // w0
  unsigned int v425; // w8
  unsigned int v426; // w2
  bool v427; // cc
  int v428; // w9
  int v429; // w0
  unsigned int v430; // w8
  unsigned int v431; // w2
  int v432; // w8
  int v433; // w8
  int v434; // w0
  unsigned int v435; // w8
  int v436; // w23
  int v437; // w0
  double v438; // d0
  double v439; // d1
  double v440; // d2
  double v441; // d3
  double v442; // d4
  double v443; // d5
  double v444; // d6
  double v445; // d7
  unsigned int v446; // w8
  _DWORD *v447; // x8
  double v448; // d0
  double v449; // d1
  double v450; // d2
  double v451; // d3
  double v452; // d4
  double v453; // d5
  double v454; // d6
  double v455; // d7
  double v456; // d0
  double v457; // d1
  double v458; // d2
  double v459; // d3
  double v460; // d4
  double v461; // d5
  double v462; // d6
  double v463; // d7
  unsigned __int64 v464; // x8
  int v465; // w4
  int v466; // w0
  unsigned int v467; // w8
  __int64 v468; // x26
  _BYTE *v469; // x20
  double v470; // d0
  double v471; // d1
  double v472; // d2
  double v473; // d3
  double v474; // d4
  double v475; // d5
  double v476; // d6
  double v477; // d7
  unsigned __int64 v478; // x8
  unsigned int v479; // w9
  int v480; // w10
  _DWORD *v481; // x12
  __int64 v482; // x11
  unsigned int v483; // w25
  _BYTE *v484; // x20
  int v485; // w28
  _DWORD *v486; // x8
  int v487; // w0
  unsigned int v488; // w9
  int v489; // w10
  __int64 v490; // x22
  char v491; // w8
  int v492; // w22
  unsigned __int64 v493; // x8
  int v494; // w0
  unsigned int *v495; // x20
  unsigned __int64 v496; // x23
  __int64 v497; // x0
  int v498; // w0
  __int64 v499; // x26
  __int64 v500; // x0
  double v501; // d0
  double v502; // d1
  double v503; // d2
  double v504; // d3
  double v505; // d4
  double v506; // d5
  double v507; // d6
  double v508; // d7
  unsigned __int64 v509; // x23
  unsigned __int64 v510; // x23
  double v511; // d0
  double v512; // d1
  double v513; // d2
  double v514; // d3
  double v515; // d4
  double v516; // d5
  double v517; // d6
  double v518; // d7
  unsigned int *v519; // x20
  __int64 v520; // x23
  unsigned __int64 v521; // x25
  unsigned int *v522; // x28
  unsigned int v523; // t1
  unsigned __int8 v524; // w0
  unsigned __int64 v525; // x8
  unsigned int *v526; // x25
  unsigned int v527; // w11
  unsigned int v528; // w9
  unsigned int v529; // w12
  unsigned int v530; // w8
  unsigned int v531; // w10
  unsigned int v532; // w8
  unsigned int v533; // w9
  unsigned int v534; // w8
  __int64 v535; // x0
  int v536; // w0
  int v537; // w25
  int v538; // w0
  unsigned __int8 v539; // w8
  unsigned __int64 v540; // x9
  unsigned int *v541; // x12
  unsigned int v542; // w8
  int v543; // w0
  unsigned __int8 v544; // w8
  unsigned __int64 v545; // x9
  unsigned int *v546; // x11
  unsigned int *v547; // x27
  __int64 v548; // x0
  double v549; // d0
  double v550; // d1
  double v551; // d2
  double v552; // d3
  double v553; // d4
  double v554; // d5
  double v555; // d6
  double v556; // d7
  unsigned int v557; // w8
  __int64 v558; // x23
  unsigned int v559; // w25
  int v560; // w20
  unsigned int *v561; // x27
  int v562; // w0
  __int64 v563; // x27
  _BYTE *v564; // x20
  double v565; // d0
  double v566; // d1
  double v567; // d2
  double v568; // d3
  double v569; // d4
  double v570; // d5
  double v571; // d6
  double v572; // d7
  unsigned int v573; // w8
  unsigned __int64 v574; // x9
  int v575; // w10
  _DWORD *v576; // x12
  __int64 v577; // x25
  unsigned int v578; // w28
  __int64 v579; // x20
  int v580; // w11
  unsigned int v581; // w8
  unsigned int v582; // w2
  bool v583; // cc
  int is_channel_present_in_acs_list; // w0
  int v585; // w25
  unsigned __int64 v586; // x8
  int v587; // w0
  unsigned int v588; // w8
  int v589; // w10
  _DWORD *v590; // x9
  __int64 v591; // x0
  unsigned int *v592; // x20
  __int64 v593; // x0
  __int64 v594; // x27
  unsigned __int64 v595; // x26
  unsigned int *v596; // x23
  double v597; // d0
  double v598; // d1
  double v599; // d2
  double v600; // d3
  double v601; // d4
  double v602; // d5
  double v603; // d6
  double v604; // d7
  unsigned int v605; // w2
  unsigned int v606; // w8
  unsigned int v607; // w9
  int v608; // w0
  unsigned int v609; // w8
  unsigned int v610; // w2
  _BOOL4 v611; // w25
  int v612; // w27
  double v613; // d0
  double v614; // d1
  double v615; // d2
  double v616; // d3
  double v617; // d4
  double v618; // d5
  double v619; // d6
  double v620; // d7
  unsigned __int64 v621; // x8
  int v622; // w0
  unsigned int v623; // w8
  double v624; // d0
  double v625; // d1
  double v626; // d2
  double v627; // d3
  double v628; // d4
  double v629; // d5
  double v630; // d6
  double v631; // d7
  __int64 v632; // x0
  const char *v633; // x2
  const char *v634; // x3
  __int64 v635; // x0
  unsigned int v636; // w8
  _BYTE *v637; // x9
  unsigned int v638; // w20
  __int64 v639; // x24
  unsigned int *v640; // x23
  __int64 v641; // x0
  double v642; // d0
  double v643; // d1
  double v644; // d2
  double v645; // d3
  double v646; // d4
  double v647; // d5
  double v648; // d6
  double v649; // d7
  __int64 v650; // x21
  double v651; // d0
  double v652; // d1
  double v653; // d2
  double v654; // d3
  double v655; // d4
  double v656; // d5
  double v657; // d6
  double v658; // d7
  unsigned int v659; // w8
  unsigned int v660; // w28
  int v661; // w25
  _BYTE *v662; // x26
  unsigned int v663; // w4
  int v664; // w0
  int v665; // [xsp+40h] [xbp-110h]
  int v666; // [xsp+44h] [xbp-10Ch]
  int v667; // [xsp+48h] [xbp-108h]
  int v668; // [xsp+4Ch] [xbp-104h]
  int v669; // [xsp+50h] [xbp-100h]
  int v670; // [xsp+54h] [xbp-FCh]
  int v671; // [xsp+58h] [xbp-F8h]
  int v672; // [xsp+58h] [xbp-F8h]
  int v673; // [xsp+5Ch] [xbp-F4h]
  unsigned int v674; // [xsp+5Ch] [xbp-F4h]
  int v675; // [xsp+5Ch] [xbp-F4h]
  int v676; // [xsp+60h] [xbp-F0h]
  int v677; // [xsp+60h] [xbp-F0h]
  int v678; // [xsp+64h] [xbp-ECh]
  int v679; // [xsp+64h] [xbp-ECh]
  int v680; // [xsp+64h] [xbp-ECh]
  int v681; // [xsp+68h] [xbp-E8h]
  int v682; // [xsp+68h] [xbp-E8h]
  int v683; // [xsp+68h] [xbp-E8h]
  int v684; // [xsp+68h] [xbp-E8h]
  int v685; // [xsp+6Ch] [xbp-E4h]
  int v686; // [xsp+6Ch] [xbp-E4h]
  int v687; // [xsp+6Ch] [xbp-E4h]
  int v688; // [xsp+70h] [xbp-E0h]
  int v689; // [xsp+70h] [xbp-E0h]
  int v690; // [xsp+70h] [xbp-E0h]
  int v691; // [xsp+74h] [xbp-DCh]
  int v692; // [xsp+74h] [xbp-DCh]
  int v693; // [xsp+74h] [xbp-DCh]
  int v694; // [xsp+78h] [xbp-D8h]
  unsigned int v695; // [xsp+78h] [xbp-D8h]
  int v696; // [xsp+78h] [xbp-D8h]
  int v697; // [xsp+7Ch] [xbp-D4h]
  signed int v698; // [xsp+7Ch] [xbp-D4h]
  int v699; // [xsp+7Ch] [xbp-D4h]
  int v700; // [xsp+7Ch] [xbp-D4h]
  int is_sap_freq_allowed; // [xsp+80h] [xbp-D0h]
  int v702; // [xsp+80h] [xbp-D0h]
  unsigned int v703; // [xsp+80h] [xbp-D0h]
  int v704; // [xsp+80h] [xbp-D0h]
  int v705; // [xsp+84h] [xbp-CCh]
  int v706; // [xsp+84h] [xbp-CCh]
  int v707; // [xsp+84h] [xbp-CCh]
  int v708; // [xsp+84h] [xbp-CCh]
  signed int v709; // [xsp+88h] [xbp-C8h]
  int v710; // [xsp+88h] [xbp-C8h]
  int v711; // [xsp+88h] [xbp-C8h]
  int v712; // [xsp+88h] [xbp-C8h]
  int v713; // [xsp+94h] [xbp-BCh]
  unsigned int v714; // [xsp+94h] [xbp-BCh]
  int v715; // [xsp+94h] [xbp-BCh]
  int v716; // [xsp+94h] [xbp-BCh]
  int v717; // [xsp+94h] [xbp-BCh]
  unsigned int v718; // [xsp+98h] [xbp-B8h]
  unsigned int v719; // [xsp+98h] [xbp-B8h]
  int v720; // [xsp+98h] [xbp-B8h]
  unsigned int v721; // [xsp+98h] [xbp-B8h]
  int v722; // [xsp+A0h] [xbp-B0h]
  unsigned int v723; // [xsp+A0h] [xbp-B0h]
  int v724; // [xsp+A0h] [xbp-B0h]
  __int64 v725; // [xsp+A0h] [xbp-B0h]
  unsigned int v726; // [xsp+A8h] [xbp-A8h]
  int v727; // [xsp+A8h] [xbp-A8h]
  signed int v728; // [xsp+A8h] [xbp-A8h]
  int v730; // [xsp+ACh] [xbp-A4h]
  int v733; // [xsp+C0h] [xbp-90h]
  unsigned int v734; // [xsp+C0h] [xbp-90h]
  unsigned int v735; // [xsp+C0h] [xbp-90h]
  __int64 v736; // [xsp+C0h] [xbp-90h]
  __int64 v737; // [xsp+C0h] [xbp-90h]
  unsigned int v738; // [xsp+C0h] [xbp-90h]
  unsigned int v740; // [xsp+C8h] [xbp-88h]
  int v741; // [xsp+C8h] [xbp-88h]
  int v742; // [xsp+C8h] [xbp-88h]
  int v743; // [xsp+C8h] [xbp-88h]
  int v744; // [xsp+C8h] [xbp-88h]
  __int64 v745; // [xsp+D0h] [xbp-80h]
  __int64 v746; // [xsp+D0h] [xbp-80h]
  unsigned int v747; // [xsp+D0h] [xbp-80h]
  unsigned int v748; // [xsp+D0h] [xbp-80h]
  unsigned int v749; // [xsp+D0h] [xbp-80h]
  int opmode_from_vdev_id; // [xsp+D8h] [xbp-78h]
  unsigned __int64 v751; // [xsp+D8h] [xbp-78h]
  unsigned int v752; // [xsp+D8h] [xbp-78h]
  int v753; // [xsp+D8h] [xbp-78h]
  _BOOL4 v754; // [xsp+E0h] [xbp-70h]
  unsigned __int64 v755; // [xsp+E0h] [xbp-70h]
  unsigned int v756; // [xsp+E0h] [xbp-70h]
  unsigned int v757; // [xsp+E0h] [xbp-70h]
  int v758; // [xsp+E0h] [xbp-70h]
  int v759; // [xsp+E0h] [xbp-70h]
  int v760; // [xsp+E0h] [xbp-70h]
  __int64 v761; // [xsp+E8h] [xbp-68h]
  int v762; // [xsp+F4h] [xbp-5Ch] BYREF
  _QWORD *v763; // [xsp+F8h] [xbp-58h] BYREF
  int v764; // [xsp+100h] [xbp-50h] BYREF
  char v765; // [xsp+104h] [xbp-4Ch]
  __int16 v766; // [xsp+108h] [xbp-48h]
  unsigned __int16 v767; // [xsp+10Ch] [xbp-44h]
  __int64 v768; // [xsp+110h] [xbp-40h] BYREF
  __int64 v769; // [xsp+118h] [xbp-38h]
  __int64 v770; // [xsp+120h] [xbp-30h]
  __int16 v771; // [xsp+12Ch] [xbp-24h] BYREF
  char v772; // [xsp+12Eh] [xbp-22h]
  _QWORD *v773[4]; // [xsp+130h] [xbp-20h] BYREF

  v773[2] = *(_QWORD **)(_ReadStatusReg(SP_EL0) + 1808);
  v772 = 0;
  v771 = 0;
  v762 = 0;
  if ( a2 >= 6u )
LABEL_997:
    __break(0x5512u);
  v17 = *(_QWORD *)(a1 + 16LL * a2 + 14888);
  v18 = *(_QWORD *)(v17 + 1544);
  if ( !v18 )
  {
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: vdev %d sap acs_cfg is null",
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      a15,
      "sap_sort_channel_list",
      a2);
    result = 29;
    goto LABEL_48;
  }
  v19 = *(_QWORD *)(a1 + 21632);
  v20 = *(_BYTE *)(v17 + 12);
  v22 = *(unsigned __int16 *)(v18 + 42);
  v761 = v17;
  LOBYTE(v768) = 0;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(v19, v20);
  if ( opmode_from_vdev_id == 17 )
    goto LABEL_46;
  v31 = *(unsigned __int8 *)(a1 + 16604);
  a4[8] = v31;
  v32 = _qdf_mem_malloc(24 * v31, "sap_chan_sel_init", 448);
  if ( !v32 )
    goto LABEL_46;
  *(_QWORD *)a4 = v32;
  v33 = (unsigned int *)v32;
  policy_mgr_get_sta_sap_scc_on_dfs_chnl(*(_QWORD *)(a1 + 21624), &v768);
  v754 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3368LL) == 1 && *(_DWORD *)(v761 + 1636) != 2;
  v35 = _qdf_mem_malloc(0x96u, "sap_chan_sel_init", 467);
  if ( !v35 )
  {
LABEL_46:
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: vdev %d ch select initialization failed",
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      "sap_sort_channel_list",
      a2);
    goto LABEL_47;
  }
  v36 = v35;
  v709 = v22;
  if ( a4[8] )
  {
    v37 = 0;
    v38 = 0;
    v39 = 0;
    v40 = (unsigned int *)(a1 + 16608);
    while ( 1 )
    {
      *v33 = *v40;
      *((_QWORD *)v33 + 1) = 0x6828FFFFFF9CLL;
      if ( v38 >= 0x8B )
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "ACS Invalid freq(%d): %s",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          (unsigned __int8)v37,
          v36);
        v38 = 0;
        v37 = 0;
      }
      is_channel_in_nol_list = sap_dfs_is_channel_in_nol_list(v761, *v40, 0);
      if ( (is_channel_in_nol_list & 1) != 0 )
      {
        is_puncture_applicable = sap_acs_is_puncture_applicable(*(_QWORD *)(v761 + 1544));
        v51 = v36 + v38;
        v52 = *v40;
        ++v37;
        v53 = 150 - v38;
        if ( (is_puncture_applicable & 1) == 0 )
        {
          v58 = 0;
          goto LABEL_38;
        }
        v42 = scnprintf(v51, v53, "%d[%d] ", v52, 1);
        v38 += v54;
      }
      if ( (!v754 || (unsigned __int8)v768 == 1
                  && (policy_mgr_is_sta_sap_scc(*(_QWORD *)(a1 + 21624), *v33, 1) & 1) == 0)
        && (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), *v33, v42, v43, v44, v45, v46, v47, v48, v49) & 1) != 0 )
      {
        v23 = scnprintf(v36 + v38, 150 - v38, "%d[%d] ", *v33, 2);
        goto LABEL_41;
      }
      if ( (policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21624), opmode_from_vdev_id, *v40) & 1) != 0 )
        goto LABEL_26;
      v56 = sap_acs_is_puncture_applicable(*(_QWORD *)(v761 + 1544));
      v51 = v36 + v38;
      v52 = *v40;
      ++v37;
      v53 = 150 - v38;
      if ( (v56 & 1) != 0 )
      {
        scnprintf(v51, v53, "%d[%d] ", v52, 4);
        is_channel_in_nol_list = 1;
        v38 += v57;
LABEL_26:
        if ( *v40 == 2484 && *(_DWORD *)(v761 + 1484) != 4 )
        {
          v23 = scnprintf(v36 + v38, 150 - v38, "%d[%d] ", 2484, 5);
        }
        else if ( (wlan_reg_is_dsrc_freq() & 1) != 0 )
        {
          v23 = scnprintf(v36 + v38, 150 - v38, "%d[%d] ", *v33, 6);
        }
        else if ( (policy_mgr_is_sap_go_interface_allowed_on_indoor(
                     *(_QWORD *)(a1 + 21632),
                     *(unsigned __int8 *)(v761 + 12),
                     *v40)
                 & 1) != 0 )
        {
          if ( (wlansap_is_channel_present_in_acs_list(
                  *v40,
                  *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                  *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL))
              & 1) != 0 )
            goto LABEL_35;
          if ( (wlansap_is_channel_present_in_acs_list(
                  *v33,
                  *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 32LL),
                  *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 40LL))
              & 1) != 0 )
          {
            v33[3] = 26663;
LABEL_35:
            *((_BYTE *)v33 + 20) = 1;
            if ( (is_channel_in_nol_list & 1) == 0 )
              v33[3] = 0;
            goto LABEL_43;
          }
          v23 = scnprintf(v36 + v38, 150 - v38, "%d[%d] ", *v40, 8);
        }
        else
        {
          v23 = scnprintf(v36 + v38, 150 - v38, "%d[%d] ", *v40, 7);
        }
LABEL_41:
        ++v37;
        goto LABEL_42;
      }
      v58 = 3;
LABEL_38:
      v23 = scnprintf(v51, v53, "%d[%d] ", v52, v58);
LABEL_42:
      v38 += v55;
LABEL_43:
      ++v39;
      ++v40;
      v33 += 6;
      if ( v39 >= (unsigned __int8)a4[8] )
      {
        if ( v38 )
          qdf_trace_msg(
            0x39u,
            8u,
            "ACS Invalid freq(%d): %s",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            (unsigned __int8)v37,
            v36);
        break;
      }
    }
  }
  _qdf_mem_free(v36);
  v59 = *(_QWORD *)a4;
  v60 = (unsigned __int8)a4[8];
  v773[0] = nullptr;
  v763 = nullptr;
  v751 = v59;
  v768 = 0;
  v769 = 0;
  v61 = _qdf_mem_malloc(0x96u, "sap_compute_spect_weight", 1712);
  if ( !v61 )
    goto LABEL_650;
  v70 = v761;
  v71 = a3;
  v72 = (void *)v61;
  v745 = v61;
  if ( a3 )
  {
    qdf_list_peek_front(a3, v773);
    v73 = v773[0];
    if ( v773[0] )
    {
      v74 = 0;
      v755 = v751 + 24LL * v60;
      while ( 1 )
      {
        v75 = v73[3];
        v76 = 0;
        v77 = *(_DWORD *)(v75 + 52);
        v78 = *(_DWORD *)(v75 + 1192);
        if ( v77 <= 22 )
        {
          if ( v77 <= 12 )
          {
            v81 = 0;
            v82 = 0;
            v83 = 0;
            if ( (unsigned int)(v77 - 7) >= 4 )
              goto LABEL_88;
          }
          else if ( v77 >= 17 )
          {
            if ( (unsigned int)(v77 - 17) >= 2 )
            {
              if ( v77 == 19 )
                goto LABEL_83;
              v80 = v77 == 20;
              goto LABEL_69;
            }
            goto LABEL_87;
          }
        }
        else if ( v77 > 29 )
        {
          if ( v77 > 36 )
          {
            if ( v77 != 37 )
            {
              v79 = v77 == 39;
LABEL_81:
              v81 = 0;
              v82 = 0;
              v83 = 0;
              if ( v79 )
              {
LABEL_83:
                v82 = *(_DWORD *)(v75 + 1200);
                if ( !v82 )
                  v82 = *(_DWORD *)(v75 + 1196);
                v81 = 0;
                v83 = 0;
                v76 = 3;
                v84 = (unsigned __int8)a4[8];
                if ( !a4[8] )
                  goto LABEL_55;
LABEL_89:
                v85 = *(_QWORD *)a4;
                v86 = 0;
                while ( v78 != *(_DWORD *)v85 )
                {
                  ++v86;
                  v85 += 24;
                  if ( v86 >= v84 )
                    goto LABEL_55;
                }
                v87 = *(char *)(v75 + 60);
                v713 = v83;
                v726 = v82;
                v733 = v76;
                if ( *(_DWORD *)(v85 + 8) < v87 )
                  *(_DWORD *)(v85 + 8) = v87;
                ++*(_WORD *)(v85 + 4);
                v718 = v74;
                if ( wlan_reg_is_24ghz_ch_freq(v78) )
                {
                  if ( v85 )
                  {
                    v96 = (unsigned __int8)wlan_reg_freq_to_chan(
                                             *(_QWORD *)(a1 + 21632),
                                             *(_DWORD *)v85,
                                             v88,
                                             v89,
                                             v90,
                                             v91,
                                             v92,
                                             v93,
                                             v94,
                                             v95);
                    if ( (unsigned int)v96 <= 4 )
                    {
                      if ( v96 > 2 )
                      {
                        if ( v96 != 3 )
                          goto LABEL_212;
                        goto LABEL_223;
                      }
                      if ( v96 == 1 )
                        goto LABEL_245;
                      if ( v96 == 2 )
                        goto LABEL_234;
                    }
                    else if ( v96 >= 11 )
                    {
                      if ( v96 > 12 )
                      {
                        if ( v96 == 13 )
                        {
                          if ( v85 - 96 < v755
                            && v85 != 96
                            && v85 - 96 >= v751
                            && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 96)) & 1) != 0 )
                          {
                            v184 = *(_DWORD *)(v85 - 88);
                            v185 = *(_DWORD *)(v85 + 8) - 40;
                            v186 = v184 < v185;
                            ++*(_WORD *)(v85 - 92);
                            if ( v184 > v185 )
                              v185 = v184;
                            if ( v186 || v185 <= -101 )
                            {
                              if ( v185 <= -100 )
                                v185 = -100;
                              *(_DWORD *)(v85 - 88) = v185;
                            }
                          }
                          if ( v85 - 72 < v755
                            && v85 != 72
                            && v85 - 72 >= v751
                            && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 72)) & 1) != 0 )
                          {
                            v187 = *(_DWORD *)(v85 - 64);
                            v188 = *(_DWORD *)(v85 + 8) - 30;
                            v189 = v187 < v188;
                            ++*(_WORD *)(v85 - 68);
                            if ( v187 > v188 )
                              v188 = v187;
                            if ( v189 || v188 <= -101 )
                            {
                              if ( v188 <= -100 )
                                v188 = -100;
                              *(_DWORD *)(v85 - 64) = v188;
                            }
                          }
                          if ( v85 - 48 < v755
                            && v85 != 48
                            && v85 - 48 >= v751
                            && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 48)) & 1) != 0 )
                          {
                            v190 = *(_DWORD *)(v85 - 40);
                            v191 = *(_DWORD *)(v85 + 8) - 20;
                            v192 = v190 < v191;
                            ++*(_WORD *)(v85 - 44);
                            if ( v190 > v191 )
                              v191 = v190;
                            if ( v192 || v191 <= -101 )
                            {
                              if ( v191 <= -100 )
                                v191 = -100;
                              *(_DWORD *)(v85 - 40) = v191;
                            }
                          }
                          if ( v85 - 24 < v755
                            && v85 != 24
                            && v85 - 24 >= v751
                            && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 24)) & 1) != 0 )
                          {
                            v193 = *(_DWORD *)(v85 - 16);
                            v194 = *(_DWORD *)(v85 + 8) - 10;
                            v195 = v193 < v194;
                            ++*(_WORD *)(v85 - 20);
                            if ( v193 > v194 )
                              v194 = v193;
                            if ( v195 || v194 <= -101 )
                            {
                              if ( v194 <= -100 )
                                v194 = -100;
                              *(_DWORD *)(v85 - 16) = v194;
                            }
                          }
                          if ( v85 + 24 < v755
                            && v85 != -24
                            && v85 + 24 >= v751
                            && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 24)) & 1) != 0 )
                          {
                            v196 = *(_DWORD *)(v85 + 32);
                            v197 = *(_DWORD *)(v85 + 8) - 10;
                            v198 = v196 < v197;
                            ++*(_WORD *)(v85 + 28);
                            if ( v196 > v197 )
                              v197 = v196;
                            if ( v198 || v197 <= -101 )
                            {
                              if ( v197 <= -100 )
                                v197 = -100;
                              *(_DWORD *)(v85 + 32) = v197;
                            }
                          }
                        }
                        else if ( v96 == 14 )
                        {
                          if ( v85 - 96 < v755
                            && v85 != 96
                            && v85 - 96 >= v751
                            && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 96)) & 1) != 0 )
                          {
                            v147 = *(_DWORD *)(v85 - 88);
                            v148 = *(_DWORD *)(v85 + 8) - 40;
                            v149 = v147 < v148;
                            ++*(_WORD *)(v85 - 92);
                            if ( v147 > v148 )
                              v148 = v147;
                            if ( v149 || v148 <= -101 )
                            {
                              if ( v148 <= -100 )
                                v148 = -100;
                              *(_DWORD *)(v85 - 88) = v148;
                            }
                          }
                          if ( v85 - 72 < v755
                            && v85 != 72
                            && v85 - 72 >= v751
                            && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 72)) & 1) != 0 )
                          {
                            v150 = *(_DWORD *)(v85 - 64);
                            v151 = *(_DWORD *)(v85 + 8) - 30;
                            v152 = v150 < v151;
                            ++*(_WORD *)(v85 - 68);
                            if ( v150 > v151 )
                              v151 = v150;
                            if ( v152 || v151 <= -101 )
                            {
                              if ( v151 <= -100 )
                                v151 = -100;
                              *(_DWORD *)(v85 - 64) = v151;
                            }
                          }
                          if ( v85 - 48 < v755
                            && v85 != 48
                            && v85 - 48 >= v751
                            && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 48)) & 1) != 0 )
                          {
                            v153 = *(_DWORD *)(v85 - 40);
                            v154 = *(_DWORD *)(v85 + 8) - 20;
                            v155 = v153 < v154;
                            ++*(_WORD *)(v85 - 44);
                            if ( v153 > v154 )
                              v154 = v153;
                            if ( v155 || v154 <= -101 )
                            {
                              if ( v154 <= -100 )
                                v154 = -100;
                              *(_DWORD *)(v85 - 40) = v154;
                            }
                          }
                          if ( v85 - 24 < v755
                            && v85 != 24
                            && v85 - 24 >= v751
                            && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 24)) & 1) != 0 )
                          {
                            v156 = *(_DWORD *)(v85 - 16);
                            v157 = *(_DWORD *)(v85 + 8) - 10;
                            v158 = v156 < v157;
                            ++*(_WORD *)(v85 - 20);
                            if ( v156 > v157 )
                              v157 = v156;
                            if ( v158 || v157 <= -101 )
                            {
                              if ( v157 <= -100 )
                                v157 = -100;
                              *(_DWORD *)(v85 - 16) = v157;
                            }
                          }
                        }
                      }
                      else if ( v96 == 11 )
                      {
                        if ( v85 - 96 < v755
                          && v85 != 96
                          && v85 - 96 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 96)) & 1) != 0 )
                        {
                          v163 = *(_DWORD *)(v85 - 88);
                          v164 = *(_DWORD *)(v85 + 8) - 40;
                          v165 = v163 < v164;
                          ++*(_WORD *)(v85 - 92);
                          if ( v163 > v164 )
                            v164 = v163;
                          if ( v165 || v164 <= -101 )
                          {
                            if ( v164 <= -100 )
                              v164 = -100;
                            *(_DWORD *)(v85 - 88) = v164;
                          }
                        }
                        if ( v85 - 72 < v755
                          && v85 != 72
                          && v85 - 72 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 72)) & 1) != 0 )
                        {
                          v166 = *(_DWORD *)(v85 - 64);
                          v167 = *(_DWORD *)(v85 + 8) - 30;
                          v168 = v166 < v167;
                          ++*(_WORD *)(v85 - 68);
                          if ( v166 > v167 )
                            v167 = v166;
                          if ( v168 || v167 <= -101 )
                          {
                            if ( v167 <= -100 )
                              v167 = -100;
                            *(_DWORD *)(v85 - 64) = v167;
                          }
                        }
                        if ( v85 - 48 < v755
                          && v85 != 48
                          && v85 - 48 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 48)) & 1) != 0 )
                        {
                          v169 = *(_DWORD *)(v85 - 40);
                          v170 = *(_DWORD *)(v85 + 8) - 20;
                          v171 = v169 < v170;
                          ++*(_WORD *)(v85 - 44);
                          if ( v169 > v170 )
                            v170 = v169;
                          if ( v171 || v170 <= -101 )
                          {
                            if ( v170 <= -100 )
                              v170 = -100;
                            *(_DWORD *)(v85 - 40) = v170;
                          }
                        }
                        if ( v85 - 24 < v755
                          && v85 != 24
                          && v85 - 24 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 24)) & 1) != 0 )
                        {
                          v172 = *(_DWORD *)(v85 - 16);
                          v173 = *(_DWORD *)(v85 + 8) - 10;
                          v174 = v172 < v173;
                          ++*(_WORD *)(v85 - 20);
                          if ( v172 > v173 )
                            v173 = v172;
                          if ( v174 || v173 <= -101 )
                          {
                            if ( v173 <= -100 )
                              v173 = -100;
                            *(_DWORD *)(v85 - 16) = v173;
                          }
                        }
                        if ( v85 + 24 < v755
                          && v85 != -24
                          && v85 + 24 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 24)) & 1) != 0 )
                        {
                          v175 = *(_DWORD *)(v85 + 32);
                          v176 = *(_DWORD *)(v85 + 8) - 10;
                          v177 = v175 < v176;
                          ++*(_WORD *)(v85 + 28);
                          if ( v175 > v176 )
                            v176 = v175;
                          if ( v177 || v176 <= -101 )
                          {
                            if ( v176 <= -100 )
                              v176 = -100;
                            *(_DWORD *)(v85 + 32) = v176;
                          }
                        }
                        if ( v85 + 48 < v755
                          && v85 != -48
                          && v85 + 48 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 48)) & 1) != 0 )
                        {
                          v178 = *(_DWORD *)(v85 + 56);
                          v179 = *(_DWORD *)(v85 + 8) - 20;
                          v180 = v178 < v179;
                          ++*(_WORD *)(v85 + 52);
                          if ( v178 > v179 )
                            v179 = v178;
                          if ( v180 || v179 <= -101 )
                          {
                            if ( v179 <= -100 )
                              v179 = -100;
                            *(_DWORD *)(v85 + 56) = v179;
                          }
                        }
                        if ( v85 + 72 < v755
                          && v85 != -72
                          && v85 + 72 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 72)) & 1) != 0 )
                        {
                          v181 = *(_DWORD *)(v85 + 80);
                          v182 = *(_DWORD *)(v85 + 8) - 30;
                          v183 = v181 < v182;
                          ++*(_WORD *)(v85 + 76);
                          if ( v181 > v182 )
                            v182 = v181;
                          if ( v183 || v182 <= -101 )
                          {
                            if ( v182 <= -100 )
                              v182 = -100;
                            *(_DWORD *)(v85 + 80) = v182;
                          }
                        }
                      }
                      else
                      {
                        if ( v85 - 96 < v755
                          && v85 != 96
                          && v85 - 96 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 96)) & 1) != 0 )
                        {
                          v108 = *(_DWORD *)(v85 - 88);
                          v109 = *(_DWORD *)(v85 + 8) - 40;
                          v110 = v108 < v109;
                          ++*(_WORD *)(v85 - 92);
                          if ( v108 > v109 )
                            v109 = v108;
                          if ( v110 || v109 <= -101 )
                          {
                            if ( v109 <= -100 )
                              v109 = -100;
                            *(_DWORD *)(v85 - 88) = v109;
                          }
                        }
                        if ( v85 - 72 < v755
                          && v85 != 72
                          && v85 - 72 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 72)) & 1) != 0 )
                        {
                          v111 = *(_DWORD *)(v85 - 64);
                          v112 = *(_DWORD *)(v85 + 8) - 30;
                          v113 = v111 < v112;
                          ++*(_WORD *)(v85 - 68);
                          if ( v111 > v112 )
                            v112 = v111;
                          if ( v113 || v112 <= -101 )
                          {
                            if ( v112 <= -100 )
                              v112 = -100;
                            *(_DWORD *)(v85 - 64) = v112;
                          }
                        }
                        if ( v85 - 48 < v755
                          && v85 != 48
                          && v85 - 48 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 48)) & 1) != 0 )
                        {
                          v114 = *(_DWORD *)(v85 - 40);
                          v115 = *(_DWORD *)(v85 + 8) - 20;
                          v116 = v114 < v115;
                          ++*(_WORD *)(v85 - 44);
                          if ( v114 > v115 )
                            v115 = v114;
                          if ( v116 || v115 <= -101 )
                          {
                            if ( v115 <= -100 )
                              v115 = -100;
                            *(_DWORD *)(v85 - 40) = v115;
                          }
                        }
                        if ( v85 - 24 < v755
                          && v85 != 24
                          && v85 - 24 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 24)) & 1) != 0 )
                        {
                          v117 = *(_DWORD *)(v85 - 16);
                          v118 = *(_DWORD *)(v85 + 8) - 10;
                          v119 = v117 < v118;
                          ++*(_WORD *)(v85 - 20);
                          if ( v117 > v118 )
                            v118 = v117;
                          if ( v119 || v118 <= -101 )
                          {
                            if ( v118 <= -100 )
                              v118 = -100;
                            *(_DWORD *)(v85 - 16) = v118;
                          }
                        }
                        if ( v85 + 24 < v755
                          && v85 != -24
                          && v85 + 24 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 24)) & 1) != 0 )
                        {
                          v120 = *(_DWORD *)(v85 + 32);
                          v121 = *(_DWORD *)(v85 + 8) - 10;
                          v122 = v120 < v121;
                          ++*(_WORD *)(v85 + 28);
                          if ( v120 > v121 )
                            v121 = v120;
                          if ( v122 || v121 <= -101 )
                          {
                            if ( v121 <= -100 )
                              v121 = -100;
                            *(_DWORD *)(v85 + 32) = v121;
                          }
                        }
                        if ( v85 + 48 < v755
                          && v85 != -48
                          && v85 + 48 >= v751
                          && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 48)) & 1) != 0 )
                        {
                          v123 = *(_DWORD *)(v85 + 56);
                          v124 = *(_DWORD *)(v85 + 8) - 20;
                          v125 = v123 < v124;
                          ++*(_WORD *)(v85 + 52);
                          if ( v123 > v124 )
                            v124 = v123;
                          if ( v125 || v124 <= -101 )
                          {
                            if ( v124 <= -100 )
                              v124 = -100;
                            *(_DWORD *)(v85 + 56) = v124;
                          }
                        }
                      }
                    }
                    else
                    {
                      if ( v85 - 96 < v755
                        && v85 != 96
                        && v85 - 96 >= v751
                        && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 96)) & 1) != 0 )
                      {
                        v97 = *(_DWORD *)(v85 - 88);
                        v98 = *(_DWORD *)(v85 + 8) - 40;
                        v99 = v97 < v98;
                        ++*(_WORD *)(v85 - 92);
                        if ( v97 > v98 )
                          v98 = v97;
                        if ( v99 || v98 <= -101 )
                        {
                          if ( v98 <= -100 )
                            v98 = -100;
                          *(_DWORD *)(v85 - 88) = v98;
                        }
                      }
LABEL_212:
                      if ( v85 - 72 < v755
                        && v85 != 72
                        && v85 - 72 >= v751
                        && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 72)) & 1) != 0 )
                      {
                        v126 = *(_DWORD *)(v85 - 64);
                        v127 = *(_DWORD *)(v85 + 8) - 30;
                        v128 = v126 < v127;
                        ++*(_WORD *)(v85 - 68);
                        if ( v126 > v127 )
                          v127 = v126;
                        if ( v128 || v127 <= -101 )
                        {
                          if ( v127 <= -100 )
                            v127 = -100;
                          *(_DWORD *)(v85 - 64) = v127;
                        }
                      }
LABEL_223:
                      if ( v85 - 48 < v755
                        && v85 != 48
                        && v85 - 48 >= v751
                        && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 48)) & 1) != 0 )
                      {
                        v129 = *(_DWORD *)(v85 - 40);
                        v130 = *(_DWORD *)(v85 + 8) - 20;
                        v131 = v129 < v130;
                        ++*(_WORD *)(v85 - 44);
                        if ( v129 > v130 )
                          v130 = v129;
                        if ( v131 || v130 <= -101 )
                        {
                          if ( v130 <= -100 )
                            v130 = -100;
                          *(_DWORD *)(v85 - 40) = v130;
                        }
                      }
LABEL_234:
                      if ( v85 - 24 < v755
                        && v85 != 24
                        && v85 - 24 >= v751
                        && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 24)) & 1) != 0 )
                      {
                        v132 = *(_DWORD *)(v85 - 16);
                        v133 = *(_DWORD *)(v85 + 8) - 10;
                        v134 = v132 < v133;
                        ++*(_WORD *)(v85 - 20);
                        if ( v132 > v133 )
                          v133 = v132;
                        if ( v134 || v133 <= -101 )
                        {
                          if ( v133 <= -100 )
                            v133 = -100;
                          *(_DWORD *)(v85 - 16) = v133;
                        }
                      }
LABEL_245:
                      if ( v85 + 24 < v755
                        && v85 != -24
                        && v85 + 24 >= v751
                        && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 24)) & 1) != 0 )
                      {
                        v135 = *(_DWORD *)(v85 + 32);
                        v136 = *(_DWORD *)(v85 + 8) - 10;
                        v137 = v135 < v136;
                        ++*(_WORD *)(v85 + 28);
                        if ( v135 > v136 )
                          v136 = v135;
                        if ( v137 || v136 <= -101 )
                        {
                          if ( v136 <= -100 )
                            v136 = -100;
                          *(_DWORD *)(v85 + 32) = v136;
                        }
                      }
                      if ( v85 + 48 < v755
                        && v85 != -48
                        && v85 + 48 >= v751
                        && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 48)) & 1) != 0 )
                      {
                        v138 = *(_DWORD *)(v85 + 56);
                        v139 = *(_DWORD *)(v85 + 8) - 20;
                        v140 = v138 < v139;
                        ++*(_WORD *)(v85 + 52);
                        if ( v138 > v139 )
                          v139 = v138;
                        if ( v140 || v139 <= -101 )
                        {
                          if ( v139 <= -100 )
                            v139 = -100;
                          *(_DWORD *)(v85 + 56) = v139;
                        }
                      }
                      if ( v85 + 72 < v755
                        && v85 != -72
                        && v85 + 72 >= v751
                        && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 72)) & 1) != 0 )
                      {
                        v141 = *(_DWORD *)(v85 + 80);
                        v142 = *(_DWORD *)(v85 + 8) - 30;
                        v143 = v141 < v142;
                        ++*(_WORD *)(v85 + 76);
                        if ( v141 > v142 )
                          v142 = v141;
                        if ( v143 || v142 <= -101 )
                        {
                          if ( v142 <= -100 )
                            v142 = -100;
                          *(_DWORD *)(v85 + 80) = v142;
                        }
                      }
                      if ( v85 + 96 < v755
                        && v85 != -96
                        && v85 + 96 >= v751
                        && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 96)) & 1) != 0 )
                      {
                        v144 = *(_DWORD *)(v85 + 104);
                        v145 = *(_DWORD *)(v85 + 8) - 40;
                        v146 = v144 < v145;
                        ++*(_WORD *)(v85 + 100);
                        if ( v144 > v145 )
                          v145 = v144;
                        if ( v146 || v145 <= -101 )
                        {
                          if ( v145 <= -100 )
                            v145 = -100;
                          *(_DWORD *)(v85 + 104) = v145;
                        }
                      }
                    }
                  }
                  else
                  {
                    qdf_trace_msg(
                      0x39u,
                      2u,
                      "%s: spect_ch is NULL",
                      v88,
                      v89,
                      v90,
                      v91,
                      v92,
                      v93,
                      v94,
                      v95,
                      "sap_interference_rssi_count");
                  }
LABEL_487:
                  v72 = (void *)v745;
                  v199 = scnprintf(
                           v745 + v718,
                           150 - v718,
                           "%d[%d,%d,%d,%d] ",
                           v78,
                           v733,
                           v726,
                           v713,
                           *(char *)(v73[3] + 60LL));
                  v74 = v207 + v718;
                  v70 = v761;
                  v71 = a3;
                  if ( v207 + v718 >= 0x7B )
                  {
                    qdf_trace_msg(
                      0x39u,
                      8u,
                      "BSS freq[width,freq0,freq1,rssi]: %s",
                      v199,
                      v200,
                      v201,
                      v202,
                      v203,
                      v204,
                      v205,
                      v206,
                      v745);
                    v74 = 0;
                  }
                  goto LABEL_55;
                }
                if ( v733 <= 2 )
                {
                  if ( v733 == 1 )
                  {
                    if ( v81 == 3 )
                    {
                      if ( v85 - 24 >= v755
                        || v85 == 24
                        || v85 - 24 < v751
                        || (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 - 24)) & 1) == 0 )
                      {
                        goto LABEL_487;
                      }
                      v160 = *(_DWORD *)(v85 - 16);
                      v104 = (int *)(v85 - 16);
                      v103 = v160;
                      v106 = v104[6];
                    }
                    else
                    {
                      if ( v81 != 1
                        || v85 + 24 >= v755
                        || v85 == -24
                        || v85 + 24 < v751
                        || (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *(_DWORD *)(v85 + 24)) & 1) == 0 )
                      {
                        goto LABEL_487;
                      }
                      v105 = *(_DWORD *)(v85 + 32);
                      v104 = (int *)(v85 + 32);
                      v103 = v105;
                      v106 = *(v104 - 6);
                    }
                    v161 = v106 - 20;
                    v162 = v103 < v161;
                    if ( v103 <= v161 )
                      v103 = v161;
                    ++*((_WORD *)v104 - 2);
                    if ( v162 || v103 < -100 )
                    {
                      if ( v103 <= -100 )
                        v103 = -100;
                      *v104 = v103;
                    }
                    goto LABEL_487;
                  }
                  if ( v733 != 2 )
                    goto LABEL_487;
LABEL_115:
                  v100 = v726 - v78;
                  if ( (int)(v726 - v78) <= 9 )
                  {
                    if ( v100 == -30 )
                    {
                      v101 = -3;
                      v102 = 3;
                    }
                    else
                    {
                      if ( v100 != -10 )
                        goto LABEL_487;
                      v101 = -2;
                      v102 = 3;
                    }
                    goto LABEL_493;
                  }
                  if ( v100 == 30 )
                  {
                    v159 = 0;
                    v102 = 3;
                    v101 = 1;
                  }
                  else
                  {
                    if ( v100 != 10 )
                      goto LABEL_487;
                    v101 = -1;
                    v102 = 3;
LABEL_493:
                    v159 = 1;
                  }
LABEL_494:
                  v208 = v85 + 24LL * (int)v101;
                  v209 = 0;
                  v210 = 24 * (v159 + v102);
                  v211 = (int *)((char *)&unk_B08EA0 + 4 * (unsigned int)(v101 + 15));
                  do
                  {
                    if ( v101 )
                    {
                      v213 = (unsigned int *)(v208 + v209);
                      if ( v208 + v209 < v755
                        && v213
                        && (unsigned __int64)v213 >= v751
                        && (wlan_reg_is_same_band_freqs(*(_DWORD *)v85, *v213) & 1) != 0 )
                      {
                        v214 = v208 + v209;
                        ++*(_WORD *)(v208 + v209 + 4);
                        if ( (unsigned int)(v101 + 15) > 0x1E )
                          v215 = 0;
                        else
                          v215 = *v211;
                        v216 = *(_DWORD *)(v214 + 8);
                        v212 = *(_DWORD *)(v85 + 8) + v215;
                        v217 = v216 < v212;
                        if ( v216 > v212 )
                          v212 = *(_DWORD *)(v214 + 8);
                        if ( v217 || v212 <= -101 )
                        {
                          if ( v212 <= -100 )
                            v212 = -100;
                          *(_DWORD *)(v214 + 8) = v212;
                        }
                      }
                    }
                    v209 += 24;
                    ++v211;
                    ++v101;
                  }
                  while ( v210 != v209 );
                  goto LABEL_487;
                }
                if ( v733 != 3 )
                  goto LABEL_115;
                v107 = v726 - v78;
                if ( (int)(v726 - v78) > 9 )
                {
                  if ( v107 > 49 )
                  {
                    if ( v107 == 70 )
                    {
                      v159 = 0;
                      v102 = 7;
                      v101 = 1;
                      goto LABEL_494;
                    }
                    if ( v107 != 50 )
                      goto LABEL_487;
                    v101 = -1;
                  }
                  else if ( v107 == 10 )
                  {
                    v101 = -3;
                  }
                  else
                  {
                    if ( v107 != 30 )
                      goto LABEL_487;
                    v101 = -2;
                  }
                }
                else if ( v107 > -31 )
                {
                  if ( v107 == -30 )
                  {
                    v101 = -5;
                  }
                  else
                  {
                    if ( v107 != -10 )
                      goto LABEL_487;
                    v101 = -4;
                  }
                }
                else if ( v107 == -70 )
                {
                  v101 = -7;
                }
                else
                {
                  if ( v107 != -50 )
                    goto LABEL_487;
                  v101 = -6;
                }
                v102 = 7;
                goto LABEL_493;
              }
              goto LABEL_88;
            }
LABEL_87:
            v82 = *(_DWORD *)(v75 + 1196);
            v81 = 0;
            v83 = 0;
            v76 = 2;
            goto LABEL_88;
          }
          if ( (unsigned int)(v77 - 33) >= 4 )
          {
            v80 = v77 == 30;
LABEL_69:
            v81 = 0;
            v82 = 0;
            v83 = 0;
            if ( v80 )
            {
              v82 = *(_DWORD *)(v75 + 1196);
              v83 = *(_DWORD *)(v75 + 1200);
              v81 = 0;
              v76 = 4;
              v84 = (unsigned __int8)a4[8];
              if ( a4[8] )
                goto LABEL_89;
              goto LABEL_55;
            }
LABEL_88:
            v84 = (unsigned __int8)a4[8];
            if ( a4[8] )
              goto LABEL_89;
            goto LABEL_55;
          }
        }
        else if ( (unsigned int)(v77 - 23) >= 4 )
        {
          if ( (unsigned int)(v77 - 27) >= 2 )
          {
            v79 = v77 == 29;
            goto LABEL_81;
          }
          goto LABEL_87;
        }
        v82 = *(_DWORD *)(v75 + 1196);
        v83 = 0;
        v76 = 1;
        if ( v82 > v78 )
          v81 = 1;
        else
          v81 = 3;
        v84 = (unsigned __int8)a4[8];
        if ( a4[8] )
          goto LABEL_89;
LABEL_55:
        qdf_list_peek_next(v71, v773[0], &v763);
        v73 = v763;
        v763 = nullptr;
        v773[0] = v73;
        if ( !v73 )
        {
          if ( v74 )
            qdf_trace_msg(0x39u, 8u, "BSS freq[width,freq0,freq1]: %s", v62, v63, v64, v65, v66, v67, v68, v69, v72);
          break;
        }
      }
    }
  }
  v218 = *(unsigned int *)(v70 + 1532);
  v219 = *(unsigned int **)a4;
  v220 = ((unsigned int)v218 >> 8) & 0xF;
  v221 = (unsigned __int16)v218 >> 12;
  v222 = WORD1(v218) & 0xF;
  v223 = ((unsigned int)v218 >> 20) & 0xF;
  v224 = (((unsigned __int8)*(_DWORD *)(v70 + 1532) >> 4)
        + (*(_DWORD *)(v70 + 1532) & 0xF)
        + v220
        + v221
        + v222
        + v223
        + (HIBYTE(*(_DWORD *)(v70 + 1532)) & 0xF)) >> 1;
  v225 = (unsigned __int16)(((unsigned __int8)*(_DWORD *)(v70 + 1532) >> 4)
                          + (*(_DWORD *)(v70 + 1532) & 0xF)
                          + v220
                          + v221
                          + v222
                          + v223
                          + (HIBYTE(*(_DWORD *)(v70 + 1532)) & 0xF));
  qdf_trace_msg(
    0x39u,
    8u,
    "Channel weight 0x%x, nf local %d, chan free local %d, txpwr range %d tput %d linear_rssi_thresh %d",
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    v68,
    v69,
    v218,
    ((unsigned __int16)(v224 + 3840 * v220) / v225 + 8) >> 4,
    ((unsigned __int16)(v224 + 3840 * v221) / v225 + 8) >> 4,
    ((unsigned __int16)(v224 + 3840 * v222) / v225 + 8) >> 4,
    ((unsigned __int16)(v224 + 3840 * v223) / v225 + 8) >> 4,
    *(__int16 *)(*(_QWORD *)(v70 + 1544) + 606LL));
  qdf_trace_msg(
    0x39u,
    8u,
    "ACS freq weight info: freq[weight{normalized_weight,rssi_bss_weight,chan_status_weight(nf,cc,txpwr range,txpwt tput)"
    ", power_weight}][rssi][bss]:",
    v226,
    v227,
    v228,
    v229,
    v230,
    v231,
    v232,
    v233);
  qdf_mem_set(v72, 0x96u, 0);
  if ( !a4[8] )
  {
    _qdf_mem_free((__int64)v72);
    goto LABEL_650;
  }
  v234 = 0;
  v235 = 0;
  v236 = 0;
  v237 = 0;
  v238 = 0;
  v239 = 0;
  v756 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v240 = *v219;
      v241 = *(_QWORD *)(v761 + 1544);
      v242 = v219[2];
      v243 = *(unsigned int *)(v241 + 556);
      if ( (_DWORD)v243 )
      {
        v244 = 0;
        v245 = v241 + 44;
        v246 = 1;
        do
        {
          if ( v244 == 102 )
            goto LABEL_997;
          if ( *(_DWORD *)(v245 + 4 * v244) == v240 )
            break;
          v246 = ++v244 < v243;
        }
        while ( v243 != v244 );
        if ( v246 )
          LOBYTE(v242) = v242 - 10;
      }
      v247 = (char)v242;
      v248 = v219[3];
      if ( v247 <= -100 )
        v249 = -100;
      else
        v249 = v247;
      if ( v248 - 26663 >= 2 )
      {
        v250 = *(unsigned __int8 *)(v761 + 1496);
        if ( !*(_BYTE *)(v761 + 1496) )
        {
LABEL_532:
          qdf_mem_set(&v768, 0x10u, 0);
          v239 = 0;
          v238 = 0;
          v237 = 0;
          if ( (wlansap_is_channel_present_in_acs_list(
                  *v219,
                  *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 32LL),
                  *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 40LL))
              & 1) != 0 )
            v261 = 26663;
          else
            v261 = 26664;
          *((_WORD *)v219 + 2) = 0;
          v219[2] = -100;
          v219[3] = v261;
LABEL_603:
          v322 = *(_QWORD *)(a1 + 8);
          v323 = *v219;
          v324 = 0;
          v325 = *(unsigned __int16 *)(v322 + 5584);
          v326 = v322 + 4096;
          if ( *(_WORD *)(v322 + 5584) )
          {
            v327 = (unsigned __int8 *)(v322 + 5472);
            v328 = 100;
            do
            {
              if ( v323 >= *((_DWORD *)v327 - 2) && v323 <= *((_DWORD *)v327 - 1) )
              {
                v328 = *v327;
                v324 = 1;
              }
              --v325;
              v327 += 12;
            }
            while ( v325 );
          }
          else
          {
            v328 = 100;
          }
          v329 = *(unsigned __int16 *)(v322 + 5460);
          if ( v329 )
          {
            v330 = (unsigned __int8 *)(v326 + 552);
            do
            {
              if ( v323 == *((_DWORD *)v330 - 1) )
              {
                v328 = *v330;
                v324 = 1;
              }
              --v329;
              v330 += 8;
            }
            while ( v329 );
          }
          if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21632), v323, v253, v254, v255, v256, v257, v258, v259, v260)
              & 1) != 0 )
          {
            v331 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5588LL);
            v332 = v331;
            if ( (unsigned __int8)v331 >= v328 )
              v332 = v328;
            if ( (v324 & 1) != 0 )
              LOBYTE(v331) = v332;
            v328 = (unsigned __int8)v331;
          }
          else if ( (v324 & 1) == 0 )
          {
            v248 = v219[3];
            v235 = 0;
            goto LABEL_624;
          }
          v333 = v219[3];
          v235 = (26664 - v333) * (100 - v328) / 0x64;
          v248 = v235 + v333;
          v219[3] = v248;
LABEL_624:
          if ( v248 >= 0x6829 )
          {
            v248 = 26664;
            v219[3] = 26664;
          }
          v240 = *v219;
          goto LABEL_627;
        }
        v251 = *(int **)(v761 + 1488);
        while ( 1 )
        {
          v252 = *v251++;
          if ( v240 == v252 )
            break;
          if ( !--v250 )
            goto LABEL_532;
        }
        qdf_mem_set(&v768, 0x10u, 0);
        v262 = *(_DWORD *)(v761 + 1532);
        v263 = *(_BYTE **)(v761 + 1544);
        v264 = *((unsigned __int16 *)v219 + 2);
        v265 = (unsigned __int8)v262 >> 4;
        v266 = (v262 >> 8) & 0xF;
        v267 = (unsigned __int16)v262 >> 12;
        v268 = HIWORD(v262) & 0xF;
        v269 = (v262 >> 20) & 0xF;
        v270 = v262 & 0xF;
        v271 = HIBYTE(v262) & 0xF;
        v272 = v265 + v270 + v266 + v267 + v268 + v269 + v271;
        v273 = v272 >> 1;
        v274 = 3840 * v265;
        v275 = v264;
        if ( (v263[604] & 1) == 0 )
          v275 = (((v273 + v274 * v264) / v272 + 30) / 0x3C + 8) >> 4;
        if ( v263[605] == 1 )
        {
          v276 = 2 * v264;
          if ( (char)v263[606] < v249 )
            v275 = v276;
        }
        v277 = 3840 * v270;
        v278 = v273 + v277;
        v279 = (unsigned __int8)(((unsigned __int16)(v273 + v274) / (unsigned int)(unsigned __int16)v272 + 8) >> 4);
        v280 = (((v273 + v277 * (v249 + 100)) / v272 + 50) / 0x64 + 8) >> 4;
        v281 = (unsigned __int8)((v278 / (unsigned int)(unsigned __int16)v272 + 8) >> 4);
        if ( v280 >= v281 )
          v282 = v281;
        else
          v282 = v280;
        if ( v275 >= v279 )
          v283 = v279;
        else
          v283 = v275;
        if ( *(_BYTE *)(a1 + 14984) == 1 )
        {
          channel_status = (_DWORD *)ucfg_mc_cp_stats_get_channel_status(*(_QWORD *)(a1 + 21632), *v219);
          v285 = *(_DWORD *)(v761 + 1532);
          v266 = (v285 >> 8) & 0xF;
          v286 = (unsigned __int8)v285 >> 4;
          v267 = (unsigned __int16)v285 >> 12;
          v268 = HIWORD(v285) & 0xF;
          v269 = (v285 >> 20) & 0xF;
          v271 = HIBYTE(v285) & 0xF;
          v272 = v286 + (*(_DWORD *)(v761 + 1532) & 0xF) + v266 + v267 + v268 + v269 + v271;
          v273 = v272 >> 1;
        }
        else
        {
          channel_status = nullptr;
        }
        v287 = 3840 * v266;
        v288 = (unsigned __int16)(3840 * v266 + v273) / (unsigned int)(unsigned __int16)v272 + 8;
        if ( channel_status && *channel_status )
        {
          v289 = channel_status[1];
          v290 = 0;
          if ( v289 != -128 && v289 )
            v290 = (((v273 + (v289 + 120) * v287) / v272 + 30) / 0x3C + 8) >> 4;
          v291 = (unsigned __int8)(v288 >> 4);
          if ( v290 >= v291 )
            v292 = v291;
          else
            v292 = v290;
        }
        else
        {
          v292 = (unsigned __int8)(v288 >> 4);
        }
        LODWORD(v768) = v292;
        v293 = 3840 * v267;
        v294 = (unsigned __int16)(3840 * v267 + v273) / (unsigned int)(unsigned __int16)v272 + 8;
        if ( channel_status && *channel_status )
        {
          v295 = channel_status[2];
          if ( (*(_BYTE *)(*(_QWORD *)(v761 + 1544) + 609LL) & 1) == 0 )
            v295 -= channel_status[9] + channel_status[7];
          v296 = channel_status[3];
          if ( v296 )
            v297 = ((((v273 + ((v296 >> 1) + (v295 << 8)) / v296 * v293) / v272 + 128) >> 8) + 8) >> 4;
          else
            v297 = 0;
          v299 = (unsigned __int8)(v294 >> 4);
          if ( v297 >= v299 )
            v298 = v299;
          else
            v298 = v297;
        }
        else
        {
          v298 = (unsigned __int8)(v294 >> 4);
        }
        HIDWORD(v768) = v298;
        v752 = v283;
        v300 = 3840 * v268;
        v301 = (unsigned __int16)(3840 * v268 + v273) / (unsigned int)(unsigned __int16)v272 + 8;
        if ( channel_status && *channel_status )
        {
          v302 = channel_status[4];
          if ( v302 )
            v303 = (((v273 + (63 - v302) * v300) / v272 + 31) / 0x3F + 8) >> 4;
          else
            v303 = 0;
          v305 = (unsigned __int8)(v301 >> 4);
          if ( v303 >= v305 )
            v304 = v305;
          else
            v304 = v303;
        }
        else
        {
          v304 = (unsigned __int8)(v301 >> 4);
        }
        LODWORD(v769) = v304;
        v306 = 3840 * v269;
        v307 = (unsigned __int16)(3840 * v269 + v273) / (unsigned int)(unsigned __int16)v272 + 8;
        if ( channel_status && *channel_status )
        {
          v308 = channel_status[5];
          if ( v308 )
            v309 = (((v273 + (63 - v308) * v306) / v272 + 31) / 0x3F + 8) >> 4;
          else
            v309 = 0;
          v313 = (unsigned __int8)(v307 >> 4);
          if ( v309 >= v313 )
            v310 = v313;
          else
            v310 = v309;
          HIDWORD(v769) = v310;
          if ( !v271 )
            goto LABEL_594;
        }
        else
        {
          v310 = (unsigned __int8)(v307 >> 4);
          HIDWORD(v769) = v310;
          if ( !v271 )
          {
LABEL_594:
            v237 = 0;
            goto LABEL_602;
          }
        }
        v734 = v282;
        v740 = v298;
        v311 = 3840 * v271;
        v767 = 0;
        v766 = 0;
        v765 = 0;
        v764 = 0;
        v237 = (unsigned __int8)(((unsigned __int16)(3840 * v271 + v273) / (unsigned int)(unsigned __int16)v272 + 8) >> 4);
        if ( !*(_QWORD *)(v761 + 16) )
        {
          v312 = "%s: sap ctx vdev is null.";
          goto LABEL_588;
        }
        if ( (unsigned int)wlan_reg_get_chan_pwr_attr_from_secondary_list_for_freq() )
        {
          v312 = "%s: fail to get power attribute.";
LABEL_588:
          qdf_trace_msg(
            0x39u,
            2u,
            v312,
            v253,
            v254,
            v255,
            v256,
            v257,
            v258,
            v259,
            v260,
            "sap_weight_channel_reg_max_power");
          v282 = v734;
          v298 = v740;
LABEL_602:
          v238 = v298 + v292 + v304 + v310;
          v239 = v752 + v282;
          v219[3] = 111 * (v238 + v752 + v282 + v237);
          goto LABEL_603;
        }
        v314 = v767;
        if ( v767 <= 0x24u )
        {
          if ( v767 > 0xDu )
            goto LABEL_600;
          v315 = 14;
          v316 = "%s: eirp_pwr %d below min";
        }
        else
        {
          v315 = 36;
          v316 = "%s: eirp_pwr %d exceed max";
        }
        v727 = v315;
        qdf_trace_msg(
          0x39u,
          8u,
          v316,
          v253,
          v254,
          v255,
          v256,
          v257,
          v258,
          v259,
          v260,
          "sap_weight_channel_reg_max_power");
        v314 = v727;
LABEL_600:
        v298 = v740;
        v317 = *(_DWORD *)(v761 + 1532);
        v318 = (36 - v314) * v311;
        v282 = v734;
        v319 = (HIWORD(v317) & 0xF) + ((v317 >> 20) & 0xF);
        v320 = ((unsigned __int8)v317 >> 4) + (v317 & 0xF) + ((v317 >> 8) & 0xF) + ((unsigned __int16)v317 >> 12);
        v321 = (((v318 + ((unsigned int)(v320 + v319 + (HIBYTE(v317) & 0xF)) >> 1))
               / (v320 + v319 + (HIBYTE(v317) & 0xF))
               + 11)
              / 0x16
              + 8) >> 4;
        if ( v321 < v237 )
          v237 = v321;
        goto LABEL_602;
      }
LABEL_627:
      v219[4] = v248;
      if ( wlan_reg_is_6ghz_chan_freq(v240) )
      {
        v342 = v219[3];
        v343 = v236 <= v342 ? v219[3] : v236;
        if ( v342 < 0x6827 )
          v236 = v343;
      }
      if ( *((_BYTE *)v219 + 20) != 1 )
        break;
      v344 = v219[3];
      if ( v344 > 0x6826 )
        break;
      v334 = scnprintf(
               v745 + v756,
               150 - v756,
               "%d[%d{%d,%d,%d(%d,%d,%d,%d),%d}][%d][%d] ",
               *v219,
               v344,
               v235,
               v239,
               v238,
               v768,
               HIDWORD(v768),
               v769,
               HIDWORD(v769),
               v237,
               v219[2],
               *((unsigned __int16 *)v219 + 2));
      v756 += v345;
      if ( v756 <= 0x4A )
        break;
      qdf_trace_msg(0x39u, 8u, "%s", v334, v335, v336, v337, v338, v339, v340, v341, v745);
      if ( ++v234 >= (unsigned int)(unsigned __int8)a4[8] )
        goto LABEL_642;
      v756 = 0;
      v219 += 6;
    }
    if ( ++v234 >= (unsigned int)(unsigned __int8)a4[8] )
      break;
    v219 += 6;
  }
  if ( v756 )
    qdf_trace_msg(0x39u, 8u, "%s", v334, v335, v336, v337, v338, v339, v340, v341, v745);
LABEL_642:
  _qdf_mem_free(v745);
  if ( v236 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: max_valid_weight_on_6ghz_channels %d",
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      v69,
      "sap_update_6ghz_max_weight",
      v236);
    if ( a4[8] )
    {
      v346 = 0;
      v347 = 0;
      do
      {
        v348 = *(_QWORD *)a4;
        if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(*(_QWORD *)a4 + v346)) )
        {
          v349 = v348 + v346;
          if ( *(_DWORD *)(v348 + v346 + 12) == 26663 )
          {
            *(_DWORD *)(v349 + 12) = v236;
            *(_DWORD *)(v349 + 16) = v236;
          }
        }
        ++v347;
        v346 += 24;
      }
      while ( v347 < (unsigned __int8)a4[8] );
    }
  }
LABEL_650:
  wlan_reg_read_current_country(*(_QWORD *)(a1 + 21624), &v771, v62, v63, v64, v65, v66, v67, v68, v69);
  wlan_reg_get_domain_from_country_code(&v762, (__int64)&v771, v350, v351, v352, v353, v354, v355, v356, v357);
  v358 = *(_DWORD *)(*(_QWORD *)(v761 + 1544) + 8LL);
  if ( v358 <= (unsigned int)wlan_reg_ch_to_freq(0xDu)
    && (v359 = *(_DWORD *)(*(_QWORD *)(v761 + 1544) + 12LL), v359 <= (unsigned int)wlan_reg_ch_to_freq(0xDu)) )
  {
    v361 = 8;
  }
  else
  {
    v360 = *(_DWORD *)(*(_QWORD *)(v761 + 1544) + 8LL);
    if ( v360 < (unsigned int)wlan_reg_ch_to_freq(0xDu) )
      v361 = 1;
    else
      v361 = 2;
  }
  v362 = 0;
  if ( (a7 & 1) != 0 )
    next_lower_bandwidth = 0;
  else
    next_lower_bandwidth = v709;
  if ( (a7 & 1) != 0 )
    v361 = 8;
  v753 = v361;
  v728 = next_lower_bandwidth;
  if ( v762 )
    v364 = 9;
  else
    v364 = 7;
  v730 = v364;
LABEL_665:
  if ( next_lower_bandwidth > 2 )
  {
    if ( next_lower_bandwidth == 3 )
    {
      v769 = 0;
      v770 = 0;
      v497 = *(_QWORD *)(a1 + 21632);
      v768 = 0;
      v498 = wlan_get_opmode_from_vdev_id(v497, *(_BYTE *)(v761 + 12));
      if ( v498 != 17 )
      {
        v759 = v498;
        v499 = *(_QWORD *)a4;
        v500 = _qdf_mem_malloc(0x96u, "sap_sort_chl_weight_160_mhz", 2240);
        if ( v500 )
        {
          if ( !a4[8] )
          {
            _qdf_mem_free(v500);
            goto LABEL_961;
          }
          v509 = 0;
          v737 = v500;
          v748 = 0;
          v743 = 0;
          while ( 2 )
          {
            while ( 2 )
            {
              v563 = v499 + 24 * v509;
              v564 = (_BYTE *)(v563 + 21);
              if ( (*(_BYTE *)(v563 + 21) & 1) == 0 )
              {
                LODWORD(v768) = 3;
                v565 = sap_acs_set_puncture_support(v761, &v768);
                wlan_reg_set_channel_params_for_pwrmode(
                  *(_QWORD *)(a1 + 21632),
                  *(_DWORD *)v563,
                  0,
                  (__int64)&v768,
                  0,
                  v565,
                  v566,
                  v567,
                  v568,
                  v569,
                  v570,
                  v571,
                  v572);
                if ( (_DWORD)v768 != 3
                  || (v573 = *(_DWORD *)v563, (unsigned __int8)(BYTE4(v769) - *(_DWORD *)v563) != 70) )
                {
                  *(_DWORD *)(v563 + 12) = 213312;
                  goto LABEL_889;
                }
                v574 = v509 + 7;
                if ( v509 + 7 <= (unsigned __int8)a4[8] )
                {
                  if ( v573 + 20 == *(_DWORD *)(v563 + 24) )
                  {
                    v575 = *(_DWORD *)(v563 + 48);
                    if ( v573 + 40 == v575
                      && v573 + 60 == *(_DWORD *)(v563 + 72)
                      && v573 + 80 == *(_DWORD *)(v563 + 96)
                      && v573 + 100 == *(_DWORD *)(v563 + 120)
                      && v573 + 120 == *(_DWORD *)(v563 + 144) )
                    {
                      v576 = (_DWORD *)(v499 + 24 * v574);
                      if ( v573 + 140 == *v576 )
                      {
                        v577 = v499 + 12 + 24 * v509;
                        v578 = *(_DWORD *)(v563 + 12);
                        v579 = 0;
                        v580 = 0;
                        v724 = 0;
                        v693 = *(_DWORD *)(v563 + 60);
                        v696 = *(_DWORD *)(v563 + 36);
                        v680 = *(_DWORD *)(v563 + 132);
                        v684 = *(_DWORD *)(v563 + 84);
                        v687 = *(_DWORD *)(v563 + 156);
                        v690 = *(_DWORD *)(v563 + 108);
                        v699 = v576[3];
                        v703 = v578;
                        v716 = 1;
                        v720 = 0;
                        do
                        {
                          v581 = *(_DWORD *)v577;
                          v582 = *(_DWORD *)(v577 - 12);
                          *(_DWORD *)v577 = 213312;
                          v583 = v578 > v581;
                          *(_BYTE *)(v577 + 9) = 1;
                          if ( v578 >= v581 )
                            v578 = v581;
                          if ( v583 )
                            v580 = v579;
                          v707 = v580;
                          v720 |= *(unsigned __int8 *)(v577 + 8);
                          v716 &= policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21624), v759, v582);
                          is_channel_present_in_acs_list = wlansap_is_channel_present_in_acs_list(
                                                             *(unsigned int *)(v577 - 12),
                                                             *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                                                             *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL));
                          v580 = v707;
                          ++v579;
                          v577 += 24;
                          v724 |= is_channel_present_in_acs_list;
                        }
                        while ( v579 != 8 );
                        LOBYTE(v773[0]) = v707;
                        v585 = v696 + v703 + v693 + v684 + v690 + v680 + v687 + v699;
                        sap_override_6ghz_psc_minidx(a1, v499 + 24 * v509, 8, v773);
                        v586 = v509 + LOBYTE(v773[0]);
                        *(_DWORD *)(v499 + 24 * v586 + 12) = v585;
                        if ( (v720 & v716 & v724 & 1) != 0 )
                        {
                          v501 = scnprintf(
                                   v737 + v748,
                                   150 - v748,
                                   "%d[%d,%d,%d] ",
                                   *(_DWORD *)(v499 + 24 * v586),
                                   v585,
                                   HIDWORD(v769),
                                   ++v743);
                          v588 = v587 + v748;
                        }
                        else
                        {
                          v588 = v748;
                        }
                        if ( v588 > 0x7C )
                        {
                          qdf_trace_msg(
                            0x39u,
                            8u,
                            "ACS 160 Mhz freq score: %s",
                            v501,
                            v502,
                            v503,
                            v504,
                            v505,
                            v506,
                            v507,
                            v508,
                            v737);
                          ++v509;
                          v748 = 0;
                          if ( v509 >= (unsigned __int8)a4[8] )
                            goto LABEL_959;
                          continue;
                        }
                        v748 = v588;
                        break;
                      }
                    }
                    *(_BYTE *)(v563 + 21) = 1;
                    *(_DWORD *)(v563 + 12) = 213312;
                    *(_DWORD *)(v563 + 36) = 213312;
                    *(_BYTE *)(v563 + 45) = 1;
                    if ( v573 + 40 != v575 )
                    {
LABEL_892:
                      if ( v573 + 60 == *(_DWORD *)(v563 + 72) )
                      {
                        *(_DWORD *)(v563 + 84) = 213312;
                        *(_BYTE *)(v563 + 93) = 1;
                      }
                      if ( v573 + 80 == *(_DWORD *)(v563 + 96) )
                      {
                        *(_DWORD *)(v563 + 108) = 213312;
                        *(_BYTE *)(v563 + 117) = 1;
                      }
                      if ( v573 + 100 == *(_DWORD *)(v563 + 120) )
                      {
                        *(_DWORD *)(v563 + 132) = 213312;
                        *(_BYTE *)(v563 + 141) = 1;
                      }
                      if ( v573 + 120 == *(_DWORD *)(v563 + 144) )
                      {
                        *(_DWORD *)(v563 + 156) = 213312;
                        *(_BYTE *)(v563 + 165) = 1;
                      }
                      v590 = (_DWORD *)(v499 + 24 * v574);
                      if ( v573 + 140 == *v590 )
                      {
                        v564 = (char *)v590 + 21;
                        v590[3] = 213312;
LABEL_889:
                        *v564 = 1;
                      }
                      break;
                    }
                  }
                  else
                  {
                    v589 = *(_DWORD *)(v563 + 48);
                    *(_DWORD *)(v563 + 12) = 213312;
                    *(_BYTE *)(v563 + 21) = 1;
                    if ( v573 + 40 != v589 )
                      goto LABEL_892;
                  }
                  *(_DWORD *)(v563 + 60) = 213312;
                  *(_BYTE *)(v563 + 69) = 1;
                  goto LABEL_892;
                }
              }
              break;
            }
            if ( ++v509 >= (unsigned __int8)a4[8] )
            {
              if ( v748 )
              {
                qdf_trace_msg(
                  0x39u,
                  8u,
                  "ACS 160 Mhz freq score: %s",
                  v501,
                  v502,
                  v503,
                  v504,
                  v505,
                  v506,
                  v507,
                  v508,
                  v737);
                v632 = v737;
              }
              else
              {
LABEL_959:
                v632 = v737;
              }
              _qdf_mem_free(v632);
              if ( v743 )
                goto LABEL_972;
LABEL_961:
              v633 = "%s: no valid chan bonding with CH_WIDTH_160MHZ";
              v634 = "sap_sort_chl_weight_160_mhz";
              goto LABEL_964;
            }
            continue;
          }
        }
LABEL_914:
        v362 = 2;
        goto LABEL_968;
      }
LABEL_841:
      v362 = 14;
      goto LABEL_968;
    }
    if ( next_lower_bandwidth == 4 )
      goto LABEL_678;
    if ( next_lower_bandwidth != 7 )
      goto LABEL_972;
    v769 = 0;
    v770 = 0;
    v365 = *(_QWORD *)(a1 + 21632);
    v773[0] = nullptr;
    v773[1] = nullptr;
    v366 = *(_BYTE *)(v761 + 12);
    v768 = 0;
    LODWORD(v763) = 0;
    v367 = wlan_get_opmode_from_vdev_id(v365, v366);
    if ( v367 == 17 )
      goto LABEL_841;
    v368 = v367;
    v369 = *(_QWORD *)a4;
    v370 = _qdf_mem_malloc(0x96u, "sap_sort_chl_weight_320_mhz", 2455);
    if ( !v370 )
      goto LABEL_914;
    v746 = v370;
    v741 = v368;
    wlan_reg_get_cur_6g_ap_pwr_type(
      *(_QWORD *)(a1 + 21632),
      (unsigned int *)&v763,
      v371,
      v372,
      v373,
      v374,
      v375,
      v376,
      v377,
      v378);
    v757 = wlan_reg_conv_6g_ap_type_to_supported_6g_pwr_types((unsigned int)v763);
    if ( !a4[8] )
      goto LABEL_941;
    v379 = 0;
    v380 = v369;
    do
    {
      *(_BYTE *)(v380 + 22) = wlan_reg_get_320_bonded_chan_array(*(_QWORD *)(a1 + 21632), *(_DWORD *)v380, 0, v773);
      ++v379;
      v380 += 24;
    }
    while ( v379 < (unsigned __int8)a4[8] );
    if ( !a4[8] )
    {
LABEL_941:
      _qdf_mem_free(v746);
      goto LABEL_942;
    }
    v389 = 0;
    v735 = 0;
    v722 = 0;
    while ( 1 )
    {
      v468 = v369 + 24 * v389;
      v469 = (_BYTE *)(v468 + 21);
      if ( (*(_BYTE *)(v468 + 21) & 1) != 0 )
        goto LABEL_735;
      qdf_mem_set(&v768, 0x18u, 0);
      LODWORD(v768) = 7;
      v470 = sap_acs_set_puncture_support(v761, &v768);
      wlan_reg_set_channel_params_for_pwrmode(
        *(_QWORD *)(a1 + 21632),
        *(_DWORD *)v468,
        0,
        (__int64)&v768,
        v757,
        v470,
        v471,
        v472,
        v473,
        v474,
        v475,
        v476,
        v477);
      if ( (_DWORD)v768 != 7 || (v478 = v389 + 15, v389 + 15 > (unsigned __int8)a4[8]) )
      {
        *(_DWORD *)(v468 + 12) = 426624;
LABEL_734:
        *v469 = 1;
        goto LABEL_735;
      }
      v479 = *(_DWORD *)v468;
      if ( *(_DWORD *)v468 + 20 != *(_DWORD *)(v468 + 24) )
        break;
      v480 = *(_DWORD *)(v468 + 48);
      if ( v479 + 40 != v480
        || v479 + 60 != *(_DWORD *)(v468 + 72)
        || v479 + 80 != *(_DWORD *)(v468 + 96)
        || v479 + 100 != *(_DWORD *)(v468 + 120)
        || v479 + 120 != *(_DWORD *)(v468 + 144)
        || v479 + 140 != *(_DWORD *)(v468 + 168)
        || v479 + 160 != *(_DWORD *)(v468 + 192)
        || v479 + 180 != *(_DWORD *)(v468 + 216)
        || v479 + 200 != *(_DWORD *)(v468 + 240)
        || v479 + 220 != *(_DWORD *)(v468 + 264)
        || v479 + 240 != *(_DWORD *)(v468 + 288)
        || v479 + 260 != *(_DWORD *)(v468 + 312)
        || v479 + 280 != *(_DWORD *)(v468 + 336)
        || (v481 = (_DWORD *)(v369 + 24 * v478), v479 + 300 != *v481) )
      {
        *(_BYTE *)(v468 + 21) = 1;
        *(_BYTE *)(v468 + 45) = 1;
        *(_DWORD *)(v468 + 12) = 426624;
        *(_DWORD *)(v468 + 36) = 426624;
        if ( v479 + 40 != v480 )
        {
LABEL_757:
          if ( v479 + 60 == *(_DWORD *)(v468 + 72) )
          {
            *(_BYTE *)(v468 + 93) = 1;
            *(_DWORD *)(v468 + 84) = 426624;
          }
          if ( v479 + 80 == *(_DWORD *)(v468 + 96) )
          {
            *(_BYTE *)(v468 + 117) = 1;
            *(_DWORD *)(v468 + 108) = 426624;
          }
          if ( v479 + 100 == *(_DWORD *)(v468 + 120) )
          {
            *(_BYTE *)(v468 + 141) = 1;
            *(_DWORD *)(v468 + 132) = 426624;
          }
          if ( v479 + 120 == *(_DWORD *)(v468 + 144) )
          {
            *(_BYTE *)(v468 + 165) = 1;
            *(_DWORD *)(v468 + 156) = 426624;
          }
          if ( v479 + 140 == *(_DWORD *)(v468 + 168) )
          {
            *(_BYTE *)(v468 + 189) = 1;
            *(_DWORD *)(v468 + 180) = 426624;
          }
          if ( v479 + 160 == *(_DWORD *)(v468 + 192) )
          {
            *(_BYTE *)(v468 + 213) = 1;
            *(_DWORD *)(v468 + 204) = 426624;
          }
          if ( v479 + 180 == *(_DWORD *)(v468 + 216) )
          {
            *(_BYTE *)(v468 + 237) = 1;
            *(_DWORD *)(v468 + 228) = 426624;
          }
          if ( v479 + 200 == *(_DWORD *)(v468 + 240) )
          {
            *(_BYTE *)(v468 + 261) = 1;
            *(_DWORD *)(v468 + 252) = 426624;
          }
          if ( v479 + 220 == *(_DWORD *)(v468 + 264) )
          {
            *(_BYTE *)(v468 + 285) = 1;
            *(_DWORD *)(v468 + 276) = 426624;
          }
          if ( v479 + 240 == *(_DWORD *)(v468 + 288) )
          {
            *(_BYTE *)(v468 + 309) = 1;
            *(_DWORD *)(v468 + 300) = 426624;
          }
          if ( v479 + 260 == *(_DWORD *)(v468 + 312) )
          {
            *(_BYTE *)(v468 + 333) = 1;
            *(_DWORD *)(v468 + 324) = 426624;
          }
          if ( v479 + 280 == *(_DWORD *)(v468 + 336) )
          {
            *(_BYTE *)(v468 + 357) = 1;
            *(_DWORD *)(v468 + 348) = 426624;
          }
          v486 = (_DWORD *)(v369 + 24 * v478);
          if ( v479 + 300 != *v486 )
            goto LABEL_735;
          v469 = (char *)v486 + 21;
          v486[3] = 426624;
          goto LABEL_734;
        }
LABEL_756:
        *(_BYTE *)(v468 + 69) = 1;
        *(_DWORD *)(v468 + 60) = 426624;
        goto LABEL_757;
      }
      v482 = 0;
      v483 = *(_DWORD *)(v468 + 12);
      v715 = 0;
      v689 = *(_DWORD *)(v468 + 60);
      v692 = *(_DWORD *)(v468 + 36);
      v711 = 0;
      v683 = *(_DWORD *)(v468 + 84);
      v686 = *(_DWORD *)(v468 + 108);
      v695 = v483;
      v698 = next_lower_bandwidth;
      v702 = *(_DWORD *)(v468 + 156);
      v484 = (_BYTE *)(v369 + 22 + 24 * v389);
      v485 = 0;
      v666 = *(_DWORD *)(v468 + 204);
      v675 = *(_DWORD *)(v468 + 228);
      v677 = *(_DWORD *)(v468 + 252);
      v679 = *(_DWORD *)(v468 + 132);
      v667 = *(_DWORD *)(v468 + 276);
      v668 = *(_DWORD *)(v468 + 180);
      v665 = *(_DWORD *)(v468 + 300);
      v669 = *(_DWORD *)(v468 + 324);
      v670 = *(_DWORD *)(v468 + 348);
      v672 = v481[3];
      v706 = 1;
      do
      {
        v488 = *(_DWORD *)(v484 - 10);
        v489 = v711;
        v490 = v482;
        if ( v483 > v488 )
          v489 = v482;
        if ( v483 >= v488 )
          v483 = *(_DWORD *)(v484 - 10);
        v711 = v489;
        if ( !*v484 || (v491 = *v484 - 1, *(v484 - 1) = 0, (*v484 = v491) == 0) )
        {
          *(_DWORD *)(v484 - 10) = 426624;
          *(v484 - 1) = 1;
        }
        v715 |= (unsigned __int8)*(v484 - 2);
        v706 &= policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21624), v741, *(_DWORD *)(v484 - 22));
        v487 = wlansap_is_channel_present_in_acs_list(
                 *(unsigned int *)(v484 - 22),
                 *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                 *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL));
        v482 = v490 + 1;
        v485 |= v487;
        v484 += 24;
      }
      while ( v490 != 15 );
      v492 = v692
           + v695
           + v689
           + v683
           + v686
           + v679
           + v702
           + v668
           + v666
           + v675
           + v677
           + v667
           + v665
           + v669
           + v670
           + v672;
      LOBYTE(v764) = v711;
      sap_override_6ghz_psc_minidx(a1, v369 + 24 * v389, 16, &v764);
      v493 = v389 + (unsigned __int8)v764;
      *(_DWORD *)(v369 + 24 * v493 + 12) = v492;
      if ( (v715 & v706 & v485 & 1) != 0 )
      {
        v381 = scnprintf(
                 v746 + v735,
                 150 - v735,
                 "%d[%d,%d,%d] ",
                 *(_DWORD *)(v369 + 24 * v493),
                 v492,
                 HIDWORD(v769),
                 ++v722);
        v735 += v494;
      }
      if ( v735 > 0x7C )
      {
        qdf_trace_msg(0x39u, 8u, "ACS 320 MHz freq score: %s", v381, v382, v383, v384, v385, v386, v387, v388, v746);
        ++v389;
        next_lower_bandwidth = v698;
        v735 = 0;
        if ( v389 >= (unsigned __int8)a4[8] )
          goto LABEL_965;
        continue;
      }
      next_lower_bandwidth = v698;
LABEL_735:
      if ( ++v389 >= (unsigned __int8)a4[8] )
      {
        if ( v735 )
        {
          qdf_trace_msg(0x39u, 8u, "ACS 320 MHz freq score: %s", v381, v382, v383, v384, v385, v386, v387, v388, v746);
          v635 = v746;
          goto LABEL_966;
        }
LABEL_965:
        v635 = v746;
LABEL_966:
        _qdf_mem_free(v635);
        if ( v722 )
        {
LABEL_972:
          sap_sort_chl_weight(a1, a4, v761);
          goto LABEL_973;
        }
LABEL_942:
        v633 = "%s: no valid chan bonding with CH_WIDTH_320MHZ";
        v634 = "sap_sort_chl_weight_320_mhz";
LABEL_964:
        qdf_trace_msg(0x39u, 8u, v633, v624, v625, v626, v627, v628, v629, v630, v631, v634);
        v362 = 4;
LABEL_968:
        next_lower_bandwidth = wlan_reg_get_next_lower_bandwidth(next_lower_bandwidth);
        if ( a4[8] )
        {
          v636 = 0;
          v637 = (_BYTE *)(*(_QWORD *)a4 + 21LL);
          do
          {
            ++v636;
            *(_DWORD *)(v637 - 9) = *(_DWORD *)(v637 - 5);
            *v637 = 0;
            v637 += 24;
          }
          while ( v636 < (unsigned __int8)a4[8] );
        }
        goto LABEL_665;
      }
    }
    *(_BYTE *)(v468 + 21) = 1;
    *(_DWORD *)(v468 + 12) = 426624;
    if ( v479 + 40 != *(_DWORD *)(v468 + 48) )
      goto LABEL_757;
    goto LABEL_756;
  }
  if ( next_lower_bandwidth != 1 )
  {
    if ( next_lower_bandwidth != 2 )
      goto LABEL_972;
LABEL_678:
    v769 = 0;
    v770 = 0;
    v390 = *(_QWORD *)(a1 + 21632);
    v768 = 0;
    v391 = wlan_get_opmode_from_vdev_id(v390, *(_BYTE *)(v761 + 12));
    if ( v391 == 17 )
      goto LABEL_841;
    v758 = v391;
    v392 = *(_QWORD *)a4;
    v393 = _qdf_mem_malloc(0x96u, "sap_sort_chl_weight_80_mhz", 2064);
    if ( !v393 )
      goto LABEL_914;
    if ( !a4[8] )
    {
      _qdf_mem_free(v393);
      goto LABEL_947;
    }
    v402 = 0;
    v736 = v393;
    v747 = 0;
    v742 = 0;
    while ( 2 )
    {
      while ( 2 )
      {
        v403 = (unsigned int *)(v392 + 24 * v402);
        v404 = (char *)v403 + 21;
        if ( (*((_BYTE *)v403 + 21) & 1) == 0 )
        {
          LODWORD(v768) = 2;
          v405 = sap_acs_set_puncture_support(v761, &v768);
          wlan_reg_set_channel_params_for_pwrmode(
            *(_QWORD *)(a1 + 21632),
            *v403,
            0,
            (__int64)&v768,
            0,
            v405,
            v406,
            v407,
            v408,
            v409,
            v410,
            v411,
            v412);
          if ( (_DWORD)v768 != 2 || (v413 = *v403, (unsigned __int8)(v769 - *v403) != 30) )
          {
            v403[3] = 106656;
            goto LABEL_683;
          }
          v414 = v402 + 3;
          if ( v402 + 3 <= (unsigned __int8)a4[8] )
          {
            if ( v413 + 20 == v403[6] )
            {
              v415 = v403[12];
              if ( v413 + 40 == v415 )
              {
                v416 = v392 + 24 * v414;
                if ( v413 + 60 == *(_DWORD *)v416 )
                {
                  v417 = v403[3];
                  v418 = v403[9];
                  *((_BYTE *)v403 + 21) = 1;
                  v403[3] = 106656;
                  v714 = v403[15];
                  v719 = v418;
                  v705 = *((unsigned __int8 *)v403 + 20);
                  v710 = *(_DWORD *)(v416 + 12);
                  is_sap_freq_allowed = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21624), v758, v413);
                  v419 = wlansap_is_channel_present_in_acs_list(
                           *v403,
                           *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                           *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL));
                  v420 = v403[9];
                  *((_BYTE *)v403 + 45) = 1;
                  v421 = v403[6];
                  v403[9] = 106656;
                  v422 = v417 > v420;
                  v723 = v417;
                  if ( v417 >= v420 )
                    v417 = v420;
                  v694 = *((unsigned __int8 *)v403 + 44);
                  v697 = v419;
                  v423 = v422;
                  v681 = v423;
                  v691 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21624), v758, v421);
                  v424 = wlansap_is_channel_present_in_acs_list(
                           v403[6],
                           *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                           *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL));
                  v425 = v403[15];
                  v426 = v403[12];
                  v403[15] = 106656;
                  v427 = v417 > v425;
                  *((_BYTE *)v403 + 69) = 1;
                  if ( v417 >= v425 )
                    v417 = v425;
                  v685 = *((unsigned __int8 *)v403 + 68);
                  v688 = v424;
                  if ( v427 )
                    v428 = 2;
                  else
                    v428 = v681;
                  v673 = v428;
                  v682 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21624), v758, v426);
                  v429 = wlansap_is_channel_present_in_acs_list(
                           v403[12],
                           *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                           *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL));
                  v430 = *(_DWORD *)(v416 + 12);
                  v431 = *(_DWORD *)v416;
                  *(_DWORD *)(v416 + 12) = 106656;
                  v99 = v417 > v430;
                  v432 = *(unsigned __int8 *)(v416 + 20);
                  *(_BYTE *)(v416 + 21) = 1;
                  v676 = v432;
                  v678 = v429;
                  if ( v99 )
                    v433 = 3;
                  else
                    v433 = v673;
                  v674 = v433;
                  v434 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21624), v758, v431);
                  v435 = *(_DWORD *)v416;
                  v436 = v434;
                  v437 = wlansap_is_channel_present_in_acs_list(
                           v435,
                           *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                           *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL));
                  if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5587LL) == 1 )
                  {
                    v671 = v437;
                    if ( wlan_reg_is_6ghz_chan_freq(*v403)
                      && (wlan_reg_is_6ghz_psc_chan_freq(*v403, v438, v439, v440, v441, v442, v443, v444, v445) & 1) != 0 )
                    {
                      v446 = 0;
                    }
                    else if ( wlan_reg_is_6ghz_chan_freq(v403[6])
                           && (wlan_reg_is_6ghz_psc_chan_freq(v403[6], v448, v449, v450, v451, v452, v453, v454, v455)
                             & 1) != 0 )
                    {
                      v446 = 1;
                    }
                    else if ( wlan_reg_is_6ghz_chan_freq(v403[12])
                           && (wlan_reg_is_6ghz_psc_chan_freq(v403[12], v456, v457, v458, v459, v460, v461, v462, v463)
                             & 1) != 0 )
                    {
                      v446 = 2;
                    }
                    else if ( wlan_reg_is_6ghz_chan_freq(v403[18])
                           && (wlan_reg_is_6ghz_psc_chan_freq(v403[18], v394, v395, v396, v397, v398, v399, v400, v401)
                             & 1) != 0 )
                    {
                      v446 = 3;
                    }
                    else
                    {
                      v446 = v674;
                    }
                    v437 = v671;
                  }
                  else
                  {
                    v446 = v674;
                  }
                  v464 = v402 + v446;
                  v465 = v719 + v723 + v714 + v710;
                  *(_DWORD *)(v392 + 24 * v464 + 12) = v465;
                  if ( ((v676 | v685 | v694 | v705)
                      & v436
                      & v682
                      & v691
                      & is_sap_freq_allowed
                      & (v437 | v678 | v688 | v697)
                      & 1) != 0 )
                  {
                    v394 = scnprintf(
                             v736 + v747,
                             150 - v747,
                             "%d[%d,%d,%d] ",
                             *(_DWORD *)(v392 + 24 * v464),
                             v465,
                             v769,
                             ++v742);
                    v467 = v466 + v747;
                    if ( v466 + v747 > 0x7C )
                    {
                      qdf_trace_msg(
                        0x39u,
                        8u,
                        "ACS 80 Mhz freq score: %s",
                        v394,
                        v395,
                        v396,
                        v397,
                        v398,
                        v399,
                        v400,
                        v401,
                        v736);
                      ++v402;
                      v747 = 0;
                      if ( v402 >= (unsigned __int8)a4[8] )
                        goto LABEL_945;
                      continue;
                    }
                  }
                  else
                  {
                    v467 = v747;
                  }
                  v747 = v467;
                  break;
                }
              }
              *((_BYTE *)v403 + 21) = 1;
              *((_BYTE *)v403 + 45) = 1;
              v403[3] = 106656;
              v403[9] = 106656;
              if ( v413 + 40 != v415 )
              {
LABEL_711:
                v447 = (_DWORD *)(v392 + 24 * v414);
                if ( v413 + 60 == *v447 )
                {
                  v404 = (char *)v447 + 21;
                  v447[3] = 106656;
LABEL_683:
                  *v404 = 1;
                }
                break;
              }
            }
            else
            {
              *((_BYTE *)v403 + 21) = 1;
              v403[3] = 106656;
              if ( v413 + 40 != v403[12] )
                goto LABEL_711;
            }
            *((_BYTE *)v403 + 69) = 1;
            v403[15] = 106656;
            goto LABEL_711;
          }
        }
        break;
      }
      if ( ++v402 >= (unsigned __int8)a4[8] )
      {
        if ( v747 )
        {
          qdf_trace_msg(0x39u, 8u, "ACS 80 Mhz freq score: %s", v394, v395, v396, v397, v398, v399, v400, v401, v736);
          v591 = v736;
        }
        else
        {
LABEL_945:
          v591 = v736;
        }
        _qdf_mem_free(v591);
        if ( v742 )
          goto LABEL_972;
LABEL_947:
        v633 = "%s: no valid chan bonding with CH_WIDTH_80MHZ";
        v634 = "sap_sort_chl_weight_80_mhz";
        goto LABEL_964;
      }
      continue;
    }
  }
  v495 = *(unsigned int **)a4;
  if ( v753 != 8 )
  {
    if ( a4[8] )
    {
      v510 = 0;
      do
      {
        if ( wlan_reg_is_24ghz_ch_freq(*v495) )
          v495[3] = 53328;
        ++v510;
        v495 += 6;
      }
      while ( v510 < (unsigned __int8)a4[8] );
    }
    v769 = 0;
    v770 = 0;
    v535 = *(_QWORD *)(a1 + 21632);
    v768 = 0;
    v536 = wlan_get_opmode_from_vdev_id(v535, *(_BYTE *)(v761 + 12));
    if ( v536 == 17 )
      goto LABEL_841;
    v760 = v536;
    v592 = *(unsigned int **)a4;
    v593 = _qdf_mem_malloc(0x96u, "sap_sort_chl_weight_40_mhz", 2980);
    if ( !v593 )
      goto LABEL_914;
    v594 = v593;
    if ( !a4[8] )
    {
      _qdf_mem_free(v593);
      goto LABEL_963;
    }
    v595 = 0;
    v749 = 0;
    v744 = 0;
    while ( 1 )
    {
      v596 = &v592[6 * v595];
      if ( wlan_reg_is_24ghz_ch_freq(*v596) || (*((_BYTE *)v596 + 21) & 1) != 0 )
        goto LABEL_916;
      LODWORD(v768) = 1;
      wlan_reg_set_channel_params_for_pwrmode(
        *(_QWORD *)(a1 + 21632),
        *v596,
        0,
        (__int64)&v768,
        0,
        v597,
        v598,
        v599,
        v600,
        v601,
        v602,
        v603,
        v604);
      if ( (_DWORD)v768 != 1 )
        goto LABEL_915;
      v605 = *v596;
      if ( (unsigned __int8)(v769 - *v596) != 10 )
        goto LABEL_915;
      if ( v595 >= (unsigned __int8)a4[8] )
        goto LABEL_916;
      if ( v605 + 20 == v596[6] )
      {
        v606 = v596[3];
        v725 = v594;
        v596[3] = 53328;
        v607 = v596[9];
        *((_BYTE *)v596 + 21) = 1;
        v738 = v606;
        v717 = *((unsigned __int8 *)v596 + 20);
        v721 = v607;
        v712 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21624), v760, v605);
        v608 = wlansap_is_channel_present_in_acs_list(
                 *v596,
                 *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                 *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL));
        v609 = v596[9];
        v596[9] = 53328;
        v610 = v596[6];
        *((_BYTE *)v596 + 45) = 1;
        v708 = v608;
        v611 = v738 > v609;
        v704 = *((unsigned __int8 *)v596 + 44);
        v700 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21624), v760, v610);
        v612 = wlansap_is_channel_present_in_acs_list(
                 v596[6],
                 *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                 *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL));
        if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5587LL) == 1 )
        {
          if ( wlan_reg_is_6ghz_chan_freq(*v596)
            && (wlan_reg_is_6ghz_psc_chan_freq(*v596, v613, v614, v615, v616, v617, v618, v619, v620) & 1) != 0 )
          {
            v611 = 0;
          }
          else if ( wlan_reg_is_6ghz_chan_freq(v596[6])
                 && (wlan_reg_is_6ghz_psc_chan_freq(v596[6], v597, v598, v599, v600, v601, v602, v603, v604) & 1) != 0 )
          {
            v611 = 1;
          }
        }
        v621 = v595 + v611;
        v592[6 * v621 + 3] = v721 + v738;
        if ( ((v704 | v717) & v700 & v712 & (v612 | v708) & 1) != 0 )
        {
          v594 = v725;
          v597 = scnprintf(v725 + v749, 150 - v749, "%d[%d,%d,%d] ", v592[6 * v621], v721 + v738, v769, ++v744);
          v623 = v622 + v749;
        }
        else
        {
          v594 = v725;
          v623 = v749;
        }
        if ( v623 <= 0x7C )
        {
          v749 = v623;
          goto LABEL_916;
        }
        qdf_trace_msg(0x39u, 8u, "ACS 40 Mhz freq score: %s", v597, v598, v599, v600, v601, v602, v603, v604, v594);
        ++v595;
        v749 = 0;
        if ( v595 >= (unsigned __int8)a4[8] )
          goto LABEL_957;
      }
      else
      {
LABEL_915:
        v596[3] = 53328;
        *((_BYTE *)v596 + 21) = 1;
LABEL_916:
        if ( ++v595 >= (unsigned __int8)a4[8] )
        {
          if ( v749 )
            qdf_trace_msg(0x39u, 8u, "ACS 40 Mhz freq score: %s", v597, v598, v599, v600, v601, v602, v603, v604, v594);
LABEL_957:
          _qdf_mem_free(v594);
          if ( v744 )
            goto LABEL_972;
LABEL_963:
          v633 = "%s: no valid chan bonding with CH_WIDTH_40MHZ";
          v634 = "sap_sort_chl_weight_40_mhz";
          goto LABEL_964;
        }
      }
    }
  }
  if ( a4[8] )
  {
    v496 = 0;
    do
    {
      if ( wlan_reg_is_5ghz_ch_freq(*v495) || wlan_reg_is_6ghz_chan_freq(*v495) )
        v495[3] = 53328;
      ++v496;
      v495 += 6;
    }
    while ( v496 < (unsigned __int8)a4[8] );
  }
  sap_update_vlp_deprority_chan(a1, a4);
  v519 = *(unsigned int **)a4;
  v520 = 0;
  while ( 2 )
  {
    if ( a4[8] )
    {
      v521 = 0;
      v522 = v519;
      do
      {
        v523 = *v522;
        v522 += 6;
        v524 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21632), v523, v511, v512, v513, v514, v515, v516, v517, v518);
        v525 = (unsigned __int8)a4[8];
        if ( acs_ht40_channels24_g[4 * v520] == v524 )
          break;
        ++v521;
      }
      while ( v521 < v525 );
      if ( (_DWORD)v525 != (unsigned __int8)v521 )
      {
        v526 = &v519[6 * v521];
        if ( (wlansap_is_channel_present_in_acs_list(
                *v526,
                *(_QWORD *)(*(_QWORD *)(v761 + 1544) + 16LL),
                *(unsigned __int8 *)(*(_QWORD *)(v761 + 1544) + 24LL))
            & 1) == 0 )
        {
          v526[3] = 53328;
          *((_BYTE *)v526 + 21) = 1;
          goto LABEL_819;
        }
        if ( *v526 + 20 == v526[24] )
        {
          if ( *v526 + 40 == v526[48] )
          {
            v527 = v526[3];
            v528 = v526[27];
            v529 = v526[51];
            v530 = v528 + v527;
            v531 = v529 + v528;
            if ( v528 + v527 <= v529 + v528 )
            {
              if ( v527 <= v528 )
              {
                v526[3] = v530;
                v526[27] = 53328;
              }
              else
              {
                v526[27] = v530;
                v526[3] = 53327;
              }
              v526[51] = 53328;
            }
            else if ( v528 <= v529 )
            {
              v526[27] = v531;
              v526[3] = 53328;
              v526[51] = 53327;
            }
            else
            {
              v526[51] = v531;
              v526[3] = 53328;
              v526[27] = 53328;
            }
            goto LABEL_819;
          }
          v532 = v526[4];
          v533 = v526[28];
          v99 = v532 > v533;
          v534 = v533 + v532;
          if ( !v99 )
          {
            v526[3] = v534;
            v526[27] = 53328;
            goto LABEL_819;
          }
          v526[27] = v534;
        }
        v526[3] = 53328;
      }
    }
LABEL_819:
    if ( ++v520 != 5 )
      continue;
    break;
  }
  v537 = v730;
  do
  {
    v538 = wlan_reg_legacy_chan_to_freq(*(_QWORD *)(a1 + 21632), v520, v511, v512, v513, v514, v515, v516, v517, v518);
    v539 = a4[8];
    if ( v539 )
    {
      v540 = 0;
      v541 = v519;
      do
      {
        if ( *v541 == v538 && v538 + 20 != v541[24] && v538 - 20 != *(v541 - 24) )
        {
          v541[3] = 53328;
          v539 = a4[8];
        }
        ++v540;
        v541 += 6;
      }
      while ( v540 < v539 );
    }
    v79 = (_DWORD)v520 == v730;
    LODWORD(v520) = v520 + 1;
  }
  while ( !v79 );
  do
  {
    v543 = wlan_reg_legacy_chan_to_freq(
             *(_QWORD *)(a1 + 21632),
             v537 + 1,
             v511,
             v512,
             v513,
             v514,
             v515,
             v516,
             v517,
             v518);
    v544 = a4[8];
    if ( v544 )
    {
      v545 = 0;
      v546 = v519;
      do
      {
        if ( *v546 == v543 && v543 - 20 != *(v546 - 24) )
        {
          v546[3] = 53328;
          v544 = a4[8];
        }
        ++v545;
        v546 += 6;
      }
      while ( v545 < v544 );
    }
    v542 = (unsigned __int8)v537++;
  }
  while ( v542 <= 0xB );
  v547 = *(unsigned int **)a4;
  v548 = _qdf_mem_malloc(0x96u, "sap_sort_chl_weight_ht40_24_g", 2923);
  if ( v548 )
  {
    v557 = (unsigned __int8)a4[8];
    v558 = v548;
    if ( a4[8] )
    {
      v559 = 0;
      v560 = 0;
      v561 = v547 + 3;
      while ( 1 )
      {
        if ( *((_BYTE *)v561 + 8) != 1 )
          goto LABEL_866;
        v549 = scnprintf(
                 v558 + v559,
                 150 - v559,
                 "%d[%d,%d,%d] ",
                 *(v561 - 3),
                 *v561,
                 *(v561 - 1),
                 *((unsigned __int16 *)v561 - 4));
        v559 += v562;
        if ( v559 <= 0x7C )
        {
          v557 = (unsigned __int8)a4[8];
LABEL_866:
          if ( ++v560 >= v557 )
          {
            if ( v559 )
              qdf_trace_msg(
                0x39u,
                8u,
                "ACS 40 Mhz freq score: %s",
                v549,
                v550,
                v551,
                v552,
                v553,
                v554,
                v555,
                v556,
                v558);
            break;
          }
          v561 += 6;
        }
        else
        {
          qdf_trace_msg(0x39u, 8u, "ACS 40 Mhz freq score: %s", v549, v550, v551, v552, v553, v554, v555, v556, v558);
          v557 = (unsigned __int8)a4[8];
          if ( ++v560 >= v557 )
            break;
          v559 = 0;
          v561 += 6;
        }
      }
    }
    _qdf_mem_free(v558);
    sap_sort_chl_weight(a1, a4, v761);
    if ( v362 )
      goto LABEL_968;
  }
  else if ( v362 )
  {
    goto LABEL_968;
  }
LABEL_973:
  if ( next_lower_bandwidth == v728 )
    next_lower_bandwidth = v728;
  else
    qdf_trace_msg(
      0x39u,
      4u,
      "%s: channel width change from %d to %d",
      v549,
      v550,
      v551,
      v552,
      v553,
      v554,
      v555,
      v556,
      "sap_sort_chl_weight_all");
  if ( (unsigned int)(next_lower_bandwidth - 1) > 6 )
    v638 = 26663;
  else
    v638 = dword_B08F1C[next_lower_bandwidth - 1];
  v639 = v761;
  v640 = *(unsigned int **)a4;
  v641 = _qdf_mem_malloc(0x96u, "sap_dump_sorted_list", 3263);
  if ( !v641 )
    goto LABEL_993;
  v650 = v641;
  qdf_trace_msg(
    0x39u,
    8u,
    "ACS sorted freq list for width %d: freq[weight]:",
    v642,
    v643,
    v644,
    v645,
    v646,
    v647,
    v648,
    v649,
    (unsigned int)next_lower_bandwidth);
  v659 = (unsigned __int8)a4[8];
  if ( !a4[8] )
    goto LABEL_992;
  v660 = 0;
  v661 = 0;
  v662 = v640 + 5;
  while ( 2 )
  {
    while ( *v662 == 1 )
    {
      v663 = *((_DWORD *)v662 - 2);
      if ( v663 >= v638 )
        break;
      v651 = scnprintf(v650 + v660, 150 - v660, "%d[%d] ", *((_DWORD *)v662 - 5), v663);
      v660 += v664;
      if ( v660 <= 0x87 )
      {
        v659 = (unsigned __int8)a4[8];
        break;
      }
      qdf_trace_msg(0x39u, 8u, "%s", v651, v652, v653, v654, v655, v656, v657, v658, v650);
      v659 = (unsigned __int8)a4[8];
      if ( ++v661 >= v659 )
        goto LABEL_992;
      v660 = 0;
      v662 += 24;
    }
    if ( ++v661 < v659 )
    {
      v662 += 24;
      continue;
    }
    break;
  }
  if ( v660 )
    qdf_trace_msg(0x39u, 8u, "%s", v651, v652, v653, v654, v655, v656, v657, v658, v650);
LABEL_992:
  _qdf_mem_free(v650);
  v639 = v761;
LABEL_993:
  *(_WORD *)(*(_QWORD *)(v639 + 1544) + 42LL) = next_lower_bandwidth;
  if ( a5 )
    *a5 = v762;
  if ( a6 )
  {
    result = 0;
    *a6 = v753;
    goto LABEL_48;
  }
LABEL_47:
  result = 0;
LABEL_48:
  _ReadStatusReg(SP_EL0);
  return result;
}
