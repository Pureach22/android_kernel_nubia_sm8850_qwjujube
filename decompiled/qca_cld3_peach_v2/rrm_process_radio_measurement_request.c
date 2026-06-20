__int64 __fastcall rrm_process_radio_measurement_request(
        __int64 a1,
        unsigned __int8 *a2,
        __int64 a3,
        __int64 a4,
        _BYTE *a5,
        int a6,
        int *a7)
{
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  unsigned int v22; // w8
  __int64 v23; // x27
  __int64 v24; // x28
  __int64 v25; // x23
  char *v26; // x20
  _BYTE *v27; // x8
  char v28; // w9
  char v29; // w19
  __int64 v30; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x0
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 v48; // x23
  __int64 result; // x0
  unsigned int v50; // w19
  unsigned int v51; // w23
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
  unsigned int v68; // w8
  __int64 v69; // x10
  __int64 v70; // x19
  unsigned int v71; // w27
  int v72; // w9
  __int64 v73; // x20
  __int64 v74; // x14
  __int64 v75; // x15
  __int64 v76; // x16
  __int64 v77; // x17
  const char *v78; // x1
  int *v79; // x10
  _BYTE *v80; // x2
  __int64 v81; // x19
  __int64 v82; // x19
  int v83; // w11
  unsigned __int8 *v84; // x19
  int v85; // t1
  int v86; // w9
  int v87; // w8
  unsigned int v88; // w8
  _BYTE *v89; // x0
  _BYTE *v90; // x20
  __int64 v91; // x26
  char v92; // w8
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
  unsigned int v109; // w8
  char v110; // w9
  bool v111; // cf
  char v112; // w8
  __int64 v113; // x8
  unsigned __int16 v114; // w8
  __int64 v117; // x20
  __int64 v118; // x27
  double v119; // d0
  double v120; // d1
  double v121; // d2
  double v122; // d3
  double v123; // d4
  double v124; // d5
  double v125; // d6
  double v126; // d7
  char *v127; // x0
  double v128; // d0
  double v129; // d1
  double v130; // d2
  double v131; // d3
  double v132; // d4
  double v133; // d5
  double v134; // d6
  double v135; // d7
  char v136; // w8
  __int64 v137; // x5
  __int64 v138; // x0
  double v139; // d0
  double v140; // d1
  double v141; // d2
  double v142; // d3
  double v143; // d4
  double v144; // d5
  double v145; // d6
  double v146; // d7
  __int64 v147; // x3
  int v148; // w8
  const char *v149; // x27
  __int64 v150; // x0
  double v151; // d0
  double v152; // d1
  double v153; // d2
  double v154; // d3
  double v155; // d4
  double v156; // d5
  double v157; // d6
  double v158; // d7
  unsigned int v159; // w11
  __int64 v160; // x8
  _BYTE *v161; // x11
  unsigned int v162; // w26
  __int64 v163; // x0
  double v164; // d0
  double v165; // d1
  double v166; // d2
  double v167; // d3
  double v168; // d4
  double v169; // d5
  double v170; // d6
  double v171; // d7
  __int64 v172; // x27
  char v173; // w8
  __int64 v174; // x5
  double v175; // d0
  double v176; // d1
  double v177; // d2
  double v178; // d3
  double v179; // d4
  double v180; // d5
  double v181; // d6
  double v182; // d7
  double v183; // d0
  double v184; // d1
  double v185; // d2
  double v186; // d3
  double v187; // d4
  double v188; // d5
  double v189; // d6
  double v190; // d7
  double v191; // d0
  double v192; // d1
  double v193; // d2
  double v194; // d3
  double v195; // d4
  double v196; // d5
  double v197; // d6
  double v198; // d7
  double v199; // d0
  double v200; // d1
  double v201; // d2
  double v202; // d3
  double v203; // d4
  double v204; // d5
  double v205; // d6
  double v206; // d7
  unsigned int v207; // w27
  int v208; // w19
  double v209; // d0
  double v210; // d1
  double v211; // d2
  double v212; // d3
  double v213; // d4
  double v214; // d5
  double v215; // d6
  double v216; // d7
  int v217; // w26
  unsigned __int8 *v218; // x20
  _BYTE *v219; // x0
  double v220; // d0
  double v221; // d1
  double v222; // d2
  double v223; // d3
  double v224; // d4
  double v225; // d5
  double v226; // d6
  double v227; // d7
  unsigned __int8 v228; // w6
  _BYTE *v229; // x26
  double v230; // d0
  double v231; // d1
  double v232; // d2
  double v233; // d3
  double v234; // d4
  double v235; // d5
  double v236; // d6
  double v237; // d7
  _BYTE *v238; // x26
  unsigned int v239; // w27
  unsigned int v240; // w20
  unsigned int v241; // w0
  __int64 v242; // x5
  char v243; // w27
  unsigned int v244; // w26
  double v245; // d0
  double v246; // d1
  double v247; // d2
  double v248; // d3
  double v249; // d4
  double v250; // d5
  double v251; // d6
  double v252; // d7
  char v253; // w26
  unsigned int v254; // w8
  char v255; // w9
  bool v256; // cf
  char v257; // w8
  __int64 v258; // x8
  unsigned __int16 v259; // w8
  unsigned int v260; // w27
  __int64 v261; // x1
  unsigned int v262; // w19
  double v263; // d0
  double v264; // d1
  double v265; // d2
  double v266; // d3
  double v267; // d4
  double v268; // d5
  double v269; // d6
  double v270; // d7
  __int16 v271; // w8
  double v272; // d0
  double v273; // d1
  double v274; // d2
  double v275; // d3
  double v276; // d4
  double v277; // d5
  double v278; // d6
  double v279; // d7
  char v280; // w8
  unsigned int v281; // w8
  char v282; // w9
  bool v283; // cf
  char v284; // w8
  __int64 v285; // x8
  unsigned __int16 v286; // w26
  unsigned int v287; // w8
  int v288; // w9
  unsigned __int8 v289; // w20
  unsigned __int8 v290; // w27
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
  const char *v307; // x2
  double v308; // d0
  double v309; // d1
  double v310; // d2
  double v311; // d3
  double v312; // d4
  double v313; // d5
  double v314; // d6
  double v315; // d7
  void *v316; // x0
  size_t v317; // x2
  unsigned __int64 v318; // x19
  const char *v319; // x2
  double v320; // d0
  double v321; // d1
  double v322; // d2
  double v323; // d3
  double v324; // d4
  double v325; // d5
  double v326; // d6
  double v327; // d7
  unsigned int v328; // w0
  double v329; // d0
  double v330; // d1
  double v331; // d2
  double v332; // d3
  double v333; // d4
  double v334; // d5
  double v335; // d6
  double v336; // d7
  unsigned int v337; // w19
  double v338; // d0
  double v339; // d1
  double v340; // d2
  double v341; // d3
  double v342; // d4
  double v343; // d5
  double v344; // d6
  double v345; // d7
  __int16 v346; // w9
  char v347; // w8
  __int16 v348; // w2
  int v349; // w3
  const char *v350; // x2
  unsigned int v351; // w19
  char v353; // w9
  char v354; // w8
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
  size_t v371; // x2
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
  unsigned __int64 v396; // x19
  __int64 v397; // x0
  __int64 v398; // x20
  __int16 v399; // w8
  double v400; // d0
  double v401; // d1
  double v402; // d2
  double v403; // d3
  double v404; // d4
  double v405; // d5
  double v406; // d6
  double v407; // d7
  double v408; // d0
  double v409; // d1
  double v410; // d2
  double v411; // d3
  double v412; // d4
  double v413; // d5
  double v414; // d6
  double v415; // d7
  double v416; // d0
  double v417; // d1
  double v418; // d2
  double v419; // d3
  double v420; // d4
  double v421; // d5
  double v422; // d6
  double v423; // d7
  int v424; // w5
  unsigned __int8 v425; // w4
  int v426; // w0
  double v427; // d0
  double v428; // d1
  double v429; // d2
  double v430; // d3
  double v431; // d4
  double v432; // d5
  double v433; // d6
  double v434; // d7
  size_t v435; // x2
  __int64 v436; // x19
  unsigned __int64 v437; // x27
  unsigned __int64 v438; // x19
  unsigned __int64 v439; // x9
  unsigned __int64 v440; // x9
  unsigned __int8 v441; // w0
  double v442; // d0
  double v443; // d1
  double v444; // d2
  double v445; // d3
  double v446; // d4
  double v447; // d5
  double v448; // d6
  double v449; // d7
  int v450; // w3
  char *v451; // x26
  char v452; // w19
  unsigned __int8 v453; // w0
  unsigned __int8 v454; // w19
  char *v455; // x26
  unsigned __int8 v456; // w0
  unsigned __int8 v457; // w19
  char *v458; // x26
  unsigned __int8 v459; // w0
  unsigned __int8 v460; // w19
  char *v461; // x26
  unsigned __int8 v462; // w0
  unsigned __int8 v463; // w19
  char *v464; // x26
  unsigned __int8 v465; // w0
  unsigned __int8 v466; // w19
  char *v467; // x26
  unsigned __int8 v468; // w0
  __int64 v469; // [xsp+0h] [xbp-180h]
  __int64 v470; // [xsp+8h] [xbp-178h]
  __int64 v471; // [xsp+10h] [xbp-170h]
  __int64 v472; // [xsp+18h] [xbp-168h]
  __int64 v473; // [xsp+20h] [xbp-160h]
  __int64 v474; // [xsp+28h] [xbp-158h]
  __int64 v475; // [xsp+30h] [xbp-150h]
  __int64 v476; // [xsp+38h] [xbp-148h]
  __int64 v477; // [xsp+48h] [xbp-138h]
  int v478; // [xsp+54h] [xbp-12Ch]
  char v479; // [xsp+58h] [xbp-128h]
  char v480; // [xsp+5Ch] [xbp-124h]
  __int64 v481; // [xsp+60h] [xbp-120h]
  char v482; // [xsp+68h] [xbp-118h]
  char v483; // [xsp+6Ch] [xbp-114h]
  __int64 v484; // [xsp+70h] [xbp-110h]
  int v485; // [xsp+74h] [xbp-10Ch]
  unsigned int v486; // [xsp+78h] [xbp-108h]
  char v487; // [xsp+78h] [xbp-108h]
  __int64 v488; // [xsp+78h] [xbp-108h]
  int v489; // [xsp+80h] [xbp-100h]
  unsigned __int16 v490; // [xsp+80h] [xbp-100h]
  __int16 v491; // [xsp+80h] [xbp-100h]
  unsigned __int64 v492; // [xsp+80h] [xbp-100h]
  unsigned __int64 v493; // [xsp+80h] [xbp-100h]
  char *v494; // [xsp+88h] [xbp-F8h]
  _DWORD *v495; // [xsp+88h] [xbp-F8h]
  unsigned int v496; // [xsp+94h] [xbp-ECh]
  int v497; // [xsp+94h] [xbp-ECh]
  __int64 v498; // [xsp+98h] [xbp-E8h]
  __int64 v499; // [xsp+98h] [xbp-E8h]
  __int64 v500; // [xsp+A0h] [xbp-E0h]
  __int64 v501; // [xsp+A8h] [xbp-D8h]
  __int64 v502; // [xsp+B0h] [xbp-D0h]
  __int64 v503; // [xsp+B0h] [xbp-D0h]
  __int64 v504; // [xsp+B8h] [xbp-C8h]
  unsigned int v505; // [xsp+B8h] [xbp-C8h]
  __int64 v506; // [xsp+B8h] [xbp-C8h]
  __int64 v507; // [xsp+C0h] [xbp-C0h]
  __int64 v508; // [xsp+C0h] [xbp-C0h]
  __int64 v509; // [xsp+C8h] [xbp-B8h]
  __int64 v510; // [xsp+D0h] [xbp-B0h]
  __int64 v511; // [xsp+D8h] [xbp-A8h]
  __int64 v512; // [xsp+E0h] [xbp-A0h]
  __int64 v513; // [xsp+E8h] [xbp-98h]
  unsigned __int8 *v514; // [xsp+F0h] [xbp-90h]
  __int64 v516; // [xsp+100h] [xbp-80h]
  __int64 v517; // [xsp+108h] [xbp-78h] BYREF
  __int64 v518; // [xsp+110h] [xbp-70h]
  __int64 v519; // [xsp+118h] [xbp-68h]
  __int64 v520; // [xsp+120h] [xbp-60h]
  __int64 v521; // [xsp+128h] [xbp-58h]
  __int64 v522; // [xsp+130h] [xbp-50h]
  __int16 v523; // [xsp+13Ch] [xbp-44h] BYREF
  unsigned __int8 v524; // [xsp+13Eh] [xbp-42h]
  char s[8]; // [xsp+140h] [xbp-40h] BYREF
  __int64 v526; // [xsp+148h] [xbp-38h]
  __int64 v527; // [xsp+150h] [xbp-30h]
  __int64 v528; // [xsp+158h] [xbp-28h]
  _BYTE v529[13]; // [xsp+160h] [xbp-20h] BYREF
  __int64 v530; // [xsp+170h] [xbp-10h]

  v530 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_WORD *)(a3 + 6) )
  {
    v39 = _qdf_mem_malloc(0x108u, "rrm_process_radio_measurement_request", 2489);
    if ( !v39 )
      goto LABEL_22;
    v48 = v39;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: RX: [802.11 RRM] No requestIes in the measurement request, sending incapable report",
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      "rrm_process_radio_measurement_request");
    *(_BYTE *)(v48 + 2) = 1;
    lim_send_radio_measure_report_action_frame(a1, *(_BYTE *)(a3 + 2), 1u, 1, v48, a2, a4);
    _qdf_mem_free(v48);
    result = 16;
    goto LABEL_33;
  }
  if ( (unsigned int)wlan_vdev_is_up() )
  {
    v21 = jiffies;
    if ( rrm_process_radio_measurement_request___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x35u,
        4u,
        "%s: Vdev:%d is not up, reject RRM request",
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        "rrm_process_radio_measurement_request",
        *(unsigned __int8 *)(a4 + 10));
      rrm_process_radio_measurement_request___last_ticks = v21;
    }
    wlan_diag_log_beacon_rpt_req_event(
      *(unsigned __int8 *)(a3 + 2),
      *(unsigned __int8 *)(a3 + 18),
      *(unsigned __int8 *)(a3 + 12),
      *(unsigned __int8 *)(a3 + 13),
      *(unsigned __int8 *)(a3 + 11),
      *(unsigned __int16 *)(a3 + 16),
      a4);
    v22 = *(unsigned __int16 *)(a3 + 6);
    if ( *(_WORD *)(a3 + 6) )
      goto LABEL_6;
    goto LABEL_32;
  }
  if ( !*(_WORD *)(a3 + 4) )
  {
    if ( *(_QWORD *)(a1 + 20232) )
    {
      v51 = 0;
      goto LABEL_31;
    }
    if ( *(_QWORD *)(a1 + 20240) )
    {
      v51 = 1;
      goto LABEL_31;
    }
    if ( *(_QWORD *)(a1 + 20248) )
    {
      v51 = 2;
      goto LABEL_31;
    }
    if ( *(_QWORD *)(a1 + 20256) )
    {
      v51 = 3;
      goto LABEL_31;
    }
    if ( *(_QWORD *)(a1 + 20264) )
    {
      v51 = 4;
LABEL_31:
      wlan_diag_log_beacon_rpt_req_event(
        *(unsigned __int8 *)(a3 + 2),
        *(unsigned __int8 *)(a3 + 18),
        *(unsigned __int8 *)(a3 + 12),
        *(unsigned __int8 *)(a3 + 13),
        *(unsigned __int8 *)(a3 + 11),
        *(unsigned __int16 *)(a3 + 16),
        a4);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RRM req for index: %d is already in progress",
        v52,
        v53,
        v54,
        v55,
        v56,
        v57,
        v58,
        v59,
        "rrm_process_radio_measurement_request",
        v51);
      v22 = *(unsigned __int16 *)(a3 + 6);
      if ( *(_WORD *)(a3 + 6) )
      {
LABEL_6:
        v516 = a1;
        v23 = 0;
        v24 = 0;
        LODWORD(a1) = 0;
        v25 = 0;
        v26 = (char *)(a3 + 11);
        while ( 1 )
        {
          if ( v24 == -5 )
            goto LABEL_272;
          v29 = *v26;
          if ( !v25 )
          {
            v30 = _qdf_mem_malloc((int)(264 * (v24 + v22)), "rrm_reject_req", 2440);
            if ( !v30 )
            {
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Fail to Reject rrm req for index: %d",
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v38,
                "rrm_process_radio_measurement_request",
                (unsigned int)a1);
              goto LABEL_22;
            }
            v25 = v30;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: rrm beacon refused of %d report, index: %d in beacon table",
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              "rrm_reject_req",
              (unsigned int)a1,
              (unsigned int)a1);
          }
          v27 = (_BYTE *)(v25 + v23);
          LODWORD(a1) = a1 + 1;
          --v24;
          v27[1] = 1;
          v23 += 264;
          v27[3] = v29;
          v28 = *(v26 - 2);
          v26 += 682;
          *v27 = v28;
          v22 = *(unsigned __int16 *)(a3 + 6);
          if ( v22 <= (unsigned __int16)a1 )
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
    qdf_mem_set((void *)(a1 + 20272), 0xFFu, 0);
    *(_BYTE *)(a1 + 21292) = 0;
    v68 = *(unsigned __int16 *)(a3 + 6);
    v500 = a1 + 20220;
    if ( !*(_WORD *)(a3 + 6) )
      goto LABEL_32;
    v69 = a1;
    v70 = 0;
    v71 = 0;
    LODWORD(result) = 0;
    v501 = a1 + 20232;
    LOBYTE(a1) = 0;
    v509 = a3 + 8;
    v72 = a6;
    v25 = 0;
    v516 = v69;
    v73 = a3 + 66;
    v74 = a3 + 324;
    v75 = a3 + 585;
    v76 = a3 + 638;
    v77 = a3 + 691;
    v78 = "update_rrm_report";
    v79 = a7;
    v80 = a5;
    v513 = a4;
    v514 = a2;
    while ( 1 )
    {
      if ( v70 == 5 )
LABEL_272:
        __break(0x5512u);
      v511 = v74;
      v512 = v70;
      v82 = v509 + 682 * v70;
      v510 = v75;
      v85 = *(unsigned __int8 *)(v82 + 3);
      v84 = (unsigned __int8 *)(v82 + 3);
      v83 = v85;
      if ( v85 <= 7 )
        break;
      a4 = v513;
      a2 = v514;
      if ( v83 != 8 && v83 != 11 && v83 != 16 )
      {
LABEL_76:
        v81 = v512;
        if ( !v25 )
        {
          v503 = v77;
          v506 = v76;
          v148 = 33 * (v68 - v71);
          v149 = v78;
          v150 = _qdf_mem_malloc(8 * v148, v78, 2413);
          if ( !v150 )
          {
LABEL_22:
            result = 2;
            goto LABEL_33;
          }
          v25 = v150;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: rrm beacon type incapable of %d report",
            v151,
            v152,
            v153,
            v154,
            v155,
            v156,
            v157,
            v158,
            v149,
            (unsigned __int8)a1);
          v75 = v510;
          v74 = v511;
          v79 = a7;
          v77 = v503;
          v76 = v506;
          v80 = a5;
          v72 = a6;
          v78 = v149;
        }
        v159 = (unsigned __int8)a1;
        v160 = v509 + 682 * v512;
        result = 0;
        LOBYTE(a1) = a1 + 1;
        v161 = (_BYTE *)(v25 + 264LL * v159);
        v161[2] = 1;
        v161[3] = *(_BYTE *)(v160 + 3);
        *v161 = *(_BYTE *)(v160 + 1);
        goto LABEL_39;
      }
      v505 = result;
      v508 = v73;
      v117 = v76;
      v118 = v77;
      lim_send_sme_mgmt_frame_ind(v516, *v80 >> 4, (__int64)v80, v72 + 24, 0, *v79, v79[2], 0);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RRM with type: %d sent to userspace",
        v119,
        v120,
        v121,
        v122,
        v123,
        v124,
        v125,
        v126,
        "rrm_process_radio_measurement_request",
        *v84);
      v75 = v510;
      v74 = v511;
      v76 = v117;
      result = v505;
      v73 = v508;
      v78 = "update_rrm_report";
      v72 = a6;
      v81 = v512;
      v77 = v118;
      v80 = a5;
      v79 = a7;
