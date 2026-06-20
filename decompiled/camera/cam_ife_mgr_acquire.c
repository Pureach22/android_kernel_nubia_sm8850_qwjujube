__int64 __fastcall cam_ife_mgr_acquire(__int64 a1, __int64 a2)
{
  _QWORD *v2; // x25
  __int64 v5; // x24
  int v6; // w19
  unsigned int v7; // w28
  _QWORD *v8; // x21
  _QWORD *v9; // x22
  _QWORD *v10; // x8
  __int64 v11; // x9
  _QWORD *v12; // x19
  _QWORD *v13; // x21
  _QWORD *v14; // x22
  _QWORD *v15; // x8
  __int64 v16; // x9
  _QWORD *v17; // x19
  _QWORD *v18; // x22
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x9
  int v22; // w8
  unsigned int unique_tbl; // w0
  __int64 v24; // x7
  __int64 v25; // x8
  __int64 v26; // x8
  unsigned __int64 v27; // x23
  __int64 v28; // x22
  unsigned int v29; // w8
  int v30; // w9
  unsigned int v31; // w19
  unsigned int v32; // w21
  unsigned __int64 v33; // x26
  int v34; // w27
  int v35; // w9
  __int64 v36; // x1
  size_t v37; // x1
  __int64 v38; // x0
  _DWORD *v39; // x0
  _DWORD *v40; // x28
  unsigned int v41; // w6
  __int64 v42; // x0
  __int64 v43; // x26
  _DWORD *v44; // x11
  unsigned int v45; // w10
  __int64 v46; // x8
  unsigned int v47; // w9
  __int64 v48; // x6
  __int64 v49; // x7
  unsigned int v50; // w24
  unsigned int v51; // w23
  unsigned __int64 v52; // x19
  _DWORD *v53; // x26
  int v54; // w6
  _QWORD *v55; // x28
  unsigned int v56; // w25
  _BOOL4 v57; // w19
  __int64 v58; // x26
  _QWORD *v59; // x21
  _QWORD *v60; // x24
  _BOOL4 v61; // w8
  unsigned int v62; // w8
  unsigned int v63; // w8
  signed int v64; // w9
  unsigned int *v65; // x25
  unsigned int v66; // w19
  unsigned int v67; // w0
  _QWORD *v68; // x0
  _QWORD *v69; // x26
  __int64 v70; // x19
  _QWORD *v71; // x21
  unsigned int v72; // w0
  unsigned int updated; // w0
  unsigned int v74; // w0
  unsigned int v75; // w28
  char v76; // w24
  unsigned int v77; // w23
  unsigned __int64 v78; // x10
  __int64 v79; // x25
  int v80; // w15
  int v81; // w6
  unsigned int v82; // w26
  unsigned int v83; // w8
  int v84; // w8
  const char *v85; // x3
  const char *v86; // x5
  __int64 v87; // x4
  _QWORD *v88; // x1
  const char *v89; // x3
  __int64 v90; // x1
  __int64 v91; // x4
  int v92; // w8
  int v93; // w9
  __int64 v94; // x8
  __int64 v95; // x10
  __int64 v96; // x10
  __int64 v97; // x10
  __int64 v98; // x10
  __int64 v99; // x10
  __int64 v100; // x10
  __int64 v101; // x10
  unsigned int v102; // w0
  _QWORD *v103; // x1
  unsigned int v104; // w19
  __int64 v105; // x23
  _QWORD *v106; // x0
  _QWORD *v107; // x23
  _QWORD *v108; // t1
  __int64 v109; // x8
  int v111; // w8
  int v112; // w9
  __int64 v113; // x6
  const char *v114; // x5
  __int64 v115; // x4
  __int64 v116; // x0
  __int64 v117; // x0
  __int64 v118; // x0
  const char *v119; // x5
  __int64 v120; // x4
  unsigned __int16 *v121; // x16
  int v122; // w14
  unsigned int v123; // w26
  int v124; // w19
  int v125; // w10
  unsigned int v126; // w28
  unsigned int v127; // w12
  unsigned int v128; // w8
  unsigned int v129; // w7
  unsigned int v130; // w8
  unsigned int v131; // w8
  unsigned int v132; // w8
  __int64 v133; // x0
  __int64 v134; // x8
  const char *v135; // x3
  __int64 v136; // x4
  __int64 v137; // x8
  __int64 v138; // x0
  signed int v139; // w8
  unsigned int *v140; // x10
  __int64 v141; // x11
  unsigned int v142; // w9
  int v143; // w6
  int v144; // w14
  int v145; // w8
  int v146; // w9
  int v147; // w10
  int v148; // w11
  int v149; // w12
  int v150; // w13
  unsigned int v151; // w6
  int v152; // w8
  __int64 v153; // x7
  unsigned int v154; // w8
  unsigned int v155; // w9
  unsigned int v156; // w6
  __int64 v157; // x7
  unsigned int v158; // w8
  int v159; // w10
  unsigned int v160; // w9
  unsigned int v161; // w8
  __int64 v162; // x7
  int v163; // w9
  unsigned int v164; // w8
  int v165; // w9
  unsigned int v166; // w8
  __int64 v167; // x7
  int v168; // w9
  unsigned int v169; // w8
  int v170; // w28
  int v171; // w9
  _BOOL4 v172; // w8
  unsigned int v173; // w9
  unsigned int v174; // w6
  __int64 v175; // x7
  unsigned int v176; // w8
  unsigned int v177; // w9
  int v178; // w24
  __int64 v179; // x7
  unsigned int v180; // w8
  int v181; // w10
  unsigned int v182; // w9
  unsigned int v183; // w8
  __int64 v184; // x7
  unsigned int v185; // w9
  unsigned int v186; // w8
  int v187; // w9
  unsigned int v188; // w8
  __int64 v189; // x7
  int v190; // w12
  unsigned int v191; // w9
  unsigned int v192; // w8
  int v193; // w9
  const char *v194; // x3
  __int64 v195; // x4
  const char *v196; // x5
  const char *v197; // x3
  __int64 v198; // x4
  __int64 v199; // x0
  __int64 v200; // x0
  __int64 v201; // x0
  unsigned int v202; // w8
  unsigned int *v203; // x10
  __int64 v204; // x11
  __int64 v205; // x0
  int v206; // w9
  int v207; // w7
  __int64 v208; // x9
  _DWORD *v209; // x8
  unsigned int v210; // w23
  int v211; // w9
  __int64 v212; // x0
  _QWORD *v213; // x24
  size_t v214; // x2
  void *v215; // x8
  _DWORD *v216; // x10
  __int64 v217; // x0
  _QWORD *v218; // x19
  size_t v219; // x2
  void *v220; // x8
  __int64 v221; // x27
  _QWORD *v222; // x0
  int v223; // w8
  unsigned int v224; // w8
  unsigned int v225; // w9
  __int64 v226; // x9
  unsigned int v227; // w0
  _QWORD *v228; // x0
  _QWORD *v229; // x28
  unsigned int v230; // w0
  unsigned int cdm_cmd; // w0
  int v232; // w8
  const char *v233; // x3
  __int64 v234; // x4
  int v235; // w7
  __int64 v236; // x26
  unsigned int v237; // w19
  __int64 v238; // x23
  _QWORD *v239; // x0
  _QWORD *v240; // x23
  _QWORD *v241; // t1
  _QWORD *v242; // x0
  _QWORD *v243; // x19
  _QWORD *v244; // x0
  int v245; // w8
  _QWORD *v246; // x0
  int v247; // w8
  _QWORD *v248; // x0
  __int64 v249; // x8
  int v250; // w9
  __int64 v251; // x8
  __int64 v252; // x10
  __int64 v253; // x10
  __int64 v254; // x10
  __int64 v255; // x10
  __int64 v256; // x10
  __int64 v257; // x10
  __int64 v258; // x10
  unsigned int v259; // w0
  int v260; // w9
  int v261; // w10
  bool v262; // zf
  __int64 v263; // x0
  __int64 v264; // x0
  int v265; // w8
  int v266; // w11
  int v267; // w8
  _QWORD *v268; // x0
  int v269; // [xsp+0h] [xbp-270h]
  unsigned int v270; // [xsp+8h] [xbp-268h]
  int v271; // [xsp+2Ch] [xbp-244h]
  int v272; // [xsp+2Ch] [xbp-244h]
  _BOOL4 v273; // [xsp+38h] [xbp-238h]
  int v274; // [xsp+38h] [xbp-238h]
  _BOOL4 v275; // [xsp+38h] [xbp-238h]
  _BOOL4 v276; // [xsp+38h] [xbp-238h]
  _DWORD *v277; // [xsp+40h] [xbp-230h]
  int v278; // [xsp+48h] [xbp-228h]
  unsigned int v279; // [xsp+4Ch] [xbp-224h]
  unsigned int v280; // [xsp+50h] [xbp-220h]
  unsigned int v281; // [xsp+5Ch] [xbp-214h]
  int v282; // [xsp+5Ch] [xbp-214h]
  int v283; // [xsp+5Ch] [xbp-214h]
  int v284; // [xsp+5Ch] [xbp-214h]
  _QWORD *v285; // [xsp+60h] [xbp-210h]
  unsigned __int64 v286; // [xsp+60h] [xbp-210h]
  __int64 v287; // [xsp+68h] [xbp-208h]
  __int64 v288; // [xsp+68h] [xbp-208h]
  __int64 v289; // [xsp+68h] [xbp-208h]
  _DWORD *v290; // [xsp+70h] [xbp-200h]
  _QWORD *v291; // [xsp+80h] [xbp-1F0h] BYREF
  unsigned __int64 v292; // [xsp+88h] [xbp-1E8h] BYREF
  _QWORD *v293; // [xsp+90h] [xbp-1E0h] BYREF
  __int64 v294; // [xsp+98h] [xbp-1D8h]
  __int64 v295; // [xsp+A0h] [xbp-1D0h]
  __int64 v296; // [xsp+A8h] [xbp-1C8h]
  __int64 v297; // [xsp+B0h] [xbp-1C0h]
  __int64 v298; // [xsp+B8h] [xbp-1B8h]
  __int64 v299; // [xsp+C0h] [xbp-1B0h]
  __int64 v300; // [xsp+C8h] [xbp-1A8h]
  __int64 v301; // [xsp+D0h] [xbp-1A0h]
  __int64 v302; // [xsp+D8h] [xbp-198h]
  __int64 v303; // [xsp+E0h] [xbp-190h]
  __int64 v304; // [xsp+E8h] [xbp-188h]
  __int64 v305; // [xsp+F0h] [xbp-180h]
  __int64 v306; // [xsp+F8h] [xbp-178h]
  __int64 v307; // [xsp+100h] [xbp-170h]
  __int64 v308; // [xsp+108h] [xbp-168h]
  __int64 v309; // [xsp+110h] [xbp-160h]
  __int64 v310; // [xsp+118h] [xbp-158h]
  __int64 v311; // [xsp+120h] [xbp-150h]
  __int64 v312; // [xsp+128h] [xbp-148h]
  __int64 v313; // [xsp+130h] [xbp-140h]
  __int64 v314; // [xsp+138h] [xbp-138h]
  __int64 v315; // [xsp+140h] [xbp-130h]
  __int64 v316; // [xsp+148h] [xbp-128h]
  __int64 v317; // [xsp+150h] [xbp-120h]
  _QWORD s[35]; // [xsp+158h] [xbp-118h] BYREF

  v2 = &unk_393000;
  v5 = (__int64)&unk_393000;
  s[33] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_acquire",
      7145,
      "Enter...");
    if ( !a2 )
      goto LABEL_6;
  }
  else if ( !a2 )
  {
LABEL_6:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_acquire",
      7148,
      "Nothing to acquire. Seems like error");
    v7 = -22;
    goto LABEL_213;
  }
  v6 = *(_DWORD *)(a2 + 32);
  if ( v6 == -16843010 )
  {
    memset(s, 0, 0x108u);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_acquire_hw",
        6446,
        "Enter...");
      if ( !*(_DWORD *)(a2 + 32) )
      {
        v233 = "cam_ife_mgr_acquire_hw";
        v234 = 6449;
        goto LABEL_488;
      }
    }
    v8 = (_QWORD *)(a1 + 368);
    mutex_lock(&unk_394A30);
    v9 = *(_QWORD **)(a1 + 368);
    if ( v9 == (_QWORD *)(a1 + 368) )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_hw_mgr_get_ctx",
        2614,
        "No more free ife hw mgr ctx");
      v12 = nullptr;
      v7 = -1;
    }
    else
    {
      v10 = (_QWORD *)v9[1];
      if ( (_QWORD *)*v10 == v9 && (v11 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
      {
        *(_QWORD *)(v11 + 8) = v10;
        *v10 = v11;
      }
      else
      {
        _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 368));
      }
      v7 = 0;
      *v9 = v9;
      v12 = v9;
      v9[1] = v9;
    }
    v291 = v12;
    mutex_unlock(&unk_394A30);
    if ( v9 == v8 || !v12 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_acquire_hw",
        6456,
        "Get ife hw context failed");
      LOBYTE(v25) = debug_mdl;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_210;
      goto LABEL_164;
    }
    cam_cpas_get_cpas_hw_version((_DWORD *)v12 + 2224);
    v18 = v291;
    *((_DWORD *)v291 + 2180) = 0;
    v18[1164] = 0;
    v18[1064] = 0;
    v18[4] = *(_QWORD *)a2;
    v19 = *(_QWORD *)(a2 + 184);
    *(_QWORD *)((char *)v18 + 60) = 0x800000008LL;
    *((_BYTE *)v18 + 9382) = 0;
    v18[1168] = 0;
    v18[1167] = 0;
    v18[5] = v19;
    v20 = *(_QWORD *)(a2 + 16);
    v18[9] = a1;
    v18[3] = v20;
    v18[1091] = cam_cdm_publish_ops();
    v21 = *(_QWORD *)(a2 + 24);
    *((_DWORD *)v18 + 2362) = 0;
    v18[1182] = 0;
    v18[6] = v21;
    *((_DWORD *)v18 + 2366) = 0;
    v18[34] = 0;
    v18[35] = 0;
    *((_DWORD *)v18 + 2383) = dword_3A85A4;
    v22 = *(_DWORD *)(a2 + 8);
    v18[1171] = 0;
    *((_BYTE *)v18 + 9401) = 0;
    *((_DWORD *)v18 + 14) = v22;
    *((_WORD *)v18 + 4992) = 0;
    memset(v18 + 1192, 0, 0x1C0u);
    unique_tbl = cam_packet_util_get_unique_tbl(v18 + 1249, v18 + 1250);
    if ( unique_tbl )
    {
      v7 = unique_tbl;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_mgr_acquire_hw",
        6492,
        "Failed at allocating mem for ISP unique src/dst buf handle tbl");
      goto LABEL_158;
    }
    if ( !v18 )
      goto LABEL_156;
    v44 = *(_DWORD **)(a2 + 40);
    if ( !v44 )
      goto LABEL_156;
    v45 = *(unsigned __int16 *)v44;
    v46 = *(unsigned int *)(a2 + 36);
    v290 = *(_DWORD **)(a2 + 40);
    v47 = v45 >> 12;
    *((_DWORD *)v18 + 2367) = v45 >> 12;
    if ( v45 >> 12 == 3 )
    {
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_235;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_check_and_update_fe",
        5158,
        "FE updates not applicable");
      goto LABEL_586;
    }
    if ( v47 != 2 )
    {
      if ( v47 != 1 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, unsigned int))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_check_and_update_fe",
          5162,
          "Invalid ver of user common info: ctx_idx %u minor %u major %u",
          *((unsigned int *)v18 + 14),
          v45 & 0xFFF,
          v47);
        goto LABEL_156;
      }
      v49 = (unsigned int)v44[4];
      v48 = (unsigned int)v44[5];
      if ( (unsigned int)v48 < (unsigned int)v49 )
      {
        v288 = a1;
        if ( v44[2] )
        {
          v50 = 0;
          v51 = 0;
          v52 = (unsigned __int64)v44 + v46;
          v53 = (_DWORD *)((char *)v44 + v48 + 24);
          while ( 1 )
          {
            if ( (unsigned __int64)(v53 + 32) > v52 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_ife_mgr_check_and_update_fe_v0",
                4996,
                "Invalid size, ctx_idx: %u",
                *((_DWORD *)v18 + 14));
              goto LABEL_230;
            }
            v54 = v53[23];
            if ( v54 - 1 >= (unsigned int)max_ife_out_res )
              break;
            v55 = v2;
            v56 = 32 * v54 + 96;
            v50 += v56;
            if ( v50 > v44[4] )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                8,
                1,
                "cam_ife_mgr_check_and_update_fe_v0",
                5014,
                "buffer size is not enough, ctx_idx: %u",
                *((_DWORD *)v18 + 14));
              a1 = v288;
              v5 = (__int64)&unk_393000;
              v2 = v55;
              goto LABEL_156;
            }
            if ( (v55[458] & 8) != 0 && !debug_priority )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v55[458] & 8LL,
                4,
                "cam_ife_mgr_check_and_update_fe_v0",
                5018,
                "in_port%d res_type %d ctx_idx: %u",
                v51,
                *v53,
                *((_DWORD *)v18 + 14));
              v44 = v290;
            }
            if ( *v53 == 16391 )
            {
              v2 = v55;
              *((_BYTE *)v18 + 9378) = 1;
              goto LABEL_233;
            }
            ++v51;
            v53 = (_DWORD *)((char *)v53 + v56);
            v2 = v55;
            if ( v51 >= v44[2] )
              goto LABEL_233;
          }
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_check_and_update_fe_v0",
            5003,
            "Invalid num output res %u ctx_idx: %u",
            v54,
            *((_DWORD *)v18 + 14));
