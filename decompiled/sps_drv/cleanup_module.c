__int64 cleanup_module()
{
  __int64 result; // x0

  platform_driver_unregister(msm_sps_driver);
  kfree(sps);
  sps = 0;
  debugfs_remove(dent);
  result = kfree(debugfs_buf);
  debugfs_buf = 0;
  return result;
}
