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
  unsigned __int8 v20; // w1
  int v22; // w20
  int opmode_from_vdev_id; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w22
  __int64 v33; // x8
  __int64 v34; // x0
  unsigned int *v35; // x24
  __int64 result; // x0
  __int64 v37; // x0
  __int64 v38; // x25
  _BOOL4 v39; // w20
  int v40; // w28
  unsigned int v41; // w27
  unsigned int v42; // w23
  unsigned int *v43; // x26
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  int v52; // w0
  int v53; // w0
  unsigned __int64 v54; // x8
  unsigned int v55; // w20
  __int64 v56; // x0
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x28
  _QWORD *v66; // x24
  void *v67; // x23
  __int64 v68; // x26
  _QWORD *v69; // x27
  unsigned int v70; // w25
  __int64 v71; // x8
  int v72; // w12
  int v73; // w9
  unsigned int v74; // w28
  int v75; // w20
  unsigned int v76; // w13
  int v77; // w14
  unsigned int v78; // w9
  bool v79; // zf
  __int64 v80; // x22
  unsigned int v81; // w10
  int v82; // w8
  double v83; // d0
  double v84; // d1
  double v85; // d2
  double v86; // d3
  double v87; // d4
  double v88; // d5
  double v89; // d6
  double v90; // d7
  int v91; // w8
  int v92; // w10
  int v93; // w8
  bool v94; // cc
  unsigned int v95; // w8
  __int64 v96; // x20
  __int64 v97; // x8
  int v98; // w8
  int *v99; // x22
  int v100; // t1
  int v101; // w9
  int v102; // w8
  int v103; // w10
  int v104; // w8
  bool v105; // cc
  int v106; // w10
  int v107; // w8
  bool v108; // cc
  int v109; // w10
  int v110; // w8
  bool v111; // cc
  int v112; // w10
  int v113; // w8
  bool v114; // cc
  int v115; // w10
  int v116; // w8
  bool v117; // cc
  int v118; // w10
  int v119; // w8
  bool v120; // cc
  int v121; // w10
  int v122; // w8
  bool v123; // cc
  int v124; // w10
  int v125; // w8
  bool v126; // cc
  int v127; // w10
  int v128; // w8
  bool v129; // cc
  int v130; // w10
  int v131; // w8
  bool v132; // cc
  int v133; // w10
  int v134; // w8
  bool v135; // cc
  int v136; // w10
  int v137; // w8
  bool v138; // cc
  int v139; // w10
  int v140; // w8
  bool v141; // cc
  int v142; // w10
  int v143; // w8
  bool v144; // cc
  int v145; // w10
  int v146; // w8
  bool v147; // cc
  int v148; // w10
  int v149; // w8
  bool v150; // cc
  int v151; // w10
  int v152; // w8
  bool v153; // cc
  __int64 v154; // x9
  int v155; // t1
  int v156; // w9
  bool v157; // cc
  int v158; // w10
  int v159; // w8
  bool v160; // cc
  int v161; // w10
  int v162; // w8
  bool v163; // cc
  int v164; // w10
  int v165; // w8
  bool v166; // cc
  int v167; // w10
  int v168; // w8
  bool v169; // cc
  int v170; // w10
  int v171; // w8
  bool v172; // cc
  int v173; // w10
  int v174; // w8
  bool v175; // cc
  int v176; // w10
  int v177; // w8
  bool v178; // cc
  int v179; // w10
  int v180; // w8
  bool v181; // cc
  int v182; // w10
  int v183; // w8
  bool v184; // cc
  int v185; // w10
  int v186; // w8
  bool v187; // cc
  int v188; // w10
  int v189; // w8
  bool v190; // cc
  int v191; // w10
  int v192; // w8
  bool v193; // cc
  double v194; // d0
  double v195; // d1
  double v196; // d2
  double v197; // d3
  double v198; // d4
  double v199; // d5
  double v200; // d6
  double v201; // d7
  int v202; // w0
  __int64 v203; // x23
  __int64 v204; // x24
  __int64 v205; // x26
  int *v206; // x25
  int v207; // w9
  unsigned int *v208; // x8
  __int64 v209; // x8
  int v210; // w9
  int v211; // w11
  bool v212; // cc
  __int64 v213; // x3
  unsigned int *v214; // x20
  unsigned int v215; // w8
  int v216; // w9
  unsigned int v217; // w10
  unsigned int v218; // w11
  unsigned int v219; // w13
  unsigned int v220; // w12
  double v221; // d0
  double v222; // d1
  double v223; // d2
  double v224; // d3
  double v225; // d4
  double v226; // d5
  double v227; // d6
  double v228; // d7
  int v229; // w25
  unsigned int v230; // w27
  unsigned int v231; // w23
  unsigned int v232; // w28
  int v233; // w26
  unsigned int v234; // w0
  __int64 v235; // x11
  unsigned int v236; // w8
  unsigned __int64 v237; // x9
  __int64 v238; // x10
  __int64 v239; // x11
  bool v240; // w12
  int v241; // w9
  unsigned int v242; // w8
  char v243; // w22
  __int64 v244; // x8
  int *v245; // x9
  int v246; // t1
  double v247; // d0
  double v248; // d1
  double v249; // d2
  double v250; // d3
  double v251; // d4
  double v252; // d5
  double v253; // d6
  double v254; // d7
  int v255; // w8
  unsigned int v256; // w8
  _BYTE *v257; // x0
  unsigned int v258; // w1
  int v259; // w16
  int v260; // w14
  int v261; // w13
  int v262; // w12
  int v263; // w11
  int v264; // w15
  int v265; // w8
  unsigned int v266; // w9
  unsigned int v267; // w10
  int v268; // w17
  unsigned int v269; // w16
  int v270; // w1
  int v271; // w15
  unsigned __int16 v272; // w0
  unsigned int v273; // w17
  unsigned int v274; // w15
  unsigned int v275; // w0
  unsigned int v276; // w28
  unsigned int v277; // w15
  _DWORD *channel_status; // x0
  unsigned int v279; // w8
  int v280; // w9
  int v281; // w14
  unsigned int v282; // w17
  int v283; // w16
  unsigned int v284; // w15
  int v285; // w13
  unsigned int v286; // w26
  int v287; // w14
  unsigned int v288; // w15
  unsigned int v289; // w13
  int v290; // w12
  unsigned int v291; // w27
  int v292; // w13
  unsigned int v293; // w12
  int v294; // w11
  unsigned int v295; // w22
  int v296; // w12
  unsigned int v297; // w11
  int v298; // w24
  unsigned int v299; // w28
  const char *v300; // x2
  unsigned int v301; // w16
  int v302; // w4
  int v303; // w8
  const char *v304; // x2
  unsigned int v305; // w8
  int v306; // w12
  int v307; // w10
  unsigned int v308; // w8
  unsigned int v309; // w10
  unsigned int v310; // w8
  __int64 v311; // x8
  unsigned int v312; // w1
  char v313; // w27
  __int64 v314; // x10
  __int64 v315; // x9
  unsigned __int8 *v316; // x11
  unsigned int v317; // w22
  __int64 v318; // x8
  unsigned __int8 *v319; // x9
  int v320; // w8
  char v321; // w9
  unsigned int v322; // w8
  double v323; // d0
  double v324; // d1
  double v325; // d2
  double v326; // d3
  double v327; // d4
  double v328; // d5
  double v329; // d6
  double v330; // d7
  unsigned int v331; // w8
  unsigned int v332; // w9
  unsigned int v333; // w4
  int v334; // w0
  __int64 v335; // x20
  unsigned __int64 v336; // x22
  __int64 v337; // x25
  __int64 v338; // x8
  double v339; // d0
  double v340; // d1
  double v341; // d2
  double v342; // d3
  double v343; // d4
  double v344; // d5
  double v345; // d6
  double v346; // d7
  unsigned int v347; // w20
  unsigned int v348; // w20
  unsigned int v349; // w20
  int v350; // w8
  int v351; // w24
  int v352; // w22
  int v353; // w8
  int next_lower_bandwidth; // w0
  unsigned int v355; // w26
  int v356; // w0
  double v357; // d0
  double v358; // d1
  double v359; // d2
  double v360; // d3
  double v361; // d4
  double v362; // d5
  double v363; // d6
  double v364; // d7
  unsigned int *v365; // x20
  unsigned __int64 v366; // x23
  int v367; // w0
  __int64 v368; // x28
  __int64 v369; // x0
  unsigned __int64 v370; // x23
  unsigned int *v371; // x24
  _BYTE *v372; // x20
  __int64 v373; // x0
  unsigned int v374; // w2
  unsigned __int64 v375; // x8
  unsigned int v376; // w9
  unsigned int v377; // w10
  unsigned int *v378; // x20
  unsigned int v379; // w22
  unsigned int v380; // w9
  int is_channel_present_in_acs_list; // w0
  unsigned int v382; // w8
  unsigned int v383; // w2
  bool v384; // cc
  int v385; // w9
  int v386; // w0
  unsigned int v387; // w8
  unsigned int v388; // w2
  bool v389; // cc
  int v390; // w9
  int v391; // w0
  unsigned int v392; // w8
  unsigned int v393; // w2
  unsigned int v394; // w22
  int v395; // w0
  double v396; // d0
  double v397; // d1
  double v398; // d2
  double v399; // d3
  double v400; // d4
  double v401; // d5
  double v402; // d6
  double v403; // d7
  _DWORD *v404; // x8
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
  unsigned __int64 v421; // x8
  int v422; // w4
  int v423; // w0
  unsigned int v424; // w8
  unsigned __int64 v425; // x23
  double v426; // d0
  double v427; // d1
  double v428; // d2
  double v429; // d3
  double v430; // d4
  double v431; // d5
  double v432; // d6
  double v433; // d7
  unsigned int *v434; // x26
  __int64 v435; // x23
  unsigned __int64 v436; // x20
  unsigned int *v437; // x27
  unsigned int v438; // t1
  unsigned __int8 v439; // w0
  unsigned __int64 v440; // x8
  unsigned int *v441; // x20
  unsigned int v442; // w11
  unsigned int v443; // w9
  unsigned int v444; // w12
  unsigned int v445; // w8
  unsigned int v446; // w10
  unsigned int v447; // w8
  unsigned int v448; // w9
  unsigned int v449; // w8
  int v450; // w0
  unsigned __int8 v451; // w8
  unsigned __int64 v452; // x9
  unsigned int *v453; // x12
  unsigned int *v454; // x24
  __int64 v455; // x0
  unsigned __int64 v456; // x27
  unsigned int *v457; // x28
  _BYTE *v458; // x20
  __int64 v459; // x0
  unsigned int v460; // w8
  unsigned __int64 v461; // x9
  unsigned int v462; // w10
  unsigned int *v463; // x12
  __int64 v464; // x23
  unsigned int v465; // w20
  __int64 v466; // x22
  char v467; // w26
  unsigned int v468; // w8
  unsigned int v469; // w2
  bool v470; // cc
  int v471; // w0
  unsigned int v472; // w22
  unsigned __int64 v473; // x8
  unsigned int v474; // w28
  int v475; // w0
  unsigned int v476; // w10
  unsigned int *v477; // x9
  double v478; // d0
  double v479; // d1
  double v480; // d2
  double v481; // d3
  double v482; // d4
  double v483; // d5
  double v484; // d6
  double v485; // d7
  int v486; // w0
  int v487; // w20
  unsigned int v488; // w8
  int v489; // w0
  unsigned __int8 v490; // w8
  unsigned __int64 v491; // x9
  unsigned int *v492; // x11
  unsigned int *v493; // x26
  __int64 v494; // x0
  unsigned int v495; // w8
  __int64 v496; // x23
  unsigned int v497; // w28
  int v498; // w20
  unsigned int *i; // x27
  int v500; // w0
  __int64 v501; // x0
  unsigned int *v502; // x24
  __int64 v503; // x0
  __int64 v504; // x27
  __int64 v505; // x22
  unsigned __int64 v506; // x28
  unsigned int *v507; // x23
  double v508; // d0
  double v509; // d1
  double v510; // d2
  double v511; // d3
  double v512; // d4
  double v513; // d5
  double v514; // d6
  double v515; // d7
  unsigned int v516; // w2
  unsigned int v517; // w8
  unsigned int v518; // w10
  __int64 v519; // x26
  unsigned int v520; // w22
  int v521; // w0
  unsigned int v522; // w8
  _BOOL4 v523; // w20
  int v524; // w27
  double v525; // d0
  double v526; // d1
  double v527; // d2
  double v528; // d3
  double v529; // d4
  double v530; // d5
  double v531; // d6
  double v532; // d7
  unsigned __int64 v533; // x8
  int v534; // w0
  unsigned int v535; // w8
  double v536; // d0
  double v537; // d1
  double v538; // d2
  double v539; // d3
  double v540; // d4
  double v541; // d5
  double v542; // d6
  double v543; // d7
  unsigned int v544; // w0
  const char *v545; // x2
  const char *v546; // x3
  unsigned int v547; // w8
  _BYTE *v548; // x9
  unsigned int v549; // w22
  unsigned int v550; // w20
  unsigned int *v551; // x23
  __int64 v552; // x0
  double v553; // d0
  double v554; // d1
  double v555; // d2
  double v556; // d3
  double v557; // d4
  double v558; // d5
  double v559; // d6
  double v560; // d7
  __int64 v561; // x21
  double v562; // d0
  double v563; // d1
  double v564; // d2
  double v565; // d3
  double v566; // d4
  double v567; // d5
  double v568; // d6
  double v569; // d7
  unsigned int v570; // w8
  unsigned int v571; // w28
  int v572; // w25
  _BYTE *v573; // x26
  unsigned int v574; // w4
  int v575; // w0
  int v576; // [xsp+44h] [xbp-ECh]
  int v577; // [xsp+48h] [xbp-E8h]
  unsigned int v578; // [xsp+4Ch] [xbp-E4h]
  int v579; // [xsp+4Ch] [xbp-E4h]
  int v580; // [xsp+50h] [xbp-E0h]
  unsigned int v581; // [xsp+50h] [xbp-E0h]
  int v582; // [xsp+54h] [xbp-DCh]
  int v583; // [xsp+54h] [xbp-DCh]
  unsigned int v584; // [xsp+54h] [xbp-DCh]
  int v585; // [xsp+58h] [xbp-D8h]
  unsigned int v586; // [xsp+58h] [xbp-D8h]
  int v587; // [xsp+5Ch] [xbp-D4h]
  unsigned int v588; // [xsp+5Ch] [xbp-D4h]
  int v589; // [xsp+60h] [xbp-D0h]
  unsigned int v590; // [xsp+60h] [xbp-D0h]
  int v591; // [xsp+64h] [xbp-CCh]
  unsigned int v592; // [xsp+64h] [xbp-CCh]
  int v593; // [xsp+68h] [xbp-C8h]
  unsigned int v594; // [xsp+68h] [xbp-C8h]
  int v595; // [xsp+68h] [xbp-C8h]
  int is_sap_freq_allowed; // [xsp+6Ch] [xbp-C4h]
  unsigned int v597; // [xsp+6Ch] [xbp-C4h]
  int v598; // [xsp+6Ch] [xbp-C4h]
  int v599; // [xsp+70h] [xbp-C0h]
  int v600; // [xsp+70h] [xbp-C0h]
  int v601; // [xsp+7Ch] [xbp-B4h]
  unsigned int v602; // [xsp+7Ch] [xbp-B4h]
  int v603; // [xsp+7Ch] [xbp-B4h]
  int v604; // [xsp+7Ch] [xbp-B4h]
  int v605; // [xsp+80h] [xbp-B0h]
  unsigned int v606; // [xsp+80h] [xbp-B0h]
  __int64 v607; // [xsp+80h] [xbp-B0h]
  int v608; // [xsp+80h] [xbp-B0h]
  unsigned int v609; // [xsp+84h] [xbp-ACh]
  unsigned int v610; // [xsp+84h] [xbp-ACh]
  unsigned int v611; // [xsp+84h] [xbp-ACh]
  unsigned int v612; // [xsp+88h] [xbp-A8h]
  unsigned int v613; // [xsp+90h] [xbp-A0h]
  int v614; // [xsp+90h] [xbp-A0h]
  unsigned int v615; // [xsp+90h] [xbp-A0h]
  __int64 v616; // [xsp+90h] [xbp-A0h]
  __int64 v617; // [xsp+90h] [xbp-A0h]
  int v619; // [xsp+9Ch] [xbp-94h]
  int v620; // [xsp+9Ch] [xbp-94h]
  int v621; // [xsp+9Ch] [xbp-94h]
  int v624; // [xsp+B4h] [xbp-7Ch]
  unsigned int v625; // [xsp+B4h] [xbp-7Ch]
  unsigned int v626; // [xsp+B4h] [xbp-7Ch]
  unsigned int v627; // [xsp+B4h] [xbp-7Ch]
  unsigned int v628; // [xsp+B4h] [xbp-7Ch]
  unsigned int v630; // [xsp+B8h] [xbp-78h]
  int v631; // [xsp+B8h] [xbp-78h]
  int v632; // [xsp+B8h] [xbp-78h]
  int v633; // [xsp+B8h] [xbp-78h]
  __int64 v634; // [xsp+C0h] [xbp-70h]
  int v635; // [xsp+C0h] [xbp-70h]
  unsigned __int64 v636; // [xsp+C8h] [xbp-68h]
  unsigned int v637; // [xsp+C8h] [xbp-68h]
  int v638; // [xsp+C8h] [xbp-68h]
  __int64 v639; // [xsp+C8h] [xbp-68h]
  _BOOL4 v640; // [xsp+D0h] [xbp-60h]
  unsigned __int64 v641; // [xsp+D0h] [xbp-60h]
  unsigned int v642; // [xsp+D0h] [xbp-60h]
  unsigned int v643; // [xsp+D0h] [xbp-60h]
  int v644; // [xsp+D0h] [xbp-60h]
  __int64 v645; // [xsp+D8h] [xbp-58h]
  int v646; // [xsp+E4h] [xbp-4Ch] BYREF
  _QWORD *v647; // [xsp+E8h] [xbp-48h] BYREF
  _QWORD *v648; // [xsp+F0h] [xbp-40h] BYREF
  int v649; // [xsp+F8h] [xbp-38h]
  char v650; // [xsp+FCh] [xbp-34h]
  __int16 v651; // [xsp+100h] [xbp-30h]
  unsigned __int16 v652; // [xsp+104h] [xbp-2Ch]
  __int64 v653; // [xsp+108h] [xbp-28h] BYREF
  __int64 v654; // [xsp+110h] [xbp-20h]
  __int16 v655; // [xsp+11Ch] [xbp-14h] BYREF
  char v656; // [xsp+11Eh] [xbp-12h]
  __int64 v657; // [xsp+120h] [xbp-10h]

  v657 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v656 = 0;
  v655 = 0;
  v646 = 0;
  if ( a2 >= 6u )
