__int64 __fastcall wma_rx_ready_event(
        __int64 a1,
        __int64 *a2,
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
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x21
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 v37; // x21
  __int64 v38; // x8
  __int64 v39; // x8
  int v40; // w9
  __int16 v41; // w10
  int v42; // w8
  bool is_dual_mac_disabled_in_ini; // w0
  int v44; // w8
  int v45; // w9
  const char *v46; // x2
  const char *v47; // x3
  const char *v48; // x2
  const char *v49; // x2
  __int64 v50; // x20
  int v51; // w8
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  _QWORD *context; // x20
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x8
  __int64 v70; // x21
  __int64 v71; // x22
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  __int64 v80; // x24
  double v81; // d0
  double v82; // d1
  double v83; // d2
  double v84; // d3
  double v85; // d4
  double v86; // d5
  double v87; // d6
  double v88; // d7
  char v89; // w0
  unsigned int v90; // w25
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
  unsigned int v131; // w20
  __int64 v132; // x8
  __int64 v133; // x28
  unsigned __int8 i; // w27
  __int64 result; // x0
  _DWORD *v136; // x9
  _DWORD *v137; // x8
  unsigned int v138; // w4
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  int v147; // w9
  __int64 v148; // x0
  unsigned int v149; // w1
  int v150; // w8
  int v151; // w10
  double v152; // d0
  double v153; // d1
  double v154; // d2
  double v155; // d3
  double v156; // d4
  double v157; // d5
  double v158; // d6
  double v159; // d7
  double v160; // d0
  double v161; // d1
  double v162; // d2
  double v163; // d3
  double v164; // d4
  double v165; // d5
  double v166; // d6
  double v167; // d7
  double v168; // d0
  double v169; // d1
  double v170; // d2
  double v171; // d3
  double v172; // d4
  double v173; // d5
  double v174; // d6
  double v175; // d7
  double v176; // d0
  double v177; // d1
  double v178; // d2
  double v179; // d3
  double v180; // d4
  double v181; // d5
  double v182; // d6
  double v183; // d7
  int v184; // w9
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  int v193; // w8
  double v194; // d0
  double v195; // d1
  double v196; // d2
  double v197; // d3
  double v198; // d4
  double v199; // d5
  double v200; // d6
  double v201; // d7
  double v202; // d0
  double v203; // d1
  double v204; // d2
  double v205; // d3
  double v206; // d4
  double v207; // d5
  double v208; // d6
  double v209; // d7
  double v210; // d0
  double v211; // d1
  double v212; // d2
  double v213; // d3
  double v214; // d4
  double v215; // d5
  double v216; // d6
  double v217; // d7
  double v218; // d0
  double v219; // d1
  double v220; // d2
  double v221; // d3
  double v222; // d4
  double v223; // d5
  double v224; // d6
  double v225; // d7
  double v226; // d0
  double v227; // d1
  double v228; // d2
  double v229; // d3
  double v230; // d4
  double v231; // d5
  double v232; // d6
  double v233; // d7
  double v234; // d0
  double v235; // d1
  double v236; // d2
  double v237; // d3
  double v238; // d4
  double v239; // d5
  double v240; // d6
  double v241; // d7
  double v242; // d0
  double v243; // d1
  double v244; // d2
  double v245; // d3
  double v246; // d4
  double v247; // d5
  double v248; // d6
  double v249; // d7
  double v250; // d0
  double v251; // d1
  double v252; // d2
  double v253; // d3
  double v254; // d4
  double v255; // d5
  double v256; // d6
  double v257; // d7
  double v258; // d0
  double v259; // d1
  double v260; // d2
  double v261; // d3
  double v262; // d4
  double v263; // d5
  double v264; // d6
  double v265; // d7
  double v266; // d0
  double v267; // d1
  double v268; // d2
  double v269; // d3
  double v270; // d4
  double v271; // d5
  double v272; // d6
  double v273; // d7
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  double v282; // d0
  double v283; // d1
  double v284; // d2
  double v285; // d3
  double v286; // d4
  double v287; // d5
  double v288; // d6
  double v289; // d7
  double v290; // d0
  double v291; // d1
  double v292; // d2
  double v293; // d3
  double v294; // d4
  double v295; // d5
  double v296; // d6
  double v297; // d7
  _QWORD *v298; // x0
  double v299; // d0
  double v300; // d1
  double v301; // d2
  double v302; // d3
  double v303; // d4
  double v304; // d5
  double v305; // d6
  double v306; // d7
  __int64 v307; // x8
  __int64 v308; // x8
  const char *v309; // x2
  unsigned int v310; // w1
  double v311; // d0
  double v312; // d1
  double v313; // d2
  double v314; // d3
  double v315; // d4
  double v316; // d5
  double v317; // d6
  double v318; // d7
  double v319; // d0
  double v320; // d1
  double v321; // d2
  double v322; // d3
  double v323; // d4
  double v324; // d5
  double v325; // d6
  double v326; // d7
  unsigned int v327; // w23
  _QWORD *v328; // x24
  double v329; // d0
  double v330; // d1
  double v331; // d2
  double v332; // d3
  double v333; // d4
  double v334; // d5
  double v335; // d6
  double v336; // d7
  _QWORD *v337; // x0
  double v338; // d0
  double v339; // d1
  double v340; // d2
  double v341; // d3
  double v342; // d4
  double v343; // d5
  double v344; // d6
  double v345; // d7
  __int64 v346; // x8
  void (*v347)(void); // x8
  double updated; // d0
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
  char v484; // w0
  unsigned int v485; // w3
  int v486; // w11
  double v487; // d0
  double v488; // d1
  double v489; // d2
  double v490; // d3
  double v491; // d4
  double v492; // d5
  double v493; // d6
  double v494; // d7
  double v495; // d0
  double v496; // d1
  double v497; // d2
  double v498; // d3
  double v499; // d4
  double v500; // d5
  double v501; // d6
  double v502; // d7
  unsigned int v503; // w8
  int v504; // w3
  int v505; // w4
  double v506; // d0
  double v507; // d1
  double v508; // d2
  double v509; // d3
  double v510; // d4
  double v511; // d5
  double v512; // d6
  double v513; // d7
  unsigned int v514; // w9
  __int64 v515; // x25
  _DWORD *v516; // x24
  int v517; // w8
  _DWORD *v518; // x10
  __int64 v519; // x9
  unsigned int *v520; // x20
  __int64 v521; // x1
  unsigned int v522; // w22
  double v523; // d0
  double v524; // d1
  double v525; // d2
  double v526; // d3
  double v527; // d4
  double v528; // d5
  double v529; // d6
  double v530; // d7
  double v531; // d0
  double v532; // d1
  double v533; // d2
  double v534; // d3
  double v535; // d4
  double v536; // d5
  double v537; // d6
  double v538; // d7
  const char *v539; // x2
  unsigned int v540; // w1
  unsigned int v541; // w9
  __int64 v542; // x25
  int v543; // w8
  __int64 v544; // x9
  int v545; // w26
  int *v546; // x20
  int v547; // w8
  int v548; // w9
  _BOOL4 v549; // w8
  _BOOL4 v550; // w9
  int v551; // w22
  double v552; // d0
  double v553; // d1
  double v554; // d2
  double v555; // d3
  double v556; // d4
  double v557; // d5
  double v558; // d6
  double v559; // d7
  const char *v560; // x2
  unsigned int v561; // w1
  double v562; // d0
  double v563; // d1
  double v564; // d2
  double v565; // d3
  double v566; // d4
  double v567; // d5
  double v568; // d6
  double v569; // d7
  unsigned int v570; // w9
  __int64 v571; // x10
  int v572; // w8
  unsigned int v573; // w8
  __int64 v574; // x0
  int v575; // w8
  int v576; // w9
  int v577; // w10
  __int64 v578; // x0
  char v579; // w8
  char v580; // w0
  __int64 v581; // x8
  double v582; // d0
  double v583; // d1
  double v584; // d2
  double v585; // d3
  double v586; // d4
  double v587; // d5
  double v588; // d6
  double v589; // d7
  char v590; // w0
  char v591; // w8
  char v592; // w9
  __int64 v593; // x0
  double v594; // d0
  double v595; // d1
  double v596; // d2
  double v597; // d3
  double v598; // d4
  double v599; // d5
  double v600; // d6
  double v601; // d7
  double v602; // d0
  double v603; // d1
  double v604; // d2
  double v605; // d3
  double v606; // d4
  double v607; // d5
  double v608; // d6
  double v609; // d7
  double v610; // d0
  double v611; // d1
  double v612; // d2
  double v613; // d3
  double v614; // d4
  double v615; // d5
  double v616; // d6
  double v617; // d7
  double v618; // d0
  double v619; // d1
  double v620; // d2
  double v621; // d3
  double v622; // d4
  double v623; // d5
  double v624; // d6
  double v625; // d7
  double v626; // d0
  double v627; // d1
  double v628; // d2
  double v629; // d3
  double v630; // d4
  double v631; // d5
  double v632; // d6
  double v633; // d7
  double v634; // d0
  double v635; // d1
  double v636; // d2
  double v637; // d3
  double v638; // d4
  double v639; // d5
  double v640; // d6
  double v641; // d7
  double v642; // d0
  double v643; // d1
  double v644; // d2
  double v645; // d3
  double v646; // d4
  double v647; // d5
  double v648; // d6
  double v649; // d7
  double v650; // d0
  double v651; // d1
  double v652; // d2
  double v653; // d3
  double v654; // d4
  double v655; // d5
  double v656; // d6
  double v657; // d7
  double v658; // d0
  double v659; // d1
  double v660; // d2
  double v661; // d3
  double v662; // d4
  double v663; // d5
  double v664; // d6
  double v665; // d7
  double v666; // d0
  double v667; // d1
  double v668; // d2
  double v669; // d3
  double v670; // d4
  double v671; // d5
  double v672; // d6
  double v673; // d7
  double v674; // d0
  double v675; // d1
  double v676; // d2
  double v677; // d3
  double v678; // d4
  double v679; // d5
  double v680; // d6
  double v681; // d7
  double v682; // d0
  double v683; // d1
  double v684; // d2
  double v685; // d3
  double v686; // d4
  double v687; // d5
  double v688; // d6
  double v689; // d7
  double v690; // d0
  double v691; // d1
  double v692; // d2
  double v693; // d3
  double v694; // d4
  double v695; // d5
  double v696; // d6
  double v697; // d7
  char v698; // w0
  double v699; // d0
  double v700; // d1
  double v701; // d2
  double v702; // d3
  double v703; // d4
  double v704; // d5
  double v705; // d6
  double v706; // d7
  unsigned int v707; // w20
  __int64 v708; // x25
  unsigned __int8 j; // w24
  _DWORD *v710; // x9
  _DWORD *v711; // x8
  unsigned int v712; // w4
  unsigned __int64 v713; // x24
  unsigned __int8 *v714; // x25
  _BYTE *v715; // x0
  unsigned int v716; // w8
  unsigned int v717; // w8
  unsigned int v718; // w8
  unsigned int v719; // w8
  unsigned int v720; // w8
  unsigned int v721; // w8
  unsigned int v722; // w8
  unsigned int v723; // w8
  _DWORD *v724; // x8
  double v725; // d0
  double v726; // d1
  double v727; // d2
  double v728; // d3
  double v729; // d4
  double v730; // d5
  double v731; // d6
  double v732; // d7
  __int64 v733; // [xsp+0h] [xbp-380h]
  __int64 v734; // [xsp+0h] [xbp-380h]
  __int64 v735; // [xsp+8h] [xbp-378h]
  __int64 v736; // [xsp+8h] [xbp-378h]
  __int64 v737; // [xsp+10h] [xbp-370h]
  __int64 v738; // [xsp+10h] [xbp-370h]
  __int64 v739; // [xsp+18h] [xbp-368h]
  __int64 v740; // [xsp+18h] [xbp-368h]
  __int64 v741; // [xsp+20h] [xbp-360h]
  __int64 v742; // [xsp+38h] [xbp-348h]
  _QWORD *v743; // [xsp+40h] [xbp-340h]
  int v744; // [xsp+4Ch] [xbp-334h] BYREF
  __int16 v745; // [xsp+50h] [xbp-330h] BYREF
  _BYTE v746[4]; // [xsp+54h] [xbp-32Ch] BYREF
  __int64 v747; // [xsp+58h] [xbp-328h] BYREF
  __int64 v748; // [xsp+60h] [xbp-320h]
  __int64 v749; // [xsp+68h] [xbp-318h]
  __int64 v750; // [xsp+70h] [xbp-310h]
  __int64 v751; // [xsp+78h] [xbp-308h]
  __int64 v752; // [xsp+80h] [xbp-300h]
  __int64 v753; // [xsp+88h] [xbp-2F8h]
  _QWORD s[75]; // [xsp+90h] [xbp-2F0h] BYREF
  __int64 v755; // [xsp+2E8h] [xbp-98h] BYREF
  __int64 v756; // [xsp+2F0h] [xbp-90h]
  __int64 v757; // [xsp+2F8h] [xbp-88h]
  __int64 v758; // [xsp+300h] [xbp-80h]
  __int64 v759; // [xsp+308h] [xbp-78h]
  __int64 v760; // [xsp+310h] [xbp-70h]
  __int64 v761; // [xsp+318h] [xbp-68h]
  __int64 v762; // [xsp+320h] [xbp-60h]
  __int64 v763; // [xsp+328h] [xbp-58h]
  __int64 v764; // [xsp+330h] [xbp-50h]
  __int64 v765; // [xsp+338h] [xbp-48h]
  __int64 v766; // [xsp+340h] [xbp-40h]
  __int64 v767; // [xsp+348h] [xbp-38h]
  __int64 v768; // [xsp+350h] [xbp-30h]
  __int64 v769; // [xsp+358h] [xbp-28h]
  __int64 v770; // [xsp+360h] [xbp-20h]
  int v771; // [xsp+368h] [xbp-18h]
  __int64 v772; // [xsp+370h] [xbp-10h]

  v772 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", a3, a4, a5, a6, a7, a8, a9, a10, "wma_rx_ready_event");
  if ( !a1 || !a2 )
  {
    v46 = "%s: Invalid arguments";
    v47 = "wma_rx_ready_event";
LABEL_44:
    qdf_trace_msg(0x36u, 2u, v46, v12, v13, v14, v15, v16, v17, v18, v19, v47);
    goto LABEL_45;
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: WMA <-- WMI_READY_EVENTID",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "wma_rx_ready_event");
  v28 = *(_QWORD *)(a1 + 8);
  if ( !v28 )
  {
    v48 = "%s: Invalid cds context";
LABEL_29:
    qdf_trace_msg(0x36u, 2u, v48, v20, v21, v22, v23, v24, v25, v26, v27, "wma_is_feature_set_supported");
    goto LABEL_36;
  }
  if ( !*(_QWORD *)(v28 + 152) )
  {
    v48 = "%s: Invalid cds config";
    goto LABEL_29;
  }
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0x119u, v20, v21, v22, v23, v24, v25, v26, v27) & 1) == 0 )
  {
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Get wifi feature is disabled from fw",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      "wma_is_feature_set_supported");
    goto LABEL_36;
  }
  if ( *(_BYTE *)(*(_QWORD *)(v28 + 152) + 144LL) != 1 )
    goto LABEL_36;
  v37 = *(_QWORD *)(a1 + 24);
  v38 = *(_QWORD *)(a1 + 8);
  memset(s, 0, 92);
  v745 = 0;
  LODWORD(v747) = 0;
  v758 = 0;
  v757 = 0;
  v756 = 0;
  v755 = 0;
  v744 = 0;
  if ( v37 )
  {
    if ( v38 )
    {
      v39 = *(_QWORD *)(v38 + 152);
      if ( v39 )
      {
        v40 = *(_DWORD *)(v39 + 132);
        v41 = *(_WORD *)(v39 + 136);
        v42 = *(_DWORD *)(v39 + 140);
        v746[0] = 0;
        LODWORD(s[0]) = v40;
        LOWORD(s[2]) = v41;
        HIDWORD(s[2]) = v42;
        is_dual_mac_disabled_in_ini = policy_mgr_is_dual_mac_disabled_in_ini(v37);
        v44 = 0;
        if ( !is_dual_mac_disabled_in_ini )
        {
          policy_mgr_get_sbs_cfg(v37, v746);
          if ( v746[0] )
            v44 = 2;
          else
            v44 = 1;
        }
        HIDWORD(s[0]) = v44;
        wlan_scan_get_feature_info(v37, &v745);
        LOBYTE(s[1]) = v745;
        if ( (unsigned __int8)v745 == 1 )
          BYTE1(s[1]) = HIBYTE(v745);
        wlan_twt_get_feature_info(v37, &v747);
        BYTE2(s[1]) = v747;
        if ( (unsigned __int8)v747 == 1 )
        {
          BYTE3(s[1]) = BYTE1(v747);
          WORD2(s[1]) = WORD1(v747);
        }
        HIBYTE(s[1]) = 1;
        wlan_mlme_get_feature_info(v37, (__int64)&v755);
        BYTE4(s[3]) = 1;
        LOBYTE(s[3]) = BYTE1(v755);
        BYTE6(s[1]) = v755;
        WORD2(s[4]) = WORD1(v755);
        BYTE4(s[6]) = 1;
        LODWORD(s[6]) = HIDWORD(v757);
        LODWORD(s[4]) = v757;
        *(_DWORD *)((char *)&s[5] + 2) = v756;
        *(_DWORD *)((char *)&s[4] + 6) = HIDWORD(v755);
        HIWORD(s[5]) = WORD2(v756);
        if ( (_BYTE)v758 )
          v45 = 2;
        else
          v45 = 1;
        HIDWORD(s[9]) = v45;
        HIDWORD(s[10]) = HIDWORD(v758);
        *(_WORD *)((char *)&s[3] + 1) = 257;
        BYTE3(s[3]) = s[0];
        BYTE5(s[6]) = ucfg_dp_is_local_pkt_capture_enabled();
        BYTE6(s[6]) = BYTE5(s[6]);
        HIBYTE(s[6]) = BYTE5(s[6]);
        s[7] = 0x101010101010101LL;
        LOBYTE(s[8]) = 1;
        BYTE1(s[8]) = cfg_nan_get_enable(v37) & 1;
        wlan_tdls_get_features_info(v37, &v744);
        BYTE2(s[8]) = v744;
        if ( (unsigned __int8)v744 == 1 )
        {
          BYTE6(s[8]) = BYTE2(v744);
          BYTE4(s[8]) = BYTE1(v744);
          BYTE5(s[8]) = HIBYTE(v744);
        }
        if ( BYTE1(s[2]) == 1 )
          BYTE3(s[8]) = policy_mgr_is_6ghz_conc_mode_supported(v37, 2);
        *(_WORD *)((char *)&s[8] + 7) = 257;
        BYTE1(s[9]) = 1;
        LOBYTE(s[10]) = 1;
        LOBYTE(s[11]) = cfg_nan_is_eht_cap_enable(v37) & 1;
        WORD1(s[9]) = 11;
        goto LABEL_35;
      }
      v49 = "%s: Invalid cds config";
    }
    else
    {
      v49 = "%s: Invalid cds context";
    }
  }
  else
  {
    v49 = "%s: Invalid psoc";
  }
  qdf_trace_msg(0x36u, 2u, v49, v29, v30, v31, v32, v33, v34, v35, v36, "wma_set_feature_set_info");
