__int64 cleanup_module()
{
  platform_driver_unregister(replicator_driver);
  amba_driver_unregister(&dynamic_replicator_driver);
  return replicator_pm_clear();
}
