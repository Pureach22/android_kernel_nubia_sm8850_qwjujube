// Alternative name is 'init_module'
__int64 regulator_stub_init()
{
  return _platform_driver_register(&regulator_stub_driver, &_this_module);
}
