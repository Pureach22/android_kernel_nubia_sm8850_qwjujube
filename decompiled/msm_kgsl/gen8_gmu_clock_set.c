__int64 __fastcall gen8_gmu_clock_set(__int64 a1, __int64 a2)
{
  return gen8_gmu_dcvs_set(a1, a2, 255, 0xFFFF);
}
