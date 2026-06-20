__int64 init_module()
{
  unsigned int v0; // w0

  v0 = tracepoint_probe_register(&_tracepoint_android_vh_thermal_pm_notify_suspend, qti_thermal_pm_notify, 0);
  if ( v0 )
    printk(&unk_6168, v0);
  return 0;
}
