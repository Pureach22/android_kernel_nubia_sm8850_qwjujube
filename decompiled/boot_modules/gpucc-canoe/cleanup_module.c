__int64 cleanup_module()
{
  platform_driver_unregister(&gx_clkctl_canoe_driver);
  return platform_driver_unregister(&gpu_cc_canoe_driver);
}
