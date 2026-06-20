__int64 __fastcall reg_process_master_chan_list_ext(_QWORD *a1)
{
  __int64 v2; // x20
  __int64 psoc_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x21
  __int64 psoc_tx_ops; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _DWORD *v22; // x8
  __int64 v23; // x22
  __int64 v24; // x23
  __int64 v25; // x8
  const char *v26; // x2
  const char *v27; // x3
  unsigned int v28; // w23
  _WORD *v29; // x9
  int v30; // w6
  __int64 v31; // x8
  _WORD *v32; // x9
  int v33; // w6
  __int64 v34; // x8
  _QWORD *v35; // x25
  _DWORD *v36; // x27
  _DWORD *v37; // x28
  _DWORD *v38; // x26
  __int64 v39; // x12
  _WORD *v40; // x13
  int v41; // w6
  _QWORD *v42; // x13
  unsigned int *v43; // x14
  _DWORD *v44; // x12
  __int64 v45; // x15
  _WORD *v46; // x16
  int v47; // w6
  __int64 v48; // x14
  int v49; // w15
  _WORD *v50; // x12
  int v51; // w6
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
  __int64 v68; // x24
  int v69; // w8
  _BYTE *v70; // x8
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  const char *v79; // x2
  __int64 v80; // x20
  __int64 v81; // x0
  void (__fastcall *v82)(__int64, __int64, __int64 *); // x8
  __int64 v83; // x1
  __int64 v84; // x21
  int v85; // w19
  unsigned int v86; // w19
  __int64 v87; // x0
  double v88; // d0
  double v89; // d1
  double v90; // d2
  double v91; // d3
  double v92; // d4
  double v93; // d5
  double v94; // d6
  double v95; // d7
  double (*v96)(void); // x8
  __int64 v97; // x20
  double v98; // d0
  unsigned int *v99; // x8
  double v100; // d1
  double v101; // d2
  double v102; // d3
  double v103; // d4
  double v104; // d5
  double v105; // d6
  double v106; // d7
  __int64 v108; // x9
  __int64 v109; // x10
  int v110; // w12
  __int64 i; // x9
  __int64 v112; // x14
  __int64 v113; // x13
  int v114; // w15
  __int64 v115; // x14
  __int64 v116; // x13
  int v117; // w15
  __int64 v118; // x14
  __int64 v119; // x13
  int v120; // w15
  double v121; // d0
  double v122; // d1
  double v123; // d2
  double v124; // d3
  double v125; // d4
  double v126; // d5
  double v127; // d6
  double v128; // d7
  char v129; // w8
  char v130; // w8
  char v131; // w8
  __int64 v132; // x17
  _WORD *v133; // x0
  int v134; // w8
  unsigned int v135; // w4
  __int64 v136; // x9
  unsigned int v137; // w10
  unsigned int v138; // w11
  _WORD *v139; // x12
  __int64 v140; // x13
  unsigned int v141; // w14
  unsigned int v142; // w15
  _WORD *v143; // x10
  __int64 v144; // x9
  _WORD *v145; // x10
  unsigned int v146; // w11
  unsigned int v147; // w1
  __int64 v148; // x16
  _WORD *v149; // x12
  __int64 v150; // x8
  _WORD *v151; // x15
  _WORD *v152; // x9
  __int64 v153; // x10
  unsigned int v154; // w11
  unsigned int v155; // w12
  unsigned int v156; // w13
  _WORD *v157; // x9
  __int64 v158; // x8
  _WORD *v159; // x9
  unsigned int v160; // w10
  _WORD *v161; // x9
  __int64 v162; // x2
  int v163; // w8
  __int64 v164; // x9
  unsigned int v165; // w12
  __int64 v166; // x11
  _WORD *v167; // x10
  unsigned int v168; // w13
  unsigned int v169; // w14
  char *v170; // x10
  __int64 v171; // x9
  _WORD *v172; // x10
  unsigned int v173; // w11
  _WORD *v174; // x9
  __int64 v175; // x12
  int v176; // w8
  __int64 v177; // x9
  unsigned int v178; // w12
  __int64 v179; // x11
  _WORD *v180; // x10
  unsigned int v181; // w13
  unsigned int v182; // w14
  char *v183; // x10
  __int64 v184; // x9
  _WORD *v185; // x10
  unsigned int v186; // w11
  _WORD *v187; // x13
  __int64 v188; // x11
  int v189; // w8
  __int64 v190; // x9
  _WORD *v191; // x3
  _WORD *v192; // x10
  __int64 v193; // x11
  unsigned int v194; // w12
  unsigned int v195; // w13
  unsigned int v196; // w14
  _WORD *v197; // x10
  __int64 v198; // x9
  _WORD *v199; // x10
  unsigned int v200; // w11
  _WORD *v201; // x11
  __int64 v202; // x12
  int v203; // w8
  __int64 v204; // x9
  _WORD *v205; // x10
  unsigned int v206; // w12
  __int64 v207; // x11
  unsigned int v208; // w13
  unsigned int v209; // w14
  _WORD *v210; // x10
  __int64 v211; // x9
  _WORD *v212; // x10
  unsigned int v213; // w11
  unsigned __int64 v214; // x8
  unsigned __int64 v215; // x17
  unsigned int *v216; // x16
  __int64 *v217; // x14
  __int64 v218; // x0
  int *v219; // x15
  __int64 v220; // x1
  int v221; // w17
  __int64 v222; // x2
  _WORD *v223; // x3
  unsigned int v224; // w6
  __int64 v225; // x5
  unsigned int v226; // w7
  unsigned int v227; // w24
  __int64 v228; // x0
  _WORD *v229; // x1
  unsigned int v230; // w2
  __int64 v231; // x16
  __int64 v232; // x17
  int v233; // w14
  __int64 v234; // x15
  _WORD *v235; // x0
  unsigned int v236; // w2
  __int64 v237; // x1
  unsigned int v238; // w3
  unsigned int v239; // w5
  __int64 v240; // x17
  __int64 v241; // x15
  _WORD *v242; // x16
  unsigned int v243; // w17
  _DWORD *v244; // x12
  int v245; // w8
  int v246; // w8
  int v247; // w8
  int v248; // w8
  __int64 v249; // x24
  _QWORD *v250; // x28
  __int64 v251; // x1
  unsigned int *v252; // x26
  __int64 v253; // x1
  __int64 v254; // x1
  int v255; // w8
  __int64 pdev_by_id; // x0
  __int64 v257; // x21
  double v258; // d0
  unsigned int v259; // w0
  unsigned int *v260; // x8
  double v261; // d1
  double v262; // d2
  double v263; // d3
  double v264; // d4
  double v265; // d5
  double v266; // d6
  double v267; // d7
  _DWORD *v268; // [xsp+8h] [xbp-1A8h]
  const void *v269; // [xsp+10h] [xbp-1A0h]
  unsigned int v270; // [xsp+1Ch] [xbp-194h]
  unsigned int v271; // [xsp+20h] [xbp-190h]
  unsigned int v272; // [xsp+24h] [xbp-18Ch]
  const void *v273; // [xsp+28h] [xbp-188h]
  const void *v274; // [xsp+30h] [xbp-180h]
  _WORD *v275; // [xsp+38h] [xbp-178h]
  __int64 v276; // [xsp+40h] [xbp-170h]
  __int64 v277; // [xsp+48h] [xbp-168h]
  __int64 v278; // [xsp+50h] [xbp-160h]
  __int64 v279; // [xsp+58h] [xbp-158h]
  _WORD *v280; // [xsp+60h] [xbp-150h]
  _WORD *v281; // [xsp+68h] [xbp-148h]
  unsigned int v282; // [xsp+70h] [xbp-140h]
  __int64 v283; // [xsp+78h] [xbp-138h]
  __int64 v284; // [xsp+80h] [xbp-130h]
  int v285; // [xsp+88h] [xbp-128h]
  unsigned int v286; // [xsp+8Ch] [xbp-124h]
  _BYTE *v287; // [xsp+90h] [xbp-120h]
  char v288[4]; // [xsp+9Ch] [xbp-114h] BYREF
  __int64 v289; // [xsp+A0h] [xbp-110h] BYREF
  _QWORD v290[7]; // [xsp+A8h] [xbp-108h] BYREF
  _QWORD v291[4]; // [xsp+E0h] [xbp-D0h]
  _QWORD v292[4]; // [xsp+100h] [xbp-B0h] BYREF
  _DWORD v293[4]; // [xsp+120h] [xbp-90h]
  _BYTE v294[32]; // [xsp+130h] [xbp-80h] BYREF
  _QWORD v295[4]; // [xsp+150h] [xbp-60h]
  _DWORD *v296; // [xsp+170h] [xbp-40h]
  _DWORD *v297; // [xsp+178h] [xbp-38h]
  _DWORD *v298; // [xsp+180h] [xbp-30h]
  _DWORD *v299; // [xsp+188h] [xbp-28h]
  _DWORD v300[4]; // [xsp+190h] [xbp-20h]
  __int64 v301; // [xsp+1A0h] [xbp-10h]

  v301 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v288[0] = 0;
  psoc_obj = reg_get_psoc_obj(v2);
  if ( !psoc_obj )
  {
    v26 = "%s: psoc reg component is NULL";
LABEL_9:
    v27 = "__reg_process_master_chan_list_ext";
    goto LABEL_10;
  }
  v12 = psoc_obj;
  psoc_tx_ops = reg_get_psoc_tx_ops(v2);
  if ( !psoc_tx_ops )
    goto LABEL_11;
  v22 = *(_DWORD **)(psoc_tx_ops + 136);
  v23 = *((unsigned __int8 *)a1 + 13);
  v24 = psoc_tx_ops;
  if ( v22 )
  {
    if ( *(v22 - 1) != 13449260 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, _QWORD, char *))v22)(v2, (unsigned int)v23, v288);
    v25 = *((unsigned int *)a1 + 12);
    if ( !(_DWORD)v25 )
      goto LABEL_19;
