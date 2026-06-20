__int64 __fastcall rrm_process_radio_measurement_request(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        _BYTE *a5,
        int a6,
        int *a7)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  char v21; // w19
  __int16 v22; // w20
  __int16 v23; // w22
  char v24; // w23
  __int16 v25; // w24
  __int64 v26; // x1
  __int64 v27; // x2
  __int64 v28; // x3
  __int64 v29; // x4
  __int64 v30; // x0
  unsigned int v31; // w8
  __int64 v32; // x27
  __int64 v33; // x28
  unsigned int v34; // w24
  __int64 v35; // x23
  char *v36; // x20
  _BYTE *v37; // x8
  char v38; // w9
  char v39; // w19
  __int64 v40; // x0
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  __int64 v49; // x0
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  __int64 v58; // x23
  __int64 result; // x0
  char v60; // w19
  __int16 v61; // w20
  __int16 v62; // w22
  char v63; // w24
  __int16 v64; // w25
  __int64 v65; // x1
  __int64 v66; // x2
  __int64 v67; // x3
  __int64 v68; // x4
  __int64 v69; // x0
  unsigned int v70; // w19
  unsigned int v71; // w23
  char v72; // w19
  __int16 v73; // w20
  __int16 v74; // w22
  char v75; // w24
  __int16 v76; // w25
  __int64 v77; // x1
  __int64 v78; // x2
  __int64 v79; // x3
  __int64 v80; // x4
  __int64 v81; // x0
  double v82; // d0
  double v83; // d1
  double v84; // d2
  double v85; // d3
  double v86; // d4
  double v87; // d5
  double v88; // d6
  double v89; // d7
  double v90; // d0
  double v91; // d1
  double v92; // d2
  double v93; // d3
  double v94; // d4
  double v95; // d5
  double v96; // d6
  double v97; // d7
  unsigned int v98; // w8
  int *v99; // x10
  unsigned int v100; // w25
  int v101; // w9
  __int64 v102; // x20
  __int64 v103; // x14
  __int64 v104; // x15
  __int64 v105; // x16
  __int64 v106; // x17
  __int64 v107; // x27
  const char *v108; // x1
  _BYTE *v109; // x2
  __int64 v110; // x19
  int v111; // w11
  unsigned __int8 *v112; // x19
  int v113; // t1
  int v114; // w9
  int v115; // w8
  unsigned int v116; // w8
  _BYTE *v117; // x0
  __int64 v118; // x19
  _BYTE *v119; // x22
  char v120; // w8
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
  unsigned int v137; // w8
  char v138; // w9
  bool v139; // cf
  char v140; // w8
  __int64 v141; // x8
  unsigned __int16 v142; // w8
  __int64 v145; // x20
  __int64 v146; // x22
  __int64 v147; // x25
  __int64 v148; // x27
  double v149; // d0
  double v150; // d1
  double v151; // d2
  double v152; // d3
  double v153; // d4
  double v154; // d5
  double v155; // d6
  double v156; // d7
  char *v157; // x0
  double v158; // d0
  double v159; // d1
  double v160; // d2
  double v161; // d3
  double v162; // d4
  double v163; // d5
  double v164; // d6
  double v165; // d7
  _BYTE *v166; // x22
  char v167; // w8
  __int64 v168; // x5
  __int64 v169; // x0
  double v170; // d0
  double v171; // d1
  double v172; // d2
  double v173; // d3
  double v174; // d4
  double v175; // d5
  double v176; // d6
  double v177; // d7
  const char *v178; // x2
  __int64 v179; // x3
  int v180; // w8
  __int64 v181; // x22
  __int64 v182; // x19
  const char *v183; // x25
  __int64 v184; // x0
  double v185; // d0
  double v186; // d1
  double v187; // d2
  double v188; // d3
  double v189; // d4
  double v190; // d5
  double v191; // d6
  double v192; // d7
  unsigned int v193; // w11
  __int64 v194; // x8
  _BYTE *v195; // x11
  __int64 v196; // x0
  double v197; // d0
  double v198; // d1
  double v199; // d2
  double v200; // d3
  double v201; // d4
  double v202; // d5
  double v203; // d6
  double v204; // d7
  _BYTE *v205; // x22
  __int64 v206; // x26
  char v207; // w8
  __int64 v208; // x5
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
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
  unsigned int v241; // w22
  int v242; // w19
  __int64 v243; // x25
  int v244; // w26
  __int64 v245; // x19
  unsigned __int8 *v246; // x20
  _BYTE *v247; // x0
  double v248; // d0
  double v249; // d1
  double v250; // d2
  double v251; // d3
  double v252; // d4
  double v253; // d5
  double v254; // d6
  double v255; // d7
  unsigned __int8 v256; // w6
  _BYTE *v257; // x26
  double v258; // d0
  double v259; // d1
  double v260; // d2
  double v261; // d3
  double v262; // d4
  double v263; // d5
  double v264; // d6
  double v265; // d7
  unsigned int v266; // w26
  unsigned int v267; // w19
  unsigned int v268; // w25
  unsigned int v269; // w22
  double v270; // d0
  double v271; // d1
  double v272; // d2
  double v273; // d3
  double v274; // d4
  double v275; // d5
  double v276; // d6
  double v277; // d7
  char v278; // w19
  unsigned int v279; // w8
  char v280; // w9
  bool v281; // cf
  char v282; // w8
  __int64 v283; // x8
  unsigned __int16 v284; // w8
  const char *v285; // x3
  unsigned int v286; // w22
  __int16 v287; // w14
  unsigned int v288; // w20
  __int64 v289; // x19
  unsigned __int16 v290; // w22
  char v291; // w19
  __int16 v292; // w20
  char v293; // w8
  __int16 v294; // w22
  __int64 v295; // x1
  __int64 v296; // x2
  __int64 v297; // x3
  __int64 v298; // x4
  __int64 v299; // x0
  unsigned __int16 v300; // w19
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
  char v317; // w8
  char v318; // w11
  unsigned int v319; // w8
  char v320; // w9
  bool v321; // cf
  char v322; // w8
  __int64 v323; // x8
  unsigned __int16 v324; // w26
  unsigned int v325; // w8
  int v326; // w9
  int v327; // w12
  int v328; // w13
  __int64 v329; // x6
  unsigned __int8 v330; // w25
  unsigned __int8 v331; // w22
  double v332; // d0
  double v333; // d1
  double v334; // d2
  double v335; // d3
  double v336; // d4
  double v337; // d5
  double v338; // d6
  double v339; // d7
  double v340; // d0
  double v341; // d1
  double v342; // d2
  double v343; // d3
  double v344; // d4
  double v345; // d5
  double v346; // d6
  double v347; // d7
  const char *v348; // x2
  double v349; // d0
  double v350; // d1
  double v351; // d2
  double v352; // d3
  double v353; // d4
  double v354; // d5
  double v355; // d6
  double v356; // d7
  unsigned __int8 *v357; // x27
  void *v358; // x0
  size_t v359; // x2
  unsigned __int64 v360; // x19
  const char *v361; // x2
  double v362; // d0
  double v363; // d1
  double v364; // d2
  double v365; // d3
  double v366; // d4
  double v367; // d5
  double v368; // d6
  double v369; // d7
  unsigned int v370; // w0
  double v371; // d0
  double v372; // d1
  double v373; // d2
  double v374; // d3
  double v375; // d4
  double v376; // d5
  double v377; // d6
  double v378; // d7
  unsigned int v379; // w19
  double v380; // d0
  double v381; // d1
  double v382; // d2
  double v383; // d3
  double v384; // d4
  double v385; // d5
  double v386; // d6
  double v387; // d7
  __int64 v388; // x0
  unsigned __int64 v389; // x20
  __int16 v390; // w9
  char v391; // w8
  __int16 v392; // w2
  __int64 *v393; // x1
  const char *v394; // x2
  unsigned int v395; // w20
  char v397; // w9
  char v398; // w8
  double v399; // d0
  double v400; // d1
  double v401; // d2
  double v402; // d3
  double v403; // d4
  double v404; // d5
  double v405; // d6
  double v406; // d7
  unsigned int v407; // w26
  __int64 v408; // x3
  double v409; // d0
  double v410; // d1
  double v411; // d2
  double v412; // d3
  double v413; // d4
  double v414; // d5
  double v415; // d6
  double v416; // d7
  size_t v417; // x2
  double v418; // d0
  double v419; // d1
  double v420; // d2
  double v421; // d3
  double v422; // d4
  double v423; // d5
  double v424; // d6
  double v425; // d7
  double v426; // d0
  double v427; // d1
  double v428; // d2
  double v429; // d3
  double v430; // d4
  double v431; // d5
  double v432; // d6
  double v433; // d7
  double v434; // d0
  double v435; // d1
  double v436; // d2
  double v437; // d3
  double v438; // d4
  double v439; // d5
  double v440; // d6
  double v441; // d7
  unsigned __int64 v442; // x19
  __int64 v443; // x0
  __int64 v444; // x25
  __int16 v445; // w8
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
  int v470; // w5
  unsigned __int8 v471; // w4
  int v472; // w0
  double v473; // d0
  double v474; // d1
  double v475; // d2
  double v476; // d3
  double v477; // d4
  double v478; // d5
  double v479; // d6
  double v480; // d7
  size_t v481; // x2
  _DWORD *v482; // x26
  __int64 v483; // x20
  unsigned __int64 v484; // x20
  unsigned __int64 v485; // x9
  unsigned __int64 v486; // x9
  unsigned __int8 v487; // w0
  double v488; // d0
  double v489; // d1
  double v490; // d2
  double v491; // d3
  double v492; // d4
  double v493; // d5
  double v494; // d6
  double v495; // d7
  __int64 v496; // x8
  int v497; // w3
  char *v498; // x26
  char v499; // w19
  unsigned __int8 v500; // w0
  unsigned __int8 v501; // w19
  char *v502; // x26
  unsigned __int8 v503; // w0
  unsigned __int8 v504; // w19
  char *v505; // x26
  unsigned __int8 v506; // w0
  unsigned __int8 v507; // w19
  char *v508; // x26
  unsigned __int8 v509; // w0
  unsigned __int8 v510; // w19
  char *v511; // x26
  unsigned __int8 v512; // w0
  unsigned __int8 v513; // w19
  char *v514; // x26
  unsigned __int8 v515; // w0
  __int16 v516; // w2
  __int64 v517; // [xsp+0h] [xbp-1B0h]
  __int64 v518; // [xsp+8h] [xbp-1A8h]
  __int64 v519; // [xsp+10h] [xbp-1A0h]
  __int64 v520; // [xsp+18h] [xbp-198h]
  __int64 v521; // [xsp+20h] [xbp-190h]
  __int64 v522; // [xsp+28h] [xbp-188h]
  __int64 v523; // [xsp+30h] [xbp-180h]
  __int64 v524; // [xsp+38h] [xbp-178h]
  char v525; // [xsp+44h] [xbp-16Ch]
  char v526; // [xsp+48h] [xbp-168h]
  int v527; // [xsp+4Ch] [xbp-164h]
  __int64 v528; // [xsp+50h] [xbp-160h]
  char v529; // [xsp+58h] [xbp-158h]
  char v530; // [xsp+5Ch] [xbp-154h]
  __int64 v531; // [xsp+60h] [xbp-150h]
  __int64 v532; // [xsp+68h] [xbp-148h]
  __int64 v533; // [xsp+70h] [xbp-140h]
  int v534; // [xsp+70h] [xbp-140h]
  char v535; // [xsp+78h] [xbp-138h]
  unsigned __int16 v536; // [xsp+78h] [xbp-138h]
  int v537; // [xsp+84h] [xbp-12Ch]
  char v538; // [xsp+84h] [xbp-12Ch]
  unsigned int v539; // [xsp+84h] [xbp-12Ch]
  int v540; // [xsp+88h] [xbp-128h]
  _BYTE *v541; // [xsp+88h] [xbp-128h]
  unsigned __int64 v542; // [xsp+88h] [xbp-128h]
  unsigned __int64 v543; // [xsp+88h] [xbp-128h]
  char *v544; // [xsp+90h] [xbp-120h]
  unsigned int v545; // [xsp+90h] [xbp-120h]
  unsigned __int16 v546; // [xsp+90h] [xbp-120h]
  unsigned __int64 v547; // [xsp+90h] [xbp-120h]
  __int64 v548; // [xsp+98h] [xbp-118h]
  __int64 v549; // [xsp+A0h] [xbp-110h]
  __int64 v550; // [xsp+A8h] [xbp-108h]
  __int64 v551; // [xsp+B0h] [xbp-100h]
  __int64 v552; // [xsp+B0h] [xbp-100h]
  __int64 v553; // [xsp+B0h] [xbp-100h]
  __int64 v554; // [xsp+B8h] [xbp-F8h]
  __int64 v555; // [xsp+B8h] [xbp-F8h]
  __int64 v556; // [xsp+C0h] [xbp-F0h]
  unsigned int v557; // [xsp+C0h] [xbp-F0h]
  __int64 v558; // [xsp+C0h] [xbp-F0h]
  __int64 v559; // [xsp+C8h] [xbp-E8h]
  __int64 v560; // [xsp+D0h] [xbp-E0h]
  __int64 v561; // [xsp+D0h] [xbp-E0h]
  __int64 v562; // [xsp+D8h] [xbp-D8h]
  __int16 v567; // [xsp+104h] [xbp-ACh] BYREF
  unsigned __int8 v568; // [xsp+106h] [xbp-AAh]
  __int64 v569; // [xsp+108h] [xbp-A8h] BYREF
  __int64 v570; // [xsp+110h] [xbp-A0h]
  __int64 v571; // [xsp+118h] [xbp-98h]
  __int64 v572; // [xsp+120h] [xbp-90h]
  __int64 v573; // [xsp+128h] [xbp-88h]
  __int64 v574; // [xsp+130h] [xbp-80h]
  __int64 v575; // [xsp+138h] [xbp-78h] BYREF
  unsigned __int64 time_of_the_day_us; // [xsp+140h] [xbp-70h]
  __int64 v577; // [xsp+148h] [xbp-68h]
  __int64 v578; // [xsp+150h] [xbp-60h]
  __int64 v579; // [xsp+158h] [xbp-58h]
  __int64 v580; // [xsp+160h] [xbp-50h]
  int v581; // [xsp+168h] [xbp-48h]
  char s[8]; // [xsp+170h] [xbp-40h] BYREF
  __int64 v583; // [xsp+178h] [xbp-38h]
  __int64 v584; // [xsp+180h] [xbp-30h]
  __int64 v585; // [xsp+188h] [xbp-28h]
  _QWORD v586[4]; // [xsp+190h] [xbp-20h]

  v586[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_WORD *)(a3 + 6) )
  {
    v49 = _qdf_mem_malloc(0x108u, "rrm_process_radio_measurement_request", 2489);
    if ( !v49 )
      goto LABEL_22;
    v58 = v49;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: RX: [802.11 RRM] No requestIes in the measurement request, sending incapable report",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "rrm_process_radio_measurement_request");
    *(_BYTE *)(v58 + 2) = 1;
    lim_send_radio_measure_report_action_frame(a1, *(_BYTE *)(a3 + 2), 1u, 1, v58, a2, a4);
    _qdf_mem_free(v58);
    result = 16;
    goto LABEL_33;
  }
  if ( (unsigned int)wlan_vdev_is_up() )
  {
    v20 = jiffies;
    if ( rrm_process_radio_measurement_request___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        4u,
        "%s: Vdev:%d is not up, reject RRM request",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "rrm_process_radio_measurement_request",
        *(unsigned __int8 *)(a4 + 10));
      rrm_process_radio_measurement_request___last_ticks = v20;
    }
    v21 = *(_BYTE *)(a3 + 2);
    v22 = *(unsigned __int8 *)(a3 + 18);
    v23 = *(_WORD *)(a3 + 12);
    v24 = *(_BYTE *)(a3 + 11);
    v25 = *(_WORD *)(a3 + 16);
    v581 = 0;
    v579 = 0;
    v580 = 0;
    v577 = 0;
    v578 = 0;
    v575 = 0;
    time_of_the_day_us = 0;
    qdf_mem_set(&v575, 0x34u, 0);
    HIWORD(v575) = *(unsigned __int8 *)(*(_QWORD *)(a4 + 16) + 104LL);
    time_of_the_day_us = qdf_get_time_of_the_day_us();
    v30 = ktime_get(time_of_the_day_us, v26, v27, v28, v29);
    HIBYTE(v579) = v21;
    LOWORD(v580) = v22;
    *(_WORD *)((char *)&v579 + 3) = v23;
    WORD1(v580) = v25;
    LOWORD(v579) = 11011;
    BYTE5(v579) = v24;
    v578 = v30 / 1000;
    host_diag_event_report_payload(3384, 52, &v575);
    v31 = *(unsigned __int16 *)(a3 + 6);
    if ( *(_WORD *)(a3 + 6) )
      goto LABEL_6;
    goto LABEL_32;
  }
  if ( !*(_WORD *)(a3 + 4) )
  {
    if ( *(_QWORD *)(a1 + 20160) )
    {
      v71 = 0;
      goto LABEL_31;
    }
    if ( *(_QWORD *)(a1 + 20168) )
    {
      v71 = 1;
      goto LABEL_31;
    }
    if ( *(_QWORD *)(a1 + 20176) )
    {
      v71 = 2;
      goto LABEL_31;
    }
    if ( *(_QWORD *)(a1 + 20184) )
    {
      v71 = 3;
      goto LABEL_31;
    }
    if ( *(_QWORD *)(a1 + 20192) )
    {
      v71 = 4;
LABEL_31:
      v72 = *(_BYTE *)(a3 + 2);
      v73 = *(unsigned __int8 *)(a3 + 18);
      v74 = *(_WORD *)(a3 + 12);
      v75 = *(_BYTE *)(a3 + 11);
      v76 = *(_WORD *)(a3 + 16);
      v581 = 0;
      v579 = 0;
      v580 = 0;
      v577 = 0;
      v578 = 0;
      v575 = 0;
      time_of_the_day_us = 0;
      qdf_mem_set(&v575, 0x34u, 0);
      HIWORD(v575) = *(unsigned __int8 *)(*(_QWORD *)(a4 + 16) + 104LL);
      time_of_the_day_us = qdf_get_time_of_the_day_us();
      v81 = ktime_get(time_of_the_day_us, v77, v78, v79, v80);
      HIBYTE(v579) = v72;
      LOWORD(v580) = v73;
      *(_WORD *)((char *)&v579 + 3) = v74;
      WORD1(v580) = v76;
      LOWORD(v579) = 11011;
      BYTE5(v579) = v75;
      v578 = v81 / 1000;
      host_diag_event_report_payload(3384, 52, &v575);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RRM req for index: %d is already in progress",
        v82,
        v83,
        v84,
        v85,
        v86,
        v87,
        v88,
        v89,
        "rrm_process_radio_measurement_request",
        v71);
      v31 = *(unsigned __int16 *)(a3 + 6);
      if ( *(_WORD *)(a3 + 6) )
      {
LABEL_6:
        v32 = 0;
        v33 = 0;
        v34 = 0;
        v35 = 0;
        v36 = (char *)(a3 + 11);
        while ( 1 )
        {
          if ( v33 == -5 )
            goto LABEL_275;
          v39 = *v36;
          if ( !v35 )
          {
            v40 = _qdf_mem_malloc((int)(264 * (v33 + v31)), "rrm_reject_req", 2440);
            if ( !v40 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Fail to Reject rrm req for index: %d",
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                "rrm_process_radio_measurement_request",
                v34);
              goto LABEL_22;
            }
            v35 = v40;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: rrm beacon refused of %d report, index: %d in beacon table",
              v41,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              "rrm_reject_req",
              v34,
              v34);
          }
          v37 = (_BYTE *)(v35 + v32);
          ++v34;
          --v33;
          v37[1] = 1;
          v32 += 264;
          v37[3] = v39;
          v38 = *(v36 - 2);
          v36 += 682;
          *v37 = v38;
          v31 = *(unsigned __int16 *)(a3 + 6);
          if ( v31 <= (unsigned __int16)v34 )
          {
            LODWORD(result) = 0;
            goto LABEL_18;
          }
        }
      }
