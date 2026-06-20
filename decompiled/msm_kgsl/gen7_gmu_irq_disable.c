__int64 __fastcall gen7_gmu_irq_disable(__int64 a1)
{
  disable_irq(*(unsigned int *)(a1 - 1776));
  disable_irq(*(unsigned int *)(a1 - 1736));
  gmu_core_regwrite(a1, 129427, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 146182, 0xFFFFFFFFLL);
  gmu_core_regwrite(a1, 129425, 0xFFFFFFFFLL);
  return gmu_core_regwrite(a1, 146180, 0xFFFFFFFFLL);
}
