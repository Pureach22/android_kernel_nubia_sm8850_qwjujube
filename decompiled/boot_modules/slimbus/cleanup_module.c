__int64 cleanup_module()
{
  return bus_unregister(&slimbus_bus);
}
