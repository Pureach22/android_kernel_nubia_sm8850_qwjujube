__int64 init_module()
{
  return _platform_driver_register(&sdam_driver, &_this_module);
}