LABEL_13:
    v29 = (_WORD *)(a1[8] + 4LL);
    while ( 1 )
    {
      v30 = (unsigned __int16)*v29 >= (unsigned int)(unsigned __int16)*((_DWORD *)a1 + 9)
          ? (unsigned __int16)*((_DWORD *)a1 + 9)
          : (unsigned __int16)*v29;
      if ( (unsigned int)(unsigned __int16)*(v29 - 1) - v30 < (unsigned __int16)*(v29 - 2) )
        break;
      --v25;
      v29 += 7;
      if ( !v25 )
        goto LABEL_19;
    }
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: start freq = %u, end_freq = %u, max_bw = %u",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "reg_validate_reg_rules");
    v79 = "%s: Invalid 2GHz reg rules received from fw";
LABEL_61:
    qdf_trace_msg(0x51u, 2u, v79, v71, v72, v73, v74, v75, v76, v77, v78, "reg_validate_master_chan_list_ext");
    v28 = 4;
    goto LABEL_62;
  }
  v288[0] = *((_BYTE *)a1 + 13);
  v25 = *((unsigned int *)a1 + 12);
  if ( (_DWORD)v25 )
    goto LABEL_13;
LABEL_19:
  v31 = *((unsigned int *)a1 + 13);
  if ( (_DWORD)v31 )
  {
    v32 = (_WORD *)(a1[9] + 4LL);
    while ( 1 )
    {
      v33 = (unsigned __int16)*v32 >= (unsigned int)(unsigned __int16)*((_DWORD *)a1 + 11)
          ? (unsigned __int16)*((_DWORD *)a1 + 11)
          : (unsigned __int16)*v32;
      if ( (unsigned int)(unsigned __int16)*(v32 - 1) - v33 < (unsigned __int16)*(v32 - 2) )
        break;
      --v31;
      v32 += 7;
      if ( !v31 )
        goto LABEL_26;
    }
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: start freq = %u, end_freq = %u, max_bw = %u",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "reg_validate_reg_rules");
    v79 = "%s: Invalid 5GHz reg rules received from fw";
    goto LABEL_61;
  }
