__int64 __fastcall cam_smmu_map_stage2_iova(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        unsigned int a4,
        _QWORD *a5,
        _QWORD *a6,
        _QWORD *a7)
{
  unsigned int v9; // w19
  __int64 v10; // x8
  int v12; // w28
  __int64 v17; // x9
  __int64 *v18; // x8
  __int64 v19; // x9
  unsigned int v21; // w21
  const char *v23; // x5
  __int64 v24; // x4
  __int64 v25; // x6
  unsigned int v26; // w0

  if ( !a5 || !a6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_stage2_iova",
      3697,
      "Error: Invalid inputs, paddr_ptr:%pK, len_ptr: %pK",
      a5,
      a6);
    return 4294967274LL;
  }
  *a5 = 0;
  *a6 = 0;
  if ( a4 >= 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_translate_dir",
      1131,
      "Error: Direction is invalid. dir = %d",
      a4);
    v23 = "Error: translate direction failed. dir = %d";
    v24 = 3707;
    v25 = a4;
LABEL_18:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_stage2_iova",
      v24,
      v23,
      v25);
    return 4294967274LL;
  }
  v9 = HIWORD(a1) & 0xFFF;
  if ( a1 == -1 || v9 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_stage2_iova",
      3717,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v9,
      a1);
    return 4294967274LL;
  }
  v10 = iommu_cb_set + 14280LL * v9;
  if ( (*(_BYTE *)(v10 + 80) & 1) == 0 )
  {
    v23 = "Error: can't map secure mem to non secure cb, idx=%d";
    v24 = 3724;
    v25 = v9;
    goto LABEL_18;
  }
  v12 = a1 & 0xFFFFFFF;
  mutex_lock(v10 + 8432);
  if ( *(_DWORD *)(iommu_cb_set + 14280LL * v9 + 8480) == v12 )
  {
    v17 = iommu_cb_set + 14280LL * v9;
    v18 = *(__int64 **)(v17 + 8400);
    v19 = v17 + 8400;
    if ( v18 == (__int64 *)v19 )
    {
LABEL_22:
      v26 = cam_smmu_map_stage2_buffer_and_add_to_list(v9, a2, 2 - a4, a5, a6, a3, a7);
      v21 = v26;
      if ( (v26 & 0x80000000) != 0 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          64,
          1,
          "cam_smmu_map_stage2_iova",
          3751,
          "Error: mapping or add list fail, idx=%d, handle=%d, fd=%d, rc=%d",
          v9,
          a1,
          a2,
          v26);
    }
    else
    {
      while ( *((_DWORD *)v18 + 4) != a2 || v18[3] != *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a3 + 8) + 40LL) + 64LL) )
      {
        v18 = (__int64 *)*v18;
        if ( v18 == (__int64 *)v19 )
          goto LABEL_22;
      }
      *a5 = *(v18 - 1);
      *a6 = v18[4];
      v21 = 0;
      ++*((_DWORD *)v18 - 5);
      *a7 = v18 - 2;
      if ( (debug_mdl & 0x40) != 0 && !debug_priority )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x40,
          4,
          "cam_smmu_map_stage2_iova",
          3742,
          "fd:%d already in list idx:%d, handle=%d give same addr back",
          a2,
          v9,
          a1);
        v21 = 0;
      }
    }
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_map_stage2_iova",
      3732,
      "Error: hdl is not valid, idx=%d, table_hdl=%x, hdl=%x",
      v9);
    v21 = -22;
  }
  mutex_unlock(iommu_cb_set + 14280LL * v9 + 8432);
  return v21;
}
