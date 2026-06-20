__int64 __fastcall sde_plane_atomic_set_property(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  int v8; // w4
  unsigned int v9; // w23
  int v10; // w0
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x9
  unsigned __int64 v13; // x9
  unsigned __int64 v19; // x8
  size_t v20; // x2
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x9
  __int64 v25; // x11
  __int64 v26; // x10
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x12
  unsigned __int64 v29; // x9
  unsigned __int64 v30; // x11
  unsigned __int64 v31; // x10
  __int64 v32; // x12
  __int64 v33; // x8
  unsigned __int64 v34; // x9
  __int64 v35; // x8
  __int64 v36; // x10
  __int64 v37; // x11
  __int64 v38; // x8
  unsigned __int64 v39; // x8
  unsigned __int64 v40; // x9
  unsigned __int64 v41; // x9
  unsigned __int64 v43; // x8
  unsigned __int64 v44; // x8
  unsigned __int64 v46; // x9
  __int16 v47; // w6
  __int16 v48; // w9
  char v49; // w10
  __int16 v50; // w8
  __int64 v51; // x4
  const char *v52; // x3
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x9
  unsigned __int64 v55; // x9
  unsigned __int64 v57; // x8
  unsigned __int64 v58; // x8
  unsigned __int64 v60; // x9
  __int16 v61; // w6
  __int16 v62; // w9
  char v63; // w10
  __int16 v64; // w8
  unsigned __int64 v65; // x8
  unsigned __int64 v66; // x9
  unsigned __int64 v67; // x9
  unsigned __int64 v69; // x8
  unsigned __int64 v70; // x8
  unsigned __int64 v72; // x9
  int v73; // w11
  __int64 v74; // x9
  int v75; // w7
  __int64 v76; // x10
  int v77; // w5
  __int64 v78; // x8
  __int64 v79; // x12
  __int64 v80; // x9
  __int64 v81; // x10
  __int64 v82; // x11
  int v83; // w13
  int v84; // w14
  int v85; // w13
  int v86; // w14
  int v87; // w9
  int v88; // w8
  int v89; // w9
  int v90; // w8
  int v91; // w9
  int v92; // w8
  int v93; // w9
  int v94; // w8
  int v95; // w9
  int v96; // w8
  int v97; // w9
  int v98; // w8
  int v99; // w9
  int v100; // w8
  int v101; // w9
  int v102; // w8
  int v103; // w9
  int v104; // w8
  int v105; // w9
  int v106; // w8
  int v107; // w9
  int v108; // w8
  int v109; // w9
  int v110; // w8
  int v111; // w9
  int v112; // w8
  int v113; // w9
  int v114; // w8
  int v115; // w9
  int v116; // w8
  int v117; // w9
  int v118; // w8
  int v119; // w9
  int v120; // w8
  int v121; // w0
  int v122; // w9
  int v123; // w8
  int v124; // w9
  int v125; // w8
  int v126; // w9
  int v127; // w8
  int v128; // w9
  int v129; // w4
  unsigned __int64 v130; // x8
  unsigned __int64 v131; // x9
  unsigned __int64 v132; // x9
  unsigned __int64 v134; // x8
  unsigned __int64 v135; // x8
  unsigned __int64 v137; // x9
  __int64 v138; // x8
  __int64 v139; // x10
  __int64 v140; // x9
  __int64 v141; // x8
  __int64 v142; // x9
  __int64 v143; // x11
  __int64 v144; // x9
  __int64 v145; // x9
  __int64 v146; // x8
  __int64 v147; // x9
  __int64 v148; // x11
  int v149; // w12
  int v150; // w13
  int v151; // w14
  int v152; // w12
  int v153; // w13
  int v154; // w14
  int v155; // w6
  int v156; // w7
  unsigned __int64 v157; // x8
  unsigned __int64 v158; // x9
  unsigned __int64 v159; // x9
  unsigned __int64 v161; // x8
  unsigned __int64 v162; // x8
  unsigned __int64 v164; // x9
  __int16 v165; // w6
  __int16 v166; // w9
  char v167; // w10
  __int16 v168; // w8
  __int64 v169; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v171; // x9
  unsigned __int64 v172; // x9
  unsigned __int64 v174; // x8
  unsigned __int64 v175; // x8
  unsigned __int64 v177; // x9
  __int16 v178; // w6
  __int16 v179; // w9
  char v180; // w10
  __int16 v181; // w8
  unsigned __int64 v182; // x8
  unsigned __int64 v183; // x9
  unsigned __int64 v184; // x9
  unsigned __int64 v186; // x8
  unsigned __int64 v187; // x8
  unsigned __int64 v189; // x9
  int v190; // w5
  unsigned int v191; // w8
  int v192; // w6
  char v193; // w8
  __int64 v195; // x0
  char v196; // [xsp+0h] [xbp-2F0h]
  _QWORD s[89]; // [xsp+28h] [xbp-2C8h] BYREF

  s[88] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (_drm_debug & 4) != 0 )
  {
    if ( a1 )
      v8 = *(_DWORD *)(a1 + 104);
    else
      v8 = -1;
    _drm_dev_dbg(0, 0, 0, "plane%d \n", v8);
  }
  if ( !a1 )
  {
    printk(&unk_226FC0, "sde_plane_atomic_set_property");
    v9 = -22;
    if ( (_drm_debug & 4) != 0 )
    {
      v129 = -1;
LABEL_124:
      _drm_dev_dbg(
        0,
        0,
        0,
        "plane%d %s[%d] <= 0x%llx ret=%d\n",
        v129,
        (const char *)(a3 + 52),
        *(_DWORD *)(a3 + 16),
        a4,
        v9);
    }
LABEL_125:
    _ReadStatusReg(SP_EL0);
    return v9;
  }
  if ( !a2 )
  {
    printk(&unk_2246B5, "sde_plane_atomic_set_property");
    v9 = -22;
    goto LABEL_122;
  }
  v9 = msm_property_atomic_set(a1 + 3344, a2 + 176, a3, a4);
  if ( v9 )
    goto LABEL_122;
  v10 = msm_property_index(a1 + 3344, a3);
  if ( v10 > 29 )
  {
    if ( v10 > 37 )
    {
      if ( v10 == 38 )
      {
        s[0] = 0;
        if ( !a4 )
        {
          *(_QWORD *)(a2 + 2920) = 0;
          goto LABEL_121;
        }
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v171 = a4, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v171 = a4 & ((__int64)(a4 << 8) >> 8);
        if ( v171 > 0x7FFFFFFFF8LL )
        {
          v20 = 8;
        }
        else
        {
          v172 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v174 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v174 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v174);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v172);
          v20 = _arch_copy_from_user(s, a4 & 0xFF7FFFFFFFFFFFFFLL, 8);
          v175 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v177 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v177 - 4096);
          _WriteStatusReg(TTBR1_EL1, v177);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v175);
          if ( !v20 )
          {
            v178 = WORD1(s[0]);
            v179 = HIWORD(s[0]);
            v180 = _drm_debug;
            v181 = WORD2(s[0]) - LOWORD(s[0]);
            *(_WORD *)(a2 + 2920) = s[0];
            *(_WORD *)(a2 + 2922) = v178;
            *(_WORD *)(a2 + 2924) = v181;
            *(_WORD *)(a2 + 2926) = v179 - v178;
            if ( (v180 & 4) == 0 )
              goto LABEL_121;
            v51 = *(unsigned int *)(a1 + 104);
            v52 = "plane%d img size: {%u,%u,%u,%u}\n";
            goto LABEL_88;
          }
        }
        if ( v20 < 9 )
        {
          memset((char *)&s[1] - v20, 0, v20);
          printk(&unk_246666, "_sde_plane_set_img_size");
          goto LABEL_121;
        }
        goto LABEL_150;
      }
      if ( v10 == 46 )
      {
        s[0] = 0;
        if ( !a4 )
        {
          *(_QWORD *)(a2 + 2928) = 0;
          goto LABEL_121;
        }
        v157 = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(v157 + 70) & 0x20) != 0 || (v158 = a4, (*(_QWORD *)v157 & 0x4000000) != 0) )
          v158 = a4 & ((__int64)(a4 << 8) >> 8);
        if ( v158 > 0x7FFFFFFFF8LL )
        {
          v20 = 8;
        }
        else
        {
          v159 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v161 = *(_QWORD *)(v157 + 8);
          _WriteStatusReg(TTBR1_EL1, v161 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v161);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v159);
          v20 = _arch_copy_from_user(s, a4 & 0xFF7FFFFFFFFFFFFFLL, 8);
          v162 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v164 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v164 - 4096);
          _WriteStatusReg(TTBR1_EL1, v164);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v162);
          if ( !v20 )
          {
            v165 = WORD1(s[0]);
            v166 = HIWORD(s[0]);
            v167 = _drm_debug;
            v168 = WORD2(s[0]) - LOWORD(s[0]);
            *(_WORD *)(a2 + 2928) = s[0];
            *(_WORD *)(a2 + 2930) = v165;
            *(_WORD *)(a2 + 2932) = v168;
            *(_WORD *)(a2 + 2934) = v166 - v165;
            if ( (v167 & 4) == 0 )
              goto LABEL_121;
            v51 = *(unsigned int *)(a1 + 104);
            v52 = "plane%d src rect extn dimensions: {%d,%d,%d,%d}\n";
            goto LABEL_88;
          }
        }
        if ( v20 < 9 )
        {
          memset((char *)&s[1] - v20, 0, v20);
          printk(&unk_22116A, "_sde_plane_set_src_rect_extn");
          goto LABEL_121;
        }
        goto LABEL_150;
      }
      if ( v10 != 47 )
        goto LABEL_122;
      s[0] = 0;
      if ( !a4 )
      {
        *(_QWORD *)(a2 + 2936) = 0;
        goto LABEL_121;
      }
      v39 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v39 + 70) & 0x20) != 0 || (v40 = a4, (*(_QWORD *)v39 & 0x4000000) != 0) )
        v40 = a4 & ((__int64)(a4 << 8) >> 8);
      if ( v40 > 0x7FFFFFFFF8LL )
      {
        v20 = 8;
      }
      else
      {
        v41 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v43 = *(_QWORD *)(v39 + 8);
        _WriteStatusReg(TTBR1_EL1, v43 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v43);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v41);
        v20 = _arch_copy_from_user(s, a4 & 0xFF7FFFFFFFFFFFFFLL, 8);
        v44 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v46 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v46 - 4096);
        _WriteStatusReg(TTBR1_EL1, v46);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v44);
        if ( !v20 )
        {
          v47 = WORD1(s[0]);
          v48 = HIWORD(s[0]);
          v49 = _drm_debug;
          v50 = WORD2(s[0]) - LOWORD(s[0]);
          *(_WORD *)(a2 + 2936) = s[0];
          *(_WORD *)(a2 + 2938) = v47;
          *(_WORD *)(a2 + 2940) = v50;
          *(_WORD *)(a2 + 2942) = v48 - v47;
          if ( (v49 & 4) == 0 )
            goto LABEL_121;
          v51 = *(unsigned int *)(a1 + 104);
          v52 = "plane%d dst rect extn dimensions: {%d,%d,%d,%d}\n";
LABEL_88:
          _drm_dev_dbg(0, 0, 0, v52, v51);
          goto LABEL_121;
        }
      }
      if ( v20 < 9 )
      {
        memset((char *)&s[1] - v20, 0, v20);
        printk(&unk_25765C, "_sde_plane_set_dst_rect_extn");
        goto LABEL_121;
      }
      goto LABEL_150;
    }
    if ( v10 == 30 )
    {
      memset(s, 0, 256);
      *(_DWORD *)(a2 + 2692) = 0;
      if ( !a4 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "plane%d scale data removed\n", *(unsigned int *)(a1 + 104));
        goto LABEL_121;
      }
      v130 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v130 + 70) & 0x20) != 0 || (v131 = a4, (*(_QWORD *)v130 & 0x4000000) != 0) )
        v131 = a4 & ((__int64)(a4 << 8) >> 8);
      if ( v131 > 0x7FFFFFFF00LL )
      {
        v20 = 256;
      }
      else
      {
        v132 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v134 = *(_QWORD *)(v130 + 8);
        _WriteStatusReg(TTBR1_EL1, v134 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v134);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v132);
        v20 = _arch_copy_from_user(s, a4 & 0xFF7FFFFFFFFFFFFFLL, 256);
        v135 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v137 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v137 - 4096);
        _WriteStatusReg(TTBR1_EL1, v137);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v135);
        if ( !v20 )
        {
          msm_property_set_dirty(a1 + 3344, a2 + 176, 30);
          v138 = s[20];
          v139 = s[21];
          *(_QWORD *)(a2 + 2368) = 0;
          *(_QWORD *)(a2 + 2376) = 0;
          *(_QWORD *)(a2 + 2384) = 0;
          *(_QWORD *)(a2 + 2392) = 0;
          *(_QWORD *)(a2 + 2400) = 0;
          *(_QWORD *)(a2 + 2408) = 0;
          *(_QWORD *)(a2 + 2416) = 0;
          *(_QWORD *)(a2 + 2424) = 0;
          *(_QWORD *)(a2 + 2432) = 0;
          *(_QWORD *)(a2 + 2440) = 0;
          *(_QWORD *)(a2 + 2448) = 0;
          *(_QWORD *)(a2 + 2456) = 0;
          *(_QWORD *)(a2 + 2464) = 0;
          *(_QWORD *)(a2 + 2472) = 0;
          *(_QWORD *)(a2 + 2480) = 0;
          *(_QWORD *)(a2 + 2488) = 0;
          *(_DWORD *)(a2 + 2496) = 0;
          *(_QWORD *)(a2 + 2372) = v138;
          *(_QWORD *)(a2 + 2380) = v139;
          v140 = s[23];
          *(_QWORD *)(a2 + 2388) = s[22];
          *(_QWORD *)(a2 + 2396) = v140;
          v141 = s[25];
          *(_QWORD *)(a2 + 2404) = s[24];
          *(_QWORD *)(a2 + 2412) = v141;
          v142 = s[27];
          *(_QWORD *)(a2 + 2420) = s[26];
          *(_QWORD *)(a2 + 2428) = v142;
          v143 = s[29];
          *(_QWORD *)(a2 + 2660) = s[28];
          *(_QWORD *)(a2 + 2668) = v143;
          v144 = s[31];
          *(_QWORD *)(a2 + 2676) = s[30];
          *(_QWORD *)(a2 + 2684) = v144;
          v145 = s[5];
          *(_QWORD *)(a2 + 2500) = s[4];
          *(_QWORD *)(a2 + 2508) = v145;
          v146 = s[7];
          *(_QWORD *)(a2 + 2516) = s[6];
          *(_QWORD *)(a2 + 2524) = v146;
          v147 = s[9];
          *(_QWORD *)(a2 + 2532) = s[8];
          *(_QWORD *)(a2 + 2540) = v147;
          v148 = s[11];
          *(_QWORD *)(a2 + 2548) = s[10];
          *(_QWORD *)(a2 + 2556) = v148;
          LODWORD(v147) = HIDWORD(s[12]);
          LODWORD(v146) = s[14];
          LODWORD(v148) = HIDWORD(s[14]);
          *(_DWORD *)(a2 + 2564) = s[12];
          LODWORD(v139) = s[0];
          v149 = HIDWORD(s[0]);
          *(_DWORD *)(a2 + 2580) = v146;
          LODWORD(v146) = s[16];
          v150 = HIDWORD(s[16]);
          *(_DWORD *)(a2 + 2628) = v139;
          LODWORD(v139) = s[18];
          v151 = HIDWORD(s[18]);
          *(_DWORD *)(a2 + 2596) = v146;
          *(_DWORD *)(a2 + 2568) = v147;
          *(_DWORD *)(a2 + 2612) = v139;
          LODWORD(v146) = s[2];
          LODWORD(v139) = HIDWORD(s[2]);
          *(_DWORD *)(a2 + 2584) = v148;
          *(_DWORD *)(a2 + 2632) = v149;
          *(_DWORD *)(a2 + 2644) = v146;
          *(_DWORD *)(a2 + 2648) = v139;
          LODWORD(v146) = s[13];
          LODWORD(v139) = HIDWORD(s[13]);
          LODWORD(v147) = s[15];
          LODWORD(v148) = HIDWORD(s[15]);
          *(_DWORD *)(a2 + 2600) = v150;
          *(_DWORD *)(a2 + 2572) = v146;
          LODWORD(v146) = s[1];
          v152 = HIDWORD(s[1]);
          *(_DWORD *)(a2 + 2616) = v151;
          *(_DWORD *)(a2 + 2588) = v147;
          LODWORD(v147) = s[17];
          v153 = HIDWORD(s[17]);
          *(_DWORD *)(a2 + 2636) = v146;
          LODWORD(v146) = s[19];
          v154 = HIDWORD(s[19]);
          *(_DWORD *)(a2 + 2604) = v147;
          *(_DWORD *)(a2 + 2576) = v139;
          *(_DWORD *)(a2 + 2620) = v146;
          LODWORD(v147) = s[3];
          LODWORD(v146) = HIDWORD(s[3]);
          *(_DWORD *)(a2 + 2592) = v148;
          *(_DWORD *)(a2 + 2640) = v152;
          *(_DWORD *)(a2 + 2652) = v147;
          *(_DWORD *)(a2 + 2608) = v153;
          *(_DWORD *)(a2 + 2624) = v154;
          *(_DWORD *)(a2 + 2656) = v146;
          *(_DWORD *)(a2 + 2692) = 2;
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_plane_set_scaler_v1",
            4932,
            4,
            *(_DWORD *)(a1 + 104),
            -1059143953,
            v155,
            v156,
            v196);
          goto LABEL_104;
        }
      }
      if ( v20 < 0x101 )
      {
        memset((char *)&s[32] - v20, 0, v20);
        printk(&unk_212AE3, "_sde_plane_set_scaler_v1");
        goto LABEL_121;
      }
      goto LABEL_150;
    }
    if ( v10 != 31 )
      goto LABEL_122;
    memset(s, 0, 0x2BCu);
    *(_DWORD *)(a2 + 2692) = 0;
    if ( !a4 )
      goto LABEL_100;
    v65 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v65 + 70) & 0x20) != 0 || (v66 = a4, (*(_QWORD *)v65 & 0x4000000) != 0) )
      v66 = a4 & ((__int64)(a4 << 8) >> 8);
    if ( v66 > 0x7FFFFFFD44LL )
    {
      v20 = 700;
    }
    else
    {
      v67 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v69 = *(_QWORD *)(v65 + 8);
      _WriteStatusReg(TTBR1_EL1, v69 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v69);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v67);
      v20 = _arch_copy_from_user(s, a4 & 0xFF7FFFFFFFFFFFFFLL, 700);
      v70 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v72 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v72 - 4096);
      _WriteStatusReg(TTBR1_EL1, v72);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v70);
      if ( !v20 )
      {
        if ( LODWORD(s[0]) )
        {
          sde_set_scaler_v2(a2 + 1800, s);
          if ( (*(_BYTE *)(a1 + 1939) & 2) != 0 )
          {
            v73 = HIDWORD(s[52]);
            v74 = *(_QWORD *)((char *)&s[51] + 4);
            *(_DWORD *)(a2 + 2696) = s[51];
            *(_QWORD *)(a2 + 2700) = v74;
            *(_DWORD *)(a2 + 2708) = v73;
          }
          memset((void *)(a2 + 2368), 0, 0x144u);
          v76 = s[6];
          v77 = s[56];
          *(_QWORD *)(a2 + 2500) = s[5];
          *(_QWORD *)(a2 + 2508) = v76;
          v78 = s[7];
          v79 = s[8];
          v80 = s[9];
          v81 = s[10];
          *(_DWORD *)(a2 + 2108) = v77;
          *(_QWORD *)(a2 + 2516) = v78;
          *(_QWORD *)(a2 + 2524) = v79;
          *(_QWORD *)(a2 + 2532) = v80;
          *(_QWORD *)(a2 + 2540) = v81;
          v82 = s[12];
          *(_QWORD *)(a2 + 2548) = s[11];
          *(_QWORD *)(a2 + 2556) = v82;
          LODWORD(v80) = HIDWORD(s[13]);
          LODWORD(v78) = s[15];
          LODWORD(v82) = HIDWORD(s[15]);
          *(_DWORD *)(a2 + 2564) = s[13];
          LODWORD(v81) = s[1];
          LODWORD(v79) = HIDWORD(s[1]);
          *(_DWORD *)(a2 + 2580) = v78;
          LODWORD(v78) = s[17];
          v83 = HIDWORD(s[17]);
          *(_DWORD *)(a2 + 2628) = v81;
          LODWORD(v81) = s[19];
          v84 = HIDWORD(s[19]);
          *(_DWORD *)(a2 + 2596) = v78;
          *(_DWORD *)(a2 + 2568) = v80;
          *(_DWORD *)(a2 + 2612) = v81;
          LODWORD(v78) = s[3];
          LODWORD(v81) = HIDWORD(s[3]);
          *(_DWORD *)(a2 + 2584) = v82;
          *(_DWORD *)(a2 + 2632) = v79;
          *(_DWORD *)(a2 + 2644) = v78;
          *(_DWORD *)(a2 + 2648) = v81;
          LODWORD(v78) = s[14];
          LODWORD(v81) = HIDWORD(s[14]);
          LODWORD(v80) = s[16];
          LODWORD(v82) = HIDWORD(s[16]);
          *(_DWORD *)(a2 + 2600) = v83;
          *(_DWORD *)(a2 + 2572) = v78;
          LODWORD(v78) = s[2];
          LODWORD(v79) = HIDWORD(s[2]);
          *(_DWORD *)(a2 + 2616) = v84;
          *(_DWORD *)(a2 + 2588) = v80;
          LODWORD(v80) = s[18];
          v85 = HIDWORD(s[18]);
          *(_DWORD *)(a2 + 2636) = v78;
          LODWORD(v78) = s[20];
          v86 = HIDWORD(s[20]);
          *(_DWORD *)(a2 + 2604) = v80;
          *(_DWORD *)(a2 + 2576) = v81;
          *(_DWORD *)(a2 + 2620) = v78;
          LODWORD(v80) = s[4];
          LODWORD(v78) = HIDWORD(s[4]);
          *(_DWORD *)(a2 + 2592) = v82;
          *(_DWORD *)(a2 + 2640) = v79;
          *(_DWORD *)(a2 + 2652) = v80;
          *(_DWORD *)(a2 + 2692) = 5;
          LODWORD(v80) = s[81];
          *(_DWORD *)(a2 + 2656) = v78;
          *(_QWORD *)(a2 + 2316) = 0;
          *(_QWORD *)(a2 + 2324) = 0;
          *(_QWORD *)(a2 + 2300) = 0;
          *(_QWORD *)(a2 + 2308) = 0;
          *(_QWORD *)(a2 + 2284) = 0;
          *(_QWORD *)(a2 + 2292) = 0;
          *(_QWORD *)(a2 + 2268) = 0;
          *(_QWORD *)(a2 + 2276) = 0;
          *(_QWORD *)(a2 + 2252) = 0;
          *(_QWORD *)(a2 + 2260) = 0;
          *(_QWORD *)(a2 + 2236) = 0;
          *(_QWORD *)(a2 + 2244) = 0;
          *(_QWORD *)(a2 + 2220) = 0;
          *(_QWORD *)(a2 + 2228) = 0;
          *(_QWORD *)(a2 + 2204) = 0;
          *(_QWORD *)(a2 + 2212) = 0;
          *(_QWORD *)(a2 + 2188) = 0;
          *(_QWORD *)(a2 + 2196) = 0;
          *(_QWORD *)(a2 + 2172) = 0;
          *(_QWORD *)(a2 + 2180) = 0;
          *(_QWORD *)(a2 + 2156) = 0;
          *(_QWORD *)(a2 + 2164) = 0;
          *(_QWORD *)(a2 + 2140) = 0;
          *(_QWORD *)(a2 + 2148) = 0;
          *(_QWORD *)(a2 + 2124) = 0;
          *(_QWORD *)(a2 + 2132) = 0;
          *(_QWORD *)(a2 + 2116) = 0;
          *(_DWORD *)(a2 + 2608) = v85;
          *(_DWORD *)(a2 + 2624) = v86;
          *(_DWORD *)(a2 + 2112) = v80;
          if ( v77 | (unsigned int)v80 )
          {
            v87 = HIDWORD(s[58]);
            *(_DWORD *)(a2 + 2120) = HIDWORD(s[56]);
            v88 = HIDWORD(s[60]);
            *(_DWORD *)(a2 + 2136) = v87;
            v89 = HIDWORD(s[62]);
            *(_DWORD *)(a2 + 2152) = v88;
            v90 = HIDWORD(s[64]);
            *(_DWORD *)(a2 + 2168) = v89;
            v91 = HIDWORD(s[66]);
            *(_DWORD *)(a2 + 2184) = v90;
            v92 = HIDWORD(s[68]);
            *(_DWORD *)(a2 + 2200) = v91;
            v93 = HIDWORD(s[70]);
            *(_DWORD *)(a2 + 2216) = v92;
            LOWORD(v92) = s[75];
            *(_DWORD *)(a2 + 2232) = v93;
            LOWORD(v93) = s[76];
            *(_WORD *)(a2 + 2284) = v92;
            LOWORD(v92) = s[77];
            *(_WORD *)(a2 + 2292) = v93;
            LOWORD(v93) = s[78];
            *(_WORD *)(a2 + 2300) = v92;
            LOWORD(v92) = s[79];
            *(_WORD *)(a2 + 2308) = v93;
            LOWORD(v93) = s[80];
            *(_WORD *)(a2 + 2316) = v92;
            v94 = s[57];
            *(_WORD *)(a2 + 2324) = v93;
            v95 = s[59];
            *(_DWORD *)(a2 + 2124) = v94;
            v96 = s[61];
            *(_DWORD *)(a2 + 2140) = v95;
            v97 = s[63];
            *(_DWORD *)(a2 + 2156) = v96;
            v98 = s[65];
            *(_DWORD *)(a2 + 2172) = v97;
            v99 = s[67];
            *(_DWORD *)(a2 + 2188) = v98;
            v100 = s[69];
            *(_DWORD *)(a2 + 2204) = v99;
            v101 = s[71];
            *(_DWORD *)(a2 + 2220) = v100;
            LOWORD(v100) = WORD1(s[75]);
            *(_DWORD *)(a2 + 2236) = v101;
            LOWORD(v101) = WORD1(s[76]);
            *(_WORD *)(a2 + 2286) = v100;
            LOWORD(v100) = WORD1(s[77]);
            *(_WORD *)(a2 + 2294) = v101;
            LOWORD(v101) = WORD1(s[78]);
            *(_WORD *)(a2 + 2302) = v100;
            LOWORD(v100) = WORD1(s[79]);
            *(_WORD *)(a2 + 2310) = v101;
            LOWORD(v101) = WORD1(s[80]);
            *(_WORD *)(a2 + 2318) = v100;
            v102 = HIDWORD(s[57]);
            *(_WORD *)(a2 + 2326) = v101;
            v103 = HIDWORD(s[59]);
            *(_DWORD *)(a2 + 2128) = v102;
            v104 = HIDWORD(s[61]);
            *(_DWORD *)(a2 + 2144) = v103;
            v105 = HIDWORD(s[63]);
            *(_DWORD *)(a2 + 2160) = v104;
            v106 = HIDWORD(s[65]);
            *(_DWORD *)(a2 + 2176) = v105;
            v107 = HIDWORD(s[67]);
            *(_DWORD *)(a2 + 2192) = v106;
            v108 = HIDWORD(s[69]);
            *(_DWORD *)(a2 + 2208) = v107;
            v109 = HIDWORD(s[71]);
            *(_DWORD *)(a2 + 2224) = v108;
            LOWORD(v108) = WORD2(s[75]);
            *(_DWORD *)(a2 + 2240) = v109;
            LOWORD(v109) = WORD2(s[76]);
            *(_WORD *)(a2 + 2288) = v108;
            LOWORD(v108) = WORD2(s[77]);
            *(_WORD *)(a2 + 2296) = v109;
            LOWORD(v109) = WORD2(s[78]);
            *(_WORD *)(a2 + 2304) = v108;
            LOWORD(v108) = WORD2(s[79]);
            *(_WORD *)(a2 + 2312) = v109;
            LOWORD(v109) = WORD2(s[80]);
            *(_WORD *)(a2 + 2320) = v108;
            v110 = s[58];
            *(_WORD *)(a2 + 2328) = v109;
            v111 = s[60];
            *(_DWORD *)(a2 + 2132) = v110;
            v112 = s[62];
            *(_DWORD *)(a2 + 2148) = v111;
            v113 = s[64];
            *(_DWORD *)(a2 + 2164) = v112;
            v114 = s[66];
            *(_DWORD *)(a2 + 2180) = v113;
            v115 = s[68];
            *(_DWORD *)(a2 + 2196) = v114;
            v116 = s[70];
            *(_DWORD *)(a2 + 2212) = v115;
            v117 = s[72];
            *(_DWORD *)(a2 + 2228) = v116;
            LOWORD(v116) = HIWORD(s[75]);
            *(_DWORD *)(a2 + 2244) = v117;
            LOWORD(v117) = HIWORD(s[76]);
            *(_WORD *)(a2 + 2290) = v116;
            LOWORD(v116) = HIWORD(s[77]);
            *(_WORD *)(a2 + 2298) = v117;
            LOWORD(v117) = HIWORD(s[78]);
            *(_WORD *)(a2 + 2306) = v116;
            LOWORD(v116) = HIWORD(s[79]);
            *(_WORD *)(a2 + 2314) = v117;
            LOWORD(v117) = HIWORD(s[80]);
            *(_WORD *)(a2 + 2322) = v116;
            v118 = HIDWORD(s[72]);
            *(_WORD *)(a2 + 2330) = v117;
            v119 = s[73];
            *(_DWORD *)(a2 + 2248) = v118;
            v120 = HIDWORD(s[73]);
            v121 = sde_dbg_base_evtlog;
            *(_DWORD *)(a2 + 2252) = v119;
            v122 = s[74];
            *(_DWORD *)(a2 + 2256) = v120;
            v123 = HIDWORD(s[74]);
            *(_DWORD *)(a2 + 2260) = v122;
            v124 = HIDWORD(s[39]);
            *(_DWORD *)(a2 + 2264) = v123;
            v125 = HIDWORD(s[81]);
            *(_DWORD *)(a2 + 2116) = v124;
            v126 = s[82];
            *(_DWORD *)(a2 + 2268) = v125;
            v127 = HIDWORD(s[82]);
            *(_DWORD *)(a2 + 2272) = v126;
            v128 = s[83];
            *(_DWORD *)(a2 + 2276) = v127;
            *(_DWORD *)(a2 + 2280) = v128;
            sde_evtlog_log(v121, "sde_set_cac_cfg", 4999, 4, *(_DWORD *)(a1 + 104), v77, -1059143953, v75, v196);
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "plane%d copied cac scalar properties\n", *(_DWORD *)(a1 + 104));
          }
LABEL_103:
          msm_property_set_dirty(a1 + 3344, a2 + 176, 31);
          sde_evtlog_log(
            sde_dbg_base_evtlog,
            "_sde_plane_set_scaler_v2",
            5079,
            4,
            *(_DWORD *)(a1 + 104),
            *(_DWORD *)(a2 + 1800),
            *(_DWORD *)(a2 + 2040),
            *(_DWORD *)(a2 + 1912),
            *(_DWORD *)(a2 + 1928));
LABEL_104:
          if ( (_drm_debug & 4) != 0 )
            _drm_dev_dbg(0, 0, 0, "plane%d user property data copied\n", *(unsigned int *)(a1 + 104));
          goto LABEL_121;
        }
