__int64 cleanup_module()
{
  return platform_driver_unregister(&geni_i2c_driver);
}
