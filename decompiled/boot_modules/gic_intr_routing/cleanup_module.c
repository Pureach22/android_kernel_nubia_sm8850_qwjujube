__int64 cleanup_module()
{
  return platform_driver_unregister(gic_intr_routing_driver);
}
