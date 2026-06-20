__int64 __fastcall a630_counter_vbif_pwr_enable(__int64 a1, _QWORD *a2, unsigned int a3)
{
  __int64 v3; // x20

  v3 = *a2 + 48LL * a3;
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, 0);
  kgsl_regmap_write(a1 + 13200, 1);
  *(_QWORD *)(v3 + 32) = 0;
  return 0;
}
