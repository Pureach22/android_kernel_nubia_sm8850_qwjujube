__int64 init_module()
{
  return _platform_driver_register(logbuf_vh_driver, &_this_module);
}