LABEL_100:
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "plane%d scale data removed\n", *(_DWORD *)(a1 + 104));
        *(_DWORD *)(a2 + 1800) = 0;
        *(_QWORD *)(a2 + 2696) = 0;
        *(_QWORD *)(a2 + 2704) = 0;
        goto LABEL_103;
      }
    }
    if ( v20 < 0x2BD )
    {
      memset((char *)&s[87] - v20 + 4, 0, v20);
      printk(&unk_212AE3, "_sde_plane_set_scaler_v2");
      goto LABEL_121;
    }
    goto LABEL_150;
  }
  if ( v10 > 14 )
  {
    if ( v10 != 15 )
    {
      if ( v10 == 22 )
      {
        if ( *(_QWORD *)(a2 + 1752) )
          sde_sync_put();
        if ( a4 )
          v169 = sde_sync_get(a4);
        else
          v169 = 0;
        v193 = _drm_debug;
        *(_QWORD *)(a2 + 1752) = v169;
        if ( (v193 & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "plane%d 0x%llX\n", *(_DWORD *)(a1 + 104), a4);
        goto LABEL_121;
      }
      if ( v10 != 27 )
        goto LABEL_122;
      s[0] = 0;
      if ( !a4 )
      {
        *(_QWORD *)(a2 + 1764) = 0;
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "plane%d excl_rect data cleared\n", *(unsigned int *)(a1 + 104));
        goto LABEL_121;
      }
      v53 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v53 + 70) & 0x20) != 0 || (v54 = a4, (*(_QWORD *)v53 & 0x4000000) != 0) )
        v54 = a4 & ((__int64)(a4 << 8) >> 8);
      if ( v54 > 0x7FFFFFFFF8LL )
      {
        v20 = 8;
      }
      else
      {
        v55 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v57 = *(_QWORD *)(v53 + 8);
        _WriteStatusReg(TTBR1_EL1, v57 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v57);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v55);
        v20 = _arch_copy_from_user(s, a4 & 0xFF7FFFFFFFFFFFFFLL, 8);
        v58 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v60 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v60 - 4096);
        _WriteStatusReg(TTBR1_EL1, v60);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v58);
        if ( !v20 )
        {
          v61 = WORD1(s[0]);
          v62 = HIWORD(s[0]);
          v63 = _drm_debug;
          v64 = WORD2(s[0]) - LOWORD(s[0]);
          *(_WORD *)(a2 + 1764) = s[0];
          *(_WORD *)(a2 + 1766) = v61;
          *(_WORD *)(a2 + 1768) = v64;
          *(_WORD *)(a2 + 1770) = v62 - v61;
          if ( (v63 & 4) == 0 )
            goto LABEL_121;
          v51 = *(unsigned int *)(a1 + 104);
          v52 = "plane%d excl_rect: {%d,%d,%d,%d}\n";
          goto LABEL_88;
        }
      }
      if ( v20 < 9 )
      {
        memset((char *)&s[1] - v20, 0, v20);
        printk(&unk_212B1F, "_sde_plane_set_excl_rect_v1");
        goto LABEL_121;
      }
      goto LABEL_150;
    }
    LODWORD(s[0]) = 0;
    if ( a4 )
    {
      v182 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v182 + 70) & 0x20) != 0 || (v183 = a4, (*(_QWORD *)v182 & 0x4000000) != 0) )
        v183 = a4 & ((__int64)(a4 << 8) >> 8);
      if ( v183 > 0x7FFFFFFFFCLL )
      {
        v20 = 4;
      }
      else
      {
        v184 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v186 = *(_QWORD *)(v182 + 8);
        _WriteStatusReg(TTBR1_EL1, v186 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v186);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v184);
        v20 = _arch_copy_from_user(s, a4 & 0xFF7FFFFFFFFFFFFFLL, 4);
        v187 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v189 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v189 - 4096);
        _WriteStatusReg(TTBR1_EL1, v189);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v187);
        if ( !v20 )
        {
          v190 = LOWORD(s[0]);
          v191 = *(unsigned __int16 *)(a1 + 2294);
          v192 = WORD1(s[0]);
          if ( LOWORD(s[0]) > v191 || WORD1(s[0]) > v191 )
          {
            printk(&unk_219E6E, "_sde_plane_set_ubwc_stats_roi");
            v192 = 0;
            v190 = 0;
            LODWORD(s[0]) = 0;
          }
          goto LABEL_120;
        }
      }
      if ( v20 < 5 )
      {
        memset((char *)s - v20 + 4, 0, v20);
        printk(&unk_21DE05, "_sde_plane_set_ubwc_stats_roi");
        goto LABEL_121;
      }
      goto LABEL_150;
    }
    if ( (_drm_debug & 4) != 0 )
    {
      _drm_dev_dbg(0, 0, 0, "plane%d ubwc roi disabled", *(_DWORD *)(a1 + 104));
      v190 = LOWORD(s[0]);
      v192 = WORD1(s[0]);
    }
    else
    {
      v192 = 0;
      v190 = 0;
    }