LABEL_230:
          a1 = v288;
          v5 = (__int64)&unk_393000;
          goto LABEL_156;
        }
LABEL_233:
        a1 = v288;
        v5 = (__int64)&unk_393000;
        if ( (v2[458] & 8) == 0 || debug_priority )
        {
LABEL_235:
          if ( mem_trace_en == 1 )
            v116 = cam_mem_trace_alloc(232LL * (unsigned int)v44[2], 0xCC0u, 0, "cam_ife_mgr_acquire_hw", 0x196Bu);
          else
            v116 = _kvmalloc_node_noprof(232LL * (unsigned int)v44[2], 0, 3520, 0xFFFFFFFFLL);
          v28 = v116;
          if ( !v116 )
          {
            v18 = v291;
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              8,
              1,
              "cam_ife_mgr_acquire_hw",
              6510,
              "No memory available, ctx_idx: %u",
              *((_DWORD *)v291 + 14));
            v7 = -12;
            goto LABEL_157;
          }
          if ( mem_trace_en == 1 )
            v117 = cam_mem_trace_alloc(5256, 0xCC0u, 0, "cam_ife_mgr_acquire_hw", 0x1974u);
          else
            v117 = _kvmalloc_node_noprof(5256, 0, 3520, 0xFFFFFFFFLL);
          v291[1184] = v117;
          if ( v117 )
          {
            if ( mem_trace_en == 1 )
              v118 = cam_mem_trace_alloc(3504, 0xCC0u, 0, "cam_ife_mgr_acquire_hw", 0x197Cu);
            else
              v118 = _kvmalloc_node_noprof(3504, 0, 3520, 0xFFFFFFFFLL);
            v291[1185] = v118;
            if ( v118 )
            {
              v121 = (unsigned __int16 *)v290;
              v287 = a1;
              if ( v290[2] )
              {
                v27 = 0;
                v122 = 0;
                v123 = 0;
                v124 = 0;
                v125 = 0;
                v126 = 0;
                v127 = 0;
                v277 = v290 + 6;
                _ReadStatusReg(SP_EL0);
                while ( 1 )
                {
                  v128 = *v121;
                  v279 = v123;
                  v280 = v124;
                  v58 = v28 + 232LL * (int)v27;
                  v283 = v125;
                  LODWORD(v285) = v122;
                  v129 = v128 >> 12;
                  if ( v128 >> 12 == 3 )
                    break;
                  if ( v129 == 2 )
                  {
                    v316 = 0;
                    v317 = 0;
                    v314 = 0;
                    v315 = 0;
                    v312 = 0;
                    v313 = 0;
                    v310 = 0;
                    v311 = 0;
                    v308 = 0;
                    v309 = 0;
                    v306 = 0;
                    v307 = 0;
                    v304 = 0;
                    v305 = 0;
                    v302 = 0;
                    v303 = 0;
                    v300 = 0;
                    v301 = 0;
                    v298 = 0;
                    v299 = 0;
                    v296 = 0;
                    v297 = 0;
                    v294 = 0;
                    v295 = 0;
                    v134 = *((unsigned int *)v121 + 5);
                    v292 = 0;
                    v293 = nullptr;
                    v65 = (_DWORD *)((char *)v277 + v134 + v127);
                    v278 = v127 + 40 * v65[30] + 152;
                    if ( !v58 || v127 + 40 * v65[30] + 152 > *((_DWORD *)v121 + 4) )
                    {
                      v66 = v126;
                      v135 = "cam_ife_mgr_acquire_get_unified_structure_v2";
                      v136 = 6256;
                      goto LABEL_265;
                    }
                    *(_DWORD *)v58 = v121[7];
                    *(_DWORD *)(v58 + 4) = v121[6];
                    *(_DWORD *)(v58 + 8) = *v65;
                    *(_DWORD *)(v58 + 12) = v65[1];
                    *(_DWORD *)(v58 + 16) = v65[2];
                    *(_DWORD *)(v58 + 20) = v65[3];
                    v151 = v65[12];
                    *(_DWORD *)(v58 + 56) = v151;
                    v152 = dword_3A85C0;
                    if ( v151 - 5 >= 0xFFFFFFFC && v151 <= dword_3A85C0 )
                    {
                      v153 = v65[4];
                      v154 = v65[8];
                      *(_DWORD *)(v58 + 24) = v153;
                      v155 = v65[8];
                      v273 = v153 != 0xFFFF;
                      v5 = v154 != 0xFFFF;
                      *(_DWORD *)(v58 + 40) = v155;
                      v270 = v155;
                      cam_print_to_buffer((__int64)&v293, 0xC8u, &v292, 3u, 8u, "VC%d: 0x%x, DT%d: 0x%x ", 0, v153, 0);
                      v156 = *(_DWORD *)(v58 + 56);
                      if ( v156 < 2 )
                        goto LABEL_352;
                      v157 = v65[5];
                      v158 = v65[9];
                      v159 = v273;
                      *(_DWORD *)(v58 + 28) = v157;
                      v160 = v65[9];
                      if ( (_DWORD)v157 != 0xFFFF )
                        v159 = v273 + 1;
                      v273 = v159;
                      v5 = v158 == 0xFFFF ? (unsigned int)v5 : (unsigned int)(v5 + 1);
                      *(_DWORD *)(v58 + 44) = v160;
                      v270 = v160;
                      cam_print_to_buffer((__int64)&v293, 0xC8u, &v292, 3u, 8u, "VC%d: 0x%x, DT%d: 0x%x ", 1, v157, 1);
                      v156 = *(_DWORD *)(v58 + 56);
                      if ( v156 < 3 )
                      {
LABEL_352:
                        v172 = v273;
                        v66 = v126;
                        v173 = 0;
                        v7 = -22;
                        if ( !v273 )
                          goto LABEL_357;
                      }
                      else
                      {
                        v161 = v65[10];
                        v162 = v65[6];
                        *(_DWORD *)(v58 + 32) = v162;
                        if ( v161 == 0xFFFF )
                          v163 = -22;
                        else
                          v163 = 0;
                        if ( v161 == 0xFFFF )
                          v5 = (unsigned int)v5;
                        else
                          v5 = (unsigned int)(v5 + 1);
                        if ( (_DWORD)v162 != 0xFFFF )
                          v163 = -22;
                        v164 = v65[10];
                        v271 = v163;
                        v165 = v273;
                        *(_DWORD *)(v58 + 48) = v164;
                        if ( (_DWORD)v162 != 0xFFFF )
                          v165 = v273 + 1;
                        v270 = v164;
                        v274 = v165;
                        cam_print_to_buffer((__int64)&v293, 0xC8u, &v292, 3u, 8u, "VC%d: 0x%x, DT%d: 0x%x ", 2, v162, 2);
                        v156 = *(_DWORD *)(v58 + 56);
                        v66 = v126;
                        if ( v156 <= 3 )
                        {
                          v172 = v274;
                          v173 = v271;
                          v7 = -22;
                          if ( !v274 )
                            goto LABEL_357;
                        }
                        else
                        {
                          v166 = v65[11];
                          v167 = v65[7];
                          v168 = v271;
                          *(_DWORD *)(v58 + 36) = v167;
                          if ( v166 == 0xFFFF )
                          {
                            v168 = -22;
                            v5 = (unsigned int)v5;
                          }
                          else
                          {
                            v5 = (unsigned int)(v5 + 1);
                          }
                          v169 = v65[11];
                          if ( (_DWORD)v167 == 0xFFFF )
                            v170 = v168;
                          else
                            v170 = -22;
                          v171 = v274;
                          if ( (_DWORD)v167 != 0xFFFF )
                            v171 = v274 + 1;
                          *(_DWORD *)(v58 + 52) = v169;
                          v270 = v169;
                          v275 = v171;
                          cam_print_to_buffer(
                            (__int64)&v293,
                            0xC8u,
                            &v292,
                            3u,
                            8u,
                            "VC%d: 0x%x, DT%d: 0x%x ",
                            3,
                            v167,
                            3);
                          v156 = *(_DWORD *)(v58 + 56);
                          if ( v156 > 4 )
                            goto LABEL_592;
                          v172 = v275;
                          v173 = v170;
                          v7 = -22;
                          if ( !v275 )
                          {
LABEL_357:
                            v197 = "cam_ife_mgr_acquire_get_unified_structure_v2";
                            v198 = 6305;
                            goto LABEL_365;
                          }
                        }
                      }
                      if ( !(_DWORD)v5 || v172 && (_DWORD)v5 != 1 )
                        goto LABEL_357;
                      v7 = v173;
                      if ( v173 )
                        goto LABEL_357;
                      if ( (debug_mdl & 8) != 0 && !debug_priority )
                      {
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          debug_mdl & 8,
                          4,
                          "cam_ife_mgr_acquire_get_unified_structure_v2",
                          6310,
                          "VC/DT args from UMD:, num: %d, pairs: %s",
                          v156,
                          (const char *)&v293);
                        v156 = *(_DWORD *)(v58 + 56);
                        if ( v156 )
                        {
LABEL_371:
                          *(_DWORD *)(v58 + 60) = *((unsigned __int8 *)v65 + 52);
                          if ( v156 != 1 )
                          {
                            *(_DWORD *)(v58 + 64) = *((unsigned __int8 *)v65 + 53);
                            if ( v156 != 2 )
                            {
                              *(_DWORD *)(v58 + 68) = *((unsigned __int8 *)v65 + 54);
                              if ( v156 != 3 )
                              {
                                v63 = *((unsigned __int8 *)v65 + 55);
                                *(_DWORD *)(v58 + 72) = v63;
                                if ( v156 != 4 )
                                  goto LABEL_592;
                              }
                            }
                          }
                        }
                      }
                      else if ( v156 )
                      {
                        goto LABEL_371;
                      }
                      *(_DWORD *)(v58 + 76) = v65[14];
                      *(_DWORD *)(v58 + 80) = v65[15];
                      *(_DWORD *)(v58 + 84) = v65[16];
                      *(_DWORD *)(v58 + 88) = v65[17];
                      *(_DWORD *)(v58 + 92) = v65[18];
                      *(_DWORD *)(v58 + 96) = v65[19];
                      *(_DWORD *)(v58 + 100) = v65[20];
                      *(_DWORD *)(v58 + 104) = v65[21];
                      *(_DWORD *)(v58 + 108) = v65[22];
                      *(_DWORD *)(v58 + 112) = v65[23];
                      *(_DWORD *)(v58 + 116) = v65[24];
                      *(_DWORD *)(v58 + 120) = v65[25];
                      *(_DWORD *)(v58 + 124) = v65[26];
                      *(_DWORD *)(v58 + 128) = v65[27];
                      *(_DWORD *)(v58 + 132) = v65[28];
                      *(_DWORD *)(v58 + 140) = v65[29];
                      *(_DWORD *)(v58 + 148) = *((unsigned __int16 *)v65 + 64);
                      *(_DWORD *)(v58 + 152) = *((unsigned __int16 *)v65 + 65);
                      *(_DWORD *)(v58 + 156) = v65[33];
                      *(_DWORD *)(v58 + 144) = v65[30];
                      *(_DWORD *)(v58 + 196) = *((unsigned __int16 *)v65 + 68);
                      *(_DWORD *)(v58 + 200) = *((unsigned __int16 *)v65 + 69);
                      *(_DWORD *)(v58 + 136) = *((unsigned __int8 *)v65 + 52);
                      *(_BYTE *)(v58 + 216) = v65[35] & 1;
                      *(_BYTE *)(v58 + 217) = (v65[35] & 4) != 0;
                      *(_BYTE *)(v58 + 218) = (v65[35] & 2) != 0;
                      *(_BYTE *)(v58 + 219) = (v65[35] & 8) != 0;
                      *(_BYTE *)(v58 + 220) = (v65[35] & 0x10) != 0;
                      *(_BYTE *)(v58 + 221) = (v65[35] & 0x80) != 0;
                      *(_BYTE *)(v58 + 222) = *((_BYTE *)v65 + 141) & 1;
                      if ( mem_trace_en == 1 )
                      {
                        v199 = cam_mem_trace_alloc(
                                 44LL * v65[30],
                                 0xCC0u,
                                 0,
                                 "cam_ife_mgr_acquire_get_unified_structure_v2",
                                 0x18CEu);
                        *(_QWORD *)(v58 + 224) = v199;
                        if ( !v199 )
                          goto LABEL_405;
                      }
                      else
                      {
                        v201 = _kvmalloc_node_noprof(44LL * v65[30], 0, 3520, 0xFFFFFFFFLL);
                        *(_QWORD *)(v58 + 224) = v201;
                        if ( !v201 )
                          goto LABEL_405;
                      }
                      if ( *(_DWORD *)(v58 + 144) )
                      {
                        v202 = 0;
                        v5 = (__int64)&unk_393000;
                        do
                        {
                          v203 = &v65[10 * v202 + 38];
                          v7 = 0;
                          *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * (int)v202) = *v203;
                          *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * (int)v202 + 4) = v203[1];
                          *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * (int)v202 + 8) = v203[2];
                          *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * (int)v202 + 12) = v203[3];
                          *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * (int)v202 + 16) = v203[4];
                          *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * (int)v202 + 20) = v203[5];
                          v204 = *(_QWORD *)(v58 + 224) + 44LL * (int)v202++;
                          *(_DWORD *)(v204 + 24) = v203[6];
                        }
                        while ( v202 < *(_DWORD *)(v58 + 144) );
                        goto LABEL_267;
                      }