LABEL_32:
      result = 0;
      goto LABEL_33;
    }
    qdf_mem_set((void *)(a1 + 20200), 0xFFu, 0);
    *(_BYTE *)(a1 + 21220) = 0;
    v98 = *(unsigned __int16 *)(a3 + 6);
    v548 = a1 + 20148;
    if ( !*(_WORD *)(a3 + 6) )
      goto LABEL_32;
    v99 = a7;
    v100 = 0;
    LODWORD(result) = 0;
    LOBYTE(v34) = 0;
    v549 = a1 + 20160;
    v35 = 0;
    v559 = a3 + 8;
    v101 = a6;
    v102 = 0;
    v103 = a3 + 66;
    v104 = a3 + 324;
    v105 = a3 + 585;
    v106 = a3 + 638;
    v107 = a3 + 691;
    v108 = "update_rrm_report";
    v109 = a5;
    v562 = a4;
    while ( 1 )
    {
      if ( v102 == 5 )
LABEL_275:
        __break(0x5512u);
      v110 = v559 + 682 * v102;
      v113 = *(unsigned __int8 *)(v110 + 3);
      v112 = (unsigned __int8 *)(v110 + 3);
      v111 = v113;
      if ( v113 <= 7 )
        break;
      a4 = v562;
      if ( v111 != 8 && v111 != 11 && v111 != 16 )
      {
LABEL_77:
        if ( !v35 )
        {
          v555 = v106;
          v558 = v105;
          v180 = 33 * (v98 - v100);
          v181 = v104;
          v182 = v103;
          v183 = v108;
          v184 = _qdf_mem_malloc(8 * v180, v108, 2413);
          if ( !v184 )
          {
LABEL_22:
            result = 2;
            goto LABEL_33;
          }
          v35 = v184;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: rrm beacon type incapable of %d report",
            v185,
            v186,
            v187,
            v188,
            v189,
            v190,
            v191,
            v192,
            v183,
            (unsigned __int8)v34);
          v106 = v555;
          v105 = v558;
          v109 = a5;
          v99 = a7;
          v101 = a6;
          v103 = v182;
          v104 = v181;
          v108 = v183;
        }
        v193 = (unsigned __int8)v34;
        v194 = v559 + 682 * v102;
        result = 0;
        LOBYTE(v34) = v34 + 1;
        v195 = (_BYTE *)(v35 + 264LL * v193);
        v195[2] = 1;
        v195[3] = *(_BYTE *)(v194 + 3);
        *v195 = *(_BYTE *)(v194 + 1);
        goto LABEL_39;
      }
      v557 = result;
      v552 = v102;
      v145 = v104;
      v146 = v105;
      v561 = v103;
      v147 = v107;
      v148 = v106;
      lim_send_sme_mgmt_frame_ind(a1, *v109 >> 4, (__int64)v109, v101 + 24, 0, *v99, v99[2], 0);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RRM with type: %d sent to userspace",
        v149,
        v150,
        v151,
        v152,
        v153,
        v154,
        v155,
        v156,
        "rrm_process_radio_measurement_request",
        *v112);
      v104 = v145;
      v103 = v561;
      result = v557;
      v102 = v552;
      v101 = a6;
      v108 = "update_rrm_report";
      v99 = a7;
      v106 = v148;
      v107 = v147;
      v105 = v146;
      v109 = a5;
