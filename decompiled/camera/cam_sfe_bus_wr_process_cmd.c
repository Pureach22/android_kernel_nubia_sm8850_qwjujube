__int64 __fastcall cam_sfe_bus_wr_process_cmd(
        __int64 is_expanded_memory,
        unsigned int a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  unsigned __int64 v8; // x19
  unsigned int v9; // w25
  __int64 v10; // x28
  __int64 v11; // x22
  __int64 v12; // x21
  __int64 v13; // x8
  int v14; // w7
  int v15; // w6
  __int64 v16; // x20
  __int64 v17; // x8
  int v18; // w0
  const char *v19; // x5
  __int64 v20; // x0
  __int64 v21; // x1
  __int64 v22; // x2
  const char *v23; // x3
  __int64 v24; // x4
  int v26; // w8
  int v27; // w8
  __int64 v28; // x8
  int v29; // w9
  char v30; // w21
  __int64 v31; // x22
  __int64 v32; // x23
  __int64 v33; // x24
  unsigned int v34; // w21
  __int64 v35; // x26
  __int64 v36; // x27
  unsigned __int64 v37; // x20
  __int64 v38; // x28
  int *v39; // x21
  unsigned int *v40; // x24
  int v41; // w9
  unsigned int v42; // w6
  unsigned int v43; // w7
  bool v44; // zf
  int v45; // w8
  __int64 v46; // x8
  __int64 v47; // x22
  unsigned int v48; // w8
  unsigned __int64 v49; // x23
  __int64 v50; // x24
  int v51; // w27
  int v52; // w10
  __int64 v53; // x10
  __int64 v54; // x9
  int v55; // w8
  char v56; // w11
  int v57; // w10
  __int64 v58; // x22
  unsigned int v59; // w23
  const char *v60; // x13
  int *v61; // x9
  int *v62; // x10
  int v63; // w11
  int v64; // w7
  int v65; // w9
  int v66; // w6
  const char *v67; // x10
  const char *v68; // x25
  unsigned int v69; // w8
  __int64 v70; // x27
  int v71; // w7
  int v72; // w6
  unsigned __int64 v73; // x23
  __int64 v74; // x21
  _DWORD *v75; // x20
  unsigned int v76; // w25
  int v77; // w8
  __int64 v78; // x1
  __int64 v79; // x9
  int v80; // w22
  unsigned int v81; // w25
  unsigned int v82; // w26
  int v83; // w8
  unsigned int v84; // w25
  unsigned __int64 v85; // x26
  __int64 v86; // x0
  int v87; // w9
  int v88; // w8
  int v89; // w10
  __int64 v90; // x27
  __int64 v91; // x26
  unsigned __int64 v92; // x8
  _DWORD *v93; // x22
  unsigned __int64 v94; // x28
  __int64 v95; // x6
  __int64 v96; // x23
  __int64 v97; // x20
  unsigned int *v98; // x21
  __int64 v99; // x9
  _DWORD *v100; // x9
  int v101; // w9
  _DWORD *v102; // x9
  int v103; // w9
  _DWORD *v104; // x9
  int v105; // w9
  _DWORD *v106; // x9
  int v107; // w9
  __int64 v108; // x23
  _DWORD *v109; // x24
  unsigned int v110; // w26
  unsigned int v111; // w6
  _DWORD *v112; // x21
  int v113; // w22
  int packer_fmt; // w0
  int v115; // w8
  int v116; // w8
  int v117; // w9
  int v118; // w10
  unsigned int v119; // w8
  __int64 v120; // x8
  __int64 v121; // x8
  __int64 v122; // x2
  __int64 v123; // x24
  unsigned int v124; // w0
  __int64 v125; // x7
  const char *v126; // x5
  __int64 v127; // x4
  unsigned int v128; // w1
  int v129; // w9
  __int64 v130; // x8
  int v131; // w13
  _DWORD *v132; // x12
  int v133; // w20
  int v134; // w11
  int v135; // w6
  __int64 v136; // x6
  __int64 v137; // x22
  int v138; // w0
  int v139; // w20
  unsigned int v140; // w24
  __int64 v141; // x9
  __int64 v142; // x21
  __int64 v143; // x20
  __int64 v144; // x22
  int v146; // w0
  const char *v147; // x5
  __int64 v148; // x0
  __int64 v149; // x1
  __int64 v150; // x2
  const char *v151; // x3
  __int64 v152; // x4
  const char *v153; // x3
  const char *v154; // x5
  __int64 v155; // x1
  __int64 v156; // x2
  __int64 v157; // x4
  __int64 v158; // x21
  __int64 v159; // x20
  unsigned __int64 applied_src_clk; // x0
  __int64 v161; // x8
  unsigned __int64 v162; // x9
  __int64 v163; // x25
  int v164; // w23
  unsigned int v165; // w24
  __int64 v166; // x26
  __int64 v167; // x22
  __int64 v168; // x28
  unsigned __int64 v169; // x27
  unsigned __int64 v170; // x20
  _DWORD *v171; // x9
  _DWORD *v172; // x8
  unsigned int v173; // w26
  __int64 v174; // x8
  __int64 v175; // x9
  __int64 v176; // x20
  __int64 v177; // x9
  __int64 v178; // x28
  unsigned __int64 v179; // x9
  __int64 v180; // x21
  unsigned __int64 i; // x27
  __int64 v182; // x10
  __int64 v183; // x2
  unsigned int v184; // w0
  __int64 v185; // x22
  const char *v186; // x3
  __int64 v187; // x1
  __int64 v188; // x4
  const char *v189; // x3
  __int64 v190; // x4
  __int64 v191; // x6
  unsigned __int64 v192; // x24
  unsigned int v193; // w27
  __int64 v194; // x12
  int *v195; // x21
  __int64 v196; // x25
  __int64 v197; // x8
  _DWORD *v198; // x22
  unsigned int *v199; // x20
  unsigned int v200; // w8
  unsigned int v201; // w8
  int v202; // w9
  unsigned int v203; // w8
  unsigned int v204; // w9
  int v205; // w10
  int v206; // w10
  int v207; // w7
  __int64 v208; // x9
  int *v209; // x8
  int *v210; // x10
  int v211; // w10
  int v212; // w22
  unsigned int v213; // w23
  unsigned int v214; // w26
  _DWORD *v215; // x9
  int v216; // w8
  _DWORD *v217; // x9
  _QWORD *v218; // x8
  unsigned int v219; // w22
  __int64 v220; // x10
  __int64 v221; // x9
  unsigned __int64 v222; // x27
  int v223; // w7
  _DWORD *v224; // x9
  _DWORD *v225; // x23
  int v226; // w23
  int v227; // w23
  int v228; // w26
  int v229; // w23
  __int64 (__fastcall *v230)(_QWORD); // x8
  unsigned int v231; // w21
  const char *v232; // x3
  __int64 v233; // x4
  _DWORD *v234; // x8
  __int64 v235; // x0
  unsigned int v236; // w21
  __int64 (__fastcall *v237)(_QWORD); // x8
  unsigned int v238; // w22
  __int64 (__fastcall *v239)(_QWORD); // x8
  unsigned int v240; // w20
  _DWORD *v241; // x8
  __int64 v242; // x0
  _DWORD *v243; // x8
  __int64 v244; // x0
  char v245; // [xsp+0h] [xbp-160h]
  char v246; // [xsp+0h] [xbp-160h]
  __int64 v247; // [xsp+20h] [xbp-140h]
  __int64 v248; // [xsp+28h] [xbp-138h]
  __int64 v249; // [xsp+30h] [xbp-130h]
  __int64 v250; // [xsp+38h] [xbp-128h]
  __int64 v251; // [xsp+38h] [xbp-128h]
  __int64 v252; // [xsp+40h] [xbp-120h]
  unsigned int v253; // [xsp+40h] [xbp-120h]
  unsigned int v254; // [xsp+40h] [xbp-120h]
  unsigned int v255; // [xsp+40h] [xbp-120h]
  unsigned int v256; // [xsp+40h] [xbp-120h]
  __int64 v257; // [xsp+40h] [xbp-120h]
  __int64 v258; // [xsp+40h] [xbp-120h]
  unsigned __int64 v259; // [xsp+48h] [xbp-118h] BYREF
  _QWORD v260[34]; // [xsp+50h] [xbp-110h] BYREF

  v260[32] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( is_expanded_memory && (v8 = a3) != 0 )
  {
    v9 = 0;
    v10 = is_expanded_memory + 24576;
    switch ( a2 )
    {
      case 1u:
        v11 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
        if ( !v11 || (v12 = *(_QWORD *)(v11 + 88)) == 0 )
        {
          v23 = "cam_sfe_bus_wr_update_wm";
          v19 = "Invalid data";
          v20 = 3;
          v21 = 0x40000000;
          v22 = 1;
          v24 = 2452;
          break;
        }
        v13 = *(_QWORD *)(a3 + 40);
        v14 = *(_DWORD *)(v11 + 24);
        v15 = *(_DWORD *)(v13 + 20);
        if ( v15 != v14 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_bus_wr_update_wm",
            2460,
            "Failed! Invalid number buffers:%d required:%d",
            v15,
            v14);
          goto LABEL_16;
        }
        v16 = *(_QWORD *)(v11 + 8);
        if ( (*(_BYTE *)(a3 + 32) & 1) != 0 )
        {
          v17 = 0;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            is_expanded_memory = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2466,
                                   "Using scratch buf config");
            v15 = *(_DWORD *)(v11 + 24);
            v17 = 0;
          }
        }
        else
        {
          v17 = *(_QWORD *)(v13 + 56);
        }
        if ( !v15 )
        {
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            v186 = "cam_sfe_bus_wr_update_wm";
            v187 = debug_mdl & 0x40000000;
            v188 = 2646;
            goto LABEL_374;
          }
          goto LABEL_352;
        }
        v192 = 0;
        v193 = 0;
        v194 = v16 + 56;
        v247 = v16 + 92;
        v248 = v12;
        v195 = (int *)(v17 + 36);
        v196 = 128;
        v251 = v11;
        v258 = v16 + 56;
        while ( 1 )
        {
          if ( v193 >= 0x70 )
          {
            v189 = "cam_sfe_bus_wr_update_wm";
            v190 = 2474;
            v95 = v193;
            goto LABEL_355;
          }
          v197 = *(_QWORD *)(v11 + 32);
          v198 = (_DWORD *)(v194 + 4LL * v193);
          v199 = *(unsigned int **)(v197 + v196 - 104);
          *v198 = **((_DWORD **)v199 + 2);
          v200 = v199[24];
          v198[1] = v200;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            is_expanded_memory = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2486,
                                   "WM:%d %s en_cfg 0x%X",
                                   *v199,
                                   (const char *)(*(_QWORD *)(v251 + 32) + v196),
                                   v200);
            v194 = v258;
          }
          v198[2] = *(_DWORD *)(*((_QWORD *)v199 + 2) + 24LL);
          v201 = v199[17];
          v198[3] = v201;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            is_expanded_memory = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2492,
                                   "WM:%d %s packer_fmt 0x%X",
                                   *v199,
                                   (const char *)(*(_QWORD *)(v251 + 32) + v196),
                                   v201);
            v194 = v258;
          }
          v202 = *((unsigned __int8 *)v199 + 120);
          v203 = v199[28];
          v199[28] = *(_DWORD *)(v10 + 2892);
          if ( v202 != 1
            || *(_BYTE *)(v10 + 2941) == 1 && (*(_BYTE *)(v8 + 32) & 1) != 0
            || *(_BYTE *)(v10 + 2943) == 1 && *(_BYTE *)(v8 + 32) != 1 )
          {
            goto LABEL_300;
          }
          v204 = v199[29];
          v205 = (v204 << 8) | 0x30;
          v199[28] = v205;
          if ( *(_BYTE *)(v8 + 32) == 1 )
          {
            if ( *(_BYTE *)(v10 + 2942) != 1 )
              goto LABEL_296;
            v206 = *(_DWORD *)(v10 + 2932) | v205;
          }
          else
          {
            if ( *(_BYTE *)(v10 + 2944) != 1 )
            {
LABEL_296:
              v206 = (v204 << 8) | 0x31;
              goto LABEL_297;
            }
            v206 = *(_DWORD *)(v10 + 2936) | v205;
          }
