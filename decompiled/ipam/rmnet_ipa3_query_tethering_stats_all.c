__int64 __fastcall rmnet_ipa3_query_tethering_stats_all(__int64 a1)
{
  int upstream_type; // w0
  __int64 v3; // x0
  __int64 v4; // x22
  int v5; // w8
  _QWORD *v6; // x25
  _QWORD *v7; // x27
  __int64 ipc_logbuf_low; // x0
  char v9; // w11
  __int64 ipc_logbuf; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  _DWORD *v14; // x8
  int v15; // w9
  char v16; // w12
  unsigned __int8 v17; // w11
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x0
  __int64 v26; // x0
  unsigned int v27; // w19
  char v28; // w20
  __int64 result; // x0
  __int64 v30; // x20
  int v31; // w21
  char v32; // w0
  __int64 v33; // x20
  int v34; // w21
  char v35; // w0
  unsigned int tethering_stats_modem; // w0
  __int64 v37; // x20
  int type; // w21
  char flag; // w0
  __int64 v40; // x20
  int v41; // w21
  char v42; // w0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x9
  const char *v46; // x24
  int teth_stats; // w20
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x23
  int v52; // w0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  int v56; // w0
  unsigned int ep_mapping; // w0
  unsigned int v58; // w21
  __int64 v59; // x0
  __int64 v60; // x0
  unsigned int v61; // w0
  __int64 v62; // x0
  long double v63; // q0
  __int64 v64; // x0
  int v65; // w28
  __int64 wigig_cons; // x0
  unsigned int v67; // w0
  _QWORD *v68; // x20
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x9
  int v72; // w11
  int v73; // w14
  __int64 v74; // x8
  __int64 v75; // x12
  __int64 v76; // x9
  int v77; // w20
  __int64 v78; // x0
  unsigned int v79; // w0
  unsigned int v80; // w21
  long double v81; // q0
  __int64 v82; // x8
  __int64 v83; // x9
  __int64 v84; // x12
  __int64 v85; // x8
  __int64 v86; // x13
  int v87; // w21
  __int64 v88; // x0
  __int64 v89; // x0
  int v90; // w0
  __int64 v91; // x0
  unsigned int v92; // w0
  unsigned int v93; // w20
  __int64 v94; // x0
  __int64 v95; // x0
  __int64 v96; // x0
  __int64 v97; // x0
  __int64 v98; // x0
  __int64 v99; // x0
  __int64 v100; // x0
  __int64 v101; // x0
  __int64 v102; // x8
  __int64 v103; // x0
  __int64 v104; // x0
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 v107; // x8
  __int64 v108; // x0
  __int64 v109; // x0
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 v112; // x8
  __int64 v113; // x0
  __int64 v114; // x0
  __int64 v115; // x8
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x8
  __int64 v119; // x0
  __int64 v120; // x0
  __int64 v121; // x8
  __int64 v122; // x0
  __int64 v123; // x0
  int v124; // w0
  unsigned int v125; // w21
  unsigned int v126; // w0
  __int64 v127; // x0
  __int64 v128; // x0
  __int64 v129; // x0
  long double v130; // q0
  __int64 v131; // x0
  unsigned int v132; // w21
  __int64 v133; // x0
  _QWORD *v134; // x28
  __int64 v135; // x0
  __int64 v136; // x0
  __int64 v137; // x8
  __int64 v138; // x16
  int v139; // w14
  __int64 v140; // x10
  __int64 v141; // x8
  __int64 v142; // x11
  __int64 v143; // x12
  __int64 v144; // x9
  int v145; // w20
  __int64 v146; // x0
  unsigned int v147; // w0
  unsigned int v148; // w21
  long double v149; // q0
  __int64 v150; // x8
  __int64 v151; // x9
  __int64 v152; // x12
  __int64 v153; // x8
  __int64 v154; // x13
  __int64 v155; // x0
  __int64 v156; // x0
  int v157; // w0
  unsigned int v158; // w21
  __int64 v159; // x0
  __int64 v160; // x0
  __int64 v161; // x0
  long double v162; // q0
  __int64 v163; // x0
  unsigned int v164; // w21
  __int64 v165; // x0
  unsigned int v166; // w0
  unsigned int v167; // w20
  long double v168; // q0
  __int64 v169; // x8
  __int64 v170; // x9
  __int64 v171; // x12
  __int64 v172; // x8
  __int64 v173; // x13
  __int64 v174; // x0
  unsigned int v175; // w0
  unsigned int v176; // w20
  long double v177; // q0
  __int64 v178; // x8
  __int64 v179; // x9
  __int64 v180; // x12
  __int64 v181; // x8
  __int64 v182; // x13
  __int64 v183; // x0
  unsigned int v184; // w0
  unsigned int v185; // w20
  __int64 v186; // x8
  __int64 v187; // x9
  __int64 v188; // x12
  __int64 v189; // x8
  __int64 v190; // x13
  __int64 v191; // x8
  __int64 v192; // x20
  __int64 v193; // x10
  __int64 v194; // x8
  __int64 v195; // x9
  int v196; // w9
  unsigned int v197; // w0
  unsigned int v198; // w20
  __int64 v199; // x0
  __int64 v200; // x0
  __int64 v201; // x8
  __int64 v202; // x0
  __int64 v203; // x0
  __int64 v204; // x0
  __int64 v205; // x0
  __int64 v206; // x0
  __int64 v207; // x8
  __int64 v208; // x16
  int v209; // w13
  int v210; // w14
  __int64 v211; // x8
  __int64 v212; // x11
  __int64 v213; // x12
  __int64 v214; // x10
  int v215; // w20
  __int64 v216; // x0
  unsigned int v217; // w0
  unsigned int v218; // w21
  long double v219; // q0
  __int64 v220; // x8
  __int64 v221; // x9
  __int64 v222; // x12
  __int64 v223; // x8
  __int64 v224; // x13
  __int64 v225; // x0
  __int64 v226; // x0
  __int64 v227; // x8
  __int64 v228; // x10
  __int64 v229; // x9
  __int64 v230; // x8
  __int64 v231; // x11
  _BOOL4 v232; // w21
  __int64 v233; // x0
  int v234; // w0
  __int64 v235; // x0
  unsigned int v236; // w0
  unsigned int v237; // w20
  __int64 v238; // x0
  __int64 v239; // x0
  int v240; // w21
  __int64 v241; // x8
  __int64 v242; // x10
  __int64 v243; // x9
  __int64 v244; // x8
  __int64 v245; // x11
  unsigned int v246; // w0
  unsigned int v247; // w20
  __int64 v248; // x0
  __int64 v249; // x0
  __int64 v250; // x8
  __int64 v251; // x0
  __int64 v252; // x0
  __int64 v253; // x8
  __int64 v254; // x0
  __int64 v255; // x0
  __int64 v256; // x0
  unsigned int v257; // w0
  unsigned int v258; // w20
  long double v259; // q0
  __int64 v260; // x8
  __int64 v261; // x9
  __int64 v262; // x12
  __int64 v263; // x8
  __int64 v264; // x13
  __int64 v265; // x0
  unsigned int v266; // w0
  unsigned int v267; // w20
  long double v268; // q0
  __int64 v269; // x8
  __int64 v270; // x9
  __int64 v271; // x12
  __int64 v272; // x8
  __int64 v273; // x13
  __int64 v274; // x0
  unsigned int v275; // w0
  unsigned int v276; // w20
  __int64 v277; // x8
  __int64 v278; // x9
  __int64 v279; // x12
  __int64 v280; // x8
  __int64 v281; // x13
  __int64 v282; // x8
  __int64 v283; // x10
  __int64 v284; // x9
  __int64 v285; // x8
  __int64 v286; // x11
  int v287; // w0
  __int64 v288; // x0
  unsigned int v289; // w0
  unsigned int v290; // w20
  __int64 v291; // x0
  __int64 v292; // x0
  __int64 v293; // x0
  __int64 v294; // x0
  __int64 v295; // x8
  __int64 v296; // x10
  __int64 v297; // x9
  __int64 v298; // x8
  __int64 v299; // x11
  unsigned int v300; // w0
  unsigned int v301; // w20
  __int64 v302; // x8
  __int64 v303; // x10
  __int64 v304; // x9
  __int64 v305; // x8
  __int64 v306; // x11
  __int64 v307; // x0
  __int64 v308; // x0
  __int64 v309; // x8
  __int64 v310; // x0
  __int64 v311; // x0
  __int64 v312; // x8
  __int64 v313; // x0
  __int64 v314; // x0
  __int64 v315; // x0
  unsigned int v316; // w0
  unsigned int v317; // w20
  long double v318; // q0
  __int64 v319; // x8
  __int64 v320; // x9
  __int64 v321; // x12
  __int64 v322; // x8
  __int64 v323; // x13
  __int64 v324; // x0
  unsigned int v325; // w0
  unsigned int v326; // w20
  long double v327; // q0
  __int64 v328; // x8
  __int64 v329; // x9
  __int64 v330; // x12
  __int64 v331; // x8
  __int64 v332; // x13
  __int64 v333; // x0
  unsigned int v334; // w0
  unsigned int v335; // w20
  __int64 v336; // x8
  __int64 v337; // x9
  __int64 v338; // x12
  __int64 v339; // x8
  __int64 v340; // x13
  unsigned __int64 StatusReg; // x20
  __int64 v342; // x21
  __int64 v343; // x0
  __int64 v344; // x0
  __int64 v345; // x0
  __int64 v346; // x0
  __int64 v347; // x8
  __int64 v348; // x0
  __int64 v349; // x0
  __int64 v350; // x8
  __int64 v351; // x0
  __int64 v352; // x0
  __int64 v353; // x0
  __int64 v354; // x0
  unsigned int v355; // [xsp+14h] [xbp-CCh]
  unsigned int v356; // [xsp+14h] [xbp-CCh]
  char v357; // [xsp+18h] [xbp-C8h]
  int v358; // [xsp+1Ch] [xbp-C4h]
  unsigned int v359; // [xsp+20h] [xbp-C0h]
  int v360; // [xsp+24h] [xbp-BCh]
  __int16 v361; // [xsp+34h] [xbp-ACh] BYREF
  unsigned __int8 v362; // [xsp+36h] [xbp-AAh]
  _QWORD v363[2]; // [xsp+38h] [xbp-A8h] BYREF
  __int64 *v364; // [xsp+48h] [xbp-98h]
  _QWORD v365[2]; // [xsp+50h] [xbp-90h] BYREF
  _DWORD *v366; // [xsp+60h] [xbp-80h]
  _QWORD v367[4]; // [xsp+68h] [xbp-78h] BYREF
  __int64 v368; // [xsp+88h] [xbp-58h]
  __int64 v369; // [xsp+90h] [xbp-50h]
  __int64 v370; // [xsp+98h] [xbp-48h]
  __int64 v371; // [xsp+A0h] [xbp-40h]
  __int64 v372; // [xsp+A8h] [xbp-38h]
  __int64 v373; // [xsp+B0h] [xbp-30h]
  __int64 v374; // [xsp+B8h] [xbp-28h]
  __int64 v375; // [xsp+C0h] [xbp-20h]
  __int64 v376; // [xsp+C8h] [xbp-18h]
  __int64 v377; // [xsp+D0h] [xbp-10h]

  v377 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v375 = 0;
  v376 = 0;
  v374 = 0;
  v372 = 0;
  v373 = 0;
  v370 = 0;
  v371 = 0;
  v368 = 0;
  v369 = 0;
  memset(v367, 0, sizeof(v367));
  *(_BYTE *)(a1 + 15) = 0;
  upstream_type = find_upstream_type((char *)a1);
  if ( upstream_type == 2 )
  {
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa-wan %s:%d  query wifi-backhaul stats\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5640);
    }
    if ( (int)ipa3_ctx_get_type(0) >= 17 && (ipa3_ctx_get_flag(1) & 1) != 0 )
    {
      v365[0] = 0;
      v365[1] = 0;
      v366 = nullptr;
      v363[0] = 0;
      v363[1] = 0;
      v364 = nullptr;
      v361 = 0;
      v362 = 0;
      if ( (ipa_get_fnr_info(&v361) & 1) != 0 )
      {
        v9 = *(_BYTE *)(a1 + 20);
        LOBYTE(v365[0]) = HIBYTE(v361);
        BYTE1(v365[0]) = HIBYTE(v361) + 1;
        BYTE2(v365[0]) = v9;
        if ( (unsigned __int8)(HIBYTE(v361) + 1) - HIBYTE(v361) == 1 )
        {
          v366 = (_DWORD *)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
          if ( !v366 )
          {
            printk(&unk_3C20F6, "rmnet_ipa3_query_tethering_stats_fnr");
            v347 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v348 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v348 )
              {
                ipc_log_string(
                  v348,
                  "ipa %s:%d Failed to allocate memory for query hw-stats\n",
                  "rmnet_ipa3_query_tethering_stats_fnr",
                  5478);
                v347 = ipa3_ctx;
              }
              v349 = *(_QWORD *)(v347 + 34160);
              if ( v349 )
                ipc_log_string(
                  v349,
                  "ipa %s:%d Failed to allocate memory for query hw-stats\n",
                  "rmnet_ipa3_query_tethering_stats_fnr",
                  5478);
            }
            goto LABEL_447;
          }
          if ( (unsigned int)ipa_get_flt_rt_stats((unsigned __int8 *)v365) )
          {
            printk(&unk_3B0A9C, "rmnet_ipa3_query_tethering_stats_fnr");
            v107 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v108 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v108 )
              {
                ipc_log_string(
                  v108,
                  "ipa %s:%d Failed to request stats from h/w\n",
                  "rmnet_ipa3_query_tethering_stats_fnr",
                  5483);
                v107 = ipa3_ctx;
              }
              v109 = *(_QWORD *)(v107 + 34160);
              if ( v109 )
                ipc_log_string(
                  v109,
                  "ipa %s:%d Failed to request stats from h/w\n",
                  "rmnet_ipa3_query_tethering_stats_fnr",
                  5483);
            }
            kfree(v366);
          }
          else
          {
            if ( ipa3_get_ipc_logbuf() )
            {
              ipc_logbuf = ipa3_get_ipc_logbuf();
              ipc_log_string(
                ipc_logbuf,
                "ipa-wan %s:%d ul: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                "rmnet_ipa3_query_tethering_stats_fnr",
                5491,
                *((_QWORD *)v366 + 1),
                *v366,
                v366[1]);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v11 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v11,
                "ipa-wan %s:%d ul: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                "rmnet_ipa3_query_tethering_stats_fnr",
                5491,
                *((_QWORD *)v366 + 1),
                *v366,
                v366[1]);
            }
            if ( ipa3_get_ipc_logbuf() )
            {
              v12 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v12,
                "ipa-wan %s:%d dl: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                "rmnet_ipa3_query_tethering_stats_fnr",
                5495,
                *((_QWORD *)v366 + 3),
                v366[4],
                v366[5]);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v13 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v13,
                "ipa-wan %s:%d dl: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                "rmnet_ipa3_query_tethering_stats_fnr",
                5495,
                *((_QWORD *)v366 + 3),
                v366[4],
                v366[5]);
            }
            v14 = v366;
            v15 = v362;
            v16 = *(_BYTE *)(a1 + 20);
            v17 = v362 + 1;
            *(_QWORD *)(a1 + 24) = *((_QWORD *)v366 + 1);
            v18 = *((_QWORD *)v14 + 3);
            LOBYTE(v363[0]) = v15;
            BYTE1(v363[0]) = v17;
            *(_QWORD *)(a1 + 32) = v18;
            BYTE2(v363[0]) = v16;
            if ( v17 - v15 == 1 )
            {
              v364 = (__int64 *)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
              if ( v364 )
              {
                if ( (unsigned int)ipa_get_flt_rt_stats((unsigned __int8 *)v363) )
                {
                  printk(&unk_3B0A9C, "rmnet_ipa3_query_tethering_stats_fnr");
                  v112 = ipa3_ctx;
                  if ( ipa3_ctx )
                  {
                    v113 = *(_QWORD *)(ipa3_ctx + 34152);
                    if ( v113 )
                    {
                      ipc_log_string(
                        v113,
                        "ipa %s:%d Failed to request stats from h/w\n",
                        "rmnet_ipa3_query_tethering_stats_fnr",
                        5523);
                      v112 = ipa3_ctx;
                    }
                    v114 = *(_QWORD *)(v112 + 34160);
                    if ( v114 )
                      ipc_log_string(
                        v114,
                        "ipa %s:%d Failed to request stats from h/w\n",
                        "rmnet_ipa3_query_tethering_stats_fnr",
                        5523);
                  }
                }
                else
                {
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v19 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v19,
                      "ipa-wan %s:%d ul sw: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                      "rmnet_ipa3_query_tethering_stats_fnr",
                      5531,
                      v364[1],
                      *(_DWORD *)v364,
                      *((_DWORD *)v364 + 1));
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v20 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v20,
                      "ipa-wan %s:%d ul sw: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                      "rmnet_ipa3_query_tethering_stats_fnr",
                      5531,
                      v364[1],
                      *(_DWORD *)v364,
                      *((_DWORD *)v364 + 1));
                  }
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v21 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v21,
                      "ipa-wan %s:%d dl sw: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                      "rmnet_ipa3_query_tethering_stats_fnr",
                      5535,
                      v364[3],
                      *((_DWORD *)v364 + 4),
                      *((_DWORD *)v364 + 5));
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v22 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v22,
                      "ipa-wan %s:%d dl sw: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                      "rmnet_ipa3_query_tethering_stats_fnr",
                      5535,
                      v364[3],
                      *((_DWORD *)v364 + 4),
                      *((_DWORD *)v364 + 5));
                  }
                  v364[1] += *((_QWORD *)v366 + 1);
                  *(_DWORD *)v364 += *v366;
                  *((_DWORD *)v364 + 1) += v366[1];
                  v364[3] += *((_QWORD *)v366 + 3);
                  *((_DWORD *)v364 + 4) += v366[4];
                  *((_DWORD *)v364 + 5) += v366[5];
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v23 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v23,
                      "ipa-wan %s:%d ul sw: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                      "rmnet_ipa3_query_tethering_stats_fnr",
                      5554,
                      v364[1],
                      *(_DWORD *)v364,
                      *((_DWORD *)v364 + 1));
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v24 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v24,
                      "ipa-wan %s:%d ul sw: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                      "rmnet_ipa3_query_tethering_stats_fnr",
                      5554,
                      v364[1],
                      *(_DWORD *)v364,
                      *((_DWORD *)v364 + 1));
                  }
                  if ( ipa3_get_ipc_logbuf() )
                  {
                    v25 = ipa3_get_ipc_logbuf();
                    ipc_log_string(
                      v25,
                      "ipa-wan %s:%d dl sw: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                      "rmnet_ipa3_query_tethering_stats_fnr",
                      5558,
                      v364[3],
                      *((_DWORD *)v364 + 4),
                      *((_DWORD *)v364 + 5));
                  }
                  if ( ipa3_get_ipc_logbuf_low() )
                  {
                    v26 = ipa3_get_ipc_logbuf_low();
                    ipc_log_string(
                      v26,
                      "ipa-wan %s:%d dl sw: bytes = %llu, pkts = %u, pkts_hash = %u\n",
                      "rmnet_ipa3_query_tethering_stats_fnr",
                      5558,
                      v364[3],
                      *((_DWORD *)v364 + 4),
                      *((_DWORD *)v364 + 5));
                  }
                  if ( (unsigned int)ipa_set_flt_rt_stats(v362, *v364, v364[1]) )
                  {
                    printk(&unk_3E782A, "rmnet_ipa3_query_tethering_stats_fnr");
                    v115 = ipa3_ctx;
                    if ( ipa3_ctx )
                    {
                      v116 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v116 )
                      {
                        ipc_log_string(
                          v116,
                          "ipa %s:%d Failed to set stats to sw-cache %d\n",
                          "rmnet_ipa3_query_tethering_stats_fnr",
                          5564,
                          v362);
                        v115 = ipa3_ctx;
                      }
                      v117 = *(_QWORD *)(v115 + 34160);
                      if ( v117 )
                        ipc_log_string(
                          v117,
                          "ipa %s:%d Failed to set stats to sw-cache %d\n",
                          "rmnet_ipa3_query_tethering_stats_fnr",
                          5564,
                          v362);
                    }
                  }
                  else
                  {
                    if ( !(unsigned int)ipa_set_flt_rt_stats((unsigned int)v362 + 1, v364[2], v364[3]) )
                    {
                      v27 = 0;
                      v28 = 1;
                      goto LABEL_49;
                    }
                    printk(&unk_3E782A, "rmnet_ipa3_query_tethering_stats_fnr");
                    v118 = ipa3_ctx;
                    if ( ipa3_ctx )
                    {
                      v119 = *(_QWORD *)(ipa3_ctx + 34152);
                      if ( v119 )
                      {
                        ipc_log_string(
                          v119,
                          "ipa %s:%d Failed to set stats to sw-cache %d\n",
                          "rmnet_ipa3_query_tethering_stats_fnr",
                          5573,
                          v362 + 1);
                        v118 = ipa3_ctx;
                      }
                      v120 = *(_QWORD *)(v118 + 34160);
                      if ( v120 )
                        ipc_log_string(
                          v120,
                          "ipa %s:%d Failed to set stats to sw-cache %d\n",
                          "rmnet_ipa3_query_tethering_stats_fnr",
                          5573,
                          (unsigned int)v362 + 1);
                    }
                  }
                }
                v28 = 0;
                v27 = -22;
