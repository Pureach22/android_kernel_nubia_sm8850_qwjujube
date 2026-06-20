__int64 __fastcall a6xx_nogmu_start(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x1
  __int64 v4; // x2

  kgsl_regmap_write(a1 + 13200, 0);
  kgsl_regmap_write(a1 + 13200, 0);
  result = kgsl_mmu_start(a1);
  if ( !(_DWORD)result )
  {
    adreno_get_bus_counters(a1, v3, v4);
    adreno_perfcounter_restore(a1);
    a6xx_start(a1);
    return 0;
  }
  return result;
}