LABEL_905:
    __break(0x5512u);
  v17 = *(_QWORD *)(a1 + 16LL * a2 + 14816);
  v18 = *(_QWORD *)(v17 + 1536);
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
    goto LABEL_42;
  }
  v19 = *(_QWORD *)(a1 + 21560);
  v20 = *(_BYTE *)(v17 + 12);
  v22 = *(unsigned __int16 *)(v18 + 42);
  v645 = v17;
  LOBYTE(v653) = 0;
  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(v19, v20);
  if ( opmode_from_vdev_id == 17 )
    goto LABEL_40;
  v32 = opmode_from_vdev_id;
  v33 = *(unsigned __int8 *)(a1 + 16532);
  a4[8] = v33;
  v34 = _qdf_mem_malloc(24 * v33, "sap_chan_sel_init", 448);
  if ( !v34 )
    goto LABEL_40;
  *(_QWORD *)a4 = v34;
  v35 = (unsigned int *)v34;
  policy_mgr_get_sta_sap_scc_on_dfs_chnl(*(_QWORD *)(a1 + 21552), &v653);
  v640 = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 3168LL) == 1 && *(_DWORD *)(v645 + 1620) != 2;
  v37 = _qdf_mem_malloc(0x96u, "sap_chan_sel_init", 467);
  if ( !v37 )
  {
LABEL_40:
    qdf_trace_msg(
      0x39u,
      2u,
      "%s: vdev %d ch select initialization failed",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "sap_sort_channel_list",
      a2);
    goto LABEL_41;
  }
  v38 = v37;
  v601 = v22;
  if ( a4[8] )
  {
    v39 = v640;
    v40 = 0;
    v41 = 0;
    v42 = 0;
    v43 = (unsigned int *)(a1 + 16536);
    while ( 1 )
    {
      *v35 = *v43;
      *((_QWORD *)v35 + 1) = 0x6828FFFFFF9CLL;
      if ( v41 >= 0x8B )
      {
        qdf_trace_msg(
          0x39u,
          8u,
          "ACS Invalid freq(%d): %s",
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          (unsigned __int8)v40,
          v38);
        v41 = 0;
        v40 = 0;
      }
      if ( (sap_dfs_is_channel_in_nol_list(v645, *v43, 0) & 1) != 0 )
      {
        v24 = scnprintf(v38 + v41, 150 - v41, "%d[%d] ", *v43, 0);
      }
      else if ( v39
             && ((unsigned __int8)v653 != 1 || (policy_mgr_is_sta_sap_scc(*(_QWORD *)(a1 + 21552), *v35, 1) & 1) != 0)
             || (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21560), *v35, v44, v45, v46, v47, v48, v49, v50, v51) & 1) == 0 )
      {
        if ( (policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21552), v32, *v43) & 1) != 0 )
        {
          if ( *v43 == 2484 && *(_DWORD *)(v645 + 1484) != 4 )
          {
            v24 = scnprintf(v38 + v41, 150 - v41, "%d[%d] ", 2484, 5);
          }
          else
          {
            if ( (wlan_reg_is_dsrc_freq() & 1) == 0 )
            {
              if ( (policy_mgr_is_sap_go_interface_allowed_on_indoor(
                      *(_QWORD *)(a1 + 21560),
                      *(unsigned __int8 *)(v645 + 12),
                      *v43)
                  & 1) != 0 )
              {
                if ( (wlansap_is_channel_present_in_acs_list(
                        *v43,
                        *(_QWORD *)(*(_QWORD *)(v645 + 1536) + 16LL),
                        *(unsigned __int8 *)(*(_QWORD *)(v645 + 1536) + 24LL))
                    & 1) != 0
                  || (wlansap_is_channel_present_in_acs_list(
                        *v35,
                        *(_QWORD *)(*(_QWORD *)(v645 + 1536) + 32LL),
                        *(unsigned __int8 *)(*(_QWORD *)(v645 + 1536) + 40LL))
                    & 1) != 0 )
                {
                  v35[3] = 0;
                  *((_BYTE *)v35 + 20) = 1;
LABEL_38:
                  v39 = v640;
                  goto LABEL_29;
                }
                v24 = scnprintf(v38 + v41, 150 - v41, "%d[%d] ", *v43, 8);
              }
              else
              {
                v24 = scnprintf(v38 + v41, 150 - v41, "%d[%d] ", *v43, 7);
              }
              ++v40;
              v41 += v53;
              goto LABEL_38;
            }
            v24 = scnprintf(v38 + v41, 150 - v41, "%d[%d] ", *v35, 6);
          }
        }
        else
        {
          v24 = scnprintf(v38 + v41, 150 - v41, "%d[%d] ", *v43, 3);
        }
      }
      else
      {
        v24 = scnprintf(v38 + v41, 150 - v41, "%d[%d] ", *v35, 2);
      }
      ++v40;
      v41 += v52;
