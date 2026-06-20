__int64 __fastcall cam_smmu_reset_iommu_table(__int64 result)
{
  int v1; // w19
  __int64 v2; // x22
  unsigned __int64 v3; // x23
  __int64 v4; // x8
  __int64 v5; // x8

  if ( dword_394060 )
  {
    v1 = result;
    v2 = 0;
    v3 = 0;
    do
    {
      if ( !v1 )
        _mutex_init(iommu_cb_set + v2 + 8432, "&iommu_cb_set.cb_info[i].lock", &cam_smmu_reset_iommu_table___key);
      mutex_lock(iommu_cb_set + v2 + 8432);
      *(_DWORD *)(iommu_cb_set + v2 + 8480) = -1;
      v4 = iommu_cb_set + v2;
      *(_QWORD *)(v4 + 8400) = v4 + 8400;
      *(_QWORD *)(v4 + 8408) = v4 + 8400;
      v5 = iommu_cb_set + v2;
      *(_QWORD *)(v5 + 8416) = v5 + 8416;
      *(_QWORD *)(v5 + 8424) = v5 + 8416;
      *(_DWORD *)(iommu_cb_set + v2 + 8484) = 1;
      *(_QWORD *)(iommu_cb_set + v2) = 0;
      *(_DWORD *)(iommu_cb_set + v2 + 8584) = 0;
      *(_DWORD *)(iommu_cb_set + v2 + 8592) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8536) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8488) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8544) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8496) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8552) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8504) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8560) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8512) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8568) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8520) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8576) = 0;
      *(_QWORD *)(iommu_cb_set + v2 + 8528) = 0;
      result = mutex_unlock(iommu_cb_set + v2 + 8432);
      ++v3;
      v2 += 14280;
    }
    while ( v3 < (unsigned int)dword_394060 );
  }
  return result;
}