LABEL_297:
          v199[28] = v206;
          if ( *(_BYTE *)(v10 + 2945) == 1 && v203 != v206 )
          {
            is_expanded_memory = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   0x40000000,
                                   3,
                                   "cam_sfe_bus_wr_update_wm",
                                   2521,
                                   "SFE:%d WM:%d current_scid:%d cache_cfg:0x%x",
                                   **((_DWORD **)v199 + 1),
                                   *v199,
                                   v204,
                                   v206);
            v194 = v258;
          }
LABEL_300:
          v198[4] = *(_DWORD *)(*((_QWORD *)v199 + 2) + 60LL);
          v198[5] = v199[28];
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            is_expanded_memory = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2532,
                                   "WM:%d cache_cfg:0x%x",
                                   *v199);
            v194 = v258;
          }
          v207 = v199[13] | (v199[14] << 16);
          v198[6] = *(_DWORD *)(*((_QWORD *)v199 + 2) + 12LL);
          v198[7] = v207;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            is_expanded_memory = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2539,
                                   "WM:%d image height and width 0x%X",
                                   *v199);
            v194 = v258;
          }
          if ( *(_BYTE *)(v8 + 32) == 1 )
          {
            v208 = *(_QWORD *)(v8 + 40);
            v209 = (int *)(v208 + 48);
            v210 = (int *)(v208 + 52);
          }
          else
          {
            if ( v192 > 2 )
              goto LABEL_197;
            v209 = v195 - 1;
            v210 = v195;
          }
          v211 = *v210;
          v212 = *v209;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            v226 = v211;
            is_expanded_memory = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2551,
                                   "before stride %d",
                                   v212);
            v194 = v258;
            v211 = v226;
          }
          v213 = (v212 + 15) & 0xFFFFFFF0;
          if ( v213 != v212 && (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            v228 = v211;
            is_expanded_memory = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2555,
                                   "Warning stride %u expected %u",
                                   v212,
                                   v213);
            v194 = v258;
            v211 = v228;
          }
          v214 = v193 + 8;
          if ( v199[15] != v213 || (*((_BYTE *)v199 + 121) & 1) == 0 )
          {
            v215 = (_DWORD *)(v194 + 4LL * v214);
            v214 = v193 + 10;
            *v215 = *(_DWORD *)(*((_QWORD *)v199 + 2) + 20LL);
            v215[1] = v212;
            v216 = debug_mdl;
            v199[15] = v213;
            if ( (v216 & 0x40000000) != 0 && !debug_priority )
            {
              v227 = v211;
              is_expanded_memory = ((__int64 (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                     3,
                                     v216 & 0x40000000,
                                     4,
                                     "cam_sfe_bus_wr_update_wm",
                                     2564,
                                     "WM:%d image stride 0x%X",
                                     *v199,
                                     *(_DWORD *)(v247 + 4LL * v193));
              v194 = v258;
              v211 = v227;
            }
          }
          if ( (*((_BYTE *)v199 + 98) & 3) != 0
            || (v217 = (_DWORD *)(v194 + 4LL * v214),
                v214 += 2,
                *v217 = *(_DWORD *)(*((_QWORD *)v199 + 2) + 16LL),
                v217[1] = v199[19],
                (debug_mdl & 0x40000000) == 0)
            || debug_priority )
          {
            if ( v196 == 584 )
              goto LABEL_197;
          }
          else
          {
            v229 = v211;
            is_expanded_memory = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2574,
                                   "WM:%d h_init 0x%X",
                                   *v199);
            v211 = v229;
            if ( v196 == 584 )
              goto LABEL_197;
          }
          v218 = *(_QWORD **)(v8 + 40);
          v219 = v212 * v211;
          v220 = v199[12];
          v221 = *(_QWORD *)(*v218 + 8 * v192);
          *((_DWORD *)v218 + v192 + 2) = v220;
          v222 = v221 + v220;
          is_expanded_memory = cam_smmu_is_expanded_memory();
          if ( (is_expanded_memory & 1) != 0 )
          {
            v194 = v258;
            v223 = (unsigned __int8)v222;
            v222 >>= 8;
            v219 >>= 8;
            v224 = (_DWORD *)(v258 + 4LL * v214);
            v214 += 2;
            *v224 = *(_DWORD *)(*((_QWORD *)v199 + 2) + 64LL);
            v224[1] = v223;
            if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            {
              is_expanded_memory = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                                     3,
                                     debug_mdl & 0x40000000,
                                     4,
                                     "cam_sfe_bus_wr_update_wm",
                                     2594,
                                     "WM:%d image offset 0x%X",
                                     *v199);
              v194 = v258;
            }
          }
          else
          {
            v194 = v258;
          }
          v225 = (_DWORD *)(v194 + 4LL * v214);
          *v225 = *(_DWORD *)(*((_QWORD *)v199 + 2) + 4LL);
          v225[1] = v222;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            is_expanded_memory = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2603,
                                   "WM:%d image address 0x%x",
                                   *v199,
                                   v222);
            v194 = v258;
          }
          v225[2] = *(_DWORD *)(*((_QWORD *)v199 + 2) + 8LL);
          v225[3] = v219;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            is_expanded_memory = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                                   3,
                                   debug_mdl & 0x40000000,
                                   4,
                                   "cam_sfe_bus_wr_update_wm",
                                   2610,
                                   "WM:%d frame_inc %d expanded mem: %s",
                                   *v199,
                                   v219,
                                   "Y");
            v194 = v258;
          }
          v225[4] = **((_DWORD **)v199 + 2);
          v225[5] = v199[24];
          if ( (*((_BYTE *)v199 + 121) & 1) == 0 )
            *((_BYTE *)v199 + 121) = 1;
          v11 = v251;
          ++v192;
          v193 = v214 + 6;
          v196 += 152;
          v195 += 12;
          if ( v192 >= *(unsigned int *)(v251 + 24) )
          {
            v239 = *(__int64 (__fastcall **)(_QWORD))(v248 + 24);
            if ( *((_DWORD *)v239 - 1) != 2010610996 )
              __break(0x8228u);
            v240 = 4 * v239(v193 >> 1);
            if ( v240 > *(_DWORD *)(v8 + 24) )
            {
              v232 = "cam_sfe_bus_wr_update_wm";
              v233 = 2633;
              goto LABEL_364;
            }
            v243 = *(_DWORD **)(v248 + 120);
            v244 = *(_QWORD *)(v8 + 16);
            if ( *(v243 - 1) != -1401492769 )
              __break(0x8228u);
            ((void (__fastcall *)(__int64, _QWORD, __int64))v243)(v244, v193 >> 1, v258);
            v9 = 0;
            *(_DWORD *)(v8 + 28) = v240;
            goto LABEL_17;
          }
        }
      case 4u:
        v90 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
        if ( !v90 || (v91 = *(_QWORD *)(v90 + 88)) == 0 )
        {
          v23 = "cam_sfe_bus_wr_update_hfr";
          v19 = "Invalid data";
          v20 = 3;
          v21 = 0x40000000;
          v22 = 1;
          v24 = 2828;
          break;
        }
        LODWORD(v92) = *(_DWORD *)(v90 + 24);
        if ( !(_DWORD)v92 )
          goto LABEL_271;
        v93 = *(_DWORD **)(a3 + 40);
        v94 = 0;
        v95 = 0;
        v96 = 24;
        v97 = *(_QWORD *)(v90 + 8) + 56LL;
        do
        {
          if ( (unsigned int)v95 >= 0x70 )
          {
            v189 = "cam_sfe_bus_wr_update_hfr";
            v190 = 2840;
LABEL_355:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64))cam_print_log)(
              3,
              0x40000000,
              1,
              v189,
              v190,
              "reg_val_pair %d exceeds the array limit %zu",
              v95,
              168);
            v9 = -12;
            goto LABEL_17;
          }
          v98 = *(unsigned int **)(*(_QWORD *)(v90 + 32) + v96);
          if ( v98[23] != v93[3] || (*((_BYTE *)v98 + 122) & 1) == 0 )
          {
            v99 = (unsigned int)v95;
            v95 = (unsigned int)(v95 + 2);
            v100 = (_DWORD *)(v97 + 4 * v99);
            *v100 = *(_DWORD *)(*((_QWORD *)v98 + 2) + 56LL);
            v100[1] = v93[3];
            v101 = debug_mdl;
            v98[23] = v93[3];
            if ( (v101 & 0x40000000) != 0 && !debug_priority )
            {
              v253 = v95;
              ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                v101 & 0x40000000,
                4,
                "cam_sfe_bus_wr_update_hfr",
                2854,
                "WM:%d framedrop pattern 0x%X",
                *v98);
              v95 = v253;
            }
          }
          if ( v98[22] != v93[4] || (*((_BYTE *)v98 + 122) & 1) == 0 )
          {
            v102 = (_DWORD *)(v97 + 4LL * (unsigned int)v95);
            v95 = (unsigned int)(v95 + 2);
            *v102 = *(_DWORD *)(*((_QWORD *)v98 + 2) + 52LL);
            v102[1] = v93[4];
            v103 = debug_mdl;
            v98[22] = v93[4];
            if ( (v103 & 0x40000000) != 0 && !debug_priority )
            {
              v254 = v95;
              ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                v103 & 0x40000000,
                4,
                "cam_sfe_bus_wr_update_hfr",
                2865,
                "WM:%d framedrop period 0x%X",
                *v98);
              v95 = v254;
            }
          }
          if ( v98[20] != v93[2] || (*((_BYTE *)v98 + 122) & 1) == 0 )
          {
            v104 = (_DWORD *)(v97 + 4LL * (unsigned int)v95);
            v95 = (unsigned int)(v95 + 2);
            *v104 = *(_DWORD *)(*((_QWORD *)v98 + 2) + 44LL);
            v104[1] = v93[2];
            v105 = debug_mdl;
            v98[20] = v93[2];
            if ( (v105 & 0x40000000) != 0 && !debug_priority )
            {
              v255 = v95;
              ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                3,
                v105 & 0x40000000,
                4,
                "cam_sfe_bus_wr_update_hfr",
                2877,
                "WM:%d irq subsample period 0x%X",
                *v98);
              v95 = v255;
            }
          }
          if ( v98[21] == v93[1] && (*((_BYTE *)v98 + 122) & 1) != 0
            || (v106 = (_DWORD *)(v97 + 4LL * (unsigned int)v95),
                v95 = (unsigned int)(v95 + 2),
                *v106 = *(_DWORD *)(*((_QWORD *)v98 + 2) + 48LL),
                v106[1] = v93[1],
                v107 = debug_mdl,
                v98[21] = v93[1],
                (v107 & 0x40000000) == 0)
            || debug_priority )
          {
            if ( (*((_BYTE *)v98 + 122) & 1) != 0 )
              goto LABEL_131;
LABEL_153:
            *((_BYTE *)v98 + 122) = 1;
            goto LABEL_131;
          }
          v256 = v95;
          ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
            3,
            v107 & 0x40000000,
            4,
            "cam_sfe_bus_wr_update_hfr",
            2889,
            "WM:%d irq subsample pattern 0x%X",
            *v98);
          v95 = v256;
          if ( (*((_BYTE *)v98 + 122) & 1) == 0 )
            goto LABEL_153;