LABEL_399:
                      v7 = 0;
                      v5 = (__int64)&unk_393000;
                      goto LABEL_267;
                    }
                    v66 = v126;
                    v194 = "cam_ife_mgr_acquire_get_unified_structure_v2";
                    v195 = 6276;
LABEL_350:
                    v196 = "Invalid i/p arg invalid vc-dt: %d, arr size %u, max supported by HW: %u";
                    v269 = v152;
LABEL_351:
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      8,
                      1,
                      v194,
                      v195,
                      v196);
LABEL_266:
                    v7 = -22;
                    goto LABEL_267;
                  }
                  if ( v129 != 1 )
                  {
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_ife_mgr_acquire_get_unified_structure",
                      6397,
                      "Invalid ver of i/p port info from user. minor %u, major %u",
                      v128 & 0xFFF);
                    v7 = -22;
                    goto LABEL_492;
                  }
                  if ( !v58
                    || (v65 = (_DWORD *)((char *)v277 + *((unsigned int *)v121 + 5) + v127),
                        v127 + 32 * v65[23] + 96 > *((_DWORD *)v121 + 4)) )
                  {
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_ife_mgr_acquire_get_unified_structure_v0",
                      6008,
                      "Input is not proper");
                    v7 = -22;
                    goto LABEL_492;
                  }
                  v278 = v127 + 32 * v65[23] + 96;
                  *(_DWORD *)v58 = v121[7];
                  *(_DWORD *)(v58 + 4) = v121[6];
                  *(_DWORD *)(v58 + 8) = *v65;
                  *(_DWORD *)(v58 + 12) = v65[1];
                  *(_DWORD *)(v58 + 16) = v65[2];
                  *(_DWORD *)(v58 + 20) = v65[3];
                  *(_DWORD *)(v58 + 24) = v65[4];
                  v130 = v65[5];
                  *(_DWORD *)(v58 + 56) = 1;
                  *(_DWORD *)(v58 + 40) = v130;
                  *(_DWORD *)(v58 + 60) = v65[6];
                  *(_DWORD *)(v58 + 76) = v65[7];
                  *(_DWORD *)(v58 + 80) = v65[8];
                  *(_DWORD *)(v58 + 84) = v65[9];
                  *(_DWORD *)(v58 + 88) = v65[10];
                  *(_DWORD *)(v58 + 92) = v65[11];
                  *(_DWORD *)(v58 + 96) = v65[12];
                  *(_DWORD *)(v58 + 100) = v65[13];
                  *(_DWORD *)(v58 + 104) = v65[14];
                  *(_DWORD *)(v58 + 108) = v65[15];
                  *(_DWORD *)(v58 + 112) = v65[16];
                  *(_DWORD *)(v58 + 116) = v65[17];
                  *(_DWORD *)(v58 + 120) = v65[18];
                  *(_DWORD *)(v58 + 124) = v65[19];
                  *(_DWORD *)(v58 + 128) = v65[20];
                  v131 = v65[21];
                  *(_DWORD *)(v58 + 140) = 0;
                  *(_DWORD *)(v58 + 148) = 0;
                  *(_DWORD *)(v58 + 132) = v131;
                  *(_DWORD *)(v58 + 156) = 0;
                  v132 = v65[23];
                  *(_DWORD *)(v58 + 144) = v132;
                  if ( mem_trace_en == 1 )
                  {
                    v133 = cam_mem_trace_alloc(
                             44LL * v132,
                             0xCC0u,
                             0,
                             "cam_ife_mgr_acquire_get_unified_structure_v0",
                             0x179Fu);
                    *(_QWORD *)(v58 + 224) = v133;
                    if ( !v133 )
                      goto LABEL_491;
                  }
                  else
                  {
                    v138 = _kvmalloc_node_noprof(44LL * v65[23], 0, 3520, 0xFFFFFFFFLL);
                    *(_QWORD *)(v58 + 224) = v138;
                    if ( !v138 )
                    {
LABEL_491:
                      v7 = -12;
LABEL_492:
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        8,
                        1,
                        "cam_ife_mgr_acquire_hw",
                        6538,
                        "Failed in parsing: %d, ctx_idx: %u",
                        v7,
                        *((_DWORD *)v291 + 14));
LABEL_493:
                      a1 = v287;
                      v2 = &unk_393000;
                      goto LABEL_502;
                    }
                  }
                  v66 = v126;
                  if ( v65[23] )
                  {
                    v139 = 0;
                    do
                    {
                      v140 = &v65[8 * v139 + 24];
                      *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v139) = *v140;
                      *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v139 + 4) = v140[1];
                      *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v139 + 8) = v140[2];
                      *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v139 + 12) = v140[3];
                      *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v139 + 16) = v140[4];
                      *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v139 + 20) = v140[5];
                      *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v139 + 24) = v140[6];
                      v141 = *(_QWORD *)(v58 + 224) + 44LL * v139++;
                      *(_DWORD *)(v141 + 28) = v140[7];
                    }
                    while ( v139 < v65[23] );
                  }
