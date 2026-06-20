__int64 __fastcall dp_tx_mon_process_status_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11,
        __int64 a12,
        unsigned int a13,
        __int64 a14,
        unsigned int a15)
{
  unsigned int *v15; // x19
  __int64 v16; // x20
  __int64 v17; // x24
  __int64 v18; // x28
  __int64 v19; // x23
  __int64 v20; // x21
  __int64 v22; // x27
  unsigned int v24; // w5
  unsigned int v25; // w25
  __int64 v26; // x23
  __int64 v27; // x8
  unsigned int v28; // w20
  __int64 v29; // x28
  _DWORD *v30; // x26
  __int64 v31; // x25
  bool v32; // zf
  __int64 v33; // x8
  __int64 v34; // x28
  _DWORD *v35; // x20
  __int64 v36; // x26
  unsigned int *v37; // x10
  char v38; // w8
  unsigned int v39; // w9
  __int64 v40; // x8
  __int64 v41; // x24
  _DWORD *v42; // x23
  __int64 v43; // x22
  __int64 result; // x0
  __int64 v45; // x9
  __int64 v46; // x22
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  unsigned __int8 v55; // w25
  _DWORD *v56; // x22
  _DWORD *v57; // x8
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  char **v67; // x8
  char *v68; // x25
  char *v69; // x28
  __int64 v70; // x9
  unsigned __int64 v71; // x8
  __int64 v72; // x9
  __int64 (*v73)(void); // x8
  int v74; // w0
  __int64 v75; // x24
  unsigned __int64 v76; // x22
  __int64 v77; // x26
  __int64 v78; // x27
  unsigned int v79; // w8
  __int64 v80; // x0
  __int64 v81; // x1
  __int64 v82; // x2
  unsigned __int64 v83; // x26
  __int64 *v84; // x22
  unsigned int v85; // w8
  __int64 v86; // x8
  int v87; // w9
  __int64 v88; // x9
  unsigned __int64 v89; // x8
  __int64 v90; // x9
  char v91; // w6
  __int64 v92; // x9
  const void *v93; // x1
  int v94; // w3
  __int64 v95; // x4
  __int64 v96; // x2
  __int64 v97; // x0
  __int64 v98; // x8
  __int64 v99; // x9
  int v100; // w8
  __int64 v101; // x22
  __int64 v102; // x0
  _DWORD *v103; // x26
  __int64 v104; // x8
  _WORD *v105; // x22
  __int64 v106; // x24
  __int64 v107; // x27
  __int64 v108; // x8
  __int64 v109; // x8
  __int64 v110; // x24
  unsigned int v111; // w8
  __int64 v112; // x22
  __int64 v113; // x26
  unsigned int *v114; // x24
  _BYTE *v115; // x24
  int v116; // t1
  __int64 *v117; // x8
  __int64 v118; // x0
  __int64 v119; // x9
  __int64 *v120; // x10
  __int64 v121; // x8
  __int64 **v122; // x9
  unsigned int i; // w8
  __int64 *v124; // x10
  __int64 v125; // x11
  __int64 v126; // x8
  __int64 v127; // x8
  unsigned int *v128; // x22
  _BYTE *v129; // x22
  int v130; // t1
  _QWORD *v131; // x0
  unsigned __int64 v132; // x8
  unsigned int *v133; // x8
  __int64 v134; // x10
  unsigned int *v135; // x8
  unsigned int *v136; // x9
  unsigned int v137; // w9
  __int64 v138; // x26
  __int64 v139; // x8
  unsigned int v140; // w9
  __int64 v141; // x22
  __int64 v142; // x0
  __int64 v143; // x24
  _WORD *v144; // x22
  __int64 v145; // x8
  unsigned int v146; // w8
  __int64 v147; // x0
  _WORD *v148; // x27
  _DWORD *v149; // x24
  __int64 v150; // x8
  unsigned int v151; // w8
  unsigned int *v152; // x24
  __int64 v153; // x0
  _WORD *v154; // x22
  _DWORD *v155; // x26
  __int64 v156; // x8
  unsigned int v157; // w9
  unsigned int v158; // w27
  unsigned int v159; // w8
  __int64 v160; // x22
  __int64 v161; // x0
  __int64 v162; // x24
  _WORD *v163; // x22
  __int64 v164; // x8
  unsigned int v165; // w8
  int v166; // w9
  unsigned int v167; // w8
  int v168; // w9
  unsigned int v169; // w8
  int v170; // w9
  __int64 v171; // x0
  __int64 v172; // x0
  __int64 v173; // x0
  _WORD *v174; // x12
  int v175; // w9
  int v176; // w10
  __int64 v177; // x11
  char v178; // w13
  char v179; // w14
  _WORD *v180; // x10
  __int64 v181; // x8
  char v182; // w11
  unsigned int v183; // w22
  __int64 v184; // x0
  _WORD *v185; // x22
  __int64 v186; // x8
  int v187; // w9
  int v188; // w10
  __int64 v189; // x1
  int v190; // w9
  unsigned int v191; // w8
  int v192; // w9
  unsigned int v193; // w8
  __int64 v194; // x12
  char *v195; // x22
  unsigned int v196; // w9
  unsigned int v197; // w27
  unsigned int v198; // w8
  int v199; // w9
  int v200; // w9
  int v201; // w10
  __int64 v202; // x2
  __int64 v203; // x0
  __int64 v204; // x1
  _DWORD *v205; // x3
  int v206; // w9
  int v207; // w10
  int v208; // w9
  int v209; // w10
  int v210; // w8
  int v211; // w9
  int v212; // w9
  int v213; // w10
  int v214; // w9
  int v215; // w10
  int v216; // w0
  __int64 v217; // x24
  char *v218; // x22
  char v219; // w8
  unsigned __int64 v220; // x9
  unsigned int v221; // w9
  double v222; // d0
  double v223; // d1
  double v224; // d2
  double v225; // d3
  double v226; // d4
  double v227; // d5
  double v228; // d6
  double v229; // d7
  __int64 v230; // x8
  unsigned int v231; // w20
  __int64 v232; // x24
  _DWORD *v233; // x23
  __int64 v234; // x22
  unsigned __int64 StatusReg; // x8
  int v236; // w10
  __int64 v237; // x8
  unsigned __int64 v238; // x8
  int v239; // w10
  __int64 v240; // x8
  __int64 v241; // x8
  __int64 v242; // x8
  unsigned int v243; // w20
  __int64 v244; // x26
  _DWORD *v245; // x25
  __int64 v246; // x24
  __int64 v247; // [xsp+18h] [xbp-88h]
  int v248; // [xsp+24h] [xbp-7Ch]
  unsigned int v249; // [xsp+28h] [xbp-78h]
  _WORD *v250; // [xsp+38h] [xbp-68h]
  __int64 v251; // [xsp+40h] [xbp-60h]
  __int64 v252; // [xsp+48h] [xbp-58h]
  __int64 v253; // [xsp+50h] [xbp-50h]
  __int64 v254; // [xsp+58h] [xbp-48h]
  char **v255; // [xsp+60h] [xbp-40h]
  signed __int64 v256; // [xsp+70h] [xbp-30h]
  __int64 v259; // [xsp+80h] [xbp-20h]
  unsigned int v260; // [xsp+88h] [xbp-18h]
  char v261[4]; // [xsp+94h] [xbp-Ch] BYREF
  __int64 v262; // [xsp+98h] [xbp-8h]

  v18 = a15;
  v19 = a13;
  v20 = a10;
  v262 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a10 || (v22 = *(_QWORD *)(a10 + 96456)) == 0 )
  {
    ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))dp_tx_mon_status_free_packet_buf)(
      a10,
      a12,
      a13,
      a14,
      a15);
