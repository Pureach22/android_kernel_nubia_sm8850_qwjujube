__int64 cleanup_module()
{
  return platform_driver_unregister(&cam_bist_mclk_cc_canoe_driver);
}
