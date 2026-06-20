__int64 cleanup_module()
{
  return tracepoint_probe_unregister(&_tracepoint_android_vh_thermal_pm_notify_suspend, qti_thermal_pm_notify, 0);
}
