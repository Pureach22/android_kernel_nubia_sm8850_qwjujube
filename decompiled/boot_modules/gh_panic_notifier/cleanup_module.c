__int64 cleanup_module()
{
  return platform_driver_unregister(gh_panic_notifier_driver);
}