LABEL_39:
      v68 = *(unsigned __int16 *)(a3 + 6);
      v70 = v81 + 1;
      v73 += 682;
      v74 += 682;
      v75 += 682;
      v76 += 682;
      v77 += 682;
      v71 = v70;
      if ( v68 <= (unsigned __int16)v70 )
      {
        if ( v25 )
          goto LABEL_18;
        goto LABEL_33;
      }
    }
    a4 = v513;
    if ( v83 != 3 )
    {
      a2 = v514;
      if ( v83 != 5 )
      {
        if ( v83 != 7 )
          goto LABEL_76;
        v86 = *(unsigned __int8 *)(a3 + 11);
        v87 = *(unsigned __int8 *)(a3 + 693);
        v502 = v77;
        v504 = v76;
        if ( v86 != 7 || v87 != 7 )
        {
          if ( v87 == 7 )
            v88 = (v86 == 7) + 1;
          else
            v88 = v86 == 7;
          if ( *(_BYTE *)(a3 + 1375) == 7 )
            ++v88;
          if ( v88 <= 1 )
          {
            if ( *(_BYTE *)(a3 + 2057) == 7 )
              LOBYTE(v88) = v88 + 1;
            if ( (unsigned __int8)v88 <= 1u )
            {
              if ( *(_BYTE *)(a3 + 2739) == 7 )
                LOBYTE(v88) = v88 + 1;
              if ( (unsigned __int8)v88 < 2u )
              {
                v507 = v73;
                v89 = (_BYTE *)_qdf_mem_malloc(0x130u, "rrm_process_sta_stats_req", 1092);
                if ( v89 )
                {
                  v90 = v89;
                  v91 = v509 + 682 * v512;
                  v89[1] = *(_BYTE *)(a3 + 2);
                  v92 = *(_BYTE *)(v91 + 1);
                  *v89 = v512;
                  v89[2] = v92;
                  v89[3] = *(_BYTE *)(v91 + 3);
                  qdf_mem_set((void *)(v500 + 1076), 0x118u, 0);
                  *(_BYTE *)(v500 + 1346) = v512;
                  *(_QWORD *)(v501 + 8 * v512) = v90;
                  ++*(_BYTE *)(v500 + 10);
                  qdf_mem_copy((void *)(v516 + 21560), v514, 6u);
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: Processing sta stats Report req %d num_active_req:%d",
                    v93,
                    v94,
                    v95,
                    v96,
                    v97,
                    v98,
                    v99,
                    v100,
                    "rrm_process_sta_stats_req",
                    v71,
                    *(unsigned __int8 *)(v500 + 10));
                  v109 = (*(_DWORD *)v500 >> 21) & 7;
                  v110 = 4 - v109;
                  v111 = v109 >= 4;
                  v112 = v109 - 4;
                  if ( !v111 )
                    v112 = v110;
                  v113 = 1LL << v112;
                  if ( v111 )
                    v114 = *(_WORD *)(v513 + 7158) * v113;
                  else
                    v114 = *(_WORD *)(v513 + 7158) / (unsigned __int16)v113;
                  if ( *(unsigned __int16 *)(v91 + 12) <= 0xAu )
                    v351 = 10;
                  else
                    v351 = *(unsigned __int16 *)(v91 + 12);
                  if ( v351 > v114 && (LOWORD(v351) = v114, (*(_BYTE *)(v91 + 2) & 0x10) != 0) )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "Dropping the req: duration mandatory & max duration > meas duration",
                      v101,
                      v102,
                      v103,
                      v104,
                      v105,
                      v106,
                      v107,
                      v108);
                  }
                  else if ( *(_DWORD *)(v91 + 4) == -1 && *(__int16 *)(v91 + 8) == -1 )
                  {
                    qdf_trace_msg(
                      0x35u,
                      2u,
                      "%s: Dropping req: broadcast address not supported",
                      v101,
                      v102,
                      v103,
                      v104,
                      v105,
                      v106,
                      v107,
                      v108,
                      "rrm_process_sta_stats_report_req");
                  }
                  else
                  {
                    *(_BYTE *)(v500 + 1076) = v90[2];
                    v353 = v90[3];
                    *(_WORD *)(v500 + 1077) = 0;
                    *(_BYTE *)(v500 + 1079) = v353;
                    v354 = *(_BYTE *)(v91 + 14);
                    *(_WORD *)(v500 + 1084) = v351;
                    *(_BYTE *)(v500 + 1086) = v354;
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: sta stats req vdev :%d, meas_dur:%d, max_dur:%d group id %d",
                      v101,
                      v102,
                      v103,
                      v104,
                      v105,
                      v106,
                      v107,
                      v108,
                      "rrm_process_sta_stats_report_req",
                      *(unsigned __int8 *)(v513 + 10),
                      (unsigned __int16)v351);
                    if ( *(unsigned __int8 *)(v91 + 14) > 1u )
                    {
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "group id %d not supported",
                        v355,
                        v356,
                        v357,
                        v358,
                        v359,
                        v360,
                        v361,
                        v362);
                    }
                    else if ( !(unsigned int)rrm_send_sta_stats_req(v516, v513, (const void *)(v91 + 4)) )
                    {
                      *(_BYTE *)(v516 + 3506) = *(_BYTE *)(v513 + 8);
                      tx_timer_change(v516 + 3456, (unsigned __int16)v351 / 0xAu, 0);
                      result = tx_timer_activate((char *)(v516 + 3456));
                      if ( !(_DWORD)result )
                      {
                        v72 = a6;
                        a4 = v513;
                        goto LABEL_267;
                      }
                      qdf_trace_msg(
                        0x35u,
                        2u,
                        "%s: failed to start sta stats timer",
                        v60,
                        v61,
                        v62,
                        v63,
                        v64,
                        v65,
                        v66,
                        v67,
                        "rrm_process_sta_stats_report_req");
                    }
                  }
                  a4 = v513;
                  a2 = v514;
                  v363 = ((double (__fastcall *)(__int64, __int64))rrm_process_rrm_sta_stats_request_failure)(
                           v516,
                           v513);
                  v81 = v512;
                  rrm_cleanup(v516, (unsigned int)v512, v363, v364, v365, v366, v367, v368, v369, v370);
                  v72 = a6;
                  result = 16;
                  v79 = a7;
                  v80 = a5;
LABEL_268:
                  v76 = v504;
                  v73 = v507;
                  v75 = v510;
                  v74 = v511;
                  v77 = v502;
                  v78 = "update_rrm_report";
                  goto LABEL_39;
                }
                v81 = v512;
                *(_QWORD *)(v501 + 8 * v512) = 0;
                qdf_mem_set((void *)(v500 + 1076), 0x118u, 0);
                v72 = a6;
                a4 = v513;
                result = 2;
                goto LABEL_114;
              }
            }
          }
        }
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: another sta stats request already in progress",
          v60,
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          "rrm_process_sta_stats_req");
        v72 = a6;
        v81 = v512;
        result = 16;
