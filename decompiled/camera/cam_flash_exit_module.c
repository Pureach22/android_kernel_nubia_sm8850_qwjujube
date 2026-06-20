__int64 cam_flash_exit_module()
{
  platform_driver_unregister(cam_flash_platform_driver);
  return i2c_del_driver(&cam_flash_i2c_driver);
}
