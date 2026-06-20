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
  __int64 v11; // x8
  __int64 v12; // x27
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
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
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  double v93; // d0
  double v94; // d1
  double v95; // d2
  double v96; // d3
  double v97; // d4
  double v98; // d5
  double v99; // d6
  double v100; // d7
  double v101; // d0
  double v102; // d1
  double v103; // d2
  double v104; // d3
  double v105; // d4
  double v106; // d5
  double v107; // d6
  double v108; // d7
  double v109; // d0
  double v110; // d1
  double v111; // d2
  double v112; // d3
  double v113; // d4
  double v114; // d5
  double v115; // d6
  double v116; // d7
  double v117; // d0
  double v118; // d1
  double v119; // d2
  double v120; // d3
  double v121; // d4
  double v122; // d5
  double v123; // d6
  double v124; // d7
  double v125; // d0
  double v126; // d1
  double v127; // d2
  double v128; // d3
  double v129; // d4
  double v130; // d5
  double v131; // d6
  double v132; // d7
  double v133; // d0
  double v134; // d1
  double v135; // d2
  double v136; // d3
  double v137; // d4
  double v138; // d5
  double v139; // d6
  double v140; // d7
  double v141; // d0
  double v142; // d1
  double v143; // d2
  double v144; // d3
  double v145; // d4
  double v146; // d5
  double v147; // d6
  double v148; // d7
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  double v157; // d0
  double v158; // d1
  double v159; // d2
  double v160; // d3
  double v161; // d4
  double v162; // d5
  double v163; // d6
  double v164; // d7
  double v165; // d0
  double v166; // d1
  double v167; // d2
  double v168; // d3
  double v169; // d4
  double v170; // d5
  double v171; // d6
  double v172; // d7
  double v173; // d0
  double v174; // d1
  double v175; // d2
  double v176; // d3
  double v177; // d4
  double v178; // d5
  double v179; // d6
  double v180; // d7
  double v181; // d0
  double v182; // d1
  double v183; // d2
  double v184; // d3
  double v185; // d4
  double v186; // d5
  double v187; // d6
  double v188; // d7
  double v189; // d0
  double v190; // d1
  double v191; // d2
  double v192; // d3
  double v193; // d4
  double v194; // d5
  double v195; // d6
  double v196; // d7
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  double v213; // d0
  double v214; // d1
  double v215; // d2
  double v216; // d3
  double v217; // d4
  double v218; // d5
  double v219; // d6
  double v220; // d7
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  double v229; // d0
  double v230; // d1
  double v231; // d2
  double v232; // d3
  double v233; // d4
  double v234; // d5
  double v235; // d6
  double v236; // d7
  unsigned __int64 v237; // x8
  double v238; // d0
  double v239; // d1
  double v240; // d2
  double v241; // d3
  double v242; // d4
  double v243; // d5
  double v244; // d6
  double v245; // d7
  double v246; // d0
  double v247; // d1
  double v248; // d2
  double v249; // d3
  double v250; // d4
  double v251; // d5
  double v252; // d6
  double v253; // d7
  double v254; // d0
  double v255; // d1
  double v256; // d2
  double v257; // d3
  double v258; // d4
  double v259; // d5
  double v260; // d6
  double v261; // d7
  double v262; // d0
  double v263; // d1
  double v264; // d2
  double v265; // d3
  double v266; // d4
  double v267; // d5
  double v268; // d6
  double v269; // d7
  double v270; // d0
  double v271; // d1
  double v272; // d2
  double v273; // d3
  double v274; // d4
  double v275; // d5
  double v276; // d6
  double v277; // d7
  double v278; // d0
  double v279; // d1
  double v280; // d2
  double v281; // d3
  double v282; // d4
  double v283; // d5
  double v284; // d6
  double v285; // d7
  double v286; // d0
  double v287; // d1
  double v288; // d2
  double v289; // d3
  double v290; // d4
  double v291; // d5
  double v292; // d6
  double v293; // d7
  double v294; // d0
  double v295; // d1
  double v296; // d2
  double v297; // d3
  double v298; // d4
  double v299; // d5
  double v300; // d6
  double v301; // d7
  double v302; // d0
  double v303; // d1
  double v304; // d2
  double v305; // d3
  double v306; // d4
  double v307; // d5
  double v308; // d6
  double v309; // d7
  double v310; // d0
  double v311; // d1
  double v312; // d2
  double v313; // d3
  double v314; // d4
  double v315; // d5
  double v316; // d6
  double v317; // d7
  double v318; // d0
  double v319; // d1
  double v320; // d2
  double v321; // d3
  double v322; // d4
  double v323; // d5
  double v324; // d6
  double v325; // d7
  double v326; // d0
  double v327; // d1
  double v328; // d2
  double v329; // d3
  double v330; // d4
  double v331; // d5
  double v332; // d6
  double v333; // d7
  double v334; // d0
  double v335; // d1
  double v336; // d2
  double v337; // d3
  double v338; // d4
  double v339; // d5
  double v340; // d6
  double v341; // d7
  double v342; // d0
  double v343; // d1
  double v344; // d2
  double v345; // d3
  double v346; // d4
  double v347; // d5
  double v348; // d6
  double v349; // d7
  double v350; // d0
  double v351; // d1
  double v352; // d2
  double v353; // d3
  double v354; // d4
  double v355; // d5
  double v356; // d6
  double v357; // d7
  double v358; // d0
  double v359; // d1
  double v360; // d2
  double v361; // d3
  double v362; // d4
  double v363; // d5
  double v364; // d6
  double v365; // d7
  double v366; // d0
  double v367; // d1
  double v368; // d2
  double v369; // d3
  double v370; // d4
  double v371; // d5
  double v372; // d6
  double v373; // d7
  double v374; // d0
  double v375; // d1
  double v376; // d2
  double v377; // d3
  double v378; // d4
  double v379; // d5
  double v380; // d6
  double v381; // d7
  double v382; // d0
  double v383; // d1
  double v384; // d2
  double v385; // d3
  double v386; // d4
  double v387; // d5
  double v388; // d6
  double v389; // d7
  double v390; // d0
  double v391; // d1
  double v392; // d2
  double v393; // d3
  double v394; // d4
  double v395; // d5
  double v396; // d6
  double v397; // d7
  double v398; // d0
  double v399; // d1
  double v400; // d2
  double v401; // d3
  double v402; // d4
  double v403; // d5
  double v404; // d6
  double v405; // d7
  double v406; // d0
  double v407; // d1
  double v408; // d2
  double v409; // d3
  double v410; // d4
  double v411; // d5
  double v412; // d6
  double v413; // d7
  double v414; // d0
  double v415; // d1
  double v416; // d2
  double v417; // d3
  double v418; // d4
  double v419; // d5
  double v420; // d6
  double v421; // d7
  double v422; // d0
  double v423; // d1
  double v424; // d2
  double v425; // d3
  double v426; // d4
  double v427; // d5
  double v428; // d6
  double v429; // d7
  double v430; // d0
  double v431; // d1
  double v432; // d2
  double v433; // d3
  double v434; // d4
  double v435; // d5
  double v436; // d6
  double v437; // d7
  double v438; // d0
  double v439; // d1
  double v440; // d2
  double v441; // d3
  double v442; // d4
  double v443; // d5
  double v444; // d6
  double v445; // d7
  double v446; // d0
  double v447; // d1
  double v448; // d2
  double v449; // d3
  double v450; // d4
  double v451; // d5
  double v452; // d6
  double v453; // d7
  double v454; // d0
  double v455; // d1
  double v456; // d2
  double v457; // d3
  double v458; // d4
  double v459; // d5
  double v460; // d6
  double v461; // d7
  double v462; // d0
  double v463; // d1
  double v464; // d2
  double v465; // d3
  double v466; // d4
  double v467; // d5
  double v468; // d6
  double v469; // d7
  double v470; // d0
  double v471; // d1
  double v472; // d2
  double v473; // d3
  double v474; // d4
  double v475; // d5
  double v476; // d6
  double v477; // d7
  double v478; // d0
  double v479; // d1
  double v480; // d2
  double v481; // d3
  double v482; // d4
  double v483; // d5
  double v484; // d6
  double v485; // d7
  double v486; // d0
  double v487; // d1
  double v488; // d2
  double v489; // d3
  double v490; // d4
  double v491; // d5
  double v492; // d6
  double v493; // d7
  double v494; // d0
  double v495; // d1
  double v496; // d2
  double v497; // d3
  double v498; // d4
  double v499; // d5
  double v500; // d6
  double v501; // d7
  double v502; // d0
  double v503; // d1
  double v504; // d2
  double v505; // d3
  double v506; // d4
  double v507; // d5
  double v508; // d6
  double v509; // d7
  double v510; // d0
  double v511; // d1
  double v512; // d2
  double v513; // d3
  double v514; // d4
  double v515; // d5
  double v516; // d6
  double v517; // d7
  double v518; // d0
  double v519; // d1
  double v520; // d2
  double v521; // d3
  double v522; // d4
  double v523; // d5
  double v524; // d6
  double v525; // d7
  double v526; // d0
  double v527; // d1
  double v528; // d2
  double v529; // d3
  double v530; // d4
  double v531; // d5
  double v532; // d6
  double v533; // d7
  double v534; // d0
  double v535; // d1
  double v536; // d2
  double v537; // d3
  double v538; // d4
  double v539; // d5
  double v540; // d6
  double v541; // d7
  double v542; // d0
  double v543; // d1
  double v544; // d2
  double v545; // d3
  double v546; // d4
  double v547; // d5
  double v548; // d6
  double v549; // d7
  double v550; // d0
  double v551; // d1
  double v552; // d2
  double v553; // d3
  double v554; // d4
  double v555; // d5
  double v556; // d6
  double v557; // d7
  double v558; // d0
  double v559; // d1
  double v560; // d2
  double v561; // d3
  double v562; // d4
  double v563; // d5
  double v564; // d6
  double v565; // d7
  unsigned __int8 v566; // w20
  double v567; // d0
  double v568; // d1
  double v569; // d2
  double v570; // d3
  double v571; // d4
  double v572; // d5
  double v573; // d6
  double v574; // d7
  unsigned int v575; // w26
  unsigned int v576; // w28
  unsigned __int64 v577; // x25
  int v578; // w0
  double v579; // d0
  double v580; // d1
  double v581; // d2
  double v582; // d3
  double v583; // d4
  double v584; // d5
  double v585; // d6
  double v586; // d7
  bool v587; // cf
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
  double v692; // d0
  double v693; // d1
  double v694; // d2
  double v695; // d3
  double v696; // d4
  double v697; // d5
  double v698; // d6
  double v699; // d7
  double v700; // d0
  double v701; // d1
  double v702; // d2
  double v703; // d3
  double v704; // d4
  double v705; // d5
  double v706; // d6
  double v707; // d7
  double v708; // d0
  double v709; // d1
  double v710; // d2
  double v711; // d3
  double v712; // d4
  double v713; // d5
  double v714; // d6
  double v715; // d7
  double v716; // d0
  double v717; // d1
  double v718; // d2
  double v719; // d3
  double v720; // d4
  double v721; // d5
  double v722; // d6
  double v723; // d7
  double v724; // d0
  double v725; // d1
  double v726; // d2
  double v727; // d3
  double v728; // d4
  double v729; // d5
  double v730; // d6
  double v731; // d7
  double v732; // d0
  double v733; // d1
  double v734; // d2
  double v735; // d3
  double v736; // d4
  double v737; // d5
  double v738; // d6
  double v739; // d7
  double v740; // d0
  double v741; // d1
  double v742; // d2
  double v743; // d3
  double v744; // d4
  double v745; // d5
  double v746; // d6
  double v747; // d7
  double v748; // d0
  double v749; // d1
  double v750; // d2
  double v751; // d3
  double v752; // d4
  double v753; // d5
  double v754; // d6
  double v755; // d7
  double v756; // d0
  double v757; // d1
  double v758; // d2
  double v759; // d3
  double v760; // d4
  double v761; // d5
  double v762; // d6
  double v763; // d7
  double v764; // d0
  double v765; // d1
  double v766; // d2
  double v767; // d3
  double v768; // d4
  double v769; // d5
  double v770; // d6
  double v771; // d7
  _DWORD *v772; // x8
  double v773; // d0
  double v774; // d1
  double v775; // d2
  double v776; // d3
  double v777; // d4
  double v778; // d5
  double v779; // d6
  double v780; // d7
  double v781; // d0
  double v782; // d1
  double v783; // d2
  double v784; // d3
  double v785; // d4
  double v786; // d5
  double v787; // d6
  double v788; // d7
  double v789; // d0
  double v790; // d1
  double v791; // d2
  double v792; // d3
  double v793; // d4
  double v794; // d5
  double v795; // d6
  double v796; // d7
  double v797; // d0
  double v798; // d1
  double v799; // d2
  double v800; // d3
  double v801; // d4
  double v802; // d5
  double v803; // d6
  double v804; // d7
  double v805; // d0
  double v806; // d1
  double v807; // d2
  double v808; // d3
  double v809; // d4
  double v810; // d5
  double v811; // d6
  double v812; // d7
  double v813; // d0
  double v814; // d1
  double v815; // d2
  double v816; // d3
  double v817; // d4
  double v818; // d5
  double v819; // d6
  double v820; // d7
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
  const char *v1365; // x21
  __int64 i; // x20
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
  const char *v1383; // x21
  __int64 j; // x20
  double v1385; // d0
  double v1386; // d1
  double v1387; // d2
  double v1388; // d3
  double v1389; // d4
  double v1390; // d5
  double v1391; // d6
  double v1392; // d7
  const char *v1393; // x21
  __int64 k; // x20
  double v1395; // d0
  double v1396; // d1
  double v1397; // d2
  double v1398; // d3
  double v1399; // d4
  double v1400; // d5
  double v1401; // d6
  double v1402; // d7
  double v1403; // d0
  double v1404; // d1
  double v1405; // d2
  double v1406; // d3
  double v1407; // d4
  double v1408; // d5
  double v1409; // d6
  double v1410; // d7
  double v1411; // d0
  double v1412; // d1
  double v1413; // d2
  double v1414; // d3
  double v1415; // d4
  double v1416; // d5
  double v1417; // d6
  double v1418; // d7
  double v1419; // d0
  double v1420; // d1
  double v1421; // d2
  double v1422; // d3
  double v1423; // d4
  double v1424; // d5
  double v1425; // d6
  double v1426; // d7
  double v1427; // d0
  double v1428; // d1
  double v1429; // d2
  double v1430; // d3
  double v1431; // d4
  double v1432; // d5
  double v1433; // d6
  double v1434; // d7
  double v1435; // d0
  double v1436; // d1
  double v1437; // d2
  double v1438; // d3
  double v1439; // d4
  double v1440; // d5
  double v1441; // d6
  double v1442; // d7
  double v1443; // d0
  double v1444; // d1
  double v1445; // d2
  double v1446; // d3
  double v1447; // d4
  double v1448; // d5
  double v1449; // d6
  double v1450; // d7
  double v1451; // d0
  double v1452; // d1
  double v1453; // d2
  double v1454; // d3
  double v1455; // d4
  double v1456; // d5
  double v1457; // d6
  double v1458; // d7
  double v1459; // d0
  double v1460; // d1
  double v1461; // d2
  double v1462; // d3
  double v1463; // d4
  double v1464; // d5
  double v1465; // d6
  double v1466; // d7
  double v1467; // d0
  double v1468; // d1
  double v1469; // d2
  double v1470; // d3
  double v1471; // d4
  double v1472; // d5
  double v1473; // d6
  double v1474; // d7
  double v1475; // d0
  double v1476; // d1
  double v1477; // d2
  double v1478; // d3
  double v1479; // d4
  double v1480; // d5
  double v1481; // d6
  double v1482; // d7
  double v1483; // d0
  double v1484; // d1
  double v1485; // d2
  double v1486; // d3
  double v1487; // d4
  double v1488; // d5
  double v1489; // d6
  double v1490; // d7
  double v1491; // d0
  double v1492; // d1
  double v1493; // d2
  double v1494; // d3
  double v1495; // d4
  double v1496; // d5
  double v1497; // d6
  double v1498; // d7
  double v1499; // d0
  double v1500; // d1
  double v1501; // d2
  double v1502; // d3
  double v1503; // d4
  double v1504; // d5
  double v1505; // d6
  double v1506; // d7
  double v1507; // d0
  double v1508; // d1
  double v1509; // d2
  double v1510; // d3
  double v1511; // d4
  double v1512; // d5
  double v1513; // d6
  double v1514; // d7
  double v1515; // d0
  double v1516; // d1
  double v1517; // d2
  double v1518; // d3
  double v1519; // d4
  double v1520; // d5
  double v1521; // d6
  double v1522; // d7
  double v1523; // d0
  double v1524; // d1
  double v1525; // d2
  double v1526; // d3
  double v1527; // d4
  double v1528; // d5
  double v1529; // d6
  double v1530; // d7
  double v1531; // d0
  double v1532; // d1
  double v1533; // d2
  double v1534; // d3
  double v1535; // d4
  double v1536; // d5
  double v1537; // d6
  double v1538; // d7
  double v1539; // d0
  double v1540; // d1
  double v1541; // d2
  double v1542; // d3
  double v1543; // d4
  double v1544; // d5
  double v1545; // d6
  double v1546; // d7
  double v1547; // d0
  double v1548; // d1
  double v1549; // d2
  double v1550; // d3
  double v1551; // d4
  double v1552; // d5
  double v1553; // d6
  double v1554; // d7
  double v1555; // d0
  double v1556; // d1
  double v1557; // d2
  double v1558; // d3
  double v1559; // d4
  double v1560; // d5
  double v1561; // d6
  double v1562; // d7
  double v1563; // d0
  double v1564; // d1
  double v1565; // d2
  double v1566; // d3
  double v1567; // d4
  double v1568; // d5
  double v1569; // d6
  double v1570; // d7
  double v1571; // d0
  double v1572; // d1
  double v1573; // d2
  double v1574; // d3
  double v1575; // d4
  double v1576; // d5
  double v1577; // d6
  double v1578; // d7
  double v1579; // d0
  double v1580; // d1
  double v1581; // d2
  double v1582; // d3
  double v1583; // d4
  double v1584; // d5
  double v1585; // d6
  double v1586; // d7
  double v1587; // d0
  double v1588; // d1
  double v1589; // d2
  double v1590; // d3
  double v1591; // d4
  double v1592; // d5
  double v1593; // d6
  double v1594; // d7
  double v1595; // d0
  double v1596; // d1
  double v1597; // d2
  double v1598; // d3
  double v1599; // d4
  double v1600; // d5
  double v1601; // d6
  double v1602; // d7
  double v1603; // d0
  double v1604; // d1
  double v1605; // d2
  double v1606; // d3
  double v1607; // d4
  double v1608; // d5
  double v1609; // d6
  double v1610; // d7
  double v1611; // d0
  double v1612; // d1
  double v1613; // d2
  double v1614; // d3
  double v1615; // d4
  double v1616; // d5
  double v1617; // d6
  double v1618; // d7
  void (__fastcall *v1619)(__int64, __int64); // x8
  __int64 result; // x0
  double v1621; // d0
  double v1622; // d1
  double v1623; // d2
  double v1624; // d3
  double v1625; // d4
  double v1626; // d5
  double v1627; // d6
  double v1628; // d7
  _QWORD v1630[12]; // [xsp+8h] [xbp-98h] BYREF
  _QWORD v1631[7]; // [xsp+68h] [xbp-38h] BYREF

  v1631[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_QWORD *)(a1 + 24);
  memset(v1630, 0, sizeof(v1630));
  v12 = *(_QWORD *)(v11 + 24);
  memset(v1631, 0, 48);
  DP_PRINT_STATS("Node Tx Stats:\n", a3, a4, a5, a6, a7, a8, a9, a10);
  DP_PRINT_STATS("Total Packet Completions = %llu", v13, v14, v15, v16, v17, v18, v19, v20, *(_QWORD *)(a2 + 8));
  DP_PRINT_STATS("Total Bytes Completions = %llu", v21, v22, v23, v24, v25, v26, v27, v28, *(_QWORD *)(a2 + 16));
  DP_PRINT_STATS("Success Packets = %llu", v29, v30, v31, v32, v33, v34, v35, v36, *(_QWORD *)(a2 + 88));
  DP_PRINT_STATS("Success Bytes = %llu", v37, v38, v39, v40, v41, v42, v43, v44, *(_QWORD *)(a2 + 96));
  DP_PRINT_STATS(
    "Success Packets in TWT Session = %llu",
    v45,
    v46,
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    *(_QWORD *)(a2 + 1816));
  DP_PRINT_STATS("Success Bytes in TWT Session = %llu", v53, v54, v55, v56, v57, v58, v59, v60, *(_QWORD *)(a2 + 1824));
  DP_PRINT_STATS("Unicast Success Packets = %llu", v61, v62, v63, v64, v65, v66, v67, v68, *(_QWORD *)(a2 + 24));
  DP_PRINT_STATS("Unicast Success Bytes = %llu", v69, v70, v71, v72, v73, v74, v75, v76, *(_QWORD *)(a2 + 32));
  DP_PRINT_STATS("Multicast Success Packets = %llu", v77, v78, v79, v80, v81, v82, v83, v84, *(_QWORD *)(a2 + 40));
  DP_PRINT_STATS("Multicast Success Bytes = %llu", v85, v86, v87, v88, v89, v90, v91, v92, *(_QWORD *)(a2 + 48));
  DP_PRINT_STATS("Broadcast Success Packets = %llu", v93, v94, v95, v96, v97, v98, v99, v100, *(_QWORD *)(a2 + 56));
  DP_PRINT_STATS("Broadcast Success Bytes = %llu", v101, v102, v103, v104, v105, v106, v107, v108, *(_QWORD *)(a2 + 64));
  DP_PRINT_STATS(
    "Packets Successfully Sent after one or more retry = %d",
    v109,
    v110,
    v111,
    v112,
    v113,
    v114,
    v115,
    v116,
    *(unsigned int *)(a2 + 968));
  DP_PRINT_STATS(
    "Total msdu Packets retries = %d",
    v117,
    v118,
    v119,
    v120,
    v121,
    v122,
    v123,
    v124,
    *(unsigned int *)(a2 + 972));
  DP_PRINT_STATS(
    "Packets Successfully Sent after more than one retry = %d",
    v125,
    v126,
    v127,
    v128,
    v129,
    v130,
    v131,
    v132,
    *(unsigned int *)(a2 + 976));
  DP_PRINT_STATS("Packets Failed = %d", v133, v134, v135, v136, v137, v138, v139, v140, *(unsigned int *)(a2 + 108));
  DP_PRINT_STATS(
    "Packets Failed due to retry threshold breach = %d",
    v141,
    v142,
    v143,
    v144,
    v145,
    v146,
    v147,
    v148,
    *(unsigned int *)(a2 + 964));
  DP_PRINT_STATS(
    "mpdu Packets Retries = %u",
    v149,
    v150,
    v151,
    v152,
    v153,
    v154,
    v155,
    v156,
    *(unsigned int *)(a2 + 956));
  DP_PRINT_STATS(
    "Total mpdu packets retries = %u",
    v157,
    v158,
    v159,
    v160,
    v161,
    v162,
    v163,
    v164,
    *(unsigned int *)(a2 + 960));
  DP_PRINT_STATS("Packets In OFDMA = %d", v165, v166, v167, v168, v169, v170, v171, v172, *(unsigned int *)(a2 + 112));
  DP_PRINT_STATS("Packets In STBC = %d", v173, v174, v175, v176, v177, v178, v179, v180, *(unsigned int *)(a2 + 116));
  DP_PRINT_STATS("Packets In LDPC = %d", v181, v182, v183, v184, v185, v186, v187, v188, *(unsigned int *)(a2 + 120));
  DP_PRINT_STATS("Packet Retries = %d", v189, v190, v191, v192, v193, v194, v195, v196, *(unsigned int *)(a2 + 124));
  DP_PRINT_STATS(
    "MSDU's Part of AMSDU = %d",
    v197,
    v198,
    v199,
    v200,
    v201,
    v202,
    v203,
    v204,
    *(unsigned int *)(a2 + 136));
  DP_PRINT_STATS(
    "Msdu's As Part of Ampdu = %d",
    v205,
    v206,
    v207,
    v208,
    v209,
    v210,
    v211,
    v212,
    *(unsigned int *)(a2 + 952));
  DP_PRINT_STATS("Msdu's As Ampdu = %d", v213, v214, v215, v216, v217, v218, v219, v220, *(unsigned int *)(a2 + 948));
  DP_PRINT_STATS("Last Packet RSSI = %d", v221, v222, v223, v224, v225, v226, v227, v228, *(unsigned int *)(a2 + 184));
  v237 = *(unsigned int *)(a2 + 188);
  if ( (v237 & 0x80) != 0 )
    v237 += 255LL;
  DP_PRINT_STATS("Average Packet RSSI = %lu", v229, v230, v231, v232, v233, v234, v235, v236, v237 >> 8);
  DP_PRINT_STATS(
    "Dropped At FW: Removed Pkts = %llu",
    v238,
    v239,
    v240,
    v241,
    v242,
    v243,
    v244,
    v245,
    *(_QWORD *)(a2 + 760));
  DP_PRINT_STATS(
    "Release source not TQM = %u",
    v246,
    v247,
    v248,
    v249,
    v250,
    v251,
    v252,
    v253,
    *(unsigned int *)(a2 + 2072));
  if ( v12 && !(unsigned int)wlan_cfg_get_dp_pdev_nss_enabled(*(_QWORD *)(v12 + 288)) )
    DP_PRINT_STATS(
      "Dropped At FW: Removed bytes = %llu",
      v254,
      v255,
      v256,
      v257,
      v258,
      v259,
      v260,
      v261,
      *(_QWORD *)(a2 + 768));
  DP_PRINT_STATS(
    "Dropped At FW: Removed transmitted = %llu",
    v254,
    v255,
    v256,
    v257,
    v258,
    v259,
    v260,
    v261,
    *(_QWORD *)(a2 + 784));
  DP_PRINT_STATS(
    "Dropped At FW: Removed Untransmitted = %d",
    v262,
    v263,
    v264,
    v265,
    v266,
    v267,
    v268,
    v269,
    *(unsigned int *)(a2 + 776));
  DP_PRINT_STATS(
    "Dropped At FW: removed untransmitted fw_reason1 = %u",
    v270,
    v271,
    v272,
    v273,
    v274,
    v275,
    v276,
    v277,
    *(unsigned int *)(a2 + 804));
  DP_PRINT_STATS(
    "Dropped At FW: removed untransmitted fw_reason2 = %u",
    v278,
    v279,
    v280,
    v281,
    v282,
    v283,
    v284,
    v285,
    *(unsigned int *)(a2 + 808));
  DP_PRINT_STATS(
    "Dropped At FW: removed untransmitted fw_reason3 = %u",
    v286,
    v287,
    v288,
    v289,
    v290,
    v291,
    v292,
    v293,
    *(unsigned int *)(a2 + 812));
  DP_PRINT_STATS(
    "Dropped At FW:removed untransmitted disable queue = %u",
    v294,
    v295,
    v296,
    v297,
    v298,
    v299,
    v300,
    v301,
    *(unsigned int *)(a2 + 816));
  DP_PRINT_STATS(
    "Dropped At FW: removed untransmitted no match = %u",
    v302,
    v303,
    v304,
    v305,
    v306,
    v307,
    v308,
    v309,
    *(unsigned int *)(a2 + 820));
  DP_PRINT_STATS(
    "Dropped due to HW threshold criteria = %u",
    v310,
    v311,
    v312,
    v313,
    v314,
    v315,
    v316,
    v317,
    *(unsigned int *)(a2 + 824));
  DP_PRINT_STATS(
    "Dropped due Link desc not available drop in HW = %u",
    v318,
    v319,
    v320,
    v321,
    v322,
    v323,
    v324,
    v325,
    *(unsigned int *)(a2 + 828));
  DP_PRINT_STATS(
    "Drop bit set or invalid flow = %u",
    v326,
    v327,
    v328,
    v329,
    v330,
    v331,
    v332,
    v333,
    *(unsigned int *)(a2 + 832));
  DP_PRINT_STATS(
    "MCAST vdev drop in HW = %u",
    v334,
    v335,
    v336,
    v337,
    v338,
    v339,
    v340,
    v341,
    *(unsigned int *)(a2 + 836));
  DP_PRINT_STATS("Dropped : Age Out = %d", v342, v343, v344, v345, v346, v347, v348, v349, *(unsigned int *)(a2 + 800));
  DP_PRINT_STATS(
    "Dropped : Invalid Reason = %u",
    v350,
    v351,
    v352,
    v353,
    v354,
    v355,
    v356,
    v357,
    *(unsigned int *)(a2 + 840));
  DP_PRINT_STATS("NAWDS : ", v358, v359, v360, v361, v362, v363, v364, v365);
  DP_PRINT_STATS(
    "Nawds multicast Drop Tx Packet = %d",
    v366,
    v367,
    v368,
    v369,
    v370,
    v371,
    v372,
    v373,
    *(unsigned int *)(a2 + 104));
  DP_PRINT_STATS(
    "\tNawds multicast  Tx Packet Count = %llu",
    v374,
    v375,
    v376,
    v377,
    v378,
    v379,
    v380,
    v381,
    *(_QWORD *)(a2 + 72));
  DP_PRINT_STATS(
    "\tNawds multicast  Tx Packet Bytes = %llu",
    v382,
    v383,
    v384,
    v385,
    v386,
    v387,
    v388,
    v389,
    *(_QWORD *)(a2 + 80));
  DP_PRINT_STATS("PPDU's = %d", v390, v391, v392, v393, v394, v395, v396, v397, *(unsigned int *)(a2 + 984));
  DP_PRINT_STATS(
    "Number of PPDU's with Punctured Preamble = %d",
    v398,
    v399,
    v400,
    v401,
    v402,
    v403,
    v404,
    v405,
    *(unsigned int *)(a2 + 644));
  DP_PRINT_STATS("MPDU's Successful = %d", v406, v407, v408, v409, v410, v411, v412, v413, *(unsigned int *)(a2 + 988));
  DP_PRINT_STATS("MPDU's Tried = %d", v414, v415, v416, v417, v418, v419, v420, v421, *(unsigned int *)(a2 + 992));
  DP_PRINT_STATS("Rate Info:", v422, v423, v424, v425, v426, v427, v428, v429);
  dp_print_common_rates_info(a2 + 216, v430, v431, v432, v433, v434, v435, v436, v437);
  DP_PRINT_STATS(
    "SGI = 0.8us %d 0.4us %d 1.6us %d 3.2us %d",
    v438,
    v439,
    v440,
    v441,
    v442,
    v443,
    v444,
    v445,
    *(unsigned int *)(a2 + 624),
    *(unsigned int *)(a2 + 628),
    *(unsigned int *)(a2 + 632),
    *(unsigned int *)(a2 + 636));
  DP_PRINT_STATS("Wireless Mutlimedia ", v446, v447, v448, v449, v450, v451, v452, v453);
  DP_PRINT_STATS("\t Best effort = %d", v454, v455, v456, v457, v458, v459, v460, v461, *(unsigned int *)(a2 + 712));
  DP_PRINT_STATS("\t Background= %d", v462, v463, v464, v465, v466, v467, v468, v469, *(unsigned int *)(a2 + 716));
  DP_PRINT_STATS("\t Video = %d", v470, v471, v472, v473, v474, v475, v476, v477, *(unsigned int *)(a2 + 720));
  DP_PRINT_STATS("\t Voice = %d", v478, v479, v480, v481, v482, v483, v484, v485, *(unsigned int *)(a2 + 724));
  DP_PRINT_STATS("Excess Retries per AC ", v486, v487, v488, v489, v490, v491, v492, v493);
  DP_PRINT_STATS("\t Best effort = %d", v494, v495, v496, v497, v498, v499, v500, v501, *(unsigned int *)(a2 + 728));
  DP_PRINT_STATS("\t Background= %d", v502, v503, v504, v505, v506, v507, v508, v509, *(unsigned int *)(a2 + 732));
  DP_PRINT_STATS("\t Video = %d", v510, v511, v512, v513, v514, v515, v516, v517, *(unsigned int *)(a2 + 736));
  DP_PRINT_STATS("\t Voice = %d", v518, v519, v520, v521, v522, v523, v524, v525, *(unsigned int *)(a2 + 740));
  dp_print_nss(v1631, a2 + 648);
  DP_PRINT_STATS("NSS(1-8) = %s", v526, v527, v528, v529, v530, v531, v532, v533, v1631);
  DP_PRINT_STATS("Transmit Type :", v534, v535, v536, v537, v538, v539, v540, v541);
  DP_PRINT_STATS(
    "MSDUs Success: SU %d, MU_MIMO %d, MU_OFDMA %d, MU_MIMO_OFDMA %d",
    v542,
    v543,
    v544,
    v545,
    v546,
    v547,
    v548,
    v549,
    *(unsigned int *)(a2 + 996),
    *(unsigned int *)(a2 + 1008),
    *(unsigned int *)(a2 + 1020),
    *(unsigned int *)(a2 + 1032));
  DP_PRINT_STATS(
    "MPDUs Success: SU %d, MU_MIMO %d, MU_OFDMA %d, MU_MIMO_OFDMA %d",
    v550,
    v551,
    v552,
    v553,
    v554,
    v555,
    v556,
    v557,
    *(unsigned int *)(a2 + 1000),
    *(unsigned int *)(a2 + 1012),
    *(unsigned int *)(a2 + 1024),
    *(unsigned int *)(a2 + 1036));
  DP_PRINT_STATS(
    "MPDUs Tried: SU %d, MU_MIMO %d, MU_OFDMA %d, MU_MIMO_OFDMA %d",
    v558,
    v559,
    v560,
    v561,
    v562,
    v563,
    v564,
    v565,
    *(unsigned int *)(a2 + 1004),
    *(unsigned int *)(a2 + 1016),
    *(unsigned int *)(a2 + 1028),
    *(unsigned int *)(a2 + 1040));
  v566 = 0;
  do
  {
    v575 = 0;
    v576 = 0;
    v577 = v566;
    do
    {
      if ( v576 > 0x60 )
        __break(0x5512u);
      v578 = snprintf((char *)v1630 + v576, 96 - v576, " %d", *(_DWORD *)(a2 + 4 * v577 + 1104));
      v566 = v577 + 1;
      if ( v575 > 0xE )
        break;
      v587 = v577 >= 0x3F;
      v576 += v578;
      ++v575;
      ++v577;
    }
    while ( !v587 );
    DP_PRINT_STATS(
      "User position list for GID %02d->%d: [%s]",
      v579,
      v580,
      v581,
      v582,
      v583,
      v584,
      v585,
      v586,
      (unsigned int)v566 - 16,
      (unsigned int)v566 - 1,
      v1630);
  }
  while ( (unsigned __int8)(v566 - 1) < 0x3Fu );
  DP_PRINT_STATS(
    "Last Packet RU index [%d], Size [%d]",
    v567,
    v568,
    v569,
    v570,
    v571,
    v572,
    v573,
    v574,
    *(unsigned int *)(a2 + 1360),
    *(unsigned int *)(a2 + 1364));
  DP_PRINT_STATS("Aggregation:", v588, v589, v590, v591, v592, v593, v594, v595);
  DP_PRINT_STATS(
    "Number of Msdu's Part of Amsdu = %d",
    v596,
    v597,
    v598,
    v599,
    v600,
    v601,
    v602,
    v603,
    *(unsigned int *)(a2 + 136));
  DP_PRINT_STATS(
    "Number of Msdu's With No Msdu Level Aggregation = %d",
    v604,
    v605,
    v606,
    v607,
    v608,
    v609,
    v610,
    v611,
    *(unsigned int *)(a2 + 132));
  DP_PRINT_STATS("Bytes and Packets transmitted  in last one sec:", v612, v613, v614, v615, v616, v617, v618, v619);
  DP_PRINT_STATS(
    "\tBytes transmitted in last sec: %d",
    v620,
    v621,
    v622,
    v623,
    v624,
    v625,
    v626,
    v627,
    *(unsigned int *)(a2 + 200));
  DP_PRINT_STATS(
    "\tData transmitted in last sec: %d",
    v628,
    v629,
    v630,
    v631,
    v632,
    v633,
    v634,
    v635,
    *(unsigned int *)(a2 + 204));
  DP_PRINT_STATS(
    "EAPOL Tx comp Success = %d",
    v636,
    v637,
    v638,
    v639,
    v640,
    v641,
    v642,
    v643,
    *(unsigned int *)(a2 + 2172));
  DP_PRINT_STATS("EAPOL Tx comp Failures:", v644, v645, v646, v647, v648, v649, v650, v651);
  DP_PRINT_STATS(
    "\tFail reason:DROP = %d",
    v652,
    v653,
    v654,
    v655,
    v656,
    v657,
    v658,
    v659,
    *(unsigned int *)(a2 + 2176));
  DP_PRINT_STATS("\tFail reason:TTL = %d", v660, v661, v662, v663, v664, v665, v666, v667, *(unsigned int *)(a2 + 2180));
  DP_PRINT_STATS(
    "\tFail reason:REINJECT = %d",
    v668,
    v669,
    v670,
    v671,
    v672,
    v673,
    v674,
    v675,
    *(unsigned int *)(a2 + 2184));
  DP_PRINT_STATS(
    "\tFail reason:INSPECT = %d",
    v676,
    v677,
    v678,
    v679,
    v680,
    v681,
    v682,
    v683,
    *(unsigned int *)(a2 + 2188));
  DP_PRINT_STATS(
    "\tFail reason:MEC NOTIFY = %d",
    v684,
    v685,
    v686,
    v687,
    v688,
    v689,
    v690,
    v691,
    *(unsigned int *)(a2 + 2192));
  DP_PRINT_STATS(
    "\tFail reason:VDEVID MISMATCH = %d",
    v692,
    v693,
    v694,
    v695,
    v696,
    v697,
    v698,
    v699,
    *(unsigned int *)(a2 + 2196));
  DP_PRINT_STATS(
    "Rekey EAPOL Tx comp Success = %d",
    v700,
    v701,
    v702,
    v703,
    v704,
    v705,
    v706,
    v707,
    *(unsigned int *)(a2 + 2200));
  DP_PRINT_STATS("Rekey EAPOL Tx comp Failures:", v708, v709, v710, v711, v712, v713, v714, v715);
  DP_PRINT_STATS(
    "\tFail reason:DROP = %d",
    v716,
    v717,
    v718,
    v719,
    v720,
    v721,
    v722,
    v723,
    *(unsigned int *)(a2 + 2204));
  DP_PRINT_STATS("\tFail reason:TTL = %d", v724, v725, v726, v727, v728, v729, v730, v731, *(unsigned int *)(a2 + 2208));
  DP_PRINT_STATS(
    "\tFail reason:REINJECT = %d",
    v732,
    v733,
    v734,
    v735,
    v736,
    v737,
    v738,
    v739,
    *(unsigned int *)(a2 + 2212));
  DP_PRINT_STATS(
    "\tFail reason:INSPECT = %d",
    v740,
    v741,
    v742,
    v743,
    v744,
    v745,
    v746,
    v747,
    *(unsigned int *)(a2 + 2216));
  DP_PRINT_STATS(
    "\tFail reason:MEC NOTIFY = %d",
    v748,
    v749,
    v750,
    v751,
    v752,
    v753,
    v754,
    v755,
    *(unsigned int *)(a2 + 2220));
  DP_PRINT_STATS(
    "\tFail reason:VDEVID MISMATCH = %d",
    v756,
    v757,
    v758,
    v759,
    v760,
    v761,
    v762,
    v763,
    *(unsigned int *)(a2 + 2224));
  if ( v12 )
  {
    v772 = *(_DWORD **)(*(_QWORD *)(v12 + 8) + 1608LL);
    if ( v772 )
    {
      if ( *(v772 - 1) != -1009236478 )
        __break(0x8228u);
      ((void (__fastcall *)(__int64, _QWORD))v772)(a2, 0);
    }
  }
  DP_PRINT_STATS("Tx PPDU Duration: %llu", v764, v765, v766, v767, v768, v769, v770, v771, *(_QWORD *)(a2 + 2744));
  if ( *(_DWORD *)(a1 + 408) == 2 )
    DP_PRINT_STATS(
      "TX Invalid Link ID Packet Count = %u",
      v773,
      v774,
      v775,
      v776,
      v777,
      v778,
      v779,
      v780,
      *(unsigned int *)(a2 + 2096));
  DP_PRINT_STATS("Node Rx Stats:", v773, v774, v775, v776, v777, v778, v779, v780);
  DP_PRINT_STATS("Packets Sent To Stack = %llu", v781, v782, v783, v784, v785, v786, v787, v788, *(_QWORD *)(a2 + 3048));
  DP_PRINT_STATS("Bytes Sent To Stack = %llu", v789, v790, v791, v792, v793, v794, v795, v796, *(_QWORD *)(a2 + 3056));
  DP_PRINT_STATS("Ring Id = %d", v797, v798, v799, v800, v801, v802, v803, v804, 0);
  DP_PRINT_STATS("\tPackets Received = %llu", v805, v806, v807, v808, v809, v810, v811, v812, *(_QWORD *)(a2 + 2768));
  DP_PRINT_STATS("\tBytes Received = %llu", v813, v814, v815, v816, v817, v818, v819, v820, *(_QWORD *)(a2 + 2776));
  DP_PRINT_STATS("Ring Id = %d", v821, v822, v823, v824, v825, v826, v827, v828, 1);
  DP_PRINT_STATS("\tPackets Received = %llu", v829, v830, v831, v832, v833, v834, v835, v836, *(_QWORD *)(a2 + 2784));
  DP_PRINT_STATS("\tBytes Received = %llu", v837, v838, v839, v840, v841, v842, v843, v844, *(_QWORD *)(a2 + 2792));
  DP_PRINT_STATS("Ring Id = %d", v845, v846, v847, v848, v849, v850, v851, v852, 2);
  DP_PRINT_STATS("\tPackets Received = %llu", v853, v854, v855, v856, v857, v858, v859, v860, *(_QWORD *)(a2 + 2800));
  DP_PRINT_STATS("\tBytes Received = %llu", v861, v862, v863, v864, v865, v866, v867, v868, *(_QWORD *)(a2 + 2808));
  DP_PRINT_STATS("Ring Id = %d", v869, v870, v871, v872, v873, v874, v875, v876, 3);
  DP_PRINT_STATS("\tPackets Received = %llu", v877, v878, v879, v880, v881, v882, v883, v884, *(_QWORD *)(a2 + 2816));
  DP_PRINT_STATS("\tBytes Received = %llu", v885, v886, v887, v888, v889, v890, v891, v892, *(_QWORD *)(a2 + 2824));
  DP_PRINT_STATS("Ring Id = %d", v893, v894, v895, v896, v897, v898, v899, v900, 4);
  DP_PRINT_STATS("\tPackets Received = %llu", v901, v902, v903, v904, v905, v906, v907, v908, *(_QWORD *)(a2 + 2832));
  DP_PRINT_STATS("\tBytes Received = %llu", v909, v910, v911, v912, v913, v914, v915, v916, *(_QWORD *)(a2 + 2840));
  DP_PRINT_STATS("Ring Id = %d", v917, v918, v919, v920, v921, v922, v923, v924, 5);
  DP_PRINT_STATS("\tPackets Received = %llu", v925, v926, v927, v928, v929, v930, v931, v932, *(_QWORD *)(a2 + 2848));
  DP_PRINT_STATS("\tBytes Received = %llu", v933, v934, v935, v936, v937, v938, v939, v940, *(_QWORD *)(a2 + 2856));
  DP_PRINT_STATS("Ring Id = %d", v941, v942, v943, v944, v945, v946, v947, v948, 6);
  DP_PRINT_STATS("\tPackets Received = %llu", v949, v950, v951, v952, v953, v954, v955, v956, *(_QWORD *)(a2 + 2864));
  DP_PRINT_STATS("\tBytes Received = %llu", v957, v958, v959, v960, v961, v962, v963, v964, *(_QWORD *)(a2 + 2872));
  DP_PRINT_STATS("Ring Id = %d", v965, v966, v967, v968, v969, v970, v971, v972, 7);
  DP_PRINT_STATS("\tPackets Received = %llu", v973, v974, v975, v976, v977, v978, v979, v980, *(_QWORD *)(a2 + 2880));
  DP_PRINT_STATS("\tBytes Received = %llu", v981, v982, v983, v984, v985, v986, v987, v988, *(_QWORD *)(a2 + 2888));
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
    *(_QWORD *)(a2 + 2912),
    *(_QWORD *)(a2 + 2920));
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
    *(_QWORD *)(a2 + 2928),
    *(_QWORD *)(a2 + 2936));
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
    *(_QWORD *)(a2 + 2944));
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
    *(_QWORD *)(a2 + 2952));
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
    *(_QWORD *)(a2 + 2960));
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
    *(_QWORD *)(a2 + 2968));
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
    *(_QWORD *)(a2 + 2976));
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
    *(_QWORD *)(a2 + 2984));
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
    *(_QWORD *)(a2 + 4208));
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
    *(_QWORD *)(a2 + 4216));
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
    *(_QWORD *)(a2 + 3072));
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
    *(_QWORD *)(a2 + 3080));
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
    *(_QWORD *)(a2 + 3088));
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
    *(_QWORD *)(a2 + 3096));
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
    *(unsigned int *)(a2 + 3104));
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
    *(_QWORD *)(a2 + 2992));
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
    *(_QWORD *)(a2 + 3000));
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
    *(unsigned int *)(a2 + 3112));
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
    *(unsigned int *)(a2 + 3116));
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
    *(unsigned int *)(a2 + 3124));
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
    *(unsigned int *)(a2 + 3128));
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
    *(unsigned int *)(a2 + 3132));
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
    *(unsigned int *)(a2 + 3136));
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
    *(unsigned int *)(a2 + 4004));
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
    *(unsigned int *)(a2 + 4008));
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
    *(unsigned int *)(a2 + 4012));
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
    *(unsigned int *)(a2 + 4016));
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
    *(unsigned int *)(a2 + 4080));
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
    *(unsigned int *)(a2 + 4224));
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
    *(unsigned int *)(a2 + 3008));
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
    *(unsigned int *)(a2 + 4452));
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
    *(unsigned int *)(a2 + 3580),
    *(unsigned int *)(a2 + 3584),
    *(unsigned int *)(a2 + 3588),
    *(unsigned int *)(a2 + 3592));
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
    *(unsigned int *)(a2 + 3140));
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
    *(unsigned int *)(a2 + 3144));
  DP_PRINT_STATS("\t Video = %d", v1277, v1278, v1279, v1280, v1281, v1282, v1283, v1284, *(unsigned int *)(a2 + 3148));
  DP_PRINT_STATS("\t Voice = %d", v1285, v1286, v1287, v1288, v1289, v1290, v1291, v1292, *(unsigned int *)(a2 + 3152));
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
    *(unsigned int *)(a2 + 4088));
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
    *(unsigned int *)(a2 + 4084));
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
    *(unsigned int *)(a2 + 3156),
    *(unsigned int *)(a2 + 3160),
    *(unsigned int *)(a2 + 3164),
    *(unsigned int *)(a2 + 3168));
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
    *(unsigned int *)(a2 + 3740),
    *(unsigned int *)(a2 + 3744),
    *(unsigned int *)(a2 + 3748),
    *(unsigned int *)(a2 + 3752));
  dp_print_common_rates_info(a2 + 3172, v1341, v1342, v1343, v1344, v1345, v1346, v1347, v1348);
  DP_PRINT_STATS("PPDU Count", v1349, v1350, v1351, v1352, v1353, v1354, v1355, v1356);
  v1365 = "HE MCS 0 (BPSK 1/2)     ";
  for ( i = 3672; i != 3740; i += 4 )
  {
    if ( v1365[34] )
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
        v1365,
        *(unsigned int *)(a2 + i));
    v1365 += 35;
  }
  DP_PRINT_STATS("\n", v1357, v1358, v1359, v1360, v1361, v1362, v1363, v1364);
  DP_PRINT_STATS("PPDU Count", v1367, v1368, v1369, v1370, v1371, v1372, v1373, v1374);
  v1383 = "HE MU-MIMO MCS 0 (BPSK 1/2)     ";
  for ( j = 3796; j != 3864; j += 4 )
  {
    if ( v1383[34] )
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
        v1383,
        *(unsigned int *)(a2 + j));
    v1383 += 35;
  }
  DP_PRINT_STATS("\n", v1375, v1376, v1377, v1378, v1379, v1380, v1381, v1382);
  v1393 = "HE OFDMA MCS 0 (BPSK 1/2)     ";
  for ( k = 3904; k != 3972; k += 4 )
  {
    if ( v1393[34] )
      DP_PRINT_STATS(
        "\t%s = %d",
        v1385,
        v1386,
        v1387,
        v1388,
        v1389,
        v1390,
        v1391,
        v1392,
        v1393,
        *(unsigned int *)(a2 + k));
    v1393 += 35;
  }
  DP_PRINT_STATS("\n", v1385, v1386, v1387, v1388, v1389, v1390, v1391, v1392);
  dp_print_nss(v1631, a2 + 3600);
  DP_PRINT_STATS("MSDU Count", v1395, v1396, v1397, v1398, v1399, v1400, v1401, v1402);
  DP_PRINT_STATS("\tNSS(1-8) = %s", v1403, v1404, v1405, v1406, v1407, v1408, v1409, v1410, v1631);
  DP_PRINT_STATS("reception mode SU", v1411, v1412, v1413, v1414, v1415, v1416, v1417, v1418);
  dp_print_nss(v1631, a2 + 3632);
  DP_PRINT_STATS("\tPPDU Count", v1419, v1420, v1421, v1422, v1423, v1424, v1425, v1426);
  DP_PRINT_STATS("\tNSS(1-8) = %s", v1427, v1428, v1429, v1430, v1431, v1432, v1433, v1434, v1631);
  DP_PRINT_STATS(
    "\tMPDU OK = %d, MPDU Fail = %d",
    v1435,
    v1436,
    v1437,
    v1438,
    v1439,
    v1440,
    v1441,
    v1442,
    *(unsigned int *)(a2 + 3664),
    *(unsigned int *)(a2 + 3668));
  DP_PRINT_STATS("reception mode %s", v1443, v1444, v1445, v1446, v1447, v1448, v1449, v1450, mu_reception_mode[0]);
  dp_print_nss(v1631, a2 + 3756);
  DP_PRINT_STATS("\tPPDU Count", v1451, v1452, v1453, v1454, v1455, v1456, v1457, v1458);
  DP_PRINT_STATS("\tNSS(1-8) = %s", v1459, v1460, v1461, v1462, v1463, v1464, v1465, v1466, v1631);
  DP_PRINT_STATS(
    "\tMPDU OK = %d, MPDU Fail = %d",
    v1467,
    v1468,
    v1469,
    v1470,
    v1471,
    v1472,
    v1473,
    v1474,
    *(unsigned int *)(a2 + 3788),
    *(unsigned int *)(a2 + 3792));
  DP_PRINT_STATS("reception mode %s", v1475, v1476, v1477, v1478, v1479, v1480, v1481, v1482, off_16240[0]);
  dp_print_nss(v1631, a2 + 3864);
  DP_PRINT_STATS("\tPPDU Count", v1483, v1484, v1485, v1486, v1487, v1488, v1489, v1490);
  DP_PRINT_STATS("\tNSS(1-8) = %s", v1491, v1492, v1493, v1494, v1495, v1496, v1497, v1498, v1631);
  DP_PRINT_STATS(
    "\tMPDU OK = %d, MPDU Fail = %d",
    v1499,
    v1500,
    v1501,
    v1502,
    v1503,
    v1504,
    v1505,
    v1506,
    *(unsigned int *)(a2 + 3896),
    *(unsigned int *)(a2 + 3900));
  DP_PRINT_STATS("Aggregation:", v1507, v1508, v1509, v1510, v1511, v1512, v1513, v1514);
  DP_PRINT_STATS(
    "\tMsdu's Part of Ampdu = %d",
    v1515,
    v1516,
    v1517,
    v1518,
    v1519,
    v1520,
    v1521,
    v1522,
    *(unsigned int *)(a2 + 4008));
  DP_PRINT_STATS(
    "\tMsdu's With No Mpdu Level Aggregation = %d",
    v1523,
    v1524,
    v1525,
    v1526,
    v1527,
    v1528,
    v1529,
    v1530,
    *(unsigned int *)(a2 + 4004));
  DP_PRINT_STATS(
    "\tMsdu's Part of Amsdu = %d",
    v1531,
    v1532,
    v1533,
    v1534,
    v1535,
    v1536,
    v1537,
    v1538,
    *(unsigned int *)(a2 + 4016));
  DP_PRINT_STATS(
    "\tMsdu's With No Msdu Level Aggregation = %d",
    v1539,
    v1540,
    v1541,
    v1542,
    v1543,
    v1544,
    v1545,
    v1546,
    *(unsigned int *)(a2 + 4012));
  DP_PRINT_STATS("Bytes and Packets received in last one sec:", v1547, v1548, v1549, v1550, v1551, v1552, v1553, v1554);
  DP_PRINT_STATS(
    "\tBytes received in last sec: %d",
    v1555,
    v1556,
    v1557,
    v1558,
    v1559,
    v1560,
    v1561,
    v1562,
    *(unsigned int *)(a2 + 4072));
  DP_PRINT_STATS(
    "\tData received in last sec: %d",
    v1563,
    v1564,
    v1565,
    v1566,
    v1567,
    v1568,
    v1569,
    v1570,
    *(unsigned int *)(a2 + 4076));
  DP_PRINT_STATS(
    "MEC Packet Drop = %llu",
    v1571,
    v1572,
    v1573,
    v1574,
    v1575,
    v1576,
    v1577,
    v1578,
    *(_QWORD *)(a2 + 3016));
  DP_PRINT_STATS("MEC Byte Drop = %llu", v1579, v1580, v1581, v1582, v1583, v1584, v1585, v1586, *(_QWORD *)(a2 + 3024));
  DP_PRINT_STATS(
    "Multipass Rx Packet Drop = %d",
    v1587,
    v1588,
    v1589,
    v1590,
    v1591,
    v1592,
    v1593,
    v1594,
    *(unsigned int *)(a2 + 4124));
  DP_PRINT_STATS(
    "Peer Unauth Rx Packet Drop = %d",
    v1595,
    v1596,
    v1597,
    v1598,
    v1599,
    v1600,
    v1601,
    v1602,
    *(unsigned int *)(a2 + 4128));
  DP_PRINT_STATS(
    "Policy Check Rx Packet Drop = %d",
    v1603,
    v1604,
    v1605,
    v1606,
    v1607,
    v1608,
    v1609,
    v1610,
    *(unsigned int *)(a2 + 4132));
  if ( v12 )
  {
    v1619 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(v12 + 8) + 1608LL);
    if ( v1619 )
    {
      if ( *((_DWORD *)v1619 - 1) != -1009236478 )
        __break(0x8228u);
      v1619(a2, 1);
    }
  }
  result = DP_PRINT_STATS(
             "Rx PPDU Duration: %llu",
             v1611,
             v1612,
             v1613,
             v1614,
             v1615,
             v1616,
             v1617,
             v1618,
             *(_QWORD *)(a2 + 4528));
  if ( *(_DWORD *)(a1 + 408) == 2 )
    result = DP_PRINT_STATS(
               "RX Invalid Link ID Packet Count = %u",
               v1621,
               v1622,
               v1623,
               v1624,
               v1625,
               v1626,
               v1627,
               v1628,
               *(unsigned int *)(a2 + 4464));
  if ( v12 )
    result = wlan_cfg_get_dp_proto_stats(*(_QWORD *)(*(_QWORD *)(v12 + 8) + 40LL));
  _ReadStatusReg(SP_EL0);
  return result;
}