LABEL_35:
  wmi_feature_set_cmd_send(*(_QWORD *)a1);
LABEL_36:
  v50 = *a2;
  *(_BYTE *)(a1 + 3778) = wmi_service_enabled(*(_QWORD *)a1, 0x76u, v29, v30, v31, v32, v33, v34, v35, v36) & 1;
  *(_BYTE *)(a1 + 178) = 1;
  v51 = *(unsigned __int8 *)(a1 + 3779);
  *(_DWORD *)(a1 + 180) = *(_DWORD *)(v50 + 36);
  if ( v51 == 1 )
    wmi_unified_dfs_phyerr_offload_en_cmd(*(_QWORD *)a1);
  *(_WORD *)(a1 + 164) = *(_DWORD *)(v50 + 28);
  *(_BYTE *)(a1 + 166) = *(_WORD *)(v50 + 30);
  *(_BYTE *)(a1 + 167) = *(_BYTE *)(v50 + 31);
  *(_WORD *)(a1 + 168) = *(_DWORD *)(v50 + 32);
  *(_WORD *)(a1 + 170) = *(_DWORD *)(v50 + 28);
  *(_BYTE *)(a1 + 172) = *(_WORD *)(v50 + 30);
  *(_BYTE *)(a1 + 173) = *(_BYTE *)(v50 + 31);
  *(_WORD *)(a1 + 174) = *(_DWORD *)(v50 + 32);
  memset(s, 0, 0x254u);
  context = _cds_get_context(51, (__int64)"wma_update_hdd_cfg", v52, v53, v54, v55, v56, v57, v58, v59);
  qdf_trace_msg(0x36u, 8u, "%s: Enter", v61, v62, v63, v64, v65, v66, v67, v68, "wma_update_hdd_cfg");
  v69 = *(_QWORD *)(a1 + 24);
  if ( !v69 || (v70 = *(_QWORD *)(v69 + 2800)) == 0 )
  {
    v46 = "%s: target psoc info is NULL";
    v47 = "wma_update_hdd_cfg";
    goto LABEL_44;
  }
  v71 = *(_QWORD *)(v70 + 16);
  if ( (unsigned int)_wmi_validate_handle(v71, (__int64)"wma_update_hdd_cfg", v12, v13, v14, v15, v16, v17, v18, v19) )
  {
LABEL_45:
    result = 4294967274LL;
    goto LABEL_46;
  }
  v80 = *(_QWORD *)(a1 + 24);
  v743 = context;
  BYTE3(v755) = 0;
  LOBYTE(v755) = wmi_service_enabled(v71, 0xB5u, v72, v73, v74, v75, v76, v77, v78, v79) & 1;
  v89 = wmi_service_enabled(v71, 0xC9u, v81, v82, v83, v84, v85, v86, v87, v88);
  v90 = v89 & 1;
  BYTE1(v755) = v89 & 1;
  BYTE2(v755) = wmi_service_enabled(v71, 0xCBu, v91, v92, v93, v94, v95, v96, v97, v98) & 1;
  BYTE4(v755) = wmi_service_enabled(v71, 0xD1u, v99, v100, v101, v102, v103, v104, v105, v106) & 1;
  BYTE5(v755) = wmi_service_enabled(v71, 0xD7u, v107, v108, v109, v110, v111, v112, v113, v114) & 1;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: beacon protection support %d, ocv support %d",
    v115,
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    "wma_update_mlme_related_tgt_caps",
    v90);
  wlan_mlme_update_cfg_with_tgt_caps(v80, &v755);
  v131 = *(_DWORD *)(v70 + 1020);
  v132 = *(_QWORD *)(a1 + 24);
  v771 = 0;
  v770 = 0;
  v769 = 0;
  v768 = 0;
  v767 = 0;
  v766 = 0;
  v765 = 0;
  v764 = 0;
  v763 = 0;
  v762 = 0;
  v761 = 0;
  v760 = 0;
  v759 = 0;
  v758 = 0;
  v757 = 0;
  v742 = v132;
  v756 = 0;
  v755 = 0;
  if ( v131 )
  {
    v133 = *(_QWORD *)(v70 + 4496);
    for ( i = 0; i < v131; ++i )
    {
      v137 = (_DWORD *)(v133 + 20LL * i);
      if ( !*v137 )
      {
        v138 = v137[1];
        if ( v138 < 0xB )
        {
          v136 = (_DWORD *)&v755 + 3 * v138;
          *v136 = v137[2];
          v136[1] = v137[3];
          v136[2] = v137[4];
        }
        else
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: invalid hw mode id %d.",
            v123,
            v124,
            v125,
            v126,
            v127,
            v128,
            v129,
            v130,
            "wma_update_mlme_aux_dev_caps");
        }
      }
    }
  }
  wlan_mlme_update_aux_dev_caps(v742, &v755);
  if ( (wmi_service_enabled(v71, 0xD2u, v139, v140, v141, v142, v143, v144, v145, v146) & 1) != 0 )
    *(_DWORD *)(*(_QWORD *)(a1 + 24) + 20LL) |= 0x10000000u;
  qdf_mem_set(s, 0x254u, 0);
  v147 = *(_DWORD *)(a1 + 460);
  v148 = *(_QWORD *)(a1 + 24);
  v149 = *(_DWORD *)(v70 + 424);
  BYTE1(s[21]) = *(_BYTE *)(a1 + 3778);
  v150 = *(_DWORD *)(a1 + 464);
  v151 = *(_DWORD *)(v70 + 64);
  HIDWORD(s[1]) = v147;
  LODWORD(s[2]) = v150;
  LOBYTE(s[20]) = v151;
  policy_mgr_set_max_conc_cxns(v148, v149);
  qdf_mem_copy((char *)&s[2] + 4, (const void *)(a1 + 170), 6u);
  HIDWORD(s[3]) = wmi_service_enabled(v71, 4u, v152, v153, v154, v155, v156, v157, v158, v159) & 1;
  LOBYTE(s[4]) = wmi_service_enabled(v71, 6u, v160, v161, v162, v163, v164, v165, v166, v167) & 1;
  HIDWORD(s[4]) = wmi_service_enabled(v71, 7u, v168, v169, v170, v171, v172, v173, v174, v175) & 1;
  v184 = wmi_service_enabled(v71, 8u, v176, v177, v178, v179, v180, v181, v182, v183) & 1;
  v193 = g_fw_wlan_feat_caps;
  LODWORD(s[5]) = v184;
  if ( v184 )
    v193 = g_fw_wlan_feat_caps | 4;
  g_fw_wlan_feat_caps = v193 | 0x10400000;
  HIDWORD(s[5]) = wmi_service_enabled(v71, 0x2Eu, v185, v186, v187, v188, v189, v190, v191, v192) & 1;
  LODWORD(s[6]) = wmi_service_enabled(v71, 0x21u, v194, v195, v196, v197, v198, v199, v200, v201) & 1;
  LOBYTE(s[10]) = wmi_service_enabled(v71, 0x23u, v202, v203, v204, v205, v206, v207, v208, v209) & 1;
  if ( (wmi_service_enabled(v71, 0x2Fu, v210, v211, v212, v213, v214, v215, v216, v217) & 1) != 0 )
  {
    BYTE4(s[6]) = 1;
    g_fw_wlan_feat_caps |= 0x400u;
  }
  LODWORD(s[7]) = wmi_service_enabled(v71, 0x3Au, v218, v219, v220, v221, v222, v223, v224, v225) & 1;
  if ( (wmi_service_enabled(v71, 0x34u, v226, v227, v228, v229, v230, v231, v232, v233) & 1) != 0 )
  {
    BYTE4(s[7]) = 1;
    g_fw_wlan_feat_caps |= 0x40u;
  }
  if ( (wmi_service_enabled(v71, 0x47u, v234, v235, v236, v237, v238, v239, v240, v241) & 1) != 0 )
  {
    BYTE5(s[7]) = 1;
    g_fw_wlan_feat_caps |= 0x40000000u;
  }
  BYTE6(s[7]) = wmi_service_enabled(v71, 0x48u, v242, v243, v244, v245, v246, v247, v248, v249) & 1;
  HIBYTE(s[7]) = wmi_service_enabled(v71, 0x49u, v250, v251, v252, v253, v254, v255, v256, v257) & 1;
  if ( (wmi_service_enabled(v71, 0, v258, v259, v260, v261, v262, v263, v264, v265) & 1) != 0 )
    BYTE5(s[6]) = 1;
  if ( (wmi_service_enabled(v71, 0x6Au, v266, v267, v268, v269, v270, v271, v272, v273) & 1) != 0 )
    BYTE6(s[6]) = 1;
  BYTE3(s[8]) = wmi_service_enabled(v71, 0x4Fu, v274, v275, v276, v277, v278, v279, v280, v281) & 1;
  if ( (wmi_service_enabled(v71, 0x43u, v282, v283, v284, v285, v286, v287, v288, v289) & 1) != 0 )
    g_fw_wlan_feat_caps |= 0x800u;
  v298 = _cds_get_context(54, (__int64)"wma_nan_set_pairing_feature", v290, v291, v292, v293, v294, v295, v296, v297);
  if ( !v298 )
  {
    v309 = "%s: wma handle is null";
    goto LABEL_75;
  }
  v307 = v298[3];
  if ( !v307 || (v308 = *(_QWORD *)(v307 + 2800)) == 0 )
  {
    v309 = "%s: tgt_hdl is null";
LABEL_75:
    v310 = 2;
    goto LABEL_76;
  }
  if ( !*(_DWORD *)(v308 + 976) )
    goto LABEL_77;
  v309 = "%s: Secure NAN is enabled";
  v310 = 8;
  g_fw_wlan_feat_caps |= 0x8000u;
