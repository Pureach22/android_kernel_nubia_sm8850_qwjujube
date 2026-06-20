__int64 cleanup_module()
{
  return platform_driver_unregister(pmic_glink_debug_driver);
}
