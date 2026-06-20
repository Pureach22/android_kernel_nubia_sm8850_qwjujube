__int64 init_module()
{
  return _platform_driver_register(&mem_object_plat_driver, &_this_module);
}