LABEL_131:
          v92 = *(unsigned int *)(v90 + 24);
          ++v94;
          v96 += 152;
        }
        while ( v94 < v92 );
        if ( (unsigned int)v95 < 2 )
        {
LABEL_271:
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            v186 = "cam_sfe_bus_wr_update_hfr";
            v187 = debug_mdl & 0x40000000;
            v188 = 2920;
            v191 = (unsigned int)v92;
            goto LABEL_375;
          }
          goto LABEL_352;
        }
        v236 = (unsigned int)v95 >> 1;
        v237 = *(__int64 (__fastcall **)(_QWORD))(v91 + 24);
        if ( *((_DWORD *)v237 - 1) != 2010610996 )
          __break(0x8228u);
        v238 = 4 * v237((unsigned int)v95 >> 1);
        if ( v238 <= *(_DWORD *)(v8 + 24) )
        {
          v241 = *(_DWORD **)(v91 + 120);
          v242 = *(_QWORD *)(v8 + 16);
          if ( *(v241 - 1) != -1401492769 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD, __int64))v241)(v242, v236, v97);
          v9 = 0;
          *(_DWORD *)(v8 + 28) = v238;
        }
        else
        {
          v232 = "cam_sfe_bus_wr_update_hfr";
          v233 = 2907;
LABEL_364:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x40000000,
            1,
            v232,
            v233,
            "Failed! Buf size:%d insufficient, expected size:%d");
          v9 = -12;
        }
