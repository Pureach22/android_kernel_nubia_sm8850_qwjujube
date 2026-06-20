__int64 cleanup_module()
{
  qmp_put(*(_QWORD *)(pwr_data + 152));
  return platform_driver_unregister(bt_power_driver);
}