LABEL_120:
    sde_evtlog_log(sde_dbg_base_evtlog, "_sde_plane_set_ubwc_stats_roi", 5232, -1, a1, v190, v192, -1059143953, v196);
    *(_DWORD *)(a2 + 2762) = s[0];
    goto LABEL_121;
  }
  if ( (unsigned int)v10 >= 2 )
  {
    if ( v10 != 9 )
      goto LABEL_122;
    cp_feature_set_curr_mode(0, a1 + 4496, a4);
LABEL_121:
    v9 = 0;
LABEL_122:
    if ( (_drm_debug & 4) != 0 )
    {
      v129 = *(_DWORD *)(a1 + 104);
      goto LABEL_124;
    }
    goto LABEL_125;
  }
  memset(s, 0, 144);
  *(_QWORD *)(a2 + 2904) = 0;
  if ( !a4 )
  {
    if ( (_drm_debug & 4) != 0 )
      _drm_dev_dbg(0, 0, 0, "plane%d csc data removed\n", *(unsigned int *)(a1 + 104));
    goto LABEL_121;
  }
  v11 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v11 + 70) & 0x20) != 0 || (v12 = a4, (*(_QWORD *)v11 & 0x4000000) != 0) )
    v12 = a4 & ((__int64)(a4 << 8) >> 8);
  if ( v12 > 0x7FFFFFFF70LL )
  {
    v20 = 144;
  }
  else
  {
    v13 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v19 = *(_QWORD *)(v11 + 8);
    _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v19);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v13);
    v20 = _arch_copy_from_user(s, a4 & 0xFF7FFFFFFFFFFFFFLL, 144);
    v21 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v23 - 4096);
    _WriteStatusReg(TTBR1_EL1, v23);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v21);
    if ( !v20 )
    {
      v24 = s[1] >> 16;
      v25 = s[3] >> 16;
      v26 = s[2] >> 16;
      *(_DWORD *)(a2 + 2792) = s[0] >> 16;
      v27 = s[4];
      v28 = s[5];
      *(_DWORD *)(a2 + 2796) = v24;
      *(_DWORD *)(a2 + 2804) = v25;
      v29 = s[6];
      v30 = s[7];
      *(_DWORD *)(a2 + 2800) = v26;
      v31 = v28 >> 16;
      v32 = *(_QWORD *)((char *)&s[10] + 4);
      *(_DWORD *)(a2 + 2808) = v27 >> 16;
      *(_DWORD *)(a2 + 2812) = v31;
      *(_DWORD *)(a2 + 2816) = v29 >> 16;
      v34 = s[8];
      v33 = s[9];
      *(_DWORD *)(a2 + 2820) = v30 >> 16;
      LODWORD(v31) = s[10];
      *(_QWORD *)(a2 + 2840) = v32;
      *(_DWORD *)(a2 + 2836) = v31;
      LODWORD(v31) = HIDWORD(s[11]);
      *(_DWORD *)(a2 + 2824) = v34 >> 16;
      *(_QWORD *)(a2 + 2828) = v33;
      *(_DWORD *)(a2 + 2848) = v31;
      v35 = s[14];
      *(_QWORD *)(a2 + 2860) = s[13];
      *(_QWORD *)(a2 + 2868) = v35;
      v37 = s[15];
      v36 = s[16];
      *(_QWORD *)(a2 + 2852) = s[12];
      v38 = s[17];
      *(_QWORD *)(a2 + 2884) = v36;
      *(_QWORD *)(a2 + 2892) = v38;
      *(_QWORD *)(a2 + 2876) = v37;
      *(_QWORD *)(a2 + 2904) = a2 + 2792;
      goto LABEL_121;
    }
  }
  if ( v20 < 0x91 )
  {
    memset((char *)&s[18] - v20, 0, v20);
    printk(&unk_24662C, "_sde_plane_set_csc_v1");
    goto LABEL_121;
  }
LABEL_150:
  v195 = _fortify_panic(15, 0, v20);
  return sde_plane_destroy_fb(v195);
}