LABEL_17:
        _ReadStatusReg(SP_EL0);
        return v9;
      case 6u:
        v9 = 0;
        **(_DWORD **)(a3 + 40) = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)a3 + 24LL) + 96LL) == 1;
        goto LABEL_17;
      case 8u:
        v46 = *(_QWORD *)(a3 + 8);
        v47 = *(_QWORD *)(v46 + 24);
        if ( v47 )
        {
          v48 = *(_DWORD *)(v46 + 4);
          if ( v48 < 0x6000 || v48 >= *(_DWORD *)(is_expanded_memory + 27552) || !*(_DWORD *)(v47 + 24) )
            goto LABEL_245;
          v49 = 0;
          v50 = 24;
          v51 = 3 * **(_DWORD **)(a3 + 16) * *(_DWORD *)a3 + 3 * (unsigned __int8)v48;
          while ( 1 )
          {
            v53 = *(_QWORD *)(v8 + 16) + 16LL * (unsigned int)(v51 + v49);
            v54 = *(_QWORD *)(*(_QWORD *)(v47 + 32) + v50);
            v55 = *(_DWORD *)(v53 + 28);
            v56 = *(_BYTE *)(v54 + 98);
            *(_DWORD *)(v54 + 52) = v55;
            v57 = *(_DWORD *)(v53 + 24);
            if ( (v56 & 3) != 0 )
            {
              *(_DWORD *)(v54 + 48) = v57;
              v52 = debug_mdl;
              if ( (debug_mdl & 0x40000000) != 0 )
              {
LABEL_53:
                if ( !debug_priority )
                  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    v52 & 0x40000000,
                    4,
                    "cam_sfe_bus_wr_update_stripe_cfg",
                    2977,
                    "out_type:0x%X WM:%d width:%d offset:0x%X h_init:%d",
                    *(_DWORD *)(*(_QWORD *)(v8 + 8) + 4LL),
                    *(_DWORD *)v54,
                    v55,
                    *(_DWORD *)(v54 + 48),
                    *(_DWORD *)(v54 + 76));
              }
            }
            else
            {
              *(_DWORD *)(v54 + 76) = v57;
              v52 = debug_mdl;
              if ( (debug_mdl & 0x40000000) != 0 )
                goto LABEL_53;
            }
            ++v49;
            v9 = 0;
            v50 += 152;
            if ( v49 >= *(unsigned int *)(v47 + 24) )
              goto LABEL_17;
          }
        }
        v23 = "cam_sfe_bus_wr_update_stripe_cfg";
        v19 = "Failed! Invalid data";
        v20 = 3;
        v21 = 0x40000000;
        v22 = 1;
        v24 = 2944;
        break;
      case 0xEu:
        goto LABEL_17;
      case 0x11u:
        v69 = *(_DWORD *)(a3 + 8) - 24576;
        if ( v69 < 0x12 )
        {
          cam_sfe_bus_wr_print_dimensions(dword_44E5D8[v69], is_expanded_memory);
          v9 = 0;
          goto LABEL_17;
        }
        v9 = 0;
        if ( (debug_mdl & 0x40000000) == 0 || debug_priority )
          goto LABEL_17;
        v153 = "cam_sfe_bus_wr_process_cmd";
        v154 = "No a SFE write res: 0x%x - skip dump";
        v155 = debug_mdl & 0x40000000;
        v156 = 4;
        v157 = 3517;
        goto LABEL_226;
      case 0x1Au:
        v108 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
        if ( !v108 || !*(_QWORD *)(v108 + 88) || (v109 = *(_DWORD **)(a3 + 40)) == nullptr )
        {
          v23 = "cam_sfe_bus_wr_update_wm_config";
          v19 = "Invalid data";
          v20 = 3;
          v21 = 0x40000000;
          v22 = 1;
          v24 = 3004;
          break;
        }
        if ( !*(_DWORD *)(v108 + 24) )
          goto LABEL_245;
        v110 = 0;
        while ( 1 )
        {
          v111 = v109[1];
          v112 = *(_DWORD **)(*(_QWORD *)(v108 + 32) + 152LL * (int)v110 + 24);
          if ( v111 >= 3 )
            break;
          v112[24] = (v111 << 16) | (2 * v109[5]) | 1;
          v112[13] = v109[4];
          v113 = v109[9];
          if ( v113 )
          {
            packer_fmt = cam_sfe_bus_get_packer_fmt(*(_QWORD *)(v108 + 16));
            if ( packer_fmt != 17 )
            {
              if ( (unsigned int)(v113 - 14) <= 3 )
                packer_fmt |= 1 << *(_DWORD *)(*((_QWORD *)v112 + 1) + 27440LL);
              v112[17] = packer_fmt;
            }
          }
          if ( *(_DWORD *)v108 <= 4u )
          {
            v115 = v109[1];
            v112[18] = v115;
            if ( !v115 )
              cam_sfe_bus_config_rdi_wm(v112);
          }
          v116 = v109[3] >> (v110 == 1);
          v117 = debug_mdl;
          v112[14] = v116;
          v118 = v109[7];
          v112[12] = v118;
          if ( (v117 & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              v117 & 0x40000000,
              4,
              "cam_sfe_bus_wr_update_wm_config",
              3064,
              "WM:%d en_cfg:0x%X height:%d width:%d offset:%u packer_fmt: 0x%x",
              *v112,
              v112[24],
              v116,
              v112[13],
              v118,
              v112[17]);
          ++v110;
          v9 = 0;
          if ( v110 >= *(_DWORD *)(v108 + 24) )
            goto LABEL_17;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_bus_wr_update_wm_config",
          3013,
          "Invalid wm_mode: 0x%X WM:%d",
          v111,
          *v112);
        goto LABEL_16;
      case 0x25u:
        v119 = *(_DWORD *)(a3 + 4) - 24576;
        if ( v119 >= 0x12 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_sfe_bus_get_last_consumed_addr",
            3456,
            "invalid res id:%u",
            18);
          *(_DWORD *)(v8 + 12) = 0;
        }
        else
        {
          v120 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(is_expanded_memory + 27576)
                                                   + 152LL * qword_44E620[v119]
                                                   + 24)
                                       + 32LL)
                           + 24LL);
          *(_DWORD *)(a3 + 12) = cam_io_r_mb(
                                   *(_QWORD *)(*(_QWORD *)(v120 + 8) + 8LL)
                                 + *(unsigned int *)(*(_QWORD *)(v120 + 16) + 68LL));
        }
        goto LABEL_16;
      case 0x26u:
        v8 = *(_QWORD *)(a3 + 40);
        if ( !v8 )
        {
          v23 = "cam_sfe_bus_wr_get_res_for_mid";
          v19 = "invalid get resource for mid paramas";
          v20 = 3;
          v21 = 0x40000000;
          v22 = 1;
          v24 = 3189;
          break;
        }
        v129 = *(_DWORD *)(is_expanded_memory + 27548);
        if ( !v129 )
          goto LABEL_225;
        v130 = *(_QWORD *)(is_expanded_memory + 27608);
        v131 = 0;
        while ( 1 )
        {
          v132 = (_DWORD *)(v130 + 56LL * v131);
          v133 = v131;
          v134 = v132[8];
          if ( v134 )
          {
            v135 = *(_DWORD *)v8;
            if ( v132[4] == *(_DWORD *)v8 )
              goto LABEL_260;
            if ( v134 != 1 )
            {
              if ( v132[5] == v135 )
                goto LABEL_260;
              if ( v134 != 2 )
              {
                if ( v132[6] == v135 )
                  goto LABEL_260;
                if ( v134 != 3 )
                {
                  if ( v132[7] == v135 )
                  {
LABEL_260:
                    v185 = is_expanded_memory;
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      0x40000000,
                      3,
                      "cam_sfe_bus_wr_get_res_for_mid",
                      3212,
                      "match mid :%d  out resource: %s 0x%x found",
                      v135,
                      *(const char **)(v130 + 56LL * v131 + 48),
                      *(_DWORD *)(*(_QWORD *)(is_expanded_memory + 27576) + 152LL * v131 + 4));
                    v9 = 0;
                    *(_DWORD *)(v8 + 4) = *(_DWORD *)(*(_QWORD *)(v185 + 27576) + 152LL * v133 + 4);
                    goto LABEL_17;
                  }
                  if ( v134 != 4 )
                    goto LABEL_197;
                }
              }
            }
          }
          ++v131;
          if ( v129 == v133 + 1 )
          {
LABEL_225:
            v153 = "cam_sfe_bus_wr_get_res_for_mid";
            v154 = "mid:%d does not match with any out resource";
            v155 = 0x40000000;
            v156 = 3;
            v157 = 3205;
LABEL_226:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
              3,
              v155,
              v156,
              v153,
              v157,
              v154);
            v9 = 0;
            goto LABEL_17;
          }
        }
      case 0x2Bu:
        v128 = *(_DWORD *)a3;
        if ( *(_BYTE *)(a3 + 76) == 1 )
          cam_sfe_bus_parse_cache_cfg(0, v128, is_expanded_memory + 27508);
        else
          *(_DWORD *)(is_expanded_memory + 27472) = v128;
        v9 = 0;
        *(_DWORD *)(v10 + 2900) = *(_DWORD *)(v8 + 44);
        *(_DWORD *)(v10 + 2904) = *(_DWORD *)(v8 + 48);
        *(_DWORD *)(v10 + 2908) = *(_DWORD *)(v8 + 52);
        *(_DWORD *)(v10 + 2912) = *(_DWORD *)(v8 + 56);
        *(_DWORD *)(v10 + 2916) = *(_DWORD *)(v8 + 60);
        *(_DWORD *)(v10 + 2920) = *(_DWORD *)(v8 + 64);
        *(_DWORD *)(v10 + 2924) = *(_DWORD *)(v8 + 68);
        *(_DWORD *)(v10 + 2928) = *(_DWORD *)(v8 + 72);
        goto LABEL_17;
      case 0x2Cu:
        v9 = 0;
        *(_DWORD *)a3 = *(_DWORD *)(is_expanded_memory + 27552);
        *(_DWORD *)(a3 + 8) = *(_DWORD *)(*(_QWORD *)(is_expanded_memory + 48) + 104LL);
        goto LABEL_17;
      case 0x38u:
        v70 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
        if ( v70 )
        {
          v71 = *(_DWORD *)(v70 + 24);
          v72 = *(_DWORD *)(*(_QWORD *)(a3 + 40) + 20LL);
          if ( v72 == v71 )
          {
            if ( !v72 )
              goto LABEL_245;
            v73 = 0;
            v74 = 24;
            while ( 1 )
            {
              v75 = *(_DWORD **)(*(_QWORD *)(v70 + 32) + v74);
              v76 = v75[13] | (v75[14] << 16);
              cam_io_w_mb(v76, *(_QWORD *)(*((_QWORD *)v75 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v75 + 2) + 12LL));
              v77 = debug_priority;
              v78 = debug_mdl & 0x40000000;
              if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v78,
                  4,
                  "cam_sfe_bus_wr_config_wm",
                  2699,
                  "WM:%d image height and width 0x%X",
                  *v75,
                  v76);
                v77 = debug_priority;
                v78 = debug_mdl & 0x40000000;
              }
              v79 = *(_QWORD *)(v8 + 40);
              v81 = *(_DWORD *)(v79 + 48);
              v80 = *(_DWORD *)(v79 + 52);
              if ( v78 && !v77 )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  v78,
                  4,
                  "cam_sfe_bus_wr_config_wm",
                  2706,
                  "before stride %d",
                  v81);
              v82 = (v81 + 15) & 0xFFFFFFF0;
              if ( v82 != v81 && v82 != v75[15] )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  0x40000000,
                  2,
                  "cam_sfe_bus_wr_config_wm",
                  2711,
                  "Warning stride %u expected %u",
                  v81,
                  v82);
              if ( v75[15] != v82 || (*((_BYTE *)v75 + 121) & 1) == 0 )
              {
                cam_io_w_mb(
                  v81,
                  *(_QWORD *)(*((_QWORD *)v75 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v75 + 2) + 20LL));
                v83 = debug_mdl;
                v75[15] = v82;
                if ( (v83 & 0x40000000) != 0 && !debug_priority )
                  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    v83 & 0x40000000,
                    4,
                    "cam_sfe_bus_wr_config_wm",
                    2719,
                    "WM:%d image stride 0x%X",
                    *v75,
                    v82);
              }
              if ( (*((_BYTE *)v75 + 98) & 3) == 0 )
              {
                cam_io_w_mb(
                  (unsigned int)v75[19],
                  *(_QWORD *)(*((_QWORD *)v75 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v75 + 2) + 16LL));
                if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x40000000,
                    4,
                    "cam_sfe_bus_wr_config_wm",
                    2729,
                    "WM:%d h_init 0x%X",
                    *v75,
                    v75[19]);
              }
              v84 = v80 * v81;
              v85 = *(_QWORD *)(**(_QWORD **)(v8 + 40) + 8 * v73) + (unsigned int)v75[12];
              if ( (cam_smmu_is_expanded_memory() & 1) != 0 )
              {
                if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 0x40000000,
                    4,
                    "cam_sfe_bus_wr_config_wm",
                    2742,
                    "WM:%d image address offset: 0x%x",
                    *v75,
                    (unsigned __int8)v85);
                v84 >>= 8;
                cam_io_w_mb(
                  (unsigned __int8)v85,
                  *(_QWORD *)(*((_QWORD *)v75 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v75 + 2) + 64LL));
                v85 >>= 8;
              }
              if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x40000000,
                  4,
                  "cam_sfe_bus_wr_config_wm",
                  2750,
                  "WM:%d image address: 0x%x, offset: 0x%x",
                  *v75,
                  v85,
                  v75[12]);
              cam_io_w_mb(
                (unsigned int)v85,
                *(_QWORD *)(*((_QWORD *)v75 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v75 + 2) + 4LL));
              cam_io_w_mb(v84, *(_QWORD *)(*((_QWORD *)v75 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v75 + 2) + 8LL));
              if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x40000000,
                  4,
                  "cam_sfe_bus_wr_config_wm",
                  2760,
                  "WM:%d frame_inc: %d expanded_mem: %s",
                  *v75,
                  v84,
                  "Y");
              v86 = *(unsigned int *)(v10 + 2892);
              v87 = v75[28];
              v75[28] = v86;
              if ( (*(_BYTE *)(v10 + 2941) & 1) == 0 && *((_BYTE *)v75 + 120) == 1 )
              {
                v88 = v75[29];
                v89 = (v88 << 8) | 0x30;
                v75[28] = v89;
                v86 = *(_BYTE *)(v10 + 2942) == 1 ? *(_DWORD *)(v10 + 2932) | (unsigned int)v89 : (v88 << 8) | 0x31u;
                v75[28] = v86;
                if ( *(_BYTE *)(v10 + 2945) == 1 && v87 != (_DWORD)v86 )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x40000000,
                    3,
                    "cam_sfe_bus_wr_config_wm",
                    2779,
                    "SFE:%d Scratch Buff WM:%d current_scid:%d cache_cfg:0x%x",
                    **((_DWORD **)v75 + 1),
                    *v75,
                    v88,
                    v86);
                  v86 = (unsigned int)v75[28];
                }
              }
              cam_io_w_mb(v86, *(_QWORD *)(*((_QWORD *)v75 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v75 + 2) + 60LL));
              if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x40000000,
                  4,
                  "cam_sfe_bus_wr_config_wm",
                  2787,
                  "WM:%d cache_cfg:0x%x",
                  *v75,
                  v75[28]);
              cam_io_w_mb(
                (unsigned int)v75[17],
                *(_QWORD *)(*((_QWORD *)v75 + 1) + 8LL) + *(unsigned int *)(*((_QWORD *)v75 + 2) + 24LL));
              if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x40000000,
                  4,
                  "cam_sfe_bus_wr_config_wm",
                  2793,
                  "WM:%d packer_cfg 0x%X",
                  *v75,
                  v75[17]);
              cam_io_w_mb((unsigned int)v75[24], *(_QWORD *)(*((_QWORD *)v75 + 1) + 8LL) + **((unsigned int **)v75 + 2));
              if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
                break;
              if ( (*((_BYTE *)v75 + 121) & 1) == 0 )
                goto LABEL_123;
