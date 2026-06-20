__int64 cleanup_module()
{
  return platform_driver_unregister(qrtr_gunyah_driver);
}
