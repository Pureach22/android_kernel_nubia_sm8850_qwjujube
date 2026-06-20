__int64 init_module()
{
  return _platform_driver_register(gic_intr_routing_driver, &_this_module);
}
