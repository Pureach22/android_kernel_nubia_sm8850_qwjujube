__int64 __fastcall ipa3_pre_init(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x9
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x10
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  int v13; // w9
  __int64 v14; // x17
  __int64 v15; // x20
  int v16; // w10
  int v17; // w10
  int v18; // w10
  int v19; // w9
  int v20; // w9
  int v21; // w10
  int v22; // w10
  void *v23; // x0
  __int64 v24; // x9
  __int64 v25; // x8
  char v26; // w11
  _QWORD *v27; // x9
  __int64 v28; // x8
  int v29; // w10
  __int64 v30; // x9
  int v31; // w11
  int v32; // w11
  int v33; // w11
  int v34; // w13
  int v35; // w11
  __int64 v36; // x8
  char hw_type_index; // w0
  __int64 v38; // x9
  __int64 v39; // x10
  _QWORD *v40; // x8
  int v41; // w11
  char v42; // w12
  size_t v43; // x20
  __int64 v44; // x0
  size_t v45; // x2
  __int64 v46; // x0
  __int64 v47; // x8
  int *v48; // x9
  _DWORD *v49; // x9
  __int64 v50; // x8
  __int64 v51; // x0
  __int64 v52; // x0
  unsigned int v53; // w20
  int v54; // w10
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x0
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  int v64; // w9
  _BYTE *v65; // x8
  __int64 v66; // x0
  unsigned int v67; // w9
  __int64 v68; // x12
  unsigned int v69; // w1
  _DWORD *v70; // x10
  unsigned int v71; // w2
  unsigned int v72; // w8
  __int64 v73; // x2
  char *v74; // x3
  char *v75; // x3
  __int64 v76; // x0
  __int64 v77; // x8
  __int64 v78; // x8
  int v79; // w9
  __int64 v80; // x0
  _QWORD *v81; // x9
  __int64 v82; // x0
  __int64 v83; // x0
  __int64 v84; // x0
  __int64 v85; // x0
  __int64 v86; // x1
  __int64 v87; // x8
  __int64 i; // x9
  __int64 v89; // x20
  _BYTE *v90; // x25
  void *v91; // x0
  void *v92; // x0
  __int64 v93; // x9
  unsigned int v94; // w11
  __int64 v95; // x8
  __int64 v96; // x0
  __int64 v97; // x0
  int v98; // w8
  __int64 v99; // x2
  __int64 v100; // x0
  __int64 v101; // x8
  const void *v102; // x7
  __int64 v103; // x0
  __int64 v104; // x0
  __int64 v105; // x8
  unsigned __int64 v106; // x0
  _DWORD *v107; // x8
  __int64 v108; // x0
  __int64 v109; // x8
  _QWORD *v110; // x20
  __int64 v111; // x0
  __int64 v112; // x0
  __int64 v113; // x20
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  __int64 v119; // x0
  __int64 v120; // x0
  __int64 v121; // x0
  __int64 v122; // x0
  __int64 v123; // x0
  _QWORD *v124; // x8
  __int64 v125; // x8
  __int64 v126; // x8
  __int64 v127; // x8
  __int64 v128; // x8
  __int64 v129; // x8
  __int64 v130; // x8
  __int64 v131; // x8
  __int64 v132; // x8
  __int64 v133; // x8
  __int64 v134; // x8
  __int64 v135; // x8
  __int64 v136; // x8
  __int64 v137; // x8
  __int64 v138; // x8
  __int64 v139; // x8
  __int64 v140; // x8
  __int64 v141; // x8
  __int64 v142; // x8
  __int64 v143; // x8
  __int64 v144; // x8
  __int64 v145; // x8
  __int64 v146; // x8
  __int64 v147; // x8
  __int64 v148; // x8
  _QWORD *v149; // x8
  __int64 v150; // x8
  _QWORD *v151; // x8
  __int64 v152; // x8
  _QWORD *v153; // x9
  __int64 v154; // x8
  __int64 v155; // x8
  _QWORD *v156; // x8
  __int64 v157; // x10
  __int64 v158; // x0
  __int64 v159; // x8
  unsigned __int64 v160; // x0
  __int64 v161; // x0
  __int64 v162; // x8
  int v163; // w0
  __int64 v164; // x8
  __int64 v165; // x0
  __int64 v166; // x0
  __int64 v167; // x8
  __int64 inited; // x0
  __int64 v169; // x20
  __int64 v170; // x9
  __int64 v171; // x0
  __int64 v172; // x8
  __int64 v173; // x0
  unsigned int v174; // w8
  __int64 v175; // x8
  __int64 v176; // x0
  __int64 v177; // x0
  __int64 v178; // x8
  __int64 v179; // x0
  __int64 v180; // x0
  __int64 v181; // x8
  __int64 v182; // x0
  __int64 v183; // x0
  __int64 v184; // x8
  __int64 v185; // x0
  __int64 v186; // x0
  __int64 v187; // x8
  __int64 v188; // x0
  __int64 v189; // x0
  __int64 v190; // x8
  __int64 v191; // x0
  __int64 v192; // x0
  __int64 v193; // x8
  __int64 v194; // x0
  __int64 v195; // x0
  __int64 v196; // x8
  __int64 v197; // x0
  __int64 v198; // x0
  __int64 v199; // x0
  int v200; // w0
  __int64 v201; // x8
  int v202; // w0
  int v203; // w0
  __int64 v204; // x8
  __int64 v205; // x0
  __int64 v206; // x8
  __int64 v207; // x0
  __int64 v208; // x0
  __int64 v209; // x8
  __int64 v210; // x0
  __int64 v211; // x0
  __int64 v212; // x0
  __int64 v213; // x0
  __int64 v214; // x0
  __int64 v215; // x0
  __int64 v216; // x8
  __int64 v217; // x8
  __int64 v218; // x0
  __int64 v219; // x8
  __int64 v220; // x0
  __int64 v221; // x0
  __int64 v222; // x8
  __int64 v223; // x9
  unsigned __int64 v224; // x0
  __int64 v225; // x8
  unsigned __int64 v226; // t1
  __int64 v227; // x8
  __int64 v228; // x8
  unsigned __int64 v229; // x0
  __int64 v230; // x8
  unsigned __int64 v231; // x0
  __int64 v232; // x8
  unsigned __int64 v233; // x0
  __int64 v235; // x8
  __int64 v236; // x0
  __int64 v237; // x0
  __int64 v238; // x8
  __int64 v239; // x0
  __int64 v240; // x0
  __int64 v241; // x8
  __int64 v242; // x0
  __int64 v243; // x0
  __int64 v244; // x8
  __int64 v245; // x0
  __int64 v246; // x0
  __int64 v247; // x8
  __int64 v248; // x0
  __int64 v249; // x0
  __int64 v250; // x8
  __int64 v251; // x0
  __int64 v252; // x0
  __int64 v253; // x8
  __int64 v254; // x0
  __int64 v255; // x0
  __int64 v256; // x8
  __int64 v257; // x0
  __int64 v258; // x0
  __int64 v259; // x8
  __int64 v260; // x0
  __int64 v261; // x0
  __int64 v262; // x8
  __int64 v263; // x0
  __int64 v264; // x0
  __int64 v265; // x8
  __int64 v266; // x0
  __int64 v267; // x0
  __int64 v268; // x8
  __int64 v269; // x0
  __int64 v270; // x0
  __int64 v271; // x8
  __int64 v272; // x0
  __int64 v273; // x0
  __int64 v274; // x0
  __int64 v275; // x0
  __int64 v276; // x8
  __int64 v277; // x0
  __int64 v278; // x0
  int v279; // w19
  __int64 v280; // x8
  __int64 v281; // x0
  __int64 v282; // x0
  __int64 v283; // x8
  __int64 v284; // x0
  __int64 v285; // x8
  __int64 v286; // x0
  int v287; // w19
  __int64 v288; // x8
  __int64 v289; // x0
  __int64 v290; // x8
  __int64 v291; // x0
  int v292; // w19
  __int64 v293; // x8
  __int64 v294; // x0
  int v295; // w19
  __int64 v296; // x8
  __int64 v297; // x0
  unsigned int v298; // w19
  __int64 v299; // x8
  __int64 v300; // x0
  unsigned int v301; // w19
  __int64 v302; // x8
  __int64 v303; // x0
  __int64 v304; // x8
  __int64 v305; // x0
  __int64 v306; // x0
  __int64 v307; // x8
  __int64 v308; // x0
  __int64 v309; // x8
  __int64 v310; // x0
  unsigned __int64 StatusReg; // x23
  __int64 v312; // x24
  __int64 v313; // [xsp+8h] [xbp-28h] BYREF
  __int64 v314; // [xsp+10h] [xbp-20h]
  __int64 v315; // [xsp+18h] [xbp-18h]
  __int64 v316; // [xsp+20h] [xbp-10h]
  __int64 v317; // [xsp+28h] [xbp-8h]

  v317 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_67;
  v3 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v3 )
  {
    ipc_log_string(v3, "ipa %s:%d IPA Driver initialization started\n", "ipa3_pre_init", 9209);
    v1 = ipa3_ctx;
  }
  v4 = *(_QWORD *)(v1 + 34160);
  if ( v4 )
  {
    ipc_log_string(v4, "ipa %s:%d IPA Driver initialization started\n", "ipa3_pre_init", 9209);
    v1 = ipa3_ctx;
  }
  if ( !v1 )
    goto LABEL_67;
  if ( *(_DWORD *)(v1 + 45144) != 2 )
    *(_DWORD *)(v1 + 45144) = 0;
  _mutex_init(v1 + 45152, "&ipa3_ctx->fw_load_data.lock", &ipa3_pre_init___key);
  v5 = ipc_log_context_create(50, &unk_1B1CA0, 0x10000);
  v6 = ipa3_ctx;
  *(_QWORD *)(ipa3_ctx + 34152) = v5;
  if ( !v5 )
  {
    if ( v6 )
    {
      v7 = *(_QWORD *)(v6 + 34160);
      if ( v7 )
        ipc_log_string(v7, "ipa %s:%d failed to create IPC log, continue...\n", "ipa3_pre_init", 9223);
    }
  }
  v8 = ipc_log_context_create(50, "ipa_clk", 0x10000);
  v9 = ipa3_ctx;
  *(_QWORD *)(ipa3_ctx + 34168) = v8;
  if ( !v8 && v9 )
  {
    v10 = *(_QWORD *)(v9 + 34152);
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d failed to create IPC ipa_clk log, continue...\n", "ipa3_pre_init", 9227);
      v9 = ipa3_ctx;
    }
    v11 = *(_QWORD *)(v9 + 34160);
    if ( v11 )
    {
      ipc_log_string(v11, "ipa %s:%d failed to create IPC ipa_clk log, continue...\n", "ipa3_pre_init", 9227);
      v9 = ipa3_ctx;
    }
  }
  *(_QWORD *)(v9 + 34208) = a1;
  *(_WORD *)(v9 + 43310) = 257;
  v12 = 0;
  v13 = 0;
  *(_BYTE *)(ipa3_ctx + 43312) = 1;
  *(_BYTE *)(ipa3_ctx + 43313) = 1;
  *(_BYTE *)(ipa3_ctx + 43314) = 1;
  *(_BYTE *)(ipa3_ctx + 43315) = 1;
  *(_BYTE *)(ipa3_ctx + 43316) = 1;
  do
  {
    *(_DWORD *)(ipa3_ctx + v12 + 45232) = v13++;
    *(_BYTE *)(ipa3_ctx + v12 + 45237) = -1;
    *(_BYTE *)(ipa3_ctx + v12 + 45239) = -1;
    *(_BYTE *)(ipa3_ctx + v12 + 45241) = -1;
    *(_BYTE *)(ipa3_ctx + v12 + 45243) = -1;
    v14 = ipa3_ctx + v12;
    v12 += 14;
    *(_BYTE *)(v14 + 45245) = -1;
  }
  while ( v12 != 154 );
  v15 = ipa3_ctx;
  *(_DWORD *)(ipa3_ctx + 28640) = dword_1F7DAC;
  v16 = dword_1F7DB0;
  *(_QWORD *)(v15 + 32968) = 0;
  *(_QWORD *)(v15 + 32976) = 0;
  *(_QWORD *)(v15 + 32952) = 0;
  *(_QWORD *)(v15 + 32960) = 0;
  *(_DWORD *)(v15 + 28644) = v16;
  v17 = dword_1F7DBC;
  *(_QWORD *)(v15 + 32936) = 0;
  *(_QWORD *)(v15 + 32944) = 0;
  *(_QWORD *)(v15 + 32920) = 0;
  *(_QWORD *)(v15 + 32928) = 0;
  *(_DWORD *)(v15 + 28648) = v17;
  v18 = qword_1F7DDC;
  *(_QWORD *)(v15 + 32912) = 0;
  *(_DWORD *)(v15 + 32240) = v18;
  *(_BYTE *)(v15 + 32260) = byte_1F7E10;
  v19 = HIDWORD(qword_1F7DDC);
  *(_QWORD *)(v15 + 33040) = 0;
  *(_QWORD *)(v15 + 33048) = 0;
  *(_DWORD *)(v15 + 32248) = v19;
  v20 = dword_1F7DE4;
  *(_QWORD *)(v15 + 33024) = 0;
  *(_QWORD *)(v15 + 33032) = 0;
  *(_QWORD *)(v15 + 33008) = 0;
  *(_QWORD *)(v15 + 33016) = 0;
  *(_DWORD *)(v15 + 32256) = v20;
  LOBYTE(v20) = ipa3_res[0];
  *(_QWORD *)(v15 + 32992) = 0;
  *(_QWORD *)(v15 + 33000) = 0;
  *(_QWORD *)(v15 + 32984) = 0;
  *(_BYTE *)(v15 + 32261) = v20;
  *(_BYTE *)(v15 + 32262) = word_1F7DEC;
  LOBYTE(v18) = HIBYTE(word_1F7DEC);
  *(_QWORD *)(v15 + 34080) = 0;
  *(_QWORD *)(v15 + 34088) = 0;
  *(_BYTE *)(v15 + 32263) = v18;
  LOBYTE(v18) = word_1F7DEF;
  *(_QWORD *)(v15 + 34064) = 0;
  *(_QWORD *)(v15 + 34072) = 0;
  *(_QWORD *)(v15 + 34048) = 0;
  *(_QWORD *)(v15 + 34056) = 0;
  *(_BYTE *)(v15 + 32265) = v18;
  LOBYTE(v18) = HIBYTE(word_1F7DEF);
  *(_QWORD *)(v15 + 34032) = 0;
  *(_QWORD *)(v15 + 34040) = 0;
  *(_QWORD *)(v15 + 34016) = 0;
  *(_QWORD *)(v15 + 34024) = 0;
  *(_BYTE *)(v15 + 32266) = v18;
  LOBYTE(v18) = byte_1F7DF1;
  *(_QWORD *)(v15 + 34000) = 0;
  *(_QWORD *)(v15 + 34008) = 0;
  *(_QWORD *)(v15 + 33984) = 0;
  *(_QWORD *)(v15 + 33992) = 0;
  *(_BYTE *)(v15 + 32270) = v18;
  LOBYTE(v18) = byte_1F7DF2;
  *(_QWORD *)(v15 + 33968) = 0;
  *(_QWORD *)(v15 + 33976) = 0;
  *(_QWORD *)(v15 + 33952) = 0;
  *(_QWORD *)(v15 + 33960) = 0;
  *(_BYTE *)(v15 + 32271) = v18;
  LOBYTE(v18) = word_1F7DF3;
  *(_QWORD *)(v15 + 33936) = 0;
  *(_QWORD *)(v15 + 33944) = 0;
  *(_QWORD *)(v15 + 33920) = 0;
  *(_QWORD *)(v15 + 33928) = 0;
  *(_BYTE *)(v15 + 32272) = v18;
  v21 = qword_1F7DF8;
  *(_QWORD *)(v15 + 33904) = 0;
  *(_QWORD *)(v15 + 33912) = 0;
  *(_QWORD *)(v15 + 33888) = 0;
  *(_QWORD *)(v15 + 33896) = 0;
  *(_DWORD *)(v15 + 43256) = v21;
  v22 = HIDWORD(qword_1F7DF8);
  *(_QWORD *)(v15 + 33872) = 0;
  *(_QWORD *)(v15 + 33880) = 0;
  *(_QWORD *)(v15 + 33856) = 0;
  *(_QWORD *)(v15 + 33864) = 0;
  *(_DWORD *)(v15 + 43260) = v22;
  LOBYTE(v22) = byte_1F7EF2;
  *(_QWORD *)(v15 + 33848) = 0;
  *(_BYTE *)(v15 + 45386) = v22;
  *(_BYTE *)(v15 + 34904) = byte_1F7FC4;
  *(_DWORD *)(v15 + 34916) = dword_1F7FC8;
  *(_DWORD *)(v15 + 34920) = dword_1F7FCC;
  *(_DWORD *)(v15 + 34924) = dword_1F7FD0;
  *(_DWORD *)(v15 + 34928) = dword_1F7FD4;
  *(_DWORD *)(v15 + 50128) = dword_1F7FF8;
  v23 = memset((void *)(v15 + 33096), 0, 0x2D0u);
  *(_QWORD *)(v15 + 33056) = 0;
  *(_QWORD *)(v15 + 33064) = 0;
  *(_QWORD *)(v15 + 33072) = 0;
  *(_QWORD *)(v15 + 33080) = 0;
  *(_DWORD *)(v15 + 33088) = 0;
  v24 = ipa3_ctx;
  *(_QWORD *)(v15 + 34096) = 0;
  *(_QWORD *)(v15 + 34104) = 0;
  *(_QWORD *)(v24 + 34112) = 0;
  v25 = ipa3_ctx;
  *(_BYTE *)(ipa3_ctx + 43264) = byte_1F7E00;
  *(_BYTE *)(v25 + 43636) = byte_1F7E03;
  *(_DWORD *)(v25 + 43304) = dword_1F7DE8;
  *(_WORD *)(v25 + 43308) = word_1F7E01;
  v26 = byte_1F7EE0;
  *(_BYTE *)(v25 + 31536) = 0;
  *(_BYTE *)(v25 + 51241) = 0;
  *(_BYTE *)(v25 + 44853) = v26;
  *(_QWORD *)(v25 + 43744) = qword_1F7E08;
  v27 = (_QWORD *)(v25 + 34120);
  v28 = ipa3_ctx;
  v29 = dword_1F7EE4;
  *v27 = 0;
  v27[1] = 0;
  v30 = v28 + 44856;
  *(_DWORD *)(v28 + 44856) = v29;
  *(_BYTE *)(v28 + 44860) = byte_1F7EE8;
  *(_BYTE *)(v28 + 44861) = byte_1F7EE9;
  *(_BYTE *)(v28 + 44862) = byte_1F7EEA;
  *(_DWORD *)(v28 + 44864) = dword_1F7EEC;
  *(_BYTE *)(v28 + 44863) = byte_1F7EEB;
  *(_BYTE *)(v28 + 45390) = byte_1F7E04;
  *(_BYTE *)(v28 + 45391) = byte_1F7E05;
  *(_BYTE *)(v28 + 45392) = byte_1F7E06;
  *(_BYTE *)(v28 + 48857) = byte_1F7FC0;
  *(_BYTE *)(v28 + 48858) = word_1F7FC1;
  *(_BYTE *)(v28 + 32269) = byte_1F7FC3;
  *(_BYTE *)(v28 + 48859) = HIBYTE(word_1F7FC1);
  v31 = dword_1F7FE8;
  if ( (unsigned int)dword_1F7FE8 >= 0x7D0 )
    v31 = 2000;
  *(_DWORD *)(v28 + 48776) = v31;
  v32 = dword_1F7FEC;
  if ( !dword_1F7FEC )
    v32 = 5;
  *(_DWORD *)(v28 + 48780) = v32;
  v33 = dword_1F7FF0;
  if ( !dword_1F7FF0 )
    v33 = 3;
  *(_DWORD *)(v28 + 48784) = v33;
  if ( (unsigned int)dword_1F7FF4 >= 2 )
    v34 = 2;
  else
    v34 = dword_1F7FF4;
  if ( dword_1F7FF4 )
    v35 = v34;
  else
    v35 = 2;
  *(_DWORD *)(v28 + 48788) = v35;
  *(_BYTE *)(v28 + 32264) = byte_1F7DEE;
  v36 = v28 + 50132;
  *(_BYTE *)v36 = byte_1F7FFC;
  *(_DWORD *)(v36 + 8) = dword_1F8000;
  *(_BYTE *)(v30 + 4004) = byte_1F8017;
  hw_type_index = ipa3_get_hw_type_index(v23);
  v38 = ipa3_ctx + 32244;
  v39 = ipa3_ctx + 50144;
  v40 = (_QWORD *)(ipa3_ctx + 43268);
  *(_BYTE *)(ipa3_ctx + 32244) = hw_type_index;
  *(_DWORD *)v39 = qword_1F8004;
  v41 = HIDWORD(qword_1F8004);
  *(_BYTE *)(v39 + 8) = 0;
  *(_DWORD *)(v39 + 4) = v41;
  *(_BYTE *)(v39 + 953) = byte_1F800D;
  *(_WORD *)(v39 + 954) = word_1F800E;
  *(_WORD *)(v39 + 956) = word_1F8010;
  *(_BYTE *)(v39 + 958) = byte_1F8012;
  v42 = byte_1F8013;
  *v40 = 0x1000000010LL;
  v40[1] = 0x600000006LL;
  *(_BYTE *)(v39 + 1184) = 0;
  v40[2] = 0x400000018LL;
  *(_BYTE *)(v39 + 961) = v42;
  *(_QWORD *)(v39 + 1240) = 0;
  *(_BYTE *)(v38 + 23) = byte_1F8015;
  if ( !qword_1F7FD8 )
    goto LABEL_38;
  v43 = strlen((const char *)qword_1F7FD8) + 1;
  v44 = _kmalloc_noprof(v43, 3520);
  while ( 1 )
  {
    *(_QWORD *)(ipa3_ctx + 48864) = v44;
    if ( !v44 )
    {
      if ( (unsigned int)__ratelimit(&ipa3_pre_init__rs, "ipa3_pre_init") )
      {
        printk(&unk_3DAE07, "ipa3_pre_init");
        v50 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_67;
      }
      else
      {
        v50 = ipa3_ctx;
        if ( !ipa3_ctx )
          goto LABEL_67;
      }
      v51 = *(_QWORD *)(v50 + 34152);
      if ( v51 )
      {
        ipc_log_string(v51, "ipa %s:%d Failed to alloc GSI FW file name\n", "ipa3_pre_init", 9360);
        v50 = ipa3_ctx;
      }
      v52 = *(_QWORD *)(v50 + 34160);
      if ( v52 )
      {
        ipc_log_string(v52, "ipa %s:%d Failed to alloc GSI FW file name\n", "ipa3_pre_init", 9360);
        v53 = -12;
        goto LABEL_314;
      }
LABEL_67:
      v53 = -12;
      goto LABEL_314;
    }
    v45 = strlen((const char *)qword_1F7FD8);
    if ( v43 < v45 )
      goto LABEL_468;
    memcpy(*(void **)(ipa3_ctx + 48864), (const void *)qword_1F7FD8, v45);
LABEL_38:
    if ( !qword_1F7FE0 )
      goto LABEL_42;
    v43 = strlen((const char *)qword_1F7FE0) + 1;
    v46 = _kmalloc_noprof(v43, 3520);
    *(_QWORD *)(ipa3_ctx + 48872) = v46;
    if ( !v46 )
      break;
    v45 = strlen((const char *)qword_1F7FE0);
    if ( v43 >= v45 )
    {
      memcpy(*(void **)(ipa3_ctx + 48872), (const void *)qword_1F7FE0, v45);
LABEL_42:
      v47 = ipa3_ctx;
      v48 = (int *)(ipa3_ctx + 44864);
      if ( (*(_DWORD *)(ipa3_ctx + 32248) | 4) == 4 )
      {
        v54 = *v48;
        if ( !*v48 )
        {
          LODWORD(v313) = 0;
          if ( (unsigned int)qcom_scm_get_sec_dump_state(&v313) )
          {
            printk(&unk_3BD8D1, "ipa_is_mem_dump_allowed");
            v47 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v60 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v60 )
              {
                ipc_log_string(v60, "ipa %s:%d SCM DUMP_STATE call failed\n", "ipa_is_mem_dump_allowed", 9060);
                v47 = ipa3_ctx;
              }
              v61 = *(_QWORD *)(v47 + 34160);
              if ( v61 )
              {
                ipc_log_string(v61, "ipa %s:%d SCM DUMP_STATE call failed\n", "ipa_is_mem_dump_allowed", 9060);
                v47 = ipa3_ctx;
              }
            }
          }
          else
          {
            v47 = ipa3_ctx;
            if ( (_DWORD)v313 == 1 )
            {
              v49 = (_DWORD *)(ipa3_ctx + 44868);
              goto LABEL_55;
            }
          }
          v49 = (_DWORD *)(v47 + 44868);
LABEL_76:
          *v49 = 1;
          if ( v47 )
          {
            v62 = *(_QWORD *)(v47 + 34152);
            if ( v62 )
            {
              ipc_log_string(v62, "ipa %s:%d secure debug disabled\n", "ipa3_pre_init", 9402);
              v47 = ipa3_ctx;
            }
            v63 = *(_QWORD *)(v47 + 34160);
            if ( v63 )
            {
              ipc_log_string(v63, "ipa %s:%d secure debug disabled\n", "ipa3_pre_init", 9402);
              v47 = ipa3_ctx;
            }
          }
          *(_BYTE *)(v47 + 44861) = 0;
LABEL_82:
          *(_BYTE *)(v47 + 32268) = word_1F7EF0;
          v64 = *(_DWORD *)(v47 + 32248);
          v65 = (_BYTE *)(v47 + 50153);
          *v65 = byte_1F800C;
          v65[1089] = byte_1F8014;
          v65[1251] = byte_1F8016 != 0;
          if ( (v64 | 4) != 4 )
          {
            _warn_printk("Non NORMAL IPA HW mode, is this emulation platform ?");
            __break(0x800u);
          }
          if ( !qword_1F7E18 )
            goto LABEL_93;
          *(_DWORD *)(ipa3_ctx + 43752) = dword_1F7E14;
          v66 = _kmalloc_noprof(16LL * *(unsigned int *)(ipa3_ctx + 43752), 3520);
          v57 = ipa3_ctx;
          *(_QWORD *)(ipa3_ctx + 43760) = v66;
          if ( !v66 )
          {
            v53 = -12;
LABEL_311:
            if ( *(_QWORD *)(v57 + 34152) )
            {
              ipc_log_context_destroy();
              v57 = ipa3_ctx;
              *(_QWORD *)(ipa3_ctx + 34152) = 0;
            }
            goto LABEL_313;
          }
          if ( *(_DWORD *)(v57 + 43752) )
          {
            v67 = 0;
            do
            {
              v68 = 16LL * (int)v67++;
              *(_QWORD *)(*(_QWORD *)(v57 + 43760) + v68) = *(_QWORD *)(qword_1F7E18 + v68);
              *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 43760) + v68 + 8) = *(_QWORD *)(qword_1F7E18 + v68 + 8);
              v57 = ipa3_ctx;
              v69 = *(_DWORD *)(ipa3_ctx + 43752);
            }
            while ( v67 < v69 );
            if ( (unsigned int)ipa3_tz_unlock_reg(*(_QWORD *)(ipa3_ctx + 43760), v69) )
            {
LABEL_213:
              printk(&unk_3CF4D0, "ipa3_pre_init");
              v184 = ipa3_ctx;
              if ( ipa3_ctx )
              {
                v185 = *(_QWORD *)(ipa3_ctx + 34152);
                if ( v185 )
                {
                  ipc_log_string(v185, "ipa %s:%d Failed to unlock memory region using TZ\n", "ipa3_pre_init", 9435);
                  v184 = ipa3_ctx;
                }
                v186 = *(_QWORD *)(v184 + 34160);
                if ( v186 )
                  ipc_log_string(v186, "ipa %s:%d Failed to unlock memory region using TZ\n", "ipa3_pre_init", 9435);
              }
            }
          }
          else if ( (unsigned int)ipa3_tz_unlock_reg(v66, 0) )
          {
            goto LABEL_213;
          }
