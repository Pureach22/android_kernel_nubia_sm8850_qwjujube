__int64 cam_hw_cdm_init_module()
{
  return _platform_driver_register(cam_hw_cdm_driver, &_this_module);
}
