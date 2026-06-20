__int64 qtee_shmbridge_driver_init()
{
  return _platform_driver_register(qtee_shmbridge_driver, &_this_module);
}
