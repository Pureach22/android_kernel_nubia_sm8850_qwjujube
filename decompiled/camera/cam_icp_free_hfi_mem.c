__int64 __fastcall cam_icp_free_hfi_mem(__int64 a1)
{
  __int64 v1; // x20
  __int64 result; // x0

  v1 = a1 + 40960;
  if ( *(_BYTE *)(a1 + 44236) == 1 )
    cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 5);
  if ( *(_BYTE *)(v1 + 3275) == 1 )
  {
    cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 6, 3);
    cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 1);
    cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 2);
  }
  cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 7, 4);
  if ( *(_BYTE *)(a1 + 984) == 1 )
  {
    cam_mem_mgr_free_memory_region((unsigned int *)(a1 + 488));
    *(_BYTE *)(a1 + 984) = 0;
  }
  else
  {
    cam_mem_mgr_release_mem((_DWORD *)(a1 + 168));
    cam_mem_mgr_release_mem((_DWORD *)(a1 + 208));
    cam_mem_mgr_release_mem((_DWORD *)(a1 + 248));
    cam_mem_mgr_release_mem((_DWORD *)(a1 + 288));
    cam_mem_mgr_release_mem((_DWORD *)(a1 + 448));
    cam_mem_mgr_free_memory_region((unsigned int *)(a1 + 328));
  }
  result = cam_smmu_unmap_phy_mem_region(*(_DWORD *)(a1 + 148), 5, 0);
  if ( (*(_BYTE *)(v1 + 3272) & 1) == 0 )
  {
    if ( (cam_presil_mode_enabled(result) & 1) != 0 )
      return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               256,
               3,
               "cam_icp_free_fw_mem",
               3687,
               "PRESIL-ICP-B2B-HFI-INIT No Shutdown No Deinit No HFIfreeMem");
    else
      return ((__int64 (__fastcall *)(_QWORD))cam_smmu_dealloc_firmware)(*(unsigned int *)(a1 + 148));
  }
  return result;
}