LABEL_76:
  qdf_trace_msg(0x36u, v310, v309, v299, v300, v301, v302, v303, v304, v305, v306, "wma_nan_set_pairing_feature");
LABEL_77:
  if ( (wmi_service_enabled(v71, 0xCu, v299, v300, v301, v302, v303, v304, v305, v306) & 1) != 0 )
    g_fw_wlan_feat_caps |= 0x1000u;
  if ( (wmi_service_enabled(v71, 0x7Eu, v311, v312, v313, v314, v315, v316, v317, v318) & 1) != 0 )
    v327 = 0x2000;
  else
    v327 = 3000;
  v328 = _cds_get_context(71, (__int64)"wma_set_tx_partition_base", v319, v320, v321, v322, v323, v324, v325, v326);
  v337 = _cds_get_context(65, (__int64)"wma_set_tx_partition_base", v329, v330, v331, v332, v333, v334, v335, v336);
  if ( v328 && *v328 && v337 && (v346 = *(_QWORD *)(*v328 + 152LL)) != 0 )
  {
    v347 = *(void (**)(void))(v346 + 72);
    if ( v347 )
    {
      if ( *((_DWORD *)v347 - 1) != -107830899 )
        __break(0x8228u);
      v347();
    }
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      1u,
      "%s invalid instance",
      v338,
      v339,
      v340,
      v341,
      v342,
      v343,
      v344,
      v345,
      "cdp_ipa_set_uc_tx_partition_base");
  }
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: TX_MSDU_ID_PARTITION=%d",
    v338,
    v339,
    v340,
    v341,
    v342,
    v343,
    v344,
    v345,
    "wma_set_tx_partition_base",
    v327);
  updated = wma_he_update_tgt_services(v71, (char *)&s[3] + 4);
  BYTE2(s[10]) = 0;
  BYTE5(s[8]) = wmi_service_enabled(v71, 0x82u, updated, v349, v350, v351, v352, v353, v354, v355) & 1;
  if ( (wmi_service_enabled(v71, 0x90u, v356, v357, v358, v359, v360, v361, v362, v363) & 1) != 0 )
    BYTE6(s[8]) = 1;
  if ( (wmi_service_enabled(v71, 0x91u, v364, v365, v366, v367, v368, v369, v370, v371) & 1) != 0 )
    HIBYTE(s[8]) = 1;
  if ( (wmi_service_enabled(v71, 0x93u, v372, v373, v374, v375, v376, v377, v378, v379) & 1) != 0 )
    LOBYTE(s[9]) = 1;
  if ( (wmi_service_enabled(v71, 0x9Au, v380, v381, v382, v383, v384, v385, v386, v387) & 1) != 0 )
    BYTE1(s[9]) = 1;
  if ( (wmi_service_enabled(v71, 0x9Bu, v388, v389, v390, v391, v392, v393, v394, v395) & 1) != 0 )
    BYTE2(s[9]) = 1;
  if ( (wmi_service_enabled(v71, 0x46u, v396, v397, v398, v399, v400, v401, v402, v403) & 1) != 0 )
    BYTE3(s[9]) = 1;
  if ( (wmi_service_enabled(v71, 0xA4u, v404, v405, v406, v407, v408, v409, v410, v411) & 1) != 0 )
    BYTE4(s[9]) = 1;
  if ( (wmi_service_enabled(v71, 0xA5u, v412, v413, v414, v415, v416, v417, v418, v419) & 1) != 0 )
    g_fw_wlan_feat_caps |= 0x80000000;
  if ( (wmi_service_enabled(v71, 0xC8u, v420, v421, v422, v423, v424, v425, v426, v427) & 1) != 0 )
    BYTE5(s[9]) = 1;
  BYTE6(s[9]) = wmi_service_enabled(v71, 0xD8u, v428, v429, v430, v431, v432, v433, v434, v435) & 1;
  HIBYTE(s[9]) = wmi_service_enabled(v71, 0xDCu, v436, v437, v438, v439, v440, v441, v442, v443) & 1;
  BYTE1(s[10]) = wmi_service_enabled(v71, 0xF1u, v444, v445, v446, v447, v448, v449, v450, v451) & 1;
  BYTE1(s[8]) = wmi_service_enabled(v71, 0xF2u, v452, v453, v454, v455, v456, v457, v458, v459) & 1;
  BYTE2(s[8]) = wmi_service_enabled(v71, 0x114u, v460, v461, v462, v463, v464, v465, v466, v467) & 1;
  LOBYTE(s[8]) = wmi_service_enabled(v71, 0x115u, v468, v469, v470, v471, v472, v473, v474, v475) & 1;
  v484 = wmi_service_enabled(v71, 0x105u, v476, v477, v478, v479, v480, v481, v482, v483);
  v485 = *(_DWORD *)(v70 + 692);
  v486 = *(_DWORD *)(v70 + 688);
  BYTE3(s[10]) = v484 & 1;
  HIDWORD(s[10]) = v485 & 0x700;
  LOBYTE(s[11]) = (v485 & 0x30) != 0;
  BYTE1(s[11]) = (v485 & 8) != 0;
  BYTE2(s[11]) = (v485 & 0x40) != 0;
  BYTE3(s[11]) = (v485 & 2) != 0;
  BYTE4(s[11]) = (v485 & 0x800) != 0;
  BYTE4(s[12]) = (v485 & 4) != 0;
  LODWORD(s[12]) = v486;
  qdf_trace_msg(
    0x36u,
    8u,
    "ht_cap_info - %x ht_rx_stbc - %d, ht_tx_stbc - %d\n"
    "mpdu_density - %d ht_rx_ldpc - %d ht_sgi_20 - %d\n"
    "ht_sgi_40 - %d num_rf_chains - %d dynamic_smps - %d",
    v487,
    v488,
    v489,
    v490,
    v491,
    v492,
    v493,
    v494,
    (v485 >> 1) & 1,
    (v485 >> 11) & 1,
    v486,
    (v485 >> 2) & 1);
  v503 = *(_DWORD *)(v70 + 696);
  if ( (v503 & 2) != 0 )
    v504 = 2;
  else
    v504 = *(_DWORD *)(v70 + 696) & 1;
  LODWORD(s[13]) = v504;
  if ( (v503 & 8) != 0 )
  {
    v505 = 24;
  }
  else if ( (v503 & 4) != 0 )
  {
    v505 = 8;
  }
  else
  {
    v505 = 4;
  }
  LODWORD(s[15]) = v503 & 0x40;
  HIDWORD(s[16]) = v503 & 0x800;
  HIDWORD(s[17]) = v503 & 0x80000;
  HIDWORD(s[13]) = v505;
  LODWORD(s[14]) = v503 & 0x10;
  HIDWORD(s[14]) = v503 & 0x20;
  HIDWORD(s[15]) = v503 & 0x80;
  LODWORD(s[16]) = v503 & 0x300;
  LODWORD(s[17]) = v503 & 0x1000;
  HIDWORD(s[18]) = (v503 >> 23) & 7;
  LODWORD(s[18]) = v503 & 0x100000;
  LODWORD(s[19]) = v503 & 0x200000;
  LODWORD(v739) = v503 & 0x100000;
  LODWORD(v737) = LOWORD(s[17]);
  LODWORD(v735) = v503 & 0x200000;
  LODWORD(v733) = LOWORD(s[16]);
  qdf_trace_msg(
    0x36u,
    8u,
    "max_mpdu %d supp_chan_width %x rx_ldpc %x\n"
    "short_gi_80 %x tx_stbc %x rx_stbc %x txop_ps %x\n"
    "su_bformee %x mu_bformee %x max_ampdu_len_exp %d",
    v495,
    v496,
    v497,
    v498,
    v499,
    v500,
    v501,
    v502,
    v733,
    v735,
    v737,
    v739,
    HIDWORD(s[18]));
  v514 = *(_DWORD *)(v70 + 504);
  v515 = *(unsigned __int8 *)(v70 + 486);
  v516 = (_DWORD *)(v70 + 1072);
  v517 = *(_DWORD *)(v70 + 824);
  v518 = (_DWORD *)(v70 + 1072);
  LODWORD(v757) = 0;
  v756 = 0;
  v755 = 0;
  LODWORD(v749) = 0;
  v747 = 0;
  v748 = 0;
  if ( v514 <= 0xA )
  {
    if ( *v516 == v514 )
    {
      v519 = 0;
    }
    else if ( *(_DWORD *)(v70 + 1328) == v514 )
    {
      v519 = 1;
    }
    else if ( *(_DWORD *)(v70 + 1584) == v514 )
    {
      v519 = 2;
    }
    else if ( *(_DWORD *)(v70 + 1840) == v514 )
    {
      v519 = 3;
    }
    else if ( *(_DWORD *)(v70 + 2096) == v514 )
    {
      v519 = 4;
    }
    else if ( *(_DWORD *)(v70 + 2352) == v514 )
    {
      v519 = 5;
    }
    else if ( *(_DWORD *)(v70 + 2608) == v514 )
    {
      v519 = 6;
    }
    else
    {
      if ( *(_DWORD *)(v70 + 2864) != v514 )
      {
LABEL_147:
        v539 = "%s: Invalid MAC PHY capabilities handle";
        v540 = 2;
LABEL_149:
        qdf_trace_msg(0x36u, v540, v539, v506, v507, v508, v509, v510, v511, v512, v513, "wma_update_target_ext_ht_cap");
        goto LABEL_150;
      }
      v519 = 7;
    }
    v518 = &v516[64 * v519];
  }
  if ( !v518 )
    goto LABEL_147;
  if ( !v517 )
  {
    v539 = "%s: No extended HT cap for current SOC";
    v540 = 8;
    goto LABEL_149;
  }
  if ( (_DWORD)v515 )
  {
    v520 = v518 + 15;
    do
    {
      v521 = *(v520 - 6);
      v522 = v520[3];
      if ( (_DWORD)v521 )
        wma_derive_ext_ht_cap(&v755, v521, *v520, v520[1]);
      if ( v522 )
        wma_derive_ext_ht_cap(&v755, v522, v520[9], v520[10]);
      --v515;
      v520 += 64;
    }
    while ( v515 );
  }
  if ( (unsigned int)qdf_mem_cmp(&v747, &v755, 0x14u) )
    qdf_mem_copy((char *)&s[10] + 4, &v755, 0x14u);
  LODWORD(v734) = BYTE4(s[11]);
  LODWORD(v738) = BYTE4(s[12]);
  LODWORD(v736) = s[12];
  qdf_trace_msg(
    0x36u,
    8u,
    "[ext ht cap] ht_rx_stbc - %d, ht_tx_stbc - %d\n"
    "mpdu_density - %d ht_rx_ldpc - %d ht_sgi_20 - %d\n"
    "ht_sgi_40 - %d num_rf_chains - %d dynamic_smps - %d",
    v523,
    v524,
    v525,
    v526,
    v527,
    v528,
    v529,
    v530,
    LOBYTE(s[11]),
    BYTE1(s[11]),
    HIDWORD(s[10]),
    BYTE2(s[11]),
    BYTE3(s[11]),
    v734,
    v736,
    v738);
