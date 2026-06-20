__int64 cleanup_module()
{
  return platform_driver_unregister(&alor_tlmm_driver);
}
