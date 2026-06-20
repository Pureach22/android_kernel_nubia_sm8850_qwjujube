__int64 cleanup_module()
{
  return platform_driver_unregister(heuristics_scid_driver);
}
