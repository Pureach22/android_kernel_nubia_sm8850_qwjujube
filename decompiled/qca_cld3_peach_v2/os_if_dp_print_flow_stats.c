__int64 __fastcall os_if_dp_print_flow_stats(__int64 a1, char a2)
{
  __int64 result; // x0
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x3
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  char v16; // w26
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
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
  unsigned __int16 v51; // w0
  unsigned __int16 v52; // w24
  __int16 v53; // w0
  unsigned __int16 v54; // w24
  __int16 v55; // w0
  unsigned __int16 v56; // w24
  __int16 v57; // w0
  unsigned __int16 v58; // w24
  __int16 v59; // w0
  unsigned __int16 v60; // w24
  __int16 v61; // w0
  unsigned __int16 v62; // w24
  __int16 v63; // w0
  unsigned __int16 v64; // w24
  __int16 v65; // w0
  unsigned __int16 v66; // w24
  __int16 v67; // w0
  unsigned __int16 v68; // w24
  __int16 v69; // w0
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  unsigned __int16 v78; // w0
  unsigned __int16 v79; // w25
  __int16 v80; // w0
  unsigned __int16 v81; // w25
  __int16 v82; // w0
  unsigned __int16 v83; // w25
  __int16 v84; // w0
  unsigned __int16 v85; // w25
  __int16 v86; // w0
  unsigned __int16 v87; // w25
  __int16 v88; // w0
  unsigned __int16 v89; // w25
  __int16 v90; // w0
  unsigned __int16 v91; // w25
  __int16 v92; // w0
  unsigned __int16 v93; // w25
  __int16 v94; // w0
  unsigned __int16 v95; // w25
  __int16 v96; // w0
  double v97; // d0
  double v98; // d1
  double v99; // d2
  double v100; // d3
  double v101; // d4
  double v102; // d5
  double v103; // d6
  double v104; // d7
  unsigned __int16 v105; // w0
  unsigned __int16 v106; // w25
  __int16 v107; // w0
  unsigned __int16 v108; // w25
  __int16 v109; // w0
  unsigned __int16 v110; // w25
  __int16 v111; // w0
  unsigned __int16 v112; // w25
  __int16 v113; // w0
  unsigned __int16 v114; // w25
  __int16 v115; // w0
  unsigned __int16 v116; // w25
  __int16 v117; // w0
  unsigned __int16 v118; // w25
  __int16 v119; // w0
  unsigned __int16 v120; // w25
  __int16 v121; // w0
  unsigned __int16 v122; // w25
  __int16 v123; // w0
  double v124; // d0
  double v125; // d1
  double v126; // d2
  double v127; // d3
  double v128; // d4
  double v129; // d5
  double v130; // d6
  double v131; // d7
  unsigned __int16 v132; // w0
  unsigned __int16 v133; // w25
  __int16 v134; // w0
  unsigned __int16 v135; // w25
  __int16 v136; // w0
  unsigned __int16 v137; // w25
  __int16 v138; // w0
  unsigned __int16 v139; // w25
  __int16 v140; // w0
  unsigned __int16 v141; // w25
  __int16 v142; // w0
  unsigned __int16 v143; // w25
  __int16 v144; // w0
  unsigned __int16 v145; // w25
  __int16 v146; // w0
  unsigned __int16 v147; // w25
  __int16 v148; // w0
  unsigned __int16 v149; // w25
  __int16 v150; // w0
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  unsigned __int16 v159; // w0
  unsigned __int16 v160; // w25
  __int16 v161; // w0
  unsigned __int16 v162; // w25
  __int16 v163; // w0
  unsigned __int16 v164; // w25
  __int16 v165; // w0
  unsigned __int16 v166; // w25
  __int16 v167; // w0
  unsigned __int16 v168; // w25
  __int16 v169; // w0
  unsigned __int16 v170; // w25
  __int16 v171; // w0
  unsigned __int16 v172; // w25
  __int16 v173; // w0
  unsigned __int16 v174; // w25
  __int16 v175; // w0
  unsigned __int16 v176; // w25
  __int16 v177; // w0
  double v178; // d0
  double v179; // d1
  double v180; // d2
  double v181; // d3
  double v182; // d4
  double v183; // d5
  double v184; // d6
  double v185; // d7
  unsigned __int16 v186; // w0
  unsigned __int16 v187; // w25
  __int16 v188; // w0
  unsigned __int16 v189; // w25
  __int16 v190; // w0
  unsigned __int16 v191; // w25
  __int16 v192; // w0
  unsigned __int16 v193; // w25
  __int16 v194; // w0
  unsigned __int16 v195; // w25
  __int16 v196; // w0
  unsigned __int16 v197; // w25
  __int16 v198; // w0
  unsigned __int16 v199; // w25
  __int16 v200; // w0
  unsigned __int16 v201; // w25
  __int16 v202; // w0
  unsigned __int16 v203; // w25
  __int16 v204; // w0
  double v205; // d0
  double v206; // d1
  double v207; // d2
  double v208; // d3
  double v209; // d4
  double v210; // d5
  double v211; // d6
  double v212; // d7
  unsigned __int16 v213; // w0
  unsigned __int16 v214; // w25
  __int16 v215; // w0
  unsigned __int16 v216; // w25
  __int16 v217; // w0
  unsigned __int16 v218; // w25
  __int16 v219; // w0
  unsigned __int16 v220; // w25
  __int16 v221; // w0
  unsigned __int16 v222; // w25
  __int16 v223; // w0
  unsigned __int16 v224; // w25
  __int16 v225; // w0
  unsigned __int16 v226; // w25
  __int16 v227; // w0
  unsigned __int16 v228; // w25
  __int16 v229; // w0
  unsigned __int16 v230; // w25
  __int16 v231; // w0
  double v232; // d0
  double v233; // d1
  double v234; // d2
  double v235; // d3
  double v236; // d4
  double v237; // d5
  double v238; // d6
  double v239; // d7
  unsigned __int16 v240; // w0
  unsigned __int16 v241; // w25
  __int16 v242; // w0
  unsigned __int16 v243; // w25
  __int16 v244; // w0
  unsigned __int16 v245; // w25
  __int16 v246; // w0
  unsigned __int16 v247; // w25
  __int16 v248; // w0
  unsigned __int16 v249; // w25
  __int16 v250; // w0
  unsigned __int16 v251; // w25
  __int16 v252; // w0
  unsigned __int16 v253; // w25
  __int16 v254; // w0
  unsigned __int16 v255; // w25
  __int16 v256; // w0
  unsigned __int16 v257; // w25
  __int16 v258; // w0
  double v259; // d0
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  unsigned __int16 v267; // w0
  unsigned __int16 v268; // w25
  __int16 v269; // w0
  unsigned __int16 v270; // w25
  __int16 v271; // w0
  unsigned __int16 v272; // w25
  __int16 v273; // w0
  unsigned __int16 v274; // w25
  __int16 v275; // w0
  unsigned __int16 v276; // w25
  __int16 v277; // w0
  unsigned __int16 v278; // w25
  __int16 v279; // w0
  unsigned __int16 v280; // w25
  __int16 v281; // w0
  unsigned __int16 v282; // w25
  __int16 v283; // w0
  unsigned __int16 v284; // w25
  __int16 v285; // w0
  double v286; // d0
  double v287; // d1
  double v288; // d2
  double v289; // d3
  double v290; // d4
  double v291; // d5
  double v292; // d6
  double v293; // d7
  unsigned __int16 v294; // w0
  unsigned __int16 v295; // w25
  __int16 v296; // w0
  unsigned __int16 v297; // w25
  __int16 v298; // w0
  unsigned __int16 v299; // w25
  __int16 v300; // w0
  unsigned __int16 v301; // w25
  __int16 v302; // w0
  unsigned __int16 v303; // w25
  __int16 v304; // w0
  unsigned __int16 v305; // w25
  __int16 v306; // w0
  unsigned __int16 v307; // w25
  __int16 v308; // w0
  unsigned __int16 v309; // w25
  __int16 v310; // w0
  unsigned __int16 v311; // w25
  __int16 v312; // w0
  double v313; // d0
  double v314; // d1
  double v315; // d2
  double v316; // d3
  double v317; // d4
  double v318; // d5
  double v319; // d6
  double v320; // d7
  unsigned __int16 v321; // w0
  unsigned __int16 v322; // w25
  __int16 v323; // w0
  unsigned __int16 v324; // w25
  __int16 v325; // w0
  unsigned __int16 v326; // w25
  __int16 v327; // w0
  unsigned __int16 v328; // w25
  __int16 v329; // w0
  unsigned __int16 v330; // w25
  __int16 v331; // w0
  unsigned __int16 v332; // w25
  __int16 v333; // w0
  unsigned __int16 v334; // w25
  __int16 v335; // w0
  unsigned __int16 v336; // w25
  __int16 v337; // w0
  unsigned __int16 v338; // w25
  __int16 v339; // w0
  double v340; // d0
  double v341; // d1
  double v342; // d2
  double v343; // d3
  double v344; // d4
  double v345; // d5
  double v346; // d6
  double v347; // d7
  unsigned __int16 v348; // w0
  unsigned __int16 v349; // w24
  __int16 v350; // w0
  unsigned __int16 v351; // w24
  __int16 v352; // w0
  unsigned __int16 v353; // w24
  __int16 v354; // w0
  unsigned __int16 v355; // w24
  __int16 v356; // w0
  unsigned __int16 v357; // w24
  __int16 v358; // w0
  unsigned __int16 v359; // w24
  __int16 v360; // w0
  unsigned __int16 v361; // w24
  __int16 v362; // w0
  unsigned __int16 v363; // w24
  __int16 v364; // w0
  unsigned __int16 v365; // w24
  __int16 v366; // w0
  double v367; // d0
  double v368; // d1
  double v369; // d2
  double v370; // d3
  double v371; // d4
  double v372; // d5
  double v373; // d6
  double v374; // d7
  unsigned __int16 v375; // w0
  unsigned __int16 v376; // w24
  __int16 v377; // w0
  unsigned __int16 v378; // w24
  __int16 v379; // w0
  unsigned __int16 v380; // w24
  __int16 v381; // w0
  unsigned __int16 v382; // w24
  __int16 v383; // w0
  unsigned __int16 v384; // w24
  __int16 v385; // w0
  unsigned __int16 v386; // w24
  __int16 v387; // w0
  unsigned __int16 v388; // w24
  __int16 v389; // w0
  unsigned __int16 v390; // w24
  __int16 v391; // w0
  unsigned __int16 v392; // w24
  __int16 v393; // w0
  double v394; // d0
  double v395; // d1
  double v396; // d2
  double v397; // d3
  double v398; // d4
  double v399; // d5
  double v400; // d6
  double v401; // d7
  unsigned __int16 v402; // w0
  unsigned __int16 v403; // w23
  __int16 v404; // w0
  unsigned __int16 v405; // w23
  __int16 v406; // w0
  unsigned __int16 v407; // w23
  __int16 v408; // w0
  unsigned __int16 v409; // w23
  __int16 v410; // w0
  unsigned __int16 v411; // w23
  __int16 v412; // w0
  unsigned __int16 v413; // w23
  __int16 v414; // w0
  unsigned __int16 v415; // w23
  __int16 v416; // w0
  unsigned __int16 v417; // w23
  __int16 v418; // w0
  unsigned __int16 v419; // w23
  __int16 v420; // w0
  double v421; // d0
  double v422; // d1
  double v423; // d2
  double v424; // d3
  double v425; // d4
  double v426; // d5
  double v427; // d6
  double v428; // d7
  unsigned __int64 v429; // x8
  __int64 v430; // x25
  double v431; // d0
  double v432; // d1
  double v433; // d2
  double v434; // d3
  double v435; // d4
  double v436; // d5
  double v437; // d6
  double v438; // d7
  double v439; // d0
  double v440; // d1
  double v441; // d2
  double v442; // d3
  double v443; // d4
  double v444; // d5
  double v445; // d6
  double v446; // d7
  double v447; // d0
  double v448; // d1
  double v449; // d2
  double v450; // d3
  double v451; // d4
  double v452; // d5
  double v453; // d6
  double v454; // d7
  double v455; // d0
  double v456; // d1
  double v457; // d2
  double v458; // d3
  double v459; // d4
  double v460; // d5
  double v461; // d6
  double v462; // d7
  double v463; // d0
  double v464; // d1
  double v465; // d2
  double v466; // d3
  double v467; // d4
  double v468; // d5
  double v469; // d6
  double v470; // d7
  double v471; // d0
  double v472; // d1
  double v473; // d2
  double v474; // d3
  double v475; // d4
  double v476; // d5
  double v477; // d6
  double v478; // d7
  double v479; // d0
  double v480; // d1
  double v481; // d2
  double v482; // d3
  double v483; // d4
  double v484; // d5
  double v485; // d6
  double v486; // d7
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
  double v503; // d0
  double v504; // d1
  double v505; // d2
  double v506; // d3
  double v507; // d4
  double v508; // d5
  double v509; // d6
  double v510; // d7
  double v511; // d0
  double v512; // d1
  double v513; // d2
  double v514; // d3
  double v515; // d4
  double v516; // d5
  double v517; // d6
  double v518; // d7
  double v519; // d0
  double v520; // d1
  double v521; // d2
  double v522; // d3
  double v523; // d4
  double v524; // d5
  double v525; // d6
  double v526; // d7
  double v527; // d0
  double v528; // d1
  double v529; // d2
  double v530; // d3
  double v531; // d4
  double v532; // d5
  double v533; // d6
  double v534; // d7
  double v535; // d0
  double v536; // d1
  double v537; // d2
  double v538; // d3
  double v539; // d4
  double v540; // d5
  double v541; // d6
  double v542; // d7
  double v543; // d0
  double v544; // d1
  double v545; // d2
  double v546; // d3
  double v547; // d4
  double v548; // d5
  double v549; // d6
  double v550; // d7
  double v551; // d0
  double v552; // d1
  double v553; // d2
  double v554; // d3
  double v555; // d4
  double v556; // d5
  double v557; // d6
  double v558; // d7
  double v559; // d0
  double v560; // d1
  double v561; // d2
  double v562; // d3
  double v563; // d4
  double v564; // d5
  double v565; // d6
  double v566; // d7
  double v567; // d0
  double v568; // d1
  double v569; // d2
  double v570; // d3
  double v571; // d4
  double v572; // d5
  double v573; // d6
  double v574; // d7

  result = os_if_dp_print_tuple(a1 + 4);
  v16 = a2;
  if ( (a2 & 1) != 0 )
  {
    v17 = _qdf_mem_malloc(0x100u, "os_if_dp_print_flow_txrx_stats", 233);
    if ( !v17 )
    {
      result = qdf_trace_msg(
                 0x48u,
                 8u,
                 "%s: log buffer allocation failed",
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 "os_if_dp_print_flow_txrx_stats");
      if ( (a2 & 2) == 0 )
        return result;
      goto LABEL_5;
    }
    v26 = v17;
    v27 = scnprintf(v17, 256, "Flow TxRx Stats:");
    qdf_trace_msg(0x48u, 8u, "STC: %s", v27, v28, v29, v30, v31, v32, v33, v34, v26);
    v35 = scnprintf(
            v26,
            256,
            "%20s %32s %32s %32s %32s %32s",
            (const char *)&unk_98C763,
            "Sample1          ",
            "Sample2          ",
            "Sample3          ",
            "Sample4          ",
            "Sample5          ");
    qdf_trace_msg(0x48u, 8u, "STC: %s", v35, v36, v37, v38, v39, v40, v41, v42, v26);
    v43 = scnprintf(
            v26,
            256,
            "%20s %15s %15s %15s %15s %15s %15s %15s %15s %15s %15s",
            (const char *)&unk_98C763,
            "WIN1     ",
            "WIN2     ",
            "WIN1     ",
            "WIN2     ",
            "WIN1     ",
            "WIN2     ",
            "WIN1     ",
            "WIN2     ",
            "WIN1     ",
            "WIN2     ");
    qdf_trace_msg(0x48u, 8u, "STC: %s", v43, v44, v45, v46, v47, v48, v49, v50, v26);
    scnprintf(v26, 256, "%20s", "UL bytes: ");
    v52 = v51;
    scnprintf(v26 + v51, 256LL - v51, " %15llu", *(_QWORD *)(a1 + 64));
    v54 = v53 + v52;
    scnprintf(v26 + v54, 256LL - v54, " %15llu", *(_QWORD *)(a1 + 184));
    v56 = v54 + v55;
    scnprintf(v26 + v56, 256LL - v56, " %15llu", *(_QWORD *)(a1 + 304));
    v58 = v56 + v57;
    scnprintf(v26 + v58, 256LL - v58, " %15llu", *(_QWORD *)(a1 + 424));
    v60 = v58 + v59;
    scnprintf(v26 + v60, 256LL - v60, " %15llu", *(_QWORD *)(a1 + 544));
    v62 = v60 + v61;
    scnprintf(v26 + v62, 256LL - v62, " %15llu", *(_QWORD *)(a1 + 664));
    v64 = v62 + v63;
    scnprintf(v26 + v64, 256LL - v64, " %15llu", *(_QWORD *)(a1 + 784));
    v66 = v64 + v65;
    scnprintf(v26 + v66, 256LL - v66, " %15llu", *(_QWORD *)(a1 + 904));
    v68 = v66 + v67;
    scnprintf(v26 + v68, 256LL - v68, " %15llu", *(_QWORD *)(a1 + 1024));
    v70 = scnprintf(
            v26 + (unsigned __int16)(v68 + v69),
            256LL - (unsigned __int16)(v68 + v69),
            " %15llu",
            *(_QWORD *)(a1 + 1144));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v70, v71, v72, v73, v74, v75, v76, v77, v26);
    scnprintf(v26, 256, "%20s", "UL pkts: ");
    v79 = v78;
    scnprintf(v26 + v78, 256LL - v78, " %15u", *(_DWORD *)(a1 + 72));
    v81 = v80 + v79;
    scnprintf(v26 + v81, 256LL - v81, " %15u", *(_DWORD *)(a1 + 192));
    v83 = v81 + v82;
    scnprintf(v26 + v83, 256LL - v83, " %15u", *(_DWORD *)(a1 + 312));
    v85 = v83 + v84;
    scnprintf(v26 + v85, 256LL - v85, " %15u", *(_DWORD *)(a1 + 432));
    v87 = v85 + v86;
    scnprintf(v26 + v87, 256LL - v87, " %15u", *(_DWORD *)(a1 + 552));
    v89 = v87 + v88;
    scnprintf(v26 + v89, 256LL - v89, " %15u", *(_DWORD *)(a1 + 672));
    v91 = v89 + v90;
    scnprintf(v26 + v91, 256LL - v91, " %15u", *(_DWORD *)(a1 + 792));
    v93 = v91 + v92;
    scnprintf(v26 + v93, 256LL - v93, " %15u", *(_DWORD *)(a1 + 912));
    v95 = v93 + v94;
    scnprintf(v26 + v95, 256LL - v95, " %15u", *(_DWORD *)(a1 + 1032));
    v97 = scnprintf(
            v26 + (unsigned __int16)(v95 + v96),
            256LL - (unsigned __int16)(v95 + v96),
            " %15u",
            *(_DWORD *)(a1 + 1152));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v97, v98, v99, v100, v101, v102, v103, v104, v26);
    scnprintf(v26, 256, "%20s", "UL pkt_size_min: ");
    v106 = v105;
    scnprintf(v26 + v105, 256LL - v105, " %15u", *(_DWORD *)(a1 + 76));
    v108 = v107 + v106;
    scnprintf(v26 + v108, 256LL - v108, " %15u", *(_DWORD *)(a1 + 196));
    v110 = v108 + v109;
    scnprintf(v26 + v110, 256LL - v110, " %15u", *(_DWORD *)(a1 + 316));
    v112 = v110 + v111;
    scnprintf(v26 + v112, 256LL - v112, " %15u", *(_DWORD *)(a1 + 436));
    v114 = v112 + v113;
    scnprintf(v26 + v114, 256LL - v114, " %15u", *(_DWORD *)(a1 + 556));
    v116 = v114 + v115;
    scnprintf(v26 + v116, 256LL - v116, " %15u", *(_DWORD *)(a1 + 676));
    v118 = v116 + v117;
    scnprintf(v26 + v118, 256LL - v118, " %15u", *(_DWORD *)(a1 + 796));
    v120 = v118 + v119;
    scnprintf(v26 + v120, 256LL - v120, " %15u", *(_DWORD *)(a1 + 916));
    v122 = v120 + v121;
    scnprintf(v26 + v122, 256LL - v122, " %15u", *(_DWORD *)(a1 + 1036));
    v124 = scnprintf(
             v26 + (unsigned __int16)(v122 + v123),
             256LL - (unsigned __int16)(v122 + v123),
             " %15u",
             *(_DWORD *)(a1 + 1156));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v124, v125, v126, v127, v128, v129, v130, v131, v26);
    scnprintf(v26, 256, "%20s", "UL pkt_size_max: ");
    v133 = v132;
    scnprintf(v26 + v132, 256LL - v132, " %15u", *(_DWORD *)(a1 + 80));
    v135 = v134 + v133;
    scnprintf(v26 + v135, 256LL - v135, " %15u", *(_DWORD *)(a1 + 200));
    v137 = v135 + v136;
    scnprintf(v26 + v137, 256LL - v137, " %15u", *(_DWORD *)(a1 + 320));
    v139 = v137 + v138;
    scnprintf(v26 + v139, 256LL - v139, " %15u", *(_DWORD *)(a1 + 440));
    v141 = v139 + v140;
    scnprintf(v26 + v141, 256LL - v141, " %15u", *(_DWORD *)(a1 + 560));
    v143 = v141 + v142;
    scnprintf(v26 + v143, 256LL - v143, " %15u", *(_DWORD *)(a1 + 680));
    v145 = v143 + v144;
    scnprintf(v26 + v145, 256LL - v145, " %15u", *(_DWORD *)(a1 + 800));
    v147 = v145 + v146;
    scnprintf(v26 + v147, 256LL - v147, " %15u", *(_DWORD *)(a1 + 920));
    v149 = v147 + v148;
    scnprintf(v26 + v149, 256LL - v149, " %15u", *(_DWORD *)(a1 + 1040));
    v151 = scnprintf(
             v26 + (unsigned __int16)(v149 + v150),
             256LL - (unsigned __int16)(v149 + v150),
             " %15u",
             *(_DWORD *)(a1 + 1160));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v151, v152, v153, v154, v155, v156, v157, v158, v26);
    scnprintf(v26, 256, "%20s", "UL pkt_iat_min: ");
    v160 = v159;
    scnprintf(v26 + v159, 256LL - v159, " %15llu", *(_QWORD *)(a1 + 88));
    v162 = v161 + v160;
    scnprintf(v26 + v162, 256LL - v162, " %15llu", *(_QWORD *)(a1 + 208));
    v164 = v162 + v163;
    scnprintf(v26 + v164, 256LL - v164, " %15llu", *(_QWORD *)(a1 + 328));
    v166 = v164 + v165;
    scnprintf(v26 + v166, 256LL - v166, " %15llu", *(_QWORD *)(a1 + 448));
    v168 = v166 + v167;
    scnprintf(v26 + v168, 256LL - v168, " %15llu", *(_QWORD *)(a1 + 568));
    v170 = v168 + v169;
    scnprintf(v26 + v170, 256LL - v170, " %15llu", *(_QWORD *)(a1 + 688));
    v172 = v170 + v171;
    scnprintf(v26 + v172, 256LL - v172, " %15llu", *(_QWORD *)(a1 + 808));
    v174 = v172 + v173;
    scnprintf(v26 + v174, 256LL - v174, " %15llu", *(_QWORD *)(a1 + 928));
    v176 = v174 + v175;
    scnprintf(v26 + v176, 256LL - v176, " %15llu", *(_QWORD *)(a1 + 1048));
    v178 = scnprintf(
             v26 + (unsigned __int16)(v176 + v177),
             256LL - (unsigned __int16)(v176 + v177),
             " %15llu",
             *(_QWORD *)(a1 + 1168));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v178, v179, v180, v181, v182, v183, v184, v185, v26);
    scnprintf(v26, 256, "%20s", "UL pkt_iat_max: ");
    v187 = v186;
    scnprintf(v26 + v186, 256LL - v186, " %15llu", *(_QWORD *)(a1 + 96));
    v189 = v188 + v187;
    scnprintf(v26 + v189, 256LL - v189, " %15llu", *(_QWORD *)(a1 + 216));
    v191 = v189 + v190;
    scnprintf(v26 + v191, 256LL - v191, " %15llu", *(_QWORD *)(a1 + 336));
    v193 = v191 + v192;
    scnprintf(v26 + v193, 256LL - v193, " %15llu", *(_QWORD *)(a1 + 456));
    v195 = v193 + v194;
    scnprintf(v26 + v195, 256LL - v195, " %15llu", *(_QWORD *)(a1 + 576));
    v197 = v195 + v196;
    scnprintf(v26 + v197, 256LL - v197, " %15llu", *(_QWORD *)(a1 + 696));
    v199 = v197 + v198;
    scnprintf(v26 + v199, 256LL - v199, " %15llu", *(_QWORD *)(a1 + 816));
    v201 = v199 + v200;
    scnprintf(v26 + v201, 256LL - v201, " %15llu", *(_QWORD *)(a1 + 936));
    v203 = v201 + v202;
    scnprintf(v26 + v203, 256LL - v203, " %15llu", *(_QWORD *)(a1 + 1056));
    v205 = scnprintf(
             v26 + (unsigned __int16)(v203 + v204),
             256LL - (unsigned __int16)(v203 + v204),
             " %15llu",
             *(_QWORD *)(a1 + 1176));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v205, v206, v207, v208, v209, v210, v211, v212, v26);
    scnprintf(v26, 256, "%20s", "UL pkt_iat_sum: ");
    v214 = v213;
    scnprintf(v26 + v213, 256LL - v213, " %15llu", *(_QWORD *)(a1 + 104));
    v216 = v215 + v214;
    scnprintf(v26 + v216, 256LL - v216, " %15llu", *(_QWORD *)(a1 + 224));
    v218 = v216 + v217;
    scnprintf(v26 + v218, 256LL - v218, " %15llu", *(_QWORD *)(a1 + 344));
    v220 = v218 + v219;
    scnprintf(v26 + v220, 256LL - v220, " %15llu", *(_QWORD *)(a1 + 464));
    v222 = v220 + v221;
    scnprintf(v26 + v222, 256LL - v222, " %15llu", *(_QWORD *)(a1 + 584));
    v224 = v222 + v223;
    scnprintf(v26 + v224, 256LL - v224, " %15llu", *(_QWORD *)(a1 + 704));
    v226 = v224 + v225;
    scnprintf(v26 + v226, 256LL - v226, " %15llu", *(_QWORD *)(a1 + 824));
    v228 = v226 + v227;
    scnprintf(v26 + v228, 256LL - v228, " %15llu", *(_QWORD *)(a1 + 944));
    v230 = v228 + v229;
    scnprintf(v26 + v230, 256LL - v230, " %15llu", *(_QWORD *)(a1 + 1064));
    v232 = scnprintf(
             v26 + (unsigned __int16)(v230 + v231),
             256LL - (unsigned __int16)(v230 + v231),
             " %15llu",
             *(_QWORD *)(a1 + 1184));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v232, v233, v234, v235, v236, v237, v238, v239, v26);
    scnprintf(v26, 256, "%20s", "DL bytes: ");
    v241 = v240;
    scnprintf(v26 + v240, 256LL - v240, " %15llu", *(_QWORD *)(a1 + 120));
    v243 = v242 + v241;
    scnprintf(v26 + v243, 256LL - v243, " %15llu", *(_QWORD *)(a1 + 240));
    v245 = v243 + v244;
    scnprintf(v26 + v245, 256LL - v245, " %15llu", *(_QWORD *)(a1 + 360));
    v247 = v245 + v246;
    scnprintf(v26 + v247, 256LL - v247, " %15llu", *(_QWORD *)(a1 + 480));
    v249 = v247 + v248;
    scnprintf(v26 + v249, 256LL - v249, " %15llu", *(_QWORD *)(a1 + 600));
    v251 = v249 + v250;
    scnprintf(v26 + v251, 256LL - v251, " %15llu", *(_QWORD *)(a1 + 720));
    v253 = v251 + v252;
    scnprintf(v26 + v253, 256LL - v253, " %15llu", *(_QWORD *)(a1 + 840));
    v255 = v253 + v254;
    scnprintf(v26 + v255, 256LL - v255, " %15llu", *(_QWORD *)(a1 + 960));
    v257 = v255 + v256;
    scnprintf(v26 + v257, 256LL - v257, " %15llu", *(_QWORD *)(a1 + 1080));
    v259 = scnprintf(
             v26 + (unsigned __int16)(v257 + v258),
             256LL - (unsigned __int16)(v257 + v258),
             " %15llu",
             *(_QWORD *)(a1 + 1200));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v259, v260, v261, v262, v263, v264, v265, v266, v26);
    scnprintf(v26, 256, "%20s", "DL pkts: ");
    v268 = v267;
    scnprintf(v26 + v267, 256LL - v267, " %15u", *(_DWORD *)(a1 + 128));
    v270 = v269 + v268;
    scnprintf(v26 + v270, 256LL - v270, " %15u", *(_DWORD *)(a1 + 248));
    v272 = v270 + v271;
    scnprintf(v26 + v272, 256LL - v272, " %15u", *(_DWORD *)(a1 + 368));
    v274 = v272 + v273;
    scnprintf(v26 + v274, 256LL - v274, " %15u", *(_DWORD *)(a1 + 488));
    v276 = v274 + v275;
    scnprintf(v26 + v276, 256LL - v276, " %15u", *(_DWORD *)(a1 + 608));
    v278 = v276 + v277;
    scnprintf(v26 + v278, 256LL - v278, " %15u", *(_DWORD *)(a1 + 728));
    v280 = v278 + v279;
    scnprintf(v26 + v280, 256LL - v280, " %15u", *(_DWORD *)(a1 + 848));
    v282 = v280 + v281;
    scnprintf(v26 + v282, 256LL - v282, " %15u", *(_DWORD *)(a1 + 968));
    v284 = v282 + v283;
    scnprintf(v26 + v284, 256LL - v284, " %15u", *(_DWORD *)(a1 + 1088));
    v286 = scnprintf(
             v26 + (unsigned __int16)(v284 + v285),
             256LL - (unsigned __int16)(v284 + v285),
             " %15u",
             *(_DWORD *)(a1 + 1208));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v286, v287, v288, v289, v290, v291, v292, v293, v26);
    scnprintf(v26, 256, "%20s", "DL pkt_size_min: ");
    v295 = v294;
    scnprintf(v26 + v294, 256LL - v294, " %15u", *(_DWORD *)(a1 + 132));
    v297 = v296 + v295;
    scnprintf(v26 + v297, 256LL - v297, " %15u", *(_DWORD *)(a1 + 252));
    v299 = v297 + v298;
    scnprintf(v26 + v299, 256LL - v299, " %15u", *(_DWORD *)(a1 + 372));
    v301 = v299 + v300;
    scnprintf(v26 + v301, 256LL - v301, " %15u", *(_DWORD *)(a1 + 492));
    v303 = v301 + v302;
    scnprintf(v26 + v303, 256LL - v303, " %15u", *(_DWORD *)(a1 + 612));
    v305 = v303 + v304;
    scnprintf(v26 + v305, 256LL - v305, " %15u", *(_DWORD *)(a1 + 732));
    v307 = v305 + v306;
    scnprintf(v26 + v307, 256LL - v307, " %15u", *(_DWORD *)(a1 + 852));
    v309 = v307 + v308;
    scnprintf(v26 + v309, 256LL - v309, " %15u", *(_DWORD *)(a1 + 972));
    v311 = v309 + v310;
    scnprintf(v26 + v311, 256LL - v311, " %15u", *(_DWORD *)(a1 + 1092));
    v313 = scnprintf(
             v26 + (unsigned __int16)(v311 + v312),
             256LL - (unsigned __int16)(v311 + v312),
             " %15u",
             *(_DWORD *)(a1 + 1212));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v313, v314, v315, v316, v317, v318, v319, v320, v26);
    scnprintf(v26, 256, "%20s", "DL pkt_size_max: ");
    v322 = v321;
    scnprintf(v26 + v321, 256LL - v321, " %15u", *(_DWORD *)(a1 + 136));
    v324 = v323 + v322;
    scnprintf(v26 + v324, 256LL - v324, " %15u", *(_DWORD *)(a1 + 256));
    v326 = v324 + v325;
    scnprintf(v26 + v326, 256LL - v326, " %15u", *(_DWORD *)(a1 + 376));
    v328 = v326 + v327;
    scnprintf(v26 + v328, 256LL - v328, " %15u", *(_DWORD *)(a1 + 496));
    v330 = v328 + v329;
    scnprintf(v26 + v330, 256LL - v330, " %15u", *(_DWORD *)(a1 + 616));
    v332 = v330 + v331;
    scnprintf(v26 + v332, 256LL - v332, " %15u", *(_DWORD *)(a1 + 736));
    v334 = v332 + v333;
    scnprintf(v26 + v334, 256LL - v334, " %15u", *(_DWORD *)(a1 + 856));
    v336 = v334 + v335;
    scnprintf(v26 + v336, 256LL - v336, " %15u", *(_DWORD *)(a1 + 976));
    v338 = v336 + v337;
    scnprintf(v26 + v338, 256LL - v338, " %15u", *(_DWORD *)(a1 + 1096));
    v340 = scnprintf(
             v26 + (unsigned __int16)(v338 + v339),
             256LL - (unsigned __int16)(v338 + v339),
             " %15u",
             *(_DWORD *)(a1 + 1216));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v340, v341, v342, v343, v344, v345, v346, v347, v26);
    scnprintf(v26, 256, "%20s", "DL pkt_iat_min: ");
    v349 = v348;
    scnprintf(v26 + v348, 256LL - v348, " %15llu", *(_QWORD *)(a1 + 144));
    v351 = v350 + v349;
    scnprintf(v26 + v351, 256LL - v351, " %15llu", *(_QWORD *)(a1 + 264));
    v353 = v351 + v352;
    scnprintf(v26 + v353, 256LL - v353, " %15llu", *(_QWORD *)(a1 + 384));
    v355 = v353 + v354;
    scnprintf(v26 + v355, 256LL - v355, " %15llu", *(_QWORD *)(a1 + 504));
    v357 = v355 + v356;
    scnprintf(v26 + v357, 256LL - v357, " %15llu", *(_QWORD *)(a1 + 624));
    v359 = v357 + v358;
    scnprintf(v26 + v359, 256LL - v359, " %15llu", *(_QWORD *)(a1 + 744));
    v361 = v359 + v360;
    scnprintf(v26 + v361, 256LL - v361, " %15llu", *(_QWORD *)(a1 + 864));
    v363 = v361 + v362;
    scnprintf(v26 + v363, 256LL - v363, " %15llu", *(_QWORD *)(a1 + 984));
    v365 = v363 + v364;
    scnprintf(v26 + v365, 256LL - v365, " %15llu", *(_QWORD *)(a1 + 1104));
    v367 = scnprintf(
             v26 + (unsigned __int16)(v365 + v366),
             256LL - (unsigned __int16)(v365 + v366),
             " %15llu",
             *(_QWORD *)(a1 + 1224));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v367, v368, v369, v370, v371, v372, v373, v374, v26);
    scnprintf(v26, 256, "%20s", "DL pkt_iat_max: ");
    v376 = v375;
    scnprintf(v26 + v375, 256LL - v375, " %15llu", *(_QWORD *)(a1 + 152));
    v378 = v377 + v376;
    scnprintf(v26 + v378, 256LL - v378, " %15llu", *(_QWORD *)(a1 + 272));
    v380 = v378 + v379;
    scnprintf(v26 + v380, 256LL - v380, " %15llu", *(_QWORD *)(a1 + 392));
    v382 = v380 + v381;
    scnprintf(v26 + v382, 256LL - v382, " %15llu", *(_QWORD *)(a1 + 512));
    v384 = v382 + v383;
    scnprintf(v26 + v384, 256LL - v384, " %15llu", *(_QWORD *)(a1 + 632));
    v386 = v384 + v385;
    scnprintf(v26 + v386, 256LL - v386, " %15llu", *(_QWORD *)(a1 + 752));
    v388 = v386 + v387;
    scnprintf(v26 + v388, 256LL - v388, " %15llu", *(_QWORD *)(a1 + 872));
    v390 = v388 + v389;
    scnprintf(v26 + v390, 256LL - v390, " %15llu", *(_QWORD *)(a1 + 992));
    v392 = v390 + v391;
    scnprintf(v26 + v392, 256LL - v392, " %15llu", *(_QWORD *)(a1 + 1112));
    v394 = scnprintf(
             v26 + (unsigned __int16)(v392 + v393),
             256LL - (unsigned __int16)(v392 + v393),
             " %15llu",
             *(_QWORD *)(a1 + 1232));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v394, v395, v396, v397, v398, v399, v400, v401, v26);
    scnprintf(v26, 256, "%20s", "DL pkt_iat_sum: ");
    v403 = v402;
    scnprintf(v26 + v402, 256LL - v402, " %15llu", *(_QWORD *)(a1 + 160));
    v405 = v404 + v403;
    scnprintf(v26 + v405, 256LL - v405, " %15llu", *(_QWORD *)(a1 + 280));
    v407 = v405 + v406;
    scnprintf(v26 + v407, 256LL - v407, " %15llu", *(_QWORD *)(a1 + 400));
    v409 = v407 + v408;
    scnprintf(v26 + v409, 256LL - v409, " %15llu", *(_QWORD *)(a1 + 520));
    v411 = v409 + v410;
    scnprintf(v26 + v411, 256LL - v411, " %15llu", *(_QWORD *)(a1 + 640));
    v413 = v411 + v412;
    scnprintf(v26 + v413, 256LL - v413, " %15llu", *(_QWORD *)(a1 + 760));
    v415 = v413 + v414;
    scnprintf(v26 + v415, 256LL - v415, " %15llu", *(_QWORD *)(a1 + 880));
    v417 = v415 + v416;
    scnprintf(v26 + v417, 256LL - v417, " %15llu", *(_QWORD *)(a1 + 1000));
    v419 = v417 + v418;
    scnprintf(v26 + v419, 256LL - v419, " %15llu", *(_QWORD *)(a1 + 1120));
    v421 = scnprintf(
             v26 + (unsigned __int16)(v419 + v420),
             256LL - (unsigned __int16)(v419 + v420),
             " %15llu",
             *(_QWORD *)(a1 + 1240));
    qdf_trace_msg(0x48u, 8u, "STC: %s", v421, v422, v423, v424, v425, v426, v427, v428, v26);
    result = _qdf_mem_free(v26);
  }
  if ( (v16 & 2) == 0 )
    return result;