LABEL_29:
      ++v42;
      ++v43;
      v35 += 6;
      if ( v42 >= (unsigned __int8)a4[8] )
      {
        if ( v41 )
          qdf_trace_msg(
            0x39u,
            8u,
            "ACS Invalid freq(%d): %s",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            (unsigned __int8)v40,
            v38);
        break;
      }
    }
  }
  _qdf_mem_free(v38);
  v54 = *(_QWORD *)a4;
  v55 = (unsigned __int8)a4[8];
  v647 = nullptr;
  v648 = nullptr;
  v636 = v54;
  v653 = 0;
  v654 = 0;
  v56 = _qdf_mem_malloc(0x96u, "sap_compute_spect_weight", 1712);
  v65 = v645;
  if ( !v56 )
    goto LABEL_633;
  v66 = a3;
  v67 = (void *)v56;
  v68 = v645;
  v634 = v56;
  if ( a3 )
  {
    qdf_list_peek_front(a3, &v648);
    v69 = v648;
    if ( v648 )
    {
      v70 = 0;
      v641 = v636 + 24LL * v55;
      while ( 1 )
      {
        v71 = v69[3];
        v72 = 0;
        v73 = *(_DWORD *)(v71 + 52);
        v74 = *(_DWORD *)(v71 + 1064);
        if ( v73 <= 18 )
          break;
        if ( v73 > 26 )
        {
          if ( (unsigned int)(v73 - 27) < 2 )
          {
LABEL_65:
            v76 = *(_DWORD *)(v71 + 1068);
            v75 = 0;
            v77 = 0;
            v72 = 2;
            v78 = (unsigned __int8)a4[8];
            if ( a4[8] )
              goto LABEL_76;
            goto LABEL_49;
          }
          if ( v73 != 29 )
          {
            v79 = v73 == 30;
LABEL_69:
            v75 = 0;
            v76 = 0;
            v77 = 0;
            if ( v79 )
            {
              v76 = *(_DWORD *)(v71 + 1068);
              v77 = *(_DWORD *)(v71 + 1072);
              v75 = 0;
              v72 = 4;
              v78 = (unsigned __int8)a4[8];
              if ( a4[8] )
                goto LABEL_76;
              goto LABEL_49;
            }
LABEL_75:
            v78 = (unsigned __int8)a4[8];
            if ( a4[8] )
              goto LABEL_76;
            goto LABEL_49;
          }
        }
        else
        {
          if ( (unsigned int)(v73 - 23) < 4 )
            goto LABEL_57;
          if ( v73 != 19 )
          {
            v79 = v73 == 20;
            goto LABEL_69;
          }
        }
        v76 = *(_DWORD *)(v71 + 1072);
        if ( v76 )
        {
          v75 = 0;
          v77 = 0;
          v72 = 3;
          goto LABEL_75;
        }
        v76 = *(_DWORD *)(v71 + 1068);
        v75 = 0;
        v77 = 0;
        v72 = 3;
        v78 = (unsigned __int8)a4[8];
        if ( a4[8] )
          goto LABEL_76;
LABEL_49:
        qdf_list_peek_next(v66, v648, &v647);
        v69 = v647;
        v647 = nullptr;
        v648 = v69;
        if ( !v69 )
        {
          if ( v70 )
            qdf_trace_msg(0x39u, 8u, "BSS freq[width,freq0,freq1]: %s", v57, v58, v59, v60, v61, v62, v63, v64, v67);
          goto LABEL_504;
        }
      }
      if ( (unsigned int)(v73 - 7) >= 4 && (unsigned int)(v73 - 13) >= 4 )
      {
        v75 = 0;
        v76 = 0;
        v77 = 0;
        if ( (unsigned int)(v73 - 17) < 2 )
          goto LABEL_65;
        goto LABEL_75;
      }
LABEL_57:
      v76 = *(_DWORD *)(v71 + 1068);
      v77 = 0;
      v72 = 1;
      if ( v76 > v74 )
        v75 = 1;
      else
        v75 = 3;
      v78 = (unsigned __int8)a4[8];
      if ( a4[8] )
      {
LABEL_76:
        v80 = *(_QWORD *)a4;
        v81 = 0;
        while ( v74 != *(_DWORD *)v80 )
        {
          ++v81;
          v80 += 24;
          if ( v81 >= v78 )
            goto LABEL_49;
        }
        v82 = *(char *)(v71 + 60);
        v605 = v77;
        v613 = v76;
        v624 = v72;
        if ( *(_DWORD *)(v80 + 8) < v82 )
          *(_DWORD *)(v80 + 8) = v82;
        ++*(_WORD *)(v80 + 4);
        v609 = v70;
        if ( wlan_reg_is_24ghz_ch_freq(v74) )
        {
          if ( v80 )
          {
            v91 = (unsigned __int8)wlan_reg_freq_to_chan(
                                     *(_QWORD *)(a1 + 21560),
                                     *(_DWORD *)v80,
                                     v83,
                                     v84,
                                     v85,
                                     v86,
                                     v87,
                                     v88,
                                     v89,
                                     v90);
            if ( (unsigned int)v91 <= 4 )
            {
              if ( v91 > 2 )
              {
                if ( v91 != 3 )
                  goto LABEL_201;
                goto LABEL_212;
              }
              if ( v91 == 1 )
                goto LABEL_234;
              if ( v91 == 2 )
                goto LABEL_223;
            }
            else if ( v91 >= 11 )
            {
              if ( v91 > 12 )
              {
                if ( v91 == 13 )
                {
                  if ( v80 - 96 < v641
                    && v80 != 96
                    && v80 - 96 >= v636
                    && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 96)) & 1) != 0 )
                  {
                    v179 = *(_DWORD *)(v80 - 88);
                    v180 = *(_DWORD *)(v80 + 8) - 40;
                    v181 = v179 < v180;
                    ++*(_WORD *)(v80 - 92);
                    if ( v179 > v180 )
                      v180 = v179;
                    if ( v181 || v180 <= -101 )
                    {
                      if ( v180 <= -100 )
                        v180 = -100;
                      *(_DWORD *)(v80 - 88) = v180;
                    }
                  }
                  if ( v80 - 72 < v641
                    && v80 != 72
                    && v80 - 72 >= v636
                    && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 72)) & 1) != 0 )
                  {
                    v182 = *(_DWORD *)(v80 - 64);
                    v183 = *(_DWORD *)(v80 + 8) - 30;
                    v184 = v182 < v183;
                    ++*(_WORD *)(v80 - 68);
                    if ( v182 > v183 )
                      v183 = v182;
                    if ( v184 || v183 <= -101 )
                    {
                      if ( v183 <= -100 )
                        v183 = -100;
                      *(_DWORD *)(v80 - 64) = v183;
                    }
                  }
                  if ( v80 - 48 < v641
                    && v80 != 48
                    && v80 - 48 >= v636
                    && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 48)) & 1) != 0 )
                  {
                    v185 = *(_DWORD *)(v80 - 40);
                    v186 = *(_DWORD *)(v80 + 8) - 20;
                    v187 = v185 < v186;
                    ++*(_WORD *)(v80 - 44);
                    if ( v185 > v186 )
                      v186 = v185;
                    if ( v187 || v186 <= -101 )
                    {
                      if ( v186 <= -100 )
                        v186 = -100;
                      *(_DWORD *)(v80 - 40) = v186;
                    }
                  }
                  if ( v80 - 24 < v641
                    && v80 != 24
                    && v80 - 24 >= v636
                    && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 24)) & 1) != 0 )
                  {
                    v188 = *(_DWORD *)(v80 - 16);
                    v189 = *(_DWORD *)(v80 + 8) - 10;
                    v190 = v188 < v189;
                    ++*(_WORD *)(v80 - 20);
                    if ( v188 > v189 )
                      v189 = v188;
                    if ( v190 || v189 <= -101 )
                    {
                      if ( v189 <= -100 )
                        v189 = -100;
                      *(_DWORD *)(v80 - 16) = v189;
                    }
                  }
                  if ( v80 + 24 < v641
                    && v80 != -24
                    && v80 + 24 >= v636
                    && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 24)) & 1) != 0 )
                  {
                    v191 = *(_DWORD *)(v80 + 32);
                    v192 = *(_DWORD *)(v80 + 8) - 10;
                    v193 = v191 < v192;
                    ++*(_WORD *)(v80 + 28);
                    if ( v191 > v192 )
                      v192 = v191;
                    if ( v193 || v192 <= -101 )
                    {
                      if ( v192 <= -100 )
                        v192 = -100;
                      *(_DWORD *)(v80 + 32) = v192;
                    }
                  }
                }
                else if ( v91 == 14 )
                {
                  if ( v80 - 96 < v641
                    && v80 != 96
                    && v80 - 96 >= v636
                    && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 96)) & 1) != 0 )
                  {
                    v142 = *(_DWORD *)(v80 - 88);
                    v143 = *(_DWORD *)(v80 + 8) - 40;
                    v144 = v142 < v143;
                    ++*(_WORD *)(v80 - 92);
                    if ( v142 > v143 )
                      v143 = v142;
                    if ( v144 || v143 <= -101 )
                    {
                      if ( v143 <= -100 )
                        v143 = -100;
                      *(_DWORD *)(v80 - 88) = v143;
                    }
                  }
                  if ( v80 - 72 < v641
                    && v80 != 72
                    && v80 - 72 >= v636
                    && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 72)) & 1) != 0 )
                  {
                    v145 = *(_DWORD *)(v80 - 64);
                    v146 = *(_DWORD *)(v80 + 8) - 30;
                    v147 = v145 < v146;
                    ++*(_WORD *)(v80 - 68);
                    if ( v145 > v146 )
                      v146 = v145;
                    if ( v147 || v146 <= -101 )
                    {
                      if ( v146 <= -100 )
                        v146 = -100;
                      *(_DWORD *)(v80 - 64) = v146;
                    }
                  }
                  if ( v80 - 48 < v641
                    && v80 != 48
                    && v80 - 48 >= v636
                    && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 48)) & 1) != 0 )
                  {
                    v148 = *(_DWORD *)(v80 - 40);
                    v149 = *(_DWORD *)(v80 + 8) - 20;
                    v150 = v148 < v149;
                    ++*(_WORD *)(v80 - 44);
                    if ( v148 > v149 )
                      v149 = v148;
                    if ( v150 || v149 <= -101 )
                    {
                      if ( v149 <= -100 )
                        v149 = -100;
                      *(_DWORD *)(v80 - 40) = v149;
                    }
                  }
                  if ( v80 - 24 < v641
                    && v80 != 24
                    && v80 - 24 >= v636
                    && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 24)) & 1) != 0 )
                  {
                    v151 = *(_DWORD *)(v80 - 16);
                    v152 = *(_DWORD *)(v80 + 8) - 10;
                    v153 = v151 < v152;
                    ++*(_WORD *)(v80 - 20);
                    if ( v151 > v152 )
                      v152 = v151;
                    if ( v153 || v152 <= -101 )
                    {
                      if ( v152 <= -100 )
                        v152 = -100;
                      *(_DWORD *)(v80 - 16) = v152;
                    }
                  }
                }
              }
              else if ( v91 == 11 )
              {
                if ( v80 - 96 < v641
                  && v80 != 96
                  && v80 - 96 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 96)) & 1) != 0 )
                {
                  v158 = *(_DWORD *)(v80 - 88);
                  v159 = *(_DWORD *)(v80 + 8) - 40;
                  v160 = v158 < v159;
                  ++*(_WORD *)(v80 - 92);
                  if ( v158 > v159 )
                    v159 = v158;
                  if ( v160 || v159 <= -101 )
                  {
                    if ( v159 <= -100 )
                      v159 = -100;
                    *(_DWORD *)(v80 - 88) = v159;
                  }
                }
                if ( v80 - 72 < v641
                  && v80 != 72
                  && v80 - 72 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 72)) & 1) != 0 )
                {
                  v161 = *(_DWORD *)(v80 - 64);
                  v162 = *(_DWORD *)(v80 + 8) - 30;
                  v163 = v161 < v162;
                  ++*(_WORD *)(v80 - 68);
                  if ( v161 > v162 )
                    v162 = v161;
                  if ( v163 || v162 <= -101 )
                  {
                    if ( v162 <= -100 )
                      v162 = -100;
                    *(_DWORD *)(v80 - 64) = v162;
                  }
                }
                if ( v80 - 48 < v641
                  && v80 != 48
                  && v80 - 48 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 48)) & 1) != 0 )
                {
                  v164 = *(_DWORD *)(v80 - 40);
                  v165 = *(_DWORD *)(v80 + 8) - 20;
                  v166 = v164 < v165;
                  ++*(_WORD *)(v80 - 44);
                  if ( v164 > v165 )
                    v165 = v164;
                  if ( v166 || v165 <= -101 )
                  {
                    if ( v165 <= -100 )
                      v165 = -100;
                    *(_DWORD *)(v80 - 40) = v165;
                  }
                }
                if ( v80 - 24 < v641
                  && v80 != 24
                  && v80 - 24 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 24)) & 1) != 0 )
                {
                  v167 = *(_DWORD *)(v80 - 16);
                  v168 = *(_DWORD *)(v80 + 8) - 10;
                  v169 = v167 < v168;
                  ++*(_WORD *)(v80 - 20);
                  if ( v167 > v168 )
                    v168 = v167;
                  if ( v169 || v168 <= -101 )
                  {
                    if ( v168 <= -100 )
                      v168 = -100;
                    *(_DWORD *)(v80 - 16) = v168;
                  }
                }
                if ( v80 + 24 < v641
                  && v80 != -24
                  && v80 + 24 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 24)) & 1) != 0 )
                {
                  v170 = *(_DWORD *)(v80 + 32);
                  v171 = *(_DWORD *)(v80 + 8) - 10;
                  v172 = v170 < v171;
                  ++*(_WORD *)(v80 + 28);
                  if ( v170 > v171 )
                    v171 = v170;
                  if ( v172 || v171 <= -101 )
                  {
                    if ( v171 <= -100 )
                      v171 = -100;
                    *(_DWORD *)(v80 + 32) = v171;
                  }
                }
                if ( v80 + 48 < v641
                  && v80 != -48
                  && v80 + 48 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 48)) & 1) != 0 )
                {
                  v173 = *(_DWORD *)(v80 + 56);
                  v174 = *(_DWORD *)(v80 + 8) - 20;
                  v175 = v173 < v174;
                  ++*(_WORD *)(v80 + 52);
                  if ( v173 > v174 )
                    v174 = v173;
                  if ( v175 || v174 <= -101 )
                  {
                    if ( v174 <= -100 )
                      v174 = -100;
                    *(_DWORD *)(v80 + 56) = v174;
                  }
                }
                if ( v80 + 72 < v641
                  && v80 != -72
                  && v80 + 72 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 72)) & 1) != 0 )
                {
                  v176 = *(_DWORD *)(v80 + 80);
                  v177 = *(_DWORD *)(v80 + 8) - 30;
                  v178 = v176 < v177;
                  ++*(_WORD *)(v80 + 76);
                  if ( v176 > v177 )
                    v177 = v176;
                  if ( v178 || v177 <= -101 )
                  {
                    if ( v177 <= -100 )
                      v177 = -100;
                    *(_DWORD *)(v80 + 80) = v177;
                  }
                }
              }
              else
              {
                if ( v80 - 96 < v641
                  && v80 != 96
                  && v80 - 96 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 96)) & 1) != 0 )
                {
                  v103 = *(_DWORD *)(v80 - 88);
                  v104 = *(_DWORD *)(v80 + 8) - 40;
                  v105 = v103 < v104;
                  ++*(_WORD *)(v80 - 92);
                  if ( v103 > v104 )
                    v104 = v103;
                  if ( v105 || v104 <= -101 )
                  {
                    if ( v104 <= -100 )
                      v104 = -100;
                    *(_DWORD *)(v80 - 88) = v104;
                  }
                }
                if ( v80 - 72 < v641
                  && v80 != 72
                  && v80 - 72 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 72)) & 1) != 0 )
                {
                  v106 = *(_DWORD *)(v80 - 64);
                  v107 = *(_DWORD *)(v80 + 8) - 30;
                  v108 = v106 < v107;
                  ++*(_WORD *)(v80 - 68);
                  if ( v106 > v107 )
                    v107 = v106;
                  if ( v108 || v107 <= -101 )
                  {
                    if ( v107 <= -100 )
                      v107 = -100;
                    *(_DWORD *)(v80 - 64) = v107;
                  }
                }
                if ( v80 - 48 < v641
                  && v80 != 48
                  && v80 - 48 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 48)) & 1) != 0 )
                {
                  v109 = *(_DWORD *)(v80 - 40);
                  v110 = *(_DWORD *)(v80 + 8) - 20;
                  v111 = v109 < v110;
                  ++*(_WORD *)(v80 - 44);
                  if ( v109 > v110 )
                    v110 = v109;
                  if ( v111 || v110 <= -101 )
                  {
                    if ( v110 <= -100 )
                      v110 = -100;
                    *(_DWORD *)(v80 - 40) = v110;
                  }
                }
                if ( v80 - 24 < v641
                  && v80 != 24
                  && v80 - 24 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 24)) & 1) != 0 )
                {
                  v112 = *(_DWORD *)(v80 - 16);
                  v113 = *(_DWORD *)(v80 + 8) - 10;
                  v114 = v112 < v113;
                  ++*(_WORD *)(v80 - 20);
                  if ( v112 > v113 )
                    v113 = v112;
                  if ( v114 || v113 <= -101 )
                  {
                    if ( v113 <= -100 )
                      v113 = -100;
                    *(_DWORD *)(v80 - 16) = v113;
                  }
                }
                if ( v80 + 24 < v641
                  && v80 != -24
                  && v80 + 24 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 24)) & 1) != 0 )
                {
                  v115 = *(_DWORD *)(v80 + 32);
                  v116 = *(_DWORD *)(v80 + 8) - 10;
                  v117 = v115 < v116;
                  ++*(_WORD *)(v80 + 28);
                  if ( v115 > v116 )
                    v116 = v115;
                  if ( v117 || v116 <= -101 )
                  {
                    if ( v116 <= -100 )
                      v116 = -100;
                    *(_DWORD *)(v80 + 32) = v116;
                  }
                }
                if ( v80 + 48 < v641
                  && v80 != -48
                  && v80 + 48 >= v636
                  && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 48)) & 1) != 0 )
                {
                  v118 = *(_DWORD *)(v80 + 56);
                  v119 = *(_DWORD *)(v80 + 8) - 20;
                  v120 = v118 < v119;
                  ++*(_WORD *)(v80 + 52);
                  if ( v118 > v119 )
                    v119 = v118;
                  if ( v120 || v119 <= -101 )
                  {
                    if ( v119 <= -100 )
                      v119 = -100;
                    *(_DWORD *)(v80 + 56) = v119;
                  }
                }
              }
            }
            else
            {
              if ( v80 - 96 < v641
                && v80 != 96
                && v80 - 96 >= v636
                && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 96)) & 1) != 0 )
              {
                v92 = *(_DWORD *)(v80 - 88);
                v93 = *(_DWORD *)(v80 + 8) - 40;
                v94 = v92 < v93;
                ++*(_WORD *)(v80 - 92);
                if ( v92 > v93 )
                  v93 = v92;
                if ( v94 || v93 <= -101 )
                {
                  if ( v93 <= -100 )
                    v93 = -100;
                  *(_DWORD *)(v80 - 88) = v93;
                }
              }
