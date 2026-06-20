__int64 __fastcall gen7_periph_regread64(__int64 result, __int64 a2, unsigned int a3, __int64 *a4, int a5)
{
  __int64 v7; // x20
  __int64 v8; // x24
  __int64 v9; // x8

  v7 = result;
  if ( (unsigned int)(a5 - 1) > 2 )
  {
    v8 = 0;
    v9 = 0;
  }
  else
  {
    kgsl_regmap_write(result + 13200, a2);
    __dsb(0xFu);
    v8 = (unsigned int)kgsl_regmap_read(v7 + 13200);
    kgsl_regmap_write(v7 + 13200, a3);
    __dsb(0xFu);
    result = kgsl_regmap_read(v7 + 13200);
    v9 = result << 32;
  }
  *a4 = v9 | v8;
  return result;
}
