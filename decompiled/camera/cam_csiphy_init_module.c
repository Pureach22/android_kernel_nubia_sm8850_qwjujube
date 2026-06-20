__int64 cam_csiphy_init_module()
{
  return _platform_driver_register(csiphy_driver, &_this_module);
}
