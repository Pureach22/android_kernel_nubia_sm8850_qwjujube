__int64 __fastcall sde_hw_setup_scaler3(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5, char a6)
{
  unsigned int v8; // w22
  int v10; // w9
  unsigned int v11; // w8
  int v12; // w10
  int v13; // w8
  int v14; // w9
  int v15; // w24
  int v16; // w25
  int v17; // w26
  unsigned int v18; // w22
  int v19; // w26
  int v20; // w28
  unsigned int v21; // w27
  __int16 v22; // w24
  __int16 v23; // w23
  __int16 v24; // w25
  unsigned int v25; // w28
  int v26; // w25
  unsigned int v27; // w8
  unsigned int v28; // w9
  __int64 v29; // x0
  unsigned int v30; // w22
  unsigned int v31; // w25
  int v32; // w24
  unsigned int v33; // w8
  unsigned int v34; // w9
  __int64 v35; // x0
  unsigned int v36; // w23
  unsigned int v37; // w25
  unsigned int v38; // w8
  unsigned int v39; // w9
  __int64 v40; // x0
  unsigned int v41; // w23
  unsigned int v42; // w26
  unsigned int v43; // w8
  unsigned int v44; // w9
  __int64 v45; // x0
  unsigned int v46; // w23
  unsigned int v47; // w27
  unsigned int v48; // w8
  unsigned int v49; // w9
  __int64 v50; // x0
  unsigned int v51; // w23
  unsigned int v52; // w8
  unsigned int v53; // w9
  __int64 v54; // x0
  unsigned int v55; // w22
  unsigned int v56; // w8
  unsigned int v57; // w9
  __int64 v58; // x0
  __int64 (__fastcall *v59)(); // x8
  unsigned int v60; // w22
  unsigned int v61; // w24
  unsigned int v62; // w24
  int v63; // w23
  unsigned int v64; // w8
  unsigned int v65; // w9
  __int64 v66; // x0
  unsigned int v67; // w24
  int v68; // w23
  unsigned int v69; // w8
  unsigned int v70; // w9
  __int64 v71; // x0
  unsigned int v72; // w23
  int v73; // w22
  unsigned int v74; // w8
  unsigned int v75; // w9
  __int64 v76; // x0
  int v77; // w25
  unsigned int v78; // w8
  unsigned int v79; // w9
  __int64 v80; // x0
  unsigned int v81; // w24
  int v82; // w22
  unsigned int v83; // w25
  unsigned int v84; // w8
  unsigned int v85; // w9
  __int64 v86; // x0
  unsigned int v87; // w24
  int v88; // w23
  unsigned int v89; // w25
  unsigned int v90; // w8
  unsigned int v91; // w9
  __int64 v92; // x0
  unsigned int v93; // w26
  int v94; // w24
  unsigned int v95; // w25
  unsigned int v96; // w8
  unsigned int v97; // w9
  __int64 v98; // x0
  unsigned int v99; // w27
  int v100; // w26
  int v101; // w24
  unsigned int v102; // w8
  unsigned int v103; // w9
  __int64 v104; // x0
  unsigned int v105; // w27
  int v106; // w26
  unsigned int v107; // w8
  unsigned int v108; // w9
  __int64 v109; // x0
  unsigned int v110; // w27
  int v111; // w25
  unsigned int v112; // w8
  unsigned int v113; // w9
  __int64 v114; // x0
  unsigned int v115; // w23
  unsigned int v116; // w8
  unsigned int v117; // w9
  __int64 v118; // x0
  unsigned int v119; // w22
  unsigned int v120; // w8
  unsigned int v121; // w9
  __int64 v122; // x0
  unsigned int v123; // w22
  unsigned int v124; // w24
  unsigned int v125; // w8
  unsigned int v126; // w9
  __int64 v127; // x0
  unsigned int v128; // w23
  int v129; // w25
  unsigned int v130; // w8
  unsigned int v131; // w9
  __int64 v132; // x0
  unsigned int v133; // w23
  int v134; // w25
  unsigned int v135; // w8
  unsigned int v136; // w9
  __int64 v137; // x0
  unsigned int v138; // w22
  int v139; // w25
  unsigned int v140; // w8
  unsigned int v141; // w9
  __int64 v142; // x0
  int v143; // w9
  unsigned int v144; // w20
  unsigned int v145; // w8
  unsigned int v146; // w9
  __int64 v147; // x0
  __int16 v149; // [xsp+0h] [xbp-60h]
  __int16 v150; // [xsp+4h] [xbp-5Ch]
  __int16 v151; // [xsp+8h] [xbp-58h]
  __int16 v152; // [xsp+Ch] [xbp-54h]
  __int16 v153; // [xsp+10h] [xbp-50h]
  __int16 v154; // [xsp+14h] [xbp-4Ch]
  __int16 v155; // [xsp+18h] [xbp-48h]
  __int16 v156; // [xsp+1Ch] [xbp-44h]
  __int16 v157; // [xsp+20h] [xbp-40h]
  int v158; // [xsp+24h] [xbp-3Ch]
  int v159; // [xsp+28h] [xbp-38h]
  int v160; // [xsp+2Ch] [xbp-34h]
  int v161; // [xsp+30h] [xbp-30h]
  int v162; // [xsp+34h] [xbp-2Ch]
  int v163; // [xsp+38h] [xbp-28h]
  int v164; // [xsp+3Ch] [xbp-24h]
  int v165; // [xsp+40h] [xbp-20h]
  int v166; // [xsp+44h] [xbp-1Ch]
  int v167; // [xsp+48h] [xbp-18h]
  __int64 v169; // [xsp+50h] [xbp-10h]
  int v171; // [xsp+5Ch] [xbp-4h]

  v8 = a3;
  if ( !*(_DWORD *)a2 )
  {
    v15 = 0;
    if ( !a5 )
      goto LABEL_183;
    goto LABEL_176;
  }
  v10 = *(_DWORD *)(a2 + 152);
  v169 = a5;
  v11 = ((v10 & 3) << 16) | 1;
  if ( a5 && (*(_QWORD *)(a5 + 32) & 1) != 0 )
    v11 = ((v10 & 3) << 16) & 0xFCFFFFFF | ((*(_DWORD *)(a2 + 156) & 3) << 24) | 0x1001;
  v12 = *(_DWORD *)(a2 + 4);
  v13 = v11 | (*(_DWORD *)(a2 + 164) << 31) | (16 * (v12 != 0));
  if ( v12 )
  {
    v13 |= 32 * (*(_DWORD *)(a2 + 12) != 0);
    v14 = (*(_DWORD *)(a2 + 8) != 0) << 6;
  }
  else
  {
    v14 = 0;
  }
  v16 = *(_DWORD *)(a2 + 80);
  v17 = *(_DWORD *)(a2 + 84);
  v162 = *(_DWORD *)(a2 + 100);
  v160 = *(_DWORD *)(a2 + 96);
  v171 = v14 | v13 | ((*(_DWORD *)(a2 + 288) != 0) << 13);
  v161 = *(_DWORD *)(a2 + 112);
  v163 = *(_DWORD *)(a2 + 128);
  v164 = *(_DWORD *)(a2 + 116);
  v165 = *(_DWORD *)(a2 + 132);
  v166 = *(_DWORD *)(a2 + 144);
  v167 = *(_DWORD *)(a2 + 148);
  if ( *(_DWORD *)(a2 + 240) )
  {
    v158 = *(_DWORD *)(a2 + 80);
    v159 = *(_DWORD *)(a2 + 84);
    v18 = a4 + 36;
    v151 = *(_WORD *)(a2 + 258);
    v19 = *(_WORD *)(a2 + 244) & 0x1FF | ((*(_WORD *)(a2 + 246) & 0x1FF) << 16);
    v154 = *(_WORD *)(a2 + 266);
    v153 = *(_WORD *)(a2 + 270);
    v20 = *(unsigned __int8 *)(a2 + 252);
    v149 = *(_WORD *)(a2 + 264);
    v150 = *(_WORD *)(a2 + 268);
    v21 = ((*(_WORD *)(a2 + 260) & 7) << 13)
        | ((*(_WORD *)(a2 + 250) & 0xF) << 9)
        | ((*(_WORD *)(a2 + 248) & 7) << 16) & 0xFF0FFFFF
        | ((*(_DWORD *)(a2 + 280) & 0xF) << 20);
    v22 = *(_WORD *)(a2 + 254);
    v23 = *(_WORD *)(a2 + 256);
    v24 = *(_WORD *)(a2 + 262);
    v152 = *(_WORD *)(a2 + 274);
    v155 = *(_WORD *)(a2 + 276);
    v156 = *(_WORD *)(a2 + 272);
    v157 = *(_WORD *)(a2 + 278);
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DE_SHARPEN + offset", *(_DWORD *)(a1 + 8) + v18, v19);
    v25 = v20 & 0xFC00FFFF | ((v22 & 0x3FF) << 16);
    v26 = v24 & 0x3FF;
    writel_relaxed_8(v19, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v18));
    v27 = *(_DWORD *)(a1 + 24);
    v28 = 32 - __clz(v27);
    if ( v27 )
      v29 = v28;
    else
      v29 = 0;
    sde_reglog_log(v29, v19, *(_DWORD *)(a1 + 8) + v18);
    v30 = a4 + 40;
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DE_SHARPEN_CTL + offset", *(_DWORD *)(a1 + 8) + v30, v21);
    v31 = v26 & 0xFFF003FF | ((v149 & 0x3FF) << 10);
    v32 = v23 & 0x3FF | ((v151 & 0x3FF) << 16);
    writel_relaxed_8(v21, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v30));
    v33 = *(_DWORD *)(a1 + 24);
    v34 = 32 - __clz(v33);
    if ( v33 )
      v35 = v34;
    else
      v35 = 0;
    sde_reglog_log(v35, v21, *(_DWORD *)(a1 + 8) + v30);
    v36 = a4 + 44;
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DE_SHAPE_CTL + offset", *(_DWORD *)(a1 + 8) + v36, v25);
    v37 = v31 & 0xC00FFFFF | ((v154 & 0x3FF) << 20);
    writel_relaxed_8(v25, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v36));
    v38 = *(_DWORD *)(a1 + 24);
    v39 = 32 - __clz(v38);
    if ( v38 )
      v40 = v39;
    else
      v40 = 0;
    sde_reglog_log(v40, v25, *(_DWORD *)(a1 + 8) + v36);
    v41 = a4 + 48;
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DE_THRESHOLD + offset", *(_DWORD *)(a1 + 8) + v41, v32);
    v42 = v150 & 0x3FF | ((v153 & 0x3FF) << 10) & 0xC00FFFFF | ((v156 & 0x3FF) << 20);
    writel_relaxed_8(v32, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v41));
    v43 = *(_DWORD *)(a1 + 24);
    v44 = 32 - __clz(v43);
    if ( v43 )
      v45 = v44;
    else
      v45 = 0;
    sde_reglog_log(v45, v32, *(_DWORD *)(a1 + 8) + v41);
    v46 = a4 + 52;
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DE_ADJUST_DATA_0 + offset", *(_DWORD *)(a1 + 8) + v46, v37);
    v47 = v152 & 0x3FF | ((v155 & 0x3FF) << 10) & 0xC00FFFFF | ((v157 & 0x3FF) << 20);
    writel_relaxed_8(v37, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v46));
    v48 = *(_DWORD *)(a1 + 24);
    v49 = 32 - __clz(v48);
    if ( v48 )
      v50 = v49;
    else
      v50 = 0;
    sde_reglog_log(v50, v37, *(_DWORD *)(a1 + 8) + v46);
    v51 = a4 + 56;
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DE_ADJUST_DATA_1 + offset", *(_DWORD *)(a1 + 8) + v51, v42);
    writel_relaxed_8(v42, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v51));
    v52 = *(_DWORD *)(a1 + 24);
    v53 = 32 - __clz(v52);
    if ( v52 )
      v54 = v53;
    else
      v54 = 0;
    sde_reglog_log(v54, v42, *(_DWORD *)(a1 + 8) + v51);
    LOBYTE(v16) = v158;
    v55 = a4 + 60;
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DE_ADJUST_DATA_2 + offset", *(_DWORD *)(a1 + 8) + v55, v47);
    writel_relaxed_8(v47, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v55));
    v56 = *(_DWORD *)(a1 + 24);
    v57 = 32 - __clz(v56);
    if ( v56 )
      v58 = v57;
    else
      v58 = 0;
    sde_reglog_log(v58, v47, *(_DWORD *)(a1 + 8) + v55);
    v8 = a3;
    LOBYTE(v17) = v159;
    v171 |= 0x100u;
  }
  if ( *(_DWORD *)(a2 + 168) )
  {
    v59 = sde_hw_setup_scaler3_lut;
    if ( v8 >> 2 >= 0x801 )
      v59 = sde_hw_setup_scaler3lite_lut;
    if ( *((_DWORD *)v59 - 1) != -1458905737 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))v59)(a1, a2, a4);
  }
  if ( v8 == 4098 )
  {
    v60 = a4 + 12;
    v61 = *(_DWORD *)(a2 + 16) & 0x3F
        | ((*(_WORD *)(a2 + 48) & 0x3F) << 8)
        | ((*(_DWORD *)(a2 + 20) & 0x3F) << 16) & 0xC0FFFFFF
        | ((*(_DWORD *)(a2 + 52) & 0x3F) << 24);
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PHASE_INIT + scaler_offset", *(_DWORD *)(a1 + 8) + v60, v61);
  }
  else
  {
    v62 = a4 + 144;
    v63 = *(_DWORD *)(a2 + 16);
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err(
        "[%s:0x%X] <= 0x%X\n",
        "QSEED3_PHASE_INIT_Y_H + scaler_offset",
        *(_DWORD *)(a1 + 8) + v62,
        v63 & 0x1FFFFF);
    writel_relaxed_8(v63 & 0x1FFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v62));
    v64 = *(_DWORD *)(a1 + 24);
    v65 = 32 - __clz(v64);
    if ( v64 )
      v66 = v65;
    else
      v66 = 0;
    sde_reglog_log(v66, v63 & 0x1FFFFF, *(_DWORD *)(a1 + 8) + v62);
    v67 = a4 + 148;
    v68 = *(_DWORD *)(a2 + 48);
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err(
        "[%s:0x%X] <= 0x%X\n",
        "QSEED3_PHASE_INIT_Y_V + scaler_offset",
        *(_DWORD *)(a1 + 8) + v67,
        v68 & 0x1FFFFF);
    writel_relaxed_8(v68 & 0x1FFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v67));
    v69 = *(_DWORD *)(a1 + 24);
    v70 = 32 - __clz(v69);
    if ( v69 )
      v71 = v70;
    else
      v71 = 0;
    sde_reglog_log(v71, v68 & 0x1FFFFF, *(_DWORD *)(a1 + 8) + v67);
    v72 = a4 + 152;
    v73 = *(_DWORD *)(a2 + 20);
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err(
        "[%s:0x%X] <= 0x%X\n",
        "QSEED3_PHASE_INIT_UV_H + scaler_offset",
        *(_DWORD *)(a1 + 8) + v72,
        v73 & 0x1FFFFF);
    writel_relaxed_8(v73 & 0x1FFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v72));
    v74 = *(_DWORD *)(a1 + 24);
    v75 = 32 - __clz(v74);
    if ( v74 )
      v76 = v75;
    else
      v76 = 0;
    sde_reglog_log(v76, v73 & 0x1FFFFF, *(_DWORD *)(a1 + 8) + v72);
    v60 = a4 + 156;
    v61 = *(_DWORD *)(a2 + 52) & 0x1FFFFF;
    if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PHASE_INIT_UV_V + scaler_offset", *(_DWORD *)(a1 + 8) + v60, v61);
  }
  v77 = v16 & 0x7F;
  writel_relaxed_8(v61, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v60));
  v78 = *(_DWORD *)(a1 + 24);
  v79 = 32 - __clz(v78);
  if ( v78 )
    v80 = v79;
  else
    v80 = 0;
  sde_reglog_log(v80, v61, *(_DWORD *)(a1 + 8) + v60);
  v81 = a4 + 16;
  v82 = *(_DWORD *)(a2 + 32);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PHASE_STEP_Y_H + scaler_offset", *(_DWORD *)(a1 + 8) + v81, v82 & 0xFFFFFF);
  v83 = v77 & 0xFFFF80FF | ((v160 & 0x7F) << 8);
  writel_relaxed_8(v82 & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v81));
  v84 = *(_DWORD *)(a1 + 24);
  v85 = 32 - __clz(v84);
  if ( v84 )
    v86 = v85;
  else
    v86 = 0;
  sde_reglog_log(v86, v82 & 0xFFFFFF, *(_DWORD *)(a1 + 8) + v81);
  v87 = a4 + 20;
  v88 = *(_DWORD *)(a2 + 64);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PHASE_STEP_Y_V + scaler_offset", *(_DWORD *)(a1 + 8) + v87, v88 & 0xFFFFFF);
  v89 = v83 & 0xFF80FFFF | ((v17 & 0x7F) << 16);
  writel_relaxed_8(v88 & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v87));
  v90 = *(_DWORD *)(a1 + 24);
  v91 = 32 - __clz(v90);
  if ( v90 )
    v92 = v91;
  else
    v92 = 0;
  sde_reglog_log(v92, v88 & 0xFFFFFF, *(_DWORD *)(a1 + 8) + v87);
  v93 = a4 + 24;
  v94 = *(_DWORD *)(a2 + 36);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PHASE_STEP_UV_H + scaler_offset", *(_DWORD *)(a1 + 8) + v93, v94 & 0xFFFFFF);
  v95 = v89 & 0x80FFFFFF | ((v162 & 0x7F) << 24);
  writel_relaxed_8(v94 & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v93));
  v96 = *(_DWORD *)(a1 + 24);
  v97 = 32 - __clz(v96);
  if ( v96 )
    v98 = v97;
  else
    v98 = 0;
  sde_reglog_log(v98, v94 & 0xFFFFFF, *(_DWORD *)(a1 + 8) + v93);
  v99 = a4 + 28;
  v100 = *(_DWORD *)(a2 + 68);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err(
      "[%s:0x%X] <= 0x%X\n",
      "QSEED3_PHASE_STEP_UV_V + scaler_offset",
      *(_DWORD *)(a1 + 8) + v99,
      v100 & 0xFFFFFF);
  v101 = v161 & 0x1FFFF | (v163 << 16);
  writel_relaxed_8(v100 & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v99));
  v102 = *(_DWORD *)(a1 + 24);
  v103 = 32 - __clz(v102);
  if ( v102 )
    v104 = v103;
  else
    v104 = 0;
  sde_reglog_log(v104, v100 & 0xFFFFFF, *(_DWORD *)(a1 + 8) + v99);
  v105 = a4 + 32;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PRELOAD + scaler_offset", *(_DWORD *)(a1 + 8) + v105, v95);
  v106 = v164 & 0x1FFFF | (v165 << 16);
  writel_relaxed_8(v95, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v105));
  v107 = *(_DWORD *)(a1 + 24);
  v108 = 32 - __clz(v107);
  if ( v107 )
    v109 = v108;
  else
    v109 = 0;
  sde_reglog_log(v109, v95, *(_DWORD *)(a1 + 8) + v105);
  v110 = a4 + 64;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_SRC_SIZE_Y_RGB_A + scaler_offset", *(_DWORD *)(a1 + 8) + v110, v101);
  v111 = v166 & 0x1FFFF | (v167 << 16);
  writel_relaxed_8(v101, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v110));
  v112 = *(_DWORD *)(a1 + 24);
  v113 = 32 - __clz(v112);
  if ( v112 )
    v114 = v113;
  else
    v114 = 0;
  sde_reglog_log(v114, v101, *(_DWORD *)(a1 + 8) + v110);
  v115 = a4 + 68;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_SRC_SIZE_UV + scaler_offset", *(_DWORD *)(a1 + 8) + v115, v106);
  writel_relaxed_8(v106, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v115));
  v116 = *(_DWORD *)(a1 + 24);
  v117 = 32 - __clz(v116);
  if ( v116 )
    v118 = v117;
  else
    v118 = 0;
  sde_reglog_log(v118, v106, *(_DWORD *)(a1 + 8) + v115);
  v119 = a4 + 72;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DST_SIZE + scaler_offset", *(_DWORD *)(a1 + 8) + v119, v111);
  writel_relaxed_8(v111, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v119));
  v120 = *(_DWORD *)(a1 + 24);
  v121 = 32 - __clz(v120);
  if ( v120 )
    v122 = v121;
  else
    v122 = 0;
  sde_reglog_log(v122, v111, *(_DWORD *)(a1 + 8) + v119);
  if ( (a6 & 1) != 0 )
  {
    if ( (*(_BYTE *)(a2 + 292) & 1) != 0 )
    {
      v123 = a4 + 100;
      v124 = *(_DWORD *)(a2 + 300) & 0x3FF
           | ((*(_DWORD *)(a2 + 304) & 0x3FF) << 10) & 0xC00FFFFF
           | ((*(_DWORD *)(a2 + 296) & 0x3FF) << 20);
      if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) == 0 || (_drm_debug & 2) == 0 )
      {
LABEL_145:
        writel_relaxed_8(v124, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v123));
        v125 = *(_DWORD *)(a1 + 24);
        v126 = 32 - __clz(v125);
        if ( v125 )
          v127 = v126;
        else
          v127 = 0;
        sde_reglog_log(v127, v124, *(_DWORD *)(a1 + 8) + v123);
        goto LABEL_149;
      }
    }
    else
    {
      v123 = a4 + 100;
      if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) == 0 )
      {
        v124 = 1072693248;
        goto LABEL_145;
      }
      v124 = 1072693248;
      if ( (_drm_debug & 2) == 0 )
        goto LABEL_145;
    }
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DE_LPF_BLEND + scaler_offset", *(_DWORD *)(a1 + 8) + v123, v124);
    goto LABEL_145;
  }