LABEL_93:
          v70 = (_DWORD *)ipa3_ctx;
          *(_QWORD *)(ipa3_ctx + 30396) = 0x100000000LL;
          v70[7601] = 0;
          v71 = dword_1F7EF4;
          v70[12140] = dword_1F7EF4;
          v70[12141] = dword_1F7EF8;
          if ( !v71 )
            goto LABEL_104;
          v72 = 0;
          while ( 1 )
          {
            if ( v70[12141] )
            {
              if ( v72 > 4 )
                goto LABEL_108;
              v73 = 32LL * (int)v72;
              v74 = &ipa3_res[v73];
              v70[(unsigned __int64)v73 / 4 + 12142] = *(_DWORD *)&ipa3_res[v73 + 376];
              *(_DWORD *)(ipa3_ctx + v73 + 48572) = *(_DWORD *)&ipa3_res[v73 + 380];
              v70 = (_DWORD *)ipa3_ctx;
              if ( *(_DWORD *)(ipa3_ctx + 48564) >= 2u )
              {
                *(_DWORD *)(ipa3_ctx + v73 + 48576) = *((_DWORD *)v74 + 96);
                *(_DWORD *)(ipa3_ctx + v73 + 48580) = *((_DWORD *)v74 + 97);
                v70 = (_DWORD *)ipa3_ctx;
                if ( *(_DWORD *)(ipa3_ctx + 48564) >= 3u )
                {
                  v75 = &ipa3_res[v73];
                  *(_DWORD *)(ipa3_ctx + v73 + 48584) = *(_DWORD *)&ipa3_res[v73 + 392];
                  *(_DWORD *)(ipa3_ctx + v73 + 48588) = *(_DWORD *)&ipa3_res[v73 + 396];
                  v70 = (_DWORD *)ipa3_ctx;
                  if ( *(_DWORD *)(ipa3_ctx + 48564) >= 4u )
                  {
                    *(_DWORD *)(ipa3_ctx + v73 + 48592) = *((_DWORD *)v75 + 100);
                    *(_DWORD *)(ipa3_ctx + v73 + 48596) = *((_DWORD *)v75 + 101);
                    v70 = (_DWORD *)ipa3_ctx;
                    if ( *(_DWORD *)(ipa3_ctx + 48564) > 4u )
                    {
LABEL_108:
                      while ( 1 )
                      {
                        while ( 1 )
                        {
                          __break(0x5512u);
LABEL_104:
                          v76 = _kmalloc_cache_noprof(_kmalloc_noprof, 3520, 184);
                          v77 = ipa3_ctx;
                          *(_QWORD *)(ipa3_ctx + 34176) = v76;
                          if ( !v76 )
                          {
                            v53 = -12;
                            goto LABEL_310;
                          }
                          if ( (unsigned int)ipa3_controller_static_bind(
                                               v76,
                                               *(unsigned int *)(v77 + 32240),
                                               *(unsigned int *)(v77 + 28648)) )
                          {
                            printk(&unk_3E9015, "ipa3_pre_init");
                            v178 = ipa3_ctx;
                            if ( !ipa3_ctx )
                              goto LABEL_224;
                            v179 = *(_QWORD *)(ipa3_ctx + 34152);
                            if ( v179 )
                            {
                              ipc_log_string(v179, "ipa %s:%d fail to static bind IPA ctrl\n", "ipa3_pre_init", 9463);
                              v178 = ipa3_ctx;
                            }
                            v180 = *(_QWORD *)(v178 + 34160);
                            if ( v180 )
                            {
                              ipc_log_string(v180, "ipa %s:%d fail to static bind IPA ctrl\n", "ipa3_pre_init", 9463);
                              v53 = -14;
                            }
                            else
                            {
LABEL_224:
                              v53 = -14;
                            }
LABEL_309:
                            kfree(*(_QWORD *)(ipa3_ctx + 34176));
                            v77 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 34176) = 0;
LABEL_310:
                            kfree(*(_QWORD *)(v77 + 43760));
                            v57 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 43760) = 0;
                            goto LABEL_311;
                          }
                          if ( (unsigned int)ipa3_init_mem_partition(*(unsigned int *)(ipa3_ctx + 32240)) )
                          {
                            printk(&unk_3C04ED, "ipa3_pre_init");
                            v181 = ipa3_ctx;
                            if ( !ipa3_ctx )
                              goto LABEL_225;
                            v182 = *(_QWORD *)(ipa3_ctx + 34152);
                            if ( v182 )
                            {
                              ipc_log_string(v182, "ipa %s:%d :ipa3_init_mem_partition failed\n", "ipa3_pre_init", 9470);
                              v181 = ipa3_ctx;
                            }
                            v183 = *(_QWORD *)(v181 + 34160);
                            if ( v183 )
                            {
                              ipc_log_string(v183, "ipa %s:%d :ipa3_init_mem_partition failed\n", "ipa3_pre_init", 9470);
                              v53 = -19;
                            }
                            else
                            {
LABEL_225:
                              v53 = -19;
                            }
                            goto LABEL_309;
                          }
                          v78 = ipa3_ctx;
                          v79 = *(_DWORD *)(ipa3_ctx + 32248);
                          if ( (v79 | 2) != 3 )
                          {
                            if ( *(_DWORD *)(ipa3_ctx + 48564) )
                              break;
                          }
LABEL_118:
                          if ( (v79 | 4) != 4 )
                          {
                            if ( v78 )
                            {
                              v84 = *(_QWORD *)(v78 + 34152);
                              if ( v84 )
                              {
                                ipc_log_string(v84, "ipa %s:%d not supported in this HW mode\n", "ipa3_get_clks", 6658);
                                v78 = ipa3_ctx;
                              }
                              v85 = *(_QWORD *)(v78 + 34160);
                              if ( v85 )
                                ipc_log_string(v85, "ipa %s:%d not supported in this HW mode\n", "ipa3_get_clks", 6658);
                            }
                            goto LABEL_131;
                          }
                          if ( HIBYTE(word_1F7DF3) == 1 )
                          {
                            if ( v78 )
                            {
                              v82 = *(_QWORD *)(v78 + 34152);
                              if ( v82 )
                              {
                                ipc_log_string(
                                  v82,
                                  "ipa %s:%d Vote IPA clock by bw voting via bus scaling driver\n",
                                  "ipa3_get_clks",
                                  6664);
                                v78 = ipa3_ctx;
                              }
                              v83 = *(_QWORD *)(v78 + 34160);
                              if ( v83 )
                                ipc_log_string(
                                  v83,
                                  "ipa %s:%d Vote IPA clock by bw voting via bus scaling driver\n",
                                  "ipa3_get_clks",
                                  6664);
                            }
LABEL_131:
                            ipa3_clk = 0;
                            goto LABEL_132;
                          }
                          v106 = clk_get(*(_QWORD *)(v78 + 34208) + 16LL, "core_clk");
                          ipa3_clk = v106;
                          if ( v106 >= 0xFFFFFFFFFFFFF001LL )
                          {
                            if ( v106 != -517 )
                            {
                              printk(&unk_3AC34B, "ipa3_get_clks");
                              v259 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v260 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v260 )
                                {
                                  ipc_log_string(v260, "ipa %s:%d fail to get ipa clk\n", "ipa3_get_clks", 6672);
                                  v259 = ipa3_ctx;
                                }
                                v261 = *(_QWORD *)(v259 + 34160);
                                if ( v261 )
                                  ipc_log_string(v261, "ipa %s:%d fail to get ipa clk\n", "ipa3_get_clks", 6672);
                              }
                            }
                            v53 = ipa3_clk;
                            if ( (_DWORD)ipa3_clk )
                              goto LABEL_294;
                          }
LABEL_132:
                          *(_DWORD *)(ipa3_ctx + 30560) = 0;
                          *(_QWORD *)(ipa3_ctx + 30568) = _kmalloc_large_noprof(11520, 3520);
                          active_clients_table_buf = _kmalloc_cache_noprof(dma_alloc_attrs, 3520, 4096);
                          if ( *(_QWORD *)(ipa3_ctx + 30568) )
                          {
                            v87 = 0;
                            for ( i = 3821; i != 3941; ++i )
                            {
                              *(_QWORD *)(ipa3_ctx + 8 * i) = *(_QWORD *)(ipa3_ctx + 30568) + v87;
                              v87 += 96;
                            }
                            v89 = ipa3_ctx;
                            v90 = (_BYTE *)(ipa3_ctx + 51103);
                            v91 = (void *)(ipa3_ctx + 31544);
                            *(_QWORD *)(ipa3_ctx + 31528) = 0x7700000000LL;
                            v92 = memset(v91, 0, 0x190u);
                            v93 = *(_QWORD *)(v89 + 34176);
                            v94 = *(_DWORD *)(v89 + 32240);
                            *(_BYTE *)(v89 + 31536) = 1;
                            *(_DWORD *)(v89 + 34236) = 1;
                            LODWORD(v93) = *(_DWORD *)(v93 + 20);
                            *v90 = 15;
                            *(_DWORD *)(v89 + 34240) = 1;
                            *(_DWORD *)(v89 + 34244) = v93;
                            *(_QWORD *)(v89 + 51396) = 0x200000003LL;
                            if ( v94 >= 0x16 )
                              *(_BYTE *)(v89 + 51104) = 1;
                            if ( (*(_DWORD *)(v89 + 32248) | 2) == 3 )
                              *(_DWORD *)(v89 + 45120) = 1;
                            ((void (__fastcall *)(void *))ipa3_enable_clks)(v92);
                            v95 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
                              v96 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v96 )
                              {
                                ipc_log_string(
                                  v96,
                                  "ipa %s:%d Mapping 0x%x\n",
                                  "ipa3_pre_init",
                                  9533,
                                  *(_DWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 36LL) + dword_1F7DAC);
                                v95 = ipa3_ctx;
                              }
                              v97 = *(_QWORD *)(v95 + 34160);
                              if ( v97 )
                              {
                                ipc_log_string(
                                  v97,
                                  "ipa %s:%d Mapping 0x%x\n",
                                  "ipa3_pre_init",
                                  9533,
                                  *(_DWORD *)(*(_QWORD *)(v95 + 34176) + 36LL) + dword_1F7DAC);
                                v95 = ipa3_ctx;
                              }
                            }
                            v98 = *(_DWORD *)(*(_QWORD *)(v95 + 34176) + 36LL);
                            if ( arm64_use_ng_mappings )
                              v99 = 0x68000000000F13LL;
                            else
                              v99 = 0x68000000000713LL;
                            v100 = ioremap_prot((unsigned int)(v98 + dword_1F7DAC), (unsigned int)dword_1F7DB0, v99);
                            v101 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28632) = v100;
                            if ( !v100 )
                            {
                              printk(&unk_3E903F, "ipa3_pre_init");
                              v187 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v188 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v188 )
                                {
                                  ipc_log_string(v188, "ipa %s:%d :ipa-base ioremap err\n", "ipa3_pre_init", 9538);
                                  v187 = ipa3_ctx;
                                }
                                v189 = *(_QWORD *)(v187 + 34160);
                                if ( v189 )
                                  ipc_log_string(v189, "ipa %s:%d :ipa-base ioremap err\n", "ipa3_pre_init", 9538);
                              }
                              goto LABEL_231;
                            }
                            if ( v101 )
                            {
                              v102 = (const void *)v100;
                              v103 = *(_QWORD *)(v101 + 34152);
                              if ( v103 )
                              {
                                ipc_log_string(
                                  v103,
                                  "ipa %s:%d base(0x%x)+offset(0x%x)=(0x%x) mapped to (0x%p) with len (0x%x)\n",
                                  "ipa3_pre_init",
                                  9549,
                                  dword_1F7DAC,
                                  *(_DWORD *)(*(_QWORD *)(v101 + 34176) + 36LL),
                                  *(_DWORD *)(*(_QWORD *)(v101 + 34176) + 36LL) + dword_1F7DAC,
                                  v102,
                                  dword_1F7DB0);
                                v101 = ipa3_ctx;
                              }
                              v104 = *(_QWORD *)(v101 + 34160);
                              if ( v104 )
                              {
                                ipc_log_string(
                                  v104,
                                  "ipa %s:%d base(0x%x)+offset(0x%x)=(0x%x) mapped to (0x%p) with len (0x%x)\n",
                                  "ipa3_pre_init",
                                  9549,
                                  dword_1F7DAC,
                                  *(_DWORD *)(*(_QWORD *)(v101 + 34176) + 36LL),
                                  *(_DWORD *)(*(_QWORD *)(v101 + 34176) + 36LL) + dword_1F7DAC,
                                  *(const void **)(v101 + 28632),
                                  dword_1F7DB0);
                                v101 = ipa3_ctx;
                              }
                            }
                            if ( *(_DWORD *)(v101 + 32240) == 10 )
                            {
                              if ( !(unsigned int)ipahal_init(
                                                    10,
                                                    *(_QWORD *)(v101 + 28632),
                                                    *(unsigned int *)(v101 + 28648),
                                                    *(_QWORD *)(v101 + 34208) + 16LL) )
                              {
                                v101 = ipa3_ctx;
                                goto LABEL_156;
                              }
                              printk(&unk_3BD600, "ipa3_pre_init");
                              v190 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v191 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v191 )
                                {
                                  ipc_log_string(v191, "ipa %s:%d fail to init ipahal\n", "ipa3_pre_init", 9556);
                                  v190 = ipa3_ctx;
                                }
                                v192 = *(_QWORD *)(v190 + 34160);
                                if ( v192 )
                                  ipc_log_string(v192, "ipa %s:%d fail to init ipahal\n", "ipa3_pre_init", 9556);
                              }
