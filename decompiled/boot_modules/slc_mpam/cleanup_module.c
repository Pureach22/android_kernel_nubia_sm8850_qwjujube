__int64 cleanup_module()
{
  return platform_driver_unregister(&slc_mpam_driver);
}
