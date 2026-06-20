__int64 __fastcall cam_smmu_set_client_page_fault_handler(unsigned int a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w19
  __int64 v7; // x10
  int v8; // w6
  int v9; // w11
  __int64 v11; // x10
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  int v17; // w11
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 v20; // x8
  _QWORD *v21; // x9
  __int64 v22; // x11
  __int64 v23; // x11

  if ( a1 == -1 || !a3 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             64,
             1,
             "cam_smmu_set_client_page_fault_handler",
             905,
             "Error: token is NULL or invalid handle");
  v3 = HIWORD(a1) & 0xFFF;
  if ( v3 >= dword_394060 )
    return ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
             3,
             64,
             1,
             "cam_smmu_set_client_page_fault_handler",
             913,
             "Error: handle or index invalid. idx = %d hdl = %x",
             v3,
             a1);
  mutex_lock(iommu_cb_set + 14280LL * v3 + 8432);
  v7 = iommu_cb_set + 14280LL * v3;
  v8 = *(_DWORD *)(v7 + 8480);
  if ( v8 != (a1 & 0xFFFFFFF) )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_set_client_page_fault_handler",
      921,
      "Error: hdl is not valid, table_hdl = %x, hdl = %x",
      v8,
      a1);
    return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
  }
  if ( !a2 )
  {
    v11 = iommu_cb_set + 14280LL * v3;
    if ( *(_QWORD *)(v11 + 8536) != a3 )
    {
      v12 = iommu_cb_set + 14280LL * v3;
      if ( *(_QWORD *)(v12 + 8544) == a3 )
      {
        v21 = (_QWORD *)(v12 + 8544);
        v20 = 1;
      }
      else
      {
        v13 = iommu_cb_set + 14280LL * v3;
        if ( *(_QWORD *)(v13 + 8552) == a3 )
        {
          v21 = (_QWORD *)(v13 + 8552);
          v20 = 2;
        }
        else
        {
          v14 = iommu_cb_set + 14280LL * v3;
          if ( *(_QWORD *)(v14 + 8560) == a3 )
          {
            v21 = (_QWORD *)(v14 + 8560);
            v20 = 3;
          }
          else
          {
            v15 = iommu_cb_set + 14280LL * v3;
            if ( *(_QWORD *)(v15 + 8568) == a3 )
            {
              v21 = (_QWORD *)(v15 + 8568);
              v20 = 4;
            }
            else
            {
              v16 = iommu_cb_set + 14280LL * v3;
              if ( *(_QWORD *)(v16 + 8576) != a3 )
              {
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  64,
                  1,
                  "cam_smmu_set_client_page_fault_handler",
                  958,
                  "Error: hdl %x no matching tokens: %s",
                  a1,
                  *(const char **)(iommu_cb_set + 14280LL * v3 + 32));
                return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
              }
              v21 = (_QWORD *)(v16 + 8576);
              v20 = 5;
            }
          }
        }
      }
LABEL_40:
      *v21 = 0;
      *(_QWORD *)(iommu_cb_set + 14280LL * v3 + 8 * v20 + 8488) = 0;
      --*(_DWORD *)(iommu_cb_set + 14280LL * v3 + 8584);
      return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
    }
LABEL_32:
    v20 = 0;
    v21 = (_QWORD *)(v11 + 8536);
    goto LABEL_40;
  }
  v9 = *(_DWORD *)(v7 + 8584);
  if ( v9 != 6 )
  {
    *(_DWORD *)(v7 + 8584) = v9 + 1;
    v11 = iommu_cb_set + 14280LL * v3;
    v17 = *(_DWORD *)(v11 + 8584);
    if ( v17 < 1 )
      return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
    v18 = a2;
    v19 = a3;
    if ( *(_QWORD *)(v11 + 8536) )
    {
      if ( v17 == 1 )
        return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
      if ( *(_QWORD *)(v11 + 8544) )
      {
        if ( v17 == 2 )
          return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
        if ( *(_QWORD *)(v11 + 8552) )
        {
          if ( v17 == 3 )
            return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
          if ( *(_QWORD *)(v11 + 8560) )
          {
            if ( v17 == 4 )
              return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
            if ( *(_QWORD *)(v11 + 8568) )
            {
              if ( v17 == 5 )
                return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
              if ( *(_QWORD *)(v11 + 8576) )
              {
                if ( v17 == 6 )
                  return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
                __break(0x5512u);
                goto LABEL_32;
              }
              v22 = 5;
              v19 = a3;
              v18 = a2;
            }
            else
            {
              v22 = 4;
            }
          }
          else
          {
            v22 = 3;
          }
        }
        else
        {
          v22 = 2;
        }
      }
      else
      {
        v22 = 1;
      }
    }
    else
    {
      v22 = 0;
    }
    v23 = 8 * v22;
    *(_QWORD *)(v11 + 8536 + v23) = v19;
    *(_QWORD *)(iommu_cb_set + 14280LL * v3 + v23 + 8488) = v18;
    return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_set_client_page_fault_handler",
    930,
    "%s Should not regiester more handlers",
    *(const char **)(v7 + 32));
  return mutex_unlock(iommu_cb_set + 14280LL * v3 + 8432);
}
