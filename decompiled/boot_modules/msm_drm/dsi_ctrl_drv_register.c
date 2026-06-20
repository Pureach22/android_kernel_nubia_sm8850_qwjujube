__int64 dsi_ctrl_drv_register()
{
  return _platform_driver_register(dsi_ctrl_driver, &_this_module);
}
