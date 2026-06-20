__int64 __fastcall cam_smmu_get_iova(
        unsigned int a1,
        int a2,
        __int64 a3,
        _QWORD *a4,
        _QWORD *a5,
        __int64 *a6,
        unsigned int **a7)
{
  unsigned int v7; // w19
  __int64 v8; // x8
  const char *v9; // x5
  __int64 v10; // x4
  int v13; // w28
  int v20; // w6
  __int64 v21; // x8
  __int64 *v22; // x9
  __int64 v23; // x1
  unsigned int v24; // w20

  if ( !a4 || !a5 )
  {
    v9 = "Error: Input pointers are invalid";
    v10 = 4097;
    goto LABEL_9;
  }
  if ( a1 == -1 )
  {
    v9 = "Error: Invalid handle";
    v10 = 4102;
    goto LABEL_9;
  }
  *a4 = 0;
  v7 = HIWORD(a1) & 0xFFF;
  *a5 = 0;
  if ( v7 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_iova",
      4114,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v7,
      a1);
    return 4294967274LL;
  }
  v8 = iommu_cb_set + 14280LL * v7;
  if ( *(_BYTE *)(v8 + 80) != 1 )
  {
    v13 = a1 & 0xFFFFFFF;
    mutex_lock(v8 + 8432);
    v20 = *(_DWORD *)(iommu_cb_set + 14280LL * v7 + 8480);
    if ( v20 == v13 )
    {
      v21 = iommu_cb_set + 14280LL * v7;
      v22 = *(__int64 **)(v21 + 8400);
      if ( v22 != (__int64 *)(v21 + 8400) )
      {
        v23 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 8) + 40LL) + 64LL);
        while ( *((_DWORD *)v22 + 4) != a2 || v22[3] != v23 )
        {
          v22 = (__int64 *)*v22;
          if ( v22 == (__int64 *)(v21 + 8400) )
            goto LABEL_22;
        }
        *a4 = *(v22 - 1);
        *a5 = v22[4];
        *a7 = (unsigned int *)(v22 - 2);
        if ( a6 )
          v24 = cam_smmu_add_buf_to_track_list(a2, v23, a7, a6, v7);
        else
          v24 = 0;
        goto LABEL_24;
      }
LABEL_22:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_get_iova",
        4136,
        "ion_fd:%d not in the mapped list",
        a2);
      ((void (__fastcall *)(_QWORD))cam_smmu_dump_cb_info)(v7);
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_get_iova",
        4128,
        "Error: hdl is not valid, table_hdl = %x, hdl = %x",
        v20,
        a1);
    }
    v24 = -22;
LABEL_24:
    mutex_unlock(iommu_cb_set + 14280LL * v7 + 8432);
    return v24;
  }
  v9 = "Error: can't get non-secure mem from secure cb";
  v10 = 4120;
LABEL_9:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_get_iova",
    v10,
    v9);
  return 4294967274LL;
}
