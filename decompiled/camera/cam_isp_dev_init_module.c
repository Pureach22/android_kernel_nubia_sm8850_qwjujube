__int64 cam_isp_dev_init_module()
{
  return _platform_driver_register(isp_driver, &_this_module);
}
