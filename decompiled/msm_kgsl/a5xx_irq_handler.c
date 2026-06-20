__int64 __fastcall a5xx_irq_handler(__int64 a1)
{
  unsigned int v2; // w20
  __int64 result; // x0
  unsigned int v4; // w20

  v2 = kgsl_regmap_read(a1 + 13200);
  kgsl_regmap_write(a1 + 13200, v2 & 0xFFFFFFFE);
  result = adreno_irq_callbacks(a1, (__int64)&a5xx_irq_funcs, v2);
  if ( (v2 & 1) != 0 )
  {
    v4 = result;
    kgsl_regmap_write(a1 + 13200, 1);
    return v4;
  }
  return result;
}
