__int64 __fastcall arm_smmu_device_remove(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 168);
  iommu_device_unregister(v1 + 232);
  iommu_device_sysfs_remove(v1 + 232);
  return arm_smmu_device_shutdown(a1);
}
