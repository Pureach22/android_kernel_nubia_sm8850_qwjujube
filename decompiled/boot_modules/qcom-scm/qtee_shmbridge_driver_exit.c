__int64 qtee_shmbridge_driver_exit()
{
  return platform_driver_unregister(qtee_shmbridge_driver);
}
