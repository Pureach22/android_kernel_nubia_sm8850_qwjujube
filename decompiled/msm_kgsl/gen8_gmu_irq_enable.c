__int64 __fastcall gen8_gmu_irq_enable(__int64 a1)
{
  unsigned int *v2; // x20
  unsigned int *v3; // x21
  __int64 result; // x0

  v2 = (unsigned int *)(a1 - 1824);
  v3 = (unsigned int *)(a1 - 1784);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 129427, 4294934521LL);
  gmu_core_regwrite(a1, 146182, 4294967254LL);
  enable_irq(*v3);
  result = enable_irq(*v2);
  if ( *(int *)(a1 + 14172) >= 1 )
  {
    kgsl_regmap_write(a1 + 13200, 0xFFFFFFFFLL);
    kgsl_regmap_write(a1 + 13200, 0x80000000LL);
    return enable_irq(*(unsigned int *)(a1 + 14172));
  }
  return result;
}