LABEL_49:
                kfree(v364);
                kfree(v366);
                if ( (v28 & 1) != 0 )
                {
                  result = 0;
                  goto LABEL_454;
                }
LABEL_448:
                if ( (unsigned int)__ratelimit(
                                     &rmnet_ipa3_query_tethering_stats_all__rs_64,
                                     "rmnet_ipa3_query_tethering_stats_all") )
                {
                  printk(&unk_3F9161, "rmnet_ipa3_query_tethering_stats_all");
                  if ( !ipa3_get_ipc_logbuf() )
                  {
LABEL_451:
                    if ( ipa3_get_ipc_logbuf_low() )
                    {
                      v354 = ipa3_get_ipc_logbuf_low();
                      ipc_log_string(
                        v354,
                        "ipa-wan %s:%d wlan WAN_IOC_QUERY_TETHER_STATS failed\n",
                        "rmnet_ipa3_query_tethering_stats_all",
                        5661);
                    }
LABEL_453:
                    result = v27;
                    goto LABEL_454;
                  }
                }
                else if ( !ipa3_get_ipc_logbuf() )
                {
                  goto LABEL_451;
                }
                v353 = ipa3_get_ipc_logbuf();
                ipc_log_string(
                  v353,
                  "ipa-wan %s:%d wlan WAN_IOC_QUERY_TETHER_STATS failed\n",
                  "rmnet_ipa3_query_tethering_stats_all",
                  5661);
                goto LABEL_451;
              }
              printk(&unk_3A7D5E, "rmnet_ipa3_query_tethering_stats_fnr");
              v350 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v351 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v351 )
                {
                  ipc_log_string(
                    v351,
                    "ipa %s:%d Failed to allocate memory for query sw-stats\n",
                    "rmnet_ipa3_query_tethering_stats_fnr",
                    5518);
                  v350 = ipa3_ctx;
                }
                v352 = *(_QWORD *)(v350 + 34160);
                if ( v352 )
                  ipc_log_string(
                    v352,
                    "ipa %s:%d Failed to allocate memory for query sw-stats\n",
                    "rmnet_ipa3_query_tethering_stats_fnr",
                    5518);
              }