LABEL_231:
                              v53 = -14;
LABEL_290:
                              ipa3_disable_clks();
                              a1 = raw_spin_lock_irqsave(ipa3_ctx + 30560);
                              v218 = active_clients_table_buf;
                              *(_BYTE *)(ipa3_ctx + 31536) = 0;
                              kfree(v218);
                              active_clients_table_buf = 0;
                              kfree(*(_QWORD *)(ipa3_ctx + 30568));
                              v219 = ipa3_ctx;
                              v220 = ipa3_ctx + 30560;
                              *(_QWORD *)(ipa3_ctx + 30568) = 0;
                              *(_QWORD *)(v219 + 31528) = 0x7700000000LL;
                              v221 = raw_spin_unlock_irqrestore(v220, a1);
                              gsi_unmap_base(v221);
                              goto LABEL_291;
                            }
LABEL_156:
                            v105 = v101 + 49152;
                            *(_QWORD *)(v105 + 2256) = v105 + 2256;
                            *(_QWORD *)(v105 + 2264) = v105 + 2256;
                            if ( (unsigned int)ipa_reg_save_init(-1) )
                            {
                              v53 = -14;
LABEL_287:
                              v217 = ipa3_ctx;
                              if ( *(_QWORD *)(ipa3_ctx + 44872) )
                              {
                                ((void (*)(void))iounmap)();
                                v217 = ipa3_ctx;
                              }
                              iounmap(*(_QWORD *)(v217 + 28632));
                              goto LABEL_290;
                            }
                            _mutex_init(
                              ipa3_ctx + 30504,
                              "&ipa3_ctx->ipa3_active_clients.mutex",
                              &ipa3_pre_init___key_1220);
                            v107 = (_DWORD *)(ipa3_ctx + 30552);
                            *(_BYTE *)(ipa3_ctx + 34248) = 1;
                            v107[938] = 1;
                            *v107 = 1;
                            v108 = alloc_workqueue("ipa_power_mgmt", 90, 1);
                            v109 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 31944) = v108;
                            if ( !v108 )
                            {
                              printk(&unk_3F745D, "ipa3_pre_init");
                              v193 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_352;
                              v194 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v194 )
                              {
                                ipc_log_string(
                                  v194,
                                  "ipa %s:%d failed to create power mgmt wq\n",
                                  "ipa3_pre_init",
                                  9586);
                                v193 = ipa3_ctx;
                              }
                              v195 = *(_QWORD *)(v193 + 34160);
                              if ( v195 )
                              {
                                ipc_log_string(
                                  v195,
                                  "ipa %s:%d failed to create power mgmt wq\n",
                                  "ipa3_pre_init",
                                  9586);
                                v53 = -12;
                              }
                              else
                              {
LABEL_352:
                                v53 = -12;
                              }
                              goto LABEL_287;
                            }
                            _mutex_init(
                              v109 + 52392,
                              "&ipa3_ctx->recycle_stats_collection_lock",
                              &ipa3_pre_init___key_1226);
                            v110 = (_QWORD *)ipa3_ctx;
                            memset((void *)(ipa3_ctx + 51456), 0, 0x360u);
                            v110[6540] = 0;
                            v110[6541] = 0;
                            v110[6542] = 0;
                            v110[6543] = 0;
                            v110[6544] = 0;
                            v110[6545] = 0;
                            v110[6546] = 0;
                            v110[6547] = 0;
                            v110[6548] = 0;
                            v111 = alloc_workqueue("%s", (const char *)0x6000A);
                            *(_QWORD *)(ipa3_ctx + 31952) = v111;
                            if ( !v111 )
                            {
                              printk(&unk_3B4820, "ipa3_pre_init");
                              v196 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_363;
                              v197 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v197 )
                              {
                                ipc_log_string(
                                  v197,
                                  "ipa %s:%d failed to create transport power mgmt wq\n",
                                  "ipa3_pre_init",
                                  9599);
                                v196 = ipa3_ctx;
                              }
                              v198 = *(_QWORD *)(v196 + 34160);
                              if ( v198 )
                              {
                                ipc_log_string(
                                  v198,
                                  "ipa %s:%d failed to create transport power mgmt wq\n",
                                  "ipa3_pre_init",
                                  9599);
                                v53 = -12;
                              }
                              else
                              {
LABEL_363:
                                v53 = -12;
                              }
                              goto LABEL_286;
                            }
                            v112 = alloc_workqueue("%s", (const char *)0x6000A);
                            v113 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 51448) = v112;
                            if ( !v112 )
                            {
                              printk(&unk_3AC30A, "ipa3_pre_init");
                              v235 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_369;
                              v236 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v236 )
                              {
                                ipc_log_string(
                                  v236,
                                  "ipa %s:%d failed to create page recycling stats collection wq\n",
                                  "ipa3_pre_init",
                                  9608);
                                v235 = ipa3_ctx;
                              }
                              v237 = *(_QWORD *)(v235 + 34160);
                              if ( v237 )
                              {
                                ipc_log_string(
                                  v237,
                                  "ipa %s:%d failed to create page recycling stats collection wq\n",
                                  "ipa3_pre_init",
                                  9608);
                                v53 = -12;
                              }
                              else
                              {
LABEL_369:
                                v53 = -12;
                              }
                              goto LABEL_285;
                            }
                            memset((void *)(v113 + 51456), 0, 0x360u);
                            _mutex_init(
                              v113 + 31976,
                              "&ipa3_ctx->transport_pm.transport_pm_mutex",
                              &ipa3_pre_init___key_1235);
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v114 = _kmem_cache_create_args("IPA_FLT", 424, &v313, 0);
                            *(_QWORD *)(ipa3_ctx + 29376) = v114;
                            if ( !v114 )
                            {
                              printk(&unk_3CBE04, "ipa3_pre_init");
                              v238 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_375;
                              v239 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v239 )
                              {
                                ipc_log_string(v239, "ipa %s:%d :ipa flt cache create failed\n", "ipa3_pre_init", 9621);
                                v238 = ipa3_ctx;
                              }
                              v240 = *(_QWORD *)(v238 + 34160);
                              if ( v240 )
                              {
                                ipc_log_string(v240, "ipa %s:%d :ipa flt cache create failed\n", "ipa3_pre_init", 9621);
                                v53 = -12;
                              }
                              else
                              {
LABEL_375:
                                v53 = -12;
                              }
                              goto LABEL_284;
                            }
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v115 = _kmem_cache_create_args("IPA_RT", 240, &v313, 0);
                            *(_QWORD *)(ipa3_ctx + 29384) = v115;
                            if ( !v115 )
                            {
                              printk(&unk_3E5E00, "ipa3_pre_init");
                              v241 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_381;
                              v242 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v242 )
                              {
                                ipc_log_string(v242, "ipa %s:%d :ipa rt cache create failed\n", "ipa3_pre_init", 9628);
                                v241 = ipa3_ctx;
                              }
                              v243 = *(_QWORD *)(v241 + 34160);
                              if ( v243 )
                              {
                                ipc_log_string(v243, "ipa %s:%d :ipa rt cache create failed\n", "ipa3_pre_init", 9628);
                                v53 = -12;
                              }
                              else
                              {
LABEL_381:
                                v53 = -12;
                              }
                              goto LABEL_283;
                            }
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v116 = _kmem_cache_create_args("IPA_HDR", 352, &v313, 0);
                            *(_QWORD *)(ipa3_ctx + 29392) = v116;
                            if ( !v116 )
                            {
                              printk(&unk_3BD8A7, "ipa3_pre_init");
                              v244 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_387;
                              v245 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v245 )
                              {
                                ipc_log_string(v245, "ipa %s:%d :ipa hdr cache create failed\n", "ipa3_pre_init", 9635);
                                v244 = ipa3_ctx;
                              }
                              v246 = *(_QWORD *)(v244 + 34160);
                              if ( v246 )
                              {
                                ipc_log_string(v246, "ipa %s:%d :ipa hdr cache create failed\n", "ipa3_pre_init", 9635);
                                v53 = -12;
                              }
                              else
                              {
LABEL_387:
                                v53 = -12;
                              }
                              goto LABEL_282;
                            }
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v117 = _kmem_cache_create_args("IPA_HDR_OFFSET", 32, &v313, 0);
                            *(_QWORD *)(ipa3_ctx + 29400) = v117;
                            if ( !v117 )
                            {
                              printk(&unk_3CBE2E, "ipa3_pre_init");
                              v247 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_393;
                              v248 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v248 )
                              {
                                ipc_log_string(
                                  v248,
                                  "ipa %s:%d :ipa hdr off cache create failed\n",
                                  "ipa3_pre_init",
                                  9643);
                                v247 = ipa3_ctx;
                              }
                              v249 = *(_QWORD *)(v247 + 34160);
                              if ( v249 )
                              {
                                ipc_log_string(
                                  v249,
                                  "ipa %s:%d :ipa hdr off cache create failed\n",
                                  "ipa3_pre_init",
                                  9643);
                                v53 = -12;
                              }
                              else
                              {
LABEL_393:
                                v53 = -12;
                              }
                              goto LABEL_281;
                            }
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v118 = _kmem_cache_create_args("IPA_FNR_STATS", 12, &v313, 0);
                            *(_QWORD *)(ipa3_ctx + 29408) = v118;
                            if ( !v118 )
                            {
                              printk(&unk_3CBE5C, "ipa3_pre_init");
                              v250 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_399;
                              v251 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v251 )
                              {
                                ipc_log_string(
                                  v251,
                                  "ipa %s:%d :ipa fnr stats cache create failed\n",
                                  "ipa3_pre_init",
                                  9650);
                                v250 = ipa3_ctx;
                              }
                              v252 = *(_QWORD *)(v250 + 34160);
                              if ( v252 )
                              {
                                ipc_log_string(
                                  v252,
                                  "ipa %s:%d :ipa fnr stats cache create failed\n",
                                  "ipa3_pre_init",
                                  9650);
                                v53 = -12;
                              }
                              else
                              {
LABEL_399:
                                v53 = -12;
                              }
                              goto LABEL_280;
                            }
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v119 = _kmem_cache_create_args("IPA_HDR_PROC_CTX", 88, &v313, 0);
                            *(_QWORD *)(ipa3_ctx + 29416) = v119;
                            if ( !v119 )
                            {
                              printk(&unk_3E33F9, "ipa3_pre_init");
                              v253 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_405;
                              v254 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v254 )
                              {
                                ipc_log_string(
                                  v254,
                                  "ipa %s:%d :ipa hdr proc ctx cache create failed\n",
                                  "ipa3_pre_init",
                                  9657);
                                v253 = ipa3_ctx;
                              }
                              v255 = *(_QWORD *)(v253 + 34160);
                              if ( v255 )
                              {
                                ipc_log_string(
                                  v255,
                                  "ipa %s:%d :ipa hdr proc ctx cache create failed\n",
                                  "ipa3_pre_init",
                                  9657);
                                v53 = -12;
                              }
                              else
                              {
LABEL_405:
                                v53 = -12;
                              }
                              goto LABEL_279;
                            }
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v120 = _kmem_cache_create_args("IPA_HDR_PROC_CTX_OFFSET", 32, &v313, 0);
                            *(_QWORD *)(ipa3_ctx + 29424) = v120;
                            if ( !v120 )
                            {
                              printk(&unk_3B1B0D, "ipa3_pre_init");
                              v256 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_411;
                              v257 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v257 )
                              {
                                ipc_log_string(
                                  v257,
                                  "ipa %s:%d :ipa hdr proc ctx off cache create failed\n",
                                  "ipa3_pre_init",
                                  9665);
                                v256 = ipa3_ctx;
                              }
                              v258 = *(_QWORD *)(v256 + 34160);
                              if ( v258 )
                              {
                                ipc_log_string(
                                  v258,
                                  "ipa %s:%d :ipa hdr proc ctx off cache create failed\n",
                                  "ipa3_pre_init",
                                  9665);
                                v53 = -12;
                              }
                              else
                              {
LABEL_411:
                                v53 = -12;
                              }
                              goto LABEL_278;
                            }
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v121 = _kmem_cache_create_args("IPA_RT_TBL", 224, &v313, 0);
                            *(_QWORD *)(ipa3_ctx + 29432) = v121;
                            if ( !v121 )
                            {
                              printk(&unk_3CBE8C, "ipa3_pre_init");
                              v262 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_418;
                              v263 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v263 )
                              {
                                ipc_log_string(
                                  v263,
                                  "ipa %s:%d :ipa rt tbl cache create failed\n",
                                  "ipa3_pre_init",
                                  9672);
                                v262 = ipa3_ctx;
                              }
                              v264 = *(_QWORD *)(v262 + 34160);
                              if ( v264 )
                              {
                                ipc_log_string(
                                  v264,
                                  "ipa %s:%d :ipa rt tbl cache create failed\n",
                                  "ipa3_pre_init",
                                  9672);
                                v53 = -12;
                              }
                              else
                              {
LABEL_418:
                                v53 = -12;
                              }
                              goto LABEL_277;
                            }
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v122 = _kmem_cache_create_args("IPA_TX_PKT_WRAPPER", 104, &v313, 0);
                            *(_QWORD *)(ipa3_ctx + 29440) = v122;
                            if ( !v122 )
                            {
                              printk(&unk_3B7964, "ipa3_pre_init");
                              v265 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_419;
                              v266 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v266 )
                              {
                                ipc_log_string(
                                  v266,
                                  "ipa %s:%d :ipa tx pkt wrapper cache create failed\n",
                                  "ipa3_pre_init",
                                  9680);
                                v265 = ipa3_ctx;
                              }
                              v267 = *(_QWORD *)(v265 + 34160);
                              if ( v267 )
                              {
                                ipc_log_string(
                                  v267,
                                  "ipa %s:%d :ipa tx pkt wrapper cache create failed\n",
                                  "ipa3_pre_init",
                                  9680);
                                v53 = -12;
                              }
                              else
                              {
LABEL_419:
                                v53 = -12;
                              }
                              goto LABEL_276;
                            }
                            v315 = 0;
                            v316 = 0;
                            v313 = 0;
                            v314 = 0;
                            v123 = _kmem_cache_create_args("IPA_RX_PKT_WRAPPER", 88, &v313, 0);
                            v124 = (_QWORD *)ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29448) = v123;
                            if ( !v123 )
                            {
                              printk(&unk_3FAAAD, "ipa3_pre_init");
                              v268 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_425;
                              v269 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v269 )
                              {
                                ipc_log_string(
                                  v269,
                                  "ipa %s:%d :ipa rx pkt wrapper cache create failed\n",
                                  "ipa3_pre_init",
                                  9688);
                                v268 = ipa3_ctx;
                              }
                              v270 = *(_QWORD *)(v268 + 34160);
                              if ( v270 )
                              {
                                ipc_log_string(
                                  v270,
                                  "ipa %s:%d :ipa rx pkt wrapper cache create failed\n",
                                  "ipa3_pre_init",
                                  9688);
                                v53 = -12;
                              }
                              else
                              {
LABEL_425:
                                v53 = -12;
                              }
                              goto LABEL_275;
                            }
                            v124[3582] = v124 + 3582;
                            v124[3583] = v124 + 3582;
                            v124[3584] = v124 + 3584;
                            v124[3585] = v124 + 3584;
                            v125 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28768) = ipa3_ctx + 28768;
                            *(_QWORD *)(v125 + 28776) = v125 + 28768;
                            v126 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28688) = ipa3_ctx + 28688;
                            *(_QWORD *)(v126 + 28696) = v126 + 28688;
                            v127 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28784) = ipa3_ctx + 28784;
                            *(_QWORD *)(v127 + 28792) = v127 + 28784;
                            v128 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28704) = ipa3_ctx + 28704;
                            *(_QWORD *)(v128 + 28712) = v128 + 28704;
                            v129 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28800) = ipa3_ctx + 28800;
                            *(_QWORD *)(v129 + 28808) = v129 + 28800;
                            v130 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28720) = ipa3_ctx + 28720;
                            *(_QWORD *)(v130 + 28728) = v130 + 28720;
                            v131 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28816) = ipa3_ctx + 28816;
                            *(_QWORD *)(v131 + 28824) = v131 + 28816;
                            v132 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28736) = ipa3_ctx + 28736;
                            *(_QWORD *)(v132 + 28744) = v132 + 28736;
                            v133 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28832) = ipa3_ctx + 28832;
                            *(_QWORD *)(v133 + 28840) = v133 + 28832;
                            v134 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28752) = ipa3_ctx + 28752;
                            *(_QWORD *)(v134 + 28760) = v134 + 28752;
                            v135 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28848) = ipa3_ctx + 28848;
                            *(_QWORD *)(v135 + 28856) = v135 + 28848;
                            v136 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28872) = ipa3_ctx + 28872;
                            *(_QWORD *)(v136 + 28880) = v136 + 28872;
                            v137 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28888) = ipa3_ctx + 28888;
                            *(_QWORD *)(v137 + 28896) = v137 + 28888;
                            v138 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28984) = ipa3_ctx + 28984;
                            *(_QWORD *)(v138 + 28992) = v138 + 28984;
                            v139 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28904) = ipa3_ctx + 28904;
                            *(_QWORD *)(v139 + 28912) = v139 + 28904;
                            v140 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29000) = ipa3_ctx + 29000;
                            *(_QWORD *)(v140 + 29008) = v140 + 29000;
                            v141 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28920) = ipa3_ctx + 28920;
                            *(_QWORD *)(v141 + 28928) = v141 + 28920;
                            v142 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29016) = ipa3_ctx + 29016;
                            *(_QWORD *)(v142 + 29024) = v142 + 29016;
                            v143 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28936) = ipa3_ctx + 28936;
                            *(_QWORD *)(v143 + 28944) = v143 + 28936;
                            v144 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29032) = ipa3_ctx + 29032;
                            *(_QWORD *)(v144 + 29040) = v144 + 29032;
                            v145 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28952) = ipa3_ctx + 28952;
                            *(_QWORD *)(v145 + 28960) = v145 + 28952;
                            v146 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29048) = ipa3_ctx + 29048;
                            *(_QWORD *)(v146 + 29056) = v146 + 29048;
                            v147 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 28968) = ipa3_ctx + 28968;
                            *(_QWORD *)(v147 + 28976) = v147 + 28968;
                            v148 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29064) = ipa3_ctx + 29064;
                            *(_QWORD *)(v148 + 29072) = v148 + 29064;
                            v149 = (_QWORD *)ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29088) = ipa3_ctx + 29088;
                            v149[3637] = v149 + 3636;
                            v149[3638] = v149 + 3638;
                            v149[3639] = v149 + 3638;
                            v149[3642] = v149 + 3642;
                            v149[3643] = v149 + 3642;
                            v149[3640] = v149 + 3640;
                            v149[3641] = v149 + 3640;
                            v150 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29152) = ipa3_ctx + 29152;
                            *(_QWORD *)(v150 + 29160) = v150 + 29152;
                            v151 = (_QWORD *)ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29184) = ipa3_ctx + 29184;
                            v151[3649] = v151 + 3648;
                            v151[3651] = 0x1000000400000000LL;
                            v151[3653] = 0;
                            v151[3652] = 0;
                            v151[3654] = v151 + 3654;
                            v151[3655] = v151 + 3654;
                            v152 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 29256) = 0x1000000400000000LL;
                            *(_QWORD *)(v152 + 29264) = 0;
                            v153 = (_QWORD *)ipa3_ctx;
                            *(_QWORD *)(v152 + 29272) = 0;
                            v153[3660] = v153 + 3660;
                            v153[3661] = v153 + 3660;
                            v153[3663] = 0x1000000400000000LL;
                            v153[3664] = 0;
                            v153[3665] = 0;
                            v153[3666] = v153 + 3666;
                            v153[3667] = v153 + 3666;
                            v153[3669] = 0x1000000400000000LL;
                            v153[3670] = 0;
                            v154 = ipa3_ctx;
                            v153[3671] = 0;
                            *(_QWORD *)(v154 + 43816) = 0;
                            *(_QWORD *)(v154 + 43824) = 0;
                            *(_QWORD *)(v154 + 43808) = 0x1000000400000000LL;
                            *(_QWORD *)(v154 + 43832) = 0;
                            *(_QWORD *)(v154 + 43840) = 0;
                            *(_QWORD *)(v154 + 43848) = 0;
                            *(_DWORD *)(v154 + 43864) = 0;
                            *(_QWORD *)(v154 + 43856) = 0;
                            *(_QWORD *)(v154 + 32056) = v154 + 32056;
                            *(_QWORD *)(v154 + 32064) = v154 + 32056;
                            *(_QWORD *)(v154 + 32072) = v154 + 32072;
                            *(_QWORD *)(v154 + 32080) = v154 + 32072;
                            *(_QWORD *)(v154 + 32088) = v154 + 32088;
                            *(_QWORD *)(v154 + 32096) = v154 + 32088;
                            _init_waitqueue_head(v154 + 32216, "&ipa3_ctx->msg_waitq", &ipa3_pre_init___key_1267);
                            _mutex_init(ipa3_ctx + 32104, "&ipa3_ctx->msg_lock", &ipa3_pre_init___key_1269);
                            v155 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 32152) = ipa3_ctx + 32152;
                            *(_QWORD *)(v155 + 32160) = v155 + 32152;
                            _mutex_init(v155 + 32168, "&ipa3_ctx->msg_wlan_client_lock", &ipa3_pre_init___key_1271);
                            _mutex_init(
                              ipa3_ctx + 34256,
                              "&ipa3_ctx->q6_proxy_clk_vote_mutex",
                              &ipa3_pre_init___key_1273);
                            _mutex_init(ipa3_ctx + 44800, "&ipa3_ctx->ipa_cne_evt_lock", &ipa3_pre_init___key_1275);
                            _mutex_init(ipa3_ctx + 51336, "&ipa3_ctx->act_tbl_lock", &ipa3_pre_init___key_1277);
                            v156 = (_QWORD *)ipa3_ctx;
                            v157 = ipa3_ctx + 0x8000;
                            *(_QWORD *)(ipa3_ctx + 34184) = 0x1000000400000000LL;
                            v156[4274] = 0;
                            v156[4275] = 0;
                            v156 += 4326;
                            *(_DWORD *)(v157 + 1464) = 0;
                            *v156 = 0;
                            v156[1] = 0;
                            v156[2] = 0;
                            v156[3] = 0;
                            v156[4] = 0;
                            v156[5] = 0;
                            *(_QWORD *)(v157 + 1864) = v157 + 1864;
                            *(_QWORD *)(v157 + 1872) = v157 + 1864;
                            v158 = class_create(&unk_1B1CA0);
                            v159 = ipa3_ctx;
                            *(_QWORD *)(ipa3_ctx + 8) = v158;
                            if ( (unsigned int)alloc_chrdev_region(v159 + 16, 0, 1, &unk_1B1CA0) )
                            {
                              printk(&unk_3A2CD3, "ipa3_pre_init");
                              v271 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_426;
                              v272 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v272 )
                              {
                                ipc_log_string(v272, "ipa %s:%d alloc_chrdev_region err\n", "ipa3_pre_init", 9753);
                                v271 = ipa3_ctx;
                              }
                              v273 = *(_QWORD *)(v271 + 34160);
                              if ( v273 )
                              {
                                ipc_log_string(v273, "ipa %s:%d alloc_chrdev_region err\n", "ipa3_pre_init", 9753);
                                v53 = -19;
                              }
                              else
                              {
LABEL_426:
                                v53 = -19;
                              }
                              goto LABEL_274;
                            }
                            v160 = device_create(
                                     *(_QWORD *)(ipa3_ctx + 8),
                                     0,
                                     *(unsigned int *)(ipa3_ctx + 16),
                                     ipa3_ctx,
                                     &unk_1B1CA0);
                            *(_QWORD *)(ipa3_ctx + 24) = v160;
                            if ( v160 >= 0xFFFFFFFFFFFFF001LL )
                            {
                              printk(&unk_3F4A85, "ipa3_pre_init");
                              v216 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_427;
                              v274 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v274 )
                              {
                                ipc_log_string(v274, "ipa %s:%d :device_create err.\n", "ipa3_pre_init", 9761);
                                v216 = ipa3_ctx;
                              }
                              v275 = *(_QWORD *)(v216 + 34160);
                              if ( v275 )
                              {
                                ipc_log_string(v275, "ipa %s:%d :device_create err.\n", "ipa3_pre_init", 9761);
                                v216 = ipa3_ctx;
                                v53 = -19;
                              }
                              else
                              {
LABEL_427:
                                v53 = -19;
                              }
                              goto LABEL_273;
                            }
                            v161 = wakeup_source_register(a1 + 16, "IPA_WS");
                            v162 = ipa3_ctx + 40960;
                            *(_QWORD *)(ipa3_ctx + 43328) = v161;
                            if ( !v161 )
                            {
                              printk(&unk_3DDE8B, "ipa3_pre_init");
                              v276 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_428;
                              v277 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v277 )
                              {
                                ipc_log_string(
                                  v277,
                                  "ipa %s:%d IPA wakeup source register failed\n",
                                  "ipa3_pre_init",
                                  9770);
                                v276 = ipa3_ctx;
                              }
                              v278 = *(_QWORD *)(v276 + 34160);
                              if ( v278 )
                              {
                                ipc_log_string(
                                  v278,
                                  "ipa %s:%d IPA wakeup source register failed\n",
                                  "ipa3_pre_init",
                                  9770);
                                v53 = -12;
                              }
                              else
                              {
LABEL_428:
                                v53 = -12;
                              }
                              goto LABEL_271;
                            }
                            *(_DWORD *)(v162 + 2376) = 0;
                            v163 = ipa_pm_init(&unk_1F7E20);
                            if ( v163 )
                            {
                              v279 = -v163;
                              printk(&unk_3EE8B5, "ipa3_pre_init");
                              v280 = ipa3_ctx;
                              if ( !ipa3_ctx )
                                goto LABEL_434;
                              v281 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v281 )
                              {
                                ipc_log_string(
                                  v281,
                                  "ipa %s:%d IPA PM initialization failed (%d)\n",
                                  "ipa3_pre_init",
                                  9779,
                                  v279);
                                v280 = ipa3_ctx;
                              }
                              v282 = *(_QWORD *)(v280 + 34160);
                              if ( v282 )
                              {
                                ipc_log_string(
                                  v282,
                                  "ipa %s:%d IPA PM initialization failed (%d)\n",
                                  "ipa3_pre_init",
                                  9779,
                                  v279);
                                v53 = -19;
                              }
                              else
                              {
LABEL_434:
                                v53 = -19;
                              }
                              goto LABEL_272;
                            }
                            v164 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
                              v165 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v165 )
                              {
                                ipc_log_string(v165, "ipa %s:%d IPA power manager initialized\n", "ipa3_pre_init", 9783);
                                v164 = ipa3_ctx;
                              }
                              v166 = *(_QWORD *)(v164 + 34160);
                              if ( v166 )
                              {
                                ipc_log_string(v166, "ipa %s:%d IPA power manager initialized\n", "ipa3_pre_init", 9783);
                                v164 = ipa3_ctx;
                              }
                            }
                            *(_DWORD *)(v164 + 43656) = 0;
                            _init_swait_queue_head(v164 + 43664, "&x->wait", &init_completion___key);
                            v167 = ipa3_ctx;
                            *(_DWORD *)(ipa3_ctx + 43688) = 0;
                            inited = _init_swait_queue_head(v167 + 43696, "&x->wait", &init_completion___key);
                            if ( (unsigned int)ipa3_dma_setup(inited) )
                            {
                              v215 = printk(&unk_3C67FB, "ipa3_pre_init");
                              v283 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v284 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v284 )
                                {
                                  ipc_log_string(v284, "ipa %s:%d Failed to setup IPA DMA\n", "ipa3_pre_init", 9790);
                                  v283 = ipa3_ctx;
                                }
                                v215 = *(_QWORD *)(v283 + 34160);
                                if ( v215 )
                                  v215 = ipc_log_string(
                                           v215,
                                           "ipa %s:%d Failed to setup IPA DMA\n",
                                           "ipa3_pre_init",
                                           9790);
                              }
                              goto LABEL_270;
                            }
                            if ( (unsigned int)ipa3_usb_init() )
                            {
                              v214 = printk(&unk_3B487C, "ipa3_pre_init");
                              v285 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v286 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v286 )
                                {
                                  ipc_log_string(v286, "ipa %s:%d Failed to setup USB\n", "ipa3_pre_init", 9797);
                                  v285 = ipa3_ctx;
                                }
                                v214 = *(_QWORD *)(v285 + 34160);
                                if ( v214 )
                                  v214 = ipc_log_string(v214, "ipa %s:%d Failed to setup USB\n", "ipa3_pre_init", 9797);
                              }
                              goto LABEL_269;
                            }
                            v169 = ipa3_ctx;
                            if ( *(_DWORD *)(ipa3_ctx + 32240) == 10 || *(_DWORD *)(ipa3_ctx + 32248) == 3 )
                            {
                              if ( !(unsigned int)ipa3_gsi_pre_fw_load_init() )
                              {
                                v169 = ipa3_ctx;
                                goto LABEL_190;
                              }
                              v213 = printk(&unk_3D808C, "ipa3_pre_init");
                              v290 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v291 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v291 )
                                {
                                  ipc_log_string(
                                    v291,
                                    "ipa %s:%d gsi pre FW loading config failed\n",
                                    "ipa3_pre_init",
                                    9814);
                                  v290 = ipa3_ctx;
                                }
                                v213 = *(_QWORD *)(v290 + 34160);
                                if ( v213 )
                                  v213 = ipc_log_string(
                                           v213,
                                           "ipa %s:%d gsi pre FW loading config failed\n",
                                           "ipa3_pre_init",
                                           9814);
                              }
