__int64 cleanup_module()
{
  return platform_driver_unregister(qti_ptd_share_module);
}
