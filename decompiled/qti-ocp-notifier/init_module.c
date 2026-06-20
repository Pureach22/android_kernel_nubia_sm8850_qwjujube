__int64 init_module()
{
  return _platform_driver_register(ocp_notifier_driver, &_this_module);
}
