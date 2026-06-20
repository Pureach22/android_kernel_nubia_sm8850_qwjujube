__int64 __fastcall sde_write_3d_gamut(const void *a1, unsigned int *a2, unsigned int a3, int *a4, unsigned int a5)
{
  int v7; // w1
  int v9; // w8
  int v10; // w28
  __int64 v11; // x21
  int v13; // w8
  unsigned int *v14; // x22
  unsigned int *v15; // x25
  unsigned int *v16; // x26
  __int64 v17; // x27
  unsigned int v18; // t1
  unsigned int *v19; // x22
  __int64 v20; // x27
  unsigned int v21; // t1
  __int64 v22; // x22
  unsigned int v23; // t1
  unsigned int v24; // t1
  __int64 v25; // x2
  __int64 v26; // x25
  unsigned int v27; // w23
  __int64 v28; // x21
  unsigned int *v29; // x22
  unsigned int v30; // t1
  unsigned int v31; // w23
  __int64 v32; // x22
  unsigned int *v33; // x21
  unsigned int v34; // t1
  unsigned int v35; // w23
  unsigned int *v36; // x21
  unsigned int v37; // t1
  int v38; // [xsp+8h] [xbp-18h]
  unsigned int v39; // [xsp+Ch] [xbp-14h]
  unsigned int *v41; // [xsp+18h] [xbp-8h]

  if ( !a4 )
    return _drm_err("invalid payload %pK opcode %pK hw %pK\n", a2, nullptr, a1);
  v7 = a2[2];
  switch ( v7 )
  {
    case 3:
      v11 = 550;
      if ( (*a4 & 0xC) == 8 )
        v13 = 224;
      else
        v13 = 16;
      v38 = v13;
      v39 = a5;
      if ( (*a4 & 0xC) == 8 )
        v9 = 12;
      else
        v9 = 8;
      if ( (*a4 & 0xC) == 8 )
        v10 = 640;
      else
        v10 = 0;
      *a4 = v9;
      break;
    case 2:
      v9 = 4;
      v10 = 1248;
      *a4 = 4;
      v11 = 32;
      v38 = 224;
      v39 = a5;
      break;
    case 1:
      v9 = 0;
      v10 = 0;
      *a4 = 0;
      v11 = 1229;
      v38 = 16;
      v39 = a5;
      break;
    default:
      return _drm_err("invalid mode %d\n", v7);
  }
  v14 = a2 + 52;
  v41 = a2;
  v15 = a2 + 4968;
  v16 = a2 + 7426;
  *a4 = v9 | (2 * (*a2 & 1)) | 1;
  sde_reg_write(a1, a3 + 4, v10 | 0x1000u, "base + GAMUT_TABLE_SEL_OFF");
  v17 = v11;
  do
  {
    sde_reg_write(a1, a3 + 12, *(v14 - 1), "base + GAMUT_LOWER_COLOR_OFF");
    v18 = *v14;
    v14 += 2;
    sde_reg_write(a1, a3 + 8, v18, "base + GAMUT_UPPER_COLOR_OFF");
    --v17;
  }
  while ( v17 );
  sde_reg_write(a1, a3 + 4, v10 | 0x2000u, "base + GAMUT_TABLE_SEL_OFF");
  v19 = v41 + 2510;
  v20 = v11;
  do
  {
    sde_reg_write(a1, a3 + 12, *(v19 - 1), "base + GAMUT_LOWER_COLOR_OFF");
    v21 = *v19;
    v19 += 2;
    sde_reg_write(a1, a3 + 8, v21, "base + GAMUT_UPPER_COLOR_OFF");
    --v20;
  }
  while ( v20 );
  sde_reg_write(a1, a3 + 4, v10 | 0x4000u, "base + GAMUT_TABLE_SEL_OFF");
  v22 = v11;
  do
  {
    sde_reg_write(a1, a3 + 12, *(v15 - 1), "base + GAMUT_LOWER_COLOR_OFF");
    v23 = *v15;
    v15 += 2;
    sde_reg_write(a1, a3 + 8, v23, "base + GAMUT_UPPER_COLOR_OFF");
    --v22;
  }
  while ( v22 );
  sde_reg_write(a1, a3 + 4, v10 | 0x8000u, "base + GAMUT_TABLE_SEL_OFF");
  do
  {
    sde_reg_write(a1, a3 + 12, *(v16 - 1), "base + GAMUT_LOWER_COLOR_OFF");
    v24 = *v16;
    v16 += 2;
    sde_reg_write(a1, a3 + 8, v24, "base + GAMUT_UPPER_COLOR_OFF");
    --v11;
  }
  while ( v11 );
  v25 = (unsigned int)*a4;
  if ( (v25 & 2) != 0 )
  {
    if ( v38 == 16 )
      v26 = 16;
    else
      v26 = v39;
    if ( (_DWORD)v26 )
    {
      v27 = v38 + a3;
      v28 = v26;
      v29 = v41 + 3;
      do
      {
        v30 = *v29++;
        sde_reg_write(a1, v27, v30, "scale_tbl_off + (j * sizeof(u32))");
        --v28;
        v27 += 4;
      }
      while ( v28 );
      v31 = v38 + a3 + 4 * v26;
      v32 = v26;
      v33 = v41 + 19;
      do
      {
        v34 = *v33++;
        sde_reg_write(a1, v31, v34, "scale_tbl_off + (j * sizeof(u32))");
        --v32;
        v31 += 4;
      }
      while ( v32 );
      v35 = v38 + a3 + 8 * v26;
      v36 = v41 + 35;
      do
      {
        v37 = *v36++;
        sde_reg_write(a1, v35, v37, "scale_tbl_off + (j * sizeof(u32))");
        --v26;
        v35 += 4;
      }
      while ( v26 );
    }
    v25 = (unsigned int)*a4;
  }
  return sde_reg_write(a1, a3, v25, "base");
}
