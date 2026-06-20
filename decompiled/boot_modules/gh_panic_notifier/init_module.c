__int64 init_module()
{
  return _platform_driver_register(gh_panic_notifier_driver, &_this_module);
}
