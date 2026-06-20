__int64 cleanup_module()
{
  return platform_driver_unregister(logbuf_vh_driver);
}