LABEL_76:
              ++v73;
              v9 = 0;
              v74 += 152;
              if ( v73 >= *(unsigned int *)(v70 + 24) )
                goto LABEL_17;
            }
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_bus_wr_config_wm",
              2800,
              "WM:%d en_cfg 0x%X",
              *v75,
              v75[24]);
            if ( (*((_BYTE *)v75 + 121) & 1) != 0 )
              goto LABEL_76;
LABEL_123:
            *((_BYTE *)v75 + 121) = 1;
            goto LABEL_76;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            1,
            "cam_sfe_bus_wr_config_wm",
            2686,
            "Failed! Invalid number buffers:%d required:%d",
            v72,
            v71);
LABEL_16:
          v9 = -22;
          goto LABEL_17;
        }
        v23 = "cam_sfe_bus_wr_config_wm";
        v19 = "Invalid data";
        v20 = 3;
        v21 = 0x40000000;
        v22 = 1;
        v24 = 2679;
        break;
      case 0x3Eu:
        v58 = *(_QWORD *)(*(_QWORD *)(a3 + 8) + 24LL);
        if ( !v58 )
        {
          v23 = "cam_sfe_bus_wr_cache_config";
          v19 = "Invalid data";
          v20 = 3;
          v21 = 0x40000000;
          v22 = 1;
          v24 = 3355;
          break;
        }
        if ( (*(_BYTE *)(is_expanded_memory + 27516) & 1) != 0 || !*(_DWORD *)(v58 + 24) )
          goto LABEL_245;
        v59 = 0;
        v60 = "true";
        do
        {
          v61 = *(int **)(*(_QWORD *)(v58 + 32) + 152LL * (int)v59 + 24);
          *((_BYTE *)v61 + 120) = *(_BYTE *)(v8 + 16);
          v61[29] = *(_DWORD *)(v8 + 20);
          *(_BYTE *)v8 = 1;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
          {
            v62 = *((int **)v61 + 1);
            v63 = *((unsigned __int8 *)v61 + 120);
            v64 = *v61;
            v65 = v61[29];
            v66 = *v62;
            if ( v63 )
              v67 = v60;
            else
              v67 = "false";
            v68 = v60;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_bus_wr_cache_config",
              3373,
              "SFE:%d WM:%d cache_enable:%s scid:%u",
              v66,
              v64,
              v67,
              v65);
            v60 = v68;
          }
          ++v59;
          v9 = 0;
        }
        while ( v59 < *(_DWORD *)(v58 + 24) );
        goto LABEL_17;
      case 0x40u:
        v35 = *(_QWORD *)(*(_QWORD *)a3 + 24LL);
        if ( !v35 || !*(_QWORD *)(v35 + 88) )
        {
          v23 = "cam_sfe_bus_wr_update_bw_limiter";
          v19 = "Invalid data";
          v20 = 3;
          v21 = 0x40000000;
          v22 = 1;
          v24 = 3089;
          break;
        }
        if ( !*(_DWORD *)(v35 + 24) )
        {
          if ( (debug_mdl & 0x40000000) == 0 || debug_priority )
            goto LABEL_352;
          v186 = "cam_sfe_bus_wr_update_bw_limiter";
          v187 = debug_mdl & 0x40000000;
          v188 = 3171;
LABEL_374:
          v191 = 0;
LABEL_375:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            v187,
            4,
            v186,
            v188,
            "No reg val pairs. num_wms: %u",
            v191);
