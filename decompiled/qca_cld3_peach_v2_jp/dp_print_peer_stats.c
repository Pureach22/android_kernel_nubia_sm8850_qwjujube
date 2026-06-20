__int64 __fastcall dp_print_peer_stats(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x28
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
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  double v68; // d0
  double v69; // d1
  double v70; // d2
  double v71; // d3
  double v72; // d4
  double v73; // d5
  double v74; // d6
  double v75; // d7
  double v76; // d0
  double v77; // d1
  double v78; // d2
  double v79; // d3
  double v80; // d4
  double v81; // d5
  double v82; // d6
  double v83; // d7
  double v84; // d0
  double v85; // d1
  double v86; // d2
  double v87; // d3
  double v88; // d4
  double v89; // d5
  double v90; // d6
  double v91; // d7
  double v92; // d0
  double v93; // d1
  double v94; // d2
  double v95; // d3
  double v96; // d4
  double v97; // d5
  double v98; // d6
  double v99; // d7
  double v100; // d0
  double v101; // d1
  double v102; // d2
  double v103; // d3
  double v104; // d4
  double v105; // d5
  double v106; // d6
  double v107; // d7
  double v108; // d0
  double v109; // d1
  double v110; // d2
  double v111; // d3
  double v112; // d4
  double v113; // d5
  double v114; // d6
  double v115; // d7
  double v116; // d0
  double v117; // d1
  double v118; // d2
  double v119; // d3
  double v120; // d4
  double v121; // d5
  double v122; // d6
  double v123; // d7
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  double v132; // d0
  double v133; // d1
  double v134; // d2
  double v135; // d3
  double v136; // d4
  double v137; // d5
  double v138; // d6
  double v139; // d7
  double v140; // d0
  double v141; // d1
  double v142; // d2
  double v143; // d3
  double v144; // d4
  double v145; // d5
  double v146; // d6
  double v147; // d7
  double v148; // d0
  double v149; // d1
  double v150; // d2
  double v151; // d3
  double v152; // d4
  double v153; // d5
  double v154; // d6
  double v155; // d7
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
  double v172; // d0
  double v173; // d1
  double v174; // d2
  double v175; // d3
  double v176; // d4
  double v177; // d5
  double v178; // d6
  double v179; // d7
  double v180; // d0
  double v181; // d1
  double v182; // d2
  double v183; // d3
  double v184; // d4
  double v185; // d5
  double v186; // d6
  double v187; // d7
  double v188; // d0
  double v189; // d1
  double v190; // d2
  double v191; // d3
  double v192; // d4
  double v193; // d5
  double v194; // d6
  double v195; // d7
  double v196; // d0
  double v197; // d1
  double v198; // d2
  double v199; // d3
  double v200; // d4
  double v201; // d5
  double v202; // d6
  double v203; // d7
  double v204; // d0
  double v205; // d1
  double v206; // d2
  double v207; // d3
  double v208; // d4
  double v209; // d5
  double v210; // d6
  double v211; // d7
  double v212; // d0
  double v213; // d1
  double v214; // d2
  double v215; // d3
  double v216; // d4
  double v217; // d5
  double v218; // d6
  double v219; // d7
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  double v228; // d0
  double v229; // d1
  double v230; // d2
  double v231; // d3
  double v232; // d4
  double v233; // d5
  double v234; // d6
  double v235; // d7
  unsigned __int64 v236; // x8
  double v237; // d0
  double v238; // d1
  double v239; // d2
  double v240; // d3
  double v241; // d4
  double v242; // d5
  double v243; // d6
  double v244; // d7
  double v245; // d0
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  double v253; // d0
  double v254; // d1
  double v255; // d2
  double v256; // d3
  double v257; // d4
  double v258; // d5
  double v259; // d6
  double v260; // d7
  double v261; // d0
  double v262; // d1
  double v263; // d2
  double v264; // d3
  double v265; // d4
  double v266; // d5
  double v267; // d6
  double v268; // d7
  double v269; // d0
  double v270; // d1
  double v271; // d2
  double v272; // d3
  double v273; // d4
  double v274; // d5
  double v275; // d6
  double v276; // d7
  double v277; // d0
  double v278; // d1
  double v279; // d2
  double v280; // d3
  double v281; // d4
  double v282; // d5
  double v283; // d6
  double v284; // d7
  double v285; // d0
  double v286; // d1
  double v287; // d2
  double v288; // d3
  double v289; // d4
  double v290; // d5
  double v291; // d6
  double v292; // d7
  double v293; // d0
  double v294; // d1
  double v295; // d2
  double v296; // d3
  double v297; // d4
  double v298; // d5
  double v299; // d6
  double v300; // d7
  double v301; // d0
  double v302; // d1
  double v303; // d2
  double v304; // d3
  double v305; // d4
  double v306; // d5
  double v307; // d6
  double v308; // d7
  double v309; // d0
  double v310; // d1
  double v311; // d2
  double v312; // d3
  double v313; // d4
  double v314; // d5
  double v315; // d6
  double v316; // d7
  double v317; // d0
  double v318; // d1
  double v319; // d2
  double v320; // d3
  double v321; // d4
  double v322; // d5
  double v323; // d6
  double v324; // d7
  double v325; // d0
  double v326; // d1
  double v327; // d2
  double v328; // d3
  double v329; // d4
  double v330; // d5
  double v331; // d6
  double v332; // d7
  double v333; // d0
  double v334; // d1
  double v335; // d2
  double v336; // d3
  double v337; // d4
  double v338; // d5
  double v339; // d6
  double v340; // d7
  double v341; // d0
  double v342; // d1
  double v343; // d2
  double v344; // d3
  double v345; // d4
  double v346; // d5
  double v347; // d6
  double v348; // d7
  double v349; // d0
  double v350; // d1
  double v351; // d2
  double v352; // d3
  double v353; // d4
  double v354; // d5
  double v355; // d6
  double v356; // d7
  double v357; // d0
  double v358; // d1
  double v359; // d2
  double v360; // d3
  double v361; // d4
  double v362; // d5
  double v363; // d6
  double v364; // d7
  double v365; // d0
  double v366; // d1
  double v367; // d2
  double v368; // d3
  double v369; // d4
  double v370; // d5
  double v371; // d6
  double v372; // d7
  double v373; // d0
  double v374; // d1
  double v375; // d2
  double v376; // d3
  double v377; // d4
  double v378; // d5
  double v379; // d6
  double v380; // d7
  double v381; // d0
  double v382; // d1
  double v383; // d2
  double v384; // d3
  double v385; // d4
  double v386; // d5
  double v387; // d6
  double v388; // d7
  double v389; // d0
  double v390; // d1
  double v391; // d2
  double v392; // d3
  double v393; // d4
  double v394; // d5
  double v395; // d6
  double v396; // d7
  double v397; // d0
  double v398; // d1
  double v399; // d2
  double v400; // d3
  double v401; // d4
  double v402; // d5
  double v403; // d6
  double v404; // d7
  double v405; // d0
  double v406; // d1
  double v407; // d2
  double v408; // d3
  double v409; // d4
  double v410; // d5
  double v411; // d6
  double v412; // d7
  double v413; // d0
  double v414; // d1
  double v415; // d2
  double v416; // d3
  double v417; // d4
  double v418; // d5
  double v419; // d6
  double v420; // d7
  double v421; // d0
  double v422; // d1
  double v423; // d2
  double v424; // d3
  double v425; // d4
  double v426; // d5
  double v427; // d6
  double v428; // d7
  double v429; // d0
  double v430; // d1
  double v431; // d2
  double v432; // d3
  double v433; // d4
  double v434; // d5
  double v435; // d6
  double v436; // d7
  double v437; // d0
  double v438; // d1
  double v439; // d2
  double v440; // d3
  double v441; // d4
  double v442; // d5
  double v443; // d6
  double v444; // d7
  double v445; // d0
  double v446; // d1
  double v447; // d2
  double v448; // d3
  double v449; // d4
  double v450; // d5
  double v451; // d6
  double v452; // d7
  double v453; // d0
  double v454; // d1
  double v455; // d2
  double v456; // d3
  double v457; // d4
  double v458; // d5
  double v459; // d6
  double v460; // d7
  double v461; // d0
  double v462; // d1
  double v463; // d2
  double v464; // d3
  double v465; // d4
  double v466; // d5
  double v467; // d6
  double v468; // d7
  double v469; // d0
  double v470; // d1
  double v471; // d2
  double v472; // d3
  double v473; // d4
  double v474; // d5
  double v475; // d6
  double v476; // d7
  double v477; // d0
  double v478; // d1
  double v479; // d2
  double v480; // d3
  double v481; // d4
  double v482; // d5
  double v483; // d6
  double v484; // d7
  double v485; // d0
  double v486; // d1
  double v487; // d2
  double v488; // d3
  double v489; // d4
  double v490; // d5
  double v491; // d6
  double v492; // d7
  double v493; // d0
  double v494; // d1
  double v495; // d2
  double v496; // d3
  double v497; // d4
  double v498; // d5
  double v499; // d6
  double v500; // d7
  double v501; // d0
  double v502; // d1
  double v503; // d2
  double v504; // d3
  double v505; // d4
  double v506; // d5
  double v507; // d6
  double v508; // d7
  double v509; // d0
  double v510; // d1
  double v511; // d2
  double v512; // d3
  double v513; // d4
  double v514; // d5
  double v515; // d6
  double v516; // d7
  double v517; // d0
  double v518; // d1
  double v519; // d2
  double v520; // d3
  double v521; // d4
  double v522; // d5
  double v523; // d6
  double v524; // d7
  double v525; // d0
  double v526; // d1
  double v527; // d2
  double v528; // d3
  double v529; // d4
  double v530; // d5
  double v531; // d6
  double v532; // d7
  double v533; // d0
  double v534; // d1
  double v535; // d2
  double v536; // d3
  double v537; // d4
  double v538; // d5
  double v539; // d6
  double v540; // d7
  double v541; // d0
  double v542; // d1
  double v543; // d2
  double v544; // d3
  double v545; // d4
  double v546; // d5
  double v547; // d6
  double v548; // d7
  double v549; // d0
  double v550; // d1
  double v551; // d2
  double v552; // d3
  double v553; // d4
  double v554; // d5
  double v555; // d6
  double v556; // d7
  double v557; // d0
  double v558; // d1
  double v559; // d2
  double v560; // d3
  double v561; // d4
  double v562; // d5
  double v563; // d6
  double v564; // d7
  unsigned __int8 v565; // w24
  double v566; // d0
  double v567; // d1
  double v568; // d2
  double v569; // d3
  double v570; // d4
  double v571; // d5
  double v572; // d6
  double v573; // d7
  unsigned int v574; // w25
  unsigned int v575; // w26
  unsigned __int64 v576; // x27
  int v577; // w0
  double v578; // d0
  double v579; // d1
  double v580; // d2
  double v581; // d3
  double v582; // d4
  double v583; // d5
  double v584; // d6
  double v585; // d7
  bool v586; // cf
  double v587; // d0
  double v588; // d1
  double v589; // d2
  double v590; // d3
  double v591; // d4
  double v592; // d5
  double v593; // d6
  double v594; // d7
  double v595; // d0
  double v596; // d1
  double v597; // d2
  double v598; // d3
  double v599; // d4
  double v600; // d5
  double v601; // d6
  double v602; // d7
  double v603; // d0
  double v604; // d1
  double v605; // d2
  double v606; // d3
  double v607; // d4
  double v608; // d5
  double v609; // d6
  double v610; // d7
  double v611; // d0
  double v612; // d1
  double v613; // d2
  double v614; // d3
  double v615; // d4
  double v616; // d5
  double v617; // d6
  double v618; // d7
  double v619; // d0
  double v620; // d1
  double v621; // d2
  double v622; // d3
  double v623; // d4
  double v624; // d5
  double v625; // d6
  double v626; // d7
  double v627; // d0
  double v628; // d1
  double v629; // d2
  double v630; // d3
  double v631; // d4
  double v632; // d5
  double v633; // d6
  double v634; // d7
  double v635; // d0
  double v636; // d1
  double v637; // d2
  double v638; // d3
  double v639; // d4
  double v640; // d5
  double v641; // d6
  double v642; // d7
  double v643; // d0
  double v644; // d1
  double v645; // d2
  double v646; // d3
  double v647; // d4
  double v648; // d5
  double v649; // d6
  double v650; // d7
  double v651; // d0
  double v652; // d1
  double v653; // d2
  double v654; // d3
  double v655; // d4
  double v656; // d5
  double v657; // d6
  double v658; // d7
  double v659; // d0
  double v660; // d1
  double v661; // d2
  double v662; // d3
  double v663; // d4
  double v664; // d5
  double v665; // d6
  double v666; // d7
  double v667; // d0
  double v668; // d1
  double v669; // d2
  double v670; // d3
  double v671; // d4
  double v672; // d5
  double v673; // d6
  double v674; // d7
  double v675; // d0
  double v676; // d1
  double v677; // d2
  double v678; // d3
  double v679; // d4
  double v680; // d5
  double v681; // d6
  double v682; // d7
  double v683; // d0
  double v684; // d1
  double v685; // d2
  double v686; // d3
  double v687; // d4
  double v688; // d5
  double v689; // d6
  double v690; // d7
  double v691; // d0
  double v692; // d1
  double v693; // d2
  double v694; // d3
  double v695; // d4
  double v696; // d5
  double v697; // d6
  double v698; // d7
  double v699; // d0
  double v700; // d1
  double v701; // d2
  double v702; // d3
  double v703; // d4
  double v704; // d5
  double v705; // d6
  double v706; // d7
  double v707; // d0
  double v708; // d1
  double v709; // d2
  double v710; // d3
  double v711; // d4
  double v712; // d5
  double v713; // d6
  double v714; // d7
  double v715; // d0
  double v716; // d1
  double v717; // d2
  double v718; // d3
  double v719; // d4
  double v720; // d5
  double v721; // d6
  double v722; // d7
  double v723; // d0
  double v724; // d1
  double v725; // d2
  double v726; // d3
  double v727; // d4
  double v728; // d5
  double v729; // d6
  double v730; // d7
  double v731; // d0
  double v732; // d1
  double v733; // d2
  double v734; // d3
  double v735; // d4
  double v736; // d5
  double v737; // d6
  double v738; // d7
  double v739; // d0
  double v740; // d1
  double v741; // d2
  double v742; // d3
  double v743; // d4
  double v744; // d5
  double v745; // d6
  double v746; // d7
  double v747; // d0
  double v748; // d1
  double v749; // d2
  double v750; // d3
  double v751; // d4
  double v752; // d5
  double v753; // d6
  double v754; // d7
  double v755; // d0
  double v756; // d1
  double v757; // d2
  double v758; // d3
  double v759; // d4
  double v760; // d5
  double v761; // d6
  double v762; // d7
  double v763; // d0
  double v764; // d1
  double v765; // d2
  double v766; // d3
  double v767; // d4
  double v768; // d5
  double v769; // d6
  double v770; // d7
  _DWORD *v771; // x8
  double v772; // d0
  double v773; // d1
  double v774; // d2
  double v775; // d3
  double v776; // d4
  double v777; // d5
  double v778; // d6
  double v779; // d7
  double v780; // d0
  double v781; // d1
  double v782; // d2
  double v783; // d3
  double v784; // d4
  double v785; // d5
  double v786; // d6
  double v787; // d7
  double v788; // d0
  double v789; // d1
  double v790; // d2
  double v791; // d3
  double v792; // d4
  double v793; // d5
  double v794; // d6
  double v795; // d7
  double v796; // d0
  double v797; // d1
  double v798; // d2
  double v799; // d3
  double v800; // d4
  double v801; // d5
  double v802; // d6
  double v803; // d7
  double v804; // d0
  double v805; // d1
  double v806; // d2
  double v807; // d3
  double v808; // d4
  double v809; // d5
  double v810; // d6
  double v811; // d7
  double v812; // d0
  double v813; // d1
  double v814; // d2
  double v815; // d3
  double v816; // d4
  double v817; // d5
  double v818; // d6
  double v819; // d7
  char v820; // w24
  double v821; // d0
  double v822; // d1
  double v823; // d2
  double v824; // d3
  double v825; // d4
  double v826; // d5
  double v827; // d6
  double v828; // d7
  double v829; // d0
  double v830; // d1
  double v831; // d2
  double v832; // d3
  double v833; // d4
  double v834; // d5
  double v835; // d6
  double v836; // d7
  double v837; // d0
  double v838; // d1
  double v839; // d2
  double v840; // d3
  double v841; // d4
  double v842; // d5
  double v843; // d6
  double v844; // d7
  double v845; // d0
  double v846; // d1
  double v847; // d2
  double v848; // d3
  double v849; // d4
  double v850; // d5
  double v851; // d6
  double v852; // d7
  double v853; // d0
  double v854; // d1
  double v855; // d2
  double v856; // d3
  double v857; // d4
  double v858; // d5
  double v859; // d6
  double v860; // d7
  double v861; // d0
  double v862; // d1
  double v863; // d2
  double v864; // d3
  double v865; // d4
  double v866; // d5
  double v867; // d6
  double v868; // d7
  double v869; // d0
  double v870; // d1
  double v871; // d2
  double v872; // d3
  double v873; // d4
  double v874; // d5
  double v875; // d6
  double v876; // d7
  double v877; // d0
  double v878; // d1
  double v879; // d2
  double v880; // d3
  double v881; // d4
  double v882; // d5
  double v883; // d6
  double v884; // d7
  double v885; // d0
  double v886; // d1
  double v887; // d2
  double v888; // d3
  double v889; // d4
  double v890; // d5
  double v891; // d6
  double v892; // d7
  double v893; // d0
  double v894; // d1
  double v895; // d2
  double v896; // d3
  double v897; // d4
  double v898; // d5
  double v899; // d6
  double v900; // d7
  double v901; // d0
  double v902; // d1
  double v903; // d2
  double v904; // d3
  double v905; // d4
  double v906; // d5
  double v907; // d6
  double v908; // d7
  double v909; // d0
  double v910; // d1
  double v911; // d2
  double v912; // d3
  double v913; // d4
  double v914; // d5
  double v915; // d6
  double v916; // d7
  double v917; // d0
  double v918; // d1
  double v919; // d2
  double v920; // d3
  double v921; // d4
  double v922; // d5
  double v923; // d6
  double v924; // d7
  double v925; // d0
  double v926; // d1
  double v927; // d2
  double v928; // d3
  double v929; // d4
  double v930; // d5
  double v931; // d6
  double v932; // d7
  double v933; // d0
  double v934; // d1
  double v935; // d2
  double v936; // d3
  double v937; // d4
  double v938; // d5
  double v939; // d6
  double v940; // d7
  double v941; // d0
  double v942; // d1
  double v943; // d2
  double v944; // d3
  double v945; // d4
  double v946; // d5
  double v947; // d6
  double v948; // d7
  double v949; // d0
  double v950; // d1
  double v951; // d2
  double v952; // d3
  double v953; // d4
  double v954; // d5
  double v955; // d6
  double v956; // d7
  double v957; // d0
  double v958; // d1
  double v959; // d2
  double v960; // d3
  double v961; // d4
  double v962; // d5
  double v963; // d6
  double v964; // d7
  double v965; // d0
  double v966; // d1
  double v967; // d2
  double v968; // d3
  double v969; // d4
  double v970; // d5
  double v971; // d6
  double v972; // d7
  double v973; // d0
  double v974; // d1
  double v975; // d2
  double v976; // d3
  double v977; // d4
  double v978; // d5
  double v979; // d6
  double v980; // d7
  double v981; // d0
  double v982; // d1
  double v983; // d2
  double v984; // d3
  double v985; // d4
  double v986; // d5
  double v987; // d6
  double v988; // d7
  double v989; // d0
  double v990; // d1
  double v991; // d2
  double v992; // d3
  double v993; // d4
  double v994; // d5
  double v995; // d6
  double v996; // d7
  double v997; // d0
  double v998; // d1
  double v999; // d2
  double v1000; // d3
  double v1001; // d4
  double v1002; // d5
  double v1003; // d6
  double v1004; // d7
  double v1005; // d0
  double v1006; // d1
  double v1007; // d2
  double v1008; // d3
  double v1009; // d4
  double v1010; // d5
  double v1011; // d6
  double v1012; // d7
  double v1013; // d0
  double v1014; // d1
  double v1015; // d2
  double v1016; // d3
  double v1017; // d4
  double v1018; // d5
  double v1019; // d6
  double v1020; // d7
  double v1021; // d0
  double v1022; // d1
  double v1023; // d2
  double v1024; // d3
  double v1025; // d4
  double v1026; // d5
  double v1027; // d6
  double v1028; // d7
  double v1029; // d0
  double v1030; // d1
  double v1031; // d2
  double v1032; // d3
  double v1033; // d4
  double v1034; // d5
  double v1035; // d6
  double v1036; // d7
  double v1037; // d0
  double v1038; // d1
  double v1039; // d2
  double v1040; // d3
  double v1041; // d4
  double v1042; // d5
  double v1043; // d6
  double v1044; // d7
  double v1045; // d0
  double v1046; // d1
  double v1047; // d2
  double v1048; // d3
  double v1049; // d4
  double v1050; // d5
  double v1051; // d6
  double v1052; // d7
  double v1053; // d0
  double v1054; // d1
  double v1055; // d2
  double v1056; // d3
  double v1057; // d4
  double v1058; // d5
  double v1059; // d6
  double v1060; // d7
  double v1061; // d0
  double v1062; // d1
  double v1063; // d2
  double v1064; // d3
  double v1065; // d4
  double v1066; // d5
  double v1067; // d6
  double v1068; // d7
  double v1069; // d0
  double v1070; // d1
  double v1071; // d2
  double v1072; // d3
  double v1073; // d4
  double v1074; // d5
  double v1075; // d6
  double v1076; // d7
  double v1077; // d0
  double v1078; // d1
  double v1079; // d2
  double v1080; // d3
  double v1081; // d4
  double v1082; // d5
  double v1083; // d6
  double v1084; // d7
  double v1085; // d0
  double v1086; // d1
  double v1087; // d2
  double v1088; // d3
  double v1089; // d4
  double v1090; // d5
  double v1091; // d6
  double v1092; // d7
  double v1093; // d0
  double v1094; // d1
  double v1095; // d2
  double v1096; // d3
  double v1097; // d4
  double v1098; // d5
  double v1099; // d6
  double v1100; // d7
  double v1101; // d0
  double v1102; // d1
  double v1103; // d2
  double v1104; // d3
  double v1105; // d4
  double v1106; // d5
  double v1107; // d6
  double v1108; // d7
  double v1109; // d0
  double v1110; // d1
  double v1111; // d2
  double v1112; // d3
  double v1113; // d4
  double v1114; // d5
  double v1115; // d6
  double v1116; // d7
  double v1117; // d0
  double v1118; // d1
  double v1119; // d2
  double v1120; // d3
  double v1121; // d4
  double v1122; // d5
  double v1123; // d6
  double v1124; // d7
  double v1125; // d0
  double v1126; // d1
  double v1127; // d2
  double v1128; // d3
  double v1129; // d4
  double v1130; // d5
  double v1131; // d6
  double v1132; // d7
  double v1133; // d0
  double v1134; // d1
  double v1135; // d2
  double v1136; // d3
  double v1137; // d4
  double v1138; // d5
  double v1139; // d6
  double v1140; // d7
  double v1141; // d0
  double v1142; // d1
  double v1143; // d2
  double v1144; // d3
  double v1145; // d4
  double v1146; // d5
  double v1147; // d6
  double v1148; // d7
  double v1149; // d0
  double v1150; // d1
  double v1151; // d2
  double v1152; // d3
  double v1153; // d4
  double v1154; // d5
  double v1155; // d6
  double v1156; // d7
  double v1157; // d0
  double v1158; // d1
  double v1159; // d2
  double v1160; // d3
  double v1161; // d4
  double v1162; // d5
  double v1163; // d6
  double v1164; // d7
  double v1165; // d0
  double v1166; // d1
  double v1167; // d2
  double v1168; // d3
  double v1169; // d4
  double v1170; // d5
  double v1171; // d6
  double v1172; // d7
  double v1173; // d0
  double v1174; // d1
  double v1175; // d2
  double v1176; // d3
  double v1177; // d4
  double v1178; // d5
  double v1179; // d6
  double v1180; // d7
  double v1181; // d0
  double v1182; // d1
  double v1183; // d2
  double v1184; // d3
  double v1185; // d4
  double v1186; // d5
  double v1187; // d6
  double v1188; // d7
  double v1189; // d0
  double v1190; // d1
  double v1191; // d2
  double v1192; // d3
  double v1193; // d4
  double v1194; // d5
  double v1195; // d6
  double v1196; // d7
  double v1197; // d0
  double v1198; // d1
  double v1199; // d2
  double v1200; // d3
  double v1201; // d4
  double v1202; // d5
  double v1203; // d6
  double v1204; // d7
  double v1205; // d0
  double v1206; // d1
  double v1207; // d2
  double v1208; // d3
  double v1209; // d4
  double v1210; // d5
  double v1211; // d6
  double v1212; // d7
  double v1213; // d0
  double v1214; // d1
  double v1215; // d2
  double v1216; // d3
  double v1217; // d4
  double v1218; // d5
  double v1219; // d6
  double v1220; // d7
  double v1221; // d0
  double v1222; // d1
  double v1223; // d2
  double v1224; // d3
  double v1225; // d4
  double v1226; // d5
  double v1227; // d6
  double v1228; // d7
  double v1229; // d0
  double v1230; // d1
  double v1231; // d2
  double v1232; // d3
  double v1233; // d4
  double v1234; // d5
  double v1235; // d6
  double v1236; // d7
  double v1237; // d0
  double v1238; // d1
  double v1239; // d2
  double v1240; // d3
  double v1241; // d4
  double v1242; // d5
  double v1243; // d6
  double v1244; // d7
  double v1245; // d0
  double v1246; // d1
  double v1247; // d2
  double v1248; // d3
  double v1249; // d4
  double v1250; // d5
  double v1251; // d6
  double v1252; // d7
  double v1253; // d0
  double v1254; // d1
  double v1255; // d2
  double v1256; // d3
  double v1257; // d4
  double v1258; // d5
  double v1259; // d6
  double v1260; // d7
  double v1261; // d0
  double v1262; // d1
  double v1263; // d2
  double v1264; // d3
  double v1265; // d4
  double v1266; // d5
  double v1267; // d6
  double v1268; // d7
  double v1269; // d0
  double v1270; // d1
  double v1271; // d2
  double v1272; // d3
  double v1273; // d4
  double v1274; // d5
  double v1275; // d6
  double v1276; // d7
  double v1277; // d0
  double v1278; // d1
  double v1279; // d2
  double v1280; // d3
  double v1281; // d4
  double v1282; // d5
  double v1283; // d6
  double v1284; // d7
  double v1285; // d0
  double v1286; // d1
  double v1287; // d2
  double v1288; // d3
  double v1289; // d4
  double v1290; // d5
  double v1291; // d6
  double v1292; // d7
  double v1293; // d0
  double v1294; // d1
  double v1295; // d2
  double v1296; // d3
  double v1297; // d4
  double v1298; // d5
  double v1299; // d6
  double v1300; // d7
  double v1301; // d0
  double v1302; // d1
  double v1303; // d2
  double v1304; // d3
  double v1305; // d4
  double v1306; // d5
  double v1307; // d6
  double v1308; // d7
  double v1309; // d0
  double v1310; // d1
  double v1311; // d2
  double v1312; // d3
  double v1313; // d4
  double v1314; // d5
  double v1315; // d6
  double v1316; // d7
  double v1317; // d0
  double v1318; // d1
  double v1319; // d2
  double v1320; // d3
  double v1321; // d4
  double v1322; // d5
  double v1323; // d6
  double v1324; // d7
  double v1325; // d0
  double v1326; // d1
  double v1327; // d2
  double v1328; // d3
  double v1329; // d4
  double v1330; // d5
  double v1331; // d6
  double v1332; // d7
  double v1333; // d0
  double v1334; // d1
  double v1335; // d2
  double v1336; // d3
  double v1337; // d4
  double v1338; // d5
  double v1339; // d6
  double v1340; // d7
  double v1341; // d0
  double v1342; // d1
  double v1343; // d2
  double v1344; // d3
  double v1345; // d4
  double v1346; // d5
  double v1347; // d6
  double v1348; // d7
  double v1349; // d0
  double v1350; // d1
  double v1351; // d2
  double v1352; // d3
  double v1353; // d4
  double v1354; // d5
  double v1355; // d6
  double v1356; // d7
  double v1357; // d0
  double v1358; // d1
  double v1359; // d2
  double v1360; // d3
  double v1361; // d4
  double v1362; // d5
  double v1363; // d6
  double v1364; // d7
  double v1365; // d0
  double v1366; // d1
  double v1367; // d2
  double v1368; // d3
  double v1369; // d4
  double v1370; // d5
  double v1371; // d6
  double v1372; // d7
  double v1373; // d0
  double v1374; // d1
  double v1375; // d2
  double v1376; // d3
  double v1377; // d4
  double v1378; // d5
  double v1379; // d6
  double v1380; // d7
  double v1381; // d0
  double v1382; // d1
  double v1383; // d2
  double v1384; // d3
  double v1385; // d4
  double v1386; // d5
  double v1387; // d6
  double v1388; // d7
  double v1389; // d0
  double v1390; // d1
  double v1391; // d2
  double v1392; // d3
  double v1393; // d4
  double v1394; // d5
  double v1395; // d6
  double v1396; // d7
  double v1397; // d0
  double v1398; // d1
  double v1399; // d2
  double v1400; // d3
  double v1401; // d4
  double v1402; // d5
  double v1403; // d6
  double v1404; // d7
  double v1405; // d0
  double v1406; // d1
  double v1407; // d2
  double v1408; // d3
  double v1409; // d4
  double v1410; // d5
  double v1411; // d6
  double v1412; // d7
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
  __int64 v1493; // x26
  char v1494; // w28
  unsigned int *v1495; // x22
  char *v1496; // x8
  char *v1497; // x8
  char *v1498; // x8
  char *v1499; // x8
  char *v1500; // x8
  char *v1501; // x8
  char *v1502; // x8
  char *v1503; // x8
  char *v1504; // x8
  char *v1505; // x8
  char *v1506; // x8
  char *v1507; // x8
  char *v1508; // x8
  char *v1509; // x8
  double v1510; // d0
  double v1511; // d1
  double v1512; // d2
  double v1513; // d3
  double v1514; // d4
  double v1515; // d5
  double v1516; // d6
  double v1517; // d7
  double v1518; // d0
  double v1519; // d1
  double v1520; // d2
  double v1521; // d3
  double v1522; // d4
  double v1523; // d5
  double v1524; // d6
  double v1525; // d7
  double v1526; // d0
  double v1527; // d1
  double v1528; // d2
  double v1529; // d3
  double v1530; // d4
  double v1531; // d5
  double v1532; // d6
  double v1533; // d7
  double v1534; // d0
  double v1535; // d1
  double v1536; // d2
  double v1537; // d3
  double v1538; // d4
  double v1539; // d5
  double v1540; // d6
  double v1541; // d7
  double v1542; // d0
  double v1543; // d1
  double v1544; // d2
  double v1545; // d3
  double v1546; // d4
  double v1547; // d5
  double v1548; // d6
  double v1549; // d7
  double v1550; // d0
  double v1551; // d1
  double v1552; // d2
  double v1553; // d3
  double v1554; // d4
  double v1555; // d5
  double v1556; // d6
  double v1557; // d7
  double v1558; // d0
  double v1559; // d1
  double v1560; // d2
  double v1561; // d3
  double v1562; // d4
  double v1563; // d5
  double v1564; // d6
  double v1565; // d7
  double v1566; // d0
  double v1567; // d1
  double v1568; // d2
  double v1569; // d3
  double v1570; // d4
  double v1571; // d5
  double v1572; // d6
  double v1573; // d7
  double v1574; // d0
  double v1575; // d1
  double v1576; // d2
  double v1577; // d3
  double v1578; // d4
  double v1579; // d5
  double v1580; // d6
  double v1581; // d7
  double v1582; // d0
  double v1583; // d1
  double v1584; // d2
  double v1585; // d3
  double v1586; // d4
  double v1587; // d5
  double v1588; // d6
  double v1589; // d7
  double v1590; // d0
  double v1591; // d1
  double v1592; // d2
  double v1593; // d3
  double v1594; // d4
  double v1595; // d5
  double v1596; // d6
  double v1597; // d7
  double v1598; // d0
  double v1599; // d1
  double v1600; // d2
  double v1601; // d3
  double v1602; // d4
  double v1603; // d5
  double v1604; // d6
  double v1605; // d7
  double v1606; // d0
  double v1607; // d1
  double v1608; // d2
  double v1609; // d3
  double v1610; // d4
  double v1611; // d5
  double v1612; // d6
  double v1613; // d7
  double v1614; // d0
  double v1615; // d1
  double v1616; // d2
  double v1617; // d3
  double v1618; // d4
  double v1619; // d5
  double v1620; // d6
  double v1621; // d7
  double v1622; // d0
  double v1623; // d1
  double v1624; // d2
  double v1625; // d3
  double v1626; // d4
  double v1627; // d5
  double v1628; // d6
  double v1629; // d7
  double v1630; // d0
  double v1631; // d1
  double v1632; // d2
  double v1633; // d3
  double v1634; // d4
  double v1635; // d5
  double v1636; // d6
  double v1637; // d7
  double v1638; // d0
  double v1639; // d1
  double v1640; // d2
  double v1641; // d3
  double v1642; // d4
  double v1643; // d5
  double v1644; // d6
  double v1645; // d7
  double v1646; // d0
  double v1647; // d1
  double v1648; // d2
  double v1649; // d3
  double v1650; // d4
  double v1651; // d5
  double v1652; // d6
  double v1653; // d7
  double v1654; // d0
  double v1655; // d1
  double v1656; // d2
  double v1657; // d3
  double v1658; // d4
  double v1659; // d5
  double v1660; // d6
  double v1661; // d7
  double v1662; // d0
  double v1663; // d1
  double v1664; // d2
  double v1665; // d3
  double v1666; // d4
  double v1667; // d5
  double v1668; // d6
  double v1669; // d7
  double v1670; // d0
  double v1671; // d1
  double v1672; // d2
  double v1673; // d3
  double v1674; // d4
  double v1675; // d5
  double v1676; // d6
  double v1677; // d7
  double v1678; // d0
  double v1679; // d1
  double v1680; // d2
  double v1681; // d3
  double v1682; // d4
  double v1683; // d5
  double v1684; // d6
  double v1685; // d7
  double v1686; // d0
  double v1687; // d1
  double v1688; // d2
  double v1689; // d3
  double v1690; // d4
  double v1691; // d5
  double v1692; // d6
  double v1693; // d7
  double v1694; // d0
  double v1695; // d1
  double v1696; // d2
  double v1697; // d3
  double v1698; // d4
  double v1699; // d5
  double v1700; // d6
  double v1701; // d7
  double v1702; // d0
  double v1703; // d1
  double v1704; // d2
  double v1705; // d3
  double v1706; // d4
  double v1707; // d5
  double v1708; // d6
  double v1709; // d7
  double v1710; // d0
  double v1711; // d1
  double v1712; // d2
  double v1713; // d3
  double v1714; // d4
  double v1715; // d5
  double v1716; // d6
  double v1717; // d7
  double v1718; // d0
  double v1719; // d1
  double v1720; // d2
  double v1721; // d3
  double v1722; // d4
  double v1723; // d5
  double v1724; // d6
  double v1725; // d7
  double v1726; // d0
  double v1727; // d1
  double v1728; // d2
  double v1729; // d3
  double v1730; // d4
  double v1731; // d5
  double v1732; // d6
  double v1733; // d7
  void (__fastcall *v1734)(__int64, __int64); // x8
  __int64 result; // x0
  __int64 v1736; // [xsp+0h] [xbp-A0h]
  _QWORD v1737[12]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v1738[7]; // [xsp+68h] [xbp-38h] BYREF

  v1738[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 24LL);
  memset(v1738, 0, 48);
  memset(v1737, 0, sizeof(v1737));
  DP_PRINT_STATS("Node Tx Stats:\n", a3, a4, a5, a6, a7, a8, a9, a10);
  DP_PRINT_STATS("Total Packet Completions = %llu", v12, v13, v14, v15, v16, v17, v18, v19, *(_QWORD *)(a2 + 8));
  DP_PRINT_STATS("Total Bytes Completions = %llu", v20, v21, v22, v23, v24, v25, v26, v27, *(_QWORD *)(a2 + 16));
  DP_PRINT_STATS("Success Packets = %llu", v28, v29, v30, v31, v32, v33, v34, v35, *(_QWORD *)(a2 + 88));
  DP_PRINT_STATS("Success Bytes = %llu", v36, v37, v38, v39, v40, v41, v42, v43, *(_QWORD *)(a2 + 96));
  DP_PRINT_STATS(
    "Success Packets in TWT Session = %llu",
    v44,
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    *(_QWORD *)(a2 + 1592));
  DP_PRINT_STATS("Success Bytes in TWT Session = %llu", v52, v53, v54, v55, v56, v57, v58, v59, *(_QWORD *)(a2 + 1600));
  DP_PRINT_STATS("Unicast Success Packets = %llu", v60, v61, v62, v63, v64, v65, v66, v67, *(_QWORD *)(a2 + 24));
  DP_PRINT_STATS("Unicast Success Bytes = %llu", v68, v69, v70, v71, v72, v73, v74, v75, *(_QWORD *)(a2 + 32));
  DP_PRINT_STATS("Multicast Success Packets = %llu", v76, v77, v78, v79, v80, v81, v82, v83, *(_QWORD *)(a2 + 40));
  DP_PRINT_STATS("Multicast Success Bytes = %llu", v84, v85, v86, v87, v88, v89, v90, v91, *(_QWORD *)(a2 + 48));
  DP_PRINT_STATS("Broadcast Success Packets = %llu", v92, v93, v94, v95, v96, v97, v98, v99, *(_QWORD *)(a2 + 56));
  DP_PRINT_STATS("Broadcast Success Bytes = %llu", v100, v101, v102, v103, v104, v105, v106, v107, *(_QWORD *)(a2 + 64));
  DP_PRINT_STATS(
    "Packets Successfully Sent after one or more retry = %d",
    v108,
    v109,
    v110,
    v111,
    v112,
    v113,
    v114,
    v115,
    *(unsigned int *)(a2 + 864));
  DP_PRINT_STATS(
    "Total msdu Packets retries = %d",
    v116,
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    v123,
    *(unsigned int *)(a2 + 868));
  DP_PRINT_STATS(
    "Packets Successfully Sent after more than one retry = %d",
    v124,
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    *(unsigned int *)(a2 + 872));
  DP_PRINT_STATS("Packets Failed = %d", v132, v133, v134, v135, v136, v137, v138, v139, *(unsigned int *)(a2 + 108));
  DP_PRINT_STATS(
    "Packets Failed due to retry threshold breach = %d",
    v140,
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    *(unsigned int *)(a2 + 860));
  DP_PRINT_STATS(
    "mpdu Packets Retries = %u",
    v148,
    v149,
    v150,
    v151,
    v152,
    v153,
    v154,
    v155,
    *(unsigned int *)(a2 + 852));
  DP_PRINT_STATS(
    "Total mpdu packets retries = %u",
    v156,
    v157,
    v158,
    v159,
    v160,
    v161,
    v162,
    v163,
    *(unsigned int *)(a2 + 856));
  DP_PRINT_STATS("Packets In OFDMA = %d", v164, v165, v166, v167, v168, v169, v170, v171, *(unsigned int *)(a2 + 112));
  DP_PRINT_STATS("Packets In STBC = %d", v172, v173, v174, v175, v176, v177, v178, v179, *(unsigned int *)(a2 + 116));
  DP_PRINT_STATS("Packets In LDPC = %d", v180, v181, v182, v183, v184, v185, v186, v187, *(unsigned int *)(a2 + 120));
  DP_PRINT_STATS("Packet Retries = %d", v188, v189, v190, v191, v192, v193, v194, v195, *(unsigned int *)(a2 + 124));
  DP_PRINT_STATS(
    "MSDU's Part of AMSDU = %d",
    v196,
    v197,
    v198,
    v199,
    v200,
    v201,
    v202,
    v203,
    *(unsigned int *)(a2 + 136));
  DP_PRINT_STATS(
    "Msdu's As Part of Ampdu = %d",
    v204,
    v205,
    v206,
    v207,
    v208,
    v209,
    v210,
    v211,
    *(unsigned int *)(a2 + 848));
  DP_PRINT_STATS("Msdu's As Ampdu = %d", v212, v213, v214, v215, v216, v217, v218, v219, *(unsigned int *)(a2 + 844));
  DP_PRINT_STATS("Last Packet RSSI = %d", v220, v221, v222, v223, v224, v225, v226, v227, *(unsigned int *)(a2 + 184));
  v236 = *(unsigned int *)(a2 + 188);
  if ( (v236 & 0x80) != 0 )
    v236 += 255LL;
  DP_PRINT_STATS("Average Packet RSSI = %lu", v228, v229, v230, v231, v232, v233, v234, v235, v236 >> 8);
  DP_PRINT_STATS(
    "Dropped At FW: Removed Pkts = %llu",
    v237,
    v238,
    v239,
    v240,
    v241,
    v242,
    v243,
    v244,
    *(_QWORD *)(a2 + 656));
  DP_PRINT_STATS(
    "Release source not TQM = %u",
    v245,
    v246,
    v247,
    v248,
    v249,
    v250,
    v251,
    v252,
    *(unsigned int *)(a2 + 1624));
  if ( v11 && !(unsigned int)wlan_cfg_get_dp_pdev_nss_enabled(*(_QWORD *)(v11 + 288)) )
    DP_PRINT_STATS(
      "Dropped At FW: Removed bytes = %llu",
      v253,
      v254,
      v255,
      v256,
      v257,
      v258,
      v259,
      v260,
      *(_QWORD *)(a2 + 664));
  DP_PRINT_STATS(
    "Dropped At FW: Removed transmitted = %llu",
    v253,
    v254,
    v255,
    v256,
    v257,
    v258,
    v259,
    v260,
    *(_QWORD *)(a2 + 680));
  DP_PRINT_STATS(
    "Dropped At FW: Removed Untransmitted = %d",
    v261,
    v262,
    v263,
    v264,
    v265,
    v266,
    v267,
    v268,
    *(unsigned int *)(a2 + 672));
  DP_PRINT_STATS(
    "Dropped At FW: removed untransmitted fw_reason1 = %u",
    v269,
    v270,
    v271,
    v272,
    v273,
    v274,
    v275,
    v276,
    *(unsigned int *)(a2 + 700));
  DP_PRINT_STATS(
    "Dropped At FW: removed untransmitted fw_reason2 = %u",
    v277,
    v278,
    v279,
    v280,
    v281,
    v282,
    v283,
    v284,
    *(unsigned int *)(a2 + 704));
  DP_PRINT_STATS(
    "Dropped At FW: removed untransmitted fw_reason3 = %u",
    v285,
    v286,
    v287,
    v288,
    v289,
    v290,
    v291,
    v292,
    *(unsigned int *)(a2 + 708));
  DP_PRINT_STATS(
    "Dropped At FW:removed untransmitted disable queue = %u",
    v293,
    v294,
    v295,
    v296,
    v297,
    v298,
    v299,
    v300,
    *(unsigned int *)(a2 + 712));
  DP_PRINT_STATS(
    "Dropped At FW: removed untransmitted no match = %u",
    v301,
    v302,
    v303,
    v304,
    v305,
    v306,
    v307,
    v308,
    *(unsigned int *)(a2 + 716));
  DP_PRINT_STATS(
    "Dropped due to HW threshold criteria = %u",
    v309,
    v310,
    v311,
    v312,
    v313,
    v314,
    v315,
    v316,
    *(unsigned int *)(a2 + 720));
  DP_PRINT_STATS(
    "Dropped due Link desc not available drop in HW = %u",
    v317,
    v318,
    v319,
    v320,
    v321,
    v322,
    v323,
    v324,
    *(unsigned int *)(a2 + 724));
  DP_PRINT_STATS(
    "Drop bit set or invalid flow = %u",
    v325,
    v326,
    v327,
    v328,
    v329,
    v330,
    v331,
    v332,
    *(unsigned int *)(a2 + 728));
  DP_PRINT_STATS(
    "MCAST vdev drop in HW = %u",
    v333,
    v334,
    v335,
    v336,
    v337,
    v338,
    v339,
    v340,
    *(unsigned int *)(a2 + 732));
  DP_PRINT_STATS("Dropped : Age Out = %d", v341, v342, v343, v344, v345, v346, v347, v348, *(unsigned int *)(a2 + 696));
  DP_PRINT_STATS(
    "Dropped : Invalid Reason = %u",
    v349,
    v350,
    v351,
    v352,
    v353,
    v354,
    v355,
    v356,
    *(unsigned int *)(a2 + 736));
  DP_PRINT_STATS("NAWDS : ", v357, v358, v359, v360, v361, v362, v363, v364);
  DP_PRINT_STATS(
    "Nawds multicast Drop Tx Packet = %d",
    v365,
    v366,
    v367,
    v368,
    v369,
    v370,
    v371,
    v372,
    *(unsigned int *)(a2 + 104));
  DP_PRINT_STATS(
    "\tNawds multicast  Tx Packet Count = %llu",
    v373,
    v374,
    v375,
    v376,
    v377,
    v378,
    v379,
    v380,
    *(_QWORD *)(a2 + 72));
  DP_PRINT_STATS(
    "\tNawds multicast  Tx Packet Bytes = %llu",
    v381,
    v382,
    v383,
    v384,
    v385,
    v386,
    v387,
    v388,
    *(_QWORD *)(a2 + 80));
  DP_PRINT_STATS("PPDU's = %d", v389, v390, v391, v392, v393, v394, v395, v396, *(unsigned int *)(a2 + 880));
  DP_PRINT_STATS(
    "Number of PPDU's with Punctured Preamble = %d",
    v397,
    v398,
    v399,
    v400,
    v401,
    v402,
    v403,
    v404,
    *(unsigned int *)(a2 + 536));
  DP_PRINT_STATS("MPDU's Successful = %d", v405, v406, v407, v408, v409, v410, v411, v412, *(unsigned int *)(a2 + 884));
  DP_PRINT_STATS("MPDU's Tried = %d", v413, v414, v415, v416, v417, v418, v419, v420, *(unsigned int *)(a2 + 888));
  DP_PRINT_STATS("Rate Info:", v421, v422, v423, v424, v425, v426, v427, v428);
  dp_print_common_rates_info(a2 + 216, v429, v430, v431, v432, v433, v434, v435, v436);
  DP_PRINT_STATS(
    "SGI = 0.8us %d 0.4us %d 1.6us %d 3.2us %d",
    v437,
    v438,
    v439,
    v440,
    v441,
    v442,
    v443,
    v444,
    *(unsigned int *)(a2 + 516),
    *(unsigned int *)(a2 + 520),
    *(unsigned int *)(a2 + 524),
    *(unsigned int *)(a2 + 528));
  DP_PRINT_STATS("Wireless Mutlimedia ", v445, v446, v447, v448, v449, v450, v451, v452);
  DP_PRINT_STATS("\t Best effort = %d", v453, v454, v455, v456, v457, v458, v459, v460, *(unsigned int *)(a2 + 604));
  DP_PRINT_STATS("\t Background= %d", v461, v462, v463, v464, v465, v466, v467, v468, *(unsigned int *)(a2 + 608));
  DP_PRINT_STATS("\t Video = %d", v469, v470, v471, v472, v473, v474, v475, v476, *(unsigned int *)(a2 + 612));
  DP_PRINT_STATS("\t Voice = %d", v477, v478, v479, v480, v481, v482, v483, v484, *(unsigned int *)(a2 + 616));
  DP_PRINT_STATS("Excess Retries per AC ", v485, v486, v487, v488, v489, v490, v491, v492);
  DP_PRINT_STATS("\t Best effort = %d", v493, v494, v495, v496, v497, v498, v499, v500, *(unsigned int *)(a2 + 620));
  DP_PRINT_STATS("\t Background= %d", v501, v502, v503, v504, v505, v506, v507, v508, *(unsigned int *)(a2 + 624));
  DP_PRINT_STATS("\t Video = %d", v509, v510, v511, v512, v513, v514, v515, v516, *(unsigned int *)(a2 + 628));
  DP_PRINT_STATS("\t Voice = %d", v517, v518, v519, v520, v521, v522, v523, v524, *(unsigned int *)(a2 + 632));
  dp_print_nss(v1738, a2 + 540);
  DP_PRINT_STATS("NSS(1-8) = %s", v525, v526, v527, v528, v529, v530, v531, v532, v1738);
  DP_PRINT_STATS("Transmit Type :", v533, v534, v535, v536, v537, v538, v539, v540);
  DP_PRINT_STATS(
    "MSDUs Success: SU %d, MU_MIMO %d, MU_OFDMA %d, MU_MIMO_OFDMA %d",
    v541,
    v542,
    v543,
    v544,
    v545,
    v546,
    v547,
    v548,
    *(unsigned int *)(a2 + 892),
    *(unsigned int *)(a2 + 904),
    *(unsigned int *)(a2 + 916),
    *(unsigned int *)(a2 + 928));
  DP_PRINT_STATS(
    "MPDUs Success: SU %d, MU_MIMO %d, MU_OFDMA %d, MU_MIMO_OFDMA %d",
    v549,
    v550,
    v551,
    v552,
    v553,
    v554,
    v555,
    v556,
    *(unsigned int *)(a2 + 896),
    *(unsigned int *)(a2 + 908),
    *(unsigned int *)(a2 + 920),
    *(unsigned int *)(a2 + 932));
  DP_PRINT_STATS(
    "MPDUs Tried: SU %d, MU_MIMO %d, MU_OFDMA %d, MU_MIMO_OFDMA %d",
    v557,
    v558,
    v559,
    v560,
    v561,
    v562,
    v563,
    v564,
    *(unsigned int *)(a2 + 900),
    *(unsigned int *)(a2 + 912),
    *(unsigned int *)(a2 + 924),
    *(unsigned int *)(a2 + 936));
  v565 = 0;
  do
  {
    v574 = 0;
    v575 = 0;
    v576 = v565;
    do
    {
      if ( v575 > 0x60 )
        __break(0x5512u);
      v577 = snprintf((char *)v1737 + v575, 96 - v575, " %d", *(_DWORD *)(a2 + 4 * v576 + 1000));
      v565 = v576 + 1;
      if ( v574 > 0xE )
        break;
      v586 = v576 >= 0x3F;
      v575 += v577;
      ++v574;
      ++v576;
    }
    while ( !v586 );
    DP_PRINT_STATS(
      "User position list for GID %02d->%d: [%s]",
      v578,
      v579,
      v580,
      v581,
      v582,
      v583,
      v584,
      v585,
      (unsigned int)v565 - 16,
      (unsigned int)v565 - 1,
      v1737);
  }
  while ( (unsigned __int8)(v565 - 1) < 0x3Fu );
  DP_PRINT_STATS(
    "Last Packet RU index [%d], Size [%d]",
    v566,
    v567,
    v568,
    v569,
    v570,
    v571,
    v572,
    v573,
    *(unsigned int *)(a2 + 1256),
    *(unsigned int *)(a2 + 1260));
  DP_PRINT_STATS("Aggregation:", v587, v588, v589, v590, v591, v592, v593, v594);
  DP_PRINT_STATS(
    "Number of Msdu's Part of Amsdu = %d",
    v595,
    v596,
    v597,
    v598,
    v599,
    v600,
    v601,
    v602,
    *(unsigned int *)(a2 + 136));
  DP_PRINT_STATS(
    "Number of Msdu's With No Msdu Level Aggregation = %d",
    v603,
    v604,
    v605,
    v606,
    v607,
    v608,
    v609,
    v610,
    *(unsigned int *)(a2 + 132));
  DP_PRINT_STATS("Bytes and Packets transmitted  in last one sec:", v611, v612, v613, v614, v615, v616, v617, v618);
  DP_PRINT_STATS(
    "\tBytes transmitted in last sec: %d",
    v619,
    v620,
    v621,
    v622,
    v623,
    v624,
    v625,
    v626,
    *(unsigned int *)(a2 + 200));
  DP_PRINT_STATS(
    "\tData transmitted in last sec: %d",
    v627,
    v628,
    v629,
    v630,
    v631,
    v632,
    v633,
    v634,
    *(unsigned int *)(a2 + 204));
  DP_PRINT_STATS(
    "EAPOL Tx comp Success = %d",
    v635,
    v636,
    v637,
    v638,
    v639,
    v640,
    v641,
    v642,
    *(unsigned int *)(a2 + 1724));
  DP_PRINT_STATS("EAPOL Tx comp Failures:", v643, v644, v645, v646, v647, v648, v649, v650);
  DP_PRINT_STATS(
    "\tFail reason:DROP = %d",
    v651,
    v652,
    v653,
    v654,
    v655,
    v656,
    v657,
    v658,
    *(unsigned int *)(a2 + 1728));
  DP_PRINT_STATS("\tFail reason:TTL = %d", v659, v660, v661, v662, v663, v664, v665, v666, *(unsigned int *)(a2 + 1732));
  DP_PRINT_STATS(
    "\tFail reason:REINJECT = %d",
    v667,
    v668,
    v669,
    v670,
    v671,
    v672,
    v673,
    v674,
    *(unsigned int *)(a2 + 1736));
  DP_PRINT_STATS(
    "\tFail reason:INSPECT = %d",
    v675,
    v676,
    v677,
    v678,
    v679,
    v680,
    v681,
    v682,
    *(unsigned int *)(a2 + 1740));
  DP_PRINT_STATS(
    "\tFail reason:MEC NOTIFY = %d",
    v683,
    v684,
    v685,
    v686,
    v687,
    v688,
    v689,
    v690,
    *(unsigned int *)(a2 + 1744));
  DP_PRINT_STATS(
    "\tFail reason:VDEVID MISMATCH = %d",
    v691,
    v692,
    v693,
    v694,
    v695,
    v696,
    v697,
    v698,
    *(unsigned int *)(a2 + 1748));
  DP_PRINT_STATS(
    "Rekey EAPOL Tx comp Success = %d",
    v699,
    v700,
    v701,
    v702,
    v703,
    v704,
    v705,
    v706,
    *(unsigned int *)(a2 + 1752));
  DP_PRINT_STATS("Rekey EAPOL Tx comp Failures:", v707, v708, v709, v710, v711, v712, v713, v714);
  DP_PRINT_STATS(
    "\tFail reason:DROP = %d",
    v715,
    v716,
    v717,
    v718,
    v719,
    v720,
    v721,
    v722,
    *(unsigned int *)(a2 + 1756));
  DP_PRINT_STATS("\tFail reason:TTL = %d", v723, v724, v725, v726, v727, v728, v729, v730, *(unsigned int *)(a2 + 1760));
  DP_PRINT_STATS(
    "\tFail reason:REINJECT = %d",
    v731,
    v732,
    v733,
    v734,
    v735,
    v736,
    v737,
    v738,
    *(unsigned int *)(a2 + 1764));
  DP_PRINT_STATS(
    "\tFail reason:INSPECT = %d",
    v739,
    v740,
    v741,
    v742,
    v743,
    v744,
    v745,
    v746,
    *(unsigned int *)(a2 + 1768));
  DP_PRINT_STATS(
    "\tFail reason:MEC NOTIFY = %d",
    v747,
    v748,
    v749,
    v750,
    v751,
    v752,
    v753,
    v754,
    *(unsigned int *)(a2 + 1772));
  DP_PRINT_STATS(
    "\tFail reason:VDEVID MISMATCH = %d",
    v755,
    v756,
    v757,
    v758,
    v759,
    v760,
    v761,
    v762,
    *(unsigned int *)(a2 + 1776));
  if ( v11 )
  {
    v771 = *(_DWORD **)(*(_QWORD *)(v11 + 8) + 1560LL);
    if ( v771 )
    {
      if ( *(v771 - 1) != -1009236478 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v771)(a2, 0);
    }
  }
  DP_PRINT_STATS("Tx PPDU Duration: %llu", v763, v764, v765, v766, v767, v768, v769, v770, *(_QWORD *)(a2 + 2296), v11);
  DP_PRINT_STATS("Node Rx Stats:", v772, v773, v774, v775, v776, v777, v778, v779);
  DP_PRINT_STATS("Packets Sent To Stack = %llu", v780, v781, v782, v783, v784, v785, v786, v787, *(_QWORD *)(a2 + 2600));
  DP_PRINT_STATS("Bytes Sent To Stack = %llu", v788, v789, v790, v791, v792, v793, v794, v795, *(_QWORD *)(a2 + 2608));
  DP_PRINT_STATS("Ring Id = %d", v796, v797, v798, v799, v800, v801, v802, v803, 0);
  DP_PRINT_STATS("\tPackets Received = %llu", v804, v805, v806, v807, v808, v809, v810, v811, *(_QWORD *)(a2 + 2320));
  DP_PRINT_STATS("\tBytes Received = %llu", v812, v813, v814, v815, v816, v817, v818, v819, *(_QWORD *)(a2 + 2328));
  v820 = 1;
  DP_PRINT_STATS("Ring Id = %d", v821, v822, v823, v824, v825, v826, v827, v828, 1);
  DP_PRINT_STATS("\tPackets Received = %llu", v829, v830, v831, v832, v833, v834, v835, v836, *(_QWORD *)(a2 + 2336));
  DP_PRINT_STATS("\tBytes Received = %llu", v837, v838, v839, v840, v841, v842, v843, v844, *(_QWORD *)(a2 + 2344));
  DP_PRINT_STATS("Ring Id = %d", v845, v846, v847, v848, v849, v850, v851, v852, 2);
  DP_PRINT_STATS("\tPackets Received = %llu", v853, v854, v855, v856, v857, v858, v859, v860, *(_QWORD *)(a2 + 2352));
  DP_PRINT_STATS("\tBytes Received = %llu", v861, v862, v863, v864, v865, v866, v867, v868, *(_QWORD *)(a2 + 2360));
  DP_PRINT_STATS("Ring Id = %d", v869, v870, v871, v872, v873, v874, v875, v876, 3);
  DP_PRINT_STATS("\tPackets Received = %llu", v877, v878, v879, v880, v881, v882, v883, v884, *(_QWORD *)(a2 + 2368));
  DP_PRINT_STATS("\tBytes Received = %llu", v885, v886, v887, v888, v889, v890, v891, v892, *(_QWORD *)(a2 + 2376));
  DP_PRINT_STATS("Ring Id = %d", v893, v894, v895, v896, v897, v898, v899, v900, 4);
  DP_PRINT_STATS("\tPackets Received = %llu", v901, v902, v903, v904, v905, v906, v907, v908, *(_QWORD *)(a2 + 2384));
  DP_PRINT_STATS("\tBytes Received = %llu", v909, v910, v911, v912, v913, v914, v915, v916, *(_QWORD *)(a2 + 2392));
  DP_PRINT_STATS("Ring Id = %d", v917, v918, v919, v920, v921, v922, v923, v924, 5);
  DP_PRINT_STATS("\tPackets Received = %llu", v925, v926, v927, v928, v929, v930, v931, v932, *(_QWORD *)(a2 + 2400));
  DP_PRINT_STATS("\tBytes Received = %llu", v933, v934, v935, v936, v937, v938, v939, v940, *(_QWORD *)(a2 + 2408));
  DP_PRINT_STATS("Ring Id = %d", v941, v942, v943, v944, v945, v946, v947, v948, 6);
  DP_PRINT_STATS("\tPackets Received = %llu", v949, v950, v951, v952, v953, v954, v955, v956, *(_QWORD *)(a2 + 2416));
  DP_PRINT_STATS("\tBytes Received = %llu", v957, v958, v959, v960, v961, v962, v963, v964, *(_QWORD *)(a2 + 2424));
  DP_PRINT_STATS("Ring Id = %d", v965, v966, v967, v968, v969, v970, v971, v972, 7);
  DP_PRINT_STATS("\tPackets Received = %llu", v973, v974, v975, v976, v977, v978, v979, v980, *(_QWORD *)(a2 + 2432));
  DP_PRINT_STATS("\tBytes Received = %llu", v981, v982, v983, v984, v985, v986, v987, v988, *(_QWORD *)(a2 + 2440));
  DP_PRINT_STATS(
    "Packets Received on lmac[%d] = %llu ( %llu )",
    v989,
    v990,
    v991,
    v992,
    v993,
    v994,
    v995,
    v996,
    0,
    *(_QWORD *)(a2 + 2464),
    *(_QWORD *)(a2 + 2472));
  DP_PRINT_STATS(
    "Packets Received on lmac[%d] = %llu ( %llu )",
    v997,
    v998,
    v999,
    v1000,
    v1001,
    v1002,
    v1003,
    v1004,
    1,
    *(_QWORD *)(a2 + 2480),
    *(_QWORD *)(a2 + 2488));
  DP_PRINT_STATS(
    "Unicast Packets Received = %llu",
    v1005,
    v1006,
    v1007,
    v1008,
    v1009,
    v1010,
    v1011,
    v1012,
    *(_QWORD *)(a2 + 2496));
  DP_PRINT_STATS(
    "Unicast Bytes Received = %llu",
    v1013,
    v1014,
    v1015,
    v1016,
    v1017,
    v1018,
    v1019,
    v1020,
    *(_QWORD *)(a2 + 2504));
  DP_PRINT_STATS(
    "Multicast Packets Received = %llu",
    v1021,
    v1022,
    v1023,
    v1024,
    v1025,
    v1026,
    v1027,
    v1028,
    *(_QWORD *)(a2 + 2512));
  DP_PRINT_STATS(
    "Multicast Bytes Received = %llu",
    v1029,
    v1030,
    v1031,
    v1032,
    v1033,
    v1034,
    v1035,
    v1036,
    *(_QWORD *)(a2 + 2520));
  DP_PRINT_STATS(
    "Broadcast Packets Received = %llu",
    v1037,
    v1038,
    v1039,
    v1040,
    v1041,
    v1042,
    v1043,
    v1044,
    *(_QWORD *)(a2 + 2528));
  DP_PRINT_STATS(
    "Broadcast Bytes Received = %llu",
    v1045,
    v1046,
    v1047,
    v1048,
    v1049,
    v1050,
    v1051,
    v1052,
    *(_QWORD *)(a2 + 2536));
  DP_PRINT_STATS(
    "Packets Sent To Stack in TWT Session = %llu",
    v1053,
    v1054,
    v1055,
    v1056,
    v1057,
    v1058,
    v1059,
    v1060,
    *(_QWORD *)(a2 + 3616));
  DP_PRINT_STATS(
    "Bytes Sent To Stack in TWT Session = %llu",
    v1061,
    v1062,
    v1063,
    v1064,
    v1065,
    v1066,
    v1067,
    v1068,
    *(_QWORD *)(a2 + 3624));
  DP_PRINT_STATS(
    "Intra BSS Packets Received = %llu",
    v1069,
    v1070,
    v1071,
    v1072,
    v1073,
    v1074,
    v1075,
    v1076,
    *(_QWORD *)(a2 + 2624));
  DP_PRINT_STATS(
    "Intra BSS Bytes Received = %llu",
    v1077,
    v1078,
    v1079,
    v1080,
    v1081,
    v1082,
    v1083,
    v1084,
    *(_QWORD *)(a2 + 2632));
  DP_PRINT_STATS(
    "Intra BSS Packets Failed = %llu",
    v1085,
    v1086,
    v1087,
    v1088,
    v1089,
    v1090,
    v1091,
    v1092,
    *(_QWORD *)(a2 + 2640));
  DP_PRINT_STATS(
    "Intra BSS Bytes Failed = %llu",
    v1093,
    v1094,
    v1095,
    v1096,
    v1097,
    v1098,
    v1099,
    v1100,
    *(_QWORD *)(a2 + 2648));
  DP_PRINT_STATS(
    "Intra BSS MDNS Packets Not Forwarded  = %d",
    v1101,
    v1102,
    v1103,
    v1104,
    v1105,
    v1106,
    v1107,
    v1108,
    *(unsigned int *)(a2 + 2656));
  DP_PRINT_STATS(
    "Raw Packets Received = %llu",
    v1109,
    v1110,
    v1111,
    v1112,
    v1113,
    v1114,
    v1115,
    v1116,
    *(_QWORD *)(a2 + 2544));
  DP_PRINT_STATS(
    "Raw Bytes Received = %llu",
    v1117,
    v1118,
    v1119,
    v1120,
    v1121,
    v1122,
    v1123,
    v1124,
    *(_QWORD *)(a2 + 2552));
  DP_PRINT_STATS(
    "Errors: MIC Errors = %d",
    v1125,
    v1126,
    v1127,
    v1128,
    v1129,
    v1130,
    v1131,
    v1132,
    *(unsigned int *)(a2 + 2664));
  DP_PRINT_STATS(
    "Errors: Decryption Errors = %d",
    v1133,
    v1134,
    v1135,
    v1136,
    v1137,
    v1138,
    v1139,
    v1140,
    *(unsigned int *)(a2 + 2668));
  DP_PRINT_STATS(
    "Errors: PN Errors = %d",
    v1141,
    v1142,
    v1143,
    v1144,
    v1145,
    v1146,
    v1147,
    v1148,
    *(unsigned int *)(a2 + 2676));
  DP_PRINT_STATS(
    "Errors: OOR Errors = %d",
    v1149,
    v1150,
    v1151,
    v1152,
    v1153,
    v1154,
    v1155,
    v1156,
    *(unsigned int *)(a2 + 2680));
  DP_PRINT_STATS(
    "Errors: 2k Jump Errors = %d",
    v1157,
    v1158,
    v1159,
    v1160,
    v1161,
    v1162,
    v1163,
    v1164,
    *(unsigned int *)(a2 + 2684));
  DP_PRINT_STATS(
    "Errors: RXDMA Wifi Parse Errors = %d",
    v1165,
    v1166,
    v1167,
    v1168,
    v1169,
    v1170,
    v1171,
    v1172,
    *(unsigned int *)(a2 + 2688));
  DP_PRINT_STATS(
    "Msdu's Received As Part of Ampdu = %d",
    v1173,
    v1174,
    v1175,
    v1176,
    v1177,
    v1178,
    v1179,
    v1180,
    *(unsigned int *)(a2 + 3424));
  DP_PRINT_STATS(
    "Msdu's Received As Ampdu = %d",
    v1181,
    v1182,
    v1183,
    v1184,
    v1185,
    v1186,
    v1187,
    v1188,
    *(unsigned int *)(a2 + 3428));
  DP_PRINT_STATS(
    "Msdu's Received Not Part of Amsdu's = %d",
    v1189,
    v1190,
    v1191,
    v1192,
    v1193,
    v1194,
    v1195,
    v1196,
    *(unsigned int *)(a2 + 3432));
  DP_PRINT_STATS(
    "MSDUs Received As Part of Amsdu = %d",
    v1197,
    v1198,
    v1199,
    v1200,
    v1201,
    v1202,
    v1203,
    v1204,
    *(unsigned int *)(a2 + 3436));
  DP_PRINT_STATS(
    "MSDU Rx Retries= %d",
    v1205,
    v1206,
    v1207,
    v1208,
    v1209,
    v1210,
    v1211,
    v1212,
    *(unsigned int *)(a2 + 3496));
  DP_PRINT_STATS(
    "MPDU Rx Retries= %d",
    v1213,
    v1214,
    v1215,
    v1216,
    v1217,
    v1218,
    v1219,
    v1220,
    *(unsigned int *)(a2 + 3632));
  DP_PRINT_STATS("NAWDS : ", v1221, v1222, v1223, v1224, v1225, v1226, v1227, v1228);
  DP_PRINT_STATS(
    "\tNawds multicast Drop Rx Packet = %d",
    v1229,
    v1230,
    v1231,
    v1232,
    v1233,
    v1234,
    v1235,
    v1236,
    *(unsigned int *)(a2 + 2560));
  DP_PRINT_STATS(
    " 3address multicast Drop Rx Packet = %d",
    v1237,
    v1238,
    v1239,
    v1240,
    v1241,
    v1242,
    v1243,
    v1244,
    *(unsigned int *)(a2 + 3636));
  DP_PRINT_STATS(
    "SGI = 0.8us %d 0.4us %d 1.6us %d 3.2us %d",
    v1245,
    v1246,
    v1247,
    v1248,
    v1249,
    v1250,
    v1251,
    v1252,
    *(unsigned int *)(a2 + 3024),
    *(unsigned int *)(a2 + 3028),
    *(unsigned int *)(a2 + 3032),
    *(unsigned int *)(a2 + 3036));
  DP_PRINT_STATS("Wireless Mutlimedia ", v1253, v1254, v1255, v1256, v1257, v1258, v1259, v1260);
  DP_PRINT_STATS(
    "\t Best effort = %d",
    v1261,
    v1262,
    v1263,
    v1264,
    v1265,
    v1266,
    v1267,
    v1268,
    *(unsigned int *)(a2 + 2692));
  DP_PRINT_STATS(
    "\t Background= %d",
    v1269,
    v1270,
    v1271,
    v1272,
    v1273,
    v1274,
    v1275,
    v1276,
    *(unsigned int *)(a2 + 2696));
  DP_PRINT_STATS("\t Video = %d", v1277, v1278, v1279, v1280, v1281, v1282, v1283, v1284, *(unsigned int *)(a2 + 2700));
  DP_PRINT_STATS("\t Voice = %d", v1285, v1286, v1287, v1288, v1289, v1290, v1291, v1292, *(unsigned int *)(a2 + 2704));
  DP_PRINT_STATS(
    " Total Rx PPDU Count = %d",
    v1293,
    v1294,
    v1295,
    v1296,
    v1297,
    v1298,
    v1299,
    v1300,
    *(unsigned int *)(a2 + 3504));
  DP_PRINT_STATS(
    " Total Rx MPDU Count = %d",
    v1301,
    v1302,
    v1303,
    v1304,
    v1305,
    v1306,
    v1307,
    v1308,
    *(unsigned int *)(a2 + 3500));
  DP_PRINT_STATS("MSDU Reception Type", v1309, v1310, v1311, v1312, v1313, v1314, v1315, v1316);
  DP_PRINT_STATS(
    "SU %d MU_MIMO %d MU_OFDMA %d MU_OFDMA_MIMO %d",
    v1317,
    v1318,
    v1319,
    v1320,
    v1321,
    v1322,
    v1323,
    v1324,
    *(unsigned int *)(a2 + 2708),
    *(unsigned int *)(a2 + 2712),
    *(unsigned int *)(a2 + 2716),
    *(unsigned int *)(a2 + 2720));
  DP_PRINT_STATS("PPDU Reception Type", v1325, v1326, v1327, v1328, v1329, v1330, v1331, v1332);
  DP_PRINT_STATS(
    "SU %d MU_MIMO %d MU_OFDMA %d MU_OFDMA_MIMO %d",
    v1333,
    v1334,
    v1335,
    v1336,
    v1337,
    v1338,
    v1339,
    v1340,
    *(unsigned int *)(a2 + 3176),
    *(unsigned int *)(a2 + 3180),
    *(unsigned int *)(a2 + 3184),
    *(unsigned int *)(a2 + 3188));
  dp_print_common_rates_info(a2 + 2724, v1341, v1342, v1343, v1344, v1345, v1346, v1347, v1348);
  DP_PRINT_STATS("PPDU Count", v1349, v1350, v1351, v1352, v1353, v1354, v1355, v1356);
  DP_PRINT_STATS(
    "\t%s = %d",
    v1357,
    v1358,
    v1359,
    v1360,
    v1361,
    v1362,
    v1363,
    v1364,
    "HE MCS 0 (BPSK 1/2)     ",
    *(unsigned int *)(a2 + 3116));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1365,
    v1366,
    v1367,
    v1368,
    v1369,
    v1370,
    v1371,
    v1372,
    "HE MCS 1 (QPSK 1/2)     ",
    *(unsigned int *)(a2 + 3120));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1373,
    v1374,
    v1375,
    v1376,
    v1377,
    v1378,
    v1379,
    v1380,
    "HE MCS 2 (QPSK 3/4)     ",
    *(unsigned int *)(a2 + 3124));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1381,
    v1382,
    v1383,
    v1384,
    v1385,
    v1386,
    v1387,
    v1388,
    "HE MCS 3 (16-QAM 1/2)   ",
    *(unsigned int *)(a2 + 3128));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1389,
    v1390,
    v1391,
    v1392,
    v1393,
    v1394,
    v1395,
    v1396,
    "HE MCS 4 (16-QAM 3/4)   ",
    *(unsigned int *)(a2 + 3132));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1397,
    v1398,
    v1399,
    v1400,
    v1401,
    v1402,
    v1403,
    v1404,
    "HE MCS 5 (64-QAM 2/3)   ",
    *(unsigned int *)(a2 + 3136));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1405,
    v1406,
    v1407,
    v1408,
    v1409,
    v1410,
    v1411,
    v1412,
    "HE MCS 6 (64-QAM 3/4)   ",
    *(unsigned int *)(a2 + 3140));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1413,
    v1414,
    v1415,
    v1416,
    v1417,
    v1418,
    v1419,
    v1420,
    "HE MCS 7 (64-QAM 5/6)   ",
    *(unsigned int *)(a2 + 3144));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1421,
    v1422,
    v1423,
    v1424,
    v1425,
    v1426,
    v1427,
    v1428,
    "HE MCS 8 (256-QAM 3/4)  ",
    *(unsigned int *)(a2 + 3148));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1429,
    v1430,
    v1431,
    v1432,
    v1433,
    v1434,
    v1435,
    v1436,
    "HE MCS 9 (256-QAM 5/6)  ",
    *(unsigned int *)(a2 + 3152));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1437,
    v1438,
    v1439,
    v1440,
    v1441,
    v1442,
    v1443,
    v1444,
    "HE MCS 10 (1024-QAM 3/4)",
    *(unsigned int *)(a2 + 3156));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1445,
    v1446,
    v1447,
    v1448,
    v1449,
    v1450,
    v1451,
    v1452,
    "HE MCS 11 (1024-QAM 5/6)",
    *(unsigned int *)(a2 + 3160));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1453,
    v1454,
    v1455,
    v1456,
    v1457,
    v1458,
    v1459,
    v1460,
    "HE MCS 12 (4096-QAM 3/4)",
    *(unsigned int *)(a2 + 3164));
  DP_PRINT_STATS(
    "\t%s = %d",
    v1461,
    v1462,
    v1463,
    v1464,
    v1465,
    v1466,
    v1467,
    v1468,
    "HE MCS 13 (4096-QAM 5/6)",
    *(unsigned int *)(a2 + 3168));
  DP_PRINT_STATS("\n", v1469, v1470, v1471, v1472, v1473, v1474, v1475, v1476);
  DP_PRINT_STATS("PPDU Count", v1477, v1478, v1479, v1480, v1481, v1482, v1483, v1484);
  v1493 = 0;
  do
  {
    v1494 = v820;
    v1495 = (unsigned int *)(a2 + 3192 + 100 * v1493);
    if ( dp_mu_rate_string[525 * v1493 + 34] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492);
    v1496 = &dp_mu_rate_string[525 * v1493];
    if ( v1496[69] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1496 + 35, v1495[11]);
    v1497 = &dp_mu_rate_string[525 * v1493];
    if ( v1497[104] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1497 + 70, v1495[12]);
    v1498 = &dp_mu_rate_string[525 * v1493];
    if ( v1498[139] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1498 + 105, v1495[13]);
    v1499 = &dp_mu_rate_string[525 * v1493];
    if ( v1499[174] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1499 + 140, v1495[14]);
    v1500 = &dp_mu_rate_string[525 * v1493];
    if ( v1500[209] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1500 + 175, v1495[15]);
    v1501 = &dp_mu_rate_string[525 * v1493];
    if ( v1501[244] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1501 + 210, v1495[16]);
    v1502 = &dp_mu_rate_string[525 * v1493];
    if ( v1502[279] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1502 + 245, v1495[17]);
    v1503 = &dp_mu_rate_string[525 * v1493];
    if ( v1503[314] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1503 + 280, v1495[18]);
    v1504 = &dp_mu_rate_string[525 * v1493];
    if ( v1504[349] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1504 + 315, v1495[19]);
    v1505 = &dp_mu_rate_string[525 * v1493];
    if ( v1505[384] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1505 + 350, v1495[20]);
    v1506 = &dp_mu_rate_string[525 * v1493];
    if ( v1506[419] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1506 + 385, v1495[21]);
    v1507 = &dp_mu_rate_string[525 * v1493];
    if ( v1507[454] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1507 + 420, v1495[22]);
    v1508 = &dp_mu_rate_string[525 * v1493];
    if ( v1508[489] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1508 + 455, v1495[23]);
    v1509 = &dp_mu_rate_string[525 * v1493];
    if ( v1509[524] )
      DP_PRINT_STATS("\t%s = %d", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492, v1509 + 490, v1495[24]);
    DP_PRINT_STATS("\n", v1485, v1486, v1487, v1488, v1489, v1490, v1491, v1492);
    v820 = 0;
    v1493 = 1;
  }
  while ( (v1494 & 1) != 0 );
  dp_print_nss(v1738, a2 + 3044);
  DP_PRINT_STATS("MSDU Count", v1510, v1511, v1512, v1513, v1514, v1515, v1516, v1517);
  DP_PRINT_STATS("\tNSS(1-8) = %s", v1518, v1519, v1520, v1521, v1522, v1523, v1524, v1525, v1738);
  DP_PRINT_STATS("reception mode SU", v1526, v1527, v1528, v1529, v1530, v1531, v1532, v1533);
  dp_print_nss(v1738, a2 + 3076);
  DP_PRINT_STATS("\tPPDU Count", v1534, v1535, v1536, v1537, v1538, v1539, v1540, v1541);
  DP_PRINT_STATS("\tNSS(1-8) = %s", v1542, v1543, v1544, v1545, v1546, v1547, v1548, v1549, v1738);
  DP_PRINT_STATS(
    "\tMPDU OK = %d, MPDU Fail = %d",
    v1550,
    v1551,
    v1552,
    v1553,
    v1554,
    v1555,
    v1556,
    v1557,
    *(unsigned int *)(a2 + 3108),
    *(unsigned int *)(a2 + 3112));
  DP_PRINT_STATS("reception mode %s", v1558, v1559, v1560, v1561, v1562, v1563, v1564, v1565, mu_reception_mode[0]);
  dp_print_nss(v1738, a2 + 3192);
  DP_PRINT_STATS("\tPPDU Count", v1566, v1567, v1568, v1569, v1570, v1571, v1572, v1573);
  DP_PRINT_STATS("\tNSS(1-8) = %s", v1574, v1575, v1576, v1577, v1578, v1579, v1580, v1581, v1738);
  DP_PRINT_STATS(
    "\tMPDU OK = %d, MPDU Fail = %d",
    v1582,
    v1583,
    v1584,
    v1585,
    v1586,
    v1587,
    v1588,
    v1589,
    *(unsigned int *)(a2 + 3224),
    *(unsigned int *)(a2 + 3228));
  DP_PRINT_STATS("reception mode %s", v1590, v1591, v1592, v1593, v1594, v1595, v1596, v1597, off_15920[0]);
  dp_print_nss(v1738, a2 + 3292);
  DP_PRINT_STATS("\tPPDU Count", v1598, v1599, v1600, v1601, v1602, v1603, v1604, v1605);
  DP_PRINT_STATS("\tNSS(1-8) = %s", v1606, v1607, v1608, v1609, v1610, v1611, v1612, v1613, v1738);
  DP_PRINT_STATS(
    "\tMPDU OK = %d, MPDU Fail = %d",
    v1614,
    v1615,
    v1616,
    v1617,
    v1618,
    v1619,
    v1620,
    v1621,
    *(unsigned int *)(a2 + 3324),
    *(unsigned int *)(a2 + 3328));
  DP_PRINT_STATS("Aggregation:", v1622, v1623, v1624, v1625, v1626, v1627, v1628, v1629);
  DP_PRINT_STATS(
    "\tMsdu's Part of Ampdu = %d",
    v1630,
    v1631,
    v1632,
    v1633,
    v1634,
    v1635,
    v1636,
    v1637,
    *(unsigned int *)(a2 + 3428));
  DP_PRINT_STATS(
    "\tMsdu's With No Mpdu Level Aggregation = %d",
    v1638,
    v1639,
    v1640,
    v1641,
    v1642,
    v1643,
    v1644,
    v1645,
    *(unsigned int *)(a2 + 3424));
  DP_PRINT_STATS(
    "\tMsdu's Part of Amsdu = %d",
    v1646,
    v1647,
    v1648,
    v1649,
    v1650,
    v1651,
    v1652,
    v1653,
    *(unsigned int *)(a2 + 3436));
  DP_PRINT_STATS(
    "\tMsdu's With No Msdu Level Aggregation = %d",
    v1654,
    v1655,
    v1656,
    v1657,
    v1658,
    v1659,
    v1660,
    v1661,
    *(unsigned int *)(a2 + 3432));
  DP_PRINT_STATS("Bytes and Packets received in last one sec:", v1662, v1663, v1664, v1665, v1666, v1667, v1668, v1669);
  DP_PRINT_STATS(
    "\tBytes received in last sec: %d",
    v1670,
    v1671,
    v1672,
    v1673,
    v1674,
    v1675,
    v1676,
    v1677,
    *(unsigned int *)(a2 + 3488));
  DP_PRINT_STATS(
    "\tData received in last sec: %d",
    v1678,
    v1679,
    v1680,
    v1681,
    v1682,
    v1683,
    v1684,
    v1685,
    *(unsigned int *)(a2 + 3492));
  DP_PRINT_STATS(
    "MEC Packet Drop = %llu",
    v1686,
    v1687,
    v1688,
    v1689,
    v1690,
    v1691,
    v1692,
    v1693,
    *(_QWORD *)(a2 + 2568));
  DP_PRINT_STATS("MEC Byte Drop = %llu", v1694, v1695, v1696, v1697, v1698, v1699, v1700, v1701, *(_QWORD *)(a2 + 2576));
  DP_PRINT_STATS(
    "Multipass Rx Packet Drop = %d",
    v1702,
    v1703,
    v1704,
    v1705,
    v1706,
    v1707,
    v1708,
    v1709,
    *(unsigned int *)(a2 + 3540));
  DP_PRINT_STATS(
    "Peer Unauth Rx Packet Drop = %d",
    v1710,
    v1711,
    v1712,
    v1713,
    v1714,
    v1715,
    v1716,
    v1717,
    *(unsigned int *)(a2 + 3544));
  DP_PRINT_STATS(
    "Policy Check Rx Packet Drop = %d",
    v1718,
    v1719,
    v1720,
    v1721,
    v1722,
    v1723,
    v1724,
    v1725,
    *(unsigned int *)(a2 + 3548));
  if ( v1736 )
  {
    v1734 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v1736 + 8) + 1560LL);
    if ( v1734 )
    {
      if ( *((_DWORD *)v1734 - 1) != -1009236478 )
        __break(0x8228u);
      v1734(a2, 1);
    }
    DP_PRINT_STATS(
      "Rx PPDU Duration: %llu",
      v1726,
      v1727,
      v1728,
      v1729,
      v1730,
      v1731,
      v1732,
      v1733,
      *(_QWORD *)(a2 + 3712));
    result = wlan_cfg_get_dp_proto_stats(*(_QWORD *)(*(_QWORD *)(v1736 + 8) + 40LL));
  }
  else
  {
    result = DP_PRINT_STATS(
               "Rx PPDU Duration: %llu",
               v1726,
               v1727,
               v1728,
               v1729,
               v1730,
               v1731,
               v1732,
               v1733,
               *(_QWORD *)(a2 + 3712));
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
