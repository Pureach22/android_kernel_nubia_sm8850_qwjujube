__int64 __fastcall wlan_cm_calculate_bss_score(
        __int64 a1,
        unsigned int *a2,
        _QWORD *a3,
        __int64 a4,
        unsigned __int8 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v13; // x25
  _QWORD *v14; // x20
  __int64 v15; // x23
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int v26; // w8
  _BYTE *v27; // x19
  const char *v28; // x2
  _QWORD *v29; // x1
  __int64 v30; // x26
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  _QWORD *v47; // x27
  __int64 v48; // x1
  int v49; // w8
  __int64 v51; // x9
  unsigned int v52; // w10
  unsigned int v53; // w10
  _BYTE *v54; // x9
  __int64 v55; // x11
  unsigned int v56; // w10
  _BOOL4 v57; // w10
  int v58; // w28
  char v59; // w21
  __int64 v60; // x25
  _BOOL4 v61; // w26
  __int64 v62; // x3
  __int64 v63; // x4
  __int64 v64; // x5
  __int64 v65; // x6
  int v66; // w9
  int v67; // w23
  unsigned __int64 v68; // x8
  __int64 v69; // x10
  int v70; // w4
  __int64 v71; // x9
  bool v72; // w10
  double v73; // d0
  double v74; // d1
  double v75; // d2
  double v76; // d3
  double v77; // d4
  double v78; // d5
  double v79; // d6
  double v80; // d7
  _BOOL4 v81; // w12
  __int64 v82; // x8
  __int64 v83; // x3
  __int64 v84; // x4
  __int64 v85; // x5
  __int64 v86; // x6
  __int64 v87; // x24
  __int64 cmpt_obj; // x0
  __int64 v89; // x19
  int v90; // w15
  int v91; // w12
  int v92; // w11
  int v93; // w13
  unsigned int v94; // w8
  unsigned int v95; // w10
  int v96; // w14
  unsigned int v97; // w9
  unsigned int v98; // w17
  unsigned int v99; // w15
  __int16 v100; // w8
  unsigned int v101; // w23
  unsigned int v102; // w21
  unsigned int v103; // w26
  unsigned int v104; // w8
  unsigned int v105; // w21
  char v106; // w0
  double v107; // d0
  double v108; // d1
  double v109; // d2
  double v110; // d3
  double v111; // d4
  double v112; // d5
  double v113; // d6
  double v114; // d7
  unsigned int v115; // w9
  int v116; // w8
  _BOOL4 v117; // w10
  unsigned __int64 v118; // x15
  unsigned int v119; // w11
  int v120; // w11
  int v121; // w26
  int v122; // w9
  int v123; // w13
  __int64 v124; // x8
  unsigned int v125; // w23
  int v126; // w21
  int v127; // w9
  int v128; // w9
  unsigned int v129; // w23
  int v130; // w21
  int v131; // w14
  __int64 v132; // x12
  int v133; // w11
  unsigned int v134; // w23
  unsigned int v135; // w17
  unsigned int v136; // w16
  char v137; // w15
  char v138; // w12
  char v139; // w16
  bool v140; // cc
  unsigned int v141; // w8
  unsigned int v142; // w10
  __int64 v143; // x26
  __int64 v144; // x20
  __int64 v145; // x22
  int v146; // w23
  int v147; // w21
  int v148; // w8
  __int64 v149; // x13
  int v150; // w9
  int v151; // w21
  char is_24ghz_ch_freq; // w0
  unsigned int v153; // w8
  int v154; // w8
  unsigned int v155; // w8
  char v156; // w9
  int v157; // w10
  int v158; // w11
  int v159; // w9
  unsigned int v160; // w8
  int v161; // w13
  int v162; // w8
  int v163; // w9
  unsigned int v164; // w10
  unsigned int v165; // w9
  int v166; // w11
  char v167; // w10
  unsigned int v168; // w10
  unsigned int v169; // w10
  unsigned int v170; // w9
  unsigned int v171; // w9
  unsigned int v172; // w8
  unsigned int v173; // w9
  int v174; // w9
  bool v175; // zf
  int v176; // w8
  int v177; // w8
  unsigned int v178; // w8
  unsigned int v179; // w22
  unsigned int v180; // w9
  unsigned int v181; // w8
  unsigned int v182; // w14
  unsigned int v183; // w21
  int v184; // w8
  unsigned int v185; // w26
  int v186; // w11
  int v187; // w12
  unsigned int v188; // w8
  int max_amsdu_num; // w0
  bool v190; // zf
  unsigned int v191; // w9
  unsigned int v192; // w26
  unsigned int v193; // w8
  unsigned int v194; // w9
  double v195; // d0
  double v196; // d1
  double v197; // d2
  double v198; // d3
  double v199; // d4
  double v200; // d5
  double v201; // d6
  double v202; // d7
  __int64 v204; // x4
  __int64 v205; // x5
  __int64 v206; // x6
  __int64 v207; // x7
  int v208; // w9
  int v209; // w10
  unsigned int v210; // w21
  double v211; // d0
  double v212; // d1
  double v213; // d2
  double v214; // d3
  double v215; // d4
  double v216; // d5
  double v217; // d6
  double v218; // d7
  char v219; // w8
  int v221; // w21
  char is_hw_dbs_capable; // w0
  unsigned __int8 v223; // w10
  int v224; // w9
  int v225; // w21
  char is_6ghz_chan_freq; // w0
  char v227; // w0
  double v228; // d0
  double v229; // d1
  double v230; // d2
  double v231; // d3
  double v232; // d4
  double v233; // d5
  double v234; // d6
  double v235; // d7
  __int16 v236; // w8
  int v237; // w15
  int v238; // w16
  int v239; // w8
  __int16 v240; // w9
  char v241; // w0
  int v242; // w17
  __int64 v243; // x4
  __int64 v244; // x5
  __int64 v245; // x6
  int v246; // w8
  __int64 v247; // x7
  int v248; // w9
  int v249; // w10
  char v250; // w13
  char v251; // w11
  int v252; // w12
  int v253; // w10
  char v254; // w14
  _BOOL4 v255; // w12
  __int64 v256; // x14
  __int64 v257; // x13
  int v258; // w0
  int v259; // w11
  int v260; // w8
  int v261; // w1
  unsigned int v262; // w8
  int v263; // w2
  unsigned int v264; // w8
  __int64 v265; // x9
  unsigned int v266; // w10
  unsigned int v267; // w10
  _BYTE *v268; // x9
  unsigned int v269; // w22
  __int64 v270; // x11
  unsigned int v271; // w10
  unsigned int v272; // w9
  unsigned int v273; // w8
  char v274; // w9
  unsigned int v275; // w8
  __int64 v276; // x8
  unsigned int v277; // w9
  unsigned int v278; // w10
  _BYTE *v279; // x9
  __int64 v280; // x11
  unsigned int v281; // w10
  unsigned int v282; // w10
  int v283; // w3
  int v284; // w12
  char v285; // w11
  unsigned int v286; // w4
  int v287; // w13
  int v288; // w14
  unsigned int v289; // w9
  bool v290; // cf
  char v291; // w10
  unsigned int v292; // w10
  unsigned int v293; // w10
  unsigned int v294; // w11
  unsigned int v295; // w9
  unsigned int v296; // w9
  unsigned int v297; // w9
  _BYTE *v298; // x8
  __int64 v299; // x10
  unsigned int v300; // w9
  __int64 v301; // x1
  unsigned __int8 *v302; // x0
  double v303; // d0
  double v304; // d1
  double v305; // d2
  double v306; // d3
  double v307; // d4
  double v308; // d5
  double v309; // d6
  double v310; // d7
  unsigned __int8 *v311; // x0
  int v312; // w22
  unsigned int v313; // w23
  unsigned int v314; // w21
  unsigned int v315; // w26
  double v316; // d0
  double v317; // d1
  double v318; // d2
  double v319; // d3
  double v320; // d4
  double v321; // d5
  double v322; // d6
  double v323; // d7
  unsigned int v324; // w9
  unsigned int v325; // w8
  unsigned int v326; // w10
  int v327; // w12
  int v328; // w9
  int v329; // w12
  unsigned int v330; // w10
  unsigned int v331; // w11
  int v332; // w19
  unsigned int v333; // w21
  unsigned __int64 v334; // x23
  __int64 v335; // x11
  __int64 v336; // x10
  double v337; // d0
  double v338; // d1
  double v339; // d2
  double v340; // d3
  double v341; // d4
  double v342; // d5
  double v343; // d6
  double v344; // d7
  __int64 v345; // x19
  __int64 v346; // x3
  __int64 v347; // x4
  __int64 v348; // x5
  __int64 v349; // x6
  __int64 v350; // x7
  unsigned int v351; // w8
  unsigned int v352; // w8
  int v353; // w9
  int v354; // w11
  unsigned __int8 *v355; // x8
  __int64 v356; // x25
  _BOOL4 v357; // w26
  __int64 v358; // x3
  __int64 v359; // x4
  __int64 v360; // x5
  __int64 v361; // x0
  __int64 v362; // x19
  unsigned int v363; // w8
  unsigned int v364; // w9
  __int64 v365; // x0
  __int64 v366; // x0
  __int64 v367; // x0
  __int64 v368; // x0
  double v369; // d0
  double v370; // d1
  double v371; // d2
  double v372; // d3
  double v373; // d4
  double v374; // d5
  double v375; // d6
  double v376; // d7
  __int64 v377; // x8
  __int64 v378; // x3
  __int64 v379; // x4
  __int64 v380; // x5
  __int64 v381; // x6
  __int64 v382; // x19
  __int64 v383; // x0
  __int64 v384; // x0
  unsigned int v385; // w23
  unsigned __int8 *v386; // x8
  __int64 v387; // x4
  __int64 v388; // x5
  __int64 v389; // x6
  __int64 v390; // x7
  __int64 v391; // x8
  __int64 v392; // x3
  __int64 v393; // x4
  __int64 v394; // x5
  __int64 v395; // x6
  __int64 v396; // x19
  __int64 v397; // x0
  __int64 v398; // x0
  __int64 v399; // [xsp+0h] [xbp-180h]
  __int64 v400; // [xsp+0h] [xbp-180h]
  __int64 v401; // [xsp+0h] [xbp-180h]
  __int64 v402; // [xsp+8h] [xbp-178h]
  __int64 v403; // [xsp+8h] [xbp-178h]
  __int64 v404; // [xsp+8h] [xbp-178h]
  __int64 v405; // [xsp+10h] [xbp-170h]
  __int64 v406; // [xsp+10h] [xbp-170h]
  __int64 v407; // [xsp+10h] [xbp-170h]
  __int64 v408; // [xsp+18h] [xbp-168h]
  __int64 v409; // [xsp+18h] [xbp-168h]
  __int64 v410; // [xsp+20h] [xbp-160h]
  __int64 v411; // [xsp+20h] [xbp-160h]
  __int64 v412; // [xsp+28h] [xbp-158h]
  __int64 v413; // [xsp+28h] [xbp-158h]
  __int64 v414; // [xsp+30h] [xbp-150h]
  __int64 v415; // [xsp+30h] [xbp-150h]
  __int64 v416; // [xsp+38h] [xbp-148h]
  __int64 v417; // [xsp+38h] [xbp-148h]
  __int64 v418; // [xsp+40h] [xbp-140h]
  __int64 v419; // [xsp+40h] [xbp-140h]
  __int64 v420; // [xsp+48h] [xbp-138h]
  __int64 v421; // [xsp+48h] [xbp-138h]
  __int64 v422; // [xsp+50h] [xbp-130h]
  __int64 v423; // [xsp+50h] [xbp-130h]
  __int64 v424; // [xsp+58h] [xbp-128h]
  __int64 v425; // [xsp+58h] [xbp-128h]
  __int64 v426; // [xsp+60h] [xbp-120h]
  __int64 v427; // [xsp+60h] [xbp-120h]
  __int64 v428; // [xsp+68h] [xbp-118h]
  __int64 v429; // [xsp+68h] [xbp-118h]
  __int64 v430; // [xsp+70h] [xbp-110h]
  __int64 v431; // [xsp+70h] [xbp-110h]
  __int64 v432; // [xsp+78h] [xbp-108h]
  __int64 v433; // [xsp+78h] [xbp-108h]
  __int64 v434; // [xsp+80h] [xbp-100h]
  __int64 v435; // [xsp+80h] [xbp-100h]
  __int64 v436; // [xsp+88h] [xbp-F8h]
  __int64 v437; // [xsp+88h] [xbp-F8h]
  __int64 v438; // [xsp+90h] [xbp-F0h]
  __int64 v439; // [xsp+90h] [xbp-F0h]
  __int64 v440; // [xsp+98h] [xbp-E8h]
  unsigned int *v441; // [xsp+A0h] [xbp-E0h]
  char v442; // [xsp+ACh] [xbp-D4h]
  char v443; // [xsp+B0h] [xbp-D0h]
  char v444; // [xsp+B4h] [xbp-CCh]
  int v445; // [xsp+B8h] [xbp-C8h]
  int v446; // [xsp+BCh] [xbp-C4h]
  int v447; // [xsp+C0h] [xbp-C0h]
  unsigned int v448; // [xsp+C4h] [xbp-BCh]
  int v449; // [xsp+C4h] [xbp-BCh]
  __int64 v450; // [xsp+C8h] [xbp-B8h]
  unsigned __int64 v451; // [xsp+C8h] [xbp-B8h]
  unsigned int v452; // [xsp+D0h] [xbp-B0h]
  int v453; // [xsp+D0h] [xbp-B0h]
  int v454; // [xsp+D4h] [xbp-ACh]
  unsigned int v455; // [xsp+D4h] [xbp-ACh]
  int v456; // [xsp+D4h] [xbp-ACh]
  _QWORD *v457; // [xsp+D8h] [xbp-A8h]
  unsigned int v458; // [xsp+D8h] [xbp-A8h]
  int v459; // [xsp+D8h] [xbp-A8h]
  int v460; // [xsp+E4h] [xbp-9Ch]
  unsigned int v461; // [xsp+E4h] [xbp-9Ch]
  int v462; // [xsp+E4h] [xbp-9Ch]
  int v463; // [xsp+E4h] [xbp-9Ch]
  int v464; // [xsp+E8h] [xbp-98h]
  int v465; // [xsp+E8h] [xbp-98h]
  int v466; // [xsp+E8h] [xbp-98h]
  int v467; // [xsp+E8h] [xbp-98h]
  int v468; // [xsp+ECh] [xbp-94h]
  int v469; // [xsp+ECh] [xbp-94h]
  int v470; // [xsp+ECh] [xbp-94h]
  unsigned int v471; // [xsp+F0h] [xbp-90h]
  int v472; // [xsp+F0h] [xbp-90h]
  unsigned int v473; // [xsp+F4h] [xbp-8Ch]
  int v474; // [xsp+F4h] [xbp-8Ch]
  _BOOL4 v475; // [xsp+F8h] [xbp-88h]
  unsigned int v476; // [xsp+F8h] [xbp-88h]
  int v477; // [xsp+FCh] [xbp-84h]
  char v478; // [xsp+FCh] [xbp-84h]
  int v479; // [xsp+FCh] [xbp-84h]
  int v480; // [xsp+100h] [xbp-80h]
  _BOOL4 v481; // [xsp+100h] [xbp-80h]
  unsigned __int8 *v482; // [xsp+108h] [xbp-78h]
  __int64 v483; // [xsp+110h] [xbp-70h]
  __int64 v484; // [xsp+118h] [xbp-68h]
  _BOOL4 v485; // [xsp+124h] [xbp-5Ch]
  __int64 v486; // [xsp+128h] [xbp-58h]
  _BYTE *v488; // [xsp+138h] [xbp-48h]
  int v489; // [xsp+144h] [xbp-3Ch]
  _QWORD *v491; // [xsp+150h] [xbp-30h] BYREF
  _QWORD *v492; // [xsp+158h] [xbp-28h] BYREF
  unsigned __int8 v493[12]; // [xsp+164h] [xbp-1Ch] BYREF
  __int64 v494; // [xsp+170h] [xbp-10h]

  v494 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = *(_QWORD *)(a1 + 80);
  v491 = nullptr;
  v492 = nullptr;
  if ( !v13 )
  {
    v28 = "%s: psoc NULL";
    goto LABEL_8;
  }
  v14 = a3;
  if ( !a3 )
  {
    v28 = "%s: Scan list NULL";
    goto LABEL_8;
  }
  v15 = a1;
  result = wlan_psoc_mlme_get_cmpt_obj(v13);
  if ( result )
  {
    v26 = *(unsigned __int16 *)(result + 2018);
    v27 = (_BYTE *)result;
    qdf_trace_msg(
      0x68u,
      8u,
      "Self caps: HT %d VHT %d HE %d EHT %d VHT_24Ghz %d BF cap %d bw_above_20_24ghz %d bw_above_20_5ghz %d 2.4G NSS %d 5G NSS %d",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26 & 1,
      (v26 >> 1) & 1,
      (v26 >> 2) & 1,
      (v26 >> 3) & 1,
      (v26 >> 4) & 1,
      (v26 >> 5) & 1,
      (v26 >> 7) & 1,
      (v26 >> 6) & 1,
      *(unsigned __int8 *)(result + 2016),
      *(unsigned __int8 *)(result + 2017));
    result = qdf_list_peek_front(v14, &v492);
    if ( (_DWORD)result )
    {
      v28 = "%s: failed to peer front of scan list";
LABEL_8:
      result = qdf_trace_msg(0x68u, 2u, v28, a6, a7, a8, a9, a10, a11, a12, a13, "wlan_cm_calculate_bss_score");
      goto LABEL_9;
    }
    v29 = v492;
    if ( !v492 )
      goto LABEL_9;
    v30 = 0;
    v482 = a5;
    v484 = v15;
    v488 = v27;
    v441 = a2 + 103;
    v489 = 1;
    v486 = v13;
    while ( 1 )
    {
      qdf_list_peek_next(v14, v29, &v491);
      v47 = v492;
      v48 = v492[3];
      v49 = *(_DWORD *)a4 | *(unsigned __int16 *)(a4 + 4);
      if ( !v49 )
        goto LABEL_26;
      if ( (v27[2000] & 1) == 0 )
        goto LABEL_23;
      if ( *(_DWORD *)a4 == *(_DWORD *)(v48 + 1) && *(unsigned __int16 *)(a4 + 4) == *(unsigned __int16 *)(v48 + 5) )
        break;
      if ( *(char *)(v48 + 60) >= (char)v27[1944] )
      {
LABEL_23:
        LOBYTE(v49) = 0;
        if ( (v27[2000] & 2) == 0 )
          goto LABEL_33;
        goto LABEL_27;
      }
      LODWORD(v402) = (char)v27[1944];
      LODWORD(v399) = *(char *)(v48 + 60);
      qdf_trace_msg(
        0x68u,
        8u,
        "Candidate(%02x:%02x:%02x:**:**:%02x  freq %d): remove entry, rssi %d lower than rssi_threshold %d",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        *(unsigned __int8 *)(v48 + 1),
        *(unsigned __int8 *)(v48 + 2),
        *(unsigned __int8 *)(v48 + 3),
        *(unsigned __int8 *)(v48 + 6),
        *(unsigned int *)(v48 + 1064),
        v399,
        v402);
      v48 = v47[3];
      LOBYTE(v49) = 1;
      if ( (v27[2000] & 2) == 0 )
        goto LABEL_33;
LABEL_27:
      v51 = *(_QWORD *)(v48 + 1616);
      if ( v51 )
      {
        v52 = *(unsigned __int8 *)(v51 + 1);
        if ( v52 >= 7 )
        {
          v53 = v52 - 4;
          v54 = (_BYTE *)(v51 + 6);
          do
          {
            v55 = (unsigned __int8)v54[1];
            v56 = v53 - 2;
            if ( (unsigned int)v55 > (unsigned __int8)v56 )
              break;
            if ( *v54 == 4 )
            {
              LODWORD(v402) = (unsigned __int8)v54[2];
              LODWORD(v399) = *(char *)(v48 + 60);
              qdf_trace_msg(
                0x68u,
                8u,
                "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d, assoc disallowed set in MBO/OCE IE reason %d",
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                *(unsigned __int8 *)(v48 + 1),
                *(unsigned __int8 *)(v48 + 2),
                *(unsigned __int8 *)(v48 + 3),
                *(unsigned __int8 *)(v48 + 6),
                *(unsigned int *)(v48 + 1064),
                v399,
                v402);
              v48 = v47[3];
              goto LABEL_34;
            }
            v53 = v56 - v55;
            v54 += v55 + 2;
          }
          while ( (unsigned __int8)v53 > 2u );
        }
      }
LABEL_33:
      if ( (v49 & 1) != 0 )
      {
LABEL_34:
        v57 = 0;
        v58 = 2;
        v59 = 1;
LABEL_35:
        v60 = v30;
        v61 = v57;
        if ( v48 == -1 )
        {
          v64 = 0;
          v62 = 0;
          v63 = 0;
          v65 = 0;
        }
        else
        {
          v62 = *(unsigned __int8 *)(v48 + 1);
          v63 = *(unsigned __int8 *)(v48 + 2);
          v64 = *(unsigned __int8 *)(v48 + 3);
          v65 = *(unsigned __int8 *)(v48 + 6);
        }
        LODWORD(v399) = v58;
        qdf_trace_msg(
          0x68u,
          8u,
          "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): denylist_action %d",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          v62,
          v63,
          v64,
          v65,
          *(unsigned int *)(v48 + 1064),
          v399);
        v81 = v61;
        v30 = v60;
        v13 = v486;
        goto LABEL_436;
      }
      v58 = wlan_denylist_action_on_bssid(v15, v48);
      if ( v58 != 3 && v58 )
      {
        v66 = v489;
        v67 = 0;
      }
      else
      {
        v66 = 0;
        if ( a2 )
        {
          v67 = 0;
          if ( !v58 )
          {
            v68 = *a2;
            if ( !(_DWORD)v68 || (v69 = v47[3], *(char *)(v69 + 60) < -74) || !v27[1928] )
            {
              v485 = 0;
              v67 = 0;
              v489 = 0;
              goto LABEL_61;
            }
            v70 = *(_DWORD *)(v69 + 1064);
            v71 = 0;
            v72 = 1;
            while ( 1 )
            {
              if ( v71 == 102 )
              {
                __break(0x5512u);
                goto LABEL_500;
              }
              if ( v441[v71 - 102] == v70 )
                break;
              v72 = ++v71 < v68;
              if ( v68 == v71 )
              {
                v66 = 0;
                v67 = 0;
                goto LABEL_55;
              }
            }
            v67 = *((unsigned __int8 *)v441 + v71);
            if ( v72 )
              qdf_trace_msg(
                0x68u,
                8u,
                "%s: pcl freq %d pcl_chan_weight %d",
                v39,
                v40,
                v41,
                v42,
                v43,
                v44,
                v45,
                v46,
                "wlan_cm_calculate_bss_score");
            v66 = 0;
          }
        }
        else
        {
          v67 = 0;
        }
      }
LABEL_55:
      v489 = v66;
      v57 = v58 == 1;
      if ( !v58 || (v57 & v66) != 0 )
      {
        v485 = v58 == 1;
LABEL_61:
        v87 = v47[3];
        cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(v13);
        if ( !cmpt_obj )
          goto LABEL_426;
        v89 = cmpt_obj;
        v483 = v30;
        if ( (*(_BYTE *)(cmpt_obj + 2000) & 4) == 0 )
        {
          v90 = *(unsigned __int8 *)(cmpt_obj + 1936);
          v91 = *(char *)(v87 + 60);
          v92 = *(unsigned __int8 *)(cmpt_obj + 1937);
          v93 = *(unsigned __int8 *)(cmpt_obj + 1938);
          v94 = *(unsigned __int8 *)(cmpt_obj + 1939);
          v95 = *(unsigned __int8 *)(cmpt_obj + 1942);
          v96 = -v92;
          v480 = 100 * *(unsigned __int8 *)(cmpt_obj + 1920);
          v97 = *(unsigned __int8 *)(cmpt_obj + 1940);
          if ( -v90 >= v91 )
          {
            if ( -v93 >= v91 )
            {
              v118 = (42949673 * (unsigned __int64)(v480 * v97)) >> 32;
            }
            else
            {
              if ( v96 >= v91 )
              {
                v135 = v94
                     - v97
                     + ((char)((v93 - v92) / v95 + 1 + ((unsigned __int8)(((v93 - v92) / v95 + 1) & 0x80) >> 7)) >> 1);
                v136 = ~((char)(v96 - v91) / v95);
                v99 = v94 + v135 / (char)((v93 - v92) / v95 + 1) * v136;
                if ( v97 > (char)(v94 + v135 / (char)((v93 - v92) / v95 + 1) * v136) )
                  LOBYTE(v99) = *(_BYTE *)(cmpt_obj + 1940);
              }
              else
              {
                v98 = *(unsigned __int8 *)(cmpt_obj + 1941);
                v99 = (((char)((v92 - v90) / v98 + 1 + ((((v92 - v90) / v98 + 1) & 0x80) >> 7)) >> 1) - v94 + 100)
                    / (char)((v92 - v90) / v98 + 1)
                    * ~((char)(-(char)v90 - v91) / v98)
                    + 100;
                if ( v94 > (char)v99 )
                  LOBYTE(v99) = *(_BYTE *)(cmpt_obj + 1939);
              }
              LODWORD(v118) = (char)v99 * v480 / 100;
            }
            v480 = v118;
          }
          v137 = v96 - v91;
          if ( v96 >= v91 )
          {
            v139 = *(_BYTE *)(cmpt_obj + 1943);
            if ( v91 < (char)-v139
              || (unsigned __int16)(v137 / (char)v95) == (unsigned __int16)((char)(v139 - v92) / (char)v95) )
            {
              v138 = 0;
            }
            else
            {
              v140 = -v93 < v91;
              v138 = 0;
              if ( v140 )
              {
                v141 = v94
                     + (v94
                      - v97
                      + ((char)((v93 - v92) / v95 + 1 + ((unsigned __int8)(((v93 - v92) / v95 + 1) & 0x80) >> 7)) >> 1))
                     / (char)((v93 - v92) / v95 + 1)
                     * ~(v137 / v95);
                if ( v97 <= (char)v141 )
                  v138 = v141;
                else
                  v138 = *(_BYTE *)(cmpt_obj + 1940);
              }
            }
          }
          else
          {
            v138 = 100;
          }
          v151 = *(unsigned __int8 *)(cmpt_obj + 1924);
          v478 = v138;
          is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(unsigned int *)(v87 + 1064));
          v153 = *(_DWORD *)(v87 + 52);
          if ( v153 > 0x1E )
            goto LABEL_209;
          v154 = 1 << v153;
          if ( (v154 & 0x781E780) != 0 )
          {
            v155 = 40;
            goto LABEL_169;
          }
          if ( (v154 & 0x18060000) != 0 )
          {
            v155 = 80;
LABEL_169:
            v156 = 1;
          }
          else
          {
            if ( (v154 & 0x60180000) != 0 )
            {
              v155 = 160;
              goto LABEL_169;
            }
LABEL_209:
            v156 = 0;
            v155 = 20;
          }
          v157 = *(unsigned __int16 *)(v89 + 2018);
          if ( (is_24ghz_ch_freq & 1) != 0 )
            v158 = 16;
          else
            v158 = 2;
          if ( (((v157 & 1) == 0) & (unsigned __int8)v156) != 0 )
            v155 = 20;
          if ( v155 >= 0x28 )
            v159 = 40;
          else
            v159 = v155;
          if ( (v157 & v158) == 0 )
            v155 = v159;
          v160 = ((205 * v155) >> 12) - 1;
          if ( v160 > 0xF )
            goto LABEL_500;
          v161 = link_bw_score[(unsigned __int8)v160];
          v162 = *(unsigned __int8 *)(v89 + 1929);
          v465 = v161;
          v469 = v151;
          if ( v87 )
          {
            v163 = *(unsigned __int8 *)(v87 + 82);
            if ( *(_BYTE *)(v87 + 82) )
            {
              v164 = 100 - ((unsigned int)(3289700 * v163) >> 23);
              if ( ((100 * (_WORD)v163 - 25500) & 0xFFFCu) < 0xFF )
                v164 = 1;
            }
            else if ( *(_QWORD *)(v87 + 1376) )
            {
              if ( (3289700 * (unsigned int)*(unsigned __int8 *)(v87 + 83)) >> 23 <= 1 )
                v164 = 1;
              else
                v164 = (3289700 * (unsigned int)*(unsigned __int8 *)(v87 + 83)) >> 23;
            }
            else
            {
              v164 = 0;
            }
            v165 = *(unsigned __int8 *)(v89 + 1948);
            if ( !*(_BYTE *)(v89 + 1948) )
            {
              v474 = 0;
              goto LABEL_285;
            }
            if ( v165 <= 0xF )
            {
              if ( *(char *)(v87 + 60) > -*(unsigned __int8 *)(v89 + 1937) )
                goto LABEL_196;
              v167 = 8 * v165;
              if ( v165 > 3 )
              {
                if ( v165 > 7 )
                  goto LABEL_279;
                v171 = *(_DWORD *)(v89 + 1956);
              }
              else
              {
                v171 = *(_DWORD *)(v89 + 1952);
              }
LABEL_282:
              v170 = v171 >> v167;
              goto LABEL_283;
            }
            v165 = 15;
            v166 = *(unsigned __int8 *)(v89 + 1937);
            *(_BYTE *)(v89 + 1948) = 15;
            if ( *(char *)(v87 + 60) <= -v166 )
            {
              v167 = 120;
              goto LABEL_281;
            }
LABEL_196:
            if ( v164 )
            {
              v168 = v164 / (0x64 / v165);
              if ( v168 + 1 < v165 )
                v165 = v168 + 1;
              if ( v165 <= 3 )
              {
                v169 = *(_DWORD *)(v89 + 1952);
                goto LABEL_206;
              }
              if ( v165 <= 7 )
              {
                v169 = *(_DWORD *)(v89 + 1956);
LABEL_206:
                v170 = v169 >> (8 * v165);
LABEL_283:
                v170 = (unsigned __int8)v170;
LABEL_284:
                v474 = v170 * v162;
LABEL_285:
                v210 = *(_DWORD *)(v87 + 1064);
                if ( (wlan_reg_is_5ghz_ch_freq(v210) & 1) != 0 )
                {
                  v219 = 8;
                  goto LABEL_291;
                }
                if ( (wlan_reg_is_24ghz_ch_freq(v210) & 1) != 0 )
                {
                  v219 = 0;
                  goto LABEL_291;
                }
                if ( (wlan_reg_is_6ghz_chan_freq(v210) & 1) != 0 )
                {
                  v219 = 16;
LABEL_291:
                  v472 = (unsigned __int8)(*(_DWORD *)(v89 + 1996) >> v219) * *(unsigned __int8 *)(v89 + 1925);
                  if ( a4 )
                  {
LABEL_292:
                    if ( (*(_BYTE *)(v89 + 2000) & 1) == 0 )
                      goto LABEL_297;
                    if ( *(_DWORD *)a4 != *(_DWORD *)(v87 + 1)
                      || *(unsigned __int16 *)(a4 + 4) != *(unsigned __int16 *)(v87 + 5) )
                    {
                      goto LABEL_297;
                    }
                    v243 = *(unsigned __int8 *)(v87 + 1);
                    v244 = *(unsigned __int8 *)(v87 + 2);
                    v245 = *(unsigned __int8 *)(v87 + 3);
                    v246 = *(_DWORD *)(v87 + 1132) + 20000;
                    v247 = *(unsigned __int8 *)(v87 + 6);
                    v248 = *(_DWORD *)(v87 + 1064);
                    v249 = *(char *)(v87 + 60);
                    *(_DWORD *)(v87 + 1132) = v246;
                    LODWORD(v405) = v246;
                    LODWORD(v402) = v249;
                    LODWORD(v399) = v248;
                    qdf_trace_msg(
                      0x68u,
                      8u,
                      "%s(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d BSSID hint given, give max score %d",
                      v211,
                      v212,
                      v213,
                      v214,
                      v215,
                      v216,
                      v217,
                      v218,
                      "Candidate",
                      v243,
                      v244,
                      v245,
                      v247,
                      v399,
                      v402,
                      v405);
LABEL_426:
                    if ( (policy_mgr_is_hw_dbs_capable(v13) & 1) != 0 )
                    {
                      a5 = v482;
                      v15 = v484;
LABEL_435:
                      v59 = 0;
                      v27 = v488;
                      v81 = v485;
                      goto LABEL_436;
                    }
                    v27 = v488;
                    a5 = v482;
                    v15 = v484;
                    if ( v488[1935] )
                    {
                      v345 = v47[3];
                      if ( (policy_mgr_is_sta_sap_mcc_weightage_required(v13, v484, *(unsigned int *)(v345 + 1064)) & 1) == 0 )
                        goto LABEL_435;
                      v346 = *(unsigned __int8 *)(v345 + 1);
                      v347 = *(unsigned __int8 *)(v345 + 2);
                      v348 = *(unsigned __int8 *)(v345 + 3);
                      v349 = *(unsigned __int8 *)(v345 + 6);
                      v350 = *(unsigned int *)(v345 + 1064);
                      v351 = *(_DWORD *)(v345 + 1132) * (unsigned __int8)v488[1935];
                      if ( v351 < 0x64 )
                        v352 = 1;
                      else
                        v352 = v351 / 0x64;
                      v353 = *(char *)(v345 + 60);
                      *(_DWORD *)(v345 + 1132) = v352;
                      v27 = v488;
                      LODWORD(v402) = v352;
                      LODWORD(v399) = v353;
                      qdf_trace_msg(
                        0x68u,
                        8u,
                        "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d, is causing MCC, update score to %d",
                        v73,
                        v74,
                        v75,
                        v76,
                        v77,
                        v78,
                        v79,
                        v80,
                        v346,
                        v347,
                        v348,
                        v349,
                        v350,
                        v399,
                        v402);
                    }
                    v81 = v485;
                    v59 = 0;
                    goto LABEL_436;
                  }
                }
                else
                {
                  v472 = 0;
                  if ( a4 )
                    goto LABEL_292;
                }
LABEL_297:
                v221 = *(unsigned __int8 *)(v89 + 1928);
                if ( (policy_mgr_is_pcl_weightage_required(v13) & 1) != 0 )
                {
                  is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(v13);
                  v476 = 0;
                  if ( v67 )
                  {
                    v223 = v478;
                    if ( (is_hw_dbs_capable & 1) != 0 )
                      v476 = 100
                           * ((v221 - ((205 * (v67 ^ 0xFFu)) >> 12))
                            & ~((int)(v221 - ((205 * (v67 ^ 0xFFu)) >> 12)) >> 31));
                  }
                  else
                  {
                    v223 = v478;
                  }
                }
                else
                {
                  v223 = v478;
                  v476 = 0;
                }
                v224 = v223;
                v479 = v223;
                if ( (*(_WORD *)(v89 + 2018) & 1) != 0 )
                {
                  if ( *(_QWORD *)(v87 + 1328)
                    || (is_6ghz_chan_freq = wlan_reg_is_6ghz_chan_freq(*(unsigned int *)(v87 + 1064)),
                        v224 = v479,
                        (is_6ghz_chan_freq & 1) != 0) )
                  {
                    v225 = v224 * *(unsigned __int8 *)(v89 + 1921);
                  }
                  else
                  {
                    v225 = 0;
                  }
                }
                else
                {
                  v225 = 0;
                }
                v227 = wlan_reg_is_24ghz_ch_freq(*(unsigned int *)(v87 + 1064));
                v236 = *(_WORD *)(v89 + 2018);
                if ( (v227 & 1) != 0 )
                {
                  if ( (v236 & 0x10) == 0 )
                    goto LABEL_309;
LABEL_312:
                  v237 = v479;
                  if ( *(_QWORD *)(v87 + 1432)
                    || (v241 = wlan_reg_is_6ghz_chan_freq(*(unsigned int *)(v87 + 1064)), v237 = v479, (v241 & 1) != 0) )
                  {
                    v238 = v237 * *(unsigned __int8 *)(v89 + 1922);
                    v239 = 0;
                    v240 = *(_WORD *)(v89 + 2018);
                    if ( (v240 & 4) != 0 )
                      goto LABEL_315;
LABEL_323:
                    v242 = 0;
LABEL_324:
                    v250 = *(_BYTE *)(v89 + 1937);
                    v251 = *(_BYTE *)(v89 + 1943);
                    v252 = (char)-v250;
                    v253 = *(char *)(v87 + 60);
                    v254 = v252 - v253;
                    v140 = v252 <= v253;
                    v255 = 0;
                    if ( !v140 )
                      v255 = (unsigned __int16)(v254 / *(char *)(v89 + 1942)) == (unsigned __int16)((char)(v251 - v250)
                                                                                                  / *(char *)(v89 + 1942));
                    v256 = *(_QWORD *)(v87 + 1432);
                    v257 = *(_QWORD *)(v87 + 1568);
                    if ( v256 && (*(_BYTE *)(v256 + 3) & 8) != 0 || v257 && *(char *)(v257 + 12) < 0 )
                    {
                      v259 = (char)-v251;
                      if ( (v240 & 0x20) == 0 )
                        v239 = 1;
                      if ( v253 <= v259 )
                        v239 = 1;
                      if ( ((v239 | v255) & 1) != 0 )
                        v258 = 0;
                      else
                        v258 = 100 * *(unsigned __int8 *)(v89 + 1927);
                      v446 = 1;
                    }
                    else
                    {
                      v446 = 0;
                      v258 = 0;
                    }
                    v451 = __PAIR64__(v238, v242);
                    v449 = v258;
                    v447 = v237 * v469 * v465 / 100;
                    v260 = *(unsigned __int8 *)(v87 + 82);
                    v261 = v447
                         + v480
                         + ((42949673 * (unsigned __int64)(unsigned int)(80 * v474)) >> 32)
                         + v472
                         + v476
                         + v225
                         + v238
                         + v242
                         + v258;
                    if ( *(_BYTE *)(v87 + 82) )
                    {
                      if ( ((100 * (_WORD)v260 - 25500) & 0xFFFCu) < 0xFF )
                      {
                        v459 = 1;
                        goto LABEL_349;
                      }
                      v262 = 100 - ((unsigned int)(3289700 * v260) >> 23);
LABEL_346:
                      v459 = v262;
                      if ( v262 > 0x4A )
                      {
                        v263 = 0;
LABEL_373:
                        v276 = *(_QWORD *)(v87 + 1616);
                        if ( v276 )
                        {
                          v277 = *(unsigned __int8 *)(v276 + 1);
                          if ( v277 >= 7 )
                          {
                            v278 = v277 - 4;
                            v279 = (_BYTE *)(v276 + 6);
                            do
                            {
                              v280 = (unsigned __int8)v279[1];
                              v281 = v278 - 2;
                              if ( (unsigned int)v280 > (unsigned __int8)v281 )
                                break;
                              if ( *v279 == 107 )
                              {
                                v283 = -(unsigned __int8)v279[2];
                                v282 = *(char *)(v87 + 60) - (char)-v279[2] + 20;
                                goto LABEL_380;
                              }
                              v278 = v281 - v280;
                              v279 += v280 + 2;
                            }
                            while ( (unsigned __int8)v278 > 2u );
                          }
                        }
                        v282 = *(char *)(v87 + 60);
                        LOBYTE(v283) = 0;
LABEL_380:
                        v284 = *(unsigned __int8 *)(v89 + 1936);
                        v285 = -(char)v284 - v282;
                        if ( -v284 >= v282 )
                        {
                          v287 = *(unsigned __int8 *)(v89 + 1938);
                          v286 = *(unsigned __int8 *)(v89 + 1940);
                          if ( v282 > -v287 )
                          {
                            v288 = *(unsigned __int8 *)(v89 + 1937);
                            v289 = *(unsigned __int8 *)(v89 + 1939);
                            v290 = -v288 >= v282;
                            v291 = -(char)v288 - v282;
                            if ( v290 )
                            {
                              v294 = *(unsigned __int8 *)(v89 + 1942);
                              v295 = v289
                                   + (v289
                                    - v286
                                    + ((char)((v287 - v288) / v294
                                            + 1
                                            + ((unsigned __int8)(((v287 - v288) / v294 + 1) & 0x80) >> 7)) >> 1))
                                   / (char)((v287 - v288) / v294 + 1)
                                   * ~(v291 / v294);
                              if ( v286 <= (char)v295 )
                                LOBYTE(v286) = v295;
                            }
                            else
                            {
                              v292 = *(unsigned __int8 *)(v89 + 1941);
                              v293 = (((char)((v288 - v284) / v292 + 1 + ((((v288 - v284) / v292 + 1) & 0x80) >> 7)) >> 1)
                                    - v289
                                    + 100)
                                   / (char)((v288 - v284) / v292 + 1)
                                   * ~(v285 / v292)
                                   + 100;
                              if ( v289 <= (char)v293 )
                                LOBYTE(v286) = v293;
                              else
                                LOBYTE(v286) = *(_BYTE *)(v89 + 1939);
                            }
                          }
                        }
                        else
                        {
                          LOBYTE(v286) = 100;
                        }
                        v462 = v261;
                        v444 = v283;
                        v445 = v263;
                        v442 = *(_BYTE *)(v89 + 1931);
                        v443 = v286;
                        if ( v276 )
                        {
                          v296 = *(unsigned __int8 *)(v276 + 1);
                          if ( v296 >= 7 )
                          {
                            v297 = v296 - 4;
                            v298 = (_BYTE *)(v276 + 6);
                            do
                            {
                              v299 = (unsigned __int8)v298[1];
                              v300 = v297 - 2;
                              if ( (unsigned int)v299 > (unsigned __int8)v300 )
                                break;
                              if ( *v298 == 108 )
                              {
                                v470 = (unsigned __int8)(50 * *(_BYTE *)(v89 + 1932));
                                v456 = 1;
                                goto LABEL_396;
                              }
                              v297 = v300 - v299;
                              v298 += v299 + 2;
                            }
                            while ( (unsigned __int8)v297 > 2u );
                          }
                        }
                        v456 = 0;
                        v470 = 0;
LABEL_396:
                        v301 = *(unsigned __int8 *)(v87 + 1158);
                        v493[0] = 0;
                        v302 = (unsigned __int8 *)util_scan_entry_rsnxe_by_gen(v87, v301);
                        v311 = wlan_crypto_parse_rsnxe_ie(v302, v493, v303, v304, v305, v306, v307, v308, v309, v310);
                        v453 = v225;
                        if ( v311 && (*v311 & 0x40) != 0 )
                        {
                          v312 = 1;
                          v467 = 100 * *(unsigned __int8 *)(v89 + 1933);
                        }
                        else
                        {
                          v312 = 0;
                          v467 = 0;
                        }
                        v313 = *(_DWORD *)(v87 + 1064);
                        v314 = *(unsigned __int8 *)(v89 + 2016);
                        v315 = *(unsigned __int8 *)(v89 + 2017);
                        if ( (policy_mgr_is_chnl_in_diff_band(v13, v313) & 1) != 0
                          && (policy_mgr_is_hw_dbs_capable(v13) & 1) != 0
                          && (policy_mgr_is_hw_dbs_2x2_capable(v13) & 1) == 0 )
                        {
                          v324 = 1;
                        }
                        else if ( (wlan_reg_is_24ghz_ch_freq(v313) & 1) != 0 )
                        {
                          v324 = v314;
                        }
                        else
                        {
                          v324 = v315;
                        }
                        v325 = *(unsigned __int8 *)(v87 + 84);
                        if ( v324 >= v325 )
                          v324 = *(unsigned __int8 *)(v87 + 84);
                        v326 = *(_DWORD *)(v89 + 1992);
                        switch ( v324 )
                        {
                          case 2u:
                            v326 >>= 8;
                            break;
                          case 3u:
                            v326 >>= 16;
                            break;
                          case 4u:
                            v326 >>= 24;
                            break;
                        }
                        v327 = *(_DWORD *)(v87 + 1136);
                        v328 = *(_DWORD *)(v87 + 1140);
                        if ( (v327 & 0x6C8) != 0 )
                        {
                          if ( (v328 & 0x19FF0C00) != 0 )
                          {
                            LOWORD(v329) = *(_WORD *)(v89 + 2014);
                            goto LABEL_422;
                          }
                          if ( (v328 & 0x1E2) != 0 )
                          {
                            v329 = *(_DWORD *)(v89 + 2012) >> 8;
                            goto LABEL_422;
                          }
                        }
                        else if ( (v327 & 0x124) != 0 )
                        {
                          LOBYTE(v329) = *(_BYTE *)(v89 + 2012);
                          goto LABEL_422;
                        }
                        LOBYTE(v329) = 0;
LABEL_422:
                        v330 = (unsigned __int8)v326 * v479 * *(unsigned __int8 *)(v89 + 1926);
                        v331 = ((unsigned __int8)v329 * (unsigned int)*(unsigned __int8 *)(v89 + 1934)) >> 2;
                        v332 = (unsigned __int8)(v442 * v443);
                        v333 = (5243 * v331) >> 17;
                        v334 = (42949673 * (unsigned __int64)v330) >> 32;
                        v335 = *(_QWORD *)(v87 + 1680);
                        *(_DWORD *)(v87 + 1132) = v462 + v332 + v470 + v467 + v333 + v334;
                        if ( v335 || (v336 = *(_QWORD *)(v87 + 1696)) != 0 )
                          LODWORD(v336) = 1;
                        LODWORD(v424) = v325;
                        LODWORD(v430) = v312;
                        LODWORD(v422) = v459;
                        LODWORD(v432) = v479;
                        LODWORD(v426) = v444;
                        LODWORD(v420) = *(unsigned __int8 *)(v87 + 83);
                        LODWORD(v410) = *(_QWORD *)(v87 + 1568) != 0;
                        LODWORD(v440) = *(_QWORD *)(v87 + 1688) != 0;
                        LODWORD(v438) = v336;
                        LODWORD(v436) = 0;
                        LODWORD(v434) = v328;
                        LODWORD(v428) = v456;
                        LODWORD(v418) = *(unsigned __int8 *)(v87 + 82);
                        LODWORD(v416) = *(_DWORD *)(v87 + 52);
                        LODWORD(v414) = v446;
                        LODWORD(v412) = 0;
                        LODWORD(v408) = *(_QWORD *)(v87 + 1432) != 0;
                        LODWORD(v405) = *(_QWORD *)(v87 + 1328) != 0;
                        LODWORD(v402) = *(char *)(v87 + 60);
                        LODWORD(v399) = *(_DWORD *)(v87 + 1064);
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "%s(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d HT %d VHT %d HE %d EHT %d su_bfer %d phy %d atf"
                          " %d qbss %d cong_pct %d NSS %d ap_tx_pwr %d oce_subnet %d sae_pk_cap %d prorated_pcnt %d keymg"
                          "mt 0x%x mlo type %d rsno %d rsnxo %d",
                          v316,
                          v317,
                          v318,
                          v319,
                          v320,
                          v321,
                          v322,
                          v323,
                          "Candidate",
                          *(unsigned __int8 *)(v87 + 1),
                          *(unsigned __int8 *)(v87 + 2),
                          *(unsigned __int8 *)(v87 + 3),
                          *(unsigned __int8 *)(v87 + 6),
                          v399,
                          v402,
                          v405,
                          v408,
                          v410,
                          v412,
                          v414,
                          v416,
                          v418,
                          v420,
                          v422,
                          v424,
                          v426,
                          v428,
                          v430,
                          v432,
                          v434,
                          v436,
                          v438,
                          v440);
                        LODWORD(v431) = v467;
                        LODWORD(v439) = v462 + v332 + v470 + v467 + v333 + v334;
                        LODWORD(v429) = v470;
                        LODWORD(v437) = 0;
                        LODWORD(v425) = v445;
                        LODWORD(v435) = v333;
                        LODWORD(v421) = v474;
                        LODWORD(v433) = 0;
                        LODWORD(v419) = v472;
                        LODWORD(v427) = (unsigned __int8)(v442 * v443);
                        LODWORD(v417) = v447;
                        LODWORD(v423) = v334;
                        LODWORD(v415) = v449;
                        LODWORD(v401) = *(_DWORD *)(v87 + 1064);
                        LODWORD(v411) = HIDWORD(v451);
                        LODWORD(v413) = v451;
                        LODWORD(v409) = v453;
                        LODWORD(v407) = v476;
                        LODWORD(v404) = v480;
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "%s score(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d pcl %d ht %d vht %d he %d bfee %d bw %d b"
                          "and %d cong %d nss %d oce_wan %d oce_ap_pwr %d oce_subnet %d sae_pk %d eht %d security %d ml %d TOTAL %d",
                          v337,
                          v338,
                          v339,
                          v340,
                          v341,
                          v342,
                          v343,
                          v344,
                          "Candidate",
                          *(unsigned __int8 *)(v87 + 1),
                          *(unsigned __int8 *)(v87 + 2),
                          *(unsigned __int8 *)(v87 + 3),
                          *(unsigned __int8 *)(v87 + 6),
                          v401,
                          v404,
                          v407,
                          v409,
                          v411,
                          v413,
                          v415,
                          v417,
                          v419,
                          v421,
                          v423,
                          v425,
                          v427,
                          v429,
                          v431,
                          v433,
                          v435,
                          v437,
                          v439);
                        v30 = v483;
                        goto LABEL_426;
                      }
                    }
                    else
                    {
                      if ( *(_QWORD *)(v87 + 1376) )
                      {
                        v262 = (3289700 * (unsigned int)*(unsigned __int8 *)(v87 + 83)) >> 23;
                        if ( v262 <= 1 )
                          v262 = 1;
                        goto LABEL_346;
                      }
                      v459 = 0;
                    }
LABEL_349:
                    v264 = *(unsigned __int8 *)(v89 + 1968);
                    if ( *(_BYTE *)(v89 + 1968) )
                    {
                      if ( v264 >= 0x10 )
                      {
                        v264 = 15;
                        *(_BYTE *)(v89 + 1968) = 15;
                      }
                      v265 = *(_QWORD *)(v87 + 1616);
                      if ( v265 )
                      {
                        v266 = *(unsigned __int8 *)(v265 + 1);
                        if ( v266 >= 7 )
                        {
                          v267 = v266 - 4;
                          v268 = (_BYTE *)(v265 + 6);
                          v269 = 0xF / v264;
                          do
                          {
                            v270 = (unsigned __int8)v268[1];
                            v271 = v267 - 2;
                            if ( (unsigned int)v270 > (unsigned __int8)v271 )
                              break;
                            if ( *v268 == 103 )
                            {
                              v463 = v447
                                   + v480
                                   + ((42949673 * (unsigned __int64)(unsigned int)(80 * v474)) >> 32)
                                   + v472
                                   + v476
                                   + v225
                                   + v238
                                   + v242
                                   + v258;
                              v385 = v268[2] & 0xF;
                              qdf_trace_msg(
                                0x68u,
                                2u,
                                "%s: downlink_av_cap %d",
                                v228,
                                v229,
                                v230,
                                v231,
                                v232,
                                v233,
                                v234,
                                v235,
                                "cm_calculate_oce_wan_score",
                                v268[2] & 0xF);
                              if ( v385 )
                              {
                                LODWORD(v265) = v385 / v269;
                                v264 = *(unsigned __int8 *)(v89 + 1968);
                                v261 = v463;
                                goto LABEL_359;
                              }
                              v261 = v463;
                              v263 = 0;
                              goto LABEL_372;
                            }
                            v267 = v271 - v270;
                            v268 += v270 + 2;
                          }
                          while ( (unsigned __int8)v267 > 2u );
                        }
                        LODWORD(v265) = 0;
                      }
LABEL_359:
                      if ( (unsigned int)v265 < v264 )
                        v264 = v265;
                      if ( v264 <= 3 )
                      {
                        v272 = *(_DWORD *)(v89 + 1972);
                        goto LABEL_366;
                      }
                      if ( v264 > 7 )
                      {
                        v274 = 8 * v264;
                        if ( v264 > 0xB )
                          v275 = *(_DWORD *)(v89 + 1984);
                        else
                          v275 = *(_DWORD *)(v89 + 1980);
                        v273 = v275 >> v274;
                      }
                      else
                      {
                        v272 = *(_DWORD *)(v89 + 1976);
LABEL_366:
                        v273 = v272 >> (8 * v264);
                      }
                      v263 = (unsigned __int8)v273 * *(unsigned __int8 *)(v89 + 1930);
                    }
                    else
                    {
                      v263 = 0;
                    }
LABEL_372:
                    v261 += v263;
                    goto LABEL_373;
                  }
                  v239 = 0;
                  v238 = 0;
                  v240 = *(_WORD *)(v89 + 2018);
                  if ( (v240 & 4) == 0 )
                    goto LABEL_323;
                }
                else
                {
                  if ( (v236 & 2) != 0 )
                    goto LABEL_312;
LABEL_309:
                  v237 = v479;
                  v238 = 0;
                  v239 = 1;
                  v240 = *(_WORD *)(v89 + 2018);
                  if ( (v240 & 4) == 0 )
                    goto LABEL_323;
                }
LABEL_315:
                if ( !*(_QWORD *)(v87 + 1568) )
                  goto LABEL_323;
                v242 = v237 * *(unsigned __int8 *)(v89 + 1923);
                goto LABEL_324;
              }
              v167 = 8 * v165;
LABEL_279:
              if ( v165 > 0xB )
LABEL_281:
                v171 = *(_DWORD *)(v89 + 1964);
              else
                v171 = *(_DWORD *)(v89 + 1960);
              goto LABEL_282;
            }
          }
          v170 = *(unsigned __int8 *)(v89 + 1952);
          goto LABEL_284;
        }
        v100 = *(_WORD *)(cmpt_obj + 2018);
        v481 = (v100 & 4) != 0 && *(_QWORD *)(v87 + 1568) != 0;
        if ( (v100 & 0x12) != 0
          && (*(_QWORD *)(v87 + 1432) || (wlan_reg_is_6ghz_chan_freq(*(unsigned int *)(v87 + 1064)) & 1) != 0) )
        {
          v477 = 1;
          if ( (*(_WORD *)(v89 + 2018) & 1) == 0 )
            goto LABEL_77;
LABEL_79:
          v475 = *(_QWORD *)(v87 + 1328) != 0;
        }
        else
        {
          v477 = 0;
          if ( (*(_WORD *)(v89 + 2018) & 1) != 0 )
            goto LABEL_79;
LABEL_77:
          v475 = 0;
        }
        v101 = *(_DWORD *)(v87 + 1064);
        v102 = *(unsigned __int8 *)(v89 + 2016);
        v103 = *(unsigned __int8 *)(v89 + 2017);
        if ( (policy_mgr_is_chnl_in_diff_band(v13, v101) & 1) != 0
          && (policy_mgr_is_hw_dbs_capable(v13) & 1) != 0
          && (policy_mgr_is_hw_dbs_2x2_capable(v13) & 1) == 0 )
        {
          v104 = 1;
        }
        else if ( (wlan_reg_is_24ghz_ch_freq(v101) & 1) != 0 )
        {
          v104 = v102;
        }
        else
        {
          v104 = v103;
        }
        if ( v104 >= *(unsigned __int8 *)(v87 + 84) )
          v105 = *(unsigned __int8 *)(v87 + 84);
        else
          v105 = v104;
        v106 = wlan_reg_is_24ghz_ch_freq(*(unsigned int *)(v87 + 1064));
        v115 = *(unsigned __int16 *)(v89 + 2018);
        if ( (v106 & 1) != 0 )
        {
          v116 = (v115 >> 7) & 1;
          v117 = (v115 & 0x10) == 0;
        }
        else if ( (v115 & 2) != 0 )
        {
          v116 = (v115 >> 6) & 1;
          v117 = 0;
        }
        else
        {
          v116 = 0;
          v117 = 1;
        }
        v119 = *(_DWORD *)(v87 + 52) - 7;
        if ( v119 > 0x17 )
          v120 = 0;
        else
          v120 = dword_9E0268[v119];
        v121 = *(unsigned __int8 *)(v87 + 82);
        v122 = ((int)(v115 << 31) >> 31) & v120;
        if ( v117 )
          v122 = v122 != 0;
        if ( v116 )
          v123 = v122;
        else
          v123 = 0;
        if ( *(_BYTE *)(v87 + 82) )
        {
          v124 = *(_QWORD *)(v87 + 1608);
          if ( v124 )
          {
            v125 = v105;
            v126 = v123;
            v127 = (*(unsigned __int8 *)(v124 + 6) >> 5) - 1;
            if ( (unsigned int)v127 > 6 )
              v128 = 1;
            else
              v128 = dword_9E02C8[v127];
            v471 = v128;
            v460 = 50 * *(unsigned __int8 *)(v124 + 8);
            qdf_trace_msg(
              0x68u,
              8u,
              "%s: esp ba_window_size: %d, ppdu_duration: %d",
              v107,
              v108,
              v109,
              v110,
              v111,
              v112,
              v113,
              v114,
              "cm_calculate_etp_score");
            v123 = v126;
            v105 = v125;
LABEL_119:
            v131 = *(char *)(v87 + 60);
            v132 = *(_QWORD *)(v87 + 1328);
            if ( v481 )
            {
              if ( (unsigned int)(v123 - 1) >= 3 )
                v133 = 234;
              else
                v133 = dword_9E02E4[v123 - 1];
              if ( (v477 & 1) == 0 )
              {
                if ( !v475 )
                {
                  v134 = 20;
LABEL_150:
                  v142 = 5000;
                  v468 = v121;
                  if ( (*(_WORD *)(v89 + 2018) & 2) != 0 && (v143 = *(_QWORD *)(v87 + 1432)) != 0 )
                  {
                    v457 = v14;
                    v144 = *(_QWORD *)(v87 + 1568);
                    v454 = *(char *)(v87 + 60);
                    v145 = *(_QWORD *)(v87 + 1328);
                    v473 = v134;
                    v146 = v133;
                    v464 = v123;
                    *(_DWORD *)v493 = 0;
                    if ( (unsigned int)wlan_mlme_cfg_get_vht_rx_mcs_map(v13, v493) )
                    {
                      v123 = v464;
                      v133 = v146;
                      v134 = v473;
                      v131 = v454;
                      v14 = v457;
                      v142 = 5000;
                      v132 = v145;
                      goto LABEL_154;
                    }
                    LOBYTE(v148) = v493[0];
                    v149 = v144;
                    if ( v105 == 2 )
                    {
                      v133 = v146;
                      v134 = v473;
                      v131 = v454;
                      v14 = v457;
                      v148 = *(_DWORD *)v493 >> 2;
                      v150 = *(unsigned __int16 *)(v143 + 6) >> 2;
                      v132 = v145;
                    }
                    else
                    {
                      v131 = v454;
                      v133 = v146;
                      v132 = v145;
                      if ( v105 == 3 )
                      {
                        v134 = v473;
                        v148 = *(_DWORD *)v493 >> 4;
                        v14 = v457;
                        v150 = *(unsigned __int16 *)(v143 + 6) >> 4;
                      }
                      else
                      {
                        v134 = v473;
                        v14 = v457;
                        if ( v105 == 4 )
                        {
                          v148 = *(_DWORD *)v493 >> 6;
                          v150 = *(unsigned __int16 *)(v143 + 6) >> 6;
                        }
                        else
                        {
                          LOWORD(v150) = *(_WORD *)(v143 + 6);
                        }
                      }
                    }
                    v172 = v148 & 3;
                    v173 = v150 & 3;
                    if ( v172 >= v173 )
                      v172 = v173;
                    if ( v149 )
                    {
                      if ( v172 == 1 )
                        v174 = 7500;
                      else
                        v174 = 5000;
                      v175 = v172 == 2;
                      v176 = 8333;
                    }
                    else
                    {
                      if ( v172 == 1 )
                        v174 = 6000;
                      else
                        v174 = 5000;
                      v175 = v172 == 2;
                      v176 = 6667;
                    }
                    v123 = v464;
                    if ( v175 )
                      v142 = v176;
                    else
                      v142 = v174;
                    if ( v131 >= -96 )
                    {
LABEL_228:
                      v30 = v483;
                      v177 = -3 * v123 + v131 + 80;
                      if ( v177 > 9 )
                      {
                        v179 = 334 * v177;
                      }
                      else
                      {
                        if ( v177 <= -10 )
                          v177 = -10;
                        v178 = v177 + 10;
                        if ( v178 > 0x13 )
                        {
LABEL_500:
                          __break(1u);
                          return ((__int64 (*)(void))util_scan_copy_cache_entry)();
                        }
                        v179 = SNR_DB_TO_BIT_PER_TONE_LUT[v178];
                      }
                      if ( v179 >= v142 )
                        v180 = v142;
                      else
                        v180 = v179;
                      v181 = v133 * v105 * v180;
                      if ( v481 )
                        v182 = v181 / 0xE;
                      else
                        v182 = v181 >> 2;
                      if ( v182 <= 0x3E7 )
                      {
                        v147 = 1;
                        LODWORD(v402) = v182;
                        LODWORD(v405) = 1;
                        LODWORD(v399) = *(_DWORD *)(v87 + 1064);
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "%s(%02x:%02x:%02x:**:**:%02x freq %d): data_rate_kbps %d is less than 1Mbps, so return score %d",
                          v107,
                          v108,
                          v109,
                          v110,
                          v111,
                          v112,
                          v113,
                          v114,
                          "Candidate",
                          *(unsigned __int8 *)(v87 + 1),
                          *(unsigned __int8 *)(v87 + 2),
                          *(unsigned __int8 *)(v87 + 3),
                          *(unsigned __int8 *)(v87 + 6),
                          v399,
                          v402,
                          v405);
LABEL_269:
                        *(_DWORD *)(v87 + 1132) = v147;
                        if ( a4 && (*(_BYTE *)(v89 + 2000) & 1) != 0 )
                        {
                          v147 = *(_DWORD *)(v87 + 1132);
                          if ( *(_DWORD *)a4 == *(_DWORD *)(v87 + 1)
                            && *(unsigned __int16 *)(a4 + 4) == *(unsigned __int16 *)(v87 + 5) )
                          {
                            v204 = *(unsigned __int8 *)(v87 + 1);
                            v205 = *(unsigned __int8 *)(v87 + 2);
                            v206 = *(unsigned __int8 *)(v87 + 3);
                            v207 = *(unsigned __int8 *)(v87 + 6);
                            v208 = *(_DWORD *)(v87 + 1064);
                            v209 = *(char *)(v87 + 60);
                            *(_DWORD *)(v87 + 1132) = v147 + 20000;
                            LODWORD(v405) = v147 + 20000;
                            LODWORD(v402) = v209;
                            LODWORD(v399) = v208;
                            qdf_trace_msg(
                              0x68u,
                              8u,
                              "%s(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d BSSID hint given, give max score %d",
                              v107,
                              v108,
                              v109,
                              v110,
                              v111,
                              v112,
                              v113,
                              v114,
                              "Candidate",
                              v204,
                              v205,
                              v206,
                              v207,
                              v399,
                              v402,
                              v405);
                            v147 = *(_DWORD *)(v87 + 1132);
                          }
                        }
                        LODWORD(v405) = 0;
                        LODWORD(v402) = v147;
                        LODWORD(v399) = *(char *)(v87 + 60);
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "Candidate score(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d score %d, mlo type %d",
                          v107,
                          v108,
                          v109,
                          v110,
                          v111,
                          v112,
                          v113,
                          v114,
                          *(unsigned __int8 *)(v87 + 1),
                          *(unsigned __int8 *)(v87 + 2),
                          *(unsigned __int8 *)(v87 + 3),
                          *(unsigned __int8 *)(v87 + 6),
                          *(unsigned int *)(v87 + 1064),
                          v399,
                          v402,
                          v405);
                        goto LABEL_426;
                      }
                      v452 = v133;
                      v455 = v142;
                      if ( v475 )
                      {
                        v183 = v182;
                        v466 = v123;
                        v184 = ((*(unsigned __int8 *)(v132 + 2) >> 2) & 7) - 1;
                        if ( (unsigned int)v184 > 6 )
                          v185 = 100;
                        else
                          v185 = dword_9E02FC[v184];
                        v493[0] = 0;
                        max_amsdu_num = wlan_mlme_get_max_amsdu_num(v13, v493);
                        v182 = v183;
                        LODWORD(v450) = v460 - v134;
                        HIDWORD(v450) = v185;
                        v190 = v493[0] == 1 && max_amsdu_num == 0;
                        v191 = (v185 + 100 * (v460 - v134) - 1) / v185;
                        if ( v190 )
                          v187 = 7935;
                        else
                          v187 = 3839;
                        v188 = v183 / 0x3E8;
                        v123 = v466;
                        if ( v191 >= (8 * v187 + 208 + v183 / 0x3E8 * (v460 - v134) - 1) / (8 * v187 + 208) )
                          v191 = (8 * v187 + 208 + v183 / 0x3E8 * (v460 - v134) - 1) / (8 * v187 + 208);
                        v448 = v191;
                        if ( v191 <= 1 )
                          v191 = 1;
                        if ( v471 >= v191 )
                          v186 = v191;
                        else
                          v186 = v471;
                      }
                      else
                      {
                        v450 = 0;
                        v186 = 1;
                        v448 = 0;
                        v187 = 1500;
                        v188 = v182 / 0x3E8;
                      }
                      v461 = v187;
                      v458 = v186;
                      v192 = v134 + 4 * ((4 * v188 + v186 * (8 * v187 + 208) - 1) / (4 * v188));
                      v193 = (v192 + v186 * 8 * v187 - 1) / v192 * v468;
                      v194 = v193 / 0xFF;
                      if ( v193 / 0xFF >= 0x4E20 )
                        v194 = 20000;
                      if ( v193 < 0xFF )
                        v147 = 1;
                      else
                        v147 = v194;
                      LODWORD(v418) = v182;
                      LODWORD(v410) = v481;
                      LODWORD(v416) = v123;
                      LODWORD(v414) = *(unsigned __int8 *)(v87 + 84);
                      LODWORD(v412) = v468;
                      LODWORD(v408) = v477;
                      LODWORD(v405) = v475;
                      LODWORD(v402) = *(char *)(v87 + 60);
                      LODWORD(v399) = *(_DWORD *)(v87 + 1064);
                      qdf_trace_msg(
                        0x68u,
                        8u,
                        "%s(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d HT %d VHT %d HE %d ATF %d NSS %d ch_width %d data_rate %d",
                        v107,
                        v108,
                        v109,
                        v110,
                        v111,
                        v112,
                        v113,
                        v114,
                        "Candidate",
                        *(unsigned __int8 *)(v87 + 1),
                        *(unsigned __int8 *)(v87 + 2),
                        *(unsigned __int8 *)(v87 + 3),
                        *(unsigned __int8 *)(v87 + 6),
                        v399,
                        v402,
                        v405,
                        v408,
                        v410,
                        v412,
                        v414,
                        v416,
                        v418);
                      if ( v475 )
                      {
                        LODWORD(v400) = v471;
                        qdf_trace_msg(
                          0x68u,
                          8u,
                          "min_mpdu_ss_us_100x %d max_amsdu %d ppdu_payload_dur_us %d mpdu_per_ampdu %d mpdu_per_ppdu %d ba_window %d",
                          v195,
                          v196,
                          v197,
                          v198,
                          v199,
                          v200,
                          v201,
                          v202,
                          HIDWORD(v450),
                          v461,
                          (unsigned int)v450,
                          v448,
                          v458,
                          v400);
                      }
                      LODWORD(v406) = v147;
                      LODWORD(v403) = v192;
                      LODWORD(v400) = v461;
                      qdf_trace_msg(
                        0x68u,
                        8u,
                        "ETP score: ntone %d phy_hdr_dur_us %d max_bits_per_sc_1000x %d snr_tone_1000x %d mpdu_p_ppdu %d "
                        "max_amsdu %d ppdu_dur_us %d TOTAL %d",
                        v195,
                        v196,
                        v197,
                        v198,
                        v199,
                        v200,
                        v201,
                        v202,
                        v452,
                        v134,
                        v455,
                        v179,
                        v458,
                        v400,
                        v403,
                        v406);
LABEL_268:
                      v30 = v483;
                      goto LABEL_269;
                    }
                  }
                  else
                  {
LABEL_154:
                    if ( v131 >= -96 )
                      goto LABEL_228;
                  }
                  v147 = 1;
                  goto LABEL_268;
                }
LABEL_133:
                v134 = 4 * v105 + 32;
                goto LABEL_150;
              }
            }
            else
            {
              if ( !v477 )
              {
                if ( !v475 )
                {
                  v134 = 20;
                  v133 = 48;
                  goto LABEL_150;
                }
                if ( v123 == 1 )
                  v133 = 108;
                else
                  v133 = 52;
                goto LABEL_133;
              }
              if ( (unsigned int)(v123 - 1) >= 3 )
                v133 = 52;
              else
                v133 = dword_9E02F0[v123 - 1];
            }
            v134 = 4 * v105 + 36;
            goto LABEL_150;
          }
        }
        else if ( *(_BYTE *)(v87 + 83) )
        {
          v129 = v105;
          v130 = v123;
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: qbss_chan_load: %d",
            v107,
            v108,
            v109,
            v110,
            v111,
            v112,
            v113,
            v114,
            "cm_calculate_etp_score");
          v123 = v130;
          v105 = v129;
          v121 = *(unsigned __int8 *)(v87 + 83) ^ 0xFF;
        }
        else
        {
          v121 = 127;
        }
        v471 = 32;
        v460 = 5000;
        goto LABEL_119;
      }
      v48 = v47[3];
      if ( v58 != 3 )
      {
        v15 = v484;
        v59 = 0;
        goto LABEL_35;
      }
      v15 = v484;
      *(_DWORD *)(v48 + 1132) = 1;
      v82 = v47[3];
      if ( v82 == -1 )
      {
        v85 = 0;
        v83 = 0;
        v84 = 0;
        v86 = 0;
      }
      else
      {
        v83 = *(unsigned __int8 *)(v82 + 1);
        v84 = *(unsigned __int8 *)(v82 + 2);
        v85 = *(unsigned __int8 *)(v82 + 3);
        v86 = *(unsigned __int8 *)(v82 + 6);
      }
      LODWORD(v399) = *(char *)(v82 + 60);
      LODWORD(v402) = *(_DWORD *)(v82 + 1132);
      qdf_trace_msg(
        0x68u,
        8u,
        "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d, is in Avoidlist, give min score %d",
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v83,
        v84,
        v85,
        v86,
        *(unsigned int *)(v82 + 1064),
        v399,
        v402);
      v81 = 0;
      v59 = 0;
      v58 = 3;