LABEL_201:
              if ( v80 - 72 < v641
                && v80 != 72
                && v80 - 72 >= v636
                && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 72)) & 1) != 0 )
              {
                v121 = *(_DWORD *)(v80 - 64);
                v122 = *(_DWORD *)(v80 + 8) - 30;
                v123 = v121 < v122;
                ++*(_WORD *)(v80 - 68);
                if ( v121 > v122 )
                  v122 = v121;
                if ( v123 || v122 <= -101 )
                {
                  if ( v122 <= -100 )
                    v122 = -100;
                  *(_DWORD *)(v80 - 64) = v122;
                }
              }
LABEL_212:
              if ( v80 - 48 < v641
                && v80 != 48
                && v80 - 48 >= v636
                && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 48)) & 1) != 0 )
              {
                v124 = *(_DWORD *)(v80 - 40);
                v125 = *(_DWORD *)(v80 + 8) - 20;
                v126 = v124 < v125;
                ++*(_WORD *)(v80 - 44);
                if ( v124 > v125 )
                  v125 = v124;
                if ( v126 || v125 <= -101 )
                {
                  if ( v125 <= -100 )
                    v125 = -100;
                  *(_DWORD *)(v80 - 40) = v125;
                }
              }
LABEL_223:
              if ( v80 - 24 < v641
                && v80 != 24
                && v80 - 24 >= v636
                && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 24)) & 1) != 0 )
              {
                v127 = *(_DWORD *)(v80 - 16);
                v128 = *(_DWORD *)(v80 + 8) - 10;
                v129 = v127 < v128;
                ++*(_WORD *)(v80 - 20);
                if ( v127 > v128 )
                  v128 = v127;
                if ( v129 || v128 <= -101 )
                {
                  if ( v128 <= -100 )
                    v128 = -100;
                  *(_DWORD *)(v80 - 16) = v128;
                }
              }
LABEL_234:
              if ( v80 + 24 < v641
                && v80 != -24
                && v80 + 24 >= v636
                && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 24)) & 1) != 0 )
              {
                v130 = *(_DWORD *)(v80 + 32);
                v131 = *(_DWORD *)(v80 + 8) - 10;
                v132 = v130 < v131;
                ++*(_WORD *)(v80 + 28);
                if ( v130 > v131 )
                  v131 = v130;
                if ( v132 || v131 <= -101 )
                {
                  if ( v131 <= -100 )
                    v131 = -100;
                  *(_DWORD *)(v80 + 32) = v131;
                }
              }
              if ( v80 + 48 < v641
                && v80 != -48
                && v80 + 48 >= v636
                && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 48)) & 1) != 0 )
              {
                v133 = *(_DWORD *)(v80 + 56);
                v134 = *(_DWORD *)(v80 + 8) - 20;
                v135 = v133 < v134;
                ++*(_WORD *)(v80 + 52);
                if ( v133 > v134 )
                  v134 = v133;
                if ( v135 || v134 <= -101 )
                {
                  if ( v134 <= -100 )
                    v134 = -100;
                  *(_DWORD *)(v80 + 56) = v134;
                }
              }
              if ( v80 + 72 < v641
                && v80 != -72
                && v80 + 72 >= v636
                && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 72)) & 1) != 0 )
              {
                v136 = *(_DWORD *)(v80 + 80);
                v137 = *(_DWORD *)(v80 + 8) - 30;
                v138 = v136 < v137;
                ++*(_WORD *)(v80 + 76);
                if ( v136 > v137 )
                  v137 = v136;
                if ( v138 || v137 <= -101 )
                {
                  if ( v137 <= -100 )
                    v137 = -100;
                  *(_DWORD *)(v80 + 80) = v137;
                }
              }
              if ( v80 + 96 < v641
                && v80 != -96
                && v80 + 96 >= v636
                && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 96)) & 1) != 0 )
              {
                v139 = *(_DWORD *)(v80 + 104);
                v140 = *(_DWORD *)(v80 + 8) - 40;
                v141 = v139 < v140;
                ++*(_WORD *)(v80 + 100);
                if ( v139 > v140 )
                  v140 = v139;
                if ( v141 || v140 <= -101 )
                {
                  if ( v140 <= -100 )
                    v140 = -100;
                  *(_DWORD *)(v80 + 104) = v140;
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
              v83,
              v84,
              v85,
              v86,
              v87,
              v88,
              v89,
              v90,
              "sap_interference_rssi_count");
          }
LABEL_476:
          v67 = (void *)v634;
          v194 = scnprintf(v634 + v609, 150 - v609, "%d[%d,%d,%d,%d] ", v74, v624, v613, v605, *(char *)(v69[3] + 60LL));
          v70 = v202 + v609;
          v68 = v645;
          v66 = a3;
          if ( v202 + v609 >= 0x7B )
          {
            qdf_trace_msg(
              0x39u,
              8u,
              "BSS freq[width,freq0,freq1,rssi]: %s",
              v194,
              v195,
              v196,
              v197,
              v198,
              v199,
              v200,
              v201,
              v634);
            v70 = 0;
          }
          goto LABEL_49;
        }
        if ( v624 <= 2 )
        {
          if ( v624 == 1 )
          {
            if ( v75 == 3 )
            {
              if ( v80 - 24 >= v641
                || v80 == 24
                || v80 - 24 < v636
                || (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 - 24)) & 1) == 0 )
              {
                goto LABEL_476;
              }
              v155 = *(_DWORD *)(v80 - 16);
              v99 = (int *)(v80 - 16);
              v98 = v155;
              v101 = v99[6];
            }
            else
            {
              if ( v75 != 1
                || v80 + 24 >= v641
                || v80 == -24
                || v80 + 24 < v636
                || (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *(_DWORD *)(v80 + 24)) & 1) == 0 )
              {
                goto LABEL_476;
              }
              v100 = *(_DWORD *)(v80 + 32);
              v99 = (int *)(v80 + 32);
              v98 = v100;
              v101 = *(v99 - 6);
            }
            v156 = v101 - 20;
            v157 = v98 < v156;
            if ( v98 <= v156 )
              v98 = v156;
            ++*((_WORD *)v99 - 2);
            if ( v157 || v98 < -100 )
            {
              if ( v98 <= -100 )
                v98 = -100;
              *v99 = v98;
            }
            goto LABEL_476;
          }
          if ( v624 != 2 )
            goto LABEL_476;
LABEL_102:
          v95 = v613 - v74;
          if ( (int)(v613 - v74) <= 9 )
          {
            if ( v95 == -30 )
            {
              v96 = -3;
              v97 = 3;
            }
            else
            {
              if ( v95 != -10 )
                goto LABEL_476;
              v96 = -2;
              v97 = 3;
            }
            goto LABEL_482;
          }
          if ( v95 == 30 )
          {
            v154 = 0;
            v97 = 3;
            v96 = 1;
          }
          else
          {
            if ( v95 != 10 )
              goto LABEL_476;
            v96 = -1;
            v97 = 3;
LABEL_482:
            v154 = 1;
          }