LABEL_37:
        v79 = a7;
        v80 = a5;
LABEL_38:
        v75 = v510;
        v74 = v511;
        v78 = "update_rrm_report";
        v77 = v502;
        v76 = v504;
        goto LABEL_39;
      }
      v162 = v71;
      v502 = v77;
      v504 = v76;
      v163 = _qdf_mem_malloc(0x130u, "rrm_process_beacon_req", 1989);
      if ( !v163 )
      {
LABEL_271:
        result = 2;
        *(_QWORD *)(v501 + 8LL * (unsigned __int8)v512) = 0;
        goto LABEL_33;
      }
      v172 = v163;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Processing Beacon Report request %d",
        v164,
        v165,
        v166,
        v167,
        v168,
        v169,
        v170,
        v171,
        "rrm_process_beacon_req",
        v162);
      v81 = v512;
      *(_BYTE *)(v172 + 1) = *(_BYTE *)(a3 + 2);
      v173 = *(_BYTE *)(v509 + 682 * v512 + 1);
      v499 = v509 + 682 * v512;
      *(_BYTE *)(v172 + 296) = 1;
      *(_BYTE *)(v172 + 2) = v173;
      *(_BYTE *)v172 = v512;
      *(_QWORD *)(v501 + 8 * v512) = v172;
      v174 = (unsigned __int8)++*(_BYTE *)(v500 + 10);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Processing Bcn Report req %d num_active_req:%d",
        v175,
        v176,
        v177,
        v178,
        v179,
        v180,
        v181,
        v182,
        "rrm_process_beacon_req",
        v162,
        v174);
      v521 = 0;
      v522 = 0;
      v519 = 0;
      v520 = 0;
      v517 = 0;
      v518 = 0;
      v528 = 0;
      memset(v529, 0, sizeof(v529));
      v526 = 0;
      v527 = 0;
      *(_QWORD *)s = 0;
      v524 = 0;
      v523 = 0;
      v507 = v73;
      v496 = v162;
      if ( !v513 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: pe_session is NULL",
          v183,
          v184,
          v185,
          v186,
          v187,
          v188,
          v189,
          v190,
          "rrm_process_beacon_report_req");
