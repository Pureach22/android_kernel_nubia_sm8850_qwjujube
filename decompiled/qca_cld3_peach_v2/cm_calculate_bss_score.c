__int64 __fastcall cm_calculate_bss_score(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        __int64 a5,
        _QWORD *a6,
        int a7)
{
  __int64 *v7; // x25
  __int64 v13; // x26
  __int64 cmpt_obj; // x0
  __int64 v15; // x21
  __int64 v16; // x24
  int v17; // w16
  int v18; // w11
  int v19; // w10
  int v20; // w13
  unsigned int v21; // w8
  unsigned int v22; // w12
  int v23; // w15
  int v24; // w14
  unsigned int v25; // w9
  unsigned int v26; // w0
  unsigned int v27; // w16
  int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  unsigned int v37; // w10
  int v38; // w8
  unsigned int v39; // w27
  unsigned __int8 sta_mlo_conn_max_num; // w0
  __int64 v41; // x22
  __int64 v42; // x20
  __int64 v43; // x21
  char v44; // w10
  __int64 *v45; // x27
  unsigned __int8 *v46; // x28
  unsigned __int64 v47; // x25
  __int64 entry; // x0
  unsigned int v49; // w23
  __int64 v50; // x24
  __int64 v51; // x3
  __int64 v52; // x4
  __int64 v53; // x5
  __int64 v54; // x6
  int v55; // w0
  unsigned __int64 v56; // x16
  int v57; // w8
  unsigned int v58; // w9
  __int64 v59; // x14
  unsigned int v60; // w0
  unsigned int v61; // w17
  __int64 v62; // x23
  char v63; // w26
  char v64; // w16
  unsigned int v65; // w24
  unsigned __int8 v66; // w22
  char v67; // w17
  unsigned int v68; // w8
  int v69; // w20
  unsigned __int8 v70; // w27
  unsigned int v71; // w8
  __int64 v72; // x8
  int v73; // w28
  int v74; // w0
  unsigned int v75; // w20
  int v76; // w22
  char v77; // w8
  int v78; // w12
  unsigned int v79; // w13
  unsigned int v80; // w22
  bool v81; // zf
  int v82; // w20
  char is_hw_dbs_capable; // w0
  int v84; // w8
  char is_24ghz_ch_freq; // w0
  __int16 v86; // w8
  int v87; // w27
  int v88; // w8
  __int16 v89; // w9
  int v90; // w17
  char v91; // w14
  char v92; // w13
  _BOOL4 v93; // w12
  int v94; // w15
  int v95; // w11
  bool v96; // vf
  int v97; // w15
  __int64 v98; // x15
  __int64 v99; // x14
  __int64 v100; // x14
  int v101; // w24
  int v102; // w13
  int v103; // w8
  int v104; // w25
  unsigned int v105; // w8
  __int64 v106; // x8
  int v107; // w10
  int v108; // w11
  __int64 v109; // x4
  __int64 v110; // x5
  __int64 v111; // x6
  int v112; // w8
  __int64 v113; // x7
  const char *v114; // x3
  const char *v115; // x2
  unsigned int v116; // w8
  __int64 v117; // x9
  unsigned int v118; // w10
  unsigned int v119; // w10
  _BYTE *v120; // x9
  unsigned int v121; // w22
  __int64 v122; // x11
  unsigned int v123; // w10
  unsigned int v124; // w10
  unsigned int v125; // w9
  unsigned __int8 v126; // w20
  __int64 v127; // x8
  unsigned int v128; // w0
  unsigned int v129; // w23
  char v130; // w8
  char v131; // w10
  unsigned int v132; // w9
  unsigned __int8 v133; // w8
  char *v134; // x9
  __int64 *v135; // x11
  __int64 v136; // x12
  __int64 v137; // x12
  __int64 v138; // x14
  __int64 v139; // x15
  __int64 v140; // x12
  __int64 v141; // x13
  __int64 v142; // x14
  __int64 v143; // x12
  char v144; // t1
  __int64 v145; // x12
  __int64 v146; // x13
  __int64 v147; // x13
  unsigned int v148; // w9
  unsigned int v149; // w10
  _BYTE *v150; // x9
  __int64 v151; // x11
  unsigned int v152; // w10
  unsigned int v153; // w11
  int v154; // w13
  char v155; // w12
  unsigned int v156; // w10
  int v157; // w14
  int v158; // w15
  unsigned int v159; // w9
  char v160; // w11
  unsigned int v161; // w10
  unsigned int v162; // w12
  unsigned int v163; // w9
  int v164; // w12
  unsigned int v165; // w9
  unsigned int v166; // w9
  _BYTE *v167; // x8
  __int64 v168; // x10
  unsigned int v169; // w9
  __int64 v170; // x1
  int v171; // w22
  int v172; // w24
  unsigned __int8 *v173; // x0
  double v174; // d0
  double v175; // d1
  double v176; // d2
  double v177; // d3
  double v178; // d4
  double v179; // d5
  double v180; // d6
  double v181; // d7
  unsigned __int8 *v182; // x0
  __int64 v183; // x23
  int v184; // w26
  unsigned int v185; // w20
  unsigned int v186; // w25
  unsigned int v187; // w27
  int v188; // w22
  unsigned int v189; // w8
  unsigned int v190; // w10
  unsigned int v191; // w9
  int v192; // w23
  unsigned __int64 v193; // x10
  int v194; // w9
  unsigned __int64 v195; // x20
  int v196; // w9
  int v197; // w9
  unsigned int v198; // w27
  unsigned int v199; // w25
  int v200; // w22
  char v201; // w10
  unsigned int v202; // w8
  unsigned int v203; // w25
  int v204; // w9
  int v205; // w21
  const char *v206; // x3
  char is_eht_allowed_for_current_security; // w0
  int v208; // w0
  unsigned int v209; // w11
  __int64 v210; // x11
  __int64 *v211; // x12
  __int64 v212; // x13
  __int64 v213; // x10
  __int64 v214; // x10
  __int64 v215; // x10
  __int64 v216; // x10
  __int64 v217; // x11
  __int64 v218; // x13
  __int64 v219; // x11
  int v220; // w8
  __int64 v221; // x9
  int v222; // w10
  __int64 v223; // x12
  _QWORD *v224; // x10
  __int64 v225; // x13
  __int64 v226; // x11
  __int64 v227; // x11
  __int64 v228; // x13
  __int64 v229; // x12
  __int64 v230; // x14
  __int64 v231; // x12
  __int64 v232; // x13
  __int64 v233; // x11
  __int64 v234; // x12
  __int64 v235; // x13
  __int64 v236; // x11
  int v237; // w9
  __int64 v238; // x9
  unsigned int v239; // w10
  unsigned __int64 v240; // x11
  __int64 v241; // x9
  __int64 v243; // x4
  __int64 v244; // x5
  __int64 v245; // x6
  __int64 v246; // x7
  int v247; // w10
  int v248; // w11
  int v249; // w8
  const char *v250; // x3
  unsigned int v252; // w20
  int v253; // w23
  unsigned int v254; // w8
  bool v255; // cf
  __int64 v256; // x27
  int v257; // w8
  __int64 v258; // x0
  unsigned int v259; // w23
  double v260; // d0
  double v261; // d1
  double v262; // d2
  double v263; // d3
  double v264; // d4
  double v265; // d5
  double v266; // d6
  double v267; // d7
  int v268; // w0
  __int64 v269; // x23
  char v270; // w22
  unsigned __int16 v271; // w0
  __int64 v272; // x4
  unsigned __int16 op_class_width; // w23
  double v274; // d0
  double v275; // d1
  double v276; // d2
  double v277; // d3
  double v278; // d4
  double v279; // d5
  double v280; // d6
  double v281; // d7
  int v282; // w24
  int v283; // w16
  int v284; // w12
  int v285; // w13
  int v286; // w15
  unsigned __int64 v287; // x2
  unsigned int v288; // w9
  unsigned int v289; // w11
  int v290; // w10
  unsigned int v291; // w8
  int v292; // w14
  unsigned int v293; // w0
  unsigned int v294; // w16
  unsigned int v295; // w0
  unsigned int v296; // w17
  char v297; // w17
  unsigned __int8 v298; // w16
  char v299; // w0
  unsigned int v301; // w8
  unsigned int v302; // w8
  unsigned int v303; // w0
  unsigned int v304; // w23
  unsigned int v305; // w9
  unsigned int v306; // w26
  unsigned int v307; // w9
  int v308; // w22
  double v309; // d0
  double v310; // d1
  double v311; // d2
  double v312; // d3
  double v313; // d4
  double v314; // d5
  double v315; // d6
  double v316; // d7
  char v317; // w8
  unsigned int v318; // w13
  int v319; // w6
  int v320; // w11
  int v321; // w12
  int v322; // w14
  int v323; // w8
  unsigned int v324; // w10
  unsigned int v325; // w11
  unsigned int v326; // w12
  unsigned int v327; // w20
  int v328; // w8
  unsigned int v329; // w9
  unsigned int v330; // w10
  __int64 v331; // x11
  __int64 v332; // x12
  __int64 *v333; // x11
  __int64 v334; // x13
  __int64 v335; // x13
  __int64 v336; // x14
  __int64 v337; // x10
  __int64 v338; // x15
  __int64 v339; // x12
  __int64 v340; // x16
  __int64 v341; // x10
  __int64 v342; // x17
  __int64 v343; // x0
  __int64 v344; // x15
  int v345; // w8
  __int64 v346; // x9
  int v347; // w10
  __int64 v348; // x12
  __int64 *v349; // x10
  __int64 v350; // x13
  __int64 v351; // x11
  __int64 v352; // x11
  __int64 v353; // x13
  __int64 v354; // x12
  __int64 v355; // x14
  __int64 v356; // x12
  __int64 v357; // x13
  __int64 v358; // x11
  __int64 v359; // x12
  __int64 v360; // x13
  __int64 v361; // x11
  int v362; // w20
  int v363; // w22
  __int64 v364; // x0
  unsigned int v365; // w22
  int v366; // w20
  int v367; // w23
  __int64 v368; // x8
  __int64 v369; // x9
  __int64 v370; // x10
  __int64 v371; // x8
  __int64 v372; // x9
  __int64 v373; // x8
  __int64 v374; // x10
  __int64 v375; // x8
  __int64 v376; // x9
  __int64 v377; // x8
  __int64 v378; // x9
  __int64 v379; // x8
  __int64 v380; // x8
  __int64 v381; // x8
  __int64 v382; // x8
  __int64 v383; // [xsp+0h] [xbp-1F0h]
  __int64 v384; // [xsp+8h] [xbp-1E8h]
  __int64 v385; // [xsp+10h] [xbp-1E0h]
  __int64 v386; // [xsp+18h] [xbp-1D8h]
  __int64 v387; // [xsp+20h] [xbp-1D0h]
  __int64 v388; // [xsp+28h] [xbp-1C8h]
  __int64 v389; // [xsp+30h] [xbp-1C0h]
  __int64 v390; // [xsp+38h] [xbp-1B8h]
  __int64 v391; // [xsp+40h] [xbp-1B0h]
  __int64 v392; // [xsp+48h] [xbp-1A8h]
  __int64 v393; // [xsp+50h] [xbp-1A0h]
  __int64 v394; // [xsp+58h] [xbp-198h]
  __int64 v395; // [xsp+60h] [xbp-190h]
  __int64 v396; // [xsp+68h] [xbp-188h]
  __int64 v397; // [xsp+70h] [xbp-180h]
  __int64 v398; // [xsp+78h] [xbp-178h]
  __int64 v399; // [xsp+80h] [xbp-170h]
  __int64 v400; // [xsp+88h] [xbp-168h]
  __int64 v401; // [xsp+90h] [xbp-160h]
  __int64 *v402; // [xsp+A0h] [xbp-150h]
  unsigned int v403; // [xsp+A8h] [xbp-148h]
  unsigned int v404; // [xsp+ACh] [xbp-144h]
  unsigned int v405; // [xsp+B0h] [xbp-140h]
  int v406; // [xsp+B4h] [xbp-13Ch]
  __int64 v407; // [xsp+B8h] [xbp-138h]
  __int64 v408; // [xsp+B8h] [xbp-138h]
  unsigned __int16 ch_width; // [xsp+C4h] [xbp-12Ch]
  int v410; // [xsp+C4h] [xbp-12Ch]
  int v411; // [xsp+C8h] [xbp-128h]
  int v412; // [xsp+C8h] [xbp-128h]
  int v413; // [xsp+CCh] [xbp-124h]
  int v414; // [xsp+D0h] [xbp-120h]
  unsigned int v415; // [xsp+D0h] [xbp-120h]
  int v416; // [xsp+D4h] [xbp-11Ch]
  int v417; // [xsp+D4h] [xbp-11Ch]
  int v418; // [xsp+D8h] [xbp-118h]
  int v419; // [xsp+D8h] [xbp-118h]
  unsigned int v420; // [xsp+DCh] [xbp-114h]
  int v421; // [xsp+DCh] [xbp-114h]
  int v422; // [xsp+E0h] [xbp-110h]
  int v423; // [xsp+E8h] [xbp-108h]
  int v424; // [xsp+E8h] [xbp-108h]
  int v425; // [xsp+E8h] [xbp-108h]
  int v426; // [xsp+F0h] [xbp-100h]
  int v427; // [xsp+F0h] [xbp-100h]
  char v428; // [xsp+F0h] [xbp-100h]
  char v429; // [xsp+FCh] [xbp-F4h]
  int v430; // [xsp+FCh] [xbp-F4h]
  unsigned int v431; // [xsp+FCh] [xbp-F4h]
  __int64 v432; // [xsp+100h] [xbp-F0h]
  int v433; // [xsp+100h] [xbp-F0h]
  unsigned int v434; // [xsp+100h] [xbp-F0h]
  unsigned int v435; // [xsp+100h] [xbp-F0h]
  unsigned int v436; // [xsp+108h] [xbp-E8h]
  __int64 v437; // [xsp+110h] [xbp-E0h]
  __int64 v438; // [xsp+118h] [xbp-D8h]
  unsigned int v439; // [xsp+124h] [xbp-CCh]
  unsigned int v440; // [xsp+124h] [xbp-CCh]
  int v441; // [xsp+124h] [xbp-CCh]
  __int64 v442; // [xsp+128h] [xbp-C8h]
  unsigned int v443; // [xsp+130h] [xbp-C0h]
  _QWORD *v444; // [xsp+138h] [xbp-B8h]
  int v445; // [xsp+140h] [xbp-B0h] BYREF
  char v446[4]; // [xsp+144h] [xbp-ACh] BYREF
  int v447; // [xsp+148h] [xbp-A8h] BYREF
  _BYTE v448[4]; // [xsp+14Ch] [xbp-A4h] BYREF
  __int64 v449; // [xsp+150h] [xbp-A0h] BYREF
  __int64 v450; // [xsp+158h] [xbp-98h]
  __int64 v451; // [xsp+160h] [xbp-90h]
  __int64 v452; // [xsp+168h] [xbp-88h]
  __int64 v453; // [xsp+170h] [xbp-80h]
  __int64 v454; // [xsp+178h] [xbp-78h]
  int v455; // [xsp+180h] [xbp-70h]
  __int16 v456; // [xsp+184h] [xbp-6Ch]
  __int64 v457; // [xsp+188h] [xbp-68h]
  unsigned int v458; // [xsp+190h] [xbp-60h]
  __int64 v459; // [xsp+198h] [xbp-58h] BYREF
  unsigned int v460; // [xsp+1A0h] [xbp-50h]
  __int64 v461; // [xsp+1A8h] [xbp-48h] BYREF
  int v462; // [xsp+1B0h] [xbp-40h]
  __int64 v463; // [xsp+1B8h] [xbp-38h]
  unsigned int v464; // [xsp+1C0h] [xbp-30h]
  __int64 v465; // [xsp+1C8h] [xbp-28h]
  __int64 v466; // [xsp+1D0h] [xbp-20h]
  __int64 v467; // [xsp+1D8h] [xbp-18h]
  __int64 v468; // [xsp+1E0h] [xbp-10h]

  LODWORD(v7) = a7;
  v13 = a1;
  v468 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v445 = 0;
  cmpt_obj = wlan_psoc_mlme_get_cmpt_obj(a1);
  if ( !cmpt_obj )
  {
    LODWORD(a2) = 0;
    goto LABEL_297;
  }
  v15 = cmpt_obj;
  LODWORD(v16) = cm_bss_mlo_type(v13, a3, a6);
  if ( (*(_BYTE *)(v15 + 2048) & 4) != 0 )
  {
    v28 = cm_calculate_etp_score(v13, a3, v15 + 2068, (unsigned int)v16, (unsigned int)v7);
    v37 = v16 - 1;
    LODWORD(a2) = v28;
    v38 = v28;
    *(_DWORD *)(a3 + 1260) = v28;
    if ( (unsigned int)(v16 - 1) > 2 )
      goto LABEL_277;
    LODWORD(v438) = v16 - 1;
    LODWORD(v466) = 0;
    v465 = 0;
    v464 = 0;
    v463 = 0;
    LOBYTE(v459) = 0;
    BYTE2(v461) = 0;
    LOWORD(v461) = 0;
    wlan_psoc_mlme_get_11be_capab(v13, &v459);
    if ( (unsigned __int8)v459 != 1 )
      goto LABEL_276;
    v39 = *(unsigned __int8 *)(a3 + 1918);
    sta_mlo_conn_max_num = wlan_mlme_get_sta_mlo_conn_max_num(v13);
    if ( !v39 )
      goto LABEL_276;
    v444 = a6;
    if ( v39 >= 3 )
      v41 = 3;
    else
      v41 = v39;
    LODWORD(v42) = *(_DWORD *)(a3 + 1192);
    v436 = v39;
    v432 = v15;
    v43 = v13;
    v13 = 0;
    v44 = 0;
    v45 = (__int64 *)(a3 + 1920);
    v423 = a2;
    v442 = a5;
    v426 = (int)v7;
    v439 = v16;
    v437 = a3 + 1920;
    v443 = sta_mlo_conn_max_num;
LABEL_20:
    v46 = (unsigned __int8 *)(v437 + 48 * v13);
    v47 = 4 * v13;
    v429 = v44;
    while ( 1 )
    {
      if ( v46[40] == 1 )
      {
        entry = cm_get_entry(v444, (__int64)v46, a3 + 1912);
        if ( entry )
        {
          if ( v47 > 0xB )
            goto LABEL_446;
          v49 = *(_DWORD *)(entry + 1192);
          v50 = entry;
          *((_DWORD *)&v465 + v13) = v49;
          if ( (policy_mgr_2_freq_always_on_same_mac(v43, v49, (unsigned int)v42) & 1) == 0 )
          {
            v55 = cm_calculate_etp_score(v43, v50, v432 + 2068, v439, 0);
            v44 = 1;
            *((_DWORD *)&v463 + v13) = v55;
            v81 = v41 - 1 == v13++;
            if ( !v81 )
              goto LABEL_20;
LABEL_42:
            v57 = v463;
            if ( (unsigned __int8)v436 == 1 )
            {
              LODWORD(v16) = v439;
              v15 = v432;
              v58 = 0;
              LOBYTE(v7) = v426;
              a5 = v442;
              LODWORD(a2) = v423;
              v59 = a3 + 1920;
              goto LABEL_264;
            }
            v209 = HIDWORD(v463);
            LODWORD(v16) = v439;
            v15 = v432;
            LOBYTE(v7) = v426;
            a5 = v442;
            LODWORD(a2) = v423;
            v59 = a3 + 1920;
            v58 = (unsigned int)v463 < HIDWORD(v463);
            if ( (unsigned int)v463 > HIDWORD(v463) )
              v209 = v463;
            if ( (unsigned __int8)v436 == 2 )
              goto LABEL_264;
            if ( v209 < v464 )
              v58 = 2;
            if ( (unsigned __int8)v436 >= 3u )
            {
LABEL_264:
              if ( v58 )
              {
                v210 = *(_QWORD *)(a3 + 1944);
                v211 = (__int64 *)(v59 + 48LL * v58);
                v451 = *(_QWORD *)(a3 + 1936);
                v452 = v210;
                v212 = *(_QWORD *)(a3 + 1960);
                v453 = *(_QWORD *)(a3 + 1952);
                v454 = v212;
                v213 = *(_QWORD *)(a3 + 1928);
                v449 = *v45;
                v450 = v213;
                v214 = v211[3];
                *(_QWORD *)(a3 + 1936) = v211[2];
                *(_QWORD *)(a3 + 1944) = v214;
                v215 = v211[5];
                *(_QWORD *)(a3 + 1952) = v211[4];
                *(_QWORD *)(a3 + 1960) = v215;
                v216 = v211[1];
                *v45 = *v211;
                *(_QWORD *)(a3 + 1928) = v216;
                v217 = v450;
                *v211 = v449;
                v211[1] = v217;
                v218 = v454;
                v211[4] = v453;
                v211[5] = v218;
                v219 = v452;
                v211[2] = v451;
                v211[3] = v219;
                *((_DWORD *)&v463 + v58) = v57;
              }
              LODWORD(v463) = 0;
              if ( (unsigned __int8)v436 == 1 )
                goto LABEL_276;
              v220 = HIDWORD(v463);
              v221 = 1;
              if ( (unsigned __int8)v436 > 2u && HIDWORD(v463) < v464 )
                v222 = 2;
              else
                v222 = 1;
              if ( (unsigned __int8)v436 > 2u && HIDWORD(v463) < v464 )
                v221 = 2;
              if ( v222 != 1 )
              {
                v223 = *(_QWORD *)(a3 + 1992);
                v224 = (_QWORD *)(v59 + 48 * v221);
                v225 = *(_QWORD *)(a3 + 2000);
                v451 = *(_QWORD *)(a3 + 1984);
                v452 = v223;
                v226 = *(_QWORD *)(a3 + 2008);
                v453 = v225;
                v454 = v226;
                v227 = *(_QWORD *)(a3 + 1968);
                v228 = v224[1];
                *(_QWORD *)(a3 + 1968) = *v224;
                v229 = *(_QWORD *)(a3 + 1976);
                *(_QWORD *)(a3 + 1976) = v228;
                v449 = v227;
                v450 = v229;
                v230 = v224[4];
                v232 = v224[2];
                v231 = v224[3];
                *(_QWORD *)(a3 + 2008) = v224[5];
                *(_QWORD *)(a3 + 1992) = v231;
                v234 = v453;
                v233 = v454;
                *(_QWORD *)(a3 + 1984) = v232;
                *(_QWORD *)(a3 + 2000) = v230;
                v224[4] = v234;
                v224[5] = v233;
                v235 = v452;
                v224[2] = v451;
                v224[3] = v235;
                v236 = v450;
                *v224 = v449;
                v224[1] = v236;
                *((_DWORD *)&v463 + v221) = v220;
              }
              HIDWORD(v463) = 0;
              if ( (unsigned __int8)v436 == 2 || (v464 = 0, (unsigned __int8)v436 >= 3u) )
              {
LABEL_276:
                v38 = *(_DWORD *)(a3 + 1260);
                v37 = v438;
LABEL_277:
                if ( *(_QWORD *)(a3 + 1824) )
                {
                  if ( v37 > 2 )
                    v237 = 5;
                  else
                    v237 = dword_AD1E98[v37];
                  v238 = 1374389535LL * v237 * v38;
                  v239 = *(unsigned __int8 *)(a3 + 1918);
                  v240 = (unsigned __int64)v238 >> 63;
                  v241 = v238 >> 37;
                  if ( v239 <= 1 )
                    v239 = 1;
                  *(_DWORD *)(a3 + 1260) = v38 + (v241 + v240) * v239;
                  if ( a5 )
                  {
LABEL_286:
                    if ( (*(_BYTE *)(v15 + 2048) & 1) != 0
                      && *(_DWORD *)a5 == *(_DWORD *)(a3 + 1)
                      && *(unsigned __int16 *)(a5 + 4) == *(unsigned __int16 *)(a3 + 5) )
                    {
                      LODWORD(a2) = 20000;
                      v243 = *(unsigned __int8 *)(a3 + 1);
                      v244 = *(unsigned __int8 *)(a3 + 2);
                      v245 = *(unsigned __int8 *)(a3 + 3);
                      v246 = *(unsigned __int8 *)(a3 + 6);
                      v247 = *(_DWORD *)(a3 + 1192);
                      v248 = *(char *)(a3 + 60);
                      v249 = *(_DWORD *)(a3 + 1260) + 20000;
                      if ( ((unsigned __int8)v7 & 2) != 0 )
                        v250 = "Candidate";
                      else
                        v250 = "Partner";
                      *(_DWORD *)(a3 + 1260) = v249;
                      LODWORD(v383) = v247;
                      qdf_trace_msg(
                        0x68u,
                        8u,
                        "%s(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d BSSID hint given, give max score %d",
                        v29,
                        v30,
                        v31,
                        v32,
                        v33,
                        v34,
                        v35,
                        v36,
                        v250,
                        v243,
                        v244,
                        v245,
                        v246,
                        v383,
                        v248,
                        v249);
                    }
                  }
                }
                else
                {
                  LODWORD(v383) = v16;
                  qdf_trace_msg(
                    0x68u,
                    8u,
                    "%s: %02x:%02x:%02x:**:**:%02xentry with mlo type %d",
                    v29,
                    v30,
                    v31,
                    v32,
                    v33,
                    v34,
                    v35,
                    v36,
                    "cm_vendor_specific_boost",
                    *(unsigned __int8 *)(a3 + 1),
                    *(unsigned __int8 *)(a3 + 2),
                    *(unsigned __int8 *)(a3 + 3),
                    *(unsigned __int8 *)(a3 + 6),
                    v383);
                  if ( a5 )
                    goto LABEL_286;
                }
                LODWORD(v385) = v16;
                LODWORD(v383) = *(char *)(a3 + 60);
                LODWORD(v384) = *(_DWORD *)(a3 + 1260);
                qdf_trace_msg(
                  0x68u,
                  8u,
                  "Candidate score(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d score %d, mlo type %d",
                  v29,
                  v30,
                  v31,
                  v32,
                  v33,
                  v34,
                  v35,
                  v36,
                  *(unsigned __int8 *)(a3 + 1),
                  *(unsigned __int8 *)(a3 + 2),
                  *(unsigned __int8 *)(a3 + 3),
                  *(unsigned __int8 *)(a3 + 6),
                  *(unsigned int *)(a3 + 1192),
                  v383,
                  v384,
                  v385);
                goto LABEL_297;
              }
            }
LABEL_446:
            __break(1u);
          }
        }
        else
        {
          if ( v47 > 0xB )
            goto LABEL_446;
          v49 = *((unsigned __int16 *)v46 + 3);
          *((_DWORD *)&v465 + v13) = v49;
          if ( (policy_mgr_2_freq_always_on_same_mac(v43, v49, (unsigned int)v42) & 1) == 0 )
            goto LABEL_22;
        }
        *((_DWORD *)&v463 + v13) = 0;
        if ( (wlan_mlme_is_5gl_5gh_mlsr_supported(v43) & 1) == 0 )
        {
          if ( v46 )
          {
            v51 = *v46;
            v52 = v46[1];
            v53 = v46[2];
            v54 = v46[5];
          }
          else
          {
            v53 = 0;
            v51 = 0;
            v52 = 0;
            v54 = 0;
          }
          LODWORD(v383) = v42;
          qdf_trace_msg(
            0x68u,
            8u,
            "Partner(%02x:%02x:%02x:**:**:%02x freq %d): assoc freq %d can't be MLMR",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v51,
            v52,
            v53,
            v54,
            v49,
            v383);
          if ( v443 < 3 || *(unsigned __int8 *)(a3 + 1918) <= 1u )
            v46[40] = 0;
        }
      }
LABEL_22:
      ++v13;
      v47 += 4LL;
      v46 += 48;
      if ( v41 == v13 )
      {
        if ( (v429 & 1) == 0 )
        {
          qdf_trace_msg(
            0x68u,
            8u,
            "%s: None of the partners have been scored, re-order the links",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "cm_sort_vendor_algo_mlo_bss_entry");
          LOBYTE(v461) = policy_mgr_2_freq_always_on_same_mac(v43, (unsigned int)v465, (unsigned int)v42) & 1;
          if ( (unsigned __int8)v436 != 1 )
          {
            BYTE1(v461) = policy_mgr_2_freq_always_on_same_mac(v43, HIDWORD(v465), (unsigned int)v42) & 1;
            if ( (unsigned __int8)v436 != 2 )
              BYTE2(v461) = policy_mgr_2_freq_always_on_same_mac(v43, (unsigned int)v466, (unsigned int)v42) & 1;
          }
          LODWORD(v16) = v439;
          v15 = v432;
          v133 = -1;
          LODWORD(v7) = v426;
          a5 = v442;
          v134 = (char *)&v461;
          LODWORD(a2) = v423;
          while ( 1 )
          {
            v144 = *v134++;
            if ( (v144 & 1) == 0 )
            {
              v145 = v45[3];
              ++v133;
              v451 = v45[2];
              v452 = v145;
              v146 = v45[5];
              v453 = v45[4];
              v454 = v146;
              v147 = v45[1];
              v449 = *v45;
              v450 = v147;
              if ( v133 > 3u )
                goto LABEL_164;
              v135 = (__int64 *)(v437 + 48LL * v133);
              v136 = v135[1];
              *v45 = *v135;
              v45[1] = v136;
              v137 = v135[5];
              v138 = v135[2];
              v139 = v135[3];
              v45[4] = v135[4];
              v45[5] = v137;
              v140 = v451;
              v141 = v452;
              v45[2] = v138;
              v45[3] = v139;
              v135[2] = v140;
              v135[3] = v141;
              v142 = v454;
              v135[4] = v453;
              v135[5] = v142;
              v143 = v450;
              *v135 = v449;
              v135[1] = v143;
            }
            --v41;
            v45 += 6;
            if ( !v41 )
              goto LABEL_276;
          }
        }
        goto LABEL_42;
      }
    }
  }
  v442 = a5;
  LOBYTE(v443) = (_BYTE)v7;
  if ( ((unsigned __int8)v7 & 1) != 0
    || (unsigned int)v16 <= 4 && (_DWORD)v16 != 3
    || (wlan_cm_is_eht_allowed_for_current_security(v13, a3, 0) & 1) == 0
    || ((unsigned __int8)v7 & 2) != 0
    && *(_QWORD *)(a3 + 1824)
    && *(_QWORD *)(a3 + 1840)
    && (unsigned int)wlan_t2lm_validate_candidate(a3) )
  {
    v17 = *(unsigned __int8 *)(v15 + 1948);
    v18 = *(char *)(a3 + 60);
    v19 = *(unsigned __int8 *)(v15 + 1949);
    v20 = *(unsigned __int8 *)(v15 + 1950);
    v21 = *(unsigned __int8 *)(v15 + 1951);
    v22 = *(unsigned __int8 *)(v15 + 1954);
    v23 = -v19;
    v24 = -v20;
    LODWORD(v444) = 100 * *(unsigned __int8 *)(v15 + 1920);
    v25 = *(unsigned __int8 *)(v15 + 1952);
    if ( -v17 >= v18 )
    {
      if ( v24 >= v18 )
      {
        v56 = (42949673 * (unsigned __int64)((unsigned int)v444 * v25)) >> 32;
      }
      else
      {
        if ( v23 >= v18 )
        {
          v60 = v21
              - v25
              + ((char)((v20 - v19) / v22 + 1 + ((unsigned __int8)(((v20 - v19) / v22 + 1) & 0x80) >> 7)) >> 1);
          v61 = ~((char)(v23 - v18) / v22);
          v27 = v21 + v60 / (char)((v20 - v19) / v22 + 1) * v61;
          if ( v25 > (char)(v21 + v60 / (char)((v20 - v19) / v22 + 1) * v61) )
            LOBYTE(v27) = *(_BYTE *)(v15 + 1952);
        }
        else
        {
          v26 = *(unsigned __int8 *)(v15 + 1953);
          v27 = (((char)((v19 - v17) / v26 + 1 + ((((v19 - v17) / v26 + 1) & 0x80) >> 7)) >> 1) - v21 + 100)
              / (char)((v19 - v17) / v26 + 1)
              * ~((char)(-(char)v17 - v18) / v26)
              + 100;
          if ( v21 > (char)v27 )
            LOBYTE(v27) = *(_BYTE *)(v15 + 1951);
        }
        LODWORD(v56) = (char)v27 * (int)v444 / 100;
      }
      LODWORD(v444) = v56;
    }
    v62 = v13;
    v63 = (char)v7;
    LODWORD(v7) = v16;
    v64 = v23 - v18;
    if ( v23 >= v18 )
    {
      v67 = *(_BYTE *)(v15 + 1955);
      v66 = 0;
      v65 = a4;
      if ( v18 >= (char)-v67
        && (unsigned __int16)(v64 / (char)v22) != (unsigned __int16)((char)(v67 - v19) / (char)v22)
        && v24 < v18 )
      {
        v68 = v21
            + (v21
             - v25
             + ((char)((v20 - v19) / v22 + 1 + ((unsigned __int8)(((v20 - v19) / v22 + 1) & 0x80) >> 7)) >> 1))
            / (char)((v20 - v19) / v22 + 1)
            * ~(v64 / v22);
        if ( v25 <= (char)v68 )
          v66 = v68;
        else
          v66 = *(_BYTE *)(v15 + 1952);
      }
    }
    else
    {
      v65 = a4;
      v66 = 100;
    }
    v69 = *(unsigned __int8 *)(v15 + 1924);
    v70 = v66;
    v71 = (unsigned __int8)((unsigned __int16)cm_get_ch_width(a3, v15 + 2068) / 0x14u - 1);
    if ( v71 >= 0xF )
      v71 = 15;
    v72 = 1374389535LL * v69 * v66 * link_bw_score[v71];
    v73 = (v72 >> 37) + ((unsigned __int64)v72 >> 63);
    v74 = cm_calculate_congestion_score(a3, v15 + 1920, &v445, 0);
    v75 = *(_DWORD *)(a3 + 1192);
    LODWORD(v437) = v74;
    LODWORD(v438) = v73;
    v76 = v73 + (_DWORD)v444 + 80 * v74 / 0x64u;
    if ( (wlan_reg_is_5ghz_ch_freq(v75) & 1) != 0 )
    {
      v77 = 8;
      LOBYTE(a2) = v70;
    }
    else if ( (wlan_reg_is_24ghz_ch_freq(v75) & 1) != 0 )
    {
      v77 = 0;
      LOBYTE(a2) = v70;
    }
    else
    {
      LOBYTE(a2) = v70;
      if ( (wlan_reg_is_6ghz_chan_freq(v75) & 1) == 0 )
      {
        v78 = 0;
        a4 = v65;
LABEL_65:
        LODWORD(v16) = (_DWORD)v7;
        LOBYTE(v7) = v63;
        v13 = v62;
        a5 = v442;
        v79 = 0;
        v80 = v76 + v78;
        if ( !v442 )
          goto LABEL_71;
        goto LABEL_66;
      }
      v77 = 16;
    }
    a4 = v65;
    v78 = (unsigned __int8)(*(_DWORD *)(v15 + 2044) >> v77) * *(unsigned __int8 *)(v15 + 1925);
    goto LABEL_65;
  }
  v466 = 0;
  v467 = 0;
  v465 = 0;
  v456 = 0;
  v455 = 0;
  v464 = 0;
  v463 = 0;
  v462 = 0;
  v461 = 0;
  v460 = 0;
  v459 = 0;
  v447 = 0;
  v446[0] = 0;
  v453 = 0;
  v454 = 0;
  v451 = 0;
  v452 = 0;
  v449 = 0;
  v450 = 0;
  v458 = 0;
  v457 = 0;
  v126 = wlan_mlme_get_sta_mlo_conn_max_num(v13);
  wlan_psoc_mlme_get_11be_capab(v13, v446);
  if ( v446[0] != 1 )
  {
    LOBYTE(a2) = 0;
    v80 = 0;
    goto LABEL_444;
  }
  LODWORD(v437) = *(_DWORD *)(a3 + 1192);
  if ( *(unsigned __int8 *)(a3 + 1918) >= 3u )
    v127 = 3;
  else
    v127 = *(unsigned __int8 *)(a3 + 1918);
  v404 = *(unsigned __int8 *)(a3 + 1918);
  v438 = v127;
  ch_width = cm_get_ch_width(a3, v15 + 2068);
  v431 = cm_calculate_congestion_score(a3, v15 + 1920, &v447, 0);
  v128 = cm_calculate_bss_score(v13, a2, a3, a4, 0, a6, 3);
  v129 = *(_DWORD *)(a3 + 1192);
  v403 = v128;
  *(_WORD *)(a3 + 2066) = v128;
  if ( (wlan_reg_is_5ghz_ch_freq(v129) & 1) != 0 )
  {
    v130 = 8;
  }
  else if ( (wlan_reg_is_24ghz_ch_freq(v129) & 1) != 0 )
  {
    v130 = 0;
  }
  else
  {
    if ( (wlan_reg_is_6ghz_chan_freq(v129) & 1) == 0 )
    {
      a5 = v442;
      v406 = 0;
      v254 = v404;
      if ( v404 )
        goto LABEL_307;
LABEL_412:
      LOBYTE(a2) = v455;
      v80 = 0;
      v327 = v254;
      goto LABEL_413;
    }
    v130 = 16;
  }
  a5 = v442;
  v406 = (unsigned __int8)(*(_DWORD *)(v15 + 2044) >> v130) * *(unsigned __int8 *)(v15 + 1925);
  v254 = v404;
  if ( !v404 )
    goto LABEL_412;
LABEL_307:
  v444 = a6;
  v255 = v254 == 1 || v126 >= 3u;
  v405 = a4;
  v428 = (char)v7;
  v256 = 0;
  v80 = 0;
  v42 = a3 + 1920;
  v257 = !v255;
  v7 = &v461;
  v441 = v16;
  v436 = 0;
  v412 = v257;
  v402 = (__int64 *)(a3 + 1920);
  v408 = v13;
  do
  {
    if ( *(_BYTE *)(v42 + 40) == 1 )
    {
      v258 = cm_get_entry(v444, v42, a3 + 1912);
      v16 = v258;
      *(&v465 + v256) = v258;
      if ( v258 )
        v259 = *(_DWORD *)(v258 + 1192);
      else
        v259 = *(unsigned __int16 *)(v42 + 6);
      *((_DWORD *)&v463 + v256) = v259;
      if ( v412 && (policy_mgr_2_freq_always_on_same_mac(v13, v259, (unsigned int)v437) & 1) != 0 )
      {
        qdf_trace_msg(
          0x68u,
          8u,
          "freq %d %d can't be MLMR",
          v260,
          v261,
          v262,
          v263,
          v264,
          v265,
          v266,
          v267,
          v259,
          (unsigned int)v437);
LABEL_315:
        a5 = v442;
        goto LABEL_316;
      }
      v434 = v80;
      if ( v16 )
      {
        v268 = cm_calculate_bss_score(v13, a2, v16, v405, 0, v444, 1);
        v269 = *(&v465 + v256);
        *((_DWORD *)&v457 + v256) = v268;
        v270 = *(_BYTE *)(v269 + 60);
        *(_WORD *)(v269 + 2066) = v268;
        v271 = cm_get_ch_width(v269, v15 + 2068);
        v272 = v269;
        op_class_width = v271;
      }
      else
      {
        v270 = *(_BYTE *)(a3 + 60);
        if ( (wlan_reg_is_24ghz_ch_freq((unsigned int)v437) & 1) != 0 )
        {
          if ( (wlan_reg_is_5ghz_ch_freq(v259) & 1) != 0 )
          {
            v270 -= 7;
          }
          else if ( (wlan_reg_is_6ghz_chan_freq(v259) & 1) != 0 )
          {
            v270 -= 8;
          }
        }
        else if ( (wlan_reg_is_5ghz_ch_freq((unsigned int)v437) & 1) != 0 )
        {
          if ( (wlan_reg_is_24ghz_ch_freq(v259) & 1) != 0 )
            v270 += 7;
          else
            v270 -= wlan_reg_is_6ghz_chan_freq(v259) & 1;
        }
        else if ( (wlan_reg_is_6ghz_chan_freq((unsigned int)v437) & 1) != 0 )
        {
          if ( (wlan_reg_is_24ghz_ch_freq(v259) & 1) != 0 )
            v270 += 8;
          else
            v270 += wlan_reg_is_5ghz_ch_freq(v259) & 1;
        }
        op_class_width = wlan_reg_get_op_class_width(a2, *(unsigned __int8 *)(v42 + 41), 1);
        qdf_trace_msg(
          0x68u,
          8u,
          "No entry for partner, estimate with rnr",
          v274,
          v275,
          v276,
          v277,
          v278,
          v279,
          v280,
          v281);
        v272 = 0;
      }
      v282 = op_class_width;
      v283 = *(unsigned __int8 *)(v15 + 1948);
      v284 = *(unsigned __int8 *)(v15 + 1949);
      v285 = *(unsigned __int8 *)(v15 + 1950);
      v286 = -v284;
      LODWORD(v287) = 100 * *(unsigned __int8 *)(v15 + 1920);
      v288 = *(unsigned __int8 *)(v15 + 1952);
      v289 = *(unsigned __int8 *)(v15 + 1954);
      v290 = (*(char *)(a3 + 60) * ch_width + v270 * op_class_width) / (op_class_width + ch_width);
      v291 = *(unsigned __int8 *)(v15 + 1951);
      v292 = -v285;
      if ( -v283 >= v290 )
      {
        if ( v290 <= v292 )
        {
          v287 = (42949673 * (unsigned __int64)((unsigned int)v287 * v288)) >> 32;
        }
        else
        {
          if ( v286 >= v290 )
          {
            v295 = v291
                 - v288
                 + ((char)((v285 - v284) / v289 + 1 + ((unsigned __int8)(((v285 - v284) / v289 + 1) & 0x80) >> 7)) >> 1);
            v296 = ~((char)(v286 - v290) / v289);
            v294 = v291 + v295 / (char)((v285 - v284) / v289 + 1) * v296;
            if ( v288 > (char)(v291 + v295 / (char)((v285 - v284) / v289 + 1) * v296) )
              LOBYTE(v294) = *(_BYTE *)(v15 + 1952);
          }
          else
          {
            v293 = *(unsigned __int8 *)(v15 + 1953);
            v294 = (((char)((v284 - v283) / v293 + 1 + ((((v284 - v283) / v293 + 1) & 0x80) >> 7)) >> 1) - v291 + 100)
                 / (char)((v284 - v283) / v293 + 1)
                 * ~((char)(-(char)v283 - v290) / v293)
                 + 100;
            if ( v291 > (char)v294 )
              LOBYTE(v294) = *(_BYTE *)(v15 + 1951);
          }
          LODWORD(v287) = (char)v294 * (int)v287 / 100;
        }
      }
      v297 = v286 - v290;
      v425 = v287;
      v415 = op_class_width + ch_width;
      if ( v286 >= v290 )
      {
        v299 = *(_BYTE *)(v15 + 1955);
        v298 = 0;
        if ( v290 >= (char)-v299
          && (unsigned __int16)(v297 / (char)v289) != (unsigned __int16)((char)(v299 - v284) / (char)v289)
          && v290 > v292 )
        {
          v301 = v291
               + (v291
                - v288
                + ((char)((v285 - v284) / v289 + 1 + ((unsigned __int8)(((v285 - v284) / v289 + 1) & 0x80) >> 7)) >> 1))
               / (char)((v285 - v284) / v289 + 1)
               * ~(v297 / v289);
          if ( v288 <= (char)v301 )
            v298 = v301;
          else
            v298 = *(_BYTE *)(v15 + 1952);
        }
      }
      else
      {
        v298 = 100;
      }
      v302 = (unsigned __int8)((unsigned __int16)(op_class_width + ch_width) / 0x14u - 1);
      if ( v302 >= 0xF )
        v302 = 15;
      v421 = *(unsigned __int8 *)(v15 + 1924);
      v417 = v298;
      v419 = link_bw_score[v302];
      *((_WORD *)&v455 + v256) = (char)v298;
      v303 = cm_calculate_congestion_score(v272, v15 + 1920, v7, v298 < 0x64u);
      v304 = v303;
      if ( v431 <= v303 )
      {
        if ( v431 < v303 )
        {
          v306 = v303;
          v305 = v431 * v282 / v415;
          goto LABEL_368;
        }
        v305 = v303 >> 1;
      }
      else
      {
        v305 = v303 * ch_width / v415;
      }
      v306 = v431;
LABEL_368:
      LODWORD(v16) = *((_DWORD *)&v463 + v256);
      v307 = 80 * v305 / 0x64;
      if ( v307 >= 20 * (unsigned int)*(unsigned __int8 *)(v15 + 1929) )
        v308 = 20 * *(unsigned __int8 *)(v15 + 1929);
      else
        v308 = v307;
      if ( (wlan_reg_is_5ghz_ch_freq((unsigned int)v16) & 1) != 0 )
      {
        v317 = 8;
      }
      else if ( (wlan_reg_is_24ghz_ch_freq((unsigned int)v16) & 1) != 0 )
      {
        v317 = 0;
      }
      else
      {
        if ( (wlan_reg_is_6ghz_chan_freq((unsigned int)v16) & 1) == 0 )
        {
          v320 = v421;
          v322 = v417;
          v321 = v419;
          v318 = v431;
          v319 = v425;
          v323 = 0;
          goto LABEL_378;
        }
        v317 = 16;
      }
      v318 = v431;
      v319 = v425;
      v320 = v421;
      v322 = v417;
      v321 = v419;
      v323 = (unsigned __int8)(*(_DWORD *)(v15 + 2044) >> v317) * *(unsigned __int8 *)(v15 + 1925);
LABEL_378:
      LODWORD(v388) = v323;
      LODWORD(v387) = v406;
      LODWORD(v385) = v304;
      LODWORD(v384) = v318;
      v324 = v308 + 80 * v306 / 0x64;
      v80 = v434;
      LODWORD(v386) = v324;
      LODWORD(v383) = v320 * v322 * v321 / 100;
      v325 = v383 + v319 + v324 + ((unsigned int)(v323 + v406) >> 1);
      *((_DWORD *)&v459 + v256) = v325;
      if ( v325 <= v434 )
        v326 = v436;
      else
        v326 = v256;
      if ( v325 > v434 )
        v80 = v383 + v319 + v324 + ((unsigned int)(v323 + v406) >> 1);
      v436 = v326;
      LODWORD(v389) = v383 + v319 + v324 + ((unsigned int)(v323 + v406) >> 1);
      qdf_trace_msg(
        0x68u,
        8u,
        "ML idx %d score: freq (%d + %d) rssi %u pror %u bw %u congest %u %u %u band score: %u %u total %u",
        v309,
        v310,
        v311,
        v312,
        v313,
        v314,
        v315,
        v316,
        (unsigned int)v256,
        (unsigned int)v437,
        (unsigned int)v16,
        v383,
        v384,
        v385,
        v386,
        v387,
        v388,
        v389);
      v13 = v408;
      goto LABEL_315;
    }
LABEL_316:
    ++v256;
    v42 += 48;
    v7 = (__int64 *)((char *)v7 + 4);
  }
  while ( v438 != v256 );
  if ( (unsigned __int8)v436 > 2u )
  {
LABEL_164:
    __break(0x5512u);
    goto LABEL_165;
  }
  LODWORD(v16) = v441;
  v327 = v404;
  a4 = v405;
  LOWORD(a2) = *((_WORD *)&v455 + (unsigned __int8)v436);
  LOBYTE(v7) = v428;
  v328 = v459;
  if ( v404 == 1 )
  {
    v329 = 0;
  }
  else
  {
    v330 = HIDWORD(v459);
    v329 = (unsigned int)v459 < HIDWORD(v459);
    if ( (unsigned int)v459 > HIDWORD(v459) )
      v330 = v459;
    if ( v404 != 2 && v330 < v460 )
      v329 = 2;
  }
  if ( v329 )
  {
    v331 = *(_QWORD *)(a3 + 1944);
    v451 = *(_QWORD *)(a3 + 1936);
    v452 = v331;
    v332 = *(_QWORD *)(a3 + 1928);
    v333 = &v402[6 * v329];
    v449 = *v402;
    v450 = v332;
    v334 = *(_QWORD *)(a3 + 1960);
    v453 = *(_QWORD *)(a3 + 1952);
    v454 = v334;
    v335 = *v333;
    v336 = v333[1];
    *v333 = v449;
    v333[1] = v332;
    v337 = v453;
    v338 = v454;
    v339 = v333[4];
    v340 = v333[5];
    *v402 = v335;
    *(_QWORD *)(a3 + 1928) = v336;
    v333[4] = v337;
    v333[5] = v338;
    v341 = v451;
    v342 = v452;
    v344 = v333[2];
    v343 = v333[3];
    *(_QWORD *)(a3 + 1952) = v339;
    *(_QWORD *)(a3 + 1960) = v340;
    v333[2] = v341;
    v333[3] = v342;
    *(_QWORD *)(a3 + 1936) = v344;
    *(_QWORD *)(a3 + 1944) = v343;
    *((_DWORD *)&v459 + v329) = v328;
  }
  LODWORD(v459) = 0;
  if ( v404 != 1 )
  {
    v345 = HIDWORD(v459);
    v346 = 1;
    if ( v404 > 2 && HIDWORD(v459) < v460 )
      v347 = 2;
    else
      v347 = 1;
    if ( v404 > 2 && HIDWORD(v459) < v460 )
      v346 = 2;
    if ( v347 != 1 )
    {
      v348 = *(_QWORD *)(a3 + 1992);
      v349 = &v402[6 * v346];
      v350 = *(_QWORD *)(a3 + 2000);
      v451 = *(_QWORD *)(a3 + 1984);
      v452 = v348;
      v351 = *(_QWORD *)(a3 + 2008);
      v453 = v350;
      v454 = v351;
      v352 = *(_QWORD *)(a3 + 1968);
      v353 = v349[1];
      *(_QWORD *)(a3 + 1968) = *v349;
      v354 = *(_QWORD *)(a3 + 1976);
      *(_QWORD *)(a3 + 1976) = v353;
      v449 = v352;
      v450 = v354;
      v355 = v349[4];
      v357 = v349[2];
      v356 = v349[3];
      *(_QWORD *)(a3 + 2008) = v349[5];
      *(_QWORD *)(a3 + 1992) = v356;
      v359 = v453;
      v358 = v454;
      *(_QWORD *)(a3 + 1984) = v357;
      *(_QWORD *)(a3 + 2000) = v355;
      v349[4] = v359;
      v349[5] = v358;
      v360 = v452;
      v349[2] = v451;
      v349[3] = v360;
      v361 = v450;
      *v349 = v449;
      v349[1] = v361;
      *((_DWORD *)&v459 + v346) = v345;
    }
    HIDWORD(v459) = 0;
    if ( v404 != 2 )
      v460 = 0;
  }
  if ( (unsigned int)v457 <= v403 && (v404 == 1 || HIDWORD(v457) <= v403 && (v404 == 2 || v458 <= v403)) )
  {
LABEL_413:
    qdf_trace_msg(
      0x68u,
      8u,
      "assoc link (freq %d) is best, boost %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      (unsigned int)v437,
      20);
    v80 += 20;
  }
  *(_WORD *)(a3 + 2064) = v80;
  if ( v327 >= 3 )
  {
    v362 = wlan_reg_freq_to_band(*(unsigned __int16 *)(a3 + 1974));
    v435 = v80;
    if ( (policy_mgr_2_freq_always_on_same_mac(v13, *(unsigned __int16 *)(a3 + 1974), *(unsigned int *)(a3 + 1192)) & 1) != 0 )
    {
      if ( v362 )
      {
        v448[0] = 0;
        wlan_mlme_get_emlsr_mode_enabled(v13, v448);
        if ( v448[0] )
          v363 = 5;
        else
          v363 = 0;
      }
      else
      {
        v363 = 0;
      }
    }
    else
    {
      v363 = 10;
    }
    if ( (policy_mgr_2_freq_always_on_same_mac(v13, *(unsigned __int16 *)(a3 + 1974), *(unsigned __int16 *)(a3 + 1926))
        & 1) != 0 )
    {
      if ( v362 )
      {
        v448[0] = 0;
        wlan_mlme_get_emlsr_mode_enabled(v13, v448);
        if ( v448[0] )
          v363 += 5;
      }
    }
    else
    {
      v363 += 10;
    }
    v364 = *(unsigned __int16 *)(a3 + 2022);
    v365 = HIDWORD(v457) * v363;
    HIDWORD(v459) = v365;
    v366 = wlan_reg_freq_to_band(v364);
    if ( (policy_mgr_2_freq_always_on_same_mac(v13, *(unsigned __int16 *)(a3 + 2022), *(unsigned int *)(a3 + 1192)) & 1) != 0 )
    {
      if ( v366 )
      {
        v448[0] = 0;
        wlan_mlme_get_emlsr_mode_enabled(v13, v448);
        if ( v448[0] )
          v367 = 5;
        else
          v367 = 0;
      }
      else
      {
        v367 = 0;
      }
    }
    else
    {
      v367 = 10;
    }
    if ( (policy_mgr_2_freq_always_on_same_mac(v13, *(unsigned __int16 *)(a3 + 2022), *(unsigned __int16 *)(a3 + 1926))
        & 1) != 0 )
    {
      if ( v366 )
      {
        v448[0] = 0;
        wlan_mlme_get_emlsr_mode_enabled(v13, v448);
        if ( v448[0] )
          v367 += 5;
      }
    }
    else
    {
      v367 += 10;
    }
    if ( v365 < v458 * v367 )
    {
      v368 = *(_QWORD *)(a3 + 1984);
      v369 = *(_QWORD *)(a3 + 1992);
      v370 = *(_QWORD *)(a3 + 2000);
      v460 = v365;
      v451 = v368;
      v452 = v369;
      v371 = *(_QWORD *)(a3 + 2008);
      v372 = *(_QWORD *)(a3 + 1968);
      v453 = v370;
      v454 = v371;
      v373 = *(_QWORD *)(a3 + 1976);
      v374 = *(_QWORD *)(a3 + 2032);
      v449 = v372;
      v450 = v373;
      v375 = *(_QWORD *)(a3 + 2040);
      v376 = *(_QWORD *)(a3 + 2048);
      *(_QWORD *)(a3 + 1984) = v374;
      *(_QWORD *)(a3 + 1992) = v375;
      v377 = *(_QWORD *)(a3 + 2056);
      *(_QWORD *)(a3 + 2000) = v376;
      v378 = *(_QWORD *)(a3 + 2016);
      *(_QWORD *)(a3 + 2008) = v377;
      v379 = *(_QWORD *)(a3 + 2024);
      *(_QWORD *)(a3 + 1968) = v378;
      *(_QWORD *)(a3 + 1976) = v379;
      v380 = v449;
      *(_QWORD *)(a3 + 2024) = v450;
      *(_QWORD *)(a3 + 2016) = v380;
      v381 = v453;
      *(_QWORD *)(a3 + 2056) = v454;
      *(_QWORD *)(a3 + 2048) = v381;
      v382 = v451;
      *(_QWORD *)(a3 + 2040) = v452;
      *(_QWORD *)(a3 + 2032) = v382;
    }
    a5 = v442;
    v80 = v435;
    HIDWORD(v459) = 0;
  }
LABEL_444:
  v78 = 0;
  v79 = v80;
  LODWORD(v444) = 0;
  LODWORD(v438) = 0;
  LODWORD(v437) = 0;
  if ( a5 )
  {
LABEL_66:
    if ( (*(_BYTE *)(v15 + 2048) & 1) == 0 )
      goto LABEL_71;
    v81 = *(_DWORD *)a5 == *(_DWORD *)(a3 + 1) && *(unsigned __int16 *)(a5 + 4) == *(unsigned __int16 *)(a3 + 5);
    if ( !v81 )
      goto LABEL_71;
    LODWORD(a2) = 20000;
    v107 = *(_DWORD *)(a3 + 1192);
    v108 = *(char *)(a3 + 60);
    v109 = *(unsigned __int8 *)(a3 + 1);
    v110 = *(unsigned __int8 *)(a3 + 2);
    v111 = *(unsigned __int8 *)(a3 + 3);
    v112 = *(_DWORD *)(a3 + 1260) + 20000;
    v113 = *(unsigned __int8 *)(a3 + 6);
    *(_DWORD *)(a3 + 1260) = v112;
    if ( ((unsigned __int8)v7 & 2) != 0 )
      v114 = "Candidate";
    else
      v114 = "Partner";
    LODWORD(v385) = v112;
    v115 = "%s(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d BSSID hint given, give max score %d";
    LODWORD(v384) = v108;
    LODWORD(v383) = v107;
    goto LABEL_248;
  }
LABEL_71:
  v82 = *(unsigned __int8 *)(v15 + 1928);
  v436 = v79;
  LODWORD(v442) = v78;
  if ( (policy_mgr_is_pcl_weightage_required(v13) & 1) != 0 )
  {
    is_hw_dbs_capable = policy_mgr_is_hw_dbs_capable(v13);
    LODWORD(a5) = 0;
    if ( a4 && (is_hw_dbs_capable & 1) != 0 )
    {
      v84 = v82 - (int)(255 - a4) / 0x14uLL;
      LODWORD(a5) = 100 * (v84 & ~(v84 >> 31));
    }
    if ( (*(_WORD *)(v15 + 2070) & 1) == 0 )
    {
LABEL_81:
      LODWORD(v7) = 0;
      goto LABEL_82;
    }
  }
  else
  {
    LODWORD(a5) = 0;
    if ( (*(_WORD *)(v15 + 2070) & 1) == 0 )
      goto LABEL_81;
  }
  if ( !*(_QWORD *)(a3 + 1456) && (wlan_reg_is_6ghz_chan_freq(*(unsigned int *)(a3 + 1192)) & 1) == 0 )
    goto LABEL_81;
  LODWORD(v7) = *(unsigned __int8 *)(v15 + 1921) * (unsigned __int8)a2;
LABEL_82:
  LODWORD(v42) = a5 + v80;
  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(*(unsigned int *)(a3 + 1192));
  v86 = *(_WORD *)(v15 + 2070);
  if ( (is_24ghz_ch_freq & 1) != 0 )
  {
    if ( (v86 & 0x10) == 0 )
      goto LABEL_84;
LABEL_86:
    if ( *(_QWORD *)(a3 + 1560) || (wlan_reg_is_6ghz_chan_freq(*(unsigned int *)(a3 + 1192)) & 1) != 0 )
    {
      v87 = *(unsigned __int8 *)(v15 + 1922) * (unsigned __int8)a2;
      v88 = 0;
      goto LABEL_89;
    }
LABEL_165:
    v88 = 0;
    v87 = 0;
    goto LABEL_89;
  }
  if ( (v86 & 2) != 0 )
    goto LABEL_86;
LABEL_84:
  v87 = 0;
  v88 = 1;
LABEL_89:
  v89 = *(_WORD *)(v15 + 2070);
  if ( (v89 & 4) != 0 && *(_QWORD *)(a3 + 1696) )
    v90 = *(unsigned __int8 *)(v15 + 1923) * (unsigned __int8)a2;
  else
    v90 = 0;
  v91 = *(_BYTE *)(v15 + 1949);
  v92 = *(_BYTE *)(v15 + 1955);
  v93 = 0;
  v94 = (char)-v91;
  v95 = *(char *)(a3 + 60);
  v96 = __OFSUB__(v94, v95);
  v97 = v94 - v95;
  if ( !((v97 < 0) ^ v96 | (v97 == 0)) )
    v93 = (unsigned __int16)((char)v97 / *(char *)(v15 + 1954)) == (unsigned __int16)((char)(v92 - v91)
                                                                                    / *(char *)(v15 + 1954));
  v98 = *(_QWORD *)(a3 + 1560);
  v99 = *(_QWORD *)(a3 + 1696);
  v440 = v16;
  v430 = (int)v7;
  v433 = a5;
  if ( v98 && (*(_BYTE *)(v98 + 3) & 8) != 0
    || v99 && *(char *)(v99 + 12) < 0
    || (v100 = *(_QWORD *)(a3 + 1800)) != 0 && (*(_BYTE *)(v100 + 5) & 0x20) != 0 )
  {
    v102 = (char)-v92;
    if ( (v89 & 0x20) == 0 )
      v88 = 1;
    if ( v95 <= v102 )
      v88 = 1;
    if ( ((v88 | v93) & 1) != 0 )
      v101 = 0;
    else
      v101 = 100 * *(unsigned __int8 *)(v15 + 1927);
    v416 = 1;
  }
  else
  {
    v416 = 0;
    v101 = 0;
  }
  v103 = *(unsigned __int8 *)(a3 + 82);
  v104 = v42 + (_DWORD)v7 + v87 + v90 + v101;
  if ( !*(_BYTE *)(a3 + 82) )
  {
    if ( *(_QWORD *)(a3 + 1504) )
    {
      v105 = (3289700 * (unsigned int)*(unsigned __int8 *)(a3 + 83)) >> 23;
      if ( v105 <= 1 )
        v105 = 1;
      goto LABEL_117;
    }
    v414 = 0;
LABEL_126:
    v116 = *(unsigned __int8 *)(v15 + 1980);
    if ( !*(_BYTE *)(v15 + 1980) )
      goto LABEL_169;
    if ( v116 >= 0x10 )
    {
      v116 = 15;
      *(_BYTE *)(v15 + 1980) = 15;
    }
    v117 = *(_QWORD *)(a3 + 1744);
    if ( v117 )
    {
      v118 = *(unsigned __int8 *)(v117 + 1);
      if ( v118 >= 7 )
      {
        v119 = v118 - 4;
        v120 = (_BYTE *)(v117 + 6);
        v121 = 0xF / v116;
        do
        {
          v122 = (unsigned __int8)v120[1];
          v123 = v119 - 2;
          if ( (unsigned int)v122 > (unsigned __int8)v123 )
            break;
          if ( *v120 == 103 )
          {
            v252 = v120[2] & 0xF;
            v253 = v90;
            qdf_trace_msg(
              0x68u,
              2u,
              "%s: downlink_av_cap %d",
              v29,
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              "cm_calculate_oce_wan_score",
              v120[2] & 0xF);
            if ( v252 )
            {
              LODWORD(v117) = v252 / v121;
              v116 = *(unsigned __int8 *)(v15 + 1980);
              v90 = v253;
              goto LABEL_136;
            }
            v116 = 0;
            v90 = v253;
            goto LABEL_169;
          }
          v119 = v123 - v122;
          v120 += v122 + 2;
        }
        while ( (unsigned __int8)v119 > 2u );
      }
      LODWORD(v117) = 0;
    }
LABEL_136:
    if ( (unsigned int)v117 >= v116 )
      LODWORD(v117) = v116;
    if ( (unsigned int)v117 > 3 )
    {
      if ( (unsigned int)v117 > 7 )
      {
        v131 = 8 * v117;
        if ( (unsigned int)v117 > 0xB )
          v132 = *(_DWORD *)(v15 + 1996);
        else
          v132 = *(_DWORD *)(v15 + 1992);
        v125 = v132 >> v131;
        goto LABEL_168;
      }
      v124 = *(_DWORD *)(v15 + 1988);
    }
    else
    {
      v124 = *(_DWORD *)(v15 + 1984);
    }
    v125 = v124 >> (8 * v117);
LABEL_168:
    v116 = (unsigned __int8)v125 * *(unsigned __int8 *)(v15 + 1930);
LABEL_169:
    v104 += v116;
    v420 = v116;
    v106 = *(_QWORD *)(a3 + 1744);
    if ( v106 )
      goto LABEL_170;
    goto LABEL_175;
  }
  if ( ((100 * (_WORD)v103 - 25500) & 0xFFFCu) < 0xFF )
  {
    v414 = 1;
    goto LABEL_126;
  }
  v105 = 100 - ((unsigned int)(3289700 * v103) >> 23);
LABEL_117:
  v414 = v105;
  if ( v105 <= 0x4A )
    goto LABEL_126;
  v420 = 0;
  v106 = *(_QWORD *)(a3 + 1744);
  if ( !v106 )
    goto LABEL_175;
LABEL_170:
  v148 = *(unsigned __int8 *)(v106 + 1);
  if ( v148 >= 7 )
  {
    v149 = v148 - 4;
    v150 = (_BYTE *)(v106 + 6);
    do
    {
      v151 = (unsigned __int8)v150[1];
      v152 = v149 - 2;
      if ( (unsigned int)v151 > (unsigned __int8)v152 )
        break;
      if ( *v150 == 107 )
      {
        v413 = -(unsigned __int8)v150[2];
        v153 = *(char *)(a3 + 60) - (char)v413 + 20;
        goto LABEL_176;
      }
      v149 = v152 - v151;
      v150 += v151 + 2;
    }
    while ( (unsigned __int8)v149 > 2u );
  }
LABEL_175:
  v153 = *(char *)(a3 + 60);
  LOBYTE(v413) = 0;
LABEL_176:
  v154 = *(unsigned __int8 *)(v15 + 1948);
  v155 = -(char)v154 - v153;
  if ( -v154 >= v153 )
  {
    v157 = *(unsigned __int8 *)(v15 + 1950);
    v156 = *(unsigned __int8 *)(v15 + 1952);
    if ( v153 > -v157 )
    {
      v158 = *(unsigned __int8 *)(v15 + 1949);
      v159 = *(unsigned __int8 *)(v15 + 1951);
      v255 = -v158 >= v153;
      v160 = -(char)v158 - v153;
      if ( v255 )
      {
        v162 = *(unsigned __int8 *)(v15 + 1954);
        v163 = v159
             + (v159
              - v156
              + ((char)((v157 - v158) / v162 + 1 + ((unsigned __int8)(((v157 - v158) / v162 + 1) & 0x80) >> 7)) >> 1))
             / (char)((v157 - v158) / v162 + 1)
             * ~(v160 / v162);
        if ( v156 <= (char)v163 )
          LOBYTE(v156) = v163;
      }
      else
      {
        v161 = *(unsigned __int8 *)(v15 + 1953);
        v156 = (((char)((v158 - v154) / v161 + 1 + ((((v158 - v154) / v161 + 1) & 0x80) >> 7)) >> 1) - v159 + 100)
             / (char)((v158 - v154) / v161 + 1)
             * ~(v155 / v161)
             + 100;
        if ( v159 > (char)v156 )
          LOBYTE(v156) = *(_BYTE *)(v15 + 1951);
      }
    }
  }
  else
  {
    LOBYTE(v156) = 100;
  }
  v424 = v90;
  v422 = v101;
  v164 = (unsigned __int8)(*(_BYTE *)(v15 + 1931) * v156);
  if ( v106 )
  {
    v165 = *(unsigned __int8 *)(v106 + 1);
    if ( v165 >= 7 )
    {
      v166 = v165 - 4;
      v167 = (_BYTE *)(v106 + 6);
      do
      {
        v168 = (unsigned __int8)v167[1];
        v169 = v166 - 2;
        if ( (unsigned int)v168 > (unsigned __int8)v169 )
          break;
        if ( *v167 == 108 )
        {
          LOBYTE(v106) = 50 * *(_BYTE *)(v15 + 1932);
          v411 = 1;
          goto LABEL_195;
        }
        v166 = v169 - v168;
        v167 += v168 + 2;
      }
      while ( (unsigned __int8)v166 > 2u );
    }
    v411 = 0;
    LOBYTE(v106) = 0;
  }
  else
  {
    v411 = 0;
  }
LABEL_195:
  v170 = *(unsigned __int8 *)(a3 + 1286);
  v418 = v164;
  v171 = v104 + v164;
  v172 = v106 & 0xFE;
  LOBYTE(v449) = 0;
  v173 = (unsigned __int8 *)util_scan_entry_rsnxe_by_gen(a3, v170);
  v182 = wlan_crypto_parse_rsnxe_ie(v173, &v449, v174, v175, v176, v177, v178, v179, v180, v181);
  v183 = v13;
  v427 = v87;
  if ( v182 && (*v182 & 0x40) != 0 )
  {
    v184 = 100 * *(unsigned __int8 *)(v15 + 1933);
    v410 = 1;
  }
  else
  {
    v410 = 0;
    v184 = 0;
  }
  v185 = *(_DWORD *)(a3 + 1192);
  v186 = *(unsigned __int8 *)(v15 + 2068);
  v187 = *(unsigned __int8 *)(v15 + 2069);
  v188 = v171 + v172;
  v407 = v183;
  if ( (policy_mgr_is_chnl_in_diff_band(v183, v185) & 1) != 0
    && (policy_mgr_is_hw_dbs_capable(v183) & 1) != 0
    && (policy_mgr_is_hw_dbs_2x2_capable(v183) & 1) == 0 )
  {
    v189 = 1;
  }
  else if ( (wlan_reg_is_24ghz_ch_freq(v185) & 1) != 0 )
  {
    v189 = v186;
  }
  else
  {
    v189 = v187;
  }
  if ( v189 >= *(unsigned __int8 *)(a3 + 84) )
    v190 = *(unsigned __int8 *)(a3 + 84);
  else
    v190 = v189;
  v191 = *(_DWORD *)(v15 + 2036);
  switch ( v190 )
  {
    case 2u:
      v191 >>= 8;
      break;
    case 3u:
      v191 >>= 16;
      break;
    case 4u:
      v191 >>= 24;
      break;
  }
  v192 = (unsigned __int8)a2;
  v193 = 42949673LL * (unsigned __int8)v191 * (unsigned __int8)a2 * (unsigned int)*(unsigned __int8 *)(v15 + 1926);
  v194 = *(_DWORD *)(a3 + 1264);
  v195 = HIDWORD(v193);
  if ( (v194 & 0x6C8) == 0 )
  {
    if ( (v194 & 0x124) != 0 )
    {
      LOBYTE(v197) = *(_BYTE *)(v15 + 2064);
      goto LABEL_222;
    }
LABEL_221:
    LOBYTE(v197) = 0;
    goto LABEL_222;
  }
  v196 = *(_DWORD *)(a3 + 1268);
  if ( (v196 & 0x19FF0C00) == 0 )
  {
    if ( (v196 & 0x1E2) != 0 )
    {
      v197 = *(_DWORD *)(v15 + 2064) >> 8;
      goto LABEL_222;
    }
    goto LABEL_221;
  }
  LOWORD(v197) = *(_WORD *)(v15 + 2066);
LABEL_222:
  v198 = (5243 * (((unsigned __int8)v197 * (unsigned int)*(unsigned __int8 *)(v15 + 1945)) >> 2)) >> 17;
  v199 = v188 + v184 + HIDWORD(v193) + v198;
  if ( (*(_WORD *)(v15 + 2070) & 8) != 0 && *(_QWORD *)(a3 + 1800) )
  {
    v200 = 0;
    if ( (wlan_cm_is_eht_allowed_for_current_security(v407, a3, 0) & 1) != 0 )
      v200 = *(unsigned __int8 *)(v15 + 1934) * (unsigned __int8)a2;
  }
  else
  {
    v200 = 0;
  }
  v201 = v443;
  v202 = v199 + v200;
  if ( (v443 & 1) != 0 )
  {
    v203 = v440;
    LODWORD(a2) = v202;
    if ( !*(_QWORD *)(a3 + 1864) )
      goto LABEL_236;
LABEL_237:
    v205 = 1;
    if ( (v201 & 1) != 0 )
      goto LABEL_240;
    goto LABEL_238;
  }
  v203 = v440;
  LODWORD(a2) = v202;
  *(_DWORD *)(a3 + 1260) = v202;
  if ( v440 <= 3 )
  {
    if ( v440 )
      v204 = 10;
    else
      v204 = 0;
    v201 = v443;
    LODWORD(a2) = (v204 + (unsigned __int8)(*(_DWORD *)(v15 + 1936) >> (8 * v440))) * v202 / 0x64 + v202;
    *(_DWORD *)(a3 + 1260) = a2;
  }
  if ( *(_QWORD *)(a3 + 1864) )
    goto LABEL_237;
LABEL_236:
  if ( *(_QWORD *)(a3 + 1880) )
    goto LABEL_237;
  v205 = 0;
  if ( (v201 & 1) != 0 )
  {
LABEL_240:
    if ( (v201 & 2) != 0 )
      v206 = "Candidate";
    else
      v206 = "Partner";
    LODWORD(v389) = v416;
    LODWORD(v388) = *(_QWORD *)(a3 + 1800) != 0;
    LODWORD(v387) = *(_QWORD *)(a3 + 1696) != 0;
    LODWORD(v386) = *(_QWORD *)(a3 + 1560) != 0;
    LODWORD(v385) = *(_QWORD *)(a3 + 1456) != 0;
    LODWORD(v384) = *(char *)(a3 + 60);
    LODWORD(v383) = *(_DWORD *)(a3 + 1192);
    qdf_trace_msg(
      0x68u,
      8u,
      "%s(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d HT %d VHT %d HE %d EHT %d su_bfer %d phy %d atf %d qbss %d cong_pct"
      " %d NSS %d ap_tx_pwr %d oce_subnet %d sae_pk_cap %d prorated_pcnt %d keymgmt 0x%x mlo type %d rsno %d rsnxo %d",
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v206,
      *(unsigned __int8 *)(a3 + 1),
      *(unsigned __int8 *)(a3 + 2),
      *(unsigned __int8 *)(a3 + 3),
      *(unsigned __int8 *)(a3 + 6),
      v383,
      v384,
      v385,
      v386,
      v387,
      v388,
      v389,
      *(_DWORD *)(a3 + 52),
      *(unsigned __int8 *)(a3 + 82),
      *(unsigned __int8 *)(a3 + 83),
      v414,
      *(unsigned __int8 *)(a3 + 84),
      (char)v413,
      v411,
      v410,
      v192,
      *(_DWORD *)(a3 + 1268),
      v203,
      v205,
      *(_QWORD *)(a3 + 1872) != 0);
    v201 = v443;
    goto LABEL_244;
  }
LABEL_238:
  if ( v203 <= 4 && v203 != 3 )
    goto LABEL_240;
  is_eht_allowed_for_current_security = wlan_cm_is_eht_allowed_for_current_security(v407, a3, 0);
  v201 = v443;
  if ( (is_eht_allowed_for_current_security & 1) == 0 )
    goto LABEL_240;
  if ( (v443 & 2) != 0 )
  {
    if ( *(_QWORD *)(a3 + 1824) )
    {
      if ( *(_QWORD *)(a3 + 1840) )
      {
        v208 = wlan_t2lm_validate_candidate(a3);
        v201 = v443;
        if ( v208 )
          goto LABEL_240;
      }
    }
  }
LABEL_244:
  v109 = *(unsigned __int8 *)(a3 + 1);
  if ( (v201 & 1) != 0 )
    v114 = "Link";
  else
    v114 = "Candidate";
  v110 = *(unsigned __int8 *)(a3 + 2);
  v111 = *(unsigned __int8 *)(a3 + 3);
  v113 = *(unsigned __int8 *)(a3 + 6);
  LODWORD(v400) = v436;
  v115 = "%s score(%02x:%02x:%02x:**:**:%02x freq %d): rssi %d pcl %d ht %d vht %d he %d bfee %d bw %d band %d cong %d ns"
         "s %d oce_wan %d oce_ap_pwr %d oce_subnet %d sae_pk %d eht %d security %d ml %d TOTAL %d";
  LODWORD(v401) = a2;
  LODWORD(v399) = v198;
  LODWORD(v394) = v420;
  LODWORD(v398) = v200;
  LODWORD(v392) = v437;
  LODWORD(v397) = v184;
  LODWORD(v391) = v442;
  LODWORD(v396) = v172;
  LODWORD(v390) = v438;
  LODWORD(v395) = v418;
  LODWORD(v389) = v422;
  LODWORD(v393) = v195;
  LODWORD(v388) = v424;
  LODWORD(v383) = *(_DWORD *)(a3 + 1192);
  LODWORD(v387) = v427;
  LODWORD(v386) = v430;
  LODWORD(v385) = v433;
  LODWORD(v384) = (_DWORD)v444;
LABEL_248:
  qdf_trace_msg(
    0x68u,
    8u,
    v115,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    v36,
    v114,
    v109,
    v110,
    v111,
    v113,
    v383,
    v384,
    v385,
    v386,
    v387,
    v388,
    v389,
    v390,
    v391,
    v392,
    v393,
    v394,
    v395,
    v396,
    v397,
    v398,
    v399,
    v400,
    v401);
LABEL_297:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)a2;
}