LABEL_273:
    if ( a12 )
      page_frag_free(a12);
    result = 2;
    goto LABEL_276;
  }
  if ( (unsigned __int8)a15 >= 3u )
    goto LABEL_286;
  v260 = (unsigned __int8)a15;
  v15 = (unsigned int *)(v22 + 2576LL * (unsigned __int8)a15 + 39344);
  if ( (*(_QWORD *)(a11 + 12) & 0x30000LL) == 0x10000 )
  {
    v241 = *(_QWORD *)(v22 + 2576LL * (unsigned __int8)a15 + 39616);
    *(_DWORD *)(v22 + 2576LL * (unsigned __int8)a15 + 39348) = 0;
    *(_QWORD *)(v22 + 2576LL * (unsigned __int8)a15 + 39616) = v241 + 1;
    *v15 = *(_DWORD *)(a11 + 8);
    goto LABEL_262;
  }
  if ( *(char *)(v22 + 2576LL * (unsigned __int8)a15 + 39844) < 0 )
  {
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: status frag queue for a ppdu[%d] exceed %d\n",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "dp_tx_mon_process_status_tlv",
      *v15,
      128);
    goto LABEL_262;
  }
  if ( !*(_DWORD *)(v22 + 2576LL * (unsigned __int8)a15 + 39352) )
  {
LABEL_262:
    v242 = *(unsigned __int8 *)(v22 + 2576LL * (unsigned __int8)v18 + 39845);
    if ( *(unsigned __int8 *)(v22 + 2576LL * (unsigned __int8)v18 + 39844) >= 0x80u )
      v243 = 128;
    else
      v243 = *(unsigned __int8 *)(v22 + 2576LL * (unsigned __int8)v18 + 39844);
    if ( (unsigned int)v242 < v243 )
    {
      v244 = v242 + 1;
      v245 = (_DWORD *)(16 * v242 + 2576LL * v260 + v22 + 39856);
      do
      {
        v246 = *((_QWORD *)v245 - 1);
        if ( v246 )
        {
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD))dp_tx_mon_status_free_packet_buf)(
            v20,
            *((_QWORD *)v245 - 1),
            (unsigned int)*v245,
            a14,
            (unsigned int)v18);
          ++*(_QWORD *)(v22 + 2576LL * (unsigned __int8)v18 + 39576);
          page_frag_free(v246);
          *((_QWORD *)v245 - 1) = 0;
          *v245 = 0;
        }
        v32 = v243 == (unsigned __int8)v244++;
        v245 += 4;
      }
      while ( !v32 );
    }
    *(_WORD *)(v22 + 2576LL * (unsigned __int8)v18 + 39844) = 0;
    ((void (__fastcall *)(__int64, __int64, _QWORD, __int64, _QWORD))dp_tx_mon_status_free_packet_buf)(
      v20,
      a12,
      (unsigned int)v19,
      a14,
      (unsigned int)v18);
    if ( v22 + 2576LL * (unsigned __int8)v18 != -39344 )
      ++*(_QWORD *)(v22 + 2576LL * (unsigned __int8)v18 + 39576);
    goto LABEL_273;
  }
  v24 = *(_DWORD *)(a11 + 8);
  v25 = *(unsigned __int8 *)(v22 + 2576LL * (unsigned __int8)a15 + 39844);
  if ( *v15 == v24 )
  {
    v24 = *v15;
  }
  else if ( *(_BYTE *)(v22 + 2576LL * (unsigned __int8)a15 + 39844) )
  {
    v26 = a15;
    if ( (*(_BYTE *)(v22 + 2576LL * (unsigned __int8)a15 + 39348) & 8) != 0 )
    {
      v33 = *(unsigned __int8 *)(v22 + 2576LL * (unsigned __int8)a15 + 39845);
      ++*(_QWORD *)(v22 + 2576LL * (unsigned __int8)a15 + 39624);
      if ( (unsigned int)v33 < v25 )
      {
        v34 = v33 + 1;
        v35 = (_DWORD *)(16 * v33 + 2576LL * (unsigned __int8)a15 + v22 + 39856);
        do
        {
          v36 = *((_QWORD *)v35 - 1);
          if ( v36 )
          {
            ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD))dp_tx_mon_status_free_packet_buf)(
              v20,
              *((_QWORD *)v35 - 1),
              (unsigned int)*v35,
              a14,
              (unsigned int)v26);
            ++*((_QWORD *)v15 + 29);
            page_frag_free(v36);
            *((_QWORD *)v35 - 1) = 0;
            *v35 = 0;
          }
          v32 = v25 == (unsigned __int8)v34++;
          v35 += 4;
        }
        while ( !v32 );
      }
    }
    else
    {
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: End of ppdu not seen PID:%d cur_pid:%d idx:%d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "dp_tx_mon_process_status_tlv");
      v27 = *(unsigned __int8 *)(v22 + 2576LL * (unsigned __int8)v18 + 39845);
      if ( *(unsigned __int8 *)(v22 + 2576LL * (unsigned __int8)v18 + 39844) >= 0x80u )
        v28 = 128;
      else
        v28 = *(unsigned __int8 *)(v22 + 2576LL * (unsigned __int8)v18 + 39844);
      if ( (unsigned int)v27 < v28 )
      {
        v29 = v27 + 1;
        v30 = (_DWORD *)(16 * v27 + 2576LL * v260 + v22 + 39856);
        do
        {
          v31 = *((_QWORD *)v30 - 1);
          if ( v31 )
          {
            ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD))dp_tx_mon_status_free_packet_buf)(
              v20,
              *((_QWORD *)v30 - 1),
              (unsigned int)*v30,
              a14,
              (unsigned int)v26);
            ++*((_QWORD *)v15 + 29);
            page_frag_free(v31);
            *((_QWORD *)v30 - 1) = 0;
            *v30 = 0;
          }
          v32 = v28 == (unsigned __int8)v29++;
          v30 += 4;
        }
        while ( !v32 );
      }
    }
    v15[1] = 0;
    v18 = v26;
    v19 = a13;
    *((_WORD *)v15 + 250) = 0;
    v25 = 0;
    v24 = *(_DWORD *)(a11 + 8);
  }
  *v15 = v24;
  v37 = &v15[4 * v25];
  v38 = *(_WORD *)(a11 + 14);
  *((_QWORD *)v37 + 63) = a12;
  v37[128] = v19;
  v39 = v15[1];
  *((_BYTE *)v15 + 500) = v25 + 1;
  v15[1] = (1 << (v38 & 3)) | v39;
  if ( (*(_QWORD *)(a11 + 12) & 0x30000LL) != 0x20000 )
    goto LABEL_258;
  if ( v15[26] + v15[32] >= 0x41 )
  {
    v40 = *((unsigned __int8 *)v15 + 501);
    ++*((_QWORD *)v15 + 33);
    if ( (unsigned int)v40 <= v25 )
    {
      v41 = v40 + 1;
      v42 = (_DWORD *)(16 * v40 + 2576LL * v260 + v22 + 39856);
      do
      {
        v43 = *((_QWORD *)v42 - 1);
        if ( v43 )
        {
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD))dp_tx_mon_status_free_packet_buf)(
            v20,
            *((_QWORD *)v42 - 1),
            (unsigned int)*v42,
            a14,
            (unsigned int)v18);
          ++*((_QWORD *)v15 + 29);
          page_frag_free(v43);
          *((_QWORD *)v42 - 1) = 0;
          *v42 = 0;
        }
        v32 = v25 + 1 == (unsigned __int8)v41++;
        v42 += 4;
      }
      while ( !v32 );
    }
    *((_WORD *)v15 + 250) = 0;
    result = 24;
    goto LABEL_276;
  }
  v261[0] = 0;
  v16 = *(_QWORD *)(v20 + 96456);
  if ( !v16 )
    goto LABEL_231;
  v45 = v16 + 2576LL * v260;
  v17 = v45 + 39344;
  v46 = *(unsigned __int8 *)(v45 + 39845);
  v259 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, _QWORD, _QWORD))dp_tx_mon_get_ppdu_info)(
           v20,
           0,
           1,
           *(unsigned int *)(v45 + 39344),
           (unsigned int)v18);
  if ( !v259 )
    goto LABEL_230;
  v55 = v46;
  if ( (char)v46 < 0 )
  {
LABEL_286:
    __break(0x5512u);
    goto LABEL_287;
  }
  v56 = *(_DWORD **)(v17 + 504 + 16 * v46);
  v254 = v17 + 504;
  qdf_trace_msg(
    0x92u,
    8u,
    "%s: last_frag_q_idx: %d status_frag:%pK",
    v47,
    v48,
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    "dp_tx_mon_process_tlv_2_0",
    *(unsigned __int8 *)(v17 + 500),
    v56);
  v57 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v20 + 8) + 1128LL) + 74392LL) + 1704LL);
  if ( *(v57 - 1) != 803707193 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(_DWORD *, char *))v57)(v56, v261) == 36 || !v261[0] )
  {
    dp_tx_mon_free_ppdu_info(v259, v17);
    *(_QWORD *)(v17 + 296) = 0;
    qdf_trace_msg(
      0x92u,
      2u,
      "%s: window open with tlv_tag[0x%x] num_users[%d]!\n",
      v222,
      v223,
      v224,
      v225,
      v226,
      v227,
      v228,
      v229,
      "dp_tx_mon_process_tlv_2_0",
      (*v56 >> 1) & 0x1FF,
      (unsigned __int8)v261[0]);
LABEL_231:
    v230 = *((unsigned __int8 *)v15 + 501);
    if ( *((unsigned __int8 *)v15 + 500) >= 0x80u )
      v231 = 128;
    else
      v231 = *((unsigned __int8 *)v15 + 500);
    if ( (unsigned int)v230 < v231 )
    {
      v232 = v230 + 1;
      v233 = (_DWORD *)(16 * v230 + 2576LL * v260 + v22 + 39856);
      do
      {
        v234 = *((_QWORD *)v233 - 1);
        if ( v234 )
        {
          ((void (__fastcall *)(__int64, _QWORD, _QWORD, __int64, _QWORD))dp_tx_mon_status_free_packet_buf)(
            v20,
            *((_QWORD *)v233 - 1),
            (unsigned int)*v233,
            a14,
            (unsigned int)v18);
          ++*((_QWORD *)v15 + 29);
          page_frag_free(v234);
          *((_QWORD *)v233 - 1) = 0;
          *v233 = 0;
        }
        v32 = v231 == (unsigned __int8)v232++;
        v233 += 4;
      }
      while ( !v32 );
    }
    result = 0;
    *((_WORD *)v15 + 250) = 0;
    goto LABEL_276;
  }
  v58 = ((__int64 (__fastcall *)(__int64, __int64))dp_tx_mon_get_ppdu_info)(v20, 1);
  if ( !v58 )
  {
    dp_tx_mon_free_ppdu_info(v259, v17);
    *(_QWORD *)(v17 + 296) = 0;
LABEL_230:
    qdf_trace_msg(
      0x92u,
      5u,
      "%s: tx prot ppdu info alloc got failed!!",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      "dp_tx_mon_process_tlv_2_0");
    goto LABEL_231;
  }
  v19 = v58;
  if ( *(unsigned __int8 *)(v17 + 501) >= (unsigned int)*(unsigned __int8 *)(v17 + 500) )
    goto LABEL_225;
  v15 = (unsigned int *)(v58 + 384);
  v252 = v17;
  v253 = v18;
  v250 = (_WORD *)(v58 + 408);
  v247 = v58 + 400;
  do
  {
    if ( (v55 & 0x80) != 0 )
      goto LABEL_286;
    v67 = (char **)(v254 + 16LL * v55);
    v68 = *v67;
    v255 = v67;
    v256 = *((unsigned int *)v67 + 2);
    if ( !*v67 )
      qdf_trace_msg(
        0x92u,
        2u,
        "%s: status frag is NULL\n",
        v59,
        v60,
        v61,
        v62,
        v63,
        v64,
        v65,
        v66,
        "dp_tx_mon_process_tlv_2_0");
    v69 = v68;
    do
    {
      v73 = *(__int64 (**)(void))(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v20 + 8) + 1128LL) + 74392LL) + 1696LL);
      if ( *((_DWORD *)v73 - 1) != -1498240919 )
        __break(0x8228u);
      v74 = v73();
      v75 = *(_QWORD *)(v20 + 96456);
      if ( !v75 )
        goto LABEL_52;
      v76 = *(unsigned int *)(v19 + 28);
      v77 = v75 + 39344;
      v78 = v75 + 39344 + 2576LL * v260;
      if ( v74 <= 8 )
      {
        if ( v74 <= 5 )
        {
          if ( v74 != 1 )
          {
            if ( v74 != 3 )
              goto LABEL_52;
            v79 = *(unsigned __int8 *)(v78 + 411);
            if ( v79 <= 1 )
            {
              if ( *(_BYTE *)(v78 + 411) )
              {
                if ( v79 != 1 )
                  goto LABEL_52;
                v80 = v20;
                v81 = v19;
                v82 = 1;
                goto LABEL_143;
              }
              v147 = _qdf_nbuf_alloc(
                       *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL),
                       128,
                       0,
                       4,
                       0,
                       "dp_tx_mon_generate_ack_frm",
                       518);
              if ( !v147 )
                goto LABEL_52;
              v148 = *(_WORD **)(v147 + 224);
              v149 = (_DWORD *)v147;
              v150 = *(_QWORD *)(v19 + 76) | 0x200000000000LL;
              *(_WORD *)(v19 + 140) = 212;
              *(_QWORD *)(v19 + 76) = v150;
              *v148 = 212;
              qdf_mem_copy(v148 + 2, (const void *)(v77 + 2576LL * v260 + 457), 6u);
              v148[1] = 0;
              v151 = v149[28];
              if ( v151 >= 0xB )
              {
                skb_trim(v149, 10);
                goto LABEL_191;
              }
              if ( v149[29] )
              {
                if ( v151 != 10 )
                {
                  v168 = 0;
                  v169 = 10 - v151;
LABEL_188:
                  if ( (unsigned int)pskb_expand_head(v149, 0, v168 + v169, 2080) )
                    dev_kfree_skb_any_reason(v149, 1);
                }
              }
              else
              {
                v201 = v149[52];
                v200 = v149[53];
                v169 = 10 - v151;
                if ( v200 - v201 < v169 )
                {
                  v168 = v201 - v200;
                  goto LABEL_188;
                }
              }
              skb_put(v149, (unsigned int)(10 - v149[28]));
LABEL_191:
              v202 = (unsigned int)v76 >> 10;
              v203 = v20;
              v204 = v19;
              v205 = v149;
LABEL_198:
              dp_tx_mon_enqueue_mpdu_nbuf(v203, v204, v202, v205);
              *(_DWORD *)(v19 + 28) |= 0x100u;
              goto LABEL_52;
            }
            if ( v79 == 2 )
            {
              v152 = &v15[86 * *(unsigned __int8 *)(v19 + 37)];
              v153 = _qdf_nbuf_alloc(
                       *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL),
                       (4 << *((_WORD *)v152 + 12)) + 20LL,
                       0,
                       4,
                       0,
                       "dp_tx_mon_generate_block_ack_frm",
                       950);
              if ( !v153 )
                goto LABEL_52;
              v154 = *(_WORD **)(v153 + 224);
              v155 = (_DWORD *)v153;
              qdf_mem_set(v154, 0x34u, 0);
              v156 = *(_QWORD *)(v19 + 76);
              *(_WORD *)(v19 + 140) = 148;
              *(_QWORD *)(v19 + 76) = v156 | 0x200000000000LL;
              *(_DWORD *)v154 = 2097300;
              qdf_mem_copy(v154 + 5, (const void *)(v78 + 463), 6u);
              qdf_mem_copy(v154 + 2, (const void *)(v78 + 457), 6u);
              v154[8] = *((_WORD *)v152 + 86);
              v154[9] = *((_WORD *)v152 + 85);
              v154 += 10;
              qdf_mem_copy(v154, v152 + 44, (unsigned int)(4 << *((_WORD *)v152 + 12)));
              v157 = v155[28];
              v158 = (_DWORD)v154 + (4 << *((_WORD *)v152 + 12)) - v155[56];
              v159 = v158 - v157;
              if ( v158 < v157 )
              {
                skb_trim(v155, v158);
LABEL_197:
                v203 = v20;
                v204 = v19;
                v202 = 0;
                v205 = v155;
                goto LABEL_198;
              }
              if ( v155[29] )
              {
                v159 = v158 - v157;
                if ( v158 != v157 )
                {
                  v170 = 0;
LABEL_194:
                  if ( (unsigned int)pskb_expand_head(v155, 0, v170 + v159, 2080) )
                    dev_kfree_skb_any_reason(v155, 1);
                }
              }
              else
              {
                v207 = v155[52];
                v206 = v155[53];
                if ( v206 - v207 < v159 )
                {
                  v170 = v207 - v206;
                  goto LABEL_194;
                }
              }
              skb_put(v155, v158 - v155[28]);
              goto LABEL_197;
            }
            if ( v79 == 3 )
            {
              v138 = (unsigned __int8)*(_DWORD *)(v19 + 28);
              if ( (unsigned __int8)*(_DWORD *)(v19 + 28) - 1 == *(unsigned __int8 *)(v19 + 37) )
              {
                if ( (unsigned int)v138 < 2 )
                {
                  v139 = 0;
                  v140 = 0;
                  goto LABEL_164;
                }
                v139 = (unsigned __int8)v76 & 0xFE;
                v174 = v250;
                v175 = 0;
                v176 = 0;
                v177 = v139;
                do
                {
                  v178 = *v174;
                  v179 = v174[172];
                  v177 -= 2;
                  v174 += 344;
                  v175 += (4 << v178) + 4;
                  v176 += (4 << v179) + 4;
                }
                while ( v177 );
                v140 = v176 + v175;
                if ( v139 != v138 )
                {
LABEL_164:
                  v180 = &v250[172 * (unsigned int)v139];
                  v181 = v138 - v139;
                  do
                  {
                    v182 = *v180;
                    --v181;
                    v180 += 172;
                    v140 += (4 << v182) + 4;
                  }
                  while ( v181 );
                }
                v183 = v140;
                v184 = _qdf_nbuf_alloc(
                         *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL),
                         v140 + 18LL,
                         0,
                         4,
                         0,
                         "dp_tx_mon_generate_mu_block_ack_frm",
                         874);
                if ( !v184 )
                  goto LABEL_52;
                v249 = v183;
                v185 = *(_WORD **)(v184 + 224);
                v251 = v184;
                v248 = *(_DWORD *)(v19 + 28);
                qdf_mem_set(v185, 0x34u, 0);
                v186 = *(_QWORD *)(v19 + 76) | 0x200000000000LL;
                *(_WORD *)(v19 + 140) = 148;
                *(_QWORD *)(v19 + 76) = v186;
                *(_DWORD *)v185 = 148;
                qdf_mem_copy(v185 + 5, (const void *)(v78 + 463), 6u);
                if ( (v248 & 0xFE) != 0 )
                  qdf_mem_set(v185 + 2, 6u, 255);
                else
                  qdf_mem_copy(v185 + 2, (const void *)(v78 + 457), 6u);
                v194 = v251;
                v185[8] = 22;
                v195 = (char *)(*(_QWORD *)(v251 + 224) + 18LL);
                v196 = *(_DWORD *)(v251 + 112);
                v197 = v249 + 18;
                v198 = v249 + 18 - v196;
                if ( v249 + 18 < v196 )
                {
                  skb_trim(v251, v197);
                  goto LABEL_217;
                }
                if ( *(_DWORD *)(v251 + 116) )
                {
                  v198 = v197 - v196;
                  if ( v197 != v196 )
                  {
                    v199 = 0;
LABEL_214:
                    v216 = pskb_expand_head(v251, 0, v199 + v198, 2080);
                    v194 = v251;
                    if ( v216 )
                    {
                      dev_kfree_skb_any_reason(v251, 1);
                      v194 = v251;
                    }
                  }
                }
                else
                {
                  v215 = *(_DWORD *)(v251 + 208);
                  v214 = *(_DWORD *)(v251 + 212);
                  if ( v214 - v215 < v198 )
                  {
                    v199 = v215 - v214;
                    goto LABEL_214;
                  }
                }
                skb_put(v194, v197 - *(_DWORD *)(v194 + 112));
LABEL_217:
                v217 = v247;
                do
                {
                  *(_WORD *)v195 = (*(_QWORD *)v217 >> 20) & 0xF000 | *(_WORD *)(v217 + 288) & 0x7FF;
                  *((_WORD *)v195 + 1) = *(_WORD *)(v217 + 154);
                  v218 = v195 + 4;
                  qdf_mem_copy(v218, (const void *)(v217 + 160), (unsigned int)(4 << *(_WORD *)(v217 + 8)));
                  v219 = *(_WORD *)(v217 + 8);
                  --v138;
                  v217 += 344;
                  v195 = &v218[4 << v219];
                }
                while ( v138 );
                dp_tx_mon_enqueue_mpdu_nbuf(v20, v19, 0, v251);
                v220 = *(_QWORD *)(v19 + 76) & 0xFFFFFFFFFFFFFFF7LL;
                *(_DWORD *)(v19 + 28) |= 0x100u;
                *(_QWORD *)(v19 + 76) = v220;
                goto LABEL_52;
              }
            }
            goto LABEL_52;
          }
          v112 = (unsigned __int8)*(_DWORD *)(v19 + 28);
          if ( !(unsigned __int8)*(_DWORD *)(v19 + 28) )
            goto LABEL_52;
          v113 = 0;
          while ( 2 )
          {
            v114 = &v15[86 * v113];
            v116 = *((unsigned __int8 *)v114 + 125);
            v115 = (char *)v114 + 125;
            if ( !v116 )
            {
LABEL_99:
              if ( ++v113 == v112 )
                goto LABEL_52;
              continue;
            }
            break;
          }
          v117 = (__int64 *)&v15[86 * v113 + 78];
          if ( &v15[86 * v113] != (unsigned int *)-312LL )
          {
            v118 = *v117;
            if ( *v117 )
            {
              v119 = *(_QWORD *)&v15[86 * v113 + 80];
              --v15[86 * v113 + 82];
              if ( v118 == v119 )
              {
                *v117 = 0;
                *(_QWORD *)&v15[86 * v113 + 80] = 0;
              }
              else
              {
                do
                {
                  v120 = (__int64 *)v118;
                  v118 = *(_QWORD *)v118;
                }
                while ( v119 != v118 );
                *(_QWORD *)&v15[86 * v113 + 80] = v120;
                v118 = *v120;
                if ( !*v120 )
                  goto LABEL_111;
              }
              v121 = *(_QWORD *)(v118 + 216) + *(unsigned int *)(v118 + 212);
              v122 = *(__int64 ***)(v121 + 8);
              for ( i = *(unsigned __int8 *)(v121 + 2); v122; i += *((unsigned __int8 *)v124 + v125 + 2) )
              {
                v124 = v122[27];
                v125 = *((unsigned int *)v122 + 53);
                v122 = (__int64 **)*v122;
              }
              *(_QWORD *)(v78 + 200) += i;
              _qdf_nbuf_free(v118);
            }
          }
