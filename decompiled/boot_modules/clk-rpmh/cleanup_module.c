__int64 cleanup_module()
{
  return platform_driver_unregister(&clk_rpmh_driver);
}