LABEL_88:
        v207 = 1;
        goto LABEL_89;
      }
      if ( (unsigned __int8)wlan_policy_mgr_get_ll_lt_sap_vdev_id(*(_QWORD *)(v516 + 21624)) != 0xFF )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: RX: [802.11 BCN_RPT] reject req as ll_lt_sap is present",
          v191,
          v192,
          v193,
          v194,
          v195,
          v196,
          v197,
          v198,
          "rrm_process_beacon_report_req");
        v207 = 2;
        goto LABEL_89;
      }
      v238 = (_BYTE *)(v509 + 682 * v512);
      if ( *(_BYTE *)(v499 + 51) && *(_BYTE *)(v499 + 52) )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "RX: [802.11 BCN_RPT] Dropping req: Reporting condition included is not zero",
          v191,
          v192,
          v193,
          v194,
          v195,
          v196,
          v197,
          v198);
        goto LABEL_88;
      }
      v254 = (*(_DWORD *)v500 >> 21) & 7;
      v255 = 4 - v254;
      v256 = v254 >= 4;
      v257 = v254 - 4;
      if ( !v256 )
        v257 = v255;
      v258 = 1LL << v257;
      if ( v256 )
        v259 = *(_WORD *)(v513 + 7158) * v258;
      else
        v259 = *(_WORD *)(v513 + 7158) / (unsigned __int16)v258;
      v261 = *(unsigned __int8 *)(v499 + 10);
      v262 = *(unsigned __int16 *)(v499 + 8);
      if ( !*(_BYTE *)(v499 + 10) )
        v259 += 10;
      v488 = jiffies;
      v490 = v259;
      if ( rrm_process_beacon_report_req___last_ticks - jiffies + 125 < 0 )
      {
        LODWORD(v474) = *(unsigned __int8 *)(v499 + 10);
        LODWORD(v476) = v259;
        LODWORD(v475) = *(unsigned __int16 *)(v499 + 8);
        LODWORD(v473) = *(unsigned __int8 *)(v499 + 5);
        LODWORD(v472) = *(unsigned __int8 *)(v499 + 4);
        LODWORD(v471) = *(unsigned __int8 *)(v499 + 1);
        LODWORD(v470) = *(unsigned __int8 *)(v499 + 16);
        LODWORD(v469) = *(unsigned __int8 *)(v499 + 13);
        qdf_trace_msg(
          0x35u,
          4u,
          "RX: [802.11 BCN_RPT] seq:%d SSID:%.*s BSSID:%02x:%02x:%02x:**:**:%02x Token:%d op_class:%d ch:%d meas_mode:%d "
          "meas_duration:%d max_meas_dur: %d",
          v191,
          v192,
          v193,
          v194,
          v195,
          v196,
          v197,
          v198,
          *(unsigned __int16 *)(v500 + 8),
          *(unsigned __int8 *)(v499 + 18),
          v499 + 19,
          *(unsigned __int8 *)(v499 + 11),
          *(unsigned __int8 *)(v499 + 12),
          v469,
          v470,
          v471,
          v472,
          v473,
          v474,
          v475,
          v476);
        rrm_process_beacon_report_req___last_ticks = v488;
        v261 = *(unsigned __int8 *)(v499 + 10);
      }
      wlan_diag_log_beacon_rpt_req_event(
        *(unsigned __int8 *)(v499 + 1),
        v261,
        *(unsigned __int8 *)(v499 + 4),
        *(unsigned __int8 *)(v499 + 5),
        *(_BYTE *)(v499 + 2) & 0x1F,
        v262,
        v513);
      if ( v262 || *(_BYTE *)(v499 + 10) == 2 )
      {
        v271 = v262;
        if ( v262 <= v490 )
          goto LABEL_130;
        if ( (*(_BYTE *)(v499 + 2) & 0x10) == 0 )
        {
          v271 = v490;
          v238 = (_BYTE *)(v509 + 682 * v512);
          v262 = v490;
LABEL_130:
          v491 = v271;
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: measurement duration %d",
            v263,
            v264,
            v265,
            v266,
            v267,
            v268,
            v269,
            v270,
            "rrm_process_beacon_report_req",
            v262);
          if ( v238[54] )
            v280 = v238[55];
          else
            v280 = 2;
          *(_BYTE *)(v172 + 8) = v280;
          if ( v238[680] )
          {
            *(_BYTE *)(v172 + 9) = v238[681];
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: RX: [802.11 BCN_RPT] Last Bcn Report in the req: %d",
              v272,
              v273,
              v274,
              v275,
              v276,
              v277,
              v278,
              v279,
              "rrm_process_beacon_report_req");
          }
          else
          {
            *(_BYTE *)(v172 + 9) = 0;
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: RX: [802.11 BCN_RPT] Last Bcn rpt ind not present",
              v272,
              v273,
              v274,
              v275,
              v276,
              v277,
              v278,
              v279,
              "rrm_process_beacon_report_req");
          }
          if ( !v238[56] )
            goto LABEL_160;
          if ( *(_BYTE *)(v499 + 57) )
          {
            v316 = (void *)_qdf_mem_malloc(*(unsigned __int8 *)(v499 + 57), "rrm_process_beacon_report_req", 1258);
            *(_QWORD *)(v172 + 24) = v316;
            if ( v316 )
            {
              v317 = *(unsigned __int8 *)(v499 + 57);
              *(_BYTE *)(v172 + 16) = v317;
              qdf_mem_copy(v316, (const void *)(v499 + 58), v317);
              if ( *(_BYTE *)(v172 + 16) )
              {
                v318 = 0;
                do
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: RX: [802.11 BCN_RPT]:Requested EID is %d",
                    v308,
                    v309,
                    v310,
                    v311,
                    v312,
                    v313,
                    v314,
                    v315,
                    "rrm_process_beacon_report_req",
                    *(unsigned __int8 *)(v73 + v318++));
                while ( v318 < *(unsigned __int8 *)(v172 + 16) );
              }
LABEL_160:
              if ( *(_BYTE *)(v499 + 313) )
              {
                if ( !*(_BYTE *)(v499 + 315) )
                {
                  v319 = "%s: RX: [802.11 BCN_RPT]: Requested num of Extn EID is 0";
                  goto LABEL_191;
                }
                if ( *(unsigned __int8 *)(v499 + 314) != 255 )
                {
                  v319 = "%s: RX: [802.11 BCN_RPT]: Extn Element ID is not 0xFF";
LABEL_191:
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    v319,
                    v308,
                    v309,
                    v310,
                    v311,
                    v312,
                    v313,
                    v314,
                    v315,
                    "rrm_process_beacon_report_req");
                  goto LABEL_253;
                }
                *(_BYTE *)(v172 + 32) = -1;
                v371 = *(unsigned __int8 *)(v499 + 315);
                *(_BYTE *)(v172 + 33) = v371;
                qdf_mem_copy((void *)(v172 + 34), (const void *)(v499 + 316), v371);
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: RX: [802.11 BCN_RPT]: EID is %d",
                  v372,
                  v373,
                  v374,
                  v375,
                  v376,
                  v377,
                  v378,
                  v379,
                  "rrm_process_beacon_report_req",
                  *(unsigned __int8 *)(v172 + 32));
                qdf_trace_msg(
                  0x35u,
                  8u,
                  "%s: RX: [802.11 BCN_RPT]:Num of Extn EID is %d",
                  v380,
                  v381,
                  v382,
                  v383,
                  v384,
                  v385,
                  v386,
                  v387,
                  "rrm_process_beacon_report_req",
                  *(unsigned __int8 *)(v172 + 33));
                if ( *(_BYTE *)(v172 + 33) )
                {
                  v396 = 0;
                  do
                    qdf_trace_msg(
                      0x35u,
                      8u,
                      "%s: RX: [802.11 BCN_RPT]:Requested Extn EID is %d",
                      v388,
                      v389,
                      v390,
                      v391,
                      v392,
                      v393,
                      v394,
                      v395,
                      "rrm_process_beacon_report_req",
                      *(unsigned __int8 *)(v511 + v396++));
                  while ( v396 < *(unsigned __int8 *)(v172 + 33) );
                }
              }
              v397 = _qdf_mem_malloc(0x84u, "rrm_process_beacon_report_req", 1302);
              if ( v397 )
              {
                v398 = v397;
                qdf_mem_copy((void *)(v397 + 5), (const void *)(v513 + 24), 6u);
                *(_DWORD *)v398 = 8655917;
                v399 = *(unsigned __int8 *)(v499 + 1);
                *(_DWORD *)(v398 + 128) = 2;
                *(_WORD *)(v398 + 88) = v399;
                *(_WORD *)(v398 + 28) = (68719477 * (unsigned __int64)(*(unsigned __int16 *)(v499 + 6) << 10)) >> 36;
                *(_BYTE *)(v398 + 4) = *(_BYTE *)v172;
                if ( (wlan_reg_is_6ghz_supported(
                        *(_QWORD *)(v516 + 21624),
                        v400,
                        v401,
                        v402,
                        v403,
                        v404,
                        v405,
                        v406,
                        v407)
                    & 1) != 0
                  || !wlan_reg_is_6ghz_op_class(*(_QWORD *)(v516 + 21632), *(_BYTE *)(v499 + 4)) )
                {
                  rrm_get_country_code_from_connected_profile(v516, *(_BYTE *)(v513 + 10), (unsigned __int8 *)&v523);
                  v424 = *(unsigned __int8 *)(v499 + 5);
                  *(_BYTE *)(v398 + 33) = v424;
                  v425 = *(_BYTE *)(v499 + 4);
                  *(_BYTE *)(v398 + 32) = v425;
                  if ( !v424 || v424 == 255 )
                  {
                    *(_DWORD *)(v398 + 36) = 0;
LABEL_211:
                    LODWORD(v471) = *(unsigned __int8 *)(v398 + 4);
                    LODWORD(v470) = v524;
                    LODWORD(v469) = HIBYTE(v523);
                    qdf_trace_msg(
                      0x34u,
                      8u,
                      "%s: opclass %d, ch %d freq %d AP's country code %c%c 0x%x index:%d",
                      v416,
                      v417,
                      v418,
                      v419,
                      v420,
                      v421,
                      v422,
                      v423,
                      "rrm_process_beacon_report_req",
                      v469,
                      v470,
                      v471);
                    *(_WORD *)(v398 + 12) = v491;
                    *(_BYTE *)(v398 + 46) = *(_BYTE *)(v499 + 10);
                    qdf_mem_copy((void *)(v398 + 40), (const void *)(v499 + 11), 6u);
                    if ( *(_BYTE *)(v499 + 17) )
                    {
                      v435 = *(unsigned __int8 *)(v499 + 18);
                      *(_BYTE *)(v398 + 54) = v435;
                      qdf_mem_copy((void *)(v398 + 55), (const void *)(v499 + 19), v435);
                    }
                    *(_BYTE *)(v172 + 2) = *(_BYTE *)(v499 + 1);
                    v485 = *(unsigned __int8 *)(v499 + 572);
                    if ( *(_BYTE *)(v499 + 572) )
                    {
                      v495 = (_DWORD *)(v398 + 96);
                      if ( *(_BYTE *)(v499 + 576) )
                      {
                        v436 = 0;
                        while ( 1 )
                        {
                          if ( (wlan_reg_is_6ghz_supported(
                                  *(_QWORD *)(v516 + 21624),
                                  v427,
                                  v428,
                                  v429,
                                  v430,
                                  v431,
                                  v432,
                                  v433,
                                  v434)
                              & 1) == 0
                            && wlan_reg_is_6ghz_op_class(*(_QWORD *)(v516 + 21632), *(_BYTE *)(v499 + 575)) )
                          {
                            goto LABEL_206;
                          }
                          v495[v436] = wlan_reg_country_chan_opclass_to_freq(
                                         *(_QWORD *)(v516 + 21632),
                                         (unsigned __int8 *)&v523,
                                         *(_BYTE *)(v510 + v436),
                                         *(_BYTE *)(v499 + 575),
                                         1,
                                         v408,
                                         v409,
                                         v410,
                                         v411,
                                         v412,
                                         v413,
                                         v414,
                                         v415);
                          if ( v436 == 7 )
                            break;
                          if ( ++v436 >= (unsigned __int64)*(unsigned __int8 *)(v499 + 576) )
                          {
                            v437 = (unsigned __int16)v436;
                            goto LABEL_226;
                          }
                        }
                        v437 = 8;
LABEL_256:
                        v450 = *(_DWORD *)(v398 + 96);
                        *(_BYTE *)(v398 + 92) = v437;
                        v441 = snprintf(s, 0x2Du, "%d ", v450);
LABEL_257:
                        v451 = &s[v441];
                        v452 = 45 - v441;
                        v453 = snprintf(v451, (unsigned __int8)(45 - v441), "%d ", *(_DWORD *)(v398 + 100));
                        if ( v437 != 2 )
                        {
                          v454 = v452 - v453;
                          v455 = &v451[v453];
                          v456 = snprintf(v455, v454, "%d ", *(_DWORD *)(v398 + 104));
                          if ( v437 != 3 )
                          {
                            v457 = v454 - v456;
                            v458 = &v455[v456];
                            v459 = snprintf(v458, v457, "%d ", *(_DWORD *)(v398 + 108));
                            if ( v437 != 4 )
                            {
                              v460 = v457 - v459;
                              v461 = &v458[v459];
                              v462 = snprintf(v461, v460, "%d ", *(_DWORD *)(v398 + 112));
                              if ( v437 != 5 )
                              {
                                v463 = v460 - v462;
                                v464 = &v461[v462];
                                v465 = snprintf(v464, v463, "%d ", *(_DWORD *)(v398 + 116));
                                if ( v437 != 6 )
                                {
                                  v466 = v463 - v465;
                                  v467 = &v464[v465];
                                  v468 = snprintf(v467, v466, "%d ", *(_DWORD *)(v398 + 120));
                                  if ( v437 != 7 )
                                  {
                                    snprintf(
                                      &v467[v468],
                                      (unsigned __int8)(v466 - v468),
                                      "%d ",
                                      *(_DWORD *)(v398 + 124));
                                    if ( v437 != 8 )
                                      goto LABEL_272;
                                  }
                                }
                              }
                            }
                          }
                        }
LABEL_264:
                        qdf_trace_msg(
                          0x35u,
                          4u,
                          "RX: [802.11 BCN_RPT] Ch-list:%s",
                          v442,
                          v443,
                          v444,
                          v445,
                          v446,
                          v447,
                          v448,
                          v449,
                          s);
                      }
                      else
                      {
                        v437 = 0;
LABEL_226:
                        if ( v485 != 1 )
                        {
                          if ( *(_BYTE *)(v499 + 629) )
                          {
                            v438 = 0;
                            v439 = 7 - v437;
                            if ( v437 > 7 )
                              v439 = 0;
                            v492 = v439;
                            while ( 1 )
                            {
                              if ( (wlan_reg_is_6ghz_supported(
                                      *(_QWORD *)(v516 + 21624),
                                      v427,
                                      v428,
                                      v429,
                                      v430,
                                      v431,
                                      v432,
                                      v433,
                                      v434)
                                  & 1) == 0
                                && wlan_reg_is_6ghz_op_class(*(_QWORD *)(v516 + 21632), *(_BYTE *)(v499 + 628)) )
                              {
                                goto LABEL_206;
                              }
                              *(_DWORD *)(v398 + 4 * v437 + 96 + 4 * v438) = wlan_reg_country_chan_opclass_to_freq(
                                                                               *(_QWORD *)(v516 + 21632),
                                                                               (unsigned __int8 *)&v523,
                                                                               *(_BYTE *)(v504 + v438),
                                                                               *(_BYTE *)(v499 + 628),
                                                                               1,
                                                                               v408,
                                                                               v409,
                                                                               v410,
                                                                               v411,
                                                                               v412,
                                                                               v413,
                                                                               v414,
                                                                               v415);
                              if ( v492 == v438 )
                                break;
                              if ( ++v438 >= *(unsigned __int8 *)(v499 + 629) )
                              {
                                v437 = (unsigned __int16)(v437 + v438);
                                goto LABEL_236;
                              }
                            }
LABEL_255:
                            v437 = (unsigned __int16)(v437 + v438 + 1);
                            goto LABEL_256;
                          }
LABEL_236:
                          if ( v485 != 2 )
                          {
                            if ( *(_BYTE *)(v499 + 682) )
                            {
                              v438 = 0;
                              v440 = 7 - v437;
                              if ( v437 > 7 )
                                v440 = 0;
                              v493 = v440;
                              do
                              {
                                if ( (wlan_reg_is_6ghz_supported(
                                        *(_QWORD *)(v516 + 21624),
                                        v427,
                                        v428,
                                        v429,
                                        v430,
                                        v431,
                                        v432,
                                        v433,
                                        v434)
                                    & 1) == 0
                                  && wlan_reg_is_6ghz_op_class(*(_QWORD *)(v516 + 21632), *(_BYTE *)(v499 + 681)) )
                                {
                                  goto LABEL_206;
                                }
                                *(_DWORD *)(v398 + 4 * v437 + 96 + 4 * v438) = wlan_reg_country_chan_opclass_to_freq(
                                                                                 *(_QWORD *)(v516 + 21632),
                                                                                 (unsigned __int8 *)&v523,
                                                                                 *(_BYTE *)(v502 + v438),
                                                                                 *(_BYTE *)(v499 + 681),
                                                                                 1,
                                                                                 v408,
                                                                                 v409,
                                                                                 v410,
                                                                                 v411,
                                                                                 v412,
                                                                                 v413,
                                                                                 v414,
                                                                                 v415);
                                if ( v493 == v438 )
                                  goto LABEL_255;
                                ++v438;
                              }
                              while ( v438 < *(unsigned __int8 *)(v499 + 682) );
                              v437 = (unsigned __int16)(v437 + v438);
                            }
                            if ( v485 != 3 )
                              goto LABEL_272;
                          }
                        }
                        *(_BYTE *)(v398 + 92) = v437;
                        if ( v437 )
                        {
                          v441 = snprintf(s, 0x2Du, "%d ", *v495);
                          if ( v437 != 1 )
                            goto LABEL_257;
                          goto LABEL_264;
                        }
                      }
                    }
                    else
                    {
                      *(_BYTE *)(v398 + 92) = 0;
                    }
                    a4 = v513;
                    v349 = 5165;
                    LOWORD(v517) = 5165;
                    v348 = *(_WORD *)(v513 + 8);
                    v518 = v398;
LABEL_266:
                    qdf_trace(53, 6u, v348, v349);
                    sys_process_mmh_msg(v516, &v517);
                    v72 = a6;
                    result = 0;
LABEL_267:
                    v79 = a7;
                    v80 = a5;
                    a2 = v514;
                    v81 = v512;
                    goto LABEL_268;
                  }
                  v426 = wlan_reg_country_chan_opclass_to_freq(
                           *(_QWORD *)(v516 + 21632),
                           (unsigned __int8 *)&v523,
                           v424,
                           v425,
                           0,
                           v416,
                           v417,
                           v418,
                           v419,
                           v420,
                           v421,
                           v422,
                           v423);
                  *(_DWORD *)(v398 + 36) = v426;
                  if ( v426 )
                    goto LABEL_211;
                  qdf_trace_msg(
                    0x35u,
                    8u,
                    "%s: invalid ch freq, chan_num %d",
                    v416,
                    v417,
                    v418,
                    v419,
                    v420,
                    v421,
                    v422,
                    v423,
                    "rrm_process_beacon_report_req",
                    *(unsigned __int8 *)(v398 + 33));
                }
                else
                {
LABEL_206:
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "RX: [802.11 BCN_RPT] Ch belongs to 6 ghz spectrum, abort",
                    v408,
                    v409,
                    v410,
                    v411,
                    v412,
                    v413,
                    v414,
                    v415);
                }
                _qdf_mem_free(v398);
              }
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              8u,
              "%s: RX: [802.11 BCN_RPT]: Requested num of EID is 0",
              v308,
              v309,
              v310,
              v311,
              v312,
              v313,
              v314,
              v315,
              "rrm_process_beacon_report_req");
          }