LABEL_352:
          v9 = 0;
          *(_DWORD *)(v8 + 28) = 0;
          goto LABEL_17;
        }
        v36 = *(_QWORD *)(a3 + 40);
        v37 = 0;
        v38 = 128;
        v39 = (int *)(*(_QWORD *)(v35 + 8) + 60LL);
        v250 = *(_QWORD *)(v35 + 8);
        v252 = *(_QWORD *)(v35 + 88);
        while ( v38 != 584 )
        {
          v40 = *(unsigned int **)(*(_QWORD *)(v35 + 32) + v38 - 104);
          v41 = *(_DWORD *)(*((_QWORD *)v40 + 2) + 104LL);
          if ( !v41 )
          {
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              0x40000000,
              1,
              "cam_sfe_bus_wr_update_bw_limiter",
              3115,
              "WM: %d %s has no support for bw limiter",
              *v40);
            goto LABEL_16;
          }
          v42 = *(_DWORD *)(v36 + 8 + 4 * v37);
          v43 = *(_DWORD *)(*((_QWORD *)v40 + 1) + 27444LL);
          if ( v42 > v43 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x40000000,
              2,
              "cam_sfe_bus_wr_update_bw_limiter",
              3127,
              "Invalid counter limit: 0x%x capping to max: 0x%x",
              v42,
              v43);
            v42 = *(_DWORD *)(*((_QWORD *)v40 + 1) + 27444LL);
            v41 = *(_DWORD *)(*((_QWORD *)v40 + 2) + 104LL);
          }
          if ( v42 )
            v44 = *(_DWORD *)(v36 + 4) == 0;
          else
            v44 = 1;
          if ( v44 )
            v45 = 0;
          else
            v45 = 2 * v42 + 1;
          *(v39 - 1) = v41;
          *v39 = v45;
          if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000000,
              4,
              "cam_sfe_bus_wr_update_bw_limiter",
              3143,
              "WM: %d %s bw_limter: 0x%x",
              *v40,
              (const char *)(*(_QWORD *)(v35 + 32) + v38),
              v45);
          ++v37;
          v38 += 152;
          v39 += 2;
          if ( v37 >= *(unsigned int *)(v35 + 24) )
            goto LABEL_342;
        }
        LODWORD(v37) = 3;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          2,
          "cam_sfe_bus_wr_update_bw_limiter",
          3106,
          "Num of WMs: %d exceeded max planes",
          3);
