__int64 init_module()
{
  return _platform_driver_register(&qpnp_tm_driver, &_this_module);
}
