__int64 cleanup_module()
{
  return platform_driver_unregister(&eva_cc_canoe_driver);
}
