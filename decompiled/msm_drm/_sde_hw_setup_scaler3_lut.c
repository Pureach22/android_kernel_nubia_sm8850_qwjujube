__int64 __fastcall sde_hw_setup_scaler3_lut(__int64 result, __int64 a2, int a3)
{
  __int64 v3; // x19
  int v4; // w8
  int v5; // w8
  unsigned int v6; // w9
  unsigned int v7; // w9
  unsigned int v8; // w9
  unsigned int v9; // w9
  __int64 v10; // x9
  __int64 v11; // x27
  __int64 v12; // x25
  unsigned int v13; // w26
  char *v14; // x8
  int v15; // w21
  unsigned int v16; // w22
  unsigned int v17; // w8
  unsigned int v18; // w9
  __int64 v19; // x0
  unsigned int v20; // w23
  unsigned int v21; // w20
  unsigned int v22; // w8
  unsigned int v23; // w9
  __int64 v24; // x0
  __int64 v26; // [xsp+8h] [xbp-58h]
  int v27; // [xsp+14h] [xbp-4Ch]
  char *v28; // [xsp+18h] [xbp-48h]
  unsigned int v29; // [xsp+24h] [xbp-3Ch]
  char v30; // [xsp+28h] [xbp-38h]
  __int64 v31; // [xsp+30h] [xbp-30h]
  __int64 v32; // [xsp+38h] [xbp-28h]
  __int64 v33; // [xsp+40h] [xbp-20h]
  __int64 v34; // [xsp+48h] [xbp-18h]
  __int64 v35; // [xsp+50h] [xbp-10h]
  __int64 v36; // [xsp+58h] [xbp-8h]

  v3 = result;
  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD *)(a2 + 168);
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = v4;
  v31 = 0;
  if ( (v4 & 2) != 0 && *(_QWORD *)(a2 + 200) == 800 )
  {
    v31 = *(_QWORD *)(a2 + 192);
    v5 = 1;
    if ( (v30 & 4) == 0 )
      goto LABEL_9;
  }
  else
  {
    v5 = 0;
    if ( (v30 & 4) == 0 )
      goto LABEL_9;
  }
  v6 = *(_DWORD *)(a2 + 176);
  if ( v6 <= 8 && *(_QWORD *)(a2 + 216) == 2160 )
  {
    v32 = *(_QWORD *)(a2 + 208) + 240LL * v6;
    v5 = 1;
  }
LABEL_9:
  if ( (v30 & 8) != 0 )
  {
    v7 = *(_DWORD *)(a2 + 180);
    if ( v7 <= 8 && *(_QWORD *)(a2 + 216) == 2160 )
    {
      v33 = *(_QWORD *)(a2 + 208) + 240LL * v7;
      v5 = 1;
    }
  }
  if ( (v30 & 0x10) != 0 )
  {
    v8 = *(_DWORD *)(a2 + 184);
    if ( v8 <= 9 && *(_QWORD *)(a2 + 232) == 2400 )
    {
      v34 = *(_QWORD *)(a2 + 224) + 240LL * v8;
      v5 = 1;
    }
  }
  if ( (v30 & 0x20) != 0 && (v9 = *(_DWORD *)(a2 + 188), v9 <= 9) && *(_QWORD *)(a2 + 232) == 2400 )
  {
    v35 = *(_QWORD *)(a2 + 224) + 240LL * v9;
  }
  else if ( !v5 )
  {
    goto LABEL_37;
  }
  v10 = 0;
  v27 = a3 + 256;
  do
  {
    v26 = v10;
    v11 = *(&v31 + v10);
    if ( v11 )
    {
      v12 = 0;
      v13 = 0;
      v28 = (char *)&sde_hw_setup_scaler3_lut_off_tbl + 32 * v10;
      do
      {
        v14 = &v28[8 * v12];
        v15 = 4 * *(_DWORD *)v14;
        if ( v15 )
        {
          v16 = v27 + *((_DWORD *)v14 + 1);
          v29 = v13 + v15;
          do
          {
            v20 = *(_DWORD *)(v11 + 4LL * v13);
            if ( (sde_hw_util_log_mask & *(_DWORD *)(v3 + 24)) != 0 && (_drm_debug & 2) != 0 )
              _drm_err("[%s:0x%X] <= 0x%X\n", "lut_addr", v16 + *(_DWORD *)(v3 + 8), v20);
            writel_relaxed_8(v20, (unsigned int *)(*(_QWORD *)v3 + *(unsigned int *)(v3 + 8) + v16));
            v17 = *(_DWORD *)(v3 + 24);
            v18 = 32 - __clz(v17);
            if ( v17 )
              v19 = v18;
            else
              v19 = 0;
            result = sde_reglog_log(v19, v20, v16 + *(_DWORD *)(v3 + 8));
            --v15;
            v16 += 4;
            ++v13;
          }
          while ( v15 );
          v13 = v29;
        }
        ++v12;
      }
      while ( v12 != 4 );
    }
    v10 = v26 + 1;
  }
  while ( v26 != 4 );
LABEL_37:
  if ( (v30 & 1) != 0 )
  {
    v21 = a3 + 76;
    if ( (sde_hw_util_log_mask & *(_DWORD *)(v3 + 24)) != 0 && (_drm_debug & 2) != 0 )
      _drm_err("[%s:0x%X] <= 0x%X\n", "QSEED3_COEF_LUT_CTRL + offset", *(_DWORD *)(v3 + 8) + v21, 1);
    writel_relaxed_8(1u, (unsigned int *)(*(_QWORD *)v3 + *(unsigned int *)(v3 + 8) + v21));
    v22 = *(_DWORD *)(v3 + 24);
    v23 = 32 - __clz(v22);
    if ( v22 )
      v24 = v23;
    else
      v24 = 0;
    result = sde_reglog_log(v24, 1, *(_DWORD *)(v3 + 8) + v21);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
