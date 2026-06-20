__int64 __fastcall a6xx_counter_gmu_xoclk_enable(__int64 a1, __int64 *a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x20
  int *v7; // x8
  int v8; // w21
  const char *v9; // x8
  __int64 v10; // x22
  unsigned int v11; // w23
  int v12; // w0
  int v13; // w8
  __int64 v14; // x20
  char v15; // w10
  char v16; // w8
  __int64 v17; // x23
  char v18; // w21
  int v19; // w0

  if ( a4 > 0xFF )
    return 4294967274LL;
  v5 = *a2;
  if ( a3 >= 6 )
  {
    v7 = *(int **)(a1 + 14264);
    v8 = *v7;
    if ( *v7 != 660 )
    {
      v9 = *((const char **)v7 + 3);
      if ( !v9 || (v10 = a1, v11 = a3, v12 = strcmp(v9, "qcom,adreno-gpu-a642l"), a3 = v11, v13 = v12, a1 = v10, v13) )
      {
        if ( v8 != 662 && v8 != 643 )
          return 4294967274LL;
      }
    }
  }
  v14 = v5 + 48LL * a3;
  v15 = a3 - 6;
  v16 = a3 - 4;
  if ( a3 <= 5 )
    v15 = a3;
  if ( (a3 & 0xFFFFFFFE) != 4 )
    v16 = v15;
  v17 = a1;
  v18 = 8 * v16;
  v19 = kgsl_regmap_read(a1 + 13200);
  kgsl_regmap_write(v17 + 13200, v19 & ~(255 << v18) | (a4 << v18));
  *(_QWORD *)(v14 + 32) = 0;
  kgsl_regmap_write(v17 + 13200, 1);
  return 0;
}
