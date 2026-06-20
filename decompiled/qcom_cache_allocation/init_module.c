__int64 init_module()
{
  return _platform_driver_register(cache_allocation_driver, &_this_module);
}
