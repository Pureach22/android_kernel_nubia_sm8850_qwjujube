__int64 __fastcall cam_smmu_get_scratch_iova(
        unsigned int a1,
        unsigned int a2,
        __int64 a3,
        unsigned __int64 a4,
        unsigned __int64 a5)
{
  const char *v5; // x5
  __int64 v6; // x4
  unsigned int v8; // w19
  __int64 v13; // x8
  int v14; // w6
  int v15; // w10
  __int64 v16; // x1
  unsigned __int64 v17; // x2
  unsigned __int64 v18; // x9
  __int64 v19; // x10
  const char *v21; // x5
  __int64 v22; // x4
  unsigned int v23; // w20

  if ( !a3 || !a4 || !a5 )
  {
    v5 = "Error: Input pointer or lengths invalid";
    v6 = 3453;
    goto LABEL_7;
  }
  if ( a4 < a5 )
  {
    v5 = "Error: virt_len > phys_len";
    v6 = 3458;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_scratch_iova",
      v6,
      v5);
    return 4294967274LL;
  }
  if ( a1 == -1 )
  {
    v5 = "Error: Invalid handle";
    v6 = 3463;
    goto LABEL_7;
  }
  if ( a2 >= 3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_translate_dir_to_iommu_dir",
      1112,
      "Error: Direction is invalid. dir = %d",
      a2);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_scratch_iova",
      3470,
      "Error: translate direction failed. dir = %d",
      a2);
    return 4294967274LL;
  }
  v8 = HIWORD(a1) & 0xFFF;
  if ( v8 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_scratch_iova",
      3478,
      "Error: handle or index invalid. idx = %d hdl = %x",
      v8,
      a1);
    return 4294967274LL;
  }
  mutex_lock(iommu_cb_set + 14280LL * v8 + 8432);
  v13 = iommu_cb_set + 14280LL * v8;
  v14 = *(_DWORD *)(v13 + 8480);
  if ( v14 != a1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_scratch_iova",
      3486,
      "Error: hdl is not valid, table_hdl = %x, hdl = %x",
      v14,
      a1);
    goto LABEL_31;
  }
  if ( !*(_BYTE *)(v13 + 81) )
  {
    v21 = "Error: Context bank does not support scratch bufs";
    v22 = 3493;
LABEL_30:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_get_scratch_iova",
      v22,
      v21);
    goto LABEL_31;
  }
  v15 = debug_priority;
  v16 = debug_mdl & 0x40;
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v16,
      4,
      "cam_smmu_get_scratch_iova",
      3499,
      "smmu handle = %x, idx = %d, dir = %d",
      a1,
      v8,
      a2);
    v15 = debug_priority;
    v18 = a4;
    v17 = a5;
    v16 = debug_mdl & 0x40;
    if ( (debug_mdl & 0x40) == 0 )
      goto LABEL_19;
  }
  else
  {
    v17 = a5;
    v18 = a4;
    if ( (debug_mdl & 0x40) == 0 )
      goto LABEL_19;
  }
  if ( !v15 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v16,
      4,
      "cam_smmu_get_scratch_iova",
      3501,
      "virt_len = %zx, phys_len  = %zx",
      a5,
      a4);
    v18 = a4;
    v17 = a5;
  }
LABEL_19:
  v19 = iommu_cb_set + 14280LL * v8;
  if ( !*(_DWORD *)(v19 + 8484) )
  {
    if ( (v18 & 0xFFF) != 0 )
    {
      v21 = "Requested scratch buffer length not page aligned";
      v22 = 3513;
    }
    else
    {
      if ( ((v17 - 1) & v18) == 0 )
      {
        v23 = cam_smmu_alloc_scratch_buffer_add_to_list(v8, v18);
        if ( (v23 & 0x80000000) != 0 )
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_get_scratch_iova",
            3531,
            "Error: mapping or add list fail");
        goto LABEL_32;
      }
      v21 = "Requested virt length not aligned with phys length";
      v22 = 3520;
    }
    goto LABEL_30;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_get_scratch_iova",
    3506,
    "Err:Dev %s should call SMMU attach before map buffer",
    *(const char **)(v19 + 32));
LABEL_31:
  v23 = -22;
LABEL_32:
  mutex_unlock(iommu_cb_set + 14280LL * v8 + 8432);
  return v23;
}
