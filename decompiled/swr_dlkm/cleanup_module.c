__int64 cleanup_module()
{
  device_unregister(&soundwire_dev);
  return bus_unregister(&soundwire_type);
}
