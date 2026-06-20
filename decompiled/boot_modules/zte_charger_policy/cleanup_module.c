__int64 cleanup_module()
{
  return platform_driver_unregister(charger_policy_driver);
}
