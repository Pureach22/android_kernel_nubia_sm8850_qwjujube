__int64 __fastcall sub_603C(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6, __int64 a7)
{
  __int64 v7; // x12

  return smmu_pmu_offline_cpu(a1, a2, a3, v7 ^ ~__ROR8__(a7, 20));
}