LABEL_483:
          v203 = v80 + 24LL * (int)v96;
          v204 = 0;
          v205 = 24 * (v154 + v97);
          v206 = (int *)((char *)&unk_A16DA8 + 4 * (unsigned int)(v96 + 15));
          do
          {
            if ( v96 )
            {
              v208 = (unsigned int *)(v203 + v204);
              if ( v203 + v204 < v641
                && v208
                && (unsigned __int64)v208 >= v636
                && (wlan_reg_is_same_band_freqs(*(_DWORD *)v80, *v208) & 1) != 0 )
              {
                v209 = v203 + v204;
                ++*(_WORD *)(v203 + v204 + 4);
                if ( (unsigned int)(v96 + 15) > 0x1E )
                  v210 = 0;
                else
                  v210 = *v206;
                v211 = *(_DWORD *)(v209 + 8);
                v207 = *(_DWORD *)(v80 + 8) + v210;
                v212 = v211 < v207;
                if ( v211 > v207 )
                  v207 = *(_DWORD *)(v209 + 8);
                if ( v212 || v207 <= -101 )
                {
                  if ( v207 <= -100 )
                    v207 = -100;
                  *(_DWORD *)(v209 + 8) = v207;
                }
              }
            }
            v204 += 24;
            ++v206;
            ++v96;
          }
          while ( v205 != v204 );
          goto LABEL_476;
        }
        if ( v624 != 3 )
          goto LABEL_102;
        v102 = v613 - v74;
        if ( (int)(v613 - v74) > 9 )
        {
          if ( v102 > 49 )
          {
            if ( v102 == 70 )
            {
              v154 = 0;
              v97 = 7;
              v96 = 1;
              goto LABEL_483;
            }
            if ( v102 != 50 )
              goto LABEL_476;
            v96 = -1;
          }
          else if ( v102 == 10 )
          {
            v96 = -3;
          }
          else
          {
            if ( v102 != 30 )
              goto LABEL_476;
            v96 = -2;
          }
        }
        else if ( v102 > -31 )
        {
          if ( v102 == -30 )
          {
            v96 = -5;
          }
          else
          {
            if ( v102 != -10 )
              goto LABEL_476;
            v96 = -4;
          }
        }
        else if ( v102 == -70 )
        {
          v96 = -7;
        }
        else
        {
          if ( v102 != -50 )
            goto LABEL_476;
          v96 = -6;
        }
        v97 = 7;
        goto LABEL_482;
      }
      goto LABEL_49;
    }
  }
LABEL_504:
  v213 = *(unsigned int *)(v68 + 1524);
  v214 = *(unsigned int **)a4;
  v215 = ((unsigned int)v213 >> 8) & 0xF;
  v216 = (unsigned __int16)v213 >> 12;
  v217 = WORD1(v213) & 0xF;
  v218 = ((unsigned int)v213 >> 20) & 0xF;
  v65 = v68;
  v219 = (((unsigned __int8)*(_DWORD *)(v68 + 1524) >> 4)
        + (*(_DWORD *)(v68 + 1524) & 0xF)
        + v215
        + v216
        + v217
        + v218
        + (HIBYTE(*(_DWORD *)(v68 + 1524)) & 0xF)) >> 1;
  v220 = (unsigned __int16)(((unsigned __int8)*(_DWORD *)(v68 + 1524) >> 4)
                          + (*(_DWORD *)(v68 + 1524) & 0xF)
                          + v215
                          + v216
                          + v217
                          + v218
                          + (HIBYTE(*(_DWORD *)(v68 + 1524)) & 0xF));
  qdf_trace_msg(
    0x39u,
    8u,
    "Channel weight 0x%x, nf local %d, chan free local %d, txpwr range %d tput %d linear_rssi_thresh %d",
    v57,
    v58,
    v59,
    v60,
    v61,
    v62,
    v63,
    v64,
    v213,
    ((unsigned __int16)(v219 + 3840 * v215) / v220 + 8) >> 4,
    ((unsigned __int16)(v219 + 3840 * v216) / v220 + 8) >> 4,
    ((unsigned __int16)(v219 + 3840 * v217) / v220 + 8) >> 4,
    ((unsigned __int16)(v219 + 3840 * v218) / v220 + 8) >> 4,
    *(__int16 *)(*(_QWORD *)(v68 + 1536) + 602LL));
  qdf_trace_msg(
    0x39u,
    8u,
    "ACS freq weight info: freq[weight{normalized_weight,rssi_bss_weight,chan_status_weight(nf,cc,txpwr range,txpwt tput)"
    ", power_weight}][rssi][bss]:",
    v221,
    v222,
    v223,
    v224,
    v225,
    v226,
    v227,
    v228);
  qdf_mem_set(v67, 0x96u, 0);
  if ( !a4[8] )
  {
    _qdf_mem_free((__int64)v67);
    goto LABEL_633;
  }
  v229 = 0;
  v230 = 0;
  v231 = 0;
  v232 = 0;
  v233 = 0;
  v637 = 0;
  v642 = 0;
  while ( 1 )
  {
    while ( 1 )
    {
      v234 = *v214;
      v235 = *(_QWORD *)(v645 + 1536);
      v236 = v214[2];
      v237 = *(unsigned int *)(v235 + 556);
      if ( (_DWORD)v237 )
      {
        v238 = 0;
        v239 = v235 + 44;
        v240 = 1;
        do
        {
          if ( v238 == 102 )
            goto LABEL_905;
          if ( *(_DWORD *)(v239 + 4 * v238) == v234 )
            break;
          v240 = ++v238 < v237;
        }
        while ( v237 != v238 );
        if ( v240 )
          LOBYTE(v236) = v236 - 10;
      }
      v241 = (char)v236;
      v242 = v214[3];
      if ( v241 <= -100 )
        v243 = -100;
      else
        v243 = v241;
      if ( v242 - 26663 >= 2 )
      {
        v244 = *(unsigned __int8 *)(v645 + 1496);
        if ( !*(_BYTE *)(v645 + 1496) )
        {
LABEL_521:
          qdf_mem_set(&v653, 0x10u, 0);
          v233 = 0;
          v232 = 0;
          if ( (wlansap_is_channel_present_in_acs_list(
                  *v214,
                  *(_QWORD *)(*(_QWORD *)(v645 + 1536) + 32LL),
                  *(unsigned __int8 *)(*(_QWORD *)(v645 + 1536) + 40LL))
              & 1) != 0 )
            v255 = 26663;
          else
            v255 = 26664;
          v642 = 0;
          v214[2] = -100;
          v214[3] = v255;
          *((_WORD *)v214 + 2) = 0;
LABEL_586:
          v311 = *(_QWORD *)(a1 + 8);
          v312 = *v214;
          v313 = 0;
          v314 = *(unsigned __int16 *)(v311 + 5368);
          v315 = v311 + 4096;
          if ( *(_WORD *)(v311 + 5368) )
          {
            v316 = (unsigned __int8 *)(v311 + 5256);
            v317 = 100;
            do
            {
              if ( v312 >= *((_DWORD *)v316 - 2) && v312 <= *((_DWORD *)v316 - 1) )
              {
                v317 = *v316;
                v313 = 1;
              }
              --v314;
              v316 += 12;
            }
            while ( v314 );
          }
          else
          {
            v317 = 100;
          }
          v318 = *(unsigned __int16 *)(v311 + 5244);
          if ( v318 )
          {
            v319 = (unsigned __int8 *)(v315 + 336);
            do
            {
              if ( v312 == *((_DWORD *)v319 - 1) )
              {
                v317 = *v319;
                v313 = 1;
              }
              --v318;
              v319 += 8;
            }
            while ( v318 );
          }
          if ( (wlan_reg_is_dfs_for_freq(*(_QWORD *)(a1 + 21560), v312, v247, v248, v249, v250, v251, v252, v253, v254)
              & 1) != 0 )
          {
            v320 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5372LL);
            v321 = v320;
            if ( (unsigned __int8)v320 >= v317 )
              v321 = v317;
            if ( (v313 & 1) != 0 )
              LOBYTE(v320) = v321;
            v317 = (unsigned __int8)v320;
          }
          else if ( (v313 & 1) == 0 )
          {
            v242 = v214[3];
            v230 = 0;
            goto LABEL_607;
          }
          v322 = v214[3];
          v230 = (26664 - v322) * (100 - v317) / 0x64;
          v242 = v230 + v322;
          v214[3] = v242;
LABEL_607:
          if ( v242 >= 0x6829 )
          {
            v242 = 26664;
            v214[3] = 26664;
          }
          v234 = *v214;
          goto LABEL_610;
        }
        v245 = *(int **)(v645 + 1488);
        while ( 1 )
        {
          v246 = *v245++;
          if ( v234 == v246 )
            break;
          if ( !--v244 )
            goto LABEL_521;
        }
        qdf_mem_set(&v653, 0x10u, 0);
        v256 = *(_DWORD *)(v645 + 1524);
        v257 = *(_BYTE **)(v645 + 1536);
        v258 = *((unsigned __int16 *)v214 + 2);
        v259 = (unsigned __int8)v256 >> 4;
        v260 = (v256 >> 8) & 0xF;
        v261 = (unsigned __int16)v256 >> 12;
        v262 = HIWORD(v256) & 0xF;
        v263 = (v256 >> 20) & 0xF;
        v264 = v256 & 0xF;
        v265 = HIBYTE(v256) & 0xF;
        v266 = v259 + v264 + v260 + v261 + v262 + v263 + v265;
        v267 = v266 >> 1;
        v268 = 3840 * v259;
        v269 = v258;
        if ( (v257[600] & 1) == 0 )
          v269 = (((v267 + v268 * v258) / v266 + 30) / 0x3C + 8) >> 4;
        if ( v257[601] == 1 )
        {
          v270 = 2 * v258;
          if ( (char)v257[602] < v243 )
            v269 = v270;
        }
        v271 = 3840 * v264;
        v272 = v267 + v271;
        v273 = (unsigned __int8)(((unsigned __int16)(v267 + v268) / (unsigned int)(unsigned __int16)v266 + 8) >> 4);
        v274 = (((v267 + v271 * (v243 + 100)) / v266 + 50) / 0x64 + 8) >> 4;
        v275 = (unsigned __int8)((v272 / (unsigned int)(unsigned __int16)v266 + 8) >> 4);
        if ( v274 >= v275 )
          v276 = v275;
        else
          v276 = v274;
        if ( v269 >= v273 )
          v277 = v273;
        else
          v277 = v269;
        v643 = v277;
        if ( *(_BYTE *)(a1 + 14912) == 1 )
        {
          channel_status = (_DWORD *)ucfg_mc_cp_stats_get_channel_status(*(_QWORD *)(a1 + 21560), *v214);
          v279 = *(_DWORD *)(v645 + 1524);
          v260 = (v279 >> 8) & 0xF;
          v280 = (unsigned __int8)v279 >> 4;
          v261 = (unsigned __int16)v279 >> 12;
          v262 = HIWORD(v279) & 0xF;
          v263 = (v279 >> 20) & 0xF;
          v265 = HIBYTE(v279) & 0xF;
          v266 = v280 + (*(_DWORD *)(v645 + 1524) & 0xF) + v260 + v261 + v262 + v263 + v265;
          v267 = v266 >> 1;
        }
        else
        {
          channel_status = nullptr;
        }
        v281 = 3840 * v260;
        v282 = (unsigned __int8)(((unsigned __int16)(v281 + v267) / (unsigned int)(unsigned __int16)v266 + 8) >> 4);
        if ( channel_status && *channel_status )
        {
          v283 = channel_status[1];
          v284 = 0;
          if ( v283 != -128 && v283 )
            v284 = (((v267 + (v283 + 120) * v281) / v266 + 30) / 0x3C + 8) >> 4;
          if ( v284 < v282 )
            v282 = v284;
        }
        LODWORD(v653) = v282;
        v285 = 3840 * v261;
        v286 = (unsigned __int8)(((unsigned __int16)(v285 + v267) / (unsigned int)(unsigned __int16)v266 + 8) >> 4);
        if ( channel_status && *channel_status )
        {
          v287 = channel_status[2];
          if ( (*(_BYTE *)(*(_QWORD *)(v645 + 1536) + 605LL) & 1) == 0 )
            v287 -= channel_status[9] + channel_status[7];
          v288 = channel_status[3];
          if ( v288 )
            v289 = ((((v267 + ((v288 >> 1) + (v287 << 8)) / v288 * v285) / v266 + 128) >> 8) + 8) >> 4;
          else
            v289 = 0;
          if ( v289 < v286 )
            v286 = v289;
        }
        HIDWORD(v653) = v286;
        v290 = 3840 * v262;
        v291 = (unsigned __int8)(((unsigned __int16)(v290 + v267) / (unsigned int)(unsigned __int16)v266 + 8) >> 4);
        if ( channel_status && *channel_status )
        {
          v292 = channel_status[4];
          v293 = v292 ? (((v267 + (63 - v292) * v290) / v266 + 31) / 0x3F + 8) >> 4 : 0;
          if ( v293 < v291 )
            v291 = v293;
        }
        LODWORD(v654) = v291;
        v294 = 3840 * v263;
        v295 = (unsigned __int8)(((unsigned __int16)(v294 + v267) / (unsigned int)(unsigned __int16)v266 + 8) >> 4);
        if ( channel_status && *channel_status )
        {
          v296 = channel_status[5];
          v297 = v296 ? (((v267 + (63 - v296) * v294) / v266 + 31) / 0x3F + 8) >> 4 : 0;
          if ( v297 < v295 )
            v295 = v297;
        }
        HIDWORD(v654) = v295;
        if ( !v265 )
        {
          v301 = 0;
LABEL_585:
          v309 = v643;
          v310 = v286 + v282;
          v642 = v301;
          v233 = v309 + v276;
          v232 = v310 + v291 + v295;
          v214[3] = 111 * (v232 + v233 + v301);
          goto LABEL_586;
        }
        v625 = v276;
        v630 = v282;
        v652 = 0;
        v298 = 3840 * v265;
        v651 = 0;
        v650 = 0;
        v649 = 0;
        v299 = (unsigned __int8)(((unsigned __int16)(3840 * v265 + v267) / (unsigned int)(unsigned __int16)v266 + 8) >> 4);
        if ( !*(_QWORD *)(v645 + 16) )
        {
          v300 = "%s: sap ctx vdev is null.";
          goto LABEL_575;
        }
        if ( (unsigned int)wlan_reg_get_chan_pwr_attr_from_secondary_list_for_freq() )
        {
          v300 = "%s: fail to get power attribute.";
LABEL_575:
          qdf_trace_msg(
            0x39u,
            2u,
            v300,
            v247,
            v248,
            v249,
            v250,
            v251,
            v252,
            v253,
            v254,
            "sap_weight_channel_reg_max_power");
          v301 = v299;
          v276 = v625;
          v282 = v630;
          goto LABEL_585;
        }
        v302 = v652;
        if ( v652 <= 0x24u )
        {
          if ( v652 > 0xDu )
          {
LABEL_581:
            v282 = v630;
            v305 = *(_DWORD *)(v645 + 1524);
            v306 = (HIWORD(v305) & 0xF) + ((v305 >> 20) & 0xF);
            v307 = ((unsigned __int8)v305 >> 4) + (v305 & 0xF) + ((v305 >> 8) & 0xF) + ((unsigned __int16)v305 >> 12);
            v308 = ((((36 - v302) * v298 + ((unsigned int)(v307 + v306 + (HIBYTE(v305) & 0xF)) >> 1))
                   / (v307 + v306 + (HIBYTE(v305) & 0xF))
                   + 11)
                  / 0x16
                  + 8) >> 4;
            if ( v308 >= v299 )
              v301 = v299;
            else
              v301 = v308;
            v276 = v625;
            goto LABEL_585;
          }
          v303 = 14;
          v304 = "%s: eirp_pwr %d below min";
        }
        else
        {
          v303 = 36;
          v304 = "%s: eirp_pwr %d exceed max";
        }
        v614 = v303;
        qdf_trace_msg(
          0x39u,
          8u,
          v304,
          v247,
          v248,
          v249,
          v250,
          v251,
          v252,
          v253,
          v254,
          "sap_weight_channel_reg_max_power");
        v302 = v614;
        goto LABEL_581;
      }
LABEL_610:
      v214[4] = v242;
      if ( wlan_reg_is_6ghz_chan_freq(v234) )
      {
        v331 = v214[3];
        v332 = v231 <= v331 ? v214[3] : v231;
        if ( v331 < 0x6827 )
          v231 = v332;
      }
      if ( *((_BYTE *)v214 + 20) != 1 )
        break;
      v333 = v214[3];
      if ( v333 > 0x6826 )
        break;
      v323 = scnprintf(
               v634 + v637,
               150 - v637,
               "%d[%d{%d,%d,%d(%d,%d,%d,%d),%d}][%d][%d] ",
               *v214,
               v333,
               v230,
               v233,
               v232,
               v653,
               HIDWORD(v653),
               v654,
               HIDWORD(v654),
               v642,
               v214[2],
               *((unsigned __int16 *)v214 + 2));
      v637 += v334;
      if ( v637 <= 0x4A )
        break;
      qdf_trace_msg(0x39u, 8u, "%s", v323, v324, v325, v326, v327, v328, v329, v330, v634);
      if ( ++v229 >= (unsigned int)(unsigned __int8)a4[8] )
        goto LABEL_625;
      v637 = 0;
      v214 += 6;
    }
    if ( ++v229 >= (unsigned int)(unsigned __int8)a4[8] )
      break;
    v214 += 6;
  }
  if ( v637 )
    qdf_trace_msg(0x39u, 8u, "%s", v323, v324, v325, v326, v327, v328, v329, v330, v634);
