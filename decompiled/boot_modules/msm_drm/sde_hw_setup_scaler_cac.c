__int64 __fastcall sde_hw_setup_scaler_cac(__int64 a1, int a2, int *a3)
{
  int v6; // w0
  int v7; // w25
  int v8; // w23
  unsigned int v9; // w24
  int v10; // w26
  int v11; // w27
  unsigned int v12; // w8
  unsigned int v13; // w9
  __int64 v14; // x0
  unsigned int v15; // w27
  int v16; // w24
  unsigned int v17; // w8
  unsigned int v18; // w9
  __int64 v19; // x0
  unsigned int v20; // w27
  int v21; // w22
  unsigned int v22; // w8
  unsigned int v23; // w9
  __int64 v24; // x0
  unsigned int v25; // w27
  unsigned int v26; // w22
  unsigned int v27; // w8
  unsigned int v28; // w9
  __int64 v29; // x0
  unsigned int v30; // w27
  unsigned int v31; // w22
  unsigned int v32; // w8
  unsigned int v33; // w9
  __int64 v34; // x0
  unsigned int v35; // w27
  unsigned int v36; // w22
  unsigned int v37; // w8
  unsigned int v38; // w9
  __int64 v39; // x0
  unsigned int v40; // w24
  unsigned int v41; // w22
  unsigned int v42; // w8
  unsigned int v43; // w9
  __int64 v44; // x0
  unsigned int v45; // w22
  unsigned int v46; // w24
  int v47; // w27
  unsigned int v48; // w8
  unsigned int v49; // w9
  __int64 v50; // x0
  unsigned int v51; // w22
  unsigned int v52; // w24
  int v53; // w28
  unsigned int v54; // w8
  unsigned int v55; // w9
  __int64 v56; // x0
  unsigned int v57; // w22
  unsigned int v58; // w8
  unsigned int v59; // w9
  __int64 v60; // x0
  unsigned int v61; // w22
  unsigned int v62; // w8
  unsigned int v63; // w9
  __int64 v64; // x0
  unsigned int v65; // w24
  unsigned int v66; // w22
  int v67; // w27
  unsigned int v68; // w8
  unsigned int v69; // w9
  __int64 v70; // x0
  unsigned int v71; // w24
  unsigned int v72; // w22
  int v73; // w28
  unsigned int v74; // w8
  unsigned int v75; // w9
  __int64 v76; // x0
  unsigned int v77; // w24
  unsigned int v78; // w8
  unsigned int v79; // w9
  __int64 v80; // x0
  unsigned int v81; // w23
  int v82; // w25
  unsigned int v83; // w8
  unsigned int v84; // w9
  __int64 v85; // x0
  unsigned int v86; // w23
  unsigned int v87; // w27
  int v88; // w26
  unsigned int v89; // w8
  unsigned int v90; // w9
  __int64 v91; // x0
  int v92; // w23
  unsigned int v93; // w8
  unsigned int v94; // w9
  __int64 v95; // x0
  int v96; // w24
  unsigned int v97; // w8
  unsigned int v98; // w9
  __int64 v99; // x0
  unsigned int v100; // w8
  unsigned int v101; // w9
  __int64 v102; // x0
  int v103; // w23
  int v104; // w22
  unsigned int v105; // w8
  unsigned int v106; // w9
  __int64 v107; // x0
  unsigned int v108; // w8
  unsigned int v109; // w9
  __int64 v110; // x0
  unsigned int v111; // w23
  int v112; // w22
  unsigned int v113; // w8
  unsigned int v114; // w9
  __int64 v115; // x0
  unsigned int v116; // w24
  int v117; // w23
  unsigned int v118; // w8
  unsigned int v119; // w9
  __int64 v120; // x0
  unsigned int v121; // w24
  int v122; // w23
  unsigned int v123; // w8
  unsigned int v124; // w9
  __int64 v125; // x0
  unsigned int v126; // w20
  int v127; // w21
  unsigned int v128; // w8
  unsigned int v129; // w9
  __int64 v130; // x0
  int v132; // [xsp+4h] [xbp-8Ch]
  int v133; // [xsp+8h] [xbp-88h]
  int v134; // [xsp+Ch] [xbp-84h]
  int v135; // [xsp+10h] [xbp-80h]
  int v136; // [xsp+14h] [xbp-7Ch]
  int v137; // [xsp+18h] [xbp-78h]
  int v138; // [xsp+1Ch] [xbp-74h]
  int v139; // [xsp+20h] [xbp-70h]
  int v140; // [xsp+24h] [xbp-6Ch]
  int v141; // [xsp+28h] [xbp-68h]
  int v142; // [xsp+2Ch] [xbp-64h]
  int v143; // [xsp+30h] [xbp-60h]
  int v144; // [xsp+34h] [xbp-5Ch]
  int v145; // [xsp+38h] [xbp-58h]
  int v146; // [xsp+3Ch] [xbp-54h]
  int v147; // [xsp+40h] [xbp-50h]
  int v148; // [xsp+44h] [xbp-4Ch]
  int v149; // [xsp+48h] [xbp-48h]
  int v150; // [xsp+4Ch] [xbp-44h]
  int v151; // [xsp+50h] [xbp-40h]
  int v152; // [xsp+54h] [xbp-3Ch]
  __int64 v153; // [xsp+58h] [xbp-38h]
  int v154; // [xsp+64h] [xbp-2Ch]
  __int64 v155; // [xsp+68h] [xbp-28h]
  int v156; // [xsp+74h] [xbp-1Ch]
  __int64 v157; // [xsp+78h] [xbp-18h]
  __int64 v158; // [xsp+80h] [xbp-10h]
  __int64 v159; // [xsp+88h] [xbp-8h]

  v158 = (unsigned int)(a2 + 16);
  v141 = readl_relaxed_10((unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v158));
  v153 = (unsigned int)(a2 + 20);
  v139 = readl_relaxed_10((unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v153));
  v155 = (unsigned int)(a2 + 24);
  v147 = readl_relaxed_10((unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v155));
  v159 = (unsigned int)(a2 + 28);
  v146 = readl_relaxed_10((unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v159));
  v157 = (unsigned int)(a2 + 4);
  v6 = readl_relaxed_10((unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v157));
  v7 = *((unsigned __int16 *)a3 + 38);
  v8 = *((unsigned __int16 *)a3 + 40);
  v9 = a2 + 160;
  v151 = a3[1];
  v152 = a3[2];
  v154 = *a3;
  v137 = *((unsigned __int16 *)a3 + 100);
  v138 = *((unsigned __int16 *)a3 + 96);
  v156 = v6;
  v144 = *((unsigned __int16 *)a3 + 97);
  v145 = *((unsigned __int16 *)a3 + 108);
  v140 = *((unsigned __int16 *)a3 + 92);
  v142 = *((unsigned __int16 *)a3 + 88);
  v143 = *((unsigned __int16 *)a3 + 101);
  v10 = a3[23];
  v148 = *((unsigned __int16 *)a3 + 93);
  v149 = *((unsigned __int16 *)a3 + 89);
  v11 = ((a3[32] & 0x7F) << 24) | ((a3[31] & 0x7F) << 8);
  v150 = *((unsigned __int16 *)a3 + 109);
  v132 = a3[24];
  v133 = *((unsigned __int16 *)a3 + 70);
  v136 = a3[38];
  v134 = a3[36];
  v135 = *((unsigned __int16 *)a3 + 74);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_RE_PRELOAD + sspp_blk_off", *(_DWORD *)(a1 + 8) + v9, v11);
  writel_relaxed_8(v11, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v9));
  v12 = *(_DWORD *)(a1 + 24);
  v13 = 32 - __clz(v12);
  if ( v12 )
    v14 = v13;
  else
    v14 = 0;
  sde_reglog_log(v14, v11, *(_DWORD *)(a1 + 8) + v9);
  v15 = a2 + 164;
  v16 = a3[15];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err(
      "[%s:0x%X] <= 0x%X\n",
      "QSEED3_CAC_RE_PHASE_INIT_Y_V + sspp_blk_off",
      *(_DWORD *)(a1 + 8) + v15,
      v16 & 0x1FFFFF);
  writel_relaxed_8(v16 & 0x1FFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v15));
  v17 = *(_DWORD *)(a1 + 24);
  v18 = 32 - __clz(v17);
  if ( v17 )
    v19 = v18;
  else
    v19 = 0;
  sde_reglog_log(v19, v16 & 0x1FFFFF, *(_DWORD *)(a1 + 8) + v15);
  v20 = a2 + 168;
  v21 = a3[16];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err(
      "[%s:0x%X] <= 0x%X\n",
      "QSEED3_CAC_RE_PHASE_INIT_UV_V + sspp_blk_off",
      *(_DWORD *)(a1 + 8) + v20,
      v21 & 0x1FFFFF);
  writel_relaxed_8(v21 & 0x1FFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v20));
  v22 = *(_DWORD *)(a1 + 24);
  v23 = 32 - __clz(v22);
  if ( v22 )
    v24 = v23;
  else
    v24 = 0;
  sde_reglog_log(v24, v21 & 0x1FFFFF, *(_DWORD *)(a1 + 8) + v20);
  v25 = a2 + 172;
  v26 = a3[3];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_LE_PHASE_INIT2_Y_H + sspp_blk_off", *(_DWORD *)(a1 + 8) + v25, v26);
  writel_relaxed_8(v26, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v25));
  v27 = *(_DWORD *)(a1 + 24);
  v28 = 32 - __clz(v27);
  if ( v27 )
    v29 = v28;
  else
    v29 = 0;
  sde_reglog_log(v29, v26, *(_DWORD *)(a1 + 8) + v25);
  v30 = a2 + 180;
  v31 = a3[4];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_LE_PHASE_INIT2_UV_H + sspp_blk_off", *(_DWORD *)(a1 + 8) + v30, v31);
  writel_relaxed_8(v31, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v30));
  v32 = *(_DWORD *)(a1 + 24);
  v33 = 32 - __clz(v32);
  if ( v32 )
    v34 = v33;
  else
    v34 = 0;
  sde_reglog_log(v34, v31, *(_DWORD *)(a1 + 8) + v30);
  v35 = a2 + 176;
  v36 = a3[7];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_LE_PHASE_INIT2_Y_V + sspp_blk_off", *(_DWORD *)(a1 + 8) + v35, v36);
  writel_relaxed_8(v36, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v35));
  v37 = *(_DWORD *)(a1 + 24);
  v38 = 32 - __clz(v37);
  if ( v37 )
    v39 = v38;
  else
    v39 = 0;
  sde_reglog_log(v39, v36, *(_DWORD *)(a1 + 8) + v35);
  v40 = a2 + 184;
  v41 = a3[8];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_LE_PHASE_INIT2_UV_V + sspp_blk_off", *(_DWORD *)(a1 + 8) + v40, v41);
  writel_relaxed_8(v41, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v40));
  v42 = *(_DWORD *)(a1 + 24);
  v43 = 32 - __clz(v42);
  if ( v42 )
    v44 = v43;
  else
    v44 = 0;
  sde_reglog_log(v44, v41, *(_DWORD *)(a1 + 8) + v40);
  v45 = a3[11];
  v46 = a2 + 188;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_RE_PHASE_INIT2_Y_V + sspp_blk_off", *(_DWORD *)(a1 + 8) + v46, v45);
  v47 = v7 | (v10 << 16);
  writel_relaxed_8(v45, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v46));
  v48 = *(_DWORD *)(a1 + 24);
  v49 = 32 - __clz(v48);
  if ( v48 )
    v50 = v49;
  else
    v50 = 0;
  sde_reglog_log(v50, v45, *(_DWORD *)(a1 + 8) + v46);
  v51 = a3[12];
  v52 = a2 + 192;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_RE_PHASE_INIT2_UV_V + sspp_blk_off", *(_DWORD *)(a1 + 8) + v52, v51);
  v53 = v8 | (v132 << 16);
  writel_relaxed_8(v51, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v52));
  v54 = *(_DWORD *)(a1 + 24);
  v55 = 32 - __clz(v54);
  if ( v54 )
    v56 = v55;
  else
    v56 = 0;
  sde_reglog_log(v56, v51, *(_DWORD *)(a1 + 8) + v52);
  v57 = a2 + 196;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_LE_Y + sspp_blk_off", *(_DWORD *)(a1 + 8) + v57, v47);
  writel_relaxed_8(v47, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v57));
  v58 = *(_DWORD *)(a1 + 24);
  v59 = 32 - __clz(v58);
  if ( v58 )
    v60 = v59;
  else
    v60 = 0;
  sde_reglog_log(v60, v47, *(_DWORD *)(a1 + 8) + v57);
  v61 = a2 + 200;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_LE_UV + sspp_blk_off", *(_DWORD *)(a1 + 8) + v61, v53);
  writel_relaxed_8(v53, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v61));
  v62 = *(_DWORD *)(a1 + 24);
  v63 = 32 - __clz(v62);
  if ( v62 )
    v64 = v63;
  else
    v64 = 0;
  sde_reglog_log(v64, v53, *(_DWORD *)(a1 + 8) + v61);
  v65 = a2 + 204;
  v66 = a3[27] << 16;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_RE_Y + sspp_blk_off", *(_DWORD *)(a1 + 8) + v65, v66);
  v67 = v133 | (v134 << 16);
  writel_relaxed_8(v66, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v65));
  v68 = *(_DWORD *)(a1 + 24);
  v69 = 32 - __clz(v68);
  if ( v68 )
    v70 = v69;
  else
    v70 = 0;
  sde_reglog_log(v70, v66, *(_DWORD *)(a1 + 8) + v65);
  v71 = a2 + 208;
  v72 = a3[28] << 16;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_CAC_RE_UV + sspp_blk_off", *(_DWORD *)(a1 + 8) + v71, v72);
  v73 = v135 | (v136 << 16);
  writel_relaxed_8(v72, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v71));
  v74 = *(_DWORD *)(a1 + 24);
  v75 = 32 - __clz(v74);
  if ( v74 )
    v76 = v75;
  else
    v76 = 0;
  sde_reglog_log(v76, v72, *(_DWORD *)(a1 + 8) + v71);
  v77 = a2 + 212;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DST_UV_SIZE + sspp_blk_off", *(_DWORD *)(a1 + 8) + v77, v67);
  writel_relaxed_8(v67, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v77));
  v78 = *(_DWORD *)(a1 + 24);
  v79 = 32 - __clz(v78);
  if ( v78 )
    v80 = v79;
  else
    v80 = 0;
  sde_reglog_log(v80, v67, *(_DWORD *)(a1 + 8) + v77);
  v81 = a2 + 216;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DST_LE_OFFSET + sspp_blk_off", *(_DWORD *)(a1 + 8) + v81, v73);
  v82 = v141 | (v138 << 29) | (v142 << 28);
  writel_relaxed_8(v73, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v81));
  v83 = *(_DWORD *)(a1 + 24);
  v84 = 32 - __clz(v83);
  if ( v83 )
    v85 = v84;
  else
    v85 = 0;
  sde_reglog_log(v85, v73, *(_DWORD *)(a1 + 8) + v81);
  v86 = a2 + 220;
  v87 = a3[39] << 16;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_DST_RE_OFFSET + sspp_blk_off", *(_DWORD *)(a1 + 8) + v86, v87);
  v88 = v139 | (v137 << 29) | (v140 << 28) | (v145 << 30);
  writel_relaxed_8(v87, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v86));
  v89 = *(_DWORD *)(a1 + 24);
  v90 = 32 - __clz(v89);
  if ( v89 )
    v91 = v90;
  else
    v91 = 0;
  sde_reglog_log(v91, v87, *(_DWORD *)(a1 + 8) + v86);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PHASE_STEP_Y_H + sspp_blk_off", *(_DWORD *)(a1 + 8) + v158, v82);
  v92 = v147 | (v144 << 29) | (v149 << 28);
  writel_relaxed_8(v82, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v158));
  v93 = *(_DWORD *)(a1 + 24);
  v94 = 32 - __clz(v93);
  if ( v93 )
    v95 = v94;
  else
    v95 = 0;
  sde_reglog_log(v95, v82, *(_DWORD *)(a1 + 8) + v158);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PHASE_STEP_Y_V + sspp_blk_off", *(_DWORD *)(a1 + 8) + v153, v88);
  v96 = v146 | (v143 << 29) | (v148 << 28) | (v150 << 30);
  writel_relaxed_8(v88, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v153));
  v97 = *(_DWORD *)(a1 + 24);
  v98 = 32 - __clz(v97);
  if ( v97 )
    v99 = v98;
  else
    v99 = 0;
  sde_reglog_log(v99, v88, *(_DWORD *)(a1 + 8) + v153);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PHASE_STEP_UV_H + sspp_blk_off", *(_DWORD *)(a1 + 8) + v155, v92);
  writel_relaxed_8(v92, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v155));
  v100 = *(_DWORD *)(a1 + 24);
  v101 = 32 - __clz(v100);
  if ( v100 )
    v102 = v101;
  else
    v102 = 0;
  sde_reglog_log(v102, v92, *(_DWORD *)(a1 + 8) + v155);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_PHASE_STEP_UV_V + sspp_blk_off", *(_DWORD *)(a1 + 8) + v159, v96);
  v103 = ((v152 & 3) << 24) | ((v151 & 3) << 20);
  v104 = v156 | (2 * v154);
  writel_relaxed_8(v96, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v159));
  v105 = *(_DWORD *)(a1 + 24);
  v106 = 32 - __clz(v105);
  if ( v105 )
    v107 = v106;
  else
    v107 = 0;
  sde_reglog_log(v107, v96, *(_DWORD *)(a1 + 8) + v159);
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_OP_MODE + sspp_blk_off", *(_DWORD *)(a1 + 8) + v157, v104 | v103);
  writel_relaxed_8(v104 | v103, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v157));
  v108 = *(_DWORD *)(a1 + 24);
  v109 = 32 - __clz(v108);
  if ( v108 )
    v110 = v109;
  else
    v110 = 0;
  sde_reglog_log(v110, v104 | v103, *(_DWORD *)(a1 + 8) + v157);
  v111 = a2 + 104;
  v112 = a3[40];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err(
      "[%s:0x%X] <= 0x%X\n",
      "QSEED3_ASYM_PHASE_STEP_H + sspp_blk_off",
      *(_DWORD *)(a1 + 8) + v111,
      v112 & 0xFFFFFF);
  writel_relaxed_8(v112 & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v111));
  v113 = *(_DWORD *)(a1 + 24);
  v114 = 32 - __clz(v113);
  if ( v113 )
    v115 = v114;
  else
    v115 = 0;
  sde_reglog_log(v115, v112 & 0xFFFFFF, *(_DWORD *)(a1 + 8) + v111);
  v116 = a2 + 108;
  v117 = a3[41];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err(
      "[%s:0x%X] <= 0x%X\n",
      "QSEED3_ASYM_PHASE_STEP_V + sspp_blk_off",
      *(_DWORD *)(a1 + 8) + v116,
      v117 & 0xFFFFFF);
  writel_relaxed_8(v117 & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v116));
  v118 = *(_DWORD *)(a1 + 24);
  v119 = 32 - __clz(v118);
  if ( v118 )
    v120 = v119;
  else
    v120 = 0;
  sde_reglog_log(v120, v117 & 0xFFFFFF, *(_DWORD *)(a1 + 8) + v116);
  v121 = a2 + 136;
  v122 = a3[42];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err(
      "[%s:0x%X] <= 0x%X\n",
      "QSEED3_FOV_RE_PHASE_STEP2_V + sspp_blk_off",
      *(_DWORD *)(a1 + 8) + v121,
      v122 & 0xFFFFFF);
  writel_relaxed_8(v122 & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v121));
  v123 = *(_DWORD *)(a1 + 24);
  v124 = 32 - __clz(v123);
  if ( v123 )
    v125 = v124;
  else
    v125 = 0;
  sde_reglog_log(v125, v122 & 0xFFFFFF, *(_DWORD *)(a1 + 8) + v121);
  v126 = a2 + 140;
  v127 = a3[43];
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err(
      "[%s:0x%X] <= 0x%X\n",
      "QSEED3_FOV_RE_ASYM_PHASE_STEP_V + sspp_blk_off",
      *(_DWORD *)(a1 + 8) + v126,
      v127 & 0xFFFFFF);
  writel_relaxed_8(v127 & 0xFFFFFF, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v126));
  v128 = *(_DWORD *)(a1 + 24);
  v129 = 32 - __clz(v128);
  if ( v128 )
    v130 = v129;
  else
    v130 = 0;
  return sde_reglog_log(v130, v127 & 0xFFFFFF, *(_DWORD *)(a1 + 8) + v126);
}
