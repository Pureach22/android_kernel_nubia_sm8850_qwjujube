__int64 __fastcall cam_smmu_unmap_kernel_iova(unsigned int a1, const void *a2)
{
  unsigned int v2; // w19
  __int64 v5; // x8
  int v7; // w6
  int *v8; // x9
  int *v9; // x0
  unsigned int v10; // w0
  unsigned int v11; // w20
  int *v12; // x20
  int *v13; // [xsp+18h] [xbp+18h]

  if ( a1 == -1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_validate_params",
      4219,
      "Error: Invalid handle");
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_kernel_iova",
      4316,
      "unmap util validation failure");
    return 4294967274LL;
  }
  v2 = HIWORD(a1) & 0xFFF;
  if ( v2 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_validate_params",
      4228,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v2,
      a1);
    goto LABEL_7;
  }
  mutex_lock(iommu_cb_set + 14280LL * v2 + 8432);
  v5 = iommu_cb_set + 14280LL * v2;
  if ( *(_BYTE *)(v5 + 80) != 1 )
  {
    v7 = *(_DWORD *)(v5 + 8480);
    if ( v7 != a1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_unmap_kernel_iova",
        4332,
        "Error: hdl is not valid, table_hdl = %x, hdl = %x",
        v7,
        a1);
      goto LABEL_25;
    }
    if ( a2 )
    {
      v8 = (int *)(iommu_cb_set + 14280LL * v2 + 8416);
      do
      {
        v8 = *(int **)v8;
        if ( v8 == (int *)(iommu_cb_set + 14280LL * v2 + 8416) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_find_mapping_by_dma_buf",
            1468,
            "Error: Cannot find entry by index %d",
            v2);
          goto LABEL_24;
        }
      }
      while ( *((const void **)v8 - 7) != a2 );
      v9 = v8 - 14;
      if ( (debug_mdl & 0x40) == 0 || debug_priority )
      {
        if ( v8 == &dword_38 )
          goto LABEL_24;
        goto LABEL_16;
      }
      v13 = v8 - 14;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40,
        4,
        "cam_smmu_find_mapping_by_dma_buf",
        1463,
        "find dma_buf %pK",
        a2);
      v9 = v13;
      if ( v13 )
      {
LABEL_16:
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        {
          v12 = v9;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_smmu_unmap_kernel_iova",
            4349,
            "SMMU: removing buffer idx = %d",
            v2);
          v9 = v12;
        }
        v10 = cam_smmu_unmap_buf_and_remove_from_list(v9, v2);
        if ( (v10 & 0x80000000) != 0 )
        {
          v11 = v10;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_unmap_kernel_iova",
            4352,
            "Error: unmap or remove list fail");
        }
        else
        {
          v11 = 0;
        }
        goto LABEL_26;
      }
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_find_mapping_by_dma_buf",
        1455,
        "Invalid dma_buf");
    }
LABEL_24:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unmap_kernel_iova",
      4343,
      "Error: Invalid params idx = %d, dma_buf = %pK",
      v2,
      a2);
    goto LABEL_25;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_unmap_kernel_iova",
    4324,
    "Error: can't unmap non-secure mem from secure cb");
LABEL_25:
  v11 = -22;
LABEL_26:
  mutex_unlock(iommu_cb_set + 14280LL * v2 + 8432);
  return v11;
}
