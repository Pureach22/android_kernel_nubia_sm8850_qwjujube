__int64 cleanup_module()
{
  platform_driver_unregister(static_tpdm_driver);
  return amba_driver_unregister(&tpdm_driver);
}
