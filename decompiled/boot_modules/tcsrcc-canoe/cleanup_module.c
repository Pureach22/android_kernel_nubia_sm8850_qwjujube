__int64 cleanup_module()
{
  return platform_driver_unregister(&tcsr_cc_canoe_driver);
}