LABEL_447:
              v27 = -12;
              goto LABEL_448;
            }
            printk(&unk_3C20CF, "rmnet_ipa3_query_tethering_stats_fnr");
            if ( ipa3_get_ipc_logbuf() )
            {
              v110 = ipa3_get_ipc_logbuf();
              ipc_log_string(
                v110,
                "ipa-wan %s:%d Only query 2 counters\n",
                "rmnet_ipa3_query_tethering_stats_fnr",
                5509);
            }
            if ( ipa3_get_ipc_logbuf_low() )
            {
              v111 = ipa3_get_ipc_logbuf_low();
              ipc_log_string(
                v111,
                "ipa-wan %s:%d Only query 2 counters\n",
                "rmnet_ipa3_query_tethering_stats_fnr",
                5509);
            }
          }
        }
        else
        {
          printk(&unk_3C20CF, "rmnet_ipa3_query_tethering_stats_fnr");
          if ( ipa3_get_ipc_logbuf() )
          {
            v105 = ipa3_get_ipc_logbuf();
            ipc_log_string(v105, "ipa-wan %s:%d Only query 2 counters\n", "rmnet_ipa3_query_tethering_stats_fnr", 5469);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v106 = ipa3_get_ipc_logbuf_low();
            ipc_log_string(v106, "ipa-wan %s:%d Only query 2 counters\n", "rmnet_ipa3_query_tethering_stats_fnr", 5469);
          }
        }
      }
      else
      {
        printk(&unk_3AA56F, "rmnet_ipa3_query_tethering_stats_fnr");
        v102 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v103 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v103 )
          {
            ipc_log_string(
              v103,
              "ipa %s:%d FNR counter haven't configured\n",
              "rmnet_ipa3_query_tethering_stats_fnr",
              5459);
            v102 = ipa3_ctx;
          }
          v104 = *(_QWORD *)(v102 + 34160);
          if ( v104 )
            ipc_log_string(
              v104,
              "ipa %s:%d FNR counter haven't configured\n",
              "rmnet_ipa3_query_tethering_stats_fnr",
              5459);
        }
      }
      v27 = -22;
      goto LABEL_448;
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v37 = ipa3_get_ipc_logbuf();
      type = ipa3_ctx_get_type(0);
      flag = ipa3_ctx_get_flag(1);
      ipc_log_string(
        v37,
        "ipa-wan %s:%d hw version %d,hw_stats.enabled %d\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5645,
        type,
        flag & 1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v40 = ipa3_get_ipc_logbuf_low();
      v41 = ipa3_ctx_get_type(0);
      v42 = ipa3_ctx_get_flag(1);
      ipc_log_string(
        v40,
        "ipa-wan %s:%d hw version %d,hw_stats.enabled %d\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5645,
        v41,
        v42 & 1);
    }
    result = rmnet_ipa3_query_tethering_stats_wifi(v367, *(_BYTE *)(a1 + 20) != 0);
    if ( !(_DWORD)result )
      goto LABEL_67;
    v27 = result;
    if ( (unsigned int)__ratelimit(&rmnet_ipa3_query_tethering_stats_all__rs, "rmnet_ipa3_query_tethering_stats_all") )
    {
      printk(&unk_3F9161, "rmnet_ipa3_query_tethering_stats_all");
      if ( !ipa3_get_ipc_logbuf() )
      {
LABEL_65:
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v44 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(
            v44,
            "ipa-wan %s:%d wlan WAN_IOC_QUERY_TETHER_STATS failed\n",
            "rmnet_ipa3_query_tethering_stats_all",
            5650);
        }
        goto LABEL_453;
      }
    }
    else if ( !ipa3_get_ipc_logbuf() )
    {
      goto LABEL_65;
    }
    v43 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v43,
      "ipa-wan %s:%d wlan WAN_IOC_QUERY_TETHER_STATS failed\n",
      "rmnet_ipa3_query_tethering_stats_all",
      5650);
    goto LABEL_65;
  }
  if ( upstream_type == 3 )
  {
    printk(&unk_3E1E82, "rmnet_ipa3_query_tethering_stats_all");
    if ( ipa3_get_ipc_logbuf() )
    {
      v96 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v96,
        "ipa-wan %s:%d  Wrong upstreamIface name %s\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5638,
        (const char *)a1);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v97 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v97,
        "ipa-wan %s:%d  Wrong upstreamIface name %s\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5638,
        (const char *)a1);
      result = 0;
    }
    goto LABEL_454;
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v3 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v3, "ipa-wan %s:%d  query modem-backhaul stats\n", "rmnet_ipa3_query_tethering_stats_all", 5666);
  }
  LODWORD(v368) = *(_DWORD *)(a1 + 16);
  if ( (int)ipa3_ctx_get_type(0) < 14 || (ipa3_ctx_get_flag(1) & 1) == 0 )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v30 = ipa3_get_ipc_logbuf();
      v31 = ipa3_ctx_get_type(0);
      v32 = ipa3_ctx_get_flag(1);
      ipc_log_string(
        v30,
        "ipa-wan %s:%d hw version %d,hw_stats.enabled %d\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5672,
        v31,
        v32 & 1);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v33 = ipa3_get_ipc_logbuf_low();
      v34 = ipa3_ctx_get_type(0);
      v35 = ipa3_ctx_get_flag(1);
      ipc_log_string(
        v33,
        "ipa-wan %s:%d hw version %d,hw_stats.enabled %d\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5672,
        v34,
        v35 & 1);
    }
    tethering_stats_modem = rmnet_ipa3_query_tethering_stats_modem((__int64)v367, *(_BYTE *)(a1 + 20) != 0);
    if ( !tethering_stats_modem )
      goto LABEL_56;
    v27 = tethering_stats_modem;
    printk(&unk_3E1EB0, "rmnet_ipa3_query_tethering_stats_all");
    if ( ipa3_get_ipc_logbuf() )
    {
      v98 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v98,
        "ipa-wan %s:%d modem QUERY_TETHER_STATS failed\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5677);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v99 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v99,
        "ipa-wan %s:%d modem QUERY_TETHER_STATS failed\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5677);
    }
    goto LABEL_453;
  }
  v4 = (__int64)&off_1F7000;
  v5 = *(_DWORD *)(ipa3_ctx + 32240);
  switch ( v5 )
  {
    case 20:
LABEL_10:
      v360 = 0;
      LOBYTE(v6) = 0;
      LODWORD(v7) = 0;
      goto LABEL_71;
    case 24:
      LODWORD(v7) = 3;
      LOBYTE(v6) = 1;
      break;
    case 23:
      goto LABEL_10;
    default:
      LOBYTE(v6) = 0;
      LODWORD(v7) = 4;
      break;
  }
  v360 = 1;
