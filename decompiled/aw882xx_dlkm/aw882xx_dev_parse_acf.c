__int64 __fastcall aw882xx_dev_parse_acf(__int64 a1, _DWORD *a2)
{
  __int64 *v4; // x9
  __int64 v5; // x8
  __int64 *v6; // x8
  __int64 v7; // x1
  __int64 v8; // x2
  _DWORD *v9; // x21
  __int64 *v10; // x8
  __int64 v11; // x1
  __int64 v12; // x24
  unsigned int v13; // w23
  int v14; // w22
  char *v15; // x24
  int v16; // w0
  __int64 v17; // x8
  char *v18; // x2
  int v19; // w0
  __int64 *v20; // x8
  int v21; // w21
  __int64 v22; // x1
  void *v23; // x0
  unsigned int v24; // w9
  _DWORD *v25; // x23
  __int64 result; // x0
  unsigned int v27; // w10
  char *v28; // x8
  char *v29; // x12
  __int64 v30; // x13
  __int64 *v31; // x8
  __int64 v32; // x1
  __int64 *v33; // x8
  __int64 v34; // x1
  unsigned int v35; // w21
  int v36; // w21
  __int64 *v37; // x8
  __int64 v38; // x1
  __int64 v39; // x0
  __int64 *v40; // x8
  __int64 v41; // x1
  __int64 *v42; // x8
  __int64 v43; // x1
  __int64 *v44; // x8
  __int64 v45; // x1
  __int64 *v46; // x8
  __int64 v47; // x1
  __int64 v48; // x24
  unsigned int v49; // w8
  int v50; // w23
  int v51; // w22
  char *v52; // x24
  int v53; // w0
  char *v54; // x2
  int v55; // w0
  __int64 *v56; // x8
  __int64 *v57; // x8
  __int64 v58; // x1
  int v59; // w8
  __int64 *v60; // x8
  __int64 v61; // x1
  __int64 v62; // x23
  unsigned int v63; // w8
  __int64 *v64; // x8
  __int64 v65; // x1
  __int64 *v66; // x8
  __int64 v67; // x1
  __int64 *v68; // x8
  __int64 v69; // x1
  __int64 *v70; // x8
  __int64 v71; // x1
  __int64 v72; // x22
  int v73; // w8
  int v74; // w9
  unsigned int v75; // w12
  char *v76; // x25
  char *v77; // x13
  int v78; // w14
  __int64 v79; // x13
  unsigned int v80; // w15
  __int64 v81; // x14
  unsigned __int64 v82; // x16
  __int64 v83; // x15
  unsigned int v84; // w14
  unsigned __int64 v85; // x17
  unsigned int v86; // w12
  int v87; // w0
  unsigned int v88; // w26
  int v89; // w22
  char *v90; // x27
  char *v91; // x9
  unsigned __int64 v92; // x8
  __int64 *v93; // x10
  __int64 v94; // x1
  __int64 v95; // x23
  int v96; // w25
  unsigned __int64 v97; // x24
  __int64 v98; // x0
  __int64 v99; // x8
  unsigned int v100; // w3
  _DWORD *v101; // x9
  __int64 v102; // x11
  __int64 v103; // x13
  _QWORD *v104; // x10
  __int64 v105; // x14
  __int64 v106; // x12
  __int64 v107; // x12
  __int64 *v108; // x8
  __int64 v109; // x1
  __int64 *v110; // x8
  __int64 v111; // x1
  void *v112; // x0
  const char *v113; // x2
  __int64 *v114; // x8
  __int64 v115; // x1
  void *v116; // x0
  int v117; // w3
  unsigned int i; // w10
  char *v119; // x12
  int v120; // w3
  unsigned int j; // w10
  char *v122; // x12
  __int64 v123; // x13
  __int64 v124; // x28
  __int64 v125; // x27
  int v126; // w26
  __int64 v127; // x21
  unsigned int v128; // w0
  char *v129; // x24
  int v130; // w8
  unsigned int v131; // w0
  unsigned int v132; // w0
  __int64 *v133; // x8
  __int64 v134; // x1
  __int64 v135; // x21
  int v136; // w23
  __int64 v137; // x9
  __int64 v138; // x8
  __int64 *v139; // x8
  __int64 v140; // x1
  __int64 *v141; // x8
  const char *v142; // x2
  __int64 *v143; // x8
  __int64 v144; // x1
  __int64 v145; // x21
  unsigned int v146; // w8
  __int64 v147; // x22
  __int64 *v148; // x0
  __int64 v149; // x1
  int v150; // w3
  unsigned int k; // w10
  char *v152; // x12
  __int64 *v153; // x8
  __int64 *v154; // x8
  __int64 v155; // x1
  __int64 *v156; // x8
  __int64 *v157; // x8
  __int64 v158; // x1
  void *v159; // x0
  __int64 *v160; // x8
  __int64 *v161; // x8
  int v162; // w25
  char *v163; // x26
  __int64 v164; // x0
  __int64 *v165; // x8
  __int64 v166; // x1
  __int64 *v167; // x8
  int v168; // w23
  char *v169; // x21
  char *v170; // x27
  int v171; // w21
  __int64 v172; // x22
  int v173; // w8
  int v174; // w24
  __int64 v175; // x28
  const char *v176; // x0
  __int64 *v177; // x8
  __int64 v178; // x1
  __int64 *v179; // x8
  __int64 v180; // x1
  __int64 *v181; // x8
  __int64 v182; // x1
  void *v183; // x0
  __int64 *v184; // x8
  int v185; // w8
  int v186; // w23
  __int64 v187; // x9
  __int64 *v188; // x8
  __int64 v189; // x1
  __int64 *v190; // x8
  __int64 v191; // x1
  __int64 *v192; // x8
  __int64 *v193; // x8
  _DWORD *v194; // [xsp+0h] [xbp-5A0h]
  __int64 v195; // [xsp+8h] [xbp-598h]
  _DWORD dest[176]; // [xsp+10h] [xbp-590h] BYREF
  _QWORD s[90]; // [xsp+2D0h] [xbp-2D0h] BYREF

  s[88] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(a1 + 112);
  v5 = v4[14];
  if ( !v5 )
    v5 = *v4;
  printk(&unk_26EB3, v5, "aw882xx_dev_parse_acf");
  v6 = *(__int64 **)(a1 + 112);
  v7 = v6[14];
  if ( !v7 )
    v7 = *v6;
  printk(&unk_2512C, v7, "aw882xx_dev_parse_acf");
  v8 = (unsigned int)a2[17];
  if ( (_DWORD)v8 == 0x1000000 )
  {
    v24 = a2[15];
    v25 = a2 + 1;
    if ( v24 )
    {
      v27 = 0;
      v28 = (char *)v25 + (unsigned int)a2[16];
      do
      {
        v29 = &v28[96 * v27];
        if ( (*((_DWORD *)v29 + 7) | 4) == 4 && !*(_DWORD *)v29 )
        {
          v30 = *(_QWORD *)(a1 + 120);
          if ( *(_DWORD *)(*(_QWORD *)(v30 + 24) + 1032LL) == *((unsigned __int16 *)v29 + 11)
            && *(unsigned __int16 *)(v30 + 2) == *((unsigned __int16 *)v29 + 12)
            && *(_DWORD *)(a1 + 4) == *((_DWORD *)v29 + 19) )
          {
            ++*(_DWORD *)(a1 + 624);
            v24 = a2[15];
          }
        }
        ++v27;
      }
      while ( v27 < v24 );
      if ( *(_DWORD *)(a1 + 624) )
        goto LABEL_42;
      if ( v24 )
      {
        v117 = 0;
        v36 = 0;
        for ( i = 0; i < v24; ++i )
        {
          v119 = &v28[96 * i];
          if ( (*((_DWORD *)v119 + 7) | 4) == 4
            && *(_DWORD *)v119 == 2
            && *(_DWORD *)(a1 + 52) == *((unsigned __int16 *)v119 + 10)
            && *(_DWORD *)(a1 + 4) == *((_DWORD *)v119 + 19) )
          {
            ++v117;
            v36 = 1;
            *(_DWORD *)(a1 + 624) = v117;
            v24 = a2[15];
          }
        }
        if ( v117 )
          goto LABEL_43;
        if ( v24 )
        {
          v120 = 0;
          for ( j = 0; j < v24; ++j )
          {
            v122 = &v28[96 * j];
            if ( *((_DWORD *)v122 + 7) == 7 && !*(_DWORD *)v122 )
            {
              v123 = *(_QWORD *)(a1 + 120);
              if ( *(_DWORD *)(*(_QWORD *)(v123 + 24) + 1032LL) == *((unsigned __int16 *)v122 + 11)
                && *(unsigned __int16 *)(v123 + 2) == *((unsigned __int16 *)v122 + 12)
                && *(_DWORD *)(a1 + 4) == *((_DWORD *)v122 + 19) )
              {
                ++v120;
                v36 = 0;
                *(_DWORD *)(a1 + 624) = v120;
                v24 = a2[15];
              }
            }
          }
          if ( v120 )
            goto LABEL_43;
          if ( v24 )
          {
            v150 = 0;
            for ( k = 0; k < v24; ++k )
            {
              v152 = &v28[96 * k];
              if ( *((_DWORD *)v152 + 7) == 7
                && *(_DWORD *)v152 == 2
                && *(_DWORD *)(a1 + 52) == *((unsigned __int16 *)v152 + 10)
                && *(_DWORD *)(a1 + 4) == *((_DWORD *)v152 + 19) )
              {
                ++v150;
                v36 = 1;
                *(_DWORD *)(a1 + 624) = v150;
                v24 = a2[15];
              }
            }
            if ( v150 )
              goto LABEL_43;
          }
        }
      }
    }
    else if ( *(_DWORD *)(a1 + 624) )
    {
LABEL_42:
      v36 = 0;
LABEL_43:
      v37 = *(__int64 **)(a1 + 112);
      v38 = v37[14];
      if ( !v38 )
        v38 = *v37;
      printk(&unk_23AE3, v38, "aw_dev_parse_get_scene_count_v1_0_0_0");
      v39 = devm_kmalloc(*(_QWORD *)(a1 + 112), (unsigned __int64)*(unsigned int *)(a1 + 624) << 6, 3520);
      *(_QWORD *)(a1 + 640) = v39;
      if ( !v39 )
      {
        v40 = *(__int64 **)(a1 + 112);
        v41 = v40[14];
        if ( !v41 )
          v41 = *v40;
        printk(&unk_266C2, v41, "aw_dev_parse_acf_by_hdr_v_1_0_0_0");
        v35 = -12;
        goto LABEL_234;
      }
      v70 = *(__int64 **)(a1 + 112);
      v71 = v70[14];
      memset(s, 0, 128);
      if ( !v71 )
        v71 = *v70;
      v72 = (unsigned int)a2[16];
      printk(&unk_26EB3, v71, "aw_dev_parse_scene_v_1_0_0_0");
      v73 = a2[15];
      if ( !v73 )
        goto LABEL_160;
      v74 = 0;
      v75 = 0;
      v76 = (char *)v25 + v72;
      while ( 1 )
      {
        v77 = &v76[96 * v74];
        v78 = *(_DWORD *)v77;
        if ( v36 )
        {
          if ( v78 != 2 || *(_DWORD *)(a1 + 52) != *((unsigned __int16 *)v77 + 10) )
            goto LABEL_111;
        }
        else
        {
          if ( v78 )
            goto LABEL_111;
          v81 = *(_QWORD *)(a1 + 120);
          if ( *(_DWORD *)(*(_QWORD *)(v81 + 24) + 1032LL) != *((unsigned __int16 *)v77 + 11)
            || *(unsigned __int16 *)(v81 + 2) != *((unsigned __int16 *)v77 + 12) )
          {
            goto LABEL_111;
          }
        }
        if ( *(_DWORD *)(a1 + 4) == *((_DWORD *)v77 + 19) )
        {
          if ( v75 )
          {
            v79 = 0;
            v80 = v75;
            while ( 1 )
            {
              if ( v79 == 32 )
                goto LABEL_297;
              if ( (v79 & 0x3FFFFFFFFFFFFFFFLL) == 0x20 )
                goto LABEL_148;
              if ( *(unsigned __int16 *)&v76[96 * v74 + 26] <= (unsigned int)*(unsigned __int16 *)&v76[96 * *((unsigned int *)s + v79) + 26] )
                break;
              ++v79;
              --v80;
              if ( v75 == v79 )
              {
                LODWORD(v79) = v75;
                goto LABEL_133;
              }
            }
            v82 = v80;
            v83 = v75 + 1;
            v84 = v75 + 1;
            v85 = v83 - 1;
            v86 = v75 - 1;
            if ( v82 <= 1 )
              v82 = 1;
            do
            {
              if ( v86 > 0x1F || v85 > 0x1F )
                goto LABEL_297;
              v87 = *((_DWORD *)s + v86);
              --v82;
              --v86;
              *((_DWORD *)s + v85--) = v87;
            }
            while ( v82 );
            if ( (v79 & 0x3FFFFFFFFFFFFFFFLL) == 0x20 )
            {
LABEL_148:
              __break(1u);
              goto LABEL_149;
            }
            v75 = v83;
            *((_DWORD *)s + v79) = v74;
            if ( v84 == (_DWORD)v79 )
            {
LABEL_133:
              if ( (unsigned int)v79 > 0x1F )
              {
LABEL_297:
                __break(0x5512u);
                goto LABEL_298;
              }
              v75 = v79 + 1;
              *((_DWORD *)s + (unsigned int)v79) = v74;
            }
            goto LABEL_111;
          }
          LODWORD(s[0]) = v74++;
          v75 = 1;
          if ( v74 == v73 )
            goto LABEL_185;
        }
        else
        {
LABEL_111:
          if ( ++v74 == v73 )
          {
            if ( !v75 )
              goto LABEL_160;
LABEL_185:
            v124 = 4LL * v75;
            v125 = 0;
            v126 = 0;
            v194 = a2 + 1;
            while ( 2 )
            {
              if ( v125 == 128 )
                goto LABEL_297;
              v129 = &v76[96 * *(unsigned int *)((char *)s + v125)];
              v130 = *((_DWORD *)v129 + 7);
              if ( v130 <= 6 )
              {
                if ( v130 == 4 )
                {
                  v127 = v126;
                  v132 = aw_dev_parse_reg_bin_with_hdr(
                           a1,
                           (char *)v25 + *((unsigned int *)v129 + 9),
                           *((unsigned int *)v129 + 8),
                           *(_QWORD *)(a1 + 640) + ((__int64)v126 << 6));
                  if ( (v132 & 0x80000000) != 0 )
                  {
                    v160 = *(__int64 **)(a1 + 112);
                    v35 = v132;
                    v158 = v160[14];
                    if ( !v158 )
                      v158 = *v160;
                    v159 = &unk_2261A;
                    goto LABEL_251;
                  }
                }
                else
                {
                  if ( v130 )
                  {
LABEL_238:
                    v156 = *(__int64 **)(a1 + 112);
                    v111 = v156[14];
                    if ( !v111 )
                      v111 = *v156;
                    v112 = &unk_256DE;
                    goto LABEL_241;
                  }
                  v133 = *(__int64 **)(a1 + 112);
                  v134 = v133[14];
                  if ( !v134 )
                    v134 = *v133;
                  v136 = *((_DWORD *)v129 + 8);
                  v135 = *((unsigned int *)v129 + 9);
                  v195 = *(_QWORD *)(a1 + 640);
                  printk(&unk_2880A, v134, "aw_dev_parse_raw_reg");
                  if ( (v136 & 3) != 0 )
                  {
                    v190 = *(__int64 **)(a1 + 112);
                    v191 = v190[14];
                    if ( !v191 )
                      v191 = *v190;
                    printk(&unk_26FE8, v191, "aw_dev_parse_raw_reg");
                    v192 = *(__int64 **)(a1 + 112);
                    v111 = v192[14];
                    if ( !v111 )
                      v111 = *v192;
                    v112 = &unk_2432E;
LABEL_241:
                    v113 = "aw_dev_parse_drv_type_v_1_0_0_0";
LABEL_163:
                    printk(v112, v111, v113);
                    v35 = -22;
LABEL_164:
                    v114 = *(__int64 **)(a1 + 112);
                    v115 = v114[14];
                    if ( !v115 )
                      v115 = *v114;
                    v116 = &unk_23FDA;
                    goto LABEL_167;
                  }
                  v137 = v135;
                  v127 = v126;
                  v138 = v195 + ((__int64)v126 << 6);
                  *(_QWORD *)(v138 + 24) = (char *)v194 + v137;
                  *(_DWORD *)(v138 + 16) = v136;
                  v25 = a2 + 1;
                  *(_DWORD *)v138 = 1;
                }
              }
              else
              {
                if ( v130 != 7 )
                {
                  if ( v130 != 10 )
                    goto LABEL_238;
                  v131 = aw882xx_monitor_parse_fw(
                           a1 + 672,
                           (char *)v25 + *((unsigned int *)v129 + 9),
                           *((unsigned int *)v129 + 8));
                  if ( (v131 & 0x80000000) != 0 )
                  {
                    v161 = *(__int64 **)(a1 + 112);
                    v35 = v131;
                    v158 = v161[14];
                    if ( !v158 )
                      v158 = *v161;
                    v159 = &unk_281AD;
                    goto LABEL_251;
                  }
LABEL_188:
                  v125 += 4;
                  if ( v124 == v125 )
                  {
                    if ( v126 )
                    {
                      v143 = *(__int64 **)(a1 + 112);
                      v144 = v143[14];
                      if ( !v144 )
                        v144 = *v143;
                      v145 = (unsigned int)a2[16];
                      printk(&unk_26EB3, v144, "aw_dev_parse_skt_type_v_1_0_0_0");
                      v146 = a2[15];
                      if ( !v146 )
                        goto LABEL_215;
                      v162 = 0;
                      v163 = (char *)v25 + v145;
LABEL_264:
                      v170 = &v163[96 * v162];
                      if ( *(_DWORD *)v170 != 1
                        || *((_DWORD *)v170 + 7) != 1
                        || *(_DWORD *)(a1 + 52) != *((unsigned __int16 *)v170 + 10)
                        || *(_DWORD *)(a1 + 4) != *((_DWORD *)v170 + 19) )
                      {
                        goto LABEL_263;
                      }
                      if ( v170 != (char *)-44LL )
                      {
                        v171 = *(_DWORD *)(a1 + 624);
                        if ( v171 )
                        {
                          v172 = *(_QWORD *)(a1 + 640);
                          v173 = 0;
                          while ( 1 )
                          {
                            v174 = v173;
                            v175 = v172 + ((__int64)v173 << 6);
                            v176 = *(const char **)(v175 + 8);
                            if ( !v176 )
                              break;
                            if ( !strcmp(v176, v170 + 44) )
                            {
                              v177 = *(__int64 **)(a1 + 112);
                              v178 = v177[14];
                              if ( !v178 )
                                v178 = *v177;
                              v168 = *((_DWORD *)v170 + 8);
                              v169 = (char *)v194 + *((unsigned int *)v170 + 9);
                              printk(&unk_2880A, v178, "aw_dev_parse_raw_dsp");
                              *(_QWORD *)(v175 + 40) = v169;
                              *(_DWORD *)(v175 + 32) = v168;
                              v146 = a2[15];
LABEL_263:
                              if ( ++v162 < v146 )
                                goto LABEL_264;
LABEL_215:
                              v147 = *(_QWORD *)(a1 + 640);
                              v148 = *(__int64 **)(a1 + 112);
                              if ( v147 )
                              {
                                v164 = devm_kmalloc(v148, (unsigned int)(32 * *(_DWORD *)(a1 + 624)), 3520);
                                *(_QWORD *)(a1 + 632) = v164;
                                if ( v164 )
                                {
                                  if ( *(_DWORD *)(a1 + 624) )
                                  {
                                    v185 = 0;
                                    do
                                    {
                                      v186 = v185;
                                      v187 = v147 + ((__int64)v185 << 6);
                                      *(_DWORD *)(v187 + 4) = v185;
                                      *(_QWORD *)(*(_QWORD *)(a1 + 632) + 8LL * v185) = *(_QWORD *)(v187 + 8);
                                      v188 = *(__int64 **)(a1 + 112);
                                      v189 = v188[14];
                                      if ( !v189 )
                                        v189 = *v188;
                                      printk(&unk_26C61, v189, "aw_dev_parse_create_prof_name_list_v_1_0_0_0");
                                      v185 = v186 + 1;
                                    }
                                    while ( (unsigned int)(v186 + 1) < *(_DWORD *)(a1 + 624) );
                                  }
LABEL_204:
                                  v139 = *(__int64 **)(a1 + 112);
                                  v140 = v139[14];
                                  if ( !v140 )
                                    v140 = *v139;
                                  printk(&unk_27EFD, v140, "aw882xx_dev_parse_acf");
                                  result = 0;
                                  goto LABEL_237;
                                }
                                v165 = *(__int64 **)(a1 + 112);
                                v166 = v165[14];
                                if ( !v166 )
                                  v166 = *v165;
                                printk(&unk_27BBF, v166, "aw_dev_parse_create_prof_name_list_v_1_0_0_0");
                                v35 = -12;
                              }
                              else
                              {
                                v149 = v148[14];
                                if ( !v149 )
                                  v149 = *v148;
                                printk(&unk_27807, v149, "aw_dev_parse_create_prof_name_list_v_1_0_0_0");
                                v35 = -22;
                              }
                              v167 = *(__int64 **)(a1 + 112);
                              v115 = v167[14];
                              if ( !v115 )
                                v115 = *v167;
                              v116 = &unk_23507;
LABEL_167:
                              printk(v116, v115, "aw_dev_parse_acf_by_hdr_v_1_0_0_0");
                              goto LABEL_234;
                            }
                            v173 = v174 + 1;
                            if ( v171 == v174 + 1 )
                              goto LABEL_277;
                          }
                          v181 = *(__int64 **)(a1 + 112);
                          v182 = v181[14];
                          if ( !v182 )
                            v182 = *v181;
                          v183 = &unk_27FA5;
LABEL_283:
                          printk(v183, v182, "aw_dev_parse_get_scene_id_v_1_0_0_0");
                        }
                        else
                        {
LABEL_277:
                          v179 = *(__int64 **)(a1 + 112);
                          v180 = v179[14];
                          if ( !v180 )
                            v180 = *v179;
                          printk(&unk_22F2F, v180, "aw_dev_parse_get_scene_id_v_1_0_0_0");
                        }
                        v184 = *(__int64 **)(a1 + 112);
                        v111 = v184[14];
                        if ( !v111 )
                          v111 = *v184;
                        v112 = &unk_24E4E;
                        v113 = "aw_dev_parse_skt_type_v_1_0_0_0";
                        goto LABEL_163;
                      }
LABEL_298:
                      v193 = *(__int64 **)(a1 + 112);
                      v182 = v193[14];
                      if ( !v182 )
                        v182 = *v193;
                      v183 = &unk_26155;
                      goto LABEL_283;
                    }
LABEL_160:
                    v110 = *(__int64 **)(a1 + 112);
                    v111 = v110[14];
                    if ( !v111 )
                      v111 = *v110;
                    v112 = &unk_277D2;
                    v113 = "aw_dev_parse_scene_v_1_0_0_0";
                    goto LABEL_163;
                  }
                  continue;
                }
                v127 = v126;
                v128 = aw_dev_prof_parse_multi_bin(
                         a1,
                         (char *)v25 + *((unsigned int *)v129 + 9),
                         *((unsigned int *)v129 + 8),
                         *(_QWORD *)(a1 + 640) + ((__int64)v126 << 6));
                if ( (v128 & 0x80000000) != 0 )
                {
                  v157 = *(__int64 **)(a1 + 112);
                  v35 = v128;
                  v158 = v157[14];
                  if ( !v158 )
                    v158 = *v157;
                  v159 = &unk_26C37;
LABEL_251:
                  printk(v159, v158, "aw_dev_parse_drv_type_v_1_0_0_0");
                  goto LABEL_164;
                }
              }
              break;
            }
            ++v126;
            *(_QWORD *)(*(_QWORD *)(a1 + 640) + (v127 << 6) + 8) = v129 + 44;
            *(_DWORD *)(*(_QWORD *)(a1 + 640) + (v127 << 6) + 4) = *((unsigned __int16 *)v129 + 13);
            goto LABEL_188;
          }
        }
      }
    }
    v31 = *(__int64 **)(a1 + 112);
    v32 = v31[14];
    if ( !v32 )
      v32 = *v31;
    printk(&unk_23743, v32, "aw_dev_parse_get_scene_count_v1_0_0_0");
    v33 = *(__int64 **)(a1 + 112);
    v34 = v33[14];
    if ( !v34 )
      v34 = *v33;
    printk(&unk_25D43, v34, "aw_dev_parse_acf_by_hdr_v_1_0_0_0");
    v35 = -22;
    goto LABEL_234;
  }
  if ( (_DWORD)v8 != 1 )
  {
    printk(&unk_259FC, "aw882xx_dev_parse_acf", v8);
    result = 4294967274LL;
    goto LABEL_237;
  }
  v9 = a2 + 1;
  memset(s, 0, 0x2C0u);
  v10 = *(__int64 **)(a1 + 112);
  v11 = v10[14];
  if ( !v11 )
    v11 = *v10;
  v12 = (unsigned int)a2[16];
  printk(&unk_26EB3, v11, "aw_dev_parse_dev_type");
  if ( !a2[15] )
    goto LABEL_50;
  v13 = 0;
  v14 = 0;
  v15 = (char *)v9 + v12;
  do
  {
    v17 = *(_QWORD *)(a1 + 120);
    v18 = &v15[64 * (__int64)(int)v13];
    if ( *(_DWORD *)(*(_QWORD *)(v17 + 24) + 1032LL) == *((unsigned __int16 *)v18 + 11)
      && *(unsigned __int16 *)(v17 + 2) == *((unsigned __int16 *)v18 + 12)
      && !*(_DWORD *)v18 )
    {
      if ( *((_DWORD *)v18 + 7) == 10 )
      {
        v16 = aw_dev_parse_data_by_sec_type(a1, a2 + 1);
        if ( v16 < 0 )
        {
          v153 = *(__int64 **)(a1 + 112);
          v21 = v16;
          v22 = v153[14];
          if ( !v22 )
            v22 = *v153;
          v23 = &unk_23F8D;
LABEL_231:
          v142 = "aw_dev_parse_dev_type";
          goto LABEL_232;
        }
      }
      else
      {
        if ( *((unsigned __int16 *)v18 + 13) >= 0xCuLL )
          goto LABEL_297;
        v19 = aw_dev_parse_data_by_sec_type(a1, a2 + 1);
        if ( v19 < 0 )
        {
          v20 = *(__int64 **)(a1 + 112);
          v21 = v19;
          v22 = v20[14];
          if ( !v22 )
            v22 = *v20;
          v23 = &unk_2566F;
          goto LABEL_231;
        }
      }
      ++v14;
    }
    ++v13;
  }
  while ( v13 < a2[15] );
  if ( v14 )
    goto LABEL_73;
LABEL_50:
  v42 = *(__int64 **)(a1 + 112);
  v43 = v42[14];
  if ( !v43 )
    v43 = *v42;
  printk(&unk_28510, v43, "aw_dev_parse_dev_type");
  v44 = *(__int64 **)(a1 + 112);
  v45 = v44[14];
  if ( !v45 )
    v45 = *v44;
  printk(&unk_24612, v45, "aw_dev_parse_acf_by_hdr");
  v46 = *(__int64 **)(a1 + 112);
  v47 = v46[14];
  if ( !v47 )
    v47 = *v46;
  v48 = (unsigned int)a2[16];
  printk(&unk_26EB3, v47, "aw_dev_parse_dev_default_type");
  v49 = a2[15];
  if ( !v49 )
    goto LABEL_70;
  v50 = 0;
  v51 = 0;
  v52 = (char *)v9 + v48;
  while ( 2 )
  {
    v54 = &v52[64 * (__int64)v50];
    if ( *(_DWORD *)(a1 + 52) != *((unsigned __int16 *)v54 + 10) || *(_DWORD *)v54 != 2 )
      goto LABEL_60;
    if ( *((_DWORD *)v54 + 7) == 10 )
    {
      v53 = aw_dev_parse_data_by_sec_type(a1, a2 + 1);
      if ( (v53 & 0x80000000) == 0 )
        goto LABEL_59;
      v141 = *(__int64 **)(a1 + 112);
      v21 = v53;
      v22 = v141[14];
      if ( !v22 )
        v22 = *v141;
      v23 = &unk_23F8D;
LABEL_210:
      v142 = "aw_dev_parse_dev_default_type";
LABEL_232:
      printk(v23, v22, v142);
      v59 = v21;
      goto LABEL_233;
    }
    if ( *((unsigned __int16 *)v54 + 13) >= 0xCuLL )
      goto LABEL_297;
    v55 = aw_dev_parse_data_by_sec_type(a1, a2 + 1);
    if ( v55 < 0 )
    {
      v56 = *(__int64 **)(a1 + 112);
      v21 = v55;
      v22 = v56[14];
      if ( !v22 )
        v22 = *v56;
      v23 = &unk_2566F;
      goto LABEL_210;
    }
LABEL_59:
    v49 = a2[15];
    ++v51;
LABEL_60:
    if ( ++v50 < v49 )
      continue;
    break;
  }
  if ( !v51 )
  {
LABEL_70:
    v57 = *(__int64 **)(a1 + 112);
    v58 = v57[14];
    if ( !v58 )
      v58 = *v57;
    printk(&unk_26656, v58, "aw_dev_parse_dev_default_type");
    v59 = -22;
    goto LABEL_233;
  }
LABEL_73:
  v60 = *(__int64 **)(a1 + 112);
  v61 = v60[14];
  if ( !v61 )
    v61 = *v60;
  v62 = (unsigned int)a2[16];
  printk(&unk_26EB3, v61, "aw_dev_parse_skt_type");
  v63 = a2[15];
  if ( v63 )
  {
    v88 = 0;
    v89 = 0;
    v90 = (char *)v9 + v62;
    do
    {
      v91 = &v90[64 * (__int64)(int)v88];
      if ( *(_DWORD *)(a1 + 52) == *((unsigned __int16 *)v91 + 10) && *(_DWORD *)v91 == 1 && *((_DWORD *)v91 + 7) == 1 )
      {
        v92 = *((unsigned __int16 *)v91 + 13);
        if ( v92 >= 0xC )
          goto LABEL_297;
        v93 = *(__int64 **)(a1 + 112);
        v94 = v93[14];
        if ( !v94 )
          v94 = *v93;
        v96 = *((_DWORD *)v91 + 8);
        v95 = *((unsigned int *)v91 + 9);
        v97 = v92 << 6;
        printk(&unk_2880A, v94, "aw_dev_parse_raw_dsp");
        if ( (v97 | 0x28) > 0x2C0 )
          goto LABEL_148;
        *(_QWORD *)((char *)&s[5] + v97) = (char *)v9 + v95;
        if ( (v97 | 0x20) > 0x2C0 )
          goto LABEL_148;
        v63 = a2[15];
        ++v89;
        *(_DWORD *)((char *)&s[4] + v97) = v96;
      }
      ++v88;
    }
    while ( v88 < v63 );
  }
  v64 = *(__int64 **)(a1 + 112);
  v65 = v64[14];
  if ( !v65 )
    v65 = *v64;
  printk(&unk_26692, v65, "aw_dev_parse_skt_type");
  memcpy(dest, s, sizeof(dest));
  if ( dest[0] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[16] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[32] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[48] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[64] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[80] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[96] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[112] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[128] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[144] == 1 )
    ++*(_DWORD *)(a1 + 624);
  if ( dest[160] == 1 )
    ++*(_DWORD *)(a1 + 624);
  v66 = *(__int64 **)(a1 + 112);
  v67 = v66[14];
  if ( !v67 )
    v67 = *v66;
  printk(&unk_25A64, v67, "aw_dev_parse_get_vaild_prof");
  if ( !*(_DWORD *)(a1 + 624) )
  {
    v68 = *(__int64 **)(a1 + 112);
    v69 = v68[14];
    if ( !v69 )
      v69 = *v68;
    printk(&unk_25573, v69, "aw_dev_parse_get_vaild_prof");
    v59 = -1;
    goto LABEL_233;
  }
LABEL_149:
  v98 = _kmalloc_noprof((unsigned __int64)*(unsigned int *)(a1 + 624) << 6, 3520);
  *(_QWORD *)(a1 + 640) = v98;
  if ( !v98 )
    goto LABEL_158;
  v99 = 0;
  v100 = 0;
  v101 = dest;
  while ( 2 )
  {
    if ( *v101 != 1 )
    {
LABEL_152:
      ++v99;
      v101 += 16;
      if ( v99 == 11 )
      {
        *(_QWORD *)(a1 + 632) = profile_name;
        goto LABEL_204;
      }
      continue;
    }
    break;
  }
  if ( v100 < *(_DWORD *)(a1 + 624) )
  {
    v102 = (__int64)(int)v100++ << 6;
    v103 = *((_QWORD *)v101 + 5);
    v104 = (_QWORD *)(*(_QWORD *)(a1 + 640) + v102);
    v104[4] = *((_QWORD *)v101 + 4);
    v104[5] = v103;
    v105 = *((_QWORD *)v101 + 7);
    v104[6] = *((_QWORD *)v101 + 6);
    v104[7] = v105;
    v106 = *((_QWORD *)v101 + 1);
    *v104 = *(_QWORD *)v101;
    v104[1] = v106;
    v107 = *((_QWORD *)v101 + 3);
    v104[2] = *((_QWORD *)v101 + 2);
    v104[3] = v107;
    *(_DWORD *)(*(_QWORD *)(a1 + 640) + v102 + 4) = v99;
    goto LABEL_152;
  }
  v108 = *(__int64 **)(a1 + 112);
  v109 = v108[14];
  if ( !v109 )
    v109 = *v108;
  printk(&unk_2778D, v109, "aw_dev_parse_get_vaild_prof");
LABEL_158:
  v59 = -12;
LABEL_233:
  v35 = v59;
LABEL_234:
  v154 = *(__int64 **)(a1 + 112);
  v155 = v154[14];
  if ( !v155 )
    v155 = *v154;
  printk(&unk_254EB, v155, "aw882xx_dev_parse_acf");
  result = v35;
LABEL_237:
  _ReadStatusReg(SP_EL0);
  return result;
}
