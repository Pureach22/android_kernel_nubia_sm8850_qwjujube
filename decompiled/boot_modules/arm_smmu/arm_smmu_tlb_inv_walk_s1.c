__int64 __fastcall arm_smmu_tlb_inv_walk_s1(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( *(_BYTE *)(a4 + 68) == 1 )
    return arm_smmu_tlb_inv_context_s1((unsigned __int16 *)a4);
  arm_smmu_tlb_inv_range_s1(a1, a2, a3);
  return arm_smmu_tlb_sync_context(a4);
}
