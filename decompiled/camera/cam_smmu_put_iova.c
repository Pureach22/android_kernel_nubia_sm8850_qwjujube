__int64 __fastcall cam_smmu_put_iova(unsigned int a1, int a2, __int64 a3)
{
  unsigned int v3; // w19
  unsigned int v7; // w20
  const char *v9; // x5
  __int64 v10; // x4

  if ( a1 == -1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_put_iova",
      4368,
      "Error: Invalid handle");
    return 4294967274LL;
  }
  v3 = HIWORD(a1) & 0xFFF;
  if ( v3 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_put_iova",
      4377,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v3,
      a1);
    return 4294967274LL;
  }
  mutex_lock(iommu_cb_set + 14280LL * v3 + 8432);
  if ( *(_DWORD *)(iommu_cb_set + 14280LL * v3 + 8480) != a1 )
  {
    v9 = "Error: hdl is not valid, table_hdl = %x, hdl = %x";
    v10 = 4385;
LABEL_10:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_put_iova",
      v10,
      v9);
    v7 = -22;
    goto LABEL_11;
  }
  if ( !cam_smmu_find_mapping_by_ion_index(v3, a2, a3) )
  {
    v9 = "Error: Invalid params idx = %d, fd = %d";
    v10 = 4394;
    goto LABEL_10;
  }
  v7 = 0;
LABEL_11:
  mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
  return v7;
}