LABEL_71:
  LODWORD(v46) = *(unsigned __int8 *)(a1 + 20);
  teth_stats = ipa_get_teth_stats();
  v48 = ipa3_get_ipc_logbuf();
  if ( teth_stats )
  {
    if ( v48 )
    {
      v100 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v100,
        "ipa-wan %s:%d ipa_get_teth_stats failed %d,\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        4951,
        teth_stats);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v101 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v101,
        "ipa-wan %s:%d ipa_get_teth_stats failed %d,\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        4951,
        teth_stats);
    }
    LODWORD(v46) = teth_stats;
    goto LABEL_432;
  }
  if ( v48 )
  {
    v49 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v49,
      "ipa-wan %s:%d reset the pipe stats? (%d)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      4956,
      (_DWORD)v46 != 0);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v50 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v50,
      "ipa-wan %s:%d reset the pipe stats? (%d)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      4956,
      (_DWORD)v46 != 0);
  }
  v51 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 864);
  if ( !v51 )
  {
LABEL_427:
    printk(&unk_3A7D98, "rmnet_ipa3_query_tethering_stats_hw");
    if ( ipa3_get_ipc_logbuf() )
    {
      v343 = ipa3_get_ipc_logbuf();
      ipc_log_string(v343, "ipa-wan %s:%d no memory\n", "rmnet_ipa3_query_tethering_stats_hw", 4959);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v344 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v344, "ipa-wan %s:%d no memory\n", "rmnet_ipa3_query_tethering_stats_hw", 4959);
    }
    LODWORD(v46) = -12;
