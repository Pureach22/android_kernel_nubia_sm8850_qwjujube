__int64 __fastcall cam_smmu_component_unbind(__int64 a1)
{
  __int64 result; // x0

  cam_smmu_reset_iommu_table(1);
  if ( a1 && *(_QWORD *)(a1 + 672) )
  {
    devm_kfree(a1);
    *(_QWORD *)(a1 + 672) = 0;
  }
  result = ((__int64 (__fastcall *)(__int64))cam_smmu_release_cb)(a1 - 16);
  qword_3940C8 = 0;
  return result;
}