LABEL_273:
                  if ( *((_BYTE *)v291 + 9378) == 1 )
                  {
                    v142 = *(_DWORD *)(v58 + 56);
                    if ( v142 >= 2 )
                    {
                      v143 = *(_DWORD *)(v58 + 60);
                      v63 = *(_DWORD *)(v58 + 64);
                      if ( v63 != v143 )
                      {
                        v235 = 1;
                        goto LABEL_500;
                      }
                      if ( v142 != 2 )
                      {
                        v63 = *(_DWORD *)(v58 + 68);
                        if ( v63 != v143 )
                        {
                          v235 = 2;
                          goto LABEL_500;
                        }
                        if ( v142 != 3 )
                        {
                          v63 = *(_DWORD *)(v58 + 72);
                          if ( v63 != v143 )
                          {
                            v235 = 3;
LABEL_500:
                            a1 = v287;
                            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                              3,
                              8,
                              1,
                              "cam_ife_mgr_acquire_hw",
                              6550,
                              "Different input formats for FE use-cases not supported - formats vc0: %u vc%d: %u ctx_idx: %u",
                              v143,
                              v235,
                              v63,
                              *((_DWORD *)v291 + 14));
                            v7 = -22;
LABEL_501:
                            v2 = &unk_393000;
LABEL_502:
                            v209 = v290;
                            if ( v28 )
                            {
LABEL_503:
                              v236 = a1;
                              if ( v209[2] )
                              {
                                v237 = 0;
                                do
                                {
                                  v238 = v28 + 232LL * (int)v237;
                                  v241 = *(_QWORD **)(v238 + 224);
                                  v240 = (_QWORD *)(v238 + 224);
                                  v239 = v241;
                                  if ( mem_trace_en == 1 )
                                    cam_mem_trace_free(v239, 0);
                                  else
                                    kvfree(v239);
                                  *v240 = 0;
                                  ++v237;
                                }
                                while ( v237 < v290[2] );
                              }
                              if ( mem_trace_en == 1 )
                                cam_mem_trace_free((_QWORD *)v28, 0);
                              else
                                kvfree(v28);
                              a1 = v236;
                            }
                            v18 = v291;
                            v242 = (_QWORD *)v291[1184];
                            v243 = v291 + 1184;
                            if ( mem_trace_en == 1 )
                              cam_mem_trace_free(v242, 0);
                            else
                              kvfree(v242);
                            v244 = (_QWORD *)v291[1185];
                            if ( mem_trace_en == 1 )
                              cam_mem_trace_free(v244, 0);
                            else
                              kvfree(v244);
                            v245 = (unsigned __int8)mem_trace_en;
                            v246 = (_QWORD *)v291[35];
                            *v243 = 0;
                            v243[1] = 0;
                            if ( v245 == 1 )
                              cam_mem_trace_free(v246, 0);
                            else
                              kvfree(v246);
                            v247 = (unsigned __int8)mem_trace_en;
                            v248 = (_QWORD *)v18[34];
                            v18[35] = 0;
                            if ( v247 == 1 )
                              cam_mem_trace_free(v248, 0);
                            else
                              kvfree(v248);
                            v18[34] = 0;
LABEL_157:
                            cam_packet_util_put_unique_tbl((_QWORD *)v18[1249], (_QWORD *)v18[1250]);
                            v18[1250] = 0;
                            v18[1249] = 0;
LABEL_158:
                            mutex_lock(&unk_394A30);
                            if ( v18 )
                            {
                              v88 = *(_QWORD **)(a1 + 376);
                              if ( v18 == v8 || v88 == v18 || (_QWORD *)*v88 != v8 )
                              {
                                _list_add_valid_or_report(v18);
                              }
                              else
                              {
                                *(_QWORD *)(a1 + 376) = v18;
                                *v18 = v8;
                                v18[1] = v88;
                                *v88 = v18;
                              }
                            }
                            mutex_unlock(&unk_394A30);
                            v25 = v2[458];
                            if ( (v25 & 8) == 0 )
                              goto LABEL_210;
LABEL_164:
                            if ( *(_DWORD *)(v5 + 3676) )
                              goto LABEL_210;
                            v89 = "cam_ife_mgr_acquire_hw";
                            v90 = v25 & 8;
                            v91 = 6843;
LABEL_496:
                            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, int, unsigned int))cam_print_log)(
                              3,
                              v90,
                              4,
                              v89,
                              v91,
                              "Exit...(rc=%d)",
                              v7,
                              v24,
                              v269,
                              v270);
                            v109 = v2[458];
                            if ( (v109 & 8) != 0 )
                              goto LABEL_211;
                            goto LABEL_213;
                          }
                          if ( v142 != 4 )
                            goto LABEL_592;
                        }
                      }
                    }
                  }
                  if ( *(_DWORD *)(v58 + 80) && *(_BYTE *)(v58 + 216) == 1 )
                  {
                    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                      3,
                      8,
                      1,
                      "cam_ife_mgr_acquire_hw",
                      6559,
                      "Dual IFE mode is not supported in secure camera usecases");
                    v7 = -22;
                    goto LABEL_493;
                  }
                  cam_ife_hw_mgr_preprocess_port(v291, v28 + 232LL * (int)v27);
                  v144 = *(_DWORD *)(v58 + 164);
                  v146 = *(_DWORD *)(v58 + 180);
                  v145 = *(_DWORD *)(v58 + 184);
                  v148 = *(_DWORD *)(v58 + 168);
                  v147 = *(_DWORD *)(v58 + 172);
                  v149 = *(_DWORD *)(v58 + 188);
                  v150 = *(_DWORD *)(v58 + 192);
                  if ( *(_DWORD *)v58 == 3 && v144 )
                    *((_BYTE *)v291 + 9402) = 1;
                  v121 = (unsigned __int16 *)v290;
                  v27 = (unsigned int)(v27 + 1);
                  v126 = v150 + v66;
                  v123 = v147 + v279;
                  v124 = v148 + v280;
                  v125 = v149 + v283;
                  v127 = v278;
                  v122 = v144 + (_DWORD)v285 + v145 + v146;
                  if ( (unsigned int)v27 >= v290[2] )
                    goto LABEL_409;
                }
                v316 = 0;
                v317 = 0;
                v314 = 0;
                v315 = 0;
                v312 = 0;
                v313 = 0;
                v310 = 0;
                v311 = 0;
                v308 = 0;
                v309 = 0;
                v306 = 0;
                v307 = 0;
                v304 = 0;
                v305 = 0;
                v302 = 0;
                v303 = 0;
                v300 = 0;
                v301 = 0;
                v298 = 0;
                v299 = 0;
                v296 = 0;
                v297 = 0;
                v294 = 0;
                v295 = 0;
                v137 = *((unsigned int *)v121 + 5);
                v292 = 0;
                v293 = nullptr;
                v65 = (_DWORD *)((char *)v277 + v137 + v127);
                v278 = v127 + (v65[27] << 6) + 112;
                if ( !v58 || v127 + (v65[27] << 6) + 112 > *((_DWORD *)v121 + 4) )
                {
                  v66 = v126;
                  v135 = "cam_ife_mgr_acquire_get_unified_structure_v3";
                  v136 = 6131;
LABEL_265:
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    8,
                    1,
                    v135,
                    v136,
                    "Input is not proper");
                  goto LABEL_266;
                }
                *(_DWORD *)v58 = *(unsigned __int16 *)((char *)v121 + 13);
                *(_DWORD *)(v58 + 4) = v121[6];
                *(_DWORD *)(v58 + 8) = v65[21];
                *(_DWORD *)(v58 + 12) = v65[22];
                *(_DWORD *)(v58 + 16) = v65[23];
                *(_DWORD *)(v58 + 20) = v65[24];
                v174 = v65[8];
                *(_DWORD *)(v58 + 56) = v174;
                *(_BYTE *)(v58 + 220) = v65[13] & 1;
                v152 = dword_3A85C0;
                if ( v174 - 5 < 0xFFFFFFFC || v174 > dword_3A85C0 )
                {
                  v66 = v126;
                  v194 = "cam_ife_mgr_acquire_get_unified_structure_v3";
                  v195 = 6150;
                  goto LABEL_350;
                }
                v175 = *v65;
                v176 = v65[4];
                *(_DWORD *)(v58 + 24) = v175;
                v177 = v65[4];
                v276 = v175 != 0xFFFF;
                v178 = v176 != 0xFFFF;
                *(_DWORD *)(v58 + 40) = v177;
                v270 = v177;
                cam_print_to_buffer((__int64)&v293, 0xC8u, &v292, 3u, 8u, "VC%d: 0x%x, DT%d: 0x%x ", 0, v175, 0);
                v156 = *(_DWORD *)(v58 + 56);
                if ( v156 < 2 )
                  goto LABEL_358;
                v179 = v65[1];
                v180 = v65[5];
                v181 = v276;
                *(_DWORD *)(v58 + 28) = v179;
                v182 = v65[5];
                if ( (_DWORD)v179 != 0xFFFF )
                  v181 = v276 + 1;
                v276 = v181;
                if ( v180 != 0xFFFF )
                  ++v178;
                *(_DWORD *)(v58 + 44) = v182;
                v270 = v182;
                cam_print_to_buffer((__int64)&v293, 0xC8u, &v292, 3u, 8u, "VC%d: 0x%x, DT%d: 0x%x ", 1, v179, 1);
                v156 = *(_DWORD *)(v58 + 56);
                if ( v156 < 3 )
                {
LABEL_358:
                  v272 = v178;
                  v66 = v126;
                  v5 = 0;
                }
                else
                {
                  v183 = v65[6];
                  v184 = v65[2];
                  *(_DWORD *)(v58 + 32) = v184;
                  if ( v183 == 0xFFFF )
                    v185 = -22;
                  else
                    v185 = 0;
                  if ( v183 != 0xFFFF )
                    ++v178;
                  v186 = v65[6];
                  v272 = v178;
                  if ( (_DWORD)v184 == 0xFFFF )
                    v5 = v185;
                  else
                    v5 = 4294967274LL;
                  v187 = v276;
                  *(_DWORD *)(v58 + 48) = v186;
                  if ( (_DWORD)v184 != 0xFFFF )
                    v187 = v276 + 1;
                  v270 = v186;
                  v276 = v187;
                  cam_print_to_buffer((__int64)&v293, 0xC8u, &v292, 3u, 8u, "VC%d: 0x%x, DT%d: 0x%x ", 2, v184, 2);
                  v156 = *(_DWORD *)(v58 + 56);
                  v66 = v126;
                  if ( v156 > 3 )
                  {
                    v188 = v65[7];
                    v189 = v65[3];
                    v190 = v272;
                    *(_DWORD *)(v58 + 36) = v189;
                    if ( v188 == 0xFFFF )
                      v191 = -22;
                    else
                      v191 = v5;
                    if ( v188 != 0xFFFF )
                      v190 = v272 + 1;
                    v192 = v65[7];
                    if ( (_DWORD)v189 == 0xFFFF )
                      v5 = v191;
                    else
                      v5 = 4294967274LL;
                    v193 = v276;
                    if ( (_DWORD)v189 != 0xFFFF )
                      v193 = v276 + 1;
                    *(_DWORD *)(v58 + 52) = v192;
                    v270 = v192;
                    v272 = v190;
                    v276 = v193;
                    cam_print_to_buffer((__int64)&v293, 0xC8u, &v292, 3u, 8u, "VC%d: 0x%x, DT%d: 0x%x ", 3, v189, 3);
                    v156 = *(_DWORD *)(v58 + 56);
                    if ( v156 > 4 )
                    {
LABEL_592:
                      __break(0x5512u);
                      goto LABEL_593;
                    }
                  }
                }
                v7 = -22;
                if ( !v276 || !v272 || v276 && v272 != 1 || (v7 = v5) != 0 )
                {
                  v197 = "cam_ife_mgr_acquire_get_unified_structure_v3";
                  v198 = 6179;
LABEL_365:
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    8,
                    1,
                    v197,
                    v198,
                    "Invalid VC/DT args, printing given %d args: %s",
                    v156,
                    (const char *)&v293);
                  v5 = (__int64)&unk_393000;