LABEL_26:
  v34 = 0;
  v35 = (_QWORD *)(v12 + 90112);
  v36 = a1 + 21;
  v37 = a1 + 35;
  v38 = a1 + 27;
  do
  {
    v39 = *((unsigned int *)a1 + v34 + 50);
    if ( (_DWORD)v39 )
    {
      v40 = (_WORD *)(a1[v34 + 31] + 4LL);
      do
      {
        v41 = (unsigned __int16)*v40 >= (unsigned int)(unsigned __int16)*((_DWORD *)a1 + v34 + 30)
            ? (unsigned __int16)*((_DWORD *)a1 + v34 + 30)
            : (unsigned __int16)*v40;
        if ( (unsigned int)(unsigned __int16)*(v40 - 1) - v41 < (unsigned __int16)*(v40 - 2) )
          goto LABEL_58;
        --v39;
        v40 += 7;
      }
      while ( v39 );
    }
    v42 = &v37[4 * v34];
    v43 = &v38[2 * v34];
    v44 = &v36[2 * v34];
    v45 = *v43;
    if ( (_DWORD)v45 )
    {
      v46 = (_WORD *)(*v42 + 4LL);
      do
      {
        v47 = (unsigned __int16)*v46 >= (unsigned int)(unsigned __int16)*v44
            ? (unsigned __int16)*v44
            : (unsigned __int16)*v46;
        if ( (unsigned int)(unsigned __int16)*(v46 - 1) - v47 < (unsigned __int16)*(v46 - 2) )
          goto LABEL_58;
        --v45;
        v46 += 7;
      }
      while ( v45 );
    }
    v48 = v43[1];
    if ( (_DWORD)v48 )
    {
      v49 = v44[1];
      v50 = (_WORD *)(v42[1] + 4LL);
      while ( 1 )
      {
        v51 = (unsigned __int16)*v50 >= (unsigned int)(unsigned __int16)v49
            ? (unsigned __int16)v49
            : (unsigned __int16)*v50;
        if ( (unsigned int)(unsigned __int16)*(v50 - 1) - v51 < (unsigned __int16)*(v50 - 2) )
          break;
        --v48;
        v50 += 7;
        if ( !v48 )
          goto LABEL_48;
      }
LABEL_58:
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: start freq = %u, end_freq = %u, max_bw = %u",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "reg_validate_reg_rules");
      v79 = "%s: Invalid 6GHz AP reg rules received from fw";
      goto LABEL_61;
    }
LABEL_48:
    ++v34;
  }
  while ( v34 != 4 );
  if ( (reg_ignore_default_country(v12, a1) & 1) != 0
    && !(unsigned int)((__int64 (__fastcall *)(__int64, _QWORD *, __int64))reg_set_curr_country)(v12, a1, v24) )
  {
    qdf_trace_msg(
      0x51u,
      8u,
      "%s: WLAN restart - Ignore default CC for phy_id: %u",
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      "__reg_process_master_chan_list_ext",
      (unsigned int)v23);
    v28 = 0;
    goto LABEL_62;
  }
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: process reg master chan extended list",
    v52,
    v53,
    v54,
    v55,
    v56,
    v57,
    v58,
    v59,
    "__reg_process_master_chan_list_ext");
  v68 = *((unsigned int *)a1 + 2);
  if ( *(_BYTE *)(v12 + 91095) )
    v69 = 22;
  else
    v69 = 21;
  v285 = *(unsigned __int8 *)(v12 + 91095);
  v286 = v69;
  if ( !(_DWORD)v68 )
  {
    if ( (unsigned int)v23 <= 3 )
      goto LABEL_80;
    goto LABEL_304;
  }
  qdf_trace_msg(
    0x51u,
    2u,
    "%s: Set country code failed, status code %d",
    v60,
    v61,
    v62,
    v63,
    v64,
    v65,
    v66,
    v67,
    "reg_soc_vars_reset_on_failure",
    (unsigned int)v68);
  if ( (_DWORD)v68 != 1 )
    goto LABEL_11;
  if ( (unsigned int)v23 >= 3 )
    goto LABEL_304;
  v70 = (_BYTE *)(v12 + v23);
  v70[91128] = 0;
  v70[91134] = 0;
  v70[91137] = 1;
