__int64 cleanup_module()
{
  return platform_driver_unregister(&msm_gsi_driver);
}
