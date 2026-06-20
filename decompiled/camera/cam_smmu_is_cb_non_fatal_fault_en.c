__int64 __fastcall cam_smmu_is_cb_non_fatal_fault_en(unsigned int a1, _BYTE *a2)
{
  unsigned int v2; // w6

  if ( a1 == -1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_is_cb_non_fatal_fault_en",
      1075,
      "Invalid iommu handle %d",
      -1);
  }
  else
  {
    v2 = HIWORD(a1) & 0xFFF;
    if ( v2 < dword_394060 )
    {
      *a2 = *(_BYTE *)(iommu_cb_set + 14280LL * v2 + 106);
      return 0;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_is_cb_non_fatal_fault_en",
      1082,
      "Invalid handle or idx. idx: %d, hdl: 0x%x",
      v2,
      a1);
  }
  return 4294967274LL;
}