LABEL_39:
      v98 = *(unsigned __int16 *)(a3 + 6);
      ++v102;
      v103 += 682;
      v104 += 682;
      v105 += 682;
      v106 += 682;
      v107 += 682;
      v100 = v102;
      if ( v98 <= (unsigned __int16)v102 )
      {
        if ( v35 )
          goto LABEL_18;
        goto LABEL_33;
      }
    }
    a4 = v562;
    if ( v111 != 3 )
    {
      if ( v111 != 5 )
      {
        if ( v111 != 7 )
          goto LABEL_77;
        v114 = *(unsigned __int8 *)(a3 + 11);
        v115 = *(unsigned __int8 *)(a3 + 693);
        v554 = v106;
        v556 = v105;
        v550 = v104;
        v560 = v103;
        if ( v114 != 7 || v115 != 7 )
        {
          if ( v115 == 7 )
            v116 = (v114 == 7) + 1;
          else
            v116 = v114 == 7;
          if ( *(_BYTE *)(a3 + 1375) == 7 )
            ++v116;
          if ( v116 <= 1 )
          {
            if ( *(_BYTE *)(a3 + 2057) == 7 )
              LOBYTE(v116) = v116 + 1;
            if ( (unsigned __int8)v116 <= 1u )
            {
              if ( *(_BYTE *)(a3 + 2739) == 7 )
                LOBYTE(v116) = v116 + 1;
              if ( (unsigned __int8)v116 < 2u )
              {
                v117 = (_BYTE *)_qdf_mem_malloc(0x130u, "rrm_process_sta_stats_req", 1092);
                if ( v117 )
                {
                  v118 = v559 + 682 * v102;
                  v119 = v117;
                  v117[1] = *(_BYTE *)(a3 + 2);
                  v120 = *(_BYTE *)(v118 + 1);
                  *v117 = v102;
                  v117[2] = v120;
                  v117[3] = *(_BYTE *)(v118 + 3);
                  qdf_mem_set((void *)(v548 + 1076), 0x118u, 0);
                  *(_BYTE *)(v548 + 1346) = v102;
                  v551 = v102;
                  *(_QWORD *)(v549 + 8 * v102) = v119;
                  ++*(_BYTE *)(v548 + 10);
                  qdf_mem_copy((void *)(a1 + 21488), a2, 6u);
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Processing sta stats Report req %d num_active_req:%d",
                    v121,
                    v122,
                    v123,
                    v124,
                    v125,
                    v126,
                    v127,
                    v128,
                    "rrm_process_sta_stats_req",
                    v100,
                    *(unsigned __int8 *)(v548 + 10));
                  v137 = (*(_DWORD *)v548 >> 21) & 7;
                  v138 = 4 - v137;
                  v139 = v137 >= 4;
                  v140 = v137 - 4;
                  if ( !v139 )
                    v140 = v138;
                  v141 = 1LL << v140;
                  if ( v139 )
                    v142 = *(_WORD *)(v562 + 7158) * v141;
                  else
                    v142 = *(_WORD *)(v562 + 7158) / (unsigned __int16)v141;
                  if ( *(unsigned __int16 *)(v118 + 12) <= 0xAu )
                    v395 = 10;
                  else
                    v395 = *(unsigned __int16 *)(v118 + 12);
                  if ( v395 > v142 )
                  {
                    LOWORD(v395) = v142;
                    if ( (*(_BYTE *)(v118 + 2) & 0x10) != 0 )
                    {
                      v407 = 2;
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "Dropping the req: duration mandatory & max duration > meas duration",
                        v129,
                        v130,
                        v131,
                        v132,
                        v133,
                        v134,
                        v135,
                        v136);
                      goto LABEL_202;
                    }
                  }
                  if ( *(_DWORD *)(v118 + 4) == -1 && *(__int16 *)(v118 + 8) == -1 )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: Dropping req: broadcast address not supported",
                      v129,
                      v130,
                      v131,
                      v132,
                      v133,
                      v134,
                      v135,
                      v136,
                      "rrm_process_sta_stats_report_req");
                  }
                  else
                  {
                    *(_BYTE *)(v548 + 1076) = v119[2];
                    v397 = v119[3];
                    *(_WORD *)(v548 + 1077) = 0;
                    *(_BYTE *)(v548 + 1079) = v397;
                    v398 = *(_BYTE *)(v118 + 14);
                    *(_WORD *)(v548 + 1084) = v395;
                    *(_BYTE *)(v548 + 1086) = v398;
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: sta stats req vdev :%d, meas_dur:%d, max_dur:%d group id %d",
                      v129,
                      v130,
                      v131,
                      v132,
                      v133,
                      v134,
                      v135,
                      v136,
                      "rrm_process_sta_stats_report_req",
                      *(unsigned __int8 *)(v562 + 10),
                      (unsigned __int16)v395);
                    if ( *(unsigned __int8 *)(v118 + 14) <= 1u )
                    {
                      if ( (unsigned int)rrm_send_sta_stats_req(a1, v562, (const void *)(v118 + 4)) )
                      {
                        v407 = 2;
                        goto LABEL_202;
                      }
                      *(_BYTE *)(a1 + 3506) = *(_BYTE *)(v562 + 8);
                      tx_timer_change(a1 + 3456, (unsigned __int16)v395 / 0xAu, 0);
                      result = tx_timer_activate((char *)(a1 + 3456));
                      if ( (_DWORD)result )
                      {
                        v407 = 2;
                        qdf_trace_msg(
                          0x35u,
                          2u,
                          "%s: failed to start sta stats timer",
                          v90,
                          v91,
                          v92,
                          v93,
                          v94,
                          v95,
                          v96,
                          v97,
                          "rrm_process_sta_stats_report_req");
LABEL_202:
                        v408 = v407;
                        v102 = v551;
                        a4 = v562;
                        v409 = ((double (__fastcall *)(__int64, __int64, unsigned __int8 *, __int64, _QWORD))rrm_process_rrm_sta_stats_request_failure)(
                                 a1,
                                 v562,
                                 a2,
                                 v408,
                                 (unsigned int)v551);
                        rrm_cleanup(a1, (unsigned int)v551, v409, v410, v411, v412, v413, v414, v415, v416);
                        v99 = a7;
                        v101 = a6;
                        result = 16;
                        v109 = a5;
                      }
                      else
                      {
                        v99 = a7;
                        v101 = a6;
                        v109 = a5;
                        a4 = v562;
                        v102 = v551;
                      }
                      v106 = v554;
                      v105 = v556;
                      v103 = v560;
                      v104 = v550;
                      goto LABEL_271;
                    }
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "group id %d not supported",
                      v399,
                      v400,
                      v401,
                      v402,
                      v403,
                      v404,
                      v405,
                      v406);
                  }
                  v407 = 1;
                  goto LABEL_202;
                }
                *(_QWORD *)(v549 + 8 * v102) = 0;
                qdf_mem_set((void *)(v548 + 1076), 0x118u, 0);
                result = 2;
                goto LABEL_115;
              }
            }
          }
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: another sta stats request already in progress",
          v90,
          v91,
          v92,
          v93,
          v94,
          v95,
          v96,
          v97,
          "rrm_process_sta_stats_req");
        result = 16;
