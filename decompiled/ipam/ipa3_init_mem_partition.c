__int64 __fastcall ipa3_init_mem_partition(int a1)
{
  _QWORD *v1; // x8
  void *v2; // x9
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x9
  int v7; // w4
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  _DWORD *v12; // x9
  int v13; // w4
  __int64 v14; // x0
  __int64 v15; // x0
  _DWORD *v16; // x9
  int v17; // w4
  __int64 v18; // x0
  __int64 v19; // x0
  _DWORD *v20; // x9
  int v21; // w4
  __int64 v22; // x0
  __int64 v23; // x0
  _DWORD *v24; // x9
  int v25; // w4
  __int64 v26; // x0
  __int64 v27; // x0
  __int64 v28; // x0
  __int64 v29; // x0
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x0
  int v34; // w4
  __int64 v35; // x0
  __int64 v36; // x0
  __int64 v37; // x0
  __int64 v38; // x0
  int v39; // w4
  __int64 v40; // x0
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x0
  __int64 v45; // x0
  __int64 v46; // x0
  __int64 v47; // x0
  __int64 v48; // x0
  __int64 v49; // x0
  int v50; // w4
  __int64 v51; // x0
  __int64 v52; // x0
  __int64 v53; // x0
  __int64 v54; // x0
  int v55; // w4
  __int64 v56; // x0
  __int64 v57; // x0
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x9
  int v61; // w4
  __int64 v62; // x0
  __int64 v63; // x0
  _DWORD *v64; // x9
  int v65; // w4
  __int64 v66; // x0
  __int64 v67; // x0
  __int64 v68; // x9
  int v69; // w4
  __int64 v70; // x0
  __int64 v71; // x0
  _DWORD *v72; // x9
  int v73; // w4
  __int64 v74; // x0
  __int64 v75; // x0
  _DWORD *v76; // x9
  int v77; // w3
  __int64 v78; // x0
  __int64 v79; // x0
  _DWORD *v80; // x9
  __int64 v81; // x0
  __int64 v82; // x0
  _DWORD *v83; // x9
  __int64 v84; // x0
  __int64 v85; // x0
  _DWORD *v86; // x9
  __int64 v87; // x0
  __int64 v88; // x0
  _DWORD *v89; // x9
  __int64 v90; // x0
  __int64 v91; // x0
  _DWORD *v92; // x9
  __int64 v93; // x0
  __int64 v94; // x8
  __int64 v95; // x0
  _DWORD *v96; // x9
  __int64 v97; // x0
  __int64 v98; // x0
  _DWORD *v99; // x9
  __int64 v100; // x0
  __int64 v101; // x0
  __int64 v102; // x0
  __int64 v103; // x0
  __int64 v104; // x0
  __int64 v105; // x0
  __int64 v106; // x0
  __int64 v107; // x0
  __int64 v108; // x0
  __int64 v109; // x0
  __int64 v110; // x0
  __int64 v111; // x0
  __int64 v112; // x0
  __int64 v113; // x0
  __int64 v114; // x0
  __int64 v115; // x0
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x9
  int v119; // w4
  __int64 v120; // x0
  __int64 v121; // x0
  __int64 v122; // x9
  int v123; // w4
  __int64 v124; // x0
  __int64 v125; // x8
  __int64 result; // x0
  __int64 v127; // x8
  __int64 v128; // x0
  __int64 v129; // x8
  __int64 v130; // x0
  __int64 v131; // x8
  __int64 v132; // x0
  __int64 v133; // x8
  __int64 v134; // x0
  __int64 v135; // x8
  __int64 v136; // x0
  __int64 v137; // x8
  __int64 v138; // x0
  __int64 v139; // x8
  __int64 v140; // x0
  __int64 v141; // x8
  __int64 v142; // x0
  __int64 v143; // x8
  __int64 v144; // x0
  __int64 v145; // x8
  __int64 v146; // x0
  __int64 v147; // x8
  __int64 v148; // x0
  __int64 v149; // x8
  __int64 v150; // x0
  __int64 v151; // x8
  __int64 v152; // x0
  __int64 v153; // x8
  __int64 v154; // x0
  __int64 v155; // x8
  __int64 v156; // x0
  __int64 v157; // x8
  __int64 v158; // x0
  __int64 v159; // x8
  __int64 v160; // x0
  __int64 v161; // x8
  __int64 v162; // x0
  __int64 v163; // x8
  __int64 v164; // x0
  __int64 v165; // x8
  __int64 v166; // x0
  __int64 v167; // x8
  __int64 v168; // x0
  __int64 v169; // x8
  __int64 v170; // x0
  __int64 v171; // x8
  __int64 v172; // x0
  __int64 v173; // x8
  __int64 v174; // x0
  __int64 v175; // x8
  __int64 v176; // x0
  __int64 v177; // x8
  __int64 v178; // x0
  __int64 v179; // x8
  __int64 v180; // x0
  __int64 v181; // x8
  __int64 v182; // x0
  __int64 v183; // x8
  const char *v184; // x1
  __int64 v185; // x3
  __int64 v186; // x8
  __int64 v187; // x0
  __int64 v188; // x8
  __int64 v189; // x0
  __int64 v190; // x8
  __int64 v191; // x0
  __int64 v192; // x0
  __int64 v193; // x8
  __int64 v194; // x0
  __int64 v195; // x8
  __int64 v196; // x0
  __int64 v197; // x8
  __int64 v198; // x0
  __int64 v199; // x8
  __int64 v200; // x4
  __int64 v201; // x8
  __int64 v202; // x0
  __int64 v203; // x8
  __int64 v204; // x0
  __int64 v205; // x8
  __int64 v206; // x0
  __int64 v207; // x8
  __int64 v208; // x0
  __int64 v209; // x8
  __int64 v210; // x0
  __int64 v211; // x8
  __int64 v212; // x0
  __int64 v213; // x8
  __int64 v214; // x0
  __int64 v215; // x8
  __int64 v216; // x0
  __int64 v217; // x8
  __int64 v218; // x0
  __int64 v219; // x8
  __int64 v220; // x0
  __int64 v221; // x8
  __int64 v222; // x0
  __int64 v223; // x8
  __int64 v224; // x0
  __int64 v225; // x8
  __int64 v226; // x0
  __int64 v227; // x8
  __int64 v229; // x8
  __int64 v230; // x0
  __int64 v231; // x0

  if ( a1 <= 15 )
  {
    if ( (unsigned int)a1 < 7 || a1 == 10 )
    {
      v1 = *(_QWORD **)(ipa3_ctx + 34176);
      v2 = &ipa_3_0_mem_part;
      goto LABEL_4;
    }
    if ( a1 == 15 )
    {
      v1 = *(_QWORD **)(ipa3_ctx + 34176);
      v2 = &ipa_4_1_mem_part;
      goto LABEL_4;
    }
LABEL_398:
    printk(&unk_3D07E8, "ipa3_init_mem_partition");
    v229 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v230 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v230 )
      {
        ipc_log_string(v230, "ipa %s:%d unsupported version %d\n", "ipa3_init_mem_partition", 10331, a1);
        v229 = ipa3_ctx;
      }
      v231 = *(_QWORD *)(v229 + 34160);
      if ( v231 )
        ipc_log_string(v231, "ipa %s:%d unsupported version %d\n", "ipa3_init_mem_partition", 10331, a1);
    }
    return 0xFFFFFFFFLL;
  }
  if ( a1 <= 19 )
  {
    if ( a1 > 17 )
    {
      v1 = *(_QWORD **)(ipa3_ctx + 34176);
      if ( a1 == 18 )
        v2 = &ipa_4_7_mem_part;
      else
        v2 = &ipa_4_9_mem_part;
    }
    else
    {
      v1 = *(_QWORD **)(ipa3_ctx + 34176);
      if ( a1 == 16 )
        v2 = &ipa_4_2_mem_part;
      else
        v2 = &ipa_4_5_mem_part;
    }
  }
  else if ( a1 <= 21 )
  {
    v1 = *(_QWORD **)(ipa3_ctx + 34176);
    if ( a1 == 20 )
      v2 = &ipa_4_11_mem_part;
    else
      v2 = &ipa_5_0_mem_part;
  }
  else
  {
    switch ( a1 )
    {
      case 22:
        v1 = *(_QWORD **)(ipa3_ctx + 34176);
        v2 = &ipa_5_1_mem_part;
        break;
      case 23:
        v1 = *(_QWORD **)(ipa3_ctx + 34176);
        if ( *(_BYTE *)(ipa3_ctx + 48860) == 1 )
          v2 = &ipa_5_2_iot_mem_part;
        else
          v2 = &ipa_5_2_mem_part;
        break;
      case 24:
        v1 = *(_QWORD **)(ipa3_ctx + 34176);
        v2 = &ipa_5_5_mem_part;
        break;
      default:
        goto LABEL_398;
    }
  }