LABEL_432:
    printk(&unk_3E1EB0, "rmnet_ipa3_query_tethering_stats_all");
    if ( ipa3_get_ipc_logbuf() )
    {
      v345 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v345,
        "ipa-wan %s:%d modem QUERY_TETHER_STATS failed\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5685);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v346 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v346,
        "ipa-wan %s:%d modem QUERY_TETHER_STATS failed\n",
        "rmnet_ipa3_query_tethering_stats_all",
        5685);
    }
    result = (unsigned int)v46;
    goto LABEL_454;
  }
  while ( 1 )
  {
    if ( *(_BYTE *)(rmnet_ipa3_ctx + 1992) == 1 )
    {
      v52 = ((__int64 (__fastcall *)(__int64, __int64, bool))ipa_query_teth_stats)(96, v51, (_DWORD)v46 != 0);
      if ( v52 )
      {
        LODWORD(v46) = v52;
        printk(&unk_3B62F3, "rmnet_ipa3_query_tethering_stats_hw");
        v53 = *(_QWORD *)(v4 + 2056);
        if ( v53 )
        {
          v54 = *(_QWORD *)(v53 + 34152);
          if ( v54 )
          {
            ipc_log_string(
              v54,
              "ipa %s:%d MHI_PRIME_TETH_PROD query failed %d,\n",
              "rmnet_ipa3_query_tethering_stats_hw",
              4967,
              (_DWORD)v46);
            v53 = *(_QWORD *)(v4 + 2056);
          }
          v55 = *(_QWORD *)(v53 + 34160);
          if ( v55 )
            ipc_log_string(
              v55,
              "ipa %s:%d MHI_PRIME_TETH_PROD query failed %d,\n",
              "rmnet_ipa3_query_tethering_stats_hw",
              4967,
              (unsigned int)v46);
        }
LABEL_202:
        kfree(v51);
        goto LABEL_432;
      }
    }
    else
    {
      v56 = ((__int64 (__fastcall *)(__int64, __int64, bool))ipa_query_teth_stats)(52, v51, (_DWORD)v46 != 0);
      if ( v56 )
      {
        LODWORD(v46) = v56;
        printk(&unk_3FC541, "rmnet_ipa3_query_tethering_stats_hw");
        v121 = *(_QWORD *)(v4 + 2056);
        if ( v121 )
        {
          v122 = *(_QWORD *)(v121 + 34152);
          if ( v122 )
          {
            ipc_log_string(
              v122,
              "ipa %s:%d IPA_CLIENT_Q6_WAN_PROD query failed %d,\n",
              "rmnet_ipa3_query_tethering_stats_hw",
              4975,
              (_DWORD)v46);
            v121 = *(_QWORD *)(v4 + 2056);
          }
          v123 = *(_QWORD *)(v121 + 34160);
          if ( v123 )
            ipc_log_string(
              v123,
              "ipa %s:%d IPA_CLIENT_Q6_WAN_PROD query failed %d,\n",
              "rmnet_ipa3_query_tethering_stats_hw",
              4975,
              (unsigned int)v46);
        }
        goto LABEL_202;
      }
    }
    if ( *(_BYTE *)(*(_QWORD *)(v4 + 2056) + 32266LL) )
      v4 = 13;
    else
      v4 = 11;
    ep_mapping = ipa_get_ep_mapping((unsigned int)v4);
    if ( ep_mapping == -1 )
      goto LABEL_425;
    v58 = ep_mapping;
    v358 = (int)v46;
    v359 = (unsigned int)v7;
    v357 = (char)v6;
    LODWORD(v46) = ep_mapping;
    if ( ep_mapping >= (unsigned int)ipa3_get_max_num_pipes() )
      goto LABEL_423;
    if ( ipa3_get_ipc_logbuf() )
    {
      v59 = ipa3_get_ipc_logbuf();
      if ( v58 >= 0x24 )
        goto LABEL_426;
      ipc_log_string(
        v59,
        "ipa-wan %s:%d wlan: v4_rx_p-b(%d,%lld) v6_rx_p-b(%d,%lld),client(%d)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        4996,
        *(_DWORD *)(v51 + 24LL * v58 + 16),
        *(_QWORD *)(v51 + 24LL * v58),
        *(_DWORD *)(v51 + 24LL * v58 + 20),
        *(_QWORD *)(v51 + 24LL * v58 + 8),
        v4);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v60 = ipa3_get_ipc_logbuf_low();
      if ( v58 > 0x23 )
        goto LABEL_426;
      ipc_log_string(
        v60,
        "ipa-wan %s:%d wlan: v4_rx_p-b(%d,%lld) v6_rx_p-b(%d,%lld),client(%d)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        4996,
        *(_DWORD *)(v51 + 24LL * v58 + 16),
        *(_QWORD *)(v51 + 24LL * v58),
        *(_DWORD *)(v51 + 24LL * v58 + 20),
        *(_QWORD *)(v51 + 24LL * v58 + 8),
        v4);
    }
    v61 = ipa_get_ep_mapping(19);
    if ( v61 == -1 )
      goto LABEL_425;
    LODWORD(v7) = v61;
    LODWORD(v46) = v61;
    if ( v61 >= (unsigned int)ipa3_get_max_num_pipes() )
      goto LABEL_423;
    if ( ipa3_get_ipc_logbuf() )
    {
      v62 = ipa3_get_ipc_logbuf();
      if ( (unsigned int)v7 > 0x23 )
        goto LABEL_426;
      ipc_log_string(
        v62,
        "ipa-wan %s:%d usb: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5008,
        *(_DWORD *)(v51 + 24LL * (unsigned int)v7 + 16),
        *(_QWORD *)(v51 + 24LL * (unsigned int)v7),
        *(_DWORD *)(v51 + 24LL * (unsigned int)v7 + 20),
        *(_QWORD *)(v51 + 24LL * (unsigned int)v7 + 8));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v64 = ipa3_get_ipc_logbuf_low();
      if ( (unsigned int)v7 > 0x23 )
        goto LABEL_426;
      v63 = ipc_log_string(
              v64,
              "ipa-wan %s:%d usb: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
              "rmnet_ipa3_query_tethering_stats_hw",
              5008,
              *(_DWORD *)(v51 + 24LL * (unsigned int)v7 + 16),
              *(_QWORD *)(v51 + 24LL * (unsigned int)v7),
              *(_DWORD *)(v51 + 24LL * (unsigned int)v7 + 20),
              *(_QWORD *)(v51 + 24LL * (unsigned int)v7 + 8));
    }
    if ( v360 )
    {
      v4 = 0;
      v46 = "rmnet_ipa3_query_tethering_stats_hw";
      if ( v359 <= 1 )
        v65 = 1;
      else
        v65 = v359;
      while ( 1 )
      {
        wigig_cons = rmnet_ipa3_get_wigig_cons((unsigned int)v4, v63);
        v67 = ipa_get_ep_mapping(wigig_cons);
        if ( v67 == -1 )
          break;
        LODWORD(v6) = v67;
        if ( v67 >= (unsigned int)ipa3_get_max_num_pipes() )
        {
          LODWORD(v46) = (_DWORD)v6;
          goto LABEL_423;
        }
        v68 = (_QWORD *)(v51 + 24LL * (unsigned int)v6);
        if ( ipa3_get_ipc_logbuf() )
        {
          v69 = ipa3_get_ipc_logbuf();
          if ( (unsigned int)v6 > 0x23 )
            goto LABEL_426;
          ipc_log_string(
            v69,
            "ipa-wan %s:%d wigig%d: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
            "rmnet_ipa3_query_tethering_stats_hw",
            5025,
            v4 + 1,
            *((_DWORD *)v68 + 4),
            *v68,
            *((_DWORD *)v68 + 5),
            v68[1]);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v70 = ipa3_get_ipc_logbuf_low();
          if ( (unsigned int)v6 > 0x23 )
            goto LABEL_426;
          v4 = (unsigned int)(v4 + 1);
          v63 = ipc_log_string(
                  v70,
                  "ipa-wan %s:%d wigig%d: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
                  "rmnet_ipa3_query_tethering_stats_hw",
                  5025,
                  v4,
                  *((_DWORD *)v68 + 4),
                  *v68,
                  *((_DWORD *)v68 + 5),
                  v68[1]);
          if ( (_DWORD)v4 == v65 )
            goto LABEL_117;
        }
        else
        {
          v4 = (unsigned int)(v4 + 1);
          if ( (_DWORD)v4 == v65 )
            goto LABEL_117;
        }
      }
LABEL_425:
      LODWORD(v46) = -1;
      goto LABEL_432;
    }
LABEL_117:
    if ( v58 <= 0x23 && (unsigned int)v7 <= 0x23 )
    {
      v4 = v51;
      v71 = v51 + 24LL * v58;
      v6 = (_QWORD *)(v51 + 24LL * (unsigned int)v7);
      v72 = *(_DWORD *)(v71 + 20);
      v73 = *((_DWORD *)v6 + 5);
      v74 = (unsigned int)(*((_DWORD *)v6 + 4) + *(_DWORD *)(v71 + 16));
      v75 = *v6 + *(_QWORD *)v71;
      v76 = v6[1] + *(_QWORD *)(v71 + 8);
      v371 = v74;
      v372 = v75;
      v375 = (unsigned int)(v73 + v72);
      v376 = v76;
      if ( v360 )
      {
        if ( v359 <= 1 )
          v77 = 1;
        else
          v77 = v359;
        v78 = rmnet_ipa3_get_wigig_cons(0, v63);
        v79 = ipa_get_ep_mapping(v78);
        if ( v79 == -1 )
          goto LABEL_425;
        v80 = v79;
        LODWORD(v46) = v79;
        if ( v79 >= (unsigned int)ipa3_get_max_num_pipes() )
          goto LABEL_423;
        if ( (unsigned int)v46 > 0x23 )
          goto LABEL_426;
        v4 = v51;
        v82 = v51 + 24LL * v80;
        v83 = *(unsigned int *)(v82 + 16);
        v84 = *(unsigned int *)(v82 + 20);
        v86 = *(_QWORD *)v82;
        v85 = *(_QWORD *)(v82 + 8);
        v371 += v83;
        v372 += v86;
        v375 += v84;
        v376 += v85;
        if ( v77 != 1 )
        {
          v165 = rmnet_ipa3_get_wigig_cons(1, v81);
          v166 = ipa_get_ep_mapping(v165);
          if ( v166 == -1 )
            goto LABEL_425;
          v167 = v166;
          LODWORD(v46) = v166;
          if ( v166 >= (unsigned int)ipa3_get_max_num_pipes() )
            goto LABEL_423;
          if ( (unsigned int)v46 > 0x23 )
            goto LABEL_426;
          v169 = v51 + 24LL * v167;
          v170 = *(unsigned int *)(v169 + 16);
          v171 = *(unsigned int *)(v169 + 20);
          v173 = *(_QWORD *)v169;
          v172 = *(_QWORD *)(v169 + 8);
          v371 += v170;
          v372 += v173;
          v375 += v171;
          v376 += v172;
          v174 = rmnet_ipa3_get_wigig_cons(2, v168);
          v175 = ipa_get_ep_mapping(v174);
          if ( v175 == -1 )
            goto LABEL_425;
          v176 = v175;
          LODWORD(v46) = v175;
          if ( v175 >= (unsigned int)ipa3_get_max_num_pipes() )
            goto LABEL_423;
          if ( (unsigned int)v46 > 0x23 )
            goto LABEL_426;
          v4 = v51;
          v178 = v51 + 24LL * v176;
          v179 = *(unsigned int *)(v178 + 16);
          v180 = *(unsigned int *)(v178 + 20);
          v182 = *(_QWORD *)v178;
          v181 = *(_QWORD *)(v178 + 8);
          v371 += v179;
          v372 += v182;
          v375 += v180;
          v376 += v181;
          if ( (v357 & 1) == 0 )
          {
            v183 = rmnet_ipa3_get_wigig_cons(3, v177);
            v184 = ipa_get_ep_mapping(v183);
            if ( v184 == -1 )
              goto LABEL_425;
            v185 = v184;
            LODWORD(v46) = v184;
            if ( v184 >= (unsigned int)ipa3_get_max_num_pipes() )
              goto LABEL_423;
            if ( (unsigned int)v46 > 0x23 )
              goto LABEL_426;
            v4 = v51;
            v186 = v51 + 24LL * v185;
            v187 = *(unsigned int *)(v186 + 16);
            v188 = *(unsigned int *)(v186 + 20);
            v190 = *(_QWORD *)v186;
            v189 = *(_QWORD *)(v186 + 8);
            v371 += v187;
            v372 += v190;
            v375 += v188;
            v376 += v189;
          }
        }
      }
      v87 = v358;
      if ( ipa3_get_ipc_logbuf() )
      {
        v88 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v88,
          "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5065,
          v371,
          v375,
          v372,
          v376);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v89 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v89,
          "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5065,
          v371,
          v375,
          v372,
          v376);
      }
      if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x11u || *(_DWORD *)(ipa3_ctx + 32256) == 2 )
        goto LABEL_133;
      memset((void *)v4, 0, 0x360u);
      v124 = ((__int64 (__fastcall *)(__int64, __int64, bool))ipa_query_teth_stats)(74, v4, v358 != 0);
      if ( v124 )
      {
        LODWORD(v46) = v124;
        printk(&unk_3E49C0, "rmnet_ipa3_query_tethering_stats_hw");
        v253 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v254 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v254 )
          {
            ipc_log_string(
              v254,
              "ipa %s:%d IPA_CLIENT_Q6_DL_NLO_DATA_PROD query failed %d,\n",
              "rmnet_ipa3_query_tethering_stats_hw",
              5075,
              (_DWORD)v46);
            v253 = ipa3_ctx;
          }
          v255 = *(_QWORD *)(v253 + 34160);
          if ( v255 )
            ipc_log_string(
              v255,
              "ipa %s:%d IPA_CLIENT_Q6_DL_NLO_DATA_PROD query failed %d,\n",
              "rmnet_ipa3_query_tethering_stats_hw",
              5075,
              (unsigned int)v46);
        }
        goto LABEL_356;
      }
      if ( *(_BYTE *)(ipa3_ctx + 32266) )
        v125 = 13;
      else
        v125 = 11;
      v126 = ipa_get_ep_mapping(v125);
      if ( v126 == -1 )
        goto LABEL_425;
      v355 = v126;
      LODWORD(v46) = v126;
      if ( v126 >= (unsigned int)ipa3_get_max_num_pipes() )
        goto LABEL_423;
      if ( ipa3_get_ipc_logbuf() )
      {
        v127 = ipa3_get_ipc_logbuf();
        if ( v355 > 0x23 )
          goto LABEL_426;
        ipc_log_string(
          v127,
          "ipa-wan %s:%d wlan: v4_rx_p-b(%d,%lld) v6_rx_p-b(%d,%lld),client(%d)\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5095,
          *(_DWORD *)(v51 + 24LL * v355 + 16),
          *(_QWORD *)(v51 + 24LL * v355),
          *(_DWORD *)(v51 + 24LL * v355 + 20),
          *(_QWORD *)(v51 + 24LL * v355 + 8),
          v125);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v128 = ipa3_get_ipc_logbuf_low();
        if ( v355 > 0x23 )
          goto LABEL_426;
        ipc_log_string(
          v128,
          "ipa-wan %s:%d wlan: v4_rx_p-b(%d,%lld) v6_rx_p-b(%d,%lld),client(%d)\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5095,
          *(_DWORD *)(v51 + 24LL * v355 + 16),
          *(_QWORD *)(v51 + 24LL * v355),
          *(_DWORD *)(v51 + 24LL * v355 + 20),
          *(_QWORD *)(v51 + 24LL * v355 + 8),
          v125);
      }
      if ( ipa3_get_ipc_logbuf() )
      {
        v129 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v129,
          "ipa-wan %s:%d usb: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5101,
          *((_DWORD *)v6 + 4),
          *v6,
          *((_DWORD *)v6 + 5),
          v6[1]);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v131 = ipa3_get_ipc_logbuf_low();
        v130 = ipc_log_string(
                 v131,
                 "ipa-wan %s:%d usb: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
                 "rmnet_ipa3_query_tethering_stats_hw",
                 5101,
                 *((_DWORD *)v6 + 4),
                 *v6,
                 *((_DWORD *)v6 + 5),
                 v6[1]);
      }
      if ( v360 )
      {
        v132 = 0;
        v4 = (__int64)"ipa-wan %s:%d wigig%d: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n";
        if ( v359 <= 1 )
          LODWORD(v7) = 1;
        else
          LODWORD(v7) = v359;
        while ( 1 )
        {
          v133 = rmnet_ipa3_get_wigig_cons(v132, v130);
          LODWORD(v46) = ipa_get_ep_mapping(v133);
          if ( (_DWORD)v46 == -1 )
            goto LABEL_432;
          if ( (unsigned int)v46 >= (unsigned int)ipa3_get_max_num_pipes() )
            goto LABEL_423;
          v134 = (_QWORD *)(v51 + 24LL * (unsigned int)v46);
          if ( ipa3_get_ipc_logbuf() )
          {
            v135 = ipa3_get_ipc_logbuf();
            if ( (unsigned int)v46 > 0x23 )
              goto LABEL_426;
            ipc_log_string(
              v135,
              "ipa-wan %s:%d wigig%d: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
              "rmnet_ipa3_query_tethering_stats_hw",
              5117,
              v132 + 1,
              *((_DWORD *)v134 + 4),
              *v134,
              *((_DWORD *)v134 + 5),
              v134[1]);
          }
          if ( ipa3_get_ipc_logbuf_low() )
          {
            v136 = ipa3_get_ipc_logbuf_low();
            if ( (unsigned int)v46 > 0x23 )
              goto LABEL_426;
            v130 = ipc_log_string(
                     v136,
                     "ipa-wan %s:%d wigig%d: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
                     "rmnet_ipa3_query_tethering_stats_hw",
                     5117,
                     ++v132,
                     *((_DWORD *)v134 + 4),
                     *v134,
                     *((_DWORD *)v134 + 5),
                     v134[1]);
            if ( v132 == (_DWORD)v7 )
              break;
          }
          else if ( ++v132 == (_DWORD)v7 )
          {
            break;
          }
        }
      }
      if ( v355 <= 0x23 )
        break;
    }