LABEL_37:
        v99 = a7;
        v101 = a6;
        v109 = a5;
LABEL_38:
        v106 = v554;
        v105 = v556;
        v103 = v560;
        v104 = v550;
        v108 = "update_rrm_report";
        goto LABEL_39;
      }
      v554 = v106;
      v556 = v105;
      v550 = v104;
      v560 = v103;
      v196 = _qdf_mem_malloc(0x130u, "rrm_process_beacon_req", 1989);
      if ( !v196 )
      {
LABEL_274:
        result = 2;
        *(_QWORD *)(v549 + 8LL * (unsigned __int8)v102) = 0;
        goto LABEL_33;
      }
      v205 = (_BYTE *)v196;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Processing Beacon Report request %d",
        v197,
        v198,
        v199,
        v200,
        v201,
        v202,
        v203,
        v204,
        "rrm_process_beacon_req",
        v100);
      v206 = v559 + 682 * v102;
      v205[1] = *(_BYTE *)(a3 + 2);
      v207 = *(_BYTE *)(v206 + 1);
      v205[296] = 1;
      *v205 = v102;
      v205[2] = v207;
      *(_QWORD *)(v549 + 8 * v102) = v205;
      v208 = (unsigned __int8)++*(_BYTE *)(v548 + 10);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Processing Bcn Report req %d num_active_req:%d",
        v209,
        v210,
        v211,
        v212,
        v213,
        v214,
        v215,
        v216,
        "rrm_process_beacon_req",
        v100,
        v208);
      v573 = 0;
      v574 = 0;
      *(_QWORD *)((char *)v586 + 5) = 0;
      v585 = 0;
      v586[0] = 0;
      v571 = 0;
      v572 = 0;
      v569 = 0;
      v570 = 0;
      v583 = 0;
      v584 = 0;
      *(_QWORD *)s = 0;
      v568 = 0;
      v567 = 0;
      if ( !v562 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: pe_session is NULL",
          v217,
          v218,
          v219,
          v220,
          v221,
          v222,
          v223,
          v224,
          "rrm_process_beacon_report_req");
