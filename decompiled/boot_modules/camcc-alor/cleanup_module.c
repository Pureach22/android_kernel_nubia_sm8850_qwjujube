__int64 cleanup_module()
{
  return platform_driver_unregister(&cam_cc_alor_driver);
}
