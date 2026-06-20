__int64 __fastcall cam_smmu_ops(unsigned int a1, int a2)
{
  unsigned int v2; // w19
  int v5; // w6
  int v6; // w6
  int v7; // w0
  unsigned int v8; // w20
  __int64 v10; // x8
  int v11; // w9

  if ( a1 == -1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_ops",
      3238,
      "Error: Invalid handle");
    return 4294967274LL;
  }
  v2 = HIWORD(a1) & 0xFFF;
  if ( v2 >= dword_394060 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_ops",
      3245,
      "Error: Index invalid. idx = %d hdl = %x",
      v2,
      a1);
    return 4294967274LL;
  }
  mutex_lock(iommu_cb_set + 14280LL * v2 + 8432);
  v5 = *(_DWORD *)(iommu_cb_set + 14280LL * v2 + 8480);
  if ( v5 != a1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_ops",
      3253,
      "Error: hdl is not valid, table_hdl = %x, hdl = %x",
      v5,
      a1);
    mutex_unlock(iommu_cb_set + 14280LL * v2 + 8432);
    return 4294967274LL;
  }
  if ( a2 == 1 )
  {
    v10 = iommu_cb_set + 14280LL * v2;
    v11 = *(_DWORD *)(v10 + 8484);
    if ( v11 != 1 )
    {
      if ( v11 )
      {
        v8 = 0;
      }
      else
      {
        iommu_detach_device(*(_QWORD *)(v10 + 8), *(_QWORD *)v10);
        v8 = 0;
        *(_DWORD *)(iommu_cb_set + 14280LL * v2 + 8484) = 1;
      }
      goto LABEL_20;
    }
  }
  else
  {
    if ( a2 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_ops",
        3270,
        "Error: idx = %d, ops = %d",
        v2,
        a2);
LABEL_19:
      v8 = -22;
      goto LABEL_20;
    }
    v6 = *(_DWORD *)(iommu_cb_set + 14280LL * v2 + 8484);
    if ( v6 )
    {
      if ( v6 == 1 )
      {
        v7 = iommu_attach_device(*(_QWORD *)(iommu_cb_set + 14280LL * v2 + 8), *(_QWORD *)(iommu_cb_set + 14280LL * v2));
        if ( v7 < 0 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_attach_device",
            1211,
            "Error: ARM IOMMU attach failed. ret = %d",
            v7);
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            64,
            1,
            "cam_smmu_attach",
            1572,
            "Error: ATTACH fail");
          v8 = -19;
        }
        else
        {
          v8 = 0;
          *(_DWORD *)(iommu_cb_set + 14280LL * v2 + 8484) = 0;
        }
        goto LABEL_20;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_attach",
        1579,
        "Error: Not detach/attach: %d",
        v6);
      goto LABEL_19;
    }
  }
  v8 = -114;
LABEL_20:
  mutex_unlock(iommu_cb_set + 14280LL * v2 + 8432);
  return v8;
}
