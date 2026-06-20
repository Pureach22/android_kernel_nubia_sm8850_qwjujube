__int64 camera_platform_compare_dev()
{
  __int64 (*v0)(void); // x8

  v0 = (__int64 (*)(void))qcom_iommu_get_fault_ids;
  if ( *(_DWORD *)(qcom_iommu_get_fault_ids - 4LL) != 810692157 )
    __break(0x8228u);
  return v0();
}
