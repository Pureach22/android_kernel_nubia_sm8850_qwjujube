__int64 __fastcall sde_hw_csc_matrix_coeff_setup(__int64 result, unsigned int a2, _DWORD *a3, char a4)
{
  __int64 v6; // x19
  int v8; // w23
  unsigned int v9; // w8
  unsigned int v10; // w9
  __int64 v11; // x0
  unsigned int v12; // w27
  int v13; // w23
  unsigned int v14; // w8
  unsigned int v15; // w9
  __int64 v16; // x0
  unsigned int v17; // w27
  int v18; // w23
  unsigned int v19; // w8
  unsigned int v20; // w9
  __int64 v21; // x0
  unsigned int v22; // w27
  int v23; // w23
  unsigned int v24; // w8
  unsigned int v25; // w9
  __int64 v26; // x0
  unsigned int v27; // w21
  int v28; // w20
  unsigned int v29; // w8
  unsigned int v30; // w9
  __int64 v31; // x0

  if ( result && a3 )
  {
    v6 = result;
    v8 = (*a3 >> a4) & 0x1FFF | (((a3[1] >> a4) & 0x1FFF) << 16);
    if ( (sde_hw_util_log_mask & *(_DWORD *)(result + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off", *(_DWORD *)(result + 8) + a2, v8);
    writel_relaxed_8(v8, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + a2));
    v9 = *(_DWORD *)(v6 + 24);
    v10 = 32 - __clz(v9);
    if ( v9 )
      v11 = v10;
    else
      v11 = 0;
    sde_reglog_log(v11, v8, *(_DWORD *)(v6 + 8) + a2);
    v12 = a2 + 4;
    v13 = (a3[2] >> a4) & 0x1FFF | (((a3[3] >> a4) & 0x1FFF) << 16);
    if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x4", *(_DWORD *)(v6 + 8) + v12, v13);
    writel_relaxed_8(v13, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v12));
    v14 = *(_DWORD *)(v6 + 24);
    v15 = 32 - __clz(v14);
    if ( v14 )
      v16 = v15;
    else
      v16 = 0;
    sde_reglog_log(v16, v13, *(_DWORD *)(v6 + 8) + v12);
    v17 = a2 + 8;
    v18 = (a3[4] >> a4) & 0x1FFF | (((a3[5] >> a4) & 0x1FFF) << 16);
    if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x8", *(_DWORD *)(v6 + 8) + v17, v18);
    writel_relaxed_8(v18, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v17));
    v19 = *(_DWORD *)(v6 + 24);
    v20 = 32 - __clz(v19);
    if ( v19 )
      v21 = v20;
    else
      v21 = 0;
    sde_reglog_log(v21, v18, *(_DWORD *)(v6 + 8) + v17);
    v22 = a2 + 12;
    v23 = (a3[6] >> a4) & 0x1FFF | (((a3[7] >> a4) & 0x1FFF) << 16);
    if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0xc", *(_DWORD *)(v6 + 8) + v22, v23);
    writel_relaxed_8(v23, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v22));
    v24 = *(_DWORD *)(v6 + 24);
    v25 = 32 - __clz(v24);
    if ( v24 )
      v26 = v25;
    else
      v26 = 0;
    sde_reglog_log(v26, v23, *(_DWORD *)(v6 + 8) + v22);
    v27 = a2 + 16;
    v28 = a3[8] >> a4;
    if ( (sde_hw_util_log_mask & *(_DWORD *)(v6 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "csc_reg_off + 0x10", *(_DWORD *)(v6 + 8) + v27, v28 & 0x1FFF);
    writel_relaxed_8(v28 & 0x1FFF, (unsigned int *)(*(_QWORD *)v6 + *(unsigned int *)(v6 + 8) + v27));
    v29 = *(_DWORD *)(v6 + 24);
    v30 = 32 - __clz(v29);
    if ( v29 )
      v31 = v30;
    else
      v31 = 0;
    return sde_reglog_log(v31, v28 & 0x1FFF, *(_DWORD *)(v6 + 8) + v27);
  }
  return result;
}
