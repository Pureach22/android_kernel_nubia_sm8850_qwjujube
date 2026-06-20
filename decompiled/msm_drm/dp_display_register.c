__int64 dp_display_register()
{
  dp_pll_drv_register();
  return _platform_driver_register(&dp_display_driver, &_this_module);
}
