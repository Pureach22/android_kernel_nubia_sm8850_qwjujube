__int64 __fastcall cam_smmu_alloc_iova(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  unsigned int v4; // w19
  unsigned int v5; // w6
  __int64 v6; // x10
  __int64 v7; // x8
  int v8; // w7
  const char *v9; // x5
  __int64 v10; // x4
  __int64 result; // x0
  __int64 *v12; // x19
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x8
  _QWORD *v16; // [xsp+18h] [xbp-28h]
  unsigned int v17; // [xsp+24h] [xbp-1Ch]
  __int64 v18; // [xsp+28h] [xbp-18h]
  int v19; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  if ( (_DWORD)a3 == -1 || !a1 || !a4 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_alloc_iova",
      1610,
      "Error: Input args are invalid");
    goto LABEL_18;
  }
  v4 = a3;
  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
  {
    v18 = a1;
    v17 = a2;
    v16 = a4;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40,
      4,
      "cam_smmu_alloc_iova",
      1615,
      "Allocating iova size = %zu for smmu hdl=%X",
      a1,
      a3);
    a2 = v17;
    a1 = v18;
    a4 = v16;
  }
  v5 = HIWORD(v4) & 0xFFF;
  if ( v5 >= dword_394060 )
  {
    v9 = "Error: handle or index invalid. idx = %d hdl = %x";
    v10 = 1621;
LABEL_17:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_alloc_iova",
      v10,
      v9);
    goto LABEL_18;
  }
  v6 = iommu_cb_set + 14280LL * v5;
  if ( *(_DWORD *)(v6 + 8480) != (v4 & 0xFFFFFFF) )
  {
    v9 = "Error: hdl is not valid, table_hdl = %x, hdl = %x";
    v10 = 1628;
    goto LABEL_17;
  }
  if ( !*(_BYTE *)(v6 + 83) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_alloc_iova",
      1636,
      "Error: Shared memory not supported for hdl = %X",
      v4);
    goto LABEL_18;
  }
  v7 = 0;
  if ( !(_DWORD)a2 || !*(_DWORD *)(v6 + 8628) )
  {
LABEL_23:
    v12 = a4;
    v13 = *(_QWORD *)(iommu_cb_set + 14280LL * v5 + 8 * v7 + 144);
    v14 = gen_pool_alloc_algo_owner(v13, a1, *(_QWORD *)(v13 + 32), *(_QWORD *)(v13 + 40), 0);
    if ( v14 )
    {
      v15 = v14;
      result = 0;
      *v12 = v15;
    }
    else
    {
      result = 4294967284LL;
    }
    goto LABEL_19;
  }
  v19 = a2;
  v8 = *(_DWORD *)(v6 + 1640);
  if ( v8 - 1 < (int)a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_validate_nested_region_idx",
      666,
      "Nested region idx=%d exceeds max regions=%d for region_id=%d in cb=%s",
      (unsigned int)&v19,
      v8,
      1,
      *(const char **)(v6 + 32));
LABEL_18:
    result = 4294967274LL;
LABEL_19:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( (unsigned int)a2 < 2 )
  {
    v7 = 1;
    goto LABEL_23;
  }
  __break(0x5512u);
  return cam_smmu_free_iova(a1, a2, a3, a4);
}
