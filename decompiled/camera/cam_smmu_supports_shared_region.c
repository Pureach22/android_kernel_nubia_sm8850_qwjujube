__int64 __fastcall cam_smmu_supports_shared_region(unsigned int a1, bool *a2)
{
  unsigned int v2; // w19

  v2 = HIWORD(a1) & 0xFFF;
  if ( v2 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_supports_shared_region",
      3915,
      "Error: handle or index invalid. idx = %d hdl = 0x%x",
      v2,
      a1);
    return 4294967274LL;
  }
  else
  {
    mutex_lock(iommu_cb_set + 14280LL * v2 + 8432);
    *a2 = *(_BYTE *)(iommu_cb_set + 14280LL * v2 + 83) != 0;
    mutex_unlock(iommu_cb_set + 14280LL * v2 + 8432);
    return 0;
  }
}
