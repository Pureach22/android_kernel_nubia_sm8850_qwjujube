__int64 __fastcall cam_smmu_free_scratch_buffer_remove_from_list(_QWORD *a1, unsigned int a2)
{
  __int64 v2; // x20
  unsigned __int64 v4; // x6
  __int64 v5; // x8
  const char *v6; // x5
  __int64 v7; // x4
  unsigned int v8; // w20
  unsigned __int64 v9; // x8
  unsigned int v10; // w10
  __int64 v11; // x1
  _QWORD *v12; // x0
  _QWORD *v13; // x8
  _QWORD *v14; // x9
  __int64 v15; // x10

  v2 = iommu_cb_set + 14280LL * a2;
  if ( !a1[2] )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_free_scratch_buffer_remove_from_list",
      3412,
      "Error: Invalid params: dev = %pK, table = %pK",
      *(const void **)v2,
      nullptr);
    return (unsigned int)-22;
  }
  v4 = iommu_unmap(*(_QWORD *)(v2 + 8), a1[6], a1[11]);
  if ( v4 != a1[11] )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, unsigned __int64))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_free_scratch_buffer_remove_from_list",
      3420,
      "Unmapped only %zx instead of %zx",
      v4);
    v4 = a1[11];
  }
  v5 = a1[6];
  if ( v5 )
  {
    if ( (unsigned __int64)((unsigned int)(((v4 >> 12) + (1 << *(_DWORD *)(v2 + 128)) - 1) >> *(_DWORD *)(v2 + 128))
                          + (unsigned int)((unsigned __int64)(v5 - *(_QWORD *)(v2 + 136)) >> ((unsigned __int8)*(_DWORD *)(v2 + 128)
                                                                                            + 12))) <= *(_QWORD *)(v2 + 120) )
    {
      _bitmap_clear(*(_QWORD *)(v2 + 112));
      v8 = 0;
      goto LABEL_11;
    }
    v6 = "Error: Invalid page bits in scratch map";
    v7 = 1388;
  }
  else
  {
    v6 = "Error: Invalid address";
    v7 = 1383;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_free_scratch_va",
    v7,
    v6);
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_free_scratch_buffer_remove_from_list",
    3427,
    "Error: Invalid iova while freeing scratch buffer");
  v8 = -22;
LABEL_11:
  v9 = a1[12] - 1LL;
  v10 = 64 - __clz(v9 >> 12);
  if ( v9 >= 0x1000 )
    v11 = v10;
  else
    v11 = 0;
  _free_pages(**(_QWORD **)a1[2] & 0xFFFFFFFFFFFFFFFCLL, v11);
  sg_free_table(a1[2]);
  v12 = (_QWORD *)a1[2];
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v12, 0);
  else
    kvfree(v12);
  v13 = (_QWORD *)a1[8];
  v14 = a1 + 7;
  if ( (_QWORD *)*v13 == a1 + 7 && (v15 = *v14, *(_QWORD **)(*v14 + 8LL) == v14) )
  {
    *(_QWORD *)(v15 + 8) = v13;
    *v13 = v15;
  }
  else
  {
    _list_del_entry_valid_or_report(a1 + 7);
  }
  a1[7] = a1 + 7;
  a1[8] = v14;
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(a1, 0);
  else
    kvfree(a1);
  return v8;
}
