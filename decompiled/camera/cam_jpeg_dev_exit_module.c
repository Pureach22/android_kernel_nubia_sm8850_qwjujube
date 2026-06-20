__int64 cam_jpeg_dev_exit_module()
{
  return platform_driver_unregister(jpeg_driver);
}
