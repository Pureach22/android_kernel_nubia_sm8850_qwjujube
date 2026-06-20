__int64 __fastcall cam_smmu_get_stage2_iova(
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
  int v10; // w28
  int v17; // w6
  __int64 v18; // x8
  __int64 *v19; // x9
  __int64 v20; // x1
  unsigned int v21; // w20
  const char *v22; // x5
  __int64 v23; // x4

  if ( !a4 || !a5 )
  {
    v22 = "Error: Input pointers are invalid";
    v23 = 4160;
LABEL_18:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_stage2_iova",
      v23,
      v22);
    return 4294967274LL;
  }
  if ( a1 == -1 )
  {
    v22 = "Error: Invalid handle";
    v23 = 4165;
    goto LABEL_18;
  }
  *a4 = 0;
  v7 = HIWORD(a1) & 0xFFF;
  *a5 = 0;
  if ( v7 < dword_394060 )
  {
    v8 = iommu_cb_set + 14280LL * v7;
    if ( (*(_BYTE *)(v8 + 80) & 1) != 0 )
    {
      v10 = a1 & 0xFFFFFFF;
      mutex_lock(v8 + 8432);
      v17 = *(_DWORD *)(iommu_cb_set + 14280LL * v7 + 8480);
      if ( v17 == v10 )
      {
        v18 = iommu_cb_set + 14280LL * v7;
        v19 = *(__int64 **)(v18 + 8400);
        if ( v19 != (__int64 *)(v18 + 8400) )
        {
          v20 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 8) + 40LL) + 64LL);
          while ( *((_DWORD *)v19 + 4) != a2 || v19[3] != v20 )
          {
            v19 = (__int64 *)*v19;
            if ( v19 == (__int64 *)(v18 + 8400) )
              goto LABEL_22;
          }
          *a4 = *(v19 - 1);
          *a5 = v19[4];
          *a7 = (unsigned int *)(v19 - 2);
          if ( a6 )
            v21 = cam_smmu_add_buf_to_track_list(a2, v20, a7, a6, v7);
          else
            v21 = 0;
          goto LABEL_24;
        }
LABEL_22:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_get_stage2_iova",
          4200,
          "ion_fd:%d not in the mapped list",
          a2);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_get_stage2_iova",
          4191,
          "Error: hdl is not valid, table_hdl = %x, hdl = %x",
          v17,
          a1);
      }
      v21 = -22;
LABEL_24:
      mutex_unlock(iommu_cb_set + 14280LL * v7 + 8432);
      return v21;
    }
    v22 = "Error: can't get secure mem from non secure cb";
    v23 = 4183;
    goto LABEL_18;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_get_stage2_iova",
    4177,
    "Error: handle or index invalid. idx = %d hdl = %x",
    v7,
    a1);
  return 4294967274LL;
}
