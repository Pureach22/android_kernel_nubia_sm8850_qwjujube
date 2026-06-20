__int64 __fastcall arm_smmu_sid_switch(__int64 a1, unsigned int a2)
{
  __int64 v3; // x20
  unsigned int v4; // w19

  v3 = iommu_group_get();
  v4 = iommu_group_for_each_dev(v3, a2, _arm_smmu_sid_switch);
  iommu_group_put(v3);
  return v4;
}
