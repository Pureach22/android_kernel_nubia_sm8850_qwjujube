__int64 __fastcall gen7_gmu_irq_enable(__int64 a1)
{
  unsigned int *v2; // x20
  unsigned int *v3; // x21

  v2 = (unsigned int *)(a1 - 1776);
  v3 = (unsigned int *)(a1 - 1736);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 129427, 4294934521LL);
  gmu_core_regwrite(a1, 146182, 4294967254LL);
  enable_irq(*v3);
  return enable_irq(*v2);
}
