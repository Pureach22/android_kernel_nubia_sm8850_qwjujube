__int64 dsi_display_unregister()
{
  platform_driver_unregister(&dsi_display_driver);
  dsi_ctrl_drv_unregister();
  return dsi_phy_drv_unregister();
}
