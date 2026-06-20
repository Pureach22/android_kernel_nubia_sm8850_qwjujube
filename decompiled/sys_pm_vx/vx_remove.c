__int64 __fastcall vx_remove(__int64 a1)
{
  __int64 v1; // x20

  v1 = *(_QWORD *)(a1 + 168);
  debugfs_remove(*(_QWORD *)(v1 + 8));
  device_remove_file(a1 + 16, &dev_attr_debug_time_ms);
  device_remove_file(a1 + 16, &dev_attr_debug_enable);
  device_remove_file(a1 + 16, &dev_attr_set_timer_ms);
  qmp_put(*(_QWORD *)(v1 + 96));
  return subsystem_sleep_debug_enable(0);
}
