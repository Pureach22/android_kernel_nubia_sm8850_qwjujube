__int64 init_module()
{
  return _platform_driver_register(&gdsc_driver, &_this_module);
}