LABEL_426:
    __break(0x5512u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v342 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &rmnet_ipa3_query_tethering_stats_hw__alloc_tag;
    v51 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 864);
    *(_QWORD *)(StatusReg + 80) = v342;
    if ( !v51 )
      goto LABEL_427;
  }
  v4 = v51;
  v137 = v51 + 24LL * v355;
  v138 = v6[1];
  v139 = *(_DWORD *)(v137 + 20);
  v140 = (unsigned int)(*((_DWORD *)v6 + 4) + *(_DWORD *)(v137 + 16));
  v142 = *(_QWORD *)v137;
  v141 = *(_QWORD *)(v137 + 8);
  v143 = (unsigned int)(*((_DWORD *)v6 + 5) + v139);
  v144 = *v6 + v372 + v142;
  v371 += v140;
  v372 = v144;
  v375 += v143;
  v376 += v138 + v141;
  if ( v360 )
  {
    if ( v359 <= 1 )
      v145 = 1;
    else
      v145 = v359;
    v146 = rmnet_ipa3_get_wigig_cons(0, v130);
    v147 = ipa_get_ep_mapping(v146);
    if ( v147 == -1 )
      goto LABEL_425;
    v148 = v147;
    LODWORD(v46) = v147;
    if ( v147 >= (unsigned int)ipa3_get_max_num_pipes() )
      goto LABEL_423;
    if ( (unsigned int)v46 > 0x23 )
      goto LABEL_426;
    v4 = v51;
    v150 = v51 + 24LL * v148;
    v151 = *(unsigned int *)(v150 + 16);
    v152 = *(unsigned int *)(v150 + 20);
    v154 = *(_QWORD *)v150;
    v153 = *(_QWORD *)(v150 + 8);
    v371 += v151;
    v372 += v154;
    v375 += v152;
    v376 += v153;
    if ( v145 != 1 )
    {
      v256 = rmnet_ipa3_get_wigig_cons(1, v149);
      v257 = ipa_get_ep_mapping(v256);
      if ( v257 == -1 )
        goto LABEL_425;
      v258 = v257;
      LODWORD(v46) = v257;
      if ( v257 >= (unsigned int)ipa3_get_max_num_pipes() )
        goto LABEL_423;
      if ( (unsigned int)v46 > 0x23 )
        goto LABEL_426;
      v260 = v51 + 24LL * v258;
      v261 = *(unsigned int *)(v260 + 16);
      v262 = *(unsigned int *)(v260 + 20);
      v264 = *(_QWORD *)v260;
      v263 = *(_QWORD *)(v260 + 8);
      v371 += v261;
      v372 += v264;
      v375 += v262;
      v376 += v263;
      v265 = rmnet_ipa3_get_wigig_cons(2, v259);
      v266 = ipa_get_ep_mapping(v265);
      if ( v266 == -1 )
        goto LABEL_425;
      v267 = v266;
      LODWORD(v46) = v266;
      if ( v266 >= (unsigned int)ipa3_get_max_num_pipes() )
        goto LABEL_423;
      if ( (unsigned int)v46 > 0x23 )
        goto LABEL_426;
      v4 = v51;
      v269 = v51 + 24LL * v267;
      v270 = *(unsigned int *)(v269 + 16);
      v271 = *(unsigned int *)(v269 + 20);
      v273 = *(_QWORD *)v269;
      v272 = *(_QWORD *)(v269 + 8);
      v371 += v270;
      v372 += v273;
      v375 += v271;
      v376 += v272;
      if ( (v357 & 1) == 0 )
      {
        v274 = rmnet_ipa3_get_wigig_cons(3, v268);
        v275 = ipa_get_ep_mapping(v274);
        if ( v275 == -1 )
          goto LABEL_425;
        v276 = v275;
        LODWORD(v46) = v275;
        if ( v275 >= (unsigned int)ipa3_get_max_num_pipes() )
          goto LABEL_423;
        if ( (unsigned int)v46 > 0x23 )
          goto LABEL_426;
        v4 = v51;
        v277 = v51 + 24LL * v276;
        v278 = *(unsigned int *)(v277 + 16);
        v279 = *(unsigned int *)(v277 + 20);
        v281 = *(_QWORD *)v277;
        v280 = *(_QWORD *)(v277 + 8);
        v371 += v278;
        v372 += v281;
        v375 += v279;
        v376 += v280;
      }
    }
  }
  v87 = v358;
  if ( ipa3_get_ipc_logbuf() )
  {
    v155 = ipa3_get_ipc_logbuf();
    ipc_log_string(
      v155,
      "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      5157,
      v371,
      v375,
      v372,
      v376);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v156 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      v156,
      "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      5157,
      v371,
      v375,
      v372,
      v376);
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
  {
    memset((void *)v4, 0, 0x360u);
    v157 = ((__int64 (__fastcall *)(__int64, __int64, bool))ipa_query_teth_stats)(122, v4, v358 != 0);
    if ( v157 )
    {
      LODWORD(v46) = v157;
      printk(&unk_3E49C0, "rmnet_ipa3_query_tethering_stats_hw");
      v312 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v313 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v313 )
        {
          ipc_log_string(
            v313,
            "ipa %s:%d IPA_CLIENT_Q6_DL_NLO_DATA_PROD query failed %d,\n",
            "rmnet_ipa3_query_tethering_stats_hw",
            5166,
            (_DWORD)v46);
          v312 = ipa3_ctx;
        }
        v314 = *(_QWORD *)(v312 + 34160);
        if ( v314 )
          ipc_log_string(
            v314,
            "ipa %s:%d IPA_CLIENT_Q6_DL_NLO_DATA_PROD query failed %d,\n",
            "rmnet_ipa3_query_tethering_stats_hw",
            5166,
            (unsigned int)v46);
      }
      goto LABEL_202;
    }
    if ( *(_BYTE *)(ipa3_ctx + 32266) )
      v158 = 13;
    else
      v158 = 11;
    v356 = ipa_get_ep_mapping(v158);
    if ( v356 == -1 )
      goto LABEL_425;
    LODWORD(v46) = v356;
    if ( v356 >= (unsigned int)ipa3_get_max_num_pipes() )
      goto LABEL_423;
    if ( ipa3_get_ipc_logbuf() )
    {
      v159 = ipa3_get_ipc_logbuf();
      if ( v356 > 0x23 )
        goto LABEL_426;
      ipc_log_string(
        v159,
        "ipa-wan %s:%d wlan: v4_rx_p-b(%d,%lld) v6_rx_p-b(%d,%lld),client(%d)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5186,
        *(_DWORD *)(v51 + 24LL * v356 + 16),
        *(_QWORD *)(v51 + 24LL * v356),
        *(_DWORD *)(v51 + 24LL * v356 + 20),
        *(_QWORD *)(v51 + 24LL * v356 + 8),
        v158);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v160 = ipa3_get_ipc_logbuf_low();
      if ( v356 > 0x23 )
        goto LABEL_426;
      ipc_log_string(
        v160,
        "ipa-wan %s:%d wlan: v4_rx_p-b(%d,%lld) v6_rx_p-b(%d,%lld),client(%d)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5186,
        *(_DWORD *)(v51 + 24LL * v356 + 16),
        *(_QWORD *)(v51 + 24LL * v356),
        *(_DWORD *)(v51 + 24LL * v356 + 20),
        *(_QWORD *)(v51 + 24LL * v356 + 8),
        v158);
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v161 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v161,
        "ipa-wan %s:%d usb: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5192,
        *((_DWORD *)v6 + 4),
        *v6,
        *((_DWORD *)v6 + 5),
        v6[1]);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v163 = ipa3_get_ipc_logbuf_low();
      v162 = ipc_log_string(
               v163,
               "ipa-wan %s:%d usb: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
               "rmnet_ipa3_query_tethering_stats_hw",
               5192,
               *((_DWORD *)v6 + 4),
               *v6,
               *((_DWORD *)v6 + 5),
               v6[1]);
    }
    if ( v360 )
    {
      v164 = 0;
      v4 = (__int64)"ipa-wan %s:%d wigig%d: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n";
      if ( v359 <= 1 )
        LODWORD(v6) = 1;
      else
        LODWORD(v6) = v359;
      while ( 1 )
      {
        v204 = rmnet_ipa3_get_wigig_cons(v164, v162);
        LODWORD(v46) = ipa_get_ep_mapping(v204);
        if ( (_DWORD)v46 == -1 )
          goto LABEL_432;
        if ( (unsigned int)v46 >= (unsigned int)ipa3_get_max_num_pipes() )
          goto LABEL_423;
        v7 = (_QWORD *)(v51 + 24LL * (unsigned int)v46);
        if ( ipa3_get_ipc_logbuf() )
        {
          v205 = ipa3_get_ipc_logbuf();
          if ( (unsigned int)v46 > 0x23 )
            goto LABEL_426;
          ipc_log_string(
            v205,
            "ipa-wan %s:%d wigig%d: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
            "rmnet_ipa3_query_tethering_stats_hw",
            5208,
            v164 + 1,
            *((_DWORD *)v7 + 4),
            *v7,
            *((_DWORD *)v7 + 5),
            v7[1]);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v206 = ipa3_get_ipc_logbuf_low();
          if ( (unsigned int)v46 > 0x23 )
            goto LABEL_426;
          v162 = ipc_log_string(
                   v206,
                   "ipa-wan %s:%d wigig%d: v4_rx_p(%d) b(%lld) v6_rx_p(%d) b(%lld)\n",
                   "rmnet_ipa3_query_tethering_stats_hw",
                   5208,
                   ++v164,
                   *((_DWORD *)v7 + 4),
                   *v7,
                   *((_DWORD *)v7 + 5),
                   v7[1]);
          if ( v164 == (_DWORD)v6 )
            break;
        }
        else if ( ++v164 == (_DWORD)v6 )
        {
          break;
        }
      }
    }
    if ( v356 > 0x23 )
      goto LABEL_426;
    v207 = v51 + 24LL * v356;
    v208 = *(_QWORD *)(v51 + 464);
    v209 = *(_DWORD *)(v207 + 16);
    v210 = *(_DWORD *)(v207 + 20);
    v212 = *(_QWORD *)v207;
    v211 = *(_QWORD *)(v207 + 8);
    v213 = (unsigned int)(*(_DWORD *)(v51 + 476) + v210);
    v214 = *(_QWORD *)(v51 + 456) + v372 + v212;
    v371 += (unsigned int)(*(_DWORD *)(v51 + 472) + v209);
    v372 = v214;
    v375 += v213;
    v376 += v208 + v211;
    if ( v360 )
    {
      if ( v359 <= 1 )
        v215 = 1;
      else
        v215 = v359;
      v216 = rmnet_ipa3_get_wigig_cons(0, v162);
      v217 = ipa_get_ep_mapping(v216);
      if ( v217 == -1 )
        goto LABEL_425;
      v218 = v217;
      LODWORD(v46) = v217;
      if ( v217 >= (unsigned int)ipa3_get_max_num_pipes() )
        goto LABEL_423;
      if ( (unsigned int)v46 > 0x23 )
        goto LABEL_426;
      v220 = v51 + 24LL * v218;
      v221 = *(unsigned int *)(v220 + 16);
      v222 = *(unsigned int *)(v220 + 20);
      v224 = *(_QWORD *)v220;
      v223 = *(_QWORD *)(v220 + 8);
      v371 += v221;
      v372 += v224;
      v375 += v222;
      v376 += v223;
      if ( v215 != 1 )
      {
        v315 = rmnet_ipa3_get_wigig_cons(1, v219);
        v316 = ipa_get_ep_mapping(v315);
        if ( v316 == -1 )
          goto LABEL_425;
        v317 = v316;
        LODWORD(v46) = v316;
        if ( v316 >= (unsigned int)ipa3_get_max_num_pipes() )
          goto LABEL_423;
        if ( (unsigned int)v46 > 0x23 )
          goto LABEL_426;
        v319 = v51 + 24LL * v317;
        v320 = *(unsigned int *)(v319 + 16);
        v321 = *(unsigned int *)(v319 + 20);
        v323 = *(_QWORD *)v319;
        v322 = *(_QWORD *)(v319 + 8);
        v371 += v320;
        v372 += v323;
        v375 += v321;
        v376 += v322;
        v324 = rmnet_ipa3_get_wigig_cons(2, v318);
        v325 = ipa_get_ep_mapping(v324);
        if ( v325 == -1 )
          goto LABEL_425;
        v326 = v325;
        LODWORD(v46) = v325;
        if ( v325 >= (unsigned int)ipa3_get_max_num_pipes() )
          goto LABEL_423;
        if ( (unsigned int)v46 > 0x23 )
          goto LABEL_426;
        v328 = v51 + 24LL * v326;
        v329 = *(unsigned int *)(v328 + 16);
        v330 = *(unsigned int *)(v328 + 20);
        v332 = *(_QWORD *)v328;
        v331 = *(_QWORD *)(v328 + 8);
        v371 += v329;
        v372 += v332;
        v375 += v330;
        v376 += v331;
        if ( (v357 & 1) == 0 )
        {
          v333 = rmnet_ipa3_get_wigig_cons(3, v327);
          v334 = ipa_get_ep_mapping(v333);
          if ( v334 == -1 )
            goto LABEL_425;
          v335 = v334;
          LODWORD(v46) = v334;
          if ( v334 >= (unsigned int)ipa3_get_max_num_pipes() )
            goto LABEL_423;
          if ( (unsigned int)v46 > 0x23 )
            goto LABEL_426;
          v336 = v51 + 24LL * v335;
          v337 = *(unsigned int *)(v336 + 16);
          v338 = *(unsigned int *)(v336 + 20);
          v340 = *(_QWORD *)v336;
          v339 = *(_QWORD *)(v336 + 8);
          v371 += v337;
          v372 += v340;
          v375 += v338;
          v376 += v339;
        }
      }
    }
    if ( ipa3_get_ipc_logbuf() )
    {
      v225 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v225,
        "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5247,
        v371,
        v375,
        v372,
        v376);
    }
    v4 = v51;
    v87 = v358;
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v226 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v226,
        "ipa-wan %s:%d v4_rx_p(%lu) v6_rx_p(%lu) v4_rx_b(%lu) v6_rx_b(%lu)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5247,
        v371,
        v375,
        v372,
        v376);
    }
  }
