__int64 cleanup_module()
{
  return platform_driver_unregister(gh_rm_booster_driver);
}