LABEL_5:
  v429 = *(unsigned __int8 *)(a1 + 1688) - 1LL;
  if ( v429 >= 3 )
  {
    __break(0x5512u);
    return os_if_dp_send_flow_stats(result, v5, v6, v7);
  }
  else
  {
    v430 = a1 + 216LL * (int)v429;
    qdf_trace_msg(0x48u, 8u, "STC: Burst TxRx Stats:", v8, v9, v10, v11, v12, v13, v14, v15);
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: Window duration: %u",
      v431,
      v432,
      v433,
      v434,
      v435,
      v436,
      v437,
      v438,
      *(unsigned int *)(v430 + 1256));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15s %15s",
      v439,
      v440,
      v441,
      v442,
      v443,
      v444,
      v445,
      v446,
      &unk_98C763,
      "UL",
      "DL");
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15llu\t\t\t%15llu",
      v447,
      v448,
      v449,
      v450,
      v451,
      v452,
      v453,
      v454,
      "bytes: ",
      *(_QWORD *)(v430 + 1264),
      *(_QWORD *)(v430 + 1320));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15u\t\t\t%15u",
      v455,
      v456,
      v457,
      v458,
      v459,
      v460,
      v461,
      v462,
      "pkts: ",
      *(unsigned int *)(v430 + 1272),
      *(unsigned int *)(v430 + 1328));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15u\t\t\t%15u",
      v463,
      v464,
      v465,
      v466,
      v467,
      v468,
      v469,
      v470,
      "pkt_size_min: ",
      *(unsigned int *)(v430 + 1276),
      *(unsigned int *)(v430 + 1332));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15u\t\t\t%15u",
      v471,
      v472,
      v473,
      v474,
      v475,
      v476,
      v477,
      v478,
      "pkt_size_max: ",
      *(unsigned int *)(v430 + 1280),
      *(unsigned int *)(v430 + 1336));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15llu\t\t\t%15llu",
      v479,
      v480,
      v481,
      v482,
      v483,
      v484,
      v485,
      v486,
      "pkt_iat_min: ",
      *(_QWORD *)(v430 + 1288),
      *(_QWORD *)(v430 + 1344));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15llu\t\t\t%15llu",
      v487,
      v488,
      v489,
      v490,
      v491,
      v492,
      v493,
      v494,
      "pkt_iat_max: ",
      *(_QWORD *)(v430 + 1296),
      *(_QWORD *)(v430 + 1352));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15llu\t\t\t%15llu",
      v495,
      v496,
      v497,
      v498,
      v499,
      v500,
      v501,
      v502,
      "pkt_iat_sum: ",
      *(_QWORD *)(v430 + 1304),
      *(_QWORD *)(v430 + 1360));
    qdf_trace_msg(0x48u, 8u, "STC: Burst Stats: ", v503, v504, v505, v506, v507, v508, v509, v510);
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15s %15s",
      v511,
      v512,
      v513,
      v514,
      v515,
      v516,
      v517,
      v518,
      &unk_98C763,
      "UL",
      "DL");
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15llu\t\t\t%15llu",
      v519,
      v520,
      v521,
      v522,
      v523,
      v524,
      v525,
      v526,
      "burst_duration_min: ",
      *(_QWORD *)(v430 + 1376),
      *(_QWORD *)(v430 + 1424));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15llu\t\t\t%15llu",
      v527,
      v528,
      v529,
      v530,
      v531,
      v532,
      v533,
      v534,
      "burst_duration_max: ",
      *(_QWORD *)(v430 + 1384),
      *(_QWORD *)(v430 + 1432));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15llu\t\t\t%15llu",
      v535,
      v536,
      v537,
      v538,
      v539,
      v540,
      v541,
      v542,
      "burst_duration_sum: ",
      *(_QWORD *)(v430 + 1392),
      *(_QWORD *)(v430 + 1440));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15u\t\t\t%15u",
      v543,
      v544,
      v545,
      v546,
      v547,
      v548,
      v549,
      v550,
      "burst_size_min: ",
      *(unsigned int *)(v430 + 1400),
      *(unsigned int *)(v430 + 1448));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15u\t\t\t%15u",
      v551,
      v552,
      v553,
      v554,
      v555,
      v556,
      v557,
      v558,
      "burst_size_max: ",
      *(unsigned int *)(v430 + 1404),
      *(unsigned int *)(v430 + 1452));
    qdf_trace_msg(
      0x48u,
      8u,
      "STC: %20s %15llu\t\t\t%15llu",
      v559,
      v560,
      v561,
      v562,
      v563,
      v564,
      v565,
      v566,
      "burst_size_sum: ",
      *(_QWORD *)(v430 + 1408),
      *(_QWORD *)(v430 + 1456));
    return qdf_trace_msg(
             0x48u,
             8u,
             "STC: %20s %15u\t\t\t%15u",
             v567,
             v568,
             v569,
             v570,
             v571,
             v572,
             v573,
             v574,
             "burst_count: ",
             *(unsigned int *)(v430 + 1416),
             *(unsigned int *)(v430 + 1464));
  }
}