LABEL_133:
  memset((void *)v4, 0, 0x360u);
  v90 = ((__int64 (__fastcall *)(__int64, __int64, bool))ipa_query_teth_stats)(18, v4, v87 != 0);
  if ( v90 )
  {
    LODWORD(v46) = v90;
    printk(&unk_3FC576, "rmnet_ipa3_query_tethering_stats_hw");
    v201 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v202 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v202 )
      {
        ipc_log_string(
          v202,
          "ipa %s:%d IPA_CLIENT_USB_PROD query failed %d\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5254,
          (_DWORD)v46);
        v201 = ipa3_ctx;
      }
      v203 = *(_QWORD *)(v201 + 34160);
      if ( v203 )
        ipc_log_string(
          v203,
          "ipa %s:%d IPA_CLIENT_USB_PROD query failed %d\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5254,
          (unsigned int)v46);
    }
    goto LABEL_356;
  }
  if ( *(_BYTE *)(rmnet_ipa3_ctx + 1992) )
    v91 = 97;
  else
    v91 = 53;
  v92 = ipa_get_ep_mapping(v91);
  if ( v92 == -1 )
    goto LABEL_425;
  v93 = v92;
  LODWORD(v46) = v92;
  if ( v92 >= (unsigned int)ipa3_get_max_num_pipes() )
    goto LABEL_423;
  if ( ipa3_get_ipc_logbuf() )
  {
    v94 = ipa3_get_ipc_logbuf();
    if ( v93 > 0x23 )
      goto LABEL_426;
    ipc_log_string(
      v94,
      "ipa-wan %s:%d usb: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      5272,
      *(_DWORD *)(v51 + 24LL * v93 + 16),
      *(_QWORD *)(v51 + 24LL * v93),
      *(_DWORD *)(v51 + 24LL * v93 + 20),
      *(_QWORD *)(v51 + 24LL * v93 + 8));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v95 = ipa3_get_ipc_logbuf_low();
    if ( v93 > 0x23 )
      goto LABEL_426;
    v4 = v51;
    ipc_log_string(
      v95,
      "ipa-wan %s:%d usb: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      5272,
      *(_DWORD *)(v51 + 24LL * v93 + 16),
      *(_QWORD *)(v51 + 24LL * v93),
      *(_DWORD *)(v51 + 24LL * v93 + 20),
      *(_QWORD *)(v51 + 24LL * v93 + 8));
  }
  else
  {
    if ( v93 > 0x23 )
      goto LABEL_426;
    v4 = v51;
  }
  v191 = v4 + 24LL * v93;
  v192 = ipa3_ctx;
  v193 = *(unsigned int *)(v191 + 16);
  v373 = *(unsigned int *)(v191 + 20);
  v195 = *(_QWORD *)v191;
  v194 = *(_QWORD *)(v191 + 8);
  v369 = v193;
  v370 = v195;
  v374 = v194;
  v196 = v358;
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u && *(_DWORD *)(ipa3_ctx + 32256) == 1 )
  {
    v197 = ipa_get_ep_mapping(75);
    if ( v197 == -1 )
      goto LABEL_425;
    v198 = v197;
    LODWORD(v46) = v197;
    if ( v197 >= (unsigned int)ipa3_get_max_num_pipes() )
      goto LABEL_423;
    if ( ipa3_get_ipc_logbuf() )
    {
      v199 = ipa3_get_ipc_logbuf();
      if ( v198 > 0x23 )
        goto LABEL_426;
      ipc_log_string(
        v199,
        "ipa-wan %s:%d usb: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5298,
        *(_DWORD *)(v51 + 24LL * v198 + 16),
        *(_QWORD *)(v51 + 24LL * v198),
        *(_DWORD *)(v51 + 24LL * v198 + 20),
        *(_QWORD *)(v51 + 24LL * v198 + 8));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v200 = ipa3_get_ipc_logbuf_low();
      if ( v198 > 0x23 )
        goto LABEL_426;
      v4 = v51;
      ipc_log_string(
        v200,
        "ipa-wan %s:%d usb: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5298,
        *(_DWORD *)(v51 + 24LL * v198 + 16),
        *(_QWORD *)(v51 + 24LL * v198),
        *(_DWORD *)(v51 + 24LL * v198 + 20),
        *(_QWORD *)(v51 + 24LL * v198 + 8));
    }
    else
    {
      if ( v198 > 0x23 )
        goto LABEL_426;
      v4 = v51;
    }
    v227 = v4 + 24LL * v198;
    v192 = ipa3_ctx;
    v228 = *(unsigned int *)(v227 + 16);
    v229 = v373 + *(unsigned int *)(v227 + 20);
    v231 = *(_QWORD *)v227;
    v230 = *(_QWORD *)(v227 + 8);
    v373 = v229;
    v196 = v358;
    v369 += v228;
    v370 += v231;
    v374 += v230;
  }
  v232 = v196 != 0;
  memset((void *)v4, 0, 0x360u);
  if ( *(_BYTE *)(v192 + 32266) )
    v233 = 12;
  else
    v233 = 10;
  v234 = ((__int64 (__fastcall *)(__int64, __int64, _BOOL4))ipa_query_teth_stats)(v233, v4, v232);
  if ( v234 )
  {
    LODWORD(v46) = v234;
    printk(&unk_3A4B7C, "rmnet_ipa3_query_tethering_stats_hw");
    v250 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v251 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v251 )
      {
        ipc_log_string(
          v251,
          "ipa %s:%d IPA_CLIENT_WLAN_PROD query failed %d\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5321,
          (_DWORD)v46);
        v250 = ipa3_ctx;
      }
      v252 = *(_QWORD *)(v250 + 34160);
      if ( v252 )
        ipc_log_string(
          v252,
          "ipa %s:%d IPA_CLIENT_WLAN_PROD query failed %d\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5321,
          (unsigned int)v46);
    }