LABEL_268:
                              v214 = ipa3_usb_exit(v213);
LABEL_269:
                              v215 = ipa3_dma_shutdown(v214);
LABEL_270:
                              ipa_pm_destroy(v215);
                              v53 = -19;
LABEL_271:
                              device_destroy(*(_QWORD *)(ipa3_ctx + 8), *(unsigned int *)(ipa3_ctx + 16));
LABEL_272:
                              wakeup_source_unregister(*(_QWORD *)(ipa3_ctx + 43328));
                              v216 = ipa3_ctx;
                              *(_QWORD *)(ipa3_ctx + 43328) = 0;
LABEL_273:
                              unregister_chrdev_region(*(unsigned int *)(v216 + 16), 1);
LABEL_274:
                              idr_destroy(ipa3_ctx + 34184);
                              idr_destroy(ipa3_ctx + 29352);
                              idr_destroy(ipa3_ctx + 29304);
                              idr_destroy(ipa3_ctx + 29256);
                              idr_destroy(ipa3_ctx + 29208);
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29448));
LABEL_275:
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29440));
LABEL_276:
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29432));
LABEL_277:
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29424));
LABEL_278:
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29416));
LABEL_279:
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29408));
LABEL_280:
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29400));
LABEL_281:
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29392));
LABEL_282:
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29384));
LABEL_283:
                              kmem_cache_destroy(*(_QWORD *)(ipa3_ctx + 29376));