LABEL_253:
          v81 = v512;
          a4 = v513;
          v207 = 3;
LABEL_89:
          v218 = *(unsigned __int8 **)(v501 + 8 * v81);
          if ( v218 )
          {
            v219 = (_BYTE *)_qdf_mem_malloc(0x108u, "rrm_process_beacon_request_failure", 1920);
            if ( v219 )
            {
              v228 = v218[2];
              v229 = v219;
              v219[3] = 5;
              *v219 = v228;
              qdf_trace_msg(
                0x35u,
                8u,
                "%s: Measurement index:%d status %d token %d",
                v220,
                v221,
                v222,
                v223,
                v224,
                v225,
                v226,
                v227,
                "rrm_process_beacon_request_failure",
                v496,
                v207);
              if ( v207 == 1 )
              {
                v229[2] = 1;
              }
              else
              {
                if ( v207 != 2 )
                {
                  qdf_trace_msg(
                    0x35u,
                    2u,
                    "%s: RX [802.11 BCN_RPT] Beacon request processing failed no report sent",
                    v230,
                    v231,
                    v232,
                    v233,
                    v234,
                    v235,
                    v236,
                    v237,
                    "rrm_process_beacon_request_failure");
LABEL_112:
                  _qdf_mem_free((__int64)v229);
                  goto LABEL_113;
                }
                v229[1] = 1;
              }
              if ( v218[9] )
                v229[37] = 1;
              lim_send_radio_measure_report_action_frame(v516, v218[1], 1u, 1, (__int64)v229, v514, a4);
              goto LABEL_112;
            }
          }
          else
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Current request is NULL",
              v199,
              v200,
              v201,
              v202,
              v203,
              v204,
              v205,
              v206,
              "rrm_process_beacon_request_failure");
          }
