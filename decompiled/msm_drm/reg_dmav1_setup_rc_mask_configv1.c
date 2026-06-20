__int64 __fastcall reg_dmav1_setup_rc_mask_configv1(__int64 a1, __int64 *a2)
{
  __int64 *v2; // x20
  const void *v3; // x1
  __int64 v4; // x2
  __int64 v5; // x19
  unsigned int v6; // w4
  unsigned __int64 ops; // x21
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x9
  unsigned __int64 *v11; // x8
  void (__fastcall *v12)(_QWORD); // x9
  unsigned __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x9
  __int64 (__fastcall *v16)(_QWORD); // x8
  unsigned int v17; // w0
  int v18; // w7
  __int64 v19; // x8
  int v20; // w9
  __int64 v21; // x8
  __int64 v22; // x9
  __int64 v23; // x10
  int v24; // w8
  int v25; // w10
  __int64 v26; // x11
  __int64 (__fastcall *v27)(_QWORD); // x9
  unsigned int v28; // w0
  _QWORD *v29; // x8
  __int64 v30; // x4
  __int64 v31; // x8
  __int64 v32; // x5
  __int64 v33; // x6
  __int64 v34; // x9
  unsigned __int64 v35; // x11
  unsigned int v36; // w10
  unsigned int v37; // w8
  _DWORD *v38; // x8
  unsigned int ajusted_roi; // w0
  __int64 v40; // x22
  unsigned int *v41; // x23
  int v42; // w4
  int v43; // w23
  void *v44; // x0
  void *v45; // x0
  __int64 v46; // x1
  unsigned int param_rb; // w0
  int v48; // w24
  int v49; // w24
  int v50; // w23
  __int64 v51; // x9
  int v52; // w8
  __int64 v53; // x10
  __int64 v54; // x9
  int v55; // w10
  __int64 v56; // x11
  __int64 (__fastcall *v57)(_QWORD); // x9
  unsigned int v58; // w0
  __int64 v59; // x8
  __int64 v60; // x9
  __int64 v61; // x10
  int v62; // w8
  int v63; // w10
  __int64 v64; // x11
  __int64 (__fastcall *v65)(_QWORD); // x9
  unsigned int v66; // w0
  __int64 v67; // x8
  __int64 v68; // x9
  __int64 v69; // x10
  int v70; // w8
  int v71; // w10
  __int64 v72; // x11
  __int64 (__fastcall *v73)(_QWORD); // x9
  int v74; // w9
  int v75; // w8
  int v76; // w9
  int v77; // w26
  int v78; // w24
  int v79; // w23
  __int64 v80; // x8
  __int64 v81; // x9
  __int64 v82; // x10
  int v83; // w8
  int v84; // w10
  __int64 v85; // x11
  __int64 (__fastcall *v86)(_QWORD); // x9
  unsigned int v87; // w0
  __int64 v88; // x8
  __int64 v89; // x9
  __int64 v90; // x10
  int v91; // w8
  int v92; // w10
  __int64 v93; // x11
  __int64 (__fastcall *v94)(_QWORD); // x9
  unsigned int v95; // w0
  __int64 v96; // x8
  __int64 v97; // x9
  __int64 v98; // x10
  int v99; // w8
  int v100; // w10
  __int64 v101; // x11
  __int64 (__fastcall *v102)(_QWORD); // x9
  unsigned int v103; // w0
  __int64 v104; // x8
  __int64 v105; // x9
  __int64 v106; // x10
  int v107; // w8
  int v108; // w10
  __int64 v109; // x11
  __int64 (__fastcall *v110)(_QWORD); // x9
  unsigned int v111; // w0
  int v112; // w6
  int v113; // w7
  __int64 v114; // x8
  int v115; // w8
  __int64 v116; // x9
  int v117; // w8
  __int64 v118; // x4
  __int64 v119; // x5
  __int64 v120; // x6
  __int64 v121; // x9
  unsigned int v122; // w11
  int v123; // w11
  _DWORD *v124; // x8
  unsigned int v125; // w0
  _DWORD *v126; // x23
  unsigned int v127; // w19
  __int64 v128; // x1
  void *v129; // x0
  int v130; // w26
  int v131; // w27
  unsigned __int64 v132; // x24
  __int64 v133; // x0
  __int64 v134; // x27
  unsigned __int64 v135; // x26
  __int64 v136; // x23
  __int64 v137; // x28
  unsigned __int64 v138; // x25
  __int64 v139; // x10
  _DWORD *v140; // x11
  unsigned __int64 v141; // x26
  __int64 v142; // x21
  unsigned __int64 v143; // x22
  __int64 v144; // x24
  __int64 v145; // x27
  __int64 *v146; // x19
  _DWORD *v147; // x20
  _DWORD *v148; // x9
  unsigned __int64 v149; // x9
  __int64 (__fastcall *v150)(_QWORD); // x9
  int v151; // w6
  int v152; // w7
  __int64 v153; // x4
  __int64 v154; // x8
  __int64 v155; // x5
  __int64 v156; // x6
  __int64 v157; // x9
  unsigned __int64 v158; // x11
  unsigned int v159; // w10
  unsigned int v160; // w8
  _DWORD *v161; // x8
  unsigned int v162; // w0
  void *v163; // x8
  void *v164; // x8
  void *v165; // x0
  void *v166; // x8
  unsigned int v167; // w19
  char v168; // [xsp+0h] [xbp-130h]
  char v169; // [xsp+0h] [xbp-130h]
  int v170; // [xsp+10h] [xbp-120h]
  int v171; // [xsp+14h] [xbp-11Ch]
  unsigned __int64 v172; // [xsp+18h] [xbp-118h]
  int v173; // [xsp+20h] [xbp-110h]
  _DWORD *v174; // [xsp+28h] [xbp-108h]
  __int64 v175; // [xsp+30h] [xbp-100h] BYREF
  __int64 v176; // [xsp+38h] [xbp-F8h] BYREF
  unsigned __int64 v177; // [xsp+40h] [xbp-F0h] BYREF
  __int128 v178; // [xsp+48h] [xbp-E8h]
  unsigned __int64 v179; // [xsp+58h] [xbp-D8h]
  _DWORD *v180; // [xsp+60h] [xbp-D0h]
  __int64 v181; // [xsp+68h] [xbp-C8h]
  __int64 v182; // [xsp+70h] [xbp-C0h]
  __int64 v183; // [xsp+78h] [xbp-B8h]
  __int64 v184; // [xsp+80h] [xbp-B0h] BYREF
  __int64 v185; // [xsp+88h] [xbp-A8h]
  unsigned __int64 v186; // [xsp+90h] [xbp-A0h]
  __int128 v187; // [xsp+98h] [xbp-98h]
  __int64 v188; // [xsp+A8h] [xbp-88h]
  __int64 v189; // [xsp+B0h] [xbp-80h]
  unsigned __int64 v190; // [xsp+B8h] [xbp-78h]
  unsigned __int64 v191; // [xsp+C0h] [xbp-70h]
  unsigned __int64 v192; // [xsp+C8h] [xbp-68h]
  __int64 v193; // [xsp+D0h] [xbp-60h] BYREF
  int v194; // [xsp+D8h] [xbp-58h] BYREF
  __int64 v195; // [xsp+DCh] [xbp-54h]
  __int64 v196; // [xsp+E4h] [xbp-4Ch]
  int v197; // [xsp+ECh] [xbp-44h]
  unsigned __int64 v198; // [xsp+F0h] [xbp-40h]
  int *v199; // [xsp+F8h] [xbp-38h]
  __int64 v200; // [xsp+100h] [xbp-30h]
  __int64 v201; // [xsp+108h] [xbp-28h]
  __int64 v202; // [xsp+110h] [xbp-20h]
  int v203; // [xsp+11Ch] [xbp-14h] BYREF
  __int64 v204; // [xsp+120h] [xbp-10h]

  v204 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v191 = 0;
  v192 = 0;
  v189 = 0;
  v190 = 0;
  v188 = 0;
  v186 = 0;
  v187 = 0u;
  v184 = 0;
  v185 = 0;
  v182 = 0;
  v183 = 0;
  v180 = nullptr;
  v181 = 0;
  v179 = 0;
  v177 = 0;
  v178 = 0u;
  v175 = 0;
  v176 = 0;
  if ( !a1 || (v2 = a2) == nullptr )
  {
    v44 = &unk_227DF6;
LABEL_143:
    printk(v44, a2);
    result = 4294967274LL;
    goto LABEL_189;
  }
  v3 = (const void *)a2[2];
  v4 = *(unsigned int *)(a1 + 64);
  v5 = a1;
  v6 = *(_DWORD *)(a1 + 1496);
  if ( !v3 || (unsigned int)v4 > 4 || v6 >= 2 )
  {
    _drm_err("invalid ctl %pK dspp idx %d feature %d dpu idx %d\n", v3, v4, 18, v6);
LABEL_61:
    v45 = &unk_246948;
LABEL_62:
    v46 = 4294967274LL;
LABEL_63:
    printk(v45, v46);
    result = 4294967274LL;
    goto LABEL_189;
  }
  if ( &dspp_buf[2 * v4] == (unsigned __int64 *)-1440LL )
  {
    _drm_err("invalid dma_buf\n");
    goto LABEL_61;
  }
  ops = sde_reg_dma_get_ops(v6);
  result = 4294967201LL;
  if ( ops && ops <= 0xFFFFFFFFFFFFF000LL )
  {
    v9 = *(unsigned int *)(v5 + 64);
    if ( (unsigned int)v9 >= 5 )
      goto LABEL_197;
    v10 = *(unsigned int *)(v5 + 1496);
    if ( (unsigned int)v10 > 1 )
      goto LABEL_197;
    if ( (unsigned __int64)(16 * v9 + 8 * v10 + 1440) > 0x7CF )
      goto LABEL_198;
    v11 = &dspp_buf[2 * v9 + v10];
    v12 = *(void (__fastcall **)(_QWORD))(ops + 64);
    v13 = v11[180];
    if ( *((_DWORD *)v12 - 1) != -870478129 )
      __break(0x8229u);
    v12(v13);
    v14 = *(unsigned int *)(v5 + 64);
    v177 = 0x8000000000000000LL;
    v179 = 0;
    v180 = nullptr;
    v181 = 0;
    v182 = 0;
    v183 = 0;
    v178 = 0x12u;
    if ( (unsigned int)v14 > 4 )
      goto LABEL_197;
    v15 = *(unsigned int *)(v5 + 1496);
    if ( (unsigned int)v15 > 1 )
      goto LABEL_197;
    if ( (unsigned __int64)(16 * v14 + 8 * v15 + 1440) > 0x7CF )
      goto LABEL_198;
    HIDWORD(v178) = 0;
    DWORD1(v178) = 0;
    v181 = 0;
    v179 = dspp_buf[2 * v14 + 180 + v15];
    v180 = nullptr;
    v16 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
    if ( *((_DWORD *)v16 - 1) != -1839634494 )
      __break(0x8228u);
    v17 = v16(&v177);
    if ( v17 )
    {
      v128 = v17;
      v129 = &unk_23C6E2;
      goto LABEL_145;
    }
    v19 = *((unsigned int *)v2 + 44);
    *((_DWORD *)v2 + 40) = v2[20] & 0xFF0F0FFF | 0x101000;
    if ( (unsigned int)v19 > 4 )
      goto LABEL_197;
    v20 = *((_DWORD *)v2 + 2);
    *((_DWORD *)v2 + 42) = hfi_dspp_idx_map[v19];
    if ( v20 != 21856 )
    {
      if ( !v20 && !*v2 )
      {
        if ( (_drm_debug & 4) != 0 )
          _drm_dev_dbg(0, 0, 0, "RC feature disabled\n");
        v21 = *(_QWORD *)(v5 + 72);
        v22 = *(unsigned int *)(v5 + 64);
        v203 = 0;
        v23 = *(_QWORD *)(v21 + 48);
        v24 = *(_DWORD *)(v5 + 8);
        v201 = 0;
        v202 = 0;
        v25 = *(_DWORD *)(v23 + 524);
        v195 = 0x1280000000LL;
        if ( (unsigned int)v22 < 5 )
        {
          v26 = *(unsigned int *)(v5 + 1496);
          if ( (unsigned int)v26 <= 1 )
          {
            if ( (unsigned __int64)(16 * v22 + 8 * v26 + 1440) > 0x7CF )
              goto LABEL_198;
            v196 = 0;
            v197 = v24 + v25 + 4;
            v198 = dspp_buf[2 * v22 + 180 + v26];
            v199 = &v203;
            v200 = 0x400000000LL;
            v27 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
            v194 = 1;
            if ( *((_DWORD *)v27 - 1) != -1839634494 )
              __break(0x8229u);
            v28 = v27(&v194);
            if ( v28 )
              printk(&unk_27AAB6, v28);
            memset(*(void **)(v5 + 1480), 0, 0x5560u);
            v29 = *(_QWORD **)(v5 + 1488);
            *v29 = 0;
            v29[1] = 0;
            v29[2] = 0;
            v29[3] = 0;
            v29[4] = 0;
            v29[5] = 0;
            v29[6] = 0;
            v29[7] = 0;
            v29[8] = 0;
            sde_evtlog_log(
              sde_dbg_base_evtlog,
              "reg_dmav1_setup_rc_mask_configv1",
              1794,
              -1,
              *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 72) + 48LL) + 536LL),
              *(_QWORD *)(v5 + 1480),
              *(_DWORD *)(*(_QWORD *)(v5 + 1480) + 16LL),
              **(_DWORD **)(v5 + 1488),
              239);
            v30 = *(unsigned int *)(v5 + 64);
            v31 = v2[2];
            v191 = 0;
            v192 = 0;
            v189 = 0;
            v190 = 0;
            v188 = 0;
            v186 = 0;
            v187 = 0u;
            v184 = v31;
            v185 = 0;
            if ( (unsigned int)v30 <= 4 )
            {
              v32 = *(unsigned int *)(v5 + 1496);
              if ( (unsigned int)v32 <= 1 )
              {
                if ( (unsigned __int64)(16 * v30 + 8 * v32 + 1440) > 0x7CF )
                  goto LABEL_198;
                LODWORD(v185) = 1;
                v33 = *(unsigned int *)(v5 + 28);
                *(_QWORD *)((char *)&v187 + 4) = 1;
                v34 = v2[19];
                v35 = v2[20];
                LODWORD(v188) = 18;
                v189 = v34;
                v190 = v35;
                LODWORD(v34) = *((_DWORD *)v2 + 43);
                v36 = *((_DWORD *)v2 + 44);
                v186 = dspp_buf[2 * v30 + 180 + v32];
                v37 = *((_DWORD *)v2 + 42);
                v192 = __PAIR64__(v36, v34);
                v191 = __PAIR64__(*((_DWORD *)v2 + 7), v37);
                if ( (unsigned int)v33 <= 2 )
                {
                  v38 = *(_DWORD **)(ops + 8 * v33 + 16);
                  if ( !v38 )
                  {
LABEL_42:
                    sde_evtlog_log(
                      sde_dbg_base_evtlog,
                      "reg_dmav1_setup_rc_mask_configv1",
                      1806,
                      -1,
                      v30,
                      v32,
                      v33,
                      0,
                      239);
                    result = 0;
                    goto LABEL_189;
                  }
                  if ( *(v38 - 1) != 1772228465 )
                    __break(0x8228u);
                  ajusted_roi = ((__int64 (__fastcall *)(__int64 *, _QWORD))v38)(&v184, (unsigned int)v32);
                  if ( !ajusted_roi )
                  {
                    LODWORD(v30) = *(_DWORD *)(v5 + 64);
                    LODWORD(v32) = *(_DWORD *)(v5 + 1496);
                    LODWORD(v33) = *(_DWORD *)(v5 + 28);
                    goto LABEL_42;
                  }
                  v163 = &unk_277957;
                  goto LABEL_186;
                }
              }
            }
          }
        }
        goto LABEL_197;
      }
      goto LABEL_142;
    }
    v40 = *v2;
    if ( !*v2 )
    {
LABEL_142:
      v44 = &unk_269767;
      goto LABEL_143;
    }
    if ( *(__int64 *)((char *)v2 + 92) != *(_QWORD *)(v40 + 21848) )
    {
      printk(&unk_269785, *(unsigned int *)(*(_QWORD *)(*(_QWORD *)(v5 + 72) + 48LL) + 536LL));
      sde_evtlog_log(
        sde_dbg_base_evtlog,
        "reg_dmav1_setup_rc_mask_configv1",
        1827,
        -1,
        1,
        -1059143953,
        v151,
        v152,
        v168);
      reg_dmav1_rc_write(v5, 4, 0, ops, 18);
      v153 = *(unsigned int *)(v5 + 64);
      v154 = v2[2];
      v191 = 0;
      v192 = 0;
      v189 = 0;
      v190 = 0;
      v188 = 0;
      v186 = 0;
      v187 = 0u;
      v184 = v154;
      v185 = 0;
      if ( (unsigned int)v153 > 4 )
        goto LABEL_197;
      v155 = *(unsigned int *)(v5 + 1496);
      if ( (unsigned int)v155 > 1 )
        goto LABEL_197;
      if ( (unsigned __int64)(16 * v153 + 8 * v155 + 1440) > 0x7CF )
        goto LABEL_198;
      LODWORD(v185) = 1;
      v156 = *(unsigned int *)(v5 + 28);
      *(_QWORD *)((char *)&v187 + 4) = 1;
      v157 = v2[19];
      v158 = v2[20];
      LODWORD(v188) = 18;
      v189 = v157;
      v190 = v158;
      LODWORD(v157) = *((_DWORD *)v2 + 43);
      v159 = *((_DWORD *)v2 + 44);
      v186 = dspp_buf[2 * v153 + 180 + v155];
      v160 = *((_DWORD *)v2 + 42);
      v192 = __PAIR64__(v159, v157);
      v191 = __PAIR64__(*((_DWORD *)v2 + 7), v160);
      if ( (unsigned int)v156 > 2 )
        goto LABEL_197;
      v161 = *(_DWORD **)(ops + 8 * v156 + 16);
      if ( v161 )
      {
        if ( *(v161 - 1) != 1772228465 )
          __break(0x8228u);
        v162 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v161)(&v184, (unsigned int)v155);
        if ( v162 )
        {
          v46 = v162;
          v45 = &unk_277957;
          goto LABEL_63;
        }
        LODWORD(v153) = *(_DWORD *)(v5 + 64);
        LODWORD(v155) = *(_DWORD *)(v5 + 1496);
        LODWORD(v156) = *(_DWORD *)(v5 + 28);
      }
      sde_evtlog_log(sde_dbg_base_evtlog, "reg_dmav1_setup_rc_mask_configv1", 1840, -1, v153, v155, v156, 0, 239);
      result = 4294967274LL;
      goto LABEL_189;
    }
    v41 = *(unsigned int **)(v5 + 1488);
    if ( v41 && *v41 )
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "partial frame update\n");
      sde_kms_rect_merge_rectangles(v41, (__int64)&v175);
    }
    else
    {
      if ( (_drm_debug & 4) != 0 )
        _drm_dev_dbg(0, 0, 0, "full frame update\n");
      v175 = 0;
    }
    sde_evtlog_log(
      sde_dbg_base_evtlog,
      "reg_dmav1_setup_rc_mask_configv1",
      1851,
      -1,
      *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 72) + 48LL) + 536LL),
      *v41,
      -1059143953,
      v18,
      v168);
    ajusted_roi = sde_hw_rc_get_ajusted_roi((int *)v2, (unsigned __int16 *)&v175, (unsigned __int16 *)&v176);
    if ( ajusted_roi )
    {
      v163 = &unk_21E2E0;
LABEL_186:
      v127 = ajusted_roi;
      v165 = v163;
      goto LABEL_187;
    }
    v42 = *((_DWORD *)v2 + 7);
    switch ( v42 )
    {
      case 1:
        v43 = 0;
        break;
      case 4:
        v43 = 3;
        break;
      case 2:
        v43 = 1;
        break;
      default:
        _drm_err("invalid number of mixers:%d\n", v42);
        v45 = &unk_23FBD9;
        goto LABEL_62;
    }
    _drm_dev_dbg(0, 0, 0, "number mixers:%u, merge mode:%u\n", v42, v43);
    v193 = 0;
    param_rb = sde_hw_rc_get_param_rb((_DWORD *)v40, (unsigned __int16 *)&v176, (_DWORD *)&v193 + 1, (int *)&v193);
    if ( param_rb )
    {
      v164 = &unk_24D260;
    }
    else
    {
      v48 = *(_DWORD *)(v40 + 16);
      param_rb = reg_dmav1_rc_program_enable_bits(
                   v5,
                   (__int64 *)v40,
                   v48,
                   v193,
                   SHIDWORD(v193),
                   v43,
                   (__int64)&v176,
                   ops,
                   0x12u);
      if ( param_rb )
      {
        v164 = &unk_274459;
      }
      else
      {
        if ( v48 == 2 )
        {
          v49 = *(_DWORD *)(v40 + 20);
          v50 = *(_DWORD *)(v40 + 24);
        }
        else if ( v48 == 4 )
        {
          v49 = *(_DWORD *)(v40 + 20) | (*(_DWORD *)(v40 + 24) << 16);
          v50 = *(_DWORD *)(v40 + 28) | (*(_DWORD *)(v40 + 32) << 16);
        }
        else
        {
          v49 = 0;
          v50 = 0;
        }
        v51 = *(_QWORD *)(v5 + 72);
        v203 = *(unsigned __int16 *)(v40 + 8) | (*(_DWORD *)(v40 + 12) << 16);
        v52 = *(_DWORD *)(v5 + 8);
        v53 = *(_QWORD *)(v51 + 48);
        v54 = *(unsigned int *)(v5 + 64);
        v201 = 0;
        v202 = 0;
        v195 = 0x1280000000LL;
        v55 = *(_DWORD *)(v53 + 524);
        if ( (unsigned int)v54 >= 5 )
          goto LABEL_197;
        v56 = *(unsigned int *)(v5 + 1496);
        if ( (unsigned int)v56 > 1 )
          goto LABEL_197;
        if ( (unsigned __int64)(16 * v54 + 8 * v56 + 1440) > 0x7CF )
          goto LABEL_198;
        v196 = 0;
        v197 = v52 + v55 + 8;
        v198 = dspp_buf[2 * v54 + 180 + v56];
        v199 = &v203;
        v200 = 0x400000000LL;
        v57 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
        v194 = 1;
        if ( *((_DWORD *)v57 - 1) != -1839634494 )
          __break(0x8229u);
        v58 = v57(&v194);
        if ( v58 )
          printk(&unk_27AAB6, v58);
        v59 = *(_QWORD *)(v5 + 72);
        v60 = *(unsigned int *)(v5 + 64);
        v203 = v49;
        v61 = *(_QWORD *)(v59 + 48);
        v62 = *(_DWORD *)(v5 + 8);
        v201 = 0;
        v202 = 0;
        v63 = *(_DWORD *)(v61 + 524);
        v195 = 0x1280000000LL;
        if ( (unsigned int)v60 >= 5 )
          goto LABEL_197;
        v64 = *(unsigned int *)(v5 + 1496);
        if ( (unsigned int)v64 > 1 )
          goto LABEL_197;
        if ( (unsigned __int64)(16 * v60 + 8 * v64 + 1440) > 0x7CF )
          goto LABEL_198;
        v196 = 0;
        v197 = v62 + v63 + 12;
        v198 = dspp_buf[2 * v60 + 180 + v64];
        v199 = &v203;
        v200 = 0x400000000LL;
        v65 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
        v194 = 1;
        if ( *((_DWORD *)v65 - 1) != -1839634494 )
          __break(0x8229u);
        v66 = v65(&v194);
        if ( v66 )
          printk(&unk_27AAB6, v66);
        v67 = *(_QWORD *)(v5 + 72);
        v68 = *(unsigned int *)(v5 + 64);
        v203 = v50;
        v69 = *(_QWORD *)(v67 + 48);
        v70 = *(_DWORD *)(v5 + 8);
        v201 = 0;
        v202 = 0;
        v71 = *(_DWORD *)(v69 + 524);
        v195 = 0x1280000000LL;
        if ( (unsigned int)v68 >= 5 )
          goto LABEL_197;
        v72 = *(unsigned int *)(v5 + 1496);
        if ( (unsigned int)v72 > 1 )
          goto LABEL_197;
        if ( (unsigned __int64)(16 * v68 + 8 * v72 + 1440) > 0x7CF )
          goto LABEL_198;
        v196 = 0;
        v197 = v70 + v71 + 16;
        v198 = dspp_buf[2 * v68 + 180 + v72];
        v199 = &v203;
        v200 = 0x400000000LL;
        v73 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
        v194 = 1;
        if ( *((_DWORD *)v73 - 1) != -1839634494 )
          __break(0x8229u);
        param_rb = v73(&v194);
        if ( !param_rb )
        {
          v74 = *(_DWORD *)(v40 + 16);
          v75 = *(_DWORD *)(v40 + 72);
          if ( v74 == 2 )
          {
            v76 = *(_DWORD *)(v40 + 36) + v75;
            v77 = *(_DWORD *)(v40 + 40) + v75;
            v78 = *(_DWORD *)(v40 + 52) + v75;
            v79 = *(_DWORD *)(v40 + 56) + v75;
          }
          else if ( v74 == 4 )
          {
            v76 = (*(_DWORD *)(v40 + 36) + v75) | ((*(_DWORD *)(v40 + 40) + v75) << 16);
            v77 = (*(_DWORD *)(v40 + 44) + v75) | ((*(_DWORD *)(v40 + 48) + v75) << 16);
            v78 = (*(_DWORD *)(v40 + 52) + v75) | ((*(_DWORD *)(v40 + 56) + v75) << 16);
            v79 = (*(_DWORD *)(v40 + 60) + v75) | ((*(_DWORD *)(v40 + 64) + v75) << 16);
          }
          else
          {
            v76 = 0;
            v77 = 0;
            v78 = 0;
            v79 = 0;
          }
          v80 = *(_QWORD *)(v5 + 72);
          v203 = v76;
          v81 = *(unsigned int *)(v5 + 64);
          v82 = *(_QWORD *)(v80 + 48);
          v83 = *(_DWORD *)(v5 + 8);
          v201 = 0;
          v202 = 0;
          v195 = 0x1280000000LL;
          v84 = *(_DWORD *)(v82 + 524);
          if ( (unsigned int)v81 >= 5 )
            goto LABEL_197;
          v85 = *(unsigned int *)(v5 + 1496);
          if ( (unsigned int)v85 > 1 )
            goto LABEL_197;
          if ( (unsigned __int64)(16 * v81 + 8 * v85 + 1440) > 0x7CF )
            goto LABEL_198;
          v196 = 0;
          v197 = v83 + v84 + 20;
          v198 = dspp_buf[2 * v81 + 180 + v85];
          v199 = &v203;
          v200 = 0x400000000LL;
          v86 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
          v194 = 1;
          if ( *((_DWORD *)v86 - 1) != -1839634494 )
            __break(0x8229u);
          v87 = v86(&v194);
          if ( v87 )
            printk(&unk_27AAB6, v87);
          v88 = *(_QWORD *)(v5 + 72);
          v89 = *(unsigned int *)(v5 + 64);
          v203 = v77;
          v90 = *(_QWORD *)(v88 + 48);
          v91 = *(_DWORD *)(v5 + 8);
          v201 = 0;
          v202 = 0;
          v92 = *(_DWORD *)(v90 + 524);
          v195 = 0x1280000000LL;
          if ( (unsigned int)v89 >= 5 )
            goto LABEL_197;
          v93 = *(unsigned int *)(v5 + 1496);
          if ( (unsigned int)v93 > 1 )
            goto LABEL_197;
          if ( (unsigned __int64)(16 * v89 + 8 * v93 + 1440) > 0x7CF )
            goto LABEL_198;
          v196 = 0;
          v197 = v91 + v92 + 24;
          v198 = dspp_buf[2 * v89 + 180 + v93];
          v199 = &v203;
          v200 = 0x400000000LL;
          v94 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
          v194 = 1;
          if ( *((_DWORD *)v94 - 1) != -1839634494 )
            __break(0x8229u);
          v95 = v94(&v194);
          if ( v95 )
            printk(&unk_27AAB6, v95);
          v96 = *(_QWORD *)(v5 + 72);
          v97 = *(unsigned int *)(v5 + 64);
          v203 = v78;
          v98 = *(_QWORD *)(v96 + 48);
          v99 = *(_DWORD *)(v5 + 8);
          v201 = 0;
          v202 = 0;
          v100 = *(_DWORD *)(v98 + 524);
          v195 = 0x1280000000LL;
          if ( (unsigned int)v97 >= 5 )
            goto LABEL_197;
          v101 = *(unsigned int *)(v5 + 1496);
          if ( (unsigned int)v101 > 1 )
            goto LABEL_197;
          if ( (unsigned __int64)(16 * v97 + 8 * v101 + 1440) > 0x7CF )
            goto LABEL_198;
          v196 = 0;
          v197 = v99 + v100 + 28;
          v198 = dspp_buf[2 * v97 + 180 + v101];
          v199 = &v203;
          v200 = 0x400000000LL;
          v102 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
          v194 = 1;
          if ( *((_DWORD *)v102 - 1) != -1839634494 )
            __break(0x8229u);
          v103 = v102(&v194);
          if ( v103 )
            printk(&unk_27AAB6, v103);
          v104 = *(_QWORD *)(v5 + 72);
          v105 = *(unsigned int *)(v5 + 64);
          v203 = v79;
          v106 = *(_QWORD *)(v104 + 48);
          v107 = *(_DWORD *)(v5 + 8);
          v201 = 0;
          v202 = 0;
          v108 = *(_DWORD *)(v106 + 524);
          v195 = 0x1280000000LL;
          if ( (unsigned int)v105 >= 5 )
            goto LABEL_197;
          v109 = *(unsigned int *)(v5 + 1496);
          if ( (unsigned int)v109 > 1 )
            goto LABEL_197;
          if ( (unsigned __int64)(16 * v105 + 8 * v109 + 1440) > 0x7CF )
            goto LABEL_198;
          v196 = 0;
          v197 = v107 + v108 + 32;
          v198 = dspp_buf[2 * v105 + 180 + v109];
          v199 = &v203;
          v200 = 0x400000000LL;
          v110 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
          v194 = 1;
          if ( *((_DWORD *)v110 - 1) != -1839634494 )
            __break(0x8229u);
          v111 = v110(&v194);
          if ( !v111 )
          {
            if ( (*(_BYTE *)v40 & 1) != 0
              || (v114 = *(_QWORD *)(*(_QWORD *)(v5 + 72) + 48LL), *(_DWORD *)(v114 + 536) % *((_DWORD *)v2 + 7)) )
            {
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "skip data programming\n");
              sde_evtlog_log(
                sde_dbg_base_evtlog,
                "reg_dmav1_setup_rc_mask_configv1",
                1913,
                -1,
                *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(v5 + 72) + 48LL) + 536LL),
                -1059143953,
                v112,
                v113,
                v169);
              v174 = nullptr;
              goto LABEL_130;
            }
            v130 = *(_DWORD *)(v5 + 8);
            v131 = *(_DWORD *)(v114 + 524);
            v132 = (unsigned int)(8 * *(_DWORD *)(v40 + 80));
            if ( (_drm_debug & 4) != 0 )
              _drm_dev_dbg(0, 0, 0, "allocating %u bytes of memory for dma\n", v132);
            v133 = _kvmalloc_node_noprof(v132, 0, 3520, 0xFFFFFFFFLL);
            if ( v133 )
            {
              v170 = v131;
              v171 = v130;
              v134 = *(_QWORD *)(v40 + 72);
              v174 = (_DWORD *)v133;
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "cfg_param_07:%u\n", v134);
              if ( !*(_DWORD *)(v40 + 80) )
                goto LABEL_166;
              v135 = *(_QWORD *)(v40 + 88);
              if ( (_drm_debug & 4) != 0 )
                _drm_dev_dbg(0, 0, 0, "cfg_param_09[%d] = 0x%016llX at %u\n", 0, *(_QWORD *)(v40 + 88), v134);
              if ( v132 < 4 || (*v174 = v135 & 0x3FFFF | ((_DWORD)v134 << 18) | 0x40000000, (v132 & 0xFFFFFFFC) == 4) )
LABEL_198:
                __break(1u);
              v174[1] = (v135 >> 18) & 0x3FFFF;
              if ( *(_DWORD *)(v40 + 80) < 2u )
              {
LABEL_166:
                v126 = v174;
                *(_QWORD *)((char *)&v178 + 4) = 0;
                LODWORD(v181) = 0;
                HIDWORD(v181) = v132;
                v180 = v174;
                HIDWORD(v178) = v171 + v170 + 40;
                v150 = *(__int64 (__fastcall **)(_QWORD))(ops + 8);
                LODWORD(v177) = 3;
                if ( *((_DWORD *)v150 - 1) != -1839634494 )
                  __break(0x8229u);
                v125 = v150(&v177);
                if ( v125 )
                {
                  v166 = &unk_27AAB6;
                  goto LABEL_194;
                }
LABEL_130:
                v115 = *((_DWORD *)v2 + 42);
                v116 = v2[2];
                v186 = 0;
                v187 = 0u;
                v188 = 0;
                v117 = v115 | 1;
                v184 = v116;
                v185 = 0;
                *((_DWORD *)v2 + 42) = v117;
                v118 = *(unsigned int *)(v5 + 64);
                v189 = 0;
                v190 = 0;
                v191 = 0;
                v192 = 0;
                if ( (unsigned int)v118 > 4 )
                  goto LABEL_197;
                v119 = *(unsigned int *)(v5 + 1496);
                if ( (unsigned int)v119 > 1 )
                  goto LABEL_197;
                if ( (unsigned __int64)(16 * v118 + 8 * v119 + 1440) > 0x7CF )
                  goto LABEL_198;
                LODWORD(v185) = 1;
                v120 = *(unsigned int *)(v5 + 28);
                *(_QWORD *)((char *)&v187 + 4) = 1;
                v121 = v2[19];
                LODWORD(v188) = 18;
                v189 = v121;
                v122 = *((_DWORD *)v2 + 40);
                LODWORD(v121) = *((_DWORD *)v2 + 41);
                v186 = dspp_buf[2 * v118 + 180 + v119];
                v190 = __PAIR64__(v121, v122);
                v123 = *((_DWORD *)v2 + 44);
                LODWORD(v192) = *((_DWORD *)v2 + 43);
                HIDWORD(v192) = v123;
                v191 = __PAIR64__(*((_DWORD *)v2 + 7), v117);
                if ( (unsigned int)v120 > 2 )
                  goto LABEL_197;
                v124 = *(_DWORD **)(ops + 8 * v120 + 16);
                if ( !v124 )
                {
                  v126 = v174;
LABEL_140:
                  sde_evtlog_log(
                    sde_dbg_base_evtlog,
                    "reg_dmav1_setup_rc_mask_configv1",
                    1931,
                    -1,
                    v118,
                    v119,
                    v120,
                    1,
                    239);
                  memcpy(*(void **)(v5 + 1480), (const void *)v40, 0x5560u);
                  result = 0;
                  if ( !v126 )
                    goto LABEL_189;
                  goto LABEL_141;
                }
                if ( *(v124 - 1) != 1772228465 )
                  __break(0x8228u);
                v125 = ((__int64 (__fastcall *)(__int64 *, _QWORD))v124)(&v184, (unsigned int)v119);
                v126 = v174;
                if ( !v125 )
                {
                  LODWORD(v118) = *(_DWORD *)(v5 + 64);
                  LODWORD(v119) = *(_DWORD *)(v5 + 1496);
                  LODWORD(v120) = *(_DWORD *)(v5 + 28);
                  goto LABEL_140;
                }
                v166 = &unk_277957;
LABEL_194:
                v167 = v125;
                printk(v166, v125);
                result = v167;
                if ( !v126 )
                  goto LABEL_189;
LABEL_141:
                v127 = result;
                kvfree(v126);
LABEL_188:
                result = v127;
                goto LABEL_189;
              }
              v136 = 0;
              v137 = 0;
              v172 = ops;
              v173 = v134 + 1;
              v138 = v132 - 12;
              v139 = v40 + 96;
              v140 = v174 + 2;
              while ( v136 != 2719 )
              {
                v141 = *(_QWORD *)(v139 + 8 * v136);
                if ( (_drm_debug & 4) != 0 )
                {
                  v142 = v40;
                  v143 = v132;
                  v144 = v139;
                  v145 = v5;
                  v146 = v2;
                  v147 = v140;
                  _drm_dev_dbg(
                    0,
                    0,
                    0,
                    "cfg_param_09[%d] = 0x%016llX at %u\n",
                    v136 + 1,
                    *(_QWORD *)(v139 + 8 * v136),
                    v173 + v136);
                  v139 = v144;
                  v132 = v143;
                  v40 = v142;
                  ops = v172;
                  v140 = v147;
                  v2 = v146;
                  v5 = v145;
                }
                if ( v132 < v137 * 4 + 8 )
                  goto LABEL_198;
                if ( v138 >= 0xFFFFFFFFFFFFFFFCLL )
                  goto LABEL_198;
                v140[v137] = v141 & 0x3FFFF;
                if ( v132 < v137 * 4 + 12 || v138 < 4 )
                  goto LABEL_198;
                v148 = &v140[v137];
                v138 -= 8LL;
                v137 += 2;
                v148[1] = (v141 >> 18) & 0x3FFFF;
                v149 = v136 + 2;
                ++v136;
                if ( v149 >= *(unsigned int *)(v40 + 80) )
                  goto LABEL_166;
              }
LABEL_197:
              __break(0x5512u);
              goto LABEL_198;
            }
            v129 = &unk_23C712;
            v128 = 0;
LABEL_145:
            printk(v129, v128);
            result = 4294967284LL;
            goto LABEL_189;
          }
          v127 = v111;
          printk(&unk_27AAB6, v111);
          v165 = &unk_250911;
LABEL_187:
          printk(v165, v127);
          goto LABEL_188;
        }
        v164 = &unk_27AAB6;
      }
    }
    v127 = param_rb;
    printk(v164, param_rb);
    v165 = &unk_25B6FF;
    goto LABEL_187;
  }
LABEL_189:
  _ReadStatusReg(SP_EL0);
  return result;
}