LABEL_150:
  v541 = *(_DWORD *)(v70 + 504);
  v542 = *(unsigned __int8 *)(v70 + 486);
  v543 = *(_DWORD *)(v70 + 824);
  v761 = 0;
  v760 = 0;
  v759 = 0;
  v758 = 0;
  v757 = 0;
  v756 = 0;
  v755 = 0;
  v752 = 0;
  v753 = 0;
  v750 = 0;
  v751 = 0;
  v748 = 0;
  v749 = 0;
  v747 = 0;
  if ( v541 <= 0xA )
  {
    if ( *v516 == v541 )
    {
      v544 = 0;
    }
    else if ( *(_DWORD *)(v70 + 1328) == v541 )
    {
      v544 = 1;
    }
    else if ( *(_DWORD *)(v70 + 1584) == v541 )
    {
      v544 = 2;
    }
    else if ( *(_DWORD *)(v70 + 1840) == v541 )
    {
      v544 = 3;
    }
    else if ( *(_DWORD *)(v70 + 2096) == v541 )
    {
      v544 = 4;
    }
    else if ( *(_DWORD *)(v70 + 2352) == v541 )
    {
      v544 = 5;
    }
    else if ( *(_DWORD *)(v70 + 2608) == v541 )
    {
      v544 = 6;
    }
    else
    {
      if ( *(_DWORD *)(v70 + 2864) != v541 )
      {
LABEL_188:
        v560 = "%s: Invalid MAC PHY capabilities handle";
        v561 = 2;
LABEL_190:
        qdf_trace_msg(
          0x36u,
          v561,
          v560,
          v531,
          v532,
          v533,
          v534,
          v535,
          v536,
          v537,
          v538,
          "wma_update_target_ext_vht_cap");
        goto LABEL_191;
      }
      v544 = 7;
    }
    v516 += 64 * v544;
  }
  if ( !v516 )
    goto LABEL_188;
  if ( !v543 )
  {
    v560 = "%s: No extended VHT cap for current SOC";
    v561 = 8;
    goto LABEL_190;
  }
  v545 = 0;
  if ( (_DWORD)v542 )
  {
    v546 = v516 + 20;
    do
    {
      v551 = *(v546 - 1);
      if ( *(v546 - 10) )
        wma_derive_ext_vht_cap(&v755);
      if ( v551 )
        wma_derive_ext_vht_cap(&v755);
      v547 = *v546;
      v548 = *(v546 - 9);
      v546 += 64;
      v549 = (v547 & 0x1000000) == 0 || (v547 & 0x30000) == 0;
      v550 = (v548 & 0x1000000) == 0 || (v548 & 0x30000) == 0;
      if ( !v550 || !v549 )
        v545 = 1;
      --v542;
    }
    while ( v542 );
  }
  if ( (unsigned int)qdf_mem_cmp(&v747, &v755, 0x38u) )
    qdf_mem_copy(&s[13], &v755, 0x38u);
  HIDWORD(s[19]) = v545;
  LODWORD(v741) = HIDWORD(s[18]);
  LODWORD(v740) = s[18];
  LODWORD(v738) = s[17];
  LODWORD(v736) = s[19];
  LODWORD(v734) = s[16];
  qdf_trace_msg(
    0x36u,
    8u,
    "[ext vhtcap] max_mpdu %d supp_chan_width %x rx_ldpc %x\n"
    "short_gi_80 %x tx_stbc %x rx_stbc %x txop_ps %x\n"
    "su_bformee %x mu_bformee %x max_ampdu_len_exp %d\n"
    "vht_mcs_10_11_supp %d",
    v552,
    v553,
    v554,
    v555,
    v556,
    v557,
    v558,
    v559,
    LODWORD(s[13]),
    HIDWORD(s[13]),
    LODWORD(s[14]),
    HIDWORD(s[14]),
    HIDWORD(s[15]),
    v734,
    v736,
    v738,
    v740,
    v741,
    v545);
