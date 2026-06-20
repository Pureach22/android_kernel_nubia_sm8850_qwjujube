__int64 __fastcall sub_125F0(long double a1, long double a2, long double a3, long double a4, long double a5)
{
  double v5; // d17
  double v6; // d27
  double v7; // d29

  return arm_smmu_tlb_add_page_s2_v1(a1, a2, a3, a4, a5, v5 - v6 * v7);
}