LABEL_436:
      v354 = v489;
      if ( a5 )
      {
        v355 = (unsigned __int8 *)v47[3];
        if ( a5[3] == v355[4] && a5[4] == v355[5] && a5[5] == v355[6] )
        {
          v356 = v30;
          v357 = v81;
          if ( v355 == (unsigned __int8 *)-1LL )
          {
            v360 = 0;
            v358 = 0;
            v359 = 0;
          }
          else
          {
            v358 = v355[1];
            v359 = v355[2];
            v360 = v355[3];
          }
          qdf_trace_msg(
            0x68u,
            8u,
            "Candidate(%02x:%02x:%02x:**:**:%02x freq %d): boost bss score due to same last 3 byte match",
            v73,
            v74,
            v75,
            v76,
            v77,
            v78,
            v79,
            v80,
            v358,
            v359,
            v360);
          v354 = v489;
          v81 = v357;
          v30 = v356;
          v13 = v486;
          *(_DWORD *)(v47[3] + 1132LL) = 20000;
        }
      }
      if ( (v81 & v354) == 1 )
      {
        if ( v30 )
        {
          v361 = v47[3];
          v362 = *(_QWORD *)(v30 + 24);
          v363 = *(_DWORD *)(v361 + 1132);
          v364 = *(_DWORD *)(v362 + 1132);
          if ( v363 > v364 || v363 == v364 && *(char *)(v361 + 60) > *(char *)(v362 + 60) )
          {
            if ( v362 )
            {
              v365 = *(_QWORD *)(v362 + 1192);
              if ( v365 )
                _qdf_mem_free(v365);
              v366 = *(_QWORD *)(v362 + 1712);
              if ( v366 )
                _qdf_mem_free(v366);
              _qdf_mem_free(v362);
              v361 = v47[3];
            }
            v367 = util_scan_copy_cache_entry(v361);
            *(_QWORD *)(v30 + 24) = v367;
            if ( !v367 )
              goto LABEL_496;
          }
          v27 = v488;
        }
        else
        {
          result = _qdf_mem_malloc(0x20u, "wlan_cm_calculate_bss_score", 3710);
          if ( !result )
            goto LABEL_9;
          v30 = result;
          v368 = util_scan_copy_cache_entry(v47[3]);
          *(_QWORD *)(v30 + 24) = v368;
          if ( !v368 )
            goto LABEL_496;
        }
      }
      if ( (unsigned int)qdf_list_remove_node((__int64)v14, v492) )
      {
        v386 = (unsigned __int8 *)v47[3];
        if ( v386 == (unsigned __int8 *)-1LL )
        {
          v389 = 0;
          v387 = 0;
          v388 = 0;
          v390 = 0;
        }
        else
        {
          v387 = v386[1];
          v388 = v386[2];
          v389 = v386[3];
          v390 = v386[6];
        }
        result = qdf_trace_msg(
                   0x68u,
                   2u,
                   "%s: failed to remove node for BSS %02x:%02x:%02x:**:**:%02x from scan list",
                   v369,
                   v370,
                   v371,
                   v372,
                   v373,
                   v374,
                   v375,
                   v376,
                   "wlan_cm_calculate_bss_score",
                   v387,
                   v388,
                   v389,
                   v390);
        if ( v30 )
        {
          v396 = *(_QWORD *)(v30 + 24);
          if ( v396 )
          {
            v397 = *(_QWORD *)(v396 + 1192);
            if ( v397 )
              _qdf_mem_free(v397);
            v398 = *(_QWORD *)(v396 + 1712);
            if ( v398 )
              _qdf_mem_free(v398);
            _qdf_mem_free(v396);
          }
LABEL_496:
          result = _qdf_mem_free(v30);
          goto LABEL_9;
        }
        goto LABEL_9;
      }
      if ( (unsigned int)(v58 - 1) > 1 )
      {
        result = cm_list_insert_sorted(v14, v47);
      }
      else
      {
        if ( (v59 & 1) == 0 )
        {
          v377 = v47[3];
          if ( v377 == -1 )
          {
            v380 = 0;
            v378 = 0;
            v379 = 0;
            v381 = 0;
          }
          else
          {
            v378 = *(unsigned __int8 *)(v377 + 1);
            v379 = *(unsigned __int8 *)(v377 + 2);
            v380 = *(unsigned __int8 *)(v377 + 3);
            v381 = *(unsigned __int8 *)(v377 + 6);
          }
          LODWORD(v402) = v58;
          LODWORD(v399) = *(char *)(v377 + 60);
          qdf_trace_msg(
            0x68u,
            8u,
            "Candidate( %02x:%02x:%02x:**:**:%02x freq %d): rssi %d, dlm action %d is in Denylist, remove entry",
            v369,
            v370,
            v371,
            v372,
            v373,
            v374,
            v375,
            v376,
            v378,
            v379,
            v380,
            v381,
            *(unsigned int *)(v377 + 1064),
            v399,
            v402);
        }
        v382 = v47[3];
        if ( v382 )
        {
          v383 = *(_QWORD *)(v382 + 1192);
          if ( v383 )
            _qdf_mem_free(v383);
          v384 = *(_QWORD *)(v382 + 1712);
          if ( v384 )
            _qdf_mem_free(v384);
          _qdf_mem_free(v382);
        }
        result = _qdf_mem_free((__int64)v47);
        v27 = v488;
      }
      v29 = v491;
      v491 = nullptr;
      v492 = v29;
      if ( !v29 )
      {
        if ( ((unsigned __int8)v489 & (v30 != 0)) != 1 )
        {
          if ( !v30 )
            goto LABEL_9;
          util_scan_free_cache_entry(*(_QWORD *)(v30 + 24));
          goto LABEL_496;
        }
        v391 = *(_QWORD *)(v30 + 24);
        if ( v391 == -1 )
        {
          v394 = 0;
          v392 = 0;
          v393 = 0;
          v395 = 0;
        }
        else
        {
          v392 = *(unsigned __int8 *)(v391 + 1);
          v393 = *(unsigned __int8 *)(v391 + 2);
          v394 = *(unsigned __int8 *)(v391 + 3);
          v395 = *(unsigned __int8 *)(v391 + 6);
        }
        LODWORD(v399) = *(char *)(v391 + 60);
        qdf_trace_msg(
          0x68u,
          8u,
          "All candidates in denylist, Candidate( %02x:%02x:%02x:**:**:%02x freq %d): rssi %d, selected for connection",
          v31,
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v392,
          v393,
          v394,
          v395,
          *(unsigned int *)(v391 + 1064),
          v399);
        result = cm_list_insert_sorted(v14, v30);
        goto LABEL_9;
      }
    }
    LOBYTE(v49) = 0;
LABEL_26:
    if ( (v27[2000] & 2) == 0 )
      goto LABEL_33;
    goto LABEL_27;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