LABEL_191:
  wma_update_target_ext_he_cap(v70, s);
  v570 = *(_DWORD *)(v70 + 748);
  *(_QWORD *)((char *)&s[53] + 4) = *(_QWORD *)(a1 + 2724);
  v571 = *(_QWORD *)(a1 + 2712);
  s[0] = __PAIR64__(*(_DWORD *)(v70 + 820), v570);
  v572 = *(_DWORD *)(a1 + 2720);
  LOWORD(v570) = *(_WORD *)(a1 + 176);
  s[52] = v571;
  LODWORD(v571) = *(_DWORD *)(a1 + 2732);
  LODWORD(s[53]) = v572;
  v573 = *(_DWORD *)(v70 + 680);
  *(_WORD *)((char *)&s[20] + 1) = v570;
  LOBYTE(v570) = *(_BYTE *)(a1 + 3779);
  HIDWORD(s[54]) = v571;
  LOBYTE(v571) = *(_BYTE *)(a1 + 3800);
  LOBYTE(s[51]) = v570;
  BYTE3(s[51]) = v571;
  if ( v573 > 8 )
  {
LABEL_199:
    v575 = 7;
    goto LABEL_200;
  }
  if ( ((1 << v573) & 0x92) == 0 )
  {
    if ( ((1 << v573) & 0x148) != 0 )
    {
      v574 = *(_QWORD *)(a1 + 24);
      LODWORD(s[1]) = 3;
      if ( (wlan_reg_is_6ghz_supported(v574, v562, v563, v564, v565, v566, v567, v568, v569) & 1) == 0 )
        goto LABEL_201;
      v575 = LODWORD(s[1]) | 4;
      goto LABEL_200;
    }
    if ( ((1 << v573) & 0x24) != 0 )
    {
      LODWORD(s[1]) = 1;
      goto LABEL_201;
    }
    goto LABEL_199;
  }
  v575 = 2;
