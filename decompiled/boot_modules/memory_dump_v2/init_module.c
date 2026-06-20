__int64 init_module()
{
  return _platform_driver_register(&mem_dump_driver, &_this_module);
}
