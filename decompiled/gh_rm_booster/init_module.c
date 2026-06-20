__int64 init_module()
{
  return _platform_driver_register(gh_rm_booster_driver, &_this_module);
}
