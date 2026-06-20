__int64 cleanup_module()
{
  return platform_driver_unregister(qcom_cpuss_sleep_stats_v4);
}
