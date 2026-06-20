__int64 cleanup_module()
{
  __int64 v0; // x0
  __int64 v1; // x1
  __int64 v2; // x2

  v0 = syna_dev_module_exit();
  zte_touch_deinit(v0, v1, v2);
  return platform_driver_unregister(zte_touch_device_driver);
}