LABEL_625:
  _qdf_mem_free(v634);
  v65 = v645;
  if ( v231 )
  {
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: max_valid_weight_on_6ghz_channels %d",
      v57,
      v58,
      v59,
      v60,
      v61,
      v62,
      v63,
      v64,
      "sap_update_6ghz_max_weight",
      v231);
    if ( a4[8] )
    {
      v335 = 0;
      v336 = 0;
      do
      {
        v337 = *(_QWORD *)a4;
        if ( wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(*(_QWORD *)a4 + v335)) )
        {
          v338 = v337 + v335;
          if ( *(_DWORD *)(v337 + v335 + 12) == 26663 )
          {
            *(_DWORD *)(v338 + 12) = v231;
            *(_DWORD *)(v338 + 16) = v231;
          }
        }
        ++v336;
        v335 += 24;
      }
      while ( v336 < (unsigned __int8)a4[8] );
    }
  }
LABEL_633:
  wlan_reg_read_current_country(*(_QWORD *)(a1 + 21552), &v655, v57, v58, v59, v60, v61, v62, v63, v64);
  wlan_reg_get_domain_from_country_code(&v646, (__int64)&v655, v339, v340, v341, v342, v343, v344, v345, v346);
  v347 = *(_DWORD *)(*(_QWORD *)(v65 + 1536) + 8LL);
  if ( v347 <= (unsigned int)wlan_reg_ch_to_freq(0xDu)
    && (v348 = *(_DWORD *)(*(_QWORD *)(v65 + 1536) + 12LL), v348 <= (unsigned int)wlan_reg_ch_to_freq(0xDu)) )
  {
    v350 = 8;
  }
  else
  {
    v349 = *(_DWORD *)(*(_QWORD *)(v65 + 1536) + 8LL);
    if ( v349 < (unsigned int)wlan_reg_ch_to_freq(0xDu) )
      v350 = 1;
    else
      v350 = 2;
  }
  v351 = 0;
  if ( (a7 & 1) != 0 )
  {
    v350 = 8;
    v352 = 0;
  }
  else
  {
    v352 = v601;
  }
  v635 = v350;
  if ( v646 )
    v353 = 9;
  else
    v353 = 7;
  next_lower_bandwidth = v352;
  v644 = v353;
  v612 = v352;
  while ( 2 )
  {
    if ( next_lower_bandwidth <= 2 )
    {
      if ( next_lower_bandwidth != 1 )
      {
        v355 = next_lower_bandwidth;
        if ( next_lower_bandwidth != 2 )
          goto LABEL_881;
LABEL_652:
        v653 = 0;
        v654 = 0;
        v356 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), *(_BYTE *)(v65 + 12));
        if ( v356 == 17 )
        {
          v351 = 14;
LABEL_821:
          v65 = v645;
          goto LABEL_858;
        }
        v631 = v356;
        v368 = *(_QWORD *)a4;
        v369 = _qdf_mem_malloc(0x96u, "sap_sort_chl_weight_80_mhz", 2064);
        if ( !v369 )
        {
          v351 = 2;
          goto LABEL_821;
        }
        v639 = v369;
        if ( !a4[8] )
        {
          _qdf_mem_free(v369);
          v65 = v645;
          goto LABEL_857;
        }
        v370 = 0;
        v626 = 0;
        v619 = 0;
LABEL_667:
        while ( 2 )
        {
          v371 = (unsigned int *)(v368 + 24 * v370);
          v372 = (char *)v371 + 21;
          if ( (*((_BYTE *)v371 + 21) & 1) == 0 )
          {
            v373 = *(_QWORD *)(a1 + 21560);
            LODWORD(v653) = 2;
            wlan_reg_set_channel_params_for_pwrmode(
              v373,
              *v371,
              0,
              (__int64)&v653,
              0,
              v357,
              v358,
              v359,
              v360,
              v361,
              v362,
              v363,
              v364);
            if ( (_DWORD)v653 != 2 || (v374 = *v371, (unsigned __int8)(v654 - *v371) != 30) )
            {
              v371[3] = 106656;
              goto LABEL_692;
            }
            v375 = v370 + 3;
            if ( v370 + 3 <= (unsigned __int8)a4[8] )
            {
              if ( v374 + 20 == v371[6] )
              {
                v376 = v371[12];
                v377 = v374 + 40;
                if ( v374 + 40 == v376 )
                {
                  v378 = (unsigned int *)(v368 + 24 * v375);
                  if ( v374 + 60 == *v378 )
                  {
                    v379 = v371[3];
                    v380 = v371[9];
                    v371[3] = 106656;
                    v606 = v371[15];
                    v610 = v380;
                    *((_BYTE *)v371 + 21) = 1;
                    v602 = v378[3];
                    v599 = *((unsigned __int8 *)v371 + 20);
                    is_sap_freq_allowed = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21552), v631, v374);
                    is_channel_present_in_acs_list = wlansap_is_channel_present_in_acs_list(
                                                       *v371,
                                                       *(_QWORD *)(*(_QWORD *)(v645 + 1536) + 16LL),
                                                       *(unsigned __int8 *)(*(_QWORD *)(v645 + 1536) + 24LL));
                    v382 = v371[9];
                    v383 = v371[6];
                    v615 = v379;
                    v371[9] = 106656;
                    v384 = v379 > v382;
                    *((_BYTE *)v371 + 45) = 1;
                    if ( v379 >= v382 )
                      v379 = v382;
                    v591 = *((unsigned __int8 *)v371 + 44);
                    v593 = is_channel_present_in_acs_list;
                    v385 = v384;
                    v582 = v385;
                    v589 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21552), v631, v383);
                    v386 = wlansap_is_channel_present_in_acs_list(
                             v371[6],
                             *(_QWORD *)(*(_QWORD *)(v645 + 1536) + 16LL),
                             *(unsigned __int8 *)(*(_QWORD *)(v645 + 1536) + 24LL));
                    v387 = v371[15];
                    v388 = v371[12];
                    v371[15] = 106656;
                    v389 = v379 > v387;
                    *((_BYTE *)v371 + 69) = 1;
                    if ( v379 >= v387 )
                      v379 = v387;
                    v585 = *((unsigned __int8 *)v371 + 68);
                    v587 = v386;
                    if ( v389 )
                      v390 = 2;
                    else
                      v390 = v582;
                    v578 = v390;
                    v583 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21552), v631, v388);
                    v391 = wlansap_is_channel_present_in_acs_list(
                             v371[12],
                             *(_QWORD *)(*(_QWORD *)(v645 + 1536) + 16LL),
                             *(unsigned __int8 *)(*(_QWORD *)(v645 + 1536) + 24LL));
                    v392 = v378[3];
                    v580 = v391;
                    v393 = *v378;
                    v378[3] = 106656;
                    *((_BYTE *)v378 + 21) = 1;
                    v577 = *((unsigned __int8 *)v378 + 20);
                    if ( v379 <= v392 )
                      v394 = v578;
                    else
                      v394 = 3;
                    v579 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21552), v631, v393);
                    v395 = wlansap_is_channel_present_in_acs_list(
                             *v378,
                             *(_QWORD *)(*(_QWORD *)(v645 + 1536) + 16LL),
                             *(unsigned __int8 *)(*(_QWORD *)(v645 + 1536) + 24LL));
                    if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5371LL) == 1 )
                    {
                      v576 = v395;
                      if ( wlan_reg_is_6ghz_chan_freq(*v371)
                        && (wlan_reg_is_6ghz_psc_chan_freq(*v371, v396, v397, v398, v399, v400, v401, v402, v403) & 1) != 0 )
                      {
                        v394 = 0;
                      }
                      else if ( wlan_reg_is_6ghz_chan_freq(v371[6])
                             && (wlan_reg_is_6ghz_psc_chan_freq(v371[6], v405, v406, v407, v408, v409, v410, v411, v412)
                               & 1) != 0 )
                      {
                        v394 = 1;
                      }
                      else if ( wlan_reg_is_6ghz_chan_freq(v371[12])
                             && (wlan_reg_is_6ghz_psc_chan_freq(
                                   v371[12],
                                   v413,
                                   v414,
                                   v415,
                                   v416,
                                   v417,
                                   v418,
                                   v419,
                                   v420)
                               & 1) != 0 )
                      {
                        v394 = 2;
                      }
                      else if ( wlan_reg_is_6ghz_chan_freq(v371[18])
                             && (wlan_reg_is_6ghz_psc_chan_freq(
                                   v371[18],
                                   v357,
                                   v358,
                                   v359,
                                   v360,
                                   v361,
                                   v362,
                                   v363,
                                   v364)
                               & 1) != 0 )
                      {
                        v394 = 3;
                      }
                      v395 = v576;
                    }
                    v421 = v370 + v394;
                    v422 = v610 + v615 + v606 + v602;
                    *(_DWORD *)(v368 + 24 * v421 + 12) = v422;
                    if ( ((v577 | v585 | v591 | v599)
                        & v579
                        & v583
                        & v589
                        & is_sap_freq_allowed
                        & (v395 | v580 | v587 | v593)
                        & 1) != 0 )
                    {
                      v357 = scnprintf(
                               v639 + v626,
                               150 - v626,
                               "%d[%d,%d,%d] ",
                               *(_DWORD *)(v368 + 24 * v421),
                               v422,
                               v654,
                               ++v619);
                      v424 = v423 + v626;
                      if ( v423 + v626 > 0x7C )
                        goto LABEL_716;
                    }
                    else
                    {
                      v424 = v626;
                      if ( v626 > 0x7C )
                      {
LABEL_716:
                        qdf_trace_msg(
                          0x39u,
                          8u,
                          "ACS 80 Mhz freq score: %s",
                          v357,
                          v358,
                          v359,
                          v360,
                          v361,
                          v362,
                          v363,
                          v364,
                          v639);
                        ++v370;
                        v626 = 0;
                        if ( v370 >= (unsigned __int8)a4[8] )
                          goto LABEL_854;
                        continue;
                      }
                    }
                    v626 = v424;
                    break;
                  }
                }
                *((_BYTE *)v371 + 21) = 1;
                v371[3] = 106656;
                v371[9] = 106656;
                *((_BYTE *)v371 + 45) = 1;
              }
              else
              {
                v377 = v374 + 40;
                *((_BYTE *)v371 + 21) = 1;
                v371[3] = 106656;
                v376 = v371[12];
              }
              if ( v377 == v376 )
              {
                *((_BYTE *)v371 + 69) = 1;
                v371[15] = 106656;
              }
              v404 = (_DWORD *)(v368 + 24 * v375);
              if ( v374 + 60 == *v404 )
              {
                v372 = (char *)v404 + 21;
                v404[3] = 106656;
LABEL_692:
                *v372 = 1;
              }
            }
          }
          break;
        }
        if ( ++v370 >= (unsigned __int8)a4[8] )
        {
          if ( v626 )
          {
            qdf_trace_msg(0x39u, 8u, "ACS 80 Mhz freq score: %s", v357, v358, v359, v360, v361, v362, v363, v364, v639);
            v501 = v639;
            goto LABEL_855;
          }
LABEL_854:
          v501 = v639;
LABEL_855:
          _qdf_mem_free(v501);
          v65 = v645;
          if ( v619 )
          {
            sap_sort_chl_weight(a1, a4, v645);
            v351 = 0;
            goto LABEL_858;
          }
LABEL_857:
          qdf_trace_msg(
            0x39u,
            8u,
            "%s: no valid chan bonding with CH_WIDTH_80MHZ",
            v536,
            v537,
            v538,
            v539,
            v540,
            v541,
            v542,
            v543,
            "sap_sort_chl_weight_80_mhz");
          v351 = 4;
LABEL_858:
          v544 = v355;
LABEL_876:
          if ( !v351 )
            goto LABEL_882;
          next_lower_bandwidth = wlan_reg_get_next_lower_bandwidth();
          if ( a4[8] )
          {
            v547 = 0;
            v548 = (_BYTE *)(*(_QWORD *)a4 + 21LL);
            do
            {
              ++v547;
              *(_DWORD *)(v548 - 9) = *(_DWORD *)(v548 - 5);
              *v548 = 0;
              v548 += 24;
            }
            while ( v547 < (unsigned __int8)a4[8] );
          }
          continue;
        }
        goto LABEL_667;
      }
      v365 = *(unsigned int **)a4;
      v638 = 1;
      if ( v635 == 8 )
      {
        if ( a4[8] )
        {
          v366 = 0;
          do
          {
            if ( wlan_reg_is_5ghz_ch_freq(*v365) || wlan_reg_is_6ghz_chan_freq(*v365) )
              v365[3] = 53328;
            ++v366;
            v365 += 6;
          }
          while ( v366 < (unsigned __int8)a4[8] );
        }
        sap_update_vlp_deprority_chan(a1, a4);
        v434 = *(unsigned int **)a4;
        v435 = 0;
        while ( 1 )
        {
          if ( !a4[8] )
            goto LABEL_725;
          v436 = 0;
          v437 = v434;
          do
          {
            v438 = *v437;
            v437 += 6;
            v439 = wlan_reg_freq_to_chan(*(_QWORD *)(a1 + 21560), v438, v426, v427, v428, v429, v430, v431, v432, v433);
            v440 = (unsigned __int8)a4[8];
            if ( acs_ht40_channels24_g[4 * v435] == v439 )
              break;
            ++v436;
          }
          while ( v436 < v440 );
          if ( (_DWORD)v440 == (unsigned __int8)v436 )
            goto LABEL_725;
          v441 = &v434[6 * v436];
          if ( (wlansap_is_channel_present_in_acs_list(
                  *v441,
                  *(_QWORD *)(*(_QWORD *)(v645 + 1536) + 16LL),
                  *(unsigned __int8 *)(*(_QWORD *)(v645 + 1536) + 24LL))
              & 1) != 0 )
          {
            if ( *v441 + 20 != v441[24] )
              goto LABEL_740;
            if ( *v441 + 40 == v441[48] )
            {
              v442 = v441[3];
              v443 = v441[27];
              v444 = v441[51];
              v445 = v443 + v442;
              v446 = v444 + v443;
              if ( v443 + v442 <= v444 + v443 )
              {
                if ( v442 <= v443 )
                {
                  v441[3] = v445;
                  v441[27] = 53328;
                }
                else
                {
                  v441[27] = v445;
                  v441[3] = 53327;
                }
                v441[51] = 53328;
              }
              else if ( v443 <= v444 )
              {
                v441[27] = v446;
                v441[3] = 53328;
                v441[51] = 53327;
              }
              else
              {
                v441[51] = v446;
                v441[3] = 53328;
                v441[27] = 53328;
              }
              goto LABEL_725;
            }
            v447 = v441[4];
            v448 = v441[28];
            v94 = v447 > v448;
            v449 = v448 + v447;
            if ( v94 )
            {
              v441[27] = v449;
LABEL_740:
              v441[3] = 53328;
              goto LABEL_725;
            }
            v441[3] = v449;
            v441[27] = 53328;
          }
          else
          {
            v441[3] = 53328;
            *((_BYTE *)v441 + 21) = 1;
          }
LABEL_725:
          if ( ++v435 == 5 )
          {
            do
            {
              v450 = wlan_reg_legacy_chan_to_freq(
                       *(_QWORD *)(a1 + 21560),
                       v435,
                       v426,
                       v427,
                       v428,
                       v429,
                       v430,
                       v431,
                       v432,
                       v433);
              v451 = a4[8];
              if ( v451 )
              {
                v452 = 0;
                v453 = v434;
                do
                {
                  if ( *v453 == v450 && v450 + 20 != v453[24] && v450 - 20 != *(v453 - 24) )
                  {
                    v453[3] = 53328;
                    v451 = a4[8];
                  }
                  ++v452;
                  v453 += 6;
                }
                while ( v452 < v451 );
              }
              v79 = (_DWORD)v435 == v644;
              LODWORD(v435) = v435 + 1;
            }
            while ( !v79 );
            v487 = v644;
            do
            {
              v489 = wlan_reg_legacy_chan_to_freq(
                       *(_QWORD *)(a1 + 21560),
                       v487 + 1,
                       v426,
                       v427,
                       v428,
                       v429,
                       v430,
                       v431,
                       v432,
                       v433);
              v490 = a4[8];
              if ( v490 )
              {
                v491 = 0;
                v492 = v434;
                do
                {
                  if ( *v492 == v489 && v489 - 20 != *(v492 - 24) )
                  {
                    v492[3] = 53328;
                    v490 = a4[8];
                  }
                  ++v491;
                  v492 += 6;
                }
                while ( v491 < v490 );
              }
              v488 = (unsigned __int8)v487++;
            }
            while ( v488 <= 0xB );
            v493 = *(unsigned int **)a4;
            v494 = _qdf_mem_malloc(0x96u, "sap_sort_chl_weight_ht40_24_g", 2923);
            if ( !v494 )
            {
              v65 = v645;
              goto LABEL_862;
            }
            v495 = (unsigned __int8)a4[8];
            v496 = v494;
            if ( !a4[8] )
              goto LABEL_861;
            v497 = 0;
            v498 = 0;
            for ( i = v493 + 3; ; i += 6 )
            {
              while ( 2 )
              {
                if ( *((_BYTE *)i + 8) == 1 )
                {
                  v357 = scnprintf(
                           v496 + v497,
                           150 - v497,
                           "%d[%d,%d,%d] ",
                           *(i - 3),
                           *i,
                           *(i - 1),
                           *((unsigned __int16 *)i - 4));
                  v497 += v500;
                  if ( v497 > 0x7C )
                  {
                    qdf_trace_msg(
                      0x39u,
                      8u,
                      "ACS 40 Mhz freq score: %s",
                      v357,
                      v358,
                      v359,
                      v360,
                      v361,
                      v362,
                      v363,
                      v364,
                      v496);
                    v495 = (unsigned __int8)a4[8];
                    if ( ++v498 >= v495 )
                      goto LABEL_861;
                    v497 = 0;
                    i += 6;
                    continue;
                  }
                  v495 = (unsigned __int8)a4[8];
                }
                break;
              }
              if ( ++v498 >= v495 )
              {
                if ( v497 )
                  qdf_trace_msg(
                    0x39u,
                    8u,
                    "ACS 40 Mhz freq score: %s",
                    v357,
                    v358,
                    v359,
                    v360,
                    v361,
                    v362,
                    v363,
                    v364,
                    v496);
LABEL_861:
                _qdf_mem_free(v496);
                v65 = v645;
                sap_sort_chl_weight(a1, a4, v645);
LABEL_862:
                v544 = 1;
                goto LABEL_876;
              }
            }
          }
        }
      }
      if ( a4[8] )
      {
        v425 = 0;
        do
        {
          if ( wlan_reg_is_24ghz_ch_freq(*v365) )
            v365[3] = 53328;
          ++v425;
          v365 += 6;
        }
        while ( v425 < (unsigned __int8)a4[8] );
      }
      v653 = 0;
      v654 = 0;
      v486 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), *(_BYTE *)(v65 + 12));
      if ( v486 == 17 )
      {
        v351 = 14;
        goto LABEL_875;
      }
      v633 = v486;
      v502 = *(unsigned int **)a4;
      v503 = _qdf_mem_malloc(0x96u, "sap_sort_chl_weight_40_mhz", 2980);
      if ( v503 )
      {
        v504 = v503;
        if ( !a4[8] )
        {
          _qdf_mem_free(v503);
          goto LABEL_873;
        }
        v505 = v65;
        v506 = 0;
        v628 = 0;
        v621 = 0;
        while ( 1 )
        {
          v507 = &v502[6 * v506];
          if ( wlan_reg_is_24ghz_ch_freq(*v507) || (*((_BYTE *)v507 + 21) & 1) != 0 )
            goto LABEL_836;
          LODWORD(v653) = 1;
          wlan_reg_set_channel_params_for_pwrmode(
            *(_QWORD *)(a1 + 21560),
            *v507,
            0,
            (__int64)&v653,
            0,
            v508,
            v509,
            v510,
            v511,
            v512,
            v513,
            v514,
            v515);
          if ( (_DWORD)v653 != 1 )
            break;
          v516 = *v507;
          if ( (unsigned __int8)(v654 - *v507) != 10 )
            break;
          if ( v506 < (unsigned __int8)a4[8] )
          {
            if ( v516 + 20 != v507[6] )
              break;
            v617 = v504;
            v517 = v507[3];
            v507[3] = 53328;
            v518 = v507[9];
            *((_BYTE *)v507 + 21) = 1;
            v519 = v505;
            v520 = v517;
            v608 = *((unsigned __int8 *)v507 + 20);
            v611 = v518;
            v604 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21552), v633, v516);
            v521 = wlansap_is_channel_present_in_acs_list(
                     *v507,
                     *(_QWORD *)(*(_QWORD *)(v519 + 1536) + 16LL),
                     *(unsigned __int8 *)(*(_QWORD *)(v519 + 1536) + 24LL));
            v522 = v507[9];
            v507[9] = 53328;
            *((_BYTE *)v507 + 45) = 1;
            v523 = v520 > v522;
            v598 = *((unsigned __int8 *)v507 + 44);
            v600 = v521;
            v595 = policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21552), v633, v507[6]);
            v524 = wlansap_is_channel_present_in_acs_list(
                     v507[6],
                     *(_QWORD *)(*(_QWORD *)(v519 + 1536) + 16LL),
                     *(unsigned __int8 *)(*(_QWORD *)(v519 + 1536) + 24LL));
            if ( *(_BYTE *)(*(_QWORD *)(a1 + 8) + 5371LL) == 1 )
            {
              if ( wlan_reg_is_6ghz_chan_freq(*v507)
                && (wlan_reg_is_6ghz_psc_chan_freq(*v507, v525, v526, v527, v528, v529, v530, v531, v532) & 1) != 0 )
              {
                v523 = 0;
              }
              else if ( wlan_reg_is_6ghz_chan_freq(v507[6])
                     && (wlan_reg_is_6ghz_psc_chan_freq(v507[6], v508, v509, v510, v511, v512, v513, v514, v515) & 1) != 0 )
              {
                v523 = 1;
              }
            }
            v533 = v506 + v523;
            v502[6 * v533 + 3] = v611 + v520;
            if ( ((v598 | v608) & v595 & v604 & (v524 | v600) & 1) != 0 )
            {
              v504 = v617;
              v508 = scnprintf(v617 + v628, 150 - v628, "%d[%d,%d,%d] ", v502[6 * v533], v611 + v520, v654, ++v621);
              v535 = v534 + v628;
              v505 = v645;
            }
            else
            {
              v505 = v645;
              v504 = v617;
              v535 = v628;
            }
            if ( v535 > 0x7C )
            {
              qdf_trace_msg(
                0x39u,
                8u,
                "ACS 40 Mhz freq score: %s",
                v508,
                v509,
                v510,
                v511,
                v512,
                v513,
                v514,
                v515,
                v504);
              ++v506;
              v628 = 0;
              if ( v506 >= (unsigned __int8)a4[8] )
                goto LABEL_866;
              continue;
            }
            v628 = v535;
          }