LABEL_284:
                              destroy_workqueue(*(_QWORD *)(ipa3_ctx + 51448));
LABEL_285:
                              destroy_workqueue(*(_QWORD *)(ipa3_ctx + 31952));
LABEL_286:
                              destroy_workqueue(*(_QWORD *)(ipa3_ctx + 31944));
                              goto LABEL_287;
                            }
LABEL_190:
                            cdev_init(v169 + 32, &ipa3_drv_fops);
                            v170 = ipa3_ctx;
                            *(_QWORD *)(v169 + 128) = &_this_module;
                            *(_QWORD *)(v169 + 136) = &ipa3_drv_fops;
                            v171 = cdev_add(v169 + 32, *(unsigned int *)(v170 + 16), 1);
                            if ( (_DWORD)v171 )
                            {
                              v287 = -(int)v171;
                              v213 = printk(&unk_3A2D21, "ipa3_pre_init");
                              v288 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v289 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v289 )
                                {
                                  ipc_log_string(v289, "ipa %s:%d :cdev_add err=%d\n", "ipa3_pre_init", 9827, v287);
                                  v288 = ipa3_ctx;
                                }
                                v213 = *(_QWORD *)(v288 + 34160);
                                if ( v213 )
                                  v213 = ipc_log_string(
                                           v213,
                                           "ipa %s:%d :cdev_add err=%d\n",
                                           "ipa3_pre_init",
                                           9827,
                                           v287);
                              }
                              goto LABEL_268;
                            }
                            v172 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
                              v173 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v173 )
                              {
                                ipc_log_string(
                                  v173,
                                  "ipa %s:%d ipa cdev added successful. major:%d minor:%d\n",
                                  "ipa3_pre_init",
                                  9833,
                                  *(_DWORD *)(ipa3_ctx + 16) >> 20,
                                  *(_DWORD *)(ipa3_ctx + 16) & 0xFFFFF);
                                v172 = ipa3_ctx;
                              }
                              v171 = *(_QWORD *)(v172 + 34160);
                              if ( v171 )
                              {
                                v171 = ipc_log_string(
                                         v171,
                                         "ipa %s:%d ipa cdev added successful. major:%d minor:%d\n",
                                         "ipa3_pre_init",
                                         9833,
                                         *(_DWORD *)(v172 + 16) >> 20,
                                         *(_DWORD *)(v172 + 16) & 0xFFFFF);
                                v172 = ipa3_ctx;
                              }
                            }
                            v174 = *(_DWORD *)(v172 + 32240);
                            if ( v174 >= 0xF )
                            {
                              v171 = ipa_odl_init();
                              v175 = ipa3_ctx;
                              if ( (_DWORD)v171 )
                              {
                                if ( ipa3_ctx )
                                {
                                  v176 = *(_QWORD *)(ipa3_ctx + 34152);
                                  if ( v176 )
                                  {
                                    ipc_log_string(v176, "ipa %s:%d Error: ODL init fialed\n", "ipa3_pre_init", 9838);
                                    v175 = ipa3_ctx;
                                  }
                                  v177 = *(_QWORD *)(v175 + 34160);
                                  if ( v177 )
                                    ipc_log_string(v177, "ipa %s:%d Error: ODL init fialed\n", "ipa3_pre_init", 9838);
                                }
LABEL_267:
                                v213 = cdev_del(v169 + 32);
                                goto LABEL_268;
                              }
                              v174 = *(_DWORD *)(ipa3_ctx + 32240);
                            }
                            if ( v174 != 14 )
                              v171 = ipa3_proxy_clk_unvote();
                            v199 = ipa3_enable_napi_netdev(v171);
                            v200 = ipa3_wwan_init(v199);
                            if ( v200 )
                            {
                              v292 = -v200;
                              v211 = printk(&unk_3D230B, "ipa3_pre_init");
                              v293 = ipa3_ctx;
                              if ( ipa3_ctx )
                              {
                                v294 = *(_QWORD *)(ipa3_ctx + 34152);
                                if ( v294 )
                                {
                                  ipc_log_string(
                                    v294,
                                    "ipa %s:%d :ipa3_wwan_init err=%d\n",
                                    "ipa3_pre_init",
                                    9858,
                                    v292);
                                  v293 = ipa3_ctx;
                                }
                                v211 = *(_QWORD *)(v293 + 34160);
                                if ( v211 )
                                  v211 = ipc_log_string(
                                           v211,
                                           "ipa %s:%d :ipa3_wwan_init err=%d\n",
                                           "ipa3_pre_init",
                                           9858,
                                           v292);
                              }
                            }
                            else
                            {
                              v201 = ipa3_ctx;
                              if ( *(_BYTE *)(ipa3_ctx + 48858) != 1 )
                                goto LABEL_249;
                              v202 = ipa3_rmnet_ctl_init();
                              if ( v202 )
                              {
                                v298 = -v202;
                                v208 = printk(&unk_3C9544, "ipa3_pre_init");
                                v299 = ipa3_ctx;
                                if ( ipa3_ctx )
                                {
                                  v300 = *(_QWORD *)(ipa3_ctx + 34152);
                                  if ( v300 )
                                  {
                                    ipc_log_string(
                                      v300,
                                      "ipa %s:%d :ipa3_rmnet_ctl_init err=%d\n",
                                      "ipa3_pre_init",
                                      9866,
                                      v298);
                                    v299 = ipa3_ctx;
                                  }
                                  v208 = *(_QWORD *)(v299 + 34160);
                                  if ( v208 )
                                    v208 = ipc_log_string(
                                             v208,
                                             "ipa %s:%d :ipa3_rmnet_ctl_init err=%d\n",
                                             "ipa3_pre_init",
                                             9866,
                                             v298);
                                }
                              }
                              else
                              {
                                v201 = ipa3_ctx;
LABEL_249:
                                if ( *(_BYTE *)(v201 + 48859) == 1 )
                                {
                                  v203 = ipa3_rmnet_ll_init();
                                  if ( !v203 )
                                  {
                                    v201 = ipa3_ctx;
                                    goto LABEL_252;
                                  }
                                  v301 = -v203;
                                  v208 = printk(&unk_3C0573, "ipa3_pre_init");
                                  v302 = ipa3_ctx;
                                  if ( ipa3_ctx )
                                  {
                                    v303 = *(_QWORD *)(ipa3_ctx + 34152);
                                    if ( v303 )
                                    {
                                      ipc_log_string(
                                        v303,
                                        "ipa %s:%d :ipa3_rmnet_ll_init err=%d\n",
                                        "ipa3_pre_init",
                                        9875,
                                        v301);
                                      v302 = ipa3_ctx;
                                    }
                                    v208 = *(_QWORD *)(v302 + 34160);
                                    if ( v208 )
                                      v208 = ipc_log_string(
                                               v208,
                                               "ipa %s:%d :ipa3_rmnet_ll_init err=%d\n",
                                               "ipa3_pre_init",
                                               9875,
                                               v301);
                                  }
                                }
                                else
                                {
LABEL_252:
                                  *(_QWORD *)(v201 + 51264) = &ipa_rmnet_notifier_list;
                                  *(_QWORD *)(v201 + 51272) = v201 + 51272;
                                  *(_QWORD *)(v201 + 51280) = v201 + 51272;
                                  *(_DWORD *)(v201 + 51256) = 0;
                                  *(_DWORD *)(v201 + 51289) = 0;
                                  *(_DWORD *)(v201 + 51292) = 0;
                                  _mutex_init(
                                    v201 + 48800,
                                    "&ipa3_ctx->app_clock_vote.mutex",
                                    &ipa3_pre_init___key_1305);
                                  _mutex_init(ipa3_ctx + 52440, "&ipa3_ctx->ssr_lock", &ipa3_pre_init___key_1307);
                                  v204 = ipa3_ctx + 49152;
                                  *(_BYTE *)(ipa3_ctx + 51096) = 0;
                                  *(_BYTE *)(v204 + 2144) = 0;
                                  v205 = qcom_va_md_register("ipa_mini", &qcom_va_md_ipa_notif_blk);
                                  if ( (_DWORD)v205 )
                                  {
                                    v295 = v205;
                                    v205 = printk(&unk_3B79DA, "ipa3_pre_init");
                                    v296 = ipa3_ctx;
                                    if ( ipa3_ctx )
                                    {
                                      v297 = *(_QWORD *)(ipa3_ctx + 34152);
                                      if ( v297 )
                                      {
                                        ipc_log_string(
                                          v297,
                                          "ipa %s:%d ipa mini qcom_va_md_register failed = %d\n",
                                          "ipa3_pre_init",
                                          9900,
                                          v295);
                                        v296 = ipa3_ctx;
                                      }
                                      v205 = *(_QWORD *)(v296 + 34160);
                                      if ( v205 )
                                        v205 = ipc_log_string(
                                                 v205,
                                                 "ipa %s:%d ipa mini qcom_va_md_register failed = %d\n",
                                                 "ipa3_pre_init",
                                                 9900,
                                                 v295);
                                    }
                                  }
                                  else
                                  {
                                    v206 = ipa3_ctx;
                                    if ( ipa3_ctx )
                                    {
                                      v207 = *(_QWORD *)(ipa3_ctx + 34152);
                                      if ( v207 )
                                      {
                                        ipc_log_string(
                                          v207,
                                          "ipa %s:%d ipa mini qcom_va_md_register success\n",
                                          "ipa3_pre_init",
                                          9902);
                                        v206 = ipa3_ctx;
                                      }
                                      v205 = *(_QWORD *)(v206 + 34160);
                                      if ( v205 )
                                        v205 = ipc_log_string(
                                                 v205,
                                                 "ipa %s:%d ipa mini qcom_va_md_register success\n",
                                                 "ipa3_pre_init",
                                                 9902);
                                    }
                                  }
                                  v208 = ipa_opt_log_init(v205);
                                  if ( !(_DWORD)v208 )
                                  {
                                    v53 = 0;
                                    goto LABEL_314;
                                  }
                                  v209 = ipa3_ctx;
                                  if ( ipa3_ctx )
                                  {
                                    v210 = *(_QWORD *)(ipa3_ctx + 34152);
                                    if ( v210 )
                                    {
                                      ipc_log_string(
                                        v210,
                                        "ipa %s:%d Error: OPT LOG init failed\n",
                                        "ipa3_pre_init",
                                        9907);
                                      v209 = ipa3_ctx;
                                    }
                                    v208 = *(_QWORD *)(v209 + 34160);
                                    if ( v208 )
                                      v208 = ipc_log_string(
                                               v208,
                                               "ipa %s:%d Error: OPT LOG init failed\n",
                                               "ipa3_pre_init",
                                               9907);
                                  }
                                }
                              }
                              v211 = ipa3_wwan_cleanup(v208);
                            }
                            v212 = ipa3_disable_napi_netdev(v211);
                            if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0xFu )
                              ipa_odl_cleanup(v212);
                            goto LABEL_267;
                          }
                          printk(&unk_3C059B, v86);
                          v53 = -12;