LABEL_111:
          *v115 = 0;
          goto LABEL_99;
        }
        if ( v74 == 6 )
        {
          v128 = &v15[86 * (unsigned __int8)(v76 >> 10)];
          v130 = *((unsigned __int8 *)v128 + 125);
          v129 = (char *)v128 + 125;
          if ( v130 )
            dp_tx_mon_free_last_mpdu_q(v75 + 39344 + 2576LL * v260, v19);
          v131 = (_QWORD *)_qdf_nbuf_alloc(
                             *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL),
                             512,
                             512,
                             4,
                             0,
                             "dp_tx_mon_alloc_mpdu",
                             1050);
          if ( v131 )
          {
            v132 = *(unsigned int *)(v19 + 28);
            *v131 = 0;
            v133 = &v15[86 * (unsigned __int8)(v132 >> 10)];
            v134 = *((_QWORD *)v133 + 39);
            v135 = v133 + 78;
            v136 = v135;
            if ( v134 )
              v136 = *((unsigned int **)v135 + 1);
            *(_QWORD *)v136 = v131;
            v137 = v135[4];
            *((_QWORD *)v135 + 1) = v131;
            v135[4] = v137 + 1;
          }
          else
          {
            qdf_trace_msg(
              0x38u,
              2u,
              "%s: %s: %d No memory to allocate mpdu_nbuf!!!!!\n",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "dp_tx_mon_alloc_mpdu",
              "dp_tx_mon_alloc_mpdu",
              1053);
          }
          *v129 = 1;
          goto LABEL_52;
        }
        if ( v74 != 8 )
          goto LABEL_52;
        v83 = *(_QWORD *)(v19 + 40);
        v84 = (__int64 *)(v83 | 0xFFFFFF0000000000LL);
        if ( *(_DWORD *)((char *)&off_18 + (v83 | 0xFFFFFF0000000000LL) + 4) == -559043635 )
        {
          if ( *v84 )
            goto LABEL_76;
LABEL_158:
          v172 = printk(
                   &unk_AAA255,
                   "mon_desc->buf_addr",
                   "dp_tx_mon_update_ppdu_info_status",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_tx_mon_status_2.0.c");
          dump_stack(v172);
        }
        else
        {
          v171 = printk(
                   &unk_AAA255,
                   "0",
                   "dp_tx_mon_update_ppdu_info_status",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_tx_mon_status_2.0.c");
          dump_stack(v171);
          if ( !*v84 )
            goto LABEL_158;
        }
LABEL_76:
        ++*(_QWORD *)(v78 + 176);
        v85 = *(_DWORD *)((char *)&off_10 + (v83 | 0xFFFFFF0000000000LL));
        if ( ((v85 >> 2) & 0xFFFFFF) == v83 >> 40 )
        {
          if ( (v85 & 2) == 0 )
            goto LABEL_78;
        }
        else
        {
          ++*(_DWORD *)(v75 + 8 + 18528LL * v260 + 1924);
          v173 = printk(
                   &unk_AAA255,
                   "0",
                   "dp_tx_mon_update_ppdu_info_status",
                   "../vendor/qcom/opensource/wlan/qcacld-3.0/cmn/dp/wifi3.0/monitor/2.0/dp_tx_mon_status_2.0.c");
          dump_stack(v173);
          if ( (*(_DWORD *)((_BYTE *)&off_10 + (v83 | 0xFFFFFF0000000000LL)) & 2) == 0 )
          {
LABEL_78:
            _qdf_mem_unmap_page(
              *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL),
              *(__int64 *)((char *)&qword_8 + (v83 | 0xFFFFFF0000000000LL)),
              2048,
              2);
            *(_DWORD *)((char *)&off_10 + (v83 | 0xFFFFFF0000000000LL)) |= 2u;
          }
        }
        v86 = *v84;
        *v84 = 0;
        ++*(_DWORD *)(a14 + 16);
        if ( a14 )
        {
          v87 = *(_DWORD *)((char *)&off_10 + (v83 | 0xFFFFFF0000000000LL));
          *v84 = 0;
          *(_DWORD *)((char *)&off_10 + (v83 | 0xFFFFFF0000000000LL)) = v87 & 0xFFFFFFFE;
          *v84 = *(_QWORD *)a14;
          v88 = *(_QWORD *)(a14 + 8);
          *(_QWORD *)a14 = v84;
          if ( !v88 || !*v84 )
            *(_QWORD *)(a14 + 8) = v84;
        }
        *(_QWORD *)(v78 + 440) = v86;
        *(_DWORD *)(v78 + 448) = 0;
        *(_DWORD *)(v78 + 452) = *(unsigned __int16 *)(v19 + 48);
        v89 = *(unsigned int *)(v19 + 28);
        *(_DWORD *)(v19 + 28) = v89 | 0x100;
        v90 = *(_QWORD *)(v20 + 96456);
        if ( v90 )
        {
          v91 = 0;
          v92 = v90 + 2576LL * v260 + 39344;
          v93 = *(const void **)(v92 + 440);
          v94 = *(_DWORD *)(v92 + 448);
          v95 = *(unsigned int *)(v92 + 452);
          v96 = *(_QWORD *)&v15[86 * (unsigned __int8)(v89 >> 10) + 80];
          ++*(_QWORD *)(v92 + 192);
          v97 = *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL);
LABEL_114:
          qdf_nbuf_add_frag_debug(v97, v93, v96, v94, v95, 0x800u, v91, 0x40u, "dp_tx_mon_generate_data_frm", 1117);
          goto LABEL_52;
        }
        goto LABEL_52;
      }
      if ( v74 > 12 )
      {
        if ( v74 == 35 )
        {
          *(_DWORD *)(v19 + 68) = *(unsigned __int16 *)(v78 + 416);
          *(_DWORD *)(v259 + 68) = *(unsigned __int16 *)(v78 + 416);
          goto LABEL_52;
        }
        if ( v74 == 13 )
        {
          *(_DWORD *)(v259 + 64) *= 2;
          v98 = *(_QWORD *)(v20 + 96456);
          if ( v98 )
          {
            v99 = v98 + 2576LL * v260 + 39344;
            v100 = *(unsigned __int8 *)(v98 + 2576LL * v260 + 39754);
            *(_BYTE *)(v99 + 330) = v100;
            if ( v100 > 3 )
            {
              if ( v100 == 4 )
              {
                v81 = v259;
                v80 = v20;
                v82 = 0;
LABEL_143:
                dp_tx_mon_generate_cts2self_frm(v80, v81, v82, v253);
                goto LABEL_52;
              }
              if ( v100 != 5 )
              {
                if ( v100 != 6 )
                  goto LABEL_52;
                v141 = *(_QWORD *)(v20 + 96456);
                if ( !v141 )
                  goto LABEL_52;
                v142 = _qdf_nbuf_alloc(
                         *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL),
                         128,
                         0,
                         4,
                         0,
                         "dp_tx_mon_generate_4addr_qos_null_frm",
                         669);
                if ( !v142 )
                  goto LABEL_52;
                v103 = (_DWORD *)v142;
                v143 = v141 + 2576LL * v260;
                v144 = *(_WORD **)(v142 + 224);
                qdf_mem_set(v144, 0x20u, 0);
                v107 = v259;
                v145 = *(_QWORD *)(v259 + 76);
                *(_WORD *)(v259 + 140) = 200;
                *(_QWORD *)(v259 + 76) = v145 | 0x200000000000LL;
                *v144 = 200;
                v144[1] = *(_WORD *)(v259 + 138);
                qdf_mem_copy(v144 + 2, (const void *)(v143 + 39801), 6u);
                qdf_mem_copy(v144 + 5, (const void *)(v143 + 39807), 6u);
                qdf_mem_copy(v144 + 8, (const void *)(v143 + 39813), 6u);
                qdf_mem_copy(v144 + 12, (const void *)(v143 + 39819), 6u);
                v146 = v103[28];
                if ( v146 >= 0x21 )
                {
                  skb_trim(v103, 32);
                  goto LABEL_211;
                }
                if ( v103[29] )
                {
                  if ( v146 != 32 )
                  {
                    v190 = 0;
                    v191 = 32 - v146;
LABEL_201:
                    if ( (unsigned int)pskb_expand_head(v103, 0, v190 + v191, 2080) )
                      dev_kfree_skb_any_reason(v103, 1);
                  }
                }
                else
                {
                  v209 = v103[52];
                  v208 = v103[53];
                  v191 = 32 - v146;
                  if ( v208 - v209 < v191 )
                  {
                    v190 = v209 - v208;
                    goto LABEL_201;
                  }
                }
                v210 = v103[28];
                v211 = 32;
LABEL_209:
                v189 = (unsigned int)(v211 - v210);
                goto LABEL_210;
              }
              v160 = *(_QWORD *)(v20 + 96456);
              if ( v160 )
              {
                v161 = _qdf_nbuf_alloc(
                         *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL),
                         128,
                         0,
                         4,
                         0,
                         "dp_tx_mon_generate_3addr_qos_null_frm",
                         590);
                if ( v161 )
                {
                  v103 = (_DWORD *)v161;
                  v162 = v160 + 2576LL * v260;
                  v163 = *(_WORD **)(v161 + 224);
                  qdf_mem_set(v163, 0x1Au, 0);
                  v107 = v259;
                  v164 = *(_QWORD *)(v259 + 76);
                  *(_WORD *)(v259 + 140) = 200;
                  *(_QWORD *)(v259 + 76) = v164 | 0x200000000000LL;
                  *v163 = 200;
                  v163[1] = *(_WORD *)(v259 + 138);
                  qdf_mem_copy(v163 + 2, (const void *)(v162 + 39801), 6u);
                  qdf_mem_copy(v163 + 5, (const void *)(v162 + 39807), 6u);
                  qdf_mem_copy(v163 + 8, (const void *)(v162 + 39813), 6u);
                  v165 = v103[28];
                  if ( v165 >= 0x1B )
                  {
                    skb_trim(v103, 26);
                    goto LABEL_211;
                  }
                  if ( v103[29] )
                  {
                    if ( v165 != 26 )
                    {
                      v192 = 0;
                      v193 = 26 - v165;
LABEL_206:
                      if ( (unsigned int)pskb_expand_head(v103, 0, v192 + v193, 2080) )
                        dev_kfree_skb_any_reason(v103, 1);
                    }
                  }
                  else
                  {
                    v213 = v103[52];
                    v212 = v103[53];
                    v193 = 26 - v165;
                    if ( v212 - v213 < v193 )
                    {
                      v192 = v213 - v212;
                      goto LABEL_206;
                    }
                  }
                  v210 = v103[28];
                  v211 = 26;
                  goto LABEL_209;
                }
              }
            }
            else
            {
              if ( (unsigned int)(v100 - 1) >= 3 )
              {
                *(_DWORD *)(v259 + 28) &= ~0x100u;
                goto LABEL_52;
              }
              v101 = *(_QWORD *)(v20 + 96456);
              if ( v101 )
              {
                v102 = _qdf_nbuf_alloc(
                         *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL),
                         128,
                         0,
                         4,
                         0,
                         "dp_tx_mon_generate_rts_frm",
                         433);
                if ( v102 )
                {
                  v103 = (_DWORD *)v102;
                  v104 = v101 + 2576LL * v260;
                  v105 = *(_WORD **)(v102 + 224);
                  v106 = v104 + 39344;
                  qdf_mem_set(v105, 0x80u, 0);
                  v107 = v259;
                  v108 = *(_QWORD *)(v259 + 76);
                  *(_WORD *)(v259 + 140) = 180;
                  *(_QWORD *)(v259 + 76) = v108 | 0x200000000000LL;
                  *v105 = 180;
                  v105[1] = *(_WORD *)(v259 + 138);
                  v109 = 328;
                  if ( !*(_BYTE *)(v106 + 376) )
                    v109 = 408;
                  v110 = v106 + v109;
                  qdf_mem_copy(v105 + 2, (const void *)(v110 + 49), 6u);
                  qdf_mem_copy(v105 + 5, (const void *)(v110 + 55), 6u);
                  v111 = v103[28];
                  if ( v111 >= 0x11 )
                  {
                    skb_trim(v103, 16);
LABEL_211:
                    dp_tx_mon_enqueue_mpdu_nbuf(v20, v107, 0, v103);
                    *(_DWORD *)(v107 + 28) |= 0x100u;
                    goto LABEL_52;
                  }
                  if ( v103[29] )
                  {
                    if ( v111 != 16 )
                    {
                      v166 = 0;
                      v167 = 16 - v111;
LABEL_171:
                      if ( (unsigned int)pskb_expand_head(v103, 0, v166 + v167, 2080) )
                        dev_kfree_skb_any_reason(v103, 1);
                    }
                  }
                  else
                  {
                    v188 = v103[52];
                    v187 = v103[53];
                    v167 = 16 - v111;
                    if ( v187 - v188 < v167 )
                    {
                      v166 = v188 - v187;
                      goto LABEL_171;
                    }
                  }
                  v189 = (unsigned int)(16 - v103[28]);
LABEL_210:
                  skb_put(v103, v189);
                  goto LABEL_211;
                }
              }
            }
          }
        }
      }
      else
      {
        if ( v74 == 9 )
        {
          *(_DWORD *)(v19 + 28) = v76 | 0x100;
          v126 = *(_QWORD *)(v20 + 96456);
          if ( !v126 )
            goto LABEL_52;
          v91 = 1;
          v127 = v126 + 2576LL * v260 + 39344;
          v93 = *(const void **)(v127 + 440);
          v94 = *(_DWORD *)(v127 + 448);
          v95 = *(unsigned int *)(v127 + 452);
          v96 = *(_QWORD *)&v15[86 * (unsigned __int8)(v76 >> 10) + 80];
          ++*(_QWORD *)(v127 + 192);
          v97 = *(_QWORD *)(*(_QWORD *)(v20 + 8) + 24LL);
          goto LABEL_114;
        }
        if ( v74 == 11 )
          BYTE1(v15[86 * (unsigned __int8)(v76 >> 10) + 31]) = 0;
      }
