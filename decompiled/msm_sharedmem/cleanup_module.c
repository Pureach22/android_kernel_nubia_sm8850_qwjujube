__int64 cleanup_module()
{
  return platform_driver_unregister(&msm_sharedmem_driver);
}
