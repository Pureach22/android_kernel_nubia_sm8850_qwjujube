__int64 spf_core_platform_driver_remove()
{
  __int64 v0; // x0

  v0 = gpr_driver_unregister(qcom_spf_core_driver);
  spf_core_priv = 0;
  return digital_cdc_rsc_mgr_exit(v0);
}
