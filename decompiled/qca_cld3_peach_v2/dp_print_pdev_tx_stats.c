__int64 __fastcall dp_print_pdev_tx_stats(
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
  unsigned __int8 *v10; // x22
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
  double v243; // d0
  double v244; // d1
  double v245; // d2
  double v246; // d3
  double v247; // d4
  double v248; // d5
  double v249; // d6
  double v250; // d7
  double v251; // d0
  double v252; // d1
  double v253; // d2
  double v254; // d3
  double v255; // d4
  double v256; // d5
  double v257; // d6
  double v258; // d7
  double v259; // d0
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  double v267; // d0
  double v268; // d1
  double v269; // d2
  double v270; // d3
  double v271; // d4
  double v272; // d5
  double v273; // d6
  double v274; // d7
  double v275; // d0
  double v276; // d1
  double v277; // d2
  double v278; // d3
  double v279; // d4
  double v280; // d5
  double v281; // d6
  double v282; // d7
  double v283; // d0
  double v284; // d1
  double v285; // d2
  double v286; // d3
  double v287; // d4
  double v288; // d5
  double v289; // d6
  double v290; // d7
  double v291; // d0
  double v292; // d1
  double v293; // d2
  double v294; // d3
  double v295; // d4
  double v296; // d5
  double v297; // d6
  double v298; // d7
  double v299; // d0
  double v300; // d1
  double v301; // d2
  double v302; // d3
  double v303; // d4
  double v304; // d5
  double v305; // d6
  double v306; // d7
  double v307; // d0
  double v308; // d1
  double v309; // d2
  double v310; // d3
  double v311; // d4
  double v312; // d5
  double v313; // d6
  double v314; // d7
  double v315; // d0
  double v316; // d1
  double v317; // d2
  double v318; // d3
  double v319; // d4
  double v320; // d5
  double v321; // d6
  double v322; // d7
  double v323; // d0
  double v324; // d1
  double v325; // d2
  double v326; // d3
  double v327; // d4
  double v328; // d5
  double v329; // d6
  double v330; // d7
  double v331; // d0
  double v332; // d1
  double v333; // d2
  double v334; // d3
  double v335; // d4
  double v336; // d5
  double v337; // d6
  double v338; // d7
  double v339; // d0
  double v340; // d1
  double v341; // d2
  double v342; // d3
  double v343; // d4
  double v344; // d5
  double v345; // d6
  double v346; // d7
  double v347; // d0
  double v348; // d1
  double v349; // d2
  double v350; // d3
  double v351; // d4
  double v352; // d5
  double v353; // d6
  double v354; // d7
  double v355; // d0
  double v356; // d1
  double v357; // d2
  double v358; // d3
  double v359; // d4
  double v360; // d5
  double v361; // d6
  double v362; // d7
  double v363; // d0
  double v364; // d1
  double v365; // d2
  double v366; // d3
  double v367; // d4
  double v368; // d5
  double v369; // d6
  double v370; // d7
  double v371; // d0
  double v372; // d1
  double v373; // d2
  double v374; // d3
  double v375; // d4
  double v376; // d5
  double v377; // d6
  double v378; // d7
  double v379; // d0
  double v380; // d1
  double v381; // d2
  double v382; // d3
  double v383; // d4
  double v384; // d5
  double v385; // d6
  double v386; // d7
  double v387; // d0
  double v388; // d1
  double v389; // d2
  double v390; // d3
  double v391; // d4
  double v392; // d5
  double v393; // d6
  double v394; // d7
  double v395; // d0
  double v396; // d1
  double v397; // d2
  double v398; // d3
  double v399; // d4
  double v400; // d5
  double v401; // d6
  double v402; // d7
  double v403; // d0
  double v404; // d1
  double v405; // d2
  double v406; // d3
  double v407; // d4
  double v408; // d5
  double v409; // d6
  double v410; // d7
  double v411; // d0
  double v412; // d1
  double v413; // d2
  double v414; // d3
  double v415; // d4
  double v416; // d5
  double v417; // d6
  double v418; // d7
  double v419; // d0
  double v420; // d1
  double v421; // d2
  double v422; // d3
  double v423; // d4
  double v424; // d5
  double v425; // d6
  double v426; // d7
  double v427; // d0
  double v428; // d1
  double v429; // d2
  double v430; // d3
  double v431; // d4
  double v432; // d5
  double v433; // d6
  double v434; // d7
  double v435; // d0
  double v436; // d1
  double v437; // d2
  double v438; // d3
  double v439; // d4
  double v440; // d5
  double v441; // d6
  double v442; // d7
  double v443; // d0
  double v444; // d1
  double v445; // d2
  double v446; // d3
  double v447; // d4
  double v448; // d5
  double v449; // d6
  double v450; // d7
  double v451; // d0
  double v452; // d1
  double v453; // d2
  double v454; // d3
  double v455; // d4
  double v456; // d5
  double v457; // d6
  double v458; // d7
  double v459; // d0
  double v460; // d1
  double v461; // d2
  double v462; // d3
  double v463; // d4
  double v464; // d5
  double v465; // d6
  double v466; // d7
  double v467; // d0
  double v468; // d1
  double v469; // d2
  double v470; // d3
  double v471; // d4
  double v472; // d5
  double v473; // d6
  double v474; // d7
  double v475; // d0
  double v476; // d1
  double v477; // d2
  double v478; // d3
  double v479; // d4
  double v480; // d5
  double v481; // d6
  double v482; // d7
  double v483; // d0
  double v484; // d1
  double v485; // d2
  double v486; // d3
  double v487; // d4
  double v488; // d5
  double v489; // d6
  double v490; // d7
  double v491; // d0
  double v492; // d1
  double v493; // d2
  double v494; // d3
  double v495; // d4
  double v496; // d5
  double v497; // d6
  double v498; // d7
  double v499; // d0
  double v500; // d1
  double v501; // d2
  double v502; // d3
  double v503; // d4
  double v504; // d5
  double v505; // d6
  double v506; // d7
  double v507; // d0
  double v508; // d1
  double v509; // d2
  double v510; // d3
  double v511; // d4
  double v512; // d5
  double v513; // d6
  double v514; // d7
  double v515; // d0
  double v516; // d1
  double v517; // d2
  double v518; // d3
  double v519; // d4
  double v520; // d5
  double v521; // d6
  double v522; // d7
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
  double v539; // d0
  double v540; // d1
  double v541; // d2
  double v542; // d3
  double v543; // d4
  double v544; // d5
  double v545; // d6
  double v546; // d7
  double v547; // d0
  double v548; // d1
  double v549; // d2
  double v550; // d3
  double v551; // d4
  double v552; // d5
  double v553; // d6
  double v554; // d7
  double v555; // d0
  double v556; // d1
  double v557; // d2
  double v558; // d3
  double v559; // d4
  double v560; // d5
  double v561; // d6
  double v562; // d7
  double v563; // d0
  double v564; // d1
  double v565; // d2
  double v566; // d3
  double v567; // d4
  double v568; // d5
  double v569; // d6
  double v570; // d7
  double v571; // d0
  double v572; // d1
  double v573; // d2
  double v574; // d3
  double v575; // d4
  double v576; // d5
  double v577; // d6
  double v578; // d7
  double v579; // d0
  double v580; // d1
  double v581; // d2
  double v582; // d3
  double v583; // d4
  double v584; // d5
  double v585; // d6
  double v586; // d7
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
  double v771; // d0
  double v772; // d1
  double v773; // d2
  double v774; // d3
  double v775; // d4
  double v776; // d5
  double v777; // d6
  double v778; // d7
  double v779; // d0
  double v780; // d1
  double v781; // d2
  double v782; // d3
  double v783; // d4
  double v784; // d5
  double v785; // d6
  double v786; // d7
  double v787; // d0
  double v788; // d1
  double v789; // d2
  double v790; // d3
  double v791; // d4
  double v792; // d5
  double v793; // d6
  double v794; // d7
  double v795; // d0
  double v796; // d1
  double v797; // d2
  double v798; // d3
  double v799; // d4
  double v800; // d5
  double v801; // d6
  double v802; // d7
  double v803; // d0
  double v804; // d1
  double v805; // d2
  double v806; // d3
  double v807; // d4
  double v808; // d5
  double v809; // d6
  double v810; // d7
  double v811; // d0
  double v812; // d1
  double v813; // d2
  double v814; // d3
  double v815; // d4
  double v816; // d5
  double v817; // d6
  double v818; // d7
  double v819; // d0
  double v820; // d1
  double v821; // d2
  double v822; // d3
  double v823; // d4
  double v824; // d5
  double v825; // d6
  double v826; // d7
  double v827; // d0
  double v828; // d1
  double v829; // d2
  double v830; // d3
  double v831; // d4
  double v832; // d5
  double v833; // d6
  double v834; // d7
  double v835; // d0
  double v836; // d1
  double v837; // d2
  double v838; // d3
  double v839; // d4
  double v840; // d5
  double v841; // d6
  double v842; // d7
  double v843; // d0
  double v844; // d1
  double v845; // d2
  double v846; // d3
  double v847; // d4
  double v848; // d5
  double v849; // d6
  double v850; // d7
  double v851; // d0
  double v852; // d1
  double v853; // d2
  double v854; // d3
  double v855; // d4
  double v856; // d5
  double v857; // d6
  double v858; // d7
  double v859; // d0
  double v860; // d1
  double v861; // d2
  double v862; // d3
  double v863; // d4
  double v864; // d5
  double v865; // d6
  double v866; // d7
  double v867; // d0
  double v868; // d1
  double v869; // d2
  double v870; // d3
  double v871; // d4
  double v872; // d5
  double v873; // d6
  double v874; // d7
  double v875; // d0
  double v876; // d1
  double v877; // d2
  double v878; // d3
  double v879; // d4
  double v880; // d5
  double v881; // d6
  double v882; // d7
  __int64 v883; // x8
  double v884; // d0
  double v885; // d1
  double v886; // d2
  double v887; // d3
  double v888; // d4
  double v889; // d5
  double v890; // d6
  double v891; // d7
  double v892; // d0
  double v893; // d1
  double v894; // d2
  double v895; // d3
  double v896; // d4
  double v897; // d5
  double v898; // d6
  double v899; // d7
  double v900; // d0
  double v901; // d1
  double v902; // d2
  double v903; // d3
  double v904; // d4
  double v905; // d5
  double v906; // d6
  double v907; // d7
  double v908; // d0
  double v909; // d1
  double v910; // d2
  double v911; // d3
  double v912; // d4
  double v913; // d5
  double v914; // d6
  double v915; // d7
  double v916; // d0
  double v917; // d1
  double v918; // d2
  double v919; // d3
  double v920; // d4
  double v921; // d5
  double v922; // d6
  double v923; // d7
  double v924; // d0
  double v925; // d1
  double v926; // d2
  double v927; // d3
  double v928; // d4
  double v929; // d5
  double v930; // d6
  double v931; // d7
  double v932; // d0
  double v933; // d1
  double v934; // d2
  double v935; // d3
  double v936; // d4
  double v937; // d5
  double v938; // d6
  double v939; // d7
  __int64 i; // x21
  __int64 v941; // x8
  __int64 v942; // x8
  void (__fastcall *v943)(_QWORD); // x8
  double v944; // d0
  double v945; // d1
  double v946; // d2
  double v947; // d3
  double v948; // d4
  double v949; // d5
  double v950; // d6
  double v951; // d7
  const char *v952; // x2
  double v953; // d0
  double v954; // d1
  double v955; // d2
  double v956; // d3
  double v957; // d4
  double v958; // d5
  double v959; // d6
  double v960; // d7
  double v961; // d0
  double v962; // d1
  double v963; // d2
  double v964; // d3
  double v965; // d4
  double v966; // d5
  double v967; // d6
  double v968; // d7
  double v969; // d0
  double v970; // d1
  double v971; // d2
  double v972; // d3
  double v973; // d4
  double v974; // d5
  double v975; // d6
  double v976; // d7
  double v977; // d0
  double v978; // d1
  double v979; // d2
  double v980; // d3
  double v981; // d4
  double v982; // d5
  double v983; // d6
  double v984; // d7
  double v985; // d0
  double v986; // d1
  double v987; // d2
  double v988; // d3
  double v989; // d4
  double v990; // d5
  double v991; // d6
  double v992; // d7
  double v993; // d0
  double v994; // d1
  double v995; // d2
  double v996; // d3
  double v997; // d4
  double v998; // d5
  double v999; // d6
  double v1000; // d7
  double v1001; // d0
  double v1002; // d1
  double v1003; // d2
  double v1004; // d3
  double v1005; // d4
  double v1006; // d5
  double v1007; // d6
  double v1008; // d7
  double v1009; // d0
  double v1010; // d1
  double v1011; // d2
  double v1012; // d3
  double v1013; // d4
  double v1014; // d5
  double v1015; // d6
  double v1016; // d7
  double v1017; // d0
  double v1018; // d1
  double v1019; // d2
  double v1020; // d3
  double v1021; // d4
  double v1022; // d5
  double v1023; // d6
  double v1024; // d7
  double v1025; // d0
  double v1026; // d1
  double v1027; // d2
  double v1028; // d3
  double v1029; // d4
  double v1030; // d5
  double v1031; // d6
  double v1032; // d7
  double v1033; // d0
  double v1034; // d1
  double v1035; // d2
  double v1036; // d3
  double v1037; // d4
  double v1038; // d5
  double v1039; // d6
  double v1040; // d7
  double v1041; // d0
  double v1042; // d1
  double v1043; // d2
  double v1044; // d3
  double v1045; // d4
  double v1046; // d5
  double v1047; // d6
  double v1048; // d7
  double v1049; // d0
  double v1050; // d1
  double v1051; // d2
  double v1052; // d3
  double v1053; // d4
  double v1054; // d5
  double v1055; // d6
  double v1056; // d7
  double v1057; // d0
  double v1058; // d1
  double v1059; // d2
  double v1060; // d3
  double v1061; // d4
  double v1062; // d5
  double v1063; // d6
  double v1064; // d7
  double v1065; // d0
  double v1066; // d1
  double v1067; // d2
  double v1068; // d3
  double v1069; // d4
  double v1070; // d5
  double v1071; // d6
  double v1072; // d7

  v10 = (unsigned __int8 *)(a1 + 92208);
  DP_PRINT_STATS("PDEV Tx Stats:\n", a2, a3, a4, a5, a6, a7, a8, a9);
  DP_PRINT_STATS("Received From Stack:", v11, v12, v13, v14, v15, v16, v17, v18);
  DP_PRINT_STATS("\tPackets = %llu", v19, v20, v21, v22, v23, v24, v25, v26, *(_QWORD *)(a1 + 520));
  DP_PRINT_STATS("\tBytes = %llu", v27, v28, v29, v30, v31, v32, v33, v34, *(_QWORD *)(a1 + 528));
  DP_PRINT_STATS("Received from Stack in FP:", v35, v36, v37, v38, v39, v40, v41, v42);
  DP_PRINT_STATS("\tPackets = %llu", v43, v44, v45, v46, v47, v48, v49, v50, *(_QWORD *)(a1 + 536));
  DP_PRINT_STATS("Received from Stack per core:", v51, v52, v53, v54, v55, v56, v57, v58);
  DP_PRINT_STATS(
    "\tPackets = %u %u %u %u",
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    *(unsigned int *)(a1 + 544),
    *(unsigned int *)(a1 + 548),
    *(unsigned int *)(a1 + 552),
    *(unsigned int *)(a1 + 556));
  DP_PRINT_STATS("Processed:", v67, v68, v69, v70, v71, v72, v73, v74);
  DP_PRINT_STATS("\tPackets = %llu", v75, v76, v77, v78, v79, v80, v81, v82, *(_QWORD *)(a1 + 568));
  DP_PRINT_STATS("\tBytes = %llu", v83, v84, v85, v86, v87, v88, v89, v90, *(_QWORD *)(a1 + 576));
  DP_PRINT_STATS("Total Completions:", v91, v92, v93, v94, v95, v96, v97, v98);
  DP_PRINT_STATS("\tPackets = %llu", v99, v100, v101, v102, v103, v104, v105, v106, *(_QWORD *)(a1 + 2992));
  DP_PRINT_STATS("\tBytes = %llu", v107, v108, v109, v110, v111, v112, v113, v114, *(_QWORD *)(a1 + 3000));
  DP_PRINT_STATS("Successful Completions:", v115, v116, v117, v118, v119, v120, v121, v122);
  DP_PRINT_STATS("\tPackets = %llu", v123, v124, v125, v126, v127, v128, v129, v130, *(_QWORD *)(a1 + 3072));
  DP_PRINT_STATS("\tBytes = %llu", v131, v132, v133, v134, v135, v136, v137, v138, *(_QWORD *)(a1 + 3080));
  DP_PRINT_STATS("Dropped:", v139, v140, v141, v142, v143, v144, v145, v146);
  DP_PRINT_STATS("\tTotal = %llu", v147, v148, v149, v150, v151, v152, v153, v154, *(_QWORD *)(a1 + 784));
  DP_PRINT_STATS("\tDma_map_error = %u", v155, v156, v157, v158, v159, v160, v161, v162, *(unsigned int *)(a1 + 872));
  DP_PRINT_STATS("\tRing Full = %u", v163, v164, v165, v166, v167, v168, v169, v170, *(unsigned int *)(a1 + 864));
  DP_PRINT_STATS(
    "\tDescriptor Not available = %llu",
    v171,
    v172,
    v173,
    v174,
    v175,
    v176,
    v177,
    v178,
    *(_QWORD *)(a1 + 800));
  DP_PRINT_STATS("\tHW enqueue failed= %u", v179, v180, v181, v182, v183, v184, v185, v186, *(unsigned int *)(a1 + 868));
  DP_PRINT_STATS(
    "        Descriptor alloc fail = %llu",
    v187,
    v188,
    v189,
    v190,
    v191,
    v192,
    v193,
    v194,
    *(_QWORD *)(a1 + 816));
  DP_PRINT_STATS(
    "        Tx outstanding too many = %llu",
    v195,
    v196,
    v197,
    v198,
    v199,
    v200,
    v201,
    v202,
    *(_QWORD *)(a1 + 832));
  DP_PRINT_STATS(
    "\tPkt dropped in vdev-id check= %u",
    v203,
    v204,
    v205,
    v206,
    v207,
    v208,
    v209,
    v210,
    *(unsigned int *)(a1 + 884));
  DP_PRINT_STATS("\tResources Full = %u", v211, v212, v213, v214, v215, v216, v217, v218, *(unsigned int *)(a1 + 876));
  DP_PRINT_STATS("\tDrop Ingress = %u", v219, v220, v221, v222, v223, v224, v225, v226, *(unsigned int *)(a1 + 888));
  DP_PRINT_STATS(
    "\tinvalid peer id in exception path = %u",
    v227,
    v228,
    v229,
    v230,
    v231,
    v232,
    v233,
    v234,
    *(unsigned int *)(a1 + 892));
  DP_PRINT_STATS("\tTx Mcast Drop = %u", v235, v236, v237, v238, v239, v240, v241, v242, *(unsigned int *)(a1 + 896));
  DP_PRINT_STATS(
    "\tPPE-DS FW2WBM Tx Drop = %u",
    v243,
    v244,
    v245,
    v246,
    v247,
    v248,
    v249,
    v250,
    *(unsigned int *)(a1 + 900));
  DP_PRINT_STATS("Tx failed = %u", v251, v252, v253, v254, v255, v256, v257, v258, *(unsigned int *)(a1 + 3092));
  DP_PRINT_STATS("\tFW removed Pkts = %llu", v259, v260, v261, v262, v263, v264, v265, v266, *(_QWORD *)(a1 + 3744));
  DP_PRINT_STATS("\tFW removed bytes= %llu", v267, v268, v269, v270, v271, v272, v273, v274, *(_QWORD *)(a1 + 3752));
  DP_PRINT_STATS(
    "\tFW removed transmitted = %llu",
    v275,
    v276,
    v277,
    v278,
    v279,
    v280,
    v281,
    v282,
    *(_QWORD *)(a1 + 3768));
  DP_PRINT_STATS(
    "\tFW removed untransmitted = %u",
    v283,
    v284,
    v285,
    v286,
    v287,
    v288,
    v289,
    v290,
    *(unsigned int *)(a1 + 3760));
  DP_PRINT_STATS(
    "\tFW removed untransmitted fw_reason1 = %u",
    v291,
    v292,
    v293,
    v294,
    v295,
    v296,
    v297,
    v298,
    *(unsigned int *)(a1 + 3788));
  DP_PRINT_STATS(
    "\tFW removed untransmitted fw_reason2 = %u",
    v299,
    v300,
    v301,
    v302,
    v303,
    v304,
    v305,
    v306,
    *(unsigned int *)(a1 + 3792));
  DP_PRINT_STATS(
    "\tFW removed untransmitted fw_reason3 = %u",
    v307,
    v308,
    v309,
    v310,
    v311,
    v312,
    v313,
    v314,
    *(unsigned int *)(a1 + 3796));
  DP_PRINT_STATS(
    "\tFW removed untransmitted disable queue = %u",
    v315,
    v316,
    v317,
    v318,
    v319,
    v320,
    v321,
    v322,
    *(unsigned int *)(a1 + 3800));
  DP_PRINT_STATS(
    "\tFW removed untransmitted no match = %u",
    v323,
    v324,
    v325,
    v326,
    v327,
    v328,
    v329,
    v330,
    *(unsigned int *)(a1 + 3804));
  DP_PRINT_STATS(
    "\tDropped due to HW threshold criteria = %u",
    v331,
    v332,
    v333,
    v334,
    v335,
    v336,
    v337,
    v338,
    *(unsigned int *)(a1 + 3808));
  DP_PRINT_STATS(
    "\tLink desc not available drop = %u",
    v339,
    v340,
    v341,
    v342,
    v343,
    v344,
    v345,
    v346,
    *(unsigned int *)(a1 + 3812));
  DP_PRINT_STATS(
    "\tDrop bit set or invalid flow = %u",
    v347,
    v348,
    v349,
    v350,
    v351,
    v352,
    v353,
    v354,
    *(unsigned int *)(a1 + 3816));
  DP_PRINT_STATS(
    "\tMCAST vdev drop in HW = %u",
    v355,
    v356,
    v357,
    v358,
    v359,
    v360,
    v361,
    v362,
    *(unsigned int *)(a1 + 3820));
  DP_PRINT_STATS(
    "\tDropped with invalid reason = %u",
    v363,
    v364,
    v365,
    v366,
    v367,
    v368,
    v369,
    v370,
    *(unsigned int *)(a1 + 3824));
  DP_PRINT_STATS(
    "\tAged Out from msdu/mpdu queues = %u",
    v371,
    v372,
    v373,
    v374,
    v375,
    v376,
    v377,
    v378,
    *(unsigned int *)(a1 + 3784));
  DP_PRINT_STATS(
    "\theadroom insufficient = %u",
    v379,
    v380,
    v381,
    v382,
    v383,
    v384,
    v385,
    v386,
    *(unsigned int *)(a1 + 880));
  DP_PRINT_STATS("Multicast:", v387, v388, v389, v390, v391, v392, v393, v394);
  DP_PRINT_STATS("\tPackets: %llu", v395, v396, v397, v398, v399, v400, v401, v402, *(_QWORD *)(a1 + 3024));
  DP_PRINT_STATS("\tBytes: %llu", v403, v404, v405, v406, v407, v408, v409, v410, *(_QWORD *)(a1 + 3032));
  DP_PRINT_STATS("Scatter Gather:", v411, v412, v413, v414, v415, v416, v417, v418);
  DP_PRINT_STATS("\tPackets = %llu", v419, v420, v421, v422, v423, v424, v425, v426, *(_QWORD *)(a1 + 680));
  DP_PRINT_STATS("\tBytes = %llu", v427, v428, v429, v430, v431, v432, v433, v434, *(_QWORD *)(a1 + 688));
  DP_PRINT_STATS("\tDropped By Host = %llu", v435, v436, v437, v438, v439, v440, v441, v442, *(_QWORD *)(a1 + 712));
  DP_PRINT_STATS(
    "\tDropped By Target = %u",
    v443,
    v444,
    v445,
    v446,
    v447,
    v448,
    v449,
    v450,
    *(unsigned int *)(a1 + 728));
  DP_PRINT_STATS("Mcast Enhancement:", v451, v452, v453, v454, v455, v456, v457, v458);
  DP_PRINT_STATS("\tPackets = %llu", v459, v460, v461, v462, v463, v464, v465, v466, *(_QWORD *)(a1 + 736));
  DP_PRINT_STATS("\tBytes = %llu", v467, v468, v469, v470, v471, v472, v473, v474, *(_QWORD *)(a1 + 744));
  DP_PRINT_STATS(
    "\tDropped: Map Errors = %u",
    v475,
    v476,
    v477,
    v478,
    v479,
    v480,
    v481,
    v482,
    *(unsigned int *)(a1 + 752));
  DP_PRINT_STATS(
    "\tDropped: Self Mac = %u",
    v483,
    v484,
    v485,
    v486,
    v487,
    v488,
    v489,
    v490,
    *(unsigned int *)(a1 + 756));
  DP_PRINT_STATS(
    "\tDropped: Send Fail = %u",
    v491,
    v492,
    v493,
    v494,
    v495,
    v496,
    v497,
    v498,
    *(unsigned int *)(a1 + 760));
  DP_PRINT_STATS("\tUnicast sent = %u", v499, v500, v501, v502, v503, v504, v505, v506, *(unsigned int *)(a1 + 764));
  DP_PRINT_STATS("EAPOL Packets dropped:", v507, v508, v509, v510, v511, v512, v513, v514);
  DP_PRINT_STATS("        Dropped: TX desc errors = %u", v515, v516, v517, v518, v519, v520, v521, v522, *v10);
  DP_PRINT_STATS(
    "        Dropped: Tx HAL ring access errors = %u",
    v523,
    v524,
    v525,
    v526,
    v527,
    v528,
    v529,
    v530,
    v10[1]);
  DP_PRINT_STATS("        Dropped: TX DMA map errors = %u", v531, v532, v533, v534, v535, v536, v537, v538, v10[2]);
  DP_PRINT_STATS("        Dropped: Tx HW enqueue errors = %u", v539, v540, v541, v542, v543, v544, v545, v546, v10[3]);
  DP_PRINT_STATS("        Dropped: TX SW enqueue errors= %u", v547, v548, v549, v550, v551, v552, v553, v554, v10[4]);
  DP_PRINT_STATS("IGMP Mcast Enhancement:", v555, v556, v557, v558, v559, v560, v561, v562);
  DP_PRINT_STATS(
    "\tIGMP packets received = %u",
    v563,
    v564,
    v565,
    v566,
    v567,
    v568,
    v569,
    v570,
    *(unsigned int *)(a1 + 776));
  DP_PRINT_STATS(
    "\tConverted to uncast = %u",
    v571,
    v572,
    v573,
    v574,
    v575,
    v576,
    v577,
    v578,
    *(unsigned int *)(a1 + 780));
  DP_PRINT_STATS("Raw:", v579, v580, v581, v582, v583, v584, v585, v586);
  DP_PRINT_STATS("\tPackets = %llu", v587, v588, v589, v590, v591, v592, v593, v594, *(_QWORD *)(a1 + 648));
  DP_PRINT_STATS("\tBytes = %llu", v595, v596, v597, v598, v599, v600, v601, v602, *(_QWORD *)(a1 + 656));
  DP_PRINT_STATS("\tDMA map error = %u", v603, v604, v605, v606, v607, v608, v609, v610, *(unsigned int *)(a1 + 664));
  DP_PRINT_STATS(
    "        RAW pkt type[!data] error = %u",
    v611,
    v612,
    v613,
    v614,
    v615,
    v616,
    v617,
    v618,
    *(unsigned int *)(a1 + 668));
  DP_PRINT_STATS(
    "        Frags count overflow  error = %u",
    v619,
    v620,
    v621,
    v622,
    v623,
    v624,
    v625,
    v626,
    *(unsigned int *)(a1 + 672));
  DP_PRINT_STATS("Reinjected:", v627, v628, v629, v630, v631, v632, v633, v634);
  DP_PRINT_STATS("\tPackets = %llu", v635, v636, v637, v638, v639, v640, v641, v642, *(_QWORD *)(a1 + 584));
  DP_PRINT_STATS("\tBytes = %llu\n", v643, v644, v645, v646, v647, v648, v649, v650, *(_QWORD *)(a1 + 592));
  DP_PRINT_STATS("Inspected:", v651, v652, v653, v654, v655, v656, v657, v658);
  DP_PRINT_STATS("\tPackets = %llu", v659, v660, v661, v662, v663, v664, v665, v666, *(_QWORD *)(a1 + 600));
  DP_PRINT_STATS("\tBytes = %llu", v667, v668, v669, v670, v671, v672, v673, v674, *(_QWORD *)(a1 + 608));
  DP_PRINT_STATS("Nawds Multicast:", v675, v676, v677, v678, v679, v680, v681, v682);
  DP_PRINT_STATS("\tPackets = %llu", v683, v684, v685, v686, v687, v688, v689, v690, *(_QWORD *)(a1 + 616));
  DP_PRINT_STATS("\tBytes = %llu", v691, v692, v693, v694, v695, v696, v697, v698, *(_QWORD *)(a1 + 624));
  DP_PRINT_STATS("CCE Classified:", v699, v700, v701, v702, v703, v704, v705, v706);
  DP_PRINT_STATS(
    "\tCCE Classified Packets: %u",
    v707,
    v708,
    v709,
    v710,
    v711,
    v712,
    v713,
    v714,
    *(unsigned int *)(a1 + 928));
  DP_PRINT_STATS(
    "\tRAW CCE Classified Packets: %u",
    v715,
    v716,
    v717,
    v718,
    v719,
    v720,
    v721,
    v722,
    *(unsigned int *)(a1 + 932));
  DP_PRINT_STATS("Mesh stats:", v723, v724, v725, v726, v727, v728, v729, v730);
  DP_PRINT_STATS(
    "\tframes to firmware: %u",
    v731,
    v732,
    v733,
    v734,
    v735,
    v736,
    v737,
    v738,
    *(unsigned int *)(a1 + 920));
  DP_PRINT_STATS(
    "\tcompletions from fw: %u",
    v739,
    v740,
    v741,
    v742,
    v743,
    v744,
    v745,
    v746,
    *(unsigned int *)(a1 + 924));
  DP_PRINT_STATS("PPDU stats counter", v747, v748, v749, v750, v751, v752, v753, v754);
  DP_PRINT_STATS("\tTag[%d] = %llu", v755, v756, v757, v758, v759, v760, v761, v762, 0, *(_QWORD *)(a1 + 7592));
  DP_PRINT_STATS("\tTag[%d] = %llu", v763, v764, v765, v766, v767, v768, v769, v770, 1, *(_QWORD *)(a1 + 7600));
  DP_PRINT_STATS("\tTag[%d] = %llu", v771, v772, v773, v774, v775, v776, v777, v778, 2, *(_QWORD *)(a1 + 7608));
  DP_PRINT_STATS("\tTag[%d] = %llu", v779, v780, v781, v782, v783, v784, v785, v786, 3, *(_QWORD *)(a1 + 7616));
  DP_PRINT_STATS("\tTag[%d] = %llu", v787, v788, v789, v790, v791, v792, v793, v794, 4, *(_QWORD *)(a1 + 7624));
  DP_PRINT_STATS("\tTag[%d] = %llu", v795, v796, v797, v798, v799, v800, v801, v802, 5, *(_QWORD *)(a1 + 7632));
  DP_PRINT_STATS("\tTag[%d] = %llu", v803, v804, v805, v806, v807, v808, v809, v810, 6, *(_QWORD *)(a1 + 7640));
  DP_PRINT_STATS("\tTag[%d] = %llu", v811, v812, v813, v814, v815, v816, v817, v818, 7, *(_QWORD *)(a1 + 7648));
  DP_PRINT_STATS("\tTag[%d] = %llu", v819, v820, v821, v822, v823, v824, v825, v826, 8, *(_QWORD *)(a1 + 7656));
  DP_PRINT_STATS("\tTag[%d] = %llu", v827, v828, v829, v830, v831, v832, v833, v834, 9, *(_QWORD *)(a1 + 7664));
  DP_PRINT_STATS("\tTag[%d] = %llu", v835, v836, v837, v838, v839, v840, v841, v842, 10, *(_QWORD *)(a1 + 7672));
  DP_PRINT_STATS("\tTag[%d] = %llu", v843, v844, v845, v846, v847, v848, v849, v850, 11, *(_QWORD *)(a1 + 7680));
  DP_PRINT_STATS("\tTag[%d] = %llu", v851, v852, v853, v854, v855, v856, v857, v858, 12, *(_QWORD *)(a1 + 7688));
  DP_PRINT_STATS("\tTag[%d] = %llu", v859, v860, v861, v862, v863, v864, v865, v866, 13, *(_QWORD *)(a1 + 7696));
  DP_PRINT_STATS(
    "BA not received for delayed_ba: %u",
    v867,
    v868,
    v869,
    v870,
    v871,
    v872,
    v873,
    v874,
    *(unsigned int *)(a1 + 7704));
  if ( a1 )
  {
    v883 = *(_QWORD *)(a1 + 96456);
    if ( v883 )
    {
      DP_PRINT_STATS(
        "ppdu info schedule completion list depth: %d",
        v875,
        v876,
        v877,
        v878,
        v879,
        v880,
        v881,
        v882,
        *(unsigned int *)(v883 + 39208));
      DP_PRINT_STATS(
        "delivered sched cmdid: %d",
        v884,
        v885,
        v886,
        v887,
        v888,
        v889,
        v890,
        v891,
        *(unsigned __int16 *)(*(_QWORD *)(a1 + 96456) + 39212LL));
      DP_PRINT_STATS(
        "cur sched cmdid: %d",
        v892,
        v893,
        v894,
        v895,
        v896,
        v897,
        v898,
        v899,
        *(unsigned __int16 *)(*(_QWORD *)(a1 + 96456) + 39214LL));
      DP_PRINT_STATS(
        "ppdu info list depth: %d",
        v900,
        v901,
        v902,
        v903,
        v904,
        v905,
        v906,
        v907,
        *(unsigned int *)(*(_QWORD *)(a1 + 96456) + 39220LL));
    }
  }
  DP_PRINT_STATS("tx_ppdu_proc: %llu", v875, v876, v877, v878, v879, v880, v881, v882, *((_QWORD *)v10 + 263));
  DP_PRINT_STATS("ack ba comes twice: %llu", v908, v909, v910, v911, v912, v913, v914, v915, *((_QWORD *)v10 + 264));
  DP_PRINT_STATS(
    "ppdu dropped because of incomplete tlv: %llu",
    v916,
    v917,
    v918,
    v919,
    v920,
    v921,
    v922,
    v923,
    *((_QWORD *)v10 + 265));
  DP_PRINT_STATS(
    "ppdu dropped because of wrap around: %llu",
    v924,
    v925,
    v926,
    v927,
    v928,
    v929,
    v930,
    v931,
    *((_QWORD *)v10 + 266));
  for ( i = 2154; i != 2205; ++i )
  {
    if ( *(_DWORD *)(a1 + 4 * i) )
      DP_PRINT_STATS("Wdi msgs received for event ID[%d]:%d", v932, v933, v934, v935, v936, v937, v938, v939, i - 2154);
  }
  v941 = *(_QWORD *)(*(_QWORD *)(a1 + 8) + 20112LL);
  if ( !v941 )
  {
    v952 = "%s: monitor soc is NULL";
    goto LABEL_16;
  }
  v942 = *(_QWORD *)(v941 + 416);
  if ( !v942 || (v943 = *(void (__fastcall **)(_QWORD))(v942 + 400)) == nullptr )
  {
    v952 = "%s: callback not registered";
LABEL_16:
    qdf_trace_msg(
      0x92u,
      8u,
      v952,
      v932,
      v933,
      v934,
      v935,
      v936,
      v937,
      v938,
      v939,
      "dp_monitor_print_pdev_tx_capture_stats");
    goto LABEL_17;
  }
  if ( *((_DWORD *)v943 - 1) != -1557217772 )
    __break(0x8228u);
  v943(a1);
LABEL_17:
  DP_PRINT_STATS(
    "EAPOL Tx comp Success = %d",
    v944,
    v945,
    v946,
    v947,
    v948,
    v949,
    v950,
    v951,
    *(unsigned int *)(a1 + 5156));
  DP_PRINT_STATS("EAPOL Tx comp Failures:", v953, v954, v955, v956, v957, v958, v959, v960);
  DP_PRINT_STATS(
    "\tFail reason:DROP = %d",
    v961,
    v962,
    v963,
    v964,
    v965,
    v966,
    v967,
    v968,
    *(unsigned int *)(a1 + 5160));
  DP_PRINT_STATS("\tFail reason:TTL = %d", v969, v970, v971, v972, v973, v974, v975, v976, *(unsigned int *)(a1 + 5164));
  DP_PRINT_STATS(
    "\tFail reason:REINJECT = %d",
    v977,
    v978,
    v979,
    v980,
    v981,
    v982,
    v983,
    v984,
    *(unsigned int *)(a1 + 5168));
  DP_PRINT_STATS(
    "\tFail reason:INSPECT = %d",
    v985,
    v986,
    v987,
    v988,
    v989,
    v990,
    v991,
    v992,
    *(unsigned int *)(a1 + 5172));
  DP_PRINT_STATS(
    "\tFail reason:MEC NOTIFY = %d",
    v993,
    v994,
    v995,
    v996,
    v997,
    v998,
    v999,
    v1000,
    *(unsigned int *)(a1 + 5176));
  DP_PRINT_STATS(
    "\tFail reason:VDEVID MISMATCH = %d",
    v1001,
    v1002,
    v1003,
    v1004,
    v1005,
    v1006,
    v1007,
    v1008,
    *(unsigned int *)(a1 + 5180));
  DP_PRINT_STATS(
    "Rekey EAPOL Tx comp Success = %d",
    v1009,
    v1010,
    v1011,
    v1012,
    v1013,
    v1014,
    v1015,
    v1016,
    *(unsigned int *)(a1 + 5184));
  DP_PRINT_STATS("Rekey EAPOL Tx comp Failures:", v1017, v1018, v1019, v1020, v1021, v1022, v1023, v1024);
  DP_PRINT_STATS(
    "\tFail reason:DROP = %d",
    v1025,
    v1026,
    v1027,
    v1028,
    v1029,
    v1030,
    v1031,
    v1032,
    *(unsigned int *)(a1 + 5188));
  DP_PRINT_STATS(
    "\tFail reason:TTL = %d",
    v1033,
    v1034,
    v1035,
    v1036,
    v1037,
    v1038,
    v1039,
    v1040,
    *(unsigned int *)(a1 + 5192));
  DP_PRINT_STATS(
    "\tFail reason:REINJECT = %d",
    v1041,
    v1042,
    v1043,
    v1044,
    v1045,
    v1046,
    v1047,
    v1048,
    *(unsigned int *)(a1 + 5196));
  DP_PRINT_STATS(
    "\tFail reason:INSPECT = %d",
    v1049,
    v1050,
    v1051,
    v1052,
    v1053,
    v1054,
    v1055,
    v1056,
    *(unsigned int *)(a1 + 5200));
  DP_PRINT_STATS(
    "\tFail reason:MEC NOTIFY = %d",
    v1057,
    v1058,
    v1059,
    v1060,
    v1061,
    v1062,
    v1063,
    v1064,
    *(unsigned int *)(a1 + 5204));
  return DP_PRINT_STATS(
           "\tFail reason:VDEVID MISMATCH = %d",
           v1065,
           v1066,
           v1067,
           v1068,
           v1069,
           v1070,
           v1071,
           v1072,
           *(unsigned int *)(a1 + 5208));
}
