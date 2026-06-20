__int64 __fastcall cam_smmu_destroy_handle(unsigned int a1)
{
  unsigned int v1; // w19
  __int64 v3; // x8
  int v4; // w6
  unsigned __int64 v5; // x10
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 *v8; // x27
  __int64 *v9; // x9
  __int64 *v10; // x0
  __int64 *v11; // x22
  unsigned __int64 *v13; // x8
  unsigned __int64 v14; // x9
  __int64 v15; // x8
  __int64 v16; // x9
  _QWORD *v17; // x27
  _QWORD *v18; // x9
  _QWORD *v19; // x0
  _QWORD *v20; // x21
  __int64 v21; // x9
  int v22; // w8
  __int64 v23; // x8
  _DWORD *v24; // x9
  int v25; // w10

  if ( a1 == -1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_destroy_handle",
      4410,
      "Error: Invalid handle");
    return 4294967274LL;
  }
  v1 = HIWORD(a1) & 0xFFF;
  if ( v1 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_destroy_handle",
      4418,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v1,
      a1);
    return 4294967274LL;
  }
  mutex_lock(iommu_cb_set + 14280LL * v1 + 8432);
  v3 = iommu_cb_set + 14280LL * v1;
  v4 = *(_DWORD *)(v3 + 8480);
  if ( v4 != (a1 & 0xFFFFFFF) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_destroy_handle",
      4426,
      "Error: hdl is not valid, table_hdl = %x, hdl = %x",
      v4,
      a1);
    mutex_unlock(iommu_cb_set + 14280LL * v1 + 8432);
    return 4294967274LL;
  }
  v5 = atomic_load((unsigned __int64 *)(v3 + 8400));
  if ( v3 + 8400 == v5 && *(_QWORD *)(v3 + 8408) == v3 + 8400 )
  {
    v6 = iommu_cb_set;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_destroy_handle",
      4433,
      "UMD %s buffer list is not clean",
      *(const char **)(iommu_cb_set + 14280LL * v1 + 32));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_print_user_list",
      797,
      "index = %d",
      v1);
    v6 = iommu_cb_set;
    v7 = iommu_cb_set + 14280LL * v1;
    v8 = *(__int64 **)(v7 + 8400);
    if ( v8 != (__int64 *)(v7 + 8400) )
    {
      do
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_print_user_list",
          803,
          "ion_fd = %d, i_ino=%lu, paddr= 0x%lx, len = %lu, region = %d",
          *((_DWORD *)v8 + 4),
          v8[3],
          *(v8 - 1),
          v8[4],
          *((_DWORD *)v8 - 7));
        v6 = iommu_cb_set;
        v8 = (__int64 *)*v8;
        v9 = (__int64 *)(iommu_cb_set + 14280LL * v1 + 8400);
      }
      while ( v8 != v9 );
      v8 = (__int64 *)*v9;
    }
    if ( v8 != (__int64 *)(v6 + 14280LL * v1 + 8400) )
    {
      do
      {
        v10 = v8 - 7;
        v11 = (__int64 *)*v8;
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_smmu_clean_user_buffer_list",
            1502,
            "Free mapping address %pK, i = %d, fd = %d, i_ino = %lu",
            (const void *)*(v8 - 1),
            v1,
            *((_DWORD *)v8 + 4),
            v8[3]);
          v10 = v8 - 7;
        }
        if ( *((_DWORD *)v8 + 4) == -559038737 )
        {
          if ( (cam_smmu_free_scratch_buffer_remove_from_list(v10, v1) & 0x80000000) != 0 )
            goto LABEL_19;
        }
        else if ( (cam_smmu_unmap_buf_and_remove_from_list(v10, v1) & 0x80000000) != 0 )
        {
LABEL_19:
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_clean_user_buffer_list",
            1516,
            "Buffer delete failed: idx = %d",
            v1);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_clean_user_buffer_list",
            1520,
            "Buffer delete failed: addr = 0x%lx, fd = %d, i_ino = %lu",
            *(v8 - 1),
            *((_DWORD *)v8 + 4),
            v8[3]);
        }
        v6 = iommu_cb_set;
        v8 = v11;
      }
      while ( v11 != (__int64 *)(iommu_cb_set + 14280LL * v1 + 8400) );
    }
  }
  v13 = (unsigned __int64 *)(v6 + 14280LL * v1 + 8416);
  v14 = atomic_load(v13);
  if ( v13 == (unsigned __int64 *)v14 && (unsigned __int64 *)v13[1] == v13 )
  {
    v15 = iommu_cb_set;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_destroy_handle",
      4441,
      "KMD %s buffer list is not clean",
      *(const char **)(iommu_cb_set + 14280LL * v1 + 32));
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_print_kernel_list",
      811,
      "index = %d",
      v1);
    v15 = iommu_cb_set;
    v16 = iommu_cb_set + 14280LL * v1;
    v17 = *(_QWORD **)(v16 + 8416);
    if ( v17 != (_QWORD *)(v16 + 8416) )
    {
      do
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_print_kernel_list",
          817,
          "dma_buf = %pK, i_ino = %lu, paddr= 0x%lx, len = %lu, region = %d",
          (const void *)*(v17 - 7),
          v17[3],
          *(v17 - 1),
          v17[4],
          *((_DWORD *)v17 - 7));
        v15 = iommu_cb_set;
        v17 = (_QWORD *)*v17;
        v18 = (_QWORD *)(iommu_cb_set + 14280LL * v1 + 8416);
      }
      while ( v17 != v18 );
      v17 = (_QWORD *)*v18;
    }
    if ( v17 != (_QWORD *)(v15 + 14280LL * v1 + 8416) )
    {
      do
      {
        v19 = v17 - 7;
        v20 = (_QWORD *)*v17;
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_smmu_clean_kernel_buffer_list",
            1540,
            "Free mapping address %pK, i = %d, dma_buf = %pK",
            (const void *)*(v17 - 1),
            v1,
            (const void *)*(v17 - 7));
          v19 = v17 - 7;
        }
        if ( (cam_smmu_unmap_buf_and_remove_from_list(v19, v1) & 0x80000000) != 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_clean_kernel_buffer_list",
            1550,
            "Buffer delete in kernel list failed: idx = %d",
            v1);
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_clean_kernel_buffer_list",
            1553,
            "Buffer delete failed: addr = 0x%lx, dma_buf = %pK",
            *(v17 - 1),
            (const void *)*(v17 - 7));
        }
        v15 = iommu_cb_set;
        v17 = v20;
      }
      while ( v20 != (_QWORD *)(iommu_cb_set + 14280LL * v1 + 8416) );
    }
  }
  v21 = v15 + 14280LL * v1;
  if ( *(_BYTE *)(v21 + 80) != 1 )
  {
    if ( *(_BYTE *)(v21 + 8616) == 1 )
    {
      v25 = *(_DWORD *)(v21 + 8620);
      if ( v25 )
      {
        *(_DWORD *)(v21 + 8620) = v25 - 1;
        v23 = iommu_cb_set;
        v24 = (_DWORD *)(iommu_cb_set + 14280LL * v1);
        if ( v24[2155] )
          goto LABEL_48;
        goto LABEL_41;
      }
    }
    *(_DWORD *)(v15 + 14280LL * v1 + 8620) = 0;
    *(_DWORD *)(iommu_cb_set + 14280LL * v1 + 8584) = 0;
    *(_DWORD *)(iommu_cb_set + 14280LL * v1 + 8480) = -1;
    v23 = iommu_cb_set;
LABEL_48:
    mutex_unlock(v23 + 14280LL * v1 + 8432);
    return 0;
  }
  v22 = *(_DWORD *)(v21 + 8588);
  if ( v22 )
  {
    *(_DWORD *)(v21 + 8588) = v22 - 1;
    v23 = iommu_cb_set;
    v24 = (_DWORD *)(iommu_cb_set + 14280LL * v1);
    if ( !v24[2147] )
    {
LABEL_41:
      v24[2146] = 0;
      *(_DWORD *)(iommu_cb_set + 14280LL * v1 + 8480) = -1;
      v23 = iommu_cb_set;
      goto LABEL_48;
    }
    goto LABEL_48;
  }
  mutex_unlock(v21 + 8432);
  return 0xFFFFFFFFLL;
}