LABEL_342:
        v230 = *(__int64 (__fastcall **)(_QWORD))(v252 + 24);
        if ( *((_DWORD *)v230 - 1) != 2010610996 )
          __break(0x8228u);
        v231 = 4 * v230((unsigned int)v37);
        if ( v231 > *(_DWORD *)(v8 + 24) )
        {
          v232 = "cam_sfe_bus_wr_update_bw_limiter";
          v233 = 3158;
          goto LABEL_364;
        }
        v234 = *(_DWORD **)(v252 + 120);
        v235 = *(_QWORD *)(v8 + 16);
        if ( *(v234 - 1) != -1401492769 )
          __break(0x8228u);
        ((void (__fastcall *)(__int64, _QWORD, __int64))v234)(v235, (unsigned int)v37, v250 + 56);
        v9 = 0;
        *(_DWORD *)(v8 + 28) = v231;
        goto LABEL_17;
      case 0x46u:
        if ( *(_QWORD *)(a3 + 8) < 0x18u )
        {
          v121 = 0;
          goto LABEL_264;
        }
        v158 = *(_QWORD *)a3;
        v257 = is_expanded_memory;
        v159 = *(_QWORD *)(*(_QWORD *)(is_expanded_memory + 16) + 112LL);
        applied_src_clk = cam_soc_util_get_applied_src_clk((_QWORD *)(v159 + 96), 1);
        v161 = v257;
        *(_QWORD *)(v158 + 8) = applied_src_clk;
        *(_BYTE *)(v158 + 21) = *(_DWORD *)(*(_QWORD *)(v257 + 16) + 4LL);
        *(_BYTE *)(v158 + 20) = *(_DWORD *)(v159 + 92);
        *(_QWORD *)v158 = *(_QWORD *)v8 + 24LL;
        v162 = *(unsigned int *)(v10 + 2972);
        if ( (_DWORD)v162 )
        {
          v163 = 0;
          v164 = 0;
          v165 = 24;
          v249 = v10;
          while ( 1 )
          {
            v166 = *(_QWORD *)(v161 + 27576) + 152 * v163;
            v167 = *(_QWORD *)(v166 + 24);
            if ( v167 && *(_DWORD *)(v167 + 24) )
            {
              v168 = 0;
              v169 = 0;
              do
              {
                v170 = v165 + 56LL;
                if ( v170 > *(_QWORD *)(v8 + 8) )
                {
                  v164 += v169;
                  goto LABEL_263;
                }
                v171 = (_DWORD *)(*(_QWORD *)v158 + 56LL * (unsigned int)(v164 + v169));
                v172 = *(_DWORD **)(*(_QWORD *)(v167 + 32) + v168 + 24);
                *v171 = v172[13];
                v171[8] = *v172;
                v171[1] = v172[14];
                v171[2] = v172[15];
                v171[6] = v172[24];
                v171[3] = v172[19];
                v171[7] = v172[16];
                v171[4] = v172[26];
                v171[5] = v172[27];
                v171[9] = *(_DWORD *)(v166 + 8);
                scnprintf(v171 + 10, 16, "%s", (const char *)(*(_QWORD *)(v167 + 32) + v168 + 128));
                ++v169;
                v168 += 152;
                v165 += 56;
              }
              while ( v169 < *(unsigned int *)(v167 + 24) );
              v161 = v257;
              v164 += v169;
              v165 = v170;
              v162 = *(unsigned int *)(v249 + 2972);
            }
            if ( ++v163 >= v162 )
              goto LABEL_263;
          }
        }
        v164 = 0;
        v165 = 24;
LABEL_263:
        v121 = v165;
        *(_DWORD *)(v158 + 16) = v164;
LABEL_264:
        v9 = 0;
        *(_QWORD *)(v8 + 16) = v121;
        goto LABEL_17;
      case 0x47u:
        v122 = *(_QWORD *)(*(_QWORD *)(is_expanded_memory + 16) + 112LL);
        if ( *(_DWORD *)(v122 + 92) )
        {
          v123 = is_expanded_memory;
          v124 = cam_common_user_dump_helper(
                   (_QWORD *)v8,
                   (__int64 (__fastcall *)(__int64, __int64))cam_common_user_dump_clock,
                   v122,
                   8,
                   "CLK_RATE_PRINT:",
                   a6,
                   a7,
                   a8,
                   v245);
          if ( v124 )
          {
            v9 = v124;
            v126 = "SFE BUS WR: Clock dump failed, rc:%d";
            v127 = 2110;
LABEL_181:
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
              3,
              8,
              1,
              "cam_sfe_bus_wr_user_dump",
              v127,
              v126,
              v9);
            goto LABEL_17;
          }
          if ( !*(_DWORD *)(v10 + 2972) )
            goto LABEL_245;
          v173 = 0;
          v174 = v123;
          while ( 1 )
          {
            v175 = *(_QWORD *)(v174 + 27608);
            if ( !v175 )
              break;
            v136 = *(unsigned int *)(v175 + 56LL * (int)v173);
            if ( (unsigned int)v136 >= 0x12 )
              goto LABEL_372;
            v176 = v10;
            v177 = *(_QWORD *)(v174 + 27576) + 152LL * (unsigned int)v136;
            if ( *(_DWORD *)(v177 + 8) > 1u )
            {
              v178 = *(_QWORD *)(v177 + 24);
              if ( v178 )
              {
                v179 = *(unsigned int *)(v178 + 24);
                if ( (_DWORD)v179 )
                {
                  v180 = 0;
                  for ( i = 0; i < v179; ++i )
                  {
                    v182 = *(_QWORD *)(v178 + 32) + v180;
                    v183 = *(_QWORD *)(v182 + 24);
                    if ( v183 )
                    {
                      v184 = cam_common_user_dump_helper(
                               (_QWORD *)v8,
                               (__int64 (__fastcall *)(__int64, __int64))cam_sfe_bus_wr_user_dump_info,
                               v183,
                               4,
                               "SFE_BUS_CLIENT.%s.%d:",
                               v182 + 128,
                               **(unsigned int **)(v178 + 8),
                               v125,
                               v246);
                      if ( v184 )
                      {
                        v9 = v184;
                        v126 = "SFE BUS WR: Info dump failed, rc:%d";
                        v127 = 2146;
                        goto LABEL_181;
                      }
                      v179 = *(unsigned int *)(v178 + 24);
                      v174 = v123;
                    }
                    v180 += 152;
                  }
                }
              }
            }
            else if ( (debug_mdl & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 8,
                4,
                "cam_sfe_bus_wr_user_dump",
                2127,
                "SFE BUS WR: path inactive res ID: %d, continuing",
                *(_DWORD *)(v177 + 4));
              v174 = v123;
            }
            ++v173;
            v10 = v176;
            v9 = 0;
            if ( v173 >= *(_DWORD *)(v176 + 2972) )
              goto LABEL_17;
          }
          v136 = 18;