LABEL_52:
      v70 = 8;
      if ( *(_BYTE *)(v16 + 39275) )
        v70 = 16;
      v71 = (unsigned __int64)&v69[v70 + (((unsigned __int64)*(unsigned int *)v69 >> 10) & 0xFFF)];
      v72 = -4;
      if ( *(_BYTE *)(v16 + 39275) )
        v72 = -8;
      v69 = (char *)((v71 - 1) & v72);
    }
    while ( v69 - v68 < v256 );
    v17 = v252;
    ++*(_QWORD *)(v252 + 232);
    if ( v68 )
      page_frag_free(v68);
    v221 = *(unsigned __int8 *)(v252 + 500);
    v55 = *(_BYTE *)(v252 + 501) + 1;
    *v255 = nullptr;
    *((_DWORD *)v255 + 2) = 0;
    *(_BYTE *)(v252 + 501) = v55;
  }
  while ( v221 > v55 );
LABEL_225:
  v20 = v259;
  *(_WORD *)(v17 + 500) = 0;
  v15 = (unsigned int *)(v16 + 18528LL * v260);
  LODWORD(v16) = *(_DWORD *)(v259 + 28);
  if ( (v16 & 0x100) != 0 )
  {
    if ( *(_WORD *)(v259 + 72) )
    {
      if ( *(_DWORD *)(v259 + 68) )
        goto LABEL_243;
    }
    else
    {
      *(_WORD *)(v259 + 72) = v15[6];
      if ( *(_DWORD *)(v259 + 68) )
      {
LABEL_243:
        if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
        {
LABEL_244:
          StatusReg = _ReadStatusReg(SP_EL0);
          if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            goto LABEL_246;
LABEL_287:
          raw_spin_lock_bh(v17 + 32);
          *(_QWORD *)(v17 + 40) |= 1uLL;
LABEL_247:
          *(_QWORD *)(v17 + 312) = *(_QWORD *)(v17 + 296);
          *(_QWORD *)(v20 + 8) = 0;
          **(_QWORD **)(v17 + 120) = v20;
          v236 = *(_DWORD *)(v17 + 104);
          v237 = *(_QWORD *)(v17 + 40);
          *(_QWORD *)(v17 + 120) = v20 + 8;
          *(_QWORD *)(v17 + 296) = 0;
          *(_DWORD *)(v17 + 104) = v236 + 1;
          if ( (v237 & 1) != 0 )
          {
            *(_QWORD *)(v17 + 40) = v237 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v17 + 32);
            if ( (*(_BYTE *)(v19 + 29) & 1) != 0 )
              goto LABEL_249;
          }
          else
          {
            raw_spin_unlock(v17 + 32);
            if ( (*(_BYTE *)(v19 + 29) & 1) != 0 )
              goto LABEL_249;
          }
LABEL_227:
          dp_tx_mon_free_ppdu_info(v19, v17);
          *(_QWORD *)(v17 + 304) = 0;
          if ( (v16 & 0x100) != 0 )
            goto LABEL_257;
          goto LABEL_258;
        }
LABEL_246:
        raw_spin_lock(v17 + 32);
        goto LABEL_247;
      }
    }
    *(_DWORD *)(v259 + 68) = v15[7];
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      goto LABEL_244;
    goto LABEL_246;
  }
  dp_tx_mon_free_ppdu_info(v259, v17);
  *(_QWORD *)(v17 + 296) = 0;
  if ( (*(_BYTE *)(v19 + 29) & 1) == 0 )
    goto LABEL_227;