LABEL_89:
        v241 = 1;
        goto LABEL_90;
      }
      if ( (unsigned __int8)wlan_policy_mgr_get_ll_lt_sap_vdev_id(*(_QWORD *)(a1 + 21552)) != 0xFF )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: RX: [802.11 BCN_RPT] reject req as ll_lt_sap is present",
          v225,
          v226,
          v227,
          v228,
          v229,
          v230,
          v231,
          v232,
          "rrm_process_beacon_report_req");
        v241 = 2;
        goto LABEL_90;
      }
      if ( *(_BYTE *)(v206 + 51) && *(_BYTE *)(v206 + 52) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "RX: [802.11 BCN_RPT] Dropping req: Reporting condition included is not zero",
          v225,
          v226,
          v227,
          v228,
          v229,
          v230,
          v231,
          v232);
        goto LABEL_89;
      }
      v279 = (*(_DWORD *)v548 >> 21) & 7;
      v280 = 4 - v279;
      v281 = v279 >= 4;
      v282 = v279 - 4;
      if ( !v281 )
        v282 = v280;
      v283 = 1LL << v282;
      if ( v281 )
        v284 = *(_WORD *)(v562 + 7158) * v283;
      else
        v284 = *(_WORD *)(v562 + 7158) / (unsigned __int16)v283;
      v541 = v205;
      v287 = *(unsigned __int8 *)(v206 + 10);
      v553 = v102;
      v288 = *(unsigned __int16 *)(v206 + 8);
      v289 = jiffies;
      if ( *(_BYTE *)(v206 + 10) )
        v290 = v284;
      else
        v290 = v284 + 10;
      if ( rrm_process_beacon_report_req___last_ticks - jiffies + 125 < 0 )
      {
        LODWORD(v524) = v290;
        LODWORD(v523) = *(unsigned __int16 *)(v206 + 8);
        LODWORD(v522) = *(unsigned __int8 *)(v206 + 10);
        LODWORD(v521) = *(unsigned __int8 *)(v206 + 5);
        LODWORD(v520) = *(unsigned __int8 *)(v206 + 4);
        LODWORD(v519) = *(unsigned __int8 *)(v206 + 1);
        LODWORD(v518) = *(unsigned __int8 *)(v206 + 16);
        LODWORD(v517) = *(unsigned __int8 *)(v206 + 13);
        qdf_trace_msg(
          0x35u,
          4u,
          "RX: [802.11 BCN_RPT] seq:%d SSID:%.*s BSSID:%02x:%02x:%02x:**:**:%02x Token:%d op_class:%d ch:%d meas_mode:%d "
          "meas_duration:%d max_meas_dur: %d",
          v225,
          v226,
          v227,
          v228,
          v229,
          v230,
          v231,
          v232,
          *(unsigned __int16 *)(v548 + 8),
          *(unsigned __int8 *)(v206 + 18),
          v206 + 19,
          *(unsigned __int8 *)(v206 + 11),
          *(unsigned __int8 *)(v206 + 12),
          v517,
          v518,
          v519,
          v520,
          v521,
          v522,
          v523,
          v524);
        rrm_process_beacon_report_req___last_ticks = v289;
        v287 = *(unsigned __int8 *)(v206 + 10);
      }
      v291 = *(_BYTE *)(v206 + 1);
      v545 = v288;
      v292 = *(_WORD *)(v206 + 4);
      v293 = *(_BYTE *)(v206 + 2) & 0x1F;
      v536 = v290;
      v581 = 0;
      v294 = v287;
      v579 = 0;
      v580 = 0;
      v577 = 0;
      v578 = 0;
      v575 = 0;
      time_of_the_day_us = 0;
      v538 = v293;
      qdf_mem_set(&v575, 0x34u, 0);
      HIWORD(v575) = *(unsigned __int8 *)(*(_QWORD *)(v562 + 16) + 104LL);
      time_of_the_day_us = qdf_get_time_of_the_day_us();
      v299 = ktime_get(time_of_the_day_us, v295, v296, v297, v298);
      HIBYTE(v579) = v291;
      LOWORD(v579) = 11011;
      v300 = v545;
      LOWORD(v580) = v294;
      *(_WORD *)((char *)&v579 + 3) = v292;
      WORD1(v580) = v545;
      v578 = v299 / 1000;
      BYTE5(v579) = v538;
      host_diag_event_report_payload(3384, 52, &v575);
      if ( v545 || *(_BYTE *)(v206 + 10) == 2 )
      {
        if ( v545 <= v536 || (v300 = v536, (*(_BYTE *)(v206 + 2) & 0x10) == 0) )
        {
          v539 = v100;
          v532 = v107;
          v546 = v300;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: measurement duration %d",
            v301,
            v302,
            v303,
            v304,
            v305,
            v306,
            v307,
            v308,
            "rrm_process_beacon_report_req",
            v300);
          if ( *(_BYTE *)(v206 + 54) )
            v317 = *(_BYTE *)(v206 + 55);
          else
            v317 = 2;
          v541[8] = v317;
          if ( *(_BYTE *)(v206 + 680) )
          {
            v541[9] = *(_BYTE *)(v206 + 681);
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: RX: [802.11 BCN_RPT] Last Bcn Report in the req: %d",
              v309,
              v310,
              v311,
              v312,
              v313,
              v314,
              v315,
              v316,
              "rrm_process_beacon_report_req");
          }
          else
          {
            v541[9] = 0;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: RX: [802.11 BCN_RPT] Last Bcn rpt ind not present",
              v309,
              v310,
              v311,
              v312,
              v313,
              v314,
              v315,
              v316,
              "rrm_process_beacon_report_req");
          }
          v357 = (unsigned __int8 *)v206;
          if ( !*(_BYTE *)(v206 + 56) )
            goto LABEL_161;
          if ( *(_BYTE *)(v206 + 57) )
          {
            v358 = (void *)_qdf_mem_malloc(*(unsigned __int8 *)(v206 + 57), "rrm_process_beacon_report_req", 1258);
            *((_QWORD *)v541 + 3) = v358;
            if ( v358 )
            {
              v359 = *(unsigned __int8 *)(v206 + 57);
              v541[16] = v359;
              qdf_mem_copy(v358, (const void *)(v206 + 58), v359);
              if ( v541[16] )
              {
                v360 = 0;
                do
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: RX: [802.11 BCN_RPT]:Requested EID is %d",
                    v349,
                    v350,
                    v351,
                    v352,
                    v353,
                    v354,
                    v355,
                    v356,
                    "rrm_process_beacon_report_req",
                    *(unsigned __int8 *)(v560 + v360++));
                while ( v360 < (unsigned __int8)v541[16] );
              }
LABEL_161:
              if ( *(_BYTE *)(v206 + 313) )
              {
                if ( !*(_BYTE *)(v206 + 315) )
                {
                  v361 = "%s: RX: [802.11 BCN_RPT]: Requested num of Extn EID is 0";
                  goto LABEL_192;
                }
                if ( *(unsigned __int8 *)(v206 + 314) != 255 )
                {
                  v361 = "%s: RX: [802.11 BCN_RPT]: Extn Element ID is not 0xFF";
LABEL_192:
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    v361,
                    v349,
                    v350,
                    v351,
                    v352,
                    v353,
                    v354,
                    v355,
                    v356,
                    "rrm_process_beacon_report_req");
                  goto LABEL_257;
                }
                v541[32] = -1;
                v417 = *(unsigned __int8 *)(v206 + 315);
                v541[33] = v417;
                qdf_mem_copy(v541 + 34, (const void *)(v206 + 316), v417);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: RX: [802.11 BCN_RPT]: EID is %d",
                  v418,
                  v419,
                  v420,
                  v421,
                  v422,
                  v423,
                  v424,
                  v425,
                  "rrm_process_beacon_report_req",
                  (unsigned __int8)v541[32]);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: RX: [802.11 BCN_RPT]:Num of Extn EID is %d",
                  v426,
                  v427,
                  v428,
                  v429,
                  v430,
                  v431,
                  v432,
                  v433,
                  "rrm_process_beacon_report_req",
                  (unsigned __int8)v541[33]);
                if ( v541[33] )
                {
                  v442 = 0;
                  do
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: RX: [802.11 BCN_RPT]:Requested Extn EID is %d",
                      v434,
                      v435,
                      v436,
                      v437,
                      v438,
                      v439,
                      v440,
                      v441,
                      "rrm_process_beacon_report_req",
                      *(unsigned __int8 *)(v550 + v442++));
                  while ( v442 < (unsigned __int8)v541[33] );
                }
              }
              v443 = _qdf_mem_malloc(0x84u, "rrm_process_beacon_report_req", 1302);
              if ( v443 )
              {
                v444 = v443;
                qdf_mem_copy((void *)(v443 + 5), (const void *)(v562 + 24), 6u);
                *(_DWORD *)v444 = 8655917;
                v445 = *(unsigned __int8 *)(v206 + 1);
                *(_DWORD *)(v444 + 128) = 2;
                *(_WORD *)(v444 + 88) = v445;
                *(_WORD *)(v444 + 28) = (68719477 * (unsigned __int64)(*(unsigned __int16 *)(v206 + 6) << 10)) >> 36;
                *(_BYTE *)(v444 + 4) = *v541;
                if ( (wlan_reg_is_6ghz_supported(
                        *(_QWORD *)(a1 + 21552),
                        v446,
                        v447,
                        v448,
                        v449,
                        v450,
                        v451,
                        v452,
                        v453)
                    & 1) != 0
                  || !wlan_reg_is_6ghz_op_class(*(_QWORD *)(a1 + 21560), *(_BYTE *)(v206 + 4)) )
                {
                  rrm_get_country_code_from_connected_profile(a1, *(_BYTE *)(v562 + 10), (unsigned __int8 *)&v567);
                  v470 = *(unsigned __int8 *)(v206 + 5);
                  *(_BYTE *)(v444 + 33) = v470;
                  v471 = *(_BYTE *)(v206 + 4);
                  *(_BYTE *)(v444 + 32) = v471;
                  if ( !v470 || v470 == 255 )
                  {
                    *(_DWORD *)(v444 + 36) = 0;
LABEL_215:
                    LODWORD(v519) = *(unsigned __int8 *)(v444 + 4);
                    LODWORD(v518) = v568;
                    LODWORD(v517) = HIBYTE(v567);
                    qdf_trace_msg(
                      0x34u,
                      8u,
                      "%s: opclass %d, ch %d freq %d AP's country code %c%c 0x%x index:%d",
                      v462,
                      v463,
                      v464,
                      v465,
                      v466,
                      v467,
                      v468,
                      v469,
                      "rrm_process_beacon_report_req",
                      v517,
                      v518,
                      v519);
                    *(_WORD *)(v444 + 12) = v546;
                    *(_BYTE *)(v444 + 46) = *(_BYTE *)(v206 + 10);
                    qdf_mem_copy((void *)(v444 + 40), (const void *)(v206 + 11), 6u);
                    if ( *(_BYTE *)(v206 + 17) )
                    {
                      v481 = *(unsigned __int8 *)(v206 + 18);
                      *(_BYTE *)(v444 + 54) = v481;
                      qdf_mem_copy((void *)(v444 + 55), (const void *)(v206 + 19), v481);
                    }
                    v541[2] = *(_BYTE *)(v206 + 1);
                    v534 = *(unsigned __int8 *)(v206 + 572);
                    if ( *(_BYTE *)(v206 + 572) )
                    {
                      v482 = (_DWORD *)(v444 + 96);
                      if ( v357[576] )
                      {
                        v483 = 0;
                        while ( 1 )
                        {
                          if ( (wlan_reg_is_6ghz_supported(
                                  *(_QWORD *)(a1 + 21552),
                                  v473,
                                  v474,
                                  v475,
                                  v476,
                                  v477,
                                  v478,
                                  v479,
                                  v480)
                              & 1) == 0
                            && wlan_reg_is_6ghz_op_class(*(_QWORD *)(a1 + 21560), v357[575]) )
                          {
                            goto LABEL_210;
                          }
                          v482[v483] = wlan_reg_country_chan_opclass_to_freq(
                                         *(_QWORD *)(a1 + 21560),
                                         (unsigned __int8 *)&v567,
                                         *(_BYTE *)(v556 + v483),
                                         v357[575],
                                         1,
                                         v454,
                                         v455,
                                         v456,
                                         v457,
                                         v458,
                                         v459,
                                         v460,
                                         v461);
                          if ( v483 == 7 )
                            break;
                          if ( ++v483 >= (unsigned __int64)v357[576] )
                          {
                            v547 = (unsigned __int16)v483;
                            goto LABEL_230;
                          }
                        }
                        v496 = 8;
LABEL_260:
                        v497 = *(_DWORD *)(v444 + 96);
                        v547 = v496;
                        *(_BYTE *)(v444 + 92) = v496;
                        v487 = snprintf(s, 0x2Du, "%d ", v497);
LABEL_261:
                        v498 = &s[v487];
                        v499 = 45 - v487;
                        v500 = snprintf(v498, (unsigned __int8)(45 - v487), "%d ", *(_DWORD *)(v444 + 100));
                        if ( v547 != 2 )
                        {
                          v501 = v499 - v500;
                          v502 = &v498[v500];
                          v503 = snprintf(v502, v501, "%d ", *(_DWORD *)(v444 + 104));
                          if ( v547 != 3 )
                          {
                            v504 = v501 - v503;
                            v505 = &v502[v503];
                            v506 = snprintf(v505, v504, "%d ", *(_DWORD *)(v444 + 108));
                            if ( v547 != 4 )
                            {
                              v507 = v504 - v506;
                              v508 = &v505[v506];
                              v509 = snprintf(v508, v507, "%d ", *(_DWORD *)(v444 + 112));
                              if ( v547 != 5 )
                              {
                                v510 = v507 - v509;
                                v511 = &v508[v509];
                                v512 = snprintf(v511, v510, "%d ", *(_DWORD *)(v444 + 116));
                                if ( v547 != 6 )
                                {
                                  v513 = v510 - v512;
                                  v514 = &v511[v512];
                                  v515 = snprintf(v514, v513, "%d ", *(_DWORD *)(v444 + 120));
                                  if ( v547 != 7 )
                                  {
                                    snprintf(
                                      &v514[v515],
                                      (unsigned __int8)(v513 - v515),
                                      "%d ",
                                      *(_DWORD *)(v444 + 124));
                                    if ( v547 != 8 )
                                      goto LABEL_275;
                                  }
                                }
                              }
                            }
                          }
                        }
LABEL_268:
                        qdf_trace_msg(
                          0x35u,
                          4u,
                          "RX: [802.11 BCN_RPT] Ch-list:%s",
                          v488,
                          v489,
                          v490,
                          v491,
                          v492,
                          v493,
                          v494,
                          v495,
                          s);
                      }
                      else
                      {
                        v547 = 0;
LABEL_230:
                        if ( v534 != 1 )
                        {
                          if ( v357[629] )
                          {
                            v484 = 0;
                            v485 = 7 - v547;
                            if ( v547 > 7 )
                              v485 = 0;
                            v542 = v485;
                            while ( 1 )
                            {
                              if ( (wlan_reg_is_6ghz_supported(
                                      *(_QWORD *)(a1 + 21552),
                                      v473,
                                      v474,
                                      v475,
                                      v476,
                                      v477,
                                      v478,
                                      v479,
                                      v480)
                                  & 1) == 0
                                && wlan_reg_is_6ghz_op_class(*(_QWORD *)(a1 + 21560), v357[628]) )
                              {
                                goto LABEL_210;
                              }
                              *(_DWORD *)(v444 + 4 * v547 + 96 + 4 * v484) = wlan_reg_country_chan_opclass_to_freq(
                                                                               *(_QWORD *)(a1 + 21560),
                                                                               (unsigned __int8 *)&v567,
                                                                               *(_BYTE *)(v554 + v484),
                                                                               v357[628],
                                                                               1,
                                                                               v454,
                                                                               v455,
                                                                               v456,
                                                                               v457,
                                                                               v458,
                                                                               v459,
                                                                               v460,
                                                                               v461);
                              if ( v542 == v484 )
                                break;
                              if ( ++v484 >= v357[629] )
                              {
                                v547 = (unsigned __int16)(v547 + v484);
                                goto LABEL_240;
                              }
                            }
LABEL_259:
                            v496 = (unsigned __int16)(v547 + v484 + 1);
                            goto LABEL_260;
                          }
LABEL_240:
                          if ( v534 != 2 )
                          {
                            if ( v357[682] )
                            {
                              v484 = 0;
                              v486 = 7 - v547;
                              if ( v547 > 7 )
                                v486 = 0;
                              v543 = v486;
                              do
                              {
                                if ( (wlan_reg_is_6ghz_supported(
                                        *(_QWORD *)(a1 + 21552),
                                        v473,
                                        v474,
                                        v475,
                                        v476,
                                        v477,
                                        v478,
                                        v479,
                                        v480)
                                    & 1) == 0
                                  && wlan_reg_is_6ghz_op_class(*(_QWORD *)(a1 + 21560), v357[681]) )
                                {
                                  goto LABEL_210;
                                }
                                *(_DWORD *)(v444 + 4 * v547 + 96 + 4 * v484) = wlan_reg_country_chan_opclass_to_freq(
                                                                                 *(_QWORD *)(a1 + 21560),
                                                                                 (unsigned __int8 *)&v567,
                                                                                 *(_BYTE *)(v532 + v484),
                                                                                 v357[681],
                                                                                 1,
                                                                                 v454,
                                                                                 v455,
                                                                                 v456,
                                                                                 v457,
                                                                                 v458,
                                                                                 v459,
                                                                                 v460,
                                                                                 v461);
                                if ( v543 == v484 )
                                  goto LABEL_259;
                                ++v484;
                              }
                              while ( v484 < v357[682] );
                              v547 = (unsigned __int16)(v547 + v484);
                            }
                            if ( v534 != 3 )
                              goto LABEL_275;
                          }
                        }
                        *(_BYTE *)(v444 + 92) = v547;
                        if ( v547 )
                        {
                          v487 = snprintf(s, 0x2Du, "%d ", *v482);
                          if ( v547 != 1 )
                            goto LABEL_261;
                          goto LABEL_268;
                        }
                      }
                    }
                    else
                    {
                      *(_BYTE *)(v444 + 92) = 0;
                    }
                    a4 = v562;
                    LOWORD(v569) = 5165;
                    v516 = *(_WORD *)(v562 + 8);
                    v570 = v444;
                    qdf_trace(53, 6u, v516, 5165);
                    v393 = &v569;
LABEL_270:
                    sys_process_mmh_msg(a1, v393);
                    v104 = v550;
                    v102 = v553;
                    result = 0;
                    v106 = v554;
                    v105 = v556;
                    v109 = a5;
                    v99 = a7;
                    v101 = a6;
                    v103 = v560;
                    v107 = v532;
LABEL_271:
                    v108 = "update_rrm_report";
                    goto LABEL_39;
                  }
                  v472 = wlan_reg_country_chan_opclass_to_freq(
                           *(_QWORD *)(a1 + 21560),
                           (unsigned __int8 *)&v567,
                           v470,
                           v471,
                           0,
                           v462,
                           v463,
                           v464,
                           v465,
                           v466,
                           v467,
                           v468,
                           v469);
                  *(_DWORD *)(v444 + 36) = v472;
                  if ( v472 )
                    goto LABEL_215;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: invalid ch freq, chan_num %d",
                    v462,
                    v463,
                    v464,
                    v465,
                    v466,
                    v467,
                    v468,
                    v469,
                    "rrm_process_beacon_report_req",
                    *(unsigned __int8 *)(v444 + 33));
                }
                else
                {
LABEL_210:
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "RX: [802.11 BCN_RPT] Ch belongs to 6 ghz spectrum, abort",
                    v454,
                    v455,
                    v456,
                    v457,
                    v458,
                    v459,
                    v460,
                    v461);
                }
                _qdf_mem_free(v444);
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: RX: [802.11 BCN_RPT]: Requested num of EID is 0",
              v349,
              v350,
              v351,
              v352,
              v353,
              v354,
              v355,
              v356,
              "rrm_process_beacon_report_req");
          }
