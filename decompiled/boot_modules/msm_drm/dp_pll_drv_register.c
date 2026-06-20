__int64 dp_pll_drv_register()
{
  return _platform_driver_register(dp_pll_platform_driver, &_this_module);
}
