__int64 init_module()
{
  return _platform_driver_register(&bcl_driver, &_this_module);
}