LABEL_836:
          if ( ++v506 >= (unsigned __int8)a4[8] )
          {
            if ( v628 )
              qdf_trace_msg(
                0x39u,
                8u,
                "ACS 40 Mhz freq score: %s",
                v508,
                v509,
                v510,
                v511,
                v512,
                v513,
                v514,
                v515,
                v504);
LABEL_866:
            _qdf_mem_free(v504);
            v65 = v505;
            if ( !v621 )
            {
LABEL_873:
              v545 = "%s: no valid chan bonding with CH_WIDTH_40MHZ";
              v546 = "sap_sort_chl_weight_40_mhz";
LABEL_874:
              qdf_trace_msg(0x39u, 8u, v545, v478, v479, v480, v481, v482, v483, v484, v485, v546);
              v351 = 4;
LABEL_875:
              v544 = v638;
              goto LABEL_876;
            }
LABEL_870:
            sap_sort_chl_weight(a1, a4, v65);
            v351 = 0;
            goto LABEL_875;
          }
        }
        v507[3] = 53328;
        *((_BYTE *)v507 + 21) = 1;
        goto LABEL_836;
      }
LABEL_849:
      v351 = 2;
      goto LABEL_875;
    }
    break;
  }
  if ( next_lower_bandwidth == 3 )
  {
    v653 = 0;
    v654 = 0;
    v638 = 3;
    v367 = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), *(_BYTE *)(v65 + 12));
    if ( v367 == 17 )
    {
      v351 = 14;
      goto LABEL_875;
    }
    v632 = v367;
    v454 = *(unsigned int **)a4;
    v455 = _qdf_mem_malloc(0x96u, "sap_sort_chl_weight_160_mhz", 2240);
    if ( !v455 )
      goto LABEL_849;
    if ( !a4[8] )
    {
      _qdf_mem_free(v455);
      goto LABEL_871;
    }
    v456 = 0;
    v616 = v455;
    v627 = 0;
    v620 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v457 = &v454[6 * v456];
        v458 = (char *)v457 + 21;
        if ( (*((_BYTE *)v457 + 21) & 1) == 0 )
        {
          v459 = *(_QWORD *)(a1 + 21560);
          LODWORD(v653) = 3;
          wlan_reg_set_channel_params_for_pwrmode(
            v459,
            *v457,
            0,
            (__int64)&v653,
            0,
            v357,
            v358,
            v359,
            v360,
            v361,
            v362,
            v363,
            v364);
          if ( (_DWORD)v653 != 3 || (v460 = *v457, (unsigned __int8)(BYTE4(v654) - *v457) != 70) )
          {
            v457[3] = 213312;
LABEL_777:
            *v458 = 1;
            goto LABEL_778;
          }
          v461 = v456 + 7;
          if ( v456 + 7 <= (unsigned __int8)a4[8] )
            break;
        }
