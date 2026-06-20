__int64 cleanup_module()
{
  return platform_driver_unregister(&amoled_regulator_driver);
}