LABEL_291:
                          if ( ipa3_clk )
                            clk_put();
                          ipa3_clk = 0;
LABEL_294:
                          if ( !*(_DWORD *)(ipa3_ctx + 48564) )
                            goto LABEL_309;
                          v222 = *(_QWORD *)(ipa3_ctx + 34176);
                          v223 = 0;
                          v226 = *(_QWORD *)(v222 + 152);
                          v225 = v222 + 152;
                          v224 = v226;
                          if ( !v226 || v224 >= 0xFFFFFFFFFFFFF001LL )
                            goto LABEL_308;
                          icc_put();
                          v227 = ipa3_ctx;
                          *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 152LL) = 0;
                          if ( *(_DWORD *)(v227 + 48564) < 2u )
                            goto LABEL_309;
                          v228 = *(_QWORD *)(v227 + 34176);
                          v223 = 1;
                          v229 = *(_QWORD *)(v228 + 160);
                          v225 = v228 + 152;
                          if ( !v229 || v229 > 0xFFFFFFFFFFFFF000LL )
                            goto LABEL_308;
                          icc_put();
                          *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 160LL) = 0;
                          if ( *(_DWORD *)(ipa3_ctx + 48564) < 3u )
                            goto LABEL_309;
                          v230 = *(_QWORD *)(ipa3_ctx + 34176);
                          v223 = 2;
                          v231 = *(_QWORD *)(v230 + 168);
                          v225 = v230 + 152;
                          if ( !v231 || v231 > 0xFFFFFFFFFFFFF000LL )
                            goto LABEL_308;
                          icc_put();
                          *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 168LL) = 0;
                          if ( *(_DWORD *)(ipa3_ctx + 48564) < 4u )
                            goto LABEL_309;
                          v232 = *(_QWORD *)(ipa3_ctx + 34176);
                          v223 = 3;
                          v233 = *(_QWORD *)(v232 + 176);
                          v225 = v232 + 152;
                          if ( !v233 || v233 > 0xFFFFFFFFFFFFF000LL )
                          {
LABEL_308:
                            *(_QWORD *)(v225 + 8 * v223) = 0;
                            goto LABEL_309;
                          }
                          icc_put();
                          *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 176LL) = 0;
                          if ( *(_DWORD *)(ipa3_ctx + 48564) <= 4u )
                            goto LABEL_309;
                        }
                        v80 = of_icc_get(*(_QWORD *)(ipa3_ctx + 34208) + 16LL, qword_1F7F00);
                        v78 = ipa3_ctx;
                        v81 = (_QWORD *)(ipa3_ctx + 34176);
                        *(_QWORD *)(*v81 + 152LL) = v80;
                        if ( *(_QWORD *)(*v81 + 152LL) > 0xFFFFFFFFFFFFF000LL )
                        {
                          a1 = 0;
LABEL_457:
                          printk(&unk_3D51AB, "ipa3_pre_init");
                          v304 = ipa3_ctx;
                          if ( ipa3_ctx )
                          {
                            v305 = *(_QWORD *)(ipa3_ctx + 34152);
                            if ( v305 )
                            {
                              ipc_log_string(v305, "ipa %s:%d fail to register with bus mgr!\n", "ipa3_pre_init", 9483);
                              v304 = ipa3_ctx;
                            }
                            v306 = *(_QWORD *)(v304 + 34160);
                            if ( v306 )
                            {
                              ipc_log_string(v306, "ipa %s:%d fail to register with bus mgr!\n", "ipa3_pre_init", 9483);
                              v304 = ipa3_ctx;
                            }
                          }
                          v53 = *(_DWORD *)(*(_QWORD *)(v304 + 34176) + 8 * a1 + 152);
                          if ( v53 != -517 )
                          {
                            printk(&unk_3F4A62, "ipa3_pre_init");
                            v307 = ipa3_ctx;
                            if ( ipa3_ctx )
                            {
                              v308 = *(_QWORD *)(ipa3_ctx + 34152);
                              if ( v308 )
                              {
                                ipc_log_string(
                                  v308,
                                  "ipa %s:%d Failed to get path %s\n",
                                  "ipa3_pre_init",
                                  9487,
                                  **(const char ***)(ipa3_ctx + 34208));
                                v307 = ipa3_ctx;
                              }
                              v309 = v307 + 0x8000;
                              v310 = *(_QWORD *)(v309 + 1392);
                              if ( v310 )
                                ipc_log_string(
                                  v310,
                                  "ipa %s:%d Failed to get path %s\n",
                                  "ipa3_pre_init",
                                  9487,
                                  **(const char ***)(v309 + 1440));
                            }
                          }
                          goto LABEL_294;
                        }
                        if ( *(_DWORD *)(v78 + 48564) >= 2u )
                        {
                          *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 160LL) = of_icc_get(v81[4] + 16LL, qword_1F7F08);
                          v78 = ipa3_ctx;
                          if ( *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 160LL) > 0xFFFFFFFFFFFFF000LL )
                          {
                            a1 = 1;
                            goto LABEL_457;
                          }
                          if ( *(_DWORD *)(ipa3_ctx + 48564) >= 3u )
                          {
                            *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 168LL) = of_icc_get(
                                                                                   *(_QWORD *)(ipa3_ctx + 34208) + 16LL,
                                                                                   qword_1F7F10);
                            v78 = ipa3_ctx;
                            if ( *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 168LL) > 0xFFFFFFFFFFFFF000LL )
                            {
                              a1 = 2;
                              goto LABEL_457;
                            }
                            if ( *(_DWORD *)(ipa3_ctx + 48564) >= 4u )
                            {
                              *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 176LL) = of_icc_get(
                                                                                     *(_QWORD *)(ipa3_ctx + 34208)
                                                                                   + 16LL,
                                                                                     qword_1F7F18);
                              v78 = ipa3_ctx;
                              if ( *(_QWORD *)(*(_QWORD *)(ipa3_ctx + 34176) + 176LL) > 0xFFFFFFFFFFFFF000LL )
                              {
                                a1 = 3;
                                goto LABEL_457;
                              }
                              if ( *(_DWORD *)(ipa3_ctx + 48564) > 4u )
                                continue;
                            }
                          }
                        }
                        v79 = *(_DWORD *)(v78 + 32248);
                        goto LABEL_118;
                      }
                    }
                  }
                }
              }
              v71 = v70[12140];
            }
            if ( ++v72 >= v71 )
              goto LABEL_104;
          }
        }
      }
      else
      {
        v54 = *v48;
      }
      v49 = (_DWORD *)(ipa3_ctx + 44868);
      if ( v54 == 1 )
      {
LABEL_55:
        *v49 = 0;
        if ( v47 )
        {
          v55 = *(_QWORD *)(v47 + 34152);
          if ( v55 )
          {
            ipc_log_string(v55, "ipa %s:%d secure debug enabled\n", "ipa3_pre_init", 9399);
            v47 = ipa3_ctx;
          }
          v56 = *(_QWORD *)(v47 + 34160);
          if ( v56 )
          {
            ipc_log_string(v56, "ipa %s:%d secure debug enabled\n", "ipa3_pre_init", 9399);
            v47 = ipa3_ctx;
          }
        }
        goto LABEL_82;
      }
      goto LABEL_76;
    }