LABEL_778:
        if ( ++v456 >= (unsigned __int8)a4[8] )
        {
          v65 = v645;
          if ( v627 )
            qdf_trace_msg(0x39u, 8u, "ACS 160 Mhz freq score: %s", v357, v358, v359, v360, v361, v362, v363, v364, v616);
          _qdf_mem_free(v616);
          goto LABEL_869;
        }
      }
      if ( v460 + 20 != v457[6] )
        break;
      v462 = v457[12];
      if ( v460 + 40 != v462
        || v460 + 60 != v457[18]
        || v460 + 80 != v457[24]
        || v460 + 100 != v457[30]
        || v460 + 120 != v457[36]
        || (v463 = &v454[6 * v461], v460 + 140 != *v463) )
      {
        v457[3] = 213312;
        *((_BYTE *)v457 + 21) = 1;
        v457[9] = 213312;
        *((_BYTE *)v457 + 45) = 1;
        if ( v460 + 40 != v462 )
          goto LABEL_782;
LABEL_781:
        v457[15] = 213312;
        *((_BYTE *)v457 + 69) = 1;
LABEL_782:
        if ( v460 + 60 == v457[18] )
        {
          v457[21] = 213312;
          *((_BYTE *)v457 + 93) = 1;
        }
        if ( v460 + 80 == v457[24] )
        {
          v457[27] = 213312;
          *((_BYTE *)v457 + 117) = 1;
        }
        if ( v460 + 100 == v457[30] )
        {
          v457[33] = 213312;
          *((_BYTE *)v457 + 141) = 1;
        }
        if ( v460 + 120 == v457[36] )
        {
          v457[39] = 213312;
          *((_BYTE *)v457 + 165) = 1;
        }
        v477 = &v454[6 * v461];
        if ( v460 + 140 != *v477 )
          goto LABEL_778;
        v477[3] = 213312;
        v458 = (char *)v477 + 21;
        goto LABEL_777;
      }
      v464 = (__int64)&v454[6 * v456 + 3];
      v465 = v457[3];
      v466 = 0;
      v467 = 0;
      v607 = 0;
      v590 = v457[15];
      v592 = v457[9];
      v581 = v457[33];
      v584 = v457[21];
      v586 = v457[39];
      v588 = v457[27];
      v594 = v463[3];
      v597 = v465;
      v603 = 1;
      do
      {
        v468 = *(_DWORD *)v464;
        v469 = *(_DWORD *)(v464 - 12);
        *(_DWORD *)v464 = 213312;
        v470 = v465 > v468;
        *(_BYTE *)(v464 + 9) = 1;
        if ( v465 >= v468 )
          v465 = v468;
        if ( v470 )
          v467 = v466;
        LODWORD(v607) = *(unsigned __int8 *)(v464 + 8) | (unsigned int)v607;
        v603 &= policy_mgr_is_sap_freq_allowed(*(_QWORD *)(a1 + 21552), v632, v469);
        v471 = wlansap_is_channel_present_in_acs_list(
                 *(unsigned int *)(v464 - 12),
                 *(_QWORD *)(*(_QWORD *)(v645 + 1536) + 16LL),
                 *(unsigned __int8 *)(*(_QWORD *)(v645 + 1536) + 24LL));
        ++v466;
        v464 += 24;
        HIDWORD(v607) |= v471;
      }
      while ( v466 != 8 );
      LOBYTE(v648) = v467;
      v472 = v592 + v597 + v590 + v584 + v588 + v581 + v586 + v594;
      sap_override_6ghz_psc_minidx(a1, v457, 8, &v648);
      v473 = v456 + (unsigned __int8)v648;
      v454[6 * v473 + 3] = v472;
      v474 = v627;
      if ( ((unsigned int)v607 & v603 & HIDWORD(v607) & 1) != 0 )
      {
        v357 = scnprintf(v616 + v627, 150 - v627, "%d[%d,%d,%d] ", v454[6 * v473], v472, HIDWORD(v654), ++v620);
        v474 = v475 + v627;
      }
      if ( v474 <= 0x7C )
      {
        v627 = v474;
        goto LABEL_778;
      }
      qdf_trace_msg(0x39u, 8u, "ACS 160 Mhz freq score: %s", v357, v358, v359, v360, v361, v362, v363, v364, v616);
      ++v456;
      v627 = 0;
      if ( v456 >= (unsigned __int8)a4[8] )
      {
        _qdf_mem_free(v616);
        v65 = v645;
LABEL_869:
        if ( v620 )
          goto LABEL_870;
LABEL_871:
        v545 = "%s: no valid chan bonding with CH_WIDTH_160MHZ";
        v546 = "sap_sort_chl_weight_160_mhz";
        goto LABEL_874;
      }
    }
    v476 = v457[12];
    v457[3] = 213312;
    *((_BYTE *)v457 + 21) = 1;
    if ( v460 + 40 == v476 )
      goto LABEL_781;
    goto LABEL_782;
  }
  v355 = next_lower_bandwidth;
  if ( next_lower_bandwidth == 4 )
    goto LABEL_652;
LABEL_881:
  sap_sort_chl_weight(a1, a4, v65);
  v544 = v355;
LABEL_882:
  v549 = v612;
  if ( v544 != v612 )
  {
    v549 = v544;
    qdf_trace_msg(
      0x39u,
      4u,
      "%s: channel width change from %d to %d",
      v357,
      v358,
      v359,
      v360,
      v361,
      v362,
      v363,
      v364,
      "sap_sort_chl_weight_all",
      v612,
      v544);
  }
  if ( v549 - 1 > 6 )
    v550 = 26663;
  else
    v550 = dword_A16E24[v549 - 1];
  v551 = *(unsigned int **)a4;
  v552 = _qdf_mem_malloc(0x96u, "sap_dump_sorted_list", 3263);
  if ( !v552 )
    goto LABEL_901;
  v561 = v552;
  qdf_trace_msg(
    0x39u,
    8u,
    "ACS sorted freq list for width %d: freq[weight]:",
    v553,
    v554,
    v555,
    v556,
    v557,
    v558,
    v559,
    v560,
    v549);
  v570 = (unsigned __int8)a4[8];
  if ( !a4[8] )
    goto LABEL_900;
  v571 = 0;
  v572 = 0;
  v573 = v551 + 5;
  while ( 2 )
  {
    while ( *v573 == 1 )
    {
      v574 = *((_DWORD *)v573 - 2);
      if ( v574 >= v550 )
        break;
      v562 = scnprintf(v561 + v571, 150 - v571, "%d[%d] ", *((_DWORD *)v573 - 5), v574);
      v571 += v575;
      if ( v571 <= 0x87 )
      {
        v570 = (unsigned __int8)a4[8];
        break;
      }
      qdf_trace_msg(0x39u, 8u, "%s", v562, v563, v564, v565, v566, v567, v568, v569, v561);
      v570 = (unsigned __int8)a4[8];
      if ( ++v572 >= v570 )
        goto LABEL_900;
      v571 = 0;
      v573 += 24;
    }
    if ( ++v572 < v570 )
    {
      v573 += 24;
      continue;
    }
    break;
  }
  if ( v571 )
    qdf_trace_msg(0x39u, 8u, "%s", v562, v563, v564, v565, v566, v567, v568, v569, v561);
LABEL_900:
  _qdf_mem_free(v561);
  v65 = v645;
LABEL_901:
  *(_WORD *)(*(_QWORD *)(v65 + 1536) + 42LL) = v549;
  if ( a5 )
    *a5 = v646;
  if ( a6 )
  {
    result = 0;
    *a6 = v635;
    goto LABEL_42;
  }
LABEL_41:
  result = 0;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}
