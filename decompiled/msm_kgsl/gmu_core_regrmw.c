__int64 __fastcall gmu_core_regrmw(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  return kgsl_regmap_rmw(a1 + 13200, a2, a3, a4);
}
