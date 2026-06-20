__int64 cleanup_module()
{
  return platform_driver_unregister(pm8941_pwrkey_driver);
}
