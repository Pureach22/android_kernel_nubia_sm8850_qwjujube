__int64 __fastcall arm_smmu_tlb_add_page_s1(__int64 a1, __int64 a2, __int64 a3)
{
  return arm_smmu_tlb_inv_range_s1(a2, a3, a3);
}
