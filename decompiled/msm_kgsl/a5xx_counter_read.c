unsigned __int64 __fastcall a5xx_counter_read(__int64 a1)
{
  unsigned int v2; // w20

  v2 = kgsl_regmap_read(a1 + 13200);
  return v2 | (unsigned __int64)(kgsl_regmap_read(a1 + 13200) << 32);
}
