__int64 cleanup_module()
{
  return platform_driver_unregister(pmic_pon_log_driver);
}
