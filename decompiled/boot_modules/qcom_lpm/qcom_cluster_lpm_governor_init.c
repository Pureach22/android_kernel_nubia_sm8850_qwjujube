__int64 qcom_cluster_lpm_governor_init()
{
  return _platform_driver_register(qcom_cluster_lpm_driver, &_this_module);
}
