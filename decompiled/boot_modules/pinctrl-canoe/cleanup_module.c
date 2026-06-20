__int64 cleanup_module()
{
  return platform_driver_unregister(&canoe_tlmm_driver);
}
