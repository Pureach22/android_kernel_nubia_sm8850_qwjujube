__int64 qcom_cluster_lpm_governor_deinit()
{
  return platform_driver_unregister(qcom_cluster_lpm_driver);
}