LABEL_267:
                  if ( (v7 & 0x80000000) != 0 )
                    goto LABEL_492;
                  goto LABEL_273;
                }
                if ( (debug_mdl & 8) != 0 && !debug_priority )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 8,
                    4,
                    "cam_ife_mgr_acquire_get_unified_structure_v3",
                    6184,
                    "VC/DT args from UMD:, num: %d, pairs: %s",
                    v156,
                    (const char *)&v293);
                  v156 = *(_DWORD *)(v58 + 56);
                  if ( v156 )
                    goto LABEL_381;
                }
                else if ( v156 )
                {
LABEL_381:
                  *(_DWORD *)(v58 + 60) = *((unsigned __int8 *)v65 + 36);
                  if ( v156 != 1 )
                  {
                    *(_DWORD *)(v58 + 64) = *((unsigned __int8 *)v65 + 37);
                    if ( v156 != 2 )
                    {
                      *(_DWORD *)(v58 + 68) = *((unsigned __int8 *)v65 + 38);
                      if ( v156 != 3 )
                      {
                        v63 = *((unsigned __int8 *)v65 + 39);
                        *(_DWORD *)(v58 + 72) = v63;
                        if ( v156 != 4 )
                          goto LABEL_592;
                      }
                    }
                  }
                }
                *(_DWORD *)(v58 + 208) = v65[12];
                *(_DWORD *)(v58 + 92) = v65[10];
                *(_DWORD *)(v58 + 116) = v65[11];
                *(_DWORD *)(v58 + 144) = v65[27];
                *(_BYTE *)(v58 + 217) = (v65[26] & 4) != 0;
                *(_BYTE *)(v58 + 218) = (v65[26] & 2) != 0;
                *(_BYTE *)(v58 + 221) = (v65[26] & 0x80) != 0;
                *(_BYTE *)(v58 + 222) = *((_BYTE *)v65 + 105) & 1;
                if ( mem_trace_en == 1 )
                {
                  v200 = cam_mem_trace_alloc(
                           44LL * v65[27],
                           0xCC0u,
                           0,
                           "cam_ife_mgr_acquire_get_unified_structure_v3",
                           0x1838u);
                  *(_QWORD *)(v58 + 224) = v200;
                  if ( !v200 )
                  {
LABEL_405:
                    v7 = -12;
                    v5 = (__int64)&unk_393000;
                    goto LABEL_267;
                  }
                }
                else
                {
                  v205 = _kvmalloc_node_noprof(44LL * v65[27], 0, 3520, 0xFFFFFFFFLL);
                  *(_QWORD *)(v58 + 224) = v205;
                  if ( !v205 )
                    goto LABEL_405;
                }
                if ( !*(_DWORD *)(v58 + 144) )
                  goto LABEL_399;
                v206 = 0;
                v5 = (__int64)&unk_393000;
                while ( 1 )
                {
                  v207 = v206;
                  v208 = (__int64)&v65[16 * (__int64)v206 + 28];
                  if ( (unsigned int)(*(_DWORD *)(v208 + 32) - 5) <= 0xFFFFFFFB )
                    break;
                  v7 = 0;
                  *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v207) = *(_DWORD *)v208;
                  *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 4) = *(_DWORD *)(v208 + 4);
                  *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 8) = *(_DWORD *)(v208 + 8);
                  *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 12) = *(_DWORD *)(v208 + 12);
                  *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 16) = *(_DWORD *)(v208 + 16);
                  *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 20) = *(_DWORD *)(v208 + 20);
                  *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 24) = *(_DWORD *)(v208 + 24);
                  *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 32) = *(_DWORD *)(v208 + 28);
                  *(_DWORD *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 36) = *(_DWORD *)(v208 + 32);
                  *(_BYTE *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 40) = (*(_BYTE *)(v208 + 36) & 2) != 0;
                  *(_BYTE *)(*(_QWORD *)(v58 + 224) + 44LL * v207 + 41) = *(_BYTE *)(v208 + 36) & 1;
                  v206 = v207 + 1;
                  if ( (unsigned int)(v207 + 1) >= *(_DWORD *)(v58 + 144) )
                    goto LABEL_267;
                }
                v194 = "cam_ife_mgr_acquire_get_unified_structure_v3";
                v195 = 6210;
                v196 = "Invalid hw context id: 0x%x for acquire i: %d";
                goto LABEL_351;
              }
              v126 = 0;
              v125 = 0;
              v124 = 0;
              v123 = 0;
              v122 = 0;
LABEL_409:
              v210 = v122 + v123;
              v284 = v125;
              LODWORD(v285) = v122;
              v211 = (unsigned __int8)mem_trace_en;
              *(_DWORD *)(a2 + 148) = v122 + v123 + v124;
              if ( v211 == 1 )
                v212 = cam_mem_trace_alloc(
                         (unsigned __int64)(v210 + v124) << 7,
                         0xCC0u,
                         0,
                         "cam_ife_mgr_acquire_hw",
                         0x19B4u);
              else
                v212 = _kvmalloc_node_noprof((unsigned __int64)(v210 + v124) << 7, 0, 3520, 0xFFFFFFFFLL);
              v213 = v291;
              v214 = (unsigned int)max_ife_out_res;
              v215 = (void *)v291[1062];
              v291[34] = v212;
              memset(v215, 255, v214);
              if ( !v213[34] )
              {
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_ife_mgr_acquire_hw",
                  6585,
                  "Alloc failed for ife out map");
                a1 = v287;
                v7 = -12;
                v5 = (__int64)&unk_393000;
                goto LABEL_501;
              }
              v280 = v124;
              if ( (unsigned int)v285 | v124 )
              {
                v216 = v290;
                if ( !(_DWORD)v285 )
                {
                  if ( v124 )
                  {
                    if ( v123 )
                    {
                      *((_BYTE *)v213 + 9399) = 1;
                      if ( (debug_mdl & 8) != 0 && !debug_priority )
                      {
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          debug_mdl & 8,
                          4,
                          "cam_ife_mgr_acquire_hw",
                          6599,
                          "RDI and PD context with [%u pd] [%u rdi], ctx_idx: %u",
                          v124,
                          v123,
                          *((_DWORD *)v213 + 14));
LABEL_591:
                        v216 = v290;
                      }
                    }
                  }
                }
              }
              else
              {
                v216 = v290;
                *((_BYTE *)v213 + 9385) = 1;
                if ( (debug_mdl & 8) != 0 && !debug_priority )
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    debug_mdl & 8,
                    4,
                    "cam_ife_mgr_acquire_hw",
                    6591,
                    "RDI only context, ctx_idx: %u",
                    *((_DWORD *)v213 + 14));
                  goto LABEL_591;
                }
              }
              if ( v284 == v210 )
                *((_BYTE *)v213 + 9386) = 1;
              a1 = v287;
              v5 = (__int64)&unk_393000;
              if ( v126 )
              {
                v217 = mem_trace_en == 1
                     ? cam_mem_trace_alloc((unsigned __int64)v126 << 7, 0xCC0u, 0, "cam_ife_mgr_acquire_hw", 0x19D0u)
                     : _kvmalloc_node_noprof((unsigned __int64)v126 << 7, 0, 3520, 0xFFFFFFFFLL);
                v218 = v291;
                v219 = (unsigned int)max_sfe_out_res;
                v220 = (void *)v291[1063];
                v291[35] = v217;
                memset(v220, 255, v219);
                v216 = v290;
                if ( !v218[35] )
                {
                  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
                    3,
                    8,
                    1,
                    "cam_ife_mgr_acquire_hw",
                    6612,
                    "Alloc failed for sfe out map");
                  v7 = -12;
                  goto LABEL_501;
                }
              }
              v66 = v123;
              if ( v216[2] )
              {
                v27 = 0;
                v58 = a2 + 84;
                v221 = a2 + 64;
                v65 = (unsigned int *)v28;
                do
                {
                  v222 = v291;
                  if ( (debug_mdl & 8) != 0 && !debug_priority )
                  {
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 8,
                      4,
                      "cam_ife_mgr_acquire_hw",
                      6620,
                      "ctx_idx: %u in_res_type %x",
                      *((_DWORD *)v291 + 14),
                      v65[2]);
                    v222 = v291;
                    if ( *((_DWORD *)v291 + 2328) )
                      goto LABEL_442;
                  }
                  else if ( *((_DWORD *)v291 + 2328) )
                  {
                    goto LABEL_442;
                  }
                  if ( v65[35] )
                  {
                    v223 = *((_DWORD *)v222 + 2329);
                    *((_DWORD *)v222 + 2328) = 1;
                    *((_DWORD *)v222 + 2329) = v223 | 3;
                  }
                  else if ( v65[49] )
                  {
                    *((_DWORD *)v222 + 2328) = 2;
                  }
LABEL_442:
                  if ( (debug_mdl & 8) != 0 && !debug_priority )
                  {
                    v229 = v222;
                    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 8,
                      4,
                      "cam_ife_mgr_acquire_hw",
                      6637,
                      "in_res_type: 0x%x ctx_idx: %u sfe_in_path_type: 0x%x sfe_ife_enable: 0x%x",
                      v65[2],
                      *((_DWORD *)v222 + 14),
                      v65[49],
                      v65[50]);
                    v222 = v229;
                  }
                  if ( *v65 == 3 )
                  {
                    if ( v65[41] )
                    {
                      v224 = v65[53];
                      if ( v224 )
                      {
                        v225 = v65[52];
                        switch ( v225 )
                        {
                          case 1u:
                            v226 = 0;
                            break;
                          case 0x200u:
                            v226 = 2;
                            break;
                          case 0x100u:
                            v226 = 1;
                            break;
                          default:
                            goto LABEL_455;
                        }
                        *((_DWORD *)v222 + v226 + 2380) = v224;
                      }
                    }
                  }
