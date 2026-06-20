__int64 cleanup_module()
{
  return platform_driver_unregister(ocp_notifier_driver);
}
