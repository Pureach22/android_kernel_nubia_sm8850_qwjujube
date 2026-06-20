__int64 init_module()
{
  return _platform_driver_register(charger_policy_driver, &_this_module);
}
