__int64 dp_display_unregister()
{
  platform_driver_unregister(&dp_display_driver);
  return dp_pll_drv_unregister();
}
