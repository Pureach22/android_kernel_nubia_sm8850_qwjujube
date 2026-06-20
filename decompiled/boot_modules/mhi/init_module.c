__int64 init_module()
{
  mhi_misc_init();
  return bus_register(mhi_bus_type);
}
