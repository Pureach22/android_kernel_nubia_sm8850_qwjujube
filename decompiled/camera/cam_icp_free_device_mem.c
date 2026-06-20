__int64 __fastcall cam_icp_free_device_mem(__int64 a1)
{
  __int64 v1; // x20

  v1 = a1 + 40960;
  if ( *(_BYTE *)(a1 + 44236) == 1 )
    cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 5);
  if ( *(_BYTE *)(v1 + 3275) == 1 )
  {
    cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 6, 3);
    cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 1);
    cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 2);
  }
  return cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 4);
}