LABEL_455:
                  v63 = *((unsigned __int8 *)v222 + 9380);
                  if ( v63 == 1 )
                  {
                    if ( v27 > 5 )
                      goto LABEL_592;
                    v227 = cam_ife_mgr_acquire_hw_for_offline_ctx(v222, v65);
                  }
                  else
                  {
                    if ( v27 > 5 )
                      goto LABEL_592;
                    v227 = cam_ife_mgr_acquire_hw_for_ctx(v222, v65);
                  }
                  v7 = v227;
                  if ( v227 )
                  {
                    v58 = (__int64)v291;
                    cam_ife_hw_mgr_print_acquire_info(v291, v65[46] + v65[41] + v65[45], v65[42], v65[43], v227);
                    v2 = &unk_393000;
                    goto LABEL_472;
                  }
                  v228 = *((_QWORD **)v65 + 28);
                  if ( mem_trace_en == 1 )
                    cam_mem_trace_free(v228, 0);
                  else
                    kvfree(v228);
                  *((_QWORD *)v65 + 28) = 0;
                  ++v27;
                  v65 += 58;
                  v58 += 12;
                  v221 += 4;
                }
                while ( v27 < (unsigned int)v290[2] );
              }
              if ( mem_trace_en == 1 )
                cam_mem_trace_free((_QWORD *)v28, 0);
              else
                kvfree(v28);
              v58 = (__int64)v291;
              v2 = &unk_393000;
              v230 = cam_ife_mgr_process_base_info(v291);
              a1 = v287;
              if ( v230 )
              {
                v7 = v230;
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  8,
                  1,
                  "cam_ife_mgr_acquire_hw",
                  6676,
                  "Process base info failed, ctx_idx: %u",
                  *((_DWORD *)v291 + 14));
LABEL_482:
                v28 = 0;
LABEL_483:
                cam_ife_hw_mgr_release_hw_for_ctx(v58);
                goto LABEL_502;
              }
              if ( *((_DWORD *)v291 + 2328) != 2 || (cdm_cmd = cam_ife_mgr_update_core_info_to_cpas(v291, 1)) == 0 )
              {
                v27 = (unsigned __int64)&unk_393000;
                v28 = v287 + 77824;
                if ( *(_BYTE *)(v287 + 81883) == 1 )
                {
                  v232 = *((_DWORD *)v291 + 2328);
                  if ( v232 != 2 )
                  {
LABEL_480:
                    cdm_cmd = cam_ife_mgr_allocate_cdm_cmd(v232 == 2, v291 + 1092);
                    if ( cdm_cmd )
                      goto LABEL_481;
                    v65 = (unsigned int *)(v291 + 1024);
                    if ( *((_BYTE *)v291 + 9379) == 1 )
                    {
                      s[0] = 0x6566696C617564LL;
                      v249 = 60;
                    }
                    else
                    {
                      LODWORD(s[0]) = 6645353;
                      v249 = 8584;
                    }
                    v250 = *(_DWORD *)((char *)v291 + v249);
                    s[17] = v291;
                    v251 = *(_QWORD *)(v287 + 248);
                    LODWORD(s[16]) = v250;
                    LODWORD(s[32]) = 0;
                    LODWORD(s[19]) = 8;
                    if ( v251 )
                    {
                      s[20] = v251;
                      LODWORD(v251) = 1;
                    }
                    v252 = *(_QWORD *)(v287 + 256);
                    if ( v252 )
                    {
                      s[(unsigned int)v251 + 20] = v252;
                      LODWORD(v251) = v251 + 1;
                    }
                    v253 = *(_QWORD *)(v287 + 264);
                    if ( v253 )
                    {
                      s[(unsigned int)v251 + 20] = v253;
                      LODWORD(v251) = v251 + 1;
                    }
                    v254 = *(_QWORD *)(v287 + 272);
                    if ( v254 )
                    {
                      s[(unsigned int)v251 + 20] = v254;
                      LODWORD(v251) = v251 + 1;
                    }
                    v255 = *(_QWORD *)(v287 + 280);
                    if ( v255 )
                    {
                      s[(unsigned int)v251 + 20] = v255;
                      LODWORD(v251) = v251 + 1;
                    }
                    v256 = *(_QWORD *)(v287 + 288);
                    if ( v256 )
                    {
                      s[(unsigned int)v251 + 20] = v256;
                      LODWORD(v251) = v251 + 1;
                    }
                    v257 = *(_QWORD *)(v287 + 296);
                    if ( v257 )
                    {
                      s[(unsigned int)v251 + 20] = v257;
                      LODWORD(v251) = v251 + 1;
                    }
                    v258 = *(_QWORD *)(v287 + 304);
                    if ( v258 )
                    {
                      s[(unsigned int)v251 + 20] = v258;
                      LODWORD(v251) = v251 + 1;
                    }
                    LODWORD(s[19]) = v251;
                    LODWORD(s[28]) = 0;
                    HIDWORD(s[16]) = 0;
                    s[18] = cam_ife_cam_cdm_callback;
                    v259 = cam_cdm_acquire((__int64)s);
                    if ( v259 )
                    {
                      v7 = v259;
                      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        8,
                        1,
                        "cam_ife_mgr_acquire_hw",
                        6722,
                        "Failed to acquire the CDM HW, ctx_idx: %u",
                        *(_DWORD *)(v58 + 56));
                      goto LABEL_589;
                    }
                    LOBYTE(v63) = debug_mdl;
                    if ( (debug_mdl & 8) != 0 && !debug_priority )
LABEL_593:
                      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                        3,
                        v63 & 8,
                        4,
                        "cam_ife_mgr_acquire_hw",
                        6728,
                        "Successfully acquired ctx_idx: %u CDM Id: %d, CDM HW hdl=%x, is_dual=%d",
                        *(_DWORD *)(v58 + 56),
                        HIDWORD(s[16]),
                        LODWORD(s[32]),
                        *((unsigned __int8 *)v65 + 1187));
                    v260 = HIDWORD(s[16]);
                    v261 = HIDWORD(s[32]);
                    v262 = HIDWORD(s[16]) == 3;
                    *(_DWORD *)(v58 + 8720) = s[32];
                    *(_DWORD *)(v58 + 8744) = v260;
                    *(_DWORD *)(v58 + 8724) = v261;
                    if ( v262 )
                      *((_BYTE *)v65 + 1190) = 1;
                    *(_DWORD *)(v58 + 8848) = 1;
                    *(_QWORD *)(v58 + 8856) = 0;
                    if ( byte_3A85C4 == 1 )
                      *(_DWORD *)(a2 + 60) |= 4u;
                    if ( byte_3A85D4 == 1 && (*(_BYTE *)(v28 + 3210) & 1) == 0 )
                      *(_DWORD *)(a2 + 60) |= 0x80u;
                    if ( (*((_BYTE *)v65 + 1195) & 1) != 0 || (v65[299] & 1) != 0 || *((_BYTE *)v65 + 1208) == 1 )
                    {
                      v262 = mem_trace_en == 1;
                      *(_DWORD *)(a2 + 60) |= 8u;
                      if ( v262 )
                        v263 = cam_mem_trace_alloc(144, 0xCC0u, 0, "cam_ife_mgr_acquire_hw", 0x1A60u);
                      else
                        v263 = _kvmalloc_node_noprof(144, 0, 3520, 0xFFFFFFFFLL);
                      v58 = (__int64)v291;
                      v291[1170] = v263;
                      if ( v263 )
                      {
                        if ( mem_trace_en == 1 )
                          v264 = cam_mem_trace_alloc(96, 0xCC0u, 0, "cam_ife_mgr_acquire_hw", 0x1A69u);
                        else
                          v264 = _kvmalloc_node_noprof(96, 0, 3520, 0xFFFFFFFFLL);
                        v58 = (__int64)v291;
                        v291[1171] = v264;
                        if ( v264 )
                        {
                          *(_BYTE *)(v264 + 88) = 0;
                          *(_BYTE *)(*(_QWORD *)(v58 + 9360) + 136LL) = 0;
                          *(_DWORD *)(*(_QWORD *)(v58 + 9368) + 4LL) = 0;
                          *(_DWORD *)(*(_QWORD *)(v58 + 9360) + 4LL) = 0;
                          goto LABEL_570;
                        }
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          8,
                          1,
                          "cam_ife_mgr_acquire_hw",
                          6764,
                          "Failed to allocate IFE scratch config, ctx_idx: %u",
                          *(_DWORD *)(v58 + 56));
                        v268 = *(_QWORD **)(v58 + 9360);
                        if ( mem_trace_en == 1 )
                          cam_mem_trace_free(v268, 0);
                        else
                          kvfree(v268);
                      }
                      else
                      {
                        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                          3,
                          8,
                          1,
                          "cam_ife_mgr_acquire_hw",
                          6755,
                          "Failed to allocate SFE scratch config, ctx_idx: %u",
                          *(_DWORD *)(v58 + 56));
                      }
                      v7 = -12;
LABEL_589:
                      cam_ife_mgr_free_cdm_cmd(v58 + 8736);
                      v58 = (__int64)v291;
                      v28 = 0;
                      v2 = (_QWORD *)v27;
LABEL_472:
                      a1 = v287;
                      goto LABEL_483;
                    }
LABEL_570:
                    *(_QWORD *)(a2 + 48) = v58;
                    if ( *(_DWORD *)(v58 + 9312) == 1 )
                    {
                      *(_DWORD *)(a2 + 60) |= 1u;
                      v265 = *(_DWORD *)(v58 + 9316);
                      if ( (v265 & 1) != 0 )
                        goto LABEL_572;
                    }
                    else
                    {
                      v265 = *(_DWORD *)(v58 + 9316);
                      if ( (v265 & 1) != 0 )
                      {
LABEL_572:
                        *(_DWORD *)(a2 + 60) |= 2u;
                        if ( (*(_DWORD *)(v58 + 9316) & 4) == 0 )
                        {
LABEL_577:
                          if ( *(_DWORD *)(v58 + 9312) == 2 )
                            *(_DWORD *)(a2 + 60) |= 0x10u;
                          if ( *(_BYTE *)(v58 + 9391) == 1 )
                            *(_DWORD *)(a2 + 60) |= 0x20u;
                          *(_DWORD *)(v58 + 9140) = 0;
                          *(_BYTE *)(v58 + 9376) = 1;
                          v266 = max_ife_out_res;
                          v267 = v290[2];
                          *(_DWORD *)(a2 + 160) = 2;
                          *(_DWORD *)(a2 + 164) = v266;
                          *(_DWORD *)(a2 + 144) = v267;
                          *(_DWORD *)(a2 + 168) = max_sfe_out_res;
                          *(_DWORD *)(a2 + 56) = *(_DWORD *)(v58 + 56);
                          *(_QWORD *)(a2 + 152) = &dword_3A8590;
                          cam_ife_hw_mgr_print_acquire_info(v58, (unsigned int)v285, v280, v66, 0);
                          cam_ife_hw_mgr_put_ctx(v287 + 384, &v291);
                          v7 = 0;
                          v109 = *(_QWORD *)(v27 + 3664);
                          if ( (v109 & 8) == 0 )
                            goto LABEL_213;
                          goto LABEL_211;
                        }
LABEL_576:
                        *(_DWORD *)(a2 + 60) |= 0x40u;
                        goto LABEL_577;
                      }
                    }
                    if ( (v265 & 4) == 0 )
                      goto LABEL_577;
                    goto LABEL_576;
                  }
                }
                cdm_cmd = cam_ife_mgr_share_sof_qtimer_addr(v291);
                if ( !cdm_cmd )
                {
                  v232 = *((_DWORD *)v291 + 2328);
                  goto LABEL_480;
                }
              }