LABEL_80:
  v68 = v12 + 30364LL * (unsigned int)v23;
  v291[0] = v68 + 3684;
  qdf_mem_set((void *)(v68 + 3684), 0x870u, 0);
  v289 = v68 + 12324;
  qdf_mem_set((void *)(v68 + 12324), 0x870u, 0);
  v290[0] = v68 + 14484;
  qdf_mem_set((void *)(v68 + 14484), 0x870u, 0);
  v291[1] = v68 + 5844;
  qdf_mem_set((void *)(v68 + 5844), 0x870u, 0);
  v290[1] = v68 + 16644;
  qdf_mem_set((void *)(v68 + 16644), 0x870u, 0);
  v290[2] = v68 + 18804;
  qdf_mem_set((void *)(v68 + 18804), 0x870u, 0);
  v291[2] = v68 + 8004;
  qdf_mem_set((void *)(v68 + 8004), 0x870u, 0);
  v290[3] = v68 + 20964;
  qdf_mem_set((void *)(v68 + 20964), 0x870u, 0);
  v290[4] = v68 + 23124;
  qdf_mem_set((void *)(v68 + 23124), 0x870u, 0);
  v291[3] = v68 + 10164;
  qdf_mem_set((void *)(v68 + 10164), 0x870u, 0);
  v290[5] = v68 + 25284;
  qdf_mem_set((void *)(v68 + 25284), 0x870u, 0);
  v290[6] = v68 + 27444;
  qdf_mem_set((void *)(v68 + 27444), 0x870u, 0);
  reg_init_channel_map(*((unsigned int *)a1 + 6));
  v108 = 0;
  v109 = v68 + 16;
  v287 = (_BYTE *)v68;
  do
  {
    *(_BYTE *)(v109 - 4) = *(_BYTE *)(channel_map + v108 + 4);
    v110 = *(_DWORD *)(channel_map + v108);
    *(_QWORD *)v109 = 0x100000000LL;
    *(_DWORD *)(v109 - 8) = v110;
    if ( (*(_BYTE *)(v12 + 93256) & 1) == 0 )
      *(_BYTE *)(v109 + 17) = 0;
    v108 += 12;
    v109 += 36;
  }
  while ( v108 != 504 );
  for ( i = 0; i != 4; ++i )
  {
    v112 = 508;
    v113 = v291[i] + 12LL;
    do
    {
      *(_BYTE *)(v113 - 8) = *(_BYTE *)(channel_map + v112);
      v114 = *(_DWORD *)(channel_map + v112 - 4);
      *(_QWORD *)(v113 - 4) = 0x100000000LL;
      *(_DWORD *)(v113 - 12) = v114;
      if ( (*(_BYTE *)(v12 + 93256) & 1) == 0 )
        *(_BYTE *)(v113 + 13) = 0;
      v112 += 12;
      v113 += 36;
    }
    while ( v112 != 1228 );
    v115 = 508;
    v116 = v290[2 * i - 1] + 12;
    do
    {
      *(_BYTE *)(v116 - 8) = *(_BYTE *)(channel_map + v115);
      v117 = *(_DWORD *)(channel_map + v115 - 4);
      *(_QWORD *)(v116 - 4) = 0x100000000LL;
      *(_DWORD *)(v116 - 12) = v117;
      if ( (*(_BYTE *)(v12 + 93256) & 1) == 0 )
        *(_BYTE *)(v116 + 13) = 0;
      v115 += 12;
      v116 += 36;
    }
    while ( v115 != 1228 );
    v118 = 508;
    v119 = v290[2 * i] + 12;
    do
    {
      *(_BYTE *)(v119 - 8) = *(_BYTE *)(channel_map + v118);
      v120 = *(_DWORD *)(channel_map + v118 - 4);
      *(_QWORD *)(v119 - 4) = 0x100000000LL;
      *(_DWORD *)(v119 - 12) = v120;
      if ( (*(_BYTE *)(v12 + 93256) & 1) == 0 )
        *(_BYTE *)(v119 + 13) = 0;
      v118 += 12;
      v119 += 36;
    }
    while ( v118 != 1228 );
  }
  *(_BYTE *)(v12 + 91098) = *((_BYTE *)a1 + 12);
  if ( (unsigned int)v23 >= 3 )
    goto LABEL_304;
  *(_DWORD *)(v68 + 4) = *((_DWORD *)a1 + 7);
  *(_DWORD *)v68 = *((_DWORD *)a1 + 6);
  *(_WORD *)(v68 + 29622) = *((_WORD *)a1 + 8);
  *(_DWORD *)(v68 + 29616) = *((unsigned __int16 *)a1 + 7);
  *(_WORD *)(v68 + 29620) = *((_DWORD *)a1 + 25);
  *(_WORD *)(v68 + 30362) = *((_DWORD *)a1 + 11);
  qdf_mem_copy((void *)(v68 + 29607), (char *)a1 + 18, 3u);
  qdf_mem_copy((void *)(v12 + 91099), (char *)a1 + 18, 3u);
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: set cur_country %.2s",
    v121,
    v122,
    v123,
    v124,
    v125,
    v126,
    v127,
    v128,
    "reg_store_regulatory_ext_info_to_socpriv",
    v12 + 91099);
  *(_DWORD *)(v68 + 30344) = 0;
  *(_DWORD *)(v68 + 30348) = *((_DWORD *)a1 + 20);
  *(_BYTE *)(v68 + 30352) = *((_BYTE *)a1 + 84);
  *(_BYTE *)(v68 + 30353) = *((_BYTE *)a1 + 85);
  *(_DWORD *)(v68 + 30356) = *((_DWORD *)a1 + 14);
  *(_BYTE *)(v12 + 30364LL * (unsigned int)v23 + 30360) = *((_BYTE *)a1 + 372);
  v129 = *((_BYTE *)a1 + 86);
  *(_BYTE *)(v68 + 3680) = 1;
  *(_BYTE *)(v12 + 93257) = v129;
  qdf_mem_copy((void *)(v12 + 93261), (char *)a1 + 90, 2u);
  v130 = *((_BYTE *)a1 + 87);
  *(_BYTE *)(v68 + 3680) = 1;
  *(_BYTE *)(v12 + 93258) = v130;
  qdf_mem_copy((void *)(v12 + 93263), (char *)a1 + 92, 2u);
  v131 = *((_BYTE *)a1 + 88);
  *(_BYTE *)(v68 + 3680) = 1;
  *(_BYTE *)(v12 + 93259) = v131;
  qdf_mem_copy((void *)(v12 + 93265), (char *)a1 + 94, 2u);
  *(_BYTE *)(v12 + 93260) = *((_BYTE *)a1 + 89);
  *(_BYTE *)(v68 + 3680) = 1;
  qdf_mem_copy((void *)(v12 + 93267), a1 + 12, 2u);
  if ( *(_DWORD *)(v68 + 30348) >= 2u )
  {
    v26 = "%s: 6 GHz reg client type invalid";
    goto LABEL_9;
  }
  v132 = *((unsigned int *)a1 + 12);
  v133 = (_WORD *)a1[8];
  v279 = *(unsigned int *)(v68 + 30348);
  v272 = *((_DWORD *)a1 + 8);
  if ( (_DWORD)v132 )
  {
    v134 = *((_DWORD *)a1 + 9);
    if ( (_DWORD)v132 == 1 )
    {
      v135 = 0;
      v136 = 0;
      goto LABEL_120;
    }
    v136 = (unsigned int)v132 & 0xFFFFFFFE;
    v137 = 0;
    v138 = 0;
    v139 = v133 + 9;
    v140 = v136;
    do
    {
      v141 = (unsigned __int16)*(v139 - 7);
      v142 = (unsigned __int16)v134;
      if ( v141 >= (unsigned __int16)v134 )
        v141 = (unsigned __int16)v134;
      if ( (unsigned __int16)*v139 < (unsigned int)(unsigned __int16)v134 )
        v142 = (unsigned __int16)*v139;
      *(v139 - 7) = v141;
      if ( v137 <= v141 )
        v137 = v141;
      if ( v138 <= v142 )
        v138 = v142;
      v140 -= 2;
      *v139 = v142;
      v139 += 14;
    }
    while ( v140 );
    if ( v137 <= v138 )
      v135 = v138;
    else
      v135 = v137;
    if ( v136 != v132 )
    {
LABEL_120:
      v143 = &v133[7 * (unsigned int)v136];
      v144 = v132 - v136;
      v145 = v143 + 2;
      do
      {
        v146 = (unsigned __int16)*v145;
        if ( v146 >= (unsigned __int16)v134 )
          v146 = (unsigned __int16)v134;
        *v145 = v146;
        v145 += 7;
        if ( v135 <= v146 )
          v135 = v146;
        --v144;
      }
      while ( v144 );
    }
  }
  else
  {
    v135 = 0;
  }
  v147 = *((_DWORD *)a1 + 11);
  v148 = *((unsigned int *)a1 + 13);
  v149 = (_WORD *)a1[9];
  v271 = *((_DWORD *)a1 + 10);
  if ( (_DWORD)v148 )
  {
    if ( (_DWORD)v148 == 1 )
    {
      v150 = 0;
      goto LABEL_142;
    }
    v150 = (unsigned int)v148 & 0xFFFFFFFE;
    v151 = (_WORD *)a1[9];
    v152 = v149 + 9;
    v153 = v150;
    v154 = v135;
    do
    {
      v155 = (unsigned __int16)*(v152 - 7);
      v156 = (unsigned __int16)v147;
      if ( v155 >= (unsigned __int16)v147 )
        v155 = (unsigned __int16)v147;
      if ( (unsigned __int16)*v152 < (unsigned int)(unsigned __int16)v147 )
        v156 = (unsigned __int16)*v152;
      *(v152 - 7) = v155;
      if ( v135 <= v155 )
        v135 = v155;
      if ( v154 <= v156 )
        v154 = v156;
      v153 -= 2;
      *v152 = v156;
      v152 += 14;
    }
    while ( v153 );
    v149 = v151;
    if ( v135 <= v154 )
      v135 = v154;
    if ( v150 != v148 )
    {
LABEL_142:
      v157 = &v149[7 * (unsigned int)v150];
      v158 = v148 - v150;
      v159 = v157 + 2;
      do
      {
        v160 = (unsigned __int16)*v159;
        if ( v160 >= (unsigned __int16)v147 )
          v160 = (unsigned __int16)v147;
        *v159 = v160;
        v159 += 7;
        if ( v135 <= v160 )
          v135 = v160;
        --v158;
      }
      while ( v158 );
    }
  }
  v161 = (_WORD *)a1[31];
  v162 = *((unsigned int *)a1 + 50);
  v274 = v149;
  v293[0] = *((_DWORD *)a1 + 26);
  v163 = *((_DWORD *)a1 + 30);
  v281 = v161;
  v295[0] = v161;
  v300[0] = v162;
  if ( (_DWORD)v162 )
  {
    if ( (_DWORD)v162 == 1 )
    {
      v164 = 0;
      goto LABEL_164;
    }
    v164 = (unsigned int)v162 & 0xFFFFFFFE;
    v165 = v135;
    v166 = v164;
    v167 = v281 + 9;
    do
    {
      v168 = (unsigned __int16)*(v167 - 7);
      v169 = (unsigned __int16)v163;
      if ( v168 >= (unsigned __int16)v163 )
        v168 = (unsigned __int16)v163;
      if ( (unsigned __int16)*v167 < (unsigned int)(unsigned __int16)v163 )
        v169 = (unsigned __int16)*v167;
      *(v167 - 7) = v168;
      if ( v135 <= v168 )
        v135 = v168;
      if ( v165 <= v169 )
        v165 = v169;
      v166 -= 2;
      *v167 = v169;
      v167 += 14;
    }
    while ( v166 );
    if ( v135 <= v165 )
      v135 = v165;
    if ( v164 != v162 )
    {
LABEL_164:
      v170 = (char *)&v281[7 * (unsigned int)v164];
      v171 = v162 - v164;
      v172 = v170 + 4;
      do
      {
        v173 = (unsigned __int16)*v172;
        if ( v173 >= (unsigned __int16)v163 )
          v173 = (unsigned __int16)v163;
        *v172 = v173;
        v172 += 7;
        if ( v135 <= v173 )
          v135 = v173;
        --v171;
      }
      while ( v171 );
    }
  }
  v174 = (_WORD *)a1[32];
  v175 = *((unsigned int *)a1 + 51);
  v293[1] = *((_DWORD *)a1 + 27);
  v176 = *((_DWORD *)a1 + 31);
  v280 = v174;
  v295[1] = v174;
  v300[1] = v175;
  v278 = v175;
  if ( (_DWORD)v175 )
  {
    if ( (_DWORD)v175 == 1 )
    {
      v177 = 0;
      goto LABEL_186;
    }
    v177 = (unsigned int)v175 & 0xFFFFFFFE;
    v178 = v135;
    v179 = v177;
    v180 = v280 + 9;
    do
    {
      v181 = (unsigned __int16)*(v180 - 7);
      v182 = (unsigned __int16)v176;
      if ( v181 >= (unsigned __int16)v176 )
        v181 = (unsigned __int16)v176;
      if ( (unsigned __int16)*v180 < (unsigned int)(unsigned __int16)v176 )
        v182 = (unsigned __int16)*v180;
      *(v180 - 7) = v181;
      if ( v135 <= v181 )
        v135 = v181;
      if ( v178 <= v182 )
        v178 = v182;
      v179 -= 2;
      *v180 = v182;
      v180 += 14;
    }
    while ( v179 );
    if ( v135 <= v178 )
      v135 = v178;
    v175 = v278;
    if ( v177 != v278 )
    {
LABEL_186:
      v183 = (char *)&v280[7 * (unsigned int)v177];
      v184 = v175 - v177;
      v185 = v183 + 4;
      do
      {
        v186 = (unsigned __int16)*v185;
        if ( v186 >= (unsigned __int16)v176 )
          v186 = (unsigned __int16)v176;
        *v185 = v186;
        v185 += 7;
        if ( v135 <= v186 )
          v135 = v186;
        --v184;
      }
      while ( v184 );
    }
  }
  v187 = (_WORD *)a1[33];
  v188 = *((unsigned int *)a1 + 52);
  v293[2] = *((_DWORD *)a1 + 28);
  v189 = *((_DWORD *)a1 + 32);
  v295[2] = v187;
  v300[2] = v188;
  v277 = v188;
  if ( (_DWORD)v188 )
  {
    if ( (_DWORD)v188 == 1 )
    {
      v190 = 0;
      goto LABEL_208;
    }
    v190 = (unsigned int)v188 & 0xFFFFFFFE;
    v191 = v187;
    v192 = v187 + 9;
    v193 = v190;
    v194 = v135;
    do
    {
      v195 = (unsigned __int16)*(v192 - 7);
      v196 = (unsigned __int16)v189;
      if ( v195 >= (unsigned __int16)v189 )
        v195 = (unsigned __int16)v189;
      if ( (unsigned __int16)*v192 < (unsigned int)(unsigned __int16)v189 )
        v196 = (unsigned __int16)*v192;
      *(v192 - 7) = v195;
      if ( v135 <= v195 )
        v135 = v195;
      if ( v194 <= v196 )
        v194 = v196;
      v193 -= 2;
      *v192 = v196;
      v192 += 14;
    }
    while ( v193 );
    v188 = v277;
    v187 = v191;
    if ( v135 <= v194 )
      v135 = v194;
    if ( v190 != v277 )
    {
LABEL_208:
      v197 = &v187[7 * (unsigned int)v190];
      v198 = v188 - v190;
      v199 = v197 + 2;
      do
      {
        v200 = (unsigned __int16)*v199;
        if ( v200 >= (unsigned __int16)v189 )
          v200 = (unsigned __int16)v189;
        *v199 = v200;
        v199 += 7;
        if ( v135 <= v200 )
          v135 = v200;
        --v198;
      }
      while ( v198 );
    }
  }
  v201 = (_WORD *)a1[34];
  v202 = *((unsigned int *)a1 + 53);
  v269 = v187;
  v293[3] = *((_DWORD *)a1 + 29);
  v203 = *((_DWORD *)a1 + 33);
  v295[3] = v201;
  v300[3] = v202;
  v275 = v201;
  v276 = v202;
  if ( (_DWORD)v202 )
  {
    if ( (_DWORD)v202 == 1 )
    {
      v204 = 0;
      goto LABEL_230;
    }
    v204 = (unsigned int)v202 & 0xFFFFFFFE;
    v205 = v201 + 9;
    v206 = v135;
    v207 = v204;
    do
    {
      v208 = (unsigned __int16)*(v205 - 7);
      v209 = (unsigned __int16)v203;
      if ( v208 >= (unsigned __int16)v203 )
        v208 = (unsigned __int16)v203;
      if ( (unsigned __int16)*v205 < (unsigned int)(unsigned __int16)v203 )
        v209 = (unsigned __int16)*v205;
      *(v205 - 7) = v208;
      if ( v135 <= v208 )
        v135 = v208;
      if ( v206 <= v209 )
        v206 = v209;
      v207 -= 2;
      *v205 = v209;
      v205 += 14;
    }
    while ( v207 );
    if ( v135 <= v206 )
      v135 = v206;
    v201 = v275;
    v202 = v276;
    if ( v204 != v276 )
    {
LABEL_230:
      v210 = &v201[7 * (unsigned int)v204];
      v211 = v202 - v204;
      v212 = v210 + 2;
      do
      {
        v213 = (unsigned __int16)*v212;
        if ( v213 >= (unsigned __int16)v203 )
          v213 = (unsigned __int16)v203;
        *v212 = v213;
        v212 += 7;
        if ( v135 <= v213 )
          v135 = v213;
        --v211;
      }
      while ( v211 );
    }
  }
  v214 = 0;
  v282 = v162;
  v283 = v132;
  v284 = v148;
  v273 = v133;
  v298 = nullptr;
  v299 = nullptr;
  v296 = nullptr;
  v297 = nullptr;
  memset(v294, 0, sizeof(v294));
  memset(v292, 0, sizeof(v292));
  v270 = v147;
  while ( 2 )
  {
    v215 = v214;
    v216 = &v38[2 * v214];
    v292[v215] = &a1[v214 + 17];
    v217 = (__int64 *)&v37[4 * v214];
    v218 = *v216;
    v219 = &v36[2 * v214];
    *(_QWORD *)&v294[v215 * 8] = v217;
    (&v296)[v215] = v216;
    if ( (_DWORD)v218 )
    {
      v220 = *v217;
      v221 = *v219;
      if ( (_DWORD)v218 == 1 )
      {
        v222 = 0;
        goto LABEL_254;
      }
      v222 = (unsigned int)v218 & 0xFFFFFFFE;
      v223 = (_WORD *)(v220 + 18);
      v224 = v135;
      v225 = v222;
      do
      {
        v226 = (unsigned __int16)*(v223 - 7);
        v227 = (unsigned __int16)*v223;
        if ( v226 >= (unsigned __int16)v221 )
          v226 = (unsigned __int16)v221;
        if ( v227 >= (unsigned __int16)v221 )
          v227 = (unsigned __int16)v221;
        *(v223 - 7) = v226;
        if ( v135 <= v226 )
          v135 = v226;
        if ( v224 <= v227 )
          v224 = v227;
        v225 -= 2;
        *v223 = v227;
        v223 += 14;
      }
      while ( v225 );
      if ( v135 <= v224 )
        v135 = v224;
      if ( v222 != v218 )
      {
LABEL_254:
        v228 = v218 - v222;
        v229 = (_WORD *)(v220 + 14LL * (unsigned int)v222 + 4);
        do
        {
          v230 = (unsigned __int16)*v229;
          if ( v230 >= (unsigned __int16)v221 )
            v230 = (unsigned __int16)v221;
          *v229 = v230;
          v229 += 7;
          if ( v135 <= v230 )
            v135 = v230;
          --v228;
        }
        while ( v228 );
      }
    }
    v231 = v216[1];
    if ( (_DWORD)v231 )
    {
      v232 = v217[1];
      v233 = v219[1];
      if ( (_DWORD)v231 == 1 )
      {
        v234 = 0;
        goto LABEL_276;
      }
      v234 = (unsigned int)v231 & 0xFFFFFFFE;
      v235 = (_WORD *)(v232 + 18);
      v236 = v135;
      v237 = v234;
      do
      {
        v238 = (unsigned __int16)*(v235 - 7);
        v239 = (unsigned __int16)v233;
        if ( v238 >= (unsigned __int16)v233 )
          v238 = (unsigned __int16)v233;
        if ( (unsigned __int16)*v235 < (unsigned int)(unsigned __int16)v233 )
          v239 = (unsigned __int16)*v235;
        *(v235 - 7) = v238;
        if ( v135 <= v238 )
          v135 = v238;
        if ( v236 <= v239 )
          v236 = v239;
        v237 -= 2;
        *v235 = v239;
        v235 += 14;
      }
      while ( v237 );
      if ( v135 <= v236 )
        v135 = v236;
      if ( v234 != v231 )
      {
LABEL_276:
        v240 = v232 + 14LL * (unsigned int)v234;
        v241 = v231 - v234;
        v242 = (_WORD *)(v240 + 4);
        do
        {
          v243 = (unsigned __int16)*v242;
          if ( v243 >= (unsigned __int16)v233 )
            v243 = (unsigned __int16)v233;
          *v242 = v243;
          v242 += 7;
          if ( v135 <= v243 )
            v135 = v243;
          --v241;
        }
        while ( v241 );
      }
    }
    if ( ++v214 != 4 )
      continue;
    break;
  }
  *(_DWORD *)(v12 + 93972) = v135;
  qdf_trace_msg(
    0x51u,
    8u,
    "%s: max_allowed_bw as per current reg rules: %d",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "reg_fill_master_channels");
  qdf_mem_set(v287 + 29624, 0x2D0u, 0);
  v287[29774] = v282;
  v287[29632] = v284 + v283;
  if ( v282 > 5 )
    goto LABEL_284;
  v37 = v296;
  v287[30058] = v296[v279];
  if ( *v37 > 5u || v37[1] > 5u )
  {
LABEL_287:
    v26 = "%s: number of reg rules for 6g client exceeds limit";
    goto LABEL_288;
  }
  v287[29775] = v278;
  if ( (unsigned int)v278 > 5 )
    goto LABEL_284;
  v36 = v297;
  v35 = v294;
  v287[30059] = v297[v279];
  if ( *v36 > 5u || v36[1] > 5u )
    goto LABEL_287;
  v68 = v279;
  v287[29776] = v277;
  if ( (unsigned int)v277 > 5 )
    goto LABEL_284;
  v38 = v298;
  v287[30060] = v298[v279];
  if ( *v38 > 5u || v38[1] > 5u )
    goto LABEL_287;
  v287[29777] = v276;
  if ( (unsigned int)v276 > 5 )
  {
LABEL_284:
    v26 = "%s: number of reg rules for 6g ap exceeds limit";
    goto LABEL_288;
  }
  v244 = v299;
  v268 = v299;
  v287[30061] = v299[v279];
  if ( *v244 > 5u || v268[1] > 5u )
    goto LABEL_287;
  if ( (unsigned __int8)(v284 + v283) <= 0xAu )
  {
    if ( !((_BYTE)v284 + (_BYTE)v283) )
      goto LABEL_307;
    if ( !(_DWORD)v283 )
    {
LABEL_305:
      if ( (_DWORD)v284 )
        goto LABEL_306;
LABEL_307:
      if ( v282 )
        qdf_mem_copy(v287 + 29778, v281, 14 * v282);
      v245 = v37[v68];
      if ( v245 )
        qdf_mem_copy(v287 + 30062, *(const void **)(*v35 + 8 * v68), (unsigned int)(14 * v245));
      if ( (_DWORD)v278 )
        qdf_mem_copy(v287 + 29848, v280, (unsigned int)(14 * v278));
      v246 = v36[v68];
      if ( v246 )
        qdf_mem_copy(v287 + 30132, *(const void **)(v35[1] + 8 * v68), (unsigned int)(14 * v246));
      if ( (_DWORD)v277 )
        qdf_mem_copy(v287 + 29918, v269, (unsigned int)(14 * v277));
      v247 = v38[v68];
      if ( v247 )
        qdf_mem_copy(v287 + 30202, *(const void **)(v35[2] + 8 * v68), (unsigned int)(14 * v247));
      if ( (_DWORD)v276 )
        qdf_mem_copy(v287 + 29988, v275, (unsigned int)(14 * v276));
      v248 = v268[v68];
      if ( v248 )
        qdf_mem_copy(v287 + 30272, *(const void **)(v35[3] + 8 * v68), (unsigned int)(14 * v248));
      if ( (_DWORD)v284 )
        reg_do_auto_bw_correction(v284, v274, v270);
      if ( (_DWORD)v283 )
        reg_populate_band_channels(0, 13, v273, v283, v272, v287 + 8);
      if ( (_DWORD)v284 )
        reg_populate_band_channels(14, 41, v274, v284, v271, v287 + 8);
      v249 = 0;
      v250 = v290;
      do
      {
        v251 = (unsigned int)v300[v249];
        if ( (_DWORD)v251 )
          reg_populate_band_channels_ext_for_6g(v295[v249], v251, (unsigned int)v293[v249], v291[v249]);
        v252 = (&v296)[v249];
        v253 = *v252;
        if ( (_DWORD)v253 )
          reg_populate_band_channels_ext_for_6g(
            **(_QWORD **)&v294[8 * v249],
            v253,
            *(unsigned int *)v292[v249],
            *(v250 - 1));
        v254 = v252[1];
        if ( (_DWORD)v254 )
          reg_populate_band_channels_ext_for_6g(
            *(_QWORD *)(*(_QWORD *)&v294[8 * v249] + 8LL),
            v254,
            *(unsigned int *)(v292[v249] + 4LL),
            *v250);
        ++v249;
        v250 += 2;
      }
      while ( v249 != 4 );
      v28 = reg_send_ctl_info(v12, a1, v24);
      if ( !v28 )
      {
        reg_set_socpriv_vars(v12, a1, v2, (unsigned int)v23);
        v255 = *((_DWORD *)a1 + 88);
        if ( v255 )
          qdf_mem_copy((void *)(v12 + 93960), (const void *)a1[43], (unsigned int)(4 * v255));
        pdev_by_id = wlan_objmgr_get_pdev_by_id(v2, v288[0], v286);
        if ( pdev_by_id )
        {
          v257 = pdev_by_id;
          v258 = reg_propagate_mas_chan_list_and_fill_legacy_list(v2, pdev_by_id, v285 ^ 1u);
          v28 = v259;
          wlan_objmgr_pdev_release_ref(v257, v286, v260, v258, v261, v262, v263, v264, v265, v266, v267);
        }
        else
        {
          v28 = 0;
        }
      }
      goto LABEL_62;
    }
    qdf_mem_copy(v287 + 29634, v273, (unsigned int)(14 * v283));
    if ( !(_DWORD)v284 )
      goto LABEL_307;
    if ( (unsigned int)v283 <= 0xA )
    {
LABEL_306:
      qdf_mem_copy(&v287[14 * (unsigned int)v283 + 29634], v274, (unsigned int)(14 * v284));
      goto LABEL_307;
    }
LABEL_304:
    __break(0x5512u);
    goto LABEL_305;
  }
  v26 = "%s: number of reg rules exceeds limit";