LABEL_249:
  if ( *(_WORD *)(v19 + 72) )
  {
    if ( *(_DWORD *)(v19 + 68) )
      goto LABEL_251;
LABEL_283:
    *(_DWORD *)(v19 + 68) = v15[7];
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0 )
      goto LABEL_254;
LABEL_252:
    v238 = _ReadStatusReg(SP_EL0);
    if ( (*(_DWORD *)(v238 + 16) & 0xF0000) != 0 || (*(_DWORD *)(v238 + 16) & 0xFF00) != 0 )
      goto LABEL_254;
    raw_spin_lock_bh(v17 + 32);
    *(_QWORD *)(v17 + 40) |= 1uLL;
  }
  else
  {
    *(_WORD *)(v19 + 72) = v15[6];
    if ( !*(_DWORD *)(v19 + 68) )
      goto LABEL_283;
LABEL_251:
    if ( (_ReadStatusReg(DAIF) & 0x80) == 0 )
      goto LABEL_252;
LABEL_254:
    raw_spin_lock(v17 + 32);
  }
  *(_QWORD *)(v17 + 320) = *(_QWORD *)(v17 + 304);
  *(_QWORD *)(v19 + 8) = 0;
  **(_QWORD **)(v17 + 120) = v19;
  v239 = *(_DWORD *)(v17 + 104);
  v240 = *(_QWORD *)(v17 + 40);
  *(_QWORD *)(v17 + 120) = v19 + 8;
  *(_QWORD *)(v17 + 304) = 0;
  *(_DWORD *)(v17 + 104) = v239 + 1;
  if ( (v240 & 1) != 0 )
  {
    *(_QWORD *)(v17 + 40) = v240 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v17 + 32);
  }
  else
  {
    raw_spin_unlock(v17 + 32);
  }
LABEL_257:
  queue_work_on(32, *(_QWORD *)(v17 + 96), v17 + 48);
LABEL_258:
  result = 0;
LABEL_276:
  _ReadStatusReg(SP_EL0);
  return result;
}