LABEL_257:
          v102 = v553;
          v107 = v532;
          v241 = 3;
          v100 = v539;
LABEL_90:
          v245 = v102;
          v246 = *(unsigned __int8 **)(v549 + 8 * v102);
          if ( v246 )
          {
            v247 = (_BYTE *)_qdf_mem_malloc(0x108u, "rrm_process_beacon_request_failure", 1920);
            if ( v247 )
            {
              v256 = v246[2];
              v257 = v247;
              v247[3] = 5;
              *v247 = v256;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Measurement index:%d status %d token %d",
                v248,
                v249,
                v250,
                v251,
                v252,
                v253,
                v254,
                v255,
                "rrm_process_beacon_request_failure",
                v100,
                v241);
              if ( v241 == 1 )
              {
                v257[2] = 1;
              }
              else
              {
                if ( v241 != 2 )
                {
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: RX [802.11 BCN_RPT] Beacon request processing failed no report sent",
                    v258,
                    v259,
                    v260,
                    v261,
                    v262,
                    v263,
                    v264,
                    v265,
                    "rrm_process_beacon_request_failure");
LABEL_113:
                  _qdf_mem_free((__int64)v257);
                  goto LABEL_114;
                }
                v257[1] = 1;
              }
              if ( v246[9] )
                v257[37] = 1;
              lim_send_radio_measure_report_action_frame(a1, v246[1], 1u, 1, (__int64)v257, a2, v562);
              goto LABEL_113;
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Current request is NULL",
              v233,
              v234,
              v235,
              v236,
              v237,
              v238,
              v239,
              v240,
              "rrm_process_beacon_request_failure");
          }
