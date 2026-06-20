__int64 __fastcall cam_smmu_probe(const char **a1)
{
  char v2; // w8
  const char *v3; // x0
  __int64 next_available_child; // x0
  __int64 v5; // x20
  __int64 (__fastcall **v6)(); // x1
  const char *v7; // x5
  __int64 v8; // x4
  __int64 result; // x0
  unsigned int v10; // w19

  v2 = debug_mdl;
  a1[86] = nullptr;
  if ( (v2 & 0x40) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v2 & 0x40,
      4,
      "cam_smmu_probe",
      5808,
      "Adding SMMU component: %s",
      *a1);
  cam_soc_util_initialize_power_domain((__int64)(a1 + 2));
  if ( (unsigned int)of_device_is_compatible(a1[95], "qcom,msm-cam-smmu") )
  {
    v3 = a1[95];
    dword_394060 = 0;
    next_available_child = of_get_next_available_child(v3, 0);
    if ( next_available_child )
    {
      v5 = next_available_child;
      do
      {
        if ( (unsigned int)of_device_is_compatible(v5, "qcom,msm-cam-smmu-cb") )
          ++dword_394060;
        if ( (unsigned int)of_device_is_compatible(v5, "qcom,qsmmu-cam-cb") )
          ++dword_394060;
        v5 = of_get_next_available_child(a1[95], v5);
      }
      while ( v5 );
    }
    if ( dword_394060 )
    {
      iommu_cb_set = (__int64)devm_kmalloc(
                                (_QWORD *)(unsigned int)dword_394060,
                                a1 + 2,
                                14280LL * (unsigned int)dword_394060,
                                3520);
      if ( iommu_cb_set )
      {
        cam_smmu_reset_iommu_table(0);
        dword_394064 = 0;
        if ( (debug_mdl & 0x40) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40,
            4,
            "cam_alloc_smmu_context_banks",
            4650,
            "no of context banks :%d",
            dword_394060);
        v6 = cam_smmu_component_ops;
LABEL_27:
        result = component_add(a1 + 2, v6);
        if ( (result & 0x80000000) == 0 )
          return result;
        goto LABEL_28;
      }
      v7 = "Error: cannot allocate context banks";
      v8 = 4643;
    }
    else
    {
      v7 = "Error: no context banks present";
      v8 = 4633;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_alloc_smmu_context_banks",
      v8,
      v7);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_probe",
      5815,
      "Failed in allocating context banks");
    return 4294967284LL;
  }
  if ( (unsigned int)of_device_is_compatible(a1[95], "qcom,msm-cam-smmu-cb") )
  {
    v6 = cam_smmu_cb_component_ops;
    goto LABEL_27;
  }
  if ( (unsigned int)of_device_is_compatible(a1[95], "qcom,qsmmu-cam-cb") )
  {
    v6 = cam_smmu_cb_qsmmu_component_ops;
    goto LABEL_27;
  }
  if ( (unsigned int)of_device_is_compatible(a1[95], "qcom,msm-cam-smmu-fw-dev") )
  {
    v6 = cam_smmu_fw_dev_component_ops;
    goto LABEL_27;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_probe",
    5830,
    "Unrecognized child device: %s",
    *a1);
  LODWORD(result) = -19;
LABEL_28:
  v10 = result;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    64,
    1,
    "cam_smmu_probe",
    5835,
    "failed to add component rc: %d",
    result);
  return v10;
}
