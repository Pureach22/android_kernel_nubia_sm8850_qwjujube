__int64 __fastcall cam_smmu_unset_client_page_fault_handler(unsigned int a1, __int64 a2)
{
  unsigned int v2; // w19
  int v5; // w6
  __int64 v6; // x10
  __int64 v7; // x10
  __int64 v8; // x10
  __int64 v9; // x10
  __int64 v10; // x10
  __int64 v11; // x10
  __int64 v13; // x8
  _QWORD *v14; // x9

  if ( a1 == -1 || !a2 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             64,
             1,
             "cam_smmu_unset_client_page_fault_handler",
             968,
             "Error: token is NULL or invalid handle");
  v2 = HIWORD(a1) & 0xFFF;
  if ( v2 >= dword_394060 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             64,
             1,
             "cam_smmu_unset_client_page_fault_handler",
             976,
             "Error: handle or index invalid. idx = %d hdl = %x",
             v2,
             a1);
  mutex_lock(iommu_cb_set + 14280LL * v2 + 8432);
  v5 = *(_DWORD *)(iommu_cb_set + 14280LL * v2 + 8480);
  if ( v5 != (a1 & 0xFFFFFFF) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_unset_client_page_fault_handler",
      984,
      "Error: hdl is not valid, table_hdl = %x, hdl = %x",
      v5,
      a1);
    return mutex_unlock(iommu_cb_set + 14280LL * v2 + 8432);
  }
  v6 = iommu_cb_set + 14280LL * v2;
  if ( *(_QWORD *)(v6 + 8536) == a2 )
  {
    v13 = 0;
    v14 = (_QWORD *)(v6 + 8536);
LABEL_21:
    *v14 = 0;
    *(_QWORD *)(iommu_cb_set + 14280LL * v2 + 8 * v13 + 8488) = 0;
    --*(_DWORD *)(iommu_cb_set + 14280LL * v2 + 8584);
    return mutex_unlock(iommu_cb_set + 14280LL * v2 + 8432);
  }
  v7 = iommu_cb_set + 14280LL * v2;
  if ( *(_QWORD *)(v7 + 8544) == a2 )
  {
    v14 = (_QWORD *)(v7 + 8544);
    v13 = 1;
    goto LABEL_21;
  }
  v8 = iommu_cb_set + 14280LL * v2;
  if ( *(_QWORD *)(v8 + 8552) == a2 )
  {
    v14 = (_QWORD *)(v8 + 8552);
    v13 = 2;
    goto LABEL_21;
  }
  v9 = iommu_cb_set + 14280LL * v2;
  if ( *(_QWORD *)(v9 + 8560) == a2 )
  {
    v14 = (_QWORD *)(v9 + 8560);
    v13 = 3;
    goto LABEL_21;
  }
  v10 = iommu_cb_set + 14280LL * v2;
  if ( *(_QWORD *)(v10 + 8568) == a2 )
  {
    v14 = (_QWORD *)(v10 + 8568);
    v13 = 4;
    goto LABEL_21;
  }
  v11 = iommu_cb_set + 14280LL * v2;
  if ( *(_QWORD *)(v11 + 8576) == a2 )
  {
    v14 = (_QWORD *)(v11 + 8576);
    v13 = 5;
    goto LABEL_21;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_unset_client_page_fault_handler",
    1000,
    "Error: hdl %x no matching tokens: %s",
    a1,
    *(const char **)(iommu_cb_set + 14280LL * v2 + 32));
  return mutex_unlock(iommu_cb_set + 14280LL * v2 + 8432);
}
