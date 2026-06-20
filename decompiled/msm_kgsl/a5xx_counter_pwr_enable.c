__int64 __fastcall a5xx_counter_pwr_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  __int64 v4; // x20

  v4 = *a2 + 48LL * a3;
  kgsl_regmap_write(a1 + 13200, a4);
  kgsl_regmap_write(a1 + 13200, 1);
  *(_QWORD *)(v4 + 32) = 0;
  return 0;
}
