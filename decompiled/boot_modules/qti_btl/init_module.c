__int64 init_module()
{
  return _platform_driver_register(&qti_btl_driver, &_this_module);
}
