__int64 cleanup_module()
{
  return platform_driver_unregister(cpu_mpam_driver);
}