LABEL_113:
          rrm_cleanup(v516, (unsigned int)v81, v220, v221, v222, v223, v224, v225, v226, v227);
          v72 = a6;
          result = 0;
LABEL_114:
          v79 = a7;
          v80 = a5;
          a2 = v514;
          v73 = v507;
          goto LABEL_38;
        }
        v350 = "RX: [802.11 BCN_RPT] Dropping the req: duration mandatory & maxduration > measduration";
      }
      else
      {
        v350 = "RX: [802.11 BCN_RPT] Invalid measurement duration";
      }
      v207 = 2;
      qdf_trace_msg(0x35u, 2u, v350, v263, v264, v265, v266, v267, v268, v269, v270);
      v81 = v512;
      goto LABEL_89;
    }
    v502 = v77;
    v504 = v76;
    v507 = v73;
    v127 = (char *)_qdf_mem_malloc(0x130u, "rrm_process_chan_load_req", 2363);
    a2 = v514;
    if ( !v127 )
      goto LABEL_271;
    v81 = v512;
    v494 = v127;
    v127[1] = *(_BYTE *)(a3 + 2);
    v136 = *(_BYTE *)(v509 + 682 * v512 + 1);
    v498 = v509 + 682 * v512;
    *v127 = v512;
    v127[2] = v136;
    *(_QWORD *)(v501 + 8 * v512) = v127;
    v137 = (unsigned __int8)++*(_BYTE *)(v500 + 10);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Processing channel load req index: %d num_active_req:%d",
      v128,
      v129,
      v130,
      v131,
      v132,
      v133,
      v134,
      v135,
      "rrm_process_chan_load_req",
      v71,
      v137);
    v521 = 0;
    v522 = 0;
    v519 = 0;
    v520 = 0;
    v138 = *(_QWORD *)(v516 + 21624);
    v517 = 0;
    v518 = 0;
    s[2] = 0;
    *(_WORD *)s = 0;
    if ( (unsigned __int8)wlan_policy_mgr_get_ll_lt_sap_vdev_id(v138) != 0xFF )
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RX:[802.11 CH_LOAD] reject req as ll_lt_sap is present",
        v139,
        v140,
        v141,
        v142,
        v143,
        v144,
        v145,
        v146,
        "rrm_process_channel_load_req");
      v147 = 2;
