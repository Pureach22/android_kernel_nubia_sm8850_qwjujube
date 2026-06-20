_QWORD *__fastcall a6xx_crashdump_init(_QWORD *result)
{
  bool v1; // cc
  int v2; // w10
  int *v3; // x25
  __int64 v4; // x19
  int v5; // w23
  int v6; // w24
  int v7; // w20
  void **v8; // x27
  const char *v9; // x0
  __int64 v10; // x9
  int v11; // w8
  _DWORD *v12; // x8
  __int64 v13; // x10
  int v14; // w11
  unsigned int v15; // w12
  __int64 v16; // x13
  int v17; // w14
  int v18; // w17
  int v19; // w15
  int v20; // w16
  int v21; // w11
  __int64 v22; // x9
  int v23; // w12
  int v24; // w10
  __int64 v25; // x9
  int v26; // w8
  char *v27; // x11
  __int64 v28; // x19
  int v29; // w27
  int v30; // w24
  char *v31; // x21
  const char *v32; // x0
  __int64 v33; // x8
  int v34; // w9
  __int64 v35; // x10
  __int64 v36; // x11
  int v37; // w12
  unsigned int v38; // w13
  __int64 v39; // x14
  int v40; // w15
  int v41; // w0
  int v42; // w16
  int v43; // w17
  unsigned int v44; // w12
  __int64 v45; // x11
  int v46; // w14
  int v47; // w13
  __int64 v48; // x10
  __int64 v49; // x11
  int v50; // w12
  unsigned int v51; // w13
  __int64 v52; // x14
  int v53; // w15
  int v54; // w0
  int v55; // w16
  int v56; // w17
  unsigned int v57; // w12
  __int64 v58; // x11
  int v59; // w14
  int v60; // w13
  __int64 i; // x8
  char *v62; // x11
  __int64 v63; // x10
  __int64 v64; // x12
  __int64 v65; // x13
  int v66; // w14
  unsigned int v67; // w15
  __int64 v68; // x16
  int v69; // w17
  int v70; // w2
  int v71; // w4
  int v72; // w1
  unsigned int v73; // w14
  __int64 v74; // x13
  int v75; // w16
  int v76; // w15
  __int64 v77; // x11
  __int64 v78; // x12
  int v79; // w13
  unsigned int v80; // w14
  __int64 v81; // x15
  int v82; // w16
  int v83; // w1
  int v84; // w17
  int v85; // w2
  unsigned int v86; // w13
  __int64 v87; // x12
  int v88; // w15
  int v89; // w14
  __int64 v90; // x10
  int v91; // w11
  unsigned int v92; // w12
  __int64 v93; // x13
  int v94; // w14
  int v95; // w17
  int v96; // w15
  int v97; // w16
  unsigned int v98; // w11
  __int64 v99; // x10
  int v100; // w13
  int v101; // w12
  __int64 v102; // x11
  int v103; // w12
  unsigned int v104; // w13
  __int64 v105; // x14
  int v106; // w15
  int v107; // w1
  int v108; // w16
  int v109; // w17
  unsigned int v110; // w12
  __int64 v111; // x11
  int v112; // w14
  int v113; // w13
  __int64 v114; // x12
  int v115; // w13
  unsigned int v116; // w14
  __int64 v117; // x15
  int v118; // w16
  int v119; // w1
  int v120; // w17
  int v121; // w2
  unsigned int v122; // w13
  __int64 v123; // x12
  int v124; // w15
  int v125; // w14
  _QWORD *v127; // x27
  __int64 v128; // x19
  char *v129; // x24
  int *v130; // x8
  _UNKNOWN **v131; // x21
  int v132; // w23
  const char *v133; // x0
  unsigned int *v134; // x8
  unsigned __int64 v135; // x8
  unsigned int v136; // w9
  unsigned int v137; // w12
  int v138; // w13
  int v139; // w11
  __int64 v140; // x11
  _QWORD *v141; // x10
  __int64 v142; // x8
  char *v143; // x12
  int v144; // w13
  __int64 v145; // x14
  __int64 v146; // x14
  __int64 v147; // x28
  int v148; // w25
  char *v149; // x19
  int *v150; // x8
  int v151; // w23
  const char *v152; // x21
  __int64 v153; // x8
  int v154; // w9
  int v155; // w8
  int v156; // w8
  unsigned int v157; // w9
  unsigned __int64 v158; // x10
  int v159; // w11
  __int64 v160; // x13
  int v161; // w14
  __int64 v162; // x13
  __int64 v163; // x12
  int v164; // w9
  unsigned int v165; // w9
  unsigned __int64 v166; // x10
  int v167; // w11
  __int64 v168; // x13
  int v169; // w14
  __int64 v170; // x13
  __int64 v171; // x12
  _QWORD *v172; // x19
  __int64 v173; // x9
  int v174; // w12
  __int64 v175; // x8
  char *v176; // x13
  unsigned __int8 v177; // w14
  int v178; // w14
  unsigned __int64 v179; // x15
  int v180; // w16
  unsigned int v181; // w17
  __int64 v182; // x1
  __int64 v183; // x2
  int v184; // w3
  __int64 v185; // x2
  __int64 v186; // x1
  int v187; // w12
  unsigned __int64 v188; // x15
  int v189; // w16
  unsigned int v190; // w17
  __int64 v191; // x1
  __int64 v192; // x2
  int v193; // w3
  __int64 v194; // x2
  __int64 v195; // x1
  _QWORD *v196; // x11
  __int64 v197; // x9
  __int64 v198; // x11
  unsigned __int64 v199; // x10
  unsigned int v200; // w12
  int v201; // w14
  __int64 v202; // x0
  int v203; // w2
  int v204; // w1
  __int64 v205; // x1
  int v206; // w11
  _QWORD *v207; // x10
  int v208; // w10
  __int64 v209; // x13
  unsigned __int64 v210; // x12
  int v211; // w14
  unsigned int v212; // w15
  __int64 v213; // x2
  int v214; // w3
  int v215; // w1
  __int64 v216; // x2
  __int64 v217; // x1
  int v218; // w11
  __int64 v219; // x13
  unsigned __int64 v220; // x12
  int v221; // w14
  unsigned int v222; // w15
  __int64 v223; // x2
  int v224; // w3
  int v225; // w1
  __int64 v226; // x2
  __int64 v227; // x1
  __int64 v228; // x20
  void *v229; // x0
  size_t v230; // x2
  __int64 v231; // x8
  int v232; // [xsp+Ch] [xbp-14h]
  __int64 v233; // [xsp+10h] [xbp-10h]
  _QWORD *v234; // [xsp+18h] [xbp-8h]

  if ( a6xx_capturescript )
    v1 = (unsigned __int64)a6xx_capturescript > 0xFFFFFFFFFFFFF000LL;
  else
    v1 = 1;
  v2 = v1;
  if ( !v1 && a6xx_crashdump_registers && (unsigned __int64)a6xx_crashdump_registers < 0xFFFFFFFFFFFFF001LL )
    return result;
  v3 = (int *)result[1783];
  v4 = 0;
  v5 = 0;
  v6 = 0;
  v7 = *v3;
  v232 = v2;
  v233 = a6xx_capturescript;
  v234 = result;
  do
  {
    v8 = (void **)(&a6xx_reg_list + 4 * v4);
    if ( v7 == 660
      || (v9 = *((const char **)v3 + 3)) != nullptr && !strcmp(v9, "qcom,adreno-gpu-a642l")
      || v7 == 643
      || v7 == 662
      || *v8 != &a660_registers )
    {
      v10 = *((unsigned int *)v8 + 2);
      v11 = v8[2] ? v5 + 16 : v5;
      v5 = v11 + 16 * v10;
      if ( (_DWORD)v10 )
      {
        v12 = *v8;
        if ( (_DWORD)v10 == 1 )
        {
          v13 = 0;
LABEL_26:
          v21 = 2 * v13;
          v22 = v10 - v13;
          do
          {
            v23 = v12[v21];
            --v22;
            v24 = v12[v21 + 1];
            v21 += 2;
            v6 += 4 * (v24 - v23) + 4;
          }
          while ( v22 );
          goto LABEL_10;
        }
        v13 = (unsigned int)v10 & 0xFFFFFFFE;
        v14 = 0;
        v15 = 3;
        v16 = v13;
        do
        {
          v17 = v12[v15 - 2];
          v18 = v12[v15];
          v19 = v12[v15 - 3];
          v20 = v12[v15 - 1];
          v16 -= 2;
          v15 += 4;
          v6 += 4 * (v17 - v19) + 4;
          v14 += 4 * (v18 - v20) + 4;
        }
        while ( v16 );
        v6 += v14;
        if ( v13 != v10 )
          goto LABEL_26;
      }
    }
LABEL_10:
    ++v4;
  }
  while ( v4 != 4 );
  v25 = 0;
  v26 = 0;
  do
  {
    v27 = (char *)&a6xx_shader_blocks + v25;
    v25 += 32;
    v6 += 12 * *((_DWORD *)v27 + 1);
    v26 += 12 * *((_DWORD *)v27 + 5);
  }
  while ( v25 != 704 );
  v28 = 0;
  v29 = v26 + v6 + 12 * dword_B7CC;
  v30 = v5 + 4320;
  do
  {
    v31 = (char *)&a6xx_clusters + 40 * v28;
    if ( v7 == 660
      || (v32 = *((const char **)v3 + 3)) != nullptr && !strcmp(v32, "qcom,adreno-gpu-a642l")
      || v7 == 643
      || v7 == 662
      || *((_UNKNOWN **)v31 + 1) != &a660_fe_cluster )
    {
      v33 = *((unsigned int *)v31 + 4);
      if ( *((_QWORD *)v31 + 3) )
        v34 = v30 + 16;
      else
        v34 = v30;
      if ( !(_DWORD)v33 )
        goto LABEL_56;
      v35 = *((_QWORD *)v31 + 1);
      if ( (_DWORD)v33 == 1 )
      {
        v36 = 0;
      }
      else
      {
        v36 = (unsigned int)v33 & 0xFFFFFFFE;
        v37 = 0;
        v38 = 3;
        v39 = v36;
        do
        {
          v40 = *(_DWORD *)(v35 + 4LL * (v38 - 2));
          v41 = *(_DWORD *)(v35 + 4LL * v38);
          v42 = *(_DWORD *)(v35 + 4LL * (v38 - 3));
          v43 = *(_DWORD *)(v35 + 4LL * (v38 - 1));
          v39 -= 2;
          v38 += 4;
          v29 += 4 * (v40 - v42) + 4;
          v37 += 4 * (v41 - v43) + 4;
        }
        while ( v39 );
        v29 += v37;
        if ( v36 == v33 )
        {
LABEL_49:
          v48 = *((_QWORD *)v31 + 1);
          if ( (_DWORD)v33 == 1 )
          {
            v49 = 0;
          }
          else
          {
            v49 = (unsigned int)v33 & 0xFFFFFFFE;
            v50 = 0;
            v51 = 3;
            v52 = v49;
            do
            {
              v53 = *(_DWORD *)(v48 + 4LL * (v51 - 2));
              v54 = *(_DWORD *)(v48 + 4LL * v51);
              v55 = *(_DWORD *)(v48 + 4LL * (v51 - 3));
              v56 = *(_DWORD *)(v48 + 4LL * (v51 - 1));
              v52 -= 2;
              v51 += 4;
              v29 += 4 * (v53 - v55) + 4;
              v50 += 4 * (v54 - v56) + 4;
            }
            while ( v52 );
            v29 += v50;
            if ( v49 == v33 )
              goto LABEL_56;
          }
          v57 = 2 * v49;
          v58 = v33 - v49;
          do
          {
            v59 = *(_DWORD *)(v48 + 4LL * v57);
            --v58;
            v60 = *(_DWORD *)(v48 + 4LL * (v57 + 1));
            v57 += 2;
            v29 += 4 * (v60 - v59) + 4;
          }
          while ( v58 );
LABEL_56:
          v30 = v34 + 32 * v33 + 32;
          goto LABEL_57;
        }
      }
      v44 = 2 * v36;
      v45 = v33 - v36;
      do
      {
        v46 = *(_DWORD *)(v35 + 4LL * v44);
        --v45;
        v47 = *(_DWORD *)(v35 + 4LL * (v44 + 1));
        v44 += 2;
        v29 += 4 * (v47 - v46) + 4;
      }
      while ( v45 );
      goto LABEL_49;
    }
LABEL_57:
    ++v28;
  }
  while ( v28 != 7 );
  result = (_QWORD *)v233;
  for ( i = 0; i != 13; ++i )
  {
    v62 = (char *)&a6xx_dbgahb_ctx_clusters + 40 * i;
    v63 = *((unsigned int *)v62 + 6);
    if ( !(_DWORD)v63 )
      goto LABEL_59;
    v64 = *((_QWORD *)v62 + 2);
    if ( (_DWORD)v63 == 1 )
    {
      v65 = 0;
LABEL_66:
      v73 = 2 * v65;
      v74 = v63 - v65;
      do
      {
        v75 = *(_DWORD *)(v64 + 4LL * v73);
        --v74;
        v76 = *(_DWORD *)(v64 + 4LL * (v73 + 1));
        v73 += 2;
        v29 += 4 * (v76 - v75) + 4;
      }
      while ( v74 );
      goto LABEL_68;
    }
    v65 = (unsigned int)v63 & 0xFFFFFFFE;
    v66 = 0;
    v67 = 3;
    v68 = v65;
    do
    {
      v69 = *(_DWORD *)(v64 + 4LL * (v67 - 2));
      v70 = *(_DWORD *)(v64 + 4LL * v67);
      v71 = *(_DWORD *)(v64 + 4LL * (v67 - 3));
      v72 = *(_DWORD *)(v64 + 4LL * (v67 - 1));
      v68 -= 2;
      v67 += 4;
      v29 += 4 * (v69 - v71) + 4;
      v66 += 4 * (v70 - v72) + 4;
    }
    while ( v68 );
    v29 += v66;
    if ( v65 != v63 )
      goto LABEL_66;
LABEL_68:
    v77 = *((_QWORD *)v62 + 2);
    if ( (_DWORD)v63 == 1 )
    {
      v78 = 0;
LABEL_73:
      v86 = 2 * v78;
      v87 = v63 - v78;
      do
      {
        v88 = *(_DWORD *)(v77 + 4LL * v86);
        --v87;
        v89 = *(_DWORD *)(v77 + 4LL * (v86 + 1));
        v86 += 2;
        v29 += 4 * (v89 - v88) + 4;
      }
      while ( v87 );
      goto LABEL_59;
    }
    v78 = (unsigned int)v63 & 0xFFFFFFFE;
    v79 = 0;
    v80 = 3;
    v81 = v78;
    do
    {
      v82 = *(_DWORD *)(v77 + 4LL * (v80 - 2));
      v83 = *(_DWORD *)(v77 + 4LL * v80);
      v84 = *(_DWORD *)(v77 + 4LL * (v80 - 3));
      v85 = *(_DWORD *)(v77 + 4LL * (v80 - 1));
      v81 -= 2;
      v80 += 4;
      v29 += 4 * (v82 - v84) + 4;
      v79 += 4 * (v83 - v85) + 4;
    }
    while ( v81 );
    v29 += v79;
    if ( v78 != v63 )
      goto LABEL_73;
LABEL_59:
    v30 += 32 * v63 + 32;
  }
  if ( dword_B7E8 )
  {
    if ( dword_B7E8 == 1 )
    {
      v90 = 0;
      goto LABEL_85;
    }
    v90 = dword_B7E8 & 0xFFFFFFFE;
    v91 = 0;
    v92 = 3;
    v93 = v90;
    do
    {
      v94 = *((_DWORD *)off_B7E0 + v92 - 2);
      v95 = *((_DWORD *)off_B7E0 + v92);
      v96 = *((_DWORD *)off_B7E0 + v92 - 3);
      v97 = *((_DWORD *)off_B7E0 + v92 - 1);
      v93 -= 2;
      v92 += 4;
      v29 += 4 * (v94 - v96) + 4;
      v91 += 4 * (v95 - v97) + 4;
    }
    while ( v93 );
    v29 += v91;
    if ( v90 != dword_B7E8 )
    {
LABEL_85:
      v98 = 2 * v90;
      v99 = (unsigned int)dword_B7E8 - v90;
      do
      {
        v100 = *((_DWORD *)off_B7E0 + v98);
        --v99;
        v101 = *((_DWORD *)off_B7E0 + v98 + 1);
        v98 += 2;
        v29 += 4 * (v101 - v100) + 4;
      }
      while ( v99 );
    }
  }
  if ( dword_B800 )
  {
    if ( dword_B800 == 1 )
    {
      v102 = 0;
      goto LABEL_93;
    }
    v102 = dword_B800 & 0xFFFFFFFE;
    v103 = 0;
    v104 = 3;
    v105 = v102;
    do
    {
      v106 = *((_DWORD *)off_B7F8 + v104 - 2);
      v107 = *((_DWORD *)off_B7F8 + v104);
      v108 = *((_DWORD *)off_B7F8 + v104 - 3);
      v109 = *((_DWORD *)off_B7F8 + v104 - 1);
      v105 -= 2;
      v104 += 4;
      v29 += 4 * (v106 - v108) + 4;
      v103 += 4 * (v107 - v109) + 4;
    }
    while ( v105 );
    v29 += v103;
    if ( v102 != dword_B800 )
    {
LABEL_93:
      v110 = 2 * v102;
      v111 = (unsigned int)dword_B800 - v102;
      do
      {
        v112 = *((_DWORD *)off_B7F8 + v110);
        --v111;
        v113 = *((_DWORD *)off_B7F8 + v110 + 1);
        v110 += 2;
        v29 += 4 * (v113 - v112) + 4;
      }
      while ( v111 );
    }
  }
  if ( dword_B818 )
  {
    if ( dword_B818 == 1 )
    {
      v114 = 0;
      goto LABEL_101;
    }
    v114 = dword_B818 & 0xFFFFFFFE;
    v115 = 0;
    v116 = 3;
    v117 = v114;
    do
    {
      v118 = *((_DWORD *)off_B810 + v116 - 2);
      v119 = *((_DWORD *)off_B810 + v116);
      v120 = *((_DWORD *)off_B810 + v116 - 3);
      v121 = *((_DWORD *)off_B810 + v116 - 1);
      v117 -= 2;
      v116 += 4;
      v29 += 4 * (v118 - v120) + 4;
      v115 += 4 * (v119 - v121) + 4;
    }
    while ( v117 );
    v29 += v115;
    if ( v114 != dword_B818 )
    {
LABEL_101:
      v122 = 2 * v114;
      v123 = (unsigned int)dword_B818 - v114;
      do
      {
        v124 = *((_DWORD *)off_B810 + v122);
        --v123;
        v125 = *((_DWORD *)off_B810 + v122 + 1);
        v122 += 2;
        v29 += 4 * (v125 - v124) + 4;
      }
      while ( v123 );
    }
  }
  if ( v232 )
  {
    result = (_QWORD *)kgsl_allocate_global(
                         v234,
                         (unsigned int)(v30 + 16 * dword_B7E8 + 16 + 16 * dword_B800 + 16 + 16 * dword_B818 + 48),
                         0,
                         0x1000000,
                         64,
                         "capturescript");
    a6xx_capturescript = (__int64)result;
    if ( (unsigned __int64)result >= 0xFFFFFFFFFFFFF001LL )
      return result;
  }
  if ( !a6xx_crashdump_registers || (unsigned __int64)a6xx_crashdump_registers >= 0xFFFFFFFFFFFFF001LL )
  {
    result = (_QWORD *)kgsl_allocate_global(v234, (unsigned int)(v29 + 4), 0, 0, 64, "capturescript_regs");
    a6xx_crashdump_registers = (__int64)result;
    if ( (unsigned __int64)result >= 0xFFFFFFFFFFFFF001LL && (unsigned int)result != 0 )
      return result;
    result = (_QWORD *)a6xx_capturescript;
  }
  v127 = (_QWORD *)result[1];
  v128 = 0;
  v129 = nullptr;
  do
  {
    v130 = (int *)v234[1783];
    v131 = &a6xx_reg_list + 4 * v128;
    v132 = *v130;
    if ( *v130 == 660
      || (v133 = *((const char **)v130 + 3)) != nullptr && !strcmp(v133, "qcom,adreno-gpu-a642l")
      || v132 == 643
      || v132 == 662
      || *v131 != &a660_registers )
    {
      v134 = (unsigned int *)v131[2];
      v131[3] = v129;
      if ( v134 )
      {
        *v127 = v134[2];
        v127[1] = ((unsigned __int64)*((unsigned int *)v131[2] + 1) << 44) | 0x200001;
        v127 += 2;
      }
      if ( *((_DWORD *)v131 + 2) )
      {
        v135 = 0;
        v136 = 1;
        do
        {
          v137 = v136 - 1;
          ++v135;
          v138 = *((_DWORD *)*v131 + v136);
          v139 = *((_DWORD *)*v131 + v136 - 1);
          v136 += 2;
          *v127 = &v129[*(_QWORD *)(a6xx_crashdump_registers + 24)];
          v140 = (unsigned int)(v138 - v139 + 1);
          v129 += 4 * (unsigned int)v140;
          v127[1] = v140 | ((unsigned __int64)*((unsigned int *)*v131 + v137) << 44);
          v141 = v127 + 2;
          v127 += 2;
        }
        while ( v135 < *((unsigned int *)v131 + 2) );
        v127 = v141;
      }
    }
    ++v128;
  }
  while ( v128 != 4 );
  v142 = 0;
  do
  {
    v143 = (char *)&a6xx_shader_blocks + v142;
    v142 += 16;
    *v127 = (unsigned int)(*(_DWORD *)v143 << 8);
    v127[1] = 0xD00000000200001LL;
    v127[2] = &v129[*(_QWORD *)(a6xx_crashdump_registers + 24)];
    v127[3] = *((unsigned int *)v143 + 1) | 0xC80000000000000LL;
    v144 = *(_DWORD *)v143;
    v145 = *((unsigned int *)v143 + 1);
    *((_QWORD *)v143 + 1) = v129;
    v127[4] = (v144 << 8) | 1u;
    v127[5] = 0xD00000000200001LL;
    v127[6] = &v129[4 * v145 + *(_QWORD *)(a6xx_crashdump_registers + 24)];
    v127[7] = *((unsigned int *)v143 + 1) | 0xC80000000000000LL;
    v146 = *((unsigned int *)v143 + 1) + v145;
    v127[8] = (*(_DWORD *)v143 << 8) | 2u;
    v127[9] = 0xD00000000200001LL;
    v127[10] = &v129[4 * v146 + *(_QWORD *)(a6xx_crashdump_registers + 24)];
    v127[11] = *((unsigned int *)v143 + 1) | 0xC80000000000000LL;
    v127 += 12;
    v129 += 4 * v146 + 4 * *((unsigned int *)v143 + 1);
  }
  while ( v142 != 720 );
  v147 = 0;
  v148 = 0;
  while ( 2 )
  {
    v149 = (char *)&a6xx_clusters + 40 * v147;
    v150 = (int *)v234[1783];
    v151 = *v150;
    if ( *v150 == 660 )
      goto LABEL_143;
    v152 = *((const char **)v150 + 3);
    if ( v152 && !strcmp(*((const char **)v150 + 3), "qcom,adreno-gpu-a642l") )
    {
LABEL_137:
      if ( v151 != 620 && v151 != 650 )
      {
LABEL_139:
        if ( (!v152 || strcmp(v152, "qcom,adreno-gpu-a642l"))
          && ((unsigned int)(v151 - 621) > 0x2A || ((1LL << ((unsigned __int8)v151 - 109)) & 0x60000400003LL) == 0) )
        {
          goto LABEL_144;
        }
      }
LABEL_143:
      if ( *((_UNKNOWN **)v149 + 1) == &a6xx_vpc_ps_cluster )
      {
        *(_DWORD *)v149 = 6;
        v153 = *((_QWORD *)v149 + 3);
        if ( !v153 )
          goto LABEL_146;
        goto LABEL_145;
      }
LABEL_144:
      v153 = *((_QWORD *)v149 + 3);
      if ( !v153 )
      {
LABEL_146:
        v155 = *(_DWORD *)v149;
        *((_DWORD *)v149 + 8) = (_DWORD)v129;
        v127[v148 + 1] = 0xA0300000200001LL;
        v127[v148] = (unsigned int)(v155 << 8);
        v156 = v148 + 2;
        if ( *((_DWORD *)v149 + 4) )
        {
          v157 = 0;
          v158 = 0;
          v159 = v148 + 3;
          do
          {
            v160 = *((_QWORD *)v149 + 1);
            ++v158;
            v161 = *(_DWORD *)(v160 + 4LL * (v157 + 1));
            LODWORD(v160) = *(_DWORD *)(v160 + 4LL * v157);
            v127[v156] = &v129[*(_QWORD *)(a6xx_crashdump_registers + 24)];
            v162 = (unsigned int)(v161 - v160 + 1);
            v156 += 2;
            v129 += 4 * (unsigned int)v162;
            v163 = *(unsigned int *)(*((_QWORD *)v149 + 1) + 4LL * v157);
            v157 += 2;
            v127[v159] = v162 | (v163 << 44);
            v159 += 2;
          }
          while ( v158 < *((unsigned int *)v149 + 4) );
          v156 = v148 + v157 + 2;
        }
        v164 = *(_DWORD *)v149;
        *((_DWORD *)v149 + 9) = (_DWORD)v129;
        v148 = v156 + 2;
        v127[v156] = (v164 << 8) | 0x11u;
        v127[v156 + 1] = 0xA0300000200001LL;
        if ( *((_DWORD *)v149 + 4) )
        {
          v165 = 0;
          v166 = 0;
          v167 = v156 + 3;
          do
          {
            v168 = *((_QWORD *)v149 + 1);
            ++v166;
            v169 = *(_DWORD *)(v168 + 4LL * (v165 + 1));
            LODWORD(v168) = *(_DWORD *)(v168 + 4LL * v165);
            v127[v148] = &v129[*(_QWORD *)(a6xx_crashdump_registers + 24)];
            v170 = (unsigned int)(v169 - v168 + 1);
            v148 += 2;
            v129 += 4 * (unsigned int)v170;
            v171 = *(unsigned int *)(*((_QWORD *)v149 + 1) + 4LL * v165);
            v165 += 2;
            v127[v167] = v170 | (v171 << 44);
            v167 += 2;
          }
          while ( v166 < *((unsigned int *)v149 + 4) );
          v148 = v156 + v165 + 2;
        }
        goto LABEL_130;
      }
LABEL_145:
      v154 = v148 + 1;
      v127[v148] = *(unsigned int *)(v153 + 8);
      v148 += 2;
      v127[v154] = ((unsigned __int64)*(unsigned int *)(*((_QWORD *)v149 + 3) + 4LL) << 44) | 0x200001;
      goto LABEL_146;
    }
    if ( v151 == 643 || v151 == 662 )
      goto LABEL_139;
    if ( *((_UNKNOWN **)v149 + 1) != &a660_fe_cluster )
      goto LABEL_137;
LABEL_130:
    if ( ++v147 != 7 )
      continue;
    break;
  }
  if ( *(_DWORD *)v234[1783] == 663 )
  {
    v172 = &v127[v148];
  }
  else
  {
    v173 = 0;
    v174 = 0;
    v175 = v148;
    do
    {
      v176 = (char *)&a6xx_dbgahb_ctx_clusters + 40 * v173;
      v177 = *((_DWORD *)v176 + 2);
      *((_DWORD *)v176 + 7) = (_DWORD)v129;
      v127[v174 + v175] = (unsigned __int64)v177 << 8;
      v178 = v174 + 2;
      v127[v174 + 1 + v175] = 0xD00000000200001LL;
      if ( *((_DWORD *)v176 + 6) )
      {
        v179 = 0;
        v180 = v174 + 3;
        v181 = 1;
        do
        {
          v182 = *((_QWORD *)v176 + 2);
          v183 = v175 * 8 + 8LL * v178;
          ++v179;
          v178 += 2;
          v184 = *(_DWORD *)(v182 + 4LL * (v181 - 1));
          LODWORD(v182) = *(_DWORD *)(v182 + 4LL * v181);
          v181 += 2;
          *(_QWORD *)((char *)v127 + v183) = &v129[*(_QWORD *)(a6xx_crashdump_registers + 24)];
          v185 = v175 * 8 + 8LL * v180;
          v186 = (unsigned int)(v182 - v184 + 1);
          v129 += 4 * (unsigned int)v186;
          v180 += 2;
          *(_QWORD *)((char *)v127 + v185) = v186
                                           | ((unsigned __int64)(unsigned int)(v184
                                                                             - (*((_DWORD *)v176 + 1) >> 2)
                                                                             + 51200) << 44);
        }
        while ( v179 < *((unsigned int *)v176 + 6) );
        v178 = v174 + v181 + 1;
      }
      v187 = *((_DWORD *)v176 + 2);
      *((_DWORD *)v176 + 8) = (_DWORD)v129;
      v127[v178 + v175] = (unsigned __int16)(((_WORD)v187 << 8) + 512) & 0xFF00;
      v127[v178 + 1 + v175] = 0xD00000000200001LL;
      v174 = v178 + 2;
      if ( *((_DWORD *)v176 + 6) )
      {
        v188 = 0;
        v189 = v178 + 3;
        v190 = 1;
        do
        {
          v191 = *((_QWORD *)v176 + 2);
          v192 = v175 * 8 + 8LL * v174;
          ++v188;
          v174 += 2;
          v193 = *(_DWORD *)(v191 + 4LL * (v190 - 1));
          LODWORD(v191) = *(_DWORD *)(v191 + 4LL * v190);
          v190 += 2;
          *(_QWORD *)((char *)v127 + v192) = &v129[*(_QWORD *)(a6xx_crashdump_registers + 24)];
          v194 = v175 * 8 + 8LL * v189;
          v195 = (unsigned int)(v191 - v193 + 1);
          v129 += 4 * (unsigned int)v195;
          v189 += 2;
          *(_QWORD *)((char *)v127 + v194) = v195
                                           | ((unsigned __int64)(unsigned int)(v193
                                                                             - (*((_DWORD *)v176 + 1) >> 2)
                                                                             + 51200) << 44);
        }
        while ( v188 < *((unsigned int *)v176 + 6) );
        v174 = v178 + v190 + 1;
      }
      ++v173;
    }
    while ( v173 != 13 );
    dword_B7EC = (int)v129;
    v196 = &v127[v174 + v175];
    *v196 = (unsigned __int64)(unsigned __int8)dword_B7DC << 8;
    v196[1] = 0xD00000000200001LL;
    v197 = v174;
    if ( dword_B7E8 )
    {
      v198 = v175 * 8 + 8LL * v174;
      v199 = 0;
      v200 = 1;
      v201 = 2;
      do
      {
        v202 = 8LL * v201;
        ++v199;
        v201 += 2;
        v203 = *((_DWORD *)off_B7E0 + v200 - 1);
        v204 = *((_DWORD *)off_B7E0 + v200);
        v200 += 2;
        *(_QWORD *)((char *)v127 + v198 + v202) = &v129[*(_QWORD *)(a6xx_crashdump_registers + 24)];
        v205 = (unsigned int)(v204 - v203 + 1);
        v129 += 4 * (unsigned int)v205;
        *(_QWORD *)((char *)v127 + v198 + v202 + 8) = v205
                                                    | ((unsigned __int64)(v203
                                                                        - ((unsigned int)a6xx_non_ctx_dbgahb >> 2)
                                                                        + 51200) << 44);
      }
      while ( v199 < (unsigned int)dword_B7E8 );
      v206 = v200 + 1;
    }
    else
    {
      v206 = 2;
    }
    dword_B804 = (int)v129;
    v207 = &v127[v206 + v197 + v175];
    *v207 = (unsigned __int64)(unsigned __int8)dword_B7F4 << 8;
    v207[1] = 0xD00000000200001LL;
    v208 = v206 + 2;
    if ( dword_B800 )
    {
      v209 = v175 * 8 + 8 * v197;
      v210 = 0;
      v211 = v206 + 3;
      v212 = 1;
      do
      {
        v213 = v209 + 8LL * v208;
        ++v210;
        v208 += 2;
        v214 = *((_DWORD *)off_B7F8 + v212 - 1);
        v215 = *((_DWORD *)off_B7F8 + v212);
        v212 += 2;
        *(_QWORD *)((char *)v127 + v213) = &v129[*(_QWORD *)(a6xx_crashdump_registers + 24)];
        v216 = v209 + 8LL * v211;
        v217 = (unsigned int)(v215 - v214 + 1);
        v129 += 4 * (unsigned int)v217;
        v211 += 2;
        *(_QWORD *)((char *)v127 + v216) = v217
                                         | ((unsigned __int64)(v214 - ((unsigned int)dword_B7F0 >> 2) + 51200) << 44);
      }
      while ( v210 < (unsigned int)dword_B800 );
      v208 = v206 + v212 + 1;
    }
    dword_B81C = (int)v129;
    v127[v208 + v197 + v175] = (unsigned __int64)(unsigned __int8)dword_B80C << 8;
    v127[v208 + 1 + v197 + v175] = 0xD00000000200001LL;
    v218 = v208 + 2;
    if ( dword_B818 )
    {
      v219 = v175 * 8 + 8 * v197;
      v220 = 0;
      v221 = v208 + 3;
      v222 = 1;
      do
      {
        v223 = v219 + 8LL * v218;
        ++v220;
        v218 += 2;
        v224 = *((_DWORD *)off_B810 + v222 - 1);
        v225 = *((_DWORD *)off_B810 + v222);
        v222 += 2;
        *(_QWORD *)((char *)v127 + v223) = &v129[*(_QWORD *)(a6xx_crashdump_registers + 24)];
        v226 = v219 + 8LL * v221;
        v227 = (unsigned int)(v225 - v224 + 1);
        v129 += 4 * (unsigned int)v227;
        v221 += 2;
        *(_QWORD *)((char *)v127 + v226) = v227
                                         | ((unsigned __int64)(v224 - ((unsigned int)dword_B808 >> 2) + 51200) << 44);
      }
      while ( v220 < (unsigned int)dword_B818 );
      v218 = v208 + v222 + 1;
    }
    v172 = &v127[v218 + v197 + v175];
  }
  v228 = a6xx_crashdump_registers;
  v229 = *(void **)(a6xx_crashdump_registers + 8);
  v230 = *(_QWORD *)(a6xx_crashdump_registers + 40);
  a6xx_cd_reg_end = (__int64)&v129[(_QWORD)v229];
  result = memset(v229, 170, v230);
  v231 = *(_QWORD *)(v228 + 24);
  v172[2] = 0;
  v172[3] = 0;
  *v172 = &v129[v231];
  v172[1] = 0x90300000000001LL;
  return result;
}