LABEL_288:
  v27 = "reg_fill_master_channels";
LABEL_10:
  qdf_trace_msg(0x51u, 2u, v26, v4, v5, v6, v7, v8, v9, v10, v11, v27);
LABEL_11:
  v28 = 16;
LABEL_62:
  v80 = *a1;
  v81 = reg_get_psoc_tx_ops(*a1);
  if ( !v81 )
    goto LABEL_77;
  if ( !*(_QWORD *)(v81 + 32) )
    goto LABEL_78;
  v82 = *(void (__fastcall **)(__int64, __int64, __int64 *))(v81 + 136);
  v83 = *((unsigned __int8 *)a1 + 13);
  v84 = v81;
  v85 = *((unsigned __int8 *)a1 + 21);
  LOBYTE(v289) = 0;
  if ( v82 )
  {
    if ( *((_DWORD *)v82 - 1) != 13449260 )
      __break(0x8228u);
    v82(v80, v83, &v289);
    LOBYTE(v83) = v289;
  }
  else
  {
    LOBYTE(v289) = v83;
  }
  if ( v85 )
    v86 = 22;
  else
    v86 = 21;
  v87 = wlan_objmgr_get_pdev_by_id(v80, v83, v86);
  if ( !v87 )
  {
    qdf_trace_msg(
      0x51u,
      2u,
      "%s: pdev obj is NULL",
      v88,
      v89,
      v90,
      v91,
      v92,
      v93,
      v94,
      v95,
      "reg_process_master_chan_list_ext");
LABEL_77:
    v28 = 16;
    goto LABEL_78;
  }
  v96 = *(double (**)(void))(v84 + 32);
  v97 = v87;
  if ( *((_DWORD *)v96 - 1) != -1127411852 )
    __break(0x8228u);
  v98 = v96();
  wlan_objmgr_pdev_release_ref(v97, v86, v99, v98, v100, v101, v102, v103, v104, v105, v106);
LABEL_78:
  _ReadStatusReg(SP_EL0);
  return v28;
}
