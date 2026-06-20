__int64 init_module()
{
  return _platform_driver_register(qpace_driver, &_this_module);
}
