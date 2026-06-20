__int64 __fastcall a6xx_counter_gmu_gmuclk_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x20
  char v8; // w21
  int v9; // w0

  if ( a4 > 0xFF )
    return 4294967274LL;
  v5 = *a2 + 48LL * a3;
  v8 = 8 * a3 + 16;
  v9 = kgsl_regmap_read(a1 + 13200);
  kgsl_regmap_write(a1 + 13200, v9 & ~(255 << v8) | (a4 << v8));
  kgsl_regmap_write(a1 + 13200, 1);
  *(_QWORD *)(v5 + 32) = 0;
  return 0;
}
