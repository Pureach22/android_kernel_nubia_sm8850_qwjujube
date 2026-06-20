__int64 cam_sync_init()
{
  return _platform_driver_register(cam_sync_driver, &_this_module);
}
