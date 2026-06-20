__int64 init_module()
{
  return _platform_driver_register(&mem_offline_driver, &_this_module);
}
