__int64 __fastcall gen8_hwsched_irq_handler(__int64 a1)
{
  unsigned int v2; // w20
  __int64 result; // x0
  unsigned int v4; // w20

  gmu_core_regwrite(a1, 128996, 1);
  v2 = kgsl_regmap_read(a1 + 13200);
  kgsl_regmap_write(a1 + 13200, v2);
  result = adreno_irq_callbacks(a1, (__int64)&gen8_irq_funcs, v2);
  __dmb(9u);
  if ( (*(_DWORD *)(a1 + 24448) & 2) == 0 )
  {
    v4 = result;
    gmu_core_regwrite(a1, 128996, 0);
    return v4;
  }
  return result;
}
