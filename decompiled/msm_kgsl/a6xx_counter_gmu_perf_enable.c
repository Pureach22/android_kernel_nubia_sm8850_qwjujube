__int64 __fastcall a6xx_counter_gmu_perf_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x20
  __int64 v7; // x0
  char v9; // w21
  int v10; // w0

  if ( a4 > 0xFF )
    return 4294967274LL;
  v5 = *a2 + 48LL * a3;
  v7 = a1 + 13200;
  if ( a3 <= 3 )
    v9 = 8 * a3;
  else
    v9 = 8 * a3 - 32;
  v10 = kgsl_regmap_read(v7);
  kgsl_regmap_write(a1 + 13200, v10 & ~(255 << v9) | (a4 << v9));
  kgsl_regmap_write(a1 + 13200, 1);
  *(_QWORD *)(v5 + 32) = 0;
  return 0;
}