LABEL_4:
  *v1 = v2;
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(
        v4,
        "ipa %s:%d UC OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10336,
        *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 328LL),
        *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 332LL));
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
    {
      ipc_log_string(
        v5,
        "ipa %s:%d UC OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10336,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 328LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 332LL));
      v3 = ipa3_ctx;
    }
  }
  v6 = **(_QWORD **)(v3 + 34176);
  v7 = *(_DWORD *)(v6 + 236);
  if ( (v7 & 3) != 0 )
  {
    printk(&unk_3B5CA5, "ipa3_init_mem_partition");
    v127 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v128 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v128 )
      {
        ipc_log_string(
          v128,
          "ipa %s:%d UC INFO OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10340,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 236LL));
        v127 = ipa3_ctx;
      }
      v129 = v127 + 0x8000;
      v130 = *(_QWORD *)(v129 + 1392);
      if ( v130 )
        ipc_log_string(
          v130,
          "ipa %s:%d UC INFO OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10340,
          *(unsigned int *)(**(_QWORD **)(v129 + 1408) + 236LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v8 = *(_QWORD *)(v3 + 34152);
    if ( v8 )
    {
      ipc_log_string(
        v8,
        "ipa %s:%d UC INFO OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10345,
        v7,
        *(_DWORD *)(v6 + 240));
      v3 = ipa3_ctx;
    }
    v9 = *(_QWORD *)(v3 + 34160);
    if ( v9 )
    {
      ipc_log_string(
        v9,
        "ipa %s:%d UC INFO OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10345,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 236LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 240LL));
      v3 = ipa3_ctx;
    }
    if ( v3 )
    {
      v10 = *(_QWORD *)(v3 + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d RAM OFST 0x%x\n", "ipa3_init_mem_partition", 10347, ***(_DWORD ***)(v3 + 34176));
        v3 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v3 + 34160);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d RAM OFST 0x%x\n", "ipa3_init_mem_partition", 10347, ***(_DWORD ***)(v3 + 34176));
        v3 = ipa3_ctx;
      }
    }
  }
  v12 = **(_DWORD ***)(v3 + 34176);
  v13 = v12[1];
  if ( (v13 & 7) != 0 )
  {
    printk(&unk_3DF0B4, "ipa3_init_mem_partition");
    v131 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v132 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v132 )
      {
        ipc_log_string(
          v132,
          "ipa %s:%d V4 FLT HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10351,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 4LL));
        v131 = ipa3_ctx;
      }
      v133 = v131 + 0x8000;
      v134 = *(_QWORD *)(v133 + 1392);
      if ( v134 )
        ipc_log_string(
          v134,
          "ipa %s:%d V4 FLT HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10351,
          *(unsigned int *)(**(_QWORD **)(v133 + 1408) + 4LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v14 = *(_QWORD *)(v3 + 34152);
    if ( v14 )
    {
      ipc_log_string(
        v14,
        "ipa %s:%d V4 FLT HASHABLE OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10358,
        v13,
        v12[2],
        v12[3]);
      v3 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v3 + 34160);
    if ( v15 )
    {
      ipc_log_string(
        v15,
        "ipa %s:%d V4 FLT HASHABLE OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10358,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 4LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 8LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 12LL));
      v3 = ipa3_ctx;
    }
  }
  v16 = **(_DWORD ***)(v3 + 34176);
  v17 = v16[4];
  if ( (v17 & 7) != 0 )
  {
    printk(&unk_3C7D28, "ipa3_init_mem_partition");
    v135 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v136 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v136 )
      {
        ipc_log_string(
          v136,
          "ipa %s:%d V4 FLT NON-HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10362,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 16LL));
        v135 = ipa3_ctx;
      }
      v137 = v135 + 0x8000;
      v138 = *(_QWORD *)(v137 + 1392);
      if ( v138 )
        ipc_log_string(
          v138,
          "ipa %s:%d V4 FLT NON-HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10362,
          *(unsigned int *)(**(_QWORD **)(v137 + 1408) + 16LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v18 = *(_QWORD *)(v3 + 34152);
    if ( v18 )
    {
      ipc_log_string(
        v18,
        "ipa %s:%d V4 FLT NON-HASHABLE OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10369,
        v17,
        v16[5],
        v16[6]);
      v3 = ipa3_ctx;
    }
    v19 = *(_QWORD *)(v3 + 34160);
    if ( v19 )
    {
      ipc_log_string(
        v19,
        "ipa %s:%d V4 FLT NON-HASHABLE OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10369,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 16LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 20LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 24LL));
      v3 = ipa3_ctx;
    }
  }
  v20 = **(_DWORD ***)(v3 + 34176);
  v21 = v20[7];
  if ( (v21 & 7) != 0 )
  {
    printk(&unk_3BEAAF, "ipa3_init_mem_partition");
    v139 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v140 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v140 )
      {
        ipc_log_string(
          v140,
          "ipa %s:%d V6 FLT HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10373,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 28LL));
        v139 = ipa3_ctx;
      }
      v141 = v139 + 0x8000;
      v142 = *(_QWORD *)(v141 + 1392);
      if ( v142 )
        ipc_log_string(
          v142,
          "ipa %s:%d V6 FLT HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10373,
          *(unsigned int *)(**(_QWORD **)(v141 + 1408) + 28LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v22 = *(_QWORD *)(v3 + 34152);
    if ( v22 )
    {
      ipc_log_string(
        v22,
        "ipa %s:%d V6 FLT HASHABLE OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10379,
        v21,
        v20[8],
        v20[9]);
      v3 = ipa3_ctx;
    }
    v23 = *(_QWORD *)(v3 + 34160);
    if ( v23 )
    {
      ipc_log_string(
        v23,
        "ipa %s:%d V6 FLT HASHABLE OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10379,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 28LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 32LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 36LL));
      v3 = ipa3_ctx;
    }
  }
  v24 = **(_DWORD ***)(v3 + 34176);
  v25 = v24[10];
  if ( (v25 & 7) != 0 )
  {
    printk(&unk_3D080C, "ipa3_init_mem_partition");
    v143 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v144 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v144 )
      {
        ipc_log_string(
          v144,
          "ipa %s:%d V6 FLT NON-HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10383,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 40LL));
        v143 = ipa3_ctx;
      }
      v145 = v143 + 0x8000;
      v146 = *(_QWORD *)(v145 + 1392);
      if ( v146 )
        ipc_log_string(
          v146,
          "ipa %s:%d V6 FLT NON-HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10383,
          *(unsigned int *)(**(_QWORD **)(v145 + 1408) + 40LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v26 = *(_QWORD *)(v3 + 34152);
    if ( v26 )
    {
      ipc_log_string(
        v26,
        "ipa %s:%d V6 FLT NON-HASHABLE OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10390,
        v25,
        v24[11],
        v24[12]);
      v3 = ipa3_ctx;
    }
    v27 = *(_QWORD *)(v3 + 34160);
    if ( v27 )
    {
      ipc_log_string(
        v27,
        "ipa %s:%d V6 FLT NON-HASHABLE OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10390,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 40LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 44LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 48LL));
      v3 = ipa3_ctx;
    }
    if ( v3 )
    {
      v28 = *(_QWORD *)(v3 + 34152);
      if ( v28 )
      {
        ipc_log_string(
          v28,
          "ipa %s:%d V4 RT NUM INDEX 0x%x\n",
          "ipa3_init_mem_partition",
          10392,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 52LL));
        v3 = ipa3_ctx;
      }
      v29 = *(_QWORD *)(v3 + 34160);
      if ( v29 )
      {
        ipc_log_string(
          v29,
          "ipa %s:%d V4 RT NUM INDEX 0x%x\n",
          "ipa3_init_mem_partition",
          10392,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 52LL));
        v3 = ipa3_ctx;
      }
      if ( v3 )
      {
        v30 = *(_QWORD *)(v3 + 34152);
        if ( v30 )
        {
          ipc_log_string(
            v30,
            "ipa %s:%d V4 RT MODEM INDEXES 0x%x - 0x%x\n",
            "ipa3_init_mem_partition",
            10396,
            *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 56LL),
            *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 60LL));
          v3 = ipa3_ctx;
        }
        v31 = *(_QWORD *)(v3 + 34160);
        if ( v31 )
        {
          ipc_log_string(
            v31,
            "ipa %s:%d V4 RT MODEM INDEXES 0x%x - 0x%x\n",
            "ipa3_init_mem_partition",
            10396,
            *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 56LL),
            *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 60LL));
          v3 = ipa3_ctx;
        }
        if ( v3 )
        {
          v32 = *(_QWORD *)(v3 + 34152);
          if ( v32 )
          {
            ipc_log_string(
              v32,
              "ipa %s:%d V4 RT APPS INDEXES 0x%x - 0x%x\n",
              "ipa3_init_mem_partition",
              10400,
              *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 64LL),
              *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 68LL));
            v3 = ipa3_ctx;
          }
          v33 = *(_QWORD *)(v3 + 34160);
          if ( v33 )
          {
            ipc_log_string(
              v33,
              "ipa %s:%d V4 RT APPS INDEXES 0x%x - 0x%x\n",
              "ipa3_init_mem_partition",
              10400,
              *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 64LL),
              *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 68LL));
            v3 = ipa3_ctx;
          }
        }
      }
    }
  }
  v34 = *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 72LL);
  if ( (v34 & 7) != 0 )
  {
    printk(&unk_3AA921, "ipa3_init_mem_partition");
    v147 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v148 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v148 )
      {
        ipc_log_string(
          v148,
          "ipa %s:%d V4 RT HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10404,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 72LL));
        v147 = ipa3_ctx;
      }
      v149 = v147 + 0x8000;
      v150 = *(_QWORD *)(v149 + 1392);
      if ( v150 )
        ipc_log_string(
          v150,
          "ipa %s:%d V4 RT HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10404,
          *(unsigned int *)(**(_QWORD **)(v149 + 1408) + 72LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v35 = *(_QWORD *)(v3 + 34152);
    if ( v35 )
    {
      ipc_log_string(v35, "ipa %s:%d V4 RT HASHABLE OFST 0x%x\n", "ipa3_init_mem_partition", 10408, v34);
      v3 = ipa3_ctx;
    }
    v36 = *(_QWORD *)(v3 + 34160);
    if ( v36 )
    {
      ipc_log_string(
        v36,
        "ipa %s:%d V4 RT HASHABLE OFST 0x%x\n",
        "ipa3_init_mem_partition",
        10408,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 72LL));
      v3 = ipa3_ctx;
    }
    if ( v3 )
    {
      v37 = *(_QWORD *)(v3 + 34152);
      if ( v37 )
      {
        ipc_log_string(
          v37,
          "ipa %s:%d V4 RT HASHABLE SIZE 0x%x DDR SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10412,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 76LL),
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 80LL));
        v3 = ipa3_ctx;
      }
      v38 = *(_QWORD *)(v3 + 34160);
      if ( v38 )
      {
        ipc_log_string(
          v38,
          "ipa %s:%d V4 RT HASHABLE SIZE 0x%x DDR SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10412,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 76LL),
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 80LL));
        v3 = ipa3_ctx;
      }
    }
  }
  v39 = *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 84LL);
  if ( (v39 & 7) != 0 )
  {
    printk(&unk_3D90D5, "ipa3_init_mem_partition");
    v151 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v152 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v152 )
      {
        ipc_log_string(
          v152,
          "ipa %s:%d V4 RT NON-HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10416,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 84LL));
        v151 = ipa3_ctx;
      }
      v153 = v151 + 0x8000;
      v154 = *(_QWORD *)(v153 + 1392);
      if ( v154 )
        ipc_log_string(
          v154,
          "ipa %s:%d V4 RT NON-HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10416,
          *(unsigned int *)(**(_QWORD **)(v153 + 1408) + 84LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v40 = *(_QWORD *)(v3 + 34152);
    if ( v40 )
    {
      ipc_log_string(v40, "ipa %s:%d V4 RT NON-HASHABLE OFST 0x%x\n", "ipa3_init_mem_partition", 10421, v39);
      v3 = ipa3_ctx;
    }
    v41 = *(_QWORD *)(v3 + 34160);
    if ( v41 )
    {
      ipc_log_string(
        v41,
        "ipa %s:%d V4 RT NON-HASHABLE OFST 0x%x\n",
        "ipa3_init_mem_partition",
        10421,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 84LL));
      v3 = ipa3_ctx;
    }
    if ( v3 )
    {
      v42 = *(_QWORD *)(v3 + 34152);
      if ( v42 )
      {
        ipc_log_string(
          v42,
          "ipa %s:%d V4 RT HASHABLE SIZE 0x%x DDR SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10425,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 88LL),
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 92LL));
        v3 = ipa3_ctx;
      }
      v43 = *(_QWORD *)(v3 + 34160);
      if ( v43 )
      {
        ipc_log_string(
          v43,
          "ipa %s:%d V4 RT HASHABLE SIZE 0x%x DDR SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10425,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 88LL),
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 92LL));
        v3 = ipa3_ctx;
      }
      if ( v3 )
      {
        v44 = *(_QWORD *)(v3 + 34152);
        if ( v44 )
        {
          ipc_log_string(
            v44,
            "ipa %s:%d V6 RT NUM INDEX 0x%x\n",
            "ipa3_init_mem_partition",
            10427,
            *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 96LL));
          v3 = ipa3_ctx;
        }
        v45 = *(_QWORD *)(v3 + 34160);
        if ( v45 )
        {
          ipc_log_string(
            v45,
            "ipa %s:%d V6 RT NUM INDEX 0x%x\n",
            "ipa3_init_mem_partition",
            10427,
            *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 96LL));
          v3 = ipa3_ctx;
        }
        if ( v3 )
        {
          v46 = *(_QWORD *)(v3 + 34152);
          if ( v46 )
          {
            ipc_log_string(
              v46,
              "ipa %s:%d V6 RT MODEM INDEXES 0x%x - 0x%x\n",
              "ipa3_init_mem_partition",
              10431,
              *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 100LL),
              *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 104LL));
            v3 = ipa3_ctx;
          }
          v47 = *(_QWORD *)(v3 + 34160);
          if ( v47 )
          {
            ipc_log_string(
              v47,
              "ipa %s:%d V6 RT MODEM INDEXES 0x%x - 0x%x\n",
              "ipa3_init_mem_partition",
              10431,
              *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 100LL),
              *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 104LL));
            v3 = ipa3_ctx;
          }
          if ( v3 )
          {
            v48 = *(_QWORD *)(v3 + 34152);
            if ( v48 )
            {
              ipc_log_string(
                v48,
                "ipa %s:%d V6 RT APPS INDEXES 0x%x - 0x%x\n",
                "ipa3_init_mem_partition",
                10435,
                *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 108LL),
                *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 112LL));
              v3 = ipa3_ctx;
            }
            v49 = *(_QWORD *)(v3 + 34160);
            if ( v49 )
            {
              ipc_log_string(
                v49,
                "ipa %s:%d V6 RT APPS INDEXES 0x%x - 0x%x\n",
                "ipa3_init_mem_partition",
                10435,
                *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 108LL),
                *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 112LL));
              v3 = ipa3_ctx;
            }
          }
        }
      }
    }
  }
  v50 = *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 116LL);
  if ( (v50 & 7) != 0 )
  {
    printk(&unk_3AA954, "ipa3_init_mem_partition");
    v155 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v156 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v156 )
      {
        ipc_log_string(
          v156,
          "ipa %s:%d V6 RT HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10439,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 116LL));
        v155 = ipa3_ctx;
      }
      v157 = v155 + 0x8000;
      v158 = *(_QWORD *)(v157 + 1392);
      if ( v158 )
        ipc_log_string(
          v158,
          "ipa %s:%d V6 RT HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10439,
          *(unsigned int *)(**(_QWORD **)(v157 + 1408) + 116LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v51 = *(_QWORD *)(v3 + 34152);
    if ( v51 )
    {
      ipc_log_string(v51, "ipa %s:%d V6 RT HASHABLE OFST 0x%x\n", "ipa3_init_mem_partition", 10443, v50);
      v3 = ipa3_ctx;
    }
    v52 = *(_QWORD *)(v3 + 34160);
    if ( v52 )
    {
      ipc_log_string(
        v52,
        "ipa %s:%d V6 RT HASHABLE OFST 0x%x\n",
        "ipa3_init_mem_partition",
        10443,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 116LL));
      v3 = ipa3_ctx;
    }
    if ( v3 )
    {
      v53 = *(_QWORD *)(v3 + 34152);
      if ( v53 )
      {
        ipc_log_string(
          v53,
          "ipa %s:%d V6 RT HASHABLE SIZE 0x%x DDR SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10447,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 120LL),
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 124LL));
        v3 = ipa3_ctx;
      }
      v54 = *(_QWORD *)(v3 + 34160);
      if ( v54 )
      {
        ipc_log_string(
          v54,
          "ipa %s:%d V6 RT HASHABLE SIZE 0x%x DDR SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10447,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 120LL),
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 124LL));
        v3 = ipa3_ctx;
      }
    }
  }
  v55 = *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 128LL);
  if ( (v55 & 7) != 0 )
  {
    printk(&unk_3E7230, "ipa3_init_mem_partition");
    v159 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v160 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v160 )
      {
        ipc_log_string(
          v160,
          "ipa %s:%d V6 RT NON-HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10451,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 128LL));
        v159 = ipa3_ctx;
      }
      v161 = v159 + 0x8000;
      v162 = *(_QWORD *)(v161 + 1392);
      if ( v162 )
        ipc_log_string(
          v162,
          "ipa %s:%d V6 RT NON-HASHABLE OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10451,
          *(unsigned int *)(**(_QWORD **)(v161 + 1408) + 128LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v56 = *(_QWORD *)(v3 + 34152);
    if ( v56 )
    {
      ipc_log_string(v56, "ipa %s:%d V6 RT NON-HASHABLE OFST 0x%x\n", "ipa3_init_mem_partition", 10456, v55);
      v3 = ipa3_ctx;
    }
    v57 = *(_QWORD *)(v3 + 34160);
    if ( v57 )
    {
      ipc_log_string(
        v57,
        "ipa %s:%d V6 RT NON-HASHABLE OFST 0x%x\n",
        "ipa3_init_mem_partition",
        10456,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 128LL));
      v3 = ipa3_ctx;
    }
    if ( v3 )
    {
      v58 = *(_QWORD *)(v3 + 34152);
      if ( v58 )
      {
        ipc_log_string(
          v58,
          "ipa %s:%d V6 RT NON-HASHABLE SIZE 0x%x DDR SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10460,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 132LL),
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 136LL));
        v3 = ipa3_ctx;
      }
      v59 = *(_QWORD *)(v3 + 34160);
      if ( v59 )
      {
        ipc_log_string(
          v59,
          "ipa %s:%d V6 RT NON-HASHABLE SIZE 0x%x DDR SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10460,
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 132LL),
          *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 136LL));
        v3 = ipa3_ctx;
      }
    }
  }
  v60 = **(_QWORD **)(v3 + 34176);
  v61 = *(_DWORD *)(v60 + 140);
  if ( (v61 & 7) != 0 )
  {
    printk(&unk_3B0652, "ipa3_init_mem_partition");
    v163 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v164 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v164 )
      {
        ipc_log_string(
          v164,
          "ipa %s:%d MODEM HDR OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10464,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 140LL));
        v163 = ipa3_ctx;
      }
      v165 = v163 + 0x8000;
      v166 = *(_QWORD *)(v165 + 1392);
      if ( v166 )
        ipc_log_string(
          v166,
          "ipa %s:%d MODEM HDR OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10464,
          *(unsigned int *)(**(_QWORD **)(v165 + 1408) + 140LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v62 = *(_QWORD *)(v3 + 34152);
    if ( v62 )
    {
      ipc_log_string(
        v62,
        "ipa %s:%d MODEM HDR OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10469,
        v61,
        *(_DWORD *)(v60 + 144));
      v3 = ipa3_ctx;
    }
    v63 = *(_QWORD *)(v3 + 34160);
    if ( v63 )
    {
      ipc_log_string(
        v63,
        "ipa %s:%d MODEM HDR OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10469,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 140LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 144LL));
      v3 = ipa3_ctx;
    }
  }
  v64 = **(_DWORD ***)(v3 + 34176);
  v65 = v64[37];
  if ( (v65 & 7) != 0 )
  {
    printk(&unk_3E1AAB, "ipa3_init_mem_partition");
    v167 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v168 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v168 )
      {
        ipc_log_string(
          v168,
          "ipa %s:%d APPS HDR OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10473,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 148LL));
        v167 = ipa3_ctx;
      }
      v169 = v167 + 0x8000;
      v170 = *(_QWORD *)(v169 + 1392);
      if ( v170 )
        ipc_log_string(
          v170,
          "ipa %s:%d APPS HDR OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10473,
          *(unsigned int *)(**(_QWORD **)(v169 + 1408) + 148LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v66 = *(_QWORD *)(v3 + 34152);
    if ( v66 )
    {
      ipc_log_string(
        v66,
        "ipa %s:%d APPS HDR OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10479,
        v65,
        v64[38],
        v64[39]);
      v3 = ipa3_ctx;
    }
    v67 = *(_QWORD *)(v3 + 34160);
    if ( v67 )
    {
      ipc_log_string(
        v67,
        "ipa %s:%d APPS HDR OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10479,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 148LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 152LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 156LL));
      v3 = ipa3_ctx;
    }
  }
  v68 = **(_QWORD **)(v3 + 34176);
  v69 = *(_DWORD *)(v68 + 160);
  if ( (v69 & 7) != 0 )
  {
    printk(&unk_3ECF34, "ipa3_init_mem_partition");
    v171 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v172 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v172 )
      {
        ipc_log_string(
          v172,
          "ipa %s:%d MODEM HDR PROC CTX OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10483,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 160LL));
        v171 = ipa3_ctx;
      }
      v173 = v171 + 0x8000;
      v174 = *(_QWORD *)(v173 + 1392);
      if ( v174 )
        ipc_log_string(
          v174,
          "ipa %s:%d MODEM HDR PROC CTX OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10483,
          *(unsigned int *)(**(_QWORD **)(v173 + 1408) + 160LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v70 = *(_QWORD *)(v3 + 34152);
    if ( v70 )
    {
      ipc_log_string(
        v70,
        "ipa %s:%d MODEM HDR PROC CTX OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10489,
        v69,
        *(_DWORD *)(v68 + 164));
      v3 = ipa3_ctx;
    }
    v71 = *(_QWORD *)(v3 + 34160);
    if ( v71 )
    {
      ipc_log_string(
        v71,
        "ipa %s:%d MODEM HDR PROC CTX OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10489,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 160LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 164LL));
      v3 = ipa3_ctx;
    }
  }
  v72 = **(_DWORD ***)(v3 + 34176);
  v73 = v72[42];
  if ( (v73 & 7) != 0 )
  {
    printk(&unk_3EA3C2, "ipa3_init_mem_partition");
    v175 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v176 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v176 )
      {
        ipc_log_string(
          v176,
          "ipa %s:%d APPS HDR PROC CTX OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10493,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 168LL));
        v175 = ipa3_ctx;
      }
      v177 = v175 + 0x8000;
      v178 = *(_QWORD *)(v177 + 1392);
      if ( v178 )
        ipc_log_string(
          v178,
          "ipa %s:%d APPS HDR PROC CTX OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10493,
          *(unsigned int *)(**(_QWORD **)(v177 + 1408) + 168LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v74 = *(_QWORD *)(v3 + 34152);
    if ( v74 )
    {
      ipc_log_string(
        v74,
        "ipa %s:%d APPS HDR PROC CTX OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10500,
        v73,
        v72[43],
        v72[44]);
      v3 = ipa3_ctx;
    }
    v75 = *(_QWORD *)(v3 + 34160);
    if ( v75 )
    {
      ipc_log_string(
        v75,
        "ipa %s:%d APPS HDR PROC CTX OFST 0x%x SIZE 0x%x DDR SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10500,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 168LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 172LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 176LL));
      v3 = ipa3_ctx;
    }
  }
  v76 = **(_DWORD ***)(v3 + 34176);
  if ( (v76[72] & 7) != 0 )
  {
    printk(&unk_3CA6B3, "ipa3_init_mem_partition");
    v179 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967277LL;
    v180 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v180 )
    {
      ipc_log_string(
        v180,
        "ipa %s:%d PDN CONFIG OFST 0x%x is unaligned\n",
        "ipa3_init_mem_partition",
        10504,
        *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 288LL));
      v179 = ipa3_ctx;
    }
    v181 = v179 + 0x8000;
    v182 = *(_QWORD *)(v181 + 1392);
    if ( !v182 )
      return 4294967277LL;
    v183 = *(_QWORD *)(v181 + 1408);
    v184 = "ipa %s:%d PDN CONFIG OFST 0x%x is unaligned\n";
    v185 = 10504;
LABEL_359:
    v200 = *(unsigned int *)(*(_QWORD *)v183 + 288LL);
    goto LABEL_395;
  }
  v77 = v76[41];
  if ( (v77 & 0x1F) != 0 )
  {
    printk(&unk_3D682A, "ipa3_init_mem_partition");
    v186 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v187 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v187 )
      {
        ipc_log_string(
          v187,
          "ipa %s:%d MODEM HDR PROC CTX SIZE 0x%x is not 32B aligned\n",
          "ipa3_init_mem_partition",
          10518,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 164LL));
        v186 = ipa3_ctx;
      }
      v188 = v186 + 0x8000;
      v189 = *(_QWORD *)(v188 + 1392);
      if ( v189 )
        ipc_log_string(
          v189,
          "ipa %s:%d MODEM HDR PROC CTX SIZE 0x%x is not 32B aligned\n",
          "ipa3_init_mem_partition",
          10518,
          *(unsigned int *)(**(_QWORD **)(v188 + 1408) + 164LL));
    }
    return 4294967277LL;
  }
  if ( v76[42] != v76[40] + v77 )
  {
    printk(&unk_3AD91F, "ipa3_init_mem_partition");
    v190 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v191 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v191 )
      {
        ipc_log_string(
          v191,
          "ipa %s:%d APPS HDR PROC CTX SIZE not adjacent to MODEM one!\n",
          "ipa3_init_mem_partition",
          10531);
        v190 = ipa3_ctx;
      }
      v192 = *(_QWORD *)(v190 + 34160);
      if ( v192 )
        ipc_log_string(
          v192,
          "ipa %s:%d APPS HDR PROC CTX SIZE not adjacent to MODEM one!\n",
          "ipa3_init_mem_partition",
          10531);
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v78 = *(_QWORD *)(v3 + 34152);
    if ( v78 )
    {
      ipc_log_string(v78, "ipa %s:%d NAT TBL OFST 0x%x SIZE 0x%x\n", "ipa3_init_mem_partition", 10537, v76[45], v76[46]);
      v3 = ipa3_ctx;
    }
    v79 = *(_QWORD *)(v3 + 34160);
    if ( v79 )
    {
      ipc_log_string(
        v79,
        "ipa %s:%d NAT TBL OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10537,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 180LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 184LL));
      v3 = ipa3_ctx;
    }
  }
  v80 = **(_DWORD ***)(v3 + 34176);
  if ( (v80[45] & 0x1F) != 0 )
  {
    printk(&unk_3CD77F, "ipa3_init_mem_partition");
    v193 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v194 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v194 )
      {
        ipc_log_string(
          v194,
          "ipa %s:%d NAT TBL OFST 0x%x is not aligned properly\n",
          "ipa3_init_mem_partition",
          10541,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 180LL));
        v193 = ipa3_ctx;
      }
      v195 = v193 + 0x8000;
      v196 = *(_QWORD *)(v195 + 1392);
      if ( v196 )
        ipc_log_string(
          v196,
          "ipa %s:%d NAT TBL OFST 0x%x is not aligned properly\n",
          "ipa3_init_mem_partition",
          10541,
          *(unsigned int *)(**(_QWORD **)(v195 + 1408) + 180LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v81 = *(_QWORD *)(v3 + 34152);
    if ( v81 )
    {
      ipc_log_string(
        v81,
        "ipa %s:%d PDN CONFIG OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10547,
        v80[72],
        v80[73]);
      v3 = ipa3_ctx;
    }
    v82 = *(_QWORD *)(v3 + 34160);
    if ( v82 )
    {
      ipc_log_string(
        v82,
        "ipa %s:%d PDN CONFIG OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10547,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 288LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 292LL));
      v3 = ipa3_ctx;
    }
  }
  v83 = **(_DWORD ***)(v3 + 34176);
  if ( (v83[72] & 7) != 0 )
  {
    printk(&unk_3CA6B3, "ipa3_init_mem_partition");
    v197 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967277LL;
    v198 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v198 )
    {
      ipc_log_string(
        v198,
        "ipa %s:%d PDN CONFIG OFST 0x%x is unaligned\n",
        "ipa3_init_mem_partition",
        10551,
        *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 288LL));
      v197 = ipa3_ctx;
    }
    v199 = v197 + 0x8000;
    v182 = *(_QWORD *)(v199 + 1392);
    if ( !v182 )
      return 4294967277LL;
    v183 = *(_QWORD *)(v199 + 1408);
    v184 = "ipa %s:%d PDN CONFIG OFST 0x%x is unaligned\n";
    v185 = 10551;
    goto LABEL_359;
  }
  if ( v3 )
  {
    v84 = *(_QWORD *)(v3 + 34152);
    if ( v84 )
    {
      ipc_log_string(
        v84,
        "ipa %s:%d Q6 QUOTA STATS OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10557,
        v83[74],
        v83[75]);
      v3 = ipa3_ctx;
    }
    v85 = *(_QWORD *)(v3 + 34160);
    if ( v85 )
    {
      ipc_log_string(
        v85,
        "ipa %s:%d Q6 QUOTA STATS OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10557,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 296LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 300LL));
      v3 = ipa3_ctx;
    }
  }
  v86 = **(_DWORD ***)(v3 + 34176);
  if ( (v86[74] & 7) != 0 )
  {
    printk(&unk_3B0680, "ipa3_init_mem_partition");
    v201 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v202 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v202 )
      {
        ipc_log_string(
          v202,
          "ipa %s:%d Q6 QUOTA STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10561,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 296LL));
        v201 = ipa3_ctx;
      }
      v203 = v201 + 0x8000;
      v204 = *(_QWORD *)(v203 + 1392);
      if ( v204 )
        ipc_log_string(
          v204,
          "ipa %s:%d Q6 QUOTA STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10561,
          *(unsigned int *)(**(_QWORD **)(v203 + 1408) + 296LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v87 = *(_QWORD *)(v3 + 34152);
    if ( v87 )
    {
      ipc_log_string(
        v87,
        "ipa %s:%d AP QUOTA STATS OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10567,
        v86[76],
        v86[77]);
      v3 = ipa3_ctx;
    }
    v88 = *(_QWORD *)(v3 + 34160);
    if ( v88 )
    {
      ipc_log_string(
        v88,
        "ipa %s:%d AP QUOTA STATS OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10567,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 304LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 308LL));
      v3 = ipa3_ctx;
    }
  }
  v89 = **(_DWORD ***)(v3 + 34176);
  if ( (v89[76] & 7) != 0 )
  {
    printk(&unk_3C7DBF, "ipa3_init_mem_partition");
    v205 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v206 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v206 )
      {
        ipc_log_string(
          v206,
          "ipa %s:%d AP QUOTA STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10571,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 304LL));
        v205 = ipa3_ctx;
      }
      v207 = v205 + 0x8000;
      v208 = *(_QWORD *)(v207 + 1392);
      if ( v208 )
        ipc_log_string(
          v208,
          "ipa %s:%d AP QUOTA STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10571,
          *(unsigned int *)(**(_QWORD **)(v207 + 1408) + 304LL));
    }
    return 4294967277LL;
  }
  if ( v3 )
  {
    v90 = *(_QWORD *)(v3 + 34152);
    if ( v90 )
    {
      ipc_log_string(
        v90,
        "ipa %s:%d TETHERING STATS OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10577,
        v89[78],
        v89[79]);
      v3 = ipa3_ctx;
    }
    v91 = *(_QWORD *)(v3 + 34160);
    if ( v91 )
    {
      ipc_log_string(
        v91,
        "ipa %s:%d TETHERING STATS OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10577,
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 312LL),
        *(_DWORD *)(**(_QWORD **)(v3 + 34176) + 316LL));
      v3 = ipa3_ctx;
    }
  }
  v92 = **(_DWORD ***)(v3 + 34176);
  if ( (v92[78] & 7) != 0 )
  {
    printk(&unk_3B8D4D, "ipa3_init_mem_partition");
    v209 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v210 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v210 )
      {
        ipc_log_string(
          v210,
          "ipa %s:%d TETHERING STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10581,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 312LL));
        v209 = ipa3_ctx;
      }
      v211 = v209 + 0x8000;
      v212 = *(_QWORD *)(v211 + 1392);
      if ( v212 )
        ipc_log_string(
          v212,
          "ipa %s:%d TETHERING STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10581,
          *(unsigned int *)(**(_QWORD **)(v211 + 1408) + 312LL));
    }
    return 4294967277LL;
  }
  if ( !v3 )
    goto LABEL_180;
  v93 = *(_QWORD *)(v3 + 34152);
  if ( v93 )
    ipc_log_string(
      v93,
      "ipa %s:%d FILTER AND ROUTING STATS OFST 0x%x SIZE 0x%x\n",
      "ipa3_init_mem_partition",
      10587,
      v92[80],
      v92[81]);
  v94 = ipa3_ctx;
  v95 = *(_QWORD *)(ipa3_ctx + 34160);
  if ( v95 )
  {
    ipc_log_string(
      v95,
      "ipa %s:%d FILTER AND ROUTING STATS OFST 0x%x SIZE 0x%x\n",
      "ipa3_init_mem_partition",
      10587,
      *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 320LL),
      *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 324LL));
LABEL_180:
    v94 = ipa3_ctx;
  }
  v96 = **(_DWORD ***)(v94 + 34176);
  if ( (v96[80] & 7) != 0 )
  {
    printk(&unk_3E460D, "ipa3_init_mem_partition");
    v213 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v214 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v214 )
      {
        ipc_log_string(
          v214,
          "ipa %s:%d FILTER AND ROUTING STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10591,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 320LL));
        v213 = ipa3_ctx;
      }
      v215 = v213 + 0x8000;
      v216 = *(_QWORD *)(v215 + 1392);
      if ( v216 )
        ipc_log_string(
          v216,
          "ipa %s:%d FILTER AND ROUTING STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10591,
          *(unsigned int *)(**(_QWORD **)(v215 + 1408) + 320LL));
    }
    return 4294967277LL;
  }
  if ( v94 )
  {
    v97 = *(_QWORD *)(v94 + 34152);
    if ( v97 )
    {
      ipc_log_string(
        v97,
        "ipa %s:%d DROP STATS OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10597,
        v96[92],
        v96[93]);
      v94 = ipa3_ctx;
    }
    v98 = *(_QWORD *)(v94 + 34160);
    if ( v98 )
    {
      ipc_log_string(
        v98,
        "ipa %s:%d DROP STATS OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10597,
        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 368LL),
        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 372LL));
      v94 = ipa3_ctx;
    }
  }
  v99 = **(_DWORD ***)(v94 + 34176);
  if ( (v99[92] & 7) != 0 )
  {
    printk(&unk_3D3A4B, "ipa3_init_mem_partition");
    v217 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v218 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v218 )
      {
        ipc_log_string(
          v218,
          "ipa %s:%d DROP STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10601,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 368LL));
        v217 = ipa3_ctx;
      }
      v219 = v217 + 0x8000;
      v220 = *(_QWORD *)(v219 + 1392);
      if ( v220 )
        ipc_log_string(
          v220,
          "ipa %s:%d DROP STATS OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10601,
          *(unsigned int *)(**(_QWORD **)(v219 + 1408) + 368LL));
    }
    return 4294967277LL;
  }
  if ( v94 )
  {
    v100 = *(_QWORD *)(v94 + 34152);
    if ( v100 )
    {
      ipc_log_string(
        v100,
        "ipa %s:%d V4 APPS HASHABLE FLT OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10607,
        v99[51],
        v99[52]);
      v94 = ipa3_ctx;
    }
    v101 = *(_QWORD *)(v94 + 34160);
    if ( v101 )
    {
      ipc_log_string(
        v101,
        "ipa %s:%d V4 APPS HASHABLE FLT OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10607,
        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 204LL),
        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 208LL));
      v94 = ipa3_ctx;
    }
    if ( v94 )
    {
      v102 = *(_QWORD *)(v94 + 34152);
      if ( v102 )
      {
        ipc_log_string(
          v102,
          "ipa %s:%d V4 APPS NON-HASHABLE FLT OFST 0x%x SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10611,
          *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 212LL),
          *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 216LL));
        v94 = ipa3_ctx;
      }
      v103 = *(_QWORD *)(v94 + 34160);
      if ( v103 )
      {
        ipc_log_string(
          v103,
          "ipa %s:%d V4 APPS NON-HASHABLE FLT OFST 0x%x SIZE 0x%x\n",
          "ipa3_init_mem_partition",
          10611,
          *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 212LL),
          *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 216LL));
        v94 = ipa3_ctx;
      }
      if ( v94 )
      {
        v104 = *(_QWORD *)(v94 + 34152);
        if ( v104 )
        {
          ipc_log_string(
            v104,
            "ipa %s:%d V6 APPS HASHABLE FLT OFST 0x%x SIZE 0x%x\n",
            "ipa3_init_mem_partition",
            10615,
            *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 220LL),
            *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 224LL));
          v94 = ipa3_ctx;
        }
        v105 = *(_QWORD *)(v94 + 34160);
        if ( v105 )
        {
          ipc_log_string(
            v105,
            "ipa %s:%d V6 APPS HASHABLE FLT OFST 0x%x SIZE 0x%x\n",
            "ipa3_init_mem_partition",
            10615,
            *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 220LL),
            *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 224LL));
          v94 = ipa3_ctx;
        }
        if ( v94 )
        {
          v106 = *(_QWORD *)(v94 + 34152);
          if ( v106 )
          {
            ipc_log_string(
              v106,
              "ipa %s:%d V6 APPS NON-HASHABLE FLT OFST 0x%x SIZE 0x%x\n",
              "ipa3_init_mem_partition",
              10619,
              *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 228LL),
              *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 232LL));
            v94 = ipa3_ctx;
          }
          v107 = *(_QWORD *)(v94 + 34160);
          if ( v107 )
          {
            ipc_log_string(
              v107,
              "ipa %s:%d V6 APPS NON-HASHABLE FLT OFST 0x%x SIZE 0x%x\n",
              "ipa3_init_mem_partition",
              10619,
              *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 228LL),
              *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 232LL));
            v94 = ipa3_ctx;
          }
          if ( v94 )
          {
            v108 = *(_QWORD *)(v94 + 34152);
            if ( v108 )
            {
              ipc_log_string(
                v108,
                "ipa %s:%d RAM END OFST 0x%x\n",
                "ipa3_init_mem_partition",
                10622,
                *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 244LL));
              v94 = ipa3_ctx;
            }
            v109 = *(_QWORD *)(v94 + 34160);
            if ( v109 )
            {
              ipc_log_string(
                v109,
                "ipa %s:%d RAM END OFST 0x%x\n",
                "ipa3_init_mem_partition",
                10622,
                *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 244LL));
              v94 = ipa3_ctx;
            }
            if ( v94 )
            {
              v110 = *(_QWORD *)(v94 + 34152);
              if ( v110 )
              {
                ipc_log_string(
                  v110,
                  "ipa %s:%d V4 APPS HASHABLE RT OFST 0x%x SIZE 0x%x\n",
                  "ipa3_init_mem_partition",
                  10626,
                  *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 248LL),
                  *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 252LL));
                v94 = ipa3_ctx;
              }
              v111 = *(_QWORD *)(v94 + 34160);
              if ( v111 )
              {
                ipc_log_string(
                  v111,
                  "ipa %s:%d V4 APPS HASHABLE RT OFST 0x%x SIZE 0x%x\n",
                  "ipa3_init_mem_partition",
                  10626,
                  *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 248LL),
                  *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 252LL));
                v94 = ipa3_ctx;
              }
              if ( v94 )
              {
                v112 = *(_QWORD *)(v94 + 34152);
                if ( v112 )
                {
                  ipc_log_string(
                    v112,
                    "ipa %s:%d V4 APPS NON-HASHABLE RT OFST 0x%x SIZE 0x%x\n",
                    "ipa3_init_mem_partition",
                    10630,
                    *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 256LL),
                    *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 260LL));
                  v94 = ipa3_ctx;
                }
                v113 = *(_QWORD *)(v94 + 34160);
                if ( v113 )
                {
                  ipc_log_string(
                    v113,
                    "ipa %s:%d V4 APPS NON-HASHABLE RT OFST 0x%x SIZE 0x%x\n",
                    "ipa3_init_mem_partition",
                    10630,
                    *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 256LL),
                    *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 260LL));
                  v94 = ipa3_ctx;
                }
                if ( v94 )
                {
                  v114 = *(_QWORD *)(v94 + 34152);
                  if ( v114 )
                  {
                    ipc_log_string(
                      v114,
                      "ipa %s:%d V6 APPS HASHABLE RT OFST 0x%x SIZE 0x%x\n",
                      "ipa3_init_mem_partition",
                      10634,
                      *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 264LL),
                      *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 268LL));
                    v94 = ipa3_ctx;
                  }
                  v115 = *(_QWORD *)(v94 + 34160);
                  if ( v115 )
                  {
                    ipc_log_string(
                      v115,
                      "ipa %s:%d V6 APPS HASHABLE RT OFST 0x%x SIZE 0x%x\n",
                      "ipa3_init_mem_partition",
                      10634,
                      *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 264LL),
                      *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 268LL));
                    v94 = ipa3_ctx;
                  }
                  if ( v94 )
                  {
                    v116 = *(_QWORD *)(v94 + 34152);
                    if ( v116 )
                    {
                      ipc_log_string(
                        v116,
                        "ipa %s:%d V6 APPS NON-HASHABLE RT OFST 0x%x SIZE 0x%x\n",
                        "ipa3_init_mem_partition",
                        10638,
                        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 272LL),
                        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 276LL));
                      v94 = ipa3_ctx;
                    }
                    v117 = *(_QWORD *)(v94 + 34160);
                    if ( v117 )
                    {
                      ipc_log_string(
                        v117,
                        "ipa %s:%d V6 APPS NON-HASHABLE RT OFST 0x%x SIZE 0x%x\n",
                        "ipa3_init_mem_partition",
                        10638,
                        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 272LL),
                        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 276LL));
                      v94 = ipa3_ctx;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v118 = **(_QWORD **)(v94 + 34176);
  v119 = *(_DWORD *)(v118 + 196);
  if ( (v119 & 7) != 0 )
  {
    printk(&unk_3CD81D, "ipa3_init_mem_partition");
    v221 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v222 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v222 )
      {
        ipc_log_string(
          v222,
          "ipa %s:%d MODEM OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10642,
          *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 196LL));
        v221 = ipa3_ctx;
      }
      v223 = v221 + 0x8000;
      v224 = *(_QWORD *)(v223 + 1392);
      if ( v224 )
        ipc_log_string(
          v224,
          "ipa %s:%d MODEM OFST 0x%x is unaligned\n",
          "ipa3_init_mem_partition",
          10642,
          *(unsigned int *)(**(_QWORD **)(v223 + 1408) + 196LL));
    }
    return 4294967277LL;
  }
  if ( v94 )
  {
    v120 = *(_QWORD *)(v94 + 34152);
    if ( v120 )
    {
      ipc_log_string(
        v120,
        "ipa %s:%d MODEM OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10647,
        v119,
        *(_DWORD *)(v118 + 200));
      v94 = ipa3_ctx;
    }
    v121 = *(_QWORD *)(v94 + 34160);
    if ( v121 )
    {
      ipc_log_string(
        v121,
        "ipa %s:%d MODEM OFST 0x%x SIZE 0x%x\n",
        "ipa3_init_mem_partition",
        10647,
        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 196LL),
        *(_DWORD *)(**(_QWORD **)(v94 + 34176) + 200LL));
      v94 = ipa3_ctx;
    }
  }
  v122 = **(_QWORD **)(v94 + 34176);
  v123 = *(_DWORD *)(v122 + 280);
  if ( (v123 & 0x3FF) != 0 )
  {
    printk(&unk_3D3A7A, "ipa3_init_mem_partition");
    v225 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967277LL;
    v226 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v226 )
    {
      ipc_log_string(
        v226,
        "ipa %s:%d UC DESCRIPTOR RAM OFST 0x%x is unaligned\n",
        "ipa3_init_mem_partition",
        10651,
        *(_DWORD *)(**(_QWORD **)(ipa3_ctx + 34176) + 280LL));
      v225 = ipa3_ctx;
    }
    v227 = v225 + 0x8000;
    v182 = *(_QWORD *)(v227 + 1392);
    if ( !v182 )
      return 4294967277LL;
    v184 = "ipa %s:%d UC DESCRIPTOR RAM OFST 0x%x is unaligned\n";
    v185 = 10651;
    v200 = *(unsigned int *)(**(_QWORD **)(v227 + 1408) + 280LL);
LABEL_395:
    ipc_log_string(v182, v184, "ipa3_init_mem_partition", v185, v200);
    return 4294967277LL;
  }
  if ( !v94 )
    return 0;
  v124 = *(_QWORD *)(v94 + 34152);
  if ( v124 )
  {
    ipc_log_string(
      v124,
      "ipa %s:%d UC DESCRIPTOR RAM OFST 0x%x SIZE 0x%x\n",
      "ipa3_init_mem_partition",
      10657,
      v123,
      *(_DWORD *)(v122 + 284));
    v94 = ipa3_ctx;
  }
  v125 = v94 + 0x8000;
  result = *(_QWORD *)(v125 + 1392);
  if ( result )
  {
    ipc_log_string(
      result,
      "ipa %s:%d UC DESCRIPTOR RAM OFST 0x%x SIZE 0x%x\n",
      "ipa3_init_mem_partition",
      10657,
      *(_DWORD *)(**(_QWORD **)(v125 + 1408) + 280LL),
      *(_DWORD *)(**(_QWORD **)(v125 + 1408) + 284LL));
    return 0;
  }
  return result;
}
