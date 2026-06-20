__int64 cleanup_module()
{
  return platform_driver_unregister(adc5_gen3_driver);
}
