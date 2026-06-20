__int64 __fastcall cam_smmu_put_scratch_iova(unsigned int a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 v5; // x9
  int v6; // w6
  __int64 v7; // x6
  int *v8; // x8
  int *v9; // x0
  unsigned int v10; // w20
  int *v12; // x20

  if ( a1 == -1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_put_scratch_iova",
      3546,
      "Error: Invalid handle");
    return 4294967274LL;
  }
  v2 = HIWORD(a1) & 0xFFF;
  if ( v2 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_put_scratch_iova",
      3555,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v2,
      a1);
    return 4294967274LL;
  }
  mutex_lock(iommu_cb_set + 14280LL * v2 + 8432);
  v5 = iommu_cb_set + 14280LL * v2;
  v6 = *(_DWORD *)(v5 + 8480);
  if ( v6 != a1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_put_scratch_iova",
      3563,
      "Error: hdl is not valid, table_hdl = %x, hdl = %x",
      v6,
      a1);
    v10 = -22;
    goto LABEL_19;
  }
  if ( !*(_BYTE *)(v5 + 81) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_put_scratch_iova",
      3570,
      "Error: Context bank does not support scratch buffers");
    v10 = -22;
    goto LABEL_19;
  }
  v7 = a2;
  v8 = (int *)(iommu_cb_set + 14280LL * v2 + 8400);
  do
  {
    v8 = *(int **)v8;
    if ( v8 == (int *)(iommu_cb_set + 14280LL * v2 + 8400) )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_find_mapping_by_virt_address",
        1417,
        "Error: Cannot find virtual address %lx by index %d",
        a2,
        v2);
      goto LABEL_18;
    }
  }
  while ( *((_QWORD *)v8 - 1) != a2 );
  v9 = v8 - 14;
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
  {
    v12 = v8 - 14;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40,
      4,
      "cam_smmu_find_mapping_by_virt_address",
      1411,
      "Found virtual address %lx",
      a2);
    v9 = v12;
    if ( v12 )
      goto LABEL_11;
LABEL_18:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_put_scratch_iova",
      3580,
      "Error: Invalid params",
      v7);
    v10 = -19;
    goto LABEL_19;
  }
  if ( v8 == &dword_38 )
    goto LABEL_18;
LABEL_11:
  v10 = cam_smmu_free_scratch_buffer_remove_from_list(v9, v2);
  if ( (v10 & 0x80000000) != 0 )
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_put_scratch_iova",
      3588,
      "Error: unmap or remove list fail");
LABEL_19:
  mutex_unlock(iommu_cb_set + 14280LL * v2 + 8432);
  return v10;
}
