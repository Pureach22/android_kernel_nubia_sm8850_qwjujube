__int64 cleanup_module()
{
  return platform_driver_unregister(&pm8916_pon_driver);
}
