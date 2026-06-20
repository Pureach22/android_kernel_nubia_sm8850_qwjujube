__int64 __fastcall a5xx_counter_load(__int64 a1, _DWORD *a2)
{
  unsigned int v4; // w21

  v4 = 1 << a2[5];
  kgsl_regmap_write(a1 + 13200, (unsigned int)a2[8]);
  kgsl_regmap_write(a1 + 13200, (unsigned int)a2[9]);
  return kgsl_regmap_write(a1 + 13200, v4);
}