LABEL_356:
    kfree(v4);
    goto LABEL_432;
  }
  if ( *(_BYTE *)(rmnet_ipa3_ctx + 1992) )
    v235 = 97;
  else
    v235 = 53;
  v236 = ipa_get_ep_mapping(v235);
  if ( v236 == -1 )
    goto LABEL_425;
  v237 = v236;
  LODWORD(v46) = v236;
  if ( v236 >= (unsigned int)ipa3_get_max_num_pipes() )
    goto LABEL_423;
  if ( ipa3_get_ipc_logbuf() )
  {
    v238 = ipa3_get_ipc_logbuf();
    if ( v237 > 0x23 )
      goto LABEL_426;
    ipc_log_string(
      v238,
      "ipa-wan %s:%d wlan1: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      5340,
      *(_DWORD *)(v51 + 24LL * v237 + 16),
      *(_QWORD *)(v51 + 24LL * v237),
      *(_DWORD *)(v51 + 24LL * v237 + 20),
      *(_QWORD *)(v51 + 24LL * v237 + 8));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v239 = ipa3_get_ipc_logbuf_low();
    if ( v237 > 0x23 )
      goto LABEL_426;
    v4 = v51;
    ipc_log_string(
      v239,
      "ipa-wan %s:%d wlan1: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      5340,
      *(_DWORD *)(v51 + 24LL * v237 + 16),
      *(_QWORD *)(v51 + 24LL * v237),
      *(_DWORD *)(v51 + 24LL * v237 + 20),
      *(_QWORD *)(v51 + 24LL * v237 + 8));
  }
  else
  {
    if ( v237 > 0x23 )
      goto LABEL_426;
    v4 = v51;
  }
  v240 = v358;
  v241 = v4 + 24LL * v237;
  v242 = *(unsigned int *)(v241 + 16);
  v243 = v373 + *(unsigned int *)(v241 + 20);
  v245 = *(_QWORD *)v241;
  v244 = *(_QWORD *)(v241 + 8);
  v373 = v243;
  v369 += v242;
  v370 += v245;
  v374 += v244;
  if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x11u && *(_DWORD *)(ipa3_ctx + 32256) == 1 )
  {
    v246 = ipa_get_ep_mapping(75);
    if ( v246 == -1 )
      goto LABEL_425;
    v247 = v246;
    LODWORD(v46) = v246;
    if ( v246 >= (unsigned int)ipa3_get_max_num_pipes() )
      goto LABEL_423;
    if ( ipa3_get_ipc_logbuf() )
    {
      v248 = ipa3_get_ipc_logbuf();
      if ( v247 > 0x23 )
        goto LABEL_426;
      ipc_log_string(
        v248,
        "ipa-wan %s:%d wlan1: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5363,
        *(_DWORD *)(v51 + 24LL * v247 + 16),
        *(_QWORD *)(v51 + 24LL * v247),
        *(_DWORD *)(v51 + 24LL * v247 + 20),
        *(_QWORD *)(v51 + 24LL * v247 + 8));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v249 = ipa3_get_ipc_logbuf_low();
      if ( v247 > 0x23 )
        goto LABEL_426;
      v4 = v51;
      ipc_log_string(
        v249,
        "ipa-wan %s:%d wlan1: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5363,
        *(_DWORD *)(v51 + 24LL * v247 + 16),
        *(_QWORD *)(v51 + 24LL * v247),
        *(_DWORD *)(v51 + 24LL * v247 + 20),
        *(_QWORD *)(v51 + 24LL * v247 + 8));
    }
    else
    {
      if ( v247 > 0x23 )
        goto LABEL_426;
      v4 = v51;
    }
    v240 = v358;
    v282 = v4 + 24LL * v247;
    v283 = *(unsigned int *)(v282 + 16);
    v284 = v373 + *(unsigned int *)(v282 + 20);
    v286 = *(_QWORD *)v282;
    v285 = *(_QWORD *)(v282 + 8);
    v373 = v284;
    v369 += v283;
    v370 += v286;
    v374 += v285;
  }
  if ( (unsigned int)ipa_get_ep_mapping(86) == -1 )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v293 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v293,
        "ipa-wan %s:%d IPA_CLIENT_WIGIG_PROD client not supported\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5434);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v294 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        v294,
        "ipa-wan %s:%d IPA_CLIENT_WIGIG_PROD client not supported\n",
        "rmnet_ipa3_query_tethering_stats_hw",
        5434);
    }
    goto LABEL_396;
  }
  memset((void *)v4, 0, 0x360u);
  v287 = ((__int64 (__fastcall *)(__int64, __int64, bool))ipa_query_teth_stats)(86, v4, v240 != 0);
  if ( v287 )
  {
    LODWORD(v46) = v287;
    printk(&unk_3EA7A7, "rmnet_ipa3_query_tethering_stats_hw");
    v309 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v310 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v310 )
      {
        ipc_log_string(
          v310,
          "ipa %s:%d IPA_CLIENT_WIGIG_PROD query failed %d\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5383,
          (_DWORD)v46);
        v309 = ipa3_ctx;
      }
      v311 = *(_QWORD *)(v309 + 34160);
      if ( v311 )
        ipc_log_string(
          v311,
          "ipa %s:%d IPA_CLIENT_WIGIG_PROD query failed %d\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5383,
          (unsigned int)v46);
    }
    goto LABEL_202;
  }
  if ( *(_BYTE *)(rmnet_ipa3_ctx + 1992) )
    v288 = 97;
  else
    v288 = 53;
  v289 = ipa_get_ep_mapping(v288);
  if ( v289 == -1 )
    goto LABEL_425;
  v290 = v289;
  LODWORD(v46) = v289;
  if ( v289 >= (unsigned int)ipa3_get_max_num_pipes() )
    goto LABEL_423;
  if ( ipa3_get_ipc_logbuf() )
  {
    v291 = ipa3_get_ipc_logbuf();
    if ( v290 > 0x23 )
      goto LABEL_426;
    ipc_log_string(
      v291,
      "ipa-wan %s:%d wigig: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      5402,
      *(_DWORD *)(v51 + 24LL * v290 + 16),
      *(_QWORD *)(v51 + 24LL * v290),
      *(_DWORD *)(v51 + 24LL * v290 + 20),
      *(_QWORD *)(v51 + 24LL * v290 + 8));
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v292 = ipa3_get_ipc_logbuf_low();
    if ( v290 > 0x23 )
      goto LABEL_426;
    v4 = v51;
    ipc_log_string(
      v292,
      "ipa-wan %s:%d wigig: v4_tx_p(%d) b(%lld) v6_tx_p(%d) b(%lld)\n",
      "rmnet_ipa3_query_tethering_stats_hw",
      5402,
      *(_DWORD *)(v51 + 24LL * v290 + 16),
      *(_QWORD *)(v51 + 24LL * v290),
      *(_DWORD *)(v51 + 24LL * v290 + 20),
      *(_QWORD *)(v51 + 24LL * v290 + 8));
  }
  else
  {
    if ( v290 > 0x23 )
      goto LABEL_426;
    v4 = v51;
  }
  v295 = v4 + 24LL * v290;
  v296 = *(unsigned int *)(v295 + 16);
  v297 = v373 + *(unsigned int *)(v295 + 20);
  v299 = *(_QWORD *)v295;
  v298 = *(_QWORD *)(v295 + 8);
  v373 = v297;
  v369 += v296;
  v370 += v299;
  v374 += v298;
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x11u || *(_DWORD *)(ipa3_ctx + 32256) != 1 )
    goto LABEL_396;
  v300 = ipa_get_ep_mapping(75);
  if ( v300 == -1 )
    goto LABEL_425;
  v301 = v300;
  LODWORD(v46) = v300;
  if ( v300 < (unsigned int)ipa3_get_max_num_pipes() )
  {
    if ( (unsigned int)v46 <= 0x23 )
    {
      v4 = v51;
      v302 = v51 + 24LL * v301;
      v303 = *(unsigned int *)(v302 + 16);
      v304 = v373 + *(unsigned int *)(v302 + 20);
      v306 = *(_QWORD *)v302;
      v305 = *(_QWORD *)(v302 + 8);
      v373 = v304;
      v369 += v303;
      v370 += v306;
      v374 += v305;
LABEL_396:
      if ( ipa3_get_ipc_logbuf() )
      {
        v307 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v307,
          "ipa-wan %s:%d v4_tx_p(%lu) v6_tx_p(%lu) v4_tx_b(%lu) v6_tx_b(%lu)\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5441,
          v369,
          v373,
          v370,
          v374);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v308 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v308,
          "ipa-wan %s:%d v4_tx_p(%lu) v6_tx_p(%lu) v4_tx_b(%lu) v6_tx_b(%lu)\n",
          "rmnet_ipa3_query_tethering_stats_hw",
          5441,
          v369,
          v373,
          v370,
          v374);
      }
      kfree(v4);
      goto LABEL_56;
    }
    goto LABEL_426;
  }
LABEL_423:
  if ( (_DWORD)v46 )
    goto LABEL_432;
LABEL_56:
  result = 0;
LABEL_67:
  v45 = v376 + v372;
  *(_QWORD *)(a1 + 24) = v374 + v370;
  *(_QWORD *)(a1 + 32) = v45;
LABEL_454:
  _ReadStatusReg(SP_EL0);
  return result;
}
