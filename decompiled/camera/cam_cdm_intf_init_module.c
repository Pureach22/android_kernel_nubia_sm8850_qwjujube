__int64 cam_cdm_intf_init_module()
{
  return _platform_driver_register(cam_cdm_intf_driver, &_this_module);
}
