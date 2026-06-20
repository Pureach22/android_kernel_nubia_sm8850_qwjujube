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
  unsigned int v147; // w15
  __int64 v148; // x16
  _WORD *v149; // x10
  __int64 v150; // x8
  _WORD *v151; // x9
  unsigned int v152; // w11
  __int64 v153; // x10
  unsigned int v154; // w12
  unsigned int v155; // w13
  _WORD *v156; // x9
  __int64 v157; // x8
  _WORD *v158; // x9
  unsigned int v159; // w10
  _WORD *v160; // x9
  __int64 v161; // x1
  int v162; // w8
  __int64 v163; // x9
  unsigned int v164; // w12
  __int64 v165; // x11
  _WORD *v166; // x10
  unsigned int v167; // w13
  unsigned int v168; // w14
  char *v169; // x10
  __int64 v170; // x9
  _WORD *v171; // x10
  unsigned int v172; // w11
  _WORD *v173; // x9
  __int64 v174; // x12
  int v175; // w8
  __int64 v176; // x9
  unsigned int v177; // w12
  __int64 v178; // x11
  _WORD *v179; // x10
  unsigned int v180; // w13
  unsigned int v181; // w14
  char *v182; // x10
  __int64 v183; // x9
  _WORD *v184; // x10
  unsigned int v185; // w11
  _WORD *v186; // x13
  __int64 v187; // x11
  int v188; // w8
  __int64 v189; // x9
  _WORD *v190; // x2
  _WORD *v191; // x10
  __int64 v192; // x11
  unsigned int v193; // w12
  unsigned int v194; // w13
  unsigned int v195; // w14
  _WORD *v196; // x10
  __int64 v197; // x9
  _WORD *v198; // x10
  unsigned int v199; // w11
  _WORD *v200; // x11
  __int64 v201; // x12
  int v202; // w8
  __int64 v203; // x9
  _WORD *v204; // x10
  unsigned int v205; // w12
  __int64 v206; // x11
  unsigned int v207; // w13
  unsigned int v208; // w14
  _WORD *v209; // x10
  __int64 v210; // x9
  _WORD *v211; // x10
  unsigned int v212; // w11
  unsigned __int64 v213; // x8
  unsigned __int64 v214; // x17
  unsigned int *v215; // x16
  __int64 *v216; // x14
  __int64 v217; // x0
  int *v218; // x15
  __int64 v219; // x1
  int v220; // w17
  __int64 v221; // x2
  _WORD *v222; // x3
  unsigned int v223; // w6
  __int64 v224; // x5
  unsigned int v225; // w7
  unsigned int v226; // w24
  __int64 v227; // x0
  _WORD *v228; // x1
  unsigned int v229; // w2
  __int64 v230; // x16
  __int64 v231; // x17
  int v232; // w14
  __int64 v233; // x15
  _WORD *v234; // x0
  unsigned int v235; // w2
  __int64 v236; // x1
  unsigned int v237; // w3
  unsigned int v238; // w5
  __int64 v239; // x17
  __int64 v240; // x15
  _WORD *v241; // x16
  unsigned int v242; // w17
  _DWORD *v243; // x12
  int v244; // w8
  int v245; // w8
  int v246; // w8
  int v247; // w8
  __int64 v248; // x24
  _QWORD *v249; // x28
  __int64 v250; // x1
  unsigned int *v251; // x26
  __int64 v252; // x1
  __int64 v253; // x1
  int v254; // w8
  __int64 pdev_by_id; // x0
  __int64 v256; // x21
  double v257; // d0
  unsigned int v258; // w0
  unsigned int *v259; // x8
  double v260; // d1
  double v261; // d2
  double v262; // d3
  double v263; // d4
  double v264; // d5
  double v265; // d6
  double v266; // d7
  _DWORD *v267; // [xsp+8h] [xbp-1A8h]
  const void *v268; // [xsp+10h] [xbp-1A0h]
  unsigned int v269; // [xsp+1Ch] [xbp-194h]
  unsigned int v270; // [xsp+20h] [xbp-190h]
  unsigned int v271; // [xsp+24h] [xbp-18Ch]
  const void *v272; // [xsp+28h] [xbp-188h]
  _WORD *v273; // [xsp+30h] [xbp-180h]
  _WORD *v274; // [xsp+38h] [xbp-178h]
  __int64 v275; // [xsp+40h] [xbp-170h]
  __int64 v276; // [xsp+48h] [xbp-168h]
  __int64 v277; // [xsp+50h] [xbp-160h]
  __int64 v278; // [xsp+58h] [xbp-158h]
  _WORD *v279; // [xsp+60h] [xbp-150h]
  _WORD *v280; // [xsp+68h] [xbp-148h]
  unsigned int v281; // [xsp+70h] [xbp-140h]
  __int64 v282; // [xsp+78h] [xbp-138h]
  __int64 v283; // [xsp+80h] [xbp-130h]
  int v284; // [xsp+88h] [xbp-128h]
  unsigned int v285; // [xsp+8Ch] [xbp-124h]
  _BYTE *v286; // [xsp+90h] [xbp-120h]
  char v287[4]; // [xsp+9Ch] [xbp-114h] BYREF
  __int64 v288; // [xsp+A0h] [xbp-110h] BYREF
  _QWORD v289[7]; // [xsp+A8h] [xbp-108h] BYREF
  _QWORD v290[4]; // [xsp+E0h] [xbp-D0h]
  _QWORD v291[4]; // [xsp+100h] [xbp-B0h] BYREF
  _DWORD v292[4]; // [xsp+120h] [xbp-90h]
  _BYTE v293[32]; // [xsp+130h] [xbp-80h] BYREF
  _QWORD v294[4]; // [xsp+150h] [xbp-60h]
  _DWORD *v295; // [xsp+170h] [xbp-40h]
  _DWORD *v296; // [xsp+178h] [xbp-38h]
  _DWORD *v297; // [xsp+180h] [xbp-30h]
  _DWORD *v298; // [xsp+188h] [xbp-28h]
  _DWORD v299[4]; // [xsp+190h] [xbp-20h]
  __int64 v300; // [xsp+1A0h] [xbp-10h]

  v300 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v287[0] = 0;
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
    ((void (__fastcall *)(__int64, _QWORD, char *))v22)(v2, (unsigned int)v23, v287);
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
  v287[0] = *((_BYTE *)a1 + 13);
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
  v284 = *(unsigned __int8 *)(v12 + 91095);
  v285 = v69;
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
  v290[0] = v68 + 3684;
  qdf_mem_set((void *)(v68 + 3684), 0x870u, 0);
  v288 = v68 + 12324;
  qdf_mem_set((void *)(v68 + 12324), 0x870u, 0);
  v289[0] = v68 + 14484;
  qdf_mem_set((void *)(v68 + 14484), 0x870u, 0);
  v290[1] = v68 + 5844;
  qdf_mem_set((void *)(v68 + 5844), 0x870u, 0);
  v289[1] = v68 + 16644;
  qdf_mem_set((void *)(v68 + 16644), 0x870u, 0);
  v289[2] = v68 + 18804;
  qdf_mem_set((void *)(v68 + 18804), 0x870u, 0);
  v290[2] = v68 + 8004;
  qdf_mem_set((void *)(v68 + 8004), 0x870u, 0);
  v289[3] = v68 + 20964;
  qdf_mem_set((void *)(v68 + 20964), 0x870u, 0);
  v289[4] = v68 + 23124;
  qdf_mem_set((void *)(v68 + 23124), 0x870u, 0);
  v290[3] = v68 + 10164;
  qdf_mem_set((void *)(v68 + 10164), 0x870u, 0);
  v289[5] = v68 + 25284;
  qdf_mem_set((void *)(v68 + 25284), 0x870u, 0);
  v289[6] = v68 + 27444;
  qdf_mem_set((void *)(v68 + 27444), 0x870u, 0);
  reg_init_channel_map(*((unsigned int *)a1 + 6));
  v108 = 0;
  v109 = v68 + 16;
  v286 = (_BYTE *)v68;
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
    v113 = v290[i] + 12LL;
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
    v116 = v289[2 * i - 1] + 12;
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
    v119 = v289[2 * i] + 12;
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
  v278 = *(unsigned int *)(v68 + 30348);
  v271 = *((_DWORD *)a1 + 8);
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
  v274 = v149;
  v270 = *((_DWORD *)a1 + 10);
  if ( (_DWORD)v148 )
  {
    if ( (_DWORD)v148 == 1 )
    {
      v150 = 0;
      goto LABEL_142;
    }
    v150 = (unsigned int)v148 & 0xFFFFFFFE;
    v151 = v149 + 9;
    v152 = v135;
    v153 = v150;
    do
    {
      v154 = (unsigned __int16)*(v151 - 7);
      v155 = (unsigned __int16)v147;
      if ( v154 >= (unsigned __int16)v147 )
        v154 = (unsigned __int16)v147;
      if ( (unsigned __int16)*v151 < (unsigned int)(unsigned __int16)v147 )
        v155 = (unsigned __int16)*v151;
      *(v151 - 7) = v154;
      if ( v135 <= v154 )
        v135 = v154;
      if ( v152 <= v155 )
        v152 = v155;
      v153 -= 2;
      *v151 = v155;
      v151 += 14;
    }
    while ( v153 );
    v149 = v274;
    if ( v135 <= v152 )
      v135 = v152;
    if ( v150 != v148 )
    {
LABEL_142:
      v156 = &v149[7 * (unsigned int)v150];
      v157 = v148 - v150;
      v158 = v156 + 2;
      do
      {
        v159 = (unsigned __int16)*v158;
        if ( v159 >= (unsigned __int16)v147 )
          v159 = (unsigned __int16)v147;
        *v158 = v159;
        v158 += 7;
        if ( v135 <= v159 )
          v135 = v159;
        --v157;
      }
      while ( v157 );
    }
  }
  v160 = (_WORD *)a1[31];
  v161 = *((unsigned int *)a1 + 50);
  v269 = v147;
  v292[0] = *((_DWORD *)a1 + 26);
  v162 = *((_DWORD *)a1 + 30);
  v280 = v160;
  v294[0] = v160;
  v299[0] = v161;
  if ( (_DWORD)v161 )
  {
    if ( (_DWORD)v161 == 1 )
    {
      v163 = 0;
      goto LABEL_164;
    }
    v163 = (unsigned int)v161 & 0xFFFFFFFE;
    v164 = v135;
    v165 = v163;
    v166 = v280 + 9;
    do
    {
      v167 = (unsigned __int16)*(v166 - 7);
      v168 = (unsigned __int16)v162;
      if ( v167 >= (unsigned __int16)v162 )
        v167 = (unsigned __int16)v162;
      if ( (unsigned __int16)*v166 < (unsigned int)(unsigned __int16)v162 )
        v168 = (unsigned __int16)*v166;
      *(v166 - 7) = v167;
      if ( v135 <= v167 )
        v135 = v167;
      if ( v164 <= v168 )
        v164 = v168;
      v165 -= 2;
      *v166 = v168;
      v166 += 14;
    }
    while ( v165 );
    if ( v135 <= v164 )
      v135 = v164;
    if ( v163 != v161 )
    {
LABEL_164:
      v169 = (char *)&v280[7 * (unsigned int)v163];
      v170 = v161 - v163;
      v171 = v169 + 4;
      do
      {
        v172 = (unsigned __int16)*v171;
        if ( v172 >= (unsigned __int16)v162 )
          v172 = (unsigned __int16)v162;
        *v171 = v172;
        v171 += 7;
        if ( v135 <= v172 )
          v135 = v172;
        --v170;
      }
      while ( v170 );
    }
  }
  v173 = (_WORD *)a1[32];
  v174 = *((unsigned int *)a1 + 51);
  v292[1] = *((_DWORD *)a1 + 27);
  v175 = *((_DWORD *)a1 + 31);
  v279 = v173;
  v294[1] = v173;
  v299[1] = v174;
  v277 = v174;
  if ( (_DWORD)v174 )
  {
    if ( (_DWORD)v174 == 1 )
    {
      v176 = 0;
      goto LABEL_186;
    }
    v176 = (unsigned int)v174 & 0xFFFFFFFE;
    v177 = v135;
    v178 = v176;
    v179 = v279 + 9;
    do
    {
      v180 = (unsigned __int16)*(v179 - 7);
      v181 = (unsigned __int16)v175;
      if ( v180 >= (unsigned __int16)v175 )
        v180 = (unsigned __int16)v175;
      if ( (unsigned __int16)*v179 < (unsigned int)(unsigned __int16)v175 )
        v181 = (unsigned __int16)*v179;
      *(v179 - 7) = v180;
      if ( v135 <= v180 )
        v135 = v180;
      if ( v177 <= v181 )
        v177 = v181;
      v178 -= 2;
      *v179 = v181;
      v179 += 14;
    }
    while ( v178 );
    if ( v135 <= v177 )
      v135 = v177;
    v174 = v277;
    if ( v176 != v277 )
    {
LABEL_186:
      v182 = (char *)&v279[7 * (unsigned int)v176];
      v183 = v174 - v176;
      v184 = v182 + 4;
      do
      {
        v185 = (unsigned __int16)*v184;
        if ( v185 >= (unsigned __int16)v175 )
          v185 = (unsigned __int16)v175;
        *v184 = v185;
        v184 += 7;
        if ( v135 <= v185 )
          v135 = v185;
        --v183;
      }
      while ( v183 );
    }
  }
  v186 = (_WORD *)a1[33];
  v187 = *((unsigned int *)a1 + 52);
  v292[2] = *((_DWORD *)a1 + 28);
  v188 = *((_DWORD *)a1 + 32);
  v294[2] = v186;
  v299[2] = v187;
  v276 = v187;
  if ( (_DWORD)v187 )
  {
    if ( (_DWORD)v187 == 1 )
    {
      v189 = 0;
      goto LABEL_208;
    }
    v189 = (unsigned int)v187 & 0xFFFFFFFE;
    v190 = v186;
    v191 = v186 + 9;
    v192 = v189;
    v193 = v135;
    do
    {
      v194 = (unsigned __int16)*(v191 - 7);
      v195 = (unsigned __int16)v188;
      if ( v194 >= (unsigned __int16)v188 )
        v194 = (unsigned __int16)v188;
      if ( (unsigned __int16)*v191 < (unsigned int)(unsigned __int16)v188 )
        v195 = (unsigned __int16)*v191;
      *(v191 - 7) = v194;
      if ( v135 <= v194 )
        v135 = v194;
      if ( v193 <= v195 )
        v193 = v195;
      v192 -= 2;
      *v191 = v195;
      v191 += 14;
    }
    while ( v192 );
    v187 = v276;
    v186 = v190;
    if ( v135 <= v193 )
      v135 = v193;
    if ( v189 != v276 )
    {
LABEL_208:
      v196 = &v186[7 * (unsigned int)v189];
      v197 = v187 - v189;
      v198 = v196 + 2;
      do
      {
        v199 = (unsigned __int16)*v198;
        if ( v199 >= (unsigned __int16)v188 )
          v199 = (unsigned __int16)v188;
        *v198 = v199;
        v198 += 7;
        if ( v135 <= v199 )
          v135 = v199;
        --v197;
      }
      while ( v197 );
    }
  }
  v200 = (_WORD *)a1[34];
  v201 = *((unsigned int *)a1 + 53);
  v268 = v186;
  v292[3] = *((_DWORD *)a1 + 29);
  v202 = *((_DWORD *)a1 + 33);
  v294[3] = v200;
  v299[3] = v201;
  v273 = v200;
  v275 = v201;
  if ( (_DWORD)v201 )
  {
    if ( (_DWORD)v201 == 1 )
    {
      v203 = 0;
      goto LABEL_230;
    }
    v203 = (unsigned int)v201 & 0xFFFFFFFE;
    v204 = v200 + 9;
    v205 = v135;
    v206 = v203;
    do
    {
      v207 = (unsigned __int16)*(v204 - 7);
      v208 = (unsigned __int16)v202;
      if ( v207 >= (unsigned __int16)v202 )
        v207 = (unsigned __int16)v202;
      if ( (unsigned __int16)*v204 < (unsigned int)(unsigned __int16)v202 )
        v208 = (unsigned __int16)*v204;
      *(v204 - 7) = v207;
      if ( v135 <= v207 )
        v135 = v207;
      if ( v205 <= v208 )
        v205 = v208;
      v206 -= 2;
      *v204 = v208;
      v204 += 14;
    }
    while ( v206 );
    v200 = v273;
    if ( v135 <= v205 )
      v135 = v205;
    v201 = v275;
    if ( v203 != v275 )
    {
LABEL_230:
      v209 = &v200[7 * (unsigned int)v203];
      v210 = v201 - v203;
      v211 = v209 + 2;
      do
      {
        v212 = (unsigned __int16)*v211;
        if ( v212 >= (unsigned __int16)v202 )
          v212 = (unsigned __int16)v202;
        *v211 = v212;
        v211 += 7;
        if ( v135 <= v212 )
          v135 = v212;
        --v210;
      }
      while ( v210 );
    }
  }
  v213 = 0;
  v281 = v161;
  v282 = v132;
  v283 = v148;
  v272 = v133;
  v297 = nullptr;
  v298 = nullptr;
  v295 = nullptr;
  v296 = nullptr;
  memset(v293, 0, sizeof(v293));
  memset(v291, 0, sizeof(v291));
  while ( 2 )
  {
    v214 = v213;
    v215 = &v38[2 * v213];
    v291[v214] = &a1[v213 + 17];
    v216 = (__int64 *)&v37[4 * v213];
    v217 = *v215;
    v218 = &v36[2 * v213];
    *(_QWORD *)&v293[v214 * 8] = v216;
    (&v295)[v214] = v215;
    if ( (_DWORD)v217 )
    {
      v219 = *v216;
      v220 = *v218;
      if ( (_DWORD)v217 == 1 )
      {
        v221 = 0;
        goto LABEL_254;
      }
      v221 = (unsigned int)v217 & 0xFFFFFFFE;
      v222 = (_WORD *)(v219 + 18);
      v223 = v135;
      v224 = v221;
      do
      {
        v225 = (unsigned __int16)*(v222 - 7);
        v226 = (unsigned __int16)*v222;
        if ( v225 >= (unsigned __int16)v220 )
          v225 = (unsigned __int16)v220;
        if ( v226 >= (unsigned __int16)v220 )
          v226 = (unsigned __int16)v220;
        *(v222 - 7) = v225;
        if ( v135 <= v225 )
          v135 = v225;
        if ( v223 <= v226 )
          v223 = v226;
        v224 -= 2;
        *v222 = v226;
        v222 += 14;
      }
      while ( v224 );
      if ( v135 <= v223 )
        v135 = v223;
      if ( v221 != v217 )
      {
LABEL_254:
        v227 = v217 - v221;
        v228 = (_WORD *)(v219 + 14LL * (unsigned int)v221 + 4);
        do
        {
          v229 = (unsigned __int16)*v228;
          if ( v229 >= (unsigned __int16)v220 )
            v229 = (unsigned __int16)v220;
          *v228 = v229;
          v228 += 7;
          if ( v135 <= v229 )
            v135 = v229;
          --v227;
        }
        while ( v227 );
      }
    }
    v230 = v215[1];
    if ( (_DWORD)v230 )
    {
      v231 = v216[1];
      v232 = v218[1];
      if ( (_DWORD)v230 == 1 )
      {
        v233 = 0;
        goto LABEL_276;
      }
      v233 = (unsigned int)v230 & 0xFFFFFFFE;
      v234 = (_WORD *)(v231 + 18);
      v235 = v135;
      v236 = v233;
      do
      {
        v237 = (unsigned __int16)*(v234 - 7);
        v238 = (unsigned __int16)v232;
        if ( v237 >= (unsigned __int16)v232 )
          v237 = (unsigned __int16)v232;
        if ( (unsigned __int16)*v234 < (unsigned int)(unsigned __int16)v232 )
          v238 = (unsigned __int16)*v234;
        *(v234 - 7) = v237;
        if ( v135 <= v237 )
          v135 = v237;
        if ( v235 <= v238 )
          v235 = v238;
        v236 -= 2;
        *v234 = v238;
        v234 += 14;
      }
      while ( v236 );
      if ( v135 <= v235 )
        v135 = v235;
      if ( v233 != v230 )
      {
LABEL_276:
        v239 = v231 + 14LL * (unsigned int)v233;
        v240 = v230 - v233;
        v241 = (_WORD *)(v239 + 4);
        do
        {
          v242 = (unsigned __int16)*v241;
          if ( v242 >= (unsigned __int16)v232 )
            v242 = (unsigned __int16)v232;
          *v241 = v242;
          v241 += 7;
          if ( v135 <= v242 )
            v135 = v242;
          --v240;
        }
        while ( v240 );
      }
    }
    if ( ++v213 != 4 )
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
  qdf_mem_set(v286 + 29624, 0x2D0u, 0);
  v286[29774] = v281;
  v286[29632] = v283 + v282;
  if ( v281 > 5 )
    goto LABEL_284;
  v37 = v295;
  v286[30058] = v295[v278];
  if ( *v37 > 5u || v37[1] > 5u )
  {
LABEL_287:
    v26 = "%s: number of reg rules for 6g client exceeds limit";
    goto LABEL_288;
  }
  v286[29775] = v277;
  if ( (unsigned int)v277 > 5 )
    goto LABEL_284;
  v36 = v296;
  v35 = v293;
  v286[30059] = v296[v278];
  if ( *v36 > 5u || v36[1] > 5u )
    goto LABEL_287;
  v68 = v278;
  v286[29776] = v276;
  if ( (unsigned int)v276 > 5 )
    goto LABEL_284;
  v38 = v297;
  v286[30060] = v297[v278];
  if ( *v38 > 5u || v38[1] > 5u )
    goto LABEL_287;
  v286[29777] = v275;
  if ( (unsigned int)v275 > 5 )
  {
LABEL_284:
    v26 = "%s: number of reg rules for 6g ap exceeds limit";
    goto LABEL_288;
  }
  v243 = v298;
  v267 = v298;
  v286[30061] = v298[v278];
  if ( *v243 > 5u || v267[1] > 5u )
    goto LABEL_287;
  if ( (unsigned __int8)(v283 + v282) <= 0xAu )
  {
    if ( !((_BYTE)v283 + (_BYTE)v282) )
      goto LABEL_307;
    if ( !(_DWORD)v282 )
    {
LABEL_305:
      if ( (_DWORD)v283 )
        goto LABEL_306;
LABEL_307:
      if ( v281 )
        qdf_mem_copy(v286 + 29778, v280, 14 * v281);
      v244 = v37[v68];
      if ( v244 )
        qdf_mem_copy(v286 + 30062, *(const void **)(*v35 + 8 * v68), (unsigned int)(14 * v244));
      if ( (_DWORD)v277 )
        qdf_mem_copy(v286 + 29848, v279, (unsigned int)(14 * v277));
      v245 = v36[v68];
      if ( v245 )
        qdf_mem_copy(v286 + 30132, *(const void **)(v35[1] + 8 * v68), (unsigned int)(14 * v245));
      if ( (_DWORD)v276 )
        qdf_mem_copy(v286 + 29918, v268, (unsigned int)(14 * v276));
      v246 = v38[v68];
      if ( v246 )
        qdf_mem_copy(v286 + 30202, *(const void **)(v35[2] + 8 * v68), (unsigned int)(14 * v246));
      if ( (_DWORD)v275 )
        qdf_mem_copy(v286 + 29988, v273, (unsigned int)(14 * v275));
      v247 = v267[v68];
      if ( v247 )
        qdf_mem_copy(v286 + 30272, *(const void **)(v35[3] + 8 * v68), (unsigned int)(14 * v247));
      if ( (_DWORD)v283 )
        reg_do_auto_bw_correction(v283, v274, v269);
      if ( (_DWORD)v282 )
        reg_populate_band_channels(0, 13, v272, v282, v271, v286 + 8);
      if ( (_DWORD)v283 )
        reg_populate_band_channels(14, 41, v274, v283, v270, v286 + 8);
      v248 = 0;
      v249 = v289;
      do
      {
        v250 = (unsigned int)v299[v248];
        if ( (_DWORD)v250 )
          reg_populate_band_channels_ext_for_6g(v294[v248], v250, (unsigned int)v292[v248], v290[v248]);
        v251 = (&v295)[v248];
        v252 = *v251;
        if ( (_DWORD)v252 )
          reg_populate_band_channels_ext_for_6g(
            **(_QWORD **)&v293[8 * v248],
            v252,
            *(unsigned int *)v291[v248],
            *(v249 - 1));
        v253 = v251[1];
        if ( (_DWORD)v253 )
          reg_populate_band_channels_ext_for_6g(
            *(_QWORD *)(*(_QWORD *)&v293[8 * v248] + 8LL),
            v253,
            *(unsigned int *)(v291[v248] + 4LL),
            *v249);
        ++v248;
        v249 += 2;
      }
      while ( v248 != 4 );
      v28 = reg_send_ctl_info(v12, a1, v24);
      if ( !v28 )
      {
        reg_set_socpriv_vars(v12, a1, v2, (unsigned int)v23);
        v254 = *((_DWORD *)a1 + 88);
        if ( v254 )
          qdf_mem_copy((void *)(v12 + 93960), (const void *)a1[43], (unsigned int)(4 * v254));
        pdev_by_id = wlan_objmgr_get_pdev_by_id(v2, v287[0], v285);
        if ( pdev_by_id )
        {
          v256 = pdev_by_id;
          v257 = reg_propagate_mas_chan_list_and_fill_legacy_list(v2, pdev_by_id, v284 ^ 1u);
          v28 = v258;
          wlan_objmgr_pdev_release_ref(v256, v285, v259, v257, v260, v261, v262, v263, v264, v265, v266);
        }
        else
        {
          v28 = 0;
        }
      }
      goto LABEL_62;
    }
    qdf_mem_copy(v286 + 29634, v272, (unsigned int)(14 * v282));
    if ( !(_DWORD)v283 )
      goto LABEL_307;
    if ( (unsigned int)v282 <= 0xA )
    {
LABEL_306:
      qdf_mem_copy(&v286[14 * (unsigned int)v282 + 29634], v274, (unsigned int)(14 * v283));
      reg_modify_max_bw_for_240mhz_5g_chans(a1, v274);
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
  LOBYTE(v288) = 0;
  if ( v82 )
  {
    if ( *((_DWORD *)v82 - 1) != 13449260 )
      __break(0x8228u);
    v82(v80, v83, &v288);
    LOBYTE(v83) = v288;
  }
  else
  {
    LOBYTE(v288) = v83;
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
