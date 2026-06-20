__int64 __fastcall cam_smmu_free_iova(__int64 a1, __int64 a2, __int64 a3, unsigned int a4)
{
  unsigned int v4; // w6
  __int64 v5; // x11
  __int64 v6; // x9
  int v7; // w7
  const char *v8; // x5
  __int64 v9; // x4
  __int64 result; // x0
  int v11; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+18h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  if ( !a2 || a4 == -1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_free_iova",
      1665,
      "Error: Input args are invalid");
    goto LABEL_13;
  }
  v4 = HIWORD(a4) & 0xFFF;
  if ( v4 >= dword_394060 )
  {
    v8 = "Error: handle or index invalid. idx = %d hdl = %x";
    v9 = 1673;
LABEL_12:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_free_iova",
      v9,
      v8);
    goto LABEL_13;
  }
  v5 = iommu_cb_set + 14280LL * v4;
  if ( *(_DWORD *)(v5 + 8480) != (a4 & 0xFFFFFFF) )
  {
    v8 = "Error: hdl is not valid, table_hdl = %x, hdl = %x";
    v9 = 1680;
    goto LABEL_12;
  }
  v6 = 0;
  if ( !(_DWORD)a3 || !*(_DWORD *)(v5 + 8628) )
    goto LABEL_17;
  v11 = a3;
  v7 = *(_DWORD *)(v5 + 1640);
  if ( v7 - 1 < (int)a3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_validate_nested_region_idx",
      666,
      "Nested region idx=%d exceeds max regions=%d for region_id=%d in cb=%s",
      (unsigned int)&v11,
      v7,
      1,
      *(const char **)(v5 + 32));
LABEL_13:
    result = 4294967274LL;
LABEL_14:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)a3 < 2 )
  {
    v6 = 1;
LABEL_17:
    gen_pool_free_owner(*(_QWORD *)(iommu_cb_set + 14280LL * v4 + 8 * v6 + 144), a1, a2, 0);
    result = 0;
    goto LABEL_14;
  }
  __break(0x5512u);
  return trace_cam_log_event(a1, a1, a3);
}
