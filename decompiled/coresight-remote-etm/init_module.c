__int64 init_module()
{
  return _platform_driver_register(&remote_etm_driver, &_this_module);
}