LABEL_200:
  LODWORD(s[1]) = v575;
LABEL_201:
  v576 = *(_DWORD *)(v70 + 1052);
  v577 = *(_DWORD *)(v70 + 732);
  v578 = *(_QWORD *)a1;
  LODWORD(s[55]) = *(_DWORD *)(v70 + 928);
  HIDWORD(s[55]) = v576;
  LOBYTE(v576) = *(_BYTE *)(a1 + 3948);
  WORD1(s[21]) = 1920;
  v579 = *(_BYTE *)(a1 + 3950);
  HIDWORD(s[20]) = v577;
  BYTE1(s[51]) = v576;
  BYTE2(s[51]) = v579;
  v580 = wmi_service_enabled(v578, 0x94u, v562, v563, v564, v565, v566, v567, v568, v569);
  v581 = *(_QWORD *)a1;
  BYTE4(s[51]) = v580 & 1;
  v590 = wmi_service_enabled(v581, 0x95u, v582, v583, v584, v585, v586, v587, v588, v589);
  v591 = *(_BYTE *)(a1 + 3776);
  v592 = v590 & 1;
  v593 = *(_QWORD *)a1;
  BYTE5(s[51]) = v592;
  LOBYTE(s[21]) = v591;
  if ( (wmi_service_enabled(v593, 0xAAu, v594, v595, v596, v597, v598, v599, v600, v601) & 1) != 0 )
    LOWORD(s[56]) |= 1u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0xA6u, v602, v603, v604, v605, v606, v607, v608, v609) & 1) != 0 )
    LOWORD(s[56]) |= 2u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0xA7u, v610, v611, v612, v613, v614, v615, v616, v617) & 1) != 0 )
    LOWORD(s[56]) |= 4u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0xA8u, v618, v619, v620, v621, v622, v623, v624, v625) & 1) != 0 )
    LOWORD(s[56]) |= 8u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0xA9u, v626, v627, v628, v629, v630, v631, v632, v633) & 1) != 0 )
    LOWORD(s[56]) |= 0x10u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0xC3u, v634, v635, v636, v637, v638, v639, v640, v641) & 1) != 0 )
    LOWORD(s[56]) |= 0x20u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0xCAu, v642, v643, v644, v645, v646, v647, v648, v649) & 1) != 0 )
    LOWORD(s[56]) |= 0x40u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0xEAu, v650, v651, v652, v653, v654, v655, v656, v657) & 1) != 0 )
    LOWORD(s[56]) |= 0x80u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0x133u, v658, v659, v660, v661, v662, v663, v664, v665) & 1) != 0 )
    LOWORD(s[56]) |= 0x100u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0x134u, v666, v667, v668, v669, v670, v671, v672, v673) & 1) != 0 )
    LOWORD(s[56]) |= 0x200u;
  if ( (wmi_service_enabled(*(_QWORD *)a1, 0x135u, v674, v675, v676, v677, v678, v679, v680, v681) & 1) != 0 )
    LOWORD(s[56]) |= 0x400u;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: NAN caps: 0x%x",
    v682,
    v683,
    v684,
    v685,
    v686,
    v687,
    v688,
    v689,
    "wma_update_nan_target_caps",
    LODWORD(s[56]));
  wma_update_bcast_twt_support(a1, s);
  v690 = wma_update_twt_tgt_cap(a1, s);
  v698 = wmi_service_enabled(*(_QWORD *)a1, 0xC0u, v690, v691, v692, v693, v694, v695, v696, v697);
  v707 = *(_DWORD *)(v70 + 1020);
  BYTE5(s[56]) = v698 & 1;
  if ( v707 )
  {
    v708 = *(_QWORD *)(v70 + 4496);
    for ( j = 0; j < v707; ++j )
    {
      v711 = (_DWORD *)(v708 + 20LL * j);
      if ( !*v711 )
      {
        v712 = v711[1];
        if ( v712 < 0xB )
        {
          v710 = (_DWORD *)&s[57] + 3 * v712 + 1;
          *v710 = v711[2];
          v710[1] = v711[3];
          v710[2] = v711[4];
        }
        else
        {
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: invalid hw mode id %d.",
            v699,
            v700,
            v701,
            v702,
            v703,
            v704,
            v705,
            v706,
            "wma_update_aux_dev_caps");
        }
      }
    }
  }
  LOBYTE(s[74]) = *(_BYTE *)(v70 + 1071);
  if ( *(_BYTE *)(v70 + 486) )
  {
    v713 = 0;
    v714 = (unsigned __int8 *)(v70 + 1172);
    do
    {
      v715 = _cds_get_context(53, (__int64)"wma_fill_chain_cfg", v699, v700, v701, v702, v703, v704, v705, v706);
      if ( v715 )
      {
        v716 = *(v714 - 40) - ((*(v714 - 40) >> 1) & 0x55555555);
        v717 = (16843009
              * (((v716 & 0x33333333)
                + ((v716 >> 2) & 0x33333333)
                + (((v716 & 0x33333333) + ((v716 >> 2) & 0x33333333)) >> 4))
               & 0xF0F0F0F)) >> 24;
        if ( v717 > (unsigned __int8)v715[4] )
          v715[4] = v717;
        v718 = *(v714 - 4) - ((*(v714 - 4) >> 1) & 0x55555555);
        v719 = (16843009
              * (((v718 & 0x33333333)
                + ((v718 >> 2) & 0x33333333)
                + (((v718 & 0x33333333) + ((v718 >> 2) & 0x33333333)) >> 4))
               & 0xF0F0F0F)) >> 24;
        if ( v719 > (unsigned __int8)v715[6] )
          v715[6] = v719;
        v720 = *(v714 - 36) - ((*(v714 - 36) >> 1) & 0x55555555);
        v721 = (16843009
              * (((v720 & 0x33333333)
                + ((v720 >> 2) & 0x33333333)
                + (((v720 & 0x33333333) + ((v720 >> 2) & 0x33333333)) >> 4))
               & 0xF0F0F0F)) >> 24;
        if ( v721 > (unsigned __int8)v715[5] )
          v715[5] = v721;
        v722 = *v714 - ((*v714 >> 1) & 0x55555555);
        v723 = (16843009
              * (((v722 & 0x33333333)
                + ((v722 >> 2) & 0x33333333)
                + (((v722 & 0x33333333) + ((v722 >> 2) & 0x33333333)) >> 4))
               & 0xF0F0F0F)) >> 24;
        if ( v723 > (unsigned __int8)v715[7] )
          v715[7] = v723;
      }
      else
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: fill chain cfg failed as mac_ctx is NULL",
          v699,
          v700,
          v701,
          v702,
          v703,
          v704,
          v705,
          v706,
          "wma_fill_chain_cfg");
      }
      ++v713;
      v714 += 256;
    }
    while ( v713 < *(unsigned __int8 *)(v70 + 486) );
  }
  v724 = *(_DWORD **)(a1 + 448);
  if ( *(v724 - 1) != -1334941919 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(_QWORD *, _QWORD *))v724)(v743, s) )
    goto LABEL_45;
  if ( (*(_BYTE *)(a1 + 272) & 1) != 0 )
    target_if_green_ap_register_egap_event_handler(*(_QWORD *)(a1 + 32));
  target_if_green_ap_register_ll_ps_event_handler(*(_QWORD *)(a1 + 32));
  qdf_trace_msg(0x36u, 8u, "%s: Exit", v725, v726, v727, v728, v729, v730, v731, v732, "wma_rx_ready_event");
  result = 0;
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}
