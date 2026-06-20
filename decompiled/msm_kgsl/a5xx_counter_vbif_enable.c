__int64 __fastcall a5xx_counter_vbif_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x20

  if ( a4 > 0x7F )
    return 4294967274LL;
  v5 = *a2 + 48LL * a3;
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 0);
  kgsl_regmap_write(a1 + 13200, a4);
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, a4);
  *(_QWORD *)(v5 + 32) = 0;
  return 0;
}