LABEL_146:
      v73 = v507;
      ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, __int64, _QWORD))rrm_process_chan_load_request_failure)(
        v516,
        a4,
        a2,
        v147,
        (unsigned int)v81);
      v72 = a6;
      result = 0;
      goto LABEL_37;
    }
    v208 = *(unsigned __int8 *)(v498 + 10);
    v489 = *(unsigned __int8 *)(v498 + 13);
    v497 = *(unsigned __int8 *)(v498 + 17);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: RX:[802.11 CH_LOAD] vdev: %d, is_rrm_reporting: %d, is_wide_bw_chan_switch: %d, is_bw_ind: %d",
      v139,
      v140,
      v141,
      v142,
      v143,
      v144,
      v145,
      v146,
      "rrm_process_channel_load_req",
      *(unsigned __int8 *)(v513 + 10),
      v208 != 0,
      v489 != 0,
      v497 != 0);
    if ( v208 )
    {
      v217 = *(unsigned __int8 *)(v498 + 11);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RX:[802.11 CH_LOAD] threshold:%d reporting_c:%d",
        v209,
        v210,
        v211,
        v212,
        v213,
        v214,
        v215,
        v216,
        "rrm_process_channel_load_req",
        *(unsigned __int8 *)(v498 + 12),
        *(unsigned __int8 *)(v498 + 11));
      if ( v217 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: RX:[802.11 CH_LOAD]: Dropping req",
          v209,
          v210,
          v211,
          v212,
          v213,
          v214,
          v215,
          v216,
          "rrm_process_channel_load_req");
        v147 = 1;
LABEL_145:
        a2 = v514;
        v81 = v512;
        goto LABEL_146;
      }
    }
    if ( v497 )
    {
      v239 = *(unsigned __int8 *)(v498 + 20);
      v486 = *(unsigned __int8 *)(v498 + 21);
      v240 = *(_BYTE *)(v498 + 19) & 7;
      v241 = wlan_reg_compute_6g_center_freq_from_cfi(*(_BYTE *)(v498 + 20));
      HIDWORD(v484) = v239;
      v242 = v239;
      v243 = v486;
      v244 = v241;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RX:[802.11 CH_LOAD] chan_width:%d ccfs0:%d, ccfs1:%d, center_freq:%d",
        v245,
        v246,
        v247,
        v248,
        v249,
        v250,
        v251,
        v252,
        "rrm_process_channel_load_req",
        v240,
        v242,
        v486,
        v241);
      LODWORD(v484) = v244;
      if ( !v244 || !HIDWORD(v484) || v240 != 7 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Dropping req: invalid is_bw_ind_element IE",
          v209,
          v210,
          v211,
          v212,
          v213,
          v214,
          v215,
          v216,
          "rrm_process_channel_load_req");
        goto LABEL_144;
      }
      v253 = 7;
      v483 = 1;
    }
    else
    {
      v483 = 0;
      v253 = 0;
      v243 = 0;
      v484 = 0;
    }
    v487 = v243;
    if ( v489 )
    {
      v260 = *(unsigned __int8 *)(v498 + 14);
      LOBYTE(v481) = *(_BYTE *)(v498 + 16);
      BYTE4(v481) = *(_BYTE *)(v498 + 15);
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: RX:[802.11 CH_LOAD] cw:%d ccf0:%d, ccf1:%d",
        v209,
        v210,
        v211,
        v212,
        v213,
        v214,
        v215,
        v216,
        "rrm_process_channel_load_req",
        *(unsigned __int8 *)(v498 + 14));
      v482 = v260;
      if ( v260 >= 7 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Dropping req: invalid wide_bw IE",
          v209,
          v210,
          v211,
          v212,
          v213,
          v214,
          v215,
          v216,
          "rrm_process_channel_load_req");
