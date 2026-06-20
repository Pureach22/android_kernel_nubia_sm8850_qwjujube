__int64 dsi_phy_drv_register()
{
  return _platform_driver_register(dsi_phy_platform_driver, &_this_module);
}
