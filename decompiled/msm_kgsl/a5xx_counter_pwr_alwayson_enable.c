__int64 __fastcall a5xx_counter_pwr_alwayson_enable(__int64 a1, __int64 *a2, unsigned int a3)
{
  __int64 v4; // x20

  v4 = *a2;
  kgsl_regmap_write(a1 + 13200, 1);
  *(_QWORD *)(v4 + 48LL * a3 + 32) = 0;
  return 0;
}
