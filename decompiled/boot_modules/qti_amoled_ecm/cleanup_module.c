__int64 cleanup_module()
{
  return platform_driver_unregister(qti_amoled_ecm_driver);
}