LABEL_114:
          v102 = v245;
          rrm_cleanup(a1, (unsigned int)v245, v248, v249, v250, v251, v252, v253, v254, v255);
          result = 0;
LABEL_115:
          v99 = a7;
          v101 = a6;
          v109 = a5;
          a4 = v562;
          goto LABEL_38;
        }
        v394 = "RX: [802.11 BCN_RPT] Dropping the req: duration mandatory & maxduration > measduration";
      }
      else
      {
        v394 = "RX: [802.11 BCN_RPT] Invalid measurement duration";
      }
      v241 = 2;
      qdf_trace_msg(0x35u, 2u, v394, v301, v302, v303, v304, v305, v306, v307, v308);
      v102 = v553;
      goto LABEL_90;
    }
    v554 = v106;
    v556 = v105;
    v550 = v104;
    v560 = v103;
    v157 = (char *)_qdf_mem_malloc(0x130u, "rrm_process_chan_load_req", 2363);
    if ( !v157 )
      goto LABEL_274;
    v166 = (_BYTE *)(v559 + 682 * v102);
    v544 = v157;
    v157[1] = *(_BYTE *)(a3 + 2);
    v167 = v166[1];
    *v157 = v102;
    v157[2] = v167;
    *(_QWORD *)(v549 + 8 * v102) = v157;
    v168 = (unsigned __int8)++*(_BYTE *)(v548 + 10);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Processing channel load req index: %d num_active_req:%d",
      v158,
      v159,
      v160,
      v161,
      v162,
      v163,
      v164,
      v165,
      "rrm_process_chan_load_req",
      v100,
      v168);
    v579 = 0;
    v580 = 0;
    v577 = 0;
    v578 = 0;
    v169 = *(_QWORD *)(a1 + 21552);
    v575 = 0;
    time_of_the_day_us = 0;
    BYTE2(v569) = 0;
    LOWORD(v569) = 0;
    if ( (unsigned __int8)wlan_policy_mgr_get_ll_lt_sap_vdev_id(v169) != 0xFF )
    {
      v178 = "%s: RX:[802.11 CH_LOAD] reject req as ll_lt_sap is present";
LABEL_76:
      qdf_trace_msg(0x35u, 8u, v178, v170, v171, v172, v173, v174, v175, v176, v177, "rrm_process_channel_load_req");
      v179 = 2;
LABEL_147:
      ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, __int64, _QWORD))rrm_process_chan_load_request_failure)(
        a1,
        a4,
        a2,
        v179,
        (unsigned int)v102);
      result = 0;
      goto LABEL_37;
    }
    v242 = (unsigned __int8)v166[10];
    v537 = (unsigned __int8)v166[13];
    v540 = (unsigned __int8)v166[17];
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: RX:[802.11 CH_LOAD] vdev: %d, is_rrm_reporting: %d, is_wide_bw_chan_switch: %d, is_bw_ind: %d",
      v170,
      v171,
      v172,
      v173,
      v174,
      v175,
      v176,
      v177,
      "rrm_process_channel_load_req",
      *(unsigned __int8 *)(v562 + 10),
      v166[10] != 0,
      v537 != 0,
      v540 != 0);
    v243 = v559 + 682 * v102;
    if ( v242 )
    {
      v244 = (unsigned __int8)v166[11];
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RX:[802.11 CH_LOAD] threshold:%d reporting_c:%d",
        v170,
        v171,
        v172,
        v173,
        v174,
        v175,
        v176,
        v177,
        "rrm_process_channel_load_req",
        (unsigned __int8)v166[12],
        (unsigned __int8)v166[11]);
      if ( v244 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: RX:[802.11 CH_LOAD]: Dropping req",
          v170,
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          "rrm_process_channel_load_req");
        v179 = 1;
