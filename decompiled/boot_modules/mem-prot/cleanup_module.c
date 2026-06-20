__int64 cleanup_module()
{
  debugfs_lookup_and_remove("mem-prot", 0);
  return platform_driver_unregister(mem_prot_driver);
}
