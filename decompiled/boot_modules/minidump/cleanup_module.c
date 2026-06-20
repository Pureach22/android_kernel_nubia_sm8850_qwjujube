__int64 cleanup_module()
{
  return platform_driver_unregister(&msm_minidump_smem_driver);
}
