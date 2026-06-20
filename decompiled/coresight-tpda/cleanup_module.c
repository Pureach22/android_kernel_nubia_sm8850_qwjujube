__int64 cleanup_module()
{
  return amba_driver_unregister(&tpda_driver);
}