LABEL_149:
  v8 = a3;
  a5 = v169;
  if ( a3 < 0x3005 )
  {
    v15 = v171;
    goto LABEL_175;
  }
  v15 = v171 | ((*(_DWORD *)(a2 + 532) != 0) << 7);
  if ( (v171 & 0x100) == 0 || !*(_DWORD *)(a2 + 536) )
  {
LABEL_175:
    if ( !v169 )
      goto LABEL_183;
    goto LABEL_176;
  }
  v128 = a4 + 224;
  v129 = *(unsigned __int16 *)(a2 + 552) | (*(_DWORD *)(a2 + 556) << 16);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED7_ADE_STRENGTH_COEFF + scaler_offset", *(_DWORD *)(a1 + 8) + v128, v129);
  writel_relaxed_8(v129, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v128));
  v130 = *(_DWORD *)(a1 + 24);
  v131 = 32 - __clz(v130);
  if ( v130 )
    v132 = v131;
  else
    v132 = 0;
  sde_reglog_log(v132, v129, *(_DWORD *)(a1 + 8) + v128);
  v133 = a4 + 228;
  v134 = *(unsigned __int8 *)(a2 + 544) | (*(_DWORD *)(a2 + 548) << 16);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED7_ADE_STRENGTH_MAP + scaler_offset", *(_DWORD *)(a1 + 8) + v133, v134);
  writel_relaxed_8(v134, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v133));
  v135 = *(_DWORD *)(a1 + 24);
  v136 = 32 - __clz(v135);
  if ( v135 )
    v137 = v136;
  else
    v137 = 0;
  sde_reglog_log(v137, v134, *(_DWORD *)(a1 + 8) + v133);
  v138 = a4 + 232;
  v139 = (unsigned __int8)*(_DWORD *)(a2 + 560) << 8;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED7_ADE_HALO_SUPPRESS + scaler_offset", *(_DWORD *)(a1 + 8) + v138, v139);
  writel_relaxed_8(v139, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v138));
  v140 = *(_DWORD *)(a1 + 24);
  v141 = 32 - __clz(v140);
  if ( v140 )
    v142 = v141;
  else
    v142 = 0;
  sde_reglog_log(v142, v139, *(_DWORD *)(a1 + 8) + v138);
  if ( *(_DWORD *)(a2 + 540) )
  {
    if ( *(_DWORD *)(a2 + 308) | v171 & 0x1000 )
      v15 |= 0x200u;
    else
      v15 |= 0xA00u;
  }
  else
  {
    v15 |= 0x200u;
  }
  v8 = a3;
  a5 = v169;
  if ( v169 )
  {
LABEL_176:
    if ( (*(_QWORD *)(a5 + 32) & 2LL) == 0 )
      v15 |= 0x4000u;
    if ( *(_BYTE *)(a5 + 24) )
    {
      if ( v8 == 4098 )
        v143 = (*(_DWORD *)(a2 + 160) & 1) << 30;
      else
        v143 = (*(_DWORD *)(a2 + 160) & 3) << 29;
      v15 |= v143 | 0x400;
    }
  }
LABEL_183:
  v144 = a4 + 4;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_OP_MODE + scaler_offset", *(_DWORD *)(a1 + 8) + v144, v15);
  writel_relaxed_8(v15, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v144));
  v145 = *(_DWORD *)(a1 + 24);
  v146 = 32 - __clz(v145);
  if ( v145 )
    v147 = v146;
  else
    v147 = 0;
  return sde_reglog_log(v147, v15, *(_DWORD *)(a1 + 8) + v144);
}
