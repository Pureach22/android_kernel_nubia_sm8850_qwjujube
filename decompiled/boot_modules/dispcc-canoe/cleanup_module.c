__int64 cleanup_module()
{
  platform_driver_unregister(&disp_cc_mx_canoe_driver);
  return platform_driver_unregister(&disp_cc_canoe_driver);
}
