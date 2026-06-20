__int64 cleanup_module()
{
  platform_driver_unregister(funnel_driver);
  amba_driver_unregister(&dynamic_funnel_driver);
  return funnel_pm_clear();
}
