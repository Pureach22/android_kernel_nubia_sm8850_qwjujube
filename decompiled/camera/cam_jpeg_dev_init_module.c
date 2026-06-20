__int64 cam_jpeg_dev_init_module()
{
  return _platform_driver_register(jpeg_driver, &_this_module);
}
