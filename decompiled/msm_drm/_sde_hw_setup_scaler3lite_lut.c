__int64 __fastcall sde_hw_setup_scaler3lite_lut(__int64 a1, __int64 a2, int a3)
{
  unsigned int v3; // w22
  unsigned int v6; // w20
  unsigned int v7; // w8
  unsigned int v8; // w9
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x8
  unsigned int v12; // w9
  __int64 v13; // x26
  char v14; // w9
  unsigned int v15; // w10
  __int64 v16; // x25
  __int64 v17; // x21
  int v18; // w27
  __int64 v19; // x22
  unsigned int v20; // w8
  unsigned int v21; // w9
  __int64 v22; // x0
  unsigned int v23; // w23
  __int64 v24; // x28
  int v25; // w26
  __int64 v26; // x21
  unsigned int v27; // w8
  unsigned int v28; // w9
  __int64 v29; // x0
  unsigned int v30; // w23
  unsigned int v31; // w20
  unsigned int v32; // w8
  unsigned int v33; // w9
  __int64 v34; // x0
  int v36; // [xsp+8h] [xbp-8h]

  v3 = *(unsigned __int8 *)(a2 + 284);
  v6 = a3 + 96;
  if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
    _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3L_DIR_FILTER_WEIGHT + offset", *(_DWORD *)(a1 + 8) + v6, v3);
  writel_relaxed_8(v3, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v6));
  v7 = *(_DWORD *)(a1 + 24);
  v8 = 32 - __clz(v7);
  if ( v7 )
    v9 = v8;
  else
    v9 = 0;
  result = sde_reglog_log(v9, v3, *(_DWORD *)(a1 + 8) + v6);
  v11 = *(_QWORD *)(a2 + 224);
  if ( v11 )
  {
    v36 = *(_DWORD *)(a2 + 168);
    if ( (v36 & 0x10) != 0 && (v12 = *(_DWORD *)(a2 + 184), v12 <= 9) && *(_QWORD *)(a2 + 232) == 1320 )
    {
      v13 = v11 + 132LL * v12;
      v14 = 0;
      if ( (v36 & 0x20) == 0 )
        goto LABEL_18;
    }
    else
    {
      v13 = 0;
      v14 = 1;
      if ( (v36 & 0x20) == 0 )
        goto LABEL_18;
    }
    v15 = *(_DWORD *)(a2 + 188);
    if ( v15 <= 9 && *(_QWORD *)(a2 + 232) == 1320 )
    {
      v16 = v11 + 132LL * v15;
      if ( v13 )
      {
LABEL_20:
        v17 = 0;
        v18 = a3 + 256;
        do
        {
          v23 = *(_DWORD *)(v13 + v17);
          if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
            _drm_err("[%s:0x%X] <= 0x%X\n", "lut_addr", v18 + v17 + *(_DWORD *)(a1 + 8), v23);
          v19 = v17 + 4;
          writel_relaxed_8(v23, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + (unsigned int)(v18 + v17)));
          v20 = *(_DWORD *)(a1 + 24);
          v21 = 32 - __clz(v20);
          if ( v20 )
            v22 = v21;
          else
            v22 = 0;
          result = sde_reglog_log(v22, v23, v18 + (int)v17 + *(_DWORD *)(a1 + 8));
          v17 += 4;
        }
        while ( v19 != 132 );
      }
LABEL_28:
      if ( v16 )
      {
        v24 = 0;
        v25 = a3 + 768;
        do
        {
          v30 = *(_DWORD *)(v16 + v24);
          if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
            _drm_err("[%s:0x%X] <= 0x%X\n", "lut_addr", v25 + v24 + *(_DWORD *)(a1 + 8), v30);
          v26 = v24 + 4;
          writel_relaxed_8(v30, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + (unsigned int)(v25 + v24)));
          v27 = *(_DWORD *)(a1 + 24);
          v28 = 32 - __clz(v27);
          if ( v27 )
            v29 = v28;
          else
            v29 = 0;
          result = sde_reglog_log(v29, v30, v25 + (int)v24 + *(_DWORD *)(a1 + 8));
          v24 += 4;
        }
        while ( v26 != 132 );
      }
      goto LABEL_37;
    }
LABEL_18:
    if ( (v14 & 1) != 0 )
    {
LABEL_37:
      if ( (v36 & 1) != 0 )
      {
        v31 = a3 + 76;
        if ( (sde_hw_util_log_mask & *(_DWORD *)(a1 + 24)) != 0 && (_drm_debug & 2) != 0 )
          _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3L_COEF_LUT_CTRL + offset", *(_DWORD *)(a1 + 8) + v31, 1);
        writel_relaxed_8(1u, (unsigned int *)(*(_QWORD *)a1 + *(unsigned int *)(a1 + 8) + v31));
        v32 = *(_DWORD *)(a1 + 24);
        v33 = 32 - __clz(v32);
        if ( v32 )
          v34 = v33;
        else
          v34 = 0;
        return sde_reglog_log(v34, 1, *(_DWORD *)(a1 + 8) + v31);
      }
      return result;
    }
    v16 = 0;
    if ( v13 )
      goto LABEL_20;
    goto LABEL_28;
  }
  return result;
}
