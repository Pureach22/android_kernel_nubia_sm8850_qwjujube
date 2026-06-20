__int64 __fastcall dp_print_per_link_stats(
        __int64 result,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned __int8 *v10; // x21
  __int64 v11; // x23
  unsigned __int64 StatusReg; // x8
  __int64 v13; // x24
  unsigned int v14; // w9
  unsigned int v21; // w11
  __int64 v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x25
  __int64 v33; // x22
  unsigned __int64 v34; // x8
  __int64 v35; // x0
  __int64 v36; // x19
  __int64 v37; // x8
  __int64 v38; // x20
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x20
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x0
  unsigned int *v58; // x8
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
  __int64 v75; // x0
  __int64 v76; // x0
  __int64 v77; // x0
  __int64 v78; // x8
  __int64 v79; // x0
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  __int64 v96; // x20
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  double v105; // d0
  double v106; // d1
  double v107; // d2
  double v108; // d3
  double v109; // d4
  double v110; // d5
  double v111; // d6
  double v112; // d7
  double v113; // d0
  double v114; // d1
  double v115; // d2
  double v116; // d3
  double v117; // d4
  double v118; // d5
  double v119; // d6
  double v120; // d7
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  double v129; // d0
  double v130; // d1
  double v131; // d2
  double v132; // d3
  double v133; // d4
  double v134; // d5
  double v135; // d6
  double v136; // d7
  double v137; // d0
  double v138; // d1
  double v139; // d2
  double v140; // d3
  double v141; // d4
  double v142; // d5
  double v143; // d6
  double v144; // d7
  double v145; // d0
  double v146; // d1
  double v147; // d2
  double v148; // d3
  double v149; // d4
  double v150; // d5
  double v151; // d6
  double v152; // d7
  double v153; // d0
  double v154; // d1
  double v155; // d2
  double v156; // d3
  double v157; // d4
  double v158; // d5
  double v159; // d6
  double v160; // d7
  double v161; // d0
  double v162; // d1
  double v163; // d2
  double v164; // d3
  double v165; // d4
  double v166; // d5
  double v167; // d6
  double v168; // d7
  double v169; // d0
  double v170; // d1
  double v171; // d2
  double v172; // d3
  double v173; // d4
  double v174; // d5
  double v175; // d6
  double v176; // d7
  double v177; // d0
  double v178; // d1
  double v179; // d2
  double v180; // d3
  double v181; // d4
  double v182; // d5
  double v183; // d6
  double v184; // d7
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  double v193; // d0
  double v194; // d1
  double v195; // d2
  double v196; // d3
  double v197; // d4
  double v198; // d5
  double v199; // d6
  double v200; // d7
  __int64 v201; // x20
  __int64 v202; // x28
  __int64 v203; // x24
  __int64 v204; // x27
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  __int64 v213; // x1
  __int64 v214; // x2
  __int64 v215; // x3
  __int64 v216; // x4
  double v217; // d0
  double v218; // d1
  double v219; // d2
  double v220; // d3
  double v221; // d4
  double v222; // d5
  double v223; // d6
  double v224; // d7
  double v225; // d0
  double v226; // d1
  double v227; // d2
  double v228; // d3
  double v229; // d4
  double v230; // d5
  double v231; // d6
  double v232; // d7
  double v233; // d0
  double v234; // d1
  double v235; // d2
  double v236; // d3
  double v237; // d4
  double v238; // d5
  double v239; // d6
  double v240; // d7
  double v241; // d0
  double v242; // d1
  double v243; // d2
  double v244; // d3
  double v245; // d4
  double v246; // d5
  double v247; // d6
  double v248; // d7
  double v249; // d0
  double v250; // d1
  double v251; // d2
  double v252; // d3
  double v253; // d4
  double v254; // d5
  double v255; // d6
  double v256; // d7
  double v257; // d0
  double v258; // d1
  double v259; // d2
  double v260; // d3
  double v261; // d4
  double v262; // d5
  double v263; // d6
  double v264; // d7
  double v265; // d0
  double v266; // d1
  double v267; // d2
  double v268; // d3
  double v269; // d4
  double v270; // d5
  double v271; // d6
  double v272; // d7
  double v273; // d0
  double v274; // d1
  double v275; // d2
  double v276; // d3
  double v277; // d4
  double v278; // d5
  double v279; // d6
  double v280; // d7
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
  double v321; // d0
  double v322; // d1
  double v323; // d2
  double v324; // d3
  double v325; // d4
  double v326; // d5
  double v327; // d6
  double v328; // d7
  double v329; // d0
  double v330; // d1
  double v331; // d2
  double v332; // d3
  double v333; // d4
  double v334; // d5
  double v335; // d6
  double v336; // d7
  double v337; // d0
  double v338; // d1
  double v339; // d2
  double v340; // d3
  double v341; // d4
  double v342; // d5
  double v343; // d6
  double v344; // d7
  double v345; // d0
  double v346; // d1
  double v347; // d2
  double v348; // d3
  double v349; // d4
  double v350; // d5
  double v351; // d6
  double v352; // d7
  double v353; // d0
  double v354; // d1
  double v355; // d2
  double v356; // d3
  double v357; // d4
  double v358; // d5
  double v359; // d6
  double v360; // d7
  double v361; // d0
  double v362; // d1
  double v363; // d2
  double v364; // d3
  double v365; // d4
  double v366; // d5
  double v367; // d6
  double v368; // d7
  double v369; // d0
  double v370; // d1
  double v371; // d2
  double v372; // d3
  double v373; // d4
  double v374; // d5
  double v375; // d6
  double v376; // d7
  double v377; // d0
  double v378; // d1
  double v379; // d2
  double v380; // d3
  double v381; // d4
  double v382; // d5
  double v383; // d6
  double v384; // d7
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
  double v401; // d0
  double v402; // d1
  double v403; // d2
  double v404; // d3
  double v405; // d4
  double v406; // d5
  double v407; // d6
  double v408; // d7
  double v409; // d0
  double v410; // d1
  double v411; // d2
  double v412; // d3
  double v413; // d4
  double v414; // d5
  double v415; // d6
  double v416; // d7
  double v417; // d0
  double v418; // d1
  double v419; // d2
  double v420; // d3
  double v421; // d4
  double v422; // d5
  double v423; // d6
  double v424; // d7
  double v425; // d0
  double v426; // d1
  double v427; // d2
  double v428; // d3
  double v429; // d4
  double v430; // d5
  double v431; // d6
  double v432; // d7
  unsigned __int64 v433; // x8
  double v434; // d0
  double v435; // d1
  double v436; // d2
  double v437; // d3
  double v438; // d4
  double v439; // d5
  double v440; // d6
  double v441; // d7
  double v442; // d0
  double v443; // d1
  double v444; // d2
  double v445; // d3
  double v446; // d4
  double v447; // d5
  double v448; // d6
  double v449; // d7
  double v450; // d0
  double v451; // d1
  double v452; // d2
  double v453; // d3
  double v454; // d4
  double v455; // d5
  double v456; // d6
  double v457; // d7
  double v458; // d0
  double v459; // d1
  double v460; // d2
  double v461; // d3
  double v462; // d4
  double v463; // d5
  double v464; // d6
  double v465; // d7
  double v466; // d0
  double v467; // d1
  double v468; // d2
  double v469; // d3
  double v470; // d4
  double v471; // d5
  double v472; // d6
  double v473; // d7
  double v474; // d0
  double v475; // d1
  double v476; // d2
  double v477; // d3
  double v478; // d4
  double v479; // d5
  double v480; // d6
  double v481; // d7
  double v482; // d0
  double v483; // d1
  double v484; // d2
  double v485; // d3
  double v486; // d4
  double v487; // d5
  double v488; // d6
  double v489; // d7
  double v490; // d0
  double v491; // d1
  double v492; // d2
  double v493; // d3
  double v494; // d4
  double v495; // d5
  double v496; // d6
  double v497; // d7
  double v498; // d0
  double v499; // d1
  double v500; // d2
  double v501; // d3
  double v502; // d4
  double v503; // d5
  double v504; // d6
  double v505; // d7
  double v506; // d0
  double v507; // d1
  double v508; // d2
  double v509; // d3
  double v510; // d4
  double v511; // d5
  double v512; // d6
  double v513; // d7
  double v514; // d0
  double v515; // d1
  double v516; // d2
  double v517; // d3
  double v518; // d4
  double v519; // d5
  double v520; // d6
  double v521; // d7
  double v522; // d0
  double v523; // d1
  double v524; // d2
  double v525; // d3
  double v526; // d4
  double v527; // d5
  double v528; // d6
  double v529; // d7
  double v530; // d0
  double v531; // d1
  double v532; // d2
  double v533; // d3
  double v534; // d4
  double v535; // d5
  double v536; // d6
  double v537; // d7
  double v538; // d0
  double v539; // d1
  double v540; // d2
  double v541; // d3
  double v542; // d4
  double v543; // d5
  double v544; // d6
  double v545; // d7
  double v546; // d0
  double v547; // d1
  double v548; // d2
  double v549; // d3
  double v550; // d4
  double v551; // d5
  double v552; // d6
  double v553; // d7
  double v554; // d0
  double v555; // d1
  double v556; // d2
  double v557; // d3
  double v558; // d4
  double v559; // d5
  double v560; // d6
  double v561; // d7
  double v562; // d0
  double v563; // d1
  double v564; // d2
  double v565; // d3
  double v566; // d4
  double v567; // d5
  double v568; // d6
  double v569; // d7
  double v570; // d0
  double v571; // d1
  double v572; // d2
  double v573; // d3
  double v574; // d4
  double v575; // d5
  double v576; // d6
  double v577; // d7
  double v578; // d0
  double v579; // d1
  double v580; // d2
  double v581; // d3
  double v582; // d4
  double v583; // d5
  double v584; // d6
  double v585; // d7
  double v586; // d0
  double v587; // d1
  double v588; // d2
  double v589; // d3
  double v590; // d4
  double v591; // d5
  double v592; // d6
  double v593; // d7
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
  double v698; // d0
  double v699; // d1
  double v700; // d2
  double v701; // d3
  double v702; // d4
  double v703; // d5
  double v704; // d6
  double v705; // d7
  double v706; // d0
  double v707; // d1
  double v708; // d2
  double v709; // d3
  double v710; // d4
  double v711; // d5
  double v712; // d6
  double v713; // d7
  double v714; // d0
  double v715; // d1
  double v716; // d2
  double v717; // d3
  double v718; // d4
  double v719; // d5
  double v720; // d6
  double v721; // d7
  double v722; // d0
  double v723; // d1
  double v724; // d2
  double v725; // d3
  double v726; // d4
  double v727; // d5
  double v728; // d6
  double v729; // d7
  double v730; // d0
  double v731; // d1
  double v732; // d2
  double v733; // d3
  double v734; // d4
  double v735; // d5
  double v736; // d6
  double v737; // d7
  double v738; // d0
  double v739; // d1
  double v740; // d2
  double v741; // d3
  double v742; // d4
  double v743; // d5
  double v744; // d6
  double v745; // d7
  double v746; // d0
  double v747; // d1
  double v748; // d2
  double v749; // d3
  double v750; // d4
  double v751; // d5
  double v752; // d6
  double v753; // d7
  double v754; // d0
  double v755; // d1
  double v756; // d2
  double v757; // d3
  double v758; // d4
  double v759; // d5
  double v760; // d6
  double v761; // d7
  unsigned __int8 v762; // w24
  double v763; // d0
  double v764; // d1
  double v765; // d2
  double v766; // d3
  double v767; // d4
  double v768; // d5
  double v769; // d6
  double v770; // d7
  unsigned int v771; // w20
  int v772; // w0
  double v773; // d0
  double v774; // d1
  double v775; // d2
  double v776; // d3
  double v777; // d4
  double v778; // d5
  double v779; // d6
  double v780; // d7
  unsigned __int64 v781; // x9
  double v782; // d0
  double v783; // d1
  double v784; // d2
  double v785; // d3
  double v786; // d4
  double v787; // d5
  double v788; // d6
  double v789; // d7
  double v790; // d0
  double v791; // d1
  double v792; // d2
  double v793; // d3
  double v794; // d4
  double v795; // d5
  double v796; // d6
  double v797; // d7
  double v798; // d0
  double v799; // d1
  double v800; // d2
  double v801; // d3
  double v802; // d4
  double v803; // d5
  double v804; // d6
  double v805; // d7
  double v806; // d0
  double v807; // d1
  double v808; // d2
  double v809; // d3
  double v810; // d4
  double v811; // d5
  double v812; // d6
  double v813; // d7
  _DWORD *v814; // x8
  double v815; // d0
  double v816; // d1
  double v817; // d2
  double v818; // d3
  double v819; // d4
  double v820; // d5
  double v821; // d6
  double v822; // d7
  double v823; // d0
  double v824; // d1
  double v825; // d2
  double v826; // d3
  double v827; // d4
  double v828; // d5
  double v829; // d6
  double v830; // d7
  double v831; // d0
  double v832; // d1
  double v833; // d2
  double v834; // d3
  double v835; // d4
  double v836; // d5
  double v837; // d6
  double v838; // d7
  double v839; // d0
  double v840; // d1
  double v841; // d2
  double v842; // d3
  double v843; // d4
  double v844; // d5
  double v845; // d6
  double v846; // d7
  double v847; // d0
  double v848; // d1
  double v849; // d2
  double v850; // d3
  double v851; // d4
  double v852; // d5
  double v853; // d6
  double v854; // d7
  double v855; // d0
  double v856; // d1
  double v857; // d2
  double v858; // d3
  double v859; // d4
  double v860; // d5
  double v861; // d6
  double v862; // d7
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
  double v879; // d0
  double v880; // d1
  double v881; // d2
  double v882; // d3
  double v883; // d4
  double v884; // d5
  double v885; // d6
  double v886; // d7
  double v887; // d0
  double v888; // d1
  double v889; // d2
  double v890; // d3
  double v891; // d4
  double v892; // d5
  double v893; // d6
  double v894; // d7
  double v895; // d0
  double v896; // d1
  double v897; // d2
  double v898; // d3
  double v899; // d4
  double v900; // d5
  double v901; // d6
  double v902; // d7
  double v903; // d0
  double v904; // d1
  double v905; // d2
  double v906; // d3
  double v907; // d4
  double v908; // d5
  double v909; // d6
  double v910; // d7
  double v911; // d0
  double v912; // d1
  double v913; // d2
  double v914; // d3
  double v915; // d4
  double v916; // d5
  double v917; // d6
  double v918; // d7
  double v919; // d0
  double v920; // d1
  double v921; // d2
  double v922; // d3
  double v923; // d4
  double v924; // d5
  double v925; // d6
  double v926; // d7
  double v927; // d0
  double v928; // d1
  double v929; // d2
  double v930; // d3
  double v931; // d4
  double v932; // d5
  double v933; // d6
  double v934; // d7
  double v935; // d0
  double v936; // d1
  double v937; // d2
  double v938; // d3
  double v939; // d4
  double v940; // d5
  double v941; // d6
  double v942; // d7
  double v943; // d0
  double v944; // d1
  double v945; // d2
  double v946; // d3
  double v947; // d4
  double v948; // d5
  double v949; // d6
  double v950; // d7
  double v951; // d0
  double v952; // d1
  double v953; // d2
  double v954; // d3
  double v955; // d4
  double v956; // d5
  double v957; // d6
  double v958; // d7
  double v959; // d0
  double v960; // d1
  double v961; // d2
  double v962; // d3
  double v963; // d4
  double v964; // d5
  double v965; // d6
  double v966; // d7
  double v967; // d0
  double v968; // d1
  double v969; // d2
  double v970; // d3
  double v971; // d4
  double v972; // d5
  double v973; // d6
  double v974; // d7
  double v975; // d0
  double v976; // d1
  double v977; // d2
  double v978; // d3
  double v979; // d4
  double v980; // d5
  double v981; // d6
  double v982; // d7
  double v983; // d0
  double v984; // d1
  double v985; // d2
  double v986; // d3
  double v987; // d4
  double v988; // d5
  double v989; // d6
  double v990; // d7
  double v991; // d0
  double v992; // d1
  double v993; // d2
  double v994; // d3
  double v995; // d4
  double v996; // d5
  double v997; // d6
  double v998; // d7
  double v999; // d0
  double v1000; // d1
  double v1001; // d2
  double v1002; // d3
  double v1003; // d4
  double v1004; // d5
  double v1005; // d6
  double v1006; // d7
  double v1007; // d0
  double v1008; // d1
  double v1009; // d2
  double v1010; // d3
  double v1011; // d4
  double v1012; // d5
  double v1013; // d6
  double v1014; // d7
  double v1015; // d0
  double v1016; // d1
  double v1017; // d2
  double v1018; // d3
  double v1019; // d4
  double v1020; // d5
  double v1021; // d6
  double v1022; // d7
  double v1023; // d0
  double v1024; // d1
  double v1025; // d2
  double v1026; // d3
  double v1027; // d4
  double v1028; // d5
  double v1029; // d6
  double v1030; // d7
  double v1031; // d0
  double v1032; // d1
  double v1033; // d2
  double v1034; // d3
  double v1035; // d4
  double v1036; // d5
  double v1037; // d6
  double v1038; // d7
  double v1039; // d0
  double v1040; // d1
  double v1041; // d2
  double v1042; // d3
  double v1043; // d4
  double v1044; // d5
  double v1045; // d6
  double v1046; // d7
  double v1047; // d0
  double v1048; // d1
  double v1049; // d2
  double v1050; // d3
  double v1051; // d4
  double v1052; // d5
  double v1053; // d6
  double v1054; // d7
  double v1055; // d0
  double v1056; // d1
  double v1057; // d2
  double v1058; // d3
  double v1059; // d4
  double v1060; // d5
  double v1061; // d6
  double v1062; // d7
  double v1063; // d0
  double v1064; // d1
  double v1065; // d2
  double v1066; // d3
  double v1067; // d4
  double v1068; // d5
  double v1069; // d6
  double v1070; // d7
  double v1071; // d0
  double v1072; // d1
  double v1073; // d2
  double v1074; // d3
  double v1075; // d4
  double v1076; // d5
  double v1077; // d6
  double v1078; // d7
  double v1079; // d0
  double v1080; // d1
  double v1081; // d2
  double v1082; // d3
  double v1083; // d4
  double v1084; // d5
  double v1085; // d6
  double v1086; // d7
  double v1087; // d0
  double v1088; // d1
  double v1089; // d2
  double v1090; // d3
  double v1091; // d4
  double v1092; // d5
  double v1093; // d6
  double v1094; // d7
  double v1095; // d0
  double v1096; // d1
  double v1097; // d2
  double v1098; // d3
  double v1099; // d4
  double v1100; // d5
  double v1101; // d6
  double v1102; // d7
  double v1103; // d0
  double v1104; // d1
  double v1105; // d2
  double v1106; // d3
  double v1107; // d4
  double v1108; // d5
  double v1109; // d6
  double v1110; // d7
  double v1111; // d0
  double v1112; // d1
  double v1113; // d2
  double v1114; // d3
  double v1115; // d4
  double v1116; // d5
  double v1117; // d6
  double v1118; // d7
  double v1119; // d0
  double v1120; // d1
  double v1121; // d2
  double v1122; // d3
  double v1123; // d4
  double v1124; // d5
  double v1125; // d6
  double v1126; // d7
  double v1127; // d0
  double v1128; // d1
  double v1129; // d2
  double v1130; // d3
  double v1131; // d4
  double v1132; // d5
  double v1133; // d6
  double v1134; // d7
  double v1135; // d0
  double v1136; // d1
  double v1137; // d2
  double v1138; // d3
  double v1139; // d4
  double v1140; // d5
  double v1141; // d6
  double v1142; // d7
  double v1143; // d0
  double v1144; // d1
  double v1145; // d2
  double v1146; // d3
  double v1147; // d4
  double v1148; // d5
  double v1149; // d6
  double v1150; // d7
  double v1151; // d0
  double v1152; // d1
  double v1153; // d2
  double v1154; // d3
  double v1155; // d4
  double v1156; // d5
  double v1157; // d6
  double v1158; // d7
  double v1159; // d0
  double v1160; // d1
  double v1161; // d2
  double v1162; // d3
  double v1163; // d4
  double v1164; // d5
  double v1165; // d6
  double v1166; // d7
  double v1167; // d0
  double v1168; // d1
  double v1169; // d2
  double v1170; // d3
  double v1171; // d4
  double v1172; // d5
  double v1173; // d6
  double v1174; // d7
  double v1175; // d0
  double v1176; // d1
  double v1177; // d2
  double v1178; // d3
  double v1179; // d4
  double v1180; // d5
  double v1181; // d6
  double v1182; // d7
  double v1183; // d0
  double v1184; // d1
  double v1185; // d2
  double v1186; // d3
  double v1187; // d4
  double v1188; // d5
  double v1189; // d6
  double v1190; // d7
  double v1191; // d0
  double v1192; // d1
  double v1193; // d2
  double v1194; // d3
  double v1195; // d4
  double v1196; // d5
  double v1197; // d6
  double v1198; // d7
  double v1199; // d0
  double v1200; // d1
  double v1201; // d2
  double v1202; // d3
  double v1203; // d4
  double v1204; // d5
  double v1205; // d6
  double v1206; // d7
  double v1207; // d0
  double v1208; // d1
  double v1209; // d2
  double v1210; // d3
  double v1211; // d4
  double v1212; // d5
  double v1213; // d6
  double v1214; // d7
  double v1215; // d0
  double v1216; // d1
  double v1217; // d2
  double v1218; // d3
  double v1219; // d4
  double v1220; // d5
  double v1221; // d6
  double v1222; // d7
  double v1223; // d0
  double v1224; // d1
  double v1225; // d2
  double v1226; // d3
  double v1227; // d4
  double v1228; // d5
  double v1229; // d6
  double v1230; // d7
  double v1231; // d0
  double v1232; // d1
  double v1233; // d2
  double v1234; // d3
  double v1235; // d4
  double v1236; // d5
  double v1237; // d6
  double v1238; // d7
  double v1239; // d0
  double v1240; // d1
  double v1241; // d2
  double v1242; // d3
  double v1243; // d4
  double v1244; // d5
  double v1245; // d6
  double v1246; // d7
  double v1247; // d0
  double v1248; // d1
  double v1249; // d2
  double v1250; // d3
  double v1251; // d4
  double v1252; // d5
  double v1253; // d6
  double v1254; // d7
  double v1255; // d0
  double v1256; // d1
  double v1257; // d2
  double v1258; // d3
  double v1259; // d4
  double v1260; // d5
  double v1261; // d6
  double v1262; // d7
  double v1263; // d0
  double v1264; // d1
  double v1265; // d2
  double v1266; // d3
  double v1267; // d4
  double v1268; // d5
  double v1269; // d6
  double v1270; // d7
  double v1271; // d0
  double v1272; // d1
  double v1273; // d2
  double v1274; // d3
  double v1275; // d4
  double v1276; // d5
  double v1277; // d6
  double v1278; // d7
  double v1279; // d0
  double v1280; // d1
  double v1281; // d2
  double v1282; // d3
  double v1283; // d4
  double v1284; // d5
  double v1285; // d6
  double v1286; // d7
  double v1287; // d0
  double v1288; // d1
  double v1289; // d2
  double v1290; // d3
  double v1291; // d4
  double v1292; // d5
  double v1293; // d6
  double v1294; // d7
  double v1295; // d0
  double v1296; // d1
  double v1297; // d2
  double v1298; // d3
  double v1299; // d4
  double v1300; // d5
  double v1301; // d6
  double v1302; // d7
  double v1303; // d0
  double v1304; // d1
  double v1305; // d2
  double v1306; // d3
  double v1307; // d4
  double v1308; // d5
  double v1309; // d6
  double v1310; // d7
  double v1311; // d0
  double v1312; // d1
  double v1313; // d2
  double v1314; // d3
  double v1315; // d4
  double v1316; // d5
  double v1317; // d6
  double v1318; // d7
  double v1319; // d0
  double v1320; // d1
  double v1321; // d2
  double v1322; // d3
  double v1323; // d4
  double v1324; // d5
  double v1325; // d6
  double v1326; // d7
  double v1327; // d0
  double v1328; // d1
  double v1329; // d2
  double v1330; // d3
  double v1331; // d4
  double v1332; // d5
  double v1333; // d6
  double v1334; // d7
  double v1335; // d0
  double v1336; // d1
  double v1337; // d2
  double v1338; // d3
  double v1339; // d4
  double v1340; // d5
  double v1341; // d6
  double v1342; // d7
  double v1343; // d0
  double v1344; // d1
  double v1345; // d2
  double v1346; // d3
  double v1347; // d4
  double v1348; // d5
  double v1349; // d6
  double v1350; // d7
  double v1351; // d0
  double v1352; // d1
  double v1353; // d2
  double v1354; // d3
  double v1355; // d4
  double v1356; // d5
  double v1357; // d6
  double v1358; // d7
  double v1359; // d0
  double v1360; // d1
  double v1361; // d2
  double v1362; // d3
  double v1363; // d4
  double v1364; // d5
  double v1365; // d6
  double v1366; // d7
  double v1367; // d0
  double v1368; // d1
  double v1369; // d2
  double v1370; // d3
  double v1371; // d4
  double v1372; // d5
  double v1373; // d6
  double v1374; // d7
  double v1375; // d0
  double v1376; // d1
  double v1377; // d2
  double v1378; // d3
  double v1379; // d4
  double v1380; // d5
  double v1381; // d6
  double v1382; // d7
  __int64 v1383; // x19
  const char *v1384; // x20
  double v1385; // d0
  double v1386; // d1
  double v1387; // d2
  double v1388; // d3
  double v1389; // d4
  double v1390; // d5
  double v1391; // d6
  double v1392; // d7
  double v1393; // d0
  double v1394; // d1
  double v1395; // d2
  double v1396; // d3
  double v1397; // d4
  double v1398; // d5
  double v1399; // d6
  double v1400; // d7
  __int64 v1401; // x19
  const char *v1402; // x20
  double v1403; // d0
  double v1404; // d1
  double v1405; // d2
  double v1406; // d3
  double v1407; // d4
  double v1408; // d5
  double v1409; // d6
  double v1410; // d7
  __int64 v1411; // x19
  const char *v1412; // x20
  double v1413; // d0
  double v1414; // d1
  double v1415; // d2
  double v1416; // d3
  double v1417; // d4
  double v1418; // d5
  double v1419; // d6
  double v1420; // d7
  double v1421; // d0
  double v1422; // d1
  double v1423; // d2
  double v1424; // d3
  double v1425; // d4
  double v1426; // d5
  double v1427; // d6
  double v1428; // d7
  double v1429; // d0
  double v1430; // d1
  double v1431; // d2
  double v1432; // d3
  double v1433; // d4
  double v1434; // d5
  double v1435; // d6
  double v1436; // d7
  double v1437; // d0
  double v1438; // d1
  double v1439; // d2
  double v1440; // d3
  double v1441; // d4
  double v1442; // d5
  double v1443; // d6
  double v1444; // d7
  double v1445; // d0
  double v1446; // d1
  double v1447; // d2
  double v1448; // d3
  double v1449; // d4
  double v1450; // d5
  double v1451; // d6
  double v1452; // d7
  double v1453; // d0
  double v1454; // d1
  double v1455; // d2
  double v1456; // d3
  double v1457; // d4
  double v1458; // d5
  double v1459; // d6
  double v1460; // d7
  double v1461; // d0
  double v1462; // d1
  double v1463; // d2
  double v1464; // d3
  double v1465; // d4
  double v1466; // d5
  double v1467; // d6
  double v1468; // d7
  double v1469; // d0
  double v1470; // d1
  double v1471; // d2
  double v1472; // d3
  double v1473; // d4
  double v1474; // d5
  double v1475; // d6
  double v1476; // d7
  double v1477; // d0
  double v1478; // d1
  double v1479; // d2
  double v1480; // d3
  double v1481; // d4
  double v1482; // d5
  double v1483; // d6
  double v1484; // d7
  double v1485; // d0
  double v1486; // d1
  double v1487; // d2
  double v1488; // d3
  double v1489; // d4
  double v1490; // d5
  double v1491; // d6
  double v1492; // d7
  double v1493; // d0
  double v1494; // d1
  double v1495; // d2
  double v1496; // d3
  double v1497; // d4
  double v1498; // d5
  double v1499; // d6
  double v1500; // d7
  double v1501; // d0
  double v1502; // d1
  double v1503; // d2
  double v1504; // d3
  double v1505; // d4
  double v1506; // d5
  double v1507; // d6
  double v1508; // d7
  double v1509; // d0
  double v1510; // d1
  double v1511; // d2
  double v1512; // d3
  double v1513; // d4
  double v1514; // d5
  double v1515; // d6
  double v1516; // d7
  double v1517; // d0
  double v1518; // d1
  double v1519; // d2
  double v1520; // d3
  double v1521; // d4
  double v1522; // d5
  double v1523; // d6
  double v1524; // d7
  double v1525; // d0
  double v1526; // d1
  double v1527; // d2
  double v1528; // d3
  double v1529; // d4
  double v1530; // d5
  double v1531; // d6
  double v1532; // d7
  double v1533; // d0
  double v1534; // d1
  double v1535; // d2
  double v1536; // d3
  double v1537; // d4
  double v1538; // d5
  double v1539; // d6
  double v1540; // d7
  double v1541; // d0
  double v1542; // d1
  double v1543; // d2
  double v1544; // d3
  double v1545; // d4
  double v1546; // d5
  double v1547; // d6
  double v1548; // d7
  double v1549; // d0
  double v1550; // d1
  double v1551; // d2
  double v1552; // d3
  double v1553; // d4
  double v1554; // d5
  double v1555; // d6
  double v1556; // d7
  double v1557; // d0
  double v1558; // d1
  double v1559; // d2
  double v1560; // d3
  double v1561; // d4
  double v1562; // d5
  double v1563; // d6
  double v1564; // d7
  double v1565; // d0
  double v1566; // d1
  double v1567; // d2
  double v1568; // d3
  double v1569; // d4
  double v1570; // d5
  double v1571; // d6
  double v1572; // d7
  double v1573; // d0
  double v1574; // d1
  double v1575; // d2
  double v1576; // d3
  double v1577; // d4
  double v1578; // d5
  double v1579; // d6
  double v1580; // d7
  double v1581; // d0
  double v1582; // d1
  double v1583; // d2
  double v1584; // d3
  double v1585; // d4
  double v1586; // d5
  double v1587; // d6
  double v1588; // d7
  double v1589; // d0
  double v1590; // d1
  double v1591; // d2
  double v1592; // d3
  double v1593; // d4
  double v1594; // d5
  double v1595; // d6
  double v1596; // d7
  double v1597; // d0
  double v1598; // d1
  double v1599; // d2
  double v1600; // d3
  double v1601; // d4
  double v1602; // d5
  double v1603; // d6
  double v1604; // d7
  void (__fastcall *v1605)(unsigned __int8 *, __int64); // x8
  unsigned int v1607; // w9
  __int64 v1608; // x8
  __int64 v1609; // [xsp+8h] [xbp-118h]
  __int64 v1610; // [xsp+10h] [xbp-110h]
  __int64 v1611; // [xsp+18h] [xbp-108h]
  __int64 v1612; // [xsp+20h] [xbp-100h]
  __int64 v1613; // [xsp+28h] [xbp-F8h]
  __int64 v1614; // [xsp+38h] [xbp-E8h]
  __int64 v1615; // [xsp+48h] [xbp-D8h]
  __int64 v1616; // [xsp+50h] [xbp-D0h]
  __int64 v1617; // [xsp+58h] [xbp-C8h] BYREF
  __int64 v1618; // [xsp+60h] [xbp-C0h]
  __int64 v1619; // [xsp+68h] [xbp-B8h]
  __int64 v1620; // [xsp+70h] [xbp-B0h]
  __int64 v1621; // [xsp+78h] [xbp-A8h]
  _QWORD v1622[12]; // [xsp+80h] [xbp-A0h] BYREF
  _QWORD v1623[8]; // [xsp+E0h] [xbp-40h] BYREF

  LOBYTE(v10) = a2;
  v1623[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1620 = 0;
  v1621 = 0;
  v1618 = 0;
  v1619 = 0;
  v1617 = 0;
  if ( a2 > 5u )
  {
LABEL_29:
    v38 = jiffies;
    if ( dp_print_per_link_stats___last_ticks - jiffies + 125 < 0 )
    {
      result = qdf_trace_msg(
                 0x45u,
                 2u,
                 "%s: vdev is NULL, vdev_id: %u",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "dp_print_per_link_stats",
                 (unsigned __int8)v10);
      dp_print_per_link_stats___last_ticks = v38;
    }
    goto LABEL_109;
  }
  v11 = result;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(result + 18984);
  }
  else
  {
    raw_spin_lock_bh(result + 18984);
    *(_QWORD *)(v11 + 18992) |= 1uLL;
  }
  v13 = *(_QWORD *)(v11 + 8LL * (unsigned __int8)v10 + 12960);
  if ( !v13 )
  {
LABEL_27:
    v37 = *(_QWORD *)(v11 + 18992);
    if ( (v37 & 1) != 0 )
    {
      *(_QWORD *)(v11 + 18992) = v37 & 0xFFFFFFFFFFFFFFFELL;
      result = raw_spin_unlock_bh(v11 + 18984);
    }
    else
    {
      result = raw_spin_unlock(v11 + 18984);
    }
    goto LABEL_29;
  }
  v14 = *(_DWORD *)(v13 + 43384);
  do
  {
    if ( !v14 )
      goto LABEL_27;
    _X13 = (unsigned int *)(v13 + 43384);
    __asm { PRFM            #0x11, [X13] }
    while ( 1 )
    {
      v21 = __ldxr(_X13);
      if ( v21 != v14 )
        break;
      if ( !__stlxr(v14 + 1, _X13) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v21 == v14;
    v14 = v21;
  }
  while ( !_ZF );
  _X8 = (unsigned int *)(v13 + 43420);
  __asm { PRFM            #0x11, [X8] }
  do
    v1607 = __ldxr(_X8);
  while ( __stxr(v1607 + 1, _X8) );
  v1608 = *(_QWORD *)(v11 + 18992);
  if ( (v1608 & 1) != 0 )
  {
    *(_QWORD *)(v11 + 18992) = v1608 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v11 + 18984);
  }
  else
  {
    raw_spin_unlock(v11 + 18984);
  }
  v23 = dp_vdev_bss_peer_ref_n_get(v11, v13, 8u);
  if ( v23 )
  {
    v32 = v23;
    if ( *(_DWORD *)(v23 + 408) == 1 )
    {
      v33 = *(_QWORD *)(v23 + 416);
      if ( v33 )
      {
        qdf_mem_set(&v1617, 0x28u, 0);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (v34 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v34 + 16) & 0xF0000) != 0)
          || (*(_DWORD *)(v34 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v33 + 480);
          if ( !*(_BYTE *)(v33 + 437) )
            goto LABEL_38;
        }
        else
        {
          raw_spin_lock_bh(v33 + 480);
          *(_QWORD *)(v33 + 488) |= 1uLL;
          if ( !*(_BYTE *)(v33 + 437) )
            goto LABEL_38;
        }
        v35 = dp_peer_find_hash_find(v11, (unsigned __int16 *)(v33 + 428), 1, *(_BYTE *)(v33 + 436), 8u);
        if ( v35 )
        {
          LODWORD(v36) = 1;
          v1617 = v35;
          goto LABEL_39;
        }
LABEL_38:
        LODWORD(v36) = 0;
LABEL_39:
        if ( *(_BYTE *)(v33 + 449) )
        {
          v75 = dp_peer_find_hash_find(v11, (unsigned __int16 *)(v33 + 440), 1, *(_BYTE *)(v33 + 448), 8u);
          if ( v75 )
          {
            *(&v1617 + (unsigned int)v36) = v75;
            LODWORD(v36) = v36 + 1;
          }
        }
        if ( *(_BYTE *)(v33 + 461) )
        {
          v76 = dp_peer_find_hash_find(v11, (unsigned __int16 *)(v33 + 452), 1, *(_BYTE *)(v33 + 460), 8u);
          if ( v76 )
          {
            *(&v1617 + (unsigned int)v36) = v76;
            LODWORD(v36) = v36 + 1;
          }
        }
        if ( *(_BYTE *)(v33 + 473) )
        {
          v77 = dp_peer_find_hash_find(v11, (unsigned __int16 *)(v33 + 464), 1, *(_BYTE *)(v33 + 472), 8u);
          if ( v77 )
          {
            *(&v1617 + (unsigned int)v36) = v77;
            LODWORD(v36) = v36 + 1;
          }
        }
        v78 = *(_QWORD *)(v33 + 488);
        v1610 = v13;
        v1611 = v11;
        v1609 = v32;
        if ( (v78 & 1) != 0 )
          goto LABEL_125;
        raw_spin_unlock(v33 + 480);
        while ( 1 )
        {
          LOBYTE(v1621) = v36;
          v79 = _qdf_mem_malloc(4544LL * (unsigned int)v36, "dp_print_per_link_stats", 11690);
          if ( v79 )
          {
            v36 = v79;
            dp_get_per_link_peer_stats(v33, v79, *(unsigned int *)(v33 + 408), v1621);
            if ( *(_DWORD *)(v33 + 408) != 2 )
              goto LABEL_92;
            v96 = (unsigned __int8)v1621;
            v1616 = *(_QWORD *)(*(_QWORD *)(v33 + 24) + 24LL);
            DP_PRINT_STATS("Node Tx ML peer Stats:\n", v88, v89, v90, v91, v92, v93, v94, v95);
            DP_PRINT_STATS(
              "Total Packet Completions = %llu",
              v97,
              v98,
              v99,
              v100,
              v101,
              v102,
              v103,
              v104,
              *(_QWORD *)(v36 + 8));
            DP_PRINT_STATS(
              "Total Bytes Completions = %llu",
              v105,
              v106,
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              *(_QWORD *)(v36 + 16));
            DP_PRINT_STATS(
              "Packets Failed = %u",
              v113,
              v114,
              v115,
              v116,
              v117,
              v118,
              v119,
              v120,
              *(unsigned int *)(v36 + 108));
            DP_PRINT_STATS(
              "Bytes and Packets transmitted  in last one sec:",
              v121,
              v122,
              v123,
              v124,
              v125,
              v126,
              v127,
              v128);
            DP_PRINT_STATS(
              "\tBytes transmitted in last sec: %u",
              v129,
              v130,
              v131,
              v132,
              v133,
              v134,
              v135,
              v136,
              *(unsigned int *)(v36 + 200));
            DP_PRINT_STATS(
              "\tData transmitted in last sec: %u",
              v137,
              v138,
              v139,
              v140,
              v141,
              v142,
              v143,
              v144,
              *(unsigned int *)(v36 + 204));
            DP_PRINT_STATS("Node Rx ML peer Stats:\n", v145, v146, v147, v148, v149, v150, v151, v152);
            DP_PRINT_STATS(
              "Packets Sent To Stack = %llu",
              v153,
              v154,
              v155,
              v156,
              v157,
              v158,
              v159,
              v160,
              *(_QWORD *)(v36 + 2752));
            DP_PRINT_STATS(
              "Bytes Sent To Stack = %llu",
              v161,
              v162,
              v163,
              v164,
              v165,
              v166,
              v167,
              v168,
              *(_QWORD *)(v36 + 2760));
            DP_PRINT_STATS(
              "Bytes and Packets received in last one sec:",
              v169,
              v170,
              v171,
              v172,
              v173,
              v174,
              v175,
              v176);
            DP_PRINT_STATS(
              "\tBytes received in last sec: %u",
              v177,
              v178,
              v179,
              v180,
              v181,
              v182,
              v183,
              v184,
              *(unsigned int *)(v36 + 4072));
            DP_PRINT_STATS(
              "\tData received in last sec: %u",
              v185,
              v186,
              v187,
              v188,
              v189,
              v190,
              v191,
              v192,
              *(unsigned int *)(v36 + 4076));
            DP_PRINT_STATS("Per Link TxRx Stats:\n", v193, v194, v195, v196, v197, v198, v199, v200);
            v1613 = v96;
            if ( (_DWORD)v96 )
            {
              v201 = 0;
              v202 = v36 + 1104;
              v33 = v36 + 3672;
              v203 = v36 + 3796;
              v204 = v36 + 3904;
              v1612 = v36;
LABEL_55:
              DP_PRINT_STATS("Link %u TxRx Stats:\n", v88, v89, v90, v91, v92, v93, v94, v95, (unsigned int)v201);
              v10 = (unsigned __int8 *)(v36 + 4544 * v201);
              if ( v10 )
              {
                v213 = *v10;
                v214 = v10[1];
                v215 = v10[2];
                v216 = v10[5];
              }
              else
              {
                v215 = 0;
                v213 = 0;
                v214 = 0;
                v216 = 0;
              }
              v1615 = v203;
              v1614 = v201;
              memset(v1623, 0, 48);
              memset(v1622, 0, sizeof(v1622));
              DP_PRINT_STATS(
                "peer_mac_addr = %02x:%02x:%02x:**:**:%02x",
                v205,
                v206,
                v207,
                v208,
                v209,
                v210,
                v211,
                v212,
                v213,
                v214,
                v215,
                v216);
              DP_PRINT_STATS("Node Tx Stats:", v217, v218, v219, v220, v221, v222, v223, v224);
              DP_PRINT_STATS(
                "Success Packets = %llu",
                v225,
                v226,
                v227,
                v228,
                v229,
                v230,
                v231,
                v232,
                *((_QWORD *)v10 + 11));
              DP_PRINT_STATS(
                "Success Bytes = %llu",
                v233,
                v234,
                v235,
                v236,
                v237,
                v238,
                v239,
                v240,
                *((_QWORD *)v10 + 12));
              DP_PRINT_STATS(
                "Success Packets in TWT Session = %llu",
                v241,
                v242,
                v243,
                v244,
                v245,
                v246,
                v247,
                v248,
                *((_QWORD *)v10 + 227));
              DP_PRINT_STATS(
                "Success Bytes in TWT Session = %llu",
                v249,
                v250,
                v251,
                v252,
                v253,
                v254,
                v255,
                v256,
                *((_QWORD *)v10 + 228));
              DP_PRINT_STATS(
                "Unicast Success Packets = %llu",
                v257,
                v258,
                v259,
                v260,
                v261,
                v262,
                v263,
                v264,
                *((_QWORD *)v10 + 3));
              DP_PRINT_STATS(
                "Unicast Success Bytes = %llu",
                v265,
                v266,
                v267,
                v268,
                v269,
                v270,
                v271,
                v272,
                *((_QWORD *)v10 + 4));
              DP_PRINT_STATS(
                "Multicast Success Packets = %llu",
                v273,
                v274,
                v275,
                v276,
                v277,
                v278,
                v279,
                v280,
                *((_QWORD *)v10 + 5));
              DP_PRINT_STATS(
                "Multicast Success Bytes = %llu",
                v281,
                v282,
                v283,
                v284,
                v285,
                v286,
                v287,
                v288,
                *((_QWORD *)v10 + 6));
              DP_PRINT_STATS(
                "Broadcast Success Packets = %llu",
                v289,
                v290,
                v291,
                v292,
                v293,
                v294,
                v295,
                v296,
                *((_QWORD *)v10 + 7));
              DP_PRINT_STATS(
                "Broadcast Success Bytes = %llu",
                v297,
                v298,
                v299,
                v300,
                v301,
                v302,
                v303,
                v304,
                *((_QWORD *)v10 + 8));
              DP_PRINT_STATS(
                "Packets Successfully Sent after one or more retry = %u",
                v305,
                v306,
                v307,
                v308,
                v309,
                v310,
                v311,
                v312,
                *((unsigned int *)v10 + 242));
              DP_PRINT_STATS(
                "Total msdu Packets retries = %d",
                v313,
                v314,
                v315,
                v316,
                v317,
                v318,
                v319,
                v320,
                *((unsigned int *)v10 + 243));
              DP_PRINT_STATS(
                "Packets  Sent Success after more than one retry = %u",
                v321,
                v322,
                v323,
                v324,
                v325,
                v326,
                v327,
                v328,
                *((unsigned int *)v10 + 244));
              DP_PRINT_STATS(
                "Packets Sent Failed = %u",
                v329,
                v330,
                v331,
                v332,
                v333,
                v334,
                v335,
                v336,
                *((unsigned int *)v10 + 27));
              DP_PRINT_STATS(
                "Packets Failed due to retry threshold breach = %u",
                v337,
                v338,
                v339,
                v340,
                v341,
                v342,
                v343,
                v344,
                *((unsigned int *)v10 + 241));
              DP_PRINT_STATS(
                "mpdu Packets Retries = %u",
                v345,
                v346,
                v347,
                v348,
                v349,
                v350,
                v351,
                v352,
                *((unsigned int *)v10 + 239));
              DP_PRINT_STATS(
                "Total mpdu packets retries = %u",
                v353,
                v354,
                v355,
                v356,
                v357,
                v358,
                v359,
                v360,
                *((unsigned int *)v10 + 240));
              DP_PRINT_STATS(
                "Packets In OFDMA = %u",
                v361,
                v362,
                v363,
                v364,
                v365,
                v366,
                v367,
                v368,
                *((unsigned int *)v10 + 28));
              DP_PRINT_STATS(
                "Packets In STBC = %u",
                v369,
                v370,
                v371,
                v372,
                v373,
                v374,
                v375,
                v376,
                *((unsigned int *)v10 + 29));
              DP_PRINT_STATS(
                "Packets In LDPC = %u",
                v377,
                v378,
                v379,
                v380,
                v381,
                v382,
                v383,
                v384,
                *((unsigned int *)v10 + 30));
              DP_PRINT_STATS(
                "Packet Retries = %u",
                v385,
                v386,
                v387,
                v388,
                v389,
                v390,
                v391,
                v392,
                *((unsigned int *)v10 + 31));
              DP_PRINT_STATS(
                "MSDU's Part of AMSDU = %u",
                v393,
                v394,
                v395,
                v396,
                v397,
                v398,
                v399,
                v400,
                *((unsigned int *)v10 + 34));
              DP_PRINT_STATS(
                "Msdu's As Part of Ampdu = %u",
                v401,
                v402,
                v403,
                v404,
                v405,
                v406,
                v407,
                v408,
                *((unsigned int *)v10 + 238));
              DP_PRINT_STATS(
                "Msdu's As Ampdu = %u",
                v409,
                v410,
                v411,
                v412,
                v413,
                v414,
                v415,
                v416,
                *((unsigned int *)v10 + 237));
              DP_PRINT_STATS(
                "Last Packet RSSI = %u",
                v417,
                v418,
                v419,
                v420,
                v421,
                v422,
                v423,
                v424,
                *((unsigned int *)v10 + 46));
              v433 = *((unsigned int *)v10 + 47);
              if ( (v433 & 0x80) != 0 )
                v433 += 255LL;
              DP_PRINT_STATS("Average Packet RSSI = %u", v425, v426, v427, v428, v429, v430, v431, v432, v433 >> 8);
              DP_PRINT_STATS(
                "Dropped At FW: Removed Pkts = %llu",
                v434,
                v435,
                v436,
                v437,
                v438,
                v439,
                v440,
                v441,
                *((_QWORD *)v10 + 95));
              DP_PRINT_STATS(
                "Release source not TQM = %u",
                v442,
                v443,
                v444,
                v445,
                v446,
                v447,
                v448,
                v449,
                *((unsigned int *)v10 + 518));
              if ( v1616 && !(unsigned int)wlan_cfg_get_dp_pdev_nss_enabled(*(_QWORD *)(v1616 + 288)) )
                DP_PRINT_STATS(
                  "Dropped At FW: Removed bytes = %llu",
                  v450,
                  v451,
                  v452,
                  v453,
                  v454,
                  v455,
                  v456,
                  v457,
                  *((_QWORD *)v10 + 96));
              DP_PRINT_STATS(
                "Dropped At FW: Removed transmitted = %u",
                v450,
                v451,
                v452,
                v453,
                v454,
                v455,
                v456,
                v457,
                *((_QWORD *)v10 + 98));
              DP_PRINT_STATS(
                "Dropped At FW: Removed Untransmitted = %u",
                v458,
                v459,
                v460,
                v461,
                v462,
                v463,
                v464,
                v465,
                *((unsigned int *)v10 + 194));
              DP_PRINT_STATS(
                "Dropped At FW: removed untransmitted fw_reason1 = %u",
                v466,
                v467,
                v468,
                v469,
                v470,
                v471,
                v472,
                v473,
                *((unsigned int *)v10 + 201));
              DP_PRINT_STATS(
                "Dropped At FW: removed untransmitted fw_reason2 = %u",
                v474,
                v475,
                v476,
                v477,
                v478,
                v479,
                v480,
                v481,
                *((unsigned int *)v10 + 202));
              DP_PRINT_STATS(
                "Dropped At FW: removed untransmitted fw_reason3 = %u",
                v482,
                v483,
                v484,
                v485,
                v486,
                v487,
                v488,
                v489,
                *((unsigned int *)v10 + 203));
              DP_PRINT_STATS(
                "Dropped At FW:removed untransmitted disable queue = %u",
                v490,
                v491,
                v492,
                v493,
                v494,
                v495,
                v496,
                v497,
                *((unsigned int *)v10 + 204));
              DP_PRINT_STATS(
                "Dropped At FW: removed untransmitted no match = %u",
                v498,
                v499,
                v500,
                v501,
                v502,
                v503,
                v504,
                v505,
                *((unsigned int *)v10 + 205));
              DP_PRINT_STATS(
                "Dropped due to HW threshold criteria = %u",
                v506,
                v507,
                v508,
                v509,
                v510,
                v511,
                v512,
                v513,
                *((unsigned int *)v10 + 206));
              DP_PRINT_STATS(
                "Dropped due Link desc not available drop in HW = %u",
                v514,
                v515,
                v516,
                v517,
                v518,
                v519,
                v520,
                v521,
                *((unsigned int *)v10 + 207));
              DP_PRINT_STATS(
                "Drop bit set or invalid flow = %u",
                v522,
                v523,
                v524,
                v525,
                v526,
                v527,
                v528,
                v529,
                *((unsigned int *)v10 + 208));
              DP_PRINT_STATS(
                "MCAST vdev drop in HW = %u",
                v530,
                v531,
                v532,
                v533,
                v534,
                v535,
                v536,
                v537,
                *((unsigned int *)v10 + 209));
              DP_PRINT_STATS(
                "Dropped : Age Out = %u",
                v538,
                v539,
                v540,
                v541,
                v542,
                v543,
                v544,
                v545,
                *((unsigned int *)v10 + 200));
              DP_PRINT_STATS(
                "Dropped : Invalid Reason = %u",
                v546,
                v547,
                v548,
                v549,
                v550,
                v551,
                v552,
                v553,
                *((unsigned int *)v10 + 210));
              DP_PRINT_STATS("NAWDS : ", v554, v555, v556, v557, v558, v559, v560, v561);
              DP_PRINT_STATS(
                "Nawds multicast Drop Tx Packet = %u",
                v562,
                v563,
                v564,
                v565,
                v566,
                v567,
                v568,
                v569,
                *((unsigned int *)v10 + 26));
              DP_PRINT_STATS(
                "\tNawds multicast  Tx Packet Count = %llu",
                v570,
                v571,
                v572,
                v573,
                v574,
                v575,
                v576,
                v577,
                *((_QWORD *)v10 + 9));
              DP_PRINT_STATS(
                "\tNawds multicast Tx Packet Bytes = %llu",
                v578,
                v579,
                v580,
                v581,
                v582,
                v583,
                v584,
                v585,
                *((_QWORD *)v10 + 10));
              DP_PRINT_STATS(
                "PPDU's = %u",
                v586,
                v587,
                v588,
                v589,
                v590,
                v591,
                v592,
                v593,
                *((unsigned int *)v10 + 246));
              DP_PRINT_STATS(
                "Number of PPDU's with Punctured Preamble = %u",
                v594,
                v595,
                v596,
                v597,
                v598,
                v599,
                v600,
                v601,
                *((unsigned int *)v10 + 161));
              DP_PRINT_STATS(
                "MPDU's Successful = %u",
                v602,
                v603,
                v604,
                v605,
                v606,
                v607,
                v608,
                v609,
                *((unsigned int *)v10 + 247));
              DP_PRINT_STATS(
                "MPDU's Tried = %u",
                v610,
                v611,
                v612,
                v613,
                v614,
                v615,
                v616,
                v617,
                *((unsigned int *)v10 + 248));
              DP_PRINT_STATS("Rate Info:", v618, v619, v620, v621, v622, v623, v624, v625);
              dp_print_common_rates_info((__int64)(v10 + 216), v626, v627, v628, v629, v630, v631, v632, v633);
              DP_PRINT_STATS(
                "SGI = 0.8us %u 0.4us %u 1.6us %u 3.2us %u",
                v634,
                v635,
                v636,
                v637,
                v638,
                v639,
                v640,
                v641,
                *((unsigned int *)v10 + 156),
                *((unsigned int *)v10 + 157),
                *((unsigned int *)v10 + 158),
                *((unsigned int *)v10 + 159));
              DP_PRINT_STATS("Wireless Mutlimedia ", v642, v643, v644, v645, v646, v647, v648, v649);
              DP_PRINT_STATS(
                "\t Best effort = %u",
                v650,
                v651,
                v652,
                v653,
                v654,
                v655,
                v656,
                v657,
                *((unsigned int *)v10 + 178));
              DP_PRINT_STATS(
                "\t Background= %u",
                v658,
                v659,
                v660,
                v661,
                v662,
                v663,
                v664,
                v665,
                *((unsigned int *)v10 + 179));
              DP_PRINT_STATS(
                "\t Video = %u",
                v666,
                v667,
                v668,
                v669,
                v670,
                v671,
                v672,
                v673,
                *((unsigned int *)v10 + 180));
              DP_PRINT_STATS(
                "\t Voice = %u",
                v674,
                v675,
                v676,
                v677,
                v678,
                v679,
                v680,
                v681,
                *((unsigned int *)v10 + 181));
              DP_PRINT_STATS("Excess Retries per AC ", v682, v683, v684, v685, v686, v687, v688, v689);
              DP_PRINT_STATS(
                "\t Best effort = %u",
                v690,
                v691,
                v692,
                v693,
                v694,
                v695,
                v696,
                v697,
                *((unsigned int *)v10 + 182));
              DP_PRINT_STATS(
                "\t Background= %u",
                v698,
                v699,
                v700,
                v701,
                v702,
                v703,
                v704,
                v705,
                *((unsigned int *)v10 + 183));
              DP_PRINT_STATS(
                "\t Video = %u",
                v706,
                v707,
                v708,
                v709,
                v710,
                v711,
                v712,
                v713,
                *((unsigned int *)v10 + 184));
              DP_PRINT_STATS(
                "\t Voice = %u",
                v714,
                v715,
                v716,
                v717,
                v718,
                v719,
                v720,
                v721,
                *((unsigned int *)v10 + 185));
              dp_print_nss((char *)v1623, (_DWORD *)v10 + 162);
              DP_PRINT_STATS("NSS(1-8) = %s", v722, v723, v724, v725, v726, v727, v728, v729, v1623);
              DP_PRINT_STATS("Transmit Type :", v730, v731, v732, v733, v734, v735, v736, v737);
              DP_PRINT_STATS(
                "MSDUs Success: SU %u, MU_MIMO %u, MU_OFDMA %u, MU_MIMO_OFDMA %u",
                v738,
                v739,
                v740,
                v741,
                v742,
                v743,
                v744,
                v745,
                *((unsigned int *)v10 + 249),
                *((unsigned int *)v10 + 252),
                *((unsigned int *)v10 + 255),
                *((unsigned int *)v10 + 258));
              DP_PRINT_STATS(
                "MPDUs Success: SU %u, MU_MIMO %u, MU_OFDMA %u, MU_MIMO_OFDMA %u",
                v746,
                v747,
                v748,
                v749,
                v750,
                v751,
                v752,
                v753,
                *((unsigned int *)v10 + 250),
                *((unsigned int *)v10 + 253),
                *((unsigned int *)v10 + 256),
                *((unsigned int *)v10 + 259));
              DP_PRINT_STATS(
                "MPDUs Tried: SU %u, MU_MIMO %u, MU_OFDMA %u, MU_MIMO_OFDMA %u",
                v754,
                v755,
                v756,
                v757,
                v758,
                v759,
                v760,
                v761,
                *((unsigned int *)v10 + 251),
                *((unsigned int *)v10 + 254),
                *((unsigned int *)v10 + 257),
                *((unsigned int *)v10 + 260));
              v762 = 0;
LABEL_65:
              v36 = 0;
              v771 = 0;
              while ( v771 <= 0x60 )
              {
                v772 = snprintf((char *)v1622 + v771, 96 - v771, " %u", *(_DWORD *)(v202 + 4LL * v762 + 4 * v36));
                v78 = v36 + 1;
                if ( (unsigned int)v36 <= 0xE )
                {
                  v781 = v762 + v36;
                  v771 += v772;
                  ++v36;
                  if ( v781 < 0x3F )
                    continue;
                }
                v762 += v78;
                DP_PRINT_STATS(
                  "User position list for GID %02d->%u: [%s]",
                  v773,
                  v774,
                  v775,
                  v776,
                  v777,
                  v778,
                  v779,
                  v780,
                  (unsigned int)v762 - 16,
                  (unsigned int)v762 - 1,
                  v1622);
                if ( (unsigned __int8)(v762 - 1) < 0x3Fu )
                  goto LABEL_65;
                DP_PRINT_STATS(
                  "Last Packet RU index [%u], Size [%u]",
                  v763,
                  v764,
                  v765,
                  v766,
                  v767,
                  v768,
                  v769,
                  v770,
                  *((unsigned int *)v10 + 340),
                  *((unsigned int *)v10 + 341));
                DP_PRINT_STATS("Aggregation:", v782, v783, v784, v785, v786, v787, v788, v789);
                DP_PRINT_STATS(
                  "Number of Msdu's Part of Amsdu = %u",
                  v790,
                  v791,
                  v792,
                  v793,
                  v794,
                  v795,
                  v796,
                  v797,
                  *((unsigned int *)v10 + 34));
                DP_PRINT_STATS(
                  "Number of Msdu's With No Msdu Level Aggregation = %u",
                  v798,
                  v799,
                  v800,
                  v801,
                  v802,
                  v803,
                  v804,
                  v805,
                  *((unsigned int *)v10 + 33));
                if ( v1616 )
                {
                  v814 = *(_DWORD **)(*(_QWORD *)(v1616 + 8) + 1608LL);
                  if ( v814 )
                  {
                    if ( *(v814 - 1) != -1009236478 )
                      __break(0x8228u);
                    ((void (__fastcall *)(unsigned __int8 *, _QWORD))v814)(v10, 0);
                  }
                }
                DP_PRINT_STATS("Node Rx Stats:", v806, v807, v808, v809, v810, v811, v812, v813);
                DP_PRINT_STATS("Ring Id = %u", v815, v816, v817, v818, v819, v820, v821, v822, 0);
                DP_PRINT_STATS(
                  "\tPackets Received = %llu",
                  v823,
                  v824,
                  v825,
                  v826,
                  v827,
                  v828,
                  v829,
                  v830,
                  *((_QWORD *)v10 + 346));
                DP_PRINT_STATS(
                  "\tBytes Received = %llu",
                  v831,
                  v832,
                  v833,
                  v834,
                  v835,
                  v836,
                  v837,
                  v838,
                  *((_QWORD *)v10 + 347));
                DP_PRINT_STATS("Ring Id = %u", v839, v840, v841, v842, v843, v844, v845, v846, 1);
                DP_PRINT_STATS(
                  "\tPackets Received = %llu",
                  v847,
                  v848,
                  v849,
                  v850,
                  v851,
                  v852,
                  v853,
                  v854,
                  *((_QWORD *)v10 + 348));
                DP_PRINT_STATS(
                  "\tBytes Received = %llu",
                  v855,
                  v856,
                  v857,
                  v858,
                  v859,
                  v860,
                  v861,
                  v862,
                  *((_QWORD *)v10 + 349));
                DP_PRINT_STATS("Ring Id = %u", v863, v864, v865, v866, v867, v868, v869, v870, 2);
                DP_PRINT_STATS(
                  "\tPackets Received = %llu",
                  v871,
                  v872,
                  v873,
                  v874,
                  v875,
                  v876,
                  v877,
                  v878,
                  *((_QWORD *)v10 + 350));
                DP_PRINT_STATS(
                  "\tBytes Received = %llu",
                  v879,
                  v880,
                  v881,
                  v882,
                  v883,
                  v884,
                  v885,
                  v886,
                  *((_QWORD *)v10 + 351));
                DP_PRINT_STATS("Ring Id = %u", v887, v888, v889, v890, v891, v892, v893, v894, 3);
                DP_PRINT_STATS(
                  "\tPackets Received = %llu",
                  v895,
                  v896,
                  v897,
                  v898,
                  v899,
                  v900,
                  v901,
                  v902,
                  *((_QWORD *)v10 + 352));
                DP_PRINT_STATS(
                  "\tBytes Received = %llu",
                  v903,
                  v904,
                  v905,
                  v906,
                  v907,
                  v908,
                  v909,
                  v910,
                  *((_QWORD *)v10 + 353));
                DP_PRINT_STATS("Ring Id = %u", v911, v912, v913, v914, v915, v916, v917, v918, 4);
                DP_PRINT_STATS(
                  "\tPackets Received = %llu",
                  v919,
                  v920,
                  v921,
                  v922,
                  v923,
                  v924,
                  v925,
                  v926,
                  *((_QWORD *)v10 + 354));
                DP_PRINT_STATS(
                  "\tBytes Received = %llu",
                  v927,
                  v928,
                  v929,
                  v930,
                  v931,
                  v932,
                  v933,
                  v934,
                  *((_QWORD *)v10 + 355));
                DP_PRINT_STATS("Ring Id = %u", v935, v936, v937, v938, v939, v940, v941, v942, 5);
                DP_PRINT_STATS(
                  "\tPackets Received = %llu",
                  v943,
                  v944,
                  v945,
                  v946,
                  v947,
                  v948,
                  v949,
                  v950,
                  *((_QWORD *)v10 + 356));
                DP_PRINT_STATS(
                  "\tBytes Received = %llu",
                  v951,
                  v952,
                  v953,
                  v954,
                  v955,
                  v956,
                  v957,
                  v958,
                  *((_QWORD *)v10 + 357));
                DP_PRINT_STATS("Ring Id = %u", v959, v960, v961, v962, v963, v964, v965, v966, 6);
                DP_PRINT_STATS(
                  "\tPackets Received = %llu",
                  v967,
                  v968,
                  v969,
                  v970,
                  v971,
                  v972,
                  v973,
                  v974,
                  *((_QWORD *)v10 + 358));
                DP_PRINT_STATS(
                  "\tBytes Received = %llu",
                  v975,
                  v976,
                  v977,
                  v978,
                  v979,
                  v980,
                  v981,
                  v982,
                  *((_QWORD *)v10 + 359));
                DP_PRINT_STATS("Ring Id = %u", v983, v984, v985, v986, v987, v988, v989, v990, 7);
                DP_PRINT_STATS(
                  "\tPackets Received = %llu",
                  v991,
                  v992,
                  v993,
                  v994,
                  v995,
                  v996,
                  v997,
                  v998,
                  *((_QWORD *)v10 + 360));
                DP_PRINT_STATS(
                  "\tBytes Received = %llu",
                  v999,
                  v1000,
                  v1001,
                  v1002,
                  v1003,
                  v1004,
                  v1005,
                  v1006,
                  *((_QWORD *)v10 + 361));
                DP_PRINT_STATS(
                  "Packets Received on lmac[%u] = %llu ( %llu ),",
                  v1007,
                  v1008,
                  v1009,
                  v1010,
                  v1011,
                  v1012,
                  v1013,
                  v1014,
                  0,
                  *((_QWORD *)v10 + 364),
                  *((_QWORD *)v10 + 365));
                DP_PRINT_STATS(
                  "Packets Received on lmac[%u] = %llu ( %llu ),",
                  v1015,
                  v1016,
                  v1017,
                  v1018,
                  v1019,
                  v1020,
                  v1021,
                  v1022,
                  1,
                  *((_QWORD *)v10 + 366),
                  *((_QWORD *)v10 + 367));
                DP_PRINT_STATS(
                  "Unicast Packets Received = %llu",
                  v1023,
                  v1024,
                  v1025,
                  v1026,
                  v1027,
                  v1028,
                  v1029,
                  v1030,
                  *((_QWORD *)v10 + 368));
                DP_PRINT_STATS(
                  "Unicast Bytes Received = %llu",
                  v1031,
                  v1032,
                  v1033,
                  v1034,
                  v1035,
                  v1036,
                  v1037,
                  v1038,
                  *((_QWORD *)v10 + 369));
                DP_PRINT_STATS(
                  "Multicast Packets Received = %llu",
                  v1039,
                  v1040,
                  v1041,
                  v1042,
                  v1043,
                  v1044,
                  v1045,
                  v1046,
                  *((_QWORD *)v10 + 370));
                DP_PRINT_STATS(
                  "Multicast Bytes Received = %llu",
                  v1047,
                  v1048,
                  v1049,
                  v1050,
                  v1051,
                  v1052,
                  v1053,
                  v1054,
                  *((_QWORD *)v10 + 371));
                DP_PRINT_STATS(
                  "Broadcast Packets Received = %llu",
                  v1055,
                  v1056,
                  v1057,
                  v1058,
                  v1059,
                  v1060,
                  v1061,
                  v1062,
                  *((_QWORD *)v10 + 372));
                DP_PRINT_STATS(
                  "Broadcast Bytes Received = %llu",
                  v1063,
                  v1064,
                  v1065,
                  v1066,
                  v1067,
                  v1068,
                  v1069,
                  v1070,
                  *((_QWORD *)v10 + 373));
                DP_PRINT_STATS(
                  "Packets Sent To Stack in TWT Session = %llu",
                  v1071,
                  v1072,
                  v1073,
                  v1074,
                  v1075,
                  v1076,
                  v1077,
                  v1078,
                  *((_QWORD *)v10 + 526));
                DP_PRINT_STATS(
                  "Bytes Sent To Stack in TWT Session = %llu",
                  v1079,
                  v1080,
                  v1081,
                  v1082,
                  v1083,
                  v1084,
                  v1085,
                  v1086,
                  *((_QWORD *)v10 + 527));
                DP_PRINT_STATS(
                  "Intra BSS Packets Received = %llu",
                  v1087,
                  v1088,
                  v1089,
                  v1090,
                  v1091,
                  v1092,
                  v1093,
                  v1094,
                  *((_QWORD *)v10 + 384));
                DP_PRINT_STATS(
                  "Intra BSS Bytes Received = %llu",
                  v1095,
                  v1096,
                  v1097,
                  v1098,
                  v1099,
                  v1100,
                  v1101,
                  v1102,
                  *((_QWORD *)v10 + 385));
                DP_PRINT_STATS(
                  "Intra BSS Packets Failed = %llu",
                  v1103,
                  v1104,
                  v1105,
                  v1106,
                  v1107,
                  v1108,
                  v1109,
                  v1110,
                  *((_QWORD *)v10 + 386));
                DP_PRINT_STATS(
                  "Intra BSS Bytes Failed = %llu",
                  v1111,
                  v1112,
                  v1113,
                  v1114,
                  v1115,
                  v1116,
                  v1117,
                  v1118,
                  *((_QWORD *)v10 + 387));
                DP_PRINT_STATS(
                  "Intra BSS MDNS Packets Not Forwarded  = %u",
                  v1119,
                  v1120,
                  v1121,
                  v1122,
                  v1123,
                  v1124,
                  v1125,
                  v1126,
                  *((unsigned int *)v10 + 776));
                DP_PRINT_STATS(
                  "Raw Packets Received = %llu",
                  v1127,
                  v1128,
                  v1129,
                  v1130,
                  v1131,
                  v1132,
                  v1133,
                  v1134,
                  *((_QWORD *)v10 + 374));
                DP_PRINT_STATS(
                  "Raw Bytes Received = %llu",
                  v1135,
                  v1136,
                  v1137,
                  v1138,
                  v1139,
                  v1140,
                  v1141,
                  v1142,
                  *((_QWORD *)v10 + 375));
                DP_PRINT_STATS(
                  "Errors: MIC Errors = %u",
                  v1143,
                  v1144,
                  v1145,
                  v1146,
                  v1147,
                  v1148,
                  v1149,
                  v1150,
                  *((unsigned int *)v10 + 778));
                DP_PRINT_STATS(
                  "Errors: Decryption Errors = %u",
                  v1151,
                  v1152,
                  v1153,
                  v1154,
                  v1155,
                  v1156,
                  v1157,
                  v1158,
                  *((unsigned int *)v10 + 779));
                DP_PRINT_STATS(
                  "Errors: PN Errors = %u",
                  v1159,
                  v1160,
                  v1161,
                  v1162,
                  v1163,
                  v1164,
                  v1165,
                  v1166,
                  *((unsigned int *)v10 + 781));
                DP_PRINT_STATS(
                  "Errors: OOR Errors = %u",
                  v1167,
                  v1168,
                  v1169,
                  v1170,
                  v1171,
                  v1172,
                  v1173,
                  v1174,
                  *((unsigned int *)v10 + 782));
                DP_PRINT_STATS(
                  "Errors: 2k Jump Errors = %u",
                  v1175,
                  v1176,
                  v1177,
                  v1178,
                  v1179,
                  v1180,
                  v1181,
                  v1182,
                  *((unsigned int *)v10 + 783));
                DP_PRINT_STATS(
                  "Errors: RXDMA Wifi Parse Errors = %u",
                  v1183,
                  v1184,
                  v1185,
                  v1186,
                  v1187,
                  v1188,
                  v1189,
                  v1190,
                  *((unsigned int *)v10 + 784));
                DP_PRINT_STATS(
                  "Msdu's Received As Part of Ampdu = %u",
                  v1191,
                  v1192,
                  v1193,
                  v1194,
                  v1195,
                  v1196,
                  v1197,
                  v1198,
                  *((unsigned int *)v10 + 1001));
                DP_PRINT_STATS(
                  "Msdu's Received As Ampdu = %u",
                  v1199,
                  v1200,
                  v1201,
                  v1202,
                  v1203,
                  v1204,
                  v1205,
                  v1206,
                  *((unsigned int *)v10 + 1002));
                DP_PRINT_STATS(
                  "Msdu's Received Not Part of Amsdu's = %u",
                  v1207,
                  v1208,
                  v1209,
                  v1210,
                  v1211,
                  v1212,
                  v1213,
                  v1214,
                  *((unsigned int *)v10 + 1003));
                DP_PRINT_STATS(
                  "MSDUs Received As Part of Amsdu = %u",
                  v1215,
                  v1216,
                  v1217,
                  v1218,
                  v1219,
                  v1220,
                  v1221,
                  v1222,
                  *((unsigned int *)v10 + 1004));
                DP_PRINT_STATS(
                  "MSDU Rx Retries= %u",
                  v1223,
                  v1224,
                  v1225,
                  v1226,
                  v1227,
                  v1228,
                  v1229,
                  v1230,
                  *((unsigned int *)v10 + 1020));
                DP_PRINT_STATS(
                  "MPDU Rx Retries= %u",
                  v1231,
                  v1232,
                  v1233,
                  v1234,
                  v1235,
                  v1236,
                  v1237,
                  v1238,
                  *((unsigned int *)v10 + 1056));
                DP_PRINT_STATS("NAWDS : ", v1239, v1240, v1241, v1242, v1243, v1244, v1245, v1246);
                DP_PRINT_STATS(
                  "\tNawds multicast Drop Rx Packet = %u",
                  v1247,
                  v1248,
                  v1249,
                  v1250,
                  v1251,
                  v1252,
                  v1253,
                  v1254,
                  *((unsigned int *)v10 + 752));
                DP_PRINT_STATS(
                  " 3address multicast Drop Rx Packet = %u",
                  v1255,
                  v1256,
                  v1257,
                  v1258,
                  v1259,
                  v1260,
                  v1261,
                  v1262,
                  *((unsigned int *)v10 + 1113));
                DP_PRINT_STATS(
                  "SGI = 0.8us %u 0.4us %u 1.6us %u 3.2us %u",
                  v1263,
                  v1264,
                  v1265,
                  v1266,
                  v1267,
                  v1268,
                  v1269,
                  v1270,
                  *((unsigned int *)v10 + 895),
                  *((unsigned int *)v10 + 896),
                  *((unsigned int *)v10 + 897),
                  *((unsigned int *)v10 + 898));
                DP_PRINT_STATS("Wireless Mutlimedia ", v1271, v1272, v1273, v1274, v1275, v1276, v1277, v1278);
                DP_PRINT_STATS(
                  "\t Best effort = %u",
                  v1279,
                  v1280,
                  v1281,
                  v1282,
                  v1283,
                  v1284,
                  v1285,
                  v1286,
                  *((unsigned int *)v10 + 785));
                DP_PRINT_STATS(
                  "\t Background= %u",
                  v1287,
                  v1288,
                  v1289,
                  v1290,
                  v1291,
                  v1292,
                  v1293,
                  v1294,
                  *((unsigned int *)v10 + 786));
                DP_PRINT_STATS(
                  "\t Video = %u",
                  v1295,
                  v1296,
                  v1297,
                  v1298,
                  v1299,
                  v1300,
                  v1301,
                  v1302,
                  *((unsigned int *)v10 + 787));
                DP_PRINT_STATS(
                  "\t Voice = %u",
                  v1303,
                  v1304,
                  v1305,
                  v1306,
                  v1307,
                  v1308,
                  v1309,
                  v1310,
                  *((unsigned int *)v10 + 788));
                DP_PRINT_STATS(
                  " Total Rx PPDU Count = %u",
                  v1311,
                  v1312,
                  v1313,
                  v1314,
                  v1315,
                  v1316,
                  v1317,
                  v1318,
                  *((unsigned int *)v10 + 1022));
                DP_PRINT_STATS(
                  " Total Rx MPDU Count = %u",
                  v1319,
                  v1320,
                  v1321,
                  v1322,
                  v1323,
                  v1324,
                  v1325,
                  v1326,
                  *((unsigned int *)v10 + 1021));
                DP_PRINT_STATS("MSDU Reception Type", v1327, v1328, v1329, v1330, v1331, v1332, v1333, v1334);
                DP_PRINT_STATS(
                  "SU %u MU_MIMO %u MU_OFDMA %u MU_OFDMA_MIMO %u",
                  v1335,
                  v1336,
                  v1337,
                  v1338,
                  v1339,
                  v1340,
                  v1341,
                  v1342,
                  *((unsigned int *)v10 + 789),
                  *((unsigned int *)v10 + 790),
                  *((unsigned int *)v10 + 791),
                  *((unsigned int *)v10 + 792));
                DP_PRINT_STATS("PPDU Reception Type", v1343, v1344, v1345, v1346, v1347, v1348, v1349, v1350);
                DP_PRINT_STATS(
                  "SU %u MU_MIMO %u MU_OFDMA %u MU_OFDMA_MIMO %u",
                  v1351,
                  v1352,
                  v1353,
                  v1354,
                  v1355,
                  v1356,
                  v1357,
                  v1358,
                  *((unsigned int *)v10 + 935),
                  *((unsigned int *)v10 + 936),
                  *((unsigned int *)v10 + 937),
                  *((unsigned int *)v10 + 938));
                dp_print_common_rates_info(
                  (__int64)(v10 + 3172),
                  v1359,
                  v1360,
                  v1361,
                  v1362,
                  v1363,
                  v1364,
                  v1365,
                  v1366);
                DP_PRINT_STATS("PPDU Count", v1367, v1368, v1369, v1370, v1371, v1372, v1373, v1374);
                v1383 = 0;
                v1384 = "HE MCS 0 (BPSK 1/2)     ";
                do
                {
                  if ( v1384[34] )
                    DP_PRINT_STATS(
                      "\t%s = %d",
                      v1375,
                      v1376,
                      v1377,
                      v1378,
                      v1379,
                      v1380,
                      v1381,
                      v1382,
                      v1384,
                      *(unsigned int *)(v33 + v1383));
                  v1383 += 4;
                  v1384 += 35;
                }
                while ( v1383 != 68 );
                DP_PRINT_STATS("\n", v1375, v1376, v1377, v1378, v1379, v1380, v1381, v1382);
                DP_PRINT_STATS("PPDU Count", v1385, v1386, v1387, v1388, v1389, v1390, v1391, v1392);
                v1401 = 0;
                v1402 = "HE MU-MIMO MCS 0 (BPSK 1/2)     ";
                do
                {
                  if ( v1402[34] )
                    DP_PRINT_STATS(
                      "\t%s = %d",
                      v1393,
                      v1394,
                      v1395,
                      v1396,
                      v1397,
                      v1398,
                      v1399,
                      v1400,
                      v1402,
                      *(unsigned int *)(v1615 + v1401));
                  v1401 += 4;
                  v1402 += 35;
                }
                while ( v1401 != 68 );
                DP_PRINT_STATS("\n", v1393, v1394, v1395, v1396, v1397, v1398, v1399, v1400);
                v1411 = 0;
                v1412 = "HE OFDMA MCS 0 (BPSK 1/2)     ";
                do
                {
                  if ( v1412[34] )
                    DP_PRINT_STATS(
                      "\t%s = %d",
                      v1403,
                      v1404,
                      v1405,
                      v1406,
                      v1407,
                      v1408,
                      v1409,
                      v1410,
                      v1412,
                      *(unsigned int *)(v204 + v1411));
                  v1411 += 4;
                  v1412 += 35;
                }
                while ( v1411 != 68 );
                DP_PRINT_STATS("\n", v1403, v1404, v1405, v1406, v1407, v1408, v1409, v1410);
                dp_print_nss((char *)v1623, (_DWORD *)v10 + 900);
                DP_PRINT_STATS("MSDU Count", v1413, v1414, v1415, v1416, v1417, v1418, v1419, v1420);
                DP_PRINT_STATS("\tNSS(1-8) = %s", v1421, v1422, v1423, v1424, v1425, v1426, v1427, v1428, v1623);
                DP_PRINT_STATS("reception mode SU", v1429, v1430, v1431, v1432, v1433, v1434, v1435, v1436);
                dp_print_nss((char *)v1623, (_DWORD *)v10 + 908);
                DP_PRINT_STATS("\tPPDU Count", v1437, v1438, v1439, v1440, v1441, v1442, v1443, v1444);
                DP_PRINT_STATS("\tNSS(1-8) = %s", v1445, v1446, v1447, v1448, v1449, v1450, v1451, v1452, v1623);
                DP_PRINT_STATS(
                  "\tMPDU OK = %u, MPDU Fail = %u",
                  v1453,
                  v1454,
                  v1455,
                  v1456,
                  v1457,
                  v1458,
                  v1459,
                  v1460,
                  *((unsigned int *)v10 + 916),
                  *((unsigned int *)v10 + 917));
                DP_PRINT_STATS(
                  "reception mode %s",
                  v1461,
                  v1462,
                  v1463,
                  v1464,
                  v1465,
                  v1466,
                  v1467,
                  v1468,
                  mu_reception_mode[0]);
                dp_print_nss((char *)v1623, (_DWORD *)v10 + 939);
                DP_PRINT_STATS("\tPPDU Count", v1469, v1470, v1471, v1472, v1473, v1474, v1475, v1476);
                DP_PRINT_STATS("\tNSS(1-8) = %s", v1477, v1478, v1479, v1480, v1481, v1482, v1483, v1484, v1623);
                DP_PRINT_STATS(
                  "\tMPDU OK = %u, MPDU Fail = %u",
                  v1485,
                  v1486,
                  v1487,
                  v1488,
                  v1489,
                  v1490,
                  v1491,
                  v1492,
                  *((unsigned int *)v10 + 947),
                  *((unsigned int *)v10 + 948));
                DP_PRINT_STATS(
                  "reception mode %s",
                  v1493,
                  v1494,
                  v1495,
                  v1496,
                  v1497,
                  v1498,
                  v1499,
                  v1500,
                  off_16240[0]);
                dp_print_nss((char *)v1623, (_DWORD *)v10 + 966);
                DP_PRINT_STATS("\tPPDU Count", v1501, v1502, v1503, v1504, v1505, v1506, v1507, v1508);
                DP_PRINT_STATS("\tNSS(1-8) = %s", v1509, v1510, v1511, v1512, v1513, v1514, v1515, v1516, v1623);
                DP_PRINT_STATS(
                  "\tMPDU OK = %u, MPDU Fail = %u",
                  v1517,
                  v1518,
                  v1519,
                  v1520,
                  v1521,
                  v1522,
                  v1523,
                  v1524,
                  *((unsigned int *)v10 + 974),
                  *((unsigned int *)v10 + 975));
                DP_PRINT_STATS("Aggregation:", v1525, v1526, v1527, v1528, v1529, v1530, v1531, v1532);
                DP_PRINT_STATS(
                  "   Msdu's Part of Ampdu = %u",
                  v1533,
                  v1534,
                  v1535,
                  v1536,
                  v1537,
                  v1538,
                  v1539,
                  v1540,
                  *((unsigned int *)v10 + 1002));
                DP_PRINT_STATS(
                  "   Msdu's With No Mpdu Level Aggregation = %u",
                  v1541,
                  v1542,
                  v1543,
                  v1544,
                  v1545,
                  v1546,
                  v1547,
                  v1548,
                  *((unsigned int *)v10 + 1001));
                DP_PRINT_STATS(
                  "   Msdu's Part of Amsdu = %u",
                  v1549,
                  v1550,
                  v1551,
                  v1552,
                  v1553,
                  v1554,
                  v1555,
                  v1556,
                  *((unsigned int *)v10 + 1004));
                DP_PRINT_STATS(
                  "   Msdu's With No Msdu Level Aggregation = %u",
                  v1557,
                  v1558,
                  v1559,
                  v1560,
                  v1561,
                  v1562,
                  v1563,
                  v1564,
                  *((unsigned int *)v10 + 1003));
                DP_PRINT_STATS(
                  "MEC Packet Drop = %llu",
                  v1565,
                  v1566,
                  v1567,
                  v1568,
                  v1569,
                  v1570,
                  v1571,
                  v1572,
                  *((_QWORD *)v10 + 377));
                DP_PRINT_STATS(
                  "MEC Byte Drop = %llu",
                  v1573,
                  v1574,
                  v1575,
                  v1576,
                  v1577,
                  v1578,
                  v1579,
                  v1580,
                  *((_QWORD *)v10 + 378));
                DP_PRINT_STATS(
                  "Multipass Rx Packet Drop = %u",
                  v1581,
                  v1582,
                  v1583,
                  v1584,
                  v1585,
                  v1586,
                  v1587,
                  v1588,
                  *((unsigned int *)v10 + 1031));
                DP_PRINT_STATS(
                  "Peer Unauth Rx Packet Drop = %u",
                  v1589,
                  v1590,
                  v1591,
                  v1592,
                  v1593,
                  v1594,
                  v1595,
                  v1596,
                  *((unsigned int *)v10 + 1032));
                DP_PRINT_STATS(
                  "Policy Check Rx Packet Drop = %u",
                  v1597,
                  v1598,
                  v1599,
                  v1600,
                  v1601,
                  v1602,
                  v1603,
                  v1604,
                  *((unsigned int *)v10 + 1033));
                if ( v1616 )
                {
                  v1605 = *(void (__fastcall **)(unsigned __int8 *, __int64))(*(_QWORD *)(v1616 + 8) + 1608LL);
                  if ( v1605 )
                  {
                    if ( *((_DWORD *)v1605 - 1) != -1009236478 )
                      __break(0x8228u);
                    v1605(v10, 1);
                  }
                }
                v36 = v1612;
                v202 += 4544;
                v201 = v1614 + 1;
                v33 += 4544;
                v203 = v1615 + 4544;
                v204 += 4544;
                if ( v1614 + 1 == v1613 )
                  goto LABEL_92;
                goto LABEL_55;
              }
            }
            else
            {
LABEL_92:
              v13 = v1610;
              v11 = v1611;
              v78 = (unsigned __int8)v1621;
              v32 = v1609;
              if ( !(_BYTE)v1621 )
                goto LABEL_105;
              if ( v1617 )
              {
                dp_peer_unref_delete(v1617, 8u, v88, v89, v90, v91, v92, v93, v94, v95);
                v78 = (unsigned __int8)v1621;
              }
              v1617 = 0;
              if ( (unsigned int)v78 < 2 )
                goto LABEL_105;
              if ( v1618 )
              {
                dp_peer_unref_delete(v1618, 8u, v88, v89, v90, v91, v92, v93, v94, v95);
                v78 = (unsigned __int8)v1621;
              }
              v1618 = 0;
              if ( (unsigned int)v78 < 3 )
                goto LABEL_105;
              if ( v1619 )
              {
                dp_peer_unref_delete(v1619, 8u, v88, v89, v90, v91, v92, v93, v94, v95);
                v78 = (unsigned __int8)v1621;
              }
              v1619 = 0;
              if ( (unsigned int)v78 < 4 )
                goto LABEL_105;
              if ( v1620 )
              {
                dp_peer_unref_delete(v1620, 8u, v88, v89, v90, v91, v92, v93, v94, v95);
                v78 = (unsigned __int8)v1621;
              }
              v1620 = 0;
              if ( (unsigned int)v78 <= 4 )
              {
LABEL_105:
                LOBYTE(v1621) = 0;
                v57 = v36;
                goto LABEL_106;
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x45u,
              2u,
              "%s: malloc failed, vdev_id: %u, ML peer_id: %u",
              v80,
              v81,
              v82,
              v83,
              v84,
              v85,
              v86,
              v87,
              "dp_print_per_link_stats",
              (unsigned __int8)v10,
              *(unsigned __int16 *)(v33 + 16));
            v13 = v1610;
            v11 = v1611;
            v78 = (unsigned __int8)v1621;
            v32 = v1609;
            if ( !(_BYTE)v1621 )
              goto LABEL_123;
            if ( v1617 )
            {
              dp_peer_unref_delete(v1617, 8u, v67, v68, v69, v70, v71, v72, v73, v74);
              v78 = (unsigned __int8)v1621;
            }
            v1617 = 0;
            if ( (unsigned int)v78 < 2 )
              goto LABEL_123;
            if ( v1618 )
            {
              dp_peer_unref_delete(v1618, 8u, v67, v68, v69, v70, v71, v72, v73, v74);
              v78 = (unsigned __int8)v1621;
            }
            v1618 = 0;
            if ( (unsigned int)v78 < 3 )
              goto LABEL_123;
            if ( v1619 )
            {
              dp_peer_unref_delete(v1619, 8u, v67, v68, v69, v70, v71, v72, v73, v74);
              v78 = (unsigned __int8)v1621;
            }
            v1619 = 0;
            if ( (unsigned int)v78 < 4 )
              goto LABEL_123;
            if ( v1620 )
            {
              dp_peer_unref_delete(v1620, 8u, v67, v68, v69, v70, v71, v72, v73, v74);
              v78 = (unsigned __int8)v1621;
            }
            v1620 = 0;
            if ( (unsigned int)v78 <= 4 )
            {
LABEL_123:
              LOBYTE(v1621) = 0;
              goto LABEL_107;
            }
          }
          __break(0x5512u);
LABEL_125:
          *(_QWORD *)(v33 + 488) = v78 & 0xFFFFFFFFFFFFFFFELL;
          raw_spin_unlock_bh(v33 + 480);
        }
      }
    }
    v39 = _qdf_mem_malloc(0x11C0u, "dp_print_per_link_stats", 11708);
    if ( v39 )
    {
      v48 = v39;
      dp_get_peer_stats(v32, v39);
      dp_print_peer_stats(v32, v48, v49, v50, v51, v52, v53, v54, v55, v56);
      v57 = v48;
LABEL_106:
      _qdf_mem_free(v57);
    }
    else
    {
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: malloc failed, vdev_id: %u, peer_id: %u",
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        "dp_print_per_link_stats",
        (unsigned __int8)v10,
        *(unsigned __int16 *)(v32 + 16));
    }
LABEL_107:
    dp_peer_unref_delete(v32, 8u, v67, v68, v69, v70, v71, v72, v73, v74);
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Peer is NULL, vdev_id: %u",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "dp_print_per_link_stats",
      (unsigned __int8)v10);
  }
  result = dp_vdev_unref_delete(v11, v13, 8u, v58, v59, v60, v61, v62, v63, v64, v65, v66);
LABEL_109:
  _ReadStatusReg(SP_EL0);
  return result;
}
