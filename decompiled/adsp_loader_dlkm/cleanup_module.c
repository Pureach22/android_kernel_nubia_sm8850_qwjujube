__int64 cleanup_module()
{
  return platform_driver_unregister(&adsp_loader_driver);
}
