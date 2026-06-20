__int64 cam_cpas_dev_init_module()
{
  return _platform_driver_register(cam_cpas_driver, &_this_module);
}
