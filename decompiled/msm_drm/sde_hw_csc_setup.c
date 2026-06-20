__int64 __fastcall sde_hw_csc_setup(__int64 result, unsigned int a2, _DWORD *a3, char a4, int a5)
{
  char v5; // w22
  __int64 v6; // x19
  int v9; // w26
  unsigned int v10; // w28
  int v11; // w27
  unsigned int v12; // w8
  unsigned int v13; // w9
  __int64 v14; // x0
  int v15; // w26
  unsigned int v16; // w28
  int v17; // w27
  unsigned int v18; // w8
  unsigned int v19; // w9
  __int64 v20; // x0
  int v21; // w26
  unsigned int v22; // w28
  int v23; // w27
  unsigned int v24; // w8
  unsigned int v25; // w9
  __int64 v26; // x0
  int v27; // w26
  unsigned int v28; // w28
  int v29; // w27
  unsigned int v30; // w8
  unsigned int v31; // w9
  __int64 v32; // x0
  int v33; // w26
  unsigned int v34; // w28
  int v35; // w27
  unsigned int v36; // w8
  unsigned int v37; // w9
  __int64 v38; // x0
  int v39; // w26
  unsigned int v40; // w27
  int v41; // w22
  unsigned int v42; // w8
  unsigned int v43; // w9
  __int64 v44; // x0
  unsigned int v45; // w26
  unsigned int v46; // w22
  unsigned int v47; // w8
  unsigned int v48; // w9
  __int64 v49; // x0
  unsigned int v50; // w26
  unsigned int v51; // w22
  unsigned int v52; // w8
  unsigned int v53; // w9
  __int64 v54; // x0
  unsigned int v55; // w26
  unsigned int v56; // w22
  unsigned int v57; // w8
  unsigned int v58; // w9
  __int64 v59; // x0
  unsigned int v60; // w26
  unsigned int v61; // w22
  unsigned int v62; // w8
  unsigned int v63; // w9
  __int64 v64; // x0
  unsigned int v65; // w26
  unsigned int v66; // w22
  unsigned int v67; // w8
  unsigned int v68; // w9
  __int64 v69; // x0
  unsigned int v70; // w20
  unsigned int v71; // w21
  unsigned int v72; // w8
  unsigned int v73; // w9
  __int64 v74; // x0

  if ( (a4 & 1) != 0 )
    v5 = 16;
  else
    v5 = 8;
  if ( a5 != 1 )
  {
    v6 = result;
    if ( result )
    {
      if ( a3 )
      {
        sde_hw_csc_matrix_coeff_setup(result, a2, a3, 7);
        v9 = a3[16];
        v10 = a2 + 20;
        v11 = a3[15] << v5;
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x14", *(_DWORD *)(v6 + 8) + v10, v11 | v9);
        writel_relaxed_8(v11 | v9, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v10));
        v12 = *(_DWORD *)(v6 + 24);
        v13 = 32 - __clz(v12);
        if ( v12 )
          v14 = v13;
        else
          v14 = 0;
        sde_reglog_log(v14, v11 | v9, *(_DWORD *)(v6 + 8) + v10);
        v15 = a3[18];
        v16 = a2 + 24;
        v17 = a3[17] << v5;
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x18", *(_DWORD *)(v6 + 8) + v16, v17 | v15);
        writel_relaxed_8(v17 | v15, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v16));
        v18 = *(_DWORD *)(v6 + 24);
        v19 = 32 - __clz(v18);
        if ( v18 )
          v20 = v19;
        else
          v20 = 0;
        sde_reglog_log(v20, v17 | v15, *(_DWORD *)(v6 + 8) + v16);
        v21 = a3[20];
        v22 = a2 + 28;
        v23 = a3[19] << v5;
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x1c", *(_DWORD *)(v6 + 8) + v22, v23 | v21);
        writel_relaxed_8(v23 | v21, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v22));
        v24 = *(_DWORD *)(v6 + 24);
        v25 = 32 - __clz(v24);
        if ( v24 )
          v26 = v25;
        else
          v26 = 0;
        sde_reglog_log(v26, v23 | v21, *(_DWORD *)(v6 + 8) + v22);
        v27 = a3[22];
        v28 = a2 + 32;
        v29 = a3[21] << v5;
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x20", *(_DWORD *)(v6 + 8) + v28, v29 | v27);
        writel_relaxed_8(v29 | v27, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v28));
        v30 = *(_DWORD *)(v6 + 24);
        v31 = 32 - __clz(v30);
        if ( v30 )
          v32 = v31;
        else
          v32 = 0;
        sde_reglog_log(v32, v29 | v27, *(_DWORD *)(v6 + 8) + v28);
        v33 = a3[24];
        v34 = a2 + 36;
        v35 = a3[23] << v5;
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x24", *(_DWORD *)(v6 + 8) + v34, v35 | v33);
        writel_relaxed_8(v35 | v33, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v34));
        v36 = *(_DWORD *)(v6 + 24);
        v37 = 32 - __clz(v36);
        if ( v36 )
          v38 = v37;
        else
          v38 = 0;
        sde_reglog_log(v38, v35 | v33, *(_DWORD *)(v6 + 8) + v34);
        v39 = a3[26];
        v40 = a2 + 40;
        v41 = a3[25] << v5;
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x28", *(_DWORD *)(v6 + 8) + v40, v41 | v39);
        writel_relaxed_8(v41 | v39, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v40));
        v42 = *(_DWORD *)(v6 + 24);
        v43 = 32 - __clz(v42);
        if ( v42 )
          v44 = v43;
        else
          v44 = 0;
        sde_reglog_log(v44, v41 | v39, *(_DWORD *)(v6 + 8) + v40);
        v45 = a2 + 44;
        v46 = a3[9];
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x2c", *(_DWORD *)(v6 + 8) + v45, v46);
        writel_relaxed_8(v46, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v45));
        v47 = *(_DWORD *)(v6 + 24);
        v48 = 32 - __clz(v47);
        if ( v47 )
          v49 = v48;
        else
          v49 = 0;
        sde_reglog_log(v49, v46, *(_DWORD *)(v6 + 8) + v45);
        v50 = a2 + 48;
        v51 = a3[10];
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x30", *(_DWORD *)(v6 + 8) + v50, v51);
        writel_relaxed_8(v51, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v50));
        v52 = *(_DWORD *)(v6 + 24);
        v53 = 32 - __clz(v52);
        if ( v52 )
          v54 = v53;
        else
          v54 = 0;
        sde_reglog_log(v54, v51, *(_DWORD *)(v6 + 8) + v50);
        v55 = a2 + 52;
        v56 = a3[11];
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x34", *(_DWORD *)(v6 + 8) + v55, v56);
        writel_relaxed_8(v56, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v55));
        v57 = *(_DWORD *)(v6 + 24);
        v58 = 32 - __clz(v57);
        if ( v57 )
          v59 = v58;
        else
          v59 = 0;
        sde_reglog_log(v59, v56, *(_DWORD *)(v6 + 8) + v55);
        v60 = a2 + 56;
        v61 = a3[12];
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x38", *(_DWORD *)(v6 + 8) + v60, v61);
        writel_relaxed_8(v61, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v60));
        v62 = *(_DWORD *)(v6 + 24);
        v63 = 32 - __clz(v62);
        if ( v62 )
          v64 = v63;
        else
          v64 = 0;
        sde_reglog_log(v64, v61, *(_DWORD *)(v6 + 8) + v60);
        v65 = a2 + 60;
        v66 = a3[13];
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x3c", *(_DWORD *)(v6 + 8) + v65, v66);
        writel_relaxed_8(v66, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v65));
        v67 = *(_DWORD *)(v6 + 24);
        v68 = 32 - __clz(v67);
        if ( v67 )
          v69 = v68;
        else
          v69 = 0;
        sde_reglog_log(v69, v66, *(_DWORD *)(v6 + 8) + v65);
        v70 = a2 + 64;
        v71 = a3[14];
        if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x40", *(_DWORD *)(v6 + 8) + v70, v71);
        writel_relaxed_8(v71, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v70));
        v72 = *(_DWORD *)(v6 + 24);
        v73 = 32 - __clz(v72);
        if ( v72 )
          v74 = v73;
        else
          v74 = 0;
        return sde_reglog_log(v74, v71, *(_DWORD *)(v6 + 8) + v70);
      }
    }
  }
  return result;
}
