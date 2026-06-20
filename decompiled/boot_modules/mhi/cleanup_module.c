__int64 cleanup_module()
{
  mhi_misc_exit();
  return bus_unregister(mhi_bus_type);
}
