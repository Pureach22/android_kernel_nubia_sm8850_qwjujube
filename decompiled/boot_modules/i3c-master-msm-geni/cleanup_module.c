__int64 cleanup_module()
{
  return platform_driver_unregister(&geni_i3c_master);
}