LABEL_481:
              a1 = v287;
              v7 = cdm_cmd;
              goto LABEL_482;
            }
            v119 = "No memory for sfe_bus_comp_grp";
            v120 = 6526;
          }
          else
          {
            v119 = "No memory for vfe_bus_comp_grp";
            v120 = 6518;
          }
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            0x80000,
            1,
            "cam_ife_mgr_acquire_hw",
            v120,
            v119);
          v209 = v290;
          v7 = -12;
          goto LABEL_503;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, int))cam_print_log)(
          3,
          v2[458] & 8LL,
          4,
          "cam_ife_mgr_check_and_update_fe_v0",
          5028,
          "is_fe_enabled %d, ctx_idx: %u",
          *((unsigned __int8 *)v18 + 9378),
          *((unsigned int *)v18 + 14),
          v269);
LABEL_586:
        v44 = v290;
        goto LABEL_235;
      }
      v84 = *((_DWORD *)v18 + 14);
      v85 = "cam_ife_mgr_check_and_update_fe_v0";
      v86 = "Invalid size offset 0x%x is greater then size 0x%x, ctx_idx: %u";
      v87 = 4983;
LABEL_155:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
        3,
        8,
        1,
        v85,
        v87,
        v86,
        v48,
        v49,
        v84);
      goto LABEL_156;
    }
    v49 = (unsigned int)v44[4];
    v48 = (unsigned int)v44[5];
    if ( (unsigned int)v48 >= (unsigned int)v49 )
    {
      v84 = *((_DWORD *)v18 + 14);
      v85 = "cam_ife_mgr_check_and_update_fe_v2";
      v86 = "Invalid size offset 0x%x is greater then size 0x%x ctx_idx: %u";
      v87 = 5060;
      goto LABEL_155;
    }
    v289 = a1;
    if ( !v44[2] )
    {
LABEL_168:
      a1 = v289;
      v2 = &unk_393000;
      v5 = (__int64)&unk_393000;
      if ( (debug_mdl & 8) == 0 || debug_priority )
        goto LABEL_235;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, _DWORD, _DWORD))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_mgr_check_and_update_fe_v2",
        5131,
        "is_fe_enabled %d is_offline %d sfe_fs %d sfe_shdr: %d num_sfe_fetches: %u ctx_idx: %u",
        *((unsigned __int8 *)v18 + 9378),
        *((unsigned __int8 *)v18 + 9380),
        *((unsigned __int8 *)v18 + 9388),
        *((unsigned __int8 *)v18 + 9387),
        *((_DWORD *)v18 + 2338),
        *((_DWORD *)v18 + 14));
      goto LABEL_586;
    }
    v75 = 0;
    v76 = 0;
    v77 = 0;
    v78 = (unsigned __int64)v44 + v46;
    v79 = (__int64)v44 + v48 + 24;
    v80 = 152;
    while ( 1 )
    {
      if ( v79 + 192 > v78 )
      {
        v113 = *((unsigned int *)v18 + 14);
        v114 = "Invalid size, ctx_idx: %u";
        v115 = 5073;
        goto LABEL_226;
      }
      v81 = *(_DWORD *)(v79 + 120);
      if ( v81 - 1 >= (unsigned int)(max_sfe_out_res + max_ife_out_res) )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_check_and_update_fe_v2",
          5081,
          "Invalid num output res %u, ctx_idx: %u",
          v81,
          *((_DWORD *)v18 + 14));
        goto LABEL_227;
      }
      v82 = v80 + 40 * v81;
      v75 += v82;
      if ( v75 > v44[4] )
      {
        v113 = *((unsigned int *)v18 + 14);
        v114 = "buffer size is not enough, ctx_idx: %u";
        v115 = 5092;
LABEL_226:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_check_and_update_fe_v2",
          v115,
          v114,
          v113);
LABEL_227:
        a1 = v289;
        v5 = (__int64)&unk_393000;
        v2 = &unk_393000;
LABEL_156:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_mgr_acquire_hw",
          6501,
          "buffer size is not enough, ctx_idx: %u",
          *((_DWORD *)v18 + 14));
        v7 = -22;
        goto LABEL_157;
      }
      if ( (debug_mdl & 8) != 0 && !debug_priority )
      {
        v286 = v78;
        v282 = v80;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_mgr_check_and_update_fe_v2",
          5096,
          "in_port%d res_type 0x%x ctx_idx: %u",
          v77,
          *(_DWORD *)v79,
          *((_DWORD *)v18 + 14));
        v80 = v282;
        v78 = v286;
        v44 = v290;
      }
      v83 = *(unsigned __int16 *)(v79 + 136) - 20481;
      if ( v83 <= 2 )
        ++*((_DWORD *)v18 + 2338);
      if ( (v76 & 1) == 0 )
      {
        if ( v83 >= 3 && *(_DWORD *)v79 != 16391 )
        {
          v76 = 0;
          goto LABEL_117;
        }
        *((_BYTE *)v18 + 9378) = 1;
        if ( *(_DWORD *)(v79 + 124) )
          *((_BYTE *)v18 + 9380) = 1;
        if ( v83 <= 2 && (*((_BYTE *)v18 + 9380) & 1) == 0 )
        {
          v76 = 1;
          if ( (*(_BYTE *)(v79 + 140) & 0x20) != 0 )
            *((_BYTE *)v18 + 9388) = 1;
          else
            *((_BYTE *)v18 + 9387) = 1;
          goto LABEL_117;
        }
      }
      v76 = 1;
LABEL_117:
      ++v77;
      v79 += v82;
      if ( v77 >= v44[2] )
        goto LABEL_168;
    }
  }
  if ( !v6 )
    goto LABEL_6;
  memset(s, 0, 0x108u);
  LODWORD(v292) = 0;
  LODWORD(v291) = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_mgr_acquire_dev",
      6909,
      "Enter...");
    if ( !*(_DWORD *)(a2 + 32) )
    {
      v233 = "cam_ife_mgr_acquire_dev";
      v234 = 6912;
LABEL_488:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        v233,
        v234,
        "Nothing to acquire. Seems like error");
      v7 = -22;
      LOBYTE(v109) = debug_mdl;
      if ( (debug_mdl & 8) != 0 )
        goto LABEL_211;
      goto LABEL_213;
    }
  }
  v13 = (_QWORD *)(a1 + 368);
  mutex_lock(&unk_394A30);
  v14 = *(_QWORD **)(a1 + 368);
  if ( v14 == (_QWORD *)(a1 + 368) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_hw_mgr_get_ctx",
      2614,
      "No more free ife hw mgr ctx");
    v17 = nullptr;
    v7 = -1;
  }
  else
  {
    v15 = (_QWORD *)v14[1];
    if ( (_QWORD *)*v15 == v14 && (v16 = *v14, *(_QWORD **)(*v14 + 8LL) == v14) )
    {
      *(_QWORD *)(v16 + 8) = v15;
      *v15 = v16;
    }
    else
    {
      _list_del_entry_valid_or_report(*(_QWORD *)(a1 + 368));
    }
    v7 = 0;
    *v14 = v14;
    v17 = v14;
    v14[1] = v14;
  }
  v293 = v17;
  mutex_unlock(&unk_394A30);
  if ( v14 == v13 || !v17 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_acquire_dev",
      6919,
      "Get ife hw context failed");
    goto LABEL_208;
  }
  *((_DWORD *)v17 + 2180) = 0;
  v287 = a1;
  v17[4] = *(_QWORD *)a2;
  v26 = *(_QWORD *)(a2 + 16);
  v17[9] = a1;
  v17[3] = v26;
  v17[1091] = cam_cdm_publish_ops();
  v27 = *(_QWORD *)(a2 + 40);
  if ( mem_trace_en != 1 )
  {
    v28 = _kvmalloc_node_noprof(232LL * *(unsigned int *)(a2 + 32), 0, 3520, 0xFFFFFFFFLL);
    if ( v28 )
      goto LABEL_33;
LABEL_77:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_acquire_dev",
      6937,
      "No memory available, ctx_idx: %u",
      *((_DWORD *)v293 + 14));
    v7 = -12;
    goto LABEL_208;
  }
  v28 = cam_mem_trace_alloc(232LL * *(unsigned int *)(a2 + 32), 0xCC0u, 0, "cam_ife_mgr_acquire_dev", 0x1B16u);
  if ( !v28 )
    goto LABEL_77;
LABEL_33:
  v29 = *(_DWORD *)(a2 + 32);
  v285 = v13;
  if ( !v29 )
  {
    v57 = 0;
    v281 = 0;
    v58 = 0;
    LODWORD(v290) = 0;
    goto LABEL_79;
  }
  v30 = 0;
  v31 = 0;
  v32 = 0;
  LODWORD(v290) = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v33 = v27 + 24LL * v30;
    v34 = v30;
    if ( !*(_DWORD *)v33 )
      break;
