__int64 __fastcall a6xx_hwsched_irq_handler(__int64 a1)
{
  unsigned int v2; // w21
  unsigned int v3; // w20

  if ( (gmu_core_isenabled(a1) & 1) != 0 )
    gmu_core_regwrite(a1, 129219, 1);
  v2 = kgsl_regmap_read(a1 + 13200);
  kgsl_regmap_write(a1 + 13200, v2);
  v3 = adreno_irq_callbacks(a1, (__int64)&a6xx_irq_funcs, v2);
  __dmb(9u);
  if ( (*(_DWORD *)(a1 + 24448) & 2) == 0 && (gmu_core_isenabled(a1) & 1) != 0 )
    gmu_core_regwrite(a1, 129219, 0);
  return v3;
}