LABEL_146:
        a4 = v562;
        goto LABEL_147;
      }
    }
    v533 = v559 + 682 * v102;
    if ( v540 )
    {
      v266 = (unsigned __int8)v166[20];
      v267 = (unsigned __int8)v166[21];
      v268 = v166[19] & 7;
      v269 = wlan_reg_compute_6g_center_freq_from_cfi(v166[20]);
      v535 = v266;
      BYTE4(v531) = v267;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RX:[802.11 CH_LOAD] chan_width:%d ccfs0:%d, ccfs1:%d, center_freq:%d",
        v270,
        v271,
        v272,
        v273,
        v274,
        v275,
        v276,
        v277,
        "rrm_process_channel_load_req",
        v268,
        v266,
        v267,
        v269);
      LODWORD(v531) = v269;
      if ( !v269 || !v266 || v268 != 7 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Dropping req: invalid is_bw_ind_element IE",
          v170,
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          "rrm_process_channel_load_req");
LABEL_145:
        v179 = 2;
        goto LABEL_146;
      }
      v243 = v559 + 682 * v102;
      v278 = 7;
      v530 = 1;
    }
    else
    {
      v530 = 0;
      v278 = 0;
      v535 = 0;
      v531 = 0;
    }
    a4 = v562;
    v285 = "rrm_process_channel_load_req";
    if ( v537 )
    {
      v286 = *(unsigned __int8 *)(v243 + 14);
      LOBYTE(v528) = *(_BYTE *)(v243 + 16);
      BYTE4(v528) = *(_BYTE *)(v243 + 15);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RX:[802.11 CH_LOAD] cw:%d ccf0:%d, ccf1:%d",
        v170,
        v171,
        v172,
        v173,
        v174,
        v175,
        v176,
        v177,
        "rrm_process_channel_load_req",
        *(unsigned __int8 *)(v243 + 14));
      v529 = v286;
      if ( v286 >= 7 )
      {
        v178 = "%s: Dropping req: invalid wide_bw IE";
        goto LABEL_76;
      }
      v318 = 1;
    }
    else
    {
      v318 = 0;
      v529 = 0;
      v528 = 0;
    }
    v319 = (*(_DWORD *)v548 >> 21) & 7;
    v320 = 4 - v319;
    v321 = v319 >= 4;
    v322 = v319 - 4;
    if ( !v321 )
      v322 = v320;
    v323 = 1LL << v322;
    if ( v321 )
      v324 = *(_WORD *)(v562 + 7158) * v323;
    else
      v324 = *(_WORD *)(v562 + 7158) / (unsigned __int16)v323;
    v325 = *(unsigned __int16 *)(v243 + 8);
    v326 = v324;
    v327 = *(unsigned __int8 *)(v243 + 5);
    v328 = *(unsigned __int16 *)(v243 + 6);
    if ( v324 >= v325 )
    {
      v324 = *(_WORD *)(v243 + 8);
    }
    else
    {
      v325 = v324;
      if ( (*(_BYTE *)(v243 + 2) & 0x10) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "RX:[802.11 CH_LOAD] Dropping the req: duration mandatory & max duration > meas duration",
          v170,
          v171,
          v172,
          v173,
          v174,
          v175,
          v176,
          v177,
          v285);
        goto LABEL_145;
      }
    }
    v329 = *(unsigned __int8 *)(v243 + 1);
    v525 = v318;
    v526 = v278;
    v330 = *(_BYTE *)(v243 + 4);
    LODWORD(v520) = v326;
    v331 = v327;
    v527 = v328;
    LODWORD(v519) = v328;
    LODWORD(v518) = v325;
    LODWORD(v517) = v327;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: RX:[802.11 CH_LOAD] vdev :%d, seq:%d Token:%d op_c:%d ch:%d meas_dur:%d, rand intv: %d, max_dur:%d",
      v170,
      v171,
      v172,
      v173,
      v174,
      v175,
      v176,
      v177,
      "rrm_process_channel_load_req",
      *(unsigned __int8 *)(v562 + 10),
      *(unsigned __int16 *)(v548 + 8),
      v329,
      v517,
      v518,
      v519,
      v520);
    if ( (unsigned __int16)(v324 - 111) < 0xFF92u )
      goto LABEL_145;
    v532 = v107;
    v553 = v102;
    if ( (wlan_reg_is_6ghz_supported(*(_QWORD *)(a1 + 21552), v332, v333, v334, v335, v336, v337, v338, v339) & 1) != 0
      || !wlan_reg_is_6ghz_op_class(*(_QWORD *)(a1 + 21560), v330) )
    {
      rrm_get_country_code_from_connected_profile(a1, *(_BYTE *)(v562 + 10), (unsigned __int8 *)&v569);
      v370 = wlan_reg_country_chan_opclass_to_freq(
               *(_QWORD *)(a1 + 21560),
               (unsigned __int8 *)&v569,
               v331,
               v330,
               0,
               v362,
               v363,
               v364,
               v365,
               v366,
               v367,
               v368,
               v369);
      if ( !v370 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Invalid ch freq for country code %c%c 0x%x",
          v371,
          v372,
          v373,
          v374,
          v375,
          v376,
          v377,
          v378,
          "rrm_process_channel_load_req",
          (unsigned __int8)v569,
          BYTE1(v569),
          BYTE2(v569));
LABEL_198:
        v179 = 1;
LABEL_199:
        a4 = v562;
        goto LABEL_147;
      }
      v379 = v370;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: freq:%d, country code %c%c 0x%x",
        v371,
        v372,
        v373,
        v374,
        v375,
        v376,
        v377,
        v378,
        "rrm_process_channel_load_req",
        v370,
        (unsigned __int8)v569,
        BYTE1(v569),
        BYTE2(v569));
      if ( (wlan_reg_is_freq_enabled(*(_QWORD *)(a1 + 21560), v379, v380, v381, v382, v383, v384, v385, v386, v387) & 1) != 0 )
      {
        v388 = _qdf_mem_malloc(0x2Cu, "rrm_process_channel_load_req", 2154);
        if ( v388 )
        {
          v389 = v388;
          qdf_mem_copy((void *)(v388 + 5), a2, 6u);
          *(_DWORD *)v389 = 2888751;
          v390 = *(unsigned __int8 *)(v533 + 1);
          *(_DWORD *)(v389 + 16) = 2;
          *(_WORD *)(v389 + 12) = v390;
          *(_WORD *)(v389 + 28) = (68719477 * (unsigned __int64)(unsigned int)(v527 << 10)) >> 36;
          v391 = *v544;
          *(_BYTE *)(v389 + 21) = v331;
          *(_DWORD *)(v389 + 24) = v379;
          *(_BYTE *)(v389 + 20) = v330;
          *(_BYTE *)(v389 + 4) = v391;
          *(_WORD *)(v389 + 30) = v324;
          v544[2] = *(_BYTE *)(v533 + 1);
          if ( v537 )
          {
            *(_BYTE *)(v389 + 40) = v525;
            *(_BYTE *)(v389 + 42) = BYTE4(v528);
            *(_BYTE *)(v389 + 41) = v529;
            *(_BYTE *)(v389 + 43) = v528;
          }
          if ( v540 )
          {
            *(_BYTE *)(v389 + 32) = v530;
            *(_BYTE *)(v389 + 33) = v526;
            *(_BYTE *)(v389 + 34) = v535;
            *(_BYTE *)(v389 + 35) = BYTE4(v531);
            *(_DWORD *)(v389 + 36) = v531;
          }
          a4 = v562;
          LOWORD(v575) = 5167;
          v392 = *(unsigned __int8 *)(v562 + 10);
          time_of_the_day_us = v389;
          qdf_trace(53, 6u, v392, 5167);
          v393 = &v575;
          goto LABEL_270;
        }
        v179 = 3;
        goto LABEL_199;
      }
      v348 = "%s: No channels populated with requested operation class and current country, Hence abort the rrm operation";
    }
    else
    {
      v348 = "%s: RX: [802.11 CH_LOAD] Ch belongs to 6 ghz spectrum, abort";
    }
    qdf_trace_msg(0x35u, 8u, v348, v340, v341, v342, v343, v344, v345, v346, v347, "rrm_process_channel_load_req");
    goto LABEL_198;
  }
  qdf_trace_msg(
    0x35u,
    4u,
    "%s: RX: [802.11 RRM] number of repetitions %d, sending incapable report",
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    "rrm_process_radio_measurement_request");
  v60 = *(_BYTE *)(a3 + 2);
  v61 = *(unsigned __int8 *)(a3 + 18);
  v62 = *(_WORD *)(a3 + 12);
  v63 = *(_BYTE *)(a3 + 11);
  v64 = *(_WORD *)(a3 + 16);
  v581 = 0;
  v579 = 0;
  v580 = 0;
  v577 = 0;
  v578 = 0;
  v575 = 0;
  time_of_the_day_us = 0;
  qdf_mem_set(&v575, 0x34u, 0);
  HIWORD(v575) = *(unsigned __int8 *)(*(_QWORD *)(a4 + 16) + 104LL);
  time_of_the_day_us = qdf_get_time_of_the_day_us();
  v69 = ktime_get(time_of_the_day_us, v65, v66, v67, v68);
  HIBYTE(v579) = v60;
  LOWORD(v580) = v61;
  *(_WORD *)((char *)&v579 + 3) = v62;
  WORD1(v580) = v64;
  LOWORD(v579) = 11011;
  BYTE5(v579) = v63;
  v578 = v69 / 1000;
  host_diag_event_report_payload(3384, 52, &v575);
  result = _qdf_mem_malloc(0x108u, "rrm_process_radio_measurement_request", 2535);
  if ( !result )
    goto LABEL_22;
  v35 = result;
  LOBYTE(v34) = 1;
  LODWORD(result) = 0;
  *(_BYTE *)(v35 + 2) = 1;
  *(_BYTE *)(v35 + 3) = *(_BYTE *)(a3 + 11);
LABEL_18:
  v70 = result;
  lim_send_radio_measure_report_action_frame(a1, *(_BYTE *)(a3 + 2), v34, 1, v35, a2, a4);
  _qdf_mem_free(v35);
  result = v70;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
