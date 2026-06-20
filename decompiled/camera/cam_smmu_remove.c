__int64 __fastcall cam_smmu_remove(const char **a1)
{
  __int64 (__fastcall **v2)(); // x1

  if ( (debug_mdl & 0x40) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40,
      4,
      "cam_smmu_remove",
      5848,
      "Removing SMMU component: %s",
      *a1);
  if ( (unsigned int)of_device_is_compatible(a1[95], "qcom,msm-cam-smmu") )
  {
    v2 = cam_smmu_component_ops;
  }
  else if ( (unsigned int)of_device_is_compatible(a1[95], "qcom,msm-cam-smmu-cb") )
  {
    v2 = cam_smmu_cb_component_ops;
  }
  else if ( (unsigned int)of_device_is_compatible(a1[95], "qcom,qsmmu-cam-cb") )
  {
    v2 = cam_smmu_cb_qsmmu_component_ops;
  }
  else
  {
    if ( !(unsigned int)of_device_is_compatible(a1[95], "qcom,msm-cam-smmu-fw-dev") )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        64,
        1,
        "cam_smmu_remove",
        5860,
        "Unrecognized child device: %s",
        *a1);
      return cam_soc_util_uninitialize_power_domain((__int64)(a1 + 2));
    }
    v2 = cam_smmu_fw_dev_component_ops;
  }
  component_del(a1 + 2, v2);
  return cam_soc_util_uninitialize_power_domain((__int64)(a1 + 2));
}
