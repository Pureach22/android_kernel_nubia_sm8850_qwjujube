__int64 cleanup_module()
{
  return platform_driver_unregister(secure_etr_driver);
}
