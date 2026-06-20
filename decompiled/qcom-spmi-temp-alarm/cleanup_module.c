__int64 cleanup_module()
{
  return platform_driver_unregister(&qpnp_tm_driver);
}