LABEL_372:
          v151 = "cam_sfe_bus_wr_user_dump";
          v147 = "Invalid sfe out type:%d";
          v148 = 3;
          v149 = 0x40000000;
          v150 = 1;
          v152 = 2119;
LABEL_224:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            v148,
            v149,
            v150,
            v151,
            v152,
            v147,
            v136);
          goto LABEL_16;
        }
        v23 = "cam_sfe_bus_wr_user_dump";
        v19 = "SFE BUS powered down, continuing";
        v20 = 3;
        v21 = 8;
        v22 = 2;
        v24 = 2102;
        break;
      case 0x4Du:
        v136 = *(unsigned int *)(a3 + 8);
        if ( (_DWORD)v136 != 400 )
        {
          v151 = "cam_sfe_bus_wr_irq_inject";
          v147 = "Invalid reg_unit %d";
          v148 = 3;
          v149 = 8;
          v150 = 2;
          v152 = 3240;
          goto LABEL_224;
        }
        v142 = *(_QWORD *)(is_expanded_memory + 27616);
        v143 = *(_QWORD *)(v142 + 80);
        if ( v143 )
        {
          v144 = *(_QWORD *)(is_expanded_memory + 27528);
          cam_io_w_mb(*(unsigned int *)(a3 + 12), *(_QWORD *)(v144 + 288) + *(unsigned int *)(v143 + 12));
          cam_io_w_mb(16, *(_QWORD *)(v144 + 288) + *(unsigned int *)(v142 + 88));
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000000,
            3,
            "cam_sfe_bus_wr_irq_inject",
            3256,
            "Injected : irq_mask %#x set_reg_offset %#x",
            *(_DWORD *)(v8 + 12),
            *(_DWORD *)(v143 + 12));
          v9 = 0;
          goto LABEL_17;
        }
        v23 = "cam_sfe_bus_wr_irq_inject";
        v19 = "Invalid inject_reg";
        v20 = 3;
        v21 = 8;
        v22 = 1;
        v24 = 3246;
        break;
      case 0x4Eu:
        goto LABEL_198;
      case 0x54u:
        v26 = *(unsigned __int8 *)(is_expanded_memory + 27540);
        v259 = 0;
        if ( v26 != 1 )
          goto LABEL_245;
        v27 = *(_DWORD *)(is_expanded_memory + 27536);
        memset(&v260[26], 0, 48);
        *(_DWORD *)(is_expanded_memory + 27536) = v27 + 1;
        v28 = *(_QWORD *)(is_expanded_memory + 48);
        v29 = *(_DWORD *)(v28 + 104);
        memset(v260, 0, 208);
        if ( !v29 )
          goto LABEL_245;
        v8 = 0;
        v30 = 0;
        v31 = is_expanded_memory + 27476;
        while ( 1 )
        {
          v32 = 8 * v8;
          while ( 1 )
          {
            v33 = is_expanded_memory;
            is_expanded_memory = cam_io_r_mb(*(_QWORD *)(is_expanded_memory + 8) + *(unsigned int *)(v28 + 108));
            if ( (((unsigned int)is_expanded_memory >> v8) & 1) != 0 )
              break;
            v28 = *(_QWORD *)(v33 + 48);
            ++v8;
            is_expanded_memory = v33;
            v32 += 8;
            if ( v8 >= *(unsigned int *)(v28 + 104) )
            {
              if ( (v30 & 1) != 0 )
                goto LABEL_234;
LABEL_245:
              v9 = 0;
              goto LABEL_17;
            }
          }
          if ( v8 >= 8 )
            break;
          v34 = cam_io_r_mb(*(_QWORD *)(v33 + 8) + *(unsigned int *)(*(_QWORD *)(v33 + 48) + v32 + 116));
          cam_io_w_mb(
            *(unsigned int *)(v31 + 4 * v8),
            *(_QWORD *)(v33 + 8) + *(unsigned int *)(*(_QWORD *)(v33 + 48) + v32 + 112));
          cam_print_to_buffer(
            (__int64)v260,
            0x100u,
            &v259,
            3u,
            0x40000000u,
            "cnt%d: 0x%x ",
            (unsigned int)v8,
            v34,
            v245);
          v28 = *(_QWORD *)(v33 + 48);
          ++v8;
          is_expanded_memory = v33;
          v30 = 1;
          if ( v8 >= *(unsigned int *)(v28 + 104) )
          {
LABEL_234:
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              3,
              "cam_sfe_bus_read_rst_perf_cntrs",
              3438,
              "SFE%u Frame: %u Perf counters c%s",
              *(_DWORD *)is_expanded_memory,
              *(_DWORD *)(v10 + 2960),
              (const char *)v260);
            goto LABEL_245;
          }
        }
LABEL_197:
        __break(0x5512u);
LABEL_198:
        v136 = *(unsigned int *)(v8 + 8);
        if ( (_DWORD)v136 == 400 )
        {
          v137 = *(_QWORD *)(is_expanded_memory + 27616);
          v138 = scnprintf(*(_QWORD *)(v8 + 32), 1500, "Printing executable IRQ for hw_type: SFE reg_unit: %d\n", 400);
          if ( *(_DWORD *)(v137 + 3104) )
          {
            v139 = v138;
            v140 = 0;
            do
            {
              v141 = *(_QWORD *)(v137 + 3112) + 24LL * (int)v140++;
              v9 = 0;
              v139 += scnprintf(
                        *(_QWORD *)(v8 + 32) + v139,
                        1500 - v139,
                        "%#12x : %s - %s\n",
                        *(_DWORD *)v141,
                        *(const char **)(v141 + 8),
                        *(const char **)(v141 + 16));
            }
            while ( v140 < *(_DWORD *)(v137 + 3104) );
            goto LABEL_17;
          }
          goto LABEL_245;
        }
        v151 = "cam_sfe_bus_wr_dump_irq_desc";
        v147 = "Invalid reg_unit %d";
        v148 = 3;
        v149 = 8;
        v150 = 2;
        v152 = 3282;
        goto LABEL_224;
      default:
        v146 = __ratelimit(&cam_sfe_bus_wr_process_cmd__rs_115, "cam_sfe_bus_wr_process_cmd");
        v147 = "Invalid HW command type:%d";
        if ( v146 )
          v148 = 3;
        else
          v148 = 2;
        v149 = 0x40000000;
        v150 = 1;
        v151 = "cam_sfe_bus_wr_process_cmd";
        v152 = 3583;
        v136 = a2;
        goto LABEL_224;
    }
  }
  else
  {
    v18 = __ratelimit(&cam_sfe_bus_wr_process_cmd__rs, "cam_sfe_bus_wr_process_cmd");
    v19 = "Invalid input arguments";
    if ( v18 )
      v20 = 3;
    else
      v20 = 2;
    v21 = 0x40000000;
    v22 = 1;
    v23 = "cam_sfe_bus_wr_process_cmd";
    v24 = 3481;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    v20,
    v21,
    v22,
    v23,
    v24,
    v19);
  goto LABEL_16;
}