LABEL_468:
    _fortify_panic(17, v43, v45);
    StatusReg = _ReadStatusReg(SP_EL0);
    v312 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ipa3_pre_init__alloc_tag;
    v43 = strlen((const char *)qword_1F7FD8) + 1;
    v44 = _kmalloc_noprof(v43, 3520);
    *(_QWORD *)(StatusReg + 80) = v312;
  }
  if ( !(unsigned int)__ratelimit(&ipa3_pre_init__rs_1194, "ipa3_pre_init") )
  {
    v57 = ipa3_ctx;
    if ( ipa3_ctx )
      goto LABEL_62;
    goto LABEL_69;
  }
  printk(&unk_3AC2DD, "ipa3_pre_init");
  v57 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_69;
LABEL_62:
  v58 = *(_QWORD *)(v57 + 34152);
  if ( v58 )
  {
    ipc_log_string(v58, "ipa %s:%d Failed to alloc uC FW file name\n", "ipa3_pre_init", 9374);
    v57 = ipa3_ctx;
  }
  v59 = *(_QWORD *)(v57 + 34160);
  if ( v59 )
  {
    ipc_log_string(v59, "ipa %s:%d Failed to alloc uC FW file name\n", "ipa3_pre_init", 9374);
    v57 = ipa3_ctx;
    v53 = -12;
  }
  else
  {
LABEL_69:
    v53 = -12;
  }
LABEL_313:
  kfree(*(_QWORD *)(v57 + 48864));
  *(_QWORD *)(ipa3_ctx + 48864) = 0;
LABEL_314:
  _ReadStatusReg(SP_EL0);
  return v53;
}
