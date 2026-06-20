__int64 init_module()
{
  return _platform_driver_register(&qfprom_driver, &_this_module);
}