LABEL_144:
        v147 = 2;
        goto LABEL_145;
      }
      v480 = 1;
    }
    else
    {
      v480 = 0;
      v482 = 0;
      v481 = 0;
    }
    v479 = v253;
    v281 = (*(_DWORD *)v500 >> 21) & 7;
    v282 = 4 - v281;
    v283 = v281 >= 4;
    v284 = v281 - 4;
    if ( !v283 )
      v284 = v282;
    v285 = 1LL << v284;
    if ( v283 )
      v286 = *(_WORD *)(v513 + 7158) * v285;
    else
      v286 = *(_WORD *)(v513 + 7158) / (unsigned __int16)v285;
    v287 = *(unsigned __int16 *)(v498 + 8);
    v288 = v286;
    if ( v286 >= v287 )
    {
      v286 = *(_WORD *)(v498 + 8);
    }
    else
    {
      v287 = v286;
      if ( (*(_BYTE *)(v498 + 2) & 0x10) != 0 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "RX:[802.11 CH_LOAD] Dropping the req: duration mandatory & max duration > meas duration",
          v209,
          v210,
          v211,
          v212,
          v213,
          v214,
          v215,
          v216);
        goto LABEL_144;
      }
    }
    LODWORD(v472) = v288;
    v289 = *(_BYTE *)(v498 + 4);
    v290 = *(_BYTE *)(v498 + 5);
    v478 = *(unsigned __int16 *)(v498 + 6);
    LODWORD(v471) = v478;
    LODWORD(v470) = v287;
    LODWORD(v469) = v290;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: RX:[802.11 CH_LOAD] vdev :%d, seq:%d Token:%d op_c:%d ch:%d meas_dur:%d, rand intv: %d, max_dur:%d",
      v209,
      v210,
      v211,
      v212,
      v213,
      v214,
      v215,
      v216,
      "rrm_process_channel_load_req",
      *(unsigned __int8 *)(v513 + 10),
      *(unsigned __int16 *)(v500 + 8),
      *(unsigned __int8 *)(v498 + 1),
      v469,
      v470,
      v471,
      v472);
    if ( (unsigned __int16)(v286 - 111) < 0xFF92u )
      goto LABEL_144;
    if ( (wlan_reg_is_6ghz_supported(*(_QWORD *)(v516 + 21624), v291, v292, v293, v294, v295, v296, v297, v298) & 1) != 0
      || !wlan_reg_is_6ghz_op_class(*(_QWORD *)(v516 + 21632), v289) )
    {
      rrm_get_country_code_from_connected_profile(v516, *(_BYTE *)(v513 + 10), (unsigned __int8 *)s);
      v328 = wlan_reg_country_chan_opclass_to_freq(
               *(_QWORD *)(v516 + 21632),
               (unsigned __int8 *)s,
               v290,
               v289,
               0,
               v320,
               v321,
               v322,
               v323,
               v324,
               v325,
               v326,
               v327);
      if ( !v328 )
      {
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: Invalid ch freq for country code %c%c 0x%x",
          v329,
          v330,
          v331,
          v332,
          v333,
          v334,
          v335,
          v336,
          "rrm_process_channel_load_req",
          (unsigned __int8)s[0],
          (unsigned __int8)s[1],
          (unsigned __int8)s[2]);
LABEL_197:
        a4 = v513;
        v147 = 1;
        goto LABEL_145;
      }
      v337 = v328;
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: freq:%d, country code %c%c 0x%x",
        v329,
        v330,
        v331,
        v332,
        v333,
        v334,
        v335,
        v336,
        "rrm_process_channel_load_req",
        v328,
        (unsigned __int8)s[0],
        (unsigned __int8)s[1],
        (unsigned __int8)s[2]);
      if ( (wlan_reg_is_freq_enabled(*(_QWORD *)(v516 + 21632), v337, v338, v339, v340, v341, v342, v343, v344, v345) & 1) != 0 )
      {
        v477 = _qdf_mem_malloc(0x2Cu, "rrm_process_channel_load_req", 2154);
        if ( v477 )
        {
          qdf_mem_copy((void *)(v477 + 5), v514, 6u);
          *(_DWORD *)v477 = 2888751;
          v346 = *(unsigned __int8 *)(v498 + 1);
          *(_DWORD *)(v477 + 16) = 2;
          *(_WORD *)(v477 + 12) = v346;
          *(_WORD *)(v477 + 28) = (68719477 * (unsigned __int64)(unsigned int)(v478 << 10)) >> 36;
          v347 = *v494;
          *(_BYTE *)(v477 + 21) = v290;
          *(_DWORD *)(v477 + 24) = v337;
          *(_BYTE *)(v477 + 20) = v289;
          *(_BYTE *)(v477 + 4) = v347;
          *(_WORD *)(v477 + 30) = v286;
          v494[2] = *(_BYTE *)(v498 + 1);
          if ( v489 )
          {
            *(_BYTE *)(v477 + 40) = v480;
            *(_BYTE *)(v477 + 42) = BYTE4(v481);
            *(_BYTE *)(v477 + 41) = v482;
            *(_BYTE *)(v477 + 43) = v481;
          }
          if ( v497 )
          {
            *(_BYTE *)(v477 + 32) = v483;
            *(_BYTE *)(v477 + 33) = v479;
            *(_BYTE *)(v477 + 35) = v487;
            *(_BYTE *)(v477 + 34) = BYTE4(v484);
            *(_DWORD *)(v477 + 36) = v484;
          }
          a4 = v513;
          LOWORD(v517) = 5167;
          v348 = *(unsigned __int8 *)(v513 + 10);
          v349 = 5167;
          v518 = v477;
          goto LABEL_266;
        }
        a4 = v513;
        v147 = 3;
        goto LABEL_145;
      }
      v307 = "%s: No channels populated with requested operation class and current country, Hence abort the rrm operation";
    }
    else
    {
      v307 = "%s: RX: [802.11 CH_LOAD] Ch belongs to 6 ghz spectrum, abort";
    }
    qdf_trace_msg(0x35u, 8u, v307, v299, v300, v301, v302, v303, v304, v305, v306, "rrm_process_channel_load_req");
    goto LABEL_197;
  }
  qdf_trace_msg(
    0x35u,
    4u,
    "%s: RX: [802.11 RRM] number of repetitions %d, sending incapable report",
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    "rrm_process_radio_measurement_request");
  wlan_diag_log_beacon_rpt_req_event(
    *(unsigned __int8 *)(a3 + 2),
    *(unsigned __int8 *)(a3 + 18),
    *(unsigned __int8 *)(a3 + 12),
    *(unsigned __int8 *)(a3 + 13),
    *(unsigned __int8 *)(a3 + 11),
    *(unsigned __int16 *)(a3 + 16),
    a4);
  result = _qdf_mem_malloc(0x108u, "rrm_process_radio_measurement_request", 2535);
  if ( !result )
    goto LABEL_22;
  v25 = result;
  v516 = a1;
  LOBYTE(a1) = 1;
  *(_BYTE *)(result + 2) = 1;
  LODWORD(result) = 0;
  *(_BYTE *)(v25 + 3) = *(_BYTE *)(a3 + 11);
LABEL_18:
  v50 = result;
  lim_send_radio_measure_report_action_frame(v516, *(_BYTE *)(a3 + 2), a1, 1, v25, a2, a4);
  _qdf_mem_free(v25);
  result = v50;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}
