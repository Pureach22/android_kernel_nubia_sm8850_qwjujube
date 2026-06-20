__int64 cleanup_module()
{
  return platform_driver_unregister(&video_cc_canoe_driver);
}