LABEL_37:
    v29 = *(_DWORD *)(a2 + 32);
    v30 = v34 + 1;
    if ( v34 + 1 >= v29 )
    {
      v62 = v31;
      v57 = v31 != 0;
      v58 = v32;
      v281 = v62;
      if ( v32 && v62 )
      {
LABEL_92:
        v63 = *(_DWORD *)(a2 + 32);
        v280 = v58;
        if ( v63 )
        {
          v64 = 0;
          v65 = (unsigned int *)(a2 + 84);
          v66 = 24;
          v5 = 12;
          do
          {
            v8 = (_QWORD *)v64;
            if ( !*(_DWORD *)(v27 + 24LL * v64) )
            {
              if ( (unsigned int)v64 >= 6 )
                goto LABEL_592;
              v58 = v28 + 232LL * v64;
              v67 = cam_ife_mgr_acquire_hw_for_ctx(v293, v58);
              if ( v67 )
              {
                v69 = v293;
                v7 = v67;
                cam_ife_hw_mgr_print_acquire_info(v293, v280, v281, (unsigned int)v290, v67);
                v5 = (__int64)&unk_393000;
                goto LABEL_152;
              }
              v68 = *(_QWORD **)(v58 + 224);
              if ( mem_trace_en == 1 )
                cam_mem_trace_free(v68, 0);
              else
                kvfree(v68);
              *(_QWORD *)(v58 + 224) = 0;
              v63 = *(_DWORD *)(a2 + 32);
            }
            v64 = (_DWORD)v8 + 1;
          }
          while ( (int)v8 + 1 < v63 );
        }
        if ( mem_trace_en == 1 )
          cam_mem_trace_free((_QWORD *)v28, 0);
        else
          kvfree(v28);
        v69 = v293;
        v71 = v285;
        v70 = v287;
        v72 = cam_ife_mgr_process_base_info(v293);
        v5 = (__int64)&unk_393000;
        v2 = &unk_393000;
        if ( v72 )
        {
          v7 = v72;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_acquire_dev",
            7057,
            "Process base info failed, ctx_idx: %u",
            *((_DWORD *)v293 + 14));
LABEL_191:
          v28 = 0;
          goto LABEL_192;
        }
        if ( *((_DWORD *)v293 + 2328) == 2 )
        {
          updated = cam_ife_mgr_update_core_info_to_cpas(v293, 1);
          if ( updated )
          {
            v7 = updated;
            goto LABEL_191;
          }
        }
        v74 = cam_ife_mgr_allocate_cdm_cmd(0, v293 + 1092);
        if ( v74 )
        {
          v7 = v74;
LABEL_190:
          v70 = v287;
          goto LABEL_191;
        }
        cam_cpas_get_cpas_hw_version((_DWORD *)v293 + 2224);
        v92 = *((unsigned __int8 *)v293 + 9379);
        *((_BYTE *)v293 + 9382) = 0;
        if ( v92 == 1 )
          s[0] = 0x6566696C617564LL;
        else
          LODWORD(s[0]) = 6645353;
        v93 = *((_DWORD *)v69 + 2146);
        s[17] = v69;
        v94 = *(_QWORD *)(v287 + 248);
        LODWORD(s[16]) = v93;
        LODWORD(s[32]) = 0;
        LODWORD(s[19]) = 8;
        if ( v94 )
        {
          s[20] = v94;
          LODWORD(v94) = 1;
        }
        v95 = *(_QWORD *)(v287 + 256);
        if ( v95 )
        {
          s[(unsigned int)v94 + 20] = v95;
          LODWORD(v94) = v94 + 1;
        }
        v96 = *(_QWORD *)(v287 + 264);
        if ( v96 )
        {
          s[(unsigned int)v94 + 20] = v96;
          LODWORD(v94) = v94 + 1;
        }
        v97 = *(_QWORD *)(v287 + 272);
        if ( v97 )
        {
          s[(unsigned int)v94 + 20] = v97;
          LODWORD(v94) = v94 + 1;
        }
        v98 = *(_QWORD *)(v287 + 280);
        if ( v98 )
        {
          s[(unsigned int)v94 + 20] = v98;
          LODWORD(v94) = v94 + 1;
        }
        v99 = *(_QWORD *)(v287 + 288);
        if ( v99 )
        {
          s[(unsigned int)v94 + 20] = v99;
          LODWORD(v94) = v94 + 1;
        }
        v100 = *(_QWORD *)(v287 + 296);
        if ( v100 )
        {
          s[(unsigned int)v94 + 20] = v100;
          LODWORD(v94) = v94 + 1;
        }
        v101 = *(_QWORD *)(v287 + 304);
        if ( v101 )
        {
          s[(unsigned int)v94 + 20] = v101;
          LODWORD(v94) = v94 + 1;
        }
        LODWORD(s[19]) = v94;
        LODWORD(s[28]) = 0;
        HIDWORD(s[16]) = 0;
        s[18] = cam_ife_cam_cdm_callback;
        v102 = cam_cdm_acquire((__int64)s);
        if ( v102 )
        {
          v7 = v102;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            8,
            1,
            "cam_ife_mgr_acquire_dev",
            7094,
            "Failed to acquire the CDM HW, ctx_idx: %u",
            *((_DWORD *)v69 + 14));
          cam_ife_mgr_free_cdm_cmd(v69 + 1092);
          goto LABEL_190;
        }
        if ( (debug_mdl & 8) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 8,
            4,
            "cam_ife_mgr_acquire_dev",
            7099,
            "Successfully acquired CDM ID:%d, CDM HW hdl=%x ctx_idx: %u",
            HIDWORD(s[16]),
            LODWORD(s[32]),
            *((_DWORD *)v69 + 14));
        v111 = HIDWORD(s[16]);
        if ( HIDWORD(s[16]) == 3 )
          *((_BYTE *)v69 + 9382) = 1;
        v112 = s[32];
        *((_DWORD *)v69 + 2186) = v111;
        *((_DWORD *)v69 + 2180) = v112;
        *((_DWORD *)v69 + 2212) = 1;
        v69[1107] = 0;
        *(_QWORD *)(a2 + 48) = v69;
        *((_BYTE *)v69 + 9376) = 1;
        *((_DWORD *)v69 + 2285) = 0;
        cam_ife_hw_mgr_print_acquire_info(v69, v280, v281, (unsigned int)v290, 0);
        cam_ife_hw_mgr_put_ctx(v287 + 384, &v293);
        v7 = 0;
        LOBYTE(v109) = debug_mdl;
        if ( (debug_mdl & 8) == 0 )
          goto LABEL_213;
LABEL_211:
        if ( !*(_DWORD *)(v5 + 3676) )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v109 & 8,
            4,
            "cam_ife_mgr_acquire",
            7157,
            "Exit...(rc=%d)",
            v7);
        goto LABEL_213;
      }
LABEL_79:
      v59 = v293;
      v60 = v293 + 1024;
      *((_BYTE *)v293 + 9385) = 1;
      if ( (debug_mdl & 8) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 8,
          4,
          "cam_ife_mgr_acquire_dev",
          7018,
          "RDI only context, ctx_idx: %u",
          *((_DWORD *)v59 + 14));
      if ( (_DWORD)v58 )
        v61 = 0;
      else
        v61 = v57;
      if ( v61 )
      {
        if ( (_DWORD)v290 )
        {
          v58 = 0;
          *((_BYTE *)v60 + 1207) = 1;
          if ( (debug_mdl & 8) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 8,
              4,
              "cam_ife_mgr_acquire_dev",
              7026,
              "RDI and PD context with [%u pd] [%u rdi] ctx_idx: %u",
              v281,
              (_DWORD)v290,
              *((_DWORD *)v59 + 14));
            v58 = 0;
          }
        }
      }
      goto LABEL_92;
    }
  }
  v35 = debug_priority;
  v36 = debug_mdl & 8;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v36,
      4,
      "cam_ife_mgr_acquire_dev",
      6947,
      "ctx_idx: %u acquire no = %d total = %d",
      *((_DWORD *)v293 + 14),
      v34,
      v29);
    v35 = debug_priority;
    v36 = debug_mdl & 8;
    if ( (debug_mdl & 8) == 0 )
      goto LABEL_44;
  }
  else if ( (debug_mdl & 8) == 0 )
  {
    goto LABEL_44;
  }
  if ( !v35 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v36,
      4,
      "cam_ife_mgr_acquire_dev",
      6951,
      "ctx_idx: %u start copy from user handle %lld with len = %d",
      *((_DWORD *)v293 + 14),
      *(_QWORD *)(v33 + 16),
      *(_DWORD *)(v33 + 4));
LABEL_44:
  v37 = *(unsigned int *)(v33 + 4);
  if ( (unsigned int)v37 <= 0x7F )
  {
    v69 = v293;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_acquire_dev",
      6957,
      "buffer size is not enough, ctx_idx: %u",
      *((_DWORD *)v293 + 14));
    v7 = -22;
    goto LABEL_152;
  }
  v38 = *(_QWORD *)(v33 + 16);
  if ( mem_trace_en == 1 )
    v39 = (_DWORD *)memdup_user_trace(v38, v37, "cam_ife_mgr_acquire_dev", 0x1B34u);
  else
    v39 = (_DWORD *)memdup_user(v38, v37);
  v40 = v39;
  if ( (unsigned __int64)v39 > 0xFFFFFFFFFFFFF000LL )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_acquire_dev",
      7009,
      "Copy from user failed with in_port = %pK, ctx_idx: %u",
      v39,
      *((_DWORD *)v293 + 14));
    v7 = -14;
    v2 = &unk_393000;
    goto LABEL_198;
  }
  v41 = v39[23];
  if ( v41 > max_ife_out_res )
  {
    v69 = v293;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_mgr_acquire_dev",
      6968,
      "too many output res %d, ctx_idx: %u",
      v41,
      *((_DWORD *)v293 + 14));
    goto LABEL_147;
  }
  if ( 32 * v41 + 96 <= *(_DWORD *)(v33 + 4) )
  {
    if ( mem_trace_en == 1 )
      v42 = cam_mem_trace_alloc(44LL * v41, 0xCC0u, 0, "cam_ife_mgr_acquire_dev", 0x1B4Cu);
    else
      v42 = _kvmalloc_node_noprof(44LL * (unsigned int)v39[23], 0, 3520, 0xFFFFFFFFLL);
    v43 = v28 + 232LL * v34;
    *(_QWORD *)(v43 + 224) = v42;
    if ( v42 )
    {
      cam_ife_mgr_acquire_get_unified_dev_str(v40, v28 + 232LL * v34);
      cam_ife_hw_mgr_preprocess_port(v293, v28 + 232LL * v34);
      v31 += *(_DWORD *)(v43 + 168);
      v32 += *(_DWORD *)(v43 + 164) + *(_DWORD *)(v43 + 184) + *(_DWORD *)(v43 + 180);
      LODWORD(v290) = *(_DWORD *)(v43 + 172) + (_DWORD)v290;
      if ( mem_trace_en == 1 )
        cam_mem_trace_free(v40, 0);
      else
        kvfree(v40);
      goto LABEL_37;
    }
    v69 = v293;
    v7 = -12;
LABEL_152:
    v71 = v285;
    v70 = v287;
    v2 = &unk_393000;
    goto LABEL_192;
  }
  v69 = v293;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_ife_mgr_acquire_dev",
    6979,
    "buffer size is not enough, ctx_idx: %u",
    *((_DWORD *)v293 + 14));
LABEL_147:
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v40, 0);
  else
    kvfree(v40);
  v71 = v285;
  v70 = v287;
  v7 = -22;
  v2 = &unk_393000;
LABEL_192:
  cam_ife_hw_mgr_release_hw_for_ctx(v69);
  mutex_lock(&unk_394A30);
  if ( v69 )
  {
    v103 = *(_QWORD **)(v70 + 376);
    if ( v69 == v71 || v103 == v69 || (_QWORD *)*v103 != v71 )
    {
      _list_add_valid_or_report(v69);
    }
    else
    {
      *(_QWORD *)(v70 + 376) = v69;
      *v69 = v71;
      v69[1] = v103;
      *v103 = v69;
    }
  }
  v293 = nullptr;
  mutex_unlock(&unk_394A30);
LABEL_198:
  if ( v28 )
  {
    if ( *(_DWORD *)(a2 + 32) )
    {
      v104 = 0;
      do
      {
        v105 = v28 + 232LL * (int)v104;
        v108 = *(_QWORD **)(v105 + 224);
        v107 = (_QWORD *)(v105 + 224);
        v106 = v108;
        if ( mem_trace_en == 1 )
          cam_mem_trace_free(v106, 0);
        else
          kvfree(v106);
        *v107 = 0;
        ++v104;
      }
      while ( v104 < *(_DWORD *)(a2 + 32) );
    }
    if ( mem_trace_en == 1 )
      cam_mem_trace_free((_QWORD *)v28, 0);
    else
      kvfree(v28);
  }
LABEL_208:
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v89 = "cam_ife_mgr_acquire_dev";
    v90 = debug_mdl & 8;
    v91 = 7134;
    goto LABEL_496;
  }
LABEL_210:
  v109 = v2[458];
  if ( (v109 & 8) != 0 )
    goto LABEL_211;
LABEL_213:
  _ReadStatusReg(SP_EL0);
  return v7;
}
