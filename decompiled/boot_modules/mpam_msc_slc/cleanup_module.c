__int64 cleanup_module()
{
  return platform_driver_unregister(mpam_msc_slc_driver);
}
