__int64 cleanup_module()
{
  return platform_driver_unregister(&chora_tlmm_driver);
}
