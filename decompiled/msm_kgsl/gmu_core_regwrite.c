__int64 __fastcall gmu_core_regwrite(__int64 a1, __int64 a2, unsigned int a3)
{
  return kgsl_regmap_write(a1 + 13200, a3);
}
