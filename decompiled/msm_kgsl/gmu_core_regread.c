__int64 __fastcall gmu_core_regread(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 result; // x0

  result = kgsl_regmap_read(a1 + 13200);
  *a3 = result;
  return result;
}
