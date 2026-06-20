__int64 __fastcall gen8_gmu_irq_disable(__int64 a1)
{
  __int64 result; // x0

  disable_irq(*(unsigned int *)(a1 - 1824));
  disable_irq(*(unsigned int *)(a1 - 1784));
  gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 146182, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
  result = *(unsigned int *)(a1 + 14172);
  if ( (int)result >= 1 )
  {
    disable_irq(result);
    kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
    return kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
  }
  return result;
}
