__int64 __fastcall sub_130684(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int128 v5; // q30

  *(_OWORD *)(a5 + 58864) = v5;
  return cam_smmu_reset_iommu_table();
}
